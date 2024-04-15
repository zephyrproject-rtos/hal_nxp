/* -------------------------------------------------------------------------- */
/*                           Copyright 2023 NXP                               */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_H_
#define _FWK_PLATFORM_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

#define PLATFORM_OSTIMER_CLK kOSC32K_to_OSTIMER_CLK

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

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
