/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file Psi5_Ip.c
*
*   @addtogroup PSI5_IP PSI5 IPV Driver
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
#include "Psi5_Ip.h"
#include "Psi5_Ip_Cfg.h"
#include "SchM_Psi5.h"

#if (STD_ON == PSI5_IP_DMA_IS_USED)
#include "CDD_Mcl.h"
#endif

#ifdef PSI5_IP_DEV_ERROR_DETECT
#if (STD_ON == PSI5_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PSI5_IP_VENDOR_ID_C                        43
#define PSI5_IP_AR_RELEASE_MAJOR_VERSION_C         4
#define PSI5_IP_AR_RELEASE_MINOR_VERSION_C         7
#define PSI5_IP_AR_RELEASE_REVISION_VERSION_C      0
#define PSI5_IP_SW_MAJOR_VERSION_C                 2
#define PSI5_IP_SW_MINOR_VERSION_C                 0
#define PSI5_IP_SW_PATCH_VERSION_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Checks against Mcal.h */
    #if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PSI5_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Psi5_Ip.c and Mcal.h are different"
    #endif
#endif

/* Checks against Psi5_Ip.h */
#if (PSI5_IP_VENDOR_ID_C != PSI5_IP_VENDOR_ID)
    #error "Psi5_Ip.c and Psi5_Ip.h have different vendor ids"
#endif
#if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION_C    != PSI5_IP_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_MINOR_VERSION_C    != PSI5_IP_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_REVISION_VERSION_C != PSI5_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip.c and Psi5_Ip.h are different"
#endif
#if ((PSI5_IP_SW_MAJOR_VERSION_C != PSI5_IP_SW_MAJOR_VERSION) || \
     (PSI5_IP_SW_MINOR_VERSION_C != PSI5_IP_SW_MINOR_VERSION) || \
     (PSI5_IP_SW_PATCH_VERSION_C != PSI5_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip.c and Psi5_Ip.h are different"
#endif

/* Checks against Psi5_Ip_Cfg.h */
#if (PSI5_IP_VENDOR_ID_C != PSI5_IP_CFG_VENDOR_ID)
    #error "Psi5_Ip.c and Psi5_Ip_Cfg.h have different vendor ids"
#endif
#if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION_C    != PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_MINOR_VERSION_C    != PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_REVISION_VERSION_C != PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip.c and Psi5_Ip_Cfg.h are different"
#endif
#if ((PSI5_IP_SW_MAJOR_VERSION_C != PSI5_IP_CFG_SW_MAJOR_VERSION) || \
     (PSI5_IP_SW_MINOR_VERSION_C != PSI5_IP_CFG_SW_MINOR_VERSION) || \
     (PSI5_IP_SW_PATCH_VERSION_C != PSI5_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip.c and Psi5_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef AXBS_IP_DEV_ERROR_DETECT
    #if (STD_ON == AXBS_IP_DEV_ERROR_DETECT)
        /* Check if the files Psi5_Ip.c and Devassert.h are of the same version */
        #if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (PSI5_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AUTOSAR Version Numbers of Psi5_Ip.c and Devassert.h are different"
        #endif
    #endif
    #endif
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

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

/*!
 *Instance base addresses
 */
static const PSI5_MemMapPtr Psi5_Ip_axBaseAddresses[PSI5_INSTANCE_COUNT] = IP_PSI5_BASE_PTRS;

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == PSI5_IP_MULTIPARTITION_SUPPORT)
#define PSI5_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"

VAR_SEC_NOCACHE(Psi5_Ip_pUsedConfig) static Psi5_Ip_ConfigType const *Psi5_Ip_pUsedConfig  = NULL_PTR;
VAR_SEC_NOCACHE(Psi5_Ip_axMessages) static Psi5_Ip_AvailableMessagesType Psi5_Ip_axMessages[PSI5_INSTANCE_COUNT][PSI5_CHANNEL_COUNT];
VAR_SEC_NOCACHE(Psi5_Ip_bDriverInitialized) static boolean Psi5_Ip_bDriverInitialized = FALSE;

#define PSI5_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Psi5_MemMap.h"
#else
#define PSI5_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

static Psi5_Ip_ConfigType const *Psi5_Ip_pUsedConfig  = NULL_PTR;

#define PSI5_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

#define PSI5_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Psi5_MemMap.h"

static Psi5_Ip_AvailableMessagesType Psi5_Ip_axMessages[PSI5_INSTANCE_COUNT][PSI5_CHANNEL_COUNT];

static boolean Psi5_Ip_bDriverInitialized = FALSE;

#define PSI5_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Psi5_MemMap.h"
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"
#if (STD_ON == PSI5_IP_GET_PSI5_FRAME_API)
static Std_ReturnType Psi5_Hw_GetRawPsi5Frame(const Psi5_Ip_InstanceIdType instance,
                                              const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                              Psi5_Ip_RawFrameType *raw
                                             );
#endif

#if ((STD_ON == PSI5_IP_GET_PSI5_FRAME_API) || (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED))
static void Psi5_Hw_ConvertRawPsi5Frame(Psi5_Ip_Psi5FrameType *frame,
                                        Psi5_Ip_RawFrameType *raw,
                                        const Psi5_Ip_SlotConfigType *states
                                       );
#endif
#if (STD_ON == PSI5_IP_GET_SMC_FRAME_API)
static Std_ReturnType Psi5_Hw_GetRawSmcFrame(const Psi5_Ip_InstanceIdType instance,
                                             const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                             Psi5_Ip_RawFrameType *raw
                                            );
#endif
#if ((STD_ON == PSI5_IP_GET_SMC_FRAME_API) || (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED))
static void Psi5_Hw_ConvertRawSmcFrame(Psi5_Ip_SmcFrameType *frame,
                                       Psi5_Ip_RawFrameType *raw
                                      );
#endif
static void Psi5_Hw_ConfigureSlot(const Psi5_Ip_InstanceIdType instance,
                                  const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                  const Psi5_Ip_SlotConfigType *slot
                                 );
static void Psi5_Hw_EnterConfigMode(const Psi5_Ip_InstanceIdType instance,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                   );
static void Psi5_Hw_EnterNormalMode(const Psi5_Ip_InstanceIdType instanceId,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                   );
static void Psi5_Hw_ConfigureTx(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *chCfg
                               );
static void Psi5_Hw_ConfigureRx(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *chCfg
                               );
static void Psi5_Hw_ConfigurePulseGenerator(const Psi5_Ip_InstanceIdType instanceId,
                                            const Psi5_Ip_ChannelConfigType *chCfg
                                           );
#if (STD_ON == PSI5_IP_DMA_IS_USED)
static void Psi5_Hw_ConfigureDma(const Psi5_Ip_InstanceIdType instanceId,
                                 const Psi5_Ip_ChannelConfigType *chCfg
                                );
#endif
static void Psi5_Hw_InstanceDisable(const Psi5_Ip_InstanceIdType instanceId,
                                    const boolean state
                                   );
static Std_ReturnType Psi5_Hw_StartGlobalCtc(const Psi5_Ip_InstanceIdType instanceId,
                                             const boolean state
                                            );
static void Psi5_Hw_ResetRegisters(const Psi5_Ip_InstanceIdType instance);
#if ((STD_ON == PSI5_IP_GET_TRANSMISSION_STATUS_API) || (STD_ON == PSI5_IP_TRANSMIT_API))
static boolean Psi5_Hw_IsDataRegisterReady(const Psi5_Ip_InstanceIdType instance,
                                           const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                          );
#endif
static void Psi5_EnterConfigMode(const Psi5_Ip_InstanceType *instance);
static void Psi5_EnterNormalMode(const Psi5_Ip_InstanceType *instance);
static void Psi5_ConfigureSlots(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *channelConfig
                               );
static void Psi5_ConfigureChannel(const Psi5_Ip_InstanceIdType instanceId,
                                  const Psi5_Ip_ChannelConfigType * chCfg
                                 );
static void Psi5_ConfigureChannels(const Psi5_Ip_InstanceType * instance);

static void Psi5_Hw_GetTxEvents(const Psi5_Ip_InstanceIdType instance,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                Psi5_Ip_EventType *const Events
                               );
static void Psi5_Hw_GetSmcEvents(const Psi5_Ip_InstanceIdType instance,
                                 const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                 Psi5_Ip_EventType *const Events
                                );
static void Psi5_Hw_GetPsi5Events(const Psi5_Ip_InstanceIdType instance,
                                  const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                  Psi5_Ip_EventType *const Events
                                 );
static void Psi5_Hw_GetEvents(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                              const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                              Psi5_Ip_EventType *const Events
                             );
static void Psi5_Hw_EnableInterrupts(const Psi5_Ip_InstanceIdType instance,
                                     const Psi5_Ip_ChannelConfigType *chCfg,
                                     const boolean Enable
                                    );
static void Psi5_Hw_ClearEvents(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId
                               );

/**
 *
 * Function Name : Psi5_Hw_GetTxEvents
 * Description   : Returns active Tx events
 *
 *END**************************************************************************/
static void Psi5_Hw_GetTxEvents(const Psi5_Ip_InstanceIdType instance,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                Psi5_Ip_EventType *const Events
                               )
{
    const PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[instance].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[instance].channelConfig[arrayIndex]);
    uint32 regValue;

    if (NULL_PTR != config->txConfig)
    {
        uint32 txMaskOvr = (config->txConfig->txMode == PSI5_TX_MODE_7) ? PSI5_CH_GISR_IS_DSROW_MASK : PSI5_CH_GISR_IS_PROW_MASK;
        uint32 txMaskOvrSet = (config->txConfig->txMode == PSI5_TX_MODE_7) ? PSI5_CH_GICR_IE_DSROW_MASK : PSI5_CH_GICR_IE_PROW_MASK;
        uint32 txMaskRdy = (config->txConfig->txMode == PSI5_TX_MODE_7) ? PSI5_CH_GISR_DSR_RDY_MASK : PSI5_CH_GISR_DPR_RDY_MASK;
        uint32 txMaskRdySet = (config->txConfig->txMode == PSI5_TX_MODE_7) ? PSI5_CH_GICR_IE_DSRR_MASK : PSI5_CH_GICR_IE_PRR_MASK;

        regValue = base->CHANNEL[Psi5ChannelId].CH_GISR & txMaskOvr;

        /* Data prep overwrite */
        if (0u != regValue)
        {
            if (0u != (base->CHANNEL[Psi5ChannelId].CH_GICR & txMaskOvrSet))
            {
                Events->Psi5_TxDataOverwrite = TRUE;

                /*Disable interrupt, it will be re-enabled  in the transmit function*/
                base->CHANNEL[Psi5ChannelId].CH_GICR &= ~txMaskOvrSet;
            }
            /*clear interrupt*/
            base->CHANNEL[Psi5ChannelId].CH_GISR |= txMaskOvr;
        }

        regValue = base->CHANNEL[Psi5ChannelId].CH_GISR & txMaskRdy;
        /* Data prep ready */
        if (0u != regValue)
        {
            if (0u != (base->CHANNEL[Psi5ChannelId].CH_GICR & txMaskRdySet))
            {
                Events->Psi5_DriverReadyToTransmit = TRUE;

                /*Disable interrupt, it will be re-enabled  in the transmit function*/
                base->CHANNEL[Psi5ChannelId].CH_GICR &= ~txMaskRdySet;
            }
            /*There is no interrupt flag, does not need clear interrupt*/
        }
    }
}

/**
 *
 * Function Name : Psi5_Hw_GetSmcEvents
 * Description   : Returns active SMC events
 *
 *END**************************************************************************/
static void Psi5_Hw_GetSmcEvents(const Psi5_Ip_InstanceIdType instance,
                                 const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                 Psi5_Ip_EventType *const Events
                                )
{
    const PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
#if (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED)
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[instance].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[instance].channelConfig[arrayIndex]);
#endif

    uint8 tempPosition = 0u;
    uint8 regRavlue;

#if (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED)
    /* SMC DMA / Normal */
    if (NULL_PTR != config->rxConfig->smcDmaConfig)
    {
        /* Ready */
        if (0u != (base->CHANNEL[Psi5ChannelId].CH_DSR & PSI5_CH_DSR_IS_DMA_TF_SF_MASK))
        {
            if (0u != (base->CHANNEL[Psi5ChannelId].CH_DCR & PSI5_CH_DCR_IE_DMA_TF_SF_MASK))
            {
                Events->Psi5_SmcDmaTransferComplete = TRUE;

                /*Convert data*/
                Psi5_Hw_ConvertRawSmcFrame(config->rxConfig->smcDmaConfig->smcDmaUserBuffer, config->rxConfig->smcDmaConfig->smcDmaInternalBuffer);
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_DSR |= PSI5_CH_DSR_IS_DMA_TF_SF_MASK;
        }

        /* Underflow */
        if (0u != (base->CHANNEL[Psi5ChannelId].CH_DSR & PSI5_CH_DSR_IS_DMA_SFUF_MASK))
        {
            if (0u != (base->CHANNEL[Psi5ChannelId].CH_DCR & PSI5_CH_DCR_IE_DMA_SFUF_MASK))
            {
                Events->Psi5_SmcDmaUnderflow = TRUE;
            }

             /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_DSR |= PSI5_CH_DSR_IS_DMA_SFUF_MASK;
        }
    }
    else
#endif
    {
        /* SMC Rx Complete */
        if (0u != (base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_NVSM_MASK))
        {
            /* Mark event */
            Events->Psi5_SmcMessageReceived = TRUE;

            regRavlue = (uint8)((base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_NVSM_MASK) >> PSI5_CH_GISR_IS_NVSM_SHIFT);

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_SFR_COUNT - 1u))) 
            {
                /* increment position */
                tempPosition++;
            }

            if (0XFFu == Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex)
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex = 0u;
            }

            /*increment index of array and save bit position*/
            Psi5_Ip_axMessages[instance][Psi5ChannelId].smcPosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex] = tempPosition;

            if ((Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex + 1u) >= PSI5_CHANNEL_CH_SFR_COUNT)
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex = 0u;
            }
            else
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_GISR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }

        /* SMC Overwrite */
        if (0u != (base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_OWSM_MASK))
        {
            Events->Psi5_SmcMessageOverwrite = TRUE;

            regRavlue = (uint8)((base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_OWSM_MASK) >> PSI5_CH_GISR_IS_OWSM_SHIFT);

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_SFR_COUNT - 1u)))
            {
                /* increment position */
                tempPosition++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_GISR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }

        /* SMC error */
        if (0u != (base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_CESM_MASK))
        {
            Events->Psi5_SmcMessageCRCError = TRUE;

            regRavlue = (uint8)((base->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_IS_CESM_MASK) >> PSI5_CH_GISR_IS_CESM_SHIFT);

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_SFR_COUNT - 1u))) 
            {
                /* increment position */
                tempPosition++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_GISR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }
    }
}

/**
 *
 * Function Name : Psi5_Hw_GetPsi5Events
 * Description   : Returns active PSI5 events
 *
 *END**************************************************************************/
static void Psi5_Hw_GetPsi5Events(const Psi5_Ip_InstanceIdType instance,
                                  const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                  Psi5_Ip_EventType *const Events
                                 )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
#if (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED)
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[instance].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType * config = &(Psi5_Ip_pUsedConfig->instancesConfig[instance].channelConfig[arrayIndex]);
    const Psi5_Ip_SlotConfigType * slotStates;
    const Psi5_Ip_ChannelRxPsi5DmaConfigType * psi5DmaConfig;
    uint8 index = 0;
#endif

    uint32 regRavlue;
    uint8 tempPosition = 0u;

#if (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED)
    /* PSI5 DMA */
    if (NULL_PTR != config->rxConfig->psi5DmaConfig)
    {
        /* Ready */
        if ((0U != (base->CHANNEL[Psi5ChannelId].CH_DSR & PSI5_CH_DSR_IS_DMA_TF_PM_DS_MASK)) && (0U != (base->CHANNEL[Psi5ChannelId].CH_DCR & PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK)))
        {
            Events->Psi5_Psi5DmaTransferComplete = TRUE;

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_DSR |= PSI5_CH_DSR_IS_DMA_TF_PM_DS_MASK;

            psi5DmaConfig = config->rxConfig->psi5DmaConfig;
            /*Convert data if Mode is PSI5_DMA_MODE_CONF2 or PSI5_DMA_MODE_CONF3*/
            if(PSI5_DMA_MODE_CONF4 != psi5DmaConfig->psi5DmaMode)
            {
                slotStates = config->rxConfig->slotConfig;

                for(index = 0U;index< psi5DmaConfig->psi5DmaWatermarkDmaTrigger; index++)
                {
                    Psi5_Hw_ConvertRawPsi5Frame(&(psi5DmaConfig->psi5DmaUserBuffer[index]), &(psi5DmaConfig->psi5DmaInternalBuffer[index]), slotStates);
                }
            }
            /*store diagnostic bits if Mode is PSI5_DMA_MODE_CONF2*/
            if(PSI5_DMA_MODE_CONF2 == psi5DmaConfig->psi5DmaMode)
            {
                psi5DmaConfig->psi5DmaUserDiagnosticBuffer[0U] = psi5DmaConfig->psi5DmaInternalBuffer[psi5DmaConfig->psi5DmaWatermarkDmaTrigger][0U];
                psi5DmaConfig->psi5DmaUserDiagnosticBuffer[1U] = psi5DmaConfig->psi5DmaInternalBuffer[psi5DmaConfig->psi5DmaWatermarkDmaTrigger][1U];
            }
            /*store diagnostic bits if Mode is PSI5_DMA_MODE_CONF4*/
            if(PSI5_DMA_MODE_CONF4 == psi5DmaConfig->psi5DmaMode)
            {
                psi5DmaConfig->psi5DmaUserDiagnosticBuffer[0U] = psi5DmaConfig->psi5DmaInternalBuffer[0U][0U];
                psi5DmaConfig->psi5DmaUserDiagnosticBuffer[1U] = psi5DmaConfig->psi5DmaInternalBuffer[0U][1U];
            }
        }

        /* Underflow */
        if ((0u != (base->CHANNEL[Psi5ChannelId].CH_DSR & PSI5_CH_DSR_IS_DMA_PM_DS_UF_MASK)) && (0u != (base->CHANNEL[Psi5ChannelId].CH_DCR & PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK)))
        {
            Events->Psi5_Psi5DmaUnderflow = TRUE;

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_DSR |= PSI5_CH_DSR_IS_DMA_PM_DS_UF_MASK;
        }

        /* Overflow */
        if ((0u != (base->CHANNEL[Psi5ChannelId].CH_DSR & PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_MASK)) && (0u != (base->CHANNEL[Psi5ChannelId].CH_DCR & PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_MASK)))
        {
            Events->Psi5_Psi5DmaOverflow = TRUE;

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_DSR |= PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_MASK;
        }
    }
    else
#endif
    {
        /* PSI5 Rx Complete */
        if ((0u != base->CHANNEL[Psi5ChannelId].CH_NDSR) && (0u != (base->CHANNEL[Psi5ChannelId].CH_NDICR & PSI5_CH_NDICR_IE_ND_MASK)))
        {
            /* Mark event */
            Events->Psi5_Psi5MessageReceived = TRUE;

            regRavlue = base->CHANNEL[Psi5ChannelId].CH_NDSR;

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_PMR_COUNT - 1u))) 
            {
                /* increment position */
                tempPosition++;
            }

            /*0xFF means that there are no messages waiting to be read*/
            if (0xFFu == Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex)
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex = 0u;
            }

            /*save bit position*/
            Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5PosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex] = tempPosition;

            if ((Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex + 1u) >= PSI5_CHANNEL_CH_PMR_COUNT)
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex = 0u;
            }
            else
            {
                Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_NDSR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }

        /* PSI5 Overwrite */
        if ((0u != base->CHANNEL[Psi5ChannelId].CH_OWSR) && (0u != (base->CHANNEL[Psi5ChannelId].CH_OWICR & PSI5_CH_OWICR_IE_OW_MASK)))
        {
            Events->Psi5_Psi5MessageOverwrite = TRUE;

            regRavlue = base->CHANNEL[Psi5ChannelId].CH_OWSR;
            tempPosition = 0u;

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_PMR_COUNT - 1u))) 
            {
                /* increment position */
                tempPosition++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_OWSR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }

        /* PSI5 error */
        if ((0u != base->CHANNEL[Psi5ChannelId].CH_EISR) && (0u != (base->CHANNEL[Psi5ChannelId].CH_EICR & PSI5_CH_EICR_IE_ERROR_MASK)))
        {
            Events->Psi5_Psi5MessageErrorsPresent = TRUE;

            regRavlue = base->CHANNEL[Psi5ChannelId].CH_EISR;
            tempPosition = 0u;

            /* Iterate through bits of regRavlue till we find a set bit */
            while ((((regRavlue >> tempPosition) & 1u) == 0u) && (tempPosition < (PSI5_CHANNEL_CH_PMR_COUNT - 1u))) 
            {
                /* increment position */
                tempPosition++;
            }

            /*clear interrupt flag*/
            base->CHANNEL[Psi5ChannelId].CH_EISR |= (uint32)((uint32)1u << (uint32)tempPosition);
        }
    }
}

/**
 *
 * Function Name : Psi5_Hw_GetEvents
 * Description   : Returns active events
 *
 *END**************************************************************************/
static void Psi5_Hw_GetEvents(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                              const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                              Psi5_Ip_EventType *const Events
                             )
{
    /* Enter critical region */
    SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_05();

    /* Tx events */
    Psi5_Hw_GetTxEvents(Psi5InstanceId, Psi5ChannelId, Events);
    /* SMC events */
    Psi5_Hw_GetSmcEvents(Psi5InstanceId, Psi5ChannelId, Events);
    /* PSI5 events */
    Psi5_Hw_GetPsi5Events(Psi5InstanceId, Psi5ChannelId, Events);

    /* Exit critical region*/
    SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_05();
}

#if (STD_ON == PSI5_IP_GET_PSI5_FRAME_API)
/**
 *
 * Function Name : Psi5_Hw_GetRawPsi5Frame
 * Description   : Returns a raw PSI5 frame
 *
 */
static Std_ReturnType Psi5_Hw_GetRawPsi5Frame(const Psi5_Ip_InstanceIdType instance,
                                              const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                              Psi5_Ip_RawFrameType *raw
                                             )
{
    PSI5_Type const * base = Psi5_Ip_axBaseAddresses[instance];
    uint8 msgPosition = PSI5_CHANNEL_CH_PMR_COUNT;
    Std_ReturnType retVal;

    /* Enter critical region*/
    SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_01();

    if (0xFFu != Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex)
    {
        if (Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex > 0u)
        {
            Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex--;

            msgPosition = Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5PosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex];
        }
        else if (0u == Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex)
        {
            msgPosition = Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5PosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex];

            Psi5_Ip_axMessages[instance][Psi5ChannelId].psi5CurrentIndex = 0xFFu;
        }
        else
        {
            /* misra fix */
        }

        if (msgPosition < PSI5_CHANNEL_CH_PMR_COUNT)
        {
            /* Read message */
            (*raw)[0] = base->CHANNEL[Psi5ChannelId].CH_PMR[msgPosition].CH_PMRL;
            (*raw)[1] = base->CHANNEL[Psi5ChannelId].CH_PMR[msgPosition].CH_PMRH;

            retVal = (Std_ReturnType)E_OK;
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Exit critical region*/
    SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_01();

    return retVal;
}
#endif

#if (STD_ON == PSI5_IP_GET_SMC_FRAME_API)
/**
 *
 * Function Name : Psi5_Hw_GetRawSmcFrame
 * Description   : Returns a raw SMC frame
 *
 */
static Std_ReturnType Psi5_Hw_GetRawSmcFrame(const Psi5_Ip_InstanceIdType instance,
                                             const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                             Psi5_Ip_RawFrameType *raw
                                            )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
    uint8 msgPosition = PSI5_CHANNEL_CH_SFR_COUNT;
    Std_ReturnType retVal;

    /* Enter critical region*/
    SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_02();
    if (0xFFu != Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex)
    {
        if (Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex > 0u)
        {
            Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex--;

            msgPosition = Psi5_Ip_axMessages[instance][Psi5ChannelId].smcPosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex];
        }
        else if (0u == Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex)
        {
            msgPosition = Psi5_Ip_axMessages[instance][Psi5ChannelId].smcPosMsgAvailable[Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex];

            Psi5_Ip_axMessages[instance][Psi5ChannelId].smcCurrentIndex = 0xFFu;
        }
        else
        {
            /* misra fix */
        }

        if (msgPosition < PSI5_CHANNEL_CH_SFR_COUNT)
        {
            /* Read message (only 32 bits in lower data buffer) */
            (*raw)[0] = base->CHANNEL[Psi5ChannelId].CH_SFR[msgPosition];

            retVal = (Std_ReturnType)E_OK;
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Exit critical region*/
    SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_02();

    return retVal;
}
#endif

#if ((STD_ON == PSI5_IP_GET_PSI5_FRAME_API) || (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED))
/**
 *
 * Function Name : Psi5_Hw_ConvertRawPsi5Frame
 * Description   : Converts a raw PSI5 frame
 *
 */
static void Psi5_Hw_ConvertRawPsi5Frame(Psi5_Ip_Psi5FrameType *frame,
                                        Psi5_Ip_RawFrameType *raw,
                                        const Psi5_Ip_SlotConfigType *states
                                       )
{
    frame->CRC = (uint8)(((*raw)[0] & PSI5_CH_PMRRL_CRC_MASK) >> PSI5_CH_PMRRL_CRC_SHIFT);
    frame->C = (uint8)(((*raw)[0] & PSI5_CH_PMRRL_C_MASK) >> PSI5_CH_PMRRL_C_SHIFT);
    frame->F = (uint8)(((*raw)[1] & PSI5_CH_PMRRH_F_MASK) >> PSI5_CH_PMRRH_F_SHIFT);
    frame->EM = (uint8)(((*raw)[1] & PSI5_CH_PMRRH_EM_MASK) >> PSI5_CH_PMRRH_EM_SHIFT);
    frame->E = (uint8)(((*raw)[1] & PSI5_CH_PMRRH_E_MASK) >> PSI5_CH_PMRRH_E_SHIFT);
    frame->T = (uint8)(((*raw)[1] & PSI5_CH_PMRRH_T_MASK) >> PSI5_CH_PMRRH_T_SHIFT);
    frame->SLOT_COUNTER = (uint8)(((*raw)[1] & PSI5_CH_PMRRH_SlotCounter_MASK) >> PSI5_CH_PMRRH_SlotCounter_SHIFT);
    frame->TIME_STAMP = (uint32)(((*raw)[1] & PSI5_CH_PMRRH_TimeStampValue_MASK) >> PSI5_CH_PMRRH_TimeStampValue_SHIFT);

    /* If slot counter is 0 or any other out of range value, we assign settings from slot 1 (index 0) */
    uint32 slotIdx = (frame->SLOT_COUNTER < 1u) ?
                        0u : (((frame->SLOT_COUNTER > PSI5_CHANNEL_CH_SFR_COUNT) ?
                        5u : ((uint32)frame->SLOT_COUNTER - 1u)));

    /* 28 bits max, left aligned */
    uint32 dataRegion = (uint32)((*raw)[0] >> PSI5_CH_PMRRL_DATA_REGION_SHIFT);

    /* Number of normalization shifts */
    const uint8 shiftCount = (uint8)((uint8)PSI5_CH_PMRRL_DATA_REGION_WIDTH - (uint8)states[slotIdx].dataSize);

    /* If MSB first */
    if (states[slotIdx].msbFirst)
    {
        /* As we received it */
        frame->DATA_REGION = dataRegion >> shiftCount;
    }
    else
    {
        dataRegion = dataRegion >> shiftCount;
        /* Reverse bits*/
        for (uint8 i = 0u; i < states[slotIdx].dataSize; i++)
        {
            if (0u != (dataRegion & (uint32)((uint32)1u << (uint32)i)))
            {
                frame->DATA_REGION |= (uint32)((uint32)1u << (uint32)((uint32)((uint32)states[slotIdx].dataSize - (uint32)1u) - (uint32)i));
            }
        }
    }
}
#endif

#if ((STD_ON == PSI5_IP_GET_SMC_FRAME_API) || (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED))
/**
 *
 * Function Name : Psi5_Hw_ConvertRawSmcFrame
 * Description   : Converts a raw SMC frame
 *
 */
static void Psi5_Hw_ConvertRawSmcFrame(Psi5_Ip_SmcFrameType *frame,
                                       Psi5_Ip_RawFrameType *raw
                                      )
{
    frame->SLOT_NO = (uint8)(((*raw)[0] & PSI5_CH_SFR_SLOT_NO_MASK) >> PSI5_CH_SFR_SLOT_NO_SHIFT);
    frame->CER = (uint8)(((*raw)[0] & PSI5_CH_SFR_CER_MASK) >> PSI5_CH_SFR_CER_SHIFT);
    frame->OW = (uint8)(((*raw)[0] & PSI5_CH_SFR_OW_MASK) >> PSI5_CH_SFR_OW_SHIFT);
    frame->CRC = (uint8)(((*raw)[0] & PSI5_CH_SFR_CRC_MASK) >> PSI5_CH_SFR_CRC_SHIFT);
    frame->C = (uint8)(((*raw)[0] & PSI5_CH_SFR_C_MASK) >> PSI5_CH_SFR_C_SHIFT);
    frame->IDDATA = (uint8)(((*raw)[0] & PSI5_CH_SFR_IDDATA_MASK) >> PSI5_CH_SFR_IDDATA_SHIFT);

    /* Modify fields based on the C bit */
    if (0u != (frame->C))
    {
        frame->ID = (uint8)(((*raw)[0] & PSI5_CH_SFR_ID_MASK) >> PSI5_CH_SFR_ID_SHIFT);
        frame->DATA = (uint16)(((*raw)[0] & (PSI5_CH_SFR_IDDATA_MASK | PSI5_CH_SFR_DATA_MASK)) >> PSI5_CH_SFR_DATA_SHIFT);
    }
    else
    {
        frame->ID = (uint8)(((*raw)[0] & (PSI5_CH_SFR_ID_MASK | PSI5_CH_SFR_IDDATA_MASK)) >> PSI5_CH_SFR_IDDATA_SHIFT);
        frame->DATA = (uint16)(((*raw)[0] & PSI5_CH_SFR_DATA_MASK) >> PSI5_CH_SFR_DATA_SHIFT);
    }
}
#endif

/**
 *
 * Function Name : Psi5_Hw_ConfigureSlot
 * Description   : Configures a single slot
 *
 */
static void Psi5_Hw_ConfigureSlot(const Psi5_Ip_InstanceIdType instance,
                                  const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                  const Psi5_Ip_SlotConfigType *slot
                                 )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];

    switch(slot->slotId)
    {
        case 1u:{ base->CHANNEL[Psi5ChannelId].CH_S1SBR = PSI5_CH_S1SBR_S1SBT(slot->startOffs); break;}
        case 2u:{ base->CHANNEL[Psi5ChannelId].CH_S2SBR = PSI5_CH_S2SBR_S2SBT(slot->startOffs); break;}
        case 3u:{ base->CHANNEL[Psi5ChannelId].CH_S3SBR = PSI5_CH_S3SBR_S3SBT(slot->startOffs); break;}
        case 4u:{ base->CHANNEL[Psi5ChannelId].CH_S4SBR = PSI5_CH_S4SBR_S4SBT(slot->startOffs); break;}
        case 5u:{ base->CHANNEL[Psi5ChannelId].CH_S5SBR = PSI5_CH_S5SBR_S5SBT(slot->startOffs); break;}
        case 6u:{ base->CHANNEL[Psi5ChannelId].CH_S6SBR = PSI5_CH_S6SBR_S6SBT(slot->startOffs); break;}
        default: /*error, not possible by configuration */ break;
    }

    /* Configuration */
    base->CHANNEL[Psi5ChannelId].CH_SFCR[slot->slotId - 1U] = PSI5_CH_SFCR_SLOT_EN(1u) | PSI5_CH_SFCR_TS_CAPT(((slot->tsCapS0 == FALSE) ? 0u : 1u)) |
                                                              PSI5_CH_SFCR_SMCL(((slot->hasSMC == FALSE) ? 0u : 1u)) | PSI5_CH_SFCR_DRL(slot->dataSize) |
                                                              PSI5_CH_SFCR_CRCP(((slot->hasParity == FALSE) ? 0u : 1u));
}

/**
 *
 * Function Name : Psi5_Hw_EnterConfigMode
 * Description   : Puts the channel in configuration mode
 *
 */
static void Psi5_Hw_EnterConfigMode(const Psi5_Ip_InstanceIdType instance,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                   )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];

    /* Configure channel */
    base->CHANNEL[Psi5ChannelId].CH_PCCR |= (PSI5_CH_PCCR_PSI5_CH_EN_MASK | PSI5_CH_PCCR_PSI5_CH_CONFIG_MASK);
}

/**
 *
 * Function Name : Psi5_Hw_EnterNormalMode
 * Description   : Puts the channel in normal mode
 *
 */
static void Psi5_Hw_EnterNormalMode(const Psi5_Ip_InstanceIdType instanceId,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                   )
{

    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    /* Configure channel */
    base->CHANNEL[Psi5ChannelId].CH_PCCR &= ~PSI5_CH_PCCR_PSI5_CH_CONFIG_MASK;
}

/**
 *
 * Function Name : Psi5_Hw_ConfigureTx
 * Description   : Configures transmission
 *
 */
static void Psi5_Hw_ConfigureTx(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *chCfg
                               )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];
    uint16 defaultSync = 0u;

    /* Set mode to synchronous */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_MODE_MASK;

    if (chCfg->txConfig->txDefault1)
    {
        defaultSync = 1u;
    }

    /* Tx mode, Data length, default bit values, auto transfer from DBR to DSR */
    base->CHANNEL[chCfg->channelId].CH_DOBCR |= (PSI5_CH_DOBCR_CMD_TYPE(chCfg->txConfig->txMode) | PSI5_CH_DOBCR_DATA_LENGTH(((uint16)chCfg->txConfig->txSize) - ((uint16)1u))
                                                | PSI5_CH_DOBCR_DEFAULT_SYNC(defaultSync)
                                                | (((chCfg->txConfig->txMode) == PSI5_TX_MODE_7) ? PSI5_CH_DOBCR_DSR_RST_MASK : PSI5_CH_DOBCR_DBR_RST_MASK)
                                                | PSI5_CH_DOBCR_SW_READY_MASK);
}

/**
 *
 * Function Name : Psi5_Hw_ConfigureRx
 * Description   : Configures reception
 *
 */
static void Psi5_Hw_ConfigureRx(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *chCfg
                               )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    /* Buffer size */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_MEM_DEPTH(((uint32)chCfg->rxConfig->rxBufSize) - ((uint32)1u));

    /* bit rate */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_BIT_RATE(chCfg->rxConfig->bitRate);

    /* Fast clearing for both */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_FAST_CLR_PSI5_MASK | PSI5_CH_PCCR_FAST_CLR_SMC_MASK;
}

/**
 *
 * Function Name : Psi5_Hw_ConfigurePulseGenerator
 * Description   : Configures pulse generation
 *
 */
static void Psi5_Hw_ConfigurePulseGenerator(const Psi5_Ip_InstanceIdType instanceId,
                                            const Psi5_Ip_ChannelConfigType *chCfg
                                           )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    /* CTC control */
    if (chCfg->txConfig->syncGlobal)
    {
        base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_CTC_GED_SEL_MASK;
    }

    /* GTM reset */
    if (chCfg->txConfig->asyncReset)
    {
        base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_GTM_RESET_ASYNC_EN_MASK;
    }

    /* Decoder offset */
    base->CHANNEL[chCfg->channelId].CH_MDDIS_OFF = chCfg->txConfig->decoderOffset;

    /* Sync states */
    if (((uint8)(chCfg->txConfig->syncState) & 4u) != 0u)
    {
        base->CHANNEL[chCfg->channelId].CH_DOBCR |= PSI5_CH_DOBCR_GTM_TRIG_SEL_MASK;
    }

    if (((uint8)(chCfg->txConfig->syncState) & 2u) != 0u)
    {
        base->CHANNEL[chCfg->channelId].CH_DOBCR |= PSI5_CH_DOBCR_SP_PULSE_SEL_MASK;
    }

    if (((uint8)(chCfg->txConfig->syncState) & 1u) != 0u)
    {
        base->CHANNEL[chCfg->channelId].CH_DOBCR |= PSI5_CH_DOBCR_OP_SEL_MASK;
    }

    /* Pulse forming*/
    base->CHANNEL[chCfg->channelId].CH_PW0D = chCfg->txConfig->pulse0Width;
    base->CHANNEL[chCfg->channelId].CH_PW1D = chCfg->txConfig->pulse1Width;
    base->CHANNEL[chCfg->channelId].CH_CIPR = chCfg->txConfig->initialPulse;
    base->CHANNEL[chCfg->channelId].CH_CTPR = chCfg->txConfig->targetPulse;
}

#if (STD_ON == PSI5_IP_DMA_IS_USED)
/**
 *
 * Function Name : Psi5_Hw_ConfigureDma
 * Description   : Configures DMA
 *
 */
static void Psi5_Hw_ConfigureDma(const Psi5_Ip_InstanceIdType instanceId,
                                 const Psi5_Ip_ChannelConfigType *chCfg
                                )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];
    uint32 DCRvalue = 0;
    Mcl_DmaChannelTransferListType global_Mcl_DmaChannelTransferList[11U];

    const Psi5_Ip_ChannelRxPsi5DmaConfigType *psi5DmaConfig = chCfg->rxConfig->psi5DmaConfig;              /*!< DMA config for PSI5 messages */
    const Psi5_Ip_ChannelRxSmcDmaConfigType  *smcDmaConfig  = chCfg->rxConfig->smcDmaConfig;               /*!< DMA config for SMC messages */
    /* Pre - computed */
    boolean psi5DmaOk = psi5DmaConfig != NULL_PTR ? TRUE : FALSE;
    boolean smcDmaOk  = smcDmaConfig  != NULL_PTR ? TRUE : FALSE;

    if (psi5DmaOk || smcDmaOk)
    {
        /* Create the desired configuration list. */
        global_Mcl_DmaChannelTransferList[0U].Param = MCL_DMA_CH_SET_SOURCE_ADDRESS;
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe.
         * The application should ensure that only addresses that fit in uint32 are used for configuring DMA. */
        global_Mcl_DmaChannelTransferList[1U].Param = MCL_DMA_CH_SET_DESTINATION_ADDRESS;

        global_Mcl_DmaChannelTransferList[2U].Param = MCL_DMA_CH_SET_DESTINATION_TRANSFER_SIZE;
        global_Mcl_DmaChannelTransferList[2U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_Mcl_DmaChannelTransferList[3U].Param = MCL_DMA_CH_SET_SOURCE_TRANSFER_SIZE;
        global_Mcl_DmaChannelTransferList[3U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_Mcl_DmaChannelTransferList[4U].Param = MCL_DMA_CH_SET_SOURCE_SIGNED_OFFSET;
        global_Mcl_DmaChannelTransferList[4U].Value = (uint32)0U;
        global_Mcl_DmaChannelTransferList[5U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_OFFSET;
        global_Mcl_DmaChannelTransferList[5U].Value = (uint32)4U;
        global_Mcl_DmaChannelTransferList[6U].Param = MCL_DMA_CH_SET_SOURCE_MODULO;
        global_Mcl_DmaChannelTransferList[6U].Value = (uint32)0U;
        global_Mcl_DmaChannelTransferList[7U].Param = MCL_DMA_CH_SET_DESTINATION_MODULO;
        global_Mcl_DmaChannelTransferList[7U].Value = (uint32)0U;
        global_Mcl_DmaChannelTransferList[8U].Param = MCL_DMA_CH_SET_MINORLOOP_SIZE;
        global_Mcl_DmaChannelTransferList[9U].Param = MCL_DMA_CH_SET_MAJORLOOP_COUNT;
        global_Mcl_DmaChannelTransferList[9U].Value = (uint32)1U;
        global_Mcl_DmaChannelTransferList[10U].Param = MCL_DMA_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;

        /* Read DCR value */
        DCRvalue = base->CHANNEL[chCfg->channelId].CH_DCR;
        /* Clear old value*/
        DCRvalue = DCRvalue & (~(PSI5_CH_DCR_DMA_PM_DS_WM_MASK | PSI5_CH_DCR_DMA_PM_DS_CONFIG_MASK | PSI5_CH_DCR_DMA_EN_SF_MASK));
        /* Set new value*/
        DCRvalue |= (psi5DmaOk ? (PSI5_CH_DCR_DMA_PM_DS_WM(psi5DmaConfig->psi5DmaWatermarkDmaTrigger - 1u)) : (uint32)0U);
        DCRvalue |= (psi5DmaOk ? PSI5_CH_DCR_DMA_PM_DS_CONFIG(psi5DmaConfig->psi5DmaMode) : (uint32)0U);
        DCRvalue |= (smcDmaOk  ? (uint32)PSI5_CH_DCR_DMA_EN_SF_MASK : (uint32)0u);
        /*Store value to register*/
        base->CHANNEL[chCfg->channelId].CH_DCR = DCRvalue;

        /* DMA transfer */
        if (smcDmaOk)
        {
            /*Source address: address of DSFR register */
            global_Mcl_DmaChannelTransferList[0U].Value = (uint32)(&base->CHANNEL[chCfg->channelId].CH_DSFR);

            /*Dest address: the address of internal buffer*/
            global_Mcl_DmaChannelTransferList[1U].Value = (uint32)(smcDmaConfig->smcDmaInternalBuffer);

            /*4 bytes transfer for each request*/
            global_Mcl_DmaChannelTransferList[8U].Value = (uint32)4U;

            /*Back to the start address of the buffer after finish transfer*/
            global_Mcl_DmaChannelTransferList[10U].Value = (uint32)(0xFFFFFFFF-sizeof(uint32)+1);

            /*Config and start DMA channel*/
            Mcl_SetDmaChannelTransferList(smcDmaConfig->smcDmaChannel, global_Mcl_DmaChannelTransferList, (uint32)11U);
            Mcl_SetDmaChannelCommand(smcDmaConfig->smcDmaChannel, MCL_DMA_CH_START_REQUEST);
        }

        if (psi5DmaOk)
        {
            if (PSI5_DMA_MODE_CONF4 == psi5DmaConfig->psi5DmaMode)
            {
                /* Mode CONF4: Only the diagnostic bits are transferred through the DDSR*/
                global_Mcl_DmaChannelTransferList[0U].Value = (uint32)(&base->CHANNEL[chCfg->channelId].CH_DDSR);

                /*Number of bytes for each request*/
                global_Mcl_DmaChannelTransferList[8U].Value = ((uint32)sizeof(Psi5_Ip_RawFrameType));

                /*Back to the start address of the buffer after finish each transfer*/
                global_Mcl_DmaChannelTransferList[10U].Value = (uint32)(0xFFFFFFFF-sizeof(Psi5_Ip_RawFrameType)+1);
            }
            else if (PSI5_DMA_MODE_CONF3 == psi5DmaConfig->psi5DmaMode)
            {
                /* Mode CONF3: Data and diagnostic bits are transferred through the CH_DPMR*/
                global_Mcl_DmaChannelTransferList[0U].Value = (uint32)(&base->CHANNEL[chCfg->channelId].CH_DPMR);

                /*Number of bytes for each request*/
                global_Mcl_DmaChannelTransferList[8U].Value = ((uint32)sizeof(Psi5_Ip_RawFrameType)) * (psi5DmaConfig->psi5DmaWatermarkDmaTrigger);

                /*Back to the start address of the buffer after finish each transfer*/
                global_Mcl_DmaChannelTransferList[10U].Value = -(sint32)(sizeof(Psi5_Ip_RawFrameType) * (psi5DmaConfig->psi5DmaWatermarkDmaTrigger));
            }
            else
            {
                /* Mode CONF2: Data and diagnostic bits are transferred through the CH_DPMR*/
                global_Mcl_DmaChannelTransferList[0U].Value = (uint32)(&base->CHANNEL[chCfg->channelId].CH_DPMR);

                /*Number of bytes for each request*/
                global_Mcl_DmaChannelTransferList[8U].Value = ((uint32)sizeof(Psi5_Ip_RawFrameType)) * (psi5DmaConfig->psi5DmaWatermarkDmaTrigger + 1U);

                /*Back to the start address of the buffer after finish each transfer*/
                global_Mcl_DmaChannelTransferList[10U].Value = -(sint32)(sizeof(Psi5_Ip_RawFrameType) * (psi5DmaConfig->psi5DmaWatermarkDmaTrigger + 1U));
            }

            /*Dest address the address of internal buffer*/
            global_Mcl_DmaChannelTransferList[1U].Value = (uint32)(psi5DmaConfig->psi5DmaInternalBuffer);

            /*Config and start DMA channel*/
            Mcl_SetDmaChannelTransferList(psi5DmaConfig->psi5DmaChannel, global_Mcl_DmaChannelTransferList, (uint32)11U);
            Mcl_SetDmaChannelCommand(psi5DmaConfig->psi5DmaChannel, MCL_DMA_CH_START_REQUEST);
        }
    }
}
#endif

/**
 *
 * Function Name : Psi5_Hw_InstanceDisable
 * Description   : Global channel disabler
 *
 */
static void Psi5_Hw_InstanceDisable(const Psi5_Ip_InstanceIdType instanceId,
                                    const boolean state
                                   )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    base->GCR = (uint16)(base->GCR & ~(uint16)PSI5_GCR_GLOBAL_DISABLE_REQ_MASK) | PSI5_GCR_GLOBAL_DISABLE_REQ(((FALSE == state) ? 0U : 1U));
}

/**
 *
 * Function Name : Psi5_Hw_StartGlobalCtc
 * Description   : Global CTC (timer) enabler.
 *
 */
static Std_ReturnType Psi5_Hw_StartGlobalCtc(const Psi5_Ip_InstanceIdType instanceId,
                                             const boolean state
                                            )
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    uint8 ChIndex;
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    for (ChIndex = 0u; ChIndex < PSI5_CHANNEL_COUNT; ChIndex++)
    {
        if ((base->CHANNEL[ChIndex].CH_PCCR & PSI5_CH_PCCR_CTC_GED_SEL_MASK) != 0U)
        {
            base->GCR = (uint16)(base->GCR & ~(uint16)PSI5_GCR_CTC_GED_MASK) | PSI5_GCR_CTC_GED(((FALSE == state) ? 0U : 1U));
            ret = (Std_ReturnType)E_OK;
        }
    }

    return ret;
}

/**
 *
 * Function Name : Psi5_Hw_ResetRegisters
 * Description   : Resets registers
 *
 */
static void Psi5_Hw_ResetRegisters(const Psi5_Ip_InstanceIdType instance)
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
    uint8 ChIndex;

    for (ChIndex = 0u; ChIndex < PSI5_CHANNEL_COUNT; ChIndex++)
    {
        /* Control registers */
        base->CHANNEL[ChIndex].CH_DCR = 0u;
        base->CHANNEL[ChIndex].CH_GICR = 0u;
        base->CHANNEL[ChIndex].CH_NDICR = 0u;
        base->CHANNEL[ChIndex].CH_OWICR = 0u;
        base->CHANNEL[ChIndex].CH_EICR = 0u;

        /* Reset Slot configuration */
        base->CHANNEL[ChIndex].CH_S1SBR = 0u;
        base->CHANNEL[ChIndex].CH_S2SBR = 0u;
        base->CHANNEL[ChIndex].CH_S3SBR = 0u;
        base->CHANNEL[ChIndex].CH_S4SBR = 0u;
        base->CHANNEL[ChIndex].CH_S5SBR = 0u;
        base->CHANNEL[ChIndex].CH_S6SBR = 0u;

        for (uint8 slotIdx = 0u; slotIdx < PSI5_CHANNEL_CH_SFR_COUNT; slotIdx++)
        {
            base->CHANNEL[ChIndex].CH_SFCR[slotIdx] = PSI5_CH_SFCR_DRL(8u);
        }

        /* Boundary end */
        base->CHANNEL[ChIndex].CH_SNEBR = 0u;

        /* Tx block */
        base->CHANNEL[ChIndex].CH_DOBCR = 0u;
        base->CHANNEL[ChIndex].CH_MDDIS_OFF = 0u;
        base->CHANNEL[ChIndex].CH_PW0D = 0u;
        base->CHANNEL[ChIndex].CH_PW1D = 0u;
        base->CHANNEL[ChIndex].CH_CTPR = 0u;
        base->CHANNEL[ChIndex].CH_CIPR = 0u;

        /* Normal and disable */
        base->CHANNEL[ChIndex].CH_PCCR = (PSI5_CH_PCCR_ERROR_SELECT0_MASK | PSI5_CH_PCCR_ERROR_SELECT1_MASK |
                                          PSI5_CH_PCCR_ERROR_SELECT2_MASK | PSI5_CH_PCCR_ERROR_SELECT3_MASK |
                                          PSI5_CH_PCCR_ERROR_SELECT4_MASK);
    }
}

#if ((STD_ON == PSI5_IP_GET_TRANSMISSION_STATUS_API) || (STD_ON == PSI5_IP_TRANSMIT_API))
/**
 *
 * Function Name : Psi5_Hw_IsDataRegisterReady
 * Description   : Returns Tx register status
 *
 */
static boolean Psi5_Hw_IsDataRegisterReady(const Psi5_Ip_InstanceIdType instance,
                                           const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                          )
{
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[instance].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[instance].channelConfig[arrayIndex]);

    boolean ret = FALSE;

    /* Depending on Tx type */
    if (NULL_PTR != config->txConfig)
    {
        if (PSI5_TX_MODE_7 == config->txConfig->txMode)
        {
            ret = (Psi5_Ip_axBaseAddresses[instance]->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_DSR_RDY_MASK) != 0u;
        }
        else
        {
            ret = (Psi5_Ip_axBaseAddresses[instance]->CHANNEL[Psi5ChannelId].CH_GISR & PSI5_CH_GISR_DPR_RDY_MASK) != 0u;
        }
    }

    return ret;
}
#endif

/**
 *
 * Function Name : Psi5_EnterConfigMode
 * Description   : Enter CONFIG mode.
 *
 */
static void Psi5_EnterConfigMode(const Psi5_Ip_InstanceType *instance)
{
    /* Disable the instance */
    Psi5_Hw_InstanceDisable(instance->instanceId, TRUE);

    /* Put all channels in configuration mode */
    for (uint8 chIdx = 0u; chIdx < instance->numOfChannels; chIdx++)
    {
        const Psi5_Ip_ChannelConfigType *chCfg = &instance->channelConfig[chIdx];

        /* Enter configuration mode */
        Psi5_Hw_EnterConfigMode(instance->instanceId, chCfg->channelId);
    }

    /* Enable the instance */
    Psi5_Hw_InstanceDisable(instance->instanceId, FALSE);
}

/**
 *
 * Function Name : Psi5_EnterNormalMode
 * Description   : Enter NORMAL mode.
 *
 */
static void Psi5_EnterNormalMode(const Psi5_Ip_InstanceType *instance)
{
    /* Put all channels in normal mode */
    for (uint32 chIdx = 0u; chIdx < instance->numOfChannels; chIdx++)
    {
        const Psi5_Ip_ChannelConfigType *chCfg = &instance->channelConfig[chIdx];

        /* Enter normal mode */
        Psi5_Hw_EnterNormalMode(instance->instanceId, chCfg->channelId);
    }
}

/**
 *
 * Function Name : Psi5_ConfigureSlots
 * Description   : Configures a single slot.
 *
 */
static void Psi5_ConfigureSlots(const Psi5_Ip_InstanceIdType instanceId,
                                const Psi5_Ip_ChannelConfigType *channelConfig
                               )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];
    const Psi5_Ip_SlotConfigType *lastSlotCfg = &(channelConfig->rxConfig->slotConfig[(channelConfig->rxConfig->numOfSlotConfigs - 1u)]);
    uint16 SnEBT_Value = lastSlotCfg->startOffs + lastSlotCfg->slotLen;
    uint8 LastSlotId = lastSlotCfg->slotId;

    /* For each slot configuration */
    for (uint32 slotIdx = 0u; slotIdx < channelConfig->rxConfig->numOfSlotConfigs; slotIdx++)
    {
        const Psi5_Ip_SlotConfigType *slotCfg = &(channelConfig->rxConfig->slotConfig[slotIdx]);

        /* Configure current slot */
        Psi5_Hw_ConfigureSlot(instanceId, channelConfig->channelId, slotCfg);
    }

    /* New time frame */
    base->CHANNEL[channelConfig->channelId].CH_SNEBR = PSI5_CH_SNEBR_SnEBT(SnEBT_Value) | PSI5_CH_SNEBR_SLOT_NO(LastSlotId);
}

/**
 *
 * Function Name : Psi5_ConfigureChannel
 * Description   : Configures a single channel.
 *
 */
static void Psi5_ConfigureChannel(const Psi5_Ip_InstanceIdType instanceId,
                                  const Psi5_Ip_ChannelConfigType *chCfg
                                 )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instanceId];

    /* Set debug mode */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= PSI5_CH_PCCR_DEBUG_EN(((chCfg->debugEnable == TRUE) ? 1u : 0u)) | PSI5_CH_PCCR_DEBUG_FREEZE_CTRL(((chCfg->debugFreeze == TRUE) ? 1u : 0u));

    /* Configure Rx parameters */
    Psi5_Hw_ConfigureRx(instanceId, chCfg);

#if (STD_ON == PSI5_IP_DMA_IS_USED)
    /* Configure DMA */
    Psi5_Hw_ConfigureDma(instanceId, chCfg);
#endif

    /* Configure the Tx side */
    if (PSI5_SYNCHRONOUS == chCfg->channelMode)
    {
        /* Configure Tx mode */
        Psi5_Hw_ConfigureTx(instanceId, chCfg);

        /* Configure the pulse generator */
        Psi5_Hw_ConfigurePulseGenerator(instanceId, chCfg);
    }

    /* Configure interrupts */
    Psi5_Hw_EnableInterrupts(instanceId, chCfg, TRUE);
}

/**
 *
 * Function Name : Psi5_ConfigureChannels
 * Description   : Configures all the channels.
 *
 */
static void Psi5_ConfigureChannels(const Psi5_Ip_InstanceType *instance)
{
    /* For each channel configuration */
    for (uint32 chIdx = 0u; chIdx < instance->numOfChannels; chIdx++)
    {
        const Psi5_Ip_ChannelConfigType *chCfg = &(instance->channelConfig[chIdx]);

        /* Configure the pulse generator */
        Psi5_ConfigureChannel(instance->instanceId, chCfg);

        /* Configure the slots */
        Psi5_ConfigureSlots(instance->instanceId, chCfg);
    }

    /* Global Sync start */
    (void)Psi5_Hw_StartGlobalCtc(instance->instanceId, instance->globalCtcEn);
}

/**
 *
 * Function Name : Psi5_Hw_EnableInterrupts
 * Description   : Interrupt enabler
 *
 */
static void Psi5_Hw_EnableInterrupts(const Psi5_Ip_InstanceIdType instance,
                                     const Psi5_Ip_ChannelConfigType *chCfg,
                                     const boolean Enable
                                    )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[instance];
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[instance].chHwIdToIndexArrayConfig[chCfg->channelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[instance].channelConfig[arrayIndex]);
    const Psi5_Ip_ErrorSelectConfigType *errorSelect = config->errorSelectConfig;
    uint32 ErrorSelectBits;

    /* Clear interrupts flag */
    Psi5_Hw_ClearEvents(instance, chCfg->channelId);
    /* We need to enable ALL interrupts */
    if (Enable != (boolean)FALSE)
    {
        ErrorSelectBits = (uint32)((((errorSelect->errorSelect0 == FALSE) ? (uint32)0u : (uint32)1u) << PSI5_CH_PCCR_ERROR_SELECT0_SHIFT) |
                                   (((errorSelect->errorSelect1 == FALSE) ? (uint32)0u : (uint32)1u) << PSI5_CH_PCCR_ERROR_SELECT1_SHIFT) |
                                   (((errorSelect->errorSelect2 == FALSE) ? (uint32)0u : (uint32)1u) << PSI5_CH_PCCR_ERROR_SELECT2_SHIFT) |
                                   (((errorSelect->errorSelect3 == FALSE) ? (uint32)0u : (uint32)1u) << PSI5_CH_PCCR_ERROR_SELECT3_SHIFT) |
                                   (((errorSelect->errorSelect4 == FALSE) ? (uint32)0u : (uint32)1u) << PSI5_CH_PCCR_ERROR_SELECT4_SHIFT));
    }
    else
    {
        ErrorSelectBits = 0U;
    }
    
    /* Error interrupts */
    base->CHANNEL[chCfg->channelId].CH_PCCR |= ErrorSelectBits;

#if (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED)
    /* DMA interrupts (Only if DMA enabled) */
    if (NULL_PTR != chCfg->rxConfig->psi5DmaConfig)
    {
        base->CHANNEL[chCfg->channelId].CH_DCR = Enable ? base->CHANNEL[chCfg->channelId].CH_DCR | (PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK | PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_MASK | PSI5_CH_DCR_IE_DMA_PM_DS_UF_MASK) : base->CHANNEL[chCfg->channelId].CH_DCR & ~(PSI5_CH_DCR_IE_DMA_TF_PM_DS_MASK | PSI5_CH_DCR_IE_DMA_PM_DS_FIFO_FULL_MASK | PSI5_CH_DCR_IE_DMA_PM_DS_UF_MASK);

        /*Disable all RX interrupts*/
        base->CHANNEL[chCfg->channelId].CH_NDICR = 0U;
        base->CHANNEL[chCfg->channelId].CH_OWICR = 0U;
        base->CHANNEL[chCfg->channelId].CH_EICR  = 0U;

    }
    else
#endif
    {
        /*Enable PSI5 Rx interrupts */
        base->CHANNEL[chCfg->channelId].CH_NDICR = Enable ? PSI5_CH_NDICR_IE_ND(chCfg->rxConfig->watermarkInterruptLevel)   : 0U;
        base->CHANNEL[chCfg->channelId].CH_OWICR = Enable ? PSI5_CH_OWICR_IE_OW(chCfg->rxConfig->watermarkInterruptLevel)   : 0U;
        base->CHANNEL[chCfg->channelId].CH_EICR  = Enable ? PSI5_CH_EICR_IE_ERROR(chCfg->rxConfig->watermarkInterruptLevel) : 0U;
    }

#if (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED)
    if (NULL_PTR != chCfg->rxConfig->smcDmaConfig)
    {
        base->CHANNEL[chCfg->channelId].CH_DCR = Enable ? base->CHANNEL[chCfg->channelId].CH_DCR | (PSI5_CH_DCR_IE_DMA_TF_SF_MASK | PSI5_CH_DCR_IE_DMA_SFUF_MASK) : base->CHANNEL[chCfg->channelId].CH_DCR & ~(PSI5_CH_DCR_IE_DMA_TF_SF_MASK | PSI5_CH_DCR_IE_DMA_SFUF_MASK);
    }
#endif

}

/**
 *
 * Function Name : Psi5_Hw_ClearEvents
 * Description   : Clears all active events
 *
 */
static void Psi5_Hw_ClearEvents(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId
                               )
{
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[Psi5InstanceId];

#if (STD_ON == PSI5_IP_DMA_IS_USED)
    uint32 Ch_Dsr_Value = 0;

#if (STD_ON == PSI5_IP_DMA_PSI5_FRAME_IS_USED)
    Ch_Dsr_Value = PSI5_CH_DSR_IS_DMA_PM_DS_FIFO_FULL_MASK | PSI5_CH_DSR_IS_DMA_TF_PM_DS_MASK | PSI5_CH_DSR_IS_DMA_PM_DS_UF_MASK;
#endif

#if (STD_ON == PSI5_IP_DMA_SMC_FRAME_IS_USED)
    Ch_Dsr_Value |= PSI5_CH_DSR_IS_DMA_TF_SF_MASK | PSI5_CH_DSR_IS_DMA_SFUF_MASK;
#endif

    /* DMA flags */
    base->CHANNEL[Psi5ChannelId].CH_DSR = Ch_Dsr_Value;
#endif

    /* General flags */
    base->CHANNEL[Psi5ChannelId].CH_GISR = PSI5_CH_GISR_IS_CESM_MASK | PSI5_CH_GISR_IS_STS_MASK
                                          | PSI5_CH_GISR_IS_DTS_MASK | PSI5_CH_GISR_IS_DSROW_MASK
                                          | PSI5_CH_GISR_IS_BROW_MASK | PSI5_CH_GISR_IS_PROW_MASK
                                          | PSI5_CH_GISR_IS_OWSM_MASK | PSI5_CH_GISR_IS_NVSM_MASK;

    /* PSI5 status */
    base->CHANNEL[Psi5ChannelId].CH_NDSR = PSI5_CH_NDSR_NDS_MASK;
    base->CHANNEL[Psi5ChannelId].CH_OWSR = PSI5_CH_OWSR_OWS_MASK;
    base->CHANNEL[Psi5ChannelId].CH_EISR = PSI5_CH_EISR_ERROR_MASK;
}

/**
 *
 * Function Name : Psi5_Ip_IRQ_Handler
 * Description   : Gets called from the low level handler with instance and channel as parameter.
 *
 */
void Psi5_Ip_IRQ_Handler(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                         const Psi5_Ip_HwChannelIdType Psi5ChannelId
                        )
{
    Psi5_Ip_EventType Events;

    /*Clear all values*/
    Events.Psi5_Psi5MessageReceived         = FALSE;
    Events.Psi5_Psi5MessageOverwrite        = FALSE;
    Events.Psi5_Psi5MessageErrorsPresent    = FALSE;
    Events.Psi5_SmcMessageReceived          = FALSE;
    Events.Psi5_SmcMessageOverwrite         = FALSE;
    Events.Psi5_SmcMessageCRCError          = FALSE;
    Events.Psi5_TxDataOverwrite             = FALSE;
    Events.Psi5_DriverReadyToTransmit       = FALSE;
    Events.Psi5_Psi5DmaOverflow             = FALSE;
    Events.Psi5_Psi5DmaUnderflow            = FALSE;
    Events.Psi5_Psi5DmaTransferComplete     = FALSE;
    Events.Psi5_SmcDmaUnderflow             = FALSE;
    Events.Psi5_SmcDmaTransferComplete      = FALSE;

    Psi5_Hw_GetEvents(Psi5InstanceId, Psi5ChannelId, &Events);

    if(TRUE == Psi5_Ip_bDriverInitialized)
    {
        const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].chHwIdToIndexArrayConfig[Psi5ChannelId];
        const Psi5_Ip_ChannelConfigType * chCfg = &(Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].channelConfig[arrayIndex]);

        if(NULL_PTR != chCfg->callback)
        {
            chCfg->callback(Events);
        }
    }
}

/**
 *
 * Function Name : Psi5_Ip_Init
 * Description   : Initializes the driver for a given peripheral
 * according to the given configuration structure.
 *
 * Implements    : Psi5_Ip_Init_Activity
 */
void Psi5_Ip_Init(const Psi5_Ip_ConfigType *configPtr)
{
    uint8 instanceCnt = 0u;
    uint8 channelCnt = 0u;
    Psi5_Ip_pUsedConfig = configPtr;
    Psi5_Ip_bDriverInitialized =  TRUE;

    for (instanceCnt = 0u; instanceCnt < PSI5_INSTANCE_COUNT; instanceCnt++)
    {
        for (channelCnt = 0u; channelCnt < PSI5_CHANNEL_COUNT; channelCnt++)
        {
            Psi5_Ip_axMessages[instanceCnt][channelCnt].psi5CurrentIndex = 0xFFu;
            Psi5_Ip_axMessages[instanceCnt][channelCnt].smcCurrentIndex = 0xFFu;
        }
    }

    for (instanceCnt = 0u; instanceCnt < Psi5_Ip_pUsedConfig->numOfInstances; instanceCnt++)
    {
        const Psi5_Ip_InstanceType *cfgInstance = &(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt]);
        /* Enter configuration mode */
        Psi5_EnterConfigMode(cfgInstance);

        /* Configure channels */
        Psi5_ConfigureChannels(cfgInstance);

        /* Enter normal mode */
        Psi5_EnterNormalMode(cfgInstance);
    }
}

#if (STD_ON == PSI5_IP_GET_PSI5_FRAME_API)
/**
 *
 * Function Name : Psi5_Ip_GetPsi5Frame
 * Description   : Returns the last received PSI5 frame.
 *
 * Implements    : Psi5_Ip_GetPsi5Frame_Activity
 */
Std_ReturnType Psi5_Ip_GetPsi5Frame(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                    Psi5_Ip_Psi5FrameType *PsiFramePtr
                                   )
{
    Std_ReturnType ret;
    Psi5_Ip_RawFrameType Psi5_RawFrame;
    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].channelConfig[arrayIndex]);

    ret = Psi5_Hw_GetRawPsi5Frame(Psi5InstanceId, Psi5ChannelId, &Psi5_RawFrame);

    if ((Std_ReturnType)E_OK == ret)
    {
        const Psi5_Ip_SlotConfigType *slotStates = config->rxConfig->slotConfig;

        Psi5_Hw_ConvertRawPsi5Frame(PsiFramePtr, &Psi5_RawFrame, slotStates);
    }

    return ret;
}
#endif

#if (STD_ON == PSI5_IP_GET_SMC_FRAME_API)
/**
 *
 * Function Name : Psi5_Ip_GetSmcFrame
 * Description   : Returns the last received SMC frame.
 *
 * Implements    : Psi5_Ip_GetSmcFrame_Activity
 */
Std_ReturnType Psi5_Ip_GetSmcFrame(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                   const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                   Psi5_Ip_SmcFrameType *Psi5SmcFramePtr
                                  )
{
    Std_ReturnType ret;
    Psi5_Ip_RawFrameType Psi5_RawFrame;

    ret = Psi5_Hw_GetRawSmcFrame(Psi5InstanceId, Psi5ChannelId, &Psi5_RawFrame);

    if (ret == (Std_ReturnType)E_OK)
    {
        Psi5_Hw_ConvertRawSmcFrame(Psi5SmcFramePtr, &Psi5_RawFrame);
    }

    return ret;
}
#endif

/**
 *
 * Function Name : Psi5_Ip_DeInit
 * Description   : Stops the driver and resets the internal states.
 *
 * Implements    : Psi5_Ip_DeInit_Activity
 */
void Psi5_Ip_DeInit(void)
{
    uint8 instanceCnt;

    Psi5_Ip_bDriverInitialized = FALSE;

    for (instanceCnt = 0u; instanceCnt < Psi5_Ip_pUsedConfig->numOfInstances; instanceCnt++)
    {
        /* Put all channels in configuration mode */
        for (uint8 chIdx = 0u; chIdx < Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].numOfChannels; chIdx++)
        {
            const Psi5_Ip_ChannelConfigType *chCfg =  &(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].channelConfig[chIdx]);

            /* Disable the instance */
            Psi5_Hw_InstanceDisable(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, TRUE);

            /* Enter configuration mode */
            Psi5_Hw_EnterConfigMode(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, chCfg->channelId);

            /* Enable the instance */
            Psi5_Hw_InstanceDisable(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, FALSE);

            /* Disable interrupts */
            Psi5_Hw_EnableInterrupts(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, chCfg, FALSE);

            Psi5_Hw_ClearEvents(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, chIdx);
        }

        (void)Psi5_Hw_StartGlobalCtc(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, FALSE);

        /* Clear all registers */
        Psi5_Hw_ResetRegisters(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId);

        /* Disable the instance */
        Psi5_Hw_InstanceDisable(Psi5_Ip_pUsedConfig->instancesConfig[instanceCnt].instanceId, TRUE);
    }

    Psi5_Ip_pUsedConfig = NULL_PTR;
}

#if (STD_ON == PSI5_IP_TRANSMIT_API)
/**
 *
 * Function Name : Psi5_Ip_Transmit
 * Description   : Transmits a frame (standard or custom).
 *
 * Implements    : Psi5_Ip_Transmit_Activity
 */
Std_ReturnType Psi5_Ip_Transmit(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                const uint64 Psi5Data
                               )
{
    Std_ReturnType ret;

    const uint8 arrayIndex = Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].chHwIdToIndexArrayConfig[Psi5ChannelId];
    const Psi5_Ip_ChannelConfigType *config = &(Psi5_Ip_pUsedConfig->instancesConfig[Psi5InstanceId].channelConfig[arrayIndex]);

    /* Only if enabled */
    if (NULL_PTR != config->txConfig)
    {
        /* Check if ready for Tx */
        if (!Psi5_Hw_IsDataRegisterReady(Psi5InstanceId, Psi5ChannelId))
        {
            ret = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Write and trigger */
            PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[Psi5InstanceId];

            /* Enter critical region*/
            SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_00();

            if (PSI5_TX_MODE_7 == config->txConfig->txMode)
            {
                base->CHANNEL[Psi5ChannelId].CH_DSRH = (uint32)((Psi5Data >> 32u) & PSI5_CH_DSRH_DSR_MASK);
                base->CHANNEL[Psi5ChannelId].CH_DSRL = (uint32)(Psi5Data & PSI5_CH_DSRL_DSR_MASK);
                base->CHANNEL[Psi5ChannelId].CH_GISR |= PSI5_CH_GISR_DSR_RDY_MASK;
                /* Tx interrupts */
                if ((NULL_PTR != config->callback) && ((PSI5_SYNC_STATE_2 == config->txConfig->syncState) || (PSI5_SYNC_STATE_4 == config->txConfig->syncState)))
                {
                    base->CHANNEL[Psi5ChannelId].CH_GICR |= (PSI5_CH_GICR_IE_DSROW_MASK | PSI5_CH_GICR_IE_DSRR_MASK);
                }
            }
            else
            {
                base->CHANNEL[Psi5ChannelId].CH_DPRL = (uint32)(Psi5Data & PSI5_CH_DPRL_DPR_MASK);
                base->CHANNEL[Psi5ChannelId].CH_GISR |= PSI5_CH_GISR_DPR_RDY_MASK;
                /* Tx interrupts */
                if ((NULL_PTR != config->callback) && ((PSI5_SYNC_STATE_2 == config->txConfig->syncState) || (PSI5_SYNC_STATE_4 == config->txConfig->syncState)))
                {
                    base->CHANNEL[Psi5ChannelId].CH_GICR |= (PSI5_CH_GICR_IE_PROW_MASK | PSI5_CH_GICR_IE_PRR_MASK);
                }
            }
            /* Exit critical region*/
            SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_00();
            ret = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        ret = (Std_ReturnType)E_NOT_OK;
    }

    return ret;
}
#endif

#if (STD_ON == PSI5_IP_GET_TRANSMISSION_STATUS_API)
/**
 *
 * Function Name : Psi5_Ip_GetTransmissionStatus
 * Description   : Returns the status of the transmission part of the driver.
 *
 * Implements    : Psi5_Ip_GetTransmissionStatus_Activity
 */
boolean Psi5_Ip_GetTransmissionStatus(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                      const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                     )
{
    /* Status */
    return Psi5_Hw_IsDataRegisterReady(Psi5InstanceId, Psi5ChannelId);
}
#endif

#if (STD_ON == PSI5_IP_SET_GLOBAL_SYNC_API)
/**
 *
 * Function Name : Psi5_Ip_SetGlobalSync
 * Description   : Sets the global Pulse Generator state.
 *
 * Implements    : Psi5_Ip_SetGlobalSync_Activity
 */
Std_ReturnType Psi5_Ip_SetGlobalSync(const uint8 Psi5InstanceId,
                                     const boolean PsiState
                                    )
{
    Std_ReturnType retVal;
    /* Enter critical region */
    SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_03();

    retVal = Psi5_Hw_StartGlobalCtc((Psi5InstanceId == 0U) ? PSI5_INSTANCE0 : PSI5_INSTANCE1, PsiState);

    /* Exit critical region*/
    SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_03();

    return retVal;
}
#endif

#if (STD_ON == PSI5_IP_SET_CHANNEL_SYNC_API)
/**
 *
 * Function Name : Psi5_Ip_SetChannelSync
 * Description   : Sets the local (Psi5ChannelId) Pulse Generator state.
 *
 * Implements    : Psi5_Ip_SetChannelSync_Activity
 */
Std_ReturnType Psi5_Ip_SetChannelSync(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                      const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                      const boolean PsiState
                                     )
{
    Std_ReturnType ret = (Std_ReturnType)E_NOT_OK;
    /* Enable the local CTC */
    PSI5_MemMapPtr base = Psi5_Ip_axBaseAddresses[Psi5InstanceId];

    /* Enter critical region */
    SchM_Enter_Psi5_PSI5_EXCLUSIVE_AREA_04();

    if (0u == (base->CHANNEL[Psi5ChannelId].CH_PCCR & PSI5_CH_PCCR_CTC_GED_SEL_MASK))
    {
        base->CHANNEL[Psi5ChannelId].CH_PCCR = PsiState ? (base->CHANNEL[Psi5ChannelId].CH_PCCR | PSI5_CH_PCCR_CTC_ED_MASK) : (base->CHANNEL[Psi5ChannelId].CH_PCCR & ~PSI5_CH_PCCR_CTC_ED_MASK);

        ret = (Std_ReturnType)E_OK;
    }

    /* Exit critical region*/
    SchM_Exit_Psi5_PSI5_EXCLUSIVE_AREA_04();

    return ret;
}
#endif

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
