# MCUXpresso SDK : mcuxsdk-components-conn_fwloader-fw_bin

## Overview
This repository is for MCUXpresso SDK components conn_fwloader fw_bin delivery and it contains the components officially provided in NXP MCUXpresso SDK. This repository is part of the MCUXpresso SDK overall delivery which is composed of several sub-repositories/projects. Navigate to the top/parent repository (mcuxsdk-manifests) for the complete delivery of MCUXpresso SDK.

## Documentation
Overall details can be reviewed here: [MCUXpresso SDK Online Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/introduction/README.html)  

## Setup
Instructions on how to install the MCUXpresso SDK provided from GitHub via west manifest [Getting Started with SDK - Detailed Installation Instructions](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/gsd/installation.html#installation)

## Contribution
Contributions are not currently accepted. Guidelines to contribute will be posted in the future.

---------------------------------
## CPU1 and CPU2 firmware binaries for RW61x

1.Examples that support monolithic image download do not need the steps 2-4 to load fw:
    Wi-Fi examples: wifi_cli, wifi_wpa_supplicant, wifi_cert, wifi_test_mode
	ncp examples: ncp_device
	coex examples: coex_wifi_edgefast, coex_zigbee

	These examples can load cpu1/2 fw automatically, don't need to load them seperately.

2. FW image names:
	Production FW, for users:
		rw61x_sb_wifi_a2.bin, for CPU1_wifi of redfinch a2 board
		rw61x_sb_ble_a2.bin, for CPU2_ble of redfinch a2 board
		rw61x_sb_ble_15d4_combo_a2.bin, for CPU2_ble_15.4_combo of redfinch a2 board

3. where to get FW image:
	In the directory:  /components/conn_fwloader/fw_bin

4. How to load FW:
	Need to write the FW image to flash first, then the loadservice will download FW when power on.
	For example, the CMD to write CPU1 image to flash in J-link window:
		loadbin C:\xxx\rw61x_sb_wifi_xx.bin,0x08400000

	The CMD to write CPU2_ble image to flash in J-link window:
		loadbin C:\xxx\rw61x_sb_ble_xx.bin,0x08540000

	The CMD to write CPU2_15.4 image to flash in J-link window:
		loadbin C:\xxx\rw61x_sb_ble_15d4_combo_xx.bin,0x085e0000