/*
 * Copyright 2019-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_PWMLL_H_
#define FSL_PWMLL_H_

#include "fsl_common.h"

/*!
 * @addtogroup pwmll_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief PWMLL driver version 2.1.0. */
#define FSL_PWMLL_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*! @} */

/*! PWM catpure FIFO depth */
#define PWMLL_CAPTURE_FIFO_DEPTH 4U

/*! Maximum value for PWM capture edge compare */
#define PWMLL_CAPTURE_EDGE_COMPARE_MAX 255U

/*! @brief List of PWM submodules ID */
typedef enum _pwmll_sm_id_t
{
    kPWMLL_SM0_ID = 0U, /*!< Submodule 0 ID */
    kPWMLL_SM1_ID = 1U, /*!< Submodule 1 ID */
    kPWMLL_SM2_ID = 2U, /*!< Submodule 2 ID */
    kPWMLL_SM3_ID = 3U  /*!< Submodule 3 ID */
} pwmll_sm_id_t;

/*! @brief List of PWM submodules mask */
typedef enum _pwmll_sm_mask_t
{
    kPWMLL_SM0_Mask = 1U, /*!< Submodule 0 mask */
    kPWMLL_SM1_Mask = 2U, /*!< Submodule 1 mask */
    kPWMLL_SM2_Mask = 4U, /*!< Submodule 2 mask */
    kPWMLL_SM3_Mask = 8U, /*!< Submodule 3 mask */
    kPWMLL_SM_MaskComp =
        kPWMLL_SM0_Mask | kPWMLL_SM1_Mask | kPWMLL_SM2_Mask | kPWMLL_SM3_Mask /*!< All submodule mask */
} pwmll_sm_mask_t;

/*! @brief List of PWM pair operation mode */
typedef enum _pwmll_pair_mode_t
{
    kPWMLL_PairMode_Complementary = 0U, /*!< PWM works in complementary mode.*/
    kPWMLL_PairMode_Independent   = 1U  /*!< PWM works in independent mode.*/
} pwmll_pair_mode_t;

/*! @brief PWM counter initialization options */
typedef enum _pwmll_init_sel_t
{
    kPWMLL_InitSel_Local        = 0U, /*!< Local sync causes initialization */
    kPWMLL_InitSel_MasterReload = 1U, /*!< Master reload from submodule 0 causes initialization */
    kPWMLL_InitSel_MasterSync   = 2U, /*!< Master sync from submodule 0 causes initialization */
    kPWMLL_InitSel_ExtSync      = 3U  /*!< EXT_SYNC causes initialization */
} pwmll_init_sel_t;

/*! @brief Options that can trigger a PWM FORCE_OUT */
typedef enum _pwmll_force_sel_t
{
    kPWMLL_ForceSel_LocalForce =
        0U, /*!< The local force signal, CTRL2[FORCE], from the submodule is used to force updates */
    kPWMLL_ForceSel_MasterForce = 1U, /*!< The master force signal from submodule 0 is used to force updates */
    kPWMLL_ForceSel_LocalReload = 2U, /*!< The local reload signal from this submodule is used to force updates without
                                         regard to the state of LDOK */
    kPWMLL_ForceSel_MasterReload =
        3U, /*!< The master reload signal from submodule 0 is used to force updates if LDOK is set */
    kPWMLL_ForceSel_LocalSync  = 4U, /*!< The local sync signal from this submodule is used to force updates */
    kPWMLL_ForceSel_MasterSync = 5U, /*!< The master sync signal from submodule0 is used to force updates */
    kPWMLL_ForceSel_ExtForce =
        6U, /*!< The external force signal, EXT_FORCE, from outside the PWM module causes updates */
    kPWMLL_ForceSel_ExtSync = 7U /*!< The external sync signal, EXT_SYNC, from outside the PWM module causes updates */
} pwmll_force_sel_t;

/*! @brief Options for PWM register reload trigger */
typedef enum _pwmll_reload_sel_t
{
    kPWMLL_ReloadSel_Local  = 0U, /*!< Buffered register reload signal is from local reload signal.*/
    kPWMLL_ReloadSel_Master = 1U  /*!< Buffered register reload signal is from master(sm0) reload signal.*/
} pwmll_reload_sel_t;

/*! @brief PWM clock source selection.*/
typedef enum _pwmll_clk_sel_t
{
    kPWMLL_ClkSel_IpBus  = 0U, /*!< The IPBus clock is used as the clock */
    kPWMLL_ClkSel_ExtClk = 1U, /*!< EXT_CLK is used as the clock */
    kPWMLL_ClkSel_Sm0Clk = 2U  /*!< Clock of the submodule 0 (AUX_CLK) is used as the source clock */
} pwmll_clk_sel_t;

/*! @brief PWM load frequency selection */
typedef enum _pwmll_load_freq_t
{
    kPWMLL_LoadFreq_1_Opptunity  = 0U,  /*!< Every PWM opportunities */
    kPWMLL_LoadFreq_2_Opptunity  = 1U,  /*!< Every 2 PWM opportunities */
    kPWMLL_LoadFreq_3_Opptunity  = 2U,  /*!< Every 3 PWM opportunities */
    kPWMLL_LoadFreq_4_Opptunity  = 3U,  /*!< Every 4 PWM opportunities */
    kPWMLL_LoadFreq_5_Opptunity  = 4U,  /*!< Every 5 PWM opportunities */
    kPWMLL_LoadFreq_6_Opptunity  = 5U,  /*!< Every 6 PWM opportunities */
    kPWMLL_LoadFreq_7_Opptunity  = 6U,  /*!< Every 7 PWM opportunities */
    kPWMLL_LoadFreq_8_Opptunity  = 7U,  /*!< Every 8 PWM opportunities */
    kPWMLL_LoadFreq_9_Opptunity  = 8U,  /*!< Every 9 PWM opportunities */
    kPWMLL_LoadFreq_10_Opptunity = 9U,  /*!< Every 10 PWM opportunities */
    kPWMLL_LoadFreq_11_Opptunity = 10U, /*!< Every 11 PWM opportunities */
    kPWMLL_LoadFreq_12_Opptunity = 11U, /*!< Every 12 PWM opportunities */
    kPWMLL_LoadFreq_13_Opptunity = 12U, /*!< Every 13 PWM opportunities */
    kPWMLL_LoadFreq_14_Opptunity = 13U, /*!< Every 14 PWM opportunities */
    kPWMLL_LoadFreq_15_Opptunity = 14U, /*!< Every 15 PWM opportunities */
    kPWMLL_LoadFreq_16_Opptunity = 15U  /*!< Every 16 PWM opportunities */
} pwmll_load_freq_t;

/*! @brief Options for PWM comparison mode */
typedef enum _pwmll_comp_mode_t
{
    kPWMLL_CompMode_Equal = 0U, /*!< The VALx register and the PWM counter are compared using an "euqal to" method. */
    kPWMLL_CompMode_EqualOrGreater =
        1U /*!< The VALx register and the PWM counter are compared using an "euqal to or greater" method. */
} pwmll_comp_mode_t;

/*! @brief PWM prescaler factor selection for clock source*/
typedef enum _pwmll_clk_prescaler_t
{
    kPWMLL_ClkPrescaler_div1   = 0U, /*!< PWM clock frequency = fclk/1 */
    kPWMLL_ClkPrescaler_div2   = 1U, /*!< PWM clock frequency = fclk/2 */
    kPWMLL_ClkPrescaler_div4   = 2U, /*!< PWM clock frequency = fclk/4 */
    kPWMLL_ClkPrescaler_div8   = 3U, /*!< PWM clock frequency = fclk/8 */
    kPWMLL_ClkPrescaler_div16  = 4U, /*!< PWM clock frequency = fclk/16 */
    kPWMLL_ClkPrescaler_div32  = 5U, /*!< PWM clock frequency = fclk/32 */
    kPWMLL_ClkPrescaler_div64  = 6U, /*!< PWM clock frequency = fclk/64 */
    kPWMLL_ClkPrescaler_div128 = 7U  /*!< PWM clock frequency = fclk/128 */
} pwmll_clk_prescaler_t;

/*! @brief Options for PWM buffered register load mode */
typedef enum _pwmll_load_mode_t
{
    kPWMLL_LoadMode_NextReloadOpportunity = 0U, /*!< Buffered register are reloaded at next reload opportunity. */
    kPWMLL_LoadMode_Immediately           = 1U  /*!< Buffered register are reloaded immediately. */
} pwmll_load_mode_t;

/*! @brief Options for PWM output polarity */
typedef enum _pwmll_output_polarity_t
{
    kPWMLL_OutputPolarity_Normal   = 0U, /*!< Output signal is as original. */
    kPWMLL_OutputPolarity_Inverted = 1U  /*!< Output signal is inverted. */
} pwmll_output_polarity_t;

/*! @brief Options for PWM output for fault state */
typedef enum _pwmll_fault_state_t
{
    kPWMLL_FaultState_Forced0  = 0U, /*!< Output 0 when fault condition. */
    kPWMLL_FaultState_Forced1  = 1U, /*!< Output 1 when fault condition. */
    kPWMLL_FaultState_TriState = 2U  /*!< Output tristate when fault condition. */
} pwmll_fault_state_t;

/*! @brief List of PWM value register */
typedef enum _pwmll_val_reg_mask_t
{
    kPWMLL_ValRegMask_0 = 0x1U,  /*!< PWM Value0 register mask. */
    kPWMLL_ValRegMask_1 = 0x2U,  /*!< PWM Value1 register mask. */
    kPWMLL_ValRegMask_2 = 0x4U,  /*!< PWM Value2 register mask. */
    kPWMLL_ValRegMask_3 = 0x8U,  /*!< PWM Value3 register mask. */
    kPWMLL_ValRegMask_4 = 0x10U, /*!< PWM Value4 register mask. */
    kPWMLL_ValRegMask_5 = 0x20U  /*!< PWM Value5 register mask. */
} pwmll_val_reg_mask_t;

/*! @brief Options for FIFO watermark mode for DMA */
typedef enum _pwmll_fifo_watermark_mode_t
{
    kPWMLL_FifoWatermarkMode_Or  = 0U, /*!< FIFO watermark are ORed for a DMA request. */
    kPWMLL_FifoWatermarkMode_And = 1U  /*!< FIFO watermark are ANDed for a DMA request. */
} pwmll_fifo_watermark_mode_t;

/*! @brief Options for capture DMA enable source */
typedef enum _pwmll_capture_dma_src_t
{
    kPWMLL_CaptureDmaSrc_Disabled      = 0U, /*!< Capture DMA requests disabled. */
    kPWMLL_CaptureDmaSrc_FifoWaterMark = 1U, /*!< Exceeding a FIFO watermark sets DMA request. */
    kPWMLL_CaptureDmaSrc_LocalSync     = 2U, /*!< A local sync (VAL1 matches counter) sets DMA request. */
    kPWMLL_CaptureDmaSrc_LocalReload   = 3U  /*!< A local reload (STS[RF] being set) sets DMA request. */
} pwmll_capture_dma_src_t;

/*! @brief Options for Mux output trigger 0 source */
typedef enum _pwmll_mux_output_trigger_0_src_t
{
    kPWMLL_MuxOutputTrigger0Src_PwmOutTrig0 = 0U, /*!< Select PWM_OUT_TRIG0 as the source for PWM_MUX_TRIG0. */
    kPWMLL_MuxOutputTrigger0Src_PwmA        = 1U  /*!< Select PWMA as the source for PWM_MUX_TRIG0. */
} pwmll_mux_output_trigger_0_src_t;

/*! @brief Options for Mux output trigger 1 source */
typedef enum _pwmll_mux_output_trigger_1_src_t
{
    kPWMLL_MuxOutputTrigger1Src_PwmOutTrig1 = 0U, /*!< Select PWM_OUT_TRIG1 as the source for PWM_MUX_TRIG1. */
    kPWMLL_MuxOutputTrigger1Src_PwmB        = 1U  /*!< Select PWMB as the source for PWM_MUX_TRIG1. */
} pwmll_mux_output_trigger_1_src_t;

/*! @brief Options for trigger output frequency */
typedef enum _pwmll_trigger_freq_t
{
    kPWMLL_TriggerFreq_EveryPwmCycle = 0U, /*!< Trigger output at every PWM cycle */
    kPWMLL_TriggerFreq_EveryReload   = 1U  /*!< Trigger output at every PWM reload */
} pwmll_trigger_freq_t;

/*! @brief List for PWM fault channel */
typedef enum _pwmll_fault_channel_t
{
    kPWMLL_FaultChannle_0 = 0U, /*!< Fault channel 0 id */
    kPWMLL_FaultChannle_1 = 1U  /*!< Fault channel 1 id */
} pwmll_fault_channel_t;

/*! @brief List for PWM fault input */
typedef enum _pwmll_fault_input_t
{
    kPWMLL_FaultInput_0      = 1U, /*!< Fault input 0 id */
    kPWMLL_FaultInput_1      = 2U, /*!< Fault input 1 id */
    kPWMLL_FaultInput_2      = 4U, /*!< Fault input 2 id */
    kPWMLL_FaultInput_3      = 8U, /*!< Fault input 3 id */
    kPWMLL_FaultInputCombine = kPWMLL_FaultInput_0 | kPWMLL_FaultInput_1 | kPWMLL_FaultInput_2 |
                               kPWMLL_FaultInput_3 /*!< Fault input combination*/
} pwmll_fault_input_t;

/*! @brief Options for capture input source */
typedef enum _pwmll_cap_input_src_t
{
    kPWMLL_CapInputSrc_Pwm         = 0U, /*!< PWM signal(PWMA or PWMB) is used for capture input */
    kPWMLL_CapInputSrc_EdgeCounter = 1U  /*!< Output of edge counter/compare is used for capture input */
} pwmll_cap_input_src_t;

/*! @brief Options for capture edge mode */
typedef enum _pwmll_cap_edge_mode_t
{
    kPWMLL_CapEdgemode_Disabled    = 0U, /*!< Disabled */
    kPWMLL_CapEdgemode_FallingEdge = 1U, /*!< Capture on falling edge only. */
    kPWMLL_CapEdgemode_RisingEdge  = 2U, /*!< Capture on rising edge only. */
    kPWMLL_CapEdgemode_BothEdge    = 3U  /*!< Capture on rising or falling edge. */
} pwmll_cap_edge_mode_t;

/*! @brief Options for PLL monitor mode */
typedef enum _pwmll_pll_monitor_mode_t
{
    kPWMLL_PllMonitorMode_NotLockedDoNotMonitor = 0U, /*!< Not locked, not monitor PLL */
    kPWMLL_PllMonitorMode_NotLockedMonitor      = 1U, /*!< Not locked, monitor PLL */
    kPWMLL_PllMonitorMode_LockedDoNotMonitor    = 2U, /*!< Locked, not monitor PLL */
    kPWMLL_PllMonitorMode_LockedMonitor         = 3U  /*!< Locked, monitor PLL */
} pwmll_pll_monitor_mode_t;

/*! @brief Options for input source of deadtime logic's PWM23 signal */
typedef enum _pwmll_deadtime_pwm23_source_t
{
    kPWMLL_DeadtimePwm23SourcePwm23         = 0U, /*!< Generated PWM23 signal is used by the deadtime logic. */
    kPWMLL_DeadtimePwm23SourceInvertedPwm23 = 1U, /*!< Inverted PWM23 signal is used by the deadtime logic. */
    kPWMLL_DeadtimePwm23SourceSWCOUT        = 2U, /*!< Software controlled value is used by the deadtime logic. */
    kPWMLL_DeadtimePwm23SourceExtA          = 3U  /*!< PWM_EXTA signal is used by the deadtime logic. */
} pwmll_deadtime_pwm23_source_t;

/*! @brief Options for input source of deadtime logic's PWM45 signal */
typedef enum _pwmll_deadtime_pwm45_source_t
{
    kPWMLL_DeadtimePwm45SourcePwm45         = 0U, /*!< Generated PWM45 signal is used by the deadtime logic. */
    kPWMLL_DeadtimePwm45SourceInvertedPwm45 = 1U, /*!< Inverted PWM45 signal is used by the deadtime logic. */
    kPWMLL_DeadtimePwm45SourceSWCOUT        = 2U, /*!< Software controlled value is used by the deadtime logic. */
    kPWMLL_DeadtimePwm45SourceExtB          = 3U  /*!< PWM_EXTB signal is used by the deadtime logic. */
} pwmll_deadtime_pwm45_source_t;

/*! @brief List of PWM pin in each submodule */
typedef enum _pwmll_sm_pin_id_t
{
    kPWMLL_SMPinId_X = 0U, /*!< PWMX pin/signal id. */
    kPWMLL_SMPinId_B = 1U, /*!< PWMB pin/signal id. */
    kPWMLL_SMPinId_A = 2U  /*!< PWMA pin/signal id. */
} pwmll_sm_pin_id_t;

/*! @brief List of capture module */
typedef enum _pwmll_sm_cap_id_t
{
    kPWMLL_SMCapId_0 = 0U, /*!< Capture circuit 0 id. */
    kPWMLL_SMCapId_1 = 1U  /*!< Capture circuit 1 id. */
} pwmll_sm_cap_id_t;

/*! @brief List of interrupt flag */
typedef enum _pwmll_int_mask_t
{
    kPWMLL_INT_Val0ComparedMask    = 0x1U,    /*!< VAL0 register compared mask. */
    kPWMLL_INT_Val1ComparedMask    = 0x2U,    /*!< VAL1 register compared mask. */
    kPWMLL_INT_Val2ComparedMask    = 0x4U,    /*!< VAL2 register compared mask. */
    kPWMLL_INT_Val3ComparedMask    = 0x8U,    /*!< VAL3 register compared mask. */
    kPWMLL_INT_Val4ComparedMask    = 0x10U,   /*!< VAL4 register compared mask. */
    kPWMLL_INT_Val5ComparedMask    = 0x20U,   /*!< VAL5 register compared mask. */
    kPWMLL_INT_CaptureX0Mask       = 0x40U,   /*!< Capture X0 mask. */
    kPWMLL_INT_CaptureX1Mask       = 0x80U,   /*!< Capture X1 mask. */
    kPWMLL_INT_CaptureB0Mask       = 0x100U,  /*!< Capture B0 mask. */
    kPWMLL_INT_CaptureB1Mask       = 0x200U,  /*!< Capture B1 mask. */
    kPWMLL_INT_CaptureA0Mask       = 0x400U,  /*!< Capture A0 mask. */
    kPWMLL_INT_CaptureA1Mask       = 0x800U,  /*!< Capture A1 mask. */
    kPWMLL_INT_ReloadMask          = 0x1000U, /*!< Reload mask. */
    kPWMLL_INT_ReloadErrorMask     = 0x2000U, /*!< Reload error mask. */
    kPWMLL_INT_RegisterUpdatedMask = 0x4000U  /*!< Register updated mask. */
} pwmll_int_mask_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Get submodule register CNT value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The value of submodule register: CNT.
 */
static inline uint16_t PWMLL_SM_GetCNT(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    return base->SM[id].CNT;
}

/*!
 * @brief Get submodule register INIT value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The value of submodule register: INIT.
 */
static inline uint16_t PWMLL_SM_GetINIT(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    return base->SM[id].INIT;
}

/*!
 * @brief Set submodule register INIT value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param value Setting value to register INIT.
 */
static inline void PWMLL_SM_SetINIT(PWM_Type *base, pwmll_sm_id_t id, uint16_t value)
{
    assert(base != NULL);
    base->SM[id].INIT = value;
}

/*!
 * @brief Get submodule register VALx value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID, should be member of pwmll_sm_id_t.
 * @param valRegIndex Value register index, range in 0~5.
 *
 * @return The value of submodule register VALx.
 */
#define PWMLL_SM_GetVal(base, id, valRegIndex) (base->SM[id].VAL##valRegIndex)

/*!
 * @brief Set submodule register VALx value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID, should be member of pwmll_sm_id_t.
 * @param valRegIndex Value register index, range in 0~5.
 * @param value Setting value to register VALx.
 */
#define PWMLL_SM_SetVal(base, id, valRegIndex, value) \
    {                                                 \
        base->SM[id].VAL##valRegIndex = value;        \
    }

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U))

/*!
 * @brief Get submodule register FRACVALx value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID, should be member of pwmll_sm_id_t.
 * @param fracValRegIndex Fractional value register index, range in 1~5.
 *
 * @return The value of submodule register FRACVALx.
 */
#define PWMLL_SM_GetFracVal(base, id, fracValRegIndex) (base->SM[id].FRACVAL##fracValRegIndex)

/*!
 * @brief Set submodule register FRACVALx value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID, should be member of pwmll_sm_id_t.
 * @param fracValRegIndex Fractional value register index, range in 1~5.
 * @param value Setting value to register FRACVALx.
 */
#define PWMLL_SM_SetFracVal(base, id, fracValRegIndex, value) \
    {                                                         \
        base->SM[id].FRACVAL##fracValRegIndex = value;        \
    }

/*!
 * @brief Get submodule register VALx and its FRAC value with 32bit access.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param valRegIndex Value register index, range in 1~5.
 *
 * @return The value of submodule register VALx and its FRAC, combined into 32bit.
 *         VALx: BIT16~BIT31.
 *         FRACVALx: BIT11~BIT15.
 *         RSVD: BIT10~BIT0.
 */
#define PWMLL_SM_GetValAndFrac(base, id, valRegIndex) (*((volatile uint32_t *)(&(base->SM[id].FRACVAL##valRegIndex))))

/*!
 * @brief Set submodule register VALx and its FRAC value with 32bit access.
 *
 * @param base   PWM peripheral base address.
 * @param id     Submodule ID.
 * @param valRegIndex Value register index, range in 1~5.
 * @param value  32bit value for VALx and its FRAC.
 *               VALx: BIT16~BIT31.
 *               FRACVALx: BIT11~BIT15.
 *               RSVD: BIT10~BIT0.
 */
#define PWMLL_SM_SetValAndFrac(base, id, valRegIndex, value)                    \
    {                                                                           \
        *((volatile uint32_t *)(&(base->SM[id].FRACVAL##valRegIndex))) = value; \
    }

#endif /* defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U) */

/*!
 * @brief Get submodule register DTCNT0 value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The value of submodule register: DTCNT0.
 */
static inline uint16_t PWMLL_SM_GetDTCNT0(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    return base->SM[id].DTCNT0;
}

/*!
 * @brief Set submodule register DTCNT0 value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param value Setting value to register DTCNT0.
 */
static inline void PWMLL_SM_SetDTCNT0(PWM_Type *base, pwmll_sm_id_t id, uint16_t value)
{
    assert(base != NULL);
    base->SM[id].DTCNT0 = value;
}

/*!
 * @brief Get submodule register DTCNT1 value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The value of submodule register: DTCNT1.
 */
static inline uint16_t PWMLL_SM_GetDTCNT1(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    return base->SM[id].DTCNT1;
}

/*!
 * @brief Set submodule register DTCNT1 value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param value Setting value to register DTCNT1.
 */
static inline void PWMLL_SM_SetDTCNT1(PWM_Type *base, pwmll_sm_id_t id, uint16_t value)
{
    assert(base != NULL);
    base->SM[id].DTCNT1 = value;
}

/*!
 * @brief Get submodule capture value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Submodule pin ID.
 * @param capId Submodule capture module ID.
 *
 * @return The capture value indicated by pin and capId
 */
static inline uint16_t PWMLL_SM_GetCaptureValue(PWM_Type *base,
                                                pwmll_sm_id_t id,
                                                pwmll_sm_pin_id_t pin,
                                                pwmll_sm_cap_id_t capId)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL3;
        }
        else
        {
            return base->SM[id].CVAL2;
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL5;
        }
        else
        {
            return base->SM[id].CVAL4;
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL1;
        }
        else
        {
            return base->SM[id].CVAL0;
        }
    }
}

/*!
 * @brief Get submodule capture cycle value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Submodule pin ID.
 * @param capId Submodule capture module ID.
 *
 * @return The capture cycle value indicated by pin and capId
 */
static inline uint16_t PWMLL_SM_GetCaptureCycleValue(PWM_Type *base,
                                                     pwmll_sm_id_t id,
                                                     pwmll_sm_pin_id_t pin,
                                                     pwmll_sm_cap_id_t capId)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL3CYC;
        }
        else
        {
            return base->SM[id].CVAL2CYC;
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL5CYC;
        }
        else
        {
            return base->SM[id].CVAL4CYC;
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return base->SM[id].CVAL1CYC;
        }
        else
        {
            return base->SM[id].CVAL0CYC;
        }
    }
}

/*!
 * @brief Get submodule register PHASEDLY value.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The value of submodule register: PHASEDLY.
 */
static inline uint16_t PWMLL_SM_GetPHASEDLY(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    assert(id != kPWMLL_SM0_ID);
    return base->SM[id].PHASEDLY;
}

/*!
 * @brief Set submodule register PHASEDLY value.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param value Setting value to register PHASEDLY.
 */
static inline void PWMLL_SM_SetPHASEDLY(PWM_Type *base, pwmll_sm_id_t id, uint16_t value)
{
    assert(base != NULL);
    assert(id != kPWMLL_SM0_ID);
    base->SM[id].PHASEDLY = value;
}

/*!
 * @brief Config PWM output in debug mode.
 *
 * This function handles DBGEN bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigPWMOutputInDebugMode(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_DBGEN(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_DBGEN(1U);
    }
}

/*!
 * @brief Config PWM output in wait mode.
 *
 * This function handles WAITEN bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigPWMOutputInWaitMode(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_WAITEN(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_WAITEN(1U);
    }
}

/*!
 * @brief Config PWM pair mode.
 *
 * This function handles INDEP bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param mode  Setting pair mode.
 */
static inline void PWMLL_SM_ConfigPairMode(PWM_Type *base, pwmll_sm_id_t id, pwmll_pair_mode_t mode)
{
    assert(base != NULL);
    if (kPWMLL_PairMode_Independent == mode)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_INDEP(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_INDEP(1U);
    }
}

/*!
 * @brief Config PWM23 initial value.
 *
 * This function handles PWM23_INIT bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param init  Setting initial value.
 */
static inline void PWMLL_SM_ConfigPWM23InitValue(PWM_Type *base, pwmll_sm_id_t id, bool init)
{
    assert(base != NULL);
    if (init)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_PWM23_INIT(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_PWM23_INIT(1U);
    }
}

/*!
 * @brief Config PWM45 initial value.
 *
 * This function handles PWM45_INIT bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param init  Setting initial value.
 */
static inline void PWMLL_SM_ConfigPWM45InitValue(PWM_Type *base, pwmll_sm_id_t id, bool init)
{
    assert(base != NULL);
    if (init)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_PWM45_INIT(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_PWM45_INIT(1U);
    }
}

/*!
 * @brief Config PWMX initial value.
 *
 * This function handles PWMX_INIT bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param init  Setting initial value.
 */
static inline void PWMLL_SM_ConfigPWMXInitValue(PWM_Type *base, pwmll_sm_id_t id, bool init)
{
    assert(base != NULL);
    if (init)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_PWMX_INIT(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_PWMX_INIT(1U);
    }
}

/*!
 * @brief Config source of INIT signal.
 *
 * This function handles INIT_SEL bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param sel   Setting source for INIT signal.
 */
static inline void PWMLL_SM_ConfigSyncSource(PWM_Type *base, pwmll_sm_id_t id, pwmll_init_sel_t sel)
{
    assert(base != NULL);
    base->SM[id].CTRL2 = (base->SM[id].CTRL2 & (~PWM_CTRL2_INIT_SEL_MASK)) | PWM_CTRL2_INIT_SEL(sel);
}

/*!
 * @brief Config counter initialization when FORCE_OUT event.
 *
 * This function handles FRCEN bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param init  Enable or disable.
 */
static inline void PWMLL_SM_ConfigForceCNTandInitValue(PWM_Type *base, pwmll_sm_id_t id, bool init)
{
    assert(base != NULL);
    if (init)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_FRCEN(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_FRCEN(1U);
    }
}

/*!
 * @brief Generate a FORCE_OUT event.
 *
 * This function handles FORCE bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 */
static inline void PWMLL_SM_GenerateForceOutEvent(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    base->SM[id].CTRL2 |= PWM_CTRL2_FORCE(1U);
}

/*!
 * @brief Config source of FORCE_OUTPUT signal.
 *
 * This function handles FORCE_SEL bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param sel   Setting source for FORCE_OUT signal.
 */
static inline void PWMLL_SM_ConfigForceSource(PWM_Type *base, pwmll_sm_id_t id, pwmll_force_sel_t sel)
{
    assert(base != NULL);
    base->SM[id].CTRL2 = (base->SM[id].CTRL2 & (~PWM_CTRL2_FORCE_SEL_MASK)) | PWM_CTRL2_FORCE_SEL(sel);
}

/*!
 * @brief Config source of reload signal.
 *
 * This function handles RELOAD_SEL bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param sel   Setting source for reload signal.
 */
static inline void PWMLL_SM_ConfigReloadSource(PWM_Type *base, pwmll_sm_id_t id, pwmll_reload_sel_t sel)
{
    assert(base != NULL);
    if (kPWMLL_ReloadSel_Master == sel)
    {
        base->SM[id].CTRL2 |= PWM_CTRL2_RELOAD_SEL(1U);
    }
    else
    {
        base->SM[id].CTRL2 &= ~PWM_CTRL2_RELOAD_SEL(1U);
    }
}

/*!
 * @brief Config source of PWM clock.
 *
 * This function handles CLK_SEL bitfield for CTRL2 register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param sel   Setting source for clock.
 */
static inline void PWMLL_SM_ConfigClockSource(PWM_Type *base, pwmll_sm_id_t id, pwmll_clk_sel_t sel)
{
    assert(base != NULL);
    base->SM[id].CTRL2 = (base->SM[id].CTRL2 & (~PWM_CTRL2_CLK_SEL_MASK)) | PWM_CTRL2_CLK_SEL(sel);
}

/*!
 * @brief Config reload frequency.
 *
 * This function handles LDFQ bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param config  Setting reload frequency.
 */
static inline void PWMLL_SM_ConfigReLoadFrequency(PWM_Type *base, pwmll_sm_id_t id, pwmll_load_freq_t config)
{
    assert(base != NULL);
    base->SM[id].CTRL = (base->SM[id].CTRL & (~PWM_CTRL_LDFQ_MASK)) | PWM_CTRL_LDFQ(config);
}

/*!
 * @brief Config reload at half cycle.
 *
 * This function handles HALF bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigHalfCycleReload(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL |= PWM_CTRL_HALF(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_HALF(1U);
    }
}

/*!
 * @brief Config reload at full cycle.
 *
 * This function handles FULL bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigFullCycleReload(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL |= PWM_CTRL_FULL(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_FULL(1U);
    }
}

/*!
 * @brief Get PWMX value at end of dead time.
 *
 * This function handles DT bitfield for CTRL register
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 *
 * @return The DT bitfield at bit0 ~ bit1.
 */
static inline uint8_t PWMLL_SM_GetPWMXValueAtEndofDeadTime(PWM_Type *base, pwmll_sm_id_t id)
{
    assert(base != NULL);
    return (base->SM[id].CTRL & PWM_CTRL_DT_MASK) >> PWM_CTRL_DT_SHIFT;
}

/*!
 * @brief Config comparison mode.
 *
 * This function handles COMPMODE bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param mode  Setting for comparison mode.
 */
static inline void PWMLL_SM_ConfigComparisonMode(PWM_Type *base, pwmll_sm_id_t id, pwmll_comp_mode_t mode)
{
    assert(base != NULL);
    if (kPWMLL_CompMode_EqualOrGreater == mode)
    {
        base->SM[id].CTRL |= PWM_CTRL_COMPMODE(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_COMPMODE(1U);
    }
}

/*!
 * @brief Config clock prescale value.
 *
 * This function handles PRSC bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param config  Setting value for clock prescale.
 */
static inline void PWMLL_SM_ConfigClockPrescaler(PWM_Type *base, pwmll_sm_id_t id, pwmll_clk_prescaler_t config)
{
    assert(base != NULL);
    base->SM[id].CTRL = (base->SM[id].CTRL & (~PWM_CTRL_PRSC_MASK)) | PWM_CTRL_PRSC(config);
}

/*!
 * @brief Config the DBLPWM split mode.
 *
 * This function handles SPLIT bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigSplitPWMSignal(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL |= PWM_CTRL_SPLIT(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_SPLIT(1U);
    }
}

/*!
 * @brief Config the buffered register load mode.
 *
 * This function handles LDMOD bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param mode  Setting for load mode of buffered register.
 */
static inline void PWMLL_SM_ConfigRegLoadMode(PWM_Type *base, pwmll_sm_id_t id, pwmll_load_mode_t mode)
{
    assert(base != NULL);
    if (kPWMLL_LoadMode_Immediately == mode)
    {
        base->SM[id].CTRL |= PWM_CTRL_LDMOD(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_LDMOD(1U);
    }
}

/*!
 * @brief Config the PWMX double switching mode.
 *
 * This function handles DBLX bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigPWMXDoubleSwitching(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL |= PWM_CTRL_DBLX(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_DBLX(1U);
    }
}

/*!
 * @brief Config the double switching mode.
 *
 * This function handles DBLEN bitfield for CTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigDoubleSwitching(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].CTRL |= PWM_CTRL_DBLEN(1U);
    }
    else
    {
        base->SM[id].CTRL &= ~PWM_CTRL_DBLEN(1U);
    }
}

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U))

/*!
 * @brief Config the fractional circuit power.
 *
 * This function handles FRAC_UP bitfield for FRCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigFracCircuitPowerUp(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].FRCTRL |= PWM_FRCTRL_FRAC_PU(1U);
    }
    else
    {
        base->SM[id].FRCTRL &= ~PWM_FRCTRL_FRAC_PU(1U);
    }
}

/*!
 * @brief Config the fractional cycle placement for PWM_B.
 *
 * This function handles FRAC45_EN bitfield for FRCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigFracOnPWMB(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].FRCTRL |= PWM_FRCTRL_FRAC45_EN(1U);
    }
    else
    {
        base->SM[id].FRCTRL &= ~PWM_FRCTRL_FRAC45_EN(1U);
    }
}

/*!
 * @brief Config the fractional cycle placement for PWM_A.
 *
 * This function handles FRAC23_EN bitfield for FRCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigFracOnPWMA(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].FRCTRL |= PWM_FRCTRL_FRAC23_EN(1U);
    }
    else
    {
        base->SM[id].FRCTRL &= ~PWM_FRCTRL_FRAC23_EN(1U);
    }
}

/*!
 * @brief Config the fractional cycle placement for PWM period.
 *
 * This function handles FRAC1_EN bitfield for FRCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_ConfigFracOnPWMPeriod(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].FRCTRL |= PWM_FRCTRL_FRAC1_EN(1U);
    }
    else
    {
        base->SM[id].FRCTRL &= ~PWM_FRCTRL_FRAC1_EN(1U);
    }
}

#endif /* defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U) */

/*!
 * @brief Get the logic value being driven into PWM_x input.
 *
 * This function handles PWMx_IN bitfield for OCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Pin ID.
 *
 * @return The logic value currently being driven into PWM_x input.
 */
static inline bool PWMLL_SM_GetPWMPinStatus(PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin)
{
    assert(base != NULL);
    return (bool)((base->SM[id].OCTRL & (1U << (13U + ((uint16_t)pin)))) >> (13U + ((uint16_t)pin)));
}

/*!
 * @brief Config the PWM pin output polarity.
 *
 * This function handles POLx bitfield for OCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Pin ID.
 * @param pol   Setting polarity.
 */
static inline void PWMLL_SM_ConfigPWMPinPolarity(PWM_Type *base,
                                                 pwmll_sm_id_t id,
                                                 pwmll_sm_pin_id_t pin,
                                                 pwmll_output_polarity_t pol)
{
    assert(base != NULL);
    if (kPWMLL_OutputPolarity_Inverted == pol)
    {
        base->SM[id].OCTRL |= 1U << (8U + ((uint16_t)pin));
    }
    else
    {
        base->SM[id].OCTRL &= ~(1U << (8U + ((uint16_t)pin)));
    }
}

/*!
 * @brief Config the PWM_x output state during fault conditions and STOP mode.
 *
 * This function handles PWMxFS bitfield for OCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Pin ID.
 * @param state Setting state.
 */
static inline void PWMLL_SM_ConfigPWMPinFaultState(PWM_Type *base,
                                                   pwmll_sm_id_t id,
                                                   pwmll_sm_pin_id_t pin,
                                                   pwmll_fault_state_t state)
{
    assert(base != NULL);
    base->SM[id].OCTRL =
        (base->SM[id].OCTRL & (~(3U << (2U * ((uint16_t)pin))))) | (((uint16_t)state) << (2U * ((uint16_t)pin)));
}

/*!
 * @brief Get the flag state.
 *
 * This function handles each bitfield for STS register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param flagMask  Flag mask.
 *
 * @return The logic value of designated flag.
 */
static inline bool PWMLL_SM_CheckInterruptFlag(PWM_Type *base, pwmll_sm_id_t id, pwmll_int_mask_t flagMask)
{
    assert(base != NULL);
    if (0U != (base->SM[id].STS & flagMask))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Get the flag state.
 *
 * This function handles designated bitfield for STS register.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param flagMasks  Flag mask, should be combination of pwmll_int_mask_t member.
 *
 * @return Value combination of designated flags.
 */
static inline uint16_t PWMLL_SM_GetInterruptFlag(PWM_Type *base, pwmll_sm_id_t id, uint16_t flagMasks)
{
    assert(base != NULL);
    return base->SM[id].STS & flagMasks;
}

/*!
 * @brief Clear interrupt flags.
 *
 * This function handles designated bitfield for STS register.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param flagMasks  Flag mask, should be combination of pwmll_int_mask_t member.
 */
static inline bool PWMLL_SM_ClearInterruptFlags(PWM_Type *base, pwmll_sm_id_t id, uint16_t flagMasks)
{
    assert(base != NULL);
    base->SM[id].STS = flagMasks;
}

/*!
 * @brief Enable/Disable interrupt.
 *
 * This function handles designated bitfield for INTEN register.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param intMasks  interrupt masks, should be combination of pwmll_int_mask_t member other than
 * kPWMLL_INT_RegisterUpdatedMask.
 * @param en Enable or disable.
 */
static inline void PWMLL_SM_EnableInterrupt(PWM_Type *base, pwmll_sm_id_t id, uint16_t intMasks, bool en)
{
    assert(base != NULL);
    assert(0U == (intMasks & ((uint16_t)kPWMLL_INT_RegisterUpdatedMask)));
    if (en)
    {
        base->SM[id].INTEN |= intMasks;
    }
    else
    {
        base->SM[id].INTEN &= ~intMasks;
    }
}

/*!
 * @brief Enable/Disable DMA for value register.
 *
 * This function handles VALDE bitfield for DMAEN register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_EnableValueRegisterDMA(PWM_Type *base, pwmll_sm_id_t id, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].DMAEN |= PWM_DMAEN_VALDE(1U);
    }
    else
    {
        base->SM[id].DMAEN &= ~PWM_DMAEN_VALDE(1U);
    }
}

/*!
 * @brief Config FIFO watermark mode.
 *
 * This function handles FAND bitfield for DMAEN register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param mode  Setting FIFO watermark mode.
 */
static inline void PWMLL_SM_ConfigFIFOWatermarkMode(PWM_Type *base, pwmll_sm_id_t id, pwmll_fifo_watermark_mode_t mode)
{
    assert(base != NULL);
    if (kPWMLL_FifoWatermarkMode_And == mode)
    {
        base->SM[id].DMAEN |= PWM_DMAEN_FAND(1U);
    }
    else
    {
        base->SM[id].DMAEN &= ~PWM_DMAEN_FAND(1U);
    }
}

/*!
 * @brief Config capture DMA enable and source.
 *
 * This function handles CAPTDE bitfield for DMAEN register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param src   Setting capture DMA enable and source.
 */
static inline void PWMLL_SM_ConfigCaptureDMASource(PWM_Type *base, pwmll_sm_id_t id, pwmll_capture_dma_src_t src)
{
    assert(base != NULL);
    base->SM[id].DMAEN = (base->SM[id].DMAEN & (~PWM_DMAEN_CAPTDE_MASK)) | PWM_DMAEN_CAPTDE(src);
}

/*!
 * @brief Enable/Disable DMA for pin and capture combination.
 *
 * This function handles CxxDE bitfield for DMAEN register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param pin   Pin ID.
 * @param capId Capture ID.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_EnableCaptureFIFODMA(
    PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin, pwmll_sm_cap_id_t capId, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].DMAEN |= (1U << (((uint16_t)pin) * 2U + ((uint16_t)capId)));
    }
    else
    {
        base->SM[id].DMAEN &= ~(1U << (((uint16_t)pin) * 2U + ((uint16_t)capId)));
    }
}

/*!
 * @brief Config source for mux output trigger 0.
 *
 * This function handles PWAOT0 bitfield for TCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param src   Setting source for mux output trigger 0.
 */
static inline void PWMLL_SM_ConfigMuxOutputTrigger0Source(PWM_Type *base,
                                                          pwmll_sm_id_t id,
                                                          pwmll_mux_output_trigger_0_src_t src)
{
    assert(base != NULL);
    if (kPWMLL_MuxOutputTrigger0Src_PwmA == src)
    {
        base->SM[id].TCTRL |= PWM_TCTRL_PWAOT0(1U);
    }
    else
    {
        base->SM[id].TCTRL &= ~PWM_TCTRL_PWAOT0(1U);
    }
}

/*!
 * @brief Config source for mux output trigger 1.
 *
 * This function handles PWBOT1 bitfield for TCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param src   Setting source for mux output trigger 1.
 */
static inline void PWMLL_SM_ConfigMuxOutputTrigger1Source(PWM_Type *base,
                                                          pwmll_sm_id_t id,
                                                          pwmll_mux_output_trigger_1_src_t src)
{
    assert(base != NULL);
    if (kPWMLL_MuxOutputTrigger1Src_PwmB == src)
    {
        base->SM[id].TCTRL |= PWM_TCTRL_PWBOT1(1U);
    }
    else
    {
        base->SM[id].TCTRL &= ~PWM_TCTRL_PWBOT1(1U);
    }
}

/*!
 * @brief Config trigger frequency.
 *
 * This function handles TRGFRQ bitfield for TCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param freq  Setting trigger frequency.
 */
static inline void PWMLL_SM_ConfigTriggerFrequency(PWM_Type *base, pwmll_sm_id_t id, pwmll_trigger_freq_t freq)
{
    assert(base != NULL);
    if (kPWMLL_TriggerFreq_EveryReload == freq)
    {
        base->SM[id].TCTRL |= PWM_TCTRL_TRGFRQ(1U);
    }
    else
    {
        base->SM[id].TCTRL &= ~PWM_TCTRL_TRGFRQ(1U);
    }
}

/*!
 * @brief Enable/Disable trigger output when counter value matches VALx value.
 *
 * This function handles OUT_TRIG_EN bitfield for TCTRL register
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param mask  VAL register mask.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_EnableValueRegMatchTriggerOutput(PWM_Type *base,
                                                             pwmll_sm_id_t id,
                                                             pwmll_val_reg_mask_t mask,
                                                             bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->SM[id].TCTRL |= PWM_TCTRL_OUT_TRIG_EN(mask);
    }
    else
    {
        base->SM[id].TCTRL &= ~PWM_TCTRL_OUT_TRIG_EN(mask);
    }
}

/*!
 * @brief Enable/Disable maps between PWM_x pin and fault inputs.
 *
 * This function handles DISxx bitfield for DISMAPx register.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param fault Fault channel ID.
 * @param pin   Pin ID.
 * @param input Fault input ID, should be combination of pwmll_fault_input_t member.
 * @param en    Enable or disable.
 */
static inline void PWMLL_SM_EnableMapBetweenPWMandFaultInput(
    PWM_Type *base, pwmll_sm_id_t id, pwmll_fault_channel_t fault, pwmll_sm_pin_id_t pin, uint16_t input, bool en)
{
    assert(base != NULL);
    assert(input <= (uint16_t)kPWMLL_FaultInputCombine);
    if (en)
    {
        base->SM[id].DISMAP[(uint8_t)fault] |= input << ((2U - (uint16_t)pin) * 4U);
    }
    else
    {
        base->SM[id].DISMAP[(uint8_t)fault] &= ~(input << ((2U - (uint16_t)pin) * 4U));
    }
}

/*!
 * @brief Disable all maps between PWM_x pin and fault inputs.
 *
 * This function handles DISMAPx register.
 *
 * @param base  PWM peripheral base address.
 * @param id    Submodule ID.
 * @param fault Fault channel ID.
 */
static inline void PWMLL_SM_DisableAllMapBetweenPWMandFaultInput(PWM_Type *base,
                                                                 pwmll_sm_id_t id,
                                                                 pwmll_fault_channel_t fault)
{
    base->SM[id].DISMAP[(uint8_t)fault] = 0x0U;
}

/*!
 * @brief Get capture FIFO count.
 *
 * This function handles CxxCNT bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param capId Capture ID.
 *
 * @return The value of designated pin and capture.
 */
static inline uint8_t PWMLL_SM_GetCaptureFifoCount(PWM_Type *base,
                                                   pwmll_sm_id_t id,
                                                   pwmll_sm_pin_id_t pin,
                                                   pwmll_sm_cap_id_t capId)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return (base->SM[id].CAPTCTRLA & PWM_CAPTCTRLA_CA1CNT_MASK) >> PWM_CAPTCTRLA_CA1CNT_SHIFT;
        }
        else
        {
            return (base->SM[id].CAPTCTRLA & PWM_CAPTCTRLA_CA0CNT_MASK) >> PWM_CAPTCTRLA_CA0CNT_SHIFT;
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return (base->SM[id].CAPTCTRLB & PWM_CAPTCTRLB_CB1CNT_MASK) >> PWM_CAPTCTRLB_CB1CNT_SHIFT;
        }
        else
        {
            return (base->SM[id].CAPTCTRLB & PWM_CAPTCTRLB_CB0CNT_MASK) >> PWM_CAPTCTRLB_CB0CNT_SHIFT;
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            return (base->SM[id].CAPTCTRLX & PWM_CAPTCTRLX_CX1CNT_MASK) >> PWM_CAPTCTRLX_CX1CNT_SHIFT;
        }
        else
        {
            return (base->SM[id].CAPTCTRLX & PWM_CAPTCTRLX_CX0CNT_MASK) >> PWM_CAPTCTRLX_CX0CNT_SHIFT;
        }
    }
}

/*!
 * @brief Configure FIFO watermark for capture.
 *
 * This function handles CFxWM bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param wm   Setting watermark.
 */
static inline void PWMLL_SM_ConfigCaptureFifoWatermark(PWM_Type *base,
                                                       pwmll_sm_id_t id,
                                                       pwmll_sm_pin_id_t pin,
                                                       uint8_t wm)
{
    assert(base != NULL);
    assert(wm < PWMLL_CAPTURE_FIFO_DEPTH);
    if (kPWMLL_SMPinId_A == pin)
    {
        base->SM[id].CAPTCTRLA = (base->SM[id].CAPTCTRLA & (~PWM_CAPTCTRLA_CFAWM_MASK)) | PWM_CAPTCTRLA_CFAWM(wm);
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        base->SM[id].CAPTCTRLB = (base->SM[id].CAPTCTRLB & (~PWM_CAPTCTRLB_CFBWM_MASK)) | PWM_CAPTCTRLB_CFBWM(wm);
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        base->SM[id].CAPTCTRLX = (base->SM[id].CAPTCTRLX & (~PWM_CAPTCTRLX_CFXWM_MASK)) | PWM_CAPTCTRLX_CFXWM(wm);
    }
}

/*!
 * @brief Enable/Disable edge counter for PWM input.
 *
 * This function handles EDGCNTx_EN bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_SM_EnableEdgeCounterForCaptureInput(PWM_Type *base,
                                                             pwmll_sm_id_t id,
                                                             pwmll_sm_pin_id_t pin,
                                                             bool en)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLA |= PWM_CAPTCTRLA_EDGCNTA_EN(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLA &= ~PWM_CAPTCTRLA_EDGCNTA_EN(1U);
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLB |= PWM_CAPTCTRLB_EDGCNTB_EN(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLB &= ~PWM_CAPTCTRLB_EDGCNTB_EN(1U);
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (en)
        {
            base->SM[id].CAPTCTRLX |= PWM_CAPTCTRLX_EDGCNTX_EN(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLX &= ~PWM_CAPTCTRLX_EDGCNTX_EN(1U);
        }
    }
}

/*!
 * @brief Configure capture input source.
 *
 * This function handles INP_SELx bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param src  Setting source for capture input.
 */
static inline void PWMLL_SM_ConfigCaptureInputSource(PWM_Type *base,
                                                     pwmll_sm_id_t id,
                                                     pwmll_sm_pin_id_t pin,
                                                     pwmll_cap_input_src_t src)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (kPWMLL_CapInputSrc_EdgeCounter == src)
        {
            base->SM[id].CAPTCTRLA |= PWM_CAPTCTRLA_INP_SELA(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLA &= ~PWM_CAPTCTRLA_INP_SELA(1U);
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (kPWMLL_CapInputSrc_EdgeCounter == src)
        {
            base->SM[id].CAPTCTRLB |= PWM_CAPTCTRLB_INP_SELB(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLB &= ~PWM_CAPTCTRLB_INP_SELB(1U);
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (kPWMLL_CapInputSrc_EdgeCounter == src)
        {
            base->SM[id].CAPTCTRLX |= PWM_CAPTCTRLX_INP_SELX(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLX &= ~PWM_CAPTCTRLX_INP_SELX(1U);
        }
    }
}

/*!
 * @brief Configure capture input edge mode.
 *
 * This function handles EDGxx bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param capId Capture ID.
 * @param mode Setting edge mode.
 */
static inline void PWMLL_SM_ConfigCaptureInputEdgeMode(
    PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin, pwmll_sm_cap_id_t capId, pwmll_cap_edge_mode_t mode)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            base->SM[id].CAPTCTRLA = (base->SM[id].CAPTCTRLA & (~PWM_CAPTCTRLA_EDGA1_MASK)) | PWM_CAPTCTRLA_EDGA1(mode);
        }
        else
        {
            base->SM[id].CAPTCTRLA = (base->SM[id].CAPTCTRLA & (~PWM_CAPTCTRLA_EDGA0_MASK)) | PWM_CAPTCTRLA_EDGA0(mode);
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            base->SM[id].CAPTCTRLB = (base->SM[id].CAPTCTRLB & (~PWM_CAPTCTRLB_EDGB1_MASK)) | PWM_CAPTCTRLB_EDGB1(mode);
        }
        else
        {
            base->SM[id].CAPTCTRLB = (base->SM[id].CAPTCTRLB & (~PWM_CAPTCTRLB_EDGB0_MASK)) | PWM_CAPTCTRLB_EDGB0(mode);
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (kPWMLL_SMCapId_1 == capId)
        {
            base->SM[id].CAPTCTRLX = (base->SM[id].CAPTCTRLX & (~PWM_CAPTCTRLX_EDGX1_MASK)) | PWM_CAPTCTRLX_EDGX1(mode);
        }
        else
        {
            base->SM[id].CAPTCTRLX = (base->SM[id].CAPTCTRLX & (~PWM_CAPTCTRLX_EDGX0_MASK)) | PWM_CAPTCTRLX_EDGX0(mode);
        }
    }
}

/*!
 * @brief Enable/Disable oneshot mdoe for capture.
 *
 * This function handles ONESHOTx bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_SM_EnableCaptureOneShotMode(PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin, bool en)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLA |= PWM_CAPTCTRLA_ONESHOTA(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLA &= ~PWM_CAPTCTRLA_ONESHOTA(1U);
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLB |= PWM_CAPTCTRLB_ONESHOTB(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLB &= ~PWM_CAPTCTRLB_ONESHOTB(1U);
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (en)
        {
            base->SM[id].CAPTCTRLX |= PWM_CAPTCTRLX_ONESHOTX(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLX &= ~PWM_CAPTCTRLX_ONESHOTX(1U);
        }
    }
}

/*!
 * @brief Enable/Disable capture.
 *
 * This function handles ARMx bit filed of CAPTCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_SM_EnableCapture(PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin, bool en)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLA |= PWM_CAPTCTRLA_ARMA(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLA &= ~PWM_CAPTCTRLA_ARMA(1U);
        }
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        if (en)
        {
            base->SM[id].CAPTCTRLB |= PWM_CAPTCTRLB_ARMB(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLB &= ~PWM_CAPTCTRLB_ARMB(1U);
        }
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        if (en)
        {
            base->SM[id].CAPTCTRLX |= PWM_CAPTCTRLX_ARMX(1U);
        }
        else
        {
            base->SM[id].CAPTCTRLX &= ~PWM_CAPTCTRLX_ARMX(1U);
        }
    }
}

/*!
 * @brief Get capture edge counter value.
 *
 * This function handles EDGCNTx bit filed of CAPTCOMPx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 *
 * @return The value of edge counter.
 */
static inline uint16_t PWMLL_SM_GetCaptureCounter(PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        return (base->SM[id].CAPTCOMPA & PWM_CAPTCOMPA_EDGCNTA_MASK) >> PWM_CAPTCOMPA_EDGCNTA_SHIFT;
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        return (base->SM[id].CAPTCOMPB & PWM_CAPTCOMPB_EDGCNTB_MASK) >> PWM_CAPTCOMPB_EDGCNTB_SHIFT;
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        return (base->SM[id].CAPTCOMPX & PWM_CAPTCOMPX_EDGCNTX_MASK) >> PWM_CAPTCOMPX_EDGCNTX_SHIFT;
    }
}

/*!
 * @brief Get capture edge compare value.
 *
 * This function handles EDGCMPx bit filed of CAPTCOMPx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 *
 * @return The value of edge compare.
 */
static inline uint16_t PWMLL_SM_GetCaptureCompareValue(PWM_Type *base, pwmll_sm_id_t id, pwmll_sm_pin_id_t pin)
{
    assert(base != NULL);
    if (kPWMLL_SMPinId_A == pin)
    {
        return (base->SM[id].CAPTCOMPA & PWM_CAPTCOMPA_EDGCMPA_MASK) >> PWM_CAPTCOMPA_EDGCMPA_SHIFT;
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        return (base->SM[id].CAPTCOMPB & PWM_CAPTCOMPB_EDGCMPB_MASK) >> PWM_CAPTCOMPB_EDGCMPB_SHIFT;
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        return (base->SM[id].CAPTCOMPX & PWM_CAPTCOMPX_EDGCMPX_MASK) >> PWM_CAPTCOMPX_EDGCMPX_SHIFT;
    }
}

/*!
 * @brief Set capture edge compare value.
 *
 * This function handles EDGCMPx bit filed of CAPTCOMPx register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param pin  Pin ID.
 * @param value Setting edge compare value.
 */
static inline void PWMLL_SM_SetCaptureCompareValue(PWM_Type *base,
                                                   pwmll_sm_id_t id,
                                                   pwmll_sm_pin_id_t pin,
                                                   uint16_t value)
{
    assert(base != NULL);
    assert(value <= PWMLL_CAPTURE_EDGE_COMPARE_MAX);
    if (kPWMLL_SMPinId_A == pin)
    {
        base->SM[id].CAPTCOMPA = PWM_CAPTCOMPA_EDGCMPA(value);
    }
    else if (kPWMLL_SMPinId_B == pin)
    {
        base->SM[id].CAPTCOMPB = PWM_CAPTCOMPB_EDGCMPB(value);
    }
    else /* if(kPWMLL_SMPinId_X == pin) */
    {
        base->SM[id].CAPTCOMPX = PWM_CAPTCOMPX_EDGCMPX(value);
    }
}

/*!
 * @brief Enable/Disable pin output.
 *
 * This function handles PWMx_EN bit filed of OUTEN register.
 *
 * @param base PWM peripheral base address.
 * @param mask Submodule mask.
 * @param pin  Pin ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_EnablePWMOutput(PWM_Type *base, pwmll_sm_mask_t mask, pwmll_sm_pin_id_t pin, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->OUTEN |= ((uint16_t)mask) << (4U * ((uint16_t)pin));
    }
    else
    {
        base->OUTEN &= ~(((uint16_t)mask) << (4U * ((uint16_t)pin)));
    }
}

/*!
 * @brief Enable/Disable pin combination output.
 *
 * This function handles PWMx_EN bit filed of OUTEN register.
 *
 * @param base PWM peripheral base address.
 * @param Amasks Submodule mask for PWMA, should be combination of pwmll_sm_mask_t member.
 * @param Bmasks Submodule mask for PWMB, should be combination of pwmll_sm_mask_t member.
 * @param Xmasks Submodule mask for PWMX, should be combination of pwmll_sm_mask_t member.
 * @param en Enable or disable.
 */
static inline void PWMLL_EnableCombinedPWMOutput(
    PWM_Type *base, uint16_t Amasks, uint16_t Bmasks, uint16_t Xmasks, bool en)
{
    assert(base != NULL);
    assert(Amasks <= kPWMLL_SM_MaskComp);
    assert(Bmasks <= kPWMLL_SM_MaskComp);
    assert(Xmasks <= kPWMLL_SM_MaskComp);
    if (en)
    {
        base->OUTEN |= PWM_OUTEN_PWMA_EN(Amasks) | PWM_OUTEN_PWMB_EN(Bmasks) | PWM_OUTEN_PWMX_EN(Xmasks);
    }
    else
    {
        base->OUTEN &= ~(PWM_OUTEN_PWMA_EN(Amasks) | PWM_OUTEN_PWMB_EN(Bmasks) | PWM_OUTEN_PWMX_EN(Xmasks));
    }
}

/*!
 * @brief Update MASKx bitfield in MASK register immediately.
 *
 * This function handles UPDATE_MASK bit filed of MASK register.
 *
 * @param base PWM peripheral base address.
 * @param masks Submodule mask, should be combination of pwmll_sm_mask_t member.
 */
static inline void PWMLL_UpdateMaskBitsImmediately(PWM_Type *base, uint16_t masks)
{
    assert(base != NULL);
    assert(masks <= kPWMLL_SM_MaskComp);
    base->MASK |= PWM_MASK_UPDATE_MASK(masks);
}

/*!
 * @brief Mask/Unmask PWMx signal output.
 *
 * This function handles MASKx bit filed of MASK register.
 *
 * @param base PWM peripheral base address.
 * @param mask Submodule mask.
 * @param pin  Pin ID.
 * @param en   Mask or unmask.
 */
static inline void PWMLL_MaskPWMOutput(PWM_Type *base, pwmll_sm_mask_t mask, pwmll_sm_pin_id_t pin, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->MASK |= ((uint16_t)mask) << (4U * ((uint16_t)pin));
    }
    else
    {
        base->MASK &= ~(((uint16_t)mask) << (4U * ((uint16_t)pin)));
    }
}

/*!
 * @brief Mask/Unmask PWMA/B/X combination signal output.
 *
 * This function handles MASKx bit filed of MASK register.
 *
 * @param base PWM peripheral base address.
 * @param Amasks Submodule mask for PWMA, should be combination of pwmll_sm_mask_t member.
 * @param Bmasks Submodule mask for PWMB, should be combination of pwmll_sm_mask_t member.
 * @param Xmasks Submodule mask for PWMX, should be combination of pwmll_sm_mask_t member.
 * @param en Mask or unmask.
 */
static inline void PWMLL_MaskCombinedPWMOutput(
    PWM_Type *base, uint16_t Amasks, uint16_t Bmasks, uint16_t Xmasks, bool en)
{
    assert(base != NULL);
    assert(Amasks <= kPWMLL_SM_MaskComp);
    assert(Bmasks <= kPWMLL_SM_MaskComp);
    assert(Xmasks <= kPWMLL_SM_MaskComp);
    if (en)
    {
        base->MASK |= PWM_MASK_MASKA(Amasks) | PWM_MASK_MASKB(Bmasks) | PWM_MASK_MASKX(Xmasks);
    }
    else
    {
        base->MASK &= ~(PWM_MASK_MASKA(Amasks) | PWM_MASK_MASKB(Bmasks) | PWM_MASK_MASKX(Xmasks));
    }
}

/*!
 * @brief Configure PWM23 software logic value to dead time generator.
 *
 * This function handles SMxOUT23 bit filed of SWCOUT register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param value Setting software logic value.
 */
static inline void PWMLL_SM_ConfigPWM23SWLogicValueToDeadtimeGenerator(PWM_Type *base, pwmll_sm_id_t id, bool value)
{
    assert(base != NULL);
    if (value)
    {
        base->SWCOUT |= 1U << ((((uint16_t)id) * 2U) + 1U);
    }
    else
    {
        base->SWCOUT &= ~(1U << ((((uint16_t)id) * 2U) + 1U));
    }
}

/*!
 * @brief Configure PWM45 software logic value to dead time generator.
 *
 * This function handles SMxOUT45 bit filed of SWCOUT register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param value Setting software logic value.
 */
static inline void PWMLL_SM_ConfigPWM45SWLogicValueToDeadtimeGenerator(PWM_Type *base, pwmll_sm_id_t id, bool value)
{
    assert(base != NULL);
    if (value)
    {
        base->SWCOUT |= 1U << (((uint16_t)id) * 2U);
    }
    else
    {
        base->SWCOUT &= ~(1U << ((((uint16_t)id) * 2U)));
    }
}

/*!
 * @brief Configure source for dead time generator PWM23 signal.
 *
 * This function handles SMxSEL23 bit filed of DTSRCSEL register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param src  Setting source for dead time generator PWM23 signal.
 */
static inline void PWMLL_SM_ConfigDeadtimeGeneratorPWM23Source(PWM_Type *base,
                                                               pwmll_sm_id_t id,
                                                               pwmll_deadtime_pwm23_source_t src)
{
    assert(base != NULL);
    base->DTSRCSEL =
        (base->DTSRCSEL & (~(3U << ((((uint16_t)id) * 4U) + 2U)))) | (((uint16_t)src) << ((((uint16_t)id) * 4U) + 2U));
}

/*!
 * @brief Configure source for dead time generator PWM45 signal.
 *
 * This function handles SMxSEL45 bit filed of DTSRCSEL register.
 *
 * @param base PWM peripheral base address.
 * @param id   Submodule ID.
 * @param src  Setting source for dead time generator PWM45 signal.
 */
static inline void PWMLL_SM_ConfigDeadtimeGeneratorPWM45Source(PWM_Type *base,
                                                               pwmll_sm_id_t id,
                                                               pwmll_deadtime_pwm45_source_t src)
{
    assert(base != NULL);
    base->DTSRCSEL =
        (base->DTSRCSEL & (~(3U << ((((uint16_t)id) * 4U))))) | (((uint16_t)src) << ((((uint16_t)id) * 4U)));
}

/*!
 * @brief Set PWM45 to generate complementary PWM pair.
 *
 * This function handles IPOL bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param mask Submodule mask.
 */
static inline void PWMLL_UsePWM45ForComplementaryOutput(PWM_Type *base, pwmll_sm_mask_t mask)
{
    assert(base != NULL);
    base->MCTRL |= PWM_MCTRL_IPOL(mask);
}

/*!
 * @brief Set PWM23 to generate complementary PWM pair.
 *
 * This function handles IPOL bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param mask Submodule mask.
 */
static inline void PWMLL_UsePWM23ForComplementaryOutput(PWM_Type *base, pwmll_sm_mask_t mask)
{
    assert(base != NULL);
    base->MCTRL &= ~PWM_MCTRL_IPOL(mask);
}

/*!
 * @brief Enable/Disable PWM submodule.
 *
 * This function handles RUN bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param masks Submodule mask, should be combination of pwmll_sm_mask_t member.
 * @param en Enable or disable.
 */
static inline void PWMLL_EnablePWMRun(PWM_Type *base, uint16_t masks, bool en)
{
    assert(base != NULL);
    assert(masks <= kPWMLL_SM_MaskComp);
    if (en)
    {
        base->MCTRL |= PWM_MCTRL_RUN(masks);
    }
    else
    {
        base->MCTRL &= ~PWM_MCTRL_RUN(masks);
    }
}

/*!
 * @brief Get PWM submodule running status.
 *
 * This function handles RUN bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param mask Submodule mask.
 *
 * @return The submodule running status.
 */
static inline bool PWMLL_GetPWMRunStatus(PWM_Type *base, pwmll_sm_mask_t mask)
{
    assert(base != NULL);
    if (0U != (base->MCTRL & PWM_MCTRL_RUN(mask)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Clear load OK for PWM submodule buffered registers.
 *
 * This function handles CLDOK bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param masks Submodule mask, should be combination of pwmll_sm_mask_t member.
 */
static inline void PWMLL_ClearLoadOkay(PWM_Type *base, uint16_t masks)
{
    assert(base != NULL);
    assert(masks <= kPWMLL_SM_MaskComp);
    base->MCTRL |= PWM_MCTRL_CLDOK(masks);
}

/*!
 * @brief Set load OK for PWM submodule buffered registers.
 *
 * This function handles CLDOK bit filed of MCTRL register.
 *
 * @param base PWM peripheral base address.
 * @param masks Submodule mask, should be combination of pwmll_sm_mask_t member.
 */
static inline void PWMLL_SetLoadOkay(PWM_Type *base, uint16_t masks)
{
    assert(base != NULL);
    assert(masks <= kPWMLL_SM_MaskComp);
    base->MCTRL |= PWM_MCTRL_LDOK(masks);
}

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U))
/*!
 * @brief Configure PLL monitor state.
 *
 * This function handles MONPLL bit filed of MCTRL2 register.
 *
 * @param base PWM peripheral base address.
 * @param mode Setting PLL monitor state.
 */
static inline void PWMLL_ConfigPLLMonitorMode(PWM_Type *base, pwmll_pll_monitor_mode_t mode)
{
    assert(base != NULL);
    base->MCTRL2 = (base->MCTRL2 & (~PWM_MCTRL2_MONPLL_MASK)) | PWM_MCTRL2_MONPLL(mode);
}
#endif /* defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U) */

/*!
 * @brief Configure fault input effective logic value.
 *
 * This function handles FLVL bit filed of FCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param logicValue Setting logic value.
 */
static inline void PWMLL_ConfigFaultInputEffectiveValue(PWM_Type *base,
                                                        pwmll_fault_channel_t ch,
                                                        pwmll_fault_input_t input,
                                                        bool logicValue)
{
    assert(base != NULL);
    if (logicValue)
    {
        base->FAULT[(uint8_t)ch].FCTRL |= PWM_FCTRL_FLVL(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FCTRL &= ~PWM_FCTRL_FLVL(input);
    }
}

/*!
 * @brief Enable/Disable automatic fault clearing.
 *
 * This function handles FAUTO bit filed of FCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en Enable or disable.
 */
static inline void PWMLL_EnableAutoFaultClearing(PWM_Type *base,
                                                 pwmll_fault_channel_t ch,
                                                 pwmll_fault_input_t input,
                                                 bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FCTRL |= PWM_FCTRL_FAUTO(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FCTRL &= ~PWM_FCTRL_FAUTO(input);
    }
}

/*!
 * @brief Enable/Disable fault safety mode.
 *
 * This function handles FSAFE bit filed of FCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en Enable or disable.
 */
static inline void PWMLL_EnableFaultSafetyMode(PWM_Type *base,
                                               pwmll_fault_channel_t ch,
                                               pwmll_fault_input_t input,
                                               bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FCTRL |= PWM_FCTRL_FSAFE(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FCTRL &= ~PWM_FCTRL_FSAFE(input);
    }
}

/*!
 * @brief Enable/Disable fault input interrupt.
 *
 * This function handles FIE bit filed of FCTRLx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_EnableFaultInterrupt(PWM_Type *base,
                                              pwmll_fault_channel_t ch,
                                              pwmll_fault_input_t input,
                                              bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FCTRL |= PWM_FCTRL_FIE(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FCTRL &= ~PWM_FCTRL_FIE(input);
    }
}

/*!
 * @brief Enable/Disable fault recovery at half cycle.
 *
 * This function handles FHALF bit filed of FSTSx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_EnableFaultRecoveryAtHalfCycle(PWM_Type *base,
                                                        pwmll_fault_channel_t ch,
                                                        pwmll_fault_input_t input,
                                                        bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FSTS =
            (base->FAULT[(uint8_t)ch].FSTS & (~PWM_FSTS_FFLAG_MASK)) | PWM_FSTS_FHALF(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FSTS =
            base->FAULT[(uint8_t)ch].FSTS & (~(PWM_FSTS_FHALF(input) | PWM_FSTS_FFLAG_MASK));
    }
}

/*!
 * @brief Get fault filtered pin logic state.
 *
 * This function handles FFPIN bit filed of FSTSx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 *
 * @return Fault pin logic state. true means fault condition exists.
 */
static inline bool PWMLL_GetFilteredFaultPinStatus(PWM_Type *base, pwmll_fault_channel_t ch, pwmll_fault_input_t input)
{
    assert(base != NULL);
    if (0U != (base->FAULT[(uint8_t)ch].FSTS & PWM_FSTS_FFPIN(input)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Enable/Disable fault recovery at full cycle.
 *
 * This function handles FFULL bit filed of FSTSx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_EnableFaultRecoveryAtFullCycle(PWM_Type *base,
                                                        pwmll_fault_channel_t ch,
                                                        pwmll_fault_input_t input,
                                                        bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FSTS =
            (base->FAULT[(uint8_t)ch].FSTS & (~PWM_FSTS_FFLAG_MASK)) | PWM_FSTS_FFULL(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FSTS =
            base->FAULT[(uint8_t)ch].FSTS & (~(PWM_FSTS_FFULL(input) | PWM_FSTS_FFLAG_MASK));
    }
}

/*!
 * @brief Get fault flag.
 *
 * This function handles FFLAG bit filed of FSTSx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 *
 * @return Fault status, true means fault condition exists.
 */
static inline bool PWMLL_GetFaultFlag(PWM_Type *base, pwmll_fault_channel_t ch, pwmll_fault_input_t input)
{
    assert(base != NULL);
    if (0U != (base->FAULT[(uint8_t)ch].FSTS & PWM_FSTS_FFLAG(input)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Clear fault flag.
 *
 * This function handles FFLAG bit filed of FSTSx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 */
static inline bool PWMLL_ClearFaultFlag(PWM_Type *base, pwmll_fault_channel_t ch, pwmll_fault_input_t input)
{
    assert(base != NULL);
    base->FAULT[(uint8_t)ch].FSTS = (base->FAULT[(uint8_t)ch].FSTS & (~PWM_FSTS_FFLAG_MASK)) | PWM_FSTS_FFLAG(input);
}

/*!
 * @brief Enable/Disable fault glitch stretch.
 *
 * This function handles GSTR bit filed of FFILTx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param en   Enable or disable.
 */
static inline void PWMLL_EnableFaultGlitchStretch(PWM_Type *base, pwmll_fault_channel_t ch, bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FFILT |= PWM_FFILT_GSTR(1U);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FFILT &= ~PWM_FFILT_GSTR(1U);
    }
}

/*!
 * @brief Configure fault filter count.
 *
 * This function handles FILT_CNT bit filed of FFILTx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param value Setting filter count.
 */
static inline void PWMLL_ConfigFilterCount(PWM_Type *base, pwmll_fault_channel_t ch, uint16_t value)
{
    assert(base != NULL);
    base->FAULT[(uint8_t)ch].FFILT =
        (base->FAULT[(uint8_t)ch].FFILT & (~PWM_FFILT_FILT_CNT_MASK)) | PWM_FFILT_FILT_CNT(value);
}

/*!
 * @brief Configure fault filter period.
 *
 * This function handles FILT_PER bit filed of FFILTx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param value Setting filter period.
 */
static inline void PWMLL_ConfigFilterPeriod(PWM_Type *base, pwmll_fault_channel_t ch, uint16_t value)
{
    assert(base != NULL);
    base->FAULT[(uint8_t)ch].FFILT =
        (base->FAULT[(uint8_t)ch].FFILT & (~PWM_FFILT_FILT_PER_MASK)) | PWM_FFILT_FILT_PER(value);
}

/*!
 * @brief Generate simulated fault.
 *
 * This function handles FTEST bit filed of FTSTx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 */
static inline void PWMLL_GenerateSimulatedFault(PWM_Type *base, pwmll_fault_channel_t ch)
{
    assert(base != NULL);
    base->FAULT[(uint8_t)ch].FTST |= PWM_FTST_FTEST(1U);
}

/*!
 * @brief Clear simulated fault.
 *
 * This function handles FTEST bit filed of FTSTx register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 */
static inline void PWMLL_ClearSimulatedFault(PWM_Type *base, pwmll_fault_channel_t ch)
{
    assert(base != NULL);
    base->FAULT[(uint8_t)ch].FTST &= ~PWM_FTST_FTEST(1U);
}

/*!
 * @brief Enable/Disable fault filter takes effect on PWM output.
 *
 * This function handles NOCOMB bit filed of FCTRL2x register.
 *
 * @param base PWM peripheral base address.
 * @param ch   Fault channel ID.
 * @param input Fault input ID.
 * @param en Enable or disable.
 */
static inline void PWMLL_EnableFaultFilterOnPWMOutput(PWM_Type *base,
                                                      pwmll_fault_channel_t ch,
                                                      pwmll_fault_input_t input,
                                                      bool en)
{
    assert(base != NULL);
    if (en)
    {
        base->FAULT[(uint8_t)ch].FCTRL2 |= PWM_FCTRL2_NOCOMB(input);
    }
    else
    {
        base->FAULT[(uint8_t)ch].FCTRL2 &= ~PWM_FCTRL2_NOCOMB(input);
    }
}

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PWMLL_H_ */
