/*
 * Copyright 2021-2024 NXP
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
#define I3C_IP_SW_MAJOR_VERSION_HWACCESS             1
#define I3C_IP_SW_MINOR_VERSION_HWACCESS             0
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
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief      Clear the I3C master error status.
*
* @param[in]  Base              Table of base addresses for I3C instances
* @param[in]  MasterErrorMask   Mask of the error/warning to be cleared
*
*/
static inline void I3c_Ip_MasterClearErrorStatusFlags(I3C_Type * const Base,
                                                      const uint32 MasterErrorMask)
{
    Base->MERRWARN = MasterErrorMask;
}

/**
* @brief      Clear the I3C slave error status.
*
* @param[in]  Base             Table of base addresses for I3C instances
* @param[in]  SlaveErrorMask   Mask of the error/warning to be cleared
*
*/
static inline void I3c_Ip_SlaveClearErrorStatusFlags(I3C_Type * const Base,
                                                     const uint32 SlaveErrorMask)
{
    Base->SERRWARN = SlaveErrorMask;
}

/**
* @brief      Clear I3C master status flag.
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
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_MasterEnableInterrupts(I3C_Type * const Base,
                                                 const uint32 Interrupts)
{
    Base->MINTSET |= Interrupts;
}

/**
* @brief      Disables the master interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_MasterDisableInterrupts(I3C_Type * const Base,
                                                  const uint32 Interrupts)
{
    Base->MINTCLR = Interrupts;
}

/**
* @brief      Enables the slave interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_SlaveEnableInterrupts(I3C_Type * const Base,
                                                const uint32 Interrupts)
{
    Base->SINTSET |= Interrupts;
}

/**
* @brief      Disables the slave interrupts given as input parameter.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  Interrupts    Mask of the interrupts to be enabled/disabled
*
*/
static inline void I3c_Ip_SlaveDisableInterrupts(I3C_Type * const Base,
                                                 const uint32 Interrupts)
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
    uint32 RetVal = Base->MCONFIG;

    RetVal &= (~I3C_MCONFIG_MSTENA_MASK);
    RetVal |= I3C_MCONFIG_MSTENA(MasterEnable);
    Base->MCONFIG = RetVal;
}

/**
* @brief      Sets the watermarks for I3C master Tx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  TxLevel   Trigger level for TX emptiness when using a FIFO
*
*/
static inline void I3c_Ip_MasterSetTxFifoWatermark(I3C_Type * const Base,
                                                   I3c_Ip_FifoTriggerLevelType TxLevel)
{
    uint32 RetVal = Base->MDATACTRL;

    RetVal &= (~I3C_MDATACTRL_TXTRIG_MASK);
    RetVal |= I3C_MDATACTRL_TXTRIG(TxLevel) | I3C_MDATACTRL_UNLOCK_MASK;
    Base->MDATACTRL = RetVal;
}

/**
* @brief      Sets the watermarks for I3C master Rx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  RxLevel   Trigger level for RX fullness when using a FIFO
*
*/
static inline void I3c_Ip_MasterSetRxFifoWatermark(I3C_Type * const Base,
                                                   I3c_Ip_FifoTriggerLevelType RxLevel)
{
    uint32 RetVal = Base->MDATACTRL;

    RetVal &= ~I3C_MDATACTRL_RXTRIG_MASK;
    RetVal |= I3C_MDATACTRL_RXTRIG(RxLevel) | I3C_MDATACTRL_UNLOCK_MASK;
    Base->MDATACTRL = RetVal;
}

/**
* @brief      Sets the watermarks for I3C slave Tx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  TxLevel   Trigger level for TX emptiness when using a FIFO
*
*/
static inline void I3c_Ip_SlaveSetTxFifoWatermark(I3C_Type * const Base,
                                                  I3c_Ip_FifoTriggerLevelType TxLevel)
{
    uint32 RetVal = Base->SDATACTRL;

    RetVal &= ~I3C_SDATACTRL_TXTRIG_MASK;
    RetVal |= I3C_SDATACTRL_TXTRIG(TxLevel) | I3C_SDATACTRL_UNLOCK_MASK;
    Base->SDATACTRL = RetVal;
}

/**
* @brief      Sets the watermarks for I3C slave Rx FIFO.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  RxLevel   Trigger level for RX fullness when using a FIFO
*
*/
static inline void I3c_Ip_SlaveSetRxFifoWatermark(I3C_Type * const Base,
                                                  I3c_Ip_FifoTriggerLevelType RxLevel)
{
    uint32 RetVal = Base->SDATACTRL;

    RetVal &= ~I3C_SDATACTRL_RXTRIG_MASK;
    RetVal |= I3C_SDATACTRL_RXTRIG(RxLevel) | I3C_SDATACTRL_UNLOCK_MASK;
    Base->SDATACTRL = RetVal;
}

/**
* @brief      This function empties the Tx FIFO of the I3C master.
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
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  MasterRequest Type of the request
*
*/
static inline void I3c_Ip_MasterEmitRequest(I3C_Type * const Base,
                                            I3c_Ip_MasterRequestType MasterRequest)
{
    uint32 RegValue = Base->MCTRL;

    RegValue &= (~I3C_MCTRL_REQUEST_MASK);
    RegValue |= I3C_MCTRL_REQUEST(MasterRequest);
    Base->MCTRL = RegValue;
}

/**
* @brief      This function sets the configuration register for the master init.
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
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Enable    If TRUE, the slave is enabled. Otherwise, the slave is disabled.
*
*/
static inline void I3c_Ip_SlaveEnable(I3C_Type * const Base,
                                      boolean Enable)
{
    uint32 RegValue = Base->SCONFIG;

    RegValue &= (~I3C_SCONFIG_SLVENA_MASK);
    RegValue |= I3C_SCONFIG_SLVENA(Enable ? 1U : 0U);
    Base->SCONFIG = RegValue;
}

/**
* @brief      This function sets the configuration parameters for the slave.
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
                  I3C_SCONFIG_MATCHSS_MASK);
    RegValue |= I3C_SCONFIG_NACK(Config->Nack ? 1U : 0U)                |
                I3C_SCONFIG_MATCHSS(Config->MatchStartStop ? 1U : 0U);

    Base->SCONFIG = RegValue;
}

/**
* @brief      This function sets the I3C slave's 7-bit static address.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  SlaveAddress  I3C Slave 7-bit SA
*
*/
static inline void I3c_Ip_SlaveSetStaticAddr(I3C_Type * const Base,
                                             const uint8 SlaveAddress)
{
    uint32 RegValue = Base->SCONFIG;

    RegValue &= ~(I3C_SCONFIG_SADDR_MASK);
    RegValue |= I3C_SCONFIG_SADDR(SlaveAddress);
    Base->SCONFIG = RegValue;
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
    boolean RetVal;

    if ((Base->MSTATUS & I3C_MSTATUS_ERRWARN_MASK) != 0U)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if a slave error/warning occurred.
*
* @param[in]  Base  Table of base addresses for I3C instances
*
*/
static inline boolean I3c_Ip_SlaveCheckErrorEvent(const I3C_Type * const Base)
{
    boolean RetVal;

    if ((Base->SSTATUS & I3C_SSTATUS_ERRWARN_MASK) != 0U)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if the interrupt given as parameter was spurious.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  InterruptMask Interrupt mask
*
*/
static inline boolean I3c_Ip_MasterCheckSpuriousInt(const I3C_Type * const Base,
                                                    uint32 InterruptMask)
{
    boolean RetVal;

    if (0U == (Base->MINTMASKED & InterruptMask))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if the interrupt given as parameter was spurious.
*
* @param[in]  Base          Table of base addresses for I3C instances
* @param[in]  InterruptMask Interrupt mask
*
*/
static inline boolean I3c_Ip_SlaveCheckSpuriousInt(const I3C_Type * const Base,
                                                   uint32 InterruptMask)
{
    boolean RetVal;

    if (0U == (Base->SINTMASKED & InterruptMask))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if the status flag given as parameter is set.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Status    Status flag
*
*/
static inline boolean I3c_Ip_MasterCheckStatus(const I3C_Type * const Base,
                                               const uint32 Status)
{
    boolean RetVal;

    if ((Base->MSTATUS & Status) != 0U)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if the status flag given as parameter is set.
*
* @param[in]  Base      Table of base addresses for I3C instances
* @param[in]  Status    Status flag
*
*/
static inline boolean I3c_Ip_SlaveCheckStatus(const I3C_Type * const Base,
                                              const uint32 Status)
{
     boolean RetVal;

    if ((Base->SSTATUS & Status) != 0U)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief      This function returns true if the state given as parameter is the current master state.
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
* @brief      Clear the I3C all master status and error flags.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterClearAllStatusFlags(I3C_Type * const Base)
{
    /* Clear all master status flag in MSTATUS register*/
    I3c_Ip_MasterClearStatus(Base, (I3C_MSTATUS_MCTRLDONE_MASK |
                                    I3C_MSTATUS_COMPLETE_MASK));

    /* Clear all master error flag in MERRWARN register*/
    I3c_Ip_MasterClearErrorStatusFlags(Base, (I3C_IP_MASTER_ERROR_NACK            |
                                              I3C_IP_MASTER_ERROR_WRITE_ABORT     |
                                              I3C_IP_MASTER_ERROR_OREAD           |
                                              I3C_IP_MASTER_ERROR_OWRITE          |
                                              I3C_IP_MASTER_ERROR_MSG             |
                                              I3C_IP_MASTER_ERROR_INVALID_REQUEST |
                                              I3C_IP_MASTER_ERROR_TIMEOUT));
}

/**
* @brief      Reset all registers to default values.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_MasterReset(I3C_Type * const Base)
{
    /* Clear all status and error flag*/
    I3c_Ip_MasterClearAllStatusFlags(Base);

    /* Disable all interrupt*/
    I3c_Ip_MasterDisableInterrupts(Base, (I3C_MINTCLR_MCTRLDONE_MASK |
                                          I3C_MINTCLR_COMPLETE_MASK  |
                                          I3C_MINTCLR_RXPEND_MASK    |
                                          I3C_MINTCLR_TXNOTFULL_MASK |
                                          I3C_MINTCLR_ERRWARN_MASK));

    /* Flush master Tx and Rx FIFOs */
    I3c_Ip_MasterResetTxFIFO(Base);
    I3c_Ip_MasterResetRxFIFO(Base);
    /* Set all configured register to default value */
    Base->MCONFIG   = I3C_IP_MCONFIG_RESET_VALUE;
    Base->MCTRL     = I3C_IP_MCTRL_RESET_VALUE;
    Base->MDMACTRL  = I3C_IP_MDMACTRL_RESET_VALUE;
    Base->MDATACTRL = I3C_IP_MDATACTRL_RESET_VALUE;
}

/**
* @brief      Clear the I3C all slave status and error flags.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveClearAllStatusFlags(I3C_Type * const Base)
{
    /* Clear all slave status flag in SSTATUS register*/
    I3c_Ip_SlaveClearStatus(Base, (I3C_SSTATUS_START_MASK      |
                                   I3C_SSTATUS_MATCHED_MASK    |
                                   I3C_SSTATUS_STOP_MASK));
    /* Clear all slave error flag in SERRWARN register*/
    I3c_Ip_SlaveClearErrorStatusFlags(Base, (I3C_IP_SLAVE_ERROR_RX_OVERRUN       |
                                             I3C_IP_SLAVE_ERROR_TX_UNDERRUN      |
                                             I3C_IP_SLAVE_ERROR_TX_UNDERRUN_NACK |
                                             I3C_IP_SLAVE_ERROR_TERM             |
                                             I3C_IP_SLAVE_ERROR_INVALID_START    |
                                             I3C_IP_SLAVE_ERROR_SDR_PARITY       |
                                             I3C_IP_SLAVE_ERROR_OREAD            |
                                             I3C_IP_SLAVE_ERROR_OWRITE));
}

/**
* @brief      Reset all registers to default values.
*
* @param[in] Base       Table of base addresses for I3C instances
*
*/
static inline void I3c_Ip_SlaveReset(I3C_Type * const Base)
{
    /* Clear all status and error flag*/
    I3c_Ip_SlaveClearAllStatusFlags(Base);
    /* Disable all interrupt*/
    I3c_Ip_SlaveDisableInterrupts(Base, (I3C_SINTCLR_START_MASK       |
                                         I3C_SINTCLR_MATCHED_MASK     |
                                         I3C_SINTCLR_STOP_MASK        |
                                         I3C_SINTCLR_RXPEND_MASK      |
                                         I3C_SINTCLR_TXSEND_MASK      |
                                         I3C_SINTCLR_ERRWARN_MASK));

    /* Flush slave Tx and Rx FIFOs */
    I3c_Ip_SlaveResetTxFIFO(Base);
    I3c_Ip_SlaveResetRxFIFO(Base);

    /* Set all configured register to default value */
    Base->SCONFIG   = I3C_IP_SCONFIG_RESET_VALUE;
    Base->SDMACTRL  = I3C_IP_SDMACTRL_RESET_VALUE;
    Base->SDATACTRL = I3C_IP_SDATACTRL_RESET_VALUE;
}

/**
* @brief      This function returns the value of MRDATAB register clearing all bit values that do not belong in the actual data bitfield.
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
*
* @param[in]  RegValue     MRDATAH register value
*
*/
static inline uint8 I3c_Ip_GetMRDATAH_MSBValue(uint32 RegValue)
{
    return (uint8)((RegValue & I3C_MRDATAH_MSB_MASK) >> I3C_MRDATAH_MSB_SHIFT);
}

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* I3C_IP_HWACCESS_H */
