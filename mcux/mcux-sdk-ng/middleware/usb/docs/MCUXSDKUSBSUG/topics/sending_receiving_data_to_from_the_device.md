# Sending/Receiving data to/from the device

The transfer flow is as follows:

1.  Call the `USB_hostClassxxx` API to begin the transfer.
2.  The transfer result is notified by the callback function that is passed as a parameter.
3.  The HID mouse host uses the following code to receive data from the device:`USB_HostHidRecv(classHandle, mouseBuffer, bufferLength, callbackFunction, callbackParameter);`

**Parent topic:**[How to develop a new host application](../topics/how_to_develop_a_new_host_application.md)

