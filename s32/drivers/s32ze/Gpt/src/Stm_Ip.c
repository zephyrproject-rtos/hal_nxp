/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Stm_Ip.c
*
*   @addtogroup stm_ip Stm IPL
*
*   @{
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
#include "Stm_Ip.h"

#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STM_IP_ENABLE_USER_MODE_SUPPORT)
    #include "RegLockMacros.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define STM_IP_VENDOR_ID_C                    43
#define STM_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define STM_IP_AR_RELEASE_MINOR_VERSION_C     4
#define STM_IP_AR_RELEASE_REVISION_VERSION_C  0
#define STM_IP_SW_MAJOR_VERSION_C             0
#define STM_IP_SW_MINOR_VERSION_C             8
#define STM_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION != STM_IP_AR_RELEASE_MAJOR_VERSION_C) || \
         (REGLOCKMACROS_AR_RELEASE_MINOR_VERSION != STM_IP_AR_RELEASE_MINOR_VERSION_C))
        #error "AutoSar Version Numbers of RegLockMacros.h and Stm_Ip.c are different"
    #endif
#endif
#endif

#if (STM_IP_VENDOR_ID != STM_IP_VENDOR_ID_C)
    #error "Stm_Ip.h and Stm_Ip.c have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION != STM_IP_AR_RELEASE_MAJOR_VERSION_C) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION != STM_IP_AR_RELEASE_MINOR_VERSION_C) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION != STM_IP_AR_RELEASE_REVISION_VERSION_C) \
    )
    #error "AutoSar Version Numbers of Stm_Ip.h and Stm_Ip.c are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION != STM_IP_SW_MAJOR_VERSION_C) || \
     (STM_IP_SW_MINOR_VERSION != STM_IP_SW_MINOR_VERSION_C) || \
     (STM_IP_SW_PATCH_VERSION != STM_IP_SW_PATCH_VERSION_C) \
    )
    #error "Software Version Numbers of Stm_Ip.h and Stm_Ip.c are different"
#endif
/*==================================================================================================
*                                          LOCAL DEFINIES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#if (STM_IP_USED == STD_ON)

#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"
/** @brief Global array variable used to store the runtime target time value. */
uint32 Stm_Ip_u32TargetValue[STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
uint32 Stm_Ip_u32NextTargetValue[STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#endif
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"
/** @brief Table of base addresses for STM instances. */
STM_Type * const stmBase[STM_INSTANCE_COUNT] = IP_STM_BASE_PTRS;
#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
/** @brief Global array variable used to channel state for process common interrupt */
static Stm_Ip_ChState Stm_Ip_u32ChState[STM_INSTANCE_COUNT][STM_CHANNEL_COUNT] =  {
                                                                                    {
                                                                                        {
                                                                                            (boolean)FALSE,
                                                                                            NULL_PTR,
                                                                                            0U,
                                                                                            STM_IP_CH_MODE_CONTINUOUS
                                                                                        }
                                                                                    }
                                                                                };
#endif
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
static Stm_Ip_InstanceState Stm_Ip_u32InstanceState[STM_INSTANCE_COUNT] =   {
                                                                                {
                                                                                    0U,
                                                                                    0U
                                                                                }
                                                                            };
#endif
#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

static inline void Stm_Ip_SetDebugMode(uint8 instance, boolean stopRun);
static inline void Stm_Ip_TimerEnable(uint8 instance, boolean enable);
static inline uint32 Stm_Ip_GetTimerEnableBit(uint8 instance);
static inline void Stm_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue);
static inline void Stm_Ip_ChannelEnable(uint8 instance, uint8 channel, boolean enable);
static inline void Stm_Ip_ClearInterruptFlag(uint8 instance, uint8 channel);
static inline void Stm_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 compareValue);
static inline uint32 Stm_Ip_GetCmpValue(uint8 instance, uint8 channel);
static inline void Stm_Ip_SetCntValue(uint8 instance, uint32 counterValue);
static inline uint32 Stm_Ip_GetCntValue(uint8 instance);


#if (STM_IP_MODULE_SINGLE_INTERRUPT == STD_ON)
#ifdef STM_0_ISR_USED
ISR(STM_0_ISR);
#endif
#ifdef STM_1_ISR_USED
ISR(STM_1_ISR);
#endif
#ifdef STM_2_ISR_USED
ISR(STM_2_ISR);
#endif
#ifdef STM_3_ISR_USED
ISR(STM_3_ISR);
#endif
#ifdef STM_4_ISR_USED
ISR(STM_4_ISR);
#endif
#ifdef STM_5_ISR_USED
ISR(STM_5_ISR);
#endif
#ifdef STM_6_ISR_USED
ISR(STM_6_ISR);
#endif
#ifdef STM_7_ISR_USED
ISR(STM_7_ISR);
#endif
#ifdef STM_8_ISR_USED
ISR(STM_8_ISR);
#endif
#ifdef STM_9_ISR_USED
ISR(STM_9_ISR);
#endif
#ifdef STM_10_ISR_USED
ISR(STM_10_ISR);
#endif
#ifdef STM_11_ISR_USED
ISR(STM_11_ISR);
#endif
#ifdef STM_12_ISR_USED
ISR(STM_12_ISR);
#endif
#ifdef SMU_STM_0_ISR_USED
ISR(SMU_STM_0_ISR);
#endif
#ifdef SMU_STM_2_ISR_USED
ISR(SMU_STM_2_ISR);
#endif
#ifdef CE_STM_0_ISR_USED
ISR(CE_STM_0_ISR);
#endif
#ifdef CE_STM_1_ISR_USED
ISR(CE_STM_1_ISR);
#endif
#ifdef CE_STM_2_ISR_USED
ISR(CE_STM_2_ISR);
#endif
#ifdef RTU0_STM_0_ISR_USED
ISR(RTU0_STM_0_ISR);
#endif
#ifdef RTU0_STM_1_ISR_USED
ISR(RTU0_STM_1_ISR);
#endif
#ifdef RTU0_STM_2_ISR_USED
ISR(RTU0_STM_2_ISR);
#endif
#ifdef RTU0_STM_3_ISR_USED
ISR(RTU0_STM_3_ISR);
#endif
#ifdef RTU1_STM_0_ISR_USED
ISR(RTU1_STM_0_ISR);
#endif
#ifdef RTU1_STM_1_ISR_USED
ISR(RTU1_STM_1_ISR);
#endif
#ifdef RTU1_STM_2_ISR_USED
ISR(RTU1_STM_2_ISR);
#endif
#ifdef RTU1_STM_3_ISR_USED
ISR(RTU1_STM_3_ISR);
#endif

#endif /* STM_IP_MODULE_SINGLE_INTERRUPT == STD_ON */
#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
static inline void Stm_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel);
static inline uint32 Stm_Ip_GetInterruptBit(uint8 instance, uint8 channel);
#endif

#if (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT)
    void Stm_Ip_SetUserAccessAllowed(uint32 StmBaseAddr);
#endif


#if (defined(MCAL_STM_REG_PROT_AVAILABLE) && (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT))

    #define Call_Stm_Ip_SetUserAccessAllowed(StmBaseAddr) OsIf_Trusted_Call1param(Stm_Ip_SetUserAccessAllowed,(StmBaseAddr))

#else

    #define Call_Stm_Ip_SetUserAccessAllowed(StmBaseAddr)
#endif


#if (defined(MCAL_STM_REG_PROT_AVAILABLE) && (STD_ON == STM_IP_ENABLE_USER_MODE_SUPPORT))
/**
* @brief        Enables STM registers writing in User Mode by configuring REG_PROT
* @details      Sets the UAA (User Access Allowed) bit of the STM IP allowing STM registers writing in User Mode
*
* @param[in]    none
*
* @return       none
*
* @pre          Should be executed in supervisor mode
* @post         none
*/
void Stm_Ip_SetUserAccessAllowed (uint32 StmBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(StmBaseAddr, STM_PROT_MEM_U32);
}
#endif /* STM_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief
* Function Name : Stm_Ip_GetInterruptFlag
* Description   : Gets interrupt request flag:
*
* @param[in]     instance     STM hw instance number
* @param[in]     channel      STM hw channel number
*
* @return        flag         flag bit value 0/1
*
*/
uint32 Stm_Ip_GetInterruptFlag(uint8 instance, uint8 channel)
{
    uint32 flag = 0U;
    flag = stmBase[instance]->CHANNEL[channel].CIR;
    return flag;
}

static inline void Stm_Ip_SetDebugMode(uint8 instance, boolean stopRun)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_29();
    /* Enable DebugMode */
    if (TRUE == stopRun)
    {
        stmBase[instance]->CR |= STM_CR_FRZ_MASK;
    }
    else
    {
        stmBase[instance]->CR &= ~STM_CR_FRZ_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_29();
}

static inline void Stm_Ip_TimerEnable(uint8 instance, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_30();
    /* Enable TEN */
    if (TRUE == enable)
    {
        stmBase[instance]->CR |= STM_CR_TEN_MASK;
    }
    else
    {
        stmBase[instance]->CR &= ~STM_CR_TEN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_30();
}

static inline uint32 Stm_Ip_GetTimerEnableBit(uint8 instance)
{
    uint32 flag = 0;
    /* Get TimerEnableBit value*/
    flag = (stmBase[instance]->CR & STM_CR_TEN_MASK) >> STM_CR_TEN_SHIFT;

    return flag;
}

static inline void Stm_Ip_SetPrescaler(uint8 instance, uint8 prescalerValue)
{
    /* SetPrescaler value*/
    stmBase[instance]->CR = (stmBase[instance]->CR & (~STM_CR_CPS_MASK)) | STM_CR_CPS(prescalerValue);

}

static inline void Stm_Ip_ChannelEnable(uint8 instance, uint8 channel, boolean enable)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_31();
    /* Enable ChannelEnable */
    if (TRUE == enable)
    {
        stmBase[instance]->CHANNEL[channel].CCR |= STM_CCR_CEN_MASK;
    }
    else
    {
        stmBase[instance]->CHANNEL[channel].CCR &= ~STM_CCR_CEN_MASK;
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_31();
}

static inline void Stm_Ip_ClearInterruptFlag(uint8 instance, uint8 channel)
{
    /* Clear InterruptFlag */
    stmBase[instance]->CHANNEL[channel].CIR = STM_CIR_CIF_MASK;
}

#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
static inline uint32 Stm_Ip_GetInterruptBit(uint8 instance, uint8 channel)
{
    uint32 flag = 0U;
    /* Get InterruptBit CCR*/
    flag = stmBase[instance]->CHANNEL[channel].CCR;
    return flag;
}
#endif

static inline void Stm_Ip_SetCmpValue(uint8 instance, uint8 channel, uint32 compareValue)
{
    /* Set compareValue */
    stmBase[instance]->CHANNEL[channel].CMP = compareValue;
}

static inline uint32 Stm_Ip_GetCmpValue(uint8 instance, uint8 channel)
{
    uint32 currentCmpValue;
    /* Get compareValue */
    currentCmpValue = stmBase[instance]->CHANNEL[channel].CMP;
    return currentCmpValue;
}

static inline void Stm_Ip_SetCntValue(uint8 instance, uint32 counterValue)
{
    /* Set counterValue */
    stmBase[instance]->CNT = counterValue;
}

static inline uint32 Stm_Ip_GetCntValue(uint8 instance)
{
    uint32 currentCntValue;
    /* Get counterValue */
    currentCntValue = stmBase[instance]->CNT;
    return currentCntValue;
}

#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
/**
* @brief   Driver routine to process all the interrupts of STM.
* @details Support function used by interrupt service routines to implement STM specific operations
*          and call the upper layer handler to implement non-hardware specific operations.
*
* @param[in]     instance     STM hw instance number
* @param[in]     channel      STM hw channel number
*
* @implements       Stm_Ip_ProcessCommonInterrupt_Activity
*/
static inline void Stm_Ip_ProcessCommonInterrupt(uint8 instance, uint8 channel)
{
    uint32 oldCmpValue = 0U;
    uint32 targetValue = 0U;

#if(STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
    if(0x0U != Stm_Ip_u32NextTargetValue[instance][channel])
    {
        Stm_Ip_u32TargetValue[instance][channel] = Stm_Ip_u32NextTargetValue[instance][channel];
        Stm_Ip_u32NextTargetValue[instance][channel] = 0x0U;
    }
#endif
    /* Check if channel mode is ONE-SHOT */
    if((STM_IP_CH_MODE_ONESHOT == Stm_Ip_u32ChState[instance][channel].channelMode))
    {
        Stm_Ip_DisableChannel(instance, channel);
    }
    else
    {
        /*Get current CMP value*/
        oldCmpValue = Stm_Ip_GetCmpValue(instance, channel);
        /*Get current target value*/
        targetValue = Stm_Ip_u32TargetValue[instance][channel];
        /*Set new CMP value*/
        Stm_Ip_SetCmpValue(instance, channel, (oldCmpValue + targetValue));
    }

    /* Call upper layer handler */
    if((TRUE == Stm_Ip_u32ChState[instance][channel].chInit) && \
            (NULL_PTR != Stm_Ip_u32ChState[instance][channel].callback))
    {
        Stm_Ip_u32ChState[instance][channel].callback(Stm_Ip_u32ChState[instance][channel].callbackParam);
    }
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_Init
* @details       Initializes the STM instance. This functions is called for each STM hw Instance and:
*                    - sets the counter value
*                    - configures the freeze mode
*                    - sets the prescaler value
*                    - enables the STM counter
*
* @param[in]     instance     STM hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Stm_Ip_Init_Activity
*/
void Stm_Ip_Init(uint8 instance, const Stm_Ip_InstanceConfigType *configPtr)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(NULL_PTR != configPtr);
#endif
   /* Enable register access from user mode, if enabled from configuration file */
    Call_Stm_Ip_SetUserAccessAllowed((uint32)stmBase[instance]);
    Stm_Ip_SetCntValue(instance, 0U);
    Stm_Ip_SetDebugMode(instance, configPtr->stopInDebugMode);
    Stm_Ip_SetPrescaler(instance, configPtr->clockPrescaler);
    Stm_Ip_TimerEnable(instance, TRUE);
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
    Stm_Ip_u32InstanceState[instance].clockPrescaler = configPtr->clockPrescaler;
    Stm_Ip_u32InstanceState[instance].clockAlternatePrescaler = configPtr->clockAlternatePrescaler;
#endif
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_InitChannel
* @details       Initializes the STM channels. This functions is called for each STM hw channel and:
*                    - disables hw channel
*                    - clears interrupt clear
*                    - sets compare value to 0
*                    - initializes the state sructure for common process interrupt
*
* @param[in]     instance     STM hw instance number
* @param[in]     configPtr    Pointer to a selected configuration structure
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver
* @implements    Stm_Ip_InitChannel_Activity
*/
void Stm_Ip_InitChannel(uint8 instance, const Stm_Ip_ChannelConfigType *configPtr)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(NULL_PTR != configPtr);
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > configPtr->hwChannel);
#endif

    /*Disable hw channel */
    Stm_Ip_ChannelEnable(instance, configPtr->hwChannel, FALSE);
    /* Clear Interrupt Flag */
    Stm_Ip_ClearInterruptFlag(instance, configPtr->hwChannel);
    /*Set compare value to 0*/
    Stm_Ip_SetCmpValue(instance, configPtr->hwChannel, 0U);
#if ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)  || (defined STM_3_ISR_USED)  || \
     (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED)  || (defined STM_7_ISR_USED)  || \
     (defined STM_8_ISR_USED) || (defined STM_9_ISR_USED) || (defined STM_10_ISR_USED) || (defined STM_11_ISR_USED) || \
     (defined STM_12_ISR_USED)|| (defined SMU_STM_0_ISR_USED) || (defined SMU_STM_2_ISR_USED) || \
     (defined CE_STM_0_ISR_USED) || (defined CE_STM_1_ISR_USED) || (defined CE_STM_2_ISR_USED) || \
     (defined RTU0_STM_0_ISR_USED) || (defined RTU0_STM_1_ISR_USED) || (defined RTU0_STM_2_ISR_USED) || (defined RTU0_STM_3_ISR_USED) || \
     (defined RTU1_STM_0_ISR_USED) || (defined RTU1_STM_1_ISR_USED) || (defined RTU1_STM_2_ISR_USED) || (defined RTU1_STM_3_ISR_USED))
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].chInit = TRUE;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].callback = configPtr->callback;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].callbackParam = configPtr->callbackParam;
    Stm_Ip_u32ChState[instance][configPtr->hwChannel].channelMode = configPtr->channelMode;
#endif
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_Deinit
* @details      De-Initializes the STM module. This functions is called for each STM hw instance and:
*                    - resets all channels to default
*                    - sets to default prescaler bits
*                    - disables the STM counter
*
* @param[in]     instance     STM hw instance number
* @return        void
* @pre           The data structure including the configuration set required for initializing the GPT driver.
* @implements    Stm_Ip_Deinit_Activity
*/
void Stm_Ip_Deinit(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
#endif

    uint8 channelIndex;

    /* Reset all channels to default */
    for (channelIndex = 0; channelIndex < STM_CHANNEL_COUNT; channelIndex++)
    {
        /* Disable channels */
        Stm_Ip_ChannelEnable(instance, channelIndex, FALSE);
        /* Clear interrupt flags */
        Stm_Ip_ClearInterruptFlag(instance, channelIndex);
        /* Sets compare value to 0 */
        Stm_Ip_SetCmpValue(instance, channelIndex, 0x0U);
    }

    /* Set to default prescaler bits */
    Stm_Ip_SetPrescaler(instance, 0x0U);

    /* Disable counter */
    Stm_Ip_TimerEnable(instance, FALSE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_StartCounting
* @details      This function is called for starting the Stm timer channel
*                    - reads the current counter register value and sets the compare register to the sum of
*                      counter register value plus the timeout value
*                    - enables the STM channel
*
* @param[in]     instance        STM hw instance number
* @param[in]     channel         Stm channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartCounting_Activity
*/
void Stm_Ip_StartCounting(uint8 instance, uint8 channel, uint32 compareValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    uint32 currentCntValue;

    currentCntValue = 0U;
    Stm_Ip_u32TargetValue[instance][channel] = compareValue;
    currentCntValue = Stm_Ip_GetCntValue(instance);
    Stm_Ip_SetCmpValue(instance, channel, (currentCntValue + compareValue));
    /*Enable hw Channel*/
    Stm_Ip_ChannelEnable(instance, channel, TRUE);
}
/*================================================================================================*/
#if STM_IP_ABSOLUTE_COUNTING_API  == STD_ON
/**
* @brief        Function Name : Stm_Ip_StartCountingAbsolute
* @details      This function is called for starting the Stm timer channel
*                    - sets the compare value without adding the current counter value to the timeout value
*                    - enables the STM channel
*
* @param[in]     instance        STM hw instance number
* @param[in]     channel         Stm channel
* @param[in]     compareValue    Compare value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartCountingAbsolute_Activity
*/
void Stm_Ip_StartCountingAbsolute(uint8 instance, uint8 channel, uint32 compareValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_u32TargetValue[instance][channel] = 0U;
    Stm_Ip_SetCmpValue(instance, channel, compareValue);
    /*Enable hw Channel*/
    Stm_Ip_ChannelEnable(instance, channel, TRUE);
}
#endif
/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_StartTimer
* @details       This function is called for setting a new start counter value and enables the STM counter:
*                   - sets the new counter value
*                   - enables the STM counter
*
* @param[in]     instance       Stm hw instance
* @param[in]     startValue     counter value
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_StartTimer_Activity
*/
void Stm_Ip_StartTimer(uint8 instance, uint32 startValue)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
#endif

    Stm_Ip_SetCntValue(instance, startValue);
    Stm_Ip_TimerEnable(instance, TRUE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_StopTimer
* @details      Gpt driver function for stopping the Stm counter.
*                   - disables the STM counter
*
* @param[in]     instance       Stm hw instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for stoping the STM timer channel.
* @implements    Stm_Ip_StopTimer_Activity
*/
void Stm_Ip_StopTimer(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
#endif

    Stm_Ip_TimerEnable(instance, FALSE);
}

/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_EnableChannel
* @details      Enables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_EnableChannel_Activity
*/
void Stm_Ip_EnableChannel(uint8 instance, uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_ClearInterruptFlag(instance, channel);
    Stm_Ip_ChannelEnable(instance, channel, TRUE);
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_DisableChannel
* @details       Disables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_DisableChannel_Activity
*/
void Stm_Ip_DisableChannel(uint8 instance, uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    Stm_Ip_ChannelEnable(instance, channel, FALSE);
    Stm_Ip_ClearInterruptFlag(instance, channel);
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_GetCounterValue
* @details       Gets the counter value.
*
* @param[in]     instance                  Stm hw instance
*
* @return        currentCounterValue       current counter value
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
* @implements    Stm_Ip_GetCounterValue_Activity
*/
uint32 Stm_Ip_GetCounterValue(uint8 instance)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
#endif

    uint32 currentCounterValue;

    currentCounterValue = 0;

    currentCounterValue = Stm_Ip_GetCntValue(instance);

    return currentCounterValue;
}

/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_GetCompareValue
* @details       Gets the compare value for selected channel
*
* @param[in]     instance                  Stm hw instance
* @param[in]     channel                   Stm hw channel
*
* @return        currentCompareValue       compare value for selected channel
* @pre           The driver needs to be initialized.
* @implements    Stm_Ip_GetCompareValue_Activity
*/
uint32 Stm_Ip_GetCompareValue(uint8 instance,  uint8 channel)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    uint32 currentCompareValue;

    currentCompareValue = 0;

    currentCompareValue = Stm_Ip_GetCmpValue(instance, channel);

    return currentCompareValue;
}

#if (STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the Stm compare register value.
* @details This function:
*          - Write next timeout to local variable
*
* @param[in]     instance        Stm hw instance
* @param[in]     channel         Channel
* @param[in]     value           Channel timeout value
* @return        void
* @pre           The driver needs to be initialized.
* @implements       Stm_Ip_ChangeNextTimeoutValue_Activity
*/
void Stm_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
    DevAssert(STM_CHANNEL_COUNT > channel);
#endif

    /* Update the target time value to be used on next cycle */
    Stm_Ip_u32NextTargetValue[instance][channel] = value;

}
#endif

#if (STM_IP_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the STM prescaler value.
* @details    This function sets the STM prescaler based on the input mode.
*
* @param[in]  instance     Stm hw instance
* @param[in]  clockMode    STM_IP_CLOCKMODE_NORMAL or STM_IP_CLOCKMODE_ALTERNATE
*
* @return     void
* @pre        The driver needs to be initialized. On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
* @implements Stm_Ip_SetClockMode_Activity
*/
void Stm_Ip_SetClockMode(uint8 instance, Stm_Ip_ClockModeType clockMode)
{
#if STM_IP_DEV_ERROR_DETECT == STD_ON
    DevAssert(STM_INSTANCE_COUNT > instance);
#endif

    if(STM_IP_CLOCKMODE_NORMAL == clockMode)
    {
        Stm_Ip_SetPrescaler(instance, Stm_Ip_u32InstanceState[instance].clockPrescaler);
    }
    else
    {
        Stm_Ip_SetPrescaler(instance, Stm_Ip_u32InstanceState[instance].clockAlternatePrescaler);
    }

}
#endif

/*================================================================================================*/
/**
* @brief      This function sets the STM prescaler, freeze bit and enables counter
* @details    This function start counting with predefined values(like a free running timer)
*
* @param[in]  instance        Stm hw instance
* @param[in]  prescaler       Prescaler value
* @param[in]  freezeEnable    Freeze value
* @return     void
* @pre        The driver needs to be initialized
* @implements Stm_Ip_PredefCounting_Activity
*/
void Stm_Ip_PredefCounting(uint8 instance, uint8 prescaler, boolean freezeEnable)
{

    /* Enable register access from user mode, if enabled from configuration file */
    Call_Stm_Ip_SetUserAccessAllowed((uint32)stmBase[instance]);
    /* check if the timer is not enabled - TEN bit*/
    if(1U != Stm_Ip_GetTimerEnableBit(instance))
    {
        /* clear counter */
        Stm_Ip_SetCntValue(instance, 0x0000U);
        /* Set prescaler for stm timer */
        Stm_Ip_SetPrescaler(instance, prescaler);
        if (TRUE == freezeEnable)
        {
            Stm_Ip_SetDebugMode(instance, TRUE);
        }
        else
        {
            Stm_Ip_SetDebugMode(instance, FALSE);
        }
        /*Enable counting*/
        Stm_Ip_TimerEnable(instance, TRUE);
    }
}

/*================================================================================================*/
#if (STM_IP_MODULE_SINGLE_INTERRUPT == STD_ON) /* STM_IP_MODULE_SINGLE_INTERRUPT == STD_ON */
#ifdef STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_0 module.
* @param[in] none
* @return  none
* @isr
* @pre      The driver needs to be initialized.
*/
ISR(STM_0_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(0U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(0U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(0U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(0U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_1_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_1 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_1_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(1U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(1U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(1U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(1U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_2 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_2_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(2U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(2U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(2U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(2U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_3_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_3 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_3_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(3U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(3U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(3U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(3U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_4_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_4 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_4_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(4U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(4U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(4U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(4U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_5_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_5 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_5_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(5U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(5U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(5U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(5U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_6_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_6 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_6_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(6U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(6U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(6U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(6U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_7_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_7 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_7_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(7U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(7U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(7U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(7U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_8_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_8 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_8_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(8U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(8U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(8U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(8U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_9_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_9 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_9_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(9U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(9U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(9U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(9U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_10_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_10 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_10_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(10U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(10U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(10U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(10U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_11_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_10 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_11_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(11U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(11U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(11U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(11U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef STM_12_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(STM_12_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(12U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(12U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(12U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(12U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef SMU_STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(SMU_STM_0_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(101U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(11U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(11U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(11U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef SMU_STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(SMU_STM_2_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(12U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(12U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(12U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(12U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef CE_STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(CE_STM_0_ISR)
{
    uint8 channel = 0U;    
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(0U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(0U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(0U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(0U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef CE_STM_1_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(CE_STM_1_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(1U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(1U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(1U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(1U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef CE_STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(CE_STM_2_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(2U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(2U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(2U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(2U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef CE_STM_3_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(CE_STM_3_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(3U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(3U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(3U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(3U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU0_STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU0_STM_0_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(3U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(3U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(3U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(3U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU0_STM_1_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU0_STM_1_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(4U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(4U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(4U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(4U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU0_STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU0_STM_2_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(5U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(5U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(5U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(5U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU0_STM_3_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU0_STM_3_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(6U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(6U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(6U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(6U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU1_STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU1_STM_0_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(7U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(7U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(7U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(7U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU1_STM_1_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU1_STM_1_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(8U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(8U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(8U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(8U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU1_STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU1_STM_2_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(9U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(9U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(9U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(9U, channel);
        }
    }
}
#endif
/*================================================================================================*/
#ifdef RTU1_STM_3_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common STM_12 module.
*
* @param[in] none
* @return  void
* @isr
* @pre      The driver needs to be initialized.
*
*/
ISR(RTU1_STM_3_ISR)
{
    uint8 channel = 0U;
    uint32 flagBits = 0U;
    uint32 enableBits = 0U;
    uint32 currentChannelMask = 0U;

    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        flagBits |= ((Stm_Ip_GetInterruptFlag(10U, channel)) << channel);
        enableBits |= ((Stm_Ip_GetInterruptBit(10U, channel)) << channel);
        if((currentChannelMask == (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ClearInterruptFlag(10U, channel);
        }
    }
    for (channel = 0U; channel < STM_CHANNEL_COUNT; channel++)
    {
        currentChannelMask = 1U << (uint32)channel;
        if((currentChannelMask== (flagBits & currentChannelMask)) && (currentChannelMask == (enableBits & currentChannelMask)))
        {
            Stm_Ip_ProcessCommonInterrupt(10U, channel);
        }
    }
}
#endif
#endif /* STM_IP_MODULE_SINGLE_INTERRUPT == STD_ON */

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* STM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif  /*STM_IP_C*/
/** @} */

