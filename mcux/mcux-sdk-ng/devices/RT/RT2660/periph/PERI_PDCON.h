/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PDCON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_PDCON.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for PDCON
 *
 * CMSIS Peripheral Access Layer for PDCON
 */

#if !defined(PERI_PDCON_H_)
#define PERI_PDCON_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- PDCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDCON_Peripheral_Access_Layer PDCON Peripheral Access Layer
 * @{
 */

/** PDCON - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t ACCCTRL;                           /**< Access Control, offset: 0x4 */
  __IO uint32_t HSKEN0;                            /**< Handshake Enable 0, offset: 0x8 */
  __IO uint32_t HSKEN1;                            /**< Handshake Enable 1, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t MDCTRL;                            /**< Mode Control, offset: 0x18 */
  __IO uint32_t PDRUNCFG;                          /**< Power Domain Run Configuration, offset: 0x1C */
  __IO uint32_t PDSLPCFG;                          /**< Power Domain Sleep Configuration, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t PDST;                              /**< Power Domain State, offset: 0x28 */
  __IO uint32_t PDSEF;                             /**< Power Domain State Flag, offset: 0x2C */
  __IO uint32_t SWCTRL;                            /**< Software Trigger Control, offset: 0x30 */
       uint8_t RESERVED_2[32];
  __IO uint32_t MISCCTRL;                          /**< Misc Control, offset: 0x54 */
  __IO uint32_t WRPSP0;                            /**< Warm Reset Postpone 0, offset: 0x58 */
  __IO uint32_t WRPSP1;                            /**< Warm Reset Postpone 1, offset: 0x5C */
} PDCON_Type;

/* ----------------------------------------------------------------------------
   -- PDCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PDCON_Register_Masks PDCON Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define PDCON_VERID_VERSION_MASK                 (0xFFFFFFFFU)
#define PDCON_VERID_VERSION_SHIFT                (0U)
/*! VERSION - Version ID */
#define PDCON_VERID_VERSION(x)                   (((uint32_t)(((uint32_t)(x)) << PDCON_VERID_VERSION_SHIFT)) & PDCON_VERID_VERSION_MASK)
/*! @} */

/*! @name ACCCTRL - Access Control */
/*! @{ */

#define PDCON_ACCCTRL_DID_MASK                   (0xFU)
#define PDCON_ACCCTRL_DID_SHIFT                  (0U)
/*! DID - Domain ID */
#define PDCON_ACCCTRL_DID(x)                     (((uint32_t)(((uint32_t)(x)) << PDCON_ACCCTRL_DID_SHIFT)) & PDCON_ACCCTRL_DID_MASK)

#define PDCON_ACCCTRL_UM_MASK                    (0x10000U)
#define PDCON_ACCCTRL_UM_SHIFT                   (16U)
/*! UM - User Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDCON_ACCCTRL_UM(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_ACCCTRL_UM_SHIFT)) & PDCON_ACCCTRL_UM_MASK)

#define PDCON_ACCCTRL_NSM_MASK                   (0x20000U)
#define PDCON_ACCCTRL_NSM_SHIFT                  (17U)
/*! NSM - Non-Secure Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PDCON_ACCCTRL_NSM(x)                     (((uint32_t)(((uint32_t)(x)) << PDCON_ACCCTRL_NSM_SHIFT)) & PDCON_ACCCTRL_NSM_MASK)

#define PDCON_ACCCTRL_LOCK_MASK                  (0x80000000U)
#define PDCON_ACCCTRL_LOCK_SHIFT                 (31U)
/*! LOCK - Access Control Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define PDCON_ACCCTRL_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_ACCCTRL_LOCK_SHIFT)) & PDCON_ACCCTRL_LOCK_MASK)
/*! @} */

/*! @name HSKEN0 - Handshake Enable 0 */
/*! @{ */

#define PDCON_HSKEN0_PD0_HSK_MASK                (0x7U)
#define PDCON_HSKEN0_PD0_HSK_SHIFT               (0U)
/*! PD0_HSK - Handshake Enable */
#define PDCON_HSKEN0_PD0_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN0_PD0_HSK_SHIFT)) & PDCON_HSKEN0_PD0_HSK_MASK)

#define PDCON_HSKEN0_PD1_HSK_MASK                (0x700U)
#define PDCON_HSKEN0_PD1_HSK_SHIFT               (8U)
/*! PD1_HSK - Handshake Enable */
#define PDCON_HSKEN0_PD1_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN0_PD1_HSK_SHIFT)) & PDCON_HSKEN0_PD1_HSK_MASK)

#define PDCON_HSKEN0_PD2_HSK_MASK                (0x70000U)
#define PDCON_HSKEN0_PD2_HSK_SHIFT               (16U)
/*! PD2_HSK - Handshake Enable */
#define PDCON_HSKEN0_PD2_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN0_PD2_HSK_SHIFT)) & PDCON_HSKEN0_PD2_HSK_MASK)

#define PDCON_HSKEN0_PD3_HSK_MASK                (0x7000000U)
#define PDCON_HSKEN0_PD3_HSK_SHIFT               (24U)
/*! PD3_HSK - Handshake Enable */
#define PDCON_HSKEN0_PD3_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN0_PD3_HSK_SHIFT)) & PDCON_HSKEN0_PD3_HSK_MASK)
/*! @} */

/*! @name HSKEN1 - Handshake Enable 1 */
/*! @{ */

#define PDCON_HSKEN1_PD4_HSK_MASK                (0x7U)
#define PDCON_HSKEN1_PD4_HSK_SHIFT               (0U)
/*! PD4_HSK - Handshake Enable */
#define PDCON_HSKEN1_PD4_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN1_PD4_HSK_SHIFT)) & PDCON_HSKEN1_PD4_HSK_MASK)

#define PDCON_HSKEN1_PD5_HSK_MASK                (0x700U)
#define PDCON_HSKEN1_PD5_HSK_SHIFT               (8U)
/*! PD5_HSK - Handshake Enable */
#define PDCON_HSKEN1_PD5_HSK(x)                  (((uint32_t)(((uint32_t)(x)) << PDCON_HSKEN1_PD5_HSK_SHIFT)) & PDCON_HSKEN1_PD5_HSK_MASK)
/*! @} */

/*! @name MDCTRL - Mode Control */
/*! @{ */

#define PDCON_MDCTRL_HW_MASK                     (0x3FU)
#define PDCON_MDCTRL_HW_SHIFT                    (0U)
/*! HW - Hardware Enable */
#define PDCON_MDCTRL_HW(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_MDCTRL_HW_SHIFT)) & PDCON_MDCTRL_HW_MASK)

#define PDCON_MDCTRL_SW_MASK                     (0x3F0000U)
#define PDCON_MDCTRL_SW_SHIFT                    (16U)
/*! SW - Software Enable */
#define PDCON_MDCTRL_SW(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_MDCTRL_SW_SHIFT)) & PDCON_MDCTRL_SW_MASK)

#define PDCON_MDCTRL_LOCK_MASK                   (0x80000000U)
#define PDCON_MDCTRL_LOCK_SHIFT                  (31U)
/*! LOCK - Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define PDCON_MDCTRL_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << PDCON_MDCTRL_LOCK_SHIFT)) & PDCON_MDCTRL_LOCK_MASK)
/*! @} */

/*! @name PDRUNCFG - Power Domain Run Configuration */
/*! @{ */

#define PDCON_PDRUNCFG_PDCFG3_MASK               (0xC0U)
#define PDCON_PDRUNCFG_PDCFG3_SHIFT              (6U)
/*! PDCFG3 - Power Domain Configuration 3
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDRUNCFG_PDCFG3(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDRUNCFG_PDCFG3_SHIFT)) & PDCON_PDRUNCFG_PDCFG3_MASK)

#define PDCON_PDRUNCFG_PDCFG4_MASK               (0x300U)
#define PDCON_PDRUNCFG_PDCFG4_SHIFT              (8U)
/*! PDCFG4 - Power Domain Configuration 4
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDRUNCFG_PDCFG4(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDRUNCFG_PDCFG4_SHIFT)) & PDCON_PDRUNCFG_PDCFG4_MASK)

#define PDCON_PDRUNCFG_PDCFG5_MASK               (0xC00U)
#define PDCON_PDRUNCFG_PDCFG5_SHIFT              (10U)
/*! PDCFG5 - Power Domain Configuration 5
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDRUNCFG_PDCFG5(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDRUNCFG_PDCFG5_SHIFT)) & PDCON_PDRUNCFG_PDCFG5_MASK)
/*! @} */

/*! @name PDSLPCFG - Power Domain Sleep Configuration */
/*! @{ */

#define PDCON_PDSLPCFG_PDCFG1_MASK               (0xCU)
#define PDCON_PDSLPCFG_PDCFG1_SHIFT              (2U)
/*! PDCFG1 - Power Domain Configuration 1
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDSLPCFG_PDCFG1(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDSLPCFG_PDCFG1_SHIFT)) & PDCON_PDSLPCFG_PDCFG1_MASK)

#define PDCON_PDSLPCFG_PDCFG2_MASK               (0x30U)
#define PDCON_PDSLPCFG_PDCFG2_SHIFT              (4U)
/*! PDCFG2 - Power Domain Configuration 2
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDSLPCFG_PDCFG2(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDSLPCFG_PDCFG2_SHIFT)) & PDCON_PDSLPCFG_PDCFG2_MASK)

#define PDCON_PDSLPCFG_PDCFG3_MASK               (0xC0U)
#define PDCON_PDSLPCFG_PDCFG3_SHIFT              (6U)
/*! PDCFG3 - Power Domain Configuration 3
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDSLPCFG_PDCFG3(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDSLPCFG_PDCFG3_SHIFT)) & PDCON_PDSLPCFG_PDCFG3_MASK)

#define PDCON_PDSLPCFG_PDCFG4_MASK               (0x300U)
#define PDCON_PDSLPCFG_PDCFG4_SHIFT              (8U)
/*! PDCFG4 - Power Domain Configuration 4
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDSLPCFG_PDCFG4(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDSLPCFG_PDCFG4_SHIFT)) & PDCON_PDSLPCFG_PDCFG4_MASK)

#define PDCON_PDSLPCFG_PDCFG5_MASK               (0xC00U)
#define PDCON_PDSLPCFG_PDCFG5_SHIFT              (10U)
/*! PDCFG5 - Power Domain Configuration 5
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDSLPCFG_PDCFG5(x)                 (((uint32_t)(((uint32_t)(x)) << PDCON_PDSLPCFG_PDCFG5_SHIFT)) & PDCON_PDSLPCFG_PDCFG5_MASK)
/*! @} */

/*! @name PDST - Power Domain State */
/*! @{ */

#define PDCON_PDST_PDS0_MASK                     (0x3U)
#define PDCON_PDST_PDS0_SHIFT                    (0U)
/*! PDS0 - Power Domain State 0
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS0(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS0_SHIFT)) & PDCON_PDST_PDS0_MASK)

#define PDCON_PDST_PDS1_MASK                     (0xCU)
#define PDCON_PDST_PDS1_SHIFT                    (2U)
/*! PDS1 - Power Domain State 1
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS1(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS1_SHIFT)) & PDCON_PDST_PDS1_MASK)

#define PDCON_PDST_PDS2_MASK                     (0x30U)
#define PDCON_PDST_PDS2_SHIFT                    (4U)
/*! PDS2 - Power Domain State 2
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS2(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS2_SHIFT)) & PDCON_PDST_PDS2_MASK)

#define PDCON_PDST_PDS3_MASK                     (0xC0U)
#define PDCON_PDST_PDS3_SHIFT                    (6U)
/*! PDS3 - Power Domain State 3
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS3(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS3_SHIFT)) & PDCON_PDST_PDS3_MASK)

#define PDCON_PDST_PDS4_MASK                     (0x300U)
#define PDCON_PDST_PDS4_SHIFT                    (8U)
/*! PDS4 - Power Domain State 4
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS4(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS4_SHIFT)) & PDCON_PDST_PDS4_MASK)

#define PDCON_PDST_PDS5_MASK                     (0xC00U)
#define PDCON_PDST_PDS5_SHIFT                    (10U)
/*! PDS5 - Power Domain State 5
 *  0b00..Active or Power-on mode
 *  0b10..Power-off mode
 */
#define PDCON_PDST_PDS5(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDS5_SHIFT)) & PDCON_PDST_PDS5_MASK)

#define PDCON_PDST_PDB0_MASK                     (0x10000U)
#define PDCON_PDST_PDB0_SHIFT                    (16U)
/*! PDB0 - Busy Flag for Power Domain 0
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB0(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB0_SHIFT)) & PDCON_PDST_PDB0_MASK)

#define PDCON_PDST_PDB1_MASK                     (0x20000U)
#define PDCON_PDST_PDB1_SHIFT                    (17U)
/*! PDB1 - Busy Flag for Power Domain 1
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB1(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB1_SHIFT)) & PDCON_PDST_PDB1_MASK)

#define PDCON_PDST_PDB2_MASK                     (0x40000U)
#define PDCON_PDST_PDB2_SHIFT                    (18U)
/*! PDB2 - Busy Flag for Power Domain 2
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB2(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB2_SHIFT)) & PDCON_PDST_PDB2_MASK)

#define PDCON_PDST_PDB3_MASK                     (0x80000U)
#define PDCON_PDST_PDB3_SHIFT                    (19U)
/*! PDB3 - Busy Flag for Power Domain 3
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB3(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB3_SHIFT)) & PDCON_PDST_PDB3_MASK)

#define PDCON_PDST_PDB4_MASK                     (0x100000U)
#define PDCON_PDST_PDB4_SHIFT                    (20U)
/*! PDB4 - Busy Flag for Power Domain 4
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB4(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB4_SHIFT)) & PDCON_PDST_PDB4_MASK)

#define PDCON_PDST_PDB5_MASK                     (0x200000U)
#define PDCON_PDST_PDB5_SHIFT                    (21U)
/*! PDB5 - Busy Flag for Power Domain 5
 *  0b0..Idle
 *  0b1..Busy
 */
#define PDCON_PDST_PDB5(x)                       (((uint32_t)(((uint32_t)(x)) << PDCON_PDST_PDB5_SHIFT)) & PDCON_PDST_PDB5_MASK)
/*! @} */

/*! @name PDSEF - Power Domain State Flag */
/*! @{ */

#define PDCON_PDSEF_PEF0_MASK                    (0x3U)
#define PDCON_PDSEF_PEF0_SHIFT                   (0U)
/*! PEF0 - Low-Power Event Flag of Power Domain 0
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF0(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF0_SHIFT)) & PDCON_PDSEF_PEF0_MASK)

#define PDCON_PDSEF_PEF1_MASK                    (0xCU)
#define PDCON_PDSEF_PEF1_SHIFT                   (2U)
/*! PEF1 - Low-Power Event Flag of Power Domain 1
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF1(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF1_SHIFT)) & PDCON_PDSEF_PEF1_MASK)

#define PDCON_PDSEF_PEF2_MASK                    (0x30U)
#define PDCON_PDSEF_PEF2_SHIFT                   (4U)
/*! PEF2 - Low-Power Event Flag of Power Domain 2
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF2(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF2_SHIFT)) & PDCON_PDSEF_PEF2_MASK)

#define PDCON_PDSEF_PEF3_MASK                    (0xC0U)
#define PDCON_PDSEF_PEF3_SHIFT                   (6U)
/*! PEF3 - Low-Power Event Flag of Power Domain 3
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF3(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF3_SHIFT)) & PDCON_PDSEF_PEF3_MASK)

#define PDCON_PDSEF_PEF4_MASK                    (0x300U)
#define PDCON_PDSEF_PEF4_SHIFT                   (8U)
/*! PEF4 - Low-Power Event Flag of Power Domain 4
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF4(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF4_SHIFT)) & PDCON_PDSEF_PEF4_MASK)

#define PDCON_PDSEF_PEF5_MASK                    (0xC00U)
#define PDCON_PDSEF_PEF5_SHIFT                   (10U)
/*! PEF5 - Low-Power Event Flag of Power Domain 5
 *  0b00..No low-power event
 *  0b10..Power-off event occurred
 */
#define PDCON_PDSEF_PEF5(x)                      (((uint32_t)(((uint32_t)(x)) << PDCON_PDSEF_PEF5_SHIFT)) & PDCON_PDSEF_PEF5_MASK)
/*! @} */

/*! @name SWCTRL - Software Trigger Control */
/*! @{ */

#define PDCON_SWCTRL_SWTRG_MASK                  (0x3FU)
#define PDCON_SWCTRL_SWTRG_SHIFT                 (0U)
/*! SWTRG - Software Trigger */
#define PDCON_SWCTRL_SWTRG(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_SWCTRL_SWTRG_SHIFT)) & PDCON_SWCTRL_SWTRG_MASK)
/*! @} */

/*! @name MISCCTRL - Misc Control */
/*! @{ */

#define PDCON_MISCCTRL_SEL_MASK                  (0x7U)
#define PDCON_MISCCTRL_SEL_SHIFT                 (0U)
/*! SEL - Observe Select
 *  0b000..Power Domain 0
 *  0b001..Power Domain 1
 *  0b010..Power Domain 2
 *  0b011..Power Domain 3
 *  0b100..Power Domain 4
 *  0b101..Power Domain 5
 */
#define PDCON_MISCCTRL_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_MISCCTRL_SEL_SHIFT)) & PDCON_MISCCTRL_SEL_MASK)

#define PDCON_MISCCTRL_FCEN_MASK                 (0x80000000U)
#define PDCON_MISCCTRL_FCEN_SHIFT                (31U)
/*! FCEN - Function Clock Enable
 *  0b0..Disable function clock
 *  0b1..Enable function clock
 */
#define PDCON_MISCCTRL_FCEN(x)                   (((uint32_t)(((uint32_t)(x)) << PDCON_MISCCTRL_FCEN_SHIFT)) & PDCON_MISCCTRL_FCEN_MASK)
/*! @} */

/*! @name WRPSP0 - Warm Reset Postpone 0 */
/*! @{ */

#define PDCON_WRPSP0_PSPD0_MASK                  (0xFFU)
#define PDCON_WRPSP0_PSPD0_SHIFT                 (0U)
/*! PSPD0 - Warm Reset Postpone for Domain 0 */
#define PDCON_WRPSP0_PSPD0(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP0_PSPD0_SHIFT)) & PDCON_WRPSP0_PSPD0_MASK)

#define PDCON_WRPSP0_PSPD1_MASK                  (0xFF00U)
#define PDCON_WRPSP0_PSPD1_SHIFT                 (8U)
/*! PSPD1 - Warm Reset Postpone for Domain 1 */
#define PDCON_WRPSP0_PSPD1(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP0_PSPD1_SHIFT)) & PDCON_WRPSP0_PSPD1_MASK)

#define PDCON_WRPSP0_PSPD2_MASK                  (0xFF0000U)
#define PDCON_WRPSP0_PSPD2_SHIFT                 (16U)
/*! PSPD2 - Warm Reset Postpone for Domain 2 */
#define PDCON_WRPSP0_PSPD2(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP0_PSPD2_SHIFT)) & PDCON_WRPSP0_PSPD2_MASK)

#define PDCON_WRPSP0_PSPD3_MASK                  (0xFF000000U)
#define PDCON_WRPSP0_PSPD3_SHIFT                 (24U)
/*! PSPD3 - Warm Reset Postpone for Domain 3 */
#define PDCON_WRPSP0_PSPD3(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP0_PSPD3_SHIFT)) & PDCON_WRPSP0_PSPD3_MASK)
/*! @} */

/*! @name WRPSP1 - Warm Reset Postpone 1 */
/*! @{ */

#define PDCON_WRPSP1_PSPD4_MASK                  (0xFFU)
#define PDCON_WRPSP1_PSPD4_SHIFT                 (0U)
/*! PSPD4 - Warm Reset Postpone for Domain 4 */
#define PDCON_WRPSP1_PSPD4(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP1_PSPD4_SHIFT)) & PDCON_WRPSP1_PSPD4_MASK)

#define PDCON_WRPSP1_PSPD5_MASK                  (0xFF00U)
#define PDCON_WRPSP1_PSPD5_SHIFT                 (8U)
/*! PSPD5 - Warm Reset Postpone for Domain 5 */
#define PDCON_WRPSP1_PSPD5(x)                    (((uint32_t)(((uint32_t)(x)) << PDCON_WRPSP1_PSPD5_SHIFT)) & PDCON_WRPSP1_PSPD5_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PDCON_Register_Masks */


/*!
 * @}
 */ /* end of group PDCON_Peripheral_Access_Layer */


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


#endif  /* PERI_PDCON_H_ */

