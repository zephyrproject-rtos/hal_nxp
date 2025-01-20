# USB stack configurations

Class configuration:

This section describes a use case where two or more of the same classes are used in the composite device.

To reduce the footprint, the released USB stack does not support multiple instances of the same class in the default configuration. If two or more same classes are used in the composite device, the user needs to configure the class.

-   For HID class, USB\_DEVICE\_CONFIG\_HID must be configured in the usb\_device\_config.h.
-   For CDC class, USB\_DEVICE\_CONFIG\_CDC\_ACM must be configured in the usb\_device\_config.h.
-   For MSD class, USB\_DEVICE\_CONFIG\_MSC must be configured in the usb\_device\_config.h.
-   For AUDIO class, USB\_DEVICE\_CONFIG\_AUDIO must be configured in the usb\_device\_config.h.
-   For PHDC class, USB\_DEVICE\_CONFIG\_PHDC must be configured in the usb\_device\_config.h.
-   For VIDEO class, USB\_DEVICE\_CONFIG\_VIDEO must be configured in the usb\_device\_config.h.
-   For CCID class, USB\_DEVICE\_CONFIG\_CCID must be configured in the usb\_device\_config.h.

The value of the configuration depends on use cases and user requirements. For example, for the composite device HID+HID, the USB\_DEVICE\_CONFIG\_HID must be set to 2.

**Note:** USBCFG\_DEV\_MAX\_ENDPOINTS must not be less than “max used endpoint number + 1”. “max used endpoint number” indicates the maximum endpoint number that the example uses.

