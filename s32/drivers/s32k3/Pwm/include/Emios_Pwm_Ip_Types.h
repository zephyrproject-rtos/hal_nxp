/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_TYPES_H
#define EMIOS_PWM_IP_TYPES_H

/**
*   @file       Emios_Pwm_Ip_Types.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
#include "Std_Types.h"
#include "Emios_Pwm_Ip_CfgDefines.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_TYPES_VENDOR_ID                    43
#define EMIOS_PWM_IP_TYPES_MODULE_ID                    121
#define EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION             3
#define EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION             0
#define EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip_Types.h and Std_Types.h are different"
    #endif
#endif


/* Check if header file and Emios_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (EMIOS_PWM_IP_TYPES_VENDOR_ID != EMIOS_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_Types.h and Emios_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_Types.h and Emios_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION != EMIOS_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION != EMIOS_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_Types.h and Emios_Pwm_Ip_CfgDefines.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief       Status return codes.
 * @details     Common error codes will be a unified enumeration (C enum) that will contain all error codes
 *              (common and specific). There will be separate "error values spaces" (or slots), each of 256
 *              positions, allocated per functionality.
 */
typedef enum
{
    /* Generic error codes */
    /** @brief Generic operation success status */
    EMIOS_PWM_IP_STATUS_SUCCESS                         = E_OK,
    /** @brief Generic operation failure status */
    EMIOS_PWM_IP_STATUS_ERROR                           = E_NOT_OK,
    /** @brief Generic operation busy status */
    EMIOS_PWM_IP_STATUS_BUSY                            = 0x002U,
    /** @brief Generic operation timeout status */
    EMIOS_PWM_IP_STATUS_TIMEOUT                         = 0x003U,
    /** @brief Generic operation unsupported status */
    EMIOS_PWM_IP_STATUS_UNSUPPORTED                     = 0x004U,

    /* EMIOS specific error codes */
    /** @brief EMIOS unsuccessful attempt selecting wrong mode. */
    EMIOS_PWM_IP_STATUS_WRONG_MODE                = 0xC00U,
    /** @brief EMIOS counter bus overflow. */
    EMIOS_PWM_IP_STATUS_CNT_BUS_OVERFLOW          = 0xC01U,
    /** @brief EMIOS unsuccessful attempt selecting wrong counter bus. */
    EMIOS_PWM_IP_STATUS_WRONG_CNT_BUS             = 0xC02U,
    /** @brief EMIOS must set global allow enter debug mode first. */
    EMIOS_PWM_IP_STATUS_GLOBAL_FREEZE_DISABLED    = 0xC03U,
} Emios_Pwm_Ip_StatusType;

/**
 * @brief       PWM output polarity
 * @details     This enumeration specifies polarity type of Emios
 */
typedef enum
{
    /** @brief Output signal active low */
    EMIOS_PWM_IP_ACTIVE_LOW            = 0x00U,
    /** @brief Output signal active high */
    EMIOS_PWM_IP_ACTIVE_HIGH           = 0x01U
} Emios_Pwm_Ip_PolarityType;

/**
 * @brief       PWM output pin state
 * @details     This enumeration specifies output state of Emios channel pin
 */
typedef enum
{
    /** @brief Output signal low */
    EMIOS_PWM_IP_OUTPUT_STATE_LOW      = 0x00U,
    /** @brief Output signal high */
    EMIOS_PWM_IP_OUTPUT_STATE_HIGH     = 0x01U
} Emios_Pwm_Ip_OutputStateType;

#ifndef EMIOS_PWM_IP_PRESCALER_14BIT
/**
 * @brief       Internal pre-scaler factor selection for the clock source.
 * @details     This enumeration specifies the clock divider value for the internal prescaler of Emios
 */
typedef enum
{
    /** @brief Divide by 1 */
    EMIOS_PWM_IP_CLOCK_DIV_1           = 0x00U,
    /** @brief Divide by 2 */
    EMIOS_PWM_IP_CLOCK_DIV_2           = 0x01U,
    /** @brief Divide by 3 */
    EMIOS_PWM_IP_CLOCK_DIV_3           = 0x02U,
    /** @brief Divide by 4 */
    EMIOS_PWM_IP_CLOCK_DIV_4           = 0x03U,
    /** @brief Divide by 5 */
    EMIOS_PWM_IP_CLOCK_DIV_5           = 0x04U,
    /** @brief Divide by 6 */
    EMIOS_PWM_IP_CLOCK_DIV_6           = 0x05U,
    /** @brief Divide by 7 */
    EMIOS_PWM_IP_CLOCK_DIV_7           = 0x06U,
    /** @brief Divide by 8 */
    EMIOS_PWM_IP_CLOCK_DIV_8           = 0x07U,
    /** @brief Divide by 9 */
    EMIOS_PWM_IP_CLOCK_DIV_9           = 0x08U,
    /** @brief Divide by 10 */
    EMIOS_PWM_IP_CLOCK_DIV_10          = 0x09U,
    /** @brief Divide by 11 */
    EMIOS_PWM_IP_CLOCK_DIV_11          = 0x0AU,
    /** @brief Divide by 12 */
    EMIOS_PWM_IP_CLOCK_DIV_12          = 0x0BU,
    /** @brief Divide by 13 */
    EMIOS_PWM_IP_CLOCK_DIV_13          = 0x0CU,
    /** @brief Divide by 14 */
    EMIOS_PWM_IP_CLOCK_DIV_14          = 0x0DU,
    /** @brief Divide by 15 */
    EMIOS_PWM_IP_CLOCK_DIV_15          = 0x0EU,
    /** @brief Divide by 16 */
    EMIOS_PWM_IP_CLOCK_DIV_16          = 0x0FU,
    /** @brief Prescaler Disabled */
    EMIOS_PWM_IP_CLOCK_NONE            = 0xFFU
} Emios_Pwm_Ip_InternalClkPsType;
#else
typedef uint16 Emios_Pwm_Ip_InternalClkPsType;
#endif
/**
 * @brief       Internal prescaler source
 * @details
 */
typedef enum
{
    EMIOS_PWM_IP_PS_SRC_PRESCALED_CLOCK    = 0x00U,
    EMIOS_PWM_IP_PS_SRC_MODULE_CLOCK       = 0x01U
} Emios_Pwm_Ip_InternalPsSrcType;

/**
 * @brief       Output Disable select
 * @details     Select one of the four output disable input signals
 */
typedef enum
{
    /** @brief Channel output disable source 0 */
    EMIOS_PWM_IP_OUTPUT_DISABLE_0            = 0x00U,
    /** @brief Channel output disable source 1 */
    EMIOS_PWM_IP_OUTPUT_DISABLE_1            = 0x01U,
    /** @brief Channel output disable source 2 */
    EMIOS_PWM_IP_OUTPUT_DISABLE_2            = 0x02U,
    /** @brief Channel output disable source 3 */
    EMIOS_PWM_IP_OUTPUT_DISABLE_3            = 0x03U,
    /** @brief Channel output disable not used */
    EMIOS_PWM_IP_OUTPUT_DISABLE_NONE         = 0xFFU,
} Emios_Pwm_Ip_OutDisableSourceType;

/**
 * @brief       Interrupt types enabled for the channel
 * @details     This enumeration specifies interrupt type of Emios
 */
typedef enum
{
    /** @brief Interrupt/DMA requests are disabled */
    EMIOS_PWM_IP_NOTIFICATION_DISABLED     = 0x00U,
    /** @brief Interrupt requests are generated on FLAGs */
    EMIOS_PWM_IP_INTERRUPT_REQUEST         = 0x01U,
    /** @brief DMA requests are generated on FLAGs */
    EMIOS_PWM_IP_DMA_REQUEST               = 0x02U
} Emios_Pwm_Ip_InterruptType;

/**
 * @brief   Counter bus select.
 * @details Select either one of the counter buses or the internal counter to be used by the Unified Channel.
 */
typedef enum
{
    /** @brief Global counter bus A */
    EMIOS_PWM_IP_BUS_A                   = 0x00U,
    /** @brief Local group counter bus */
    EMIOS_PWM_IP_BUS_BCDE                = 0x01U,
    /** @brief Global counter bus F */
    EMIOS_PWM_IP_BUS_F                   = 0x02U,
    /** @brief Internal counter bus */
    EMIOS_PWM_IP_BUS_INTERNAL            = 0x03U
} Emios_Pwm_Ip_CounterBusSourceType;

/**
* @brief    Supported channel PWM modes
* @details  This enumeration specifies mode type of Emios
*/
typedef enum
{
    /** @brief GPIO (output) */
    EMIOS_PWM_IP_MODE_GPO                          = 0x01U,
    /** @brief Double Action Output Compare.
     *  FLAGs are generated only on B1 matches. */
    EMIOS_PWM_IP_MODE_DAOC_FLAG                    = 0x06U,
    /** @brief Double Action Output Compare.
     *  FLAGs are generated only on A1 & B1 matches. */
    EMIOS_PWM_IP_MODE_DAOC_FLAG_BOTH               = 0x07U,
    /** @brief Center Aligned Output Pulse Width Modulation (with trail edge dead-time).
     *  FLAGs are generated on the trailing edge. */
    EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG       = 0x1CU,
    /** @brief Center Aligned Output Pulse Width Modulation (with trail edge dead-time).
     *  FLAGs are generated on the both edges */
    EMIOS_PWM_IP_MODE_OPWMC_TRAIL_EDGE_FLAG_BOTH  = 0x1EU,
    /** @brief Center Aligned Output Pulse Width Modulation (with lead edge dead-time).
     *  FLAG are generated on the leading edge */
    EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG        = 0x1DU,
    /** @brief Center Aligned Output Pulse Width Modulation (with lead edge dead-time).
     *  FLAG are generated in the both edges */
    EMIOS_PWM_IP_MODE_OPWMC_LEAD_EDGE_FLAG_BOTH   = 0x1FU,
    /** @brief Output Pulse-Width Modulation with Trigger */
    EMIOS_PWM_IP_MODE_OPWMT                        = 0x26U,
    /** @brief Output Pulse Width and Frequency Modulation Buffered.
     *  FLAGs are generated only on B1 matches. */
    EMIOS_PWM_IP_MODE_OPWFMB_FLAG                  = 0x58U,
    /** @brief Output Pulse Width and Frequency Modulation Buffered.
     *  FLAGs are generated on both A1 & B1 matches. */
    EMIOS_PWM_IP_MODE_OPWFMB_FLAG_BOTH             = 0x5AU,
    /** @brief Center Aligned Output Pulse Width Modulation Buffered (with trail edge dead-time).
     *  FLAGs are generated on the trailing edge. */
    EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG       = 0x5CU,
    /** @brief Center Aligned Output Pulse Width Modulation Buffered (with trail edge dead-time).
     *  FLAGs are generated on the both edges */
    EMIOS_PWM_IP_MODE_OPWMCB_TRAIL_EDGE_FLAG_BOTH  = 0x5EU,
    /** @brief Center Aligned Output Pulse Width Modulation Buffered (with lead edge dead-time).
     *  FLAG are generated on the leading edge */
    EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG        = 0x5DU,
    /** @brief Center Aligned Output Pulse Width Modulation Buffered (with lead edge dead-time).
     *  FLAG are generated in the both edges */
    EMIOS_PWM_IP_MODE_OPWMCB_LEAD_EDGE_FLAG_BOTH   = 0x5FU,
    /** @brief Output Pulse Width Modulation Buffered.
     *  FLAGs are generated only on trailing matches */
    EMIOS_PWM_IP_MODE_OPWMB_FLAG                   = 0x60U,
    /** @brief Output Pulse Width Modulation Buffered.
     *  FLAGs are generated on both leading and trailing matches */
    EMIOS_PWM_IP_MODE_OPWMB_FLAG_BOTH              = 0x62U,
    /** @brief Output Pulse Width Modulation (immediate update).
     *  FLAGs are generated only on trailing matches */
    EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG   = 0x20U,
    /** @brief Output Pulse Width Modulation (immediate update).
     *  FLAGs are generated on both leading and trailing matches */
    EMIOS_PWM_IP_MODE_OPWM_IMMEDIATE_UPDATE_FLAG_BOTH  = 0x22U,
    /** @brief Output Pulse Width Modulation (next period update).
     *  FLAGs are generated only on trailing matches */
    EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG  = 0x21U,
    /** @brief Output Pulse Width Modulation (next period update).
     *  FLAGs are generated on both leading and trailing matches */
    EMIOS_PWM_IP_MODE_OPWM_NEXT_PERIOD_UPDATE_FLAG_BOTH  = 0x23U,
    /** @brief Output Pulse Width and Frequency Modulation (immediate update).
     *  FLAGs are generated only on BS1 matches. */
    EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG = 0x18U,
    /** @brief Output Pulse Width and Frequency Modulation (immediate update).
     *  FLAGs are generated on both AS1 & BS1 matches. */
    EMIOS_PWM_IP_MODE_OPWFM_IMMEDIATE_UPDATE_FLAG_BOTH = 0x1AU,
    /** @brief Output Pulse Width and Frequency Modulation (next period update).
     *  FLAGs are generated only on BS1 matches. */
    EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG = 0x19U,
    /** @brief Output Pulse Width and Frequency Modulation (next period update).
     *  FLAGs are generated on both AS1 & BS1 matches. */
    EMIOS_PWM_IP_MODE_OPWFM_NEXT_PERIOD_UPDATE_FLAG_BOTH = 0x1BU,
    /* @brief Undefination mode*/
    EMIOS_PWM_IP_MODE_NODEFINE                     = 0xFFU
} Emios_Pwm_Ip_PwmModeType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (defined (EMIOS_PWM_IP_NOTIFICATION_SUPPORT) && (EMIOS_PWM_IP_NOTIFICATION_SUPPORT == STD_ON))
/**
 * @brief       Notification function callback type.
 */
typedef void (* Emios_Pwm_Ip_CallbackType)(uint8 param);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    Emios_Pwm_Ip_CallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    uint8                           CbParameter;
} Emios_Pwm_Ip_NotificationType;
#else
/**
 * @brief       Notification function callback type.
 */
typedef void (* Emios_Pwm_Ip_CallbackType)(void * Param);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 */
typedef struct
{
    /** @brief Callback function pointer */
    Emios_Pwm_Ip_CallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    void                          * CbParameter;
} Emios_Pwm_Ip_NotificationType;
#endif

/**
* @internal
* @brief     PWM configuration parameters structure
* @details   Emios IP specific channel configuration structure type
*/
typedef struct
{
    /** @brief Emios channel number */
    uint8                               ChannelId;
    /** @brief Sub-mode selected */
    Emios_Pwm_Ip_PwmModeType            Mode;
    /** @brief Counter bus selected, ignore with OPWFM mode */
    Emios_Pwm_Ip_CounterBusSourceType   Timebase;
    /** @brief Debug mode support enable */
    boolean                             DebugMode;
    /** @brief Select source for Output Disable feature */
    Emios_Pwm_Ip_OutDisableSourceType   OutputDisableSource;
    #ifdef EMIOS_PWM_IP_PRESCALER_14BIT
    /** @brief Internal prescaler selection */
    uint16                              InternalPs;
    /** @brief Internal prescaler alternate selection */
    uint16                              InternalPsAlt;
    #else
    /** @brief Internal prescaler selection */
    Emios_Pwm_Ip_InternalClkPsType      InternalPs;
    /** @brief Internal prescaler alternate selection */
    Emios_Pwm_Ip_InternalClkPsType      InternalPsAlt;
    #endif
    /** @brief Internal prescaler source */
    Emios_Pwm_Ip_InternalPsSrcType      InternalPsSrc;
    /** @brief Output active value, Choose active low or high level */
    Emios_Pwm_Ip_PolarityType           OutputPolarity;
    /** @brief Interrupt mode */
    Emios_Pwm_Ip_InterruptType          IrqMode;
    /** @brief Interrupt callback */
    Emios_Pwm_Ip_NotificationType       UserCallback;
#ifdef EMIOS_PWM_IP_TIMER_WIDTH_24BITS
    /** @brief Period count for OPWFM mode only */
    uint32                              PeriodCount;
    /** @brief Duty cycle count */
    uint32                              DutyCycle;
    /** @brief Phase shift of the pwm used in OPWMCB, OPWMT */
    uint32                              PhaseShift;
    /** @brief The dead time value and is compared against the internal counter, for OPWMCB only */
    uint32                              DeadTime;
    /** @brief Trigger Event placement, for OPWMT mode only */
    uint32                              TriggerPosition;
#else
    /** @brief Period count for OPWFM mode only */
    uint16                              PeriodCount;
    /** @brief Duty cycle count */
    uint16                              DutyCycle;
    /** @brief Phase shift of the pwm used in OPWMCB, OPWMT */
    uint16                              PhaseShift;
    /** @brief The dead time value and is compared against the internal counter, for OPWMCB only */
    uint16                              DeadTime;
    /** @brief Trigger Event placement, for OPWMT mode only */
    uint16                              TriggerPosition;
#endif
} Emios_Pwm_Ip_ChannelConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_TYPES_H */
