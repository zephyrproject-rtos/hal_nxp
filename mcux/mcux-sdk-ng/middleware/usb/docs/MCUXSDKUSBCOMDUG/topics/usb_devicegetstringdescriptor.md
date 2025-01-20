# USB\_DeviceGetStringDescriptor

This function is used to get the string descriptor. All devices must implement this function.

```

/* Get device string descriptor request */
usb_status_t USB_DeviceGetStringDescriptor(usb_device_handle handle,
                                            usb_device_get_string_descriptor_struct_t *stringDescriptor)
{
    if (stringDescriptor->stringIndex == 0U)
    {
        stringDescriptor->buffer = (uint8_t *)g_UsbDeviceLanguageList.languageString;
        stringDescriptor->length = g_UsbDeviceLanguageList.stringLength;
    }
    else
    {
        uint8_t languageId = 0U;
        uint8_t languageIndex = USB_DEVICE_STRING_COUNT;
        for (; languageId < USB_DEVICE_STRING_COUNT; languageId++)
        {
            if (stringDescriptor->languageId == g_UsbDeviceLanguageList.languageList[languageId].languageId)
            {
                if (stringDescriptor->stringIndex < USB_DEVICE_STRING_COUNT)
                {
                    languageIndex = stringDescriptor->stringIndex;
                }
                break;
            }
        }
        if (USB_DEVICE_STRING_COUNT == languageIndex)
        {
            return kStatus_USB_InvalidRequest;
        }
        stringDescriptor->buffer = (uint8_t *)g_UsbDeviceLanguageList.languageList[languageId].string[languageIndex];
        stringDescriptor->length = g_UsbDeviceLanguageList.languageList[languageId].length[languageIndex];
    }
    return kStatus_USB_Success;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

