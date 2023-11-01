/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file
*
*   @addtogroup Swt
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Swt_Ip.h"
#include "Devassert.h"
#include "SchM_Wdg.h"

#include "OsIf.h"
#include "Swt_Ip_Irq.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_VENDOR_ID_C                      43
#define SWT_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define SWT_IP_AR_RELEASE_MINOR_VERSION_C       7
#define SWT_IP_AR_RELEASE_REVISION_VERSION_C    0
#define SWT_IP_SW_MAJOR_VERSION_C               1
#define SWT_IP_SW_MINOR_VERSION_C               0
#define SWT_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip header file are of the same vendor */
#if (SWT_IP_VENDOR_ID_C != SWT_IP_VENDOR_ID)
#error "Swt_Ip.c and Swt_Ip.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip header file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C     != SWT_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_C     != SWT_IP_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_C  != SWT_IP_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Swt_Ip.c and Swt_Ip.h are different"
#endif

/* Check if current file and Swt_Ip header file are of the same software version */
#if ((SWT_IP_SW_MAJOR_VERSION_C != SWT_IP_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION_C != SWT_IP_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION_C != SWT_IP_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Swt_Ip.c and Swt_Ip.h are different"
#endif

/* Check if current file and Swt_Ip_Irq header file are of the same vendor */
#if (SWT_IP_VENDOR_ID_C != SWT_IP_IRQ_VENDOR_ID)
#error "Swt_Ip.c and Swt_Ip_Irq.h have different vendor ids"
#endif

/* Check if current file and Swt_Ip_Irq header file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C     != SWT_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_C     != SWT_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION_C  != SWT_IP_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Swt_Ip.c and Swt_Ip_Irq.h are different"
#endif

/* Check if current file and Swt_Ip_Irq header file are of the same software version */
#if ((SWT_IP_SW_MAJOR_VERSION_C != SWT_IP_IRQ_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION_C != SWT_IP_IRQ_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION_C != SWT_IP_IRQ_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Swt_Ip.c and Swt_Ip_Irq.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (SWT_IP_AR_RELEASE_MINOR_VERSION_C    != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Swt_Ip.c and Devassert.h are different"
    #endif

    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SWT_IP_AR_RELEASE_MINOR_VERSION_C    != STD_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Swt_Ip.c and StandardTypes.h are different"
    #endif

    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C    != SCHM_WDG_AR_RELEASE_MAJOR_VERSION) || \
         (SWT_IP_AR_RELEASE_MINOR_VERSION_C    != SCHM_WDG_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Swt_Ip.c and SchM_Wdg.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and Osif header file are of the same Autosar version */
#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION_C    != OSIF_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Swt_Ip.c and Osif.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define SWT_IP_MAP(x)  (((uint32)(((uint32)(x)) << SWT_IP_MAP_SHIFT)) & SWT_IP_MAP_MASK_U32)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"
#if SWT_IP_DISCOUNTINUOUS_INSTANCE_IDS == STD_OFF
static Swt_Ip_Type * const Swt_Ip_sBase[SWT_INSTANCE_COUNT] = IP_SWT_BASE_PTRS;
#else
static Swt_Ip_Type * const Swt_Ip_sBase[SWT_INSTANCE_COUNT] = {IP_SWT_0, IP_SWT_0, IP_SWT_2, IP_SWT_3};
#endif

#define WDG_STOP_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

static Swt_CallbackPtrType Swt_Ip_apCallbackPtr[SWT_INSTANCE_NUM];

#define WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_CLEARED_BOOLEAN

#include "Wdg_MemMap.h"

static boolean Swt_Ip_abStatus[SWT_INSTANCE_NUM];

#define WDG_STOP_SEC_VAR_CLEARED_BOOLEAN

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

static inline boolean Swt_Ip_IsEnable(const Swt_Ip_Type * const Base)
{
    /* Checks whether the SWT is enabled */
    return ((Base->CR & SWT_CR_WEN_MASK) != 0U);
}

static inline void Swt_Ip_Enable(Swt_Ip_Type * const Base)
{
    /* Enables the SWT */
    Base->CR |= SWT_CR_WEN_MASK;
}

static inline void Swt_Ip_Disable(Swt_Ip_Type * const Base)
{
    /* Enables the SWT */
    Base->CR &= ~SWT_CR_WEN_MASK;
}

static  Swt_Ip_ServiceModeType Swt_Ip_GetServiceMode(const Swt_Ip_Type * const Base)
{
    Swt_Ip_ServiceModeType Mode;

    /* Gets current service mode */
    switch ((Base->CR & SWT_CR_SMD_MASK) >> SWT_CR_SMD_SHIFT)
    {
        /* Keyed Service Sequence */
        case 1U:
            Mode = SWT_IP_KS_SEQ_MODE;
            break;
        /* Fixed Service Sequence */
        case 0U:
            Mode = SWT_IP_FS_SEQ_MODE;
            break;
        /* Invalid mode */
        default:
            Mode = SWT_IP_INVALID_MODE;
            break;
    }

    return Mode;
}

static Swt_Ip_LockType Swt_Ip_GetLock(const Swt_Ip_Type * const Base)
{
    Swt_Ip_LockType LockMode = SWT_IP_UNLOCK;

    /* Get lock mode */
    switch ((Base->CR & (SWT_CR_SLK_MASK | SWT_CR_HLK_MASK)) >> SWT_CR_SLK_SHIFT)
    {
        case 0U:
            LockMode = SWT_IP_UNLOCK;
            break;
        case 1U:
            LockMode = SWT_IP_SOFTLOCK;
            break;
        case 2U:
            LockMode = SWT_IP_HARDLOCK;
            break;
        default:
            LockMode = SWT_IP_HARDLOCK;
            break;
    }

    return LockMode;
}

static void Swt_Ip_Lock(Swt_Ip_Type * const Base,
                 Swt_Ip_LockType LockConfig)
{
    /* Configures lock bits */
    switch (LockConfig)
    {
        /* Hard lock */
        case SWT_IP_HARDLOCK:
            Base->CR |= SWT_CR_HLK(1U);
            break;
        /* Soft lock */
        case SWT_IP_SOFTLOCK:
            Base->CR |= SWT_CR_SLK(1U);
            break;
        /* Unlock */
        default:
            /* Do nothing */
            break;
    }
}

static Swt_Ip_StatusType Swt_Ip_Unlock(Swt_Ip_Type * const Base)
{
    Swt_Ip_StatusType Ret = SWT_IP_STATUS_SUCCESS;

    uint32 TimeoutTicks = OsIf_MicrosToTicks(SWT_IP_OSIF_TIMEOUT_VAL, SWT_IP_TIMEOUT_METHOD);
    uint32 CurrentTicks = 0u; /* initialize current counter */
    uint32 ElapsedTicks = 0u; /* elapsed will give timeout */

    /* Hard lock */
    if ((Base->CR & SWT_CR_HLK_MASK) != 0U)
    {
        Ret = SWT_IP_STATUS_ERROR;
    }
    else
    {
        /* Soft lock */
        if ((Base->CR & SWT_CR_SLK_MASK) != 0U)
        {
            /* Unlocks sequence */
            Base->SR = SWT_SR_WSC(SWT_IP_UNLOCK_VALUE1_U16);
            Base->SR = SWT_SR_WSC(SWT_IP_UNLOCK_VALUE2_U16);

            CurrentTicks = OsIf_GetCounter(SWT_IP_TIMEOUT_METHOD);

            /* Waits unlock complete */
            while (((Base->CR & SWT_CR_SLK_MASK) != 0U) && (ElapsedTicks < TimeoutTicks))
            {
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SWT_IP_TIMEOUT_METHOD);
            }

            if (ElapsedTicks >= TimeoutTicks)
            {
                /* Soft lock is enabled again to avoid unlock sequence successfully after osif timeout expired */
                Swt_Ip_Lock(Base, SWT_IP_SOFTLOCK);
                Ret = SWT_IP_STATUS_ERROR;
            }
        }
        /* Unlock */
        else
        {
            /* Do nothing */
        }
    }

    return Ret;
}


static void Swt_Ip_RegisterConfig(Swt_Ip_Type * const Base,
                                  const Swt_Ip_ConfigType * const ConfigPtr)
{
    /* Temporary storage for control register value */
    uint32 TempCr = 0x00UL;
    Swt_Ip_ServiceModeType ServiceMode = ConfigPtr->eServiceMode;

    /* Sets control configuration */
    TempCr = (SWT_IP_MAP(ConfigPtr->u8MapEnBitmask)
        | SWT_CR_SMD(ServiceMode)
        | SWT_CR_RIA(ConfigPtr->bEnResetOnInvalidAccess ? 1UL : 0UL)
        | SWT_CR_WND(ConfigPtr->bEnWindow ? 1UL : 0UL)
#if (defined(SWT_IP_HAS_STOP_MODE) && (SWT_IP_HAS_STOP_MODE == 1U))
        | SWT_CR_STP(ConfigPtr->bEnRunInStopMode? 0UL : 1UL)
#endif
        | SWT_CR_FRZ(ConfigPtr->bEnRunInDebugMode ? 0UL : 1UL)
        | SWT_CR_ITR(ConfigPtr->bEnInterrupt ? 1UL : 0UL));
    /* Write configuration to the SWT CR register*/
    Base->CR = TempCr;

    /* Clears interrupt flags */

    Base->IR = SWT_IR_TIF_MASK;

    /* Sets timeout value */
    Base->TO = ConfigPtr->u32TimeoutValue;

    /* Sets window value */
    if (ConfigPtr->bEnWindow)
    {
        Base->WN = ConfigPtr->u32WindowValue;
    }
    /* Sets initial service key value */
    if (SWT_IP_KS_SEQ_MODE == ServiceMode)
    {
        Base->SK = SWT_SK_SK(ConfigPtr->u16InitialKey);
    }
}

static Swt_Ip_StatusType Swt_Ip_CheckTimeout(uint32 u32TimeoutValue, uint32 u32WindowValue)
{
    /* Check timeout period is valid */
    Swt_Ip_StatusType Ret = SWT_IP_STATUS_SUCCESS;

    if (u32TimeoutValue < SWT_MIN_VALUE_TIMEOUT_U32)
    {
        Ret = SWT_IP_STATUS_ERROR;
    }

    if ((u32WindowValue != 0U) && (u32TimeoutValue <= u32WindowValue))
    {
        Ret = SWT_IP_STATUS_ERROR;
    }

    return Ret;
}

static inline void Swt_Ip_ServiceCmd(Swt_Ip_Type * const Base,
                                     uint16 ServiceKey)
{
    /* Services SWT instance */
    Base->SR = (Base->SR & ~SWT_SR_WSC_MASK) | SWT_SR_WSC(ServiceKey);
}

static inline uint16 Swt_Ip_ServiceKeyGen(const Swt_Ip_Type * const Base)
{
    /* Generates the next key used to service the SWT */
    return ((uint16)((((Base->SK & SWT_SK_SK_MASK) >> SWT_SK_SK_SHIFT) * 17U) + 3U));
}

#if (SWT_IP_DEINIT == STD_ON)
#if (SWT_IP_CLEAR_RESET_REQUEST == STD_ON)
static inline boolean Swt_Ip_RequestedReset(const Swt_Ip_Type * const Base)
{
    /* Get reset request flag */
    return (((Base->RRR & SWT_RRR_RRF_MASK)>> SWT_RRR_RRF_SHIFT) == 1U);
}
#endif /* (SWT_IP_CLEAR_RESET_REQUEST == STD_ON) */
#endif /* (SWT_IP_DEINIT == STD_ON) */

#if (SWT_IP_HAS_CLEAR_RESET == 1)
#if (SWT_IP_DEINIT == STD_ON)
static inline void Swt_Ip_ClearRequest(Swt_Ip_Type * const Base)
{
    /* Clear reset request flag */
    Base->RRR = SWT_RRR_RRF(1U);
}
#endif /* (SWT_IP_DEINIT == STD_ON) */
#endif /* (SWT_IP_HAS_CLEAR_RESET == 1) */

static inline boolean Swt_Ip_GetIntFlag(const Swt_Ip_Type * const Base)
{
    /* Get interrupt flag */
    return ((Base->IR & SWT_IR_TIF_MASK) != 0U);
}

static inline boolean Swt_Ip_IsIntEnabled(const Swt_Ip_Type * const Base)
{
    /* Interrupt then reset request */
    return ((Base->CR & SWT_CR_ITR_MASK ) != 0U);
}

static inline void Swt_Ip_ClearIntFlag(Swt_Ip_Type * const Base)
{
    /* Clear interrupt flag */
    Base->IR &= SWT_IR_TIF_MASK;
}

/*==================================================================================================
*                                 GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @Description    This function initializes SWT instance.
*
* @implements     Swt_Ip_Init_Activity
*/
Swt_Ip_StatusType Swt_Ip_Init(const uint32 Instance,
                              const Swt_Ip_ConfigType * const ConfigPtr)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    Swt_Ip_StatusType Ret = SWT_IP_STATUS_SUCCESS;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
    DevAssert(ConfigPtr != NULL_PTR);
#endif

    if (Swt_Ip_Unlock(Base) == SWT_IP_STATUS_ERROR)
    {
        Ret = SWT_IP_STATUS_ERROR;
    }
    else
    {
        boolean bSwtEnabled = Swt_Ip_IsEnable(Base);

        if (bSwtEnabled)
        {
            Swt_Ip_Disable(Base);
        }

        /* Verify if the timeout and window values are within accepted range */
        Ret = Swt_Ip_CheckTimeout(ConfigPtr->u32TimeoutValue, ConfigPtr->u32WindowValue);

        if (SWT_IP_STATUS_SUCCESS == Ret)
        {
            /* Configures the SWT instance */
            Swt_Ip_RegisterConfig(Base, ConfigPtr);


            if (ConfigPtr->bEnInterrupt)
            {
                Swt_Ip_apCallbackPtr[Instance] = ConfigPtr->pfSwtCallback;
            }

            /* Enable the SWT timer */
            Swt_Ip_Enable(Base);

            /* Lock the SWT */
            Swt_Ip_Lock(Base, ConfigPtr->lockConfig);

            /* Set driver status is initialized */
            Swt_Ip_abStatus[Instance] = TRUE;
        }
    }

    return Ret;
}

#if (SWT_IP_DEINIT == STD_ON)
/**
* @Description    This function de-initializes SWT instance.
*
* @implements     Swt_Ip_Deinit_Activity
*/
    Swt_Ip_StatusType Swt_Ip_Deinit(const uint32 Instance)
    {
        Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
        Swt_Ip_StatusType Ret;

    #if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(Instance < SWT_INSTANCE_NUM);
    #endif /* (SWT_IP_DEV_ERROR_DETECT == STD_ON) */

        /* Unlocks SWT instance */
        Ret = Swt_Ip_Unlock(Base);

        if (Ret == SWT_IP_STATUS_SUCCESS)
        {
            /* Disable SWT timer */
            Swt_Ip_Disable(Base);

            /* Clears interrupt flag */
            Base->IR = SWT_IR_TIF_MASK;
            /* Resets timeout value */
            #ifdef  SWT_IP_HAS_MULTIPLE_HEADER_FILES
            Base->TO = SWT_IP_TO_RESET_VALUE_U32(Instance);
            #else
            Base->TO = SWT_IP_TO_RESET_VALUE_U32;
            #endif
            /* Resets window value */
            Base->WN = SWT_IP_WN_RESET_VALUE_U32;
            /* Resets service key value */
            Base->SK = SWT_IP_SK_RESET_VALUE_U16;
            /* Resets control register */
            #ifdef  SWT_IP_HAS_MULTIPLE_HEADER_FILES
            Base->CR = (SWT_IP_CR_RESET_VALUE_U32(Instance)) & (~SWT_CR_WEN_MASK); /* make sure the SWT is disabled after reset */
            #else
            Base->CR = SWT_IP_CR_RESET_VALUE_U32 & (~SWT_CR_WEN_MASK); /* make sure the SWT is disabled after reset */
            #endif


            /* Clear RRF bit in RRR register */
            #if (SWT_IP_HAS_CLEAR_RESET == 1)
            Swt_Ip_ClearRequest(Base);
            #endif /* (SWT_IP_HAS_CLEAR_RESET == 1) */

            /* Set driver status is uninit */
            Swt_Ip_abStatus[Instance] = FALSE;
        }

        return Ret;
    }
#endif /* (SWT_IP_DEINIT == STD_ON) */

/**
* @Description    This function services SWT instance.
*
* @implements     Swt_Ip_Service_Activity
*/
void Swt_Ip_Service(const uint32 Instance)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    boolean BUnlockSequence = FALSE;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
#endif /* (SWT_IP_DEV_ERROR_DETECT == STD_ON) */

    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_09();

    Swt_Ip_ServiceModeType ServiceMode = Swt_Ip_GetServiceMode(Base);

    switch (ServiceMode)
    {
        /* Keyed Service Sequence Mode */
        case SWT_IP_KS_SEQ_MODE:
            if (Swt_Ip_ServiceKeyGen(Base) == SWT_IP_UNLOCK_VALUE1_U16)
            {
                BUnlockSequence = TRUE;
            }

            Swt_Ip_ServiceCmd(Base, Swt_Ip_ServiceKeyGen(Base));

            if (Swt_Ip_ServiceKeyGen(Base) == SWT_IP_UNLOCK_VALUE1_U16)
            {
                BUnlockSequence = TRUE;
            }

            Swt_Ip_ServiceCmd(Base, Swt_Ip_ServiceKeyGen(Base));

            if ((SWT_IP_SOFTLOCK == Swt_Ip_GetLock(Base)) && (TRUE == BUnlockSequence))
            {
                /* Unlock key generated. Complete the unlock sequence and lock it again. */
                Swt_Ip_ServiceCmd(Base, SWT_IP_UNLOCK_VALUE2_U16);
                Swt_Ip_Lock(Base, SWT_IP_SOFTLOCK);
            }
            break;
        /* Fixed Service Sequence Mode */
        case SWT_IP_FS_SEQ_MODE:
            Swt_Ip_ServiceCmd(Base, SWT_IP_FIXED_SERVICE_VALUE1_U16);
            Swt_Ip_ServiceCmd(Base, SWT_IP_FIXED_SERVICE_VALUE2_U16);
            break;
        default:
            /* No register write required for servicing the watchdog.
            The watchdog is serviced when executing code at the address loaded into the designated IAC register */
            break;
    }

    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_09();
}

/**
* @Description    This function configure SWT instance.
*
* @implements     Swt_Ip_Config_Activity
*/
Swt_Ip_StatusType Swt_Ip_Config(const uint32 Instance,
                                const Swt_Ip_ConfigType * const ConfigPtr)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    Swt_Ip_StatusType Ret;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
    DevAssert(ConfigPtr != NULL_PTR);
#endif

    Ret = Swt_Ip_CheckTimeout(ConfigPtr->u32TimeoutValue, ConfigPtr->u32WindowValue);

    if (SWT_IP_STATUS_SUCCESS == Ret)
    {
        if (SWT_IP_STATUS_ERROR == Swt_Ip_Unlock(Base))
        {
            Ret = SWT_IP_STATUS_ERROR;
        }
        else
        {
            boolean bSwtEnabled = Swt_Ip_IsEnable(Base);

            if (bSwtEnabled)
            {
                Swt_Ip_Disable(Base);
            }

            /* Configures the SWT instance */
            Swt_Ip_RegisterConfig(Base, ConfigPtr);

            /* If the timer was enebled, enable it after configuration is done */
            if (bSwtEnabled)
            {
                Swt_Ip_Enable(Base);
            }
            /* Lock the SWT */
            Swt_Ip_Lock(Base, ConfigPtr->lockConfig);
        }
    }

    return Ret;
}

/**
* @Description    This function sets the timeout value for the SWT instance.
*
* @implements     Swt_Ip_SetTimeout_Activity
*/
Swt_Ip_StatusType Swt_Ip_SetTimeout(const uint32 Instance,
                                    const uint32 TimeoutValue, const uint32 WindowValue)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    Swt_Ip_LockType LockConfig;
    Swt_Ip_StatusType Ret;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
#endif

    LockConfig = Swt_Ip_GetLock(Base);
    Ret = Swt_Ip_CheckTimeout(TimeoutValue, WindowValue);

    if (SWT_IP_STATUS_SUCCESS == Ret)
    {
        if (SWT_IP_STATUS_ERROR == Swt_Ip_Unlock(Base))
        {
            Ret = SWT_IP_STATUS_ERROR;
        }
        else
        {
            /* Stop the SWT timer */
            Swt_Ip_Disable(Base);

            /* Sets timeout value */
            Base->TO = TimeoutValue;

            /* Sets window value */
            if (WindowValue > 0U)
            {
                Base->WN = WindowValue;
                /* Enable Windowed Mode */
                Base->CR |= SWT_CR_WND_MASK;
            }
            else
            {
                Base->CR &= ~SWT_CR_WND_MASK;
            }

            /* Start the SWT timer */
            Swt_Ip_Enable(Base);

            /* Lock the SWT */
            Swt_Ip_Lock(Base, LockConfig);
        }
    }

    return Ret;
}

/**
* @Description    This function starts the timer for the SWT instance.
*
* @implements     Swt_Ip_StartTimer_Activity
*/
Swt_Ip_StatusType Swt_Ip_StartTimer(const uint32 Instance)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    Swt_Ip_LockType LockConfig;
    Swt_Ip_StatusType Ret;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
#endif

    LockConfig = Swt_Ip_GetLock(Base);
    /* Unlocks the SWT */
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_10();
    Ret = Swt_Ip_Unlock(Base);

    if (SWT_IP_STATUS_SUCCESS == Ret)
    {
        /* Start the SWT timer */
        Swt_Ip_Enable(Base);

        Swt_Ip_Lock(Base, LockConfig);
    }
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_10();

    return Ret;
}

/**
* @Description    This function stops the timer for the SWT instance.
*
* @implements     Swt_Ip_StopTimer_Activity
*/
Swt_Ip_StatusType Swt_Ip_StopTimer(const uint32 Instance)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
    Swt_Ip_LockType LockConfig;
    Swt_Ip_StatusType Ret;

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
#endif

    LockConfig = Swt_Ip_GetLock(Base);
    /* Unlocks the SWT */
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_11();
    Ret = Swt_Ip_Unlock(Base);

    if (SWT_IP_STATUS_SUCCESS == Ret)
    {
        /* Start the SWT timer */
        Swt_Ip_Disable(Base);

        Swt_Ip_Lock(Base, LockConfig);
    }
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_11();

    return Ret;
}

#if (SWT_IP_HAS_CLEAR_RESET == 1)
#if (SWT_IP_DEINIT == STD_ON)
#if (SWT_IP_CLEAR_RESET_REQUEST == STD_ON)
/**
* @Description    This function clears reset request.
*
* @return                             Swt_Ip_StatusType.
* @retval  SWT_IP_STATUS_ERROR        returned if SWT has not requested a reset.
* @retval  SWT_IP_STATUS_SUCCESS      Clear reset request successfully.
* @implements     Swt_Ip_ClearResetRequest_Activity
*/
    Swt_Ip_StatusType Swt_Ip_ClearResetRequest(const uint32 Instance)
    {
        Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];
        Swt_Ip_StatusType Ret = SWT_IP_STATUS_SUCCESS;

        uint32 TimeoutTicks = OsIf_MicrosToTicks(SWT_IP_OSIF_TIMEOUT_VAL, SWT_IP_TIMEOUT_METHOD);
        uint32 CurrentTicks = 0u; /* initialize current counter */
        uint32 ElapsedTicks = 0u; /* elapsed will give timeout */

    #if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(Instance < SWT_INSTANCE_NUM);

        /* Can the SWT instance be reset without system reset */
        DevAssert((SWT_IP_RRR_SUPPORT & (1UL << Instance)) != 0UL);
    #endif

        if (Swt_Ip_RequestedReset(Base))
        {   /* Reset the SWT instance */
            Swt_Ip_ClearRequest(Base);

            CurrentTicks = OsIf_GetCounter(SWT_IP_TIMEOUT_METHOD);

            /* Wait for the SWT instance to finish reseting */
            while ((Swt_Ip_RequestedReset(Base)) && (ElapsedTicks < TimeoutTicks))
            {
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SWT_IP_TIMEOUT_METHOD);
            }

            if ((ElapsedTicks >= TimeoutTicks) && (Swt_Ip_RequestedReset(Base)))
            {
                Ret = SWT_IP_STATUS_TIMEOUT;
            }

        }
        else
        {   /* SWT has not requested a reset */
            Ret = SWT_IP_STATUS_ERROR;
        }

        return Ret;
    }
#endif /* (SWT_IP_CLEAR_RESET_REQUEST == STD_ON) */
#endif /* (SWT_IP_DEINIT == STD_ON) */
#endif /* (SWT_IP_HAS_CLEAR_RESET == 1) */

/**
* @Description    This function handles the swt interrupt request.
*
* @implements     Swt_Ip_IrqHandler_Activity
*/
void Swt_Ip_IrqHandler(uint32 Instance)
{
    Swt_Ip_Type * const Base = Swt_Ip_sBase[Instance];

#if (SWT_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < SWT_INSTANCE_NUM);
#endif
    if (TRUE == Swt_Ip_abStatus[Instance])
    {
        if  (Swt_Ip_GetIntFlag(Base) && Swt_Ip_IsIntEnabled(Base))
        {
            Swt_Ip_ClearIntFlag(Base);

            if (Swt_Ip_apCallbackPtr[Instance] != ((void *)0))
            {
                Swt_Ip_apCallbackPtr[Instance]();
            }
        }
    }
    else
    {
        Swt_Ip_ClearIntFlag(Base);
    }
}


#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
