/**
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __USB_DEVICE_CDC_ECM_H__
#define __USB_DEVICE_CDC_ECM_H__

/*!
 * @addtogroup cdc_ecm
 * @{
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define USB_DEVICE_CDC_COMM_CLASS_CODE   (0x02U)       /*!< The CDC communication class code. */
#define USB_DEVICE_CDC_DATA_CLASS_CODE   (0x0AU)       /*!< The CDC data class code. */
#define USB_DEVICE_CDC_ECM_CLASS_CODE    (0x02U)       /*!< The CDC ECM class code. */
#define USB_DEVICE_CDC_ECM_SUBCLASS_CODE (0x06U)       /*!< The CDC ECM sub class code. */
#define USB_DEVICE_CDC_ECM_PROTOCOL_CODE (0x00U)       /*!< The CDC ECM protocol code. */

#define USB_DEVICE_CDC_NETWORK_CONNECTION      (0x00U) /*!< The CDC class notify code for NETWORK_CONNECTION. */
#define USB_DEVICE_CDC_CONNECTION_SPEED_CHANGE (0x2AU) /*!< The CDC class notify code for CONNECTION_SPEED_CHANGE. */
#define USB_DEVICE_CDC_ECM_SET_ETHERNET_MULTICAST_FILTER \
    (0x40U) /*!< The CDC class request code for SET_ETHERNET_MULTICAST_FILTERS. */
#define USB_DEVICE_CDC_ECM_SET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER \
    (0x41U) /*!< The CDC class request code for SET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER. */
#define USB_DEVICE_CDC_ECM_GET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER \
    (0x42U) /*!< The CDC class request code for GET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER. */
#define USB_DEVICE_CDC_ECM_SET_ETHERNET_PACKET_FILTER \
    (0x43U) /*!< The CDC class request code for SET_ETHERNET_PACKET_FILTER. */
#define USB_DEVICE_CDC_ECM_GET_ETHERNET_STATISTIC                       \
    (0x44U) /*!< The CDC class request code for GET_ETHERNET_STATISTIC. \
             */

#define USB_DEVICE_CDC_ECM_PACKET_TYPE_MULTICAST_MASK \
    (1U << 4) /*!< The CDC ECM ethernet packet filter bitmap value of PACKET_TYPE_MULTICAST. */
#define USB_DEVICE_CDC_ECM_PACKET_TYPE_BROADCAST_MASK \
    (1U << 3) /*!< The CDC ECM ethernet packet filter bitmap value of PACKET_TYPE_BROADCAST. */
#define USB_DEVICE_CDC_ECM_PACKET_TYPE_DIRECTED_MASK \
    (1U << 2) /*!< The CDC ECM ethernet packet filter bitmap value of PACKET_TYPE_DIRECTED. */
#define USB_DEVICE_CDC_ECM_PACKET_TYPE_ALL_MULTICAST_MASK \
    (1U << 1) /*!< The CDC ECM ethernet packet filter bitmap value of PACKET_TYPE_ALL_MULTICAST. */
#define USB_DEVICE_CDC_ECM_PACKET_TYPE_PROMISCUOUS_MASK \
    (1U << 0) /*!< The CDC ECM ethernet packet filter bitmap value of PACKET_TYPE_PROMISCUOUS. */

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*! @brief Definition of pipe structure. */
typedef struct _usb_device_cdc_ecm_pipe
{
    uint8_t ep;              /*!< The endpoint number of the pipe. */
    uint8_t isBusy;          /*!< 1: The pipe is transferring packet, 0: The pipe is idle. */
    uint8_t *pipeDataBuffer; /*!< pipe data buffer backup when stall. */
    uint32_t pipeDataLen;    /*!< pipe data length backup when stall.  */
    uint8_t pipeStall;       /*!< 1: The pipe is stall, 0: The pipe is not stall. */
} usb_device_cdc_ecm_pipe_t;

/*! @brief Definition of structure for CDC ECM device. */
typedef struct _usb_device_cdc_ecm_struct
{
    usb_device_handle handle;                           /*!< The handle of the USB device. */
    usb_device_class_config_struct_t *config;           /*!< The class configure structure. */
    usb_device_interface_struct_t *commInterfaceHandle; /*!< The CDC communication interface handle. */
    usb_device_interface_struct_t *dataInterfaceHandle; /*!< The CDC data interface handle. */
    usb_device_cdc_ecm_pipe_t bulkIn;                   /*!< The bulk in pipe for sending packet to host. */
    usb_device_cdc_ecm_pipe_t bulkOut;                  /*!< The bulk out pipe for receiving packet from host. */
    usb_device_cdc_ecm_pipe_t interruptIn; /*!< The interrupt in pipe for notifying the device state to host. */
    uint8_t configurationValue;            /*!< The current configuration value. */
    uint8_t interfaceNumber;               /*!< The current interface number. */
    uint8_t alternate;                     /*!< The alternate setting value of the interface. */
} usb_device_cdc_ecm_struct_t;

/*! @brief Definition of CDC class event. */
typedef enum _usb_device_cdc_ecm_event
{
    kUSB_DeviceCdcEcmEventSendResponse,   /*!< This event indicates the bulk send transfer is complete or cancelled etc.
                                           */
    kUSB_DeviceCdcEcmEventRecvResponse,   /*!< This event indicates the bulk receive transfer is complete or cancelled
                                             etc. */
    kUSB_DeviceCdcEcmEventNotifyResponse, /*!< This event indicates the interrupt in transfer is complete or cancelled
                                             etc. */
    kUSB_DeviceCdcEcmEventSetEthernetMulticastFilters,             /*!< This event indicates the device received the
                                                                      SET_ETHERNET_MULTICAST_FILTERS request. */
    kUSB_DeviceCdcEcmEventSetEthernetPowerManagementPatternFilter, /*!< This event indicates the device received the
                                                                      SET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER
                                                                      request. */
    kUSB_DeviceCdcEcmEventGetEthernetPowerManagementPatternFilter, /*!< This event indicates the device received the
                                                                      GET_ETHERNET_POWER_MANAGEMENT_PATTERN_FILTER
                                                                      request. */
    kUSB_DeviceCdcEcmEventSetEthernetPacketFilter,                 /*!< This event indicates the device received the
                                                                      SET_ETHERNET_PACKET_FILTER request. */
    kUSB_DeviceCdcEcmEventGetEthernetStatistic, /*!< This event indicates the device received the GET_ETHERNET_STATISTIC
                                                   request. */
} usb_device_cdc_ecm_event_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name USB CDC ECM Class Driver
 * @{
 */

/*!
 * @brief Initializes the USB CDC ECM class.
 *
 * This function obtains a USB device handle according to the controller ID, initializes the CDC ECM class
 * with the class configure parameters and creates the mutex for each pipe.
 *
 * @param controllerId The ID of the controller.
 * @param config The user configuration structure of type usb_device_class_config_struct_t. The user
 *  populates the members of this structure and passes the pointer of this structure
 *  into this function.
 * @param handle  It is out parameter. The class handle of the CDC ECM class.
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success The CDC ECM class is initialized successfully.
 * @retval kStatus_USB_Busy No CDC ECM device handle available for allocation.
 * @retval kStatus_USB_AllocFail The CDC ECM device handle allocation failure.
 * @retval kStatus_USB_InvalidParameter The USB device handle allocation failure.
 */
usb_status_t USB_DeviceCdcEcmInit(uint8_t controllerId,
                                  usb_device_class_config_struct_t *config,
                                  class_handle_t *handle);

/*!
 * @brief Deinitializes the USB CDC ECM class.
 *
 * This function destroys the mutex for each pipe, deinitializes each endpoint of the CDC ECM class and frees
 * the CDC ECM class handle.
 *
 * @param handle The class handle of the CDC ECM class.
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success The CDC ECM class is de-initialized successfully.
 * @retval kStatus_USB_Error The endpoint deinitialization failure.
 * @retval kStatus_USB_InvalidHandle The CDC ECM device handle or the CDC ECM class handle is invalid.
 * @retval kStatus_USB_InvalidParameter The endpoint number of the CDC ECM class handle is invalid.
 */
usb_status_t USB_DeviceCdcEcmDeinit(class_handle_t handle);

/*!
 * @brief Primes the endpoint to send packet to host.
 *
 * This function checks whether the endpoint is sending packet, then it primes the endpoint
 * with the buffer address and the buffer length if the pipe is not busy. Otherwise, it ignores this transfer by
 * returning an error code.
 *
 * @param handle The class handle of the CDC ECM class.
 * @param ep The endpoint number of the transfer.
 * @param buffer The pointer to the buffer to be transferred.
 * @param length The length of the buffer to be transferred.
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success Prime to send packet successfully.
 * @retval kStatus_USB_Busy The endpoint is busy in transferring.
 * @retval kStatus_USB_InvalidHandle The CDC ECM device handle or the CDC ECM class handle is invalid.
 * @retval kStatus_USB_ControllerNotFound The controller interface is invalid.
 *
 * @note The function can only be called in the same context.
 */
usb_status_t USB_DeviceCdcEcmSend(class_handle_t handle, uint8_t ep, uint8_t *buffer, uint32_t length);

/*!
 * @brief Primes the endpoint to receive packet from host.
 *
 * This function checks whether the endpoint is receiving packet, then it primes the endpoint
 * with the buffer address and the buffer length if the pipe is not busy. Otherwise, it ignores this transfer by
 * returning an error code.
 *
 * @param handle The class handle of the CDC ECM class.
 * @param ep The endpoint number of the transfer.
 * @param buffer The pointer to the buffer to be transferred.
 * @param length The length of the buffer to be transferred.
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success Prime to receive packet successfully.
 * @retval kStatus_USB_Busy The endpoint is busy in transferring.
 * @retval kStatus_USB_InvalidHandle The CDC ECM device handle or the CDC ECM class handle is invalid.
 * @retval kStatus_USB_ControllerNotFound The controller interface is invalid.
 *
 * @note The function can only be called in the same context.
 */
usb_status_t USB_DeviceCdcEcmRecv(class_handle_t handle, uint8_t ep, uint8_t *buffer, uint32_t length);

/*!
 * @brief Handles the CDC ECM class event.
 *
 * This function responds to various events including the common device events and the class-specific events.
 * For class-specific events, it calls the class callback defined in the application to deal with the class-specific
 * event.
 *
 * @param handle The class handle of the CDC ECM class.
 * @param event The event type.
 * @param param The class handle of the CDC ECM class.
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success The CDC ECM class is de-initialized successfully.
 * @retval kStatus_USB_Error The configure structure of the CDC ECM class handle is invalid.
 * @retval kStatus_USB_InvalidHandle The CDC ECM device handle or the CDC ECM class handle is invalid.
 * @retval Others The error code returned by class callback in application.
 */
usb_status_t USB_DeviceCdcEcmEvent(void *handle, uint32_t event, void *param);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif
