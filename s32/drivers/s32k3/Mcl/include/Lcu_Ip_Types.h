/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_TYPES_H_
#define LCU_IP_TYPES_H_

/**
*   @file    Lcu_Ip_Types.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Lcu Ip driver header file.
*   @details
*
*   @addtogroup LCU_IP_DRIVER LCU IP Driver
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
#include "Lcu_Ip_Cfg_Defines.h"

#if (STD_ON == LCU_IP_IS_AVAILABLE)

#include "Lcu_Ip_Regs.h"
#include "Lcu_Ip_Features.h"

#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_TYPES_VENDOR_ID                       43
#define LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_TYPES_SW_MAJOR_VERSION                3
#define LCU_IP_TYPES_SW_MINOR_VERSION                0
#define LCU_IP_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same vendor */
#if (LCU_IP_TYPES_VENDOR_ID != LCU_IP_CFG_DEFINES_VENDOR_ID)
    #error "Lcu_Ip_Types.h and Lcu_Ip_Cfg_Defines.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same Autosar version */
#if ((LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION != LCU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Cfg_Defines.h are different"
#endif

/* Check if header file and Lcu_Ip_Cfg_Defines.h file are of the same Software version */
#if ((LCU_IP_TYPES_SW_MAJOR_VERSION != LCU_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (LCU_IP_TYPES_SW_MINOR_VERSION != LCU_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (LCU_IP_TYPES_SW_PATCH_VERSION != LCU_IP_CFG_DEFINES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Cfg_Defines.h are different"
#endif

#if (STD_ON == LCU_IP_IS_AVAILABLE)

/* Check if header file and Lcu_Ip_Regs.h file are of the same vendor */
#if (LCU_IP_TYPES_VENDOR_ID != LCU_IP_REGS_VENDOR_ID)
    #error "Lcu_Ip_Types.h and Lcu_Ip_Regs.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Regs.h file are of the same Autosar version */
#if ((LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LCU_IP_REGS_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION != LCU_IP_REGS_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION != LCU_IP_REGS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Regs.h are different"
#endif

/* Check if header file and Lcu_Ip_Regs.h file are of the same Software version */
#if ((LCU_IP_TYPES_SW_MAJOR_VERSION != LCU_IP_REGS_SW_MAJOR_VERSION) || \
     (LCU_IP_TYPES_SW_MINOR_VERSION != LCU_IP_REGS_SW_MINOR_VERSION) || \
     (LCU_IP_TYPES_SW_PATCH_VERSION != LCU_IP_REGS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Regs.h are different"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same vendor */
#if (LCU_IP_TYPES_VENDOR_ID != LCU_IP_FEATURES_VENDOR_ID)
    #error "Lcu_Ip_Types.h and Lcu_Ip_Features.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Autosar version */
#if ((LCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_MINOR_VERSION != LCU_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_TYPES_AR_RELEASE_REVISION_VERSION != LCU_IP_FEATURES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Features.h are different"
#endif

/* Check if header file and Lcu_Ip_Features.h file are of the same Software version */
#if ((LCU_IP_TYPES_SW_MAJOR_VERSION != LCU_IP_FEATURES_SW_MAJOR_VERSION) || \
     (LCU_IP_TYPES_SW_MINOR_VERSION != LCU_IP_FEATURES_SW_MINOR_VERSION) || \
     (LCU_IP_TYPES_SW_PATCH_VERSION != LCU_IP_FEATURES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip_Types.h and Lcu_Ip_Features.h are different"
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
 * @brief This type contains the LCU IP Event.
 * @details The Event Type give information for interrupt event is LUT or FORCE.
 *
 * */
typedef enum
{
    LCU_IP_LUT_EVENT        = 0U,
    LCU_IP_FORCE_EVENT      = 1U
}Lcu_Ip_Event;

/**
 * @brief This type contains the LCU IP Return Type.
 * @details The Return Type give information for the execution of interfaces.
 *
 * */
typedef enum{
    LCU_IP_STATUS_SUCCESS      = E_OK,
    LCU_IP_STATUS_ERROR        = E_NOT_OK,
    LCU_IP_STATUS_PROTECTED    = 2U,
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    LCU_IP_STATUS_WRONG_CORE   = 3U,
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
}Lcu_Ip_ReturnType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This type contains the LCU IP Callback interface.
 * @details The Callback is defined by the user and installed by the driver in the corresponding IRQ.
 *
 * @return void
 * */
typedef void(*Lcu_Ip_Callback) (Lcu_Ip_Event Event);

/* LCU Ip Logic Input Identification */
typedef struct{
    uint8 HwInstId;                              /**< @brief LCU hardware instance number. */
    uint8 HwLcInputId;                           /**< @brief This information was created by combine hardware logic cell and hardware input number */
}Lcu_Ip_LogicInputIdType;

/* LCU Ip Logic Output Identification */
typedef struct{
    uint8 HwInstId;                              /**< @brief LCU hardware instance number. */
    uint8 HwLcOutputId;                          /**< @brief This information was created by combine hardware logic cell and hardware output number. */
    Lcu_Ip_Callback IntCallback;                 /**< @brief The channel callback is installed in
                                                      the interrupt and is called automatically
                                                      from the interrupt every time it is triggered.*/
}Lcu_Ip_LogicOutputIdType;

/* LCU IP LC Input Configuration */
typedef struct{
    uint8 MuxSel;                                /**< @brief [MUXSEL] Input MUX Select. */
    boolean SwSynMode;                           /**< @brief [SW_MODE] Specifies the software sync mode for the inputs to this LC.When Software Override is enabled (SWEN),these bits control whether Software Override Value (SWVALUE) changes occur immediately or on the rising edge of the selected sync pulse */
    uint8 SwValue;                               /**< @brief [SWVALUE] Software override input value */
}Lcu_Ip_LogicInputConfigType;

/* LCU IP LC Output Configuration */
typedef struct{
    boolean EnDebugMode;                             /**< @brief [DBGEN] Enables outputs to continue operation in Debug mode */
    uint16 LutControl;                               /**< @brief [LUTCTRL] LUT control */
    uint16 LutRiseFilt;                              /**< @brief [LUT_RISE_FILT] LUT Rise Filter */
    uint16 LutFallFilt;                              /**< @brief [LUT_FALL_FILT] LUT Fall Filter */
    boolean EnLutDma;                                /**< @brief [LUT_DMA_EN] Enables the generation of a DMA request when an LUT event occurs */
    boolean EnForceDma;                              /**< @brief [FORCE_DMA_EN] Enables the generation of a DMA request when a force event occurs */
    boolean EnLutInt;                                /**< @brief [LUT_INT_EN] Enables the generation of an interrupt request when an LUT event */
    boolean EnForceInt;                              /**< @brief [FORCE_INT_EN] Enables the generation of an interrupt request when a force event occurs */
    boolean InvertOutput;                            /**< @brief [OUTPOL] Set Output Polarity: invert or not. */
    uint8 ForceSignalSel;                            /**< @brief [FORCE_SENSE] Select Force signal */
    uint8 ClearForceMode;                            /**< @brief [FORCE_MODE] Force Clearing Mode */
    uint8 ForceSyncSel;                              /**< @brief [SYNC_SEL] The Force Sync Select Parameter specifies which sync input to use for this output */
}Lcu_Ip_LogicOutputConfigType;


/* Logic Input Configuration  */
typedef struct{
    Lcu_Ip_LogicInputIdType xLogicInputId;           /**< @brief The Logic LC ID contains configuration information and identification */
    const Lcu_Ip_LogicInputConfigType * pxLcInputConfig;   /**< @brief The Logic Input configuration */
}Lcu_Ip_LogicInputType;

/* Logic Output Configuration */
typedef struct{
    Lcu_Ip_LogicOutputIdType xLogicOutputId;         /**< @brief The Logic LC ID contains configuration information and identification */
    const Lcu_Ip_LogicOutputConfigType * pxLcOutputConfig; /**< @brief The Logic Cell input configuration for all inputs */
}Lcu_Ip_LogicOutputType;

/* Logic Cell Configuration */
typedef struct{
    uint8 HwLcId;                                /**< @brief LCU hardware Logic cell number. */
    uint8 ForceFilter;                           /**< @brief [FORCE_FILT] Specifies the count, in clock cycles, that a force input must remain at a given logic state before the filtered force input switches state */
    uint8 ForcePolarity;                         /**< @brief [FORCE_POL] Specifies the polarity of the force input */
    uint8 CombEn;                                /**< @brief [COMB_EN] Combinational Force Path (CFP) Enable */
    uint8 SwSyncSel;                             /**< @brief [SW_SYNC_SEL] Selects which sync input to use for software synced mode */
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    uint8 CoreRef;                               /**< @brief Core reference */
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
}Lcu_Ip_LogicCellType;

/* Logic Instance Configuration */
typedef struct{
    uint8 HwInstId;                                                  /**< @brief LCU hardware instance number. */
    uint8 NumLogicCellConfig;                                        /**< @brief Number logic cell configuration */
    const Lcu_Ip_LogicCellType * const * ppxLogicCellConfigArray;    /**< @brief Logic Cell configuration array */
    uint8 OperationMode;                                             /**< @brief LCU operation mode: Interrupt/Polling Mode. */
}Lcu_Ip_LogicInstanceType;

typedef struct{
    Lcu_Ip_Callback Callback;
}Lcu_Ip_HwOutputStateType;

/* LCU initialization */
typedef struct{
    Lcu_Ip_HwOutputStateType ** ppxHwOutputStateArray;
    const Lcu_Ip_LogicInstanceType * const * ppxLogicInstanceConfigArray;
    const Lcu_Ip_LogicOutputConfigType * const pxLogicOutputResetConfigArray;
    const Lcu_Ip_LogicInputConfigType * const pxLogicInputResetConfigArray;
    const Lcu_Ip_LogicOutputType * const * ppxLogicOutputConfigArray;
    const Lcu_Ip_LogicInputType * const * ppxLogicInputConfigArray;
#if (STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE)
    uint8 LcuCoreRef;
#endif /* STD_ON == LCU_IP_MULTICORE_IS_AVAILABLE */
}Lcu_Ip_InitType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* #ifdef LCU_IP_IS_AVAILABLE */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef LCU_IP_TYPES_H_ */
