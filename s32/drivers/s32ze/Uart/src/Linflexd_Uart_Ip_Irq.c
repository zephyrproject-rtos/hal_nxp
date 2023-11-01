/*
 * Copyright 2021-2023 NXP
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
#define LINFLEXD_UART_IP_IRQ_SW_MAJOR_VERSION_C               1
#define LINFLEXD_UART_IP_IRQ_SW_MINOR_VERSION_C               0
#define LINFLEXD_UART_IP_IRQ_SW_PATCH_VERSION_C               0

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

#if (LINFLEXD_INSTANCE_COUNT > 0U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_0
/* Implementation of LINFLEXD0 handler named in startup code. */
ISR(LINFLEXD0_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(0U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 1U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_1
/* Implementation of LINFLEXD1 handler named in startup code. */
ISR(LINFLEXD1_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(1U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 2U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_2
/* Implementation of LINFLEXD2 handler named in startup code. */
ISR(LINFLEXD2_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(2U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 3U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_3
/* Implementation of LINFLEXD3 handler named in startup code. */
ISR(LINFLEXD3_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(3U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 4U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_4
/* Implementation of LINFLEXD4 handler named in startup code. */
ISR(LINFLEXD4_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(4U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 5U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_5
/* Implementation of LINFLEXD5 handler named in startup code. */
ISR(LINFLEXD5_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(5U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 6U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_6
/* Implementation of LINFLEXD6 handler named in startup code. */
ISR(LINFLEXD6_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(6U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 7U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_7
/* Implementation of LINFLEXD7 handler named in startup code. */
ISR(LINFLEXD7_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(7U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 8U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_8
/* Implementation of LINFLEXD8 handler named in startup code. */
ISR(LINFLEXD8_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(8U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 9U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_9
/* Implementation of LINFLEXD9 handler named in startup code. */
ISR(LINFLEXD9_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(9U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 10U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_10
/* Implementation of LINFLEXD10 handler named in startup code. */
ISR(LINFLEXD10_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(10U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 11U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_11
/* Implementation of LINFLEXD11 handler named in startup code. */
ISR(LINFLEXD11_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(11U);
}
#endif
#endif
#if (LINFLEXD_INSTANCE_COUNT > 12U)
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_12
/* Implementation of LINFLEXD12 handler named in startup code. */
ISR(LINFLEXD12_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(12U);
}
#endif
#ifdef LINFLEXD_UART_IP_INSTANCE_USING_MSC_0_LIN
/* Implementation of MSC_0_LIN handler named in startup code. */
ISR(MSC_0_LIN_UART_IRQHandler)
{
    Linflexd_Uart_Ip_IRQHandler(12U);
}
#endif
#endif

#if (LINFLEXD_UART_IP_HAS_DMA_ENABLED == STD_ON)
#if (LINFLEXD_INSTANCE_COUNT > 0U)
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

#if (LINFLEXD_INSTANCE_COUNT > 1U)
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

#if (LINFLEXD_INSTANCE_COUNT > 2U)
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

#if (LINFLEXD_INSTANCE_COUNT > 3U)
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

#if (LINFLEXD_INSTANCE_COUNT > 4U)
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

#if (LINFLEXD_INSTANCE_COUNT > 5U)
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

#if (LINFLEXD_INSTANCE_COUNT > 6U)
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

#if (LINFLEXD_INSTANCE_COUNT > 7U)
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

#if (LINFLEXD_INSTANCE_COUNT > 8U)
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

#if (LINFLEXD_INSTANCE_COUNT > 9U)
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

#if (LINFLEXD_INSTANCE_COUNT > 10U)
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

#if (LINFLEXD_INSTANCE_COUNT > 11U)
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

#if (LINFLEXD_INSTANCE_COUNT > 12U)
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
/* Implementation of MSC_0_LIN Tx callback function for Dma interrupt. */
void MSC_0_Lin_Uart_Ip_DmaTxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteSendUsingDma(12U);
}
/* Implementation of MSC_0_LIN Rx callback function for Dma interrupt. */
void MSC_0_Lin_Uart_Ip_DmaRxCompleteCallback(void)
{
    Linflexd_Uart_Ip_CompleteReceiveUsingDma(12U);
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
