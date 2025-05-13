/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IRQ_H
#define EMIOS_ICU_IRQ_H

/**
 *   @file Emios_Icu_Ip_Irq.h
 *
 *   @addtogroup emios_icu_ip EMIOS IPL
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Emios_Icu_Ip_Cfg.h"

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
        #include "Dma_Ip.h"
    #endif
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_IRQ_VENDOR_ID                       43
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION                2
#define EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION                0
#define EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if ((STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL) || (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL))
            /* Check if header file and Dma_Ip.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
                 (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION != DMA_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.h and Dma_Ip.h are different"
            #endif
        #endif
    #endif
#endif

#if (EMIOS_ICU_IP_IRQ_VENDOR_ID != EMIOS_ICU_IP_CFG_VENDOR_ID)
    #error "Emios_Icu_Ip_Irq.h and Emios_Icu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip_Cfg.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.h and Emios_Icu_Ip_Cfg.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_Cfg.h file are of the same Software version */
#if ((EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION != EMIOS_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION != EMIOS_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION != EMIOS_ICU_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_Irq.h and Emios_Icu_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.h and OsIf.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)
    
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
/**
* @brief      This function saves the value of timestamps in the internal buffer
* @details    This function saves the value of timestamps in the internal buffer
*
* @param[in]  Channel   Logical number of the ICU channel
*
* @return     void
* @pre        Emios_Icu_Ip_Init must be called before.
* implements  Emios_Icu_Ip_TimestampDmaProcessing
**/
void Emios_Icu_Ip_TimestampDmaProcessing(uint8 instance, uint8 hwChannel);
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */

#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
/**
* @brief      This function saves the value of signal measurement  in the internal buffer
* @details    This function saves the value of signal measurement in the internal buffer
*
* @param[in]  Channel   Logical number of the ICU channel
* @return     void
* @pre        Emios_Icu_Ip_Init must be called before.
*
* implements Emios_Icu_Ip_SignalMeasurementDmaProcessing
**/
void Emios_Icu_Ip_SignalMeasurementDmaProcessing(uint8 instance, uint8 hwChannel);
#endif

/**
* @brief      Icu driver function that handles the interrupt of eMIOS channel.
* @details    This function:
*              - Reads the status register
*              - Clears the pending interrupt
*              - Processes interrupt for corresponding eMIOS channel
*
* @param[in]  channel - eMIOS hardware channel
*
*
*/
void Emios_Icu_Ip_IrqHandler(uint8 instance, uint8 channel);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_IRQ_H */
