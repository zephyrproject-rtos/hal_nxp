/* -------------------------------------------------------------------------- */
/*                           Copyright 2025-2026 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fwk_platform.h"
#include "fwk_debug.h"
#include "fwk_platform_ics.h"
#include "fsl_os_abstraction.h"
#include "fwk_platform_mcu_nbu_common.h"

#if defined PLAT_FWK_INTERCORE_DBG_LP && (PLAT_FWK_INTERCORE_DBG_LP > 0)
#include "fsl_debug_console.h"
#endif
/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private type definitions                           */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */

__attribute__((section(".m_shared_data"))) IntercoreSharedCtx_t mNbu_shared_ctx = {.ts.u64 = ~0ULL};

/* -------------------------------------------------------------------------- */
/*                              Private functions                              */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
/*!
 * \brief Get 32kHz timestamp from TSTMR1 counter
 *
 * \return uint64_t number ticks since start of TSTMR1.
 *
 */
uint64_t PLATFORM_Get32KTimeStamp(void)
{
    return PLATFORM_TSTMR_ReadTimeStamp(TSTMR_32KHZ_ID);
}

/*!
 * \brief Compute number of microseconds between 2 timestamps expressed in number of TSTM 32kHz ticks
 *
 * \param [in] timestamp0 start timestamp from which duration is assessed.
 * \param [in] timestamp1 end timestamp till which duration is assessed.
 *
 * \return uint64_t number of microseconds
 *
 */
uint64_t PLATFORM_Get32KTimeStampDeltaUs(uint64_t timestamp0, uint64_t timestamp1)
{
    uint64_t duration_us;

    duration_us = PLATFORM_GetTstmrDeltaTicks(timestamp0, timestamp1);
    /* Prevent overflow */
    duration_us &= PLATFORM_TSTMR_MAX_VAL;
    /* Normally useless but let Coverity know that the input is necessarily less than 2^56 */
    /* Multiply by 1000000 (2^6 * 5^6) and divide by 32768 (2^15) can be be simplified to Multiplication by 125*125 and
     * division by 512 */
    /* Multiply by 125, inserting the division by 64 and then multiply again by 125 and finally divide by 8 prevents the
     * overflow considering the argument is smaller than 2^56
     */
    duration_us *= 125ULL; /* Since timestamps are no more than 56 bit wide, multiplying by 125 is smaller than 2^63 */
    duration_us >>= 6;     /* Dividing by 64 (2^6) yields a result strictly smaller than 2^57 */
    duration_us *= 125ULL; /* Multiplying by 125 is necessarily strictly smaller than 2^64-1 */
    duration_us >>= 3;     /* Divide by 8 (2^3)  */

    return duration_us;
}

int PLATFORM_GetRadioIdleDuration32K(void)
{
    int      ret;
    uint64_t remaining_time = ~0ULL;

    uint64_t cur_nbu_ts;
    uint64_t next_core1_activity_ts;
    /* Copy fields of structure to registers */
    uint32_t ts_lsb_core1, ts_msb_core1;

    /* Loop reading exchange structure LSB first, then MSB until MSB has bit 31 unset  */
    do
    {
        ts_lsb_core1 = mNbu_shared_ctx.ts.u32.ts_lsb;
        __ISB();
        __DSB();
        /* If Low Power is disabled on NBU side, the intercore structure is never updated and
         * the timestamp will be remain set to ~0ULL */
        ts_msb_core1 = mNbu_shared_ctx.ts.u32.ts_msb;
        if (ts_msb_core1 & CORE1_TS_UNSET_MASK)
        {
            /* If timestamp is unset, causes to exit loop, cannot assume absence of constraint
             * because NBU is not sleeping  */
            ts_msb_core1 &= ~(CORE1_TS_CHANGE_ONGOING | CORE1_NO_CONSTRAINT);
        }
    } while (ts_msb_core1 & CORE1_TS_CHANGE_ONGOING);

    if (ts_msb_core1 & CORE1_NO_CONSTRAINT)
    {
        /* infinity : let remaining_time ~0ULL*/
    }
    else
    {
        next_core1_activity_ts = (((uint64_t)(ts_msb_core1 & TSTMR_H_VALUE_MASK) << 32) | (uint64_t)ts_lsb_core1);
        cur_nbu_ts             = PLATFORM_Get32KTimeStamp();
        if (next_core1_activity_ts > cur_nbu_ts)
        {
            /* mNbu_shared_ctx.ts is written by core#1 (NBU) at each sleep decision */
            remaining_time = next_core1_activity_ts - cur_nbu_ts;
        }
        else
        {
            remaining_time = 0ULL; /* deadline passed */
        }
    }
    if (remaining_time > INT32_MAX)
    {
        ret = PLATFORM_RADIO_IDLE_FOREVER;
    }
    else
    {
        ret = (int)remaining_time;
    }
    /* Return 0 if time is passed */
    return ret;
}

/*
 * Tell NBU the address in RAM where to write its next activity timestamp.
 */
int PLATFORM_SetNbuSharedCtxAddress(void)
{
    int                            ret;
    volatile IntercoreSharedCtx_t *p_shared_ctx = &mNbu_shared_ctx;
    ret = PLATFORM_FwkSrvSendPacket(gFwkSrvHostSetNbuSharedCtxAddr_c, (void *)&p_shared_ctx, sizeof(void *));
    return ret;
}

bool PLATFORM_IsNbuStuck(uint32_t nbuWatchdogDurationInUs)
{
    (void)nbuWatchdogDurationInUs;
    return false;
}

#if defined     PLAT_FWK_INTERCORE_DBG_LP && (PLAT_FWK_INTERCORE_DBG_LP > 0)
static uint32_t prev_ts        = 0U;
static uint32_t prev_cnt       = 0U;
static uint32_t prev_ble_state = ~0uL;

void dump_shared(void)
{
    uint32_t ble_state =
        (RFMC->RF2P4GHZ_STAT & RFMC_RF2P4GHZ_STAT_BLE_STATE_MASK) >> RFMC_RF2P4GHZ_STAT_BLE_STATE_SHIFT;
    if (ble_state != prev_ble_state)
    {
        PRINTF("BLE_STATE = %x\r\n", ble_state);
        prev_ble_state = ble_state;
    }
    if (prev_cnt != mNbu_shared_ctx.cnt[0])
    {
        if (prev_ts != mNbu_shared_ctx.time_stamp[0])
        {
            PRINTF("MRCC_DSB=%x, RFMC_2P4G_STAT pre=%x post=%x\r\n", MRCC->MRCC_DATA_STREAM_2P4_CLKSEL,
                   mNbu_shared_ctx.rfmc_2p4g_stat[0], mNbu_shared_ctx.rfmc_2p4g_stat[1]);
            prev_cnt = mNbu_shared_ctx.cnt[0];
        }
    }
}
#endif
