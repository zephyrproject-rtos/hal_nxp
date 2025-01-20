# USB composite device structure examples

```
/* Two HID classes */
usb_device_class_config_list_struct_t g_UsbDeviceCompositeConfigList =
{
    g_CompositeClassConfig,
    USB_DeviceCallback,
    2U,
};
/* Two HID classes definition */
usb_device_class_config_struct_t g_CompositeClassConfig[2] =
 {
    {
        USB_DeviceHidKeyboardCallback,
        (class_handle_t)NULL,
        &g_UsbDeviceHidKeyboardConfig,
    },
    {
        USB_DeviceHidGenericCallback,
        (class_handle_t)NULL,
        &g_UsbDeviceHidGenericConfig,
    }
};
/* HID generic device config */
usb_device_class_struct_t g_UsbDeviceHidGenericConfig =
{
    g_UsbDeviceHidGenericInterfaceList, /* The interface list of the HID generic */
    kUSB_DeviceClassTypeHid,             /* The HID class type */
    USB_DEVICE_CONFIGURATION_COUNT,          /* The configuration count */
};
/* HID generic device interface list */
usb_device_interface_list_t g_UsbDeviceHidGenericInterfaceList[USB_DEVICE_CONFIGURATION_COUNT] =
{
    {
        USB_HID_GENERIC_INTERFACE_COUNT, /* The interface count of the HID generic */
        g_UsbDeviceHidGenericInterfaces,        /* The interfaces handle */
    },
};
/* HID generic device interfaces */
usb_device_interfaces_struct_t g_UsbDeviceHidGenericInterfaces[USB_HID_GENERIC_INTERFACE_COUNT] =
{
    USB_HID_GENERIC_CLASS,           /* HID generic class code */
    USB_HID_GENERIC_SUBCLASS,        /* HID generic subclass code */
    USB_HID_GENERIC_PROTOCOL,        /* HID generic protocol code */
    USB_HID_GENERIC_INTERFACE_INDEX, /* The interface number of the HID generic */
    g_UsbDeviceHidGenericInterface,         /* Interfaces handle */
    sizeof(g_UsbDeviceHidGenericInterface) / sizeof(usb_device_interface_struct_t),
};
/* HID generic device interface and alternate setting device information */
usb_device_interface_struct_t g_UsbDeviceHidGenericInterface[] =
{
    {
        0U, /* The alternate setting of the interface */
        {
            USB_HID_GENERIC_ENDPOINT_COUNT, /* Endpoint count */
            g_UsbDeviceHidGenericEndpoints,        /* Endpoints handle */
        },
    }
};
/* HID generic device endpoint information for interface USB_HID_GENERIC_INTERFACE_INDEX and alternate setting is 0. */
usb_device_endpoint_struct_t g_UsbDeviceHidGenericEndpoints[USB_HID_GENERIC_ENDPOINT_COUNT] =
{
    /* HID generic interrupt IN pipe */
    {
        USB_HID_GENERIC_ENDPOINT_IN | (USB_IN << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT),
        USB_ENDPOINT_INTERRUPT,
        FS_HID_GENERIC_INTERRUPT_IN_PACKET_SIZE,
    },
    /* HID generic interrupt OUT pipe */
    {
        USB_HID_GENERIC_ENDPOINT_OUT | (USB_OUT << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT),
        USB_ENDPOINT_INTERRUPT,
        FS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE,
    },
};
/* HID keyboard device config */
usb_device_class_struct_t g_UsbDeviceHidKeyboardConfig =
{
    g_UsbDeviceHidKeyboardInterfaceList, /* The interface list of the HID keyboard */
    kUSB_DeviceClassTypeHid,             /* The HID class type */
    USB_DEVICE_CONFIGURATION_COUNT,          /* The configuration count */
};
/* HID keyboard device interface list */
usb_device_interface_list_t g_UsbDeviceHidKeyboardInterfaceList[USB_DEVICE_CONFIGURATION_COUNT] =
{
    {
        USB_HID_KEYBOARD_INTERFACE_COUNT, /* The interface count of the HID keyboard */
        g_UsbDeviceHidKeyboardInterfaces,        /* The interfaces handle */
    },
};
/* HID generic device interfaces */
usb_device_interfaces_struct_t g_UsbDeviceHidKeyboardInterfaces[USB_HID_KEYBOARD_INTERFACE_COUNT] =
{
    USB_HID_KEYBOARD_CLASS,           /* HID keyboard class code */
    USB_HID_KEYBOARD_SUBCLASS,        /* HID keyboard subclass code */
    USB_HID_KEYBOARD_PROTOCOL,        /* HID keyboard protocol code */
    USB_HID_KEYBOARD_INTERFACE_INDEX, /* The interface number of the HID keyboard */
    g_UsbDeviceHidKeyboardInterface,         /* Interfaces handle */
    sizeof(g_UsbDeviceHidKeyboardInterface) / sizeof(usb_device_interface_struct_t),
};
/* HID generic device interface and alternate setting device information */
usb_device_interface_struct_t g_UsbDeviceHidKeyboardInterface[] =
{
    {
        0U, /* The alternate setting of the interface */
        {
            USB_HID_KEYBOARD_ENDPOINT_COUNT, /* Endpoint count */
            g_UsbDeviceHidKeyboardEndpoints,        /* Endpoints handle */
        },
    }
};
/* HID generic device endpoint information for interface USB_HID_GENERIC_INTERFACE_INDEX and alternate setting is 0. */
usb_device_endpoint_struct_t g_UsbDeviceHidKeyboardEndpoints[USB_HID_KEYBOARD_ENDPOINT_COUNT] =
{
    /* HID keyboard interrupt IN pipe */
    {
        USB_HID_KEYBOARD_ENDPOINT_IN | (USB_IN << USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_SHIFT),
        USB_ENDPOINT_INTERRUPT,
        FS_HID_KEYBOARD_INTERRUPT_IN_PACKET_SIZE,
    },
};

```

**Parent topic:**[HID keyboard + HID generic composite device example](../topics/hid_keyboard__hid_generic_composite_device_example.md)

