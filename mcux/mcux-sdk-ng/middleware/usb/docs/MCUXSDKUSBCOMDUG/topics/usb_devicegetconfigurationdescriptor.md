# USB\_DeviceGetConfigurationDescriptor

This function is used to get the configuration descriptor. All devices must implement this function.

```
/* Get device configuration descriptor request */
usb_status_t USB_DeviceGetConfigurationDescriptor(
    usb_device_handle handle, usb_device_get_configuration_descriptor_struct_t *configurationDescriptor)
{
    if (USB_COMPOSITE_CONFIGURE_INDEX > configurationDescriptor->configuration)
    {
        configurationDescriptor->buffer = g_UsbDeviceConfigurationDescriptor;
        configurationDescriptor->length = USB_DESCRIPTOR_LENGTH_CONFIGURATION_ALL;
        return kStatus_USB_Success;
    }
    return kStatus_USB_InvalidRequest;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

