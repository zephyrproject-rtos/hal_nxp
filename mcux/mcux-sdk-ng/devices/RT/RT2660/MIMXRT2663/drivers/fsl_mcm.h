/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MCM_H_
#define _FSL_MCM_H_

#include "fsl_common.h"

/*!
 * @addtogroup mcm
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief MCM driver version 1.0.0. */
#define FSL_MCM_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*!
 * @brief MCM ISCR interrupt-enable flags.
 *
 * These flags can be OR'ed and passed to MCM_EnableInterrupts /
 * MCM_DisableInterrupts. They live in the upper half of the ISCR register.
 */
enum _mcm_interrupt_enable
{
    kMCM_IrqTcmWriteAbort = MCM_ISCR_WABE_MASK,  /*!< TCM write abort interrupt enable. */
    kMCM_IrqFpuInvalidOp  = MCM_ISCR_FIOCE_MASK, /*!< FPU invalid-operation interrupt enable. */
    kMCM_IrqFpuDivByZero  = MCM_ISCR_FDZCE_MASK, /*!< FPU divide-by-zero interrupt enable. */
    kMCM_IrqFpuOverflow   = MCM_ISCR_FOFCE_MASK, /*!< FPU overflow interrupt enable. */
    kMCM_IrqFpuUnderflow  = MCM_ISCR_FUFCE_MASK, /*!< FPU underflow interrupt enable. */
    kMCM_IrqFpuInexact    = MCM_ISCR_FIXCE_MASK, /*!< FPU inexact interrupt enable. */
    kMCM_IrqFpuInputDenom = MCM_ISCR_FIDCE_MASK, /*!< FPU input-denormal interrupt enable. */
    kMCM_IrqAll           = MCM_ISCR_WABE_MASK  | MCM_ISCR_FIOCE_MASK | MCM_ISCR_FDZCE_MASK |
                            MCM_ISCR_FOFCE_MASK | MCM_ISCR_FUFCE_MASK | MCM_ISCR_FIXCE_MASK |
                            MCM_ISCR_FIDCE_MASK, /*!< All ISCR enable bits. */
};

/*!
 * @brief MCM ISCR status flags (lower half of ISCR).
 *
 * The FPU flags (FIOC..FIDC) mirror the corresponding bits in the core's
 * FPSCR and remain set until the matching FPSCR bit is cleared by software.
 * WABS is the only software-clearable bit (W1C); WABSO is auto-cleared when
 * WABS is cleared.
 */
enum _mcm_status_flags
{
    kMCM_StatusTcmWriteAbort         = MCM_ISCR_WABS_MASK,  /*!< TCM write-abort detected. */
    kMCM_StatusTcmWriteAbortOverrun  = MCM_ISCR_WABSO_MASK, /*!< TCM write-abort overrun. */
    kMCM_StatusFpuInvalidOp          = MCM_ISCR_FIOC_MASK,  /*!< FPU invalid-operation. */
    kMCM_StatusFpuDivByZero          = MCM_ISCR_FDZC_MASK,  /*!< FPU divide-by-zero. */
    kMCM_StatusFpuOverflow           = MCM_ISCR_FOFC_MASK,  /*!< FPU overflow. */
    kMCM_StatusFpuUnderflow          = MCM_ISCR_FUFC_MASK,  /*!< FPU underflow. */
    kMCM_StatusFpuInexact            = MCM_ISCR_FIXC_MASK,  /*!< FPU inexact. */
    kMCM_StatusFpuInputDenom         = MCM_ISCR_FIDC_MASK,  /*!< FPU input-denormal. */
    kMCM_StatusAll                   = MCM_ISCR_WABS_MASK  | MCM_ISCR_WABSO_MASK |
                                       MCM_ISCR_FIOC_MASK  | MCM_ISCR_FDZC_MASK  |
                                       MCM_ISCR_FOFC_MASK  | MCM_ISCR_FUFC_MASK  |
                                       MCM_ISCR_FIXC_MASK  | MCM_ISCR_FIDC_MASK, /*!< All ISCR status bits. */
};

/*!
 * @brief Aggregated process-fault state read from PFSHR + PFSLR.
 *
 * Mirrors the Cortex-M85 FAULTSTAT bus[42:0]: PFSLR holds bits [31:0] and
 * PFSHR holds bits [42:32] arranged as follows:
 *  - PFSHR.HFSR_VECTTBL  (bit 0)  = FAULTSTAT[32]
 *  - PFSHR.HFSR_FORCED   (bit 1)  = FAULTSTAT[33]
 *  - PFSHR.HFSR_DEBUGEVT (bit 2)  = FAULTSTAT[34]
 *  - PFSHR.SFSR          (bits 10:3) = FAULTSTAT[42:35]
 */
typedef struct _mcm_fault_status
{
    uint8_t  mmfsr;       /*!< Memory-Management Fault Status Register (FAULTSTAT[7:0]). */
    uint8_t  bfsr;        /*!< Bus Fault Status Register (FAULTSTAT[15:8]). */
    uint16_t ufsr;        /*!< Usage Fault Status Register (FAULTSTAT[31:16]). */
    uint8_t  sfsr;        /*!< Secure Fault Status Register (FAULTSTAT[42:35]). */
    bool     hfsrVecttbl; /*!< Hard fault vector-table read failure. */
    bool     hfsrForced;  /*!< Hard fault forced. */
    bool     hfsrDebugEvt;/*!< Hard fault triggered by a debug event. */
} mcm_fault_status_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Interrupt control
 * @{
 */

/*!
 * @brief Enable MCM interrupt sources.
 *
 * @param base  MCM peripheral base.
 * @param mask  OR'ed mask of ::_mcm_interrupt_enable values.
 */
static inline void MCM_EnableInterrupts(MCM_Type *base, uint32_t mask)
{
    base->ISCR |= (mask & (uint32_t)kMCM_IrqAll);
}

/*!
 * @brief Disable MCM interrupt sources.
 *
 * @param base  MCM peripheral base.
 * @param mask  OR'ed mask of ::_mcm_interrupt_enable values.
 */
static inline void MCM_DisableInterrupts(MCM_Type *base, uint32_t mask)
{
    base->ISCR &= ~(mask & (uint32_t)kMCM_IrqAll);
}

/*!
 * @brief Get the currently-enabled MCM interrupt sources.
 *
 * @param base  MCM peripheral base.
 * @return  OR'ed mask of ::_mcm_interrupt_enable values currently enabled.
 */
static inline uint32_t MCM_GetEnabledInterrupts(MCM_Type *base)
{
    return base->ISCR & (uint32_t)kMCM_IrqAll;
}

/*! @} */

/*!
 * @name Status flags
 * @{
 */

/*!
 * @brief Get the asserted MCM status flags from ISCR.
 *
 * The returned mask covers eight ISCR status bits with three different clear paths:
 *   - kMCM_StatusTcmWriteAbort (WABS):         cleared via MCM_ClearTcmWriteAbort().
 *   - kMCM_StatusTcmWriteAbortOverrun (WABSO): auto-cleared by hardware when WABS clears.
 *   - kMCM_StatusFpuInvalidOp .. kMCM_StatusFpuInputDenom (FIOC..FIDC):
 *                                              read-only mirrors of FPSCR; clear by
 *                                              writing the matching bit in the core's FPSCR.
 *
 * @param base  MCM peripheral base.
 * @return  OR'ed mask of ::_mcm_status_flags currently asserted.
 */
static inline uint32_t MCM_GetStatusFlags(MCM_Type *base)
{
    return base->ISCR & (uint32_t)kMCM_StatusAll;
}

/*!
 * @brief Clear the TCM write-abort status.
 *
 * Writes 1 to ISCR[WABS]; WABSO is auto-cleared by hardware. The FPU status
 * bits cannot be cleared from MCM - clear the corresponding FPSCR bit instead.
 *
 * @param base  MCM peripheral base.
 */
void MCM_ClearTcmWriteAbort(MCM_Type *base);

/*! @} */

/*!
 * @name Fault state and current PC
 * @{
 */

/*!
 * @brief Read the raw PFSHR register (FAULTSTAT[42:32]).
 *
 * @param base  MCM peripheral base.
 * @return  Raw PFSHR value.
 */
static inline uint32_t MCM_GetProcessFaultStateHigh(MCM_Type *base)
{
    return base->PFSHR;
}

/*!
 * @brief Read the raw PFSLR register (FAULTSTAT[31:0]).
 *
 * @param base  MCM peripheral base.
 * @return  Raw PFSLR value.
 */
static inline uint32_t MCM_GetProcessFaultStateLow(MCM_Type *base)
{
    return base->PFSLR;
}

/*!
 * @brief Read and decode the process-fault state into a structure.
 *
 * Reads PFSLR and PFSHR once and unpacks the fields. This is convenient when
 * a non-CPU master (e.g. debugger) wants to inspect the CM85 fault state.
 *
 * @param base    MCM peripheral base.
 * @param status  Out: decoded fault status; must not be NULL.
 */
void MCM_GetFaultStatus(MCM_Type *base, mcm_fault_status_t *status);

/*!
 * @brief Read the current program counter (CURRPC).
 *
 * Returns the address of the instruction currently executing on the CM85
 * processor, or the address of the last instruction executed during exception
 * entry / return. Bit 0 is always 0.
 *
 * @param base  MCM peripheral base.
 * @return  32-bit instruction address.
 */
static inline uint32_t MCM_GetCurrentPC(MCM_Type *base)
{
    return base->CURRPC & MCM_CURRPC_ADDR_MASK;
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_MCM_H_ */
