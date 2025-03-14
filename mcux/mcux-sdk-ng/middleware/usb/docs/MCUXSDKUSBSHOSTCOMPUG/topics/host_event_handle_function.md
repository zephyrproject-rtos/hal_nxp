# Host event handle function

The USB\_HostEvent is a common handle function for attach, unsupported device, enumeration, and detach event. This function needs to call the class-specific event handle function. When the host only supports CDC devices, the USB\_HostEvent function is the following:

```
usb_status_t USB_HostEvent(usb_device_handle deviceHandle,
usb_host_configuration_handle configurationHandle,
uint32_t event_code)
{
usb_status_t status;
status = kStatus_USB_Success;
switch (event_code)
{
case kUSB_HostEventAttach:
status = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
/* here add the new device’s event handle function */
break;
case kUSB_HostEventNotSupported:
usb_echo("device not supported.\r\n");
break;
case kUSB_HostEventEnumerationDone:
status = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
/* here add the new device’s event handle function */
break;
case kUSB_HostEventDetach:
status = USB_HostCdcEvent(deviceHandle, configurationHandle, event_code);
/* here add the new device’s event handle function */
break;
default:
break;
}
return status;
}
```

To support other devices, add the corresponding class-specific event handle function. Additionally, it is necessary to add the local variable to receive the return value of every event handle function. The return value of USB\_HostEvent should be changed according to the following occasions:

1.  kUSB\_HostEventAttach: if the return values for all of the class-specific event handle functions are kUSB\_HostEventNotSupported, the return value of USB\_HostEvent is kUSB\_HostEventNotSupported.
2.  kUSB\_HostEventNotSupported: no change.
3.  kUSB\_HostEventEnumerationDone: if the return values for all of the class-specific event handle functions are not kStatus\_USB\_Success, the return value of USB\_HostEvent is kStatus\_USB\_Error.
4.  kUSB\_HostEventDetach: if the return values for all of the class-specific event handle functions are not kStatus\_USB\_Success, the return value of USB\_HostEvent is kStatus\_USB\_Error.

**Parent topic:**[Detailed steps](../topics/detailed_steps.md)

