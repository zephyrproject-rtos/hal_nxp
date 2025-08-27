/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022, 2025 NXP                    */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _PLATFORM_BLE_H_
#define _PLATFORM_BLE_H_

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_Ble
 * The FWK_Platform_Ble module
 *
 * FWK_Platform_Ble module provides APIs to set BLE platform parameters.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include "fwk_platform.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Low level initialization for BLE Controller
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitBle(void);

/*!
 * \brief Registers HCI RX callback for upper layers, likely called from Host's
 *        HCI transport layers. The callback is called when PLATFORM has
 *        received a message from lower transport layers such as RPMSG or UART
 *
 * \param[in] callback function pointer to callback. Can be NULL to unregister
 *            the callback.
 * \return int return status: >=0 for success, <0 for errors
 */
int  PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len));

/*!
 * \brief Sends a HCI message to Controller.
 *        This is usually called from Host's HCI transport layers.
 *        This allows complete abstraction of physical transport layers from one
 *        platform to another.
 *
 * \param[in] msg pointer to HCI message buffer
 * \param[in] len size of the message
 * \return int 0 if success, negative value if error
 */
int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len);

/* \brief Shutdown BLE Controller
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_TerminateBle(void);

/* \brief Extra procedures during HCI init from Host, likely to check if the
 *        HCI link is valid and execute Vendor specific init
 *
 * \return int return status: >=0 for success, <0 for errors
 */
int PLATFORM_StartHci(void);

#ifdef __cplusplus
}
#endif

/*!
 * @}  end of FWK_Platform_Ble addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* _PLATFORM_BLE_H_ */
