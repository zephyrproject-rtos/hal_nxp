/*!
 * Copyright 2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * \file fwk_platform_zb.h
 * \brief PLATFORM abstraction API for Zigbee
 *
 */

#ifndef _FWK_PLATFORM_ZB_H_
#define _FWK_PLATFORM_ZB_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

typedef void (*platform_zb_rx_callback_t)(uint8_t *data, uint16_t len, void *param);

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Initialize the platform for Zigbee
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitZigbee(void);

/*!
 * \brief Initializes Zigbee MAC interface
 *
 * \param[in] callback Callback called by PLATFORM layer when a Zigbee MAC message has been received
 * \param[in] param Optional parameter passed to the callback
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitZbMacInterface(platform_zb_rx_callback_t callback, void *param);

/*!
 * \brief Terminates Zigbee MAC interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateZbMacInterface(void);

/*!
 * \brief Hard reset of the Zigbee MAC Interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetZbMacInterface(void);

/*!
 * \brief Sends a Zigbee MAC message to Controller.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to Zigbee MAC message buffer
 * \param[in] len size of the message
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_SendZbMacMessage(uint8_t *msg, uint32_t len);

/*!
 * \brief Initializes Zigbee PHY interface
 *
 * \param[in] callback Callback called by PLATFORM layer when a Zigbee PHY message has been received
 * \param[in] param Optional parameter passed to the callback
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitZbPhyInterface(platform_zb_rx_callback_t callback, void *param);

/*!
 * \brief Terminates Zigbee PHY interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateZbPhyInterface(void);

/*!
 * \brief Hard reset of the Zigbee PHY Interface
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetZbPhyInterface(void);

/*!
 * \brief Sends a Zigbee PHY message to Controller.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to Zigbee MAC message buffer
 * \param[in] len size of the message
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_SendZbPhyMessage(uint8_t *msg, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif /* _FWK_PLATFORM_ZB_H_ */
