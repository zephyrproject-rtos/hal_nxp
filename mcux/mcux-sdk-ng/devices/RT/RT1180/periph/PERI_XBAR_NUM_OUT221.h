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
**         CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
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
 * @file PERI_XBAR_NUM_OUT221.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
 *
 * CMSIS Peripheral Access Layer for XBAR_NUM_OUT221
 */

#if !defined(PERI_XBAR_NUM_OUT221_H_)
#define PERI_XBAR_NUM_OUT221_H_                  /**< Symbol preventing repeated inclusion */

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
   -- XBAR_NUM_OUT221 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT221_Peripheral_Access_Layer XBAR_NUM_OUT221 Peripheral Access Layer
 * @{
 */

/** XBAR_NUM_OUT221 - Size of Registers Arrays */
#define XBAR_NUM_OUT221_SEL_COUNT                 111u
#define XBAR_NUM_OUT221_CTRL_COUNT                2u

/** XBAR_NUM_OUT221 - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL[XBAR_NUM_OUT221_SEL_COUNT];    /**< Crossbar Select Register, array offset: 0x0, array step: 0x2 */
  __IO uint16_t CTRL[XBAR_NUM_OUT221_CTRL_COUNT];  /**< Crossbar Control Register, array offset: 0xDE, array step: 0x2 */
} XBAR_NUM_OUT221_Type;

/* ----------------------------------------------------------------------------
   -- XBAR_NUM_OUT221 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBAR_NUM_OUT221_Register_Masks XBAR_NUM_OUT221 Register Masks
 * @{
 */

/*! @name SEL - Crossbar Select Register */
/*! @{ */

#define XBAR_NUM_OUT221_SEL_SEL0_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL0_SHIFT           (0U)
/*! SEL0 - SEL0 */
#define XBAR_NUM_OUT221_SEL_SEL0(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL0_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL0_MASK)

#define XBAR_NUM_OUT221_SEL_SEL2_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL2_SHIFT           (0U)
/*! SEL2 - SEL2 */
#define XBAR_NUM_OUT221_SEL_SEL2(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL2_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL2_MASK)

#define XBAR_NUM_OUT221_SEL_SEL4_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL4_SHIFT           (0U)
/*! SEL4 - SEL4 */
#define XBAR_NUM_OUT221_SEL_SEL4(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL4_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL4_MASK)

#define XBAR_NUM_OUT221_SEL_SEL6_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL6_SHIFT           (0U)
/*! SEL6 - SEL6 */
#define XBAR_NUM_OUT221_SEL_SEL6(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL6_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL6_MASK)

#define XBAR_NUM_OUT221_SEL_SEL8_MASK            (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL8_SHIFT           (0U)
/*! SEL8 - SEL8 */
#define XBAR_NUM_OUT221_SEL_SEL8(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL8_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL8_MASK)

#define XBAR_NUM_OUT221_SEL_SEL10_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL10_SHIFT          (0U)
/*! SEL10 - SEL10 */
#define XBAR_NUM_OUT221_SEL_SEL10(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL10_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL10_MASK)

#define XBAR_NUM_OUT221_SEL_SEL12_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL12_SHIFT          (0U)
/*! SEL12 - SEL12 */
#define XBAR_NUM_OUT221_SEL_SEL12(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL12_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL12_MASK)

#define XBAR_NUM_OUT221_SEL_SEL14_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL14_SHIFT          (0U)
/*! SEL14 - SEL14 */
#define XBAR_NUM_OUT221_SEL_SEL14(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL14_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL14_MASK)

#define XBAR_NUM_OUT221_SEL_SEL16_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL16_SHIFT          (0U)
/*! SEL16 - SEL16 */
#define XBAR_NUM_OUT221_SEL_SEL16(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL16_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL16_MASK)

#define XBAR_NUM_OUT221_SEL_SEL18_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL18_SHIFT          (0U)
/*! SEL18 - SEL18 */
#define XBAR_NUM_OUT221_SEL_SEL18(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL18_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL18_MASK)

#define XBAR_NUM_OUT221_SEL_SEL20_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL20_SHIFT          (0U)
/*! SEL20 - SEL20 */
#define XBAR_NUM_OUT221_SEL_SEL20(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL20_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL20_MASK)

#define XBAR_NUM_OUT221_SEL_SEL22_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL22_SHIFT          (0U)
/*! SEL22 - SEL22 */
#define XBAR_NUM_OUT221_SEL_SEL22(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL22_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL22_MASK)

#define XBAR_NUM_OUT221_SEL_SEL24_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL24_SHIFT          (0U)
/*! SEL24 - SEL24 */
#define XBAR_NUM_OUT221_SEL_SEL24(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL24_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL24_MASK)

#define XBAR_NUM_OUT221_SEL_SEL26_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL26_SHIFT          (0U)
/*! SEL26 - SEL26 */
#define XBAR_NUM_OUT221_SEL_SEL26(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL26_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL26_MASK)

#define XBAR_NUM_OUT221_SEL_SEL28_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL28_SHIFT          (0U)
/*! SEL28 - SEL28 */
#define XBAR_NUM_OUT221_SEL_SEL28(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL28_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL28_MASK)

#define XBAR_NUM_OUT221_SEL_SEL30_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL30_SHIFT          (0U)
/*! SEL30 - SEL30 */
#define XBAR_NUM_OUT221_SEL_SEL30(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL30_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL30_MASK)

#define XBAR_NUM_OUT221_SEL_SEL32_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL32_SHIFT          (0U)
/*! SEL32 - SEL32 */
#define XBAR_NUM_OUT221_SEL_SEL32(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL32_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL32_MASK)

#define XBAR_NUM_OUT221_SEL_SEL34_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL34_SHIFT          (0U)
/*! SEL34 - SEL34 */
#define XBAR_NUM_OUT221_SEL_SEL34(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL34_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL34_MASK)

#define XBAR_NUM_OUT221_SEL_SEL36_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL36_SHIFT          (0U)
/*! SEL36 - SEL36 */
#define XBAR_NUM_OUT221_SEL_SEL36(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL36_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL36_MASK)

#define XBAR_NUM_OUT221_SEL_SEL38_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL38_SHIFT          (0U)
/*! SEL38 - SEL38 */
#define XBAR_NUM_OUT221_SEL_SEL38(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL38_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL38_MASK)

#define XBAR_NUM_OUT221_SEL_SEL40_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL40_SHIFT          (0U)
/*! SEL40 - SEL40 */
#define XBAR_NUM_OUT221_SEL_SEL40(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL40_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL40_MASK)

#define XBAR_NUM_OUT221_SEL_SEL42_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL42_SHIFT          (0U)
/*! SEL42 - SEL42 */
#define XBAR_NUM_OUT221_SEL_SEL42(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL42_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL42_MASK)

#define XBAR_NUM_OUT221_SEL_SEL44_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL44_SHIFT          (0U)
/*! SEL44 - SEL44 */
#define XBAR_NUM_OUT221_SEL_SEL44(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL44_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL44_MASK)

#define XBAR_NUM_OUT221_SEL_SEL46_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL46_SHIFT          (0U)
/*! SEL46 - SEL46 */
#define XBAR_NUM_OUT221_SEL_SEL46(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL46_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL46_MASK)

#define XBAR_NUM_OUT221_SEL_SEL48_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL48_SHIFT          (0U)
/*! SEL48 - SEL48 */
#define XBAR_NUM_OUT221_SEL_SEL48(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL48_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL48_MASK)

#define XBAR_NUM_OUT221_SEL_SEL50_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL50_SHIFT          (0U)
/*! SEL50 - SEL50 */
#define XBAR_NUM_OUT221_SEL_SEL50(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL50_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL50_MASK)

#define XBAR_NUM_OUT221_SEL_SEL52_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL52_SHIFT          (0U)
/*! SEL52 - SEL52 */
#define XBAR_NUM_OUT221_SEL_SEL52(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL52_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL52_MASK)

#define XBAR_NUM_OUT221_SEL_SEL54_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL54_SHIFT          (0U)
/*! SEL54 - SEL54 */
#define XBAR_NUM_OUT221_SEL_SEL54(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL54_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL54_MASK)

#define XBAR_NUM_OUT221_SEL_SEL56_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL56_SHIFT          (0U)
/*! SEL56 - SEL56 */
#define XBAR_NUM_OUT221_SEL_SEL56(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL56_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL56_MASK)

#define XBAR_NUM_OUT221_SEL_SEL58_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL58_SHIFT          (0U)
/*! SEL58 - SEL58 */
#define XBAR_NUM_OUT221_SEL_SEL58(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL58_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL58_MASK)

#define XBAR_NUM_OUT221_SEL_SEL60_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL60_SHIFT          (0U)
/*! SEL60 - SEL60 */
#define XBAR_NUM_OUT221_SEL_SEL60(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL60_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL60_MASK)

#define XBAR_NUM_OUT221_SEL_SEL62_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL62_SHIFT          (0U)
/*! SEL62 - SEL62 */
#define XBAR_NUM_OUT221_SEL_SEL62(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL62_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL62_MASK)

#define XBAR_NUM_OUT221_SEL_SEL64_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL64_SHIFT          (0U)
/*! SEL64 - SEL64 */
#define XBAR_NUM_OUT221_SEL_SEL64(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL64_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL64_MASK)

#define XBAR_NUM_OUT221_SEL_SEL66_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL66_SHIFT          (0U)
/*! SEL66 - SEL66 */
#define XBAR_NUM_OUT221_SEL_SEL66(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL66_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL66_MASK)

#define XBAR_NUM_OUT221_SEL_SEL68_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL68_SHIFT          (0U)
/*! SEL68 - SEL68 */
#define XBAR_NUM_OUT221_SEL_SEL68(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL68_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL68_MASK)

#define XBAR_NUM_OUT221_SEL_SEL70_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL70_SHIFT          (0U)
/*! SEL70 - SEL70 */
#define XBAR_NUM_OUT221_SEL_SEL70(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL70_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL70_MASK)

#define XBAR_NUM_OUT221_SEL_SEL72_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL72_SHIFT          (0U)
/*! SEL72 - SEL72 */
#define XBAR_NUM_OUT221_SEL_SEL72(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL72_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL72_MASK)

#define XBAR_NUM_OUT221_SEL_SEL74_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL74_SHIFT          (0U)
/*! SEL74 - SEL74 */
#define XBAR_NUM_OUT221_SEL_SEL74(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL74_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL74_MASK)

#define XBAR_NUM_OUT221_SEL_SEL76_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL76_SHIFT          (0U)
/*! SEL76 - SEL76 */
#define XBAR_NUM_OUT221_SEL_SEL76(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL76_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL76_MASK)

#define XBAR_NUM_OUT221_SEL_SEL78_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL78_SHIFT          (0U)
/*! SEL78 - SEL78 */
#define XBAR_NUM_OUT221_SEL_SEL78(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL78_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL78_MASK)

#define XBAR_NUM_OUT221_SEL_SEL80_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL80_SHIFT          (0U)
/*! SEL80 - SEL80 */
#define XBAR_NUM_OUT221_SEL_SEL80(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL80_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL80_MASK)

#define XBAR_NUM_OUT221_SEL_SEL82_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL82_SHIFT          (0U)
/*! SEL82 - SEL82 */
#define XBAR_NUM_OUT221_SEL_SEL82(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL82_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL82_MASK)

#define XBAR_NUM_OUT221_SEL_SEL84_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL84_SHIFT          (0U)
/*! SEL84 - SEL84 */
#define XBAR_NUM_OUT221_SEL_SEL84(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL84_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL84_MASK)

#define XBAR_NUM_OUT221_SEL_SEL86_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL86_SHIFT          (0U)
/*! SEL86 - SEL86 */
#define XBAR_NUM_OUT221_SEL_SEL86(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL86_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL86_MASK)

#define XBAR_NUM_OUT221_SEL_SEL88_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL88_SHIFT          (0U)
/*! SEL88 - SEL88 */
#define XBAR_NUM_OUT221_SEL_SEL88(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL88_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL88_MASK)

#define XBAR_NUM_OUT221_SEL_SEL90_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL90_SHIFT          (0U)
/*! SEL90 - SEL90 */
#define XBAR_NUM_OUT221_SEL_SEL90(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL90_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL90_MASK)

#define XBAR_NUM_OUT221_SEL_SEL92_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL92_SHIFT          (0U)
/*! SEL92 - SEL92 */
#define XBAR_NUM_OUT221_SEL_SEL92(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL92_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL92_MASK)

#define XBAR_NUM_OUT221_SEL_SEL94_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL94_SHIFT          (0U)
/*! SEL94 - SEL94 */
#define XBAR_NUM_OUT221_SEL_SEL94(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL94_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL94_MASK)

#define XBAR_NUM_OUT221_SEL_SEL96_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL96_SHIFT          (0U)
/*! SEL96 - SEL96 */
#define XBAR_NUM_OUT221_SEL_SEL96(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL96_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL96_MASK)

#define XBAR_NUM_OUT221_SEL_SEL98_MASK           (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL98_SHIFT          (0U)
/*! SEL98 - SEL98 */
#define XBAR_NUM_OUT221_SEL_SEL98(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL98_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL98_MASK)

#define XBAR_NUM_OUT221_SEL_SEL100_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL100_SHIFT         (0U)
/*! SEL100 - SEL100 */
#define XBAR_NUM_OUT221_SEL_SEL100(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL100_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL100_MASK)

#define XBAR_NUM_OUT221_SEL_SEL102_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL102_SHIFT         (0U)
/*! SEL102 - SEL102 */
#define XBAR_NUM_OUT221_SEL_SEL102(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL102_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL102_MASK)

#define XBAR_NUM_OUT221_SEL_SEL104_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL104_SHIFT         (0U)
/*! SEL104 - SEL104 */
#define XBAR_NUM_OUT221_SEL_SEL104(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL104_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL104_MASK)

#define XBAR_NUM_OUT221_SEL_SEL106_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL106_SHIFT         (0U)
/*! SEL106 - SEL106 */
#define XBAR_NUM_OUT221_SEL_SEL106(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL106_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL106_MASK)

#define XBAR_NUM_OUT221_SEL_SEL108_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL108_SHIFT         (0U)
/*! SEL108 - SEL108 */
#define XBAR_NUM_OUT221_SEL_SEL108(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL108_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL108_MASK)

#define XBAR_NUM_OUT221_SEL_SEL110_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL110_SHIFT         (0U)
/*! SEL110 - SEL110 */
#define XBAR_NUM_OUT221_SEL_SEL110(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL110_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL110_MASK)

#define XBAR_NUM_OUT221_SEL_SEL112_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL112_SHIFT         (0U)
/*! SEL112 - SEL112 */
#define XBAR_NUM_OUT221_SEL_SEL112(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL112_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL112_MASK)

#define XBAR_NUM_OUT221_SEL_SEL114_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL114_SHIFT         (0U)
/*! SEL114 - SEL114 */
#define XBAR_NUM_OUT221_SEL_SEL114(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL114_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL114_MASK)

#define XBAR_NUM_OUT221_SEL_SEL116_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL116_SHIFT         (0U)
/*! SEL116 - SEL116 */
#define XBAR_NUM_OUT221_SEL_SEL116(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL116_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL116_MASK)

#define XBAR_NUM_OUT221_SEL_SEL118_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL118_SHIFT         (0U)
/*! SEL118 - SEL118 */
#define XBAR_NUM_OUT221_SEL_SEL118(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL118_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL118_MASK)

#define XBAR_NUM_OUT221_SEL_SEL120_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL120_SHIFT         (0U)
/*! SEL120 - SEL120 */
#define XBAR_NUM_OUT221_SEL_SEL120(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL120_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL120_MASK)

#define XBAR_NUM_OUT221_SEL_SEL122_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL122_SHIFT         (0U)
/*! SEL122 - SEL122 */
#define XBAR_NUM_OUT221_SEL_SEL122(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL122_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL122_MASK)

#define XBAR_NUM_OUT221_SEL_SEL124_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL124_SHIFT         (0U)
/*! SEL124 - SEL124 */
#define XBAR_NUM_OUT221_SEL_SEL124(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL124_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL124_MASK)

#define XBAR_NUM_OUT221_SEL_SEL126_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL126_SHIFT         (0U)
/*! SEL126 - SEL126 */
#define XBAR_NUM_OUT221_SEL_SEL126(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL126_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL126_MASK)

#define XBAR_NUM_OUT221_SEL_SEL128_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL128_SHIFT         (0U)
/*! SEL128 - SEL128 */
#define XBAR_NUM_OUT221_SEL_SEL128(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL128_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL128_MASK)

#define XBAR_NUM_OUT221_SEL_SEL130_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL130_SHIFT         (0U)
/*! SEL130 - SEL130 */
#define XBAR_NUM_OUT221_SEL_SEL130(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL130_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL130_MASK)

#define XBAR_NUM_OUT221_SEL_SEL132_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL132_SHIFT         (0U)
/*! SEL132 - SEL132 */
#define XBAR_NUM_OUT221_SEL_SEL132(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL132_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL132_MASK)

#define XBAR_NUM_OUT221_SEL_SEL134_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL134_SHIFT         (0U)
/*! SEL134 - SEL134 */
#define XBAR_NUM_OUT221_SEL_SEL134(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL134_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL134_MASK)

#define XBAR_NUM_OUT221_SEL_SEL136_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL136_SHIFT         (0U)
/*! SEL136 - SEL136 */
#define XBAR_NUM_OUT221_SEL_SEL136(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL136_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL136_MASK)

#define XBAR_NUM_OUT221_SEL_SEL138_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL138_SHIFT         (0U)
/*! SEL138 - SEL138 */
#define XBAR_NUM_OUT221_SEL_SEL138(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL138_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL138_MASK)

#define XBAR_NUM_OUT221_SEL_SEL140_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL140_SHIFT         (0U)
/*! SEL140 - SEL140 */
#define XBAR_NUM_OUT221_SEL_SEL140(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL140_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL140_MASK)

#define XBAR_NUM_OUT221_SEL_SEL142_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL142_SHIFT         (0U)
/*! SEL142 - SEL142 */
#define XBAR_NUM_OUT221_SEL_SEL142(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL142_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL142_MASK)

#define XBAR_NUM_OUT221_SEL_SEL144_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL144_SHIFT         (0U)
/*! SEL144 - SEL144 */
#define XBAR_NUM_OUT221_SEL_SEL144(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL144_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL144_MASK)

#define XBAR_NUM_OUT221_SEL_SEL146_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL146_SHIFT         (0U)
/*! SEL146 - SEL146 */
#define XBAR_NUM_OUT221_SEL_SEL146(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL146_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL146_MASK)

#define XBAR_NUM_OUT221_SEL_SEL148_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL148_SHIFT         (0U)
/*! SEL148 - SEL148 */
#define XBAR_NUM_OUT221_SEL_SEL148(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL148_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL148_MASK)

#define XBAR_NUM_OUT221_SEL_SEL150_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL150_SHIFT         (0U)
/*! SEL150 - SEL150 */
#define XBAR_NUM_OUT221_SEL_SEL150(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL150_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL150_MASK)

#define XBAR_NUM_OUT221_SEL_SEL152_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL152_SHIFT         (0U)
/*! SEL152 - SEL152 */
#define XBAR_NUM_OUT221_SEL_SEL152(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL152_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL152_MASK)

#define XBAR_NUM_OUT221_SEL_SEL154_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL154_SHIFT         (0U)
/*! SEL154 - SEL154 */
#define XBAR_NUM_OUT221_SEL_SEL154(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL154_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL154_MASK)

#define XBAR_NUM_OUT221_SEL_SEL156_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL156_SHIFT         (0U)
/*! SEL156 - SEL156 */
#define XBAR_NUM_OUT221_SEL_SEL156(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL156_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL156_MASK)

#define XBAR_NUM_OUT221_SEL_SEL158_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL158_SHIFT         (0U)
/*! SEL158 - SEL158 */
#define XBAR_NUM_OUT221_SEL_SEL158(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL158_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL158_MASK)

#define XBAR_NUM_OUT221_SEL_SEL160_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL160_SHIFT         (0U)
/*! SEL160 - SEL160 */
#define XBAR_NUM_OUT221_SEL_SEL160(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL160_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL160_MASK)

#define XBAR_NUM_OUT221_SEL_SEL162_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL162_SHIFT         (0U)
/*! SEL162 - SEL162 */
#define XBAR_NUM_OUT221_SEL_SEL162(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL162_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL162_MASK)

#define XBAR_NUM_OUT221_SEL_SEL164_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL164_SHIFT         (0U)
/*! SEL164 - SEL164 */
#define XBAR_NUM_OUT221_SEL_SEL164(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL164_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL164_MASK)

#define XBAR_NUM_OUT221_SEL_SEL166_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL166_SHIFT         (0U)
/*! SEL166 - SEL166 */
#define XBAR_NUM_OUT221_SEL_SEL166(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL166_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL166_MASK)

#define XBAR_NUM_OUT221_SEL_SEL168_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL168_SHIFT         (0U)
/*! SEL168 - SEL168 */
#define XBAR_NUM_OUT221_SEL_SEL168(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL168_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL168_MASK)

#define XBAR_NUM_OUT221_SEL_SEL170_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL170_SHIFT         (0U)
/*! SEL170 - SEL170 */
#define XBAR_NUM_OUT221_SEL_SEL170(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL170_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL170_MASK)

#define XBAR_NUM_OUT221_SEL_SEL172_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL172_SHIFT         (0U)
/*! SEL172 - SEL172 */
#define XBAR_NUM_OUT221_SEL_SEL172(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL172_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL172_MASK)

#define XBAR_NUM_OUT221_SEL_SEL174_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL174_SHIFT         (0U)
/*! SEL174 - SEL174 */
#define XBAR_NUM_OUT221_SEL_SEL174(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL174_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL174_MASK)

#define XBAR_NUM_OUT221_SEL_SEL176_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL176_SHIFT         (0U)
/*! SEL176 - SEL176 */
#define XBAR_NUM_OUT221_SEL_SEL176(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL176_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL176_MASK)

#define XBAR_NUM_OUT221_SEL_SEL178_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL178_SHIFT         (0U)
/*! SEL178 - SEL178 */
#define XBAR_NUM_OUT221_SEL_SEL178(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL178_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL178_MASK)

#define XBAR_NUM_OUT221_SEL_SEL180_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL180_SHIFT         (0U)
/*! SEL180 - SEL180 */
#define XBAR_NUM_OUT221_SEL_SEL180(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL180_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL180_MASK)

#define XBAR_NUM_OUT221_SEL_SEL182_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL182_SHIFT         (0U)
/*! SEL182 - SEL182 */
#define XBAR_NUM_OUT221_SEL_SEL182(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL182_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL182_MASK)

#define XBAR_NUM_OUT221_SEL_SEL184_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL184_SHIFT         (0U)
/*! SEL184 - SEL184 */
#define XBAR_NUM_OUT221_SEL_SEL184(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL184_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL184_MASK)

#define XBAR_NUM_OUT221_SEL_SEL186_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL186_SHIFT         (0U)
/*! SEL186 - SEL186 */
#define XBAR_NUM_OUT221_SEL_SEL186(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL186_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL186_MASK)

#define XBAR_NUM_OUT221_SEL_SEL188_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL188_SHIFT         (0U)
/*! SEL188 - SEL188 */
#define XBAR_NUM_OUT221_SEL_SEL188(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL188_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL188_MASK)

#define XBAR_NUM_OUT221_SEL_SEL190_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL190_SHIFT         (0U)
/*! SEL190 - SEL190 */
#define XBAR_NUM_OUT221_SEL_SEL190(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL190_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL190_MASK)

#define XBAR_NUM_OUT221_SEL_SEL192_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL192_SHIFT         (0U)
/*! SEL192 - SEL192 */
#define XBAR_NUM_OUT221_SEL_SEL192(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL192_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL192_MASK)

#define XBAR_NUM_OUT221_SEL_SEL194_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL194_SHIFT         (0U)
/*! SEL194 - SEL194 */
#define XBAR_NUM_OUT221_SEL_SEL194(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL194_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL194_MASK)

#define XBAR_NUM_OUT221_SEL_SEL196_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL196_SHIFT         (0U)
/*! SEL196 - SEL196 */
#define XBAR_NUM_OUT221_SEL_SEL196(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL196_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL196_MASK)

#define XBAR_NUM_OUT221_SEL_SEL198_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL198_SHIFT         (0U)
/*! SEL198 - SEL198 */
#define XBAR_NUM_OUT221_SEL_SEL198(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL198_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL198_MASK)

#define XBAR_NUM_OUT221_SEL_SEL200_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL200_SHIFT         (0U)
/*! SEL200 - SEL200 */
#define XBAR_NUM_OUT221_SEL_SEL200(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL200_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL200_MASK)

#define XBAR_NUM_OUT221_SEL_SEL202_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL202_SHIFT         (0U)
/*! SEL202 - SEL202 */
#define XBAR_NUM_OUT221_SEL_SEL202(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL202_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL202_MASK)

#define XBAR_NUM_OUT221_SEL_SEL204_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL204_SHIFT         (0U)
/*! SEL204 - SEL204 */
#define XBAR_NUM_OUT221_SEL_SEL204(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL204_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL204_MASK)

#define XBAR_NUM_OUT221_SEL_SEL206_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL206_SHIFT         (0U)
/*! SEL206 - SEL206 */
#define XBAR_NUM_OUT221_SEL_SEL206(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL206_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL206_MASK)

#define XBAR_NUM_OUT221_SEL_SEL208_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL208_SHIFT         (0U)
/*! SEL208 - SEL208 */
#define XBAR_NUM_OUT221_SEL_SEL208(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL208_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL208_MASK)

#define XBAR_NUM_OUT221_SEL_SEL210_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL210_SHIFT         (0U)
/*! SEL210 - SEL210 */
#define XBAR_NUM_OUT221_SEL_SEL210(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL210_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL210_MASK)

#define XBAR_NUM_OUT221_SEL_SEL212_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL212_SHIFT         (0U)
/*! SEL212 - SEL212 */
#define XBAR_NUM_OUT221_SEL_SEL212(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL212_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL212_MASK)

#define XBAR_NUM_OUT221_SEL_SEL214_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL214_SHIFT         (0U)
/*! SEL214 - SEL214 */
#define XBAR_NUM_OUT221_SEL_SEL214(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL214_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL214_MASK)

#define XBAR_NUM_OUT221_SEL_SEL216_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL216_SHIFT         (0U)
/*! SEL216 - SEL216 */
#define XBAR_NUM_OUT221_SEL_SEL216(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL216_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL216_MASK)

#define XBAR_NUM_OUT221_SEL_SEL218_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL218_SHIFT         (0U)
/*! SEL218 - SEL218 */
#define XBAR_NUM_OUT221_SEL_SEL218(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL218_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL218_MASK)

#define XBAR_NUM_OUT221_SEL_SEL220_MASK          (0xFFU)
#define XBAR_NUM_OUT221_SEL_SEL220_SHIFT         (0U)
/*! SEL220 - SEL220 */
#define XBAR_NUM_OUT221_SEL_SEL220(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL220_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL220_MASK)

#define XBAR_NUM_OUT221_SEL_SEL1_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL1_SHIFT           (8U)
/*! SEL1 - SEL1 */
#define XBAR_NUM_OUT221_SEL_SEL1(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL1_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL1_MASK)

#define XBAR_NUM_OUT221_SEL_SEL3_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL3_SHIFT           (8U)
/*! SEL3 - SEL3 */
#define XBAR_NUM_OUT221_SEL_SEL3(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL3_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL3_MASK)

#define XBAR_NUM_OUT221_SEL_SEL5_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL5_SHIFT           (8U)
/*! SEL5 - SEL5 */
#define XBAR_NUM_OUT221_SEL_SEL5(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL5_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL5_MASK)

#define XBAR_NUM_OUT221_SEL_SEL7_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL7_SHIFT           (8U)
/*! SEL7 - SEL7 */
#define XBAR_NUM_OUT221_SEL_SEL7(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL7_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL7_MASK)

#define XBAR_NUM_OUT221_SEL_SEL9_MASK            (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL9_SHIFT           (8U)
/*! SEL9 - SEL9 */
#define XBAR_NUM_OUT221_SEL_SEL9(x)              (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL9_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL9_MASK)

#define XBAR_NUM_OUT221_SEL_SEL11_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL11_SHIFT          (8U)
/*! SEL11 - SEL11 */
#define XBAR_NUM_OUT221_SEL_SEL11(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL11_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL11_MASK)

#define XBAR_NUM_OUT221_SEL_SEL13_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL13_SHIFT          (8U)
/*! SEL13 - SEL13 */
#define XBAR_NUM_OUT221_SEL_SEL13(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL13_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL13_MASK)

#define XBAR_NUM_OUT221_SEL_SEL15_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL15_SHIFT          (8U)
/*! SEL15 - SEL15 */
#define XBAR_NUM_OUT221_SEL_SEL15(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL15_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL15_MASK)

#define XBAR_NUM_OUT221_SEL_SEL17_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL17_SHIFT          (8U)
/*! SEL17 - SEL17 */
#define XBAR_NUM_OUT221_SEL_SEL17(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL17_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL17_MASK)

#define XBAR_NUM_OUT221_SEL_SEL19_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL19_SHIFT          (8U)
/*! SEL19 - SEL19 */
#define XBAR_NUM_OUT221_SEL_SEL19(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL19_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL19_MASK)

#define XBAR_NUM_OUT221_SEL_SEL21_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL21_SHIFT          (8U)
/*! SEL21 - SEL21 */
#define XBAR_NUM_OUT221_SEL_SEL21(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL21_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL21_MASK)

#define XBAR_NUM_OUT221_SEL_SEL23_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL23_SHIFT          (8U)
/*! SEL23 - SEL23 */
#define XBAR_NUM_OUT221_SEL_SEL23(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL23_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL23_MASK)

#define XBAR_NUM_OUT221_SEL_SEL25_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL25_SHIFT          (8U)
/*! SEL25 - SEL25 */
#define XBAR_NUM_OUT221_SEL_SEL25(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL25_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL25_MASK)

#define XBAR_NUM_OUT221_SEL_SEL27_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL27_SHIFT          (8U)
/*! SEL27 - SEL27 */
#define XBAR_NUM_OUT221_SEL_SEL27(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL27_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL27_MASK)

#define XBAR_NUM_OUT221_SEL_SEL29_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL29_SHIFT          (8U)
/*! SEL29 - SEL29 */
#define XBAR_NUM_OUT221_SEL_SEL29(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL29_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL29_MASK)

#define XBAR_NUM_OUT221_SEL_SEL31_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL31_SHIFT          (8U)
/*! SEL31 - SEL31 */
#define XBAR_NUM_OUT221_SEL_SEL31(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL31_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL31_MASK)

#define XBAR_NUM_OUT221_SEL_SEL33_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL33_SHIFT          (8U)
/*! SEL33 - SEL33 */
#define XBAR_NUM_OUT221_SEL_SEL33(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL33_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL33_MASK)

#define XBAR_NUM_OUT221_SEL_SEL35_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL35_SHIFT          (8U)
/*! SEL35 - SEL35 */
#define XBAR_NUM_OUT221_SEL_SEL35(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL35_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL35_MASK)

#define XBAR_NUM_OUT221_SEL_SEL37_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL37_SHIFT          (8U)
/*! SEL37 - SEL37 */
#define XBAR_NUM_OUT221_SEL_SEL37(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL37_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL37_MASK)

#define XBAR_NUM_OUT221_SEL_SEL39_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL39_SHIFT          (8U)
/*! SEL39 - SEL39 */
#define XBAR_NUM_OUT221_SEL_SEL39(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL39_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL39_MASK)

#define XBAR_NUM_OUT221_SEL_SEL41_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL41_SHIFT          (8U)
/*! SEL41 - SEL41 */
#define XBAR_NUM_OUT221_SEL_SEL41(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL41_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL41_MASK)

#define XBAR_NUM_OUT221_SEL_SEL43_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL43_SHIFT          (8U)
/*! SEL43 - SEL43 */
#define XBAR_NUM_OUT221_SEL_SEL43(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL43_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL43_MASK)

#define XBAR_NUM_OUT221_SEL_SEL45_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL45_SHIFT          (8U)
/*! SEL45 - SEL45 */
#define XBAR_NUM_OUT221_SEL_SEL45(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL45_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL45_MASK)

#define XBAR_NUM_OUT221_SEL_SEL47_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL47_SHIFT          (8U)
/*! SEL47 - SEL47 */
#define XBAR_NUM_OUT221_SEL_SEL47(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL47_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL47_MASK)

#define XBAR_NUM_OUT221_SEL_SEL49_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL49_SHIFT          (8U)
/*! SEL49 - SEL49 */
#define XBAR_NUM_OUT221_SEL_SEL49(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL49_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL49_MASK)

#define XBAR_NUM_OUT221_SEL_SEL51_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL51_SHIFT          (8U)
/*! SEL51 - SEL51 */
#define XBAR_NUM_OUT221_SEL_SEL51(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL51_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL51_MASK)

#define XBAR_NUM_OUT221_SEL_SEL53_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL53_SHIFT          (8U)
/*! SEL53 - SEL53 */
#define XBAR_NUM_OUT221_SEL_SEL53(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL53_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL53_MASK)

#define XBAR_NUM_OUT221_SEL_SEL55_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL55_SHIFT          (8U)
/*! SEL55 - SEL55 */
#define XBAR_NUM_OUT221_SEL_SEL55(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL55_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL55_MASK)

#define XBAR_NUM_OUT221_SEL_SEL57_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL57_SHIFT          (8U)
/*! SEL57 - SEL57 */
#define XBAR_NUM_OUT221_SEL_SEL57(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL57_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL57_MASK)

#define XBAR_NUM_OUT221_SEL_SEL59_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL59_SHIFT          (8U)
/*! SEL59 - SEL59 */
#define XBAR_NUM_OUT221_SEL_SEL59(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL59_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL59_MASK)

#define XBAR_NUM_OUT221_SEL_SEL61_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL61_SHIFT          (8U)
/*! SEL61 - SEL61 */
#define XBAR_NUM_OUT221_SEL_SEL61(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL61_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL61_MASK)

#define XBAR_NUM_OUT221_SEL_SEL63_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL63_SHIFT          (8U)
/*! SEL63 - SEL63 */
#define XBAR_NUM_OUT221_SEL_SEL63(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL63_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL63_MASK)

#define XBAR_NUM_OUT221_SEL_SEL65_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL65_SHIFT          (8U)
/*! SEL65 - SEL65 */
#define XBAR_NUM_OUT221_SEL_SEL65(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL65_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL65_MASK)

#define XBAR_NUM_OUT221_SEL_SEL67_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL67_SHIFT          (8U)
/*! SEL67 - SEL67 */
#define XBAR_NUM_OUT221_SEL_SEL67(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL67_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL67_MASK)

#define XBAR_NUM_OUT221_SEL_SEL69_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL69_SHIFT          (8U)
/*! SEL69 - SEL69 */
#define XBAR_NUM_OUT221_SEL_SEL69(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL69_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL69_MASK)

#define XBAR_NUM_OUT221_SEL_SEL71_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL71_SHIFT          (8U)
/*! SEL71 - SEL71 */
#define XBAR_NUM_OUT221_SEL_SEL71(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL71_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL71_MASK)

#define XBAR_NUM_OUT221_SEL_SEL73_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL73_SHIFT          (8U)
/*! SEL73 - SEL73 */
#define XBAR_NUM_OUT221_SEL_SEL73(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL73_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL73_MASK)

#define XBAR_NUM_OUT221_SEL_SEL75_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL75_SHIFT          (8U)
/*! SEL75 - SEL75 */
#define XBAR_NUM_OUT221_SEL_SEL75(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL75_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL75_MASK)

#define XBAR_NUM_OUT221_SEL_SEL77_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL77_SHIFT          (8U)
/*! SEL77 - SEL77 */
#define XBAR_NUM_OUT221_SEL_SEL77(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL77_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL77_MASK)

#define XBAR_NUM_OUT221_SEL_SEL79_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL79_SHIFT          (8U)
/*! SEL79 - SEL79 */
#define XBAR_NUM_OUT221_SEL_SEL79(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL79_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL79_MASK)

#define XBAR_NUM_OUT221_SEL_SEL81_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL81_SHIFT          (8U)
/*! SEL81 - SEL81 */
#define XBAR_NUM_OUT221_SEL_SEL81(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL81_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL81_MASK)

#define XBAR_NUM_OUT221_SEL_SEL83_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL83_SHIFT          (8U)
/*! SEL83 - SEL83 */
#define XBAR_NUM_OUT221_SEL_SEL83(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL83_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL83_MASK)

#define XBAR_NUM_OUT221_SEL_SEL85_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL85_SHIFT          (8U)
/*! SEL85 - SEL85 */
#define XBAR_NUM_OUT221_SEL_SEL85(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL85_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL85_MASK)

#define XBAR_NUM_OUT221_SEL_SEL87_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL87_SHIFT          (8U)
/*! SEL87 - SEL87 */
#define XBAR_NUM_OUT221_SEL_SEL87(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL87_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL87_MASK)

#define XBAR_NUM_OUT221_SEL_SEL89_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL89_SHIFT          (8U)
/*! SEL89 - SEL89 */
#define XBAR_NUM_OUT221_SEL_SEL89(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL89_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL89_MASK)

#define XBAR_NUM_OUT221_SEL_SEL91_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL91_SHIFT          (8U)
/*! SEL91 - SEL91 */
#define XBAR_NUM_OUT221_SEL_SEL91(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL91_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL91_MASK)

#define XBAR_NUM_OUT221_SEL_SEL93_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL93_SHIFT          (8U)
/*! SEL93 - SEL93 */
#define XBAR_NUM_OUT221_SEL_SEL93(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL93_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL93_MASK)

#define XBAR_NUM_OUT221_SEL_SEL95_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL95_SHIFT          (8U)
/*! SEL95 - SEL95 */
#define XBAR_NUM_OUT221_SEL_SEL95(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL95_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL95_MASK)

#define XBAR_NUM_OUT221_SEL_SEL97_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL97_SHIFT          (8U)
/*! SEL97 - SEL97 */
#define XBAR_NUM_OUT221_SEL_SEL97(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL97_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL97_MASK)

#define XBAR_NUM_OUT221_SEL_SEL99_MASK           (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL99_SHIFT          (8U)
/*! SEL99 - SEL99 */
#define XBAR_NUM_OUT221_SEL_SEL99(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL99_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL99_MASK)

#define XBAR_NUM_OUT221_SEL_SEL101_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL101_SHIFT         (8U)
/*! SEL101 - SEL101 */
#define XBAR_NUM_OUT221_SEL_SEL101(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL101_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL101_MASK)

#define XBAR_NUM_OUT221_SEL_SEL103_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL103_SHIFT         (8U)
/*! SEL103 - SEL103 */
#define XBAR_NUM_OUT221_SEL_SEL103(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL103_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL103_MASK)

#define XBAR_NUM_OUT221_SEL_SEL105_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL105_SHIFT         (8U)
/*! SEL105 - SEL105 */
#define XBAR_NUM_OUT221_SEL_SEL105(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL105_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL105_MASK)

#define XBAR_NUM_OUT221_SEL_SEL107_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL107_SHIFT         (8U)
/*! SEL107 - SEL107 */
#define XBAR_NUM_OUT221_SEL_SEL107(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL107_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL107_MASK)

#define XBAR_NUM_OUT221_SEL_SEL109_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL109_SHIFT         (8U)
/*! SEL109 - SEL109 */
#define XBAR_NUM_OUT221_SEL_SEL109(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL109_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL109_MASK)

#define XBAR_NUM_OUT221_SEL_SEL111_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL111_SHIFT         (8U)
/*! SEL111 - SEL111 */
#define XBAR_NUM_OUT221_SEL_SEL111(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL111_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL111_MASK)

#define XBAR_NUM_OUT221_SEL_SEL113_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL113_SHIFT         (8U)
/*! SEL113 - SEL113 */
#define XBAR_NUM_OUT221_SEL_SEL113(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL113_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL113_MASK)

#define XBAR_NUM_OUT221_SEL_SEL115_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL115_SHIFT         (8U)
/*! SEL115 - SEL115 */
#define XBAR_NUM_OUT221_SEL_SEL115(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL115_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL115_MASK)

#define XBAR_NUM_OUT221_SEL_SEL117_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL117_SHIFT         (8U)
/*! SEL117 - SEL117 */
#define XBAR_NUM_OUT221_SEL_SEL117(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL117_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL117_MASK)

#define XBAR_NUM_OUT221_SEL_SEL119_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL119_SHIFT         (8U)
/*! SEL119 - SEL119 */
#define XBAR_NUM_OUT221_SEL_SEL119(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL119_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL119_MASK)

#define XBAR_NUM_OUT221_SEL_SEL121_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL121_SHIFT         (8U)
/*! SEL121 - SEL121 */
#define XBAR_NUM_OUT221_SEL_SEL121(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL121_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL121_MASK)

#define XBAR_NUM_OUT221_SEL_SEL123_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL123_SHIFT         (8U)
/*! SEL123 - SEL123 */
#define XBAR_NUM_OUT221_SEL_SEL123(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL123_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL123_MASK)

#define XBAR_NUM_OUT221_SEL_SEL125_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL125_SHIFT         (8U)
/*! SEL125 - SEL125 */
#define XBAR_NUM_OUT221_SEL_SEL125(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL125_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL125_MASK)

#define XBAR_NUM_OUT221_SEL_SEL127_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL127_SHIFT         (8U)
/*! SEL127 - SEL127 */
#define XBAR_NUM_OUT221_SEL_SEL127(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL127_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL127_MASK)

#define XBAR_NUM_OUT221_SEL_SEL129_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL129_SHIFT         (8U)
/*! SEL129 - SEL129 */
#define XBAR_NUM_OUT221_SEL_SEL129(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL129_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL129_MASK)

#define XBAR_NUM_OUT221_SEL_SEL131_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL131_SHIFT         (8U)
/*! SEL131 - SEL131 */
#define XBAR_NUM_OUT221_SEL_SEL131(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL131_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL131_MASK)

#define XBAR_NUM_OUT221_SEL_SEL133_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL133_SHIFT         (8U)
/*! SEL133 - SEL133 */
#define XBAR_NUM_OUT221_SEL_SEL133(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL133_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL133_MASK)

#define XBAR_NUM_OUT221_SEL_SEL135_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL135_SHIFT         (8U)
/*! SEL135 - SEL135 */
#define XBAR_NUM_OUT221_SEL_SEL135(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL135_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL135_MASK)

#define XBAR_NUM_OUT221_SEL_SEL137_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL137_SHIFT         (8U)
/*! SEL137 - SEL137 */
#define XBAR_NUM_OUT221_SEL_SEL137(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL137_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL137_MASK)

#define XBAR_NUM_OUT221_SEL_SEL139_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL139_SHIFT         (8U)
/*! SEL139 - SEL139 */
#define XBAR_NUM_OUT221_SEL_SEL139(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL139_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL139_MASK)

#define XBAR_NUM_OUT221_SEL_SEL141_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL141_SHIFT         (8U)
/*! SEL141 - SEL141 */
#define XBAR_NUM_OUT221_SEL_SEL141(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL141_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL141_MASK)

#define XBAR_NUM_OUT221_SEL_SEL143_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL143_SHIFT         (8U)
/*! SEL143 - SEL143 */
#define XBAR_NUM_OUT221_SEL_SEL143(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL143_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL143_MASK)

#define XBAR_NUM_OUT221_SEL_SEL145_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL145_SHIFT         (8U)
/*! SEL145 - SEL145 */
#define XBAR_NUM_OUT221_SEL_SEL145(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL145_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL145_MASK)

#define XBAR_NUM_OUT221_SEL_SEL147_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL147_SHIFT         (8U)
/*! SEL147 - SEL147 */
#define XBAR_NUM_OUT221_SEL_SEL147(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL147_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL147_MASK)

#define XBAR_NUM_OUT221_SEL_SEL149_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL149_SHIFT         (8U)
/*! SEL149 - SEL149 */
#define XBAR_NUM_OUT221_SEL_SEL149(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL149_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL149_MASK)

#define XBAR_NUM_OUT221_SEL_SEL151_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL151_SHIFT         (8U)
/*! SEL151 - SEL151 */
#define XBAR_NUM_OUT221_SEL_SEL151(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL151_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL151_MASK)

#define XBAR_NUM_OUT221_SEL_SEL153_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL153_SHIFT         (8U)
/*! SEL153 - SEL153 */
#define XBAR_NUM_OUT221_SEL_SEL153(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL153_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL153_MASK)

#define XBAR_NUM_OUT221_SEL_SEL155_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL155_SHIFT         (8U)
/*! SEL155 - SEL155 */
#define XBAR_NUM_OUT221_SEL_SEL155(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL155_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL155_MASK)

#define XBAR_NUM_OUT221_SEL_SEL157_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL157_SHIFT         (8U)
/*! SEL157 - SEL157 */
#define XBAR_NUM_OUT221_SEL_SEL157(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL157_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL157_MASK)

#define XBAR_NUM_OUT221_SEL_SEL159_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL159_SHIFT         (8U)
/*! SEL159 - SEL159 */
#define XBAR_NUM_OUT221_SEL_SEL159(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL159_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL159_MASK)

#define XBAR_NUM_OUT221_SEL_SEL161_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL161_SHIFT         (8U)
/*! SEL161 - SEL161 */
#define XBAR_NUM_OUT221_SEL_SEL161(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL161_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL161_MASK)

#define XBAR_NUM_OUT221_SEL_SEL163_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL163_SHIFT         (8U)
/*! SEL163 - SEL163 */
#define XBAR_NUM_OUT221_SEL_SEL163(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL163_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL163_MASK)

#define XBAR_NUM_OUT221_SEL_SEL165_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL165_SHIFT         (8U)
/*! SEL165 - SEL165 */
#define XBAR_NUM_OUT221_SEL_SEL165(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL165_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL165_MASK)

#define XBAR_NUM_OUT221_SEL_SEL167_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL167_SHIFT         (8U)
/*! SEL167 - SEL167 */
#define XBAR_NUM_OUT221_SEL_SEL167(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL167_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL167_MASK)

#define XBAR_NUM_OUT221_SEL_SEL169_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL169_SHIFT         (8U)
/*! SEL169 - SEL169 */
#define XBAR_NUM_OUT221_SEL_SEL169(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL169_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL169_MASK)

#define XBAR_NUM_OUT221_SEL_SEL171_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL171_SHIFT         (8U)
/*! SEL171 - SEL171 */
#define XBAR_NUM_OUT221_SEL_SEL171(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL171_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL171_MASK)

#define XBAR_NUM_OUT221_SEL_SEL173_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL173_SHIFT         (8U)
/*! SEL173 - SEL173 */
#define XBAR_NUM_OUT221_SEL_SEL173(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL173_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL173_MASK)

#define XBAR_NUM_OUT221_SEL_SEL175_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL175_SHIFT         (8U)
/*! SEL175 - SEL175 */
#define XBAR_NUM_OUT221_SEL_SEL175(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL175_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL175_MASK)

#define XBAR_NUM_OUT221_SEL_SEL177_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL177_SHIFT         (8U)
/*! SEL177 - SEL177 */
#define XBAR_NUM_OUT221_SEL_SEL177(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL177_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL177_MASK)

#define XBAR_NUM_OUT221_SEL_SEL179_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL179_SHIFT         (8U)
/*! SEL179 - SEL179 */
#define XBAR_NUM_OUT221_SEL_SEL179(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL179_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL179_MASK)

#define XBAR_NUM_OUT221_SEL_SEL181_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL181_SHIFT         (8U)
/*! SEL181 - SEL181 */
#define XBAR_NUM_OUT221_SEL_SEL181(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL181_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL181_MASK)

#define XBAR_NUM_OUT221_SEL_SEL183_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL183_SHIFT         (8U)
/*! SEL183 - SEL183 */
#define XBAR_NUM_OUT221_SEL_SEL183(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL183_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL183_MASK)

#define XBAR_NUM_OUT221_SEL_SEL185_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL185_SHIFT         (8U)
/*! SEL185 - SEL185 */
#define XBAR_NUM_OUT221_SEL_SEL185(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL185_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL185_MASK)

#define XBAR_NUM_OUT221_SEL_SEL187_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL187_SHIFT         (8U)
/*! SEL187 - SEL187 */
#define XBAR_NUM_OUT221_SEL_SEL187(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL187_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL187_MASK)

#define XBAR_NUM_OUT221_SEL_SEL189_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL189_SHIFT         (8U)
/*! SEL189 - SEL189 */
#define XBAR_NUM_OUT221_SEL_SEL189(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL189_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL189_MASK)

#define XBAR_NUM_OUT221_SEL_SEL191_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL191_SHIFT         (8U)
/*! SEL191 - SEL191 */
#define XBAR_NUM_OUT221_SEL_SEL191(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL191_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL191_MASK)

#define XBAR_NUM_OUT221_SEL_SEL193_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL193_SHIFT         (8U)
/*! SEL193 - SEL193 */
#define XBAR_NUM_OUT221_SEL_SEL193(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL193_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL193_MASK)

#define XBAR_NUM_OUT221_SEL_SEL195_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL195_SHIFT         (8U)
/*! SEL195 - SEL195 */
#define XBAR_NUM_OUT221_SEL_SEL195(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL195_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL195_MASK)

#define XBAR_NUM_OUT221_SEL_SEL197_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL197_SHIFT         (8U)
/*! SEL197 - SEL197 */
#define XBAR_NUM_OUT221_SEL_SEL197(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL197_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL197_MASK)

#define XBAR_NUM_OUT221_SEL_SEL199_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL199_SHIFT         (8U)
/*! SEL199 - SEL199 */
#define XBAR_NUM_OUT221_SEL_SEL199(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL199_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL199_MASK)

#define XBAR_NUM_OUT221_SEL_SEL201_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL201_SHIFT         (8U)
/*! SEL201 - SEL201 */
#define XBAR_NUM_OUT221_SEL_SEL201(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL201_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL201_MASK)

#define XBAR_NUM_OUT221_SEL_SEL203_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL203_SHIFT         (8U)
/*! SEL203 - SEL203 */
#define XBAR_NUM_OUT221_SEL_SEL203(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL203_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL203_MASK)

#define XBAR_NUM_OUT221_SEL_SEL205_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL205_SHIFT         (8U)
/*! SEL205 - SEL205 */
#define XBAR_NUM_OUT221_SEL_SEL205(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL205_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL205_MASK)

#define XBAR_NUM_OUT221_SEL_SEL207_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL207_SHIFT         (8U)
/*! SEL207 - SEL207 */
#define XBAR_NUM_OUT221_SEL_SEL207(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL207_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL207_MASK)

#define XBAR_NUM_OUT221_SEL_SEL209_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL209_SHIFT         (8U)
/*! SEL209 - SEL209 */
#define XBAR_NUM_OUT221_SEL_SEL209(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL209_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL209_MASK)

#define XBAR_NUM_OUT221_SEL_SEL211_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL211_SHIFT         (8U)
/*! SEL211 - SEL211 */
#define XBAR_NUM_OUT221_SEL_SEL211(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL211_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL211_MASK)

#define XBAR_NUM_OUT221_SEL_SEL213_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL213_SHIFT         (8U)
/*! SEL213 - SEL213 */
#define XBAR_NUM_OUT221_SEL_SEL213(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL213_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL213_MASK)

#define XBAR_NUM_OUT221_SEL_SEL215_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL215_SHIFT         (8U)
/*! SEL215 - SEL215 */
#define XBAR_NUM_OUT221_SEL_SEL215(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL215_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL215_MASK)

#define XBAR_NUM_OUT221_SEL_SEL217_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL217_SHIFT         (8U)
/*! SEL217 - SEL217 */
#define XBAR_NUM_OUT221_SEL_SEL217(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL217_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL217_MASK)

#define XBAR_NUM_OUT221_SEL_SEL219_MASK          (0xFF00U)
#define XBAR_NUM_OUT221_SEL_SEL219_SHIFT         (8U)
/*! SEL219 - SEL219 */
#define XBAR_NUM_OUT221_SEL_SEL219(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_SEL_SEL219_SHIFT)) & XBAR_NUM_OUT221_SEL_SEL219_MASK)
/*! @} */

/*! @name CTRL - Crossbar Control Register */
/*! @{ */

#define XBAR_NUM_OUT221_CTRL_DEN0_MASK           (0x1U)
#define XBAR_NUM_OUT221_CTRL_DEN0_SHIFT          (0U)
/*! DEN0 - DMA Enable for XBAR_OUT0
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN0_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN0_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN2_MASK           (0x1U)
#define XBAR_NUM_OUT221_CTRL_DEN2_SHIFT          (0U)
/*! DEN2 - DMA Enable for XBAR_OUT2
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN2_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN2_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN0_MASK           (0x2U)
#define XBAR_NUM_OUT221_CTRL_IEN0_SHIFT          (1U)
/*! IEN0 - Interrupt Enable for XBAR_OUT0
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN0_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN0_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN2_MASK           (0x2U)
#define XBAR_NUM_OUT221_CTRL_IEN2_SHIFT          (1U)
/*! IEN2 - Interrupt Enable for XBAR_OUT2
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN2_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN2_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE0_MASK          (0xCU)
#define XBAR_NUM_OUT221_CTRL_EDGE0_SHIFT         (2U)
/*! EDGE0 - Active edge for edge detection on XBAR_OUT0
 *  0b00..STS0 never asserts
 *  0b01..STS0 asserts on rising edges of XBAR_OUT0
 *  0b10..STS0 asserts on falling edges of XBAR_OUT0
 *  0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
 */
#define XBAR_NUM_OUT221_CTRL_EDGE0(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE0_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE0_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE2_MASK          (0xCU)
#define XBAR_NUM_OUT221_CTRL_EDGE2_SHIFT         (2U)
/*! EDGE2 - Active edge for edge detection on XBAR_OUT2
 *  0b00..STS2 never asserts
 *  0b01..STS2 asserts on rising edges of XBAR_OUT2
 *  0b10..STS2 asserts on falling edges of XBAR_OUT2
 *  0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
 */
#define XBAR_NUM_OUT221_CTRL_EDGE2(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE2_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE2_MASK)

#define XBAR_NUM_OUT221_CTRL_STS0_MASK           (0x10U)
#define XBAR_NUM_OUT221_CTRL_STS0_SHIFT          (4U)
/*! STS0 - Edge detection status for XBAR_OUT0
 *  0b0..Active edge not yet detected on XBAR_OUT0
 *  0b1..Active edge detected on XBAR_OUT0
 */
#define XBAR_NUM_OUT221_CTRL_STS0(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS0_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS0_MASK)

#define XBAR_NUM_OUT221_CTRL_STS2_MASK           (0x10U)
#define XBAR_NUM_OUT221_CTRL_STS2_SHIFT          (4U)
/*! STS2 - Edge detection status for XBAR_OUT2
 *  0b0..Active edge not yet detected on XBAR_OUT2
 *  0b1..Active edge detected on XBAR_OUT2
 */
#define XBAR_NUM_OUT221_CTRL_STS2(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS2_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS2_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN1_MASK           (0x100U)
#define XBAR_NUM_OUT221_CTRL_DEN1_SHIFT          (8U)
/*! DEN1 - DMA Enable for XBAR_OUT1
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN1_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN1_MASK)

#define XBAR_NUM_OUT221_CTRL_DEN3_MASK           (0x100U)
#define XBAR_NUM_OUT221_CTRL_DEN3_SHIFT          (8U)
/*! DEN3 - DMA Enable for XBAR_OUT3
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBAR_NUM_OUT221_CTRL_DEN3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_DEN3_SHIFT)) & XBAR_NUM_OUT221_CTRL_DEN3_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN1_MASK           (0x200U)
#define XBAR_NUM_OUT221_CTRL_IEN1_SHIFT          (9U)
/*! IEN1 - Interrupt Enable for XBAR_OUT1
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN1_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN1_MASK)

#define XBAR_NUM_OUT221_CTRL_IEN3_MASK           (0x200U)
#define XBAR_NUM_OUT221_CTRL_IEN3_SHIFT          (9U)
/*! IEN3 - Interrupt Enable for XBAR_OUT3
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBAR_NUM_OUT221_CTRL_IEN3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_IEN3_SHIFT)) & XBAR_NUM_OUT221_CTRL_IEN3_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE1_MASK          (0xC00U)
#define XBAR_NUM_OUT221_CTRL_EDGE1_SHIFT         (10U)
/*! EDGE1 - Active edge for edge detection on XBAR_OUT1
 *  0b00..STS1 never asserts
 *  0b01..STS1 asserts on rising edges of XBAR_OUT1
 *  0b10..STS1 asserts on falling edges of XBAR_OUT1
 *  0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
 */
#define XBAR_NUM_OUT221_CTRL_EDGE1(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE1_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE1_MASK)

#define XBAR_NUM_OUT221_CTRL_EDGE3_MASK          (0xC00U)
#define XBAR_NUM_OUT221_CTRL_EDGE3_SHIFT         (10U)
/*! EDGE3 - Active edge for edge detection on XBAR_OUT3
 *  0b00..STS3 never asserts
 *  0b01..STS3 asserts on rising edges of XBAR_OUT3
 *  0b10..STS3 asserts on falling edges of XBAR_OUT3
 *  0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
 */
#define XBAR_NUM_OUT221_CTRL_EDGE3(x)            (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_EDGE3_SHIFT)) & XBAR_NUM_OUT221_CTRL_EDGE3_MASK)

#define XBAR_NUM_OUT221_CTRL_STS1_MASK           (0x1000U)
#define XBAR_NUM_OUT221_CTRL_STS1_SHIFT          (12U)
/*! STS1 - Edge detection status for XBAR_OUT1
 *  0b0..Active edge not yet detected on XBAR_OUT1
 *  0b1..Active edge detected on XBAR_OUT1
 */
#define XBAR_NUM_OUT221_CTRL_STS1(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS1_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS1_MASK)

#define XBAR_NUM_OUT221_CTRL_STS3_MASK           (0x1000U)
#define XBAR_NUM_OUT221_CTRL_STS3_SHIFT          (12U)
/*! STS3 - Edge detection status for XBAR_OUT3
 *  0b0..Active edge not yet detected on XBAR_OUT3
 *  0b1..Active edge detected on XBAR_OUT3
 */
#define XBAR_NUM_OUT221_CTRL_STS3(x)             (((uint16_t)(((uint16_t)(x)) << XBAR_NUM_OUT221_CTRL_STS3_SHIFT)) & XBAR_NUM_OUT221_CTRL_STS3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT221_Register_Masks */


/*!
 * @}
 */ /* end of group XBAR_NUM_OUT221_Peripheral_Access_Layer */


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


#endif  /* PERI_XBAR_NUM_OUT221_H_ */

