/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_OT_H_
#define _FWK_PLATFORM_OT_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Low level initialization for OpenThread/15.4, can be used to initialize 15.4 Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitOt(void);

/*!
 * \brief Low level deinitialization for OpenThread/15.4, can be used to deinitialize 15.4 Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateOt(void);

/*!
 * \brief Low level reset for OpenThread/15.4, can be used to reset the CPU2
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetOt(void);

/*!
 * \brief Get MAC address for OpenThread/15.4
 *
 * \param  eui64_address at least 8 byte of storage to receive 64 bit address.
 */
void PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address);

#ifdef __cplusplus
}
#endif

#endif /* _FWK_PLATFORM_OT_H_ */