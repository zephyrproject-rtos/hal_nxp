/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file    Spi_Ip_Irq.c
*   @implements     Spi_Ip_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
*
*   @addtogroup SPI_IP_DRIVER Spi Ip Driver
*   @{
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
#include "Spi_Ip.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_VENDOR_ID_IRQ_C                      43
#define SPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define SPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C       7
#define SPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C    0
#define SPI_IP_SW_MAJOR_VERSION_IRQ_C               2
#define SPI_IP_SW_MINOR_VERSION_IRQ_C               0
#define SPI_IP_SW_PATCH_VERSION_IRQ_C               1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ip.h and Spi_Ip_Irq.c are of the same vendor */
#if (SPI_IP_VENDOR_ID != SPI_IP_VENDOR_ID_IRQ_C)
    #error "Spi_Ip.h and Spi_Ip_Irq.c have different vendor ids"
#endif
/* Check if Spi_Ip.h file and Spi_Ip_Irq.c file are of the same Autosar version */
#if ((SPI_IP_AR_RELEASE_MAJOR_VERSION != SPI_IP_AR_RELEASE_MAJOR_VERSION_IRQ_C) || \
     (SPI_IP_AR_RELEASE_MINOR_VERSION != SPI_IP_AR_RELEASE_MINOR_VERSION_IRQ_C) || \
     (SPI_IP_AR_RELEASE_REVISION_VERSION != SPI_IP_AR_RELEASE_REVISION_VERSION_IRQ_C))
#error "AutoSar Version Numbers of Spi_Ip.h and Spi_Ip_Irq.c are different"
#endif
#if ((SPI_IP_SW_MAJOR_VERSION != SPI_IP_SW_MAJOR_VERSION_IRQ_C) || \
     (SPI_IP_SW_MINOR_VERSION != SPI_IP_SW_MINOR_VERSION_IRQ_C) || \
     (SPI_IP_SW_PATCH_VERSION != SPI_IP_SW_PATCH_VERSION_IRQ_C))
#error "Software Version Numbers of Spi_Ip.h and Spi_Ip_Irq.c are different"
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#ifdef SPI_IP_0_ENABLED
    #if (SPI_IP_0_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_0_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_0_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_1_ENABLED
    #if (SPI_IP_1_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_1_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_1_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_2_ENABLED
    #if (SPI_IP_2_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_2_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_2_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_3_ENABLED
    #if (SPI_IP_3_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_3_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_3_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_4_ENABLED
    #if (SPI_IP_4_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_4_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_4_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_5_ENABLED
    #if (SPI_IP_5_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_5_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_5_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_6_ENABLED
    #if (SPI_IP_6_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_6_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_6_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_7_ENABLED
    #if (SPI_IP_7_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_7_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_7_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_8_ENABLED
    #if (SPI_IP_8_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_8_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_8_IrqDmaHandler(void);
        #endif
    #endif
#endif
#ifdef SPI_IP_9_ENABLED
    #if (SPI_IP_9_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_9_IRQHandler);
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_9_IrqDmaHandler(void);
        #endif
    #endif
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef SPI_IP_0_ENABLED
    #if (SPI_IP_0_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_0_IRQHandler)
{
    /* Calling interrupt handler for instance 0 */
    Spi_Ip_IrqHandler(0u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_0_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 0 */
    Spi_Ip_IrqDmaHandler(0u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_1_ENABLED
    #if (SPI_IP_1_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_1_IRQHandler)
{
    /* Calling interrupt handler for instance 1 */
    Spi_Ip_IrqHandler(1u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_1_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 1 */
    Spi_Ip_IrqDmaHandler(1u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_2_ENABLED
    #if (SPI_IP_2_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_2_IRQHandler)
{
    /* Calling interrupt handler for instance 2 */
    Spi_Ip_IrqHandler(2u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_2_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 2 */
    Spi_Ip_IrqDmaHandler(2u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_3_ENABLED
    #if (SPI_IP_3_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_3_IRQHandler)
{
    /* Calling interrupt handler for instance 3 */
    Spi_Ip_IrqHandler(3u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_3_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 3 */
    Spi_Ip_IrqDmaHandler(3u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_4_ENABLED
    #if (SPI_IP_4_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_4_IRQHandler)
{
    /* Calling interrupt handler for instance 4 */
    Spi_Ip_IrqHandler(4u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_4_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 4 */
    Spi_Ip_IrqDmaHandler(4u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_5_ENABLED
    #if (SPI_IP_5_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_5_IRQHandler)
{
    /* Calling interrupt handler for instance 5 */
    Spi_Ip_IrqHandler(5u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_5_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 5 */
    Spi_Ip_IrqDmaHandler(5u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_6_ENABLED
    #if (SPI_IP_6_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_6_IRQHandler)
{
    /* Calling interrupt handler for instance 6 */
    Spi_Ip_IrqHandler(6u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_6_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 6 */
    Spi_Ip_IrqDmaHandler(6u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_7_ENABLED
    #if (SPI_IP_7_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_7_IRQHandler)
{
    /* Calling interrupt handler for instance 7 */
    Spi_Ip_IrqHandler(7u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_7_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 7 */
    Spi_Ip_IrqDmaHandler(7u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_8_ENABLED
    #if (SPI_IP_8_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_8_IRQHandler)
{
    /* Calling interrupt handler for instance 8 */
    Spi_Ip_IrqHandler(8u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_8_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 8 */
    Spi_Ip_IrqDmaHandler(8u);
}
        #endif
    #endif
#endif
#ifdef SPI_IP_9_ENABLED
    #if (SPI_IP_9_ENABLED == STD_ON)
ISR(Spi_Ip_SPI_9_IRQHandler)
{
    /* Calling interrupt handler for instance 9 */
    Spi_Ip_IrqHandler(9u);
}
        #if (SPI_IP_DMA_USED == STD_ON)
void Spi_Ip_SPI_9_IrqDmaHandler(void)
{
    /* Calling dma handler for instance 9 */
    Spi_Ip_IrqDmaHandler(9u);
}
        #endif
    #endif
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
