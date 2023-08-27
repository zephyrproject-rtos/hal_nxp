/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_H
#define EMIOS_ICU_IP_H

/**
*   @file Emios_Icu_Ip.h
*
*   @addtogroup emios_icu_ip EMIOS IPL
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Icu_Ip_Types.h"
#include "Emios_Icu_Ip_Cfg.h"

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
    /* Include common functions of EMIOS. */
        #include "Emios_Mcl_Ip.h"
    #endif
#endif  /* EMIOS_ICU_IP_USED */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_ICU_IP_VENDOR_ID                           43
#define EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION            4
#define EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION            7
#define EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION         0
#define EMIOS_ICU_IP_SW_MAJOR_VERSION                    3
#define EMIOS_ICU_IP_SW_MINOR_VERSION                    0
#define EMIOS_ICU_IP_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check Emios_Icu_Ip.h against Emios_Icu_Ip_Types.h file versions */
#if (EMIOS_ICU_IP_VENDOR_ID != EMIOS_ICU_IP_TYPES_VENDOR_ID)
    #error "Emios_Icu_Ip.h and Emios_Icu_Ip_Types.h have different vendor IDs"
#endif

#if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Emios_Icu_Ip.h and Emios_Icu_Ip_Types.h are different"
#endif

#if ((EMIOS_ICU_IP_SW_MAJOR_VERSION != EMIOS_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_SW_MINOR_VERSION != EMIOS_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_SW_PATCH_VERSION != EMIOS_ICU_IP_TYPES_SW_PATCH_VERSION))
       #error "Software Version Numbers of Emios_Icu_Ip.h  and Emios_Icu_Ip_Types.h are different"
#endif

#if (EMIOS_ICU_IP_VENDOR_ID != EMIOS_ICU_IP_CFG_VENDOR_ID)
    #error "Emios_Icu_Ip.h and Emios_Icu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if  header file and Emios_Icu_Ip_Cfg.h file are of the same Autosar version */
#if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION != EMIOS_ICU_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Icu_Ip.h and Emios_Icu_Ip_Cfg.h are different"
#endif

/* Check if header file and Emios_Icu_Ip_Cfg.h file are of the same Software version */
#if ((EMIOS_ICU_IP_SW_MAJOR_VERSION != EMIOS_ICU_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_ICU_IP_SW_MINOR_VERSION != EMIOS_ICU_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_ICU_IP_SW_PATCH_VERSION != EMIOS_ICU_IP_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Icu_Ip.h and Emios_Icu_Ip_Cfg.h are different"
#endif

#if (STD_ON == EMIOS_ICU_IP_USED)
    #if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
        /* Check if  header file and Emios_Mcl_Ip.h file are of the same Autosar version */
        #if (EMIOS_ICU_IP_VENDOR_ID != EMIOS_MCL_IP_VENDOR_ID)
            #error "Emios_Icu_Ip.h and Emios_Mcl_Ip.h have different vendor ids"
        #endif
        
        /* Check if  header file and Emios_Mcl_Ip.h file are of the same Autosar version */
        #if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION    != EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
             (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION    != EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION) || \
             (EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_AR_RELEASE_REVISION_VERSION))
            #error "AutoSar Version Numbers of Emios_Icu_Ip.h and Emios_Mcl_Ip.h are different"
        #endif
        
        /* Check if header file and Emios_Mcl_Ip.h file are of the same Software version */
        #if ((EMIOS_ICU_IP_SW_MAJOR_VERSION != EMIOS_MCL_IP_SW_MAJOR_VERSION) || \
             (EMIOS_ICU_IP_SW_MINOR_VERSION != EMIOS_MCL_IP_SW_MINOR_VERSION) || \
             (EMIOS_ICU_IP_SW_PATCH_VERSION != EMIOS_MCL_IP_SW_PATCH_VERSION))
            #error "Software Version Numbers of Emios_Icu_Ip.h and Emios_Mcl_Ip.h are different"
        #endif
    #endif
#endif  /* EMIOS_ICU_IP_USED */
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == EMIOS_ICU_IP_USED)

#if (defined EMIOS_ICU_CONFIG_EXT)
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/* Macro used to import SIUL2 PB generated configurations. */
EMIOS_ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
 * @brief      Emios_Icu_Ip_Init
 * @details    This function is called separately for each EMIOS hw channel corresponding to
 *             the configured Icu channels, and:
 *             - Disables the interrupt corresponding to eMIOS channel
 *             - Initializes prescaler value, channel filter, freeze enable, and bus select fields
 *             - Defines on which edge the period starts
 *             - Clears the (pending) interrupt flag corresponding to eMIOS channel
 *             - Resets the UC A register.
 *             - Enables the SAIC mode for eMIOS channels.
 * @param[in]  instance - EMIOS instance used.
 * @param[in]  userConfig - pointer to eMios configuration structure
 */
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Init(uint8 instance, const eMios_Icu_Ip_ConfigType *userConfig);

#if (EMIOS_ICU_IP_DEINIT_API == STD_ON)
/**
* @brief      Emios_Icu_Ip_Deinit
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Resets the eMIOS channel control register
*             - Resets the UC A register.
*             - Clears the (pending) interrupt flag corresponding to eMIOS channel
* @param[in]  peMiosIpConfig   - pointer to eMios configuration structure
*/
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Deinit(uint8 instance);
#endif

#if (EMIOS_ICU_IP_SET_MODE_API == STD_ON)
/**
* @brief      Emios_Icu_Ip_SetSleepMode
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Enables the interrupt for the eMIOS channel,
*                 if the wake up functionality is enabled
*             - Disables the interrupt for the eMIOS channel,
*                 if the wake up functionality is disabled
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @api
*/
void Emios_Icu_Ip_SetSleepMode(uint8 instance, uint8 hwChannel);

/**
* @brief      Emios_Icu_Ip_SetNormalMode
* @details    This function: Set normal mode
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @api
*/
void Emios_Icu_Ip_SetNormalMode(uint8 instance, uint8 hwChannel);
#endif  /* ICU_SET_MODE_API */

/**
* @brief      Icu driver function that sets activation condition of eMIOS channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding eMIOS channels.
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS channel index
* @param[in]  edge        - type of edge to be used
* @api
*/
void Emios_Icu_Ip_SetActivation(uint8 instance, uint8 hwChannel, eMios_Icu_Ip_EdgeType edge);

#if (EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON)
/**
* @brief      Emios_Icu_Ip_EnableEdgeDetection
* @details    eMIOS IP function that starts the edge detection service for an eMIOS channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @return void
*/
void Emios_Icu_Ip_EnableEdgeDetection(uint8 instance, uint8 hwChannel);

/**
* @brief      Emios_Icu_Ip_DisableEdgeDetection
* @details    eMIOS IP function that stops the edge detection service for an eMIOS channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @return void
*/
void Emios_Icu_Ip_DisableEdgeDetection(uint8 instance, uint8 hwChannel);
#endif /* ICU_EDGE_DETECT_API */

/**
 * @brief      Driver function Enable Notification.
 *
 * @param[in]  instance  Hardware instance used. 
 * @param[in]  hwChannel Hardware channel used.
 * @return     void
 */
void Emios_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel);

/**
 * @brief      Driver function Disable Notification.
 *
 * @param[in]  instance  Hardware instance used. 
 * @param[in]  hwChannel Hardware channel used.
 * @return     void
 */
void Emios_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel);

#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu driver function that starts time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Clears the pending interrupts
*             - Enables SAIC mode for the channel
*             - Enbales the interrupt for the channel
*
* @param[in]  instance         - eMIOS module index
* @param[in]  hwChannel        - eMIOS encoded hardware channel
* @param[in]  bufferPtr        - buffer pointer for results
* @param[in]  bufferSize       - size of buffer results
* @param[in]  notifyInterval   - interval for calling notification
* @api
*/
void Emios_Icu_Ip_StartTimestamp
(
    uint8 instance,
    uint8 hwChannel,
    eMios_Icu_ValueType * bufferPtr,
    uint16 bufferSize,
    uint16 notifyInterval
);

/**
* @brief   This function reads the timestamp index of the given channel.
* @details This function reentrant and reads the timestamp index of the given channel,
*          which is next to be written.
*
* @param[in]  instance      - eMIOS module index
* @param[in]  hwChannel     - Logical number of the ICU channel
*
* @return     uint16 - Timestamp index of the given channel
* @pre        Emios_Icu_Ip_Init must be called before. Icu_StartTimestamp must be called before.
*/
uint16 Emios_Icu_Ip_GetTimestampIndex
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Icu driver function that stops time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for the channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
* @api
*/
void Emios_Icu_Ip_StopTimestamp(uint8 instance, uint8 hwChannel);
#endif  /* EMIOS_ICU_IP_TIMESTAMP_API */

#if ((EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_USES_DMA == STD_ON))
/**
* @brief      Emios_Icu_Ip_GetStartAddress
* @details    eMIOS IP function that stops the edge detection service for an eMIOS channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @return void
*
**/
uint32 Emios_Icu_Ip_GetStartAddress
(
    uint8 instance,
    uint8 hwChannel
);
#endif

#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that resets the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Resets the counter to initial value
*             - Loads the initial value to the RegisterA
*             - Clears the pending interrupts
*             - Restores the previous mode
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @api
*/
void Emios_Icu_Ip_ResetEdgeCount
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Icu driver function that enables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Counter register is loaded with startValue
*             - Loads initial value to RegisterA
*             - Clears the pending interrupts
*             - Sets the mode to Modulus counter mode
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*/
void Emios_Icu_Ip_EnableEdgeCount(uint8 instance, uint8 hwChannel);

/**
* @brief      Icu driver function that disables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Disables the eMIOS channel interrupt
*             - Clears the pending interrupts
*             - Save the current counter value before entering into GPIO mode
*             - Puts the channel into GPIO mode
*             - Disables MCB mode for the channel
*
* @param[in]  instance     - eMIOS module index
* @param[in]  hwChannel    - eMIOS encoded hardware channel
*
* @api
*/
void Emios_Icu_Ip_DisableEdgeCount
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Icu driver function that gets edge counter measurement of eMIOS channel.
* @details    This function returns counter value (the number of counter edges) of eMIOS channel
*
* @param[in]  instance    - eMIOS module index
* @param[in]  hwChannel   - eMIOS encoded hardware channel
*
* @return     uint32 - Counted edges number
*
* @api
*/
eMios_Icu_ValueType Emios_Icu_Ip_GetEdgeNumbers
(
    uint8 instance,
    uint8 hwChannel
);

#if (STD_ON == EMIOS_ICU_IP_SET_INITIAL_COUNTER)
/**
* @brief      Icu driver function that Set Initial setting of eMIOS Counter.
* @details    This function Set Initial setting of eMIOS Counter
*
* @param[in]  instance        - eMIOS module index
* @param[in]  hwChannel       - eMIOS encoded hardware channel
* @param[in]  offsetCounter   - eMios Initial counter
*
* @pre        This function is not required because the counter value is 
*             set automatically. But to arbitrarily change the Initial value 
*             of the counter value, it is necessary to call this function 
*             before the Emios_Icu_Ip_EnableEdgeCount.
*             After call Emios_Icu_Ip_ResetEdgeCount function to reset counter value 
*             to 0, the previously set Initial value will no longer be valid.
*/
void Emios_Icu_Ip_SetInitialCounterValue
(
    uint8 instance,
    uint8 hwChannel,
    uint32 initialCounter
);
#endif  /* STD_ON == EMIOS_ICU_IP_SET_INITIAL_COUNTER */

#if (STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER)
/**
* @brief      Icu driver function that Set Max setting of eMIOS Counter.
* @details    This function Set Max setting of eMIOS Counter
*
* @param[in]  instance        - eMIOS module index
* @param[in]  hwChannel       - eMIOS encoded hardware channel
* @param[in]  defaultCounter  - eMios Max counter
*
* @pre        This function is not required because the counter value is 
*             set automatically. But to arbitrarily change the Max value 
*             of the counter value, it is necessary to call this function  
*             before the Emios_Icu_Ip_EnableEdgeCount function.
*/
void Emios_Icu_Ip_SetMaxCounterValue
(
    uint8 instance,
    uint8 hwChannel,
    uint32 maxCounter
);
#endif  /* STD_ON == EMIOS_ICU_IP_SET_MAX_COUNTER */
#endif  /* EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON */

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that starts the signal measurement of eMIOS channel.
* @details    This function:
*             - Disables the interrupt of eMIOS channel
*             - Puts the eMIOS channel into GPIO mode
*             - Sets activation condition (Rising, Falling or Both edges)
*             - Puts the eMIOS channel into requested mode (IPWM, IPM or SAIC)
*             - Clears pending interrupts
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS encoded hardware channel
*
* @api
*/
void Emios_Icu_Ip_StartSignalMeasurement
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Icu driver function that stops the signal measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for requsted eMIOS channel
*             - Clears pending interrupts
*
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS encoded hardware channel
*
* @api
*/
void Emios_Icu_Ip_StopSignalMeasurement
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief   This function reads the elapsed Signal Low, High or Period Time for the given channel.
* @details This service is reentrant and reads the elapsed Signal Low Time for the given channel
*          that is configured  in Measurement Mode Signal Measurement, Signal Low Time.
*          The elapsed time is measured between a falling edge and the consecutive rising edge of
*          the channel.
*          This service reads the elapsed Signal High Time for the given channel that is configured
*          in Measurement Mode Signal Measurement,Signal High Time.The elapsed time is measured
*          between a rising edge and the consecutive falling edge of the channel.
*          This service reads the elapsed Signal Period Time for the given channel that is
*          configured in Measurement Mode Signal Measurement,  Signal Period Time.The elapsed time
*          is measured between consecutive  rising (or falling) edges  of the  channel. The  period
*          start edge is
*
*          configurable.
*
* @param[in]  instance     - eMIOS module index
* @param[in]  hwChannel    - Logical number of the ICU channel
*
* @return     uint16 -  the elapsed Signal Low Time for the given channel that is configured in
*             Measurement Mode Signal Measurement, Signal Low Time
* @pre        Emios_Icu_Ip_Init must be called before. The channel must be configured in Measurement Mode Signal
*             Measurement.
*/
eMios_Icu_ValueType Emios_Icu_Ip_GetTimeElapsed
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief   This function reads the coherent active time and period time for the given ICU Channel.
* @details The function is reentrant and reads the coherent active time and period time for
*          the given ICU Channel, if it is configured in Measurement Mode Signal Measurement, Duty
*          Cycle Values.
*
* @param[in]     instance         - eMIOS module index
* @param[in]     hwChannel        - Logical number of the ICU channel
* @param[out]    dutyCycleValues  - Pointer to a buffer where the results (active time and period time)
*                                   shall be placed.
*
* @return     void
* @pre        Emios_Icu_Ip_Init must be called before. The given channel must be configured in Measurement Mode
*             Signal Measurement, Duty Cycle Values.
*/
void Emios_Icu_Ip_GetDutyCycleValues
(
    uint8 instance,
    uint8 hwChannel,
    eMios_Icu_Ip_DutyCycleType*  dutyCycleValues
);

/**
 * @brief Emios_Icu_Ip_SetPWandPeriod
 * 
 * @param instance 
 * @param hwChannel 
 * @param activePulseWidth 
 * @param period 
 */
void Emios_Icu_Ip_SetPWandPeriod(uint8 instance,
                                 uint8 hwChannel,
                                 eMios_Icu_ValueType activePulseWidth,
                                 eMios_Icu_ValueType period);

#endif  /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API */

#if (EMIOS_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu driver function that gets the input state of eMIOS channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding eMIOS channel is set then
*             it clears the interrupt flag and returns the value as true.
*
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS encoded hardware channel
*
* @return       boolean
* @retval       true  - if channel is active
* @retval       false - if channel is idle
*
* @api
*/
boolean Emios_Icu_Ip_GetInputState
(
    uint8 instance,
    uint8 hwChannel
);
#endif  /* EMIOS_ICU_IP_GET_INPUT_STATE_API */

#if (EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      This function returns the actual status of PIN.
* @details    This function returns the actual status o PIN
*
* @param[in]     instance   - eMIOS module index
* @param[in]     hwChannel  - eMIOS encoded hardware channel
*
* @return  void
*
* @api
*/
eMios_Icu_Ip_LevelType Emios_Icu_Ip_GetInputLevel
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON */

/**
* @brief      Emios_Icu_Ip_GetOverflow
* @details    eMIOS IP function that get the state of the overflow flag
*
* @param[in]   instance    - eMIOS module index
* @param[in]   hwChannel   - eMIOS  encoded hardware channel
*
* @return      boolean      the state of the overflow flag
* @retval      true         the overflow flag is set
* @retval      false        the overflow flag is not set
*
* @return void
*/
boolean Emios_Icu_Ip_GetOverflow
(
    uint8 instance,
    uint8 hwChannel
);

#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
void Emios_Icu_Ip_SetClockMode
(
    uint8 instance,
    const eMios_Icu_Ip_ConfigType * peMiosIpConfig,
    const eMios_Icu_Ip_ClockModeType Prescaler
);
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_CAPTURERGISTER_API == STD_ON) && ((EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)))
uint32 Emios_Icu_Ip_GetCaptureRegValue
(
    uint8 instance,
    uint8 hwChannel
);
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief      This function returns the signals High time, Low time and Period without using the
*             channel interrupt
* @details    This function returns the signals High time, Low time and Period without using the
*             channel interrupt
*
* @param[in]  instance   - eMIOS module index
* @param[in]  hwChannel  - eMIOS hardware channel
*/
void Emios_Icu_Ip_GetPulseWidth
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) &&  (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL == STD_ON) && ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)))
Std_ReturnType Emios_Icu_Ip_ValidateSignalMeasureWithoutInterrupt
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) &&  (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

/**
* @brief      Emios_Icu_Ip_EnableInterrupt
* @details    This function Clears the pending interrupts of eMIOS channels and
*             enables eMIOS Channel interrupt
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - eMIOS Channel index
* @api
*/
void Emios_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel);

/**
* @brief      Emios_Icu_Ip_DisableInterrupt
* @details    This function disables eMIOS Channel interrupt
*
* @param[in]  instance  - eMIOS module index
* @param[in]  hwChannel - eMIOS Channel index
* @api
*/
void Emios_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel);


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_H */
