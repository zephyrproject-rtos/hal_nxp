/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FWK_PLATFORM_MCU_NBU_COMMON_H_
#define _FWK_PLATFORM_MCU_NBU_COMMON_H_

#include <stdint.h>
#include <stdbool.h>

#include "fsl_device_registers.h"
#include "fwk_platform_definitions.h"

/* -------------------------------------------------------------------------- */
/*                           Macro definitions                                */
/* -------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
   -- TSTMR Register Masks
   ---------------------------------------------------------------------------- */

#define FWK_TSTMR_L_VALUE_MASK  (0x00FFFFFFFFU)
#define FWK_TSTMR_L_VALUE_SHIFT (0U)
/*! VALUE - TIMESTAMP Low */
#define FWK_TSTMR_L_VALUE(x) (((uint32_t)(((uint32_t)(x)) << FWK_TSTMR_L_VALUE_SHIFT)) & FWK_TSTMR_L_VALUE_MASK)

#define FWK_TSTMR_H_VALUE_MASK  (0xFFFFFFU)
#define FWK_TSTMR_H_VALUE_SHIFT (0U)
/*! VALUE - TIMESTAMP High */
#define FWK_TSTMR_H_VALUE(x) (((uint32_t)(((uint32_t)(x)) << FWK_TSTMR_H_VALUE_SHIFT)) & FWK_TSTMR_H_VALUE_MASK)

/* MRCC clock configuration definitions*/
#define FWK_MRCC_TSTMR0_CLK_DIS                   0x00U
#define FWK_MRCC_TSTMR0_CLK_EN_NO_LP_STALL        0x01U
#define FWK_MRCC_TSTMR0_CLK_EN_LP_STALL_IDLE      0x02U
#define FWK_MRCC_TSTMR0_CLK_EN_LP_STALL_DEEPSLEEP 0x03U

/*! CC - Clock Config
 *  0b00..Peripheral clocks are disabled; module does not stall low power mode entry
 *  0b01..Peripheral clocks are enabled; module does not stall low power mode entry
 *  0b10..Peripheral clocks are enabled unless module is idle; low power mode entry stalls until module is idle
 *  0b11..Peripheral clocks are enabled unless in SLEEP (or lower) mode; low power mode entry stalls until module
 *        is idle. Peripheral functional clocks that remain enabled in SLEEP mode are enabled and do not stall low
 *        power mode entry unless entering DEEPSLEEP (or lower) mode
 */
#define FWK_MRCC_TSTMR0_CC_MASK  (0x3U)
#define FWK_MRCC_TSTMR0_CC_SHIFT (0U)
#define FWK_MRCC_TSTMR0_CC(x)    (((uint32_t)(((uint32_t)(x)) << FWK_MRCC_TSTMR0_CC_SHIFT)) & FWK_MRCC_TSTMR0_CC_MASK)

/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_6M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_32K
 *  0b101..CLK_1M
 */
/* TSTMR0 is always configured with 1MHz clock */
#define FWK_MRCC_TSTMR0_MUX_MASK  (0x70U)
#define FWK_MRCC_TSTMR0_MUX_SHIFT (4U)
#define FWK_MRCC_TSTMR0_MUX(x)    (((uint32_t)(((uint32_t)(x)) << FWK_MRCC_TSTMR0_MUX_SHIFT)) & FWK_MRCC_TSTMR0_MUX_MASK)
#define FWK_MRCC_TSTMR0_DIV_MASK  (0xF00U)
#define FWK_MRCC_TSTMR0_DIV_SHIFT (8U)
#define FWK_MRCC_TSTMR0_DIV(x)    (((uint32_t)(((uint32_t)(x)) << FWK_MRCC_TSTMR0_DIV_SHIFT)) & FWK_MRCC_TSTMR0_DIV_MASK)

/*! RSTB - Reset Negation
 *  0b0..Module is held in reset
 *  0b1..Module released from reset
 */
#define FWK_MRCC_TSTMR0_RSTB_MASK  (0x40000000U)
#define FWK_MRCC_TSTMR0_RSTB_SHIFT (30U)
#define FWK_MRCC_TSTMR0_RSTB(x)    (((uint32_t)(((uint32_t)(x)) << FWK_MRCC_RSTB_SHIFT)) & FWK_MRCC_RSTB_MASK)

/*! PR - Peripheral Present
 *  0b0..Module is not present; writes to this register are ignored
 *  0b1..Module is present
 */
#define FWK_MRCC_TSTMR0_PR_MASK  (0x80000000U)
#define FWK_MRCC_TSTMR0_PR_SHIFT (31U)
#define FWK_MRCC_TSTMR0_PR(x)    (((uint32_t)(((uint32_t)(x)) << FWK_MRCC_PR_SHIFT)) & FWK_MRCC_PR_MASK)

/* gPlatformTstmr32Bit_d should have the same definition between MCU and NBU.
* For better performance and to avoid hazardous glitches at LOW counter rollover,
* define gPlatformTstmr32Bit_d as 1 by default, unless MSB are really needed.
*-----------------------------------------------------------------------------*
* TSTMR Input clock | Width |  Elapsed time                                    |
          frequency | bits  |  at rollover                                     |
-------------------------------------------------------------------------------*
*           1MHz    |  32   | ~4295 seconds ~ 1h11min                          |
*------------------------------------------------------------------------------*
*           1MHz    |  56   | ~72.10^9 seconds ~20.10^6h ~ 2284 years          |
*------------------------------------------------------------------------------*
*           32kHz   |  32   | 131072 seconds ~ 36.4 hours                      | KW43 / MCXW70 only
*------------------------------------------------------------------------------*
*           32kHz   |  56   | 2199.10^9 seconds ~610.10^6h ~ 69730 years       | KW43 / MCXW70 only
*------------------------------------------------------------------------------*/

#ifndef gPlatformTstmr32Bit_d
#define gPlatformTstmr32Bit_d 1 /* Unless otherwise defined , default to 32-bit timer */
#endif

#define EXTRACT_TSTMR_LSB32(x64) ((uint32_t)((x64)&FWK_TSTMR_L_VALUE_MASK))

#if defined gPlatformTstmr32Bit_d && (gPlatformTstmr32Bit_d > 0)
#define PLATFORM_TSTMR_MAX_VAL   ((uint64_t)FWK_TSTMR_L_VALUE_MASK)
#define EXTRACT_TSTMR_MSB32(x64) ((uint32_t)0UL)
#else
/* Maximum value of 56 bit counter */
#define PLATFORM_TSTMR_MAX_VAL   ((uint64_t)FWK_TSTMR_L_VALUE_MASK | ((uint64_t)FWK_TSTMR_H_VALUE_MASK << 32))
#define EXTRACT_TSTMR_MSB32(x64) ((uint32_t)(((x64) >> 32) & TSTMR_H_VALUE_MASK))
#endif

#define TSTMR_1MHZ_ID  0U /* TSTMR counting on a 1MHz clock : exists on all KW4x and MCXW7x platforms */
#define TSTMR_32KHZ_ID 1U /* TSTMR counting on a 32kHz clock : exists on KW43 and MCXW70 only */

/* TSTMR timestamp is a 56 bit quantity, leaving 8 free bits in a 64 bit timestamp representation */
/* Bit 31 of timestamp MSB is used by core#0 to indicate that timestamp is being updated */
#define CORE1_TS_CHANGE_ONGOING (1UL << 31)
/*  Bit 30 of timestamp MSB denotes of the absence of constraint : no LL activity */
#define CORE1_NO_CONSTRAINT (1UL << 30)
#define CORE1_TS_UNSET_MASK (0x3fUL << 24)

/* -------------------------------------------------------------------------- */
/*                           Type definitions                                 */
/* -------------------------------------------------------------------------- */

/* Uncomment PLAT_FWK_INTERCORE_DBG_LP only for debug purposes */
//#define PLAT_FWK_INTERCORE_DBG_LP 1
/* IntercoreSharedCtx_t can only be used where a shared RAM space can be available.
 * Only possible on KW43 / MCXW70 so far.
 * In the context of 'lowpower' implementation, the purpose is to let the NBU share
 * the timestamp information related to its next activity to the MCU.
 * Other debug related fields can optionally be added.
 * The use of this context is used for low power management but does not preclude other uses.
 */
typedef struct
{
    union
    {
        struct
        {
            volatile uint32_t ts_lsb; /*! Timestamp LSB value - 32 bits */
            volatile uint32_t ts_msb; /*! Timestamp MSB value - 32 bits */
        } u32;
        volatile uint64_t u64;
    } ts;
#if defined(PLAT_FWK_INTERCORE_DBG_LP) && (PLAT_FWK_INTERCORE_DBG_LP > 0)
    volatile uint32_t cnt[2];
    volatile uint32_t time_stamp[2];     /* ! low power entry / exit pair of timestamps */
    volatile uint32_t rfmc_2p4g_stat[2]; /* ! RFMC 2.4G status tracking */
#endif
} IntercoreSharedCtx_t;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * brief Enable or disable TSTMR module.
 *
 *
 * \param tstmrId TSTMR instance id - 0 on all MCU/NBUs, 1 on KW43 only.
 * \param enablenDisable true to enable TSTMR, false to disable it.
 */
void PLATFORM_TSTMR_Enable(uint8_t tstmrId, bool enablenDisable);

/*!
 * \brief Get TSTMR timestamp.
 *
 * Behavior depends on gPlatformTstmr32Bit_d configuration.
 * Use of gPlatformTstmr32Bit_d should be preferred because it allows a much simpler / faster
 * implementation, nonetheless the code performing the read of MSB bits [32..55] is kept in case it
 * becomes useful.
 *
 * \param tstmrId 0 for TSTMR0, 1 for TSTMR1
 *
 * \return timestamp the value is either a 32-bit or 56-bit timestamp.
 */
uint64_t PLATFORM_TSTMR_ReadTimeStamp(uint8_t tstmrId);

/*!
 * \brief Compute number of ticks between 2 timestamps expressed in number of TSTMR ticks
 *
 * \param [in] timestamp0 start timestamp.
 * \param [in] timestamp1 end timestamp.
 *
 * \return uint64_t number of TSTMR ticks
 *
 */
uint64_t PLATFORM_GetTstmrDeltaTicks(uint64_t timestamp0, uint64_t timestamp1);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _FWK_PLATFORM_MCU_NBU_COMMON_H_ */
