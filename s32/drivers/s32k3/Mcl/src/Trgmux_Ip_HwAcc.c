/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifdef __cplusplus
extern "C"{
#endif
/**
*   @file    Trgmux_Ip_HwAcc.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Trgmux Ip driver source file.
*   @details
*
*   @addtogroup TRGMUX_IP_DRIVER TRGMUX IP Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Trgmux_Ip.h"
#include "Trgmux_Ip_HwAcc.h"

#if (TRGMUX_IP_IS_AVAILABLE == STD_ON)
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_HWACC_VENDOR_ID_C                    43
#define TRGMUX_IP_HWACC_MODULE_ID_C                    255
#define TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION_C     4
#define TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION_C     7
#define TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION_C  0
#define TRGMUX_IP_HWACC_SW_MAJOR_VERSION_C             3
#define TRGMUX_IP_HWACC_SW_MINOR_VERSION_C             0
#define TRGMUX_IP_HWACC_SW_PATCH_VERSION_C             0

/**
* @page misra_violations MISRA-C:2012 violations
*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if Trgmux_Ip_HwAcc.c file and Trgmux_Ip.h file are of the same vendor */
#if (TRGMUX_IP_HWACC_VENDOR_ID_C != TRGMUX_IP_VENDOR_ID)
    #error "Trgmux_Ip_HwAcc.c and Trgmux_Ip.h have different vendor ids"
#endif

/* Check if Trgmux_Ip_HwAcc.c file and Trgmux_Ip.h file are of the same Autosar version */
#if ((TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION_C != TRGMUX_IP_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION_C != TRGMUX_IP_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION_C != TRGMUX_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_HwAcc.c and Trgmux_Ip.h are different"
#endif

/* Check if Trgmux_Ip_HwAcc.c file and Trgmux_Ip.h file are of the same Software version */
#if ((TRGMUX_IP_HWACC_SW_MAJOR_VERSION_C != TRGMUX_IP_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_MINOR_VERSION_C != TRGMUX_IP_SW_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_PATCH_VERSION_C != TRGMUX_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_HwAcc.c and Trgmux_Ip.h are different"
#endif

/* Check if Trgmux_Ip_HwAcc.c file and Trgmux_Ip_HwAcc.c file are of the same vendor */
#if (TRGMUX_IP_HWACC_VENDOR_ID_C != TRGMUX_IP_HWACC_VENDOR_ID)
    #error "Trgmux_Ip_HwAcc.c and Trgmux_Ip_HwAcc.c have different vendor ids"
#endif

/* Check if Trgmux_Ip_HwAcc.h file and Trgmux_Ip_HwAcc.c file are of the same Autosar version */
#if ((TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION_C != TRGMUX_IP_HWACC_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION_C != TRGMUX_IP_HWACC_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION_C != TRGMUX_IP_HWACC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_HwAcc.h and Trgmux_Ip_HwAcc.c are different"
#endif

/* Check if Trgmux_Ip_HwAcc.h file and Trgmux_Ip_HwAcc.c file are of the same Software version */
#if ((TRGMUX_IP_HWACC_SW_MAJOR_VERSION_C != TRGMUX_IP_HWACC_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_MINOR_VERSION_C != TRGMUX_IP_HWACC_SW_MINOR_VERSION) || \
     (TRGMUX_IP_HWACC_SW_PATCH_VERSION_C != TRGMUX_IP_HWACC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_HwAcc.h and Trgmux_Ip_HwAcc.c are different"
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/* Number of SEL bitfields in one TRGMUX register */
#define TRGMUX_IP_REG_SELECTION_NUM         ((uint8)(4U))
/* Get the index of the TRGMUX register */
#define TRGMUX_IP_REG_IDX(x)                ((uint8)((uint8)(x) / TRGMUX_IP_REG_SELECTION_NUM))
/* Get the index of the SEL bitfield inside TRGMUX register */
#define TRGMUX_IP_REG_SELECTION_IDX(x)      ((uint8)((uint8)(x) % TRGMUX_IP_REG_SELECTION_NUM))

/*==================================================================================================
 *                                      INLINE FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

Trgmux_Ip_StatusType hwAcc_Init(TRGMUX_Type * const pTrgmux, uint8 TrgmuxCount)
{
    uint32 RegIdx;
    uint32 RegValue;
    Trgmux_Ip_StatusType Status = TRGMUX_IP_STATUS_SUCCESS;

    for(RegIdx = 0U; RegIdx < TrgmuxCount; RegIdx++)
    {
        if(TRGMUX_IP_STATUS_LOCKED != Status)
        {
            RegValue = pTrgmux->TRGMUXn[RegIdx] & TRGMUX_TRGMUXn_LK_MASK;
            if(TRGMUX_TRGMUXn_LK_MASK == RegValue)
            {
                Status = TRGMUX_IP_STATUS_LOCKED;
            }
            else
            {
                pTrgmux->TRGMUXn[RegIdx] &= ((~(TRGMUX_TRGMUXn_SEL0_MASK)) | (~(TRGMUX_TRGMUXn_SEL1_MASK)) | (~(TRGMUX_TRGMUXn_SEL2_MASK)) | (~(TRGMUX_TRGMUXn_SEL3_MASK)));
            }
        }
        else
        {
            /* Do nothing */
        }
    }

    return Status;
}

void hwAcc_SetInputForOutput(TRGMUX_Type * const pTrgmux, uint8 Instance, const uint32 Input, const uint32 Output)
{
    uint32 RegValue;

    /* Set input for output */
    RegValue = pTrgmux->TRGMUXn[TRGMUX_IP_REG_IDX(Output)];
    RegValue &= ~((uint32)TRGMUX_TRGMUXn_SEL0_MASK << (TRGMUX_TRGMUXn_SEL1_SHIFT * TRGMUX_IP_REG_SELECTION_IDX(Output)));
    RegValue |=  ((uint32)Input) << ((uint8)(TRGMUX_TRGMUXn_SEL1_SHIFT * TRGMUX_IP_REG_SELECTION_IDX(Output)));
    pTrgmux->TRGMUXn[TRGMUX_IP_REG_IDX(Output)] = RegValue;
    (void)Instance;
}

void hwAcc_SetLockForOutput(TRGMUX_Type * const pTrgmux, const uint32 Output)
{
    /* Set TRGMUX_IP_REG_IDX register value */
    pTrgmux->TRGMUXn[TRGMUX_IP_REG_IDX(Output)] |= (((uint32)1U) << TRGMUX_TRGMUXn_LK_SHIFT);
}

boolean hwAcc_GetLockForOutput(const TRGMUX_Type * const pTrgmux, const uint32 Output)
{
    boolean Status;
    /* Get TRGMUX_IP_REG_IDX register value */
    if(((pTrgmux->TRGMUXn[TRGMUX_IP_REG_IDX(Output)] & TRGMUX_TRGMUXn_LK_MASK) >> TRGMUX_TRGMUXn_LK_SHIFT) == 1U)
    {
        Status = TRUE;
    }
    else
    {
        Status = FALSE;
    }

    return Status;
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* TRGMUX_IP_IS_AVAILABLE */

/** @} */

#ifdef __cplusplus
}
#endif

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
