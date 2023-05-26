/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/**
*   @file       Power_Ip_MC_RGM_Irq.c
*   @version    3.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip_Cfg.h"
#include "Power_Ip_MC_RGM.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_MC_RGM_IRQ_VENDOR_ID_C                      43
#define POWER_IP_MC_RGM_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_MC_RGM_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_MC_RGM_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_MC_RGM_IRQ_SW_MAJOR_VERSION_C               3
#define POWER_IP_MC_RGM_IRQ_SW_MINOR_VERSION_C               0
#define POWER_IP_MC_RGM_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_Cfg.h file are of the same vendor */
#if (POWER_IP_MC_RGM_IRQ_VENDOR_ID_C != POWER_IP_CFG_VENDOR_ID)
    #error "Power_Ip_MC_RGM_Irq.c and Power_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_Cfg.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_IRQ_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM_Irq.c and Power_Ip_Cfg.h are different"
#endif

/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_Cfg.h file are of the same Software version */
#if ((POWER_IP_MC_RGM_IRQ_SW_MAJOR_VERSION_C != POWER_IP_CFG_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_SW_MINOR_VERSION_C != POWER_IP_CFG_SW_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_SW_PATCH_VERSION_C != POWER_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_RGM_Irq.c and Power_Ip_Cfg.h are different"
#endif

/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_MC_RGM.h file are of the same vendor */
#if (POWER_IP_MC_RGM_IRQ_VENDOR_ID_C != POWER_IP_MC_RGM_VENDOR_ID)
    #error "Power_Ip_MC_RGM_Irq.c and Power_Ip_MC_RGM.h have different vendor ids"
#endif

/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_MC_RGM.h file are of the same Autosar version */
#if ((POWER_IP_MC_RGM_IRQ_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_AR_RELEASE_MINOR_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_AR_RELEASE_REVISION_VERSION_C != POWER_IP_MC_RGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_MC_RGM_Irq.c and Power_Ip_MC_RGM.h are different"
#endif

/* Check if Power_Ip_MC_RGM_Irq.c file and Power_Ip_MC_RGM.h file are of the same Software version */
#if ((POWER_IP_MC_RGM_IRQ_SW_MAJOR_VERSION_C != POWER_IP_MC_RGM_SW_MAJOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_SW_MINOR_VERSION_C != POWER_IP_MC_RGM_SW_MINOR_VERSION) || \
     (POWER_IP_MC_RGM_IRQ_SW_PATCH_VERSION_C != POWER_IP_MC_RGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_MC_RGM_Irq.c and Power_Ip_MC_RGM.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef POWER_IP_RESET_ALTERNATE_ISR_USED
#if (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON)

ISR(MC_RGM_ResetAlt_IRQHandler);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/* This function handles both the 'Functional' and 'Destructive' Reset Alternate Event Interrupts. */
ISR(MC_RGM_ResetAlt_IRQHandler)
{
    Power_Ip_MC_RGM_ResetAltInt();
    EXIT_INTERRUPT();
}

#endif
#endif /* POWER_IP_RESET_ALTERNATE_ISR_USED */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

