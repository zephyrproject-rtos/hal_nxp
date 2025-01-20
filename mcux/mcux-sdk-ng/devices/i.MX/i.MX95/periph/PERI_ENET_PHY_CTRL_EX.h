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
**         CMSIS Peripheral Access Layer for ENET_PHY_CTRL_EX
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
 * @file ENET_PHY_CTRL_EX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_CTRL_EX
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_CTRL_EX
 */

#if !defined(ENET_PHY_CTRL_EX_H_)
#define ENET_PHY_CTRL_EX_H_                      /**< Symbol preventing repeated inclusion */

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
   -- ENET_PHY_CTRL_EX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_CTRL_EX_Peripheral_Access_Layer ENET_PHY_CTRL_EX Peripheral Access Layer
 * @{
 */

/** ENET_PHY_CTRL_EX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[276];
  __IO uint16_t GLOBAL_CTRL_EX_0;                  /**< PHY Global Extra Control 0, offset: 0x114 */
       uint8_t RESERVED_1[2];
  __IO uint16_t GLOBAL_CTRL_EX_1;                  /**< PHY Global Extra Control 1, offset: 0x118 */
       uint8_t RESERVED_2[10];
  __IO uint16_t GLOBAL_CTRL_EX_4;                  /**< PHY Global Extra Control 2, offset: 0x124 */
       uint8_t RESERVED_3[130950];
  __IO uint16_t MPLLA_CTRL_EX_0;                   /**< MPLLA Extra Control, offset: 0x200AC */
       uint8_t RESERVED_4[131070];
  __IO uint16_t MPLLB_CTRL_EX_0;                   /**< MPLLB Extra Control, offset: 0x400AC */
} ENET_PHY_CTRL_EX_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_CTRL_EX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_CTRL_EX_Register_Masks ENET_PHY_CTRL_EX Register Masks
 * @{
 */

/*! @name GLOBAL_CTRL_EX_0 - PHY Global Extra Control 0 */
/*! @{ */

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_MASK (0x1U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_SHIFT (0U)
/*! PHY_SRAM_BYPASS - SRAM Bypass
 *  0b0..No bypass
 *  0b1..Bypass
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_1 - PHY Global Extra Control 1 */
/*! @{ */

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_FLYOVER_EN_MASK (0x1U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_FLYOVER_EN_SHIFT (0U)
/*! PHY_TEST_FLYOVER_EN - Enable Flyover Test Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_FLYOVER_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_FLYOVER_EN_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_FLYOVER_EN_MASK)

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_STOP_CLK_EN_MASK (0x10U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_STOP_CLK_EN_SHIFT (4U)
/*! PHY_TEST_STOP_CLK_EN - Stop Clock Test Mode Enable */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_STOP_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_STOP_CLK_EN_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_1_PHY_TEST_STOP_CLK_EN_MASK)
/*! @} */

/*! @name GLOBAL_CTRL_EX_4 - PHY Global Extra Control 2 */
/*! @{ */

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_VPH_NOMINAL_MASK (0x3U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_VPH_NOMINAL_SHIFT (0U)
/*! PHY_VPH_NOMINAL - VPH Nominal Selection
 *  0b00, 0b01..Reserved
 *  0b10..1.5 V
 *  0b11..1.8 V
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_VPH_NOMINAL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_VPH_NOMINAL_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_VPH_NOMINAL_MASK)

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE_MASK (0x100U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE_SHIFT (8U)
/*! PHY_PCS_PWR_STABLE - Power Stable for Raw PCS
 *  0b0..Not stable
 *  0b1..Stable
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE_MASK)

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_MASK (0x400U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_SHIFT (10U)
/*! PHY_PG_MODE_EN - Power Gating Support Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_MODE_EN_MASK)

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_MASK (0x1000U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_SHIFT (12U)
/*! PHY_PG_RESET - Power Gated Reset
 *  0b0..No reset
 *  0b1..Reset
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PG_RESET_MASK)

#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE_MASK (0x4000U)
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE_SHIFT (14U)
/*! PHY_PMA_PWR_STABLE - Power Stable for PMA
 *  0b0..Not stable
 *  0b1..Stable
 */
#define ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE_SHIFT)) & ENET_PHY_CTRL_EX_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE_MASK)
/*! @} */

/*! @name MPLLA_CTRL_EX_0 - MPLLA Extra Control */
/*! @{ */

#define ENET_PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_MASK (0x1U)
#define ENET_PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_SHIFT (0U)
/*! PHY_MPLLA_FORCE_EN - MPLLA Force Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_SHIFT)) & ENET_PHY_CTRL_EX_MPLLA_CTRL_EX_0_PHY_MPLLA_FORCE_EN_MASK)
/*! @} */

/*! @name MPLLB_CTRL_EX_0 - MPLLB Extra Control */
/*! @{ */

#define ENET_PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_MASK (0x1U)
#define ENET_PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_SHIFT (0U)
/*! PHY_MPLLB_FORCE_EN - MPLLA Force Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define ENET_PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_SHIFT)) & ENET_PHY_CTRL_EX_MPLLB_CTRL_EX_0_PHY_MPLLB_FORCE_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_CTRL_EX_Register_Masks */

#define ENET_PHY_CTRL_EX_BASE                    (0x0u)
#define ENET_PHY_CTRL_EX                         ((ENET_PHY_CTRL_EX_Type *)ENET_PHY_CTRL_EX_BASE)
#define ENET_PHY_CTRL_EX_BASE_ADDRS              { ENET_PHY_CTRL_EX_BASE }
#define ENET_PHY_CTRL_EX_BASE_PTRS               { ENET_PHY_CTRL_EX }


/*!
 * @}
 */ /* end of group ENET_PHY_CTRL_EX_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_CTRL_EX_H_ */

