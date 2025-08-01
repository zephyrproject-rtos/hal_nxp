/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SUBSAM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SUBSAM.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SUBSAM
 *
 * CMSIS Peripheral Access Layer for SUBSAM
 */

#if !defined(PERI_SUBSAM_H_)
#define PERI_SUBSAM_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SUBSAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SUBSAM_Peripheral_Access_Layer SUBSAM Peripheral Access Layer
 * @{
 */

/** SUBSAM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< offset: 0x0 */
    __IO uint32_t SET;                               /**< offset: 0x4 */
    __IO uint32_t CLR;                               /**< offset: 0x8 */
    __IO uint32_t TOG;                               /**< offset: 0xC */
  } SS_SYS_CTRL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< offset: 0x10 */
    __IO uint32_t SET;                               /**< offset: 0x14 */
    __IO uint32_t CLR;                               /**< offset: 0x18 */
    __IO uint32_t TOG;                               /**< offset: 0x1C */
  } SS_DISPLAY;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< offset: 0x20 */
    __IO uint32_t SET;                               /**< offset: 0x24 */
    __IO uint32_t CLR;                               /**< offset: 0x28 */
    __IO uint32_t TOG;                               /**< offset: 0x2C */
  } SS_HSYNC;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< offset: 0x30 */
    __IO uint32_t SET;                               /**< offset: 0x34 */
    __IO uint32_t CLR;                               /**< offset: 0x38 */
    __IO uint32_t TOG;                               /**< offset: 0x3C */
  } SS_VSYNC;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< offset: 0x40 */
    __IO uint32_t SET;                               /**< offset: 0x44 */
    __IO uint32_t CLR;                               /**< offset: 0x48 */
    __IO uint32_t TOG;                               /**< offset: 0x4C */
  } SS_DE_ULC;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< offset: 0x50 */
    __IO uint32_t SET;                               /**< offset: 0x54 */
    __IO uint32_t CLR;                               /**< offset: 0x58 */
    __IO uint32_t TOG;                               /**< offset: 0x5C */
  } SS_DE_LRC;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< offset: 0x60 */
    __IO uint32_t SET;                               /**< offset: 0x64 */
    __IO uint32_t CLR;                               /**< offset: 0x68 */
    __IO uint32_t TOG;                               /**< offset: 0x6C */
  } SS_MODE;
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< offset: 0x70 */
    __IO uint32_t SET;                               /**< offset: 0x74 */
    __IO uint32_t CLR;                               /**< offset: 0x78 */
    __IO uint32_t TOG;                               /**< offset: 0x7C */
  } SS_COEFF;
  struct {                                         /* offset: 0x80 */
    __IO uint32_t RW;                                /**< offset: 0x80 */
    __IO uint32_t SET;                               /**< offset: 0x84 */
    __IO uint32_t CLR;                               /**< offset: 0x88 */
    __IO uint32_t TOG;                               /**< offset: 0x8C */
  } SS_CLIP_CB;
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< offset: 0x90 */
    __IO uint32_t SET;                               /**< offset: 0x94 */
    __IO uint32_t CLR;                               /**< offset: 0x98 */
    __IO uint32_t TOG;                               /**< offset: 0x9C */
  } SS_CLIP_CR;
  struct {                                         /* offset: 0xA0 */
    __IO uint32_t RW;                                /**< offset: 0xA0 */
    __IO uint32_t SET;                               /**< offset: 0xA4 */
    __IO uint32_t CLR;                               /**< offset: 0xA8 */
    __IO uint32_t TOG;                               /**< offset: 0xAC */
  } SS_INTER_MODE;
  __IO uint32_t SS_CHKSUM_CTRL;                    /**< offset: 0xB0 */
  __IO uint32_t SS_CHKSUM_START;                   /**< offset: 0xB4 */
  __IO uint32_t SS_CHKSUM_END;                     /**< offset: 0xB8 */
  __I  uint32_t SS_CHKSUM_DATA_LOW;                /**< offset: 0xBC */
  __IO uint32_t SS_CHKSUM_DATA_HIGH;               /**< offset: 0xC0 */
} SUBSAM_Type;

/* ----------------------------------------------------------------------------
   -- SUBSAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SUBSAM_Register_Masks SUBSAM Register Masks
 * @{
 */

/*! @name SS_SYS_CTRL -  */
/*! @{ */

#define SUBSAM_SS_SYS_CTRL_RUN_EN_MASK           (0x1U)
#define SUBSAM_SS_SYS_CTRL_RUN_EN_SHIFT          (0U)
#define SUBSAM_SS_SYS_CTRL_RUN_EN(x)             (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_SYS_CTRL_RUN_EN_SHIFT)) & SUBSAM_SS_SYS_CTRL_RUN_EN_MASK)
/*! @} */

/*! @name SS_DISPLAY -  */
/*! @{ */

#define SUBSAM_SS_DISPLAY_LRC_X_MASK             (0x1FFFU)
#define SUBSAM_SS_DISPLAY_LRC_X_SHIFT            (0U)
#define SUBSAM_SS_DISPLAY_LRC_X(x)               (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DISPLAY_LRC_X_SHIFT)) & SUBSAM_SS_DISPLAY_LRC_X_MASK)

#define SUBSAM_SS_DISPLAY_LRC_Y_MASK             (0x1FFF0000U)
#define SUBSAM_SS_DISPLAY_LRC_Y_SHIFT            (16U)
#define SUBSAM_SS_DISPLAY_LRC_Y(x)               (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DISPLAY_LRC_Y_SHIFT)) & SUBSAM_SS_DISPLAY_LRC_Y_MASK)
/*! @} */

/*! @name SS_HSYNC -  */
/*! @{ */

#define SUBSAM_SS_HSYNC_START_MASK               (0x1FFFU)
#define SUBSAM_SS_HSYNC_START_SHIFT              (0U)
#define SUBSAM_SS_HSYNC_START(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_HSYNC_START_SHIFT)) & SUBSAM_SS_HSYNC_START_MASK)

#define SUBSAM_SS_HSYNC_END_MASK                 (0x1FFF0000U)
#define SUBSAM_SS_HSYNC_END_SHIFT                (16U)
#define SUBSAM_SS_HSYNC_END(x)                   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_HSYNC_END_SHIFT)) & SUBSAM_SS_HSYNC_END_MASK)

#define SUBSAM_SS_HSYNC_POL_MASK                 (0x80000000U)
#define SUBSAM_SS_HSYNC_POL_SHIFT                (31U)
#define SUBSAM_SS_HSYNC_POL(x)                   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_HSYNC_POL_SHIFT)) & SUBSAM_SS_HSYNC_POL_MASK)
/*! @} */

/*! @name SS_VSYNC -  */
/*! @{ */

#define SUBSAM_SS_VSYNC_START_MASK               (0x1FFFU)
#define SUBSAM_SS_VSYNC_START_SHIFT              (0U)
#define SUBSAM_SS_VSYNC_START(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_VSYNC_START_SHIFT)) & SUBSAM_SS_VSYNC_START_MASK)

#define SUBSAM_SS_VSYNC_END_MASK                 (0x1FFF0000U)
#define SUBSAM_SS_VSYNC_END_SHIFT                (16U)
#define SUBSAM_SS_VSYNC_END(x)                   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_VSYNC_END_SHIFT)) & SUBSAM_SS_VSYNC_END_MASK)

#define SUBSAM_SS_VSYNC_POL_MASK                 (0x80000000U)
#define SUBSAM_SS_VSYNC_POL_SHIFT                (31U)
#define SUBSAM_SS_VSYNC_POL(x)                   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_VSYNC_POL_SHIFT)) & SUBSAM_SS_VSYNC_POL_MASK)
/*! @} */

/*! @name SS_DE_ULC -  */
/*! @{ */

#define SUBSAM_SS_DE_ULC_ULC_X_MASK              (0x1FFFU)
#define SUBSAM_SS_DE_ULC_ULC_X_SHIFT             (0U)
#define SUBSAM_SS_DE_ULC_ULC_X(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DE_ULC_ULC_X_SHIFT)) & SUBSAM_SS_DE_ULC_ULC_X_MASK)

#define SUBSAM_SS_DE_ULC_ULC_Y_MASK              (0x1FFF0000U)
#define SUBSAM_SS_DE_ULC_ULC_Y_SHIFT             (16U)
#define SUBSAM_SS_DE_ULC_ULC_Y(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DE_ULC_ULC_Y_SHIFT)) & SUBSAM_SS_DE_ULC_ULC_Y_MASK)

#define SUBSAM_SS_DE_ULC_POL_MASK                (0x80000000U)
#define SUBSAM_SS_DE_ULC_POL_SHIFT               (31U)
#define SUBSAM_SS_DE_ULC_POL(x)                  (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DE_ULC_POL_SHIFT)) & SUBSAM_SS_DE_ULC_POL_MASK)
/*! @} */

/*! @name SS_DE_LRC -  */
/*! @{ */

#define SUBSAM_SS_DE_LRC_LRC_X_MASK              (0x1FFFU)
#define SUBSAM_SS_DE_LRC_LRC_X_SHIFT             (0U)
#define SUBSAM_SS_DE_LRC_LRC_X(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DE_LRC_LRC_X_SHIFT)) & SUBSAM_SS_DE_LRC_LRC_X_MASK)

#define SUBSAM_SS_DE_LRC_LRC_Y_MASK              (0x1FFF0000U)
#define SUBSAM_SS_DE_LRC_LRC_Y_SHIFT             (16U)
#define SUBSAM_SS_DE_LRC_LRC_Y(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_DE_LRC_LRC_Y_SHIFT)) & SUBSAM_SS_DE_LRC_LRC_Y_MASK)
/*! @} */

/*! @name SS_MODE -  */
/*! @{ */

#define SUBSAM_SS_MODE_PIPE_MODE_MASK            (0x3U)
#define SUBSAM_SS_MODE_PIPE_MODE_SHIFT           (0U)
#define SUBSAM_SS_MODE_PIPE_MODE(x)              (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_PIPE_MODE_SHIFT)) & SUBSAM_SS_MODE_PIPE_MODE_MASK)

#define SUBSAM_SS_MODE_COMP_SEL0_OUT_MASK        (0x300U)
#define SUBSAM_SS_MODE_COMP_SEL0_OUT_SHIFT       (8U)
#define SUBSAM_SS_MODE_COMP_SEL0_OUT(x)          (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL0_OUT_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL0_OUT_MASK)

#define SUBSAM_SS_MODE_COMP_SEL1_OUT_MASK        (0xC00U)
#define SUBSAM_SS_MODE_COMP_SEL1_OUT_SHIFT       (10U)
#define SUBSAM_SS_MODE_COMP_SEL1_OUT(x)          (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL1_OUT_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL1_OUT_MASK)

#define SUBSAM_SS_MODE_COMP_SEL2_OUT_MASK        (0x3000U)
#define SUBSAM_SS_MODE_COMP_SEL2_OUT_SHIFT       (12U)
#define SUBSAM_SS_MODE_COMP_SEL2_OUT(x)          (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL2_OUT_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL2_OUT_MASK)

#define SUBSAM_SS_MODE_COMP_SEL0_IN_MASK         (0x30000U)
#define SUBSAM_SS_MODE_COMP_SEL0_IN_SHIFT        (16U)
#define SUBSAM_SS_MODE_COMP_SEL0_IN(x)           (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL0_IN_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL0_IN_MASK)

#define SUBSAM_SS_MODE_COMP_SEL1_IN_MASK         (0xC0000U)
#define SUBSAM_SS_MODE_COMP_SEL1_IN_SHIFT        (18U)
#define SUBSAM_SS_MODE_COMP_SEL1_IN(x)           (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL1_IN_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL1_IN_MASK)

#define SUBSAM_SS_MODE_COMP_SEL2_IN_MASK         (0x300000U)
#define SUBSAM_SS_MODE_COMP_SEL2_IN_SHIFT        (20U)
#define SUBSAM_SS_MODE_COMP_SEL2_IN(x)           (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_MODE_COMP_SEL2_IN_SHIFT)) & SUBSAM_SS_MODE_COMP_SEL2_IN_MASK)
/*! @} */

/*! @name SS_COEFF -  */
/*! @{ */

#define SUBSAM_SS_COEFF_HORIZ_A_MASK             (0xFU)
#define SUBSAM_SS_COEFF_HORIZ_A_SHIFT            (0U)
#define SUBSAM_SS_COEFF_HORIZ_A(x)               (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_HORIZ_A_SHIFT)) & SUBSAM_SS_COEFF_HORIZ_A_MASK)

#define SUBSAM_SS_COEFF_HORIZ_B_MASK             (0xF0U)
#define SUBSAM_SS_COEFF_HORIZ_B_SHIFT            (4U)
#define SUBSAM_SS_COEFF_HORIZ_B(x)               (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_HORIZ_B_SHIFT)) & SUBSAM_SS_COEFF_HORIZ_B_MASK)

#define SUBSAM_SS_COEFF_HORIZ_C_MASK             (0xF00U)
#define SUBSAM_SS_COEFF_HORIZ_C_SHIFT            (8U)
#define SUBSAM_SS_COEFF_HORIZ_C(x)               (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_HORIZ_C_SHIFT)) & SUBSAM_SS_COEFF_HORIZ_C_MASK)

#define SUBSAM_SS_COEFF_HORIZ_NORM_MASK          (0x7000U)
#define SUBSAM_SS_COEFF_HORIZ_NORM_SHIFT         (12U)
#define SUBSAM_SS_COEFF_HORIZ_NORM(x)            (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_HORIZ_NORM_SHIFT)) & SUBSAM_SS_COEFF_HORIZ_NORM_MASK)

#define SUBSAM_SS_COEFF_VERT_A_MASK              (0xF0000U)
#define SUBSAM_SS_COEFF_VERT_A_SHIFT             (16U)
#define SUBSAM_SS_COEFF_VERT_A(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_VERT_A_SHIFT)) & SUBSAM_SS_COEFF_VERT_A_MASK)

#define SUBSAM_SS_COEFF_VERT_B_MASK              (0xF00000U)
#define SUBSAM_SS_COEFF_VERT_B_SHIFT             (20U)
#define SUBSAM_SS_COEFF_VERT_B(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_VERT_B_SHIFT)) & SUBSAM_SS_COEFF_VERT_B_MASK)

#define SUBSAM_SS_COEFF_VERT_C_MASK              (0xF000000U)
#define SUBSAM_SS_COEFF_VERT_C_SHIFT             (24U)
#define SUBSAM_SS_COEFF_VERT_C(x)                (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_VERT_C_SHIFT)) & SUBSAM_SS_COEFF_VERT_C_MASK)

#define SUBSAM_SS_COEFF_VERT_NORM_MASK           (0x70000000U)
#define SUBSAM_SS_COEFF_VERT_NORM_SHIFT          (28U)
#define SUBSAM_SS_COEFF_VERT_NORM(x)             (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_COEFF_VERT_NORM_SHIFT)) & SUBSAM_SS_COEFF_VERT_NORM_MASK)
/*! @} */

/*! @name SS_CLIP_CB -  */
/*! @{ */

#define SUBSAM_SS_CLIP_CB_MIN_MASK               (0xFFFU)
#define SUBSAM_SS_CLIP_CB_MIN_SHIFT              (0U)
#define SUBSAM_SS_CLIP_CB_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CLIP_CB_MIN_SHIFT)) & SUBSAM_SS_CLIP_CB_MIN_MASK)

#define SUBSAM_SS_CLIP_CB_MAX_MASK               (0xFFF0000U)
#define SUBSAM_SS_CLIP_CB_MAX_SHIFT              (16U)
#define SUBSAM_SS_CLIP_CB_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CLIP_CB_MAX_SHIFT)) & SUBSAM_SS_CLIP_CB_MAX_MASK)
/*! @} */

/*! @name SS_CLIP_CR -  */
/*! @{ */

#define SUBSAM_SS_CLIP_CR_MIN_MASK               (0xFFFU)
#define SUBSAM_SS_CLIP_CR_MIN_SHIFT              (0U)
#define SUBSAM_SS_CLIP_CR_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CLIP_CR_MIN_SHIFT)) & SUBSAM_SS_CLIP_CR_MIN_MASK)

#define SUBSAM_SS_CLIP_CR_MAX_MASK               (0xFFF0000U)
#define SUBSAM_SS_CLIP_CR_MAX_SHIFT              (16U)
#define SUBSAM_SS_CLIP_CR_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CLIP_CR_MAX_SHIFT)) & SUBSAM_SS_CLIP_CR_MAX_MASK)
/*! @} */

/*! @name SS_INTER_MODE -  */
/*! @{ */

#define SUBSAM_SS_INTER_MODE_INT_EN_MASK         (0x1U)
#define SUBSAM_SS_INTER_MODE_INT_EN_SHIFT        (0U)
#define SUBSAM_SS_INTER_MODE_INT_EN(x)           (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_INTER_MODE_INT_EN_SHIFT)) & SUBSAM_SS_INTER_MODE_INT_EN_MASK)

#define SUBSAM_SS_INTER_MODE_VSYNC_SHIFT_MASK    (0x2U)
#define SUBSAM_SS_INTER_MODE_VSYNC_SHIFT_SHIFT   (1U)
#define SUBSAM_SS_INTER_MODE_VSYNC_SHIFT(x)      (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_INTER_MODE_VSYNC_SHIFT_SHIFT)) & SUBSAM_SS_INTER_MODE_VSYNC_SHIFT_MASK)
/*! @} */

/*! @name SS_CHKSUM_CTRL -  */
/*! @{ */

#define SUBSAM_SS_CHKSUM_CTRL_CHKSUM_EN_MASK     (0x1U)
#define SUBSAM_SS_CHKSUM_CTRL_CHKSUM_EN_SHIFT    (0U)
/*! CHKSUM_EN
 *  0b0..Checksum is disabled.
 *  0b1..Checksum is enabled.
 */
#define SUBSAM_SS_CHKSUM_CTRL_CHKSUM_EN(x)       (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_CTRL_CHKSUM_EN_SHIFT)) & SUBSAM_SS_CHKSUM_CTRL_CHKSUM_EN_MASK)

#define SUBSAM_SS_CHKSUM_CTRL_NUM_FRAMES_MASK    (0xF0U)
#define SUBSAM_SS_CHKSUM_CTRL_NUM_FRAMES_SHIFT   (4U)
/*! NUM_FRAMES
 *  0b0000..Continuous mode. Output a checksum after each start trigger to end trigger process.
 *  0b0001..Accumulate the cheksum over one complete frame.
 *  0b0010..Accumulate the cheksum over two complete frames.
 *  0b0011-0b1111..Accumulate the cheksum over NUM_FRAMES complete frames.
 */
#define SUBSAM_SS_CHKSUM_CTRL_NUM_FRAMES(x)      (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_CTRL_NUM_FRAMES_SHIFT)) & SUBSAM_SS_CHKSUM_CTRL_NUM_FRAMES_MASK)
/*! @} */

/*! @name SS_CHKSUM_START -  */
/*! @{ */

#define SUBSAM_SS_CHKSUM_START_VCOUNT_START_MASK (0x1FFFU)
#define SUBSAM_SS_CHKSUM_START_VCOUNT_START_SHIFT (0U)
#define SUBSAM_SS_CHKSUM_START_VCOUNT_START(x)   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_START_VCOUNT_START_SHIFT)) & SUBSAM_SS_CHKSUM_START_VCOUNT_START_MASK)

#define SUBSAM_SS_CHKSUM_START_HCOUNT_START_MASK (0x1FFF0000U)
#define SUBSAM_SS_CHKSUM_START_HCOUNT_START_SHIFT (16U)
#define SUBSAM_SS_CHKSUM_START_HCOUNT_START(x)   (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_START_HCOUNT_START_SHIFT)) & SUBSAM_SS_CHKSUM_START_HCOUNT_START_MASK)
/*! @} */

/*! @name SS_CHKSUM_END -  */
/*! @{ */

#define SUBSAM_SS_CHKSUM_END_VCOUNT_END_MASK     (0x1FFFU)
#define SUBSAM_SS_CHKSUM_END_VCOUNT_END_SHIFT    (0U)
#define SUBSAM_SS_CHKSUM_END_VCOUNT_END(x)       (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_END_VCOUNT_END_SHIFT)) & SUBSAM_SS_CHKSUM_END_VCOUNT_END_MASK)

#define SUBSAM_SS_CHKSUM_END_HCOUNT_END_MASK     (0x1FFF0000U)
#define SUBSAM_SS_CHKSUM_END_HCOUNT_END_SHIFT    (16U)
#define SUBSAM_SS_CHKSUM_END_HCOUNT_END(x)       (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_END_HCOUNT_END_SHIFT)) & SUBSAM_SS_CHKSUM_END_HCOUNT_END_MASK)
/*! @} */

/*! @name SS_CHKSUM_DATA_LOW -  */
/*! @{ */

#define SUBSAM_SS_CHKSUM_DATA_LOW_CHKSUM_RESULT_MASK (0xFFFFFFFFU)
#define SUBSAM_SS_CHKSUM_DATA_LOW_CHKSUM_RESULT_SHIFT (0U)
#define SUBSAM_SS_CHKSUM_DATA_LOW_CHKSUM_RESULT(x) (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_DATA_LOW_CHKSUM_RESULT_SHIFT)) & SUBSAM_SS_CHKSUM_DATA_LOW_CHKSUM_RESULT_MASK)
/*! @} */

/*! @name SS_CHKSUM_DATA_HIGH -  */
/*! @{ */

#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_RESULT_MASK (0x3FFU)
#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_RESULT_SHIFT (0U)
#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_RESULT(x) (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_RESULT_SHIFT)) & SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_RESULT_MASK)

#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_VLD_MASK (0x80000000U)
#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_VLD_SHIFT (31U)
#define SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_VLD(x) (((uint32_t)(((uint32_t)(x)) << SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_VLD_SHIFT)) & SUBSAM_SS_CHKSUM_DATA_HIGH_CHKSUM_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SUBSAM_Register_Masks */


/*!
 * @}
 */ /* end of group SUBSAM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SUBSAM_H_ */

