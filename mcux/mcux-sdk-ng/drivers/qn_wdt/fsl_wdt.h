/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2019, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_WDT_H_
#define FSL_WDT_H_

#include "fsl_common.h"

/*!
 * @addtogroup qn_wdt
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief WDT driver version */
#define FSL_WDT_DRIVER_VERSION (MAKE_VERSION(2, 0, 2))
/*! @} */

/*! @brief Describes WDT configuration structure. */
typedef struct _wdt_config
{
    bool enableWdtReset; /*!< true: Watchdog timeout will cause a chip reset
                                   false: Watchdog timeout will not cause a chip reset */
    uint32_t loadValue;  /*!< Load value, default value is 0xFFFFFFFF */
} wdt_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/*!
 * @brief Initializes the WDT with configuration.
 *
 * This function initializes the WDT.
 *
 * @param base WDT peripheral base address.
 * @param config pointer to configuration structure
 */
void WDT_Init(WDT_Type *base, const wdt_config_t *config);

/*!
 * @brief Disable the WDT peripheral.
 *
 * This function shuts down the WDT.
 *
 * @param base WDT peripheral base address.
 */
void WDT_Deinit(WDT_Type *base);

/*!
 * @brief  Unlock WDT access
 *
 * This function unlock WDT access.
 *
 * @param base WDT peripheral base address.
 */
static inline void WDT_Unlock(WDT_Type *base)
{
    base->LOCK = 0x1ACCE551;
}

/*!
 * @brief  Lock WDT access
 *
 * This function unlock WDT access.
 *
 * @param base WDT peripheral base address.
 */
static inline void WDT_Lock(WDT_Type *base)
{
    base->LOCK = 0;
}

/*!
 * @brief Clears status flags.
 *
 * This function clears WDT status flag.
 *
 * @param base WDT peripheral base address.
 */
static inline void WDT_ClearStatusFlags(WDT_Type *base)
{
    WDT_Unlock(base);
    base->INT_CLR = WDT_INT_CLR_INTCLR_MASK;
    WDT_Lock(base);
}

/*!
 * @brief Initializes WDT configure structure
 *
 * This function initializes the WDT configure structure to default value. The default
 * value are:
 * @code
 *   config->enableWdtReset = true;
 *   config->loadValue = 0xffffffff;
 * @endcode
 * @param config pointer to WDT config structure
 */
void WDT_GetDefaultConfig(wdt_config_t *config);

/*!
 * @brief Refresh WDT counter
 *
 * This function feeds the WDT.
 * This function should be called before WDT timer is in timeout.
 *
 * @param base WDT peripheral base address.
 * @param  cycle  time-out interval
 */
static inline void WDT_Refresh(WDT_Type *base, uint32_t cycle)
{
    uint32_t primask;

    primask = DisableGlobalIRQ();
    WDT_Unlock(base);
    base->LOAD = cycle;
    WDT_Lock(base);
    EnableGlobalIRQ(primask);
}
#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* FSL_WDT_H_*/
