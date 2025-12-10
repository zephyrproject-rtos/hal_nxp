/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_ICU_IP_H
#define EMIOS_ICU_IP_H

/**
 *   @file       Emios_Icu_Ip_Types.h
 *   @version    0.8.0
 *
 *   @brief      AUTOSAR Icu - eMIOS ICU IP driver type definitions
 *   @details    Contains the type definitions, enumerations, and structure declarations used by the eMIOS ICU IP driver.
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
#define EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION            9
#define EMIOS_ICU_IP_AR_RELEASE_REVISION_VERSION         0
#define EMIOS_ICU_IP_SW_MAJOR_VERSION                    0
#define EMIOS_ICU_IP_SW_MINOR_VERSION                    8
#define EMIOS_ICU_IP_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
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

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == EMIOS_ICU_IP_USED)
        #if (STD_ON == EMIOS_ICU_USES_MCL_DRIVER)
            /* Check if  header file and Emios_Mcl_Ip.h file are of the same Autosar version */
            #if ((EMIOS_ICU_IP_AR_RELEASE_MAJOR_VERSION    != EMIOS_MCL_IP_AR_RELEASE_MAJOR_VERSION) || \
                (EMIOS_ICU_IP_AR_RELEASE_MINOR_VERSION    != EMIOS_MCL_IP_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Emios_Icu_Ip.h and Emios_Mcl_Ip.h are different"
            #endif
        #endif
    #endif  /* EMIOS_ICU_IP_USED */
#endif
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

/* Macro used to import Emios PB generated configurations. */
EMIOS_ICU_CONFIG_EXT

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"
#endif
/*==================================================================================================
*                                        GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"
#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
extern eMios_Icu_Ip_MeasStatusType eMios_Icu_Ip_aeInt_Counter[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
extern eMios_Icu_ValueType eMios_Icu_Ip_auCapturedActivePulseWidth[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
extern eMios_Icu_ValueType eMios_Icu_Ip_auTimeStart[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */
#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
extern eMios_Icu_ValueType eMios_Icu_Ip_auBufferPtr[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];
#endif /* EMIOS_ICU_IP_TIMESTAMP_API == STD_ON */

extern eMios_Icu_Ip_ChStateType eMios_Icu_Ip_axChState[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#endif
#include "Icu_MemMap.h"

#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_START_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_START_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"
/* This array stores the positions in the eMios_Icu_Ip_axChState array of the configured eMios channels. */
extern uint8 eMios_Icu_Ip_u8IndexInChState[EMIOS_ICU_IP_INSTANCE_COUNT][EMIOS_ICU_IP_NUM_OF_CHANNELS];
#if (EMIOS_ICU_IP_NO_CACHE_USED == STD_ON)
    #define ICU_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
#else
    #define ICU_STOP_SEC_VAR_INIT_8
#endif
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"
extern eMIOS_Type * const s_emiosBase[];
#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Icu_MemMap.h"
#if (STD_ON == EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL)
/** @brief Array for saving value of DMA **/
extern volatile uint32 Emios_Icu_Ip_aDmaBuffer[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED][EMIOS_ICU_IP_DMA_MAJORLOOP_COUNT];

/** @brief Array for saving the period */
extern volatile uint32 Emios_Icu_Ip_aIsSecondInterrupt[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

/** @brief Array for saving the period */
extern volatile uint32 Emios_Icu_Ip_aFirstEdgeTimeStamp[EMIOS_ICU_IP_NUM_OF_CHANNELS_USED];

#endif /* EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA_IPL */

#define ICU_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Icu_MemMap.h"

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
 * @brief      Initialize eMIOS ICU IP driver
 * @details    This function initializes the eMIOS ICU IP driver for a specific instance.
 *             For each configured eMIOS hardware channel, it performs:
 *             - Disables the interrupt corresponding to eMIOS channel
 *             - Initializes prescaler value, channel filter, freeze enable, and bus select fields
 *             - Configures the edge detection settings (rising, falling, or both edges)
 *             - Clears any pending interrupt flags for the eMIOS channel
 *             - Resets the UC A register to initial state
 *             - Enables the SAIC (Single Action Input Capture) mode for eMIOS channels
 *             - Validates configuration parameters and hardware availability
 *
 * @param[in]  instance - eMIOS hardware instance number (0, 1, 2, etc.)
 * @param[in]  userConfig - Pointer to eMIOS ICU configuration structure containing
 *                         channel configurations, prescaler settings, and feature enables
 *
 * @return eMios_Icu_Ip_StatusType
 *         - EMIOS_IP_STATUS_SUCCESS : Driver initialized successfully
 *         - EMIOS_IP_STATUS_ERROR : Initialization failed due to invalid parameters or hardware error
 *
 * @pre        Hardware must be available and not already initialized
 * @post       eMIOS instance is ready for ICU operations
 */
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Init(uint8 instance, const eMios_Icu_Ip_ConfigType *userConfig);

#if (EMIOS_ICU_IP_DEINIT_API == STD_ON)
/**
* @brief      Deinitialize eMIOS ICU IP driver
* @details    This function deinitializes the eMIOS ICU IP driver for a specific instance.
*             For each configured eMIOS hardware channel, it performs:
*             - Disables all channel interrupts
*             - Resets the eMIOS channel control register to default state
*             - Resets the UC A register to default value
*             - Clears any pending interrupt flags for all eMIOS channels
*             - Restores hardware to power-on reset state
*             - Releases any allocated resources
*
* @param[in]  instance - eMIOS hardware instance number to deinitialize
*
* @return     eMios_Icu_Ip_StatusType
*             - EMIOS_IP_STATUS_SUCCESS : Deinitialization completed successfully
*             - EMIOS_IP_STATUS_ERROR : Deinitialization failed
*
* @pre        Instance must be previously initialized with Emios_Icu_Ip_Init
* @post       eMIOS instance is returned to uninitialized state
*/
eMios_Icu_Ip_StatusType Emios_Icu_Ip_Deinit(uint8 instance);
#endif

/**
* @brief      Configure edge activation condition for eMIOS channel
* @details    This function configures the edge detection activation condition for a specific
*             eMIOS channel. It sets the hardware registers to detect:
*             - Rising edges only
*             - Falling edges only
*             - Both rising and falling edges
*             The function modifies the channel control register to enable the requested
*             edge detection mode while preserving other channel settings.
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number (0-31 depending on instance)
* @param[in]  edge        - Edge detection type:
*                          - EMIOS_ICU_RISING_EDGE: Detect rising edges only
*                          - EMIOS_ICU_FALLING_EDGE: Detect falling edges only
*                          - EMIOS_ICU_BOTH_EDGES: Detect both rising and falling edges
*
* @return     void
*
* @pre        Emios_Icu_Ip_Init must be called before using this function
* @pre        Channel must be configured for edge detection mode
* @post       Channel will generate interrupts/events on specified edge transitions
*/
void Emios_Icu_Ip_SetActivation(uint8 instance, uint8 hwChannel, eMios_Icu_Ip_EdgeType edge);

#if (EMIOS_ICU_IP_EDGE_DETECT_API == STD_ON)
/**
* @brief      Enable edge detection service for eMIOS channel
* @details    This function starts the edge detection service for a specific eMIOS channel.
*             It performs the following operations:
*             - Configures the channel for SAIC (Single Action Input Capture) mode
*             - Enables the channel interrupt if notification is required
*             - Clears any pending interrupt flags
*             - Starts the edge detection based on previously configured activation condition
*             - Initializes internal state variables for edge detection
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return void
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for edge detection
* @pre        Edge activation condition must be set using Emios_Icu_Ip_SetActivation
* @post       Channel is actively detecting edges and can generate notifications
*/
void Emios_Icu_Ip_EnableEdgeDetection(uint8 instance, uint8 hwChannel);

/**
* @brief      Disable edge detection service for eMIOS channel
* @details    This function stops the edge detection service for a specific eMIOS channel.
*             It performs the following operations:
*             - Disables the channel interrupt
*             - Puts the channel into GPIO (inactive) mode
*             - Clears any pending interrupt flags
*             - Stops edge detection functionality
*             - Preserves channel configuration for potential restart
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return void
*
* @pre        Channel must be previously enabled for edge detection
* @post       Channel stops detecting edges and generating notifications
*/
void Emios_Icu_Ip_DisableEdgeDetection(uint8 instance, uint8 hwChannel);
#endif /* ICU_EDGE_DETECT_API */

/**
 * @brief      Enable notification for eMIOS channel
 * @details    This function enables interrupt-based notifications for a specific eMIOS channel.
 *             When enabled, the channel will generate interrupts when the configured event
 *             occurs (edge detection, capture, overflow, etc.). The interrupt will call
 *             the registered callback function if configured.
 *
 * @param[in]  instance  - eMIOS hardware instance number
 * @param[in]  hwChannel - eMIOS hardware channel number
 *
 * @return     void
 *
 * @pre        Channel must be initialized and configured for the desired operation mode
 * @post       Channel will generate interrupts when configured events occur
 */
void Emios_Icu_Ip_EnableNotification(uint8 instance, uint8 hwChannel);

/**
 * @brief      Disable notification for eMIOS channel
 * @details    This function disables interrupt-based notifications for a specific eMIOS channel.
 *             After calling this function, the channel will continue to operate but will not
 *             generate interrupts. Events can still be detected by polling methods.
 *
 * @param[in]  instance  - eMIOS hardware instance number
 * @param[in]  hwChannel - eMIOS hardware channel number
 *
 * @return     void
 *
 * @pre        Channel must be initialized
 * @post       Channel will not generate interrupts for events
 */
void Emios_Icu_Ip_DisableNotification(uint8 instance, uint8 hwChannel);

#if (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)
/**
* @brief      Start timestamp measurement for eMIOS channel
* @details    This function starts timestamp measurement service for a specific eMIOS channel.
*             It configures the channel to capture timestamps of input signal edges and store
*             them in a circular buffer. The function performs:
*             - Configures channel for SAIC (Single Action Input Capture) mode
*             - Sets up the result buffer and buffer management parameters
*             - Configures notification interval for buffer management
*             - Clears pending interrupts and enables channel interrupt
*             - Initializes timestamp capture state variables
*
* @param[in]  instance         - eMIOS hardware instance number
* @param[in]  hwChannel        - eMIOS hardware channel number
* @param[in]  bufferPtr        - Pointer to buffer for storing timestamp values
* @param[in]  bufferSize       - Size of the timestamp buffer (number of timestamps)
* @param[in]  notifyInterval   - Number of timestamps between notifications (0 = no periodic notification)
*
* @return     void
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for timestamp measurement
* @pre        bufferPtr must point to valid memory of size (bufferSize * sizeof(eMios_Icu_ValueType))
* @post       Channel actively captures timestamps and stores them in the provided buffer
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
* @brief   Get current timestamp buffer index for eMIOS channel
* @details This function returns the current index in the timestamp buffer that indicates
*          the next position where a timestamp will be written. This is useful for:
*          - Determining how many timestamps have been captured
*          - Calculating buffer fill level
*          - Synchronizing with timestamp capture process
*          The function is reentrant and can be called from interrupt context.
*
* @param[in]  instance      - eMIOS hardware instance number
* @param[in]  hwChannel     - eMIOS hardware channel number
*
* @return     uint16 - Current timestamp buffer index (0 to bufferSize-1)
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Emios_Icu_Ip_StartTimestamp must be called before to initialize timestamp capture
* @post       Returns current buffer write position
*/
uint16 Emios_Icu_Ip_GetTimestampIndex
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Stop timestamp measurement for eMIOS channel
* @details    This function stops the timestamp measurement service for a specific eMIOS channel.
*             It performs the following operations:
*             - Disables the channel interrupt to stop timestamp capture
*             - Puts the channel into GPIO (inactive) mode
*             - Clears any pending interrupt flags
*             - Preserves the current buffer contents and index
*             - Stops timestamp capture without clearing captured data
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return void
*
* @pre        Channel must be previously started for timestamp measurement
* @post       Timestamp capture is stopped, captured data remains available
*/
void Emios_Icu_Ip_StopTimestamp(uint8 instance, uint8 hwChannel);
#endif  /* EMIOS_ICU_IP_TIMESTAMP_API */

#if ((EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_USES_DMA == STD_ON))
/**
* @brief      Get DMA transfer source address for eMIOS channel
* @details    This function returns the hardware register address that should be used
*             as the source address for DMA transfers. For eMIOS ICU operations, this
*             is typically the address of the capture register (UC A register) that
*             contains the captured timestamp or measurement value.
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return uint32 - Physical address of the source register for DMA transfer
*
* @pre        Channel must be configured for DMA-based operation
* @post       Returns valid hardware register address for DMA configuration
*
**/
uint32 Emios_Icu_Ip_GetStartAddress
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* ((EMIOS_ICU_IP_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_USES_DMA == STD_ON)) */

#if (EMIOS_ICU_IP_EDGE_COUNT_API == STD_ON)
/**
* @brief      Reset edge counter for eMIOS channel
* @details    This function resets the edge counter measurement for a specific eMIOS channel.
*             It performs the following operations:
*             - Temporarily puts the channel into GPIO mode to safely reset counter
*             - Resets the internal counter to the initial value (typically 0)
*             - Loads the initial value into the UC A register
*             - Clears any pending interrupt flags
*             - Restores the previous channel operating mode
*             - Resets overflow flags and status indicators
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return void
*
* @pre        Channel must be configured for edge counting mode
* @post       Edge counter is reset to initial value, ready for new counting cycle
*/
void Emios_Icu_Ip_ResetEdgeCount
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Enable edge counting for eMIOS channel
* @details    This function enables edge counter measurement for a specific eMIOS channel.
*             It configures the channel for Modulus Counter Buffered (MCB) mode and performs:
*             - Temporarily puts channel into GPIO mode for safe configuration
*             - Loads the counter register with the configured start value
*             - Loads the initial value into UC A register
*             - Clears any pending interrupt flags
*             - Configures the channel for MCB (Modulus Counter Buffered) mode
*             - Enables channel interrupt for overflow detection (if configured)
*             - Sets up edge detection based on configured activation condition
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return void
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for edge counting mode
* @pre        Edge activation condition must be set
* @post       Channel actively counts edges and can generate overflow notifications
*/
void Emios_Icu_Ip_EnableEdgeCount(uint8 instance, uint8 hwChannel);

/**
* @brief      Disable edge counting for eMIOS channel
* @details    This function disables edge counter measurement for a specific eMIOS channel.
*             It performs the following operations:
*             - Disables the channel interrupt to stop overflow notifications
*             - Clears any pending interrupt flags
*             - Saves the current counter value before mode change
*             - Puts the channel into GPIO (inactive) mode
*             - Disables MCB (Modulus Counter Buffered) mode
*             - Preserves the last counter value for potential readout
*
* @param[in]  instance     - eMIOS hardware instance number
* @param[in]  hwChannel    - eMIOS hardware channel number
*
* @return void
*
* @pre        Channel must be previously enabled for edge counting
* @post       Edge counting is stopped, last counter value is preserved
*/
void Emios_Icu_Ip_DisableEdgeCount
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Get current edge count for eMIOS channel
* @details    This function returns the current number of edges counted by the eMIOS channel.
*             The returned value represents the total number of edges detected since the
*             counter was last reset or enabled. For channels configured with a maximum
*             count value, the counter will wrap around after reaching the maximum.
*
* @param[in]  instance    - eMIOS hardware instance number
* @param[in]  hwChannel   - eMIOS hardware channel number
*
* @return     eMios_Icu_ValueType - Current edge count value
*
* @pre        Channel must be configured and enabled for edge counting
* @post       Returns current edge count without affecting the counter operation
*/
eMios_Icu_ValueType Emios_Icu_Ip_GetEdgeNumbers
(
    uint8 instance,
    uint8 hwChannel
);

#if (STD_ON == EMIOS_ICU_IP_SET_INITIAL_COUNTER)
/**
* @brief      Set initial counter value for eMIOS edge counting
* @details    This function sets a custom initial value for the edge counter. By default,
*             the counter starts from 0, but this function allows setting a different
*             starting value. This is useful for:
*             - Implementing countdown counters
*             - Setting up specific counting ranges
*             - Synchronizing multiple counters
*             The initial value will be used when the counter is reset or enabled.
*
* @param[in]  instance        - eMIOS hardware instance number
* @param[in]  hwChannel       - eMIOS hardware channel number
* @param[in]  initialCounter  - Initial counter value to be set
*
* @return     void
*
* @pre        This function must be called before Emios_Icu_Ip_EnableEdgeCount
* @pre        Channel must be configured for edge counting mode
* @post       Counter will start from the specified initial value when enabled/reset
* @note       After calling Emios_Icu_Ip_ResetEdgeCount, the counter resets to 0,
*             and the previously set initial value becomes invalid
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
* @brief      Set maximum counter value for eMIOS edge counting
* @details    This function sets a custom maximum value for the edge counter. When the
*             counter reaches this maximum value, it will wrap around to the initial value
*             and can generate an overflow interrupt. This is useful for:
*             - Creating periodic counter behavior
*             - Implementing modulus counting
*             - Setting up counter overflow detection at specific values
*             - Creating custom counting ranges
*
* @param[in]  instance        - eMIOS hardware instance number
* @param[in]  hwChannel       - eMIOS hardware channel number
* @param[in]  maxCounter      - Maximum counter value before wraparound
*
* @return     void
*
* @pre        This function must be called before Emios_Icu_Ip_EnableEdgeCount
* @pre        Channel must be configured for edge counting mode
* @pre        maxCounter should be greater than the initial counter value
* @post       Counter will wrap around at the specified maximum value
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
* @brief      Start signal measurement for eMIOS channel
* @details    This function starts signal measurement service for a specific eMIOS channel.
*             It configures the channel to measure signal characteristics such as period,
*             duty cycle, pulse width, etc. The function performs:
*             - Disables channel interrupt during configuration
*             - Temporarily puts channel into GPIO mode for safe setup
*             - Configures edge activation condition (rising, falling, or both edges)
*             - Sets up the appropriate measurement mode (IPWM, IPM, or SAIC)
*             - Clears any pending interrupt flags
*             - Enables channel interrupt for measurement completion
*             - Initializes measurement state variables and buffers
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return     void
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for signal measurement mode
* @pre        Measurement type and activation edges must be configured
* @post       Channel actively measures signal characteristics and can generate notifications
*/
void Emios_Icu_Ip_StartSignalMeasurement
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief      Stop signal measurement for eMIOS channel
* @details    This function stops signal measurement service for a specific eMIOS channel.
*             It performs the following operations:
*             - Puts the channel into GPIO (inactive) mode to stop measurement
*             - Disables the channel interrupt to stop measurement notifications
*             - Clears any pending interrupt flags
*             - Preserves the last measured values for potential readout
*             - Stops all measurement activities without clearing measured data
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return     void
*
* @pre        Channel must be previously started for signal measurement
* @post       Signal measurement is stopped, last measured values remain available
*/
void Emios_Icu_Ip_StopSignalMeasurement
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief   Get elapsed time measurement for eMIOS channel
* @details This function reads the elapsed time measurement for a channel configured
*          in signal measurement mode. Depending on the channel configuration, it returns:
*          - Signal Low Time: Time between falling edge and consecutive rising edge
*          - Signal High Time: Time between rising edge and consecutive falling edge
*          - Signal Period Time: Time between consecutive rising (or falling) edges
*          The function is reentrant and provides the most recent complete measurement.
*          The time value is expressed in timer ticks and depends on the configured
*          prescaler and system clock frequency.
*
* @param[in]  instance     - eMIOS hardware instance number
* @param[in]  hwChannel    - eMIOS hardware channel number
*
* @return     eMios_Icu_ValueType - Elapsed time in timer ticks for the configured measurement type
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for signal measurement mode
* @pre        Emios_Icu_Ip_StartSignalMeasurement must be called to start measurement
* @post       Returns the most recent complete time measurement
*/
eMios_Icu_ValueType Emios_Icu_Ip_GetTimeElapsed
(
    uint8 instance,
    uint8 hwChannel
);

/**
* @brief   Get duty cycle values for eMIOS channel
* @details This function reads coherent active time and period time measurements for
*          a channel configured in duty cycle measurement mode. It provides both values
*          from the same measurement cycle to ensure coherency. The function:
*          - Reads the active (high) time of the signal
*          - Reads the complete period time of the signal
*          - Ensures both values are from the same measurement cycle
*          - Stores results in the provided dutyCycleValues structure
*          Time values are expressed in timer ticks.
*
* @param[in]     instance         - eMIOS hardware instance number
* @param[in]     hwChannel        - eMIOS hardware channel number
* @param[out]    dutyCycleValues  - Pointer to structure where results will be stored:
*                                   - ActiveTime: Duration of high signal level
*                                   - PeriodTime: Complete signal period duration
*
* @return     void
*
* @pre        Emios_Icu_Ip_Init must be called before
* @pre        Channel must be configured for duty cycle measurement mode
* @pre        Emios_Icu_Ip_StartSignalMeasurement must be called to start measurement
* @pre        dutyCycleValues must point to valid eMios_Icu_Ip_DutyCycleType structure
* @post       dutyCycleValues structure contains coherent active time and period time
*/
void Emios_Icu_Ip_GetDutyCycleValues
(
    uint8 instance,
    uint8 hwChannel,
    eMios_Icu_Ip_DutyCycleType*  dutyCycleValues
);

/**
 * @brief Store pulse width and period values for eMIOS channel
 * @details This function stores the measured pulse width and period values in global
 *          variables for the specified eMIOS channel. This is typically called by
 *          interrupt handlers or DMA completion routines to save measurement results.
 *          The stored values can later be retrieved by other API functions.
 *
 * @param[in] instance         - eMIOS hardware instance number
 * @param[in] hwChannel        - eMIOS hardware channel number
 * @param[in] activePulseWidth - Measured pulse width value in timer ticks
 * @param[in] period           - Measured period value in timer ticks
 *
 * @return    void
 *
 * @pre       Channel must be configured for signal measurement
 * @post      Pulse width and period values are stored in global variables
 */
void Emios_Icu_Ip_SetPWandPeriod(uint8 instance,
                                 uint8 hwChannel,
                                 eMios_Icu_ValueType activePulseWidth,
                                 eMios_Icu_ValueType period);

#endif  /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API */

#if (EMIOS_ICU_IP_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Get input state of eMIOS channel
* @details    This function checks and returns the current input state of an eMIOS channel.
*             It examines the interrupt flag for the channel to determine if an edge or
*             event has been detected since the last check. The function:
*             - Checks if the interrupt flag for the channel is set
*             - If flag is set, clears the interrupt flag and returns true
*             - If flag is not set, returns false
*             This provides a polling mechanism to detect channel activity.
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return       boolean
* @retval       true  - Channel is active (edge/event detected since last check)
* @retval       false - Channel is idle (no edge/event detected)
*
* @pre          Channel must be initialized and configured
* @post         If channel was active, interrupt flag is cleared
*/
boolean Emios_Icu_Ip_GetInputState
(
    uint8 instance,
    uint8 hwChannel
);
#endif  /* EMIOS_ICU_IP_GET_INPUT_STATE_API */

#if (EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      Get current input pin level of eMIOS channel
* @details    This function returns the actual logical level present on the input pin
*             associated with the eMIOS channel. It directly reads the pin state
*             regardless of edge detection configuration or channel mode. This provides
*             an instantaneous reading of the physical pin level.
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return  eMios_Icu_Ip_LevelType - Current pin level
* @retval  EMIOS_ICU_LOW  - Pin is at logical low level (0V or below threshold)
* @retval  EMIOS_ICU_HIGH - Pin is at logical high level (VDD or above threshold)
*
* @pre     Channel must be initialized and pin must be configured as input
* @post    Returns instantaneous pin level without affecting channel operation
*/
eMios_Icu_Ip_LevelType Emios_Icu_Ip_GetInputLevel
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* EMIOS_ICU_IP_GET_INPUT_LEVEL_API == STD_ON */

/**
* @brief      Get overflow status of eMIOS channel
* @details    This function checks and returns the state of the overflow flag for
*             a specific eMIOS channel. Overflow can occur in various scenarios:
*             - Edge counter reaches maximum value and wraps around
*             - Timestamp buffer becomes full
*             - Signal measurement values exceed maximum representable value
*             - Timer counter overflows during measurement
*             The function reads the hardware overflow flag without clearing it.
*
* @param[in]   instance    - eMIOS hardware instance number
* @param[in]   hwChannel   - eMIOS hardware channel number
*
* @return      boolean - Overflow flag state
* @retval      true    - Overflow has occurred since last cleared
* @retval      false   - No overflow detected
*
* @pre         Channel must be initialized
* @post        Returns overflow status without modifying the flag
*/
boolean Emios_Icu_Ip_GetOverflow
(
    uint8 instance,
    uint8 hwChannel
);

#if (EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON)
/**
* @brief      Switch between normal and alternate clock modes
* @details    This function switches the clock source for the entire eMIOS instance
*             between normal and alternate clock modes. This is useful for:
*             - Power management (switching to slower clock to save power)
*             - Dynamic frequency scaling based on system requirements
*             - Adapting measurement resolution based on signal characteristics
*             The function updates prescaler settings for all channels in the instance
*             to maintain consistent timing relationships when possible.
*
* @param[in]   instance       - eMIOS hardware instance number
* @param[in]   peMiosIpConfig - Pointer to eMIOS configuration structure containing
*                              both normal and alternate clock configurations
* @param[in]   Prescaler      - Clock mode selection:
*                              - EMIOS_ICU_NORMAL_CLOCK: Use normal/primary clock source
*                              - EMIOS_ICU_ALTERNATE_CLOCK: Use alternate/secondary clock source
*
* @return      void
*
* @pre         Emios_Icu_Ip_Init must be called with dual clock mode configuration
* @pre         peMiosIpConfig must contain valid configurations for both clock modes
* @post        All channels in the instance use the selected clock source
* @note        Clock switching may temporarily affect ongoing measurements
*/
void Emios_Icu_Ip_SetClockMode
(
    uint8 instance,
    const eMios_Icu_Ip_ConfigType * peMiosIpConfig,
    const eMios_Icu_Ip_ClockModeType Prescaler
);
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_CAPTURERGISTER_API == STD_ON) && ((EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON) || (EMIOS_ICU_IP_TIMESTAMP_API == STD_ON)))
/**
* @brief      Get capture register value for eMIOS channel
* @details    This function returns the current value stored in the capture register
*             (UC A register) of the specified eMIOS channel. The capture register
*             contains the timer counter value that was captured when the last
*             configured event occurred (edge detection, etc.). This provides access
*             to the raw hardware capture value for advanced applications.
*
* @param[in]   instance    - eMIOS hardware instance number
* @param[in]   hwChannel   - eMIOS hardware channel number
*
* @return      uint32 - Current capture register value in timer ticks
*
* @pre         Channel must be configured for signal measurement or timestamp mode
* @pre         At least one capture event must have occurred to get valid data
* @post        Returns raw capture register value without affecting channel operation
*/
uint32 Emios_Icu_Ip_GetCaptureRegValue
(
    uint8 instance,
    uint8 hwChannel
);
#endif  /* EMIOS_ICU_IP_DUAL_CLOCK_MODE_API == STD_ON */

#if ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief      Measure pulse width without using interrupts
* @details    This function performs signal measurement (High time, Low time, and Period)
*             using polling method without relying on channel interrupts. It:
*             - Configures the channel for the appropriate measurement mode
*             - Waits for signal edges using polling
*             - Captures timing values directly from hardware registers
*             - Calculates and stores High time, Low time, and Period values
*             - Provides synchronous measurement operation
*             This is useful when interrupt-based measurement is not desired or available.
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return     void
*
* @pre        Channel must be configured for signal measurement mode
* @pre        Input signal must be present and stable
* @post       Measured values are stored and available via other API functions
* @note       This function blocks until measurement is complete
* @note       Measurement accuracy depends on polling frequency and system load
*/
void Emios_Icu_Ip_GetPulseWidth
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) &&  (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((EMIOS_ICU_IP_VALIDATE_GLOBAL_CALL == STD_ON) && ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) && (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)))
/**
* @brief      Validate channel for non-interrupt signal measurement
* @details    This function validates whether the specified eMIOS channel is properly
*             configured and suitable for non-interrupt based signal measurement.
*             It checks:
*             - Channel initialization status
*             - Channel configuration for signal measurement mode
*             - Hardware availability and readiness
*             - Input signal presence and stability
*             - Compatibility with polling-based measurement
*
* @param[in]  instance   - eMIOS hardware instance number
* @param[in]  hwChannel  - eMIOS hardware channel number
*
* @return     Std_ReturnType
* @retval     E_OK     - Channel is valid and ready for non-interrupt measurement
* @retval     E_NOT_OK - Channel is not suitable for non-interrupt measurement
*
* @pre        Emios_Icu_Ip_Init must be called before
* @post       Returns validation status without affecting channel configuration
*/
Std_ReturnType Emios_Icu_Ip_ValidateSignalMeasureWithoutInterrupt
(
    uint8 instance,
    uint8 hwChannel
);
#endif /* ((EMIOS_ICU_IP_GET_PULSE_WIDTH_API == STD_ON) &&  (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON))*/

/**
* @brief      Enable interrupt for eMIOS channel
* @details    This function enables the interrupt for a specific eMIOS channel and
*             ensures clean interrupt operation by:
*             - Clearing any pending interrupt flags for the channel
*             - Enabling the channel interrupt in the eMIOS hardware
*             - Configuring interrupt priority if applicable
*             - Ensuring interrupt handler is properly registered
*             After calling this function, the channel will generate interrupts
*             when configured events occur.
*
* @param[in]  instance  - eMIOS hardware instance number
* @param[in]  hwChannel - eMIOS hardware channel number
*
* @return     void
*
* @pre        Channel must be initialized and configured for desired operation
* @pre        Interrupt handler must be properly configured in the system
* @post       Channel interrupt is enabled and ready to generate interrupts
*/
void Emios_Icu_Ip_EnableInterrupt(uint8 instance, uint8 hwChannel);

/**
* @brief      Disable interrupt for eMIOS channel
* @details    This function disables the interrupt for a specific eMIOS channel.
*             It performs:
*             - Disables the channel interrupt in the eMIOS hardware
*             - Prevents the channel from generating interrupt requests
*             - Does not clear pending interrupt flags (they remain for polling)
*             - Maintains channel operation in polling mode
*             The channel continues to operate but will not generate interrupts.
*
* @param[in]  instance  - eMIOS hardware instance number
* @param[in]  hwChannel - eMIOS hardware channel number
*
* @return     void
*
* @pre        Channel must be initialized
* @post       Channel interrupt is disabled, channel operates in polling mode
*/
void Emios_Icu_Ip_DisableInterrupt(uint8 instance, uint8 hwChannel);

#if (EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Handle signal measurement interrupt for eMIOS channel
* @details    This function is the interrupt service routine handler for signal measurement
*             operations. It processes different types of signal measurement interrupts:
*             - Duty Cycle measurement: Handles three-edge detection (start, active end, period end)
*             - Period measurement: Calculates time between consecutive same edges
*             - Pulse Width measurement: Measures high or low pulse duration
*             - Overflow handling: Manages counter overflow conditions
*             The function updates global measurement variables and calls notification
*             callbacks when measurements are complete.
*
* @param[in]  instance  - eMIOS hardware instance number
* @param[in]  hwChannel - eMIOS hardware channel number
* @param[in]  bOverflow - Indicates if interrupt was caused by overflow condition:
*                        - true: Interrupt caused by counter overflow
*                        - false: Interrupt caused by normal measurement event
*
* @return     void
*
* @pre        Channel must be configured and started for signal measurement
* @pre        This function should only be called from interrupt context
* @post       Measurement data is updated and notifications are triggered if configured
* @note       This function is typically called by the interrupt dispatcher
*/
void Emios_Icu_Ip_SignalMeasurementHandler(const uint8 instance, const uint8 hwChannel, boolean bOverflow);
#endif /* EMIOS_ICU_IP_SIGNAL_MEASUREMENT_API == STD_ON */


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif  /* EMIOS_ICU_IP_USED */

#if defined(__cplusplus)
}
#endif

/** @} */

#endif  /* EMIOS_ICU_IP_H */
