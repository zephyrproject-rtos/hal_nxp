/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup i3c_ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I3c_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I3C_IP_VENDOR_ID_ISR_C                      43
#define I3C_IP_AR_RELEASE_MAJOR_VERSION_ISR_C       4
#define I3C_IP_AR_RELEASE_MINOR_VERSION_ISR_C       7
#define I3C_IP_AR_RELEASE_REVISION_VERSION_ISR_C    0
#define I3C_IP_SW_MAJOR_VERSION_ISR_C               1
#define I3C_IP_SW_MINOR_VERSION_ISR_C               0
#define I3C_IP_SW_PATCH_VERSION_ISR_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I3c_Ip_Irq header file are of the same vendor */
#if (I3C_IP_VENDOR_ID_ISR_C != I3C_IP_IRQ_VENDOR_ID)
    #error "I3c_Ip_Irq.c and I3c_Ip_Irq.h have different vendor ids"
#endif

/* Check if current file and I3c_Ip_Irq header file are of the same Autosar version */
#if ((I3C_IP_AR_RELEASE_MAJOR_VERSION_ISR_C     != I3C_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (I3C_IP_AR_RELEASE_MINOR_VERSION_ISR_C     != I3C_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (I3C_IP_AR_RELEASE_REVISION_VERSION_ISR_C  != I3C_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I3c_Ip_Irq.c and I3c_Ip_Irq.h are different"
#endif

/* Check if current file and I3c_Ip_Irq header file are of the same software version */
#if ((I3C_IP_SW_MAJOR_VERSION_ISR_C != I3C_IP_IRQ_SW_MAJOR_VERSION) || \
     (I3C_IP_SW_MINOR_VERSION_ISR_C != I3C_IP_IRQ_SW_MINOR_VERSION) || \
     (I3C_IP_SW_PATCH_VERSION_ISR_C != I3C_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of I3c_Ip_Irq.c and I3c_Ip_Irq.h are different"
#endif

/*==================================================================================================
*                                           CODE
==================================================================================================*/
#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

#if (I3C_INSTANCE_COUNT > 0U)
/* Implementation of I3c0 IRQ Handler */
ISR(I3c0_Isr)
{
    I3c_Ip_IRQHandler(0U);
}
#endif /* (I3C_INSTANCE_COUNT > 0U) */

#if (I3C_INSTANCE_COUNT > 1U)
/* Implementation of I3c1 IRQ Handler */
ISR(I3c1_Isr)
{
    I3c_Ip_IRQHandler(1U);
}
#endif /* (I3C_INSTANCE_COUNT > 1U) */

#if (I3C_INSTANCE_COUNT > 2U)
/* Implementation of I3c2 IRQ Handler */
ISR(I3c2_Isr)
{
    I3c_Ip_IRQHandler(2U);
}
#endif /* (I3C_INSTANCE_COUNT > 2U) */


#if (STD_ON == I3C_IP_DMA_FEATURE_AVAILABLE)

#if (I3C_INSTANCE_COUNT > 0U)
/* Implementation of I3C_0 Master callback function for Dma Error interrupt. */
void I3c_0_Ip_MasterDmaErrorCallback(void)
{
    I3c_Ip_MasterDmaErrorHandler(0U);
}

/* Implementation of I3C_0 Slave callback function for Dma Error interrupt. */
void I3c_0_Ip_SlaveDmaErrorCallback(void)
{
    I3c_Ip_SlaveDmaErrorHandler(0U);
}
#endif /* (I3C_INSTANCE_COUNT > 0U) */

#if (I3C_INSTANCE_COUNT > 1U)
/* Implementation of I3C_1 Master callback function for Dma Error interrupt. */
void I3c_1_Ip_MasterDmaErrorCallback(void)
{
    I3c_Ip_MasterDmaErrorHandler(1U);
}

/* Implementation of I3C_1 Slave callback function for Dma Error interrupt. */
void I3c_1_Ip_SlaveDmaErrorCallback(void)
{
    I3c_Ip_SlaveDmaErrorHandler(1U);
}
#endif /* (I3C_INSTANCE_COUNT > 1U) */

#if (I3C_INSTANCE_COUNT > 2U)
/* Implementation of I3C_2 Master callback function for Dma Error interrupt. */
void I3c_2_Ip_MasterDmaErrorCallback(void)
{
    I3c_Ip_MasterDmaErrorHandler(2U);
}

/* Implementation of I3C_2 Slave callback function for Dma Error interrupt. */
void I3c_2_Ip_SlaveDmaErrorCallback(void)
{
    I3c_Ip_SlaveDmaErrorHandler(2U);
}
#endif /* (I3C_INSTANCE_COUNT > 2U) */
#endif /* I3C_IP_DMA_FEATURE_AVAILABLE */

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
