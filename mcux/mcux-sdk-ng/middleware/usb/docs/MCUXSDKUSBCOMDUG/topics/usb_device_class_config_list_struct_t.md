# usb\_device\_class\_config\_list\_struct\_t

This structure is required for the composite device and relays device callback, class callback, interface numbers, and endpoint numbers of each interface to the class driver. The structure should be placed in the “composite.c” file.

This is an example for a composite device MSD + CDC:

```
usb_device_class_config_list_struct_t g_compositeDeviceConfigList =
       {
        .config = g_compositeDevice,
        .deviceCallback = USB_DeviceCallback,
        .count = 2,
        };
```

The variable “count” holds the number of classes included in the composite device. Because the composite device MSD+CDC includes two classes, the value of variable "count" is 2.

The type of “config” is usb\_device\_class\_config\_struct\_t. See subsequent sections for more information.

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

