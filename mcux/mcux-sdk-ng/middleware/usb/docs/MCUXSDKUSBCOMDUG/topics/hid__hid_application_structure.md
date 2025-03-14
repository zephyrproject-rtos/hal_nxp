# HID + HID Application structure

```
typedef struct _usb_device_composite_struct
{
    usb_device_handle                  deviceHandle;
    class_handle_t                     hidKeyboardHandle;
    class_handle_t                     hidGenericHandle;
    uint8_t                            speed;
    uint8_t                            attach;
    uint8_t                            currentConfiguration;
    uint8_t                            currentInterfaceAlternateSetting[USB_COMPOSITE_INTERFACE_COUNT];
} usb_device_composite_struct_t;
/* HID keyboard structure */
typedef struct _usb_device_hid_keyboard_struct
{
    uint8_t                   buffer[USB_HID_KEYBOARD_IN_BUFFER_LENGTH];
    uint8_t                   idleRate;
} usb_device_hid_keyboard_struct_t;
/* HID generic structure */
typedef struct _usb_device_hid_generic_struct
{
    uint32_t                  buffer[2][USB_HID_GENERIC_IN_BUFFER_LENGTH>>2];
    uint8_t                   bufferIndex;
    uint8_t                   idleRate;
} usb_device_hid_generic_struct_t;

```

**Parent topic:**[USB composite device application example](../topics/usb_composite_device_application_example.md)

