# Design steps

1.  A new composite device application should use the existing examples as a template.
2.  Prepare the descriptor-related data structure to ensure that the correct information about the customized composite device is related to the USB device stack. See [USB composite device structures](usb_composite_device_structures.md) for additional information.
3.  Prepare the descriptors array and ensure that the descriptors are consistent with the descriptor-related data structure. See [USB descriptor functions](usb_descriptor_functions.md).
4.  Implement the specific descriptor-related callback function which the USB device stack calls to get the device descriptor. See [USB descriptor functions](usb_descriptor_functions.md).

**Parent topic:**[Setup](../topics/setup.md)

