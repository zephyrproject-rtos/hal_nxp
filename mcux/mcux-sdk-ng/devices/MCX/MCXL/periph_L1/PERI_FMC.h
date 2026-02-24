/*
** ###################################################################
**     Processors:          MCXL142VDH_cm0plus
**                          MCXL142VDH_cm33
**                          MCXL142VLL_cm0plus
**                          MCXL142VLL_cm33
**                          MCXL143VDH_cm0plus
**                          MCXL143VDH_cm33
**                          MCXL143VLL_cm0plus
**                          MCXL143VLL_cm33
**                          MCXL144VDH_cm0plus
**                          MCXL144VDH_cm33
**                          MCXL144VLL_cm0plus
**                          MCXL144VLL_cm33
**
**     Version:             rev. 1.1, 2026-01-02
**     Build:               b260109
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-06-13)
**         Generated based on Rev1 DraftH.
**     - rev. 1.1 (2026-01-02)
**         Generated based on Rev.1 RC.
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 1.1
 * @date 2026-01-02
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL142VDH_cm0plus) || defined(CPU_MCXL142VLL_cm0plus))
#include "MCXL142_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL142VDH_cm33) || defined(CPU_MCXL142VLL_cm33))
#include "MCXL142_cm33_COMMON.h"
#elif (defined(CPU_MCXL143VDH_cm0plus) || defined(CPU_MCXL143VLL_cm0plus))
#include "MCXL143_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL143VDH_cm33) || defined(CPU_MCXL143VLL_cm33))
#include "MCXL143_cm33_COMMON.h"
#elif (defined(CPU_MCXL144VDH_cm0plus) || defined(CPU_MCXL144VLL_cm0plus))
#include "MCXL144_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL144VDH_cm33) || defined(CPU_MCXL144VLL_cm33))
#include "MCXL144_cm33_COMMON.h"
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
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t REMAP;                             /**< Data Remap, offset: 0x20 */
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name REMAP - Data Remap */
/*! @{ */

#define FMC_REMAP_REMAPLK_MASK                   (0x1U)
#define FMC_REMAP_REMAPLK_SHIFT                  (0U)
/*! REMAPLK - Remap Lock Enable
 *  0b0..Lock disabled: can write to REMAP
 *  0b1..Lock enabled: cannot write to REMAP
 */
#define FMC_REMAP_REMAPLK(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_REMAPLK_SHIFT)) & FMC_REMAP_REMAPLK_MASK)

#define FMC_REMAP_LIM_MASK                       (0x1F0000U)
#define FMC_REMAP_LIM_SHIFT                      (16U)
/*! LIM - LIM Remapping Address */
#define FMC_REMAP_LIM(x)                         (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_LIM_SHIFT)) & FMC_REMAP_LIM_MASK)

#define FMC_REMAP_LIMDP_MASK                     (0x1F000000U)
#define FMC_REMAP_LIMDP_SHIFT                    (24U)
/*! LIMDP - LIMDP Remapping Address */
#define FMC_REMAP_LIMDP(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_LIMDP_SHIFT)) & FMC_REMAP_LIMDP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


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


#endif  /* PERI_FMC_H_ */

