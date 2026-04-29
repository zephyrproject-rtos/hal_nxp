/*
 * Copyright 2023-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dpu.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dpu_1"
#endif

typedef struct
{
    __IO uint32_t COMCTRL_IPIDENTIFIER;
    uint8_t RESERVED_0[4092];
    __IO uint32_t IRQ_LOCKUNLOCK;
    __IO uint32_t IRQ_LOCKSTATUS;
    __IO uint32_t IRQ_INTERRUPTENABLE[3];
    __IO uint32_t IRQ_INTERRUPTPRESET[3];
    __IO uint32_t IRQ_INTERRUPTCLEAR[3];
    __IO uint32_t IRQ_INTERRUPTSTATUS[3];
    uint8_t RESERVED_1[4040];
} DPU_COMCTRL_Type;

typedef struct
{
    __IO uint32_t BASEADDRESS0;
    __IO uint32_t BASEADDRESSMSB0;
    __IO uint32_t AUTOUPDATEBASEADDRESS0;
    __IO uint32_t AUTOUPDATEBASEADDRESSMSB0;
    __IO uint32_t SOURCEBUFFERATTRIBUTES0;
    __IO uint32_t SOURCEBUFFERDIMENSION0;
    __IO uint32_t COLORCOMPONENTBITS0;
    __IO uint32_t COLORCOMPONENTSHIFT0;
    __IO uint32_t LAYEROFFSET0;
    __IO uint32_t CLIPWINDOWOFFSET0;
    __IO uint32_t CLIPWINDOWDIMENSIONS0;
    __IO uint32_t CONSTANTCOLOR0;
    __IO uint32_t LAYERPROPERTY0;
} DPU_SUBLAYER_CONTROL_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __I uint32_t LOCKSTATUS;
    __IO uint32_t STATIC;
    __IO uint32_t DYNAMIC;
    __IO uint32_t REQUEST;
    __O uint32_t TRIGGER;
    __I uint32_t STATUS;
} DPU_PIPELINE_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    DPU_SUBLAYER_CONTROL_Type LAYER[1];
    uint8_t RESERVED_0[4];
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t FRAMERESAMPLING;
    __IO uint32_t CONTROL;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t FETCHTYPE;
    __IO uint32_t BURSTBUFFERPROPERTIES;
    uint8_t RESERVED_1[4];
    __IO uint32_t CURBASEADDRESS0;
    __IO uint32_t CURBASEADDRESSMSB0;
    __IO uint32_t HIDDENSTATUS;
} DPU_FETCHECO_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t CONSTANTCOLOR;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t STATUS;
} DPU_CONSTFRAME_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t CONTROL;
    __IO uint32_t NEUTRALBORDER;
    __IO uint32_t CONSTANTCOLOR;
    __IO uint32_t COLORREDBLENDFUNCTION;
    __IO uint32_t COLORGREENBLENDFUNCTION;
    __IO uint32_t COLORBLUEBLENDFUNCTION;
    __IO uint32_t ALPHABLENDFUNCTION;
    __IO uint32_t BLENDMODE1;
    __IO uint32_t BLENDMODE2;
    __IO uint32_t DIRECTSETUP;
    __IO uint32_t PRIMCONTROLWORD;
    __IO uint32_t SECCONTROLWORD;
} DPU_BLITBLEND_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t POLARITYCTRL;
} DPU_DISENGCONF_BLOCK_Type;

typedef struct
{
    DPU_DISENGCONF_BLOCK_Type DITHER;
} DPU_DISENGCONF_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t CONTROL;
    __IO uint32_t SOFTWAREKICK;
    __IO uint32_t STATUS;
    __IO uint32_t CONTROLWORD;
    __IO uint32_t CURPIXELCNT;
    __IO uint32_t LASTPIXELCNT;
    __IO uint32_t PERFCOUNTER;
} DPU_EXTDST_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    __IO uint32_t RINGBUFSTARTADDR0;
    __IO uint32_t RINGBUFSTARTADDRMSB0;
    __IO uint32_t RINGBUFWRAPADDR0;
    __IO uint32_t RINGBUFWRAPADDRMSB0;
    __IO uint32_t FRAMEPROPERTIES0;
    uint8_t RESERVED_0[4];
    DPU_SUBLAYER_CONTROL_Type LAYER[1];
    uint8_t RESERVED_1[4];
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t FRAMERESAMPLING;
    __IO uint32_t DECODECONTROL;
    __IO uint32_t SOURCEBUFFERLENGTH;
    __IO uint32_t CONTROL;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t FETCHTYPE;
    __IO uint32_t DECODERSTATUS;
    uint8_t RESERVED_2[4];
    __IO uint32_t READADDRESS0;
    __IO uint32_t READADDRESSMSB0;
    __IO uint32_t BURSTBUFFERPROPERTIES;
    __IO uint32_t STATUS;
    __IO uint32_t CURBASEADDRESS0;
    __IO uint32_t CURBASEADDRESSMSB0;
    __IO uint32_t HIDDENSTATUS;
    uint8_t RESERVED_3[860];
    __IO uint32_t COLORPALETTE;
} DPU_FETCHDECODER_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    __IO uint32_t RINGBUFSTARTADDR0;
    __IO uint32_t RINGBUFSTARTADDRMSB0;
    __IO uint32_t RINGBUFWRAPADDR0;
    __IO uint32_t RINGBUFWRAPADDRMSB0;
    __IO uint32_t FRAMEPROPERTIES0;
    uint8_t RESERVED_0[4];
    DPU_SUBLAYER_CONTROL_Type LAYER[1];
    uint8_t RESERVED_1[4];
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t FRAMERESAMPLING;
    __IO uint32_t CONTROL;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t FETCHTYPE;
    __IO uint32_t READADDRESS0;
    __IO uint32_t READADDRESSMSB0;
    __IO uint32_t BURSTBUFFERPROPERTIES;
    __IO uint32_t STATUS;
    __IO uint32_t CURBASEADDRESS0;
    __IO uint32_t CURBASEADDRESSMSB0;
    __IO uint32_t HIDDENSTATUS;
} DPU_FETCHYUV_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t SHDLDREQCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    uint8_t RESERVED_0[4];
    DPU_SUBLAYER_CONTROL_Type LAYER[8];
    uint8_t RESERVED_1[4];
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t FRAMERESAMPLING;
    __IO uint32_t CONTROL;
    __IO uint32_t TRIGGERENABLE;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t FETCHTYPE;
    uint8_t RESERVED_2[4];
    __IO uint32_t BURSTBUFFERPROPERTIES;
    __IO uint32_t STATUS;
    uint8_t RESERVED_3[64];
    __IO uint32_t HIDDENSTATUS;
    uint8_t RESERVED_4[444];
    __IO uint32_t COLORPALETTE;
} DPU_FETCHLAYER_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    __IO uint32_t RINGBUFSTARTADDR0;
    __IO uint32_t RINGBUFSTARTADDRMSB0;
    __IO uint32_t RINGBUFWRAPADDR0;
    __IO uint32_t RINGBUFWRAPADDRMSB0;
    DPU_SUBLAYER_CONTROL_Type LAYER[1];
    uint8_t RESERVED_0[4];
    __IO uint32_t FRAMEDIMENSIONS;
    __IO uint32_t FRAMERESAMPLING;
    __IO uint32_t WARPCONTROL;
    __IO uint32_t AFFINESTARTX;
    __IO uint32_t AFFINESTARTY;
    __IO uint32_t AFFINEDELTAXX;
    __IO uint32_t AFFINEDELTAXY;
    __IO uint32_t AFFINEDELTAYX;
    __IO uint32_t AFFINEDELTAYY;
    __IO uint32_t ARBSTARTX;
    __IO uint32_t ARBSTARTY;
    __IO uint32_t ARBDELTA;
    __IO uint32_t FIRPOSITIONS;
    __IO uint32_t FIRCOEFFICIENTS;
    __IO uint32_t CONTROL;
    __IO uint32_t CONTROLTRIGGER;
    __IO uint32_t START;
    __IO uint32_t FETCHTYPE;
    __IO uint32_t READADDRESS0;
    __IO uint32_t READADDRESSMSB0;
    __IO uint32_t BURSTBUFFERPROPERTIES;
    __IO uint32_t STATUS;
    __IO uint32_t CURBASEADDRESS0;
    __IO uint32_t CURBASEADDRESSMSB0;
    __IO uint32_t HIDDENSTATUS;
} DPU_FETCHROT_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t FGSTCTRL;
    __IO uint32_t HTCFG1;
    __IO uint32_t HTCFG2;
    __IO uint32_t VTCFG1;
    __IO uint32_t VTCFG2;
    __IO uint32_t INTCONFIG[4];
    __IO uint32_t PKICKCONFIG;
    __IO uint32_t SKICKCONFIG;
    __IO uint32_t SECSTATCONFIG;
    __IO uint32_t FGSRCR1;
    __IO uint32_t FGSRCR2;
    __IO uint32_t FGSRCR3;
    __IO uint32_t FGSRCR4;
    __IO uint32_t FGSRCR5;
    __IO uint32_t FGSRCR6;
    __IO uint32_t FGSRCR7;
    __IO uint32_t FGSRCR8;
    __IO uint32_t FGSRCR9;
    __IO uint32_t FGSRCR10;
    __IO uint32_t FGSRCR11;
    __IO uint32_t FGSRCR12;
    __IO uint32_t FGSRCR13;
    __IO uint32_t FGSRCR14;
    __IO uint32_t FGSRCR15;
    __IO uint32_t FGKSDR;
    __IO uint32_t PACFG;
    __IO uint32_t SACFG;
    __IO uint32_t FGINCTRL;
    __IO uint32_t FGINCTRLPANIC;
    __IO uint32_t FGCCR;
    __IO uint32_t FGENABLE;
    __IO uint32_t FGSLR;
    __IO uint32_t FGENSTS;
    __IO uint32_t FGTIMESTAMP;
    __IO uint32_t FGCHSTAT;
    __IO uint32_t FGCHSTATCLR;
    __IO uint32_t FGSKEWMON;
    __IO uint32_t FGPFIFOMIN;
    __IO uint32_t FGPFIFOMAX;
    __IO uint32_t FGPFIFOFILLCLR;
    __IO uint32_t FGPFIFOTRES;
    __IO uint32_t FGSFIFOMIN;
    __IO uint32_t FGSFIFOMAX;
    __IO uint32_t FGSFIFOFILLCLR;
    __IO uint32_t FGSREPD;
    __IO uint32_t FGSRFTD;
    __IO uint32_t FGSRCSHTOTAL;
    __IO uint32_t FGSRCLOCKDIV;
    __IO uint32_t FGSL;
} DPU_FRAMEGEN_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __O uint32_t CONTROLTRIGGER;
    __IO uint32_t MODECONTROL;
    __IO uint32_t ALPHACONTROL;
    __IO uint32_t BLENDCONTROL;
    __IO uint32_t TIMEOUT_FEEDBACK;
    __IO uint32_t LOCKUP_CLEAR;
    __IO uint32_t DELAY_COUNTER_EN;
    __IO uint32_t DELAY_COUNTER_PRIM;
    __IO uint32_t DELAY_COUNTER_SEC;
    __IO uint32_t ERROR_COUNTER_PRIM;
    __IO uint32_t ERROR_COUNTER_SEC;
    __IO uint32_t SOURCE_STATUS;
    __IO uint32_t SOURCE_STATUS_CLEAR;
    __IO uint32_t PRIMCONTROLWORD;
    __IO uint32_t SECCONTROLWORD;
} DPU_DOMAINBLEND_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t SETUP1;
    __IO uint32_t SETUP2;
    __IO uint32_t CONTROL;
} DPU_HSCALER_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t CONTROL;
    __IO uint32_t BLENDCONTROL;
    __IO uint32_t POSITION;
    __IO uint32_t PRIMCONTROLWORD;
    __IO uint32_t SECCONTROLWORD;
} DPU_LAYERBLEND_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t SETUP1;
    __IO uint32_t SETUP2;
    __IO uint32_t CONTROL;
} DPU_VSCALER_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t CONTROL;
    __IO uint32_t RASTEROPERATIONINDICES;
    __IO uint32_t PRIMCONTROLWORD;
    __IO uint32_t SECCONTROLWORD;
    __IO uint32_t TERTCONTROLWORD;
} DPU_ROP_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t BURSTBUFFERMANAGEMENT;
    __IO uint32_t RINGBUFSTARTADDR;
    __IO uint32_t RINGBUFSTARTMSBADDR;
    __IO uint32_t RINGBUFWRAPADDR;
    __IO uint32_t RINGBUFWRAPMSBADDR;
    __IO uint32_t BASEADDRESS0;
    __IO uint32_t BASEADDRESSMSB0;
    __IO uint32_t AUTOUPDATEBASEADDRESS0;
    __IO uint32_t AUTOUPDATEBASEADDRESSMSB0;
    __IO uint32_t DESTINATIONBUFFERATTRIBUTES0;
    uint8_t RESERVED_0[4];
    __IO uint32_t BASEADDRESS1;
    __IO uint32_t BASEADDRESSMSB1;
    __IO uint32_t DESTINATIONBUFFERATTRIBUTES1;
    uint8_t RESERVED_1[4];
    __IO uint32_t BASEADDRESS2;
    __IO uint32_t BASEADDRESSMSB2;
    __IO uint32_t DESTINATIONBUFFERATTRIBUTES2;
    __IO uint32_t DESTINATIONBUFFERDIMENSION;
    __IO uint32_t FRAMEOFFSET;
    __IO uint32_t COLORCOMPONENTBITS;
    __IO uint32_t COLORCOMPONENTSHIFT;
    __IO uint32_t CONTROL;
    __IO uint32_t START;
    uint8_t RESERVED_2[4];
    __IO uint32_t WRITEADDRESS;
    __IO uint32_t WRITEADDRESSMSB;
    __IO uint32_t FRAMEPROPERTIES;
    __IO uint32_t BURSTBUFFERPROPERTIES;
    __IO uint32_t LASTCONTROLWORD;
    __IO uint32_t PERFCOUNTER;
    __IO uint32_t STATUS;
    uint8_t RESERVED_3[3956];
} DPU_STORE_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t ERRORTHRESHOLD;
    __IO uint32_t MATCHTHRESHOLD;
    __IO uint32_t PANICCOLOR;
    __IO uint32_t SHADOWLOAD;
    __IO uint32_t CONTINUOUSMODE;
    __IO uint32_t SOFTWAREKICK;
    __IO uint32_t SKIPWINDOW;
    __IO uint32_t STATUS;
    struct
    {
        __IO uint32_t CONTROL;
        __IO uint32_t UPPERLEFT;
        __IO uint32_t LOWERRIGHT;
        __IO uint32_t REF_R;
        __IO uint32_t REF_G;
        __IO uint32_t REF_B;
        __IO uint32_t STATUS0;
        __IO uint32_t STATUS1;
        __IO uint32_t MIN_REDSUM;
        __IO uint32_t MIN_GREENSUM;
        __IO uint32_t MIN_BLUESUM;
        __IO uint32_t MIN_LUMSUM;
        __IO uint32_t MAX_REDSUM;
        __IO uint32_t MAX_GREENSUM;
        __IO uint32_t MAX_BLUESUM;
        __IO uint32_t MAX_LUMSUM;
    } WINDOW[8];
} DPU_SIG_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t STATICCONTROL;
    __IO uint32_t CONTROL;
    __IO uint32_t RED[2];
    __IO uint32_t GREEN[2];
    __IO uint32_t BLUE[2];
    uint8_t RESERVED_0[8];
    __IO uint32_t OFFSETVECTOR[2];
    __IO uint32_t LASTCONTROLWORD;
} DPU_MATRIX_Type;

typedef struct
{
    __IO uint32_t LOCKUNLOCK;
    __IO uint32_t LOCKSTATUS;
    __IO uint32_t CONTROL;
    __IO uint32_t DITHERCONTROL10BITS;
    __IO uint32_t DITHERCONTROL12BITS;
} DPU_DITHER_Type;

typedef struct
{
    DPU_DOMAINBLEND_Type DOMAINBLEND;
    uint8_t RESERVED_0[65464];
    DPU_FRAMEGEN_Type FRAMEGEN;
    uint8_t RESERVED_1[65320];
} DPU_DISPLAY_Type;

#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
static inline void writel(uint32_t value, volatile void *addr)
{
    *(volatile uint32_t *)addr = value;
}

static inline void DPU_LdWrite(DISPLAY_SEERIS_LD_Type *base, uint32_t offset, uint32_t value)
{
    writel(value, (void *)((uintptr_t)base + offset));
}
#endif

#define DPU_INT_GROUP_NUM 3U /* Interrupt group number. */
#define DPU_DISPLAY_COUNT 2U /* Display number. */

#define DPU_MAKE_DIMENSION(heigth, width)   (((uint32_t)(heigth) << 16U) | ((uint32_t)(width) << 0U))
#define DPU_MAKE_POSITION(offsetY, offsetX) (((uint32_t)(offsetY) << 16U) | ((uint32_t)(offsetX) << 0U))
#define DPU_REG(base, offset)               *((volatile uint32_t *)((uint32_t)(base) + (offset)))

/* Make the register <fetch_unit>_StaticControl */
#define DPU_MAKE_SOURCEBUFFERATTRIBUTES(bitsPerPixel, stride) \
    ((((uint32_t)(bitsPerPixel) << 16U) & 0x003F0000U) | ((((uint32_t)(stride)-1U) << 0U) & 0x0000FFFFU))

#define DPU_MAKE_DESTINATIONBUFFERATTRIBUTES(bitsPerPixel, stride) \
    ((((uint32_t)(bitsPerPixel) << 24U) & 0x7F000000U) | ((uint32_t)0xF << 20U) | ((((uint32_t)(stride)-1U) << 0U) & 0x0001FFFFU))

#define DPU_SCALER_CONTROL_OUTPUTSIZE(output_size) ((((uint32_t)(output_size)) << 16U) & 0x3FFF0000U)
#define DPU_SCALER_CONTROL_SCALEMODE_MASK          (0x10U)
#define DPU_SCALER_CONTROL_FILTERMODE_MASK         (0x100U)
#define DPU_SCALER_CONTROL_MODE_MASK               (0x01U)

/* Mask of the register feild ShdEn */
#define DPU_UNIT_SHDEN_MASK 0x01U

#define DPU_LAYERPROPERTY_SOURCEBUFFERENABLE_MASK 0x80000000U
#define DPU_LAYERPROPERTY_CLIPWINDOWENABLE_MASK   0x40000000U
#define DPU_LAYERPROPERTY_PALETTEENABLE_MASK      0x1U
#define DPU_LAYERPROPERTY_GAMMAREMOVE_MASK        0x100000U

#define DPU_EXTDST_STATICCONTROL_KICKMODE_MASK   0x100U
#define DPU_EXTDST_CONTROL_GAMMAAPPLYENABLE_MASK 0x01U

/* Offset of register <unit>_StaticControl in each unit control block. */
#define DPU_STATIC_CONTROL_OFFSET 0x8U
/* Mask of clken in <unit>_dynamic register. */
#define DPU_DYNAMIC_CLKEN_MASK 0x03000000U

#define DPU_PIPELINE_STATIC_SYNCMODE_MASK      (1UL << 8U)
#define DPU_PIPELINE_STATIC_POWERDOWN_MASK     (1UL << 4U)
#define DPU_PIPELINE_STATIC_DIV(x)             (((uint32_t)(x) << 16U) & 0x00ff0000U)
#define DPU_PIPELINE_TRIGGER_SYNC_TRIGGER_MASK (1UL << 0U)
#define DPU_PIPELINE_TRIGGER_SEQ_COMP_MASK     (1UL << 4U)
#define DPU_STORE_START_Start_MASK             (1UL << 0U)

#define DPU_DOMAINBLEND_STATICCONTROL_ShdEn_MASK      (1UL << 0U)
#define DPU_DOMAINBLEND_STATICCONTROL_ShdTokSel(x)    ((uint32_t)(x) << 4U)
#define DPU_DOMAINBLEND_STATICCONTROL_ShdLdSel(x)     ((uint32_t)(x) << 1U)
#define DPU_DOMAINBLEND_CONTROLTRIGGER_ShdTokGen_MASK (1UL << 0U)

#define DPU_DOMAINBLEND_SW                          0x4U
#define DPU_FETCH_STATICCONTROL_SHDLDREQSTICKY_MASK 0xFF000000U
#define DPU_LAYERBLEND_STATICCONTROL_ShdEn_MASK     (1UL << 0U)
#define DPU_LAYERBLEND_STATICCONTROL_ShdTokSel(x)   ((uint32_t)(x) << 3U)
#define DPU_LAYERBLEND_STATICCONTROL_ShdLdSel(x)    ((uint32_t)(x) << 1U)

#define DPU_LAYERBLEND_BLENDCONTROL_BlendAlpha(x)      (((uint32_t)(x)&0xFFU) << 16U)
#define DPU_LAYERBLEND_BLENDCONTROL_PRIM_C_BLD_FUNC(x) (((uint32_t)(x)&0x7U) << 0U)
#define DPU_LAYERBLEND_BLENDCONTROL_SEC_C_BLD_FUNC(x)  (((uint32_t)(x)&0x7U) << 4U)
#define DPU_LAYERBLEND_BLENDCONTROL_PRIM_A_BLD_FUNC(x) (((uint32_t)(x)&0x7U) << 8U)
#define DPU_LAYERBLEND_BLENDCONTROL_SEC_A_BLD_FUNC(x)  (((uint32_t)(x)&0x7U) << 12U)

#define DPU_LAYERBLEND_CONTROL_MODE_MASK            (1UL << 0U)
#define DPU_LAYERBLEND_CONTROL_AlphaMaskEnable_MASK (1UL << 2U)
#define DPU_LAYERBLEND_CONTROL_AlphaMaskMode_MASK   (7UL << 4U)
#define DPU_LAYERBLEND_CONTROL_AlphaMaskEnable(x)   (((uint32_t)(x)&0x1U) << 2U)
#define DPU_LAYERBLEND_CONTROL_AlphaMaskMode(x)     (((uint32_t)(x)&0x7U) << 4U)

#define DPU_BLITBLEND_NEUTRALBORDER_NeutralBorderLeft(x)  (((uint32_t)(x)&0x07U) << 8U)
#define DPU_BLITBLEND_NEUTRALBORDER_NeutralBorderRight(x) (((uint32_t)(x)&0x07U) << 12U)
#define DPU_BLITBLEND_NEUTRALBORDER_NeutralBorderMode(x)  (((uint32_t)(x)&0x01U) << 0U)

#define DPU_BLITBLEND_CONTROL_Mode_MASK (1UL << 0U)

#define DPU_FETCHWARP_WARPCONTROL_WarpBitsPerPixel(x)    (((uint32_t)(x) << 0U) & 0x3FU)
#define DPU_FETCHWARP_WARPCONTROL_WarpCoordinateMode(x)  (((uint32_t)(x)&0x03U) << 8U)
#define DPU_FETCHWARP_WARPCONTROL_WarpSymmetricOffset(x) (((uint32_t)(x)&0x01U) << 12U)

#define DPU_FETCHWARP_ARBDELTA_ArbDeltaXX(x) ((uint32_t)(x) << 0U)
#define DPU_FETCHWARP_ARBDELTA_ArbDeltaXY(x) ((uint32_t)(x) << 8U)
#define DPU_FETCHWARP_ARBDELTA_ArbDeltaYX(x) ((uint32_t)(x) << 16U)
#define DPU_FETCHWARP_ARBDELTA_ArbDeltaYY(x) ((uint32_t)(x) << 24U)

#define DPU_FRAMEGEN_HTCFG1_Htotal(x) (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_HTCFG1_Hact(x)   (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_HTCFG2_Hsync(x)  (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_HTCFG2_Hsbp(x)   (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_HTCFG2_HsEn_MASK (1UL << 31U)
#define DPU_FRAMEGEN_VTCFG1_Vtotal(x) (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_VTCFG1_Vact(x)   (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_VTCFG2_Vsync(x)  (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_VTCFG2_Vsbp(x)   (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_VTCFG2_VsEn_MASK (1UL << 31U)

/* Bit in MDR7 only */
#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
#define DPU_FRAMEGEN_VTCFG2_VsAlign_MASK (1UL << 30U)
#endif

#define DPU_FRAMEGEN_PKICKCONFIG_PKickRow(x)  (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_PKICKCONFIG_PKickCol(x)  (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_PKICKCONFIG_PKickEn_MASK (1UL << 31U)
#define DPU_FRAMEGEN_SKICKCONFIG_SKickRow(x)  (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_SKICKCONFIG_SKickCol(x)  (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_SKICKCONFIG_SKickEn_MASK (1UL << 31U)

#define DPU_FRAMEGEN_PACFG_Pstartx(x)          (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_PACFG_Pstarty(x)          (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_SACFG_Sstartx(x)          (((uint32_t)(x)&0x3FFFU) << 0U)
#define DPU_FRAMEGEN_SACFG_Sstarty(x)          (((uint32_t)(x)&0x3FFFU) << 16U)
#define DPU_FRAMEGEN_FGINCTRL_FgDm(x)          ((uint32_t)(x)&0x07U)
#define DPU_FRAMEGEN_FGINCTRL_EnSecAlpha_MASK  (1UL << 4U)
#define DPU_FRAMEGEN_FGINCTRL_EnPrimAlpha_MASK (1UL << 3U)

#define DPU_FRAMEGEN_FGCCR_CcBlue(x)  (((uint32_t)(x)&0x3FFU) << 0U)
#define DPU_FRAMEGEN_FGCCR_CcGreen(x) (((uint32_t)(x)&0x3FFU) << 10U)
#define DPU_FRAMEGEN_FGCCR_CcRed(x)   (((uint32_t)(x)&0x3FFU) << 20U)
#define DPU_FRAMEGEN_FGCCR_CcAlpha(x) (((uint32_t)(x)&0x1U) << 30U)

#define DPU_FRAMEGEN_FGSLR_ShdTokGen_MASK (1UL << 0U)
#define DPU_FRAMEGEN_FGENABLE_FgEn_MASK   (1UL << 0U)

#define DPU_SIG_STATICCONTROL_ErrThres_SHIFT      16U
#define DPU_SIG_STATICCONTROL_ErrThresReset_SHIFT 24U
#define DPU_SIG_STATICCONTROL_ShdEn_MASK          (1UL << 0U)
#define DPU_SIG_PANICCOLOR_PanicRed_SHIFT         24U
#define DPU_SIG_PANICCOLOR_PanicGreen_SHIFT       16U
#define DPU_SIG_PANICCOLOR_PanicBlue_SHIFT        8U
#define DPU_SIG_PANICCOLOR_PanicAlpha_MASK        (1UL << 7U)
#define DPU_SIG_CONTINUOUSMODE_EnCont_MASK        (1UL << 0U)

typedef union _u32_f32
{
    float f32;
    uint32_t u32;
} u32_f32_t;

#if DPU_USE_GENERATE_HEADER
#define DPU_STORE9_DYNAMIC_OFFSET       DPU_UNIT_OFFSET(PIXENGCFG.STORE9_DYNAMIC)
#define DPU_FETCHDECODE9_DYNAMIC_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.FETCHDECODE9_DYNAMIC)
#define DPU_ROP9_DYNAMIC_OFFSET         DPU_UNIT_OFFSET(PIXENGCFG.ROP9_DYNAMIC)
#define DPU_BLITBLEND9_DYNAMIC_OFFSET   DPU_UNIT_OFFSET(PIXENGCFG.BLITBLEND9_DYNAMIC)
#define DPU_FETCHYUV0_DYNAMIC_OFFSET    DPU_UNIT_OFFSET(PIXENGCFG.FETCHYUV0_DYNAMIC)
#define DPU_H_SCALER9_DYNAMIC_OFFSET    DPU_UNIT_OFFSET(PIXENGCFG.HSCALER9_DYNAMIC)
#define DPU_V_SCALER9_DYNAMIC_OFFSET    DPU_UNIT_OFFSET(PIXENGCFG.VSCALER9_DYNAMIC)
#define DPU_EXTDST0_DYNAMIC_OFFSET      DPU_UNIT_OFFSET(PIXENGCFG.EXTDST0_DYNAMIC)
#define DPU_EXTDST4_DYNAMIC_OFFSET      DPU_UNIT_OFFSET(PIXENGCFG.EXTDST4_DYNAMIC)
#define DPU_EXTDST1_DYNAMIC_OFFSET      DPU_UNIT_OFFSET(PIXENGCFG.EXTDST1_DYNAMIC)
#define DPU_EXTDST5_DYNAMIC_OFFSET      DPU_UNIT_OFFSET(PIXENGCFG.EXTDST5_DYNAMIC)
#define DPU_FETCHDECODE9_DYNAMIC_OFFSET DPU_UNIT_OFFSET(PIXENGCFG.FETCHDECODE9_DYNAMIC)
#define DPU_H_SCALER4_DYNAMIC_OFFSET    DPU_UNIT_OFFSET(PIXENGCFG.HSCALER4_DYNAMIC)
#define DPU_V_SCALER4_DYNAMIC_OFFSET    DPU_UNIT_OFFSET(PIXENGCFG.VSCALER4_DYNAMIC)
#define DPU_LAYERBLEND0_DYNAMIC_OFFSET  DPU_UNIT_OFFSET(PIXENGCFG.LAYERBLEND0_DYNAMIC)
#define DPU_LAYERBLEND1_DYNAMIC_OFFSET  DPU_UNIT_OFFSET(PIXENGCFG.LAYERBLEND1_DYNAMIC)
#define DPU_LAYERBLEND2_DYNAMIC_OFFSET  DPU_UNIT_OFFSET(PIXENGCFG.LAYERBLEND2_DYNAMIC)
#define DPU_LAYERBLEND3_DYNAMIC_OFFSET  DPU_UNIT_OFFSET(PIXENGCFG.LAYERBLEND3_DYNAMIC)

#else /* DPU_USE_GENERATE_HEADER */

#define DPU_STORE9_DYNAMIC_OFFSET       0xE100CU
#define DPU_FETCHDECODE9_DYNAMIC_OFFSET 0x91008U
#define DPU_FETCHROT9_DYNAMIC_OFFSET    0x86008U
#define DPU_ROP9_DYNAMIC_OFFSET         0x41008U
#define DPU_BLITBLEND9_DYNAMIC_OFFSET   0x71008U
#define DPU_H_SCALER9_DYNAMIC_OFFSET    0xB1008U
#define DPU_V_SCALER9_DYNAMIC_OFFSET    0xC1008U
#define DPU_EXTDST0_DYNAMIC_OFFSET      0x11100CU
#define DPU_EXTDST4_DYNAMIC_OFFSET      0x12100CU
#define DPU_EXTDST1_DYNAMIC_OFFSET      0x15100CU
#define DPU_EXTDST5_DYNAMIC_OFFSET      0x16100CU
#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
#define DPU_FETCHYUV0_DYNAMIC_OFFSET    0x1F1008U
#define DPU_H_SCALER4_DYNAMIC_OFFSET    0x241008U
#define DPU_V_SCALER4_DYNAMIC_OFFSET    0x251008U
#else
#define DPU_FETCHYUV0_DYNAMIC_OFFSET    0x201008U
#define DPU_H_SCALER4_DYNAMIC_OFFSET    0x271008U
#define DPU_V_SCALER4_DYNAMIC_OFFSET    0x281008U
#endif
#define DPU_LAYERBLEND1_DYNAMIC_OFFSET  0x171008U
#define DPU_LAYERBLEND2_DYNAMIC_OFFSET  0x181008U
#define DPU_LAYERBLEND3_DYNAMIC_OFFSET  0x191008U
#define DPU_LAYERBLEND4_DYNAMIC_OFFSET  0x1A1008U
#define DPU_LAYERBLEND5_DYNAMIC_OFFSET  0x1B1008U
#define DPU_LAYERBLEND6_DYNAMIC_OFFSET  0x1C1008U
#endif /* DPU_USE_GENERATE_HEADER */

#define DPU_STRUCT_OFFSET(structure, member) (uint32_t)(&((structure *)0)->member)

#define DPU_FETCHECO_FRAMEDIMENSIONS_OFFSET        (uint32_t)(&((DPU_FETCHECO_Type *)0)->FRAMEDIMENSIONS)
#define DPU_FETCHDECODE_FRAMEDIMENSIONS_OFFSET     (uint32_t)(&((DPU_FETCHDECODER_Type *)0)->FRAMEDIMENSIONS)
#define DPU_FETCHYUV_FRAMEDIMENSIONS_OFFSET        (uint32_t)(&((DPU_FETCHYUV_Type *)0)->FRAMEDIMENSIONS)
#define DPU_FETCHLAYER_FRAMEDIMENSIONS_OFFSET      (uint32_t)(&((DPU_FETCHLAYER_Type *)0)->FRAMEDIMENSIONS)
#define DPU_FETCHROT_FRAMEDIMENSIONS_OFFSET        (uint32_t)(&((DPU_FETCHROT_Type *)0)->FRAMEDIMENSIONS)
#define DPU_FETCHECO_FRAMERESAMPLING_OFFSET        (uint32_t)(&((DPU_FETCHECO_Type *)0)->FRAMERESAMPLING)
#define DPU_FETCHDECODE_FRAMERESAMPLING_OFFSET     (uint32_t)(&((DPU_FETCHDECODER_Type *)0)->FRAMERESAMPLING)
#define DPU_FETCHYUV_FRAMERESAMPLING_OFFSET        (uint32_t)(&((DPU_FETCHYUV_Type *)0)->FRAMERESAMPLING)
#define DPU_FETCHLAYER_FRAMERESAMPLING_OFFSET      (uint32_t)(&((DPU_FETCHLAYER_Type *)0)->FRAMERESAMPLING)
#define DPU_FETCHROT_FRAMERESAMPLING_OFFSET        (uint32_t)(&((DPU_FETCHROT_Type *)0)->FRAMERESAMPLING)
#define DPU_FETCHECO_CONTROL_OFFSET                (uint32_t)(&((DPU_FETCHECO_Type *)0)->CONTROL)
#define DPU_FETCHDECODE_CONTROL_OFFSET             (uint32_t)(&((DPU_FETCHDECODER_Type *)0)->CONTROL)
#define DPU_FETCHYUV_CONTROL_OFFSET                (uint32_t)(&((DPU_FETCHYUV_Type *)0)->CONTROL)
#define DPU_FETCHLAYER_CONTROL_OFFSET              (uint32_t)(&((DPU_FETCHLAYER_Type *)0)->CONTROL)
#define DPU_FETCHROT_CONTROL_OFFSET                (uint32_t)(&((DPU_FETCHROT_Type *)0)->CONTROL)
#define DPU_FETCHECO_SUBLAYER_CONTROL_OFFSET       (uint32_t)(&((DPU_FETCHECO_Type *)0)->LAYER)
#define DPU_FETCHDECODE_SUBLAYER_CONTROL_OFFSET    (uint32_t)(&((DPU_FETCHDECODER_Type *)0)->LAYER)
#define DPU_FETCHYUV_SUBLAYER_CONTROL_OFFSET       (uint32_t)(&((DPU_FETCHYUV_Type *)0)->LAYER)
#define DPU_FETCHLAYER_SUBLAYER_CONTROL_OFFSET     (uint32_t)(&((DPU_FETCHLAYER_Type *)0)->LAYER)
#define DPU_FETCHROT_SUBLAYER_CONTROL_OFFSET       (uint32_t)(&((DPU_FETCHROT_Type *)0)->LAYER)
#define DPU_FETCHUNIT_BURSTBUFFERMANAGEMENT_OFFSET (uint32_t)(&((DPU_FETCHROT_Type *)0)->BURSTBUFFERMANAGEMENT)

#define DPU_BURSTBUFFERMANAGEMENT_SETNUMBUFFERS(x)  (((uint32_t)(x) << 0U) & 0xffU)
#define DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(x) (((uint32_t)(x) << 8U) & 0x1f00U)

#define DPU_MAKE_FETCH_RESAMPLING(swap, deltaX, deltaY, startX, startY)                      \
    (((uint32_t)(swap) << 24U) | ((uint32_t)(deltaY) << 18U) | ((uint32_t)(deltaX) << 12U) | \
     ((uint32_t)(startY) << 6U) | (uint32_t)(startX))

#define DPU_FETCH_CONTROL_RASTERMODE_MASK           0x7U
#define DPU_FETCH_CONTROL_INPUTSELECT_MASK          0x18U
#define DPU_FETCH_CONTROL_YUV422UPSAMPLINGMODE_MASK 0x20U
#define DPU_FETCH_CONTROL_RAWPIXEL_MASK             0x80U
#define DPU_FETCH_CONTROL_PALETTEIDXWIDTH_MASK      0x700U
#define DPU_FETCH_CONTROL_CLIPCOLOR_MASK            0x10000U
#define DPU_FETCH_CONTROL_FILTERMODE_MASK           0x1C00000U

#define DPU_FETCH_CONTROL_RASTERMODE(x)           ((uint32_t)(x))
#define DPU_FETCH_CONTROL_INPUTSELECT(x)          ((uint32_t)(x) << 3U)
#define DPU_FETCH_CONTROL_YUV422UPSAMPLINGMODE(x) ((uint32_t)(x) << 5U)
#define DPU_FETCH_CONTROL_RAWPIXEL(x)             ((uint32_t)(x) << 7U)
#define DPU_FETCH_CONTROL_PALETTEIDXWIDTH(x)      ((uint32_t)(x) << 8U)
#define DPU_FETCH_CONTROL_CLIPCOLOR(x)            ((uint32_t)(x) << 16U)
#define DPU_FETCH_CONTROL_FILTERMODE(x)           ((uint32_t)(x) << 22U)

/*! @brief Fetch unit control input select, selects function for the frame input port. */
enum _dpu_fetch_ctrl_input_sel
{
    kDPU_FetchCtrlInputSelInactive   = 0x00U, /*!< Not used. */
    kDPU_FetchCtrlInputSelCompPack   = 0x01U, /*!< Used for component packing, e.g. UV or source alpha buffer. */
    kDPU_FetchCtrlInputSelAlphaMask  = 0x02U, /*!< Used for RGB and alpha pre-multiply stage (mask alpha buffer). */
    kDPU_FetchCtrlInputSelCoordinate = 0x03U, /*!< Used for arbitrary warping. */
};

/*! @brief Fetch unit control input select, selects function for the frame input port. */
enum _dpu_fetch_ctrl_raster_mode
{
    kDPU_FetchCtrlRasterNormal      = 0x00U,
    kDPU_FetchCtrlRasterDecode      = 0x01U,
    kDPU_FetchCtrlRasterArbitrary   = 0x02U,
    kDPU_FetchCtrlRasterPerspective = 0x03U,
    kDPU_FetchCtrlRasterYUV422      = 0x04U,
    kDPU_FetchCtrlRasterAffine      = 0x05U,
};

/*! @brief Fetch unit control filter mode. */
enum _dpu_fetch_ctrl_filter_mode
{
    kDPU_FetchCtrlFilterNearest  = 0U, /*!< Chooses pixel closest to sample point */
    kDPU_FetchCtrlFilterBilinear = 1U, /*!< Calculates result from 4 pixels closest to sample point */
    kDPU_FetchCtrlFilterFir2     = 2U, /*!< FIR mode with 2 programmable pixel positions and coefficients */
    kDPU_FetchCtrlFilterFir4     = 3U, /*!< FIR mode with 4 programmable pixel positions and coefficients */
    kDPU_FetchCtrlFilterHorLinear =
        4U, /*!< Calculates result from 2 pixels closest to the sample point and on the same line */
};

static bool DPU_CheckBufferAlignment(uint8_t bitsPerPixel, uint32_t baseAddr, uint32_t strideBytes)
{
    uint32_t mask = 0U;
    uint32_t i;
    bool ret;

    /*
     * Frame buffer alignment restrictions:
     *   32 bpp: Base address and stride must be a multiple of 4 bytes.
     *   16 bpp: Base address and stride must be a multiple of 2 bytes.
     *   others: any byte alignment allowed
     */
    static const uint32_t s_dpuBufferAlignMask[][2] = {
        {32U, 0x03U},
        {16U, 0x01U},
    };

    /* Find the mask to compare. */
    for (i = 0U; i < ARRAY_SIZE(s_dpuBufferAlignMask); i++)
    {
        if (s_dpuBufferAlignMask[i][0] == bitsPerPixel)
        {
            mask = s_dpuBufferAlignMask[i][1];
            break;
        }
    }

    if (0U != ((baseAddr & mask) | (strideBytes & mask)))
    {
        ret = false;
    }
    else
    {
        ret = true;
    }

    return ret;
}

#define DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(x) (((uint32_t)(x) << 8U) & 0x1f00U)

/*! @brief DPU unit dynamic register offset. */
typedef struct _dpu_unit_dynamic_reg_offset
{
    dpu_unit_t unit;
    uint32_t offset;
} dpu_unit_dynamic_reg_offset_t;

/*!
 * @name Macros for pixel format.
 *
 * In DPU, the pixel format are controlled by three parameters,
 * ColorComponentBits, ColorComponentShift, and PixelPerBits. These macros define
 * the parameter values for different pixel format, they could be used during
 * source buffer and Destination buffer configuration.
 *
 * The width of color components as stored in memory can be setup individually to
 * any value between
 *   - 0 and 10 bits for RGB or YUV
 *   - 0 and 8 bits for Alpha and Index
 * Any bit position within the pixel word can be configured individually for each
 * component. There are no restrictions regarding sequence or overlaps.
 *
 * Example for RGB565 (16 bpp):
 * @verbatim
   |--------------- total size --------------------|
   |15|14|13|12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| 1| 0|
   |---bluebits---|----greenbits----|---redbits----|
                  |---------- blue shift ----------|
                                    |-green shift -|
   @endverbatim
 *
 * The value for components that are setup to null size is taken from constant color.
 *
 * If the @p itu is set to 1, then the ITU656 compatibility mode is used, the max value
 * of 10-bit YUV codes is considered 1020 instead of 1023.
 * @{
 */
#define DPU_MAKE_COLORCOMPONENTBITS(itu, redbits, greenbits, bluebits, alphabits) \
    (((itu) << 31U) | ((redbits) << 24U) | ((greenbits) << 16U) | ((bluebits) << 8U) | (alphabits))
#define DPU_MAKE_COLORCOMPONENTSHIFT(redshift, greenshift, blueshift, alphashift) \
    (((redshift) << 24U) | ((greenshift) << 16U) | ((blueshift) << 8U) | (alphashift))
/*
 * @}
 */

/*!
 * @brief DPU pixel format definition.
 *
 * This table works together with @ref dpu_pixel_format_t.
 */
static const uint32_t s_dpuColorComponentFormats[][2] = {
    /* kDPU_PixelFormatGray8 */
    {
        DPU_MAKE_COLORCOMPONENTBITS(0, 8, 8, 8, 0),
        DPU_MAKE_COLORCOMPONENTSHIFT(0, 0, 0, 0),
    },
    /* kDPU_PixelFormatRGB565 */
    {
        DPU_MAKE_COLORCOMPONENTBITS(0, 5, 6, 5, 0),
        DPU_MAKE_COLORCOMPONENTSHIFT(11, 5, 0, 0),
    },
    /* kDPU_PixelFormatARGB8888 */
    {
        DPU_MAKE_COLORCOMPONENTBITS(0, 8, 8, 8, 8),
        DPU_MAKE_COLORCOMPONENTSHIFT(16, 8, 0, 24),
    },
    /* kDPU_PixelFormatRGB888 */
    {
        DPU_MAKE_COLORCOMPONENTBITS(0, 8, 8, 8, 0),
        DPU_MAKE_COLORCOMPONENTSHIFT(16, 8, 0, 0),
    },
    /* kDPU_PixelFormatARGB1555 */
    {
        DPU_MAKE_COLORCOMPONENTBITS(0, 5, 5, 5, 1),
        DPU_MAKE_COLORCOMPONENTSHIFT(10, 5, 0, 15),
    },
};

/*! @brief Map to get the dynamic register in PIXENG for DPU unit.  */
static const dpu_unit_dynamic_reg_offset_t s_dpuUnitDynamicRegOffsetTable[] = {
    {
        .unit   = kDPU_Store9,
        .offset = DPU_STORE9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_FetchDecode9,
        .offset = DPU_FETCHDECODE9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_FetchRot9,
        .offset = DPU_FETCHROT9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_BlitBlend9,
        .offset = DPU_BLITBLEND9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_Rop9,
        .offset = DPU_ROP9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_FetchYuv0,
        .offset = DPU_FETCHYUV0_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_Hscaler9,
        .offset = DPU_H_SCALER9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_Vscaler9,
        .offset = DPU_V_SCALER9_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_Hscaler4,
        .offset = DPU_H_SCALER4_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_Vscaler4,
        .offset = DPU_V_SCALER4_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_ExtDst0,
        .offset = DPU_EXTDST0_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_ExtDst4,
        .offset = DPU_EXTDST4_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_ExtDst1,
        .offset = DPU_EXTDST1_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_ExtDst5,
        .offset = DPU_EXTDST5_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_LayerBlend1,
        .offset = DPU_LAYERBLEND1_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_LayerBlend2,
        .offset = DPU_LAYERBLEND2_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_LayerBlend3,
        .offset = DPU_LAYERBLEND3_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_LayerBlend4,
        .offset = DPU_LAYERBLEND4_DYNAMIC_OFFSET,
    },
    {
        .unit   = kDPU_LayerBlend5,
        .offset = DPU_LAYERBLEND5_DYNAMIC_OFFSET,
    },
#if !(defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7)
    {
        .unit   = kDPU_LayerBlend6,
        .offset = DPU_LAYERBLEND6_DYNAMIC_OFFSET,
    },
#endif
};

/*!
 * @brief Convert IEEE 754 float value to the value could be written to registers.
 *
 * This function converts the float value to integer value to set the scaler parameters.
 *
 * @param floatValue The float value to convert.
 * @param intBits Bits number of integer part in result.
 * @param fracBits Bits number of fractional part in result.
 * @return The value to set to register.
 */
static uint32_t DPU_ConvertFloat(float floatValue, uint8_t intBits, uint8_t fracBits);

/*!
 * @brief Get the DPU instance from peripheral base address.
 *
 * @param base DPU peripheral base address.
 * @return DPU instance.
 */
uint32_t DPU_GetInstance(DISPLAY_SEERIS_Type *base);

static const uint32_t s_displayOffsetArray[]   = {DPU_FRAME_GEN0_OFFSET, DPU_FRAME_GEN1_OFFSET};
static const uint32_t s_ditherOffsettArray[]   = {DPU_DITHER0_CONFIG_OFFSET, DPU_DITHER1_CONFIG_OFFSET};
static DISPLAY_SEERIS_Type *const s_dpuBases[] = DISPLAY_SEERIS_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of DPU clock name. */
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*!
 * brief Initializes the DPU peripheral.
 *
 * This function ungates the DPU clock.
 *
 * param base DPU peripheral base address.
 *
 */

static DPU_SUBLAYER_CONTROL_Type *DPU_GetSubLayer(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer)
{
    /* The sublayer register offset in the fetch unit control block. */
    uint32_t offset;

    /* If the fetch unit does not support sublayer, then configure sublayer 0. */
    if (0U == ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrSubLayer)))
    {
        sublayer = 0;
    }

    if ((uint32_t)kDPU_FetchDecode == DPU_GET_UNIT_TYPE(unit))
    {
        offset = DPU_FETCHDECODE_SUBLAYER_CONTROL_OFFSET;
    }
    else if ((uint32_t)KDPU_FetchYuv == DPU_GET_UNIT_TYPE(unit))
    {
        offset = DPU_FETCHYUV_SUBLAYER_CONTROL_OFFSET;
    }
    else if ((uint32_t)kDPU_FetchEco == DPU_GET_UNIT_TYPE(unit))
    {
        offset = DPU_FETCHECO_SUBLAYER_CONTROL_OFFSET;
    }
    else if ((uint32_t)kDPU_FetchRot == DPU_GET_UNIT_TYPE(unit))
    {
        offset = DPU_FETCHROT_SUBLAYER_CONTROL_OFFSET;
    }
    else
    {
        offset = DPU_FETCHLAYER_SUBLAYER_CONTROL_OFFSET;
    }

    return (DPU_SUBLAYER_CONTROL_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit) + offset +
                                         (uint32_t)sublayer * sizeof(DPU_SUBLAYER_CONTROL_Type));
}

static uint32_t DPU_ConvertFloat(float floatValue, uint8_t intBits, uint8_t fracBits)
{
    /* One bit reserved for sign bit. */
    assert(intBits + fracBits + 1U < 32U);

    u32_f32_t u32_f32;
    uint32_t ret;
    uint32_t expBits;

    u32_f32.f32        = floatValue;
    uint32_t floatBits = u32_f32.u32;
    expBits            = (floatBits & 0x7F800000U) >> 23U;
    int32_t expValue   = (int32_t)expBits - 127;

    ret = (floatBits & 0x007FFFFFU) | 0x00800000U;
    expValue += (int32_t)fracBits;

    if (expValue < 0)
    {
        return 0U;
    }
    else if (expValue > 23)
    {
        /* should not exceed 31-bit when left shift. */
        assert((expValue - 23) <= 7);
        ret <<= ((uint32_t)expValue - 23UL);
    }
    else
    {
        ret >>= (23UL - (uint32_t)expValue);
    }

    /* Set the sign bit. */
    if (0U != (floatBits & 0x80000000UL))
    {
        ret = ((~(uint32_t)ret) + 1U) & ~(0xFFFFFFFFU << (intBits + fracBits + 1U));
    }

    return ret;
}

void DPU_Init(DISPLAY_SEERIS_Type *base)
{
    /*
     * No dpu dedicate clock, related root clocks were enabled in dpu_board.c.
     * Enable domainmask for store9 and extdst0, 1, 4, 5.
     */
#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
    /* MDR7 version. */
    DISPLAY__SEERIS__DOMAINMA->STOR9DM |= DOMAINMASK_ENABLE;
    DISPLAY__SEERIS__DOMAINMA->EXTD0DK0 |= DOMAINMASK_ENABLE;
    DISPLAY__SEERIS__DOMAINMA->EXTD4DK0 |= DOMAINMASK_ENABLE;
    DISPLAY__SEERIS__DOMAINMA->EXTD1DK0 |= DOMAINMASK_ENABLE;
    DISPLAY__SEERIS__DOMAINMA->EXTD5DK0 |= DOMAINMASK_ENABLE;
#else
    /* MDR5 version */
    base->DOMAINMASK_STORE9_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST0_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST4_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST1_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST5_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
#endif
}

/*!
 * brief Deinitializes the DPU peripheral.
 *
 * This function gates the DPU clock.
 *
 * param base DPU peripheral base address.
 */
void DPU_Deinit(DISPLAY_SEERIS_Type *base)
{
    uint8_t i;

    /* Disable display output. */
    for (i = 0U; i < DPU_DISPLAY_COUNT; i++)
    {
        DPU_StopDisplay(base, i);
    }

    /* Power down all pipline. */
    DPU_DeinitPipeline(base, kDPU_PipelineExtDst0);
    DPU_DeinitPipeline(base, kDPU_PipelineExtDst1);
    DPU_DeinitPipeline(base, kDPU_PipelineExtDst4);
    DPU_DeinitPipeline(base, kDPU_PipelineExtDst5);
    DPU_DeinitPipeline(base, kDPU_PipelineStore9);

    /* Clear all pending interrupts. */
    for (i = 0U; i < DPU_INT_GROUP_NUM; i++)
    {
        DPU_DisableInterrupts(base, i, 0xFFFFFFFFU);
        DPU_ClearInterruptsPendingFlags(base, i, 0xFFFFFFFFU);
    }

}

/*!
 * brief Prepare the unit path configuration.
 *
 * The DPU has a default path configuration. Before changing the configuration,
 * this function could be used to break all the original path. This make sure
 * one pixel engine unit is not used in multiple pipelines.
 *
 * param base DPU peripheral base address.
 */
void DPU_PreparePathConfig(DISPLAY_SEERIS_Type *base)
{
    const dpu_unit_t dpuPipeLines[] = {
        kDPU_PipelineStore9, kDPU_PipelineExtDst0, kDPU_PipelineExtDst1, kDPU_PipelineExtDst4, kDPU_PipelineExtDst5,
    };

    /* Disable shadow for all pipelines. */
    for (uint32_t i = 0; i < ARRAY_SIZE(dpuPipeLines); i++)
    {
        (void)DPU_EnableShadowLoad(base, dpuPipeLines[i], false);
    }

    /* Set all pixel engine unit source to NULL. */
    const dpu_unit_t dpuUnits[] = {
        kDPU_FetchDecode9, kDPU_Hscaler9,    kDPU_Vscaler9,    kDPU_Rop9,        kDPU_BlitBlend9,
        kDPU_Store9,       kDPU_ExtDst0,     kDPU_ExtDst4,     kDPU_ExtDst1,     kDPU_ExtDst5,
        kDPU_Hscaler4,     kDPU_Vscaler4,    kDPU_FetchRot9,   kDPU_FetchYuv0,   kDPU_FetchYuv1,
        kDPU_LayerBlend1,  kDPU_LayerBlend2, kDPU_LayerBlend3, kDPU_LayerBlend4, kDPU_FetchYuv3,
        kDPU_LayerBlend5,
#if !(defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7)
	kDPU_LayerBlend6,  kDPU_FetchYuv2
#endif
    };
    for (uint32_t i = 0; i < ARRAY_SIZE(dpuUnits); i++)
    {
        DPU_SetUnitSrc(base, dpuUnits[i], 0U);
    }

/* Enable fetchlayer shdldreq Sticky */
#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
    DISPLAY__SEERIS__FETCHLAY->SHDLRCON |= SHDLDREQSTICKY_ENABLE;
    DISPLAY__SEERIS__FETCHL13->SHDLRCON |= SHDLDREQSTICKY_ENABLE;
#else
    base->PIXENG_FETCHLAYER0_SHDLDREQCONTROL |= SHDLDREQSTICKY_ENABLE;
    base->PIXENG_FETCHLAYER1_SHDLDREQCONTROL |= SHDLDREQSTICKY_ENABLE;
#endif
}

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
void DPU_EnableInterrupts(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask)
{
    assert(group < DPU_INT_GROUP_NUM);

    ((DPU_COMCTRL_Type *)((uint32_t)base + DPU_COMCTRL_OFFSET))->IRQ_INTERRUPTENABLE[group] |= mask;
}

/*******************************************************************************
 * Code
 ******************************************************************************/

uint32_t DPU_GetInstance(DISPLAY_SEERIS_Type *base)
{
    uint32_t instance;
    const uint32_t dpuArrayCount = ARRAY_SIZE(s_dpuBases);

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < dpuArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_dpuBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < dpuArrayCount);

    return instance;
}

/*!
 * brief Enable or disable the register shadowing for the DPU process units.
 *
 * For example, to enable the shadowing of all RWS registers of the pipeline with endpoint Store9.
 * code
   DPU_EnableShadowLoad(DPU, kDPU_PipelineStore9, true);
   endcode
 *
 * param base DPU peripheral base address.
 * param unit The unit whose shadow load to enable or disable, see ref dpu_unit_t.
 * param enable True to enable, false to disable.
 * retval kStatus_Success The shadow load is enabled or disabled successfully.
 * retval kStatus_InvalidArgument The unit does not support shadow load.
 */
status_t DPU_EnableShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable)
{
    /* Offset of the static control register to enable/disable shadow load. */
    uint32_t staticRegOffset;
    status_t status;

    if (0U != ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrNoShdow)))
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        staticRegOffset = DPU_GET_UNIT_OFFSET(unit) + DPU_STATIC_CONTROL_OFFSET;

        if (enable)
        {
            DPU_REG(base, staticRegOffset) |= DPU_UNIT_SHDEN_MASK;
        }
        else
        {
            DPU_REG(base, staticRegOffset) &= ~DPU_UNIT_SHDEN_MASK;
        }

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Initialize the pipeline.
 *
 * param base DPU peripheral base address.
 * param unit The DPU pipeline unit.
 */
void DPU_InitPipeline(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    assert((uint32_t)kDPU_Pipeline == DPU_GET_UNIT_TYPE(unit));

    DPU_PIPELINE_Type *pipeline = (DPU_PIPELINE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Set pipeline sync mode to single mode, power up, and enable shadow load. */
    pipeline->STATIC &= ~DPU_PIPELINE_STATIC_POWERDOWN_MASK;
    pipeline->STATIC |= DPU_UNIT_SHDEN_MASK;
}

/*!
 * brief Deinitializes the pipeline.
 *
 * Power down the pipeline and disable the shadow load feature.
 *
 * param base DPU peripheral base address.
 * param unit The DPU pipeline unit.
 */
void DPU_DeinitPipeline(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    assert((uint32_t)kDPU_Pipeline == DPU_GET_UNIT_TYPE(unit));

    DPU_PIPELINE_Type *pipeline = (DPU_PIPELINE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Disable shadow load and powerdown the pipeline. */
    pipeline->STATIC |= DPU_PIPELINE_STATIC_POWERDOWN_MASK;
}

/*!
 * brief Trigger the pipeline shadow load.
 *
 * This function triggers the pipeline reconfiguration.
 *
 * param base DPU peripheral base address.
 * param unit The DPU pipeline unit.
 */
void DPU_TriggerPipelineShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    assert((uint32_t)kDPU_Pipeline == DPU_GET_UNIT_TYPE(unit));

    DPU_PIPELINE_Type *pipeline = (DPU_PIPELINE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    pipeline->TRIGGER = DPU_PIPELINE_TRIGGER_SYNC_TRIGGER_MASK;
}

/*!
 * @brief Get the offset of the register <unit>_dynamic.
 *
 * Only the unit with attribute @ref kDPU_UnitAttrHasSrc could use this function.
 *
 * @param unit See @ref dpu_unit_t.
 * @return Offset of <unit>_dynamic.
 */
static uint32_t DPU_GetDynamicRegOffset(dpu_unit_t unit)
{
    uint32_t offset = 0U;
    uint32_t i;

    for (i = 0; i < ARRAY_SIZE(s_dpuUnitDynamicRegOffsetTable); i++)
    {
        if (s_dpuUnitDynamicRegOffsetTable[i].unit == unit)
        {
            offset = s_dpuUnitDynamicRegOffsetTable[i].offset;
            break;
        }
    }

    return offset;
}

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
void DPU_InitStore(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    DPU_STORE_Type *store;

    assert((uint32_t)kDPU_Store == DPU_GET_UNIT_TYPE(unit));

    store = (DPU_STORE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Enable Shadow. */
    store->STATICCONTROL |= DPU_UNIT_SHDEN_MASK;

    /* Disable ring buffer. */
    store->RINGBUFSTARTADDR = 0U;
    store->RINGBUFWRAPADDR  = 0U;

    /* Burst management. */
    store->BURSTBUFFERMANAGEMENT = DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(16);

    /* Set input source selection (the register dynamic). */
    DPU_SetUnitSrc(base, unit, srcReg);
}

/*!
 * brief Set the Store unit Destination buffer configuration.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Store unit here.
 * param config Pointer to the configuration.
 * retval kStatus_Success Initialization success.
 * retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_SetStoreDstBufferConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_dst_buffer_config_t *config)
{
    assert(NULL != config);

    /* Buffer should be aligned. */
    if (!(DPU_CheckBufferAlignment(config->bitsPerPixel, config->baseAddr, config->strideBytes)))
    {
        return kStatus_InvalidArgument;
    }

    DPU_STORE_Type *store = (DPU_STORE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    store->BASEADDRESS0    = config->baseAddr;
    store->BASEADDRESSMSB0 = 0;
    store->DESTINATIONBUFFERATTRIBUTES0 =
        DPU_MAKE_DESTINATIONBUFFERATTRIBUTES(config->bitsPerPixel, config->strideBytes);
    store->DESTINATIONBUFFERDIMENSION = DPU_MAKE_DIMENSION(config->bufferHeight - 1UL, config->bufferWidth - 1UL);
    store->COLORCOMPONENTBITS         = s_dpuColorComponentFormats[config->pixelFormat][0];
    store->COLORCOMPONENTSHIFT        = s_dpuColorComponentFormats[config->pixelFormat][1];

    return kStatus_Success;
}

/*!
 * brief Set the DPU unit input source selection.
 *
 * Sets the DPU unit input source, the input source is controlled by the
 * register \<unit\>_dynamic in "Pixel Engin Top Level". This function writes
 * the register \<unit\>_dynamic directly, please check the reference manual
 * for the register details. This function only changes the input source
 * control bits in register.
 *
 * param base DPU peripheral base address.
 * param unit The DPU pipeline unit.
 * param srcReg The value written to register \<unit\>_dynamic. Could be
 *               generated using ref DPU_MAKE_SRC_REG1, ref DPU_MAKE_SRC_REG2,
 *               and ref DPU_MAKE_SRC_REG3.
 */
void DPU_SetUnitSrc(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    assert(0U != ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrHasSrc)));

    uint32_t reg;
    uint32_t offset = DPU_GetDynamicRegOffset(unit);

    reg                   = DPU_REG(base, offset) & DPU_DYNAMIC_CLKEN_MASK;
    DPU_REG(base, offset) = reg | (srcReg & ~DPU_DYNAMIC_CLKEN_MASK);
}

/*!
 * brief Get the default configuration for Store unit.
 *
 * The default value is:
 * code
    config->baseAddr = 0U;
    config->strideBytes = 0x500U;
    config->bitsPerPixel = 32U,
    config->pixelFormat = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth = 0U;
   endcode
 * param config Pointer to the configuration.
 */
void DPU_DstBufferGetDefaultConfig(dpu_dst_buffer_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->baseAddr     = 0U;
    config->strideBytes  = 0x500U;
    config->bitsPerPixel = 32U;
    config->pixelFormat  = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth  = 0U;
}

/*!
 * brief Start the Store unit.
 *
 * This function starts the Store unit to save the frame to output buffer. When
 * the frame store completed, the interrupt flag ref kDPU_Group0Store9FrameCompleteInterrupt
 * asserts.
 *
 * For better performance, it is allowed to set next operation while current is still in progress.
 * Upper layer could set next operation immediately after shadow load finished.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Store unit here.
 */
void DPU_StartStore(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    DPU_STORE_Type *store = (DPU_STORE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    store->START = DPU_STORE_START_Start_MASK;
}

/*!
 * brief Get default configuration structure for LayerBlend.
 *
 * The default value is:
 * code
    config->constAlpha = 0U;
    config->secAlphaBlendMode = kDPU_BlendOne;
    config->primAlphaBlendMode = kDPU_BlendZero;
    config->secColorBlendMode = kDPU_BlendOne;
    config->primColorBlendMode = kDPU_BlendZero;
    config->enableAlphaMask = true;
    config->alphaMaskMode = kDPU_AlphaMaskPrim;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_LayerBlendGetDefaultConfig(dpu_layer_blend_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->constAlpha         = 0U;
    config->secAlphaBlendMode  = kDPU_BlendOne;
    config->primAlphaBlendMode = kDPU_BlendZero;
    config->secColorBlendMode  = kDPU_BlendOne;
    config->primColorBlendMode = kDPU_BlendZero;
    config->enableAlphaMask    = false;
    config->alphaMaskMode      = kDPU_AlphaMaskPrim;
}

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
void DPU_InitLayerBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    DPU_LAYERBLEND_Type *layerBlend;

    assert((uint32_t)kDPU_LayerBlend == DPU_GET_UNIT_TYPE(unit));

    layerBlend = (DPU_LAYERBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Shadow token generate mode: BOTH. Shadow load mode: Both. */
    layerBlend->STATICCONTROL = DPU_LAYERBLEND_STATICCONTROL_ShdEn_MASK |
                                DPU_LAYERBLEND_STATICCONTROL_ShdTokSel(kDPU_LayerBlendShadowTokenBoth) |
                                DPU_LAYERBLEND_STATICCONTROL_ShdLdSel(kDPU_LayerBlendShadowLoadBoth);

    /*
     * Disable second frame overlay position. Explaination from the spec:
     * Note: Technically the foreground plane can be setup with a smaller dimension
     * than the background and placed by the LayerBlend unit itself (Position.XPOS/YPOS),
     * however, this must not be done for the following reasons:
     *   - Layer overlay must be completely inside the background area then, otherwise
     *   display tearing may result. This would require clip window computations by SW.
     *   - Timing setup for certain use cases is not valid any longer, because Fetch unit
     *   starts fetching source buffer data for a layer not at position of first overlay
     *   pixel, but at first pixel of the background plane already.
     *   - Layer position is not part of the shadow load domain correlated to the layer,
     *   but to the stream.
     */
    layerBlend->POSITION = 0U;

    DPU_SetUnitSrc(base, unit, srcReg);
}

/*!
 * brief Set the LayerBlend unit configuration.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be LayerBlend unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_SetLayerBlendConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_layer_blend_config_t *config)
{
    assert(NULL != config);

    DPU_LAYERBLEND_Type *layerBlend;

    layerBlend = (DPU_LAYERBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Set layer blend control. */
    layerBlend->BLENDCONTROL = DPU_LAYERBLEND_BLENDCONTROL_BlendAlpha(config->constAlpha) |
                               DPU_LAYERBLEND_BLENDCONTROL_PRIM_C_BLD_FUNC(config->primColorBlendMode) |
                               DPU_LAYERBLEND_BLENDCONTROL_SEC_C_BLD_FUNC(config->secColorBlendMode) |
                               DPU_LAYERBLEND_BLENDCONTROL_PRIM_A_BLD_FUNC(config->primAlphaBlendMode) |
                               DPU_LAYERBLEND_BLENDCONTROL_SEC_A_BLD_FUNC(config->secAlphaBlendMode);

    /* Set alpha mask config. */
    layerBlend->CONTROL = ((layerBlend->CONTROL & ~(DPU_LAYERBLEND_CONTROL_AlphaMaskEnable_MASK |
                                                    DPU_LAYERBLEND_CONTROL_AlphaMaskMode_MASK)) |
                           DPU_LAYERBLEND_CONTROL_AlphaMaskEnable(config->enableAlphaMask ? 1U : 0U) |
                           DPU_LAYERBLEND_CONTROL_AlphaMaskMode(config->alphaMaskMode));
}

/*!
 * brief Enable or disable the LayerBlend unit.
 *
 * If enabled, the blend result is output, otherwise, the primary input is output.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be LayerBlend unit here.
 * param enable Pass true to enable, false to disable.
 */
void DPU_EnableLayerBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable)
{
    DPU_LAYERBLEND_Type *layerBlend = (DPU_LAYERBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    if (enable)
    {
        layerBlend->CONTROL |= DPU_LAYERBLEND_CONTROL_MODE_MASK;
    }
    else
    {
        layerBlend->CONTROL &= ~DPU_LAYERBLEND_CONTROL_MODE_MASK;
    }
}

/*!
 * brief Initialize the ConstFrame unit.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be ConstFrame unit here.
 */
void DPU_InitConstFrame(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    assert((uint32_t)kDPU_ConstFrame == DPU_GET_UNIT_TYPE(unit));

    DPU_CONSTFRAME_Type *constFrame = (DPU_CONSTFRAME_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    constFrame->STATICCONTROL = DPU_UNIT_SHDEN_MASK;
}

/*!
 * brief Get default configuration structure for ConstFrame unit.
 *
 * The default value is:
   code
    config->frameHeight = 320U;
    config->frameWidth = 480U;
    config->constColor = DPU_MAKE_CONST_COLOR(0xFF, 0xFF, 0xFF, 0xFF);
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_ConstFrameGetDefaultConfig(dpu_const_frame_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->frameHeight = 320U;
    config->frameWidth  = 480U;
    config->constColor  = DPU_MAKE_CONST_COLOR(0xFF, 0xFF, 0xFF, 0xFF);
}

/*!
 * brief Set the ConstFrame unit configuration.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be ConstFrame unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_SetConstFrameConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_const_frame_config_t *config)
{
    assert(NULL != config);

    DPU_CONSTFRAME_Type *constFrame = (DPU_CONSTFRAME_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    constFrame->FRAMEDIMENSIONS = DPU_MAKE_DIMENSION(config->frameHeight - 1UL, config->frameWidth - 1UL);
    constFrame->CONSTANTCOLOR   = config->constColor;
}

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
void DPU_InitBlitBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    assert((uint32_t)kDPU_BlitBlend == DPU_GET_UNIT_TYPE(unit));

    DPU_BLITBLEND_Type *blitBlend = (DPU_BLITBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    blitBlend->STATICCONTROL = DPU_UNIT_SHDEN_MASK;

    DPU_SetUnitSrc(base, unit, srcReg);
}

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
void DPU_EnableBlitBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable)
{
    DPU_BLITBLEND_Type *blitBlend = (DPU_BLITBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    if (enable)
    {
        blitBlend->CONTROL = DPU_BLITBLEND_CONTROL_Mode_MASK;
    }
    else
    {
        blitBlend->CONTROL = 0U;
    }
}

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
void DPU_InitRop(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    assert((uint32_t)kDPU_Rop == DPU_GET_UNIT_TYPE(unit));

    DPU_ROP_Type *rop = (DPU_ROP_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    rop->STATICCONTROL = DPU_UNIT_SHDEN_MASK;

    DPU_SetUnitSrc(base, unit, srcReg);
}

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
void DPU_RopGetDefaultConfig(dpu_rop_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->controlFlags = 0U;
    config->alphaIndex   = 0U;
    config->blueIndex    = 0U;
    config->greenIndex   = 0U;
    config->redIndex     = 0U;
}

/*!
 * brief Set the ROp unit configuration.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Rop unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_SetRopConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_rop_config_t *config)
{
    assert(NULL != config);

    DPU_ROP_Type *rop = (DPU_ROP_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    rop->RASTEROPERATIONINDICES =
        DPU_MAKE_CONST_COLOR(config->redIndex, config->greenIndex, config->blueIndex, config->alphaIndex);
    rop->CONTROL = (rop->CONTROL & DPU_ROP_CONTROL_Mode_MASK) | config->controlFlags;
}

/*!
 * brief Enable or disable the ROp unit.
 *
 * If disabled, only the primary input is output.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Rop unit here.
 * param enable Pass true to enable, false to disable.
 */
void DPU_EnableRop(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, bool enable)
{
    DPU_ROP_Type *rop = (DPU_ROP_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    if (enable)
    {
        rop->CONTROL |= DPU_ROP_CONTROL_Mode_MASK;
    }
    else
    {
        rop->CONTROL &= ~DPU_ROP_CONTROL_Mode_MASK;
    }
}

void DPU_FetchUnitGetDefaultConfig(dpu_fetch_unit_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->srcReg      = 0U;
    config->frameHeight = 320U;
    config->frameWidth  = 480U;
}

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
void DPU_InitFetchUnit(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_fetch_unit_config_t *config)
{
    assert(NULL != config);
    assert(0U != ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrIsFetch)));

    uint32_t reg;
    uint32_t offset;
    uint32_t type;
    uint32_t dimensionOffset;
    uint32_t controlOffset;
    uint32_t resamplingOffset;

    offset = DPU_GET_UNIT_OFFSET(unit);
    type   = DPU_GET_UNIT_TYPE(unit);

    switch (type)
    {
        case kDPU_FetchDecode:
            dimensionOffset  = DPU_FETCHDECODE_FRAMEDIMENSIONS_OFFSET;
            controlOffset    = DPU_FETCHDECODE_CONTROL_OFFSET;
            resamplingOffset = DPU_FETCHDECODE_FRAMERESAMPLING_OFFSET;
            break;

        case kDPU_FetchEco:
            dimensionOffset  = DPU_FETCHECO_FRAMEDIMENSIONS_OFFSET;
            controlOffset    = DPU_FETCHECO_CONTROL_OFFSET;
            resamplingOffset = DPU_FETCHECO_FRAMERESAMPLING_OFFSET;
            break;

        case kDPU_FetchRot:
            dimensionOffset  = DPU_FETCHROT_FRAMEDIMENSIONS_OFFSET;
            controlOffset    = DPU_FETCHROT_CONTROL_OFFSET;
            resamplingOffset = DPU_FETCHROT_FRAMERESAMPLING_OFFSET;
            break;

        case KDPU_FetchYuv:
            dimensionOffset  = DPU_FETCHYUV_FRAMEDIMENSIONS_OFFSET;
            controlOffset    = DPU_FETCHYUV_CONTROL_OFFSET;
            resamplingOffset = DPU_FETCHYUV_FRAMERESAMPLING_OFFSET;
            break;

        default:
            dimensionOffset  = DPU_FETCHLAYER_FRAMEDIMENSIONS_OFFSET;
            controlOffset    = DPU_FETCHLAYER_CONTROL_OFFSET;
            resamplingOffset = DPU_FETCHLAYER_FRAMERESAMPLING_OFFSET;
            break;
    }

    /*
     * Set <unit>_StaticControl
     * If the fetch unit supports sublayer, set the ShdLdReqSticky.
     */
    if (0U != ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrSubLayer)))
    {
        DPU_REG(base, offset + DPU_STATIC_CONTROL_OFFSET) =
            DPU_UNIT_SHDEN_MASK | DPU_FETCH_STATICCONTROL_SHDLDREQSTICKY_MASK;
    }
    else
    {
        DPU_REG(base, offset + DPU_STATIC_CONTROL_OFFSET) = DPU_UNIT_SHDEN_MASK;
    }

    /* Set input source. */
    if (0U != ((uint32_t)unit & DPU_MAKE_UNIT_ATTR(kDPU_UnitAttrHasSrc)))
    {
        DPU_SetUnitSrc(base, unit, config->srcReg);
    }

    if ((uint32_t)kDPU_FetchDecode == type)
    {
        /* Disable ring buffer. */
        ((DPU_FETCHDECODER_Type *)((uint32_t)base + offset))->RINGBUFSTARTADDR0 = 0U;
        ((DPU_FETCHDECODER_Type *)((uint32_t)base + offset))->RINGBUFWRAPADDR0  = 0U;
    }
    if ((uint32_t)KDPU_FetchYuv == type)
    {
        /* Disable ring buffer. */
        ((DPU_FETCHYUV_Type *)((uint32_t)base + offset))->RINGBUFSTARTADDR0 = 0U;
        ((DPU_FETCHYUV_Type *)((uint32_t)base + offset))->RINGBUFWRAPADDR0  = 0U;
    }

    if ((uint32_t)kDPU_FetchRot == type)
    {
        /* AXI burst management. */
        DPU_REG(base, offset + DPU_FETCHUNIT_BURSTBUFFERMANAGEMENT_OFFSET) =
            DPU_BURSTBUFFERMANAGEMENT_SETNUMBUFFERS(64) |
            DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(DPU_FETCH_UNIT_BURST_LENGTH);
    }
    else
    {
        /* AXI burst management. */
        DPU_REG(base, offset + DPU_FETCHUNIT_BURSTBUFFERMANAGEMENT_OFFSET) =
            DPU_BURSTBUFFERMANAGEMENT_SETNUMBUFFERS(16) |
            DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(DPU_FETCH_UNIT_BURST_LENGTH);
    }

    /* Set <unit>_FrameDimensions. */
    DPU_REG(base, offset + dimensionOffset) = DPU_MAKE_DIMENSION(config->frameHeight - 1UL, config->frameWidth - 1UL);

    /* Set <unit>_Control. */
    reg = DPU_REG(base, offset + controlOffset) &
          ~(DPU_FETCH_CONTROL_YUV422UPSAMPLINGMODE_MASK | DPU_FETCH_CONTROL_RASTERMODE_MASK |
            DPU_FETCH_CONTROL_INPUTSELECT_MASK | DPU_FETCH_CONTROL_RAWPIXEL_MASK);

    reg |= DPU_FETCH_CONTROL_INPUTSELECT(kDPU_FetchCtrlInputSelInactive) |
           DPU_FETCH_CONTROL_RASTERMODE(kDPU_FetchCtrlRasterNormal);

    DPU_REG(base, offset + controlOffset) = reg;

    /* Set resampling. */
    DPU_REG(base, offset + resamplingOffset) = DPU_MAKE_FETCH_RESAMPLING(0, 4, 4, 0, 0);
}

/*!
 * brief Get default configuration structure for fetch unit source buffer.
 *
 * The default value is:
 * code
    config->baseAddr = 0U;
    config->strideBytes = 0x500U;
    config->bitsPerPixel = 32U;
    config->pixelFormat = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth = 0U;
    config->constColor = DPU_MAKE_CONST_COLOR(0, 0, 0, 0);
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_SrcBufferGetDefaultConfig(dpu_src_buffer_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->baseAddr     = 0U;
    config->strideBytes  = 0x500U;
    config->bitsPerPixel = 32U;
    config->pixelFormat  = kDPU_PixelFormatARGB8888;
    config->bufferHeight = 0U;
    config->bufferWidth  = 0U;
    config->constColor   = DPU_MAKE_CONST_COLOR(0, 0, 0, 0);
}

/*!
 * brief Set the fetch unit sublayer source buffer.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param config Pointer to the configuration structure.
 * retval kStatus_Success Initialization success.
 * retval kStatus_InvalidArgument Wrong argument.
 */
status_t DPU_SetFetchUnitSrcBufferConfig(DISPLAY_SEERIS_Type *base,
                                         dpu_unit_t unit,
                                         uint8_t sublayer,
                                         const dpu_src_buffer_config_t *config)
{
    assert(NULL != config);

    DPU_SUBLAYER_CONTROL_Type *control;

    /* Buffer should be aligned. */
    if (!(DPU_CheckBufferAlignment(config->bitsPerPixel, config->baseAddr, config->strideBytes)))
    {
        return kStatus_InvalidArgument;
    }

    control = DPU_GetSubLayer(base, unit, sublayer);

    control->BASEADDRESS0            = config->baseAddr;
    control->SOURCEBUFFERATTRIBUTES0 = DPU_MAKE_SOURCEBUFFERATTRIBUTES(config->bitsPerPixel, config->strideBytes);
    control->SOURCEBUFFERDIMENSION0  = DPU_MAKE_DIMENSION(config->bufferHeight - 1UL, config->bufferWidth - 1UL);
    control->COLORCOMPONENTBITS0     = s_dpuColorComponentFormats[config->pixelFormat][0];
    control->COLORCOMPONENTSHIFT0    = s_dpuColorComponentFormats[config->pixelFormat][1];
    control->CONSTANTCOLOR0          = config->constColor;

    return kStatus_Success;
}

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
    DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, uint16_t offsetX, uint16_t offsetY)
{
    DPU_SUBLAYER_CONTROL_Type *control = DPU_GetSubLayer(base, unit, sublayer);

    control->LAYEROFFSET0 = DPU_MAKE_POSITION(offsetY, offsetX);
}

/*!
 * brief Enable or disable fetch unit sublayer source buffer.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param enable True to enable, false to disable.
 */
void DPU_EnableFetchUnitSrcBuffer(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, bool enable)
{
    DPU_SUBLAYER_CONTROL_Type *control = DPU_GetSubLayer(base, unit, sublayer);

    if (enable)
    {
        control->LAYERPROPERTY0 |= DPU_LAYERPROPERTY_SOURCEBUFFERENABLE_MASK;
    }
    else
    {
        control->LAYERPROPERTY0 &= ~DPU_LAYERPROPERTY_SOURCEBUFFERENABLE_MASK;
    }
}

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
                               uint8_t sublayer)
{
    uint32_t reg;
    uint32_t offset;
    uint32_t type;
    uint32_t controlOffset;

    offset = DPU_GET_UNIT_OFFSET(unit);
    type   = DPU_GET_UNIT_TYPE(unit);

    switch (type)
    {
        case kDPU_FetchDecode:
            controlOffset = DPU_FETCHDECODE_CONTROL_OFFSET;
            break;

        case kDPU_FetchEco:
            controlOffset = DPU_FETCHECO_CONTROL_OFFSET;
            break;

        case kDPU_FetchRot:
            controlOffset = DPU_FETCHROT_CONTROL_OFFSET;
            break;

        default:
            controlOffset = DPU_FETCHLAYER_CONTROL_OFFSET;
            break;
    }

    /* Set <unit>_Control. */
    reg = DPU_REG(base, offset + controlOffset) & ~(DPU_FETCH_CONTROL_CLIPCOLOR_MASK);

    if (kDPU_ClipColorNull != clipColorMode)
    {
        reg |= DPU_FETCH_CONTROL_CLIPCOLOR_MASK;
    }
    DPU_REG(base, offset + controlOffset) = reg;
}

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
void DPU_InitExtDst(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t srcReg)
{
    DPU_EXTDST_Type *extDst;

    assert((uint32_t)kDPU_ExtDst == DPU_GET_UNIT_TYPE(unit));

    extDst = (DPU_EXTDST_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Set KICK_MODE to external. */
    extDst->STATICCONTROL = DPU_EXTDST_STATICCONTROL_KICKMODE_MASK | DPU_UNIT_SHDEN_MASK;

    /* Set input source selection (the register dynamic). */
    DPU_SetUnitSrc(base, unit, srcReg);
}

/*!
 * brief Set the Store unit Destination buffer base address.
 *
 * This function is run time used for better performance.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be Store unit here.
 * param baseAddr Base address of the Destination buffer to set.
 */
void DPU_SetStoreDstBufferAddr(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint32_t baseAddr)
{
    DPU_STORE_Type *store = (DPU_STORE_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    store->BASEADDRESS0 = baseAddr;
}

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
void DPU_DisableInterrupts(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask)
{
    assert(group < DPU_INT_GROUP_NUM);

    ((DPU_COMCTRL_Type *)((uint32_t)base + DPU_COMCTRL_OFFSET))->IRQ_INTERRUPTENABLE[group] &= ~mask;
}

/*!
 * brief Get the DPU interrupts pending status.
 *
 * The pending status are returned as mask.
 *
 * param base DPU peripheral base address.
 * param group Interrupt group index.
 * return The interrupts pending status mask value, see ref _dpu_interrupt.
 */
uint32_t DPU_GetInterruptsPendingFlags(DISPLAY_SEERIS_Type *base, uint8_t group)
{
    assert(group < DPU_INT_GROUP_NUM);

    return ((DPU_COMCTRL_Type *)((uint32_t)base + DPU_COMCTRL_OFFSET))->IRQ_INTERRUPTSTATUS[group];
}

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
void DPU_ClearInterruptsPendingFlags(DISPLAY_SEERIS_Type *base, uint8_t group, uint32_t mask)
{
    assert(group < DPU_INT_GROUP_NUM);

    ((DPU_COMCTRL_Type *)((uint32_t)base + DPU_COMCTRL_OFFSET))->IRQ_INTERRUPTCLEAR[group] = mask;
}

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
void DPU_DisplayTimingGetDefaultConfig(dpu_display_timing_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->flags  = (uint16_t)kDPU_DisplayDataEnableActiveHigh;
    config->width  = 320U;
    config->hsw    = 32U;
    config->hfp    = 8U;
    config->hbp    = 40U;
    config->height = 240U;
    config->vsw    = 4U;
    config->vfp    = 13U;
    config->vbp    = 6U;
}

/*!
 * brief Initialize the display timing.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 * param config Pointer to the configuration structure.
 */
void DPU_InitDisplayTiming(DISPLAY_SEERIS_Type *base, uint8_t displayIndex, const dpu_display_timing_config_t *config)
{
    assert(displayIndex < DPU_DISPLAY_COUNT);

    uint32_t reg;
    uint16_t vtotal;
    DPU_FRAMEGEN_Type *display  = (DPU_FRAMEGEN_Type *)(((uint32_t)base) + s_displayOffsetArray[displayIndex]);
    DPU_DISENGCONF_Type *diseng = (DPU_DISENGCONF_Type *)(((uint32_t)base) + s_ditherOffsettArray[displayIndex]);

    display->FGSTCTRL |= DPU_UNIT_SHDEN_MASK;

    /* Set signal polarity. */
    reg = config->flags & ((uint32_t)kDPU_DisplayDataEnableActiveHigh | (uint32_t)kDPU_DisplayHsyncActiveHigh |
                           (uint32_t)kDPU_DisplayVsyncActiveHigh);
    diseng->DITHER.POLARITYCTRL = reg;

    /* Set timing. */
    vtotal = config->height + config->vfp + config->vbp + config->vsw - 1U;
    display->HTCFG1 =
        DPU_FRAMEGEN_HTCFG1_Htotal((uint32_t)config->width + config->hfp + config->hbp + config->hsw - 1UL) |
        DPU_FRAMEGEN_HTCFG1_Hact(config->width);

    display->HTCFG2 = DPU_FRAMEGEN_HTCFG2_Hsync(config->hsw - 1UL) |
                      DPU_FRAMEGEN_HTCFG2_Hsbp((uint32_t)config->hbp + config->hsw - 1UL) |
                      DPU_FRAMEGEN_HTCFG2_HsEn_MASK;

    display->VTCFG1 = DPU_FRAMEGEN_VTCFG1_Vtotal(vtotal) | DPU_FRAMEGEN_VTCFG1_Vact(config->height);

    display->VTCFG2 = DPU_FRAMEGEN_VTCFG2_Vsync(config->vsw - 1UL) |
                      DPU_FRAMEGEN_VTCFG2_Vsbp((uint32_t)config->vbp + config->vsw - 1UL) |
#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
                      DPU_FRAMEGEN_VTCFG2_VsEn_MASK | DPU_FRAMEGEN_VTCFG2_VsAlign_MASK;
#else
                      DPU_FRAMEGEN_VTCFG2_VsEn_MASK;
#endif

    /* Kick signal set to start of last vertical blanking line. */
    display->PKICKCONFIG = DPU_FRAMEGEN_PKICKCONFIG_PKickRow(vtotal + 1UL) |
                           DPU_FRAMEGEN_PKICKCONFIG_PKickCol((uint32_t)config->width + config->hfp + config->hbp + config->hsw) |
                           DPU_FRAMEGEN_PKICKCONFIG_PKickEn_MASK;
    display->SKICKCONFIG = DPU_FRAMEGEN_SKICKCONFIG_SKickRow(vtotal + 1UL) |
                           DPU_FRAMEGEN_SKICKCONFIG_SKickCol((uint32_t)config->width + config->hfp + config->hbp + config->hsw) |
                           DPU_FRAMEGEN_SKICKCONFIG_SKickEn_MASK;
}

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
void DPU_DisplayGetDefaultConfig(dpu_display_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enablePrimAlpha        = false;
    config->enableSecAlpha         = false;
    config->displayMode            = kDPU_DisplayTest;
    config->enablePrimAlphaInPanic = false;
    config->enableSecAlphaInPanic  = false;
    config->displayModeInPanic     = kDPU_DisplayTest;
    config->constRed               = 0x3FFU;
    config->constGreen             = 0x3FFU;
    config->constBlue              = 0x3FFU;
    config->constAlpha             = 1U;
    config->primAreaStartX         = 1U;
    config->primAreaStartY         = 1U;
    config->secAreaStartX          = 1U;
    config->secAreaStartY          = 1U;
}

/*!
 * brief Set the display mode.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 * param config Pointer to the configuration structure.
 */
void DPU_SetDisplayConfig(DISPLAY_SEERIS_Type *base, uint8_t displayIndex, const dpu_display_config_t *config)
{
    assert(displayIndex < DPU_DISPLAY_COUNT);

    uint32_t reg;
    DPU_FRAMEGEN_Type *display = (DPU_FRAMEGEN_Type *)(((uint32_t)base) + s_displayOffsetArray[displayIndex]);

    /* Area configure. */
    display->PACFG =
        DPU_FRAMEGEN_PACFG_Pstartx(config->primAreaStartX) | DPU_FRAMEGEN_PACFG_Pstarty(config->primAreaStartY);
    display->SACFG =
        DPU_FRAMEGEN_SACFG_Sstartx(config->secAreaStartX) | DPU_FRAMEGEN_SACFG_Sstarty(config->secAreaStartY);

    /* Input control. */
    reg = DPU_FRAMEGEN_FGINCTRL_FgDm(config->displayMode);

    if (config->enableSecAlpha)
    {
        reg |= DPU_FRAMEGEN_FGINCTRL_EnSecAlpha_MASK;
    }

    if (config->enablePrimAlpha)
    {
        reg |= DPU_FRAMEGEN_FGINCTRL_EnPrimAlpha_MASK;
    }

    display->FGINCTRL = reg;

    reg = DPU_FRAMEGEN_FGINCTRL_FgDm(config->displayModeInPanic);

    if (config->enableSecAlphaInPanic)
    {
        reg |= DPU_FRAMEGEN_FGINCTRL_EnSecAlpha_MASK;
    }

    if (config->enablePrimAlphaInPanic)
    {
        reg |= DPU_FRAMEGEN_FGINCTRL_EnPrimAlpha_MASK;
    }
    display->FGINCTRLPANIC = reg;

    /* Configure constant color. */
    display->FGCCR = DPU_FRAMEGEN_FGCCR_CcBlue(config->constBlue) | DPU_FRAMEGEN_FGCCR_CcGreen(config->constGreen) |
                     DPU_FRAMEGEN_FGCCR_CcRed(config->constRed) | DPU_FRAMEGEN_FGCCR_CcAlpha(config->constAlpha);
}

/*!
 * brief Start the display.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 */
void DPU_StartDisplay(DISPLAY_SEERIS_Type *base, uint8_t displayIndex)
{
    assert(displayIndex < DPU_DISPLAY_COUNT);

    DPU_FRAMEGEN_Type *display = (DPU_FRAMEGEN_Type *)(((uint32_t)base) + s_displayOffsetArray[displayIndex]);

    display->FGENABLE = DPU_FRAMEGEN_FGENABLE_FgEn_MASK;
}

/*!
 * brief Stop the display.
 *
 * This function stops the display and wait the sequence complete.
 *
 * param base DPU peripheral base address.
 * param displayIndex Index of the display.
 */
void DPU_StopDisplay(DISPLAY_SEERIS_Type *base, uint8_t displayIndex)
{
    assert(displayIndex < DPU_DISPLAY_COUNT);

    DPU_DISPLAY_Type *display = (DPU_DISPLAY_Type *)(((uint32_t)base) + s_displayOffsetArray[displayIndex]);

    display->FRAMEGEN.FGENABLE = 0U;
}

/*!
 * brief Trigger the display stream shadow load token.
 *
 * Trigger the display stream shadow load token, then the shadow register will
 * be loaded at the begining of next frame.
 *
 * param base DPU peripheral base address.
 * param displayIndex Display index.
 */
void DPU_TriggerDisplayShadowLoad(DISPLAY_SEERIS_Type *base, uint8_t displayIndex)
{
    assert(displayIndex < DPU_DISPLAY_COUNT);

    DPU_FRAMEGEN_Type *display = (DPU_FRAMEGEN_Type *)(((uint32_t)base) + s_displayOffsetArray[displayIndex]);

    display->FGSLR = DPU_FRAMEGEN_FGSLR_ShdTokGen_MASK;
}

/*!
 * brief Set the fetch unit sublayer source buffer base address.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be fetch unit here.
 * param sublayer Sublayer index, should be 0 to 7.
 * param baseAddr Source buffer base address.
 */
void DPU_SetFetchUnitSrcBufferAddr(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, uint8_t sublayer, uint32_t baseAddr)
{
    DPU_SUBLAYER_CONTROL_Type *control = DPU_GetSubLayer(base, unit, sublayer);

    control->BASEADDRESS0 = baseAddr;
}

/*!
 * brief Initialize the Domainblend.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be DomainBlend unit here.
 */
void DPU_InitDomainBlend(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    DPU_DOMAINBLEND_Type *domainBlend;

    assert((uint32_t)kDPU_DomainBlend == DPU_GET_UNIT_TYPE(unit));

    domainBlend = (DPU_DOMAINBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /* Shadow token generate mode: SW. Shadow load mode: SW. Shadow enabled in static-control*/
    domainBlend->STATICCONTROL = DPU_DOMAINBLEND_STATICCONTROL_ShdEn_MASK |
                                 DPU_DOMAINBLEND_STATICCONTROL_ShdTokSel(DPU_DOMAINBLEND_SW) |
                                 DPU_DOMAINBLEND_STATICCONTROL_ShdLdSel(DPU_DOMAINBLEND_SW);
    domainBlend->BLENDCONTROL = 0x10U;
}

/*!
 * brief Trigger the display stream domainblend shadow load token.
 *
 * Trigger the display stream shadow load token, then the shadow register will
 * be loaded at the begining of next frame.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be DomainBlend unit here.
 */
void DPU_TriggerDisplayDbShadowLoad(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    DPU_DOMAINBLEND_Type *domainBlend;

    assert((uint32_t)kDPU_DomainBlend == DPU_GET_UNIT_TYPE(unit));

    domainBlend = (DPU_DOMAINBLEND_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    domainBlend->CONTROLTRIGGER = DPU_DOMAINBLEND_CONTROLTRIGGER_ShdTokGen_MASK;
}

/*!
 * brief Initialize the VScaler or HScaler unit.
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be HScaler or VScaler unit here.
 */
void DPU_InitScaler(DISPLAY_SEERIS_Type *base, dpu_unit_t unit)
{
    assert(((uint32_t)kDPU_VScaler == DPU_GET_UNIT_TYPE(unit)) ||
           (((uint32_t)kDPU_HScaler == DPU_GET_UNIT_TYPE(unit))));

    (void)DPU_EnableShadowLoad(base, unit, true);
}

/*!
 * brief Get default configuration structure for VScaler and HScaler.
 *
 * The default value is:
   code
    config->srcReg = 0U;
    config->inputSize = 0U;
    config->outputSize = 0U;
   endcode
 *
 * param config Pointer to the configuration structure.
 */
void DPU_ScalerGetDefaultConfig(dpu_scaler_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->srcReg     = 0U;
    config->inputSize  = 0U;
    config->outputSize = 0U;
}

/*!
 * brief Set the VScaler or HScaler units configuration.
 *
 * The valid input source could be:
 *  - ref kDPU_UnitSrcNone
 *  - ref kDPU_UnitSrcFetchYuv0-3
 *  - ref kDPU_UnitSrcMatrix4
 *  - ref kDPU_UnitSrcVScaler4
 *  - ref kDPU_UnitSrcHScaler4
 *  - ref kDPU_UnitSrcVScaler9
 *  - ref kDPU_UnitSrcHScaler9
 *  - ref kDPU_UnitSrcFilter9
 *  - ref kDPU_UnitSrcMatrix9
 *
 * param base DPU peripheral base address.
 * param unit DPU unit, see ref dpu_unit_t, must be HScaler or VScaler unit here.
 * param config Pointer to the configuration structure.
 */
void DPU_SetScalerConfig(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_scaler_config_t *config)
{
    assert(NULL != config);

    float scaleFact;
    uint32_t control;
    uint32_t setup1;
    uint32_t offset = ((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit);

    control = DPU_SCALER_CONTROL_OUTPUTSIZE(config->outputSize - 1UL) | DPU_SCALER_CONTROL_FILTERMODE_MASK |
              DPU_SCALER_CONTROL_MODE_MASK;

    if (config->inputSize > config->outputSize)
    {
        scaleFact = (float)config->outputSize / (float)config->inputSize;
    }
    else
    {
        /* Output size is larger, use up-scaling mode. */
        control |= DPU_SCALER_CONTROL_SCALEMODE_MASK;
        scaleFact = (float)config->inputSize / (float)config->outputSize;
    }

    /*
     * The scale fact is a float value (0.0 to 1.0], it should be converted to
     * fixed 1.19 value and set to register SETUP1.
     */
    setup1 = DPU_ConvertFloat(scaleFact, 1, 19);

    if (0U == setup1)
    {
        setup1 = 1U;
    }
    else if (setup1 > 0x80000U)
    {
        setup1 = 0x80000U;
    }
    else
    {
        /* MISRA 15.7 */
    }

    ((DPU_VSCALER_Type *)offset)->SETUP1 = setup1;

    if ((uint32_t)kDPU_VScaler == DPU_GET_UNIT_TYPE(unit))
    {
        ((DPU_VSCALER_Type *)offset)->CONTROL = control;
    }
    else
    {
        ((DPU_HSCALER_Type *)offset)->CONTROL = control;
    }

    DPU_SetUnitSrc(base, unit, config->srcReg);
}

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
void DPU_FetcUnitGetDefaultWarpConfig(dpu_warp_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->srcReg                = 0U;
    config->frameHeight           = 320U;
    config->frameWidth            = 480U;
    config->warpBitsPerPixel      = 0U;
    config->enableSymmetricOffset = false;
    config->coordMode             = kDPU_WarpCoordinateModePNT;
    config->arbStartX             = 0U;
    config->arbStartY             = 0U;
    config->arbDeltaYY            = 0U;
    config->arbDeltaYX            = 0U;
    config->arbDeltaXY            = 0U;
    config->arbDeltaXX            = 0U;
}

/*!
 * brief Initialize the Warp function for FetchRot unit.
 *
 * This function initializes the FetchWarp unit for the arbitrary warping.
 *
 * The valid source of fetch Rot unit could be:
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
status_t DPU_InitFetchUnitWarp(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_warp_config_t *config)
{
    assert(NULL != config);

    uint32_t reg;
    DPU_FETCHROT_Type *fetchWarp;

    if ((uint32_t)kDPU_FetchRot != DPU_GET_UNIT_TYPE(unit))
    {
        return kStatus_InvalidArgument;
    }

    fetchWarp = (DPU_FETCHROT_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    /*
     * Set <unit>_StaticControl
     * If the fetch unit supports sublayer, set the ShdLdReqSticky.
     */
    fetchWarp->STATICCONTROL = DPU_UNIT_SHDEN_MASK | DPU_FETCH_STATICCONTROL_SHDLDREQSTICKY_MASK;

    /* Set input source. */
    DPU_SetUnitSrc(base, unit, config->srcReg);

    /* Set <unit>_FrameDimensions. */
    fetchWarp->FRAMEDIMENSIONS = DPU_MAKE_DIMENSION(config->frameHeight - 1UL, config->frameWidth - 1UL);

    /* Set resampling. */
    fetchWarp->FRAMERESAMPLING = DPU_MAKE_FETCH_RESAMPLING(0, 4, 4, 0, 0);

    /* Setup warping. */
    fetchWarp->WARPCONTROL = DPU_FETCHWARP_WARPCONTROL_WarpBitsPerPixel(config->warpBitsPerPixel) |
                             DPU_FETCHWARP_WARPCONTROL_WarpCoordinateMode(config->coordMode) |
                             DPU_FETCHWARP_WARPCONTROL_WarpSymmetricOffset(config->enableSymmetricOffset ? 1UL : 0UL);

    fetchWarp->ARBSTARTX = config->arbStartX;
    fetchWarp->ARBSTARTY = config->arbStartY;
    fetchWarp->ARBDELTA =
        DPU_FETCHWARP_ARBDELTA_ArbDeltaXX(config->arbDeltaXX) | DPU_FETCHWARP_ARBDELTA_ArbDeltaXY(config->arbDeltaXY) |
        DPU_FETCHWARP_ARBDELTA_ArbDeltaYX(config->arbDeltaYX) | DPU_FETCHWARP_ARBDELTA_ArbDeltaYY(config->arbDeltaYY);

    fetchWarp->BURSTBUFFERMANAGEMENT = DPU_BURSTBUFFERMANAGEMENT_SETNUMBUFFERS(64) |
                                       DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(DPU_FETCH_UNIT_BURST_LENGTH);

    /* Set <unit>_Control. */
    reg = fetchWarp->CONTROL & ~(DPU_FETCH_CONTROL_YUV422UPSAMPLINGMODE_MASK | DPU_FETCH_CONTROL_RASTERMODE_MASK |
                                 DPU_FETCH_CONTROL_INPUTSELECT_MASK | DPU_FETCH_CONTROL_RAWPIXEL_MASK);
    fetchWarp->CONTROL = reg | DPU_FETCH_CONTROL_INPUTSELECT(kDPU_FetchCtrlInputSelCoordinate) |
                         DPU_FETCH_CONTROL_RASTERMODE(kDPU_FetchCtrlRasterArbitrary) |
                         DPU_FETCH_CONTROL_FILTERMODE(kDPU_FetchCtrlFilterBilinear);

    return kStatus_Success;
}

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
void DPU_CorrdinatesGetDefaultConfig(dpu_coordinates_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->bitsPerPixel = 0U;
    config->strideBytes  = 0x500U;
    config->baseAddr     = 0U;
    config->frameHeight  = 320U;
    config->frameWidth   = 480U;
}

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
status_t DPU_InitWarpCoordinates(DISPLAY_SEERIS_Type *base, dpu_unit_t unit, const dpu_coordinates_config_t *config)
{
    assert(NULL != config);

    DPU_FETCHECO_Type *fetchEco;
    uint32_t dimension;
    uint32_t reg;

    if (!DPU_CheckBufferAlignment(config->bitsPerPixel, config->baseAddr, config->strideBytes))
    {
        return kStatus_InvalidArgument;
    }

    fetchEco = (DPU_FETCHECO_Type *)(((uint32_t)base) + DPU_GET_UNIT_OFFSET(unit));

    dimension = DPU_MAKE_DIMENSION(config->frameHeight - 1UL, config->frameWidth - 1UL);

    fetchEco->STATICCONTROL = DPU_UNIT_SHDEN_MASK;

    fetchEco->LAYER[0].BASEADDRESS0 = config->baseAddr;
    fetchEco->LAYER[0].SOURCEBUFFERATTRIBUTES0 =
        DPU_MAKE_SOURCEBUFFERATTRIBUTES(config->bitsPerPixel, config->strideBytes);
    fetchEco->LAYER[0].SOURCEBUFFERDIMENSION0 = dimension;
    fetchEco->LAYER[0].COLORCOMPONENTBITS0    = 0U;
    fetchEco->LAYER[0].COLORCOMPONENTSHIFT0   = 0U;
    fetchEco->LAYER[0].LAYEROFFSET0           = 0U;
    fetchEco->LAYER[0].LAYERPROPERTY0 |= DPU_LAYERPROPERTY_SOURCEBUFFERENABLE_MASK;
    fetchEco->FRAMEDIMENSIONS = dimension;

    fetchEco->BURSTBUFFERMANAGEMENT = DPU_BURSTBUFFERMANAGEMENT_SETNUMBUFFERS(16) |
                                      DPU_BURSTBUFFERMANAGEMENT_SETBURSTLENGTH(DPU_FETCH_UNIT_BURST_LENGTH);

    /* Enable Control.RawPixel. */
    reg = fetchEco->CONTROL & ~(DPU_FETCH_CONTROL_YUV422UPSAMPLINGMODE_MASK | DPU_FETCH_CONTROL_RASTERMODE_MASK);

    fetchEco->CONTROL =
        reg | DPU_FETCH_CONTROL_RASTERMODE(kDPU_FetchCtrlRasterNormal) | DPU_FETCH_CONTROL_RAWPIXEL_MASK;

    return kStatus_Success;
}

#if defined(FSL_FEATURE_DISPLAY_SEERIS_MDR7) && FSL_FEATURE_DISPLAY_SEERIS_MDR7
/*!
 * @brief Start the localdimming.
 *
 * This function starts the localdimming.
 *
 * @param base DPU localdimming peripheral base address.
 *
 */
void DPU_Localdimming_Start(DISPLAY_SEERIS_LD_Type *base)
{
    base->LDUP000 = DISPLAY_SEERIS_LD_LDUP000_upd_MASK;
}

/*!
 * @brief Initializes the localdimming setting.
 *
 * This function configs the localdimming setting.
 *
 * @param ld DPU localdimming peripheral base address.
 *
 */
void DPU_Init_Localdimming_Env(DISPLAY_SEERIS_LD_Type *ld)
{
    DPU_LdWrite(ld, 0x0008,  0x1U);
    DPU_LdWrite(ld, 0x000C,  0x3U);
    DPU_LdWrite(ld, 0x0020,  0x1U);
    DPU_LdWrite(ld, 0x0024,  0x02D702D6U);
    DPU_LdWrite(ld, 0x001C,  0x302EU);
    DPU_LdWrite(ld, 0x1000,  0x0F040101U);
    DPU_LdWrite(ld, 0x1004,  0x00000000U);
    DPU_LdWrite(ld, 0x1020,  0x00000001U);
    DPU_LdWrite(ld, 0x1024,  0x00000000U);
    DPU_LdWrite(ld, 0x1028,  0x00000000U);
    DPU_LdWrite(ld, 0x102C,  0x00000003U);
    DPU_LdWrite(ld, 0x1030,  0x00000000U);
    DPU_LdWrite(ld, 0x1034,  0x00000000U);
    DPU_LdWrite(ld, 0x1038,  0x00000000U);
    DPU_LdWrite(ld, 0x1040,  0x00000000U);
    DPU_LdWrite(ld, 0x1044,  0x0FFF0000U);
    DPU_LdWrite(ld, 0x1048,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x104C,  0x00000000U);
    DPU_LdWrite(ld, 0x1050,  0x00000000U);
    DPU_LdWrite(ld, 0x1054,  0x00000000U);
    DPU_LdWrite(ld, 0x1058,  0x00000000U);
    DPU_LdWrite(ld, 0x1060,  0x00000000U);
    DPU_LdWrite(ld, 0x1064,  0x02D00780U);
    DPU_LdWrite(ld, 0x1068,  0x00180008U);
    DPU_LdWrite(ld, 0x106C,  0x00C00040U);
    DPU_LdWrite(ld, 0x1070,  0x00000033U);
    DPU_LdWrite(ld, 0x1074,  0x00000001U);
    DPU_LdWrite(ld, 0x107C,  0x00080000U);
    DPU_LdWrite(ld, 0x1218,  0x00052060U);
    DPU_LdWrite(ld, 0x1220,  0x000320B0U);
    DPU_LdWrite(ld, 0x1224,  0x000000C0U);
    DPU_LdWrite(ld, 0x1228,  0x00000000U);
    DPU_LdWrite(ld, 0x122C,  0x00000101U);
    DPU_LdWrite(ld, 0x1230,  0x08000000U);
    DPU_LdWrite(ld, 0x1234,  0x00000000U);
    DPU_LdWrite(ld, 0x1238,  0x00CD8020U);
    DPU_LdWrite(ld, 0x1250,  0x00010002U);
    DPU_LdWrite(ld, 0x1254,  0x00060008U);
    DPU_LdWrite(ld, 0x1258,  0x0002000BU);
    DPU_LdWrite(ld, 0x125C,  0x001B0025U);
    DPU_LdWrite(ld, 0x1260,  0x0006001BU);
    DPU_LdWrite(ld, 0x1264,  0x0045005EU);
    DPU_LdWrite(ld, 0x1268,  0x00080025U);
    DPU_LdWrite(ld, 0x126C,  0x005E0100U);
    DPU_LdWrite(ld, 0x1298,  0x00000000U);
    DPU_LdWrite(ld, 0x129C,  0x18800031U);
    DPU_LdWrite(ld, 0x12A0,  0x2C180730U);
    DPU_LdWrite(ld, 0x12A4,  0x00000100U);
    DPU_LdWrite(ld, 0x12A8,  0x00000000U);
    DPU_LdWrite(ld, 0x12AC,  0x0FFF0000U);
    DPU_LdWrite(ld, 0x12B0,  0x00000000U);
    DPU_LdWrite(ld, 0x12B4,  0x00000000U);
    DPU_LdWrite(ld, 0x12B8,  0x00000000U);
    DPU_LdWrite(ld, 0x12BC,  0x00000000U);
    DPU_LdWrite(ld, 0x12C0,  0x00000000U);
    DPU_LdWrite(ld, 0x12C4,  0x00000000U);
    DPU_LdWrite(ld, 0x12C8,  0x00000000U);
    DPU_LdWrite(ld, 0x12CC,  0x00000000U);
    DPU_LdWrite(ld, 0x1300,  0x00000050U); // SET THE START COORDINATE OF HORIZONTAL POSITION 1,2
    DPU_LdWrite(ld, 0x1304,  0x00A000F0U);
    DPU_LdWrite(ld, 0x1308,  0x01400190U);
    DPU_LdWrite(ld, 0x130C,  0x01E00230U);
    DPU_LdWrite(ld, 0x1310,  0x028002D0U);
    DPU_LdWrite(ld, 0x1314,  0x03200370U);
    DPU_LdWrite(ld, 0x1318,  0x03C00410U);
    DPU_LdWrite(ld, 0x131C,  0x046004B0U);
    DPU_LdWrite(ld, 0x1320,  0x05000550U);
    DPU_LdWrite(ld, 0x1324,  0x05A005F0U);
    DPU_LdWrite(ld, 0x1328,  0x06400690U);
    DPU_LdWrite(ld, 0x132C,  0x06E00730U);
    DPU_LdWrite(ld, 0x1330,  0x07800780U);
    DPU_LdWrite(ld, 0x1334,  0x07800780U);
    DPU_LdWrite(ld, 0x1338,  0x07800780U);
    DPU_LdWrite(ld, 0x133C,  0x07800780U);
    DPU_LdWrite(ld, 0x1340,  0x07800780U);
    DPU_LdWrite(ld, 0x1344,  0x07800780U);
    DPU_LdWrite(ld, 0x1348,  0x07800780U);
    DPU_LdWrite(ld, 0x134C,  0x07800780U);
    DPU_LdWrite(ld, 0x1350,  0x07800780U);
    DPU_LdWrite(ld, 0x1354,  0x07800780U);
    DPU_LdWrite(ld, 0x1358,  0x07800780U);
    DPU_LdWrite(ld, 0x135C,  0x07800780U);
    DPU_LdWrite(ld, 0x1360,  0x07800780U);
    DPU_LdWrite(ld, 0x1364,  0x07800780U);
    DPU_LdWrite(ld, 0x1368,  0x07800780U);
    DPU_LdWrite(ld, 0x136C,  0x07800780U);
    DPU_LdWrite(ld, 0x1370,  0x07800780U);
    DPU_LdWrite(ld, 0x1374,  0x07800780U);
    DPU_LdWrite(ld, 0x1378,  0x07800780U);
    DPU_LdWrite(ld, 0x137C,  0x07800780U);
    DPU_LdWrite(ld, 0x1380,  0x07800000U);
    DPU_LdWrite(ld, 0x13A0,  0x0000005AU); // SET THE START COORDINATE OF VERTICAL POSITION
    DPU_LdWrite(ld, 0x13A4,  0x00B4010EU);
    DPU_LdWrite(ld, 0x13A8,  0x016801C2U);
    DPU_LdWrite(ld, 0x13AC,  0x021C0276U);
    DPU_LdWrite(ld, 0x13B0,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13B4,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13B8,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13BC,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13C0,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13C4,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13C8,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13CC,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13D0,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13D4,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13D8,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13DC,  0x02D002D0U);
    DPU_LdWrite(ld, 0x13E0,  0x02D00000U);
    DPU_LdWrite(ld, 0x1400,  0x00000000U);
    DPU_LdWrite(ld, 0x1404,  0xD47A1000U);
    DPU_LdWrite(ld, 0x1408,  0x08000800U);
    DPU_LdWrite(ld, 0x140C,  0x03000000U);
    DPU_LdWrite(ld, 0x1410,  0x00000000U);
    DPU_LdWrite(ld, 0x1414,  0x00000000U);
    DPU_LdWrite(ld, 0x1420,  0x00000000U);
    DPU_LdWrite(ld, 0x1440,  0x00000080U);
    DPU_LdWrite(ld, 0x1444,  0x01000180U);
    DPU_LdWrite(ld, 0x1448,  0x02000280U);
    DPU_LdWrite(ld, 0x144C,  0x03000380U);
    DPU_LdWrite(ld, 0x1450,  0x04000480U);
    DPU_LdWrite(ld, 0x1454,  0x05000580U);
    DPU_LdWrite(ld, 0x1458,  0x06000680U);
    DPU_LdWrite(ld, 0x145C,  0x07000780U);
    DPU_LdWrite(ld, 0x1460,  0x08000880U);
    DPU_LdWrite(ld, 0x1464,  0x09000980U);
    DPU_LdWrite(ld, 0x1468,  0x0A000A80U);
    DPU_LdWrite(ld, 0x146C,  0x0B000B80U);
    DPU_LdWrite(ld, 0x1470,  0x0C000C80U);
    DPU_LdWrite(ld, 0x1474,  0x0D000D80U);
    DPU_LdWrite(ld, 0x1478,  0x0E000E80U);
    DPU_LdWrite(ld, 0x147C,  0x0F000F80U);
    DPU_LdWrite(ld, 0x1480,  0x10000000U);
    DPU_LdWrite(ld, 0x1484,  0x00000000U);
    DPU_LdWrite(ld, 0x1488,  0x00000FFFU);
    DPU_LdWrite(ld, 0x148C,  0x00000000U);
    DPU_LdWrite(ld, 0x1490,  0x00001000U);
    DPU_LdWrite(ld, 0x1644,  0x00016C17U);
    DPU_LdWrite(ld, 0x1648,  0x03F8B60BU);
    DPU_LdWrite(ld, 0x164C,  0x02D00006U);
    DPU_LdWrite(ld, 0x1650,  0x0001999AU);
    DPU_LdWrite(ld, 0x1654,  0x03F8CCCDU);
    DPU_LdWrite(ld, 0x1658,  0x07800043U);
    DPU_LdWrite(ld, 0x165C,  0x00C01FFFU);
    DPU_LdWrite(ld, 0x1660,  0x00000000U);
    DPU_LdWrite(ld, 0x1664,  0x00808000U);
    DPU_LdWrite(ld, 0x1668,  0x07FF0000U);
    DPU_LdWrite(ld, 0x166C,  0x00000000U);
    DPU_LdWrite(ld, 0x1670,  0x00FFFFFFU);
    DPU_LdWrite(ld, 0x1680,  0x00000007U);
    DPU_LdWrite(ld, 0x1684,  0x00000000U);
    DPU_LdWrite(ld, 0x1688,  0x00800100U);
    DPU_LdWrite(ld, 0x168C,  0x01800200U);
    DPU_LdWrite(ld, 0x1690,  0x02800300U);
    DPU_LdWrite(ld, 0x1694,  0x03800400U);
    DPU_LdWrite(ld, 0x1698,  0x04800500U);
    DPU_LdWrite(ld, 0x169C,  0x05800600U);
    DPU_LdWrite(ld, 0x16A0,  0x06800700U);
    DPU_LdWrite(ld, 0x16A4,  0x07800800U);
    DPU_LdWrite(ld, 0x16A8,  0x08800900U);
    DPU_LdWrite(ld, 0x16AC,  0x09800A00U);
    DPU_LdWrite(ld, 0x16B0,  0x0A800B00U);
    DPU_LdWrite(ld, 0x16B4,  0x0B800C00U);
    DPU_LdWrite(ld, 0x16B8,  0x0C800D00U);
    DPU_LdWrite(ld, 0x16BC,  0x0D800E00U);
    DPU_LdWrite(ld, 0x16C0,  0x0E800F00U);
    DPU_LdWrite(ld, 0x16C4,  0x0F801000U);
    DPU_LdWrite(ld, 0x16C8,  0x00000000U);
    DPU_LdWrite(ld, 0x16CC,  0x00400060U);
    DPU_LdWrite(ld, 0x16D0,  0x008000A0U);
    DPU_LdWrite(ld, 0x16D4,  0x00C00100U);
    DPU_LdWrite(ld, 0x16D8,  0x01400180U);
    DPU_LdWrite(ld, 0x16DC,  0x01C00200U);
    DPU_LdWrite(ld, 0x16E0,  0x02800300U);
    DPU_LdWrite(ld, 0x16E4,  0x03800400U);
    DPU_LdWrite(ld, 0x16E8,  0x05000600U);
    DPU_LdWrite(ld, 0x16EC,  0x07000800U);
    DPU_LdWrite(ld, 0x16F0,  0x09000A00U);
    DPU_LdWrite(ld, 0x16F4,  0x0B000C00U);
    DPU_LdWrite(ld, 0x16F8,  0x0D000E00U);
    DPU_LdWrite(ld, 0x16FC,  0x0F001000U);
    DPU_LdWrite(ld, 0x1700,  0x000001F8U);
    DPU_LdWrite(ld, 0x1704,  0x00000001U);
    DPU_LdWrite(ld, 0x1708,  0x00001000U);
    DPU_LdWrite(ld, 0x170C,  0x00000001U);
    DPU_LdWrite(ld, 0x1710,  0x00020004U);
    DPU_LdWrite(ld, 0x1714,  0x00080010U);
    DPU_LdWrite(ld, 0x1718,  0x00200040U);
    DPU_LdWrite(ld, 0x171C,  0x00600080U);
    DPU_LdWrite(ld, 0x1720,  0x00A000C0U);
    DPU_LdWrite(ld, 0x1724,  0x01000140U);
    DPU_LdWrite(ld, 0x1728,  0x018001C0U);
    DPU_LdWrite(ld, 0x172C,  0x02000280U);
    DPU_LdWrite(ld, 0x1730,  0x03000380U);
    DPU_LdWrite(ld, 0x1734,  0x04000500U);
    DPU_LdWrite(ld, 0x1738,  0x06000700U);
    DPU_LdWrite(ld, 0x173C,  0x08000900U);
    DPU_LdWrite(ld, 0x1740,  0x0A000B00U);
    DPU_LdWrite(ld, 0x1744,  0x0C000D00U);
    DPU_LdWrite(ld, 0x1748,  0x0E000F00U);
    DPU_LdWrite(ld, 0x174C,  0x10000000U);
    DPU_LdWrite(ld, 0x1750,  0x00001000U);
    DPU_LdWrite(ld, 0x1754,  0x01010001U);
    DPU_LdWrite(ld, 0x1758,  0x00008038U);
    DPU_LdWrite(ld, 0x175C,  0x000FFFFFU);
    DPU_LdWrite(ld, 0x1760,  0x00000000U);
    DPU_LdWrite(ld, 0x1764,  0x00000000U);
    DPU_LdWrite(ld, 0x1768,  0x00104020U);
    DPU_LdWrite(ld, 0x176C,  0x00000000U);
    DPU_LdWrite(ld, 0x1770,  0x00000000U);
    DPU_LdWrite(ld, 0x1774,  0x00000000U);
    DPU_LdWrite(ld, 0x1778,  0x00000000U);
    DPU_LdWrite(ld, 0x177C,  0x00000000U);
    DPU_LdWrite(ld, 0x1780,  0x00000000U);
    DPU_LdWrite(ld, 0x1784,  0x00000001U);
    DPU_LdWrite(ld, 0x1788,  0x00020004U);
    DPU_LdWrite(ld, 0x178C,  0x00080010U);
    DPU_LdWrite(ld, 0x1790,  0x00200040U);
    DPU_LdWrite(ld, 0x1794,  0x00600080U);
    DPU_LdWrite(ld, 0x1798,  0x00A000C0U);
    DPU_LdWrite(ld, 0x179C,  0x01000140U);
    DPU_LdWrite(ld, 0x17A0,  0x018001C0U);
    DPU_LdWrite(ld, 0x17A4,  0x0200021CU);
    DPU_LdWrite(ld, 0x17A8,  0x03000380U);
    DPU_LdWrite(ld, 0x17AC,  0x04000500U);
    DPU_LdWrite(ld, 0x17B0,  0x06000700U);
    DPU_LdWrite(ld, 0x17B4,  0x08000900U);
    DPU_LdWrite(ld, 0x17B8,  0x0A000B00U);
    DPU_LdWrite(ld, 0x17BC,  0x0C000D00U);
    DPU_LdWrite(ld, 0x17C0,  0x0E000F00U);
    DPU_LdWrite(ld, 0x17C4,  0x10000000U);
    DPU_LdWrite(ld, 0x2000,  0x00100000U);
    DPU_LdWrite(ld, 0x2004,  0x00300020U);
    DPU_LdWrite(ld, 0x2008,  0x00500040U);
    DPU_LdWrite(ld, 0x200C,  0x00700060U);
    DPU_LdWrite(ld, 0x2010,  0x00900080U);
    DPU_LdWrite(ld, 0x2014,  0x00B000A0U);
    DPU_LdWrite(ld, 0x2018,  0x00D000C0U);
    DPU_LdWrite(ld, 0x201C,  0x00F000E0U);
    DPU_LdWrite(ld, 0x2020,  0x01100100U);
    DPU_LdWrite(ld, 0x2024,  0x01300120U);
    DPU_LdWrite(ld, 0x2028,  0x01500140U);
    DPU_LdWrite(ld, 0x202C,  0x01700160U);
    DPU_LdWrite(ld, 0x2030,  0x01900180U);
    DPU_LdWrite(ld, 0x2034,  0x01B001A0U);
    DPU_LdWrite(ld, 0x2038,  0x01D001C0U);
    DPU_LdWrite(ld, 0x203C,  0x01F001E0U);
    DPU_LdWrite(ld, 0x2040,  0x02100200U);
    DPU_LdWrite(ld, 0x2044,  0x02300220U);
    DPU_LdWrite(ld, 0x2048,  0x02500240U);
    DPU_LdWrite(ld, 0x204C,  0x02700260U);
    DPU_LdWrite(ld, 0x2050,  0x02900280U);
    DPU_LdWrite(ld, 0x2054,  0x02B002A0U);
    DPU_LdWrite(ld, 0x2058,  0x02D002C0U);
    DPU_LdWrite(ld, 0x205C,  0x02F002E0U);
    DPU_LdWrite(ld, 0x2060,  0x03100300U);
    DPU_LdWrite(ld, 0x2064,  0x03300320U);
    DPU_LdWrite(ld, 0x2068,  0x03500340U);
    DPU_LdWrite(ld, 0x206C,  0x03700360U);
    DPU_LdWrite(ld, 0x2070,  0x03900380U);
    DPU_LdWrite(ld, 0x2074,  0x03B003A0U);
    DPU_LdWrite(ld, 0x2078,  0x03D003C0U);
    DPU_LdWrite(ld, 0x207C,  0x03F003E0U);
    DPU_LdWrite(ld, 0x2080,  0x04100400U);
    DPU_LdWrite(ld, 0x2084,  0x04300420U);
    DPU_LdWrite(ld, 0x2088,  0x04500440U);
    DPU_LdWrite(ld, 0x208C,  0x04700460U);
    DPU_LdWrite(ld, 0x2090,  0x04900480U);
    DPU_LdWrite(ld, 0x2094,  0x04B004A0U);
    DPU_LdWrite(ld, 0x2098,  0x04D004C0U);
    DPU_LdWrite(ld, 0x209C,  0x04F004E0U);
    DPU_LdWrite(ld, 0x20A0,  0x05100500U);
    DPU_LdWrite(ld, 0x20A4,  0x05300520U);
    DPU_LdWrite(ld, 0x20A8,  0x05500540U);
    DPU_LdWrite(ld, 0x20AC,  0x05700560U);
    DPU_LdWrite(ld, 0x20B0,  0x05900580U);
    DPU_LdWrite(ld, 0x20B4,  0x05B005A0U);
    DPU_LdWrite(ld, 0x20B8,  0x05D005C0U);
    DPU_LdWrite(ld, 0x20BC,  0x05F005E0U);
    DPU_LdWrite(ld, 0x20C0,  0x06100600U);
    DPU_LdWrite(ld, 0x20C4,  0x06300620U);
    DPU_LdWrite(ld, 0x20C8,  0x06500640U);
    DPU_LdWrite(ld, 0x20CC,  0x06700660U);
    DPU_LdWrite(ld, 0x20D0,  0x06900680U);
    DPU_LdWrite(ld, 0x20D4,  0x06B006A0U);
    DPU_LdWrite(ld, 0x20D8,  0x06D006C0U);
    DPU_LdWrite(ld, 0x20DC,  0x06F006E0U);
    DPU_LdWrite(ld, 0x20E0,  0x07100700U);
    DPU_LdWrite(ld, 0x20E4,  0x07300720U);
    DPU_LdWrite(ld, 0x20E8,  0x07500740U);
    DPU_LdWrite(ld, 0x20EC,  0x07700760U);
    DPU_LdWrite(ld, 0x20F0,  0x07900780U);
    DPU_LdWrite(ld, 0x20F4,  0x07B007A0U);
    DPU_LdWrite(ld, 0x20F8,  0x07D007C0U);
    DPU_LdWrite(ld, 0x20FC,  0x07F007E0U);
    DPU_LdWrite(ld, 0x2100,  0x08100800U);
    DPU_LdWrite(ld, 0x2104,  0x08300820U);
    DPU_LdWrite(ld, 0x2108,  0x08500840U);
    DPU_LdWrite(ld, 0x210C,  0x08700860U);
    DPU_LdWrite(ld, 0x2110,  0x08900880U);
    DPU_LdWrite(ld, 0x2114,  0x08B008A0U);
    DPU_LdWrite(ld, 0x2118,  0x08D008C0U);
    DPU_LdWrite(ld, 0x211C,  0x08F008E0U);
    DPU_LdWrite(ld, 0x2120,  0x09100900U);
    DPU_LdWrite(ld, 0x2124,  0x09300920U);
    DPU_LdWrite(ld, 0x2128,  0x09500940U);
    DPU_LdWrite(ld, 0x212C,  0x09700960U);
    DPU_LdWrite(ld, 0x2130,  0x09900980U);
    DPU_LdWrite(ld, 0x2134,  0x09B009A0U);
    DPU_LdWrite(ld, 0x2138,  0x09D009C0U);
    DPU_LdWrite(ld, 0x213C,  0x09F009E0U);
    DPU_LdWrite(ld, 0x2140,  0x0A100A00U);
    DPU_LdWrite(ld, 0x2144,  0x0A300A20U);
    DPU_LdWrite(ld, 0x2148,  0x0A500A40U);
    DPU_LdWrite(ld, 0x214C,  0x0A700A60U);
    DPU_LdWrite(ld, 0x2150,  0x0A900A80U);
    DPU_LdWrite(ld, 0x2154,  0x0AB00AA0U);
    DPU_LdWrite(ld, 0x2158,  0x0AD00AC0U);
    DPU_LdWrite(ld, 0x215C,  0x0AF00AE0U);
    DPU_LdWrite(ld, 0x2160,  0x0B100B00U);
    DPU_LdWrite(ld, 0x2164,  0x0B300B20U);
    DPU_LdWrite(ld, 0x2168,  0x0B500B40U);
    DPU_LdWrite(ld, 0x216C,  0x0B700B60U);
    DPU_LdWrite(ld, 0x2170,  0x0B900B80U);
    DPU_LdWrite(ld, 0x2174,  0x0BB00BA0U);
    DPU_LdWrite(ld, 0x2178,  0x0BD00BC0U);
    DPU_LdWrite(ld, 0x217C,  0x0BF00BE0U);
    DPU_LdWrite(ld, 0x2180,  0x0C100C00U);
    DPU_LdWrite(ld, 0x2184,  0x0C300C20U);
    DPU_LdWrite(ld, 0x2188,  0x0C500C40U);
    DPU_LdWrite(ld, 0x218C,  0x0C700C60U);
    DPU_LdWrite(ld, 0x2190,  0x0C900C80U);
    DPU_LdWrite(ld, 0x2194,  0x0CB00CA0U);
    DPU_LdWrite(ld, 0x2198,  0x0CD00CC0U);
    DPU_LdWrite(ld, 0x219C,  0x0CF00CE0U);
    DPU_LdWrite(ld, 0x21A0,  0x0D100D00U);
    DPU_LdWrite(ld, 0x21A4,  0x0D300D20U);
    DPU_LdWrite(ld, 0x21A8,  0x0D500D40U);
    DPU_LdWrite(ld, 0x21AC,  0x0D700D60U);
    DPU_LdWrite(ld, 0x21B0,  0x0D900D80U);
    DPU_LdWrite(ld, 0x21B4,  0x0DB00DA0U);
    DPU_LdWrite(ld, 0x21B8,  0x0DD00DC0U);
    DPU_LdWrite(ld, 0x21BC,  0x0DF00DE0U);
    DPU_LdWrite(ld, 0x21C0,  0x0E100E00U);
    DPU_LdWrite(ld, 0x21C4,  0x0E300E20U);
    DPU_LdWrite(ld, 0x21C8,  0x0E500E40U);
    DPU_LdWrite(ld, 0x21CC,  0x0E700E60U);
    DPU_LdWrite(ld, 0x21D0,  0x0E900E80U);
    DPU_LdWrite(ld, 0x21D4,  0x0EB00EA0U);
    DPU_LdWrite(ld, 0x21D8,  0x0ED00EC0U);
    DPU_LdWrite(ld, 0x21DC,  0x0EF00EE0U);
    DPU_LdWrite(ld, 0x21E0,  0x0F100F00U);
    DPU_LdWrite(ld, 0x21E4,  0x0F300F20U);
    DPU_LdWrite(ld, 0x21E8,  0x0F500F40U);
    DPU_LdWrite(ld, 0x21EC,  0x0F700F60U);
    DPU_LdWrite(ld, 0x21F0,  0x0F900F80U);
    DPU_LdWrite(ld, 0x21F4,  0x0FB00FA0U);
    DPU_LdWrite(ld, 0x21F8,  0x0FD00FC0U);
    DPU_LdWrite(ld, 0x21FC,  0x0FF00FE0U);
    DPU_LdWrite(ld, 0x3000,  0x03FF03F6U);
    DPU_LdWrite(ld, 0x3004,  0x03E503CCU);
    DPU_LdWrite(ld, 0x3008,  0x03AD0387U);
    DPU_LdWrite(ld, 0x300C,  0x035D0330U);
    DPU_LdWrite(ld, 0x3010,  0x030002D0U);
    DPU_LdWrite(ld, 0x3014,  0x029F0270U);
    DPU_LdWrite(ld, 0x3018,  0x02420216U);
    DPU_LdWrite(ld, 0x301C,  0x01ED01C7U);
    DPU_LdWrite(ld, 0x3020,  0x01A30182U);
    DPU_LdWrite(ld, 0x3024,  0x01630147U);
    DPU_LdWrite(ld, 0x3028,  0x012C0114U);
    DPU_LdWrite(ld, 0x302C,  0x00FD00E8U);
    DPU_LdWrite(ld, 0x3030,  0x00D500C3U);
    DPU_LdWrite(ld, 0x3034,  0x00B200A2U);
    DPU_LdWrite(ld, 0x3038,  0x00930085U);
    DPU_LdWrite(ld, 0x303C,  0x0078006CU);
    DPU_LdWrite(ld, 0x3040,  0x00610057U);
    DPU_LdWrite(ld, 0x3044,  0x004E0045U);
    DPU_LdWrite(ld, 0x3048,  0x003D0036U);
    DPU_LdWrite(ld, 0x304C,  0x0030002AU);
    DPU_LdWrite(ld, 0x3050,  0x00240020U);
    DPU_LdWrite(ld, 0x3054,  0x001C0018U);
    DPU_LdWrite(ld, 0x3058,  0x00150012U);
    DPU_LdWrite(ld, 0x305C,  0x000F000DU);
    DPU_LdWrite(ld, 0x3080,  0x03F603EEU);
    DPU_LdWrite(ld, 0x3084,  0x03DD03C4U);
    DPU_LdWrite(ld, 0x3088,  0x03A50380U);
    DPU_LdWrite(ld, 0x308C,  0x03560329U);
    DPU_LdWrite(ld, 0x3090,  0x02FA02CBU);
    DPU_LdWrite(ld, 0x3094,  0x029B026CU);
    DPU_LdWrite(ld, 0x3098,  0x023E0213U);
    DPU_LdWrite(ld, 0x309C,  0x01EA01C4U);
    DPU_LdWrite(ld, 0x30A0,  0x01A10180U);
    DPU_LdWrite(ld, 0x30A4,  0x01610145U);
    DPU_LdWrite(ld, 0x30A8,  0x012B0113U);
    DPU_LdWrite(ld, 0x30AC,  0x00FC00E8U);
    DPU_LdWrite(ld, 0x30B0,  0x00D400C2U);
    DPU_LdWrite(ld, 0x30B4,  0x00B100A1U);
    DPU_LdWrite(ld, 0x30B8,  0x00920085U);
    DPU_LdWrite(ld, 0x30BC,  0x0078006CU);
    DPU_LdWrite(ld, 0x30C0,  0x00610057U);
    DPU_LdWrite(ld, 0x30C4,  0x004D0045U);
    DPU_LdWrite(ld, 0x30C8,  0x003D0036U);
    DPU_LdWrite(ld, 0x30CC,  0x002F002AU);
    DPU_LdWrite(ld, 0x30D0,  0x00240020U);
    DPU_LdWrite(ld, 0x30D4,  0x001C0018U);
    DPU_LdWrite(ld, 0x30D8,  0x00150012U);
    DPU_LdWrite(ld, 0x30DC,  0x000F000DU);
    DPU_LdWrite(ld, 0x3100,  0x03E503DDU);
    DPU_LdWrite(ld, 0x3104,  0x03CC03B4U);
    DPU_LdWrite(ld, 0x3108,  0x03960372U);
    DPU_LdWrite(ld, 0x310C,  0x0349031DU);
    DPU_LdWrite(ld, 0x3110,  0x02EF02C1U);
    DPU_LdWrite(ld, 0x3114,  0x02920264U);
    DPU_LdWrite(ld, 0x3118,  0x0237020DU);
    DPU_LdWrite(ld, 0x311C,  0x01E501C0U);
    DPU_LdWrite(ld, 0x3120,  0x019D017CU);
    DPU_LdWrite(ld, 0x3124,  0x015E0142U);
    DPU_LdWrite(ld, 0x3128,  0x01290111U);
    DPU_LdWrite(ld, 0x312C,  0x00FB00E6U);
    DPU_LdWrite(ld, 0x3130,  0x00D300C1U);
    DPU_LdWrite(ld, 0x3134,  0x00B000A0U);
    DPU_LdWrite(ld, 0x3138,  0x00910084U);
    DPU_LdWrite(ld, 0x313C,  0x0077006BU);
    DPU_LdWrite(ld, 0x3140,  0x00600056U);
    DPU_LdWrite(ld, 0x3144,  0x004D0044U);
    DPU_LdWrite(ld, 0x3148,  0x003C0035U);
    DPU_LdWrite(ld, 0x314C,  0x002F0029U);
    DPU_LdWrite(ld, 0x3150,  0x0024001FU);
    DPU_LdWrite(ld, 0x3154,  0x001B0018U);
    DPU_LdWrite(ld, 0x3158,  0x00140012U);
    DPU_LdWrite(ld, 0x315C,  0x000F000DU);
    DPU_LdWrite(ld, 0x3180,  0x03CC03C4U);
    DPU_LdWrite(ld, 0x3184,  0x03B4039DU);
    DPU_LdWrite(ld, 0x3188,  0x0380035DU);
    DPU_LdWrite(ld, 0x318C,  0x0336030CU);
    DPU_LdWrite(ld, 0x3190,  0x02DF02B2U);
    DPU_LdWrite(ld, 0x3194,  0x02850258U);
    DPU_LdWrite(ld, 0x3198,  0x022D0204U);
    DPU_LdWrite(ld, 0x319C,  0x01DD01B9U);
    DPU_LdWrite(ld, 0x31A0,  0x01970177U);
    DPU_LdWrite(ld, 0x31A4,  0x015A013EU);
    DPU_LdWrite(ld, 0x31A8,  0x0125010EU);
    DPU_LdWrite(ld, 0x31AC,  0x00F800E3U);
    DPU_LdWrite(ld, 0x31B0,  0x00D000BFU);
    DPU_LdWrite(ld, 0x31B4,  0x00AE009EU);
    DPU_LdWrite(ld, 0x31B8,  0x00900082U);
    DPU_LdWrite(ld, 0x31BC,  0x0076006AU);
    DPU_LdWrite(ld, 0x31C0,  0x005F0055U);
    DPU_LdWrite(ld, 0x31C4,  0x004C0044U);
    DPU_LdWrite(ld, 0x31C8,  0x003C0035U);
    DPU_LdWrite(ld, 0x31CC,  0x002F0029U);
    DPU_LdWrite(ld, 0x31D0,  0x0024001FU);
    DPU_LdWrite(ld, 0x31D4,  0x001B0017U);
    DPU_LdWrite(ld, 0x31D8,  0x00140011U);
    DPU_LdWrite(ld, 0x31DC,  0x000F000DU);
    DPU_LdWrite(ld, 0x3200,  0x03AD03A5U);
    DPU_LdWrite(ld, 0x3204,  0x03960380U);
    DPU_LdWrite(ld, 0x3208,  0x03640343U);
    DPU_LdWrite(ld, 0x320C,  0x031D02F5U);
    DPU_LdWrite(ld, 0x3210,  0x02CB029FU);
    DPU_LdWrite(ld, 0x3214,  0x02740249U);
    DPU_LdWrite(ld, 0x3218,  0x022001F8U);
    DPU_LdWrite(ld, 0x321C,  0x01D301B0U);
    DPU_LdWrite(ld, 0x3220,  0x018F0170U);
    DPU_LdWrite(ld, 0x3224,  0x01540139U);
    DPU_LdWrite(ld, 0x3228,  0x01200109U);
    DPU_LdWrite(ld, 0x322C,  0x00F400E0U);
    DPU_LdWrite(ld, 0x3230,  0x00CD00BCU);
    DPU_LdWrite(ld, 0x3234,  0x00AC009CU);
    DPU_LdWrite(ld, 0x3238,  0x008E0081U);
    DPU_LdWrite(ld, 0x323C,  0x00740069U);
    DPU_LdWrite(ld, 0x3240,  0x005E0054U);
    DPU_LdWrite(ld, 0x3244,  0x004B0043U);
    DPU_LdWrite(ld, 0x3248,  0x003B0034U);
    DPU_LdWrite(ld, 0x324C,  0x002E0028U);
    DPU_LdWrite(ld, 0x3250,  0x0023001FU);
    DPU_LdWrite(ld, 0x3254,  0x001B0017U);
    DPU_LdWrite(ld, 0x3258,  0x00140011U);
    DPU_LdWrite(ld, 0x325C,  0x000F000DU);
    DPU_LdWrite(ld, 0x3280,  0x03870380U);
    DPU_LdWrite(ld, 0x3284,  0x0372035DU);
    DPU_LdWrite(ld, 0x3288,  0x03430323U);
    DPU_LdWrite(ld, 0x328C,  0x030002DAU);
    DPU_LdWrite(ld, 0x3290,  0x02B20289U);
    DPU_LdWrite(ld, 0x3294,  0x02600237U);
    DPU_LdWrite(ld, 0x3298,  0x021001EAU);
    DPU_LdWrite(ld, 0x329C,  0x01C701A5U);
    DPU_LdWrite(ld, 0x32A0,  0x01850168U);
    DPU_LdWrite(ld, 0x32A4,  0x014C0133U);
    DPU_LdWrite(ld, 0x32A8,  0x011B0104U);
    DPU_LdWrite(ld, 0x32AC,  0x00EF00DCU);
    DPU_LdWrite(ld, 0x32B0,  0x00CA00B9U);
    DPU_LdWrite(ld, 0x32B4,  0x00A9009AU);
    DPU_LdWrite(ld, 0x32B8,  0x008B007EU);
    DPU_LdWrite(ld, 0x32BC,  0x00720067U);
    DPU_LdWrite(ld, 0x32C0,  0x005C0053U);
    DPU_LdWrite(ld, 0x32C4,  0x004A0042U);
    DPU_LdWrite(ld, 0x32C8,  0x003A0033U);
    DPU_LdWrite(ld, 0x32CC,  0x002D0028U);
    DPU_LdWrite(ld, 0x32D0,  0x0023001EU);
    DPU_LdWrite(ld, 0x32D4,  0x001A0017U);
    DPU_LdWrite(ld, 0x32D8,  0x00140011U);
    DPU_LdWrite(ld, 0x32DC,  0x000E000CU);
    DPU_LdWrite(ld, 0x3300,  0x035D0356U);
    DPU_LdWrite(ld, 0x3304,  0x03490336U);
    DPU_LdWrite(ld, 0x3308,  0x031D0300U);
    DPU_LdWrite(ld, 0x330C,  0x02DF02BCU);
    DPU_LdWrite(ld, 0x3310,  0x02960270U);
    DPU_LdWrite(ld, 0x3314,  0x02490223U);
    DPU_LdWrite(ld, 0x3318,  0x01FE01DBU);
    DPU_LdWrite(ld, 0x331C,  0x01B90199U);
    DPU_LdWrite(ld, 0x3320,  0x017A015EU);
    DPU_LdWrite(ld, 0x3324,  0x0144012BU);
    DPU_LdWrite(ld, 0x3328,  0x011400FEU);
    DPU_LdWrite(ld, 0x332C,  0x00EA00D7U);
    DPU_LdWrite(ld, 0x3330,  0x00C500B5U);
    DPU_LdWrite(ld, 0x3334,  0x00A50096U);
    DPU_LdWrite(ld, 0x3338,  0x0089007CU);
    DPU_LdWrite(ld, 0x333C,  0x00700065U);
    DPU_LdWrite(ld, 0x3340,  0x005A0051U);
    DPU_LdWrite(ld, 0x3344,  0x00480040U);
    DPU_LdWrite(ld, 0x3348,  0x00390032U);
    DPU_LdWrite(ld, 0x334C,  0x002C0027U);
    DPU_LdWrite(ld, 0x3350,  0x0022001EU);
    DPU_LdWrite(ld, 0x3354,  0x001A0016U);
    DPU_LdWrite(ld, 0x3358,  0x00130011U);
    DPU_LdWrite(ld, 0x335C,  0x000E000CU);
    DPU_LdWrite(ld, 0x3380,  0x03300329U);
    DPU_LdWrite(ld, 0x3384,  0x031D030CU);
    DPU_LdWrite(ld, 0x3388,  0x02F502DAU);
    DPU_LdWrite(ld, 0x338C,  0x02BC029BU);
    DPU_LdWrite(ld, 0x3390,  0x02780254U);
    DPU_LdWrite(ld, 0x3394,  0x0231020DU);
    DPU_LdWrite(ld, 0x3398,  0x01EA01C9U);
    DPU_LdWrite(ld, 0x339C,  0x01A9018BU);
    DPU_LdWrite(ld, 0x33A0,  0x016E0154U);
    DPU_LdWrite(ld, 0x33A4,  0x013A0123U);
    DPU_LdWrite(ld, 0x33A8,  0x010D00F8U);
    DPU_LdWrite(ld, 0x33AC,  0x00E400D2U);
    DPU_LdWrite(ld, 0x33B0,  0x00C100B0U);
    DPU_LdWrite(ld, 0x33B4,  0x00A10093U);
    DPU_LdWrite(ld, 0x33B8,  0x00850079U);
    DPU_LdWrite(ld, 0x33BC,  0x006D0062U);
    DPU_LdWrite(ld, 0x33C0,  0x0058004FU);
    DPU_LdWrite(ld, 0x33C4,  0x0047003FU);
    DPU_LdWrite(ld, 0x33C8,  0x00380031U);
    DPU_LdWrite(ld, 0x33CC,  0x002B0026U);
    DPU_LdWrite(ld, 0x33D0,  0x0021001DU);
    DPU_LdWrite(ld, 0x33D4,  0x00190016U);
    DPU_LdWrite(ld, 0x33D8,  0x00130010U);
    DPU_LdWrite(ld, 0x33DC,  0x000E000CU);
    DPU_LdWrite(ld, 0x3400,  0x030002FAU);
    DPU_LdWrite(ld, 0x3404,  0x02EF02DFU);
    DPU_LdWrite(ld, 0x3408,  0x02CB02B2U);
    DPU_LdWrite(ld, 0x340C,  0x02960278U);
    DPU_LdWrite(ld, 0x3410,  0x02580237U);
    DPU_LdWrite(ld, 0x3414,  0x021601F6U);
    DPU_LdWrite(ld, 0x3418,  0x01D501B6U);
    DPU_LdWrite(ld, 0x341C,  0x0199017CU);
    DPU_LdWrite(ld, 0x3420,  0x01610148U);
    DPU_LdWrite(ld, 0x3424,  0x0130011AU);
    DPU_LdWrite(ld, 0x3428,  0x010400F0U);
    DPU_LdWrite(ld, 0x342C,  0x00DE00CCU);
    DPU_LdWrite(ld, 0x3430,  0x00BB00ACU);
    DPU_LdWrite(ld, 0x3434,  0x009D008FU);
    DPU_LdWrite(ld, 0x3438,  0x00820076U);
    DPU_LdWrite(ld, 0x343C,  0x006A0060U);
    DPU_LdWrite(ld, 0x3440,  0x0056004DU);
    DPU_LdWrite(ld, 0x3444,  0x0045003DU);
    DPU_LdWrite(ld, 0x3448,  0x00360030U);
    DPU_LdWrite(ld, 0x344C,  0x002A0025U);
    DPU_LdWrite(ld, 0x3450,  0x0020001CU);
    DPU_LdWrite(ld, 0x3454,  0x00180015U);
    DPU_LdWrite(ld, 0x3458,  0x00120010U);
    DPU_LdWrite(ld, 0x345C,  0x000D000CU);
    DPU_LdWrite(ld, 0x3480,  0x02D002CBU);
    DPU_LdWrite(ld, 0x3484,  0x02C102B2U);
    DPU_LdWrite(ld, 0x3488,  0x029F0289U);
    DPU_LdWrite(ld, 0x348C,  0x02700254U);
    DPU_LdWrite(ld, 0x3490,  0x0237021AU);
    DPU_LdWrite(ld, 0x3494,  0x01FB01DDU);
    DPU_LdWrite(ld, 0x3498,  0x01C001A3U);
    DPU_LdWrite(ld, 0x349C,  0x0187016DU);
    DPU_LdWrite(ld, 0x34A0,  0x0154013CU);
    DPU_LdWrite(ld, 0x34A4,  0x01250110U);
    DPU_LdWrite(ld, 0x34A8,  0x00FC00E8U);
    DPU_LdWrite(ld, 0x34AC,  0x00D600C5U);
    DPU_LdWrite(ld, 0x34B0,  0x00B500A6U);
    DPU_LdWrite(ld, 0x34B4,  0x0098008BU);
    DPU_LdWrite(ld, 0x34B8,  0x007E0072U);
    DPU_LdWrite(ld, 0x34BC,  0x0067005DU);
    DPU_LdWrite(ld, 0x34C0,  0x0053004BU);
    DPU_LdWrite(ld, 0x34C4,  0x0043003BU);
    DPU_LdWrite(ld, 0x34C8,  0x0035002EU);
    DPU_LdWrite(ld, 0x34CC,  0x00290024U);
    DPU_LdWrite(ld, 0x34D0,  0x001F001BU);
    DPU_LdWrite(ld, 0x34D4,  0x00180015U);
    DPU_LdWrite(ld, 0x34D8,  0x0012000FU);
    DPU_LdWrite(ld, 0x34DC,  0x000D000BU);
    DPU_LdWrite(ld, 0x3500,  0x029F029BU);
    DPU_LdWrite(ld, 0x3504,  0x02920285U);
    DPU_LdWrite(ld, 0x3508,  0x02740260U);
    DPU_LdWrite(ld, 0x350C,  0x02490231U);
    DPU_LdWrite(ld, 0x3510,  0x021601FBU);
    DPU_LdWrite(ld, 0x3514,  0x01E001C4U);
    DPU_LdWrite(ld, 0x3518,  0x01A9018FU);
    DPU_LdWrite(ld, 0x351C,  0x0175015DU);
    DPU_LdWrite(ld, 0x3520,  0x0145012FU);
    DPU_LdWrite(ld, 0x3524,  0x011A0105U);
    DPU_LdWrite(ld, 0x3528,  0x00F200E0U);
    DPU_LdWrite(ld, 0x352C,  0x00CF00BFU);
    DPU_LdWrite(ld, 0x3530,  0x00AF00A1U);
    DPU_LdWrite(ld, 0x3534,  0x00930086U);
    DPU_LdWrite(ld, 0x3538,  0x007A006EU);
    DPU_LdWrite(ld, 0x353C,  0x0064005AU);
    DPU_LdWrite(ld, 0x3540,  0x00510048U);
    DPU_LdWrite(ld, 0x3544,  0x00400039U);
    DPU_LdWrite(ld, 0x3548,  0x0033002DU);
    DPU_LdWrite(ld, 0x354C,  0x00280023U);
    DPU_LdWrite(ld, 0x3550,  0x001E001AU);
    DPU_LdWrite(ld, 0x3554,  0x00170014U);
    DPU_LdWrite(ld, 0x3558,  0x0011000FU);
    DPU_LdWrite(ld, 0x355C,  0x000D000BU);
    DPU_LdWrite(ld, 0x3580,  0x0270026CU);
    DPU_LdWrite(ld, 0x3584,  0x02640258U);
    DPU_LdWrite(ld, 0x3588,  0x02490237U);
    DPU_LdWrite(ld, 0x358C,  0x0223020DU);
    DPU_LdWrite(ld, 0x3590,  0x01F601DDU);
    DPU_LdWrite(ld, 0x3594,  0x01C401ABU);
    DPU_LdWrite(ld, 0x3598,  0x0193017AU);
    DPU_LdWrite(ld, 0x359C,  0x0163014CU);
    DPU_LdWrite(ld, 0x35A0,  0x01360122U);
    DPU_LdWrite(ld, 0x35A4,  0x010E00FBU);
    DPU_LdWrite(ld, 0x35A8,  0x00E800D7U);
    DPU_LdWrite(ld, 0x35AC,  0x00C700B7U);
    DPU_LdWrite(ld, 0x35B0,  0x00A9009BU);
    DPU_LdWrite(ld, 0x35B4,  0x008D0081U);
    DPU_LdWrite(ld, 0x35B8,  0x0075006AU);
    DPU_LdWrite(ld, 0x35BC,  0x00600057U);
    DPU_LdWrite(ld, 0x35C0,  0x004E0046U);
    DPU_LdWrite(ld, 0x35C4,  0x003E0037U);
    DPU_LdWrite(ld, 0x35C8,  0x0031002BU);
    DPU_LdWrite(ld, 0x35CC,  0x00260021U);
    DPU_LdWrite(ld, 0x35D0,  0x001D0019U);
    DPU_LdWrite(ld, 0x35D4,  0x00160013U);
    DPU_LdWrite(ld, 0x35D8,  0x0011000EU);
    DPU_LdWrite(ld, 0x35DC,  0x000C000AU);
    DPU_LdWrite(ld, 0x3600,  0x0242023EU);
    DPU_LdWrite(ld, 0x3604,  0x0237022DU);
    DPU_LdWrite(ld, 0x3608,  0x02200210U);
    DPU_LdWrite(ld, 0x360C,  0x01FE01EAU);
    DPU_LdWrite(ld, 0x3610,  0x01D501C0U);
    DPU_LdWrite(ld, 0x3614,  0x01A90193U);
    DPU_LdWrite(ld, 0x3618,  0x017C0166U);
    DPU_LdWrite(ld, 0x361C,  0x0151013CU);
    DPU_LdWrite(ld, 0x3620,  0x01270114U);
    DPU_LdWrite(ld, 0x3624,  0x010100EFU);
    DPU_LdWrite(ld, 0x3628,  0x00DE00CEU);
    DPU_LdWrite(ld, 0x362C,  0x00BF00B0U);
    DPU_LdWrite(ld, 0x3630,  0x00A20094U);
    DPU_LdWrite(ld, 0x3634,  0x0088007CU);
    DPU_LdWrite(ld, 0x3638,  0x00710066U);
    DPU_LdWrite(ld, 0x363C,  0x005C0053U);
    DPU_LdWrite(ld, 0x3640,  0x004B0043U);
    DPU_LdWrite(ld, 0x3644,  0x003C0035U);
    DPU_LdWrite(ld, 0x3648,  0x002F002AU);
    DPU_LdWrite(ld, 0x364C,  0x00250020U);
    DPU_LdWrite(ld, 0x3650,  0x001C0018U);
    DPU_LdWrite(ld, 0x3654,  0x00150012U);
    DPU_LdWrite(ld, 0x3658,  0x0010000EU);
    DPU_LdWrite(ld, 0x365C,  0x000C000AU);
    DPU_LdWrite(ld, 0x3680,  0x02160213U);
    DPU_LdWrite(ld, 0x3684,  0x020D0204U);
    DPU_LdWrite(ld, 0x3688,  0x01F801EAU);
    DPU_LdWrite(ld, 0x368C,  0x01DB01C9U);
    DPU_LdWrite(ld, 0x3690,  0x01B601A3U);
    DPU_LdWrite(ld, 0x3694,  0x018F017AU);
    DPU_LdWrite(ld, 0x3698,  0x01660152U);
    DPU_LdWrite(ld, 0x369C,  0x013E012BU);
    DPU_LdWrite(ld, 0x36A0,  0x01180106U);
    DPU_LdWrite(ld, 0x36A4,  0x00F500E4U);
    DPU_LdWrite(ld, 0x36A8,  0x00D400C5U);
    DPU_LdWrite(ld, 0x36AC,  0x00B600A8U);
    DPU_LdWrite(ld, 0x36B0,  0x009B008EU);
    DPU_LdWrite(ld, 0x36B4,  0x00820076U);
    DPU_LdWrite(ld, 0x36B8,  0x006C0062U);
    DPU_LdWrite(ld, 0x36BC,  0x00580050U);
    DPU_LdWrite(ld, 0x36C0,  0x00480040U);
    DPU_LdWrite(ld, 0x36C4,  0x00390033U);
    DPU_LdWrite(ld, 0x36C8,  0x002D0028U);
    DPU_LdWrite(ld, 0x36CC,  0x0023001FU);
    DPU_LdWrite(ld, 0x36D0,  0x001B0017U);
    DPU_LdWrite(ld, 0x36D4,  0x00140012U);
    DPU_LdWrite(ld, 0x36D8,  0x000F000DU);
    DPU_LdWrite(ld, 0x36DC,  0x000B000AU);
    DPU_LdWrite(ld, 0x3700,  0x01ED01EAU);
    DPU_LdWrite(ld, 0x3704,  0x01E501DDU);
    DPU_LdWrite(ld, 0x3708,  0x01D301C7U);
    DPU_LdWrite(ld, 0x370C,  0x01B901A9U);
    DPU_LdWrite(ld, 0x3710,  0x01990187U);
    DPU_LdWrite(ld, 0x3714,  0x01750163U);
    DPU_LdWrite(ld, 0x3718,  0x0151013EU);
    DPU_LdWrite(ld, 0x371C,  0x012C011BU);
    DPU_LdWrite(ld, 0x3720,  0x010900F9U);
    DPU_LdWrite(ld, 0x3724,  0x00E800D9U);
    DPU_LdWrite(ld, 0x3728,  0x00CA00BBU);
    DPU_LdWrite(ld, 0x372C,  0x00AD00A0U);
    DPU_LdWrite(ld, 0x3730,  0x00930087U);
    DPU_LdWrite(ld, 0x3734,  0x007C0071U);
    DPU_LdWrite(ld, 0x3738,  0x0067005DU);
    DPU_LdWrite(ld, 0x373C,  0x0054004CU);
    DPU_LdWrite(ld, 0x3740,  0x0044003DU);
    DPU_LdWrite(ld, 0x3744,  0x00370030U);
    DPU_LdWrite(ld, 0x3748,  0x002B0026U);
    DPU_LdWrite(ld, 0x374C,  0x0021001DU);
    DPU_LdWrite(ld, 0x3750,  0x001A0016U);
    DPU_LdWrite(ld, 0x3754,  0x00130011U);
    DPU_LdWrite(ld, 0x3758,  0x000F000CU);
    DPU_LdWrite(ld, 0x375C,  0x000B0009U);
    DPU_LdWrite(ld, 0x3780,  0x01C701C4U);
    DPU_LdWrite(ld, 0x3784,  0x01C001B9U);
    DPU_LdWrite(ld, 0x3788,  0x01B001A5U);
    DPU_LdWrite(ld, 0x378C,  0x0199018BU);
    DPU_LdWrite(ld, 0x3790,  0x017C016DU);
    DPU_LdWrite(ld, 0x3794,  0x015D014CU);
    DPU_LdWrite(ld, 0x3798,  0x013C012BU);
    DPU_LdWrite(ld, 0x379C,  0x011B010AU);
    DPU_LdWrite(ld, 0x37A0,  0x00FB00EBU);
    DPU_LdWrite(ld, 0x37A4,  0x00DC00CDU);
    DPU_LdWrite(ld, 0x37A8,  0x00BF00B2U);
    DPU_LdWrite(ld, 0x37AC,  0x00A50098U);
    DPU_LdWrite(ld, 0x37B0,  0x008C0081U);
    DPU_LdWrite(ld, 0x37B4,  0x0076006BU);
    DPU_LdWrite(ld, 0x37B8,  0x00620059U);
    DPU_LdWrite(ld, 0x37BC,  0x00500048U);
    DPU_LdWrite(ld, 0x37C0,  0x0041003AU);
    DPU_LdWrite(ld, 0x37C4,  0x0034002EU);
    DPU_LdWrite(ld, 0x37C8,  0x00290024U);
    DPU_LdWrite(ld, 0x37CC,  0x0020001CU);
    DPU_LdWrite(ld, 0x37D0,  0x00180015U);
    DPU_LdWrite(ld, 0x37D4,  0x00120010U);
    DPU_LdWrite(ld, 0x37D8,  0x000E000CU);
    DPU_LdWrite(ld, 0x37DC,  0x000A0009U);
    DPU_LdWrite(ld, 0x3800,  0x01A301A1U);
    DPU_LdWrite(ld, 0x3804,  0x019D0197U);
    DPU_LdWrite(ld, 0x3808,  0x018F0185U);
    DPU_LdWrite(ld, 0x380C,  0x017A016EU);
    DPU_LdWrite(ld, 0x3810,  0x01610154U);
    DPU_LdWrite(ld, 0x3814,  0x01450136U);
    DPU_LdWrite(ld, 0x3818,  0x01270118U);
    DPU_LdWrite(ld, 0x381C,  0x010900FBU);
    DPU_LdWrite(ld, 0x3820,  0x00EC00DEU);
    DPU_LdWrite(ld, 0x3824,  0x00D000C2U);
    DPU_LdWrite(ld, 0x3828,  0x00B500A8U);
    DPU_LdWrite(ld, 0x382C,  0x009C0090U);
    DPU_LdWrite(ld, 0x3830,  0x0085007AU);
    DPU_LdWrite(ld, 0x3834,  0x006F0066U);
    DPU_LdWrite(ld, 0x3838,  0x005D0054U);
    DPU_LdWrite(ld, 0x383C,  0x004C0044U);
    DPU_LdWrite(ld, 0x3840,  0x003E0037U);
    DPU_LdWrite(ld, 0x3844,  0x0031002CU);
    DPU_LdWrite(ld, 0x3848,  0x00270022U);
    DPU_LdWrite(ld, 0x384C,  0x001E001AU);
    DPU_LdWrite(ld, 0x3850,  0x00170014U);
    DPU_LdWrite(ld, 0x3854,  0x0012000FU);
    DPU_LdWrite(ld, 0x3858,  0x000D000BU);
    DPU_LdWrite(ld, 0x385C,  0x000A0008U);
    DPU_LdWrite(ld, 0x3880,  0x01820180U);
    DPU_LdWrite(ld, 0x3884,  0x017C0177U);
    DPU_LdWrite(ld, 0x3888,  0x01700168U);
    DPU_LdWrite(ld, 0x388C,  0x015E0154U);
    DPU_LdWrite(ld, 0x3890,  0x0148013CU);
    DPU_LdWrite(ld, 0x3894,  0x012F0122U);
    DPU_LdWrite(ld, 0x3898,  0x01140106U);
    DPU_LdWrite(ld, 0x389C,  0x00F900EBU);
    DPU_LdWrite(ld, 0x38A0,  0x00DE00D0U);
    DPU_LdWrite(ld, 0x38A4,  0x00C300B7U);
    DPU_LdWrite(ld, 0x38A8,  0x00AA009EU);
    DPU_LdWrite(ld, 0x38AC,  0x00930088U);
    DPU_LdWrite(ld, 0x38B0,  0x007D0073U);
    DPU_LdWrite(ld, 0x38B4,  0x00690060U);
    DPU_LdWrite(ld, 0x38B8,  0x0057004FU);
    DPU_LdWrite(ld, 0x38BC,  0x00480041U);
    DPU_LdWrite(ld, 0x38C0,  0x003A0034U);
    DPU_LdWrite(ld, 0x38C4,  0x002E0029U);
    DPU_LdWrite(ld, 0x38C8,  0x00250020U);
    DPU_LdWrite(ld, 0x38CC,  0x001C0019U);
    DPU_LdWrite(ld, 0x38D0,  0x00160013U);
    DPU_LdWrite(ld, 0x38D4,  0x0011000EU);
    DPU_LdWrite(ld, 0x38D8,  0x000C000BU);
    DPU_LdWrite(ld, 0x38DC,  0x00090008U);
    DPU_LdWrite(ld, 0x3900,  0x01630161U);
    DPU_LdWrite(ld, 0x3904,  0x015E015AU);
    DPU_LdWrite(ld, 0x3908,  0x0154014CU);
    DPU_LdWrite(ld, 0x390C,  0x0144013AU);
    DPU_LdWrite(ld, 0x3910,  0x01300125U);
    DPU_LdWrite(ld, 0x3914,  0x011A010EU);
    DPU_LdWrite(ld, 0x3918,  0x010100F5U);
    DPU_LdWrite(ld, 0x391C,  0x00E800DCU);
    DPU_LdWrite(ld, 0x3920,  0x00D000C3U);
    DPU_LdWrite(ld, 0x3924,  0x00B700ACU);
    DPU_LdWrite(ld, 0x3928,  0x00A00095U);
    DPU_LdWrite(ld, 0x392C,  0x008A0080U);
    DPU_LdWrite(ld, 0x3930,  0x0076006CU);
    DPU_LdWrite(ld, 0x3934,  0x0063005AU);
    DPU_LdWrite(ld, 0x3938,  0x0052004BU);
    DPU_LdWrite(ld, 0x393C,  0x0044003DU);
    DPU_LdWrite(ld, 0x3940,  0x00370031U);
    DPU_LdWrite(ld, 0x3944,  0x002C0027U);
    DPU_LdWrite(ld, 0x3948,  0x0022001EU);
    DPU_LdWrite(ld, 0x394C,  0x001B0018U);
    DPU_LdWrite(ld, 0x3950,  0x00150012U);
    DPU_LdWrite(ld, 0x3954,  0x0010000DU);
    DPU_LdWrite(ld, 0x3958,  0x000C000AU);
    DPU_LdWrite(ld, 0x395C,  0x00090007U);
    DPU_LdWrite(ld, 0x3980,  0x01470145U);
    DPU_LdWrite(ld, 0x3984,  0x0142013EU);
    DPU_LdWrite(ld, 0x3988,  0x01390133U);
    DPU_LdWrite(ld, 0x398C,  0x012B0123U);
    DPU_LdWrite(ld, 0x3990,  0x011A0110U);
    DPU_LdWrite(ld, 0x3994,  0x010500FBU);
    DPU_LdWrite(ld, 0x3998,  0x00EF00E4U);
    DPU_LdWrite(ld, 0x399C,  0x00D900CDU);
    DPU_LdWrite(ld, 0x39A0,  0x00C200B7U);
    DPU_LdWrite(ld, 0x39A4,  0x00AC00A1U);
    DPU_LdWrite(ld, 0x39A8,  0x0096008BU);
    DPU_LdWrite(ld, 0x39AC,  0x00810078U);
    DPU_LdWrite(ld, 0x39B0,  0x006E0065U);
    DPU_LdWrite(ld, 0x39B4,  0x005D0055U);
    DPU_LdWrite(ld, 0x39B8,  0x004D0046U);
    DPU_LdWrite(ld, 0x39BC,  0x003F0039U);
    DPU_LdWrite(ld, 0x39C0,  0x0033002EU);
    DPU_LdWrite(ld, 0x39C4,  0x00290024U);
    DPU_LdWrite(ld, 0x39C8,  0x0020001DU);
    DPU_LdWrite(ld, 0x39CC,  0x00190016U);
    DPU_LdWrite(ld, 0x39D0,  0x00130011U);
    DPU_LdWrite(ld, 0x39D4,  0x000F000DU);
    DPU_LdWrite(ld, 0x39D8,  0x000B0009U);
    DPU_LdWrite(ld, 0x39DC,  0x00080007U);
    DPU_LdWrite(ld, 0x3A00,  0x012C012BU);
    DPU_LdWrite(ld, 0x3A04,  0x01290125U);
    DPU_LdWrite(ld, 0x3A08,  0x0120011BU);
    DPU_LdWrite(ld, 0x3A0C,  0x0114010DU);
    DPU_LdWrite(ld, 0x3A10,  0x010400FCU);
    DPU_LdWrite(ld, 0x3A14,  0x00F200E8U);
    DPU_LdWrite(ld, 0x3A18,  0x00DE00D4U);
    DPU_LdWrite(ld, 0x3A1C,  0x00CA00BFU);
    DPU_LdWrite(ld, 0x3A20,  0x00B500AAU);
    DPU_LdWrite(ld, 0x3A24,  0x00A00096U);
    DPU_LdWrite(ld, 0x3A28,  0x008C0082U);
    DPU_LdWrite(ld, 0x3A2C,  0x00790070U);
    DPU_LdWrite(ld, 0x3A30,  0x0067005FU);
    DPU_LdWrite(ld, 0x3A34,  0x0057004FU);
    DPU_LdWrite(ld, 0x3A38,  0x00480042U);
    DPU_LdWrite(ld, 0x3A3C,  0x003B0035U);
    DPU_LdWrite(ld, 0x3A40,  0x0030002BU);
    DPU_LdWrite(ld, 0x3A44,  0x00260022U);
    DPU_LdWrite(ld, 0x3A48,  0x001E001BU);
    DPU_LdWrite(ld, 0x3A4C,  0x00180015U);
    DPU_LdWrite(ld, 0x3A50,  0x00120010U);
    DPU_LdWrite(ld, 0x3A54,  0x000E000CU);
    DPU_LdWrite(ld, 0x3A58,  0x000A0009U);
    DPU_LdWrite(ld, 0x3A5C,  0x00080006U);
    DPU_LdWrite(ld, 0x3A80,  0x01140113U);
    DPU_LdWrite(ld, 0x3A84,  0x0111010EU);
    DPU_LdWrite(ld, 0x3A88,  0x01090104U);
    DPU_LdWrite(ld, 0x3A8C,  0x00FE00F8U);
    DPU_LdWrite(ld, 0x3A90,  0x00F000E8U);
    DPU_LdWrite(ld, 0x3A94,  0x00E000D7U);
    DPU_LdWrite(ld, 0x3A98,  0x00CE00C5U);
    DPU_LdWrite(ld, 0x3A9C,  0x00BB00B2U);
    DPU_LdWrite(ld, 0x3AA0,  0x00A8009EU);
    DPU_LdWrite(ld, 0x3AA4,  0x0095008BU);
    DPU_LdWrite(ld, 0x3AA8,  0x00820079U);
    DPU_LdWrite(ld, 0x3AAC,  0x00710068U);
    DPU_LdWrite(ld, 0x3AB0,  0x00600058U);
    DPU_LdWrite(ld, 0x3AB4,  0x0051004AU);
    DPU_LdWrite(ld, 0x3AB8,  0x0043003DU);
    DPU_LdWrite(ld, 0x3ABC,  0x00370032U);
    DPU_LdWrite(ld, 0x3AC0,  0x002D0028U);
    DPU_LdWrite(ld, 0x3AC4,  0x00240020U);
    DPU_LdWrite(ld, 0x3AC8,  0x001C0019U);
    DPU_LdWrite(ld, 0x3ACC,  0x00160013U);
    DPU_LdWrite(ld, 0x3AD0,  0x0011000FU);
    DPU_LdWrite(ld, 0x3AD4,  0x000D000BU);
    DPU_LdWrite(ld, 0x3AD8,  0x000A0008U);
    DPU_LdWrite(ld, 0x3ADC,  0x00070006U);
    DPU_LdWrite(ld, 0x3B00,  0x00FD00FCU);
    DPU_LdWrite(ld, 0x3B04,  0x00FB00F8U);
    DPU_LdWrite(ld, 0x3B08,  0x00F400EFU);
    DPU_LdWrite(ld, 0x3B0C,  0x00EA00E4U);
    DPU_LdWrite(ld, 0x3B10,  0x00DE00D6U);
    DPU_LdWrite(ld, 0x3B14,  0x00CF00C7U);
    DPU_LdWrite(ld, 0x3B18,  0x00BF00B6U);
    DPU_LdWrite(ld, 0x3B1C,  0x00AD00A5U);
    DPU_LdWrite(ld, 0x3B20,  0x009C0093U);
    DPU_LdWrite(ld, 0x3B24,  0x008A0081U);
    DPU_LdWrite(ld, 0x3B28,  0x00790071U);
    DPU_LdWrite(ld, 0x3B2C,  0x00690061U);
    DPU_LdWrite(ld, 0x3B30,  0x00590052U);
    DPU_LdWrite(ld, 0x3B34,  0x004B0045U);
    DPU_LdWrite(ld, 0x3B38,  0x003F0039U);
    DPU_LdWrite(ld, 0x3B3C,  0x0033002EU);
    DPU_LdWrite(ld, 0x3B40,  0x002A0025U);
    DPU_LdWrite(ld, 0x3B44,  0x0021001EU);
    DPU_LdWrite(ld, 0x3B48,  0x001A0017U);
    DPU_LdWrite(ld, 0x3B4C,  0x00140012U);
    DPU_LdWrite(ld, 0x3B50,  0x0010000EU);
    DPU_LdWrite(ld, 0x3B54,  0x000C000AU);
    DPU_LdWrite(ld, 0x3B58,  0x00090008U);
    DPU_LdWrite(ld, 0x3B5C,  0x00070006U);
    DPU_LdWrite(ld, 0x3B80,  0x00E800E8U);
    DPU_LdWrite(ld, 0x3B84,  0x00E600E3U);
    DPU_LdWrite(ld, 0x3B88,  0x00E000DCU);
    DPU_LdWrite(ld, 0x3B8C,  0x00D700D2U);
    DPU_LdWrite(ld, 0x3B90,  0x00CC00C5U);
    DPU_LdWrite(ld, 0x3B94,  0x00BF00B7U);
    DPU_LdWrite(ld, 0x3B98,  0x00B000A8U);
    DPU_LdWrite(ld, 0x3B9C,  0x00A00098U);
    DPU_LdWrite(ld, 0x3BA0,  0x00900088U);
    DPU_LdWrite(ld, 0x3BA4,  0x00800078U);
    DPU_LdWrite(ld, 0x3BA8,  0x00700068U);
    DPU_LdWrite(ld, 0x3BAC,  0x0061005AU);
    DPU_LdWrite(ld, 0x3BB0,  0x0053004CU);
    DPU_LdWrite(ld, 0x3BB4,  0x00460040U);
    DPU_LdWrite(ld, 0x3BB8,  0x003A0035U);
    DPU_LdWrite(ld, 0x3BBC,  0x0030002BU);
    DPU_LdWrite(ld, 0x3BC0,  0x00260022U);
    DPU_LdWrite(ld, 0x3BC4,  0x001F001BU);
    DPU_LdWrite(ld, 0x3BC8,  0x00180015U);
    DPU_LdWrite(ld, 0x3BCC,  0x00130011U);
    DPU_LdWrite(ld, 0x3BD0,  0x000E000DU);
    DPU_LdWrite(ld, 0x3BD4,  0x000B0009U);
    DPU_LdWrite(ld, 0x3BD8,  0x00080007U);
    DPU_LdWrite(ld, 0x3BDC,  0x00060005U);
    DPU_LdWrite(ld, 0x3C00,  0x00D500D4U);
    DPU_LdWrite(ld, 0x3C04,  0x00D300D0U);
    DPU_LdWrite(ld, 0x3C08,  0x00CD00CAU);
    DPU_LdWrite(ld, 0x3C0C,  0x00C500C1U);
    DPU_LdWrite(ld, 0x3C10,  0x00BB00B5U);
    DPU_LdWrite(ld, 0x3C14,  0x00AF00A9U);
    DPU_LdWrite(ld, 0x3C18,  0x00A2009BU);
    DPU_LdWrite(ld, 0x3C1C,  0x0093008CU);
    DPU_LdWrite(ld, 0x3C20,  0x0085007DU);
    DPU_LdWrite(ld, 0x3C24,  0x0076006EU);
    DPU_LdWrite(ld, 0x3C28,  0x00670060U);
    DPU_LdWrite(ld, 0x3C2C,  0x00590053U);
    DPU_LdWrite(ld, 0x3C30,  0x004C0046U);
    DPU_LdWrite(ld, 0x3C34,  0x0040003BU);
    DPU_LdWrite(ld, 0x3C38,  0x00350030U);
    DPU_LdWrite(ld, 0x3C3C,  0x002C0028U);
    DPU_LdWrite(ld, 0x3C40,  0x00240020U);
    DPU_LdWrite(ld, 0x3C44,  0x001C0019U);
    DPU_LdWrite(ld, 0x3C48,  0x00160014U);
    DPU_LdWrite(ld, 0x3C4C,  0x0011000FU);
    DPU_LdWrite(ld, 0x3C50,  0x000D000CU);
    DPU_LdWrite(ld, 0x3C54,  0x000A0009U);
    DPU_LdWrite(ld, 0x3C58,  0x00080007U);
    DPU_LdWrite(ld, 0x3C5C,  0x00060005U);
    DPU_LdWrite(ld, 0x3C80,  0x00C300C2U);
    DPU_LdWrite(ld, 0x3C84,  0x00C100BFU);
    DPU_LdWrite(ld, 0x3C88,  0x00BC00B9U);
    DPU_LdWrite(ld, 0x3C8C,  0x00B500B0U);
    DPU_LdWrite(ld, 0x3C90,  0x00AC00A6U);
    DPU_LdWrite(ld, 0x3C94,  0x00A1009BU);
    DPU_LdWrite(ld, 0x3C98,  0x0094008EU);
    DPU_LdWrite(ld, 0x3C9C,  0x00870081U);
    DPU_LdWrite(ld, 0x3CA0,  0x007A0073U);
    DPU_LdWrite(ld, 0x3CA4,  0x006C0065U);
    DPU_LdWrite(ld, 0x3CA8,  0x005F0058U);
    DPU_LdWrite(ld, 0x3CAC,  0x0052004CU);
    DPU_LdWrite(ld, 0x3CB0,  0x00460040U);
    DPU_LdWrite(ld, 0x3CB4,  0x003B0036U);
    DPU_LdWrite(ld, 0x3CB8,  0x0031002DU);
    DPU_LdWrite(ld, 0x3CBC,  0x00280024U);
    DPU_LdWrite(ld, 0x3CC0,  0x0021001DU);
    DPU_LdWrite(ld, 0x3CC4,  0x001A0017U);
    DPU_LdWrite(ld, 0x3CC8,  0x00150012U);
    DPU_LdWrite(ld, 0x3CCC,  0x0010000EU);
    DPU_LdWrite(ld, 0x3CD0,  0x000C000BU);
    DPU_LdWrite(ld, 0x3CD4,  0x00090008U);
    DPU_LdWrite(ld, 0x3CD8,  0x00070006U);
    DPU_LdWrite(ld, 0x3CDC,  0x00050004U);
    DPU_LdWrite(ld, 0x3D00,  0x00B200B1U);
    DPU_LdWrite(ld, 0x3D04,  0x00B000AEU);
    DPU_LdWrite(ld, 0x3D08,  0x00AC00A9U);
    DPU_LdWrite(ld, 0x3D0C,  0x00A500A1U);
    DPU_LdWrite(ld, 0x3D10,  0x009D0098U);
    DPU_LdWrite(ld, 0x3D14,  0x0093008DU);
    DPU_LdWrite(ld, 0x3D18,  0x00880082U);
    DPU_LdWrite(ld, 0x3D1C,  0x007C0076U);
    DPU_LdWrite(ld, 0x3D20,  0x006F0069U);
    DPU_LdWrite(ld, 0x3D24,  0x0063005DU);
    DPU_LdWrite(ld, 0x3D28,  0x00570051U);
    DPU_LdWrite(ld, 0x3D2C,  0x004B0046U);
    DPU_LdWrite(ld, 0x3D30,  0x0040003BU);
    DPU_LdWrite(ld, 0x3D34,  0x00360031U);
    DPU_LdWrite(ld, 0x3D38,  0x002D0029U);
    DPU_LdWrite(ld, 0x3D3C,  0x00250021U);
    DPU_LdWrite(ld, 0x3D40,  0x001E001BU);
    DPU_LdWrite(ld, 0x3D44,  0x00180015U);
    DPU_LdWrite(ld, 0x3D48,  0x00130011U);
    DPU_LdWrite(ld, 0x3D4C,  0x000F000DU);
    DPU_LdWrite(ld, 0x3D50,  0x000B000AU);
    DPU_LdWrite(ld, 0x3D54,  0x00090007U);
    DPU_LdWrite(ld, 0x3D58,  0x00060005U);
    DPU_LdWrite(ld, 0x3D5C,  0x00050004U);
    DPU_LdWrite(ld, 0x3D80,  0x00A200A1U);
    DPU_LdWrite(ld, 0x3D84,  0x00A0009EU);
    DPU_LdWrite(ld, 0x3D88,  0x009C009AU);
    DPU_LdWrite(ld, 0x3D8C,  0x00960093U);
    DPU_LdWrite(ld, 0x3D90,  0x008F008BU);
    DPU_LdWrite(ld, 0x3D94,  0x00860081U);
    DPU_LdWrite(ld, 0x3D98,  0x007C0076U);
    DPU_LdWrite(ld, 0x3D9C,  0x0071006BU);
    DPU_LdWrite(ld, 0x3DA0,  0x00660060U);
    DPU_LdWrite(ld, 0x3DA4,  0x005A0055U);
    DPU_LdWrite(ld, 0x3DA8,  0x004F004AU);
    DPU_LdWrite(ld, 0x3DAC,  0x00450040U);
    DPU_LdWrite(ld, 0x3DB0,  0x003B0036U);
    DPU_LdWrite(ld, 0x3DB4,  0x0031002DU);
    DPU_LdWrite(ld, 0x3DB8,  0x00290025U);
    DPU_LdWrite(ld, 0x3DBC,  0x0022001EU);
    DPU_LdWrite(ld, 0x3DC0,  0x001B0018U);
    DPU_LdWrite(ld, 0x3DC4,  0x00160013U);
    DPU_LdWrite(ld, 0x3DC8,  0x0011000FU);
    DPU_LdWrite(ld, 0x3DCC,  0x000D000CU);
    DPU_LdWrite(ld, 0x3DD0,  0x000A0009U);
    DPU_LdWrite(ld, 0x3DD4,  0x00080007U);
    DPU_LdWrite(ld, 0x3DD8,  0x00060005U);
    DPU_LdWrite(ld, 0x3DDC,  0x00040004U);
    DPU_LdWrite(ld, 0x3E00,  0x00930092U);
    DPU_LdWrite(ld, 0x3E04,  0x00910090U);
    DPU_LdWrite(ld, 0x3E08,  0x008E008BU);
    DPU_LdWrite(ld, 0x3E0C,  0x00890085U);
    DPU_LdWrite(ld, 0x3E10,  0x0082007EU);
    DPU_LdWrite(ld, 0x3E14,  0x007A0075U);
    DPU_LdWrite(ld, 0x3E18,  0x0071006CU);
    DPU_LdWrite(ld, 0x3E1C,  0x00670062U);
    DPU_LdWrite(ld, 0x3E20,  0x005D0057U);
    DPU_LdWrite(ld, 0x3E24,  0x0052004DU);
    DPU_LdWrite(ld, 0x3E28,  0x00480043U);
    DPU_LdWrite(ld, 0x3E2C,  0x003F003AU);
    DPU_LdWrite(ld, 0x3E30,  0x00350031U);
    DPU_LdWrite(ld, 0x3E34,  0x002D0029U);
    DPU_LdWrite(ld, 0x3E38,  0x00250022U);
    DPU_LdWrite(ld, 0x3E3C,  0x001F001CU);
    DPU_LdWrite(ld, 0x3E40,  0x00190016U);
    DPU_LdWrite(ld, 0x3E44,  0x00140012U);
    DPU_LdWrite(ld, 0x3E48,  0x0010000EU);
    DPU_LdWrite(ld, 0x3E4C,  0x000C000BU);
    DPU_LdWrite(ld, 0x3E50,  0x00090008U);
    DPU_LdWrite(ld, 0x3E54,  0x00070006U);
    DPU_LdWrite(ld, 0x3E58,  0x00050005U);
    DPU_LdWrite(ld, 0x3E5C,  0x00040003U);
    DPU_LdWrite(ld, 0x3E80,  0x00850085U);
    DPU_LdWrite(ld, 0x3E84,  0x00840082U);
    DPU_LdWrite(ld, 0x3E88,  0x0081007EU);
    DPU_LdWrite(ld, 0x3E8C,  0x007C0079U);
    DPU_LdWrite(ld, 0x3E90,  0x00760072U);
    DPU_LdWrite(ld, 0x3E94,  0x006E006AU);
    DPU_LdWrite(ld, 0x3E98,  0x00660062U);
    DPU_LdWrite(ld, 0x3E9C,  0x005D0059U);
    DPU_LdWrite(ld, 0x3EA0,  0x0054004FU);
    DPU_LdWrite(ld, 0x3EA4,  0x004B0046U);
    DPU_LdWrite(ld, 0x3EA8,  0x0042003DU);
    DPU_LdWrite(ld, 0x3EAC,  0x00390035U);
    DPU_LdWrite(ld, 0x3EB0,  0x0030002DU);
    DPU_LdWrite(ld, 0x3EB4,  0x00290025U);
    DPU_LdWrite(ld, 0x3EB8,  0x0022001FU);
    DPU_LdWrite(ld, 0x3EBC,  0x001C0019U);
    DPU_LdWrite(ld, 0x3EC0,  0x00170014U);
    DPU_LdWrite(ld, 0x3EC4,  0x00120010U);
    DPU_LdWrite(ld, 0x3EC8,  0x000E000DU);
    DPU_LdWrite(ld, 0x3ECC,  0x000B000AU);
    DPU_LdWrite(ld, 0x3ED0,  0x00090007U);
    DPU_LdWrite(ld, 0x3ED4,  0x00060006U);
    DPU_LdWrite(ld, 0x3ED8,  0x00050004U);
    DPU_LdWrite(ld, 0x3EDC,  0x00040003U);
    DPU_LdWrite(ld, 0x3F00,  0x00780078U);
    DPU_LdWrite(ld, 0x3F04,  0x00770076U);
    DPU_LdWrite(ld, 0x3F08,  0x00740072U);
    DPU_LdWrite(ld, 0x3F0C,  0x0070006DU);
    DPU_LdWrite(ld, 0x3F10,  0x006A0067U);
    DPU_LdWrite(ld, 0x3F14,  0x00640060U);
    DPU_LdWrite(ld, 0x3F18,  0x005C0058U);
    DPU_LdWrite(ld, 0x3F1C,  0x00540050U);
    DPU_LdWrite(ld, 0x3F20,  0x004C0048U);
    DPU_LdWrite(ld, 0x3F24,  0x0044003FU);
    DPU_LdWrite(ld, 0x3F28,  0x003B0037U);
    DPU_LdWrite(ld, 0x3F2C,  0x00330030U);
    DPU_LdWrite(ld, 0x3F30,  0x002C0028U);
    DPU_LdWrite(ld, 0x3F34,  0x00250022U);
    DPU_LdWrite(ld, 0x3F38,  0x001F001CU);
    DPU_LdWrite(ld, 0x3F3C,  0x00190017U);
    DPU_LdWrite(ld, 0x3F40,  0x00140012U);
    DPU_LdWrite(ld, 0x3F44,  0x0010000FU);
    DPU_LdWrite(ld, 0x3F48,  0x000D000BU);
    DPU_LdWrite(ld, 0x3F4C,  0x000A0009U);
    DPU_LdWrite(ld, 0x3F50,  0x00080007U);
    DPU_LdWrite(ld, 0x3F54,  0x00060005U);
    DPU_LdWrite(ld, 0x3F58,  0x00040004U);
    DPU_LdWrite(ld, 0x3F5C,  0x00030003U);
    DPU_LdWrite(ld, 0x3F80,  0x006C006CU);
    DPU_LdWrite(ld, 0x3F84,  0x006B006AU);
    DPU_LdWrite(ld, 0x3F88,  0x00690067U);
    DPU_LdWrite(ld, 0x3F8C,  0x00650062U);
    DPU_LdWrite(ld, 0x3F90,  0x0060005DU);
    DPU_LdWrite(ld, 0x3F94,  0x005A0057U);
    DPU_LdWrite(ld, 0x3F98,  0x00530050U);
    DPU_LdWrite(ld, 0x3F9C,  0x004C0048U);
    DPU_LdWrite(ld, 0x3FA0,  0x00440041U);
    DPU_LdWrite(ld, 0x3FA4,  0x003D0039U);
    DPU_LdWrite(ld, 0x3FA8,  0x00350032U);
    DPU_LdWrite(ld, 0x3FAC,  0x002E002BU);
    DPU_LdWrite(ld, 0x3FB0,  0x00280024U);
    DPU_LdWrite(ld, 0x3FB4,  0x0021001EU);
    DPU_LdWrite(ld, 0x3FB8,  0x001C0019U);
    DPU_LdWrite(ld, 0x3FBC,  0x00170015U);
    DPU_LdWrite(ld, 0x3FC0,  0x00120011U);
    DPU_LdWrite(ld, 0x3FC4,  0x000F000DU);
    DPU_LdWrite(ld, 0x3FC8,  0x000C000AU);
    DPU_LdWrite(ld, 0x3FCC,  0x00090008U);
    DPU_LdWrite(ld, 0x3FD0,  0x00070006U);
    DPU_LdWrite(ld, 0x3FD4,  0x00050005U);
    DPU_LdWrite(ld, 0x3FD8,  0x00040003U);
    DPU_LdWrite(ld, 0x3FDC,  0x00030002U);
    DPU_LdWrite(ld, 0x4000,  0x00610061U);
    DPU_LdWrite(ld, 0x4004,  0x0060005FU);
    DPU_LdWrite(ld, 0x4008,  0x005E005CU);
    DPU_LdWrite(ld, 0x400C,  0x005A0058U);
    DPU_LdWrite(ld, 0x4010,  0x00560053U);
    DPU_LdWrite(ld, 0x4014,  0x0051004EU);
    DPU_LdWrite(ld, 0x4018,  0x004B0048U);
    DPU_LdWrite(ld, 0x401C,  0x00440041U);
    DPU_LdWrite(ld, 0x4020,  0x003E003AU);
    DPU_LdWrite(ld, 0x4024,  0x00370033U);
    DPU_LdWrite(ld, 0x4028,  0x0030002DU);
    DPU_LdWrite(ld, 0x402C,  0x002A0026U);
    DPU_LdWrite(ld, 0x4030,  0x00240021U);
    DPU_LdWrite(ld, 0x4034,  0x001E001BU);
    DPU_LdWrite(ld, 0x4038,  0x00190017U);
    DPU_LdWrite(ld, 0x403C,  0x00140012U);
    DPU_LdWrite(ld, 0x4040,  0x0011000FU);
    DPU_LdWrite(ld, 0x4044,  0x000D000CU);
    DPU_LdWrite(ld, 0x4048,  0x000A0009U);
    DPU_LdWrite(ld, 0x404C,  0x00080007U);
    DPU_LdWrite(ld, 0x4050,  0x00060005U);
    DPU_LdWrite(ld, 0x4054,  0x00050004U);
    DPU_LdWrite(ld, 0x4058,  0x00040003U);
    DPU_LdWrite(ld, 0x405C,  0x00030002U);
    DPU_LdWrite(ld, 0x4080,  0x00570057U);
    DPU_LdWrite(ld, 0x4084,  0x00560055U);
    DPU_LdWrite(ld, 0x4088,  0x00540053U);
    DPU_LdWrite(ld, 0x408C,  0x0051004FU);
    DPU_LdWrite(ld, 0x4090,  0x004D004BU);
    DPU_LdWrite(ld, 0x4094,  0x00480046U);
    DPU_LdWrite(ld, 0x4098,  0x00430040U);
    DPU_LdWrite(ld, 0x409C,  0x003D003AU);
    DPU_LdWrite(ld, 0x40A0,  0x00370034U);
    DPU_LdWrite(ld, 0x40A4,  0x0031002EU);
    DPU_LdWrite(ld, 0x40A8,  0x002B0028U);
    DPU_LdWrite(ld, 0x40AC,  0x00250022U);
    DPU_LdWrite(ld, 0x40B0,  0x0020001DU);
    DPU_LdWrite(ld, 0x40B4,  0x001B0018U);
    DPU_LdWrite(ld, 0x40B8,  0x00160014U);
    DPU_LdWrite(ld, 0x40BC,  0x00120011U);
    DPU_LdWrite(ld, 0x40C0,  0x000F000DU);
    DPU_LdWrite(ld, 0x40C4,  0x000C000BU);
    DPU_LdWrite(ld, 0x40C8,  0x00090008U);
    DPU_LdWrite(ld, 0x40CC,  0x00070006U);
    DPU_LdWrite(ld, 0x40D0,  0x00060005U);
    DPU_LdWrite(ld, 0x40D4,  0x00040004U);
    DPU_LdWrite(ld, 0x40D8,  0x00030003U);
    DPU_LdWrite(ld, 0x40DC,  0x00020002U);
    DPU_LdWrite(ld, 0x4100,  0x004E004DU);
    DPU_LdWrite(ld, 0x4104,  0x004D004CU);
    DPU_LdWrite(ld, 0x4108,  0x004B004AU);
    DPU_LdWrite(ld, 0x410C,  0x00480047U);
    DPU_LdWrite(ld, 0x4110,  0x00450043U);
    DPU_LdWrite(ld, 0x4114,  0x0040003EU);
    DPU_LdWrite(ld, 0x4118,  0x003C0039U);
    DPU_LdWrite(ld, 0x411C,  0x00370034U);
    DPU_LdWrite(ld, 0x4120,  0x0031002EU);
    DPU_LdWrite(ld, 0x4124,  0x002C0029U);
    DPU_LdWrite(ld, 0x4128,  0x00260024U);
    DPU_LdWrite(ld, 0x412C,  0x0021001FU);
    DPU_LdWrite(ld, 0x4130,  0x001C001AU);
    DPU_LdWrite(ld, 0x4134,  0x00180016U);
    DPU_LdWrite(ld, 0x4138,  0x00140012U);
    DPU_LdWrite(ld, 0x413C,  0x0010000FU);
    DPU_LdWrite(ld, 0x4140,  0x000D000CU);
    DPU_LdWrite(ld, 0x4144,  0x000B0009U);
    DPU_LdWrite(ld, 0x4148,  0x00080007U);
    DPU_LdWrite(ld, 0x414C,  0x00060006U);
    DPU_LdWrite(ld, 0x4150,  0x00050004U);
    DPU_LdWrite(ld, 0x4154,  0x00040003U);
    DPU_LdWrite(ld, 0x4158,  0x00030002U);
    DPU_LdWrite(ld, 0x415C,  0x00020002U);
    DPU_LdWrite(ld, 0x4180,  0x00450045U);
    DPU_LdWrite(ld, 0x4184,  0x00440044U);
    DPU_LdWrite(ld, 0x4188,  0x00430042U);
    DPU_LdWrite(ld, 0x418C,  0x0040003FU);
    DPU_LdWrite(ld, 0x4190,  0x003D003BU);
    DPU_LdWrite(ld, 0x4194,  0x00390037U);
    DPU_LdWrite(ld, 0x4198,  0x00350033U);
    DPU_LdWrite(ld, 0x419C,  0x0030002EU);
    DPU_LdWrite(ld, 0x41A0,  0x002C0029U);
    DPU_LdWrite(ld, 0x41A4,  0x00270024U);
    DPU_LdWrite(ld, 0x41A8,  0x00220020U);
    DPU_LdWrite(ld, 0x41AC,  0x001E001BU);
    DPU_LdWrite(ld, 0x41B0,  0x00190017U);
    DPU_LdWrite(ld, 0x41B4,  0x00150013U);
    DPU_LdWrite(ld, 0x41B8,  0x00120010U);
    DPU_LdWrite(ld, 0x41BC,  0x000F000DU);
    DPU_LdWrite(ld, 0x41C0,  0x000C000BU);
    DPU_LdWrite(ld, 0x41C4,  0x00090008U);
    DPU_LdWrite(ld, 0x41C8,  0x00070007U);
    DPU_LdWrite(ld, 0x41CC,  0x00060005U);
    DPU_LdWrite(ld, 0x41D0,  0x00040004U);
    DPU_LdWrite(ld, 0x41D4,  0x00030003U);
    DPU_LdWrite(ld, 0x41D8,  0x00030002U);
    DPU_LdWrite(ld, 0x41DC,  0x00020002U);
    DPU_LdWrite(ld, 0x4200,  0x003D003DU);
    DPU_LdWrite(ld, 0x4204,  0x003C003CU);
    DPU_LdWrite(ld, 0x4208,  0x003B003AU);
    DPU_LdWrite(ld, 0x420C,  0x00390038U);
    DPU_LdWrite(ld, 0x4210,  0x00360035U);
    DPU_LdWrite(ld, 0x4214,  0x00330031U);
    DPU_LdWrite(ld, 0x4218,  0x002F002DU);
    DPU_LdWrite(ld, 0x421C,  0x002B0029U);
    DPU_LdWrite(ld, 0x4220,  0x00270025U);
    DPU_LdWrite(ld, 0x4224,  0x00220020U);
    DPU_LdWrite(ld, 0x4228,  0x001E001CU);
    DPU_LdWrite(ld, 0x422C,  0x001A0018U);
    DPU_LdWrite(ld, 0x4230,  0x00160015U);
    DPU_LdWrite(ld, 0x4234,  0x00130011U);
    DPU_LdWrite(ld, 0x4238,  0x0010000EU);
    DPU_LdWrite(ld, 0x423C,  0x000D000CU);
    DPU_LdWrite(ld, 0x4240,  0x000A0009U);
    DPU_LdWrite(ld, 0x4244,  0x00080007U);
    DPU_LdWrite(ld, 0x4248,  0x00070006U);
    DPU_LdWrite(ld, 0x424C,  0x00050004U);
    DPU_LdWrite(ld, 0x4250,  0x00040003U);
    DPU_LdWrite(ld, 0x4254,  0x00030003U);
    DPU_LdWrite(ld, 0x4258,  0x00020002U);
    DPU_LdWrite(ld, 0x425C,  0x00020001U);
    DPU_LdWrite(ld, 0x4280,  0x00360036U);
    DPU_LdWrite(ld, 0x4284,  0x00350035U);
    DPU_LdWrite(ld, 0x4288,  0x00340033U);
    DPU_LdWrite(ld, 0x428C,  0x00320031U);
    DPU_LdWrite(ld, 0x4290,  0x0030002EU);
    DPU_LdWrite(ld, 0x4294,  0x002D002BU);
    DPU_LdWrite(ld, 0x4298,  0x002A0028U);
    DPU_LdWrite(ld, 0x429C,  0x00260024U);
    DPU_LdWrite(ld, 0x42A0,  0x00220020U);
    DPU_LdWrite(ld, 0x42A4,  0x001E001DU);
    DPU_LdWrite(ld, 0x42A8,  0x001B0019U);
    DPU_LdWrite(ld, 0x42AC,  0x00170015U);
    DPU_LdWrite(ld, 0x42B0,  0x00140012U);
    DPU_LdWrite(ld, 0x42B4,  0x0011000FU);
    DPU_LdWrite(ld, 0x42B8,  0x000E000DU);
    DPU_LdWrite(ld, 0x42BC,  0x000B000AU);
    DPU_LdWrite(ld, 0x42C0,  0x00090008U);
    DPU_LdWrite(ld, 0x42C4,  0x00070007U);
    DPU_LdWrite(ld, 0x42C8,  0x00060005U);
    DPU_LdWrite(ld, 0x42CC,  0x00050004U);
    DPU_LdWrite(ld, 0x42D0,  0x00030003U);
    DPU_LdWrite(ld, 0x42D4,  0x00030002U);
    DPU_LdWrite(ld, 0x42D8,  0x00020002U);
    DPU_LdWrite(ld, 0x42DC,  0x00010001U);
    DPU_LdWrite(ld, 0x4300,  0x0030002FU);
    DPU_LdWrite(ld, 0x4304,  0x002F002FU);
    DPU_LdWrite(ld, 0x4308,  0x002E002DU);
    DPU_LdWrite(ld, 0x430C,  0x002C002BU);
    DPU_LdWrite(ld, 0x4310,  0x002A0029U);
    DPU_LdWrite(ld, 0x4314,  0x00280026U);
    DPU_LdWrite(ld, 0x4318,  0x00250023U);
    DPU_LdWrite(ld, 0x431C,  0x00210020U);
    DPU_LdWrite(ld, 0x4320,  0x001E001CU);
    DPU_LdWrite(ld, 0x4324,  0x001B0019U);
    DPU_LdWrite(ld, 0x4328,  0x00180016U);
    DPU_LdWrite(ld, 0x432C,  0x00140013U);
    DPU_LdWrite(ld, 0x4330,  0x00110010U);
    DPU_LdWrite(ld, 0x4334,  0x000F000DU);
    DPU_LdWrite(ld, 0x4338,  0x000C000BU);
    DPU_LdWrite(ld, 0x433C,  0x000A0009U);
    DPU_LdWrite(ld, 0x4340,  0x00080007U);
    DPU_LdWrite(ld, 0x4344,  0x00060006U);
    DPU_LdWrite(ld, 0x4348,  0x00050005U);
    DPU_LdWrite(ld, 0x434C,  0x00040003U);
    DPU_LdWrite(ld, 0x4350,  0x00030003U);
    DPU_LdWrite(ld, 0x4354,  0x00020002U);
    DPU_LdWrite(ld, 0x4358,  0x00020001U);
    DPU_LdWrite(ld, 0x435C,  0x00010001U);
    DPU_LdWrite(ld, 0x4380,  0x002A002AU);
    DPU_LdWrite(ld, 0x4384,  0x00290029U);
    DPU_LdWrite(ld, 0x4388,  0x00280028U);
    DPU_LdWrite(ld, 0x438C,  0x00270026U);
    DPU_LdWrite(ld, 0x4390,  0x00250024U);
    DPU_LdWrite(ld, 0x4394,  0x00230021U);
    DPU_LdWrite(ld, 0x4398,  0x0020001FU);
    DPU_LdWrite(ld, 0x439C,  0x001D001CU);
    DPU_LdWrite(ld, 0x43A0,  0x001A0019U);
    DPU_LdWrite(ld, 0x43A4,  0x00180016U);
    DPU_LdWrite(ld, 0x43A8,  0x00150013U);
    DPU_LdWrite(ld, 0x43AC,  0x00120011U);
    DPU_LdWrite(ld, 0x43B0,  0x000F000EU);
    DPU_LdWrite(ld, 0x43B4,  0x000D000CU);
    DPU_LdWrite(ld, 0x43B8,  0x000B000AU);
    DPU_LdWrite(ld, 0x43BC,  0x00090008U);
    DPU_LdWrite(ld, 0x43C0,  0x00070006U);
    DPU_LdWrite(ld, 0x43C4,  0x00060005U);
    DPU_LdWrite(ld, 0x43C8,  0x00040004U);
    DPU_LdWrite(ld, 0x43CC,  0x00030003U);
    DPU_LdWrite(ld, 0x43D0,  0x00030002U);
    DPU_LdWrite(ld, 0x43D4,  0x00020002U);
    DPU_LdWrite(ld, 0x43D8,  0x00020001U);
    DPU_LdWrite(ld, 0x43DC,  0x00010001U);
    DPU_LdWrite(ld, 0x4400,  0x00240024U);
    DPU_LdWrite(ld, 0x4404,  0x00240024U);
    DPU_LdWrite(ld, 0x4408,  0x00230023U);
    DPU_LdWrite(ld, 0x440C,  0x00220021U);
    DPU_LdWrite(ld, 0x4410,  0x0020001FU);
    DPU_LdWrite(ld, 0x4414,  0x001E001DU);
    DPU_LdWrite(ld, 0x4418,  0x001C001BU);
    DPU_LdWrite(ld, 0x441C,  0x001A0018U);
    DPU_LdWrite(ld, 0x4420,  0x00170016U);
    DPU_LdWrite(ld, 0x4424,  0x00150013U);
    DPU_LdWrite(ld, 0x4428,  0x00120011U);
    DPU_LdWrite(ld, 0x442C,  0x0010000EU);
    DPU_LdWrite(ld, 0x4430,  0x000D000CU);
    DPU_LdWrite(ld, 0x4434,  0x000B000AU);
    DPU_LdWrite(ld, 0x4438,  0x00090009U);
    DPU_LdWrite(ld, 0x443C,  0x00080007U);
    DPU_LdWrite(ld, 0x4440,  0x00060006U);
    DPU_LdWrite(ld, 0x4444,  0x00050004U);
    DPU_LdWrite(ld, 0x4448,  0x00040003U);
    DPU_LdWrite(ld, 0x444C,  0x00030003U);
    DPU_LdWrite(ld, 0x4450,  0x00020002U);
    DPU_LdWrite(ld, 0x4454,  0x00020002U);
    DPU_LdWrite(ld, 0x4458,  0x00010001U);
    DPU_LdWrite(ld, 0x445C,  0x00010001U);
    DPU_LdWrite(ld, 0x4480,  0x00200020U);
    DPU_LdWrite(ld, 0x4484,  0x001F001FU);
    DPU_LdWrite(ld, 0x4488,  0x001F001EU);
    DPU_LdWrite(ld, 0x448C,  0x001E001DU);
    DPU_LdWrite(ld, 0x4490,  0x001C001BU);
    DPU_LdWrite(ld, 0x4494,  0x001A0019U);
    DPU_LdWrite(ld, 0x4498,  0x00180017U);
    DPU_LdWrite(ld, 0x449C,  0x00160015U);
    DPU_LdWrite(ld, 0x44A0,  0x00140013U);
    DPU_LdWrite(ld, 0x44A4,  0x00120011U);
    DPU_LdWrite(ld, 0x44A8,  0x0010000FU);
    DPU_LdWrite(ld, 0x44AC,  0x000E000DU);
    DPU_LdWrite(ld, 0x44B0,  0x000C000BU);
    DPU_LdWrite(ld, 0x44B4,  0x000A0009U);
    DPU_LdWrite(ld, 0x44B8,  0x00080007U);
    DPU_LdWrite(ld, 0x44BC,  0x00070006U);
    DPU_LdWrite(ld, 0x44C0,  0x00050005U);
    DPU_LdWrite(ld, 0x44C4,  0x00040004U);
    DPU_LdWrite(ld, 0x44C8,  0x00030003U);
    DPU_LdWrite(ld, 0x44CC,  0x00030002U);
    DPU_LdWrite(ld, 0x44D0,  0x00020002U);
    DPU_LdWrite(ld, 0x44D4,  0x00020001U);
    DPU_LdWrite(ld, 0x44D8,  0x00010001U);
    DPU_LdWrite(ld, 0x44DC,  0x00010001U);
    DPU_LdWrite(ld, 0x4500,  0x001C001CU);
    DPU_LdWrite(ld, 0x4504,  0x001B001BU);
    DPU_LdWrite(ld, 0x4508,  0x001B001AU);
    DPU_LdWrite(ld, 0x450C,  0x001A0019U);
    DPU_LdWrite(ld, 0x4510,  0x00180018U);
    DPU_LdWrite(ld, 0x4514,  0x00170016U);
    DPU_LdWrite(ld, 0x4518,  0x00150014U);
    DPU_LdWrite(ld, 0x451C,  0x00130012U);
    DPU_LdWrite(ld, 0x4520,  0x00120011U);
    DPU_LdWrite(ld, 0x4524,  0x0010000FU);
    DPU_LdWrite(ld, 0x4528,  0x000E000DU);
    DPU_LdWrite(ld, 0x452C,  0x000C000BU);
    DPU_LdWrite(ld, 0x4530,  0x000A0009U);
    DPU_LdWrite(ld, 0x4534,  0x00090008U);
    DPU_LdWrite(ld, 0x4538,  0x00070006U);
    DPU_LdWrite(ld, 0x453C,  0x00060005U);
    DPU_LdWrite(ld, 0x4540,  0x00050004U);
    DPU_LdWrite(ld, 0x4544,  0x00040003U);
    DPU_LdWrite(ld, 0x4548,  0x00030003U);
    DPU_LdWrite(ld, 0x454C,  0x00020002U);
    DPU_LdWrite(ld, 0x4550,  0x00020002U);
    DPU_LdWrite(ld, 0x4554,  0x00010001U);
    DPU_LdWrite(ld, 0x4558,  0x00010001U);
    DPU_LdWrite(ld, 0x455C,  0x00010001U);
    DPU_LdWrite(ld, 0x4580,  0x00180018U);
    DPU_LdWrite(ld, 0x4584,  0x00180017U);
    DPU_LdWrite(ld, 0x4588,  0x00170017U);
    DPU_LdWrite(ld, 0x458C,  0x00160016U);
    DPU_LdWrite(ld, 0x4590,  0x00150015U);
    DPU_LdWrite(ld, 0x4594,  0x00140013U);
    DPU_LdWrite(ld, 0x4598,  0x00120012U);
    DPU_LdWrite(ld, 0x459C,  0x00110010U);
    DPU_LdWrite(ld, 0x45A0,  0x000F000EU);
    DPU_LdWrite(ld, 0x45A4,  0x000D000DU);
    DPU_LdWrite(ld, 0x45A8,  0x000C000BU);
    DPU_LdWrite(ld, 0x45AC,  0x000A0009U);
    DPU_LdWrite(ld, 0x45B0,  0x00090008U);
    DPU_LdWrite(ld, 0x45B4,  0x00070007U);
    DPU_LdWrite(ld, 0x45B8,  0x00060006U);
    DPU_LdWrite(ld, 0x45BC,  0x00050005U);
    DPU_LdWrite(ld, 0x45C0,  0x00040004U);
    DPU_LdWrite(ld, 0x45C4,  0x00030003U);
    DPU_LdWrite(ld, 0x45C8,  0x00030002U);
    DPU_LdWrite(ld, 0x45CC,  0x00020002U);
    DPU_LdWrite(ld, 0x45D0,  0x00020001U);
    DPU_LdWrite(ld, 0x45D4,  0x00010001U);
    DPU_LdWrite(ld, 0x45D8,  0x00010001U);
    DPU_LdWrite(ld, 0x45DC,  0x00010001U);
    DPU_LdWrite(ld, 0x4600,  0x00150015U);
    DPU_LdWrite(ld, 0x4604,  0x00140014U);
    DPU_LdWrite(ld, 0x4608,  0x00140014U);
    DPU_LdWrite(ld, 0x460C,  0x00130013U);
    DPU_LdWrite(ld, 0x4610,  0x00120012U);
    DPU_LdWrite(ld, 0x4614,  0x00110011U);
    DPU_LdWrite(ld, 0x4618,  0x0010000FU);
    DPU_LdWrite(ld, 0x461C,  0x000F000EU);
    DPU_LdWrite(ld, 0x4620,  0x000D000CU);
    DPU_LdWrite(ld, 0x4624,  0x000C000BU);
    DPU_LdWrite(ld, 0x4628,  0x000A000AU);
    DPU_LdWrite(ld, 0x462C,  0x00090008U);
    DPU_LdWrite(ld, 0x4630,  0x00080007U);
    DPU_LdWrite(ld, 0x4634,  0x00060006U);
    DPU_LdWrite(ld, 0x4638,  0x00050005U);
    DPU_LdWrite(ld, 0x463C,  0x00040004U);
    DPU_LdWrite(ld, 0x4640,  0x00040003U);
    DPU_LdWrite(ld, 0x4644,  0x00030003U);
    DPU_LdWrite(ld, 0x4648,  0x00020002U);
    DPU_LdWrite(ld, 0x464C,  0x00020002U);
    DPU_LdWrite(ld, 0x4650,  0x00010001U);
    DPU_LdWrite(ld, 0x4654,  0x00010001U);
    DPU_LdWrite(ld, 0x4658,  0x00010001U);
    DPU_LdWrite(ld, 0x465C,  0x00010000U);
    DPU_LdWrite(ld, 0x4680,  0x00120012U);
    DPU_LdWrite(ld, 0x4684,  0x00120011U);
    DPU_LdWrite(ld, 0x4688,  0x00110011U);
    DPU_LdWrite(ld, 0x468C,  0x00110010U);
    DPU_LdWrite(ld, 0x4690,  0x0010000FU);
    DPU_LdWrite(ld, 0x4694,  0x000F000EU);
    DPU_LdWrite(ld, 0x4698,  0x000E000DU);
    DPU_LdWrite(ld, 0x469C,  0x000C000CU);
    DPU_LdWrite(ld, 0x46A0,  0x000B000BU);
    DPU_LdWrite(ld, 0x46A4,  0x000A0009U);
    DPU_LdWrite(ld, 0x46A8,  0x00090008U);
    DPU_LdWrite(ld, 0x46AC,  0x00080007U);
    DPU_LdWrite(ld, 0x46B0,  0x00070006U);
    DPU_LdWrite(ld, 0x46B4,  0x00050005U);
    DPU_LdWrite(ld, 0x46B8,  0x00050004U);
    DPU_LdWrite(ld, 0x46BC,  0x00040003U);
    DPU_LdWrite(ld, 0x46C0,  0x00030003U);
    DPU_LdWrite(ld, 0x46C4,  0x00020002U);
    DPU_LdWrite(ld, 0x46C8,  0x00020002U);
    DPU_LdWrite(ld, 0x46CC,  0x00010001U);
    DPU_LdWrite(ld, 0x46D0,  0x00010001U);
    DPU_LdWrite(ld, 0x46D4,  0x00010001U);
    DPU_LdWrite(ld, 0x46D8,  0x00010001U);
    DPU_LdWrite(ld, 0x46DC,  0x00000000U);
    DPU_LdWrite(ld, 0x4700,  0x000F000FU);
    DPU_LdWrite(ld, 0x4704,  0x000F000FU);
    DPU_LdWrite(ld, 0x4708,  0x000F000EU);
    DPU_LdWrite(ld, 0x470C,  0x000E000EU);
    DPU_LdWrite(ld, 0x4710,  0x000D000DU);
    DPU_LdWrite(ld, 0x4714,  0x000D000CU);
    DPU_LdWrite(ld, 0x4718,  0x000C000BU);
    DPU_LdWrite(ld, 0x471C,  0x000B000AU);
    DPU_LdWrite(ld, 0x4720,  0x000A0009U);
    DPU_LdWrite(ld, 0x4724,  0x00090008U);
    DPU_LdWrite(ld, 0x4728,  0x00080007U);
    DPU_LdWrite(ld, 0x472C,  0x00070006U);
    DPU_LdWrite(ld, 0x4730,  0x00060005U);
    DPU_LdWrite(ld, 0x4734,  0x00050004U);
    DPU_LdWrite(ld, 0x4738,  0x00040004U);
    DPU_LdWrite(ld, 0x473C,  0x00030003U);
    DPU_LdWrite(ld, 0x4740,  0x00030002U);
    DPU_LdWrite(ld, 0x4744,  0x00020002U);
    DPU_LdWrite(ld, 0x4748,  0x00020001U);
    DPU_LdWrite(ld, 0x474C,  0x00010001U);
    DPU_LdWrite(ld, 0x4750,  0x00010001U);
    DPU_LdWrite(ld, 0x4754,  0x00010001U);
    DPU_LdWrite(ld, 0x4758,  0x00010000U);
    DPU_LdWrite(ld, 0x475C,  0x00000000U);
    DPU_LdWrite(ld, 0x4780,  0x000D000DU);
    DPU_LdWrite(ld, 0x4784,  0x000D000DU);
    DPU_LdWrite(ld, 0x4788,  0x000D000CU);
    DPU_LdWrite(ld, 0x478C,  0x000C000CU);
    DPU_LdWrite(ld, 0x4790,  0x000C000BU);
    DPU_LdWrite(ld, 0x4794,  0x000B000AU);
    DPU_LdWrite(ld, 0x4798,  0x000A000AU);
    DPU_LdWrite(ld, 0x479C,  0x00090009U);
    DPU_LdWrite(ld, 0x47A0,  0x00080008U);
    DPU_LdWrite(ld, 0x47A4,  0x00070007U);
    DPU_LdWrite(ld, 0x47A8,  0x00060006U);
    DPU_LdWrite(ld, 0x47AC,  0x00060005U);
    DPU_LdWrite(ld, 0x47B0,  0x00050004U);
    DPU_LdWrite(ld, 0x47B4,  0x00040004U);
    DPU_LdWrite(ld, 0x47B8,  0x00030003U);
    DPU_LdWrite(ld, 0x47BC,  0x00030002U);
    DPU_LdWrite(ld, 0x47C0,  0x00020002U);
    DPU_LdWrite(ld, 0x47C4,  0x00020002U);
    DPU_LdWrite(ld, 0x47C8,  0x00010001U);
    DPU_LdWrite(ld, 0x47CC,  0x00010001U);
    DPU_LdWrite(ld, 0x47D0,  0x00010001U);
    DPU_LdWrite(ld, 0x47D4,  0x00010001U);
    DPU_LdWrite(ld, 0x47D8,  0x00000000U);
    DPU_LdWrite(ld, 0x47DC,  0x00000000U);
    DPU_LdWrite(ld, 0x5000,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5004,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5008,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x500C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5010,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5014,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5018,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x501C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5020,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5024,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5028,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x502C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5030,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5034,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5038,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x503C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5040,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5044,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5048,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x504C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5050,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5054,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5058,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x505C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5060,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5064,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5068,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x506C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5070,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5074,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5078,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x507C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5080,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5084,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5088,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x508C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5090,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5094,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5098,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x509C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50A0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50A4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50A8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50AC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50B0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50B4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50B8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50BC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50C0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50C4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50C8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50CC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50D0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50D4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50D8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50DC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50E0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50E4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50E8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50EC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50F0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50F4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50F8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x50FC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5100,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5104,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5108,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x510C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5110,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5114,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5118,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x511C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5120,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5124,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5128,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x512C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5130,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5134,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5138,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x513C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5140,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5144,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5148,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x514C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5150,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5154,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5158,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x515C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5160,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5164,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5168,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x516C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5170,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5174,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5178,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x517C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5180,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5184,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5188,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x518C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5190,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5194,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5198,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x519C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51A0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51A4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51A8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51AC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51B0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51B4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51B8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51BC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51C0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51C4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51C8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51CC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51D0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51D4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51D8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51DC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51E0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51E4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51E8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51EC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51F0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51F4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51F8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x51FC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5200,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5204,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5208,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x520C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5210,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5214,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5218,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x521C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5220,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5224,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5228,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x522C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5230,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5234,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5238,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x523C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5240,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5244,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5248,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x524C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5250,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5254,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5258,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x525C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5260,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5264,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5268,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x526C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5270,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5274,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5278,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x527C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5280,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5284,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5288,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x528C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5290,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5294,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5298,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x529C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52A0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52A4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52A8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52AC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52B0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52B4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52B8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52BC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52C0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52C4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52C8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52CC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52D0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52D4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52D8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52DC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52E0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52E4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52E8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52EC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52F0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52F4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52F8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x52FC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5300,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5304,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5308,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x530C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5310,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5314,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5318,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x531C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5320,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5324,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5328,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x532C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5330,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5334,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5338,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x533C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5340,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5344,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5348,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x534C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5350,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5354,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5358,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x535C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5360,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5364,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5368,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x536C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5370,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5374,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5378,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x537C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5380,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5384,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5388,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x538C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5390,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5394,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x5398,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x539C,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53A0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53A4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53A8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53AC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53B0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53B4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53B8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53BC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53C0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53C4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53C8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53CC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53D0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53D4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53D8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53DC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53E0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53E4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53E8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53EC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53F0,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53F4,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53F8,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x53FC,  0x0FFF0FFFU);
    DPU_LdWrite(ld, 0x6000,  0x08000800U);
    DPU_LdWrite(ld, 0x6004,  0x08000800U);
    DPU_LdWrite(ld, 0x6008,  0x08000800U);
    DPU_LdWrite(ld, 0x600C,  0x08000800U);
    DPU_LdWrite(ld, 0x6010,  0x08000800U);
    DPU_LdWrite(ld, 0x6014,  0x08000800U);
    DPU_LdWrite(ld, 0x6018,  0x08000800U);
    DPU_LdWrite(ld, 0x601C,  0x08000800U);
    DPU_LdWrite(ld, 0x6020,  0x08000800U);
    DPU_LdWrite(ld, 0x6024,  0x08000800U);
    DPU_LdWrite(ld, 0x6028,  0x08000800U);
    DPU_LdWrite(ld, 0x602C,  0x08000800U);
    DPU_LdWrite(ld, 0x6030,  0x08000800U);
    DPU_LdWrite(ld, 0x6034,  0x08000800U);
    DPU_LdWrite(ld, 0x6038,  0x08000800U);
    DPU_LdWrite(ld, 0x603C,  0x08000800U);
    DPU_LdWrite(ld, 0x6040,  0x08000800U);
    DPU_LdWrite(ld, 0x6044,  0x08000800U);
    DPU_LdWrite(ld, 0x6048,  0x08000800U);
    DPU_LdWrite(ld, 0x604C,  0x08000800U);
    DPU_LdWrite(ld, 0x6050,  0x08000800U);
    DPU_LdWrite(ld, 0x6054,  0x08000800U);
    DPU_LdWrite(ld, 0x6058,  0x08000800U);
    DPU_LdWrite(ld, 0x605C,  0x08000800U);
    DPU_LdWrite(ld, 0x6060,  0x08000800U);
    DPU_LdWrite(ld, 0x6064,  0x08000800U);
    DPU_LdWrite(ld, 0x6068,  0x08000800U);
    DPU_LdWrite(ld, 0x606C,  0x08000800U);
    DPU_LdWrite(ld, 0x6070,  0x08000800U);
    DPU_LdWrite(ld, 0x6074,  0x08000800U);
    DPU_LdWrite(ld, 0x6078,  0x08000800U);
    DPU_LdWrite(ld, 0x607C,  0x08000800U);
    DPU_LdWrite(ld, 0x6080,  0x08000800U);
    DPU_LdWrite(ld, 0x6084,  0x08000800U);
    DPU_LdWrite(ld, 0x6088,  0x08000800U);
    DPU_LdWrite(ld, 0x608C,  0x08000800U);
    DPU_LdWrite(ld, 0x6090,  0x08000800U);
    DPU_LdWrite(ld, 0x6094,  0x08000800U);
    DPU_LdWrite(ld, 0x6098,  0x08000800U);
    DPU_LdWrite(ld, 0x609C,  0x08000800U);
    DPU_LdWrite(ld, 0x60A0,  0x08000800U);
    DPU_LdWrite(ld, 0x60A4,  0x08000800U);
    DPU_LdWrite(ld, 0x60A8,  0x08000800U);
    DPU_LdWrite(ld, 0x60AC,  0x08000800U);
    DPU_LdWrite(ld, 0x60B0,  0x08000800U);
    DPU_LdWrite(ld, 0x60B4,  0x08000800U);
    DPU_LdWrite(ld, 0x60B8,  0x08000800U);
    DPU_LdWrite(ld, 0x60BC,  0x08000800U);
    DPU_LdWrite(ld, 0x60C0,  0x08000800U);
    DPU_LdWrite(ld, 0x60C4,  0x08000800U);
    DPU_LdWrite(ld, 0x60C8,  0x08000800U);
    DPU_LdWrite(ld, 0x60CC,  0x08000800U);
    DPU_LdWrite(ld, 0x60D0,  0x08000800U);
    DPU_LdWrite(ld, 0x60D4,  0x08000800U);
    DPU_LdWrite(ld, 0x60D8,  0x08000800U);
    DPU_LdWrite(ld, 0x60DC,  0x08000800U);
    DPU_LdWrite(ld, 0x60E0,  0x08000800U);
    DPU_LdWrite(ld, 0x60E4,  0x08000800U);
    DPU_LdWrite(ld, 0x60E8,  0x08000800U);
    DPU_LdWrite(ld, 0x60EC,  0x08000800U);
    DPU_LdWrite(ld, 0x60F0,  0x08000800U);
    DPU_LdWrite(ld, 0x60F4,  0x08000800U);
    DPU_LdWrite(ld, 0x60F8,  0x08000800U);
    DPU_LdWrite(ld, 0x60FC,  0x08000800U);
    DPU_LdWrite(ld, 0x6100,  0x08000800U);
    DPU_LdWrite(ld, 0x6104,  0x08000800U);
    DPU_LdWrite(ld, 0x6108,  0x08000800U);
    DPU_LdWrite(ld, 0x610C,  0x08000800U);
    DPU_LdWrite(ld, 0x6110,  0x08000800U);
    DPU_LdWrite(ld, 0x6114,  0x08000800U);
    DPU_LdWrite(ld, 0x6118,  0x08000800U);
    DPU_LdWrite(ld, 0x611C,  0x08000800U);
    DPU_LdWrite(ld, 0x6120,  0x08000800U);
    DPU_LdWrite(ld, 0x6124,  0x08000800U);
    DPU_LdWrite(ld, 0x6128,  0x08000800U);
    DPU_LdWrite(ld, 0x612C,  0x08000800U);
    DPU_LdWrite(ld, 0x6130,  0x08000800U);
    DPU_LdWrite(ld, 0x6134,  0x08000800U);
    DPU_LdWrite(ld, 0x6138,  0x08000800U);
    DPU_LdWrite(ld, 0x613C,  0x08000800U);
    DPU_LdWrite(ld, 0x6140,  0x08000800U);
    DPU_LdWrite(ld, 0x6144,  0x08000800U);
    DPU_LdWrite(ld, 0x6148,  0x08000800U);
    DPU_LdWrite(ld, 0x614C,  0x08000800U);
    DPU_LdWrite(ld, 0x6150,  0x08000800U);
    DPU_LdWrite(ld, 0x6154,  0x08000800U);
    DPU_LdWrite(ld, 0x6158,  0x08000800U);
    DPU_LdWrite(ld, 0x615C,  0x08000800U);
    DPU_LdWrite(ld, 0x6160,  0x08000800U);
    DPU_LdWrite(ld, 0x6164,  0x08000800U);
    DPU_LdWrite(ld, 0x6168,  0x08000800U);
    DPU_LdWrite(ld, 0x616C,  0x08000800U);
    DPU_LdWrite(ld, 0x6170,  0x08000800U);
    DPU_LdWrite(ld, 0x6174,  0x08000800U);
    DPU_LdWrite(ld, 0x6178,  0x08000800U);
    DPU_LdWrite(ld, 0x617C,  0x08000800U);
    DPU_LdWrite(ld, 0x6180,  0x08000800U);
    DPU_LdWrite(ld, 0x6184,  0x08000800U);
    DPU_LdWrite(ld, 0x6188,  0x08000800U);
    DPU_LdWrite(ld, 0x618C,  0x08000800U);
    DPU_LdWrite(ld, 0x6190,  0x08000800U);
    DPU_LdWrite(ld, 0x6194,  0x08000800U);
    DPU_LdWrite(ld, 0x6198,  0x08000800U);
    DPU_LdWrite(ld, 0x619C,  0x08000800U);
    DPU_LdWrite(ld, 0x61A0,  0x08000800U);
    DPU_LdWrite(ld, 0x61A4,  0x08000800U);
    DPU_LdWrite(ld, 0x61A8,  0x08000800U);
    DPU_LdWrite(ld, 0x61AC,  0x08000800U);
    DPU_LdWrite(ld, 0x61B0,  0x08000800U);
    DPU_LdWrite(ld, 0x61B4,  0x08000800U);
    DPU_LdWrite(ld, 0x61B8,  0x08000800U);
    DPU_LdWrite(ld, 0x61BC,  0x08000800U);
    DPU_LdWrite(ld, 0x61C0,  0x08000800U);
    DPU_LdWrite(ld, 0x61C4,  0x08000800U);
    DPU_LdWrite(ld, 0x61C8,  0x08000800U);
    DPU_LdWrite(ld, 0x61CC,  0x08000800U);
    DPU_LdWrite(ld, 0x61D0,  0x08000800U);
    DPU_LdWrite(ld, 0x61D4,  0x08000800U);
    DPU_LdWrite(ld, 0x61D8,  0x08000800U);
    DPU_LdWrite(ld, 0x61DC,  0x08000800U);
    DPU_LdWrite(ld, 0x61E0,  0x08000800U);
    DPU_LdWrite(ld, 0x61E4,  0x08000800U);
    DPU_LdWrite(ld, 0x61E8,  0x08000800U);
    DPU_LdWrite(ld, 0x61EC,  0x08000800U);
    DPU_LdWrite(ld, 0x61F0,  0x08000800U);
    DPU_LdWrite(ld, 0x61F4,  0x08000800U);
    DPU_LdWrite(ld, 0x61F8,  0x08000800U);
    DPU_LdWrite(ld, 0x61FC,  0x08000800U);
    DPU_LdWrite(ld, 0x6200,  0x08000800U);
    DPU_LdWrite(ld, 0x6204,  0x08000800U);
    DPU_LdWrite(ld, 0x6208,  0x08000800U);
    DPU_LdWrite(ld, 0x620C,  0x08000800U);
    DPU_LdWrite(ld, 0x6210,  0x08000800U);
    DPU_LdWrite(ld, 0x6214,  0x08000800U);
    DPU_LdWrite(ld, 0x6218,  0x08000800U);
    DPU_LdWrite(ld, 0x621C,  0x08000800U);
    DPU_LdWrite(ld, 0x6220,  0x08000800U);
    DPU_LdWrite(ld, 0x6224,  0x08000800U);
    DPU_LdWrite(ld, 0x6228,  0x08000800U);
    DPU_LdWrite(ld, 0x622C,  0x08000800U);
    DPU_LdWrite(ld, 0x6230,  0x08000800U);
    DPU_LdWrite(ld, 0x6234,  0x08000800U);
    DPU_LdWrite(ld, 0x6238,  0x08000800U);
    DPU_LdWrite(ld, 0x623C,  0x08000800U);
    DPU_LdWrite(ld, 0x6240,  0x08000800U);
    DPU_LdWrite(ld, 0x6244,  0x08000800U);
    DPU_LdWrite(ld, 0x6248,  0x08000800U);
    DPU_LdWrite(ld, 0x624C,  0x08000800U);
    DPU_LdWrite(ld, 0x6250,  0x08000800U);
    DPU_LdWrite(ld, 0x6254,  0x08000800U);
    DPU_LdWrite(ld, 0x6258,  0x08000800U);
    DPU_LdWrite(ld, 0x625C,  0x08000800U);
    DPU_LdWrite(ld, 0x6260,  0x08000800U);
    DPU_LdWrite(ld, 0x6264,  0x08000800U);
    DPU_LdWrite(ld, 0x6268,  0x08000800U);
    DPU_LdWrite(ld, 0x626C,  0x08000800U);
    DPU_LdWrite(ld, 0x6270,  0x08000800U);
    DPU_LdWrite(ld, 0x6274,  0x08000800U);
    DPU_LdWrite(ld, 0x6278,  0x08000800U);
    DPU_LdWrite(ld, 0x627C,  0x08000800U);
    DPU_LdWrite(ld, 0x6280,  0x08000800U);
    DPU_LdWrite(ld, 0x6284,  0x08000800U);
    DPU_LdWrite(ld, 0x6288,  0x08000800U);
    DPU_LdWrite(ld, 0x628C,  0x08000800U);
    DPU_LdWrite(ld, 0x6290,  0x08000800U);
    DPU_LdWrite(ld, 0x6294,  0x08000800U);
    DPU_LdWrite(ld, 0x6298,  0x08000800U);
    DPU_LdWrite(ld, 0x629C,  0x08000800U);
    DPU_LdWrite(ld, 0x62A0,  0x08000800U);
    DPU_LdWrite(ld, 0x62A4,  0x08000800U);
    DPU_LdWrite(ld, 0x62A8,  0x08000800U);
    DPU_LdWrite(ld, 0x62AC,  0x08000800U);
    DPU_LdWrite(ld, 0x62B0,  0x08000800U);
    DPU_LdWrite(ld, 0x62B4,  0x08000800U);
    DPU_LdWrite(ld, 0x62B8,  0x08000800U);
    DPU_LdWrite(ld, 0x62BC,  0x08000800U);
    DPU_LdWrite(ld, 0x62C0,  0x08000800U);
    DPU_LdWrite(ld, 0x62C4,  0x08000800U);
    DPU_LdWrite(ld, 0x62C8,  0x08000800U);
    DPU_LdWrite(ld, 0x62CC,  0x08000800U);
    DPU_LdWrite(ld, 0x62D0,  0x08000800U);
    DPU_LdWrite(ld, 0x62D4,  0x08000800U);
    DPU_LdWrite(ld, 0x62D8,  0x08000800U);
    DPU_LdWrite(ld, 0x62DC,  0x08000800U);
    DPU_LdWrite(ld, 0x62E0,  0x08000800U);
    DPU_LdWrite(ld, 0x62E4,  0x08000800U);
    DPU_LdWrite(ld, 0x62E8,  0x08000800U);
    DPU_LdWrite(ld, 0x62EC,  0x08000800U);
    DPU_LdWrite(ld, 0x62F0,  0x08000800U);
    DPU_LdWrite(ld, 0x62F4,  0x08000800U);
    DPU_LdWrite(ld, 0x62F8,  0x08000800U);
    DPU_LdWrite(ld, 0x62FC,  0x08000800U);
    DPU_LdWrite(ld, 0x6300,  0x08000800U);
    DPU_LdWrite(ld, 0x6304,  0x08000800U);
    DPU_LdWrite(ld, 0x6308,  0x08000800U);
    DPU_LdWrite(ld, 0x630C,  0x08000800U);
    DPU_LdWrite(ld, 0x6310,  0x08000800U);
    DPU_LdWrite(ld, 0x6314,  0x08000800U);
    DPU_LdWrite(ld, 0x6318,  0x08000800U);
    DPU_LdWrite(ld, 0x631C,  0x08000800U);
    DPU_LdWrite(ld, 0x6320,  0x08000800U);
    DPU_LdWrite(ld, 0x6324,  0x08000800U);
    DPU_LdWrite(ld, 0x6328,  0x08000800U);
    DPU_LdWrite(ld, 0x632C,  0x08000800U);
    DPU_LdWrite(ld, 0x6330,  0x08000800U);
    DPU_LdWrite(ld, 0x6334,  0x08000800U);
    DPU_LdWrite(ld, 0x6338,  0x08000800U);
    DPU_LdWrite(ld, 0x633C,  0x08000800U);
    DPU_LdWrite(ld, 0x6340,  0x08000800U);
    DPU_LdWrite(ld, 0x6344,  0x08000800U);
    DPU_LdWrite(ld, 0x6348,  0x08000800U);
    DPU_LdWrite(ld, 0x634C,  0x08000800U);
    DPU_LdWrite(ld, 0x6350,  0x08000800U);
    DPU_LdWrite(ld, 0x6354,  0x08000800U);
    DPU_LdWrite(ld, 0x6358,  0x08000800U);
    DPU_LdWrite(ld, 0x635C,  0x08000800U);
    DPU_LdWrite(ld, 0x6360,  0x08000800U);
    DPU_LdWrite(ld, 0x6364,  0x08000800U);
    DPU_LdWrite(ld, 0x6368,  0x08000800U);
    DPU_LdWrite(ld, 0x636C,  0x08000800U);
    DPU_LdWrite(ld, 0x6370,  0x08000800U);
    DPU_LdWrite(ld, 0x6374,  0x08000800U);
    DPU_LdWrite(ld, 0x6378,  0x08000800U);
    DPU_LdWrite(ld, 0x637C,  0x08000800U);
    DPU_LdWrite(ld, 0x6380,  0x08000800U);
    DPU_LdWrite(ld, 0x6384,  0x08000800U);
    DPU_LdWrite(ld, 0x6388,  0x08000800U);
    DPU_LdWrite(ld, 0x638C,  0x08000800U);
    DPU_LdWrite(ld, 0x6390,  0x08000800U);
    DPU_LdWrite(ld, 0x6394,  0x08000800U);
    DPU_LdWrite(ld, 0x6398,  0x08000800U);
    DPU_LdWrite(ld, 0x639C,  0x08000800U);
    DPU_LdWrite(ld, 0x63A0,  0x08000800U);
    DPU_LdWrite(ld, 0x63A4,  0x08000800U);
    DPU_LdWrite(ld, 0x63A8,  0x08000800U);
    DPU_LdWrite(ld, 0x63AC,  0x08000800U);
    DPU_LdWrite(ld, 0x63B0,  0x08000800U);
    DPU_LdWrite(ld, 0x63B4,  0x08000800U);
    DPU_LdWrite(ld, 0x63B8,  0x08000800U);
    DPU_LdWrite(ld, 0x63BC,  0x08000800U);
    DPU_LdWrite(ld, 0x63C0,  0x08000800U);
    DPU_LdWrite(ld, 0x63C4,  0x08000800U);
    DPU_LdWrite(ld, 0x63C8,  0x08000800U);
    DPU_LdWrite(ld, 0x63CC,  0x08000800U);
    DPU_LdWrite(ld, 0x63D0,  0x08000800U);
    DPU_LdWrite(ld, 0x63D4,  0x08000800U);
    DPU_LdWrite(ld, 0x63D8,  0x08000800U);
    DPU_LdWrite(ld, 0x63DC,  0x08000800U);
    DPU_LdWrite(ld, 0x63E0,  0x08000800U);
    DPU_LdWrite(ld, 0x63E4,  0x08000800U);
    DPU_LdWrite(ld, 0x63E8,  0x08000800U);
    DPU_LdWrite(ld, 0x63EC,  0x08000800U);
    DPU_LdWrite(ld, 0x63F0,  0x08000800U);
    DPU_LdWrite(ld, 0x63F4,  0x08000800U);
    DPU_LdWrite(ld, 0x63F8,  0x08000800U);
    DPU_LdWrite(ld, 0x63FC,  0x08000800U);
}
#endif
