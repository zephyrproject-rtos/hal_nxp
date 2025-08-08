/*
** ###################################################################
**     Processors:          MIMXRT1015CAF4A
**                          MIMXRT1015CAF4B
**                          MIMXRT1015DAF5A
**                          MIMXRT1015DAF5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 0.1 (2018-11-05)
**         Initial version.
**     - rev. 1.0 (2019-01-18)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-02-20)
**         Update register SRC_SRSR's bitfield LOCKUP_SYSRESETREQ to LOCKUP.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1015RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCOTP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP
 *
 * CMSIS Peripheral Access Layer for OCOTP
 */

#if !defined(PERI_OCOTP_H_)
#define PERI_OCOTP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1015CAF4A) || defined(CPU_MIMXRT1015CAF4B) || defined(CPU_MIMXRT1015DAF5A) || defined(CPU_MIMXRT1015DAF5B))
#include "MIMXRT1015_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
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
  __IO uint32_t CTRL;                              /**< OTP Controller Control and Status Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< OTP Controller Control and Status Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< OTP Controller Control and Status Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< OTP Controller Control and Status Register, offset: 0xC */
  __IO uint32_t TIMING;                            /**< OTP Controller Timing Register, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DATA;                              /**< OTP Controller Write Data Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t READ_CTRL;                         /**< OTP Controller Write Data Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t READ_FUSE_DATA;                    /**< OTP Controller Read Data Register, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t SW_STICKY;                         /**< Sticky bit Register, offset: 0x50 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SCS;                               /**< Software Controllable Signals Register, offset: 0x60 */
  __IO uint32_t SCS_SET;                           /**< Software Controllable Signals Register, offset: 0x64 */
  __IO uint32_t SCS_CLR;                           /**< Software Controllable Signals Register, offset: 0x68 */
  __IO uint32_t SCS_TOG;                           /**< Software Controllable Signals Register, offset: 0x6C */
       uint8_t RESERVED_5[32];
  __I  uint32_t VERSION;                           /**< OTP Controller Version Register, offset: 0x90 */
       uint8_t RESERVED_6[108];
  __IO uint32_t TIMING2;                           /**< OTP Controller Timing Register 2, offset: 0x100 */
       uint8_t RESERVED_7[764];
  __IO uint32_t LOCK;                              /**< Value of OTP Bank0 Word0 (Lock controls), offset: 0x400 */
       uint8_t RESERVED_8[12];
  __IO uint32_t CFG0;                              /**< Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.), offset: 0x410 */
       uint8_t RESERVED_9[12];
  __IO uint32_t CFG1;                              /**< Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.), offset: 0x420 */
       uint8_t RESERVED_10[12];
  __IO uint32_t CFG2;                              /**< Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.), offset: 0x430 */
       uint8_t RESERVED_11[12];
  __IO uint32_t CFG3;                              /**< Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.), offset: 0x440 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CFG4;                              /**< Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.), offset: 0x450 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CFG5;                              /**< Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.), offset: 0x460 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CFG6;                              /**< Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.), offset: 0x470 */
       uint8_t RESERVED_15[12];
  __IO uint32_t MEM0;                              /**< Value of OTP Bank1 Word0 (Memory Related Info.), offset: 0x480 */
       uint8_t RESERVED_16[12];
  __IO uint32_t MEM1;                              /**< Value of OTP Bank1 Word1 (Memory Related Info.), offset: 0x490 */
       uint8_t RESERVED_17[12];
  __IO uint32_t MEM2;                              /**< Value of OTP Bank1 Word2 (Memory Related Info.), offset: 0x4A0 */
       uint8_t RESERVED_18[12];
  __IO uint32_t MEM3;                              /**< Value of OTP Bank1 Word3 (Memory Related Info.), offset: 0x4B0 */
       uint8_t RESERVED_19[12];
  __IO uint32_t MEM4;                              /**< Value of OTP Bank 1 Word 4 (Memory Related Info.), offset: 0x4C0 */
       uint8_t RESERVED_20[12];
  __IO uint32_t ANA0;                              /**< Value of OTP Bank 1 Word 5 (Analog Info.), offset: 0x4D0 */
       uint8_t RESERVED_21[12];
  __IO uint32_t ANA1;                              /**< Value of OTP Bank 1 Word 6 (Analog Info.), offset: 0x4E0 */
       uint8_t RESERVED_22[12];
  __IO uint32_t ANA2;                              /**< Value of OTP Bank 1 Word 7 (Analog Info.), offset: 0x4F0 */
       uint8_t RESERVED_23[140];
  __IO uint32_t SRK0;                              /**< Shadow Register for OTP Bank3 Word0 (SRK Hash), offset: 0x580 */
       uint8_t RESERVED_24[12];
  __IO uint32_t SRK1;                              /**< Shadow Register for OTP Bank3 Word1 (SRK Hash), offset: 0x590 */
       uint8_t RESERVED_25[12];
  __IO uint32_t SRK2;                              /**< Shadow Register for OTP Bank3 Word2 (SRK Hash), offset: 0x5A0 */
       uint8_t RESERVED_26[12];
  __IO uint32_t SRK3;                              /**< Shadow Register for OTP Bank3 Word3 (SRK Hash), offset: 0x5B0 */
       uint8_t RESERVED_27[12];
  __IO uint32_t SRK4;                              /**< Shadow Register for OTP Bank3 Word4 (SRK Hash), offset: 0x5C0 */
       uint8_t RESERVED_28[12];
  __IO uint32_t SRK5;                              /**< Shadow Register for OTP Bank3 Word5 (SRK Hash), offset: 0x5D0 */
       uint8_t RESERVED_29[12];
  __IO uint32_t SRK6;                              /**< Shadow Register for OTP Bank3 Word6 (SRK Hash), offset: 0x5E0 */
       uint8_t RESERVED_30[12];
  __IO uint32_t SRK7;                              /**< Shadow Register for OTP Bank3 Word7 (SRK Hash), offset: 0x5F0 */
       uint8_t RESERVED_31[12];
  __IO uint32_t SJC_RESP0;                         /**< Value of OTP Bank4 Word0 (Secure JTAG Response Field), offset: 0x600 */
       uint8_t RESERVED_32[12];
  __IO uint32_t SJC_RESP1;                         /**< Value of OTP Bank4 Word1 (Secure JTAG Response Field), offset: 0x610 */
       uint8_t RESERVED_33[12];
  __IO uint32_t MAC0;                              /**< Value of OTP Bank4 Word2 (MAC Address), offset: 0x620 */
       uint8_t RESERVED_34[12];
  __IO uint32_t MAC1;                              /**< Value of OTP Bank4 Word3 (MAC Address), offset: 0x630 */
       uint8_t RESERVED_35[12];
  __IO uint32_t GP3;                               /**< Value of OTP Bank4 Word4 (MAC Address), offset: 0x640 */
       uint8_t RESERVED_36[28];
  __IO uint32_t GP1;                               /**< Value of OTP Bank4 Word6 (General Purpose Customer Defined Info), offset: 0x660 */
       uint8_t RESERVED_37[12];
  __IO uint32_t GP2;                               /**< Value of OTP Bank4 Word7 (General Purpose Customer Defined Info), offset: 0x670 */
       uint8_t RESERVED_38[12];
  __IO uint32_t SW_GP1;                            /**< Value of OTP Bank5 Word0 (SW GP1), offset: 0x680 */
       uint8_t RESERVED_39[12];
  __IO uint32_t SW_GP20;                           /**< Value of OTP Bank5 Word1 (SW GP2), offset: 0x690 */
       uint8_t RESERVED_40[12];
  __IO uint32_t SW_GP21;                           /**< Value of OTP Bank5 Word2 (SW GP2), offset: 0x6A0 */
       uint8_t RESERVED_41[12];
  __IO uint32_t SW_GP22;                           /**< Value of OTP Bank5 Word3 (SW GP2), offset: 0x6B0 */
       uint8_t RESERVED_42[12];
  __IO uint32_t SW_GP23;                           /**< Value of OTP Bank5 Word4 (SW GP2), offset: 0x6C0 */
       uint8_t RESERVED_43[12];
  __IO uint32_t MISC_CONF0;                        /**< Value of OTP Bank5 Word5 (Misc Conf), offset: 0x6D0 */
       uint8_t RESERVED_44[12];
  __IO uint32_t MISC_CONF1;                        /**< Value of OTP Bank5 Word6 (Misc Conf), offset: 0x6E0 */
       uint8_t RESERVED_45[12];
  __IO uint32_t SRK_REVOKE;                        /**< Value of OTP Bank5 Word7 (SRK Revoke), offset: 0x6F0 */
} OCOTP_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Register_Masks OCOTP Register Masks
 * @{
 */

/*! @name CTRL - OTP Controller Control and Status Register */
/*! @{ */

#define OCOTP_CTRL_ADDR_MASK                     (0x3FU)
#define OCOTP_CTRL_ADDR_SHIFT                    (0U)
/*! ADDR - OTP write and read access address register */
#define OCOTP_CTRL_ADDR(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_ADDR_SHIFT)) & OCOTP_CTRL_ADDR_MASK)

#define OCOTP_CTRL_BUSY_MASK                     (0x100U)
#define OCOTP_CTRL_BUSY_SHIFT                    (8U)
/*! BUSY - OTP controller status bit
 *  0b0..No write or read access to OTP started.
 *  0b1..Write or read access to OTP started.
 */
#define OCOTP_CTRL_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_BUSY_SHIFT)) & OCOTP_CTRL_BUSY_MASK)

#define OCOTP_CTRL_ERROR_MASK                    (0x200U)
#define OCOTP_CTRL_ERROR_SHIFT                   (9U)
/*! ERROR - Locked Region Access Error
 *  0b0..No error.
 *  0b1..Error - access to a locked region requested.
 */
#define OCOTP_CTRL_ERROR(x)                      (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_ERROR_SHIFT)) & OCOTP_CTRL_ERROR_MASK)

#define OCOTP_CTRL_RELOAD_SHADOWS_MASK           (0x400U)
#define OCOTP_CTRL_RELOAD_SHADOWS_SHIFT          (10U)
/*! RELOAD_SHADOWS - Reload Shadow Registers
 *  0b0..Do not force shadow register re-load.
 *  0b1..Force shadow register re-load. This bit is cleared automatically after shadow registers are re-loaded.
 */
#define OCOTP_CTRL_RELOAD_SHADOWS(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_WR_UNLOCK_MASK                (0xFFFF0000U)
#define OCOTP_CTRL_WR_UNLOCK_SHIFT               (16U)
/*! WR_UNLOCK - Write Unlock
 *  0b0000000000000000..OTP write access is locked.
 *  0b0011111001110111..OTP write access is unlocked.
 */
#define OCOTP_CTRL_WR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_SET - OTP Controller Control and Status Register */
/*! @{ */

#define OCOTP_CTRL_SET_ADDR_MASK                 (0x3FU)
#define OCOTP_CTRL_SET_ADDR_SHIFT                (0U)
/*! ADDR - OTP write and read access address register */
#define OCOTP_CTRL_SET_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_ADDR_SHIFT)) & OCOTP_CTRL_SET_ADDR_MASK)

#define OCOTP_CTRL_SET_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_SET_BUSY_SHIFT                (8U)
/*! BUSY - OTP controller status bit */
#define OCOTP_CTRL_SET_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_BUSY_SHIFT)) & OCOTP_CTRL_SET_BUSY_MASK)

#define OCOTP_CTRL_SET_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_SET_ERROR_SHIFT               (9U)
/*! ERROR - Locked Region Access Error */
#define OCOTP_CTRL_SET_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_ERROR_SHIFT)) & OCOTP_CTRL_SET_ERROR_MASK)

#define OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT      (10U)
/*! RELOAD_SHADOWS - Reload Shadow Registers */
#define OCOTP_CTRL_SET_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_SET_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_SET_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_SET_WR_UNLOCK_SHIFT           (16U)
/*! WR_UNLOCK - Write Unlock */
#define OCOTP_CTRL_SET_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SET_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_SET_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_CLR - OTP Controller Control and Status Register */
/*! @{ */

#define OCOTP_CTRL_CLR_ADDR_MASK                 (0x3FU)
#define OCOTP_CTRL_CLR_ADDR_SHIFT                (0U)
/*! ADDR - OTP write and read access address register */
#define OCOTP_CTRL_CLR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_ADDR_SHIFT)) & OCOTP_CTRL_CLR_ADDR_MASK)

#define OCOTP_CTRL_CLR_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_CLR_BUSY_SHIFT                (8U)
/*! BUSY - OTP controller status bit */
#define OCOTP_CTRL_CLR_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_BUSY_SHIFT)) & OCOTP_CTRL_CLR_BUSY_MASK)

#define OCOTP_CTRL_CLR_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_CLR_ERROR_SHIFT               (9U)
/*! ERROR - Locked Region Access Error */
#define OCOTP_CTRL_CLR_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_ERROR_SHIFT)) & OCOTP_CTRL_CLR_ERROR_MASK)

#define OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT      (10U)
/*! RELOAD_SHADOWS - Reload Shadow Registers */
#define OCOTP_CTRL_CLR_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_CLR_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_CLR_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT           (16U)
/*! WR_UNLOCK - Write Unlock */
#define OCOTP_CTRL_CLR_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_CLR_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_CLR_WR_UNLOCK_MASK)
/*! @} */

/*! @name CTRL_TOG - OTP Controller Control and Status Register */
/*! @{ */

#define OCOTP_CTRL_TOG_ADDR_MASK                 (0x3FU)
#define OCOTP_CTRL_TOG_ADDR_SHIFT                (0U)
/*! ADDR - OTP write and read access address register */
#define OCOTP_CTRL_TOG_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_ADDR_SHIFT)) & OCOTP_CTRL_TOG_ADDR_MASK)

#define OCOTP_CTRL_TOG_BUSY_MASK                 (0x100U)
#define OCOTP_CTRL_TOG_BUSY_SHIFT                (8U)
/*! BUSY - OTP controller status bit */
#define OCOTP_CTRL_TOG_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_BUSY_SHIFT)) & OCOTP_CTRL_TOG_BUSY_MASK)

#define OCOTP_CTRL_TOG_ERROR_MASK                (0x200U)
#define OCOTP_CTRL_TOG_ERROR_SHIFT               (9U)
/*! ERROR - Locked Region Access Error */
#define OCOTP_CTRL_TOG_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_ERROR_SHIFT)) & OCOTP_CTRL_TOG_ERROR_MASK)

#define OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK       (0x400U)
#define OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT      (10U)
/*! RELOAD_SHADOWS - Reload Shadow Registers */
#define OCOTP_CTRL_TOG_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_RELOAD_SHADOWS_SHIFT)) & OCOTP_CTRL_TOG_RELOAD_SHADOWS_MASK)

#define OCOTP_CTRL_TOG_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT           (16U)
/*! WR_UNLOCK - Write Unlock */
#define OCOTP_CTRL_TOG_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_TOG_WR_UNLOCK_SHIFT)) & OCOTP_CTRL_TOG_WR_UNLOCK_MASK)
/*! @} */

/*! @name TIMING - OTP Controller Timing Register */
/*! @{ */

#define OCOTP_TIMING_STROBE_PROG_MASK            (0xFFFU)
#define OCOTP_TIMING_STROBE_PROG_SHIFT           (0U)
/*! STROBE_PROG - Write Strobe Period */
#define OCOTP_TIMING_STROBE_PROG(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_STROBE_PROG_SHIFT)) & OCOTP_TIMING_STROBE_PROG_MASK)

#define OCOTP_TIMING_RELAX_MASK                  (0xF000U)
#define OCOTP_TIMING_RELAX_SHIFT                 (12U)
/*! RELAX - Relax Count Value */
#define OCOTP_TIMING_RELAX(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_RELAX_SHIFT)) & OCOTP_TIMING_RELAX_MASK)

#define OCOTP_TIMING_STROBE_READ_MASK            (0x3F0000U)
#define OCOTP_TIMING_STROBE_READ_SHIFT           (16U)
/*! STROBE_READ - Read Strobe Period */
#define OCOTP_TIMING_STROBE_READ(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_STROBE_READ_SHIFT)) & OCOTP_TIMING_STROBE_READ_MASK)

#define OCOTP_TIMING_WAIT_MASK                   (0xFC00000U)
#define OCOTP_TIMING_WAIT_SHIFT                  (22U)
/*! WAIT - Wait Interval */
#define OCOTP_TIMING_WAIT(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING_WAIT_SHIFT)) & OCOTP_TIMING_WAIT_MASK)
/*! @} */

/*! @name DATA - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_DATA_DATA_MASK                     (0xFFFFFFFFU)
#define OCOTP_DATA_DATA_SHIFT                    (0U)
/*! DATA - Data */
#define OCOTP_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DATA_DATA_SHIFT)) & OCOTP_DATA_DATA_MASK)
/*! @} */

/*! @name READ_CTRL - OTP Controller Write Data Register */
/*! @{ */

#define OCOTP_READ_CTRL_READ_FUSE_MASK           (0x1U)
#define OCOTP_READ_CTRL_READ_FUSE_SHIFT          (0U)
/*! READ_FUSE - Read Fuse */
#define OCOTP_READ_CTRL_READ_FUSE(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_READ_CTRL_READ_FUSE_SHIFT)) & OCOTP_READ_CTRL_READ_FUSE_MASK)
/*! @} */

/*! @name READ_FUSE_DATA - OTP Controller Read Data Register */
/*! @{ */

#define OCOTP_READ_FUSE_DATA_DATA_MASK           (0xFFFFFFFFU)
#define OCOTP_READ_FUSE_DATA_DATA_SHIFT          (0U)
/*! DATA - Data */
#define OCOTP_READ_FUSE_DATA_DATA(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_READ_FUSE_DATA_DATA_SHIFT)) & OCOTP_READ_FUSE_DATA_DATA_MASK)
/*! @} */

/*! @name SW_STICKY - Sticky bit Register */
/*! @{ */

#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK_MASK     (0x2U)
#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK_SHIFT    (1U)
/*! SRK_REVOKE_LOCK - SRK Revoke Lock
 *  0b0..The writing of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..The writing of this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
 */
#define OCOTP_SW_STICKY_SRK_REVOKE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_SRK_REVOKE_LOCK_SHIFT)) & OCOTP_SW_STICKY_SRK_REVOKE_LOCK_MASK)

#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK   (0x4U)
#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT  (2U)
/*! FIELD_RETURN_LOCK - Field Return Lock
 *  0b0..Writing to this region's shadow register and OTP fuse word are not blocked.
 *  0b1..Writing to this region's shadow register and OTP fuse word are blocked. Once this bit is set, it is always high unless a POR is issued.
 */
#define OCOTP_SW_STICKY_FIELD_RETURN_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_STICKY_FIELD_RETURN_LOCK_SHIFT)) & OCOTP_SW_STICKY_FIELD_RETURN_LOCK_MASK)
/*! @} */

/*! @name SCS - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_HAB_JDE_MASK                   (0x1U)
#define OCOTP_SCS_HAB_JDE_SHIFT                  (0U)
/*! HAB_JDE - HAB JTAG Debug Enable
 *  0b0..JTAG debugging is not enabled by the HAB (it may still be enabled by other mechanisms).
 *  0b1..JTAG debugging is enabled by the HAB (though this signal may be gated off).
 */
#define OCOTP_SCS_HAB_JDE(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_HAB_JDE_SHIFT)) & OCOTP_SCS_HAB_JDE_MASK)

#define OCOTP_SCS_SPARE_MASK                     (0x7FFFFFFEU)
#define OCOTP_SCS_SPARE_SHIFT                    (1U)
/*! SPARE - Spare */
#define OCOTP_SCS_SPARE(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SPARE_SHIFT)) & OCOTP_SCS_SPARE_MASK)

#define OCOTP_SCS_LOCK_MASK                      (0x80000000U)
#define OCOTP_SCS_LOCK_SHIFT                     (31U)
/*! LOCK - Lock
 *  0b0..Bits in this register are unlocked.
 *  0b1..Bits in this register are locked. When set, all of the bits in this register are locked and can not be
 *       changed through SW programming. After this bit is set, it can only be cleared by a POR.
 */
#define OCOTP_SCS_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_LOCK_SHIFT)) & OCOTP_SCS_LOCK_MASK)
/*! @} */

/*! @name SCS_SET - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_SET_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_SET_HAB_JDE_SHIFT              (0U)
/*! HAB_JDE - HAB JTAG Debug Enable */
#define OCOTP_SCS_SET_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_HAB_JDE_SHIFT)) & OCOTP_SCS_SET_HAB_JDE_MASK)

#define OCOTP_SCS_SET_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_SET_SPARE_SHIFT                (1U)
/*! SPARE - Spare */
#define OCOTP_SCS_SET_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_SPARE_SHIFT)) & OCOTP_SCS_SET_SPARE_MASK)

#define OCOTP_SCS_SET_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_SET_LOCK_SHIFT                 (31U)
/*! LOCK - Lock */
#define OCOTP_SCS_SET_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_SET_LOCK_SHIFT)) & OCOTP_SCS_SET_LOCK_MASK)
/*! @} */

/*! @name SCS_CLR - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_CLR_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_CLR_HAB_JDE_SHIFT              (0U)
/*! HAB_JDE - HAB JTAG Debug Enable */
#define OCOTP_SCS_CLR_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_HAB_JDE_SHIFT)) & OCOTP_SCS_CLR_HAB_JDE_MASK)

#define OCOTP_SCS_CLR_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_CLR_SPARE_SHIFT                (1U)
/*! SPARE - Spare */
#define OCOTP_SCS_CLR_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_SPARE_SHIFT)) & OCOTP_SCS_CLR_SPARE_MASK)

#define OCOTP_SCS_CLR_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_CLR_LOCK_SHIFT                 (31U)
/*! LOCK - Lock */
#define OCOTP_SCS_CLR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_CLR_LOCK_SHIFT)) & OCOTP_SCS_CLR_LOCK_MASK)
/*! @} */

/*! @name SCS_TOG - Software Controllable Signals Register */
/*! @{ */

#define OCOTP_SCS_TOG_HAB_JDE_MASK               (0x1U)
#define OCOTP_SCS_TOG_HAB_JDE_SHIFT              (0U)
/*! HAB_JDE - HAB JTAG Debug Enable */
#define OCOTP_SCS_TOG_HAB_JDE(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_HAB_JDE_SHIFT)) & OCOTP_SCS_TOG_HAB_JDE_MASK)

#define OCOTP_SCS_TOG_SPARE_MASK                 (0x7FFFFFFEU)
#define OCOTP_SCS_TOG_SPARE_SHIFT                (1U)
/*! SPARE - Spare */
#define OCOTP_SCS_TOG_SPARE(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_SPARE_SHIFT)) & OCOTP_SCS_TOG_SPARE_MASK)

#define OCOTP_SCS_TOG_LOCK_MASK                  (0x80000000U)
#define OCOTP_SCS_TOG_LOCK_SHIFT                 (31U)
/*! LOCK - Lock */
#define OCOTP_SCS_TOG_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SCS_TOG_LOCK_SHIFT)) & OCOTP_SCS_TOG_LOCK_MASK)
/*! @} */

/*! @name VERSION - OTP Controller Version Register */
/*! @{ */

#define OCOTP_VERSION_STEP_MASK                  (0xFFFFU)
#define OCOTP_VERSION_STEP_SHIFT                 (0U)
/*! STEP - RTL Version Steping */
#define OCOTP_VERSION_STEP(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_STEP_SHIFT)) & OCOTP_VERSION_STEP_MASK)

#define OCOTP_VERSION_MINOR_MASK                 (0xFF0000U)
#define OCOTP_VERSION_MINOR_SHIFT                (16U)
/*! MINOR - Minor RTL Version */
#define OCOTP_VERSION_MINOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MINOR_SHIFT)) & OCOTP_VERSION_MINOR_MASK)

#define OCOTP_VERSION_MAJOR_MASK                 (0xFF000000U)
#define OCOTP_VERSION_MAJOR_SHIFT                (24U)
/*! MAJOR - Major RTL Version */
#define OCOTP_VERSION_MAJOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MAJOR_SHIFT)) & OCOTP_VERSION_MAJOR_MASK)
/*! @} */

/*! @name TIMING2 - OTP Controller Timing Register 2 */
/*! @{ */

#define OCOTP_TIMING2_RELAX_PROG_MASK            (0xFFFU)
#define OCOTP_TIMING2_RELAX_PROG_SHIFT           (0U)
/*! RELAX_PROG - Relax Prog. count value */
#define OCOTP_TIMING2_RELAX_PROG(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING2_RELAX_PROG_SHIFT)) & OCOTP_TIMING2_RELAX_PROG_MASK)

#define OCOTP_TIMING2_RELAX_READ_MASK            (0x3F0000U)
#define OCOTP_TIMING2_RELAX_READ_SHIFT           (16U)
/*! RELAX_READ - Relax Read count value */
#define OCOTP_TIMING2_RELAX_READ(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_TIMING2_RELAX_READ_SHIFT)) & OCOTP_TIMING2_RELAX_READ_MASK)
/*! @} */

/*! @name LOCK - Value of OTP Bank0 Word0 (Lock controls) */
/*! @{ */

#define OCOTP_LOCK_BOOT_CFG_MASK                 (0xCU)
#define OCOTP_LOCK_BOOT_CFG_SHIFT                (2U)
/*! BOOT_CFG - BOOT_CFG Write Lock Status */
#define OCOTP_LOCK_BOOT_CFG(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_BOOT_CFG_SHIFT)) & OCOTP_LOCK_BOOT_CFG_MASK)

#define OCOTP_LOCK_SJC_RESP_MASK                 (0x40U)
#define OCOTP_LOCK_SJC_RESP_SHIFT                (6U)
/*! SJC_RESP - SJC_RESP Lock Status
 *  0b0..The writing or reading of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked. The read of this
 *       region's shadow register and OTP fuse word are also blocked
 */
#define OCOTP_LOCK_SJC_RESP(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SJC_RESP_SHIFT)) & OCOTP_LOCK_SJC_RESP_MASK)

#define OCOTP_LOCK_MAC_ADDR_MASK                 (0x300U)
#define OCOTP_LOCK_MAC_ADDR_SHIFT                (8U)
/*! MAC_ADDR - MAC_ADDR Write Lock Status */
#define OCOTP_LOCK_MAC_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_MAC_ADDR_SHIFT)) & OCOTP_LOCK_MAC_ADDR_MASK)

#define OCOTP_LOCK_GP1_MASK                      (0xC00U)
#define OCOTP_LOCK_GP1_SHIFT                     (10U)
/*! GP1 - GP1 Write Lock Status */
#define OCOTP_LOCK_GP1(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP1_SHIFT)) & OCOTP_LOCK_GP1_MASK)

#define OCOTP_LOCK_GP2_MASK                      (0x3000U)
#define OCOTP_LOCK_GP2_SHIFT                     (12U)
/*! GP2 - GP2 Write Lock Status */
#define OCOTP_LOCK_GP2(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP2_SHIFT)) & OCOTP_LOCK_GP2_MASK)

#define OCOTP_LOCK_SW_GP1_MASK                   (0x10000U)
#define OCOTP_LOCK_SW_GP1_SHIFT                  (16U)
/*! SW_GP1 - SW_GP1 Write Lock Status
 *  0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
 */
#define OCOTP_LOCK_SW_GP1(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SW_GP1_SHIFT)) & OCOTP_LOCK_SW_GP1_MASK)

#define OCOTP_LOCK_ANALOG_MASK                   (0xC0000U)
#define OCOTP_LOCK_ANALOG_SHIFT                  (18U)
/*! ANALOG - ANALOG Write Lock Status */
#define OCOTP_LOCK_ANALOG(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_ANALOG_SHIFT)) & OCOTP_LOCK_ANALOG_MASK)

#define OCOTP_LOCK_SW_GP2_LOCK_MASK              (0x200000U)
#define OCOTP_LOCK_SW_GP2_LOCK_SHIFT             (21U)
/*! SW_GP2_LOCK - SW_GP2 Write Lock Status
 *  0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
 */
#define OCOTP_LOCK_SW_GP2_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SW_GP2_LOCK_SHIFT)) & OCOTP_LOCK_SW_GP2_LOCK_MASK)

#define OCOTP_LOCK_MISC_CONF_MASK                (0x400000U)
#define OCOTP_LOCK_MISC_CONF_SHIFT               (22U)
/*! MISC_CONF - MISC_CONF Write Lock Status
 *  0b0..Writing of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..When set, the writing of this region's shadow register and OTP fuse word are blocked.
 */
#define OCOTP_LOCK_MISC_CONF(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_MISC_CONF_SHIFT)) & OCOTP_LOCK_MISC_CONF_MASK)

#define OCOTP_LOCK_SW_GP2_RLOCK_MASK             (0x800000U)
#define OCOTP_LOCK_SW_GP2_RLOCK_SHIFT            (23U)
/*! SW_GP2_RLOCK - SW_GP2 Read Lock Status
 *  0b0..The reading of this region's shadow register and OTP fuse word are not blocked.
 *  0b1..When set, the reading of this region's shadow register and OTP fuse word are blocked.
 */
#define OCOTP_LOCK_SW_GP2_RLOCK(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_SW_GP2_RLOCK_SHIFT)) & OCOTP_LOCK_SW_GP2_RLOCK_MASK)

#define OCOTP_LOCK_GP3_MASK                      (0xC000000U)
#define OCOTP_LOCK_GP3_SHIFT                     (26U)
/*! GP3 - GP3 Write Lock Status */
#define OCOTP_LOCK_GP3(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_GP3_SHIFT)) & OCOTP_LOCK_GP3_MASK)

#define OCOTP_LOCK_FIELD_RETURN_MASK             (0x80000000U)
#define OCOTP_LOCK_FIELD_RETURN_SHIFT            (31U)
/*! FIELD_RETURN - FIELD RETURN Status
 *  0b0..The device is a functional part.
 *  0b1..The device is a field returned part.
 */
#define OCOTP_LOCK_FIELD_RETURN(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_LOCK_FIELD_RETURN_SHIFT)) & OCOTP_LOCK_FIELD_RETURN_MASK)
/*! @} */

/*! @name CFG0 - Value of OTP Bank0 Word1 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG0_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG0_BITS_SHIFT)) & OCOTP_CFG0_BITS_MASK)
/*! @} */

/*! @name CFG1 - Value of OTP Bank0 Word2 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG1_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG1_BITS_SHIFT)) & OCOTP_CFG1_BITS_MASK)
/*! @} */

/*! @name CFG2 - Value of OTP Bank0 Word3 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG2_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG2_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG2_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG2_BITS_SHIFT)) & OCOTP_CFG2_BITS_MASK)
/*! @} */

/*! @name CFG3 - Value of OTP Bank0 Word4 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG3_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG3_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG3_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG3_BITS_SHIFT)) & OCOTP_CFG3_BITS_MASK)
/*! @} */

/*! @name CFG4 - Value of OTP Bank0 Word5 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG4_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG4_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG4_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG4_BITS_SHIFT)) & OCOTP_CFG4_BITS_MASK)
/*! @} */

/*! @name CFG5 - Value of OTP Bank0 Word6 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG5_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG5_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG5_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG5_BITS_SHIFT)) & OCOTP_CFG5_BITS_MASK)
/*! @} */

/*! @name CFG6 - Value of OTP Bank0 Word7 (Configuration and Manufacturing Info.) */
/*! @{ */

#define OCOTP_CFG6_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_CFG6_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_CFG6_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_CFG6_BITS_SHIFT)) & OCOTP_CFG6_BITS_MASK)
/*! @} */

/*! @name MEM0 - Value of OTP Bank1 Word0 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MEM0_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MEM0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM0_BITS_SHIFT)) & OCOTP_MEM0_BITS_MASK)
/*! @} */

/*! @name MEM1 - Value of OTP Bank1 Word1 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MEM1_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MEM1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM1_BITS_SHIFT)) & OCOTP_MEM1_BITS_MASK)
/*! @} */

/*! @name MEM2 - Value of OTP Bank1 Word2 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM2_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MEM2_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MEM2_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM2_BITS_SHIFT)) & OCOTP_MEM2_BITS_MASK)
/*! @} */

/*! @name MEM3 - Value of OTP Bank1 Word3 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM3_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MEM3_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MEM3_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM3_BITS_SHIFT)) & OCOTP_MEM3_BITS_MASK)
/*! @} */

/*! @name MEM4 - Value of OTP Bank 1 Word 4 (Memory Related Info.) */
/*! @{ */

#define OCOTP_MEM4_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MEM4_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MEM4_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MEM4_BITS_SHIFT)) & OCOTP_MEM4_BITS_MASK)
/*! @} */

/*! @name ANA0 - Value of OTP Bank 1 Word 5 (Analog Info.) */
/*! @{ */

#define OCOTP_ANA0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_ANA0_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_ANA0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_ANA0_BITS_SHIFT)) & OCOTP_ANA0_BITS_MASK)
/*! @} */

/*! @name ANA1 - Value of OTP Bank 1 Word 6 (Analog Info.) */
/*! @{ */

#define OCOTP_ANA1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_ANA1_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_ANA1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_ANA1_BITS_SHIFT)) & OCOTP_ANA1_BITS_MASK)
/*! @} */

/*! @name ANA2 - Value of OTP Bank 1 Word 7 (Analog Info.) */
/*! @{ */

#define OCOTP_ANA2_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_ANA2_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_ANA2_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_ANA2_BITS_SHIFT)) & OCOTP_ANA2_BITS_MASK)
/*! @} */

/*! @name SRK0 - Shadow Register for OTP Bank3 Word0 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK0_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK0_BITS_SHIFT)) & OCOTP_SRK0_BITS_MASK)
/*! @} */

/*! @name SRK1 - Shadow Register for OTP Bank3 Word1 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK1_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK1_BITS_SHIFT)) & OCOTP_SRK1_BITS_MASK)
/*! @} */

/*! @name SRK2 - Shadow Register for OTP Bank3 Word2 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK2_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK2_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK2_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK2_BITS_SHIFT)) & OCOTP_SRK2_BITS_MASK)
/*! @} */

/*! @name SRK3 - Shadow Register for OTP Bank3 Word3 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK3_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK3_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK3_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK3_BITS_SHIFT)) & OCOTP_SRK3_BITS_MASK)
/*! @} */

/*! @name SRK4 - Shadow Register for OTP Bank3 Word4 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK4_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK4_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK4_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK4_BITS_SHIFT)) & OCOTP_SRK4_BITS_MASK)
/*! @} */

/*! @name SRK5 - Shadow Register for OTP Bank3 Word5 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK5_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK5_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK5_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK5_BITS_SHIFT)) & OCOTP_SRK5_BITS_MASK)
/*! @} */

/*! @name SRK6 - Shadow Register for OTP Bank3 Word6 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK6_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK6_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK6_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK6_BITS_SHIFT)) & OCOTP_SRK6_BITS_MASK)
/*! @} */

/*! @name SRK7 - Shadow Register for OTP Bank3 Word7 (SRK Hash) */
/*! @{ */

#define OCOTP_SRK7_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_SRK7_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_SRK7_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK7_BITS_SHIFT)) & OCOTP_SRK7_BITS_MASK)
/*! @} */

/*! @name SJC_RESP0 - Value of OTP Bank4 Word0 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_SJC_RESP0_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_SJC_RESP0_BITS_SHIFT               (0U)
/*! BITS - BITS */
#define OCOTP_SJC_RESP0_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_SJC_RESP0_BITS_SHIFT)) & OCOTP_SJC_RESP0_BITS_MASK)
/*! @} */

/*! @name SJC_RESP1 - Value of OTP Bank4 Word1 (Secure JTAG Response Field) */
/*! @{ */

#define OCOTP_SJC_RESP1_BITS_MASK                (0xFFFFFFFFU)
#define OCOTP_SJC_RESP1_BITS_SHIFT               (0U)
/*! BITS - BITS */
#define OCOTP_SJC_RESP1_BITS(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_SJC_RESP1_BITS_SHIFT)) & OCOTP_SJC_RESP1_BITS_MASK)
/*! @} */

/*! @name MAC0 - Value of OTP Bank4 Word2 (MAC Address) */
/*! @{ */

#define OCOTP_MAC0_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MAC0_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MAC0_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MAC0_BITS_SHIFT)) & OCOTP_MAC0_BITS_MASK)
/*! @} */

/*! @name MAC1 - Value of OTP Bank4 Word3 (MAC Address) */
/*! @{ */

#define OCOTP_MAC1_BITS_MASK                     (0xFFFFFFFFU)
#define OCOTP_MAC1_BITS_SHIFT                    (0U)
/*! BITS - BITS */
#define OCOTP_MAC1_BITS(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_MAC1_BITS_SHIFT)) & OCOTP_MAC1_BITS_MASK)
/*! @} */

/*! @name GP3 - Value of OTP Bank4 Word4 (MAC Address) */
/*! @{ */

#define OCOTP_GP3_BITS_MASK                      (0xFFFFFFFFU)
#define OCOTP_GP3_BITS_SHIFT                     (0U)
/*! BITS - BITS */
#define OCOTP_GP3_BITS(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_GP3_BITS_SHIFT)) & OCOTP_GP3_BITS_MASK)
/*! @} */

/*! @name GP1 - Value of OTP Bank4 Word6 (General Purpose Customer Defined Info) */
/*! @{ */

#define OCOTP_GP1_BITS_MASK                      (0xFFFFFFFFU)
#define OCOTP_GP1_BITS_SHIFT                     (0U)
/*! BITS - BITS */
#define OCOTP_GP1_BITS(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_GP1_BITS_SHIFT)) & OCOTP_GP1_BITS_MASK)
/*! @} */

/*! @name GP2 - Value of OTP Bank4 Word7 (General Purpose Customer Defined Info) */
/*! @{ */

#define OCOTP_GP2_BITS_MASK                      (0xFFFFFFFFU)
#define OCOTP_GP2_BITS_SHIFT                     (0U)
/*! BITS - BITS */
#define OCOTP_GP2_BITS(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_GP2_BITS_SHIFT)) & OCOTP_GP2_BITS_MASK)
/*! @} */

/*! @name SW_GP1 - Value of OTP Bank5 Word0 (SW GP1) */
/*! @{ */

#define OCOTP_SW_GP1_BITS_MASK                   (0xFFFFFFFFU)
#define OCOTP_SW_GP1_BITS_SHIFT                  (0U)
/*! BITS - BITS */
#define OCOTP_SW_GP1_BITS(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_GP1_BITS_SHIFT)) & OCOTP_SW_GP1_BITS_MASK)
/*! @} */

/*! @name SW_GP20 - Value of OTP Bank5 Word1 (SW GP2) */
/*! @{ */

#define OCOTP_SW_GP20_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_SW_GP20_BITS_SHIFT                 (0U)
/*! BITS - BITS */
#define OCOTP_SW_GP20_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_GP20_BITS_SHIFT)) & OCOTP_SW_GP20_BITS_MASK)
/*! @} */

/*! @name SW_GP21 - Value of OTP Bank5 Word2 (SW GP2) */
/*! @{ */

#define OCOTP_SW_GP21_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_SW_GP21_BITS_SHIFT                 (0U)
/*! BITS - BITS */
#define OCOTP_SW_GP21_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_GP21_BITS_SHIFT)) & OCOTP_SW_GP21_BITS_MASK)
/*! @} */

/*! @name SW_GP22 - Value of OTP Bank5 Word3 (SW GP2) */
/*! @{ */

#define OCOTP_SW_GP22_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_SW_GP22_BITS_SHIFT                 (0U)
/*! BITS - BITS */
#define OCOTP_SW_GP22_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_GP22_BITS_SHIFT)) & OCOTP_SW_GP22_BITS_MASK)
/*! @} */

/*! @name SW_GP23 - Value of OTP Bank5 Word4 (SW GP2) */
/*! @{ */

#define OCOTP_SW_GP23_BITS_MASK                  (0xFFFFFFFFU)
#define OCOTP_SW_GP23_BITS_SHIFT                 (0U)
/*! BITS - BITS */
#define OCOTP_SW_GP23_BITS(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_SW_GP23_BITS_SHIFT)) & OCOTP_SW_GP23_BITS_MASK)
/*! @} */

/*! @name MISC_CONF0 - Value of OTP Bank5 Word5 (Misc Conf) */
/*! @{ */

#define OCOTP_MISC_CONF0_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_MISC_CONF0_BITS_SHIFT              (0U)
/*! BITS - BITS */
#define OCOTP_MISC_CONF0_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_MISC_CONF0_BITS_SHIFT)) & OCOTP_MISC_CONF0_BITS_MASK)
/*! @} */

/*! @name MISC_CONF1 - Value of OTP Bank5 Word6 (Misc Conf) */
/*! @{ */

#define OCOTP_MISC_CONF1_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_MISC_CONF1_BITS_SHIFT              (0U)
/*! BITS - BITS */
#define OCOTP_MISC_CONF1_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_MISC_CONF1_BITS_SHIFT)) & OCOTP_MISC_CONF1_BITS_MASK)
/*! @} */

/*! @name SRK_REVOKE - Value of OTP Bank5 Word7 (SRK Revoke) */
/*! @{ */

#define OCOTP_SRK_REVOKE_BITS_MASK               (0xFFFFFFFFU)
#define OCOTP_SRK_REVOKE_BITS_SHIFT              (0U)
/*! BITS - BITS */
#define OCOTP_SRK_REVOKE_BITS(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_SRK_REVOKE_BITS_SHIFT)) & OCOTP_SRK_REVOKE_BITS_MASK)
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
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_OCOTP_H_ */

