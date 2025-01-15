/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Psi5_S_Ip.c
*
*   @addtogroup PSI5_S_IP PSI5 IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Psi5_S_Ip.h"
#include "Psi5_S_Ip_Cfg.h"

#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
#include "Dma_Ip.h"
#endif

#ifdef PSI5_S_IP_DEV_ERROR_DETECT
#if (STD_ON == PSI5_S_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_S_IP_VENDOR_ID_C                        43
#define PSI5_S_IP_AR_RELEASE_MAJOR_VERSION_C         4
#define PSI5_S_IP_AR_RELEASE_MINOR_VERSION_C         7
#define PSI5_S_IP_AR_RELEASE_REVISION_VERSION_C      0
#define PSI5_S_IP_SW_MAJOR_VERSION_C                 2
#define PSI5_S_IP_SW_MINOR_VERSION_C                 0
#define PSI5_S_IP_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PSI5_S_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Psi5_S_Ip.c and Mcal.h are different"
    #endif
#endif

/* Checks against Psi5_S_Ip.h */
#if (PSI5_S_IP_VENDOR_ID_C != PSI5_S_IP_VENDOR_ID)
    #error "Psi5_S_Ip.c and Psi5_S_Ip.h have different vendor ids"
#endif
#if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION_C    != PSI5_S_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_MINOR_VERSION_C    != PSI5_S_IP_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_REVISION_VERSION_C != PSI5_S_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip.c and Psi5_S_Ip.h are different"
#endif
#if ((PSI5_S_IP_SW_MAJOR_VERSION_C != PSI5_S_IP_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_SW_MINOR_VERSION_C != PSI5_S_IP_SW_MINOR_VERSION) || \
     (PSI5_S_IP_SW_PATCH_VERSION_C != PSI5_S_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip.c and Psi5_S_Ip.h are different"
#endif

/* Checks against Psi5_S_Ip_Cfg.h */
#if (PSI5_S_IP_VENDOR_ID_C != PSI5_S_IP_CFG_VENDOR_ID)
    #error "Psi5_S_Ip.c and Psi5_S_Ip_Cfg.h have different vendor ids"
#endif
#if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION_C    != PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_MINOR_VERSION_C    != PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_REVISION_VERSION_C != PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip.c and Psi5_S_Ip_Cfg.h are different"
#endif
#if ((PSI5_S_IP_SW_MAJOR_VERSION_C != PSI5_S_IP_CFG_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_SW_MINOR_VERSION_C != PSI5_S_IP_CFG_SW_MINOR_VERSION) || \
     (PSI5_S_IP_SW_PATCH_VERSION_C != PSI5_S_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip.c and Psi5_S_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef AXBS_IP_DEV_ERROR_DETECT
    #if (STD_ON == AXBS_IP_DEV_ERROR_DETECT)
        /* Check if the files Psi5_S_Ip.c and Devassert.h are of the same version */
        #if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (PSI5_S_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Psi5_S_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define PSI5_S_GET_EVENT(events, ev)      ((Psi5_S_Ip_EventType)((events) & ((uint32)ev)))
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/* Instance base addresses */
static const PSI5_S_MemMapPtr s_psi5BaseAddresses[PSI5_S_INSTANCE_COUNT] = IP_PSI5_S_BASE_PTRS;

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == PSI5_S_IP_MULTIPARTITION_SUPPORT)
#define PSI5_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"

VAR_SEC_NOCACHE(Psi5_S_UsedConfig) static Psi5_S_Ip_ConfigType const * Psi5_S_UsedConfig  = NULL_PTR;
VAR_SEC_NOCACHE(Psi5_S_DriverInitialized) static boolean Psi5_S_DriverInitialized = (boolean)FALSE;
VAR_SEC_NOCACHE(g_psi5_s_sram_mailbox) static uint32 g_psi5_s_sram_mailbox[PSI5_S_INSTANCE_COUNT][PSI5_S_CH_COUNT+1][6*3];

#define PSI5_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"
#else
#define PSI5_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

static Psi5_S_Ip_ConfigType const * Psi5_S_UsedConfig  = NULL_PTR;

#define PSI5_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

#define PSI5_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Psi5_MemMap.h"

static boolean Psi5_S_DriverInitialized = (boolean)FALSE;

#define PSI5_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Psi5_MemMap.h"

#define PSI5_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"

VAR_SEC_NOCACHE(g_psi5_s_sram_mailbox) static uint32 g_psi5_s_sram_mailbox[PSI5_S_INSTANCE_COUNT][PSI5_S_CH_COUNT+1][6*3];

#define PSI5_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"
#endif

#define PSI5_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"

#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
VAR_ALIGN(static Dma_Ip_SwTcdRegType STcd[4], 32U)
#endif

#define PSI5_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"

static Std_ReturnType Psi5_S_Hw_GetPsi5SFrame(const Psi5_S_Ip_InstanceIdType instanceId,
                                              const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                              Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static Std_ReturnType Psi5_S_Hw_GetPsi5SFrameCal(const Psi5_S_Ip_InstanceIdType instanceId,
                                              const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                              const uint32 frameID,
                                              Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static Std_ReturnType Psi5_S_Hw_GetPsi5SFrameSub(const Psi5_S_Ip_InstanceIdType instanceId,
                                                 const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                                 Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static void Psi5_S_Hw_ConvertRawPsi5SFrame(const uint32 * sram_mailbox,
                                          Psi5_S_Ip_Psi5SFrameType * rawFrame);
static void Psi5_S_Hw_ConfigureSlot(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                  const Psi5_S_Ip_SlotConfigType * slot);
static void Psi5_S_Hw_ConfigureSlotSub(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                  const Psi5_S_Ip_SlotConfigType * slot,
                                  const float32 minUARTbytes);
static void Psi5_S_Hw_EnterUartMode(const Psi5_S_Ip_InstanceIdType instanceId);
static void Psi5_S_Hw_EnterConfigMode(const Psi5_S_Ip_InstanceIdType instanceId);
static void Psi5_S_Hw_EnterNormalMode(const Psi5_S_Ip_InstanceIdType instanceId);
static void Psi5_S_Hw_ConfigureTx(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * chCfg);
static void Psi5_S_Hw_ConfigureRx(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * chCfg);
#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
static void Psi5_S_Hw_ConfigureDma(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                   const Psi5_S_Ip_DmaConfigType * dmaConfig);
#endif /* (STD_ON == PSI5_S_IP_DMA_IS_USED) */
static void Psi5_S_Hw_InstanceDisable(const Psi5_S_Ip_InstanceIdType instanceId);
static void Psi5_S_Hw_ResetRegisters(const Psi5_S_Ip_InstanceIdType instanceId);
static boolean Psi5_S_Hw_IsDataRegisterReady(const Psi5_S_Ip_InstanceIdType instanceId,
                                           const Psi5_S_Ip_HwChannelIdType Psi5SChannelId);
static boolean Psi5_S_Hw_IsDirectCommandRegisterReady(const Psi5_S_Ip_InstanceIdType instanceId);
static void Psi5_S_EnterUartMode(const Psi5_S_Ip_InstanceType * instance);
static void Psi5_S_EnterConfigMode(const Psi5_S_Ip_InstanceType * instance);
static void Psi5_S_EnterNormalMode(const Psi5_S_Ip_InstanceType * instance);
static void Psi5_S_ConfigureUartMode(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_UartConfigType * uartConfig);
static void Psi5_S_ConfigureUart(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_UartConfigType * uartConfig);
static void Psi5_S_ConfigureSlots(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * channelConfig);
static void Psi5_S_ConfigureChannel(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_ChannelConfigType * chCfg);
static void Psi5_S_ConfigureChannels(const Psi5_S_Ip_InstanceType * instance);
static void Psi5_S_Hw_GetTxEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                  Psi5_S_Ip_EventType *const Events);
static void Psi5_S_Hw_GetEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                Psi5_S_Ip_EventType *const Events);
static void Psi5_S_Hw_GetPsi5SFrameInt(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                    Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static void Psi5_S_Hw_GetPsi5SFrameIntSub(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                    Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static void Psi5_S_Hw_GetPsi5SEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);
static void Psi5_S_Hw_EnableGLInterrupts(const Psi5_S_Ip_InstanceIdType instanceId,
                                     const boolean Enable);
static void Psi5_S_Hw_EnableRxInterrupts(const Psi5_S_Ip_InstanceIdType instanceId,
                                     const Psi5_S_Ip_ChannelConfigType * chCfg,
                                     const boolean Enable);
static void Psi5_S_Hw_ClearEvents(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId);

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetTxEvents
 * Description   : Returns active Tx events
 *
 *END**************************************************************************/
static void Psi5_S_Hw_GetTxEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId, 
                                  Psi5_S_Ip_EventType *const Events)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5InstanceId];
    const uint8 arrayIndex = Psi5_S_UsedConfig->instancesConfig[Psi5InstanceId].chHwIdToIndexArrayConfig[Psi5SChannelId]; 
    const Psi5_S_Ip_ChannelConfigType * config = &(Psi5_S_UsedConfig->instancesConfig[Psi5InstanceId].channelConfig[arrayIndex]);
    if (config->txConfig != NULL_PTR)
    {
        /* Data prep overwrite */
        if (((base->CH[(uint8)(Psi5SChannelId-1u)].E2SSR & PSI5_S_E2SSR_CMDTR_NWRT_MASK) != 0u) && ((base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR & PSI5_S_E2SCR_CMDTR_NWRT_IE_MASK) != 0u))
        {
            Events->Psi5S_TxDataOverwrite = TRUE;
            /*disable interrupt*/
            base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR &= ~PSI5_S_E2SCR_CMDTR_NWRT_IE_MASK;
        }
        /* Data prep ready */
        if (((base->CH[(uint8)(Psi5SChannelId-1u)].E2SSR & PSI5_S_E2SSR_DDSR_RDY_MASK) != 0u) && ((base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR & PSI5_S_E2SCR_DDSR_RDY_IE_MASK) != 0u))
        {
            Events->Psi5S_ReadyToTransmit = TRUE;
            /*disable interrupt*/
            base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR &= ~PSI5_S_E2SCR_DDSR_RDY_IE_MASK;
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SFrameInt
 * Description   : Returns active PSI5 interrupt
 *
 *END**************************************************************************/
static void Psi5_S_Hw_GetPsi5SFrameInt(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                    Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr)
{
    Psi5_S_Ip_Psi5SFrameType rawFrame;
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5InstanceId];
    uint32 mBoxIRQ = 0u;
    uint32 frameID = 0u;
    uint32 channelID = (uint32)Psi5SChannelId;
    
    mBoxIRQ = base->MBOX_SR_IRQ;
    if (mBoxIRQ != 0u)
    {
        if (channelID == 0u)
        {
            /* MAILBOX0,LOC0 - MAILBOX0,LOC1 Check */
            if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F0_READ_MASK) != 0u)
            {
                frameID = 0u;
                /* Read MailBox message */
                Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[Psi5InstanceId][channelID][frameID], &rawFrame);
                Psi5SFramePtr->XCRC       = rawFrame.XCRC;
                Psi5SFramePtr->CRC        = rawFrame.CRC;
                Psi5SFramePtr->ERR        = rawFrame.ERR;
                Psi5SFramePtr->F_ERR      = rawFrame.F_ERR;
                Psi5SFramePtr->FID        = rawFrame.FID;
                Psi5SFramePtr->CHID       = rawFrame.CHID;
                Psi5SFramePtr->DCI1       = rawFrame.DCI1;
                Psi5SFramePtr->PS_DATA    = rawFrame.PS_DATA;
                Psi5SFramePtr->DCI2       = rawFrame.DCI2;
                Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
                Psi5SFramePtr->DCI3       = rawFrame.DCI3;
                Psi5SFramePtr->F_OV       = (uint8)(base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F0_OV_MASK);
                if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F0_ERR_MASK) != 0u)
                {
                    base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F0_ERR_MASK;
                }
                if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F0_OV_MASK) != 0u)
                {
                    base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F0_OV_MASK;
                }
                base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F0_READ_MASK;
            }
            if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_READ_MASK) != 0u)
            {
                frameID = 1u;
                /* Read MailBox message */
                Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[Psi5InstanceId][channelID][frameID*3u], &rawFrame);
                Psi5SFramePtr->XCRC       = rawFrame.XCRC;
                Psi5SFramePtr->CRC        = rawFrame.CRC;
                Psi5SFramePtr->ERR        = rawFrame.ERR;
                Psi5SFramePtr->F_ERR      = rawFrame.F_ERR;
                Psi5SFramePtr->FID        = rawFrame.FID;
                Psi5SFramePtr->CHID       = rawFrame.CHID;
                Psi5SFramePtr->DCI1       = rawFrame.DCI1;
                Psi5SFramePtr->PS_DATA    = rawFrame.PS_DATA;
                Psi5SFramePtr->DCI2       = rawFrame.DCI2;
                Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
                Psi5SFramePtr->DCI3       = rawFrame.DCI3;
                Psi5SFramePtr->F_OV       = (uint8)(base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_OV_MASK);
                if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_ERR_MASK) != 0u)
                {
                    base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F1_ERR_MASK;
                }
                if((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_OV_MASK) != 0u)
                {
                    base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F1_OV_MASK;
                }
                base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F1_READ_MASK;
            }
            /* Check all error in MRU buf2 */
            if ((base->ERR_SR_IRQ & 0x3ffu) != 0u) 
            {
                base->ERR_SR_IRQ &= 0x3ffu; /* clear error */
            }
        }
        else
        {
            Psi5_S_Hw_GetPsi5SFrameIntSub(Psi5InstanceId, Psi5SChannelId, Psi5SFramePtr);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SFrameIntSub
 * Description   : Returns active PSI5 interrupt
 *
 *END**************************************************************************/
static void Psi5_S_Hw_GetPsi5SFrameIntSub(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                    Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr)
{
    Psi5_S_Ip_Psi5SFrameType rawFrame;
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5InstanceId];
    uint32 mBoxSR = 0u;
    uint32 frameID = 0u;
    uint32 channelID = (uint32)Psi5SChannelId;
    Psi5_S_Ip_ChannelModeType channelMode;
    channelMode = (((base->CH[(uint8)(Psi5SChannelId - 1u)].MSGA & PSI5_S_MSGA_MODE_MASK) >> PSI5_S_MSGA_MODE_SHIFT) == 1u) ? PSI5_S_ASYNCHRONOUS : PSI5_S_SYNCHRONOUS;
    mBoxSR = base->CH[(uint8)(channelID-1u)].MBOX_SR;
    while (((mBoxSR >> (frameID * 3u)) & 0x7u) == 0u)
    {
        frameID++;
    }
    if ((frameID <= 5u) && ((((base->CH[(uint8)(channelID-1u)].MBOX_SR)>>(frameID*3u)) & PSI5_S_MBOX_SR_F0_READ_MASK) != 0u))
    {
        /* Read MailBox message */
        if (channelMode == PSI5_S_ASYNCHRONOUS)
        {
            Psi5_S_Hw_ConvertRawPsi5SFrame((uint32*)base->MRU_BUF2_REG0, &rawFrame);
            Psi5SFramePtr->XCRC       = rawFrame.XCRC;
            Psi5SFramePtr->CRC        = rawFrame.CRC;
            Psi5SFramePtr->ERR        = rawFrame.ERR;
            Psi5SFramePtr->F_ERR      = rawFrame.F_ERR;
            Psi5SFramePtr->FID        = rawFrame.FID;
            Psi5SFramePtr->CHID       = rawFrame.CHID;
            Psi5SFramePtr->DCI1       = rawFrame.DCI1;
            Psi5SFramePtr->PS_DATA    = rawFrame.PS_DATA;
            Psi5SFramePtr->DCI2       = rawFrame.DCI2;
            Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
            Psi5SFramePtr->DCI3       = rawFrame.DCI3;
            Psi5SFramePtr->F_OV       = (uint8)(((base->CH[(uint8)(channelID-1u)].MBOX_SR)>>(frameID*3u)) & (PSI5_S_MBOX_SR_F0_OV_MASK >> PSI5_S_MBOX_SR_F0_OV_SHIFT));
        }
        else
        {
            Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[Psi5InstanceId][channelID][frameID*3u], &rawFrame);
            Psi5SFramePtr->XCRC       = rawFrame.XCRC;
            Psi5SFramePtr->CRC        = rawFrame.CRC;
            Psi5SFramePtr->ERR        = rawFrame.ERR;
            Psi5SFramePtr->F_ERR      = rawFrame.F_ERR;
            Psi5SFramePtr->FID        = rawFrame.FID;
            Psi5SFramePtr->CHID       = rawFrame.CHID;
            Psi5SFramePtr->DCI1       = rawFrame.DCI1;
            Psi5SFramePtr->PS_DATA    = rawFrame.PS_DATA;
            Psi5SFramePtr->DCI2       = rawFrame.DCI2;
            Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
            Psi5SFramePtr->DCI3       = rawFrame.DCI3;
            Psi5SFramePtr->F_OV       = (uint8)(((base->CH[(uint8)(channelID-1u)].MBOX_SR)>>(frameID*3u)) & (PSI5_S_MBOX_SR_F0_OV_MASK >> PSI5_S_MBOX_SR_F0_OV_SHIFT));
        }
        if((((base->CH[(uint8)(channelID-1u)].MBOX_SR)>>(frameID*3u)) & PSI5_S_MBOX_SR_F0_ERR_MASK) != 0u)
        {
            base->CH[(uint8)(channelID-1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_ERR_MASK<<(uint32)(frameID*3u));
        }
        if((((base->CH[(uint8)(channelID-1u)].MBOX_SR)>>(frameID*3u)) & PSI5_S_MBOX_SR_F0_OV_MASK) != 0u)
        {
            base->CH[(uint8)(channelID-1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_OV_MASK<<(uint32)(frameID*3u));
        }
        base->CH[(uint8)(channelID-1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_READ_MASK<<(uint32)(frameID*3u));
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetEvents
 * Description   : Returns active events
 *
 *END**************************************************************************/
static void Psi5_S_Hw_GetEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                Psi5_S_Ip_EventType *const Events)
{
    /* Tx events */
    Psi5_S_Hw_GetTxEvents(Psi5InstanceId, Psi5SChannelId, Events);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SEvents
 * Description   : Returns active events
 *
 *END**************************************************************************/
static void Psi5_S_Hw_GetPsi5SEvents(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr)
{
    /* PSI5S Frame interrupt */
    Psi5_S_Hw_GetPsi5SFrameInt(Psi5InstanceId, Psi5SChannelId, Psi5SFramePtr);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SFrame
 * Description   : Returns a raw PSI5_S frame
 *
 *END**************************************************************************/
static Std_ReturnType Psi5_S_Hw_GetPsi5SFrame(const Psi5_S_Ip_InstanceIdType instanceId,
                                              const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                              Psi5_S_Ip_Psi5SFrameType *Psi5SFramePtr)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
    Psi5_S_Ip_Psi5SFrameType rawFrame;
    rawFrame.XCRC = 0;
    rawFrame.CRC = 0;
    rawFrame.ERR = 0;
    rawFrame.F_ERR = 0;
    rawFrame.FID = 0;
    rawFrame.CHID = 0;
    rawFrame.DCI1 = 0;
    rawFrame.PS_DATA = 0;
    rawFrame.DCI2 = 0;
    rawFrame.TIME_STAMP = 0;
    rawFrame.DCI3 = 0;
    uint32 mBoxIRQ = 0u;
    uint8 arrayIndex = 0u;
    const Psi5_S_Ip_ChannelConfigType *chConfig;
    mBoxIRQ = base->MBOX_SR_IRQ;
    if (mBoxIRQ != 0u)
    {
        arrayIndex = Psi5_S_UsedConfig->instancesConfig[instanceId].chHwIdToIndexArrayConfig[Psi5SChannelId];
        chConfig = &(Psi5_S_UsedConfig->instancesConfig[instanceId].channelConfig[arrayIndex]);
        if (chConfig->callbackRx == NULL_PTR)
        {
            /* Check status MAILBOX0,LOC1 */
            if ((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_READ_MASK) != 0u)
            {
                Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[instanceId][0][1], &rawFrame);
            }
            if ((rawFrame.CHID != Psi5SChannelId) || (Psi5SChannelId == 0u))
            {
                retVal = Psi5_S_Hw_GetPsi5SFrameSub(instanceId, Psi5SChannelId, Psi5SFramePtr);
            }
            else
            {
                Psi5SFramePtr->XCRC = rawFrame.XCRC;
                Psi5SFramePtr->CRC = rawFrame.CRC;
                Psi5SFramePtr->ERR = rawFrame.ERR;
                Psi5SFramePtr->F_ERR = rawFrame.F_ERR;
                Psi5SFramePtr->FID = rawFrame.FID;
                Psi5SFramePtr->CHID = rawFrame.CHID;
                Psi5SFramePtr->DCI1 = rawFrame.DCI1;
                Psi5SFramePtr->PS_DATA = rawFrame.PS_DATA;
                Psi5SFramePtr->DCI2 = rawFrame.DCI2;
                Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
                Psi5SFramePtr->DCI3 = rawFrame.DCI3;
                Psi5SFramePtr->F_OV = (uint8)(base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F1_OV_MASK);
                base->CH0_MBOX_SR &= PSI5_S_CH0_MBOX_SR_F1_READ_MASK;
                base->CH[Psi5SFramePtr->CHID - 1u].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_ERR_MASK << (uint32)((uint32)rawFrame.FID * (uint32)3u));
            }
        }
    }
    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SFrameSub
 * Description   : Returns a raw PSI5_S frame
 *
 *END**************************************************************************/
static Std_ReturnType Psi5_S_Hw_GetPsi5SFrameSub(const Psi5_S_Ip_InstanceIdType instanceId,
                                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                                Psi5_S_Ip_Psi5SFrameType *Psi5SFramePtr)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
    Psi5_S_Ip_Psi5SFrameType rawFrame;
    uint32 mBoxSR = 0u;
    uint32 frameID = 0u;
    if (Psi5SChannelId == 0u)
    {
        if ((base->CH0_MBOX_SR & PSI5_S_CH0_MBOX_SR_F0_READ_MASK) != 0u)
        {
            frameID = 0u;
            Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[instanceId][Psi5SChannelId][frameID*3u], &rawFrame);
            Psi5SFramePtr->XCRC = rawFrame.XCRC;
            Psi5SFramePtr->CRC = rawFrame.CRC;
            Psi5SFramePtr->ERR = rawFrame.ERR;
            Psi5SFramePtr->F_ERR = rawFrame.F_ERR;
            Psi5SFramePtr->FID = rawFrame.FID;
            Psi5SFramePtr->CHID = rawFrame.CHID;
            Psi5SFramePtr->DCI1 = rawFrame.DCI1;
            Psi5SFramePtr->PS_DATA = rawFrame.PS_DATA;
            Psi5SFramePtr->DCI2 = rawFrame.DCI2;
            Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
            Psi5SFramePtr->DCI3 = rawFrame.DCI3;
            Psi5SFramePtr->F_OV = (uint8)(((base->CH0_MBOX_SR) >> (frameID * 3u)) & (PSI5_S_CH0_MBOX_SR_F0_OV_MASK >> PSI5_S_CH0_MBOX_SR_F0_OV_SHIFT));
            if ((((base->CH0_MBOX_SR) >> (frameID * 3u)) & PSI5_S_CH0_MBOX_SR_F0_ERR_MASK) != 0u)
            {
                base->CH0_MBOX_SR &= (uint32)((uint32)PSI5_S_CH0_MBOX_SR_F0_ERR_MASK << (uint32)(frameID * 3u));
            }
            if ((((base->CH0_MBOX_SR) >> (frameID * 3u)) & PSI5_S_CH0_MBOX_SR_F0_OV_MASK) != 0u)
            {
                base->CH0_MBOX_SR &= (uint32)((uint32)PSI5_S_CH0_MBOX_SR_F0_OV_MASK << (uint32)(frameID * 3u));
            }
            base->CH0_MBOX_SR &= (uint32)((uint32)PSI5_S_CH0_MBOX_SR_F0_READ_MASK << (uint32)(frameID * 3u));
            /* Error in current message */
            if (rawFrame.F_ERR != 0u)
            {
                retVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    else
    {
        mBoxSR = base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR;
        if (mBoxSR != 0u)
        {
            while (((mBoxSR >> (frameID * 3u)) & 0x7u) == 0u)
            {
                frameID++;
            }
            if (frameID > 5u)
            {
                retVal = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                if ((((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & PSI5_S_MBOX_SR_F0_READ_MASK) != 0u)
                {
                     retVal = Psi5_S_Hw_GetPsi5SFrameCal(instanceId, Psi5SChannelId, frameID, Psi5SFramePtr);
                }
            }
        }
    }
    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_GetPsi5SFrameCal
 * Description   : Returns a raw PSI5_S frame
 *
 *END**************************************************************************/
static Std_ReturnType Psi5_S_Hw_GetPsi5SFrameCal(const Psi5_S_Ip_InstanceIdType instanceId,
                                              const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                              const uint32 frameID,
                                              Psi5_S_Ip_Psi5SFrameType *Psi5SFramePtr)
{
    Psi5_S_Ip_Psi5SFrameType rawFrame;
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
    uint32 StartTime;
    uint32 TimeoutTicks;
    uint32 ElapsedTicks = 0;
    Psi5_S_Ip_ChannelModeType channelMode;
    channelMode = (((base->CH[(uint8)(Psi5SChannelId - 1u)].MSGA & PSI5_S_MSGA_MODE_MASK) >> PSI5_S_MSGA_MODE_SHIFT) == 1u) ? PSI5_S_ASYNCHRONOUS : PSI5_S_SYNCHRONOUS;
    /* Read MailBox message */
    if (channelMode == PSI5_S_ASYNCHRONOUS)
    {
        Psi5_S_Ip_StartTimeout(&StartTime, &TimeoutTicks, PSI5_S_IP_TIMEOUT_VALUE_US, PSI5_S_IP_TIMEOUT_TYPE);
        base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR |= (uint32)((uint32)PSI5_S_MBOX_SR_F0_READ_MASK << (uint32)(frameID * 3u));
        while((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR == 0u) && !Psi5_S_Ip_CheckTimeout(&StartTime, &ElapsedTicks, TimeoutTicks, PSI5_S_IP_TIMEOUT_TYPE))
        {}
        Psi5_S_Hw_ConvertRawPsi5SFrame((uint32 *)base->MRU_BUF2_REG0, &rawFrame);
        Psi5SFramePtr->XCRC = rawFrame.XCRC;
        Psi5SFramePtr->CRC = rawFrame.CRC;
        Psi5SFramePtr->ERR = rawFrame.ERR;
        Psi5SFramePtr->F_ERR = rawFrame.F_ERR;
        Psi5SFramePtr->FID = rawFrame.FID;
        Psi5SFramePtr->CHID = rawFrame.CHID;
        Psi5SFramePtr->DCI1 = rawFrame.DCI1;
        Psi5SFramePtr->PS_DATA = rawFrame.PS_DATA;
        Psi5SFramePtr->DCI2 = rawFrame.DCI2;
        Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
        Psi5SFramePtr->DCI3 = rawFrame.DCI3;
        Psi5SFramePtr->F_OV = (uint8)(((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & (PSI5_S_MBOX_SR_F0_OV_MASK >> PSI5_S_MBOX_SR_F0_OV_SHIFT));
        if ((((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & PSI5_S_MBOX_SR_F0_ERR_MASK) != 0u)
        {
             base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_ERR_MASK << (uint32)(frameID * 3u));
             /* Error in current message */
             if (rawFrame.F_ERR != 0u)
             {
                 retVal = (Std_ReturnType)E_NOT_OK;
             }
        }
        if ((((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & PSI5_S_MBOX_SR_F0_OV_MASK) != 0u)
        {
            base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_OV_MASK << (uint32)(frameID * 3u));
        }
        base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_READ_MASK << (uint32)(frameID * 3u));
    }
    else
    {
        Psi5_S_Hw_ConvertRawPsi5SFrame(&g_psi5_s_sram_mailbox[instanceId][Psi5SChannelId][frameID * 3u], &rawFrame);
        Psi5SFramePtr->XCRC = rawFrame.XCRC;
        Psi5SFramePtr->CRC = rawFrame.CRC;
        Psi5SFramePtr->ERR = rawFrame.ERR;
        Psi5SFramePtr->F_ERR = rawFrame.F_ERR;
        Psi5SFramePtr->FID = rawFrame.FID;
        Psi5SFramePtr->CHID = rawFrame.CHID;
        Psi5SFramePtr->DCI1 = rawFrame.DCI1;
        Psi5SFramePtr->PS_DATA = rawFrame.PS_DATA;
        Psi5SFramePtr->DCI2 = rawFrame.DCI2;
        Psi5SFramePtr->TIME_STAMP = rawFrame.TIME_STAMP;
        Psi5SFramePtr->DCI3 = rawFrame.DCI3;
        Psi5SFramePtr->F_OV = (uint8)(((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & (PSI5_S_MBOX_SR_F0_OV_MASK >> PSI5_S_MBOX_SR_F0_OV_SHIFT));
        if ((((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & PSI5_S_MBOX_SR_F0_ERR_MASK) != 0u)
        {
            base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_ERR_MASK << (uint32)(frameID * 3u));
            /* Error in current message */
            if (rawFrame.F_ERR != 0u)
            {
              retVal = (Std_ReturnType)E_NOT_OK;
            }
        }
        if ((((base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR) >> (frameID * 3u)) & PSI5_S_MBOX_SR_F0_OV_MASK) != 0u)
        {
            base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_OV_MASK << (uint32)(frameID * 3u));
        }
        base->CH[(uint8)(Psi5SChannelId - 1u)].MBOX_SR &= (uint32)((uint32)PSI5_S_MBOX_SR_F0_READ_MASK << (uint32)(frameID * 3u));
    }
    return retVal;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConvertRawPsi5SFrame
 * Description   : Converts a raw PSI5_S frame
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConvertRawPsi5SFrame(const uint32 * sram_mailbox,
                                         Psi5_S_Ip_Psi5SFrameType * rawFrame)
{
    rawFrame->XCRC       = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_XCRC_MASK) >> PSI5_S_MRU_BUF2_REG1_XCRC_SHIFT);
    rawFrame->CRC        = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_CRC_MASK) >> PSI5_S_MRU_BUF2_REG1_CRC_SHIFT);
    rawFrame->ERR        = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_ERR_SHIFT);
    rawFrame->F_ERR      = (uint8)((uint16)(sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_XCRC_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_XCRC_ERR_SHIFT)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_SHIFT)<<CRC_ERR_P_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_HD_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_HD_ERR_SHIFT)<<HD_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_SHIFT)<<SCI_P_ERRE)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_SHIFT)<<F_WD_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_SHIFT)<<R_OVL_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_F_WD_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_F_WD_ERR_SHIFT)<<F_WD_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_SHIFT)<<R_OVL_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_N_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_N_ERR_SHIFT)<<N_ERR)
                           |(uint16)(((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_MASK) >> PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_SHIFT)<<R_UVL_ERR);
    rawFrame->FID        = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_FID_MASK) >> PSI5_S_MRU_BUF2_REG1_FID_SHIFT);
    rawFrame->CHID       = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_CHID_MASK) >> PSI5_S_MRU_BUF2_REG1_CHID_SHIFT);
    rawFrame->DCI1       = (uint8)((sram_mailbox[0] & PSI5_S_MRU_BUF2_REG1_DCI_MASK) >> PSI5_S_MRU_BUF2_REG1_DCI_SHIFT);
    rawFrame->PS_DATA    = (uint32)((sram_mailbox[1] & PSI5_S_MRU_BUF2_REG2_PS_DATA_MASK) >> PSI5_S_MRU_BUF2_REG2_PS_DATA_SHIFT);
    rawFrame->DCI2       = (uint8)((sram_mailbox[1] & PSI5_S_MRU_BUF2_REG2_DCI_MASK) >> PSI5_S_MRU_BUF2_REG2_DCI_SHIFT);
    rawFrame->TIME_STAMP = (uint32)((sram_mailbox[2] & PSI5_S_MRU_BUF2_REG3_TIMESTAMP_MASK) >> PSI5_S_MRU_BUF2_REG3_TIMESTAMP_SHIFT);
    rawFrame->DCI3       = (uint8)((sram_mailbox[2] & PSI5_S_MRU_BUF2_REG3_DCI_MASK) >> PSI5_S_MRU_BUF2_REG3_DCI_SHIFT);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConfigureSlot
 * Description   : Configures a single slot
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConfigureSlot(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                  const Psi5_S_Ip_SlotConfigType * slot
                                  )
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    float32 minUARTbytes = (float32)0;
    if (Psi5SChannelId == 0u)
    {
        minUARTbytes = (float32)((float32)8 + (float32)(slot->payloadSize) + (float32)0 + (float32)6) / (float32)8;
    }
    else
    {
        /* P/CRC controled by global*/
        if(!((base->CH[(uint8)(Psi5SChannelId-1u)].MSGA & PSI5_S_MSGA_L_PC_EN_MASK) != 0u))
        {
            if((base->CH[(uint8)(Psi5SChannelId-1u)].MSGA & PSI5_S_MSGA_G_PC_MASK) != 0u)
            {
                minUARTbytes = (float32)((float32)8 + (float32)(slot->payloadSize) + (float32)3 + (float32)6) / (float32)8;
            }
            else
            {
                minUARTbytes = (float32)((float32)8 + (float32)(slot->payloadSize) + (float32)1 + (float32)6) / (float32)8;
            }
        }
        /* P/CRC controled by local*/
        else
        {
            if((boolean)slot->useCRC)
            {
                minUARTbytes = (float32)((float32)8 + (float32)(slot->payloadSize) + (float32)3 + (float32)6) / (float32)8;
            }
            else
            {
                minUARTbytes = (float32)((float32)8 + (float32)(slot->payloadSize) + (float32)1 + (float32)6) / (float32)8;
            }
        }
    }
    if ((minUARTbytes - (float32)(uint8)minUARTbytes) > (float32)0)
    {
        minUARTbytes = (float32)((uint8)minUARTbytes) + (float32)1;
    }
    if (Psi5SChannelId == 0u)
    {
        base->CH0_MSGA |= PSI5_S_CH0_MSGA_F0_BYTE(minUARTbytes);
        base->CH0_MSGB = (base->CH0_MSGB & ~PSI5_S_CH0_MSGB_F0_payload_MASK) | PSI5_S_CH0_MSGB_F0_payload(slot->payloadSize);
    }
    else
    {
        Psi5_S_Hw_ConfigureSlotSub(instanceId, Psi5SChannelId, slot, minUARTbytes);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConfigureSlotSub
 * Description   : Configures a single slot
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConfigureSlotSub(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                  const Psi5_S_Ip_SlotConfigType * slot,
                                  const float32 minUARTbytes)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    uint8 slotIdx = (slot->slotId);
    switch(slotIdx)
    {
        case 0u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F0_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC0((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F0_payload_MASK) | PSI5_S_MSGB_F0_payload(slot->payloadSize);
            break;
        }
            case 1u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F1_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC1((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F1_payload_MASK) | PSI5_S_MSGB_F1_payload(slot->payloadSize);
            break;
        }
        case 2u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F2_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC2((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F2_payload_MASK) | PSI5_S_MSGB_F2_payload(slot->payloadSize);
            break;
        }
        case 3u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F3_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC3((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F3_payload_MASK) | PSI5_S_MSGB_F3_payload(slot->payloadSize);
            break;
        }
        case 4u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F4_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC4((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F4_payload_MASK) | PSI5_S_MSGB_F4_payload(slot->payloadSize);
            break;
        }
        case 5u:{ 
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_F5_BYTE(minUARTbytes);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGA |= PSI5_S_MSGA_L_PC5((slot->useCRC == FALSE) ? 0u : 1u);
            base->CH[(uint8)(Psi5SChannelId-1u)].MSGB  = (base->CH[(uint8)(Psi5SChannelId-1u)].MSGB & ~PSI5_S_MSGB_F5_payload_MASK) | PSI5_S_MSGB_F5_payload(slot->payloadSize);
            break;
        }
        default: /*error, not possible by configuration */ 
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_EnterUartMode
 * Description   : Enter into UART mode
 *
 *END**************************************************************************/
static void Psi5_S_Hw_EnterUartMode(const Psi5_S_Ip_InstanceIdType instanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    if((base->GLCR & PSI5_S_GLCR_GLOBAL_MODE_MASK) != 7u)
    {
        /* Global disable mode */
        base->GLCR |= (base->GLCR & ~PSI5_S_GLCR_GLOBAL_MODE_MASK) | PSI5_S_GLCR_GLOBAL_MODE(7u);
        base->GLSR |= PSI5_S_GLSR_GL_MODETR_DONE_MASK;
    }
    /* Global uart mode */
    base->GLCR = PSI5_S_GLCR_GLOBAL_MODE(0u);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_EnterConfigMode
 * Description   : Puts the channel in configuration mode
 *
 *END**************************************************************************/
static void Psi5_S_Hw_EnterConfigMode(const Psi5_S_Ip_InstanceIdType instanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
#if (STD_ON == PSI5_S_IP_DEBUG_MODE)
    base->GLCR |= PSI5_S_GLCR_DEBUG_EN_MASK;
#endif
    if((base->GLCR & PSI5_S_GLCR_GLOBAL_MODE_MASK) != 7u)
    {
        /* Global disable mode */
        base->GLCR |= (base->GLCR & ~PSI5_S_GLCR_GLOBAL_MODE_MASK) | PSI5_S_GLCR_GLOBAL_MODE(7u);
        base->GLSR |= PSI5_S_GLSR_GL_MODETR_DONE_MASK;
    }
    /* Global config mode */
    base->GLCR &= PSI5_S_GLCR_GLOBAL_MODE(4u);
    base->GLSR |= PSI5_S_GLSR_GL_MODETR_DONE_MASK;
    base->GLCR |= PSI5_S_GLCR_TSCNTEN_G_L_MASK;
    /* base->GLCR |= PSI5_S_GLCR_CLRTSCNT_G_L_MASK */
    base->GLCR |= PSI5_S_GLCR_TSCNT_EN_A_MASK;
    base->GLCR |= PSI5_S_GLCR_TSCNT_EN_B_MASK;
    /* base->GLCR |= PSI5_S_GLCR_CLRTSCNT_G_MASK */
    base->GLCR |= PSI5_S_GLCR_TSCNTEN_G_MASK;
    /* Provide the base address of the mailbox in the system RAM */
    base->CH_BASE_ADDR |= (base->CH_BASE_ADDR & ~(uint16)PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_MASK) | (uint32)&g_psi5_s_sram_mailbox[instanceId];
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_EnterNormalMode
 * Description   : Puts the channel in normal mode
 *
 *END**************************************************************************/
static void Psi5_S_Hw_EnterNormalMode(const Psi5_S_Ip_InstanceIdType instanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    if((base->GLCR & PSI5_S_GLCR_GLOBAL_MODE_MASK) != 7u)
    {
        /* Global disable mode */
        base->GLCR |= (base->GLCR & ~PSI5_S_GLCR_GLOBAL_MODE_MASK) | PSI5_S_GLCR_GLOBAL_MODE(7u);
        base->GLSR |= PSI5_S_GLSR_GL_MODETR_DONE_MASK;
    }
    /* Global config mode */
    base->GLCR &= PSI5_S_GLCR_GLOBAL_MODE(0x1U);
    base->GLSR |= PSI5_S_GLSR_GL_MODETR_DONE_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConfigureTx
 * Description   : Configures transmission
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConfigureTx(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * chCfg)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    /* Tx mode, Data length, default bit values */
    if ((chCfg->channelId > 0u) && (chCfg->txConfig != NULL_PTR))
    {
        /* Set mode to synchronous */
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_GL_TRIG_SEL((chCfg->txConfig->syncGlobal == FALSE) ? 0u : 1u);
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_DDSR_CLK_SEL((uint32)(chCfg->txConfig->clockSel));
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_CMD_TYPE((uint32)(chCfg->txConfig->txMode));
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_CMD((uint32)(chCfg->txConfig->initCMD));
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_ACMD((uint32)(chCfg->txConfig->initACMD));
        base->CH[(uint8)(chCfg->channelId-1u)].E2SCR |= PSI5_S_E2SCR_DEFAULT_SYNC((chCfg->txConfig->txDefault1 == FALSE) ? 0u : 1u);
        base->CH[(uint8)(chCfg->channelId-1u)].DDTRIG_OFFR |= PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR((uint32)(chCfg->txConfig->counterDelay));
        base->CH[(uint8)(chCfg->channelId-1u)].DDTRIG_PERR |= PSI5_S_DDTRIG_PERR_DDTRIG_PERR((uint32)(chCfg->txConfig->targetPeriod));
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConfigureRx
 * Description   : Configures reception
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConfigureRx(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * chCfg)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    if (chCfg->channelId == 0u)
    {
        base->CH0_MSGA |= PSI5_S_CH0_MSGA_TSBUF_EN(0x1U);    /* enable to capture respective TIMESTAMP value */
        base->CH0_MSGA |= PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL((uint32)(chCfg->timestamp));
    }
    else
    {
        /* Enable channel 1-7 message A */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_CH_EN_MASK;
        /* Configures mode for channel 1-7 message A */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_L_PC_EN((chCfg->LocalCtrl == FALSE) ? 0u : 1u); /* Parity/CRC option controlled locally. */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_MODE((uint32)(chCfg->mode));                    /* synchronous or asynchronous mode */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_TSBUF_EN(0x1U);                                 /* enable to capture respective TIMESTAMP value */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_TIME_STAMP_A_B_SEL((uint32)(chCfg->timestamp)); /* TIMESTAMP Counter A is to be use */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_TSBUF_CLR(0x1U);                                /* TIMESTAMP Buffer will be clear untill trigger come. */
        base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_G_PC((chCfg->useCRC == FALSE) ? 0u : 1u);       /* Selection CRC selected all frame */
        if(PSI5_S_ASYNCHRONOUS == chCfg->mode)
        {
            base->CH[(uint8)(chCfg->channelId-1u)].MSGA |= PSI5_S_MSGA_TMSG_TCMD(0x1U);
        }
        if((boolean)(chCfg->wdEnable)){
            /* Start watchdog counter for each channel */
            base->CH[(uint8)(chCfg->channelId-1u)].WD_CFGR |= PSI5_S_WD_CFGR_WDEN(0x1U);
            base->CH[(uint8)(chCfg->channelId-1u)].WD_CFGR |= PSI5_S_WD_CFGR_WD_TO(chCfg->wdTimeout);
        }
    }
}

#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ConfigureDma
 * Description   : Configures DMA
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ConfigureDma(const Psi5_S_Ip_InstanceIdType Psi5InstanceId,
                                   const Psi5_S_Ip_DmaConfigType * dmaConfig)
{
    uint8 instanceId = (uint8)Psi5InstanceId;
    Dma_Ip_LogicChannelScatterGatherListType global_DmaChannelTransferList[12U];
    /* TCD software */
    STcd[2U*instanceId].reg_SADDR = (uint32)(&(s_psi5BaseAddresses[instanceId]->MRU_BUF2_REG1));
    STcd[2U*instanceId].reg_SOFF  = 4;
    STcd[2U*instanceId].reg_ATTR = 514; /* SSIE = 2, DSIZE = 2*/
    STcd[2U*instanceId].reg_NBYTES.reg_MLOFFNO = 12;
    STcd[2U*instanceId].reg_SLAST_SDA = 0;
    STcd[2U*instanceId].reg_DADDR = 830475535;
    STcd[2U*instanceId].reg_DOFF = 4;
    STcd[2U*instanceId].reg_CITER.reg_ELINKNO = 1;
    STcd[2U*instanceId].reg_DLAST_SGA = (uint32)(&(STcd[(2U*instanceId)+1U]));
    STcd[2U*instanceId].reg_CSR = 273; /* Enable gather scatter gather and enable start */
    STcd[2U*instanceId].reg_BITER.reg_ELINKNO = 1;

    STcd[(2U*instanceId)+1U].reg_SADDR = (uint32)(&(s_psi5BaseAddresses[instanceId]->MRU_BUF2_REG0));
    STcd[(2U*instanceId)+1U].reg_SOFF  = 0;
    STcd[(2U*instanceId)+1U].reg_ATTR = 514; /* SSIZE = 2, DSIZE = 2*/
    STcd[(2U*instanceId)+1U].reg_NBYTES.reg_MLOFFNO = 4;
    STcd[(2U*instanceId)+1U].reg_SLAST_SDA = 0;
    STcd[(2U*instanceId)+1U].reg_DADDR = (uint32)(&(STcd[2U*instanceId].reg_DADDR));
    STcd[(2U*instanceId)+1U].reg_DOFF = 0;
    STcd[(2U*instanceId)+1U].reg_CITER.reg_ELINKNO = 1;
    STcd[(2U*instanceId)+1U].reg_DLAST_SGA = (uint32)(&(STcd[2U*instanceId]));
    STcd[(2U*instanceId)+1U].reg_CSR = 16; /* Enable gather scatter gather */
    STcd[(2U*instanceId)+1U].reg_BITER.reg_ELINKNO = 1;

    /* Source address: address of DSFR register */
    global_DmaChannelTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    global_DmaChannelTransferList[0U].Value = (uint32)(&(s_psi5BaseAddresses[instanceId]->MRU_BUF2_REG0));
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe.
    * The application should ensure that only addresses that fit in uint32 are used for configuring DMA. */
    /* Dest address: the address of internal buffer */
    global_DmaChannelTransferList[1U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    global_DmaChannelTransferList[1U].Value = (uint32)((uint32)(&(STcd[2U*instanceId].reg_DADDR)));
    global_DmaChannelTransferList[2U].Param =  DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    global_DmaChannelTransferList[2U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
    global_DmaChannelTransferList[3U].Param =  DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    global_DmaChannelTransferList[3U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
    global_DmaChannelTransferList[4U].Param =  DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    global_DmaChannelTransferList[4U].Value = (uint32)0U;
    global_DmaChannelTransferList[5U].Param =  DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    global_DmaChannelTransferList[5U].Value = (uint32)0U;
    global_DmaChannelTransferList[6U].Param =  DMA_IP_CH_SET_SOURCE_MODULO;
    global_DmaChannelTransferList[6U].Value = (uint32)0U;
    global_DmaChannelTransferList[7U].Param =  DMA_IP_CH_SET_DESTINATION_MODULO;
    global_DmaChannelTransferList[7U].Value = (uint32)0U;
    /* 4 bytes transfer for each request */
    global_DmaChannelTransferList[8U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    global_DmaChannelTransferList[8U].Value = (uint32)4U;
    global_DmaChannelTransferList[9U].Param =  DMA_IP_CH_SET_MAJORLOOP_COUNT;
    global_DmaChannelTransferList[9U].Value = (uint32)1U;
    global_DmaChannelTransferList[10U].Param =  DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    global_DmaChannelTransferList[10U].Value = (uint32)0U;
    global_DmaChannelTransferList[11U].Param =  DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    global_DmaChannelTransferList[11U].Value = (uint32)(&STcd[2U*instanceId]);
   
    /* Config and start DMA channel */
    (void)Dma_Ip_SetLogicChannelScatterGatherList(dmaConfig->channelId, 0, global_DmaChannelTransferList, (uint32)12U);
    (void)Dma_Ip_SetLogicChannelScatterGatherConfig(dmaConfig->channelId, 0);
}
#endif /* (STD_ON == PSI5_S_IP_DMA_IS_USED) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_InstanceDisable
 * Description   : Global channel disabler
 *
 *END**************************************************************************/
static void Psi5_S_Hw_InstanceDisable(const Psi5_S_Ip_InstanceIdType instanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    base->GLCR |= (base->GLCR & ~(uint16)PSI5_S_GLCR_GLOBAL_MODE_MASK) | PSI5_S_GLCR_GLOBAL_MODE_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ResetRegisters
 * Description   : Resets registers
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ResetRegisters(const Psi5_S_Ip_InstanceIdType instanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    uint32 Psi5SChannelId;
    /* Control Uart registers */
    base->LINCR1  = 0x00000092;
    base->LINIER  = 0x00000000;
    base->UARTCR  = 0x00000000;
    base->LINFBRR = 0x00000000;
    base->LINIBRR = 0x00000000;
    base->BDRL    = 0x00000000;
    base->BDRM    = 0x00000000;
    base->UARTPTO = 0x00000FFF;
    base->DMATXE  = 0x00000000;
    base->DMARXE  = 0x00000000;
    base->PTD     = 0x00000000;

    /* Control registers */
    base->GLCR = 0x00000000;
    base->GLSR = 0x00106000;
    base->CH_BASE_ADDR = 0x00000000;
    base->CH0_MSGA = 0x00000051;
    base->CH0_MSGB = 0x00000008;
    for(Psi5SChannelId = 0u; Psi5SChannelId < PSI5_S_CH_COUNT; Psi5SChannelId++)
    {
        /* Control channel registers */
        base->CH[Psi5SChannelId].MSGA = 0x00000000;
        base->CH[Psi5SChannelId].MSGB = 0x10842108;
        base->CH[Psi5SChannelId].WD_CFGR = 0x00000000;
        base->CH[Psi5SChannelId].DDTRIG_OFFR = 0x00000000;
        base->CH[Psi5SChannelId].DDTRIG_PERR = 0x00000000;
        base->CH[Psi5SChannelId].E2SCR = 0x00000800;
        base->CH[Psi5SChannelId].DDSR_L = 0x00000000;
    }
    
    /* Control interrupt registers */
    for(Psi5SChannelId = 0u; Psi5SChannelId < PSI5_S_CH_COUNT; Psi5SChannelId++)
    {
        base->IRQ[Psi5SChannelId].MBOX_SEL_IRQ = 0x00000000;
        base->IRQ[Psi5SChannelId].ERR_SEL_IRQ = 0x00000000;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_IsDataRegisterReady
 * Description   : Returns Tx register status
 *
 *END**************************************************************************/
static boolean Psi5_S_Hw_IsDataRegisterReady(const Psi5_S_Ip_InstanceIdType instanceId,
                                           const Psi5_S_Ip_HwChannelIdType Psi5SChannelId)
{  
    const uint32 arrayIndex = Psi5_S_UsedConfig->instancesConfig[instanceId].chHwIdToIndexArrayConfig[Psi5SChannelId];
    const Psi5_S_Ip_ChannelConfigType * config = &(Psi5_S_UsedConfig->instancesConfig[instanceId].channelConfig[arrayIndex]);
    boolean ret = (boolean)FALSE;
    /* Depending on Tx type */
    if(config->txConfig != NULL_PTR)
    {
        ret = (s_psi5BaseAddresses[instanceId]->CH[(uint8)(Psi5SChannelId-1u)].E2SSR & PSI5_S_E2SSR_DDSR_RDY_MASK) != 0u;
    }
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_IsDirectCommandRegisterReady
 * Description   : Returns Tx register status
 *
 *END**************************************************************************/
static boolean Psi5_S_Hw_IsDirectCommandRegisterReady(const Psi5_S_Ip_InstanceIdType instanceId)
{
    boolean ret = (boolean)FALSE;
    ret = ((s_psi5BaseAddresses[instanceId]->GLSR & PSI5_S_GLSR_DIRCMD_RDY_MASK) != 0u);
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_EnterUartMode
 * Description   : Enter UART mode.
 *
 *END**************************************************************************/
static void Psi5_S_EnterUartMode(const Psi5_S_Ip_InstanceType * instance)
{
    Psi5_S_Hw_EnterUartMode(instance->instanceId);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_EnterConfigMode
 * Description   : Enter CONFIG mode.
 *
 *END**************************************************************************/
static void Psi5_S_EnterConfigMode(const Psi5_S_Ip_InstanceType * instance)
{
    Psi5_S_Hw_EnterConfigMode(instance->instanceId);
    if(instance->callback != NULL_PTR)
    {
        /* Configure interrupts */
        Psi5_S_Hw_EnableGLInterrupts(instance->instanceId, (boolean)TRUE);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_EnterNormalMode
 * Description   : Enter NORMAL mode.
 *
 *END**************************************************************************/
static void Psi5_S_EnterNormalMode(const Psi5_S_Ip_InstanceType * instance)
{
    Psi5_S_Hw_EnterNormalMode(instance->instanceId);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_ConfigureUartMode
 * Description   : Configures fields in uart mode.
 *
 *END**************************************************************************/
static void Psi5_S_ConfigureUartMode(const Psi5_S_Ip_InstanceIdType instanceId,
                                       const Psi5_S_Ip_UartConfigType *uartConfig)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    /* UART_StandAlone */
    base->LINCR1 &= ~PSI5_S_LINCR1_SLEEP_MASK;    /* exit sleep mode */
    base->LINCR1 |= PSI5_S_LINCR1_INIT(0x1U);
    if (uartConfig->Uart_loop_back_enable == TRUE)
    {
        base->LINCR1 |= PSI5_S_LINCR1_LBKM(0x1U); /* Loop Back Mode */
        base->LINCR1 &= ~PSI5_S_LINCR1_INIT_MASK; /* exit initialization mode */
    }
    else
    {
        base->LINCR1 &=~ PSI5_S_LINCR1_LBKM_MASK; /* Loop Back Mode disable */
        base->LINCR1 &= ~PSI5_S_LINCR1_INIT_MASK; /* exit initialization mode */
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_ConfigureUart
 * Description   : Configures fields in config mode.
 *
 *END**************************************************************************/
static void Psi5_S_ConfigureUart(const Psi5_S_Ip_InstanceIdType instanceId,
                              const Psi5_S_Ip_UartConfigType * uartConfig)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    uint32 Baudrate;
    uint32 integer_baudrate;
    uint32 fractional_baudrate;
    uint32 frequency_baudrate;
    uint32 Frequency = uartConfig->Uart_baud_clock;
    uint32 OSR = uartConfig->Uart_over_sampling_rate;
    uint32 CSP = uartConfig->Uart_sampling_point;
    uint16 PTO = uartConfig->Uart_preset_timeout;
    uint8 Tx_TDFBM = ((uartConfig->Uart_transmit_MSB == FALSE) ? 0u : 1u);
    uint8 Rx_RDFBM = ((uartConfig->Uart_received_MSB == FALSE) ? 0u : 1u);
    uint8 Tx_PCE_TXDTU = ((uartConfig->Uart_tx_parity_enable == FALSE) ? 0u : 1u);
    uint8 Rx_PCE_Rx = ((uartConfig->Uart_rx_parity_enable == FALSE) ? 0u : 1u);
    uint8 Tx_TDLIS = ((uartConfig->Uart_tx_data_level_inversion == FALSE) ? 0u : 1u);
    uint8 Rx_RDLIS = ((uartConfig->Uart_rx_data_level_inversion == FALSE) ? 0u : 1u);
    uint8 Tx_IFD_EN = ((uartConfig->Uart_tx_idle_delay_time_enable == FALSE) ? 0u : 1u);
    uint8 Tx_IFD = uartConfig->Uart_tx_idle_delay_time;
    if (uartConfig->Uart_baud_rate_cus_enable == FALSE)
    {
        Baudrate = (uint32)(uartConfig->Uart_baud_rate);
    }
    else
    {
        Baudrate = (uint32)(uartConfig->Uart_baud_rate_cus);
    }
    if ((base->GLCR & PSI5_S_GLCR_GLOBAL_MODE_MASK) == 0x4u)
    {
        /* Psi5_S UART mode config */
        base->UARTCR |= PSI5_S_UARTCR_UART(0x1U);
        if (uartConfig->Uart_reduced_over_sampling_enable == FALSE)
        {
            integer_baudrate = (Frequency) / (Baudrate * 16u);
            frequency_baudrate = integer_baudrate * (Baudrate * 16u);
            fractional_baudrate = ((Frequency - frequency_baudrate) * 16u) / (Baudrate * 16u);
        }
        else
        {
            integer_baudrate = (Frequency) / (Baudrate * OSR);
            frequency_baudrate = integer_baudrate * (Baudrate * OSR);
            fractional_baudrate = ((Frequency - frequency_baudrate) * OSR) / (Baudrate * OSR);
            base->UARTCR |= PSI5_S_UARTCR_ROSE(0x1U);
            base->UARTCR |= PSI5_S_UARTCR_OSR(OSR);
            base->UARTCR |= PSI5_S_UARTCR_CSP(CSP);
        }
        base->UARTCR |= PSI5_S_UARTCR_MIS(0x1U);
        base->UARTCR |= PSI5_S_UARTCR_WL0(0x1U);
        base->LINIBRR |= PSI5_S_LINIBRR_IBR(integer_baudrate);
        base->LINFBRR |= PSI5_S_LINFBRR_FBR((uint32)fractional_baudrate);
        base->UARTCR |= PSI5_S_UARTCR_TDFLTFC(0x000U);
        base->UARTCR |= PSI5_S_UARTCR_RDFLRFC(0x000U);
        base->UARTCR |= PSI5_S_UARTCR_PCE_TXDTU((uint32)Tx_PCE_TXDTU);
        base->UARTCR |= PSI5_S_UARTCR_PCE_Rx((uint32)Rx_PCE_Rx);
        base->UARTCR |= PSI5_S_UARTCR_PC0(0x1U);
        base->UARTCR |= PSI5_S_UARTCR_RxEn(0x1U);
        base->UARTCR |= PSI5_S_UARTCR_TxEn(0x1U);
        /* Psi5_S Global Control config mode */
        base->UARTCR |= PSI5_S_GCR_TDFBM((uint32)Tx_TDFBM);
        base->UARTCR |= PSI5_S_GCR_RDFBM((uint32)Rx_RDFBM);
        base->UARTCR |= PSI5_S_GCR_TDLIS((uint32)Tx_TDLIS);
        base->UARTCR |= PSI5_S_GCR_RDLIS((uint32)Rx_RDLIS);
        base->PTD |= PSI5_S_PTD_EN((uint32)Tx_IFD_EN);
        base->PTD |= PSI5_S_PTD_IFD((uint32)Tx_IFD);
        base->UARTPTO = PSI5_S_UARTPTO_PTO(PTO);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_ConfigureSlots
 * Description   : Configures a single slot.
 *
 *END**************************************************************************/
static void Psi5_S_ConfigureSlots(const Psi5_S_Ip_InstanceIdType instanceId,
                                const Psi5_S_Ip_ChannelConfigType * channelConfig)
{
    /* For each slot configuration */
    for (uint32 slotIdx = 0u; slotIdx < channelConfig->rxConfig->numOfSlotConfigs; slotIdx++)
    {
        const Psi5_S_Ip_SlotConfigType * slotCfg = &(channelConfig->rxConfig->slotConfig[slotIdx]);
        /* Configure current slot */
        Psi5_S_Hw_ConfigureSlot(instanceId, channelConfig->channelId, slotCfg);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_ConfigureChannel
 * Description   : Configures a single channel.
 *
 *END**************************************************************************/
static void Psi5_S_ConfigureChannel(const Psi5_S_Ip_InstanceIdType instanceId,
                                  const Psi5_S_Ip_ChannelConfigType * chCfg)
{
    /* Configure Rx parameters */
    Psi5_S_Hw_ConfigureRx(instanceId, chCfg);
    /* Configure Tx mode side */
    Psi5_S_Hw_ConfigureTx(instanceId, chCfg);
    if(chCfg->callbackRx != NULL_PTR)
    {
        /* Configure interrupts */
        Psi5_S_Hw_EnableRxInterrupts(instanceId, chCfg, (boolean)TRUE);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_ConfigureChannels
 * Description   : Configures all the channels.
 *
 *END**************************************************************************/
static void Psi5_S_ConfigureChannels(const Psi5_S_Ip_InstanceType * instance)
{
    /* Configure uart */
    Psi5_S_ConfigureUart(instance->instanceId, instance->uartConfig);
#if (STD_ON == PSI5_S_IP_DMA_IS_USED)
    /* Configure DMA */
    Psi5_S_Hw_ConfigureDma(instance->instanceId, instance->dmaConfig);
#endif
    /* For each channel configuration */
    for (uint32 chIdx = 0u; chIdx < instance->numOfChannels; chIdx++)
    {
        const Psi5_S_Ip_ChannelConfigType * chCfg = &(instance->channelConfig[chIdx]);
        /* Configure the pulse generator */
        Psi5_S_ConfigureChannel(instance->instanceId, chCfg);
        /* Configure the slots */
        Psi5_S_ConfigureSlots(instance->instanceId, chCfg);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_EnableGLInterrupts
 * Description   : Interrupt enabler
 *
 *END**************************************************************************/
static void Psi5_S_Hw_EnableGLInterrupts(const Psi5_S_Ip_InstanceIdType instanceId,
                                     const boolean Enable)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    /* Clear MRU error interrupt flag */
    base->GLSR = PSI5_S_GLSR_MRU_ERR_MASK;
    /* Enable MRU error interrupt */
    base->GLCR |= Enable ? PSI5_S_GLCR_MRU_ERR_EN_MASK : 0u;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_EnableRxInterrupts
 * Description   : Interrupt enabler
 *
 *END**************************************************************************/
static void Psi5_S_Hw_EnableRxInterrupts(const Psi5_S_Ip_InstanceIdType instanceId,
                                     const Psi5_S_Ip_ChannelConfigType * chCfg,
                                     const boolean Enable)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[instanceId];
    /* Enable Mailbox interrupts */
    base->IRQ[chCfg->channelId].MBOX_SEL_IRQ |= Enable ? (uint32)((uint32)(PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_MASK)<<(uint32)(chCfg->channelId)) : (uint32)0u;
    /* Clear Error interrupt flag */
    base->ERR_SR_IRQ = PSI5_S_ERR_SR_IRQ_XCRC_ERR_MASK  | PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_HD_ERR_MASK    | PSI5_S_ERR_SR_IRQ_SCI_P_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_SCI_F_ERR_MASK | PSI5_S_ERR_SR_IRQ_SCI_O_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_F_WD_ERR_MASK  | PSI5_S_ERR_SR_IRQ_R_OVL_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_N_ERR_MASK     | PSI5_S_ERR_SR_IRQ_R_UVL_ERR_MASK;
    /* Enable Error interrupts */
    base->IRQ[0].ERR_SEL_IRQ |= Enable ? (PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_MASK   | PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_MASK
                                         |PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_MASK    | PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_MASK
                                         |PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_MASK  | PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_MASK
                                         |PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_MASK  | PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_MASK
                                         |PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_MASK  | PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_MASK
                                         |PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_MASK) : 0u;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Hw_ClearEvents
 * Description   : Clears all active events
 *
 *END**************************************************************************/
static void Psi5_S_Hw_ClearEvents(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
    /* Clear LIN interrupts */
    base->LINIER |= PSI5_S_LINIER_DTIE_MASK | PSI5_S_LINIER_DRIE_MASK
                    |PSI5_S_LINIER_TOIE_MASK | PSI5_S_LINIER_WUIE_MASK
                    |PSI5_S_LINIER_BOIE_MASK | PSI5_S_LINIER_FEIE_MASK
                    |PSI5_S_LINIER_OCIE_MASK | PSI5_S_LINIER_SZIE_MASK;
    /* Clear MRU error interrupt flag */
    base->GLSR = PSI5_S_GLSR_MRU_ERR_MASK;
    /* Clear Error interrupt flag */
    base->ERR_SR_IRQ = PSI5_S_ERR_SR_IRQ_XCRC_ERR_MASK  | PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_HD_ERR_MASK    | PSI5_S_ERR_SR_IRQ_SCI_P_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_SCI_F_ERR_MASK | PSI5_S_ERR_SR_IRQ_SCI_O_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_F_WD_ERR_MASK  | PSI5_S_ERR_SR_IRQ_R_OVL_ERR_MASK
                     | PSI5_S_ERR_SR_IRQ_N_ERR_MASK     | PSI5_S_ERR_SR_IRQ_R_UVL_ERR_MASK;
    if(Psi5SChannelId == 0u)
    {
        /* Clear read flag */
        base->CH0_MBOX_SR = PSI5_S_CH0_MBOX_SR_F0_READ_MASK | PSI5_S_CH0_MBOX_SR_F1_READ_MASK;
        /* Clear error flag */
        base->CH0_MBOX_SR = PSI5_S_CH0_MBOX_SR_F0_ERR_MASK | PSI5_S_CH0_MBOX_SR_F1_ERR_MASK;
        /* Clear overwrite flag */
        base->CH0_MBOX_SR = PSI5_S_CH0_MBOX_SR_F0_OV_MASK | PSI5_S_CH0_MBOX_SR_F1_OV_MASK;
    }
    else
    {
        /* Clear read flag */
        base->CH[(uint8)(Psi5SChannelId-1u)].MBOX_SR = PSI5_S_MBOX_SR_F0_READ_MASK | PSI5_S_MBOX_SR_F1_READ_MASK
                                          | PSI5_S_MBOX_SR_F2_READ_MASK | PSI5_S_MBOX_SR_F3_READ_MASK
                                          | PSI5_S_MBOX_SR_F4_READ_MASK | PSI5_S_MBOX_SR_F5_READ_MASK;
        /* clear error flag */
        base->CH[(uint8)(Psi5SChannelId-1u)].MBOX_SR = PSI5_S_MBOX_SR_F0_ERR_MASK | PSI5_S_MBOX_SR_F1_ERR_MASK
                                          | PSI5_S_MBOX_SR_F2_ERR_MASK | PSI5_S_MBOX_SR_F3_ERR_MASK
                                          | PSI5_S_MBOX_SR_F4_ERR_MASK | PSI5_S_MBOX_SR_F5_ERR_MASK;
        /* Clear overwrite flag */
        base->CH[(uint8)(Psi5SChannelId-1u)].MBOX_SR = PSI5_S_MBOX_SR_F0_OV_MASK | PSI5_S_MBOX_SR_F1_OV_MASK
                                          | PSI5_S_MBOX_SR_F2_OV_MASK | PSI5_S_MBOX_SR_F3_OV_MASK
                                          | PSI5_S_MBOX_SR_F4_OV_MASK | PSI5_S_MBOX_SR_F5_OV_MASK;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_IRQ_Handler_Rx
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
void Psi5_S_Ip_IRQ_Handler_Rx(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                             const Psi5_S_Ip_HwChannelIdType Psi5SChannelId)
{
    Psi5_S_Ip_Psi5SFrameType Psi5SFramePtr;

    Psi5_S_Hw_GetPsi5SEvents(Psi5SInstanceId, Psi5SChannelId, &Psi5SFramePtr);
    if(TRUE == Psi5_S_DriverInitialized)
    {
        const uint8 arrayIndex = Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].chHwIdToIndexArrayConfig[Psi5SChannelId];
        const Psi5_S_Ip_ChannelConfigType * chCfg = &(Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].channelConfig[arrayIndex]);
        if(NULL_PTR != chCfg->callbackRx)
        {
            chCfg->callbackRx(Psi5SInstanceId, Psi5SFramePtr);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_IRQ_Handler_Tx
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
void Psi5_S_Ip_IRQ_Handler_Tx(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                             const Psi5_S_Ip_HwChannelIdType Psi5SChannelId)
{
    Psi5_S_Ip_EventType Events;
    /*Clear all values*/
    Events.Psi5S_UartRX  = FALSE;
    Events.Psi5S_UartTX  = FALSE;
    Events.Psi5S_UartERR = FALSE;
    Events.Psi5S_GlobalTrigger = FALSE;
    Events.Psi5S_MessageReceived = FALSE;
    Events.Psi5S_MessageOverwrite = FALSE;
    Events.Psi5S_MessageErrorsPresent = FALSE;
    Events.Psi5S_TxDataOverwrite = FALSE;
    Events.Psi5S_ReadyToTransmit = FALSE;
    
    Psi5_S_Hw_GetEvents(Psi5SInstanceId, Psi5SChannelId, &Events);
    if(TRUE == Psi5_S_DriverInitialized)
    {
        const uint8 arrayIndex = Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].chHwIdToIndexArrayConfig[Psi5SChannelId];
        const Psi5_S_Ip_ChannelConfigType * chCfg = &(Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].channelConfig[arrayIndex]);
        if(NULL_PTR != chCfg->callbackTx)
        {
            chCfg->callbackTx(Events);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_IRQ_Global_Handler
 * Description   : Gets called from the low level handler
 * with instance and channel as parameter.
 *
 *END**************************************************************************/
void Psi5_S_Ip_IRQ_Global_Handler(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId)
{
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
    Psi5_S_Ip_EventType Events;
    /* Clear all values */
    Events.Psi5S_UartRX  = FALSE;
    Events.Psi5S_UartTX  = FALSE;
    Events.Psi5S_UartERR = FALSE;
    Events.Psi5S_GlobalTrigger = FALSE;
    Events.Psi5S_MessageReceived = FALSE;
    Events.Psi5S_MessageOverwrite = FALSE;
    Events.Psi5S_MessageErrorsPresent = FALSE;
    Events.Psi5S_TxDataOverwrite = FALSE;
    Events.Psi5S_ReadyToTransmit = FALSE;

    /* Call Psi5_S_Hw_GetGLEvents(Psi5SInstanceId, &Events) */
    if ((base->GLSR & PSI5_S_GLSR_DIRCMD_RDY_MASK) != 0u)
    {
        Events.Psi5S_GlobalTrigger = TRUE;
        base->GLCR&=~PSI5_S_GLCR_IE_DIRCMD_RDY_MASK;
    }
    if(TRUE == Psi5_S_DriverInitialized)
    {
        const Psi5_S_Ip_InstanceType * chCfg = &(Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId]);
        if(NULL_PTR != chCfg->callback)
        {
            chCfg->callback(Events);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_GetPsi5SFrame
 * Description   : Returns the last received PSI5 frame.
 *
 * Implements    : Psi5_S_Ip_GetPsi5SFrame_Activity
 *END**************************************************************************/
Std_ReturnType Psi5_S_Ip_GetPsi5SFrame(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                     const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                     Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr)
{
    Std_ReturnType ret;
    ret = Psi5_S_Hw_GetPsi5SFrame(Psi5SInstanceId, Psi5SChannelId, Psi5SFramePtr);
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_Transmit
 * Description   : Transmits a frame (standard or custom).
 *
 * Implements    : Psi5_S_Ip_Transmit_Activity
 *END**************************************************************************/
Std_ReturnType Psi5_S_Ip_Transmit(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                const uint64 Psi5SData)
{
    Std_ReturnType ret;
    const uint8 arrayIndex = Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].chHwIdToIndexArrayConfig[Psi5SChannelId];
    const Psi5_S_Ip_ChannelConfigType * config = &(Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId].channelConfig[arrayIndex]);
    /* Only if enabled */
    if (config->txConfig != NULL_PTR)
    {
        /* Check if ready for Tx */
        if (!Psi5_S_Hw_IsDataRegisterReady(Psi5SInstanceId, Psi5SChannelId))
        {
            ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Write and trigger */
            PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
            /* Enter critical region */
            /* SchM_Enter_Psi5S_PSI5_EXCLUSIVE_AREA_00 */
            base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR |= PSI5_S_E2SCR_DDSR_CLR_MASK;
            base->CH[(uint8)(Psi5SChannelId-1u)].DDSR_L = (uint32)(Psi5SData & PSI5_S_DDSR_L_DDSR_L2_MASK);
            base->CH[(uint8)(Psi5SChannelId-1u)].E2SSR |= PSI5_S_E2SSR_DDSR_RDY_MASK;
            if (config->callbackTx != NULL_PTR)
            {
                 base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR |= PSI5_S_E2SCR_DDSR_RDY_IE_MASK | PSI5_S_E2SCR_CMDTR_NWRT_IE_MASK;
            }
            /* Exit critical region*/
            /* SchM_Exit_Psi5S_PSI5_EXCLUSIVE_AREA_00 */
            ret = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        ret = (Std_ReturnType)E_NOT_OK;
    }
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_GetTransmissionStatus
 * Description   : Returns the status of the transmission part of the driver.
 *
 * Implements    : Psi5_S_Ip_GetTransmissionStatus_Activity
 *END**************************************************************************/
boolean Psi5_S_Ip_GetTransmissionStatus(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                      const Psi5_S_Ip_HwChannelIdType Psi5SChannelId)
{
    return Psi5_S_Hw_IsDataRegisterReady(Psi5SInstanceId, Psi5SChannelId);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_SendDirectCommand
 * Description   : Direct writing for the special Transceiver.
 *
 * Implements    : Psi5_S_Ip_SendDirectCommand_Activity
 *END**************************************************************************/
Std_ReturnType Psi5_S_Ip_SendDirectCommand(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                         const uint32 Psi5SDirCmd,
                                         const uint8 Psi5SDirCmdLen)
{
    Std_ReturnType ret;
    const Psi5_S_Ip_InstanceType * config = &(Psi5_S_UsedConfig->instancesConfig[Psi5SInstanceId]);
    /* Only if enabled */
    if (((Psi5SDirCmdLen == 1U) || (Psi5SDirCmdLen == 2U) || (Psi5SDirCmdLen == 4U)))
    {
        /* Check if ready for Tx */
        if (!Psi5_S_Hw_IsDirectCommandRegisterReady(Psi5SInstanceId))
        {
            ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Write and trigger */
            PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
            /* Enter critical region*/
            /* SchM_Enter_Psi5S_PSI5_EXCLUSIVE_AREA_00 */
            /* Provide length of the Direct Command that is transferred to the UART Tx line */
            /* 00: 1 byte */
            /* 01: 2 bytes */
            /* 10-11: 4 bytes */
            /* Clear first */
            base->GLCR &= ~PSI5_S_GLCR_DIRCMD_LEN_MASK;
            /* Set length */
            base->GLCR |= PSI5_S_GLCR_DIRCMD_LEN((uint32)((uint32)Psi5SDirCmdLen - (uint32)1u));
            base->DIRCMD = (uint32)(Psi5SDirCmd);
            base->GLSR |= PSI5_S_GLSR_DIRCMD_RDY_MASK;
            if (config->callback != NULL_PTR)
            {
                /* IE_DIRCMD_RDY interrupt */
                base->GLCR |= PSI5_S_GLCR_IE_DIRCMD_RDY_MASK;
            }
            /* Exit critical region*/
            /* SchM_Exit_Psi5S_PSI5_EXCLUSIVE_AREA_00 */
            ret = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        ret = (Std_ReturnType)E_NOT_OK;
    }
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_SetGlobalSync
 * Description   : Sets the global Pulse Generator state.
 *
 * Implements    : Psi5_S_Ip_SetGlobalSync_Activity
 *END**************************************************************************/
Std_ReturnType Psi5_S_Ip_SetGlobalSync(const uint8 Psi5SInstanceId,
                                       const boolean Psi5SState)
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
    uint8 ChIndex;
    for (ChIndex = 0u; ChIndex < 7u; ChIndex++)
    {
        if ((base->CH[ChIndex].E2SCR & PSI5_S_E2SCR_GL_TRIG_SEL_MASK) != 0u)
        {
            /* Enter critical region */
            /* SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_03 */
            base->GLCR = (base->GLCR & ~PSI5_S_GLCR_GL_DDSR_TRIG_MASK) | PSI5_S_GLCR_GL_DDSR_TRIG(((FALSE == Psi5SState) ? 0U : 1U));
            /* Exit critical region*/
            /* SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_03 */
            ret = (Std_ReturnType)E_OK;
        }
    }
    return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_SetChannelSync
 * Description   : Sets the local (Psi5SChannelId) Pulse Generator state.
 *
 * Implements    : Psi5_S_Ip_SetChannelSync_Activity
 *END**************************************************************************/
Std_ReturnType Psi5_S_Ip_SetChannelSync(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId,
                                        const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,
                                        const boolean Psi5SState)
{
        Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
        PSI5_S_MemMapPtr base = s_psi5BaseAddresses[Psi5SInstanceId];
        if (Psi5SChannelId > 0u)
        {
            /* Enter critical region */
            /* SchM_Enter_Psi5S_PSI5_EXCLUSIVE_AREA_04 */
            base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR = Psi5SState ? (base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR | PSI5_S_E2SCR_CH_TRIG_MASK) : (base->CH[(uint8)(Psi5SChannelId-1u)].E2SCR & ~PSI5_S_E2SCR_CH_TRIG_MASK);

            /* Exit critical region*/
            /* SchM_Exit_Psi5S_PSI5_EXCLUSIVE_AREA_04 */
            ret = (Std_ReturnType)E_OK;
        }
        return ret;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_Init
 * Description   : Initializes the driver for a given peripheral
 * according to the given configuration structure.
 *
 * Implements    : Psi5_S_Ip_Init_Activity
 *END**************************************************************************/
void Psi5_S_Ip_Init(const Psi5_S_Ip_ConfigType * configPtr)
{
    Psi5_S_UsedConfig = configPtr;
    Psi5_S_DriverInitialized = (boolean) TRUE;
    
    for(uint32 instanceCnt = 0; instanceCnt < Psi5_S_UsedConfig->numOfInstances; instanceCnt++)
    {
        const Psi5_S_Ip_InstanceType * cfgInstance = &(Psi5_S_UsedConfig->instancesConfig[instanceCnt]);
        /* Ente uart mode */
        Psi5_S_EnterUartMode(cfgInstance);
        /* Configure uart mode*/
        Psi5_S_ConfigureUartMode(cfgInstance->instanceId, cfgInstance->uartConfig);
        /* Enter configuration mode */
        Psi5_S_EnterConfigMode(cfgInstance);
        /* Configure channels */
        Psi5_S_ConfigureChannels(cfgInstance);
        /* Enter normal mode */
        Psi5_S_EnterNormalMode(cfgInstance);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Psi5_S_Ip_DeInit
 * Description   : Stops the driver and resets the internal states.
 *
 * Implements    : Psi5_S_Ip_DeInit_Activity
 *END**************************************************************************/
void Psi5_S_Ip_DeInit(void)
{
    Psi5_S_DriverInitialized = (boolean) FALSE;
    for(uint32 instanceCnt = 0u; instanceCnt < Psi5_S_UsedConfig->numOfInstances; instanceCnt++)
    {
        /* Put all channels in configuration mode */
        for (uint8 chIdx = 0u; chIdx < Psi5_S_UsedConfig->instancesConfig[instanceCnt].numOfChannels; chIdx++)
        {
            const Psi5_S_Ip_ChannelConfigType * chCfg =  &(Psi5_S_UsedConfig->instancesConfig[instanceCnt].channelConfig[chIdx]);
            /* Enter configuration mode */
            Psi5_S_Hw_EnterConfigMode(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId);
            if(Psi5_S_UsedConfig->instancesConfig[instanceCnt].callback != NULL_PTR)
            {
                /* Disable interrupts */
                Psi5_S_Hw_EnableGLInterrupts(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId, (boolean)FALSE);
            }
            if(chCfg->callbackRx != NULL_PTR)
            {
                /* Disable interrupts */
                Psi5_S_Hw_EnableRxInterrupts(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId, chCfg, (boolean)FALSE);
            }
            Psi5_S_Hw_ClearEvents(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId, chIdx);
        }
        /* Clear all registers */
        Psi5_S_Hw_ResetRegisters(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId);
        /* Disable the instance */
        Psi5_S_Hw_InstanceDisable(Psi5_S_UsedConfig->instancesConfig[instanceCnt].instanceId);
    }
    Psi5_S_UsedConfig = NULL_PTR;
}

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
