/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
 * @file PERI_PCIE_SHADOW_EP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
 *
 * CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
 */

#if !defined(PERI_PCIE_SHADOW_EP_H_)
#define PERI_PCIE_SHADOW_EP_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- PCIE_SHADOW_EP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_SHADOW_EP_Peripheral_Access_Layer PCIE_SHADOW_EP Peripheral Access Layer
 * @{
 */

/** PCIE_SHADOW_EP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __O  uint32_t BAR0_MASK_REG;                     /**< BAR0 Mask Register., offset: 0x10 */
  __O  uint32_t BAR1_MASK_REG;                     /**< BAR1 Mask Register., offset: 0x14 */
  __O  uint32_t BAR2_MASK_REG;                     /**< BAR2 Mask Register., offset: 0x18 */
  __O  uint32_t BAR3_MASK_REG;                     /**< BAR3 Mask Register., offset: 0x1C */
  __O  uint32_t BAR4_MASK_REG;                     /**< BAR4 Mask Register., offset: 0x20 */
  __O  uint32_t BAR5_MASK_REG;                     /**< BAR5 Mask Register., offset: 0x24 */
       uint8_t RESERVED_1[8];
  __O  uint32_t EXP_ROM_BAR_MASK_REG;              /**< Expansion ROM BAR Mask Register., offset: 0x30 */
} PCIE_SHADOW_EP_Type;

/* ----------------------------------------------------------------------------
   -- PCIE_SHADOW_EP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCIE_SHADOW_EP_Register_Masks PCIE_SHADOW_EP Register Masks
 * @{
 */

/*! @name BAR0_MASK_REG - BAR0 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR0_ENABLED - - BAR0 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR0_MASK - - BAR0 Mask. */
#define PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR0_MASK_REG_PCI_TYPE0_BAR0_MASK_MASK)
/*! @} */

/*! @name BAR1_MASK_REG - BAR1 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR1_ENABLED - - BAR1 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR1_MASK - - BAR1 Mask. */
#define PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR1_MASK_REG_PCI_TYPE0_BAR1_MASK_MASK)
/*! @} */

/*! @name BAR2_MASK_REG - BAR2 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR2_ENABLED - BAR2 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR2_MASK - BAR2 Mask. */
#define PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR2_MASK_REG_PCI_TYPE0_BAR2_MASK_MASK)
/*! @} */

/*! @name BAR3_MASK_REG - BAR3 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR3_ENABLED - BAR3 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR3_MASK - BAR3 Mask. */
#define PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR3_MASK_REG_PCI_TYPE0_BAR3_MASK_MASK)
/*! @} */

/*! @name BAR4_MASK_REG - BAR4 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR4_ENABLED - BAR4 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR4_MASK - BAR4 Mask. */
#define PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR4_MASK_REG_PCI_TYPE0_BAR4_MASK_MASK)
/*! @} */

/*! @name BAR5_MASK_REG - BAR5 Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_SHIFT (0U)
/*! PCI_TYPE0_BAR5_ENABLED - BAR5 Mask Enabled. */
#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_SHIFT)) & PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_ENABLED_MASK)

#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_SHIFT (1U)
/*! PCI_TYPE0_BAR5_MASK - BAR5 Mask. */
#define PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_SHIFT)) & PCIE_SHADOW_EP_BAR5_MASK_REG_PCI_TYPE0_BAR5_MASK_MASK)
/*! @} */

/*! @name EXP_ROM_BAR_MASK_REG - Expansion ROM BAR Mask Register. */
/*! @{ */

#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_MASK (0x1U)
#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_SHIFT (0U)
/*! ROM_BAR_ENABLED - Expansion ROM Bar Mask Register Enabled. */
#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_SHIFT)) & PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_BAR_ENABLED_MASK)

#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_MASK_MASK (0xFFFFFFFEU)
#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_MASK_SHIFT (1U)
/*! ROM_MASK - Expansion ROM Mask. */
#define PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_MASK(x) (((uint32_t)(((uint32_t)(x)) << PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_MASK_SHIFT)) & PCIE_SHADOW_EP_EXP_ROM_BAR_MASK_REG_ROM_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCIE_SHADOW_EP_Register_Masks */


/*!
 * @}
 */ /* end of group PCIE_SHADOW_EP_Peripheral_Access_Layer */


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


#endif  /* PERI_PCIE_SHADOW_EP_H_ */

