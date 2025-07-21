/*
** ###################################################################
**     Processors:          MCXA144VFT
**                          MCXA144VLH
**                          MCXA144VLL
**                          MCXA144VMP
**                          MCXA144VPJ
**                          MCXA145VFT
**                          MCXA145VLH
**                          MCXA145VLL
**                          MCXA145VMP
**                          MCXA145VPJ
**                          MCXA146VFT
**                          MCXA146VLH
**                          MCXA146VLL
**                          MCXA146VMP
**                          MCXA146VPJ
**                          MCXA154VFT
**                          MCXA154VLH
**                          MCXA154VLL
**                          MCXA154VMP
**                          MCXA154VPJ
**                          MCXA155VFT
**                          MCXA155VLH
**                          MCXA155VLL
**                          MCXA155VMP
**                          MCXA155VPJ
**                          MCXA156VFT
**                          MCXA156VLH
**                          MCXA156VLL
**                          MCXA156VMP
**                          MCXA156VPJ
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VBAT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-29)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VBAT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VBAT
 *
 * CMSIS Peripheral Access Layer for VBAT
 */

#if !defined(PERI_VBAT_H_)
#define PERI_VBAT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA144VFT) || defined(CPU_MCXA144VLH) || defined(CPU_MCXA144VLL) || defined(CPU_MCXA144VMP) || defined(CPU_MCXA144VPJ))
#include "MCXA144_COMMON.h"
#elif (defined(CPU_MCXA145VFT) || defined(CPU_MCXA145VLH) || defined(CPU_MCXA145VLL) || defined(CPU_MCXA145VMP) || defined(CPU_MCXA145VPJ))
#include "MCXA145_COMMON.h"
#elif (defined(CPU_MCXA146VFT) || defined(CPU_MCXA146VLH) || defined(CPU_MCXA146VLL) || defined(CPU_MCXA146VMP) || defined(CPU_MCXA146VPJ))
#include "MCXA146_COMMON.h"
#elif (defined(CPU_MCXA154VFT) || defined(CPU_MCXA154VLH) || defined(CPU_MCXA154VLL) || defined(CPU_MCXA154VMP) || defined(CPU_MCXA154VPJ))
#include "MCXA154_COMMON.h"
#elif (defined(CPU_MCXA155VFT) || defined(CPU_MCXA155VLH) || defined(CPU_MCXA155VLL) || defined(CPU_MCXA155VMP) || defined(CPU_MCXA155VPJ))
#include "MCXA155_COMMON.h"
#elif (defined(CPU_MCXA156VFT) || defined(CPU_MCXA156VLH) || defined(CPU_MCXA156VLL) || defined(CPU_MCXA156VMP) || defined(CPU_MCXA156VPJ))
#include "MCXA156_COMMON.h"
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
   -- VBAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Peripheral_Access_Layer VBAT Peripheral Access Layer
 * @{
 */

/** VBAT - Size of Registers Arrays */
#define VBAT_WAKEUP_COUNT                         2u

/** VBAT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[508];
  __IO uint32_t FROCTLA;                           /**< FRO16K Control A, offset: 0x200 */
       uint8_t RESERVED_1[20];
  __IO uint32_t FROLCKA;                           /**< FRO16K Lock A, offset: 0x218 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FROCLKE;                           /**< FRO16K Clock Enable, offset: 0x220 */
       uint8_t RESERVED_3[1244];
  struct {                                         /* offset: 0x700, array step: 0x8 */
    __IO uint32_t WAKEUPA;                           /**< Wakeup 0 Register A, array offset: 0x700, array step: 0x8 */
         uint8_t RESERVED_0[4];
  } WAKEUP[VBAT_WAKEUP_COUNT];
       uint8_t RESERVED_4[232];
  __IO uint32_t WAKLCKA;                           /**< Wakeup Lock A, offset: 0x7F8 */
} VBAT_Type;

/* ----------------------------------------------------------------------------
   -- VBAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Register_Masks VBAT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VBAT_VERID_FEATURE_MASK                  (0xFFFFU)
#define VBAT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number */
#define VBAT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_FEATURE_SHIFT)) & VBAT_VERID_FEATURE_MASK)

#define VBAT_VERID_MINOR_MASK                    (0xFF0000U)
#define VBAT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define VBAT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MINOR_SHIFT)) & VBAT_VERID_MINOR_MASK)

#define VBAT_VERID_MAJOR_MASK                    (0xFF000000U)
#define VBAT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define VBAT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MAJOR_SHIFT)) & VBAT_VERID_MAJOR_MASK)
/*! @} */

/*! @name FROCTLA - FRO16K Control A */
/*! @{ */

#define VBAT_FROCTLA_FRO_EN_MASK                 (0x1U)
#define VBAT_FROCTLA_FRO_EN_SHIFT                (0U)
/*! FRO_EN - FRO16K Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_FROCTLA_FRO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_FROCTLA_FRO_EN_SHIFT)) & VBAT_FROCTLA_FRO_EN_MASK)
/*! @} */

/*! @name FROLCKA - FRO16K Lock A */
/*! @{ */

#define VBAT_FROLCKA_LOCK_MASK                   (0x1U)
#define VBAT_FROLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_FROLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROLCKA_LOCK_SHIFT)) & VBAT_FROLCKA_LOCK_MASK)
/*! @} */

/*! @name FROCLKE - FRO16K Clock Enable */
/*! @{ */

#define VBAT_FROCLKE_CLKE_MASK                   (0x3U)
#define VBAT_FROCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_FROCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROCLKE_CLKE_SHIFT)) & VBAT_FROCLKE_CLKE_MASK)
/*! @} */

/*! @name WAKEUP_WAKEUPA - Wakeup 0 Register A */
/*! @{ */

#define VBAT_WAKEUP_WAKEUPA_REG_MASK             (0xFFFFFFFFU)
#define VBAT_WAKEUP_WAKEUPA_REG_SHIFT            (0U)
/*! REG - Register */
#define VBAT_WAKEUP_WAKEUPA_REG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKEUP_WAKEUPA_REG_SHIFT)) & VBAT_WAKEUP_WAKEUPA_REG_MASK)
/*! @} */

/* The count of VBAT_WAKEUP_WAKEUPA */
#define VBAT_WAKEUP_WAKEUPA_COUNT                (2U)

/*! @name WAKLCKA - Wakeup Lock A */
/*! @{ */

#define VBAT_WAKLCKA_LOCK_MASK                   (0x1U)
#define VBAT_WAKLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is disabled
 *  0b1..Lock is enabled
 */
#define VBAT_WAKLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_WAKLCKA_LOCK_SHIFT)) & VBAT_WAKLCKA_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VBAT_Register_Masks */


/*!
 * @}
 */ /* end of group VBAT_Peripheral_Access_Layer */


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


#endif  /* PERI_VBAT_H_ */

