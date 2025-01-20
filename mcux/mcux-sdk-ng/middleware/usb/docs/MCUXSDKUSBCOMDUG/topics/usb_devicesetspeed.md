# USB\_DeviceSetSpeed

```
/* Because HS and FS descriptors are different, update the device descriptors and configurations to match the current speed.
 * By default, the device descriptors and configurations are configured by using FS parameters for both EHCI and KHCI.
 * When the EHCI is enabled, the application needs to call this function to update the device by using current speed.
 * The updated information includes the endpoint max packet size, endpoint interval, and so on. */
usb_status_t USB_DeviceSetSpeed(usb_device_handle handle, uint8_t speed)
{
    usb_descriptor_union_t *descriptorHead;
    usb_descriptor_union_t *descriptorTail;
    descriptorHead = (usb_descriptor_union_t *)&g_UsbDeviceConfigurationDescriptor[0];
    descriptorTail = (usb_descriptor_union_t *)(&g_UsbDeviceConfigurationDescriptor[USB_DESCRIPTOR_LENGTH_CONFIGURATION_ALL - 1U]);
    while (descriptorHead < descriptorTail)
    {
        if (descriptorHead->common.bDescriptorType == USB_DESCRIPTOR_TYPE_ENDPOINT)
        {
            if (USB_SPEED_HIGH == speed)
            {
                if (USB_HID_KEYBOARD_ENDPOINT_IN == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK))
                {
                    descriptorHead->endpoint.bInterval = HS_HID_KEYBOARD_INTERRUPT_IN_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(HS_HID_KEYBOARD_INTERRUPT_IN_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
                else if (((descriptorHead->endpoint.bEndpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN) ==
                          USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN) &&
                         (USB_HID_GENERIC_ENDPOINT_IN == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK)))
                {
                    descriptorHead->endpoint.bInterval = HS_HID_GENERIC_INTERRUPT_IN_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(HS_HID_GENERIC_INTERRUPT_IN_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
                else if (((descriptorHead->endpoint.bEndpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_OUT) ==
                          USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_OUT) &&
                         (USB_HID_GENERIC_ENDPOINT_OUT == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK)))
                {
                    descriptorHead->endpoint.bInterval = HS_HID_GENERIC_INTERRUPT_OUT_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(HS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
            }
            else
            {
                if (USB_HID_KEYBOARD_ENDPOINT_IN == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK))
                {
                    descriptorHead->endpoint.bInterval = FS_HID_KEYBOARD_INTERRUPT_IN_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(FS_HID_KEYBOARD_INTERRUPT_IN_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
                else if (((descriptorHead->endpoint.bEndpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN) ==
                          USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN) &&
                         (USB_HID_GENERIC_ENDPOINT_IN == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK)))
                {
                    descriptorHead->endpoint.bInterval = FS_HID_GENERIC_INTERRUPT_IN_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(FS_HID_GENERIC_INTERRUPT_IN_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
                else if (((descriptorHead->endpoint.bEndpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_OUT) ==
                          USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_OUT) &&
                         (USB_HID_GENERIC_ENDPOINT_OUT == (descriptorHead->endpoint.bEndpointAddress & USB_ENDPOINT_NUMBER_MASK)))
                {
                    descriptorHead->endpoint.bInterval = FS_HID_GENERIC_INTERRUPT_OUT_INTERVAL;
                    USB_SHORT_TO_LITTLE_ENDIAN_ADDRESS(FS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE,
                                                       descriptorHead->endpoint.wMaxPacketSize);
                }
            }
        }
        descriptorHead = (usb_descriptor_union_t *)((uint8_t *)descriptorHead + descriptorHead->common.bLength);
    }
    for (int i = 0U; i < USB_HID_GENERIC_ENDPOINT_COUNT; i++)
    {
        if (USB_SPEED_HIGH == speed)
        {
            if (g_UsbDeviceHidGenericEndpoints[i].endpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN)
            {
                g_UsbDeviceHidGenericEndpoints[i].maxPacketSize = HS_HID_GENERIC_INTERRUPT_IN_PACKET_SIZE;
            }
            else
            {
                g_UsbDeviceHidGenericEndpoints[i].maxPacketSize = HS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE;
            }
        }
        else
        {
            if (g_UsbDeviceHidGenericEndpoints[i].endpointAddress & USB_DESCRIPTOR_ENDPOINT_ADDRESS_DIRECTION_IN)
            {
                g_UsbDeviceHidGenericEndpoints[i].maxPacketSize = HS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE;
            }
            else
            {
                g_UsbDeviceHidGenericEndpoints[i].maxPacketSize = FS_HID_GENERIC_INTERRUPT_OUT_PACKET_SIZE;
            }
        }
    }
    if (USB_SPEED_HIGH == speed)
    {
        g_UsbDeviceHidKeyboardEndpoints[0].maxPacketSize = HS_HID_KEYBOARD_INTERRUPT_IN_PACKET_SIZE;
    }
    else
    {
        g_UsbDeviceHidKeyboardEndpoints[0].maxPacketSize = FS_HID_KEYBOARD_INTERRUPT_IN_PACKET_SIZE;
    }
    return kStatus_USB_Success;
}

```

**Parent topic:**[USB descriptor functions](../topics/usb_descriptor_functions.md)

**Parent topic:**[USB composite device descriptor examples](../topics/usb_composite_device_descriptor_examples.md)

