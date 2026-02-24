/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for filter
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_filter.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for filter
 *
 * CMSIS Peripheral Access Layer for filter
 */

#if !defined(PERI_FILTER_H_)
#define PERI_FILTER_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- filter Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup filter_Peripheral_Access_Layer filter Peripheral Access Layer
 * @{
 */

/** filter - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t FIRCON;                            /**< FIR_control, offset: 0x10 */
  __IO uint32_t COEFF0;                            /**< Coefficients0, offset: 0x14 */
  __IO uint32_t COEFF1;                            /**< Coefficients1, offset: 0x18 */
  __IO uint32_t COEFF2;                            /**< Coefficients2, offset: 0x1C */
  __IO uint32_t COEFF3;                            /**< Coefficients3, offset: 0x20 */
  __IO uint32_t COEFF4;                            /**< Coefficients4, offset: 0x24 */
  __IO uint32_t COEFF5;                            /**< Coefficients5, offset: 0x28 */
  __IO uint32_t COEFF6;                            /**< Coefficients6, offset: 0x2C */
} filter_Type;

/* ----------------------------------------------------------------------------
   -- filter Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup filter_Register_Masks filter Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define filter_LU_LkUn_MASK                      (0xFFFFFFFFU)
#define filter_LU_LkUn_SHIFT                     (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define filter_LU_LkUn(x)                        (((uint32_t)(((uint32_t)(x)) << filter_LU_LkUn_SHIFT)) & filter_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define filter_LOCKS_LkSus_MASK                  (0x1U)
#define filter_LOCKS_LkSus_SHIFT                 (0U)
/*! LkSus - LockStatus */
#define filter_LOCKS_LkSus(x)                    (((uint32_t)(((uint32_t)(x)) << filter_LOCKS_LkSus_SHIFT)) & filter_LOCKS_LkSus_MASK)

#define filter_LOCKS_PriSt_MASK                  (0x10U)
#define filter_LOCKS_PriSt_SHIFT                 (4U)
/*! PriSt - PrivilegeStatus */
#define filter_LOCKS_PriSt(x)                    (((uint32_t)(((uint32_t)(x)) << filter_LOCKS_PriSt_SHIFT)) & filter_LOCKS_PriSt_MASK)

#define filter_LOCKS_FreezeS_MASK                (0x100U)
#define filter_LOCKS_FreezeS_SHIFT               (8U)
/*! FreezeS - FreezeStatus */
#define filter_LOCKS_FreezeS(x)                  (((uint32_t)(((uint32_t)(x)) << filter_LOCKS_FreezeS_SHIFT)) & filter_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define filter_STATCON_ShdEn_MASK                (0x1U)
#define filter_STATCON_ShdEn_SHIFT               (0U)
/*! ShdEn - ShdEn */
#define filter_STATCON_ShdEn(x)                  (((uint32_t)(((uint32_t)(x)) << filter_STATCON_ShdEn_SHIFT)) & filter_STATCON_ShdEn_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define filter_CONTR_mode_MASK                   (0x1U)
#define filter_CONTR_mode_SHIFT                  (0U)
/*! mode - mode
 *  0b0..Neutral mode. Pixels by-pass the filter, all other settings are ignored.
 *  0b1..Filter is active.
 */
#define filter_CONTR_mode(x)                     (((uint32_t)(((uint32_t)(x)) << filter_CONTR_mode_SHIFT)) & filter_CONTR_mode_MASK)

#define filter_CONTR_tilemode_MASK               (0x30U)
#define filter_CONTR_tilemode_SHIFT              (4U)
/*! tilemode - tile_mode
 *  0b00..Samples outside the frame are padded with the last valid border pixels.
 *  0b01..Samples outside the frame are treated as zero pixel value.
 *  0b10..Applies tile mode PAD to RGB channels and tile mode ZERO to alpha channel.
 */
#define filter_CONTR_tilemode(x)                 (((uint32_t)(((uint32_t)(x)) << filter_CONTR_tilemode_SHIFT)) & filter_CONTR_tilemode_MASK)

#define filter_CONTR_filmode_MASK                (0xFFFF00U)
#define filter_CONTR_filmode_SHIFT               (8U)
/*! filmode - filter_mode
 *  0b0000000001010101..FIR filter 5x5 window.
 */
#define filter_CONTR_filmode(x)                  (((uint32_t)(((uint32_t)(x)) << filter_CONTR_filmode_SHIFT)) & filter_CONTR_filmode_MASK)

#define filter_CONTR_buffor_MASK                 (0x30000000U)
#define filter_CONTR_buffor_SHIFT                (28U)
/*! buffor - buffer_format
 *  0b00..RGB888 format. Alpha is not filtered but set to constant value 255.
 *  0b01..RGBA5658 format. Alpha is filtered.
 *  0b10..RGBA8888 format. Alpha is filtered. The filter window is limited to 5x4.
 *  0b11..RGBA10.10.10.8 format. Alpha is filtered. The filter window is limited to 5x3.
 */
#define filter_CONTR_buffor(x)                   (((uint32_t)(((uint32_t)(x)) << filter_CONTR_buffor_SHIFT)) & filter_CONTR_buffor_MASK)
/*! @} */

/*! @name FIRCON - FIR_control */
/*! @{ */

#define filter_FIRCON_FIRcomps_MASK              (0xFU)
#define filter_FIRCON_FIRcomps_SHIFT             (0U)
/*! FIRcomps - FIR_component_select */
#define filter_FIRCON_FIRcomps(x)                (((uint32_t)(((uint32_t)(x)) << filter_FIRCON_FIRcomps_SHIFT)) & filter_FIRCON_FIRcomps_MASK)

#define filter_FIRCON_FIRexpon_MASK              (0xF00U)
#define filter_FIRCON_FIRexpon_SHIFT             (8U)
/*! FIRexpon - FIR_exponent */
#define filter_FIRCON_FIRexpon(x)                (((uint32_t)(((uint32_t)(x)) << filter_FIRCON_FIRexpon_SHIFT)) & filter_FIRCON_FIRexpon_MASK)
/*! @} */

/*! @name COEFF0 - Coefficients0 */
/*! @{ */

#define filter_COEFF0_coeff00_MASK               (0xFFU)
#define filter_COEFF0_coeff00_SHIFT              (0U)
/*! coeff00 - coeff0_0 */
#define filter_COEFF0_coeff00(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF0_coeff00_SHIFT)) & filter_COEFF0_coeff00_MASK)

#define filter_COEFF0_coeff10_MASK               (0xFF00U)
#define filter_COEFF0_coeff10_SHIFT              (8U)
/*! coeff10 - coeff1_0 */
#define filter_COEFF0_coeff10(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF0_coeff10_SHIFT)) & filter_COEFF0_coeff10_MASK)

#define filter_COEFF0_coeff20_MASK               (0xFF0000U)
#define filter_COEFF0_coeff20_SHIFT              (16U)
/*! coeff20 - coeff2_0 */
#define filter_COEFF0_coeff20(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF0_coeff20_SHIFT)) & filter_COEFF0_coeff20_MASK)

#define filter_COEFF0_coeff30_MASK               (0xFF000000U)
#define filter_COEFF0_coeff30_SHIFT              (24U)
/*! coeff30 - coeff3_0 */
#define filter_COEFF0_coeff30(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF0_coeff30_SHIFT)) & filter_COEFF0_coeff30_MASK)
/*! @} */

/*! @name COEFF1 - Coefficients1 */
/*! @{ */

#define filter_COEFF1_coeff40_MASK               (0xFFU)
#define filter_COEFF1_coeff40_SHIFT              (0U)
/*! coeff40 - coeff4_0 */
#define filter_COEFF1_coeff40(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF1_coeff40_SHIFT)) & filter_COEFF1_coeff40_MASK)

#define filter_COEFF1_coeff01_MASK               (0xFF00U)
#define filter_COEFF1_coeff01_SHIFT              (8U)
/*! coeff01 - coeff0_1 */
#define filter_COEFF1_coeff01(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF1_coeff01_SHIFT)) & filter_COEFF1_coeff01_MASK)

#define filter_COEFF1_coeff11_MASK               (0xFF0000U)
#define filter_COEFF1_coeff11_SHIFT              (16U)
/*! coeff11 - coeff1_1 */
#define filter_COEFF1_coeff11(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF1_coeff11_SHIFT)) & filter_COEFF1_coeff11_MASK)

#define filter_COEFF1_coeff21_MASK               (0xFF000000U)
#define filter_COEFF1_coeff21_SHIFT              (24U)
/*! coeff21 - coeff2_1 */
#define filter_COEFF1_coeff21(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF1_coeff21_SHIFT)) & filter_COEFF1_coeff21_MASK)
/*! @} */

/*! @name COEFF2 - Coefficients2 */
/*! @{ */

#define filter_COEFF2_coeff31_MASK               (0xFFU)
#define filter_COEFF2_coeff31_SHIFT              (0U)
/*! coeff31 - coeff3_1 */
#define filter_COEFF2_coeff31(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF2_coeff31_SHIFT)) & filter_COEFF2_coeff31_MASK)

#define filter_COEFF2_coeff41_MASK               (0xFF00U)
#define filter_COEFF2_coeff41_SHIFT              (8U)
/*! coeff41 - coeff4_1 */
#define filter_COEFF2_coeff41(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF2_coeff41_SHIFT)) & filter_COEFF2_coeff41_MASK)

#define filter_COEFF2_coeff02_MASK               (0xFF0000U)
#define filter_COEFF2_coeff02_SHIFT              (16U)
/*! coeff02 - coeff0_2 */
#define filter_COEFF2_coeff02(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF2_coeff02_SHIFT)) & filter_COEFF2_coeff02_MASK)

#define filter_COEFF2_coeff12_MASK               (0xFF000000U)
#define filter_COEFF2_coeff12_SHIFT              (24U)
/*! coeff12 - coeff1_2 */
#define filter_COEFF2_coeff12(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF2_coeff12_SHIFT)) & filter_COEFF2_coeff12_MASK)
/*! @} */

/*! @name COEFF3 - Coefficients3 */
/*! @{ */

#define filter_COEFF3_coeff22_MASK               (0xFFU)
#define filter_COEFF3_coeff22_SHIFT              (0U)
/*! coeff22 - coeff2_2 */
#define filter_COEFF3_coeff22(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF3_coeff22_SHIFT)) & filter_COEFF3_coeff22_MASK)

#define filter_COEFF3_coeff32_MASK               (0xFF00U)
#define filter_COEFF3_coeff32_SHIFT              (8U)
/*! coeff32 - coeff3_2 */
#define filter_COEFF3_coeff32(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF3_coeff32_SHIFT)) & filter_COEFF3_coeff32_MASK)

#define filter_COEFF3_coeff42_MASK               (0xFF0000U)
#define filter_COEFF3_coeff42_SHIFT              (16U)
/*! coeff42 - coeff4_2 */
#define filter_COEFF3_coeff42(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF3_coeff42_SHIFT)) & filter_COEFF3_coeff42_MASK)

#define filter_COEFF3_coeff03_MASK               (0xFF000000U)
#define filter_COEFF3_coeff03_SHIFT              (24U)
/*! coeff03 - coeff0_3 */
#define filter_COEFF3_coeff03(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF3_coeff03_SHIFT)) & filter_COEFF3_coeff03_MASK)
/*! @} */

/*! @name COEFF4 - Coefficients4 */
/*! @{ */

#define filter_COEFF4_coeff13_MASK               (0xFFU)
#define filter_COEFF4_coeff13_SHIFT              (0U)
/*! coeff13 - coeff1_3 */
#define filter_COEFF4_coeff13(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF4_coeff13_SHIFT)) & filter_COEFF4_coeff13_MASK)

#define filter_COEFF4_coeff23_MASK               (0xFF00U)
#define filter_COEFF4_coeff23_SHIFT              (8U)
/*! coeff23 - coeff2_3 */
#define filter_COEFF4_coeff23(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF4_coeff23_SHIFT)) & filter_COEFF4_coeff23_MASK)

#define filter_COEFF4_coeff33_MASK               (0xFF0000U)
#define filter_COEFF4_coeff33_SHIFT              (16U)
/*! coeff33 - coeff3_3 */
#define filter_COEFF4_coeff33(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF4_coeff33_SHIFT)) & filter_COEFF4_coeff33_MASK)

#define filter_COEFF4_coeff43_MASK               (0xFF000000U)
#define filter_COEFF4_coeff43_SHIFT              (24U)
/*! coeff43 - coeff4_3 */
#define filter_COEFF4_coeff43(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF4_coeff43_SHIFT)) & filter_COEFF4_coeff43_MASK)
/*! @} */

/*! @name COEFF5 - Coefficients5 */
/*! @{ */

#define filter_COEFF5_coeff04_MASK               (0xFFU)
#define filter_COEFF5_coeff04_SHIFT              (0U)
/*! coeff04 - coeff0_4 */
#define filter_COEFF5_coeff04(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF5_coeff04_SHIFT)) & filter_COEFF5_coeff04_MASK)

#define filter_COEFF5_coeff14_MASK               (0xFF00U)
#define filter_COEFF5_coeff14_SHIFT              (8U)
/*! coeff14 - coeff1_4 */
#define filter_COEFF5_coeff14(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF5_coeff14_SHIFT)) & filter_COEFF5_coeff14_MASK)

#define filter_COEFF5_coeff24_MASK               (0xFF0000U)
#define filter_COEFF5_coeff24_SHIFT              (16U)
/*! coeff24 - coeff2_4 */
#define filter_COEFF5_coeff24(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF5_coeff24_SHIFT)) & filter_COEFF5_coeff24_MASK)

#define filter_COEFF5_coeff34_MASK               (0xFF000000U)
#define filter_COEFF5_coeff34_SHIFT              (24U)
/*! coeff34 - coeff3_4 */
#define filter_COEFF5_coeff34(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF5_coeff34_SHIFT)) & filter_COEFF5_coeff34_MASK)
/*! @} */

/*! @name COEFF6 - Coefficients6 */
/*! @{ */

#define filter_COEFF6_coeff44_MASK               (0xFFU)
#define filter_COEFF6_coeff44_SHIFT              (0U)
/*! coeff44 - coeff4_4 */
#define filter_COEFF6_coeff44(x)                 (((uint32_t)(((uint32_t)(x)) << filter_COEFF6_coeff44_SHIFT)) & filter_COEFF6_coeff44_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group filter_Register_Masks */


/*!
 * @}
 */ /* end of group filter_Peripheral_Access_Layer */


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


#endif  /* PERI_FILTER_H_ */

