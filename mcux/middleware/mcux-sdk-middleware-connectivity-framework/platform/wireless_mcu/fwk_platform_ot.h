/*!
 * Copyright 20021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PLATFORM_OT_H_
#define _PLATFORM_OT_H_

#include "EmbeddedTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief platform initialization for OpenThread
 *
 *  this function prepares:
 *     platform multicore and intercore service channel
 *     configure RFMC module, NBU domain and start CM3 core
 *     handshaking for chip revision (A0 or A1)
 *     loads some HW parameters from Flash to RAM
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitOT(void);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_OT_H_ */
