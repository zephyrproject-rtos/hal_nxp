# NETC

## [2.10.3]

- New Features
  - Supported rrt member in netc_tb_ipf_cfge_t.
  - Moved timer reference clock definition to soc to support i.MX95/i.MX943.
- Bug Fixes
  - Got right size of TX timestamp response frame.

## [2.10.2]

- Bug Fixes
  - Correct transmit start time bit width of transmit buffer descriptor format.

## [2.10.1]

- New Features
  - Supported IP version class commands in VSI-PSI message driver.
  - Added VSI3 definition.

## [2.10.0]

- Bug Fixes
  - Fixed structures used for time gate control list and stream gate request
commands memset.
- New Features
  - Added public API to query table entry in Frame Modification Table.
- Improvements
  - Optimized NETC Transmit functions: cached configuration in driver handle instead of accessing directly device
    registers at each packet transmit, and removed calls to memset/memcpy in the transmit path.

## [2.9.1]

- Improvements
  - NETC_TimerInit() will always ignore user config->atomicMode and set it to 1 internally. This guarantees that period updates, that change both the integer and fractional part are always done atomically.

## [2.9.0]

- Bug Fixes
  - Fixed padding in netc_tb_sgi_rsp_data_t union structure for query operations on OEXEN and IRXEN parameters.
  - Fixed structure use for rate policer and stream gate request commands memset.
  - Updated ERRATA 052134 to 052206.
  - Fixed MII mode setting.
  - Fixed i.MX943 getting function instance.
- New Features
  - Added API to Reset IRX and OEX flags in stream gate instance entry.
  - Added API to configure the priority to traffic class map.
  - Added APIs to query table entry and get maximum entry number for Frame Modification Table.
  - Added APIs to configure Frame preemption.
  - Added APIs to configure PSRCR and PGCR registers to implement HSR feature.
  - Moved PHY WRAPPER init sequence (NETC_PHYInit) implementation to SoC. And Added i.MX943 support.
- Improvements
  - keep netc_tb_sgi_rsp_data_t local to the low level driver functions for SGI table entry query.
  - Converted to use preinitVsi callback for VSI pre-init.
  - Added note for ERRATA 052167 to remind that actual MAC Tx IPG is longer than configured when
    transmitting back-to-back packets in MII half duplex. When using MII protocol, using full-duplex
    mode is recommended instead of half-duplex. If using MII half-duplex mode, additional bandwidth
    loss should be expected and accounted for due to extended IPG.

## [2.8.2]

- Bug Fixes
  - Fixed ingress port filter table frame attribute flags mask field issue.

## [2.8.1]

- Bug Fixes
  - Fixed MAC/VLAN filter operations through VSI-PSI message.
  - Fixed NETC_PortConfigTxIpgPreamble compile.
- Improvements
  - Enabled standard VLAN EtherTypes for i.MX95 VSIs for VLAN support.
  - Added netc_timer_exttrig_index_t definition for i.MX95.
  - Updated default BPCR[STAMVD] value setting to align the register reset value.

## [2.8.0]

- Bug Fixes
  - Fixed ERRATA 052024.
  - Fixed ERRATA 052129.
  - Fixed ERRATA 052134.
  - Fixed ERRATA 052031.
  - Fixed ERRATA 051994.
  - Fixed ERRATA 051936.
- New Features
  - Added interface to reset the mark frame red parameter.
  - Added support for FRER sequence generation reset.
  - Added NETC Switch Tag support.
  - Added the Tx offload feature support.
- Improvements
  - Simplify NETC_TimerGetFreeRunningTime. Hardware synchronizes reads from high/low
    registers for the free running time. No need to do it in software.

## [2.7.2]

- Bug Fixes
  - Fixed MISRA issue rule 4.10, 10.1, 10.3, 10.4, 10.7, 10.8, 11.3, 16.1, 16.4, 17.7.

## [2.7.1]

- Bug Fixes
  - Fixed Coverity issue with array out of bounds access.

## [2.7.0]

- New Features
  - Added VSI-PSI messaging driver.
- Bug Fixes
  - Fixed the issue that EP/SWT_ReceiveFrame don't return error status when some errors occur.

## [2.6.1]

- Bug Fixes
  - Updated the MAC loopback configuration as Reference Manual.

## [2.6.0]

- New Features
  - Added API to get transmit max SDU for specified port Traffic Class.
  - Added API to query entry from the Rate Policing table.
  - Added API to retrieve maximum rate policer entries.
  - Added API to set switch port default VID separately.
  - Added API to set max frame size separately.
  - Added API to query FRER resource.
- Bug Fixes
  - Fixed the issue that stream gate query functions don't check return status.
  - Fixed the ISF table query function operation issue.
  - Fixed the wrong configuration of Tx max SDU check.
  - Fixed ERRATA 051524.
  - Fixed ERRATA 051649.
  - Fixed ERRATA 051707.
  - Fixed ERRATA 051710.
  - Fixed ERRATA 051711.
- Improvements
  - Factorized qbv basetime workaround code, and stop using synchronized time for the workaround code.
    Synchronized time functionality should be reserved for gPTP operation.

## [2.5.1]

- Improvements
  - Conditional compile NETC_ETH_LINK_PM0_COMMAND_CONFIG_HD_FCEN register.

## [2.5.0]

- New Features
  - Added PHY WRAPPER driver.
  - Added C45 support for internal MDIO.
  - Added 10G support.
- Bug Fixes
  - Fixed ERRATA 051130.
  - Fixed master bus and memory access.
- Improvements
  - Moved platform specific code to soc driver.
  - Split switch code.

## [2.4.0]

- New Features
  - Added the interrupt control functions for port MAC module.
  - Added setting parameters including half-duplex back pressure, port timestamp capture point, RGMII Tx clock stop state during
    low power idle, ports default traffic class gating states and timer atomic writing setting.
  - Added NETC_TimerInitHandle() to initialize a timer handle without modifying hardware state. Required to be able to read timer
    from another CPU.
  - Added NETC_TimerGetFreeRunningTime() to be able to read free running timer.
  - Added support for ingress stream gate query.
- Improvements
  - Added necessary default settings in the GetDefaultConfig functions in case some features can't work after initialization.
  - Updated loopback function according to new bit field in CRR.
  - Deleted the useless error check for ERRATA051243.
  - Updated NETC_TimerGetCurrentTime() to avoid using synchronized time and be able to read the time from different threads/cpus
    without locking.
  - Deleted the useless priority check in NETC_PortConfigTcCBS().
- Bug Fixes
  - Fixed typo in NETC_PortConfig.

## [2.3.2]

- Bug Fixes
  - Added workaround for ERRATA051587.

## [2.3.1]

- Bug Fixes
  - Fixed MISRA issue rule 10.3, 10.4, 10.8, 11.6, 11.7.

## [2.3.0]

- Bug Fixes
  - Added SWT_PortStop() API for ERRATA051398.
  - Fixed the build error by add feature macro for port FCS Error Action feature.
  - Removed duplicate code from NETC_PortEthMacGracefulStop() API.
  - Fixed MISRA issue rule 8.6, 10.4, 11.9, 14.4.

## [2.2.2]

- Bug Fixes
  - Fixed the issue that NETC_PortSetSpeed() would overwrite the full PCR register.

## [2.2.1]

- Improvements
  - Fixed cpp build warning.

## [2.2.0]

- Bug Fixes
  - Fixed the issue that NETC_ConfigTGSAdminList() doesn't clear the previous command response data status filed.
  - Fixed the issue that EP_ReceiveFrameCopy(&handle, 0, NULL, 0, NULL) can't drop error frame.
  - Fixed the issue that SWT_GetTimestampRefResp can't get Switch Tx TS Resp with no MgmtRxBdRing.
  - Fixed the issue that RGMII Half Duplex mode misconfigured.
  - Fixed the issue that missing workaround for ERR050679, ERR051246 and ERR051254.
  - Fixed the issue that missing feature macro for ERR051130, ERR051202, ERR051260.
  - Fixed the issue that ep/swt_tx_opt struct use wrong vlan tag tpid value.
  - Fixed MISRA issue rule 5.8, 8.3, 8.12, 10.1, 10.3, 10.4, 10.6, 10.7, 10.8, 11.6, 11.8, 12.2, 14.4, 15.5, 15.6,
    16.1, 16.3, 16.4, 17.7.
  - Fixed the issue that internal MDIO read function uses wrong register.
  - Fixed the issue that SWT_TxPortTGSEnable()/EP_TxPortTGSEnable() still uses the default timer after enabling the 1588 timer.
  - Remove the resetCount parameter from get port discard statistic APIs because the registers required by this function have been
    removed from hardware design.
  - Fixed the issue that SWT/EP_ReclaimTxDesc() can't call reclaim callback for each full frame.
  - Fixed the issue in NETC_TimerAdjustFreq().
- New Features
  - Added the support for 1588 One-Step timestamp when chip doesn't have ERR051255.
  - Added APIs to get dynamic table remaining available entry numbers.
  - Added APIs to get static table number of entries.
- Improvements
  - Return detail error status instead of kStatus_Fail in NTMP APIs.
  - Rename feature macros and move them into the feature file.
  - Optimize the implementation of the NETC_TimerAddOffset() function to avoid change the TMR_CNT_L/H registers,
    and add required procedure for call NETC_TimerAddOffset() API in the comments.
  - Update the SWT_FMDUpdateTableEntry()/SWT_FMDQueryTableEntry() APIs to make them use internel table buffer.
  - Update SWT_TxPortTGSEnable()/EP_TxPortTGSEnable() to make it can config the default administration gate control list gates' state.
  - Use TMR_SRT_L/H instead of TMR_CUR_TIMER when want to get current 1588 timer value.

## [2.1.0]

- Bug Fixes
  - Fixed the issue that EP_RxL2MFInit doesn't set the multicast promiscuous correctly.
  - Fixed the timer add offset issue.
  - Fixed the issue that all ENETC/Switch PCIe functions must be enabled firstly before
    triggering EP/SWT NTMP access and MSIX messages.
  - Fixed RT1180 NETC errata 051202: Configure Tx MAC to wait until 32 bytes of data are
    built up in the transmit FIFO before beginning transmission on the link.
  - Added workaround for RT1180 NETC errata 051130: C Egress time gate scheduling can get
    corrupted when functional level reset is applied or when time gating is disabled.
  - Fixed bugs in statistic APIs.
- New Features
  - Added the support for EP VSI transmission and PSI-VSI message exchanging.
  - Added EP receive regular frame zero-copy support.
  - Integrated EMDIO support in NETC MDIO driver for accessing PHY when EP/Switch function
    isn't enabled.
  - Added Timer and Switch MSIX table configuration support.
  - Added update entry APIs for IPF/VF/FDB/L2MCF/IS/ISF/SGI/RP/FM/ET/ISEQG tables, and
    search entry APIs for FDB/L2MCF table.
  - Added Ingress buffer pool table config APIs.
  - Added MAC Tx padding and Rx min/max frame size configuration to support Tx/Rx frames smaller than 64 bytes.
  - Added API to do graceful Stop for ETH MAC.
- Improvements
  - Used Rx buffer address array provided by application instead of buffer start address with
    contiguous memory to make the Rx buffer setup more flexible.
  - Added ring and userData parameter in the Tx reclaim callback.
  - Updated NETC hardware layer folder name from 'hw' to 'netc_hw'.
  - Stored necessary EP and SWT configurations constant in handle structure instead of storing
    pointer which forces appliction to keep static configuration structure data.
  - Updated NETC_MsixXxx to EP_MsixXxx to differentiate with corresponding SWT/Timer MSIX
    configuration APIs.
  - Aligned TGSL/SGCL API with enet_qos high-level driver.
  - Updated EP/Switch config structure to include all port related config.
  - Updated Switch transfer API only send management frame (Direct enqueue and Switch Port Masquerading)
    and only receive Host Reason no-zero frames.
  - Updated EP transfer API only send/receive regular frames.
  - Updated Switch/EP handle to make them use independent cache maintain, alloc/free memory and reclaimCallback
    functions.

## [2.0.0]

- Initial version.
