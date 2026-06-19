/*
 * Copyright (C) 2026, Savoir-faire Linux
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_LCDIFV3_SOC_H_
#define FSL_LCDIFV3_SOC_H_

/* Per-SoC compatibility definitions for LCDIFv3. */

#if defined(CPU_MIMX8ML2CVNKZ_cm7)  || defined(CPU_MIMX8ML2DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53) || \
    defined(CPU_MIMX8ML2CVNKZ_dsp)  || defined(CPU_MIMX8ML2DVNLZ_dsp)  || \
    defined(CPU_MIMX8ML3CVNKZ_cm7)  || defined(CPU_MIMX8ML3DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53) || \
    defined(CPU_MIMX8ML3CVNKZ_dsp)  || defined(CPU_MIMX8ML3DVNLZ_dsp)  || \
    defined(CPU_MIMX8ML4CVNKZ_cm7)  || defined(CPU_MIMX8ML4DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53) || \
    defined(CPU_MIMX8ML5CVNKZ_cm7)  || defined(CPU_MIMX8ML5DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53) || \
    defined(CPU_MIMX8ML5CVNKZ_dsp)  || defined(CPU_MIMX8ML5DVNLZ_dsp)  || \
    defined(CPU_MIMX8ML6CVNKZ_cm7)  || defined(CPU_MIMX8ML6DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53) || \
    defined(CPU_MIMX8ML8CVNKZ_cm7)  || defined(CPU_MIMX8ML8DVNLZ_cm7)  || \
    defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53) || \
    defined(CPU_MIMX8ML8CVNKZ_dsp)  || defined(CPU_MIMX8ML8DVNLZ_dsp)

/* LCDIF1 is gated by the shared MEDIA CCGR on i.MX8MP. */
#define LCDIFV3_CLOCKS { kCLOCK_Media, kCLOCK_Media, kCLOCK_Hdmi }

/*!
 * @brief i.MX93-shaped LCDIFv3 register layout overlay for the i.MX8MP.
 *
 * The i.MX8MP and i.MX93 LCDIFv3 registers are compatible, but their generated
 * device headers use different field names. This overlay keeps the LCDIFv3 HAL
 * source independent from that generated-header difference.
 */
typedef struct {
    struct {                            /* offset: 0x000 */
        __IO uint32_t RW;               /* offset: 0x000 */
        __IO uint32_t SET;              /* offset: 0x004 */
        __IO uint32_t CLR;              /* offset: 0x008 */
        __IO uint32_t TOG;              /* offset: 0x00C */
    } CTRL;
    __IO uint32_t DISP_PARA;            /* offset: 0x010 */
    __IO uint32_t DISP_SIZE;            /* offset: 0x014 */
    __IO uint32_t HSYN_PARA;            /* offset: 0x018 */
    __IO uint32_t VSYN_PARA;            /* offset: 0x01C */
    __IO uint32_t VSYN_HSYN_WIDTH;      /* offset: 0x020 */
    __IO uint32_t INT_STATUS_D0;        /* offset: 0x024 */
    __IO uint32_t INT_ENABLE_D0;        /* offset: 0x028 */
         uint8_t  RESERVED_0[4];        /* offset: 0x02C */
    __IO uint32_t INT_STATUS_D1;        /* offset: 0x030 */
    __IO uint32_t INT_ENABLE_D1;        /* offset: 0x034 */
         uint8_t  RESERVED_1[456];      /* offset: 0x038 .. 0x1FF */
    __IO uint32_t CTRLDESCL_1[1];       /* offset: 0x200 */
         uint8_t  RESERVED_2[4];        /* offset: 0x204 */
    __IO uint32_t CTRLDESCL_3[1];       /* offset: 0x208 */
    __IO uint32_t CTRLDESCL_LOW_4[1];   /* offset: 0x20C */
    __IO uint32_t CTRLDESCL_HIGH_4[1];  /* offset: 0x210 */
    __IO uint32_t CTRLDESCL_5[1];       /* offset: 0x214 */
         uint8_t  RESERVED_3[4];        /* offset: 0x218 */
    __IO uint32_t CSC_CTRL[1];          /* offset: 0x21C */
    __IO uint32_t CSC_COEF0[1];         /* offset: 0x220 */
    __IO uint32_t CSC_COEF1[1];         /* offset: 0x224 */
    __IO uint32_t CSC_COEF2[1];         /* offset: 0x228 */
    __IO uint32_t CSC_COEF3[1];         /* offset: 0x22C */
    __IO uint32_t CSC_COEF4[1];         /* offset: 0x230 */
    __IO uint32_t CSC_COEF5[1];         /* offset: 0x234 */
    __IO uint32_t PANIC_THRES[1];       /* offset: 0x238 */
} LCDIFV3_Compat_Type;

/* Use the compatible layout in the LCDIFv3 HAL without editing PERI_LCDIF.h. */
#define LCDIF_Type LCDIFV3_Compat_Type

/* CTRLDESCL_1: WIDTH / HEIGHT (SHIFT used directly) */
#define LCDIF_CTRLDESCL_1_WIDTH_SHIFT       LCDIF_CTRLDESCL0_1_WIDTH_SHIFT
#define LCDIF_CTRLDESCL_1_HEIGHT_SHIFT      LCDIF_CTRLDESCL0_1_HEIGHT_SHIFT

/* CTRLDESCL_5: BPP / EN / SHADOW_LOAD_EN / YUV_FORMAT */
#define LCDIF_CTRLDESCL_5_BPP               LCDIF_CTRLDESCL0_5_BPP
#define LCDIF_CTRLDESCL_5_BPP_MASK          LCDIF_CTRLDESCL0_5_BPP_MASK
#define LCDIF_CTRLDESCL_5_EN_MASK           LCDIF_CTRLDESCL0_5_EN_MASK
#define LCDIF_CTRLDESCL_5_SHADOW_LOAD_EN_MASK LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN_MASK
#define LCDIF_CTRLDESCL_5_YUV_FORMAT        LCDIF_CTRLDESCL0_5_YUV_FORMAT
#define LCDIF_CTRLDESCL_5_YUV_FORMAT_MASK   LCDIF_CTRLDESCL0_5_YUV_FORMAT_MASK

/* CSC_CTRL: BYPASS / CSC_MODE */
#define LCDIF_CSC_CTRL_BYPASS               LCDIF_CSC0_CTRL_BYPASS
#define LCDIF_CSC_CTRL_BYPASS_MASK          LCDIF_CSC0_CTRL_BYPASS_MASK
#define LCDIF_CSC_CTRL_CSC_MODE             LCDIF_CSC0_CTRL_CSC_MODE
#define LCDIF_CSC_CTRL_CSC_MODE_MASK        LCDIF_CSC0_CTRL_CSC_MODE_MASK

/* CSC_COEF0..5: coefficient fields (function form) */
#define LCDIF_CSC_COEF0_A1                  LCDIF_CSC0_COEF0_A1
#define LCDIF_CSC_COEF0_A2                  LCDIF_CSC0_COEF0_A2
#define LCDIF_CSC_COEF1_A3                  LCDIF_CSC0_COEF1_A3
#define LCDIF_CSC_COEF1_B1                  LCDIF_CSC0_COEF1_B1
#define LCDIF_CSC_COEF2_B2                  LCDIF_CSC0_COEF2_B2
#define LCDIF_CSC_COEF2_B3                  LCDIF_CSC0_COEF2_B3
#define LCDIF_CSC_COEF3_C1                  LCDIF_CSC0_COEF3_C1
#define LCDIF_CSC_COEF3_C2                  LCDIF_CSC0_COEF3_C2
#define LCDIF_CSC_COEF4_C3                  LCDIF_CSC0_COEF4_C3
#define LCDIF_CSC_COEF4_D1                  LCDIF_CSC0_COEF4_D1
#define LCDIF_CSC_COEF5_D2                  LCDIF_CSC0_COEF5_D2
#define LCDIF_CSC_COEF5_D3                  LCDIF_CSC0_COEF5_D3

/* PANIC_THRES: HIGH / LOW (SHIFT used directly) */
#define LCDIF_PANIC_THRES_PANIC_THRES_HIGH_SHIFT LCDIF_PANIC0_THRES_PANIC_THRES_HIGH_SHIFT
#define LCDIF_PANIC_THRES_PANIC_THRES_LOW_SHIFT  LCDIF_PANIC0_THRES_PANIC_THRES_LOW_SHIFT

#endif /* i.MX8MP */

#endif /* FSL_LCDIFV3_SOC_H_ */
