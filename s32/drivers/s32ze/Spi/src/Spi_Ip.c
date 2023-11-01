/*
 * Copyright 2021-2023 NXP NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Spi_Ip.c
*   
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
#define SPI_IP_SW_MAJOR_VERSION_C               1
#define SPI_IP_SW_MINOR_VERSION_C               0
#define SPI_IP_SW_PATCH_VERSION_C               0
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

/**
* @brief Maximum value of CTARE[DTCP]
*/
#define SPI_IP_CTARE_DTCP_MAX_U16    (uint16) 2047u
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/ 
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

static Spi_Ip_StateStructureType Spi_Ip_axStateStructure[SPI_IP_NUMBER_OF_INSTANCES];

#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Spi_MemMap.h"

#if (SPI_IP_DMA_USED == STD_ON)
    #define SPI_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
uint32 Spi_Ip_u32DiscardData;
    #define SPI_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #include "Spi_MemMap.h"
#endif

#define SPI_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

Spi_Ip_StateStructureType* Spi_Ip_apxStateStructureArray[SPI_INSTANCE_COUNT];

#define SPI_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Spi_MemMap.h"

#define SPI_START_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"

static SPI_Type* const Spi_Ip_apxBases[SPI_INSTANCE_COUNT] = IP_SPI_BASE_PTRS;

#define SPI_STOP_SEC_CONST_UNSPECIFIED
#include "Spi_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

static void Spi_Ip_TransferProcess(uint8 Instance);
#if (SPI_IP_DMA_USED == STD_ON)
static void Spi_Ip_DmaConfig(uint8 Instance);
static void Spi_Ip_CmdDmaTcdSGInit(uint8 Instance);
static void Spi_Ip_CmdDmaTcdSGConfig(   uint8 Instance, 
                                        uint8 TCDSGId, 
                                        uint32 CmdAdd,
                                        uint16 Iter, 
                                        uint8 DisHwReq
                                    );
static void Spi_Ip_DmaContinueTransfer(uint8 Instance);
#if (SPI_IP_ENABLE_DMAFASTTRANSFER_SUPPORT == STD_ON)
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

static void Spi_Ip_ReadRxFifo
(
    uint16 NumberOfReads,
    uint8 Instance
);
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
static void Spi_Ip_WriteCmdFifo
(
    uint16 NumberOfWrites,
    uint8 Instance
);

static void Spi_Ip_UpdateTxRxCounter
(
    uint8 Instance, 
    uint16 Length
);

#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)  
static void Spi_Ip_CheckValidParameters
(
    const Spi_Ip_ExternalDeviceType *ExternalDevice,
    uint16 Length
);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
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
    uint16 NumberOfWrites;
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
            if(NumberOfReads != 0u)
            {
                /* Read data from RX FIFO */
                Spi_Ip_ReceiveData(NumberOfReads, Instance);
            }
            
#if (SPI_IP_SLAVE_SUPPORT == STD_ON)
            if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
#endif
            {
                /* Cmd must be pushed before data, push Cmd until HW cmd fifo is full */
                NumberOfWrites = (uint16)((Base->SREX) & SPI_SREX_CMDCTR_MASK) >> SPI_SREX_CMDCTR_SHIFT;
                NumberOfWrites = SPI_IP_FIFO_SIZE_U16 - NumberOfWrites;
                /* Write to CMD FIFO */
                if ((NumberOfWrites != 0u) && (State->ExpectedCmdFifoWrites != 0u))
                {
                    Spi_Ip_WriteCmdFifo(NumberOfWrites, Instance);
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
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
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
    DmaTcdList[1u].Value = (uint32)&Base->PUSHR.FIFO.CMD;    /* dest address write*/
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
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
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
    
    DmaTcdList[1u].Value = (uint32)&Base->PUSHR.FIFO.TX;    /* dest address write*/ 
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
        DmaTcdList[0u].Value = (uint32)&State->PhyUnitConfig->CmdDmaFast[TCDSGIndex].DefaultData; /* src address read */
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
        DmaTcdList[0u].Value = (uint32)State->TxBuffer; /* src address read */
    }
    /* Update software TX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->TxDmaChannel, State->PhyUnitConfig->TxDmaFastSGId[TCDSGIndex], DmaTcdList, 8u);
}

static void Spi_Ip_RxDmaTcdSGInit(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
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
    
    DmaTcdList[0u].Value = (uint32)&Base->POPR; /* src address read */
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
        DmaTcdList[0u].Value = (uint32)&Spi_Ip_u32DiscardData;    /* dest address write*/ 
        DmaTcdList[4u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        DmaTcdList[0u].Value = (uint32)State->RxBuffer;    /* dest address write*/ 
    }
    DmaTcdList[5u].Value = State->ExpectedFifoReads; /* iteration count */
    DmaTcdList[6u].Value = DisHwReq; /* disable hardware request when major loop complete */
    DmaTcdList[7u].Value = DisHwReq; /* Enable Major interrupt at the end of transfer sequence(meanning when DisHwReq = 1u) */

    /* Update software RX DMA TCD Scatter Gather */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(State->PhyUnitConfig->RxDmaChannel, State->PhyUnitConfig->RxDmaFastSGId[TCDSGIndex], DmaTcdList, 8u);
}

#endif

/**
* @brief   This function will configure TCD Scatter Gather for the CMD DMA channel
*/
static void Spi_Ip_CmdDmaTcdSGConfig(   uint8 Instance, 
                                        uint8 TCDSGId, 
                                        uint32 CmdAdd,
                                        uint16 Iter, 
                                        uint8 DisHwReq
                                    )
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
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

/**
* @brief   This function will configure hardware TCDs for the channels TX DMA, RX DMA and CMD DMA 
*          according to current transfer configuration. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Spi_Ip_DmaConfig(uint8 Instance)
{
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[11u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites;
    uint16 NumberDmaIterRead = 0u;
    uint16 NumberCmdDmaIterWrite = 0u;
    boolean ClearCS = (boolean)FALSE;
    boolean EnScatterGather = (boolean)FALSE;
    
    /* Update last command */
    State->PushrCmdLast = State->PushrCmd & (~((uint16)(SPI_PUSHR_CONT_MASK>>16u)));
    
    /* Limits number of major count */
    if(SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        if((boolean)FALSE == State->KeepCs)
        {
            ClearCS = (boolean)TRUE;
        }
    }
    
    NumberDmaIterRead = NumberDmaIterWrite;
    if(State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        /* TX DMA can read 4 bytes from POPR for each request, so the number of RX DMA iter will be a half */
        NumberDmaIterRead = NumberDmaIterWrite/2u;
        /* check to make sure number of frames written should equal number of frame read, 
        avoid the case of data is written without command available in CMD FIFO.
        NumberDmaIterWrite may not be multiple of 2 due to it was assigned to SPI_IP_DMA_MAX_ITER_CNT_U16
        or by user in Spi_Ip_AsyncTransmit */
        if(0u != (NumberDmaIterWrite%2u))
        {
            NumberDmaIterWrite = NumberDmaIterRead;
        }
    }
    /* Update buffers index */
    State->TxIndex = NumberDmaIterWrite;
    State->RxIndex = NumberDmaIterRead;
    
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {
        /* configure CMD DMA channel */
        NumberCmdDmaIterWrite = NumberDmaIterRead;
        /* Update number of remain commands */
        State->ExpectedCmdFifoWrites -= NumberCmdDmaIterWrite;
        DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTcdList[1u].Value = (uint32)&State->PushrCmd;    /* default source address */
        if((boolean)TRUE == ClearCS)
        {
            if(1u == NumberCmdDmaIterWrite)
            {
                DmaTcdList[1u].Value = (uint32)&State->PushrCmdLast;    /* Clear CS command is source address */
                EnScatterGather = (boolean)FALSE;
            }
            else
            {
                NumberCmdDmaIterWrite = NumberDmaIterRead - 1u;
                EnScatterGather = (boolean)TRUE;
            }
        }
        else
        {
            EnScatterGather = (boolean)FALSE;
        }
        DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTcdList[0u].Value = NumberCmdDmaIterWrite;    /* iteration count */
        if((boolean)TRUE == EnScatterGather)
        {
            /* Update software TCD Scatter Gather 0 */
            Spi_Ip_CmdDmaTcdSGConfig(Instance, /* Cmd Dma Channel Id */
                                     State->PhyUnitConfig->TxCmdDmaSGId[0u], /* TCD Scatter Gather Id */
                                     DmaTcdList[1u].Value, /* src address read */
                                     (uint16)DmaTcdList[0u].Value, /* iteration count */
                                     0u /* Not disable hardware request when major loop complete */
                                    );
            /* Load software TCD Scatter Gather 0 into hardware TCD with ESG bit already set in software TCD */
            (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[0u]);
            /* Config next TCD Scatter Gather will clear CS */
            Spi_Ip_CmdDmaTcdSGConfig(Instance,
                                     State->PhyUnitConfig->TxCmdDmaSGId[1u], /* TCD Scatter Gather Id */
                                     (uint32)&State->PushrCmdLast, /* src address read */
                                     1u, /* iteration count is 1 for last push command */
                                     1u /* disable hardware request when major loop complete */
                                    );
        }
        else
        {
            DmaTcdList[2u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
            DmaTcdList[2u].Value = 1u;    /* disable hardware request when major loop complete */
            DmaTcdList[3u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
            DmaTcdList[3u].Value = 0u;    /* No adjust DADD when major loop completed */
            /* Update TCD for CMD DMA channel, ESG bit will be clear in this function */
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxCmdDmaChannel, DmaTcdList, 4u);
        }
    }

    /* configure TX DMA channel */
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
    
    DmaTcdList[1u].Value = (uint32)&Base->PUSHR.FIFO.TX;    /* dest address write*/ 
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
    DmaTcdList[7u].Value = NumberDmaIterWrite; /* iteration count */
    DmaTcdList[8u].Value = 1u; /* disable hardware request when major loop complete */
    DmaTcdList[9u].Value = 0u;  /* no src address modulo */
    if(NULL_PTR == State->TxBuffer)
    {
        /* send default data */
        DmaTcdList[0u].Value = (uint32)&State->ExternalDevice->DeviceParams->DefaultData; /* src address read */
        if(State->ExternalDevice->DeviceParams->FrameSize < 17u)
        {
            DmaTcdList[2u].Value = 0u;  /* src offset is 0 byte */
        }
        else
        {
            DmaTcdList[9u].Value = 2u;  /* data is 4 bytes, src address modulo is 2 bits */
        }
    }
    else
    {
        DmaTcdList[0u].Value = (uint32)State->TxBuffer; /* src address read */
    }
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[10u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    DmaTcdList[10u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for TX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 11u);
    
    /* configure RX DMA channel */
    DmaTcdList[0u].Value = (uint32)&Base->POPR; /* src address read */
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
        DmaTcdList[1u].Value = (uint32)&Spi_Ip_u32DiscardData;    /* dest address write*/ 
        DmaTcdList[6u].Value = 0u; /* dest offset is 0 bytes */
    }
    else
    {
        DmaTcdList[1u].Value = (uint32)State->RxBuffer;    /* dest address write*/ 
    }
    DmaTcdList[7u].Value = NumberDmaIterRead; /* iteration count */
    DmaTcdList[8u].Value = 1u; /* disable hardware request when major loop complete */
    /* Set DESTINATION_SIGNED_LAST_ADDR_ADJ = 0 to avoid the case it still stored from previous TCD Scatter Gather */
    DmaTcdList[9u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    DmaTcdList[9u].Value = 0u;    /* No adjust DADD when major loop completed */
    /* write TCD for RX DMA channel */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 10u);
    
    /* Enable HW request for RX DMA channel before TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {
        (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxCmdDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}

/**
* @brief   Update hardware TCD for DMA channels to continue transfer remain data frames. 
* @details In the case number of data frames are greater than SPI_IP_DMA_MAX_ITER_CNT_U16, this function will update hardware TCD for DMA channels
*          to continue transfer remain data frames. DMA channels will be started at the end of the function.
*
* @param[in]     Instance      Index of the hardware instance.
* @return void
*/
static void Spi_Ip_DmaContinueTransfer(uint8 Instance)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    Dma_Ip_LogicChannelTransferListType DmaTcdList[2u];
    uint16 NumberDmaIterWrite = State->ExpectedFifoWrites - State->TxIndex;
    uint16 NumberCmdDmaIterWrite = 0u;
    uint16 NumberDmaIterRead = 0u;
    boolean ClearCS = (boolean)FALSE;
    boolean EnScatterGather = (boolean)FALSE;
    
    /* Limits number of major count */
    if(SPI_IP_DMA_MAX_ITER_CNT_U16 < NumberDmaIterWrite)
    {
        NumberDmaIterWrite = SPI_IP_DMA_MAX_ITER_CNT_U16;
    }
    else
    {
        if((boolean)FALSE == State->KeepCs)
        {
            ClearCS = (boolean)TRUE;
        }
    }
    
    NumberDmaIterRead = NumberDmaIterWrite;
    if(State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        /* TX DMA can read 4 bytes from POPR for each request, so the number of RX DMA iter will be a haft */
        NumberDmaIterRead = NumberDmaIterWrite/2u;
        /* check to make sure number of frames written should equal number of frame read, 
        avoid the case of data is written without command available in CMD FIFO.
        NumberDmaIterWrite may not be multiple of 2 due to it was assigned to SPI_IP_DMA_MAX_ITER_CNT_U16
        or by user in Spi_Ip_AsyncTransmit */
        if(0u != (NumberDmaIterWrite%2u))
        {
            NumberDmaIterWrite = NumberDmaIterRead;
        }
    }
    
    State->TxIndex += NumberDmaIterWrite;
    State->RxIndex += NumberDmaIterRead;
    
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {
        /* Update CMD DMA channel */
        NumberCmdDmaIterWrite = NumberDmaIterRead;
        /* Update number of remain commands */
        State->ExpectedCmdFifoWrites -= NumberCmdDmaIterWrite;
        DmaTcdList[1u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        DmaTcdList[1u].Value = (uint32)&State->PushrCmd;    /* default source address */
        if((boolean)TRUE == ClearCS)
        {
            if(1u == NumberCmdDmaIterWrite)
            {
                DmaTcdList[1u].Value = (uint32)&State->PushrCmdLast;    /* Clear CS command is source address */
                EnScatterGather = (boolean)FALSE;
            }
            else
            {
                NumberCmdDmaIterWrite = NumberDmaIterRead - 1u;
                EnScatterGather = (boolean)TRUE;
            }
        }
        else
        {
            EnScatterGather = (boolean)FALSE;
        }
        DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        DmaTcdList[0u].Value = NumberCmdDmaIterWrite;    /* iteration count */
        if((boolean)TRUE == EnScatterGather)
        {
            /* Update software TCD Scatter Gather 0 */
            Spi_Ip_CmdDmaTcdSGConfig(Instance, /* Cmd Dma Channel Id */
                                     State->PhyUnitConfig->TxCmdDmaSGId[0u], /* TCD Scatter Gather Id */
                                     DmaTcdList[1u].Value, /* src address read */
                                     (uint16)DmaTcdList[0u].Value, /* iteration count */
                                     0u /* Not disable hardware request when major loop complete */
                                    );
            /* Load software TCD Scatter Gather 0 into hardware TCD with ESG bit already set in software TCD */
            (void)Dma_Ip_SetLogicChannelScatterGatherConfig(State->PhyUnitConfig->TxCmdDmaChannel, State->PhyUnitConfig->TxCmdDmaSGId[0u]);
            /* Config next TCD Scatter Gather will clear CS */
            Spi_Ip_CmdDmaTcdSGConfig(Instance,
                                     State->PhyUnitConfig->TxCmdDmaSGId[1u], /* TCD Scatter Gather Id */
                                     (uint32)&State->PushrCmdLast, /* src address read */
                                     1u, /* iteration count is 1 for last push command */
                                     1u /* disable hardware request when major loop complete */
                                    );
        }
        else
        {
            /* Update TCD for CMD DMA channel, ESG bit will be clear in this function */
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxCmdDmaChannel, DmaTcdList, 2u);
        }
    }

    /* Update TX DMA channel */
    DmaTcdList[0u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTcdList[0u].Value = NumberDmaIterWrite;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->TxDmaChannel, DmaTcdList, 1u);
    
    /* Update RX DMA channel */
    DmaTcdList[0u].Value = NumberDmaIterRead;    /* iteration count */
    (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
    
    /* Enable HW request for RX DMA channel before TX DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->RxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
    #endif
    {
        (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxCmdDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }
    (void)Dma_Ip_SetLogicChannelCommand(State->PhyUnitConfig->TxDmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
}
#endif /*#if (SPI_IP_DMA_USED == STD_ON)*/

/**
* @brief   This function will read data from RX FIFO. 
* @details This function will read data from RX FIFO.
*
* @param[in]     NumberOfReads   Number of bytes data will be read from RX FIFO .
* @param[in]     Instance       Index of the hardware instance.
* @return none
*/
static void Spi_Ip_ReadRxFifo
(
    uint16 NumberOfReads,
    uint8 Instance
)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    const SPI_Type* Base = Spi_Ip_apxBases[Instance];
    uint16 Count;
    uint32 Data;
    
    for (Count=0; Count < NumberOfReads; Count++)
    {
        Data = Base->POPR;
        if(NULL_PTR != State->RxBuffer)
        {
            if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
            {
                *((uint8*)(&State->RxBuffer[State->RxIndex])) = (uint8)Data;
            }
            else if (State->ExternalDevice->DeviceParams->FrameSize < 17u)
            {
                *((uint16*)(&State->RxBuffer[2u * State->RxIndex])) = (uint16)Data;
            }
            else
            {
                *((uint32*)(&State->RxBuffer[4u * State->RxIndex])) = Data;
            }
        }
        State->RxIndex++;
    }
}

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
    uint16 Count;
    uint16 Data = 0u;
    
    for (Count=0; Count < NumberOfWrites; Count++)
    {
        if(NULL_PTR != State->TxBuffer)
        {
            if(State->ExternalDevice->DeviceParams->FrameSize < 9u)
            {
                Data = *((const uint8*)(&State->TxBuffer[State->TxIndex]));
            }
            else
            {
                Data = *((const uint16*)(&State->TxBuffer[2u * State->TxIndex]));
            }
        }
        else
        {
            if(State->ExternalDevice->DeviceParams->FrameSize > 16u)
            {
                if ((uint16)0u == (State->TxIndex%2u))
                {
                    Data = (uint16)State->ExternalDevice->DeviceParams->DefaultData;  /* get 2 bytes */ 
                }  
                else   
                {
                    Data = (uint16)(State->ExternalDevice->DeviceParams->DefaultData >> 16u);  /* get 2 bytes */ 
                }                    
            }
            else
            {
                Data = (uint16)State->ExternalDevice->DeviceParams->DefaultData;
            }
        }
        State->TxIndex++;
        Base->PUSHR.FIFO.TX = (uint16)Data;
    }
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
    uint16 ActualNumberOfReads = NumberOfReads;
    /* Limits to remaining frames. */
    if (ActualNumberOfReads > (State->ExpectedFifoReads - State->RxIndex))
    {
        ActualNumberOfReads = State->ExpectedFifoReads - State->RxIndex;
    }
    /* Read data from RX FIFO */
    Spi_Ip_ReadRxFifo(ActualNumberOfReads, Instance);
    /* Update current TX FIFO slot */
    if (State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        State->CurrentTxFifoSlot += NumberOfReads*2u;
    }
    else
    {
        State->CurrentTxFifoSlot += NumberOfReads;
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
* @brief   This function will write command to CMD FIFO. 
* @details This function will write command to CMD FIFO.
*
* @param[in]     NumberOfWrites   Number of time the command will be writen to CMD FIFO .
* @param[in]     Instance         Index of the hardware instance.
* @return none
*/
static void Spi_Ip_WriteCmdFifo
(
    uint16 NumberOfWrites,
    uint8 Instance
)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    SPI_Type* Base = Spi_Ip_apxBases[Instance];
    uint16 Count;
    uint16 ActualNumberOfWrites = NumberOfWrites; 
    
    if (ActualNumberOfWrites > State->ExpectedCmdFifoWrites)
    {
        ActualNumberOfWrites = State->ExpectedCmdFifoWrites;
    }
    for (Count=0; Count < ActualNumberOfWrites; Count++)
    {
        if((1u == State->ExpectedCmdFifoWrites) && ((boolean)FALSE == State->KeepCs))
        {
            Base->PUSHR.FIFO.CMD = State->PushrCmd & (~((uint16)(SPI_PUSHR_CONT_MASK>>16u)));
        }
        else
        {
            Base->PUSHR.FIFO.CMD = State->PushrCmd;
        }
        State->ExpectedCmdFifoWrites--;
    }
}

/**
* @brief   This function calculates actual TX/RX counter depends on FrameSize. 
* @details This function calculates actual TX/RX counter depends on FrameSize.
*
* @param[in]     Instance         Index of the hardware instance.
* @param[in]     Length           Number of bytes transfer.
* @return none
*/
static void Spi_Ip_UpdateTxRxCounter(uint8 Instance, uint16 Length)
{
    Spi_Ip_StateStructureType* State = Spi_Ip_apxStateStructureArray[Instance];
    
    if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
    {
        State->ExpectedFifoWrites = Length;
    }
    else
    {
        State->ExpectedFifoWrites = Length/2u;
    }
    State->ExpectedFifoReads = State->ExpectedFifoWrites;
    if (State->ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        State->ExpectedFifoReads = State->ExpectedFifoWrites/2u;
    }
    State->ExpectedCmdFifoWrites = State->ExpectedFifoReads;
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
static void Spi_Ip_CheckValidParameters(
                                                    const Spi_Ip_ExternalDeviceType *ExternalDevice,
                                                    uint16 Length
                                              )
{

    if (ExternalDevice->DeviceParams->FrameSize > 16u)
    {
        DevAssert((Length%4) == 0u);
    }
    else if (ExternalDevice->DeviceParams->FrameSize > 8u)
    {
        DevAssert((Length%2) == 0u);
    }
    else
    {
        /* do nothing */
    }
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
    
    if(NULL_PTR != State)
    {
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
                if (State->ExpectedFifoReads != State->RxIndex)
                {
                    /* Transfer is not finished => update TX, RX pointers */
                    Spi_Ip_DmaContinueTransfer(Instance);
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

/*================================================================================================*/
Spi_Ip_StatusType Spi_Ip_SyncTransmit(
                                      const Spi_Ip_ExternalDeviceType *ExternalDevice,
                                      const uint8 *TxBuffer,
                                      uint8 *RxBuffer,
                                      uint16 Length,
                                      uint32 TimeOut
                                     )
{
    SPI_Type *Base;
    Spi_Ip_StateStructureType *State;
    uint16 NumberOfReads;
    uint16 NumberOfWrites;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(TimeOut, SPI_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */
    uint8 Instance = 0u;
    uint16 PushrCmd = 0u;
    uint32 LsbValue = 0u;
    
    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    DevAssert(0u != TimeOut);
    Spi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif

    PushrCmd = ExternalDevice->PushrCmd; 
    Base = Spi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_08();
    if (State->Status == SPI_IP_BUSY)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();
        Status = SPI_IP_STATUS_FAIL;
    }
    else
    {
        State->ExternalDevice = ExternalDevice;        
        /* Get Lsb value */
        LsbValue = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
        /* Update State structure and internal variables used for timeout */
        State->Status = SPI_IP_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_08();

        /* Make sure that FIFOs will be empty before start new transfer session */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        /* Reset Flags */
        Base->SR = 0xFFFF0000u;
        
        State->PushrCmd = ExternalDevice->PushrCmd;
        State->RxIndex = 0u;
        State->TxIndex = 0u;
        State->TxBuffer = TxBuffer;
        State->RxBuffer = RxBuffer;
        
        Spi_Ip_UpdateTxRxCounter(Instance, Length);
        /* To increase the performance, Some frames can be transferred using 1 CMD. Support maximum SPI_IP_CTARE_DTCP_MAX_U16 frames. */
        /* Due to CS signal always de-assert at the beginning of next channel (after move driver to stop mode by set HALT bit) so this mode only support in IP layer
           or Job has only 1 channel */
        if ((State->ExpectedCmdFifoWrites <= SPI_IP_CTARE_DTCP_MAX_U16) && (State->ExpectedCmdFifoWrites > 1u) && (FALSE == State->KeepCs))
        {
            State->CtareDtcpSupport = TRUE;
        }
        else
        {
            State->CtareDtcpSupport = FALSE;
        }
        
        /* Configure external device parameters  like: cs, clock phase, clock polarity. */
        #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
        Base->MODE.CTAR[0u] = ExternalDevice->Ctar[State->ClockMode] | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
        #else
        Base->MODE.CTAR[0u] = ExternalDevice->Ctar | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
        #endif
        if (State->CtareDtcpSupport)
        {
            /* Use CTAR0/CTARE0 to transfer all (frames - 1) */
            Base->CTARE[0u] = SPI_CTARE_FMSZE((((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) >> 4u) & 0x1u) | SPI_CTARE_DTCP((uint32)State->ExpectedCmdFifoWrites - 1u);
            Base->PUSHR.FIFO.CMD = (PushrCmd | (uint16)(SPI_PUSHR_CTAS(0U)>>16u));
            /* Use CTAR1/CTARE1 to transfer latest frame to clear CONT bit */
            Base->CTARE[1u] = SPI_CTARE_FMSZE((((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) >> 4u) & 0x1u) | SPI_CTARE_DTCP(1u);
            Base->PUSHR.FIFO.CMD = (PushrCmd | (uint16)(SPI_PUSHR_CTAS(1U)>>16u)) & (~((uint16)(SPI_PUSHR_CONT_MASK>>16u)));  
            /* Configure external device parameters  like: cs, clock phase, clock polarity. */
            #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
                Base->MODE.CTAR[1u] = ExternalDevice->Ctar[State->ClockMode] | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
            #else
                Base->MODE.CTAR[1u] = ExternalDevice->Ctar | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
            #endif
        }
        else
        {
            Base->CTARE[0u] = ExternalDevice->Ctare | SPI_CTARE_FMSZE((((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) >> 4u) & 0x1u);
        }
        
        CurrentTicks = OsIf_GetCounter(SPI_IP_TIMEOUT_METHOD); /* initialize current counter */        
		
        /* Get current FIFO slots are available.*/
        State->CurrentTxFifoSlot = SPI_IP_FIFO_SIZE_U16;
        while(SPI_IP_STATUS_SUCCESS == Status)
        {
            /* SEND CMD */
            /* if number of frames <= SPI_IP_CTARE_DTCP_MAX_U16 and this is latest channel. All frames will be transferred using only 1 CMD which has push to TX CMD above */
            if (FALSE == State->CtareDtcpSupport)
            {
                /* Cmd must be pushed before data, push Cmd until HW cmd fifo is full */
                NumberOfWrites = (uint16)((Base->SREX) & SPI_SREX_CMDCTR_MASK) >> SPI_SREX_CMDCTR_SHIFT;
                NumberOfWrites = SPI_IP_FIFO_SIZE_U16 - NumberOfWrites;
                /* Write to CMD FIFO */
                if ((NumberOfWrites != 0u) && (State->ExpectedCmdFifoWrites != 0u))
                {
                    Spi_Ip_WriteCmdFifo(NumberOfWrites, Instance);
                    ElapsedTicks = 0;
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
                ElapsedTicks = 0;
				/* Clear Halt bit, then transfer */
				if(((Base->MCR) & SPI_MCR_HALT_MASK) == SPI_MCR_HALT_MASK)
				{
					Base->MCR &= ~SPI_MCR_HALT_MASK;
				}
            }          
            /* RECEIVE */
            /* Read all data available in receive HW fifo. */
            NumberOfReads = (uint16)(((Base->SR) & SPI_SR_RXCTR_MASK) >> SPI_SR_RXCTR_SHIFT);
            if(NumberOfReads != 0u)
            {
                /* Read data from RX FIFO */
                Spi_Ip_ReceiveData(NumberOfReads, Instance);
                /* Finish the transfer if all frames have received */
                if (State->RxIndex == State->ExpectedFifoReads)
                {
                    break;
                }
                 ElapsedTicks = 0;
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

Spi_Ip_StatusType Spi_Ip_AsyncTransmit(
                                       const Spi_Ip_ExternalDeviceType *ExternalDevice,
                                       const uint8 *TxBuffer,
                                       uint8 *RxBuffer,
                                       uint16 Length,
                                       Spi_Ip_CallbackType EndCallback
                                      )
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint32 LsbValue;
    uint8 Instance;
    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
    uint16 NumberOfWrites = 0u;
    #endif
    uint16 NumberOfCmdWrites = 0u;
    #if (SPI_IP_DMA_USED == STD_ON)
    Dma_Ip_LogicChannelTransferListType DmaTcdList[1u];
    #endif

    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    DevAssert(ExternalDevice != NULL_PTR);
    DevAssert(0u != Length);
    Spi_Ip_CheckValidParameters(ExternalDevice, Length);
    #endif
    Instance = ExternalDevice->Instance;
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (STD_ON == SPI_IP_DEV_ERROR_DETECT)
    DevAssert(State != NULL_PTR);
    #endif
    
    Base = Spi_Ip_apxBases[Instance];
    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_09();
    if (SPI_IP_BUSY == State->Status)
    {
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
        Status = SPI_IP_STATUS_FAIL;
    }
    else
    {
        State->ExternalDevice = ExternalDevice;
        /* Get Lsb value */
        LsbValue = State->ExternalDevice->DeviceParams->Lsb ? 1UL : 0UL;
        /* Mark the hardware as busy. */
        State->Status = SPI_IP_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_09();
    
        /* Update State structure. */
        State->RxIndex = 0u;
        State->TxIndex = 0u;
        State->TxBuffer = TxBuffer;
        State->RxBuffer = RxBuffer;
        State->Callback = EndCallback;
        if (State->ExternalDevice->DeviceParams->FrameSize < 9u)
        {
            State->ExpectedFifoWrites = Length;
        }
        else
        {
            State->ExpectedFifoWrites = Length/2u;
        }

        State->ExpectedFifoReads = State->ExpectedFifoWrites;
        if (State->ExternalDevice->DeviceParams->FrameSize >16u)
        {
            State->ExpectedFifoReads = State->ExpectedFifoWrites/2u;
        }
        State->ExpectedCmdFifoWrites = State->ExpectedFifoReads;
        State->PushrCmd = ExternalDevice->PushrCmd;
        /* Get current FIFO slots are available.*/
        State->CurrentTxFifoSlot = SPI_IP_FIFO_SIZE_U16;
        /* Make sure that FIFOs will be empty before start new transfer session */
        Base->MCR |= SPI_MCR_CLR_TXF_MASK | SPI_MCR_CLR_RXF_MASK;
        /* Clear all flags. */
        Base->SR &= 0xFFFF0000u;
        /* Configure external device parameters  like: cs, clock phase, clock polarity. */
        #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
        if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
        #endif
        {
            #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
                Base->MODE.CTAR[0u] = ExternalDevice->Ctar[State->ClockMode] | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
            #else
                Base->MODE.CTAR[0u] = ExternalDevice->Ctar | SPI_CTAR_FMSZ(((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) & 0xFu) | SPI_CTAR_LSBFE(LsbValue);
            #endif
            Base->CTARE[0u] = ExternalDevice->Ctare | SPI_CTARE_FMSZE((((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u) >> 4u) & 0x1u);
        }
        #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
        else
        {
            #if (SPI_IP_DUAL_CLOCK_MODE == STD_ON)
                Base->MODE.CTAR[0u] = (ExternalDevice->Ctar[State->ClockMode] & (~SPI_CTAR_SLAVE_FMSZ_MASK)) | SPI_CTAR_SLAVE_FMSZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u);
            #else
                Base->MODE.CTAR[0u] = (ExternalDevice->Ctar & (~SPI_CTAR_SLAVE_FMSZ_MASK)) | SPI_CTAR_SLAVE_FMSZ((uint32)State->ExternalDevice->DeviceParams->FrameSize - 1u);
            #endif
        }
        #endif
    
        #if (SPI_IP_DMA_USED == STD_ON) 
        if((boolean)FALSE == State->PhyUnitConfig->DmaUsed)
        #endif
        {
            switch(State->TransferMode)
            {
                case SPI_IP_POLLING:
                    /* Disable interrupts and DMA requests. */
                    Base->RSER = 0U;
                    break;
                case SPI_IP_INTERRUPT:
                    /* Enable interrupts. */
                    Base->RSER = SPI_RSER_TCF_RE(1) | SPI_RSER_TFUF_RE(1) | SPI_RSER_RFOF_RE(1);
                    /* Fill data into TX FIFO to trigger TCF interrupt */
                    /* Write to CMD field first*/
                    #if (SPI_IP_SLAVE_SUPPORT == STD_ON)
                    if((boolean)FALSE == State->PhyUnitConfig->SlaveMode)
                    #endif
                    {                        
                        /* Cmd must be pushed before data, push Cmd until HW cmd fifo is full */
                        NumberOfCmdWrites = (uint16)((Base->SREX) & SPI_SREX_CMDCTR_MASK) >> SPI_SREX_CMDCTR_SHIFT;
                        NumberOfCmdWrites = SPI_IP_FIFO_SIZE_U16 - NumberOfCmdWrites;
                        /* Write to CMD FIFO */
                        if ((NumberOfCmdWrites != 0u) && (State->ExpectedCmdFifoWrites != 0u))
                        {
                            Spi_Ip_WriteCmdFifo(NumberOfCmdWrites, Instance);
                        }
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
                        if (NumberOfWrites > (State->ExpectedFifoWrites - State->TxIndex))
                        {
                            NumberOfWrites = State->ExpectedFifoWrites - State->TxIndex;
                        }
                        /* Write to TXFIFO*/
                        Spi_Ip_WriteTxFifo(NumberOfWrites, Instance);
                        /* Update current TX FIFO available */
                        State->CurrentTxFifoSlot -= NumberOfWrites;
                    }
                    #endif
                    break;
                default:
                    /* Should be non-empty to avoid misra 16.4 */
                    break;
            }
        }
        #if (SPI_IP_DMA_USED == STD_ON)
        else
        {
            /* Activate RX DMA interrupt in interrupt mode or disable then in polling mode. */
            DmaTcdList[0u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
            switch(State->TransferMode)
            {
                case SPI_IP_POLLING:
                    /* Disable DMA major interrupt. */
                    DmaTcdList[0u].Value = 0u;
                    break;
                case SPI_IP_INTERRUPT:
                    /* Enable DMA major interrupt. */
                    DmaTcdList[0u].Value = 1u;
                    break;
                default:
                    /* Should be non-empty to avoid misra 16.4 */
                    break;
            }
            (void)Dma_Ip_SetLogicChannelTransferList(State->PhyUnitConfig->RxDmaChannel, DmaTcdList, 1u);
            /* Config and Enable DMA request. */
			Spi_Ip_DmaConfig(Instance);
            Base->RSER = SPI_RSER_CMDFFF_RE(1) | SPI_RSER_CMDFFF_DIRS(1) | SPI_RSER_TFFF_RE(1) | SPI_RSER_TFFF_DIRS(1) | SPI_RSER_RFDF_RE(1) | SPI_RSER_RFDF_DIRS(1);
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
Spi_Ip_StatusType Spi_Ip_AsyncTransmitFast(
                                       const Spi_Ip_FastTransferType *FastTransferCfg,
                                       uint8 NumberOfTransfer,
                                       Spi_Ip_CallbackType EndCallback
                                      )
{
    SPI_Type* Base;
    Spi_Ip_StateStructureType* State;
    Spi_Ip_StatusType Status = SPI_IP_STATUS_SUCCESS;
    uint8 Instance = 0u;
    uint32 LsbValue = 0u;
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    uint8 Count = 0u;
    #endif

#if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != FastTransferCfg);
    DevAssert(NULL_PTR != FastTransferCfg[0u].ExternalDevice);
#endif
    Instance = FastTransferCfg[0u].ExternalDevice->Instance;
    Base = Spi_Ip_apxBases[Instance];
    State = Spi_Ip_apxStateStructureArray[Instance];
    #if (SPI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(NULL_PTR != State);
    DevAssert(State->TransferMode == SPI_IP_INTERRUPT);
    DevAssert(NumberOfTransfer <= State->PhyUnitConfig->MaxNumOfFastTransfer);

    for(Count = 0u; Count < NumberOfTransfer; Count++)
    {
        DevAssert(NULL_PTR != FastTransferCfg[Count].ExternalDevice);
        DevAssert(0u != FastTransferCfg[Count].Length);
        if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 16u)
        {
            DevAssert((FastTransferCfg[Count].Length%4) == 0u);
        }
        else if (FastTransferCfg[0u].ExternalDevice->DeviceParams->FrameSize > 8u)
        {
            DevAssert((FastTransferCfg[Count].Length%2) == 0u);
        }
        else
        {
            DevAssert(SPI_IP_DMA_MAX_ITER_CNT_U16 >= FastTransferCfg[Count].Length);
        }
    }
    #endif
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
        State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmdLast = FastTransferCfg[Count].ExternalDevice->PushrCmd & (~((uint16)(SPI_PUSHR_CONT_MASK>>16u)));
        
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
                                            (uint32)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmd,
                                            State->ExpectedCmdFifoWrites - 1u, 
                                            0u  /* not disable dma hw request, the transfer will be continued after next software TCD Scatter Gather loaded */
                                        );
                CmdTCDSGIndex++;
            }
            Spi_Ip_CmdDmaTcdSGConfig(   Instance, 
                                        State->PhyUnitConfig->TxCmdDmaSGId[CmdTCDSGIndex], 
                                        (uint32)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmdLast,
                                        1u, /* transfer last command to clear CS */
                                        DisHwRequest
                                    );
            CmdTCDSGIndex++;
        }
        else
        {
            Spi_Ip_CmdDmaTcdSGConfig(   Instance, 
                                        State->PhyUnitConfig->TxCmdDmaSGId[CmdTCDSGIndex], 
                                        (uint32)&State->PhyUnitConfig->CmdDmaFast[Count].DmaFastPushrCmd,
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
