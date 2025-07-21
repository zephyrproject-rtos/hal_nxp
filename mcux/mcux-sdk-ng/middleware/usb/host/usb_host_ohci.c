/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016,2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "usb_host_config.h"
#if (defined(USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
#include "usb_host.h"
#include "usb_host_hci.h"
#include "fsl_device_registers.h"
#include "usb_host_ohci.h"
#include "usb_host_devices.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* reset recovery time (ms) */
#define USB_HOST_OHCI_PORT_RESET_RECOVERY_DELAY (11U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static usb_status_t USB_HostOhciLinkGtdControlTr(usb_host_ohci_state_struct_t *usbHostState,
                                                 usb_host_ohci_pipe_struct_t *pipe,
                                                 usb_host_transfer_t *tr);
#if ((defined USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD))
static usb_status_t USB_HostOhciLinkItdTr(usb_host_ohci_state_struct_t *usbHostState,
                                          usb_host_ohci_pipe_struct_t *pipe,
                                          usb_host_transfer_t *tr);
static usb_status_t USB_HostOhciFreeItd(usb_host_ohci_state_struct_t *usbHostState,
                                        usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd);
#endif
static usb_status_t USB_HostOhciLinkGtdTr(usb_host_ohci_state_struct_t *usbHostState,
                                          usb_host_ohci_pipe_struct_t *pipe,
                                          usb_host_transfer_t *tr);
static usb_status_t USB_HostOhciFreeGtd(usb_host_ohci_state_struct_t *usbHostState,
                                        usb_host_ohci_general_transfer_descritpor_struct_t *gtd);
static void USB_HostOhciTdDoneHandle(usb_host_ohci_state_struct_t *usbHostState,
                                     usb_host_ohci_pipe_struct_t *pipe,
                                     usb_host_transfer_t *currentTr,
                                     usb_host_ohci_general_transfer_descritpor_struct_t *gtd,
                                     usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* The hcca for interrupt tansaction, 256-byte alignment*/
USB_CONTROLLER_DATA USB_RAM_ADDRESS_ALIGNMENT(256) static usb_host_ohci_hcca_struct_t
    s_UsbHostOhciHcca[USB_HOST_CONFIG_OHCI];
USB_CONTROLLER_DATA USB_RAM_ADDRESS_ALIGNMENT(32) static usb_host_ohci_td_struct_t
    s_UsbHostOhciTd[USB_HOST_CONFIG_OHCI];
static usb_host_ohci_state_struct_t s_UsbHostOhciState[USB_HOST_CONFIG_OHCI];

/*******************************************************************************
 * Code
 ******************************************************************************/
static void USB_HostOhciDisableIsr(usb_host_ohci_state_struct_t *usbHostState)
{
    OSA_SR_ALLOC();

    /* Enter critical */
    OSA_ENTER_CRITICAL();
    if (0U == usbHostState->isrLevel)
    {
        NVIC_DisableIRQ((IRQn_Type)usbHostState->isrNumber);
    }
    usbHostState->isrLevel++;
    OSA_EXIT_CRITICAL();
}

static void USB_HostOhciEnableIsr(usb_host_ohci_state_struct_t *usbHostState)
{
    OSA_SR_ALLOC();

    /* Enter critical */
    OSA_ENTER_CRITICAL();
    usbHostState->isrLevel--;
    if (0U == usbHostState->isrLevel)
    {
        NVIC_EnableIRQ((IRQn_Type)usbHostState->isrNumber);
    }
    OSA_EXIT_CRITICAL();
}

static void USB_HostOhciDelay(usb_host_ohci_state_struct_t *usbHostState, uint32_t ms)
{
    /* note: the max delay time cannot exceed half of max value (0x4000) */
    uint32_t sofStart;
    uint32_t SofEnd;
    uint32_t distance;

    sofStart =
        ((uint32_t)s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber & USB_HOST_OHCI_FMNUMBER_FN_MASK);

    do
    {
        SofEnd   = (uint32_t)((uint32_t)s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber &
                            USB_HOST_OHCI_FMNUMBER_FN_MASK);
        distance = (uint32_t)(SofEnd - sofStart + USB_HOST_OHCI_FMNUMBER_FN_MASK + 1U) & USB_HOST_OHCI_FMNUMBER_FN_MASK;
    } while ((distance) < (ms)); /* compute the distance between sofStart and SofEnd */
}

static usb_status_t USB_HostOhciControlBus(usb_host_ohci_state_struct_t *usbHostState, uint8_t busControl)
{
#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
    uint32_t portStatus;
#endif
    usb_status_t status                = kStatus_USB_Success;
    usb_host_bus_control_t controlCode = (usb_host_bus_control_t)busControl;
    switch (controlCode)
    {
        case kUSB_HostBusReset:
            break;

        case kUSB_HostBusRestart:
            break;

        case kUSB_HostBusEnableAttach:
            usbHostState->controlIsBusy = 0U;
            break;

        case kUSB_HostBusDisableAttach:
            break;

#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
        case kUSB_HostBusSuspend:
            if (0U != (usbHostState->usbRegBase->HcRhPortStatus[0] & USB_HOST_OHCI_RHPORTSTATUS_CCS_MASK))
            {
                usb_host_instance_t *hostPointer = (usb_host_instance_t *)usbHostState->hostHandle;
                portStatus                       = usbHostState->usbRegBase->HcRhPortStatus[0];

                portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
                portStatus |= USB_HOST_OHCI_RHPORTSTATUS_PSS_MASK;
                usbHostState->usbRegBase->HcRhPortStatus[0] = portStatus;

                portStatus = usbHostState->usbRegBase->HcControl;
                portStatus &= ~USB_HOST_OHCI_CONTROL_HCFS_MASK;
                portStatus |= USB_HOST_OHCI_CONTROL_HCFS(USB_HOST_OHCI_CONTROL_HCFS_SUSPEND) |
                              USB_HOST_OHCI_CONTROL_RWC_MASK | USB_HOST_OHCI_CONTROL_RWE_MASK;
                usbHostState->usbRegBase->HcControl = portStatus;

                usbHostState->matchTick        = hostPointer->hwTick;
                usbHostState->busSuspendStatus = kBus_OhciStartSuspend;

                while ((hostPointer->hwTick - usbHostState->matchTick) <= 3U)
                {
                }

                usbHostState->usbRegBase->HcRhStatus |= USB_HOST_OHCI_RHSTATUS_DRWE_MASK;
                /* call host callback function, function is initialized in USB_HostInit */
                (void)hostPointer->deviceCallback(hostPointer->suspendedDevice, NULL,
                                                  kUSB_HostEventSuspended); /* call host callback function */
                usbHostState->busSuspendStatus = kBus_OhciSuspended;
            }
            else
            {
                status = kStatus_USB_Error;
            }
            break;

        case kUSB_HostBusResume:
            if (0u != (usbHostState->usbRegBase->HcRhPortStatus[0] & USB_HOST_OHCI_RHPORTSTATUS_CCS_MASK))
            {
                portStatus = usbHostState->usbRegBase->HcRhPortStatus[0];
                portStatus &= ~(USB_HOST_OHCI_RHPORTSTATUS_WIC);
                portStatus |= USB_HOST_OHCI_RHPORTSTATUS_POCI_MASK;
                usbHostState->usbRegBase->HcRhPortStatus[0] = portStatus;
                usbHostState->busSuspendStatus              = kBus_OhciStartResume;
            }
            else
            {
                usb_host_instance_t *hostPointer = (usb_host_instance_t *)usbHostState->hostHandle;

                portStatus = usbHostState->usbRegBase->HcControl;
                portStatus &= ~(USB_HOST_OHCI_CONTROL_HCFS_MASK | USB_HOST_OHCI_CONTROL_RWE_MASK |
                                USB_HOST_OHCI_CONTROL_RWC_MASK);
                portStatus |= USB_HOST_OHCI_CONTROL_HCFS(USB_HOST_OHCI_CONTROL_HCFS_OPERATIONAL);
                usbHostState->usbRegBase->HcControl = portStatus;
                portStatus                          = usbHostState->usbRegBase->HcRhPortStatus[0];
                portStatus &= ~(USB_HOST_OHCI_RHPORTSTATUS_WIC);
                portStatus |= USB_HOST_OHCI_RHPORTSTATUS_PES_MASK;
                usbHostState->usbRegBase->HcRhPortStatus[0] = portStatus;
                hostPointer->suspendedDevice                = NULL;
                usbHostState->busSuspendStatus              = kBus_OhciIdle;
                status                                      = kStatus_USB_Error;
            }
            break;
#endif
        default:
            status = kStatus_USB_Error;
            break;
    }
    return status;
}

static uint32_t USB_HostOhciBusTime(uint8_t speed, uint8_t pipeType, uint8_t direction, uint32_t dataLength)
{
    uint32_t result = (3167U + ((1000U * dataLength) * 7U * 8U / 6U)) / 1000U;

    if (pipeType == USB_ENDPOINT_ISOCHRONOUS) /* iso */
    {
        if (speed == USB_SPEED_FULL)
        {
            if (direction == USB_IN)
            {
                result = 7268000U + 83540U * result + USB_HOST_OHCI_TIME_DELAY;
            }
            else
            {
                result = 6265000U + 83540U * result + USB_HOST_OHCI_TIME_DELAY;
            }
        }
        else
        {
            /*no action*/
        }
    }
    else /* interrupt */
    {
        if (speed == USB_SPEED_FULL)
        {
            result = 9107000U + 83540U * result + USB_HOST_OHCI_TIME_DELAY;
        }
        else if (speed == USB_SPEED_LOW)
        {
            if (direction == USB_IN)
            {
                result = 64060000U + 2000U * USB_HOST_OHCI_HUB_LS_SETUP_TIME_DELAY + 676670U * result +
                         USB_HOST_OHCI_TIME_DELAY;
            }
            else
            {
                result = 64107000U + 2000U * USB_HOST_OHCI_HUB_LS_SETUP_TIME_DELAY + 667000U * result +
                         USB_HOST_OHCI_TIME_DELAY;
            }
        }
        else
        {
            /*no action*/
        }
    }

    result /= 1000000U;
    if (result == 0U)
    {
        result = 1U;
    }

    return result;
}

static usb_status_t USB_HostOhciGetPipe(usb_host_ohci_pipe_struct_t **pipeQueue, usb_host_ohci_pipe_struct_t **pipe)
{
    usb_status_t error = kStatus_USB_Busy;
    void *temp;
    OSA_SR_ALLOC();

    /* get a pipe instance */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    if (NULL != (*pipeQueue))
    {
        *pipe      = *pipeQueue;
        temp       = (void *)((*pipe)->pipeCommon.next);
        *pipeQueue = (usb_host_ohci_pipe_struct_t *)temp;
        error      = kStatus_USB_Success;
    }
    /* Exit critical */
    OSA_EXIT_CRITICAL();
    return error;
}

static usb_status_t USB_HostOhciRemovePipe(usb_host_ohci_pipe_struct_t **pipeQueue, usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_pipe_struct_t *p = *pipeQueue;
    usb_host_ohci_pipe_struct_t *pre;
    void *temp;
    OSA_SR_ALLOC();

    /* get a pipe instance */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    pre = NULL;
    while (NULL != p)
    {
        if (p != pipe)
        {
            pre  = p;
            temp = (void *)p->pipeCommon.next;
            p    = (usb_host_ohci_pipe_struct_t *)temp;
        }
        else
        {
            if (NULL == pre)
            {
                temp       = (void *)p->pipeCommon.next;
                *pipeQueue = (usb_host_ohci_pipe_struct_t *)temp;
            }
            else
            {
                pre->pipeCommon.next = p->pipeCommon.next;
            }
            break;
        }
    }
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciInsertPipe(usb_host_ohci_pipe_struct_t **pipeQueue, usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_pipe_struct_t *p = *pipeQueue;
    void *temp;
    OSA_SR_ALLOC();

    /* get a pipe instance */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    while (NULL != p)
    {
        if (p != pipe)
        {
            temp = (void *)p->pipeCommon.next;
            p    = (usb_host_ohci_pipe_struct_t *)temp;
        }
        else
        {
            break;
        }
    }
    if (NULL == p)
    {
        temp                  = (*pipeQueue);
        pipe->pipeCommon.next = (usb_host_pipe_t *)temp;
        *pipeQueue            = pipe;
    }
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciGetGtd(usb_host_ohci_state_struct_t *usbHostState,
                                       usb_host_ohci_general_transfer_descritpor_struct_t **gtd,
                                       uint32_t count)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *p = NULL;
    uint32_t *tmp;
    void *temp;
    OSA_SR_ALLOC();

    /* get a td */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    if (count > usbHostState->gtdCount)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Busy;
    }
    *gtd = NULL;
    while ((0U != count) && (NULL != usbHostState->gtdList))
    {
        if (NULL == (*gtd))
        {
            *gtd = usbHostState->gtdList;
        }
        else
        {
            p->NextTD = (uint32_t)usbHostState->gtdList;
        }
        p = usbHostState->gtdList;

        usbHostState->gtdList = (usb_host_ohci_general_transfer_descritpor_struct_t *)usbHostState->gtdList->nextGtd;
        temp                  = (void *)(p);
        tmp                   = (uint32_t *)(temp);
        usbHostState->gtdCount--;
        for (uint8_t i = 0; i < (sizeof(usb_host_ohci_general_transfer_descritpor_struct_t) / sizeof(uint32_t)); i++)
        {
            tmp[i] = 0U;
        }
        count--;
    }
    if (NULL == p)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Busy;
    }
    p->NextTD = 0U;
    /* Exit critical */
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciFreeGtd(usb_host_ohci_state_struct_t *usbHostState,
                                        usb_host_ohci_general_transfer_descritpor_struct_t *gtd)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *p;
    OSA_SR_ALLOC();

    if (NULL == gtd)
    {
        return kStatus_USB_Error;
    }

    /* free a td */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    p = usbHostState->gtdList;
    while (NULL != p)
    {
        if (p == gtd)
        {
            OSA_EXIT_CRITICAL();
            return kStatus_USB_Success;
        }
        p = (usb_host_ohci_general_transfer_descritpor_struct_t *)p->nextGtd;
    }
    gtd->nextGtd          = usbHostState->gtdList;
    usbHostState->gtdList = gtd;
    usbHostState->gtdCount++;
    /* Exit critical */
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}

#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
static usb_status_t USB_HostOhciGetItd(usb_host_ohci_state_struct_t *usbHostState,
                                       usb_host_ohci_isochronous_transfer_descritpor_struct_t **itd,
                                       uint32_t count)
{
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *p = NULL;
    uint32_t *tmp;
    void *temp;
    OSA_SR_ALLOC();

    /* free a td */
    /* Enter critical */
    OSA_ENTER_CRITICAL();
    if (count > usbHostState->itdCount)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Busy;
    }
    *itd = NULL;
    while ((0U != count) && (NULL != usbHostState->itdList))
    {
        if (NULL == (*itd))
        {
            *itd = usbHostState->itdList;
        }
        else
        {
            p->NextTD = (uint32_t)usbHostState->itdList;
        }
        p                     = usbHostState->itdList;
        usbHostState->itdList = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)usbHostState->itdList->NextTD;
        temp                  = (void *)(p);
        tmp                   = (uint32_t *)(temp);
        usbHostState->itdCount--;
        for (uint32_t i = 0; i < (sizeof(usb_host_ohci_isochronous_transfer_descritpor_struct_t) / sizeof(uint32_t));
             i++)
        {
            tmp[i] = 0U;
        }
        count--;
    }
    if (NULL == p)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Busy;
    }
    p->NextTD = 0U;
    /* Exit critical */
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciFreeItd(usb_host_ohci_state_struct_t *usbHostState,
                                        usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd)
{
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *p;
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *pre;
    OSA_SR_ALLOC();

    if (NULL == itd)
    {
        return kStatus_USB_Error;
    }
    /* free a td */
    /* Enter critical */
    pre = NULL;
    OSA_ENTER_CRITICAL();
    p = usbHostState->itdList;
    while (NULL != p)
    {
        if (p == itd)
        {
            OSA_EXIT_CRITICAL();
            return kStatus_USB_Success;
        }
        pre = p;
        p   = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)p->NextTD;
    }
    if (NULL == pre)
    {
        usbHostState->itdList = itd;
    }
    else
    {
        pre->NextTD = (uint32_t)itd;
    }
    itd->NextTD = 0U;
    usbHostState->itdCount++;
    /* Exit critical */
    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}
#endif
static void USB_HostOhciLinkTdToDoneList(usb_host_ohci_state_struct_t *usbHostState)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *tdList;
    usb_host_ohci_general_transfer_descritpor_struct_t *tdListPos;
    tdList = (usb_host_ohci_general_transfer_descritpor_struct_t
                  *)(s_UsbHostOhciHcca[usbHostState->controllerId].HccaDoneHead & USB_HOST_OHCI_HD_MASK);

    while (NULL != tdList)
    {
        tdListPos = (usb_host_ohci_general_transfer_descritpor_struct_t *)(tdList->NextTD & USB_HOST_OHCI_HD_MASK);
        {
            if (NULL != usbHostState->tdDoneListTail)
            {
                usbHostState->tdDoneListTail->NextTD = (uint32_t)tdList;
            }
            else
            {
                usbHostState->tdDoneListHead = tdList;
            }
            usbHostState->tdDoneListTail = tdList;
        }
        tdList = tdListPos;
    }
    if (NULL != usbHostState->tdDoneListTail)
    {
        usbHostState->tdDoneListTail->NextTD = 0U;
    }
    usbHostState->writeBackCount++;
    s_UsbHostOhciHcca[usbHostState->controllerId].HccaDoneHead = 0U;
}

static usb_status_t USB_HostOhciPortChange(usb_host_ohci_state_struct_t *usbHostState)
{
    uint32_t portStatus;
    uint32_t i;
    uint32_t portCount = (usbHostState->usbRegBase->HcRhDescriptorA & USB_HOST_OHCI_RHDESCRIPTORA_NDP_MASK);

    for (i = 0U; i < portCount; i++)
    {
        portStatus = usbHostState->usbRegBase->HcRhPortStatus[i];
        if (0U != (portStatus & USB_HOST_OHCI_RHPORTSTATUS_CSC_MASK))
        {
#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
            if (kBus_OhciIdle != usbHostState->busSuspendStatus)
            {
                usb_host_instance_t *hostPointer = (usb_host_instance_t *)usbHostState->hostHandle;
                portStatus                       = usbHostState->usbRegBase->HcRhPortStatus[i];
                portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
                usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus | USB_HOST_OHCI_RHPORTSTATUS_PSSC_MASK;
                while (0U != (usbHostState->usbRegBase->HcRhPortStatus[i] & USB_HOST_OHCI_RHPORTSTATUS_PSS_MASK))
                {
                }
                portStatus = usbHostState->usbRegBase->HcControl;
                portStatus &= ~(USB_HOST_OHCI_CONTROL_HCFS_MASK | USB_HOST_OHCI_CONTROL_RWE_MASK |
                                USB_HOST_OHCI_CONTROL_RWC_MASK);
                portStatus |= USB_HOST_OHCI_CONTROL_HCFS(USB_HOST_OHCI_CONTROL_HCFS_OPERATIONAL);
                usbHostState->usbRegBase->HcControl = portStatus;
                portStatus                          = usbHostState->usbRegBase->HcRhPortStatus[i];
                portStatus &= ~(USB_HOST_OHCI_RHPORTSTATUS_WIC);
                portStatus |= USB_HOST_OHCI_RHPORTSTATUS_PES_MASK;
                usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus;
                hostPointer->suspendedDevice                = NULL;
                usbHostState->busSuspendStatus              = kBus_OhciIdle;
            }
#endif
            uint32_t sofStart = (uint32_t)s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber &
                                USB_HOST_OHCI_FMNUMBER_FN_MASK;
            uint32_t sof;
            while (1U == 1U)
            {
                portStatus = usbHostState->usbRegBase->HcRhPortStatus[i];
                if (0U != (portStatus & USB_HOST_OHCI_RHPORTSTATUS_CSC_MASK))
                {
                    portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
                    usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus | USB_HOST_OHCI_RHPORTSTATUS_CSC_MASK;
                }
                sof = (uint32_t)((uint32_t)s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber &
                                 USB_HOST_OHCI_FMNUMBER_FN_MASK);
                if ((((sof + USB_HOST_OHCI_FMNUMBER_FN_MASK + 1U) - sofStart) & USB_HOST_OHCI_FMNUMBER_FN_MASK) > 1U)
                {
                    break;
                }
            }
        }

        portStatus = usbHostState->usbRegBase->HcRhPortStatus[i];

        if (0U != (portStatus & USB_HOST_OHCI_RHPORTSTATUS_CCS_MASK))
        {
            uint32_t index;
            if (((uint8_t)kUSB_DeviceOhciPortDetached) != usbHostState->portState[i].portStatus)
            {
#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
                if ((kBus_OhciSuspended == usbHostState->busSuspendStatus) ||
                    (kBus_OhciStartResume == usbHostState->busSuspendStatus))
                {
                    if (0U != (portStatus & USB_HOST_OHCI_RHPORTSTATUS_PSSC_MASK))
                    {
                        usb_host_instance_t *hostPointer = (usb_host_instance_t *)usbHostState->hostHandle;
                        usbHostState->busSuspendStatus   = kBus_OhciStartResume;
                        /* call host callback function, function is initialized in USB_HostInit */
                        (void)hostPointer->deviceCallback(hostPointer->suspendedDevice, NULL,
                                                          kUSB_HostEventDetectResume); /* call host callback function */
                        portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
                        usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus | USB_HOST_OHCI_RHPORTSTATUS_PSSC_MASK;
                        while (0U !=
                               (usbHostState->usbRegBase->HcRhPortStatus[i] & USB_HOST_OHCI_RHPORTSTATUS_PSS_MASK))
                        {
                        }
                        portStatus = usbHostState->usbRegBase->HcControl;
                        portStatus &= ~(USB_HOST_OHCI_CONTROL_HCFS_MASK | USB_HOST_OHCI_CONTROL_RWE_MASK |
                                        USB_HOST_OHCI_CONTROL_RWC_MASK);
                        portStatus |= USB_HOST_OHCI_CONTROL_HCFS(USB_HOST_OHCI_CONTROL_HCFS_OPERATIONAL);
                        usbHostState->usbRegBase->HcControl = portStatus;
                        portStatus                          = usbHostState->usbRegBase->HcRhPortStatus[i];
                        portStatus &= ~(USB_HOST_OHCI_RHPORTSTATUS_WIC);
                        portStatus |= USB_HOST_OHCI_RHPORTSTATUS_PES_MASK;
                        usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus;
                        /* call host callback function, function is initialized in USB_HostInit */
                        (void)hostPointer->deviceCallback(hostPointer->suspendedDevice, NULL,
                                                          kUSB_HostEventResumed); /* call host callback function */
                        hostPointer->suspendedDevice   = NULL;
                        usbHostState->busSuspendStatus = kBus_OhciIdle;
                    }
                }
#endif
                break;
            }
#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
            usbHostState->busSuspendStatus = kBus_OhciIdle;
#endif
            for (index = 0U; index < USB_HOST_OHCI_PORT_CONNECT_DEBOUNCE_DELAY; index++)
            {
                (void)USB_HostOhciDelay(usbHostState, 1);
                if (0U == ((usbHostState->usbRegBase->HcRhPortStatus[i] & USB_HOST_OHCI_RHPORTSTATUS_CCS_MASK)))
                {
                    break;
                }
            }

            portStatus = usbHostState->usbRegBase->HcRhPortStatus[i];

            /* CCS is cleared ?*/
            if ((0U == ((portStatus & USB_HOST_OHCI_RHPORTSTATUS_CCS_MASK))) ||
                (index < USB_HOST_OHCI_PORT_CONNECT_DEBOUNCE_DELAY))
            {
                usbHostState->portState[i].portStatus = (uint8_t)kUSB_DeviceOhciPortDetached;
                continue;
            }

            portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
            usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus | USB_HOST_OHCI_RHPORTSTATUS_PRS_MASK;

            while (0U != (usbHostState->usbRegBase->HcRhPortStatus[i] & USB_HOST_OHCI_RHPORTSTATUS_PRS_MASK))
            {
                __NOP();
            }

            usbHostState->portState[i].portSpeed =
                (0U != (usbHostState->usbRegBase->HcRhPortStatus[i] & USB_HOST_OHCI_RHPORTSTATUS_LSDA_MASK)) ?
                    USB_SPEED_LOW :
                    USB_SPEED_FULL;
            /* do bus recovery delay */
            (void)USB_HostOhciDelay(usbHostState, USB_HOST_OHCI_PORT_RESET_RECOVERY_DELAY);
            usbHostState->portState[i].portStatus = (uint8_t)kUSB_DeviceOhciPortPhyAttached;
            (void)OSA_EventSet(usbHostState->ohciEvent, USB_HOST_OHCI_EVENT_ATTACH);
        }
        else
        {
            if ((uint8_t)kUSB_DeviceOhciPortDetached == usbHostState->portState[i].portStatus)
            {
                continue;
            }
#if ((defined(USB_HOST_CONFIG_LOW_POWER_MODE)) && (USB_HOST_CONFIG_LOW_POWER_MODE > 0U))
            usbHostState->busSuspendStatus = kBus_OhciIdle;
#endif
            usbHostState->portState[i].portStatus = (uint8_t)kUSB_DeviceOhciPortPhyDetached;
            (void)OSA_EventSet(usbHostState->ohciEvent, USB_HOST_OHCI_EVENT_DETACH);
        }
    }
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciFindStartFrame(usb_host_ohci_state_struct_t *usbHostState,
                                               usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_pipe_struct_t *p;
    uint32_t startFrame;
    uint32_t frame;
    uint32_t total = 0U;
    void *temp;

    pipe->startFrame = 0U;

    if (NULL == usbHostState->pipeListInUsing)
    {
        return kStatus_USB_Success;
    }

    for (startFrame = 0U; startFrame < pipe->pipeCommon.interval; startFrame++)
    {
        for (frame = startFrame; frame < USB_HOST_OHCI_HCCA_SIZE; frame++)
        {
            total = 0U;
            temp  = (void *)usbHostState->pipeListInUsing;
            while (NULL != temp)
            {
                p    = (usb_host_ohci_pipe_struct_t *)temp;
                temp = (void *)p->pipeCommon.next;
                if ((frame >= p->startFrame) && (0U == ((frame - p->startFrame) % p->pipeCommon.interval)))
                {
                    total += p->busTime;
                }
            }
            if ((float)total > USB_HOST_OHCI_PERIODIC_BANDWIDTH)
            {
                break;
            }
        }
        if (frame >= USB_HOST_OHCI_HCCA_SIZE)
        {
            pipe->startFrame = (uint16_t)startFrame;
            return kStatus_USB_Success;
        }
    }
    return kStatus_USB_BandwidthFail;
}

static usb_status_t USB_HostOhciAddToPeriodicList(usb_host_ohci_state_struct_t *usbHostState,
                                                  usb_host_ohci_pipe_struct_t *pipe)
{
    uint32_t i;
    uint32_t dummy = (uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_PERIODIC_ED_DUMMY];
    usb_host_ohci_endpoint_descritpor_struct_t *ed;
    usb_host_ohci_endpoint_descritpor_struct_t *pre;

    for (i = pipe->startFrame; i < USB_HOST_OHCI_HCCA_SIZE; i += pipe->pipeCommon.interval)
    {
        ed = (usb_host_ohci_endpoint_descritpor_struct_t *)s_UsbHostOhciHcca[usbHostState->controllerId]
                 .HccaInterrruptTable[i];
        pre = ed;

        while (NULL != pre)
        {
            if (pre == pipe->ed)
            {
                break;
            }
            pre = (usb_host_ohci_endpoint_descritpor_struct_t *)pre->NextED;
        }

        if (NULL != pre)
        {
            continue;
        }

        pre = NULL;
        while (dummy != (uint32_t)ed)
        {
            if (ed->pipe->pipeCommon.interval <= pipe->pipeCommon.interval)
            {
                if ((USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType) && (dummy != (uint32_t)ed))
                {
                }
                else
                {
                    break;
                }
            }
            pre = ed;
            ed  = (usb_host_ohci_endpoint_descritpor_struct_t *)ed->NextED;
        }
        pipe->ed->NextED = (uint32_t)ed;
        if (NULL != pre)
        {
            pre->NextED = (uint32_t)pipe->ed;
        }
        else
        {
            s_UsbHostOhciHcca[usbHostState->controllerId].HccaInterrruptTable[i] = (uint32_t)pipe->ed;
        }
    }
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciOpenControlBulkPipe(usb_host_ohci_state_struct_t *usbHostState,
                                                    usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
    usb_status_t error;

    error = USB_HostOhciGetGtd(usbHostState, &gtd, 1);
    if (kStatus_USB_Success != error)
    {
        return error;
    }

    gtd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    gtd->stateUnion.stateBitField.R  = 1U;

    pipe->ed->TailP = (uint32_t)gtd;
    pipe->ed->HeadP = (uint32_t)gtd;
    if (USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType)
    {
        pipe->ed->NextED = s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_CONTROL_ED_DUMMY].NextED;
        s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_CONTROL_ED_DUMMY].NextED = (uint32_t)pipe->ed;
        usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_CLE_MASK;
    }
    else
    {
        pipe->ed->NextED = s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_BULK_ED_DUMMY].NextED;
        s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_BULK_ED_DUMMY].NextED = (uint32_t)pipe->ed;
        usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_BLE_MASK;
    }

    return kStatus_USB_Success;
}

static uint8_t USB_HostOhciGetDeviceInfo(usb_device_handle deviceHandle, uint32_t infoCode)
{
    uint32_t info_val = 0U;

    (void)USB_HostHelperGetPeripheralInformation(deviceHandle, (uint32_t)infoCode, &info_val);
    return (uint8_t)info_val;
}

#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
static usb_status_t USB_HostOhciOpenIsoPipe(usb_host_ohci_state_struct_t *usbHostState,
                                            usb_host_ohci_pipe_struct_t *pipe)
{
#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd;
#endif
    usb_status_t error;
    OSA_SR_ALLOC();

    pipe->busTime = (uint16_t)USB_HostOhciBusTime(
        USB_HostOhciGetDeviceInfo(pipe->pipeCommon.deviceHandle, kUSB_HostGetDeviceSpeed), pipe->pipeCommon.pipeType,
        pipe->pipeCommon.direction,
        ((uint32_t)pipe->pipeCommon.maxPacketSize) * ((uint32_t)pipe->pipeCommon.numberPerUframe));

    OSA_ENTER_CRITICAL();
    error = USB_HostOhciFindStartFrame(usbHostState, pipe);
    if (kStatus_USB_Success != error)
    {
        OSA_EXIT_CRITICAL();
        return error;
    }

#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
    error = USB_HostOhciGetItd(usbHostState, &itd, 1);
    if (kStatus_USB_Success != error)
    {
        OSA_EXIT_CRITICAL();
        return error;
    }
    itd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;

    pipe->ed->TailP = (uint32_t)itd;
    pipe->ed->HeadP = (uint32_t)itd;
#else
    pipe->ed->TailP = (uint32_t)0;
    pipe->ed->HeadP = (uint32_t)0;
#endif

    usbHostState->usbRegBase->HcControl &= ~(USB_HOST_OHCI_CONTROL_PLE_MASK | USB_HOST_OHCI_CONTROL_IE_MASK);

    (void)USB_HostOhciAddToPeriodicList(usbHostState, pipe);

    usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_PLE_MASK | USB_HOST_OHCI_CONTROL_IE_MASK;

    OSA_EXIT_CRITICAL();
    return kStatus_USB_Success;
}
#endif

static usb_status_t USB_HostOhciOpenInterruptPipe(usb_host_ohci_state_struct_t *usbHostState,
                                                  usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
    usb_status_t error;
    OSA_SR_ALLOC();

    pipe->busTime = (uint16_t)USB_HostOhciBusTime(
        USB_HostOhciGetDeviceInfo(pipe->pipeCommon.deviceHandle, kUSB_HostGetDeviceSpeed), pipe->pipeCommon.pipeType,
        pipe->pipeCommon.direction,
        ((uint32_t)pipe->pipeCommon.maxPacketSize) * ((uint32_t)pipe->pipeCommon.numberPerUframe));

    OSA_ENTER_CRITICAL();
    error = USB_HostOhciFindStartFrame(usbHostState, pipe);
    if (kStatus_USB_Success != error)
    {
        OSA_EXIT_CRITICAL();
        return error;
    }

    error = USB_HostOhciGetGtd(usbHostState, &gtd, 1);
    if (kStatus_USB_Success != error)
    {
        OSA_EXIT_CRITICAL();
        return error;
    }
    gtd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    gtd->stateUnion.stateBitField.R  = 1U;

    pipe->ed->TailP = (uint32_t)gtd;
    pipe->ed->HeadP = (uint32_t)gtd;

    (void)USB_HostOhciAddToPeriodicList(usbHostState, pipe);
    OSA_EXIT_CRITICAL();

    usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_PLE_MASK;

    return kStatus_USB_Success;
}

static void USB_HostOhciTdDoneHandle(usb_host_ohci_state_struct_t *usbHostState,
                                     usb_host_ohci_pipe_struct_t *pipe,
                                     usb_host_transfer_t *currentTr,
                                     usb_host_ohci_general_transfer_descritpor_struct_t *gtd,
                                     usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd)
{
    usb_host_transfer_t *trPos;
    usb_host_transfer_t *trPre;
    usb_host_ohci_pipe_struct_t *p;

    uint32_t startFrame;
    uint32_t currentFrame;
    uint32_t *temp;
    void *tempVoid;
#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
    uint32_t conditionCode;
#endif
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
    uint8_t reRunLabel = 0;
#endif

    pipe->isDone = 0U;
    if (NULL == currentTr)
    {
#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
        if (NULL != itd)
        {
            itd->stateUnion.state            = 0U;
            itd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
            itd->NextTD                      = 0U;
            itd->BE                          = 0U;
            itd->BP0                         = 0U;
            (void)USB_HostOhciFreeItd(usbHostState, itd);
        }
        else
#endif
        {
            gtd->stateUnion.state            = 0U;
            gtd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
            gtd->stateUnion.stateBitField.R  = 1U;
            gtd->CBP                         = 0U;
            gtd->NextTD                      = 0U;
            gtd->BE                          = 0U;
        }
        return;
    }

    if (USB_HOST_OHCI_CC_NO_ERROR != gtd->stateUnion.stateBitField.CC)
    {
        if (kStatus_USB_Success == (usb_status_t)currentTr->union2.frame)
        {
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
            uint32_t speed = USB_SPEED_FULL;
            if (pipe->pipeCommon.pipeType == USB_ENDPOINT_INTERRUPT)
            {
                (void)USB_HostHelperGetPeripheralInformation(pipe->pipeCommon.deviceHandle,
                                                             (uint32_t)kUSB_HostGetDeviceSpeed, &speed);
                if ((gtd->stateUnion.stateBitField.CC == USB_HOST_OHCI_CC_DEVICE_NOT_RESPONDING) &&
                    (speed == USB_SPEED_LOW))
                {
                    pipe->deviceNotRespondingCount++;
                    if (pipe->deviceNotRespondingCount <
                        USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND_CONSEQUENT_COUNT)
                    {
                        pipe->endpointInterval = (uint16_t)(pipe->pipeCommon.interval + 1U);
                        /* re-run the GTD */
                        reRunLabel = 1U;
                    }
                    else
                    {
                        pipe->deviceNotRespondingCount = 0U;
                        pipe->endpointInterval         = 0U;
                        currentTr->union2.frame        = (uint32_t)kStatus_USB_TransferFailed;
                    }
                }
            }
            else
            {
                currentTr->union2.frame = (uint32_t)kStatus_USB_TransferFailed;
            }
#else
            currentTr->union2.frame = (uint32_t)kStatus_USB_TransferFailed;
#endif
        }

        if (USB_HOST_OHCI_CC_STALL == gtd->stateUnion.stateBitField.CC)
        {
            currentTr->union2.frame = (uint32_t)kStatus_USB_TransferStall;
        }
        pipe->ed->HeadP &= ~USB_HOST_OHCI_ED_HEADP_HALT_MASK;
    }

#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
    if (NULL != itd)
    {
        usb_host_ohci_isochronous_transfer_descritpor_struct_t *itdP;
        usb_host_ohci_isochronous_transfer_descritpor_struct_t *itdQ = NULL;
        itdP = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)currentTr->union1.unitHead;

        while (NULL != itdP)
        {
            if (itd == itdP)
            {
                if (NULL != itdQ)
                {
                    itdQ->nextItd = itdP->nextItd;
                }
                else
                {
                    currentTr->union1.unitHead = (uint32_t)itdP->nextItd;
                }
                break;
            }
            itdQ = itdP;
            itdP = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)itdP->nextItd;
        }
        currentTr->transferSofar = 0U;
        for (uint32_t i = 0; i <= itd->stateUnion.stateBitField.FC; i++)
        {
            currentTr->transferSofar += ((uint32_t)itd->OffsetPSW[i] & (USB_HOST_OHCI_ITD_TRANSFER_SIZE_MASK));
            conditionCode = (((uint32_t)itd->OffsetPSW[i] & (USB_HOST_OHCI_ITD_CONDITION_CODE_MASK)) >>
                             USB_HOST_OHCI_ITD_CONDITION_CODE_SHIFT);
            if (0U != conditionCode)
            {
                if (conditionCode != USB_HOST_OHCI_CC_DATA_UNDERRUN)
                {
                    if (kStatus_USB_Success == (usb_status_t)currentTr->union2.frame)
                    {
                        if (conditionCode == USB_HOST_OHCI_CC_DATA_OVERRUN)
                        {
                            currentTr->union2.frame = (uint32_t)kStatus_USB_DataOverRun;
                        }
                        else
                        {
                            currentTr->union2.frame = (uint32_t)kStatus_USB_Error;
                        }
                    }
                }
            }
        }
        if (currentTr->direction == USB_OUT)
        {
            currentTr->transferSofar = currentTr->transferLength - currentTr->transferSofar;
        }
        (void)USB_HostOhciFreeItd(usbHostState, itd);
    }
    else
#endif
    {
        usb_host_ohci_general_transfer_descritpor_struct_t *gtdP;
        usb_host_ohci_general_transfer_descritpor_struct_t *gtdQ = NULL;

        gtdP = (usb_host_ohci_general_transfer_descritpor_struct_t *)currentTr->union1.unitHead;
        while (NULL != gtdP)
        {
            if (gtd == gtdP)
            {
                if (NULL != gtdQ)
                {
                    gtdQ->nextGtd = gtdP->nextGtd;
                }
                else
                {
                    uint32_t tail              = pipe->ed->TailP & USB_HOST_OHCI_ED_TAILP_MASK;
                    uint32_t head              = pipe->ed->HeadP & USB_HOST_OHCI_ED_HEADP_MASK;
                    currentTr->union1.unitHead = (uint32_t)gtdP->nextGtd;
                    if (head != tail)
                    {
                        pipe->ed->HeadP &= ~USB_HOST_OHCI_ED_HEADP_MASK;
                        pipe->ed->HeadP |= (uint32_t)gtdP->NextTD;
                    }
                }
                break;
            }
            gtdQ = gtdP;
            gtdP = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtdP->nextGtd;
        }
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
        if (0U == reRunLabel)
#endif
        {
            if ((0U != gtd->CBP) && (USB_HOST_OHCI_GTD_DP_SETUP != gtd->stateUnion.stateBitField.DP))
            {
                currentTr->transferLength -= ((0U != (((gtd->BE) ^ (gtd->CBP)) & 0xFFFFF000U)) ? 0x00001000U : 0U) +
                                             ((gtd->BE) & 0x00000FFFU) - ((gtd->CBP) & 0x00000FFFU) + 1U;
            }
            currentTr->transferSofar = currentTr->transferLength;
        }
        (void)USB_HostOhciFreeGtd(usbHostState, gtd);
    }

    temp = (uint32_t *)(currentTr->union1.unitHead);
    if (NULL == (void *)(temp))
    {
        if ((0U == pipe->isCanceling) && ((uint32_t)kStatus_USB_Success == currentTr->union2.frame))
        {
            if (USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType)
            {
                if (NULL != pipe->ed->trListHead)
                {
                    if (kStatus_USB_Success == USB_HostOhciLinkGtdControlTr(usbHostState, pipe, pipe->ed->trListHead))
                    {
                        /*no action, added for misra4.7*/
                    }
                    else
                    {
                        /*no action*/
                    }
                }
            }
        }
    }
    temp = (uint32_t *)(currentTr->union1.unitHead);
    if (NULL == (void *)(temp))
    {
        uint8_t trIsFound = 0;
        trPre             = NULL;
        trPos             = pipe->ed->trListHead;

        while (NULL != trPos)
        {
            if (currentTr == trPos)
            {
                if (NULL == trPre)
                {
                    pipe->ed->trListHead = trPos->next;
                }
                else
                {
                    trPre->next = trPos->next;
                }
                trIsFound = 1;
                break;
            }
            trPre = trPos;
            trPos = trPos->next;
        }
        if (NULL == pipe->ed->trListHead)
        {
            pipe->ed->trListTail = NULL;
        }

        if (0U != trIsFound)
        {
            pipe->cutOffTime = USB_HOST_OHCI_TRANSFER_TIMEOUT_GAP;

            if ((kStatus_USB_Success == ((usb_status_t)currentTr->union2.frame)) &&
                (USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType) &&
                (USB_REQUEST_STANDARD_CLEAR_FEATURE == currentTr->setupPacket->bRequest) &&
                (USB_REQUEST_TYPE_RECIPIENT_ENDPOINT == currentTr->setupPacket->bmRequestType) &&
                (USB_REQUEST_STANDARD_FEATURE_SELECTOR_ENDPOINT_HALT ==
                 (USB_SHORT_FROM_LITTLE_ENDIAN(currentTr->setupPacket->wValue) & 0x00FFU)))
            {
                p = usbHostState->pipeListInUsing;
                while (p != NULL)
                {
                    /* only compute bulk and interrupt pipe */
                    if (((p->pipeCommon.endpointAddress |
                          (p->pipeCommon.direction << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT)) ==
                         ((uint8_t)(USB_SHORT_FROM_LITTLE_ENDIAN(currentTr->setupPacket->wIndex)))) &&
                        (p->pipeCommon.deviceHandle == pipe->pipeCommon.deviceHandle))
                    {
                        break;
                    }
                    tempVoid = (void *)p->pipeCommon.next;
                    p        = (usb_host_ohci_pipe_struct_t *)tempVoid;
                }

                if ((NULL != p) && ((p->pipeCommon.pipeType == USB_ENDPOINT_INTERRUPT) ||
                                    (p->pipeCommon.pipeType == USB_ENDPOINT_BULK)))
                {
                    p->ed->stateUnion.stateBitField.K = 1U;
                    startFrame                        = s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber;
                    currentFrame                      = startFrame;

                    while (currentFrame == startFrame)
                    {
                        currentFrame = s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber;
                    }

                    p->ed->HeadP &= ~USB_HOST_OHCI_ED_HEADP_CARRY_MASK;

                    p->ed->stateUnion.stateBitField.K = 0U;
                }
            }

#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
            if (0U != reRunLabel)
            {
                (void)USB_HostOhciWritePipe(usbHostState, pipe, currentTr);
            }
            else
#endif
            {
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
                pipe->deviceNotRespondingCount = 0U;
                pipe->endpointInterval         = 0U;
#endif
                currentTr->callbackFn(currentTr->callbackParam, currentTr,
                                      (usb_status_t)currentTr->union2.frame); /* transfer callback */
            }
            if (USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType)
            {
                usbHostState->controlIsBusy = 0U;
            }
            pipe->isBusy = 0U;
        }
        else
        {
        }

        if (0U == usbHostState->controlIsBusy)
        {
            p = usbHostState->pipeListInUsing;

            while (NULL != p)
            {
                if (USB_ENDPOINT_CONTROL == p->pipeCommon.pipeType)
                {
                    if (NULL != p->ed->trListHead)
                    {
                        /* initialize gtd for control/bulk/interrupt transfer */
                        if (kStatus_USB_Success == USB_HostOhciLinkGtdControlTr(usbHostState, p, p->ed->trListHead))
                        {
                            usbHostState->controlIsBusy = 1U;
                            break;
                        }
                        else
                        {
                            /*fixed misra directive 4.7*/
                        }
                    }
                }
                tempVoid = (void *)p->pipeCommon.next;
                p        = (usb_host_ohci_pipe_struct_t *)tempVoid;
            }
        }

        if (NULL != pipe->ed->trListHead)
        {
            switch (pipe->pipeCommon.pipeType)
            {
                case USB_ENDPOINT_CONTROL:
                    break;
                case USB_ENDPOINT_BULK:
                case USB_ENDPOINT_INTERRUPT:
                    /* initialize gtd for control/bulk/interrupt transfer */
                    if (kStatus_USB_Success != USB_HostOhciLinkGtdTr(usbHostState, pipe, pipe->ed->trListHead))
                    {
                        /*for misra 4.7, no meaning */
                    }
                    else
                    {
                        /*for misra 4.7*/
                    }
                    break;
#if ((defined USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD))
                case USB_ENDPOINT_ISOCHRONOUS:
                    /* initialize itd for iso transfer */
                    /* USB_HostOhciLinkItdTr(usbHostState, pipe, pipe->ed->trListHead); */
                    break;
#endif
                default:
                    /*no action*/
                    break;
            }
        }
    }
}

static usb_status_t USB_HostOhciCancelPipe(usb_host_ohci_state_struct_t *usbHostState,
                                           usb_host_ohci_pipe_struct_t *pipe,
                                           usb_host_transfer_t *tr)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
    usb_host_ohci_general_transfer_descritpor_struct_t *gtdPre;
    usb_host_ohci_general_transfer_descritpor_struct_t *gtdPos;
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd;
    usb_host_ohci_pipe_struct_t *currentPipe;
    usb_host_transfer_t *trCurrent;
    usb_host_transfer_t *trPos;
    usb_host_transfer_t *trPre;
    uint32_t startFrame;
    uint32_t currentFrame;
    void *temp;
    pipe->ed->stateUnion.stateBitField.K = 1U;
    startFrame                           = s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber;
    currentFrame                         = startFrame;

    while (currentFrame == startFrame)
    {
        currentFrame = s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber;
    }

    USB_HostOhciLock();
    USB_HostOhciDisableIsr(usbHostState);
    pipe->isCanceling = 1U;
    pipe->ed->HeadP &= ~USB_HOST_OHCI_ED_HEADP_MASK;
    pipe->ed->HeadP |= pipe->ed->TailP;
    /* Fetch the td from token done list */
    gtd    = (usb_host_ohci_general_transfer_descritpor_struct_t *)((uint32_t)usbHostState->tdDoneListHead);
    gtdPre = NULL;
    while (NULL != gtd)
    {
        if (((uint32_t)gtd) < ((uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].gtd[0]))
        {
            temp        = (void *)gtd;
            itd         = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)temp;
            trCurrent   = itd->tr;
            currentPipe = itd->pipe;
        }
        else
        {
            itd         = NULL;
            trCurrent   = gtd->tr;
            currentPipe = gtd->pipe;
        }
        if (pipe == currentPipe)
        {
            if ((NULL == tr) || (tr == trCurrent))
            {
                gtdPos = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtd->NextTD;
                USB_HostOhciTdDoneHandle(usbHostState, pipe, trCurrent, gtd, itd);
                if (NULL == gtdPre)
                {
                    usbHostState->tdDoneListHead = gtdPos;
                }
                else
                {
                    gtdPre->NextTD = (uint32_t)gtdPos;
                }
                gtd = gtdPos;
                continue;
            }
        }
        gtdPre = gtd;
        gtd    = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtd->NextTD;
    }

    trPre     = NULL;
    trCurrent = pipe->ed->trListHead;

    while (NULL != trCurrent)
    {
        trPos = trCurrent->next;
        if ((NULL == tr) || (tr == trCurrent))
        {
            if (0UL != trCurrent->union1.unitHead)
            {
                gtd = (usb_host_ohci_general_transfer_descritpor_struct_t *)trCurrent->union1.unitHead;
                while (NULL != gtd)
                {
                    if (USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType)
                    {
                        temp   = (void *)gtd;
                        itd    = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)temp;
                        temp   = (void *)itd->nextItd;
                        gtdPos = (usb_host_ohci_general_transfer_descritpor_struct_t *)temp;
                    }
                    else
                    {
                        itd    = NULL;
                        gtdPos = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtd->nextGtd;
                    }
                    USB_HostOhciTdDoneHandle(usbHostState, pipe, trCurrent, gtd, itd);
                    gtd = gtdPos;
                }
            }
            else
            {
                pipe->cutOffTime = USB_HOST_OHCI_TRANSFER_TIMEOUT_GAP;

#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
                pipe->deviceNotRespondingCount = 0U;
                pipe->endpointInterval         = 0U;
#endif
                trCurrent->callbackFn(trCurrent->callbackParam, trCurrent,
                                      kStatus_USB_TransferCancel); /* transfer callback */

                pipe->isBusy = 0U;

                if (NULL == trPre)
                {
                    pipe->ed->trListHead = trPos;
                }
                else
                {
                    trPre->next = trPos;
                }
            }
        }
        else
        {
            trPre = trCurrent;
        }
        trCurrent = trPos;
    }
    if (NULL == pipe->ed->trListHead)
    {
        pipe->ed->trListTail = NULL;
    }
    pipe->isCanceling = 0U;
    USB_HostOhciEnableIsr(usbHostState);
    USB_HostOhciUnlock();
    pipe->ed->stateUnion.stateBitField.K = 0U;

    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciRemoveFromPeriodicList(usb_host_ohci_state_struct_t *usbHostState,
                                                       usb_host_ohci_pipe_struct_t *pipe)
{
    uint32_t i;
    usb_host_ohci_endpoint_descritpor_struct_t *ed;
    usb_host_ohci_endpoint_descritpor_struct_t *pre;

    for (i = pipe->startFrame; i < USB_HOST_OHCI_HCCA_SIZE; i += pipe->pipeCommon.interval)
    {
        pre = NULL;
        ed  = (usb_host_ohci_endpoint_descritpor_struct_t *)s_UsbHostOhciHcca[usbHostState->controllerId]
                 .HccaInterrruptTable[i];

        while (NULL != ed)
        {
            if (ed == pipe->ed)
            {
                if (NULL == pre)
                {
                    s_UsbHostOhciHcca[usbHostState->controllerId].HccaInterrruptTable[i] = ed->NextED;
                }
                else
                {
                    pre->NextED = ed->NextED;
                }
                break;
            }
            pre = ed;
            ed  = (usb_host_ohci_endpoint_descritpor_struct_t *)ed->NextED;
        }
    }
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciCloseControlBulkPipe(usb_host_ohci_state_struct_t *usbHostState,
                                                     usb_host_ohci_pipe_struct_t *pipe)
{
    usb_host_ohci_endpoint_descritpor_struct_t *edHead;
    usb_host_ohci_endpoint_descritpor_struct_t *preEdHead;

    (void)USB_HostOhciCancelPipe(usbHostState, pipe, NULL);

    pipe->ed->stateUnion.stateBitField.K = 1U;

    if (USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType)
    {
        edHead = &s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_CONTROL_ED_DUMMY];
    }
    else
    {
        edHead = &s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_BULK_ED_DUMMY];
    }

    (void)USB_HostOhciFreeGtd(
        usbHostState,
        (usb_host_ohci_general_transfer_descritpor_struct_t *)(pipe->ed->TailP & USB_HOST_OHCI_ED_HEADP_MASK));

    preEdHead = NULL;
    while ((NULL != edHead) && (edHead != pipe->ed))
    {
        preEdHead = edHead;
        edHead    = (usb_host_ohci_endpoint_descritpor_struct_t *)edHead->NextED;
    }

    if ((NULL != preEdHead) && (NULL != edHead))
    {
        preEdHead->NextED = edHead->NextED;
    }

    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciCloseIsoInterruptPipe(usb_host_ohci_state_struct_t *usbHostState,
                                                      usb_host_ohci_pipe_struct_t *pipe)
{
    (void)USB_HostOhciCancelPipe(usbHostState, pipe, NULL);

    pipe->ed->stateUnion.stateBitField.K = 1U;
    if (USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType)
    {
#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
        (void)USB_HostOhciFreeItd(
            usbHostState,
            (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)(pipe->ed->TailP & USB_HOST_OHCI_ED_HEADP_MASK));
#endif
    }
    else
    {
        (void)USB_HostOhciFreeGtd(
            usbHostState,
            (usb_host_ohci_general_transfer_descritpor_struct_t *)(pipe->ed->TailP & USB_HOST_OHCI_ED_HEADP_MASK));
    }

    (void)USB_HostOhciRemoveFromPeriodicList(usbHostState, pipe);

    return kStatus_USB_Success;
}

static void USB_HostOhciFillGtd(usb_host_ohci_pipe_struct_t *pipe,
                                usb_host_transfer_t *tr,
                                usb_host_ohci_general_transfer_descritpor_struct_t *gtd,
                                uint8_t *buffer,
                                uint32_t length,
                                uint8_t dirPid,
                                uint8_t dataToggle,
                                uint8_t ioc)
{
    gtd->CBP                         = (uint32_t)buffer;
    gtd->BE                          = (0U != length) ? (gtd->CBP + length - 1U) : 0U;
    gtd->pipe                        = pipe;
    gtd->tr                          = tr;
    gtd->stateUnion.stateBitField.R  = 1U;
    gtd->stateUnion.stateBitField.DP = dirPid;
    gtd->stateUnion.stateBitField.DI = (0U != ioc) ? 0U : USB_HOST_OHCI_GTD_DI_NO_INTERRUPT;
    gtd->stateUnion.stateBitField.T  = dataToggle;
    gtd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    gtd->length                      = length;
}

static usb_status_t USB_HostOhciLinkGtdControlTr(usb_host_ohci_state_struct_t *usbHostState,
                                                 usb_host_ohci_pipe_struct_t *pipe,
                                                 usb_host_transfer_t *tr)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *head;
    usb_host_ohci_general_transfer_descritpor_struct_t *p = NULL;
    void *temp;
    uint8_t dirPid   = USB_HOST_OHCI_GTD_DP_SETUP;
    uint8_t statePid = 0U;
    usb_host_ohci_transfer_status_t transferStaus;
    usb_status_t status;
    OSA_SR_ALLOC();

    OSA_ENTER_CRITICAL();
    if ((0U != pipe->isBusy) && (kStatus_UsbHostOhci_Idle == (usb_host_ohci_transfer_status_t)tr->setupStatus))
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Success;
    }
    pipe->isBusy = 1;
    pipe->isDone = 0U;
    OSA_EXIT_CRITICAL();

    transferStaus = (usb_host_ohci_transfer_status_t)tr->setupStatus;
    switch (transferStaus)
    {
        case kStatus_UsbHostOhci_Idle:
            status = USB_HostOhciGetGtd(usbHostState, &p, 1);
            if (kStatus_USB_Success != status)
            {
                OSA_ENTER_CRITICAL();
                pipe->isBusy = 0;
                OSA_EXIT_CRITICAL();
                return status;
            }
            head                = (usb_host_ohci_general_transfer_descritpor_struct_t *)pipe->ed->TailP;
            head->NextTD        = (uint32_t)p;
            p                   = head;
            tr->union1.unitHead = (uint32_t)p;
            USB_HostOhciFillGtd(pipe, tr, p, (uint8_t *)tr->setupPacket, 8U, USB_HOST_OHCI_GTD_DP_SETUP, 0x02U, 0U);
            if (0U != tr->transferLength)
            {
                tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_Setup;
            }
            else
            {
                tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_Data;
            }
            status = kStatus_USB_Success;
            break;
        case kStatus_UsbHostOhci_Setup:
            status = USB_HostOhciGetGtd(usbHostState, &p, 1);
            if (kStatus_USB_Success != status)
            {
                OSA_ENTER_CRITICAL();
                pipe->isBusy = 0;
                OSA_EXIT_CRITICAL();
                return status;
            }

            head                = (usb_host_ohci_general_transfer_descritpor_struct_t *)pipe->ed->TailP;
            head->NextTD        = (uint32_t)p;
            p                   = head;
            tr->union1.unitHead = (uint32_t)p;
            dirPid              = (tr->direction == USB_OUT) ? USB_HOST_OHCI_GTD_DP_OUT : USB_HOST_OHCI_GTD_DP_IN;
            USB_HostOhciFillGtd(pipe, tr, p, (uint8_t *)tr->transferBuffer, tr->transferLength, dirPid, 0x03U, 1U);
            tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_Data;
            status          = kStatus_USB_Success;
            break;
        case kStatus_UsbHostOhci_Data:
            status = USB_HostOhciGetGtd(usbHostState, &p, 1);
            if (kStatus_USB_Success != status)
            {
                OSA_ENTER_CRITICAL();
                pipe->isBusy = 0;
                OSA_EXIT_CRITICAL();
                return status;
            }
            head                = (usb_host_ohci_general_transfer_descritpor_struct_t *)pipe->ed->TailP;
            head->NextTD        = (uint32_t)p;
            p                   = head;
            tr->union1.unitHead = (uint32_t)p;
            if (tr->setupPacket->wLength > 0u)
            {
                statePid = (tr->direction == USB_OUT) ? USB_HOST_OHCI_GTD_DP_IN : USB_HOST_OHCI_GTD_DP_OUT;
            }
            else
            {
                statePid = USB_HOST_OHCI_GTD_DP_IN;
            }
            USB_HostOhciFillGtd(pipe, tr, p, NULL, 0U, statePid, 0x03, 1U);
            tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_State;
            status          = kStatus_USB_Success;
            break;
        case kStatus_UsbHostOhci_State:
            tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_Idle;
            status          = kStatus_USB_Success;
            break;
        default:
            OSA_ENTER_CRITICAL();
            pipe->isBusy = 0;
            OSA_EXIT_CRITICAL();
            tr->setupStatus = (uint8_t)kStatus_UsbHostOhci_Idle;
            status          = kStatus_USB_Success;
            break;
    }

    if (0U == pipe->isBusy)
    {
        return kStatus_USB_Error;
    }

    if (NULL != p)
    {
        p->stateUnion.stateBitField.DI = 0U;
        p->nextGtd                     = NULL;
        p                              = (usb_host_ohci_general_transfer_descritpor_struct_t *)p->NextTD;
        p->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
        p->stateUnion.stateBitField.R  = 1U;
        p->pipe                        = pipe;
        temp                           = (void *)pipe;
        tr->transferPipe               = (usb_host_pipe_t *)temp;
        pipe->ed->TailP                = (uint32_t)p;

        usbHostState->usbRegBase->HcCommandStatus |= USB_HOST_OHCI_COMMAND_STATUS_CLF_MASK;
    }
    return status;
}

static usb_status_t USB_HostOhciLinkGtdTr(usb_host_ohci_state_struct_t *usbHostState,
                                          usb_host_ohci_pipe_struct_t *pipe,
                                          usb_host_transfer_t *tr)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *head;
    usb_host_ohci_general_transfer_descritpor_struct_t *p;
    uint32_t remainingLength = tr->transferLength;
    uint32_t tdCount         = 0U;
    uint32_t tdLength        = 0U;
    uint32_t bufferAddress   = (uint32_t)tr->transferBuffer;
    void *temp;
    usb_status_t status;
    uint8_t dirPid;

    OSA_SR_ALLOC();

    OSA_ENTER_CRITICAL();
    if (0U != pipe->isBusy)
    {
        OSA_EXIT_CRITICAL();
        return kStatus_USB_Success;
    }
    pipe->isBusy = 1U;
    pipe->isDone = 0U;
    OSA_EXIT_CRITICAL();

    while (0U != remainingLength)
    {
        tdLength = USB_HOST_OHCI_GTD_MAX_LENGTH - (bufferAddress & USB_HOST_OHCI_GTD_BUFFER_ALIGN_MASK);
        if (tdLength < remainingLength)
        {
            tdLength -= tdLength % pipe->pipeCommon.maxPacketSize;
        }
        else
        {
            tdLength = remainingLength;
        }
        remainingLength -= tdLength;
        bufferAddress += tdLength;
        tdCount++;
    }

    if (0U == tdCount)
    {
        tdCount = 1U;
    }

    status = USB_HostOhciGetGtd(usbHostState, &p, tdCount);
    if (kStatus_USB_Success != status)
    {
        OSA_ENTER_CRITICAL();
        pipe->isBusy = 0;
        OSA_EXIT_CRITICAL();
        return status;
    }

    head                = (usb_host_ohci_general_transfer_descritpor_struct_t *)pipe->ed->TailP;
    head->NextTD        = (uint32_t)p;
    p                   = head;
    tr->union1.unitHead = (uint32_t)p;
    dirPid              = (tr->direction == USB_OUT) ? USB_HOST_OHCI_GTD_DP_OUT : USB_HOST_OHCI_GTD_DP_IN;

    remainingLength = tr->transferLength;
    bufferAddress   = (uint32_t)tr->transferBuffer;

    while (0U != remainingLength)
    {
        tdLength = USB_HOST_OHCI_GTD_MAX_LENGTH - (bufferAddress & USB_HOST_OHCI_GTD_BUFFER_ALIGN_MASK);
        if (tdLength < remainingLength)
        {
            tdLength -= tdLength % pipe->pipeCommon.maxPacketSize;
        }
        else
        {
            tdLength = remainingLength;
        }
        remainingLength -= tdLength;
        if (0U != remainingLength)
        {
            USB_HostOhciFillGtd(pipe, tr, p, (uint8_t *)bufferAddress, tdLength, dirPid, 0x00U, 0U);
            p->nextGtd = (usb_host_ohci_general_transfer_descritpor_struct_t *)p->NextTD;
            p          = (usb_host_ohci_general_transfer_descritpor_struct_t *)p->NextTD;
        }
        else
        {
            USB_HostOhciFillGtd(pipe, tr, p, (uint8_t *)bufferAddress, tdLength, dirPid, 0x00U, 1U);
        }
        bufferAddress += tdLength;
    }

    if (0U == tr->transferLength)
    {
        USB_HostOhciFillGtd(pipe, tr, p, NULL, 0U, dirPid, 0x00U, 1U);
    }
    p->stateUnion.stateBitField.DI = 0U;
    p->nextGtd                     = NULL;
    p                              = (usb_host_ohci_general_transfer_descritpor_struct_t *)p->NextTD;
    p->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    p->stateUnion.stateBitField.R  = 1U;
    p->pipe                        = pipe;
    temp                           = (void *)pipe;
    tr->transferPipe               = (usb_host_pipe_t *)temp;
    pipe->ed->TailP                = (uint32_t)p;

    if (USB_ENDPOINT_BULK == pipe->pipeCommon.pipeType)
    {
        usbHostState->usbRegBase->HcCommandStatus |= USB_HOST_OHCI_COMMAND_STATUS_BLF_MASK;
    }
    else
    {
    }
    return status;
}

#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
static void USB_HostOhciFillItd(usb_host_ohci_pipe_struct_t *pipe,
                                usb_host_transfer_t *tr,
                                usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd,
                                uint8_t *buffer,
                                uint32_t length,
                                uint32_t startFrame)
{
    itd->BP0                         = ((uint32_t)buffer) & USB_HOST_OHCI_ITD_BP0_MASK;
    itd->BE                          = (0U != length) ? (((uint32_t)buffer) + length - 1U) : 0U;
    itd->stateUnion.stateBitField.SF = startFrame & USB_HOST_OHCI_FMNUMBER_FN_MASK;
    itd->stateUnion.stateBitField.DI = 0U;
    itd->stateUnion.stateBitField.FC = (length - 1U) / pipe->pipeCommon.maxPacketSize;
    itd->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    itd->pipe                        = pipe;
    itd->tr                          = tr;
    for (uint32_t i = 0; i < 8U; i++)
    {
        itd->OffsetPSW[i] = (uint16_t)((((uint32_t)buffer + (i * pipe->pipeCommon.maxPacketSize)) & 0xFFFU) |
                                       ((uint32_t)USB_HOST_OHCI_CC_NOT_ACCESSED << 12U));
        if ((((uint32_t)buffer + (i * pipe->pipeCommon.maxPacketSize)) & USB_HOST_OHCI_ITD_BP0_MASK) != itd->BP0)
        {
            itd->OffsetPSW[i] |= (uint16_t)1UL << 11U;
        }
    }
    itd->length = length;
}

static usb_status_t USB_HostOhciLinkItdTr(usb_host_ohci_state_struct_t *usbHostState,
                                          usb_host_ohci_pipe_struct_t *pipe,
                                          usb_host_transfer_t *tr)
{
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *head;
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *p;
    uint32_t remainingLength = tr->transferLength;
    uint32_t tdCount         = 0U;
    uint32_t tdLength        = 0U;
    uint32_t bufferAddress   = (uint32_t)tr->transferBuffer;
    uint32_t startFrame;
    uint32_t currentFrame;
    void *temp;
    usb_status_t status;
    uint8_t tansaction = 1U;

    if (0U == remainingLength)
    {
        return kStatus_USB_Success;
    }

    pipe->isDone = 0U;

    tdCount = ((remainingLength - 1U) / (pipe->pipeCommon.maxPacketSize)) + 1U;
    if (1U == pipe->pipeCommon.interval)
    {
        tdCount = ((tdCount - 1U) >> 3U) + 1U;
#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
#else
        tdCount++;
#endif
        tansaction = 8U;
    }
    status = USB_HostOhciGetItd(usbHostState, &p, tdCount);
    if (kStatus_USB_Success != status)
    {
        return status;
    }

#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
    head         = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)pipe->ed->TailP;
    head->NextTD = (uint32_t)p;
    p            = head;
#else
    head = p;
#endif
    tr->union1.unitHead = (uint32_t)p;

    currentFrame = s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber;
    startFrame   = currentFrame;

    while (0U != remainingLength)
    {
        tdLength = ((uint32_t)pipe->pipeCommon.maxPacketSize) * ((uint32_t)tansaction);
        if (tdLength > remainingLength)
        {
            tdLength = remainingLength;
        }
        USB_HostOhciFillItd(pipe, tr, p, (uint8_t *)bufferAddress, tdLength, startFrame);
        remainingLength -= tdLength;
        if (0U != remainingLength)
        {
            p->nextItd = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)p->NextTD;
            p          = p->nextItd;
            startFrame += ((uint32_t)tansaction) * ((uint32_t)pipe->pipeCommon.interval);
        }
        bufferAddress += tdLength;
    }
    p->nextItd                     = NULL;
    p                              = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)p->NextTD;
    p->stateUnion.stateBitField.CC = USB_HOST_OHCI_CC_NOT_ACCESSED;
    p->pipe                        = pipe;
    temp                           = (void *)pipe;
    tr->transferPipe               = (usb_host_pipe_t *)temp;
    pipe->ed->HeadP &= ~USB_HOST_OHCI_ED_HEADP_MASK;
    pipe->ed->HeadP |= (uint32_t)head;
    pipe->ed->TailP = (uint32_t)p;

    return status;
}

#endif

static usb_status_t USB_HostOhciTokenDone(usb_host_ohci_state_struct_t *usbHostState)
{
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
    usb_host_ohci_general_transfer_descritpor_struct_t *gtdPos;
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd;
    usb_host_ohci_pipe_struct_t *pipe;
    usb_host_transfer_t *trCurrent;
    void *temp;

    /* Enter critical */
    USB_HostOhciLock();
    USB_HostOhciDisableIsr(usbHostState);

    gtd = (usb_host_ohci_general_transfer_descritpor_struct_t *)((uint32_t)usbHostState->tdDoneListHead);
    while (NULL != gtd)
    {
        if (((uint32_t)gtd) < ((uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].gtd[0]))
        {
            temp      = (void *)gtd;
            itd       = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)temp;
            trCurrent = itd->tr;
            pipe      = itd->pipe;
        }
        else
        {
            itd       = NULL;
            trCurrent = gtd->tr;
            pipe      = gtd->pipe;
        }

        gtdPos = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtd->NextTD;
        USB_HostOhciTdDoneHandle(usbHostState, pipe, trCurrent, gtd, itd);
        if (usbHostState->tdDoneListTail == gtd)
        {
            break;
        }
        gtd = gtdPos;
    }
    usbHostState->tdDoneListHead = NULL;
    usbHostState->tdDoneListTail = NULL;
    /* Exit critical */
    USB_HostOhciEnableIsr(usbHostState);
    USB_HostOhciUnlock();
    return kStatus_USB_Success;
}

static usb_status_t USB_HostOhciSof(usb_host_ohci_state_struct_t *usbHostState)
{
    usb_host_ohci_pipe_struct_t *pipe;
#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
#else
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
    usb_host_ohci_general_transfer_descritpor_struct_t *gtdP;
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd;
    uint32_t head;
    uint32_t tail;
#endif
    void *temp;
    /* Enter critical */
    USB_HostOhciLock();
    USB_HostOhciDisableIsr(usbHostState);
    pipe = usbHostState->pipeListInUsing;
    while (NULL != pipe)
    {
        if ((USB_ENDPOINT_CONTROL == pipe->pipeCommon.pipeType) || (USB_ENDPOINT_BULK == pipe->pipeCommon.pipeType))
        {
            if (NULL != pipe->ed->trListHead)
            {
                pipe->cutOffTime--;
                if (0U == pipe->cutOffTime)
                {
                    (void)USB_HostOhciCancelPipe(usbHostState, pipe, pipe->ed->trListHead);
                }
            }
        }
        else
        {
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
            if (USB_ENDPOINT_INTERRUPT == pipe->pipeCommon.pipeType)
            {
                if (pipe->endpointInterval != 0U)
                {
                    pipe->endpointInterval--;
                    if (pipe->endpointInterval == 0U)
                    {
                        pipe->deviceNotRespondingCount = 0U;
                    }
                }
            }
#endif
        }

#if (defined(FSL_FEATURE_USBFSH_VERSION) && (FSL_FEATURE_USBFSH_VERSION >= 200U))
#else
        tail = pipe->ed->TailP & USB_HOST_OHCI_ED_TAILP_MASK;
        head = pipe->ed->HeadP & USB_HOST_OHCI_ED_HEADP_MASK;
        if ((0U != pipe->isBusy) && (head == tail))
        {
            if ((0U != pipe->isDone) && (pipe->currentTr == pipe->ed->trListHead))
            {
                if (pipe->startWriteBackCount != usbHostState->writeBackCount)
                {
                    pipe->isDone = 0U;
                    gtd = (usb_host_ohci_general_transfer_descritpor_struct_t *)pipe->ed->trListHead->union1.unitHead;
                    while (NULL != gtd)
                    {
                        gtdP = (usb_host_ohci_general_transfer_descritpor_struct_t *)gtd->nextGtd;
                        if (USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType)
                        {
                            temp = (void *)gtd;
                            itd = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)temp;
                        }
                        else
                        {
                            itd = NULL;
                        }
                        /* usb_echo("Timeout pipe\r\n"); */
                        USB_HostOhciTdDoneHandle(usbHostState, pipe, pipe->ed->trListHead, gtd, itd);
                        gtd = gtdP;
                    }
                }
            }
            else
            {
                pipe->isDone = 1;
                pipe->currentTr = pipe->ed->trListHead;
                pipe->startWriteBackCount = usbHostState->writeBackCount;
            }
        }
        else
        {
            pipe->isDone = 0U;
        }
#endif
        temp = (void *)pipe->pipeCommon.next;
        pipe = (usb_host_ohci_pipe_struct_t *)temp;
    }
    /* Exit critical */
    USB_HostOhciEnableIsr(usbHostState);
    USB_HostOhciUnlock();

    return kStatus_USB_Success;
}

static usb_status_t UBS_HostOhciControllerReset(usb_host_ohci_state_struct_t *usbHostState)
{
    usbHostState->usbRegBase->HcCommandStatus = USB_HOST_OHCI_COMMAND_STATUS_HCR_MASK;
    while (0U != (usbHostState->usbRegBase->HcCommandStatus & USB_HOST_OHCI_COMMAND_STATUS_HCR_MASK))
    {
        __NOP();
    }
    return kStatus_USB_Success;
}

static usb_status_t UBS_HostOhciControllerInit(usb_host_ohci_state_struct_t *usbHostState)
{
    usb_host_ohci_pipe_struct_t *pipe;
#if (defined(USB_HOST_CONFIG_OHCI_MAX_GTD) && (USB_HOST_CONFIG_OHCI_MAX_GTD > 0U))
    usb_host_ohci_general_transfer_descritpor_struct_t *gtd;
#endif
#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
    usb_host_ohci_isochronous_transfer_descritpor_struct_t *itd;
#endif
    uint32_t i;
    void *temp;
    OSA_SR_ALLOC();

    /* Enter critical */
    OSA_ENTER_CRITICAL();

    for (i = 0; i < (sizeof(s_UsbHostOhciTd[usbHostState->controllerId].ed) /
                     sizeof(usb_host_ohci_endpoint_descritpor_struct_t));
         i++)
    {
        s_UsbHostOhciTd[usbHostState->controllerId].ed[i].stateUnion.stateBitField.K = 1U;
    }

    for (i = 0; i < sizeof(usb_host_ohci_hcca_struct_t); i++)
    {
        *((uint8_t *)(&s_UsbHostOhciHcca[usbHostState->controllerId]) + i) = 0x00U;
    }

    usbHostState->pipeListInUsing = NULL;
    usbHostState->pipeList        = &usbHostState->pipePool[0];
    pipe                          = usbHostState->pipeList;
    pipe->ed                      = &s_UsbHostOhciTd[usbHostState->controllerId].ed[3];
    for (i = 1; i < USB_HOST_CONFIG_OHCI_MAX_ED; i++)
    {
        temp                  = (void *)(&usbHostState->pipePool[i]);
        pipe->pipeCommon.next = (usb_host_pipe_t *)temp;
        temp                  = (void *)pipe->pipeCommon.next;
        pipe                  = (usb_host_ohci_pipe_struct_t *)temp;
        pipe->ed              = &s_UsbHostOhciTd[usbHostState->controllerId].ed[3U + i];
    }
    pipe->pipeCommon.next = NULL;

#if (defined(USB_HOST_CONFIG_OHCI_MAX_GTD) && (USB_HOST_CONFIG_OHCI_MAX_GTD > 0U))
    usbHostState->gtdList = &s_UsbHostOhciTd[usbHostState->controllerId].gtd[0];
    gtd                   = usbHostState->gtdList;
    for (i = 1U; i < USB_HOST_CONFIG_OHCI_MAX_GTD; i++)
    {
        gtd->nextGtd = &s_UsbHostOhciTd[usbHostState->controllerId].gtd[i];
        gtd          = gtd->nextGtd;
    }
    gtd->nextGtd           = NULL;
    usbHostState->gtdCount = USB_HOST_CONFIG_OHCI_MAX_GTD;
#endif

#if (defined(USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
    usbHostState->itdList = &s_UsbHostOhciTd[usbHostState->controllerId].itd[0];
    itd                   = usbHostState->itdList;
    for (i = 1U; i < USB_HOST_CONFIG_OHCI_MAX_ITD; i++)
    {
        itd->NextTD = (uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].itd[i];
        itd         = (usb_host_ohci_isochronous_transfer_descritpor_struct_t *)itd->NextTD;
    }
    itd->NextTD            = 0U;
    usbHostState->itdCount = USB_HOST_CONFIG_OHCI_MAX_ITD;
#endif
    usbHostState->tdDoneListTail = NULL;
    usbHostState->tdDoneListHead = NULL;
    usbHostState->writeBackCount = 0U;

    /* Exit critical */
    OSA_EXIT_CRITICAL();

    usbHostState->usbRegBase->HcControl = 0U;
    usbHostState->usbRegBase->HcControl &= ~USB_HOST_OHCI_CONTROL_HCFS_MASK;
    usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_HCFS(USB_HOST_OHCI_CONTROL_HCFS_OPERATIONAL);
    usbHostState->usbRegBase->HcFmInterval =
        (USB_HOST_OHCI_FMINTERVAL_FSMPS((6UL * (USB_HOST_OHCI_SOF_INTERVAL - 210UL)) / 7UL)) |
        (USB_HOST_OHCI_FMINTERVAL_FI(USB_HOST_OHCI_SOF_INTERVAL));
    usbHostState->usbRegBase->HcPeriodicStart = USB_HOST_OHCI_PERIODIC_START_PS(
        (uint32_t)((float)USB_HOST_OHCI_SOF_INTERVAL * (float)USB_HOST_OHCI_PERIODIC_BANDWIDTH_PERCENT));
    s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_CONTROL_ED_DUMMY].NextED = 0U;
    usbHostState->usbRegBase->HcControlHeadED =
        (uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_CONTROL_ED_DUMMY];
    s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_BULK_ED_DUMMY].NextED = 0U;
    usbHostState->usbRegBase->HcBulkHeadED =
        (uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_BULK_ED_DUMMY];
    s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_PERIODIC_ED_DUMMY].NextED = 0U;
    for (i = 0; i < USB_HOST_OHCI_HCCA_SIZE; i++)
    {
        s_UsbHostOhciHcca[usbHostState->controllerId].HccaInterrruptTable[i] =
            (uint32_t)&s_UsbHostOhciTd[usbHostState->controllerId].ed[USB_HOST_OHCI_PERIODIC_ED_DUMMY];
    }
    usbHostState->usbRegBase->HcHCCA = (uint32_t)&s_UsbHostOhciHcca[usbHostState->controllerId];
    usbHostState->usbRegBase->HcControl |= USB_HOST_OHCI_CONTROL_CBSR(USB_HOST_OHCI_CONTROL_CBSR_C1_B1);
    if (0U != (usbHostState->usbRegBase->HcRhDescriptorA & USB_HOST_OHCI_RHDESCRIPTORA_NPS_MASK))
    {
    }
    else
    {
/* Use global power to turn on the port power for all ports */
#if 0
        if (usbHostState->usbRegBase->HcRhDescriptorA & USB_HOST_OHCI_RHDESCRIPTORA_PSM_MASK)
        {
            usbHostState->usbRegBase->HcRhDescriptorB |= USB_HOST_OHCI_RHDESCRIPTORB_PPCM(0xFFFEUL);
            for (i = 0; i < (usbHostState->usbRegBase->HcRhDescriptorA & USB_HOST_OHCI_RHDESCRIPTORA_NDP_MASK); i++)
            {
                uint32_t portStatus = usbHostState->usbRegBase->HcRhPortStatus[i];
                portStatus &= ~USB_HOST_OHCI_RHPORTSTATUS_WIC;
                portStatus |= USB_HOST_OHCI_RHPORTSTATUS_PPS_MASK;
                usbHostState->usbRegBase->HcRhPortStatus[i] = portStatus;
            }
            usbHostState->usbRegBase->HcRhStatus = USB_HOST_OHCI_RHSTATUS_LPSC_MASK;
        }
        else
        {
            usbHostState->usbRegBase->HcRhStatus = USB_HOST_OHCI_RHSTATUS_LPSC_MASK;
        }
#else
        usbHostState->usbRegBase->HcRhDescriptorB &= ~USB_HOST_OHCI_RHDESCRIPTORB_PPCM(0xFFFEUL);
        usbHostState->usbRegBase->HcRhStatus = USB_HOST_OHCI_RHSTATUS_LPSC_MASK;
#endif
    }
    usbHostState->usbRegBase->HcInterruptDisable |= USB_HOST_OHCI_INTERRUPT_DISABLE_MASK;
    usbHostState->usbRegBase->HcInterruptEnable |=
        USB_HOST_OHCI_INTERRUPT_ENABLE_MIE_MASK | USB_HOST_OHCI_INTERRUPT_ENABLE_WDH_MASK |
        USB_HOST_OHCI_INTERRUPT_ENABLE_RHSC_MASK | USB_HOST_OHCI_INTERRUPT_ENABLE_SF_MASK;

    return kStatus_USB_Success;
}

/*!
 * @brief create the USB host ohci instance.
 *
 * This function initializes the USB host ohci controller driver.
 *
 * @param controllerId        The controller id of the USB IP. Please refer to the enumeration usb_controller_index_t.
 * @param hostHandle         The host level handle.
 * @param controllerHandle  Return the controller instance handle.
 *
 * @retval kStatus_USB_Success              The host is initialized successfully.
 * @retval kStatus_USB_AllocFail             allocate memory fail.
 * @retval kStatus_USB_Error                 host mutex create fail, OHCI mutex or OHCI event create fail.
 *                                                         Or, OHCI IP initialize fail.
 */
usb_status_t USB_HostOhciCreate(uint8_t controllerId,
                                usb_host_handle hostHandle,
                                usb_host_controller_handle *controllerHandle)
{
    usb_host_ohci_state_struct_t *usbHostState;
    usb_status_t status       = kStatus_USB_Success;
    uint32_t usb_base_addrs[] = USBFSH_BASE_ADDRS;
    IRQn_Type usb_irq[]       = USBFSH_IRQS;

    if (((controllerId - (uint8_t)kUSB_ControllerOhci0) >= (uint8_t)USB_HOST_CONFIG_OHCI) ||
        ((controllerId - (uint8_t)kUSB_ControllerOhci0) >= (sizeof(usb_base_addrs) / sizeof(uint32_t))))
    {
        return kStatus_USB_ControllerNotFound;
    }
    usbHostState = &s_UsbHostOhciState[controllerId - (uint8_t)kUSB_ControllerOhci0];
    /* Allocate the USB Host Pipe Descriptors */
    usbHostState->hostHandle   = hostHandle;
    usbHostState->controllerId = controllerId - (uint8_t)kUSB_ControllerOhci0;

    usbHostState->usbRegBase = (usb_host_ohci_hcor_struct_t *)usb_base_addrs[usbHostState->controllerId];
    usbHostState->isrNumber  = (uint8_t)usb_irq[usbHostState->controllerId];
    usbHostState->ohciEvent  = (osa_event_handle_t)&usbHostState->taskEventHandleBuffer[0];
    if (KOSA_StatusSuccess != OSA_EventCreate(usbHostState->ohciEvent, 1U))
    {
        usbHostState->ohciEvent = NULL;
#ifdef HOST_ECHO
        usb_echo(" event create failed in USB_HostOhciCreate\n");
#endif
        return kStatus_USB_AllocFail;
    } /* Endif */
    usbHostState->mutex = (osa_mutex_handle_t)(&usbHostState->mutexBuffer[0]);
    if (KOSA_StatusSuccess != OSA_MutexCreate(usbHostState->mutex))
    {
        usbHostState->mutex = NULL;
        (void)USB_HostOhciDestory(usbHostState);
#ifdef HOST_ECHO
        usb_echo("USB_HostOhciCreate: create host mutex fail\r\n");
#endif
        return kStatus_USB_AllocFail;
    }

    /* enable Host clock, OTG clock and AHB clock */
    usbHostState->usbRegBase->PortMode &= ~USB_HOST_OHCI_PORTMODE_DEV_ENABLE_MASK;
    usbHostState->portNumber =
        (uint8_t)(usbHostState->usbRegBase->HcRhDescriptorA & USB_HOST_OHCI_RHDESCRIPTORA_NDP_MASK);
    if (0U == usbHostState->portNumber)
    {
#ifdef HOST_ECHO
        usb_echo(" Port number is invalid in USB_HostOhciCreate\n");
#endif
        (void)USB_HostOhciDestory(usbHostState);
        return kStatus_USB_Error;
    }

    usbHostState->portState = (usb_host_ohci_port_state_struct_t *)OSA_MemoryAllocate(
        (uint32_t)sizeof(usb_host_ohci_port_state_struct_t) *
        ((uint32_t)usbHostState->portNumber)); /* malloc host ohci port state */
    if (NULL == usbHostState->portState)
    {
        (void)USB_HostOhciDestory(usbHostState);
#ifdef HOST_ECHO
        usb_echo("USB_HostOhciCreate: mem alloc fail\r\n");
#endif
        return kStatus_USB_Error;
    }

    (void)UBS_HostOhciControllerReset(usbHostState);

    (void)UBS_HostOhciControllerInit(usbHostState);

    *controllerHandle = (usb_host_handle)usbHostState;
    return status;
}

/*!
 * @brief destroy USB host ohci instance.
 *
 * This function de-initialize the USB host ohci controller driver.
 *
 * @param handle                                    the controller handle.
 *
 * @retval kStatus_USB_Success              The host is initialized successfully.
 */
usb_status_t USB_HostOhciDestory(usb_host_controller_handle controllerHandle)
{
    usb_host_ohci_state_struct_t *usbHostState = (usb_host_ohci_state_struct_t *)controllerHandle;

    usbHostState->usbRegBase->HcInterruptDisable |= USB_HOST_OHCI_INTERRUPT_DISABLE_MASK;
    usbHostState->usbRegBase->HcRhStatus |= USB_HOST_OHCI_RHSTATUS_LPS_MASK;
    usbHostState->usbRegBase->HcControl = 0U;

    if (NULL != usbHostState->portState)
    {
        (void)OSA_MemoryFree(usbHostState->portState);
        usbHostState->portState = NULL;
    }

    if (NULL != usbHostState->mutex)
    {
        (void)OSA_MutexDestroy(usbHostState->mutex);
        usbHostState->mutex = NULL;
    }

    if (NULL != usbHostState->ohciEvent)
    {
        (void)OSA_EventDestroy(usbHostState->ohciEvent);
        usbHostState->ohciEvent = NULL;
    }

    return kStatus_USB_Success;
}

usb_status_t USB_HostOhciOpenPipe(usb_host_controller_handle controllerHandle,
                                  usb_host_pipe_handle *pipeHandle,
                                  usb_host_pipe_init_t *pipeInit)
{
    usb_host_ohci_pipe_struct_t *pipe = NULL;
    usb_status_t status;
    usb_host_ohci_state_struct_t *usbHostState = (usb_host_ohci_state_struct_t *)controllerHandle;

    status = USB_HostOhciGetPipe(&usbHostState->pipeList, &pipe);

    if ((kStatus_USB_Success != status) || (NULL == pipe))
    {
#ifdef HOST_ECHO
        usb_echo("ohci open pipe failed\r\n");
#endif
        return kStatus_USB_Busy;
    }

    /* initialize pipe informations */
    pipe->pipeCommon.deviceHandle         = pipeInit->devInstance;
    pipe->pipeCommon.endpointAddress      = pipeInit->endpointAddress;
    pipe->pipeCommon.direction            = pipeInit->direction;
    pipe->pipeCommon.interval             = pipeInit->interval;
    pipe->pipeCommon.maxPacketSize        = pipeInit->maxPacketSize;
    pipe->pipeCommon.pipeType             = pipeInit->pipeType;
    pipe->pipeCommon.numberPerUframe      = 1U;
    pipe->pipeCommon.nakCount             = pipeInit->nakCount;
    pipe->pipeCommon.nextdata01           = 0U;
    pipe->pipeCommon.currentCount         = 0U;
    pipe->pipeCommon.open                 = 1U;
    pipe->ed->stateUnion.stateBitField.EN = pipeInit->endpointAddress;
    pipe->ed->stateUnion.stateBitField.D  = (USB_OUT == pipeInit->direction) ? 1U : 2U;
    pipe->ed->stateUnion.stateBitField.FA = USB_HostOhciGetDeviceInfo(pipeInit->devInstance, kUSB_HostGetDeviceAddress);
    pipe->ed->stateUnion.stateBitField.S =
        (USB_SPEED_FULL == USB_HostOhciGetDeviceInfo(pipeInit->devInstance, kUSB_HostGetDeviceSpeed)) ? 0U : 1U;
    pipe->ed->stateUnion.stateBitField.F   = 0U;
    pipe->ed->stateUnion.stateBitField.MPS = pipeInit->maxPacketSize;
    pipe->ed->stateUnion.stateBitField.K   = 0U;
    pipe->ed->TailP                        = 0U;
    pipe->ed->HeadP                        = 0U;
    pipe->ed->pipe                         = pipe;
    pipe->ed->NextED                       = 0U;
    pipe->ed->trListHead                   = NULL;
    pipe->ed->trListTail                   = NULL;
    pipe->ed->dealTr                       = NULL;
    pipe->cutOffTime                       = USB_HOST_OHCI_TRANSFER_TIMEOUT_GAP;
    pipe->isCanceling                      = 0U;
#if (defined(USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND) && (USB_HOST_OHCI_DEVICE_NOT_RESPONDING_WORKAROUND))
    pipe->deviceNotRespondingCount = 0U;
    pipe->endpointInterval         = 0U;
#endif

    if (USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType)
    {
        pipe->ed->stateUnion.stateBitField.F = 1U;

#if 0
        pipe->pipeCommon.interval =
            (1 << (pipe->pipeCommon.interval - 1)); /* iso interval is the power of 2 */
        if (pipe->pipeCommon.interval > USB_HOST_OHCI_HCCA_SIZE)
        {
            pipe->pipeCommon.interval = USB_HOST_OHCI_HCCA_SIZE;
        }
#else
        pipe->pipeCommon.interval = 1U;
#endif
    }
    else if (USB_ENDPOINT_INTERRUPT == pipe->pipeCommon.pipeType)
    {
        uint32_t interval = 0U;
        /* FS/LS interrupt interval should be the power of 2, it is used for ohci bandwidth */
        for (uint32_t p = 0U; p < 16U; p++)
        {
            if (0U != (pipe->pipeCommon.interval & ((uint16_t)(1UL << p))))
            {
                if (p > interval)
                {
                    interval = p;
                }
            }
        }
        pipe->pipeCommon.interval = (uint16_t)(1UL << interval);
        if (pipe->pipeCommon.interval > USB_HOST_OHCI_HCCA_SIZE)
        {
            pipe->pipeCommon.interval = USB_HOST_OHCI_HCCA_SIZE;
        }
    }
    else
    {
    }

    /* open pipe */
    switch (pipe->pipeCommon.pipeType)
    {
        case USB_ENDPOINT_CONTROL:
            pipe->ed->stateUnion.stateBitField.D = 0;
            status                               = USB_HostOhciOpenControlBulkPipe(usbHostState, pipe);
            break;
        case USB_ENDPOINT_BULK:
            status = USB_HostOhciOpenControlBulkPipe(usbHostState, pipe);
            break;

#if ((defined(USB_HOST_CONFIG_OHCI_MAX_ITD)) && (USB_HOST_CONFIG_OHCI_MAX_ITD > 0U))
        case USB_ENDPOINT_ISOCHRONOUS:
            status = USB_HostOhciOpenIsoPipe(usbHostState, pipe);
            break;
#endif
        case USB_ENDPOINT_INTERRUPT:
            status = USB_HostOhciOpenInterruptPipe(usbHostState, pipe);
            break;

        default:
            status = kStatus_USB_Error;
            break;
    }

    if (status != kStatus_USB_Success)
    {
        pipe->ed->stateUnion.stateBitField.K = 1U;
        pipe->pipeCommon.open                = 0U;
        /* release the pipe */
        (void)USB_HostOhciInsertPipe(&usbHostState->pipeList, pipe);
        return status;
    }

    (void)USB_HostOhciInsertPipe(&usbHostState->pipeListInUsing, pipe);

    *pipeHandle = pipe;
    return status;
}

usb_status_t USB_HostOhciClosePipe(usb_host_controller_handle controllerHandle, usb_host_pipe_handle pipeHandle)
{
    usb_host_ohci_state_struct_t *usbHostState = (usb_host_ohci_state_struct_t *)controllerHandle;
    usb_host_ohci_pipe_struct_t *pipe          = (usb_host_ohci_pipe_struct_t *)pipeHandle;

    switch (pipe->pipeCommon.pipeType)
    {
        case USB_ENDPOINT_BULK:
        case USB_ENDPOINT_CONTROL:
            (void)USB_HostOhciCloseControlBulkPipe(usbHostState, pipe);
            break;

#if ((defined USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD))
        case USB_ENDPOINT_ISOCHRONOUS:
#endif
        case USB_ENDPOINT_INTERRUPT:
            (void)USB_HostOhciCloseIsoInterruptPipe(usbHostState, pipe);
            break;

        default:
            /*no action */
            break;
    }
    (void)USB_HostOhciRemovePipe(&usbHostState->pipeListInUsing, pipe);
    pipe->pipeCommon.open = 0U;
    (void)USB_HostOhciInsertPipe(&usbHostState->pipeList, pipe);

    return kStatus_USB_Success;
}

usb_status_t USB_HostOhciWritePipe(usb_host_controller_handle controllerHandle,
                                   usb_host_pipe_handle pipeHandle,
                                   usb_host_transfer_t *transfer)
{
    usb_host_ohci_state_struct_t *usbHostState = (usb_host_ohci_state_struct_t *)controllerHandle;
    usb_host_ohci_pipe_struct_t *pipe          = (usb_host_ohci_pipe_struct_t *)pipeHandle;
    usb_status_t status                        = kStatus_USB_Error;
    transfer->setupStatus                      = (uint8_t)kStatus_UsbHostOhci_Idle;
    transfer->union2.frame                     = 0U;
    OSA_SR_ALLOC();

    OSA_ENTER_CRITICAL();
    if (NULL != pipe->ed->trListHead)
    {
        pipe->ed->trListTail->next = transfer;
    }
    else
    {
        pipe->ed->trListHead = transfer;
    }
    pipe->ed->trListTail = transfer;
    transfer->next       = NULL;
    OSA_EXIT_CRITICAL();

    switch (pipe->pipeCommon.pipeType)
    {
        case USB_ENDPOINT_CONTROL:
            if (0U != usbHostState->controlIsBusy)
            {
                status = kStatus_USB_Success;
            }
            else
            {
                status = USB_HostOhciLinkGtdControlTr(usbHostState, pipe, transfer);

                if (kStatus_USB_Success == status)
                {
                    usbHostState->controlIsBusy = 1U;
                }
            }
            break;
        case USB_ENDPOINT_BULK:
        case USB_ENDPOINT_INTERRUPT:
            /* initialize gtd for control/bulk/interrupt transfer */
            status = USB_HostOhciLinkGtdTr(usbHostState, pipe, transfer);
            break;
#if ((defined USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD))
        case USB_ENDPOINT_ISOCHRONOUS:
            /* initialize itd for iso transfer */
            /* status = USB_HostOhciLinkItdTr(usbHostState, pipe, transfer); */
            if (0U != transfer->transferLength)
            {
                status = kStatus_USB_Success;
                OSA_ENTER_CRITICAL();
                if (NULL == pipe->ed->dealTr)
                {
                    if (NULL != pipe->ed->trListHead)
                    {
                        pipe->ed->dealTr = pipe->ed->trListHead;
                    }
                    else
                    {
                        pipe->ed->dealTr = transfer;
                    }
                }
                OSA_EXIT_CRITICAL();
            }
            else
            {
                status = kStatus_USB_InvalidParameter;
            }
            break;
#endif
        default:
            /*no action*/
            break;
    }

    if (kStatus_USB_Success != status)
    {
        usb_host_transfer_t *trP = pipe->ed->trListHead;
        usb_host_transfer_t *trQ = NULL;
        OSA_ENTER_CRITICAL();

        while (NULL != trP)
        {
            if (trP == transfer)
            {
                if (NULL == trQ)
                {
                    pipe->ed->trListHead = trP->next;
                }
                else
                {
                    trQ->next = trP->next;
                }
                if (pipe->ed->trListTail == transfer)
                {
                    pipe->ed->trListTail = trQ;
                }
            }
            trQ = trP;
            trP = trP->next;
        }
        OSA_EXIT_CRITICAL();
    }
    return status;
}

usb_status_t USB_HostOhciReadPipe(usb_host_controller_handle controllerHandle,
                                  usb_host_pipe_handle pipeHandle,
                                  usb_host_transfer_t *transfer)
{
    return USB_HostOhciWritePipe(controllerHandle, pipeHandle, transfer);
}

usb_status_t USB_HostOhciIoctl(usb_host_controller_handle controllerHandle, uint32_t ioctlEvent, void *ioctlParam)
{
    usb_host_ohci_state_struct_t *usbHostState = (usb_host_ohci_state_struct_t *)controllerHandle;
    usb_host_cancel_param_t *param;
    usb_host_ohci_pipe_struct_t *pipe;
    uint32_t deviceAddress;
    usb_status_t status = kStatus_USB_Success;
    usb_host_controller_control_t ioctl;
    if (controllerHandle == NULL)
    {
        return kStatus_USB_InvalidHandle;
    }
    deviceAddress = 0U;
    ioctl         = (usb_host_controller_control_t)ioctlEvent;
    switch (ioctl)
    {
        case kUSB_HostCancelTransfer:
            /* cancel pipe or one transfer */
            param = (usb_host_cancel_param_t *)ioctlParam;
            status =
                USB_HostOhciCancelPipe(usbHostState, (usb_host_ohci_pipe_struct_t *)param->pipeHandle, param->transfer);
            break;

        case kUSB_HostBusControl:
            /* bus control */
            status = USB_HostOhciControlBus(usbHostState, *((uint8_t *)ioctlParam));
            break;

        case kUSB_HostGetFrameNumber:
            /* get frame number */
            *((uint32_t *)ioctlParam) = (s_UsbHostOhciHcca[usbHostState->controllerId].HccaFrameNumber);
            break;

        case kUSB_HostUpdateControlEndpointAddress:
            pipe                                 = (usb_host_ohci_pipe_struct_t *)ioctlParam;
            pipe->ed->stateUnion.stateBitField.K = 1U;
            /* update address */
            (void)USB_HostHelperGetPeripheralInformation(pipe->pipeCommon.deviceHandle,
                                                         (uint32_t)kUSB_HostGetDeviceAddress, &deviceAddress);
            pipe->ed->stateUnion.stateBitField.FA = deviceAddress;
            pipe->ed->stateUnion.stateBitField.K  = 0U;
            USB_HostOhciDelay(usbHostState, 2U);
            break;

        case kUSB_HostUpdateControlPacketSize:
            pipe                                   = (usb_host_ohci_pipe_struct_t *)ioctlParam;
            pipe->ed->stateUnion.stateBitField.K   = 1U;
            pipe->ed->stateUnion.stateBitField.MPS = pipe->pipeCommon.maxPacketSize;
            pipe->ed->stateUnion.stateBitField.K   = 0U;
            break;

        case kUSB_HostPortAttachDisable:
            break;

        case kUSB_HostPortAttachEnable:
            break;

        default:
            status = kStatus_USB_NotSupported;
            break;
    }
    return status;
}

void USB_HostOhciTaskFunction(void *hostHandle)
{
    usb_host_ohci_state_struct_t *usbHostState;
    uint32_t bitSet;

    if (NULL == hostHandle)
    {
        return;
    }
    usbHostState = (usb_host_ohci_state_struct_t *)((usb_host_instance_t *)hostHandle)->controllerHandle;

    /* wait all event */
    if (KOSA_StatusSuccess == OSA_EventWait(usbHostState->ohciEvent, 0xFFU, 0, USB_OSA_WAIT_TIMEOUT, &bitSet))
    {
        if (0U != (bitSet & USB_HOST_OHCI_EVENT_PORT_CHANGE))
        {
            (void)USB_HostOhciPortChange(usbHostState);
        }
        if (0U != (bitSet & USB_HOST_OHCI_EVENT_TOKEN_DONE))
        {
            (void)USB_HostOhciTokenDone(usbHostState);
        }
        if (0U != (bitSet & USB_HOST_OHCI_EVENT_SOF))
        {
            (void)USB_HostOhciSof(usbHostState);
        }
        if (0U != (bitSet & USB_HOST_OHCI_EVENT_ATTACH))
        {
            for (uint8_t i = 0; i < usbHostState->portNumber; i++)
            {
                if ((uint8_t)kUSB_DeviceOhciPortPhyAttached == usbHostState->portState[i].portStatus)
                {
                    void *deviceHandle;
                    if (kStatus_USB_Success == USB_HostAttachDevice(usbHostState->hostHandle,
                                                                    usbHostState->portState[i].portSpeed, 0U, i, 1U,
                                                                    &deviceHandle))
                    {
                        usbHostState->portState[i].portStatus = (uint8_t)kUSB_DeviceOhciPortAttached;
                    }
                }
            }
        }
        if (0U != (bitSet & USB_HOST_OHCI_EVENT_DETACH))
        {
            for (uint8_t i = 0; i < usbHostState->portNumber; i++)
            {
                if ((uint8_t)kUSB_DeviceOhciPortPhyDetached == usbHostState->portState[i].portStatus)
                {
                    usbHostState->portState[i].portStatus = (uint8_t)kUSB_DeviceOhciPortDetached;
                    (void)USB_HostDetachDevice(usbHostState->hostHandle, 0U, i);
                }
            }
        }
    }
}

void USB_HostOhciIsrFunction(void *hostHandle)
{
    usb_host_ohci_state_struct_t *usbHostState;
    static uint32_t interruptStatus = 0U;
    static uint32_t sofCount        = 0U;

    if (hostHandle == NULL)
    {
        return;
    }

    usbHostState = (usb_host_ohci_state_struct_t *)((usb_host_instance_t *)hostHandle)->controllerHandle;

    interruptStatus = usbHostState->usbRegBase->HcInterruptStatus;
    interruptStatus &= usbHostState->usbRegBase->HcInterruptEnable;

    if (0U != (interruptStatus & USB_HOST_OHCI_INTERRUPT_STATUS_WDH_MASK)) /* Write back done head */
    {
        USB_HostOhciLinkTdToDoneList(usbHostState);
        (void)OSA_EventSet(usbHostState->ohciEvent, USB_HOST_OHCI_EVENT_TOKEN_DONE);
    }

    if (0U != (interruptStatus & USB_HOST_OHCI_INTERRUPT_STATUS_SF_MASK)) /* SOF interrupt */
    {
#if ((defined USB_HOST_CONFIG_OHCI_MAX_ITD) && (USB_HOST_CONFIG_OHCI_MAX_ITD))
        usb_host_ohci_pipe_struct_t *pipe;
        void *temp;
        temp = (void *)usbHostState->pipeListInUsing;
        while (NULL != temp)
        {
            pipe = (usb_host_ohci_pipe_struct_t *)temp;
            temp = (void *)pipe->pipeCommon.next;
            if ((USB_ENDPOINT_ISOCHRONOUS == pipe->pipeCommon.pipeType) && (NULL != pipe->ed->trListHead))
            {
                if ((NULL != pipe->ed->dealTr))
                {
                    uint32_t tail = pipe->ed->TailP & USB_HOST_OHCI_ED_TAILP_MASK;
                    uint32_t head = pipe->ed->HeadP & USB_HOST_OHCI_ED_HEADP_MASK;
                    if (head == tail)
                    {
                        if (kStatus_USB_Success == USB_HostOhciLinkItdTr(usbHostState, pipe, pipe->ed->dealTr))
                        {
                            pipe->ed->dealTr = pipe->ed->dealTr->next;
                        }
                        else
                        {
                            /*no action*/
                        }
                    }
                }
                pipe->isDone = 0U;
            }
        }
#endif
        sofCount++;
        if (sofCount >= USB_HOST_OHCI_TRANSFER_SCAN_INTERVAL)
        {
            sofCount = 0U;
            (void)OSA_EventSet(usbHostState->ohciEvent, USB_HOST_OHCI_EVENT_SOF);
        }
    }

    if (0U != (interruptStatus & USB_HOST_OHCI_INTERRUPT_STATUS_RHSC_MASK)) /* port change detect interrupt */
    {
        (void)OSA_EventSet(usbHostState->ohciEvent, USB_HOST_OHCI_EVENT_PORT_CHANGE);
    }

    usbHostState->usbRegBase->HcInterruptStatus = interruptStatus; /* clear interrupt */
}

#endif
