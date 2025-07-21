/*
** ###################################################################
**     Processors:          MIMXRT1064CVJ5A
**                          MIMXRT1064CVJ5B
**                          MIMXRT1064CVL5A
**                          MIMXRT1064CVL5B
**                          MIMXRT1064DVJ6A
**                          MIMXRT1064DVJ6B
**                          MIMXRT1064DVL6A
**                          MIMXRT1064DVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CSU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-06-22)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1064RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1064RM Rev.0.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1064RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CSU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CSU
 *
 * CMSIS Peripheral Access Layer for CSU
 */

#if !defined(PERI_CSU_H_)
#define PERI_CSU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1064CVJ5A) || defined(CPU_MIMXRT1064CVJ5B) || defined(CPU_MIMXRT1064CVL5A) || defined(CPU_MIMXRT1064CVL5B) || defined(CPU_MIMXRT1064DVJ6A) || defined(CPU_MIMXRT1064DVJ6B) || defined(CPU_MIMXRT1064DVL6A) || defined(CPU_MIMXRT1064DVL6B))
#include "MIMXRT1064_COMMON.h"
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
   -- CSU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSU_Peripheral_Access_Layer CSU Peripheral Access Layer
 * @{
 */

/** CSU - Size of Registers Arrays */
#define CSU_CSL_COUNT                             32u

/** CSU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSL[CSU_CSL_COUNT];                /**< Config security level register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[384];
  __IO uint32_t HP0;                               /**< HP0 register, offset: 0x200 */
       uint8_t RESERVED_1[20];
  __IO uint32_t SA;                                /**< Secure access register, offset: 0x218 */
       uint8_t RESERVED_2[316];
  __IO uint32_t HPCONTROL0;                        /**< HPCONTROL0 register, offset: 0x358 */
} CSU_Type;

/* ----------------------------------------------------------------------------
   -- CSU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSU_Register_Masks CSU Register Masks
 * @{
 */

/*! @name CSL - Config security level register */
/*! @{ */

#define CSU_CSL_SUR_S2_MASK                      (0x1U)
#define CSU_CSL_SUR_S2_SHIFT                     (0U)
/*! SUR_S2
 *  0b0..The secure user read access is disabled for the second slave.
 *  0b1..The secure user read access is enabled for the second slave.
 */
#define CSU_CSL_SUR_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SUR_S2_SHIFT)) & CSU_CSL_SUR_S2_MASK)

#define CSU_CSL_SSR_S2_MASK                      (0x2U)
#define CSU_CSL_SSR_S2_SHIFT                     (1U)
/*! SSR_S2
 *  0b0..The secure supervisor read access is disabled for the second slave.
 *  0b1..The secure supervisor read access is enabled for the second slave.
 */
#define CSU_CSL_SSR_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SSR_S2_SHIFT)) & CSU_CSL_SSR_S2_MASK)

#define CSU_CSL_NUR_S2_MASK                      (0x4U)
#define CSU_CSL_NUR_S2_SHIFT                     (2U)
/*! NUR_S2
 *  0b0..The non-secure user read access is disabled for the second slave.
 *  0b1..The non-secure user read access is enabled for the second slave.
 */
#define CSU_CSL_NUR_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NUR_S2_SHIFT)) & CSU_CSL_NUR_S2_MASK)

#define CSU_CSL_NSR_S2_MASK                      (0x8U)
#define CSU_CSL_NSR_S2_SHIFT                     (3U)
/*! NSR_S2
 *  0b0..The non-secure supervisor read access is disabled for the second slave.
 *  0b1..The non-secure supervisor read access is enabled for the second slave.
 */
#define CSU_CSL_NSR_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NSR_S2_SHIFT)) & CSU_CSL_NSR_S2_MASK)

#define CSU_CSL_SUW_S2_MASK                      (0x10U)
#define CSU_CSL_SUW_S2_SHIFT                     (4U)
/*! SUW_S2
 *  0b0..The secure user write access is disabled for the second slave.
 *  0b1..The secure user write access is enabled for the second slave.
 */
#define CSU_CSL_SUW_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SUW_S2_SHIFT)) & CSU_CSL_SUW_S2_MASK)

#define CSU_CSL_SSW_S2_MASK                      (0x20U)
#define CSU_CSL_SSW_S2_SHIFT                     (5U)
/*! SSW_S2
 *  0b0..The secure supervisor write access is disabled for the second slave.
 *  0b1..The secure supervisor write access is enabled for the second slave.
 */
#define CSU_CSL_SSW_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SSW_S2_SHIFT)) & CSU_CSL_SSW_S2_MASK)

#define CSU_CSL_NUW_S2_MASK                      (0x40U)
#define CSU_CSL_NUW_S2_SHIFT                     (6U)
/*! NUW_S2
 *  0b0..The non-secure user write access is disabled for the second slave.
 *  0b1..The non-secure user write access is enabled for the second slave.
 */
#define CSU_CSL_NUW_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NUW_S2_SHIFT)) & CSU_CSL_NUW_S2_MASK)

#define CSU_CSL_NSW_S2_MASK                      (0x80U)
#define CSU_CSL_NSW_S2_SHIFT                     (7U)
/*! NSW_S2
 *  0b0..The non-secure supervisor write access is disabled for the second slave.
 *  0b1..The non-secure supervisor write access is enabled for the second slave.
 */
#define CSU_CSL_NSW_S2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NSW_S2_SHIFT)) & CSU_CSL_NSW_S2_MASK)

#define CSU_CSL_LOCK_S2_MASK                     (0x100U)
#define CSU_CSL_LOCK_S2_SHIFT                    (8U)
/*! LOCK_S2
 *  0b0..Not locked. Bits 7-0 can be written by the software.
 *  0b1..Bits 7-0 are locked and cannot be written by the software
 */
#define CSU_CSL_LOCK_S2(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_CSL_LOCK_S2_SHIFT)) & CSU_CSL_LOCK_S2_MASK)

#define CSU_CSL_SUR_S1_MASK                      (0x10000U)
#define CSU_CSL_SUR_S1_SHIFT                     (16U)
/*! SUR_S1
 *  0b0..The secure user read access is disabled for the first slave.
 *  0b1..The secure user read access is enabled for the first slave.
 */
#define CSU_CSL_SUR_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SUR_S1_SHIFT)) & CSU_CSL_SUR_S1_MASK)

#define CSU_CSL_SSR_S1_MASK                      (0x20000U)
#define CSU_CSL_SSR_S1_SHIFT                     (17U)
/*! SSR_S1
 *  0b0..The secure supervisor read access is disabled for the first slave.
 *  0b1..The secure supervisor read access is enabled for the first slave.
 */
#define CSU_CSL_SSR_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SSR_S1_SHIFT)) & CSU_CSL_SSR_S1_MASK)

#define CSU_CSL_NUR_S1_MASK                      (0x40000U)
#define CSU_CSL_NUR_S1_SHIFT                     (18U)
/*! NUR_S1
 *  0b0..The non-secure user read access is disabled for the first slave.
 *  0b1..The non-secure user read access is enabled for the first slave.
 */
#define CSU_CSL_NUR_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NUR_S1_SHIFT)) & CSU_CSL_NUR_S1_MASK)

#define CSU_CSL_NSR_S1_MASK                      (0x80000U)
#define CSU_CSL_NSR_S1_SHIFT                     (19U)
/*! NSR_S1
 *  0b0..The non-secure supervisor read access is disabled for the first slave.
 *  0b1..The non-secure supervisor read access is enabled for the first slave.
 */
#define CSU_CSL_NSR_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NSR_S1_SHIFT)) & CSU_CSL_NSR_S1_MASK)

#define CSU_CSL_SUW_S1_MASK                      (0x100000U)
#define CSU_CSL_SUW_S1_SHIFT                     (20U)
/*! SUW_S1
 *  0b0..The secure user write access is disabled for the first slave.
 *  0b1..The secure user write access is enabled for the first slave.
 */
#define CSU_CSL_SUW_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SUW_S1_SHIFT)) & CSU_CSL_SUW_S1_MASK)

#define CSU_CSL_SSW_S1_MASK                      (0x200000U)
#define CSU_CSL_SSW_S1_SHIFT                     (21U)
/*! SSW_S1
 *  0b0..The secure supervisor write access is disabled for the first slave.
 *  0b1..The secure supervisor write access is enabled for the first slave.
 */
#define CSU_CSL_SSW_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_SSW_S1_SHIFT)) & CSU_CSL_SSW_S1_MASK)

#define CSU_CSL_NUW_S1_MASK                      (0x400000U)
#define CSU_CSL_NUW_S1_SHIFT                     (22U)
/*! NUW_S1
 *  0b0..The non-secure user write access is disabled for the first slave.
 *  0b1..The non-secure user write access is enabled for the first slave.
 */
#define CSU_CSL_NUW_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NUW_S1_SHIFT)) & CSU_CSL_NUW_S1_MASK)

#define CSU_CSL_NSW_S1_MASK                      (0x800000U)
#define CSU_CSL_NSW_S1_SHIFT                     (23U)
/*! NSW_S1
 *  0b0..The non-secure supervisor write access is disabled for the first slave.
 *  0b1..The non-secure supervisor write access is enabled for the first slave
 */
#define CSU_CSL_NSW_S1(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_CSL_NSW_S1_SHIFT)) & CSU_CSL_NSW_S1_MASK)

#define CSU_CSL_LOCK_S1_MASK                     (0x1000000U)
#define CSU_CSL_LOCK_S1_SHIFT                    (24U)
/*! LOCK_S1
 *  0b0..Not locked. The bits 16-23 can be written by the software.
 *  0b1..The bits 16-23 are locked and can't be written by the software.
 */
#define CSU_CSL_LOCK_S1(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_CSL_LOCK_S1_SHIFT)) & CSU_CSL_LOCK_S1_MASK)
/*! @} */

/*! @name HP0 - HP0 register */
/*! @{ */

#define CSU_HP0_HP_DMA_MASK                      (0x4U)
#define CSU_HP0_HP_DMA_SHIFT                     (2U)
/*! HP_DMA
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_DMA(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_DMA_SHIFT)) & CSU_HP0_HP_DMA_MASK)

#define CSU_HP0_L_DMA_MASK                       (0x8U)
#define CSU_HP0_L_DMA_SHIFT                      (3U)
/*! L_DMA
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_DMA(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_DMA_SHIFT)) & CSU_HP0_L_DMA_MASK)

#define CSU_HP0_HP_LCDIF_MASK                    (0x10U)
#define CSU_HP0_HP_LCDIF_SHIFT                   (4U)
/*! HP_LCDIF
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_LCDIF(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_LCDIF_SHIFT)) & CSU_HP0_HP_LCDIF_MASK)

#define CSU_HP0_L_LCDIF_MASK                     (0x20U)
#define CSU_HP0_L_LCDIF_SHIFT                    (5U)
/*! L_LCDIF
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_LCDIF(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_LCDIF_SHIFT)) & CSU_HP0_L_LCDIF_MASK)

#define CSU_HP0_HP_CSI_MASK                      (0x40U)
#define CSU_HP0_HP_CSI_SHIFT                     (6U)
/*! HP_CSI
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_CSI(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_CSI_SHIFT)) & CSU_HP0_HP_CSI_MASK)

#define CSU_HP0_L_CSI_MASK                       (0x80U)
#define CSU_HP0_L_CSI_SHIFT                      (7U)
/*! L_CSI
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_CSI(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_CSI_SHIFT)) & CSU_HP0_L_CSI_MASK)

#define CSU_HP0_HP_PXP_MASK                      (0x100U)
#define CSU_HP0_HP_PXP_SHIFT                     (8U)
/*! HP_PXP
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_PXP(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_PXP_SHIFT)) & CSU_HP0_HP_PXP_MASK)

#define CSU_HP0_L_PXP_MASK                       (0x200U)
#define CSU_HP0_L_PXP_SHIFT                      (9U)
/*! L_PXP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_PXP(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_PXP_SHIFT)) & CSU_HP0_L_PXP_MASK)

#define CSU_HP0_HP_DCP_MASK                      (0x400U)
#define CSU_HP0_HP_DCP_SHIFT                     (10U)
/*! HP_DCP
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_DCP(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_DCP_SHIFT)) & CSU_HP0_HP_DCP_MASK)

#define CSU_HP0_L_DCP_MASK                       (0x800U)
#define CSU_HP0_L_DCP_SHIFT                      (11U)
/*! L_DCP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit cannot be written by the software.
 */
#define CSU_HP0_L_DCP(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_DCP_SHIFT)) & CSU_HP0_L_DCP_MASK)

#define CSU_HP0_HP_ENET_MASK                     (0x4000U)
#define CSU_HP0_HP_ENET_SHIFT                    (14U)
/*! HP_ENET
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_ENET(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_ENET_SHIFT)) & CSU_HP0_HP_ENET_MASK)

#define CSU_HP0_L_ENET_MASK                      (0x8000U)
#define CSU_HP0_L_ENET_SHIFT                     (15U)
/*! L_ENET
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_ENET(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_ENET_SHIFT)) & CSU_HP0_L_ENET_MASK)

#define CSU_HP0_HP_USDHC1_MASK                   (0x10000U)
#define CSU_HP0_HP_USDHC1_SHIFT                  (16U)
/*! HP_USDHC1
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_USDHC1(x)                     (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_USDHC1_SHIFT)) & CSU_HP0_HP_USDHC1_MASK)

#define CSU_HP0_L_USDHC1_MASK                    (0x20000U)
#define CSU_HP0_L_USDHC1_SHIFT                   (17U)
/*! L_USDHC1
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_USDHC1(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_USDHC1_SHIFT)) & CSU_HP0_L_USDHC1_MASK)

#define CSU_HP0_HP_USDHC2_MASK                   (0x40000U)
#define CSU_HP0_HP_USDHC2_SHIFT                  (18U)
/*! HP_USDHC2
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_USDHC2(x)                     (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_USDHC2_SHIFT)) & CSU_HP0_HP_USDHC2_MASK)

#define CSU_HP0_L_USDHC2_MASK                    (0x80000U)
#define CSU_HP0_L_USDHC2_SHIFT                   (19U)
/*! L_USDHC2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_USDHC2(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_USDHC2_SHIFT)) & CSU_HP0_L_USDHC2_MASK)

#define CSU_HP0_HP_TPSMP_MASK                    (0x100000U)
#define CSU_HP0_HP_TPSMP_SHIFT                   (20U)
/*! HP_TPSMP
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_TPSMP(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_TPSMP_SHIFT)) & CSU_HP0_HP_TPSMP_MASK)

#define CSU_HP0_L_TPSMP_MASK                     (0x200000U)
#define CSU_HP0_L_TPSMP_SHIFT                    (21U)
/*! L_TPSMP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_TPSMP(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_TPSMP_SHIFT)) & CSU_HP0_L_TPSMP_MASK)

#define CSU_HP0_HP_USB_MASK                      (0x400000U)
#define CSU_HP0_HP_USB_SHIFT                     (22U)
/*! HP_USB
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_USB(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_USB_SHIFT)) & CSU_HP0_HP_USB_MASK)

#define CSU_HP0_L_USB_MASK                       (0x800000U)
#define CSU_HP0_L_USB_SHIFT                      (23U)
/*! L_USB
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_USB(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_USB_SHIFT)) & CSU_HP0_L_USB_MASK)

#define CSU_HP0_HP_ENET2_MASK                    (0x1000000U)
#define CSU_HP0_HP_ENET2_SHIFT                   (24U)
/*! HP_ENET2
 *  0b0..The hprot1 input signal value is routed to the csu_hprot1 output for the corresponding master.
 *  0b1..The HP register bit is routed to the csu_hprot1 output for the corresponding master.
 */
#define CSU_HP0_HP_ENET2(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_HP0_HP_ENET2_SHIFT)) & CSU_HP0_HP_ENET2_MASK)

#define CSU_HP0_L_ENET2_MASK                     (0x2000000U)
#define CSU_HP0_L_ENET2_SHIFT                    (25U)
/*! L_ENET2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HP0_L_ENET2(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_HP0_L_ENET2_SHIFT)) & CSU_HP0_L_ENET2_MASK)
/*! @} */

/*! @name SA - Secure access register */
/*! @{ */

#define CSU_SA_NSA_DMA_MASK                      (0x4U)
#define CSU_SA_NSA_DMA_SHIFT                     (2U)
/*! NSA_DMA - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_DMA(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_DMA_SHIFT)) & CSU_SA_NSA_DMA_MASK)

#define CSU_SA_L_DMA_MASK                        (0x8U)
#define CSU_SA_L_DMA_SHIFT                       (3U)
/*! L_DMA
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_DMA(x)                          (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_DMA_SHIFT)) & CSU_SA_L_DMA_MASK)

#define CSU_SA_NSA_LCDIF_MASK                    (0x10U)
#define CSU_SA_NSA_LCDIF_SHIFT                   (4U)
/*! NSA_LCDIF - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_LCDIF(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_LCDIF_SHIFT)) & CSU_SA_NSA_LCDIF_MASK)

#define CSU_SA_L_LCDIF_MASK                      (0x20U)
#define CSU_SA_L_LCDIF_SHIFT                     (5U)
/*! L_LCDIF
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_LCDIF(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_LCDIF_SHIFT)) & CSU_SA_L_LCDIF_MASK)

#define CSU_SA_NSA_CSI_MASK                      (0x40U)
#define CSU_SA_NSA_CSI_SHIFT                     (6U)
/*! NSA_CSI - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_CSI(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_CSI_SHIFT)) & CSU_SA_NSA_CSI_MASK)

#define CSU_SA_L_CSI_MASK                        (0x80U)
#define CSU_SA_L_CSI_SHIFT                       (7U)
/*! L_CSI
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_CSI(x)                          (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_CSI_SHIFT)) & CSU_SA_L_CSI_MASK)

#define CSU_SA_NSA_PXP_MASK                      (0x100U)
#define CSU_SA_NSA_PXP_SHIFT                     (8U)
/*! NSA_PXP - Non-Secure Access Policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_PXP(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_PXP_SHIFT)) & CSU_SA_NSA_PXP_MASK)

#define CSU_SA_L_PXP_MASK                        (0x200U)
#define CSU_SA_L_PXP_SHIFT                       (9U)
/*! L_PXP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_PXP(x)                          (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_PXP_SHIFT)) & CSU_SA_L_PXP_MASK)

#define CSU_SA_NSA_DCP_MASK                      (0x400U)
#define CSU_SA_NSA_DCP_SHIFT                     (10U)
/*! NSA_DCP - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_DCP(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_DCP_SHIFT)) & CSU_SA_NSA_DCP_MASK)

#define CSU_SA_L_DCP_MASK                        (0x800U)
#define CSU_SA_L_DCP_SHIFT                       (11U)
/*! L_DCP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_DCP(x)                          (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_DCP_SHIFT)) & CSU_SA_L_DCP_MASK)

#define CSU_SA_NSA_ENET_MASK                     (0x4000U)
#define CSU_SA_NSA_ENET_SHIFT                    (14U)
/*! NSA_ENET - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_ENET(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_ENET_SHIFT)) & CSU_SA_NSA_ENET_MASK)

#define CSU_SA_L_ENET_MASK                       (0x8000U)
#define CSU_SA_L_ENET_SHIFT                      (15U)
/*! L_ENET
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_ENET(x)                         (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_ENET_SHIFT)) & CSU_SA_L_ENET_MASK)

#define CSU_SA_NSA_USDHC1_MASK                   (0x10000U)
#define CSU_SA_NSA_USDHC1_SHIFT                  (16U)
/*! NSA_USDHC1 - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_USDHC1(x)                     (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_USDHC1_SHIFT)) & CSU_SA_NSA_USDHC1_MASK)

#define CSU_SA_L_USDHC1_MASK                     (0x20000U)
#define CSU_SA_L_USDHC1_SHIFT                    (17U)
/*! L_USDHC1
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_USDHC1(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_USDHC1_SHIFT)) & CSU_SA_L_USDHC1_MASK)

#define CSU_SA_NSA_USDHC2_MASK                   (0x40000U)
#define CSU_SA_NSA_USDHC2_SHIFT                  (18U)
/*! NSA_USDHC2 - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_USDHC2(x)                     (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_USDHC2_SHIFT)) & CSU_SA_NSA_USDHC2_MASK)

#define CSU_SA_L_USDHC2_MASK                     (0x80000U)
#define CSU_SA_L_USDHC2_SHIFT                    (19U)
/*! L_USDHC2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_USDHC2(x)                       (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_USDHC2_SHIFT)) & CSU_SA_L_USDHC2_MASK)

#define CSU_SA_NSA_TPSMP_MASK                    (0x100000U)
#define CSU_SA_NSA_TPSMP_SHIFT                   (20U)
/*! NSA_TPSMP - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_TPSMP(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_TPSMP_SHIFT)) & CSU_SA_NSA_TPSMP_MASK)

#define CSU_SA_L_TPSMP_MASK                      (0x200000U)
#define CSU_SA_L_TPSMP_SHIFT                     (21U)
/*! L_TPSMP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_TPSMP(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_TPSMP_SHIFT)) & CSU_SA_L_TPSMP_MASK)

#define CSU_SA_NSA_USB_MASK                      (0x400000U)
#define CSU_SA_NSA_USB_SHIFT                     (22U)
/*! NSA_USB - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_USB(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_USB_SHIFT)) & CSU_SA_NSA_USB_MASK)

#define CSU_SA_L_USB_MASK                        (0x800000U)
#define CSU_SA_L_USB_SHIFT                       (23U)
/*! L_USB
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_USB(x)                          (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_USB_SHIFT)) & CSU_SA_L_USB_MASK)

#define CSU_SA_NSA_ENET2_MASK                    (0x1000000U)
#define CSU_SA_NSA_ENET2_SHIFT                   (24U)
/*! NSA_ENET2 - Non-secure access policy indicator bit
 *  0b0..Secure access for the corresponding type-1 master
 *  0b1..Non-secure access for the corresponding type-1 master
 */
#define CSU_SA_NSA_ENET2(x)                      (((uint32_t)(((uint32_t)(x)) << CSU_SA_NSA_ENET2_SHIFT)) & CSU_SA_NSA_ENET2_MASK)

#define CSU_SA_L_ENET2_MASK                      (0x2000000U)
#define CSU_SA_L_ENET2_SHIFT                     (25U)
/*! L_ENET2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_SA_L_ENET2(x)                        (((uint32_t)(((uint32_t)(x)) << CSU_SA_L_ENET2_SHIFT)) & CSU_SA_L_ENET2_MASK)
/*! @} */

/*! @name HPCONTROL0 - HPCONTROL0 register */
/*! @{ */

#define CSU_HPCONTROL0_HPC_DMA_MASK              (0x4U)
#define CSU_HPCONTROL0_HPC_DMA_SHIFT             (2U)
/*! HPC_DMA
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_DMA(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_DMA_SHIFT)) & CSU_HPCONTROL0_HPC_DMA_MASK)

#define CSU_HPCONTROL0_L_DMA_MASK                (0x8U)
#define CSU_HPCONTROL0_L_DMA_SHIFT               (3U)
/*! L_DMA
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_DMA(x)                  (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_DMA_SHIFT)) & CSU_HPCONTROL0_L_DMA_MASK)

#define CSU_HPCONTROL0_HPC_LCDIF_MASK            (0x10U)
#define CSU_HPCONTROL0_HPC_LCDIF_SHIFT           (4U)
/*! HPC_LCDIF
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_LCDIF(x)              (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_LCDIF_SHIFT)) & CSU_HPCONTROL0_HPC_LCDIF_MASK)

#define CSU_HPCONTROL0_L_LCDIF_MASK              (0x20U)
#define CSU_HPCONTROL0_L_LCDIF_SHIFT             (5U)
/*! L_LCDIF
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_LCDIF(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_LCDIF_SHIFT)) & CSU_HPCONTROL0_L_LCDIF_MASK)

#define CSU_HPCONTROL0_HPC_CSI_MASK              (0x40U)
#define CSU_HPCONTROL0_HPC_CSI_SHIFT             (6U)
/*! HPC_CSI
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_CSI(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_CSI_SHIFT)) & CSU_HPCONTROL0_HPC_CSI_MASK)

#define CSU_HPCONTROL0_L_CSI_MASK                (0x80U)
#define CSU_HPCONTROL0_L_CSI_SHIFT               (7U)
/*! L_CSI
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_CSI(x)                  (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_CSI_SHIFT)) & CSU_HPCONTROL0_L_CSI_MASK)

#define CSU_HPCONTROL0_HPC_PXP_MASK              (0x100U)
#define CSU_HPCONTROL0_HPC_PXP_SHIFT             (8U)
/*! HPC_PXP
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_PXP(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_PXP_SHIFT)) & CSU_HPCONTROL0_HPC_PXP_MASK)

#define CSU_HPCONTROL0_L_PXP_MASK                (0x200U)
#define CSU_HPCONTROL0_L_PXP_SHIFT               (9U)
/*! L_PXP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_PXP(x)                  (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_PXP_SHIFT)) & CSU_HPCONTROL0_L_PXP_MASK)

#define CSU_HPCONTROL0_HPC_DCP_MASK              (0x400U)
#define CSU_HPCONTROL0_HPC_DCP_SHIFT             (10U)
/*! HPC_DCP
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_DCP(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_DCP_SHIFT)) & CSU_HPCONTROL0_HPC_DCP_MASK)

#define CSU_HPCONTROL0_L_DCP_MASK                (0x800U)
#define CSU_HPCONTROL0_L_DCP_SHIFT               (11U)
/*! L_DCP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_DCP(x)                  (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_DCP_SHIFT)) & CSU_HPCONTROL0_L_DCP_MASK)

#define CSU_HPCONTROL0_HPC_ENET_MASK             (0x4000U)
#define CSU_HPCONTROL0_HPC_ENET_SHIFT            (14U)
/*! HPC_ENET
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_ENET(x)               (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_ENET_SHIFT)) & CSU_HPCONTROL0_HPC_ENET_MASK)

#define CSU_HPCONTROL0_L_ENET_MASK               (0x8000U)
#define CSU_HPCONTROL0_L_ENET_SHIFT              (15U)
/*! L_ENET
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_ENET(x)                 (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_ENET_SHIFT)) & CSU_HPCONTROL0_L_ENET_MASK)

#define CSU_HPCONTROL0_HPC_USDHC1_MASK           (0x10000U)
#define CSU_HPCONTROL0_HPC_USDHC1_SHIFT          (16U)
/*! HPC_USDHC1
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_USDHC1(x)             (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_USDHC1_SHIFT)) & CSU_HPCONTROL0_HPC_USDHC1_MASK)

#define CSU_HPCONTROL0_L_USDHC1_MASK             (0x20000U)
#define CSU_HPCONTROL0_L_USDHC1_SHIFT            (17U)
/*! L_USDHC1
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_USDHC1(x)               (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_USDHC1_SHIFT)) & CSU_HPCONTROL0_L_USDHC1_MASK)

#define CSU_HPCONTROL0_HPC_USDHC2_MASK           (0x40000U)
#define CSU_HPCONTROL0_HPC_USDHC2_SHIFT          (18U)
/*! HPC_USDHC2
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_USDHC2(x)             (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_USDHC2_SHIFT)) & CSU_HPCONTROL0_HPC_USDHC2_MASK)

#define CSU_HPCONTROL0_L_USDHC2_MASK             (0x80000U)
#define CSU_HPCONTROL0_L_USDHC2_SHIFT            (19U)
/*! L_USDHC2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_USDHC2(x)               (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_USDHC2_SHIFT)) & CSU_HPCONTROL0_L_USDHC2_MASK)

#define CSU_HPCONTROL0_HPC_TPSMP_MASK            (0x100000U)
#define CSU_HPCONTROL0_HPC_TPSMP_SHIFT           (20U)
/*! HPC_TPSMP
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_TPSMP(x)              (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_TPSMP_SHIFT)) & CSU_HPCONTROL0_HPC_TPSMP_MASK)

#define CSU_HPCONTROL0_L_TPSMP_MASK              (0x200000U)
#define CSU_HPCONTROL0_L_TPSMP_SHIFT             (21U)
/*! L_TPSMP
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_TPSMP(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_TPSMP_SHIFT)) & CSU_HPCONTROL0_L_TPSMP_MASK)

#define CSU_HPCONTROL0_HPC_USB_MASK              (0x400000U)
#define CSU_HPCONTROL0_HPC_USB_SHIFT             (22U)
/*! HPC_USB
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_USB(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_USB_SHIFT)) & CSU_HPCONTROL0_HPC_USB_MASK)

#define CSU_HPCONTROL0_L_USB_MASK                (0x800000U)
#define CSU_HPCONTROL0_L_USB_SHIFT               (23U)
/*! L_USB
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_USB(x)                  (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_USB_SHIFT)) & CSU_HPCONTROL0_L_USB_MASK)

#define CSU_HPCONTROL0_HPC_ENET2_MASK            (0x1000000U)
#define CSU_HPCONTROL0_HPC_ENET2_SHIFT           (24U)
/*! HPC_ENET2
 *  0b0..User mode for the corresponding master
 *  0b1..Supervisor mode for the corresponding master
 */
#define CSU_HPCONTROL0_HPC_ENET2(x)              (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_HPC_ENET2_SHIFT)) & CSU_HPCONTROL0_HPC_ENET2_MASK)

#define CSU_HPCONTROL0_L_ENET2_MASK              (0x2000000U)
#define CSU_HPCONTROL0_L_ENET2_SHIFT             (25U)
/*! L_ENET2
 *  0b0..No lock-the adjacent (next lower) bit can be written by the software.
 *  0b1..Lock-the adjacent (next lower) bit can't be written by the software.
 */
#define CSU_HPCONTROL0_L_ENET2(x)                (((uint32_t)(((uint32_t)(x)) << CSU_HPCONTROL0_L_ENET2_SHIFT)) & CSU_HPCONTROL0_L_ENET2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CSU_Register_Masks */


/*!
 * @}
 */ /* end of group CSU_Peripheral_Access_Layer */


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


#endif  /* PERI_CSU_H_ */

