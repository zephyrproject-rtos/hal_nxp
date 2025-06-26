/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 1.0, 2021-01-18
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PORT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PORT.h
 * @version 1.0
 * @date 2021-01-18
 * @brief CMSIS Peripheral Access Layer for PORT
 *
 * CMSIS Peripheral Access Layer for PORT
 */

#if !defined(PORT_H_)
#define PORT_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                            23u

/** PORT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __O  uint32_t GPCLR;                             /**< Global Pin Control Low, offset: 0x10 */
  __O  uint32_t GPCHR;                             /**< Global Pin Control High, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CONFIG;                            /**< Configuration, offset: 0x20 */
       uint8_t RESERVED_2[28];
  __I  uint32_t EDFR;                              /**< EFT Detect Flag, offset: 0x40 */
  __IO uint32_t EDIER;                             /**< EFT Detect Interrupt Enable, offset: 0x44 */
  __IO uint32_t EDCR;                              /**< EFT Detect Clear, offset: 0x48 */
       uint8_t RESERVED_3[52];
  __IO uint32_t PCR[PORT_PCR_COUNT];               /**< Pin Control 0..Pin Control 22, array offset: 0x80, array step: 0x4, irregular array, not all indices are valid */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define PORT_VERID_FEATURE_MASK                  (0xFFFFU)
#define PORT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Basic implementation
 */
#define PORT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_VERID_FEATURE_SHIFT)) & PORT_VERID_FEATURE_MASK)

#define PORT_VERID_MINOR_MASK                    (0xFF0000U)
#define PORT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define PORT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_VERID_MINOR_SHIFT)) & PORT_VERID_MINOR_MASK)

#define PORT_VERID_MAJOR_MASK                    (0xFF000000U)
#define PORT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define PORT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_VERID_MAJOR_SHIFT)) & PORT_VERID_MAJOR_MASK)
/*! @} */

/*! @name GPCLR - Global Pin Control Low */
/*! @{ */

#define PORT_GPCLR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCLR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCLR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWD_SHIFT)) & PORT_GPCLR_GPWD_MASK)

#define PORT_GPCLR_GPWE0_MASK                    (0x10000U)
#define PORT_GPCLR_GPWE0_SHIFT                   (16U)
/*! GPWE0 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE0_SHIFT)) & PORT_GPCLR_GPWE0_MASK)

#define PORT_GPCLR_GPWE1_MASK                    (0x20000U)
#define PORT_GPCLR_GPWE1_SHIFT                   (17U)
/*! GPWE1 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE1_SHIFT)) & PORT_GPCLR_GPWE1_MASK)

#define PORT_GPCLR_GPWE2_MASK                    (0x40000U)
#define PORT_GPCLR_GPWE2_SHIFT                   (18U)
/*! GPWE2 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE2_SHIFT)) & PORT_GPCLR_GPWE2_MASK)

#define PORT_GPCLR_GPWE3_MASK                    (0x80000U)
#define PORT_GPCLR_GPWE3_SHIFT                   (19U)
/*! GPWE3 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE3_SHIFT)) & PORT_GPCLR_GPWE3_MASK)

#define PORT_GPCLR_GPWE4_MASK                    (0x100000U)
#define PORT_GPCLR_GPWE4_SHIFT                   (20U)
/*! GPWE4 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE4_SHIFT)) & PORT_GPCLR_GPWE4_MASK)

#define PORT_GPCLR_GPWE5_MASK                    (0x200000U)
#define PORT_GPCLR_GPWE5_SHIFT                   (21U)
/*! GPWE5 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE5_SHIFT)) & PORT_GPCLR_GPWE5_MASK)

#define PORT_GPCLR_GPWE6_MASK                    (0x400000U)
#define PORT_GPCLR_GPWE6_SHIFT                   (22U)
/*! GPWE6 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE6_SHIFT)) & PORT_GPCLR_GPWE6_MASK)

#define PORT_GPCLR_GPWE7_MASK                    (0x800000U)
#define PORT_GPCLR_GPWE7_SHIFT                   (23U)
/*! GPWE7 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE7_SHIFT)) & PORT_GPCLR_GPWE7_MASK)

#define PORT_GPCLR_GPWE8_MASK                    (0x1000000U)
#define PORT_GPCLR_GPWE8_SHIFT                   (24U)
/*! GPWE8 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE8(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE8_SHIFT)) & PORT_GPCLR_GPWE8_MASK)

#define PORT_GPCLR_GPWE9_MASK                    (0x2000000U)
#define PORT_GPCLR_GPWE9_SHIFT                   (25U)
/*! GPWE9 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE9(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE9_SHIFT)) & PORT_GPCLR_GPWE9_MASK)

#define PORT_GPCLR_GPWE10_MASK                   (0x4000000U)
#define PORT_GPCLR_GPWE10_SHIFT                  (26U)
/*! GPWE10 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE10(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE10_SHIFT)) & PORT_GPCLR_GPWE10_MASK)

#define PORT_GPCLR_GPWE11_MASK                   (0x8000000U)
#define PORT_GPCLR_GPWE11_SHIFT                  (27U)
/*! GPWE11 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE11(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE11_SHIFT)) & PORT_GPCLR_GPWE11_MASK)

#define PORT_GPCLR_GPWE12_MASK                   (0x10000000U)
#define PORT_GPCLR_GPWE12_SHIFT                  (28U)
/*! GPWE12 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE12(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE12_SHIFT)) & PORT_GPCLR_GPWE12_MASK)

#define PORT_GPCLR_GPWE13_MASK                   (0x20000000U)
#define PORT_GPCLR_GPWE13_SHIFT                  (29U)
/*! GPWE13 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE13(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE13_SHIFT)) & PORT_GPCLR_GPWE13_MASK)

#define PORT_GPCLR_GPWE14_MASK                   (0x40000000U)
#define PORT_GPCLR_GPWE14_SHIFT                  (30U)
/*! GPWE14 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE14(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE14_SHIFT)) & PORT_GPCLR_GPWE14_MASK)

#define PORT_GPCLR_GPWE15_MASK                   (0x80000000U)
#define PORT_GPCLR_GPWE15_SHIFT                  (31U)
/*! GPWE15 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCLR_GPWE15(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCLR_GPWE15_SHIFT)) & PORT_GPCLR_GPWE15_MASK)
/*! @} */

/*! @name GPCHR - Global Pin Control High */
/*! @{ */

#define PORT_GPCHR_GPWD_MASK                     (0xFFFFU)
#define PORT_GPCHR_GPWD_SHIFT                    (0U)
/*! GPWD - Global Pin Write Data */
#define PORT_GPCHR_GPWD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWD_SHIFT)) & PORT_GPCHR_GPWD_MASK)

#define PORT_GPCHR_GPWE16_MASK                   (0x10000U)
#define PORT_GPCHR_GPWE16_SHIFT                  (16U)
/*! GPWE16 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE16(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE16_SHIFT)) & PORT_GPCHR_GPWE16_MASK)

#define PORT_GPCHR_GPWE17_MASK                   (0x20000U)
#define PORT_GPCHR_GPWE17_SHIFT                  (17U)
/*! GPWE17 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE17(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE17_SHIFT)) & PORT_GPCHR_GPWE17_MASK)

#define PORT_GPCHR_GPWE18_MASK                   (0x40000U)
#define PORT_GPCHR_GPWE18_SHIFT                  (18U)
/*! GPWE18 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE18(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE18_SHIFT)) & PORT_GPCHR_GPWE18_MASK)

#define PORT_GPCHR_GPWE19_MASK                   (0x80000U)
#define PORT_GPCHR_GPWE19_SHIFT                  (19U)
/*! GPWE19 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE19(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE19_SHIFT)) & PORT_GPCHR_GPWE19_MASK)

#define PORT_GPCHR_GPWE20_MASK                   (0x100000U)
#define PORT_GPCHR_GPWE20_SHIFT                  (20U)
/*! GPWE20 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE20(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE20_SHIFT)) & PORT_GPCHR_GPWE20_MASK)

#define PORT_GPCHR_GPWE21_MASK                   (0x200000U)
#define PORT_GPCHR_GPWE21_SHIFT                  (21U)
/*! GPWE21 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE21(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE21_SHIFT)) & PORT_GPCHR_GPWE21_MASK)

#define PORT_GPCHR_GPWE22_MASK                   (0x400000U)
#define PORT_GPCHR_GPWE22_SHIFT                  (22U)
/*! GPWE22 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE22(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE22_SHIFT)) & PORT_GPCHR_GPWE22_MASK)

#define PORT_GPCHR_GPWE23_MASK                   (0x800000U)
#define PORT_GPCHR_GPWE23_SHIFT                  (23U)
/*! GPWE23 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE23(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE23_SHIFT)) & PORT_GPCHR_GPWE23_MASK)

#define PORT_GPCHR_GPWE24_MASK                   (0x1000000U)
#define PORT_GPCHR_GPWE24_SHIFT                  (24U)
/*! GPWE24 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE24(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE24_SHIFT)) & PORT_GPCHR_GPWE24_MASK)

#define PORT_GPCHR_GPWE25_MASK                   (0x2000000U)
#define PORT_GPCHR_GPWE25_SHIFT                  (25U)
/*! GPWE25 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE25(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE25_SHIFT)) & PORT_GPCHR_GPWE25_MASK)

#define PORT_GPCHR_GPWE26_MASK                   (0x4000000U)
#define PORT_GPCHR_GPWE26_SHIFT                  (26U)
/*! GPWE26 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE26(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE26_SHIFT)) & PORT_GPCHR_GPWE26_MASK)

#define PORT_GPCHR_GPWE27_MASK                   (0x8000000U)
#define PORT_GPCHR_GPWE27_SHIFT                  (27U)
/*! GPWE27 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE27(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE27_SHIFT)) & PORT_GPCHR_GPWE27_MASK)

#define PORT_GPCHR_GPWE28_MASK                   (0x10000000U)
#define PORT_GPCHR_GPWE28_SHIFT                  (28U)
/*! GPWE28 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE28(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE28_SHIFT)) & PORT_GPCHR_GPWE28_MASK)

#define PORT_GPCHR_GPWE29_MASK                   (0x20000000U)
#define PORT_GPCHR_GPWE29_SHIFT                  (29U)
/*! GPWE29 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE29(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE29_SHIFT)) & PORT_GPCHR_GPWE29_MASK)

#define PORT_GPCHR_GPWE30_MASK                   (0x40000000U)
#define PORT_GPCHR_GPWE30_SHIFT                  (30U)
/*! GPWE30 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE30(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE30_SHIFT)) & PORT_GPCHR_GPWE30_MASK)

#define PORT_GPCHR_GPWE31_MASK                   (0x80000000U)
#define PORT_GPCHR_GPWE31_SHIFT                  (31U)
/*! GPWE31 - Global Pin Write Enable
 *  0b0..Not updated
 *  0b1..Updated
 */
#define PORT_GPCHR_GPWE31(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_GPCHR_GPWE31_SHIFT)) & PORT_GPCHR_GPWE31_MASK)
/*! @} */

/*! @name CONFIG - Configuration */
/*! @{ */

#define PORT_CONFIG_RANGE_MASK                   (0x1U)
#define PORT_CONFIG_RANGE_SHIFT                  (0U)
/*! RANGE - Port Voltage Range
 *  0b0..1.71 V-3.6 V
 *  0b1..2.70 V-3.6 V
 */
#define PORT_CONFIG_RANGE(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_CONFIG_RANGE_SHIFT)) & PORT_CONFIG_RANGE_MASK)
/*! @} */

/*! @name EDFR - EFT Detect Flag */
/*! @{ */

#define PORT_EDFR_EDF0_MASK                      (0x1U)
#define PORT_EDFR_EDF0_SHIFT                     (0U)
/*! EDF0 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF0(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF0_SHIFT)) & PORT_EDFR_EDF0_MASK)

#define PORT_EDFR_EDF1_MASK                      (0x2U)
#define PORT_EDFR_EDF1_SHIFT                     (1U)
/*! EDF1 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF1(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF1_SHIFT)) & PORT_EDFR_EDF1_MASK)

#define PORT_EDFR_EDF2_MASK                      (0x4U)
#define PORT_EDFR_EDF2_SHIFT                     (2U)
/*! EDF2 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF2(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF2_SHIFT)) & PORT_EDFR_EDF2_MASK)

#define PORT_EDFR_EDF3_MASK                      (0x8U)
#define PORT_EDFR_EDF3_SHIFT                     (3U)
/*! EDF3 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF3(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF3_SHIFT)) & PORT_EDFR_EDF3_MASK)

#define PORT_EDFR_EDF4_MASK                      (0x10U)
#define PORT_EDFR_EDF4_SHIFT                     (4U)
/*! EDF4 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF4(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF4_SHIFT)) & PORT_EDFR_EDF4_MASK)

#define PORT_EDFR_EDF5_MASK                      (0x20U)
#define PORT_EDFR_EDF5_SHIFT                     (5U)
/*! EDF5 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF5(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF5_SHIFT)) & PORT_EDFR_EDF5_MASK)

#define PORT_EDFR_EDF6_MASK                      (0x40U)
#define PORT_EDFR_EDF6_SHIFT                     (6U)
/*! EDF6 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF6(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF6_SHIFT)) & PORT_EDFR_EDF6_MASK)

#define PORT_EDFR_Reserved6_MASK                 (0x40U)
#define PORT_EDFR_Reserved6_SHIFT                (6U)
/*! Reserved6 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved6(x)                   (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved6_SHIFT)) & PORT_EDFR_Reserved6_MASK)

#define PORT_EDFR_Reserved7_MASK                 (0x80U)
#define PORT_EDFR_Reserved7_SHIFT                (7U)
/*! Reserved7 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved7(x)                   (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved7_SHIFT)) & PORT_EDFR_Reserved7_MASK)

#define PORT_EDFR_EDF8_MASK                      (0x100U)
#define PORT_EDFR_EDF8_SHIFT                     (8U)
/*! EDF8 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF8(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF8_SHIFT)) & PORT_EDFR_EDF8_MASK)

#define PORT_EDFR_Reserved8_MASK                 (0x100U)
#define PORT_EDFR_Reserved8_SHIFT                (8U)
/*! Reserved8 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved8(x)                   (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved8_SHIFT)) & PORT_EDFR_Reserved8_MASK)

#define PORT_EDFR_EDF9_MASK                      (0x200U)
#define PORT_EDFR_EDF9_SHIFT                     (9U)
/*! EDF9 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF9(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF9_SHIFT)) & PORT_EDFR_EDF9_MASK)

#define PORT_EDFR_Reserved9_MASK                 (0x200U)
#define PORT_EDFR_Reserved9_SHIFT                (9U)
/*! Reserved9 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved9(x)                   (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved9_SHIFT)) & PORT_EDFR_Reserved9_MASK)

#define PORT_EDFR_Reserved10_MASK                (0x400U)
#define PORT_EDFR_Reserved10_SHIFT               (10U)
/*! Reserved10 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved10(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved10_SHIFT)) & PORT_EDFR_Reserved10_MASK)

#define PORT_EDFR_Reserved11_MASK                (0x800U)
#define PORT_EDFR_Reserved11_SHIFT               (11U)
/*! Reserved11 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved11(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved11_SHIFT)) & PORT_EDFR_Reserved11_MASK)

#define PORT_EDFR_Reserved12_MASK                (0x1000U)
#define PORT_EDFR_Reserved12_SHIFT               (12U)
/*! Reserved12 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved12(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved12_SHIFT)) & PORT_EDFR_Reserved12_MASK)

#define PORT_EDFR_Reserved13_MASK                (0x2000U)
#define PORT_EDFR_Reserved13_SHIFT               (13U)
/*! Reserved13 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved13(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved13_SHIFT)) & PORT_EDFR_Reserved13_MASK)

#define PORT_EDFR_Reserved14_MASK                (0x4000U)
#define PORT_EDFR_Reserved14_SHIFT               (14U)
/*! Reserved14 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved14(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved14_SHIFT)) & PORT_EDFR_Reserved14_MASK)

#define PORT_EDFR_Reserved15_MASK                (0x8000U)
#define PORT_EDFR_Reserved15_SHIFT               (15U)
/*! Reserved15 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved15(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved15_SHIFT)) & PORT_EDFR_Reserved15_MASK)

#define PORT_EDFR_EDF16_MASK                     (0x10000U)
#define PORT_EDFR_EDF16_SHIFT                    (16U)
/*! EDF16 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF16(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF16_SHIFT)) & PORT_EDFR_EDF16_MASK)

#define PORT_EDFR_Reserved16_MASK                (0x10000U)
#define PORT_EDFR_Reserved16_SHIFT               (16U)
/*! Reserved16 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved16(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved16_SHIFT)) & PORT_EDFR_Reserved16_MASK)

#define PORT_EDFR_EDF17_MASK                     (0x20000U)
#define PORT_EDFR_EDF17_SHIFT                    (17U)
/*! EDF17 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF17(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF17_SHIFT)) & PORT_EDFR_EDF17_MASK)

#define PORT_EDFR_Reserved17_MASK                (0x20000U)
#define PORT_EDFR_Reserved17_SHIFT               (17U)
/*! Reserved17 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved17(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved17_SHIFT)) & PORT_EDFR_Reserved17_MASK)

#define PORT_EDFR_EDF18_MASK                     (0x40000U)
#define PORT_EDFR_EDF18_SHIFT                    (18U)
/*! EDF18 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF18(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF18_SHIFT)) & PORT_EDFR_EDF18_MASK)

#define PORT_EDFR_Reserved18_MASK                (0x40000U)
#define PORT_EDFR_Reserved18_SHIFT               (18U)
/*! Reserved18 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved18(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved18_SHIFT)) & PORT_EDFR_Reserved18_MASK)

#define PORT_EDFR_EDF19_MASK                     (0x80000U)
#define PORT_EDFR_EDF19_SHIFT                    (19U)
/*! EDF19 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF19(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF19_SHIFT)) & PORT_EDFR_EDF19_MASK)

#define PORT_EDFR_Reserved19_MASK                (0x80000U)
#define PORT_EDFR_Reserved19_SHIFT               (19U)
/*! Reserved19 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved19(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved19_SHIFT)) & PORT_EDFR_Reserved19_MASK)

#define PORT_EDFR_EDF20_MASK                     (0x100000U)
#define PORT_EDFR_EDF20_SHIFT                    (20U)
/*! EDF20 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF20(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF20_SHIFT)) & PORT_EDFR_EDF20_MASK)

#define PORT_EDFR_Reserved20_MASK                (0x100000U)
#define PORT_EDFR_Reserved20_SHIFT               (20U)
/*! Reserved20 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved20(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved20_SHIFT)) & PORT_EDFR_Reserved20_MASK)

#define PORT_EDFR_EDF21_MASK                     (0x200000U)
#define PORT_EDFR_EDF21_SHIFT                    (21U)
/*! EDF21 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF21(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF21_SHIFT)) & PORT_EDFR_EDF21_MASK)

#define PORT_EDFR_Reserved21_MASK                (0x200000U)
#define PORT_EDFR_Reserved21_SHIFT               (21U)
/*! Reserved21 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved21(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved21_SHIFT)) & PORT_EDFR_Reserved21_MASK)

#define PORT_EDFR_EDF22_MASK                     (0x400000U)
#define PORT_EDFR_EDF22_SHIFT                    (22U)
/*! EDF22 - EFT Detect Flag
 *  0b0..No EFT event detected
 *  0b1..High or/and low EFT event detected
 */
#define PORT_EDFR_EDF22(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_EDF22_SHIFT)) & PORT_EDFR_EDF22_MASK)

#define PORT_EDFR_Reserved22_MASK                (0x400000U)
#define PORT_EDFR_Reserved22_SHIFT               (22U)
/*! Reserved22 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved22(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved22_SHIFT)) & PORT_EDFR_Reserved22_MASK)

#define PORT_EDFR_Reserved23_MASK                (0x800000U)
#define PORT_EDFR_Reserved23_SHIFT               (23U)
/*! Reserved23 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved23(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved23_SHIFT)) & PORT_EDFR_Reserved23_MASK)

#define PORT_EDFR_Reserved24_MASK                (0x1000000U)
#define PORT_EDFR_Reserved24_SHIFT               (24U)
/*! Reserved24 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved24(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved24_SHIFT)) & PORT_EDFR_Reserved24_MASK)

#define PORT_EDFR_Reserved25_MASK                (0x2000000U)
#define PORT_EDFR_Reserved25_SHIFT               (25U)
/*! Reserved25 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved25(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved25_SHIFT)) & PORT_EDFR_Reserved25_MASK)

#define PORT_EDFR_Reserved26_MASK                (0x4000000U)
#define PORT_EDFR_Reserved26_SHIFT               (26U)
/*! Reserved26 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved26(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved26_SHIFT)) & PORT_EDFR_Reserved26_MASK)

#define PORT_EDFR_Reserved27_MASK                (0x8000000U)
#define PORT_EDFR_Reserved27_SHIFT               (27U)
/*! Reserved27 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved27(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved27_SHIFT)) & PORT_EDFR_Reserved27_MASK)

#define PORT_EDFR_Reserved28_MASK                (0x10000000U)
#define PORT_EDFR_Reserved28_SHIFT               (28U)
/*! Reserved28 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved28(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved28_SHIFT)) & PORT_EDFR_Reserved28_MASK)

#define PORT_EDFR_Reserved29_MASK                (0x20000000U)
#define PORT_EDFR_Reserved29_SHIFT               (29U)
/*! Reserved29 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved29(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved29_SHIFT)) & PORT_EDFR_Reserved29_MASK)

#define PORT_EDFR_Reserved30_MASK                (0x40000000U)
#define PORT_EDFR_Reserved30_SHIFT               (30U)
/*! Reserved30 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved30(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved30_SHIFT)) & PORT_EDFR_Reserved30_MASK)

#define PORT_EDFR_Reserved31_MASK                (0x80000000U)
#define PORT_EDFR_Reserved31_SHIFT               (31U)
/*! Reserved31 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDFR_Reserved31(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDFR_Reserved31_SHIFT)) & PORT_EDFR_Reserved31_MASK)
/*! @} */

/*! @name EDIER - EFT Detect Interrupt Enable */
/*! @{ */

#define PORT_EDIER_EDIE0_MASK                    (0x1U)
#define PORT_EDIER_EDIE0_SHIFT                   (0U)
/*! EDIE0 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE0_SHIFT)) & PORT_EDIER_EDIE0_MASK)

#define PORT_EDIER_EDIE1_MASK                    (0x2U)
#define PORT_EDIER_EDIE1_SHIFT                   (1U)
/*! EDIE1 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE1_SHIFT)) & PORT_EDIER_EDIE1_MASK)

#define PORT_EDIER_EDIE2_MASK                    (0x4U)
#define PORT_EDIER_EDIE2_SHIFT                   (2U)
/*! EDIE2 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE2_SHIFT)) & PORT_EDIER_EDIE2_MASK)

#define PORT_EDIER_EDIE3_MASK                    (0x8U)
#define PORT_EDIER_EDIE3_SHIFT                   (3U)
/*! EDIE3 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE3_SHIFT)) & PORT_EDIER_EDIE3_MASK)

#define PORT_EDIER_EDIE4_MASK                    (0x10U)
#define PORT_EDIER_EDIE4_SHIFT                   (4U)
/*! EDIE4 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE4_SHIFT)) & PORT_EDIER_EDIE4_MASK)

#define PORT_EDIER_EDIE5_MASK                    (0x20U)
#define PORT_EDIER_EDIE5_SHIFT                   (5U)
/*! EDIE5 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE5_SHIFT)) & PORT_EDIER_EDIE5_MASK)

#define PORT_EDIER_EDIE6_MASK                    (0x40U)
#define PORT_EDIER_EDIE6_SHIFT                   (6U)
/*! EDIE6 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE6_SHIFT)) & PORT_EDIER_EDIE6_MASK)

#define PORT_EDIER_Reserved6_MASK                (0x40U)
#define PORT_EDIER_Reserved6_SHIFT               (6U)
/*! Reserved6 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved6(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved6_SHIFT)) & PORT_EDIER_Reserved6_MASK)

#define PORT_EDIER_Reserved7_MASK                (0x80U)
#define PORT_EDIER_Reserved7_SHIFT               (7U)
/*! Reserved7 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved7(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved7_SHIFT)) & PORT_EDIER_Reserved7_MASK)

#define PORT_EDIER_EDIE8_MASK                    (0x100U)
#define PORT_EDIER_EDIE8_SHIFT                   (8U)
/*! EDIE8 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE8(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE8_SHIFT)) & PORT_EDIER_EDIE8_MASK)

#define PORT_EDIER_Reserved8_MASK                (0x100U)
#define PORT_EDIER_Reserved8_SHIFT               (8U)
/*! Reserved8 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved8(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved8_SHIFT)) & PORT_EDIER_Reserved8_MASK)

#define PORT_EDIER_EDIE9_MASK                    (0x200U)
#define PORT_EDIER_EDIE9_SHIFT                   (9U)
/*! EDIE9 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE9(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE9_SHIFT)) & PORT_EDIER_EDIE9_MASK)

#define PORT_EDIER_Reserved9_MASK                (0x200U)
#define PORT_EDIER_Reserved9_SHIFT               (9U)
/*! Reserved9 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved9(x)                  (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved9_SHIFT)) & PORT_EDIER_Reserved9_MASK)

#define PORT_EDIER_Reserved10_MASK               (0x400U)
#define PORT_EDIER_Reserved10_SHIFT              (10U)
/*! Reserved10 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved10(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved10_SHIFT)) & PORT_EDIER_Reserved10_MASK)

#define PORT_EDIER_Reserved11_MASK               (0x800U)
#define PORT_EDIER_Reserved11_SHIFT              (11U)
/*! Reserved11 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved11(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved11_SHIFT)) & PORT_EDIER_Reserved11_MASK)

#define PORT_EDIER_Reserved12_MASK               (0x1000U)
#define PORT_EDIER_Reserved12_SHIFT              (12U)
/*! Reserved12 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved12(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved12_SHIFT)) & PORT_EDIER_Reserved12_MASK)

#define PORT_EDIER_Reserved13_MASK               (0x2000U)
#define PORT_EDIER_Reserved13_SHIFT              (13U)
/*! Reserved13 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved13(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved13_SHIFT)) & PORT_EDIER_Reserved13_MASK)

#define PORT_EDIER_Reserved14_MASK               (0x4000U)
#define PORT_EDIER_Reserved14_SHIFT              (14U)
/*! Reserved14 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved14(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved14_SHIFT)) & PORT_EDIER_Reserved14_MASK)

#define PORT_EDIER_Reserved15_MASK               (0x8000U)
#define PORT_EDIER_Reserved15_SHIFT              (15U)
/*! Reserved15 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved15(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved15_SHIFT)) & PORT_EDIER_Reserved15_MASK)

#define PORT_EDIER_EDIE16_MASK                   (0x10000U)
#define PORT_EDIER_EDIE16_SHIFT                  (16U)
/*! EDIE16 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE16(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE16_SHIFT)) & PORT_EDIER_EDIE16_MASK)

#define PORT_EDIER_Reserved16_MASK               (0x10000U)
#define PORT_EDIER_Reserved16_SHIFT              (16U)
/*! Reserved16 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved16(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved16_SHIFT)) & PORT_EDIER_Reserved16_MASK)

#define PORT_EDIER_EDIE17_MASK                   (0x20000U)
#define PORT_EDIER_EDIE17_SHIFT                  (17U)
/*! EDIE17 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE17(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE17_SHIFT)) & PORT_EDIER_EDIE17_MASK)

#define PORT_EDIER_Reserved17_MASK               (0x20000U)
#define PORT_EDIER_Reserved17_SHIFT              (17U)
/*! Reserved17 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved17(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved17_SHIFT)) & PORT_EDIER_Reserved17_MASK)

#define PORT_EDIER_EDIE18_MASK                   (0x40000U)
#define PORT_EDIER_EDIE18_SHIFT                  (18U)
/*! EDIE18 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE18(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE18_SHIFT)) & PORT_EDIER_EDIE18_MASK)

#define PORT_EDIER_Reserved18_MASK               (0x40000U)
#define PORT_EDIER_Reserved18_SHIFT              (18U)
/*! Reserved18 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved18(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved18_SHIFT)) & PORT_EDIER_Reserved18_MASK)

#define PORT_EDIER_EDIE19_MASK                   (0x80000U)
#define PORT_EDIER_EDIE19_SHIFT                  (19U)
/*! EDIE19 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE19(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE19_SHIFT)) & PORT_EDIER_EDIE19_MASK)

#define PORT_EDIER_Reserved19_MASK               (0x80000U)
#define PORT_EDIER_Reserved19_SHIFT              (19U)
/*! Reserved19 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved19(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved19_SHIFT)) & PORT_EDIER_Reserved19_MASK)

#define PORT_EDIER_EDIE20_MASK                   (0x100000U)
#define PORT_EDIER_EDIE20_SHIFT                  (20U)
/*! EDIE20 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE20(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE20_SHIFT)) & PORT_EDIER_EDIE20_MASK)

#define PORT_EDIER_Reserved20_MASK               (0x100000U)
#define PORT_EDIER_Reserved20_SHIFT              (20U)
/*! Reserved20 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved20(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved20_SHIFT)) & PORT_EDIER_Reserved20_MASK)

#define PORT_EDIER_EDIE21_MASK                   (0x200000U)
#define PORT_EDIER_EDIE21_SHIFT                  (21U)
/*! EDIE21 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE21(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE21_SHIFT)) & PORT_EDIER_EDIE21_MASK)

#define PORT_EDIER_Reserved21_MASK               (0x200000U)
#define PORT_EDIER_Reserved21_SHIFT              (21U)
/*! Reserved21 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved21(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved21_SHIFT)) & PORT_EDIER_Reserved21_MASK)

#define PORT_EDIER_EDIE22_MASK                   (0x400000U)
#define PORT_EDIER_EDIE22_SHIFT                  (22U)
/*! EDIE22 - EFT Detect Interrupt Enable
 *  0b0..Interrupt not generated upon detection of the EFT event
 *  0b1..Interrupt generated upon detection of the EFT event
 */
#define PORT_EDIER_EDIE22(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_EDIE22_SHIFT)) & PORT_EDIER_EDIE22_MASK)

#define PORT_EDIER_Reserved22_MASK               (0x400000U)
#define PORT_EDIER_Reserved22_SHIFT              (22U)
/*! Reserved22 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved22(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved22_SHIFT)) & PORT_EDIER_Reserved22_MASK)

#define PORT_EDIER_Reserved23_MASK               (0x800000U)
#define PORT_EDIER_Reserved23_SHIFT              (23U)
/*! Reserved23 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved23(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved23_SHIFT)) & PORT_EDIER_Reserved23_MASK)

#define PORT_EDIER_Reserved24_MASK               (0x1000000U)
#define PORT_EDIER_Reserved24_SHIFT              (24U)
/*! Reserved24 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved24(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved24_SHIFT)) & PORT_EDIER_Reserved24_MASK)

#define PORT_EDIER_Reserved25_MASK               (0x2000000U)
#define PORT_EDIER_Reserved25_SHIFT              (25U)
/*! Reserved25 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved25(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved25_SHIFT)) & PORT_EDIER_Reserved25_MASK)

#define PORT_EDIER_Reserved26_MASK               (0x4000000U)
#define PORT_EDIER_Reserved26_SHIFT              (26U)
/*! Reserved26 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved26(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved26_SHIFT)) & PORT_EDIER_Reserved26_MASK)

#define PORT_EDIER_Reserved27_MASK               (0x8000000U)
#define PORT_EDIER_Reserved27_SHIFT              (27U)
/*! Reserved27 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved27(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved27_SHIFT)) & PORT_EDIER_Reserved27_MASK)

#define PORT_EDIER_Reserved28_MASK               (0x10000000U)
#define PORT_EDIER_Reserved28_SHIFT              (28U)
/*! Reserved28 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved28(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved28_SHIFT)) & PORT_EDIER_Reserved28_MASK)

#define PORT_EDIER_Reserved29_MASK               (0x20000000U)
#define PORT_EDIER_Reserved29_SHIFT              (29U)
/*! Reserved29 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved29(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved29_SHIFT)) & PORT_EDIER_Reserved29_MASK)

#define PORT_EDIER_Reserved30_MASK               (0x40000000U)
#define PORT_EDIER_Reserved30_SHIFT              (30U)
/*! Reserved30 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved30(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved30_SHIFT)) & PORT_EDIER_Reserved30_MASK)

#define PORT_EDIER_Reserved31_MASK               (0x80000000U)
#define PORT_EDIER_Reserved31_SHIFT              (31U)
/*! Reserved31 - Reserved
 *  0b0..Not supported
 *  0b1..Not supported
 */
#define PORT_EDIER_Reserved31(x)                 (((uint32_t)(((uint32_t)(x)) << PORT_EDIER_Reserved31_SHIFT)) & PORT_EDIER_Reserved31_MASK)
/*! @} */

/*! @name EDCR - EFT Detect Clear */
/*! @{ */

#define PORT_EDCR_EDHC_MASK                      (0x1U)
#define PORT_EDCR_EDHC_SHIFT                     (0U)
/*! EDHC - EFT Detect High Clear
 *  0b0..Does not clear
 *  0b1..Clears
 */
#define PORT_EDCR_EDHC(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDCR_EDHC_SHIFT)) & PORT_EDCR_EDHC_MASK)

#define PORT_EDCR_EDLC_MASK                      (0x2U)
#define PORT_EDCR_EDLC_SHIFT                     (1U)
/*! EDLC - EFT Detect Low Clear
 *  0b0..Does not clear
 *  0b1..Clears
 */
#define PORT_EDCR_EDLC(x)                        (((uint32_t)(((uint32_t)(x)) << PORT_EDCR_EDLC_SHIFT)) & PORT_EDCR_EDLC_MASK)
/*! @} */

/*! @name PCR - Pin Control 0..Pin Control 22 */
/*! @{ */

#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
/*! PS - Pull Select
 *  0b0..Enables internal pulldown resistor
 *  0b1..Enables internal pullup resistor
 */
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)

#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
/*! PE - Pull Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)

#define PORT_PCR_PV_MASK                         (0x4U)
#define PORT_PCR_PV_SHIFT                        (2U)
/*! PV - Pull Value
 *  0b0..Low
 *  0b1..High
 */
#define PORT_PCR_PV(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PV_SHIFT)) & PORT_PCR_PV_MASK)

#define PORT_PCR_SRE_MASK                        (0x8U)
#define PORT_PCR_SRE_SHIFT                       (3U)
/*! SRE - Slew Rate Enable
 *  0b0..Fast
 *  0b1..Slow
 */
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)

#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
/*! PFE - Passive Filter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)

#define PORT_PCR_ODE_MASK                        (0x20U)
#define PORT_PCR_ODE_SHIFT                       (5U)
/*! ODE - Open Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PORT_PCR_ODE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ODE_SHIFT)) & PORT_PCR_ODE_MASK)

#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
/*! DSE - Drive Strength Enable
 *  0b0..Low
 *  0b1..High
 */
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)

#define PORT_PCR_DSE1_MASK                       (0x80U)
#define PORT_PCR_DSE1_SHIFT                      (7U)
/*! DSE1 - Drive Strength Enable
 *  0b0..Normal
 *  0b1..Double
 */
#define PORT_PCR_DSE1(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE1_SHIFT)) & PORT_PCR_DSE1_MASK)

#define PORT_PCR_MUX_MASK                        (0xF00U)
#define PORT_PCR_MUX_SHIFT                       (8U)
/*! MUX - Pin Multiplex Control
 *  0b0000..Pin disabled (analog)
 *  0b0001..Alternative 1 (GPIO)
 *  0b0010..Alternative 2 (chip-specific)
 *  0b0011..Alternative 3 (chip-specific)
 *  0b0100..Alternative 4 (chip-specific)
 *  0b0101..Alternative 5 (chip-specific)
 *  0b0110..Alternative 6 (chip-specific)
 *  0b0111..Alternative 7 (chip-specific)
 *  0b1000..Alternative 8 (chip-specific)
 *  0b1001..Alternative 9 (chip-specific)
 *  0b1010..Alternative 10 (chip-specific)
 *  0b1011..Alternative 11 (chip-specific)
 */
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)

#define PORT_PCR_LK_MASK                         (0x8000U)
#define PORT_PCR_LK_SHIFT                        (15U)
/*! LK - Lock Register
 *  0b0..Locks
 *  0b1..Does not lock
 */
#define PORT_PCR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_LK_SHIFT)) & PORT_PCR_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


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


#endif  /* PORT_H_ */

