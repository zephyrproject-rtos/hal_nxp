/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *   @file       Emios_Mcl_Ip.h
 *
 *   @version    3.0.0
 *
 *   @brief      AUTOSAR Mcl - Emios Common driver header file.
 *
 *   @addtogroup EMIOS_IP_DRIVER EMIOS IP Driver
 *   @{
 */

#ifndef EMIOS_MCL_IP_H
#define EMIOS_MCL_IP_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"

#include "StandardTypes.h"
#include "Emios_Mcl_Ip_Cfg.h"

#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_VENDOR_ID                    43
#define EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_MCL_IP_SW_MAJOR_VERSION             3
#define EMIOS_MCL_IP_SW_MINOR_VERSION             0
#define EMIOS_MCL_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes.h are of the same AUTOSAR version */
#if ((EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Emios_Mcl_Ip.h and StandardTypes.h are different"
#endif

/* Check if header file and OsIf.h are of the same AUTOSAR version */
#if ((EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Emios_Mcl_Ip.h and OsIf.h are different"
#endif

#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
/* Check if header file and Devassert.h are of the same AUTOSAR version */
#if ((EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Emios_Mcl_Ip.h and Devassert.h are different"
#endif
#endif /*(STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)*/
#endif /*DISABLE_MCAL_INTERMODULE_ASR_CHECK*/

/* Check if header file and Emios_Mcl_Ip_Cfg header file are of the same vendor. */
#if (EMIOS_MCL_IP_VENDOR_ID != EMIOS_MCL_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Mcl_Ip.h and Emios_Mcl_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Mcl_Ip_Cfg header file are of the same AUTOSAR version. */
#if ((EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION    != EMIOS_MCL_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION    != EMIOS_MCL_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Mcl_Ip.h and Emios_Mcl_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same software version */
#if ((EMIOS_MCL_IP_SW_MAJOR_VERSION != EMIOS_MCL_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_SW_MINOR_VERSION != EMIOS_MCL_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_SW_PATCH_VERSION != EMIOS_MCL_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Mcl_Ip.h and Emios_Mcl_Ip_Cfg.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/**
 * @brief   Emios start channel function.
 * @details This function is called separately for each EMIOS hw channel in order to enable it.
 *
 * @param[in] Instance    Instance of EMIOS used.
 * @param[in] HwChannel EMIOS hardware channel used.
 */
void Emios_Mcl_Ip_EnableChannel(uint8 Instance, uint8 HwChannel);

/**
 * @brief   Emios stop channel function.
 * @details This function is called separately for each EMIOS hw channel in order to disable it.
 *
 * @param[in] Instance    Instance of EMIOS used.
 * @param[in] HwChannel EMIOS hardware channel used.
 */
void Emios_Mcl_Ip_DisableChannel(uint8 Instance, uint8 HwChannel);

/**
 * @brief The function shall enable the output update for the corresponding channel.
 *
 * @param[in] Instance    Instance of EMIOS used.
 * @param[in] ChannelMask EMIOS channel mask used to enable the output update.
 *                        This mask should be on 32 bits.
 *                        0x00000001U <- First channel will be affected
 *                          ^      ^
 *                          |      |
 *                         MSB    LSB
 *                        0x00FFFFFFU <- All channels will be affected
 *                                       (EMIOS instance has only 24 channels)
 */
void Emios_Mcl_Ip_ComparatorTransferEnable(uint8 Instance, uint32 ChannelMask);

/**
 * @brief The function shall disable the output update for the corresponding channel.
 *
 * @param[in] Instance    Instance of EMIOS used.
 * @param[in] ChannelMask EMIOS channel mask used to disable the output update.
 *                        This mask should be on 32 bits.
 *                        0x00000001U <- First channel will be affected
 *                          ^      ^
 *                          |      |
 *                         MSB    LSB
 *                        0x00FFFFFFU <- All channels will be affected
 *                                       (EMIOS instance has only 24 channels)
 */
void Emios_Mcl_Ip_ComparatorTransferDisable(uint8 Instance, uint32 ChannelMask);

/**
 * @brief This function shall reset all the register used to initialize a channel as a masterbus. The
 * API should reset to POR values all registers used for configuring the common part of EMIOS IP.
 *
 * @param[in] Instance  Instance of EMIOS used.
 * @return Emios_Ip_CommonStatusType
 */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_Deinit(uint8 Instance);

/**
 * @brief The API should configure the common part of EMIOS IP to be used by any driver implementation
 *        with EMIOS support (ex:  ICU, PWM, GPT, OCU)
 *
 * @param[in] Instance   Instance of EMIOS used.
 * @param[in] ConfigPtr  EMIOS instance specific configuration.
 * @return Emios_Ip_CommonStatusType
 */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_Init(uint8 Instance, const Emios_Mcl_Ip_ConfigType *const ConfigPtr);

/**
 * @brief   Allow the user to specify the number of bus reload events skipped.
 *
 * @details Reload Signal Output Delay Interval
 *          Specifies the delay interval, in counter bus reload events, between each assertion of AS1-BS1 reload in
 *          MC and MCB modes.
 *              00000b - Every event
 *              00001b - Every 2nd event
 *              00010b - Every 3rd event
 *              . . .
 *              11111b - Every 32nd event
 *
 * @param HwInstance Instance of EMIOS used.
 * @param HwChannel  EMIOS hardware channel used.
 * @param Interval
 */
void Emios_Mcl_Ip_SetReloadInterval(uint8 HwInstance, uint8 HwChannel, uint8 Interval);

/**
 * @brief Change the period on active/intialized EMIOS counter(master) bus.
 *
 * @param HwInstance Instance of EMIOS used.
 * @param HwChannel  EMIOS hardware channel used.
 *
 * @return boolean Status of operation.
 */
boolean Emios_Mcl_Ip_ValidateChannel(uint8 HwInstance, uint8 HwChannel);

/**
 * @brief
 *
 * @param HwInstance  Instance of EMIOS used.
 * @param HwChannel  EMIOS hardware channel used.
 * @param Period     Period
 * @return Emios_Ip_CommonStatusType
 */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_SetCounterBusPeriod(uint8 HwInstance, uint8 HwChannel, uint32 Period);

/**
 * @brief  Get period of counter bus channels
 *
 * @param Instance  Instance of EMIOS used.
 * @param Channel   EMIOS hardware channel used.
 * @return The period value of Counter Bus channels
 */
#if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
uint32 Emios_Mcl_Ip_GetCounterBusPeriod(uint8 Instance, uint8 Channel);
#else
uint16 Emios_Mcl_Ip_GetCounterBusPeriod(uint8 Instance, uint8 Channel);
#endif

#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
/**
 * @brief
 *
 * @param HwInstance
 * @return boolean
 */
boolean Emios_Mcl_Ip_ValidateMultiCoreInit(uint8 HwInstance);
#endif /* STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE */

/**
 * @brief  Configure Global Timebase 
 * @details This function enables or disables the GTBE bit of the EMIOS->MCR register of an addressed eMIOS instance.
 *  
 * @param[in] Instance  Instance of EMIOS used.
 * @param[in] Value   STD_ON to set bit and STD_OFF to reset bit.
 * @return void
 */
void Emios_Mcl_Ip_ConfigureGlobalTimebase(uint8 Instance, uint8 Value);

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_MCL_IP_H */
