/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPC_H_
#define FSL_GPC_H_

#include "fsl_common.h"

/*!
 * @addtogroup gpc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief GPC driver version 2.0.0. */
#define FSL_GPC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Enumeration of the memory power gate control.
 *
 * Once the clock gate is enabled, the responding part would be powered off and contents are not
 * retained in Partial SLEEP mode.
 */
enum _gpc_memory_power_gate
{
    kGPC_MemoryPowerGateL2Cache = GPC_MPCTR_L2_PGE_MASK,   /*!< L2 Cache Power Gate. */
    kGPC_MemoryPowerGateITCM    = GPC_MPCTR_ITCM_PGE_MASK, /*!< ITCM Power Gate Enable. */
    kGPC_MemoryPowerGateDTCM    = GPC_MPCTR_DTCM_PGE_MASK, /*!< DTCM Power Gate Enable. */
};

/*!
 * @brief GPC flags.
 */
enum _gpc_status_flags
{
    kGPC_PoweredDownFlag = GPC_PGS_PS_MASK, /*!< Power status. HP domain was powered down for the
                                                 previous power down request. */
};

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name Memory power Control
 * @{
 */
/*!
 * @brief Control power for memory.
 *
 * @param base GPC peripheral base address.
 * @param modules Mask value for Modules to be operated, see to #_gpc_memory_power_gate.
 * @param enable Enable the power or not.
 */
static inline void GPC_EnableMemoryGate(GPC_Type *base, uint32_t modules, bool enable)
{
    if (enable)
    {
        base->MPCTR |= modules;
    }
    else
    {
        base->MPCTR &= ~modules;
    }
}

/*!
 * @}
 */

/*!
 * @name Partial sleep source
 * @{
 */

/*!
 * @brief Enable the modules as wakeup sources of PSLEEP (Partial Sleep) mode.
 *
 * In PSLEEP mode, HP domain is powered down, while LP domain remains powered on so peripherals in
 * LP domain can wakeup the system from PSLEEP mode via interrupts. In PSLEEP mode, system clocks
 * are stopped and peripheral clocks of LP domain can be optionally on. LP domain peripherals can
 * generate interrupt either asynchronously or need its peripheral clock on, depending on what kind
 * of wakeup event is expected. Refer to the corresponding module description about what kind of
 * interrupts are supported by the module.
 *
 * @param base GPC peripheral base address.
 * @param source Wakeup source for responding module, see to gpc_wakeup_source_t.
 * @param enable Enable the wakeup source or not.
 */
void GPC_EnablePartialSleepWakeupSource(GPC_Type *base, gpc_wakeup_source_t source, bool enable);

/*!
 * @brief Get if indicated wakeup module just caused the wakeup event to exit PSLEEP mode.
 *
 * This function returns if the responding wakeup module just caused the MCU to exit PSLEEP mode.
 * In hardware level, the flags of wakeup source are read only and will be cleared by cleaning the
 * interrupt status of the corresponding wakeup module.
 *
 * @param base GPC peripheral base address.
 * @param source Wakeup source for responding module, see to gpc_wakeup_source_t.
 * @retval true  - Indicated wakeup flag is asserted.
 * @retval false - Indicated wakeup flag is not asserted.
 */
bool GPC_GetPartialSleepWakeupFlag(GPC_Type *base, gpc_wakeup_source_t source);

/*!
 * @brief Switch to the Partial Sleep mode.
 *
 * This function controls if the system will enter Partial SLEEP mode or remain in STOP mode.
 *
 * @param base GPC peripheral base address.
 * @param enable Enable the gate or not.
 */
static inline void GPC_EnablePartialSleepMode(GPC_Type *base, bool enable)
{
    if (enable)
    {
        base->PGC |= GPC_PGC_PSE_MASK;
    }
    else
    {
        base->PGC &= ~GPC_PGC_PSE_MASK;
    }
}

/*!
 * @}
 */

/*!
 * @name Power gate control
 * @{
 */

/*!
 * @brief Configure the power up sequence.
 *
 * There will be two steps for power up sequence:
 * - After a power up request, GPC waits for a number of IP BUS clocks equal to the value of SW
 *   before turning on the power of HP domain. SW must not be programmed to zero.
 * - After GPC turnning on the power of HP domain, it waits for a number of IP BUS clocks equal
 *   to the value of SW2ISO before disable the isolation of HP domain. SW2ISO must not be
 *   programmed to zero.
 *
 * @param base GPC peripheral base address.
 * @param sw Count of IP BUS clocks before disabling the isolation of HP domain.
 * @param sw2iso Count of IP BUS clocks before turning on the power of HP domain.
 */
static inline void GPC_ConfigPowerUpSequence(GPC_Type *base, uint32_t sw, uint32_t sw2iso)
{
    base->PUPSCR = GPC_PUPSCR_SW2ISO(sw2iso) | GPC_PUPSCR_SW(sw);
}

/*!
 * @brief Configure the power down sequence.
 *
 * There will be two steps for power down sequence:
 * - After a power down request, the GPC waits for a number of IP BUS clocks equal to the value of
 *   ISO before it enables the isolation of HP domain. ISO must not be programmed to zero.
 * - After HP domain is isolated, GPC waits for a number of IPG BUS clocks equal to the value of
 *   ISO2SW before it turning off the power of HP domain. ISO2SW must not be programmed to zero.
 *
 * @param base GPC peripheral base address.
 * @param iso Count of IP BUS clocks before it enables the isolation of HP domain.
 * @param iso2w Count of IP BUS clocks before it turning off the power of HP domain.
 */
static inline void GPC_ConfigPowerDownSequence(GPC_Type *base, uint32_t iso, uint32_t iso2w)
{
    base->PDNSCR = GPC_PDNSCR_ISO(iso) | GPC_PDNSCR_ISO2SW(iso2w);
}

/*!
 * @brief Get the status flags of GPC.
 *
 * @param base GPC peripheral base address.
 * @return Mask value of flags, see to #_gpc_status_flags.
 */
static inline uint32_t GPC_GetStatusFlags(GPC_Type *base)
{
    return base->PGS;
}

/*!
 * @brief Clear the status flags of GPC.
 *
 * @param base GPC peripheral base address.
 * @param flags Mask value of flags to be cleared, see to #_gpc_status_flags.
 */
static inline void GPC_ClearStatusFlags(GPC_Type *base, uint32_t flags)
{
    base->PGS = flags;
}

/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif
/*!
 * @}
 */
#endif /* FSL_GPC_H_ */
