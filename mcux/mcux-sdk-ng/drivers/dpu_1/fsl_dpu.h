/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_DPU_H_
#define _FSL_DPU_H_

#include "fsl_common.h"

/*!
 * @addtogroup dpu
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief Driver version. */
#define FSL_DPU_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*@}*/

/*! @brief DPU palette entery number. */
#define DPU_PALETTE_ENTRY_NUM (256U)

/*! @brief DPU fetch unit burst length, should be less than 16. */
#ifndef DPU_FETCH_UNIT_BURST_LENGTH
#define DPU_FETCH_UNIT_BURST_LENGTH (16U)
#endif

/*! @brief DPU fetch unit burst size.
 *
 * If prefetch is used, the frame buffer stride and base address should be
 * aligned to the burst size.
 */
#define DPU_FETCH_UNIT_BURST_SIZE (8U * DPU_FETCH_UNIT_BURST_LENGTH)

#define DPU_USE_GENERATE_HEADER 0

/*!
 * @name Macros for the DPU unit input source.
 *
 * The DPU unit input source is controlled by the register pixencfg_\<unit\>_dynamic,
 * the macros @ref DPU_MAKE_SRC_REG1, @ref DPU_MAKE_SRC_REG2, and @ref DPU_MAKE_SRC_REG3
 * are used to define the register value of pixencfg_\<unit\>_dynamic. @ref DPU_MAKE_SRC_REG1
 * defines register for DPU unit that has one input source. Accordingly,
 * @ref DPU_MAKE_SRC_REG2 and @ref DPU_MAKE_SRC_REG3 are used to define the register for
 * units that have two and three input source. See @ref _dpu_unit_source for the
 * input source details.
 * @{
 */
/*! Macro for one input source unit. */
#define DPU_MAKE_SRC_REG1(src) (((uint32_t)(src)) & 0x3FU)
/*! Macro for two input source unit. */
#define DPU_MAKE_SRC_REG2(primSrc, secSrc) \
    ((((uint32_t)(primSrc)) & 0x3FU) | (((((uint32_t)(secSrc)) & 0x3FU) << 0x8U)))
/*! Macro for three input source unit. */
#define DPU_MAKE_SRC_REG3(primSrc, secSrc, tertSrc)                               \
    ((((uint32_t)(primSrc)) & 0x3FU) | ((((uint32_t)(secSrc)) & 0x3FU) << 0x8U) | \
     (((((uint32_t)(tertSrc)) & 0x3FU) << 0x10U)))
/*!@}*/

/*! @brief Define the const value that write to \<unit\>_ConstantColor. */
#define DPU_MAKE_CONST_COLOR(red, green, blue, alpha) \
    ((((uint32_t)(red)) << 24U) | (((uint32_t)(green)) << 16U) | (((uint32_t)(blue)) << 8U) | ((uint32_t)(alpha)))

/*
 * Macros to define the DPU unit, these are internal macros and should not be
 * used by upper layer.
 *
 * type: Type of the unit, see _dpu_unit_type.
 * attr: Unit attribute, OR'ed value of _dpu_unit_attr.
 * offset: Control block register offset in DPU memory map.
 */
#define DPU_UNIT_TYPE_SHIFT   (26U)
#define DPU_UNIT_TYPE_MASK    (0xFC000000U)
#define DPU_UNIT_ATTR_SHIFT   (24U)
#define DPU_UNIT_ATTR_MASK    (0x03000000U)
#define DPU_UNIT_OFFSET_SHIFT (0U)
#define DPU_UNIT_OFFSET_MASK  (0x00FFFFFFU)

#define DPU_MAKE_UNIT_TYPE(type)     (((uint32_t)(type)) << DPU_UNIT_TYPE_SHIFT)
#define DPU_MAKE_UNIT_ATTR(attr)     (((uint32_t)(attr)) << DPU_UNIT_ATTR_SHIFT)
#define DPU_MAKE_UNIT_OFFSET(offset) (((uint32_t)(offset)) << DPU_UNIT_OFFSET_SHIFT)

#define DPU_GET_UNIT_TYPE(unit)   ((((uint32_t)(unit)) & DPU_UNIT_TYPE_MASK) >> DPU_UNIT_TYPE_SHIFT)
#define DPU_GET_UNIT_ATTR(unit)   ((((uint32_t)(unit)) & DPU_UNIT_ATTR_MASK) >> DPU_UNIT_ATTR_SHIFT)
#define DPU_GET_UNIT_OFFSET(unit) ((((uint32_t)(unit)) & DPU_UNIT_OFFSET_MASK) >> DPU_UNIT_OFFSET_SHIFT)

#define DPU_MAKE_UNIT(type, attr, offset) \
    (DPU_MAKE_UNIT_TYPE(type) | DPU_MAKE_UNIT_ATTR(attr) | DPU_MAKE_UNIT_OFFSET(offset))

/* DPU init offset definitions, these offset are for driver internal use only. */
#define DPU_UNIT_OFFSET(unit) (uint32_t)(&((DISPLAY_SEERIS_Type *)0)->unit)
#if DPU_USE_GENERATE_HEADER
#define DPU_FETCH_ECO9_OFFSET       DPU_UNIT_OFFSET(FETCHECO9)
#define DPU_FETCH_DECODE9_OFFSET    DPU_UNIT_OFFSET(FETCHDECODE9)
#define DPU_FETCH_ROT9_OFFSET       DPU_UNIT_OFFSET(FETCHROT9)
#define DPU_BLITBLEND9_OFFSET       DPU_UNIT_OFFSET(BLITBLEND9)
#define DPU_ROP9_OFFSET             DPU_UNIT_OFFSET(ROP9)
#define DPU_STORE9_OFFSET           DPU_UNIT_OFFSET(STORE9)
#define DPU_H_SCALER9_OFFSET        DPU_UNIT_OFFSET(H_SCALER9)
#define DPU_V_SCALER9_OFFSET        DPU_UNIT_OFFSET(V_SCALER9)
#define DPU_CONST_FRAME0_OFFSET     DPU_UNIT_OFFSET(CONSTFRAME0)
#define DPU_EXT_DST0_OFFSET         DPU_UNIT_OFFSET(EXTDST0)
#define DPU_CONST_FRAME4_OFFSET     DPU_UNIT_OFFSET(CONSTFRAME4)
#define DPU_EXT_DST4_OFFSET         DPU_UNIT_OFFSET(EXTDST4)
#define DPU_CONST_FRAME1_OFFSET     DPU_UNIT_OFFSET(CONSTFRAME1)
#define DPU_EXT_DST1_OFFSET         DPU_UNIT_OFFSET(EXTDST1)
#define DPU_CONST_FRAME5_OFFSET     DPU_UNIT_OFFSET(CONSTFRAME5)
#define DPU_EXT_DST5_OFFSET         DPU_UNIT_OFFSET(EXTDST5)
#define DPU_FETCH_ECO2_OFFSET       DPU_UNIT_OFFSET(FETCHECO2)
#define DPU_FETCH_DECODE0_OFFSET    DPU_UNIT_OFFSET(FETCHDECODE0)
#define DPU_FETCH_ECO0_OFFSET       DPU_UNIT_OFFSET(FETCHECO0)
#define DPU_FETCH_DECODE1_OFFSET    DPU_UNIT_OFFSET(FETCHDECODE1)
#define DPU_FETCH_ECO1_OFFSET       DPU_UNIT_OFFSET(FETCHECO1)
#define DPU_FETCH_LAYER0_OFFSET     DPU_UNIT_OFFSET(FETCHLAYER0)
#define DPU_H_SCALER4_OFFSET        DPU_UNIT_OFFSET(H_SCALER4)
#define DPU_V_SCALER4_OFFSET        DPU_UNIT_OFFSET(V_SCALER4)
#define DPU_H_SCALER5_OFFSET        DPU_UNIT_OFFSET(HSCALER5)
#define DPU_V_SCALER5_OFFSET        DPU_UNIT_OFFSET(V_SCALER5)
#define DPU_LAYER_BLEND0_OFFSET     DPU_UNIT_OFFSET(LAYERBLEND0)
#define DPU_LAYER_BLEND1_OFFSET     DPU_UNIT_OFFSET(LAYERBLEND1)
#define DPU_LAYER_BLEND2_OFFSET     DPU_UNIT_OFFSET(LAYERBLEND2)
#define DPU_LAYER_BLEND3_OFFSET     DPU_UNIT_OFFSET(LAYERBLEND3)
#define DPU_FRAME_GEN0_OFFSET       DPU_UNIT_OFFSET(FRAMEGEN0)
#define DPU_SIG0_OFFSET             DPU_UNIT_OFFSET(SIG0)
#define DPU_FRAME_GEN1_OFFSET       DPU_UNIT_OFFSET(FRAMEGEN1)
#define DPU_SIG1_OFFSET             DPU_UNIT_OFFSET(SIG1)
#define DPU_PIPELINE_EXTDST0_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.EXTDST0_LOCKUNLOCK)
#define DPU_PIPELINE_EXTDST1_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.EXTDST1_LOCKUNLOCK)
#define DPU_PIPELINE_EXTDST4_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.EXTDST4_LOCKUNLOCK)
#define DPU_PIPELINE_EXTDST5_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.EXTDST5_LOCKUNLOCK)
#define DPU_PIPELINE_STORE9_OFFSET  DPU_UNIT_OFFSET(PIXENGCFG.STORE9_LOCKUNLOCK)
#else
#define DPU_COMCTRL_OFFSET          0x0000U
#define DPU_FETCH_DECODE9_OFFSET    0x90000U
#define DPU_FETCH_ROT9_OFFSET       0x80000U
#define DPU_FETCH_ECO9_OFFSET       0xa0000U
#define DPU_ROP9_OFFSET             0x40000U
#define DPU_H_SCALER9_OFFSET        0xb0000U
#define DPU_V_SCALER9_OFFSET        0xc0000U
#define DPU_BLITBLEND9_OFFSET       0x70000U
#define DPU_STORE9_OFFSET           0xE0000U
#define DPU_CONST_FRAME0_OFFSET     0xF0000U
#define DPU_EXT_DST0_OFFSET         0x110000U
#define DPU_CONST_FRAME4_OFFSET     0x100000U
#define DPU_EXT_DST4_OFFSET         0x120000U
#define DPU_CONST_FRAME1_OFFSET     0x130000U
#define DPU_EXT_DST1_OFFSET         0x150000U
#define DPU_CONST_FRAME5_OFFSET     0x140000U
#define DPU_EXT_DST5_OFFSET         0x160000U
#define DPU_FETCH_ECO0_OFFSET       0x210000U
#define DPU_FETCH_ECO1_OFFSET       0x230000U
#define DPU_FETCH_ECO2_OFFSET       0x250000U
#define DPU_FETCH_LAYER0_OFFSET     0x1d0000U
#define DPU_FETCH_LAYER1_OFFSET     0x1e0000U
#define DPU_H_SCALER4_OFFSET        0x270000U
#define DPU_V_SCALER4_OFFSET        0x280000U
#define DPU_LAYER_BLEND1_OFFSET     0x170000U
#define DPU_LAYER_BLEND2_OFFSET     0x180000U
#define DPU_LAYER_BLEND3_OFFSET     0x190000U
#define DPU_LAYER_BLEND4_OFFSET     0x1A0000U
#define DPU_LAYER_BLEND5_OFFSET     0x1B0000U
#define DPU_LAYER_BLEND6_OFFSET     0x1C0000U
#define DPU_FETCH_YUV0_OFFSET       0x200000U
#define DPU_FETCH_YUV1_OFFSET       0x220000U
#define DPU_FETCH_YUV2_OFFSET       0x240000U
#define DPU_FETCH_YUV3_OFFSET       0x1F0000U
#define DPU_DOMAIN_BLEND0_OFFSET    0x2a0000U
#define DPU_DOMAIN_BLEND1_OFFSET    0x320000U
#define DPU_FRAME_GEN0_OFFSET       0x2B0000U
#define DPU_FRAME_GEN1_OFFSET       0x330000U
#define DPU_ID_HASH0_OFFSET         0x2C0000U
#define DPU_SIG0_OFFSET             0x2d0000U
#define DPU_SIG1_OFFSET             0x340000U
#define DPU_SIG2_OFFSET             0x2E0000U
#define DPU_DITHER0_CONFIG_OFFSET   0x311000U /* Dither 0 config offset */
#define DPU_DITHER1_CONFIG_OFFSET   0x371020U /* Dither 1 config offset */
#define DPU_PIPELINE_EXTDST0_OFFSET 0x111000U
#define DPU_PIPELINE_EXTDST1_OFFSET 0x151000U
#define DPU_PIPELINE_EXTDST4_OFFSET 0x121000U
#define DPU_PIPELINE_EXTDST5_OFFSET 0x161000U
#define DPU_PIPELINE_STORE9_OFFSET  0xE1000U

#define DPU_ROP_CONTROL_Mode_MASK      (1U << 0U)
#define DPU_ROP_CONTROL_RedMode_MASK   (1U << 7U)
#define DPU_ROP_CONTROL_GreenMode_MASK (1U << 6U)
#define DPU_ROP_CONTROL_BlueMode_MASK  (1U << 5U)
#define DPU_ROP_CONTROL_AlphaMode_MASK (1U << 4U)
#define DPU_ROP_CONTROL_TertDiv2_MASK  (1U << 10U)
#define DPU_ROP_CONTROL_SecDiv2_MASK   (1U << 9U)
#define DPU_ROP_CONTROL_PrimDiv2_MASK  (1U << 8U)

#define DPU_DISENGCONF_POLARITYCTRL_PolEn_MASK (1U << 2U)
#define DPU_DISENGCONF_POLARITYCTRL_PolVs_MASK (1U << 1U)
#define DPU_DISENGCONF_POLARITYCTRL_PolHs_MASK (1U << 0U)

#define DPU_SIG_EVALUPPERLEFT_XEvalUpperLeft_SHIFT    (0U)
#define DPU_SIG_EVALUPPERLEFT_YEvalUpperLeft_SHIFT    (16U)
#define DPU_SIG_EVALLOWERRIGHT_XEvalLowerRight_SHIFT  (0U)
#define DPU_SIG0_EVALLOWERRIGHT_YEvalLowerRight_SHIFT (16U)

#define DPU_SIG_SHADOWLOAD_ShdLdReq_MASK (0xFFU)
#endif

/*Domain mask enable*/
#define DOMAINMASK_ENABLE 0xFFFFFFFFU;

#define SHDLDREQSTICKY_ENABLE 0xFFU;

/* DPU unit type, internal used for DPU_MAKE_UNIT, _dpu_unit_type. */
enum
{
    kDPU_Pipeline,
    kDPU_BlitBlend,
    kDPU_Rop,
    kDPU_FetchRot,
    KDPU_FetchYuv,
    kDPU_FetchDecode,
    kDPU_FetchEco,
    kDPU_FetchLayer,
    kDPU_HScaler,
    kDPU_VScaler,
    kDPU_ConstFrame,
    kDPU_ExtDst,
    kDPU_LayerBlend,
    kDPU_Store,
    kDPU_DomainBlend
};

/* DPU unit attribute, internal used for DPU_MAKE_UNIT, _dpu_unit_attr. */
enum
{
    kDPU_UnitAttrIsFetch  = (1U << 0U), /* Is fetch unit.              */
    kDPU_UnitAttrHasSrc   = (1U << 1U), /* Has input source selection. */
    kDPU_UnitAttrNoShdow  = (1U << 2U), /* Does not support shadow load. */
    kDPU_UnitAttrSubLayer = (1U << 3U)  /* Has sub layer. */
};

/*! @brief DPU units. */
typedef enum _dpu_unit
{
    /*
     * In DPU driver, the pipeline is also treated as a unit. For example, the
     * kDPU_PipelineExtDst0 means the pipeline with ExtDst0 as its endpoint.
     * The driver uses the endpoint control registers in "Pixel Engine Top Level"
     * as the pipeline's control block.
     */
    kDPU_PipelineStore9 = DPU_MAKE_UNIT(kDPU_Pipeline, 0U, DPU_PIPELINE_STORE9_OFFSET),
    kDPU_FetchDecode9 =
        DPU_MAKE_UNIT(kDPU_FetchDecode, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc, DPU_FETCH_DECODE9_OFFSET),
    kDPU_FetchEco9 = DPU_MAKE_UNIT(kDPU_FetchEco, kDPU_UnitAttrIsFetch, DPU_FETCH_ECO9_OFFSET),
    kDPU_Hscaler9  = DPU_MAKE_UNIT(kDPU_HScaler, kDPU_UnitAttrHasSrc, DPU_H_SCALER9_OFFSET),
    kDPU_Vscaler9  = DPU_MAKE_UNIT(kDPU_VScaler, kDPU_UnitAttrHasSrc, DPU_V_SCALER9_OFFSET),
    kDPU_FetchRot9 = DPU_MAKE_UNIT(
        kDPU_FetchRot, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc | kDPU_UnitAttrSubLayer, DPU_FETCH_ROT9_OFFSET),
    kDPU_Rop9            = DPU_MAKE_UNIT(kDPU_Rop, kDPU_UnitAttrHasSrc, DPU_ROP9_OFFSET),
    kDPU_BlitBlend9      = DPU_MAKE_UNIT(kDPU_BlitBlend, kDPU_UnitAttrHasSrc, DPU_BLITBLEND9_OFFSET),
    kDPU_Store9          = DPU_MAKE_UNIT(kDPU_Store, kDPU_UnitAttrHasSrc, DPU_STORE9_OFFSET),
    kDPU_PipelineExtDst0 = DPU_MAKE_UNIT(kDPU_Pipeline, 0U, DPU_PIPELINE_EXTDST0_OFFSET),
    kDPU_PipelineExtDst1 = DPU_MAKE_UNIT(kDPU_Pipeline, 0U, DPU_PIPELINE_EXTDST1_OFFSET),
    kDPU_PipelineExtDst4 = DPU_MAKE_UNIT(kDPU_Pipeline, 0U, DPU_PIPELINE_EXTDST4_OFFSET),
    kDPU_PipelineExtDst5 = DPU_MAKE_UNIT(kDPU_Pipeline, 0U, DPU_PIPELINE_EXTDST5_OFFSET),
    kDPU_ConstFrame0     = DPU_MAKE_UNIT(kDPU_ConstFrame, 0U, DPU_CONST_FRAME0_OFFSET),
    kDPU_ExtDst0         = DPU_MAKE_UNIT(kDPU_ExtDst, kDPU_UnitAttrHasSrc, DPU_EXT_DST0_OFFSET),
    kDPU_ConstFrame4     = DPU_MAKE_UNIT(kDPU_ConstFrame, 0U, DPU_CONST_FRAME4_OFFSET),
    kDPU_ExtDst4         = DPU_MAKE_UNIT(kDPU_ExtDst, kDPU_UnitAttrHasSrc, DPU_EXT_DST4_OFFSET),
    kDPU_ConstFrame1     = DPU_MAKE_UNIT(kDPU_ConstFrame, 0U, DPU_CONST_FRAME1_OFFSET),
    kDPU_ExtDst1         = DPU_MAKE_UNIT(kDPU_ExtDst, kDPU_UnitAttrHasSrc, DPU_EXT_DST1_OFFSET),
    kDPU_ConstFrame5     = DPU_MAKE_UNIT(kDPU_ConstFrame, 0U, DPU_CONST_FRAME5_OFFSET),
    kDPU_ExtDst5         = DPU_MAKE_UNIT(kDPU_ExtDst, kDPU_UnitAttrHasSrc, DPU_EXT_DST5_OFFSET),
    kDPU_FetchEco2       = DPU_MAKE_UNIT(kDPU_FetchEco, kDPU_UnitAttrIsFetch, DPU_FETCH_ECO2_OFFSET),
    kDPU_FetchEco0       = DPU_MAKE_UNIT(kDPU_FetchEco, kDPU_UnitAttrIsFetch, DPU_FETCH_ECO0_OFFSET),
    kDPU_FetchEco1       = DPU_MAKE_UNIT(kDPU_FetchEco, kDPU_UnitAttrIsFetch, DPU_FETCH_ECO1_OFFSET),
    kDPU_FetchLayer0 =
        DPU_MAKE_UNIT(kDPU_FetchLayer, kDPU_UnitAttrIsFetch | kDPU_UnitAttrSubLayer, DPU_FETCH_LAYER0_OFFSET),
    kDPU_FetchLayer1 =
        DPU_MAKE_UNIT(kDPU_FetchLayer, kDPU_UnitAttrIsFetch | kDPU_UnitAttrSubLayer, DPU_FETCH_LAYER1_OFFSET),
    kDPU_FetchYuv0    = DPU_MAKE_UNIT(KDPU_FetchYuv, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc, DPU_FETCH_YUV0_OFFSET),
    kDPU_FetchYuv1    = DPU_MAKE_UNIT(KDPU_FetchYuv, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc, DPU_FETCH_YUV1_OFFSET),
    kDPU_FetchYuv2    = DPU_MAKE_UNIT(KDPU_FetchYuv, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc, DPU_FETCH_YUV2_OFFSET),
    kDPU_FetchYuv3    = DPU_MAKE_UNIT(KDPU_FetchYuv, kDPU_UnitAttrIsFetch | kDPU_UnitAttrHasSrc, DPU_FETCH_YUV3_OFFSET),
    kDPU_Hscaler4     = DPU_MAKE_UNIT(kDPU_HScaler, kDPU_UnitAttrHasSrc, DPU_H_SCALER4_OFFSET),
    kDPU_Vscaler4     = DPU_MAKE_UNIT(kDPU_VScaler, kDPU_UnitAttrHasSrc, DPU_V_SCALER4_OFFSET),
    kDPU_LayerBlend1  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND1_OFFSET),
    kDPU_LayerBlend2  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND2_OFFSET),
    kDPU_LayerBlend3  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND3_OFFSET),
    kDPU_LayerBlend4  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND4_OFFSET),
    kDPU_LayerBlend5  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND5_OFFSET),
    kDPU_LayerBlend6  = DPU_MAKE_UNIT(kDPU_LayerBlend, kDPU_UnitAttrHasSrc, DPU_LAYER_BLEND6_OFFSET),
    kDPU_DomainBlend0 = DPU_MAKE_UNIT(kDPU_DomainBlend, kDPU_UnitAttrHasSrc, DPU_DOMAIN_BLEND0_OFFSET),
    kDPU_DomainBlend1 = DPU_MAKE_UNIT(kDPU_DomainBlend, kDPU_UnitAttrHasSrc, DPU_DOMAIN_BLEND1_OFFSET),

} dpu_unit_t;

/*! @brief DPU interrupt. */
enum _dpu_interrupt
{
    kDPU_Group0Store9ShadowLoadInterrupt          = (1U << 0U),  /*!< Store9 shadow load interrupt. */
    kDPU_Group0Store9FrameCompleteInterrupt       = (1U << 1U),  /*!< Store9 frame complete interrupt. */
    kDPU_Group0Store9SeqCompleteInterrupt         = (1U << 2U),  /*!< Store9 sequence complete interrupt. */
    kDPU_Group0ExtDst0ShadowLoadInterrupt         = (1U << 3U),  /*!< ExtDst0 shadow load interrupt. */
    kDPU_Group0ExtDst0FrameCompleteInterrupt      = (1U << 4U),  /*!< ExtDst0 frame complete interrupt. */
    kDPU_Group0ExtDst0SeqCompleteInterrupt        = (1U << 5U),  /*!< ExtDst0 sequence complete interrupt. */
    kDPU_Group0ExtDst4ShadowLoadInterrupt         = (1U << 6U),  /*!< ExtDst4 shadow load interrupt. */
    kDPU_Group0ExtDst4FrameCompleteInterrupt      = (1U << 7U),  /*!< ExtDst4 frame complete interrupt. */
    kDPU_Group0ExtDst4SeqCompleteInterrupt        = (1U << 8U),  /*!< ExtDst4 sequence complete interrupt. */
    kDPU_Group0ExtDst1ShadowLoadInterrupt         = (1U << 9U),  /*!< ExtDst1 shadow load interrupt. */
    kDPU_Group0ExtDst1FrameCompleteInterrupt      = (1U << 10U), /*!< ExtDst1 frame complete interrupt. */
    kDPU_Group0ExtDst1SeqCompleteInterrupt        = (1U << 11U), /*!< ExtDst1 sequence complete interrupt. */
    kDPU_Group0ExtDst5ShadowLoadInterrupt         = (1U << 12U), /*!< ExtDst5 shadow load interrupt. */
    kDPU_Group0ExtDst5FrameCompleteInterrupt      = (1U << 13U), /*!< ExtDst5 frame complete interrupt. */
    kDPU_Group0ExtDst5SeqCompleteInterrupt        = (1U << 14U), /*!< ExtDst5 sequence complete interrupt. */
    kDPU_Group0DomainBlend0ShadowLoadInterrupt    = (1U << 15U), /*!< DomainBlend0 shadow load interrupt. */
    kDPU_Group0DomainBlend0FrameCompleteInterrupt = (1U << 16U), /*!< DomainBlend0 frame complete interrupt. */
    kDPU_Group0DomainBlend0SeqCompleteInterrupt   = (1U << 17U), /*!< DomainBlend0 sequence complete interrupt. */
    kDPU_Group0DiSengcfgShadowLoad0Interrupt      = (1U << 18U), /*!< DiSengcfg shadow load0 interrupt */
    kDPU_Group0DiSengcfgFrameComplete0Interrupt   = (1U << 19U), /*!< DiSengcfg frame complete0 interrupt. */
    kDPU_Group0DiSengcfgSeqComplete0Interrupt     = (1U << 20U), /*!< DiSengcfg sequence complete0 interrupt. */
    kDPU_Group0FrameGen0Int0Interrupt             = (1U << 21U), /*!< FrameGen 0 interrupt 0. */
    kDPU_Group0FrameGen0Int1Interrupt             = (1U << 22U), /*!< FrameGen 0 interrupt 1. */
    kDPU_Group0FrameGen0Int2Interrupt             = (1U << 23U), /*!< FrameGen 0 interrupt 2. */
    kDPU_Group0FrameGen0Int3Interrupt             = (1U << 24U), /*!< FrameGen 0 interrupt 3. */
    kDPU_Group0Sig0ShadowLoadInterrupt            = (1U << 25U), /*!< Sig0 shadow load interrupt. */
    kDPU_Group0Sig0ValidInterrupt                 = (1U << 26U), /*!< Sig0 measurement valid interrupt. */
    kDPU_Group0Sig0ErrorInterrupt                 = (1U << 27U), /*!< Sig0 error interrupt. */
    kDPU_Group0Sig0ClusterErrorInterrupt          = (1U << 28U), /*!< Sig0 cluster error interrupt. */
    kDPU_Group0Sig0ClusterMatchInterrupt          = (1U << 29U), /*!< Sig0 cluster match interrupt. */
    kDPU_Group0Sig2ShadowLoadInterrupt            = (1U << 30U), /*!< Sig2 shadow load interrupt. */
    kDPU_Group0Sig2ValidInterrupt                 = (1U << 31U), /*!< Sig2 measurement valid interrupt. */
    kDPU_Group1Sig2ErrorInterrupt                 = (1U << 0U),  /*!< Sig2 error interrupt. */
    kDPU_Group1Sig2ClusterErrorInterrupt          = (1U << 1U),  /*!< Sig2 cluster error interrupt. */
    kDPU_Group1Sig2ClusterMatchInterrupt          = (1U << 2U),  /*!< Sig2 cluster match interrupt. */
    kDPU_Group1IdHash0ShadowLoadInterrupt         = (1U << 3U),  /*!< IdHash0 shadow load interrupt. */
    kDPU_Group1IdHash0ValidInterrupt              = (1U << 4U),  /*!< IdHash0 measurement valid interrupt. */
    kDPU_Group1IdHash0WindowsErrorInterrupt       = (1U << 5U),  /*!< IdHash0 windows error interrupt. */
    kDPU_Group1DomainBlend1ShadowLoadInterrupt    = (1U << 6U),  /*!< DomainBlend1 shadow load interrupt. */
    kDPU_Group1DomainBlend1FrameCompleteInterrupt = (1U << 7U),  /*!< DomainBlend1 frame complete interrupt. */
    kDPU_Group1DomainBlend1SeqCompleteInterrupt   = (1U << 8U),  /*!< DomainBlend1 sequence complete interrupt. */
    kDPU_Group1DiSengcfgShadowLoad1Interrupt      = (1U << 9U),  /*!< DiSengcfg shadow load1 interrupt */
    kDPU_Group1DiSengcfgFrameComplete1Interrupt   = (1U << 10U), /*!< DiSengcfg frame complete1 interrupt. */
    kDPU_Group1DiSengcfgSeqComplete1Interrupt     = (1U << 11U), /*!< DiSengcfg sequence complete1 interrupt. */
    kDPU_Group1FrameGen1Int0Interrupt             = (1U << 12U), /*!< FrameGen 1 interrupt 0. */
    kDPU_Group1FrameGen1Int1Interrupt             = (1U << 13U), /*!< FrameGen 1 interrupt 1. */
    kDPU_Group1FrameGen1Int2Interrupt             = (1U << 14U), /*!< FrameGen 1 interrupt 2. */
    kDPU_Group1FrameGen1Int3Interrupt             = (1U << 15U), /*!< FrameGen 1 interrupt 3. */
    kDPU_Group1Sig1ShadowLoadInterrupt            = (1U << 16U), /*!< Sig1 shadow load interrupt. */
    kDPU_Group1Sig1ValidInterrupt                 = (1U << 17U), /*!< Sig1 measurement valid interrupt. */
    kDPU_Group1Sig1ErrorInterrupt                 = (1U << 18U), /*!< Sig1 error interrupt. */
    kDPU_Group1Sig1ClusterErrorInterrupt          = (1U << 19U), /*!< Sig1 cluster error interrupt. */
    kDPU_Group1Sig1ClusterMatchInterrupt          = (1U << 20U), /*!< Sig1 cluster match interrupt. */
    kDPU_Group1CmdSeqErrorInterrupt               = (1U << 21U), /*!< CmdSeq Error interrupt. */
    kDPU_Group1ComCtrlSw0Interrupt                = (1U << 22U), /*!< ComCtrlSw0 interrupt. */
    kDPU_Group1ComCtrlSw1Interrupt                = (1U << 23U), /*!< ComCtrlSw1 interrupt. */
    kDPU_Group1ComCtrlSw2Interrupt                = (1U << 24U), /*!< ComCtrlSw1 interrupt. */
    kDPU_Group1ComCtrlSw3Interrupt                = (1U << 25U), /*!< ComCtrlSw1 interrupt. */
    kDPU_Group1FrameGen0PrimSyncOnInterrupt       = (1U << 26U), /*!< FrameGen 0 primary sync on interrupt. */
    kDPU_Group1FrameGen0PrimSyncOffInterrupt      = (1U << 27U), /*!< FrameGen 0 primary sync off interrupt. */
    kDPU_Group1FrameGen0OverFlow0OnInterrupt      = (1U << 28U), /*!< FrameGen 0 over flow0  on interrupt. */
    kDPU_Group1FrameGen0OverFlow0OffInterrupt     = (1U << 29U), /*!< FrameGen 0 over flow0 off interrupt. */
    kDPU_Group1FrameGen0UnderRun0OnInterrupt      = (1U << 30U), /*!< FrameGen 0 under run0  on interrupt. */
    kDPU_Group1FrameGen0UnderRun0OffInterrupt     = (1U << 31U), /*!< FrameGen 0 under run0  off interrupt. */
    kDPU_Group2FrameGen0Threshold0RiseInterrupt   = (1U << 0U),  /*!< FrameGen 0 Threshold0  rise interrupt. */
    kDPU_Group2FrameGen0Threshold0FailInterrupt   = (1U << 1U),  /*!< FrameGen 0 Threshold0  fail interrupt. */
    kDPU_Group2FrameGen0OverFlow1OnInterrupt      = (1U << 2U),  /*!< FrameGen 0 over flow1  on interrupt. */
    kDPU_Group2FrameGen0OverFlow1OffInterrupt     = (1U << 3U),  /*!< FrameGen 0 over flow1 off interrupt. */
    kDPU_Group2FrameGen0UnderRun1OnInterrupt      = (1U << 4U),  /*!< FrameGen 0 under run1  on interrupt. */
    kDPU_Group2FrameGen0UnderRun1OffInterrupt     = (1U << 5U),  /*!< FrameGen 0 under run1  off interrupt. */
    kDPU_Group2FrameGen0Threshold1RiseInterrupt   = (1U << 6U),  /*!< FrameGen 0 Threshold1  rise interrupt. */
    kDPU_Group2FrameGen0Threshold1FailInterrupt   = (1U << 7U),  /*!< FrameGen 0 Threshold1  fail interrupt. */
    kDPU_Group2FrameGen1PrimSyncOnInterrupt       = (1U << 8U),  /*!< FrameGen 1 primary sync on interrupt. */
    kDPU_Group2FrameGen1PrimSyncOffInterrupt      = (1U << 9U),  /*!< FrameGen 1 primary sync off interrupt. */
    kDPU_Group2FrameGen1OverFlow0OnInterrupt      = (1U << 10U), /*!< FrameGen 1 over flow0  on interrupt. */
    kDPU_Group2FrameGen1OverFlow0OffInterrupt     = (1U << 11U), /*!< FrameGen 1 over flow0 off interrupt. */
    kDPU_Group2FrameGen1UnderRun0OnInterrupt      = (1U << 12U), /*!< FrameGen 1 under run0  on interrupt. */
    kDPU_Group2FrameGen1UnderRun0OffInterrupt     = (1U << 13U), /*!< FrameGen 1 under run0  off interrupt. */
    kDPU_Group2FrameGen1Threshold0RiseInterrupt   = (1U << 14U), /*!< FrameGen 1 Threshold0  rise interrupt. */
    kDPU_Group2FrameGen1Threshold0FailInterrupt   = (1U << 15U), /*!< FrameGen 1 Threshold0  fail interrupt. */
    kDPU_Group2FrameGen1OverFlow1OnInterrupt      = (1U << 16U), /*!< FrameGen 1 over flow1  on interrupt. */
    kDPU_Group2FrameGen1OverFlow1OffInterrupt     = (1U << 17U), /*!< FrameGen 1 over flow1 off interrupt. */
    kDPU_Group2FrameGen1UnderRun1OnInterrupt      = (1U << 18U), /*!< FrameGen 1 under run1  on interrupt. */
    kDPU_Group2FrameGen1UnderRun1OffInterrupt     = (1U << 19U), /*!< FrameGen 1 under run1  off interrupt. */
    kDPU_Group2FrameGen1Threshold1RiseInterrupt   = (1U << 20U), /*!< FrameGen 1 Threshold1  rise interrupt. */
    kDPU_Group2FrameGen1Threshold1FailInterrupt   = (1U << 21U), /*!< FrameGen 1 Threshold1  fail interrupt. */
};

enum _dpu_unit_source
{
    kDPU_UnitSrcNone         = 0,   /*!< Disable the input source. */
    kDPU_UnitSrcRop9         = 1U,  /*!< The input source is Rop 9. */
    KDPU_UnitSrcExtDst0      = 2U,  /*!< The input source is ExtDst 0. */
    KDPU_UnitSrcExtDst4      = 3U,  /*!< The input source is ExtDst 4. */
    kDPU_UnitSrcBlitBlend9   = 4U,  /*!< The input source is BlitBlend 9. */
    kDPU_UnitSrcFetchRot9    = 5U,  /*!< The input source is Rot 9. */
    kDPU_UnitSrcFetchDecode9 = 6U,  /*!< The input source is fetch decode 9. */
    kDPU_UnitSrcFetchEco9    = 7U,  /*!< input source is fetch eco 9. */
    kDPU_UnitSrcVScaler9     = 8U,  /*!< The input source is VScaler 9. */
    kDPU_UnitSrcFilter9      = 9U,  /*!< The input source is Filter 9. */
    kDPU_UnitSrcConstFrame0  = 12U, /*!< The input source is ConstFrame 0. */
    kDPU_UnitSrcConstFrame4  = 13U, /*!< The input source is ConstFrame 4. */
    kDPU_UnitSrcConstFrame1  = 16U, /*!< The input source is ConstFrame 1. */
    kDPU_UnitSrcConstFrame5  = 17U, /*!< The input source is ConstFrame 5. */
    kDPU_UnitSrcLayerBlend1  = 20U, /*!< The input source is LayerBlend 1. */
    kDPU_UnitSrcLayerBlend2  = 21U, /*!< The input source is LayerBlend 2. */
    kDPU_UnitSrcLayerBlend3  = 22U, /*!< The input source is LayerBlend 3. */
    kDPU_UnitSrcLayerBlend4  = 23U, /*!< The input source is LayerBlend 4. */
    kDPU_UnitSrcLayerBlend5  = 24U, /*!< The input source is LayerBlend 5. */
    kDPU_UnitSrcLayerBlend6  = 25U, /*!< The input source is LayerBlend 6. */
    kDPU_UnitSrcFetchLayer0  = 26U, /*!< The input source is FetchLayer 0. */
    kDPU_UnitSrcFetchLayer1  = 27U, /*!< The input source is FetchLayer 1. */
    kDPU_UnitSrcFetchYUV3    = 28U, /*!< The input source is Fetchyuv 3. */
    kDPU_UnitSrcFetchYUV0    = 29U, /*!< The input source is Fetchyuv 0. */
    kDPU_UnitSrcFetchEco0    = 30U, /*!< The input source is FetchEco 0. */
    kDPU_UnitSrcFetchYUV1    = 31U, /*!< The input source is Fetchyuv 1. */
    kDPU_UnitSrcFetchEco1    = 32U, /*!< The input source is FetchEco 1. */
    kDPU_UnitSrcFetchYUV2    = 33U, /*!< The input source is Fetchyuv 2. */
    kDPU_UnitSrcFetchEco2    = 34U, /*!< The input source is FetchEco 2. */
    kDPU_UnitSrcMatrix4      = 35U, /*!< The input source is Matrix 4. */
    kDPU_UnitSrcHScaler4     = 36U, /*!< The input source is HScaler 4. */
    kDPU_UnitSrcVScaler4     = 37U, /*!< The input source is VScaler 4. */
    KDPU_UnitSrcExtDst1      = 38U, /*!< The input source is ExtDst 1. */
};

/*! @brief LayerBlend unit shadow token generate mode. */
enum _dpu_layer_blend_shadow_token_mode
{
    kDPU_LayerBlendShadowTokenPrim, /*!< Generate shadow load token when token received from primary input. */
    kDPU_LayerBlendShadowTokenSec,  /*!< Generate shadow load token when token received from secondary input. */
    kDPU_LayerBlendShadowTokenBoth  /*!< Generate shadow load token when token received from any input. */
};

/*! @brief LayerBlend unit shadow load mode. */
enum _dpu_layer_blend_shadow_load_mode
{
    kDPU_LayerBlendShadowLoadPrim, /*!< Load shadows when token received from primary input. */
    kDPU_LayerBlendShadowLoadSec,  /*!< Load shadows when token received from secondary input. */
    kDPU_LayerBlendShadowLoadBoth  /*!< Load shadows when token received from any input. */
};

/*!
 * @brief DPU pixel format.
 *
 * To support more pixel format, enhance this enum and the array s_dpuColorComponentFormats.
 */
typedef enum _dpu_pixel_format
{
    kDPU_PixelFormatGray8    = 0, /*!< 8-bit gray. */
    kDPU_PixelFormatRGB565   = 1, /*!< RGB565, 16-bit per pixel. */
    kDPU_PixelFormatARGB8888 = 2, /*!< ARGB8888, 32-bit per pixel. */
    kDPU_PixelFormatRGB888   = 3, /*!< RGB888, 24-bit per pixel. */
    kDPU_PixelFormatARGB1555 = 4, /*!< ARGB1555, 16-bit per pixel. */
} dpu_pixel_format_t;

/*! @brief Configuration structure for fetch units. */
typedef struct _dpu_fetch_unit_config
{
    uint32_t srcReg;      /*!< This value will be set to register pixengcfg_fetchX_dynamic
                               to set the unit input source, see @ref DPU_MAKE_SRC_REG1. */
    uint16_t frameHeight; /*!< Frame height. */
    uint16_t frameWidth;  /*!< Frame width. */
} dpu_fetch_unit_config_t;

/*!
 * @brief Configuration structure for the arbitrary warping re-sampling coordinates.
 *
 * The coordinate layer supports:
 *
 * - 32 bpp: 2 x s12.4 (signed fix-point)
 * - 24 bpp: 2 x s8.
 * - 16 bpp: 2 x s4.4
 * - 8 bpp: 2 x s0.4
 * - 4 bpp: 2 x s(-2).4 (means total value size = 2 bits and lowest bit = 2^-4)
 * - 2 bpp: 2 x s(-3).4
 * - 1 bpp: 1 x s(-3).4 (x and y alternating)
 */
typedef struct _dpu_coordinates_config
{
    uint8_t bitsPerPixel; /*!< Number of bits per pixel in the source buffer. Must be 1, 2, 4, 8, 16, 32. */
    uint16_t strideBytes; /*!< Source buffer stride in bytes. */
    uint32_t baseAddr;    /*!< Source buffer base address. */
    uint16_t frameHeight; /*!< Frame height. */
    uint16_t frameWidth;  /*!< Frame width. */
} dpu_coordinates_config_t;

/*! @brief FetchWarp unit warp coordinate mode. */
typedef enum _dpu_warp_coordinate_mode
{
    kDPU_WarpCoordinateModePNT   = 0U, /*!< Sample points positions are read from coordinate layer. */
    kDPU_WarpCoordinateModeDPNT  = 1U, /*!< Sample points start position and delta are read from coordinate layer. */
    kDPU_WarpCoordinateModeDDPNT = 2U  /*!< Sample points initial value and delta increase
                                            value are read from coordinate layer. */
} dpu_warp_coordinate_mode_t;

/*! @brief Warp configuration structure for FetchWarp unit. */
typedef struct _dpu_warp_config
{
    uint32_t srcReg;                      /*!< This value will be set to register pixengcfg_fetchX_dynamic
                                               to set the unit input source, see @ref DPU_MAKE_SRC_REG1. */
    uint16_t frameHeight;                 /*!< Frame height. */
    uint16_t frameWidth;                  /*!< Frame width. */
    uint8_t warpBitsPerPixel;             /*!< Pixel bits of the coordinate layer. */
    bool enableSymmetricOffset;           /*!< Enables symmetric range for negative and positive coordinate
                                            values by adding an offset of +0.03125 internally to all
                                            coordinate input values. Recommended for small coordinate formats
                                            in DD_PNT mode. */
    dpu_warp_coordinate_mode_t coordMode; /*!< Coordinate layer mode. */
    uint32_t arbStartX; /*!< X of start point position. Signed 16.5 fix-point. Used in D_PNT and DD_PNT. */
    uint32_t arbStartY; /*!< Y of start point position. Signed 16.5 fix-point. Used in D_PNT and DD_PNT. */
    uint8_t arbDeltaYY; /*!< Y of vector between start and first sample point. Signed 3.5 fix-point. Used in DD_PNT. */
    uint8_t arbDeltaYX; /*!< X of vector between start and first sample point. Signed 3.5 fix-point. Used in DD_PNT. */
    uint8_t arbDeltaXY; /*!< Y of vector between first and second sample point. Signed 3.5 fix-point. Used in DD_PNT. */
    uint8_t arbDeltaXX; /*!< X of vector between first and second sample point. Signed 3.5 fix-point. Used in DD_PNT. */
} dpu_warp_config_t;

/*! @brief Define the color to take for pixels that do not lie inside the clip window of any layer */
typedef enum _dpu_clip_color_mode
{
    kDPU_ClipColorNull,     /*!< Use null color. */
    kDPU_ClipColorSublayer, /*!< Use color of sublayer. */
} dpu_clip_color_mode_t;

/*!
 * @brief Store unit Destination buffer configuration structure.
 *
 * Base address and stride alignment restrictions:
 *   32 bpp: Base address and stride must be a multiple of 4 bytes.
 *   16 bpp: Base address and stride must be a multiple of 2 bytes.
 *   others: any byte alignment allowed
 */
typedef struct _dpu_dst_buffer_config
{
    uint32_t baseAddr;              /*!< Destination buffer base address, see alignment restrictions. */
    uint16_t strideBytes;           /*!< Destination buffer stride in bytes, see alignment restrictions. */
    uint8_t bitsPerPixel;           /*!< Bits per pixel. */
    dpu_pixel_format_t pixelFormat; /*!< Pixel format. */
    uint16_t bufferHeight;          /*!< Buffer height. */
    uint16_t bufferWidth;           /*!< Buffer width. */
} dpu_dst_buffer_config_t;

/*! @brief LayerBlend unit AlphaMask mode. */
typedef enum _dpu_alpha_mask_mode
{
    kDPU_AlphaMaskPrim,       /*!< Areas with primary input alpha > 128 mapped to alpha 255, the rest mapped to 0. */
    kDPU_AlphaMaskSec,        /*!< Areas with secondary input alpha > 128 mapped to alpha 255, the rest mapped to 0. */
    kDPU_AlphaMaskPrimOrSec,  /*!< Primary and secondary OR'ed together. */
    kDPU_AlphaMaskPrimAndSec, /*!< Primary and secondary AND'ed together. */
    kDPU_AlphaMaskPrimInv,    /*!< Primary input alpha inverted. */
    kDPU_AlphaMaskSecInv,     /*!< Secondary input alpha inverted. */
    kDPU_AlphaMaskPrimOrSecInv, /*!< Primary and inverted secondary OR'ed together. */
    kDPU_AlphaMaskPrimAndSecInv /*!< Primary and inverted secondary AND'ed together. */
} dpu_alpha_mask_mode_t;

/*! @brief LayerBlend unit alpha blend mode. */
typedef enum _dpu_blend_mode
{
    kDPU_BlendZero,          /*!< OUT = IN * 0. */
    kDPU_BlendOne,           /*!< OUT = IN * 1. */
    kDPU_BlendPrimAlpha,     /*!< OUT = IN * ALPHA_primary. */
    kDPU_BlendPrimAlphaInv,  /*!< OUT = IN * (1 - ALPHA_primary). */
    kDPU_BlendSecAlpha,      /*!< OUT = IN * ALPHA_secondary. */
    kDPU_BlendSecAlphaInv,   /*!< OUT = IN * (1 - ALPHA_secondary). */
    kDPU_BlendConstAlpha,    /*!< OUT = IN * ALPHA_const. */
    kDPU_BlendConstAlphaInv, /*!< OUT = IN * (1 - ALPHA_const). */
} dpu_blend_mode_t;

/*! @brief LayerBlend unit configuration structure. */
typedef struct _dpu_layer_blend_config
{
    uint8_t constAlpha;                  /*!< The const alpha value used in blend. */
    dpu_blend_mode_t secAlphaBlendMode;  /*!< Secondary (overlay) input alpha blending function. */
    dpu_blend_mode_t primAlphaBlendMode; /*!< Primary (background) input alpha blending function. */
    dpu_blend_mode_t secColorBlendMode;  /*!< Secondary (overlay) input color blending function. */
    dpu_blend_mode_t primColorBlendMode; /*!< Primary (background) input color blending function. */

    uint32_t srcReg;                     /*!< This value will be set to pixengcfg_layerblendX_dynamic
                                              to set the unit input source, see @ref DPU_MAKE_SRC_REG2. */
    bool enableAlphaMask;                /*!< Enable AlphaMask feature. */
    dpu_alpha_mask_mode_t alphaMaskMode; /*!< AlphaMask mode, only valid when enableAlphaMask is true. */
} dpu_layer_blend_config_t;

/*! @brief ConstFrame unit configuration structure. */
typedef struct _dpu_const_frame_config
{
    uint16_t frameHeight; /*!< Frame height. */
    uint16_t frameWidth;  /*!< Frame width. */
    uint32_t constColor;  /*!< See @ref DPU_MAKE_CONST_COLOR. */
} dpu_const_frame_config_t;

/*! @brief Display timing configuration flags. */
enum _dpu_display_timing_flags
{
    kDPU_DisplayPixelActiveHigh = 0, /*!< Pixel data active high. */
    kDPU_DisplayDataEnableActiveHigh =
        DPU_DISENGCONF_POLARITYCTRL_PolEn_MASK, /*!< Set to make data enable high active. */
    kDPU_DisplayDataEnableActiveLow = 0,        /*!< Set to make data enable high low. */
    kDPU_DisplayHsyncActiveHigh     = DPU_DISENGCONF_POLARITYCTRL_PolHs_MASK, /*!< Set to make HSYNC high active. */
    kDPU_DisplayHsyncActiveLow      = 0,                                      /*!< Set to make HSYNC low active. */
    kDPU_DisplayVsyncActiveHigh     = DPU_DISENGCONF_POLARITYCTRL_PolVs_MASK, /*!< Set to make VSYNC high active. */
    kDPU_DisplayVsyncActiveLow      = 0,                                      /*!< Set to make VSYNC low active. */
};

/*! @brief Display timing configuration structure. */
typedef struct _dpu_display_timing_config
{
    uint16_t flags;  /*!< OR'ed value of @ref _dpu_display_timing_flags. */
    uint16_t width;  /*!< Active width. */
    uint16_t hsw;    /*!< HSYNC pulse width. */
    uint16_t hfp;    /*!< Horizontal front porch. */
    uint16_t hbp;    /*!< Horizontal back porch. */
    uint16_t height; /*!< Active height. */
    uint16_t vsw;    /*!< VSYNC pulse width. */
    uint16_t vfp;    /*!< Vrtical front porch. */
    uint16_t vbp;    /*!< Vertical back porch. */
} dpu_display_timing_config_t;

/*! @brief Display mode, safety stream is the primary input, content stream is the secondary input. */
typedef enum _dpu_display_mode
{
    kDPU_DisplayBlackBackground, /*!< Black background is shown. */
    kDPU_DisplayConstBackground, /*!< Const color background is shown. */
    kDPU_DisplayOnlyPrim,        /*!< Only primary input is shown. */
    kDPU_DisplayOnlySec,         /*!< Only secondary input is shown. */
    kDPU_DisplayPrimOnTop,       /*!< Both inputs overlaid with primary on top. */
    kDPU_DisplaySecOnTop,        /*!< Both inputs overlaid with secondary on top. */
    kDPU_DisplayTest             /*!< White background with test pattern shown. */
} dpu_display_mode_t;

/*! @brief Display mode configuration structure. */
typedef struct _dpu_display_config
{
    bool enablePrimAlpha;                  /*!< Enable primary input alpha for screen composition. */
    bool enableSecAlpha;                   /*!< Enable secondary input alpha for screen composition. */
    dpu_display_mode_t displayMode;        /*!< Display mode. */
    bool enablePrimAlphaInPanic;           /*!< Enable primary input alpha for screen composition in panic mode. */
    bool enableSecAlphaInPanic;            /*!< Enable secondary input alpha for screen composition in panic mode. */
    dpu_display_mode_t displayModeInPanic; /*!< Display mode in panic mode. */
    uint16_t constRed;                     /*!< Const red value, 10-bit. */
    uint16_t constGreen;                   /*!< Const green value, 10-bit. */
    uint16_t constBlue;                    /*!< Const green value, 10-bit. */
    uint8_t constAlpha;                    /*!< Const alpha value, 1-bit. */
    uint16_t primAreaStartX;               /*!< Primary screen upper left corner, x component. 14-bit , start from 1. */
    uint16_t primAreaStartY;               /*!< Primary screen upper left corner, y component. 14-bit, start from 1. */
    uint16_t secAreaStartX; /*!< Secondary screen upper left corner, x component. 14-bit, start from 1. */
    uint16_t secAreaStartY; /*!< Secondary screen upper left corner, y component. 14-bit, start from 1. */
} dpu_display_config_t;

/*! @brief VScaler and HScaler configuration structure. */
typedef struct _dpu_scaler_config
{
    uint32_t srcReg;     /*!< This value will be set to register pixengcfg_slacer_dynamic
                              to set the unit input source, see @ref DPU_MAKE_SRC_REG1.
                              When down-scaling horizontally, the path should be -> HScaler -> VScaler ->,
                              When up-scaling horizontally, the path should be -> VScaler -> HScaler ->.  */
    uint16_t inputSize;  /*!< For HScaler, it is frame width, for VScaler, it is frame height. */
    uint16_t outputSize; /*!< For HScaler, it is frame width, for VScaler, it is frame height. */

} dpu_scaler_config_t;

/*! @brief Rop unit configuration structure. */
typedef struct _dpu_rop_config
{
    uint32_t controlFlags; /*!< Control flags, see @ref _dpu_rop_flags. */
    uint8_t alphaIndex;    /*!< Alpha operation index. */
    uint8_t blueIndex;     /*!< Blue operation index. */
    uint8_t greenIndex;    /*!< Green operation index. */
    uint8_t redIndex;      /*!< Red operation index. */
} dpu_rop_config_t;

/*!
 * @brief Fetch unit source buffer configuration structure.
 *
 * Base address and stride alignment restrictions:
 *   32 bpp: Base address and stride must be a multiple of 4 bytes.
 *   16 bpp: Base address and stride must be a multiple of 2 bytes.
 *   others: any byte alignment allowed
 *
 * Generally, the @ref bitsPerPixel and @ref pixelFormat specify the pixel format
 * in frame buffer, they should match. But when the color palette is used, the
 * @ref bitsPerPixel specify the format in framebuffer, the @ref pixelFormat
 * specify the format in color palette entry.
 */
typedef struct _dpu_src_buffer_config
{
    uint32_t baseAddr;              /*!< Source buffer base address, see alignment restrictions. */
    uint16_t strideBytes;           /*!< Source buffer stride in bytes, see alignment restrictions. */
    uint8_t bitsPerPixel;           /*!< Bits per pixel in frame buffer. */
    dpu_pixel_format_t pixelFormat; /*!< Pixel format. */
    uint16_t bufferHeight;          /*!< Buffer height. */
    uint16_t bufferWidth;           /*!< Buffer width. */
    uint32_t constColor; /*!< Const color shown in the region out of frame buffer, see @ref DPU_MAKE_CONST_COLOR. */
} dpu_src_buffer_config_t;

enum _dpu_rop_flags
{
    kDPU_RopAddRed =
        DPU_ROP_CONTROL_RedMode_MASK, /*!< Set to add the red component, otherwise raster with operation index. */
    kDPU_RopAddGreen =
        DPU_ROP_CONTROL_GreenMode_MASK, /*!< Set to add the green component, otherwise raster with operation index. */
    kDPU_RopAddBlue =
        DPU_ROP_CONTROL_BlueMode_MASK, /*!< Set to add the blue component, otherwise raster with operation index. */
    kDPU_RopAddAlpha =
        DPU_ROP_CONTROL_AlphaMode_MASK, /*!< Set to add the alpha component, otherwise raster with operation index. */
    kDPU_RopTertDiv2 = DPU_ROP_CONTROL_TertDiv2_MASK, /*!< In add mode, set this to divide tertiary port input by 2. */
    kDPU_RopSecDiv2  = DPU_ROP_CONTROL_SecDiv2_MASK,  /*!< In add mode, set this to divide secondary port input by 2. */
    kDPU_RopPrimDiv2 = DPU_ROP_CONTROL_PrimDiv2_MASK, /*!< In add mode, set this to divide primary port input by 2. */
};
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name DPU Initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the DPU peripheral.
 *
 * This function ungates the DPU clock.
 *
 * @param base DPU peripheral base address.
 *
 */
void DPU_Init(DISPLAY_SEERIS_Type *base);

/*!
 * @brief Deinitializes the DPU peripheral.
 *
 * This function gates the DPU clock.
 *
 * @param base DPU peripheral base address.
 */
void DPU_Deinit(DISPLAY_SEERIS_Type *base);

/*!
 * @brief Prepare the unit path configuration.
 *
 * The DPU has a default path configuration. Before changing the configuration,
 * this function could be used to break all the original path. This make sure
 * one pixel engine unit is not used in multiple pipelines.
 *
 * @param base DPU peripheral base address.
 */
void DPU_PreparePathConfig(DISPLAY_SEERIS_Type *base);

/* @} */

/*!
 * brief Enable the selected DPU interrupts.
 *
 * For example, to enable Store9 shadow load interrupt and Store9 frame complete
 * interrupt, use like this:
 *
 * code
   DPU_EnableInterrupts(DPU, 0, kDPU_Group0Store9ShadowLoadInterrupt |
                                kDPU_Group0Store9FrameCompleteInterrupt);
   endcode
 *
 * param base DPU peripheral base address.
 * param group Interrupt group index.
 * param mask The interrupts to enable, this is a logical OR of members in
 *             ref _dpu_interrupt.
 * note Only the members in the same group could be OR'ed, at the same time,
 * the parameter p group should be passed in correctly.
 */
void DPU_EnableInterrupts(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask);

/*!
 * @name Shadow load related.
 * @{
 */

/*!
 * @brief Enable or disable the register shadowing for the DPU process units.
 *
 * For example, to enable the shadowing of all RWS registers of the pipeline with endpoint Store9.
 * @code
   DPU_EnableShadowLoad(DPU, kDPU_PipelineStore9, true);
   @endcode
 *
 * @param base DPU peripheral base address.
 * @param unit The unit whose shadow load to enable or disable, see @ref dpu_unit_t.
 * @param enable True to enable, false to disable.
 * @retval kStatus_Success The shadow load is enabled or disabled successfully.
 * @retval kStatus_InvalidArgument The unit does not support shadow load.
 */
status_t DPU_EnableShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable);
/* @} */

/*!
 * @brief Set the DPU unit input source selection.
 *
 * Sets the DPU unit input source, the input source is controlled by the
 * register \<unit\>_dynamic in "Pixel Engin Top Level". This function writes
 * the register \<unit\>_dynamic directly, please check the reference manual
 * for the register details. This function only changes the input source
 * control bits in register.
 *
 * @param base DPU peripheral base address.
 * @param unit The DPU pipeline unit.
 * @param srcReg The value written to register \<unit\>_dynamic. Could be
 *               generated using @ref DPU_MAKE_SRC_REG1, @ref DPU_MAKE_SRC_REG2,
 *               and @ref DPU_MAKE_SRC_REG3.
 */
void DPU_SetUnitSrc(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);

/*!
 * @name Pipline.
 * @{
 */

/*!
 * @brief Initialize the pipeline.
 *
 * @param base DPU peripheral base address.
 * @param unit The DPU pipeline unit.
 */
void DPU_InitPipeline(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * @brief Deinitializes the pipeline.
 *
 * Power down the pipeline and disable the shadow load feature.
 *
 * @param base DPU peripheral base address.
 * @param unit The DPU pipeline unit.
 */
void DPU_DeinitPipeline(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * @brief Trigger the pipeline shadow load.
 *
 * This function triggers the pipeline reconfiguration.
 *
 * @param base DPU peripheral base address.
 * @param unit The DPU pipeline unit.
 */
void DPU_TriggerPipelineShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * @brief Get the default configuration for Store unit.
 *
 * The default value is:
 * @code
    config->baseAddr = 0U;
    config->strideBytes = 0x500U;
    config->bitsPerPixel = 32U,
    config->pixelFormat = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth = 0U;
   @endcode
 * @param config Pointer to the configuration.
 */
void DPU_DstBufferGetDefaultConfig(dpu_dst_buffer_config_t *config);

/*!
 * brief Initialize the Store unit.
 *
 * The valid input source of the store unit could be:
 *  - ref kDPU_UnitSrcNone
 *  - ref kDPU_UnitSrcHScaler9
 *  - ref kDPU_UnitSrcVScaler9
 *  - ref kDPU_UnitSrcFilter9
 *  - ref kDPU_UnitSrcBlitBlend9
 *  - ref kDPU_UnitSrcFetchDecode9
 *  - ref kDPU_UnitSrcFetchRot9
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Store unit here.
 * param srcReg Input source selecte register value, pixencfg_extdstX_dynamic
 * see ref DPU_MAKE_SRC_REG1.
 */
void DPU_InitStore(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);

/*!
 * @brief Set the Store unit Destination buffer configuration.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be Store unit here.
 * @param config Pointer to the configuration.
 * @retval kStatus_Success Initialization success.
 * @retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_SetStoreDstBufferConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_dst_buffer_config_t *config);

/*!
 * @brief Start the Store unit.
 *
 * This function starts the Store unit to save the frame to output buffer. When
 * the frame store completed, the interrupt flag @ref kDPU_Group0Store9FrameCompleteInterrupt
 * asserts.
 *
 * This is an example shows how to use Store unit:
 *
 * @code
   Initialize the Store unit, use FetchDecode9 output as its input.
   DPU_InitStore(DPU, kDPU_Store9, DPU_MAKE_SRC_REG1(kDPU_UnitSrcFetchDecode9));

   Configure the Store unit output buffer.
   DPU_SetStoreDstBufferConfig(DPU, kDPU_Store9, &DstBufferConfig);

   Configure FetchDecode9 unit, including source buffer setting and so on.
   ...

   Initialize the Store9 pipeline
   DPU_InitPipeline(DPU, kDPU_PipelineStore9);

   DPU_ClearUserInterruptsPendingFlags(DPU, kDPU_Group0Store9ShadowLoadInterrupt);

   Trigger the shadow load
   DPU_TriggerPipelineShadowLoad(DPU, kDPU_PipelineStore9);

   DPU_ClearUserInterruptsPendingFlags(DPU, kDPU_Group0Store9FrameCompleteInterrupt);

   Start the Store9 to convert and output.
   DPU_StartStore(DPU, kDPU_Store9);

   Wait for Store 9 completed, this could also be monitored by interrupt.
   while (!(kDPU_Group0Store9FrameCompleteInterrupt & DPU_GetUserInterruptsPendingFlags(DPU, 0))
   {
   }
   @endcode
 *
 * For better performance, it is allowed to set next operation while current is still in progress.
 * Upper layer could set next operation immediately after shadow load finished.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be Store unit here.
 */
void DPU_StartStore(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * brief Initialize the BlitBlend unit.
 *
 * The valid input primary source could be:
 * - ref kDPU_UnitSrcNone
 * - ref kDPU_UnitSrcHScaler9
 * - ref kDPU_UnitSrcVScaler9
 * - ref kDPU_UnitSrcFilter9
 * - ref kDPU_UnitSrcRop9
 *
 * The valid input secondary source could be:
 * - ref kDPU_UnitSrcNone
 * - ref kDPU_UnitSrcFetchDecode9
 * - ref kDPU_UnitSrcFetchRot9
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be BlitBlend unit here.
 * param srcReg Unit source selection, see ref DPU_MAKE_SRC_REG2.
 */
void DPU_InitBlitBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);

/*!
 * brief Enable or disable the BlitBlend unit.
 *
 * The BlitBlend unit could be runtime enabled or disabled, when disabled, the
 * primary input is output directly.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be BlitBlend unit here.
 * param enable Pass true to enable, false to disable.
 */
void DPU_EnableBlitBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable);

/* @} */

/*!
 * @name LayerBlend units
 * @{
 */

/*!
 * @brief Get default configuration structure for LayerBlend.
 *
 * The default value is:
 * @code
    config->constAlpha = 0U;
    config->secAlphaBlendMode = kDPU_BlendOne;
    config->primAlphaBlendMode = kDPU_BlendZero;
    config->secColorBlendMode = kDPU_BlendOne;
    config->primColorBlendMode = kDPU_BlendZero;
    config->enableAlphaMask = true;
    config->alphaMaskMode = kDPU_AlphaMaskPrim;
   @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void DPU_LayerBlendGetDefaultConfig(dpu_layer_blend_config_t *config);

/*!
 * brief Initialize the LayerBlend.
 *
 * The valid primary source:
 * - ref kDPU_UnitSrcNone
 * - ref kDPU_UnitSrcConstFrame0
 * - ref kDPU_UnitSrcConstFrame1
 * - ref kDPU_UnitSrcConstFrame4
 * - ref kDPU_UnitSrcConstFrame5
 *
 * The valid secondary source:
 * - ref kDPU_UnitSrcNone
 * - ref kDPU_UnitSrcHScaler4
 * - ref kDPU_UnitSrcVScaler4
 * - ref kDPU_UnitSrcMatrix4
 * - ref kDPU_UnitSrcFetchRot9
 * - ref kDPU_UnitSrcFetchlayer0
 * - ref kDPU_UnitSrcFetchlayer1
 * - ref kDPU_UnitSrcFetchYuv0-3
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be LayerBlend unit here.
 * param srcReg Unit source selection, see ref DPU_MAKE_SRC_REG2.
 */
void DPU_InitLayerBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);

/*!
 * @brief Set the LayerBlend unit configuration.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be LayerBlend unit here.
 * @param config Pointer to the configuration structure.
 */
void DPU_SetLayerBlendConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_layer_blend_config_t *config);

/*!
 * @brief Enable or disable the LayerBlend unit.
 *
 * If enabled, the blend result is output, otherwise, the primary input is output.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be LayerBlend unit here.
 * @param enable Pass true to enable, false to disable.
 */
void DPU_EnableLayerBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable);

/* @} */

/* @} */

/*!
 * @name ConstFrame units
 * @{
 */

/*!
 * @brief Initialize the ConstFrame unit.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be ConstFrame unit here.
 */
void DPU_InitConstFrame(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * @brief Get default configuration structure for ConstFrame unit.
 *
 * The default value is:
   @code
    config->frameHeight = 320U;
    config->frameWidth = 480U;
    config->constColor = DPU_MAKE_CONST_COLOR(0xFF, 0xFF, 0xFF, 0xFF);
   @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void DPU_ConstFrameGetDefaultConfig(dpu_const_frame_config_t *config);

/*!
 * @brief Set the ConstFrame unit configuration.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be ConstFrame unit here.
 * @param config Pointer to the configuration structure.
 */
void DPU_SetConstFrameConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_const_frame_config_t *config);

/* @} */

/*!
 * brief Initialize the ROp unit.
 *
 * The primary input source of the unit could be:
 *   - ref kDPU_UnitSrcNone
 *   - ref kDPU_UnitSrcFetchDecode9
 *   - ref kDPU_UnitSrcFetchRot9
 *
 * The secondary input source of the unit could be:
 *   - ref kDPU_UnitSrcNone
 *   - ref kDPU_UnitSrcFetchEco9
 *
 * The tert input source of the unit could be:
 *   - ref kDPU_UnitSrcNone
 *   - ref kDPU_UnitSrcFetchDecode9
 *   - ref kDPU_UnitSrcFetchRot9
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Rop unit here.
 * param srcReg Unit source selection, see ref DPU_MAKE_SRC_REG3.
 */
void DPU_InitRop(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);

/*!
 * brief Get the default ROp unit configuration.
 *
 * The default configuration is:
 *
 * code
    config->controlFlags = 0U;
    config->alphaIndex = 0U;
    config->blueIndex = 0U;
    config->greenIndex = 0U;
    config->redIndex = 0U;
   endcode
 * param config Pointer to the configuration structure.
 */
void DPU_RopGetDefaultConfig(dpu_rop_config_t *config);

/*!
 * brief Set the ROp unit configuration.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Rop unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_SetRopConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_rop_config_t *config);

/*!
 * brief Enable or disable the ROp unit.
 *
 * If disabled, only the primary input is output.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Rop unit here.
 * param enable Pass true to enable, false to disable.
 */
void DPU_EnableRop(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable);

/*!
 * @brief Get the default configuration for fetch unit.
 *
 * The default value is:
 * @code
    config->srcReg = 0U;
    config->frameHeight = 320U;
    config->frameWidth = 480U;
   @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void DPU_FetchUnitGetDefaultConfig(dpu_fetch_unit_config_t *config);

/*!
 * @brief Get default configuration structure for fetch unit source buffer.
 *
 * The default value is:
 * @code
    config->baseAddr = 0U;
    config->strideBytes = 0x500U;
    config->bitsPerPixel = 32U;
    config->pixelFormat = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth = 0U;
    config->constColor = DPU_MAKE_CONST_COLOR(0, 0, 0, 0);
   @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void DPU_SrcBufferGetDefaultConfig(dpu_src_buffer_config_t *config);

/*!
 * brief Initialize the fetch unit.
 *
 * This function initializes the fetch unit for the basic use, for other use
 * case such as arbitrary warping, use the functions ref DPU_InitFetchUnitRot
 * and ref DPU_InitWarpCoordinates.
 *
 * The input source of fetch unit could be:
 *  - ref kDPU_UnitSrcNone
 *  - ref kDPU_UnitSrcFetchRot9
 *  - ref kDPU_UnitSrcFetchEco2
 *  - ref kDPU_UnitSrcFetchEco9
 *  - ref kDPU_UnitSrcFetchEco0
 *  - ref kDPU_UnitSrcFetchEco1
 *  - ref kDPU_UnitSrcFetchYuv0
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_InitFetchUnit(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_fetch_unit_config_t *config);

/*!
 * @brief Set the fetch unit sublayer source buffer.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be fetch unit here.
 * @param sublayer Sublayer index, should be 0 to 7.
 * @param config Pointer to the configuration structure.
 * @retval kStatus_Success Initialization success.
 * @retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_SetFetchUnitSrcBufferConfig(DISPLAY_SEERIS_Type *base,
                                         dpu_unit_t unit,
                                         uint8_t sublayer,
                                         const dpu_src_buffer_config_t *config);

/*!
 * brief Set the fetch unit sublayer offset.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param offsetX Horizontal offset.
 * param offsetY Vertical offset.
 */
void DPU_SetFetchUnitOffset(
    DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, uint16_t offsetX, uint16_t offsetY);

/*!
 * brief Enable or disable fetch unit sublayer source buffer.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param enable True to enable, false to disable.
 */
void DPU_EnableFetchUnitSrcBuffer(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, bool enable);

/*!
 * brief Set the fetch unit clip color mode.
 *
 * This function selects which color to take for pixels that do not lie inside
 * the clip window of any layer.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param clipColorMode Select null color or use sublayer color.
 * param sublayer Select which sublayer's color to use when p clipColorMode
 * is ref kDPU_ClipColorSublayer.
 */
void DPU_SetFetchUnitClipColor(DISPLAY_SEERIS_Type *base,
                               dpu_unit_t unit,
                               dpu_clip_color_mode_t clipColorMode,
                               uint8_t sublayer);

/*!
 * brief Initialize the ExtDst unit.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be ExtDst unit here.
 * param srcReg Input source selecte register value, pixencfg_extdstX_dynamic see ref DPU_MAKE_SRC_REG1.
 * The valid source:
 * - ref kDPU_UnitSrcNone
 * - ref kDPU_UnitSrcLayerBlend1
 * - ref kDPU_UnitSrcLayerBlend2
 * - ref kDPU_UnitSrcLayerBlend3
 * - ref kDPU_UnitSrcLayerBlend4
 * - ref kDPU_UnitSrcLayerBlend5
 * - ref kDPU_UnitSrcLayerBlend6
 */
void DPU_InitExtDst(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg);
/*!
 * brief Set the Store unit Destination buffer base address.
 *
 * This function is run time used for better performance.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Store unit here.
 * param baseAddr Base address of the Destination buffer to set.
 */
void DPU_SetStoreDstBufferAddr(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t baseAddr);

/*!
 * brief Disable the selected DPU interrupts.
 *
 * For example, to disable Store9 shadow load interrupt and Store9 frame complete
 * interrupt, use like this:
 *
 * code
   DPU_DisableInterrupts(DPU, 0, kDPU_Group0Store9ShadowLoadInterrupt |
                                 kDPU_Group0Store9FrameCompleteInterrupt);
   endcode
 *
 * param base DPU peripheral base address.
 * param group Interrupt group index.
 * param mask The interrupts to disable, this is a logical OR of members in
 *             ref _dpu_interrupt.
 * note Only the members in the same group could be OR'ed, at the same time,
 * the parameter p group should be passed in correctly.
 */
void DPU_DisableInterrupts(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask);

/*!
 * brief Get the DPU interrupts pending status.
 *
 * The pending status are returned as mask.
 *
 * param base DPU peripheral base address.
 * param group Interrupt group index.
 * return The interrupts pending status mask value, see ref _dpu_interrupt.
 */
uint32_t DPU_GetInterruptsPendingFlags(DISPLAY_SEERIS_Type *base, uint8_t group);

/*!
 * brief Clear the specified DPU interrupts pending status.
 *
 * For example, to disable Store9 shadow load interrupt and Store9 frame complete
 * interrupt pending status, use like this:
 *
 * code
   DPU_ClearInterruptsPendingFlags(DPU, 0, kDPU_Group0Store9ShadowLoadInterrupt |
                                           kDPU_Group0Store9FrameCompleteInterrupt);
   endcode
 *
 * param base DPU peripheral base address.
 * param group Interrupt group index.
 * param mask The interrupt pending flags to clear, this is a logical OR of members in
 *             ref _dpu_interrupt.
 * note Only the members in the same group could be OR'ed, at the same time,
 * the parameter p group should be passed in correctly.
 */
void DPU_ClearInterruptsPendingFlags(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask);

/*!
 * brief Get default configuration structure for display mode.
 *
 * The default value is:
 * code
    config->flags = kDPU_DisplayDeActiveHigh;
    config->width = 320U;
    config->hsw = 32U;
    config->hfp = 8U;
    config->hbp = 40U;
    config->height = 240U;
    config->vsw = 4U;
    config->vfp = 13U;
    config->vbp = 6U;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_DisplayTimingGetDefaultConfig(dpu_display_timing_config_t *config);

/*!
 * brief Initialize the display timing.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 * param config Pointer to the configuration structure.
 */
void DPU_InitDisplayTiming(DISPLAY_SEERIS_Type *base, uint8_t displayIndex, const dpu_display_timing_config_t *config);

/*!
 * brief Get default configuration structure for display frame mode.
 *
 * The default value is:
   code
    config->enablePrimAlpha = false;
    config->enableSecAlpha = false;
    config->displayMode = kDPU_DisplayTest;
    config->enablePrimAlphaInPanic = false;
    config->enableSecAlphaInPanic = false;
    config->displayModeInPanic = kDPU_DisplayTest;
    config->constRed = 0x3FFU;
    config->constGreen = 0x3FFU;
    config->constBlue = 0x3FFU;
    config->constAlpha = 1U;
    config->primAreaStartX = 1U;
    config->primAreaStartY = 1U;
    config->secAreaStartX = 1U;
    config->secAreaStartY = 1U;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_DisplayGetDefaultConfig(dpu_display_config_t *config);

/*!
 * brief Set the display mode.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 * param config Pointer to the configuration structure.
 */
void DPU_SetDisplayConfig(DISPLAY_SEERIS_Type *base, uint8_t displayIndex, const dpu_display_config_t *config);

/*!
 * brief Start the display.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 */
void DPU_StartDisplay(DISPLAY_SEERIS_Type *base, uint8_t displayIndex);

/*!
 * brief Stop the display.
 *
 * This function stops the display and wait the sequence complete.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 */
void DPU_StopDisplay(DISPLAY_SEERIS_Type *base, uint8_t displayIndex);

/*!
 * brief Trigger the display stream shadow load token.
 *
 * Trigger the display stream shadow load token, then the shadow register will
 * be loaded at the begining of next frame.
 *
 * param base DPU peripheral base address.
 * param displayIndex Display index.
 */
void DPU_TriggerDisplayShadowLoad(DISPLAY_SEERIS_Type *base, uint8_t displayIndex);

/*!
 * brief Set the fetch unit sublayer source buffer base address.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param baseAddr Source buffer base address.
 */
void DPU_SetFetchUnitSrcBufferAddr(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, uint32_t baseAddr);

/*!
 * brief Initialize the Domainblend.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be DomainBlend unit here.
 */
void DPU_InitDomainBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * brief Trigger the display stream domainblend shadow load token.
 *
 * Trigger the display stream shadow load token, then the shadow register will
 * be loaded at the begining of next frame.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be DomainBlend unit here.
 */
void DPU_TriggerDisplayDbShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/* @} */

/*!
 * @name VScaler and HScaler units
 *
 * @note When both horizontal and vertical scaling is active, then the sequence
 * of both units in the Pixelbus configuration should be
 *
 *     -> HScaler -> VScaler ->    when down-scaling horizontally
 *     -> VScaler -> HScaler ->    when up-scaling horizontally
 *
 * @{
 */

/*!
 * @brief Initialize the VScaler or HScaler unit.
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be HScaler or VScaler unit here.
 */
void DPU_InitScaler(DISPLAY_SEERIS_Type *base, dpu_unit_t unit);

/*!
 * @brief Get default configuration structure for VScaler and HScaler.
 *
 * The default value is:
   @code
    config->srcReg = 0U;
    config->inputSize = 0U;
    config->outputSize = 0U;
   @endcode
 *
 * @param config Pointer to the configuration structure.
 */
void DPU_ScalerGetDefaultConfig(dpu_scaler_config_t *config);

/*!
 * @brief Set the VScaler or HScaler units configuration.
 *
 * The valid input source could be:
 *  - @ref kDPU_UnitSrcNone
 *  - @ref kDPU_UnitSrcFetchYuv0-3
 *  - @ref kDPU_UnitSrcMatrix4
 *  - @ref kDPU_UnitSrcVScaler4
 *  - @ref kDPU_UnitSrcHScaler4
 *  - @ref kDPU_UnitSrcVScaler9
 *  - @ref kDPU_UnitSrcHScaler9
 *  - @ref kDPU_UnitSrcFilter9
 *  - @ref kDPU_UnitSrcMatrix9
 *
 * @param base DPU peripheral base address.
 * @param unit DPU unit, see @ref dpu_unit_t, must be HScaler or VScaler unit here.
 * @param config Pointer to the configuration structure.
 */
void DPU_SetScalerConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_scaler_config_t *config);

/*!
 * brief Get the default warp configuration for FetchWarp unit.
 *
 * The default value is:
 * code
    config->srcReg = 0U;
    config->frameHeight = 320U;
    config->frameWidth = 480U;
    config->warpBitsPerPixel = 0U;
    config->enableSymmetricOffset = false;
    config->coordMode = kDPU_WarpCoordinateModePNT;
    config->arbStartX = 0U;
    config->arbStartY = 0U;
    config->arbDeltaYY = 0U;
    config->arbDeltaYX = 0U;
    config->arbDeltaXY = 0U;
    config->arbDeltaXX = 0U;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_FetcUnitGetDefaultWarpConfig(dpu_warp_config_t *config);

/*!
 * brief Initialize the Warp function for FetchRot unit.
 *
 * This function initializes the FetchWarp unit for the arbitrary warping.
 *
 * The valid source of fetch warp unit could be:
 *  - ref kDPU_UnitSrcNone
 *  - ref kDPU_UnitSrcFetchEco9
 *  - ref kDPU_UnitSrcFetchDecode9
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be FetchWarp unit here.
 * param config Pointer to the configuration structure.
 * retval kStatus_Success Initialization success.
 * retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_InitFetchUnitWarp(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_warp_config_t *config);

/*!
 * brief Get the default configuration structure for arbitrary warping re-sampling coordinates.
 *
 * The default value is:
 * code
    config->bitsPerPixel = 0U;
    config->strideBytes = 0x500U;
    config->baseAddr = 0U;
    config->frameHeight = 320U;
    config->frameWidth = 480U;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_CorrdinatesGetDefaultConfig(dpu_coordinates_config_t *config);

/*!
 * brief Initialize the arbitrary warping coordinates.
 *
 * This function initializes the FetchEco unit, so that it could
 * be used as the arbitrary warping coordinates.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be FetchEco here.
 * param config Pointer to the configuration structure.
 * retval kStatus_Success Initialization success.
 * retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_InitWarpCoordinates(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_coordinates_config_t *config);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_DPU_H_ */
