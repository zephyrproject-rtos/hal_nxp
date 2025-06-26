/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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
#include "Linflexd_Uart_Ip.h"
#include "Linflexd_Uart_Ip_Irq.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LINFLEXD_UART_IP_IRQ_VENDOR_ID_C                      43
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION_C               2
#define LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION_C               0
#define LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Linflexd_Uart_Ip.h */
#if (LINFLEXD_UART_IP_IRQ_VENDOR_ID_C != LINFLEXD_UART_IP_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_UART_IP_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_UART_IP_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_UART_IP_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip.h are different"
#endif
#if ((LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION_C != LINFLEXD_UART_IP_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION_C != LINFLEXD_UART_IP_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION_C != LINFLEXD_UART_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip.h are different"
#endif
/* Checks against Linflexd_Uart_Ip_Irq.h */
#if (LINFLEXD_UART_IP_IRQ_VENDOR_ID_C != LINFLEXD_UART_IP_IRQ_VENDOR_ID)
    #error "Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip_Irq.h have different vendor ids"
#endif
#if ((LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != LINFLEXD_UART_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != LINFLEXD_UART_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LINFLEXD_UART_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip_Irq.h are different"
#endif
#if ((LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION_C != LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION_C != LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION) || \
     (LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION_C != LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Linflexd_Uart_Ip_Irq.c and Linflexd_Uart_Ip_Irq.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define UART_START_SEC_CODE
#include "Uart_MemMap.h"

#if (LINFLEXD_IP_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
/* Implementation of LINFLEXD0 handler named in startup code. */
ISR(LINFLEXD0_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(0U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
/* Implementation of LINFLEXD1 handler named in startup code. */
ISR(LINFLEXD1_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(1U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
/* Implementation of LINFLEXD2 handler named in startup code. */
ISR(LINFLEXD2_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(2U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
/* Implementation of LINFLEXD3 handler named in startup code. */
ISR(LINFLEXD3_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(3U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
/* Implementation of LINFLEXD4 handler named in startup code. */
ISR(LINFLEXD4_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(4U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
/* Implementation of LINFLEXD5 handler named in startup code. */
ISR(LINFLEXD5_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(5U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 6U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
/* Implementation of LINFLEXD6 handler named in startup code. */
ISR(LINFLEXD6_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(6U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
/* Implementation of LINFLEXD7 handler named in startup code. */
ISR(LINFLEXD7_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(7U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
/* Implementation of LINFLEXD8 handler named in startup code. */
ISR(LINFLEXD8_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(8U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
/* Implementation of LINFLEXD9 handler named in startup code. */
ISR(LINFLEXD9_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(9U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
/* Implementation of LINFLEXD10 handler named in startup code. */
ISR(LINFLEXD10_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(10U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
/* Implementation of LINFLEXD11 handler named in startup code. */
ISR(LINFLEXD11_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(11U);
}
#endif
#endif
#if (LINFLEXD_IP_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
/* Implementation of LINFLEXD12 handler named in startup code. */
ISR(LINFLEXD12_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(12U);
}
#endif /* (LINFLEXD_UART_IP_INSTANCE_USING_12)*/

#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
/* Implementation of MSC handler named in startup code. */
ISR(MSC_0_LIN_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(12U);
}
#endif /* LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN */
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 13U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_13
/* Implementation of LINFLEXD13 handler named in startup code. */
ISR(LINFLEXD13_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(13U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 14U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_14
/* Implementation of LINFLEXD14 handler named in startup code. */
ISR(LINFLEXD14_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(14U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 15U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_15
/* Implementation of LINFLEXD15 handler named in startup code. */
ISR(LINFLEXD15_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(15U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 16U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_16
/* Implementation of LINFLEXD16 handler named in startup code. */
ISR(LINFLEXD16_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(16U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 17U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_17
/* Implementation of LINFLEXD17 handler named in startup code. */
ISR(LINFLEXD17_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(17U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 18U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_18
/* Implementation of LINFLEXD18 handler named in startup code. */
ISR(LINFLEXD18_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(18U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 19U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_19
/* Implementation of LINFLEXD19 handler named in startup code. */
ISR(LINFLEXD19_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(19U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 20U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_20
/* Implementation of LINFLEXD20 handler named in startup code. */
ISR(LINFLEXD20_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(20U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 21U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_21
/* Implementation of LINFLEXD21 handler named in startup code. */
ISR(LINFLEXD21_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(21U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 22U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_22
/* Implementation of LINFLEXD22 handler named in startup code. */
ISR(LINFLEXD22_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(22U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 23U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_23
/* Implementation of LINFLEXD23 handler named in startup code. */
ISR(LINFLEXD23_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(23U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 24U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_24
/* Implementation of LINFLEXD24 handler named in startup code. */
ISR(LINFLEXD24_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(24U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 25U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_25
/* Implementation of LINFLEXD25 handler named in startup code. */
ISR(LINFLEXD25_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(25U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 26U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_26
/* Implementation of LINFLEXD26 handler named in startup code. */
ISR(LINFLEXD26_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(26U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 27U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_27
/* Implementation of LINFLEXD27 handler named in startup code. */
ISR(LINFLEXD27_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(27U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 28U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_28
/* Implementation of LINFLEXD28 handler named in startup code. */
ISR(LINFLEXD28_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(28U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 29U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_29
/* Implementation of LINFLEXD29 handler named in startup code. */
ISR(LINFLEXD29_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(29U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 30U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_30
/* Implementation of LINFLEXD30 handler named in startup code. */
ISR(LINFLEXD30_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(30U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 31U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_31
/* Implementation of LINFLEXD31 handler named in startup code. */
ISR(LINFLEXD31_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(31U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 32U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_32
/* Implementation of LINFLEXD32 handler named in startup code. */
ISR(LINFLEXD32_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(32U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 33U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_33
/* Implementation of LINFLEXD33 handler named in startup code. */
ISR(LINFLEXD33_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(33U);
}
#endif
#endif

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (LINFLEXD_IP_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
/* Implementation of LINFlexD0 Tx callback function for Dma interrupt. */
void Linflexd_0_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(0U);
}
/* Implementation of LINFlexD0 Rx callback function for Dma interrupt. */
void Linflexd_0_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(0U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
/* Implementation of LINFlexD1 Tx callback function for Dma interrupt. */
void Linflexd_1_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(1U);
}
/* Implementation of LINFlexD1 Rx callback function for Dma interrupt. */
void Linflexd_1_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(1U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
/* Implementation of LINFlexD2 Tx callback function for Dma interrupt. */
void Linflexd_2_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(2U);
}
/* Implementation of LINFlexD2 Rx callback function for Dma interrupt. */
void Linflexd_2_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(2U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
/* Implementation of LINFlexD3 Tx callback function for Dma interrupt. */
void Linflexd_3_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(3U);
}
/* Implementation of LINFlexD3 Rx callback function for Dma interrupt. */
void Linflexd_3_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(3U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
/* Implementation of LINFlexD4 Tx callback function for Dma interrupt. */
void Linflexd_4_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(4U);
}
/* Implementation of LINFlexD4 Rx callback function for Dma interrupt. */
void Linflexd_4_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(4U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
/* Implementation of LINFlexD5 Tx callback function for Dma interrupt. */
void Linflexd_5_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(5U);
}
/* Implementation of LINFlexD5 Rx callback function for Dma interrupt. */
void Linflexd_5_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(5U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 6U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
/* Implementation of LINFlexD6 Tx callback function for Dma interrupt. */
void Linflexd_6_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(6U);
}
/* Implementation of LINFlexD6 Rx callback function for Dma interrupt. */
void Linflexd_6_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(6U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
/* Implementation of LINFlexD7 Tx callback function for Dma interrupt. */
void Linflexd_7_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(7U);
}
/* Implementation of LINFlexD7 Rx callback function for Dma interrupt. */
void Linflexd_7_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(7U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
/* Implementation of LINFlexD8 Tx callback function for Dma interrupt. */
void Linflexd_8_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(8U);
}
/* Implementation of LINFlexD8 Rx callback function for Dma interrupt. */
void Linflexd_8_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(8U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
/* Implementation of LINFlexD9 Tx callback function for Dma interrupt. */
void Linflexd_9_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(9U);
}
/* Implementation of LINFlexD9 Rx callback function for Dma interrupt. */
void Linflexd_9_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(9U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
/* Implementation of LINFlexD10 Tx callback function for Dma interrupt. */
void Linflexd_10_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(10U);
}
/* Implementation of LINFlexD10 Rx callback function for Dma interrupt. */
void Linflexd_10_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(10U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
/* Implementation of LINFlexD11 Tx callback function for Dma interrupt. */
void Linflexd_11_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(11U);
}
/* Implementation of LINFlexD11 Rx callback function for Dma interrupt. */
void Linflexd_11_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(11U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
/* Implementation of LINFlexD12 Tx callback function for Dma interrupt. */
void Linflexd_12_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(12U);
}
/* Implementation of LINFlexD12 Rx callback function for Dma interrupt. */
void Linflexd_12_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(12U);
}
#endif

#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
/* Implementation of LINFlexD12 Tx callback function for Dma interrupt. */
void MSC_0_Lin_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(12U);
}
/* Implementation of LINFlexD12 Rx callback function for Dma interrupt. */
void MSC_0_Lin_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(12U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 13U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_13
/* Implementation of LINFlexD13 Tx callback function for Dma interrupt. */
void Linflexd_13_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(13U);
}
/* Implementation of LINFlexD13 Rx callback function for Dma interrupt. */
void Linflexd_13_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(13U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 14U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_14
/* Implementation of LINFlexD14 Tx callback function for Dma interrupt. */
void Linflexd_14_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(14U);
}
/* Implementation of LINFlexD14 Rx callback function for Dma interrupt. */
void Linflexd_14_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(14U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 15U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_15
/* Implementation of LINFlexD15 Tx callback function for Dma interrupt. */
void Linflexd_15_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(15U);
}
/* Implementation of LINFlexD15 Rx callback function for Dma interrupt. */
void Linflexd_15_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(15U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 16U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_16
/* Implementation of LINFlexD16 Tx callback function for Dma interrupt. */
void Linflexd_16_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(16U);
}
/* Implementation of LINFlexD16 Rx callback function for Dma interrupt. */
void Linflexd_16_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(16U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 17U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_17
/* Implementation of LINFlexD17 Tx callback function for Dma interrupt. */
void Linflexd_17_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(17U);
}
/* Implementation of LINFlexD17 Rx callback function for Dma interrupt. */
void Linflexd_17_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(17U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 18U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_18
/* Implementation of LINFlexD18 Tx callback function for Dma interrupt. */
void Linflexd_18_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(18U);
}
/* Implementation of LINFlexD18 Rx callback function for Dma interrupt. */
void Linflexd_18_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(18U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 19U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_19
/* Implementation of LINFlexD19 Tx callback function for Dma interrupt. */
void Linflexd_19_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(19U);
}
/* Implementation of LINFlexD19 Rx callback function for Dma interrupt. */
void Linflexd_19_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(19U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 20U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_20
/* Implementation of LINFlexD20 Tx callback function for Dma interrupt. */
void Linflexd_20_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(20U);
}
/* Implementation of LINFlexD20 Rx callback function for Dma interrupt. */
void Linflexd_20_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(20U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 21U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_21
/* Implementation of LINFlexD21 Tx callback function for Dma interrupt. */
void Linflexd_21_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(21U);
}
/* Implementation of LINFlexD21 Rx callback function for Dma interrupt. */
void Linflexd_21_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(21U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 22U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_22
/* Implementation of LINFlexD22 Tx callback function for Dma interrupt. */
void Linflexd_22_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(22U);
}
/* Implementation of LINFlexD22 Rx callback function for Dma interrupt. */
void Linflexd_22_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(22U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 23U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_23
/* Implementation of LINFlexD23 Tx callback function for Dma interrupt. */
void Linflexd_23_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(23U);
}
/* Implementation of LINFlexD23 Rx callback function for Dma interrupt. */
void Linflexd_23_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(23U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 24U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_24
/* Implementation of LINFlexD24 Tx callback function for Dma interrupt. */
void Linflexd_24_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(24U);
}
/* Implementation of LINFlexD24 Rx callback function for Dma interrupt. */
void Linflexd_24_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(24U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 25U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_25
/* Implementation of LINFlexD25 Tx callback function for Dma interrupt. */
void Linflexd_25_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(25U);
}
/* Implementation of LINFlexD25 Rx callback function for Dma interrupt. */
void Linflexd_25_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(25U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 26U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_26
/* Implementation of LINFlexD26 Tx callback function for Dma interrupt. */
void Linflexd_26_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(26U);
}
/* Implementation of LINFlexD26 Rx callback function for Dma interrupt. */
void Linflexd_26_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(26U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 27U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_27
/* Implementation of LINFlexD27 Tx callback function for Dma interrupt. */
void Linflexd_27_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(27U);
}
/* Implementation of LINFlexD27 Rx callback function for Dma interrupt. */
void Linflexd_27_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(27U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 28U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_28
/* Implementation of LINFlexD28 Tx callback function for Dma interrupt. */
void Linflexd_28_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(28U);
}
/* Implementation of LINFlexD28 Rx callback function for Dma interrupt. */
void Linflexd_28_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(28U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 29U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_29
/* Implementation of LINFlexD29 Tx callback function for Dma interrupt. */
void Linflexd_29_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(29U);
}
/* Implementation of LINFlexD29 Rx callback function for Dma interrupt. */
void Linflexd_29_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(29U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 30U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_30
/* Implementation of LINFlexD30 Tx callback function for Dma interrupt. */
void Linflexd_30_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(30U);
}
/* Implementation of LINFlexD30 Rx callback function for Dma interrupt. */
void Linflexd_30_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(30U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 31U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_31
/* Implementation of LINFlexD31 Tx callback function for Dma interrupt. */
void Linflexd_31_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(31U);
}
/* Implementation of LINFlexD31 Rx callback function for Dma interrupt. */
void Linflexd_31_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(31U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 32U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_32
/* Implementation of LINFlexD32 Tx callback function for Dma interrupt. */
void Linflexd_32_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(32U);
}
/* Implementation of LINFlexD32 Rx callback function for Dma interrupt. */
void Linflexd_32_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(32U);
}
#endif
#endif

#if (LINFLEXD_IP_INSTANCE_COUNT > 33U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_33
/* Implementation of LINFlexD33 Tx callback function for Dma interrupt. */
void Linflexd_33_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(33U);
}
/* Implementation of LINFlexD33 Rx callback function for Dma interrupt. */
void Linflexd_33_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(33U);
}
#endif
#endif

#endif /* (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON) */

#define UART_STOP_SEC_CODE
#include "Uart_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
