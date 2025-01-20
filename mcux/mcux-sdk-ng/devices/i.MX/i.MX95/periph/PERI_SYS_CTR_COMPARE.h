/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file SYS_CTR_COMPARE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_COMPARE
 */

#if !defined(SYS_CTR_COMPARE_H_)
#define SYS_CTR_COMPARE_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- SYS_CTR_COMPARE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Peripheral_Access_Layer SYS_CTR_COMPARE Peripheral Access Layer
 * @{
 */

/** SYS_CTR_COMPARE - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t CMPCVL0;                           /**< Compare Count Value Low, offset: 0x20 */
  __IO uint32_t CMPCVH0;                           /**< Compare Count Value High, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CMPCR0;                            /**< Compare Control, offset: 0x2C */
       uint8_t RESERVED_2[240];
  __IO uint32_t CMPCVL1;                           /**< Compare Count Value Low, offset: 0x120 */
  __IO uint32_t CMPCVH1;                           /**< Compare Count Value High, offset: 0x124 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CMPCR1;                            /**< Compare Control, offset: 0x12C */
       uint8_t RESERVED_4[3744];
  __I  uint32_t CNTID0;                            /**< Counter ID, offset: 0xFD0 */
} SYS_CTR_COMPARE_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_COMPARE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_COMPARE_Register_Masks SYS_CTR_COMPARE Register Masks
 * @{
 */

/*! @name CMPCVL0 - Compare Count Value Low */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT     (0U)
/*! CMPCV0 - Compare Count Value Bits [31:0] */
#define SYS_CTR_COMPARE_CMPCVL0_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL0_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL0_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH0 - Compare Count Value High */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK      (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT     (0U)
/*! CMPCV1 - Compare Count Value Bits [55:32] */
#define SYS_CTR_COMPARE_CMPCVH0_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH0_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH0_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR0 - Compare Control */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR0_EN_MASK           (0x1U)
#define SYS_CTR_COMPARE_CMPCR0_EN_SHIFT          (0U)
/*! EN - Compare Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_COMPARE_CMPCR0_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR0_IMASK_MASK        (0x2U)
#define SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT       (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define SYS_CTR_COMPARE_CMPCR0_IMASK(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK        (0x4U)
#define SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT       (2U)
/*! ISTAT - Compare Interrupt Status
 *  0b0..Either less than the compare value or compare is disabled
 *  0b1..Greater than or equal to the compare value and compare is enabled
 */
#define SYS_CTR_COMPARE_CMPCR0_ISTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR0_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR0_ISTAT_MASK)
/*! @} */

/*! @name CMPCVL1 - Compare Count Value Low */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK      (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT     (0U)
/*! CMPCV0 - Compare Count Value Bits [31:0] */
#define SYS_CTR_COMPARE_CMPCVL1_CMPCV0(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVL1_CMPCV0_SHIFT)) & SYS_CTR_COMPARE_CMPCVL1_CMPCV0_MASK)
/*! @} */

/*! @name CMPCVH1 - Compare Count Value High */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK      (0xFFFFFFU)
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT     (0U)
/*! CMPCV1 - Compare Count Value Bits [55:32] */
#define SYS_CTR_COMPARE_CMPCVH1_CMPCV1(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCVH1_CMPCV1_SHIFT)) & SYS_CTR_COMPARE_CMPCVH1_CMPCV1_MASK)
/*! @} */

/*! @name CMPCR1 - Compare Control */
/*! @{ */

#define SYS_CTR_COMPARE_CMPCR1_EN_MASK           (0x1U)
#define SYS_CTR_COMPARE_CMPCR1_EN_SHIFT          (0U)
/*! EN - Compare Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_COMPARE_CMPCR1_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_EN_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_EN_MASK)

#define SYS_CTR_COMPARE_CMPCR1_IMASK_MASK        (0x2U)
#define SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT       (1U)
/*! IMASK - Interrupt Request Mask
 *  0b0..Not masked
 *  0b1..Masked
 */
#define SYS_CTR_COMPARE_CMPCR1_IMASK(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_IMASK_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_IMASK_MASK)

#define SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK        (0x4U)
#define SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT       (2U)
/*! ISTAT - Compare Interrupt Status
 *  0b0..Either less than the compare value or compare is disabled
 *  0b1..Greater than or equal to the compare value and compare is enabled
 */
#define SYS_CTR_COMPARE_CMPCR1_ISTAT(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_COMPARE_CMPCR1_ISTAT_SHIFT)) & SYS_CTR_COMPARE_CMPCR1_ISTAT_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID */
/*! @{ */

#define SYS_CTR_COMPARE_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_COMPARE_CNTID0_CNTID_SHIFT       (0U)
/*! CNTID - Counter Identification */
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* SYS_CTR_COMPARE_H_ */

