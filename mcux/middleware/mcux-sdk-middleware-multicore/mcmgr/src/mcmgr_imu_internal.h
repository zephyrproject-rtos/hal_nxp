/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
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

/*! @} */

#endif /* MCMGR_IMU_INTERNAL_H */
