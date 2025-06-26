# Host configuration

A host configuration file is set up for each example, such as:

*<install\_dir\>/boards/twrk22f120m/usb\_examples/usb\_host\_hid\_mouse/bm/usb\_host\_config.h*

This file is used to either enable or disable the USB class driver. The object number is configurable either to decrease the memory usage or to meet specific requirements.

If the Host stack configuration is changed, rebuild the example projects.

For each Host, follow these steps.

If the board is a Tower for Freedom platform, enable the following macros:

Enable this macro for full speed.

*\#define USB\_HOST\_CONFIG\_KHCI \(0U\)*

Enable this macro if the board supports high-speed.

*\#define USB\_HOST\_CONFIG\_EHCI \(0U\)*

**Note:** Only EHCI support pin detect feature.



If board is part of the LPC series, enable the following macros:

Enable this macro for full speed.

*\#define USB\_HOST\_CONFIG\_OHCI \(0U\)*

Enable this macro if the board supports high-speed.

*\#define USB\_HOST\_CONFIG\_IP3516HS \(0U\)*

**Parent topic:**[USB stack configuration](../topics/usb_stack_configuration.md)

