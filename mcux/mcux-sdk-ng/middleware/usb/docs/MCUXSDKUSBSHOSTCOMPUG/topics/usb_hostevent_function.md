# USB\_HostEvent function

Add the USB\_HostMsdEvent function into the USB\_HostEvent function.

```
usb_status_t USB_HostEvent(usb_device_handle deviceHandle,
                           usb_host_configuration_handle configurationHandle,
                           uint32_t event_code)
{
    usb_status_t status1;
    usb_status_t status2;
    usb_status_t status = kStatus_USB_Success;
    switch (event_code)
    {
        case kUSB_HostEventAttach:
            status1 = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
            status2 = USB_HostMsdEvent(deviceHandle, configurationHandle, event_code);
            if ((status1 == kStatus_USB_NotSupported) && (status2 ==
kStatus_USB_NotSupported))
            {
                status = kStatus_USB_NotSupported;
            }
            break;
        case kUSB_HostEventNotSupported:
            usb_echo("device not supported.\r\n");
            break;
        case kUSB_HostEventEnumerationDone:
            status1 = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
            status2 = USB_HostMsdEvent(deviceHandle, configurationHandle, event_code);
            if ((status1 != kStatus_USB_Success) && (status2 != kStatus_USB_Success))
            {
                status = kStatus_USB_Error;
            }
            break;
        case kUSB_HostEventDetach:
            status1 = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
            status2 = USB_HostMsdEvent(deviceHandle, configurationHandle, event_code);
            if ((status1 != kStatus_USB_Success) && (status2 != kStatus_USB_Success))
        {
            status = kStatus_USB_Error;
        }
        break;
    default:
        break;
    }
    return status;
}
```

**Parent topic:**[Host MSD command + CDC virtual com example](../topics/host_msd_command__cdc_virtual_com_example.md)

