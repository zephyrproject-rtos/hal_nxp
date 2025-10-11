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
**         CMSIS Peripheral Access Layer for RSTCTL2
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
 * @file PERI_RSTCTL2.h
 * @version 4.0
 * @date 2025-06-06
 * @brief CMSIS Peripheral Access Layer for RSTCTL2
 *
 * CMSIS Peripheral Access Layer for RSTCTL2
 */

#if !defined(PERI_RSTCTL2_H_)
#define PERI_RSTCTL2_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL2_Peripheral_Access_Layer RSTCTL2 Peripheral Access Layer
 * @{
 */

/** RSTCTL2 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PRSTCTL0;                          /**< VDDN Domain Peripheral Reset Control 0, offset: 0x10 */
       uint8_t RESERVED_1[44];
  __O  uint32_t PRSTCTL0_SET;                      /**< VDDN Domain Peripheral Reset Control 0 SET, offset: 0x40 */
       uint8_t RESERVED_2[44];
  __O  uint32_t PRSTCTL0_CLR;                      /**< VDDN Domain Peripheral Reset Control 0 CLR, offset: 0x70 */
} RSTCTL2_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL2_Register_Masks RSTCTL2 Register Masks
 * @{
 */

/*! @name PRSTCTL0 - VDDN Domain Peripheral Reset Control 0 */
/*! @{ */

#define RSTCTL2_PRSTCTL0_IOPCTL2_MASK            (0x2U)
#define RSTCTL2_PRSTCTL0_IOPCTL2_SHIFT           (1U)
/*! IOPCTL2 - IOPCTL2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL2_PRSTCTL0_IOPCTL2(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL2_PRSTCTL0_IOPCTL2_SHIFT)) & RSTCTL2_PRSTCTL0_IOPCTL2_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - VDDN Domain Peripheral Reset Control 0 SET */
/*! @{ */

#define RSTCTL2_PRSTCTL0_SET_IOPCTL2_MASK        (0x2U)
#define RSTCTL2_PRSTCTL0_SET_IOPCTL2_SHIFT       (1U)
/*! IOPCTL2 - IOPCTL2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL2_PRSTCTL0_SET_IOPCTL2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL2_PRSTCTL0_SET_IOPCTL2_SHIFT)) & RSTCTL2_PRSTCTL0_SET_IOPCTL2_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - VDDN Domain Peripheral Reset Control 0 CLR */
/*! @{ */

#define RSTCTL2_PRSTCTL0_CLR_IOPCTL2_MASK        (0x2U)
#define RSTCTL2_PRSTCTL0_CLR_IOPCTL2_SHIFT       (1U)
/*! IOPCTL2 - IOPCTL2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL2_PRSTCTL0_CLR_IOPCTL2(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL2_PRSTCTL0_CLR_IOPCTL2_SHIFT)) & RSTCTL2_PRSTCTL0_CLR_IOPCTL2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL2_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL2_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL2_H_ */

