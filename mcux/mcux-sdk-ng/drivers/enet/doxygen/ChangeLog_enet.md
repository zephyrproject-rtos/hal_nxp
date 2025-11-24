# ENET

## [2.11.0]

- New Features
  - Added function ENET_Ptp1588JumpTimer which adjusts the ENET PTP 1588 timer by jumping
    a relative time difference. Compared to ENET_Ptp1588SetTimer, this function yields
    more accurate results when the relative time difference between the PTP clock and
    the target clock is known.

## [2.10.1]

- Bug Fixes
  - Fixed WAKEUP interrupt not being handled.

## [2.10.0]

- New Features
  - Added function ENET_Ptp1588GetChannelCaptureValue to read last captured time from PTP 1588 timer.

## [2.9.3]

- Bug Fixes
  - Fixed ENET_Ptp1588GetTimer incorrect timestamps when timer wraps occur after nanosecond capture:
    - Now only increments second field when nanosecond value is less than half a second

## [2.9.2]

- Bug Fixes
  - RGMII mode is (temporarily) disabled before selecting between 10/100-Mbit/s and 1000-Mbit/s
    modes of operation. The bit RGMII_EN of RCR register must not be set while changing ECR
    register's speed bit, otherwise there is a possibility of ENET IP ending in an incorrect state.

## [2.9.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 8.4, 10.4.

## [2.9.0]

- Bug Fixes
  - Enabled collection of transfer statistics, so the function ENET_GetStatistics does not always return zeroes.
- New Features
  - Added new function ENET_EnableStatistics to enable/disable collection of transfer statistics.
  - Added new function ENET_ResetStatistics to reset transfer statistics.
- Improvements
  - Renamed the function ENET_ResetHareware to ENET_ResetHardware.

## [2.8.0]

- New Features
  - Added the function to reset hardware on certain devices.

## [2.7.1]

- Bug Fixes
  - Fixed the issue that free wrong buffer address when one frame stores in multiple buffers and memory pool is
    not enough to allocate these buffers to receive one complete frame.

## [2.7.0]

- Improvements
  - Deleted deprecated zero copy Tx/Rx functions and set callback function which can be configured in ENET_Init.
  - Moved the Rx zero copy buffer allocation to Rx BD initialization function to reduce unnecessary looping code.
- Bug Fixes
  - Fixed the issue that predefined Rx buffers which should not be used when enabling Rx zero copy are still be
    handled by cache operation, it causes hardfault on some platforms.
  - Fixed the issue that zero-copy Rx function doesn't check Rx length of 0 in the BD with EMPTY bit is 0, it may
    occur in the corner case reported by customer. Not sure how it turns out, consider it as an ENET IP issue and
    drop this abnormal BD.

## [2.6.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 11.6.

## [2.6.2]

- Improvements
  - Changed ENET1_MAC0_Rx_Tx_Done0_DriverIRQHandler/ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler
    to ENET1_MAC0_Rx_Tx_Done1_DriverIRQHandler/ENET1_MAC0_Rx_Tx_Done2_DriverIRQHandler which
    represent ring 1 and ring 2.

## [2.6.1]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.3, 10.4, 10.7, 11.6, 11.8.

## [2.6.0]

- Improvements
  - Added MDIO access wrapper APIs for ease of use.
  - Fixed the build warning introduced by 64-bit compatibility patch.

## [2.5.4]

- Improvements
  - Made the driver compatible with 64-bit platforms.

## [2.5.3]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 11.6.

## [2.5.2]

- Improvements
  - Updated the TXIC/RXIC register handling code according to the new header file.

## [2.5.1]

- Bug Fixes
  - Fixed document typo.

## [2.5.0]

- Bug Fixes
  - Fixed the SendFrame/SendFrameZeroCopy functions issue with scattered buffers.
  - Updated the formula of MDC calculation.
  - Used a feature macro to distinguish the old IP design from the new design, because old IP design always
    reads a value zero from ATCR->CAPTURE bit. For old IP, driver caculates and wait the necessary delay cycles
    after setting ATCR->CAPTURE then gets the timestamp value.
- New Features
  - Added new zero copy Tx/Rx function.
  - New zero copy Tx function combines scattered and contiguous Tx buffer in one API, it also supports more
    Tx featrues which buffer descriptor supports but previous Tx function doesn't support.
  - New zero copy Rx function use dynamic buffer mechanism and simpler interface.
- Improvements
  - Corrected the interrupt handler for PTP timestamp IRQ and PTP1588 event IRQ since platform difference.
  - Added missing IRQ handlers for PTP1588 events on some platforms.
  - Corrected the max Tx frame length verification, it will not depend on a fixed macro. The ENET_FRAME_MAX_FRAMELEN
    is only an default value for driver, application can configure it. Driver caculates the limitation with the
    max frame length in register which may takes extended 4 or 8 bytes VLAN tag if VLAN/SVLAN enables.
  - Deleted deprecated Clause 45 read/write legacy APIs.

## [2.4.3]

- Improvements
  - Aligned the IRQ handler name with header file.

## [2.4.2]

- Bug Fixes
  - Fixed the MISRA issue of speculative out-of-bounds access.

## [2.4.1]

- Bug Fixes
  - Fixed the PTP time capture issue.

## [2.4.0]

- Improvements
  - Exposed API ENET_ReclaimTxDescriptor for user application to relaim tx descriptors in their application.
  - Added counter to record multicast hash conflict in struct _enet_handle, improved the situation that one multicast
    group could be left by other conflict multicast address left operation.
  - Improved concurrent usage of relaim and send frame operation.

## [2.3.4]

- Bug Fixes
  - Fixed the issue that interrupt handler only checks the interrupt event flag but not checks interrupt mask flag.

## [2.3.3]

- Bug Fixes
  - Fixed the issue that some compilers may choose the memcpy with 4-bit aligned address limitation due to the type of
    address pointer is 'unsigned int *', the data address doesn't have to be 4-bit aligned.

## [2.3.2]

- New Features
  - Added the feature that ENET driver can be used in the platform which integrates both 10/100M and 1G ENET IP.
  - Deleted duplicated code about ARM errata 838869 in first/second level IRQ handler.

## [2.3.1]

- Improvements
  - Added function pointer checking in IRQ handler to make sure code can be used even it runs into
    the interrupt when the second level interupt handler is NULL.

## [2.3.0]

- Bug Fixes
  - Fixed the issue that clause 45 MDIO read/write API doesn't check the transmission over status between two transmissions.
  - Fixed violations of the MISRA C-2012 rules 2.2,10.3,10.4,10.7,11.6,11.8,13.5,14.4,15.7,17.7.
- New Features
  - Added APIs to support send/receive frame with Zero-Copy.
- Improvements
  - Separated the clock configuration from module configuration when init and deinit.
  - Added functions to set second level interrupt handler.
  - Provided new function to get 1588 timer count without disabling interrupt.
  - Improved timestamp controlling, deleted all old timestamp management APIs and data structures.
  - Merged the single/multiple ring(s) APIs, now these APIs can handle both.
  - Used base and index to control buffer descriptor, aligned with qos and lpc enet driver.

## [2.2.6]

- Bug Fixes
  - Updated MII speed formula referring to the manual.

## [2.2.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 10.1, 10.3, 10.4, 10.6, 10.7, 11.6, 11.9, 13.5, 14.4, 16.4, 17.7, 21.15, 3.1, 8.4.
  - Changed to use ARRAY_SIZE(s_enetBases) as the array size for s_ENETHandle, fixed the hardfault issue for using some ENET instance when ARRAY_SIZE(s_enetBases) is not same as FSL_FEATURE_SOC_ENET_COUNT.

## [2.2.4]

- Improvements
  - Added call to Data Synchronization Barrier instruction before activating Tx/Rx buffer descriptor to ensure
    previous data update is completed.
  - Improved ENET_TransmitIRQHandler to store timestamps for multiple transmit buffer descriptors.
  - Bug Fixes
  - Fixed the issue that ENET_Ptp1588GetTimer did not handle the timer wrap situation.

## [2.2.3]

- Improvements
  - Improved data buffer cache maintenance in the ENET driver.

## [2.2.2]

- New Features
  - Added APIs for extended multi-ring support.
  - Added the AVB configure API for extended AVB feature support.

## [2.2.1]

- Improvements
  - Changed the input data pointer attribute to const in ENET_SendFrame().

## [2.1.1]

- New Features
  - Added the extended MDIO IEEE802.3 Clause 45 MDIO format SMI command APIs.
  - Added the extended interrupt coalescing feature.
- Improvements
  - Combined all storage operations in the ENET_Init to ENET_SetHandler API.

## [2.0.1]

- Bug Fixes
  - Used direct transmit busy check when doing data transmit.
- Miscellaneous Changes
  - Updated IRQ handler work flow.
  - Changed the TX/RX interrupt macro from kENET_RxByteInterrupt to kENET_RxBufferInterrupt, from
    kENET_TxByteInterrupt to kENET_TxBufferInterrupt.
  - Deleted unnecessary parameters in ENET handler.

## [2.0.0]

- Initial version.
