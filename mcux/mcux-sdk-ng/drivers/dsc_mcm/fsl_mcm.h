/*
 * Copyright 2020 - 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MCM_H_
#define FSL_MCM_H_

#include "fsl_common.h"

/*!
 * @defgroup mcm MCM: Miscellaneous Control Module Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief MCM driver version. */
#define FSL_MCM_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup mcm_driver_log The Driver Change Log
 * @ingroup mcm
 * @{
 * The current MCM driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Improvements
 *      - Supported MC56F82xxx and MC56F84xxx.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup mcm_intro MCM Peripheral and Driver Overview
 * @ingroup mcm
 * @brief Content including 1) peripheral features and work logic; 2) driver design logic
 * @{
 *
 * Peripheral features and how this peripheral works
 * =================================================
 *  The Miscellaneous Control Module provides a myriad of miscellaneous control functions.
 *  Features
 *  --------
 *  + Program-visible information about the configuration and revision of the core and select system peripherals.
 *  + Registers for capturing information about core and core-peripheral bus errors.
 *  + Control and configuration of memory resource protection.
 *
 * How this driver is designed to make this peripheral works
 * ==========================================================
 *  Based on the behavior of the Miscellaneous Control Module, the driver is divided into serval function groups.
 *  + Core Information Interfaces \n
 *      The APIs in this function group can be used to get core information such as datapath width, etc.
 *  + Flash Controller Related Interfaces \n
 *      The APIs in this function group can be used to set flash controller, such as enable/disable data cache.
 *  + Core and Core-peripheral Bus Error Interfaces \n
 *      The APIs in this function group can be used to enable core fault error interrupt and get core fault error.
 *  + Resource Protection Related Inferfaces \n
 *      The APIs in this function can be used to control resource protection related options.
 *
 * @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The enumeration of status flags, including core fault error interrupt flag and core fault error data lost
 * flag.
 */
enum _mcm_status_flags
{
    kMCM_CoreFaultErrorInterruptFlag = MCM_CFISR_CFEI_MASK, /*!< A bus error has occurred. */
#if (defined(FSL_FEATURE_MCM_CFISR_HAS_CFEDL_BIT_FIELD) && FSL_FEATURE_MCM_CFISR_HAS_CFEDL_BIT_FIELD)
    kMCM_CoreFaultErrorDataLostFlag = MCM_CFISR_CFEDL_MASK, /*!< A bus error has occurred before the previous error
                                                            condition was cleared. */
#endif                                                      /* FSL_FEATURE_MCM_CFISR_HAS_CFEDL_BIT_FIELD */
};

/*! @brief The enumeration of datapath width, including 32 bits and 64 bits. */
typedef enum _mcm_datapath_width
{
    kMCM_Datapath32b = 0U, /*!< Datapath width is 32 bits. */
    kMCM_Datapath64b = 1U  /*!< Datapath width is 64 bits. */
} mcm_datapath_width_t;

/*! @brief The enumeration of DMA controller priority in the Crossbar switch arbitration scheme. */
typedef enum _mcm_axbs_dma_core_priority
{
    kMCM_AxbsPriorityCoreHigherThanDMA = 0U, /*!< Fixed-priority arbitration is selected: DSC core has a higher priority
                                                than the DMA Controller's priority. */
    kMCM_AxbsPriorityCoreDMARoundRobin,      /*!< Round-robin priority arbitration is selected: DMA Controller and
                                                DSC core have equal priority. */
} mcm_axbs_dma_core_priority_t;

/*! @brief The enumeration of last faulted core access direction. */
typedef enum _mcm_last_fault_access__dir
{
    kMCM_CoreRead  = 0U, /*!< Core read access. */
    kMCM_CoreWrite = 1U  /*!< Core write access. */
} mcm_last_fault_access_dir_t;

/*! @brief The enumeration of last faulted core access size. */
typedef enum _mcm_last_fault_access_size
{
    kMCM_Access8b  = 0U, /*!< Last faulted core access size is 8-bit. */
    kMCM_Access16b = 1U, /*!< Last faulted core access size is 16-bit. */
    kMCM_Access32b = 2U  /*!< Last faulted core access size is 32-bit. */
} mcm_last_fault_access_size_t;

/*! @brief The enumeration of last faulted core access type. */
typedef enum _mcm_last_fault_access_type
{
    kMCM_AccessInstruction = 0U, /*!< Last faulted core access is instruction. */
    kMCM_AccessData        = 1U  /*!< Last faulted core access is data. */
} mcm_last_fault_access_type_t;

/*! @brief The enumeration of last captured fault Location. */
typedef enum _mcm_last_fault_access_location
{
    kMCM_ErrOnInstructionBus = 0U, /*!< Error occurred on M0 (instruction bus). */
    kMCM_ErrOnOperandABus    = 1U, /*!< Error occurred on M1 (operand A bus). */
    kMCM_ErrOnOperandBBus    = 2U  /*!< Error occurred on M2 (operand B bus). */
} mcm_last_fault_access_location_t;

/*!
 * @brief The structure of core fault attributes, contains access type, access size, access direction, etc.
 */
typedef struct _mcm_core_fault_attribute
{
    mcm_last_fault_access_type_t eType : 1U;     /*!< Indicates the last faulted core access type, please refer to
                                                     @ref mcm_last_fault_access_type_t. */
    uint8_t bitReserved1 : 1U;                   /*!< Reserved 1 bit. */
    bool bBufferable : 1U;                       /*!< Indicates if last faulted core access was bufferable.
                                                     - \b true Last faulted core access is bufferable.
                                                     - \b false Last faulted core access is non-bufferable. */
    uint8_t bitReserved2 : 1U;                   /*!< Reserved 1 bit. */
    mcm_last_fault_access_size_t eSize : 3U;     /*!< Indicates last faulted core access size. */
    mcm_last_fault_access_dir_t eDirection : 1U; /*!< Indicates the last faulted core access direction. */
} mcm_core_fault_attribute_t;

/*!
 * @brief The structure of the resource protection config, the set value can be used only when the resource protection
 * is enabled, and this value can be changed only when the resource protection is disabled.
 */
typedef struct _mcm_resource_protection_config
{
    bool bEnableResourceProtection; /*!< Enable/Disable resource protection.
                                            - \b true Enable Resource protection.
                                            - \b false Disable Resource protection. */
    uint8_t u8FlashBaseAddress;     /*!< Flash base address for user region, supports 4 KB granularity. */
    uint8_t u8RamBaseAddress;       /*!< Program RAM base address for user region, support 256 byte granularity. */
    uint32_t u32BootRomBaseAddress; /*!< Boot ROM base address for user region */
    uint32_t u32ResourceProtectionOtherSP; /*!< Resource protection other stack pointer. */
} mcm_resource_protection_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Core Information Interfaces
 * @{
 */

/*!
 * @brief Indicates if the datapath is 32 or 64 bits wide.
 *
 * @param base MCM base address.
 * @return The device's datapath width, please refer to @ref mcm_datapath_width_t.
 */
static inline mcm_datapath_width_t MCM_GetDataPathWidth(MCM_Type *base)
{
    return ((mcm_datapath_width_t)((base->PLASC & MCM_PLASC_DP64_MASK) >> MCM_PLASC_DP64_SHIFT));
}

/*!
 * @brief Gets crossbar switch (AXBS) slave configuration that indicates the presence/absence of bus slave connections
 * to the device's crossbar switch.
 *
 * @param base MCM base address.
 * @return Crossbar switch (AXBS) slave configuration, each bit in the return value indicates if there is a
 * corresponding connection to the AXBS slave input port. For example if the result is 0x1, it means a bus slave
 * connection to AXBS input port 0 is present.
 */
static inline uint16_t MCM_GetCrossbarSwitchSlaveConfig(MCM_Type *base)
{
    return ((uint16_t)((base->PLASC & MCM_PLASC_ASC_MASK) >> MCM_PLASC_ASC_SHIFT));
}

/*!
 * @brief Gets crossbar switch (AXBS) master configuration that indicates the presence/absence of bus master connections
 * to the device's crossbar switch.
 *
 * @param base MCM base address.
 * @return Crossbar switch (AXBS) master configuration, each bit in the return value indicates if there is a
 * corresponding connection to the AXBS master input port. For example if the result is 0x1, it means a bus master
 * connection to AXBS input port 0 is present.
 */
static inline uint16_t MCM_GetCrossbarSwitchMasterConfig(MCM_Type *base)
{
    return ((uint16_t)((base->PLAMC & MCM_PLAMC_AMC_MASK) >> MCM_PLAMC_AMC_SHIFT));
}

/*! @} */

/*!
 * @name Flash Controller Related Interfaces
 * @{
 */
#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD)
/*!
 * @brief Clears Flash Controller Cache, 1 cycle active.
 *
 * @param base MCM base address.
 */
static inline void MCM_ClearFlashControllerCache(MCM_Type *base)
{
    base->CPCR |= MCM_CPCR_FCCCLR_MASK;
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCDCDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCDCDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables flash controller data caching.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable flash controller data caching.
 *          - \b true Disable flash controller data caching.
 *          - \b false Enable flash controller data caching.
 */
static inline void MCM_DisableFlashControllerDataCaching(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCDCDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCDCDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCDCDIS_BIT_FIELD */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCICDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCICDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables flash controller instruction caching.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable flash contoller instruction caching.
 *          - \b true Disable flash controller instruction caching.
 *          - \b false Enable flash controller instruction caching.
 */
static inline void MCM_DisableFlashControllerInstructionCaching(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCICDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCICDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCICDIS_BIT_FIELD */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCCDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCCDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables flash controller cache.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable flash controller cache.
 *          - \b true Disable flash controller cache.
 *          - \b false Enable flash controller cache.
 */
static inline void MCM_DisableFlashControllerCache(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCCDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCCDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCCDIS_BIT_FIELD */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCDSPDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCDSPDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables flash controller data speculation.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable flash controller data speculation.
 *          - \b true Disable flash controller data speculation.
 *          - \b false Enable flash controller data speculation.
 */
static inline void MCM_DisableFlashControllerDataSpeculation(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCDSPDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCDSPDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCDSPDIS_BIT_FIELD */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCSPDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCSPDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables flash controller speculation.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable flash controller speculation.
 *         - \b true Disable flash controller speculation.
 *         - \b false Enable flash controller speculation.
 */
static inline void MCM_DisableFlashControllerSpeculation(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCSPDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCSPDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCSPDIS_BIT_FIELD */

/*!
 * @brief Disables/Enables the instruction support only by DSP56800EX core, the instructions supported only by the
 * DSP56800EX core are the BPSC and 32-bit multiply and MAC instructions.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable 32-bit multiply and MAC instructions.
 *          - \b true BFSC and 32-bit multiply and MAC instructions disabled.
 *          - \b false BFSC and 32-bit multiply and MAC instructions enabled.
 */
static inline void MCM_DisableDSP56800EXCoreInstructions(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_INSDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_INSDIS_MASK;
    }
}

/*!
 * @brief Disables/Enables core reverse carry.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to enable/disable reverse carry.
 *          - \b true Disable bit-reverse addressing mode.
 *          - \b false Enable bit-reverse addressing mode.
 */
static inline void MCM_DisableCoreReverseCarry(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_RCDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_RCDIS_MASK;
    }
}

/*!
 * @brief Disables/Enables the additional AGU shadow registers on the DSP56800EX core.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to disable/enable the additional AGU shadow register on the DPS core.
 *        - \b true Only the AGU shadow registers supported by the DSP56800E core are enabled.
 *        - \b false The additional AGU shadow registers on the DSP56800EX core are also enabled.
 */
static inline void MCM_DisableDSP56800EXNewShadowRegion(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_SRDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_SRDIS_MASK;
    }
}

/*!
 * @brief Disables/Enables core instruction buffer.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to disable/enable core longword instruction buffer.
 *        - \b true Disable core longword instruction buffer.
 *        - \b false Enable core longword instruction buffer.
 */
static inline void MCM_DisableCoreInstructionBuffer(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_IBDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_IBDIS_MASK;
    }
}

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCSDIS_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCSDIS_BIT_FIELD)
/*!
 * @brief Disables/Enables the flash memory controller's ability to allow flash memory access to initiate when a flash
 * memory command is executing.
 *
 * @param base MCM peripheral base address.
 * @param bDisable Used to disable/enable stall logic.
 *        - \b true Stall logic is disabled. While a flash memory command is executing, an attempted flash memory access
 *                  causes a bus error.
 *        - \b false Stall logic is disabled. While a flash memory command is executing, a flash memory access can occur
 *                   without causing a bus error. The flash memory command completes execution, and then the flash
 *                   memory access occurs.
 */
static inline void MCM_DisableFlashMemoryControllerStall(MCM_Type *base, bool bDisable)
{
    if (bDisable)
    {
        base->CPCR |= MCM_CPCR_FCSDIS_MASK;
    }
    else
    {
        base->CPCR &= ~MCM_CPCR_FCSDIS_MASK;
    }
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCSDIS_BIT_FIELD */

/*! @} */

/*!
 * @name Core and Core-peripheral Bus Error Interfaces
 * @{
 */

#if (defined(FSL_FEATURE_MCM_CPCR_HAS_XBARARB_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_XBARARB_BIT_FIELD)
/*!
 * @brief Sets the priority of the DMA controller in the AXBS crossbar switch arbitration scheme.
 *
 * @param base MCM base address.
 * @param ePriority The selected DMA controller priority in Crossbar switch arbitration scheme, please
 *                  refer to @ref mcm_axbs_dma_core_priority_t.
 */
static inline void MCM_SetAxbsDMAControllerPriority(MCM_Type *base, mcm_axbs_dma_core_priority_t ePriority)
{
#if (defined(FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD) && FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD)
    base->CPCR = ((base->CPCR & (~MCM_CPCR_XBARARB_MASK)) | MCM_CPCR_XBARARB(ePriority)) & (~MCM_CPCR_FCCCLR_MASK);
#else
    base->CPCR = (base->CPCR & (~MCM_CPCR_XBARARB_MASK)) | MCM_CPCR_XBARARB(ePriority);
#endif /* FSL_FEATURE_MCM_CPCR_HAS_FCCCLR_BIT_FIELD */
}
#endif /* FSL_FEATURE_MCM_CPCR_HAS_XBARARB_BIT_FIELD */

/*!
 * @brief Gets the address of the last core access terminated with an error response.
 *
 * @param base MCM base address.
 * @return address of the last core access terminated with an error response.
 */
static inline uint32_t MCM_GetCoreFaultAddr(MCM_Type *base)
{
    return (base->CFADR);
}

/*!
 * @brief Gets the processor's attributes of the last faulted core access to the system bus.
 *
 * @param base MCM peripheral base address.
 * @param psAttribute The pointer of structure @ref mcm_core_fault_attribute_t.
 */
void MCM_GetCoreFaultAttribute(MCM_Type *base, mcm_core_fault_attribute_t *psAttribute);

/*!
 * @brief Gets the location of the last captured fault.
 *
 * @param base MCM peripheral base address.
 * @return The location of the last captured fault, please refer to @ref mcm_last_fault_access_location_t.
 */
static inline mcm_last_fault_access_location_t MCM_GetCoreFaultLocation(MCM_Type *base)
{
    return (mcm_last_fault_access_location_t)((base->CFLOC & (MCM_CFLOC_LOC_MASK)) >> MCM_CFLOC_LOC_SHIFT);
}

/*!
 * @brief Gets the data associated with the last faulted processor write data access from the device's internal bus.
 *
 * @param base MCM base address.
 * @return The data associated with the last faulted processor write data access.
 */
static inline uint32_t MCM_GetCoreFaultData(MCM_Type *base)
{
    return (base->CFDTR);
}

/*!
 * @brief Enables/Disables core fault error interrupt.
 *
 * @param base MCM peripheral base address.
 * @param bEnable Used to enable/disable the core fault error interrupt.
 *          - \b true Enables core fault error interrupt, so an error interrupt will be generated to the interrupt
 * controller on a faulted system bus cycle.
 *          - \b false Disables core fault error interrupt, so an error interrupt will not be generated to the interrupt
 * controller on a faulted system bus cycle.
 */
static inline void MCM_EnableCoreFaultInterrupt(MCM_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CFIER |= MCM_CFIER_ECFEI_MASK;
    }
    else
    {
        base->CFIER &= ~MCM_CFIER_ECFEI_MASK;
    }
}

/*!
 * @brief Gets the core fault error status flags, including core fault error interrupt flag and core fault error data
 * lost flag.
 *
 * @param base MCM peripheral base address.
 * @return The current status flags, should be the OR'ed value of @ref _mcm_status_flags.
 */
static inline uint8_t MCM_GetCoreFaultStatusFlags(MCM_Type *base)
{
    return base->CFISR;
}

/*!
 * @brief Clears the core fault error status flags, including core fault error interrupt flag and core fault error data
 * lost flag.
 *
 * @param base MCM peripheral base address.
 * @param u8StatusFlags The status flags to be cleared, should be the OR'ed value of @ref _mcm_status_flags.
 */
static inline void MCM_ClearCoreFaultStatusFlags(MCM_Type *base, uint8_t u8StatusFlags)
{
    base->CFISR = u8StatusFlags;
}

/*! @} */

/*!
 * @name Resource Protection Related Inferfaces
 * @{
 */

/*!
 * @brief Enables/Disables resource protection.
 *
 * @param base MCM peripheral base address.
 * @param bEnable Used to enable/disable memory resource protection.
 *          - \b true Enable memory resource protection.
 *          - \b false Disable memory resource protection.
 */
static inline void MCM_EnableResourceProtection(MCM_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->RPCR |= MCM_RPCR_RPE_MASK;
    }
    else
    {
        base->RPCR &= ~MCM_RPCR_RPE_MASK;
    }
}

/*!
 * @brief Locks the value of the resource protection related registers, after locked the registers' value can not be
 * changed until a system reset.
 *
 * @param base MCM peripheral base address.
 */
static inline void MCM_LockResourceProtectionRegisters(MCM_Type *base)
{
    base->RPCR |= MCM_RPCR_RL_MASK;
}

/*!
 * @brief Sets the configuration of resource protection, including flash base address, ram base address, etc.
 *
 * @param base MCM peripheral base address.
 * @param psConfig The pointer of structure @ref mcm_resource_protection_config_t.
 * @retval kStatus_Success Succeed to setting resource protection related options.
 * @retval kStatus_Fail    Fail to set resource protection related options.
 */
status_t MCM_SetResourceProtectionConfig(MCM_Type *base, const mcm_resource_protection_config_t *psConfig);

/*!
 * @brief Gets the 21-bit illegal faulting PC that only for a resource protection fault.
 *
 * @param base MCM peripheral base address.
 * @return The resource protection illegal faulting PC.
 */
static inline uint32_t MCM_GetResourceProtectionIllegalFaultPC(MCM_Type *base)
{
    return (base->SRPIPC & MCM_SRPIPC_SRPIFPC_MASK);
}

/*!
 * @brief Indicates whether an resource protection illegal PC fault has occurred.
 *
 * @param base MCM peripheral base address.
 * @retval true The resource protection illegal PC fault has occurred.
 * @retval false The resource protection illegal PC fault has not occurred.
 */
static inline bool MCM_IsResourceProtectionIllegalFaultValid(MCM_Type *base)
{
    return ((base->SRPIPC & MCM_SRPIPC_SRPIFV_MASK) == MCM_SRPIPC_SRPIFV_MASK);
}

/*!
 * @brief Clears the resource protection illegal fault bit.
 *
 * @param base MCM peripheral base address.
 */
static inline void MCM_ClearResourceProtectionIllegalFaultValid(MCM_Type *base)
{
    base->SRPIPC |= MCM_SRPIPC_SRPIFV_MASK;
}

/*!
 * @brief Gets the 21-bit misaligned faulting PC that only for a resource protection fault.
 *
 * @param base MCM peripheral base address.
 * @return The resource protection misaligned faulting PC.
 */
static inline uint32_t MCM_GetResourceProtectionMisalignedFaultPC(MCM_Type *base)
{
    return (base->SRPMPC & MCM_SRPMPC_SRPMFPC_MASK);
}

/*!
 * @brief Indicates whether an resource protection misaligned PC fault has occurred.
 *
 * @param base MCM peripheral base address.
 * @retval true The resource protection misaligned PC fault has occurred.
 * @retval false The resource protection misaligned PC fault has not occurred.
 */
static inline bool MCM_IsResourceProtectionMisalignedFaultValid(MCM_Type *base)
{
    return ((base->SRPMPC & MCM_SRPMPC_SRPMFV_MASK) == MCM_SRPMPC_SRPMFV_MASK);
}

/*!
 * @brief Clears the resource protection misaligned fault bit.
 *
 * @param base MCM peripheral base address.
 */
static inline void MCM_ClearResourceProtectionMisalignedFaultValid(MCM_Type *base)
{
    base->SRPMPC |= MCM_SRPMPC_SRPMFV_MASK;
}

/*! @} */

#if defined(__cplusplus)
}
#endif;

/*! @} */

#endif /* FSL_MCM_H_*/
