/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OCOTP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCOTP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP
 *
 * CMSIS Peripheral Access Layer for OCOTP
 */

#if !defined(PERI_OCOTP_H_)
#define PERI_OCOTP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OCOTP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Peripheral_Access_Layer OCOTP Peripheral Access Layer
 * @{
 */

/** OCOTP - Register Layout Typedef */
typedef struct {
  __IO uint32_t HW_OCOTP_CTRL;                     /**< OTP Controller Control Register, offset: 0x0 */
  __IO uint32_t HW_OCOTP_CTRL_SET;                 /**< OTP Controller Control Register, offset: 0x4 */
  __IO uint32_t HW_OCOTP_CTRL_CLR;                 /**< OTP Controller Control Register, offset: 0x8 */
  __IO uint32_t HW_OCOTP_CTRL_TOG;                 /**< OTP Controller Control Register, offset: 0xC */
  __IO uint32_t HW_OCOTP_TIMING;                   /**< OTP Controller Timing Register, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t HW_OCOTP_DATA;                     /**< OTP Controller Write Data Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t HW_OCOTP_READ_CTRL;                /**< OTP Controller Write Data Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t HW_OCOTP_READ_FUSE_DATA;           /**< OTP Controller Read Data Register, offset: 0x40 */
       uint8_t RESERVED_3[28];
  __IO uint32_t HW_OCOTP_SCS;                      /**< Software Controllable Signals Register, offset: 0x60 */
  __IO uint32_t HW_OCOTP_SCS_SET;                  /**< Software Controllable Signals Register, offset: 0x64 */
  __IO uint32_t HW_OCOTP_SCS_CLR;                  /**< Software Controllable Signals Register, offset: 0x68 */
  __IO uint32_t HW_OCOTP_SCS_TOG;                  /**< Software Controllable Signals Register, offset: 0x6C */
       uint8_t RESERVED_4[32];
  __I  uint32_t HW_OCOTP_VERSION;                  /**< OTP Controller Version Register, offset: 0x90 */
       uint8_t RESERVED_5[876];
  __I  uint32_t HW_OCOTP_LOCK;                     /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
       uint8_t RESERVED_6[108];
  __IO uint32_t HW_OCOTP_BOOT_CFG0;                /**< Value of OTP Bank1 Word3 (Boot Configuration Info.), offset: 0x470 */
       uint8_t RESERVED_7[12];
  __IO uint32_t HW_OCOTP_BOOT_CFG1;                /**< Value of OTP Bank2 Word0 (Boot Configuration Info.), offset: 0x480 */
       uint8_t RESERVED_8[12];
  __IO uint32_t HW_OCOTP_BOOT_CFG2;                /**< Value of OTP Bank2 Word1 (Boot Configuration Info.), offset: 0x490 */
       uint8_t RESERVED_9[12];
  __IO uint32_t HW_OCOTP_BOOT_CFG3;                /**< Value of OTP Bank2 Word2 (Boot Configuration Info.), offset: 0x4A0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t HW_OCOTP_BOOT_CFG4;                /**< Value of OTP Bank2 Word3 (BOOT Configuration Info.), offset: 0x4B0 */
       uint8_t RESERVED_11[332];
  __IO uint32_t HW_OCOTP_SJC_RESP0;                /**< Value of OTP Bank8 Word0 (Secure JTAG Response Field), offset: 0x600 */
       uint8_t RESERVED_12[12];
  __IO uint32_t HW_OCOTP_SJC_RESP1;                /**< Value of OTP Bank8 Word1 (Secure JTAG Response Field), offset: 0x610 */
       uint8_t RESERVED_13[12];
  __IO uint32_t HW_OCOTP_USB_ID;                   /**< Value of OTP Bank8 Word2 (USB ID info), offset: 0x620 */
       uint8_t RESERVED_14[28];
  __IO uint32_t HW_OCOTP_MAC_ADDR0;                /**< Value of OTP Bank9 Word0 (MAC Address), offset: 0x640 */
       uint8_t RESERVED_15[12];
  __IO uint32_t HW_OCOTP_MAC_ADDR1;                /**< Value of OTP Bank9 Word1 (MAC Address), offset: 0x650 */
       uint8_t RESERVED_16[12];
  __IO uint32_t HW_OCOTP_MAC_ADDR2;                /**< Value of OTP Bank9 Word2 (MAC Address), offset: 0x660 */
       uint8_t RESERVED_17[284];
  __IO uint32_t HW_OCOTP_GP10;                     /**< Value of OTP Bank14 Word0 (), offset: 0x780 */
       uint8_t RESERVED_18[12];
  __IO uint32_t HW_OCOTP_GP11;                     /**< Value of OTP Bank14 Word1 (), offset: 0x790 */
       uint8_t RESERVED_19[12];
  __IO uint32_t HW_OCOTP_GP20;                     /**< Value of OTP Bank14 Word2 (), offset: 0x7A0 */
       uint8_t RESERVED_20[12];
  __IO uint32_t HW_OCOTP_GP21;                     /**< Value of OTP Bank14 Word3 (), offset: 0x7B0 */
} OCOTP_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Register_Masks OCOTP Register Masks
 * @{
 */

/*! @name HW_OCOTP_CTRL - OTP Controller Control Register */
/*! @{ */

#define OCOTP_HW_OCOTP_CTRL_ADDR_MASK            (0x1FFU)
#define OCOTP_HW_OCOTP_CTRL_ADDR_SHIFT           (0U)
#define OCOTP_HW_OCOTP_CTRL_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_ADDR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_ADDR_MASK)

#define OCOTP_HW_OCOTP_CTRL_BUSY_MASK            (0x200U)
#define OCOTP_HW_OCOTP_CTRL_BUSY_SHIFT           (9U)
#define OCOTP_HW_OCOTP_CTRL_BUSY(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_BUSY_SHIFT)) & OCOTP_HW_OCOTP_CTRL_BUSY_MASK)

#define OCOTP_HW_OCOTP_CTRL_ERROR_MASK           (0x400U)
#define OCOTP_HW_OCOTP_CTRL_ERROR_SHIFT          (10U)
#define OCOTP_HW_OCOTP_CTRL_ERROR(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_ERROR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_ERROR_MASK)

#define OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS_MASK  (0x800U)
#define OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS_SHIFT (11U)
#define OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS_SHIFT)) & OCOTP_HW_OCOTP_CTRL_RELOAD_SHADOWS_MASK)

#define OCOTP_HW_OCOTP_CTRL_WR_UNLOCK_MASK       (0xFFFF0000U)
#define OCOTP_HW_OCOTP_CTRL_WR_UNLOCK_SHIFT      (16U)
#define OCOTP_HW_OCOTP_CTRL_WR_UNLOCK(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_WR_UNLOCK_SHIFT)) & OCOTP_HW_OCOTP_CTRL_WR_UNLOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_CTRL_SET - OTP Controller Control Register */
/*! @{ */

#define OCOTP_HW_OCOTP_CTRL_SET_ADDR_MASK        (0xFFU)
#define OCOTP_HW_OCOTP_CTRL_SET_ADDR_SHIFT       (0U)
#define OCOTP_HW_OCOTP_CTRL_SET_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_SET_ADDR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_SET_ADDR_MASK)

#define OCOTP_HW_OCOTP_CTRL_SET_BUSY_MASK        (0x100U)
#define OCOTP_HW_OCOTP_CTRL_SET_BUSY_SHIFT       (8U)
#define OCOTP_HW_OCOTP_CTRL_SET_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_SET_BUSY_SHIFT)) & OCOTP_HW_OCOTP_CTRL_SET_BUSY_MASK)

#define OCOTP_HW_OCOTP_CTRL_SET_ERROR_MASK       (0x200U)
#define OCOTP_HW_OCOTP_CTRL_SET_ERROR_SHIFT      (9U)
#define OCOTP_HW_OCOTP_CTRL_SET_ERROR(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_SET_ERROR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_SET_ERROR_MASK)

#define OCOTP_HW_OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK (0x400U)
#define OCOTP_HW_OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT (10U)
#define OCOTP_HW_OCOTP_CTRL_SET_RELOAD_SHADOWS(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT)) & OCOTP_HW_OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK)

#define OCOTP_HW_OCOTP_CTRL_SET_WR_UNLOCK_MASK   (0xFFFF0000U)
#define OCOTP_HW_OCOTP_CTRL_SET_WR_UNLOCK_SHIFT  (16U)
#define OCOTP_HW_OCOTP_CTRL_SET_WR_UNLOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_SET_WR_UNLOCK_SHIFT)) & OCOTP_HW_OCOTP_CTRL_SET_WR_UNLOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_CTRL_CLR - OTP Controller Control Register */
/*! @{ */

#define OCOTP_HW_OCOTP_CTRL_CLR_ADDR_MASK        (0xFFU)
#define OCOTP_HW_OCOTP_CTRL_CLR_ADDR_SHIFT       (0U)
#define OCOTP_HW_OCOTP_CTRL_CLR_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_CLR_ADDR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_CLR_ADDR_MASK)

#define OCOTP_HW_OCOTP_CTRL_CLR_BUSY_MASK        (0x100U)
#define OCOTP_HW_OCOTP_CTRL_CLR_BUSY_SHIFT       (8U)
#define OCOTP_HW_OCOTP_CTRL_CLR_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_CLR_BUSY_SHIFT)) & OCOTP_HW_OCOTP_CTRL_CLR_BUSY_MASK)

#define OCOTP_HW_OCOTP_CTRL_CLR_ERROR_MASK       (0x200U)
#define OCOTP_HW_OCOTP_CTRL_CLR_ERROR_SHIFT      (9U)
#define OCOTP_HW_OCOTP_CTRL_CLR_ERROR(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_CLR_ERROR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_CLR_ERROR_MASK)

#define OCOTP_HW_OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK (0x400U)
#define OCOTP_HW_OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT (10U)
#define OCOTP_HW_OCOTP_CTRL_CLR_RELOAD_SHADOWS(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT)) & OCOTP_HW_OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK)

#define OCOTP_HW_OCOTP_CTRL_CLR_WR_UNLOCK_MASK   (0xFFFF0000U)
#define OCOTP_HW_OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT  (16U)
#define OCOTP_HW_OCOTP_CTRL_CLR_WR_UNLOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT)) & OCOTP_HW_OCOTP_CTRL_CLR_WR_UNLOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_CTRL_TOG - OTP Controller Control Register */
/*! @{ */

#define OCOTP_HW_OCOTP_CTRL_TOG_ADDR_MASK        (0xFFU)
#define OCOTP_HW_OCOTP_CTRL_TOG_ADDR_SHIFT       (0U)
#define OCOTP_HW_OCOTP_CTRL_TOG_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_TOG_ADDR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_TOG_ADDR_MASK)

#define OCOTP_HW_OCOTP_CTRL_TOG_BUSY_MASK        (0x100U)
#define OCOTP_HW_OCOTP_CTRL_TOG_BUSY_SHIFT       (8U)
#define OCOTP_HW_OCOTP_CTRL_TOG_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_TOG_BUSY_SHIFT)) & OCOTP_HW_OCOTP_CTRL_TOG_BUSY_MASK)

#define OCOTP_HW_OCOTP_CTRL_TOG_ERROR_MASK       (0x200U)
#define OCOTP_HW_OCOTP_CTRL_TOG_ERROR_SHIFT      (9U)
#define OCOTP_HW_OCOTP_CTRL_TOG_ERROR(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_TOG_ERROR_SHIFT)) & OCOTP_HW_OCOTP_CTRL_TOG_ERROR_MASK)

#define OCOTP_HW_OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK (0x400U)
#define OCOTP_HW_OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT (10U)
#define OCOTP_HW_OCOTP_CTRL_TOG_RELOAD_SHADOWS(x) (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT)) & OCOTP_HW_OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK)

#define OCOTP_HW_OCOTP_CTRL_TOG_WR_UNLOCK_MASK   (0xFFFF0000U)
#define OCOTP_HW_OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT  (16U)
#define OCOTP_HW_OCOTP_CTRL_TOG_WR_UNLOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT)) & OCOTP_HW_OCOTP_CTRL_TOG_WR_UNLOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_TIMING - OTP Controller Timing Register */
/*! @{ */

#define OCOTP_HW_OCOTP_TIMING_STROBE_PROG_MASK   (0xFFFU)
#define OCOTP_HW_OCOTP_TIMING_STROBE_PROG_SHIFT  (0U)
#define OCOTP_HW_OCOTP_TIMING_STROBE_PROG(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_TIMING_STROBE_PROG_SHIFT)) & OCOTP_HW_OCOTP_TIMING_STROBE_PROG_MASK)

#define OCOTP_HW_OCOTP_TIMING_RELAX_MASK         (0xF000U)
#define OCOTP_HW_OCOTP_TIMING_RELAX_SHIFT        (12U)
#define OCOTP_HW_OCOTP_TIMING_RELAX(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_TIMING_RELAX_SHIFT)) & OCOTP_HW_OCOTP_TIMING_RELAX_MASK)

#define OCOTP_HW_OCOTP_TIMING_STROBE_READ_MASK   (0x3F0000U)
#define OCOTP_HW_OCOTP_TIMING_STROBE_READ_SHIFT  (16U)
#define OCOTP_HW_OCOTP_TIMING_STROBE_READ(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_TIMING_STROBE_READ_SHIFT)) & OCOTP_HW_OCOTP_TIMING_STROBE_READ_MASK)

#define OCOTP_HW_OCOTP_TIMING_WAIT_MASK          (0xFC00000U)
#define OCOTP_HW_OCOTP_TIMING_WAIT_SHIFT         (22U)
#define OCOTP_HW_OCOTP_TIMING_WAIT(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_TIMING_WAIT_SHIFT)) & OCOTP_HW_OCOTP_TIMING_WAIT_MASK)
/*! @} */

/*! @name HW_OCOTP_DATA - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_HW_OCOTP_DATA_DATA_MASK            (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_DATA_DATA_SHIFT           (0U)
#define OCOTP_HW_OCOTP_DATA_DATA(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_DATA_DATA_SHIFT)) & OCOTP_HW_OCOTP_DATA_DATA_MASK)
/*! @} */

/*! @name HW_OCOTP_READ_CTRL - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE_MASK  (0x1U)
#define OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE_SHIFT (0U)
#define OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE_SHIFT)) & OCOTP_HW_OCOTP_READ_CTRL_READ_FUSE_MASK)
/*! @} */

/*! @name HW_OCOTP_READ_FUSE_DATA - OTP Controller Read Data Register */
/*! @{ */

#define OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA_MASK  (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA_SHIFT (0U)
#define OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA(x)    (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA_SHIFT)) & OCOTP_HW_OCOTP_READ_FUSE_DATA_DATA_MASK)
/*! @} */

/*! @name HW_OCOTP_SCS - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_HW_OCOTP_SCS_HAB_JDE_MASK          (0x1U)
#define OCOTP_HW_OCOTP_SCS_HAB_JDE_SHIFT         (0U)
#define OCOTP_HW_OCOTP_SCS_HAB_JDE(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_HAB_JDE_SHIFT)) & OCOTP_HW_OCOTP_SCS_HAB_JDE_MASK)

#define OCOTP_HW_OCOTP_SCS_SPARE_MASK            (0x7FFFFFFEU)
#define OCOTP_HW_OCOTP_SCS_SPARE_SHIFT           (1U)
#define OCOTP_HW_OCOTP_SCS_SPARE(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_SPARE_SHIFT)) & OCOTP_HW_OCOTP_SCS_SPARE_MASK)

#define OCOTP_HW_OCOTP_SCS_LOCK_MASK             (0x80000000U)
#define OCOTP_HW_OCOTP_SCS_LOCK_SHIFT            (31U)
#define OCOTP_HW_OCOTP_SCS_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_LOCK_SHIFT)) & OCOTP_HW_OCOTP_SCS_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_SCS_SET - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_HW_OCOTP_SCS_SET_SPARE_MASK        (0x7FFFFFFEU)
#define OCOTP_HW_OCOTP_SCS_SET_SPARE_SHIFT       (1U)
#define OCOTP_HW_OCOTP_SCS_SET_SPARE(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_SET_SPARE_SHIFT)) & OCOTP_HW_OCOTP_SCS_SET_SPARE_MASK)

#define OCOTP_HW_OCOTP_SCS_SET_LOCK_MASK         (0x80000000U)
#define OCOTP_HW_OCOTP_SCS_SET_LOCK_SHIFT        (31U)
#define OCOTP_HW_OCOTP_SCS_SET_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_SET_LOCK_SHIFT)) & OCOTP_HW_OCOTP_SCS_SET_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_SCS_CLR - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_HW_OCOTP_SCS_CLR_SPARE_MASK        (0x7FFFFFFEU)
#define OCOTP_HW_OCOTP_SCS_CLR_SPARE_SHIFT       (1U)
#define OCOTP_HW_OCOTP_SCS_CLR_SPARE(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_CLR_SPARE_SHIFT)) & OCOTP_HW_OCOTP_SCS_CLR_SPARE_MASK)

#define OCOTP_HW_OCOTP_SCS_CLR_LOCK_MASK         (0x80000000U)
#define OCOTP_HW_OCOTP_SCS_CLR_LOCK_SHIFT        (31U)
#define OCOTP_HW_OCOTP_SCS_CLR_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_CLR_LOCK_SHIFT)) & OCOTP_HW_OCOTP_SCS_CLR_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_SCS_TOG - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_HW_OCOTP_SCS_TOG_SPARE_MASK        (0x7FFFFFFEU)
#define OCOTP_HW_OCOTP_SCS_TOG_SPARE_SHIFT       (1U)
#define OCOTP_HW_OCOTP_SCS_TOG_SPARE(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_TOG_SPARE_SHIFT)) & OCOTP_HW_OCOTP_SCS_TOG_SPARE_MASK)

#define OCOTP_HW_OCOTP_SCS_TOG_LOCK_MASK         (0x80000000U)
#define OCOTP_HW_OCOTP_SCS_TOG_LOCK_SHIFT        (31U)
#define OCOTP_HW_OCOTP_SCS_TOG_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SCS_TOG_LOCK_SHIFT)) & OCOTP_HW_OCOTP_SCS_TOG_LOCK_MASK)
/*! @} */

/*! @name HW_OCOTP_VERSION - OTP Controller Version Register */
/*! @{ */

#define OCOTP_HW_OCOTP_VERSION_STEP_MASK         (0xFFFFU)
#define OCOTP_HW_OCOTP_VERSION_STEP_SHIFT        (0U)
#define OCOTP_HW_OCOTP_VERSION_STEP(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_VERSION_STEP_SHIFT)) & OCOTP_HW_OCOTP_VERSION_STEP_MASK)

#define OCOTP_HW_OCOTP_VERSION_MINOR_MASK        (0xFF0000U)
#define OCOTP_HW_OCOTP_VERSION_MINOR_SHIFT       (16U)
#define OCOTP_HW_OCOTP_VERSION_MINOR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_VERSION_MINOR_SHIFT)) & OCOTP_HW_OCOTP_VERSION_MINOR_MASK)

#define OCOTP_HW_OCOTP_VERSION_MAJOR_MASK        (0xFF000000U)
#define OCOTP_HW_OCOTP_VERSION_MAJOR_SHIFT       (24U)
#define OCOTP_HW_OCOTP_VERSION_MAJOR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_VERSION_MAJOR_SHIFT)) & OCOTP_HW_OCOTP_VERSION_MAJOR_MASK)
/*! @} */

/*! @name HW_OCOTP_LOCK - Value of OTP Bank0 Word0 (Lock controls) */
/*! @{ */

#define OCOTP_HW_OCOTP_LOCK_BOOT_CFG_MASK        (0xCU)
#define OCOTP_HW_OCOTP_LOCK_BOOT_CFG_SHIFT       (2U)
#define OCOTP_HW_OCOTP_LOCK_BOOT_CFG(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_BOOT_CFG_SHIFT)) & OCOTP_HW_OCOTP_LOCK_BOOT_CFG_MASK)

#define OCOTP_HW_OCOTP_LOCK_SJC_RESP_MASK        (0x400U)
#define OCOTP_HW_OCOTP_LOCK_SJC_RESP_SHIFT       (10U)
#define OCOTP_HW_OCOTP_LOCK_SJC_RESP(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_SJC_RESP_SHIFT)) & OCOTP_HW_OCOTP_LOCK_SJC_RESP_MASK)

#define OCOTP_HW_OCOTP_LOCK_USB_ID_MASK          (0x3000U)
#define OCOTP_HW_OCOTP_LOCK_USB_ID_SHIFT         (12U)
#define OCOTP_HW_OCOTP_LOCK_USB_ID(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_USB_ID_SHIFT)) & OCOTP_HW_OCOTP_LOCK_USB_ID_MASK)

#define OCOTP_HW_OCOTP_LOCK_MAC_ADDR_MASK        (0xC000U)
#define OCOTP_HW_OCOTP_LOCK_MAC_ADDR_SHIFT       (14U)
#define OCOTP_HW_OCOTP_LOCK_MAC_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_MAC_ADDR_SHIFT)) & OCOTP_HW_OCOTP_LOCK_MAC_ADDR_MASK)

#define OCOTP_HW_OCOTP_LOCK_GP1_MASK             (0x300000U)
#define OCOTP_HW_OCOTP_LOCK_GP1_SHIFT            (20U)
#define OCOTP_HW_OCOTP_LOCK_GP1(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_GP1_SHIFT)) & OCOTP_HW_OCOTP_LOCK_GP1_MASK)

#define OCOTP_HW_OCOTP_LOCK_GP2_MASK             (0xC00000U)
#define OCOTP_HW_OCOTP_LOCK_GP2_SHIFT            (22U)
#define OCOTP_HW_OCOTP_LOCK_GP2(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_LOCK_GP2_SHIFT)) & OCOTP_HW_OCOTP_LOCK_GP2_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT_CFG0 - Value of OTP Bank1 Word3 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_HW_OCOTP_BOOT_CFG0_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_BOOT_CFG0_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_BOOT_CFG0_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_BOOT_CFG0_BITS_SHIFT)) & OCOTP_HW_OCOTP_BOOT_CFG0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT_CFG1 - Value of OTP Bank2 Word0 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_HW_OCOTP_BOOT_CFG1_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_BOOT_CFG1_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_BOOT_CFG1_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_BOOT_CFG1_BITS_SHIFT)) & OCOTP_HW_OCOTP_BOOT_CFG1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT_CFG2 - Value of OTP Bank2 Word1 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_HW_OCOTP_BOOT_CFG2_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_BOOT_CFG2_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_BOOT_CFG2_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_BOOT_CFG2_BITS_SHIFT)) & OCOTP_HW_OCOTP_BOOT_CFG2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT_CFG3 - Value of OTP Bank2 Word2 (Boot Configuration Info.) */
/*! @{ */

#define OCOTP_HW_OCOTP_BOOT_CFG3_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_BOOT_CFG3_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_BOOT_CFG3_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_BOOT_CFG3_BITS_SHIFT)) & OCOTP_HW_OCOTP_BOOT_CFG3_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_BOOT_CFG4 - Value of OTP Bank2 Word3 (BOOT Configuration Info.) */
/*! @{ */

#define OCOTP_HW_OCOTP_BOOT_CFG4_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_BOOT_CFG4_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_BOOT_CFG4_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_BOOT_CFG4_BITS_SHIFT)) & OCOTP_HW_OCOTP_BOOT_CFG4_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_SJC_RESP0 - Value of OTP Bank8 Word0 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_HW_OCOTP_SJC_RESP0_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_SJC_RESP0_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_SJC_RESP0_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SJC_RESP0_BITS_SHIFT)) & OCOTP_HW_OCOTP_SJC_RESP0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_SJC_RESP1 - Value of OTP Bank8 Word1 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_HW_OCOTP_SJC_RESP1_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_SJC_RESP1_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_SJC_RESP1_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_SJC_RESP1_BITS_SHIFT)) & OCOTP_HW_OCOTP_SJC_RESP1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_USB_ID - Value of OTP Bank8 Word2 (USB ID info) */
/*! @{ */

#define OCOTP_HW_OCOTP_USB_ID_BITS_MASK          (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_USB_ID_BITS_SHIFT         (0U)
#define OCOTP_HW_OCOTP_USB_ID_BITS(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_USB_ID_BITS_SHIFT)) & OCOTP_HW_OCOTP_USB_ID_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_MAC_ADDR0 - Value of OTP Bank9 Word0 (MAC Address) */
/*! @{ */

#define OCOTP_HW_OCOTP_MAC_ADDR0_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_MAC_ADDR0_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_MAC_ADDR0_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_MAC_ADDR0_BITS_SHIFT)) & OCOTP_HW_OCOTP_MAC_ADDR0_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_MAC_ADDR1 - Value of OTP Bank9 Word1 (MAC Address) */
/*! @{ */

#define OCOTP_HW_OCOTP_MAC_ADDR1_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_MAC_ADDR1_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_MAC_ADDR1_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_MAC_ADDR1_BITS_SHIFT)) & OCOTP_HW_OCOTP_MAC_ADDR1_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_MAC_ADDR2 - Value of OTP Bank9 Word2 (MAC Address) */
/*! @{ */

#define OCOTP_HW_OCOTP_MAC_ADDR2_BITS_MASK       (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_MAC_ADDR2_BITS_SHIFT      (0U)
#define OCOTP_HW_OCOTP_MAC_ADDR2_BITS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_MAC_ADDR2_BITS_SHIFT)) & OCOTP_HW_OCOTP_MAC_ADDR2_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP10 - Value of OTP Bank14 Word0 () */
/*! @{ */

#define OCOTP_HW_OCOTP_GP10_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_GP10_BITS_SHIFT           (0U)
#define OCOTP_HW_OCOTP_GP10_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_GP10_BITS_SHIFT)) & OCOTP_HW_OCOTP_GP10_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP11 - Value of OTP Bank14 Word1 () */
/*! @{ */

#define OCOTP_HW_OCOTP_GP11_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_GP11_BITS_SHIFT           (0U)
#define OCOTP_HW_OCOTP_GP11_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_GP11_BITS_SHIFT)) & OCOTP_HW_OCOTP_GP11_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP20 - Value of OTP Bank14 Word2 () */
/*! @{ */

#define OCOTP_HW_OCOTP_GP20_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_GP20_BITS_SHIFT           (0U)
#define OCOTP_HW_OCOTP_GP20_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_GP20_BITS_SHIFT)) & OCOTP_HW_OCOTP_GP20_BITS_MASK)
/*! @} */

/*! @name HW_OCOTP_GP21 - Value of OTP Bank14 Word3 () */
/*! @{ */

#define OCOTP_HW_OCOTP_GP21_BITS_MASK            (0xFFFFFFFFU)
#define OCOTP_HW_OCOTP_GP21_BITS_SHIFT           (0U)
#define OCOTP_HW_OCOTP_GP21_BITS(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_HW_OCOTP_GP21_BITS_SHIFT)) & OCOTP_HW_OCOTP_GP21_BITS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_Register_Masks */


/*!
 * @}
 */ /* end of group OCOTP_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OCOTP_H_ */

