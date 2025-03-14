# Application structure template

For a general device, a demo contains only one class. However, for the composite device, a demo contains more than one class. Likewise, a structure is required to manage the application involving more than one class.

```
typedef struct composite_device_struct
{
    usb_device_handle                  deviceHandle;
    class_handle_t                     classHandle1;
    class_handle_t                     classHandle2;
    …
    class_handle_t                     classHandlen;
    uint8_t                            speed;
    uint8_t                            attach;
    uint8_t                            currentConfiguration;
    uint8_t                            currentInterfaceAlternateSetting[USB_COMPOSITE_INTERFACE_COUNT];
}composite_device_struct_t;

```

deviceHandle: The handle pointer to a device, which is returned by the USB\_DeviceClassInit.

speed: Speed of the USB device. USB\_SPEED\_FULL/USB\_SPEED\_LOW/USB\_SPEED\_HIGH.

attach: Indicates whether the device is attached or not.

currentConfiguration: The current device configuration value.

currentInterfaceAlternateSetting: The current alternate setting for each interface.

classHandlen: The pointer to a class.

This is an example for a composite device HID mouse + HID keyboard:

This structure is in the “composite.h” file.

**Prototype:**

```
typedef struct _usb_device_composite_struct
{
    usb_device_handle                  deviceHandle;
    class_handle_t                     hidMouseHandle;
    class_handle_t                     hidKeyboardHandle;
    uint8_t                            speed;
    uint8_t                            attach;
    uint8_t                            currentConfiguration;
    uint8_t                            currentInterfaceAlternateSetting[USB_COMPOSITE_INTERFACE_COUNT];
} usb_device_composite_struct_t;

```

**Parent topic:**[Application template](../topics/application_template.md)

