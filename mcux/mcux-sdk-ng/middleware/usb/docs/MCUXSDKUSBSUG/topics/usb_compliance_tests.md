# USB compliance tests

For the device, this is enabled on "dev\_hid\_mouse\_bm" as an example.

```
enable USB_DEVICE_CONFIG_COMPLIANCE_TEST (0U)
```

The macro is defined in `usb_device_config.h`. Use the TWR-K65F180M Tower System module as an example. The file path is

*<install\_dir\>/boards/twrk65f180m/usb\_examples/usb\_device\_hid\_mouse/bm/usb\_device\_config.h.*

Both CV test and USB test mode are enabled.

For the host, this is enabled on "host\_mad\_fatfs\_bm" as an example.

```
enable USB_HOST_CONFIG_COMPLIANCE_TEST (0U)
```

The macro is defined in the usb\_host\_config.h file.

For example, for the TWR-K65F180M Tower System module, the file path is

*<install\_dir\>/boards/twrk65f180m/usb\_examples/usb\_host\_msd\_fatfs/bm/usb\_host\_config.h*

