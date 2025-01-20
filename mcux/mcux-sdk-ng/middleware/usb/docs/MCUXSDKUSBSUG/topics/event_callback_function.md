# Event callback function

In the app.c file, there is one `USB_HostEvent` function. By default, the function is registered to the host stack when calling the `USB_HostInit`. In the USB Host stack, customers do not have to write any enumeration code. When the device is connected to the host controller, the USB Host stack enumerates the device. The device attach/detach events are notified by this callback function.

Application needs to implement one or more functions to correspond to one class process. These application functions are called in the `USB_HostEvent`. The device’s configuration handle and interface list are passed to the application through the function so that the application can determine whether the device is supported by this application.

There are four events in the callback: `kUSB_HostEventAttach, kUSB_HostEventNotSupported, kUSB_HostEventEnumerationDone, and kUSB_HostEventDetach`.

The events occur as follows:

-   When one device is attached, host stack notifies `kUSB_HostEventAttach`.
-   The application returns `kStatus_USB_Success` to notify the host stack that the device configuration is supported by this class application, or return the `kStatus_USB_NotSupported` to notify the host stack that the device configuration is not supported by this class application.
-   The Host stack continues for enumeration if the device is supported by the application and notifies `kUSB_HostEventEnumerationDone` when the enumeration is done.
-   The Host stack checks the next device’s configuration if the current configuration is not supported by the application.
-   When the Host stack checks all configurations and all are not supported by the application, it notifies the `kUSB_HostEventNotSupported`.
-   When the device detaches, the Host stack notifies the `kUSB_HostEventDetach`.

This is the sample code for the HID mouse application. The `USB_HostHidMouseEvent` function should be called bythe `USB_HostEvent`. In this code, the `g_HostHidMouse` variable contains all states and pointers used by the application to control or operate the device:

```
usb_status_t USB_HostHidMouseEvent
(
usb_device_handle deviceHandle,
   usb_host_configuration_handle configurationHandle,
   uint32_t eventCode
)
{
    /* Process the same and supported device's configuration handle */
    static usb_host_configuration_handle s_ConfigHandle = NULL;
    usb_status_t status = kStatus_USB_Success;
    uint8_t id;
    usb_host_configuration_t *configuration;
    uint8_t interfaceIndex;
    usb_host_interface_t *interface;
    switch (eventCode)
    {
        case kUSB_HostEventAttach:
            /* judge whether is configurationHandle supported */
            configuration = (usb_host_configuration_t *)configurationHandle;
            for (interfaceIndex = 0; interfaceIndex < configuration->interfaceCount; ++interfaceIndex)
            {
                interface = &configuration->interfaceList[interfaceIndex];
                id = interface->interfaceDesc->bInterfaceClass;
                if (id != USB_HOST_HID_CLASS_CODE)
                {
                    continue;
                }
                id = interface->interfaceDesc->bInterfaceSubClass;
                if ((id != USB_HOST_HID_SUBCLASS_CODE_NONE) && (id != USB_HOST_HID_SUBCLASS_CODE_BOOT))
                {
                    continue;
                }
                id = interface->interfaceDesc->bInterfaceProtocol;
                if (id != USB_HOST_HID_PROTOCOL_MOUSE)
                {
                    continue;
                }
                else
                {
                    /* the interface is supported by the application */
                    g_HostHidMouse.deviceHandle = deviceHandle;
                    g_HostHidMouse.interfaceHandle = interface;
                    s_ConfigHandle = configurationHandle;
                    return kStatus_USB_Success;
                }
            }
            status = kStatus_USB_NotSupported;
            break;
        case kUSB_HostEventNotSupported:
            break;
        case kUSB_HostEventEnumerationDone:
            if (s_ConfigHandle == configurationHandle)
            {
                if ((g_HostHidMouse.deviceHandle != NULL) && (g_HostHidMouse.interfaceHandle != NULL))
                {
                    /* the device enumeration is done */
                    if (g_HostHidMouse.deviceState == kStatus_DEV_Idle)
                    {
                        g_HostHidMouse.deviceState = kStatus_DEV_Attached;
                    }
                    else
                    {
                        usb_echo("not idle mouse instance\r\n");
                    }
                }
            }
            break;
        case kUSB_HostEventDetach:
            if (s_ConfigHandle == configurationHandle)
            {
                /* the device is detached */
                s_ConfigHandle = NULL;
                if (g_HostHidMouse.deviceState != kStatus_DEV_Idle)
                {
                    g_HostHidMouse.deviceState = kStatus_DEV_Detached;
                }
            }
            break;
        default:
            break;
    }
    return status;
}
```

If implementing the callback as `USB_HostHidTestEvent`, use `g_HidTestInstance`, and support the device that the class code is USB\_HOST\_HID\_TEST\_CLASS\_CODE, sub-class code is USB\_HOST\_HID\_TEST\_SUBCLASS\_CODE, and the protocol is USB\_HOST\_HID\_TEST\_PROTOCOL. The code can be modified as follows:

```
usb_status_t USB_HostHidMouseEvent
(
usb_device_handle deviceHandle,
   usb_host_configuration_handle configurationHandle,
   uint32_t eventCode
)
{
    /* Process the same and supported device's configuration handle */
    static usb_host_configuration_handle s_ConfigHandle = NULL;
    usb_status_t status = kStatus_USB_Success;
    uint8_t id;
    usb_host_configuration_t *configuration;
    uint8_t interfaceIndex;
    usb_host_interface_t *interface;
    switch (eventCode)
    {
        case kUSB_HostEventAttach:
            /* judge whether is configurationHandle supported */
            configuration = (usb_host_configuration_t *)configurationHandle;
            for (interfaceIndex = 0; interfaceIndex < configuration->interfaceCount; ++interfaceIndex)
            {
                interface = &configuration->interfaceList[interfaceIndex];
                id = interface->interfaceDesc->bInterfaceClass;
                if (id != USB_HOST_HID_TEST_CLASS_CODE)
                {
                    continue;
                }
                id = interface->interfaceDesc->bInterfaceSubClass;
                if (id != USB_HOST_HID_TEST_SUBCLASS_CODE)
                {
                    continue;
                }
                id = interface->interfaceDesc->bInterfaceProtocol;
                if (id != USB_HOST_HID_TEST_PROTOCOL)
                {
                    continue;
                }
                else
                {
                    /* the interface is supported by the application */
                    g_HidTestInstance.deviceHandle = deviceHandle;
                    g_HidTestInstance.interfaceHandle = interface;
                    s_ConfigHandle = configurationHandle;
                    return kStatus_USB_Success;
                }
            }
            status = kStatus_USB_NotSupported;
            break;
        case kUSB_HostEventNotSupported:
            break;
        case kUSB_HostEventEnumerationDone:
            if (s_ConfigHandle == configurationHandle)
            {
                if ((g_HidTestInstance.deviceHandle != NULL) && (g_HidTestInstance.interfaceHandle != NULL))
                {
                    /* the device enumeration is done */
                    if (g_HidTestInstance.deviceState == kStatus_DEV_Idle)
                    {
                        g_HidTestInstance.deviceState = kStatus_DEV_Attached;
                    }
                    else
                    {
                        usb_echo("not idle mouse instance\r\n");
                    }
                }
            }
            break;
        case kUSB_HostEventDetach:
            if (s_ConfigHandle == configurationHandle)
            {
                /* the device is detached */
                s_ConfigHandle = NULL;
                if (g_HidTestInstance.deviceState != kStatus_DEV_Idle)
                {
                    g_HidTestInstance.deviceState = kStatus_DEV_Detached;
                }
            }
            break;
        default:
            break;
    }
    return status;
}
```

Note that the `kStatus_DEV_Attached`, `kStatus_DEV_Detached` MACROs are defined in the example.

**Parent topic:**[How to develop a new host application](../topics/how_to_develop_a_new_host_application.md)

