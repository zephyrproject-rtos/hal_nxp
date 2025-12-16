/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_HWACCESS_H
#define XSPI_IP_HWACCESS_H

/**
*   @file Xspi_Ip_HwAccess.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_HwAccess.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Xspi_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_HW_ACCESS_VENDOR_ID_H                       43
#define XSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H        4
#define XSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H        9
#define XSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H     0
#define XSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H                0
#define XSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H                8
#define XSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types.h header file are of the same vendor */
#if (XSPI_IP_HW_ACCESS_VENDOR_ID_H != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_HwAccess.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Autosar version */
#if ((XSPI_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_HwAccess.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Software version */
#if ((XSPI_IP_HW_ACCESS_SW_MAJOR_VERSION_H != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_HW_ACCESS_SW_MINOR_VERSION_H != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_HW_ACCESS_SW_PATCH_VERSION_H != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_HwAccess.h and Xspi_Ip_Types.h are different"
#endif

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct {                                         /* offset: 0x800, array step: 0x20 */
    __IO uint32_t WORD0;                             /**< Flash Region Start Address, array offset: 0x800, array step: 0x20 */
    __IO uint32_t WORD1;                             /**< Flash Region End Address, array offset: 0x804, array step: 0x20 */
    __IO uint32_t WORD2;                             /**< Flash Region Privileges, array offset: 0x808, array step: 0x20 */
    __IO uint32_t WORD3;                             /**< Flash Region Lock Control, array offset: 0x80C, array step: 0x20 */
    __I  uint32_t WORD4;                             /**< Flash Region Compare Address Status, array offset: 0x810, array step: 0x20 */
    __I  uint32_t WORD5;                             /**< Flash Region Compare Status Data, array offset: 0x814, array step: 0x20 */
    __IO uint32_t WORD6;                             /**< Flash Region Privileges, array offset: 0x818, array step: 0x20 */
    uint8_t RESERVED_0[8];
  } Xspi_Ip_FradType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*Calculate Frad offset start from XSPI_Type->FRAD0_WORD0. */
/*
Frad 0->7  offset = index * 0x20
Frad 8->15 offset = index * 0x20 + 0x80, eg: Frad8 -> offset = 8 * 0x20 + 0x80 = 0x180
if index = 0,..7.   -> (index >> 3U) = 0U
if index = 8,..15.  -> (index >> 3U) = 1U
*/
#define XSPI_IP_FRAD_OFFSET(index)      ((uint32)(((uint32)(index) * 0x20U) + (((uint32)(index) >> 3U)* 0x80U)))

/*IBE OBE configuration offset. See chapter SOC Configuration Register in Chip-specific*/
#define XSPI_IP_SOCCR_IBE_XSPI_SCK_DUMMY_OFFSET      (1U)
#define XSPI_IP_SOCCR_OBE_XSPI_SCK_DUMMY_OFFSET      (2U)
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/*
 * Checks if XSPI has completed a transaction on behalf of the current EENV
 */
static inline boolean Xspi_Ip_GetTransactionFinished(const XSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->FR;

    RegValue = (RegValue & XSPI_REG(FR_TFF_MASK));
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Clear Transaction Finished Flag
 */
static inline void Xspi_Ip_ClearBusyStatus(XSPI_Type *BaseAddr)
{
    BaseAddr->FR = XSPI_REG(FR_TFF_MASK);
}


/*
 * Checks the FSM state
 */
static inline uint32 Xspi_Ip_GetFsmState(const XSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->FSMSTAT;

    RegValue = (RegValue & XSPI_REG(FSMSTAT_STATE_MASK)) >> XSPI_REG(FSMSTAT_STATE_SHIFT);
    return RegValue;
}


/*
 * Checks the FSM valid flag
 */
static inline boolean Xspi_Ip_GetFsmValid(const XSPI_Type *BaseAddr)
{
    uint32 RegValue = (uint32)BaseAddr->FSMSTAT;

    RegValue = (RegValue & XSPI_REG(FSMSTAT_VLD_MASK));
    return (RegValue != 0U)? TRUE : FALSE;
}




/*
 * Triggers an IP transaction
 */
static inline void Xspi_Ip_IpTrigger(XSPI_Type *BaseAddr,
                                     uint8 SeqID,
                                     uint16 DataSize,
                                     boolean ArbLock,
                                     boolean ArbUnlock
                                    )
{
    BaseAddr->SFP_TG_IPCR =  XSPI_REG(SFP_TG_IPCR_SEQID)(SeqID)
                                 | XSPI_REG(SFP_TG_IPCR_IDATSZ)(DataSize)
                                 | XSPI_REG(SFP_TG_IPCR_ARB_LOCK)(ArbLock ? 1U : 0U)
                                 | XSPI_REG(SFP_TG_IPCR_ARB_UNLOCK)(ArbUnlock ? 1U : 0U);
}


/*
 * Sets address for IP transactions
 */
static inline Xspi_Ip_StatusType Xspi_Ip_SetIpAddr(XSPI_Type *BaseAddr,
                                     uint32 Addr
                                    )
{
    Xspi_Ip_StatusType Status = STATUS_XSPI_IP_ERROR;

#ifndef WORKAROUND_VDKK5_275
    uint32 TgSfars = BaseAddr->TGSFARS;
    boolean QueueBusy = ((TgSfars & XSPI_REG(TGSFARS_VLD_MASK)) >> XSPI_REG(TGSFARS_VLD_SHIFT)) != 0u;

    if (!QueueBusy)
#endif
    {
        BaseAddr->SFP_TG_SFAR = Addr;
        Status = STATUS_XSPI_IP_SUCCESS;
    }

    return Status;
}

/*
 * Configures the Watermark for the Tx buffer, expressed in number of 4-byte entries
 */
static inline void Xspi_Ip_SetTxWatermark(XSPI_Type *BaseAddr,
                                          uint8 Watermark
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->TBCT;

    RegValue &= (uint32)(~((uint32)XSPI_REG(TBCT_WMRK_MASK)));
    RegValue |= XSPI_REG(TBCT_WMRK)(Watermark);
    BaseAddr->TBCT = (uint32)RegValue;
}


/*
 * Writes data in the Tx buffer
 */
static inline void Xspi_Ip_WriteTxData(XSPI_Type *BaseAddr, uint32 Data)
{
    BaseAddr->TBDR = Data;
}


/*
 * Clear Rx buffer
 */
static inline void Xspi_Ip_ClearRxBuf(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= XSPI_REG(MCR_CLR_RXF_MASK);
}


/*
 * Clear Tx buffer
 */
static inline void Xspi_Ip_ClearTxBuf(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= XSPI_REG(MCR_CLR_TXF_MASK);
}


/*
 * Configure DQS
 */
static inline void Xspi_Ip_SetDQS(XSPI_Type *BaseAddr,
#if FEATURE_XSPI_EXT_DQS_LATENCY
                                  boolean dqsLatEn,
#endif
                                  boolean ddrEn,
                                  boolean dqsEn
                                 )
{
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(MCR_DQS_EN_MASK) | XSPI_REG(MCR_DDR_EN_MASK))));
#if FEATURE_XSPI_EXT_DQS_LATENCY
    RegValue &= (uint32)(~((uint32)(XSPI_REG(MCR_DQS_LAT_EN_MASK))));
#endif

    RegValue |= (XSPI_REG(MCR_DQS_EN)(dqsEn? 1U : 0U) | XSPI_REG(MCR_DDR_EN)(ddrEn? 1U : 0U));
#if FEATURE_XSPI_EXT_DQS_LATENCY
    RegValue |= (XSPI_REG(MCR_DQS_LAT_EN)(dqsLatEn? 1U : 0U));
#endif

    BaseAddr->MCR = RegValue;
}

/*
 * Configure DQS
 */
static inline void Xspi_Ip_DqsOutEnable(XSPI_Type *BaseAddr, boolean dqsOutEn
                                 )
{
    uint32 RegValue = BaseAddr->MCR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(MCR_DQS_OUT_EN_MASK))));

    RegValue |= (XSPI_REG(MCR_DQS_OUT_EN)(dqsOutEn? 1U : 0U));

    BaseAddr->MCR = RegValue;
}

/*
 * Configure Idle signal drive values
 */
static inline void Xspi_Ip_SetISD(XSPI_Type *BaseAddr,
                                  uint8 isdA2,
                                  uint8 isdA3
                                 )
{
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(MCR_ISD2FA_MASK) | XSPI_REG(MCR_ISD3FA_MASK))));

    RegValue |= (XSPI_REG(MCR_ISD2FA)(isdA2) | XSPI_REG(MCR_ISD3FA)(isdA3));

    BaseAddr->MCR = RegValue;
}

/*
 * Configure clock selection settings
 */
static inline void Xspi_Ip_SetClk(XSPI_Type *BaseAddr,
                                  Xspi_Ip_ReadModeType readModeA,
                                  boolean diffClockA
                                 )
{
    uint32 RegValue = (uint32)BaseAddr->MCR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(MCR_DQS_FA_SEL_MASK) | XSPI_REG(MCR_CKN_FA_EN_MASK))));

    RegValue |= (XSPI_REG(MCR_DQS_FA_SEL)((uint32)readModeA) | XSPI_REG(MCR_CKN_FA_EN)(diffClockA ? 1U : 0U));

    BaseAddr->MCR = RegValue;
}

/*
 * Configure output signal timing
 */
static inline void Xspi_Ip_SetOutTiming(XSPI_Type *BaseAddr,
                                        Xspi_Ip_FlashDataAlignType tdh,
                                        uint8 tcsh,
                                        uint8 tcss
                                       )
{
    uint32 RegValue = (uint32)BaseAddr->FLSHCR;
    RegValue |= XSPI_REG(FLSHCR_TCSS)(tcss) | XSPI_REG(FLSHCR_TCSH)(tcsh);
    RegValue |= XSPI_REG(FLSHCR_TDH)(tdh);
    BaseAddr->FLSHCR = RegValue;
}

/*
 * Configure Hresp mask option in SOCCR
 */
static inline void Xspi_Ip_SetHrespMask(XSPI_Type *BaseAddr,
                                        boolean EnableMask
                                       )
{
    uint32 RegValue = (uint32)BaseAddr->SOCCR;

    RegValue &= ~XSPI_REG(SOCCR_HRESP_ERR_MASK_MASK);
    RegValue |= XSPI_REG(SOCCR_HRESP_ERR_MASK)(EnableMask? 1U : 0U);

    /*Enable IN/OUT for Dummy pad. using for Dummy Pad loopback read mode.*/
    RegValue |=  (((uint32)1U << (uint32)XSPI_IP_SOCCR_IBE_XSPI_SCK_DUMMY_OFFSET) | ((uint32)1U << (uint32)XSPI_IP_SOCCR_OBE_XSPI_SCK_DUMMY_OFFSET));
    BaseAddr->SOCCR = RegValue;
}


/*
 * Configures error payload to be returned in case of error if AHB HRESP error masking is enabled
 */
static inline void Xspi_Ip_SetErrPayload(XSPI_Type *BaseAddr,
                                         uint32 high,
                                         uint32 low
                                        )
{
    BaseAddr->AHB_ERR_PAYLOAD_HI = high;
    BaseAddr->AHB_ERR_PAYLOAD_LO = low;
}


/*
 * Configure parameters related to sampling Rx data
 */
static inline void Xspi_Ip_SetRxCfg(XSPI_Type *BaseAddr,
                                    Xspi_Ip_SampleDelayType Delay,
                                    Xspi_Ip_SamplePhaseType ClockPhase,
                                    uint8 tapSelectA
                                   )
{
    uint32 RegValue = (uint32)BaseAddr->SMPR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(SMPR_FSPHS_MASK) | XSPI_REG(SMPR_FSDLY_MASK) | XSPI_REG(SMPR_DLLFSMPFA_MASK))));

    RegValue |= (XSPI_REG(SMPR_FSPHS)(ClockPhase) | XSPI_REG(SMPR_FSDLY)(Delay) | XSPI_REG(SMPR_DLLFSMPFA)(tapSelectA));

    BaseAddr->SMPR = RegValue;
}


/*
 * Set seq. ID for AHB reads
 * Also enable automatic invalidation of obsolete AHB data
 */
static inline void Xspi_Ip_SetAhbReadSeq(XSPI_Type *BaseAddr,
                                         uint8 seqID
                                        )
{
    uint32 RegValue     = BaseAddr->BFGENCR;

    RegValue           &= ((uint32)~((uint32)(XSPI_REG(BFGENCR_SEQID_MASK))));
    RegValue           |= XSPI_REG(BFGENCR_SEQID)(seqID) | XSPI_REG(BFGENCR_WR_FLUSH_EN_MASK);
    BaseAddr->BFGENCR   = RegValue;
}

/*
 * Set seq. ID for AHB writes
 * Also enable automatic invalidation of obsolete AHB data
 */
static inline void Xspi_Ip_SetAhbWriteSeq(XSPI_Type *BaseAddr, uint8 seqID)
{

    uint32 RegValue     = BaseAddr->BFGENCR;

    RegValue           &= ((uint32)~((uint32)(XSPI_REG(BFGENCR_SEQID_WR_MASK))));
    RegValue           |= XSPI_REG(BFGENCR_SEQID_WR)(seqID) | XSPI_REG(BFGENCR_SEQID_WR_EN_MASK) | XSPI_REG(BFGENCR_WR_FLUSH_EN_MASK);
    BaseAddr->BFGENCR   = RegValue;

}

/*
 * Configure parameters related to sampling Rx data
 */
static inline void Xspi_Ip_SetAddrCfg(XSPI_Type *BaseAddr,
                                      uint8 columnAddr,
                                      boolean wordAddresable,
                                      boolean dWordAddresable,
                                      boolean byteSwap
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->SFACR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(SFACR_CAS_MASK) | XSPI_REG(SFACR_WA_MASK) | XSPI_REG(SFACR_WA_4B_EN_MASK) | XSPI_REG(SFACR_BYTE_SWAP_MASK))));
    RegValue |= (XSPI_REG(SFACR_CAS)(columnAddr) | XSPI_REG(SFACR_WA)(wordAddresable? 1U : 0U) | XSPI_REG(SFACR_WA_4B_EN)(dWordAddresable? 1U : 0U) | XSPI_REG(SFACR_BYTE_SWAP)(byteSwap? 1U : 0U));

    BaseAddr->SFACR = RegValue;
}

/*
 * Configure external flash memory map
 */
static inline void Xspi_Ip_SetMemMap(uint32 instance,
                                     XSPI_Type *baseAddr,
                                     const Xspi_Ip_ControllerConfigType * userConfigPtr
                                    )
{
    baseAddr->SFAD[0][0] = Xspi_Ip_AhbAddress[instance] + userConfigPtr->memSizeA1;
    baseAddr->SFAD[0][1] = Xspi_Ip_AhbAddress[instance] + userConfigPtr->memSizeA1 + userConfigPtr->memSizeA2;
#if FEATURE_XSPI_HAS_SIDE_B
    baseAddr->SFAD[1][0] = Xspi_Ip_AhbAddress[instance] + userConfigPtr->memSizeA1 + userConfigPtr->memSizeA2 + userConfigPtr->memSizeB1;
    baseAddr->SFAD[1][1] = Xspi_Ip_AhbAddress[instance] + userConfigPtr->memSizeA1 + userConfigPtr->memSizeA2 + userConfigPtr->memSizeB1 + userConfigPtr->memSizeB2;
#endif
}

/*
 * Configure AHB transactions timeout
 */
static inline void Xspi_Ip_SetAhbTimeout(XSPI_Type *baseAddr, uint16 timeout)
{
    baseAddr->AHRDYTO = (uint32)timeout;
}


/*
 * Configure IP transactions timeout
 */
static inline void Xspi_Ip_SetTransactionTimeout(XSPI_Type *baseAddr, uint32 timeout)
{
    baseAddr->MTO = timeout;
}


/*
 * Configure Arbitration lock timeout
 */
static inline void Xspi_Ip_SetArbitrationTimeout(XSPI_Type *baseAddr, uint32 timeout)
{
    baseAddr->SFP_ARB_TIMEOUT = timeout;
}


/*
 * Configure MGC->TG1_FIX_PRIO
 */
static inline void Xspi_Ip_CfgPrioTg1(XSPI_Type *BaseAddr, boolean Tg1FixPrio)
{
    if (Tg1FixPrio)
    {
        BaseAddr->MGC |= XSPI_REG(MGC_TG1_FIX_PRIO_MASK);
    }
}

/*
 * Sets AHB buffer 0 configuration
 */
static inline void Xspi_Ip_SetAhbBuf0(XSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->BUF0CR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(BUF0CR_ADATSZ_MASK) | XSPI_REG(BUF0CR_MSTRID_MASK) )));
    RegValue |=  (XSPI_REG(BUF0CR_ADATSZ)((uint32)Size >> 3U) | XSPI_REG(BUF0CR_MSTRID)(Master));

    BaseAddr->BUF0CR = RegValue;
}


/*
 * Sets AHB buffer 1 configuration
 */
static inline void Xspi_Ip_SetAhbBuf1(XSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->BUF1CR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(BUF1CR_ADATSZ_MASK) | XSPI_REG(BUF1CR_MSTRID_MASK) )));
    RegValue |=  (XSPI_REG(BUF1CR_ADATSZ)((uint32)Size >> 3U) | XSPI_REG(BUF1CR_MSTRID)(Master));

    BaseAddr->BUF1CR = RegValue;
}


/*
 * Sets AHB buffer 2 configuration
 */
static inline void Xspi_Ip_SetAhbBuf2(XSPI_Type *BaseAddr,
                                      uint16 Size,
                                      uint8 Master
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->BUF2CR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(BUF2CR_ADATSZ_MASK) | XSPI_REG(BUF2CR_MSTRID_MASK) )));
    RegValue |=  (XSPI_REG(BUF2CR_ADATSZ)((uint32)Size >> 3U) | XSPI_REG(BUF2CR_MSTRID)(Master));

    BaseAddr->BUF2CR = RegValue;
}


/*
 * Sets AHB buffer 3 configuration
 */
static inline void Xspi_Ip_SetAhbBuf3(XSPI_Type *BaseAddr,
                                       uint16 Size,
                                       uint8 Master,
                                       boolean AllMasters
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->BUF3CR;

    RegValue &= (uint32)(~((uint32)(XSPI_REG(BUF3CR_ADATSZ_MASK) | XSPI_REG(BUF3CR_MSTRID_MASK) | XSPI_REG(BUF3CR_ALLMST_MASK) )));
    RegValue |=  (XSPI_REG(BUF3CR_ADATSZ)((uint32)Size >> 3U) | XSPI_REG(BUF3CR_MSTRID)(Master) | XSPI_REG(BUF3CR_ALLMST)(AllMasters? 1U : 0U));

    BaseAddr->BUF3CR = RegValue;
}


/*
 * Sets AHB buffer 0 index. Parameter represents desired end index of the buffer.
 */
static inline void Xspi_Ip_SetAhbBufInd(XSPI_Type *BaseAddr,
                                        uint8 IndNo,
                                        uint32 BufIndex
                                       )
{
    BaseAddr->BUFIND[IndNo] =  BufIndex;
}


/*
 * Configures sub-buffers for one buffer
 */
static inline void Xspi_Ip_ConfigAhbSubBuf(XSPI_Type *BaseAddr,
                                           uint8 bufNo,
                                           const Xspi_Ip_ControllerAhbSubbufConfigType* config
                                          )
{
    uint32 RegValue1;
    uint32 RegValue2;
    uint8 subBuf;
    uint16 startAddr;
    uint16 endAddr;

    /* Configure sub-buffer enable and size partitioning in BUFnCR */
    RegValue1 = (uint32)(~((uint32)(XSPI_REG(BUF0CR_SUBBUF0_DIV_MASK) | XSPI_REG(BUF0CR_SUBBUF1_DIV_MASK) | XSPI_REG(BUF0CR_SUBBUF2_DIV_MASK) | XSPI_REG(BUF0CR_SUB_DIV_EN_MASK) )));
    RegValue2 = (XSPI_REG(BUF0CR_SUB_DIV_EN)(config->enabled? 1U : 0U) | XSPI_REG(BUF0CR_SUBBUF0_DIV)(config->divFactor[0]) |
                           XSPI_REG(BUF0CR_SUBBUF1_DIV)(config->divFactor[1]) | XSPI_REG(BUF0CR_SUBBUF2_DIV)(config->divFactor[2]));

    switch(bufNo)
    {
        case 0u:
            BaseAddr->BUF0CR = (BaseAddr->BUF0CR & RegValue1) | RegValue2;
            break;
        case 1u:
            BaseAddr->BUF1CR = (BaseAddr->BUF1CR & RegValue1) | RegValue2;
            break;
        case 2u:
            BaseAddr->BUF2CR = (BaseAddr->BUF2CR & RegValue1) | RegValue2;
            break;
        case 3u:
            BaseAddr->BUF3CR = (BaseAddr->BUF3CR & RegValue1) | RegValue2;
            break;
        default:
            ; /* unknown operation */
            break;
    }
    /* Configure sub-buffer ranges if enabled */
    if (config->enabled)
    {
        for (subBuf = 0U; subBuf < XSPI_IP_AHB_SUB_BUFFERS; subBuf++)
        {
            startAddr = config->startAddr[subBuf];
            endAddr = config->endAddr[subBuf];
            BaseAddr->BUF_ADDR_RANGE[bufNo][subBuf] = ((uint32)endAddr << 16U) + (uint32)startAddr;
        }
    }
}

/*
 * Configures mdad settings
 */
static inline void Xspi_Ip_Config_Mdad(XSPI_Type *BaseAddr,
                                       uint8 index,
                                       const Xspi_Ip_SfpMdadCfgType* config
                                      )
{
    uint32 RegValue;
    __IO uint32 * MdadRegister[XSPI_MDAD_COUNT] = {
                                                    (__IO uint32*)&BaseAddr->TG0MDAD,
                                                    (__IO uint32*)&BaseAddr->TG1MDAD,
                                                  };
    /* Pointer to MDAD Register address */
    __IO uint32 *mdad = MdadRegister[index];

    RegValue = XSPI_REG(TG0MDAD_MIDMATCH)(config->DomainId) |
               XSPI_REG(TG0MDAD_MASK)(config->Mask) |
               XSPI_REG(TG0MDAD_MASKTYPE)(config->MaskType) |
               XSPI_REG(TG0MDAD_SA)(config->SecureAttribute) |
               XSPI_REG(TG0MDAD_VLD)(config->Valid? 1U : 0U);
    *mdad = RegValue;
}


/*
 * Locks mdad settings
 */
static inline void Xspi_Ip_Lock_Mdad(XSPI_Type *BaseAddr,
                                     uint8 index
                                    )
{
    __IO uint32 * MdadRegister[XSPI_MDAD_COUNT] = {
                                                    (__IO uint32*)&BaseAddr->TG0MDAD,
                                                    (__IO uint32*)&BaseAddr->TG1MDAD,
                                                  };
    /* Pointer to MDAD Register address */
    __IO uint32 *mdad = MdadRegister[index];

    *mdad |= XSPI_REG(TG0MDAD_LCK)(1U);
}

/*
 * Configures frad settings
 */
static inline void Xspi_Ip_Config_Frad(XSPI_Type *BaseAddr,
                                       uint8 index,
                                       const Xspi_Ip_SfpFradCfgType* config
                                      )
{
    /* Pointer to FRAD Registers address */
    Xspi_Ip_FradType *frad = ((Xspi_Ip_FradType *)((uint32_t)(&BaseAddr->FRAD0_WORD0) + XSPI_IP_FRAD_OFFSET(index)));

    frad->WORD0 = config->StartAddress;
    frad->WORD1 = config->EndAddress;
    frad->WORD2 = XSPI_REG(FRAD0_WORD2_MD0ACP)(config->MdAcp[0]) |
                  XSPI_REG(FRAD0_WORD2_MD1ACP)(config->MdAcp[1]);
    frad->WORD3 = XSPI_REG(FRAD0_WORD3_VLD)(config->Valid? 1U : 0U);
}

/*
 * Locks frad settings
 */
static inline void Xspi_Ip_Lock_Frad(XSPI_Type *BaseAddr,
                                     uint8 index
                                    )
{
    /* Pointer to FRAD Registers address */
    Xspi_Ip_FradType *frad = ((Xspi_Ip_FradType *)((uint32_t)(&BaseAddr->FRAD0_WORD0) + XSPI_IP_FRAD_OFFSET(index)));

    frad->WORD3 |= XSPI_REG(FRAD0_WORD3_LOCK)(1U);
}

/*
 * Enable XSPI controller
 */
static inline void Xspi_Ip_Enable(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR &= ~XSPI_REG(MCR_MDIS_MASK);
}

/*
 * Disable XSPI controller
 */
static inline void Xspi_Ip_Disable(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= XSPI_REG(MCR_MDIS_MASK);
}

/*
 * Assert XSPI sw reset bits
 */
static inline void Xspi_Ip_SwResetOn(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR |= (XSPI_REG(MCR_SWRSTHD_MASK) | XSPI_REG(MCR_SWRSTSD_MASK) | XSPI_REG(MCR_IPS_TG_RST_MASK));
}

/*
 * Deassert XSPI sw reset bits
 */
static inline void Xspi_Ip_SwResetOff(XSPI_Type *BaseAddr)
{
    BaseAddr->MCR &= ~(XSPI_REG(MCR_SWRSTHD_MASK) | XSPI_REG(MCR_SWRSTSD_MASK) | XSPI_REG(MCR_IPS_TG_RST_MASK));
}

/*
 * Enable/Disable DQS slave delay chain
 */
static inline void Xspi_Ip_DLLSlaveEn(XSPI_Type *BaseAddr,
                                      uint8 dllIdx,
                                      boolean Enable
                                     )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_EN_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_EN)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Activates/Deactivates DQS slave delay chain update
 */
static inline void Xspi_Ip_DLLSlaveUpdate(XSPI_Type *BaseAddr,
                                          uint8 dllIdx,
                                          boolean Enable
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_UPD_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_UPD)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Activates/Deactivates DQS slave delay chain update
 */
static inline void Xspi_Ip_DLLEnable(XSPI_Type *BaseAddr,
                                     uint8 dllIdx,
                                     boolean Enable
                                    )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_DLLEN_MASK)));
    RegValue |= XSPI_REG(DLLCR_DLLEN)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Activates/Deactivates slave DLL bypass
 */
static inline void Xspi_Ip_DLLSlaveBypass(XSPI_Type *BaseAddr,
                                          uint8 dllIdx,
                                          boolean Enable
                                         )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_DLL_BYPASS_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_DLL_BYPASS)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Activates/Deactivates slave auto update
 */
static inline void Xspi_Ip_DLLSlaveAutoUpdate(XSPI_Type *BaseAddr,
                                              uint8 dllIdx,
                                              boolean Enable
                                             )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLAVE_AUTO_UPDT_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLAVE_AUTO_UPDT)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Activates/Deactivates delay-chain for high frequency of operation
 */
static inline void Xspi_Ip_DLLFreqEn(XSPI_Type *BaseAddr,
                                     uint8 dllIdx,
                                     boolean Enable
                                    )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_FREQEN_MASK)));
    RegValue |= XSPI_REG(DLLCR_FREQEN)(Enable? 1U : 0U);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Sets slave delay chain coarse delay for DLL bypass mode
 */
static inline void Xspi_Ip_DLLSetDelayCoarse(XSPI_Type *BaseAddr,
                                             uint8 dllIdx,
                                             uint8 CoarseDelay
                                            )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_DLY_COARSE_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_DLY_COARSE)(CoarseDelay);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Sets fine adjustment delay elements for DLL bypass mode
 */
static inline void Xspi_Ip_DLLSlaveDlyFine(XSPI_Type *BaseAddr,
                                           uint8 dllIdx,
                                           uint8 delay
                                          )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_DLY_FINE_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_DLY_FINE)(delay);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Sets DLL reference counter
 */
static inline void Xspi_Ip_DLLSetReferenceCounter(XSPI_Type *BaseAddr,
                                                  uint8 dllIdx,
                                                  uint8 ReferenceCounter
                                                 )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_DLL_REFCNTR_MASK)));
    RegValue |= XSPI_REG(DLLCR_DLL_REFCNTR)(ReferenceCounter);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}


/*
 * Sets DLL resolution
 */
static inline void Xspi_Ip_DLLSetResolution(XSPI_Type *BaseAddr,
                                            uint8 dllIdx,
                                            uint8 Resolution
                                           )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_DLLRES_MASK)));
    RegValue |= XSPI_REG(DLLCR_DLLRES)(Resolution);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}


/*
 * Sets slave delay chain coarse offset
 */
static inline void Xspi_Ip_DLLSetDelayOffset(XSPI_Type *BaseAddr,
                                             uint8 dllIdx,
                                             uint8 CoarseDelay
                                            )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_DLY_OFFSET_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_DLY_OFFSET)(CoarseDelay);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}

/*
 * Sets slave delay chain fine offset
 */
static inline void Xspi_Ip_DLLSetFineOffset(XSPI_Type *BaseAddr,
                                            uint8 dllIdx,
                                            uint8 FineDelay
                                           )
{
    uint32 RegValue = (uint32)BaseAddr->DLLCR[dllIdx];

    RegValue &= (uint32)(~((uint32)XSPI_REG(DLLCR_SLV_FINE_OFFSET_MASK)));
    RegValue |= XSPI_REG(DLLCR_SLV_FINE_OFFSET)(FineDelay);
    BaseAddr->DLLCR[dllIdx] = (uint32)RegValue;
}


/*
 * Checks high frequency slave delay chain lock status
 */
static inline boolean Xspi_Ip_DLLGetSlaveLockStatus(const XSPI_Type *BaseAddr,
                                                    uint8 dllIdx
                                                   )
{
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    if (dllIdx == 0U)
    {
        RegValue = (RegValue & XSPI_REG(DLLSR_SLVA_LOCK_MASK));
    }
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Checks DLL lock status
 */
static inline boolean Xspi_Ip_DLLGetLockStatus(const XSPI_Type *BaseAddr,
                                               uint8 dllIdx
                                              )
{
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    if (dllIdx == 0U)
    {
        RegValue = (RegValue & XSPI_REG(DLLSR_DLLA_LOCK_MASK));
    }
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Checks high frequency slave delay chain error status
 */
static inline boolean Xspi_Ip_DLLGetErrorStatus(const XSPI_Type *BaseAddr,
                                                uint8 dllIdx
                                               )
{
    uint32 RegValue = (uint32)BaseAddr->DLLSR;

    if (dllIdx == 0U)
    {
        RegValue = RegValue & (XSPI_REG(DLLSR_DLLA_RANGE_ERR_MASK) | XSPI_REG(DLLSR_DLLA_FINE_UNDERFLOW_MASK));
    }
    return (RegValue != 0U)? TRUE : FALSE;
}


/*
 * Configure access rights of HIFs to LUTs
 */
static inline void Xspi_Ip_Config_LutAccess(XSPI_Type *BaseAddr,
                                            uint8 index,
                                            uint16 accessRights
                                           )
{
    BaseAddr->SFP_LUT_EN[index] = (uint32)accessRights;
}


/*
 * Enables FRADs and MDADs
 */
static inline void Xspi_Ip_EnableFradsMdads(XSPI_Type *BaseAddr)
{
    BaseAddr->MGC = (uint32)(XSPI_REG(MGC_GVLDFRAD_MASK) | XSPI_REG(MGC_GVLDMDAD_MASK) | XSPI_REG(MGC_GVLD_MASK));
}


/*
 * Disables FRADs and MDADs
 */
static inline void Xspi_Ip_DisableFradsMdads(XSPI_Type *BaseAddr)
{
    BaseAddr->MGC = (uint32)0U;
}


/*
 * Enables global configuration lock
 */
static inline void Xspi_Ip_GlobaConfigurationLockEnable(XSPI_Type *BaseAddr)
{
    BaseAddr->MGC |= (uint32)XSPI_REG(MGC_GCLCK_MASK);
}



#endif /* (XSPI_IP_MEM_INSTANCE_COUNT > 0) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_HWACCESS_H */
