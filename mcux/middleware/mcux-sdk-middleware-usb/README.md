# NXP Middleware USB stack
The USB stack provides USB device and USB host APIs that are targeted to support the application based on NXP's micro-controller.
## USB stack license
This project is under BSD-3-Clause license, license copy please check [COPYING_BSD-3](COPYING-BSD-3).

## Middleware USB subfolders description
The middleware USB folder contains six subfolders totally.
### device
This subfolder includes the device controller driver and common device driver for the USB device. The device controller driver includes KHCI, EHCI, IP3511(FS/HS).
> Note that the device class driver and the USB framework (chapter 9) to handle the standard enumeration and request defined by USB specification 2.0 are moved to
the application layer, which are located in the folder **examples/${boards}/usb_examples/**. The aim is to implement two types of USB device examples (lite and non-lite). 
In this case, the lite version device examples have no device class driver and class-specific codes are processed in application directly so that lite version has less footprint.

### host
This subfolder includes the host controller driver, USB host class driver and common host driver for the USB host. The host controller driver includes KHCI, EHCI, IP3516(FS/HS).
### include
This subfolder includes the definitions and structures for the USB stack. The miscellaneous content is also here.
### output
This subfolder includes the files that are specially used by the New Project Wizard(NPW) of MCUXpresso IDE.
### phy
This subfolder includes the USB PHY driver. The USB PHY driver is only used for USB high speed port of some Socs that expose the PHY interface.
### dcd
This subfolder includes the files that are specially used by the device charger detect.
> Note that only usb_device_hid_mouse demo and usb_host_hid_mouse demo supported device charger detect.

## Supported USB classes
- AUDIO
- CCID
- CDC
- DFU
- HID
- MSC
- MTP
- PHDC
- PTINTER
- VIDEO

## USB Examples
The following USB examples are provided to meet different requirements. USB examples are located in **examples/${boards}/usb_examples/** folder. Different board may have different set of USB examples.
- usb_device_audio_generator
- usb_device_audio_speaker
- usb_device_cdc_vcom
- usb_device_cdc_vnic
- usb_device_composite_audio_multi_ch_unified
- usb_device_composite_cdc_audio_unified
- usb_device_composite_cdc_hid_audio_unified
- usb_device_composite_cdc_msc
- usb_device_composite_cdc_msc_disk
- usb_device_composite_cdc_vcom_cdc_vcom
- usb_device_composite_hid_audio
- usb_device_composite_hid_audio_unified
- usb_device_composite_hid_mouse_hid_keyboard
- usb_device_dfu
- usb_device_hid_generic
- usb_device_hid_mouse
- usb_device_msc_disk
- usb_device_msc_ramdisk
- usb_device_mtp
- usb_device_phdc_weighscale
- usb_device_printer_virtual_plain_text
- usb_device_video_virtual_camera
- usb_host_audio_recorder
- usb_host_audio_speaker
- usb_host_cdc
- usb_host_hid_generic
- usb_host_hid_mouse
- usb_host_hid_mouse_dual
- usb_host_hid_mouse_keyboard
- usb_host_msd_command
- usb_host_msd_fatfs
- usb_host_phdc_manager
- usb_host_printer_plain_text
- usb_host_video_camera
- usb_keyboard2mouse
- usb_lpm_device_hid_mouse
- usb_lpm_host_hid_mouse
- usb_otg_hid_mouse
- usb_pin_detect_hid_mouse
- usb_pin_detect_hid_msd
- usb_suspend_resume_device_hid_mouse
- usb_suspend_resume_host_hid_mouse

## USB related guide
Some documents are provided to introduce more details of the USB stack or guide users to implement some new requirements.
1. MCUXpresso SDK USB Stack User's Guide.pdf
2. MCUXpresso SDK USB Stack Device Reference Manual.pdf
3. MCUXpresso SDK USB Stack Host Reference Manual.pdf
4. Enable More USB Examples on M4 Core for RT1170.pdf
5. MCUXpresso SDK USB Stack Composite Device User's Guide.pdf
6. MCUXpresso SDK USB Stack Composite Host User's Guide.pdf