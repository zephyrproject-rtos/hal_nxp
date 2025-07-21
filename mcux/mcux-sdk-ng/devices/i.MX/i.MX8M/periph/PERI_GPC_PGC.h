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
**         CMSIS Peripheral Access Layer for GPC_PGC
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
 * @file PERI_GPC_PGC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_PGC
 *
 * CMSIS Peripheral Access Layer for GPC_PGC
 */

#if !defined(PERI_GPC_PGC_H_)
#define PERI_GPC_PGC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- GPC_PGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_PGC_Peripheral_Access_Layer GPC_PGC Peripheral Access Layer
 * @{
 */

/** GPC_PGC - Register Layout Typedef */
typedef struct {
  __IO uint32_t A53CORE0_CTRL;                     /**< GPC PGC Control Register, offset: 0x0 */
  __IO uint32_t A53CORE0_PUPSCR;                   /**< GPC PGC Up Sequence Control Register, offset: 0x4 */
  __IO uint32_t A53CORE0_PDNSCR;                   /**< GPC PGC Down Sequence Control Register, offset: 0x8 */
  __IO uint32_t A53CORE0_SR;                       /**< GPC PGC Status Register, offset: 0xC */
  __IO uint32_t A53CORE0_AUXSW;                    /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x10 */
       uint8_t RESERVED_0[44];
  __IO uint32_t A53CORE1_CTRL;                     /**< GPC PGC Control Register, offset: 0x40 */
  __IO uint32_t A53CORE1_PUPSCR;                   /**< GPC PGC Up Sequence Control Register, offset: 0x44 */
  __IO uint32_t A53CORE1_PDNSCR;                   /**< GPC PGC Down Sequence Control Register, offset: 0x48 */
  __IO uint32_t A53CORE1_SR;                       /**< GPC PGC Status Register, offset: 0x4C */
  __IO uint32_t A53CORE1_AUXSW;                    /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x50 */
       uint8_t RESERVED_1[44];
  __IO uint32_t A53CORE2_CTRL;                     /**< GPC PGC Control Register, offset: 0x80 */
  __IO uint32_t A53CORE2_PUPSCR;                   /**< GPC PGC Up Sequence Control Register, offset: 0x84 */
  __IO uint32_t A53CORE2_PDNSCR;                   /**< GPC PGC Down Sequence Control Register, offset: 0x88 */
  __IO uint32_t A53CORE2_SR;                       /**< GPC PGC Status Register, offset: 0x8C */
  __IO uint32_t A53CORE2_AUXSW;                    /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x90 */
       uint8_t RESERVED_2[44];
  __IO uint32_t A53CORE3_CTRL;                     /**< GPC PGC Control Register, offset: 0xC0 */
  __IO uint32_t A53CORE3_PUPSCR;                   /**< GPC PGC Up Sequence Control Register, offset: 0xC4 */
  __IO uint32_t A53CORE3_PDNSCR;                   /**< GPC PGC Down Sequence Control Register, offset: 0xC8 */
  __IO uint32_t A53CORE3_SR;                       /**< GPC PGC Status Register, offset: 0xCC */
  __IO uint32_t A53CORE3_AUXSW;                    /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0xD0 */
       uint8_t RESERVED_3[44];
  __IO uint32_t A53SCU_CTRL;                       /**< GPC PGC Control Register, offset: 0x100 */
  __IO uint32_t A53SCU_PUPSCR;                     /**< GPC PGC Up Sequence Control Register, offset: 0x104 */
  __IO uint32_t A53SCU_PDNSCR;                     /**< GPC PGC Down Sequence Control Register, offset: 0x108 */
  __IO uint32_t A53SCU_SR;                         /**< GPC PGC Status Register, offset: 0x10C */
  __IO uint32_t A53SCU_AUXSW;                      /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x110 */
       uint8_t RESERVED_4[236];
  __IO uint32_t MIX_CTRL;                          /**< GPC PGC Control Register, offset: 0x200 */
  __IO uint32_t MIX_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x204 */
  __IO uint32_t MIX_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x208 */
  __IO uint32_t MIX_SR;                            /**< GPC PGC Status Register, offset: 0x20C */
  __IO uint32_t MIX_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x210 */
       uint8_t RESERVED_5[492];
  __IO uint32_t PU0_CTRL;                          /**< GPC PGC Control Register, offset: 0x400 */
  __IO uint32_t PU0_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x404 */
  __IO uint32_t PU0_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x408 */
  __IO uint32_t PU0_SR;                            /**< GPC PGC Status Register, offset: 0x40C */
  __IO uint32_t PU0_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x410 */
       uint8_t RESERVED_6[44];
  __IO uint32_t PU1_CTRL;                          /**< GPC PGC Control Register, offset: 0x440 */
  __IO uint32_t PU1_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x444 */
  __IO uint32_t PU1_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x448 */
  __IO uint32_t PU1_SR;                            /**< GPC PGC Status Register, offset: 0x44C */
  __IO uint32_t PU1_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x450 */
       uint8_t RESERVED_7[44];
  __IO uint32_t PU2_CTRL;                          /**< GPC PGC Control Register, offset: 0x480 */
  __IO uint32_t PU2_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x484 */
  __IO uint32_t PU2_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x488 */
  __IO uint32_t PU2_SR;                            /**< GPC PGC Status Register, offset: 0x48C */
  __IO uint32_t PU2_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x490 */
       uint8_t RESERVED_8[44];
  __IO uint32_t PU3_CTRL;                          /**< GPC PGC Control Register, offset: 0x4C0 */
  __IO uint32_t PU3_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x4C4 */
  __IO uint32_t PU3_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x4C8 */
  __IO uint32_t PU3_SR;                            /**< GPC PGC Status Register, offset: 0x4CC */
  __IO uint32_t PU3_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x4D0 */
       uint8_t RESERVED_9[44];
  __IO uint32_t PU4_CTRL;                          /**< GPC PGC Control Register, offset: 0x500 */
  __IO uint32_t PU4_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x504 */
  __IO uint32_t PU4_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x508 */
  __IO uint32_t PU4_SR;                            /**< GPC PGC Status Register, offset: 0x50C */
  __IO uint32_t PU4_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x510 */
       uint8_t RESERVED_10[44];
  __IO uint32_t PU5_CTRL;                          /**< GPC PGC Control Register, offset: 0x540 */
  __IO uint32_t PU5_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x544 */
  __IO uint32_t PU5_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x548 */
  __IO uint32_t PU5_SR;                            /**< GPC PGC Status Register, offset: 0x54C */
  __IO uint32_t PU5_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x550 */
       uint8_t RESERVED_11[44];
  __IO uint32_t PU6_CTRL;                          /**< GPC PGC Control Register, offset: 0x580 */
  __IO uint32_t PU6_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x584 */
  __IO uint32_t PU6_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x588 */
  __IO uint32_t PU6_SR;                            /**< GPC PGC Status Register, offset: 0x58C */
  __IO uint32_t PU6_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x590 */
       uint8_t RESERVED_12[44];
  __IO uint32_t PU7_CTRL;                          /**< GPC PGC Control Register, offset: 0x5C0 */
  __IO uint32_t PU7_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x5C4 */
  __IO uint32_t PU7_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x5C8 */
  __IO uint32_t PU7_SR;                            /**< GPC PGC Status Register, offset: 0x5CC */
  __IO uint32_t PU7_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x5D0 */
       uint8_t RESERVED_13[44];
  __IO uint32_t PU8_CTRL;                          /**< GPC PGC Control Register, offset: 0x600 */
  __IO uint32_t PU8_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x604 */
  __IO uint32_t PU8_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x608 */
  __IO uint32_t PU8_SR;                            /**< GPC PGC Status Register, offset: 0x60C */
  __IO uint32_t PU8_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x610 */
       uint8_t RESERVED_14[44];
  __IO uint32_t PU9_CTRL;                          /**< GPC PGC Control Register, offset: 0x640 */
  __IO uint32_t PU9_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, offset: 0x644 */
  __IO uint32_t PU9_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, offset: 0x648 */
  __IO uint32_t PU9_SR;                            /**< GPC PGC Status Register, offset: 0x64C */
  __IO uint32_t PU9_AUXSW;                         /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x650 */
       uint8_t RESERVED_15[44];
  __IO uint32_t PU10_CTRL;                         /**< GPC PGC Control Register, offset: 0x680 */
  __IO uint32_t PU10_PUPSCR;                       /**< GPC PGC Up Sequence Control Register, offset: 0x684 */
  __IO uint32_t PU10_PDNSCR;                       /**< GPC PGC Down Sequence Control Register, offset: 0x688 */
  __IO uint32_t PU10_SR;                           /**< GPC PGC Status Register, offset: 0x68C */
  __IO uint32_t PU10_AUXSW;                        /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x690 */
       uint8_t RESERVED_16[44];
  __IO uint32_t PU11_CTRL;                         /**< GPC PGC Control Register, offset: 0x6C0 */
  __IO uint32_t PU11_PUPSCR;                       /**< GPC PGC Up Sequence Control Register, offset: 0x6C4 */
  __IO uint32_t PU11_PDNSCR;                       /**< GPC PGC Down Sequence Control Register, offset: 0x6C8 */
  __IO uint32_t PU11_SR;                           /**< GPC PGC Status Register, offset: 0x6CC */
  __IO uint32_t PU11_AUXSW;                        /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x6D0 */
       uint8_t RESERVED_17[44];
  __IO uint32_t PU12_CTRL;                         /**< GPC PGC Control Register, offset: 0x700 */
  __IO uint32_t PU12_PUPSCR;                       /**< GPC PGC Up Sequence Control Register, offset: 0x704 */
  __IO uint32_t PU12_PDNSCR;                       /**< GPC PGC Down Sequence Control Register, offset: 0x708 */
  __IO uint32_t PU12_SR;                           /**< GPC PGC Status Register, offset: 0x70C */
  __IO uint32_t PU12_AUXSW;                        /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x710 */
       uint8_t RESERVED_18[44];
  __IO uint32_t PU13_CTRL;                         /**< GPC PGC Control Register, offset: 0x740 */
  __IO uint32_t PU13_PUPSCR;                       /**< GPC PGC Up Sequence Control Register, offset: 0x744 */
  __IO uint32_t PU13_PDNSCR;                       /**< GPC PGC Down Sequence Control Register, offset: 0x748 */
  __IO uint32_t PU13_SR;                           /**< GPC PGC Status Register, offset: 0x74C */
  __IO uint32_t PU13_AUXSW;                        /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x750 */
} GPC_PGC_Type;

/* ----------------------------------------------------------------------------
   -- GPC_PGC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_PGC_Register_Masks GPC_PGC Register Masks
 * @{
 */

/*! @name A53CORE0_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_A53CORE0_CTRL_PCR_MASK           (0x1U)
#define GPC_PGC_A53CORE0_CTRL_PCR_SHIFT          (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_A53CORE0_CTRL_PCR(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_CTRL_PCR_SHIFT)) & GPC_PGC_A53CORE0_CTRL_PCR_MASK)

#define GPC_PGC_A53CORE0_CTRL_L2RSTDIS_MASK      (0x7EU)
#define GPC_PGC_A53CORE0_CTRL_L2RSTDIS_SHIFT     (1U)
#define GPC_PGC_A53CORE0_CTRL_L2RSTDIS(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_A53CORE0_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_A53CORE0_CTRL_DFTRAM_TCD1_MASK   (0x3F00U)
#define GPC_PGC_A53CORE0_CTRL_DFTRAM_TCD1_SHIFT  (8U)
#define GPC_PGC_A53CORE0_CTRL_DFTRAM_TCD1(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_A53CORE0_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_A53CORE0_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_A53CORE0_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_A53CORE0_CTRL_L2RETN_TCD1_TDR(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_A53CORE0_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_A53CORE0_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_A53CORE0_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_A53CORE0_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_A53CORE0_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name A53CORE0_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE0_PUPSCR_SW_MASK          (0x3FU)
#define GPC_PGC_A53CORE0_PUPSCR_SW_SHIFT         (0U)
#define GPC_PGC_A53CORE0_PUPSCR_SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PUPSCR_SW_SHIFT)) & GPC_PGC_A53CORE0_PUPSCR_SW_MASK)

#define GPC_PGC_A53CORE0_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_A53CORE0_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_A53CORE0_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE0_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE0_PUPSCR_SW2ISO_MASK      (0x7FFF80U)
#define GPC_PGC_A53CORE0_PUPSCR_SW2ISO_SHIFT     (7U)
#define GPC_PGC_A53CORE0_PUPSCR_SW2ISO(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53CORE0_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_A53CORE0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_A53CORE0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_A53CORE0_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name A53CORE0_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE0_PDNSCR_ISO_MASK         (0x3FU)
#define GPC_PGC_A53CORE0_PDNSCR_ISO_SHIFT        (0U)
#define GPC_PGC_A53CORE0_PDNSCR_ISO(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53CORE0_PDNSCR_ISO_MASK)

#define GPC_PGC_A53CORE0_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_A53CORE0_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_A53CORE0_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE0_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE0_PDNSCR_ISO2SW_MASK      (0x3F00U)
#define GPC_PGC_A53CORE0_PDNSCR_ISO2SW_SHIFT     (8U)
#define GPC_PGC_A53CORE0_PDNSCR_ISO2SW(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53CORE0_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_A53CORE0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_A53CORE0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_A53CORE0_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_A53CORE0_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_A53CORE0_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_A53CORE0_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_A53CORE0_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name A53CORE0_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_A53CORE0_SR_PSR_MASK             (0x1U)
#define GPC_PGC_A53CORE0_SR_PSR_SHIFT            (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_A53CORE0_SR_PSR(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_SR_PSR_SHIFT)) & GPC_PGC_A53CORE0_SR_PSR_MASK)

#define GPC_PGC_A53CORE0_SR_L2RETN_FLAG_MASK     (0x2U)
#define GPC_PGC_A53CORE0_SR_L2RETN_FLAG_SHIFT    (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_A53CORE0_SR_L2RETN_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_A53CORE0_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_A53CORE0_SR_ALLOFF_FLAG_MASK     (0x4U)
#define GPC_PGC_A53CORE0_SR_ALLOFF_FLAG_SHIFT    (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE0_SR_ALLOFF_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_A53CORE0_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_A53CORE0_SR_PUP_CLK_DIV_SEL_MASK (0x78U)
#define GPC_PGC_A53CORE0_SR_PUP_CLK_DIV_SEL_SHIFT (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE0_SR_PUP_CLK_DIV_SEL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE0_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_A53CORE0_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_A53CORE0_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_A53CORE0_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_A53CORE0_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name A53CORE0_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53CORE0_AUXSW_SW2_MASK          (0x3FU)
#define GPC_PGC_A53CORE0_AUXSW_SW2_SHIFT         (0U)
#define GPC_PGC_A53CORE0_AUXSW_SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_AUXSW_SW2_SHIFT)) & GPC_PGC_A53CORE0_AUXSW_SW2_MASK)

#define GPC_PGC_A53CORE0_AUXSW_ISO2SW2_MASK      (0x3F00U)
#define GPC_PGC_A53CORE0_AUXSW_ISO2SW2_SHIFT     (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE0_AUXSW_ISO2SW2(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_A53CORE0_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_A53CORE0_AUXSW_PDN_CLK_DIV_SEL_MASK (0xF0000U)
#define GPC_PGC_A53CORE0_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE0_AUXSW_PDN_CLK_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE0_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE0_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name A53CORE1_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_A53CORE1_CTRL_PCR_MASK           (0x1U)
#define GPC_PGC_A53CORE1_CTRL_PCR_SHIFT          (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_A53CORE1_CTRL_PCR(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_CTRL_PCR_SHIFT)) & GPC_PGC_A53CORE1_CTRL_PCR_MASK)

#define GPC_PGC_A53CORE1_CTRL_L2RSTDIS_MASK      (0x7EU)
#define GPC_PGC_A53CORE1_CTRL_L2RSTDIS_SHIFT     (1U)
#define GPC_PGC_A53CORE1_CTRL_L2RSTDIS(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_A53CORE1_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_A53CORE1_CTRL_DFTRAM_TCD1_MASK   (0x3F00U)
#define GPC_PGC_A53CORE1_CTRL_DFTRAM_TCD1_SHIFT  (8U)
#define GPC_PGC_A53CORE1_CTRL_DFTRAM_TCD1(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_A53CORE1_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_A53CORE1_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_A53CORE1_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_A53CORE1_CTRL_L2RETN_TCD1_TDR(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_A53CORE1_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_A53CORE1_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_A53CORE1_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_A53CORE1_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_A53CORE1_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name A53CORE1_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE1_PUPSCR_SW_MASK          (0x3FU)
#define GPC_PGC_A53CORE1_PUPSCR_SW_SHIFT         (0U)
#define GPC_PGC_A53CORE1_PUPSCR_SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PUPSCR_SW_SHIFT)) & GPC_PGC_A53CORE1_PUPSCR_SW_MASK)

#define GPC_PGC_A53CORE1_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_A53CORE1_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_A53CORE1_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE1_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE1_PUPSCR_SW2ISO_MASK      (0x7FFF80U)
#define GPC_PGC_A53CORE1_PUPSCR_SW2ISO_SHIFT     (7U)
#define GPC_PGC_A53CORE1_PUPSCR_SW2ISO(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53CORE1_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_A53CORE1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_A53CORE1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_A53CORE1_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name A53CORE1_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE1_PDNSCR_ISO_MASK         (0x3FU)
#define GPC_PGC_A53CORE1_PDNSCR_ISO_SHIFT        (0U)
#define GPC_PGC_A53CORE1_PDNSCR_ISO(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53CORE1_PDNSCR_ISO_MASK)

#define GPC_PGC_A53CORE1_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_A53CORE1_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_A53CORE1_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE1_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE1_PDNSCR_ISO2SW_MASK      (0x3F00U)
#define GPC_PGC_A53CORE1_PDNSCR_ISO2SW_SHIFT     (8U)
#define GPC_PGC_A53CORE1_PDNSCR_ISO2SW(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53CORE1_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_A53CORE1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_A53CORE1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_A53CORE1_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_A53CORE1_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_A53CORE1_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_A53CORE1_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_A53CORE1_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name A53CORE1_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_A53CORE1_SR_PSR_MASK             (0x1U)
#define GPC_PGC_A53CORE1_SR_PSR_SHIFT            (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_A53CORE1_SR_PSR(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_SR_PSR_SHIFT)) & GPC_PGC_A53CORE1_SR_PSR_MASK)

#define GPC_PGC_A53CORE1_SR_L2RETN_FLAG_MASK     (0x2U)
#define GPC_PGC_A53CORE1_SR_L2RETN_FLAG_SHIFT    (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_A53CORE1_SR_L2RETN_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_A53CORE1_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_A53CORE1_SR_ALLOFF_FLAG_MASK     (0x4U)
#define GPC_PGC_A53CORE1_SR_ALLOFF_FLAG_SHIFT    (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE1_SR_ALLOFF_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_A53CORE1_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_A53CORE1_SR_PUP_CLK_DIV_SEL_MASK (0x78U)
#define GPC_PGC_A53CORE1_SR_PUP_CLK_DIV_SEL_SHIFT (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE1_SR_PUP_CLK_DIV_SEL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE1_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_A53CORE1_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_A53CORE1_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_A53CORE1_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_A53CORE1_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name A53CORE1_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53CORE1_AUXSW_SW2_MASK          (0x3FU)
#define GPC_PGC_A53CORE1_AUXSW_SW2_SHIFT         (0U)
#define GPC_PGC_A53CORE1_AUXSW_SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_AUXSW_SW2_SHIFT)) & GPC_PGC_A53CORE1_AUXSW_SW2_MASK)

#define GPC_PGC_A53CORE1_AUXSW_ISO2SW2_MASK      (0x3F00U)
#define GPC_PGC_A53CORE1_AUXSW_ISO2SW2_SHIFT     (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE1_AUXSW_ISO2SW2(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_A53CORE1_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_A53CORE1_AUXSW_PDN_CLK_DIV_SEL_MASK (0xF0000U)
#define GPC_PGC_A53CORE1_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE1_AUXSW_PDN_CLK_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE1_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE1_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name A53CORE2_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_A53CORE2_CTRL_PCR_MASK           (0x1U)
#define GPC_PGC_A53CORE2_CTRL_PCR_SHIFT          (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_A53CORE2_CTRL_PCR(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_CTRL_PCR_SHIFT)) & GPC_PGC_A53CORE2_CTRL_PCR_MASK)

#define GPC_PGC_A53CORE2_CTRL_L2RSTDIS_MASK      (0x7EU)
#define GPC_PGC_A53CORE2_CTRL_L2RSTDIS_SHIFT     (1U)
#define GPC_PGC_A53CORE2_CTRL_L2RSTDIS(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_A53CORE2_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_A53CORE2_CTRL_DFTRAM_TCD1_MASK   (0x3F00U)
#define GPC_PGC_A53CORE2_CTRL_DFTRAM_TCD1_SHIFT  (8U)
#define GPC_PGC_A53CORE2_CTRL_DFTRAM_TCD1(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_A53CORE2_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_A53CORE2_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_A53CORE2_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_A53CORE2_CTRL_L2RETN_TCD1_TDR(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_A53CORE2_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_A53CORE2_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_A53CORE2_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_A53CORE2_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_A53CORE2_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name A53CORE2_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE2_PUPSCR_SW_MASK          (0x3FU)
#define GPC_PGC_A53CORE2_PUPSCR_SW_SHIFT         (0U)
#define GPC_PGC_A53CORE2_PUPSCR_SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PUPSCR_SW_SHIFT)) & GPC_PGC_A53CORE2_PUPSCR_SW_MASK)

#define GPC_PGC_A53CORE2_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_A53CORE2_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_A53CORE2_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE2_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE2_PUPSCR_SW2ISO_MASK      (0x7FFF80U)
#define GPC_PGC_A53CORE2_PUPSCR_SW2ISO_SHIFT     (7U)
#define GPC_PGC_A53CORE2_PUPSCR_SW2ISO(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53CORE2_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_A53CORE2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_A53CORE2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_A53CORE2_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name A53CORE2_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE2_PDNSCR_ISO_MASK         (0x3FU)
#define GPC_PGC_A53CORE2_PDNSCR_ISO_SHIFT        (0U)
#define GPC_PGC_A53CORE2_PDNSCR_ISO(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53CORE2_PDNSCR_ISO_MASK)

#define GPC_PGC_A53CORE2_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_A53CORE2_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_A53CORE2_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE2_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE2_PDNSCR_ISO2SW_MASK      (0x3F00U)
#define GPC_PGC_A53CORE2_PDNSCR_ISO2SW_SHIFT     (8U)
#define GPC_PGC_A53CORE2_PDNSCR_ISO2SW(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53CORE2_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_A53CORE2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_A53CORE2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_A53CORE2_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_A53CORE2_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_A53CORE2_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_A53CORE2_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_A53CORE2_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name A53CORE2_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_A53CORE2_SR_PSR_MASK             (0x1U)
#define GPC_PGC_A53CORE2_SR_PSR_SHIFT            (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_A53CORE2_SR_PSR(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_SR_PSR_SHIFT)) & GPC_PGC_A53CORE2_SR_PSR_MASK)

#define GPC_PGC_A53CORE2_SR_L2RETN_FLAG_MASK     (0x2U)
#define GPC_PGC_A53CORE2_SR_L2RETN_FLAG_SHIFT    (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_A53CORE2_SR_L2RETN_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_A53CORE2_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_A53CORE2_SR_ALLOFF_FLAG_MASK     (0x4U)
#define GPC_PGC_A53CORE2_SR_ALLOFF_FLAG_SHIFT    (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE2_SR_ALLOFF_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_A53CORE2_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_A53CORE2_SR_PUP_CLK_DIV_SEL_MASK (0x78U)
#define GPC_PGC_A53CORE2_SR_PUP_CLK_DIV_SEL_SHIFT (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE2_SR_PUP_CLK_DIV_SEL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE2_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_A53CORE2_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_A53CORE2_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_A53CORE2_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_A53CORE2_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name A53CORE2_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53CORE2_AUXSW_SW2_MASK          (0x3FU)
#define GPC_PGC_A53CORE2_AUXSW_SW2_SHIFT         (0U)
#define GPC_PGC_A53CORE2_AUXSW_SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_AUXSW_SW2_SHIFT)) & GPC_PGC_A53CORE2_AUXSW_SW2_MASK)

#define GPC_PGC_A53CORE2_AUXSW_ISO2SW2_MASK      (0x3F00U)
#define GPC_PGC_A53CORE2_AUXSW_ISO2SW2_SHIFT     (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE2_AUXSW_ISO2SW2(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_A53CORE2_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_A53CORE2_AUXSW_PDN_CLK_DIV_SEL_MASK (0xF0000U)
#define GPC_PGC_A53CORE2_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE2_AUXSW_PDN_CLK_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE2_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE2_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name A53CORE3_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_A53CORE3_CTRL_PCR_MASK           (0x1U)
#define GPC_PGC_A53CORE3_CTRL_PCR_SHIFT          (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_A53CORE3_CTRL_PCR(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_CTRL_PCR_SHIFT)) & GPC_PGC_A53CORE3_CTRL_PCR_MASK)

#define GPC_PGC_A53CORE3_CTRL_L2RSTDIS_MASK      (0x7EU)
#define GPC_PGC_A53CORE3_CTRL_L2RSTDIS_SHIFT     (1U)
#define GPC_PGC_A53CORE3_CTRL_L2RSTDIS(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_A53CORE3_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_A53CORE3_CTRL_DFTRAM_TCD1_MASK   (0x3F00U)
#define GPC_PGC_A53CORE3_CTRL_DFTRAM_TCD1_SHIFT  (8U)
#define GPC_PGC_A53CORE3_CTRL_DFTRAM_TCD1(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_A53CORE3_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_A53CORE3_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_A53CORE3_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_A53CORE3_CTRL_L2RETN_TCD1_TDR(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_A53CORE3_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_A53CORE3_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_A53CORE3_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_A53CORE3_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_A53CORE3_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name A53CORE3_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE3_PUPSCR_SW_MASK          (0x3FU)
#define GPC_PGC_A53CORE3_PUPSCR_SW_SHIFT         (0U)
#define GPC_PGC_A53CORE3_PUPSCR_SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PUPSCR_SW_SHIFT)) & GPC_PGC_A53CORE3_PUPSCR_SW_MASK)

#define GPC_PGC_A53CORE3_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_A53CORE3_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_A53CORE3_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE3_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE3_PUPSCR_SW2ISO_MASK      (0x7FFF80U)
#define GPC_PGC_A53CORE3_PUPSCR_SW2ISO_SHIFT     (7U)
#define GPC_PGC_A53CORE3_PUPSCR_SW2ISO(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53CORE3_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_A53CORE3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_A53CORE3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_A53CORE3_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name A53CORE3_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53CORE3_PDNSCR_ISO_MASK         (0x3FU)
#define GPC_PGC_A53CORE3_PDNSCR_ISO_SHIFT        (0U)
#define GPC_PGC_A53CORE3_PDNSCR_ISO(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53CORE3_PDNSCR_ISO_MASK)

#define GPC_PGC_A53CORE3_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_A53CORE3_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_A53CORE3_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53CORE3_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53CORE3_PDNSCR_ISO2SW_MASK      (0x3F00U)
#define GPC_PGC_A53CORE3_PDNSCR_ISO2SW_SHIFT     (8U)
#define GPC_PGC_A53CORE3_PDNSCR_ISO2SW(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53CORE3_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_A53CORE3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_A53CORE3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_A53CORE3_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53CORE3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_A53CORE3_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_A53CORE3_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_A53CORE3_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_A53CORE3_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name A53CORE3_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_A53CORE3_SR_PSR_MASK             (0x1U)
#define GPC_PGC_A53CORE3_SR_PSR_SHIFT            (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_A53CORE3_SR_PSR(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_SR_PSR_SHIFT)) & GPC_PGC_A53CORE3_SR_PSR_MASK)

#define GPC_PGC_A53CORE3_SR_L2RETN_FLAG_MASK     (0x2U)
#define GPC_PGC_A53CORE3_SR_L2RETN_FLAG_SHIFT    (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_A53CORE3_SR_L2RETN_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_A53CORE3_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_A53CORE3_SR_ALLOFF_FLAG_MASK     (0x4U)
#define GPC_PGC_A53CORE3_SR_ALLOFF_FLAG_SHIFT    (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE3_SR_ALLOFF_FLAG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_A53CORE3_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_A53CORE3_SR_PUP_CLK_DIV_SEL_MASK (0x78U)
#define GPC_PGC_A53CORE3_SR_PUP_CLK_DIV_SEL_SHIFT (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE3_SR_PUP_CLK_DIV_SEL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE3_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_A53CORE3_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_A53CORE3_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_A53CORE3_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_A53CORE3_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name A53CORE3_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53CORE3_AUXSW_SW2_MASK          (0x3FU)
#define GPC_PGC_A53CORE3_AUXSW_SW2_SHIFT         (0U)
#define GPC_PGC_A53CORE3_AUXSW_SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_AUXSW_SW2_SHIFT)) & GPC_PGC_A53CORE3_AUXSW_SW2_MASK)

#define GPC_PGC_A53CORE3_AUXSW_ISO2SW2_MASK      (0x3F00U)
#define GPC_PGC_A53CORE3_AUXSW_ISO2SW2_SHIFT     (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53CORE3_AUXSW_ISO2SW2(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_A53CORE3_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_A53CORE3_AUXSW_PDN_CLK_DIV_SEL_MASK (0xF0000U)
#define GPC_PGC_A53CORE3_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53CORE3_AUXSW_PDN_CLK_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53CORE3_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53CORE3_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name A53SCU_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_CTRL_PCR_MASK             (0x1U)
#define GPC_PGC_A53SCU_CTRL_PCR_SHIFT            (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_A53SCU_CTRL_PCR(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_CTRL_PCR_SHIFT)) & GPC_PGC_A53SCU_CTRL_PCR_MASK)

#define GPC_PGC_A53SCU_CTRL_L2RSTDIS_MASK        (0x7EU)
#define GPC_PGC_A53SCU_CTRL_L2RSTDIS_SHIFT       (1U)
#define GPC_PGC_A53SCU_CTRL_L2RSTDIS(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_A53SCU_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_A53SCU_CTRL_DFTRAM_TCD1_MASK     (0x3F00U)
#define GPC_PGC_A53SCU_CTRL_DFTRAM_TCD1_SHIFT    (8U)
#define GPC_PGC_A53SCU_CTRL_DFTRAM_TCD1(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_A53SCU_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_A53SCU_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_A53SCU_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_A53SCU_CTRL_L2RETN_TCD1_TDR(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_A53SCU_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_A53SCU_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_A53SCU_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_A53SCU_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_A53SCU_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name A53SCU_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_PUPSCR_SW_MASK            (0x3FU)
#define GPC_PGC_A53SCU_PUPSCR_SW_SHIFT           (0U)
#define GPC_PGC_A53SCU_PUPSCR_SW(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PUPSCR_SW_SHIFT)) & GPC_PGC_A53SCU_PUPSCR_SW_MASK)

#define GPC_PGC_A53SCU_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_A53SCU_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_A53SCU_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53SCU_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53SCU_PUPSCR_SW2ISO_MASK        (0x7FFF80U)
#define GPC_PGC_A53SCU_PUPSCR_SW2ISO_SHIFT       (7U)
#define GPC_PGC_A53SCU_PUPSCR_SW2ISO(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53SCU_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_A53SCU_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_A53SCU_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_A53SCU_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53SCU_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name A53SCU_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_PDNSCR_ISO_MASK           (0x3FU)
#define GPC_PGC_A53SCU_PDNSCR_ISO_SHIFT          (0U)
#define GPC_PGC_A53SCU_PDNSCR_ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_ISO_MASK)

#define GPC_PGC_A53SCU_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_A53SCU_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_A53SCU_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_A53SCU_PDNSCR_ISO2SW_MASK        (0x3F00U)
#define GPC_PGC_A53SCU_PDNSCR_ISO2SW_SHIFT       (8U)
#define GPC_PGC_A53SCU_PDNSCR_ISO2SW(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_A53SCU_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_A53SCU_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_A53SCU_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_A53SCU_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_A53SCU_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_A53SCU_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name A53SCU_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_A53SCU_SR_PSR_MASK               (0x1U)
#define GPC_PGC_A53SCU_SR_PSR_SHIFT              (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_A53SCU_SR_PSR(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_SR_PSR_SHIFT)) & GPC_PGC_A53SCU_SR_PSR_MASK)

#define GPC_PGC_A53SCU_SR_L2RETN_FLAG_MASK       (0x2U)
#define GPC_PGC_A53SCU_SR_L2RETN_FLAG_SHIFT      (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_A53SCU_SR_L2RETN_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_A53SCU_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_A53SCU_SR_ALLOFF_FLAG_MASK       (0x4U)
#define GPC_PGC_A53SCU_SR_ALLOFF_FLAG_SHIFT      (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53SCU_SR_ALLOFF_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_A53SCU_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_A53SCU_SR_PUP_CLK_DIV_SEL_MASK   (0x78U)
#define GPC_PGC_A53SCU_SR_PUP_CLK_DIV_SEL_SHIFT  (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53SCU_SR_PUP_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53SCU_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_A53SCU_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_A53SCU_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_A53SCU_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_A53SCU_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name A53SCU_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_AUXSW_SW2_MASK            (0x3FU)
#define GPC_PGC_A53SCU_AUXSW_SW2_SHIFT           (0U)
#define GPC_PGC_A53SCU_AUXSW_SW2(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_SW2_SHIFT)) & GPC_PGC_A53SCU_AUXSW_SW2_MASK)

#define GPC_PGC_A53SCU_AUXSW_ISO2SW2_MASK        (0x3F00U)
#define GPC_PGC_A53SCU_AUXSW_ISO2SW2_SHIFT       (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_A53SCU_AUXSW_ISO2SW2(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_A53SCU_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_A53SCU_AUXSW_PDN_CLK_DIV_SEL_MASK (0xF0000U)
#define GPC_PGC_A53SCU_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_A53SCU_AUXSW_PDN_CLK_DIV_SEL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_A53SCU_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name MIX_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_MIX_CTRL_MIX_PCR_MASK            (0x1U)
#define GPC_PGC_MIX_CTRL_MIX_PCR_SHIFT           (0U)
/*! MIX_PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_MIX_CTRL_MIX_PCR(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_CTRL_MIX_PCR_SHIFT)) & GPC_PGC_MIX_CTRL_MIX_PCR_MASK)

#define GPC_PGC_MIX_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_MIX_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_MIX_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_MIX_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_MIX_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_MIX_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_MIX_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_MIX_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_MIX_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_MIX_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_MIX_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_MIX_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name MIX_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_MIX_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_MIX_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_MIX_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PUPSCR_SW_SHIFT)) & GPC_PGC_MIX_PUPSCR_SW_MASK)

#define GPC_PGC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_MIX_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_MIX_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_MIX_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_MIX_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_MIX_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_MIX_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_MIX_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_MIX_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name MIX_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_MIX_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_MIX_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_MIX_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PDNSCR_ISO_SHIFT)) & GPC_PGC_MIX_PDNSCR_ISO_MASK)

#define GPC_PGC_MIX_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_MIX_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_MIX_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_MIX_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_MIX_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_MIX_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_MIX_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_MIX_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_MIX_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_MIX_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_MIX_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_MIX_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_MIX_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_MIX_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_MIX_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_MIX_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name MIX_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_MIX_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_MIX_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_MIX_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_SR_PSR_SHIFT)) & GPC_PGC_MIX_SR_PSR_MASK)

#define GPC_PGC_MIX_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_MIX_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_MIX_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_MIX_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_MIX_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_MIX_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_MIX_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_MIX_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_MIX_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_MIX_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_MIX_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_MIX_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_MIX_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_MIX_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_MIX_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_MIX_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name MIX_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_MIX_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_MIX_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_MIX_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_AUXSW_SW2_SHIFT)) & GPC_PGC_MIX_AUXSW_SW2_MASK)

#define GPC_PGC_MIX_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_MIX_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_MIX_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_MIX_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_MIX_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_MIX_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_MIX_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_MIX_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_MIX_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU0_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU0_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU0_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU0_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_CTRL_PCR_SHIFT)) & GPC_PGC_PU0_CTRL_PCR_MASK)

#define GPC_PGC_PU0_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU0_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU0_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU0_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU0_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU0_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU0_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU0_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU0_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU0_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU0_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU0_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU0_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU0_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU0_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU0_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU0_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU0_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU0_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU0_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PUPSCR_SW_SHIFT)) & GPC_PGC_PU0_PUPSCR_SW_MASK)

#define GPC_PGC_PU0_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU0_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU0_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU0_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU0_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU0_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU0_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU0_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU0_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU0_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU0_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU0_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU0_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU0_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU0_PDNSCR_ISO_MASK)

#define GPC_PGC_PU0_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU0_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU0_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU0_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU0_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU0_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU0_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU0_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU0_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU0_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU0_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU0_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU0_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU0_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU0_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU0_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU0_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU0_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_SR_PSR_SHIFT)) & GPC_PGC_PU0_SR_PSR_MASK)

#define GPC_PGC_PU0_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU0_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU0_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU0_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU0_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU0_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU0_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU0_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU0_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU0_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU0_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU0_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU0_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU0_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU0_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU0_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU0_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU0_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU0_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU0_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_AUXSW_SW2_SHIFT)) & GPC_PGC_PU0_AUXSW_SW2_MASK)

#define GPC_PGC_PU0_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU0_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU0_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU0_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU0_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU0_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU0_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU0_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU0_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU1_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU1_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU1_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU1_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_CTRL_PCR_SHIFT)) & GPC_PGC_PU1_CTRL_PCR_MASK)

#define GPC_PGC_PU1_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU1_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU1_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU1_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU1_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU1_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU1_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU1_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU1_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU1_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU1_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU1_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU1_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU1_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU1_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU1_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU1_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU1_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU1_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU1_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PUPSCR_SW_SHIFT)) & GPC_PGC_PU1_PUPSCR_SW_MASK)

#define GPC_PGC_PU1_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU1_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU1_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU1_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU1_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU1_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU1_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU1_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU1_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU1_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU1_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU1_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU1_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU1_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU1_PDNSCR_ISO_MASK)

#define GPC_PGC_PU1_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU1_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU1_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU1_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU1_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU1_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU1_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU1_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU1_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU1_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU1_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU1_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU1_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU1_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU1_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU1_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU1_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU1_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_SR_PSR_SHIFT)) & GPC_PGC_PU1_SR_PSR_MASK)

#define GPC_PGC_PU1_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU1_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU1_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU1_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU1_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU1_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU1_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU1_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU1_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU1_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU1_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU1_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU1_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU1_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU1_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU1_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU1_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU1_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU1_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU1_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_AUXSW_SW2_SHIFT)) & GPC_PGC_PU1_AUXSW_SW2_MASK)

#define GPC_PGC_PU1_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU1_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU1_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU1_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU1_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU1_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU1_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU1_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU1_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU2_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU2_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU2_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU2_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_CTRL_PCR_SHIFT)) & GPC_PGC_PU2_CTRL_PCR_MASK)

#define GPC_PGC_PU2_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU2_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU2_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU2_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU2_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU2_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU2_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU2_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU2_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU2_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU2_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU2_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU2_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU2_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU2_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU2_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU2_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU2_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU2_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU2_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PUPSCR_SW_SHIFT)) & GPC_PGC_PU2_PUPSCR_SW_MASK)

#define GPC_PGC_PU2_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU2_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU2_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU2_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU2_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU2_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU2_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU2_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU2_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU2_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU2_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU2_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU2_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU2_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU2_PDNSCR_ISO_MASK)

#define GPC_PGC_PU2_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU2_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU2_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU2_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU2_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU2_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU2_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU2_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU2_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU2_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU2_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU2_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU2_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU2_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU2_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU2_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU2_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU2_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_SR_PSR_SHIFT)) & GPC_PGC_PU2_SR_PSR_MASK)

#define GPC_PGC_PU2_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU2_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU2_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU2_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU2_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU2_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU2_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU2_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU2_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU2_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU2_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU2_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU2_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU2_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU2_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU2_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU2_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU2_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU2_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU2_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_AUXSW_SW2_SHIFT)) & GPC_PGC_PU2_AUXSW_SW2_MASK)

#define GPC_PGC_PU2_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU2_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU2_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU2_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU2_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU2_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU2_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU2_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU2_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU3_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU3_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU3_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU3_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_CTRL_PCR_SHIFT)) & GPC_PGC_PU3_CTRL_PCR_MASK)

#define GPC_PGC_PU3_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU3_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU3_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU3_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU3_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU3_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU3_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU3_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU3_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU3_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU3_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU3_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU3_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU3_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU3_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU3_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU3_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU3_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU3_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU3_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PUPSCR_SW_SHIFT)) & GPC_PGC_PU3_PUPSCR_SW_MASK)

#define GPC_PGC_PU3_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU3_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU3_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU3_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU3_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU3_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU3_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU3_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU3_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU3_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU3_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU3_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU3_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU3_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU3_PDNSCR_ISO_MASK)

#define GPC_PGC_PU3_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU3_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU3_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU3_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU3_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU3_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU3_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU3_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU3_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU3_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU3_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU3_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU3_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU3_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU3_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU3_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU3_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU3_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_SR_PSR_SHIFT)) & GPC_PGC_PU3_SR_PSR_MASK)

#define GPC_PGC_PU3_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU3_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU3_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU3_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU3_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU3_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU3_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU3_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU3_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU3_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU3_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU3_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU3_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU3_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU3_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU3_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU3_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU3_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU3_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU3_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_AUXSW_SW2_SHIFT)) & GPC_PGC_PU3_AUXSW_SW2_MASK)

#define GPC_PGC_PU3_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU3_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU3_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU3_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU3_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU3_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU3_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU3_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU3_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU4_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU4_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU4_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU4_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_CTRL_PCR_SHIFT)) & GPC_PGC_PU4_CTRL_PCR_MASK)

#define GPC_PGC_PU4_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU4_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU4_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU4_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU4_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU4_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU4_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU4_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU4_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU4_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU4_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU4_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU4_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU4_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU4_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU4_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU4_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU4_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU4_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU4_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PUPSCR_SW_SHIFT)) & GPC_PGC_PU4_PUPSCR_SW_MASK)

#define GPC_PGC_PU4_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU4_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU4_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU4_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU4_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU4_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU4_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU4_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU4_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU4_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU4_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU4_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU4_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU4_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU4_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU4_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU4_PDNSCR_ISO_MASK)

#define GPC_PGC_PU4_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU4_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU4_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU4_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU4_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU4_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU4_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU4_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU4_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU4_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU4_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU4_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU4_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU4_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU4_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU4_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU4_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU4_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU4_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU4_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_SR_PSR_SHIFT)) & GPC_PGC_PU4_SR_PSR_MASK)

#define GPC_PGC_PU4_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU4_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU4_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU4_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU4_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU4_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU4_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU4_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU4_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU4_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU4_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU4_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU4_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU4_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU4_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU4_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU4_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU4_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU4_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU4_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_AUXSW_SW2_SHIFT)) & GPC_PGC_PU4_AUXSW_SW2_MASK)

#define GPC_PGC_PU4_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU4_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU4_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU4_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU4_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU4_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU4_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU4_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU4_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU5_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU5_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU5_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU5_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_CTRL_PCR_SHIFT)) & GPC_PGC_PU5_CTRL_PCR_MASK)

#define GPC_PGC_PU5_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU5_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU5_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU5_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU5_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU5_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU5_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU5_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU5_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU5_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU5_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU5_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU5_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU5_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU5_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU5_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU5_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU5_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU5_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU5_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PUPSCR_SW_SHIFT)) & GPC_PGC_PU5_PUPSCR_SW_MASK)

#define GPC_PGC_PU5_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU5_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU5_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU5_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU5_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU5_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU5_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU5_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU5_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU5_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU5_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU5_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU5_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU5_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU5_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU5_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU5_PDNSCR_ISO_MASK)

#define GPC_PGC_PU5_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU5_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU5_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU5_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU5_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU5_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU5_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU5_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU5_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU5_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU5_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU5_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU5_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU5_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU5_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU5_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU5_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU5_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU5_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU5_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_SR_PSR_SHIFT)) & GPC_PGC_PU5_SR_PSR_MASK)

#define GPC_PGC_PU5_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU5_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU5_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU5_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU5_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU5_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU5_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU5_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU5_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU5_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU5_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU5_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU5_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU5_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU5_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU5_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU5_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU5_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU5_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU5_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_AUXSW_SW2_SHIFT)) & GPC_PGC_PU5_AUXSW_SW2_MASK)

#define GPC_PGC_PU5_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU5_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU5_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU5_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU5_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU5_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU5_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU5_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU5_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU6_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU6_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU6_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU6_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_CTRL_PCR_SHIFT)) & GPC_PGC_PU6_CTRL_PCR_MASK)

#define GPC_PGC_PU6_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU6_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU6_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU6_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU6_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU6_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU6_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU6_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU6_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU6_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU6_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU6_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU6_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU6_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU6_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU6_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU6_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU6_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU6_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU6_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PUPSCR_SW_SHIFT)) & GPC_PGC_PU6_PUPSCR_SW_MASK)

#define GPC_PGC_PU6_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU6_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU6_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU6_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU6_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU6_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU6_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU6_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU6_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU6_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU6_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU6_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU6_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU6_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU6_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU6_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU6_PDNSCR_ISO_MASK)

#define GPC_PGC_PU6_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU6_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU6_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU6_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU6_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU6_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU6_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU6_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU6_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU6_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU6_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU6_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU6_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU6_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU6_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU6_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU6_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU6_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU6_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU6_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_SR_PSR_SHIFT)) & GPC_PGC_PU6_SR_PSR_MASK)

#define GPC_PGC_PU6_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU6_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU6_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU6_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU6_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU6_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU6_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU6_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU6_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU6_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU6_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU6_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU6_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU6_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU6_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU6_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU6_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU6_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU6_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU6_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_AUXSW_SW2_SHIFT)) & GPC_PGC_PU6_AUXSW_SW2_MASK)

#define GPC_PGC_PU6_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU6_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU6_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU6_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU6_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU6_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU6_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU6_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU6_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU7_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU7_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU7_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU7_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_CTRL_PCR_SHIFT)) & GPC_PGC_PU7_CTRL_PCR_MASK)

#define GPC_PGC_PU7_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU7_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU7_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU7_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU7_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU7_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU7_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU7_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU7_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU7_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU7_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU7_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU7_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU7_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU7_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU7_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU7_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU7_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU7_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU7_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PUPSCR_SW_SHIFT)) & GPC_PGC_PU7_PUPSCR_SW_MASK)

#define GPC_PGC_PU7_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU7_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU7_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU7_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU7_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU7_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU7_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU7_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU7_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU7_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU7_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU7_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU7_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU7_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU7_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU7_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU7_PDNSCR_ISO_MASK)

#define GPC_PGC_PU7_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU7_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU7_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU7_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU7_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU7_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU7_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU7_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU7_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU7_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU7_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU7_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU7_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU7_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU7_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU7_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU7_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU7_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU7_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU7_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_SR_PSR_SHIFT)) & GPC_PGC_PU7_SR_PSR_MASK)

#define GPC_PGC_PU7_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU7_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU7_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU7_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU7_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU7_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU7_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU7_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU7_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU7_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU7_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU7_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU7_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU7_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU7_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU7_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU7_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU7_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU7_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU7_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_AUXSW_SW2_SHIFT)) & GPC_PGC_PU7_AUXSW_SW2_MASK)

#define GPC_PGC_PU7_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU7_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU7_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU7_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU7_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU7_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU7_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU7_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU7_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU8_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU8_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU8_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU8_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_CTRL_PCR_SHIFT)) & GPC_PGC_PU8_CTRL_PCR_MASK)

#define GPC_PGC_PU8_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU8_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU8_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU8_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU8_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU8_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU8_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU8_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU8_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU8_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU8_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU8_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU8_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU8_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU8_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU8_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU8_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU8_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU8_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU8_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PUPSCR_SW_SHIFT)) & GPC_PGC_PU8_PUPSCR_SW_MASK)

#define GPC_PGC_PU8_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU8_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU8_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU8_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU8_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU8_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU8_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU8_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU8_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU8_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU8_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU8_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU8_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU8_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU8_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU8_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU8_PDNSCR_ISO_MASK)

#define GPC_PGC_PU8_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU8_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU8_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU8_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU8_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU8_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU8_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU8_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU8_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU8_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU8_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU8_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU8_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU8_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU8_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU8_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU8_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU8_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU8_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU8_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_SR_PSR_SHIFT)) & GPC_PGC_PU8_SR_PSR_MASK)

#define GPC_PGC_PU8_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU8_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU8_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU8_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU8_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU8_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU8_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU8_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU8_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU8_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU8_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU8_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU8_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU8_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU8_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU8_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU8_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU8_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU8_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU8_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_AUXSW_SW2_SHIFT)) & GPC_PGC_PU8_AUXSW_SW2_MASK)

#define GPC_PGC_PU8_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU8_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU8_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU8_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU8_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU8_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU8_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU8_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU8_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU9_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU9_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PU9_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU9_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_CTRL_PCR_SHIFT)) & GPC_PGC_PU9_CTRL_PCR_MASK)

#define GPC_PGC_PU9_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PU9_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PU9_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU9_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU9_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PU9_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PU9_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU9_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU9_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PU9_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PU9_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU9_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU9_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU9_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU9_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU9_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU9_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU9_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PU9_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PU9_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PUPSCR_SW_SHIFT)) & GPC_PGC_PU9_PUPSCR_SW_MASK)

#define GPC_PGC_PU9_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU9_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU9_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU9_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU9_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PU9_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PU9_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU9_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU9_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU9_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU9_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU9_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU9_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU9_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PU9_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PU9_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU9_PDNSCR_ISO_MASK)

#define GPC_PGC_PU9_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU9_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU9_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU9_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU9_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PU9_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PU9_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU9_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU9_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU9_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU9_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU9_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU9_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU9_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU9_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU9_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU9_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU9_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PU9_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU9_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_SR_PSR_SHIFT)) & GPC_PGC_PU9_SR_PSR_MASK)

#define GPC_PGC_PU9_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PU9_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU9_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU9_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU9_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PU9_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU9_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU9_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU9_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PU9_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU9_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU9_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU9_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU9_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU9_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU9_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU9_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU9_AUXSW_SW2_MASK               (0x3FU)
#define GPC_PGC_PU9_AUXSW_SW2_SHIFT              (0U)
#define GPC_PGC_PU9_AUXSW_SW2(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_AUXSW_SW2_SHIFT)) & GPC_PGC_PU9_AUXSW_SW2_MASK)

#define GPC_PGC_PU9_AUXSW_ISO2SW2_MASK           (0x3F00U)
#define GPC_PGC_PU9_AUXSW_ISO2SW2_SHIFT          (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU9_AUXSW_ISO2SW2(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU9_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU9_AUXSW_PDN_CLK_DIV_SEL_MASK   (0xF0000U)
#define GPC_PGC_PU9_AUXSW_PDN_CLK_DIV_SEL_SHIFT  (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU9_AUXSW_PDN_CLK_DIV_SEL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU9_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU9_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU10_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU10_CTRL_PCR_MASK               (0x1U)
#define GPC_PGC_PU10_CTRL_PCR_SHIFT              (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU10_CTRL_PCR(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_CTRL_PCR_SHIFT)) & GPC_PGC_PU10_CTRL_PCR_MASK)

#define GPC_PGC_PU10_CTRL_L2RSTDIS_MASK          (0x7EU)
#define GPC_PGC_PU10_CTRL_L2RSTDIS_SHIFT         (1U)
#define GPC_PGC_PU10_CTRL_L2RSTDIS(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU10_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU10_CTRL_DFTRAM_TCD1_MASK       (0x3F00U)
#define GPC_PGC_PU10_CTRL_DFTRAM_TCD1_SHIFT      (8U)
#define GPC_PGC_PU10_CTRL_DFTRAM_TCD1(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU10_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU10_CTRL_L2RETN_TCD1_TDR_MASK   (0x3F0000U)
#define GPC_PGC_PU10_CTRL_L2RETN_TCD1_TDR_SHIFT  (16U)
#define GPC_PGC_PU10_CTRL_L2RETN_TCD1_TDR(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU10_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU10_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU10_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU10_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU10_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU10_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU10_PUPSCR_SW_MASK              (0x3FU)
#define GPC_PGC_PU10_PUPSCR_SW_SHIFT             (0U)
#define GPC_PGC_PU10_PUPSCR_SW(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PUPSCR_SW_SHIFT)) & GPC_PGC_PU10_PUPSCR_SW_MASK)

#define GPC_PGC_PU10_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU10_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU10_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU10_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU10_PUPSCR_SW2ISO_MASK          (0x7FFF80U)
#define GPC_PGC_PU10_PUPSCR_SW2ISO_SHIFT         (7U)
#define GPC_PGC_PU10_PUPSCR_SW2ISO(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU10_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU10_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU10_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU10_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU10_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU10_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU10_PDNSCR_ISO_MASK             (0x3FU)
#define GPC_PGC_PU10_PDNSCR_ISO_SHIFT            (0U)
#define GPC_PGC_PU10_PDNSCR_ISO(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU10_PDNSCR_ISO_MASK)

#define GPC_PGC_PU10_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU10_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU10_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU10_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU10_PDNSCR_ISO2SW_MASK          (0x3F00U)
#define GPC_PGC_PU10_PDNSCR_ISO2SW_SHIFT         (8U)
#define GPC_PGC_PU10_PDNSCR_ISO2SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU10_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU10_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU10_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU10_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU10_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU10_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU10_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU10_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU10_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU10_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU10_SR_PSR_MASK                 (0x1U)
#define GPC_PGC_PU10_SR_PSR_SHIFT                (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU10_SR_PSR(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_SR_PSR_SHIFT)) & GPC_PGC_PU10_SR_PSR_MASK)

#define GPC_PGC_PU10_SR_L2RETN_FLAG_MASK         (0x2U)
#define GPC_PGC_PU10_SR_L2RETN_FLAG_SHIFT        (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU10_SR_L2RETN_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU10_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU10_SR_ALLOFF_FLAG_MASK         (0x4U)
#define GPC_PGC_PU10_SR_ALLOFF_FLAG_SHIFT        (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU10_SR_ALLOFF_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU10_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU10_SR_PUP_CLK_DIV_SEL_MASK     (0x78U)
#define GPC_PGC_PU10_SR_PUP_CLK_DIV_SEL_SHIFT    (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU10_SR_PUP_CLK_DIV_SEL(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU10_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU10_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU10_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU10_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU10_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU10_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU10_AUXSW_SW2_MASK              (0x3FU)
#define GPC_PGC_PU10_AUXSW_SW2_SHIFT             (0U)
#define GPC_PGC_PU10_AUXSW_SW2(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_AUXSW_SW2_SHIFT)) & GPC_PGC_PU10_AUXSW_SW2_MASK)

#define GPC_PGC_PU10_AUXSW_ISO2SW2_MASK          (0x3F00U)
#define GPC_PGC_PU10_AUXSW_ISO2SW2_SHIFT         (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU10_AUXSW_ISO2SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU10_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU10_AUXSW_PDN_CLK_DIV_SEL_MASK  (0xF0000U)
#define GPC_PGC_PU10_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU10_AUXSW_PDN_CLK_DIV_SEL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU10_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU10_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU11_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU11_CTRL_PCR_MASK               (0x1U)
#define GPC_PGC_PU11_CTRL_PCR_SHIFT              (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU11_CTRL_PCR(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_CTRL_PCR_SHIFT)) & GPC_PGC_PU11_CTRL_PCR_MASK)

#define GPC_PGC_PU11_CTRL_L2RSTDIS_MASK          (0x7EU)
#define GPC_PGC_PU11_CTRL_L2RSTDIS_SHIFT         (1U)
#define GPC_PGC_PU11_CTRL_L2RSTDIS(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU11_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU11_CTRL_DFTRAM_TCD1_MASK       (0x3F00U)
#define GPC_PGC_PU11_CTRL_DFTRAM_TCD1_SHIFT      (8U)
#define GPC_PGC_PU11_CTRL_DFTRAM_TCD1(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU11_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU11_CTRL_L2RETN_TCD1_TDR_MASK   (0x3F0000U)
#define GPC_PGC_PU11_CTRL_L2RETN_TCD1_TDR_SHIFT  (16U)
#define GPC_PGC_PU11_CTRL_L2RETN_TCD1_TDR(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU11_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU11_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU11_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU11_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU11_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU11_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU11_PUPSCR_SW_MASK              (0x3FU)
#define GPC_PGC_PU11_PUPSCR_SW_SHIFT             (0U)
#define GPC_PGC_PU11_PUPSCR_SW(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PUPSCR_SW_SHIFT)) & GPC_PGC_PU11_PUPSCR_SW_MASK)

#define GPC_PGC_PU11_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU11_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU11_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU11_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU11_PUPSCR_SW2ISO_MASK          (0x7FFF80U)
#define GPC_PGC_PU11_PUPSCR_SW2ISO_SHIFT         (7U)
#define GPC_PGC_PU11_PUPSCR_SW2ISO(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU11_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU11_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU11_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU11_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU11_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU11_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU11_PDNSCR_ISO_MASK             (0x3FU)
#define GPC_PGC_PU11_PDNSCR_ISO_SHIFT            (0U)
#define GPC_PGC_PU11_PDNSCR_ISO(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU11_PDNSCR_ISO_MASK)

#define GPC_PGC_PU11_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU11_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU11_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU11_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU11_PDNSCR_ISO2SW_MASK          (0x3F00U)
#define GPC_PGC_PU11_PDNSCR_ISO2SW_SHIFT         (8U)
#define GPC_PGC_PU11_PDNSCR_ISO2SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU11_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU11_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU11_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU11_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU11_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU11_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU11_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU11_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU11_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU11_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU11_SR_PSR_MASK                 (0x1U)
#define GPC_PGC_PU11_SR_PSR_SHIFT                (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU11_SR_PSR(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_SR_PSR_SHIFT)) & GPC_PGC_PU11_SR_PSR_MASK)

#define GPC_PGC_PU11_SR_L2RETN_FLAG_MASK         (0x2U)
#define GPC_PGC_PU11_SR_L2RETN_FLAG_SHIFT        (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU11_SR_L2RETN_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU11_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU11_SR_ALLOFF_FLAG_MASK         (0x4U)
#define GPC_PGC_PU11_SR_ALLOFF_FLAG_SHIFT        (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU11_SR_ALLOFF_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU11_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU11_SR_PUP_CLK_DIV_SEL_MASK     (0x78U)
#define GPC_PGC_PU11_SR_PUP_CLK_DIV_SEL_SHIFT    (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU11_SR_PUP_CLK_DIV_SEL(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU11_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU11_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU11_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU11_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU11_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU11_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU11_AUXSW_SW2_MASK              (0x3FU)
#define GPC_PGC_PU11_AUXSW_SW2_SHIFT             (0U)
#define GPC_PGC_PU11_AUXSW_SW2(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_AUXSW_SW2_SHIFT)) & GPC_PGC_PU11_AUXSW_SW2_MASK)

#define GPC_PGC_PU11_AUXSW_ISO2SW2_MASK          (0x3F00U)
#define GPC_PGC_PU11_AUXSW_ISO2SW2_SHIFT         (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU11_AUXSW_ISO2SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU11_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU11_AUXSW_PDN_CLK_DIV_SEL_MASK  (0xF0000U)
#define GPC_PGC_PU11_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU11_AUXSW_PDN_CLK_DIV_SEL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU11_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU11_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU12_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU12_CTRL_PCR_MASK               (0x1U)
#define GPC_PGC_PU12_CTRL_PCR_SHIFT              (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU12_CTRL_PCR(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_CTRL_PCR_SHIFT)) & GPC_PGC_PU12_CTRL_PCR_MASK)

#define GPC_PGC_PU12_CTRL_L2RSTDIS_MASK          (0x7EU)
#define GPC_PGC_PU12_CTRL_L2RSTDIS_SHIFT         (1U)
#define GPC_PGC_PU12_CTRL_L2RSTDIS(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU12_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU12_CTRL_DFTRAM_TCD1_MASK       (0x3F00U)
#define GPC_PGC_PU12_CTRL_DFTRAM_TCD1_SHIFT      (8U)
#define GPC_PGC_PU12_CTRL_DFTRAM_TCD1(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU12_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU12_CTRL_L2RETN_TCD1_TDR_MASK   (0x3F0000U)
#define GPC_PGC_PU12_CTRL_L2RETN_TCD1_TDR_SHIFT  (16U)
#define GPC_PGC_PU12_CTRL_L2RETN_TCD1_TDR(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU12_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU12_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU12_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU12_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU12_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU12_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU12_PUPSCR_SW_MASK              (0x3FU)
#define GPC_PGC_PU12_PUPSCR_SW_SHIFT             (0U)
#define GPC_PGC_PU12_PUPSCR_SW(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PUPSCR_SW_SHIFT)) & GPC_PGC_PU12_PUPSCR_SW_MASK)

#define GPC_PGC_PU12_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU12_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU12_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU12_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU12_PUPSCR_SW2ISO_MASK          (0x7FFF80U)
#define GPC_PGC_PU12_PUPSCR_SW2ISO_SHIFT         (7U)
#define GPC_PGC_PU12_PUPSCR_SW2ISO(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU12_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU12_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU12_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU12_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU12_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU12_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU12_PDNSCR_ISO_MASK             (0x3FU)
#define GPC_PGC_PU12_PDNSCR_ISO_SHIFT            (0U)
#define GPC_PGC_PU12_PDNSCR_ISO(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU12_PDNSCR_ISO_MASK)

#define GPC_PGC_PU12_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU12_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU12_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU12_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU12_PDNSCR_ISO2SW_MASK          (0x3F00U)
#define GPC_PGC_PU12_PDNSCR_ISO2SW_SHIFT         (8U)
#define GPC_PGC_PU12_PDNSCR_ISO2SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU12_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU12_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU12_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU12_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU12_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU12_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU12_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU12_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU12_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU12_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU12_SR_PSR_MASK                 (0x1U)
#define GPC_PGC_PU12_SR_PSR_SHIFT                (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU12_SR_PSR(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_SR_PSR_SHIFT)) & GPC_PGC_PU12_SR_PSR_MASK)

#define GPC_PGC_PU12_SR_L2RETN_FLAG_MASK         (0x2U)
#define GPC_PGC_PU12_SR_L2RETN_FLAG_SHIFT        (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU12_SR_L2RETN_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU12_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU12_SR_ALLOFF_FLAG_MASK         (0x4U)
#define GPC_PGC_PU12_SR_ALLOFF_FLAG_SHIFT        (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU12_SR_ALLOFF_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU12_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU12_SR_PUP_CLK_DIV_SEL_MASK     (0x78U)
#define GPC_PGC_PU12_SR_PUP_CLK_DIV_SEL_SHIFT    (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU12_SR_PUP_CLK_DIV_SEL(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU12_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU12_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU12_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU12_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU12_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU12_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU12_AUXSW_SW2_MASK              (0x3FU)
#define GPC_PGC_PU12_AUXSW_SW2_SHIFT             (0U)
#define GPC_PGC_PU12_AUXSW_SW2(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_AUXSW_SW2_SHIFT)) & GPC_PGC_PU12_AUXSW_SW2_MASK)

#define GPC_PGC_PU12_AUXSW_ISO2SW2_MASK          (0x3F00U)
#define GPC_PGC_PU12_AUXSW_ISO2SW2_SHIFT         (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU12_AUXSW_ISO2SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU12_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU12_AUXSW_PDN_CLK_DIV_SEL_MASK  (0xF0000U)
#define GPC_PGC_PU12_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU12_AUXSW_PDN_CLK_DIV_SEL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU12_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU12_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */

/*! @name PU13_CTRL - GPC PGC Control Register */
/*! @{ */

#define GPC_PGC_PU13_CTRL_PCR_MASK               (0x1U)
#define GPC_PGC_PU13_CTRL_PCR_SHIFT              (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU13_CTRL_PCR(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_CTRL_PCR_SHIFT)) & GPC_PGC_PU13_CTRL_PCR_MASK)

#define GPC_PGC_PU13_CTRL_L2RSTDIS_MASK          (0x7EU)
#define GPC_PGC_PU13_CTRL_L2RSTDIS_SHIFT         (1U)
#define GPC_PGC_PU13_CTRL_L2RSTDIS(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU13_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU13_CTRL_DFTRAM_TCD1_MASK       (0x3F00U)
#define GPC_PGC_PU13_CTRL_DFTRAM_TCD1_SHIFT      (8U)
#define GPC_PGC_PU13_CTRL_DFTRAM_TCD1(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU13_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU13_CTRL_L2RETN_TCD1_TDR_MASK   (0x3F0000U)
#define GPC_PGC_PU13_CTRL_L2RETN_TCD1_TDR_SHIFT  (16U)
#define GPC_PGC_PU13_CTRL_L2RETN_TCD1_TDR(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU13_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU13_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU13_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU13_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU13_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name PU13_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU13_PUPSCR_SW_MASK              (0x3FU)
#define GPC_PGC_PU13_PUPSCR_SW_SHIFT             (0U)
#define GPC_PGC_PU13_PUPSCR_SW(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PUPSCR_SW_SHIFT)) & GPC_PGC_PU13_PUPSCR_SW_MASK)

#define GPC_PGC_PU13_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_PU13_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_PU13_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU13_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU13_PUPSCR_SW2ISO_MASK          (0x7FFF80U)
#define GPC_PGC_PU13_PUPSCR_SW2ISO_SHIFT         (7U)
#define GPC_PGC_PU13_PUPSCR_SW2ISO(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU13_PUPSCR_SW2ISO_MASK)

#define GPC_PGC_PU13_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK (0xFF800000U)
#define GPC_PGC_PU13_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT (23U)
#define GPC_PGC_PU13_PUPSCR_PUP_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PUPSCR_PUP_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU13_PUPSCR_PUP_SCALL_SCALLOUT_CNT_MASK)
/*! @} */

/*! @name PU13_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU13_PDNSCR_ISO_MASK             (0x3FU)
#define GPC_PGC_PU13_PDNSCR_ISO_SHIFT            (0U)
#define GPC_PGC_PU13_PDNSCR_ISO(x)               (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU13_PDNSCR_ISO_MASK)

#define GPC_PGC_PU13_PDNSCR_PDN_WAIT_SCALL_OUT_MASK (0x80U)
#define GPC_PGC_PU13_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT (7U)
/*! PDN_WAIT_SCALL_OUT - Default 1'b0 */
#define GPC_PGC_PU13_PDNSCR_PDN_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PDNSCR_PDN_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_PU13_PDNSCR_PDN_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_PU13_PDNSCR_ISO2SW_MASK          (0x3F00U)
#define GPC_PGC_PU13_PDNSCR_ISO2SW_SHIFT         (8U)
#define GPC_PGC_PU13_PDNSCR_ISO2SW(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU13_PDNSCR_ISO2SW_MASK)

#define GPC_PGC_PU13_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK (0xFF0000U)
#define GPC_PGC_PU13_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT (16U)
#define GPC_PGC_PU13_PDNSCR_PDN_SCALL_SCALLOUT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PDNSCR_PDN_SCALL_SCALLOUT_CNT_SHIFT)) & GPC_PGC_PU13_PDNSCR_PDN_SCALL_SCALLOUT_CNT_MASK)

#define GPC_PGC_PU13_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK (0xFF000000U)
#define GPC_PGC_PU13_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT (24U)
#define GPC_PGC_PU13_PDNSCR_PUP_SCPRE_SCALL_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_PDNSCR_PUP_SCPRE_SCALL_CNT_SHIFT)) & GPC_PGC_PU13_PDNSCR_PUP_SCPRE_SCALL_CNT_MASK)
/*! @} */

/*! @name PU13_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU13_SR_PSR_MASK                 (0x1U)
#define GPC_PGC_PU13_SR_PSR_SHIFT                (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU13_SR_PSR(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_SR_PSR_SHIFT)) & GPC_PGC_PU13_SR_PSR_MASK)

#define GPC_PGC_PU13_SR_L2RETN_FLAG_MASK         (0x2U)
#define GPC_PGC_PU13_SR_L2RETN_FLAG_SHIFT        (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU13_SR_L2RETN_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU13_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU13_SR_ALLOFF_FLAG_MASK         (0x4U)
#define GPC_PGC_PU13_SR_ALLOFF_FLAG_SHIFT        (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU13_SR_ALLOFF_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU13_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU13_SR_PUP_CLK_DIV_SEL_MASK     (0x78U)
#define GPC_PGC_PU13_SR_PUP_CLK_DIV_SEL_SHIFT    (3U)
/*! PUP_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU13_SR_PUP_CLK_DIV_SEL(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU13_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU13_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU13_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU13_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU13_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU13_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_PU13_AUXSW_SW2_MASK              (0x3FU)
#define GPC_PGC_PU13_AUXSW_SW2_SHIFT             (0U)
#define GPC_PGC_PU13_AUXSW_SW2(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_AUXSW_SW2_SHIFT)) & GPC_PGC_PU13_AUXSW_SW2_MASK)

#define GPC_PGC_PU13_AUXSW_ISO2SW2_MASK          (0x3F00U)
#define GPC_PGC_PU13_AUXSW_ISO2SW2_SHIFT         (8U)
/*! ISO2SW2
 *  0b000000..A53 is not wakeup from ALL_OFF mode.
 *  0b000001..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU13_AUXSW_ISO2SW2(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_AUXSW_ISO2SW2_SHIFT)) & GPC_PGC_PU13_AUXSW_ISO2SW2_MASK)

#define GPC_PGC_PU13_AUXSW_PDN_CLK_DIV_SEL_MASK  (0xF0000U)
#define GPC_PGC_PU13_AUXSW_PDN_CLK_DIV_SEL_SHIFT (16U)
/*! PDN_CLK_DIV_SEL
 *  0b0000..1
 *  0b0001..1/2 count_clk
 *  0b0010..1/4 count_clk
 *  0b0011..1/8 count_clk
 *  0b0100..1/16 count_clk
 *  0b0101..1/32 count_clk
 *  0b0110..1/64 count_clk
 *  0b0111..1/128 count_clk
 *  0b1000..1/256 count_clk
 *  0b1001..1/512 count_clk
 *  0b1010..1/1024 count_clk
 *  0b1011..1/2056 count_clk
 *  0b1100..1/4096 count_clk
 *  0b1101..1/8192 count_clk
 *  0b1110..1/16384 count_clk
 *  0b1111..1/32768 count_clk
 */
#define GPC_PGC_PU13_AUXSW_PDN_CLK_DIV_SEL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU13_AUXSW_PDN_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU13_AUXSW_PDN_CLK_DIV_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_PGC_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_PGC_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_PGC_H_ */

