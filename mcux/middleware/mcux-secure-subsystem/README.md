# MCUXpresso SDK : mcux-secure-subsystem

## Overview
This repository is for MCUXpresso SDK Secure Subsystem (SSS) middleware delivery and it contains the components officially provided in NXP MCUXpresso SDK. This repository is part of the MCUXpresso SDK overall delivery which is composed of several sub-repositories/projects. Navigate to the top/parent repository [mcuxsdk](https://github.com/nxp-mcuxpresso/mcuxsdk-manifests/) for the complete delivery of MCUXpresso SDK to be able to build and run the examples that are based on this delivery.

## Documentation
Overall details can be reviewed here: [MCUXpresso SDK Online Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/introduction/README.html)

## Setup
Instructions on how to install the MCUXpresso SDK provided from GitHub via west manifest [Getting Started with SDK - Detailed Installation Instructions](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/gsd/installation.html#installation)

## Contribution
Contributions are not currently accepted. Guidelines to contribute will be posted in the future.

---------------------------------
## Repo Specific Content
The Secure Subsystem (SSS) library provides the Secure Subsystem APIs (SSS APIs), a common cryptographic interface used by MCUXpresso SDK middleware and applications to access NXP secure subsystem hardware. The APIs cover symmetric and asymmetric cryptography, key management/key store operations, MAC and digest operations, key derivation, and secure tunnelling to the secure element.

See `ChangeLog.txt` for the current API version and the history of supported algorithms and features.

### Usage in Zephyr
Besides the MCUXpresso SDK delivery described above, this repository is also used by Zephyr. It is a Zephyr module (see `zephyr/module.yml`, which declares the module CMake and Kconfig entry points) and is brought into a Zephyr workspace through the NXP HAL (`hal_nxp`), so no separate west entry is required.

In a Zephyr build the library is enabled through the Kconfig options defined in `zephyr/Kconfig`, for example:

* `CONFIG_MCUX_SECURE_SUBSYSTEM` - build the secure subsystem (SSS) library
* `CONFIG_MCUX_SECURE_SUBSYSTEM_LEGACY_CONN_PORT` - use the legacy connectivity port layer
* `CONFIG_MCUX_SECURE_SUBSYSTEM_FIRMWARE_EL2GO` - include the EdgeLock 2GO secure element firmware
* `CONFIG_MCUX_SECURE_SUBSYSTEM_SESSION_ID` - enable session id handling
* `CONFIG_ELE_TRACK_SESSION_STATE` - track the secure element session state

See `zephyr/Kconfig` and `zephyr/CMakeLists.txt` for the complete and up-to-date list of options, including the per-device firmware selections, and their dependencies.

## License
This repository is under the **BSD-3-Clause** license. See the `LICENSE` file for details.
