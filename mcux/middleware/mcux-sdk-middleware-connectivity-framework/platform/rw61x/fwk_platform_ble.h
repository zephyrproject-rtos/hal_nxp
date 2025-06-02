/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2024 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_BLE_H_
#define _FWK_PLATFORM_BLE_H_

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
#include <stdint.h>
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Low level initialization for BLE Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_InitBle(void);

/*!
 * \brief Performs vendor specific initialization that uses HCI vendor commands.
 *        This function is already called during init.
 *        Note: can cause troubles with some BLE Host. Can be disabled by setting
 *        <gPlatformDisableVendorSpecificInit>
 */
void PLATFORM_VendorSpecificInit(void);

/*!
 * \brief Shutdown BLE Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateBle(void);

/*!
 * \brief Hard reset of the BLE Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ResetBle(void);

/*!
 * \brief Extra procedures during HCI init from Host, likely to check if the
 *        HCI link is valid and execute Vendor specific init
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_StartHci(void);

/*!
 * \brief Registers HCI RX callback for upper layers, likely called from Host's
 *        HCI transport layers. The callback is called when PLATFORM has
 *        received a message from lower transport layers such as RPMSG or UART
 *
 * \param[in] callback function pointer to callback. Can be NULL to unregister
 *            the callback.
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len));

/*!
 * \brief Sends a HCI message to Controller.
 *        This is usually called from Host's HCI transport layers.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to HCI message buffer
 * \param[in] len size of the message
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len);

/*!
 * \brief Allows BLE Controller to enter low power
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_EnableBleLowPower(void);

/*!
 * \brief Disallows BLE Controller to enter low power
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_DisableBleLowPower(void);

/*!
 * \brief Requests BLE Controller wake up and hold it active while the request
 *        is asserted. Goes in pair with PLATFORM_ReleaseBleWakeUp and can be
 *        nested.
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_RequestBleWakeUp(void);

/*!
 * \brief Releases BLE Controller wake up request. Goes in pair with
 *        PLATFORM_RequestBleWakeUp and can be nested.
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_ReleaseBleWakeUp(void);

/*!
 * \brief Handle power state when receive message from Controller.
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_HandleControllerPowerState(void);

/*!
 * \brief Return Controller status
 *
 * \return true Controller is at active, and finish HCI initialization
 * \return false Controller is at sleep or not do HCI initialization
 */
bool PLATFORM_IsControllerActive(void);

#endif /* _FWK_PLATFORM_BLE_H_ */
