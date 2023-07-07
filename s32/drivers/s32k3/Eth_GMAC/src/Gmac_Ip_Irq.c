/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip_Hw_Access.h"
#include "Gmac_Ip_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_IRQ_VENDOR_ID_C                      43
#define GMAC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define GMAC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define GMAC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define GMAC_IP_IRQ_SW_MAJOR_VERSION_C               3
#define GMAC_IP_IRQ_SW_MINOR_VERSION_C               0
#define GMAC_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_Hw_Access.h */
#if (GMAC_IP_IRQ_VENDOR_ID_C != GMAC_IP_HW_ACCESS_VENDOR_ID)
    #error "Gmac_Ip_Irq.c and Gmac_Ip_Hw_Access.h have different vendor ids"
#endif
#if ((GMAC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Irq.c and Gmac_Ip_Hw_Access.h are different"
#endif
#if ((GMAC_IP_IRQ_SW_MAJOR_VERSION_C != GMAC_IP_HW_ACCESS_SW_MAJOR_VERSION) || \
     (GMAC_IP_IRQ_SW_MINOR_VERSION_C != GMAC_IP_HW_ACCESS_SW_MINOR_VERSION) || \
     (GMAC_IP_IRQ_SW_PATCH_VERSION_C != GMAC_IP_HW_ACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Irq.c and Gmac_Ip_Hw_Access.h are different"
#endif

/* Checks against Gmac_Ip_Irq.h */
#if (GMAC_IP_IRQ_VENDOR_ID_C != GMAC_IP_IRQ_VENDOR_ID)
    #error "Gmac_Ip_Irq.c and Gmac_Ip_Irq.h have different vendor ids"
#endif
#if ((GMAC_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != GMAC_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GMAC_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != GMAC_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GMAC_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != GMAC_IP_IRQ_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Irq.c and Gmac_Ip_Irq.h are different"
#endif
#if ((GMAC_IP_IRQ_SW_MAJOR_VERSION_C != GMAC_IP_IRQ_SW_MAJOR_VERSION) || \
     (GMAC_IP_IRQ_SW_MINOR_VERSION_C != GMAC_IP_IRQ_SW_MINOR_VERSION) || \
     (GMAC_IP_IRQ_SW_PATCH_VERSION_C != GMAC_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Irq.c and Gmac_Ip_Irq.h are different"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#if (FEATURE_GMAC_NUM_INSTANCES > 0U)
/* Handle common interrupt */
ISR(GMAC0_Common_IRQHandler)
{
    GMAC_CommonIRQHandler(0U);
}

  #if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
    /* Handle safety interrupt */  
    ISR(GMAC0_Safety_IRQHandler)
    {
        GMAC_SafetyIRQHandler(0U);
    }
  #endif

  #if FEATURE_GMAC_INDIVIDUAL_CH_IRQS

    #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
    /* Handle Tx interrupt for channel 0 */     
    ISR(GMAC0_CH0_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(0U, 0U);
    }
    /* Handle Rx interrupt for channel 0 */ 
    ISR(GMAC0_CH0_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(0U, 0U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 0U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
    /* Handle Tx interrupt for channel 1 */ 
    ISR(GMAC0_CH1_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(0U, 1U);
    }
    /* Handle Rx interrupt for channel 1 */ 
    ISR(GMAC0_CH1_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(0U, 1U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 1U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
    /* Handle Tx interrupt for channel 2 */ 
    ISR(GMAC0_CH2_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(0U, 2U);
    }
    /* Handle Rx interrupt for channel 2 */
    ISR(GMAC0_CH2_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(0U, 2U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 2U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
    /* Handle Tx interrupt for channel 3 */
    ISR(GMAC0_CH3_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(0U, 3U);
    }
    /* Handle Rx interrupt for channel 3 */
    ISR(GMAC0_CH3_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(0U, 3U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 3U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
    /* Handle Tx interrupt for channel 4 */    
    ISR(GMAC0_CH4_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(0U, 4U);
    }
    /* Handle Rx interrupt for channel 4 */
    ISR(GMAC0_CH4_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(0U, 4U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 4U) */

  #elif FEATURE_GMAC_UNIFIED_CH_IRQS
    /* Find Tx channel flag raised */
    ISR(GMAC0_CH_TX_IRQHandler)
    {
        #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
        if ((IP_GMAC_0->DMA_CH4_STATUS & GMAC_DMA_CH4_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(0U, 4U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
        if ((IP_GMAC_0->DMA_CH3_STATUS & GMAC_DMA_CH3_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(0U, 3U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
        if ((IP_GMAC_0->DMA_CH2_STATUS & GMAC_DMA_CH2_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(0U, 2U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
        if ((IP_GMAC_0->DMA_CH1_STATUS & GMAC_DMA_CH1_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(0U, 1U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
        if ((IP_GMAC_0->DMA_CH0_STATUS & GMAC_DMA_CH0_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(0U, 0U);
        }
        #endif
    }
    
    /* Find Rx channel flag raised */
    ISR(GMAC0_CH_RX_IRQHandler)
    {
        #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
        if ((IP_GMAC_0->DMA_CH4_STATUS & GMAC_DMA_CH4_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(0U, 4U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
        if ((IP_GMAC_0->DMA_CH3_STATUS  & GMAC_DMA_CH3_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(0U, 3U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
        if ((IP_GMAC_0->DMA_CH2_STATUS  & GMAC_DMA_CH2_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(0U, 2U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
        if ((IP_GMAC_0->DMA_CH1_STATUS  & GMAC_DMA_CH1_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(0U, 1U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
        if ((IP_GMAC_0->DMA_CH0_STATUS  & GMAC_DMA_CH0_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(0U, 0U);
        }
        #endif
    }
  #endif /* FEATURE_GMAC_INDIVIDUAL_CH_IRQS */
#endif /* FEATURE_GMAC_NUM_INSTANCES > 0U*/
#if (FEATURE_GMAC_NUM_INSTANCES > 1U)
    
ISR(GMAC1_Common_IRQHandler)
{
    GMAC_CommonIRQHandler(1U);
}

  #if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
  ISR(GMAC1_Safety_IRQHandler)
  {
      GMAC_SafetyIRQHandler(1U);
  }
  #endif

  #if FEATURE_GMAC_INDIVIDUAL_CH_IRQS

    #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
    ISR(GMAC1_CH0_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(1U, 0U);
    }
    ISR(GMAC1_CH0_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(1U, 0U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 0U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
    ISR(GMAC1_CH1_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(1U, 1U);
    }
    ISR(GMAC1_CH1_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(1U, 1U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 1U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
    ISR(GMAC1_CH2_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(1U, 2U);
    }
    ISR(GMAC1_CH2_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(1U, 2U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 2U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
    ISR(GMAC1_CH3_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(1U, 3U);
    }
    ISR(GMAC1_CH3_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(1U, 3U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 3U) */

    #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
    ISR(GMAC1_CH4_TX_IRQHandler)
    {
        GMAC_TxIRQHandler(1U, 4U);
    }
    ISR(GMAC1_CH4_RX_IRQHandler)
    {
        GMAC_RxIRQHandler(1U, 4U);
    }
    #endif /* (FEATURE_GMAC_NUM_CHANNELS > 4U) */

  #elif FEATURE_GMAC_UNIFIED_CH_IRQS
    ISR(GMAC1_CH_TX_IRQHandler)
    {
        #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
        if ((IP_GMAC_1->DMA_CH4_STATUS & GMAC_DMA_CH4_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(1U, 4U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
        if ((IP_GMAC_1->DMA_CH3_STATUS & GMAC_DMA_CH3_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(1U, 3U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
        if ((IP_GMAC_1->DMA_CH2_STATUS & GMAC_DMA_CH2_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(1U, 2U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
        if ((IP_GMAC_1->DMA_CH1_STATUS & GMAC_DMA_CH1_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(1U, 1U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
        if ((IP_GMAC_1->DMA_CH0_STATUS & GMAC_DMA_CH0_STATUS_TI_MASK) != 0U)
        {
             GMAC_TxIRQHandler(1U, 0U);
        }
        #endif
    }

    ISR(GMAC1_CH_RX_IRQHandler)
    {
        #if (FEATURE_GMAC_NUM_CHANNELS > 4U)
        if ((IP_GMAC_1->DMA_CH4_STATUS & GMAC_DMA_CH4_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(1U, 4U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 3U)
        if ((IP_GMAC_1->DMA_CH3_STATUS  & GMAC_DMA_CH3_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(1U, 3U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 2U)
        if ((IP_GMAC_1->DMA_CH2_STATUS  & GMAC_DMA_CH2_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(1U, 2U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 1U)
        if ((IP_GMAC_1->DMA_CH1_STATUS  & GMAC_DMA_CH1_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(1U, 1U);
        }
        #endif
        #if (FEATURE_GMAC_NUM_CHANNELS > 0U)
        if ((IP_GMAC_1->DMA_CH0_STATUS  & GMAC_DMA_CH0_STATUS_RI_MASK) != 0U)
        {
             GMAC_RxIRQHandler(1U, 0U);
        }
        #endif
    }
  #endif /* FEATURE_GMAC_INDIVIDUAL_CH_IRQS */
#endif /* (FEATURE_GMAC_NUM_INSTANCES > 1U) */

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

