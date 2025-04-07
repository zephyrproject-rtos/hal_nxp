/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* This file is used in Zephyr */

#ifndef _USB_HOST_MCUX_DRV_PORT_H_
#define _USB_HOST_MCUX_DRV_PORT_H_

#include "usb.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief USB host controller handle type define */
typedef void *usb_host_controller_handle;

/*! @brief USB host pipe handle type define */
typedef void *usb_host_pipe_handle;

/*! @brief USB host configuration handle type define */
typedef void *usb_host_configuration_handle;

/*! @brief USB host controller control code */
typedef enum _usb_host_controller_control {
	kUSB_HostCancelTransfer = 1U,          /*!< Cancel transfer code */
	kUSB_HostBusControl,                   /*!< Bus control code */
	kUSB_HostGetFrameNumber,               /*!< Get frame number code */
	kUSB_HostUpdateControlEndpointAddress, /*!< Update control endpoint address */
	kUSB_HostUpdateControlPacketSize,      /*!< Update control endpoint maximum  packet size */
	kUSB_HostPortAttachDisable,            /*!< Disable the port attach event */
	kUSB_HostPortAttachEnable,             /*!< Enable the port attach event */
	kUSB_HostL1Config,                     /*!< L1 suspend Bus control code */
	kUSB_HostSetChargerType,               /*!< set charger type */
#if ((defined USB_HOST_CONFIG_COMPLIANCE_TEST) && (USB_HOST_CONFIG_COMPLIANCE_TEST))
	kUSB_HostTestModeInit,                 /*!< initialize charger type */
#endif
} usb_host_controller_control_t;

/*! @brief USB host controller bus control code */
typedef enum _usb_host_bus_control {
	kUSB_HostBusReset = 1U,    /*!< Reset bus */
	kUSB_HostBusRestart,       /*!< Restart bus */
	kUSB_HostBusEnableAttach,  /*!< Enable attach */
	kUSB_HostBusDisableAttach, /*!< Disable attach */
	kUSB_HostBusSuspend,       /*!< Suspend BUS */
	kUSB_HostBusResume,        /*!< Resume BUS */
	kUSB_HostBusL1SuspendInit, /*!< L1 Suspend BUS */
	kUSB_HostBusL1Sleep,       /*!< L1 Suspend BUS */
	kUSB_HostBusL1Resume,      /*!< L1 Resume BUS */
} usb_host_bus_control_t;

/*! @brief USB host device information code */
typedef enum _usb_host_dev_info {
	kUSB_HostGetDeviceAddress = 1U, /*!< Device's address */
	kUSB_HostGetDeviceHubNumber,    /*!< Device's first hub address */
	kUSB_HostGetDevicePortNumber,   /*!< Device's first hub port number */
	kUSB_HostGetDeviceSpeed,        /*!< Device's speed */
	kUSB_HostGetDeviceHSHubNumber,  /*!< Device's first high-speed hub address */
	kUSB_HostGetDeviceHSHubPort,    /*!< Device's first high-speed hub number */
	kUSB_HostGetDeviceLevel,        /*!< Device's hub level */
	kUSB_HostGetHostHandle,         /*!< Device's host handle */
	kUSB_HostGetDeviceControlPipe,  /*!< Device's control pipe handle */
	kUSB_HostGetDevicePID,          /*!< Device's PID */
	kUSB_HostGetDeviceVID,          /*!< Device's VID */
	kUSB_HostGetHubThinkTime,       /*!< Device's hub total think time */
	kUSB_HostGetDeviceConfigIndex,  /*!< Device's running zero-based config index */
	kUSB_HostGetConfigurationDes,   /*!< Device's configuration descriptor pointer */
	kUSB_HostGetConfigurationLength,/*!< Device's configuration descriptor pointer */
} usb_host_dev_info_t;

struct _usb_host_transfer;
/*!
 * @brief Host stack inner transfer callback function typedef.
 *
 * This callback function is used to notify the upper layer the result of a transfer.
 * This callback pointer is passed when initializing the structure usb_host_transfer_t.
 *
 * @param param	 The parameter pointer, which is passed when calling the send/receive APIs.
 * @param transfer  The transfer information; See the structure usb_host_transfer_t.
 * @param status	A USB error code or kStatus_USB_Success.
 */
typedef void (*host_inner_transfer_callback_t)(void *param,
		struct _usb_host_transfer *transfer, usb_status_t status);

/*!
 * @brief Controller driver callback function typedef.
 *
 * This callback function is used to notify upper layer suspend related event.
 * This callback pointer is passed when initializing the host.
 *
 * @param deviceHandle		   The device handle, which indicates the attached device.
 * @param configurationHandle	The configuration handle contains the attached device's
 *				configuration information. It is not used in Zephyr environment.
 * @param event_code		   The callback event code; See the enumeration host_event_t.
 *
 * @return A USB error code or kStatus_USB_Success.
 * @retval kStatus_USB_Success	   Application handles the attached device successfully.
 * @retval kStatus_USB_NotSupported  Application don't support the attached device.
 * @retval kStatus_USB_Error		 Application handles the attached device falsely.
 */
typedef usb_status_t (*host_callback_t)(usb_device_handle deviceHandle,
				usb_host_configuration_handle configurationHandle,
				uint32_t eventCode);

/*! @brief USB host pipe information structure for opening pipe */
typedef struct _usb_host_pipe_init {
	void *devInstance;	/*!< Device instance handle*/
	uint16_t nakCount;	/*!< Maximum NAK retry count. MUST be zero for interrupt*/
	uint16_t maxPacketSize;	/*!< Pipe's maximum packet size*/
	uint8_t interval;	/*!< Pipe's interval*/
	uint8_t endpointAddress;/*!< Endpoint address*/
	uint8_t direction;	/*!< Endpoint direction*/
	uint8_t pipeType;	/*!< Endpoint type, the value is USB_ENDPOINT_INTERRUPT,
				 * USB_ENDPOINT_CONTROL, USB_ENDPOINT_ISOCHRONOUS,
				 * USB_ENDPOINT_BULK
				 */
	uint8_t numberPerUframe;/*!< Transaction number for each micro-frame*/
} usb_host_pipe_init_t;

/*! @brief USB host pipe common structure */
typedef struct _usb_host_pipe {
	struct _usb_host_pipe *next;	/*!< Link the idle pipes*/
	usb_device_handle deviceHandle; /*!< This pipe's device's handle*/
	uint16_t currentCount;		/*!< For KHCI transfer*/
	uint16_t nakCount;		/*!< Maximum NAK count*/
	uint16_t maxPacketSize;		/*!< Maximum packet size*/
	uint16_t interval;		/*!< FS/LS: frame unit; HS: micro-frame unit*/
	uint8_t open;			/*!< 0 - closed, 1 - open*/
	uint8_t nextdata01;		/*!< Data toggle*/
	uint8_t endpointAddress;	/*!< Endpoint address*/
	uint8_t direction;		/*!< Pipe direction*/
	uint8_t pipeType;		/*!< Pipe type, for example USB_ENDPOINT_BULK*/
	uint8_t numberPerUframe;	/*!< Transaction number per micro-frame*/
	uint8_t update_addr;		/*!< update control ep's addr, Zephyr use it*/
} usb_host_pipe_t;

/*! @brief USB host transfer structure */
typedef struct _usb_host_transfer {
	struct _usb_host_transfer *next;		/*!< The next transfer structure*/
	uint8_t *transferBuffer;			/*!< Transfer data buffer*/
	uint32_t transferLength;			/*!< Transfer data length*/
	uint32_t transferSofar;	/*!< Length transferred so far*/
	host_inner_transfer_callback_t callbackFn; /*!< Transfer callback function*/
	void *callbackParam;				/*!< Transfer callback parameter*/
	usb_host_pipe_t *transferPipe;			/*!< Transfer pipe pointer*/
	usb_setup_struct_t *setupPacket;		/*!< Set up packet buffer*/
	/*! Transfer direction; it's values are USB_OUT or USB_IN */
	uint8_t direction;
	uint8_t setupStatus;				/*!< Set up the transfer status*/
	union {
		uint32_t unitHead;			/*!< xTD head for this transfer*/
		int32_t transferResult;			/*!< KHCI transfer result */
	} union1;

	union {
		uint32_t unitTail;			/*!<xTD tail for this transfer*/
		uint32_t frame;				/*!< KHCI transfer frame number */
	} union2;

#if USB_HOST_CONFIG_KHCI
	uint16_t nakTimeout;				/*!< KHCI transfer NAK timeout */
	uint16_t retry;					/*!< KHCI transfer retry */
#endif
	void *uhc_xfer;
} usb_host_transfer_t;

/*! @brief Cancel transfer parameter structure */
typedef struct _usb_host_cancel_param {
	usb_host_pipe_handle pipeHandle;	/*!< Canceling pipe handle*/
	usb_host_transfer_t *transfer;		/*!< Canceling transfer*/
} usb_host_cancel_param_t;

/*! @brief USB host controller interface structure */
typedef struct _usb_host_controller_interface {
	/*! Create a controller instance function prototype*/
	usb_status_t (*controllerCreate)(
		uint8_t controllerId,
		usb_host_handle upperLayerHandle,
		usb_host_controller_handle *controllerHandle);
	/*! Destroy a controller instance function prototype*/
	usb_status_t (*controllerDestory)(
		usb_host_controller_handle controllerHandle);
	/*! Open a controller pipe function prototype*/
	usb_status_t (*controllerOpenPipe)(usb_host_controller_handle controllerHandle,
				usb_host_pipe_handle *pipeHandle,
				usb_host_pipe_init_t *pipeInit);
	/*! Close a controller pipe function prototype*/
	usb_status_t (*controllerClosePipe)(
		usb_host_controller_handle controllerHandle,
		usb_host_pipe_handle pipeHandle);
	/*! Write data to a pipe function prototype*/
	usb_status_t (*controllerWritePipe)(usb_host_controller_handle controllerHandle,
				usb_host_pipe_handle pipeHandle,
				usb_host_transfer_t *transfer);
	/*! Read data from a pipe function prototype*/
	usb_status_t (*controllerReadPipe)(usb_host_controller_handle controllerHandle,
				usb_host_pipe_handle pipeHandle,
				usb_host_transfer_t *transfer);
	/*! Control a controller function prototype*/
	usb_status_t (*controllerIoctl)(usb_host_controller_handle controllerHandle,
				uint32_t ioctlEvent,
				void *ioctlParam);
} usb_host_controller_interface_t;

/*! @brief USB host instance structure */
typedef struct _usb_host_instance {
	void *controllerHandle;		/*!< The low level controller handle*/
	host_callback_t deviceCallback;	/*!< Device attach/detach callback*/
} usb_host_instance_t;

/*!
 * @brief Controller driver calls this function when device detaches.
 *
 * @param hostHandle   Host instance handle.
 * @param hubNumber    Device hub no. root device's hub no. is 0.
 * @param portNumber   Device port no. root device's port no. is 0.
 *
 * @return kStatus_USB_Success or error codes.
 */
usb_status_t USB_HostDetachDevice(usb_host_handle hostHandle, uint8_t hubNumber,
					uint8_t portNumber);

/*!
 * @brief Controller driver calls this function when device attach.
 *
 * @param hostHandle    Host instance handle.
 * @param speed         Device speed.
 * @param hubNumber     Device hub no. root device's hub no. is 0.
 * @param portNumber    Device port no. root device's port no. is 0.
 * @param level         Device level. root device's level is 1.
 * @param deviceHandle  Return device handle.
 *
 * @return kStatus_USB_Success or error codes.
 */
usb_status_t USB_HostAttachDevice(usb_host_handle hostHandle,
				uint8_t speed,
				uint8_t hubNumber,
				uint8_t portNumber,
				uint8_t level,
				usb_device_handle *deviceHandle);

/*!
 * @brief Controller driver calls this function to get the device information.
 *
 * This function gets the device information.
 *
 * @param[in] deviceHandle   Removing device handle.
 * @param[in] infoCode       See the enumeration host_dev_info_t.
 * @param[out] infoValue     Return the information value.
 *
 * @retval kStatus_USB_Success           Close successfully.
 * @retval kStatus_USB_InvalidParameter  The deviceHandle or info_value is a NULL pointer.
 * @retval kStatus_USB_Error             The info_code is not the host_dev_info_t value.
 */
usb_status_t USB_HostHelperGetPeripheralInformation(usb_device_handle deviceHandle,
				uint32_t infoCode,
				uint32_t *infoValue);

#if (defined(USB_HOST_CONFIG_EHCI) && (USB_HOST_CONFIG_EHCI > 0U))
/*!
 * @brief Device EHCI ISR function.
 *
 * The function is the EHCI interrupt service routine.
 *
 * @param[in] hostHandle The host handle.
 */
void USB_HostEhciIsrFunction(void *hostHandle);

/*!
 * @brief EHCI task function.
 *
 * The function is used to handle the EHCI controller message.
 * In the bare metal environment, this function should be called periodically in the main function.
 * In the RTOS environment, this function should be used as a function entry to create a task.
 *
 * @param[in] hostHandle The host handle.
 */
void USB_HostEhciTaskFunction(void *hostHandle);
#endif

#if (defined(USB_HOST_CONFIG_KHCI) && (USB_HOST_CONFIG_KHCI > 0U))
/*!
 * @brief Device KHCI ISR function.
 *
 * The function is the KHCI interrupt service routine.
 *
 * @param[in] hostHandle The host handle.
 */
void USB_HostKhciIsrFunction(void *hostHandle);

/*!
 * @brief KHCI task function.
 *
 * The function is used to handle the KHCI controller message.
 * In the bare metal environment, this function should be called periodically in the main function.
 * In the RTOS environment, this function should be used as a function entry to create a task.
 *
 * @param[in] hostHandle The host handle.
 */
void USB_HostKhciTaskFunction(void *hostHandle);
#endif

#if (defined(USB_HOST_CONFIG_OHCI) && (USB_HOST_CONFIG_OHCI > 0U))
/*!
 * @brief Device OHCI ISR function.
 *
 * The function is the OHCI interrupt service routine.
 *
 * @param[in] hostHandle The host handle.
 */
extern void USB_HostOhciIsrFunction(void *hostHandle);

/*!
 * @brief OHCI task function.
 *
 * The function is used to handle the OHCI controller message.
 * In the bare metal environment, this function should be called periodically in the main function.
 * In the RTOS environment, this function should be used as a function entry to create a task.
 *
 * @param[in] hostHandle The host handle.
 */
extern void USB_HostOhciTaskFunction(void *hostHandle);
#endif

#if (defined(USB_HOST_CONFIG_IP3516HS) && (USB_HOST_CONFIG_IP3516HS > 0U))
/*!
 * @brief Device IP3516HS ISR function.
 *
 * The function is the IP3516HS interrupt service routine.
 *
 * @param[in] hostHandle The host handle.
 */
extern void USB_HostIp3516HsIsrFunction(void *hostHandle);

/*!
 * @brief IP3516HS task function.
 *
 * The function is used to handle the IP3516HS controller message.
 * In the bare metal environment, this function should be called periodically in the main function.
 * In the RTOS environment, this function should be used as a function entry to create a task.
 *
 * @param[in] hostHandle The host handle.
 */
extern void USB_HostIp3516HsTaskFunction(void *hostHandle);
#endif

#endif /* _USB_HOST_MCUX_DRV_PORT_H_ */
