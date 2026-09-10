# MCUXpresso SDK : els_pkc

## Overview
This repository is for MCUXpresso SDK ELS PKC middleware delivery and it contains the components officially provided in NXP MCUXpresso SDK. This repository is part of the MCUXpresso SDK overall delivery which is composed of several sub-repositories/projects. Navigate to the top/parent repository [mcuxsdk](https://github.com/nxp-mcuxpresso/mcuxsdk-manifests/) for the complete delivery of MCUXpresso SDK to be able to build and run the examples that are based on this delivery.

## Documentation
Overall details can be reviewed here: [MCUXpresso SDK Online Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/introduction/README.html)

## Setup
Instructions on how to install the MCUXpresso SDK provided from GitHub via west manifest [Getting Started with SDK - Detailed Installation Instructions](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/gsd/installation.html#installation)

## Contribution
Contributions are not currently accepted. Guidelines to contribute will be posted in the future.

---------------------------------
## Repo Specific Content
The ELS PKC component is the cryptographic library running on the NXP ELS (EdgeLock Secure Enclave) and PKC (Public Key Cryptography) hardware IP. It provides the low-level cryptographic primitives and platform ports used by MCUXpresso SDK middleware and applications on the supported device families (see the `src/platforms/` and `doc/` directories for per-platform content).

See `ReleaseNotes.txt` for the current library version and release history.

### Usage in Zephyr
Besides the MCUXpresso SDK delivery described above, this repository is also used by Zephyr. It is a Zephyr module (see `zephyr/module.yml`, which declares the module CMake and Kconfig entry points) and is brought into a Zephyr workspace through the NXP HAL (`hal_nxp`), so no separate west entry is required.

In a Zephyr build the library is enabled through the Kconfig options defined in `zephyr/Kconfig`:

* `CONFIG_MCUX_ELS_PKC` - build the els_pkc library
* `CONFIG_MCUX_ELS_PKC_TRNG_USE_ELS` - use the ELS TRNG as entropy source
* `CONFIG_MCUX_ELS_PKC_ENABLE_KEY_DERIVATION` - enable key derivation support

This library is also used as the hardware acceleration backend of the PSA crypto driver in Zephyr, selected there with `CONFIG_MCUX_PSA_CRYPTO_DRIVER_ELS_PKC`.

See `zephyr/Kconfig` and `zephyr/CMakeLists.txt` for the complete and up-to-date list of options and their dependencies.

## License
This repository is under the **BSD-3-Clause** license. See the `LICENSE.txt` file for details. Some content is licensed under **Apache-2.0**, see the `LICENSE_Apache-2.0.txt` file and `SBOM.spdx.json` for the per-component license information.
