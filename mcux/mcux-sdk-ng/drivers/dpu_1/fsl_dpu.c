/*
 * Copyright 2023-2024 NXP
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
#define DPU_FETCHYUV0_DYNAMIC_OFFSET    0x201008U
#define DPU_BLITBLEND9_DYNAMIC_OFFSET   0x71008U
#define DPU_H_SCALER9_DYNAMIC_OFFSET    0xB1008U
#define DPU_V_SCALER9_DYNAMIC_OFFSET    0xC1008U
#define DPU_EXTDST0_DYNAMIC_OFFSET      0x11100CU
#define DPU_EXTDST4_DYNAMIC_OFFSET      0x12100CU
#define DPU_EXTDST1_DYNAMIC_OFFSET      0x15100CU
#define DPU_EXTDST5_DYNAMIC_OFFSET      0x16100CU
#define DPU_H_SCALER4_DYNAMIC_OFFSET    0x271008U
#define DPU_V_SCALER4_DYNAMIC_OFFSET    0x281008U
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
    {
        .unit   = kDPU_LayerBlend6,
        .offset = DPU_LAYERBLEND6_DYNAMIC_OFFSET,
    },
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
    assert(intBits + fracBits < 32U);

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
        ret = ((~ret) + 1U) & ~(((uint32_t)-1) << (intBits + fracBits + 1U));
    }

    return ret;
}

void DPU_Init(DISPLAY_SEERIS_Type *base)
{
    /* No dpu dedicate clock, related root clocks were enabled in dpu_board.c */
    /* Enable domainmask for store9 and extdst0, 1, 4, 5 */
    base->DOMAINMASK_STORE9_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST0_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST4_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST1_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
    base->DOMAINMASK_EXTDST5_DOMAIN_MASK0 |= DOMAINMASK_ENABLE;
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

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable dpu clock */
    (void)CLOCK_DisableClock(s_dpuClock[DPU_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
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
        kDPU_LayerBlend1,  kDPU_LayerBlend2, kDPU_LayerBlend3, kDPU_LayerBlend4, kDPU_FetchYuv2,
        kDPU_LayerBlend5,  kDPU_LayerBlend6, kDPU_FetchYuv3
    };
    for (uint32_t i = 0; i < ARRAY_SIZE(dpuUnits); i++)
    {
        DPU_SetUnitSrc(base, dpuUnits[i], 0U);
    }

    /* Enable fetchlayer shdldreq Sticky */
    base->PIXENG_FETCHLAYER0_SHDLDREQCONTROL |= SHDLDREQSTICKY_ENABLE;
    base->PIXENG_FETCHLAYER1_SHDLDREQCONTROL |= SHDLDREQSTICKY_ENABLE;
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
                           DPU_LAYERBLEND_CONTROL_AlphaMaskEnable(config->enableAlphaMask) |
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
                      DPU_FRAMEGEN_VTCFG2_VsEn_MASK;

    /* KICK signal set to start of last vertical blanking line. */
    display->PKICKCONFIG = DPU_FRAMEGEN_PKICKCONFIG_PKickRow(config->height) |
                           DPU_FRAMEGEN_PKICKCONFIG_PKickCol(config->width + 1UL) |
                           DPU_FRAMEGEN_PKICKCONFIG_PKickEn_MASK;

    display->SKICKCONFIG = DPU_FRAMEGEN_SKICKCONFIG_SKickRow(config->height) |
                           DPU_FRAMEGEN_SKICKCONFIG_SKickCol(config->width + 1UL) |
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
                             DPU_FETCHWARP_WARPCONTROL_WarpSymmetricOffset(config->enableSymmetricOffset);

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
