# USB\_DeviceGetHidDescriptor

```
/* Get HID descriptor request */
usb_status_t USB_DeviceGetHidDescriptor(usb_device_handle handle,
                                         usb_device_get_hid_descriptor_struct_t *hidDescriptor)
{
    /* If this request is not supported, return the error code “kStatus_USB_InvalidRequest”. Otherwise, fill the hidDescriptor with the descriptor buffer address and length based on the interface number. */
    return kStatus_USB_InvalidRequest;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

