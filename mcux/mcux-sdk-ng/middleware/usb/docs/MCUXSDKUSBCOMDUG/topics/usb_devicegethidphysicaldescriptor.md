# USB\_DeviceGetHidPhysicalDescriptor

```
/* Get the HID physical descriptor request */
usb_status_t USB_DeviceGetHidPhysicalDescriptor(
    usb_device_handle handle, usb_device_get_hid_physical_descriptor_struct_t *hidPhysicalDescriptor)
{
    /* If this request is not supported, return the error code “kStatus_USB_InvalidRequest”. Otherwise, fill the hidPhysicalDescriptor with the descriptor buffer address and length based on the interface number and the physical index. */
    return kStatus_USB_InvalidRequest;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

