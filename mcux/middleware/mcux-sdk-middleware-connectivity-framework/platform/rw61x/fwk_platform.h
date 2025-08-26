/*!
 * Copyright 2021-2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform.h
 * \brief PLATFORM abstraction for general purpose use
 *
 */

#ifndef _FWK_PLATFORM_H_
#define _FWK_PLATFORM_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#ifndef PLATFORM_TM_INSTANCE
#define PLATFORM_TM_INSTANCE 0U
#endif

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief  Initialize Timer Manager
 *
 *    This API will initialize the Timer Manager and the required clocks
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitTimerManager(void);

/*!
 * \brief Initializes timestamp module
 *
 */
void PLATFORM_InitTimeStamp(void);

/*!
 * \brief Returns current timestamp in us
 *
 * \return uint64_t timestamp in us
 */
uint64_t PLATFORM_GetTimeStamp(void);

/*!
 * \brief Returns the max timestamp value that can be returned by PLATFORM_GetTimeStamp
 *        Can be used by the user to handle timestamp wrapping
 *
 * \return uint64_t the max timestamp value
 */
uint64_t PLATFORM_GetMaxTimeStamp(void);

/*!
 * \brief Save timestamp module before entering power down
 *
 */
void PLATFORM_TimeStampEnterLowPower(void);

/*!
 * \brief Restore timestamp module after exit from power down
 *
 */
void PLATFORM_TimeStampExitPowerDown(void);

#endif /* _FWK_PLATFORM_H_ */
