/*
 * Copyright 2021-2023 NXP
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
#define LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION             1
#define LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION             0
#define LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION             0

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

#if (LINFLEXD_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
/* Implementation of LINFLEXD0 handler named in startup code. */
ISR(LINFLEXD0_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
/* Implementation of LINFLEXD1 handler named in startup code. */
ISR(LINFLEXD1_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
/* Implementation of LINFLEXD2 handler named in startup code. */
ISR(LINFLEXD2_UART_IRQHandler);
#endif
#endif


#if (LINFLEXD_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
/* Implementation of LINFLEXD3 handler named in startup code. */
ISR(LINFLEXD3_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
/* Implementation of LINFLEXD4 handler named in startup code. */
ISR(LINFLEXD4_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
/* Implementation of LINFLEXD5 handler named in startup code. */
ISR(LINFLEXD5_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 6U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
/* Implementation of LINFLEXD6 handler named in startup code. */
ISR(LINFLEXD6_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
/* Implementation of LINFLEXD7 handler named in startup code. */
ISR(LINFLEXD7_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
/* Implementation of LINFLEXD8 handler named in startup code. */
ISR(LINFLEXD8_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
/* Implementation of LINFLEXD9 handler named in startup code. */
ISR(LINFLEXD9_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
/* Implementation of LINFLEXD10 handler named in startup code. */
ISR(LINFLEXD10_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
/* Implementation of LINFLEXD11 handler named in startup code. */
ISR(LINFLEXD11_UART_IRQHandler);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
/* Implementation of LINFLEXD12 handler named in startup code. */
ISR(LINFLEXD12_UART_IRQHandler);
#endif
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
/* Implementation of MSC_0_LIN handler named in startup code. */
ISR(MSC_0_LIN_UART_IRQHandler);
#endif
#endif


#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (LINFLEXD_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
void Linflexd_0_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_0_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
void Linflexd_1_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_1_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
void Linflexd_2_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_2_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
void Linflexd_3_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_3_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
void Linflexd_4_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_4_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
void Linflexd_5_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_5_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
#if (LINFLEXD_INSTANCE_COUNT > 6U)
void Linflexd_6_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_6_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
void Linflexd_7_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_7_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
void Linflexd_8_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_8_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
void Linflexd_9_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_9_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
void Linflexd_10_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_10_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
void Linflexd_11_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_11_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#if (LINFLEXD_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
void Linflexd_12_Uart_Ip_DmaRxCompleteCallback(void);
void Linflexd_12_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
void MSC_0_Lin_Uart_Ip_DmaRxCompleteCallback(void);
void MSC_0_Lin_Uart_Ip_DmaTxCompleteCallback(void);
#endif
#endif

#endif

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* LINFLEXD_UART_IP_IRQ_H */
