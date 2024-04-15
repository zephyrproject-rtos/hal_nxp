/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_COEX_H_
#define _FWK_PLATFORM_COEX_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

#define connBle_c      (uint8_t)(1U << 0)
#define conn802_15_4_c (uint8_t)(1U << 1)
#define connWlan_c     (uint8_t)(1U << 2)
#define connAll_c      (connBle_c | conn802_15_4_c | connWlan_c)

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Initialize a single or a combination of controllers
 *
 * \param[in] controllersMask mask of combined controllers_t
 * \return int >=0 for success, <0 for errors
 */
int PLATFORM_InitControllers(uint8_t controllersMask);

/*!
 * \brief Terminate a single or a combination of controllers
 *
 * \param[in] controllersMask
 * \return int >=0 for success, <0 for errors
 */
int PLATFORM_TerminateControllers(uint8_t controllersMask);

/*!
 * \brief Returns current states of each Controller
 *
 * \return uint8_t mask indicating the state of each Controller
 */
uint8_t PLATFORM_GetRunningControllers(void);

#ifdef __cplusplus
}
#endif

#endif /* _FWK_PLATFORM_COEX_H_ */