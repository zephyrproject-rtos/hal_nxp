# USB\_DeviceGetDeviceDescriptor

This function is used to get the device descriptor. All devices must implement this function.

```
usb_status_t USB_DeviceGetDeviceDescriptor(usb_device_handle handle,
                                           usb_device_get_device_descriptor_struct_t *deviceDescriptor)
{
    deviceDescriptor->buffer = g_UsbDeviceDescriptor;
    deviceDescriptor->length = USB_DESCRIPTOR_LENGTH_DEVICE;
    return kStatus_USB_Success;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

