/*! *********************************************************************************
 * \defgroup CONTROLLER
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
*
* Copyright 2021-2024, 2026 NXP
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

/************************************************************************************
*************************************************************************************
* Include
*************************************************************************************
************************************************************************************/
#include "fwk_platform_ics.h"
#include "fwk_platform.h"
#include "controller_api.h"
#if !defined(__ZEPHYR__)
#include "RNG_Interface.h"
#endif

/************************************************************************************
*************************************************************************************
* Definitions
*************************************************************************************
************************************************************************************/

#define _GET8(p)  (*((uint8_t*)(p)))
#define _GET16(p) (((uint16_t)_GET8 ((p))) | ((uint16_t)_GET8 ((uint8_t*)(p)+1U) << 8U))
#define _GET32(p) (((uint32_t)_GET16((p))) | ((uint32_t)_GET16((uint8_t*)(p)+2U) << 16U))

// this enum must be aligned with the one defined in the controller
typedef enum
{
    API_Controller_SetTxPowerLevel,
    API_Controller_SetTxPowerLevelDbm,
    API_Controller_SetMaxTxPower,
    API_Controller_SetRandomSeed,
    API_Controller_ConfigureAdvCodingScheme,
    API_Controller_ConfigureConnCodingScheme,
    API_Controller_ConfigureInvalidPduHandling,
    API_Controller_SetConnNotificationMode,
    API_Controller_SetChannelSelectionAlgo2,
    API_Controller_GetTimestamp,
    API_Controller_GetTimestampEx,
    API_Controller_SetFemConfig,
    API_Controller_GetEncryptionParam,
    API_Controller_Reserve_2, /* place holding for new entry */
    API_Controller_SetRxMode,
    API_Controller_ConfigureSCA,
    API_Controller_ConfigureIDSSecurityEvent,
    API_Controller_ReadMemory,
    API_Last
} PLATFORM_NbuApiId;

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/
osa_status_t Controller_SetTxPowerLevel(uint8_t level, txChannelType_t channel)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    bool rpmsg_status;
    uint32_t tab[2U] = {(uint32_t)level, (uint32_t)channel};
    rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetTxPowerLevel,
                                (const uint8_t*)"\x01\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_SetTxPowerLevelDbm(int8_t level_dbm, txChannelType_t channel)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    bool rpmsg_status;
    uint32_t tab[2U] = {(uint32_t)level_dbm, (uint32_t)channel};
    rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetTxPowerLevelDbm,
                                (const uint8_t*)"\x01\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_SetMaxTxPower(int8_t power_dBm, uint8_t ldo_ant_trim)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    bool rpmsg_status;
    uint32_t tab[2U] = {(uint32_t)power_dBm, (uint32_t)ldo_ant_trim};
    rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetMaxTxPower,
                                (const uint8_t*)"\x01\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

#if !defined(__ZEPHYR__)
osa_status_t Controller_SetRandomSeed(void)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    bool rpmsg_status;
    uint32_t seed[1];

    RNG_GetTrueRandomNumber(seed);

    rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetRandomSeed,
                                (const uint8_t*)"\x04", seed, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}
#endif

osa_status_t Controller_ConfigureAdvCodingScheme(advCodingScheme_t codingSch, uint8_t handle)
{
    osa_status_t api_return    = KOSA_StatusSuccess;
    int32_t      ret           = 0;
    uint32_t tab[2U] = {(uint32_t)codingSch, (uint32_t)handle};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_ConfigureAdvCodingScheme,
                                (const uint8_t*)"\x01\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_ConfigureConnCodingScheme(connCodingScheme_t codingSch)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     coding_scheme[1] = {(uint32_t)codingSch};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_ConfigureConnCodingScheme,
                                (const uint8_t*)"\x01", coding_scheme, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_ConfigureInvalidPduHandling(uint32_t pdu_handling_type)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {pdu_handling_type};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_ConfigureInvalidPduHandling,
                                (const uint8_t*)"\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_SetConnNotificationMode(uint32_t mode)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {(uint32_t) mode};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetConnNotificationMode,
                                (const uint8_t*)"\x04", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_SetChannelSelectionAlgo2(bool enable)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {(uint32_t) enable};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetChannelSelectionAlgo2,
                                (const uint8_t*)"\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_GetNextLinLayerEventUsUnsafe(uint32_t* remaining_time)
{
    osa_status_t api_return = KOSA_StatusError;
    * remaining_time = 0u; /* no event */

    return api_return;
}

osa_status_t Controller_GetTimestamp(uint32_t* timestamp)
{
    int32_t      ret        = 0;
    uint32_t     dummy[1]   = {0};
    bool         rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_GetTimestamp,
                                (const uint8_t*)"\x01", dummy, 4U);
    *timestamp = ret;
    if (rpmsg_status)
    {
      return KOSA_StatusSuccess;
    }
    else
    {
      return KOSA_StatusError;
    }
}

osa_status_t Controller_GetTimestampEx(uint32_t* ll_timing_slot, uint16_t* ll_timing_us, uint64_t *tstmr)
{
    osa_status_t api_status;
    uint32_t     ret[5];
    bool         rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret[0], API_Controller_GetTimestampEx,
                                (const uint8_t*)"", NULL, 20U);
    if (rpmsg_status)
    {
      api_status = (osa_status_t)ret[0];
      if( api_status == KOSA_StatusSuccess )
      {
        // slot
        *ll_timing_slot = ret[1];
        // slot offset in us
        *ll_timing_us   = (uint16_t)ret[2];
        // TSTMR
        *tstmr = (uint64_t)ret[3] + (((uint64_t)ret[4])<<32U);
      }
    }
    else
    {
      api_status = KOSA_StatusError;
    }
    return api_status;
}

#define XCVR_PA_FEM_SIZE (15U + 2U) /* 15 is sizeof(xcvr_pa_fem_config_t), 2 is margin */

osa_status_t Controller_SetFemConfig(const uint8_t* fem_config_ptr, uint8_t config_len)
{
    osa_status_t api_return    = KOSA_StatusSuccess;
    int32_t      ret           = 0;
    uint32_t tab[XCVR_PA_FEM_SIZE];
    uint8_t fmt[XCVR_PA_FEM_SIZE + 1]; /* +1 for end of string */
    bool rpmsg_status;

    if ((fem_config_ptr != NULL) &&
        (config_len <= XCVR_PA_FEM_SIZE)) /* detect array size issue */
    {
        for (uint8_t i=0U; i<config_len; i++)
        {
            tab[i] = (uint32_t)(*(fem_config_ptr + i));
        }
        (void)memset(fmt, 0x01, config_len); /* all parameters are of type uint8 */
        fmt[config_len] = 0x00U;             /* add end of string */
        rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetFemConfig,
                                          (const uint8_t*)fmt, tab, 4U);
        assert(rpmsg_status);
        (void)rpmsg_status;

        if ( ret!=0 )
        {
            api_return = KOSA_StatusError;
        }
    }
    else
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

osa_status_t Controller_GetEncryptionParam(uint16_t conn_handle,
                                           uint8_t  sk_or_skd_req,
                                           uint8_t  sk_or_skd[16],
                                           uint8_t  iv[8],
                                           uint8_t  payload_counter_tx[5],
                                           uint8_t  payload_counter_rx[5])
{
    osa_status_t api_status;
    int8_t       ret[38];
    uint32_t     tab[2]     = {conn_handle, sk_or_skd_req};
    bool         rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret[0], API_Controller_GetEncryptionParam,
                                (const uint8_t*)"\x02\x01", tab, 38U);
    if (rpmsg_status)
    {
      api_status = (osa_status_t)_GET32(ret);
      if( api_status == KOSA_StatusSuccess )
      {
        memcpy(sk_or_skd,          ret+4U,           16U);
        memcpy(iv,                 ret+4U+16U,       8U );
        memcpy(payload_counter_tx, ret+4U+16U+8U,    5U );
        memcpy(payload_counter_rx, ret+4U+16U+8U+5U, 5U );
      }
    }
    else
    {
      api_status = KOSA_StatusError;
    }
    return api_status;
}

#if !defined(FPGA_TARGET) || (FPGA_TARGET!=0)
osa_status_t Controller_Set_PLL_OFFSET_CTRL(int32_t cfo_in_hz)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    uint32_t chan_amp, lpm_denom_selected;

    /* Make sure remote CPU is awake */
    PLATFORM_RemoteActiveReq();

    chan_amp = XCVR_PLL_DIG->CHAN_MAP;
    lpm_denom_selected = XCVR_PLL_DIG->LPM_SDM_RES2;
    /* verify that BTLE band is selected with appropriate LPM_DENOM value to ensure the correct Hertz-to-PLL_OFFSET_CTRL
       conversion. 1 LSB of cfo_in_hz corresponds to (2*REFCLK*1e6)/LPM_DENOM Hz = (2*32e6)/0x4000000 = 0.9536743 Hz */
    if (((chan_amp & XCVR_PLL_DIG_CHAN_MAP_BAND_SELECT_MASK) == 0U) &&
        (lpm_denom_selected == 0x4000000))
    {
        /* this part is duplicated from int32_t XCVR_LCL_RsmReadCfoComp(void) in XCVR/drv/nxp_xcvr_lcl_ctrl.c */
        if ((cfo_in_hz > 500000) || (cfo_in_hz < -500000)) /* Test CFO limitation to keep to ~20bits */
        {
            api_return = KOSA_StatusError;
        }
        else
        {
            /* Each bit in the PLL_OFFSET_CTRL register is about 0.9537 Hz of frequency change so convert by multiply by 67 and
             * dividing by 64 */
            int32_t itemp                 = cfo_in_hz;
            itemp                         = itemp * 67;
            itemp                         = itemp / 64;
            XCVR_PLL_DIG->PLL_OFFSET_CTRL = XCVR_PLL_DIG_PLL_OFFSET_CTRL_PLL_NUMERATOR_OFFSET(itemp);
        }
    }
    else
    {
        api_return = KOSA_StatusError;
    }
    /* Release wake up to other CPU */
    PLATFORM_RemoteActiveRel();
    return api_return;
}
#endif

/*! *********************************************************************************
 * \brief  Set Rx Pdu handling timing
 * \param[in]  0: normal mode
 *             1: delay Rx Pdu handling after TX.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetRxMode(uint32_t mode)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {(uint32_t) mode};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_SetRxMode,
                                (const uint8_t*)"\x04", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

/*! *********************************************************************************
 * \brief  Set sleep clock accuracy for the device.
 * \param[in]  sca: ranges from 0 to 7
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetSleepClockAccuracy(uint32_t sca)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {sca};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_ConfigureSCA,
                                (const uint8_t*)"\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;

    if ( ret!=0 )
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

/*!
 * \brief Sets the security events to be monitored in LL and the callback to be called upon security event detection.
 *
 * \param[in] bitmask containing security events
 * Supported security events:
 * bit 0 set: enable gSecEvt_LlLenOverflow_c event reporting
 * \param[in] callback called when security events (enabled through mask) have been detected
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 */
osa_status_t Controller_ConfigureIDSSecurityEventReporting(nbu_security_event_callback_t cb, uint32_t securityEventsBitmask)
{
    osa_status_t api_return = KOSA_StatusSuccess;
    int32_t      ret        = 0;
    uint32_t     tab[1]     = {securityEventsBitmask};
    bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret, API_Controller_ConfigureIDSSecurityEvent,
                                (const uint8_t*)"\x01", tab, 4U);
    assert(rpmsg_status);
    (void)rpmsg_status;
    
    if (cb != NULL)
    {
      PLATFORM_RegisterSecurityEventCb(cb);
    }

    if ((ret != 0) || (cb == NULL))
    {
        api_return = KOSA_StatusError;
    }
    return api_return;
}

/*! *********************************************************************************
 * \brief  Read the NBU memory
 * \param[in]  address: NBU memory address
 * \param[in]  size:    number of bytes to read, limited to 32 bytes maximum
 * \param[in]  pBuffer: buffer to save the data
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ReadMemory(uint32_t address, uint32_t size, void* pBuffer)
{
    osa_status_t api_status;
    int8_t       ret[36];
    uint32_t     tab[2]     = {address, size};
    
    if ( size > sizeof(ret) - 4U )
    {
        api_status = KOSA_StatusError;
    }
    else
    {
        bool rpmsg_status = PLATFORM_NbuApiReq((uint8_t*)&ret[0], API_Controller_ReadMemory,
                                    (const uint8_t*)"\x04\x04", tab, 4U + size);
        if (rpmsg_status)
        {
          api_status = (osa_status_t)_GET32(ret);
          if( api_status == KOSA_StatusSuccess )
          {
            memcpy(pBuffer, ret+4U, size);
          }
        }
        else
        {
          api_status = KOSA_StatusError;
        }
    }
    return api_status;
}
