# Device configuration

A device configuration file is set up for each example, such as:

*<install\_dir\>/boards/twrk22f120m/usb\_examples/usb\_device\_hid\_mouse/bm/usb\_device\_config.h*

This file is used to either enable or disable the USB class driver and to configure the interface type \(high-speed or full speed\). The object number is configurable either to decrease the memory usage or to meet specific requirements.

If the device stack configuration is changed, rebuild the example projects. For each device, follow these steps.

If the board is a Tower or Freedom platform, enable the following macros:

1.  Enable *\#define USB\_DEVICE\_CONFIG\_KHCI \(0U\)* macro for full speed.
2.  Enable *\#define USB\_DEVICE\_CONFIG\_EHCI \(0U\)* macro if the board supports high-speed.

    **Note:** Only EHCI support pin detect feature.


If board is part of the LPC series, enable the following macros:

1.  Enable *\#define USB\_DEVICE\_CONFIG\_LPCIP3511FS \(0U\)* macro for full speed.
2.  Enable *\#define USB\_DEVICE\_CONFIG\_LPCIP3511HS \(0U\)* macro if the board supports high-speed.

**Parent topic:**[USB stack configuration](../topics/usb_stack_configuration.md)

