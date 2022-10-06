/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM_IP_H
#define STM_IP_H

/**
*   @file       Stm_Ip.h
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
#include "Stm_Ip_Types.h"
#include "Stm_Ip_Cfg.h"
#include "OsIf.h"
#if STM_IP_DEV_ERROR_DETECT == STD_ON
#include "Devassert.h"
#endif
#if (STM_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
#include "Reg_eSys.h"
#endif
#include "SchM_Gpt.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @internal
* @brief Defines used for file version checks
*/
#define STM_IP_VENDOR_ID                       43
#define STM_IP_AR_RELEASE_MAJOR_VERSION        4
#define STM_IP_AR_RELEASE_MINOR_VERSION        4
#define STM_IP_AR_RELEASE_REVISION_VERSION     0
#define STM_IP_SW_MAJOR_VERSION                0
#define STM_IP_SW_MINOR_VERSION                8
#define STM_IP_SW_PATCH_VERSION                0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (STM_IP_VENDOR_ID != STM_IP_TYPES_VENDOR_ID)
    #error "Stm_Ip.h and Stm_Ip_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION != STM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION != STM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION != STM_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Stm_Ip.h and Stm_Ip_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION != STM_IP_TYPES_SW_MAJOR_VERSION) || \
     (STM_IP_SW_MINOR_VERSION != STM_IP_TYPES_SW_MINOR_VERSION) || \
     (STM_IP_SW_PATCH_VERSION != STM_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Stm_Ip.h and Stm_Ip_Types.h are different"
#endif

#if (STM_IP_VENDOR_ID != STM_IP_VENDOR_ID_CFG)
    #error "Stm_Ip.h and Stm_Ip_Cfg.h have different vendor ids"
#endif
/* Check if STM_IP header file and STM_IP_Cfg header file are of the same Autosar version */
#if ((STM_IP_AR_RELEASE_MAJOR_VERSION != STM_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (STM_IP_AR_RELEASE_MINOR_VERSION != STM_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (STM_IP_AR_RELEASE_REVISION_VERSION != STM_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Stm_Ip.h and Stm_Ip_Cfg.h are different"
#endif
/* Check if Stm_Ip file and Stm_Ip_Cfg header file are of the same Software version */
#if ((STM_IP_SW_MAJOR_VERSION != STM_IP_SW_MAJOR_VERSION_CFG) || \
     (STM_IP_SW_MINOR_VERSION != STM_IP_SW_MINOR_VERSION_CFG) || \
     (STM_IP_SW_PATCH_VERSION != STM_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Stm_Ip.h and Stm_Ip_Cfg.h are different"
#endif


#if (STM_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
/* Check if header file and StandardTypes.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Stm_Ip.h and Reg_eSys.h are different"
    #endif
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_AR_RELEASE_MAJOR_VERSION != SCHM_GPT_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_AR_RELEASE_MINOR_VERSION != SCHM_GPT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Stm_Ip.h and SchM_Gpt.h are different"
    #endif
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((STM_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (STM_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Stm_Ip.h and OsIf.h are different"
    #endif
#endif

#if STM_IP_DEV_ERROR_DETECT == STD_ON
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((STM_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (STM_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Stm_Ip.h and Devassert.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
#if (STM_IP_USED == STD_ON)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

extern uint32 Stm_Ip_u32TargetValue[STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#if ((STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON) && ((defined STM_0_ISR_USED) || (defined STM_1_ISR_USED) || (defined STM_2_ISR_USED)|| (defined STM_3_ISR_USED) || (defined STM_4_ISR_USED) || (defined STM_5_ISR_USED) || (defined STM_6_ISR_USED) || (defined STM_7_ISR_USED)))
extern uint32 Stm_Ip_u32NextTargetValue[STM_INSTANCE_COUNT][STM_CHANNEL_COUNT];
#endif

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_VAR_CLEARED_32
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @internal
* @brief MemMap section
*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

uint32 Stm_Ip_GetInterruptFlag(uint8 instance, uint8 channel);
extern STM_Type * const stmBase[STM_INSTANCE_COUNT];
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
*/
void Stm_Ip_Init(uint8 instance, const Stm_Ip_InstanceConfigType *configPtr);
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
*/
void Stm_Ip_InitChannel(uint8 instance, const Stm_Ip_ChannelConfigType *configPtr);
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
*/
void Stm_Ip_Deinit(uint8 instance);
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
*/
void Stm_Ip_StartCounting(uint8 instance, uint8 channel, uint32 compareValue);
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
void Stm_Ip_StartCountingAbsolute(uint8 instance, uint8 channel, uint32 compareValue);
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
*
*/
void Stm_Ip_StartTimer(uint8 instance, uint32 startValue);
/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_StopTimer
* @details      Gpt driver function for stopping the Stm counter.
*                   - disables the STM counter
*
* @param[in]     instance       Stm hw instance
* @return        void
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
*/
void Stm_Ip_StopTimer(uint8 instance);
/*================================================================================================*/
/**
* @brief        Function Name : Stm_Ip_EnableChannel
* @details      Enables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
*/
void Stm_Ip_EnableChannel(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_DisableChannel
* @details       Disables the channel selected.
*
* @param[in]     instance       Stm hw instance
* @param[in]     channel        Stm hw channel
* @return        void
* @pre           The driver needs to be initialized.
*/
void Stm_Ip_DisableChannel(uint8 instance, uint8 channel);
/*================================================================================================*/
/**
* @brief         Function Name : Stm_Ip_GetCounterValue
* @details       Gets the counter value.
*
* @param[in]     instance                  Stm hw instance
*
* @return        currentCounterValue       current counter value
* @pre           The driver needs to be initialized. This function is called for starting the STM timer channel.
*/
uint32 Stm_Ip_GetCounterValue(uint8 instance);
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
*/
uint32 Stm_Ip_GetCompareValue(uint8 instance, uint8 channel);
/*================================================================================================*/
#if (STM_IP_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
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
*/
void Stm_Ip_ChangeNextTimeoutValue(uint8 instance, uint8 channel, uint32 value);
#endif
/*================================================================================================*/
#if (STM_IP_SET_CLOCK_MODE == STD_ON)
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
void Stm_Ip_SetClockMode(uint8 instance, Stm_Ip_ClockModeType clockMode);
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
* @implements
*/
void Stm_Ip_PredefCounting(uint8 instance, uint8 prescaler, boolean freezeEnable);

/**
* @internal
* @brief MemMap section
*/
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#endif /* STM_IP_USED == STD_ON */

#ifdef __cplusplus
}
#endif
/** @} */
#endif/*STM_IP_H*/
