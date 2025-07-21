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
 * @file PERI_GPC_PGC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_PGC
 *
 * CMSIS Peripheral Access Layer for GPC_PGC
 */

#if !defined(PERI_GPC_PGC_H_)
#define PERI_GPC_PGC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- GPC_PGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_PGC_Peripheral_Access_Layer GPC_PGC Peripheral Access Layer
 * @{
 */

/** GPC_PGC - Size of Registers Arrays */
#define GPC_PGC_GPC_PGC_A53COREnCTRL_COUNT        4u
#define GPC_PGC_GPC_PGC_CTRL_COUNT                20u

/** GPC_PGC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  struct {                                         /* offset: 0x800, array step: 0x40 */
    __IO uint32_t PGC_CTRL;                          /**< GPC PGC Control Register for PGC CPUs, array offset: 0x800, array step: 0x40 */
    __IO uint32_t PGC_PUPSCR;                        /**< GPC PGC Up Sequence Control Register, array offset: 0x804, array step: 0x40 */
    __IO uint32_t PGC_PDNSCR;                        /**< GPC PGC Down Sequence Control Register, array offset: 0x808, array step: 0x40 */
    __IO uint32_t PGC_SR;                            /**< GPC PGC Status Register, array offset: 0x80C, array step: 0x40 */
         uint8_t RESERVED_0[48];
  } GPC_PGC_A53COREnCTRL[GPC_PGC_GPC_PGC_A53COREnCTRL_COUNT];
  __IO uint32_t A53SCU_CTRL;                       /**< GPC PGC Control Register for PGC CPUs, offset: 0x900 */
  __IO uint32_t A53SCU_PUPSCR;                     /**< GPC PGC Up Sequence Control Register, offset: 0x904 */
  __IO uint32_t A53SCU_PDNSCR;                     /**< GPC PGC Down Sequence Control Register, offset: 0x908 */
  __IO uint32_t A53SCU_SR;                         /**< GPC PGC Status Register, offset: 0x90C */
       uint8_t RESERVED_1[304];
  __IO uint32_t NOC_MIX_CTRL;                      /**< GPC PGC Control Register for PGC MIX., offset: 0xA40 */
  __IO uint32_t NOC_MIX_PUPSCR;                    /**< GPC PGC Up Sequence Control Register, offset: 0xA44 */
  __IO uint32_t NOC_MIX_PDNSCR;                    /**< GPC PGC Down Sequence Control Register, offset: 0xA48 */
  __IO uint32_t NOC_MIX_SR;                        /**< GPC PGC Status Register, offset: 0xA4C */
       uint8_t RESERVED_2[176];
  struct {                                         /* offset: 0xB00, array step: 0x40 */
    __IO uint32_t PU_CTRL;                           /**< GPC PGC Control Register for PGC PUs, array offset: 0xB00, array step: 0x40 */
    __IO uint32_t PU_PUPSCR;                         /**< GPC PGC Up Sequence Control Register, array offset: 0xB04, array step: 0x40 */
    __IO uint32_t PU_PDNSCR;                         /**< GPC PGC Down Sequence Control Register, array offset: 0xB08, array step: 0x40 */
    __IO uint32_t PU_SR;                             /**< GPC PGC Status Register, array offset: 0xB0C, array step: 0x40 */
         uint8_t RESERVED_0[48];
  } GPC_PGC_CTRL[GPC_PGC_GPC_PGC_CTRL_COUNT];
} GPC_PGC_Type;

/* ----------------------------------------------------------------------------
   -- GPC_PGC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_PGC_Register_Masks GPC_PGC Register Masks
 * @{
 */

/*! @name PGC_CTRL - GPC PGC Control Register for PGC CPUs */
/*! @{ */

#define GPC_PGC_PGC_CTRL_PCR_MASK                (0x1U)
#define GPC_PGC_PGC_CTRL_PCR_SHIFT               (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PGC_CTRL_PCR(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_CTRL_PCR_SHIFT)) & GPC_PGC_PGC_CTRL_PCR_MASK)

#define GPC_PGC_PGC_CTRL_L2RSTDIS_MASK           (0x7EU)
#define GPC_PGC_PGC_CTRL_L2RSTDIS_SHIFT          (1U)
#define GPC_PGC_PGC_CTRL_L2RSTDIS(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PGC_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PGC_CTRL_DFTRAM_TCD1_MASK        (0x3F00U)
#define GPC_PGC_PGC_CTRL_DFTRAM_TCD1_SHIFT       (8U)
#define GPC_PGC_PGC_CTRL_DFTRAM_TCD1(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PGC_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PGC_CTRL_L2RETN_TCD1_TDR_MASK    (0x3F0000U)
#define GPC_PGC_PGC_CTRL_L2RETN_TCD1_TDR_SHIFT   (16U)
#define GPC_PGC_PGC_CTRL_L2RETN_TCD1_TDR(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PGC_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/* The count of GPC_PGC_PGC_CTRL */
#define GPC_PGC_PGC_CTRL_COUNT                   (4U)

/*! @name PGC_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PGC_PUPSCR_SW_MASK               (0x3FU)
#define GPC_PGC_PGC_PUPSCR_SW_SHIFT              (0U)
#define GPC_PGC_PGC_PUPSCR_SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_PUPSCR_SW_SHIFT)) & GPC_PGC_PGC_PUPSCR_SW_MASK)

#define GPC_PGC_PGC_PUPSCR_SW2ISO_MASK           (0x7FFF80U)
#define GPC_PGC_PGC_PUPSCR_SW2ISO_SHIFT          (7U)
#define GPC_PGC_PGC_PUPSCR_SW2ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PGC_PUPSCR_SW2ISO_MASK)
/*! @} */

/* The count of GPC_PGC_PGC_PUPSCR */
#define GPC_PGC_PGC_PUPSCR_COUNT                 (4U)

/*! @name PGC_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PGC_PDNSCR_ISO_MASK              (0x3FU)
#define GPC_PGC_PGC_PDNSCR_ISO_SHIFT             (0U)
#define GPC_PGC_PGC_PDNSCR_ISO(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_PDNSCR_ISO_SHIFT)) & GPC_PGC_PGC_PDNSCR_ISO_MASK)

#define GPC_PGC_PGC_PDNSCR_ISO2SW_MASK           (0x3F00U)
#define GPC_PGC_PGC_PDNSCR_ISO2SW_SHIFT          (8U)
#define GPC_PGC_PGC_PDNSCR_ISO2SW(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PGC_PDNSCR_ISO2SW_MASK)
/*! @} */

/* The count of GPC_PGC_PGC_PDNSCR */
#define GPC_PGC_PGC_PDNSCR_COUNT                 (4U)

/*! @name PGC_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PGC_SR_PSR_MASK                  (0x1U)
#define GPC_PGC_PGC_SR_PSR_SHIFT                 (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PGC_SR_PSR(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_SR_PSR_SHIFT)) & GPC_PGC_PGC_SR_PSR_MASK)

#define GPC_PGC_PGC_SR_L2RETN_FLAG_MASK          (0x2U)
#define GPC_PGC_PGC_SR_L2RETN_FLAG_SHIFT         (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PGC_SR_L2RETN_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PGC_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PGC_SR_ALLOFF_FLAG_MASK          (0x4U)
#define GPC_PGC_PGC_SR_ALLOFF_FLAG_SHIFT         (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PGC_SR_ALLOFF_FLAG(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PGC_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PGC_SR_PUP_CLK_DIV_SEL_MASK      (0x78U)
#define GPC_PGC_PGC_SR_PUP_CLK_DIV_SEL_SHIFT     (3U)
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
#define GPC_PGC_PGC_SR_PUP_CLK_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PGC_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PGC_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PGC_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PGC_SR_L2RSTDIS_DEASSERT_CNT(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PGC_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PGC_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/* The count of GPC_PGC_PGC_SR */
#define GPC_PGC_PGC_SR_COUNT                     (4U)

/*! @name A53SCU_CTRL - GPC PGC Control Register for PGC CPUs */
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

#define GPC_PGC_A53SCU_PUPSCR_SW2ISO_MASK        (0x7FFF80U)
#define GPC_PGC_A53SCU_PUPSCR_SW2ISO_SHIFT       (7U)
#define GPC_PGC_A53SCU_PUPSCR_SW2ISO(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_A53SCU_PUPSCR_SW2ISO_MASK)
/*! @} */

/*! @name A53SCU_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_PDNSCR_ISO_MASK           (0x3FU)
#define GPC_PGC_A53SCU_PDNSCR_ISO_SHIFT          (0U)
#define GPC_PGC_A53SCU_PDNSCR_ISO(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_ISO_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_ISO_MASK)

#define GPC_PGC_A53SCU_PDNSCR_ISO2SW_MASK        (0x3F00U)
#define GPC_PGC_A53SCU_PDNSCR_ISO2SW_SHIFT       (8U)
#define GPC_PGC_A53SCU_PDNSCR_ISO2SW(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_A53SCU_PDNSCR_ISO2SW_MASK)
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

/*! @name NOC_MIX_CTRL - GPC PGC Control Register for PGC MIX. */
/*! @{ */

#define GPC_PGC_NOC_MIX_CTRL_MIX_PCR_MASK        (0x1U)
#define GPC_PGC_NOC_MIX_CTRL_MIX_PCR_SHIFT       (0U)
/*! MIX_PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_NOC_MIX_CTRL_MIX_PCR(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_CTRL_MIX_PCR_SHIFT)) & GPC_PGC_NOC_MIX_CTRL_MIX_PCR_MASK)

#define GPC_PGC_NOC_MIX_CTRL_L2RSTDIS_MASK       (0x7EU)
#define GPC_PGC_NOC_MIX_CTRL_L2RSTDIS_SHIFT      (1U)
#define GPC_PGC_NOC_MIX_CTRL_L2RSTDIS(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_NOC_MIX_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_NOC_MIX_CTRL_DFTRAM_TCD1_MASK    (0x3F00U)
#define GPC_PGC_NOC_MIX_CTRL_DFTRAM_TCD1_SHIFT   (8U)
#define GPC_PGC_NOC_MIX_CTRL_DFTRAM_TCD1(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_NOC_MIX_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_NOC_MIX_CTRL_L2RETN_TCD1_TDR_MASK (0x3F0000U)
#define GPC_PGC_NOC_MIX_CTRL_L2RETN_TCD1_TDR_SHIFT (16U)
#define GPC_PGC_NOC_MIX_CTRL_L2RETN_TCD1_TDR(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_NOC_MIX_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_NOC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_NOC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_NOC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_NOC_MIX_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/*! @name NOC_MIX_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_NOC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_MASK (0x40U)
#define GPC_PGC_NOC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT (6U)
#define GPC_PGC_NOC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_SHIFT)) & GPC_PGC_NOC_MIX_PUPSCR_PUP_WAIT_SCALL_OUT_MASK)

#define GPC_PGC_NOC_MIX_PUPSCR_SW2ISO_MASK       (0x7FFF80U)
#define GPC_PGC_NOC_MIX_PUPSCR_SW2ISO_SHIFT      (7U)
#define GPC_PGC_NOC_MIX_PUPSCR_SW2ISO(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_NOC_MIX_PUPSCR_SW2ISO_MASK)
/*! @} */

/*! @name NOC_MIX_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_NOC_MIX_PDNSCR_ISO_MASK          (0x3FU)
#define GPC_PGC_NOC_MIX_PDNSCR_ISO_SHIFT         (0U)
#define GPC_PGC_NOC_MIX_PDNSCR_ISO(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_PDNSCR_ISO_SHIFT)) & GPC_PGC_NOC_MIX_PDNSCR_ISO_MASK)

#define GPC_PGC_NOC_MIX_PDNSCR_ISO2SW_MASK       (0x3F00U)
#define GPC_PGC_NOC_MIX_PDNSCR_ISO2SW_SHIFT      (8U)
#define GPC_PGC_NOC_MIX_PDNSCR_ISO2SW(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_NOC_MIX_PDNSCR_ISO2SW_MASK)
/*! @} */

/*! @name NOC_MIX_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_NOC_MIX_SR_PSR_MASK              (0x1U)
#define GPC_PGC_NOC_MIX_SR_PSR_SHIFT             (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_NOC_MIX_SR_PSR(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_SR_PSR_SHIFT)) & GPC_PGC_NOC_MIX_SR_PSR_MASK)

#define GPC_PGC_NOC_MIX_SR_L2RETN_FLAG_MASK      (0x2U)
#define GPC_PGC_NOC_MIX_SR_L2RETN_FLAG_SHIFT     (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_NOC_MIX_SR_L2RETN_FLAG(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_NOC_MIX_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_NOC_MIX_SR_ALLOFF_FLAG_MASK      (0x4U)
#define GPC_PGC_NOC_MIX_SR_ALLOFF_FLAG_SHIFT     (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_NOC_MIX_SR_ALLOFF_FLAG(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_NOC_MIX_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_NOC_MIX_SR_PUP_CLK_DIV_SEL_MASK  (0x78U)
#define GPC_PGC_NOC_MIX_SR_PUP_CLK_DIV_SEL_SHIFT (3U)
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
#define GPC_PGC_NOC_MIX_SR_PUP_CLK_DIV_SEL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_NOC_MIX_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_NOC_MIX_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_NOC_MIX_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_NOC_MIX_SR_L2RSTDIS_DEASSERT_CNT(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_NOC_MIX_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_NOC_MIX_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/*! @name PU_CTRL - GPC PGC Control Register for PGC PUs */
/*! @{ */

#define GPC_PGC_PU_CTRL_PCR_MASK                 (0x1U)
#define GPC_PGC_PU_CTRL_PCR_SHIFT                (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_PU_CTRL_PCR(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_CTRL_PCR_SHIFT)) & GPC_PGC_PU_CTRL_PCR_MASK)

#define GPC_PGC_PU_CTRL_L2RSTDIS_MASK            (0x7EU)
#define GPC_PGC_PU_CTRL_L2RSTDIS_SHIFT           (1U)
#define GPC_PGC_PU_CTRL_L2RSTDIS(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_PU_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_PU_CTRL_DFTRAM_TCD1_MASK         (0x3F00U)
#define GPC_PGC_PU_CTRL_DFTRAM_TCD1_SHIFT        (8U)
#define GPC_PGC_PU_CTRL_DFTRAM_TCD1(x)           (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_PU_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_PU_CTRL_L2RETN_TCD1_TDR_MASK     (0x3F0000U)
#define GPC_PGC_PU_CTRL_L2RETN_TCD1_TDR_SHIFT    (16U)
#define GPC_PGC_PU_CTRL_L2RETN_TCD1_TDR(x)       (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_PU_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_PU_CTRL_MEMPWR_TCD1_TDR_TRM_MASK (0x3F000000U)
#define GPC_PGC_PU_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT (24U)
#define GPC_PGC_PU_CTRL_MEMPWR_TCD1_TDR_TRM(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_PU_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/* The count of GPC_PGC_PU_CTRL */
#define GPC_PGC_PU_CTRL_COUNT                    (20U)

/*! @name PU_PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU_PUPSCR_SW_MASK                (0x3FU)
#define GPC_PGC_PU_PUPSCR_SW_SHIFT               (0U)
#define GPC_PGC_PU_PUPSCR_SW(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_PUPSCR_SW_SHIFT)) & GPC_PGC_PU_PUPSCR_SW_MASK)

#define GPC_PGC_PU_PUPSCR_SW2ISO_MASK            (0x7FFF80U)
#define GPC_PGC_PU_PUPSCR_SW2ISO_SHIFT           (7U)
#define GPC_PGC_PU_PUPSCR_SW2ISO(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PU_PUPSCR_SW2ISO_MASK)
/*! @} */

/* The count of GPC_PGC_PU_PUPSCR */
#define GPC_PGC_PU_PUPSCR_COUNT                  (20U)

/*! @name PU_PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PU_PDNSCR_ISO_MASK               (0x3FU)
#define GPC_PGC_PU_PDNSCR_ISO_SHIFT              (0U)
#define GPC_PGC_PU_PDNSCR_ISO(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_PDNSCR_ISO_SHIFT)) & GPC_PGC_PU_PDNSCR_ISO_MASK)

#define GPC_PGC_PU_PDNSCR_ISO2SW_MASK            (0x3F00U)
#define GPC_PGC_PU_PDNSCR_ISO2SW_SHIFT           (8U)
#define GPC_PGC_PU_PDNSCR_ISO2SW(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PU_PDNSCR_ISO2SW_MASK)
/*! @} */

/* The count of GPC_PGC_PU_PDNSCR */
#define GPC_PGC_PU_PDNSCR_COUNT                  (20U)

/*! @name PU_SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_PU_SR_PSR_MASK                   (0x1U)
#define GPC_PGC_PU_SR_PSR_SHIFT                  (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_PU_SR_PSR(x)                     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_SR_PSR_SHIFT)) & GPC_PGC_PU_SR_PSR_MASK)

#define GPC_PGC_PU_SR_L2RETN_FLAG_MASK           (0x2U)
#define GPC_PGC_PU_SR_L2RETN_FLAG_SHIFT          (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_PU_SR_L2RETN_FLAG(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_PU_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_PU_SR_ALLOFF_FLAG_MASK           (0x4U)
#define GPC_PGC_PU_SR_ALLOFF_FLAG_SHIFT          (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_PU_SR_ALLOFF_FLAG(x)             (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_PU_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_PU_SR_PUP_CLK_DIV_SEL_MASK       (0x78U)
#define GPC_PGC_PU_SR_PUP_CLK_DIV_SEL_SHIFT      (3U)
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
#define GPC_PGC_PU_SR_PUP_CLK_DIV_SEL(x)         (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_PU_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_PU_SR_L2RSTDIS_DEASSERT_CNT_MASK (0x3FF00U)
#define GPC_PGC_PU_SR_L2RSTDIS_DEASSERT_CNT_SHIFT (8U)
#define GPC_PGC_PU_SR_L2RSTDIS_DEASSERT_CNT(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PU_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_PU_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/* The count of GPC_PGC_PU_SR */
#define GPC_PGC_PU_SR_COUNT                      (20U)


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_GPC_PGC_H_ */

