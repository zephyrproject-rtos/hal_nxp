/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *     @file       File with source code used to implement ICU driver functionality on EMIOS module.
 *     @details    This file contains the source code for all functions which are using EMIOS module.
 *     @addtogroup emios_icu_ip EMIOS IPL
 *     @{
 */
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Icu_Ip.h"
#include "SchM_Icu.h"

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
        #include "Devassert.h"
    #endif

    #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        #include "Dma_Ip.h"
    #endif

#endif  /* EMIOS_ICU_IP_USED */
/*==================================================================================================
*                                        SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_VENDOR_ID_C                       43
#define EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_ICU_IP_SW_MAJOR_VERSION_C                2
#define EMIOS_ICU_IP_SW_MINOR_VERSION_C                0
#define EMIOS_ICU_IP_SW_PATCH_VERSION_C                1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
            /* Check if header file and Dma_Ip.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                 (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION_C != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip.c and Dma_Ip.h are different"
            #endif
        #endif
    #endif  /* EMIOS_ICU_IP_USED */

    /* Check if this source file and SchM_Icu.h file are of the same Autosar version */
    #if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip.c and SchM_Icu.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (EMIOS_ICU_IP_VENDOR_ID_C != EMIOS_ICU_IP_VENDOR_ID)
    #error "Emios_Icu_Ip.c and Emios_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and Emios_Icu_Ip header file are of the same Autosar version */
#if (  (EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
       (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
       (EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip.c and Emios_Icu_Ip.h are different"
#endif
/* Check if source file and Icu_eMIOS header file are of the same Software version */
#if ((EMIOS_ICU_IP_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_SW_MAJOR_VERSION) || \
        (EMIOS_ICU_IP_SW_MINOR_VERSION_C != EMIOS_ICU_IP_SW_MINOR_VERSION) || \
        (EMIOS_ICU_IP_SW_PATCH_VERSION_C != EMIOS_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip.c and Emios_Icu_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if(EMIOS_ICU_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip.c and Devassert.h are different"
            #endif
        #endif
    #endif  /* EMIOS_ICU_IP_USED */
#endif
/*==================================================================================================
*                                           LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_BOOLEAN
#endif
#include "Icu_MemMap.h"

/* State of initialized EMIOS modules. */
static boolean eMios_Icu_Ip_bInstanceState[EMIOS_ICU_IP_INSTANCE_COUNT];

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_BOOLEAN
#endif
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"
#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
/**
* @brief      eMios_Icu_Ip_u8NumOvflByCounterBus
* @details    The number of active channels has the overflow notification function using masterbus.
*/
static uint8 eMios_Icu_Ip_u8NumOvflByCounterBus[EMIOS_ICU_IP_INSTANCE_COUNT][EMIOS_ICU_IP_NUM_OF_CHANNELS];
#endif /* EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON */
#endif /* ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON)) */
#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_8
#endif
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
static uint32 eMios_Icu_Ip_u32aEdgeCurrent_Value[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
#endif /* EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON */

#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
/** @brief Array for saving value of DMA **/
volatile uint32 Emios_Icu_Ip_aDmaBuffer[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED][EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT];

/** @brief Array for saving the period */
volatile uint32 Emios_Icu_Ip_aIsSecondInterrupt[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

/** @brief Array for saving the period */
volatile uint32 Emios_Icu_Ip_aFirstEdgeTimeStamp[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

#endif /* EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL */

#define ICU_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Icu_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
/* Table of base addresses for EMIOS instances. */
eMIOS_Type * const s_emiosBase[] = IP_eMIOS_BASE_PTRS;
#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
eMios_Icu_Ip_MeasStatusType eMios_Icu_Ip_aeInt_Counter[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
eMios_Icu_ValueType eMios_Icu_Ip_auCapturedActivePulseWidth[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
eMios_Icu_ValueType eMios_Icu_Ip_auTimeStart[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
eMios_Icu_ValueType eMios_Icu_Ip_auBufferPtr[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
#endif /* EMIOS_ICU_IP_TIMESTAMP_API == STD_ON */

eMios_Icu_Ip_ChStateType eMios_Icu_Ip_axChState[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
eMios_Icu_Ip_WsChStateType eMios_Icu_Ip_axWsChState[EMIOS_ICU_IP_INSTANCE_COUNT][EMIOS_ICU_IP_WSC_NUM_OF_CHANNELS];
    #endif
#endif
#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"
/* This array stores the positions in the eMios_Icu_Ip_axChState array of the configured eMios channels. */
uint8 eMios_Icu_Ip_u8IndexInChState[EMIOS_ICU_IP_INSTANCE_COUNT][EMIOS_ICU_IP_NUM_OF_CHANNELS] = EMIOS_ICU_IP_INITIAL_INDEX_OF_CHANNELS;
#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief      Icu driver function that sets the channel prescaler.
 * @details    This function:
 *             - Writes prescaling rate at UCPRE[0:1] bits in EMIOSC[n] register
 *             - Enables channel prescaler by setting UCPREN bit in EMIOSC[n] register
 *
 * @param[in]  instance                - eMIOS module index
 * @param[in]  hwChannel               - eMIOS encoded hardware channel
 * @param[in]  u32ChannelPrescaler     - prescaler for the hardware channel
 */
static inline void Emios_Icu_Ip_SetPrescaler
(
    const uint8 instance,
    const uint8 hwChannel,
    const uint32 u32ChannelPrescaler
);
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
/**
* @brief      Icu driver function that enable the master buses Interrupt.
* @details    This function:
*             - Only using for the following functions:
*                   - Emios_Icu_Ip_StartSignalMeasurement: Used for enable master buses interrupt that hwChannel uses as an overflow notification.
*                   - Emios_Icu_Ip_StartTimestamp: Used for enable master buses interrupt that hwChannel uses as an overflow notification.
*
* @param[in]  instance        - eMIOS module index
* @param[in]  hwChannel       - eMIOS encoded hardware channel using master bus
* @api
*/
static inline void Emios_Icu_Ip_EnableMasterBusInterrupt
(
    const uint8 instance,
    const uint8 hwChannel
);

/**
* @brief      Icu driver function that disable the master buses Interrupt.
* @details    This function:
*             - Only using for the following functions:
*                   - Emios_Icu_Ip_StartSignalMeasurement: Used for disable master buses interrupt that hwChannel uses as an overflow notification.
*                   - Emios_Icu_Ip_StartTimestamp: Used for disable master buses interrupt that hwChannel uses as an overflow notification.
*
* @param[in]  instance        - eMIOS module index
* @param[in]  hwChannel       - eMIOS encoded hardware channel using master bus
* @api
*/
static inline void Emios_Icu_Ip_DisableMasterBusInterrupt
(
    const uint8 instance,
    const uint8 hwChannel
);
#endif /* EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON */
#endif

/**
* @brief      Emios_Icu_Ip_UCSetMode
* @details    This function sets CCR_MODE bitfield, the mode of operation of the Unified Channel
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - eMIOS Channel index
* @param[in]  u32Mode   - CCR_MODE bitfield value to be set
* @api
*/
static inline void Emios_Icu_Ip_UCSetMode
(
    const uint8 instance,
    const uint8 hwChannel,
    const uint32 u32Mode
);

/**
* @brief   Function to return the channel id of master bus of current channel
* @details Function to return the channel id of master bus of current channel
* @param[in]  hwChannel - eMIOS Channel index
* @param[in]  u32Bus    - the used bus for current channels
* @param[out] - The id of master bus
*/
static inline uint8 Emios_Icu_Ip_GetMasterBus
(
    uint8 hwChannel,
    eMios_Icu_Ip_BusType u32Bus
);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static inline void Emios_Icu_Ip_UCSetMode(const uint8 instance,
                                          const uint8 hwChannel,
                                          const uint32 u32Mode)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_48();
    /* Clear MODE bitfield - GPIO mode */
    s_emiosBase[instance]->CH.UC[hwChannel].C &= ~eMIOS_C_MODE_MASK;
    /* Set desired mode */
    s_emiosBase[instance]->CH.UC[hwChannel].C |= (u32Mode & eMIOS_C_MODE_MASK);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_48();
}

static inline uint8 Emios_Icu_Ip_GetMasterBus(uint8 hwChannel,
                                              eMios_Icu_Ip_BusType u32Bus)
{
    uint8 u8MasterBusChannelIdx = (uint8)0U;

    if (EMIOS_ICU_BUS_DIVERSE == u32Bus)
    {
        if (EMIOS_ICU_IP_CHANNEL_7 >= hwChannel) /* bus B */
        {
            u8MasterBusChannelIdx = EMIOS_ICU_IP_CHANNEL_0;
        }
        else if (EMIOS_ICU_IP_CHANNEL_15 >= hwChannel) /* Bus C */
        {
            u8MasterBusChannelIdx = EMIOS_ICU_IP_CHANNEL_8;
        }
        else if (EMIOS_ICU_IP_CHANNEL_23 >= hwChannel) /* bus D */
        {
            u8MasterBusChannelIdx = EMIOS_ICU_IP_CHANNEL_16;
        }
        else
        {
            /* Bus E remaining */
            u8MasterBusChannelIdx = EMIOS_ICU_IP_CHANNEL_24;
        }
    }
    else if (EMIOS_ICU_BUS_A == u32Bus) /* bus A */
    {
        u8MasterBusChannelIdx = EMIOS_ICU_IP_CHANNEL_23;
    }
    else
    {
        /*Empty else to fix misra*/
    }

    return u8MasterBusChannelIdx;
}

#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
static inline void Emios_Icu_Ip_SetPrescaler(const uint8 instance,
                                             const uint8 hwChannel,
                                             const uint32 u32ChannelPrescaler)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_53();

    /* Clear UCPREN bit */
    s_emiosBase[instance]->CH.UC[hwChannel].C &= ~eMIOS_C_UCPREN_MASK;
    /* Write prescaling rate at UCEXTPRE[0:3] bits in EMIOSC2[n] */
    s_emiosBase[instance]->CH.UC[hwChannel].C2 &= ~eMIOS_C2_UCEXTPRE_MASK;

    s_emiosBase[instance]->CH.UC[hwChannel].C2 |= eMIOS_C2_UCEXTPRE(u32ChannelPrescaler);
    /* Enable channel prescaler */
    s_emiosBase[instance]->CH.UC[hwChannel].C |= eMIOS_C_UCPREN_MASK;

    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_53();
}
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
static inline void Emios_Icu_Ip_EnableMasterBusInterrupt(const uint8 instance,
                                                         const uint8 hwChannel)
{
    uint8      nMasterBusHwChannel;

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        nMasterBusHwChannel = Emios_Icu_Ip_GetMasterBus(hwChannel, eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected);
        if (nMasterBusHwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS)
        {
            if((uint8)0U == eMios_Icu_Ip_u8NumOvflByCounterBus[instance][nMasterBusHwChannel])
            {
                /* Clear pending interrupts */
                s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);
                /* Enable Interrupt for master bus*/
                Emios_Icu_Ip_EnableInterrupt(instance, nMasterBusHwChannel);
            }
            eMios_Icu_Ip_u8NumOvflByCounterBus[instance][nMasterBusHwChannel]++;
        }
    }
}

static inline void Emios_Icu_Ip_DisableMasterBusInterrupt(const uint8 instance,
                                                          const uint8 hwChannel)
{
    uint8      nMasterBusHwChannel;

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        nMasterBusHwChannel = Emios_Icu_Ip_GetMasterBus(hwChannel, eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected);
        if (nMasterBusHwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS)
        {
            eMios_Icu_Ip_u8NumOvflByCounterBus[instance][nMasterBusHwChannel]--;
            if((uint8)0U == eMios_Icu_Ip_u8NumOvflByCounterBus[instance][nMasterBusHwChannel])
            {
                /* Disable Interrupt for master bus*/
                Emios_Icu_Ip_DisableInterrupt(instance, nMasterBusHwChannel);
            }
        }
    }
}
#endif /* EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON */
#endif /* (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/** @implements Emios_Icu_Ip_EnableInterrupt_Activity */
void Emios_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel)
{
    /* Clear pending flag */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= eMIOS_S_FLAG_MASK;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_46();
    /* Enable interrupt */
    s_emiosBase[instance]->CH.UC[hwChannel].C |= eMIOS_C_FEN_MASK;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_46();
}

/** @implements Emios_Icu_Ip_DisableInterrupt_Activity */
void Emios_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_47();
    /* Disable interrupt */
    s_emiosBase[instance]->CH.UC[hwChannel].C &= ~eMIOS_C_FEN_MASK;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_47();
}

/* @implements Emios_Icu_Ip_Init_Activity */
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Init(uint8 instance, const eMios_Icu_Ip_ConfigType *userConfig)
{
    uint8                       hwChannel;
    uint32                      u32RegCCR;
    uint8                       u8MasterBusMode[EMIOS_ICU_IP_NUM_OF_CHANNELS];
    uint8                       index;
    uint8                       u8MasterBusChannelIdx;
    eMios_Icu_Ip_StatusType     retStatus   = EMIOS_IP_STATUS_SUCCESS;
#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
    uint32                      wsRegisterValue;
    uint32                      wsInputFilter;
    #endif /* EMIOS_ICU_IP_WSC_SUPPORT */
#endif /* defined EMIOS_ICU_IP_WSC_SUPPORT */

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(userConfig != NULL_PTR);
#endif
    if (FALSE == eMios_Icu_Ip_bInstanceState[instance])
    {
        eMios_Icu_Ip_bInstanceState[instance] = TRUE;

        if (userConfig->nNumChannels > 0U)
        {
            for (index=0U; index < EMIOS_ICU_IP_NUM_OF_CHANNELS; index++)
            {
                if (eMios_Icu_Ip_u8IndexInChState[instance][index] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED)
                {
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][index]].channelsInitState = FALSE;
                }
                u8MasterBusMode[index] = EMIOS_ICU_IP_CB_NONE;
            }

            for (index=0U; index < userConfig->nNumChannels; index++)
            {
                hwChannel   = (*userConfig->pChannelsConfig)[index].hwChannel;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelsInitState = TRUE;

                /* Initialize the state for calling user notification - can be HLD or IPL direct user notification */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification = (*userConfig->pChannelsConfig)[index].eMiosChannelNotification;

                /* Take HLD callback pointer and logic channel and store them in state configuration. */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosOverflowNotification = (*userConfig->pChannelsConfig)[index].eMiosOverflowNotification;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callback      = (*userConfig->pChannelsConfig)[index].callback;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].logicChStateCallback = (*userConfig->pChannelsConfig)[index].logicChStateCallback;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callbackParam = (*userConfig->pChannelsConfig)[index].callbackParams;

                /* Set the event which will generate the interrupt */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].edgeTrigger   = (*userConfig->pChannelsConfig)[index].edgeAlignement;

                /* Clear channel config for hwChannel */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_NO_MEASUREMENT;
#if (defined(EMIOS_ICU_IP_EDGE_COUNT_API) && (STD_ON == EMIOS_ICU_IP_EDGE_COUNT_API))
#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].maxCounterValue = EMIOS_ICU_IP_INIT_CADR_U32;
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */
#endif /* (defined(EMIOS_ICU_IP_EDGE_COUNT_API) && (STD_ON == EMIOS_ICU_IP_EDGE_COUNT_API)) */

#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API)
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement = EMIOS_ICU_NO_MEASUREMENT;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod = (uint16)0U;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = (uint16)0U;
#endif
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
    #if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
                /* Reset aBufferPtr */
                eMios_Icu_Ip_auBufferPtr[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = 0U;
    #endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer = NULL_PTR;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize = (uint16)0U;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify = (uint16)0U;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount = (uint16)0U;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex = (uint16)0U;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType = (*userConfig->pChannelsConfig)[index].timestampBufferType;
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API) */
#if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel =  (*userConfig->pChannelsConfig)[index].dmaChannel;
#endif

#if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
                /* Enable EMIOS Channel. */
                Emios_Mcl_Ip_EnableChannel(instance, hwChannel);
#endif

                /* Enter GPIO Mode to Configure Channel */
                /* Reset mode for selected channel */
                s_emiosBase[instance]->CH.UC[hwChannel].C = EMIOS_ICU_IP_CCR_CLEAR_U32;

                /* Initialize channel filter, filter clock selection, freeze enable and bus select and disable the
                * Set Default Edge (included)
                */
                u32RegCCR = eMIOS_C_UCPREN_MASK;
                u32RegCCR |= eMIOS_C_FREN(((*userConfig->pChannelsConfig)[index].FreezeEn)?1U:0U);
                u32RegCCR |= eMIOS_C_IF((*userConfig->pChannelsConfig)[index].Filter);
                u32RegCCR |= eMIOS_C_FCK(((*userConfig->pChannelsConfig)[index].filterClock)?1U:0U);
                u32RegCCR |= eMIOS_C_BSL((*userConfig->pChannelsConfig)[index].CntBus);

                s_emiosBase[instance]->CH.UC[hwChannel].C |= u32RegCCR;

                /* Initialize prescaler value */
                s_emiosBase[instance]->CH.UC[hwChannel].C2 &= ~eMIOS_C2_UCEXTPRE_MASK;
                s_emiosBase[instance]->CH.UC[hwChannel].C2 |= eMIOS_C2_UCEXTPRE((*userConfig->pChannelsConfig)[index].Prescaler);

                /* Disable interrupt */
                Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

                /* Clear pending interrupt flag (and other flags) for the channel */
                s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);

                Emios_Icu_Ip_SetActivation( instance, hwChannel, eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].edgeTrigger);

                /* Set Configuration for hwChannel */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaMode = (*userConfig->pChannelsConfig)[index].chSubMode;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].operationMode = (*userConfig->pChannelsConfig)[index].ucMode;
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].msWithoutInterrupt = (*userConfig->pChannelsConfig)[index].bWithoutInterrupt;
        #if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API)
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement = (*userConfig->pChannelsConfig)[index].measurementMode;
        #endif
                /* Store bus select of hwChannel */
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected = (*userConfig->pChannelsConfig)[index].CntBus;

                if (EMIOS_ICU_BUS_INTERNAL_COUNTER != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
                {
                    u8MasterBusChannelIdx = (uint8)Emios_Icu_Ip_GetMasterBus(hwChannel, eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected);
                    if(EMIOS_ICU_IP_CB_NONE == u8MasterBusMode[u8MasterBusChannelIdx]) /* This master bus have not been configured*/
                    {
                        /* store master bus mode and master bus pre-scaler*/
                        u8MasterBusMode[u8MasterBusChannelIdx] = (uint8)EMIOS_ICU_IP_MCB_INT_CLOCK_U32;
                        eMios_Icu_Ip_u8IndexInChState[instance][u8MasterBusChannelIdx] = EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED;
#if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
                        /* Enable EMIOS Channel to make registers write-able. */
                        Emios_Mcl_Ip_EnableChannel(instance, hwChannel);
#endif
                    }
                }
            }

            /* configuration for master bus */
            for (index=0U; index < EMIOS_ICU_IP_NUM_OF_CHANNELS; index++)
            {
                if(EMIOS_ICU_IP_CB_NONE != u8MasterBusMode[index]) /* Master bus is used */
                {
#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
                    /* Reset the number of active channels has the overflow notification function using masterbus. */
                    eMios_Icu_Ip_u8NumOvflByCounterBus[instance][index] = 0;
#endif
#endif
                }
            }
        }
#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
        if (userConfig->nNumWsChannels > 0U)
        {
            for (index=0U; index < userConfig->nNumWsChannels; index++)
            {
                hwChannel = (*userConfig->pWSChannelsConfig)[index].HwWsChannel;

                /* Disable mode */
                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC1 &= ~eMIOS_WSC1_MODE_MASK;

                wsRegisterValue = 0U;
                wsInputFilter   = (uint32)(*userConfig->pWSChannelsConfig)[index].WscInputFilter;
                wsRegisterValue |= eMIOS_WSC1_FREN((*userConfig->pWSChannelsConfig)[index].FreezeEn  ? 1U : 0U);
                wsRegisterValue |= eMIOS_WSC1_FCK((*userConfig->pWSChannelsConfig)[index].FilterClockScr  ? 1U : 0U);
                wsRegisterValue |= eMIOS_WSC1_IF4_7((wsInputFilter & 0xF0U) >> 4U);
                wsRegisterValue |= eMIOS_WSC1_IF0_3(wsInputFilter & 0x0FU);
                wsRegisterValue |= eMIOS_WSC1_BSL((*userConfig->pWSChannelsConfig)[index].WscBusSelect);
                wsRegisterValue |= (uint32)((*userConfig->pWSChannelsConfig)[index].CapEdgeDetect) << eMIOS_WSC1_EDPOLCAP_SHIFT;
                wsRegisterValue |= eMIOS_WSC1_CPREN(1U);
                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC1 = wsRegisterValue;

                wsRegisterValue = 0U;
                wsRegisterValue |= (uint32)((*userConfig->pWSChannelsConfig)[index].PwEdgeDetect) << eMIOS_WSC2_EDPOLPW_SHIFT;
                wsRegisterValue |= eMIOS_WSC2_WSPREMODE((*userConfig->pWSChannelsConfig)[index].IntPrescalerMode  ? 1U : 0U);
                wsRegisterValue |= eMIOS_WSC2_WSPRE((*userConfig->pWSChannelsConfig)[index].IntPrescaler);
                wsRegisterValue |= eMIOS_WSC2_PWREN((*userConfig->pWSChannelsConfig)[index].ResetCnt  ? 1U : 0U);
                wsRegisterValue |= eMIOS_WSC2_PWSWR(1U);
                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC2 = wsRegisterValue;

                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSEV |= eMIOS_WSEV_EVENT((*userConfig->pWSChannelsConfig)[index].WscNumEvent);

                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSFC |= eMIOS_WSFC_FOOE((*userConfig->pWSChannelsConfig)[index].FiFoOverwrite  ? 1U : 0U);

                /* Set mode */
                s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC1 |= eMIOS_WSC1_MODE((*userConfig->pWSChannelsConfig)[index].WsChannelMode);

                eMios_Icu_Ip_axWsChState[instance][hwChannel].WsCAPNotification = (*userConfig->pWSChannelsConfig)[index].WsCAPNotification;
                eMios_Icu_Ip_axWsChState[instance][hwChannel].WsCENotification = (*userConfig->pWSChannelsConfig)[index].WsCENotification;
                eMios_Icu_Ip_axWsChState[instance][hwChannel].WsCEONotification = (*userConfig->pWSChannelsConfig)[index].WsCEONotification;
                eMios_Icu_Ip_axWsChState[instance][hwChannel].WsPWONotification = (*userConfig->pWSChannelsConfig)[index].WsPWONotification;
                eMios_Icu_Ip_axWsChState[instance][hwChannel].WsPWNotification = (*userConfig->pWSChannelsConfig)[index].WsPWNotification;
                eMios_Icu_Ip_axWsChState[instance][hwChannel].EnableInterruptStatus = 0U;
            }
        }
    #endif /* EMIOS_ICU_IP_WSC_SUPPORT */
#endif /* defined EMIOS_ICU_IP_WSC_SUPPORT */
    }
    else
    {
        /* Module already initialized - use de-initialize first */
        retStatus = EMIOS_IP_STATUS_ERROR;
    }
    return retStatus;
}

#if (EMIOS_ICU_IP_DEINIT_API == STD_ON)
/* @implements Emios_Icu_Ip_Deinit_Activity */
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Deinit(uint8 instance)
{
    eMios_Icu_Ip_ModeType       nMeasMode;
    uint8                       hwChannel;

    eMios_Icu_Ip_StatusType     retStatus   = EMIOS_IP_STATUS_SUCCESS;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
#endif

    if (TRUE == eMios_Icu_Ip_bInstanceState[instance])
    {
        eMios_Icu_Ip_bInstanceState[instance] = FALSE;

        for (hwChannel = 0U; hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS; hwChannel++)
        {
            if (eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED)
            {
                if (TRUE == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelsInitState)
                {
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelsInitState = FALSE;

                    nMeasMode = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode;

                    /* Set all channel registers as after reset */
                    s_emiosBase[instance]->CH.UC[hwChannel].C = EMIOS_ICU_IP_CCR_CLEAR_U32;
                    s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_CCR_CLEAR_U32;

                    switch (nMeasMode)
                    {
                        case EMIOS_ICU_MODE_SIGNAL_MEASUREMENT:
                        {
                            s_emiosBase[instance]->CH.UC[hwChannel].B = EMIOS_ICU_IP_CCR_CLEAR_U32;
                        }
                        break;

                        case EMIOS_ICU_MODE_EDGE_COUNTER:
                        {
                            s_emiosBase[instance]->CH.UC[hwChannel].CNT = EMIOS_ICU_IP_CCR_CLEAR_U32;
                        }
                        break;

                        default:
                        {
                            /*For Misra Compliance*/
                        }
                        break;
                    }
                    /* Clear CSR register */
                    s_emiosBase[instance]->CH.UC[hwChannel].S = EMIOS_ICU_IP_CSR_CLEAR_U32;

#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
                    /* Clear all aEdgeCurrent_Value */
                    eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = (uint32)(0x0U);
#endif /* EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON */

                    /* if channel using master bus, so de-init for master bus */
                    if (EMIOS_ICU_BUS_INTERNAL_COUNTER != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
                    {
#if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
                        /* Disable eMIOS Channel */
                        Emios_Mcl_Ip_DisableChannel(instance, hwChannel);
#endif
                    }
                    /* Clear config for hardware channel */
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].operationMode = EMIOS_ICU_UNINIT;
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected   = EMIOS_ICU_BUS_INTERNAL_COUNTER;
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode   = EMIOS_ICU_MODE_NO_MEASUREMENT;
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API)
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement   = EMIOS_ICU_NO_MEASUREMENT;
#endif
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API)
                    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType = EMIOS_ICU_NO_TIMESTAMP;
#endif
                }
            }
            if (EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED == eMios_Icu_Ip_u8IndexInChState[instance][hwChannel])
            {
                eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] = EMIOS_ICU_IP_CHANNEL_NOT_USED;
            }
        }
#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
        for (hwChannel = 0U; hwChannel < EMIOS_ICU_IP_WSC_NUM_OF_CHANNELS; hwChannel ++)
        {
            /* Disable mode */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC1 &= ~eMIOS_WSC1_MODE_MASK;
            /* Clear event counter */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSCAEC &= ~eMIOS_WSCAEC_EVCNT_MASK;
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSEV  = 0U;
            /* Disable channel pre-scaler and Pulse Width Detection Edge */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC2 = 0U;
            /* Clear FIFO Overflow Overwrite */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSFC &= ~eMIOS_WSFC_FOOE_MASK;
            /* Reset WSC Control 1 */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSC1 = 0U;
            /* Clears all data stored in the FIFO */
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSFC |= eMIOS_WSFC_CLRF(1U);
            /* Clear pulse width count.*/
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSPWCNT &= ~eMIOS_WSPWCNT_T16PWCNT_MASK;
            /* Clear all flags.*/
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSS |= (eMIOS_WSS_FLAGCEC(1U) | eMIOS_WSS_FLAGECOC(1U) | eMIOS_WSS_FLAGPWC(1U) | eMIOS_WSS_FLAGCAPC(1U) | eMIOS_WSS_FLAGPWOC(1U) | eMIOS_WSS_FLAGFFC(1U));
            /* Clear all Overrun flags.*/
            s_emiosBase[instance]->CH.WSC[hwChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET].WSS |= (eMIOS_WSS_OVRCEC(1U) | eMIOS_WSS_OVRECOC(1U) | eMIOS_WSS_OVRPWC(1U) | eMIOS_WSS_OVRCAPC(1U) | eMIOS_WSS_OVRPWOC(1U));

            eMios_Icu_Ip_axWsChState[instance][hwChannel].EnableInterruptStatus = 0U;
        }
    #endif /* EMIOS_ICU_IP_WSC_SUPPORT */
#endif /* defined EMIOS_ICU_IP_WSC_SUPPORT */
    }
    else
    {
        /* Module already de-init - use init first */
        retStatus = EMIOS_IP_STATUS_ERROR;
    }
    return retStatus;
}
#endif

/* @implements Emios_Icu_Ip_SetActivation_Activity */
void Emios_Icu_Ip_SetActivation(uint8 instance, uint8 hwChannel, eMios_Icu_Ip_EdgeType edge)
{
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
    uint32 u32RegEmiosCCR;
#endif  /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_50();
    switch (edge)
    {
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
        case EMIOS_OPPOSITE_EDGES:
        {
            u32RegEmiosCCR = s_emiosBase[instance]->CH.UC[hwChannel].C;
            s_emiosBase[instance]->CH.UC[hwChannel].C = (u32RegEmiosCCR ^ eMIOS_C_EDPOL_MASK);
        }
        break;
#endif  /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */

        case EMIOS_ICU_BOTH_EDGES:
        {
            s_emiosBase[instance]->CH.UC[hwChannel].C |= eMIOS_C_EDSEL_MASK;
        }
        break;

        case EMIOS_ICU_RISING_EDGE:
        {
            s_emiosBase[instance]->CH.UC[hwChannel].C &= ~eMIOS_C_EDSEL_MASK;
            s_emiosBase[instance]->CH.UC[hwChannel].C |= eMIOS_C_EDPOL_MASK;
        }
        break;

        default:
        {
            /* EMIOS_ICU_FALLING_EDGE */
            s_emiosBase[instance]->CH.UC[hwChannel].C &= ~(eMIOS_C_EDSEL_MASK|eMIOS_C_EDPOL_MASK);
        }
        break;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_50();
}

#if (EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON)
/* @implements Emios_Icu_Ip_EnableEdgeDetection_Activity */
void Emios_Icu_Ip_EnableEdgeDetection(uint8 instance, uint8 hwChannel)
{

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

#if (EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT == STD_ON)
    /* Enable SAIC with edge capturing mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_EDGE_CAPTURING_U32);
#else
    /* Enable SAIC mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_U32);
#endif

    /* Enable Interrupt */
    Emios_Icu_Ip_EnableInterrupt(instance, hwChannel);

    /* Set Channel Config */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_SIGNAL_EDGE_DETECT;

#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Enable Interrupt for masterbus*/
    Emios_Icu_Ip_EnableMasterBusInterrupt(instance, hwChannel);
#endif
}

/* @implements Emios_Icu_Ip_DisableEdgeDetection_Activity */
void Emios_Icu_Ip_DisableEdgeDetection(uint8 instance, uint8 hwChannel)
{

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Clear Channel Config */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_NO_MEASUREMENT;

#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Interrupt for masterbus*/
    Emios_Icu_Ip_DisableMasterBusInterrupt(instance, hwChannel);
#endif
}
#endif /* EMIOS_ICU_IP_EDGE_DETECT_API */

/* @implements Emios_Icu_Ip_EnableNotification_Activity */
void Emios_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel)
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].notificationEnable =  TRUE;
}

/* @implements Emios_Icu_Ip_DisableNotification_Activity */
void Emios_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel)
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].notificationEnable =  FALSE;
}

#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
/* @implements Emios_Icu_Ip_StartTimestamp_Activity */
void Emios_Icu_Ip_StartTimestamp(uint8 instance,
                                 uint8 hwChannel,
                                 eMios_Icu_ValueType * bufferPtr,
                                 uint16 bufferSize,
                                 uint16 notifyInterval
                                )
{
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
        Dma_Ip_LogicChannelTransferListType global_DmaChannelTransferList[11U];
#endif /* (EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL == STD_ON) */

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_51();
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer = bufferPtr;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize = bufferSize;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify = notifyInterval;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount = (uint16)0U;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex = (uint16)0U;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_51();

    /* Reset aBufferPtr */
    eMios_Icu_Ip_auBufferPtr[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = 0U;

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
    /* Setup DMA in Dma_Ip*/
    if (0xFFU != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel)
    {
        /* Create the desired configuration list. */
        global_DmaChannelTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        global_DmaChannelTransferList[0U].Value = Emios_Icu_Ip_GetStartAddress(instance, hwChannel);
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe.
         * The application should ensure that only addresses that fit in uint32 are used for configuring DMA. */
        global_DmaChannelTransferList[1U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        global_DmaChannelTransferList[1U].Value = (uint32)bufferPtr;
        global_DmaChannelTransferList[2U].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        global_DmaChannelTransferList[2U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_DmaChannelTransferList[3U].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        global_DmaChannelTransferList[3U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_DmaChannelTransferList[4U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        global_DmaChannelTransferList[4U].Value = (uint32)0U;
        global_DmaChannelTransferList[5U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        global_DmaChannelTransferList[5U].Value = (uint32)4U;
        global_DmaChannelTransferList[6U].Param = DMA_IP_CH_SET_SOURCE_MODULO;
        global_DmaChannelTransferList[6U].Value = (uint32)0U;
        global_DmaChannelTransferList[7U].Param = DMA_IP_CH_SET_DESTINATION_MODULO;
        global_DmaChannelTransferList[7U].Value = (uint32)0U;

        if ((notifyInterval >= bufferSize) || (notifyInterval == (uint16)0))
        {
            global_DmaChannelTransferList[8U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            global_DmaChannelTransferList[8U].Value = 4U;
            global_DmaChannelTransferList[9U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
            global_DmaChannelTransferList[9U].Value = bufferSize;
            if ((uint8) EMIOS_ICU_CIRCULAR_BUFFER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType)
            {
                global_DmaChannelTransferList[10U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
                global_DmaChannelTransferList[10U].Value = (uint32) (~(bufferSize * 4U)) + 1U;
            }
            else
            {
                global_DmaChannelTransferList[10U].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
                global_DmaChannelTransferList[10U].Value = (uint32)1U;
            }
        }
        else if (notifyInterval < bufferSize)
        {
            global_DmaChannelTransferList[8U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
            global_DmaChannelTransferList[8U].Value = 4U;
            global_DmaChannelTransferList[9U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
            global_DmaChannelTransferList[9U].Value = notifyInterval;
            if ((uint8) EMIOS_ICU_CIRCULAR_BUFFER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType)
            {

                global_DmaChannelTransferList[10U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
                global_DmaChannelTransferList[10U].Value = (uint32)0U;
            }
            else
            {
                global_DmaChannelTransferList[10U].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
                global_DmaChannelTransferList[10U].Value = (uint32)0U;
            }
        }
        else
        {
            /* Nothing to be done */
        }

        Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, global_DmaChannelTransferList, (uint32)11U);
        Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
    }
#endif  /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */

    /* Make sure channel is in GPIO mode before switching modes */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Clear pending interrupts */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);

#if (EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT == STD_ON)
    /* Enable SAIC with edge capturing mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_EDGE_CAPTURING_U32);
#else
    /* Enable SAIC mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_U32);
#endif

    if(EMIOS_ICU_MODE_WITH_DMA == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaMode)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_51();
        s_emiosBase[instance]->CH.UC[hwChannel].C |= (eMIOS_C_DMA_MASK);
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_51();
    }

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        /* Set Max. A value */
        s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_INIT_CADR_U32;
    }

    /* Set channel Config*/
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_TIMESTAMP;
    /* Enable Interrupt */
    Emios_Icu_Ip_EnableInterrupt(instance, hwChannel);

#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Enable Interrupt for masterbus*/
    Emios_Icu_Ip_EnableMasterBusInterrupt(instance ,hwChannel);
#endif
}

/* @implements Emios_Icu_Ip_GetTimestampIndex_Activity */
uint16 Emios_Icu_Ip_GetTimestampIndex(uint8 instance,
                                      uint8 hwChannel
                                     )
{
    uint16 timestampIndex = 0U;

#if (EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL == STD_ON)
    uint32          startIter;
    uint32          crtIter;
    uint32* const   pStartIter = &startIter;
    uint32* const   pCrtIter = &crtIter;
#endif

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
    if (0xFFU != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel)
    {
        if (NULL_PTR == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer)
        {
            timestampIndex = 0U;
        }
        else
        {
            Dma_Ip_GetLogicChannelParam(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_GET_BEGIN_ITER_COUNT, pStartIter);
            Dma_Ip_GetLogicChannelParam(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_GET_CURRENT_ITER_COUNT, pCrtIter);
            crtIter = startIter - crtIter;
            timestampIndex =  eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex + (uint16)crtIter;
        }
    }
    else
    {
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */
        if (NULL_PTR == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer)
        {
            timestampIndex = 0U;
        }
        else
        {
            timestampIndex = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex;
        }
#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
    }
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */

    return timestampIndex;
}

/* @implements Emios_Icu_Ip_StopTimestamp_Activity */
void Emios_Icu_Ip_StopTimestamp(uint8 instance, uint8 hwChannel)
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
    /* Disable Dma for Timestamp */
    if (0xFFU != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel)
    {
        Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
    }
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */

    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Clear channel Config */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_NO_MEASUREMENT;

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        /* Set Max. A value */
        s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_CCR_CLEAR_U32;;
    }

#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Interrupt for masterbus*/
    Emios_Icu_Ip_DisableMasterBusInterrupt(instance, hwChannel);
#endif
}
#endif  /* EMIOS_ICU_IP_TIMESTAMP_API */

#if ((EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_USES_DMA == STD_ON))
uint32 Emios_Icu_Ip_GetStartAddress(uint8 instance,
                                    uint8 hwChannel
                                   )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    /*return the Address of A register*/
    return (uint32)(&s_emiosBase[instance]->CH.UC[hwChannel].A);
}
#endif


#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)

/* @implements Emios_Icu_Ip_ResetEdgeCount_Activity */
void Emios_Icu_Ip_ResetEdgeCount(uint8 instance,
                                 uint8 hwChannel
                                )
{
    uint32  u32PrevMode;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    u32PrevMode = (s_emiosBase[instance]->CH.UC[hwChannel].C & eMIOS_C_MODE_MASK);

    /* Disable timer interrupts */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Reset counter */
    s_emiosBase[instance]->CH.UC[hwChannel].CNT = EMIOS_ICU_IP_INIT_CCNTR_U32;

    /* Max. value for register A. If reached, overflow interrupt */
    s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_INIT_CADR_U32;

    /* Clear pending interrupts */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);

    /* Restore previous mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, u32PrevMode);

    /* Cleare Current Value*/
    eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = (uint32)0U;
    /* Enable timer interrupts */
    Emios_Icu_Ip_EnableInterrupt(instance, hwChannel);
}

/* @implements Emios_Icu_Ip_EnableEdgeCount_Activity */
void Emios_Icu_Ip_EnableEdgeCount(uint8 instance, uint8 hwChannel)
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);
    /* Make sure channel is in GPIO mode before switching modes */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Set Max. A value */
#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
    s_emiosBase[instance]->CH.UC[hwChannel].A = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].maxCounterValue;
#else
    s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_INIT_CADR_U32;
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */

    /* Sync. eMIOS counter value. (Needed in case of stopping and re-enabling counting)
     * Note: Setting GPIO mode, the internal counter was cleared and must be restored
     */

    /* When call again affter call Emios_Icu_Ip_DisableEdgeCount*/
    s_emiosBase[instance]->CH.UC[hwChannel].CNT = eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]];

    /* Modulus counter mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_MCB_EXT_CLOCK_U32);

    /* Clear pending interrupts */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);

    /* Enable interrupt */
    Emios_Icu_Ip_EnableInterrupt(instance, hwChannel);

    /* Set Channel config */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_EDGE_COUNTER;
}

/* @implements Emios_Icu_Ip_DisableEdgeCount_Activity */
void Emios_Icu_Ip_DisableEdgeCount(uint8 instance,
                                   uint8 hwChannel
                                  )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Clear pending interrupts */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);

    /* Save count, before going to GPIO mode (because counter is reset to 0x0000) */
    eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = s_emiosBase[instance]->CH.UC[hwChannel].CNT;

    /* Disable MCB mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_NO_MEASUREMENT;

#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].maxCounterValue = EMIOS_ICU_IP_INIT_CADR_U32;
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */
}


/* @implements Emios_Icu_Ip_GetEdgeNumbers_Activity */
eMios_Icu_ValueType Emios_Icu_Ip_GetEdgeNumbers(uint8 instance,
                                                uint8 hwChannel
                                               )
{
    uint32 u32Mode;
    eMios_Icu_ValueType u16Result = (eMios_Icu_ValueType)0U;
    u32Mode = (s_emiosBase[instance]->CH.UC[hwChannel].C & eMIOS_C_MODE_MASK);

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    /* Check mode after call Emios_Icu_Ip_DisableEdgeCount */
    if(EMIOS_ICU_IP_CCR_MODE_GPI_U32 == u32Mode)
    {
        u16Result = (eMios_Icu_ValueType)eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]];
    }
    else
    {
        u16Result = (eMios_Icu_ValueType)s_emiosBase[instance]->CH.UC[hwChannel].CNT;
    }
    return u16Result;

}

#if (STD_ON == EMIOS_ICU_IP_SET_INITIAL_COUNTER)
/* @implements Emios_Icu_Ip_SetInitialCounterValue_Activity */
void Emios_Icu_Ip_SetInitialCounterValue(uint8 instance,
                                         uint8 hwChannel,
                                         uint32 initialCounter
                                        )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance   < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel  < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif

    /* Save initial counter for channel */
    eMios_Icu_Ip_u32aEdgeCurrent_Value[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]]= initialCounter;
}
#endif  /* STD_ON == EMIOS_ICU_IP_SET_INITIAL_COUNTER */

#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
/* @implements Emios_Icu_Ip_SetMaxCounterValue_Activity */
void Emios_Icu_Ip_SetMaxCounterValue(uint8 instance,
                                     uint8 hwChannel,
                                     uint32 maxCounter
                                    )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance   < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel  < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(maxCounter < EMIOS_ICU_IP_COUNTER_MASK);
#endif

    /* Save max counter for channel */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].maxCounterValue = maxCounter;
}
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */
#endif  /* EMIOS_ICU_IP_EDGE_COUNT_API */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/* @implements Emios_Icu_Ip_StartSignalMeasurement_Activity */
void Emios_Icu_Ip_StartSignalMeasurement(uint8 instance,
                                         uint8 hwChannel
                                        )
{
    eMios_Icu_Ip_UCModeType eMiosOperationMode;
#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
    /* Setup DMA for this channel */
    uint8 u8index = 0U;
    Dma_Ip_LogicChannelTransferListType global_DmaChannelTransferList[10U];
#endif

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif

#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
    /* Setup DMA for this channel */
    if (0xFFU != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel)
    {
        Emios_Icu_Ip_aIsSecondInterrupt[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = 0U;
        /* initialize the members of the structure */
        global_DmaChannelTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        global_DmaChannelTransferList[0U].Value = Emios_Icu_Ip_GetStartAddress(instance, hwChannel);
        global_DmaChannelTransferList[1U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        global_DmaChannelTransferList[1U].Value = (uint32)&Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][0];
        global_DmaChannelTransferList[2U].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
        global_DmaChannelTransferList[2U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_DmaChannelTransferList[3U].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
        global_DmaChannelTransferList[3U].Value = (uint32)DMA_IP_TRANSFER_SIZE_4_BYTE;
        global_DmaChannelTransferList[4U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
        global_DmaChannelTransferList[4U].Value = (uint32)0U;
        global_DmaChannelTransferList[5U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
        global_DmaChannelTransferList[5U].Value = (uint32)4U;
        global_DmaChannelTransferList[6U].Param = DMA_IP_CH_SET_SOURCE_MODULO;
        global_DmaChannelTransferList[6U].Value = (uint32)0U;
        global_DmaChannelTransferList[7U].Param = DMA_IP_CH_SET_DESTINATION_MODULO;
        global_DmaChannelTransferList[7U].Value = (uint32)0U;
        global_DmaChannelTransferList[8U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
        global_DmaChannelTransferList[8U].Value = (uint32)4U;
        global_DmaChannelTransferList[9U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        global_DmaChannelTransferList[9U].Value = (uint32)1U;

        Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, global_DmaChannelTransferList, (uint32)10U);
        Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

        /*Clear the DMA result buffer for configured DMA channel*/
        for(u8index = 0U; u8index < EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT; u8index++)
        {
             Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][u8index] = (uint16)0;
        }
    }
#endif

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod = (eMios_Icu_ValueType)0U;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = (eMios_Icu_ValueType)0U;

    /* Reset capture and timestart of hwChannel */
    eMios_Icu_Ip_auCapturedActivePulseWidth[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = 0U;
    eMios_Icu_Ip_auTimeStart[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = 0U;

    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    /* Set activation condition */
    Emios_Icu_Ip_SetActivation(instance, hwChannel, eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].edgeTrigger);

    /* Get operation mode of hardware channel */
    if(EMIOS_ICU_MODE_WITH_DMA == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaMode)\
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_52();
        s_emiosBase[instance]->CH.UC[hwChannel].C |= (eMIOS_C_DMA_MASK);
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_52();
    }
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_SIGNAL_MEASUREMENT;

    eMiosOperationMode = (eMios_Icu_Ip_UCModeType)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].operationMode;

    switch (eMiosOperationMode)
    {
        case EMIOS_ICU_IPWM:
            {
                /* Enable IPWM mode */
                Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_IPWM_U32);
            }
        break;

        case EMIOS_ICU_IPM:
            {
                /* Enable IPM mode */
                Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_IPM_U32);
            }
        break;

        default:
            {
#if (EMIOS_ICU_IP_SAIC_EDGE_CAPTURING_SUPPORT == STD_ON)
                /* Enable SAIC with edge capturing mode */
                Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_EDGE_CAPTURING_U32);
#else
                /* Enable SAIC mode */
                Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_SAIC_U32);
#endif
            }
        break;
    }

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        /* Set Max. A value */
        s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_INIT_CADR_U32;
    }
    /* Clear pending interrupt flag (and other flags) for the channel */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);
    /* Clear the counter for signal measurement */
    eMios_Icu_Ip_aeInt_Counter[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = EMIOS_ICU_MEASUREMENT_PENDING;
    if (TRUE != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].msWithoutInterrupt)
    {
        /* Enable Interrupt */
        Emios_Icu_Ip_EnableInterrupt(instance, hwChannel);
    }

#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Enable Interrupt for masterbus*/
    Emios_Icu_Ip_EnableMasterBusInterrupt(instance, hwChannel);
#endif
}

/* @implements Emios_Icu_Ip_StopSignalMeasurement_Activity */
void Emios_Icu_Ip_StopSignalMeasurement(uint8 instance,
                                        uint8 hwChannel
                                       )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    /* Disable interrupt */
    Emios_Icu_Ip_DisableInterrupt(instance, hwChannel);

    /* Enter GPIO Mode */
    Emios_Icu_Ip_UCSetMode(instance, hwChannel, EMIOS_ICU_IP_CCR_MODE_GPI_U32);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_49();
    /* EDSEL is set to 1 to discard the input in GPIO mode (not to repond the input signal
       in GPIO mode)*/
    /* Disables the flag generation as defined by EDPOL Bit */
    s_emiosBase[instance]->CH.UC[hwChannel].C |= eMIOS_C_EDSEL_MASK;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_49();

    if (EMIOS_ICU_BUS_INTERNAL_COUNTER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected)
    {
        /* Set Max. A value */
        s_emiosBase[instance]->CH.UC[hwChannel].A = EMIOS_ICU_IP_CCR_CLEAR_U32;
    }
    /* Clear pending interrupt flag (and other flags) for the channel */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);
    /* Clear channel config */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode = EMIOS_ICU_MODE_NO_MEASUREMENT;
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Interrupt for masterbus*/
    Emios_Icu_Ip_DisableMasterBusInterrupt(instance, hwChannel);
#endif
}

/* @implements Emios_Icu_Ip_GetTimeElapsed_Activity */
eMios_Icu_ValueType Emios_Icu_Ip_GetTimeElapsed(uint8 instance,
                                                uint8 hwChannel
                                               )
{
    eMios_Icu_ValueType timeElapsed = (eMios_Icu_ValueType)0U;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    if((EMIOS_ICU_DUTY_CYCLE != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement) && \
        (EMIOS_ICU_NO_MEASUREMENT != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement))
    {
        if ((eMios_Icu_Ip_MeasType)EMIOS_ICU_PERIOD_TIME == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement)
        {
            timeElapsed = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod;
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod = (eMios_Icu_ValueType)0U;
        }
        else
        {
            timeElapsed = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth;
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = (eMios_Icu_ValueType)0U;
        }
    }
    #if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    else
    {
        DevAssert(TRUE);
    }
    #endif
    return timeElapsed;
}

/* @implements Emios_Icu_Ip_GetDutyCycleValues_Activity */
void Emios_Icu_Ip_GetDutyCycleValues(uint8 instance,
                                     uint8 hwChannel,
                                     eMios_Icu_Ip_DutyCycleType*  dutyCycleValues
                                    )
{

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif
    if(EMIOS_ICU_DUTY_CYCLE == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].measurement)
    {
        if ((eMios_Icu_ValueType)0U != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod)
        {
            dutyCycleValues->ActiveTime = (eMios_Icu_ValueType)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth;
            dutyCycleValues->PeriodTime = (eMios_Icu_ValueType)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod;
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = (eMios_Icu_ValueType)0U;
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod           = (eMios_Icu_ValueType)0U;
        }
        else
        {
            dutyCycleValues->ActiveTime = (eMios_Icu_ValueType)0U;
            dutyCycleValues->PeriodTime = (eMios_Icu_ValueType)0U;
        }
    }
    #if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    else
    {
        DevAssert(TRUE);
    }
    #endif
}

/**
 * @brief Emios_Icu_Ip_SetPWandPeriod
 */
void Emios_Icu_Ip_SetPWandPeriod(uint8 instance, \
                                 uint8 hwChannel, \
                                 eMios_Icu_ValueType activePulseWidth, \
                                 eMios_Icu_ValueType period
                                )
{
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = activePulseWidth;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod           = period;
}
#endif  /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API */

#if (EMIOS_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/* @implements Emios_Icu_Ip_GetInputState_Activity */
boolean Emios_Icu_Ip_GetInputState(uint8 instance,
                                   uint8 hwChannel
                                  )
{
    boolean bResult = FALSE;
    uint32 u32ValueCCRFEN;
    uint32 u32ValueCSRFLAG;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    u32ValueCCRFEN  = (s_emiosBase[instance]->CH.UC[hwChannel].C & eMIOS_C_FEN_MASK);
    u32ValueCSRFLAG = (s_emiosBase[instance]->CH.UC[hwChannel].S & eMIOS_S_FLAG_MASK);

    /* Interrupt not enabled, flag bit was set */
    if ((eMIOS_C_FEN_MASK != u32ValueCCRFEN) && (eMIOS_S_FLAG_MASK == u32ValueCSRFLAG))
    {

        /* Clear pending interrupt */
        s_emiosBase[instance]->CH.UC[hwChannel].S |= eMIOS_S_FLAG_MASK;
        bResult = TRUE;
    }

    if ((FALSE == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].msWithoutInterrupt) && \
        (EMIOS_ICU_MODE_SIGNAL_MEASUREMENT == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode))
    {
        bResult = FALSE;
    }

    return bResult;
}
#endif  /* EMIOS_ICU_IP_GET_INPUT_STATE_API */

#if (EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON)
/* @implements  Emios_Icu_Ip_GetInputLevel_Activity */
eMios_Icu_Ip_LevelType Emios_Icu_Ip_GetInputLevel(uint8 instance,
                                                  uint8 hwChannel
                                                 )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    return ((0U != ((s_emiosBase[instance]->CH.UC[hwChannel].S & eMIOS_S_UCIN_MASK)>> eMIOS_S_UCIN_SHIFT))? \
            EMIOS_ICU_LEVEL_HIGH : EMIOS_ICU_LEVEL_LOW);
}
#endif /* EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON */

/* @implements  Emios_Icu_Ip_GetOverflow_Activity */
boolean Emios_Icu_Ip_GetOverflow(uint8 instance,
                                 uint8 hwChannel
                                )
{
    uint32 u32RegCSR = (uint32) 0U;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    u32RegCSR = s_emiosBase[instance]->CH.UC[hwChannel].S;

    /* Clear pending interrupt serviced */
    s_emiosBase[instance]->CH.UC[hwChannel].S |= eMIOS_S_OVFL_MASK;

    return ((eMIOS_S_OVFL_MASK == (u32RegCSR & eMIOS_S_OVFL_MASK)) ? TRUE : FALSE);
}

#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/* @implements Emios_Icu_Ip_SetClockMode_Activity */  
void Emios_Icu_Ip_SetClockMode(uint8 instance,
                               const eMios_Icu_Ip_ConfigType *peMiosIpConfig,
                               const eMios_Icu_Ip_ClockModeType Prescaler
                              )
{
    /* logical channel */
    uint8   index;
    uint8   hwChannel;
    eMios_Icu_Ip_BusType  nCtrlBus;
    uint8   u8MasterBusChannelIdx;
    uint8   u8MasterBusUse[EMIOS_ICU_IP_NUM_OF_CHANNELS];

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
#endif
    for (index=0U; index < (uint8)EMIOS_ICU_IP_NUM_OF_CHANNELS; index++)
    {
        u8MasterBusUse[index] = (uint8)EMIOS_ICU_IP_CB_NONE;
    }

    for (index=0U; index < peMiosIpConfig->nNumChannels; index++)
    {
        hwChannel   = (*peMiosIpConfig->pChannelsConfig)[index].hwChannel;
        nCtrlBus = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected;

        if (EMIOS_ICU_BUS_INTERNAL_COUNTER == nCtrlBus)
        {
            if (EMIOS_ICU_NORMAL_CLK == Prescaler)
            {
                Emios_Icu_Ip_SetPrescaler(  instance,
                                            hwChannel,
                                            (uint32)(*peMiosIpConfig->pChannelsConfig)[index].Prescaler
                                          );
            }
            else
            {
                Emios_Icu_Ip_SetPrescaler(  instance,
                                            hwChannel,
                                            (uint32)(*peMiosIpConfig->pChannelsConfig)[index].AltPrescaler
                                          );
            }
        }
        else
        {
            u8MasterBusChannelIdx = (uint8)Emios_Icu_Ip_GetMasterBus(hwChannel, nCtrlBus);

            if(u8MasterBusChannelIdx < EMIOS_ICU_IP_NUM_OF_CHANNELS)
            {
                if(u8MasterBusUse[u8MasterBusChannelIdx] == EMIOS_ICU_IP_CB_NONE)
                {
                    if (EMIOS_ICU_NORMAL_CLK == Prescaler)
                    {
                        Emios_Icu_Ip_SetPrescaler(  instance,
                                                u8MasterBusChannelIdx,
                                                (uint32)(*peMiosIpConfig->pChannelsConfig)[index].Prescaler
                                              );
                    }
                    else
                    {
                        Emios_Icu_Ip_SetPrescaler(  instance,
                                                u8MasterBusChannelIdx,
                                                (uint32)(*peMiosIpConfig->pChannelsConfig)[index].AltPrescaler
                                              );
                    }
                    u8MasterBusUse[u8MasterBusChannelIdx] = (uint8)1U;
                }
            }
        }
    }
}
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_CAPTURERGISTER_API == STD_ON) && ((EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)))
/** @implements Emios_Icu_Ip_GetCaptureRegValue_Activity */
uint32 Emios_Icu_Ip_GetCaptureRegValue(uint8 instance,
                                       uint8 hwChannel
                                      )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    return (s_emiosBase[instance]->CH.UC[hwChannel].A);
}
#endif  /* (EMIOS_ICU_IP_CAPTURERGISTER_API == STD_ON) && ((EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)) */

#if ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))
/* @implements Emios_Icu_Ip_GetPulseWidth_Activity */
void Emios_Icu_Ip_GetPulseWidth(uint8 instance,
                                uint8 hwChannel
                               )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    Emios_Icu_Ip_SignalMeasurementHandler(instance, hwChannel, FALSE);
}
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL == STD_ON) && ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)))
Std_ReturnType Emios_Icu_Ip_ValidateSignalMeasureWithoutInterrupt(uint8 instance,
                                                                  uint8 hwChannel
                                                                 )
{
    /*return ICU signal property without using interrupt*/
    return (eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].msWithoutInterrupt)?(Std_ReturnType)E_OK:(Std_ReturnType)E_NOT_OK;
}
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
/* @implements Emios_Icu_Ip_GetWheelSpeedTimeMeasurement_Activity */
uint32 Emios_Icu_Ip_GetWheelSpeedTimeMeasurement(uint8 instance, uint8 hwWSChannel)
{
    uint32 timeValue;
    uint8 hwWSChannelId;
    uint8 wscMode;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
    wscMode = (uint8)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC1 & eMIOS_WSC1_MODE_MASK) >> eMIOS_WSC1_MODE_SHIFT);
    if ((uint8)EMIOS_WHEEL_SPEED_MODE == wscMode)
    {
        timeValue = (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSPW & eMIOS_WSPW_T16PWCAP_MASK) >> eMIOS_WSPW_T16PWCAP_SHIFT);
    }
    else if ((uint8)EMIOS_SENT_MODE == wscMode)
    {
        timeValue = (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSFR & eMIOS_WSFR_T24CAPA_T16PWD_VAL_MASK) >> eMIOS_WSFR_T24CAPA_T16PWD_VAL_SHIFT);
    }
    else /* DISABLE MODE */
    {
        timeValue = 0U;
    }

    return timeValue;
}

/* @implements Emios_Icu_Ip_GetWheelSpeedCaptureA_Activity */
uint32 Emios_Icu_Ip_GetWheelSpeedCaptureA(uint8 instance, uint8 hwWSChannel)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    return (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSCAEC & eMIOS_WSCAEC_T24CAPA_MASK) >> eMIOS_WSCAEC_T24CAPA_SHIFT);
}

/* @implements Emios_Icu_Ip_GetWheelSpeedCaptureB_Activity */
uint32 Emios_Icu_Ip_GetWheelSpeedCaptureB(uint8 instance, uint8 hwWSChannel)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    return (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSCAPB & eMIOS_WSCAPB_T24CAPB_MASK) >> eMIOS_WSCAPB_T24CAPB_SHIFT);
}

/* @implements Emios_Icu_Ip_SetWheelSpeedEvent_Activity */
void Emios_Icu_Ip_SetWheelSpeedEvent(uint8 instance, uint8 hwWSChannel, uint8 event)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSEV |= eMIOS_WSEV_EVENT(event);
}

/* @implements Emios_Icu_Ip_GetWheelSpeedCaptureEvent_Activity */
uint32 Emios_Icu_Ip_GetWheelSpeedCaptureEvent(uint8 instance, uint8 hwWSChannel)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    return (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSCEV & eMIOS_WSCEV_T24CAPEV_MASK) >> eMIOS_WSCEV_T24CAPEV_SHIFT);
}

/* @implements Emios_Icu_Ip_GetWheelSpeedEventCnt_Activity */
uint8 Emios_Icu_Ip_GetWheelSpeedEventCnt(uint8 instance, uint8 hwWSChannel)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    return (uint8)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSCAEC & eMIOS_WSCAEC_EVCNT_MASK) >> eMIOS_WSCAEC_EVCNT_SHIFT);
}

/* @implements Emios_Icu_Ip_WheelSpeedEnableInterrupt_Activity */
void Emios_Icu_Ip_WheelSpeedEnableInterrupt(uint8 instance, uint8 hwWSChannel, eMios_Icu_Ip_WscIsrSourceType isrSource)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC2 |= eMIOS_WSC2_FLAGSEL(isrSource);

    if ((uint8)0U == eMios_Icu_Ip_axWsChState[instance][hwWSChannel].EnableInterruptStatus)
    {
        s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC1 |= (uint32)eMIOS_WSC1_FEN_MASK;
    }
    eMios_Icu_Ip_axWsChState[instance][hwWSChannel].EnableInterruptStatus |= (uint8)isrSource;
}

/* @implements Emios_Icu_Ip_WheelSpeedDisableInterrupt_Activity */
void Emios_Icu_Ip_WheelSpeedDisableInterrupt(uint8 instance, uint8 hwWSChannel, eMios_Icu_Ip_WscIsrSourceType isrSource)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC2 &= ~eMIOS_WSC2_FLAGSEL(isrSource);

    if (EMIOS_FLAG_NONE == isrSource)
    {
        eMios_Icu_Ip_axWsChState[instance][hwWSChannel].EnableInterruptStatus = 0U;
    }
    else
    {
        eMios_Icu_Ip_axWsChState[instance][hwWSChannel].EnableInterruptStatus &= ~((uint8)isrSource);
    }

    if (0U == eMios_Icu_Ip_axWsChState[instance][hwWSChannel].EnableInterruptStatus)
    {
        s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC1 &= ~(uint32)eMIOS_WSC1_FEN_MASK;
    }
}

/* @implements Emios_Icu_Ip_GetWheelSpeedFifo_Activity */
void Emios_Icu_Ip_GetWheelSpeedFifo(uint8 instance, uint8 hwWSChannel, eMios_Icu_Ip_WscFifoType* eMiosWSCFifoData)
{
    uint8 hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwWSChannel < EMIOS_ICU_IP_WSC_CHANNEL_OFFSET);
#endif
    eMiosWSCFifoData->FifoData     = (uint32)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSFR  & eMIOS_WSFR_T24CAPA_T16PWD_VAL_MASK) >> eMIOS_WSFR_T24CAPA_T16PWD_VAL_SHIFT);
    eMiosWSCFifoData->FifoCounter  = (uint8)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSFCNT & eMIOS_WSFCNT_FCNTR_MASK) >> eMIOS_WSFCNT_FCNTR_SHIFT);
    eMiosWSCFifoData->pWrite       = (uint8)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSFPNT & eMIOS_WSFPNT_FIFOWRPT_MASK) >> eMIOS_WSFPNT_FIFOWRPT_SHIFT);
    eMiosWSCFifoData->pRead        = (uint8)((s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSFPNT & eMIOS_WSFPNT_FIFORDPT_MASK) >> eMIOS_WSFPNT_FIFORDPT_SHIFT);
}
    #endif /* EMIOS_ICU_IP_WSC_SUPPORT */
#endif /* defined EMIOS_ICU_IP_WSC_SUPPORT */

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
