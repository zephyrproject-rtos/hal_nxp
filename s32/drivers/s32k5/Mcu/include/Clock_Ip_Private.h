/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_IP_PRIVATE_H
#define CLOCK_IP_PRIVATE_H

/**
*   @file    Clock_Ip_Private.h
*   @version    0.8.0
*
*   @brief   CLOCK IP driver private header file.
*   @details CLOCK IP driver private header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Clock_Ip.h"

#if defined(CLOCK_IP_PLATFORM_SPECIFIC1)
    #include "Clock_Ip_Specific1.h"         /* For S32R45 */
#elif defined(CLOCK_IP_PLATFORM_SPECIFIC2)
    #include "Clock_Ip_Specific2.h"         /* For S32G3XX */
#else
    #include "Clock_Ip_Specific.h"          /* For S32G2XX and other platforms */
#endif

#include "Clock_Ip_RegisterProtocol.h"

#ifdef CLOCK_IP_DEV_ERROR_DETECT
#if (STD_ON == CLOCK_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == CLOCK_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef CLOCK_IP_DEV_ERROR_DETECT */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CLOCK_IP_PRIVATE_VENDOR_ID                    43
#define CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION     4
#define CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION     9
#define CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION  0
#define CLOCK_IP_PRIVATE_SW_MAJOR_VERSION             0
#define CLOCK_IP_PRIVATE_SW_MINOR_VERSION             8
#define CLOCK_IP_PRIVATE_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Private.h file and Clock_Ip.h file are of the same Autosar version */
#if ((CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != CLOCK_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Private.h and Clock_Ip.h are different"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip.h file have same versions */
#if (CLOCK_IP_PRIVATE_VENDOR_ID  != CLOCK_IP_VENDOR_ID)
    #error "Clock_Ip_Private.h and Clock_Ip.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip.h file are of the same Software version */
#if ((CLOCK_IP_PRIVATE_SW_MAJOR_VERSION != CLOCK_IP_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_MINOR_VERSION != CLOCK_IP_SW_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_PATCH_VERSION != CLOCK_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Private.h and Clock_Ip.h are different"
#endif

#if defined(CLOCK_IP_PLATFORM_SPECIFIC1)
/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific1.h file are of the same Autosar version */
#if ((CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC1_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC1_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC1_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific1.h are different"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific1.h file have same versions */
#if (CLOCK_IP_PRIVATE_VENDOR_ID  != CLOCK_IP_SPECIFIC1_VENDOR_ID)
    #error "Clock_Ip_Private.h and Clock_Ip_Specific1.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific1.h file are of the same Software version */
#if ((CLOCK_IP_PRIVATE_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC1_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC1_SW_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC1_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific1.h are different"
#endif

#elif defined(CLOCK_IP_PLATFORM_SPECIFIC2)
/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific2.h file are of the same Autosar version */
#if ((CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC2_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC2_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC2_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific2.h are different"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific2.h file have same versions */
#if (CLOCK_IP_PRIVATE_VENDOR_ID  != CLOCK_IP_SPECIFIC2_VENDOR_ID)
    #error "Clock_Ip_Private.h and Clock_Ip_Specific2.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific2.h file are of the same Software version */
#if ((CLOCK_IP_PRIVATE_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC2_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC2_SW_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC2_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific2.h are different"
#endif

#else
/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific.h file are of the same Autosar version */
#if ((CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    != CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION != CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific.h are different"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific.h file have same versions */
#if (CLOCK_IP_PRIVATE_VENDOR_ID  != CLOCK_IP_SPECIFIC_VENDOR_ID)
    #error "Clock_Ip_Private.h and Clock_Ip_Specific.h have different vendor IDs"
#endif

/* Check if Clock_Ip_Private.h file and Clock_Ip_Specific.h file are of the same Software version */
#if ((CLOCK_IP_PRIVATE_SW_MAJOR_VERSION != CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_MINOR_VERSION != CLOCK_IP_SPECIFIC_SW_MINOR_VERSION) || \
     (CLOCK_IP_PRIVATE_SW_PATCH_VERSION != CLOCK_IP_SPECIFIC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Clock_Ip_Private.h and Clock_Ip_Specific.h are different"
#endif

#endif /* #if defined(CLOCK_IP_PLATFORM_SPECIFIC2) */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#ifdef CLOCK_IP_DEV_ERROR_DETECT
#if (STD_ON == CLOCK_IP_DEV_ERROR_DETECT)
/* Check if Clock_Ip_Private.h file and Devassert.h file are of the same Autosar version */
#if ((CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION    != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Clock_Ip_Private.h and Devassert.h are different"
#endif
#endif /* (STD_ON == CLOCK_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef CLOCK_IP_DEV_ERROR_DETECT */
#endif /* #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Total number of clocks */
#define CLOCK_IP_NAMES_NO                    CLOCK_IP_FEATURE_NAMES_NO
/* Total number of producer clocks */
#define CLOCK_IP_PRODUCERS_NO                CLOCK_IP_FEATURE_PRODUCERS_NO

/* Define clock features */
#define CLOCK_LLD_IMPLEMENTATION_INDEX       0U              /* Instance of the module where clock element is implemented. */
#define CLOCK_LLD_TYPE_INDEX              1U              /* Actions to be done for different implementations of a clock element. */
#define CLOCK_LLD_SOURCE_CHANNEL_INDEX             2U
#define CLOCK_LLD_SELECTOR_ENTRY             2U              /* Specific clock feature extension */
#define CLOCK_LLD_DIVIDER_ENTRY            2U              /* Index of power mode for multiplexed clock option */
#define CLOCK_LLD_GATE_INDEX                  3U              /* Gate index */
#define CLOCK_LLD_CMU_INDEX                   3U              /* Cmu index */

#define CLOCK_LLD_MODULE_INSTANCE            2U
#define CLOCK_LLD_SELECTOR_INDEX                  3U
#define CLOCK_LLD_DIVIDER_INDEX                  4U
#define CLOCK_LLD_SELECTOR_SHIFT                  5U
#define CLOCK_LLD_DIVIDER_SHIFT                  6U
#define CLOCK_LLD_SELECTOR_MASK                   7U
#define CLOCK_LLD_DIVIDER_MASK                   8U
#define CLOCK_LLD_HW_ADDRESS                   9U


/* Maximum number of clock features for each clock name */
#define CLOCK_IP_FEATURES_NO           9U

/* Size of the hardware plls array */
#if CLOCK_IP_NUMBER_OF_HARDWARE_PLL > 0U
    #define CLOCK_IP_HARDWARE_PLL_ARRAY_SIZE  CLOCK_IP_NUMBER_OF_HARDWARE_PLL
#else
    #define CLOCK_IP_HARDWARE_PLL_ARRAY_SIZE  1U
#endif

/* Size of the hardware plls array */
#if CLOCK_IP_NUMBER_OF_HARDWARE_DFS > 0U
    #define CLOCK_IP_HARDWARE_DFS_ARRAY_SIZE  CLOCK_IP_NUMBER_OF_HARDWARE_DFS
#else
    #define CLOCK_IP_HARDWARE_DFS_ARRAY_SIZE  1U
#endif

#if (defined(CLOCK_IP_REGISTER_VALUES_COUNT))
#if (CLOCK_IP_REGISTER_VALUES_COUNT > 0)
#define CLOCK_IP_REGISTER_VALUES_OPTIMIZATION (STD_ON)
#else
#define CLOCK_IP_REGISTER_VALUES_OPTIMIZATION (STD_OFF)
#endif
#else
#define CLOCK_IP_REGISTER_VALUES_OPTIMIZATION (STD_OFF)
#endif

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
#define CLOCK_IP_IRCOSC_OBJECT                 (1UL << 0U)
#define CLOCK_IP_XOSC_OBJECT                   (1UL << 1U)
#define CLOCK_IP_PLL_OBJECT                    (1UL << 2U)
#define CLOCK_IP_SELECTOR_OBJECT               (1UL << 3U)
#define CLOCK_IP_DIVIDER_OBJECT                (1UL << 4U)
#define CLOCK_IP_DIVIDER_TRIGGER_OBJECT        (1UL << 5U)
#define CLOCK_IP_FRAC_DIV_OBJECT               (1UL << 6U)
#define CLOCK_IP_EXT_SIG_OBJECT                (1UL << 7U)
#define CLOCK_IP_GATE_OBJECT                   (1UL << 8U)
#define CLOCK_IP_PCFS_OBJECT                   (1UL << 9U)
#define CLOCK_IP_CMU_OBJECT                    (1UL << 10U)
    #endif
#endif /* CLOCK_IP_DEV_ERROR_DETECT */

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
  #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
    #define CLOCK_IP_DEV_ASSERT(x)      DevAssert(x)
  #else
    #define CLOCK_IP_DEV_ASSERT(x)
  #endif
#else
    #define CLOCK_IP_DEV_ASSERT(x)
#endif
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/*! @brief Clock ip source type.
 */
typedef enum
{
    /* Generic error codes */
    UKNOWN_TYPE                                    = 0x00U,    /*!< Clock path from source to this clock name has at least one selector. */
    IRCOSC_TYPE                                    = 0x01U,    /*!< Source is an internal oscillator. */
    XOSC_TYPE                                      = 0x02U,    /*!< Source is an external oscillator. */
    PLL_TYPE                                       = 0x03U,    /*!< Source is a pll. */
    EXT_CLK_TYPE                                   = 0x04U,    /*!< Source is an external clock. */
    SERDES_TYPE                                    = 0x04U,    /*!< Source is a SERDES. */

} Clock_Ip_ClockNameSourceType;

typedef enum
{
    CLOCK_LLD_NO_TYPE                                                  = 0x01U,    /*!< NO_TYPE */
    CLOCK_LLD_XOSC_TYPE                                                = 0x02U,    /*!< XOSC_TYPE */
    CLOCK_LLD_PLL_TYPE                                                 = 0x04U,    /*!< PLL_TYPE */
    CLOCK_LLD_SEL_TYPE                                                 = 0x08U,    /*!< SEL_TYPE */
    CLOCK_LLD_DIV_TYPE                                                 = 0x10U,    /*!< DIV_TYPE */
    CLOCK_LLD_FDIV_TYPE                                                = 0x20U,    /*!< DIV_TYPE */
    CLOCK_LLD_GATE_TYPE                                                = 0x40U,    /*!< GATE_TYPE */
    CLOCK_LLD_CMU_TYPE                                                 = 0x80U,    /*!< CMU_TYPE */

} ClockLLD_ClockType;

/*! @brief Clock xosc status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_XOSC_NOT_ENABLED                         = 0x00U,    /*!< Not enabled */
    CLOCK_LLD_STATUS_XOSC_UNLOCKED                            = 0x01U,    /*!< Unlocked */
    CLOCK_LLD_STATUS_XOSC_LOCKED                              = 0x02U,    /*!< Locked */

} ClockLLD_XoscStatusReturnType;



/*! @brief Clock pll status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_PLL_NOT_ENABLED                         = 0x00U,    /*!< Not enabled */
    CLOCK_LLD_STATUS_PLL_UNLOCKED                            = 0x01U,    /*!< Unlocked */
    CLOCK_LLD_STATUS_PLL_LOCKED                              = 0x02U,    /*!< Locked */

} ClockLLD_PllStatusReturnType;

/*! @brief Clock dfs status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_DFS_NOT_ENABLED                         = 0x00U,    /*!< Not enabled */
    CLOCK_LLD_STATUS_DFS_UNLOCKED                            = 0x01U,    /*!< Unlocked */
    CLOCK_LLD_STATUS_DFS_LOCKED                              = 0x02U,    /*!< Locked */

} ClockLLD_DfsStatusType;

/*! @brief Clock dfs status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_DIV_NOT_ENABLED                         = 0x00U,    /*!< Not enabled */
    CLOCK_LLD_STATUS_DIV_ENABLED                             = 0x01U,    /*!< Enabled */

} ClockLLD_DivStatusType;



/*! @brief Clock dfs status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_SELECTOR_SWITCH_SUCCESS                 = 0x00U,    /*!< Not enabled */
    CLOCK_LLD_STATUS_SELECTOR_SAFE_CLOCK_REQUEST             = 0x01U,    /*!< Unlocked */
    CLOCK_LLD_STATUS_SELECTOR_INACTIVE_TARGET_CLOCK          = 0x02U,    /*!< Locked */

} ClockLLD_SelectorStatusType;


/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_XOSC_MONITOR_TYPE_ID                                   = 0x00U,    /*!< Monitor type id */
    CLOCK_LLD_XOSC_AUTOMATIC_LEVEL_CONTROLLER_ID                     = 0x01U,    /*!< Automatic level controller */
    CLOCK_LLD_XOSC_LEVEL_SHIFTER_CURRENT_ID                          = 0x02U,    /*!< Lever shifter current */
    CLOCK_LLD_XOSC_WAIT_FOR_OSCILLATION_TO_REACH_THRESHOLD_ID        = 0x03U,    /*!< Wait for oscillation */
    CLOCK_LLD_XOSC_PROGRAMMABILITY_COMPARATOR_CURRENT_ID             = 0x04U,    /*!< Programability comparator current */

} ClockLLD_XoscParameterIdentifierType;

/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_XOSC_SINGLE_ENDED_MODE                                   = 0x00U,    /*!< Xosc single ended mode */
    CLOCK_LLD_XOSC_BYPASS_MODE                                         = 0x01U,    /*!< Xosc bypass mode */
    CLOCK_LLD_XOSC_DIFFERENTIAL_MODE                                   = 0x02U,    /*!< Xosc diffirential mode */
    CLOCK_LLD_XOSC_CRYSTAL_MODE                                        = 0x03U,    /*!< Xosc crystal mode */

} ClockLLD_XoscModeType;


/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_PLL_MODULATION_TYPE_ID                                 = 0x00U,    /*!< Automatic level controller */
    CLOCK_LLD_PLL_MODULATION_TYPE_SELECTION_ID                       = 0x01U,    /*!< Lever shifter current */
    CLOCK_LLD_PLL_MODULATION_STEP_SIZE_ID                            = 0x02U,    /*!< Wait for oscillation */
    CLOCK_LLD_PLL_MODULATION_STEP_NO_ID                              = 0x03U,    /*!< Wait for oscillation */
    CLOCK_LLD_PLL_MULTIPHASE_SDM_ID                                  = 0x04U,    /*!< Wait for oscillation */

} ClockLLD_PllParameterIdentifierType;

/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_FDIV_MUL_ID                                            = 0x00U,    /*!< FDIV MUL id */

} ClockLLD_FracDivParameterIdentifierType;

/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_DIVIDER_PHASE_ID                                       = 0x00U,    /*!< Divider phase type id */

} ClockLLD_DividerParameterIdentifierType;


/*! @brief Clock parameter identifier types.
 */
typedef enum
{
    CLOCK_LLD_SELECTOR_PCFS_STEP_DURATION_ID                 = 0x00U,    /*!< Selector progressive clock switch step duration id */

} ClockLLD_SelectorParameterIdentifierType;


/*! @brief Clock lld status return codes.
 */
typedef enum
{
    CLOCK_LLD_STATUS_SUCCESS                                = 0x00U,    /*!< Success status */
    CLOCK_LLD_XOSC_LOCKED_STATUS                            = 0x01U,    /*!< Xosc locked status */
    CLOCK_LLD_XOSC_UNLOCKED_STATUS                          = 0x02U,    /*!< Xosc unlocked status */
    CLOCK_LLD_XOSC_NOT_ENABLED_STATUS                       = 0x03U,    /*!< Xosc unlocked status */
    CLOCK_LLD_PLL_LOCKED_STATUS                            = 0x04U,    /*!< Pll locked status */
    CLOCK_LLD_PLL_UNLOCKED_STATUS                          = 0x05U,    /*!< Pll unlocked status */
    CLOCK_LLD_PLL_NOT_ENABLED_STATUS                       = 0x06U,    /*!< Pll unlocked status */
    CLOCK_LLD_DFS_LOCKED_STATUS                            = 0x07U,    /*!< Pll locked status */
    CLOCK_LLD_DFS_UNLOCKED_STATUS                          = 0x08U,    /*!< Pll unlocked status */
    CLOCK_LLD_DFS_NOT_ENABLED_STATUS                       = 0x09U,    /*!< Pll unlocked status */

} ClockLLD_StatusReturnType;


/*! @brief Clock lld status return codes.
 */
typedef enum
{
    CLOCK_LLD_INTERRUPT_MODE                                = 0x00U,    /*!< Success status */
    CLOCK_LLD_RESET_MODE                                    = 0x01U,    /*!< Xosc locked status */

} ClockLLD_CmuEventReactionType;



/** @brief Clock monitor maximum allowed frequency deviation. */
typedef enum
{
    CLOCK_LLD_MAXIMUM_5_PERCENTAGE_DEVIATION            = 500U,       /**< @brief Maximum 5% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_9_PERCENTAGE_DEVIATION    = 490U,       /**< @brief Maximum 4.9% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_8_PERCENTAGE_DEVIATION    = 480U,       /**< @brief Maximum 4.8% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_7_PERCENTAGE_DEVIATION    = 470U,       /**< @brief Maximum 4.7% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_6_PERCENTAGE_DEVIATION    = 460U,       /**< @brief Maximum 4.6% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_5_PERCENTAGE_DEVIATION    = 450U,       /**< @brief Maximum 4.5% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_4_PERCENTAGE_DEVIATION    = 440U,       /**< @brief Maximum 4.4% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_3_PERCENTAGE_DEVIATION    = 430U,       /**< @brief Maximum 4.3% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_2_PERCENTAGE_DEVIATION    = 420U,       /**< @brief Maximum 4.2% variation. */
    CLOCK_LLD_MAXIMUM_4_POINT_1_PERCENTAGE_DEVIATION    = 410U,       /**< @brief Maximum 4.1% variation. */
    CLOCK_LLD_MAXIMUM_4_PERCENTAGE_DEVIATION            = 400U,       /**< @brief Maximum 4.0% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_9_PERCENTAGE_DEVIATION    = 390U,       /**< @brief Maximum 3.9% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_8_PERCENTAGE_DEVIATION    = 380U,       /**< @brief Maximum 3.8% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_7_PERCENTAGE_DEVIATION    = 370U,       /**< @brief Maximum 3.7% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_6_PERCENTAGE_DEVIATION    = 360U,       /**< @brief Maximum 3.6% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_5_PERCENTAGE_DEVIATION    = 350U,       /**< @brief Maximum 3.5% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_4_PERCENTAGE_DEVIATION    = 340U,       /**< @brief Maximum 3.4% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_3_PERCENTAGE_DEVIATION    = 330U,       /**< @brief Maximum 3.3% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_2_PERCENTAGE_DEVIATION    = 320U,       /**< @brief Maximum 3.2% variation. */
    CLOCK_LLD_MAXIMUM_3_POINT_1_PERCENTAGE_DEVIATION    = 310U,       /**< @brief Maximum 3.1% variation. */
    CLOCK_LLD_MAXIMUM_3_PERCENTAGE_DEVIATION            = 300U,       /**< @brief Maximum 3.0% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_9_PERCENTAGE_DEVIATION    = 290U,       /**< @brief Maximum 2.9% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_8_PERCENTAGE_DEVIATION    = 280U,       /**< @brief Maximum 2.8% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_7_PERCENTAGE_DEVIATION    = 270U,       /**< @brief Maximum 2.7% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_6_PERCENTAGE_DEVIATION    = 260U,       /**< @brief Maximum 2.6% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_5_PERCENTAGE_DEVIATION    = 250U,       /**< @brief Maximum 2.5% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_4_PERCENTAGE_DEVIATION    = 240U,       /**< @brief Maximum 2.4% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_3_PERCENTAGE_DEVIATION    = 230U,       /**< @brief Maximum 2.3% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_2_PERCENTAGE_DEVIATION    = 220U,       /**< @brief Maximum 2.2% variation. */
    CLOCK_LLD_MAXIMUM_2_POINT_1_PERCENTAGE_DEVIATION    = 210U,       /**< @brief Maximum 2.1% variation. */
    CLOCK_LLD_MAXIMUM_2_PERCENTAGE_DEVIATION            = 200U,       /**< @brief Maximum 2.0% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_9_PERCENTAGE_DEVIATION    = 190U,       /**< @brief Maximum 1.9% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_8_PERCENTAGE_DEVIATION    = 180U,       /**< @brief Maximum 1.8% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_7_PERCENTAGE_DEVIATION    = 170U,       /**< @brief Maximum 1.7% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_6_PERCENTAGE_DEVIATION    = 160U,       /**< @brief Maximum 1.6% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_5_PERCENTAGE_DEVIATION    = 150U,       /**< @brief Maximum 1.5% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_4_PERCENTAGE_DEVIATION    = 140U,       /**< @brief Maximum 1.4% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_3_PERCENTAGE_DEVIATION    = 130U,       /**< @brief Maximum 1.3% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_2_PERCENTAGE_DEVIATION    = 120U,       /**< @brief Maximum 1.2% variation. */
    CLOCK_LLD_MAXIMUM_1_POINT_1_PERCENTAGE_DEVIATION    = 110U,       /**< @brief Maximum 1.1% variation. */
    CLOCK_LLD_MAXIMUM_1_PERCENTAGE_DEVIATION            = 100U,       /**< @brief Maximum 1.0% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_9_PERCENTAGE_DEVIATION    = 90U,        /**< @brief Maximum 0.9% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_8_PERCENTAGE_DEVIATION    = 80U,        /**< @brief Maximum 0.8% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_7_PERCENTAGE_DEVIATION    = 70U,        /**< @brief Maximum 0.7% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_6_PERCENTAGE_DEVIATION    = 60U,        /**< @brief Maximum 0.6% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_5_PERCENTAGE_DEVIATION    = 50U,        /**< @brief Maximum 0.5% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_4_PERCENTAGE_DEVIATION    = 40U,        /**< @brief Maximum 0.4% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_3_PERCENTAGE_DEVIATION    = 30U,        /**< @brief Maximum 0.3% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_2_PERCENTAGE_DEVIATION    = 20U,        /**< @brief Maximum 0.2% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_1_PERCENTAGE_DEVIATION    = 10U,        /**< @brief Maximum 0.1% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_09_PERCENTAGE_DEVIATION   = 9U,         /**< @brief Maximum 0.09% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_08_PERCENTAGE_DEVIATION   = 8U,         /**< @brief Maximum 0.08% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_07_PERCENTAGE_DEVIATION   = 7U,         /**< @brief Maximum 0.07% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_06_PERCENTAGE_DEVIATION   = 6U,         /**< @brief Maximum 0.06% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_05_PERCENTAGE_DEVIATION   = 5U,         /**< @brief Maximum 0.05% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_04_PERCENTAGE_DEVIATION   = 4U,         /**< @brief Maximum 0.04% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_03_PERCENTAGE_DEVIATION   = 3U,         /**< @brief Maximum 0.03% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_02_PERCENTAGE_DEVIATION   = 2U,         /**< @brief Maximum 0.02% variation. */
    CLOCK_LLD_MAXIMUM_0_POINT_01_PERCENTAGE_DEVIATION   = 1U,         /**< @brief Maximum 0.01% variation. */

} ClockLLD_CmuDeviationType;

/** @brief Clock ip latency of clock monitor reaction. */
typedef enum
{
    CLOCK_LLD_LOWEST_LATENCY                 = 0U,         /**< @brief Clock monitor is configured to react as fast as possible. A clock failure is detected by clock monitor unit in less than one microsecond. */
    CLOCK_LLD_LOW_LATENCY_1US                = 1U,         /**< @brief Clock monitor reaction is taking 1us. A clock failure is detected by clock monitor unit in one microsecond. */
    CLOCK_LLD_MEDIUM_LATENCY_10US            = 10U,        /**< @brief Clock monitor reaction is taking 10us. A clock failure is detected by clock monitor unit in 10 microseconds. */
    CLOCK_LLD_HIGH_LATENCY_100US             = 100U,       /**< @brief Clock monitor reaction is taking 100us. A clock failure is detected by clock monitor unit in 100 microseconds. */
    CLOCK_LLD_VERY_HIGH_LATENCY_1MS          = 1000U,       /**< @brief Clock monitor reaction is taking 1ms. A clock failure is detected by clock monitor unit in 1 milisecond. */

} ClockLLD_CmuLatencyType;


/*! @brief Clock ip specific commands
 */
typedef enum
{
    CLOCK_IP_RESERVED_COMMAND                              = 0x00U,    /*!< Reserved command */
    CLOCK_IP_INITIALIZE_PLATFORM_COMMAND                   = 0x01U,    /*!< Specific platform objects */
    CLOCK_IP_INITIALIZE_CLOCK_OBJECTS_COMMAND              = 0x02U,    /*!< Initialize clock objects */
    CLOCK_IP_SET_USER_ACCESS_ALLOWED_COMMAND               = 0x03U,    /*!< User access allowed */
    CLOCK_IP_DISABLE_SAFE_CLOCK_COMMAND                    = 0x04U,    /*!< Disable safe clock */

} Clock_Ip_CommandType;


/*! @brief Clock ip hardware selector interface
 */
typedef struct{

    __IO uint32 SetSelectorValue;                    /**< Set selector value. */
    __I  uint32 GetSelectorValue;                    /**< Get selector value. */
    __IO uint32 Dividers[CLOCK_IP_MUX_DIVS_NO];      /**< Dividers */
    __IO uint32 TriggerControl;                      /**< Trigger control */
    __O  uint32 Trigger;                             /**< Trigger */
    __I  uint32 DividerStatus;                       /**< Status of the group dividers. */

}Clock_Ip_HwSelectorType;

/*! @brief Clock ip hardware pcfs interface
 */
typedef struct {

    __IO uint32 DividerChange;                           /**< PCFS Divider Change Register, array offset: 0x4, array step. */
    __IO uint32 DividerEnd;                              /**< PCFS Divider End Register, array offset: 0x8, array step. */
    __IO uint32 DividerStart;                            /**< PCFS Divider Start Register, array offset: 0xC, array step. */

}Clock_Ip_HwPcfsType;

/*! @brief Clock ip clock monitor information
 */
typedef struct{

    Clock_Ip_NameType Name;       /* Name of the clock that can be monitored/supports cmu (clock monitor) */
    Clock_Ip_NameType Reference;  /* Name of the reference clock */
    Clock_Ip_NameType Bus;        /* Name of the bus clock */

    void* CmuInstance;

}Clock_Ip_CmuInfoType;

/*! @brief Clock ip selector divider information
 */
typedef struct
{
    uint8 SelectorParentIndex;
    uint16 DividersChildrenIndexes;
    uint8 Instance;
    uint8 SelIndex;
    uint8 DivIndex;
    uint8 SelShift;
    uint8 DivShift;
    uint32 SelMask;
    uint32 DivMask;
    Clock_Ip_HwSelectorType *Address;
    Clock_Ip_HwPcfsType (*PcfsAddress)[];

}Clock_Ip_SelectorDividerType;

/*! @brief Clock ip gate information
 */
typedef struct
{
    uint8 Instance;
    uint8 Group;
    uint8 GateIndex;
    uint8 Reserved;

}Clock_Ip_GateInfoType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



typedef void (*setNameExtOscImplementation)(Clock_Ip_NameType Name);
typedef void (*resetExtOscImplementation)(void);
typedef void (*setOptionalParameterExtOscImplementation)(ClockLLD_XoscParameterIdentifierType ParamId, uint32 Value);
typedef void (*setExtOscImplementation)(uint32 ExternalOscillatorFrequency, ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
typedef void (*enableExtOscImplementation)(void);
typedef void (*waitExtOscImplementation)(void);
typedef void (*lockExtOscImplementation)(uint32 ExternalOscillatorFrequency, ClockLLD_XoscModeType Mode,uint32 StartupStabilizationTime,uint32 Transconductance);
typedef ClockLLD_StatusReturnType (*getStatusExtOscImplementation)(void);


typedef struct
{
    setNameExtOscImplementation SetName;
    resetExtOscImplementation Reset;
    resetExtOscImplementation Disable;
    setOptionalParameterExtOscImplementation SetOptionalParameter;
    setExtOscImplementation Set;
    enableExtOscImplementation Start;
    enableExtOscImplementation Enable;
    waitExtOscImplementation Wait;
    lockExtOscImplementation Lock;
    getStatusExtOscImplementation GetStatus;
}Clock_Ip_ExtOscCallbackType;


typedef void (*setNameDividerImplementation)(Clock_Ip_NameType DividerName);
typedef void (*resetDividerImplementation)(void);
typedef void (*setOptionalParameterDividerImplementation)(ClockLLD_DividerParameterIdentifierType ParamId, uint32 Value);
typedef void (*setDividerImplementation)(uint32 DividerValue);
typedef ClockLLD_StatusReturnType (*getStatusDividerImplementation)(void);
typedef uint32 (*getDividerValueDividerImplementation)(void);
typedef uint32 (*getMinimumDividerValueDividerImplementation)(void);


typedef struct
{
    setNameDividerImplementation SetName;
    resetDividerImplementation Reset;
    setOptionalParameterDividerImplementation SetOptionalParameter;
    setDividerImplementation Set;
    getStatusDividerImplementation GetStatus;
    getDividerValueDividerImplementation GetDividerValue;
    getMinimumDividerValueDividerImplementation GetMinimumDividerValue;

}Clock_Ip_DividerCallbackType;


typedef void (*setNameFracDivImplementation)(Clock_Ip_NameType Name);
typedef void (*resetFracDivImplementation)(void);
typedef void (*setOptionalParameterFracDivImplementation)(ClockLLD_FracDivParameterIdentifierType ParamId, uint32 Value);
typedef void (*setFracDivImplementation)(float DivisionValue);
typedef void (*enableFracDivImplementation)(void);
typedef void (*waitFracDivImplementation)(void);
typedef void (*lockFracDivImplementation)(float DivisionValue);
typedef ClockLLD_StatusReturnType (*getStatusFracDivImplementation)(void);
typedef struct
{
    setNameFracDivImplementation                       SetName;
    resetFracDivImplementation                         Reset;
    resetFracDivImplementation                         Disable;
    setOptionalParameterFracDivImplementation          SetOptionalParameter;
    setFracDivImplementation                           Set;
    enableFracDivImplementation                        Enable;
    enableFracDivImplementation                        Start;
    waitFracDivImplementation                          Wait;
    lockFracDivImplementation                          Lock;
    getStatusFracDivImplementation                     GetStatus;

}Clock_Ip_FracDivCallbackType;


typedef void (*setNamePllImplementation)(Clock_Ip_NameType Name);
typedef void (*resetPllImplementation)(void);
typedef void (*setOptionalParameterPllImplementation)(ClockLLD_PllParameterIdentifierType ParamId, uint32 Value);
typedef void (*setPllImplementation)(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue);
typedef void (*enablePllImplementation)(void);
typedef void (*waitPllImplementation)(void);
typedef void (*lockPllImplementation)(Clock_Ip_NameType InputReferenceName,uint32 PredividerValue,float MultiplierValue,uint32 PostdividerValue);
typedef ClockLLD_StatusReturnType (*getStatusPllImplementation)(void);
typedef uint32 (*getInputReferencesPllImplementation)(Clock_Ip_NameType (*InputReferences)[]);
typedef uint32 (*getDividerChildrenPllImplementation)(Clock_Ip_NameType (*DividerChildren)[]);
typedef uint32 (*getMaximumPredividerValuePllImplementation)(void);
typedef uint32 (*getMaximumDenominatorValuePllImplementation)(void);
typedef struct
{
    setNamePllImplementation                         SetName;
    resetPllImplementation                           Reset;
    resetPllImplementation                           Disable;
    setOptionalParameterPllImplementation            SetOptionalParameter;
    setPllImplementation                             Set;
    enablePllImplementation                          Start;
    enablePllImplementation                          Enable;
    waitPllImplementation                            Wait;
    lockPllImplementation                            Lock;
    getStatusPllImplementation                       GetStatus;
    getInputReferencesPllImplementation              GetInputReferences;
    getDividerChildrenPllImplementation              GetDividerChildren;
    getMaximumPredividerValuePllImplementation       GetMaximumPredividerValue;
    getMaximumDenominatorValuePllImplementation      GetMaximumDenominatorValue;

}Clock_Ip_PllCallbackType;


typedef void (*setNameSelectorImplementation)(Clock_Ip_NameType SelectorName);
typedef void (*resetSelectorImplementation)(void);
typedef void (*setOptionalParameterSelectorImplementation)(ClockLLD_SelectorParameterIdentifierType ParamId, uint32 Value);
typedef void (*setSelectorImplementation)(Clock_Ip_NameType Source);
typedef void (*waitSelectorImplementation)(void);
typedef void (*switchSelectorImplementation)(Clock_Ip_NameType Source);
typedef uint32 (*getSelectorEntriesSelectorImplementation)(Clock_Ip_NameType (*SelectorEntries)[]);
typedef uint32 (*getDividerChildrenSelectorImplementation)(Clock_Ip_NameType (*DividerChildren)[]);
typedef Clock_Ip_NameType (*getSourceSelectorImplementation)(void);
typedef ClockLLD_StatusReturnType (*getStatusSelectorImplementation)(void);
typedef void (*setSelectorImplementation_Optimized)(Clock_Ip_NameType Source);
typedef void (*waitSelectorImplementation_Optimized)(void);
typedef struct
{
    setNameSelectorImplementation                SetName;
    resetSelectorImplementation                  Reset;
    setOptionalParameterSelectorImplementation   SetOptionalParameter;
    setSelectorImplementation                    Set;
    waitSelectorImplementation                   Wait;
    switchSelectorImplementation                 Switch;
    getSelectorEntriesSelectorImplementation     GetSelectorEntries;
    getDividerChildrenSelectorImplementation     GetDividerChildren;
    getSourceSelectorImplementation              GetSource;
    getStatusSelectorImplementation              GetStatus;
    setSelectorImplementation_Optimized          Set_Optimized;
    waitSelectorImplementation_Optimized         Wait_Optimized;

}Clock_Ip_SelectorCallbackType;

typedef void (*setNameGateImplementation)(Clock_Ip_NameType Name);
typedef void (*resetGateImplementation)(void);
typedef void (*enableGateImplementation)(void);
typedef void (*disableGateImplementation)(void);
typedef void (*waitGateImplementation)(void);
typedef void (*setStateGateImplementation)(uint32 value);
typedef uint32 (*getStateGateImplementation)(void);
typedef ClockLLD_StatusReturnType (*getStatusGateImplementation)(void);
typedef void (*enable_Optimized_GateImplementation)(void);
typedef void (*disable_Optimized_GateImplementation)(void);
typedef void (*wait_Optimized_GateImplementation)(void);

typedef struct
{
    setNameGateImplementation SetName;
    resetGateImplementation Reset;
    enableGateImplementation Enable;
    resetGateImplementation Disable;
    waitGateImplementation Wait;
    setStateGateImplementation SetState;
    getStateGateImplementation GetState;
    getStatusGateImplementation GetStatus;
    enable_Optimized_GateImplementation Enable_Optimized;
    disable_Optimized_GateImplementation Disable_Optimized;
    wait_Optimized_GateImplementation Wait_Optimized;

}Clock_Ip_GateCallbackType;



typedef void (*setNameMonitorImplementation)(Clock_Ip_NameType CmuName);
typedef void (*resetMonitorImplementation)(void);
typedef void (*setMonitorImplementation)(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency);
typedef void (*enableMonitorImplementation)(void);
typedef ClockLLD_StatusReturnType (*getStatusMonitorImplementation)(void);
typedef void (*set_Optimized_MonitorImplementation)(ClockLLD_CmuEventReactionType EventReaction, ClockLLD_CmuDeviationType Deviation, ClockLLD_CmuLatencyType Latency, uint64 MonitoredClockFrequency);
typedef void (*enable_Optimized_MonitorImplementation)(void);
typedef struct
{
    setNameMonitorImplementation                     SetName;
    resetMonitorImplementation                       Reset;
    resetMonitorImplementation                       Disable;
    setMonitorImplementation                         Set;
    enableMonitorImplementation                      Enable;
    enableMonitorImplementation                      Start;
    getStatusMonitorImplementation                   GetStatus;
    set_Optimized_MonitorImplementation              Set_Optimized;
    enable_Optimized_MonitorImplementation           Enable_Optimized;

}Clock_Ip_ClockMonitorCallbackType;



/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* Clock start constant section data */
#define MCU_START_SEC_CONST_8
#include "Mcu_MemMap.h"

extern const uint8 Clock_Ip_au8XoscCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8FractionalDividerCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8PllCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8CmuCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint8 Clock_Ip_au8GateCallbackIndex[CLOCK_IP_ALL_CALLBACKS_COUNT];
extern const uint16 Clock_Ip_au16ClockFeatures[CLOCK_IP_NAMES_NO][CLOCK_IP_FEATURES_NO];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_8
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_16
#include "Mcu_MemMap.h"
/*!
 * @brief Converts a clock name to a selector entry hardware value
 */
extern const uint16 Clock_Ip_au16SelectorEntryHardwareValue[CLOCK_IP_PRODUCERS_NO];
extern const uint16 Clock_Ip_au16SelectorEntryRtcHardwareValue[7U];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_16
#include "Mcu_MemMap.h"

/* Clock start constant section data */
#define MCU_START_SEC_CONST_32
#include "Mcu_MemMap.h"

#if (defined(CLOCK_IP_DEV_ERROR_DETECT))
    #if (CLOCK_IP_DEV_ERROR_DETECT == STD_ON)
extern const uint32 Clock_Ip_au8ClockNameTypes[CLOCK_IP_NAMES_NO];
    #endif
#endif

extern volatile uint32* const Clock_Ip_SwitchDuration[8U];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_32
#include "Mcu_MemMap.h"




/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

extern const Clock_Ip_ExtOscCallbackType Clock_Ip_axExtOscCallbacks[CLOCK_IP_XOSC_CALLBACKS_COUNT];

extern const Clock_Ip_DividerCallbackType Clock_Ip_axDividerCallbacks[CLOCK_IP_DIVIDER_CALLBACKS_COUNT];

extern const Clock_Ip_FracDivCallbackType Clock_Ip_axFracDivCallbacks[CLOCK_IP_FRACTIONAL_DIVIDER_CALLBACKS_COUNT];

extern const Clock_Ip_PllCallbackType Clock_Ip_axPllCallbacks[CLOCK_IP_PLL_CALLBACKS_COUNT];

extern const Clock_Ip_NameType Clock_Ip_aeHwPllName[CLOCK_IP_HARDWARE_PLL_ARRAY_SIZE];
extern const Clock_Ip_NameType Clock_Ip_aeHwDfsName[CLOCK_IP_HARDWARE_DFS_ARRAY_SIZE];

extern const Clock_Ip_SelectorCallbackType Clock_Ip_axSelectorCallbacks[CLOCK_IP_SELECTOR_CALLBACKS_COUNT];

extern const Clock_Ip_ClockMonitorCallbackType Clock_Ip_axCmuCallbacks[CLOCK_IP_CMU_CALLBACKS_COUNT];

extern const Clock_Ip_GateCallbackType Clock_Ip_axGateCallbacks[CLOCK_IP_GATE_CALLBACKS_COUNT];

extern const Clock_Ip_ClockNameSourceType Clock_Ip_aeSourceTypeClockName[CLOCK_IP_PRODUCERS_NO];

extern const Clock_Ip_SelectorDividerType Clock_Ip_axSelectorsDividersTable[CLOCK_IP_SELECTOR_DIVIDER_TABLE_SIZE];

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

extern const Clock_Ip_ClockConfigType *Clock_Ip_pxConfig;

#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

#if CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 0U

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"

extern uint8 Clock_Ip_FreqIds[CLOCK_IP_FEATURE_NAMES_NO];

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_8
#include "Mcu_MemMap.h"

#endif /* CLOCK_IP_CONFIGURED_FREQUENCIES_COUNT > 0U */
/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef CLOCK_IP_POWER_NOTIFICATIONS
#if (CLOCK_IP_POWER_NOTIFICATIONS == STD_ON)
void Clock_Ip_ClockPowerNotifications(Clock_Ip_PowerModesType PowerMode,
                                    Clock_Ip_PowerNotificationType Notification);
#endif
#endif
void Clock_Ip_ReportClockErrors(Clock_Ip_NotificationType Error,
                                Clock_Ip_NameType ClockName);
void Clock_Ip_SetExternalSignalFrequency(Clock_Ip_NameType SignalName,
                                         uint64 Frequency);
#if (defined(CLOCK_IP_GET_FREQUENCY_API) && (CLOCK_IP_GET_FREQUENCY_API == STD_ON))
uint64 Clock_Ip_GetFreq(Clock_Ip_NameType ClockName);
void Clock_Ip_SetExternalOscillatorFrequency(Clock_Ip_NameType ExtOscName,
                                             uint64 Frequency);
#endif
#if CLOCK_IP_CMU_INFO_SIZE > 0U
void Clock_Ip_CMU_ClockFailInt(void);
#endif
#if defined(CLOCK_IP_CGU_INTERRUPT)
void Clock_Ip_CGU_ClockDetectInt(void);
#endif
#ifdef CLOCK_IP_HAS_RAM_WAIT_STATES
    void Clock_Ip_SetRamWaitStates(void);
#endif
#ifdef CLOCK_IP_HAS_FLASH_WAIT_STATES
    void Clock_Ip_SetFlashWaitStates(void);
#endif
#if (defined(CLOCK_IP_REGISTER_VALUES_OPTIMIZATION) && (CLOCK_IP_REGISTER_VALUES_OPTIMIZATION == STD_ON))
void Clock_Ip_WriteRegisterValues(const Clock_Ip_RegisterIndexType *Indexes);
#endif
void Clock_Ip_Command(Clock_Ip_ClockConfigType const * Config,
                    Clock_Ip_CommandType Command);
/*!
 * @brief Initializes a starting reference point for timeout
 *
 * @param[out] StartTimeOut    The starting time from which elapsed time is measured
 * @param[out] ElapsedTimeOut  The elapsed time to be passed to Clock_Ip_TimeoutExpired
 * @param[out] TimeoutTicksOut The timeout value (in ticks) to be passed to Clock_Ip_TimeoutExpired
 * @param[in]  TimeoutUs       The timeout value (in microseconds)
 */
void Clock_Ip_StartTimeout(uint32 *StartTimeOut,
                       uint32 *ElapsedTimeOut,
                       uint32 *TimeoutTicksOut,
                       uint32 TimeoutUs);
/*!
 * @brief Checks for timeout condition.
 *
 * @param[in,out] StartTimeInOut    The starting time from which elapsed time is measured
 * @param[in,out] ElapsedTimeInOut  The accumulated elapsed time from the starting time reference
 * @param[in]     TimeoutTicks      The timeout limit (in ticks)
 */
boolean Clock_Ip_TimeoutExpired(uint32 *StartTimeInOut,
                            uint32 *ElapsedTimeInOut,
                            uint32 TimeoutTicks);


static inline const Clock_Ip_ExtOscCallbackType* ClockLLD_Xoscs(Clock_Ip_NameType xoscName)
{
    const Clock_Ip_ExtOscCallbackType *returnValue = &Clock_Ip_axExtOscCallbacks[Clock_Ip_au8XoscCallbackIndex[Clock_Ip_au16ClockFeatures[xoscName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(xoscName);
    return returnValue;
}

static inline const Clock_Ip_DividerCallbackType* ClockLLD_Dividers(Clock_Ip_NameType dividerName)
{
    const Clock_Ip_DividerCallbackType *returnValue = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[Clock_Ip_au16ClockFeatures[dividerName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(dividerName);
    return returnValue;
}

static inline const Clock_Ip_FracDivCallbackType* ClockLLD_FracDividers(Clock_Ip_NameType fracDividerName)
{
    const Clock_Ip_FracDivCallbackType *returnValue = &Clock_Ip_axFracDivCallbacks[Clock_Ip_au8FractionalDividerCallbackIndex[Clock_Ip_au16ClockFeatures[fracDividerName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(fracDividerName);
    return returnValue;
}

static inline const Clock_Ip_PllCallbackType* ClockLLD_Plls(Clock_Ip_NameType pllName)
{
    const Clock_Ip_PllCallbackType *returnValue = &Clock_Ip_axPllCallbacks[Clock_Ip_au8PllCallbackIndex[Clock_Ip_au16ClockFeatures[pllName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(pllName);
    return returnValue;
}

static inline const Clock_Ip_SelectorCallbackType* ClockLLD_Selectors(Clock_Ip_NameType selectorName)
{
    const Clock_Ip_SelectorCallbackType *returnValue = &Clock_Ip_axSelectorCallbacks[Clock_Ip_au8SelectorCallbackIndex[Clock_Ip_au16ClockFeatures[selectorName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(selectorName);
    return returnValue;
}

static inline const Clock_Ip_GateCallbackType* ClockLLD_Gates(Clock_Ip_NameType gateName)
{
    const Clock_Ip_GateCallbackType *returnValue = &Clock_Ip_axGateCallbacks[Clock_Ip_au8GateCallbackIndex[Clock_Ip_au16ClockFeatures[gateName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(gateName);
    return returnValue;
}

static inline const Clock_Ip_ClockMonitorCallbackType* ClockLLD_Monitors(Clock_Ip_NameType monitoredClockName)
{
    const Clock_Ip_ClockMonitorCallbackType *returnValue = &Clock_Ip_axCmuCallbacks[Clock_Ip_au8CmuCallbackIndex[Clock_Ip_au16ClockFeatures[monitoredClockName][CLOCK_LLD_IMPLEMENTATION_INDEX]]];
    returnValue->SetName(monitoredClockName);
    return returnValue;
}


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_PRIVATE_H */

