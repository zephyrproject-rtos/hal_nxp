/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_LOWPOWER_H_
#define _FWK_PLATFORM_LOWPOWER_H_

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_LowPower
 * The FWK_Platform_LowPower module
 *
 * FWK_Platform_LowPower module provides APIs to handle Low Power .
 * @{
 */
/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include "fsl_pm_device.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#define PLATFORM_WFI_STATE             PM_LP_STATE_SLEEP
#define PLATFORM_SLEEP_STATE           PM_LP_STATE_SLEEP
#define PLATFORM_DEEP_SLEEP_STATE      PM_LP_STATE_DEEP_SLEEP
#define PLATFORM_POWER_DOWN_STATE      PM_LP_STATE_DEEP_POWER_DOWN
#define PLATFORM_DEEP_POWER_DOWN_STATE PM_LP_STATE_FULL_DEEP_POWER_DOWN

/* No constraints in WFI mode, all peripherals are available */
#define PLATFORM_WFI_CONSTRAINTS                                                                \
    17U, PM_RESC_MAIN_CLK_ON, PM_RESC_SYSXTAL_ON, PM_RESC_SYSPLLLDO_ON, PM_RESC_SYSPLLANA_ON,   \
        PM_RESC_FLEXSPI0_SRAM_ACTIVE, PM_RESC_SRAM12_128KB_ACTIVE, PM_RESC_SRAM13_128KB_ACTIVE, \
        PM_RESC_SRAM14_128KB_ACTIVE, PM_RESC_SRAM15_128KB_ACTIVE, PM_RESC_SRAM16_256KB_ACTIVE,  \
        PM_RESC_SRAM17_256KB_ACTIVE, PM_RESC_SRAM18_256KB_ACTIVE, PM_RESC_SRAM19_256KB_ACTIVE,  \
        PM_RESC_SRAM20_256KB_ACTIVE, PM_RESC_SRAM21_256KB_ACTIVE, PM_RESC_SRAM22_256KB_ACTIVE,  \
        PM_RESC_SRAM23_256KB_ACTIVE

/* No constraints in SLEEP mode, all peripherals are available */
#define PLATFORM_SLEEP_CONSTRAINTS                                                              \
    17U, PM_RESC_MAIN_CLK_ON, PM_RESC_SYSXTAL_ON, PM_RESC_SYSPLLLDO_ON, PM_RESC_SYSPLLANA_ON,   \
        PM_RESC_FLEXSPI0_SRAM_ACTIVE, PM_RESC_SRAM12_128KB_ACTIVE, PM_RESC_SRAM13_128KB_ACTIVE, \
        PM_RESC_SRAM14_128KB_ACTIVE, PM_RESC_SRAM15_128KB_ACTIVE, PM_RESC_SRAM16_256KB_ACTIVE,  \
        PM_RESC_SRAM17_256KB_ACTIVE, PM_RESC_SRAM18_256KB_ACTIVE, PM_RESC_SRAM19_256KB_ACTIVE,  \
        PM_RESC_SRAM20_256KB_ACTIVE, PM_RESC_SRAM21_256KB_ACTIVE, PM_RESC_SRAM22_256KB_ACTIVE,  \
        PM_RESC_SRAM23_256KB_ACTIVE

/* Use selective RAM retention mechanism. */
#define PLATFORM_DEEP_SLEEP_CONSTRAINTS                                                                   \
    13U, PM_RESC_FLEXSPI0_SRAM_RETENTION, PM_RESC_SRAM12_128KB_RETENTION, PM_RESC_SRAM13_128KB_RETENTION, \
        PM_RESC_SRAM14_128KB_RETENTION, PM_RESC_SRAM15_128KB_RETENTION, PM_RESC_SRAM16_256KB_RETENTION,   \
        PM_RESC_SRAM17_256KB_RETENTION, PM_RESC_SRAM18_256KB_RETENTION, PM_RESC_SRAM19_256KB_RETENTION,   \
        PM_RESC_SRAM20_256KB_RETENTION, PM_RESC_SRAM21_256KB_RETENTION, PM_RESC_SRAM22_256KB_RETENTION,   \
        PM_RESC_SRAM23_256KB_RETENTION

/* POWER DOWN mode has no configuration options. */
#define PLATFORM_POWER_DOWN_CONSTRAINTS 0

/* DEEP POWER DOWN mode has no configuration options. */
#define PLATFORM_DEEP_POWER_DOWN_CONSTRAINTS 0

/* -------------------------------------------------------------------------- */
/*                              Public type definition                        */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Initialize platform specific resources for low power support.
 *
 */
void PLATFORM_LowPowerInit(void);

/*!
 * \brief Initialize a wake up timer
 *        Should be called during low power initialization.
 *
 */
void PLATFORM_InitWakeUpTimer(void);

/*!
 * \brief Initialize wireless chip module.
 *
 */
uint8_t PLATFORM_ControllerLowPowerInit(void);

/*!
 * \brief Start a wake up timer for next tickless idle period
 *        Should be called during low power entry procedure.
 *
 * \param[in] timeOutUs maximum timeout in microsec
 */
void PLATFORM_StartWakeUpTimer(uint64_t timeOutUs);

/*!
 * \brief Stops previously started wake up timer if the tickless period ended
 *         earlier than expected. Should be called after exiting low power.
 *
 */
void PLATFORM_StopWakeUpTimer(void);

/*!
 * \brief Returns current timestamp in us, usually called before and after tickless
 *        period to compute the number of ticks to update RTOS timebase.
 *
 * \return uint64_t Timestamp value in us
 */
uint64_t PLATFORM_GetLowPowerTimestampUs(void);

/*!
 * \brief Converts timestamp values returned by PLATFORM_GetLowPowerTimestamp to
 *        a duration in us and handles counter wrapping.
 *
 * \param[in] enterLowPowerTimestamp Timestamp measured before entering tickless period
 * \param[in] exitLowPowerTimestamp Timestamp measured after exiting tickless period
 * \return uint64_t Computed duration in us
 */
uint64_t PLATFORM_GetLowPowerDurationUs(uint64_t enterLowPowerTimestamp, uint64_t exitLowPowerTimestamp);

/*!
 * \brief Platform module can implement platform specific methods to execute
 *        when entering and exiting any low power mode. \n
 *        Those methods should implement only mandatory procedures for the
 *        platform, compatible with any connectivity protocol.
 */
void PLATFORM_EnterLowPower(void);

/*!
 * \brief Platform specific procedures to execute when exiting any low power mode
 *
 */
void PLATFORM_ExitLowPower(void);

/*!
 * \brief Power gated low power modes often require specific
 *        entry/exit low power procedures, those should be implemented
 *        in the following API.
 *
 */
void PLATFORM_EnterPowerDown(void);

/*!
 * \brief Power gated low power modes often require specific
 *        entry/exit low power procedures, those should be implemented
 *        in the following API.
 *
 */
void PLATFORM_ExitPowerDown(void);

/*!
 * \brief Specific low power entry procedure when going to Deep Power Down mode (RAMOFF)
 *
 */
void PLATFORM_EnterDeepPowerDown(void);

/*!
 * \brief Check which banks need to be retained
 * \note This function is linker script specific.\n
 *       Amelioration handle by this function :\n
 *       - There is a free block at the end of the heap, so if the heap is on
 *       the top of the RAM. No need to retain all banks upper that the last one
 *       used by the heap.
 *
 * \return uint32_t mask of which bank needs to be retained
 */
uint32_t PLATFORM_GetDefaultRamBanksRetained(void);

/*!
 * \brief Set the banks that need to be retained in lowpower
 *
 * \param[in] uint32_t mask of which bank needs to be retained
 */
void PLATFORM_SetRamBanksRetained(uint32_t bank_mask);

/*!
 * \brief Check if device is allowed to enter low power mode.
 *
 * \param[in] uint8_t Zero on allowed or one on not allowed.
 */
uint8_t PLATFORM_AllowEnterLowPower(void);
/*!
 * @}  end of FWK_Platform_LowPower addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */

#endif /* _FWK_PLATFORM_LOWPOWER_H_ */
