/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GICA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_GICA.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for GICA
 *
 * CMSIS Peripheral Access Layer for GICA
 */

#if !defined(PERI_GICA_H_)
#define PERI_GICA_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- GICA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICA_Peripheral_Access_Layer GICA Peripheral Access Layer
 * @{
 */

/** GICA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[64];
  __O  uint32_t GICA_SETSPI_NSR;                   /**< GICA_SETSPI_NSR, offset: 0x40 */
       uint8_t RESERVED_1[4];
  __O  uint32_t GICA_CLRSPI_NSR;                   /**< GICA_CLRSPI_NSR, offset: 0x48 */
       uint8_t RESERVED_2[4];
  __O  uint32_t GICA_SETSPI_SR;                    /**< GICA_SETSPI_SR, offset: 0x50 */
       uint8_t RESERVED_3[4];
  __O  uint32_t GICA_CLRSPI_SR;                    /**< GICA_CLRSPI_SR, offset: 0x58 */
} GICA_Type;

/* ----------------------------------------------------------------------------
   -- GICA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICA_Register_Masks GICA Register Masks
 * @{
 */

/*! @name GICA_SETSPI_NSR - GICA_SETSPI_NSR */
/*! @{ */

#define GICA_GICA_SETSPI_NSR_ID_MASK             (0x3FFU)
#define GICA_GICA_SETSPI_NSR_ID_SHIFT            (0U)
/*! ID - ID */
#define GICA_GICA_SETSPI_NSR_ID(x)               (((uint32_t)(((uint32_t)(x)) << GICA_GICA_SETSPI_NSR_ID_SHIFT)) & GICA_GICA_SETSPI_NSR_ID_MASK)

#define GICA_GICA_SETSPI_NSR_RESERVED0_MASK      (0xFFFFFC00U)
#define GICA_GICA_SETSPI_NSR_RESERVED0_SHIFT     (10U)
/*! RESERVED0 - RESERVED0 */
#define GICA_GICA_SETSPI_NSR_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICA_GICA_SETSPI_NSR_RESERVED0_SHIFT)) & GICA_GICA_SETSPI_NSR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CLRSPI_NSR - GICA_CLRSPI_NSR */
/*! @{ */

#define GICA_GICA_CLRSPI_NSR_ID_MASK             (0x3FFU)
#define GICA_GICA_CLRSPI_NSR_ID_SHIFT            (0U)
/*! ID - ID */
#define GICA_GICA_CLRSPI_NSR_ID(x)               (((uint32_t)(((uint32_t)(x)) << GICA_GICA_CLRSPI_NSR_ID_SHIFT)) & GICA_GICA_CLRSPI_NSR_ID_MASK)

#define GICA_GICA_CLRSPI_NSR_RESERVED0_MASK      (0xFFFFFC00U)
#define GICA_GICA_CLRSPI_NSR_RESERVED0_SHIFT     (10U)
/*! RESERVED0 - RESERVED0 */
#define GICA_GICA_CLRSPI_NSR_RESERVED0(x)        (((uint32_t)(((uint32_t)(x)) << GICA_GICA_CLRSPI_NSR_RESERVED0_SHIFT)) & GICA_GICA_CLRSPI_NSR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_SETSPI_SR - GICA_SETSPI_SR */
/*! @{ */

#define GICA_GICA_SETSPI_SR_ID_MASK              (0x3FFU)
#define GICA_GICA_SETSPI_SR_ID_SHIFT             (0U)
/*! ID - ID */
#define GICA_GICA_SETSPI_SR_ID(x)                (((uint32_t)(((uint32_t)(x)) << GICA_GICA_SETSPI_SR_ID_SHIFT)) & GICA_GICA_SETSPI_SR_ID_MASK)

#define GICA_GICA_SETSPI_SR_RESERVED0_MASK       (0xFFFFFC00U)
#define GICA_GICA_SETSPI_SR_RESERVED0_SHIFT      (10U)
/*! RESERVED0 - RESERVED0 */
#define GICA_GICA_SETSPI_SR_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICA_GICA_SETSPI_SR_RESERVED0_SHIFT)) & GICA_GICA_SETSPI_SR_RESERVED0_MASK)
/*! @} */

/*! @name GICA_CLRSPI_SR - GICA_CLRSPI_SR */
/*! @{ */

#define GICA_GICA_CLRSPI_SR_ID_MASK              (0x3FFU)
#define GICA_GICA_CLRSPI_SR_ID_SHIFT             (0U)
/*! ID - ID */
#define GICA_GICA_CLRSPI_SR_ID(x)                (((uint32_t)(((uint32_t)(x)) << GICA_GICA_CLRSPI_SR_ID_SHIFT)) & GICA_GICA_CLRSPI_SR_ID_MASK)

#define GICA_GICA_CLRSPI_SR_RESERVED0_MASK       (0xFFFFFC00U)
#define GICA_GICA_CLRSPI_SR_RESERVED0_SHIFT      (10U)
/*! RESERVED0 - RESERVED0 */
#define GICA_GICA_CLRSPI_SR_RESERVED0(x)         (((uint32_t)(((uint32_t)(x)) << GICA_GICA_CLRSPI_SR_RESERVED0_SHIFT)) & GICA_GICA_CLRSPI_SR_RESERVED0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GICA_Register_Masks */


/*!
 * @}
 */ /* end of group GICA_Peripheral_Access_Layer */


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


#endif  /* PERI_GICA_H_ */
