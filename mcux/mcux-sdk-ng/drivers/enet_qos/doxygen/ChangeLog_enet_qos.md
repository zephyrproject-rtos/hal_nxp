# ENET_QOS

## [2.7.2]

- Bug Fixes
  - Not disabling ENET_QOS_ConfigureRxParser function when compiled for EMAC,
    as the MTL_RXP_INDIRECT_ACC_DATA register is writeable now.

## [2.7.1]

- Bug Fixes
  - Fixed writing after DMA_CH array on platforms with smaller number of channels (EMAC).

## [2.7.0]

- New features
  - The driver can work with EMAC IP now. EMAC is similar to ENET_QOS but doesn't support 100 % of its features.

## [2.6.5]

- Bug Fixes
  - Fixed ENET_QOS_GetMacAddr address byte order not matching ENET_QOS_SetMacAddr.

## [2.6.4]

- Improvements
  - ENET_QOS_SetMII returns success or failure status now (related to i.MX RT1170 errata ERR050539 - ENET_QOS doesn't support RMII 10Mbps mode).
- Bug Fixes
  - Fixed the MISRA C-2012 issue rule 14.3.

## [2.6.3]

- Bug Fixes
  - Fixed the issue that ENET_QOS_GetRxFrame, ENET_QOS_ReadFrame and ENET_QOS_DropFrame did not properly restart the receiving once it stopped.

## [2.6.2]

- Bug Fixes
  - Fixed the issue that free wrong buffer address when one frame stores in multiple buffers and memory pool is
    not enough to allocate these buffers to receive one complete frame.

## [2.6.1]

- Bug Fixes
  - Fixed the issue that ENET_QOS_ReadFrame doesn't check timestamp available bit before check the context BD bit, it makes software update extra BD.
    If DMA receives new frame to this BD before software update, software will lose this frame.

## [2.6.0]

- New features
  - Added hardware checksum acceleration support.

## [2.5.3]

- Bug Fixes
  - Fixed the MISRA issue rule 14.3, 5.3.

## [2.5.2]

- Bug Fixes
  - Fixed the issue that ENET_QOS_Init reset the MDIO setting of ENET_QOS_SetSMI.

## [2.5.1]

- Improvements
  - Supported RMII mode.

## [2.5.0]

- Improvements
  - Added MDIO access wrapper APIs for ease of use.

## [2.4.1]

- Improvements
  - Supported cache control.
  - Supported BD address convertion to system address.
  - Make driver aarch64 compatible
- Bug Fixes
  - Fixed the issue that driver internal interface ENET_QOS_DropFrame drops all frames in whole BD ring rather than one frame as design.
    Impact case: 1. Rx drop occurs in zero copy Rx API ENET_QOS_GetRxFrame. 2. Call ENET_QOS_ReadFrame with data pointer is NULL, driver will drop all Rx frames.

## [2.4.0]

- New features
  - Added MDIO IEEE802.3 Clause 45 access support.
  - Added get statistics API to get some statistical data in transfer.
  - Added new APIs to support zero copy Rx.
  - Fixed the MISRA issue rule 8.4, 8.6.

## [2.3.0]

- Improvements
  - Added counter to record multicast hash conflict in struct _enet_handle, improved the situation that one multicast
    group could be left by other conflict multicast address left operation.
- Bug Fixes
  - Updated txDirtyRing maintenance in reclaim and send frame process, allow txDirtyRing to be overwritten.
  - Disabled carrier sensing in full duplex mode configuration in ethernet initialization
  - Fixed 1588 sub-second calculate issue.

## [2.2.2]

- Bug Fixes
  - Fixed the issue that ENET_QOS_SetupTxDescriptor didn't handle the DMA access address mapping for SoCs have feature FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET.
  - Fixed MISRA 2012 violations detected in examples build.

## [2.2.1]

- Bug Fixes
  - Fixed MISRA 2012 violations, fixed doxygen warning.
  - Fixed the issue that cache invalidate to invalid converted memory address in ENET_QOS_ReadFrame for SoCs have feature FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET.

## [2.2.0]

- Removed the ptp time data ring management, below structures and APIs are removed:
  - structure enet_qos_ptp_time_data_t
  - structure enet_qos_ptp_time_data_ring_t
  - API ENET_QOS_GetRxFrameTime
  - API ENET_QOS_GetTxFrameTime
- Added API for GCL list read and AVB configuration
  - ENET_QOS_EstReadGcl
  - ENET_QOS_AVBConfigure
- Improved driver for PTP system time configuration, timestamp read.
- Added IRQ lock and memory barrier instruction for descriptor operation.
- Fixed MISRA 2012 violations

## [2.1.1]

- Bug Fixes
  - Fixed the bug that data pointer is not converted to local memory
    address in the call to ENET_QOS_Ptp1588ParseFrame.

## [2.1.0]

- New feature
  - Update driver to support feature FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET which convert buffer address to visible address for DMA.
  - Require user to provide implementation for ENET_QOS_SetSYSControl API, which set the PHY interface and enable clock generation for IP.

## [2.0.0]

- Initial version.
