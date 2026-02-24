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
**         CMSIS Peripheral Access Layer for NPU_BLK_CTRL
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
 * @file PERI_NPU_BLK_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NPU_BLK_CTRL
 *
 * CMSIS Peripheral Access Layer for NPU_BLK_CTRL
 */

#if !defined(PERI_NPU_BLK_CTRL_H_)
#define PERI_NPU_BLK_CTRL_H_                     /**< Symbol preventing repeated inclusion */

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
   -- NPU_BLK_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_BLK_CTRL_Peripheral_Access_Layer NPU_BLK_CTRL Peripheral Access Layer
 * @{
 */

/** NPU_BLK_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t LPCG;                              /**< NPUMIX LPCG Configuration Control, offset: 0x0 */
} NPU_BLK_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- NPU_BLK_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_BLK_CTRL_Register_Masks NPU_BLK_CTRL Register Masks
 * @{
 */

/*! @name LPCG - NPUMIX LPCG Configuration Control */
/*! @{ */

#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_MASK (0x1U)
#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SHIFT (0U)
/*! LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF - Control Force ON OFF for LPCG1 NPU_CLK_0
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL_MASK (0x2U)
#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL_SHIFT (1U)
/*! LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG1 NPU_CLK_0
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_1_NPU_CLK_0_UNGATED_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_MASK (0x4U)
#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SHIFT (2U)
/*! LPCG_2_NPU_CLK_FORCE_ON_OFF - Control Force ON OFF for LPCG2 NPU_CLK
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL_MASK (0x8U)
#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL_SHIFT (3U)
/*! LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG2 NPU_CLK
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_2_NPU_CLK_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_MASK (0x10U)
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SHIFT (4U)
/*! LPCG_3_NPU_CLK_FORCE_ON_OFF - Control Force ON OFF for LPCG3 NPU_CLK
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL_MASK (0x20U)
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL_SHIFT (5U)
/*! LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG3 NPU_CLK
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_MASK (0x100U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SHIFT (8U)
/*! LPCG_5_PER_CLK_1_FORCE_ON_OFF - Control Force ON OFF for LPCG5 PER_CLK_1
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL_MASK (0x200U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL_SHIFT (9U)
/*! LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG5 PER_CLK_1
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_1_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_MASK (0x400U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SHIFT (10U)
/*! LPCG_5_PER_CLK_2_FORCE_ON_OFF - Control Force ON OFF for LPCG5 PER_CLK_2
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL_MASK (0x800U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL_SHIFT (11U)
/*! LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG5 PER_CLK_2
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_2_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_MASK (0x4000U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SHIFT (14U)
/*! LPCG_5_PER_CLK_4_FORCE_ON_OFF - Control Force ON OFF for LPCG5 PER_CLK_4
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL_MASK (0x8000U)
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL_SHIFT (15U)
/*! LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG5 PER_CLK_4
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_5_PER_CLK_4_FORCE_ON_OFF_SEL_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_MASK (0x400000U)
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SHIFT (22U)
/*! LPCG_3_NPU_CLK_2_FORCE_ON_OFF - Control Force ON OFF for LPCG3 NPU_CLK_2
 *  0b0..Disables
 *  0b1..Enables
 */
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_MASK)

#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL_MASK (0x800000U)
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL_SHIFT (23U)
/*! LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL - Force ON OFF Select of LPCG3 NPU_CLK_2
 *  0b0..Not selected
 *  0b1..Selected
 */
#define NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL_SHIFT)) & NPU_BLK_CTRL_LPCG_LPCG_3_NPU_CLK_2_FORCE_ON_OFF_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_BLK_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_BLK_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_NPU_BLK_CTRL_H_ */

