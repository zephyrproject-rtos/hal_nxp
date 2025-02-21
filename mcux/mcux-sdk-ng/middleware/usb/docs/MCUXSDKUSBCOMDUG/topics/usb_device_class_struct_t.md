# usb\_device\_class\_struct\_t

This structure is required for each class including the class type, supported configuration count, and interface list for each configuration. The structure should be placed in the “usb\_device\_descriptor.c” file.

This is an example for MSD in the composite MSD + CDC device example.

```
usb_device_class_struct_t g_mscDiskClass =
{
    .interfaceList = g_mscDiskInterfaceList,
    .type = kUSB_DeviceClassTypeMsc,
    .configurations = USB_DEVICE_CONFIGURATION_COUNT,
};
```

*interfaceList* is the interface list pointer, which points to the type usb\_device\_interface\_list\_t. It includes detailed interface information about the class including interface count, alternate setting count for each interface, and ep count, ep type, and ep direction for each alternate setting. See subsequent sections for more information.

*Type* represents the type of each class included in the composite device. For example, the type of MSD class is kUSB\_DeviceClassTypeMsc.

*Configurations* member indicates the count of the class supported.

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

