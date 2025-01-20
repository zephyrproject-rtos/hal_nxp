# Building the demo

The demo projects are located in the paths below:

-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd*
-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd\_charger\_battery*
-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd\_sink\_battery*
-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd\_source\_charger*
-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd\_alt\_mode\_dp\_host*
-   *<root\>/boards/<board\>\_<shield board\>/usb\_examples/usb\_pd\_alt\_mode\_dp\_dock*

To build the projects, see Section 3 in *Getting Started with MCUXpresso SDK User’s Guide*\(document MCUXSDKGSUG\) at*root/docs/Getting Started with MCUXpresso SDK.pdf*. See section [Supported boards list](supported_boards_list.md) for more information.

**Note:**

1.  The <shield board\> is om13588, om13790host, or om13790dock. Only the om13790host supports DisplayPort host alternate mode. Only the om13790dock supports DisplayPort dock alternate mode.
2.  This document introduces the common PD functions based on the usb\_pd demo in <root\>/boards/ <board\>\_<shield board\>/usb\_examples/usb\_pd.
3.  For the usb\_pd\_charger\_battery, usb\_pd\_sink\_battery, the usb\_pd\_source\_charger, usb\_pd\_alt\_mode\_dp\_host, and usb\_pd\_alt\_mode\_dp\_dock example usage, see the readme in the demos directory.
4.  All USB pd example debug version for FRDM-KL27Z cannot build successfully on MCUXpresso IDE because of flash code size limitation.
5.  Some examples cannot build successfully because of memory size limitation when enable PD 3.0\(\#define PD\_CONFIG\_REVISION \(PD\_SPEC\_REVISION\_30\)\). For details, see the readme documentation in the corresponding demos directory.
6.  If one or more USB PD projects are imported in MCUXpresso IDE, the SDK debug console "UART" radio button in the main wizard page must be selected to avoid any build failures. See the following figure.

    |![](../images/select_uart_radio_button.png "Select "UART" radio button")

|


**Parent topic:**[Software](../topics/software.md)

