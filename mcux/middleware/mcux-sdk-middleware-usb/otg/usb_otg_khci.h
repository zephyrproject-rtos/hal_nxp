/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __USB_OTG_KHCI_H__
#define __USB_OTG_KHCI_H__

#include "usb_otg_config.h"

#if ((defined USB_OTG_CONFIG_KHCI) && (USB_OTG_CONFIG_KHCI))

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief restart to check the SRP when time exceeds the value */
#define USB_OTG_TIME_SRP_TIME_OUT (2000U)
/*! @brief check BHNP flag for the max3353 periodically */
#define USB_OTG_TIME_CHECK_BHNP_PERIODIC (20U)
/*! @brief check detach time */
#define USB_OTG_TIME_CHECK_DETACH (300U)

/*! @brief KHCI check types */
typedef enum _usb_otg_check_type
{
    kOtg_CheckNone = 0x00U, /*!< default value */
    kOtg_CheckNonConn,      /*!< check disconnection */
    kOtg_CheckConn,         /*!< check connection */
    kOtg_CheckSrp,          /*!< check SRP */
    kOtg_CheckSsendSe0Srp,  /*!< check b_se0_srp and b_ssend_srp */
    kOtg_CheckIdleTimeOut,  /*!< check idle time out */
    kOtg_CheckBHNP,         /*!< check HNP */
    kOtg_CheckSuspend,      /*!< check suspend */
} usb_otg_check_type_t;

/*! @brief check the status on peripheral */
typedef enum _usb_otg_peripheral_status_type
{
    kPeripheral_StatusId          = 0x01U, /*! id */
    kPeripheral_StatusSessVld     = 0x02U, /*! b_sess_vld */
    kPeripheral_StatusVbusVld     = 0x04U, /*! b_vbus_vld */
    kPeripheral_StatusHNPdetected = 0x08U, /*! detect HNP */
    kPeripheral_StatusAll         = 0x10U, /*! all above status bits value */
} usb_otg_peripheral_status_type_t;

/*! @brief The control types */
typedef enum _usb_otg_peripheral_control
{
    kPeripheral_ControlVbus,           /*! control vbus */
    kPeripheral_ControlHNPCheckEnable, /*! start to check HNP */
    kPeripheral_ControlUpdateStatus,   /*! notify the controller to update the newest status */
} usb_otg_peripheral_control_t;

/*! @brief KHCI driver instance structure */
typedef struct _usb_otg_khci
{
    usb_otg_handle otgHandle;
    USB_Type *usbRegBase;                 /*!< EHCI IP base address */
    volatile uint32_t lastState;          /*!< The last state value, please referenct to #usb_otg_device_state_t */
    volatile uint32_t peripheralStatus;   /*!< The peripheral status */
    volatile uint16_t lineStableTime;     /*!< the duration for stable line */
    volatile uint16_t internalTimerValue; /*!< internal timer value */
    volatile uint16_t externalTimerValue; /*!< external timer value */

    /* b_ssend_srp Check */
    volatile uint16_t bssendsrpCheck; /*!< use to check b_ssend_srp */

    volatile uint16_t checkTime; /*!< use to check the status, please referenct to #usb_otg_check_type_t */
    volatile uint8_t checkType;  /*!< use to check the status, please referenct to #usb_otg_check_type_t */

    volatile uint8_t
        externalTimerEnable; /*!< 1 - the externalTimerValue is valid; 0 - the externalTimerValue is invalid */

    /* srp detect */
    volatile uint8_t checkSrpState; /*!< check SRP steps */

    volatile uint8_t se0State; /*!< line state se0 */
    volatile uint8_t jState;   /*!< line state J */
} usb_otg_khci_instance_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Initialize the USB OTG KHCI instance.
 *
 * This function initializes the USB OTG KHCI controller driver.
 *
 * @param controllerId      The controller ID of the USB IP. See the enumeration #usb_controller_index_t.
 * @param otgHandle         the OTG level handle.
 * @param controllerHandle  Return the controller instance handle.
 *
 * @retval kStatus_USB_Success              The host is initialized successfully.
 * @retval kStatus_USB_AllocFail            Allocate memory failed.
 * @retval kStatus_USB_Error                Initialize fail
 */
usb_status_t USB_OtgKhciInit(uint8_t controllerId,
                             usb_otg_handle otgHandle,
                             usb_otg_controller_handle *controllerHandle);

/*!
 * @brief de-initialize the USB OTG KHCI instance.
 *
 * This function de-initializes the USB OTG KHCI controller driver.
 *
 * @param controllerHandle  Controller instance handle.
 *
 * @retval kStatus_USB_Success              success.
 * @retval other values                     Fail.
 */
usb_status_t USB_OtgKhciDeinit(usb_otg_controller_handle controllerHandle);

/*!
 * @brief Control the USB OTG KHCI.
 *
 * This function controls the USB OTG KHCI controller to implement different functions.
 *
 * @param controllerHandle  The controller instance handle.
 * @param controlType       The control type, please referenct to #usb_otg_control_t.
 * @param controlValue1     The control value, it is 0 or 1 usually.
 * @param controlValue2     It only be used in the kOtg_ControlRequestStatus control now.
 *
 * @retval kStatus_USB_Success              success.
 * @retval other values                     Fail.
 */
usb_status_t USB_OtgKhciControl(usb_otg_controller_handle controllerHandle,
                                uint32_t controlType,
                                uint32_t controlValue1,
                                uint32_t controlValue2);

#endif

#endif /* __USB_OTG_KHCI_H__ */
