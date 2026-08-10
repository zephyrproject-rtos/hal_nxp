/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FSB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-12-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_FSB.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for FSB
 *
 * CMSIS Peripheral Access Layer for FSB
 */

#if !defined(PERI_FSB_H_)
#define PERI_FSB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX93W32610GCM_ca55))
#include "MIMX93W32_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W32610GCM_cm33))
#include "MIMX93W32_cm33_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_ca55))
#include "MIMX93W52_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_cm33))
#include "MIMX93W52_cm33_COMMON.h"
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

#if defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Peripheral_Access_Layer FSB Peripheral Access Layer
 * @{
 */

/** FSB - Size of Registers Arrays */
#define FSB_FUSE_ARRAY_COUNT                      512u

/** FSB - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< FSB Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[24];
  __I  uint32_t FSB_STATUS;                        /**< FSB Status Register, offset: 0x1C */
       uint8_t RESERVED_1[68];
  __IO uint32_t ACCESS_COUNT;                      /**< Access Count Register, offset: 0x64 */
       uint8_t RESERVED_2[32664];
  __I  uint32_t FUSE[FSB_FUSE_ARRAY_COUNT];        /**< Fuse Value Registers, array offset: 0x8000, array step: 0x4 */
} FSB_Type;

/* ----------------------------------------------------------------------------
   -- FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Register_Masks FSB Register Masks
 * @{
 */

/*! @name VERID - FSB Version ID Register */
/*! @{ */

#define FSB_VERID_MISC_MASK                      (0xFFU)
#define FSB_VERID_MISC_SHIFT                     (0U)
/*! MISC - Feature Specification */
#define FSB_VERID_MISC(x)                        (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MISC_SHIFT)) & FSB_VERID_MISC_MASK)

#define FSB_VERID_ECO_MASK                       (0xFF00U)
#define FSB_VERID_ECO_SHIFT                      (8U)
/*! ECO - ECO Version Number */
#define FSB_VERID_ECO(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_VERID_ECO_SHIFT)) & FSB_VERID_ECO_MASK)

#define FSB_VERID_MINOR_MASK                     (0xFF0000U)
#define FSB_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define FSB_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MINOR_SHIFT)) & FSB_VERID_MINOR_MASK)

#define FSB_VERID_MAJOR_MASK                     (0xFF000000U)
#define FSB_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define FSB_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MAJOR_SHIFT)) & FSB_VERID_MAJOR_MASK)
/*! @} */

/*! @name FSB_STATUS - FSB Status Register */
/*! @{ */

#define FSB_FSB_STATUS_FUSE_VALID_MASK           (0x1U)
#define FSB_FSB_STATUS_FUSE_VALID_SHIFT          (0U)
/*! FUSE_VALID - Fuse valid. */
#define FSB_FSB_STATUS_FUSE_VALID(x)             (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_FUSE_VALID_SHIFT)) & FSB_FSB_STATUS_FUSE_VALID_MASK)
/*! @} */

/*! @name ACCESS_COUNT - Access Count Register */
/*! @{ */

#define FSB_ACCESS_COUNT_COUNT_MASK              (0xFFFFFFFFU)
#define FSB_ACCESS_COUNT_COUNT_SHIFT             (0U)
/*! COUNT - Access Count Register. */
#define FSB_ACCESS_COUNT_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_COUNT_COUNT_SHIFT)) & FSB_ACCESS_COUNT_COUNT_MASK)
/*! @} */

/*! @name FUSE - Fuse Value Registers */
/*! @{ */

#define FSB_FUSE_FUSE_MASK                       (0xFFFFFFFFU)
#define FSB_FUSE_FUSE_SHIFT                      (0U)
/*! FUSE - Fuse Values */
#define FSB_FUSE_FUSE(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_FUSE_SHIFT)) & FSB_FUSE_FUSE_MASK)
/*! @} */

/* The count of FSB_FUSE */
#define FSB_FUSE_COUNT                           (512U)


/*!
 * @}
 */ /* end of group FSB_Register_Masks */


/*!
 * @}
 */ /* end of group FSB_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FSB_H_ */

