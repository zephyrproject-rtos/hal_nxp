# usb\_device\_interface\_struct\_t

This structure provides information about each alternate setting interface for the current interface. All structures should be placed in the “usb\_device\_descriptor.c” file.

**Prototype:**

```
typedef struct _usb_device_interface_struct
{
    uint8_t                          alternateSetting;
    usb_device_endpoint_list_t       endpointList;
    void*                            classSpecific;
 } usb_device_interface_struct_t;

```

**Description:**

-   alternateSetting: The alternate value of this interface.
-   endpointList: endpoint list structure. See the usb\_device\_endpoint\_list\_t structure.
-   classSpecific: The class-specific structure pointer.

**Prototype:**

```
typedef struct _usb_device_endpoint_list
{
    uint8_t                          count;
    usb_device_endpoint_struct_t*    endpoint;
} usb_device_endpoint_list_t;

```

**Description:**

-   count: Number of endpoints in the current interface.
-   endpoint: Endpoint information structure.

This is an example for the composite device MSD + CDC:

MSD:

```
usb_device_interface_struct_t g_mscDiskInterface[] =
{
    {
        0,
        {
            USB_MSC_DISK_ENDPOINT_COUNT,
            g_mscDiskEndpoints,
        },
    },
};

```

Number “0” holds the alternate setting value of the MSD interface.

USB\_MSC\_DISK\_ENDPOINT\_COUNT is the endpoint number for MSD interface when the alternate setting is 0.

`“g_mscDiskEndpoints”` is the endpoint detailed information structure. See [usb\_device\_endpoint\_struct\_t](usb_device_endpoint_struct_t.md) section for more information.

CDC:

For control interface:

```
/* Define interface for communication class */
usb_device_interface_struct_t g_cdcVcomCicInterface[] =
{
    {
        0,
        {
            USB_CDC_VCOM_CIC_ENDPOINT_COUNT,
            g_cdcVcomCicEndpoints,
        },
    }
};

```

Number “0” holds the alternate setting value of the CDC control interface.

USB\_CDC\_VCOM\_CIC\_ENDPOINT\_COUNT is the endpoint number for control interface when the alternate setting is 0.

`“g_cdcVcomCicEndpoints"` is the endpoint detailed information structure. See [usb\_device\_endpoint\_struct\_t](usb_device_endpoint_struct_t.md) section for more information.

For data interface:

```
/* Define interface for data class */
usb_device_interface_struct_t g_cdcVcomDicInterface[] =
{
    {
       0,
       {
           USB_CDC_VCOM_DIC_ENDPOINT_COUNT,
           g_cdcVcomDicEndpoints,
       },
    }
};

```

Number “0” holds the alternate setting value of the CDC data interface.

USB\_CDC\_VCOM\_DIC\_ENDPOINT\_COUNT is the endpoint number for control interface when the alternate setting is 0.

`“g_cdcVcomDicEndpoints”` is the endpoint detailed information structure. See [usb\_device\_endpoint\_struct\_t](usb_device_endpoint_struct_t.md) section for more information.

**Parent topic:**[USB composite device structures](../topics/usb_composite_device_structures.md)

