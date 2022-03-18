/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_component_serial_manager.h"
#include "fsl_component_serial_port_internal.h"

#if (defined(SERIAL_PORT_TYPE_USBCDC) && (SERIAL_PORT_TYPE_USBCDC > 0U))
#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"

#include "usb_device_class.h"
#include "usb_device_cdc_acm.h"
#include "usb_device_ch9.h"

#include "usb_device_descriptor.h"
#include "fsl_component_serial_port_usb.h"

#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0)
#include "usb_phy.h"
#endif
#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
#include "fsl_sysmpu.h"
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#ifndef NDEBUG
#if (defined(DEBUG_CONSOLE_ASSERT_DISABLE) && (DEBUG_CONSOLE_ASSERT_DISABLE > 0U))
#undef assert
#define assert(n)
#else
/* MISRA C-2012 Rule 17.2 */
#undef assert
#define assert(n) \
    while (!(n))  \
    {             \
        ;         \
    }
#endif
#endif

#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0)
#define DATA_BUFF_SIZE HS_CDC_VCOM_BULK_OUT_PACKET_SIZE

#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0)
#define DATA_BUFF_SIZE FS_CDC_VCOM_BULK_OUT_PACKET_SIZE

#endif
#if defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U)
#define DATA_BUFF_SIZE FS_CDC_VCOM_BULK_OUT_PACKET_SIZE

#endif

#if defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)
#define DATA_BUFF_SIZE HS_CDC_VCOM_BULK_OUT_PACKET_SIZE
#endif

/* Currently configured line coding */
#define LINE_CODING_SIZE       (0x07)
#define LINE_CODING_DTERATE    (115200)
#define LINE_CODING_CHARFORMAT (0x00)
#define LINE_CODING_PARITYTYPE (0x00)
#define LINE_CODING_DATABITS   (0x08)

/* Communications feature */
#define COMM_FEATURE_DATA_SIZE (0x02)
#define STATUS_ABSTRACT_STATE  (0x0000)
#define COUNTRY_SETTING        (0x0000)

/* Notification of serial state */
#define NOTIF_PACKET_SIZE  (0x08)
#define UART_BITMAP_SIZE   (0x02)
#define NOTIF_REQUEST_TYPE (0xA1)

typedef struct _serial_usb_send_state
{
    serial_manager_callback_t callback;
    void *callbackParam;
    uint8_t *buffer;
    uint32_t length;
    volatile uint8_t busy;
    volatile uint8_t waiting4Prime;
} serial_usb_send_state_t;

typedef struct _serial_usb_recv_state
{
    serial_manager_callback_t callback;
    void *callbackParam;
    volatile uint8_t busy;
} serial_usb_recv_state_t;

/* Define the information relates to abstract control model */
typedef struct _usb_cdc_acm_info
{
    uint8_t serialStateBuf[NOTIF_PACKET_SIZE + UART_BITMAP_SIZE]; /* Serial state buffer of the CDC device to notify the
                                                                     serial state to host. */
    bool dtePresent;          /* A flag to indicate whether DTE is present.         */
    uint16_t breakDuration;   /* Length of time in milliseconds of the break signal */
    uint8_t dteStatus;        /* Status of data terminal equipment                  */
    uint8_t currentInterface; /* Current interface index.                           */
    uint16_t uartState;       /* UART state of the CDC device.                      */
} usb_cdc_acm_info_t;

/* Define the types for application */
typedef struct _serial_usb_cdc_state
{
    struct _serial_usb_cdc_state *next; /* Next pointer of the interface */
    usb_device_handle deviceHandle;     /* USB device handle. */
    class_handle_t cdcAcmHandle;        /* USB CDC ACM class handle. */
    serial_usb_send_state_t tx;
    serial_usb_recv_state_t rx;
    volatile uint8_t attach; /* A flag to indicate whether a usb device is attached. 1: attached, 0: not attached */
    uint8_t speed;           /* Speed of USB device. USB_SPEED_FULL/USB_SPEED_LOW/USB_SPEED_HIGH.                 */
    volatile uint8_t
        startTransactions; /* A flag to indicate whether a CDC device is ready to transmit and receive data.    */
    uint8_t currentConfiguration;                                           /* Current configuration value. */
    uint8_t currentInterfaceAlternateSetting[USB_CDC_VCOM_INTERFACE_COUNT]; /* Current alternate setting value for each
                                                                               interface. */
    uint8_t instance;                                                       /* The instance of the interface */
    uint8_t irqNumber;                                                      /* The IRQ number of the interface */
} serial_usb_cdc_state_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void USB_DeviceIsrEnable(serial_usb_cdc_state_t *serialUsbCdc);
#if USB_DEVICE_CONFIG_USE_TASK
void USB_DeviceTaskFn(void *deviceHandle);
#endif

static usb_status_t USB_DeviceCdcVcomCallback(class_handle_t handle, uint32_t event, void *param);
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param);

/*******************************************************************************
 * Variables
 ******************************************************************************/

static serial_usb_cdc_state_t *s_UsbCdcHead;

/* Line codinig of cdc device */
USB_DMA_INIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t s_lineCoding[LINE_CODING_SIZE] = {
    /* E.g. 0x00,0xC2,0x01,0x00 : 0x0001C200 is 115200 bits per second */
    (LINE_CODING_DTERATE >> 0U) & 0x000000FFU,
    (LINE_CODING_DTERATE >> 8U) & 0x000000FFU,
    (LINE_CODING_DTERATE >> 16U) & 0x000000FFU,
    (LINE_CODING_DTERATE >> 24U) & 0x000000FFU,
    LINE_CODING_CHARFORMAT,
    LINE_CODING_PARITYTYPE,
    LINE_CODING_DATABITS};

/* Abstract state of cdc device */
USB_DMA_INIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t s_abstractState[COMM_FEATURE_DATA_SIZE] = {(STATUS_ABSTRACT_STATE >> 0U) & 0x00FFU,
                                                          (STATUS_ABSTRACT_STATE >> 8U) & 0x00FFU};

/* Country code of cdc device */
USB_DMA_INIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE)
static uint8_t s_countryCode[COMM_FEATURE_DATA_SIZE] = {(COUNTRY_SETTING >> 0U) & 0x00FFU,
                                                        (COUNTRY_SETTING >> 8U) & 0x00FFU};

/* CDC ACM information */
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) static usb_cdc_acm_info_t s_usbCdcAcmInfo;
/* Data buffer for receiving and sending*/
USB_DMA_NONINIT_DATA_ALIGN(USB_DATA_ALIGN_SIZE) static uint8_t s_currRecvBuf[DATA_BUFF_SIZE];

/* USB device class information */
static usb_device_class_config_struct_t s_cdcAcmConfig[1] = {{
    USB_DeviceCdcVcomCallback,
    0,
    &g_UsbDeviceCdcVcomConfig,
}};

/* USB device class configuration information */
static usb_device_class_config_list_struct_t s_cdcAcmConfigList = {
    s_cdcAcmConfig,
    USB_DeviceCallback,
    1,
};

/*******************************************************************************
 * Code
 ******************************************************************************/

static serial_usb_cdc_state_t *USB_DeviceGetInstanceFromDeviceHandle(serial_usb_cdc_state_t *head,
                                                                     usb_device_handle deviceHandle)
{
    while (NULL != head)
    {
        if (head->deviceHandle == deviceHandle)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

static serial_usb_cdc_state_t *USB_DeviceGetInstanceFromClassHandle(serial_usb_cdc_state_t *head,
                                                                    class_handle_t ClassHandle)
{
    while (NULL != head)
    {
        if (head->cdcAcmHandle == ClassHandle)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

static usb_status_t USB_DeviceAddItem(serial_usb_cdc_state_t **head, serial_usb_cdc_state_t *node)
{
    serial_usb_cdc_state_t *p = *head;
    uint32_t regPrimask;

    regPrimask = DisableGlobalIRQ();

    if (NULL == p)
    {
        *head = node;
    }
    else
    {
        while (NULL != p->next)
        {
            if (p == node)
            {
                EnableGlobalIRQ(regPrimask);
                return kStatus_USB_Error;
            }
            p = p->next;
        }

        p->next = node;
    }
    node->next = NULL;
    EnableGlobalIRQ(regPrimask);
    return kStatus_USB_Success;
}

static usb_status_t USB_DeviceRemoveItem(serial_usb_cdc_state_t **head, serial_usb_cdc_state_t *node)
{
    serial_usb_cdc_state_t *p = *head;
    serial_usb_cdc_state_t *q = NULL;
    uint32_t regPrimask;

    regPrimask = DisableGlobalIRQ();
    while (NULL != p)
    {
        if (p == node)
        {
            if (NULL == q)
            {
                *head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            break;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    EnableGlobalIRQ(regPrimask);
    return kStatus_USB_Success;
}

/*!
 * @brief CDC class specific callback function.
 *
 * This function handles the CDC class specific requests.
 *
 * @param handle          The CDC ACM class handle.
 * @param event           The CDC ACM class event type.
 * @param param           The parameter of the class specific request.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
static usb_status_t USB_DeviceCdcVcomCallback(class_handle_t handle, uint32_t event, void *param)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    uint32_t len;
    uint8_t *uartBitmap;
    usb_device_cdc_acm_request_param_struct_t *acmReqParam;
    usb_device_endpoint_callback_message_struct_t *epCbParam;
    usb_cdc_acm_info_t *acmInfo = &s_usbCdcAcmInfo;
    serial_manager_callback_message_t msg;
    usb_status_t error = kStatus_USB_InvalidRequest;

    serialUsbCdc = USB_DeviceGetInstanceFromClassHandle(s_UsbCdcHead, handle);
    if (NULL == serialUsbCdc)
    {
        return kStatus_USB_InvalidRequest;
    }
    acmReqParam = (usb_device_cdc_acm_request_param_struct_t *)param;
    epCbParam   = (usb_device_endpoint_callback_message_struct_t *)param;
    switch ((usb_device_cdc_acm_event_t)event)
    {
        case kUSB_DeviceCdcEventSendResponse:
        {
            if (1U == serialUsbCdc->attach)
            {
                if ((epCbParam->length != 0U) &&
                    (0U == (epCbParam->length % g_UsbDeviceCdcVcomDicEndpoints[0].maxPacketSize)))
                {
                    /* If the last packet is the size of endpoint, then send also zero-ended packet,
                     ** meaning that we want to inform the host that we do not have any additional
                     ** data, so it can flush the output.
                     */
                    error = USB_DeviceCdcAcmSend(handle, (uint8_t)USB_CDC_VCOM_BULK_IN_ENDPOINT, NULL, 0U);
                }
                else
                {
                    serialUsbCdc->tx.busy = 0;

                    if ((NULL != serialUsbCdc->tx.callback))
                    {
                        serial_manager_status_t serialManagerStatus = kStatus_SerialManager_Success;
                        msg.buffer                                  = serialUsbCdc->tx.buffer;
                        msg.length                                  = serialUsbCdc->tx.length;
                        error                                       = kStatus_USB_Success;
                        if (USB_UNINITIALIZED_VAL_32 == epCbParam->length)
                        {
                            serialManagerStatus = kStatus_SerialManager_Canceled;
                        }
                        serialUsbCdc->tx.callback(serialUsbCdc->tx.callbackParam, &msg, serialManagerStatus);
                    }
                }
            }
        }
        break;
        case kUSB_DeviceCdcEventRecvResponse:
        {
            serialUsbCdc->rx.busy = 0U;
            if ((1U == serialUsbCdc->startTransactions))
            {
                serial_manager_status_t callbackStatus = kStatus_SerialManager_Success;

                if ((NULL != serialUsbCdc->rx.callback))
                {
                    msg.buffer = epCbParam->buffer;
                    msg.length = epCbParam->length;
                    error      = kStatus_USB_Success;
                    if (USB_UNINITIALIZED_VAL_32 == msg.length)
                    {
                        msg.length     = 0U;
                        callbackStatus = kStatus_SerialManager_Canceled;
                    }
                    serialUsbCdc->rx.callback(serialUsbCdc->rx.callbackParam, &msg, callbackStatus);
                }
            }
        }
        break;
        case kUSB_DeviceCdcEventSerialStateNotif:
            ((usb_device_cdc_acm_struct_t *)handle)->hasSentState = 0;
            if ((0U != serialUsbCdc->startTransactions) && (0U != serialUsbCdc->tx.waiting4Prime))
            {
                serialUsbCdc->tx.waiting4Prime = 0U;
                serialUsbCdc->tx.busy          = 1U;
                if (kStatus_USB_Success != USB_DeviceCdcAcmSend(serialUsbCdc->cdcAcmHandle,
                                                                USB_CDC_VCOM_BULK_IN_ENDPOINT, serialUsbCdc->tx.buffer,
                                                                serialUsbCdc->tx.length))
                {
                    serialUsbCdc->tx.busy = 0U;
                }
            }
            error = kStatus_USB_Success;
            break;
        case kUSB_DeviceCdcEventSendEncapsulatedCommand:
            break;
        case kUSB_DeviceCdcEventGetEncapsulatedResponse:
            break;
        case kUSB_DeviceCdcEventSetCommFeature:
            if ((uint16_t)USB_DEVICE_CDC_FEATURE_ABSTRACT_STATE == acmReqParam->setupValue)
            {
                if (1U == acmReqParam->isSetup)
                {
                    *(acmReqParam->buffer) = s_abstractState;
                    *(acmReqParam->length) = sizeof(s_abstractState);
                }
                else
                {
                    /* no action, data phase, s_abstractState has been assigned */
                }
                error = kStatus_USB_Success;
            }
            else if ((uint16_t)USB_DEVICE_CDC_FEATURE_COUNTRY_SETTING == acmReqParam->setupValue)
            {
                if (1U == acmReqParam->isSetup)
                {
                    *(acmReqParam->buffer) = s_countryCode;
                    *(acmReqParam->length) = sizeof(s_countryCode);
                }
                else
                {
                    /* no action, data phase, s_countryCode has been assigned */
                }
                error = kStatus_USB_Success;
            }
            else
            {
                /* MISRA C-2012 Rule 15.7 */
            }
            break;
        case kUSB_DeviceCdcEventGetCommFeature:
            if ((uint16_t)USB_DEVICE_CDC_FEATURE_ABSTRACT_STATE == acmReqParam->setupValue)
            {
                *(acmReqParam->buffer) = s_abstractState;
                *(acmReqParam->length) = COMM_FEATURE_DATA_SIZE;
                error                  = kStatus_USB_Success;
            }
            else if ((uint16_t)USB_DEVICE_CDC_FEATURE_COUNTRY_SETTING == acmReqParam->setupValue)
            {
                *(acmReqParam->buffer) = s_countryCode;
                *(acmReqParam->length) = COMM_FEATURE_DATA_SIZE;
                error                  = kStatus_USB_Success;
            }
            else
            {
                /* MISRA C-2012 Rule 15.7 */
            }
            break;
        case kUSB_DeviceCdcEventClearCommFeature:
            break;
        case kUSB_DeviceCdcEventGetLineCoding:
            *(acmReqParam->buffer) = s_lineCoding;
            *(acmReqParam->length) = LINE_CODING_SIZE;
            error                  = kStatus_USB_Success;
            break;
        case kUSB_DeviceCdcEventSetLineCoding:
        {
            if (1U == acmReqParam->isSetup)
            {
                *(acmReqParam->buffer) = s_lineCoding;
                *(acmReqParam->length) = sizeof(s_lineCoding);
            }
            else
            {
                /* no action, data phase, s_lineCoding has been assigned */
            }
        }
            error = kStatus_USB_Success;
            break;
        case kUSB_DeviceCdcEventSetControlLineState:
        {
            error                     = kStatus_USB_Success;
            s_usbCdcAcmInfo.dteStatus = (uint8_t)acmReqParam->setupValue;
            /* activate/deactivate Tx carrier */
            if (0U != (acmInfo->dteStatus & (uint8_t)USB_DEVICE_CDC_CONTROL_SIG_BITMAP_CARRIER_ACTIVATION))
            {
                acmInfo->uartState |= (uint16_t)USB_DEVICE_CDC_UART_STATE_TX_CARRIER;
            }
            else
            {
                acmInfo->uartState &= ~((uint16_t)USB_DEVICE_CDC_UART_STATE_TX_CARRIER);
            }

            /* activate carrier and DTE */
            if (0U != (acmInfo->dteStatus & (uint8_t)USB_DEVICE_CDC_CONTROL_SIG_BITMAP_DTE_PRESENCE))
            {
                acmInfo->uartState |= (uint16_t)USB_DEVICE_CDC_UART_STATE_RX_CARRIER;
            }
            else
            {
                acmInfo->uartState &= ~((uint16_t)USB_DEVICE_CDC_UART_STATE_RX_CARRIER);
            }

            /* Indicates to DCE if DTE is present or not */
            acmInfo->dtePresent =
                (0U != (acmInfo->dteStatus & (uint8_t)USB_DEVICE_CDC_CONTROL_SIG_BITMAP_DTE_PRESENCE)) ? true : false;

            /* Initialize the serial state buffer */
            acmInfo->serialStateBuf[0] = NOTIF_REQUEST_TYPE;                /* bmRequestType */
            acmInfo->serialStateBuf[1] = USB_DEVICE_CDC_NOTIF_SERIAL_STATE; /* bNotification */
            acmInfo->serialStateBuf[2] = 0x00;                              /* wValue */
            acmInfo->serialStateBuf[3] = 0x00;
            acmInfo->serialStateBuf[4] = 0x00; /* wIndex */
            acmInfo->serialStateBuf[5] = 0x00;
            acmInfo->serialStateBuf[6] = UART_BITMAP_SIZE; /* wLength */
            acmInfo->serialStateBuf[7] = 0x00;
            /* Notifiy to host the line state */
            acmInfo->serialStateBuf[4] = (uint8_t)acmReqParam->interfaceIndex;
            /* Lower byte of UART BITMAP */
            uartBitmap    = (uint8_t *)&acmInfo->serialStateBuf[NOTIF_PACKET_SIZE + UART_BITMAP_SIZE - 2];
            uartBitmap[0] = (uint8_t)(acmInfo->uartState & 0xFFu);
            uartBitmap[1] = (uint8_t)((acmInfo->uartState >> 8) & 0xFFu);
            len           = (uint32_t)NOTIF_PACKET_SIZE + (uint32_t)UART_BITMAP_SIZE;
            if (0U == ((usb_device_cdc_acm_struct_t *)handle)->hasSentState)
            {
                error = USB_DeviceCdcAcmSend(handle, USB_CDC_VCOM_INTERRUPT_IN_ENDPOINT, acmInfo->serialStateBuf, len);
                if (kStatus_USB_Success != error)
                {
                    /* MISRA C-2012 Rule 17.2 */
                    /* (void)usb_echo("kUSB_DeviceCdcEventSetControlLineState error!"); */
                }
                ((usb_device_cdc_acm_struct_t *)handle)->hasSentState = 1;
            }

            /* Update status */
            if (0U != (acmInfo->dteStatus & (uint8_t)USB_DEVICE_CDC_CONTROL_SIG_BITMAP_CARRIER_ACTIVATION))
            {
                /*  To do: CARRIER_ACTIVATED */
            }
            else
            {
                /* To do: CARRIER_DEACTIVATED */
            }
            if (0U != (acmInfo->dteStatus & (uint8_t)USB_DEVICE_CDC_CONTROL_SIG_BITMAP_DTE_PRESENCE))
            {
                /* DTE_ACTIVATED */
                if (1U == serialUsbCdc->attach)
                {
                    serialUsbCdc->startTransactions = 1U;
                }
            }
            else
            {
                /* DTE_DEACTIVATED */
                if (1U == serialUsbCdc->attach)
                {
                    serialUsbCdc->startTransactions = 0U;
                }
            }
        }
        break;
        case kUSB_DeviceCdcEventSendBreak:
            break;
        default:; /* MISRA C-2012 Rule 16.4 */
            break;
    }

    return error;
}

/*!
 * @brief USB device callback function.
 *
 * This function handles the usb device specific requests.
 *
 * @param handle          The USB device handle.
 * @param event           The USB device event type.
 * @param param           The parameter of the device specific request.
 *
 * @return A USB error code or kStatus_USB_Success.
 */
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    usb_status_t error = kStatus_USB_InvalidRequest;
    uint16_t *temp16   = (uint16_t *)param;
    uint8_t *temp8     = (uint8_t *)param;
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
    usb_status_t usbState;
#endif

    serialUsbCdc = USB_DeviceGetInstanceFromDeviceHandle(s_UsbCdcHead, handle);
    if (NULL == serialUsbCdc)
    {
        return kStatus_USB_InvalidRequest;
    }

    switch ((usb_device_event_t)event)
    {
        case kUSB_DeviceEventBusReset:
        {
            serialUsbCdc->attach            = 0U;
            serialUsbCdc->startTransactions = 0U;
            error                           = kStatus_USB_Success;
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)) || \
    (defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U))
            /* Get USB speed to configure the device, including max packet size and interval of the endpoints. */
            usbState = USB_DeviceClassGetSpeed(serialUsbCdc->instance, &serialUsbCdc->speed);
            (void)usbState; /* Fix MISRA C-2012 Rule 2.2: declared but never referenced */
            if (kStatus_USB_Success == usbState)
            {
                (void)USB_DeviceSetSpeed(handle, serialUsbCdc->speed);
            }
#endif
        }
        break;
        case kUSB_DeviceEventSetConfiguration:
            if (NULL != param)
            {
                serialUsbCdc->attach               = 1U;
                serialUsbCdc->currentConfiguration = *temp8;
                if ((uint8_t)USB_CDC_VCOM_CONFIGURE_INDEX == (*temp8))
                {
                    /* Schedule buffer for receive */
                    (void)Serial_UsbCdcRead(serialUsbCdc, s_currRecvBuf,
                                            g_UsbDeviceCdcVcomDicEndpoints[0].maxPacketSize);
                    error = kStatus_USB_Success;
                }
            }
            break;
        case kUSB_DeviceEventSetInterface:
            if (0U != serialUsbCdc->attach)
            {
                uint8_t interface        = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
                uint8_t alternateSetting = (uint8_t)(*temp16 & 0x00FFU);
                if (interface < (uint8_t)USB_CDC_VCOM_INTERFACE_COUNT)
                {
                    serialUsbCdc->currentInterfaceAlternateSetting[interface] = alternateSetting;
                    error                                                     = kStatus_USB_Success;
                }
            }
            break;
        case kUSB_DeviceEventGetConfiguration:
            break;
        case kUSB_DeviceEventGetInterface:
            break;
        case kUSB_DeviceEventGetDeviceDescriptor:
            if (NULL != param)
            {
                error = USB_DeviceGetDeviceDescriptor(handle, (usb_device_get_device_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetConfigurationDescriptor:
            if (NULL != param)
            {
                error = USB_DeviceGetConfigurationDescriptor(handle,
                                                             (usb_device_get_configuration_descriptor_struct_t *)param);
            }
            break;
        case kUSB_DeviceEventGetStringDescriptor:
            if (NULL != param)
            {
                /* Get device string descriptor request */
                error = USB_DeviceGetStringDescriptor(handle, (usb_device_get_string_descriptor_struct_t *)param);
            }
            break;
        default:
            /* MISRA C-2012 Rule 16.4 */
            break;
    }

    return error;
}

#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U))
void USB_OTG2_IRQHandler(void);
void USB_OTG2_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (NULL != serialUsbCdc)
    {
        if ((uint8_t)kSerialManager_UsbControllerEhci1 == serialUsbCdc->instance)
        {
            USB_DeviceEhciIsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
}
#endif

#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
void USBHS_IRQHandler(void);
void USBHS_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (NULL != serialUsbCdc)
    {
        if ((uint8_t)kSerialManager_UsbControllerEhci0 == serialUsbCdc->instance)
        {
            USB_DeviceEhciIsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
    SDK_ISR_EXIT_BARRIER;
}
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 1U)
#if defined(FSL_FEATURE_USBHS_EHCI_COUNT) && (FSL_FEATURE_USBHS_EHCI_COUNT > 1U)
void USB1_IRQHandler(void);
void USB1_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (serialUsbCdc)
    {
        if ((kSerialManager_UsbControllerEhci1 == serialUsbCdc->instance))
        {
            USB_DeviceEhciIsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
    SDK_ISR_EXIT_BARRIER;
}
#endif
#endif
#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
void USB0_IRQHandler(void);
void USB0_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (NULL != serialUsbCdc)
    {
        if (((uint8_t)kSerialManager_UsbControllerKhci0 == serialUsbCdc->instance))
        {
            USB_DeviceKhciIsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
    SDK_ISR_EXIT_BARRIER;
}
#endif
#if defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U)
void USB0_IRQHandler(void);
void USB0_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (serialUsbCdc)
    {
        if ((kSerialManager_UsbControllerLpcIp3511Fs0 == serialUsbCdc->instance))
        {
            USB_DeviceLpcIp3511IsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
    SDK_ISR_EXIT_BARRIER;
}
#endif
#if defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)
void USB1_IRQHandler(void);
void USB1_IRQHandler(void)
{
    serial_usb_cdc_state_t *serialUsbCdc = s_UsbCdcHead;

    while (NULL != serialUsbCdc)
    {
        if (((uint8_t)kSerialManager_UsbControllerLpcIp3511Hs0 == serialUsbCdc->instance))
        {
            USB_DeviceLpcIp3511IsrFunction(serialUsbCdc->deviceHandle);
        }
        serialUsbCdc = serialUsbCdc->next;
    }
    SDK_ISR_EXIT_BARRIER;
}
#endif

static void USB_DeviceIsrEnable(serial_usb_cdc_state_t *serialUsbCdc)
{
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    IRQn_Type usbDeviceEhciIrq[] = USBHS_IRQS;
    serialUsbCdc->irqNumber =
        (uint8_t)usbDeviceEhciIrq[serialUsbCdc->instance - (uint8_t)kSerialManager_UsbControllerEhci0];
#endif

#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    IRQn_Type usbDeviceKhciIrq[] = USB_IRQS;
    serialUsbCdc->irqNumber =
        (uint8_t)usbDeviceKhciIrq[serialUsbCdc->instance - (uint8_t)kSerialManager_UsbControllerKhci0];
#endif

#if defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U)
    IRQn_Type usbDeviceIP3511Irq[] = USB_IRQS;
    serialUsbCdc->irqNumber =
        (uint8_t)usbDeviceIP3511Irq[serialUsbCdc->instance - (uint8_t)kSerialManager_UsbControllerLpcIp3511Fs0];
#endif

#if defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)
    IRQn_Type usbDeviceIP3511Irq[] = USBHSD_IRQS;
    serialUsbCdc->irqNumber =
        (uint8_t)usbDeviceIP3511Irq[serialUsbCdc->instance - (uint8_t)kSerialManager_UsbControllerLpcIp3511Hs0];
#endif

/* Install isr, set priority, and enable IRQ. */
#if defined(__GIC_PRIO_BITS)
    GIC_SetPriority((IRQn_Type)serialUsbCdc->irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
#else
    NVIC_SetPriority((IRQn_Type)serialUsbCdc->irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
#endif
    (void)EnableIRQ((IRQn_Type)serialUsbCdc->irqNumber);
}

serial_manager_status_t Serial_UsbCdcInit(serial_handle_t serialHandle, void *config)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    serial_port_usb_cdc_config_t *usbCdcConfig;
    usb_status_t usbState;

    assert(config);
    assert(serialHandle);
    assert(SERIAL_PORT_USB_CDC_HANDLE_SIZE >= sizeof(serial_usb_cdc_state_t));

#if (defined(FSL_FEATURE_SOC_SYSMPU_COUNT) && (FSL_FEATURE_SOC_SYSMPU_COUNT > 0U))
    SYSMPU_Enable(SYSMPU, (bool)false);
#endif /* FSL_FEATURE_SOC_SYSMPU_COUNT */

    usbCdcConfig = (serial_port_usb_cdc_config_t *)config;
    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    serialUsbCdc->speed    = USB_SPEED_FULL;
    serialUsbCdc->instance = (uint8_t)usbCdcConfig->controllerIndex;

    usbState = USB_DeviceClassInit(serialUsbCdc->instance, &s_cdcAcmConfigList, &serialUsbCdc->deviceHandle);
    if (kStatus_USB_Success != usbState)
    {
        return kStatus_SerialManager_Error;
    }
    else
    {
        serialUsbCdc->cdcAcmHandle = s_cdcAcmConfigList.config->classHandle;
    }

    (void)USB_DeviceAddItem(&s_UsbCdcHead, serialUsbCdc);

    USB_DeviceIsrEnable(serialUsbCdc);

    /*Add one delay here to make the DP pull down long enough to allow host to detect the previous disconnection.*/
    SDK_DelayAtLeastUs(5000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    (void)USB_DeviceRun(serialUsbCdc->deviceHandle);

    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcDeinit(serial_handle_t serialHandle)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    usb_status_t usbState;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    usbState = USB_DeviceClassDeinit(serialUsbCdc->instance);
    if (kStatus_USB_Success != usbState)
    {
        return kStatus_SerialManager_Error;
    }
    else
    {
        (void)USB_DeviceRemoveItem(&s_UsbCdcHead, serialUsbCdc);
    }

    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcWrite(serial_handle_t serialHandle, uint8_t *buffer, uint32_t length)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    uint32_t needToPrime = 0;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    if (0U != serialUsbCdc->tx.busy)
    {
        return kStatus_SerialManager_Busy;
    }

#if (defined(USB_CDC_SERIAL_MANAGER_RUN_NO_HOST) && (USB_CDC_SERIAL_MANAGER_RUN_NO_HOST == 1))
    /* Prevents SerialManager_Write from blocking when no USB Host is attached */
    if ((serialUsbCdc->attach == 0U))
    {
        return kStatus_SerialManager_NotConnected;
    }

    /* Prevents SerialManager_Write from blocking when USB Host is attached but CDC terminal is closed */
    if ((serialUsbCdc->attach == 1U) && (serialUsbCdc->startTransactions == 0U))
    {
        return kStatus_SerialManager_NotConnected;
    }
#endif /* USB_CDC_SERIAL_MANAGER_RUN_NO_HOST == 1 */

    serialUsbCdc->tx.busy          = 1U;
    serialUsbCdc->tx.waiting4Prime = 0U;

    serialUsbCdc->tx.buffer = buffer;
    serialUsbCdc->tx.length = length;

    if (0U != serialUsbCdc->attach)
    {
        needToPrime = 1U;
    }

    if (0U != needToPrime)
    {
        if (kStatus_USB_Success !=
            USB_DeviceCdcAcmSend(serialUsbCdc->cdcAcmHandle, USB_CDC_VCOM_BULK_IN_ENDPOINT, buffer, length))
        {
            serialUsbCdc->tx.busy = 0U;
            return kStatus_SerialManager_Error;
        }
    }
    else
    {
        serialUsbCdc->tx.waiting4Prime = 1;
    }

    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcRead(serial_handle_t serialHandle, uint8_t *buffer, uint32_t length)
{
    serial_usb_cdc_state_t *serialUsbCdc;
    uint8_t *primeBuffer;
    uint32_t primeLength;
    uint32_t regPrimask;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    if (0U == serialUsbCdc->attach)
    {
        return kStatus_SerialManager_Error;
    }

    regPrimask = DisableGlobalIRQ();
    if (0U != serialUsbCdc->rx.busy)
    {
        EnableGlobalIRQ(regPrimask);
        return kStatus_SerialManager_Busy;
    }
    serialUsbCdc->rx.busy = 1U;
    EnableGlobalIRQ(regPrimask);

    if (length < g_UsbDeviceCdcVcomDicEndpoints[0].maxPacketSize)
    {
        serialUsbCdc->rx.busy = 0U;
        return kStatus_SerialManager_Error;
    }

    if (NULL == buffer)
    {
        primeBuffer = s_currRecvBuf;
        primeLength = g_UsbDeviceCdcVcomDicEndpoints[0].maxPacketSize;
    }
    else
    {
        primeBuffer = buffer;
        primeLength = length;
    }
    /* Schedule buffer for next receive event */

    if (kStatus_USB_Success !=
        USB_DeviceCdcAcmRecv(serialUsbCdc->cdcAcmHandle, USB_CDC_VCOM_BULK_OUT_ENDPOINT, primeBuffer, primeLength))
    {
        serialUsbCdc->rx.busy = 0U;
        return kStatus_SerialManager_Error;
    }

    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcCancelWrite(serial_handle_t serialHandle)
{
    serial_usb_cdc_state_t *serialUsbCdc;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;
    (void)USB_DeviceCancel(serialUsbCdc->deviceHandle, (USB_IN << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT) |
                                                           (uint8_t)USB_CDC_VCOM_BULK_IN_ENDPOINT);
    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcInstallTxCallback(serial_handle_t serialHandle,
                                                       serial_manager_callback_t callback,
                                                       void *callbackParam)
{
    serial_usb_cdc_state_t *serialUsbCdc;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    serialUsbCdc->tx.callback      = callback;
    serialUsbCdc->tx.callbackParam = callbackParam;

    return kStatus_SerialManager_Success;
}

serial_manager_status_t Serial_UsbCdcInstallRxCallback(serial_handle_t serialHandle,
                                                       serial_manager_callback_t callback,
                                                       void *callbackParam)
{
    serial_usb_cdc_state_t *serialUsbCdc;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

    serialUsbCdc->rx.callback      = callback;
    serialUsbCdc->rx.callbackParam = callbackParam;

    return kStatus_SerialManager_Success;
}

void Serial_UsbCdcIsrFunction(serial_handle_t serialHandle)
{
    serial_usb_cdc_state_t *serialUsbCdc;

    assert(serialHandle);

    serialUsbCdc = (serial_usb_cdc_state_t *)serialHandle;

#if 0
    DisableIRQ((IRQn_Type)serialUsbCdc->irqNumber);
#endif
#if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0)
    if (((uint8_t)kSerialManager_UsbControllerEhci0 == serialUsbCdc->instance) ||
        ((uint8_t)kSerialManager_UsbControllerEhci1 == serialUsbCdc->instance))
    {
        USB_DeviceEhciIsrFunction(serialUsbCdc->deviceHandle);
    }
#endif
#if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0)
    if (((uint8_t)kSerialManager_UsbControllerKhci0 == serialUsbCdc->instance) ||
        ((uint8_t)kSerialManager_UsbControllerKhci1 == serialUsbCdc->instance))
    {
        USB_DeviceKhciIsrFunction(serialUsbCdc->deviceHandle);
    }
#endif
#if defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U)
    if (((uint8_t)kSerialManager_UsbControllerLpcIp3511Fs0 == serialUsbCdc->instance) ||
        ((uint8_t)kSerialManager_UsbControllerLpcIp3511Fs1 == serialUsbCdc->instance))
    {
        USB_DeviceLpcIp3511IsrFunction(serialUsbCdc->deviceHandle);
    }
#endif

#if defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)
    if (((uint8_t)kSerialManager_UsbControllerLpcIp3511Hs0 == serialUsbCdc->instance) ||
        ((uint8_t)kSerialManager_UsbControllerLpcIp3511Hs1 == serialUsbCdc->instance))
    {
        USB_DeviceLpcIp3511IsrFunction(serialUsbCdc->deviceHandle);
    }
#endif
#if 0
    EnableIRQ((IRQn_Type)serialUsbCdc->irqNumber);
#endif
}
#endif
