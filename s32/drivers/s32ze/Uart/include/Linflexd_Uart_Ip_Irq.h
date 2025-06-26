/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef LINFLEXD_UART_IP_IRQ_H
#define LINFLEXD_UART_IP_IRQ_H

/**
*   @file
*   @defgroup linflexd_uart_ip Linflexd UART IPL
*   @addtogroup  linflexd_uart_ip Linflexd UART IPL
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

#include "Linflexd_Uart_Ip_Defines.h"
#include "Linflexd_Uart_Ip_Cfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_IRQ_VENDOR_ID                    43
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION     4
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION     7
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION  0
#define LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION             2
#define LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION             0
#define LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip_Defines.h */
#if (LINFLEXD_UART_IP_IRQ_VENDOR_ID != LINFLEXD_UART_IP_DEFINES_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Defines.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Defines.h are different"
#endif
#if ((LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION != LINFLEXD_UART_IP_DEFINES_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION != LINFLEXD_UART_IP_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Defines.h are different"
#endif

/* Checks against Linflexd_Uart_Ip_Cfg.h */
#if (LINFLEXD_UART_IP_IRQ_VENDOR_ID != LINFLEXD_UART_IP_CFG_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Cfg.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION    != LINFLEXD_UART_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION != LINFLEXD_UART_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Cfg.h are different"
#endif
#if ((LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION != LINFLEXD_UART_IP_CFG_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION != LINFLEXD_UART_IP_CFG_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION != LINFLEXD_UART_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_Irq.h and Linflexd_Uart_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
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
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

#if (LINFLEXD_IP_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
/* Implementation of LINFLEXD0 handler named in startup code. */
ISR(LINFLEXD0_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
/* Implementation of LINFLEXD1 handler named in startup code. */
ISR(LINFLEXD1_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
/* Implementation of LINFLEXD2 handler named in startup code. */
ISR(LINFLEXD2_UART_IRQHandler);
#endif
#endif


#if (LINFLEXD_IP_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
/* Implementation of LINFLEXD3 handler named in startup code. */
ISR(LINFLEXD3_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
/* Implementation of LINFLEXD4 handler named in startup code. */
ISR(LINFLEXD4_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
/* Implementation of LINFLEXD5 handler named in startup code. */
ISR(LINFLEXD5_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 6U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
/* Implementation of LINFLEXD6 handler named in startup code. */
ISR(LINFLEXD6_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
/* Implementation of LINFLEXD7 handler named in startup code. */
ISR(LINFLEXD7_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
/* Implementation of LINFLEXD8 handler named in startup code. */
ISR(LINFLEXD8_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
/* Implementation of LINFLEXD9 handler named in startup code. */
ISR(LINFLEXD9_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
/* Implementation of LINFLEXD10 handler named in startup code. */
ISR(LINFLEXD10_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
/* Implementation of LINFLEXD11 handler named in startup code. */
ISR(LINFLEXD11_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
/* Implementation of LINFLEXD12 handler named in startup code. */
ISR(LINFLEXD12_UART_IRQHandler);
#endif
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
/* Implementation of MSC_0_LIN handler named in startup code. */
ISR(MSC_0_LIN_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 13U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_13
/* Implementation of LINFLEXD13 handler named in startup code. */
ISR(LINFLEXD13_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 14U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_14
/* Implementation of LINFLEXD14 handler named in startup code. */
ISR(LINFLEXD14_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 15U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_15
/* Implementation of LINFLEXD15 handler named in startup code. */
ISR(LINFLEXD15_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 16U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_16
/* Implementation of LINFLEXD16 handler named in startup code. */
ISR(LINFLEXD16_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 17U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_17
/* Implementation of LINFLEXD17 handler named in startup code. */
ISR(LINFLEXD17_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 18U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_18
/* Implementation of LINFLEXD18 handler named in startup code. */
ISR(LINFLEXD18_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 19U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_19
/* Implementation of LINFLEXD19 handler named in startup code. */
ISR(LINFLEXD19_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 20U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_20
/* Implementation of LINFLEXD20 handler named in startup code. */
ISR(LINFLEXD20_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 21U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_21
/* Implementation of LINFLEXD21 handler named in startup code. */
ISR(LINFLEXD21_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 22U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_22
/* Implementation of LINFLEXD22 handler named in startup code. */
ISR(LINFLEXD22_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 23U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_23
/* Implementation of LINFLEXD23 handler named in startup code. */
ISR(LINFLEXD23_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 24U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_24
/* Implementation of LINFLEXD24 handler named in startup code. */
ISR(LINFLEXD24_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 25U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_25
/* Implementation of LINFLEXD25 handler named in startup code. */
ISR(LINFLEXD25_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 26U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_26
/* Implementation of LINFLEXD26 handler named in startup code. */
ISR(LINFLEXD26_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 27U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_27
/* Implementation of LINFLEXD27 handler named in startup code. */
ISR(LINFLEXD27_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 28U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_28
/* Implementation of LINFLEXD28 handler named in startup code. */
ISR(LINFLEXD28_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 29U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_29
/* Implementation of LINFLEXD29 handler named in startup code. */
ISR(LINFLEXD29_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 30U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_30
/* Implementation of LINFLEXD30 handler named in startup code. */
ISR(LINFLEXD30_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 31U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_31
/* Implementation of LINFLEXD31 handler named in startup code. */
ISR(LINFLEXD31_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 32U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_32
/* Implementation of LINFLEXD32 handler named in startup code. */
ISR(LINFLEXD32_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 33U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_33
/* Implementation of LINFLEXD33 handler named in startup code. */
ISR(LINFLEXD33_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (LINFLEXD_IP_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
void Linflexd_0_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_0_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
void Linflexd_1_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_1_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
void Linflexd_2_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_2_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
void Linflexd_3_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_3_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
void Linflexd_4_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_4_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
void Linflexd_5_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_5_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
#if (LINFLEXD_IP_INSTANCE_COUNT > 6U)
void Linflexd_6_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_6_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
void Linflexd_7_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_7_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
void Linflexd_8_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_8_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
void Linflexd_9_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_9_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
void Linflexd_10_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_10_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
void Linflexd_11_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_11_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
void Linflexd_12_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_12_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
void MSC_0_Lin_Uart_Ip_DmaRxCompleteCallback(void);
void MSC_0_Lin_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 13U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_13
void Linflexd_13_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_13_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 14U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_14
void Linflexd_14_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_14_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 15U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_15
void Linflexd_15_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_15_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 16U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_16
void Linflexd_16_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_16_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 17U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_17
void Linflexd_17_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_17_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 18U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_18
void Linflexd_18_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_18_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 19U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_19
void Linflexd_19_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_19_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 20U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_20
void Linflexd_20_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_20_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 21U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_21
void Linflexd_21_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_21_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 22U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_22
void Linflexd_22_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_22_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 23U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_23
void Linflexd_23_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_23_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 24U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_24
void Linflexd_24_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_24_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 25U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_25
void Linflexd_25_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_25_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 26U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_26
void Linflexd_26_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_26_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 27U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_27
void Linflexd_27_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_27_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 28U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_28
void Linflexd_28_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_28_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 29U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_29
void Linflexd_29_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_29_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 30U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_30
void Linflexd_30_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_30_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 31U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_31
void Linflexd_31_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_31_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 32U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_32
void Linflexd_32_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_32_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 33U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_33
void Linflexd_33_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_33_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#endif /* (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON) */

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_IRQ_H */
