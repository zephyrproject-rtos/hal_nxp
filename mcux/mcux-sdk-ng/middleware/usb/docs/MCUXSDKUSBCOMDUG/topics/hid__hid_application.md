# HID + HID application

1.  Define and initialize the configuration structure.

    ```
    static usb_device_composite_struct_t g_UsbDeviceComposite;
    usb_device_class_struct_t g_UsbDeviceHidGenericConfig;
    usb_device_class_struct_t g_UsbDeviceHidKeyboardConfig;
    usb_device_class_config_struct_t g_CompositeClassConfig[2] =
    {
        {
            USB_DeviceHidKeyboardCallback,
            (class_handle_t)NULL,
            &g_UsbDeviceHidKeyboardConfig,
        },
        {
            USB_DeviceHidGenericCallback,
            (class_handle_t)NULL,
            &g_UsbDeviceHidGenericConfig,
        }
    };
    usb_device_class_config_list_struct_t g_UsbDeviceCompositeConfigList =
    {
        g_CompositeClassConfig,
        USB_DeviceCallback,
        2U,
    };
    
    ```

2.  Add USB ISR.

    ```
    #if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
    void USBHS_IRQHandler(void) { USB_DeviceEhciIsrFunction(g_UsbDeviceComposite.deviceHandle); }
    #endif
    #if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    void USB0_IRQHandler(void) { USB_DeviceKhciIsrFunction(g_UsbDeviceComposite.deviceHandle); }
    #endif
    #if defined(USB_DEVICE_CONFIG_LPC3511IP) && (USB_DEVICE_CONFIG_LPC3511IP > 0U)
    void USB0_IRQHandler(void)
    {
        USB_DeviceLpc3511IpIsrFunction(g_UsbDeviceHidMouse.deviceHandle);
    }
    #endif
    
    ```

3.  Enable the USB device clock.

    ```
    #if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
        CLOCK_EnableUsbhs0Clock(kCLOCK_UsbSrcPll0, CLOCK_GetFreq(kCLOCK_PllFllSelClk));
        USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ);
    #endif
    #if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
    #if ((defined FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED) && (FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED))
        CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcIrc48M, 48000000U);
    #else
        CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcPll0, CLOCK_GetFreq(kCLOCK_PllFllSelClk));
    #endif /* FSL_FEATURE_USB_KHCI_IRC48M_MODULE_CLOCK_ENABLED */
    #endif
    #if defined(USB_DEVICE_CONFIG_LPC3511IP) && (USB_DEVICE_CONFIG_LPC3511IP > 0U)
        CLOCK_EnableUsbfs0Clock(kCLOCK_UsbSrcFro, CLOCK_GetFreq(kCLOCK_FroHf));
    #endif
    
    ```

4.  Set the default state.

    ```
    g_UsbDeviceComposite.speed = USB_SPEED_FULL;
    g_UsbDeviceComposite.attach = 0U;
    g_UsbDeviceComposite.hidGenericHandle = (class_handle_t)NULL;
    g_UsbDeviceComposite.hidKeyboardHandle = (class_handle_t)NULL;
    g_UsbDeviceComposite.deviceHandle = NULL;
    
    ```

5.  Initialize the USB device.

    ```
    if (kStatus_USB_Success !=
        USB_DeviceClassInit(CONTROLLER_ID, &g_UsbDeviceCompositeConfigList, &g_UsbDeviceComposite.deviceHandle))
    {
        usb_echo("USB device composite demo init failed\r\n");
        return;
    }
    else
    {
        usb_echo("USB device composite demo\r\n");
        …
    }
    
    ```

6.  Save each class handle when the device is initialized successfully.

    ```
    /* Get the HID keyboard class handle */
    g_UsbDeviceComposite.hidKeyboardHandle = g_UsbDeviceCompositeConfigList.config[0].classHandle;
    /* Get the HID generic class handle */
    g_UsbDeviceComposite.hidGenericHandle = g_UsbDeviceCompositeConfigList.config[1].classHandle;
    
    ```

7.  Initialize the HID keyboard and HID generic application.

    ```
    USB_DeviceHidKeyboardInit(&g_UsbDeviceComposite);
    USB_DeviceHidGenericInit(&g_UsbDeviceComposite);
    
    ```

8.  Set the device ISR priority and enable the device interrupt.

    ```
    NVIC_SetPriority((IRQn_Type)irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
    NVIC_EnableIRQ((IRQn_Type)irqNumber);
    
    ```

9.  Start the device functionality.

    ```
    USB_DeviceRun(g_UsbDeviceComposite.deviceHandle);
    ```

10. Poll the device task when the "USB\_DEVICE\_CONFIG\_USE\_TASK" is non-zero. Poll the HID keyboard and HID generic task when these tasks are implemented.

    ```
    #if USB_DEVICE_CONFIG_USE_TASK
    #if defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U)
            USB_DeviceEhciTaskFunction(g_UsbDeviceComposite.deviceHandle);
    #endif
    #if defined(USB_DEVICE_CONFIG_KHCI) && (USB_DEVICE_CONFIG_KHCI > 0U)
            USB_DeviceKhciTaskFunction(g_UsbDeviceComposite.deviceHandle);
    #endif
    #if defined(USB_DEVICE_CONFIG_LPC3511IP) && (USB_DEVICE_CONFIG_LPC3511IP > 0U)
            USB_DeviceLpc3511IpTaskFunction(g_UsbDeviceHidMouse.deviceHandle);
    #endif
    #endif
    
    ```


**Parent topic:**[USB composite device application example](../topics/usb_composite_device_application_example.md)

