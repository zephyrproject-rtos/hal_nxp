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
**         CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
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
 * @file PERI_BLK_CTRL_NS_AONMIX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_NS_AONMIX
 */

#if !defined(PERI_BLK_CTRL_NS_AONMIX_H_)
#define PERI_BLK_CTRL_NS_AONMIX_H_               /**< Symbol preventing repeated inclusion */

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
   -- BLK_CTRL_NS_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer BLK_CTRL_NS_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_NS_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPC_CFG;                           /**< GPC CORE SLEEP Request Select, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IPG_DEBUG;                         /**< IPG Debug mask, offset: 0x8 */
       uint8_t RESERVED_1[16];
  __IO uint32_t SSI;                               /**< offset: 0x1C */
  __IO uint32_t SAI1_MCLK_CTRL;                    /**< SAI1 MCLK control register, offset: 0x20 */
  __IO uint32_t DCDC_STATUS;                       /**< DCDC status register, offset: 0x24 */
  __I  uint32_t FUSE_ACC_DIS;                      /**< Fuse access disable register, offset: 0x28 */
  __IO uint32_t M33_NMI_CLR;                       /**< M33 NMI interrupt clear register, offset: 0x2C */
  __IO uint32_t I3C1_ASYNC_WAKEUP_CTRL;            /**< I3C1 async wakeup control register, offset: 0x30 */
  __IO uint32_t MISC_IO_CTRL;                      /**< Miscellaneous control register of IO, offset: 0x34 */
} BLK_CTRL_NS_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_NS_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_NS_AONMIX_Register_Masks BLK_CTRL_NS_AONMIX Register Masks
 * @{
 */

/*! @name GPC_CFG - GPC CORE SLEEP Request Select */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT (0U)
/*! M33_SLEEP_SEL - M33 SLEEP Request Select
 *  0b0..Select SLEEPING as request source
 *  0b1..Select SLEEPDEEP as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M33_SLEEP_SEL_MASK)

#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT (1U)
/*! M7_SLEEP_SEL - M7 SLEEP Request Select
 *  0b0..Select SLEEPING as request source
 *  0b1..Select SLEEPDEEP as request source
 */
#define BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_SHIFT)) & BLK_CTRL_NS_AONMIX_GPC_CFG_M7_SLEEP_SEL_MASK)
/*! @} */

/*! @name IPG_DEBUG - IPG Debug mask */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN1_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN1_SHIFT (0U)
/*! M33_CAN1 - Mask bit for CAN1 debug halted mode with M33 core
 *  0b0..CAN1 does not enter debug halted mode with CM33
 *  0b1..CAN1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_EDMA3_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_EDMA3_SHIFT (1U)
/*! M33_EDMA3 - Mask bit for EDMA3 debug halted mode with M33 core
 *  0b0..EDMA3 does not enter debug halted mode with CM33
 *  0b1..EDMA3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_EDMA3_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_EDMA3_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C1_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C1_SHIFT (2U)
/*! M33_LPI2C1 - Mask bit for LPI2C1 debug halted mode with M33 core
 *  0b0..LPI2C1 does not enter debug halted mode with CM33
 *  0b1..LPI2C1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C2_MASK (0x8U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C2_SHIFT (3U)
/*! M33_LPI2C2 - Mask bit for LPI2C2 debug halted mode with M33 core
 *  0b0..LPI2C2 does not enter debug halted mode with CM33
 *  0b1..LPI2C2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPIT1_MASK (0x10U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPIT1_SHIFT (4U)
/*! M33_LPIT1 - Mask bit for LPIT1 debug halted mode with M33 core
 *  0b0..LPIT1 does not enter debug halted mode with CM33
 *  0b1..LPIT1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI1_MASK (0x20U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI1_SHIFT (5U)
/*! M33_LPSPI1 - Mask bit for LPSPI1 debug halted mode with M33 core
 *  0b0..LPSPI1 does not enter debug halted mode with CM33
 *  0b1..LPSPI1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI2_MASK (0x40U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI2_SHIFT (6U)
/*! M33_LPSPI2 - Mask bit for LPSPI2 debug halted mode with M33 core
 *  0b0..LPSPI2 does not enter debug halted mode with CM33
 *  0b1..LPSPI2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPTMR1_MASK (0x80U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPTMR1_SHIFT (7U)
/*! M33_LPTMR1 - Mask bit for LPTMR1 debug halted mode with M33 core
 *  0b0..LPTMR1 does not enter debug halted mode with CM33
 *  0b1..LPTMR1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_SAI1_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_SAI1_SHIFT (8U)
/*! M33_SAI1 - Mask bit for SAI1 debug halted mode with M33 core
 *  0b0..SAI1 does not enter debug halted mode with CM33
 *  0b1..SAI1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_SAI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM1_MASK (0x200U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM1_SHIFT (9U)
/*! M33_TPM1 - Mask bit for TPM1 debug halted mode with M33 core
 *  0b0..TPM1 does not enter debug halted mode with CM33
 *  0b1..TPM1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM2_MASK (0x400U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM2_SHIFT (10U)
/*! M33_TPM2 - Mask bit for TPM2 debug halted mode with M33 core
 *  0b0..TPM2 does not enter debug halted mode with CM33
 *  0b1..TPM2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG1_MASK (0x800U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG1_SHIFT (11U)
/*! M33_WDOG1 - Mask bit for WDOG1 debug halted mode with M33 core
 *  0b0..WDOG1 does not enter debug halted mode with CM33
 *  0b1..WDOG1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG2_MASK (0x1000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG2_SHIFT (12U)
/*! M33_WDOG2 - Mask bit for WDOG2 debug halted mode with M33 core
 *  0b0..WDOG2 does not enter debug halted mode with CM33
 *  0b1..WDOG2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_GPT1_MASK (0x2000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_GPT1_SHIFT (13U)
/*! M33_GPT1 - Mask bit for GPT1 debug halted mode with M33 core
 *  0b0..GPT1 does not enter debug halted mode with CM33
 *  0b1..GPT1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_GPT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_GPT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_GPT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN3_MASK (0x4000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN3_SHIFT (14U)
/*! M33_CAN3 - Mask bit for CAN3 debug halted mode with M33 core
 *  0b0..CAN3 does not enter debug halted mode with CM33
 *  0b1..CAN3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN3_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_CAN3_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_I3C1_MASK (0x8000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_I3C1_SHIFT (15U)
/*! M33_I3C1 - Mask bit for I3C1 debug halted mode with M33 core
 *  0b0..I3C1 does not enter debug halted mode with CM33
 *  0b1..I3C1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_I3C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M33_I3C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN1_MASK (0x10000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN1_SHIFT (16U)
/*! M7_CAN1 - Mask bit for CAN1 debug halted mode with M7 core
 *  0b0..CAN1 does not enter debug halted mode with CM7
 *  0b1..CAN1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_EDMA3_MASK (0x20000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_EDMA3_SHIFT (17U)
/*! M7_EDMA3 - Mask bit for EDMA3 debug halted mode with M7 core
 *  0b0..EDMA3 does not enter debug halted mode with CM7
 *  0b1..EDMA3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_EDMA3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_EDMA3_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_EDMA3_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C1_MASK (0x40000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C1_SHIFT (18U)
/*! M7_LPI2C1 - Mask bit for LPI2C1 debug halted mode with M7 core
 *  0b0..LPI2C1 does not enter debug halted mode with CM7
 *  0b1..LPI2C1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C2_MASK (0x80000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C2_SHIFT (19U)
/*! M7_LPI2C2 - Mask bit for LPI2C2 debug halted mode with M7 core
 *  0b0..LPI2C2 does not enter debug halted mode with CM7
 *  0b1..LPI2C2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPI2C2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPIT1_MASK (0x100000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPIT1_SHIFT (20U)
/*! M7_LPIT1 - Mask bit for LPIT1 debug halted mode with M7 core
 *  0b0..LPIT1 does not enter debug halted mode with CM7
 *  0b1..LPIT1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPIT1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPIT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPIT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI1_MASK (0x200000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI1_SHIFT (21U)
/*! M7_LPSPI1 - Mask bit for LPSPI1 debug halted mode with M7 core
 *  0b0..LPSPI1 does not enter debug halted mode with CM7
 *  0b1..LPSPI1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI2_MASK (0x400000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI2_SHIFT (22U)
/*! M7_LPSPI2 - Mask bit for LPSPI2 debug halted mode with M7 core
 *  0b0..LPSPI2 does not enter debug halted mode with CM7
 *  0b1..LPSPI2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPSPI2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPTMR1_MASK (0x800000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPTMR1_SHIFT (23U)
/*! M7_LPTMR1 - Mask bit for LPTMR1 debug halted mode with M7 core
 *  0b0..LPTMR1 does not enter debug halted mode with CM7
 *  0b1..LPTMR1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPTMR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPTMR1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_LPTMR1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_SAI1_MASK (0x1000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_SAI1_SHIFT (24U)
/*! M7_SAI1 - Mask bit for SAI1 debug halted mode with M7 core
 *  0b0..SAI1 does not enter debug halted mode with CM7
 *  0b1..SAI1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_SAI1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_SAI1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_SAI1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM1_MASK (0x2000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM1_SHIFT (25U)
/*! M7_TPM1 - Mask bit for TPM1 debug halted mode with M7 core
 *  0b0..TPM1 does not enter debug halted mode with CM7
 *  0b1..TPM1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM2_MASK (0x4000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM2_SHIFT (26U)
/*! M7_TPM2 - Mask bit for TPM2 debug halted mode with M7 core
 *  0b0..TPM2 does not enter debug halted mode with CM7
 *  0b1..TPM2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM2(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_TPM2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG1_MASK (0x8000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG1_SHIFT (27U)
/*! M7_WDOG1 - Mask bit for WDOG1 debug halted mode with M7 core
 *  0b0..WDOG1 does not enter debug halted mode with CM7
 *  0b1..WDOG1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG2_MASK (0x10000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG2_SHIFT (28U)
/*! M7_WDOG2 - Mask bit for WDOG2 debug halted mode with M7 core
 *  0b0..WDOG2 does not enter debug halted mode with CM7
 *  0b1..WDOG2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG2_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_WDOG2_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_GPT1_MASK (0x20000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_GPT1_SHIFT (29U)
/*! M7_GPT1 - Mask bit for GPT1 debug halted mode with M7 core
 *  0b0..GPT1 does not enter debug halted mode with CM7
 *  0b1..GPT1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_GPT1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_GPT1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_GPT1_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN3_MASK (0x40000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN3_SHIFT (30U)
/*! M7_CAN3 - Mask bit for CAN3 debug halted mode with M7 core
 *  0b0..CAN3 does not enter debug halted mode with CM7
 *  0b1..CAN3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN3(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN3_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_CAN3_MASK)

#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_I3C1_MASK (0x80000000U)
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_I3C1_SHIFT (31U)
/*! M7_I3C1 - Mask bit for I3C1 debug halted mode with M7 core
 *  0b0..I3C1 does not enter debug halted mode with CM7
 *  0b1..I3C1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_I3C1(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_I3C1_SHIFT)) & BLK_CTRL_NS_AONMIX_IPG_DEBUG_M7_I3C1_MASK)
/*! @} */

/*! @name SSI -  */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK   (0x1U)
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT  (0U)
/*! PAUSE_MODE - AON Domain SSI master pause mode
 *  0b0..AON Domain SSI master is not in pause mode
 *  0b1..AON Domain SSI master is in pause mode
 */
#define BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_SHIFT)) & BLK_CTRL_NS_AONMIX_SSI_PAUSE_MODE_MASK)

#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_SHIFT (1U)
/*! BLKHOLE_MODE_B - AON Domain SSI master blackhole mode
 *  0b0..AON Domain SSI master will enter into blackhole mode
 *  0b1..AON Domain SSI master will exit from blackhole mode
 */
#define BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_SHIFT)) & BLK_CTRL_NS_AONMIX_SSI_BLKHOLE_MODE_B_MASK)
/*! @} */

/*! @name SAI1_MCLK_CTRL - SAI1 MCLK control register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_SAI1_MCLK_CTRL_SAI1_MCLK_DIR_MASK (0x100U)
#define BLK_CTRL_NS_AONMIX_SAI1_MCLK_CTRL_SAI1_MCLK_DIR_SHIFT (8U)
/*! SAI1_MCLK_DIR - SAI1_MCLK IO direction control. IOMUX need select SAI1 MCLK function
 *  0b0..SAI1_MCLK is input signal
 *  0b1..SAI1_MCLK is output signal
 */
#define BLK_CTRL_NS_AONMIX_SAI1_MCLK_CTRL_SAI1_MCLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_SAI1_MCLK_CTRL_SAI1_MCLK_DIR_SHIFT)) & BLK_CTRL_NS_AONMIX_SAI1_MCLK_CTRL_SAI1_MCLK_DIR_MASK)
/*! @} */

/*! @name DCDC_STATUS - DCDC status register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STATUS_CAPT_CLR_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STATUS_CAPT_CLR_SHIFT (1U)
/*! DCDC_STATUS_CAPT_CLR - DCDC captured status clear
 *  0b0..No change
 *  0b1..Clear the 3 bits of DCDC captured status: DCDC_OVER_VOL, DCDC_OVER_CUR, and DCDC_IN_LOW_VOL
 */
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STATUS_CAPT_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STATUS_CAPT_CLR_SHIFT)) & BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STATUS_CAPT_CLR_MASK)

#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_IN_LOW_VOL_MASK (0x10000U)
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_IN_LOW_VOL_SHIFT (16U)
/*! DCDC_IN_LOW_VOL - DCDC_IN low voltage detect
 *  0b0..Voltage on DCDC_IN is higher than 2.6V
 *  0b1..Voltage on DCDC_IN is lower than 2.6V
 */
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_IN_LOW_VOL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_IN_LOW_VOL_SHIFT)) & BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_IN_LOW_VOL_MASK)

#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_CUR_MASK (0x20000U)
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_CUR_SHIFT (17U)
/*! DCDC_OVER_CUR - DCDC output over current alert
 *  0b0..No Overcurrent on DCDC output
 *  0b1..Overcurrent on DCDC output
 */
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_CUR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_CUR_SHIFT)) & BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_CUR_MASK)

#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_VOL_MASK (0x40000U)
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_VOL_SHIFT (18U)
/*! DCDC_OVER_VOL - DCDC output over voltage alert
 *  0b0..No Overvoltage on DCDC VDDLP0 or VDDLP8 output
 *  0b1..Overvoltage on DCDC VDDLP0 or VDDLP8 output
 */
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_VOL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_VOL_SHIFT)) & BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_OVER_VOL_MASK)

#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STS_DC_OK_MASK (0x80000U)
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STS_DC_OK_SHIFT (19U)
/*! DCDC_STS_DC_OK - DCDC status OK
 *  0b0..DCDC is settling
 *  0b1..DCDC already settled
 */
#define BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STS_DC_OK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STS_DC_OK_SHIFT)) & BLK_CTRL_NS_AONMIX_DCDC_STATUS_DCDC_STS_DC_OK_MASK)
/*! @} */

/*! @name FUSE_ACC_DIS - Fuse access disable register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT (0U)
/*! OSCCA_FUSE_READ_DIS - Fuse read disable flag
 *  0b0..Read is allowed
 *  0b1..Read is not allowed
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OSCCA_FUSE_READ_DIS_MASK)

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_CALIBRATED_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_CALIBRATED_SHIFT (1U)
/*! OCOTP_CALIBRATED - Fuse calibrate flag
 *  0b0..OCOTP is not calibrated
 *  0b1..OCOTP is calibrated
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_CALIBRATED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_CALIBRATED_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_CALIBRATED_MASK)

#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_BUSY_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_BUSY_SHIFT (2U)
/*! OCOTP_BUSY - OCOTP busy flag
 *  0b0..OCOTP is not busy
 *  0b1..OCOTP is busy
 */
#define BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_BUSY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_BUSY_SHIFT)) & BLK_CTRL_NS_AONMIX_FUSE_ACC_DIS_OCOTP_BUSY_MASK)
/*! @} */

/*! @name M33_NMI_CLR - M33 NMI interrupt clear register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_M33_NMI_CLR_M33_NMI_CLEAR_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_M33_NMI_CLR_M33_NMI_CLEAR_SHIFT (0U)
/*! M33_NMI_CLEAR - Clear CM33 NMI holding register */
#define BLK_CTRL_NS_AONMIX_M33_NMI_CLR_M33_NMI_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_M33_NMI_CLR_M33_NMI_CLEAR_SHIFT)) & BLK_CTRL_NS_AONMIX_M33_NMI_CLR_M33_NMI_CLEAR_MASK)
/*! @} */

/*! @name I3C1_ASYNC_WAKEUP_CTRL - I3C1 async wakeup control register */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_CLR_SHIFT (0U)
/*! IRQ_CLR - Async wakeup interrupt clear */
#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_CLR_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_CLR_MASK)

#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_STATUS_MASK (0x10000U)
#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_STATUS_SHIFT (16U)
/*! IRQ_STATUS - Async wakeup interrupt status
 *  0b0..Interrupt not asserted
 *  0b1..Interrupt asserted
 */
#define BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_STATUS_SHIFT)) & BLK_CTRL_NS_AONMIX_I3C1_ASYNC_WAKEUP_CTRL_IRQ_STATUS_MASK)
/*! @} */

/*! @name MISC_IO_CTRL - Miscellaneous control register of IO */
/*! @{ */

#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_MASK (0x1U)
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_SHIFT (0U)
/*! I3C_ON_CHIP_STRONG_PULL_DIS - Disable I3C on-chip strong pull for I3C1
 *  0b0..On-chip strong pull is enabled
 *  0b1..On-chip strong pull is disabled
 */
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_SHIFT)) & BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_MASK)

#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_HIGH_RANGE_MASK (0x2U)
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_HIGH_RANGE_SHIFT (1U)
/*! GPIO_AON_HIGH_RANGE - GPIO_AON IO bank supply voltage range selection */
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_HIGH_RANGE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_HIGH_RANGE_SHIFT)) & BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_HIGH_RANGE_MASK)

#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_LOW_RANGE_MASK (0x4U)
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_LOW_RANGE_SHIFT (2U)
/*! GPIO_AON_LOW_RANGE - GPIO_AON IO bank supply voltage range selection */
#define BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_LOW_RANGE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_LOW_RANGE_SHIFT)) & BLK_CTRL_NS_AONMIX_MISC_IO_CTRL_GPIO_AON_LOW_RANGE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_NS_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_NS_AONMIX_H_ */

