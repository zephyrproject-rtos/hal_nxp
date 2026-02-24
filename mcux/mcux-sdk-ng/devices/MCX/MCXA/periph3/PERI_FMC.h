/*
** ###################################################################
**     Processors:          MCXA173VFM
**                          MCXA173VLF
**                          MCXA173VLH
**                          MCXA173VLL
**                          MCXA174VFM
**                          MCXA174VLF
**                          MCXA174VLH
**                          MCXA174VLL
**                          MCXA183VFM
**                          MCXA183VLF
**                          MCXA183VLH
**                          MCXA183VLL
**                          MCXA184VFM
**                          MCXA184VLF
**                          MCXA184VLH
**                          MCXA184VLL
**                          MCXA343VFM
**                          MCXA343VLF
**                          MCXA343VLH
**                          MCXA343VLL
**                          MCXA344VFM
**                          MCXA344VLF
**                          MCXA344VLH
**                          MCXA344VLL
**                          MCXA353VFM
**                          MCXA353VLF
**                          MCXA353VLH
**                          MCXA353VLL
**                          MCXA354VFM
**                          MCXA354VLF
**                          MCXA354VLH
**                          MCXA354VLL
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b251111
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-26)
**         Initial version based on Rev1 DraftC RM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA173VFM) || defined(CPU_MCXA173VLF) || defined(CPU_MCXA173VLH) || defined(CPU_MCXA173VLL))
#include "MCXA173_COMMON.h"
#elif (defined(CPU_MCXA174VFM) || defined(CPU_MCXA174VLF) || defined(CPU_MCXA174VLH) || defined(CPU_MCXA174VLL))
#include "MCXA174_COMMON.h"
#elif (defined(CPU_MCXA183VFM) || defined(CPU_MCXA183VLF) || defined(CPU_MCXA183VLH) || defined(CPU_MCXA183VLL))
#include "MCXA183_COMMON.h"
#elif (defined(CPU_MCXA184VFM) || defined(CPU_MCXA184VLF) || defined(CPU_MCXA184VLH) || defined(CPU_MCXA184VLL))
#include "MCXA184_COMMON.h"
#elif (defined(CPU_MCXA343VFM) || defined(CPU_MCXA343VLF) || defined(CPU_MCXA343VLH) || defined(CPU_MCXA343VLL))
#include "MCXA343_COMMON.h"
#elif (defined(CPU_MCXA344VFM) || defined(CPU_MCXA344VLF) || defined(CPU_MCXA344VLH) || defined(CPU_MCXA344VLL))
#include "MCXA344_COMMON.h"
#elif (defined(CPU_MCXA353VFM) || defined(CPU_MCXA353VLF) || defined(CPU_MCXA353VLH) || defined(CPU_MCXA353VLL))
#include "MCXA353_COMMON.h"
#elif (defined(CPU_MCXA354VFM) || defined(CPU_MCXA354VLF) || defined(CPU_MCXA354VLH) || defined(CPU_MCXA354VLL))
#include "MCXA354_COMMON.h"
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

#define FMC_REMAP_LIM_MASK                       (0x7F0000U)
#define FMC_REMAP_LIM_SHIFT                      (16U)
/*! LIM - LIM Remapping Address */
#define FMC_REMAP_LIM(x)                         (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_LIM_SHIFT)) & FMC_REMAP_LIM_MASK)

#define FMC_REMAP_LIMDP_MASK                     (0x7F000000U)
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

