# Application initialization process

1.  Before initializing the USB stack by calling the USB\_DeviceClassInit function, the usb\_device\_class\_config\_list\_struct\_t and usb\_device\_class\_config\_struct\_t are assigned values respectively. For example, for MSC + CDC, the steps are as follows:
    -   Declare the g\_compositeDeviceConfigList as global variables of the type usb\_device\_class\_config\_list\_struct\_t.

        ```
        usb_device_class_config_list_struct_t g_compositeDeviceConfigList =
        {
            g_compositeDevice,
            USB_DeviceCallback,
            2,
        };
        
        ```

    -   Declare the g\_compositeDevice as global variables of the type usb\_device\_class\_config\_struct\_t.

        ```
        usb_device_class_config_struct_t g_compositeDevice[2] =
        {
            {
                USB_DeviceCdcVcomCallback,
                (class_handle_t)NULL,
                &g_UsbDeviceCdcVcomConfig,
            },
            {
                USB_DeviceMscCallback,
                (class_handle_t)NULL,
                &g_mscDiskClass,
            }
        };
        
        ```

    -   Add a function for the USB device ISR.

        For EHCI,

        ```
        #if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
        void USBHS_IRQHandler(void)
        {
            USB_DeviceEhciIsrFunction(g_composite.deviceHandle);
        }
        #endif
        
        ```

        For KHC1,

        ```
        #if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
        void USB0_IRQHandler(void)
        {
            USB_DeviceKhciIsrFunction(g_composite.deviceHandle);
        }
        #endif
        
        ```

        For LPC IP3511,

        ```
        #if defined(USB_DEVICE_CONFIG_LPC3511IP) && (USB_DEVICE_CONFIG_LPC3511IP > 0U)
        void USB0_IRQHandler(void)
        {
            USB_DeviceLpc3511IpIsrFunction (g_composite.deviceHandle);
        }
        #endif
        
        ```

2.  Enable the USB device clock.

    For EHC1,

    ```
    CLOCK_EnableUsbhs0Clock(kCLOCK_UsbSrcPll0, CLOCK_GetFreq(kCLOCK_PllFllSelClk));
    USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ);
    
    ```

    For KHC1,

    ```
    #if ((defined FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED) && (FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED))
    CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcIrc48M, 48000000U);
    #else
    CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcPll0, CLOCK_GetFreq(kCLOCK_PllFllSelClk));
    #endif /* FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED */
    
    ```

    For LPC IP3511,

    ```
    CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcFro, CLOCK_GetFreq(kCLOCK_FroHf));
    ```

3.  Call the USB\_DeviceClassInit function.

    ```
    if (kStatus_USB_Success != USB_DeviceClassInit(CONTROLLER_ID, &g_compositeDeviceConfigList, &g_composite.deviceHandle))
    {
        usb_echo("USB device composite demo init failed\r\n");
        return;
    }
    else
    {
        usb_echo("USB device composite demo\r\n");
        ……
    }
    
    ```

4.  Get a handle for each class. For example,

    CDC virtual com:

    ```
    g_composite.cdcVcom.cdcAcmHandle = g_compositeDeviceConfigList.config[0].classHandle;
    ```

    MSC ramdisk:

    ```
    g_composite.mscDisk.mscHandle = g_compositeDeviceConfigList.config[1].classHandle;
    ```

5.  Initialize each class application.

    Such as,

    CDC virtual com:

    ```
    USB_DeviceCdcVcomInit(&g_composite);
    ```

    MSC ramdisk:

    ```
    USB_DeviceMscDiskInit(&g_composite);
    ```

6.  Set the interrupt priority and enable the USB device interrupt

    ```
    NVIC_SetPriority((IRQn_Type)irqNo, USB_DEVICE_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ((IRQn_Type)irqNo);
    
    ```

7.  Enable the USB device funtionally:

    ```
    USB_DeviceRun(g_composite.deviceHandle);
    ```


**Parent topic:**[Application template](../topics/application_template.md)

