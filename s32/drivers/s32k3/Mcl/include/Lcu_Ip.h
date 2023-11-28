/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Prevention from multiple including the same header */
#ifndef LCU_IP_DRIVER_H_
#define LCU_IP_DRIVER_H_

/**
*   @file    Lcu_Ip.h
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
#include "Lcu_Ip_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_VENDOR_ID                       43
#define LCU_IP_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_SW_MAJOR_VERSION                3
#define LCU_IP_SW_MINOR_VERSION                0
#define LCU_IP_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Lcu_Ip_Cfg.h file are of the same vendor */
#if (LCU_IP_VENDOR_ID != LCU_IP_CFG_VENDOR_ID)
    #error "Lcu_Ip.h and Lcu_Ip_Cfg.h have different vendor ids"
#endif

/* Check if header file and Lcu_Ip_Cfg.h file are of the same Autosar version */
#if ((LCU_IP_AR_RELEASE_MAJOR_VERSION != LCU_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_AR_RELEASE_MINOR_VERSION != LCU_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (LCU_IP_AR_RELEASE_REVISION_VERSION != LCU_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lcu_Ip.h and Lcu_Ip_Cfg.h are different"
#endif

/* Check if header file and Lcu_Ip_Cfg.h file are of the same Software version */
#if ((LCU_IP_SW_MAJOR_VERSION != LCU_IP_CFG_SW_MAJOR_VERSION) || \
     (LCU_IP_SW_MINOR_VERSION != LCU_IP_CFG_SW_MINOR_VERSION) || \
     (LCU_IP_SW_PATCH_VERSION != LCU_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lcu_Ip.h and Lcu_Ip_Cfg.h are different"
#endif

#if (STD_ON == LCU_IP_IS_AVAILABLE)
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
 * @brief This type contains the LCU Input Param Type.
 * @details The Parameters set specific functionalities for Input
 *
 * */
typedef enum
{
    LCU_IP_INPUT_SET_MUX_SEL            = 0U,   /**< @brief [MUXSEL] Input MUX Select. */
    LCU_IP_INPUT_SET_SW_SYNC_MODE       = 1U,   /**< @brief [SW_MODE] Specifies the software sync mode for the inputs to this LC.When Software Override is enabled (SWEN),these bits control whether Software Override Value (SWVALUE) changes occur immediately or on the rising edge of the selected sync pulse */
    LCU_IP_INPUT_SET_SW_OVERRIDE_EN     = 2U,   /**< @brief [SWEN] Software override input enable */
    LCU_IP_INPUT_SET_SW_VALUE           = 3U    /**< @brief [SWVALUE] Software override input value */
}Lcu_Ip_InputParamType;

/**
 * @brief This type contains the LCU Output Param Type.
 * @details The Parameters set specific functionalities for Output
 *
 * */
typedef enum
{
    LCU_IP_OUTPUT_SET_EN_DEBUG_MODE            =  0U,   /**< @brief [DBGEN] Enables outputs to continue operation in Debug mode */
    LCU_IP_OUTPUT_SET_OUTPUT_ENABLE            =  1U,   /**< @brief [OUTEN] Enables LC outputs */
    LCU_IP_OUTPUT_SET_LUT_CONTROL              =  2U,   /**< @brief [LUTCTRL] LUT control */
    LCU_IP_OUTPUT_SET_LUT_RISE_FILTER          =  3U,   /**< @brief [LUT_RISE_FILT] LUT Rise Filter */
    LCU_IP_OUTPUT_SET_LUT_FALL_FILTER          =  4U,   /**< @brief [LUT_FALL_FILT] LUT Fall Filter */
    LCU_IP_OUTPUT_SET_EN_FORCE_DMA             =  5U,   /**< @brief [LUT_DMA_EN] Enables the generation of a DMA request when an LUT event occurs */
    LCU_IP_OUTPUT_SET_EN_LUT_DMA               =  6U,   /**< @brief [FORCE_DMA_EN] Enables the generation of a DMA request when a force event occurs */
    LCU_IP_OUTPUT_SET_EN_FORCE_INT             =  7U,   /**< @brief [LUT_INT_EN] Enables the generation of an interrupt request when an LUT event */
    LCU_IP_OUTPUT_SET_EN_LUT_INT               =  8U,   /**< @brief [FORCE_INT_EN] Enables the generation of an interrupt request when a force event occurs */
    LCU_IP_OUTPUT_SET_INVERT_OUTPUT            =  9U,   /**< @brief [OUTPOL] Set Output Polarity: invert or not. */
    LCU_IP_OUTPUT_SET_FORCE_SIGNAL_SEL         = 10U,   /**< @brief [FORCE_SENSE] Select Force signal */
    LCU_IP_OUTPUT_SET_CLEAR_FORCE_MODE         = 11U,   /**< @brief [FORCE_MODE] Force Clearing Mode */
    LCU_IP_OUTPUT_SET_FORCE_SYNC_SEL           = 12U,   /**< @brief [SYNC_SEL] The Force Sync Select Parameter specifies which sync input to use for this output */
    LCU_IP_OUTPUT_CLEAR_FORCE_STS              = 13U    /**< @brief [FORCESTS] Clear force event in STS */
}Lcu_Ip_OutputParamType;

/**
 * @brief This type contains the LCU Param Type to get information for input
 * @details The Parameters get specific functionalities for Input
 *
 * */
typedef enum
{
    LCU_IP_INPUT_GET_LOGIC_INPUT_STATE         = 0U,
    LCU_IP_INPUT_GET_SW_OVERRIDE_STATE         = 1U,
}Lcu_Ip_LogicInputInfoParamType;

/**
 * @brief This type contains the LCU Param Type to get information for output
 * @details The Parameters get specific functionalities for Output
 *
 * */
typedef enum
{
    LCU_IP_OUTPUT_GET_LOGIC_OUTPUT_STATE       = 0U,
    LCU_IP_OUTPUT_GET_FORCE_OUTPUT             = 1U,
    LCU_IP_OUTPUT_GET_FORCE_STATUS             = 2U,
    LCU_IP_OUTPUT_GET_LUT_STATUS               = 3U,
    LCU_IP_OUTPUT_GET_COMBINE_FORCE_INPUT      = 4U,
}Lcu_Ip_LogicOutputInfoParamType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief This type contains the Lcu Ip Multiple Inputs and Multiple Value.
 * @details The Lcu Ip Multi Input Value contains a pair composed from Logic Input ID and the Value
 *          of configuration.
 *          The LogicInputId selects a Logic Input
 *          The Value stores the configuration's value.
 * */
typedef struct{
    uint8 LogicInputId;
    uint8 Value;
}Lcu_Ip_SyncInputValueType;

/**
 * @brief This type contains the Lcu Ip Multiple Outputs and Multiple Value.
 * @details The Lcu Ip Multi Output Value contains a pair composed from Logic Output ID and the
 *          Value of configuration.
 *          The LogicOutputId selects a Logic Output
 *          The Value stores the configuration's value.
 * */
typedef struct{
    uint8 LogicOutputId;
    uint16 Value;
}Lcu_Ip_SyncOutputValueType;

/**
 * @brief This type contains the Lcu Ip Input with multiple value
 * @details The Lcu Ip Input with Multiple Value contains a pair composed from Input Parameter and
 *          Value of the Parameter.
 *          The Lcu Ip Input Param Type selects a parameter from the Lcu_Ip_InputParamType enum
 *          The Value stores the configuration's value.
 * */
typedef struct{
    Lcu_Ip_InputParamType Param;
    uint8 Value;
}Lcu_Ip_AsyncInputValueType;

/**
 * @brief This type contains the Lcu Ip Output with multiple value
 * @details The Lcu Ip Output with Multiple Value contains a pair composed from Output Parameter
 *          and Value of the Parameter.
 *          The Lcu Ip Output Param Type selects a parameter from the Lcu_Ip_OutputParamType enum
 *          The Value stores the configuration's value.
 * */
typedef struct{
    Lcu_Ip_OutputParamType Param;
    uint16 Value;
}Lcu_Ip_AsyncOutputValueType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"

/* Initializes the LCU IP Driver */
/**
 * @brief This function initializes the Lcu Ip Driver.
 * @details This service is a non reentrant function that shall initialize the Lcu Ip driver.
 *          When enable multi cores, the API shall write the values into the register only
 *          if the reference partition is same with executing core
 *
 * @param[in]  pxLcuInit         Pointer to the configuration structure.
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and the reference partition is same with executing core.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_Init_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_Init(const Lcu_Ip_InitType * const pxLcuInit);

/**
 * @brief This function De-initializes the Lcu Ip Driver.
 * @details This service is a non reentrant function that shall De-initialize the Lcu Ip driver.
 *          When enable multi cores, the API shall write the values into the register only
 *          if the reference partition is same with executing core
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and the reference partition is same with executing core.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_Deinit_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_Deinit(void);

/**
 * @brief [WP] This function Enable Write Protect feature for the Logic Instance.
 * @details This service is a reentrant function that shall turns on write protection for all LCU
 *          registers except SWVALUE, LCn_STS, and FORCEST.
 *
 * @param[in]  LogicInstance         Specifies the Logic Instance.Using define generated by the
 *                                   configurator (Example : LCU_LOGIC_INSTANCE_0)
 *
 * @return     Lcu_Ip_ReturnType LCU_IP_STATUS_SUCCESS is returned if the write protect was enabled successfully.
 *                               LCU_IP_STATUS_PROTECTED is returned if the write protect was already enable before
 *
 * @implements Lcu_Ip_SetWriteProtect_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetWriteProtect(const uint8 LogicInstance);

/**
 * @brief [WP] This function get Write Protect status for the Logic Instance
 * @details This service is a reentrant function that shall return Write Protect Status.
 *
 * @param[in]  LogicInstance         Specifies the Logic Instance.Using define generated by the
 *                                   configurator (Example : LCU_LOGIC_INSTANCE_0)
 *
 * @return     Lcu_Ip_ReturnType LCU_IP_STATUS_PROTECTED is returned if the write protect was already enabled before.
 *                               LCU_IP_STATUS_SUCCESS is returned if the write protect is disabled. In this case user can call Lcu_Ip_SetWriteProtect to enable Write Protect feature.
 *
 * @implements Lcu_Ip_GetWriteProtect_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetWriteProtect(const uint8 LogicInstance);

#if (STD_ON == LCU_IP_SYNC_FUNC_IS_AVAILABLE)
/* Input configuration */

/**
 * @brief [SWEN] This function Enable/Disable software override of LC input.
 * @details This service is a reentrant function that shall Enable/Disable software override of LC
 *          input. When enable multi cores, the API shall write the values into the register only
 *          if the list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_OVERRIDE_DISABLE/LCU_IP_SW_OVERRIDE_ENABLE
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Input in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncInputSwOverrideEnable_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwOverrideEnable(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SWVALUE] This function specifies the software override value for each LC input.
 * @details This service is a reentrant function that shall specifies the software override value
 *          for each LC input. When enable multi cores, the API shall write the values into the
 *          register only if the list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_OVERRIDE_LOGIC_LOW/LCU_IP_SW_OVERRIDE_LOGIC_HIGH
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Input in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncInputSwOverrideValue_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwOverrideValue(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [MUXSEL] This function selects the source of the LC input.
 * @details This service is a reentrant function that shall selects the source of the LC input
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 255]
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Input in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncInputMuxSelect_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputMuxSelect(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SW_MODE] specifies the software sync mode for the inputs to this LC.
 * @details This service is a reentrant function that shall specifies the software sync mode for
 *          the inputs to this LC.When Software Override is enabled (SWEN), these bits control
 *          whether Software Override Value (SWVALUE) changes occur immediately or on the rising
 *          edge of the selected sync pulse
 *
 *          How to use this interface:
 *          List[x].LogicInputId -> The Logic Input Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_SW_SYNC_IMMEDIATE/LCU_IP_SW_SYNC_ON_RISING_EDGE
 *
 * @param[in]  List         Specifies the input configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Input in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncInputSwSyncMode_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncInputSwSyncMode(const Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/* Output configuration */

/**
 * @brief [DBGEN] This function Enables/Disables outputs to continue operation in Debug mode.
 * @details This service is a reentrant function that shall Enables/Disables outputs to continue
 *          operation in Debug mode. When enable multi cores, the API shall write the values into
 *          the register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DEBUG_DISABLE/LCU_IP_DEBUG_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputDebugMode_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputDebugMode(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [OUTEN] This function Enables/Disables LC outputs.
 * @details This service is a reentrant function that shall Enables/Disables LC outputs. When
 *          enable multi cores, the API shall write the values into the register only if the list
 *          contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_OUTPUT_DISABLE/LCU_IP_OUTPUT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputEnable_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputEnable(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_SENSE] This function specifies which force inputs affect output.
 * @details This service is a reentrant function that shall specifies which force inputs affect
 *          output. When enable multi cores, the API shall write the values into the register only
 *          if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 255]
 *          For each bit:
 *              0b - Does not affect
 *              1b - Affects
.*          Example: 011b specifies: force inputs 0 and 1 will affect for this logic output,
.*          but force inputs 2 will not affect
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputForceInputSensitivity_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceInputSensitivity(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/* [FORCE_MODE] Specifies the timing for clearing force events for output */
/**
 * @brief [FORCE_MODE] This function specifies the timing for clearing force events for output.
 * @details This service is a reentrant function that shall specifies the timing for clearing
 *          force events for output. When enable multi cores, the API shall write the values into
 *          the register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_CLEAR_FORCE_SIGNAL_IMMEDIATE/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_AFTER_CLEAR_STATUS/
 *          LCU_IP_CLEAR_FORCE_SIGNAL_ON_RISING_EDGE_AFTER_CLEAR_STATUS
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputForceClearingMode_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceClearingMode(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [SYNC_SEL] This function specifies which sync input to use for Force signal.
 * @details This service is a reentrant function that shall specifies which sync input to use for
 *          Force signal. When enable multi cores, the API shall write the values into the
 *          register only if the list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value ->  Unsigned Integer: [0, 255]
 *                            00b - Sync input 0
 *                            01b - Sync input 1
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputForceSyncSelect_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceSyncSelect(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [OUTPOL] This function specifies the polarity of the outputs.
 * @details This service is a reentrant function that shall specifies the polarity of the outputs.
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_FORCE_POL_NOT_INVERTED/LCU_IP_FORCE_POL_INVERTED
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputPolarity_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputPolarity(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_DMA_EN] This function Enables/Disable the generation of a DMA request when a
 *          force event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of a
 *          DMA request when a force event occurs. When enable multi cores, the API shall write
 *          the values into the register only if the list contains all the Outputs related to the
 *          same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DMA_DISABLE/LCU_IP_DMA_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputForceDma_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceDma(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCE_INT_EN] This function Enables/Disable the generation of an interrupt request when
 *          force event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of an
 *          interrupt request when force event occurs. When enable multi cores, the API shall
 *          write the values into the register only if the list contains all the Outputs related
 *          to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_INT_DISABLE/LCU_IP_INT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputForceInt_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputForceInt(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_DMA_EN] This function Enables/Disable the generation of a DMA request when a
 *          LUT event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of a
 *          DMA request when a LUT event occurs. When enable multi cores, the API shall write the
 *          values into the register only if the list contains all the Outputs related to the same
 *          partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_DMA_DISABLE/LCU_IP_DMA_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputLutDma_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutDma(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_INT_EN] This function Enables/Disable the generation of an interrupt request when
 *          LUT event occurs.
 * @details This service is a reentrant function that shall Enables/Disable the generation of an
 *          interrupt request when LUT event occurs. When enable multi cores, the API shall write
 *          the values into the register only if the list contains all the Outputs related to the
 *          same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Using define generated by the configurator :
 *          LCU_IP_INT_DISABLE/LCU_IP_INT_ENABLE
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputLutInt_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutInt(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_FALL_FILT] This function specifies the number of consecutive clock cycles the
 *          filter output must be logic 0 before the output signal goes low
 * @details This service is a reentrant function that shall specifies the number of consecutive
 *          clock cycles the filter output must be logic 0 before the output signal goes low
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputFallFilter_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputFallFilter(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUT_RISE_FILT] This function specifies the number of consecutive clock cycles the
 *          filter output must be logic 1 before the output signal goes high
 * @details This service is a reentrant function that shall Specifies the number of consecutive
 *          clock cycles the filter output must be logic 1 before the output signal goes high
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputRiseFilter_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputRiseFilter(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LUTCTRL] This function specifies the LUT positions, based on the combined LC input value
 * @details This service is a reentrant function that shall Specifies the LUT positions, based on
 *          the combined LC input value.
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *          List[x].Value -> Unsigned Integer: [0, 65535]
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetSyncOutputLutControl_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetSyncOutputLutControl(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCESTS] This function Clear Force Event
 * @details This service is a reentrant function that shall Clear Force Event
 *          When enable multi cores, the API shall write the values into the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          List[x].LogicOutputId -> The Logic Output Id generated by the configurator
 *
 * @param[in]  List         Specifies the Output configuration.
 * @param[in]  Dimension    Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_ClearSyncOutputForceEvent_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_ClearSyncOutputForceEvent(const Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [LC_INPUTS] This function Indicates states of LC inputs
 * @details This service is a reentrant function that shall Indicates states of LC inputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicInputId -> The Logic Input Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC inputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncLogicInput_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncLogicInput(Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [SWOUT] This function Indicates states of LC inputs or software-overridden inputs
 * @details This service is a reentrant function that shall Indicates states of LC inputs or
 *          software-overridden inputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Inputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicInputId -> The Logic Input Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC inputs or
 *                                              software-overridden inputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncSwOverrideInput_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncSwOverrideInput(Lcu_Ip_SyncInputValueType List[], const uint8 Dimension);

/**
 * @brief [LCOUT] This function Indicates states of LC outputs
 * @details This service is a reentrant function that shall Indicates states of LC outputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the states of LC outputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncLogicOutput_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncLogicOutput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCEOUT] This function Indicates the current state of force outputs for the logic
 *                   outputs
 * @details This service is a reentrant function that shall the current state of force outputs for
 *          the logic outputs
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the current state of force outputs for the
 *                logic outputs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncForceOutput_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncForceOutput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [FORCESTS] This function Indicates that a force event has occurred on the associated
          output
 * @details This service is a reentrant function that shall Indicates that a force event has
 *          occurred on the associated output
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the force event value.
 *                Value = 0: force event not occurs
 *                Value = 1: force event occurs
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncForceStatus_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncForceStatus(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief [COMB_FORCE] This function Indicates the combined value of force inputs to each output
 * @details This service is a reentrant function that shall Indicates the combined value of force
 *          inputs to each output
 *          When enable multi cores, the API shall get the values from the register only if the
 *          list contains all the Outputs related to the same partition
 *
 *          How to use this interface:
 *          [in] List[x].LogicOutputId -> The Logic Output Id generated by the
 *               configurator
 *          [out] List[x].Value -> Store the combined value of force inputs to each
 *                output
 *
 * @param[in/out]  List    Pointer to the configuration structure
 * @param[in]      Dimension            Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and at least one Output in the List has the incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_GetSyncCombineForceInput_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetSyncCombineForceInput(Lcu_Ip_SyncOutputValueType List[], const uint8 Dimension);
#endif /* #if (STD_ON == LCU_IP_SYNC_FUNC_IS_AVAILABLE) */

#if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE)

/**
 * @brief This function configure multiple configuration for one logic input
 * @details This service is a reentrant function that shall configure multiple configuration for
 *          one logic input
 *
 *          How to use this interface:
 *          List[x].Param -> Select member of Lcu_Ip_InputParamType
 *          List[x].Value -> Unsigned Integer: [0, 255] or some defines generated by configurator
 *                           base on Param
 *
 * @param[in]  LogicInput    Logic input Id
 * @param[in]  List          List of param and value
 * @param[in]  Dimension     Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and the LogicInput incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetAsyncInputList_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetAsyncInputList(const uint8 LogicInput, const Lcu_Ip_AsyncInputValueType List[], const uint8 Dimension);

/**
 * @brief This function configure multiple configuration for one logic output
 * @details This service is a reentrant function that shall configure multiple configuration for
 *          one logic output
 *
 *          How to use this interface:
 *          List[x].Param -> Select member of Lcu_Ip_InputParamType
 *          List[x].Value -> Unsigned Integer: [0, 255] or some defines generated by configurator
 *                           base on Param
 *
 * @param[in]  LogicOutput    Logic output Id
 * @param[in]  List           List of param and value
 * @param[in]  Dimension      Number of entries in the List
 *
 * @return Lcu_Ip_ReturnType LCU_IP_STATUS_WRONG_CORE is returned if enable the multi-cores feature and the LogicInput incorrect partition.
 *                           LCU_IP_STATUS_SUCCESS is returned in the remaining cases
 *
 * @implements Lcu_Ip_SetAsyncOutputList_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_SetAsyncOutputList(const uint8 LogicOutput, const Lcu_Ip_AsyncOutputValueType List[], const uint8 Dimension);

/**
 * @brief This function get information of Logic Input
 * @details This service is a reentrant function that shall get states of Logic Inputs
 *          How to use this interface:
 *          [in] LogicInput -> The Logic Input Name generated by the configurator.
 *                             By default: LCU_LOGIC_INPUT_0, LCU_LOGIC_INPUT_1,...
 *          [in] Param -> Select parameter. Example: LCU_IP_INPUT_GET_LOGIC_INPUT_STATE
 *          [out] Value -> Store the states of LC inputs
 *
 * @param[in]  LogicInput    The Logic Input Name
 * @param[in]  Param         Selection parameter
 * @param[out] Value         Output value
 *
 * @return void
 *
 *
 * @implements Lcu_Ip_GetAsyncLogicInputInfo_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetAsyncLogicInputInfo(const uint8 LogicInput, const Lcu_Ip_LogicInputInfoParamType Param, uint8 * const Value);

/**
 * @brief This function get information of Logic Output
 * @details This service is a reentrant function that shall get states of Logic Outputs
 *          How to use this interface:
 *          [in] LogicOutput -> The Logic Output Name generated by the configurator.
 *                              By default: LCU_LOGIC_OUTPUT_0, LCU_LOGIC_OUTPUT_1,...
 *          [in] Param -> Select parameter. Example: LCU_IP_OUTPUT_GET_LOGIC_OUTPUT_STATE
 *          [out] Value -> Store the states of LC inputs
 *
 * @param[in]  LogicOutput    The Logic Output Name
 * @param[in]  Param          Selection parameter
 * @param[out] Value          Output value
 *
 * @return void
 *
 *
 * @implements Lcu_Ip_GetAsyncLogicOutputInfo_Activity
 * */
Lcu_Ip_ReturnType Lcu_Ip_GetAsyncLogicOutputInfo(const uint8 LogicOutput, const Lcu_Ip_LogicOutputInfoParamType Param, uint8 * const Value);

#endif /* #if (STD_ON == LCU_IP_ASYNC_FUNC_IS_AVAILABLE) */

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* #if (STD_ON == LCU_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef LCU_IP_DRIVER_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
