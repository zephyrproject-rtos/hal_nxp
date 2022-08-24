/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017,2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_otg_config.h"
#include "usb_otg.h"
#include "usb_otg_oci.h"
#include "fsl_device_registers.h"
#include "usb_otg_khci.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "middleware.usb.otg_stack"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void _USB_OtgGetControllerInterface(uint8_t controllerId,
                                           const usb_otg_controller_interface_t **controllerTable);
static void _USB_OtgStartTimer(usb_otg_instance_t *otgInstance, uint32_t timeValue);
static void _USB_OtgCancelTimer(usb_otg_instance_t *otgInstance);
static void _USB_OtgEnterStateStart(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateStart(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateAIdle(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAIdle(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateAWaitVrise(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAWaitVrise(usb_otg_instance_t *otgInstance,
                                           uint32_t otgChangeType,
                                           uint32_t changeValue);
static void _USB_OtgEnterStateAWaitVfall(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAWaitVfall(usb_otg_instance_t *otgInstance,
                                           uint32_t otgChangeType,
                                           uint32_t changeValue);
static void _USB_OtgEnterStateAWaitBcon(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAWaitBcon(usb_otg_instance_t *otgInstance,
                                          uint32_t otgChangeType,
                                          uint32_t changeValue);
static void _USB_OtgEnterStateAHost(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAHost(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateASuspend(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateASuspend(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateAPeripheral(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAPeripheral(usb_otg_instance_t *otgInstance,
                                            uint32_t otgChangeType,
                                            uint32_t changeValue);
static void _USB_OtgEnterStateAVbusErr(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateAVbusErr(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateBIdle(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateBIdle(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateBSrpInit(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateBSrpInit(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);
static void _USB_OtgEnterStateBPeripheral(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateBPeripheral(usb_otg_instance_t *otgInstance,
                                            uint32_t otgChangeType,
                                            uint32_t changeValue);
static void _USB_OtgEnterStateBWaitAcon(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateBWaitAcon(usb_otg_instance_t *otgInstance,
                                          uint32_t otgChangeType,
                                          uint32_t changeValue);
static void _USB_OtgEnterStateBHost(usb_otg_instance_t *otgInstance);
static void _USB_OtgProcessStateBHost(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if (USB_OTG_CONFIG_KHCI)
static const usb_otg_controller_interface_t s_KhciInterface = {USB_OtgKhciInit, USB_OtgKhciDeinit, USB_OtgKhciControl};
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

static void _USB_OtgGetControllerInterface(uint8_t controllerId, const usb_otg_controller_interface_t **controllerTable)
{
#if (USB_OTG_CONFIG_KHCI)
    if (controllerId == (uint8_t)kUSB_ControllerKhci0)
    {
        *controllerTable = &s_KhciInterface;
    }
#endif
}

static void _USB_OtgStartTimer(usb_otg_instance_t *otgInstance, uint32_t timeValue)
{
#if (USB_OTG_CONFIG_KHCI)
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlSetTimer,
                                                              timeValue, 0);
#endif
}

/* todo: cancel timer in the otg stack level, the timer cannot be canceled timely */
static void _USB_OtgCancelTimer(usb_otg_instance_t *otgInstance)
{
#if (USB_OTG_CONFIG_KHCI)
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlCancelTimer, 0,
                                                              0);
#endif
    if (otgInstance->hasTimeOutMsg > 0U)
    {
        otgInstance->cancelTime = 1U;
    }
}

static void _USB_OtgEnterStateStart(usb_otg_instance_t *otgInstance)
{
    otgInstance->otgDeviceState = (uint8_t)kOtg_State_Start;
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlRequestStatus,
                                                              kOtg_StatusId, kOtg_State_Start);

    (void)USB_OtgNotifyChange(otgInstance, (uint32_t)kOtg_StatusPowerUp, 1);
}

static void _USB_OtgProcessStateStart(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))) /* a_bus_drop/ */
    {
        return;
    }

    switch (statusType)
    {
        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            else
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusId);

                _USB_OtgEnterStateAIdle(otgInstance); /* go to a_idle */
            }
            break;

        case kOtg_StatusPowerUp:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusPowerUp;
            }
            break;

        default:
            /*no action*/
            break;
    }
}

static void _USB_OtgEnterStateAIdle(usb_otg_instance_t *otgInstance)
{
    if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId)))
    {
        _USB_OtgEnterStateBIdle(otgInstance);
    }
    else if ((0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))) &&
             (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusPowerUp))))
    {
        _USB_OtgEnterStateAWaitVrise(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_AIdle;
        otgInstance->otgControllerStatus &= (~((uint32_t)kOtg_StatusBConn)); /* clear b_conn */

#if ((defined USB_OTG_ADP_ENABLE) && (USB_OTG_ADP_ENABLE))
/* todo: adp */
#endif

        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusSrpDet) | ((uint32_t)kOtg_StatusAdpChange),
            (uint32_t)kOtg_State_AIdle);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, (uint8_t)kOtg_EventStateChange,
                                 (uint32_t)kOtg_State_AIdle);

        if (0U != otgInstance->idChangeAsFalse)
        {
            otgInstance->idChangeAsFalse = 0U;
            /* a change in id from TRUE to FALSE causes a_bus_req to be asserted unless the device is ADP capable. */
            (void)USB_OtgNotifyChange(otgInstance, (uint32_t)kOtg_StatusBusReq, 1);
        }
    }
}

static void _USB_OtgProcessStateAIdle(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusBusReq:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusReq;

                if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop)))
                {
                    _USB_OtgEnterStateAWaitVrise(otgInstance); /* go to a_wait_vrise */
                }
            }
            else
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusReq);
            }
            break;

#if (USB_OTG_SRP_ENABLE)
        case kOtg_StatusSrpDet:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop)))
                {
                    _USB_OtgEnterStateAWaitVrise(otgInstance); /* go to a_wait_vrise */
                }
            }
            break;
#endif

#if ((defined USB_OTG_ADP_ENABLE) && (USB_OTG_ADP_ENABLE))
        case kOtg_StatusAdpChange:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop)))
                {
                    _USB_OtgEnterStateAWaitVrise(otgInstance); /* go to a_wait_vrise */
                }
            }
            break;
#endif

        case kOtg_StatusPowerUp:
            /* when power up, the kOtg_StatusBusDrop must be false */
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusPowerUp);

                if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop)))
                {
                    _USB_OtgEnterStateAWaitVrise(otgInstance); /* go to a_wait_vrise */
                }
            }
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgEnterStateBHost(otgInstance); /* go to b_host */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;
            }
            else
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusDrop);

                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusReq))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSrpDet))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusAdpChange))))
                {
                    _USB_OtgEnterStateAWaitVrise(otgInstance); /* go to a_wait_vrise */
                }
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAWaitVrise(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateAWaitBcon(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_AWaitVrise;

        /* driver vbus */
        if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusVbusVld;
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 1, 0);
        }
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusVbusVld), kOtg_State_AWaitVrise);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, (uint32_t)kOtg_EventStateChange,
                                 (uint8_t)kOtg_State_AWaitVrise);

        /* set timer */
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIMER_A_WAIT_VRISE_TMR);
    }
}

static void _USB_OtgProcessStateAWaitVrise(usb_otg_instance_t *otgInstance,
                                           uint32_t otgChangeType,
                                           uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusTimeOut:
            /* todo: update controller state */

            if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
            {
                _USB_OtgEnterStateAWaitBcon(otgInstance); /* go to a_wait_bcon */
            }
            else
            {
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusVbusVld;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAWaitBcon(otgInstance); /* go to a_wait_bcon */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAWaitVfall(usb_otg_instance_t *otgInstance)
{
    otgInstance->otgDeviceState = (uint8_t)kOtg_State_AWaitVfall;

    (void)USB_OtgKhciControl(otgInstance->controllerHandle, (uint32_t)kOtg_ControlPullUp, 0, 0);

    /* if there is bus req, the bus req fail. Or there is bus drop. */
    otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusReq);

    /* close vbus */
    if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);
        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlVbus, 0, 0);
    }
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlRequestStatus,
                                                              0, kOtg_State_AWaitVfall);

    otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_AWaitVfall);

    /* set timer */
    _USB_OtgStartTimer(otgInstance, USB_OTG_TIMER_A_WAIT_VFALL_TMR);
}

static void _USB_OtgProcessStateAWaitVfall(usb_otg_instance_t *otgInstance,
                                           uint32_t otgChangeType,
                                           uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusTimeOut:
            /* todo: update controller state */

            _USB_OtgEnterStateAIdle(otgInstance); /* go to a_idle */
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAWaitBcon(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBConn)))
    {
        _USB_OtgEnterStateAHost(otgInstance);
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateAVbusErr(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_AWaitBcon;

        /* driver vbus */
        if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusVbusVld;
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 1, 0);
        }
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusVbusInvld) | ((uint32_t)kOtg_StatusBConn),
            kOtg_State_AWaitBcon);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_AWaitBcon);

/* set timer */
#if (USB_OTG_TIMER_A_WAIT_BCON_TMR != 0xFFFFFFFFU)
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIMER_A_WAIT_BCON_TMR);
#endif
    }
}

static void _USB_OtgProcessStateAWaitBcon(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusTimeOut:
            /* todo: update controller state */

            _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= ((uint32_t)kOtg_StatusId);

                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= ((uint32_t)kOtg_StatusBusDrop);

                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBConn:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= ((uint32_t)kOtg_StatusBConn);

                _USB_OtgEnterStateAHost(otgInstance); /* go to a_host */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);

                _USB_OtgEnterStateAVbusErr(otgInstance); /* go to a_vbus_err */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= ((uint32_t)otgChangeType);
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAHost(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBConn)))
    {
        _USB_OtgEnterStateAWaitBcon(otgInstance);
    }
    /*
    else if (!(otgInstance->otgControllerStatus & kOtg_StatusBusReq))
    {
        _USB_OtgEnterStateASuspend(otgInstance);
    }
    */
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateAVbusErr(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = ((uint8_t)kOtg_State_AHost);
        otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBHNPFeature);

        /* driver vbus */
        if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus |= ((uint32_t)kOtg_StatusVbusVld);
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 1, 0);
        }
        /* pull down dp and dm */
        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlPullDown,
                                                                  ((uint32_t)kOtg_PullDp) | ((uint32_t)kOtg_PullDm), 0);
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusBDisconn) | ((uint32_t)kOtg_StatusVbusInvld),
            kOtg_State_AHost);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_AHost);

#if (USB_OTG_TIME_WAIT_DEVICE_INIT != 0U)
        otgInstance->waitInit = 1U;
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIME_WAIT_DEVICE_INIT); /* wait the B-Device init the device stack */
#else
        /* start work as host */
        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit, kOtg_StackHostInit);
#endif
    }
}

static void _USB_OtgExitHost(usb_otg_instance_t *otgInstance)
{
    otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit,
                             kOtg_StackHostDeinit); /* host stack de-init */
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                              (uint32_t)kOtg_ControlPullDown, 0, 0);
}

static void _USB_OtgProcessStateAHost(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
#if (USB_OTG_TIME_WAIT_DEVICE_INIT != 0U)
        case kOtg_StatusTimeOut:
            if (0U != otgInstance->waitInit) /* init host */
            {
                /* start work as host */
                otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit,
                                         kOtg_StackHostInit); /* host stack init */
                otgInstance->waitInit = 0U;
            }
            break;
#endif

        case kOtg_StatusBConn:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBConn);

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateAWaitBcon(otgInstance); /* go to a_wait_bcon */
            }
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusReq:    /* hnp or host release bus */
            if (0U == changeValue) /* bus release */
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusReq);

                _USB_OtgExitHost(otgInstance);
                /* USB_HostSuspend(otgInstance->hostHandle); */
                _USB_OtgEnterStateASuspend(otgInstance); /* go to a_suspend */
            }
            else /* HNP bus request */
            {
                /* todo: update controller state */
                /* otgInstance->otgControllerStatus &= (~kOtg_StatusBusReq); */

                _USB_OtgExitHost(otgInstance);
                /* USB_HostSuspend(otgInstance->hostHandle); */
                _USB_OtgEnterStateASuspend(otgInstance); /* go to a_suspend */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateAVbusErr(otgInstance); /* go to a_vbus_err */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateASuspend(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBConn)))
    {
        if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBHNPFeature)))
        {
            _USB_OtgEnterStateAPeripheral(otgInstance);
        }
        else
        {
            _USB_OtgEnterStateAWaitBcon(otgInstance);
        }
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateAVbusErr(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_ASuspend;

        /* driver vbus */
        if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusVbusVld;
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 1, 0);
        }
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusBDisconn) | ((uint32_t)kOtg_StatusVbusInvld),
            (uint32_t)kOtg_State_ASuspend);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, (uint32_t)kOtg_EventStateChange,
                                 kOtg_State_ASuspend);

        if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBHNPFeature)))
        {
            /* set timer */
            _USB_OtgStartTimer(otgInstance, USB_OTG_TIMER_A_AIDL_BDIS_TMR);
        }
    }
}

static void _USB_OtgProcessStateASuspend(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusBConn:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBConn);
                _USB_OtgCancelTimer(otgInstance);
                if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBHNPFeature)))
                {
                    _USB_OtgEnterStateAWaitBcon(otgInstance); /* go to a_wait_bcon */
                }
                else
                {
                    _USB_OtgEnterStateAPeripheral(otgInstance); /* go to a_peripheral */
                }
            }
            break;

        case kOtg_StatusTimeOut:
            if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBHNPFeature)))
            {
                if (0U != changeValue)
                {
                    /* todo: update controller state */

                    _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
                }
            }
            break;

        case kOtg_StatusBusReq: /* resume */
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusReq;

                _USB_OtgCancelTimer(otgInstance);
                (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                          kOtg_ControlResume, 20, 0);

                _USB_OtgEnterStateAHost(otgInstance); /* go to a_host */
            }
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateAVbusErr(otgInstance); /* go to a_vbus_err */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAPeripheral(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateAVbusErr(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_APeripheral;
        otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBConn);

        /* start work as device */
        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlPullUp, kOtg_PullDp, 0);
        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlPullDown, kOtg_PullDm, 0);
        /* driver vbus */
        if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusVbusVld;
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 1, 0);
        }
        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit,
                                 kOtg_StackDeviceInit); /* device stack init */
#if (USB_OTG_TIME_WAIT_BHOST != 0U)
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusVbusInvld), kOtg_State_APeripheral);
#else
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusVbusInvld) |
                ((uint32_t)kOtg_StatusCheckIdleInAPeripheral),
            kOtg_State_APeripheral);
#endif

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_APeripheral);

#if (USB_OTG_TIME_WAIT_BHOST != 0U)
        /* wait the B-Device init the host stack */
        otgInstance->waitInit = 1;
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIME_WAIT_BHOST);
#endif
    }
}

static void _USB_OtgExitDevice(usb_otg_instance_t *otgInstance)
{
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                              (uint32_t)kOtg_ControlPullUp, 0, 0);
    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                              (uint32_t)kOtg_ControlPullDown, 0, 0);
    /* otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlPullUp, 0); */
    otgInstance->otgCallback(otgInstance->otgCallbackParameter, (uint32_t)kOtg_EventStackInit,
                             kOtg_StackDeviceDeinit); /* device stack de-init */
}

static void _USB_OtgProcessStateAPeripheral(usb_otg_instance_t *otgInstance,
                                            uint32_t otgChangeType,
                                            uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusBusReq:
            if (0U != changeValue)
            {
                /* todo: set hnp flag for polling */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusReq;
            }
            break;

        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusTimeOut:
#if (USB_OTG_TIME_WAIT_BHOST != 0U)
            if (0U != otgInstance->waitInit) /* wait init host */
            {
                (void)otgInstance->controllerInterface->controllerControl(
                    otgInstance->controllerHandle, kOtg_ControlRequestStatus, kOtg_StatusCheckIdleInAPeripheral,
                    kOtg_State_APeripheral);
                otgInstance->waitInit = 0;
            }
            else
            {
#endif
                if (0U != changeValue)
                {
                    /* todo: update controller state */

                    _USB_OtgExitDevice(otgInstance);
                    _USB_OtgEnterStateAWaitBcon(otgInstance); /* go to a_wait_bcon */
                }
#if (USB_OTG_TIME_WAIT_BHOST != 0U)
            }
#endif
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateAVbusErr(otgInstance); /* go to a_vbus_err */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= (~otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateAVbusErr(usb_otg_instance_t *otgInstance)
{
    if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusDrop))))
    {
        _USB_OtgEnterStateAWaitVfall(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_AVbusErr;

        /* don't driver vbus */
        if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
        {
            otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      (uint32_t)kOtg_ControlVbus, 0, 0);
        }
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus, kOtg_StatusId, kOtg_State_AVbusErr);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_AVbusErr);
    }
}

static void _USB_OtgProcessStateAVbusErr(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusId:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusId;

                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusBusDrop:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusDrop;

                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        case kOtg_StatusClrErr:
            if (0U == changeValue)
            {
                /* todo: update controller state */

                _USB_OtgEnterStateAWaitVfall(otgInstance); /* go to a_wait_vfall */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateBIdle(usb_otg_instance_t *otgInstance)
{
    if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId)))
    {
        otgInstance->otgControllerStatus = 0U; /* default controller status */
        _USB_OtgEnterStateAIdle(otgInstance);
    }
    else if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSessVld)))
    {
        otgInstance->otgControllerStatus = (uint32_t)kOtg_StatusId;
        _USB_OtgEnterStateBPeripheral(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState      = (uint8_t)kOtg_State_BIdle;
        otgInstance->otgControllerStatus = (uint32_t)kOtg_StatusId;

#if ((defined USB_OTG_ADP_ENABLE) && (USB_OTG_ADP_ENABLE))
/* todo: adp */
#endif

        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlPullUp, 0,
                                                                  0); /* disable pull-up */
        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle, kOtg_ControlPullDown,
                                                                  0, 0); /* disable DP&DM pulldown */
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusAdpChange) | ((uint32_t)kOtg_StatusSessVld) |
                ((uint32_t)kOtg_StatusSe0Srp) | ((uint32_t)kOtg_StatusSsendSrp),
            kOtg_State_BIdle);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_BIdle);
    }
}

static void _USB_OtgProcessStateBIdle(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusId:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus = 0U; /* default controller status */

                _USB_OtgEnterStateAIdle(otgInstance); /* go to a_idle */
            }
            break;

        case kOtg_StatusSsendSrp:
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusSsendSrp;
            if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSe0Srp)))
            {
                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusPowerUp))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusReq))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusAdpChange))))
                {
                    otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusPowerUp);
                    _USB_OtgEnterStateBSrpInit(otgInstance); /* go to b_srp_init */
                }
            }
            break;

        case kOtg_StatusSe0Srp:
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusSe0Srp;
            if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSsendSrp)))
            {
                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusPowerUp))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusReq))) ||
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusAdpChange))))
                {
                    otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusPowerUp);
                    _USB_OtgEnterStateBSrpInit(otgInstance); /* go to b_srp_init */
                }
            }
            break;

        case kOtg_StatusPowerUp:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusPowerUp;

                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSsendSrp))) &&
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSe0Srp))))
                {
                    otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusPowerUp);
                    _USB_OtgEnterStateBSrpInit(otgInstance); /* go to b_srp_init */
                }
            }
            break;

        case kOtg_StatusBusReq:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusReq;

                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSsendSrp))) &&
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSe0Srp))))
                {
                    _USB_OtgEnterStateBSrpInit(otgInstance); /* go to b_srp_init */
                }
            }
            break;

        case kOtg_StatusAdpChange:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSsendSrp))) &&
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSe0Srp))))
                {
                    _USB_OtgEnterStateBSrpInit(otgInstance); /* go to b_srp_init */
                }
            }
            break;

        case kOtg_StatusSessVld:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusSessVld;

                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateBSrpInit(usb_otg_instance_t *otgInstance)
{
    otgInstance->otgControllerStatus = ~((uint32_t)kOtg_StatusBusReq); /* clear b_bus_req */

    if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId)))
    {
        _USB_OtgEnterStateBIdle(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_BSrpInit;

        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlDataPulse, 1, 0);

        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusBSrpDone), (uint32_t)kOtg_State_BSrpInit);
        /* todo: check SRP fail */
        /* _USB_OtgStartTimer(otgInstance, USB_OTG_TIME_B_SRP_FAIL); */

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_BSrpInit);
    }
}

static void _USB_OtgProcessStateBSrpInit(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusId:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusId);

                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusBSrpDone:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

#if 0
        case kOtg_StatusTimeOut: /* b_srp_done and srp fail */
            if (0U != changeValue)
            {
                /* todo: update controller state */

                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusSessVld: /* this change is not align with spec state machine */
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= kOtg_StatusSessVld;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;
#endif

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateBPeripheral(usb_otg_instance_t *otgInstance)
{
    otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusAConn);

    if ((0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSessVld))))
    {
        _USB_OtgEnterStateBIdle(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_BPeripheral;
        otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBHNPFeature);

        /* start work as device */
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlPullUp, (uint32_t)kOtg_PullDp, 0);
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlPullDown, (uint32_t)kOtg_PullDm, 0);
        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit,
                                 kOtg_StackDeviceInit); /* device stack init */

        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusId) | ((uint32_t)kOtg_StatusSessInvld) | ((uint32_t)kOtg_StatusBusSuspend),
            ((uint32_t)kOtg_State_BPeripheral));

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_BPeripheral);
    }
}

static void _USB_OtgProcessStateBPeripheral(usb_otg_instance_t *otgInstance,
                                            uint32_t otgChangeType,
                                            uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusId:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusId);

                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusSessVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusSessVld);

                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);
                _USB_OtgExitDevice(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            else
            {
                otgInstance->otgControllerStatus |= (uint32_t)(kOtg_StatusVbusVld);
            }
            break;

        case kOtg_StatusBusReq:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBusReq;
            }
            break;

        case kOtg_StatusBusSuspend:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                if ((0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBHNPFeature))) &&
                    (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusReq))))
                {
                    (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                              (uint32_t)kOtg_ControlPullUp, 0, 0);
                    _USB_OtgExitDevice(otgInstance);
                    _USB_OtgEnterStateBWaitAcon(otgInstance); /* go to b_wait_acon */
                }
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateBWaitAcon(usb_otg_instance_t *otgInstance)
{
    if ((0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusId))) ||
        (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusSessVld))))
    {
        _USB_OtgEnterStateBIdle(otgInstance);
    }
    else if (0U != (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusAConn)))
    {
        _USB_OtgEnterStateBHost(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_BWaitAcon;

        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlPullUp, 0, 0);
        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlRequestStatus,
            ((uint32_t)kOtg_StatusBusResume) | ((uint32_t)kOtg_StatusAConn), (uint32_t)kOtg_State_BWaitAcon);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_BWaitAcon);

        /* set timer */
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIMER_B_ASE0_BRST_TMR);
    }
}

static void _USB_OtgProcessStateBWaitAcon(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
        case kOtg_StatusAConn:
            if (0U != changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusAConn;

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateBHost(otgInstance); /* go to b_host */
            }
            break;

        case kOtg_StatusId:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusId);

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusSessVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusSessVld);

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateBIdle(otgInstance); /* go to b_idle */
            }
            break;

        case kOtg_StatusBusResume:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                _USB_OtgCancelTimer(otgInstance);
                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        case kOtg_StatusTimeOut:
            if (0U != changeValue)
            {
                /* todo: update controller state */

                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

static void _USB_OtgEnterStateBHost(usb_otg_instance_t *otgInstance)
{
    if ((0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusAConn))) ||
        (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusBusReq))))
    {
        _USB_OtgEnterStateBPeripheral(otgInstance);
    }
    else if (0U == (otgInstance->otgControllerStatus & ((uint32_t)kOtg_StatusVbusVld)))
    {
        _USB_OtgEnterStateBPeripheral(otgInstance);
    }
    else
    {
        otgInstance->otgDeviceState = (uint8_t)kOtg_State_BHost;
        otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusReq);
        otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBHNPFeature;

        (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                  (uint32_t)kOtg_ControlPullDown,
                                                                  ((uint32_t)kOtg_PullDp) | ((uint32_t)kOtg_PullDm), 0);

        (void)otgInstance->controllerInterface->controllerControl(
            otgInstance->controllerHandle, (uint32_t)kOtg_ControlRequestStatus, (uint32_t)kOtg_StatusADisconn,
            (uint32_t)kOtg_State_BHost);

        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStateChange, kOtg_State_BHost);

#if (USB_OTG_TIME_WAIT_DEVICE_INIT != 0U)
        otgInstance->waitInit = 1U;
        _USB_OtgStartTimer(otgInstance, USB_OTG_TIME_WAIT_DEVICE_INIT);
#else
        /* start work as host */
        otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit, kOtg_StackHostInit);
#endif
    }
}

static void _USB_OtgProcessStateBHost(usb_otg_instance_t *otgInstance, uint32_t otgChangeType, uint32_t changeValue)
{
    usb_otg_status_type_t statusType = (usb_otg_status_type_t)otgChangeType;
    switch (statusType)
    {
#if (USB_OTG_TIME_WAIT_DEVICE_INIT != 0U)
        case kOtg_StatusTimeOut:
            if (0U != otgInstance->waitInit) /* wait device init */
            {
                /* start work as host */
                otgInstance->waitInit = 0;
                otgInstance->otgCallback(otgInstance->otgCallbackParameter, kOtg_EventStackInit,
                                         kOtg_StackHostInit); /* host stack init */
            }
            break;
#endif

        case kOtg_StatusBusReq:
            if (0U == changeValue) /* B release bus */
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBusReq);

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            else /* A request bus */
            {
                /* todo: update controller state */

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        case kOtg_StatusAConn:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusAConn);

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        case kOtg_StatusVbusVld:
            if (0U == changeValue)
            {
                /* todo: update controller state */
                otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusVbusVld);

                _USB_OtgExitHost(otgInstance);
                _USB_OtgEnterStateBPeripheral(otgInstance); /* go to b_peripheral */
            }
            break;

        default:
            if (0U != changeValue)
            {
                otgInstance->otgControllerStatus |= (uint32_t)otgChangeType;
            }
            else
            {
                otgInstance->otgControllerStatus &= ~((uint32_t)otgChangeType);
            }
            break;
    }
}

usb_status_t USB_OtgInit(uint8_t controllerId,
                         usb_otg_handle *otgHandle,
                         usb_otg_callback_t otgCallbackFn,
                         void *callbackParameter)
{
    usb_otg_instance_t *otgInstance = NULL;

    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    /* 1. initialize otg stack */
    otgInstance = (usb_otg_instance_t *)OSA_MemoryAllocate(sizeof(usb_otg_instance_t));
    if (otgInstance == NULL)
    {
        return kStatus_USB_AllocFail;
    }
    /* initialize msg queue */
    otgInstance->otgMsgHandle = (osa_msgq_handle_t)&otgInstance->otgMsgHandleBuffer[0];
    if (KOSA_StatusSuccess != OSA_MsgQCreate(otgInstance->otgMsgHandle, USB_OTG_MSG_COUNT, USB_OTG_MESSAGES_SIZE))
    {
        OSA_MemoryFree(otgInstance);
        return kStatus_USB_Error;
    }
    /* otg instance structure filed initialization */
    otgInstance->otgControllerStatus  = 0U; /* default controller status */
    otgInstance->otgCallback          = otgCallbackFn;
    otgInstance->otgCallbackParameter = callbackParameter;
    otgInstance->hasUpdateMsg         = 0U;

    /* 2. initialize controller */
    _USB_OtgGetControllerInterface(controllerId, &otgInstance->controllerInterface);
    if ((otgInstance->controllerInterface == NULL) || (otgInstance->controllerInterface->controllerInit == NULL) ||
        (otgInstance->controllerInterface->controllerDeinit == NULL) ||
        (otgInstance->controllerInterface->controllerControl == NULL))
    {
        (void)OSA_MsgQDestroy(otgInstance->otgMsgHandle);
        OSA_MemoryFree(otgInstance);
        return kStatus_USB_Error;
    }
    if (otgInstance->controllerInterface->controllerInit(controllerId, otgInstance, &otgInstance->controllerHandle) !=
        kStatus_USB_Success)
    {
        (void)OSA_MsgQDestroy(otgInstance->otgMsgHandle);
        OSA_MemoryFree(otgInstance);
        return kStatus_USB_Error;
    }

    _USB_OtgEnterStateStart(otgInstance);

    *otgHandle = otgInstance;
    return kStatus_USB_Success;
}

usb_status_t USB_OtgDeinit(usb_otg_handle otgHandle)
{
    usb_otg_instance_t *otgInstance = (usb_otg_instance_t *)otgHandle;

    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    /* 1. de-initialize controller */
    (void)otgInstance->controllerInterface->controllerDeinit(otgInstance->controllerHandle);

    /* 2. de-initialize otg stack */
    (void)OSA_MsgQDestroy(otgInstance->otgMsgHandle);
    OSA_MemoryFree(otgInstance);

    return kStatus_USB_Success;
}

void USB_OtgTaskFunction(usb_otg_handle otgHandle)
{
    usb_otg_instance_t *otgInstance = (usb_otg_instance_t *)otgHandle;
    usb_otg_msg_t otgMsg;
    usb_otg_device_state_t deviceState;

    if (otgHandle == NULL)
    {
        return;
    }

    /* wait forever for one message */
    if (OSA_MsgQGet(otgInstance->otgMsgHandle, (osa_msg_handle_t)&otgMsg, USB_OSA_WAIT_TIMEOUT) == KOSA_StatusSuccess)
    {
        if (otgMsg.otgStatusType == (uint32_t)kOtg_StatusChange)
        {
            otgInstance->hasUpdateMsg = 0;
            (void)otgInstance->controllerInterface->controllerControl(otgInstance->controllerHandle,
                                                                      kOtg_ControlUpdateStatus, 0, 0);
        }
        else
        {
            if (otgMsg.otgStatusType == (uint32_t)kOtg_StatusTimeOut)
            {
                otgInstance->hasTimeOutMsg--;
                if (0U != otgInstance->cancelTime)
                {
                    otgInstance->cancelTime = 0;
                    return;
                }
            }

            deviceState = (usb_otg_device_state_t)otgInstance->otgDeviceState;
            switch (deviceState)
            {
                case kOtg_State_Start:
                    _USB_OtgProcessStateStart(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AIdle:
                    _USB_OtgProcessStateAIdle(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AWaitVrise:
                    _USB_OtgProcessStateAWaitVrise(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AWaitBcon:
                    _USB_OtgProcessStateAWaitBcon(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AHost:
                    _USB_OtgProcessStateAHost(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AWaitVfall:
                    _USB_OtgProcessStateAWaitVfall(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_ASuspend:
                    _USB_OtgProcessStateASuspend(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_APeripheral:
                    _USB_OtgProcessStateAPeripheral(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_AVbusErr:
                    _USB_OtgProcessStateAVbusErr(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_BIdleEh:
                    /* The device is OTG device */
                    break;

                case kOtg_State_BIdle:
                    _USB_OtgProcessStateBIdle(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_BSrpInit:
                    _USB_OtgProcessStateBSrpInit(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_BPeripheral:
                    _USB_OtgProcessStateBPeripheral(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_BWaitAcon:
                    _USB_OtgProcessStateBWaitAcon(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                case kOtg_State_BHost:
                    _USB_OtgProcessStateBHost(otgInstance, otgMsg.otgStatusType, otgMsg.otgStatusValue);
                    break;

                default:
                    /*no action*/
                    break;
            }
        }
    }
}

usb_status_t USB_OtgBusDrop(usb_otg_handle otgHandle, uint8_t drop)
{
    usb_otg_instance_t *otgInstance = (usb_otg_instance_t *)otgHandle;

    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    if ((otgInstance->otgDeviceState >= (uint8_t)kOtg_State_AIdle) &&
        (otgInstance->otgDeviceState <= (uint8_t)kOtg_State_AVbusErr))
    {
        return USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBusDrop, drop);
    }
    else
    {
        return kStatus_USB_Error;
    }
}

usb_status_t USB_OtgBusRequest(usb_otg_handle otgHandle)
{
    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    return USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBusReq, 1);
}

usb_status_t USB_OtgBusRelease(usb_otg_handle otgHandle)
{
    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    return USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBusReq, 0);
}

usb_status_t USB_OtgClearError(usb_otg_handle otgHandle)
{
    usb_otg_instance_t *otgInstance = (usb_otg_instance_t *)otgHandle;

    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    if (otgInstance->otgDeviceState == (uint8_t)kOtg_State_AVbusErr)
    {
        return USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusClrErr, 1);
    }
    else
    {
        return kStatus_USB_Error;
    }
}

usb_status_t USB_OtgNotifyChange(usb_otg_handle otgHandle, uint32_t statusType, uint32_t statusValue)
{
    usb_otg_msg_t otgMsg;
    usb_otg_instance_t *otgInstance = (usb_otg_instance_t *)otgHandle;

    if (otgHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }

    if (statusType == (uint32_t)kOtg_StatusTimeOut)
    {
        otgInstance->hasTimeOutMsg++;
    }
    else if (statusType == (uint32_t)kOtg_StatusChange)
    {
        if (otgInstance->hasUpdateMsg == 1U)
        {
            return kStatus_USB_Success;
        }
    }
    else if (statusType == (uint32_t)kOtg_StatusBHNPFeature)
    {
        if (0U != statusValue)
        {
            otgInstance->otgControllerStatus |= (uint32_t)kOtg_StatusBHNPFeature;
        }
        else
        {
            otgInstance->otgControllerStatus &= ~((uint32_t)kOtg_StatusBHNPFeature);
        }
    }
    else if (statusType == (uint32_t)kOtg_StatusId)
    {
        if (statusValue == 0U)
        {
            otgInstance->idChangeAsFalse = 1U;
        }
    }
    else
    {
    }

    otgMsg.otgStatusType  = statusType;
    otgMsg.otgStatusValue = statusValue;
    if (OSA_MsgQPut(otgInstance->otgMsgHandle, (osa_msg_handle_t)&otgMsg) == KOSA_StatusSuccess)
    {
        if (statusType == (uint32_t)kOtg_StatusChange)
        {
            otgInstance->hasUpdateMsg = 1;
        }
        return kStatus_USB_Success;
    }

    return kStatus_USB_Error;
}
