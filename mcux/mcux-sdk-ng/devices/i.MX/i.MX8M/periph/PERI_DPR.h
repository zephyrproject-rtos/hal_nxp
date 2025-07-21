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
**         CMSIS Peripheral Access Layer for DPR
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
 * @file PERI_DPR.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DPR
 *
 * CMSIS Peripheral Access Layer for DPR
 */

#if !defined(PERI_DPR_H_)
#define PERI_DPR_H_                              /**< Symbol preventing repeated inclusion */

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
   -- DPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPR_Peripheral_Access_Layer DPR Peripheral Access Layer
 * @{
 */

/** DPR - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< System Control 0, offset: 0x0 */
    __IO uint32_t SET;                               /**< System Control 0, offset: 0x4 */
    __IO uint32_t CLR;                               /**< System Control 0, offset: 0x8 */
    __IO uint32_t TOG;                               /**< System Control 0, offset: 0xC */
  } SYSTEM_CTRL0;
       uint8_t RESERVED_0[16];
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Interrupt Mask, offset: 0x20 */
    __IO uint32_t SET;                               /**< Interrupt Mask, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Interrupt Mask, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Interrupt Mask, offset: 0x2C */
  } IRQ_MASK;
  struct {                                         /* offset: 0x30 */
    __I  uint32_t RW;                                /**< Status Register of Masked IRQ, offset: 0x30 */
    __I  uint32_t SET;                               /**< Status Register of Masked IRQ, offset: 0x34 */
    __I  uint32_t CLR;                               /**< Status Register of Masked IRQ, offset: 0x38 */
    __I  uint32_t TOG;                               /**< Status Register of Masked IRQ, offset: 0x3C */
  } IRQ_MASK_STATUS;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Status of Non-Masked IRQ, offset: 0x40 */
    __IO uint32_t SET;                               /**< Status of Non-Masked IRQ, offset: 0x44 */
    __IO uint32_t CLR;                               /**< Status of Non-Masked IRQ, offset: 0x48 */
    __IO uint32_t TOG;                               /**< Status of Non-Masked IRQ, offset: 0x4C */
  } IRQ_NONMASK_STATUS;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Mode Control 0, offset: 0x50 */
    __IO uint32_t SET;                               /**< Mode Control 0, offset: 0x54 */
    __IO uint32_t CLR;                               /**< Mode Control 0, offset: 0x58 */
    __IO uint32_t TOG;                               /**< Mode Control 0, offset: 0x5C */
  } MODE_CTRL0;
       uint8_t RESERVED_1[16];
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< Frame Control 0, offset: 0x70 */
    __IO uint32_t SET;                               /**< Frame Control 0, offset: 0x74 */
    __IO uint32_t CLR;                               /**< Frame Control 0, offset: 0x78 */
    __IO uint32_t TOG;                               /**< Frame Control 0, offset: 0x7C */
  } FRAME_CTRL0;
       uint8_t RESERVED_2[16];
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< Frame 1-Plane Control 0, offset: 0x90 */
    __IO uint32_t SET;                               /**< Frame 1-Plane Control 0, offset: 0x94 */
    __IO uint32_t CLR;                               /**< Frame 1-Plane Control 0, offset: 0x98 */
    __IO uint32_t TOG;                               /**< Frame 1-Plane Control 0, offset: 0x9C */
  } FRAME_1P_CTRL0;
  struct {                                         /* offset: 0xA0 */
    __IO uint32_t RW;                                /**< Frame 1-Plane Pix X Control, offset: 0xA0 */
    __IO uint32_t SET;                               /**< Frame 1-Plane Pix X Control, offset: 0xA4 */
    __IO uint32_t CLR;                               /**< Frame 1-Plane Pix X Control, offset: 0xA8 */
    __IO uint32_t TOG;                               /**< Frame 1-Plane Pix X Control, offset: 0xAC */
  } FRAME_1P_PIX_X_CTRL;
  struct {                                         /* offset: 0xB0 */
    __IO uint32_t RW;                                /**< Frame 1-Plane Pix Y Control, offset: 0xB0 */
    __IO uint32_t SET;                               /**< Frame 1-Plane Pix Y Control, offset: 0xB4 */
    __IO uint32_t CLR;                               /**< Frame 1-Plane Pix Y Control, offset: 0xB8 */
    __IO uint32_t TOG;                               /**< Frame 1-Plane Pix Y Control, offset: 0xBC */
  } FRAME_1P_PIX_Y_CTRL;
  struct {                                         /* offset: 0xC0 */
    __IO uint32_t RW;                                /**< Frame 1-Plane Base Address Control 0, offset: 0xC0 */
    __IO uint32_t SET;                               /**< Frame 1-Plane Base Address Control 0, offset: 0xC4 */
    __IO uint32_t CLR;                               /**< Frame 1-Plane Base Address Control 0, offset: 0xC8 */
    __IO uint32_t TOG;                               /**< Frame 1-Plane Base Address Control 0, offset: 0xCC */
  } FRAME_1P_BASE_ADDR_CTRL0;
       uint8_t RESERVED_3[16];
  struct {                                         /* offset: 0xE0 */
    __IO uint32_t RW;                                /**< Frame 2-Plane Control 0, offset: 0xE0 */
    __IO uint32_t SET;                               /**< Frame 2-Plane Control 0, offset: 0xE4 */
    __IO uint32_t CLR;                               /**< Frame 2-Plane Control 0, offset: 0xE8 */
    __IO uint32_t TOG;                               /**< Frame 2-Plane Control 0, offset: 0xEC */
  } FRAME_2P_CTRL0;
  struct {                                         /* offset: 0xF0 */
    __IO uint32_t RW;                                /**< Frame 2-Plane Pix X Control, offset: 0xF0 */
    __IO uint32_t SET;                               /**< Frame 2-Plane Pix X Control, offset: 0xF4 */
    __IO uint32_t CLR;                               /**< Frame 2-Plane Pix X Control, offset: 0xF8 */
    __IO uint32_t TOG;                               /**< Frame 2-Plane Pix X Control, offset: 0xFC */
  } FRAME_2P_PIX_X_CTRL;
  struct {                                         /* offset: 0x100 */
    __IO uint32_t RW;                                /**< Frame 2-Plane Pix Y Control, offset: 0x100 */
    __IO uint32_t SET;                               /**< Frame 2-Plane Pix Y Control, offset: 0x104 */
    __IO uint32_t CLR;                               /**< Frame 2-Plane Pix Y Control, offset: 0x108 */
    __IO uint32_t TOG;                               /**< Frame 2-Plane Pix Y Control, offset: 0x10C */
  } FRAME_2P_PIX_Y_CTRL;
  struct {                                         /* offset: 0x110 */
    __IO uint32_t RW;                                /**< Frame 2-Plane Base Address Control 0, offset: 0x110 */
    __IO uint32_t SET;                               /**< Frame 2-Plane Base Address Control 0, offset: 0x114 */
    __IO uint32_t CLR;                               /**< Frame 2-Plane Base Address Control 0, offset: 0x118 */
    __IO uint32_t TOG;                               /**< Frame 2-Plane Base Address Control 0, offset: 0x11C */
  } FRAME_2P_BASE_ADDR_CTRL0;
       uint8_t RESERVED_4[224];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< RTRAM Control 0, offset: 0x200 */
    __IO uint32_t SET;                               /**< RTRAM Control 0, offset: 0x204 */
    __IO uint32_t CLR;                               /**< RTRAM Control 0, offset: 0x208 */
    __IO uint32_t TOG;                               /**< RTRAM Control 0, offset: 0x20C */
  } RTRAM_CTRL0;
} DPR_Type;

/* ----------------------------------------------------------------------------
   -- DPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPR_Register_Masks DPR Register Masks
 * @{
 */

/*! @name SYSTEM_CTRL0 - System Control 0 */
/*! @{ */

#define DPR_SYSTEM_CTRL0_RUN_EN_MASK             (0x1U)
#define DPR_SYSTEM_CTRL0_RUN_EN_SHIFT            (0U)
/*! RUN_EN - Run Enable */
#define DPR_SYSTEM_CTRL0_RUN_EN(x)               (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_RUN_EN_SHIFT)) & DPR_SYSTEM_CTRL0_RUN_EN_MASK)

#define DPR_SYSTEM_CTRL0_SOFT_RESET_MASK         (0x2U)
#define DPR_SYSTEM_CTRL0_SOFT_RESET_SHIFT        (1U)
/*! SOFT_RESET - Soft Reset */
#define DPR_SYSTEM_CTRL0_SOFT_RESET(x)           (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_SOFT_RESET_SHIFT)) & DPR_SYSTEM_CTRL0_SOFT_RESET_MASK)

#define DPR_SYSTEM_CTRL0_REPEAT_EN_MASK          (0x4U)
#define DPR_SYSTEM_CTRL0_REPEAT_EN_SHIFT         (2U)
/*! REPEAT_EN - Repeat Enable */
#define DPR_SYSTEM_CTRL0_REPEAT_EN(x)            (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_REPEAT_EN_SHIFT)) & DPR_SYSTEM_CTRL0_REPEAT_EN_MASK)

#define DPR_SYSTEM_CTRL0_SHADOW_LOAD_EN_MASK     (0x8U)
#define DPR_SYSTEM_CTRL0_SHADOW_LOAD_EN_SHIFT    (3U)
/*! SHADOW_LOAD_EN - Shadow Load Enable */
#define DPR_SYSTEM_CTRL0_SHADOW_LOAD_EN(x)       (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_SHADOW_LOAD_EN_SHIFT)) & DPR_SYSTEM_CTRL0_SHADOW_LOAD_EN_MASK)

#define DPR_SYSTEM_CTRL0_SW_SHADOW_LOAD_SEL_MASK (0x10U)
#define DPR_SYSTEM_CTRL0_SW_SHADOW_LOAD_SEL_SHIFT (4U)
/*! SW_SHADOW_LOAD_SEL - Software Shadow Load Select */
#define DPR_SYSTEM_CTRL0_SW_SHADOW_LOAD_SEL(x)   (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_SW_SHADOW_LOAD_SEL_SHIFT)) & DPR_SYSTEM_CTRL0_SW_SHADOW_LOAD_SEL_MASK)

#define DPR_SYSTEM_CTRL0_BCMD2AXI_MSTR_ID_CTRL_MASK (0x10000U)
#define DPR_SYSTEM_CTRL0_BCMD2AXI_MSTR_ID_CTRL_SHIFT (16U)
/*! BCMD2AXI_MSTR_ID_CTRL - Buscmd To AXI Master ID Control */
#define DPR_SYSTEM_CTRL0_BCMD2AXI_MSTR_ID_CTRL(x) (((uint32_t)(((uint32_t)(x)) << DPR_SYSTEM_CTRL0_BCMD2AXI_MSTR_ID_CTRL_SHIFT)) & DPR_SYSTEM_CTRL0_BCMD2AXI_MSTR_ID_CTRL_MASK)
/*! @} */

/*! @name IRQ_MASK - Interrupt Mask */
/*! @{ */

#define DPR_IRQ_MASK_IRQ_DPR_CTRL_DONE_MASK      (0x1U)
#define DPR_IRQ_MASK_IRQ_DPR_CTRL_DONE_SHIFT     (0U)
/*! IRQ_DPR_CTRL_DONE - DPR Control Done IRQ Mask */
#define DPR_IRQ_MASK_IRQ_DPR_CTRL_DONE(x)        (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_IRQ_DPR_CTRL_DONE_SHIFT)) & DPR_IRQ_MASK_IRQ_DPR_CTRL_DONE_MASK)

#define DPR_IRQ_MASK_IRQ_DPR_RUN_MASK            (0x2U)
#define DPR_IRQ_MASK_IRQ_DPR_RUN_SHIFT           (1U)
/*! IRQ_DPR_RUN - DPR Run IRQ Mask */
#define DPR_IRQ_MASK_IRQ_DPR_RUN(x)              (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_IRQ_DPR_RUN_SHIFT)) & DPR_IRQ_MASK_IRQ_DPR_RUN_MASK)

#define DPR_IRQ_MASK_IRQ_DPR_SHADOW_LOADED_MASK_MASK (0x4U)
#define DPR_IRQ_MASK_IRQ_DPR_SHADOW_LOADED_MASK_SHIFT (2U)
/*! IRQ_DPR_SHADOW_LOADED_MASK - DPR Shadow Loaded IRQ Mask */
#define DPR_IRQ_MASK_IRQ_DPR_SHADOW_LOADED_MASK(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_IRQ_DPR_SHADOW_LOADED_MASK_SHIFT)) & DPR_IRQ_MASK_IRQ_DPR_SHADOW_LOADED_MASK_MASK)

#define DPR_IRQ_MASK_IRQ_AXI_READ_ERROR_MASK     (0x8U)
#define DPR_IRQ_MASK_IRQ_AXI_READ_ERROR_SHIFT    (3U)
/*! IRQ_AXI_READ_ERROR - AXI Read Error IRQ Mask */
#define DPR_IRQ_MASK_IRQ_AXI_READ_ERROR(x)       (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_IRQ_AXI_READ_ERROR_SHIFT)) & DPR_IRQ_MASK_IRQ_AXI_READ_ERROR_MASK)

#define DPR_IRQ_MASK_DPR2RTR_YRGB_FIFO_OVFL_MASK (0x10U)
#define DPR_IRQ_MASK_DPR2RTR_YRGB_FIFO_OVFL_SHIFT (4U)
/*! DPR2RTR_YRGB_FIFO_OVFL - DPR to RTRAM YRGB Fifo Overflow IRQ Mask */
#define DPR_IRQ_MASK_DPR2RTR_YRGB_FIFO_OVFL(x)   (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_DPR2RTR_YRGB_FIFO_OVFL_SHIFT)) & DPR_IRQ_MASK_DPR2RTR_YRGB_FIFO_OVFL_MASK)

#define DPR_IRQ_MASK_DPR2RTR_UV_FIFO_OVFL_MASK   (0x20U)
#define DPR_IRQ_MASK_DPR2RTR_UV_FIFO_OVFL_SHIFT  (5U)
/*! DPR2RTR_UV_FIFO_OVFL - DPR to RTRAM UV Fifo Overflow IRQ Mask */
#define DPR_IRQ_MASK_DPR2RTR_UV_FIFO_OVFL(x)     (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_DPR2RTR_UV_FIFO_OVFL_SHIFT)) & DPR_IRQ_MASK_DPR2RTR_UV_FIFO_OVFL_MASK)

#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK (0x40U)
#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT (6U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR - DPR to RTRAM Fifo load YRGB buffer ready IRQ error Mask */
#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT)) & DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK)

#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK (0x80U)
#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT (7U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR - DPR to RTRAM Fifo load UV buffer ready IRQ error Mask */
#define DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT)) & DPR_IRQ_MASK_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK)
/*! @} */

/*! @name IRQ_MASK_STATUS - Status Register of Masked IRQ */
/*! @{ */

#define DPR_IRQ_MASK_STATUS_IRQ_DPR_CTRL_DONE_MASK (0x1U)
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_CTRL_DONE_SHIFT (0U)
/*! IRQ_DPR_CTRL_DONE - DPR Control Done Masked IRQ */
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_CTRL_DONE(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_IRQ_DPR_CTRL_DONE_SHIFT)) & DPR_IRQ_MASK_STATUS_IRQ_DPR_CTRL_DONE_MASK)

#define DPR_IRQ_MASK_STATUS_IRQ_DPR_RUN_MASK     (0x2U)
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_RUN_SHIFT    (1U)
/*! IRQ_DPR_RUN - DPR Run Masked IRQ */
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_RUN(x)       (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_IRQ_DPR_RUN_SHIFT)) & DPR_IRQ_MASK_STATUS_IRQ_DPR_RUN_MASK)

#define DPR_IRQ_MASK_STATUS_IRQ_DPR_SHADOW_LOADED_MASK (0x4U)
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_SHADOW_LOADED_SHIFT (2U)
/*! IRQ_DPR_SHADOW_LOADED - DPR Shadow Loaded Masked IRQ */
#define DPR_IRQ_MASK_STATUS_IRQ_DPR_SHADOW_LOADED(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_IRQ_DPR_SHADOW_LOADED_SHIFT)) & DPR_IRQ_MASK_STATUS_IRQ_DPR_SHADOW_LOADED_MASK)

#define DPR_IRQ_MASK_STATUS_IRQ_AXI_READ_ERROR_MASK (0x8U)
#define DPR_IRQ_MASK_STATUS_IRQ_AXI_READ_ERROR_SHIFT (3U)
/*! IRQ_AXI_READ_ERROR - AXI Read Error Masked IRQ */
#define DPR_IRQ_MASK_STATUS_IRQ_AXI_READ_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_IRQ_AXI_READ_ERROR_SHIFT)) & DPR_IRQ_MASK_STATUS_IRQ_AXI_READ_ERROR_MASK)

#define DPR_IRQ_MASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_MASK (0x10U)
#define DPR_IRQ_MASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_SHIFT (4U)
/*! DPR2RTR_YRGB_FIFO_OVFL - DPR to RTRAM YRGB Fifo Overflow Masked IRQ */
#define DPR_IRQ_MASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_SHIFT)) & DPR_IRQ_MASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_MASK)

#define DPR_IRQ_MASK_STATUS_DPR2RTR_UV_FIFO_OVFL_MASK (0x20U)
#define DPR_IRQ_MASK_STATUS_DPR2RTR_UV_FIFO_OVFL_SHIFT (5U)
/*! DPR2RTR_UV_FIFO_OVFL - DPR to RTRAM UV Fifo Overflow Masked IRQ */
#define DPR_IRQ_MASK_STATUS_DPR2RTR_UV_FIFO_OVFL(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_DPR2RTR_UV_FIFO_OVFL_SHIFT)) & DPR_IRQ_MASK_STATUS_DPR2RTR_UV_FIFO_OVFL_MASK)

#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK (0x40U)
#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT (6U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR - DPR to RTRAM Fifo load YRGB buffer error Masked IRQ */
#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT)) & DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK)

#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK (0x80U)
#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT (7U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR - DPR to RTRAM Fifo load UV buffer error Masked IRQ */
#define DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT)) & DPR_IRQ_MASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK)
/*! @} */

/*! @name IRQ_NONMASK_STATUS - Status of Non-Masked IRQ */
/*! @{ */

#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_CTRL_DONE_MASK (0x1U)
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_CTRL_DONE_SHIFT (0U)
/*! IRQ_DPR_CTRL_DONE - DPR Control Done Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_CTRL_DONE(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_IRQ_DPR_CTRL_DONE_SHIFT)) & DPR_IRQ_NONMASK_STATUS_IRQ_DPR_CTRL_DONE_MASK)

#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_RUN_MASK  (0x2U)
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_RUN_SHIFT (1U)
/*! IRQ_DPR_RUN - DPR Run Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_RUN(x)    (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_IRQ_DPR_RUN_SHIFT)) & DPR_IRQ_NONMASK_STATUS_IRQ_DPR_RUN_MASK)

#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_SHADOW_LOADED_NMSTAT_MASK (0x4U)
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_SHADOW_LOADED_NMSTAT_SHIFT (2U)
/*! IRQ_DPR_SHADOW_LOADED_NMSTAT - DPR Shadow Loaded Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_IRQ_DPR_SHADOW_LOADED_NMSTAT(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_IRQ_DPR_SHADOW_LOADED_NMSTAT_SHIFT)) & DPR_IRQ_NONMASK_STATUS_IRQ_DPR_SHADOW_LOADED_NMSTAT_MASK)

#define DPR_IRQ_NONMASK_STATUS_IRQ_AXI_READ_ERROR_MASK (0x8U)
#define DPR_IRQ_NONMASK_STATUS_IRQ_AXI_READ_ERROR_SHIFT (3U)
/*! IRQ_AXI_READ_ERROR - AXI Read Error Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_IRQ_AXI_READ_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_IRQ_AXI_READ_ERROR_SHIFT)) & DPR_IRQ_NONMASK_STATUS_IRQ_AXI_READ_ERROR_MASK)

#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_MASK (0x10U)
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_SHIFT (4U)
/*! DPR2RTR_YRGB_FIFO_OVFL - DPR to RTRAM YRGB Fifo Overflow Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_SHIFT)) & DPR_IRQ_NONMASK_STATUS_DPR2RTR_YRGB_FIFO_OVFL_MASK)

#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_UV_FIFO_OVFL_MASK (0x20U)
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_UV_FIFO_OVFL_SHIFT (5U)
/*! DPR2RTR_UV_FIFO_OVFL - DPR to RTRAM UV Fifo Overflow Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_UV_FIFO_OVFL(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_DPR2RTR_UV_FIFO_OVFL_SHIFT)) & DPR_IRQ_NONMASK_STATUS_DPR2RTR_UV_FIFO_OVFL_MASK)

#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK (0x40U)
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT (6U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR - DPR to RTRAM Fifo load YRGB buffer ready error Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_SHIFT)) & DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_YRGB_ERROR_MASK)

#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK (0x80U)
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT (7U)
/*! DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR - DPR to RTRAM Fifo load UV buffer ready error Non-Masked IRQ */
#define DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR(x) (((uint32_t)(((uint32_t)(x)) << DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_SHIFT)) & DPR_IRQ_NONMASK_STATUS_DPR2RTR_FIFO_LOAD_BUF_RDY_UV_ERROR_MASK)
/*! @} */

/*! @name MODE_CTRL0 - Mode Control 0 */
/*! @{ */

#define DPR_MODE_CTRL0_RTR_3BUF_EN_MASK          (0x1U)
#define DPR_MODE_CTRL0_RTR_3BUF_EN_SHIFT         (0U)
/*! RTR_3BUF_EN - RTRAM Buffer Implementation */
#define DPR_MODE_CTRL0_RTR_3BUF_EN(x)            (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_RTR_3BUF_EN_SHIFT)) & DPR_MODE_CTRL0_RTR_3BUF_EN_MASK)

#define DPR_MODE_CTRL0_RTR_4LINE_BUF_EN_MASK     (0x2U)
#define DPR_MODE_CTRL0_RTR_4LINE_BUF_EN_SHIFT    (1U)
/*! RTR_4LINE_BUF_EN - RTRAM Lines Per Buffer */
#define DPR_MODE_CTRL0_RTR_4LINE_BUF_EN(x)       (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_RTR_4LINE_BUF_EN_SHIFT)) & DPR_MODE_CTRL0_RTR_4LINE_BUF_EN_MASK)

#define DPR_MODE_CTRL0_TILE_TYPE_MASK            (0x1CU)
#define DPR_MODE_CTRL0_TILE_TYPE_SHIFT           (2U)
/*! TILE_TYPE - Tile Type */
#define DPR_MODE_CTRL0_TILE_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_TILE_TYPE_SHIFT)) & DPR_MODE_CTRL0_TILE_TYPE_MASK)

#define DPR_MODE_CTRL0_YUV_EN_MASK               (0x40U)
#define DPR_MODE_CTRL0_YUV_EN_SHIFT              (6U)
/*! YUV_EN - YUV Enable */
#define DPR_MODE_CTRL0_YUV_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_YUV_EN_SHIFT)) & DPR_MODE_CTRL0_YUV_EN_MASK)

#define DPR_MODE_CTRL0_COMP_2PLANE_EN_MASK       (0x80U)
#define DPR_MODE_CTRL0_COMP_2PLANE_EN_SHIFT      (7U)
/*! COMP_2PLANE_EN - Component 2-Plane Enable */
#define DPR_MODE_CTRL0_COMP_2PLANE_EN(x)         (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_COMP_2PLANE_EN_SHIFT)) & DPR_MODE_CTRL0_COMP_2PLANE_EN_MASK)

#define DPR_MODE_CTRL0_PIX_SIZE_MASK             (0x300U)
#define DPR_MODE_CTRL0_PIX_SIZE_SHIFT            (8U)
/*! PIX_SIZE - Pixel Size */
#define DPR_MODE_CTRL0_PIX_SIZE(x)               (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_PIX_SIZE_SHIFT)) & DPR_MODE_CTRL0_PIX_SIZE_MASK)

#define DPR_MODE_CTRL0_PIX_LUMA_UV_SWAP_MASK     (0x400U)
#define DPR_MODE_CTRL0_PIX_LUMA_UV_SWAP_SHIFT    (10U)
/*! PIX_LUMA_UV_SWAP - Pixel luma/UV position Swap */
#define DPR_MODE_CTRL0_PIX_LUMA_UV_SWAP(x)       (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_PIX_LUMA_UV_SWAP_SHIFT)) & DPR_MODE_CTRL0_PIX_LUMA_UV_SWAP_MASK)

#define DPR_MODE_CTRL0_PIX_UV_SWAP_MASK          (0x800U)
#define DPR_MODE_CTRL0_PIX_UV_SWAP_SHIFT         (11U)
/*! PIX_UV_SWAP - Pixel UV Swap */
#define DPR_MODE_CTRL0_PIX_UV_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_PIX_UV_SWAP_SHIFT)) & DPR_MODE_CTRL0_PIX_UV_SWAP_MASK)

#define DPR_MODE_CTRL0_B_COMP_SEL_MASK           (0x3000U)
#define DPR_MODE_CTRL0_B_COMP_SEL_SHIFT          (12U)
/*! B_COMP_SEL - B Component Select */
#define DPR_MODE_CTRL0_B_COMP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_B_COMP_SEL_SHIFT)) & DPR_MODE_CTRL0_B_COMP_SEL_MASK)

#define DPR_MODE_CTRL0_G_COMP_SEL_MASK           (0xC000U)
#define DPR_MODE_CTRL0_G_COMP_SEL_SHIFT          (14U)
/*! G_COMP_SEL - G Component Select */
#define DPR_MODE_CTRL0_G_COMP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_G_COMP_SEL_SHIFT)) & DPR_MODE_CTRL0_G_COMP_SEL_MASK)

#define DPR_MODE_CTRL0_R_COMP_SEL_MASK           (0x30000U)
#define DPR_MODE_CTRL0_R_COMP_SEL_SHIFT          (16U)
/*! R_COMP_SEL - R Component Select */
#define DPR_MODE_CTRL0_R_COMP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_R_COMP_SEL_SHIFT)) & DPR_MODE_CTRL0_R_COMP_SEL_MASK)

#define DPR_MODE_CTRL0_A_COMP_SEL_MASK           (0xC0000U)
#define DPR_MODE_CTRL0_A_COMP_SEL_SHIFT          (18U)
/*! A_COMP_SEL - A Component Select */
#define DPR_MODE_CTRL0_A_COMP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DPR_MODE_CTRL0_A_COMP_SEL_SHIFT)) & DPR_MODE_CTRL0_A_COMP_SEL_MASK)
/*! @} */

/*! @name FRAME_CTRL0 - Frame Control 0 */
/*! @{ */

#define DPR_FRAME_CTRL0_HFLIP_EN_MASK            (0x1U)
#define DPR_FRAME_CTRL0_HFLIP_EN_SHIFT           (0U)
/*! HFLIP_EN - Horizontal Flip Enable */
#define DPR_FRAME_CTRL0_HFLIP_EN(x)              (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_CTRL0_HFLIP_EN_SHIFT)) & DPR_FRAME_CTRL0_HFLIP_EN_MASK)

#define DPR_FRAME_CTRL0_VFLIP_EN_MASK            (0x2U)
#define DPR_FRAME_CTRL0_VFLIP_EN_SHIFT           (1U)
/*! VFLIP_EN - Vertical Flip Enable */
#define DPR_FRAME_CTRL0_VFLIP_EN(x)              (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_CTRL0_VFLIP_EN_SHIFT)) & DPR_FRAME_CTRL0_VFLIP_EN_MASK)

#define DPR_FRAME_CTRL0_ROT_ENC_MASK             (0xCU)
#define DPR_FRAME_CTRL0_ROT_ENC_SHIFT            (2U)
/*! ROT_ENC - Encoded Rotation */
#define DPR_FRAME_CTRL0_ROT_ENC(x)               (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_CTRL0_ROT_ENC_SHIFT)) & DPR_FRAME_CTRL0_ROT_ENC_MASK)

#define DPR_FRAME_CTRL0_ROT_FLIP_ORDER_EN_MASK   (0x10U)
#define DPR_FRAME_CTRL0_ROT_FLIP_ORDER_EN_SHIFT  (4U)
/*! ROT_FLIP_ORDER_EN - Rotation Flip Order */
#define DPR_FRAME_CTRL0_ROT_FLIP_ORDER_EN(x)     (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_CTRL0_ROT_FLIP_ORDER_EN_SHIFT)) & DPR_FRAME_CTRL0_ROT_FLIP_ORDER_EN_MASK)

#define DPR_FRAME_CTRL0_PITCH_MASK               (0xFFFF0000U)
#define DPR_FRAME_CTRL0_PITCH_SHIFT              (16U)
/*! PITCH - Image Pitch */
#define DPR_FRAME_CTRL0_PITCH(x)                 (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_CTRL0_PITCH_SHIFT)) & DPR_FRAME_CTRL0_PITCH_MASK)
/*! @} */

/*! @name FRAME_1P_CTRL0 - Frame 1-Plane Control 0 */
/*! @{ */

#define DPR_FRAME_1P_CTRL0_MAX_BYTES_PREQ_MASK   (0x7U)
#define DPR_FRAME_1P_CTRL0_MAX_BYTES_PREQ_SHIFT  (0U)
/*! MAX_BYTES_PREQ - Max Bytes Per Request */
#define DPR_FRAME_1P_CTRL0_MAX_BYTES_PREQ(x)     (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_CTRL0_MAX_BYTES_PREQ_SHIFT)) & DPR_FRAME_1P_CTRL0_MAX_BYTES_PREQ_MASK)
/*! @} */

/*! @name FRAME_1P_PIX_X_CTRL - Frame 1-Plane Pix X Control */
/*! @{ */

#define DPR_FRAME_1P_PIX_X_CTRL_NUM_X_PIX_WIDE_MASK (0xFFFFU)
#define DPR_FRAME_1P_PIX_X_CTRL_NUM_X_PIX_WIDE_SHIFT (0U)
/*! NUM_X_PIX_WIDE - Number of Pixels Wide in X-direction */
#define DPR_FRAME_1P_PIX_X_CTRL_NUM_X_PIX_WIDE(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_PIX_X_CTRL_NUM_X_PIX_WIDE_SHIFT)) & DPR_FRAME_1P_PIX_X_CTRL_NUM_X_PIX_WIDE_MASK)

#define DPR_FRAME_1P_PIX_X_CTRL_CROP_ULC_X_MASK  (0xFFFF0000U)
#define DPR_FRAME_1P_PIX_X_CTRL_CROP_ULC_X_SHIFT (16U)
/*! CROP_ULC_X - Starting Coordinate of Cropped Image X (1-Plane or 2-Plane Luma) */
#define DPR_FRAME_1P_PIX_X_CTRL_CROP_ULC_X(x)    (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_PIX_X_CTRL_CROP_ULC_X_SHIFT)) & DPR_FRAME_1P_PIX_X_CTRL_CROP_ULC_X_MASK)
/*! @} */

/*! @name FRAME_1P_PIX_Y_CTRL - Frame 1-Plane Pix Y Control */
/*! @{ */

#define DPR_FRAME_1P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_MASK (0xFFFFU)
#define DPR_FRAME_1P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_SHIFT (0U)
/*! NUM_Y_PIX_HIGH - Number of Pixels High in Y-direction */
#define DPR_FRAME_1P_PIX_Y_CTRL_NUM_Y_PIX_HIGH(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_SHIFT)) & DPR_FRAME_1P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_MASK)

#define DPR_FRAME_1P_PIX_Y_CTRL_CROP_ULC_Y_MASK  (0xFFFF0000U)
#define DPR_FRAME_1P_PIX_Y_CTRL_CROP_ULC_Y_SHIFT (16U)
/*! CROP_ULC_Y - Starting Coordinate of Cropped Image Y (1-Plane or 2-Plane Luma) */
#define DPR_FRAME_1P_PIX_Y_CTRL_CROP_ULC_Y(x)    (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_PIX_Y_CTRL_CROP_ULC_Y_SHIFT)) & DPR_FRAME_1P_PIX_Y_CTRL_CROP_ULC_Y_MASK)
/*! @} */

/*! @name FRAME_1P_BASE_ADDR_CTRL0 - Frame 1-Plane Base Address Control 0 */
/*! @{ */

#define DPR_FRAME_1P_BASE_ADDR_CTRL0_BASE_ADDR_MASK (0xFFFFFFFFU)
#define DPR_FRAME_1P_BASE_ADDR_CTRL0_BASE_ADDR_SHIFT (0U)
/*! BASE_ADDR - Base Address */
#define DPR_FRAME_1P_BASE_ADDR_CTRL0_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_1P_BASE_ADDR_CTRL0_BASE_ADDR_SHIFT)) & DPR_FRAME_1P_BASE_ADDR_CTRL0_BASE_ADDR_MASK)
/*! @} */

/*! @name FRAME_2P_CTRL0 - Frame 2-Plane Control 0 */
/*! @{ */

#define DPR_FRAME_2P_CTRL0_MAX_BYTES_PREQ_MASK   (0x7U)
#define DPR_FRAME_2P_CTRL0_MAX_BYTES_PREQ_SHIFT  (0U)
/*! MAX_BYTES_PREQ - Max Bytes Per Request */
#define DPR_FRAME_2P_CTRL0_MAX_BYTES_PREQ(x)     (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_CTRL0_MAX_BYTES_PREQ_SHIFT)) & DPR_FRAME_2P_CTRL0_MAX_BYTES_PREQ_MASK)
/*! @} */

/*! @name FRAME_2P_PIX_X_CTRL - Frame 2-Plane Pix X Control */
/*! @{ */

#define DPR_FRAME_2P_PIX_X_CTRL_NUM_X_PIX_WIDE_MASK (0xFFFFU)
#define DPR_FRAME_2P_PIX_X_CTRL_NUM_X_PIX_WIDE_SHIFT (0U)
/*! NUM_X_PIX_WIDE - Number of Pixels Wide in X-direction */
#define DPR_FRAME_2P_PIX_X_CTRL_NUM_X_PIX_WIDE(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_PIX_X_CTRL_NUM_X_PIX_WIDE_SHIFT)) & DPR_FRAME_2P_PIX_X_CTRL_NUM_X_PIX_WIDE_MASK)

#define DPR_FRAME_2P_PIX_X_CTRL_CROP_ULC_X_MASK  (0xFFFF0000U)
#define DPR_FRAME_2P_PIX_X_CTRL_CROP_ULC_X_SHIFT (16U)
/*! CROP_ULC_X - Starting Coordinate of Cropped Image X (2-Plane UV) */
#define DPR_FRAME_2P_PIX_X_CTRL_CROP_ULC_X(x)    (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_PIX_X_CTRL_CROP_ULC_X_SHIFT)) & DPR_FRAME_2P_PIX_X_CTRL_CROP_ULC_X_MASK)
/*! @} */

/*! @name FRAME_2P_PIX_Y_CTRL - Frame 2-Plane Pix Y Control */
/*! @{ */

#define DPR_FRAME_2P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_MASK (0xFFFFU)
#define DPR_FRAME_2P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_SHIFT (0U)
/*! NUM_Y_PIX_HIGH - Number of Pixels High in Y-direction */
#define DPR_FRAME_2P_PIX_Y_CTRL_NUM_Y_PIX_HIGH(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_SHIFT)) & DPR_FRAME_2P_PIX_Y_CTRL_NUM_Y_PIX_HIGH_MASK)

#define DPR_FRAME_2P_PIX_Y_CTRL_CROP_ULC_Y_MASK  (0xFFFF0000U)
#define DPR_FRAME_2P_PIX_Y_CTRL_CROP_ULC_Y_SHIFT (16U)
/*! CROP_ULC_Y - Starting Coordinate of Cropped Image Y (2-Plane UV) */
#define DPR_FRAME_2P_PIX_Y_CTRL_CROP_ULC_Y(x)    (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_PIX_Y_CTRL_CROP_ULC_Y_SHIFT)) & DPR_FRAME_2P_PIX_Y_CTRL_CROP_ULC_Y_MASK)
/*! @} */

/*! @name FRAME_2P_BASE_ADDR_CTRL0 - Frame 2-Plane Base Address Control 0 */
/*! @{ */

#define DPR_FRAME_2P_BASE_ADDR_CTRL0_BASE_ADDR_MASK (0xFFFFFFFFU)
#define DPR_FRAME_2P_BASE_ADDR_CTRL0_BASE_ADDR_SHIFT (0U)
/*! BASE_ADDR - Base Address */
#define DPR_FRAME_2P_BASE_ADDR_CTRL0_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << DPR_FRAME_2P_BASE_ADDR_CTRL0_BASE_ADDR_SHIFT)) & DPR_FRAME_2P_BASE_ADDR_CTRL0_BASE_ADDR_MASK)
/*! @} */

/*! @name RTRAM_CTRL0 - RTRAM Control 0 */
/*! @{ */

#define DPR_RTRAM_CTRL0_NUM_ROWS_ACTIVE_MASK     (0x1U)
#define DPR_RTRAM_CTRL0_NUM_ROWS_ACTIVE_SHIFT    (0U)
/*! NUM_ROWS_ACTIVE - Number of Rows Active */
#define DPR_RTRAM_CTRL0_NUM_ROWS_ACTIVE(x)       (((uint32_t)(((uint32_t)(x)) << DPR_RTRAM_CTRL0_NUM_ROWS_ACTIVE_SHIFT)) & DPR_RTRAM_CTRL0_NUM_ROWS_ACTIVE_MASK)

#define DPR_RTRAM_CTRL0_THRES_HIGH_MASK          (0xEU)
#define DPR_RTRAM_CTRL0_THRES_HIGH_SHIFT         (1U)
/*! THRES_HIGH - Threshold High */
#define DPR_RTRAM_CTRL0_THRES_HIGH(x)            (((uint32_t)(((uint32_t)(x)) << DPR_RTRAM_CTRL0_THRES_HIGH_SHIFT)) & DPR_RTRAM_CTRL0_THRES_HIGH_MASK)

#define DPR_RTRAM_CTRL0_THRES_LOW_MASK           (0x70U)
#define DPR_RTRAM_CTRL0_THRES_LOW_SHIFT          (4U)
/*! THRES_LOW - Threshold Low */
#define DPR_RTRAM_CTRL0_THRES_LOW(x)             (((uint32_t)(((uint32_t)(x)) << DPR_RTRAM_CTRL0_THRES_LOW_SHIFT)) & DPR_RTRAM_CTRL0_THRES_LOW_MASK)

#define DPR_RTRAM_CTRL0_ABORT_SEL_MASK           (0x80U)
#define DPR_RTRAM_CTRL0_ABORT_SEL_SHIFT          (7U)
/*! ABORT_SEL - Abort Select */
#define DPR_RTRAM_CTRL0_ABORT_SEL(x)             (((uint32_t)(((uint32_t)(x)) << DPR_RTRAM_CTRL0_ABORT_SEL_SHIFT)) & DPR_RTRAM_CTRL0_ABORT_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DPR_Register_Masks */


/*!
 * @}
 */ /* end of group DPR_Peripheral_Access_Layer */


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


#endif  /* PERI_DPR_H_ */

