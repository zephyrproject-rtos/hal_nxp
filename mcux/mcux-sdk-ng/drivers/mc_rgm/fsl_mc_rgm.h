/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MC_RGM_H_
#define FSL_MC_RGM_H_

#include "fsl_common.h"

/*!
 * @addtogroup mc_rgm
 * @{
 */

 /*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */

/*! @brief MC_RGM driver version 2.1.0 */
#define FSL_MC_RGM_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*! 
 * @brief Destructive reset sources flag. 
 */
enum _mc_rgm_destructive_reset_sources_flag
{
    kMC_RGM_PowerOnResetFlag = MC_RGM_DES_F_POR_MASK, /*!< A power-on destructive reset (POR) has occurred */
    kMC_RGM_FccuFailureToReactResetFlag = MC_RGM_DES_FCCU_FTR_MASK, /*!< FCCU failure to react destructive reset (FCCU_FTR) has occurred  */
    kMC_RGM_StcuUnrecoverableFaultResetFlag = MC_RGM_DES_STCU_URF_MASK, /*!< STCU unrecoverable fault (STCU_URF) destructive reset has occurred */
    kMC_RGM_FunctionalResetEscalation = MC_RGM_DES_MC_RGM_FRE_MASK, /*!< Functional reset escalation (MCRGM_FRE) destructive reset has occurred */
    kMC_RGM_FxoscFailureResetFlag = MC_RGM_DES_FXOSC_FAIL_MASK, /*!< FXOSC failure (FXOSC_FAIL) destructive reset has occurred */
    kMC_RGM_PllLossOfLockResetFlag = MC_RGM_DES_PLL_LOL_MASK, /*!< PLL loss of lock (PLL_LOL) destructive reset has occurred */
    kMC_RGM_CoreClockFailureResetFlag = MC_RGM_DES_CORE_CLK_FAIL_MASK, /*!< Core clock failure (CORE_CLK_FAIL) destructive reset has occurred */
    kMC_RGM_AipsPlatClockFailureResetFlag = MC_RGM_DES_AIPS_PLAT_CLK_FAIL_MASK, /*!< AIPS_PLAT_CLK failure (HSE_CLK_FAIL) destructive reset has occurred */
    kMC_RGM_HseClockFailureResetFlag = MC_RGM_DES_HSE_CLK_FAIL_MASK, /*!< HSE_CLK failure (SYS_DIV_FAIL) destructive reset has occurred */
    kMC_RGM_SystemDividerFailureResetFlag = MC_RGM_DES_SYS_DIV_FAIL_MASK, /*!< System clock dividers alignment failure reset (SYS_DIV_FAIL) has occurred. */
    kMC_RGM_HseTamperDetectResetFlag = MC_RGM_DES_HSE_TMPR_RST_MASK, /*!< HSE_B tamper detection reset (HSE_TMPR_RST) has occurred. */
    kMC_RGM_HseSnvsTamperDetectionResetFlag = MC_RGM_DES_HSE_SNVS_RST_MASK, /*!< HSE_B SNVS tamper detection reset (HSE_SNVS_RST) has occurred. */
    kMC_RGM_SoftwareDestructiveResetFlag = MC_RGM_DES_SW_DEST_MASK, /*!< Software destructive reset (SW_DEST) has occurred. */
    kMC_RGM_DebugDestructiveResetFlag = MC_RGM_DES_DEBUG_DEST_MASK, /*!< Debug destructive reset (DEBUG_DEST) has occurred. */
    kMC_RGM_AllDestructiveResetFlags = (kMC_RGM_PowerOnResetFlag | kMC_RGM_FccuFailureToReactResetFlag | \
                                        kMC_RGM_StcuUnrecoverableFaultResetFlag | kMC_RGM_FunctionalResetEscalation | \
                                        kMC_RGM_FxoscFailureResetFlag | kMC_RGM_PllLossOfLockResetFlag | \
                                        kMC_RGM_CoreClockFailureResetFlag | kMC_RGM_AipsPlatClockFailureResetFlag | \
                                        kMC_RGM_HseClockFailureResetFlag | kMC_RGM_SystemDividerFailureResetFlag | \
                                        kMC_RGM_HseTamperDetectResetFlag | kMC_RGM_HseSnvsTamperDetectionResetFlag | \
                                        kMC_RGM_SoftwareDestructiveResetFlag | kMC_RGM_DebugDestructiveResetFlag)
};

/*!
 * @brief Functional reset sources flag.
 */
enum _mc_rgm_functional_reset_sources_flag
{
    kMC_RGM_ExternalDestructiveResetFLag = MC_RGM_FES_F_EXR_MASK, /*!< An external destructive reset (EXR) has occurred */
    kMC_RGM_FccuReactionResetFlag = MC_RGM_FES_FCCU_RST_MASK, /*!< FCCU reaction (FCCU_RST) functional reset has occurred */
    kMC_RGM_SelfTestDoneDoneFlag = MC_RGM_FES_ST_DONE_MASK, /*!< Self-test done (STCU_DONE) functional reset has occurred */
    kMC_RGM_Swt0Reset0Flag = MC_RGM_FES_SWT0_RST_MASK, /*!< SWT0 functional reset (SWT0_RST) has occurred  */
    kMC_RGM_JtagResetFlag = MC_RGM_FES_JTAG_RST_MASK, /*!< JTAG functional reset (JTAG_RST) has occurred */
    kMC_RGM_HseSoftwareTriggerResetFlag = MC_RGM_FES_HSE_SWT_RST_MASK, /*!< HSE_B SWT functional reset (HSE_SWT_RST) has occurred */
    kMC_RGM_HseBootResetFlag = MC_RGM_FES_HSE_BOOT_RST_MASK, /*!< HSE_B boot functional reset (HSE_BOOT_RST) has occurred */
    kMC_RGM_SoftwareFunctionalResetFlag = MC_RGM_FES_SW_FUNC_MASK, /*!< Software functional reset (SW_FUNC) has occurred */
    kMC_RGM_DebugFunctionalResetFlag = MC_RGM_FES_DEBUG_FUNC_MASK, /*!< Debug functional reset (DEBUG_FUNC) has occurred */
    kMC_RGM_AllFunctionalResetFlags = (kMC_RGM_ExternalDestructiveResetFLag | kMC_RGM_FccuReactionResetFlag | \
                                    kMC_RGM_SelfTestDoneDoneFlag | kMC_RGM_Swt0Reset0Flag | kMC_RGM_JtagResetFlag | \
                                    kMC_RGM_HseSoftwareTriggerResetFlag | kMC_RGM_HseBootResetFlag | \
                                    kMC_RGM_SoftwareFunctionalResetFlag | kMC_RGM_DebugFunctionalResetFlag)
};

/*!
 * @brief Bidirectional functional reset sources.
 */
enum _mc_rgm_bidirectional_function_reset_sources
{
    kMC_RGM_BidirectionalDebugFunctionalReset = MC_RGM_FBRE_BE_DEBUG_FUNC_MASK, /*!< External reset pin is not asserted on a 'functional' reset event DEBUG_FUNC */
    kMC_RGM_BidirectionalSoftwareFunctionalReset = MC_RGM_FBRE_BE_SW_FUNC_MASK, /*!< External reset pin is not asserted on a 'functional' reset event SW_FUNC */
    kMC_RGM_BidirectionalHseBootReset = MC_RGM_FBRE_BE_HSE_BOOT_RST_MASK, /*!< External reset pin is not asserted on a 'functional' reset event HSE_BOOT_RST */
    kMC_RGM_BidirectionalHseSwtReset = MC_RGM_FBRE_BE_HSE_SWT_RST_MASK, /*!< External reset pin is not asserted on a 'functional' reset event HSE_SWT_RST */
    kMC_RGM_BidirectionalJtagReset = MC_RGM_FBRE_BE_JTAG_RST_MASK, /*!< External reset pin is not asserted on a 'functional' reset event JTAG_RST */
    kMC_RGM_BidirectionalSwt0Reset = MC_RGM_FBRE_BE_SWT0_RST_MASK, /*!< External reset pin is not asserted on a 'functional' reset event SWT0_RST */
    kMC_RGM_BidirectionalSelfTestDoneReset = MC_RGM_FBRE_BE_ST_DONE_MASK, /*!< External reset pin is not asserted on a 'functional' reset event ST_DONE */
    kMC_RGM_BidirectionalFccuReactionReset = MC_RGM_FBRE_BE_FCCU_RST_MASK /*!< External reset pin is not asserted on a 'functional' reset event FCCU_RST */
};

/*!
 * @brief Demotable functional reset sources.
 */
enum _mc_rgm_demotable_functional_reset_sources
{
    kMC_RGM_FccuReactionReset = MC_RGM_FERD_D_FCCU_RST_MASK, /*!< Functional reset event FCCU_RST generates an interrupt request. */
    kMC_RGM_Swt0Reset = MC_RGM_FERD_D_SWT0_RST_MASK, /*!< Functional reset event SWT0_RST generates an interrupt request. */
    kMC_RGM_JtagReset = MC_RGM_FERD_D_JTAG_RST_MASK, /*!< Functional reset event DEBUG_FUNC generates an interrupt request. */
    kMC_RGM_DebugFunctionalReset = MC_RGM_FERD_D_DEBUG_FUNC_MASK /*!< Functional reset event DEBUG_FUNC generates an interrupt request. */
};

/*!
 * @brief Reset during standby status.
 */
enum _mc_rgm_reset_during_standby_status
{
    kMC_RGM_DestructiveResetDuringStandby = MC_RGM_RDSS_DES_RES_MASK, /*!< Destructive reset event occurred during standby mode. */
    kMC_RGM_FunctionalResetDuringStandby = MC_RGM_RDSS_FES_RES_MASK /*!< Functional reset event occurred during standby mode. */
};

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name MC_RGM reset status control
 * @{
 */

/*!
 * @brief Get destructive reset sources status.
 *
 * @param base MC_RGM peripheral base address.
 * @return Destructive reset sources status, This is the logical OR of members of
 *         @ref _mc_rgm_destructive_reset_sources_flag.
 */
static inline uint32_t MC_RGM_GetDestuctiveResetSourcesStatus(MC_RGM_Type *base)
{
    return base->DES;
}

/*!
 * @brief Clear destructive reset sources status.
 *
 * @param base MC_RGM peripheral base address.
 * @param flag Destructive reset sources flag, it can be logical OR of members of
 *             @ref _mc_rgm_destructive_reset_sources_flag.
 */
static inline void MC_RGM_ClearDestuctiveResetSourcesStatus(MC_RGM_Type *base, uint32_t flag)
{
    base->DES = flag;
}

/*!
 * @brief Get functional reset sources status.
 *
 * @param base MC_RGM peripheral base address.
 * @return Functional reset sources status, This is the logical OR of members of
 *         @ref _mc_rgm_functional_reset_sources_flag.
 */
static inline uint32_t MC_RGM_GetFunctionalResetSourcesStatus(MC_RGM_Type *base)
{
    return base->FES;   
}

/*!
 * @brief Clear functional reset sources status.
 *
 * @param base MC_RGM peripheral base address.
 * @param flag Functional reset sources flag, it can be logical OR of members of
 *             @ref _mc_rgm_functional_reset_sources_flag.
 */
static inline void MC_RGM_ClearFunctionalResetSourcesStatus(MC_RGM_Type *base, uint32_t flag)
{
    base->FES = flag;
}

/*!
 * @brief Get reset during standby status.
 *
 * @param base MC_RGM peripheral base address.
 * @return Reset during standby status, This is the logical OR of members of
 *         @ref _mc_rgm_reset_during_standby_status.
 */
static inline uint32_t MC_RGM_GetResetDuringStandbyStatus(MC_RGM_Type *base)
{
    return base->RDSS;
}

/*!
 * @brief Clear reset during standby status.
 *
 * @param base MC_RGM peripheral base address.
 * @param flag Reset during standby status, it can be logical OR of members of
 *             @ref _mc_rgm_reset_during_standby_status.
 */
static inline void MC_RGM_ClearResetDuringStandbyStatus(MC_RGM_Type *base, uint32_t flag)
{
    base->RDSS = flag;
}

/*!
 * @brief External reset pin is not asserted on a given 'functional' reset event.
 *
 * @param base MC_RGM peripheral base address.
 * @param flag Functional reset event, it can be logical OR of members of
 *             @ref _mc_rgm_bidirectional_function_reset_sources.
 */
static inline void MC_RGM_DisableBidirectionalReset(MC_RGM_Type *base, uint32_t flag)
{
    base->FBRE = flag;
}

/*! @}*/

/*!
 * @name MC_RGM reset demotion and escalation
 * @{
 */

/*!
 * @brief Demotes selected functional reset sources to interrupts.
 *
 * @param base MC_RGM peripheral base address.
 * @param mask Functional reset sources to be demoted to interrupts, it can be logical OR of members of
 *        @ref _mc_rgm_demotable_functional_reset_sources.
 */
static inline void MC_RGM_DemoteFunctionalResetToInterrupt(MC_RGM_Type *base, uint32_t mask)
{
    base->FERD = mask;
}

/*!
 * @brief Set the threshold for destructive reset escalation.
 *
 * This function sets the threshold for destructive reset escalation. MC_RGM increases a counter on each destructive
 * reset When the counter reaches the threshold, MC_RGM enters reset DEST0 and stays there until the next
 * power-on reset occurs.
 * 
 * @note This counter is cleared on a write of any value to the RGM_DRET register (call this function) and on any 
 *       power-on reset.
 * 
 * @param base MC_RGM peripheral base address.
 * @param count The threshold for destructive reset escalation.
 */
static inline void MC_RGM_SetDestructiveResetEscalationThreshold(MC_RGM_Type *base, uint32_t count)
{
    base->DRET = MC_RGM_DRET_DRET(count);
}

/*!
 * @brief Set the threshold for functional reset escalation.
 *
 * This function sets the threshold for functional reset escalation. MC_RGM increases a counter on each functional
 * reset. When the counter reaches the threshold, MC_RGM asserts a destructive reset.
 * 
 * @note This counter is cleared on a write of any value to the RGM_FRET register (call this function) and on any
 *       power-on or destructive reset.
 * 
 * @param base MC_RGM peripheral base address.
 * @param count The threshold for functional reset escalation.
 */
static inline void MC_RGM_SetFunctionalResetEscalationThreshold(MC_RGM_Type *base, uint32_t count)
{
    base->FRET = MC_RGM_FRET_FRET(count);
}

/*!
 * @brief Get the current count of functional reset escalation counter.
 *
 * @param base MC_RGM peripheral base address.
 * @return The current count of functional reset escalation counter.
 */
static inline uint32_t MC_RGM_GetFunctionalResetEscalationCount(MC_RGM_Type *base)
{
    return base->FREC & MC_RGM_FREC_FREC_MASK;
}

/*! @}*/

/*!
 * @}
 */
#if defined(__cplusplus)
}
#endif
#endif /* FSL_MC_RGM_H_ */
