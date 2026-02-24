/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260114
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC_GPR
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
 * @file PERI_IOMUXC_GPR.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for IOMUXC_GPR
 *
 * CMSIS Peripheral Access Layer for IOMUXC_GPR
 */

#if !defined(PERI_IOMUXC_GPR_H_)
#define PERI_IOMUXC_GPR_H_                       /**< Symbol preventing repeated inclusion */

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
   -- IOMUXC_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Peripheral_Access_Layer IOMUXC_GPR Peripheral Access Layer
 * @{
 */

/** IOMUXC_GPR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONFIG;                            /**< IOMUXC GPR Configuration, offset: 0x0 */
} IOMUXC_GPR_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_GPR_Register_Masks IOMUXC_GPR Register Masks
 * @{
 */

/*! @name CONFIG - IOMUXC GPR Configuration */
/*! @{ */

#define IOMUXC_GPR_CONFIG_MASTERID0_DATA_MASK    (0xFU)
#define IOMUXC_GPR_CONFIG_MASTERID0_DATA_SHIFT   (0U)
/*! MASTERID0_DATA - Data bits */
#define IOMUXC_GPR_CONFIG_MASTERID0_DATA(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID0_DATA_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID0_DATA_MASK)

#define IOMUXC_GPR_CONFIG_MASTERID1_DATA_MASK    (0xF0U)
#define IOMUXC_GPR_CONFIG_MASTERID1_DATA_SHIFT   (4U)
/*! MASTERID1_DATA - Data bits */
#define IOMUXC_GPR_CONFIG_MASTERID1_DATA(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID1_DATA_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID1_DATA_MASK)

#define IOMUXC_GPR_CONFIG_MASTERID2_DATA_MASK    (0xF00U)
#define IOMUXC_GPR_CONFIG_MASTERID2_DATA_SHIFT   (8U)
/*! MASTERID2_DATA - Data bits */
#define IOMUXC_GPR_CONFIG_MASTERID2_DATA(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID2_DATA_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID2_DATA_MASK)

#define IOMUXC_GPR_CONFIG_MASTERID0_LOCK_MASK    (0xF0000U)
#define IOMUXC_GPR_CONFIG_MASTERID0_LOCK_SHIFT   (16U)
/*! MASTERID0_LOCK - Lock bits */
#define IOMUXC_GPR_CONFIG_MASTERID0_LOCK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID0_LOCK_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID0_LOCK_MASK)

#define IOMUXC_GPR_CONFIG_MASTERID1_LOCK_MASK    (0xF00000U)
#define IOMUXC_GPR_CONFIG_MASTERID1_LOCK_SHIFT   (20U)
/*! MASTERID1_LOCK - Lock bits */
#define IOMUXC_GPR_CONFIG_MASTERID1_LOCK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID1_LOCK_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID1_LOCK_MASK)

#define IOMUXC_GPR_CONFIG_MASTERID2_LOCK_MASK    (0xF000000U)
#define IOMUXC_GPR_CONFIG_MASTERID2_LOCK_SHIFT   (24U)
/*! MASTERID2_LOCK - Lock bits */
#define IOMUXC_GPR_CONFIG_MASTERID2_LOCK(x)      (((uint32_t)(((uint32_t)(x)) << IOMUXC_GPR_CONFIG_MASTERID2_LOCK_SHIFT)) & IOMUXC_GPR_CONFIG_MASTERID2_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_GPR_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC_GPR_H_ */

