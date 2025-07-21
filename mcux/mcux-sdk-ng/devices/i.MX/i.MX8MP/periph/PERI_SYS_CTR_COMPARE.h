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
**         CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
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
 * @file PERI_SYS_CTR_COMPARE.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 */

#if !defined(PERI_SYS_CTR_COMPARE_H_)
#define PERI_SYS_CTR_COMPARE_H_                  /**< Symbol preventing repeated inclusion */

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
   -- SYS_CTR_COMPARE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Peripheral_Access_Layer SYS_CTR_COMPARE Peripheral Access Layer
 * @{
 */

/** SYS_CTR_COMPARE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __I  uint32_t CMPCVL0;                           /**< Compare Count Value Low Register, offset: 0x20 */
  __I  uint32_t CMPCVH0;                           /**< Compare Count Value High Register, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMPCR0;                            /**< Compare Control Register, offset: 0x2C */
       uint8_t RESERVED_2[240];
  __I  uint32_t CMPCVL1;                           /**< Compare Count Value Low Register, offset: 0x120 */
  __I  uint32_t CMPCVH1;                           /**< Compare Count Value High Register, offset: 0x124 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CMPCR;                             /**< Compare Control Register, offset: 0x12C */
       uint8_t RESERVED_4[3744];
  __I  uint32_t CNTID0;                            /**< Counter ID Register, offset: 0xFD0 */
} SYS_CTR_COMPARE_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_COMPARE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Register_Masks SYS_CTR_COMPARE Register Masks
 * @{
 */

/*! @name CMPCVL0 - Compare Count Value Low Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT     (0U)
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH0 - Compare Count Value High Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK      (0x1FFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT     (0U)
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR0 - Compare Control Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR0_EN_MASK           (0x1U)
#define SYS_CTR_COMPARE_CMPCR0_EN_SHIFT          (0U)
/*! EN
 *  0b0..Compare disabled
 *  0b1..Compare enabled
 */
#define SYS_CTR_COMPARE_CMPCR0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR0_IMASK_MASK        (0x2U)
#define SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT       (1U)
/*! IMASK
 *  0b0..Interrupt output signal is not masked.
 *  0b1..Interrupt output signal is masked.
 */
#define SYS_CTR_COMPARE_CMPCR0_IMASK(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK        (0x4U)
#define SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT       (2U)
/*! ISTAT
 *  0b0..Counter value is less than the compare value or compare is disabled.
 *  0b1..Counter value is greater than or equal to the compare value and compare is enabled.
 */
#define SYS_CTR_COMPARE_CMPCR0_ISTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK)
/*! @} */

/*! @name CMPCVL1 - Compare Count Value Low Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT     (0U)
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH1 - Compare Count Value High Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK      (0x1FFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT     (0U)
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR - Compare Control Register */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR_EN_MASK            (0x1U)
#define SYS_CTR_COMPARE_CMPCR_EN_SHIFT           (0U)
/*! EN
 *  0b0..Compare disabled
 *  0b1..Compare enabled
 */
#define SYS_CTR_COMPARE_CMPCR_EN(x)              (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR_IMASK_MASK         (0x2U)
#define SYS_CTR_COMPARE_CMPCR_IMASK_SHIFT        (1U)
/*! IMASK
 *  0b0..Interrupt output signal is not masked.
 *  0b1..Interrupt output signal is masked.
 */
#define SYS_CTR_COMPARE_CMPCR_IMASK(x)           (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR_ISTAT_MASK         (0x4U)
#define SYS_CTR_COMPARE_CMPCR_ISTAT_SHIFT        (2U)
/*! ISTAT
 *  0b0..Counter value is less than the compare value or compare is disabled.
 *  0b1..Counter value is greater than or equal to the compare value and compare is enabled.
 */
#define SYS_CTR_COMPARE_CMPCR_ISTAT(x)           (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR_ISTAT_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID Register */
/*! @{ */

#define SYS_CTR_COMPARE_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT       (0U)
#define SYS_CTR_COMPARE_CNTID0_CNTID(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT)) & SYS_CTR_COMPARE_CNTID0_CNTID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Register_Masks */


/*!
 * @}
 */ /* end of group SYS_CTR_COMPARE_Peripheral_Access_Layer */


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


#endif  /* PERI_SYS_CTR_COMPARE_H_ */

