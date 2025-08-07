/*
 * Copyright 2021-2025 NXP
*
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup CRYPTO
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
#include "Mcal.h"
#include "Hse_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MU_IP_IRQ_VENDOR_ID_C                    43
#define MU_IP_IRQ_SW_MAJOR_VERSION_C             2
#define MU_IP_IRQ_SW_MINOR_VERSION_C             0
#define MU_IP_IRQ_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mu_Ip_Irq source file and Mcal.h header file are of the same vendor */
#if (MU_IP_IRQ_VENDOR_ID_C != MCAL_VENDOR_ID)
    #error "Mu_Ip_Irq.c and Mcal.h have different vendor ids"
#endif

/* Check if Mu_Ip_Irq source file and Mcal.h header file are of the same Software version */
#if ((MU_IP_IRQ_SW_MAJOR_VERSION_C != MCAL_SW_MAJOR_VERSION) || \
     (MU_IP_IRQ_SW_MINOR_VERSION_C != MCAL_SW_MINOR_VERSION) || \
     (MU_IP_IRQ_SW_PATCH_VERSION_C != MCAL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Mu_Ip_Irq.c and Mcal.h are different"
#endif

/* Check if Mu_Ip_Irq source file and Hse_Ip.h header file are of the same vendor */
#if (MU_IP_IRQ_VENDOR_ID_C != HSE_IP_VENDOR_ID_H)
    #error "Mu_Ip_Irq.c and Hse_Ip.h have different vendor ids"
#endif

/* Check if Mu_Ip_Irq source file and Hse_Ip.h header file are of the same Software version */
#if ((MU_IP_IRQ_SW_MAJOR_VERSION_C != HSE_IP_SW_MAJOR_VERSION_H) || \
     (MU_IP_IRQ_SW_MINOR_VERSION_C != HSE_IP_SW_MINOR_VERSION_H) || \
     (MU_IP_IRQ_SW_PATCH_VERSION_C != HSE_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Mu_Ip_Irq.c and Hse_Ip.h are different"
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
*                                        GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define CRYPTO_43_HSE_START_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"

ISR(Mu_Ip_Mu0_OredRx_Isr);
ISR(Mu_Ip_Mu0_OredGP_Isr);

#if (HSE_IP_NUM_OF_MU_INSTANCES > 1U)
    ISR(Mu_Ip_Mu1_OredRx_Isr);
    ISR(Mu_Ip_Mu1_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 1U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 2U)
    ISR(Mu_Ip_Mu2_OredRx_Isr);
    ISR(Mu_Ip_Mu2_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 2U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 3U)
    ISR(Mu_Ip_Mu3_OredRx_Isr);
    ISR(Mu_Ip_Mu3_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 3U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 4U)
    ISR(Mu_Ip_Mu4_OredRx_Isr);
    ISR(Mu_Ip_Mu4_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 4U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 5U)
    ISR(Mu_Ip_Mu5_OredRx_Isr);
    ISR(Mu_Ip_Mu5_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 5U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 6U)
    ISR(Mu_Ip_Mu6_OredRx_Isr);
    ISR(Mu_Ip_Mu6_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 6U) */

#if (HSE_IP_NUM_OF_MU_INSTANCES > 7U)
    ISR(Mu_Ip_Mu7_OredRx_Isr);
    ISR(Mu_Ip_Mu7_OredGP_Isr);
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 7U) */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 0.
*
* @isr
*
*/
ISR(Mu_Ip_Mu0_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(0U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 0.
*
* @isr
*
*/
ISR(Mu_Ip_Mu0_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(0U);
}

#if (HSE_IP_NUM_OF_MU_INSTANCES > 1U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 1.
*
* @isr
*
*/
ISR(Mu_Ip_Mu1_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(1U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 1.
*
* @isr
*
*/
ISR(Mu_Ip_Mu1_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(1U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 1U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 2U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 2.
*
* @isr
*
*/
ISR(Mu_Ip_Mu2_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(2U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 2.
*
* @isr
*
*/
ISR(Mu_Ip_Mu2_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(2U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 2U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 3U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 3.
*
* @isr
*
*/
ISR(Mu_Ip_Mu3_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(3U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 3.
*
* @isr
*
*/
ISR(Mu_Ip_Mu3_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(3U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 3U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 4U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 4.
*
* @isr
*
*/
ISR(Mu_Ip_Mu4_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(4U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 4.
*
* @isr
*
*/
ISR(Mu_Ip_Mu4_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(4U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 4U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 5U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 5.
*
* @isr
*
*/
ISR(Mu_Ip_Mu5_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(5U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 5.
*
* @isr
*
*/
ISR(Mu_Ip_Mu5_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(5U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 5U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 6U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 6.
*
* @isr
*
*/
ISR(Mu_Ip_Mu6_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(6U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 6.
*
* @isr
*
*/
ISR(Mu_Ip_Mu6_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(6U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 6U) */


#if (HSE_IP_NUM_OF_MU_INSTANCES > 7U)
/**
* @brief   Crypto handler for a MU instance RX interrupt.
* @details This function implements the ISR occurring on an Rx event on the MU instance 7.
*
* @isr
*
*/
ISR(Mu_Ip_Mu7_OredRx_Isr)
{
    Hse_Ip_RxIrqHandler(7U);
}

/**
* @brief   Crypto handler for a MU instance General Purpose interrupt.
* @details This function implements the ISR occurring on an General Purpose event on the MU instance 7.
*
* @isr
*
*/
ISR(Mu_Ip_Mu7_OredGP_Isr)
{
    Hse_Ip_GeneralPurposeIrqHandler(7U);
}
#endif /* (HSE_IP_NUM_OF_MU_INSTANCES > 7U) */

#define CRYPTO_43_HSE_STOP_SEC_CODE
#include "Crypto_43_HSE_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
