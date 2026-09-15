/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_RESETCON_H_
#define _FSL_RESETCON_H_

#include "fsl_common.h"

/*!
 * @addtogroup resetcon
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief RESETCON driver version 1.0.0. */
#define FSL_RESETCON_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*! @name Magic values defined by the hardware. */
/*@{*/
/*! @brief Magic value that must be written to SWRST.EN to trigger the global warm reset. */
#define RESETCON_SWRST_MAGIC      (0x0123FAFAU)
/*! @brief Magic value that must be present in PD_RSTCTRL.MAGIC[31:16] to allow PD reset writes. */
#define RESETCON_PD_RSTCTRL_MAGIC_VALUE (0x0520U)
/*! @brief Magic value that clears the RSTCNT counter. */
#define RESETCON_RSTCNT_CLR_MAGIC (0xDEEDBEEFU)
/*! @} */

/*!
 * @brief Latched-reset source flags (RSTSTAT and RSTSTAT_STICKY share this layout).
 *
 * Status bits in RSTSTAT are read-only; the matching bits in RSTSTAT_STICKY are
 * write-1-to-clear.
 */
enum _resetcon_reset_source_flags
{
    kRESETCON_SrcPorVbat   = RESETCON_RSTSTAT_POR_VBAT_MASK,    /*!< VBAT power-on reset. */
    kRESETCON_SrcPmuPor    = RESETCON_RSTSTAT_PMU_POR_MASK,     /*!< PMU internal supply POR. */
    kRESETCON_SrcPinPor    = RESETCON_RSTSTAT_PIN_POR_MASK,     /*!< POR_b pin reset. */
    kRESETCON_SrcPmuCold   = RESETCON_RSTSTAT_PMU_COLD_MASK,    /*!< PMU cold reset. */
    kRESETCON_SrcWuVbat    = RESETCON_RSTSTAT_WU_VBAT_MASK,     /*!< VBAT (DPD) wakeup reset. */
    kRESETCON_SrcSecCold   = RESETCON_RSTSTAT_SEC_COLD_MASK,    /*!< Security cold reset. */
    kRESETCON_SrcWarmEsca  = RESETCON_RSTSTAT_WARM_ESCA_MASK,   /*!< Warm reset escalated to cold. */
    kRESETCON_SrcRstErr    = RESETCON_RSTSTAT_RST_ERR_MASK,     /*!< RESETCON error reset. */
    kRESETCON_SrcPinReset  = RESETCON_RSTSTAT_PIN_RESET_MASK,   /*!< RESET_b pin reset. */
    kRESETCON_SrcResetSw   = RESETCON_RSTSTAT_RESET_SW_MASK,    /*!< Software-initiated warm reset. */
    kRESETCON_SrcDap       = RESETCON_RSTSTAT_DAP_MASK,         /*!< DAP / MDM-AP JTAG software reset. */
    kRESETCON_SrcJtag      = RESETCON_RSTSTAT_JTAG_MASK,        /*!< JTAG reset. */
    kRESETCON_SrcCpu0Sw    = RESETCON_RSTSTAT_CPU0_SW_MASK,     /*!< CPU0 software warm reset. */
    kRESETCON_SrcCpu0Err   = RESETCON_RSTSTAT_CPU0_ERR_MASK,    /*!< CPU0 lock-up reset. */
    kRESETCON_SrcSwt0      = RESETCON_RSTSTAT_SWT0_MASK,        /*!< SWT_0 reset. */
    kRESETCON_SrcSwt1      = RESETCON_RSTSTAT_SWT1_MASK,        /*!< SWT_1 reset. */
    kRESETCON_SrcSecvio    = RESETCON_RSTSTAT_SECVIO_MASK,      /*!< Security violation reset. */
    kRESETCON_SrcTamper    = RESETCON_RSTSTAT_TAMPER_MASK,      /*!< Tamper pin reset. */
    kRESETCON_SrcPmuWarm   = RESETCON_RSTSTAT_PMU_WARM_MASK,    /*!< PMU warm reset. */
    kRESETCON_SrcWuPd      = RESETCON_RSTSTAT_WU_PD_MASK,       /*!< Power-down wakeup reset. */
    kRESETCON_SrcAll       = 0x000FFFFFU,                       /*!< All defined source bits. */
};

/*!
 * @brief Warm-reset source flags shared by ESCAEN, RSTIE, RSTIS, RMSK and RTM.
 *
 * These are the warm-reset sources that can be escalated, masked, or routed to an
 * interrupt. Bit 1 (RESET_SW) is only valid in ESCAEN; it is reserved in RSTIE/RSTIS.
 */
enum _resetcon_warm_reset_flags
{
    kRESETCON_WarmPinReset = RESETCON_ESCAEN_PIN_RESET_MASK, /*!< RESET_b pin (bit 0). */
    kRESETCON_WarmResetSw  = RESETCON_ESCAEN_RESET_SW_MASK,  /*!< Software warm reset (bit 1, ESCAEN only). */
    kRESETCON_WarmDap      = RESETCON_ESCAEN_DAP_MASK,       /*!< DAP reset (bit 2). */
    kRESETCON_WarmJtag     = RESETCON_ESCAEN_JTAG_MASK,      /*!< JTAG reset (bit 3). */
    kRESETCON_WarmCpu0Sw   = RESETCON_ESCAEN_CPU0_SW_MASK,   /*!< CPU0 software (bit 4). */
    kRESETCON_WarmCpu0Err  = RESETCON_ESCAEN_CPU0_ERR_MASK,  /*!< CPU0 error (bit 5). */
    kRESETCON_WarmSwt0     = RESETCON_ESCAEN_SWT0_MASK,      /*!< SWT_0 (bit 6). */
    kRESETCON_WarmSwt1     = RESETCON_ESCAEN_SWT1_MASK,      /*!< SWT_1 (bit 7). */
    kRESETCON_WarmSecvio   = RESETCON_ESCAEN_SECVIO_MASK,    /*!< Security violation (bit 8). */
    kRESETCON_WarmTamper   = RESETCON_ESCAEN_TAMPER_MASK,    /*!< Tamper pin (bit 9). */
    kRESETCON_WarmPmuWarm  = RESETCON_ESCAEN_PMU_WARM_MASK,  /*!< PMU warm reset (bit 10). */
    kRESETCON_WarmAll      = 0x000007FFU,                    /*!< All warm-source bits. */
};

/*!
 * @brief Power-domain reset flags (PD_RSTSTAT and PD_RSTSTAT_STICKY share this layout).
 */
enum _resetcon_pd_reset_flags
{
    kRESETCON_PdWake  = RESETCON_PD_RSTSTAT_PD_WAKE_MASK,  /*!< Wake power domain. */
    kRESETCON_PdMain  = RESETCON_PD_RSTSTAT_PD_MAIN_MASK,  /*!< Main power domain. */
    kRESETCON_PdCpu   = RESETCON_PD_RSTSTAT_PD_CPU_MASK,   /*!< Cortex-M85 power domain. */
    kRESETCON_PdNpu   = RESETCON_PD_RSTSTAT_PD_NPU_MASK,   /*!< NPU power domain. */
    kRESETCON_PdMedia = RESETCON_PD_RSTSTAT_PD_MEDIA_MASK, /*!< Media power domain. */
    kRESETCON_PdComm  = RESETCON_PD_RSTSTAT_PD_COMM_MASK,  /*!< Communication power domain. */
    kRESETCON_PdAll   = 0x3FU,                              /*!< All defined power domains. */
};

/*!
 * @brief Software-controllable power-domain reset triggers (PD_RSTCTRL bits 5..3).
 *
 * These are the only domains that can be reset by software via PD_RSTCTRL.
 */
enum _resetcon_pd_reset_ctrl
{
    kRESETCON_PdCtrlNpu   = RESETCON_PD_RSTCTRL_PD_NPU_MASK,   /*!< Reset NPU power domain. */
    kRESETCON_PdCtrlMedia = RESETCON_PD_RSTCTRL_PD_MEDIA_MASK, /*!< Reset Media power domain. */
    kRESETCON_PdCtrlComm  = RESETCON_PD_RSTCTRL_PD_COMM_MASK,  /*!< Reset Communication power domain. */
};

/*!
 * @brief Boot-mode codes captured/forced by MODESTAT.MS / MODECTRL.MC.
 */
typedef enum _resetcon_boot_mode
{
    kRESETCON_BootMode0 = 0U, /*!< Boot mode 00. */
    kRESETCON_BootMode1 = 1U, /*!< Boot mode 01. */
    kRESETCON_BootMode2 = 2U, /*!< Boot mode 10. */
    kRESETCON_BootMode3 = 3U, /*!< Boot mode 11. */
} resetcon_boot_mode_t;

/*!
 * @brief Trigger-mode selection for warm reset sources (RTM).
 */
typedef enum _resetcon_trigger_mode
{
    kRESETCON_TriggerLevel = 0U, /*!< Level trigger. */
    kRESETCON_TriggerEdge  = 1U, /*!< Edge trigger. */
} resetcon_trigger_mode_t;

/*!
 * @brief Access-control configuration for ACCCTRL.
 */
typedef struct _resetcon_access_config
{
    uint8_t domainMask;  /*!< 4-bit mask: bit n enables write access for Domain ID n. */
    bool    userMode;    /*!< true: allow user-mode writes; false: privileged only. */
    bool    nonSecure;   /*!< true: allow non-secure writes; false: secure only. */
    bool    lock;        /*!< true: lock ACCCTRL until next reset. */
} resetcon_access_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Version and initialization status
 * @{
 */

/*!
 * @brief Get the RESETCON version-ID register value.
 *
 * @param base  RESETCON peripheral base.
 * @return  Raw VERID value.
 */
static inline uint32_t RESETCON_GetVersion(RESETCON_Type *base)
{
    return base->VERID;
}

/*!
 * @brief Get the PMU boot-error status from INITS.
 *
 * @param base  RESETCON peripheral base.
 * @return  PMU boot-error code (6 bits).
 */
static inline uint32_t RESETCON_GetPmuBootErrorStatus(RESETCON_Type *base)
{
    return (base->INITS & RESETCON_INITS_PMU_BE_MASK) >> RESETCON_INITS_PMU_BE_SHIFT;
}

/*! @} */

/*!
 * @name Access control
 * @{
 */

/*!
 * @brief Configure RESETCON access control (ACCCTRL).
 *
 * @param base    RESETCON peripheral base.
 * @param config  Pointer to access-control configuration; must not be NULL.
 */
void RESETCON_SetAccessControl(RESETCON_Type *base, const resetcon_access_config_t *config);

/*!
 * @brief Read the raw ACCCTRL register.
 *
 * @param base  RESETCON peripheral base.
 * @return  Raw ACCCTRL value.
 */
static inline uint32_t RESETCON_GetAccessControl(RESETCON_Type *base)
{
    return base->ACCCTRL;
}

/*! @} */

/*!
 * @name Software reset
 * @{
 */

/*!
 * @brief Trigger a global warm reset of the chip.
 *
 * Writes the magic value 0x0123FAFA to SWRST.EN. The reset can be escalated
 * to a cold reset if RESET_SW is enabled in ESCAEN. This function does not return.
 *
 * @param base  RESETCON peripheral base.
 */
static inline void RESETCON_SystemReset(RESETCON_Type *base)
{
    base->SWRST = RESETCON_SWRST_MAGIC;
}

/*! @} */

/*!
 * @name Reset status
 * @{
 */

/*!
 * @brief Get the latest-reset source flags from RSTSTAT.
 *
 * @param base  RESETCON peripheral base.
 * @return  OR'ed mask of ::_resetcon_reset_source_flags.
 */
static inline uint32_t RESETCON_GetResetStatus(RESETCON_Type *base)
{
    return base->RSTSTAT;
}

/*!
 * @brief Get the sticky-reset source flags from RSTSTAT_STICKY.
 *
 * @param base  RESETCON peripheral base.
 * @return  OR'ed mask of ::_resetcon_reset_source_flags.
 */
static inline uint32_t RESETCON_GetStickyResetStatus(RESETCON_Type *base)
{
    return base->RSTSTAT_STICKY;
}

/*!
 * @brief Clear sticky-reset flags in RSTSTAT_STICKY (write-1-to-clear).
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_reset_source_flags to clear.
 */
static inline void RESETCON_ClearStickyResetStatus(RESETCON_Type *base, uint32_t mask)
{
    base->RSTSTAT_STICKY = mask & (uint32_t)kRESETCON_SrcAll;
}

/*!
 * @brief Get the current reset count.
 *
 * @param base  RESETCON peripheral base.
 * @return  Number of warm-reset sequences completed since the last cold reset.
 */
static inline uint32_t RESETCON_GetResetCount(RESETCON_Type *base)
{
    return base->RSTCNT;
}

/*!
 * @brief Clear the reset count register (writes the magic 0xDEEDBEEF).
 *
 * @param base  RESETCON peripheral base.
 */
static inline void RESETCON_ClearResetCount(RESETCON_Type *base)
{
    base->RSTCNT = RESETCON_RSTCNT_CLR_MAGIC;
}

/*! @} */

/*!
 * @name Power-domain reset
 * @{
 */

/*!
 * @brief Get power-domain reset status from PD_RSTSTAT.
 *
 * @param base  RESETCON peripheral base.
 * @return  OR'ed mask of ::_resetcon_pd_reset_flags currently in reset.
 */
static inline uint32_t RESETCON_GetPowerDomainResetStatus(RESETCON_Type *base)
{
    return base->PD_RSTSTAT;
}

/*!
 * @brief Get sticky power-domain reset status from PD_RSTSTAT_STICKY.
 *
 * @param base  RESETCON peripheral base.
 * @return  OR'ed mask of ::_resetcon_pd_reset_flags ever asserted since last clear.
 */
static inline uint32_t RESETCON_GetStickyPowerDomainResetStatus(RESETCON_Type *base)
{
    return base->PD_RSTSTAT_STICKY;
}

/*!
 * @brief Clear sticky power-domain reset flags (write-1-to-clear).
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_pd_reset_flags to clear.
 */
static inline void RESETCON_ClearStickyPowerDomainResetStatus(RESETCON_Type *base, uint32_t mask)
{
    base->PD_RSTSTAT_STICKY = mask & (uint32_t)kRESETCON_PdAll;
}

/*!
 * @brief Trigger a software-controlled power-domain reset.
 *
 * Software must ensure the bus initiator and fabric are idle. The MAGIC field
 * (0x0520) is automatically written along with the requested domain bits.
 *
 * @param base   RESETCON peripheral base.
 * @param mask   OR'ed mask of ::_resetcon_pd_reset_ctrl: NPU, MEDIA, or COMM only.
 */
void RESETCON_TriggerPowerDomainReset(RESETCON_Type *base, uint32_t mask);

/*! @} */

/*!
 * @name Reset escalation
 * @{
 */

/*!
 * @brief Enable warm-to-cold reset escalation for the given sources.
 *
 * Bits in ESCAEN are write-once-set: once enabled, they cannot be cleared
 * until the next cold reset.
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags.
 */
static inline void RESETCON_EnableResetEscalation(RESETCON_Type *base, uint32_t mask)
{
    base->ESCAEN |= (mask & (uint32_t)kRESETCON_WarmAll);
}

/*!
 * @brief Read the ESCAEN register.
 *
 * @param base  RESETCON peripheral base.
 * @return  Raw ESCAEN value.
 */
static inline uint32_t RESETCON_GetResetEscalation(RESETCON_Type *base)
{
    return base->ESCAEN;
}

/*! @} */

/*!
 * @name Interrupt control
 * @{
 */

/*!
 * @brief Enable warm-reset interrupts (RSTIE).
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags.
 *              Bit 1 (RESET_SW) is reserved in RSTIE.
 */
static inline void RESETCON_EnableInterrupts(RESETCON_Type *base, uint32_t mask)
{
    base->RSTIE |= (mask & ((uint32_t)kRESETCON_WarmAll & ~(uint32_t)kRESETCON_WarmResetSw));
}

/*!
 * @brief Disable warm-reset interrupts (RSTIE).
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags.
 */
static inline void RESETCON_DisableInterrupts(RESETCON_Type *base, uint32_t mask)
{
    base->RSTIE &= ~(mask & (uint32_t)kRESETCON_WarmAll);
}

/*!
 * @brief Read the warm-reset interrupt status (RSTIS).
 *
 * @param base  RESETCON peripheral base.
 * @return  OR'ed mask of ::_resetcon_warm_reset_flags currently asserted.
 */
static inline uint32_t RESETCON_GetInterruptStatus(RESETCON_Type *base)
{
    return base->RSTIS;
}

/*!
 * @brief Clear warm-reset interrupt status (write-1-to-clear).
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags to clear.
 */
static inline void RESETCON_ClearInterruptStatus(RESETCON_Type *base, uint32_t mask)
{
    base->RSTIS = mask & (uint32_t)kRESETCON_WarmAll;
}

/*!
 * @brief Set the interrupt-timeout (cycles) before an unhandled reset interrupt is escalated.
 *
 * @param base   RESETCON peripheral base.
 * @param value  32-bit timeout value.
 */
static inline void RESETCON_SetInterruptTimeout(RESETCON_Type *base, uint32_t value)
{
    base->ITO = value;
}

/*! @} */

/*!
 * @name Reset masking and trigger mode
 * @{
 */

/*!
 * @brief Mask warm reset sources (RMSK).
 *
 * Setting a bit disables the corresponding reset and interrupt.
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags.
 */
static inline void RESETCON_SetResetMask(RESETCON_Type *base, uint32_t mask)
{
    base->RMSK = mask & (uint32_t)kRESETCON_WarmAll;
}

/*!
 * @brief Configure the trigger mode (level/edge) for selected warm reset sources (RTM).
 *
 * Only the bits indicated by @p mask are modified; trigger-mode settings of
 * sources that are not in @p mask are preserved.
 *
 * @param base  RESETCON peripheral base.
 * @param mask  OR'ed mask of ::_resetcon_warm_reset_flags identifying which
 *              sources to (re)configure.
 * @param mode  Trigger mode applied to the selected sources; see
 *              ::resetcon_trigger_mode_t.
 */
static inline void RESETCON_SetResetTriggerMode(RESETCON_Type *base, uint32_t mask, resetcon_trigger_mode_t mode)
{
    uint32_t scoped = mask & (uint32_t)kRESETCON_WarmAll;
    if (mode == kRESETCON_TriggerEdge)
    {
        base->RTM |= scoped;
    }
    else
    {
        base->RTM &= ~scoped;
    }
}

/*!
 * @brief Set the maximum number of consecutive warm-reset sequences (RTO).
 *
 * If exceeded, the next warm reset is escalated to a cold reset. Set 0 to disable.
 *
 * @param base   RESETCON peripheral base.
 * @param value  12-bit timeout value.
 */
void RESETCON_SetResetTimeout(RESETCON_Type *base, uint16_t value);

/*! @} */

/*!
 * @name Filters and reset output
 * @{
 */

/*!
 * @brief Configure the RESET_b pin digital filter (FILTER).
 *
 * @param base   RESETCON peripheral base.
 * @param value  16-bit cycle count; 0 disables the filter.
 */
void RESETCON_SetResetPinFilter(RESETCON_Type *base, uint16_t value);

/*!
 * @brief Configure the POR_b pin digital filter (PORPC.PFT).
 *
 * @param base   RESETCON peripheral base.
 * @param value  16-bit cycle count; 0 disables the filter.
 */
void RESETCON_SetPorPinFilter(RESETCON_Type *base, uint16_t value);

/*!
 * @brief Enable or disable the POR_b pin triggering a PMU restart (PORPC.TPC).
 *
 * @param base    RESETCON peripheral base.
 * @param enable  true: enable PMU restart; false: disable.
 */
void RESETCON_EnablePorTriggerPmuRestart(RESETCON_Type *base, bool enable);

/*!
 * @brief Drive the RESET_b output pin under software control (ROUT.OUTEN).
 *
 * @param base    RESETCON peripheral base.
 * @param assert  true: assert RESET_b; false: release.
 */
static inline void RESETCON_AssertResetOutput(RESETCON_Type *base, bool assert)
{
    base->ROUT = assert ? RESETCON_ROUT_OUTEN_MASK : 0U;
}

/*! @} */

/*!
 * @name Boot mode
 * @{
 */

/*!
 * @brief Read the latched boot-mode pins (MODESTAT.MS).
 *
 * @param base  RESETCON peripheral base.
 * @return  Latched boot mode, see ::resetcon_boot_mode_t.
 */
static inline resetcon_boot_mode_t RESETCON_GetBootMode(RESETCON_Type *base)
{
    return (resetcon_boot_mode_t)(uint32_t)((base->MODESTAT & RESETCON_MODESTAT_MS_MASK) >> RESETCON_MODESTAT_MS_SHIFT);
}

/*!
 * @brief Override the boot mode for the next warm-reset sequence.
 *
 * @param base    RESETCON peripheral base.
 * @param mode    Boot mode to force.
 * @param enable  true: enable override; false: disable override.
 */
void RESETCON_SetBootModeOverride(RESETCON_Type *base, resetcon_boot_mode_t mode, bool enable);

/*! @} */

/*!
 * @name Misc control
 * @{
 */

/*!
 * @brief Configure the trigger mode for the JTAGC quick-response warm reset
 *        path (MISCCTRL.QRSP_EN).
 *
 * Only the QRSP_EN bit is modified; other MISCCTRL fields (e.g. ACGOV) are
 * preserved.
 *
 * @param base  RESETCON peripheral base.
 * @param mode  Trigger mode applied to the quick-response source; see
 *              ::resetcon_trigger_mode_t.
 */
void RESETCON_SetQuickResponseTriggerMode(RESETCON_Type *base, resetcon_trigger_mode_t mode);

/*!
 * @brief Override automatic clock gating (MISCCTRL.ACGOV).
 *
 * @param base    RESETCON peripheral base.
 * @param enable  true: free-running clock; false: use auto clock gating.
 */
void RESETCON_OverrideAutoClockGating(RESETCON_Type *base, bool enable);

/*! @} */

/*!
 * @name General-purpose registers
 * @{
 */

/*!
 * @brief Write a 32-bit value to a RESETCON GPR.
 *
 * @param base   RESETCON peripheral base.
 * @param index  GPR index (0 .. RESETCON_GPR_COUNT - 1).
 * @param value  32-bit value.
 */
static inline void RESETCON_WriteGPR(RESETCON_Type *base, uint8_t index, uint32_t value)
{
    assert(index < RESETCON_GPR_COUNT);
    base->GPR[index] = value;
}

/*!
 * @brief Read a 32-bit value from a RESETCON GPR.
 *
 * @param base   RESETCON peripheral base.
 * @param index  GPR index (0 .. RESETCON_GPR_COUNT - 1).
 * @return  Stored 32-bit value.
 */
static inline uint32_t RESETCON_ReadGPR(RESETCON_Type *base, uint8_t index)
{
    assert(index < RESETCON_GPR_COUNT);
    return base->GPR[index];
}

/*!
 * @brief Lock individual GPR(s) until next reset.
 *
 * Each bit n in @p mask sets LOCKn for GPRn. Lock bits are sticky and can only
 * be cleared by reset.
 *
 * @param base  RESETCON peripheral base.
 * @param mask  16-bit mask of GPR indices to lock.
 */
static inline void RESETCON_LockGPR(RESETCON_Type *base, uint16_t mask)
{
    base->GPR_LOCK |= (uint32_t)mask;
}

/*!
 * @brief Read the GPR lock register (GPR_LOCK).
 *
 * @param base  RESETCON peripheral base.
 * @return  16-bit lock mask, bit n indicates GPRn is locked.
 */
static inline uint16_t RESETCON_GetGPRLockStatus(RESETCON_Type *base)
{
    return (uint16_t)(base->GPR_LOCK & 0xFFFFU);
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_RESETCON_H_ */
