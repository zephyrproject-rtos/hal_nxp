/*! *********************************************************************************
 * \addtogroup BLE
 * @{
 ********************************************************************************** */
/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2020 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef BLE_CONTROLLER_TASK_CONFIG_H
#define BLE_CONTROLLER_TASK_CONFIG_H

#include "fsl_os_abstraction.h"

/************************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
************************************************************************************/

/*
 * These values should be modified by the application as necessary.
 * They are used by the task initialization code from ble_controller_task.c.
 */

#ifndef gControllerTaskStackSize_c
#define gControllerTaskStackSize_c 1200
#endif

#ifndef gControllerTaskPriority_c
#define gControllerTaskPriority_c 1
#endif

/* Controller configuration specifics, change at your own risk.*/

/* Time between the beginning of two consecutive advertising PDU's
 * Time = ADVERTISING_PACKET_INTERVAL * 0.625msec
 * Time range <= 10msec
 * This interval should include the advertising PDU, SCAN request and SCAN response
 * if applicable and the interframe spacing.
 */
#ifndef mcAdvertisingPacketInterval_c
#define mcAdvertisingPacketInterval_c      0x03    /* 1.875 msec */
#endif

/* Advertising channels that are enabled for scanning operation.
 * Range 0x01 - 0x07
 * 0x01 - Enables channel 37 for use.
 * 0x02 - Enables channel 38 for use.
 * 0x04 - Enables channel 39 for use.
 */
#ifndef mcScanChannelMap_c
#define mcScanChannelMap_c        0x07
#endif

/* Advertising channels that are enabled for initiator scanning operation.
 * Range 0x01 - 0x07
 * 0x01 - Enables channel 37 for use.
 * 0x02 - Enables channel 38 for use.
 * 0x04 - Enables channel 39 for use.
 */
#ifndef mcInitiatorChannelMap_c
#define mcInitiatorChannelMap_c        0x07
#endif

/* Offset to the first instant register. Units in 625uS time slots.
 *
 * Ex. If current clock value is 0x0004 and offset is 0x0008, then
 *     the first event will begin when clock value becomes 0x000C.
 *
 * If mcOffsetToFirstInstant_c is 0xFFFF the value will be ignored
 * and default value (0x0006) will be set.
 */
#ifndef mcOffsetToFirstInstant_c
#define mcOffsetToFirstInstant_c        0xFFFF
#endif

/* use this to enable PA bump to reach + 5 dBm TX power
 */
#ifndef mDefaultTxPowerUsePaBump_c
#define mDefaultTxPowerUsePaBump_c    0
#endif
   
/* Default Tx Power on the advertising channel.
 * Power level as defined in the table for Controller_SetTxPowerLevel
*/
#ifndef mAdvertisingDefaultTxPower_c
#define mAdvertisingDefaultTxPower_c    20
#endif

/* Default Tx Power on the connection channel.
 * Power level as defined in the table for Controller_SetTxPowerLevel
*/
#ifndef mConnectionDefaultTxPower_c
#define mConnectionDefaultTxPower_c     20
#endif

/* Scan FIFO lockup detection interval in milliseconds. If no advertising frame
   is reported over this period of time, then the scan FIFO is flushed and the scan
   is restarted. This value needs to be increased if:
   - few advertisers or
   - few frames reported after frame filtering using the white list or
   - scan window is much smaller than the scan interval
*/
#ifndef mScanFifoLockupCheckIntervalMilliSeconds_c
#define mScanFifoLockupCheckIntervalMilliSeconds_c     2500
#endif

/* Organizationally Unique Identifier used in BD_ADDR.
 * The 24 most significant bits in BD_ADDR
*/
#ifndef BD_ADDR_OUI
#define BD_ADDR_OUI     0x37,0x60,0x00
#endif

/************************************************************************************
*************************************************************************************
* Public memory declarations
*************************************************************************************
************************************************************************************/
/* Radio system clock selection. */
extern const uint8_t gRfSysClk26MHz_c;
/* Organizationally Unique Identifier used in BD_ADDR. */
extern const uint8_t gBD_ADDR_OUI_c[];
#ifndef CPU_QN908X
    /* BD_ADDR referenced in the controller */
    extern uint8_t gBD_ADDR[];
#endif
/* Time between the beginning of two consecutive advertising PDU's */
extern uint8_t gAdvertisingPacketInterval;
/* Advertising channels that are enabled for scanning operation. */
extern const uint8_t gScanChannelMap_c;
/* Advertising channels that are enabled for initiator scanning operation. */
extern const uint8_t gInitiatorChannelMap_c;
/* Offset to the first instant register */
extern const uint16_t gOffsetToFirstInstant_c;
/* Scan FIFO lockup detection interval in milliseconds. */
extern uint32_t gScanFifoLockupCheckIntervalMilliSeconds;
/* Place holder for storing allocated memory address in the link layer */
extern const uint16_t gLeMemBufListSize;
extern void *gLeMemBufList[];

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*! *********************************************************************************
* \brief  Initializes the two tasks of the BLE Host Stack.
*
* \return  osaStatus_t.
*
********************************************************************************** */
osaStatus_t Controller_TaskInit(void);

#ifdef __cplusplus
}
#endif

#endif /* BLE_CONTROLLER_TASK_CONFIG_H */

/*! *********************************************************************************
* @}
********************************************************************************** */
