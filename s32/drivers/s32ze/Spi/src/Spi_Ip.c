/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Spi_Ip.c
*   @implements     Spi_Ip.c_Artifact
*
*   @brief   SPI low-level driver implementations.
*   @details SPI low-level driver implementations.
*
*   @addtogroup SPI_IP_DRIVER Spi Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Spi_Ip.h"
#include "Spi_Ip_Cfg.h"
#include "OsIf.h"
#if (SPI_IP_DMA_USED == STD_ON)
#include "Dma_Ip.h"
#include "Dma_Ip_Hw_Access.h"
#endif
#if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #define USER_MODE_REG_PROT_ENABLED   (SPI_IP_ENABLE_USER_MODE_SUPPORT)
   #include "RegLockMacros.h"
#endif
#include "SchM_Spi.h"
#if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_VENDOR_ID_C                      43
#define SPI_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define SPI_IP_AR_RELEASE_MINOR_VERSION_C       7
#define SPI_IP_AR_RELEASE_REVISION_VERSION_C    0
#define SPI_IP_SW_MAJOR_VERSION_C               2
#define SPI_IP_SW_MINOR_VERSION_C               0
#define SPI_IP_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Ip.c and Mcal.h are different"
    #endif

    #if (SPI_IP_DMA_USED == STD_ON)
        /* Check if current file and Dma_Ip header file are of the same Autosar version */
        #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
             (SPI_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi_Ip.c and Dma_Ip.h are different"
        #endif
    #endif

    #if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
        #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
             (SPI_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi_Ip.c and RegLockMacros.h are different"
        #endif
    #endif

    /* Check if the current file and SchM_Spi.h header file are of the same version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_SPI_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_SPI_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi_Ip.c and SchM_Spi.h are different"
    #endif

    /* Check if the current file and OsIf.h header file are of the same version */
    #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Spi_Ip.c and OsIf.h are different"
    #endif
#endif

#if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if Spi_Ip source file and Devassert.h header file are of the same release version */
        #if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
             (SPI_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Spi_Ip.c and Devassert.h are different"
        #endif
    #endif
#endif /* (STD_ON == SPI_IP_DEV_ERROR_DETECT) */

/* Check if Spi_Ip.h and Spi_Ip.c are of the same vendor */
#if (SPI_IP_VENDOR_ID != SPI_IP_VENDOR_ID_C)
    #error "Spi_Ip.h and Spi_Ip.c have different vendor ids"
#endif
/* Check if Spi_Ip.h file and Spi_Ip.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Spi_Ip.h and Spi_Ip.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION != SPI_IP_SW_MAJOR_VERSION_C) || \
     (SPI_IP_SW_MINOR_VERSION != SPI_IP_SW_MINOR_VERSION_C) || \
     (SPI_IP_SW_PATCH_VERSION != SPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Spi_Ip.h and Spi_Ip.c are different"
#endif

/* Check if Spi_Ip_Cfg.h and Spi_Ip.c are of the same vendor */
#if (SPI_IP_VENDOR_ID_CFG != SPI_IP_VENDOR_ID_C)
    #error "Spi_Ip_Cfg.h and Spi_Ip.c have different vendor ids"
#endif
/* Check if Spi_Ip_Cfg.h file and Spi_Ip.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG != SPI_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION_CFG != SPI_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION_CFG != SPI_IP_AR_RELEASE_REVISION_VERSION_C))
#error "AutoSar Version Numbers of Spi_Ip_Cfg.h and Spi_Ip.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION_CFG != SPI_IP_SW_MAJOR_VERSION_C) || \
     (SPI_IP_SW_MINOR_VERSION_CFG != SPI_IP_SW_MINOR_VERSION_C) || \
     (SPI_IP_SW_PATCH_VERSION_CFG != SPI_IP_SW_PATCH_VERSION_C))
#error "Software Version Numbers of Spi_Ip_Cfg.h and Spi_Ip.c are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (SPI_IP_DMA_USED == STD_ON)
    /* the maximum of Major loop when Minor loop Channel Linking Disabled */
    #define SPI_IP_DMA_MAX_ITER_CNT_U16 ((uint16)0x7FFFu)
#endif

/* Maximum value of CTARE[DTCP] */
#define SPI_IP_CTARE_DTCP_MAX_U16 (SPI_CTARE_DTCP_MASK >> SPI_CTARE_DTCP_SHIFT)
/* Pushr CONT mask to be used for CMD field which is uint16  */
#define SPI_IP_PUSHR_CONT_MASK_U16  ((uint16)(SPI_PUSHR_CONT_MASK >> 16))
/* Pushr FCPCS mask to be used for CMD field which is uint16  */
#define SPI_PUSHR_PP_MCSC_MASK_U16         ((uint16)(SPI_PUSHR_PP_MCSC_MASK >> 16))
/*  Maximum number of bytes that can be written in a FIFO entry */
#define SPI_TX_WORD_SIZE    (SPI_TXFR_TXDATA_WIDTH / 8U)
/*  Maximum number of bytes that can be read from a FIFO entry */
#define SPI_RX_WORD_SIZE    (SPI_RXFR_RXDATA_WIDTH / 8U)
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static SPI_Type* const Spi_Ip_apxBases[SPI_INSTANCE_COUNT] = IP_SPI_BASE_PTRS;

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
VAR_SEC_NOCACHE(Spi_Ip_u32DiscardData) static uint32 Spi_Ip_u32DiscardData;
    #define SPI_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

VAR_SEC_NOCACHE(Spi_Ip_axStateStructure) static Spi_Ip_StateStructureType Spi_Ip_axStateStructure[SPI_IP_NUMBER_OF_INSTANCES];
VAR_SEC_NOCACHE(Spi_Ip_apxStateStructureArray) static Spi_Ip_StateStructureType* Spi_Ip_apxStateStructureArray[SPI_INSTANCE_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Spi_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

static void Spi_Ip_TransferProcess(uint8 Instance);
#if (SPI_IP_DMA_USED == STD_ON)
static void Spi_Ip_CmdDmaTcdSGInit(uint8 Instance);
#if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
static void Spi_Ip_CmdDmaTcdSGConfig(uint8 Instance,
                                     uint8 TCDSGId,
                                     uint32 CmdAdd,
                                     uint16 Iter,
                                     uint8 DisHwReq);
static void Spi_Ip_DmaFastConfig(uint8 Instance, const Spi_Ip_FastTransferType *FastTransferCfg, uint8 NumberOfTransfer);
static void Spi_Ip_RxDmaTcdSGConfig(uint8 Instance, uint8 TCDSGIndex, uint8 DisHwReq);
static void Spi_Ip_RxDmaTcdSGInit(uint8 Instance);
static void Spi_Ip_TxDmaTcdSGConfig(uint8 Instance, uint8 TCDSGIndex, uint8 DisHwReq);
static void Spi_Ip_TxDmaTcdSGInit(uint8 Instance);
#endif
#endif
#if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
void Spi_Ip_SetUserAccess(uint8 Instance);
static void Spi_Ip_SetUserAccessAllowed(uint8 Instance);
#endif /* SPI_IP_ENABLE_USER_MODE_SUPPORT */

static void Spi_Ip_WriteTxFifo
(
    uint16 NumberOfWrites,
    uint8 Instance
);
static void Spi_Ip_ReceiveData
(
    uint16 NumberOfReads,
    uint8 Instance
);
static void Spi_Ip_ChannelFinished
(
    uint8 Instance, boolean ErrorFlag
);

#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
static void Spi_Ip_CheckValidParameters
(
    const Spi_Ip_ExternalDeviceType *ExternalDevice,
    uint16 Length,
    const uint8 *TxBuffer,
    const uint8 *RxBuffer,
    uint32 TimeOut
);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief   Fill CMD FIFO
* @details Write PushrCmds to CMD FIFO
*
* @param[in]     State      State of the current transfer
* @param[in]     Base       Base address of the instance regs to be updated
* @return none
*/
static uint16 Spi_Ip_WriteCmdFifo(Spi_Ip_StateStructureType* State, SPI_Type *Base)
{
    uint16 NumberOfCmdWrites = 0u;
    uint16 i;

    NumberOfCmdWrites = (uint16)((Base->SREX) & SPI_SREX_CMDCTR_MASK) >> SPI_SREX_CMDCTR_SHIFT;
    if (NumberOfCmdWrites <= SPI_IP_FIFO_SIZE_U16)
    {
        NumberOfCmdWrites = SPI_IP_FIFO_SIZE_U16 - NumberOfCmdWrites;
    }
    else
    {
        /* Handle hw error on bits. Ceil CMDCTR and calculate result: SPI_IP_FIFO_SIZE_U16 - SPI_IP_FIFO_SIZE_U16 */
        NumberOfCmdWrites = 0;
    }
    if (NumberOfCmdWrites > State->ExpectedCmdFifoWrites)
    {
        NumberOfCmdWrites = State->ExpectedCmdFifoWrites;
    }
    for (i = 0; i < NumberOfCmdWrites; i++)
    {
        if (State->Pushr0RepeatIndex < State->Pushr0Repeat)
        {
            State->Pushr0RepeatIndex++;
        }
        else
        {
            State->NbCmdsIndex++;
        }
#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(State->NbCmdsIndex < 3u);
#endif
        Base->PUSHR.FIFO.CMD = State->PushrCmds[State->NbCmdsIndex];
        State->ExpectedCmdFifoWrites--;
    }

    return NumberOfCmdWrites;
}

/**
* @brief   This function is called by Spi_Ip_IrqHandler or Spi_Ip_ManageBuffers. It will process transfer in interrupt mode and polling mode.
* @details This function will fill data into TX FIFO and read data in RX FIFO fill to Rx Buffers.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Spi_Ip_TransferProcess(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister;
    uint16 NumberOfReads;
    boolean ErrorFlag = (boolean)FALSE;

    if (SPI_IP_BUSY == State->Status)
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        Base->SR &= 0xFFFF0000u;

        if ( (0u != (SrStatusRegister & (SPI_SR_RFOF_MASK | SPI_SR_TFUF_MASK))) )
        {
            /* mark error flag */
            ErrorFlag = (boolean)TRUE;
        }
        else
        {
            /* Read all data available in receive HW fifo. */
            NumberOfReads = (uint16)(((Base->SR) & SPI_SR_RXCTR_MASK) >> SPI_SR_RXCTR_SHIFT);
            if (NumberOfReads > SPI_IP_FIFO_SIZE_U16)
            {
                NumberOfReads = SPI_IP_FIFO_SIZE_U16;
            }
            if(NumberOfReads != 0u)
            {
                /* Read data from RX FIFO */
                Spi_Ip_ReceiveData(NumberOfReads, Instance);
            }

#if (SPI_IP_SLAVE_SUPPORT == STD_ON)
            if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
#endif
            {
                if (State->ExpectedCmdFifoWrites != 0u)
                {
                    (void)Spi_Ip_WriteCmdFifo(State, Base);
                }
            }
            /* Push data until HW fifo is full or transfer is done. */
            /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO to prepare
            to fill TX FIFO. At that time, another interrupt occurred and preemptive current interrupt, and the time to process that interrupt is longer than the time to transfer all frames
            in TX FIFO. So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from that interrupt and fill TX FIFO until full and exist SPI interrupt function.
            And if there is a interrupt occurred with higher priority of SPI interrupt and the time to process that interrupt is longer than the time to transfer all frames in TX FIFO.
            So, RX FIFO can be overflow due to SPI interrupt function is not serviced to read RX FIFO.
            To avoid this, limitation total of frames in TX FIFO and RX FIFO is lower than FIFO's size(considered that maybe there is an frame on going). */
            if (State->CurrentTxFifoSlot > (State->ExpectedFifoWrites - State->TxIndex))
            {
                State->CurrentTxFifoSlot = State->ExpectedFifoWrites - State->TxIndex;
            }
            if(State->CurrentTxFifoSlot != 0u)
            {
                Spi_Ip_WriteTxFifo(State->CurrentTxFifoSlot, Instance);
                /* Update current TX FIFO slot can be written */
                State->CurrentTxFifoSlot = 0u;
            }
        }
        /* End of transfer if all of frames are received or has error */
        if ((State->RxIndex == State->ExpectedFifoReads) || ((boolean)TRUE == ErrorFlag))
        {
            /* Only set HALT bit to stop transfer when there is a error or request to de-assert CS at the end of transfers sequence */
            if(((boolean)TRUE == ErrorFlag) || ((boolean)FALSE == State->KeepCs))
            {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_12();
                /* Stop Transfer */
                Base->MCR |= SPI_MCR_HALT_MASK;
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_12();
            }
            /* Disable interrupts and DMA requests. */
            Base->RSER = 0U;
            /* Channel finished */
            Spi_Ip_ChannelFinished(Instance, ErrorFlag);
        }
    }
}

static void Spi_Ip_CalculateFifoWords(uint16 FrameSize, uint16 NbBytes,
                                      uint16 *Frames, uint16 *TxBytesPerWord,
                                      uint16 *RxBytesPerWord)
{
    uint16 BytesPerWord;
    uint16 BytesPerFrame;

    /* Calculate value of BytesPerWord and BytesPerFrame based on FrameSize */
    if (FrameSize > 16u)
    {
        BytesPerWord = 4u;
        BytesPerFrame = FrameSize / 32u * BytesPerWord;
        /* E.g. 72-bit frame -> 3 words (32,32,8) bits */
        if (0u != (FrameSize % 32u))
        {
            BytesPerFrame += BytesPerWord;
        }
    }
    else if (FrameSize > 8u)
    {
        BytesPerWord = 2u;
        BytesPerFrame = BytesPerWord;
    }
    else
    {
        BytesPerWord = 1u;
        BytesPerFrame = BytesPerWord;
    }

    *Frames = NbBytes / BytesPerFrame;

    /* Return maximum bytes that fits in TX FIFO */
    if (BytesPerWord < SPI_TX_WORD_SIZE)
    {
        *TxBytesPerWord = BytesPerWord;
    }
    else
    {
        *TxBytesPerWord = SPI_TX_WORD_SIZE;
    }

    /* Return by maximum bytes that fits in RX FIFO */
    if (BytesPerWord < SPI_RX_WORD_SIZE)
    {
        *RxBytesPerWord = BytesPerWord;
    }
    else
    {
        *RxBytesPerWord = SPI_RX_WORD_SIZE;
    }
}

static void Spi_Ip_UpdateCtarAndPushr(Spi_Ip_StateStructureType* State, SPI_Type *Base)
{
    const Spi_Ip_ExternalDeviceType *Dev = State->ExternalDevice;
    uint32 PushrCmd32 = ((uint32)Dev->PushrCmd) << 16u;
    uint16 CtarFrameSize;
    uint16 CtareFrameSize;
    uint32 CtarSrc;
    uint16 i;

#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State->NbCmds > 0u);
#endif

#if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
    CtarSrc = Dev->Ctar[State->ClockMode];
#else
    CtarSrc = Dev->Ctar;
#endif

    CtarFrameSize = (uint16)Dev->DeviceParams->FrameSize - 1u;
    CtareFrameSize = (CtarFrameSize >> 4u) & 0x1u;
#if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if (State->PhyUnitConfig->SlaveMode)
    {
        Base->MODE.CTAR_SLAVE[0] = CtarSrc | SPI_CTAR_SLAVE_FMSZ(CtarFrameSize);
    }
    else
#endif
    {
        for (i = 0u; i < State->NbCmds; i++) {
            Base->MODE.CTAR[i] = CtarSrc |
                                  SPI_CTAR_FMSZ(CtarFrameSize) |
                                  SPI_CTAR_LSBFE(Dev->DeviceParams->Lsb ? 1u : 0u);
            Base->CTARE[i] = Dev->Ctare |
                                SPI_CTARE_FMSZE(CtareFrameSize) |
                                SPI_CTARE_DTCP(State->DTCPValue[i]);
            State->PushrCmds[i] = (uint16)(((PushrCmd32 & (~SPI_PUSHR_CTAS_MASK)) |
                                    SPI_PUSHR_CTAS(i)) >> 16u);
        }
        /* Clear PUSHR_PP_MCSC bit for last frame */
        State->PushrCmds[i - 1u] &= ~SPI_PUSHR_PP_MCSC_MASK_U16;
        /* Update last pushr to clear CS if needed */
        if (((State->PushrCmds[i - 1u] & SPI_IP_PUSHR_CONT_MASK_U16) != 0u) && (State->KeepCs == FALSE))
        {
            State->PushrCmds[i - 1u] &= ~SPI_IP_PUSHR_CONT_MASK_U16;
        }
    }
}

/**
* @brief   Init State and update CTAR, CTARE and PUSHR
* @details SPI_IP_CTARE_DTCP_MAX_U16  will be repeated the needed number of times.
*          Remaining bytes will be sent with a new DTCP
*          If CONT needs to be used, an other DTCP is configured and the last updated
*          Write CTAR, CTARE and prepare PUSHR values.
*          Prepare PushrCmd values based on DTCPs and CONT.
*
* @param[in]     State      State of the current transfer
* @param[in]     Base       Base address of the instance regs to be updated
* @param[in]     NbBytes    Number of bytes of the transfer
* @return void
*/
static void Spi_Ip_PrepareTransfer(Spi_Ip_StateStructureType* State, SPI_Type *Base, uint16 NbBytes)
{
    uint16 Frames;
    uint16 TxBytesPerWord;
    uint16 RxBytesPerWord;

    Spi_Ip_CalculateFifoWords(State->ExternalDevice->DeviceParams->FrameSize, NbBytes,
                              &Frames, &TxBytesPerWord, &RxBytesPerWord);

    /*
     * How a transfer works using DTCP feature:
     * Transfer is split in up to 3 commands, each one using a different CTAR with its own DTCP value.
     *  Case 1: CS_TOGGLE and Frames < SPI_IP_CTARE_DTCP_MAX_U16
     *    - CMD0 uses CTAR0 with DTCP = Frames -> One command sends all frames.
     *  
     *  Case 2: CS_TOGGLE and Frames > DTCP_MAX
     *    - CMD0 uses CTAR0 with DTCP = DTCP_MAX -> CMD0 is sent until (repeated) remaining frames < DTCP_MAX
     *    - CMD1 uses CTAR1 with DTCP = remaining frames -> CMD1 is sent after all CMD0 are sent to send remaining frames
     * 
     *  Case 3: CS_KEEP_ASSERTED and Keep_CS = True and Frames < SPI_IP_CTARE_DTCP_MAX_U16
     *    - CMD0 uses CTAR0 with DTCP = Frames - 1
     *    - CMD1 uses CTAR1 with DTCP = 1 (Unset CONT bit)
     * 
     *  Case 4: CS_KEEP_ASSERTED and Keep_CS = True and Frames > SPI_IP_CTARE_DTCP_MAX_U16
     *    - CMD0 uses CTAR0 as in case 2
     *    - CMD1 uses CTAR1 with DTCP = remaining frames - 1
     *    - CMD2 uses CTAR2 with DTCP = 1 (Unset CONT bit)
     */
    State->RxIndex = 0u;
    State->TxIndex = 0u;
    State->NbCmdsIndex = 0;
    State->Pushr0RepeatIndex = 0;
    State->NbCmds = 1u;
#if SPI_IP_SLAVE_SUPPORT == STD_ON
    if ((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
#endif
    {
        if (TRUE == State->KeepCs)
        {
            /* Can't use CTARE[DTCP] if CS is active between transfers.
             * DTCP might be different for the next transfer and CTARE can't be updated
             * in the running state
             */
            State->DTCPValue[0] = 1;
            State->Pushr0Repeat = Frames;
            State->ExpectedCmdFifoWrites = State->Pushr0Repeat;

            if (((State->ExternalDevice->PushrCmd & SPI_IP_PUSHR_CONT_MASK_U16) != 0u) && (Frames > 1u))
            {
                State->Pushr0Repeat--;
                State->DTCPValue[1] = 1;
                State->NbCmds++;
            }
        }
        else
        {
            /* Prepare state to use CTARE[DTCP] */
            if (Frames < SPI_IP_CTARE_DTCP_MAX_U16) {
                /* Max DTCP value is enough to send Frames. Set 1 CMD to be pushed 1 time */
                State->DTCPValue[0] = Frames % SPI_IP_CTARE_DTCP_MAX_U16;
                State->Pushr0Repeat = 1u;
                State->DTCPValue[1] = 0u;
            }
            else
            {
                /*
                * Max DTCP value is not enough to send Frames
                * Use 2 CMDs:
                *  1: Set DTCP to Max DTCP value. To be pushed Frames / DTCP_MAX times
                *  2: Set DTCP to remaining frames. To be pushed 1 time.
                */
                State->DTCPValue[0] = SPI_IP_CTARE_DTCP_MAX_U16;
                State->Pushr0Repeat = Frames / SPI_IP_CTARE_DTCP_MAX_U16;
                State->DTCPValue[1] = Frames % SPI_IP_CTARE_DTCP_MAX_U16;
                State->NbCmds++;
            }
            /*
            * Split last CMD in 2 if:
            *   - KeepCs and CS Keep asserted are set and
            *   - Last calculated command DTCP is greater then 1.
            * Last CMD DTCP will become DTCP - 1.
            * New CMD is created with DTCP = 1 disabling CONT
            */
            if (State->DTCPValue[State->NbCmds - 1u] > 1u)
            {
                State->DTCPValue[State->NbCmds - 1u]--;
                State->DTCPValue[State->NbCmds] = 1u;
                State->NbCmds++;
            }
            /* Cmd 0 is repeated Pushr0Repeat times and then each cmd 1 time */
            State->ExpectedCmdFifoWrites = State->Pushr0Repeat + State->NbCmds - 1u;
        }
    }
    State->ExpectedFifoWrites = NbBytes / TxBytesPerWord;
    State->ExpectedFifoReads = NbBytes / RxBytesPerWord;

    Spi_Ip_UpdateCtarAndPushr(State, Base);
}

#if (SPI_IP_DMA_USED == STD_ON)
/**
* @brief   This function will initialize all software TCDs Scatter Gather for Command DMA channel.
*          And load software TCD Scatter Gather 0 into hardware TCD.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Spi_Ip_CmdDmaTcdSGInit(uint8 Instance)
{
    const SPI_Type* Base = Spi_Ip_apxBases[Instance];
    const Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelScatterGatherListType DmaTcdList[9u];
    uint8 TCDSGIndex = 0u;

    /* initialze configuration software TCD Scatter Gather for Cmd DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    DmaTcdList[0u].Value = 0u; /* dummy src address read, it will be updated later */
    DmaTcdList[1u].Value = (Dma_Ip_uintPtrType)&Base->PUSHR.FIFO.CMD;    /* dest address write*/
    DmaTcdList[2u].Value = 0u;    /* no src offset */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes dest transfer size */
    DmaTcdList[5u].Value = 2u; /* bytes to transfer for each request */
    DmaTcdList[6u].Value = 0u;    /* no dest offset */
    DmaTcdList[7u].Value = 0u;    /* dummy iteration count will be updated later */
    DmaTcdList[8u].Value = 1u;   /* dummy disable hardware request when major loop complete, will be updated latter in the case of Scatter Gather enabled */

    for(TCDSGIndex = 0u; TCDSGIndex < State->PhyUnitConfig->NumTxCmdDmaSGId; TCDSGIndex++)
    {
        /* Update software TCD Scatter Gather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[TCDSGIndex], DmaTcdList, 9u);
    }

    /* Load software TCD Scatter Gather 0 into hardware TCD */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[0u]);
}

#if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
static void Spi_Ip_TxDmaTcdSGInit(uint8 Instance)
{
    const SPI_Type* Base = Spi_Ip_apxBases[Instance];
    const Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[10u];
    uint8 TCDSGIndex = 0u;

    /* initialze configuration software TCD Scatter Gather for Tx DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[9u].Param = DMA_IP_CH_SET_SOURCE_MODULO;

    DmaTcdList[1u].Value = (Dma_Ip_uintPtrType)&Base->PUSHR.FIFO.TX;    /* dest address write*/
    DmaTcdList[2u].Value = 1u;  /* dummy src offset is 1 byte, will be updated latter according to frame size and transfer default data */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* dummy 1 byte src transfer size, will be updated latter according to frame size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* dummy 1 byte dest transfer size, will be updated latter according to frame size */
    DmaTcdList[5u].Value = 1u;   /* dummy bytes to transfer for each request, will be updated latter according to frame size */
    DmaTcdList[6u].Value = 0u; /* no dest offset */
    DmaTcdList[7u].Value = 0u; /* dummy iteration count, will be updated latter according to number of frames */
    DmaTcdList[8u].Value = 1u; /* dummy disable hardware request when major loop complete, will be updated latter according to last transfer or not */
    DmaTcdList[9u].Value = 0u;  /* dummy no src address modulo, will be updated latter Base on transfer default data or not */
    DmaTcdList[0u].Value = 0u; /* dummy src address read, will be updated latter Base on TxBuffer */

    for(TCDSGIndex = 0u; TCDSGIndex < State->PhyUnitConfig->MaxNumOfFastTransfer; TCDSGIndex++)
    {
        /* Update software TX DMA TCD Scatter Gather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TCDSGIndex], DmaTcdList, 10u);
    }
}

static void Spi_Ip_TxDmaTcdSGConfig(uint8 Instance, uint8 TCDSGIndex, uint8 DisHwReq)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[8u];

    /* Update buffers index */
    State->TxIndex = State->ExpectedFifoWrites;

    /* configure TX DMA TCD Scatter Gather */
    /* No need to configure dest address and dest offset due to they are already set by Spi_Ip_TxDmaTcdSGInit */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_SOURCE_MODULO;

    if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[1u].Value = 1u;  /* src offset is 1 byte */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[4u].Value = 1u;   /* bytes to transfer for each request */
    }
    else
    {
        DmaTcdList[1u].Value = 2u;  /* src offset is 2 bytes */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[4u].Value = 2u;   /* bytes to transfer for each request */
    }
    DmaTcdList[5u].Value = State->ExpectedFifoWrites; /* iteration count */
    DmaTcdList[6u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[7u].Value = 0u;  /* no src address modulo */
    if(NULL_PTR == State->TxBuffer)
    {
        /* send default data */
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)&State->PhyUnitConfig->CmdDmaFast[TCDSGIndex].DefaultData; /* src address read */
        if(State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            DmaTcdList[1u].Value = 0u;  /* src offset is 0 byte */
        }
        else
        {
            DmaTcdList[7u].Value = 2u;  /* data is 4 bytes, src address modulo is 2 bits */
        }
    }
    else
    {
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)State->TxBuffer; /* src address read */
    }
    /* Update software TX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TCDSGIndex], DmaTcdList, 8u);
}

static void Spi_Ip_RxDmaTcdSGInit(uint8 Instance)
{
    const SPI_Type* Base = Spi_Ip_apxBases[Instance];
    const Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[9u];
    uint8 TCDSGIndex = 0u;

    /* initialze configuration software TCD Scatter Gather for Rx DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)&Base->POPR; /* src address read */
    DmaTcdList[2u].Value = 0u;  /* no src offset */
    DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* dummy 1 byte src transfer size, will be updated latter Base on frame size */
    DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* dummy 1 byte dest transfer size, will be updated latter Base on frame size */
    DmaTcdList[5u].Value = 1u;   /* dummy 1 byte to transfer for each request, will be updated latter Base on frame size */
    DmaTcdList[6u].Value = 1u; /* dummy dest offset is 1 byte, will be updated latter Base on frame size and discard info */
    DmaTcdList[1u].Value = 0u;    /* dummy dest address write, will be updated latter Base on RxBuffer */
    DmaTcdList[7u].Value = 0u; /* dummy iteration count, will be updated latter Base on number of frames */
    DmaTcdList[8u].Value = 1u; /* dummy disable hardware request when major loop complete, will be updated latter according to last transfer or not */

    for(TCDSGIndex = 0u; TCDSGIndex < State->PhyUnitConfig->MaxNumOfFastTransfer; TCDSGIndex++)
    {
        /* Update software RX DMA TCD Scatter Gather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[TCDSGIndex], DmaTcdList, 9u);
    }
}

static void Spi_Ip_RxDmaTcdSGConfig(uint8 Instance, uint8 TCDSGIndex, uint8 DisHwReq)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[8u];

    /* Update buffers index */
    State->RxIndex = State->ExpectedFifoReads;

    /* configure RX DMA TCD Scatter Gather */
    /* No need to configure src address and src offset due to they are already set by Spi_Ip_RxDmaTcdSGInit */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[3u].Value = 1u;   /* 1 byte to transfer for each request */
        DmaTcdList[4u].Value = 1u; /* dest offset is 1 bytes */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[3u].Value = 2u;   /* 2 bytes to transfer for each request */
        DmaTcdList[4u].Value = 2u; /* dest offset is 2 bytes */
    }
    else
    {
        DmaTcdList[1u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[2u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[3u].Value = 4u;   /* 4 bytes to transfer for each request */
        DmaTcdList[4u].Value = 4u; /* dest offset is 4 bytes */
    }
    if(NULL_PTR == State->RxBuffer)
    {
        /* Discard data */
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)&Spi_Ip_u32DiscardData;    /* dest address write*/
        DmaTcdList[4u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)State->RxBuffer;    /* dest address write*/
    }
    DmaTcdList[5u].Value = State->ExpectedFifoReads; /* iteration count */
    DmaTcdList[6u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[7u].Value = DisHwReq; /* Enable Major interrupt at the end of transfer sequence(meanning when DisHwReq = 1u) */

    /* Update software RX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[TCDSGIndex], DmaTcdList, 8u);
}

/**
* @brief   This function will configure TCD Scatter Gather for the CMD DMA channel
*/
static void Spi_Ip_CmdDmaTcdSGConfig(uint8 Instance,
                                     uint8 TCDSGId,
                                     uint32 CmdAdd,
                                     uint16 Iter,
                                     uint8 DisHwReq)
{
    const Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[3u];

    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;

    /* configure TCD Scatter Gather for Cmd DMA channel */
    DmaTcdList[0u].Value = CmdAdd; /* src address read */
    DmaTcdList[1u].Value = Iter;    /* iteration count */
    DmaTcdList[2u].Value = DisHwReq;    /* disable hardware request when major loop complete */
    /* Update software TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxCmdDmaChannel, TCDSGId, DmaTcdList, 3u);
}

#endif /* (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON) */

/**
* @brief   This function will configure hardware TCDs for the channels CMD DMA
*          according to current transfer configuration.
*
* @param[in]     State      State of the current transfer
* @return void
*/
static void Spi_Ip_DmaCmdConfigAndStart(const Spi_Ip_StateStructureType* State)
{
    Dma_Ip_LogicChannelTransferListType Tcds[4u] = {
            [0] = { DMA_IP_CH_SET_SOURCE_ADDRESS                    , (Dma_Ip_uintPtrType)&State->PushrCmds[0] },
            [1] = { DMA_IP_CH_SET_MAJORLOOP_COUNT                   , State->Pushr0Repeat },
            [2] = { DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST          , 1u},
            [3] = { DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ  , 0u}
        };

    /*
     * State->Pushr0Repeat will always be less than SPI_IP_DMA_MAX_ITER_CNT_U16 because DMA
     * slave is not implemented.
     * For master, the maximum value can be MAX_U16(FFFF)/MAX_DTCP(7FF) = 0x20
     */

    /* Use while 0 to use break on error to end the block faster */
    if (State->NbCmds > 1u)
    {
        Tcds[2].Value = 0u; /* Enable HW Request */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxCmdDmaChannel,
                                                            State->PhyUnitConfig->TxCmdDmaSGId[0],
                                                            Tcds,
                                                            3u);
        /* Load software TCD Scatter Gather 0 into hardware TCD with ESG bit already set
            * in software TCD */
        (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[0u]);

        Tcds[0].Value = (Dma_Ip_uintPtrType)&State->PushrCmds[1]; /* SOURCE_ADDRESS */ 
        Tcds[1].Value = (uint32)State->NbCmds - 1u;   /* MAJORLOOP */
        Tcds[2].Value = 1u;                           /* Disable HW Request */
        Tcds[3].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        Tcds[3].Value = 2;
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxCmdDmaChannel,
                                                            State->PhyUnitConfig->TxCmdDmaSGId[1],
                                                            Tcds,
                                                            4u);
    }
    else
    {
        Tcds[2].Value = 1u; /* Disable HW Request */
        (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxCmdDmaChannel,
                                                    Tcds, 4u);
    }

    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxCmdDmaChannel, 
                                            DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA
*          according to current transfer configuration.
*
* @param[in]     State      State of the current transfer
* @param[in]     Base       Base address of the instance regs to be updated
* @return void
*/
static void Spi_Ip_DmaConfig(const Spi_Ip_StateStructureType* State,const SPI_Type *Base)
{
    Dma_Ip_LogicChannelTransferListType DmaTcdList[11u];

    /* configure TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTcdList[1u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTcdList[2u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTcdList[3u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTcdList[4u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTcdList[5u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTcdList[6u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTcdList[7u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTcdList[8u].Param = DMA_IP_CH_SET_SOURCE_MODULO;

    DmaTcdList[1u].Value = (Dma_Ip_uintPtrType)&Base->PUSHR.FIFO.TX;    /* dest address write*/
    if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[2u].Value = 1u;  /* src offset is 1 byte */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[5u].Value = 1u;   /* bytes to transfer for each request */
    }
    else
    {
        DmaTcdList[2u].Value = 2u;  /* src offset is 2 bytes */
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[5u].Value = 2u;   /* bytes to transfer for each request */
    }
    DmaTcdList[6u].Value = 0u; /* no dest offset */
    DmaTcdList[7u].Value = 1u; /* disable hardware request when major loop complete */
    DmaTcdList[8u].Value = 0u;  /* no src address modulo */
    if(NULL_PTR == State->TxBuffer)
    {
        /* send default data */
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)&State->ExternalDevice->DeviceParams->DefaultData; /* src address read */
        if(State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            DmaTcdList[2u].Value = 0u;  /* src offset is 0 byte */
        }
        else
        {
            DmaTcdList[8u].Value = 2u;  /* data is 4 bytes, src address modulo is 2 bits */
        }
    }
    else
    {
        DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)State->TxBuffer; /* src address read */
    }
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[9u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    DmaTcdList[9u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 10u);

    /* configure RX DMA channel */
    DmaTcdList[0u].Value = (Dma_Ip_uintPtrType)&Base->POPR; /* src address read */
    DmaTcdList[2u].Value = 0u;  /* no src offset */
    if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE; /* 1 byte src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_1_BYTE;    /* 1 byte dest transfer size */
        DmaTcdList[5u].Value = 1u;   /* 1 byte to transfer for each request */
        DmaTcdList[6u].Value = 1u; /* dest offset is 1 bytes */
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE; /* 2 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_2_BYTE;    /* 2 bytes dest transfer size */
        DmaTcdList[5u].Value = 2u;   /* 2 bytes to transfer for each request */
        DmaTcdList[6u].Value = 2u; /* dest offset is 2 bytes */
    }
    else
    {
        DmaTcdList[3u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE; /* 4 bytes src transfer size */
        DmaTcdList[4u].Value = DMA_IP_TRANSFER_SIZE_4_BYTE;    /* 4 bytes dest transfer size */
        DmaTcdList[5u].Value = 4u;   /* 4 bytes to transfer for each request */
        DmaTcdList[6u].Value = 4u; /* dest offset is 4 bytes */
    }
    if(NULL_PTR == State->RxBuffer)
    {
        /* Discard data */
        DmaTcdList[1u].Value = (Dma_Ip_uintPtrType)&Spi_Ip_u32DiscardData;    /* dest address write*/
        DmaTcdList[6u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        DmaTcdList[1u].Value = (Dma_Ip_uintPtrType)State->RxBuffer;    /* dest address write*/
    }
    DmaTcdList[7u].Value = 1u; /* disable hardware request when major loop complete */
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[8u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    DmaTcdList[8u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 9u);
}

/**
* @brief   This function will configure buffers in hardware TCDs for the channels TX DMA, RX DMA
*           and it will trigger the transfer
*
* @param[in]     State      State of the current transfer
* @return void
*/
static void Spi_Ip_DmaTxRxUpdateLoop(Spi_Ip_StateStructureType* State)
{
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites - State->TxIndex;
    uint16 NumberDmaIterRead;

    Dma_Ip_LogicChannelTransferListType Tcd = {
        .Param = DMA_IP_CH_SET_MAJORLOOP_COUNT
    };

    /* Limits number of major count */
    if (SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = SPI_IP_DMA_MAX_ITER_CNT_U16;
    }

    NumberDmaIterRead = NumberDmaIterWrite;
    if (State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        NumberDmaIterRead = NumberDmaIterWrite/2u;
        if (0u != (NumberDmaIterWrite%2u))
        {
            NumberDmaIterWrite = NumberDmaIterRead;
        }
    }
    State->TxIndex += NumberDmaIterWrite;
    State->RxIndex += NumberDmaIterRead;

    Tcd.Value = NumberDmaIterWrite;
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, &Tcd, 1u);
    
    Tcd.Value = NumberDmaIterRead;
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, &Tcd, 1u);

    /* Enable HW request for RX DMA channel before TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief   Configures and starts a DMA transfer
*
* @param[in]     State      State of the current transfer
* @param[in]     Base       Base address of the instance regs to be updated
* @param[in]     IrqEn      Enable DMA major loop interrupt.
* @return void
*/
static void Spi_Ip_DmaAsyncStart(Spi_Ip_StateStructureType* State, SPI_Type *Base, uint32 IrqEn)
{
    Dma_Ip_LogicChannelTransferListType Tcd = {
        .Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT,
        .Value = IrqEn
    };

    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, &Tcd, 1u);
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if ((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {
        Spi_Ip_DmaCmdConfigAndStart(State);
    }
    /* Config RX and TX channels */
    Spi_Ip_DmaConfig(State, Base);
    /* Enable RX and TX channels */
    Spi_Ip_DmaTxRxUpdateLoop(State);

    /* Enable SPI interrupts and set them to trigger DMA */
    Base->RSER = SPI_RSER_CMDFFF_RE(1) | SPI_RSER_CMDFFF_DIRS(1) |
                    SPI_RSER_TFFF_RE(1) | SPI_RSER_TFFF_DIRS(1) |
                    SPI_RSER_RFDF_RE(1) | SPI_RSER_RFDF_DIRS(1);
}

#endif /*#if (SPI_IP_DMA_USED == STD_ON)*/

/**
* @brief   This function will write data to TX FIFO.
* @details This function will write data to TX FIFO.
*
* @param[in]     NumberOfReads   Number of bytes data will be wrote to TX FIFO .
* @param[in]     Instance         Index of the hardware instance.
* @return none
*/
static void Spi_Ip_WriteTxFifo
(
    uint16 NumberOfWrites,
    uint8 Instance
)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    uint32 Idx;
    uint32 LastIdx;
    uint32 Factor;
    uint16 Count;
    uint16 Data = 0u;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NumberOfWrites <= SPI_IP_FIFO_SIZE_U16);
    #endif
    if(NULL_PTR != State->TxBuffer)
    {
        if(State->ExternalDevice->DeviceParams->FrameSize < 9u) 
        {
            Factor = 1u;
        }
        else
        {
            Factor = 2u;
        }
        LastIdx = ((uint32)State->TxIndex + NumberOfWrites) * Factor;
        for (Idx = State->TxIndex * Factor; Idx < LastIdx; Idx += Factor)
        {
            if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
            {
                Data = State->TxBuffer[Idx];
            }
            else
            {
                Data = *((const uint16*)&State->TxBuffer[Idx]);
            }
            Base->PUSHR.FIFO.TX = Data;  
        }
    }
    else
    {
        for (Count = 0; Count < NumberOfWrites; Count++)
        {
            if(State->ExternalDevice->DeviceParams->FrameSize > 16u)
            {
                /* get first or second word (2 bytes) based on TxIndex */
                Factor = (uint16)((Count % 2u) * 16u);
                Data = (uint16)(State->ExternalDevice->DeviceParams->DefaultData >> Factor); 
            }
            else
            {
                Data = (uint16)State->ExternalDevice->DeviceParams->DefaultData;
            }
            Base->PUSHR.FIFO.TX = Data;
        }
    }
    State->TxIndex += NumberOfWrites;
}

/**
* @brief   This function will read data from RX FIFO in Asynchronous mode.
* @details This function will read data from RX FIFO in Asynchronous mode.
*
* @param[in]     NumberOfReads    Number of bytes in RX FIFO will be read.
* @param[in]     Instance       Index of the hardware instance.
* @return none
*/
static void Spi_Ip_ReceiveData
(
    uint16 NumberOfReads,
    uint8 Instance
)
{
    Spi_Ip_StateStructureType* const State = Spi_Ip_apxStateStructureArray[Instance];
    const SPI_Type* Base = Spi_Ip_apxBases[Instance];
    uint16 LimitedNumberOfReads = NumberOfReads;
    uint32 Data;
    uint32 Idx;
    uint32 LastIdx;
    uint32 Factor;

    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        Factor = 1u;
    }
    else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
    {
        Factor = 2u;
    }
    else
    {
        Factor = 4u;
    }

    /* Limits to remaining frames. */
    if (LimitedNumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
    {
        LimitedNumberOfReads = State->ExpectedFifoReads - State->RxIndex;
    }
    if(NULL_PTR != State->RxBuffer)
    {
        LastIdx = ((uint32)State->RxIndex + LimitedNumberOfReads) * Factor;
        for (Idx = State->RxIndex * Factor; Idx < LastIdx; Idx += Factor)
        {
            Data = Base->POPR;
            if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
            {
                State->RxBuffer[Idx] = (uint8)Data;
            }
            else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
            {
                *((uint16*)&State->RxBuffer[Idx]) = (uint16)Data;
            }
            else
            {
                *((uint32*)&State->RxBuffer[Idx]) = Data;
            }
        }
    }
    else
    {
        /* Discard data */
        for (Idx = 0; Idx < (uint32)LimitedNumberOfReads; Idx++)
        {
            (void)Base->POPR;
        }
    }
    State->RxIndex += LimitedNumberOfReads;

    /* Update current TX FIFO slot */
    if (State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        State->CurrentTxFifoSlot += LimitedNumberOfReads * 2u;
    }
    else
    {
        State->CurrentTxFifoSlot += LimitedNumberOfReads;
    }
}

/**
* @brief   This function will finish transfer of a channel.
* @details This function will finish transfer of a channel.
*
* @param[in]     Instance            Index of the hardware instance.
* @param[in]     ErrorFlag           Save the status of transfer error flags
* @return void
*/
static void Spi_Ip_ChannelFinished(uint8 Instance, boolean ErrorFlag)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Spi_Ip_EventType EventState = SPI_IP_EVENT_FAULT;

    if (TRUE == ErrorFlag)
    {
        State->Status = SPI_IP_FAULT;
        EventState = SPI_IP_EVENT_FAULT;
    }
    else
    {
        State->Status = SPI_IP_IDLE;
        EventState = SPI_IP_EVENT_END_TRANSFER;
    }

    if (NULL_PTR != State->Callback)
    {
        State->Callback(Instance, EventState);
    }
    else
    {
        (void)EventState;
    }
}

/**
* @brief   Write to FIFOs to start Async Transfer
* @details Write TX and TXCMD
*
* @param[in]     State      State of the current transfer
* @param[in]     Base       Base address of the instance regs to be updated
* @return void
*/
static void Spi_Ip_AsyncStart(Spi_Ip_StateStructureType* State, SPI_Type *Base)
{
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    uint16 NumberOfWrites = 0u;
    #endif
    uint16 RemainingWrites = State->ExpectedFifoWrites - State->TxIndex;

    /* Enable interrupts. */
    Base->RSER = SPI_RSER_TCF_RE(1) | SPI_RSER_TFUF_RE(1) | SPI_RSER_RFOF_RE(1);
    /* Fill data into TX FIFO to trigger TCF interrupt */
    /* Write to CMD field first*/
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if ((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {        
        (void)Spi_Ip_WriteCmdFifo(State, Base);
        /* Limits to remaining frames. */
        if (State->CurrentTxFifoSlot > RemainingWrites)
        {
            State->CurrentTxFifoSlot = RemainingWrites;
        }
        if (State->CurrentTxFifoSlot != 0u)
        {
            Spi_Ip_WriteTxFifo(State->CurrentTxFifoSlot, State->ExternalDevice->Instance);
            /* Update current TX FIFO slot can be written */
            State->CurrentTxFifoSlot = 0u;
        }
    }
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    else
    {
        /* In slave mode, TXFIFO will be wrote full first before Master device performs transmision */
        NumberOfWrites = (uint16)((Base->SR) & SPI_SR_TXCTR_MASK) >> SPI_SR_TXCTR_SHIFT;
        if (NumberOfWrites < SPI_IP_FIFO_SIZE_U16)
        {
            NumberOfWrites = SPI_IP_FIFO_SIZE_U16 - NumberOfWrites;
        }
        else
        {
            NumberOfWrites = 0u;
        }
        /* Limits to remaining frames. */
        if (NumberOfWrites > RemainingWrites)
        {
            NumberOfWrites = RemainingWrites;
        }
        /* Write to TXFIFO*/
        Spi_Ip_WriteTxFifo(NumberOfWrites, State->ExternalDevice->Instance);
        /* Update current TX FIFO available */
        State->CurrentTxFifoSlot -= NumberOfWrites;
    }
    #endif
}

#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   This function will verify the validation of some input parameters of transmision functions.
* @details This function will verify the validation of some input parameters of transmision functions.
*
* @param[in]     ExternalDevice   Pointer to the external device where data is transmitted.
* @param[in]     Length         Number of bytes to be sent.
* @return        SPI_IP_STATUS_SUCCESS: Don't have any errors was found.
*                SPI_IP_STATUS_FAIL: Transmission command has not been accepted.
*/
static void Spi_Ip_CheckValidParameters
(
    const Spi_Ip_ExternalDeviceType *ExternalDevice,
    uint16 Length,
    const uint8 *TxBuffer,
    const uint8 *RxBuffer,
    uint32 TimeOut
)
{
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    DevAssert(0u != TimeOut);
    if (ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        DevAssert((Length % 4u) == 0u);
    }
    else if (ExternalDevice->DeviceParams->FrameSize > 8u)
    {
        DevAssert((Length % 2u) == 0u);
    }
    else
    {
        /* do nothing */
    }
    DevAssert(Spi_Ip_apxStateStructureArray[ExternalDevice->Instance] != NULL_PTR);    
    #if ((CPU_TYPE == CPU_TYPE_64) && (SPI_IP_DMA_USED == STD_ON))
    if(State->PhyUnitConfig->DmaUsed)
    {
        /* On DMA with version < 5 only 32 bits addresses are supported.*/
        /* SPI IP is not used in any platform with version > 5 */
        DevAssert((TxBuffer >> 32) == 0);
        DevAssert((RxBuffer >> 32) == 0);
    }
    #else
    (void)TxBuffer;
    (void)RxBuffer;
    #endif
}
#endif
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#if (SPI_IP_DMA_USED == STD_ON)
/**
* @brief   This function will process DMA transfer complete interrupt.
* @details This function will process continue transfer or end of transfer via DMA.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
* @implements Spi_Ip_IrqDmaHandler_Activity
*/
void Spi_Ip_IrqDmaHandler(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    uint32 SrStatusRegister = 0u;
    boolean ErrorFlag = (boolean)FALSE;
    boolean EndOfTransferFlag = (boolean)FALSE;

    if((NULL_PTR != State) && (SPI_IP_BUSY == State->Status))
    {
        /* Read Status and clear all flags. */
        SrStatusRegister = Base->SR;
        Base->SR &= 0xFFFF0000u;

        if ( (0u != (SrStatusRegister & (SPI_SR_RFOF_MASK | SPI_SR_TFUF_MASK))) )
        {
                /* mark error flag */
            ErrorFlag = (boolean)TRUE;
        }
        else
        {
            if (State->ExpectedFifoReads != State->RxIndex)
            {
                Spi_Ip_DmaTxRxUpdateLoop(State);
            }
            else
            {
                EndOfTransferFlag = (boolean)TRUE;
            }
        }

        if (((boolean)TRUE == EndOfTransferFlag) || ((boolean)TRUE == ErrorFlag))
        {
            /* Only set HALT bit to stop transfer when there is a error or request to de-assert CS at the end of transfers sequence */
            if(((boolean)TRUE == ErrorFlag) || ((boolean)FALSE == State->KeepCs))
            {
                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_13();
                /* Stop Transfer */
                Base->MCR |= SPI_MCR_HALT_MASK;
                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_13();
            }
            /* Disable interrupts and DMA requests. */
            Base->RSER = 0U;

            if((boolean)TRUE == ErrorFlag)
            {
                State->Status = SPI_IP_FAULT;
            }
            else
            {
                State->Status = SPI_IP_IDLE;
            }
            if (State->Callback != NULL_PTR)
            {
                if((boolean)TRUE == ErrorFlag)
                {
                    State->Callback(Instance, SPI_IP_EVENT_FAULT);
                }
                else
                {
                    State->Callback(Instance, SPI_IP_EVENT_END_TRANSFER);
                }
            }
        }
    }
    else
    {
        /* Driver is initialized but there was no poll request*/
        /* nothing to do */
    }
}
#endif /* (SPI_IP_DMA_USED == STD_ON) */

#if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief This function will set UAA bit in REG_PROT for SPI unit
*/
void Spi_Ip_SetUserAccess(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];

    SET_USER_ACCESS_ALLOWED((uint32)Base,SPI_IP_PROT_MEM_U32);
}

/**
* @brief This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
*/
static void Spi_Ip_SetUserAccessAllowed(uint8 Instance)
{
    OsIf_Trusted_Call1param(Spi_Ip_SetUserAccess, Instance);
}
#endif /* SPI_IP_ENABLE_USER_MODE_SUPPORT */
/*================================================================================================*/
Spi_Ip_StatusType Spi_Ip_Init(const Spi_Ip_ConfigType *PhyUnitConfigPtr)
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(PhyUnitConfigPtr != NULL_PTR);
    #endif
    Instance = PhyUnitConfigPtr->Instance;
    State = Spi_Ip_apxStateStructureArray[Instance];
    Base = Spi_Ip_apxBases[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State == NULL_PTR);
    #endif
    Spi_Ip_apxStateStructureArray[Instance] = &Spi_Ip_axStateStructure[PhyUnitConfigPtr->StateIndex];
    State = Spi_Ip_apxStateStructureArray[Instance];
    State->PhyUnitConfig = PhyUnitConfigPtr;
    #if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
    Spi_Ip_SetUserAccessAllowed(Instance);
    #endif
    /* Halt before update other fields */
    Base->MCR |= SPI_MCR_HALT_MASK;
    Base->MCR = PhyUnitConfigPtr->Mcr;

    #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
    State->ClockMode = SPI_IP_NORMAL_CLOCK;
    #endif
    State->KeepCs = (boolean)FALSE;
    #if (SPI_IP_DMA_USED == STD_ON)
    #if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
    Spi_Ip_TxDmaTcdSGInit(Instance);
    Spi_Ip_RxDmaTcdSGInit(Instance);
    #endif
    if((boolean)TRUE == State->PhyUnitConfig->DmaUsed)
    {
        Spi_Ip_CmdDmaTcdSGInit(Instance);
    }
    #endif
    /* set State to idle */
    Status = Spi_Ip_UpdateTransferMode(Instance, PhyUnitConfigPtr->TransferMode);
    if (SPI_IP_STATUS_SUCCESS == Status)
    {
        State->Status = SPI_IP_IDLE;
    }
    return Status;
}
/*================================================================================================*/
Spi_Ip_StatusType Spi_Ip_DeInit(uint8 Instance)
{
    SPI_Type* Base;
    const Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    Base = Spi_Ip_apxBases[Instance];
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    if (State->Status == SPI_IP_BUSY)
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Halt before update other fields */
        Base->MCR |= SPI_MCR_HALT_MASK;
        /* Reset FIFOs */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        Base->MCR = 0x4001u;
        Base->MODE.CTAR[0] = 0x78000000u;
        Base->SR = 0xFFFF0000u;
        Base->RSER = 0u;
        Base->CTARE[0] = 0x1u;

        Spi_Ip_apxStateStructureArray[Instance] = NULL_PTR;
    }
    return Status;
}

static Spi_Ip_StatusType Spi_Ip_IntoBusyState(Spi_Ip_StateStructureType* State)
{
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    if (SPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
        Status = SPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = SPI_IP_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();        
    }
    return Status;
}

/* Iteration of reading and writing the FIFO. Returns true if something action was taken inside the iteration */
static boolean Spi_Ip_SyncReadWriteStep(Spi_Ip_StateStructureType *State, SPI_Type *Base, uint8 Instance)
{
    boolean StepDone = FALSE;
    uint16 NumberOfReads;

    /* SEND CMD */
    if (State->ExpectedCmdFifoWrites != 0u)
    {
        if (Spi_Ip_WriteCmdFifo(State, Base) != 0u)
        {
            StepDone = TRUE;
        }
    }
    /* TRANSMIT */

    /* Push data until HW fifo is full or transfer is done. */
    /* After driver code read all frames in RX FIFO, if there are still some frames in TX FIFO, at the time before driver code check number of frames available in TX FIFO
    to prepare to fill TX FIFO. At that time, interrupt occurred, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
    So TX FIFO will be empty and some frames received in RX FIFO, then the program is returned from interrupt and fill TX FIFO until full.
    And there is a interrupt occurred after that before read all frames in RX FIFO, and the time to process interrupt is longer than the time to transfer all frames in TX FIFO.
    So, RX FIFO can be overflow. To avoid this, limits total of frames in TX FIFO and RX FIFO must be lower than FIFO size.
    State->CurrentTxFifoSlot variable is used to hanlde number of frames are "on bus transfer". They are always less than FIFO size */

    /* Limits to remaining frames. */
    if (State->CurrentTxFifoSlot > (State->ExpectedFifoWrites - State->TxIndex))
    {
        State->CurrentTxFifoSlot = State->ExpectedFifoWrites - State->TxIndex;
    }
    if (State->CurrentTxFifoSlot != 0u)
    {
        Spi_Ip_WriteTxFifo(State->CurrentTxFifoSlot, Instance);
        /* Update current TX FIFO slot can be written */
        State->CurrentTxFifoSlot = 0u;
        StepDone = TRUE;
        /* Clear Halt bit, then transfer */
        if(((Base->MCR) & SPI_MCR_HALT_MASK) == SPI_MCR_HALT_MASK)
        {
            Base->MCR &= ~SPI_MCR_HALT_MASK;
        }
    }
    /* RECEIVE */
    /* Read all data available in receive HW fifo. */
    NumberOfReads = (uint16)(((Base->SR) & SPI_SR_RXCTR_MASK) >> SPI_SR_RXCTR_SHIFT);
    if (NumberOfReads > SPI_IP_FIFO_SIZE_U16)
    {
        NumberOfReads = SPI_IP_FIFO_SIZE_U16;
    }
    if(NumberOfReads != 0u)
    {
        /* Read data from RX FIFO */
        Spi_Ip_ReceiveData(NumberOfReads, Instance);
        StepDone = TRUE;
    }

    return StepDone;
}

/*================================================================================================*/
Spi_Ip_StatusType Spi_Ip_SyncTransmit(const Spi_Ip_ExternalDeviceType *ExternalDevice,
                                      const uint8 *TxBuffer,
                                      uint8 *RxBuffer,
                                      uint16 Length,
                                      uint32 TimeOut)
{
    SPI_Type *Base;
    Spi_Ip_StateStructureType *State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, SPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;
    boolean StepDone;

    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    Spi_Ip_CheckValidParameters(ExternalDevice, Length, TxBuffer, RxBuffer, TimeOut);
    #endif
    Instance = ExternalDevice->Instance;
    State = Spi_Ip_apxStateStructureArray[Instance];

    Base = Spi_Ip_apxBases[Instance];
    Status = Spi_Ip_IntoBusyState(State);
    if (SPI_IP_STATUS_SUCCESS == Status)
    {
        /* Make sure that FIFOs will be empty before start new transfer session */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        /* Reset Flags */
        Base->SR = 0xFFFF0000u;

        State->TxBuffer = TxBuffer;
        State->RxBuffer = RxBuffer;
        State->ExternalDevice = ExternalDevice;

        Spi_Ip_PrepareTransfer(State, Base, Length);

        CurrentTicks = OsIf_GetCounter(SPI_IP_TIMEOUT_METHOD); /* initialize current counter */

        /* Get current FIFO slots are available.*/
        State->CurrentTxFifoSlot = SPI_IP_FIFO_SIZE_U16;
        while(SPI_IP_STATUS_SUCCESS == Status)
        {
            /* Read and write FIFO registers */
            StepDone = Spi_Ip_SyncReadWriteStep(State, Base, Instance);
            if (StepDone) 
            {            
                /* Finish the transfer if all frames have received */
                if (State->RxIndex == State->ExpectedFifoReads)
                {
                    break;
                }
                ElapsedTicks = 0u;
            }

            /* Check if errors like overflow or underflow are reported in Status register or timeout error */
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SPI_IP_TIMEOUT_METHOD);
            if (ElapsedTicks >= TimeoutTicks)
            {
                Status = SPI_IP_TIMEOUT;
            }
        }
        /* Only set HALT bit to stop transfer when there is a error or request to de-assert CS at the end of transfers sequence */
        if((SPI_IP_STATUS_SUCCESS != Status) || ((boolean)FALSE == State->KeepCs))
        {
            /* Stop transfer */
            Base->MCR |= SPI_MCR_HALT_MASK;
        }
        /* Channel finished */
        Spi_Ip_ChannelFinished(Instance, FALSE);
    }
    return Status;
}

Spi_Ip_StatusType Spi_Ip_AsyncTransmit(const Spi_Ip_ExternalDeviceType *ExternalDevice,
                                       const uint8 *TxBuffer,
                                       uint8 *RxBuffer,
                                       uint16 Length,
                                       Spi_Ip_CallbackType EndCallback)
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    Spi_Ip_CheckValidParameters(ExternalDevice, Length, TxBuffer, RxBuffer, 1u);
    #endif

    State = Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    Base = Spi_Ip_apxBases[ExternalDevice->Instance];
    Status = Spi_Ip_IntoBusyState(State);
    if (SPI_IP_STATUS_SUCCESS == Status)
    {
        /* Update State structure. */
        State->TxBuffer = TxBuffer;
        State->RxBuffer = RxBuffer;
        State->Callback = EndCallback;

        State->CurrentTxFifoSlot = SPI_IP_FIFO_SIZE_U16;
        State->ExternalDevice = ExternalDevice;

        Spi_Ip_PrepareTransfer(State, Base, Length);
        /* Make sure that FIFOs will be empty before start new transfer session */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        /* Clear all flags. */
        Base->SR &= 0xFFFF0000u;

        #if (SPI_IP_DMA_USED == STD_ON)
        if((boolean)FALSE == State->PhyUnitConfig->DmaUsed)
        #endif
        {
            if (State->TransferMode == SPI_IP_POLLING)
            {
                /* Disable interrupts and DMA requests. */
                Base->RSER = 0U;
            } else {
                /* Interrupt mode */
                Spi_Ip_AsyncStart(State, Base);
            }
        }
        #if (SPI_IP_DMA_USED == STD_ON)
        else
        {
            Spi_Ip_DmaAsyncStart(State, Base, (State->TransferMode == SPI_IP_POLLING) ? 0u : 1u);
        }
        #endif
        SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_11();
        /* Clear Halt bit before transfer */
        Base->MCR &= ~SPI_MCR_HALT_MASK;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_11();
    }
    return Status;
}

#if ((SPI_IP_DMA_USED == STD_ON) && (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON))
Spi_Ip_StatusType Spi_Ip_AsyncTransmitFast(const Spi_Ip_FastTransferType *FastTransferCfg,
                                           uint8 NumberOfTransfer,
                                           Spi_Ip_CallbackType EndCallback)
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
    uint32 LsbValue = 0u;
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    uint8 Count = 0u;

    DevAssert(NULL_PTR != FastTransferCfg);
    DevAssert(NULL_PTR != FastTransferCfg[0u].ExternalDevice);

    State = Spi_Ip_apxStateStructureArray[FastTransferCfg[0u].ExternalDevice->Instance];

    DevAssert(NULL_PTR != State);
    DevAssert(State->TransferMode == SPI_IP_INTERRUPT);
    DevAssert(NumberOfTransfer <= State->PhyUnitConfig->MaxNumOfFastTransfer);

    for(Count = 0u; Count < NumberOfTransfer; Count++)
    {
        DevAssert(NULL_PTR != FastTransferCfg[Count].ExternalDevice);
        DevAssert(0u != FastTransferCfg[Count].Length);
        if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 16u)
        {
            DevAssert((FastTransferCfg[Count].Length % 4u) == 0u);
        }
        else if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 8u)
        {
            DevAssert((FastTransferCfg[Count].Length % 2u) == 0u);
        }
        else
        {
            DevAssert(SPI_IP_DMA_MAX_ITER_CNT_U16 >= FastTransferCfg[Count].Length);
        }
    }
    #endif
    Instance = FastTransferCfg[0u].ExternalDevice->Instance;
    Base = Spi_Ip_apxBases[Instance];
    State = Spi_Ip_apxStateStructureArray[Instance];

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_14();
    if (SPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14();
        Status = SPI_IP_STATUS_FAIL;
    }
    else
    {
        /* Mark the hardware as busy. */
        State->Status = SPI_IP_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_14();

        /* Make sure that FIFOs will be empty before start new transfer session */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        /* Clear all flags. */
        Base->SR &= 0xFFFF0000u;

        /* Update State structure. */
        /* For Dma Fast transfer, All transfers use the same HWUnit and in Master mode only. Only some parameters can be changed as Continuous CS, PCS.
        Some parameters such as Baudrate, Clock Polarity, Clock Phase, Delays timming configuration, Bit Order, Frame Size
        must be the same between transfers. So, make sure they are configured the same in each External Device allocated for Dma Fast Transfers.
        And all those attributes can be got from first transfer in FastTransferCfg */
        State->ExternalDevice = FastTransferCfg[0u].ExternalDevice;
        /* Get Lsb value */
        LsbValue = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
        State->Callback = EndCallback;
        /* Stop transfer at the end of transfers sequence by set HALT bit in Spi_Ip_IrqDmaHandler */
        State->KeepCs = (boolean)FALSE;

        /* Configure external device parameters  like: frane size, clock phase, clock polarity. */
        #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
            Base->MODE.CTAR[0u] = FastTransferCfg[0u].ExternalDevice->Ctar[State->ClockMode] | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
        #else
            Base->MODE.CTAR[0u] = FastTransferCfg[0u].ExternalDevice->Ctar | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & (uint32)0xFu) | SPI_CTAR_LSBFE(LsbValue);
        #endif
        Base->CTARE[0u] = FastTransferCfg[0u].ExternalDevice->Ctare | SPI_CTARE_FMSZE((((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) >> 4u) & (uint32)0x1u);
        /* Config and Enable DMA request. */
        Spi_Ip_DmaFastConfig(Instance, FastTransferCfg, NumberOfTransfer);
        Base->RSER = SPI_RSER_CMDFFF_RE(1u) | SPI_RSER_CMDFFF_DIRS(1u) | SPI_RSER_TFFF_RE(1u) | SPI_RSER_TFFF_DIRS(1u) | SPI_RSER_RFDF_RE(1u) | SPI_RSER_RFDF_DIRS(1u);

        /* Clear Halt bit before transfer */
        Base->MCR &= ~SPI_MCR_HALT_MASK;
    }
    return Status;
}

/**
* @brief   This function will configure Scatter/Gather TCDs for the channels TX DMA, RX DMA and CMD DMA
*          according to Dma Fast transfers configuration. DMA channels will be started at the end of the function.
*/
static void Spi_Ip_DmaFastConfig(uint8 Instance, const Spi_Ip_FastTransferType *FastTransferCfg, uint8 NumberOfTransfer)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    boolean ClearCS = (boolean)FALSE;
    uint8 DisHwRequest = 0u;
    uint8 Count = 0u;
    uint8 CmdTCDSGIndex = 0u;
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];

    DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
    DmaTcdList[0u].Value = 1u;

    for(Count = 0u; Count < NumberOfTransfer; Count++)
    {
        /* Update State structure. */
        State->RxIndex = 0u;
        State->TxIndex = 0u;
        State->TxBuffer = FastTransferCfg[Count].TxBuffer;
        State->RxBuffer = FastTransferCfg[Count].RxBuffer;
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            State->ExpectedFifoWrites = FastTransferCfg[Count].Length;
        }
        else
        {
            State->ExpectedFifoWrites = FastTransferCfg[Count].Length/2u;
        }
        State->ExpectedFifoReads = State->ExpectedFifoWrites;
        if (State->ExternalDevice->DeviceParams->FrameSize >16u)
        {
            State->ExpectedFifoReads = State->ExpectedFifoWrites/2u;
        }
        State->ExpectedCmdFifoWrites = State->ExpectedFifoReads;
        State->PhyUnitConfig->CmdDmaFast[Count].DefaultData = FastTransferCfg[Count].DefaultData;
        State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmd = FastTransferCfg[Count].ExternalDevice->PushrCmd;
        State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmdLast = FastTransferCfg[Count].ExternalDevice->PushrCmd & (~((uint16)((SPI_PUSHR_CONT_MASK | SPI_PUSHR_PP_MCSC_MASK) >> 16u)));

        /* CS will be cleared for last transfer or depend on KeepCs if not last transfer.
        Disable DMA HW request at the end of transfer. */
        if(Count == (NumberOfTransfer - 1u))
        {
            ClearCS = (boolean)TRUE;
            DisHwRequest = 1u;
        }
        else
        {
            if((boolean)FALSE == FastTransferCfg[Count].KeepCs)
            {
                ClearCS = (boolean)TRUE;
            }
            else
            {
                ClearCS = (boolean)FALSE;
            }
            DisHwRequest = 0u;
        }

        /* Configure software TCDs Scatter Gather for CMD DMA channel */
        if((boolean)TRUE == ClearCS)
        {
            if(State->ExpectedCmdFifoWrites > 1u)
            {
                Spi_Ip_CmdDmaTcdSGConfig(   Instance,
                                            State->PhyUnitConfig->TxCmdDmaSGId[CmdTCDSGIndex],
                                            (Dma_Ip_uintPtrType)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmd,
                                            State->ExpectedCmdFifoWrites - 1u,
                                            0u  /* not disable dma hw request, the transfer will be continued after next software TCD Scatter Gather loaded */
                                        );
                CmdTCDSGIndex++;
            }
            Spi_Ip_CmdDmaTcdSGConfig(   Instance,
                                        State->PhyUnitConfig->TxCmdDmaSGId[CmdTCDSGIndex],
                                        (Dma_Ip_uintPtrType)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmdLast,
                                        1u, /* transfer last command to clear CS */
                                        DisHwRequest
                                    );
            CmdTCDSGIndex++;
        }
        else
        {
            Spi_Ip_CmdDmaTcdSGConfig(   Instance,
                                        State->PhyUnitConfig->TxCmdDmaSGId[CmdTCDSGIndex],
                                        (Dma_Ip_uintPtrType)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmd,
                                        State->ExpectedCmdFifoWrites,
                                        DisHwRequest
                                    );
            CmdTCDSGIndex++;
        }
        State->ExpectedCmdFifoWrites = 0u;

        /* Configure software TCDs Scatter Gather for TX DMA channel */
        Spi_Ip_TxDmaTcdSGConfig(Instance, Count, DisHwRequest);

        /* Configure software TCDs Scatter Gather for RX DMA channel */
        Spi_Ip_RxDmaTcdSGConfig(Instance, Count, DisHwRequest);
    }

    /* When all transfers session are completed and next TCD ScatterGather is loaded to HW. If next TCD ScatterGather loaded has INTMAJOR=0 then
    Dma_Ip interrupt function will not call Spi Dma notification due to it understood as spurious interrupt(Done flag = 1, INTMAJOR=0).
    So, the workaround is set INTMAJOR=1 for next TCD ScatterGather. */
    if (NumberOfTransfer < State->PhyUnitConfig->NumberRxSG)
    {
        /* Set INTMAJOR=1 for next RX TCD ScatterGather */
        (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[NumberOfTransfer], DmaTcdList, 1u);
    }

    /* Load first software TCD to hardware TCD for CMD DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[0u]);
    /* Load first software TCD to hardware TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[0u]);
    /* Load first software TCD to hardware TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[0u]);

    /* Enable HW request for RX DMA channel before TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxCmdDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}
#endif

void Spi_Ip_ManageBuffers(uint8 Instance)
{
    const Spi_Ip_StateStructureType* State;
    #if (SPI_IP_DMA_USED == STD_ON)
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    #endif

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    if(SPI_IP_POLLING == State->TransferMode)
    {
        #if (SPI_IP_DMA_USED == STD_ON)
        if((boolean)FALSE == State->PhyUnitConfig->DmaUsed)
        #endif
        {
            Spi_Ip_TransferProcess(Instance);
        }
        #if (SPI_IP_DMA_USED == STD_ON)
        else
        {
            DmaChannelStatus.Done = FALSE;
            (void)Dma_Ip_GetLogicChannelStatus(State->PhyUnitConfig->RxDmaChannel, &DmaChannelStatus);
            if((boolean)TRUE == DmaChannelStatus.Done)
            {
                /* Clear DONE bit */
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_DONE);
                Spi_Ip_IrqDmaHandler(Instance);
            }
        }
        #endif
    }
}
/*================================================================================================*/

Spi_Ip_StatusType Spi_Ip_UpdateTransferParam
(
    const Spi_Ip_ExternalDeviceType *ExternalDevice,
    const Spi_Ip_TransferAdjustmentType *Param
)
{
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != ExternalDevice);
    DevAssert(NULL_PTR != Param);
    DevAssert(NULL_PTR != Spi_Ip_apxStateStructureArray[ExternalDevice->Instance]);
    #endif

    State = Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    if (State->Status != SPI_IP_BUSY)
    {
        State->KeepCs = Param->KeepCs;
        if (Param->DeviceParams != NULL_PTR) 
        {
            ExternalDevice->DeviceParams->DefaultData = Param->DeviceParams->DefaultData;
            ExternalDevice->DeviceParams->FrameSize = Param->DeviceParams->FrameSize;
            ExternalDevice->DeviceParams->Lsb = Param->DeviceParams->Lsb;
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
    }
    else
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
        Status = SPI_IP_STATUS_FAIL;
    }
    
    return Status;
}

Spi_Ip_StatusType Spi_Ip_UpdateFrameSize(const Spi_Ip_ExternalDeviceType *ExternalDevice, uint8 FrameSize)
{
    const Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(SPI_IP_FRAMESIZE_MAX_U8 >= FrameSize);
    DevAssert(SPI_IP_FRAMESIZE_MIN_U8 <= FrameSize);
    #endif
    State = Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    /* Frame size can be changed when no transfers are in progress. */
    if (State->Status != SPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->FrameSize = FrameSize;
    }
    else
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Spi_Ip_StatusType Spi_Ip_UpdateLsb(const Spi_Ip_ExternalDeviceType *ExternalDevice, boolean Lsb)
{
    const Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    #endif
    State = Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != SPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->Lsb = Lsb;
    }
    else
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Spi_Ip_StatusType Spi_Ip_UpdateDefaultTransmitData(const Spi_Ip_ExternalDeviceType *ExternalDevice, uint32 DefaultData)
{
    const Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ExternalDevice != NULL_PTR);
    #endif
    State = Spi_Ip_apxStateStructureArray[ExternalDevice->Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    /* Bite order can be changed when no transfers are in progress. */
    if (State->Status != SPI_IP_BUSY)
    {
        ExternalDevice->DeviceParams->DefaultData = DefaultData;
    }
    else
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    return Status;
}

Spi_Ip_StatusType Spi_Ip_UpdateTransferMode(uint8 Instance, Spi_Ip_ModeType Mode)
{
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    /* Transfer mode can be changed when no transfers are in progress. */
    if (State->Status != SPI_IP_BUSY)
    {
        State->TransferMode = Mode;
    }
    else
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    return Status;
}

void Spi_Ip_Cancel(uint8 Instance)
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    Base = Spi_Ip_apxBases[Instance];
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_10();
    if(SPI_IP_BUSY == State->Status)
    {
        /* Halt before update RSER */
        Base->MCR |= SPI_MCR_HALT_MASK;
        /* Disable interrupts and DMA requests. */
        Base->RSER = 0U;
        #if (SPI_IP_DMA_USED == STD_ON)
        if((boolean)TRUE == State->PhyUnitConfig->DmaUsed)
        {
            /* Disable all HW request */
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
            if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
            #endif
            {
                (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxCmdDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            }
            (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        }
        #endif
        /* Clear FIFO */
        Base->MCR |= (SPI_MCR_CLR_RXF_MASK | SPI_MCR_CLR_TXF_MASK);
        /* set State to idle */
        State->Status = SPI_IP_IDLE;
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_10();
}

/**
* @brief   This function is called by SPI ISRs.
* @details This function will process activities for flags TCF, RFOF and TFUF.
*
* @param[in]     Instance            Instance of the hardware unit.
*
* @implements Spi_Ip_IrqHandler_Activity
*/
void Spi_Ip_IrqHandler(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    const Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    uint32 IrqFlags = 0u;

    if(NULL_PTR != State)
    {
        /* the driver has been initialized */
        IrqFlags = Base->SR & (SPI_SR_TCF_MASK | SPI_SR_RFOF_MASK | SPI_SR_TFUF_MASK);
        IrqFlags &= Base->RSER & (SPI_RSER_TCF_RE_MASK | SPI_RSER_RFOF_RE_MASK | SPI_RSER_TFUF_RE_MASK);
        if(0u != IrqFlags)
        {
            Spi_Ip_TransferProcess(Instance);
        }
        else
        {
            /* Do nothing - Return immediately */
        }
    }
    else
    {
        /* the driver has not been initialized */
        /* clear all flags */
        Base->SR &= 0xFFFF0000u;
    }
}

/**
* @brief   This function returns the status of the SPI driver.
* @details This function returns the status of the SPI driver.
*
* @return Spi_Ip_HwStatusType
*
* @param[in]     Instance            Instance of the hardware unit.
*/
Spi_Ip_HwStatusType Spi_Ip_GetStatus(uint8 Instance)
{
    const Spi_Ip_StateStructureType* State;
    Spi_Ip_HwStatusType Status = SPI_IP_UNINIT;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    State = Spi_Ip_apxStateStructureArray[Instance];
    if (State != NULL_PTR)
    {
        Status = State->Status;
    }
    return Status;
}

#if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
Spi_Ip_StatusType Spi_Ip_SetClockMode(uint8 Instance, Spi_Ip_DualClockModeType ClockMode)
{
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;

    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SPI_INSTANCE_COUNT);
    #endif
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(State != NULL_PTR);
    #endif
    /* Clock mode can be changed when no transfers are in progress. */
    if (State->Status != SPI_IP_BUSY)
    {
        State->ClockMode = ClockMode;
    }
    else
    {
        Status = SPI_IP_STATUS_FAIL;
    }
    return Status;
}
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
