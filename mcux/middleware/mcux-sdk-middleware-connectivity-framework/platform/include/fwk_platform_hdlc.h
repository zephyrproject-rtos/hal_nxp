/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_HDLC_H_
#define _FWK_PLATFORM_HDLC_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

typedef void (*platform_hdlc_rx_callback_t)(uint8_t *data, uint16_t len, void *param);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Initializes HDLC interface
 *
 * \param[in] callback Callback called by PLATFORM layer when a HDLC message has been received
 * \param[in] param Optional parameter passed to the callback
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitHdlcInterface(platform_hdlc_rx_callback_t callback, void *param);

/*!
 * \brief Terminates HDLC interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateHdlcInterface(void);

/*!
 * \brief Hard reset of the HDLC Interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetHdlcInterface(void);

/*!
 * \brief Sends a Spinel HDLC message to Controller.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to Spinel HDLC message buffer
 * \param[in] len size of the message
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_SendHdlcMessage(uint8_t *msg, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* _FWK_PLATFORM_HDLC_H_ */