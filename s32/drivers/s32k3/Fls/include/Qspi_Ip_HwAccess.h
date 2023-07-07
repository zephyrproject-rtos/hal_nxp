/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QUADSPI_HW_ACCESS_H
#define QUADSPI_HW_ACCESS_H

/**
*   @file Qspi_Ip_HwAccess.h
*
*   @addtogroup IPV_QSPI QSPI IPV Driver
*   @{
*/

/* implements Qspi_Ip_HwAccess.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HW_ACCESS_VENDOR_ID_H                       43
#define QSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H                3
#define QSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H                0
#define QSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define QSPI_IP_RX_READOUT_IP   1U        /* RX Buffer content is read using the AHB Bus registers QSPI_ARDBn */

/*******************************************************************************
 * API
 ******************************************************************************/


/*
 * Triggers an IP transaction
 */
static inline void Qspi_Ip_IpTrigger(QuadSPI_Type *BaseAddr,
                                     uint8 SeqID,
                                     uint16 DataSize
                                    )
{
    BaseAddr->IPCR =  QuadSPI_IPCR_SEQID(SeqID)
                    | QuadSPI_IPCR_IDATSZ(DataSize);
}


/*
 * Clear Rx buffer
 */
static inline void Qspi_Ip_ClearRxBuf(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= QuadSPI_MCR_CLR_RXF_MASK;

}


/*
 * Clear Tx buffer
 */
static inline void Qspi_Ip_ClearTxBuf(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= QuadSPI_MCR_CLR_TXF_MASK;

}


/*
 * Checks the Tx buffer clear flag
 * Returns TRUE if the Tx buffer content is invalidated.
 */
static inline boolean Qspi_Ip_GetClrTxStatus(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue = (RegValue & QuadSPI_MCR_CLR_TXF_MASK) >> QuadSPI_MCR_CLR_TXF_SHIFT;
    return (0U == RegValue)? TRUE : FALSE;
}


#ifdef QuadSPI_SPTRCLR_ABRT_CLR_MASK
/*
 * Clear AHB buffer
 */
static inline void Qspi_Ip_ClearAhbBuf(QuadSPI_Type *BaseAddr)
{
    BaseAddr->SPTRCLR |= QuadSPI_SPTRCLR_ABRT_CLR_MASK;
}

/*
 * Checks the Ahb buffer clear flag
 * Returns TRUE if the Ahb buffer content is invalidated.
 */
static inline boolean Qspi_Ip_GetClrAhbStatus(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SPTRCLR;

    RegValue = (RegValue & QuadSPI_SPTRCLR_ABRT_CLR_MASK) >> QuadSPI_SPTRCLR_ABRT_CLR_SHIFT;
    return (0U == RegValue)? TRUE : FALSE;
}
#endif


/*!
 * @brief Clears IP sequence pointer
 *
 */
static inline void Qspi_Ip_ClearIpSeqPointer(QuadSPI_Type *BaseAddr)
{
    BaseAddr->SPTRCLR = QuadSPI_SPTRCLR_IPPTRC_MASK;
}


/*!
 * @brief Clears AHB sequence pointer
 *
 */
static inline void Qspi_Ip_ClearAHBSeqPointer(QuadSPI_Type *BaseAddr)
{
    BaseAddr->SPTRCLR = QuadSPI_SPTRCLR_BFPTRC_MASK;
}


/*
 * Enable QuadSPI device
 */
static inline void Qspi_Ip_Enable(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR &= ~QuadSPI_MCR_MDIS_MASK;

}


/*
 * Disable QuadSPI device
 */
static inline void Qspi_Ip_Disable(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= QuadSPI_MCR_MDIS_MASK;

}

#ifdef QuadSPI_MCR_DDR_EN_MASK
/*
 * Enable DDR mode
 */
static inline void QSPI_DDR_Enable(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= QuadSPI_MCR_DDR_EN_MASK;
}

/*
 * Disable DDR mode
 */
static inline void QSPI_DDR_Disable(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR &= ~QuadSPI_MCR_DDR_EN_MASK;
}
#endif




/*
 * Enable DQS
 */
#ifdef QuadSPI_MCR_DQS_EN_MASK
static inline void QSPI_DQS_Enable(QuadSPI_Type *BaseAddr)
{
    /* Enable DQS */
    BaseAddr->MCR |= QuadSPI_MCR_DQS_EN_MASK;
}
#else
static inline void QSPI_DQS_Enable(const QuadSPI_Type *BaseAddr)
{
    /* Unused variable */
    (void)BaseAddr;
}
#endif

/*
 * Disable DQS
 */
#ifdef QuadSPI_MCR_DQS_EN_MASK
static inline void QSPI_DQS_Disable(QuadSPI_Type *BaseAddr)
{
    /* Disable DQS */
    BaseAddr->MCR &= ~QuadSPI_MCR_DQS_EN_MASK;
}
#else
static inline void QSPI_DQS_Disable(const QuadSPI_Type *BaseAddr)
{
    /* Unused variable */
    (void)BaseAddr;
}
#endif


/*
 * Assert QuadSPI sw reset bits
 */
static inline void Qspi_Ip_SwResetOn(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= QuadSPI_MCR_SWRSTHD_MASK | QuadSPI_MCR_SWRSTSD_MASK;

}


/*
 * Deassert QuadSPI sw reset bits
 */
static inline void Qspi_Ip_SwResetOff(QuadSPI_Type *BaseAddr)
{
    BaseAddr->MCR &= ~(QuadSPI_MCR_SWRSTHD_MASK | QuadSPI_MCR_SWRSTSD_MASK);

}


/*
 * Configure idle values for data lines 2:3
 */

#ifdef QuadSPI_MCR_ISD2FA_MASK
static inline void Qspi_Ip_SetIdleLineValuesA(QuadSPI_Type *BaseAddr,
                                             uint8 Iofa2IdleValue,
                                             uint8 Iofa3IdleValue
                                            )
{
    /* get value MCR register */
    uint32 RegValue = (uint32)BaseAddr->MCR;

    /* set mask for ISD2FA, ISD3FA */
    RegValue &= (uint32)(~(QuadSPI_MCR_ISD2FA_MASK  | QuadSPI_MCR_ISD3FA_MASK));
    RegValue |= (QuadSPI_MCR_ISD2FA(Iofa2IdleValue) | QuadSPI_MCR_ISD3FA(Iofa3IdleValue));

    /* set again the MCR register */
    BaseAddr->MCR = (uint32)RegValue;
}
#else
static inline void Qspi_Ip_SetIdleLineValuesA(const QuadSPI_Type *BaseAddr,
                                              uint8 Iofa2IdleValue,
                                              uint8 Iofa3IdleValue
                                             )
{
    /* Unused variable */
    (void)BaseAddr;
    (void)Iofa2IdleValue;
    (void)Iofa3IdleValue;
}
#endif



/*
 * Enable/Disable DQS slave delay chain
 */
static inline void Qspi_Ip_DLLSlaveEnA(QuadSPI_Type *BaseAddr,
                                       boolean Enable
                                      )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_EN_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_EN(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}

/*
 * Activates/Deactivates DQS slave delay chain update
 */
static inline void Qspi_Ip_DLLSlaveUpdateA(QuadSPI_Type *BaseAddr,
                                           boolean Enable
                                          )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_UPD_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_UPD(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}

#ifdef QuadSPI_DLLCRA_DLLEN_MASK
/*
 * Activates/Deactivates DQS slave delay chain update
 */
static inline void Qspi_Ip_DLLEnableA(QuadSPI_Type *BaseAddr,
                                      boolean Enable
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_DLLEN_MASK));
    RegValue |= QuadSPI_DLLCRA_DLLEN(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}
#endif

/*
 * Activates/Deactivates slave DLL bypass
 */
static inline void Qspi_Ip_DLLSlaveBypassA(QuadSPI_Type *BaseAddr,
                                           boolean Enable
                                          )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_DLL_BYPASS_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_DLL_BYPASS(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}


#ifdef QuadSPI_DLLCRA_SLAVE_AUTO_UPDT_MASK
/*
 * Activates/Deactivates slave auto update
 */
static inline void Qspi_Ip_DLLSlaveAutoUpdateA(QuadSPI_Type *BaseAddr,
                                               boolean Enable
                                              )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLAVE_AUTO_UPDT_MASK));
    RegValue |= QuadSPI_DLLCRA_SLAVE_AUTO_UPDT(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}
#endif /* QuadSPI_DLLCRA_SLAVE_AUTO_UPDT_MASK */

/*
 * Activates/Deactivates delay-chain for high frequency of operation
 */
static inline void Qspi_Ip_DLLFreqEnA(QuadSPI_Type *BaseAddr,
                                      boolean Enable
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_FREQEN_MASK));
    RegValue |= QuadSPI_DLLCRA_FREQEN(Enable? 1U : 0U);
    BaseAddr->DLLCRA = (uint32)RegValue;
}

/*
 * Sets slave delay chain coarse delay for DLL bypass mode
 */
static inline void Qspi_Ip_DLLSetCoarseDelayA(QuadSPI_Type *BaseAddr,
                                              uint8 CoarseDelay
                                             )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_DLY_COARSE_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_DLY_COARSE(CoarseDelay);
    BaseAddr->DLLCRA = (uint32)RegValue;
}


/*
 * Sets reference counter
 */
static inline void Qspi_Ip_DLLSetReferenceCounterA(QuadSPI_Type *BaseAddr,
                                                   uint8 ReferenceCounter
                                                  )
{
#ifdef QuadSPI_DLLCRA_DLL_REFCNTR_MASK
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_DLL_REFCNTR_MASK));
    RegValue |= QuadSPI_DLLCRA_DLL_REFCNTR(ReferenceCounter);
    BaseAddr->DLLCRA = (uint32)RegValue;
#else
    (void)BaseAddr;
    (void)ReferenceCounter;
#endif  /* QuadSPI_DLLCRA_DLL_REFCNTR_MASK */
}

#ifdef QuadSPI_DLLCRA_DLLRES_MASK
/*
 * Sets Resolution
 */
static inline void Qspi_Ip_DLLSetResolutionA(QuadSPI_Type *BaseAddr,
                                             uint8 Resolution
                                            )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_DLLRES_MASK));
    RegValue |= QuadSPI_DLLCRA_DLLRES(Resolution);
    BaseAddr->DLLCRA = (uint32)RegValue;
}
#endif /* QuadSPI_DLLCRA_DLLRES_MASK */

/*
 * Sets slave delay chain coarse offset
 */
static inline void Qspi_Ip_DLLSetCoarseOffsetA(QuadSPI_Type *BaseAddr,
                                               uint8 CoarseDelay
                                              )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_DLY_OFFSET_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_DLY_OFFSET(CoarseDelay);
    BaseAddr->DLLCRA = (uint32)RegValue;
}

/*
 * Sets slave delay chain fine offset
 */
static inline void Qspi_Ip_DLLSetFineOffsetA(QuadSPI_Type *BaseAddr,
                                             uint8 FineDelay
                                            )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCRA;

    RegValue &= (uint32)(~((uint32)QuadSPI_DLLCRA_SLV_FINE_OFFSET_MASK));
    RegValue |= QuadSPI_DLLCRA_SLV_FINE_OFFSET(FineDelay);
    BaseAddr->DLLCRA = (uint32)RegValue;
}


/*
 * Checks high frequency slave delay chain lock status
 */
static inline boolean Qspi_Ip_DLLGetSlaveLockStatusA(const QuadSPI_Type *BaseAddr)
{
#ifdef QuadSPI_DLLSR_SLVA_LOCK_MASK
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    RegValue = (RegValue & QuadSPI_DLLSR_SLVA_LOCK_MASK) >> QuadSPI_DLLSR_SLVA_LOCK_SHIFT;
    return (RegValue != 0U)? TRUE : FALSE;
#else
    (void)BaseAddr;
    return FALSE;
#endif
}


/*
 * Checks DLL lock status
 */
static inline boolean Qspi_Ip_DLLGetLockStatusA(const QuadSPI_Type *BaseAddr)
{
#ifdef QuadSPI_DLLSR_DLLA_LOCK_MASK
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    RegValue = (RegValue & QuadSPI_DLLSR_DLLA_LOCK_MASK) >> QuadSPI_DLLSR_DLLA_LOCK_SHIFT;
    return (RegValue != 0U)? TRUE : FALSE;
#else
    (void)BaseAddr;
    return FALSE;
#endif
}

/*
 * Checks high frequency slave delay chain error status
 */
static inline boolean Qspi_Ip_DLLGetErrorStatusA(const QuadSPI_Type *BaseAddr)
{
#ifdef QuadSPI_DLLSR_DLLA_RANGE_ERR_MASK
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    RegValue = RegValue & (QuadSPI_DLLSR_DLLA_RANGE_ERR_MASK | QuadSPI_DLLSR_DLLA_FINE_UNDERFLOW_MASK);
    return (RegValue != 0U)? TRUE : FALSE;
#else
    (void)BaseAddr;
    return FALSE;
#endif
}



/*
 * Configure external flash memory map size A
 */
static inline void Qspi_Ip_SetMemMapSizeA(uint32 instance,
                                          QuadSPI_Type *BaseAddr,
                                          uint32 SizeA1,
                                          uint32 SizeA2
                                         )
{
    BaseAddr->SFA1AD = Qspi_Ip_AhbAddress[instance] + SizeA1;
    BaseAddr->SFA2AD = Qspi_Ip_AhbAddress[instance] + SizeA1 + SizeA2;
}


/*
 * Set CS hold time in serial clock Cycles
 */
static inline void Qspi_Ip_SetCsHoldTime(QuadSPI_Type *BaseAddr,
                                         uint8 Cycles
                                        )
{
    uint32 RegValue = (uint32)BaseAddr->FLSHCR;

    RegValue &= (uint32)(~((uint32)QuadSPI_FLSHCR_TCSH_MASK));
    RegValue |= QuadSPI_FLSHCR_TCSH(Cycles);
    BaseAddr->FLSHCR = (uint32)RegValue;
}


/*
 * Set CS setup time
 */
static inline void Qspi_Ip_SetCsSetupTime(QuadSPI_Type *BaseAddr,
                                          uint8 Cycles
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->FLSHCR;

    RegValue &= (uint32)(~((uint32)QuadSPI_FLSHCR_TCSS_MASK));
    RegValue |= QuadSPI_FLSHCR_TCSS(Cycles);
    BaseAddr->FLSHCR = (uint32)RegValue;
}


#ifdef QuadSPI_FLSHCR_TDH_MASK
/*
 * Set data in hold time
 */
static inline void Qspi_Ip_SetDataInHoldTime(QuadSPI_Type *BaseAddr,
                                             Qspi_Ip_FlashDataAlignType Enable
                                            )
{
    uint32 RegValue = (uint32)BaseAddr->FLSHCR;

    RegValue &= (uint32)(~(QuadSPI_FLSHCR_TDH_MASK));
    RegValue |= QuadSPI_FLSHCR_TDH(Enable);
    BaseAddr->FLSHCR = (uint32)RegValue;
}
#endif /* QuadSPI_FLSHCR_TDH_MASK */


/*
 * Sets AHB buffer 0 configuration
 */
static inline void Qspi_Ip_SetAhbBuf0(QuadSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    BaseAddr->BUF0CR =  QuadSPI_BUF0CR_ADATSZ((uint32)Size >> 3U)
                      | QuadSPI_BUF0CR_MSTRID(Master);
}


/*
 * Sets AHB buffer 1 configuration
 */
static inline void Qspi_Ip_SetAhbBuf1(QuadSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    BaseAddr->BUF1CR =  QuadSPI_BUF1CR_ADATSZ((uint32)Size >> 3U)
                      | QuadSPI_BUF1CR_MSTRID(Master);
}


/*
 * Sets AHB buffer 2 configuration
 */
static inline void Qspi_Ip_SetAhbBuf2(QuadSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    BaseAddr->BUF2CR =  QuadSPI_BUF2CR_ADATSZ((uint32)Size >> 3U)
                      | QuadSPI_BUF2CR_MSTRID(Master);
}


/*
 * Sets AHB buffer 3 configuration
 */
static inline void Qspi_Ip_SetAhbBuf3(QuadSPI_Type *BaseAddr,
                                       uint16 Size,
                                       uint8 Master,
                                       boolean AllMasters
                                     )
{
    BaseAddr->BUF3CR =  QuadSPI_BUF3CR_ADATSZ((uint32)Size >> 3U)
                      | QuadSPI_BUF3CR_MSTRID(Master)
                      | QuadSPI_BUF3CR_ALLMST(AllMasters? 1U : 0U);
}


/*
 * Sets AHB buffer 0 index. Parameter represents desired end index of the buffer.
 */
static inline void Qspi_Ip_SetAhbBuf0Ind(QuadSPI_Type *BaseAddr,
                                         uint32 Index
                                        )
{
    BaseAddr->BUF0IND =  Index;
}


/*
 * Sets AHB buffer 1 index. Parameter represents desired end index of the buffer.
 */
static inline void Qspi_Ip_SetAhbBuf1Ind(QuadSPI_Type *BaseAddr,
                                         uint32 Index
                                        )
{
    BaseAddr->BUF1IND =  Index;
}


/*
 * Sets AHB buffer 2 index. Parameter represents desired end index of the buffer.
 */
static inline void Qspi_Ip_SetAhbBuf2Ind(QuadSPI_Type *BaseAddr,
                                         uint32 Index
                                        )
{
    BaseAddr->BUF2IND =  Index;
}


/*
 * Sets address for IP transactions
 */
static inline void Qspi_Ip_SetIpAddr(QuadSPI_Type *BaseAddr,
                                     uint32 Addr
                                    )
{
    BaseAddr->SFAR = Addr;
}


/*
 * Sets flash address options
 */
#ifdef QuadSPI_SFACR_CAS_MASK
static inline void Qspi_Ip_SetAddrOptions(QuadSPI_Type *BaseAddr,
                                          uint8 ColumnAddr,
                                          boolean WordAdressable
                                         )
{
    /* Set Column address and Word addressable */
    BaseAddr->SFACR = QuadSPI_SFACR_CAS(ColumnAddr)
                    | QuadSPI_SFACR_WA(WordAdressable ? 1U : 0U);
}
#else
static inline void Qspi_Ip_SetAddrOptions(const QuadSPI_Type *BaseAddr,
                                          uint8 ColumnAddr,
                                          boolean WordAdressable
                                         )
{
    /* Unused variable */
    (void)BaseAddr;
    (void)ColumnAddr;
    (void)WordAdressable;
}
#endif


/*
 * Configures parameters related to sampling Rx data
 */
static inline void Qspi_Ip_SetRxCfg(QuadSPI_Type *BaseAddr,
                                    Qspi_Ip_SampleDelayType Delay,
                                    Qspi_Ip_SamplePhaseType ClockPhase
                                   )
{
    BaseAddr->SMPR = QuadSPI_SMPR_FSPHS(ClockPhase)
                   | QuadSPI_SMPR_FSDLY(Delay);
}


/*
 * Configures parameters related to sampling Rx data
 */
static inline void Qspi_Ip_SetRxDLLTapA(QuadSPI_Type *BaseAddr,
                                        uint8 Taps
                                       )
{
    uint32 RegValue = BaseAddr->SMPR;

    RegValue &= ~QuadSPI_SMPR_DLLFSMPFA_MASK;
    RegValue |= QuadSPI_SMPR_DLLFSMPFA(Taps);
    BaseAddr->SMPR = RegValue;
}





/*
 * Checks if module is busy with a transaction
 */
static inline boolean Qspi_Ip_GetBusyStatus(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SR;

    RegValue = (RegValue & QuadSPI_SR_BUSY_MASK) >> QuadSPI_SR_BUSY_SHIFT;
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Returns the current fill level of the Rx buffer
 */
static inline uint32 Qspi_Ip_GetRxBufFill(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->RBSR;

    RegValue = (RegValue & QuadSPI_RBSR_RDBFL_MASK) >> QuadSPI_RBSR_RDBFL_SHIFT;
    return RegValue;
}


/*
 * Checks if enough Rx data is available, according to the Watermark setting
 */
static inline boolean Qspi_Ip_GetRxDataEvent(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SR;

    RegValue = (RegValue & QuadSPI_SR_RXWE_MASK) >> QuadSPI_SR_RXWE_SHIFT;
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Returns Tx buffer fill level expressed in 4-byte entries
 */
static inline uint32 Qspi_Ip_GetTxBufFill(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->TBSR;

    RegValue = (RegValue & QuadSPI_TBSR_TRBFL_MASK) >> QuadSPI_TBSR_TRBFL_SHIFT;
    return RegValue;
}


#ifdef QuadSPI_SR_TXWA_MASK
/*
 * Checks the Tx buffer Watermark.
 * Returns TRUE if number of buffer entries specified by the Watermark is available.
 */
static inline boolean Qspi_Ip_GetTxWatermarkAvailable(const QuadSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->SR;

    RegValue = (RegValue & QuadSPI_SR_TXWA_MASK) >> QuadSPI_SR_TXWA_SHIFT;
    return (RegValue != 0U)? TRUE : FALSE;
}
#endif


/*
 * Writes data in the Tx buffer
 */
static inline void Qspi_Ip_WriteTxData(QuadSPI_Type *BaseAddr, uint32 Data)
{
    BaseAddr->TBDR = Data;
}


/*
 * Returns the address of the Tx data register
 */
static inline uint32 Qspi_Ip_GetTxDataAddr(const QuadSPI_Type *BaseAddr)
{
    return (Qspi_Ip_UintPtrType)&(BaseAddr->TBDR);
}


/*
 * Returns the address of the first Rx data register
 */
static inline uint32 Qspi_Ip_GetRxDataAddr(const QuadSPI_Type *BaseAddr)
{
    return (Qspi_Ip_UintPtrType)&(BaseAddr->RBDR[0U]);
}


/*
 * Enables Tx DMA request (when Tx buffer has room for more data)
 */
static inline void Qspi_Ip_EnableTxDmaReq(QuadSPI_Type *BaseAddr)
{
    BaseAddr->RSER |= QuadSPI_RSER_TBFDE_MASK;
}


/*
 * Enables Rx DMA request (when Rx buffer has room for more data)
 */
static inline void Qspi_Ip_EnableRxDmaReq(QuadSPI_Type *BaseAddr)
{
    BaseAddr->RSER |= QuadSPI_RSER_RBDDE_MASK;
}


/*
 * Disables both Rx and Tx DMA requests
 */
static inline void Qspi_Ip_DisableDmaReq(QuadSPI_Type *BaseAddr)
{
    BaseAddr->RSER &= ~(QuadSPI_RSER_TBFDE_MASK | QuadSPI_RSER_RBDDE_MASK);
}


/*
 * Perform a POP operation on the Rx buffer, removing Rx_watermark entries
 */
static inline void Qspi_Ip_RxPop(QuadSPI_Type *BaseAddr)
{
    BaseAddr->FR = QuadSPI_FR_RBDF_MASK;
}


/*
 * Configures the Watermark for the Rx buffer, expressed in number of 4-byte entries
 */
static inline void Qspi_Ip_SetRxWatermark(QuadSPI_Type *BaseAddr,
                                          uint8 Watermark
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->RBCT;

    RegValue &= (uint32)(~((uint32)QuadSPI_RBCT_WMRK_MASK));
    RegValue |= QuadSPI_RBCT_WMRK((uint32)Watermark - 1U);
    BaseAddr->RBCT = (uint32)RegValue;
}


#ifdef QuadSPI_RBCT_RXBRD_MASK
/*
 * Configures the rx for the Rx buffer, expressed in number of 4-byte entries
 */
static inline void Qspi_Ip_SetRxBufReadout(QuadSPI_Type *BaseAddr,
                                           uint8 Readout
                                          )
{
    uint32 RegValue = (uint32)BaseAddr->RBCT;

    RegValue &= (uint32)(~((uint32)QuadSPI_RBCT_RXBRD_MASK));
    RegValue |= QuadSPI_RBCT_RXBRD(Readout);
    BaseAddr->RBCT = (uint32)RegValue;
}
#endif


/*
 * Configures the Watermark for the Tx buffer, expressed in number of 4-byte entries
 */
static inline void Qspi_Ip_SetTxWatermark(QuadSPI_Type *BaseAddr,
                                          uint8 Watermark
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->TBCT;

    RegValue &= (uint32)(~((uint32)QuadSPI_TBCT_WMRK_MASK));
    RegValue |= QuadSPI_TBCT_WMRK(Watermark);
    BaseAddr->TBCT = (uint32)RegValue;
}


/*
 * Enables interrupts specified by the mask parameter
 */
static inline void Qspi_Ip_EnableInt(QuadSPI_Type *BaseAddr,
                                     uint32 Mask
                                    )
{
    BaseAddr->RSER |= Mask;
}


/*
 * Disables interrupts specified by the mask parameter
 */
static inline void Qspi_Ip_DisableInt(QuadSPI_Type *BaseAddr,
                                      uint32 Mask
                                     )
{
    BaseAddr->RSER &= ~Mask;
}


/*
 * Clears interrupt flags specified by the mask parameter
 */
static inline void Qspi_Ip_ClearIntFlag(QuadSPI_Type *BaseAddr,
                                        uint32 Mask
                                       )
{
    BaseAddr->FR = Mask;
}


/*
 * Configure DQS clock for sampling read data
 */
static inline void Qspi_Ip_SetDQSSourceA(QuadSPI_Type *BaseAddr,
                                         Qspi_Ip_ReadModeType ReadModeA)
{
    /* get the value of MCR register */
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue &= (uint32)(~QuadSPI_MCR_DQS_FA_SEL_MASK);
    /* switch for modes */
    switch (ReadModeA)
    {
#if (FEATURE_QSPI_INTERNAL_DQS == 1)
        case QSPI_IP_READ_MODE_INTERNAL_DQS:
                /* if it is DQS internal */
                RegValue |= QuadSPI_MCR_DQS_FA_SEL(0U);
                break;
#endif
#if (FEATURE_QSPI_LOOPBACK == 1)
        case QSPI_IP_READ_MODE_LOOPBACK:
                /* if it is Pad loopback */
                RegValue |= QuadSPI_MCR_DQS_FA_SEL(1U);
                break;
#endif
#if (FEATURE_QSPI_LOOPBACK_DQS == 1)
        case QSPI_IP_READ_MODE_LOOPBACK_DQS:
                /* if it is DQS pad loopback */
                RegValue |= QuadSPI_MCR_DQS_FA_SEL(2U);
                break;
#endif
        case QSPI_IP_READ_MODE_EXTERNAL_DQS:
                /* if it is DQS external */
                RegValue |= QuadSPI_MCR_DQS_FA_SEL(3U);
                break;
        default:
                ; /* Not possible */
                break;
    }
    BaseAddr->MCR = (uint32)RegValue;
}








#ifdef QuadSPI_SFACR_BYTE_SWAP_MASK
static inline void Qspi_Ip_SetByteSwap(QuadSPI_Type *BaseAddr,
                                       boolean ByteSwap
                                      )
{
    /* Get the value of SFACR register */
    uint32 RegValue = (uint32)BaseAddr->SFACR;

    /* Set mask */
    RegValue &= (uint32)(~QuadSPI_SFACR_BYTE_SWAP_MASK);
    RegValue |= QuadSPI_SFACR_BYTE_SWAP(ByteSwap? 1U : 0U);
    /* Update again the SFACR register */
    BaseAddr->SFACR = (uint32)RegValue;
}
#else
static inline void Qspi_Ip_SetByteSwap(const QuadSPI_Type *BaseAddr,
                                       boolean ByteSwap
                                      )
{
    /* Unused variable */
    (void)BaseAddr;
    (void)ByteSwap;
}
#endif

#ifdef QuadSPI_MCR_SCLKCFG_MASK
/*
 * Configure chip-specific clock options
 */
static inline void Qspi_Ip_SetClockOptions(QuadSPI_Type *BaseAddr,
                                           uint8 Option
                                          )
{
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue &= (uint32)(~QuadSPI_MCR_SCLKCFG_MASK);
    RegValue |= QuadSPI_MCR_SCLKCFG(Option);
    BaseAddr->MCR = (uint32)RegValue;
}
#endif

#ifdef QuadSPI_SOCCR_SOCCFG_MASK
/*
 * Configure chip-specific options
 */
static inline void Qspi_Ip_SetChipOptions(QuadSPI_Type *BaseAddr,
                                          uint32 Option
                                         )
{
    BaseAddr->SOCCR = Option;
}
#endif




#if (FEATURE_QSPI_HAS_SFP == 1)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Enable/disable all or just MDAD/FRAD access controls.
 *
 * Master Global Configuration (MGC):
 * - Global Valid access control (GVLD)
 * - Global Valid MDAD (GVLDMDAD)
 * - Global Valid FRAD (GVLDFRAD)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] AccessControl an enum selecting all or just MDAD/FRAD access controls
 * @param[in] Enabled the value of the selected field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetAccessControls
(
    QuadSPI_Type * BaseAddr,
    Qspi_Ip_Sfp_AccessControlType AccessControl,
    sint8 Enabled)
{
    uint32 RegValue = BaseAddr->MGC;

    switch (AccessControl)
    {
        case QSPI_IP_SFP_ALL:
        {
            RegValue &= ~QuadSPI_MGC_GVLD_MASK;
            RegValue |= QuadSPI_MGC_GVLD(Enabled);
        }
        break;

        case QSPI_IP_SFP_MDAD:
        {
            RegValue &= ~QuadSPI_MGC_GVLDMDAD_MASK;
            RegValue |= QuadSPI_MGC_GVLDMDAD(Enabled);
        }
        break;

        case QSPI_IP_SFP_FRAD:
        {
            RegValue &= ~QuadSPI_MGC_GVLDFRAD_MASK;
            RegValue |= QuadSPI_MGC_GVLDFRAD(Enabled);
        }
        break;

        default:
            /* invalid selection */
        break;
    }

    BaseAddr->MGC = RegValue;
}

#if (QSPI_IP_SFP_ENABLE_GLOBAL == STD_ON)

#if (QSPI_IP_SFP_ENABLE_MDAD == STD_ON)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the VLD bit of a Target Group queue
 *
 * Target Group n Master Domain Access Descriptor (TG0MDAD - TG1MDAD):
 * - Valid (VLD)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 * @param[in] Valid value to be written into the VLD bit
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetTgValid
(
    QuadSPI_Type * BaseAddr,
    uint8 MdadInstance,
    boolean Valid)
{
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        uint32 RegValue = BaseAddr->MDAD[MdadInstance].TGMDAD;
        RegValue &= ~QuadSPI_TGMDAD_VLD_MASK;
        RegValue |= QuadSPI_TGMDAD_VLD(Valid ? 1U : 0U);
        BaseAddr->MDAD[MdadInstance].TGMDAD = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the Secure Attribute field of a Target Group queue
 *
 * Target Group n Master Domain Access Descriptor (TG0MDAD - TG1MDAD):
 * - Secure Attribute (SA)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 * @param[in] SecureAttribute value of the SA field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetTgSecureAttribute
(
    QuadSPI_Type * BaseAddr,
    uint8 MdadInstance,
    Qspi_Ip_SfpSaType SecureAttribute)
{
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        uint32 RegValue = BaseAddr->MDAD[MdadInstance].TGMDAD;
        RegValue &= ~QuadSPI_TGMDAD_SA_MASK;
        RegValue |= QuadSPI_TGMDAD_SA(SecureAttribute);
        BaseAddr->MDAD[MdadInstance].TGMDAD = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the MASKTYPE field of the given target group queue.
 *
 * Target Group n Master Domain Access Descriptor (TG0MDAD - TG1MDAD):
 * - Mask Type (MASKTYPE)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 * @param[in] MaskType value to be written in the mask type field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetTgMaskType
(
    QuadSPI_Type * BaseAddr,
    uint8 MdadInstance,
    Qspi_Ip_SfpMasktypeType MaskType)
{
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        uint32 RegValue = BaseAddr->MDAD[MdadInstance].TGMDAD;
        RegValue &= ~QuadSPI_TGMDAD_MASKTYPE_MASK;
        RegValue |= QuadSPI_TGMDAD_MASKTYPE(MaskType);
        BaseAddr->MDAD[MdadInstance].TGMDAD = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the MASK field of the given target group queue.
 *
 * Target Group n Master Domain Access Descriptor (TG0MDAD - TG1MDAD):
 * - Mask (MASK)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 * @param[in] Mask value that is written into the 6-bit mask
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetTgMask
(
    QuadSPI_Type * BaseAddr,
    uint8 MdadInstance,
    uint8 Mask)
{
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        uint32 RegValue = BaseAddr->MDAD[MdadInstance].TGMDAD;
        RegValue &= ~QuadSPI_TGMDAD_MASK_MASK;
        RegValue |= QuadSPI_TGMDAD_MASK(Mask);
        BaseAddr->MDAD[MdadInstance].TGMDAD = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the Domain ID reference of the given target group queue.
 *
 * Target Group n Master Domain Access Descriptor (TG0MDAD - TG1MDAD):
 * - Domain ID Reference (MIDMATCH)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 * @param[in] DomainIdMatch value of MIDMATCH field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetTgDomainIdMatch
(
    QuadSPI_Type * BaseAddr,
    uint8 MdadInstance,
    uint8 DomainIdMatch)
{
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        uint32 RegValue = BaseAddr->MDAD[MdadInstance].TGMDAD;
        RegValue &= ~QuadSPI_TGMDAD_MIDMATCH_MASK;
        RegValue |= QuadSPI_TGMDAD_MIDMATCH(DomainIdMatch);
        BaseAddr->MDAD[MdadInstance].TGMDAD = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Indicates whether the IPCR-IDATZ, IPCR-SEQID and PAR stored in this target group queue is
 * valid and queue is locked.
 *
 * Target Group n IPCR Status (TG0IPCRS - TG1IPCRS):
 * - Valid (VLD)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] MdadInstance index of the target group to be configured
 *
 * @retval TRUE: valid
 * @retval FALSE: invalid
 * @retval FALSE: the MdadInstance is invalid
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline boolean Qspi_Ip_Sfp_TgIpcrsValid
(
    QuadSPI_Type const * BaseAddr,
    uint8 MdadInstance)
{
    uint32 RegValue = 0U;
    if (MdadInstance < QuadSPI_MDAD_COUNT)
    {
        RegValue = (BaseAddr->MDAD[MdadInstance].TGIPCRS & QuadSPI_TGIPCRS_VLD_MASK) >> QuadSPI_TGIPCRS_VLD_SHIFT;
    }
    return (RegValue != 0U) ? TRUE : FALSE;
}

#endif /* QSPI_IP_SFP_ENABLE_MDAD */

#if (QSPI_IP_SFP_ENABLE_FRAD == STD_ON)

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Specifies the specific flash memory region starting address (around 64 KB boundary).
 *
 * Flash Region Start Address (FRAD0_WORD0 - FRAD7_WORD0)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] StartAddress 64 KB aligned start address of the flash region
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradStartAddress
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint32 StartAddress)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        BaseAddr->FRAD[FradInstance].WORD0 = StartAddress;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Specifies the specific flash memory region end address (around 64 KB boundary).
 *
 * Flash Region End Address (FRAD0_WORD1 - FRAD7_WORD1)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] EndAddress 64 KB aligned end address of the flash region
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradEndAddress
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint32 EndAddress)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        BaseAddr->FRAD[FradInstance].WORD1 = EndAddress;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the MD0ACP field in WORD2.
 *
 * Flash Region Privileges (FRAD0_WORD2 - FRAD7_WORD2):
 * - Master Domain Access Control Policy (MD0ACP)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] MdAcp value to be written in MD0ACP
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradMd0Acp
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint8 MdAcp)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD2;
        RegValue &= ~QuadSPI_WORD2_MD0ACP_MASK;
        RegValue |= QuadSPI_WORD2_MD0ACP(MdAcp);
        BaseAddr->FRAD[FradInstance].WORD2 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the MD1ACP field in WORD2.
 *
 * Flash Region Privileges (FRAD0_WORD2 - FRAD7_WORD2):
 * - Master Domain Access Control Policy (MD1ACP)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] MdAcp value to be written in MD0ACP
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradMd1Acp
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint8 MdAcp)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD2;
        RegValue &= ~QuadSPI_WORD2_MD1ACP_MASK;
        RegValue |= QuadSPI_WORD2_MD1ACP(MdAcp);
        BaseAddr->FRAD[FradInstance].WORD2 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the VLD bit of a FRAD descriptor.
 *
 * Flash Region Lock Control (FRAD0_WORD3 - FRAD7_WORD3):
 * - Valid (VLD)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] Valid value to be written into VLD bit
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradValid
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    boolean Valid)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD3;
        RegValue &= ~QuadSPI_WORD3_VLD_MASK;
        RegValue |= QuadSPI_WORD3_VLD(Valid ? 1U : 0U);
        BaseAddr->FRAD[FradInstance].WORD3 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the LOCK field of a FRAD descriptor.
 *
 * Flash Region Lock Control (FRAD0_WORD3 - FRAD7_WORD3):
 * - Descriptor Lock (LOCK)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] Lock value to be written into LOCK field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradLock
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint8 Lock)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD3;
        RegValue &= ~QuadSPI_WORD3_LOCK_MASK;
        RegValue |= QuadSPI_WORD3_LOCK(Lock);
        BaseAddr->FRAD[FradInstance].WORD3 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the EALO field of a FRAD descriptor.
 *
 * Flash Region Privileges (FRAD0_WORD2 - FRAD7_WORD2):
 * - Exclusive Access Lock Owner (EALO)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] EaOwner value to be written into EALO field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradEaOwner
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    uint8 EaOwner)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD2;
        RegValue &= ~QuadSPI_WORD2_EALO_MASK;
        RegValue |= QuadSPI_WORD2_EALO(EaOwner);
        BaseAddr->FRAD[FradInstance].WORD2 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Program the EAL field of a FRAD descriptor.
 *
 * Flash Region Lock Control (FRAD0_WORD3 - FRAD7_WORD3):
 * - Exclusive Access Lock (EAL)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 * @param[in] EaLock value to be written into EAL field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetFradEaLock
(
    QuadSPI_Type * BaseAddr,
    uint8 FradInstance,
    Qspi_Ip_SfpEalType EaLock)
{
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        uint32 RegValue = BaseAddr->FRAD[FradInstance].WORD3;
        RegValue &= ~QuadSPI_WORD3_EAL_MASK;
        RegValue |= QuadSPI_WORD3_EAL(EaLock);
        BaseAddr->FRAD[FradInstance].WORD3 = RegValue;
    }
}

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief This field provides exclusive write lock over a FRAD region based on MDnACP.
 *
 * Flash Region Lock Control (FRAD0_WORD3 - FRAD7_WORD3):
 * - Exclusive Access Lock (EAL)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] FradInstance index of the FRAD descriptor to be configured
 *
 * @return the value read from the EAL field
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline uint8 Qspi_Ip_Sfp_FradEaLock
(
    QuadSPI_Type const * BaseAddr,
    uint8 FradInstance)
{
    uint32 RegValue = 0U;
    if (FradInstance < QuadSPI_FRAD_COUNT)
    {
        RegValue = (BaseAddr->FRAD[FradInstance].WORD3 & QuadSPI_WORD3_LOCK_MASK) >> QuadSPI_WORD3_LOCK_SHIFT;
    }
    return (uint8)RegValue;
}

#endif /* QSPI_IP_SFP_ENABLE_FRAD */

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * @brief Configure the timeout to abort the ongoing write or read command.
 *
 * Master Timeout (MTO):
 * - Write Timeout (WRITE_TO)
 *
 * @param[in] BaseAddr base address of the given QuadSPI instance
 * @param[in] Timeout timeout value to be programmed into the register
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
static inline void Qspi_Ip_Sfp_SetMasterTimeout
(
    QuadSPI_Type * BaseAddr,
    uint32 Timeout)
{
    BaseAddr->MTO = Timeout;
}

#endif /* QSPI_IP_SFP_ENABLE_GLOBAL */

#endif /* FEATURE_QSPI_HAS_SFP */


#endif /* (QSPI_IP_MEM_INSTANCE_COUNT > 0) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QUADSPI_HW_ACCESS_H */
