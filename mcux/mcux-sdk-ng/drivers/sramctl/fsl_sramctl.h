/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SRAMCTL_H_
#define FSL_SRAMCTL_H_

#include "fsl_common.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @addtogroup sramctl
 * @{
 */

/*! @name Driver version
 * @{
 */
/*! @brief SRAMCTL driver version. */
#define FSL_SRAMCTL_DRIVER_VERSION (MAKE_VERSION(3, 0, 0))
/*! @} */

/*! @brief Determines whether RAMIAS/RAMIAE are system or local addresses. */
typedef enum
{
    kSRAMCTL_AddressTypeLocal  = 0U, /*!< Local address. */
    kSRAMCTL_AddressTypeSystem = 1U, /*!< System address. */
} sramctl_address_type_t;

/*! @brief Specifies the number of wait cycles between memory writes during initialization. */
typedef enum
{
    kSRAMCTL_ZeroWaitCycle   = 0U, /*!< 0 wait cycles. */
    kSRAMCTL_OneWaitCycle    = 1U, /*!< 1 wait cycle. */
    kSRAMCTL_TwoWaitCycles   = 2U, /*!< 2 wait cycles. */
    kSRAMCTL_ThreeWaitCycles = 3U, /*!< 3 wait cycles. */
} sramctl_initialization_wait_states_t;

/*! @brief SRAMCTL status flags (RAMSR bits). */
typedef enum
{
    kSRAMCTL_InitializationDone    = (1UL << 0),  /*!< IDONE (W1C). */
    kSRAMCTL_BusError              = (1UL << 1),  /*!< BUSERR (W1C). */
    kSRAMCTL_InitializationPending = (1UL << 2),  /*!< IPEND (RO). */
    kSRAMCTL_AddressValid          = (1UL << 3),  /*!< AVALID (W1C). */
    kSRAMCTL_EccAddressError       = (1UL << 5),  /*!< AERR (W1C). */
    kSRAMCTL_EccMultiBitError      = (1UL << 6),  /*!< MLTERR (W1C). */
    kSRAMCTL_EccSingleBitError     = (1UL << 7),  /*!< SGLERR (W1C, captures latest). */
    kSRAMCTL_SecureRegion          = (1UL << 24), /*!< SEC (RO). */

    /*! @brief All W1C bits that software is allowed to clear. */
    kSRAMCTL_AllW1CFlags = kSRAMCTL_InitializationDone | kSRAMCTL_BusError | kSRAMCTL_AddressValid | kSRAMCTL_EccAddressError |
                           kSRAMCTL_EccMultiBitError | kSRAMCTL_EccSingleBitError,

    /*! @brief All RAMSR bits (including RO bits). */
    kSRAMCTL_AllFlags = kSRAMCTL_AllW1CFlags | kSRAMCTL_InitializationPending | kSRAMCTL_SecureRegion,
} sramctl_status_flags_t;

/*! @brief SRAMCTL configuration structure. */
typedef struct
{
    sramctl_address_type_t addressType; /*!< Address type for RAMIAS/RAMIAE. See @ref sramctl_address_type_t. */
    sramctl_initialization_wait_states_t initializationWaitStates; /*!< Initialization wait states. */
    uint32_t addressStart; /*!< RAM Initialization Address Start (RAMIAS). */
    uint32_t addressEnd;   /*!< RAM Initialization Address End (RAMIAE). */
} sramctl_config_t;

/*! @brief SRAMCTL error information structure. */
typedef struct
{
    uint8_t eccSyndromeValue;         /*!< Syndrome value (RAMSR[SYND]). */
    uint8_t ramStatusEventInfo;       /*!< Event info (RAMSR[EINFO]). */
    uint8_t ramCorrectableErrorCount; /*!< Correctable error count (RAMECCNT[ECCNT]). */
    uint16_t ramEccAddressBankId;     /*!< Bank ID (RAMMEMA[BANK]). */
    uint32_t ramEccAddressBankAddress; /*!< Bank address (RAMMEMA[MEMA]). */
    uint32_t ramSystemAddress;        /*!< System address (RAMSYSA). */
} sramctl_error_info_t;

/*! @brief SRAMCTL error injection address configuration structure. */
typedef struct
{
    bool ramErrorInjectionAddressEnable; /*!< true: enable address filtering using base/mask. */
    uint32_t ramErrorInjectionBaseAddress; /*!< Base address (RAMEIA). */
    uint32_t ramErrorInjectionAddressMask; /*!< Address mask (RAMEIAM). */
} sramctl_error_injection_address_t;

/*! @brief SRAMCTL error injection data configuration structure. */
typedef struct
{
    bool ramErrorInjectionDataEnable; /*!< true: enable data injection driven by local registers. */
    uint8_t ramErrorInjectionDataCheckbits; /*!< Checkbits mask (RAMEIDC[EID_CKB]). */
    uint32_t ramErrorInjectionData0; /*!< Lower word mask (RAMEID0). */
    uint32_t ramErrorInjectionData1; /*!< Upper word mask (RAMEID1). */
} sramctl_error_injection_data_t;


/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Initialize SRAM for the configured address range.
 *
 * @param base SRAMCTL peripheral base address.
 * @param config Pointer to the configuration structure.
 * @retval kStatus_Success Initialization completed.
 * @retval kStatus_InvalidArgument Invalid argument.
 */
status_t SRAMCTL_Init(SRAMCTL_Type *base, sramctl_config_t const *config);

/*!
 * @brief Set the maximum valid address for SRAM access.
 *
 * @param base SRAMCTL peripheral base address.
 * @param address Maximum address value.
 */
void SRAMCTL_SetRamMaximumAddress(SRAMCTL_Type *base, uint32_t address);

/*!
 * @brief Enable or disable the exclusive monitor.
 *
 * @param base SRAMCTL peripheral base address.
 * @param enable true to enable exclusive monitor; false to disable it.
 */
void SRAMCTL_EnableExclusiveMonitor(SRAMCTL_Type *base, bool enable);

/*!
 * @brief Get SRAMCTL status flags.
 *
 * @param base SRAMCTL peripheral base address.
 * @return Status flags. This is a logical OR of @ref sramctl_status_flags_t.
 */
static inline uint32_t SRAMCTL_GetStatusFlags(SRAMCTL_Type *base)
{
    return base->RAMSR;
}

/*!
 * @brief Clear SRAMCTL status flags.
 *
 * This function clears W1C flags in RAMSR.
 *
 * @param base SRAMCTL peripheral base address.
 * @param mask Mask of flags to clear. This is a logical OR of @ref sramctl_status_flags_t.
 *             Only W1C flags are allowed; RO flags (such as IPEND/SEC) are rejected.
 * @retval kStatus_Success Clear completed.
 * @retval kStatus_InvalidArgument Mask contains RO flags.
 */
status_t SRAMCTL_ClearStatusFlags(SRAMCTL_Type *base, uint32_t mask);

/*!
 * @brief Get SRAMCTL error information.
 *
 * @param base SRAMCTL peripheral base address.
 * @param info Pointer to the error information structure.
 */
void SRAMCTL_GetErrorInfo(SRAMCTL_Type *base, sramctl_error_info_t *info);

/*!
 * @brief Configure address filtering for error injection.
 *
 * @param base SRAMCTL peripheral base address.
 * @param config Pointer to address injection configuration.
 */
void SRAMCTL_ConfigErrorInjectionAddress(SRAMCTL_Type *base, const sramctl_error_injection_address_t *config);

/*!
 * @brief Configure data masks for error injection.
 *
 * @param base SRAMCTL peripheral base address.
 * @param config Pointer to data injection configuration.
 */
void SRAMCTL_ConfigErrorInjectionData(SRAMCTL_Type *base, const sramctl_error_injection_data_t *config);

/*!
 * @brief Enable or disable error injection into the pipeline to cause a safety alarm.
 *
 * @param base SRAMCTL peripheral base address.
 * @param enable true to enable; false to disable.
 */
void SRAMCTL_EnableErrorInjectionForSafetyAlarm(SRAMCTL_Type *base, bool enable);

/*!
 * @brief Initialize memory range by instance index.
 *
 * @param base SRAMCTL peripheral base address.
 * @param start_addr Start address.
 * @param end_addr End address.
 *
 * @deprecated Prefer @ref SRAMCTL_Init.
 */
void SRAMCTL_InitMem(SRAMCTL_Type *base, uint32_t start_addr, uint32_t end_addr);

/*! @} */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_SRAMCTL_H_ */
