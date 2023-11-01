/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *     @file
 *      
 *     @addtogroup siul2_icu_ip SIUL2 IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Siul2_Icu_Ip.h"
#include "OsIf.h"

#if (STD_ON == SIUL2_ICU_IP_USED)
    #if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif
    
    #if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
        #define USER_MODE_REG_PROT_ENABLED  (SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
        #include "RegLockMacros.h"
    #endif
#endif /* SIUL2_ICU_IP_USED */
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_ICU_IP_VENDOR_ID_C                   43
#define SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION_C    4
#define SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION_C    7
#define SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION_C 0
#define SIUL2_ICU_IP_SW_MAJOR_VERSION_C            1
#define SIUL2_ICU_IP_SW_MINOR_VERSION_C            0
#define SIUL2_ICU_IP_SW_PATCH_VERSION_C            0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == SIUL2_ICU_IP_USED)
        #if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
            /* Check if header file and RegLockMacros.h file are of the same Autosar version */
            #if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Siul2_Icu_Ip.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* SIUL2_ICU_IP_USED */
    
    /* Check if this header file and OsIf.h file are of the same Autosar version */
    #if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION_C != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Siul2_Icu_Ip.c and OsIf.h are different"
    #endif

    #if (STD_ON == SIUL2_ICU_IP_USED)
        #if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Siul2_Icu_Ip.c and Devassert.h are different"
            #endif
        #endif
    #endif /* SIUL2_ICU_IP_USED */
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (SIUL2_ICU_IP_VENDOR_ID_C != SIUL2_ICU_IP_VENDOR_ID)
    #error "Siul2_Icu_Ip.c and Siul2_Icu_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION_C  != SIUL2_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION_C   != SIUL2_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Siul2_Icu_Ip.c and Siul2_Icu_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((SIUL2_ICU_IP_SW_MAJOR_VERSION_C  != SIUL2_ICU_IP_SW_MAJOR_VERSION) || \
     (SIUL2_ICU_IP_SW_MINOR_VERSION_C  != SIUL2_ICU_IP_SW_MINOR_VERSION) || \
     (SIUL2_ICU_IP_SW_PATCH_VERSION_C  != SIUL2_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Siul2_Icu_Ip.c and Siul2_Icu_Ip.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (STD_ON == SIUL2_ICU_IP_USED)

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/* Table of base addresses for SUIL2 instances. */
SIUL2_Type * const Siul2_Icu_Ip_pBase[] = SIUL2_ICU_IP_BASE_PTRS;

#ifdef SIUL2_ICU_AE_AVAILABLE
/* Table of base addresses for SUIL2 instances. */
SIUL2_AE_Type * const Siul2_Ae_Icu_Ip_pBase[] = IP_SIUL2_AE_BASE_PTRS;
#endif

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                  LOCAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

/* Store channel state for each SIUL2. */
Siul2_Icu_Ip_State Siul2_Icu_Ip_aChannelState[SIUL2_ICU_IP_NUM_OF_CHANNELS_USED];

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
static Siul2_Icu_Ip_InstanceConfigType Siul2_Icu_Ip_aInstanceConfiguration[SIUL2_ICU_IP_NUM_OF_INSTANCES];
#endif

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_8
#include "Icu_MemMap.h"
/* This array stores the positions in the Siul2_Icu_Ip_aChannelState array of the configured Siul2 channels. */
uint8 Siul2_Icu_Ip_IndexInChState[SIUL2_ICU_IP_NUM_OF_INSTANCES][SIUL2_ICU_IP_NUM_OF_CHANNELS] = SIUL2_ICU_IP_INITIAL_INDEX_OF_CHANNELS;
#define ICU_STOP_SEC_VAR_INIT_8
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    void Siul2_Icu_SetUserAccessAllowed(uint32 siul2BaseAddr);
#endif

#if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    #if ((defined (MCAL_SIUL2_AE_REG_PROT_AVAILABLE)) && (defined (SIUL2_ICU_AE_AVAILABLE)))
        #if (STD_ON == MCAL_SIUL2_AE_REG_PROT_AVAILABLE)
            #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr) OsIf_Trusted_Call1param(Siul2_Icu_SetUserAccessAllowed,(BaseAddr))
        #else
            #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr)
        #endif
    #elif (defined (MCAL_SIUL2_REG_PROT_AVAILABLE))
        #if (STD_ON == MCAL_SIUL2_REG_PROT_AVAILABLE)
            #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr) OsIf_Trusted_Call1param(Siul2_Icu_SetUserAccessAllowed,(BaseAddr))
        #else
            #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr)
        #endif
    #else
        #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr)
    #endif

#else
    #define Call_Siul2_Icu_SetUserAccessAllowed(BaseAddr)
#endif

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
static inline void Siul2_Icu_Ip_ConfigIntFilterClock(uint8 instance, uint8 prescaler)
{

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->IFCPR = (uint32)prescaler & SIUL2_AE_IFCPR_IFCP_MASK;
    }
    else
    {
        (Siul2_Icu_Ip_pBase[instance])->IFCPR = (uint32)prescaler & SIUL2_IFCPR_IFCP_MASK;
    }
#else
    (Siul2_Icu_Ip_pBase[instance])->IFCPR = (uint32)prescaler & SIUL2_IFCPR_IFCP_MASK;
#endif
}

#if (STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT)
    #if ((defined (MCAL_SIUL2_AE_REG_PROT_AVAILABLE)) && (defined (SIUL2_ICU_AE_AVAILABLE)))
        #if (STD_ON == MCAL_SIUL2_AE_REG_PROT_AVAILABLE)
/**
 * @brief        Enables SIUL2 registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the SIUL2 IP allowing SIUL2 registers writing in User Mode
 *
 * @param[in]    siul2BaseAddr
 *
 * @return       none
 * @pre          Should be executed in supervisor mode
 */
void Siul2_Icu_SetUserAccessAllowed(uint32 siul2BaseAddr)
{

    SET_USER_ACCESS_ALLOWED((uint32)siul2BaseAddr, SIUL2_AE_PROT_MEM_U32);
}
        #endif /* (STD_ON == MCAL_SIUL2_AE_REG_PROT_AVAILABLE) */
    #elif (defined (MCAL_SIUL2_REG_PROT_AVAILABLE))
        #if (STD_ON == MCAL_SIUL2_REG_PROT_AVAILABLE)
/**
 * @brief        Enables SIUL2 registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the SIUL2 IP allowing SIUL2 registers writing in User Mode
 *
 * @param[in]    siul2BaseAddr
 *
 * @return       none
 * @pre          Should be executed in supervisor mode
 */
void Siul2_Icu_SetUserAccessAllowed(uint32 siul2BaseAddr)
{

    SET_USER_ACCESS_ALLOWED((uint32)siul2BaseAddr, SIUL2_PROT_MEM_U32);
}        
        #endif /* (STD_ON == MCAL_SIUL2_REG_PROT_AVAILABLE) */
    #else
        /* Do Nothing */
    #endif
#endif /* STD_ON == SIUL2_ICU_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#if (SIUL2_ICU_IP_DEINIT_API == STD_ON)
/** @implements Siul2_Icu_Ip_DeInit_Activity **/
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_DeInit(uint8 instance)
{
    SIUL2_Type*             base;
#ifdef SIUL2_ICU_AE_AVAILABLE
    SIUL2_AE_Type*          baseAe;
#endif
    uint8                   hwChannel;
    Siul2_Icu_Ip_StatusType status;

#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        baseAe = Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE];
    }
    else
    {
#endif
        base = Siul2_Icu_Ip_pBase[instance];
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
    /* Clear all channels used */
    for(hwChannel = 0; hwChannel < (uint8)SIUL2_ICU_IP_NUM_OF_CHANNELS; hwChannel++)
    {
        status = SIUL2_ICU_IP_ERROR;
        if (Siul2_Icu_Ip_IndexInChState[instance][hwChannel] < SIUL2_ICU_IP_NUM_OF_CHANNELS_USED)
        {
            if(TRUE == Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].chInit)
            {
                /* Disable IRQ Interrupt */
                Siul2_Icu_Ip_DisableInterrupt (instance, hwChannel);
#ifdef SIUL2_ICU_AE_AVAILABLE
                if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
                {
                    /* Clear edge event enable registers */
                    baseAe->IREER0 &= ~((uint32)1U << hwChannel);
                    baseAe->IFEER0 &= ~((uint32)1U << hwChannel);
                    /* Clear Interrupt Filter Enable Register */
                    baseAe->IFER0 &= ~((uint32)1U << hwChannel);
                    /* Clear Interrupt Filter Clock Prescaler Register */
                    baseAe->IFMCR[hwChannel] = 0x0U;
                }
                else
                {
#endif
                    /* Clear edge event enable registers */
                    base->IREER0 &= ~((uint32)1U << hwChannel);
                    base->IFEER0 &= ~((uint32)1U << hwChannel);
                    /* Clear Interrupt Filter Enable Register */
                    base->IFER0 &= ~((uint32)1U << hwChannel);
                    /* Clear Interrupt Filter Clock Prescaler Register */
                    base->IFMCR[hwChannel] = 0x0U;
#ifdef SIUL2_ICU_AE_AVAILABLE
                }
#endif
                Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].chInit = FALSE;
                Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].callback = NULL_PTR;
                Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].callbackParam = 0U;
                Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].Siul2ChannelNotification = NULL_PTR;
                status = SIUL2_ICU_IP_SUCCESS;
            }
        }
        if(SIUL2_ICU_IP_SUCCESS == status)
        {
            /* Clear Interrupt Filter Clock Prescaler Register */
            Siul2_Icu_Ip_ConfigIntFilterClock(instance, (uint8)0x0U);
        }
    }

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
    Siul2_Icu_Ip_aInstanceConfiguration[instance].intFilterClk = 0x0U;
    Siul2_Icu_Ip_aInstanceConfiguration[instance].altIntFilterClk = 0x0U;
#endif

    return status;
}
#endif /* SIUL2_ICU_IP_DEINIT_API == STD_ON */

/** @implements Siul2_Icu_Ip_Init_Activity **/
Siul2_Icu_Ip_StatusType Siul2_Icu_Ip_Init(uint8 instance, const Siul2_Icu_Ip_ConfigType* userConfig)
{
    SIUL2_Type* base;
#ifdef SIUL2_ICU_AE_AVAILABLE
    SIUL2_AE_Type* baseAe;
#endif
    uint32      pinIntValue;
    uint8       hwChannel;
    uint8       index;

#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(userConfig->numChannels <= (uint8)SIUL2_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    /* Call user access mode if it is enabled. */
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        baseAe = Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE];
        Call_Siul2_Icu_SetUserAccessAllowed((uint32)baseAe);
    }
    else
    {
        base = Siul2_Icu_Ip_pBase[instance];
    }
#else
        base = Siul2_Icu_Ip_pBase[instance];
        Call_Siul2_Icu_SetUserAccessAllowed((uint32)Siul2_Icu_Ip_pBase[instance]);
#endif

    /* Global IP configuration */
    Siul2_Icu_Ip_ConfigIntFilterClock(instance, userConfig->pInstanceConfig->intFilterClk);

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
    Siul2_Icu_Ip_aInstanceConfiguration[instance].intFilterClk = userConfig->pInstanceConfig->intFilterClk;
    Siul2_Icu_Ip_aInstanceConfiguration[instance].altIntFilterClk = userConfig->pInstanceConfig->altIntFilterClk;
#endif

    for(index=0; index < userConfig->numChannels; index++)
    {
        hwChannel = (*userConfig->pChannelsConfig)[index].hwChannel;
        /* Get the appropriate value follow index of pin interrupt */
        pinIntValue = (1UL << hwChannel);
        /* Save in state structure the callback information */
        Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].callback = (*userConfig->pChannelsConfig)[index].callback;
        Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].callbackParam = (*userConfig->pChannelsConfig)[index].callbackParam;
        Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].Siul2ChannelNotification = (*userConfig->pChannelsConfig)[index].Siul2ChannelNotification;
        /* External interrupt initialization */
        if ((*userConfig->pChannelsConfig)[index].intEdgeSel != SIUL2_ICU_DISABLE)
        {
#ifdef SIUL2_ICU_AE_AVAILABLE
            if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
            {
                /* Set maximum interrupt filter counter value */
                baseAe->IFMCR[hwChannel] = (uint32)((uint32)(*userConfig->pChannelsConfig)[index].maxFilterCnt & (uint32)SIUL2_AE_IFMCR_MAXCNT_MASK);
                /* Setting the appropriate IFEn bits in IFER0 */
                if ( TRUE == (*userConfig->pChannelsConfig)[index].digFilterEn)
                {
                    baseAe->IFER0 |= pinIntValue;
                }
                else
                {
                    baseAe->IFER0 &= ~pinIntValue;
                }
                /* Setting the appropriate IREEn bits in IREER0 */
                if (((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_RISING_EDGE) ||
                    ((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_BOTH_EDGES))
                {
                    baseAe->IREER0 |= pinIntValue;
                }
                else
                {
                    baseAe->IREER0 &= ~pinIntValue;
                }
                /* Setting the appropriate IREEn bits in IFEER0 */
                if (((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_FALLING_EDGE) ||
                    ((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_BOTH_EDGES))
                {
                    baseAe->IFEER0 |= pinIntValue;
                }
                else
                {
                    baseAe->IFEER0 &= ~pinIntValue;
                }

                /* Select the request desired between DMA or Interrupt */
                if (SIUL2_ICU_DMA == (*userConfig->pChannelsConfig)[index].intSel)
                {
                    baseAe->DIRSR0 |= pinIntValue;
                }
                else
                {
                    baseAe->DIRSR0 &= ~pinIntValue;
                }
                /* Write to EIFn bits in DISR0  to clear any flags */
                baseAe->DISR0  |= pinIntValue;
            }
            else
            {
#endif
                /* Set maximum interrupt filter counter value */
                base->IFMCR[hwChannel] = (uint32)((uint32)(*userConfig->pChannelsConfig)[index].maxFilterCnt & (uint32)SIUL2_IFMCR_MAXCNT_MASK);
                /* Setting the appropriate IFEn bits in IFER0 */
                if ( TRUE == (*userConfig->pChannelsConfig)[index].digFilterEn)
                {
                    base->IFER0 |= pinIntValue;
                }
                else
                {
                    base->IFER0 &= ~pinIntValue;
                }

                /* Setting the appropriate IREEn bits in IREER0 */
                if (((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_RISING_EDGE) ||
                    ((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_BOTH_EDGES))
                {
                    base->IREER0 |= pinIntValue;
                }
                else
                {
                    base->IREER0 &= ~pinIntValue;
                }
                /* Setting the appropriate IREEn bits in IFEER0 */
                if (((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_FALLING_EDGE) ||
                    ((*userConfig->pChannelsConfig)[index].intEdgeSel == SIUL2_ICU_BOTH_EDGES))
                {
                    base->IFEER0 |= pinIntValue;
                }
                else
                {
                    base->IFEER0 &= ~pinIntValue;
                }

                /* Select the request desired between DMA or Interrupt */
                if (SIUL2_ICU_DMA == (*userConfig->pChannelsConfig)[index].intSel)
                {
                    base->DIRSR0 |= pinIntValue;
                }
                else
                {
                    base->DIRSR0 &= ~pinIntValue;
                }
                /* Write to EIFn bits in DISR0  to clear any flags */
                base->DISR0  |= pinIntValue;
#ifdef SIUL2_ICU_AE_AVAILABLE
            }
#endif
        }
#ifdef SIUL2_ICU_AE_AVAILABLE
        /* Call user access mode if it is enabled. */
        if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
        {
            /* Mask interrupts by clearing the EIREn bits in DIRER0 */
            baseAe->DIRER0 &= ~pinIntValue;
        }
        else
        {
#endif
            /* Mask interrupts by clearing the EIREn bits in DIRER0 */
            base->DIRER0 &= ~pinIntValue;
#ifdef SIUL2_ICU_AE_AVAILABLE
        }
#endif
        Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].chInit = TRUE;
    }

    return SIUL2_ICU_IP_SUCCESS;
}

/** @implements Siul2_Icu_Ip_SetActivationCondition_Activity */
void Siul2_Icu_Ip_SetActivationCondition(uint8 instance, uint8 hwChannel, Siul2_Icu_Ip_EdgeType edge)
{
    SIUL2_Type* base;
#ifdef SIUL2_ICU_AE_AVAILABLE
    SIUL2_AE_Type* baseAe;
#endif
    uint32      pinIntValue;

#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(hwChannel < (uint8)SIUL2_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        baseAe = Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE];
    }
    else
    {
#endif
        base = Siul2_Icu_Ip_pBase[instance];
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
    /* Get the appropriate value follow index of pin interrupt */
    pinIntValue = (1UL << hwChannel);

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        /* Setting the appropriate IREEn bits in IREER0 */
        if ((edge == SIUL2_ICU_RISING_EDGE) || (edge == SIUL2_ICU_BOTH_EDGES))
        {
            baseAe->IREER0 |= pinIntValue;
        }
        else
        {
            baseAe->IREER0 &= ~pinIntValue;
        }
        /* Setting the appropriate IREEn bits in IFEER0 */
        if ((edge == SIUL2_ICU_FALLING_EDGE) || (edge == SIUL2_ICU_BOTH_EDGES))
        {
            baseAe->IFEER0 |= pinIntValue;
        }
        else
        {
            baseAe->IFEER0 &= ~pinIntValue;
        }
    }
    else
    {
#endif
        /* Setting the appropriate IREEn bits in IREER0 */
        if ((edge == SIUL2_ICU_RISING_EDGE) || (edge == SIUL2_ICU_BOTH_EDGES))
        {
            base->IREER0 |= pinIntValue;
        }
        else
        {
            base->IREER0 &= ~pinIntValue;
        }
        /* Setting the appropriate IREEn bits in IFEER0 */
        if ((edge == SIUL2_ICU_FALLING_EDGE) || (edge == SIUL2_ICU_BOTH_EDGES))
        {
            base->IFEER0 |= pinIntValue;
        }
        else
        {
            base->IFEER0 &= ~pinIntValue;
        }
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
}

#if (SIUL2_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/** @implements Siul2_Icu_Ip_GetInputState_Activity */
boolean Siul2_Icu_Ip_GetInputState(uint8 instance, uint8 hwChannel)
{
    uint32  flag;
    uint32  irqEnable;
    boolean bStatus = FALSE;

#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
    DevAssert(hwChannel < SIUL2_ICU_IP_NUM_OF_CHANNELS);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        flag = (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DISR0 & ((uint32)1U << hwChannel);
        irqEnable = (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DIRER0 & ((uint32)1U << hwChannel);

        /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
        if ( (0x0U != flag) && (0x0U == irqEnable) )
        {
            /* Clear IRQ Flag */
            (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DISR0 = flag;
            bStatus = TRUE;
        }
    }
    else
    {
#endif
        flag = (Siul2_Icu_Ip_pBase[instance])->DISR0 & ((uint32)1U << hwChannel);
        irqEnable = (Siul2_Icu_Ip_pBase[instance])->DIRER0 & ((uint32)1U << hwChannel);

        /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
        if ( (0x0U != flag) && (0x0U == irqEnable) )
        {
            /* Clear IRQ Flag */
            (Siul2_Icu_Ip_pBase[instance])->DISR0 = flag;
            bStatus = TRUE;
        }
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
    return bStatus;
}
#endif /* SIUL2_ICU_IP_GET_INPUT_STATE_API */

#if (SIUL2_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/** @implements Siul2_Icu_Ip_SetClockMode_Activity */
void Siul2_Icu_Ip_SetClockMode(uint8 instance, Siul2_Icu_Ip_ClockModeType mode)
{
#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
#endif

    if(SIUL2_ICU_NORMAL_CLK == mode)
    {
        Siul2_Icu_Ip_ConfigIntFilterClock(instance, Siul2_Icu_Ip_aInstanceConfiguration[instance].intFilterClk);
    }
    else
    {
        Siul2_Icu_Ip_ConfigIntFilterClock(instance, Siul2_Icu_Ip_aInstanceConfiguration[instance].altIntFilterClk);
    }
}
#endif

/** @implements Siul2_Icu_Ip_EnableInterrupt_Activity **/
void Siul2_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel)
{
#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
    DevAssert(hwChannel < SIUL2_ICU_IP_NUM_OF_CHANNELS);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        /* Clear interrupt flag */
        (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DISR0  = ((uint32)1U << hwChannel);
        /* Enable interrupt */
        (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DIRER0 |= ((uint32)1U << hwChannel);
    }
    else
    {
#endif
        /* Clear interrupt flag */
        (Siul2_Icu_Ip_pBase[instance])->DISR0  = ((uint32)1U << hwChannel);
        /* Enable interrupt */
        (Siul2_Icu_Ip_pBase[instance])->DIRER0 |= ((uint32)1U << hwChannel);
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
}

/** @implements Siul2_Icu_Ip_DisableInterrupt_Activity **/
void Siul2_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel)
{
#if(SIUL2_ICU_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < SIUL2_ICU_IP_NUM_OF_INSTANCES);
    DevAssert(hwChannel < SIUL2_ICU_IP_NUM_OF_CHANNELS);
#endif

#ifdef SIUL2_ICU_AE_AVAILABLE
    if (instance >= SIUL2_ICU_AE_MIN_INSTANCE)
    {
        /* Disable interrupt */
        (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DIRER0 &= ~((uint32)1U << hwChannel);
        /* Clear interrupt flag */
        (Siul2_Ae_Icu_Ip_pBase[instance - SIUL2_ICU_AE_MIN_INSTANCE])->DISR0 = ((uint32)1U << hwChannel);
    }
    else
    {
#endif
        /* Disable interrupt */
        (Siul2_Icu_Ip_pBase[instance])->DIRER0 &= ~((uint32)1U << hwChannel);
        /* Clear interrupt flag */
        (Siul2_Icu_Ip_pBase[instance])->DISR0 = ((uint32)1U << hwChannel);
#ifdef SIUL2_ICU_AE_AVAILABLE
    }
#endif
}

#if (SIUL2_ICU_IP_SET_MODE_API == STD_ON)
void Siul2_Icu_Ip_SetSleepMode(uint8 instance, uint8 hwChannel)
{
    /*disable IRQ for the given instance*/
    Siul2_Icu_Ip_DisableInterrupt(instance, hwChannel);
}

void Siul2_Icu_Ip_SetNormalMode(uint8 instance, uint8 HwChannel)
{
    /*Enable IRQ*/
    Siul2_Icu_Ip_EnableInterrupt(instance, HwChannel);
}
#endif /* SIUL2_ICU_IP_SET_MODE_API  */

/* @implements Siul2_Icu_Ip_EnableNotification_Activity */
void Siul2_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel)
{
    Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].notificationEnable =  TRUE;
}

/* @implements Siul2_Icu_Ip_DisableNotification_Activity */
void Siul2_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel)
{
    Siul2_Icu_Ip_aChannelState[Siul2_Icu_Ip_IndexInChState[instance][hwChannel]].notificationEnable =  FALSE;
}

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* SIUL2_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
