/*
** ###################################################################
**     Processors:          MIMXRT735SGAWBR_cm33_core0
**                          MIMXRT735SGAWBR_cm33_core1
**                          MIMXRT735SGAWBR_ezhv
**                          MIMXRT735SGAWBR_hifi1
**                          MIMXRT735SGFOB_cm33_core0
**                          MIMXRT735SGFOB_cm33_core1
**                          MIMXRT735SGFOB_ezhv
**                          MIMXRT735SGFOB_hifi1
**                          MIMXRT758SGAWBR_cm33_core0
**                          MIMXRT758SGAWBR_cm33_core1
**                          MIMXRT758SGAWBR_ezhv
**                          MIMXRT758SGAWBR_hifi1
**                          MIMXRT758SGFOB_cm33_core0
**                          MIMXRT758SGFOB_cm33_core1
**                          MIMXRT758SGFOB_ezhv
**                          MIMXRT758SGFOB_hifi1
**                          MIMXRT798SGAWBR_cm33_core0
**                          MIMXRT798SGAWBR_cm33_core1
**                          MIMXRT798SGAWBR_ezhv
**                          MIMXRT798SGAWBR_hifi1
**                          MIMXRT798SGAWBR_hifi4
**                          MIMXRT798SGFOB_cm33_core0
**                          MIMXRT798SGFOB_cm33_core1
**                          MIMXRT798SGFOB_ezhv
**                          MIMXRT798SGFOB_hifi1
**                          MIMXRT798SGFOB_hifi4
**
**     Version:             rev. 4.0, 2025-06-06
**     Build:               b250722
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CACHE64_POLSEL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 4.0 (2025-06-06)
**         B0 initial version
**
** ###################################################################
*/

/*!
 * @file PERI_CACHE64_POLSEL.h
 * @version 4.0
 * @date 2025-06-06
 * @brief CMSIS Peripheral Access Layer for CACHE64_POLSEL
 *
 * CMSIS Peripheral Access Layer for CACHE64_POLSEL
 */

#if !defined(PERI_CACHE64_POLSEL_H_)
#define PERI_CACHE64_POLSEL_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWBR_cm33_core0) || defined(CPU_MIMXRT735SGFOB_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_cm33_core1) || defined(CPU_MIMXRT735SGFOB_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_ezhv) || defined(CPU_MIMXRT735SGFOB_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_hifi1) || defined(CPU_MIMXRT735SGFOB_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_cm33_core0) || defined(CPU_MIMXRT758SGFOB_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_cm33_core1) || defined(CPU_MIMXRT758SGFOB_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_ezhv) || defined(CPU_MIMXRT758SGFOB_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_hifi1) || defined(CPU_MIMXRT758SGFOB_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_cm33_core0) || defined(CPU_MIMXRT798SGFOB_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_cm33_core1) || defined(CPU_MIMXRT798SGFOB_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_ezhv) || defined(CPU_MIMXRT798SGFOB_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi1) || defined(CPU_MIMXRT798SGFOB_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi4) || defined(CPU_MIMXRT798SGFOB_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- CACHE64_POLSEL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_POLSEL_Peripheral_Access_Layer CACHE64_POLSEL Peripheral Access Layer
 * @{
 */

/** CACHE64_POLSEL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[20];
  __IO uint32_t REG0_TOP;                          /**< Region 0 Top Boundary, offset: 0x14 */
  __IO uint32_t REG1_TOP;                          /**< Region 1 Top Boundary, offset: 0x18 */
  __IO uint32_t POLSEL;                            /**< Policy Select, offset: 0x1C */
} CACHE64_POLSEL_Type;

/* ----------------------------------------------------------------------------
   -- CACHE64_POLSEL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CACHE64_POLSEL_Register_Masks CACHE64_POLSEL Register Masks
 * @{
 */

/*! @name REG0_TOP - Region 0 Top Boundary */
/*! @{ */

#define CACHE64_POLSEL_REG0_TOP_REG0_TOP_MASK    (0x7FFFC00U)
#define CACHE64_POLSEL_REG0_TOP_REG0_TOP_SHIFT   (10U)
/*! REG0_TOP - Upper Limit Of Region 0 */
#define CACHE64_POLSEL_REG0_TOP_REG0_TOP(x)      (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_REG0_TOP_REG0_TOP_SHIFT)) & CACHE64_POLSEL_REG0_TOP_REG0_TOP_MASK)
/*! @} */

/*! @name REG1_TOP - Region 1 Top Boundary */
/*! @{ */

#define CACHE64_POLSEL_REG1_TOP_REG1_TOP_MASK    (0x7FFFC00U)
#define CACHE64_POLSEL_REG1_TOP_REG1_TOP_SHIFT   (10U)
/*! REG1_TOP - Upper Limit Of Region 1 */
#define CACHE64_POLSEL_REG1_TOP_REG1_TOP(x)      (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_REG1_TOP_REG1_TOP_SHIFT)) & CACHE64_POLSEL_REG1_TOP_REG1_TOP_MASK)
/*! @} */

/*! @name POLSEL - Policy Select */
/*! @{ */

#define CACHE64_POLSEL_POLSEL_REG0_POLICY_MASK   (0x3U)
#define CACHE64_POLSEL_POLSEL_REG0_POLICY_SHIFT  (0U)
/*! REG0_POLICY - Policy Select For Region 0
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG0_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG0_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG0_POLICY_MASK)

#define CACHE64_POLSEL_POLSEL_REG1_POLICY_MASK   (0xCU)
#define CACHE64_POLSEL_POLSEL_REG1_POLICY_SHIFT  (2U)
/*! REG1_POLICY - Policy Select For Region 1
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG1_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG1_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG1_POLICY_MASK)

#define CACHE64_POLSEL_POLSEL_REG2_POLICY_MASK   (0x30U)
#define CACHE64_POLSEL_POLSEL_REG2_POLICY_SHIFT  (4U)
/*! REG2_POLICY - Policy Select For Region 2
 *  0b00..Noncacheable
 *  0b01..Write-through
 *  0b10..Write-back
 *  0b11..Invalid
 */
#define CACHE64_POLSEL_POLSEL_REG2_POLICY(x)     (((uint32_t)(((uint32_t)(x)) << CACHE64_POLSEL_POLSEL_REG2_POLICY_SHIFT)) & CACHE64_POLSEL_POLSEL_REG2_POLICY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CACHE64_POLSEL_Register_Masks */


/*!
 * @}
 */ /* end of group CACHE64_POLSEL_Peripheral_Access_Layer */


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


#endif  /* PERI_CACHE64_POLSEL_H_ */

