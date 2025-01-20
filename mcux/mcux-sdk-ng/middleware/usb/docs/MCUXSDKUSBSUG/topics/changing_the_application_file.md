# Changing the application file

-   **Main application function**

    The main application function is provided by two functions: USB\_DeviceApplicationInit and APP\_task \(optional\).

    The USB\_DeviceApplicationInit enables the clock and the USB interrupt and also initialize the specific USB class. See the usb\_device\_hid\_mouse example for the sample code.

-   **USB device call back function**

    The device callback function handles the USB device-specific requests. See the usb\_device\_hid\_mouse example for the sample code.

-   **USB Class-specific call back function**

    The class callback function handles the USB class-specific requests. See the usb\_device\_hid\_mouse example for the sample code.


**Parent topic:**[How to develop a new device application](../topics/how_to_develop_a_new_device_application.md)

