# usb\_device\_endpoint\_struct\_t

This structure is required for the composite device and provides ep information. All structures should be placed in the “usb\_device\_descriptor.c” file.

**Prototype:**

```
typedef struct _usb_device_endpoint_struct
{
    uint8_t               endpointAddress;    /*! endpoint address*/
    uint8_t               transferType;       /*! endpoint transfer type*/
    uint16_t              maxPacketSize;     /*! endpoint max packet size */
} usb_device_endpoint_struct_t;

```

**Description:**

-   endpointAddress: Endpoint address \(b7, 0 – USB\_OUT, 1 – USB\_IN\).
-   transferType: The transfer type of this endpoint.
-   maxPacketSize: The maximum packet size of this endpoint.

This is an example for the composite device MSD + CDC:

MSD:

```
usb_device_endpoint_struct_t g_mscDiskEndpoints[USB_MSC_DISK_ENDPOINT_COUNT] =
{
    {
        USB_MSC_DISK_BULK_IN_ENDPOINT | (USB_IN << 7U),
        USB_ENDPOINT_BULK,
        FS_MSC_DISK_BULK_IN_PACKET_SIZE,
    },
    {
        USB_MSC_DISK_BULK_OUT_ENDPOINT | (USB_OUT << 7U),
        USB_ENDPOINT_BULK,
        FS_MSC_DISK_BULK_OUT_PACKET_SIZE,
    }
};

```

CDC:

This is CDC class control interface endpoint information.

```
/* Define endpoint for communication class */
usb_device_endpoint_struct_t g_cdcVcomCicEndpoints[USB_CDC_VCOM_CIC_ENDPOINT_COUNT] =
{
    {
        USB_CDC_VCOM_CIC_INTERRUPT_IN_ENDPOINT | (USB_IN << 7U),
        USB_ENDPOINT_INTERRUPT,
        HS_CDC_VCOM_BULK_IN_PACKET_SIZE,
    },
};

```

This is the CDC class data interface endpoint information.

```
/* Define endpoint for data class */
usb_device_endpoint_struct_t g_cdcVcomDicEndpoints[USB_CDC_VCOM_DIC_ENDPOINT_COUNT] =
{
    {
        USB_CDC_VCOM_DIC_BULK_IN_ENDPOINT | (USB_IN << 7U),
        USB_ENDPOINT_BULK,
        FS_CDC_VCOM_BULK_IN_PACKET_SIZE,
    },
    {
        USB_CDC_VCOM_DIC_BULK_OUT_ENDPOINT | (USB_OUT << 7U),
        USB_ENDPOINT_BULK,
        FS_CDC_VCOM_BULK_OUT_PACKET_SIZE,
    },
};

```

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

