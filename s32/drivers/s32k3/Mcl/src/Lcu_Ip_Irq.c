/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Lcu_Ip_Irq.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Lcu Ip driver source file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Lcu_Ip_Irq.h"
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
#include "Lcu_Ip_Multicore.h"
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_IRQ_VENDOR_ID_C                       43
#define LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define LCU_IP_IRQ_SW_MAJOR_VERSION_C                3
#define LCU_IP_IRQ_SW_MINOR_VERSION_C                0
#define LCU_IP_IRQ_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Irq.h file are of the same vendor */
#if (LCU_IP_IRQ_VENDOR_ID_C != LCU_IP_IRQ_VENDOR_ID)
    #error "Lcu_Ip_Irq.c and Lcu_Ip_Irq.h have different vendor ids"
#endif

/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Irq.h file are of the same Autosar version */
#if ((LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Irq.c and Lcu_Ip_Irq.h are different"
#endif

/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Irq.h file are of the same Software version */
#if ((LCU_IP_IRQ_SW_MAJOR_VERSION_C != LCU_IP_IRQ_SW_MAJOR_VERSION) || \
     (LCU_IP_IRQ_SW_MINOR_VERSION_C != LCU_IP_IRQ_SW_MINOR_VERSION) || \
     (LCU_IP_IRQ_SW_PATCH_VERSION_C != LCU_IP_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Irq.c and Lcu_Ip_Irq.h are different"
#endif

#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Multicore.h file are of the same vendor */
#if (LCU_IP_IRQ_VENDOR_ID_C != LCU_IP_MULTICORE_VENDOR_ID)
    #error "Lcu_Ip_Irq.c and Lcu_Ip_Multicore.h have different vendor ids"
#endif

/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Multicore.h file are of the same Autosar version */
#if ((LCU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != LCU_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Irq.c and Lcu_Ip_Multicore.h are different"
#endif

/* Check if Lcu_Ip_Irq.c file and Lcu_Ip_Multicore.h file are of the same Software version */
#if ((LCU_IP_IRQ_SW_MAJOR_VERSION_C != LCU_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (LCU_IP_IRQ_SW_MINOR_VERSION_C != LCU_IP_MULTICORE_SW_MINOR_VERSION) || \
     (LCU_IP_IRQ_SW_PATCH_VERSION_C != LCU_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Irq.c and Lcu_Ip_Multicore.h are different"
#endif
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

#if (STD_ON == LCU_IP_IS_AVAILABLE)
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"
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
ISR(Lcu0_Ip_IRQHandler);

ISR(Lcu1_Ip_IRQHandler);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
/* LUT */
static inline boolean HwAcc_Lcu_GetLutIntEnable(const uint32 IntEn, uint8 HwOutput)
{
    boolean RetStatus = FALSE;
    /* Get Lut Int Enable*/
    if (IntEn & (LUT_INT_ENABLE_MASK << HwOutput))
    {
        RetStatus = TRUE;
    }
    return RetStatus;
}

static inline boolean HwAcc_Lcu_GetLutStatus(const uint32 Status, const uint8 HwOutput)
{
    boolean RetStatus = FALSE;
    /* Get Lut Status */
    if (Status & (LUT_STS_EVENT_MASK << HwOutput))
    {
        RetStatus = TRUE;
    }
    return RetStatus;
}

static inline void HwAcc_Lcu_ClearLutStatus(const uint8 LcuId, const uint8 LcId, const uint8 HwOutput)
{
    /* Clear Lut Status */
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    PtBase->LC[LcId].STS = LCU_STS_LUT_STS((uint32)1U << HwOutput);
}


/* FORCE */
static inline boolean HwAcc_Lcu_GetForceIntEnable(const uint32 IntEn, const uint8 HwOutput)
{
    boolean RetStatus = FALSE;
    /* Get Force Int Enable */
    if (IntEn & (FORCE_INT_ENABLE_MASK << HwOutput))
    {
        RetStatus = TRUE;
    }
    return RetStatus;
}

static inline boolean HwAcc_Lcu_GetForceStatus(const uint32 Status, const uint8 HwOutput)
{
    boolean RetStatus = FALSE;
    /* Get Force Status */
    if (Status & (FORCE_STS_EVENT_MASK << HwOutput))
    {
        RetStatus = TRUE;
    }
    return RetStatus;
}

static inline void HwAcc_Lcu_ClearForceStatus(const uint8 LcuId, const uint8 HwOutput)
{
    /* Clear Force Status */
    LCU_Type * PtBase = Lcu_Ip_paxBaseInst[LcuId];
    PtBase->FORCESTS = LCU_FORCESTS_FORCESTS((uint32)1U << HwOutput);
}

void Lcu_IrqHandler(const uint8 HwInstance)
{
    uint32 RegLcIntEn = 0U;
    uint32 RegLcStatus = 0U;
    uint8 HwLogicCell = 0U;
    uint8 HwOutput = 0U;
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    Lcu_Ip_ReturnType ReturnValue;
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

    for (HwLogicCell = 0U; HwLogicCell < LCU_LC_COUNT; HwLogicCell++)
    {
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        ReturnValue = Lcu_Ip_ValidateCore(HwInstance, HwLogicCell);
        if (ReturnValue == LCU_IP_STATUS_SUCCESS)
        {
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */

        RegLcIntEn = Lcu_Ip_paxBaseInst[HwInstance]->LC[HwLogicCell].INTDMAEN;
        RegLcStatus = Lcu_Ip_paxBaseInst[HwInstance]->LC[HwLogicCell].STS;

        if(RegLcStatus != 0U)
        {
            for(HwOutput = 0U; HwOutput < LCU_NUM_OUTPUT_PER_LC; HwOutput++)
            {
                /* If event flag was set by hardware */
                if (HwAcc_Lcu_GetLutStatus(RegLcStatus, HwOutput))
                {
                    /* If enable flag was set by user */
                    if (HwAcc_Lcu_GetLutIntEnable(RegLcIntEn, HwOutput))
                    {
                        /* Clear event flag */
                        HwAcc_Lcu_ClearLutStatus(HwInstance, HwLogicCell, HwOutput);
                        Lcu_Ip_IrqHandler(HwInstance, HwLogicCell, HwOutput, LCU_IP_LUT_EVENT);
                    }
                }
                /* If event flag was set by hardware */
                if (HwAcc_Lcu_GetForceStatus(RegLcStatus, HwOutput))
                {
                    /* If enable flag was set by user */
                    if (HwAcc_Lcu_GetForceIntEnable(RegLcIntEn, HwOutput))
                    {
                        /* Clear event flag */
                        HwAcc_Lcu_ClearForceStatus(HwInstance, HwOutput);
                        Lcu_Ip_IrqHandler(HwInstance, HwLogicCell, HwOutput, LCU_IP_FORCE_EVENT);
                    }
                }
            }
        }
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
        }
        else
        {
            /* Do Nothing */
        }
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
    }
}

ISR(Lcu0_Ip_IRQHandler)
{
    /* Lcu 0 Irq Handler */
    Lcu_IrqHandler(0U);
}

ISR(Lcu1_Ip_IRQHandler)
{
    /* Lcu 1 Irq Handler */
    Lcu_IrqHandler(1U);
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
