/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017,2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_otg_config.h"

#if ((defined USB_OTG_CONFIG_KHCI) && (USB_OTG_CONFIG_KHCI))

#include "fsl_device_registers.h"
#include "usb_otg.h"
#include "usb_otg_oci.h"
#include "usb_otg_khci.h"
#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
#include "usb_otg_peripheral.h"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void _USB_OtgKhciRequestState(usb_otg_khci_instance_t *otgKhciInstance,
                                     uint32_t requestState,
                                     uint32_t stateMachine);
static usb_status_t _USB_OtgKhciCheckSrp(usb_otg_khci_instance_t *otgKhciInstance);
/*misra 17.2 function can't call themselves*/
static usb_status_t USB_OtgKhciControlPullUp(usb_otg_controller_handle controllerHandle,
                                             uint32_t controlValue1,
                                             uint32_t controlValue2);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

static usb_status_t _USB_OtgKhciCheckSrp(usb_otg_khci_instance_t *otgKhciInstance)
{
    otgKhciInstance->checkTime++;

    if (otgKhciInstance->checkTime >= USB_OTG_TIME_SRP_TIME_OUT)
    {
        otgKhciInstance->checkTime     = 0U;
        otgKhciInstance->checkSrpState = 0U;
    }

    if (otgKhciInstance->checkSrpState == 0U) /* check SE0 */
    {
        if (0U != otgKhciInstance->se0State) /* se0 */
        {
            otgKhciInstance->checkSrpState = 1U;
        }
    }
    else if (otgKhciInstance->checkSrpState == 1U) /* check J */
    {
        if (0U != otgKhciInstance->jState) /* J */
        {
            otgKhciInstance->checkSrpState = 2;
            otgKhciInstance->checkTime     = 0;
        }
        else if ((0U == (otgKhciInstance->se0State)) &&
                 (0U != (otgKhciInstance->usbRegBase->OTGSTAT & USB_OTGSTAT_LINESTATESTABLE_MASK)))
        {
            otgKhciInstance->checkSrpState = 0U;
        }
        else
        {
            /*no action*/
        }
    }
    else if (otgKhciInstance->checkSrpState == 2U) /* check SE0 */
    {
        if (0U != otgKhciInstance->se0State) /* se0 */
        {
            otgKhciInstance->checkSrpState = 0U; /* check next srp */
            if ((otgKhciInstance->checkTime >= USB_OTG_TIME_B_DATA_PLS_MIN) &&
                (otgKhciInstance->checkTime <= USB_OTG_TIME_B_DATA_PLS_MAX))
            {
                otgKhciInstance->checkTime = 0U;
                (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusSrpDet, 1U);
                return kStatus_USB_Success;
            }
        }
        else if ((0U == (otgKhciInstance->jState)) &&
                 (0U != (otgKhciInstance->usbRegBase->OTGSTAT & USB_OTGSTAT_LINESTATESTABLE_MASK)))
        {
            otgKhciInstance->checkSrpState = 0U;
        }
        else
        {
            /*no action*/
        }
    }
    else
    {
        /*no action*/
    }

    return kStatus_USB_Error;
}
/*add this for misra 17.2, function can't call themselves. the function is same as kOtg_ControlPullUp of
 * USB_OtgKhciControl*/
static usb_status_t USB_OtgKhciControlPullUp(usb_otg_controller_handle controllerHandle,
                                             uint32_t controlValue1,
                                             uint32_t controlValue2)

{
    usb_otg_khci_instance_t *otgKhciInstance = (usb_otg_khci_instance_t *)controllerHandle;
    if (controllerHandle == NULL)
    {
        return kStatus_USB_Error;
    }

    if (0U != (controlValue1 & ((uint32_t)kOtg_PullDp)))
    {
#if (FSL_FEATURE_USB_KHCI_OTG_ENABLED)
        otgKhciInstance->usbRegBase->OTGCTL |= USB_OTGCTL_DPHIGH_MASK;
        otgKhciInstance->usbRegBase->CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
#else
        otgKhciInstance->usbRegBase->CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
#endif
    }
    else
    {
#if (FSL_FEATURE_USB_KHCI_OTG_ENABLED)
        otgKhciInstance->usbRegBase->OTGCTL &= (uint8_t)(~USB_OTGCTL_DPHIGH_MASK);
        otgKhciInstance->usbRegBase->CONTROL &= (uint8_t)(~USB_CONTROL_DPPULLUPNONOTG_MASK);
#else
        otgKhciInstance->usbRegBase->CONTROL &= (uint8_t)(~USB_CONTROL_DPPULLUPNONOTG_MASK);
#endif
    }
    return kStatus_USB_Success;
}
static void USB_OtgKhciParsePeripheralStatus(usb_otg_khci_instance_t *otgKhciInstance, uint32_t newStatus)
{
    uint32_t changes = 0;
    uint32_t value   = 0;

    changes                           = otgKhciInstance->peripheralStatus ^ newStatus;
    otgKhciInstance->peripheralStatus = newStatus;

    if (otgKhciInstance->checkType == (uint8_t)kOtg_CheckBHNP)
    {
        if (0U != (newStatus & ((uint32_t)kPeripheral_StatusHNPdetected)))
        {
            if (otgKhciInstance->lastState == (uint32_t)kOtg_State_ASuspend)
            {
                /* keep the pull-up */
                (void)USB_OtgKhciControlPullUp(otgKhciInstance, (uint32_t)kOtg_PullDp, 0U);
                /* disable hnp check */
                (void)USB_OtgPeripheralControl(otgKhciInstance, (uint32_t)kPeripheral_ControlHNPCheckEnable, 0U, 0U);
                (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusBConn,
                                          0U); /* enter a_peripheral */
            }
            else if (otgKhciInstance->lastState == (uint32_t)kOtg_State_BWaitAcon)
            {
                (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusAConn,
                                          1U); /* enter b_host */
            }
            else
            {
                /*no action*/
            }
        }
    }

    if (0U != (changes & ((uint32_t)kPeripheral_StatusId)))
    {
        value = 0U;
        if (0U != (newStatus & ((uint32_t)kPeripheral_StatusId)))
        {
            value = 1U;
        }
        (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusId, value);
    }

    if (0U != (changes & ((uint32_t)kPeripheral_StatusSessVld)))
    {
        value = 0U;
        if (0U != (newStatus & ((uint32_t)kPeripheral_StatusSessVld)))
        {
            value = 1U;
        }
        (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusSessVld, value);
    }

    if (0U != (changes & ((uint8_t)kPeripheral_StatusVbusVld)))
    {
        value = 0U;
        if (0U != (newStatus & ((uint8_t)kPeripheral_StatusVbusVld)))
        {
            value = 1U;
        }
        (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusVbusVld, value);
    }
}

static void _USB_OtgKhciRequestState(usb_otg_khci_instance_t *otgKhciInstance,
                                     uint32_t requestState,
                                     uint32_t stateMachine)
{
    uint32_t value;
    otgKhciInstance->checkType = (uint8_t)kOtg_CheckNone;

    if ((stateMachine == ((uint32_t)kOtg_State_ASuspend)) || (stateMachine == ((uint32_t)kOtg_State_BWaitAcon)))
    {
        /* enable hnp check */
        (void)USB_OtgPeripheralControl(otgKhciInstance, (uint32_t)kPeripheral_ControlHNPCheckEnable, 1U, 0U);
        otgKhciInstance->checkTime = USB_OTG_TIME_CHECK_BHNP_PERIODIC;
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckBHNP;
    }
    else
    {
        /* disable hnp check */
        (void)USB_OtgPeripheralControl(otgKhciInstance, (uint32_t)kPeripheral_ControlHNPCheckEnable, 0U, 0U);
    }

    /*
     * Don't need process the follow requested state because they are notified by interrupt:
     * kOtg_StatusId, kOtg_StatusVbusVld, kOtg_StatusVbusInvld, kOtg_StatusSessInvld, kOtg_StatusSessVld
     */
    if (0U != (requestState & ((uint32_t)kOtg_StatusAdpChange)))
    {
        /* todo: not yet */
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusSrpDet)))
    {
        otgKhciInstance->checkTime = 0;
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckSrp;
    }

    if (0U != (requestState & ((uint8_t)kOtg_StatusAConn)))
    {
        /* check max3353 BHNP periodic */
        otgKhciInstance->checkTime = USB_OTG_TIME_CHECK_BHNP_PERIODIC;
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckBHNP;
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusBusResume)))
    {
        /* todo: check resume, not yet */
    }

    if (0U != (requestState & ((uint8_t)kOtg_StatusBusSuspend)))
    {
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckSuspend;
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusSe0Srp)))
    {
        otgKhciInstance->checkTime = 0;
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckSsendSe0Srp; /* check session invalid */
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusSsendSrp)))
    {
        if (otgKhciInstance->bssendsrpCheck > USB_OTG_TIME_B_SSEND_SRP)
        {
            (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusSsendSrp, 1);
        }
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusBConn)))
    {
        if (otgKhciInstance->lastState == (uint32_t)kOtg_State_AWaitVrise)
        {
            otgKhciInstance->checkTime = USB_OTG_TIME_A_BCON_LDB;
        }
        else
        {
            otgKhciInstance->checkTime = USB_OTG_TIME_A_BCON_SDB;
        }
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckConn;
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusBDisconn)))
    {
        if (stateMachine != ((uint32_t)kOtg_State_ASuspend))
        {
            otgKhciInstance->checkTime = USB_OTG_TIME_CHECK_DETACH;
            otgKhciInstance->checkType = (uint8_t)kOtg_CheckNonConn;
        }
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusADisconn)))
    {
        otgKhciInstance->checkTime = USB_OTG_TIME_CHECK_DETACH;
        otgKhciInstance->checkType = (uint8_t)kOtg_CheckNonConn;
    }

    if (0U != (requestState & ((uint32_t)kOtg_StatusCheckIdleInAPeripheral)))
    {
        otgKhciInstance->checkType      = (uint8_t)kOtg_CheckIdleTimeOut;
        otgKhciInstance->lineStableTime = 0U;
    }

#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
    (void)USB_OtgPeripheralGetStatus((uint32_t)kPeripheral_StatusAll, &value);
    (void)USB_OtgKhciParsePeripheralStatus(otgKhciInstance, value);

    /* at start, don't know the id state, so need notify the id state no matter the id value */
    if (0U != ((requestState & ((uint32_t)kOtg_StatusId))) && (stateMachine == ((uint32_t)kOtg_State_Start)))
    {
        (void)USB_OtgPeripheralGetStatus((uint32_t)kPeripheral_StatusAll, &value);
        otgKhciInstance->peripheralStatus = value; /* initialized status */
        if (0U != (value & ((uint32_t)kPeripheral_StatusId)))
        {
            value = 1U;
        }
        else
        {
            value = 0U;
        }
        (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusId, value);
    }
#endif

    otgKhciInstance->lastState = stateMachine;
}

usb_status_t USB_OtgKhciInit(uint8_t controllerId,
                             usb_otg_handle otgHandle,
                             usb_otg_controller_handle *controllerHandle)
{
    usb_otg_khci_instance_t *otgKhciInstance;
    uint32_t usbfsBaseAddrs[] = USB_BASE_ADDRS;
    void *temp;
    uint32_t *pointer;

    if (((uint32_t)controllerId - (uint32_t)kUSB_ControllerKhci0) >=
        (sizeof(usbfsBaseAddrs) / sizeof(usbfsBaseAddrs[0])))
    {
        return kStatus_USB_ControllerNotFound;
    }
    if (otgHandle == NULL)
    {
        return kStatus_USB_Error;
    }

    otgKhciInstance = (usb_otg_khci_instance_t *)OSA_MemoryAllocate(sizeof(usb_otg_khci_instance_t));
    if (otgKhciInstance == NULL)
    {
        return kStatus_USB_AllocFail;
    }
    otgKhciInstance->otgHandle           = otgHandle;
    pointer                              = (uint32_t *)usbfsBaseAddrs[controllerId - (uint8_t)kUSB_ControllerKhci0];
    temp                                 = (void *)pointer;
    otgKhciInstance->usbRegBase          = (USB_Type *)temp;
    otgKhciInstance->externalTimerEnable = 0U;

    /* initialize controller */
    otgKhciInstance->usbRegBase->ISTAT    = 0xFFU; /* clear all interrupts */
    otgKhciInstance->usbRegBase->OTGISTAT = 0xFFU;
    otgKhciInstance->usbRegBase->OTGCTL |= USB_OTGCTL_OTGEN_MASK; /* enable otg */
    otgKhciInstance->usbRegBase->OTGICR |=
        (USB_OTGICR_LINESTATEEN_MASK | USB_OTGICR_ONEMSECEN_MASK); /* 1ms and LINE_STAT_CHG interrupts */

    *controllerHandle = otgKhciInstance;
#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
    return USB_OtgPeripheralEnable();
#else
    return kStatus_USB_Success;
#endif
}

usb_status_t USB_OtgKhciDeinit(usb_otg_controller_handle controllerHandle)
{
    usb_otg_khci_instance_t *otgKhciInstance = (usb_otg_khci_instance_t *)controllerHandle;

    if (controllerHandle == NULL)
    {
        return kStatus_USB_Error;
    }

    /* clear all interrupts */
    otgKhciInstance->usbRegBase->OTGCTL &= (uint8_t)(~USB_OTGCTL_OTGEN_MASK); /* disable otg */
    otgKhciInstance->usbRegBase->ISTAT    = 0xFFU;
    otgKhciInstance->usbRegBase->OTGISTAT = 0xFFU;

    OSA_MemoryFree(otgKhciInstance);

#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
    return USB_OtgPeripheralDisable();
#else
    return kStatus_USB_Success;
#endif
}

usb_status_t USB_OtgKhciControl(usb_otg_controller_handle controllerHandle,
                                uint32_t controlType,
                                uint32_t controlValue1,
                                uint32_t controlValue2)
{
    usb_otg_khci_instance_t *otgKhciInstance = (usb_otg_khci_instance_t *)controllerHandle;
    uint32_t statusValue                     = 0U;
    usb_otg_control_t controlCode            = (usb_otg_control_t)controlType;
    if (controllerHandle == NULL)
    {
        return kStatus_USB_Error;
    }

    switch (controlCode)
    {
        case kOtg_ControlPullUp:
            if (0U != (controlValue1 & ((uint32_t)kOtg_PullDp)))
            {
#if (FSL_FEATURE_USB_KHCI_OTG_ENABLED)
                otgKhciInstance->usbRegBase->OTGCTL |= USB_OTGCTL_DPHIGH_MASK;
                otgKhciInstance->usbRegBase->CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
#else
                otgKhciInstance->usbRegBase->CONTROL |= USB_CONTROL_DPPULLUPNONOTG_MASK;
#endif
            }
            else
            {
#if (FSL_FEATURE_USB_KHCI_OTG_ENABLED)
                otgKhciInstance->usbRegBase->OTGCTL &= (uint8_t)(~USB_OTGCTL_DPHIGH_MASK);
                otgKhciInstance->usbRegBase->CONTROL &= (uint8_t)(~USB_CONTROL_DPPULLUPNONOTG_MASK);
#else
                otgKhciInstance->usbRegBase->CONTROL &= (uint8_t)(~USB_CONTROL_DPPULLUPNONOTG_MASK);
#endif
            }
            break;
        case kOtg_ControlPullDown:
            if (0U != (controlValue1 & ((uint32_t)kOtg_PullDp)))
            {
                otgKhciInstance->usbRegBase->OTGCTL |= USB_OTGCTL_DPLOW_MASK;
            }
            else
            {
                otgKhciInstance->usbRegBase->OTGCTL &= (uint8_t)(~USB_OTGCTL_DPLOW_MASK);
            }

            if (0U != (controlValue1 & ((uint32_t)kOtg_PullDm)))
            {
                otgKhciInstance->usbRegBase->OTGCTL |= USB_OTGCTL_DMLOW_MASK;
            }
            else
            {
                otgKhciInstance->usbRegBase->OTGCTL &= (uint8_t)(~USB_OTGCTL_DMLOW_MASK);
            }
            break;

        case kOtg_ControlResume:
            if (0U != controlValue1)
            {
                otgKhciInstance->usbRegBase->CTL |= USB_CTL_RESUME_MASK;

                otgKhciInstance->internalTimerValue = (uint16_t)controlValue1; /* ms */
                while (otgKhciInstance->internalTimerValue > 0U)
                {
                }

                otgKhciInstance->usbRegBase->CTL &= (uint8_t)(~USB_CTL_RESUME_MASK);
            }
            break;
#if ((defined USB_OTG_ADP_ENABLE) && (USB_OTG_ADP_ENABLE))
        case kOtg_ControlAdpPrb:
            break;
#endif

        case kOtg_ControlDataPulse:
            /* send srp */
            (void)USB_OtgKhciControlPullUp(otgKhciInstance, (uint32_t)kOtg_PullDp, 0U);
            otgKhciInstance->internalTimerValue = USB_OTG_TIME_B_DATA_PLS; /* ms */
            while (otgKhciInstance->internalTimerValue > 0U)
            {
            }
            (void)USB_OtgKhciControlPullUp(otgKhciInstance, 0U, 0U);
            (void)USB_OtgNotifyChange(otgKhciInstance->otgHandle, (uint32_t)kOtg_StatusBSrpDone, 1U);
            break;

        case kOtg_ControlSetTimer:
            otgKhciInstance->externalTimerEnable = 1U;
            otgKhciInstance->externalTimerValue  = (uint16_t)controlValue1;
            break;

        case kOtg_ControlCancelTimer:
            otgKhciInstance->externalTimerEnable = 0U;
            break;

        case kOtg_ControlVbus:
#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
            (void)USB_OtgPeripheralControl(otgKhciInstance, (uint32_t)kPeripheral_ControlVbus, controlValue1, 0U);
#endif
            break;

        case kOtg_ControlUpdateStatus:
#if ((defined USB_OTG_KHCI_PERIPHERAL_ENABLE) && (USB_OTG_KHCI_PERIPHERAL_ENABLE))
            (void)USB_OtgPeripheralControl(otgKhciInstance, (uint32_t)kPeripheral_ControlUpdateStatus, controlValue1,
                                           0U);
#endif
            (void)USB_OtgPeripheralGetStatus((uint32_t)kPeripheral_StatusAll, &statusValue);
            (void)USB_OtgKhciParsePeripheralStatus(otgKhciInstance, statusValue);
            break;

        case kOtg_ControlRequestStatus:
            (void)_USB_OtgKhciRequestState(otgKhciInstance, controlValue1, controlValue2);
            break;

        default:
            /*no action*/
            break;
    }

    return kStatus_USB_Success;
}

void USB_OtgKhciIsrFunction(usb_otg_handle otgHandle)
{
    usb_otg_khci_instance_t *otgKhciInstance;
    uint8_t otgInterrupts;
    uint32_t value;
    usb_otg_check_type_t checkType;
    if (otgHandle == NULL)
    {
        return;
    }
    otgKhciInstance = (usb_otg_khci_instance_t *)(((usb_otg_instance_t *)otgHandle)->controllerHandle);

    otgInterrupts = (otgKhciInstance->usbRegBase->OTGISTAT & otgKhciInstance->usbRegBase->OTGICR);
    otgKhciInstance->usbRegBase->OTGISTAT = otgInterrupts; /* clear interrupts */

    if ((0U != (otgInterrupts & USB_OTGISTAT_LINE_STATE_CHG_MASK)) &&
        (0U !=
         (otgKhciInstance->usbRegBase->OTGSTAT & USB_OTGSTAT_LINESTATESTABLE_MASK))) /* line state change and stable */
    {
        otgKhciInstance->lineStableTime = 0U;
        otgKhciInstance->se0State       = otgKhciInstance->usbRegBase->CTL & USB_CTL_SE0_MASK;
        if (0U != (otgKhciInstance->se0State))
        {
            otgKhciInstance->jState = 0U;
        }
        else
        {
            otgKhciInstance->jState = otgKhciInstance->usbRegBase->CTL & USB_CTL_JSTATE_MASK;
        }
    }

    if (0U != (otgInterrupts & USB_OTGISTAT_ONEMSEC_MASK)) /* 1ms */
    {
        if (0U == (otgKhciInstance->usbRegBase->OTGSTAT & USB_OTGSTAT_LINESTATESTABLE_MASK))
        {
            otgKhciInstance->lineStableTime = 0U;
            otgKhciInstance->se0State       = otgKhciInstance->usbRegBase->CTL & USB_CTL_SE0_MASK;
            otgKhciInstance->jState         = 0U;
        }
        else
        {
            if (otgKhciInstance->lineStableTime != 0xFFFFU)
            {
                otgKhciInstance->lineStableTime++;
            }
        }

        if ((0U != otgKhciInstance->externalTimerEnable) && (otgKhciInstance->externalTimerValue > 0U))
        {
            otgKhciInstance->externalTimerValue--;
            if (otgKhciInstance->externalTimerValue == 0U)
            {
                otgKhciInstance->externalTimerEnable = 0U;
                (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusTimeOut, 1U);
            }
        }

        if (otgKhciInstance->internalTimerValue > 0U)
        {
            otgKhciInstance->internalTimerValue--;
        }

        checkType = (usb_otg_check_type_t)otgKhciInstance->checkType;
        switch (checkType)
        {
            case kOtg_CheckNonConn:
                if ((0U != otgKhciInstance->se0State) && (otgKhciInstance->lineStableTime > otgKhciInstance->checkTime))
                {
                    otgKhciInstance->checkType = (uint8_t)kOtg_CheckNone;
                    if (otgKhciInstance->lastState == (uint32_t)kOtg_State_BHost)
                    {
                        (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusAConn, 0);
                    }
                    else if ((otgKhciInstance->lastState == (uint32_t)kOtg_State_AHost))
                    {
                        (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBConn, 0);
                    }
                    else
                    {
                        /*no action*/
                    }
                }
                break;

            case kOtg_CheckConn:
                if ((0U == (otgKhciInstance->se0State)) && (0U != otgKhciInstance->jState) &&
                    (0U != (otgKhciInstance->usbRegBase->OTGSTAT & USB_OTGSTAT_LINESTATESTABLE_MASK)))
                {
                    if (otgKhciInstance->lastState == (uint32_t)kOtg_State_AWaitBcon)
                    {
                        if (otgKhciInstance->lineStableTime >= otgKhciInstance->checkTime)
                        {
                            otgKhciInstance->checkType = (uint8_t)kOtg_CheckNone;
                            (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBConn, 1U);
                        }
                    }
                }
                break;

            case kOtg_CheckSsendSe0Srp: /* b_idle */
                if ((0U != otgKhciInstance->se0State) &&
                    (otgKhciInstance->lineStableTime >= USB_OTG_TIME_B_SE0_SRP)) /* se0 */
                {
                    otgKhciInstance->lineStableTime = 0U;
                    (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusSe0Srp, 1U);
                }
                break;

            case kOtg_CheckIdleTimeOut: /* a_peripheral */
                if ((otgKhciInstance->lineStableTime >= USB_OTG_TIME_A_BIDL_ADIS))
                {
                    otgKhciInstance->checkType = (uint8_t)kOtg_CheckNone;
                    (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusTimeOut, 1U);
                }
                break;

            case kOtg_CheckSrp:
                (void)_USB_OtgKhciCheckSrp(otgKhciInstance);
                break;

            case kOtg_CheckBHNP:
                otgKhciInstance->checkTime--;
                if (otgKhciInstance->checkTime == 0U)
                {
                    otgKhciInstance->checkTime = USB_OTG_TIME_CHECK_BHNP_PERIODIC;
                    /* poll for HNP because max3353 has no interrupt for it */
                    (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusChange, 1U);
                }
                break;

            case kOtg_CheckSuspend:
                if (otgKhciInstance->lineStableTime >= USB_OTG_TIME_B_AIDL_BDIS) /* suspend */
                {
                    otgKhciInstance->lineStableTime = 0;
                    (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusBusSuspend, 1);
                }
                break;

            default:
                /*no action*/
                break;
        }

        if (otgKhciInstance->bssendsrpCheck <= USB_OTG_TIME_B_SSEND_SRP)
        {
            (void)USB_OtgPeripheralGetStatus((uint32_t)kPeripheral_StatusSessVld, &value);
            if (0U != value)
            {
                otgKhciInstance->peripheralStatus |= (uint32_t)kPeripheral_StatusSessVld;
            }
            else
            {
                otgKhciInstance->peripheralStatus &= (~((uint32_t)kPeripheral_StatusSessVld));
            }
            if (0U == value) /* invalid */
            {
                otgKhciInstance->bssendsrpCheck++;
                if (otgKhciInstance->bssendsrpCheck > USB_OTG_TIME_B_SSEND_SRP)
                {
                    (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusSsendSrp, 1);
                }
            }
#if 0
            else /* valid */
            {
                otgKhciInstance->bssendsrpCheck = 0; /* stop check */
                (void)USB_OtgNotifyChange(otgHandle, (uint32_t)kOtg_StatusSessVld, 1);
            }
#endif
        }
    }
}

#endif
