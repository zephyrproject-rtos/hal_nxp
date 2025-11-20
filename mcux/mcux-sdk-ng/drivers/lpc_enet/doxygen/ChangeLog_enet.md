# LPC_ENET

## [2.3.5]

- Bug Fixes
  - Fixed ENET_GetMacAddr address byte order not matching ENET_SetMacAddr.

## [2.3.4]

- Bug Fixes
  - Fixed the issue that free wrong buffer address when one frame stores in multiple buffers and memory pool is
    not enough to allocate these buffers to receive one complete frame.
  - Fixed the issue that ENET_DropFrame checks the buffer descriptor flag after it has been re-initialized.
  - Fixed the ENET_GetRxFrame FCS calculation issue.
  - Fixed the issue that there's no valid error type in the return structure when Rx error bit is set.

## [2.3.3]

- Bug Fixes
  - Fixed the issue that ENET_SetSMI uses wrong clock source to calculate the divisor.

## [2.3.2]

- New features
  - Added hardware checksum acceleration support.
- Bug Fixes
  - Fixed the issue that enable/disable interrupt APIs miss part of configuration.

## [2.3.1]

- Improvements
  - update ENET_SetSYSControl to support mcx family.

## [2.3.0]

- Improvements
  - Added MDIO access wrapper APIs for ease of use.

## [2.2.0]

- Bug Fixes
  - Corrected the timestamp retrieving code in ReadFrame.
- New Features
  - Supported zero copy Rx with new APIs.
- Improvements
  - Removed 4 bytes CRC data in ReadFrame function, not give them to user.
  - Deleted previous timestamp rings which store Tx/Rx timestamp temporarily for further retrieving.
    Now get Rx timestamp directly with receiving frame API, and get Tx timestamp in Tx over interrupt
    handler callback.
  - Added channel parameter for the SendFrame function, let user to decide which kind of frame can be
    sent from specified channel.
  - Supported scattered Tx buffers and more Tx configurations in SendFrame which aren't integrated.
  - Adjusted the callback location in Tx reclaim function. When use multiple BDs for Tx, only last BD
    transmit over interrupt event calls the callback. It simplifies the usage of Tx reclaiming.
  - Added interrupt configuration in config parameter for ENET_Init() to simplify the interrupt enable.
  - Changed the Tx/Rx descriptor name to common name rather than previous read format name which make
    user confused when driver uses it as write-back format.

## [2.1.5]

- Bug Fixes
  - Fixed violations of the MISRA C-2012 rules 3.1,5.8,8.4,8.6,10.1,10.3,10.4,10.6,10.8,11.6,11.9,12.2,14.4,15.6,17.7,21.15.

## [2.1.4]

- Bug Fixes
  - Fixed the MDC clock divider setting issue occurring when core clock range exceeds 150M.

## [2.1.3]

- In ENET_StartRxTx, updated to enable TX and RX at the same time to avoid issue where ENET module could not work
  under 10 M.
- Changed to use CLOCK_GetCoreSysClkFreq() instead of SystemCoreClock to get accurate core clock.

## [2.1.2]

- Bug Fixes
  - Fixed ENET receive issue where it sometimes lost some unicast packets. The issue is caused by the program
    timing issue for writing MAC_ADDR_LOW and MAC_ADDR_HIGH.

## [2.1.1]

- New Features
  - Added a control macro to enable/disable the CLOCK code in current driver.

## [2.1.0]

- New Features
  - Added two APIs to set the ENET to ACCPET or reject the multicast frames.

## [2.0.0]

- Initial version.
