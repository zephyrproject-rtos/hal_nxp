/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_HWACCESS_H
#define I3C_IP_HWACCESS_H

/**
*   @file
*
*   @addtogroup i3c_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I3c_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID_HWACCESS                    43
#define I3C_IP_MODULE_ID_HWACCESS                    255
#define I3C_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS     4
#define I3C_IP_AR_RELEASE_MINOR_VERSION_HWACCESS     7
#define I3C_IP_AR_RELEASE_REVISION_VERSION_HWACCESS  0
#define I3C_IP_SW_MAJOR_VERSION_HWACCESS             0
#define I3C_IP_SW_MINOR_VERSION_HWACCESS             9
#define I3C_IP_SW_PATCH_VERSION_HWACCESS             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I3c_Ip header file are of the same vendor */
#if (I3C_IP_VENDOR_ID_HWACCESS != I3C_IP_VENDOR_ID)
    #error "I3c_Ip_HwAccess.h and I3c_Ip.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_HWACCESS     != I3C_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_HWACCESS     != I3C_IP_AR_RELEASE_MINOR_VERSION) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION_HWACCESS  != I3C_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I3c_Ip_HwAccess.h and I3c_Ip.h are different"
#endif

/* Check if current file and I3c_Ip header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION_HWACCESS != I3C_IP_SW_MAJOR_VERSION) || \
     (I3C_IP_SW_MINOR_VERSION_HWACCESS != I3C_IP_SW_MINOR_VERSION) || \
     (I3C_IP_SW_PATCH_VERSION_HWACCESS != I3C_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of I3c_Ip_HwAccess.h and I3c_Ip.h are different"
#endif

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define I3C_START_SEC_CODE
#include "I3c_MemMap.h"

/**
* @brief      Clear the I3C master error status.
* @details    Clear the I3C master error status.
*
* @param[in]  Base              Table of base addresses for I3C instances
* @param[in]  MasterErrorMask   Mask of the error/warning to be cleared
*
*/
static inline void I3c_Ip_MasterClearErrorStatusFlags(I3C_Type * const Base,
                                                      uint32 MasterErrorMask)
{
    Base->MERRWARN = MasterErrorMask;
}

/**
* @brief      Clear the I3C slave error status.
* @details    Clear the I3C slave error status.
*
* @param[in]  Base             Table of base addresses for I3C instances
* @param[in]  SlaveErrorMask   Mask of the error/warning to be cleared
*
*/
static inline void I3c_Ip_SlaveClearErrorStatusFlags(I3C_Type * const Base,
                                                     uint32 SlaveErrorMask)
{
    Base->SERRWARN = SlaveErrorMask;
}

/**
* @brief      Clear I3C master status flag.
* @details    Clear I3C master status flag.
*
* @param[in]  Base  Table of base addresses for I3C instances
* @param[in]  Base  Status mask
*
*/
static inline void I3c_Ip_MasterClearStatus(I3C_Type * const Base,
                                            const uint32 Status)
{
    Base->MSTATUS = (Status | I3C_MSTATUS_TXNOTFULL_MASK);
}

/**
* @brief      Clear I3C slave status flag.
* @details    Clear I3C slave status flag.
*
* @param[in]  Base  Table of base addresses for I3C instances
* @param[in]  Base  Status mask
*
*/
static inline void I3c_Ip_SlaveClearStatus(I3C_Type * const Base,
                                           const uint32 Status)
{
    Base->SSTATUS = (Status | I3C_SSTATUS_TXNOTFULL_MASK);
}

/**
* @brief      Enables the master interrupts given as input parameter.
* @details    Enables the master interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_MasterEnableInterrupts(I3C_Type * const Base,
                                                 uint32 Interrupts)
{
    Base->MINTSET |= Interrupts;
}

/**
* @brief      Disables the master interrupts given as input parameter.
* @details    Disables the master interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_MasterDisableInterrupts(I3C_Type * const Base,
                                                  uint32 Interrupts)
{
    Base->MINTCLR = Interrupts;
}

/**
* @brief      Enables the slave interrupts given as input parameter.
* @details    Enables the slave interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_SlaveEnableInterrupts(I3C_Type * const Base,
                                                uint32 Interrupts)
{
    Base->SINTSET |= Interrupts;
}

/**
* @brief      Disables the slave interrupts given as input parameter.
* @details    Disables the slave interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_SlaveDisableInterrupts(I3C_Type * const Base,
                                                 uint32 Interrupts)
{
    Base->SINTCLR = Interrupts;
}

/**
* @brief      Enables/disables the master.
* @details    Indicates if the master is enabled and what states are allowed for it.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  MasterEnable  Master mode: on, off, capable, I2c
*
*/
static inline void I3c_Ip_MasterEnable(I3C_Type * const Base,
                                       I3c_Ip_MasterEnableType MasterEnable)
{
    Base->MCONFIG = (Base->MCONFIG & (~I3C_MCONFIG_MSTENA_MASK)) | I3C_MCONFIG_MSTENA(MasterEnable);
}

/**
* @brief      Sets the watermarks for I3C master Tx FIFO.
* @details    Sets the watermarks for I3C master Tx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  TxLevel   Trigger level for TX emptiness when using a FIFO
*
*/
static inline void I3c_Ip_MasterSetTxFifoWatermark(I3C_Type * const Base,
                                                   I3c_Ip_FifoTriggerLevelType TxLevel)
{
    Base->MDATACTRL = (Base->MDATACTRL & (~I3C_MDATACTRL_TXTRIG_MASK)) | (I3C_MDATACTRL_TXTRIG(TxLevel) | I3C_MDATACTRL_UNLOCK_MASK);
}

/**
* @brief      Sets the watermarks for I3C master Rx FIFO.
* @details    Sets the watermarks for I3C master Rx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  RxLevel   Trigger level for RX fullness when using a FIFO
*
*/
static inline void I3c_Ip_MasterSetRxFifoWatermark(I3C_Type * const Base,
                                                   I3c_Ip_FifoTriggerLevelType RxLevel)
{
    Base->MDATACTRL = (Base->MDATACTRL & (~I3C_MDATACTRL_RXTRIG_MASK)) | (I3C_MDATACTRL_RXTRIG(RxLevel) | I3C_MDATACTRL_UNLOCK_MASK);
}

/**
* @brief      Sets the watermarks for I3C slave Tx FIFO.
* @details    Sets the watermarks for I3C slave Tx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  TxLevel   Trigger level for TX emptiness when using a FIFO
*
*/
static inline void I3c_Ip_SlaveSetTxFifoWatermark(I3C_Type * const Base,
                                                  I3c_Ip_FifoTriggerLevelType TxLevel)
{
    Base->SDATACTRL = (Base->SDATACTRL & (~I3C_SDATACTRL_TXTRIG_MASK)) | I3C_SDATACTRL_TXTRIG(TxLevel) | I3C_SDATACTRL_UNLOCK_MASK;
}

/**
* @brief      Sets the watermarks for I3C slave Rx FIFO.
* @details    Sets the watermarks for I3C slave Rx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  RxLevel   Trigger level for RX fullness when using a FIFO
*
*/
static inline void I3c_Ip_SlaveSetRxFifoWatermark(I3C_Type * const Base,
                                                  I3c_Ip_FifoTriggerLevelType RxLevel)
{
    Base->SDATACTRL = (Base->SDATACTRL & (~I3C_SDATACTRL_RXTRIG_MASK)) | I3C_SDATACTRL_RXTRIG(RxLevel) | I3C_SDATACTRL_UNLOCK_MASK;
}

/**
* @brief      This function empties the Tx FIFO of the I3C master.
* @details    This function empties the Tx FIFO of the I3C master.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterResetTxFIFO(I3C_Type * const Base)
{
    Base->MDATACTRL |= I3C_MDATACTRL_FLUSHTB_MASK;
}

/**
* @brief      This function empties the Rx FIFO of the I3C master.
* @details    This function empties the Rx FIFO of the I3C master.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterResetRxFIFO(I3C_Type * const Base)
{
    Base->MDATACTRL |= I3C_MDATACTRL_FLUSHFB_MASK;
}

/**
* @brief      This function empties the Tx FIFO of the I3C slave.
* @details    This function empties the Tx FIFO of the I3C slave.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveResetTxFIFO(I3C_Type * const Base)
{
    Base->SDATACTRL |= I3C_SDATACTRL_FLUSHTB_MASK;
}

/**
* @brief      This function empties the Rx FIFO of the I3C slave.
* @details    This function empties the Rx FIFO of the I3C slave.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveResetRxFIFO(I3C_Type * const Base)
{
    Base->SDATACTRL |= I3C_SDATACTRL_FLUSHFB_MASK;
}

/**
* @brief      This function configures I2CBAUD, ODBAUD, PPBAUD
* @details    This function configures I2CBAUD, ODBAUD, PPBAUD
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_MasterInitBaudRate(I3C_Type * const Base,
                                             uint8 I2cBaud,
                                             uint8 OpenDrainBaud,
                                             uint8 PushPullBaud)
{
    uint32 RegValue = Base->MCONFIG;
    RegValue &= ~(I3C_MCONFIG_I2CBAUD_MASK | I3C_MCONFIG_ODBAUD_MASK | I3C_MCONFIG_PPBAUD_MASK);
    RegValue |= I3C_MCONFIG_I2CBAUD(I2cBaud)        |
                I3C_MCONFIG_ODBAUD(OpenDrainBaud)   |
                I3C_MCONFIG_PPBAUD(PushPullBaud);
    Base->MCONFIG = RegValue;
}

/**
* @brief      Master emit REQUEST.
* @details    Master emit REQUEST.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  MasterRequest Type of the request
*
*/
static inline void I3c_Ip_MasterEmitRequest(I3C_Type * const Base,
                                            I3c_Ip_MasterRequestType MasterRequest)
{
    Base->MCTRL = (Base->MCTRL & (~I3C_MCTRL_REQUEST_MASK)) | I3C_MCTRL_REQUEST(MasterRequest);
}

/**
* @brief      This function sets the configuration register for the master init.
* @details    This function sets the configuration register for the master init.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_MasterConfigInit(I3C_Type * const Base,
                                           const I3c_Ip_MasterConfigType * const Config)
{
    uint32 RegValue = Base->MCONFIG;
    RegValue &= ~(I3C_MCONFIG_DISTO_MASK  |
                  I3C_MCONFIG_HKEEP_MASK  |
                  I3C_MCONFIG_ODSTOP_MASK |
                  I3C_MCONFIG_PPLOW_MASK  |
                  I3C_MCONFIG_ODHPP_MASK  |
                  I3C_MCONFIG_SKEW_MASK);
    RegValue |= I3C_MCONFIG_DISTO(Config->DisableTimeout ? 1U : 0U) |
                I3C_MCONFIG_HKEEP(Config->MasterHighKeeper)         |
                I3C_MCONFIG_ODSTOP((Config->MasterState->OpenDrainStop) ? 1U : 0U) |
                I3C_MCONFIG_PPLOW(Config->PushPullLow)              |
                I3C_MCONFIG_SKEW(Config->Skew)                      |
                I3C_MCONFIG_ODHPP(Config->OpenDrainHighPP ? 1U : 0U);
    Base->MCONFIG = RegValue;
}

/**
* @brief      Enables the slave.
* @details    Enables the slave.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Enable    If TRUE, the slave is enabled. Otherwise, the slave is disabled.
*
*/
static inline void I3c_Ip_SlaveEnable(I3C_Type * const Base,
                                      boolean Enable)
{
    Base->SCONFIG = (Base->SCONFIG & (~I3C_SCONFIG_SLVENA_MASK)) | I3C_SCONFIG_SLVENA(Enable ? 1U : 0U);
}

/**
* @brief      This function sets the configuration parameters for the slave.
* @details    This function sets the configuration parameters for the slave.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_SlaveConfigInit(I3C_Type * const Base,
                                          const I3c_Ip_SlaveConfigType * const Config)
{
    uint32 RegValue = Base->SCONFIG;

    RegValue &= ~(I3C_SCONFIG_NACK_MASK      |
                  I3C_SCONFIG_MATCHSS_MASK   |
                  I3C_SCONFIG_S0IGNORE_MASK  |
                  I3C_SCONFIG_HDROK_MASK     |
                  I3C_SCONFIG_OFFLINE_MASK   |
                  I3C_SCONFIG_BAMATCH_MASK);
    RegValue |= I3C_SCONFIG_NACK(Config->Nack ? 1U : 0U)                |
                I3C_SCONFIG_MATCHSS(Config->MatchStartStop ? 1U : 0U)   |
                I3C_SCONFIG_S0IGNORE(Config->IgnoreS0S1Error ? 1U : 0U) |
                I3C_SCONFIG_HDROK(Config->HighDataRateSupport ? 1U : 0U)|
                I3C_SCONFIG_OFFLINE(Config->OfflineSupport ? 1U : 0U)   |
                I3C_SCONFIG_BAMATCH(Config->BusAvailableMatch);

    Base->SCONFIG = RegValue;
}

/**
* @brief      This function sets the provisional id fo the slave.
* @details    This function configures vendor Id, BCR, DCR, and Part Number of the slave device.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_SlaveConfigProvisionalId(I3C_Type * const Base,
                                                   const I3c_Ip_SlaveConfigType * const Config)
{
    Base->SVENDORID = (Base->SVENDORID & (~I3C_SVENDORID_VID_MASK)) | I3C_SVENDORID_VID(Config->VendorId);
    Base->SIDEXT = (Base->SIDEXT & (~(I3C_SIDEXT_BCR_MASK | I3C_SIDEXT_DCR_MASK))) | I3C_SIDEXT_BCR(Config->BCR) | I3C_SIDEXT_DCR(Config->DCR);
    Base->SIDPARTNO = Config->PartNumber;
}

/**
* @brief      This function sets the status fields returned by the GETSTATUS CCC.
* @details    This function configures Vendor Information, Slave Activity State, and Pending Interrupt Number.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_SlaveConfigStatusActivities(I3C_Type * const Base,
                                                      const I3c_Ip_SlaveConfigType * const Config)
{

    Base->SCTRL = (Base->SCTRL & (~(I3C_SCTRL_VENDINFO_MASK     |
                                    I3C_SCTRL_ACTSTATE_MASK     |
                                    I3C_SCTRL_PENDINT_MASK)))   |
                                    I3C_SCTRL_VENDINFO(Config->VendorInformation)   |
                                    I3C_SCTRL_ACTSTATE(Config->ActivityState)       |
                                    I3C_SCTRL_PENDINT(Config->PendingInt);
}

/**
* @brief      This function sets the I3C slave's 7-bit static address.
* @details    This function sets the I3C slave's 7-bit static address.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  SlaveAddress  I3C Slave 7-bit SA
*
*/
static inline void I3c_Ip_SlaveSetStaticAddr(I3C_Type * const Base,
                                             const uint8 SlaveAddress)
{
    Base->SCONFIG = (Base->SCONFIG & (~I3C_SCONFIG_SADDR_MASK)) | I3C_SCONFIG_SADDR(SlaveAddress);
}

/**
* @brief      This function returns true if a master error/warning occurred.
* @details    Possible erros/warnings: improper register use, overrun or underrun of FIFO/buffer,
*             invalid parity or CRC in DDR read, and others.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline boolean I3c_Ip_MasterCheckErrorEvent(const I3C_Type * const Base)
{
    return (boolean)((Base->MSTATUS & I3C_MSTATUS_ERRWARN_MASK) != 0U);
}

/**
* @brief      This function returns true if a slave error/warning occurred.
* @details    This function returns true if a slave error/warning occurred.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline boolean I3c_Ip_SlaveCheckErrorEvent(const I3C_Type * const Base)
{
    return (boolean)((Base->SSTATUS & I3C_SSTATUS_ERRWARN_MASK) != 0U);
}

/**
* @brief      This function returns true if the interrupt given as parameter was spurious.
* @details    This function returns true if the interrupt given as parameter was spurious.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  InterruptMask Interrupt mask
*
*/
static inline boolean I3c_Ip_MasterCheckSpuriousInt(const I3C_Type * const Base,
                                                    uint32 InterruptMask)
{
    return (boolean)((Base->MINTMASKED & InterruptMask) == 0U);
}

/**
* @brief      This function returns true if the interrupt given as parameter was spurious.
* @details    This function returns true if the interrupt given as parameter was spurious.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  InterruptMask Interrupt mask
*
*/
static inline boolean I3c_Ip_SlaveCheckSpuriousInt(const I3C_Type * const Base,
                                                   uint32 InterruptMask)
{
    return (boolean)((Base->SINTMASKED & InterruptMask) == 0U);
}

/**
* @brief      This function returns true if the status flag given as parameter is set.
* @details    This function returns true if the status flag given as parameter is set.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Status    Status flag
*
*/
static inline boolean I3c_Ip_MasterCheckStatus(const I3C_Type * const Base,
                                               const uint32 Status)
{
    return (boolean)((Base->MSTATUS & Status) != 0U);
}

/**
* @brief      This function returns true if the status flag given as parameter is set.
* @details    This function returns true if the status flag given as parameter is set.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Status    Status flag
*
*/
static inline boolean I3c_Ip_SlaveCheckStatus(const I3C_Type * const Base,
                                              const uint32 Status)
{
    return (boolean)((Base->SSTATUS & Status) != 0U);
}

/**
* @brief      This function returns true if the state given as parameter is the current master state.
* @details    This function returns true if the state given as parameter is the current master state.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  State     Master state
*
*/
static inline boolean I3c_Ip_MasterGetState(const I3C_Type * const Base,
                                            const uint32 State)
{
    uint32 RegValue = Base->MSTATUS;
    RegValue = (RegValue & I3C_MSTATUS_STATE_MASK) >> I3C_MSTATUS_STATE_SHIFT;
    return (boolean)((RegValue & State) == State);
}

/**
* @brief      This function is used to set the slave's vendor information, activity state, and pending interrupt.
* @details    This information should be maintained by the application because it is read by the master using GETSTATUS CCC command.
*
* @param[in] Base               Table of base addresses for I3C instances
* @param[in] VendorInfo         Vendor information
* @param[in] ActivityState      Activity state
* @param[in] PendingInterrupt   Pending interrupt
*
*/
static inline void I3c_Ip_SlaveSetAppActivityFields(I3C_Type * const Base,
                                                    const uint8 VendorInfo,
                                                    const uint8 ActivityState,
                                                    const uint8 PendingInterrupt)
{
    uint32 RegValue = Base->SCTRL;
    RegValue &= ~(I3C_SCTRL_VENDINFO_MASK |
                  I3C_SCTRL_ACTSTATE_MASK |
                  I3C_SCTRL_PENDINT_MASK);

    RegValue |= I3C_SCTRL_VENDINFO(VendorInfo)      |
                I3C_SCTRL_ACTSTATE(ActivityState)   |
                I3C_SCTRL_PENDINT(PendingInterrupt);
    Base->SCTRL = RegValue;
}

/**
* @brief      This function is used to configure a slave at runtime, after it was the main master and handed off the mastership.
* @details    This function is used to configure a slave at runtime, after it was the main master and handed off the mastership.
*
* @param[in] Base               Table of base addresses for I3C instances
* @param[in] MapIndex           Map index for which the configuration is done
* @param[in] MapAddressOptions  Slave characteristics for the mapped addresses
*
*/
static inline void I3c_Ip_SlaveSetMapAddressFields(I3C_Type * const Base,
                                                   const uint8 MapIndex,
                                                   I3c_Ip_SlaveMapAddressType MapAddressOptions)
{
    uint32 RegValue;

    if (1U == MapIndex)
    {
        RegValue = Base->SMAPCTRL1;
        RegValue &= ~(I3C_SMAPCTRL1_ENA_MASK   |
                      I3C_SMAPCTRL1_ADDR_MASK  |
#if (STD_ON == I3C_IP_SA10B_SUPPORT)
                      I3C_SMAPCTRL1_SA10B_MASK |
#endif /* (STD_ON == I3C_IP_SA10B_SUPPORT) */
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
                      I3C_SMAPCTRL1_AUTO_MASK |
                      I3C_SMAPCTRL1_DCR_MASK  |
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */
                      I3C_SMAPCTRL1_MAPSA_MASK |
                      I3C_SMAPCTRL1_NACK_MASK);

        RegValue |= I3C_SMAPCTRL1_ENA(MapAddressOptions.Enable ? 1U : 0U)   |
                    I3C_SMAPCTRL1_ADDR(MapAddressOptions.Address)           |
#if (STD_ON == I3C_IP_SA10B_SUPPORT)
                    I3C_SMAPCTRL1_SA10B(MapAddressOptions.SA10BitExtension) |
#endif /* (STD_ON == I3C_IP_SA10B_SUPPORT) */
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
                    I3C_SMAPCTRL1_AUTO(MapAddressOptions.Auto ? 1U : 0U)    |
                    I3C_SMAPCTRL1_DCR(MapAddressOptions.DCR)                |
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */
                    I3C_SMAPCTRL1_MAPSA(MapAddressOptions.AddressType)      |
                    I3C_SMAPCTRL1_NACK(MapAddressOptions.Nack ? 1U : 0U);

        Base->SMAPCTRL1 = RegValue;
    }
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
    else if (MapIndex >= 2U)
    {
        RegValue = Base->SMAPCTRL[MapIndex - 2U]; /* Map Control array starts with index 0, corresponding to SMAPCTRL2 */
        RegValue &= ~(I3C_SMAPCTRL_ENA_MASK   |
                      I3C_SMAPCTRL_ADDR_MASK  |
                      I3C_SMAPCTRL_MAPSA_MASK |
                      I3C_SMAPCTRL_NACK_MASK  |
                      I3C_SMAPCTRL_AUTO_MASK  |
                      I3C_SMAPCTRL_DCR_MASK);
        RegValue |= I3C_SMAPCTRL_ENA(MapAddressOptions.Enable ? 1U : 0U)   |
                    I3C_SMAPCTRL_ADDR(MapAddressOptions.Address)           |
                    I3C_SMAPCTRL_MAPSA(MapAddressOptions.AddressType)      |
                    I3C_SMAPCTRL_NACK(MapAddressOptions.Nack ? 1U : 0U)    |
                    I3C_SMAPCTRL_AUTO(MapAddressOptions.Auto ? 1U : 0U)    |
                    I3C_SMAPCTRL_DCR(MapAddressOptions.DCR);

        Base->SMAPCTRL[MapIndex - 2U] = RegValue;
    }
    else
    {
        /* Do nothing */
    }
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */
}

/**
* @brief      The main master assigns its own Dynamic Address before handing off the mastership.
* @details    This function is used to set a Dynamic Address for the main master before handing off the mastership.
*
* @param[in] Base       Table of base addresses for I3C instances
* @param[in] Address    Dynamic Address for the main master to set before becoming a slave
* @param[in] Valid      If TRUE, a Dynamic Address is assigned
*
*/
static inline void I3c_Ip_MasterWriteOwnDAFields(I3C_Type * const Base,
                                                 const uint8 Address,
                                                 const boolean Valid)
{
    uint32 RegValue = Base->MDYNADDR;
    RegValue &= ~(I3C_MDYNADDR_DADDR_MASK | I3C_MDYNADDR_DAVALID_MASK);
    RegValue |= I3C_MDYNADDR_DADDR(Address) | I3C_MDYNADDR_DAVALID(Valid ? 1U : 0U);
    Base->MDYNADDR = RegValue;
}

/**
* @brief      Clear the I3C all master status and error flags.
* @details    Clear the I3C all master status and error flags.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterClearAllStatusFlags(I3C_Type * const Base)
{
    I3c_Ip_MasterClearStatus(Base, (I3C_MSTATUS_SLVSTART_MASK  |
                                    I3C_MSTATUS_MCTRLDONE_MASK |
                                    I3C_MSTATUS_COMPLETE_MASK  |
                                    I3C_MSTATUS_IBIWON_MASK    |
                                    I3C_MSTATUS_NOWMASTER_MASK));

    I3c_Ip_MasterClearErrorStatusFlags(Base, (I3C_IP_MASTER_ERROR_NACK            |
                                              I3C_IP_MASTER_ERROR_WRITE_ABORT     |
                                              I3C_IP_MASTER_ERROR_TERM            |
                                              I3C_IP_MASTER_ERROR_PARITY          |
                                              I3C_IP_MASTER_ERROR_CRC             |
                                              I3C_IP_MASTER_ERROR_OREAD           |
                                              I3C_IP_MASTER_ERROR_OWRITE          |
                                              I3C_IP_MASTER_ERROR_MSG             |
                                              I3C_IP_MASTER_ERROR_INVALID_REQUEST |
                                              I3C_IP_MASTER_ERROR_TIMEOUT));
}

/**
* @brief      Reset all registers to default values.
* @details    Reset all registers to default values.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterReset(I3C_Type * const Base)
{
    I3c_Ip_MasterClearAllStatusFlags(Base);
    I3c_Ip_MasterDisableInterrupts(Base, (I3C_MINTCLR_SLVSTART_MASK  |
                                          I3C_MINTCLR_MCTRLDONE_MASK |
                                          I3C_MINTCLR_COMPLETE_MASK  |
                                          I3C_MINTCLR_RXPEND_MASK    |
                                          I3C_MINTCLR_TXNOTFULL_MASK |
                                          I3C_MINTCLR_IBIWON_MASK    |
                                          I3C_MINTCLR_ERRWARN_MASK   |
                                          I3C_MINTCLR_NOWMASTER_MASK));

    /* Flush master Tx and Rx FIFOs */
    I3c_Ip_MasterResetTxFIFO(Base);
    I3c_Ip_MasterResetRxFIFO(Base);

    Base->MCONFIG   = 0U;
    Base->MCTRL     = 0U;
    Base->MIBIRULES = 0U;
    Base->MDMACTRL  = 0U;
    Base->MDATACTRL = 0x80000030U;
    Base->MDYNADDR  = 0U;
}

/**
* @brief      Clear the I3C all slave status and error flags.
* @details    Clear the I3C all slave status and error flags.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveClearAllStatusFlags(I3C_Type * const Base)
{
    I3c_Ip_SlaveClearStatus(Base, (I3C_SSTATUS_START_MASK      |
                                   I3C_SSTATUS_MATCHED_MASK    |
                                   I3C_SSTATUS_STOP_MASK       |
                                   I3C_SSTATUS_DACHG_MASK      |
                                   I3C_SSTATUS_CCC_MASK        |
                                   I3C_SSTATUS_HDRMATCH_MASK   |
                                   I3C_SSTATUS_CHANDLED_MASK   |
                                   I3C_SSTATUS_EVENT_MASK));

    I3c_Ip_SlaveClearErrorStatusFlags(Base, (I3C_IP_SLAVE_ERROR_RX_OVERRUN       |
                                             I3C_IP_SLAVE_ERROR_TX_UNDERRUN      |
                                             I3C_IP_SLAVE_ERROR_TX_UNDERRUN_NACK |
                                             I3C_IP_SLAVE_ERROR_TERM             |
                                             I3C_IP_SLAVE_ERROR_INVALID_START    |
                                             I3C_IP_SLAVE_ERROR_SDR_PARITY       |
                                             I3C_IP_SLAVE_ERROR_HDR_PARITY_ERROR |
                                             I3C_IP_SLAVE_ERROR_HDR_CRC          |
                                             I3C_IP_SLAVE_ERROR_S0S1             |
                                             I3C_IP_SLAVE_ERROR_OREAD            |
                                             I3C_IP_SLAVE_ERROR_OWRITE));
}

/**
* @brief      Reset all registers to default values.
* @details    Reset all registers to default values.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveReset(I3C_Type * const Base)
{
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
    uint8 cnt = 0U;
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */

    I3c_Ip_SlaveClearAllStatusFlags(Base);
    I3c_Ip_SlaveDisableInterrupts(Base, (I3C_SINTCLR_START_MASK       |
                                         I3C_SINTCLR_MATCHED_MASK     |
                                         I3C_SINTCLR_STOP_MASK        |
                                         I3C_SINTCLR_RXPEND_MASK      |
                                         I3C_SINTCLR_TXSEND_MASK      |
                                         I3C_SINTCLR_DACHG_MASK       |
                                         I3C_SINTCLR_CCC_MASK         |
                                         I3C_SINTCLR_ERRWARN_MASK     |
                                         I3C_SINTCLR_DDRMATCHED_MASK  |
                                         I3C_SINTCLR_CHANDLED_MASK    |
                                         I3C_SINTCLR_EVENT_MASK));

    /* Flush slave Tx and Rx FIFOs */
    I3c_Ip_SlaveResetTxFIFO(Base);
    I3c_Ip_SlaveResetRxFIFO(Base);

    Base->SCONFIG   = 0x002F0060U;
    Base->SCTRL     = 0U;
    Base->SDMACTRL  = 0U;
    Base->SDATACTRL = 0x80000030U;
    Base->SMAXLIMITS = 0U;
    Base->SIDPARTNO = 0U;
    Base->SIDEXT = 0x660000U;
    Base->SVENDORID = 0x11BU;
    Base->STCCLOCK = 0x300AU;
    Base->SCCCMASK  = 0x7FU;
    Base->SERRWARNMASK = 0xF1FU;
    Base->SMAPCTRL1 = 0U;
#if (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT)
    /* I3C_IP_MAX_MAP_ADDRESSES also counts SMAPCTRL1 */
    while (cnt < (I3C_IP_MAX_MAP_ADDRESSES - 1U))
    {
        Base->SMAPCTRL[cnt] = 0U;
        cnt++;
    }
#endif /* (STD_ON == I3C_IP_SMAPCTRL_ARRAY_SUPPORT) */
    Base->IBIEXT1 = 0x70U;
    Base->IBIEXT2 = 0U;
#if (STD_ON == I3C_IP_SLAVE_RESET_SUPPORT)
    Base->SRSTACTTIME = 0U;
#endif /* (STD_ON == I3C_IP_SLAVE_RESET_SUPPORT) */

    /* If errata ERR051162 is applicable, SINTCLR[SLVRST] = 1 to disable this event. */
#if (STD_ON == I3C_IP_ERR051162_APPLICABLE)
    I3c_Ip_SlaveDisableInterrupts(Base, (uint32)I3C_SINTCLR_SLVRST_MASK);
#endif /* (STD_ON == I3C_IP_ERR051162_APPLICABLE) */
}

/**
* @brief      This function returns the value of MRDATAB register clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of MRDATAB register clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  Base      Table of base addresses for I3C instances
*
*/
static inline uint8 I3c_Ip_ReadMRDATABRegister(const I3C_Type * const Base)
{
    return (uint8)((Base->MRDATAB & I3C_MRDATAB_VALUE_MASK) >> I3C_MRDATAB_VALUE_SHIFT);
}

/**
* @brief      This function returns the value of SRDATAB register clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of SRDATAB register clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  Base      Table of base addresses for I3C instances
*
*/
static inline uint8 I3c_Ip_ReadSRDATABRegister(const I3C_Type * const Base)
{
    return (uint8)((Base->SRDATAB & I3C_SRDATAB_DATA0_MASK) >> I3C_SRDATAB_DATA0_SHIFT);
}

/**
* @brief      This function returns the value of SRDATAH LSB value clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of SRDATAH LSB value clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  RegValue     SRDATAH register value
*
*/
static inline uint8 I3c_Ip_GetSRDATAH_LSBValue(uint32 RegValue)
{
    return (uint8)((RegValue & I3C_SRDATAH_LSB_MASK) >> I3C_SRDATAH_LSB_SHIFT);
}

/**
* @brief      This function returns the value of SRDATAH MSB value clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of SRDATAH MSB value clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  RegValue      SRDATAH register value
*
*/
static inline uint8 I3c_Ip_GetSRDATAH_MSBValue(uint32 RegValue)
{
    return (uint8)((RegValue & I3C_SRDATAH_MSB_MASK) >> I3C_SRDATAH_MSB_SHIFT);
}

/**
* @brief      This function returns the value of MRDATAH LSB value clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of MRDATAH LSB value clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  RegValue     MRDATAH register value
*
*/
static inline uint8 I3c_Ip_GetMRDATAH_LSBValue(uint32 RegValue)
{
    return (uint8)((RegValue & I3C_MRDATAH_LSB_MASK) >> I3C_MRDATAH_LSB_SHIFT);
}

/**
* @brief      This function returns the value of MRDATAH MSB value clearing all bit values that do not belong in the actual data bitfield.
* @details    This function returns the value of MRDATAH MSB value clearing all bit values that do not belong in the actual data bitfield.
*
* @param[in]  RegValue     MRDATAH register value
*
*/
static inline uint8 I3c_Ip_GetMRDATAH_MSBValue(uint32 RegValue)
{
    return (uint8)((RegValue & I3C_MRDATAH_MSB_MASK) >> I3C_MRDATAH_MSB_SHIFT);
}

#if (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS)
/**
* @brief      This function sets the In-Band interrupts rules register for the master init.
* @details    This function sets the In-Band interrupts rules register for the master init.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Config    Pointer to the configuration structure
*
*/
static inline void I3c_Ip_MasterConfigIbiRules(I3C_Type * const Base,
                                              const I3c_Ip_MasterConfigType * const Config)
{
    uint32 RegValue;
    uint8 IbiAddressList[5U] = {0x00, 0x00, 0x00, 0x00, 0x00};
    uint8 cnt = 0U;

    RegValue = ~(I3C_MIBIRULES_ADDR0_MASK  |
                 I3C_MIBIRULES_ADDR1_MASK  |
                 I3C_MIBIRULES_ADDR2_MASK  |
                 I3C_MIBIRULES_ADDR3_MASK  |
                 I3C_MIBIRULES_ADDR4_MASK  |
                 I3C_MIBIRULES_MSB0_MASK   |
                 I3C_MIBIRULES_NOBYTE_MASK);

    if (Config->SlavesIbiByteCount > 0U)
    {
        while (cnt < Config->SlavesIbiByteCount)
        {
            IbiAddressList[cnt] = Config->IbiAddressRegistry[cnt];
            cnt++;
        }
    }

    RegValue |= I3C_MIBIRULES_MSB0(Config->EnableStartOptimization ? 1U : 0U) |
                I3C_MIBIRULES_NOBYTE(Config->NoMandatoryByte ? 1U : 0U) |
                I3C_MIBIRULES_ADDR0(IbiAddressList[0U])              |
                I3C_MIBIRULES_ADDR1(IbiAddressList[1U])              |
                I3C_MIBIRULES_ADDR2(IbiAddressList[2U])              |
                I3C_MIBIRULES_ADDR3(IbiAddressList[3U])              |
                I3C_MIBIRULES_ADDR4(IbiAddressList[4U]);

    Base->MIBIRULES = RegValue;
}
#endif /* (STD_ON == I3C_IP_ENABLE_SLAVE_REQUESTS) */

#define I3C_STOP_SEC_CODE
#include "I3c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I3C_IP_HWACCESS_H */
