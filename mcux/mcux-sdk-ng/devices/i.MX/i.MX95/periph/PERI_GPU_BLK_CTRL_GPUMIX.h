/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file GPU_BLK_CTRL_GPUMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
 *
 * CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
 */

#if !defined(GPU_BLK_CTRL_GPUMIX_H_)
#define GPU_BLK_CTRL_GPUMIX_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- GPU_BLK_CTRL_GPUMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPU_BLK_CTRL_GPUMIX_Peripheral_Access_Layer GPU_BLK_CTRL_GPUMIX Peripheral Access Layer
 * @{
 */

/** GPU_BLK_CTRL_GPUMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t STRIPING_GRANULE;                  /**< Striping Granule Register, offset: 0x0 */
  __IO uint32_t TEXFMTENABLE;                      /**< TEXFMT Enable Register, offset: 0x4 */
  __IO uint32_t GPURESET;                          /**< GPU Reset Release Register, offset: 0x8 */
} GPU_BLK_CTRL_GPUMIX_Type;

/* ----------------------------------------------------------------------------
   -- GPU_BLK_CTRL_GPUMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPU_BLK_CTRL_GPUMIX_Register_Masks GPU_BLK_CTRL_GPUMIX Register Masks
 * @{
 */

/*! @name STRIPING_GRANULE - Striping Granule Register */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_MASK (0xFU)
#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_SHIFT (0U)
/*! STRIPING_GRANULE - Striping Granule */
#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_SHIFT)) & GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_MASK)
/*! @} */

/*! @name TEXFMTENABLE - TEXFMT Enable Register */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_MASK (0xFFFFFFFFU)
#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_SHIFT (0U)
/*! TEXFMTENABLE - TEXFMT Enable */
#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_SHIFT)) & GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_MASK)
/*! @} */

/*! @name GPURESET - GPU Reset Release Register */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_MASK  (0x1U)
#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_SHIFT (0U)
/*! GPURR - GPU Reset Release */
#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR(x)    (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_SHIFT)) & GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPU_BLK_CTRL_GPUMIX_Register_Masks */


/*!
 * @}
 */ /* end of group GPU_BLK_CTRL_GPUMIX_Peripheral_Access_Layer */


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


#endif  /* GPU_BLK_CTRL_GPUMIX_H_ */

