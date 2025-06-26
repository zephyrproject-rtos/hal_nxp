# usb\_device\_interface\_list\_t

This structure is required for the composite device and provides information about each class. The structure should be placed in the “usb\_device\_descriptor.c” file.

This is an example for MSC in the composite MSC + CDC device example.

```
usb_device_interface_list_t g_mscDiskInterfaceList[USB_DEVICE_CONFIGURATION_COUNT] =
{
    {
        .count = USB_MSC_DISK_INTERFACE_COUNT,
        .interfaces = g_mscDiskInterfaces,
    },
};

```

*Count* indicates the interface count this class supports in each configuration.

*Interfaces* member indicates the interface list for each configuration.

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

