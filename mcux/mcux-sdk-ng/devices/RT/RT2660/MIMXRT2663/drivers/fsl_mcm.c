/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_mcm.h"
#include "PERI_MCM.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.mcm"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Clear the TCM write-abort status.
 *
 * Performs a W1C of WABS while preserving every other field. WABSO is
 * auto-cleared by hardware once WABS is cleared. FPU status bits are
 * preserved - they can only be cleared via FPSCR.
 *
 * @param base  MCM peripheral base.
 */
void MCM_ClearTcmWriteAbort(MCM_Type *base)
{
    assert(base != NULL);

    /* Read-modify-write: keep enable bits, then write 1 to WABS only. */
    uint32_t enables = base->ISCR & (uint32_t)kMCM_IrqAll;
    base->ISCR       = enables | MCM_ISCR_WABS_MASK;
}

/*!
 * @brief Read and decode the process-fault state into a structure.
 *
 * @param base    MCM peripheral base.
 * @param status  Out: decoded fault status.
 */
void MCM_GetFaultStatus(MCM_Type *base, mcm_fault_status_t *status)
{
    assert(base != NULL);
    assert(status != NULL);

    uint32_t low  = base->PFSLR;
    uint32_t high = base->PFSHR;

    status->mmfsr = (uint8_t)((low & MCM_PFSLR_MMFSR_MASK) >> MCM_PFSLR_MMFSR_SHIFT);
    status->bfsr  = (uint8_t)((low & MCM_PFSLR_BFSR_MASK) >> MCM_PFSLR_BFSR_SHIFT);
    status->ufsr  = (uint16_t)((low & MCM_PFSLR_UFSR_MASK) >> MCM_PFSLR_UFSR_SHIFT);

    status->hfsrVecttbl  = (high & MCM_PFSHR_HFSR_VECTTBL_MASK) != 0U;
    status->hfsrForced   = (high & MCM_PFSHR_HFSR_FORCED_MASK) != 0U;
    status->hfsrDebugEvt = (high & MCM_PFSHR_HFSR_DEBUGEVT_MASK) != 0U;
    status->sfsr         = (uint8_t)((high & MCM_PFSHR_SFSR_MASK) >> MCM_PFSHR_SFSR_SHIFT);
}
