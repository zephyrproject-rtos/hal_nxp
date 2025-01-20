/*
 * Copyright 2018-2019 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_WDT_H_
#define FSL_WDT_H_

#include "fsl_common.h"

/*!
 * @addtogroup wdt
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Defines WDT driver version 2.0.1. */
#define FSL_WDT_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief Describes WDT flags. */
enum _wdt_flags
{
    kWDT_TimeoutFlag   = WDT_WDMOD_TOF_MASK, /*!< WDT timeout flag, set when WDT times out. */
    kWDT_InterruptFlag = WDT_WDMOD_INT_MASK, /*!< WDT interrupt flag, set in interrupt mode, indicates WDT interrupt
                                                  due to WDT counter-underflow happens. */
};

/*! @brief Describes WDT configuration structure. */
typedef struct _wdt_config
{
    uint32_t timeoutCounter; /*!< Timeout counter for WDT, should be between 0xFF ~ 0x7FFFFF, indicates timeoutValue
                              between (TWDCLK * 256 * 4) and (TWDCLK * 224 * 4), TWDCLK = 1/WDT_CLK. */
    bool enableReset;        /*!< WDT reset enable, when enable, WDT timeout causes a chip reset. */
    bool enableWdog;         /*!< Enables or disables WDT. */
} wdt_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name WDT Initialization and De-initialization
 * @{
 */

/*!
 * @brief Initializes the WDT configuration structure.
 *
 * This function initializes the WDT configuration structure to default values. The default
 * values are as follows.
 * @code
 *   wdtConfig->timeoutValue = 0xFFFFU;
 *   wdtConfig->enableReset = true;
 *   wdtConfig->enableWdog = true;
 * @endcode
 *
 * @param config Pointer to the WDT configuration structure.
 * @see wdt_config_t
 */
void WDT_GetDefaultConfig(wdt_config_t *config);

/*!
 * @brief Initializes the WDT.
 *
 * This function initializes the WDT. When called, the WDT runs according to the configuration.
 *
 * This is an example.
 * @code
 *   wdt_config_t config;
 *   WDT_GetDefaultConfig(&config);
 *   config.timeoutValue = 0x7ffU;
 *   WDT_Init(wdt_base,&config);
 * @endcode
 *
 * @param base   WDT peripheral base address
 * @param config The configuration of WDT
 */
void WDT_Init(WDT_Type *base, const wdt_config_t *config);

/*!
 * @brief Shuts down the WDT.
 *
 * This function shuts down the WDT.
 */
void WDT_Deinit(WDT_Type *base);

/*! @} */

/*!
 * @name WDT Functional Operation
 * @{
 */

/*!
 * @brief Enables the WDT module.
 *
 *
 * @param base WDT peripheral base address
 */
static inline void WDT_Enable(WDT_Type *base)
{
    uint32_t modeVal = base->WDMOD;
    /* Reset flag bits to avoid improper operation. */
    modeVal &= ~((uint32_t)kWDT_TimeoutFlag | (uint32_t)kWDT_InterruptFlag);
    modeVal |= WDT_WDMOD_EN_MASK;

    base->WDMOD = modeVal;
}

/*!
 * @brief Gets the WDT all status flags.
 *
 * This function gets all status flags.
 *
 * This is an example for getting the Running Flag.
 * @code
 *   uint32_t status;
 *   status = WDT_GetStatusFlags (wdt_base) & kWDT_TimeoutFlag;
 * @endcode
 * @param base        WDT peripheral base address
 * @return            State of the status flag: asserted (true) or not-asserted (false).@see _wdt_flags
 *                    - true: a related status flag has been set.
 *                    - false: a related status flag is not set.
 */
static inline uint32_t WDT_GetStatusFlags(WDT_Type *base)
{
    return base->WDMOD;
}

/*!
 * @brief Clears the WDT flag.
 *
 * This function clears the WDT status flag.
 *
 * This is an example for clearing the timeout (interrupt) flag.
 * @code
 *   WDT_ClearStatusFlags(wdt_base,kWDT_TimeoutFlag);
 * @endcode
 * @param base        WDT peripheral base address
 * @param mask        The status flags to clear, only support clear kWDT_TimeoutFlag.
 */
static inline void WDT_ClearStatusFlags(WDT_Type *base, uint32_t mask)
{
    base->WDMOD |= mask;
}

/*!
 * @brief Sets the WDT timeout counter.
 *
 * This function sets the timeout counter.
 * The timeoutCount should be between 0xFF ~ 0x7FFFFF, writing values below 0xFF cause
 * 0x0000 00FF to be loaded to the WDT timer counter. The minimum timeoutValue is
 * (TWDCLK * 256 * 4) and the maximum value is (TWDCLK * 224 * 4), TWDCLK = 1/WDT_CLK.
 *
 * @param base WDT peripheral base address
 * @param timeoutCount WDT timeout counter; count of WDT clock tick.
 */
static inline void WDT_SetTimeoutCounter(WDT_Type *base, uint32_t timeoutCount)
{
    base->WDTC = WDT_WDTC_Count(timeoutCount);
}

/*!
 * @brief Feed WDT timer.
 *
 * This is a mandatory step, if this function isn't called after enabling the WDT, WDT will
 * ignore timeout errors and will not generate a WDT interrupt or reset the chip.
 *
 * @param base WDT peripheral base address
 *
 */
static inline void WDT_Feed(WDT_Type *base)
{
    uint32_t primask;
    primask      = DisableGlobalIRQ();
    base->WDFEED = 0xAA;
    base->WDFEED = 0x55;
    EnableGlobalIRQ(primask);
}

/*!
 *
 * @brief Get the current value of WDT
 *
 * The value reported by this function is older than the actual one. Retrieving this value takes up to
 * 6 watchdog clock cycles + 6 system clock cycles due to the lock and synchronization procedure.
 *
 * @param base WDT peripheral base address
 * @return Current value of WDT
 *
 */
static inline uint32_t WDT_GetCurrentCount(WDT_Type *base)
{
    return base->WDTV;
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_WDT_H_ */
