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
**         CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
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
 * @file PCIE_SHADOW_EP.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
 *
 * CMSIS Peripheral Access Layer for PCIE_SHADOW_EP
 */

#if !defined(PCIE_SHADOW_EP_H_)
#define PCIE_SHADOW_EP_H_                        /**< Symbol preventing repeated inclusion */

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


#endif  /* PCIE_SHADOW_EP_H_ */

