/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCMGR_IMU_INTERNAL_H
#define MCMGR_IMU_INTERNAL_H

/* If IMU is located in an other power domain that is in lowpower, these routines shall be implemented
   to request/release the IMU power domain to get active. */
/*!
 * @addtogroup mcmgr_internal
 * @{
 */

/*!
 * @brief Internal platform-specific function for requesting the IMU power domain to get active.
 *
 * This function request the IMU power domain to get active.
 */
void mcmgr_imu_remote_active_req(void);

/*!
 * @brief Internal platform-specific function for releasing the IMU power domain.
 *
 * This function release the IMU power domain.
 */
void mcmgr_imu_remote_active_rel(void);

#if (defined(MCMGR_DEFERRED_CALLBACK_ALLOWED) && (MCMGR_DEFERRED_CALLBACK_ALLOWED == 1U))
/*!
 * @brief IMU Interrupt service routine deferred call implementation.
 *
 * This function has to be implemented on the application level when MCMGR_DEFERRED_CALLBACK_ALLOWED macro is set.
 * The purpose is to make the interrupt service routine as short as possible, performing only really necessary steps
 * in the interrupt context and defer the processing outside the interrupt context. When deferred call enabled
 * (MCMGR_DEFERRED_CALLBACK_ALLOWED set), the imu_rx_isr() only clears the interrupt flag and calls this user-defined
 * callback function that typically notifies the suspended isr processing task and finishes.
 */
extern void mcmgr_imu_deferred_call(uint32_t param);
#endif

/*! @} */

#endif /* MCMGR_IMU_INTERNAL_H */
