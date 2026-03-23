/*! *********************************************************************************
 * \defgroup CONTROLLER - Controller Interface
 * @{
 ********************************************************************************** */
/*!
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _CONTROLLER_API_H_
#define _CONTROLLER_API_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************************
* Include
************************************************************************************/

#include <stdint.h>
#include "fsl_os_abstraction.h"
#include "fwk_platform_ics.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! Default Tx Power on the advertising channel in dBm.
 *   Max Tx power is defined as gAppMaxTxPowerDbm_c
*/
#ifndef mAdvertisingDefaultTxPower_c
#define mAdvertisingDefaultTxPower_c    gAppMaxTxPowerDbm_c
#endif

/*! Default Tx Power on the connection channel in dBm.
 *   Max Tx power is defined as gAppMaxTxPowerDbm_c
*/
#ifndef mConnectionDefaultTxPower_c
#define mConnectionDefaultTxPower_c     gAppMaxTxPowerDbm_c
#endif

/*! By default PDUs with invalid parameter are ignored.
 */
#ifndef gLlInvalidPduHandlingType_c
#define gLlInvalidPduHandlingType_c     0U
#endif

typedef enum txChannelType_tag {
    gAdvTxChannel_c,
    gConnTxChannel_c
} txChannelType_t;

typedef enum advCodingScheme_tag {
    gAdv_CodingScheme_S8_S8_c = 0x00, /* primary adv coding scheme S8, secondary adv coding scheme S8 */
    gAdv_CodingScheme_S8_S2_c = 0x01, /* primary adv coding scheme S8, secondary adv coding scheme S2 */
    gAdv_CodingScheme_S2_S8_c = 0x02, /* primary adv coding scheme S2, secondary adv coding scheme S8 */
    gAdv_CodingScheme_S2_S2_c = 0x03, /* primary adv coding scheme S2, secondary adv coding scheme S2 */
} advCodingScheme_t;

typedef enum connCodingScheme_tag {
    gConn_CodingScheme_S8_S8_c = 0x00, /* initiation coding scheme S8, connection coding scheme S8 */
    gConn_CodingScheme_S8_S2_c = 0x01, /* initiation coding scheme S8, connection coding scheme S2 */
    gConn_CodingScheme_S2_S8_c = 0x02, /* initiation coding scheme S2, connection coding scheme S8 */
    gConn_CodingScheme_S2_S2_c = 0x03, /* initiation coding scheme S2, connection coding scheme S2 */
} connCodingScheme_t;

typedef enum connNotifMode_tag {
    gBleConnNotifAll_c = 0x00,     /* allow notification of any non-empty PDU */
    gBleConnNotifDataOnly_c = 0x01 /* allow notification of Data PDU only */
} connNotifMode_t;
/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

/*! *********************************************************************************
 * \brief  Sets the BD_ADDR.
 * \param[in]  packetType HCI packet Type
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError
 ********************************************************************************** */
osa_status_t Controller_SetDeviceAddress(uint8_t* bdAddr);


/*! *********************************************************************************
 * \brief  Sets the TX Power on the advertising or connection channel.
 * \param[in]  level    Power level (range 0-X) as defined in the table bellow.
 *                      (X=15 for MKW40 and X=31 for MKW41 and MKW38)
 * \param[in]  channel  Advertising or connection channel.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 *
 * \remarks This function executes synchronously.
 *
 * \remarks For MKW40Z BLE controller there are 16 possible power levels 0 <= N <= 15
 * for which the output power is distributed evenly between minimum and maximum power levels.
 * For further details see the silicon datasheet.
 *
 * \remarks For MKW41Z BLE controller there are 32 possible power levels 0 <= N <= 31
 * for which the output power is distributed evenly between minimum and maximum power levels.
 * For further details see the silicon datasheet.
 *
 * \remarks For MKW38/KW45 BLE controller there are 32 possible power levels 0 <= N <= 31
 * for which the output power is distributed evenly between minimum and maximum power levels.
 * For further details see the silicon datasheet. For this latter platform, the preferred
 * interface to set the TX power is Controller_SetTxPowerLevelDbm (see below) which does not
 * require any knowledge of the power tables.
 ********************************************************************************** */
osa_status_t Controller_SetTxPowerLevel(uint8_t level, txChannelType_t channel);

/*! *********************************************************************************
 * \brief  Sets the TX Power on the advertising or connection channel.
  * \param[in]  level_dbm    Power level in dBm.
 * \param[in]  channel      Advertising or connection channel.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 *
 * \remarks This function executes synchronously.
 ********************************************************************************** */
osa_status_t Controller_SetTxPowerLevelDbm(int8_t level_dbm, txChannelType_t channel);


/*! *********************************************************************************
 * \brief  Set the XCVR ANALOG LDO ANT TRIM register value.
 * \param[in]  power_dBm       maximum target tx power
 * \param[in]  ldo_ant_trim    LDO ANT TRIM to set
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetMaxTxPower(int8_t power_dBm, uint8_t ldo_ant_trim);

/*! *********************************************************************************
 * \brief  Set the XCVR_PLL_DIG's PLL_OFFSET_CTRL to change the BLE carrier frequency offset.
 * \param[in]  cfo_in_hz    signed offset in Hertz, in range [-500..500] KHz or +/-190 ppm.
 *
 * \remarks Positive/negative input will increase/decrease RF frequency correspondingly.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 *
 * \remarks Must be called only during BLE mode, otherwise will have unpredicted impact.
 ********************************************************************************** */
osa_status_t Controller_Set_PLL_OFFSET_CTRL(int32_t cfo_in_hz);

/*! *********************************************************************************
 * \brief  Set the seed for the PRNG.
 * \param[in]  seed    seed to be set for PRNG initial state
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetRandomSeed(void);


/*! *********************************************************************************
 * \brief  Configures the handling of PDU with invalid parameter.
 * \param[in]  pdu_handling_type    handling type for invalid PDU (0: ignore PDU, 1: disconnect link)
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ConfigureInvalidPduHandling(uint32_t pdu_handling_type);


/*! *********************************************************************************
 * \brief  Configures the advertising Coding scheme.
 * \param[in]  codingSch    coding scheme
 * \param[in]  handle       handle of ADV set [0,1..]
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ConfigureAdvCodingScheme(advCodingScheme_t codingSch, uint8_t handle);


/*! *********************************************************************************
 * \brief  Configures the connection Coding scheme.
 * \param[in]  codingSch    coding scheme
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ConfigureConnCodingScheme(connCodingScheme_t codingSch);

/*! *********************************************************************************
 * \brief  Configures the connection enhanced notification mode.
 * \param[in]  uint32    mode
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetConnNotificationMode(uint32_t mode);

/*! *********************************************************************************
 * \brief  Enables the security feature.
 * \param[in]  None
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_EnableSecurityFeature(void);


/*! *********************************************************************************
 * \brief  Get Next Link Layer event in us.
 * \param[in]  remaining_time until next event
 *         0 if no next event, >0 otheriwse.
 *      @Warning immediate next event shall always be >0
 *      @Warning API shall be called with OS scheduler disabled or interrupts masked
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_GetNextLinLayerEventUsUnsafe(uint32_t* remaining_time);

/*! *********************************************************************************
 * \brief  get BLE native clock in us.
 * \param[in]  timestamp
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_GetTimestamp(uint32_t* timestamp);

/*! *********************************************************************************
 * \brief  get BLE native clock in us.
 * \param[out]  ll_timing_slot Link layer timing slot
 * \param[out]  ll_timing_us   Link layer timing micro second offset inside the slot
 * \param[out]  tstmr          TSTMR value in us when capturing the link layer timing
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_GetTimestampEx(uint32_t* ll_timing_slot, uint16_t* ll_timing_us, uint64_t *tstmr);

/*! *********************************************************************************
 * \brief  Send FEM configuration to NBU.
 * \param[in]  fem_config_ptr  pointer to the config array.
 * \param[in]  config_len      length in bytes.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 *
 * \remarks
 * - Caller has to check config_len value. API uses it solely for message size handling.
 ********************************************************************************** */
osa_status_t Controller_SetFemConfig(const uint8_t* fem_config_ptr, uint8_t config_len);

/*! *********************************************************************************
 * \brief  Retrieve the encryption parameters of the connection.
 * \param[in]  conn_handle         connection handle
 * \param[in]  sk_or_skd_req       session key (0) or session key diversifier (1) required
 * \param[out] sk_or_skd           session key or session key diversifier
 * \param[out] iv                  initialization vector
 * \param[out] payload_counter_tx  payload counter for the next packet in the rx direction
 * \param[out] payload_counter_rx  payload counter for the next packet in the tx direction
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 *
 * \remarks 
 * - If the session key encryption is enabled, it will be returned encrypted
 * - The session key diversifier corresponds to the value of the latest encryption procedure
 *   in the controller.
 ********************************************************************************** */
osa_status_t Controller_GetEncryptionParam(uint16_t conn_handle, uint8_t sk_or_skd_req, 
                                           uint8_t  sk_or_skd[16], 
                                           uint8_t  iv[8],
                                           uint8_t  payload_counter_tx[5], 
                                           uint8_t  payload_counter_rx[5]);

/*! *********************************************************************************
 * \brief  request Link layer to enter low power.
 *      @Warning API shall be called with OS scheduler disabled or interrupts masked
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_EnterLowpower(void);

/*! *********************************************************************************
 * \brief  request Link layer to exit low power.
 *      @Warning API shall be called with OS scheduler disabled or interrupts masked
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ExitLowpower(void);

/*! *********************************************************************************
 * \brief  Set Rx Pdu handling timing
 * \param[in]  0: normal mode
 *             1: delay Rx Pdu handling after TX.
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_SetRxMode(uint32_t mode);

/*! *********************************************************************************
 * \brief Sets the SCA (Sleep Clock Accuracy) of the device.
 *
 * \param[in] SCA value (shall be in the range 0 to 7)
 * SCA field encoding
 * SCA  |       Accuracy in ppm
 *   0  |       251 ppm to 500 ppm
 *   1  |       151 ppm to 250 ppm
 *   2  |       101 ppm to 150 ppm
 *   3  |        76 ppm to 100 ppm
 *   4  |        51 ppm to  75 ppm
 *   5  |        31 ppm to  50 ppm
 *   6  |        21 ppm to  30 ppm
 *   7  |         0 ppm to  20 ppm
 * \return uint32 API status 0 success, others failure
********************************************************************************** */
osa_status_t Controller_SetSleepClockAccuracy(uint32_t sca);

/*!
 * \brief Sets the security events to be monitored in LL and the callback to be called upon security event detection.
 *
 * \param[in] bitmask containing security events
 * Supported security events:
 * bit 0 set: enable gSecEvt_LlLenOverflow_c event reporting
 * \param[in] callback called when security events (enabled through mask) have been detected
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 */
osa_status_t Controller_ConfigureIDSSecurityEventReporting(nbu_security_event_callback_t cb, uint32_t securityEventsBitmask);

/*! *********************************************************************************
 * \brief  Read the NBU memory
 * \param[in]  address: NBU memory address
 * \param[in]  size:    number of bytes to read, limited to 32 bytes per operation
 * \param[in]  pBuffer: buffer to save the data
 *
 * \return KOSA_StatusSuccess or KOSA_StatusError.
 ********************************************************************************** */
osa_status_t Controller_ReadMemory(uint32_t address, uint32_t size, void* pBuffer);

#ifdef __cplusplus
}
#endif

#endif /*_CONTROLLER_API_H_*/

/*! *********************************************************************************
* @}
********************************************************************************** */
