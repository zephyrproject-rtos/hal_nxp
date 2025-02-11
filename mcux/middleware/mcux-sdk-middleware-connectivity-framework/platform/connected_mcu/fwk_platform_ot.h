/*!
 * Copyright 2021-2025 NXP
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

/*!
 * \brief Return OpenThread / iEEE 802.15.4 MAC address
 *
 *  If MAC address already programmed return its value.
 *  If not yet programmed generate one using the OUI defined by the IEEE_15_4_ADDR_OUI
 *  macro. The remaining 5 bytes are picked either from the Radio UID or generated
 *  randomly.
 * \param eui64_address pointer on buffer storage supplied by caller to receive the 8
 * bytes of EUI-64 MAC address.
 *
 */
void PLATFORM_GetIeee802_15_4Addr(uint8_t *eui64_address);

#ifdef __cplusplus
}
#endif

#endif /* _PLATFORM_OT_H_ */
