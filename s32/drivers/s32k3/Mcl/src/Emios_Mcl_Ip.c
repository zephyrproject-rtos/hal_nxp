/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
*   @file    Emios_Mcl_Ip.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Emios Common driver source file.
*   @details
*
*   @addtogroup EMIOS_IP_DRIVER EMIOS IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Mcl_Ip.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_VENDOR_ID_C                       43
#define EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_MCL_IP_SW_MAJOR_VERSION_C                3
#define EMIOS_MCL_IP_SW_MINOR_VERSION_C                0
#define EMIOS_MCL_IP_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_VENDOR_ID_C != EMIOS_MCL_IP_VENDOR_ID)
    #error "Emios_Mcl_Ip.c and Emios_Mcl_Ip.h have different vendor ids"
#endif

/* Check if  source file and Emios_Mcl_Ip.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION_C != EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION_C != EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip.c and Emios_Mcl_Ip.h are different"
#endif

/* Check if source file and Emios_Mcl_Ip.h file are of the same Software version */
#if ((EMIOS_MCL_IP_SW_MAJOR_VERSION_C != EMIOS_MCL_IP_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_SW_MINOR_VERSION_C != EMIOS_MCL_IP_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_SW_PATCH_VERSION_C != EMIOS_MCL_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip.c and Emios_Mcl_Ip.h are different"
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
#define MCL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

eMIOS_Type *const Emios_Ip_paxBase[eMIOS_INSTANCE_COUNT] = IP_eMIOS_BASE_PTRS;

#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

#if (EMIOS_IP_MULTICORE_IS_AVAILABLE == STD_ON)

    #define MCL_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #include "Mcl_MemMap.h"

    static Emios_Ip_InstStateType Emios_Ip_axIpIsInitialized[eMIOS_INSTANCE_COUNT] =
    {
        {(boolean)FALSE, (uint8)255}
    };

    #define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #include "Mcl_MemMap.h"

#else

    #define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Mcl_MemMap.h"

    VAR_SEC_NOCACHE(Emios_Ip_axIpIsInitialized) static Emios_Ip_InstStateType Emios_Ip_axIpIsInitialized[eMIOS_INSTANCE_COUNT];

    #define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #include "Mcl_MemMap.h"

#endif


#define MCL_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

VAR_SEC_NOCACHE(Emios_Ip_axChState) static Emios_Ip_ChStateType Emios_Ip_axChState[eMIOS_INSTANCE_COUNT][eMIOS_CH_UC_UC_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Mcl_MemMap.h"

#if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
#define MCL_START_SEC_VAR_CLEARED_32
#include "Mcl_MemMap.h"

/* Array to store the period master bus */
static uint32 Emios_Ip_ChPeriodMasterBus[eMIOS_INSTANCE_COUNT][eMIOS_CH_UC_UC_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_32
#include "Mcl_MemMap.h"
#else
#define MCL_START_SEC_VAR_CLEARED_16
#include "Mcl_MemMap.h"

/* Array to store the period master bus */
static uint16 Emios_Ip_ChPeriodMasterBus[eMIOS_INSTANCE_COUNT][eMIOS_CH_UC_UC_COUNT];

#define MCL_STOP_SEC_VAR_CLEARED_16
#include "Mcl_MemMap.h"
#endif

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
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/** @implements Emios_Mcl_Ip_Init_Activity */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_Init(uint8 Instance, const Emios_Mcl_Ip_ConfigType* const ConfigPtr)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(ConfigPtr != NULL_PTR);
#endif

    uint8                     CurrentChannel;
    eMIOS_Type*               Base   = Emios_Ip_paxBase[Instance];
    Emios_Ip_CommonStatusType Status = EMIOS_IP_COMMON_STATUS_SUCCESS;

#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    uint8 coreID = (uint8)OsIf_GetCoreID();
    if ( MULTICORE_INIT_CORE == coreID )
    {
#endif /* STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE */

        if (Emios_Ip_axIpIsInitialized[Instance].instanceInitState == TRUE)
        {
            Status = EMIOS_IP_COMMON_STATUS_FAIL;
        }
        else
        {
            /* Initialization of EMIOS instance specific parameters. */
            Base->MCR &= ~eMIOS_MCR_GPREN_MASK;
            Base->MCR = eMIOS_MCR_GPRE(ConfigPtr->emiosGlobalConfig->clkDivVal) | eMIOS_MCR_FRZ(((uint32)ConfigPtr->emiosGlobalConfig->allowDebugMode)) | \
                        eMIOS_MCR_GTBE(ConfigPtr->emiosGlobalConfig->enableGlobalTimeBase);

            /* Initialization of EMIOS channel specific parameters. */
            for (CurrentChannel = 0; CurrentChannel < ConfigPtr->channelsNumber; CurrentChannel++)
            {
                if ((*ConfigPtr->masterBusConfig)[CurrentChannel].allowDebugMode)
                {
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].C |= eMIOS_C_FREN_MASK;
                }

                /* Set Cn UCPRE to divider. */
                Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].C2 |= eMIOS_C2_UCEXTPRE((*ConfigPtr->masterBusConfig)[CurrentChannel].masterBusPrescaler);

                switch ((*ConfigPtr->masterBusConfig)[CurrentChannel].masterMode)
                {
                case EMIOS_IP_MC_UP_COUNTER_START:
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].A = (*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                    break;
                case EMIOS_IP_MC_UP_COUNTER_END:
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].A = (*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                    break;
                case EMIOS_IP_MC_UP_DOWN_COUNTER:
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].B = 0;
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].A = (*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                    break;
                case EMIOS_IP_MCB_UP_COUNTER:
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].A = (*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                    break;
                case EMIOS_IP_MCB_UP_DOWN_COUNTER:
                    Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].A = (*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                    break;
                default:
                    /* Do nothing. */
                    break;
                }

                /* Write CNT register with start offset value. */
                Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].CNT = (*ConfigPtr->masterBusConfig)[CurrentChannel].offsetStartValue;

                /* Set mode Cn_MODE = mode. */
                Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].C |= eMIOS_C_MODE((*ConfigPtr->masterBusConfig)[CurrentChannel].masterMode);

                Base->CH.UC[(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].C |= eMIOS_C_UCPREN(1U);

                /* Save current state of channel. */
                Emios_Ip_axChState[Instance][(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].counterMode      = (*ConfigPtr->masterBusConfig)[CurrentChannel].masterMode;
                Emios_Ip_axChState[Instance][(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel].channelInitState = TRUE;
                /* Save the period of master bus channel. */
                #if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
                Emios_Ip_ChPeriodMasterBus[Instance][(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel] = (uint32)(*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                #else
                Emios_Ip_ChPeriodMasterBus[Instance][(*ConfigPtr->masterBusConfig)[CurrentChannel].hwChannel] = (uint16)(*ConfigPtr->masterBusConfig)[CurrentChannel].defaultPeriod;
                #endif
            }

            /* Save current state of the instance. */
            Emios_Ip_axIpIsInitialized[Instance].instanceInitState = TRUE;
#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
            Emios_Ip_axIpIsInitialized[Instance].runCore           = ConfigPtr->instanceCoreNumber;
#endif
        }

        Base->MCR |= eMIOS_MCR_GPREN_MASK;

#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        Status = EMIOS_IP_COMMON_STATUS_WRONG_CORE;
    }
#endif /* STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE */

    return Status;
}

/** @implements Emios_Mcl_Ip_EnableChannel_Activity */
void Emios_Mcl_Ip_EnableChannel(uint8 Instance, uint8 HwChannel)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(HwChannel < eMIOS_CH_UC_UC_COUNT);
#endif

    eMIOS_Type* Base = Emios_Ip_paxBase[Instance];
    Base->UCDIS &= ~(uint32)((uint32)1 << ((uint32)HwChannel));
}

/** @implements Emios_Mcl_Ip_DisableChannel_Activity */
void Emios_Mcl_Ip_DisableChannel(uint8 Instance, uint8 HwChannel)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(HwChannel < eMIOS_CH_UC_UC_COUNT);
#endif

    eMIOS_Type* Base = Emios_Ip_paxBase[Instance];
    Base->UCDIS |= (uint32)((uint32)1 << ((uint32)HwChannel));
}

/** @implements Emios_Mcl_Ip_ComparatorTransferEnable_Activity */
void Emios_Mcl_Ip_ComparatorTransferEnable(uint8 Instance, uint32 ChannelMask)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(ChannelMask < EMIOS_CHANNELMASK_MAXVAL);
#endif

    eMIOS_Type* Base = Emios_Ip_paxBase[Instance];
    /* Update enable. */
    Base->OUDIS &= ~(ChannelMask);
}

/** @implements Emios_Mcl_Ip_ComparatorTransferDisable_Activity */
void Emios_Mcl_Ip_ComparatorTransferDisable(uint8 Instance, uint32 ChannelMask)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(ChannelMask < EMIOS_CHANNELMASK_MAXVAL);
#endif

    eMIOS_Type* Base = Emios_Ip_paxBase[Instance];
    /* Disable channel output. */
    Base->OUDIS |= ChannelMask;
}

/** @implements Emios_Mcl_Ip_Deinit_Activity */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_Deinit(uint8 Instance)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
#endif

    uint8                     CurrentChannel;
    Emios_Ip_CommonStatusType Status = EMIOS_IP_COMMON_STATUS_SUCCESS;
    eMIOS_Type*               Base   = Emios_Ip_paxBase[Instance];

#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    uint8 coreID = (uint8)OsIf_GetCoreID();
    if ( MULTICORE_INIT_CORE == coreID )
    {
#endif /* STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE */
        if (Emios_Ip_axIpIsInitialized[Instance].instanceInitState == FALSE)
        {
            Status = EMIOS_IP_COMMON_STATUS_FAIL;
        }
        else
        {
            Base->MCR &= ~eMIOS_MCR_GPREN_MASK;
            Base->MCR = eMIOS_MCR_GPRE(0U) | eMIOS_MCR_FRZ(0U) | eMIOS_MCR_GTBE(0U);

            for (CurrentChannel = 0; CurrentChannel < eMIOS_CH_UC_UC_COUNT; CurrentChannel++)
            {
                if(Emios_Ip_axChState[Instance][CurrentChannel].channelInitState == TRUE)
                {
                    /* Disable channel pre-scaler (reset default) */
                    Emios_Ip_paxBase[Instance]->CH.UC[CurrentChannel].C = 0U;
                    /* Reset An and Bn registers */
                    Emios_Ip_paxBase[Instance]->CH.UC[CurrentChannel].A = 0UL;
                    Emios_Ip_paxBase[Instance]->CH.UC[CurrentChannel].B = 0UL;

                    Emios_Ip_paxBase[Instance]->UCDIS |= (uint32)((uint32)0 << ((uint32)CurrentChannel));
                    /* Clear the period of master bus channel. */
                    #if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
                    Emios_Ip_ChPeriodMasterBus[Instance][CurrentChannel] = (uint32)0U;
                    #else
                    Emios_Ip_ChPeriodMasterBus[Instance][CurrentChannel] = (uint16)0U;
                    #endif
                    Emios_Ip_axChState[Instance][CurrentChannel].channelInitState = FALSE;
                }
            }
            Emios_Ip_axIpIsInitialized[Instance].instanceInitState = FALSE;
        }
#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
    }
    else
    {
        Status = EMIOS_IP_COMMON_STATUS_WRONG_CORE;
    }
#endif /* STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE */

    return Status;
}

/** @implements Emios_Mcl_Ip_SetReloadInterval_Activity */
void Emios_Mcl_Ip_SetReloadInterval(uint8 HwInstance, uint8 HwChannel, uint8 Interval)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert((uint8)31 > Interval);
    DevAssert(HwInstance < eMIOS_INSTANCE_COUNT);
    DevAssert(HwChannel < eMIOS_CH_UC_UC_COUNT);
#endif
    /* Specifies the delay interval, in counter bus reload events, between each assertion
     * of AS1-BS1 reload in MC and MCB modes. */
    Emios_Ip_paxBase[HwInstance]->CH.UC[HwChannel].C2 = eMIOS_C2_UCRELDEL_INT(Interval);
}

/** @implements Emios_Mcl_Ip_ValidateChannel_Activity */
boolean Emios_Mcl_Ip_ValidateChannel(uint8 HwInstance, uint8 HwChannel)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    /* Check input parameter*/
    DevAssert(HwInstance < eMIOS_INSTANCE_COUNT);
    DevAssert(HwChannel < eMIOS_CH_UC_UC_COUNT);
#endif
    boolean Valid = FALSE;

    if (TRUE == Emios_Ip_axChState[HwInstance][HwChannel].channelInitState)
    {
        Valid = TRUE;
    }
    return Valid;
}

/** @implements Emios_Mcl_Ip_SetCounterBusPeriod_Activity */
Emios_Ip_CommonStatusType Emios_Mcl_Ip_SetCounterBusPeriod(uint8 HwInstance, uint8 HwChannel, uint32 Period)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
#if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
    DevAssert((uint32)16777215 > Period);
#else
    DevAssert((uint32)65535 > Period);
#endif
    DevAssert(HwInstance < eMIOS_INSTANCE_COUNT);
    DevAssert(HwChannel < eMIOS_CH_UC_UC_COUNT);
#endif
    Emios_Ip_CommonStatusType Status = EMIOS_IP_COMMON_STATUS_FAIL;

    if (( (Emios_Ip_axChState[HwInstance][HwChannel].counterMode == EMIOS_IP_MCB_UP_COUNTER) || \
          (Emios_Ip_axChState[HwInstance][HwChannel].counterMode == EMIOS_IP_MCB_UP_DOWN_COUNTER) ) && \
          (Period < 1U) )
    {
        Status = EMIOS_IP_COMMON_STATUS_FAIL;
    }
    else
    {
        Emios_Ip_paxBase[HwInstance]->CH.UC[HwChannel].A = Period;
        /* Store the new period */
        #if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
        Emios_Ip_ChPeriodMasterBus[HwInstance][HwChannel] = Period;
        #else
        Emios_Ip_ChPeriodMasterBus[HwInstance][HwChannel] = (uint16)Period;
        #endif
        Status = EMIOS_IP_COMMON_STATUS_SUCCESS;
    }
    return Status;
}


/** @implements Emios_Mcl_Ip_GetCounterBusPeriod_Activity */
#if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
uint32 Emios_Mcl_Ip_GetCounterBusPeriod(uint8 Instance, uint8 Channel)
#else
uint16 Emios_Mcl_Ip_GetCounterBusPeriod(uint8 Instance, uint8 Channel)
#endif
{
#if (EMIOS_MCL_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(Channel < eMIOS_CH_UC_UC_COUNT);
#endif
    /* Get period of counter bus channels. */
#if (STD_ON == EMIOS_MCL_IP_24BITS_TIMER_WIDTH)
    uint32 PeriodCounterBus = Emios_Ip_ChPeriodMasterBus[Instance][Channel];
#else
    uint16 PeriodCounterBus = Emios_Ip_ChPeriodMasterBus[Instance][Channel];
#endif

    return PeriodCounterBus;
}

#if (STD_ON == EMIOS_IP_MULTICORE_IS_AVAILABLE)
/** @implements Emios_Mcl_Ip_ValidateMultiCoreInit_Activity */
boolean Emios_Mcl_Ip_ValidateMultiCoreInit(uint8 HwInstance)
{
    boolean Valid = FALSE;
    uint8 CoreId  = (uint8)OsIf_GetCoreID();

    if (Emios_Ip_axIpIsInitialized[HwInstance].runCore == CoreId)
    {
        Valid = TRUE;
    }

    return Valid;
}
#endif

void Emios_Mcl_Ip_ConfigureGlobalTimebase(uint8 Instance, uint8 Value)
{
#if (STD_ON == EMIOS_MCL_IP_DEV_ERROR_DETECT)
    DevAssert(Instance < eMIOS_INSTANCE_COUNT);
    DevAssert(((uint8)STD_ON == Value)||((uint8)STD_OFF == Value));
#endif

    eMIOS_Type* Base = Emios_Ip_paxBase[Instance];
    /* Configure GTBE bit. */
    if ((uint8)STD_ON == Value)
    {
        Base->MCR |= eMIOS_MCR_GTBE_MASK;
    }
    else
    {
        Base->MCR &= (~eMIOS_MCR_GTBE_MASK);
    }
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
