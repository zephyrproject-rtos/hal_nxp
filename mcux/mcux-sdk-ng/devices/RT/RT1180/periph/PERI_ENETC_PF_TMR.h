/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ENETC_PF_TMR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ENETC_PF_TMR.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ENETC_PF_TMR
 *
 * CMSIS Peripheral Access Layer for ENETC_PF_TMR
 */

#if !defined(PERI_ENETC_PF_TMR_H_)
#define PERI_ENETC_PF_TMR_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- ENETC_PF_TMR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PF_TMR_Peripheral_Access_Layer ENETC_PF_TMR Peripheral Access Layer
 * @{
 */

/** ENETC_PF_TMR - Size of Registers Arrays */
#define ENETC_PF_TMR_TMR_ALARMM_COUNT             2u
#define ENETC_PF_TMR_TMR_FIPERF_COUNT             3u
#define ENETC_PF_TMR_TMR_ETTSN_COUNT              2u

/** ENETC_PF_TMR - Register Layout Typedef */
typedef struct {
  __I  uint32_t TMR_ID;                            /**< Module ID Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t TMR_CAPR;                          /**< Timer Capability Register, offset: 0x8 */
       uint8_t RESERVED_1[20];
  __I  uint32_t TMR_FRT_L;                         /**< Timer free running time low register, offset: 0x20 */
  __I  uint32_t TMR_FRT_H;                         /**< Timer free running time high register, offset: 0x24 */
  __I  uint32_t TMR_SRT_L;                         /**< Timer synchronous time low register, offset: 0x28 */
  __I  uint32_t TMR_SRT_H;                         /**< Timer synchronous time high register., offset: 0x2C */
  __I  uint32_t TMR_DEF_CNT_L;                     /**< Default ns timer counter low register, offset: 0x30 */
  __I  uint32_t TMR_DEF_CNT_H;                     /**< Default ns timer counter high register, offset: 0x34 */
       uint8_t RESERVED_2[72];
  __IO uint32_t TMR_CTRL;                          /**< Timer Control Register, offset: 0x80 */
  __IO uint32_t TMR_TEVENT;                        /**< Timer Event Register, offset: 0x84 */
  __IO uint32_t TMR_TEMASK;                        /**< Timer event mask register, offset: 0x88 */
       uint8_t RESERVED_3[8];
  __I  uint32_t TMR_STAT;                          /**< Timer status register, offset: 0x94 */
  __IO uint32_t TMR_CNT_L;                         /**< Timer counter low register, offset: 0x98 */
  __IO uint32_t TMR_CNT_H;                         /**< Timer counter high register, offset: 0x9C */
  __IO uint32_t TMR_ADD;                           /**< Timer addend register, offset: 0xA0 */
  __I  uint32_t TMR_ACC;                           /**< Timer accumulator register, offset: 0xA4 */
  __IO uint32_t TMR_PRSC;                          /**< Timer prescale register, offset: 0xA8 */
  __IO uint32_t TMR_ECTRL;                         /**< Extended timer control register, offset: 0xAC */
  __IO uint32_t TMROFF_L;                          /**< Timer offset low register, offset: 0xB0 */
  __IO uint32_t TMROFF_H;                          /**< Timer offset high register, offset: 0xB4 */
  struct {                                         /* offset: 0xB8, array step: 0x8 */
    __IO uint32_t TMR_ALARM_L;                       /**< Alarm 1 time comparator low register..Alarm 2 time comparator low register, array offset: 0xB8, array step: 0x8 */
    __IO uint32_t TMR_ALARM_H;                       /**< Alarm 1 time comparator high register..Alarm 2 time comparator high register, array offset: 0xBC, array step: 0x8 */
  } TMR_ALARMM[ENETC_PF_TMR_TMR_ALARMM_COUNT];
       uint8_t RESERVED_4[4];
  __IO uint32_t TMR_ALARM_CTRL;                    /**< Timer Alarm Control Register, offset: 0xCC */
  __IO uint32_t TMR_FIPER[ENETC_PF_TMR_TMR_FIPERF_COUNT]; /**< Timer 1 fixed interval period register..Timer 3 fixed interval period register, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t TMR_FIPER_CTRL;                    /**< Timer FIPER Control Register, offset: 0xDC */
  struct {                                         /* offset: 0xE0, array step: 0x8 */
    __I  uint32_t TMR_ETTS_L;                        /**< External trigger stamp register, array offset: 0xE0, array step: 0x8 */
    __I  uint32_t TMR_ETTS_H;                        /**< External trigger stamp register, array offset: 0xE4, array step: 0x8 */
  } TMR_ETTSN[ENETC_PF_TMR_TMR_ETTSN_COUNT];
  __I  uint32_t TMR_CUR_TIME_L;                    /**< Timer current time low register, offset: 0xF0 */
  __I  uint32_t TMR_CUR_TIME_H;                    /**< Timer current time high register, offset: 0xF4 */
  __IO uint32_t TMR_PARAM;                         /**< Timer parameter register, offset: 0xF8 */
} ENETC_PF_TMR_Type;

/* ----------------------------------------------------------------------------
   -- ENETC_PF_TMR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PF_TMR_Register_Masks ENETC_PF_TMR Register Masks
 * @{
 */

/*! @name TMR_ID - Module ID Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ID_REV_MN_MASK          (0xFFU)
#define ENETC_PF_TMR_TMR_ID_REV_MN_SHIFT         (0U)
/*! REV_MN - Minor revision */
#define ENETC_PF_TMR_TMR_ID_REV_MN(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ID_REV_MN_SHIFT)) & ENETC_PF_TMR_TMR_ID_REV_MN_MASK)

#define ENETC_PF_TMR_TMR_ID_REV_MJ_MASK          (0xFF00U)
#define ENETC_PF_TMR_TMR_ID_REV_MJ_SHIFT         (8U)
/*! REV_MJ - Major revision */
#define ENETC_PF_TMR_TMR_ID_REV_MJ(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ID_REV_MJ_SHIFT)) & ENETC_PF_TMR_TMR_ID_REV_MJ_MASK)

#define ENETC_PF_TMR_TMR_ID_TMR_ID_MASK          (0xFFFF0000U)
#define ENETC_PF_TMR_TMR_ID_TMR_ID_SHIFT         (16U)
/*! TMR_ID - Timer IP ID */
#define ENETC_PF_TMR_TMR_ID_TMR_ID(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ID_TMR_ID_SHIFT)) & ENETC_PF_TMR_TMR_ID_TMR_ID_MASK)
/*! @} */

/*! @name TMR_CAPR - Timer Capability Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CAPR_IEEE_1722_MASK     (0x1U)
#define ENETC_PF_TMR_TMR_CAPR_IEEE_1722_SHIFT    (0U)
#define ENETC_PF_TMR_TMR_CAPR_IEEE_1722(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CAPR_IEEE_1722_SHIFT)) & ENETC_PF_TMR_TMR_CAPR_IEEE_1722_MASK)

#define ENETC_PF_TMR_TMR_CAPR_ECADJ_MASK         (0x2U)
#define ENETC_PF_TMR_TMR_CAPR_ECADJ_SHIFT        (1U)
#define ENETC_PF_TMR_TMR_CAPR_ECADJ(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CAPR_ECADJ_SHIFT)) & ENETC_PF_TMR_TMR_CAPR_ECADJ_MASK)

#define ENETC_PF_TMR_TMR_CAPR_IEEE_8021AS_REV_MASK (0x4U)
#define ENETC_PF_TMR_TMR_CAPR_IEEE_8021AS_REV_SHIFT (2U)
#define ENETC_PF_TMR_TMR_CAPR_IEEE_8021AS_REV(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CAPR_IEEE_8021AS_REV_SHIFT)) & ENETC_PF_TMR_TMR_CAPR_IEEE_8021AS_REV_MASK)

#define ENETC_PF_TMR_TMR_CAPR_NUM_MSIX_MASK      (0x10000U)
#define ENETC_PF_TMR_TMR_CAPR_NUM_MSIX_SHIFT     (16U)
#define ENETC_PF_TMR_TMR_CAPR_NUM_MSIX(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CAPR_NUM_MSIX_SHIFT)) & ENETC_PF_TMR_TMR_CAPR_NUM_MSIX_MASK)
/*! @} */

/*! @name TMR_FRT_L - Timer free running time low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_FRT_L_TMR_FRT_L_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_FRT_L_TMR_FRT_L_SHIFT   (0U)
#define ENETC_PF_TMR_TMR_FRT_L_TMR_FRT_L(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FRT_L_TMR_FRT_L_SHIFT)) & ENETC_PF_TMR_TMR_FRT_L_TMR_FRT_L_MASK)
/*! @} */

/*! @name TMR_FRT_H - Timer free running time high register */
/*! @{ */

#define ENETC_PF_TMR_TMR_FRT_H_TMR_FRT_H_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_FRT_H_TMR_FRT_H_SHIFT   (0U)
#define ENETC_PF_TMR_TMR_FRT_H_TMR_FRT_H(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FRT_H_TMR_FRT_H_SHIFT)) & ENETC_PF_TMR_TMR_FRT_H_TMR_FRT_H_MASK)
/*! @} */

/*! @name TMR_SRT_L - Timer synchronous time low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_SRT_L_TMR_SRT_L_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_SRT_L_TMR_SRT_L_SHIFT   (0U)
#define ENETC_PF_TMR_TMR_SRT_L_TMR_SRT_L(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_SRT_L_TMR_SRT_L_SHIFT)) & ENETC_PF_TMR_TMR_SRT_L_TMR_SRT_L_MASK)
/*! @} */

/*! @name TMR_SRT_H - Timer synchronous time high register. */
/*! @{ */

#define ENETC_PF_TMR_TMR_SRT_H_TMR_SRT_H_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_SRT_H_TMR_SRT_H_SHIFT   (0U)
#define ENETC_PF_TMR_TMR_SRT_H_TMR_SRT_H(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_SRT_H_TMR_SRT_H_SHIFT)) & ENETC_PF_TMR_TMR_SRT_H_TMR_SRT_H_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_L - Default ns timer counter low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT (0U)
#define ENETC_PF_TMR_TMR_DEF_CNT_L_TMR_DEF_CNT_L(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_DEF_CNT_L_TMR_DEF_CNT_L_SHIFT)) & ENETC_PF_TMR_TMR_DEF_CNT_L_TMR_DEF_CNT_L_MASK)
/*! @} */

/*! @name TMR_DEF_CNT_H - Default ns timer counter high register */
/*! @{ */

#define ENETC_PF_TMR_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT (0U)
#define ENETC_PF_TMR_TMR_DEF_CNT_H_TMR_DEF_CNT_H(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_DEF_CNT_H_TMR_DEF_CNT_H_SHIFT)) & ENETC_PF_TMR_TMR_DEF_CNT_H_TMR_DEF_CNT_H_MASK)
/*! @} */

/*! @name TMR_CTRL - Timer Control Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CTRL_CK_SEL_MASK        (0x3U)
#define ENETC_PF_TMR_TMR_CTRL_CK_SEL_SHIFT       (0U)
/*! CK_SEL - 1588 timer reference clock source select */
#define ENETC_PF_TMR_TMR_CTRL_CK_SEL(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_CK_SEL_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_CK_SEL_MASK)

#define ENETC_PF_TMR_TMR_CTRL_TE_MASK            (0x4U)
#define ENETC_PF_TMR_TMR_CTRL_TE_SHIFT           (2U)
/*! TE - 1588 timer enable */
#define ENETC_PF_TMR_TMR_CTRL_TE(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_TE_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_TE_MASK)

#define ENETC_PF_TMR_TMR_CTRL_CIPH_MASK          (0x40U)
#define ENETC_PF_TMR_TMR_CTRL_CIPH_SHIFT         (6U)
/*! CIPH - External oscillator input clock phase */
#define ENETC_PF_TMR_TMR_CTRL_CIPH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_CIPH_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_CIPH_MASK)

#define ENETC_PF_TMR_TMR_CTRL_COPH_MASK          (0x80U)
#define ENETC_PF_TMR_TMR_CTRL_COPH_SHIFT         (7U)
/*! COPH - Generated clock (TMR_GCLK) output phase. */
#define ENETC_PF_TMR_TMR_CTRL_COPH(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_COPH_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_COPH_MASK)

#define ENETC_PF_TMR_TMR_CTRL_ETEP1_MASK         (0x100U)
#define ENETC_PF_TMR_TMR_CTRL_ETEP1_SHIFT        (8U)
/*! ETEP1 - External trigger 1 edge polarity */
#define ENETC_PF_TMR_TMR_CTRL_ETEP1(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_ETEP1_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_ETEP1_MASK)

#define ENETC_PF_TMR_TMR_CTRL_ETEP2_MASK         (0x200U)
#define ENETC_PF_TMR_TMR_CTRL_ETEP2_SHIFT        (9U)
/*! ETEP2 - External trigger 2 edge polarity */
#define ENETC_PF_TMR_TMR_CTRL_ETEP2(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_ETEP2_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_ETEP2_MASK)

#define ENETC_PF_TMR_TMR_CTRL_COMP_MODE_MASK     (0x8000U)
#define ENETC_PF_TMR_TMR_CTRL_COMP_MODE_SHIFT    (15U)
/*! COMP_MODE - Mode bit to allow atomic writes to TCLK_PERIOD and TMR_ADD */
#define ENETC_PF_TMR_TMR_CTRL_COMP_MODE(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_COMP_MODE_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_COMP_MODE_MASK)

#define ENETC_PF_TMR_TMR_CTRL_TCLK_PERIOD_MASK   (0x3FF0000U)
#define ENETC_PF_TMR_TMR_CTRL_TCLK_PERIOD_SHIFT  (16U)
/*! TCLK_PERIOD - 1588 timer reference clock period */
#define ENETC_PF_TMR_TMR_CTRL_TCLK_PERIOD(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_TCLK_PERIOD_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_TCLK_PERIOD_MASK)

#define ENETC_PF_TMR_TMR_CTRL_PP2L_MASK          (0x4000000U)
#define ENETC_PF_TMR_TMR_CTRL_PP2L_SHIFT         (26U)
/*! PP2L - Fiper2 pulse loop back mode enabled */
#define ENETC_PF_TMR_TMR_CTRL_PP2L(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_PP2L_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_PP2L_MASK)

#define ENETC_PF_TMR_TMR_CTRL_PP1L_MASK          (0x8000000U)
#define ENETC_PF_TMR_TMR_CTRL_PP1L_SHIFT         (27U)
/*! PP1L - Fiper1 pulse loop back mode enabled */
#define ENETC_PF_TMR_TMR_CTRL_PP1L(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_PP1L_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_PP1L_MASK)

#define ENETC_PF_TMR_TMR_CTRL_FS_MASK            (0x10000000U)
#define ENETC_PF_TMR_TMR_CTRL_FS_SHIFT           (28U)
/*! FS - FIPER start indication */
#define ENETC_PF_TMR_TMR_CTRL_FS(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_FS_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_FS_MASK)

#define ENETC_PF_TMR_TMR_CTRL_SHADOW_DIS_MASK    (0x20000000U)
#define ENETC_PF_TMR_TMR_CTRL_SHADOW_DIS_SHIFT   (29U)
/*! SHADOW_DIS - shadow Register disable */
#define ENETC_PF_TMR_TMR_CTRL_SHADOW_DIS(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_SHADOW_DIS_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_SHADOW_DIS_MASK)

#define ENETC_PF_TMR_TMR_CTRL_ALM2P_MASK         (0x40000000U)
#define ENETC_PF_TMR_TMR_CTRL_ALM2P_SHIFT        (30U)
/*! ALM2P - Alarm2 output polarity */
#define ENETC_PF_TMR_TMR_CTRL_ALM2P(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_ALM2P_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_ALM2P_MASK)

#define ENETC_PF_TMR_TMR_CTRL_ALM1P_MASK         (0x80000000U)
#define ENETC_PF_TMR_TMR_CTRL_ALM1P_SHIFT        (31U)
/*! ALM1P - Alarm1 output polarity */
#define ENETC_PF_TMR_TMR_CTRL_ALM1P(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CTRL_ALM1P_SHIFT)) & ENETC_PF_TMR_TMR_CTRL_ALM1P_MASK)
/*! @} */

/*! @name TMR_TEVENT - Timer Event Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_TEVENT_PP3EN_MASK       (0x20U)
#define ENETC_PF_TMR_TMR_TEVENT_PP3EN_SHIFT      (5U)
#define ENETC_PF_TMR_TMR_TEVENT_PP3EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_PP3EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_PP3EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_PP2EN_MASK       (0x40U)
#define ENETC_PF_TMR_TMR_TEVENT_PP2EN_SHIFT      (6U)
#define ENETC_PF_TMR_TMR_TEVENT_PP2EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_PP2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_PP2EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_PP1EN_MASK       (0x80U)
#define ENETC_PF_TMR_TMR_TEVENT_PP1EN_SHIFT      (7U)
#define ENETC_PF_TMR_TMR_TEVENT_PP1EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_PP1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_PP1EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ALM1EN_MASK      (0x10000U)
#define ENETC_PF_TMR_TMR_TEVENT_ALM1EN_SHIFT     (16U)
#define ENETC_PF_TMR_TMR_TEVENT_ALM1EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ALM1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ALM1EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ALM2EN_MASK      (0x20000U)
#define ENETC_PF_TMR_TMR_TEVENT_ALM2EN_SHIFT     (17U)
#define ENETC_PF_TMR_TMR_TEVENT_ALM2EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ALM2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ALM2EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS1_THREN_MASK  (0x100000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS1_THREN_SHIFT (20U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS1_THREN(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS1_THREN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS1_THREN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS2_THREN_MASK  (0x200000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS2_THREN_SHIFT (21U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS2_THREN(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS2_THREN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS2_THREN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS1EN_MASK      (0x1000000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS1EN_SHIFT     (24U)
/*! ETS1EN - External trigger 1 new timestamp sample event available */
#define ENETC_PF_TMR_TMR_TEVENT_ETS1EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS1EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS2EN_MASK      (0x2000000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS2EN_SHIFT     (25U)
/*! ETS2EN - External trigger 2 new timestamp sample event available */
#define ENETC_PF_TMR_TMR_TEVENT_ETS2EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS2EN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS1_OVEN_MASK   (0x10000000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS1_OVEN_SHIFT  (28U)
/*! ETS1_OVEN - External trigger 1 timestamp FIFO Overflow event occurred */
#define ENETC_PF_TMR_TMR_TEVENT_ETS1_OVEN(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS1_OVEN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS1_OVEN_MASK)

#define ENETC_PF_TMR_TMR_TEVENT_ETS2_OVEN_MASK   (0x20000000U)
#define ENETC_PF_TMR_TMR_TEVENT_ETS2_OVEN_SHIFT  (29U)
/*! ETS2_OVEN - External trigger 2 timestamp FIFO Overflow event occurred */
#define ENETC_PF_TMR_TMR_TEVENT_ETS2_OVEN(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEVENT_ETS2_OVEN_SHIFT)) & ENETC_PF_TMR_TMR_TEVENT_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_TEMASK - Timer event mask register */
/*! @{ */

#define ENETC_PF_TMR_TMR_TEMASK_PP3EN_MASK       (0x20U)
#define ENETC_PF_TMR_TMR_TEMASK_PP3EN_SHIFT      (5U)
#define ENETC_PF_TMR_TMR_TEMASK_PP3EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_PP3EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_PP3EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_PP2EN_MASK       (0x40U)
#define ENETC_PF_TMR_TMR_TEMASK_PP2EN_SHIFT      (6U)
#define ENETC_PF_TMR_TMR_TEMASK_PP2EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_PP2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_PP2EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_PP1EN_MASK       (0x80U)
#define ENETC_PF_TMR_TMR_TEMASK_PP1EN_SHIFT      (7U)
#define ENETC_PF_TMR_TMR_TEMASK_PP1EN(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_PP1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_PP1EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ALM1EN_MASK      (0x10000U)
#define ENETC_PF_TMR_TMR_TEMASK_ALM1EN_SHIFT     (16U)
#define ENETC_PF_TMR_TMR_TEMASK_ALM1EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ALM1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ALM1EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ALM2EN_MASK      (0x20000U)
#define ENETC_PF_TMR_TMR_TEMASK_ALM2EN_SHIFT     (17U)
#define ENETC_PF_TMR_TMR_TEMASK_ALM2EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ALM2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ALM2EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS1_THREN_MASK  (0x100000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1_THREN_SHIFT (20U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1_THREN(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS1_THREN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS1_THREN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS2_THREN_MASK  (0x200000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2_THREN_SHIFT (21U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2_THREN(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS2_THREN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS2_THREN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS1EN_MASK      (0x1000000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1EN_SHIFT     (24U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS1EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS1EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS2EN_MASK      (0x2000000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2EN_SHIFT     (25U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2EN(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS2EN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS2EN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS1_OVEN_MASK   (0x10000000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1_OVEN_SHIFT  (28U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS1_OVEN(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS1_OVEN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS1_OVEN_MASK)

#define ENETC_PF_TMR_TMR_TEMASK_ETS2_OVEN_MASK   (0x20000000U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2_OVEN_SHIFT  (29U)
#define ENETC_PF_TMR_TMR_TEMASK_ETS2_OVEN(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_TEMASK_ETS2_OVEN_SHIFT)) & ENETC_PF_TMR_TMR_TEMASK_ETS2_OVEN_MASK)
/*! @} */

/*! @name TMR_STAT - Timer status register */
/*! @{ */

#define ENETC_PF_TMR_TMR_STAT_ETS1_VLD_MASK      (0x1000000U)
#define ENETC_PF_TMR_TMR_STAT_ETS1_VLD_SHIFT     (24U)
#define ENETC_PF_TMR_TMR_STAT_ETS1_VLD(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_STAT_ETS1_VLD_SHIFT)) & ENETC_PF_TMR_TMR_STAT_ETS1_VLD_MASK)

#define ENETC_PF_TMR_TMR_STAT_ETS2_VLD_MASK      (0x2000000U)
#define ENETC_PF_TMR_TMR_STAT_ETS2_VLD_SHIFT     (25U)
#define ENETC_PF_TMR_TMR_STAT_ETS2_VLD(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_STAT_ETS2_VLD_SHIFT)) & ENETC_PF_TMR_TMR_STAT_ETS2_VLD_MASK)

#define ENETC_PF_TMR_TMR_STAT_RCD_MASK           (0x80000000U)
#define ENETC_PF_TMR_TMR_STAT_RCD_SHIFT          (31U)
/*! RCD - Timer Reference Clock Detected
 *  0b0..Reference Clock has not been detected as active. Registers in timer clock domain are not allowed to be
 *       accessed; reads return 0, writes are ignored.
 *  0b1..Reference Clock has been detected as active. Registers in timer clock domain are allowed to be accessed.
 */
#define ENETC_PF_TMR_TMR_STAT_RCD(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_STAT_RCD_SHIFT)) & ENETC_PF_TMR_TMR_STAT_RCD_MASK)
/*! @} */

/*! @name TMR_CNT_L - Timer counter low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CNT_L_TMR_CNT_L_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_CNT_L_TMR_CNT_L_SHIFT   (0U)
/*! TMR_CNT_L - Timer counter register. */
#define ENETC_PF_TMR_TMR_CNT_L_TMR_CNT_L(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CNT_L_TMR_CNT_L_SHIFT)) & ENETC_PF_TMR_TMR_CNT_L_TMR_CNT_L_MASK)
/*! @} */

/*! @name TMR_CNT_H - Timer counter high register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CNT_H_TMR_CNT_H_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_CNT_H_TMR_CNT_H_SHIFT   (0U)
/*! TMR_CNT_H - Timer counter register. */
#define ENETC_PF_TMR_TMR_CNT_H_TMR_CNT_H(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CNT_H_TMR_CNT_H_SHIFT)) & ENETC_PF_TMR_TMR_CNT_H_TMR_CNT_H_MASK)
/*! @} */

/*! @name TMR_ADD - Timer addend register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ADD_ADDEND_MASK         (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ADD_ADDEND_SHIFT        (0U)
/*! ADDEND - Timer addend. */
#define ENETC_PF_TMR_TMR_ADD_ADDEND(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ADD_ADDEND_SHIFT)) & ENETC_PF_TMR_TMR_ADD_ADDEND_MASK)
/*! @} */

/*! @name TMR_ACC - Timer accumulator register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ACC_TMR_ACC_MASK        (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ACC_TMR_ACC_SHIFT       (0U)
/*! TMR_ACC - 32-bit timer accumulator register */
#define ENETC_PF_TMR_TMR_ACC_TMR_ACC(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ACC_TMR_ACC_SHIFT)) & ENETC_PF_TMR_TMR_ACC_TMR_ACC_MASK)
/*! @} */

/*! @name TMR_PRSC - Timer prescale register */
/*! @{ */

#define ENETC_PF_TMR_TMR_PRSC_PRSC_OCK_MASK      (0xFFFFU)
#define ENETC_PF_TMR_TMR_PRSC_PRSC_OCK_SHIFT     (0U)
/*! PRSC_OCK - Output clock division prescale factor. */
#define ENETC_PF_TMR_TMR_PRSC_PRSC_OCK(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_PRSC_PRSC_OCK_SHIFT)) & ENETC_PF_TMR_TMR_PRSC_PRSC_OCK_MASK)
/*! @} */

/*! @name TMR_ECTRL - Extended timer control register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ECTRL_ETFF_THR_MASK     (0xFU)
#define ENETC_PF_TMR_TMR_ECTRL_ETFF_THR_SHIFT    (0U)
/*! ETFF_THR - External trigger FIFO threshold. */
#define ENETC_PF_TMR_TMR_ECTRL_ETFF_THR(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ECTRL_ETFF_THR_SHIFT)) & ENETC_PF_TMR_TMR_ECTRL_ETFF_THR_MASK)
/*! @} */

/*! @name TMROFF_L - Timer offset low register */
/*! @{ */

#define ENETC_PF_TMR_TMROFF_L_TMROFF_L_MASK      (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMROFF_L_TMROFF_L_SHIFT     (0U)
/*! TMROFF_L - Offset value of the clock counter. */
#define ENETC_PF_TMR_TMROFF_L_TMROFF_L(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMROFF_L_TMROFF_L_SHIFT)) & ENETC_PF_TMR_TMROFF_L_TMROFF_L_MASK)
/*! @} */

/*! @name TMROFF_H - Timer offset high register */
/*! @{ */

#define ENETC_PF_TMR_TMROFF_H_TMROFF_H_MASK      (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMROFF_H_TMROFF_H_SHIFT     (0U)
/*! TMROFF_H - Offset value of the clock counter. */
#define ENETC_PF_TMR_TMROFF_H_TMROFF_H(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMROFF_H_TMROFF_H_SHIFT)) & ENETC_PF_TMR_TMROFF_H_TMROFF_H_MASK)
/*! @} */

/*! @name TMR_ALARM_L - Alarm 1 time comparator low register..Alarm 2 time comparator low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ALARM_L_ALARM_L_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ALARM_L_ALARM_L_SHIFT   (0U)
/*! ALARM_L - Alarm time comparator register. */
#define ENETC_PF_TMR_TMR_ALARM_L_ALARM_L(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_L_ALARM_L_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_L_ALARM_L_MASK)
/*! @} */

/* The count of ENETC_PF_TMR_TMR_ALARM_L */
#define ENETC_PF_TMR_TMR_ALARM_L_COUNT           (2U)

/*! @name TMR_ALARM_H - Alarm 1 time comparator high register..Alarm 2 time comparator high register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ALARM_H_ALARM_H_MASK    (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ALARM_H_ALARM_H_SHIFT   (0U)
/*! ALARM_H - Alarm time comparator register. */
#define ENETC_PF_TMR_TMR_ALARM_H_ALARM_H(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_H_ALARM_H_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_H_ALARM_H_MASK)
/*! @} */

/* The count of ENETC_PF_TMR_TMR_ALARM_H */
#define ENETC_PF_TMR_TMR_ALARM_H_COUNT           (2U)

/*! @name TMR_ALARM_CTRL - Timer Alarm Control Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM1_PW_MASK (0x1FU)
#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM1_PW_SHIFT (0U)
/*! ALARM1_PW - ALARM 1 pulse width selector */
#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM1_PW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM1_PW_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM1_PW_MASK)

#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG1_MASK     (0x80U)
#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG1_SHIFT    (7U)
/*! PG1 - Alarm1 pulse generation time */
#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG1(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_CTRL_PG1_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_CTRL_PG1_MASK)

#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM2_PW_MASK (0x1F00U)
#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM2_PW_SHIFT (8U)
/*! ALARM2_PW - ALARM 2 pulse width selector */
#define ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM2_PW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM2_PW_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_CTRL_ALARM2_PW_MASK)

#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG2_MASK     (0x8000U)
#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG2_SHIFT    (15U)
/*! PG2 - Alarm2 pulse generation time */
#define ENETC_PF_TMR_TMR_ALARM_CTRL_PG2(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ALARM_CTRL_PG2_SHIFT)) & ENETC_PF_TMR_TMR_ALARM_CTRL_PG2_MASK)
/*! @} */

/*! @name TMR_FIPER - Timer 1 fixed interval period register..Timer 3 fixed interval period register */
/*! @{ */

#define ENETC_PF_TMR_TMR_FIPER_FIPER_MASK        (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_FIPER_FIPER_SHIFT       (0U)
/*! FIPER - Fixed Interval Pulse Period */
#define ENETC_PF_TMR_TMR_FIPER_FIPER(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_FIPER_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_FIPER_MASK)
/*! @} */

/* The count of ENETC_PF_TMR_TMR_FIPER */
#define ENETC_PF_TMR_TMR_FIPER_COUNT             (3U)

/*! @name TMR_FIPER_CTRL - Timer FIPER Control Register */
/*! @{ */

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_PW_MASK (0x1FU)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_PW_SHIFT (0U)
/*! FIPER1_PW - FIPER 1 pulse width selection */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_PW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_PW_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_PW_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG1_MASK     (0x40U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG1_SHIFT    (6U)
/*! PG1 - FIPER1 pulse generation select */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG1(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_PG1_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_PG1_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_DIS_MASK (0x80U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT (7U)
/*! FIPER1_DIS - FIPER1 disable */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_DIS(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_DIS_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER1_DIS_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_PW_MASK (0x1F00U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_PW_SHIFT (8U)
/*! FIPER2_PW - FIPER 2 pulse width selection */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_PW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_PW_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_PW_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG2_MASK     (0x4000U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG2_SHIFT    (14U)
/*! PG2 - FIPER2 pulse generation time */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG2(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_PG2_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_PG2_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_DIS_MASK (0x8000U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT (15U)
/*! FIPER2_DIS - FIPER2 disable */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_DIS(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_DIS_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER2_DIS_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_PW_MASK (0x1F0000U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_PW_SHIFT (16U)
/*! FIPER3_PW - FIPER 3 pulse width selection */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_PW(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_PW_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_PW_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG3_MASK     (0x400000U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG3_SHIFT    (22U)
/*! PG3 - FIPER3 pulse generation time */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_PG3(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_PG3_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_PG3_MASK)

#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_DIS_MASK (0x800000U)
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT (23U)
/*! FIPER3_DIS - FIPER3 disable */
#define ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_DIS(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_DIS_SHIFT)) & ENETC_PF_TMR_TMR_FIPER_CTRL_FIPER3_DIS_MASK)
/*! @} */

/*! @name TMR_ETTS_L - External trigger stamp register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ETTS_L_ETTS_L_MASK      (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ETTS_L_ETTS_L_SHIFT     (0U)
#define ENETC_PF_TMR_TMR_ETTS_L_ETTS_L(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ETTS_L_ETTS_L_SHIFT)) & ENETC_PF_TMR_TMR_ETTS_L_ETTS_L_MASK)
/*! @} */

/* The count of ENETC_PF_TMR_TMR_ETTS_L */
#define ENETC_PF_TMR_TMR_ETTS_L_COUNT            (2U)

/*! @name TMR_ETTS_H - External trigger stamp register */
/*! @{ */

#define ENETC_PF_TMR_TMR_ETTS_H_ETTS_H_MASK      (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_ETTS_H_ETTS_H_SHIFT     (0U)
#define ENETC_PF_TMR_TMR_ETTS_H_ETTS_H(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_ETTS_H_ETTS_H_SHIFT)) & ENETC_PF_TMR_TMR_ETTS_H_ETTS_H_MASK)
/*! @} */

/* The count of ENETC_PF_TMR_TMR_ETTS_H */
#define ENETC_PF_TMR_TMR_ETTS_H_COUNT            (2U)

/*! @name TMR_CUR_TIME_L - Timer current time low register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT (0U)
#define ENETC_PF_TMR_TMR_CUR_TIME_L_TMR_CUR_TIME_L(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CUR_TIME_L_TMR_CUR_TIME_L_SHIFT)) & ENETC_PF_TMR_TMR_CUR_TIME_L_TMR_CUR_TIME_L_MASK)
/*! @} */

/*! @name TMR_CUR_TIME_H - Timer current time high register */
/*! @{ */

#define ENETC_PF_TMR_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK (0xFFFFFFFFU)
#define ENETC_PF_TMR_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT (0U)
#define ENETC_PF_TMR_TMR_CUR_TIME_H_TMR_CUR_TIME_H(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_CUR_TIME_H_TMR_CUR_TIME_H_SHIFT)) & ENETC_PF_TMR_TMR_CUR_TIME_H_TMR_CUR_TIME_H_MASK)
/*! @} */

/*! @name TMR_PARAM - Timer parameter register */
/*! @{ */

#define ENETC_PF_TMR_TMR_PARAM_SYNC_MASK         (0x1U)
#define ENETC_PF_TMR_TMR_PARAM_SYNC_SHIFT        (0U)
/*! SYNC - Timer synchronization */
#define ENETC_PF_TMR_TMR_PARAM_SYNC(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_PARAM_SYNC_SHIFT)) & ENETC_PF_TMR_TMR_PARAM_SYNC_MASK)

#define ENETC_PF_TMR_TMR_PARAM_PARAM_VAL_MASK    (0xFFFFFFFEU)
#define ENETC_PF_TMR_TMR_PARAM_PARAM_VAL_SHIFT   (1U)
/*! PARAM_VAL - User specific parameter values */
#define ENETC_PF_TMR_TMR_PARAM_PARAM_VAL(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_TMR_TMR_PARAM_PARAM_VAL_SHIFT)) & ENETC_PF_TMR_TMR_PARAM_PARAM_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENETC_PF_TMR_Register_Masks */


/*!
 * @}
 */ /* end of group ENETC_PF_TMR_Peripheral_Access_Layer */


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


#endif  /* PERI_ENETC_PF_TMR_H_ */

