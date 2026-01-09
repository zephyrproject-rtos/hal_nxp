# Wireless Connectivity Framework
---

Connectivity Framework repository provides both connectivity platform enablement with hardware abstraction layer and a set of Services for NXP connectivity stacks : BLE, Zigbee, OpenThread, Matter.

The connectivity framework repository consists of:
  - Common folder to common header files for minimal type definition to be used in the repo
  - Platform folder used for platform enablement with Hardware abstraction:
     - platform/include: common API header files used by several platforms
     - platform/common: common code for several platforms
     - specifics platform folders , See below the supported platform list
     - platform/../configs folder: configuration files for framework repository and other middlewares (rpmsg, mbedTls, etc.._)
  - Services folder
  - Zephyr folder for zephyr modules integrated in mcux SDK
  - clang formatting script and script folder to format appropriately the source files of the repo

## Supported platforms
The following devices/platforms are supported in platform folder for connectivity applications:
  - kw45x, k32w1x, mcxw71x, under wireless_mcu, kw45_k32w1_mcxw71 folders.
  - kw47x, mcxw72x families under wireless_mcu, kw47_mcxw72, kw47_mcxw72_nbu folders.
  - rw61x
  - RT1060 and RT1170 for Matter
  - Other RT devices such as i.MX RT595s

## Supported services
The supported services are provided for connectivity stacks and their demo application, and are usually dependent on PLATFORM API implementation:
  - DBG: Light Debug Module, currently a stubbed header file
  - FSCI: Framework Serial Communication Interface between BLE host stack and upper layer located on an other core/device
  - FunctionLib: wrapper to toolchain memory manipulation functions (memcpy, memcmp, etc) or use its own implementation for code size reduction
  - HWParameters: Store Factory hardware parameters and Application parameters in Flash or IFR
  - LowPower: wrapper of SDK power manager for connectivity applications
  - ModuleInfo: Store and handle connectivity component versions
  - NVM: NXP proprietary File System used for KW45, KW47 automotive devices and RT1060/RT1170 platform for Matter
  - OtaSupport: Handle OTA binary writes into internal or external flash.
  - SecLib and RNG: Crypto and Random Number generator functions. It supports several ports:
    - Software algorithms
    - Secure subsystem interface to an HW enclave
    - MbedTls 2.x interface
  - Sensors: Provides service for Battery and temperature measurements
  - SFC: Smart Frequency Calibration to be run from KW47/MCXW71 from NBU core.
  Matter related modules:
  - OTW: Over The Wire module for External Transceiver firmware update from RT platforms
  - FactoryDataProvider to be used for Matter

## Supported Zephyr modules integration in mcux SDK
Connectivity framework provides integration and port layers to the following Zephyr Modules located into zephyr/subsys:
   - NVS: Zephyr File System used by Matter and Zigbee
   - Settings: Over layer module that allows to store keys into NVS File System used by Matter
Port layer and required libraries for these zephyr modules are located in port and lib folder in zephyr directory
