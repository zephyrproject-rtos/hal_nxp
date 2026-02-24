/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPU_BLK_CTRL_GPUMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
 *
 * CMSIS Peripheral Access Layer for GPU_BLK_CTRL_GPUMIX
 */

#if !defined(PERI_GPU_BLK_CTRL_GPUMIX_H_)
#define PERI_GPU_BLK_CTRL_GPUMIX_H_              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
  __IO uint32_t STRIPING_GRANULE;                  /**< Striping Granule, offset: 0x0 */
  __IO uint32_t TEXFMTENABLE;                      /**< Texture Compression Formats Enable, offset: 0x4 */
  __IO uint32_t GPURESET;                          /**< GPU Reset Release, offset: 0x8 */
  __IO uint32_t DBGCTRL;                           /**< Debug Control, offset: 0xC */
  __IO uint32_t AWAKEUPS_BYPASS;                   /**< AWAKEUPS Bypass GPU Input, offset: 0x10 */
  __I  uint32_t GPU_QACTIVE;                       /**< GPU QACTIVE Pin Value, offset: 0x14 */
  __IO uint32_t GPU_QDENY;                         /**< GPU QDENY response status, offset: 0x18 */
} GPU_BLK_CTRL_GPUMIX_Type;

/* ----------------------------------------------------------------------------
   -- GPU_BLK_CTRL_GPUMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPU_BLK_CTRL_GPUMIX_Register_Masks GPU_BLK_CTRL_GPUMIX Register Masks
 * @{
 */

/*! @name STRIPING_GRANULE - Striping Granule */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_MASK (0xFU)
#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_SHIFT (0U)
/*! STRIPING_GRANULE - Striping Granule
 *  0b0000..Striping granule is 4KB
 *  0b0010..Striping granule is 256B
 *  0b0011..Striping granule is 512B
 *  0b0100..Striping granule is 1KB
 *  0b0101..Striping granule is 2KB
 *  0b0111..Use an address hash function for striping.
 */
#define GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_SHIFT)) & GPU_BLK_CTRL_GPUMIX_STRIPING_GRANULE_STRIPING_GRANULE_MASK)
/*! @} */

/*! @name TEXFMTENABLE - Texture Compression Formats Enable */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_MASK (0xFFFFFFFFU)
#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_SHIFT (0U)
/*! TEXFMTENABLE - Texture Compression Formats Enable */
#define GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_SHIFT)) & GPU_BLK_CTRL_GPUMIX_TEXFMTENABLE_TEXFMTENABLE_MASK)
/*! @} */

/*! @name GPURESET - GPU Reset Release */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_MASK  (0x1U)
#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_SHIFT (0U)
/*! GPURR - GPU Reset Release */
#define GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR(x)    (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_SHIFT)) & GPU_BLK_CTRL_GPUMIX_GPURESET_GPURR_MASK)
/*! @} */

/*! @name DBGCTRL - Debug Control */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUDBGEN_MASK (0x1U)
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUDBGEN_SHIFT (0U)
/*! MCUDBGEN - Microcontroller Debug Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUDBGEN(x)  (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUDBGEN_SHIFT)) & GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUDBGEN_MASK)

#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUNIDEN_MASK (0x2U)
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUNIDEN_SHIFT (1U)
/*! MCUNIDEN - Microcontroller Non-Invasive Debug Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUNIDEN(x)  (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUNIDEN_SHIFT)) & GPU_BLK_CTRL_GPUMIX_DBGCTRL_MCUNIDEN_MASK)

#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTDBGEN_MASK (0x4U)
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTDBGEN_SHIFT (2U)
/*! PROTDBGEN - Protected Mode Debug Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTDBGEN(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTDBGEN_SHIFT)) & GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTDBGEN_MASK)

#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTNIDEN_MASK (0x8U)
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTNIDEN_SHIFT (3U)
/*! PROTNIDEN - Protected Mode Non-Invasive Debug Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTNIDEN(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTNIDEN_SHIFT)) & GPU_BLK_CTRL_GPUMIX_DBGCTRL_PROTNIDEN_MASK)
/*! @} */

/*! @name AWAKEUPS_BYPASS - AWAKEUPS Bypass GPU Input */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_AWAKEUPS_BYPASS_AWAKEUPS_MASK (0x1U)
#define GPU_BLK_CTRL_GPUMIX_AWAKEUPS_BYPASS_AWAKEUPS_SHIFT (0U)
/*! AWAKEUPS - AWAKEUPS Bypass Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define GPU_BLK_CTRL_GPUMIX_AWAKEUPS_BYPASS_AWAKEUPS(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_AWAKEUPS_BYPASS_AWAKEUPS_SHIFT)) & GPU_BLK_CTRL_GPUMIX_AWAKEUPS_BYPASS_AWAKEUPS_MASK)
/*! @} */

/*! @name GPU_QACTIVE - GPU QACTIVE Pin Value */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_GPU_QACTIVE_QACTIVE_MASK (0x1U)
#define GPU_BLK_CTRL_GPUMIX_GPU_QACTIVE_QACTIVE_SHIFT (0U)
/*! QACTIVE - QACTIVE Pin Value */
#define GPU_BLK_CTRL_GPUMIX_GPU_QACTIVE_QACTIVE(x) (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_GPU_QACTIVE_QACTIVE_SHIFT)) & GPU_BLK_CTRL_GPUMIX_GPU_QACTIVE_QACTIVE_MASK)
/*! @} */

/*! @name GPU_QDENY - GPU QDENY response status */
/*! @{ */

#define GPU_BLK_CTRL_GPUMIX_GPU_QDENY_QDENY_MASK (0x1U)
#define GPU_BLK_CTRL_GPUMIX_GPU_QDENY_QDENY_SHIFT (0U)
/*! QDENY - QDENY Pin Value */
#define GPU_BLK_CTRL_GPUMIX_GPU_QDENY_QDENY(x)   (((uint32_t)(((uint32_t)(x)) << GPU_BLK_CTRL_GPUMIX_GPU_QDENY_QDENY_SHIFT)) & GPU_BLK_CTRL_GPUMIX_GPU_QDENY_QDENY_MASK)
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


#endif  /* PERI_GPU_BLK_CTRL_GPUMIX_H_ */

