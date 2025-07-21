/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPC_PGC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_PGC
 *
 * CMSIS Peripheral Access Layer for GPC_PGC
 */

#if !defined(PERI_GPC_PGC_H_)
#define PERI_GPC_PGC_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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

/** GPC_PGC - Size of Registers Arrays */
#define GPC_PGC_GPC_PGC_A53COREnCTRL_COUNT        4u
#define GPC_PGC_GPC_PGC_CTRL_COUNT                14u

/** GPC_PGC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  struct {                                         /* offset: 0x800, array step: 0x40 */
    __IO uint32_t CTRL;                              /**< GPC PGC Control Register for PGC CPUs, array offset: 0x800, array step: 0x40 */
    __IO uint32_t PUPSCR;                            /**< GPC PGC Up Sequence Control Register, array offset: 0x804, array step: 0x40 */
    __IO uint32_t PDNSCR;                            /**< GPC PGC Down Sequence Control Register, array offset: 0x808, array step: 0x40 */
    __IO uint32_t SR;                                /**< GPC PGC Status Register, array offset: 0x80C, array step: 0x40 */
         uint8_t RESERVED_0[48];
  } GPC_PGC_A53COREnCTRL[GPC_PGC_GPC_PGC_A53COREnCTRL_COUNT];
  __IO uint32_t A53SCU_CTRL;                       /**< GPC PGC Control Register for PGC CPUs, offset: 0x900 */
  __IO uint32_t A53SCU_PUPSCR;                     /**< GPC PGC Up Sequence Control Register, offset: 0x904 */
  __IO uint32_t A53SCU_PDNSCR;                     /**< GPC PGC Down Sequence Control Register, offset: 0x908 */
  __IO uint32_t A53SCU_SR;                         /**< GPC PGC Status Register, offset: 0x90C */
  __IO uint32_t A53SCU_AUXSW;                      /**< GPC PGC Auxiliary Power Switch Control Register, offset: 0x910 */
       uint8_t RESERVED_1[300];
  __IO uint32_t NOC_MIX_CTRL;                      /**< GPC PGC Control Register for PGC MIX., offset: 0xA40 */
  __IO uint32_t NOC_MIX_PUPSCR;                    /**< GPC PGC Up Sequence Control Register, offset: 0xA44 */
  __IO uint32_t NOC_MIX_PDNSCR;                    /**< GPC PGC Down Sequence Control Register, offset: 0xA48 */
  __IO uint32_t NOC_MIX_SR;                        /**< GPC PGC Status Register, offset: 0xA4C */
       uint8_t RESERVED_2[432];
  struct {                                         /* offset: 0xC00, array step: 0x40 */
    __IO uint32_t PU_CTRL;                           /**< GPC PGC Control Register for PGC PUs, array offset: 0xC00, array step: 0x40 */
    __IO uint32_t PU_PUPSCR;                         /**< GPC PGC Up Sequence Control Register, array offset: 0xC04, array step: 0x40 */
    __IO uint32_t PU_PDNSCR;                         /**< GPC PGC Down Sequence Control Register, array offset: 0xC08, array step: 0x40 */
    __IO uint32_t PU_SR;                             /**< GPC PGC Status Register, array offset: 0xC0C, array step: 0x40 */
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

/*! @name CTRL - GPC PGC Control Register for PGC CPUs */
/*! @{ */

#define GPC_PGC_CTRL_PCR_MASK                    (0x1U)
#define GPC_PGC_CTRL_PCR_SHIFT                   (0U)
/*! PCR
 *  0b0..Do not switch off power even if pdn_req is asserted.
 *  0b1..Switch off power when pdn_req is asserted.
 */
#define GPC_PGC_CTRL_PCR(x)                      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CTRL_PCR_SHIFT)) & GPC_PGC_CTRL_PCR_MASK)

#define GPC_PGC_CTRL_L2RSTDIS_MASK               (0x7EU)
#define GPC_PGC_CTRL_L2RSTDIS_SHIFT              (1U)
#define GPC_PGC_CTRL_L2RSTDIS(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CTRL_L2RSTDIS_SHIFT)) & GPC_PGC_CTRL_L2RSTDIS_MASK)

#define GPC_PGC_CTRL_DFTRAM_TCD1_MASK            (0x3F00U)
#define GPC_PGC_CTRL_DFTRAM_TCD1_SHIFT           (8U)
#define GPC_PGC_CTRL_DFTRAM_TCD1(x)              (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CTRL_DFTRAM_TCD1_SHIFT)) & GPC_PGC_CTRL_DFTRAM_TCD1_MASK)

#define GPC_PGC_CTRL_L2RETN_TCD1_TDR_MASK        (0x3F0000U)
#define GPC_PGC_CTRL_L2RETN_TCD1_TDR_SHIFT       (16U)
#define GPC_PGC_CTRL_L2RETN_TCD1_TDR(x)          (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CTRL_L2RETN_TCD1_TDR_SHIFT)) & GPC_PGC_CTRL_L2RETN_TCD1_TDR_MASK)

#define GPC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_MASK    (0x3F000000U)
#define GPC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT   (24U)
#define GPC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_SHIFT)) & GPC_PGC_CTRL_MEMPWR_TCD1_TDR_TRM_MASK)
/*! @} */

/* The count of GPC_PGC_CTRL */
#define GPC_PGC_CTRL_COUNT                       (4U)

/*! @name PUPSCR - GPC PGC Up Sequence Control Register */
/*! @{ */

#define GPC_PGC_PUPSCR_SW_MASK                   (0x3FU)
#define GPC_PGC_PUPSCR_SW_SHIFT                  (0U)
#define GPC_PGC_PUPSCR_SW(x)                     (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PUPSCR_SW_SHIFT)) & GPC_PGC_PUPSCR_SW_MASK)

#define GPC_PGC_PUPSCR_SW2ISO_MASK               (0x7FFF80U)
#define GPC_PGC_PUPSCR_SW2ISO_SHIFT              (7U)
#define GPC_PGC_PUPSCR_SW2ISO(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PUPSCR_SW2ISO_SHIFT)) & GPC_PGC_PUPSCR_SW2ISO_MASK)
/*! @} */

/* The count of GPC_PGC_PUPSCR */
#define GPC_PGC_PUPSCR_COUNT                     (4U)

/*! @name PDNSCR - GPC PGC Down Sequence Control Register */
/*! @{ */

#define GPC_PGC_PDNSCR_ISO_MASK                  (0x3FU)
#define GPC_PGC_PDNSCR_ISO_SHIFT                 (0U)
#define GPC_PGC_PDNSCR_ISO(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PDNSCR_ISO_SHIFT)) & GPC_PGC_PDNSCR_ISO_MASK)

#define GPC_PGC_PDNSCR_ISO2SW_MASK               (0x3F00U)
#define GPC_PGC_PDNSCR_ISO2SW_SHIFT              (8U)
#define GPC_PGC_PDNSCR_ISO2SW(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_PGC_PDNSCR_ISO2SW_SHIFT)) & GPC_PGC_PDNSCR_ISO2SW_MASK)
/*! @} */

/* The count of GPC_PGC_PDNSCR */
#define GPC_PGC_PDNSCR_COUNT                     (4U)

/*! @name SR - GPC PGC Status Register */
/*! @{ */

#define GPC_PGC_SR_PSR_MASK                      (0x1U)
#define GPC_PGC_SR_PSR_SHIFT                     (0U)
/*! PSR
 *  0b0..The target subsystem was not powered down for the previous power-down request.
 *  0b1..The target subsystem was powered down for the previous power-down request.
 */
#define GPC_PGC_SR_PSR(x)                        (((uint32_t)(((uint32_t)(x)) << GPC_PGC_SR_PSR_SHIFT)) & GPC_PGC_SR_PSR_MASK)

#define GPC_PGC_SR_L2RETN_FLAG_MASK              (0x2U)
#define GPC_PGC_SR_L2RETN_FLAG_SHIFT             (1U)
/*! L2RETN_FLAG
 *  0b0..A53 is not wakeup from L2 retention mode.
 *  0b1..A53 is wakeup from L2 retention mode.
 */
#define GPC_PGC_SR_L2RETN_FLAG(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_SR_L2RETN_FLAG_SHIFT)) & GPC_PGC_SR_L2RETN_FLAG_MASK)

#define GPC_PGC_SR_ALLOFF_FLAG_MASK              (0x4U)
#define GPC_PGC_SR_ALLOFF_FLAG_SHIFT             (2U)
/*! ALLOFF_FLAG
 *  0b0..A53 is not wakeup from ALL_OFF mode.
 *  0b1..A53 is wakeup from ALL_OFF mode.
 */
#define GPC_PGC_SR_ALLOFF_FLAG(x)                (((uint32_t)(((uint32_t)(x)) << GPC_PGC_SR_ALLOFF_FLAG_SHIFT)) & GPC_PGC_SR_ALLOFF_FLAG_MASK)

#define GPC_PGC_SR_PUP_CLK_DIV_SEL_MASK          (0x78U)
#define GPC_PGC_SR_PUP_CLK_DIV_SEL_SHIFT         (3U)
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
#define GPC_PGC_SR_PUP_CLK_DIV_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GPC_PGC_SR_PUP_CLK_DIV_SEL_SHIFT)) & GPC_PGC_SR_PUP_CLK_DIV_SEL_MASK)

#define GPC_PGC_SR_L2RSTDIS_DEASSERT_CNT_MASK    (0x3FF00U)
#define GPC_PGC_SR_L2RSTDIS_DEASSERT_CNT_SHIFT   (8U)
#define GPC_PGC_SR_L2RSTDIS_DEASSERT_CNT(x)      (((uint32_t)(((uint32_t)(x)) << GPC_PGC_SR_L2RSTDIS_DEASSERT_CNT_SHIFT)) & GPC_PGC_SR_L2RSTDIS_DEASSERT_CNT_MASK)
/*! @} */

/* The count of GPC_PGC_SR */
#define GPC_PGC_SR_COUNT                         (4U)

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

/*! @name A53SCU_AUXSW - GPC PGC Auxiliary Power Switch Control Register */
/*! @{ */

#define GPC_PGC_A53SCU_AUXSW_DFTRAM_TRC1_TMC_TMR_TCD2_MASK (0x3FFU)
#define GPC_PGC_A53SCU_AUXSW_DFTRAM_TRC1_TMC_TMR_TCD2_SHIFT (0U)
#define GPC_PGC_A53SCU_AUXSW_DFTRAM_TRC1_TMC_TMR_TCD2(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_DFTRAM_TRC1_TMC_TMR_TCD2_SHIFT)) & GPC_PGC_A53SCU_AUXSW_DFTRAM_TRC1_TMC_TMR_TCD2_MASK)

#define GPC_PGC_A53SCU_AUXSW_L2RETN_RTC1_TMC_TMR_MASK (0xFFC00U)
#define GPC_PGC_A53SCU_AUXSW_L2RETN_RTC1_TMC_TMR_SHIFT (10U)
#define GPC_PGC_A53SCU_AUXSW_L2RETN_RTC1_TMC_TMR(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_L2RETN_RTC1_TMC_TMR_SHIFT)) & GPC_PGC_A53SCU_AUXSW_L2RETN_RTC1_TMC_TMR_MASK)

#define GPC_PGC_A53SCU_AUXSW_MEMPWR_TRC1_TMC_MASK (0x3FF00000U)
#define GPC_PGC_A53SCU_AUXSW_MEMPWR_TRC1_TMC_SHIFT (20U)
#define GPC_PGC_A53SCU_AUXSW_MEMPWR_TRC1_TMC(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_A53SCU_AUXSW_MEMPWR_TRC1_TMC_SHIFT)) & GPC_PGC_A53SCU_AUXSW_MEMPWR_TRC1_TMC_MASK)
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
#define GPC_PGC_PU_CTRL_COUNT                    (14U)

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
#define GPC_PGC_PU_PUPSCR_COUNT                  (14U)

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
#define GPC_PGC_PU_PDNSCR_COUNT                  (14U)

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
#define GPC_PGC_PU_SR_COUNT                      (14U)


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

