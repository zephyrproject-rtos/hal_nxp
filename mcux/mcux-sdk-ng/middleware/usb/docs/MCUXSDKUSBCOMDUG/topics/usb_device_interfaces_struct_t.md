# usb\_device\_interfaces\_struct\_t

This structure provides alternate setting interface information about each interface. All structures should be placed in the “usb\_device\_descriptor.c” file.

**Prototype:**

```
typedef struct _usb_device_interfaces_struct
{
    uint8_t                          classCode;
    uint8_t                          subclassCode;
    uint8_t                          protocolCode;
    uint8_t                          interfaceNumber;
    usb_device_interface_struct_t*   interface;
    uint8_t                          count;
} usb_device_interfaces_struct_t;

```

**Description:**

-   classCode: The class code for this interface.
-   subclassCode: The subclass code for this interface.
-   protocolCode: The protocol code for this interface.
-   interfaceNumber: Interface index in the interface descriptor.
-   interface: Includes detailed information about the current interface. For details, see subsequent chapters.
-   count: Number of interfaces in the current interface.

This is an example for the composite device MSD + CDC:

MSD:

```
usb_device_interfaces_struct_t g_mscDiskInterfaces[USB_MSC_DISK_INTERFACE_COUNT] =
{
    {
        USB_MSC_DISK_CLASS,
        USB_MSC_DISK_SUBCLASS,
        USB_MSC_DISK_PROTOCOL,
        USB_MSC_DISK_INTERFACE_INDEX,
        g_mscDiskInterface,
        sizeof(g_mscDiskInterface) / sizeof(usb_device_interface_struct_t),
    }
};
```

`USB_MSC_DISK_INTERFACE_INDEX` is the interface index of this interface in a current configuration. In other words, in the interface descriptor, the interface number is `USB_MSC_DISK_INTERFACE_INDEX`.

`“g_mscDiskInterface”` is the interface detailed information structure. See [usb\_device\_interface\_struct\_t](usb_device_interface_struct_t.md) section for more information.

CDC:

```
usb_device_interfaces_struct_t g_cdcVcomInterfaces[USB_CDC_VCOM_INTERFACE_COUNT] =
{
    {
        USB_CDC_VCOM_CIC_CLASS,
        USB_CDC_VCOM_CIC_SUBCLASS,
        USB_CDC_VCOM_CIC_PROTOCOL,
        USB_CDC_VCOM_CIC_INTERFACE_INDEX,
        g_cdcVcomCicInterface, sizeof(g_cdcVcomCicInterface) / sizeof(usb_device_interface_struct_t)
    },
    {
        USB_CDC_VCOM_DIC_CLASS,
        USB_CDC_VCOM_DIC_SUBCLASS,
        USB_CDC_VCOM_DIC_PROTOCOL,
        USB_CDC_VCOM_DIC_INTERFACE_INDEX,
        g_cdcVcomDicInterface, sizeof(g_cdcVcomDicInterface) / sizeof(usb_device_interface_struct_t)
    },
};

```

`USB_CDC_VCOM_CIC_INTERFACE_INDEX` is the interface index of the control interface in a current configuration. In other words, in the interface descriptor, the interface number is `USB_CDC_VCOM_CIC_INTERFACE_INDEX.`

`USB_CDC_VCOM_DIC_INTERFACE_INDEX` is the interface index of the data interface in a current configuration. In other words, in the interface descriptor, the interface number is `USB_CDC_VCOM_DIC_INTERFACE_INDEX`.

`“g_cdcVcomCicInterface”` is the control interface structure with detailed information. See [usb\_device\_interface\_struct\_t](usb_device_interface_struct_t.md) section for more information.

`“g_cdcVcomDicInterface”` is the data interface structure with detailed information. See [usb\_device\_interface\_struct\_t](usb_device_interface_struct_t.md) section for more information.

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

