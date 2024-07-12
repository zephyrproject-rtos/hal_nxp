/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef I3C_IP_IRQ_H
#define I3C_IP_IRQ_H

/**
*     @file
*
*     @addtogroup I3C_DRIVER I3c Driver
*     @{
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
#include "OsIf.h"
#include "I3c_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_IRQ_VENDOR_ID                      43
#define I3C_IP_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define I3C_IP_IRQ_AR_RELEASE_MINOR_VERSION       7
#define I3C_IP_IRQ_AR_RELEASE_REVISION_VERSION    0
#define I3C_IP_IRQ_SW_MAJOR_VERSION               1
#define I3C_IP_IRQ_SW_MINOR_VERSION               0
#define I3C_IP_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I3c_Ip_CfgDefines header file are of the same vendor */
#if (I3C_IP_IRQ_VENDOR_ID != I3C_IP_VENDOR_ID_CFGDEFINES)
    #error "I3c_Ip_CfgDefines.h and I3c_Ip_Irq.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_CfgDefines header file are of the same Autosar version */
#if ((I3C_IP_IRQ_AR_RELEASE_MAJOR_VERSION     != I3C_IP_AR_RELEASE_MAJOR_VERSION_CFGDEFINES) || \
     (I3C_IP_IRQ_AR_RELEASE_MINOR_VERSION     != I3C_IP_AR_RELEASE_MINOR_VERSION_CFGDEFINES) || \
     (I3C_IP_IRQ_AR_RELEASE_REVISION_VERSION  != I3C_IP_AR_RELEASE_REVISION_VERSION_CFGDEFINES))
    #error "AutoSar Version Numbers of I3c_Ip_CfgDefines.h and I3c_Ip_Irq.h are different"
#endif

/* Check if current file and I3c_Ip_CfgDefines header file are of the same software version */
#if ((I3C_IP_IRQ_SW_MAJOR_VERSION != I3C_IP_SW_MAJOR_VERSION_CFGDEFINES) || \
     (I3C_IP_IRQ_SW_MINOR_VERSION != I3C_IP_SW_MINOR_VERSION_CFGDEFINES) || \
     (I3C_IP_IRQ_SW_PATCH_VERSION != I3C_IP_SW_PATCH_VERSION_CFGDEFINES))
    #error "Software Version Numbers of I3c_Ip_CfgDefines.h and I3c_Ip_Irq.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if I3c_Ip_CfgDefines.h file and OsIf.h file are of the same Autosar version */
    #if ((I3C_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (I3C_IP_IRQ_AR_RELEASE_MINOR_VERSION     != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of I3c_Ip_CfgDefines.h and OsIf.h are different"
    #endif
#endif  /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"
/*******************************************************************************
 * Code
 ******************************************************************************/

#if (I3C_INSTANCE_COUNT > 0U)
/* IAR requires prototypes */
ISR(I3c0_Isr);
#endif /* (I3C_INSTANCE_COUNT > 0U) */

#if (I3C_INSTANCE_COUNT > 1U)
/* IAR requires prototypes */
ISR(I3c1_Isr);
#endif /* (I3C_INSTANCE_COUNT > 1U) */

#if (I3C_INSTANCE_COUNT > 2U)
/* IAR requires prototypes */
ISR(I3c2_Isr);
#endif /* (I3C_INSTANCE_COUNT > 2U) */

void I3c_Ip_IRQHandler(const uint8 Instance);

#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)
void I3c_Ip_MasterDmaErrorHandler(const uint8 Instance);
void I3c_Ip_SlaveDmaErrorHandler(const uint8 Instance);

#if (I3C_INSTANCE_COUNT > 0U)
/* IAR requires prototypes */
void I3c_0_Ip_MasterDmaErrorCallback(void);
void I3c_0_Ip_SlaveDmaErrorCallback(void);

#endif /* (I3C_INSTANCE_COUNT > 0U) */

#if (I3C_INSTANCE_COUNT > 1U)
/* IAR requires prototypes */
void I3c_1_Ip_MasterDmaErrorCallback(void);
void I3c_1_Ip_SlaveDmaErrorCallback(void);

#endif /* (I3C_INSTANCE_COUNT > 1U) */

#if (I3C_INSTANCE_COUNT > 2U)
/* IAR requires prototypes */
void I3c_2_Ip_MasterDmaErrorCallback(void);
void I3c_2_Ip_SlaveDmaErrorCallback(void);

#endif /* (I3C_INSTANCE_COUNT > 2U) */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* LPI2C_IP_IRQ_H */

