/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 *     @file       File with source code used to implement ICU driver functionality on EMIOS module.
 *     @details    This file contains the source code for all functions which are using EMIOS module.
 *     @addtogroup emios_icu_ip EMIOS IPL
 *     @{
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
#include "Emios_Icu_Ip.h"
#include "Emios_Icu_Ip_Irq.h"
#include "SchM_Icu.h"

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if (EMIOS_ICU_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif
#endif  /* EMIOS_ICU_IP_USED */

/*==================================================================================================
*                                        SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_IRQ_VENDOR_ID_C                       43
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION_C                2
#define EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION_C                0
#define EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION_C                1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_ICU_IP_IRQ_VENDOR_ID_C != EMIOS_ICU_IP_IRQ_VENDOR_ID)
    #error "Emios_Icu_Ip_Irq.c and Emios_Icu_Ip_Irq.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip_Irq.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.c and Emios_Icu_Ip_Irq.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_Irq.h file are of the same Software version */
#if ((EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_Irq.c and Emios_Icu_Ip_Irq.h are different"
#endif

#if (EMIOS_ICU_IP_IRQ_VENDOR_ID_C != EMIOS_ICU_IP_VENDOR_ID)
    #error "Emios_Icu_Ip_Irq.c and Emios_Icu_Ip.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.c and Emios_Icu_Ip.h are different"
#endif

/* Check if header file and Emios_Icu_Ip.h file are of the same Software version */
#if ((EMIOS_ICU_IP_IRQ_SW_MAJOR_VERSION_C != EMIOS_ICU_IP_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_MINOR_VERSION_C != EMIOS_ICU_IP_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_IRQ_SW_PATCH_VERSION_C != EMIOS_ICU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip_Irq.c and Emios_Icu_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and SchM_Icu.h file are of the same Autosar version */
    #if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.c and SchM_Icu.h are different"
    #endif

    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if(EMIOS_ICU_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (EMIOS_ICU_IP_IRQ_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip_Irq.c and Devassert.h are different"
            #endif
        #endif
    #endif  /* EMIOS_ICU_IP_USED */
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief This function will handle the event interrupt.
 *
 * @param instance  : eMIOS module index
 * @param channel   : eMIOS encoded hardware channel
 * @param bOverflow : Overflow status
 */
static inline void Emios_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel, boolean bOverflow);

/**
 * @brief This function will handle the overflow interrupt.
 *
 * @param instance  : eMIOS module index
 * @param channel   : eMIOS encoded hardware channel
 * @param bOverflow : Overflow status
 */
static inline void Emios_Icu_Ip_ReportOverflow(uint8 instance, uint8 hwChannel, boolean bOverflow);

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Emios_Icu_Ip_GetCaptureRegB
* @details    This function returns the register B of the given eMIOS Unified Channel
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register B
*
* @api
*/
static inline uint32 Emios_Icu_Ip_GetCaptureRegB(const uint8 instance,
                                                 const uint8 hwChannel
                                                );
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Emios_Icu_Ip_GetCaptureRegA
* @details    This function returns the register A of the given eMIOS Unified Channel
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register A
*
* @api
*/
static inline uint32 Emios_Icu_Ip_GetCaptureRegA(const uint8 instance,
                                                 const uint8 hwChannel
                                                );
#endif /* (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) */

/**
* @brief      Emios_Icu_Ip_ClearStatusFlags
* @details    Clear the flags set only for selected interrupts that are enabled
*
* @param[in]      instance     - eMIOS module index
* @param[in]      hwChannel    - eMIOS Hardware Channel
* @param[in]      u32BitMask   - flags to be cleared
*
* @return void
*
**/
static inline void Emios_Icu_Ip_ClearStatusFlags(const uint8 instance,
                                                 const uint8 hwChannel,
                                                 uint32 u32BitMask
                                                );

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that checks the overflow flag
* @details    This function returns clock mode of channel
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - hardware channel eMIOS
*
* @return     uint32
*
*/
static inline uint32 Emios_Icu_Ip_GetChannelClockMode(const uint8 instance,
                                                      const uint8 hwChannel
                                                     );

/**
* @brief      This function will save the value of pulse width and period 
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - hardware channel eMIOS
* @param[in]  activePulseWidth - hardware channel eMIOS
* @param[in]  period - hardware channel eMIOS
* @param[in]  bOverflow - overflow status
*
*/
static inline void Emios_Icu_Ip_SignalMeasurementStore(uint8  instance,
                                                       uint8  hwChannel,
                                                       eMios_Icu_ValueType activePulseWidth,
                                                       eMios_Icu_ValueType period,
                                                       boolean bOverflow
                                                      );

/**
 @brief      This function is used to read the period values for channels
 @details    This function returns the Counter Value based on the configuration
 @param[in]  hwChannel - hardware channel eMIOS
 @pre        Icu_Init must be called before.
*/
static inline uint32 Emios_Icu_Ip_ReadCounterBus(const uint8 instance,
                                                 const uint8 hwChannel
                                                );

/**
* @brief      This function will handle the interrupt for IPWM mode 
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - hardware channel eMIOS
* @param[in]  bOverflow - overflow status
*
*/
static inline void Emios_Icu_Ip_SignalMeasurementWithIPWMMode(const uint8 instance,
                                                              const uint8 hwChannel,
                                                              boolean bOverflow
                                                             );

/**
* @brief      This function will handle the interrupt for IPM mode 
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - hardware channel eMIOS
* @param[in]  bOverflow - overflow status
*
*/
static inline void Emios_Icu_Ip_SignalMeasurementWithIPMMode(const uint8 instance,
                                                             const uint8 hwChannel,
                                                             boolean bOverflow
                                                            );

#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
    /**
* @brief      This function will handle the interrupt for SAIC mode 
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - hardware channel eMIOS
* @param[in]  bOverflow - overflow status
*
*/
static inline void Emios_Icu_Ip_SignalMeasurementWithSAICMode(const uint8 instance,
                                                              const uint8 hwChannel,
                                                              boolean bOverflow
                                                             );
#endif  /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */

#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
/**
* @brief      Icu driver function that handles the masterbus interrupt of eMIOS channel.
* @details    This function:
*              - Report overflow to notify if necessary
*
* @param[in]  hwChannel - eMIOS hardware channel
*
*/
static inline eMios_Icu_Ip_BusType Emios_Icu_Ip_ValidateChannelUsedMasterbus(const uint8 instance,
                                                                             const uint8 hwChannel
                                                                            );
#endif

/**
* @brief      Emios_Icu_Ip_GetStatusFlags
* @details    Returns the flags set only for the enabled interrupts
*
* @param[in]   hwChannel - eMIOS Hardware Channel
*
* @return      uint32 - Flags set for enabled interrupts
**/
static inline uint32 Emios_Icu_Ip_GetStatusFlags(const uint8 instance,
                                                 const uint8 hwChannel
                                                );

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
/**
* @brief      Icu driver function that handles the masterbus interrupt of eMIOS channel.
* @details    This function:
*              - Report overflow to notify if necessary
*
* @param[in]  hwChannel - eMIOS hardware channel
*/
static inline void Emios_Icu_Ip_ProcessMasterBusInterrupt(const uint8 instance,
                                                          const uint8 hwChannel
                                                         );
#endif

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API )
/**
 * @brief      Icu driver function that handles the timestamp measurement type interrupt.
 * @details    This service is  called when an  interrupt is recognized  as a Timestamp
 *             Measurement type.
 *
 * @param[in]  hwChannel - The index of ICU channel for current configuration structure
 * @param[in]  bOverflow        Parameter that indicates the source of report is an overflow
 * @implements Emios_Icu_Ip_TimestampHandler_Activity
*/
static void Emios_Icu_Ip_TimestampHandler(uint8        instance,
                                          uint8        hwChannel,
                                          const eMios_Icu_ValueType *bufferPtr,
                                          boolean      bOverflow
                                         );
#endif /* STD_ON == EMIOS_ICU_IP_TIMESTAMP_API */

#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
static inline void Emios_Icu_Ip_WSCProcessInterrupt(uint8 instance, uint8 channel);

static inline void Emios_Icu_Ip_WsClearStatusFlags(uint8 instance, uint8 channel, uint32 u32BitMask);
    #endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline uint32 Emios_Icu_Ip_GetCaptureRegB(const uint8 instance,
                                                 const uint8 hwChannel
                                                )
{
    /*return the value of shadow register*/
    return (s_emiosBase[instance]->CH.UC[hwChannel].B & eMIOS_B_B_MASK);
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline uint32 Emios_Icu_Ip_GetCaptureRegA(const uint8 instance,
                                                 const uint8 hwChannel
                                                )
{
#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif
    /*get the value of A shadow register*/
    return (s_emiosBase[instance]->CH.UC[hwChannel].A & eMIOS_A_A_MASK);
}
#endif /* (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) */

static inline void Emios_Icu_Ip_ClearStatusFlags(const uint8 instance,
                                                 const uint8 hwChannel,
                                                 uint32 u32BitMask
                                                )
{
    s_emiosBase[instance]->CH.UC[hwChannel].S = (u32BitMask & (eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK));
}

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline uint32 Emios_Icu_Ip_GetChannelClockMode(const uint8 instance,
                                                      const uint8 hwChannel
                                                     )
{
    /*return the value of mode selection*/
    return (s_emiosBase[instance]->CH.UC[hwChannel].C & eMIOS_C_MODE_MASK);
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline void Emios_Icu_Ip_SignalMeasurementStore(uint8  instance,
                                                       uint8  hwChannel,
                                                       eMios_Icu_ValueType activePulseWidth,
                                                       eMios_Icu_ValueType period,
                                                       boolean bOverflow
                                                      )
{
    /* Saving measurement data into state variable for later usage */
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aActivePulseWidth = activePulseWidth;
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aPeriod = period;


    /* Calling HLD logical channel status changer */
    if(NULL_PTR != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].logicChStateCallback)
    {
        eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].logicChStateCallback(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callbackParam, (1U << 1), TRUE);
    }

    /* Calling HLD for reporting wakeup and overflow */
    Emios_Icu_Ip_ReportOverflow(instance, hwChannel, bOverflow);
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline uint32 Emios_Icu_Ip_ReadCounterBus(const uint8 instance,
                                                 const uint8 hwChannel
                                                )
{
    uint32 u32Period = (uint32)0u;
    uint32 u32BusChannelClockMode = (uint32)0u;

    /* Get eMiosBus of hardware channel */
    eMios_Icu_Ip_BusType u32ChannelEmiosBus = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected;

    switch (u32ChannelEmiosBus)
    {
        case EMIOS_ICU_BUS_INTERNAL_COUNTER:
        {
            u32Period = EMIOS_ICU_IP_COUNTER_MASK;
        }
        break;

        case EMIOS_ICU_BUS_DIVERSE:
        {
            if (EMIOS_ICU_IP_CHANNEL_7 >= hwChannel)
            {
                u32BusChannelClockMode = Emios_Icu_Ip_GetChannelClockMode(instance, EMIOS_ICU_IP_CHANNEL_0);
                /* eMIOS Counter Bus_B Channel (EMIOS_ICU_IP_CHANNEL_0) is in Modulous counter buffer or
                Modulous counter mode */
                if (EMIOS_ICU_IP_MCB_INT_CLOCK_U32 == u32BusChannelClockMode)
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegA(instance, EMIOS_ICU_IP_CHANNEL_0);
                }
                else
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegB(instance, EMIOS_ICU_IP_CHANNEL_0);
                }
            }
            /* eMIOS Channel configured is using Counter Bus_D */
            else if (EMIOS_ICU_IP_CHANNEL_23 >= hwChannel )
            {
                u32BusChannelClockMode = Emios_Icu_Ip_GetChannelClockMode(instance, EMIOS_ICU_IP_CHANNEL_16);
                /* eMIOS Counter Bus_D Channel (EMIOS_ICU_IP_CHANNEL_16) is in Modulous counter buffer or
                 Modulous counter mode */
                if (EMIOS_ICU_IP_MCB_INT_CLOCK_U32 == u32BusChannelClockMode)
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegA(instance, EMIOS_ICU_IP_CHANNEL_16);
                }
                else
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegB(instance, EMIOS_ICU_IP_CHANNEL_16);
                }
            }

            /* eMIOS Channel configured is using Counter Bus_E */
            else
            {
                u32BusChannelClockMode = Emios_Icu_Ip_GetChannelClockMode(instance, EMIOS_ICU_IP_CHANNEL_24);
                /* eMIOS Counter Bus_E Channel (EMIOS_ICU_IP_CHANNEL_24) is in Modulous counter buffer or
                 Modulous counter mode */
                if (EMIOS_ICU_IP_MCB_INT_CLOCK_U32 == u32BusChannelClockMode)
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegA(instance, EMIOS_ICU_IP_CHANNEL_24);
                }
                else
                {
                    u32Period= (uint32)Emios_Icu_Ip_GetCaptureRegB(instance, EMIOS_ICU_IP_CHANNEL_24);
                }
            }
        }
        break;

        case EMIOS_ICU_BUS_A:
        {
            /* Get clock mode */
            u32BusChannelClockMode = Emios_Icu_Ip_GetChannelClockMode(instance, EMIOS_ICU_IP_CHANNEL_23);

            if(EMIOS_ICU_IP_MCB_INT_CLOCK_U32 == u32BusChannelClockMode)
            {
                u32Period  = (uint32) Emios_Icu_Ip_GetCaptureRegA(instance, EMIOS_ICU_IP_CHANNEL_23);
            }
            else
            {
                u32Period  = (uint32) Emios_Icu_Ip_GetCaptureRegB(instance, EMIOS_ICU_IP_CHANNEL_23);
            }
        }
        break;


        default:
        {
            /* Rule 16.1 requires switch well-formed */
        }
        break;
    }

    /* return u32Period */
    return (u32Period);
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline void Emios_Icu_Ip_SignalMeasurementWithIPWMMode(const uint8 instance,
                                                              const uint8 hwChannel,
                                                              boolean bOverflow
                                                             )
{
    uint8 u8ChIndex = eMios_Icu_Ip_u8IndexInChState[instance][hwChannel];
    eMios_Icu_ValueType activePulseWidth;
    eMios_Icu_ValueType IcuPeriod;
    eMios_Icu_ValueType Bus_Period;
    eMios_Icu_Ip_MeasType nMeasurement_property = eMios_Icu_Ip_axChState[u8ChIndex].measurement;

    eMios_Icu_ValueType IcuTempA = (eMios_Icu_ValueType)Emios_Icu_Ip_GetCaptureRegA(instance, hwChannel);
    eMios_Icu_ValueType IcuTempB = (eMios_Icu_ValueType)Emios_Icu_Ip_GetCaptureRegB(instance, hwChannel);

    if ((EMIOS_ICU_HIGH_TIME == nMeasurement_property) || \
        (EMIOS_ICU_LOW_TIME == nMeasurement_property))
    {
        if (IcuTempA > IcuTempB)
        {
            activePulseWidth = (eMios_Icu_ValueType)(IcuTempA - IcuTempB);
        }
        else /*Counter overflow Case*/
        {
            Bus_Period = (eMios_Icu_ValueType)Emios_Icu_Ip_ReadCounterBus(instance, hwChannel);
            activePulseWidth = (eMios_Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
        }

        Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, activePulseWidth, 0U, bOverflow);
    }
    /* Duty cycle */
    else
    {
        /* Check if a complete signal was acquired */
        if (EMIOS_ICU_MEASUREMENT_PENDING == eMios_Icu_Ip_aeInt_Counter[u8ChIndex])
        {
            /* Mark that the complete signal was acquired */
            eMios_Icu_Ip_aeInt_Counter[u8ChIndex] = EMIOS_ICU_MEASUREMENT_DUTY;
            /* Report event and possible overflow to HLD or IPL user overflow notification */
            Emios_Icu_Ip_ReportOverflow (instance, hwChannel, bOverflow);
        }
        else
        {
            /* Compute Period of the signal */
            if (IcuTempB > eMios_Icu_Ip_auTimeStart[u8ChIndex])
            {
                IcuPeriod = IcuTempB - eMios_Icu_Ip_auTimeStart[u8ChIndex];
            }
            else     /*Counter overflow Case */
            {
                Bus_Period = (eMios_Icu_ValueType)Emios_Icu_Ip_ReadCounterBus(instance, hwChannel);
                IcuPeriod = (eMios_Icu_ValueType)\
                (IcuTempB + ((uint32)Bus_Period - eMios_Icu_Ip_auTimeStart[u8ChIndex]) + 1U);
            }
            activePulseWidth = eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex];

            if (EMIOS_ICU_DUTY_CYCLE == nMeasurement_property)
            {
                Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, activePulseWidth, IcuPeriod, bOverflow);
            }
            else if (EMIOS_ICU_PERIOD_TIME == nMeasurement_property)
            {
                Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, 0U, IcuPeriod, bOverflow);
            }
            else
            {
                /* Nothing to do */
            }
        }
    }

    if (IcuTempA > IcuTempB)
    {
        eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex] = (eMios_Icu_ValueType)(IcuTempA - IcuTempB);
    }
    else /*Counter overflow Case */
    {
        Bus_Period = (eMios_Icu_ValueType)Emios_Icu_Ip_ReadCounterBus(instance, hwChannel);
        eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex] = (eMios_Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
    }
    eMios_Icu_Ip_auTimeStart[u8ChIndex] = (eMios_Icu_ValueType)IcuTempB;
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
static inline void Emios_Icu_Ip_SignalMeasurementWithIPMMode(const uint8 instance,
                                                             const uint8 hwChannel,
                                                             boolean bOverflow
                                                            )
{
    eMios_Icu_ValueType IcuPeriod;
    eMios_Icu_ValueType Bus_Period;
    eMios_Icu_ValueType IcuTempA = (eMios_Icu_ValueType)Emios_Icu_Ip_GetCaptureRegA(instance, hwChannel);
    eMios_Icu_ValueType IcuTempB = (eMios_Icu_ValueType)Emios_Icu_Ip_GetCaptureRegB(instance, hwChannel);

    if (IcuTempA > IcuTempB)
    {
        IcuPeriod = (eMios_Icu_ValueType)(IcuTempA - IcuTempB);
    }
    else     /*Counter overflow Case*/
    {
        Bus_Period = (eMios_Icu_ValueType)Emios_Icu_Ip_ReadCounterBus(instance, hwChannel);
        IcuPeriod = (eMios_Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
    }
    Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, 0U, IcuPeriod, bOverflow);
}
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
static inline void Emios_Icu_Ip_SignalMeasurementWithSAICMode(const uint8 instance,
                                                              const uint8 hwChannel,
                                                              boolean bOverflow
                                                             )
{
    uint8 u8ChIndex = eMios_Icu_Ip_u8IndexInChState[instance][hwChannel];
    eMios_Icu_ValueType activePulseWidth;
    eMios_Icu_ValueType IcuPeriod;
    eMios_Icu_ValueType Bus_Period;
    eMios_Icu_Ip_MeasType nMeasurement_property = eMios_Icu_Ip_axChState[u8ChIndex].measurement;
    eMios_Icu_ValueType IcuTempA = (eMios_Icu_ValueType)Emios_Icu_Ip_GetCaptureRegA(instance, hwChannel);
    eMios_Icu_ValueType Previous_Value;
    eMios_Icu_ValueType Pulse_Width;

    Emios_Icu_Ip_SetActivation (instance, hwChannel, EMIOS_OPPOSITE_EDGES);

    if (EMIOS_ICU_MEASUREMENT_PENDING == eMios_Icu_Ip_aeInt_Counter[u8ChIndex])
    {
        /* store the first value */
        eMios_Icu_Ip_auTimeStart[u8ChIndex] = IcuTempA;
        eMios_Icu_Ip_aeInt_Counter[u8ChIndex] = EMIOS_ICU_MEASUREMENT_DUTY;
    }
    else
    {
        Previous_Value = eMios_Icu_Ip_auTimeStart[u8ChIndex];
        /* if first value is greater than the second value */
        if (IcuTempA < Previous_Value)
        {
            Bus_Period = (eMios_Icu_ValueType)Emios_Icu_Ip_ReadCounterBus(instance, hwChannel);
            Pulse_Width = (Bus_Period - Previous_Value) + IcuTempA + 1U;
        }
        else
        {
            Pulse_Width = IcuTempA - Previous_Value;
        }

        /* HIGH TIME or LOW TIME measurement */
        if ((EMIOS_ICU_HIGH_TIME == nMeasurement_property) ||   \
            (EMIOS_ICU_LOW_TIME == nMeasurement_property)
           )
        {
            activePulseWidth = Pulse_Width;
            /* clear to measure next LOW/HIGH pulse */
            eMios_Icu_Ip_aeInt_Counter[u8ChIndex] = EMIOS_ICU_MEASUREMENT_PENDING;
            Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, activePulseWidth, (eMios_Icu_ValueType)0U, bOverflow);
        }
        /* Duty Cycle */
        else
        {
            /* DUTYCYCLE or PERIOD measurement */
            if (EMIOS_ICU_MEASUREMENT_DUTY == eMios_Icu_Ip_aeInt_Counter[u8ChIndex])
            {
                eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex] = Pulse_Width;
                eMios_Icu_Ip_aeInt_Counter[u8ChIndex] = EMIOS_ICU_MEASUREMENT_PERIOD;
                if(eMios_Icu_Ip_axChState[u8ChIndex].callback != NULL_PTR)
                {
                    eMios_Icu_Ip_axChState[u8ChIndex].callback(eMios_Icu_Ip_axChState[u8ChIndex].callbackParam, bOverflow);
                }
            }
            else
            {
                /* eMios_Icu_Ip_aeInt_Counter is for period */
                IcuPeriod = eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex] + Pulse_Width;
                activePulseWidth = eMios_Icu_Ip_auCapturedActivePulseWidth[u8ChIndex];

                /* set to Duty to find active pulse width next time */
                eMios_Icu_Ip_aeInt_Counter[u8ChIndex] = EMIOS_ICU_MEASUREMENT_DUTY;
                if (EMIOS_ICU_DUTY_CYCLE == nMeasurement_property)
                {
                    Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, activePulseWidth, IcuPeriod, bOverflow);
                }
                else if (EMIOS_ICU_PERIOD_TIME == nMeasurement_property)
                {
                    Emios_Icu_Ip_SignalMeasurementStore(instance, hwChannel, (eMios_Icu_ValueType)0U, IcuPeriod, bOverflow);
                }
                else
                {
                    /**/
                }
            }
            /* store for next time */
            eMios_Icu_Ip_auTimeStart[u8ChIndex] = IcuTempA;
        }
    }
}
#endif  /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
static inline eMios_Icu_Ip_BusType Emios_Icu_Ip_ValidateChannelUsedMasterbus(const uint8 instance,
                                                                             const uint8 hwChannel
                                                                            )
{
    eMios_Icu_Ip_BusType busResult = (eMios_Icu_Ip_BusType)EMIOS_ICU_BUS_INTERNAL_COUNTER;

    /*change bus if it is not the mode of no measurement*/
    if (EMIOS_ICU_MODE_NO_MEASUREMENT != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].channelMode)
    {
        busResult = (eMios_Icu_Ip_BusType)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].BusSelected;
    }
    return busResult;
}
#endif

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_API )
static void Emios_Icu_Ip_TimestampHandler(uint8        instance,
                                          uint8        hwChannel,
                                          const eMios_Icu_ValueType *bufferPtr,
                                          boolean      bOverflow
                                         )
{
    Emios_Icu_Ip_ReportOverflow(instance, hwChannel, bOverflow);

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer[eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex] = bufferPtr[0U];
    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex++;

    if (eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex >= eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize)
    {
        if(EMIOS_ICU_CIRCULAR_BUFFER == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType)
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex = 0U;
        }
        else
        {
            Emios_Icu_Ip_StopTimestamp(instance, hwChannel);
            if (NULL_PTR != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].logicChStateCallback)
            {
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].logicChStateCallback(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callbackParam, (1U << 3), FALSE);
            }

        }
    }

    if (0U != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
    {
        eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount++;
        if (eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount >= eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount = 0U;

            /* Call User Notification Function for IPL and HLD */
            if ((NULL_PTR != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification) && \
                ((boolean)TRUE == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].notificationEnable)
               )
            {
                eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification();
            }
        }
    }
}
#endif  /* EMIOS_ICU_IP_TIMESTAMP_API */

#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
static inline void Emios_Icu_Ip_ProcessMasterBusInterrupt(const uint8 instance,
                                                          const uint8 hwChannel
                                                         )
{
    uint8 nCounter;
    boolean bOverflowUsingMasterbus = FALSE;
    eMios_Icu_Ip_ModeType nMeasMode;
    eMios_Icu_Ip_BusType BusSelected;

    for(nCounter=0U; nCounter < EMIOS_ICU_IP_NUM_OF_CHANNELS; nCounter++)
    {
        if (eMios_Icu_Ip_u8IndexInChState[instance][nCounter] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED)
        {
            bOverflowUsingMasterbus = FALSE;
            BusSelected = Emios_Icu_Ip_ValidateChannelUsedMasterbus(instance, nCounter);
            switch(BusSelected)
            {
                case EMIOS_ICU_BUS_DIVERSE:
                {
                    if
                    (
                        ((hwChannel % ((uint8)8U)) == 0U) && \
                        (nCounter <= (hwChannel + ((uint8)7U))) && (nCounter >= (hwChannel + ((uint8)1U)))
                    )
                    {
                        bOverflowUsingMasterbus = TRUE;
                    }
                }
                break;
                case EMIOS_ICU_BUS_A:
                {
                    if(EMIOS_ICU_IP_CHANNEL_23 == hwChannel)
                    {
                        bOverflowUsingMasterbus = TRUE;
                    }
                }
                break;
                default:
                {
                    /* Do nothing. */
                }
                break;
            }
            if(TRUE == bOverflowUsingMasterbus)
            {
                nMeasMode = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][nCounter]].channelMode;
                if((EMIOS_ICU_MODE_TIMESTAMP == nMeasMode) || (EMIOS_ICU_MODE_SIGNAL_MEASUREMENT == nMeasMode) || (EMIOS_ICU_MODE_SIGNAL_EDGE_DETECT == nMeasMode))
                {
                    Emios_Icu_Ip_ReportOverflow(instance, nCounter, TRUE);
                }
            }
        }
    }
}
#endif

static inline uint32 Emios_Icu_Ip_GetStatusFlags(const uint8 instance,
                                                 const uint8 hwChannel
                                                )
{
    /*return the value of status*/
    return s_emiosBase[instance]->CH.UC[hwChannel].S ;
}


static inline void Emios_Icu_Ip_ReportEvents(uint8 instance, uint8 hwChannel, boolean bOverflow)
{
    /* Calling HLD Report Events for the logical channel */
    if(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callback != NULL_PTR)
    {
        eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callback(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callbackParam, bOverflow);
    }
    else
    {
        /* Calling Notification for the IPL channel */
        if ((NULL_PTR != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification) && \
           ((boolean)TRUE == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].notificationEnable))
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification();
        }
    }
}

static inline void Emios_Icu_Ip_ReportOverflow(uint8 instance, uint8 hwChannel, boolean bOverflow)
{
    /* Calling HLD Report wakeup and overflow for the logical channel */
    if(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callback != NULL_PTR)
    {
        eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callback(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].callbackParam, bOverflow);
    }
    else
    {
        /* Calling User Overflow Notification for the IPL channel */
        if ((NULL_PTR != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosOverflowNotification) && bOverflow)
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosOverflowNotification();
        }
    }
}

#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
static inline void Emios_Icu_Ip_WSCProcessInterrupt(uint8 instance, uint8 channel)
{
    uint8 hwWSChannel;
    uint8 hwWSChannelId;
    uint32 u32WSChannelStatus;
    uint32 u32WSChannelFlagSelection;

    if (channel >= 8U)
    {
        hwWSChannel = (uint8)((channel - 8U) / 2U);
        hwWSChannelId = hwWSChannel + EMIOS_ICU_IP_WSC_CHANNEL_OFFSET;
        /* Get flag status interrupt */
        u32WSChannelStatus = (uint32)(s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSS);
        u32WSChannelFlagSelection = (uint32)(s_emiosBase[instance]->CH.WSC[hwWSChannelId].WSC2);

        if (((u32WSChannelFlagSelection & eMIOS_WSC2_FLAGSEL(EMIOS_FLAGCAP_OVRCAP_DETECT)) == eMIOS_WSC2_FLAGSEL(EMIOS_FLAGCAP_OVRCAP_DETECT)) \
            && ((u32WSChannelStatus & eMIOS_WSS_FLAGCAP_MASK) == eMIOS_WSS_FLAGCAP_MASK))
        {
            Emios_Icu_Ip_WsClearStatusFlags(instance, hwWSChannelId, eMIOS_WSS_FLAGCAPC_MASK | eMIOS_WSS_OVRCAPC_MASK);
            if (NULL_PTR != eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCAPNotification)
            {
                eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCAPNotification();
            }
        }
        if (((u32WSChannelFlagSelection & eMIOS_WSC2_FLAGSEL(EMIOS_FLAGCE_OVRCE_DETECT)) == eMIOS_WSC2_FLAGSEL(EMIOS_FLAGCE_OVRCE_DETECT)) \
            && ((u32WSChannelStatus & eMIOS_WSS_FLAGCE_MASK) == eMIOS_WSS_FLAGCE_MASK))
        {
            Emios_Icu_Ip_WsClearStatusFlags(instance, hwWSChannelId, eMIOS_WSS_FLAGCEC_MASK | eMIOS_WSS_OVRCEC_MASK);
            if (NULL_PTR != eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCENotification)
            {
                eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCENotification();
            }
        }
        if (((u32WSChannelFlagSelection & eMIOS_WSC2_FLAGSEL(EMIOS_FLAGECO_OVRECO_DETECT)) == eMIOS_WSC2_FLAGSEL(EMIOS_FLAGECO_OVRECO_DETECT)) \
            && ((u32WSChannelStatus & eMIOS_WSS_FLAGECO_MASK) == eMIOS_WSS_FLAGECO_MASK))
        {
            Emios_Icu_Ip_WsClearStatusFlags(instance, hwWSChannelId, eMIOS_WSS_FLAGECOC_MASK | eMIOS_WSS_OVRECOC_MASK);
            if (NULL_PTR != eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCEONotification)
            {
                eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsCEONotification();
            }
        }
        if (((u32WSChannelFlagSelection & eMIOS_WSC2_FLAGSEL(EMIOS_FLAGPWO_OVRPWO_DETECT)) == eMIOS_WSC2_FLAGSEL(EMIOS_FLAGPWO_OVRPWO_DETECT)) \
            && ((u32WSChannelStatus & eMIOS_WSS_FLAGPWO_MASK) == eMIOS_WSS_FLAGPWO_MASK))
        {
            Emios_Icu_Ip_WsClearStatusFlags(instance, hwWSChannelId, eMIOS_WSS_FLAGPWOC_MASK | eMIOS_WSS_OVRPWOC_MASK);
            if (NULL_PTR != eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsPWONotification)
            {
                eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsPWONotification();
            }
        }
        if (((u32WSChannelFlagSelection & eMIOS_WSC2_FLAGSEL(EMIOS_FLAGPW_OVRPW_DETECT)) == eMIOS_WSC2_FLAGSEL(EMIOS_FLAGPW_OVRPW_DETECT)) \
            && ((u32WSChannelStatus & eMIOS_WSS_FLAGPW_MASK) == eMIOS_WSS_FLAGPW_MASK))
        {
            Emios_Icu_Ip_WsClearStatusFlags(instance, hwWSChannelId, eMIOS_WSS_FLAGPWC_MASK | eMIOS_WSS_OVRPWC_MASK);
            if (NULL_PTR != eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsPWNotification)
            {
                eMios_Icu_Ip_axWsChState[instance][hwWSChannel].WsPWNotification();
            }
        }
    }
}

static inline void Emios_Icu_Ip_WsClearStatusFlags(uint8 instance, uint8 channel, uint32 u32BitMask)
{
    /* Clear status flag */
    s_emiosBase[instance]->CH.WSC[channel].WSS |= u32BitMask;
}
    #endif
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
void Emios_Icu_Ip_SignalMeasurementHandler(const uint8 instance,
                                           const uint8 hwChannel,
                                           boolean bOverflow
                                          )
{
    eMios_Icu_Ip_UCModeType eMios_OperationMode;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(hwChannel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
    DevAssert(eMios_Icu_Ip_u8IndexInChState[instance][hwChannel] < EMIOS_ICU_IP_NUM_OF_CHANNELS_USED);
#endif

    eMios_OperationMode = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].operationMode;
    switch(eMios_OperationMode)
    {
        case EMIOS_ICU_IPWM :
        {
            Emios_Icu_Ip_SignalMeasurementWithIPWMMode(instance, hwChannel, bOverflow);
        }
        break;

        case EMIOS_ICU_IPM :
        {
            Emios_Icu_Ip_SignalMeasurementWithIPMMode(instance, hwChannel, bOverflow);
        }
        break;
#if (STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE)
        case EMIOS_ICU_SAIC :
        {
            Emios_Icu_Ip_SignalMeasurementWithSAICMode(instance, hwChannel, bOverflow);
        }
        break;
#endif  /* STD_ON == EMIOS_ICU_IP_SIGNAL_MEASUREMENT_USES_SAIC_MODE */
        default:
        {
                /* Do nothing. */
        }
        break;
    }
}
#endif  /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */

/* @implements Emios_Icu_Ip_IrqHandler_Activity */
void Emios_Icu_Ip_IrqHandler(uint8 instance, uint8 channel)
{
    eMios_Icu_Ip_ModeType nMeasMode;
    uint32      u32RegCSR;

#if (STD_ON == EMIOS_ICU_IP_DEV_ERROR_DETECT)
    DevAssert(instance < EMIOS_ICU_IP_INSTANCE_COUNT);
    DevAssert(channel < EMIOS_ICU_IP_NUM_OF_CHANNELS);
#endif

    uint8 u8ChIndex = eMios_Icu_Ip_u8IndexInChState[instance][channel];
#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
    uint32 u32RegCCR = s_emiosBase[instance]->CH.UC[channel].C;
#endif
    boolean     bOverflow    = FALSE;
    boolean     bEnableInter = FALSE;

    if (u8ChIndex != EMIOS_ICU_IP_CHANNEL_NOT_USED)
    {
        /* Read UC Status Register */
        u32RegCSR = Emios_Icu_Ip_GetStatusFlags(instance, channel);

        if (TRUE != eMios_Icu_Ip_axChState[u8ChIndex].channelsInitState)
        {
            /* Clean interrupt flag. */
            Emios_Icu_Ip_ClearStatusFlags(instance, channel, u32RegCSR);
        }
        else
        {
            if (eMIOS_C_FEN_MASK == (s_emiosBase[instance]->CH.UC[channel].C & eMIOS_C_FEN_MASK))
            {
                /* Clean interrupt flag. */
                Emios_Icu_Ip_ClearStatusFlags(instance, channel, u32RegCSR);
                if (eMIOS_S_FLAG_MASK == (u32RegCSR & eMIOS_S_FLAG_MASK))
                {
                    bEnableInter = TRUE;
                }
            }
        }

        /* MCL common ISR checks for spurios interrupts already */
        if(u8ChIndex < (uint8)EMIOS_ICU_IP_NUM_OF_CHANNELS_USED)
        {
            if((EMIOS_ICU_MODE_NO_MEASUREMENT != eMios_Icu_Ip_axChState[u8ChIndex].channelMode) && bEnableInter)
            {
#if (EMIOS_ICU_IP_OVERFLOW_NOTIFICATION_API == STD_OFF)
                bOverflow = ((eMIOS_S_OVFL_MASK == (u32RegCSR & eMIOS_S_OVFL_MASK)) ? TRUE : FALSE);
#endif
                nMeasMode = eMios_Icu_Ip_axChState[u8ChIndex].channelMode;
                switch (nMeasMode)
                {
                    case EMIOS_ICU_MODE_SIGNAL_EDGE_DETECT:
                    {
                        Emios_Icu_Ip_ReportEvents (instance, channel, bOverflow);
                    }
                    break;
#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
                    case EMIOS_ICU_MODE_TIMESTAMP:
                    {
                        /* Copy the Counter value in the Timestamp Buffer. */
                        eMios_Icu_Ip_auBufferPtr[u8ChIndex] = (eMios_Icu_ValueType)(s_emiosBase[instance]->CH.UC[channel].A);

                        /* Call timestamp handler. */
                        Emios_Icu_Ip_TimestampHandler(instance, channel, &eMios_Icu_Ip_auBufferPtr[u8ChIndex], bOverflow);
                    }
                    break;
#endif /* EMIOS_ICU_IP_TIMESTAMP_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
                    case EMIOS_ICU_MODE_SIGNAL_MEASUREMENT:
                    {
                        Emios_Icu_Ip_SignalMeasurementHandler(instance, channel, bOverflow);
                    }
                    break;
#endif
#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
                    case EMIOS_ICU_MODE_EDGE_COUNTER:
                    {
                        /* Calling HLD Report Wakeup and Overflow for the logical channel */
                        /* Note: - actual version of emios does not have IRQ for overflow, in some configuration this will not get executed */
                        Emios_Icu_Ip_ReportOverflow(instance, channel, TRUE);
                    }
                    break;
#endif
                    default:
                    {
                        /* Rule 16.1 requires switch well-formed */
                    }
                    break;
                }
            }
            else
            {
                /* Nothing to do */
            }
        }
#if ((EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)||(EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)||(EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON))
        else if ((uint8)EMIOS_ICU_IP_MASTERBUS_CHANNEL_USED == u8ChIndex)
        {
            if(((0U == (channel & (uint8)EMIOS_ICU_IP_CB_DIVERSE)) || \
                (EMIOS_ICU_IP_CHANNEL_23 == channel)) \
               && (EMIOS_ICU_IP_MCB_INT_CLOCK_U32 == (u32RegCCR & eMIOS_C_MODE_MASK)))
            {
                Emios_Icu_Ip_ProcessMasterBusInterrupt(instance, channel);
            }
        }
#endif
        else
        {
            /* Nothing to do */
        }
    }
#if (defined EMIOS_ICU_IP_WSC_SUPPORT)
    #if (EMIOS_ICU_IP_WSC_SUPPORT == STD_ON)
    else
    {
        Emios_Icu_Ip_WSCProcessInterrupt(instance, channel);
    }
    #endif
#endif
}

#if (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL)
/*   @implements  Emios_Icu_Ip_TimestampDmaProcessing */
void Emios_Icu_Ip_TimestampDmaProcessing(uint8 instance, uint8 hwChannel)
{
    uint32 crtIterCount;
    uint16 noOfBufferElemToFill = 0U;

    Dma_Ip_LogicChannelTransferListType Dma_IpChUpdateDestAddress[1U];
    Dma_Ip_LogicChannelTransferListType Dma_IpChUpdateIterCount[2U];

    Dma_Ip_GetLogicChannelParam(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_GET_BEGIN_ITER_COUNT, &crtIterCount);

    eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex += (uint16)crtIterCount;
    noOfBufferElemToFill = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize - eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex;

    /* Handling notification*/
    if (0U != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
    {
        eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount += (uint16)crtIterCount;
        if  (eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount == eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount = 0U;
            /* Call User Notification Function and/or Wakeup Function */
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMiosChannelNotification();
        }
    }

    if (0U == noOfBufferElemToFill)
    {
        if ((uint8) EMIOS_ICU_CIRCULAR_BUFFER ==  eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].timestampBufferType)
        {
            eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferIndex = 0U;
            if ((eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify < eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize) &&
            (0U != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify))
            {
                Dma_IpChUpdateDestAddress[0U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                Dma_IpChUpdateDestAddress[0U].Value = (uint32)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBuffer;
                Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateDestAddress, 1U);
            }

            if ((eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferSize > (eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify - eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount)) &&
                (0U != eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify))
            {
                Dma_IpChUpdateIterCount[0U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
                Dma_IpChUpdateIterCount[0U].Value = (uint32)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify - (uint32)eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aNotifyCount;
                Dma_IpChUpdateIterCount[1U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
                Dma_IpChUpdateIterCount[1U].Value = (uint32)0U;
                Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateIterCount, 2U);
            }
        }
        else /* if linear buffer stop the timestamp*/
        {
            Emios_Icu_Ip_StopTimestamp(instance, hwChannel);
        }
    }
    else
    {
        if (crtIterCount < eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
        {
            Dma_IpChUpdateIterCount[0U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
            Dma_IpChUpdateIterCount[0U].Value = eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify;
            Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateIterCount, 1U);
        }
        if (noOfBufferElemToFill < eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].eMios_Icu_Ip_aBufferNotify)
        {
            Dma_IpChUpdateIterCount[0U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
            Dma_IpChUpdateIterCount[0U].Value = noOfBufferElemToFill;
            Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateIterCount, 1U);
        }
    }
}
#endif /* (STD_ON == EMIOS_ICU_IP_TIMESTAMP_USES_DMA_IPL) */

#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
/*   @implements  Emios_Icu_Ip_TimestampDmaProcessing */
void Emios_Icu_Ip_SignalMeasurementDmaProcessing(uint8 instance, uint8 hwChannel)
{
    uint8 u8index;
    uint32 BufferValue1;
    uint32 BufferValue2;
    uint32 BufferValue3;
    Dma_Ip_LogicChannelTransferListType Dma_IpChUpdateDestAddress[1U];
    Dma_Ip_LogicChannelTransferListType Dma_IpChUpdateIterCount[1U];

    uint32 Emios_Icu_Ip_aActivePulseWidth;
    uint32 Emios_Icu_Ip_aPeriod;

    Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_CLEAR_HARDWARE_REQUEST);

    if ((uint32)1 == Emios_Icu_Ip_aIsSecondInterrupt[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]])
    {
        BufferValue1 = Emios_Icu_Ip_aFirstEdgeTimeStamp[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]];
        BufferValue2 = Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][0] & EMIOS_ICU_IP_SHADOW_REGISTER_MAX_MASK;
        BufferValue3 = Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][1] & EMIOS_ICU_IP_SHADOW_REGISTER_MAX_MASK;
        Dma_IpChUpdateDestAddress[0U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        Dma_IpChUpdateDestAddress[0U].Value = (uint32)&Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][0];
        Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateDestAddress, 1U);
        Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

        /* Store the aPeriod value */

        if(BufferValue2 > BufferValue1)
        {
            Emios_Icu_Ip_aActivePulseWidth = BufferValue2 - BufferValue1;
        }
        else
        {
            Emios_Icu_Ip_aActivePulseWidth = (EMIOS_ICU_IP_COUNTER_MASK - BufferValue1) + BufferValue2;
        }

        /* Store the aPeriod value */
        if(BufferValue3 > BufferValue1)
        {
            Emios_Icu_Ip_aPeriod =  BufferValue3 - BufferValue1;
        }
        else
        {
            Emios_Icu_Ip_aPeriod = (EMIOS_ICU_IP_COUNTER_MASK- BufferValue1) + BufferValue3;
        }
        Emios_Icu_Ip_SetPWandPeriod(instance, hwChannel, Emios_Icu_Ip_aActivePulseWidth, Emios_Icu_Ip_aPeriod);

        Emios_Icu_Ip_aFirstEdgeTimeStamp[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][1] & EMIOS_ICU_IP_SHADOW_REGISTER_MAX_MASK;
    }
    else
    {
        Emios_Icu_Ip_aIsSecondInterrupt[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = (uint16)1;
        Emios_Icu_Ip_aFirstEdgeTimeStamp[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]] = Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][0] & EMIOS_ICU_IP_SHADOW_REGISTER_MAX_MASK;
        Dma_IpChUpdateDestAddress[0U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        Dma_IpChUpdateDestAddress[0U].Value = (uint32)&Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][0];
        Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateDestAddress, 1U);
        Dma_IpChUpdateIterCount[0U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        Dma_IpChUpdateIterCount[0U].Value = (uint16)EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT;
        Dma_Ip_SetLogicChannelTransferList(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, Dma_IpChUpdateIterCount, 1U);
        Dma_Ip_SetLogicChannelCommand(eMios_Icu_Ip_axChState[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]].dmaChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        for(u8index = 0U; u8index < EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT; u8index++)
        {
            Emios_Icu_Ip_aDmaBuffer[eMios_Icu_Ip_u8IndexInChState[instance][hwChannel]][u8index] = (uint16)0;
        }
        Emios_Icu_Ip_SetActivation(instance, hwChannel, EMIOS_ICU_BOTH_EDGES);
    }
}
#endif

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
