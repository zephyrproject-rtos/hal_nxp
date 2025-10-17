/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2022 NXP                          */
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

#if !defined(gAppMaxTxPowerDbm_c)
/*!
 * \brief Default max tx power used in case of BLE
 *        this is required to correctly configure voltages output
 */
#define gAppMaxTxPowerDbm_c 10
#endif /* gAppMaxTxPowerDbm_c */

#if !defined(gPlatformUseUniqueDeviceIdForBdAddr_d)
/*!
 * \brief use the device unique Id for BD address
 *
 * \details 0 : Use the NXP OUI for the three first bytes and generate randomly the last three ones
 *          1 : Use the NXP OUI for the three first bytes and the UID_LSB from RADIO_CTRL to define the last three ones
 *          2 : Read full BD adress from IFR will fallback on RNG method if there is nothing in IFR
 *
 * \note Setting gPlatformUseUniqueDeviceIdForBdAddr_d to 2 is experimental and has not been validated on programmed samples.
 */
#define gPlatformUseUniqueDeviceIdForBdAddr_d 0
#endif

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
 */
void PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len));

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

/*!
 * \brief Sends a HCI message to Controller with packet type specification.
 *        This is an alternative version of PLATFORM_SendHciMessage that allows
 *        specifying the packet type instead of serializing it into the original packet.
 *        This is well suited for platforms where the controller runs on the same core
 *        than the Host stack.
 *        Usually called from Host's HCI transport layers.
 *
 * \param[in] packetType HCI packet type identifier
 * \param[in] msg pointer to HCI message buffer
 * \param[in] len size of the message
 * \return int 0 if success, negative value if error
 */
int PLATFORM_SendHciMessageAlt(uint8_t packetType, uint8_t *msg, uint32_t len);

/*!
 * \brief retrieve BLE device address
 *
 * \param[out] bleDeviceAddress pointer to BLE device address bytes
 *
 */
void PLATFORM_GetBDAddr(uint8_t *bleDeviceAddress);

/*!
 * \brief enable secure key management for BLE.
 *
 * \return status of the operation, whether the security enabling was successful (=0) or failed.
 *
 */
int32_t PLATFORM_EnableBleSecureKeyManagement(void);

/*!
 * \brief Check if there is a pending connectivity activity
 * \note  Deprecated - shall use PLATFORM_GetRadioIdleDuration32K() API instead
 *
 * \return bool true  : No next connectivity activity
 *                 false : Pending connectivity activity
 */
bool PLATFORM_CheckNextBleConnectivityActivity(void);

/*!
 * \brief Get number of microseconds elapsed between current value (now) and the argument of this function.
 *
 * \param[in] controllerTimestamp timestamp coming from BLE link layer controller expressed in microseconds.
 *            This value is in the range [0 .. 2^30-1]
 *
 * \return uint64_t time difference expressed in microseconds, 0U in case of error.
 */
uint64_t PLATFORM_GetDeltaTimeStamp(uint32_t controllerTimestamp);

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
