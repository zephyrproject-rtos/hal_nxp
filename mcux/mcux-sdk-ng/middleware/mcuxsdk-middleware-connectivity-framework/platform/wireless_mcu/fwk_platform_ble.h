/* -------------------------------------------------------------------------- */
/*                           Copyright 2021-2026 NXP                          */
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
#include "fwk_config.h"
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
 */
#define gPlatformUseUniqueDeviceIdForBdAddr_d 0
#endif

/* -------------------------------------------------------------------------- */
/*                           Public type definitions                          */
/* -------------------------------------------------------------------------- */

/*!
 * \brief HCI packet logging callback type
 *
 * \param[in] packet_type HCI packet type (0x01=CMD, 0x02=ACL, 0x04=EVENT, etc.)
 * \param[in] data pointer to HCI packet payload (without packet type byte)
 * \param[in] len length of payload
 * \param[in] is_rx true for RX (controller->host), false for TX (host->controller)
 */
typedef void (*platform_hci_log_cb_t)(uint8_t packet_type, const uint8_t *data, uint16_t len, bool is_rx);

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */
/*                            PLATFORM BLE HCI APIs                           */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Low level initialization for BLE Controller
 *
 * \return int 0 if success, 1 if already initialized, negative value if error.
 */
int PLATFORM_InitBle(void);

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
 * \brief Process HCI vendor event reception
 *
 * \details This function sends system-generated HCI vendor events into the HCI
 *          reception path, allowing them to be processed by the host stack as if
 *          they were received from the controller. This enables the system to
 *          generate synthetic HCI events for debug or diagnostic purposes.
 *
 * \param[in] data Pointer to HCI event data starting from the event code (0xFF for
 *                 vendor events), NOT including the HCI packet type indicator (0x04).
 *                 Format: [Event Code][Parameter Length][Parameters...]
 * \param[in] len  Total length of the HCI event data (excluding packet type)
 *
 * \return int 0 if success, negative value if error
 */
int PLATFORM_SendHciVendorEvent(uint8_t *data, uint32_t len);

/*!
 * \brief Register HCI packet logging callback
 *
 * \details This callback will be invoked for every HCI packet (TX and RX).
 *          Can be used by upper layers (DBG module, application) to log HCI traffic.
 *
 * \param[in] cb callback to be registered, NULL to unregister
 */
void PLATFORM_RegisterHciLogCallback(platform_hci_log_cb_t cb);

/* -------------------------------------------------------------------------- */
/*                           PLATFORM BLE utils APIs                          */
/* -------------------------------------------------------------------------- */

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
 * \brief Get number of microseconds elapsed between current value (now) and the argument of this function.
 *
 * \param[in] controllerTimestamp timestamp coming from BLE link layer controller expressed in microseconds.
 *            This value is in the range [0 .. 2^30-1]
 *
 * \return uint64_t time difference expressed in microseconds, 0U in case of error.
 */
uint64_t PLATFORM_GetDeltaTimeStamp(uint32_t controllerTimestamp);

/*!
 * \brief Configure max TX power in dBm for BLE
 *
 * \param[in] max_tx_power Desired max TX power in dBm
 */
void PLATFORM_SetBleMaxTxPower(int8_t max_tx_power);

/*!
 * \brief Send the wake up delay to the NBU if the application is not using the default value.
          The value to be sent is BOARD_LL_32MHz_WAKEUP_ADVANCE_HSLOT.
 *
 * \return int 0 if success, negative value if error
 */
int PLATFORM_InitWakeUpDelay(void);

/*!
 * \brief Send the SFC config to the NBU if the application is not using the default values.
 *        The SCF config can be customized through board defines:
 *          - BOARD_FRO32K_PPM_TARGET
 *          - BOARD_FRO32K_FILTER_SIZE
 *          - BOARD_FRO32K_MAX_CALIBRATION_INTERVAL_MS
 *          - BOARD_FRO32K_TRIG_SAMPLE_NUMBER
 *
 * \return int 0 if success, negative value if error
 */
int PLATFORM_InitSfc(void);

/*!
 * \brief Check if there is a pending connectivity activity
 * \note  Deprecated - shall use PLATFORM_GetRadioIdleDuration32K() API instead
 *
 * \return bool true  : No next connectivity activity
 *                 false : Pending connectivity activity
 */
bool PLATFORM_CheckNextBleConnectivityActivity(void);

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
