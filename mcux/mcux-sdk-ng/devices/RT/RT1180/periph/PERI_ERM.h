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
**         CMSIS Peripheral Access Layer for ERM
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
 * @file PERI_ERM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ERM
 *
 * CMSIS Peripheral Access Layer for ERM
 */

#if !defined(PERI_ERM_H_)
#define PERI_ERM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Peripheral_Access_Layer ERM Peripheral Access Layer
 * @{
 */

/** ERM - Size of Registers Arrays */
#define ERM_CORR_ERR_CNT_COUNT                    4u

/** ERM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< ERM Configuration Register 0, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SR0;                               /**< ERM Status Register 0, offset: 0x10 */
       uint8_t RESERVED_1[244];
  struct {                                         /* offset: 0x108, array step: 0x10 */
    __IO uint32_t CORR_ERR;                          /**< ERM Memory 0 Correctable Error Count Register..ERM Memory 3 Correctable Error Count Register, array offset: 0x108, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } CORR_ERR_CNT[ERM_CORR_ERR_CNT_COUNT];
} ERM_Type;

/* ----------------------------------------------------------------------------
   -- ERM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Register_Masks ERM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define ERM_CR0_ENCIE3_MASK                      (0x40000U)
#define ERM_CR0_ENCIE3_SHIFT                     (18U)
/*! ENCIE3 - ENCIE3
 *  0b0..Interrupt notification of Memory 3 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 3 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE3(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE3_SHIFT)) & ERM_CR0_ENCIE3_MASK)

#define ERM_CR0_ESCIE3_MASK                      (0x80000U)
#define ERM_CR0_ESCIE3_SHIFT                     (19U)
/*! ESCIE3 - ESCIE3
 *  0b0..Interrupt notification of Memory 3 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 3 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE3(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE3_SHIFT)) & ERM_CR0_ESCIE3_MASK)

#define ERM_CR0_ENCIE2_MASK                      (0x400000U)
#define ERM_CR0_ENCIE2_SHIFT                     (22U)
/*! ENCIE2 - ENCIE2
 *  0b0..Interrupt notification of Memory 2 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 2 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE2(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE2_SHIFT)) & ERM_CR0_ENCIE2_MASK)

#define ERM_CR0_ESCIE2_MASK                      (0x800000U)
#define ERM_CR0_ESCIE2_SHIFT                     (23U)
/*! ESCIE2 - ESCIE2
 *  0b0..Interrupt notification of Memory 2 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 2 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE2(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE2_SHIFT)) & ERM_CR0_ESCIE2_MASK)

#define ERM_CR0_ENCIE1_MASK                      (0x4000000U)
#define ERM_CR0_ENCIE1_SHIFT                     (26U)
/*! ENCIE1 - ENCIE1
 *  0b0..Interrupt notification of Memory 1 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 1 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE1(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE1_SHIFT)) & ERM_CR0_ENCIE1_MASK)

#define ERM_CR0_ESCIE1_MASK                      (0x8000000U)
#define ERM_CR0_ESCIE1_SHIFT                     (27U)
/*! ESCIE1 - ESCIE1
 *  0b0..Interrupt notification of Memory 1 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 1 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE1(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE1_SHIFT)) & ERM_CR0_ESCIE1_MASK)

#define ERM_CR0_ENCIE0_MASK                      (0x40000000U)
#define ERM_CR0_ENCIE0_SHIFT                     (30U)
/*! ENCIE0 - ENCIE0
 *  0b0..Interrupt notification of Memory 0 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 0 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE0_SHIFT)) & ERM_CR0_ENCIE0_MASK)

#define ERM_CR0_ESCIE0_MASK                      (0x80000000U)
#define ERM_CR0_ESCIE0_SHIFT                     (31U)
/*! ESCIE0 - ESCIE0
 *  0b0..Interrupt notification of Memory 0 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 0 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE0_SHIFT)) & ERM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define ERM_SR0_NCE3_MASK                        (0x40000U)
#define ERM_SR0_NCE3_SHIFT                       (18U)
/*! NCE3 - NCE3
 *  0b0..No non-correctable error event on Memory 3 detected.
 *  0b1..Non-correctable error event on Memory 3 detected.
 */
#define ERM_SR0_NCE3(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE3_SHIFT)) & ERM_SR0_NCE3_MASK)

#define ERM_SR0_SBC3_MASK                        (0x80000U)
#define ERM_SR0_SBC3_SHIFT                       (19U)
/*! SBC3 - SBC3
 *  0b0..No single-bit correction event on Memory 3 detected.
 *  0b1..Single-bit correction event on Memory 3 detected.
 */
#define ERM_SR0_SBC3(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC3_SHIFT)) & ERM_SR0_SBC3_MASK)

#define ERM_SR0_NCE2_MASK                        (0x400000U)
#define ERM_SR0_NCE2_SHIFT                       (22U)
/*! NCE2 - NCE2
 *  0b0..No non-correctable error event on Memory 2 detected.
 *  0b1..Non-correctable error event on Memory 2 detected.
 */
#define ERM_SR0_NCE2(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE2_SHIFT)) & ERM_SR0_NCE2_MASK)

#define ERM_SR0_SBC2_MASK                        (0x800000U)
#define ERM_SR0_SBC2_SHIFT                       (23U)
/*! SBC2 - SBC2
 *  0b0..No single-bit correction event on Memory 2 detected.
 *  0b1..Single-bit correction event on Memory 2 detected.
 */
#define ERM_SR0_SBC2(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC2_SHIFT)) & ERM_SR0_SBC2_MASK)

#define ERM_SR0_NCE1_MASK                        (0x4000000U)
#define ERM_SR0_NCE1_SHIFT                       (26U)
/*! NCE1 - NCE1
 *  0b0..No non-correctable error event on Memory 1 detected.
 *  0b1..Non-correctable error event on Memory 1 detected.
 */
#define ERM_SR0_NCE1(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE1_SHIFT)) & ERM_SR0_NCE1_MASK)

#define ERM_SR0_SBC1_MASK                        (0x8000000U)
#define ERM_SR0_SBC1_SHIFT                       (27U)
/*! SBC1 - SBC1
 *  0b0..No single-bit correction event on Memory 1 detected.
 *  0b1..Single-bit correction event on Memory 1 detected.
 */
#define ERM_SR0_SBC1(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC1_SHIFT)) & ERM_SR0_SBC1_MASK)

#define ERM_SR0_NCE0_MASK                        (0x40000000U)
#define ERM_SR0_NCE0_SHIFT                       (30U)
/*! NCE0 - NCE0
 *  0b0..No non-correctable error event on Memory 0 detected.
 *  0b1..Non-correctable error event on Memory 0 detected.
 */
#define ERM_SR0_NCE0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE0_SHIFT)) & ERM_SR0_NCE0_MASK)

#define ERM_SR0_SBC0_MASK                        (0x80000000U)
#define ERM_SR0_SBC0_SHIFT                       (31U)
/*! SBC0 - SBC0
 *  0b0..No single-bit correction event on Memory 0 detected.
 *  0b1..Single-bit correction event on Memory 0 detected.
 */
#define ERM_SR0_SBC0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC0_SHIFT)) & ERM_SR0_SBC0_MASK)
/*! @} */

/*! @name CORR_ERR - ERM Memory 0 Correctable Error Count Register..ERM Memory 3 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_COUNT_MASK                  (0xFFU)
#define ERM_CORR_ERR_COUNT_SHIFT                 (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_COUNT(x)                    (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_COUNT_SHIFT)) & ERM_CORR_ERR_COUNT_MASK)
/*! @} */

/* The count of ERM_CORR_ERR */
#define ERM_CORR_ERR_CNT_CORR_ERR_COUNT          (4U)


/*!
 * @}
 */ /* end of group ERM_Register_Masks */


/*!
 * @}
 */ /* end of group ERM_Peripheral_Access_Layer */


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


#endif  /* PERI_ERM_H_ */

