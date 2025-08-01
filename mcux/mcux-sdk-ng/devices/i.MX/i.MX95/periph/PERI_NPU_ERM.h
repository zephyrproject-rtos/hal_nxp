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
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NPU_ERM
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
**
** ###################################################################
*/

/*!
 * @file NPU_ERM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NPU_ERM
 *
 * CMSIS Peripheral Access Layer for NPU_ERM
 */

#if !defined(NPU_ERM_H_)
#define NPU_ERM_H_                               /**< Symbol preventing repeated inclusion */

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
   -- NPU_ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_ERM_Peripheral_Access_Layer NPU_ERM Peripheral Access Layer
 * @{
 */

/** NPU_ERM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< ERM Configuration Register 0, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SR0;                               /**< ERM Status Register 0, offset: 0x10 */
       uint8_t RESERVED_1[236];
  __I  uint32_t EAR0;                              /**< ERM Memory 0 Error Address Register, offset: 0x100 */
  __I  uint32_t SYN0;                              /**< ERM Memory 0 Syndrome Register, offset: 0x104 */
  __IO uint32_t CORR_ERR_CNT0;                     /**< ERM Memory 0 Correctable Error Count Register, offset: 0x108 */
} NPU_ERM_Type;

/* ----------------------------------------------------------------------------
   -- NPU_ERM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_ERM_Register_Masks NPU_ERM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define NPU_ERM_CR0_ENCIE0_MASK                  (0x40000000U)
#define NPU_ERM_CR0_ENCIE0_SHIFT                 (30U)
/*! ENCIE0 - ENCIE0
 *  0b0..Interrupt notification of Memory 0 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 0 non-correctable error events is enabled.
 */
#define NPU_ERM_CR0_ENCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ERM_CR0_ENCIE0_SHIFT)) & NPU_ERM_CR0_ENCIE0_MASK)

#define NPU_ERM_CR0_ESCIE0_MASK                  (0x80000000U)
#define NPU_ERM_CR0_ESCIE0_SHIFT                 (31U)
/*! ESCIE0 - ESCIE0
 *  0b0..Interrupt notification of Memory 0 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 0 single-bit correction events is enabled.
 */
#define NPU_ERM_CR0_ESCIE0(x)                    (((uint32_t)(((uint32_t)(x)) << NPU_ERM_CR0_ESCIE0_SHIFT)) & NPU_ERM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define NPU_ERM_SR0_NCE0_MASK                    (0x40000000U)
#define NPU_ERM_SR0_NCE0_SHIFT                   (30U)
/*! NCE0 - NCE0
 *  0b0..No non-correctable error event on Memory 0 detected.
 *  0b1..Non-correctable error event on Memory 0 detected.
 */
#define NPU_ERM_SR0_NCE0(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_ERM_SR0_NCE0_SHIFT)) & NPU_ERM_SR0_NCE0_MASK)

#define NPU_ERM_SR0_SBC0_MASK                    (0x80000000U)
#define NPU_ERM_SR0_SBC0_SHIFT                   (31U)
/*! SBC0 - SBC0
 *  0b0..No single-bit correction event on Memory 0 detected.
 *  0b1..Single-bit correction event on Memory 0 detected.
 */
#define NPU_ERM_SR0_SBC0(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_ERM_SR0_SBC0_SHIFT)) & NPU_ERM_SR0_SBC0_MASK)
/*! @} */

/*! @name EAR0 - ERM Memory 0 Error Address Register */
/*! @{ */

#define NPU_ERM_EAR0_EAR_MASK                    (0xFFFFFFFFU)
#define NPU_ERM_EAR0_EAR_SHIFT                   (0U)
/*! EAR - EAR */
#define NPU_ERM_EAR0_EAR(x)                      (((uint32_t)(((uint32_t)(x)) << NPU_ERM_EAR0_EAR_SHIFT)) & NPU_ERM_EAR0_EAR_MASK)
/*! @} */

/*! @name SYN0 - ERM Memory 0 Syndrome Register */
/*! @{ */

#define NPU_ERM_SYN0_SYNDROME_MASK               (0xFF000000U)
#define NPU_ERM_SYN0_SYNDROME_SHIFT              (24U)
/*! SYNDROME - SYNDROME */
#define NPU_ERM_SYN0_SYNDROME(x)                 (((uint32_t)(((uint32_t)(x)) << NPU_ERM_SYN0_SYNDROME_SHIFT)) & NPU_ERM_SYN0_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT0 - ERM Memory 0 Correctable Error Count Register */
/*! @{ */

#define NPU_ERM_CORR_ERR_CNT0_COUNT_MASK         (0xFFU)
#define NPU_ERM_CORR_ERR_CNT0_COUNT_SHIFT        (0U)
/*! COUNT - Memory n Correctable Error Count */
#define NPU_ERM_CORR_ERR_CNT0_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << NPU_ERM_CORR_ERR_CNT0_COUNT_SHIFT)) & NPU_ERM_CORR_ERR_CNT0_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_ERM_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_ERM_Peripheral_Access_Layer */


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


#endif  /* NPU_ERM_H_ */

