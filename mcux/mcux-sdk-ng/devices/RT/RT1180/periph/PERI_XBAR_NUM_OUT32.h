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
**         CMSIS Peripheral Access Layer for XBAR_NUM_OUT32
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
 * @file PERI_XBAR_NUM_OUT32.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBAR_NUM_OUT32
 *
 * CMSIS Peripheral Access Layer for XBAR_NUM_OUT32
 */

#if !defined(PERI_XBAR_NUM_OUT32_H_)
#define PERI_XBAR_NUM_OUT32_H_                   /**< Symbol preventing repeated inclusion */

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
   -- XBAR_NUM_OUT32 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT32_Peripheral_Access_Layer XBAR_NUM_OUT32 Peripheral Access Layer
 * @{
 */

/** XBAR_NUM_OUT32 - Size of Registers Arrays */
#define XBAR_NUM_OUT32_SEL_COUNT                  16u

/** XBAR_NUM_OUT32 - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL[XBAR_NUM_OUT32_SEL_COUNT];     /**< Crossbar Select Register, array offset: 0x0, array step: 0x2 */
} XBAR_NUM_OUT32_Type;

/* ----------------------------------------------------------------------------
   -- XBAR_NUM_OUT32 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT32_Register_Masks XBAR_NUM_OUT32 Register Masks
 * @{
 */

/*! @name SEL - Crossbar Select Register */
/*! @{ */

#define XBAR_NUM_OUT32_SEL_SEL0_MASK             (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL0_SHIFT            (0U)
/*! SEL0 - SEL0 */
#define XBAR_NUM_OUT32_SEL_SEL0(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL0_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL0_MASK)

#define XBAR_NUM_OUT32_SEL_SEL2_MASK             (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL2_SHIFT            (0U)
/*! SEL2 - SEL2 */
#define XBAR_NUM_OUT32_SEL_SEL2(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL2_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL2_MASK)

#define XBAR_NUM_OUT32_SEL_SEL4_MASK             (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL4_SHIFT            (0U)
/*! SEL4 - SEL4 */
#define XBAR_NUM_OUT32_SEL_SEL4(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL4_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL4_MASK)

#define XBAR_NUM_OUT32_SEL_SEL6_MASK             (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL6_SHIFT            (0U)
/*! SEL6 - SEL6 */
#define XBAR_NUM_OUT32_SEL_SEL6(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL6_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL6_MASK)

#define XBAR_NUM_OUT32_SEL_SEL8_MASK             (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL8_SHIFT            (0U)
/*! SEL8 - SEL8 */
#define XBAR_NUM_OUT32_SEL_SEL8(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL8_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL8_MASK)

#define XBAR_NUM_OUT32_SEL_SEL10_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL10_SHIFT           (0U)
/*! SEL10 - SEL10 */
#define XBAR_NUM_OUT32_SEL_SEL10(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL10_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL10_MASK)

#define XBAR_NUM_OUT32_SEL_SEL12_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL12_SHIFT           (0U)
/*! SEL12 - SEL12 */
#define XBAR_NUM_OUT32_SEL_SEL12(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL12_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL12_MASK)

#define XBAR_NUM_OUT32_SEL_SEL14_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL14_SHIFT           (0U)
/*! SEL14 - SEL14 */
#define XBAR_NUM_OUT32_SEL_SEL14(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL14_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL14_MASK)

#define XBAR_NUM_OUT32_SEL_SEL16_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL16_SHIFT           (0U)
/*! SEL16 - SEL16 */
#define XBAR_NUM_OUT32_SEL_SEL16(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL16_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL16_MASK)

#define XBAR_NUM_OUT32_SEL_SEL18_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL18_SHIFT           (0U)
/*! SEL18 - SEL18 */
#define XBAR_NUM_OUT32_SEL_SEL18(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL18_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL18_MASK)

#define XBAR_NUM_OUT32_SEL_SEL20_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL20_SHIFT           (0U)
/*! SEL20 - SEL20 */
#define XBAR_NUM_OUT32_SEL_SEL20(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL20_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL20_MASK)

#define XBAR_NUM_OUT32_SEL_SEL22_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL22_SHIFT           (0U)
/*! SEL22 - SEL22 */
#define XBAR_NUM_OUT32_SEL_SEL22(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL22_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL22_MASK)

#define XBAR_NUM_OUT32_SEL_SEL24_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL24_SHIFT           (0U)
/*! SEL24 - SEL24 */
#define XBAR_NUM_OUT32_SEL_SEL24(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL24_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL24_MASK)

#define XBAR_NUM_OUT32_SEL_SEL26_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL26_SHIFT           (0U)
/*! SEL26 - SEL26 */
#define XBAR_NUM_OUT32_SEL_SEL26(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL26_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL26_MASK)

#define XBAR_NUM_OUT32_SEL_SEL28_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL28_SHIFT           (0U)
/*! SEL28 - SEL28 */
#define XBAR_NUM_OUT32_SEL_SEL28(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL28_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL28_MASK)

#define XBAR_NUM_OUT32_SEL_SEL30_MASK            (0xFFU)
#define XBAR_NUM_OUT32_SEL_SEL30_SHIFT           (0U)
/*! SEL30 - SEL30 */
#define XBAR_NUM_OUT32_SEL_SEL30(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL30_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL30_MASK)

#define XBAR_NUM_OUT32_SEL_SEL1_MASK             (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL1_SHIFT            (8U)
/*! SEL1 - SEL1 */
#define XBAR_NUM_OUT32_SEL_SEL1(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL1_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL1_MASK)

#define XBAR_NUM_OUT32_SEL_SEL3_MASK             (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL3_SHIFT            (8U)
/*! SEL3 - SEL3 */
#define XBAR_NUM_OUT32_SEL_SEL3(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL3_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL3_MASK)

#define XBAR_NUM_OUT32_SEL_SEL5_MASK             (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL5_SHIFT            (8U)
/*! SEL5 - SEL5 */
#define XBAR_NUM_OUT32_SEL_SEL5(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL5_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL5_MASK)

#define XBAR_NUM_OUT32_SEL_SEL7_MASK             (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL7_SHIFT            (8U)
/*! SEL7 - SEL7 */
#define XBAR_NUM_OUT32_SEL_SEL7(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL7_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL7_MASK)

#define XBAR_NUM_OUT32_SEL_SEL9_MASK             (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL9_SHIFT            (8U)
/*! SEL9 - SEL9 */
#define XBAR_NUM_OUT32_SEL_SEL9(x)               (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL9_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL9_MASK)

#define XBAR_NUM_OUT32_SEL_SEL11_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL11_SHIFT           (8U)
/*! SEL11 - SEL11 */
#define XBAR_NUM_OUT32_SEL_SEL11(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL11_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL11_MASK)

#define XBAR_NUM_OUT32_SEL_SEL13_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL13_SHIFT           (8U)
/*! SEL13 - SEL13 */
#define XBAR_NUM_OUT32_SEL_SEL13(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL13_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL13_MASK)

#define XBAR_NUM_OUT32_SEL_SEL15_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL15_SHIFT           (8U)
/*! SEL15 - SEL15 */
#define XBAR_NUM_OUT32_SEL_SEL15(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL15_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL15_MASK)

#define XBAR_NUM_OUT32_SEL_SEL17_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL17_SHIFT           (8U)
/*! SEL17 - SEL17 */
#define XBAR_NUM_OUT32_SEL_SEL17(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL17_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL17_MASK)

#define XBAR_NUM_OUT32_SEL_SEL19_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL19_SHIFT           (8U)
/*! SEL19 - SEL19 */
#define XBAR_NUM_OUT32_SEL_SEL19(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL19_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL19_MASK)

#define XBAR_NUM_OUT32_SEL_SEL21_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL21_SHIFT           (8U)
/*! SEL21 - SEL21 */
#define XBAR_NUM_OUT32_SEL_SEL21(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL21_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL21_MASK)

#define XBAR_NUM_OUT32_SEL_SEL23_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL23_SHIFT           (8U)
/*! SEL23 - SEL23 */
#define XBAR_NUM_OUT32_SEL_SEL23(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL23_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL23_MASK)

#define XBAR_NUM_OUT32_SEL_SEL25_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL25_SHIFT           (8U)
/*! SEL25 - SEL25 */
#define XBAR_NUM_OUT32_SEL_SEL25(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL25_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL25_MASK)

#define XBAR_NUM_OUT32_SEL_SEL27_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL27_SHIFT           (8U)
/*! SEL27 - SEL27 */
#define XBAR_NUM_OUT32_SEL_SEL27(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL27_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL27_MASK)

#define XBAR_NUM_OUT32_SEL_SEL29_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL29_SHIFT           (8U)
/*! SEL29 - SEL29 */
#define XBAR_NUM_OUT32_SEL_SEL29(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL29_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL29_MASK)

#define XBAR_NUM_OUT32_SEL_SEL31_MASK            (0xFF00U)
#define XBAR_NUM_OUT32_SEL_SEL31_SHIFT           (8U)
/*! SEL31 - SEL31 */
#define XBAR_NUM_OUT32_SEL_SEL31(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT32_SEL_SEL31_SHIFT)) & XBAR_NUM_OUT32_SEL_SEL31_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT32_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT32_Peripheral_Access_Layer */


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


#endif  /* PERI_XBAR_NUM_OUT32_H_ */

