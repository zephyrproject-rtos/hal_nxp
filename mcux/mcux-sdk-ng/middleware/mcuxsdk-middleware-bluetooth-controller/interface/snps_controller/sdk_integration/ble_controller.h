/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _BLE_CONTROLLER_H_
#define _BLE_CONTROLLER_H_

#include <stdint.h>

/************************************************************************************
*************************************************************************************
* Definitions
*************************************************************************************
************************************************************************************/


/************************************************************************************
*************************************************************************************
* Structures/Data Types
*************************************************************************************
************************************************************************************/

typedef enum
{
    kBLEC_Success = 0U,
    kBLEC_UnknownHCICommand,
    kBLEC_Overflow,
    kBLEC_ErrorLLInit,
    kBLEC_ErrorLLHCIInit,
    kBLEC_ErrorSelectPowerTable,
    kBLEC_ErrorLLConfigCtx,
    kBLEC_ErrorLLSlpClkSrc,
    kBLEC_ErrorNotApplicable,
    kBLEC_InvalidParameter,
    kBLEC_UnknownError,
    kBLEC_CommandDisallowed,
    kBLEC_OutOfMemory,
    kBLEC_ErrorLLIrqPriorityInit
} blec_result_t;

typedef enum
{
    kBLEC_HciCommandPacket          = 0x01U, /*!<  HCI Command */
    kBLEC_HciDataPacket             = 0x02U, /*!<  L2CAP Data Packet */
    kBLEC_HciSynchronousDataPacket  = 0x03U, /*!<  Not used in BLE */
    kBLEC_HciEventPacket            = 0x04U, /*!<  HCI Event */
} blec_hciPacketType_t;

typedef blec_result_t (*blecHostHciRecvCallback_t)
(
    blec_hciPacketType_t packetType,
    void* pHciPacket,
    uint16_t hciPacketLength
);

typedef void (*blecIdleCallback_t)(void);

typedef struct
{
    int8_t min;
    int8_t max;
} power_range_dbm_t;

typedef enum
{
    kBLEC_CHANNEL_CW_0          = 0U,
    kBLEC_CHANNEL_CW_1          = 1U,
    kBLEC_CHANNEL_CW_2          = 2U,
    kBLEC_CHANNEL_CW_3          = 3U,
    kBLEC_CHANNEL_CW_4          = 4U,
    kBLEC_CHANNEL_CW_5          = 5U,
    kBLEC_CHANNEL_CW_6          = 6U,
    kBLEC_CHANNEL_CW_7          = 7U,
    kBLEC_CHANNEL_CW_8          = 8U,
    kBLEC_CHANNEL_CW_9          = 9U,
    kBLEC_CHANNEL_CW_10         = 10U,
    kBLEC_CHANNEL_CW_11         = 11U,
    kBLEC_CHANNEL_CW_12         = 12U,
    kBLEC_CHANNEL_CW_13         = 13U,
    kBLEC_CHANNEL_CW_14         = 14U,
    kBLEC_CHANNEL_CW_15         = 15U,
    kBLEC_CHANNEL_CW_16         = 16U,
    kBLEC_CHANNEL_CW_17         = 17U,
    kBLEC_CHANNEL_CW_18         = 18U,
    kBLEC_CHANNEL_CW_19         = 19U,
    kBLEC_CHANNEL_CW_20         = 20U,
    kBLEC_CHANNEL_CW_21         = 21U,
    kBLEC_CHANNEL_CW_22         = 22U,
    kBLEC_CHANNEL_CW_23         = 23U,
    kBLEC_CHANNEL_CW_24         = 24U,
    kBLEC_CHANNEL_CW_25         = 25U,
    kBLEC_CHANNEL_CW_26         = 26U,
    kBLEC_CHANNEL_CW_27         = 27U,
    kBLEC_CHANNEL_CW_28         = 28U,
    kBLEC_CHANNEL_CW_29         = 29U,
    kBLEC_CHANNEL_CW_30         = 30U,
    kBLEC_CHANNEL_CW_31         = 31U,
    kBLEC_CHANNEL_CW_32         = 32U,
    kBLEC_CHANNEL_CW_33         = 33U,
    kBLEC_CHANNEL_CW_34         = 34U,
    kBLEC_CHANNEL_CW_35         = 35U,
    kBLEC_CHANNEL_CW_36         = 36U,
    kBLEC_CHANNEL_CW_37         = 37U,
    kBLEC_CHANNEL_CW_38         = 38U,
    kBLEC_CHANNEL_CW_39         = 39U,
    kBLEC_CHANNEL_CW_MAX        = kBLEC_CHANNEL_CW_39,
} channel_selection_cw_t;

typedef enum
{
    kBLEC_PAYLOAD_TYPE_CW_PRBS9    = 0U,
    kBLEC_PAYLOAD_TYPE_CW_11110000 = 1U,
    kBLEC_PAYLOAD_TYPE_CW_10101010 = 2U,
	kBLEC_PAYLOAD_TYPE_CW_PRBS15   = 3U,
    kBLEC_PAYLOAD_TYPE_CW_11111111 = 4U,
    kBLEC_PAYLOAD_TYPE_CW_00000000 = 5U,
    kBLEC_PAYLOAD_TYPE_CW_00001111 = 6U,
    kBLEC_PAYLOAD_TYPE_CW_01010101 = 7U,
    kBLEC_PAYLOAD_TYPE_CW_MAX,
} payload_type_t;


typedef enum {
    kBLEC_PHY_1M                   = 0x01,
    kBLEC_PHY_2M                   = 0x02,
    kBLEC_PHY_CODED_S8             = 0x03,  /* S=8, where 8 symbols represent 1 bit */
    kBLEC_PHY_CODED                = 0x04,  /* S=2, where 2 symbols represent 1 bit */
} tx_rx_phy_t;

typedef void (*blec_printf_t)(const char * fmt, ...);

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/


/*! *********************************************************************************
 * \brief Set the transmit power level of the Controller for all BLE events including
 * continuous wave.
 * Exceptions are:
 *   - Extended advertising events: Set by the host as a parameter of
 *     HCI_LE_Set_Extended_Advertising_Param (OCF=0x0036)
 *
 * If the requested level_dbm value is not supported by the controller but is
 * between the supported range, the controller uses the nearest transmit power level
 * that is greater than the requested one.
 *
 * \param level_dbm : [in] Desired Tx Power Level in dbm
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_SetTxPowerDbm(int8_t level_dbm);

/*! *********************************************************************************
 * \brief Set the initial transmit power level of the Controller Connection
 * events.
 *
 * If the requested level_dbm value is not supported by the controller but is
 * between the supported range, the controller uses the nearest transmit power level
 * that is greater than the requested one.
 *
 * \param level_dbm : [in] Desired Tx Power Level in dbm
 *
 * \return blec_result_t
 ************************************************************************************/
blec_result_t BLEController_SetConnectionInitialTxPowerDbm(int8_t level_dbm);

/*! *********************************************************************************
 * \brief Initialize the Controller. 
 *        
 * \pre   This function assumes link layer interrupts (BLE_LL_IRQn and BLE_SLP_TMR_IRQn)
 *        have the highest priority in the system.
 * 
 * \param callback : [in]  callback HCI Host Receive Callback
 *
 * \param requested_max_power_dBm : [in] Maximum transmit power in dbm that the
 *            Controller needs to support. The Controller will choose the power table
 *            that both:
 *              - supports at least up to the given value
 *              - optimizes power use
 *
 *            If the requested value cannot be configured in the Controller then the
 *            Controller will choose the power table which maximum value is the
 *            nearest higher value, if it can.
 *
 *            If the requested value is higher than the maximum supported value then
 *            the Controller will select the power table which maximum value is the
 *            highest.
 *
 * \param selected_power_range : [out] min and max power values of the power table
 *            which was selected by the controller based on the input.
 *
 *
 * \return bleResult_t
 *********************************************************************************** */
blec_result_t BLEController_Init(blecHostHciRecvCallback_t callback,
        int8_t requested_max_power_dBm,
        power_range_dbm_t *selected_power_range);

/*! *********************************************************************************
 * \brief  Process Hci Packet
 * \param packetType : [in] HCI packet Type
 * \param pPacket    : [in] data buffer
 * \param packetSize : [in] data buffer length
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_ProcessHciPacket(blec_hciPacketType_t packetType,
        void* pPacket,
        uint16_t packetSize);

/*! *********************************************************************************
 * \brief  Set task stack size. Not used for bm applications
 *         BLEController_init creates the Controller tasks therefore
 *         this function needs to be called before BLEController_Init
 *
 * \param sizeNormalPrioTask      : [in] Stack size in bytes for normal tasks
 * \param sizeHighPrioTask        : [in] Stack size in bytes for high priority tasks
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_SetTaskStackSize(uint32_t sizeNormalPrioTask,
        uint32_t sizeHighPrioTask);

/*! *********************************************************************************
 * \brief  Get sleep timer value in us
 *
 * \return Sleep timer value in us
 ********************************************************************************** */
uint64_t BLEController_GetSleepTimerUs();

/*! *********************************************************************************
 * \brief Get the remaining timer for the next event. Safe access to internal timer structures.
 *        Potentially slower and less predictable call duration.
 * \param remainingTimeUs: [out] the value of remaining time  for the next event in us
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_GetRemainingTimeForNextEvent(uint32_t* remainingTimeUs);

/*! *********************************************************************************
 * \brief Get the remaining timer for the next event. Lock free but unsafe access to internal timer structures.
 *        Faster and more predictable call duration.
 * \param remainingTimeUs: [out] the value of remaining time  for the next event in us
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_GetRemainingTimeForNextEventUnsafe(uint32_t* remainingTimeUs);

/*! *********************************************************************************
 * \brief Read the Bluetooth Device Address of the LE controller.
 * \param bdAddr: [out] Public address of the LE controller in little-endian.
 *                              |LSB              MSB|
 *                      bdAddr: |[0][1][2]|[3]|[4][5]|
 *                              | LAP     |UAP| NAP  |
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_ReadBdAddr(uint8_t bdAddr[6]);

/*! *********************************************************************************
 * \brief Write the Bluetooth Device Address of the LE controller.
 * \param bdAddr: [in] Public address of the LE controller in little-endian.
 *                              |LSB              MSB|
 *                      bdAddr: |[0][1][2]|[3]|[4][5]|
 *                              | LAP     |UAP| NAP  |
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_WriteBdAddr(uint8_t bdAddr[6]);

/*! *********************************************************************************
 * \brief  Start continuous wave transmission
 *
 * \param channel        : [in] Channel where the wave will be transmitted
 *
 ********************************************************************************** */
blec_result_t BLEController_ContinuousWave_StartTx(channel_selection_cw_t channel);

/*! *********************************************************************************
 * \brief  Start modulated continuous wave transmission
 *
 * \param channel        : [in] Channel where the wave will be transmitted
 * \param payload_type   : [in] Payload type
 * \param phy            : [in] Modulation/Phy to use
 *
 ********************************************************************************** */
blec_result_t BLEController_ContinuousWave_StartTxModulated(channel_selection_cw_t channel,
        payload_type_t payload_type, tx_rx_phy_t phy);

/*! *********************************************************************************
 * \brief  Start continuous wave reception
 ********************************************************************************** */
blec_result_t BLEController_ContinuousWave_StartRx(channel_selection_cw_t channel);

/*! *********************************************************************************
 * \brief  Stop Continuous Wave operation
 ********************************************************************************** */
blec_result_t BLEController_ContinuousWave_Stop(void);

/*! *********************************************************************************
 * \brief  Used to return the RSSI measured during a continuous wave reception
 *
 * \return rssi as signed 16-bit value in 0.25 dBm unity steps.
 *
 ********************************************************************************** */
int16_t BLEController_ContinuousWave_ReadRSSI(void);

/*! *********************************************************************************
 * \brief  Used to return the RSSI measured during a connection
 *
 * \param conn_handle_id : [in]  connection handle of connection to read RSSI from
 * \param rssi           : [out] signed 8-bit value in 1 dBm unity steps
 *
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_Connection_ReadRSSI(uint16_t conn_handle_id, int8_t *rssi);

/*! *********************************************************************************
 * \brief  Check whether there are pending software tasks, i.e. pending events that require processing
 *
 * \return 0: Not idle, 1: idle.
 *
 ********************************************************************************** */
int BLEController_EmngrIsIdle(void);

/*! *********************************************************************************
 * \brief  Used to loop through all the registered handles in the event manager and process their events, if any exists.
 ********************************************************************************** */
void BLEController_EmngrHandleAllEvents(void);

/*! *********************************************************************************
 * \brief  Used to return the number of events in the event manager
 *
 * \return Events Number.
 *
 ********************************************************************************** */
int BLEController_EmngrGetTotalEvents(void);

/**
 * \brief Register function to be called when there are no more events to process
 *
 * \param callback : [in]  callback to execute when the Controller is Idle
 */
void BLEController_RegisterIdleCallback(blecIdleCallback_t callback);

/**
 * \brief Instruct the link layer controller to enter low power mode
* \return blec_result_t
 */
blec_result_t BLEController_EnterLowPower(void);

/**
 * \brief Instruct the link layer controller to exit low power mode
  * \return blec_result_t
 */
blec_result_t BLEController_ExitLowPower(void);

/**
 * \brief Enable LL internal debugging via GPIO
 *        The pins used are defined in BLECONTROLLER_GPIO_MAP and GPIO_FOR_RADIO_ACTIVITY
 *        This function also takes care of the pin mux settings
 *
 * \return blec_result_t
 */
blec_result_t BLEController_EnableGPIODebugging(void);

/**
 * \brief Disable LL internal debugging via GPIO
  * \return blec_result_t
 */
blec_result_t BLEController_DisableGPIODebugging(void);

/**
 * \brief Print the profile report and reset profiling
 * \param printf : [in]  print function used for printing the report
 * \return blec_result_t
 */
blec_result_t BLEController_PrintProfileReport(blec_printf_t printf);

#endif /* _BLE_CONTROLLER_H_ */
