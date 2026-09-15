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
**         CMSIS Peripheral Access Layer for RESETCON
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
 * @file PERI_RESETCON.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for RESETCON
 *
 * CMSIS Peripheral Access Layer for RESETCON
 */

#if !defined(PERI_RESETCON_H_)
#define PERI_RESETCON_H_                         /**< Symbol preventing repeated inclusion */

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
   -- RESETCON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RESETCON_Peripheral_Access_Layer RESETCON Peripheral Access Layer
 * @{
 */

/** RESETCON - Size of Registers Arrays */
#define RESETCON_GPR_COUNT                        16u

/** RESETCON - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __IO uint32_t ACCCTRL;                           /**< Access Control, offset: 0x4 */
  __IO uint32_t SWRST;                             /**< Software Reset, offset: 0x8 */
  __I  uint32_t RSTSTAT;                           /**< Reset Status, offset: 0xC */
  __IO uint32_t RSTSTAT_STICKY;                    /**< Sticky Reset Status, offset: 0x10 */
  __I  uint32_t PD_RSTSTAT;                        /**< Power Domain Reset Status, offset: 0x14 */
  __IO uint32_t PD_RSTSTAT_STICKY;                 /**< Sticky Power Domain Reset Status, offset: 0x18 */
  __IO uint32_t PD_RSTCTRL;                        /**< Power Domain Reset Control, offset: 0x1C */
  __I  uint32_t INITS;                             /**< Initialization Status, offset: 0x20 */
  __IO uint32_t ESCAEN;                            /**< Reset Escalation Enable, offset: 0x24 */
  __IO uint32_t RSTIE;                             /**< Reset Interrupt Enable, offset: 0x28 */
  __IO uint32_t RSTIS;                             /**< Reset Interrupt Status, offset: 0x2C */
  __IO uint32_t ITO;                               /**< Reset Interrupt Timeout, offset: 0x30 */
  __IO uint32_t RSTCNT;                            /**< Reset Count, offset: 0x34 */
  __IO uint32_t RTO;                               /**< Reset Timeout, offset: 0x38 */
  __IO uint32_t FILTER;                            /**< Reset Filter, offset: 0x3C */
  __IO uint32_t ROUT;                              /**< Reset Output, offset: 0x40 */
  __I  uint32_t MODESTAT;                          /**< Boot Mode Status, offset: 0x44 */
  __IO uint32_t MODECTRL;                          /**< Boot Mode Control, offset: 0x48 */
  __IO uint32_t PORPC;                             /**< POR_b Pin Reset Control, offset: 0x4C */
  __IO uint32_t RMSK;                              /**< Reset Mask, offset: 0x50 */
  __IO uint32_t RTM;                               /**< Reset Trigger Mode, offset: 0x54 */
  __IO uint32_t MISCCTRL;                          /**< Misc Control, offset: 0x58 */
       uint8_t RESERVED_0[4];
  __IO uint32_t GPR_LOCK;                          /**< General Purpose Register Lock, offset: 0x60 */
  __IO uint32_t GPR[RESETCON_GPR_COUNT];           /**< General Purpose Register 0..General Purpose Register 15, array offset: 0x64, array step: 0x4 */
} RESETCON_Type;

/* ----------------------------------------------------------------------------
   -- RESETCON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RESETCON_Register_Masks RESETCON Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define RESETCON_VERID_VERSION_MASK              (0xFFFFFFFFU)
#define RESETCON_VERID_VERSION_SHIFT             (0U)
/*! VERSION - Version ID */
#define RESETCON_VERID_VERSION(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_VERID_VERSION_SHIFT)) & RESETCON_VERID_VERSION_MASK)
/*! @} */

/*! @name ACCCTRL - Access Control */
/*! @{ */

#define RESETCON_ACCCTRL_DID_MASK                (0xFU)
#define RESETCON_ACCCTRL_DID_SHIFT               (0U)
/*! DID - Domain ID
 *  0b0xxx..Disables access for Domain ID 3
 *  0b1xxx..Enables access for Domain ID 3
 *  0bx0xx..Disables access for Domain ID 2
 *  0bx1xx..Enables access for Domain ID 2
 *  0bxx0x..Disables access for Domain ID 1
 *  0bxx1x..Enables access for Domain ID 1
 *  0bxxx0..Disables access for Domain ID 0
 *  0bxxx1..Enables access for Domain ID 0
 */
#define RESETCON_ACCCTRL_DID(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_ACCCTRL_DID_SHIFT)) & RESETCON_ACCCTRL_DID_MASK)

#define RESETCON_ACCCTRL_UM_MASK                 (0x10000U)
#define RESETCON_ACCCTRL_UM_SHIFT                (16U)
/*! UM - User Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ACCCTRL_UM(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_ACCCTRL_UM_SHIFT)) & RESETCON_ACCCTRL_UM_MASK)

#define RESETCON_ACCCTRL_NSM_MASK                (0x20000U)
#define RESETCON_ACCCTRL_NSM_SHIFT               (17U)
/*! NSM - Non-Secure Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ACCCTRL_NSM(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_ACCCTRL_NSM_SHIFT)) & RESETCON_ACCCTRL_NSM_MASK)

#define RESETCON_ACCCTRL_LOCK_MASK               (0x80000000U)
#define RESETCON_ACCCTRL_LOCK_SHIFT              (31U)
/*! LOCK - Access Control Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_ACCCTRL_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_ACCCTRL_LOCK_SHIFT)) & RESETCON_ACCCTRL_LOCK_MASK)
/*! @} */

/*! @name SWRST - Software Reset */
/*! @{ */

#define RESETCON_SWRST_EN_MASK                   (0xFFFFFFFFU)
#define RESETCON_SWRST_EN_SHIFT                  (0U)
/*! EN - Software Reset */
#define RESETCON_SWRST_EN(x)                     (((uint32_t)(((uint32_t)(x)) << RESETCON_SWRST_EN_SHIFT)) & RESETCON_SWRST_EN_MASK)
/*! @} */

/*! @name RSTSTAT - Reset Status */
/*! @{ */

#define RESETCON_RSTSTAT_POR_VBAT_MASK           (0x1U)
#define RESETCON_RSTSTAT_POR_VBAT_SHIFT          (0U)
/*! POR_VBAT - VBAT Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_POR_VBAT(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_POR_VBAT_SHIFT)) & RESETCON_RSTSTAT_POR_VBAT_MASK)

#define RESETCON_RSTSTAT_PMU_POR_MASK            (0x2U)
#define RESETCON_RSTSTAT_PMU_POR_SHIFT           (1U)
/*! PMU_POR - PMU Internal Supply Power On Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_PMU_POR(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_PMU_POR_SHIFT)) & RESETCON_RSTSTAT_PMU_POR_MASK)

#define RESETCON_RSTSTAT_PIN_POR_MASK            (0x4U)
#define RESETCON_RSTSTAT_PIN_POR_SHIFT           (2U)
/*! PIN_POR - POR_b Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_PIN_POR(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_PIN_POR_SHIFT)) & RESETCON_RSTSTAT_PIN_POR_MASK)

#define RESETCON_RSTSTAT_PMU_COLD_MASK           (0x8U)
#define RESETCON_RSTSTAT_PMU_COLD_SHIFT          (3U)
/*! PMU_COLD - PMU Cold Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_PMU_COLD(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_PMU_COLD_SHIFT)) & RESETCON_RSTSTAT_PMU_COLD_MASK)

#define RESETCON_RSTSTAT_WU_VBAT_MASK            (0x10U)
#define RESETCON_RSTSTAT_WU_VBAT_SHIFT           (4U)
/*! WU_VBAT - VBAT Wakeup Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_WU_VBAT(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_WU_VBAT_SHIFT)) & RESETCON_RSTSTAT_WU_VBAT_MASK)

#define RESETCON_RSTSTAT_SEC_COLD_MASK           (0x20U)
#define RESETCON_RSTSTAT_SEC_COLD_SHIFT          (5U)
/*! SEC_COLD - Security Cold Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_SEC_COLD(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_SEC_COLD_SHIFT)) & RESETCON_RSTSTAT_SEC_COLD_MASK)

#define RESETCON_RSTSTAT_WARM_ESCA_MASK          (0x40U)
#define RESETCON_RSTSTAT_WARM_ESCA_SHIFT         (6U)
/*! WARM_ESCA - Warm Reset Escalate to Cold Reset
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_WARM_ESCA(x)            (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_WARM_ESCA_SHIFT)) & RESETCON_RSTSTAT_WARM_ESCA_MASK)

#define RESETCON_RSTSTAT_RST_ERR_MASK            (0x80U)
#define RESETCON_RSTSTAT_RST_ERR_SHIFT           (7U)
/*! RST_ERR - RESETCON Error Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_RST_ERR(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_RST_ERR_SHIFT)) & RESETCON_RSTSTAT_RST_ERR_MASK)

#define RESETCON_RSTSTAT_PIN_RESET_MASK          (0x100U)
#define RESETCON_RSTSTAT_PIN_RESET_SHIFT         (8U)
/*! PIN_RESET - RESET_b Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_PIN_RESET(x)            (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_PIN_RESET_SHIFT)) & RESETCON_RSTSTAT_PIN_RESET_MASK)

#define RESETCON_RSTSTAT_RESET_SW_MASK           (0x200U)
#define RESETCON_RSTSTAT_RESET_SW_SHIFT          (9U)
/*! RESET_SW - Software-Initiated Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_RESET_SW(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_RESET_SW_SHIFT)) & RESETCON_RSTSTAT_RESET_SW_MASK)

#define RESETCON_RSTSTAT_DAP_MASK                (0x400U)
#define RESETCON_RSTSTAT_DAP_SHIFT               (10U)
/*! DAP - DAP or MDM-AP JTAG Software Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_DAP(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_DAP_SHIFT)) & RESETCON_RSTSTAT_DAP_MASK)

#define RESETCON_RSTSTAT_JTAG_MASK               (0x800U)
#define RESETCON_RSTSTAT_JTAG_SHIFT              (11U)
/*! JTAG - JTAG Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_JTAG(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_JTAG_SHIFT)) & RESETCON_RSTSTAT_JTAG_MASK)

#define RESETCON_RSTSTAT_CPU0_SW_MASK            (0x1000U)
#define RESETCON_RSTSTAT_CPU0_SW_SHIFT           (12U)
/*! CPU0_SW - CPU0 Software Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_CPU0_SW(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_CPU0_SW_SHIFT)) & RESETCON_RSTSTAT_CPU0_SW_MASK)

#define RESETCON_RSTSTAT_CPU0_ERR_MASK           (0x2000U)
#define RESETCON_RSTSTAT_CPU0_ERR_SHIFT          (13U)
/*! CPU0_ERR - CPU0 Lock Up Condition Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_CPU0_ERR(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_CPU0_ERR_SHIFT)) & RESETCON_RSTSTAT_CPU0_ERR_MASK)

#define RESETCON_RSTSTAT_SWT0_MASK               (0x4000U)
#define RESETCON_RSTSTAT_SWT0_SHIFT              (14U)
/*! SWT0 - SWT_0 Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_SWT0(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_SWT0_SHIFT)) & RESETCON_RSTSTAT_SWT0_MASK)

#define RESETCON_RSTSTAT_SWT1_MASK               (0x8000U)
#define RESETCON_RSTSTAT_SWT1_SHIFT              (15U)
/*! SWT1 - SWT_1 Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_SWT1(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_SWT1_SHIFT)) & RESETCON_RSTSTAT_SWT1_MASK)

#define RESETCON_RSTSTAT_SECVIO_MASK             (0x10000U)
#define RESETCON_RSTSTAT_SECVIO_SHIFT            (16U)
/*! SECVIO - Security Violation Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_SECVIO(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_SECVIO_SHIFT)) & RESETCON_RSTSTAT_SECVIO_MASK)

#define RESETCON_RSTSTAT_TAMPER_MASK             (0x20000U)
#define RESETCON_RSTSTAT_TAMPER_SHIFT            (17U)
/*! TAMPER - Tamper Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_TAMPER(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_TAMPER_SHIFT)) & RESETCON_RSTSTAT_TAMPER_MASK)

#define RESETCON_RSTSTAT_PMU_WARM_MASK           (0x40000U)
#define RESETCON_RSTSTAT_PMU_WARM_SHIFT          (18U)
/*! PMU_WARM - PMU Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_PMU_WARM(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_PMU_WARM_SHIFT)) & RESETCON_RSTSTAT_PMU_WARM_MASK)

#define RESETCON_RSTSTAT_WU_PD_MASK              (0x80000U)
#define RESETCON_RSTSTAT_WU_PD_SHIFT             (19U)
/*! WU_PD - Power Down Mode Wakeup Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_WU_PD(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_WU_PD_SHIFT)) & RESETCON_RSTSTAT_WU_PD_MASK)
/*! @} */

/*! @name RSTSTAT_STICKY - Sticky Reset Status */
/*! @{ */

#define RESETCON_RSTSTAT_STICKY_POR_VBAT_MASK    (0x1U)
#define RESETCON_RSTSTAT_STICKY_POR_VBAT_SHIFT   (0U)
/*! POR_VBAT - VBAT Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_POR_VBAT(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_POR_VBAT_SHIFT)) & RESETCON_RSTSTAT_STICKY_POR_VBAT_MASK)

#define RESETCON_RSTSTAT_STICKY_PMU_POR_MASK     (0x2U)
#define RESETCON_RSTSTAT_STICKY_PMU_POR_SHIFT    (1U)
/*! PMU_POR - PMU Internal Supply Power On Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_PMU_POR(x)       (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_PMU_POR_SHIFT)) & RESETCON_RSTSTAT_STICKY_PMU_POR_MASK)

#define RESETCON_RSTSTAT_STICKY_PIN_POR_MASK     (0x4U)
#define RESETCON_RSTSTAT_STICKY_PIN_POR_SHIFT    (2U)
/*! PIN_POR - POR_b Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_PIN_POR(x)       (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_PIN_POR_SHIFT)) & RESETCON_RSTSTAT_STICKY_PIN_POR_MASK)

#define RESETCON_RSTSTAT_STICKY_PMU_COLD_MASK    (0x8U)
#define RESETCON_RSTSTAT_STICKY_PMU_COLD_SHIFT   (3U)
/*! PMU_COLD - PMU Cold Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_PMU_COLD(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_PMU_COLD_SHIFT)) & RESETCON_RSTSTAT_STICKY_PMU_COLD_MASK)

#define RESETCON_RSTSTAT_STICKY_WU_VBAT_MASK     (0x10U)
#define RESETCON_RSTSTAT_STICKY_WU_VBAT_SHIFT    (4U)
/*! WU_VBAT - VBAT Wakeup Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_WU_VBAT(x)       (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_WU_VBAT_SHIFT)) & RESETCON_RSTSTAT_STICKY_WU_VBAT_MASK)

#define RESETCON_RSTSTAT_STICKY_SEC_COLD_MASK    (0x20U)
#define RESETCON_RSTSTAT_STICKY_SEC_COLD_SHIFT   (5U)
/*! SEC_COLD - Security Cold Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_SEC_COLD(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_SEC_COLD_SHIFT)) & RESETCON_RSTSTAT_STICKY_SEC_COLD_MASK)

#define RESETCON_RSTSTAT_STICKY_WARM_ESCA_MASK   (0x40U)
#define RESETCON_RSTSTAT_STICKY_WARM_ESCA_SHIFT  (6U)
/*! WARM_ESCA - Warm Reset Escalate to Cold Reset
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_WARM_ESCA(x)     (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_WARM_ESCA_SHIFT)) & RESETCON_RSTSTAT_STICKY_WARM_ESCA_MASK)

#define RESETCON_RSTSTAT_STICKY_RST_ERR_MASK     (0x80U)
#define RESETCON_RSTSTAT_STICKY_RST_ERR_SHIFT    (7U)
/*! RST_ERR - RESETCON Error Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_RST_ERR(x)       (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_RST_ERR_SHIFT)) & RESETCON_RSTSTAT_STICKY_RST_ERR_MASK)

#define RESETCON_RSTSTAT_STICKY_PIN_RESET_MASK   (0x100U)
#define RESETCON_RSTSTAT_STICKY_PIN_RESET_SHIFT  (8U)
/*! PIN_RESET - RESET_b Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_PIN_RESET(x)     (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_PIN_RESET_SHIFT)) & RESETCON_RSTSTAT_STICKY_PIN_RESET_MASK)

#define RESETCON_RSTSTAT_STICKY_RESET_SW_MASK    (0x200U)
#define RESETCON_RSTSTAT_STICKY_RESET_SW_SHIFT   (9U)
/*! RESET_SW - Software-Initiated Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_RESET_SW(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_RESET_SW_SHIFT)) & RESETCON_RSTSTAT_STICKY_RESET_SW_MASK)

#define RESETCON_RSTSTAT_STICKY_DAP_MASK         (0x400U)
#define RESETCON_RSTSTAT_STICKY_DAP_SHIFT        (10U)
/*! DAP - DAP or MDM-AP JTAG Software Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_DAP(x)           (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_DAP_SHIFT)) & RESETCON_RSTSTAT_STICKY_DAP_MASK)

#define RESETCON_RSTSTAT_STICKY_JTAG_MASK        (0x800U)
#define RESETCON_RSTSTAT_STICKY_JTAG_SHIFT       (11U)
/*! JTAG - JTAG Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_JTAG(x)          (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_JTAG_SHIFT)) & RESETCON_RSTSTAT_STICKY_JTAG_MASK)

#define RESETCON_RSTSTAT_STICKY_CPU0_SW_MASK     (0x1000U)
#define RESETCON_RSTSTAT_STICKY_CPU0_SW_SHIFT    (12U)
/*! CPU0_SW - CPU0 Software Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_CPU0_SW(x)       (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_CPU0_SW_SHIFT)) & RESETCON_RSTSTAT_STICKY_CPU0_SW_MASK)

#define RESETCON_RSTSTAT_STICKY_CPU0_ERR_MASK    (0x2000U)
#define RESETCON_RSTSTAT_STICKY_CPU0_ERR_SHIFT   (13U)
/*! CPU0_ERR - CPU0 Lock Up Condition Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_CPU0_ERR(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_CPU0_ERR_SHIFT)) & RESETCON_RSTSTAT_STICKY_CPU0_ERR_MASK)

#define RESETCON_RSTSTAT_STICKY_SWT0_MASK        (0x4000U)
#define RESETCON_RSTSTAT_STICKY_SWT0_SHIFT       (14U)
/*! SWT0 - SWT_0 Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_SWT0(x)          (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_SWT0_SHIFT)) & RESETCON_RSTSTAT_STICKY_SWT0_MASK)

#define RESETCON_RSTSTAT_STICKY_SWT1_MASK        (0x8000U)
#define RESETCON_RSTSTAT_STICKY_SWT1_SHIFT       (15U)
/*! SWT1 - SWT_1 Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_SWT1(x)          (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_SWT1_SHIFT)) & RESETCON_RSTSTAT_STICKY_SWT1_MASK)

#define RESETCON_RSTSTAT_STICKY_SECVIO_MASK      (0x10000U)
#define RESETCON_RSTSTAT_STICKY_SECVIO_SHIFT     (16U)
/*! SECVIO - Security Violation Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_SECVIO(x)        (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_SECVIO_SHIFT)) & RESETCON_RSTSTAT_STICKY_SECVIO_MASK)

#define RESETCON_RSTSTAT_STICKY_TAMPER_MASK      (0x20000U)
#define RESETCON_RSTSTAT_STICKY_TAMPER_SHIFT     (17U)
/*! TAMPER - Tamper Pin Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_TAMPER(x)        (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_TAMPER_SHIFT)) & RESETCON_RSTSTAT_STICKY_TAMPER_MASK)

#define RESETCON_RSTSTAT_STICKY_PMU_WARM_MASK    (0x40000U)
#define RESETCON_RSTSTAT_STICKY_PMU_WARM_SHIFT   (18U)
/*! PMU_WARM - PMU Warm Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_PMU_WARM(x)      (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_PMU_WARM_SHIFT)) & RESETCON_RSTSTAT_STICKY_PMU_WARM_MASK)

#define RESETCON_RSTSTAT_STICKY_WU_PD_MASK       (0x80000U)
#define RESETCON_RSTSTAT_STICKY_WU_PD_SHIFT      (19U)
/*! WU_PD - Power Down Mode Wakeup Reset Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTSTAT_STICKY_WU_PD(x)         (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTSTAT_STICKY_WU_PD_SHIFT)) & RESETCON_RSTSTAT_STICKY_WU_PD_MASK)
/*! @} */

/*! @name PD_RSTSTAT - Power Domain Reset Status */
/*! @{ */

#define RESETCON_PD_RSTSTAT_PD_WAKE_MASK         (0x1U)
#define RESETCON_PD_RSTSTAT_PD_WAKE_SHIFT        (0U)
/*! PD_WAKE - Wake Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_WAKE(x)           (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_WAKE_SHIFT)) & RESETCON_PD_RSTSTAT_PD_WAKE_MASK)

#define RESETCON_PD_RSTSTAT_PD_MAIN_MASK         (0x2U)
#define RESETCON_PD_RSTSTAT_PD_MAIN_SHIFT        (1U)
/*! PD_MAIN - Main Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_MAIN(x)           (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_MAIN_SHIFT)) & RESETCON_PD_RSTSTAT_PD_MAIN_MASK)

#define RESETCON_PD_RSTSTAT_PD_CPU_MASK          (0x4U)
#define RESETCON_PD_RSTSTAT_PD_CPU_SHIFT         (2U)
/*! PD_CPU - Cortex-M85 Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_CPU(x)            (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_CPU_SHIFT)) & RESETCON_PD_RSTSTAT_PD_CPU_MASK)

#define RESETCON_PD_RSTSTAT_PD_NPU_MASK          (0x8U)
#define RESETCON_PD_RSTSTAT_PD_NPU_SHIFT         (3U)
/*! PD_NPU - NPU Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_NPU(x)            (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_NPU_SHIFT)) & RESETCON_PD_RSTSTAT_PD_NPU_MASK)

#define RESETCON_PD_RSTSTAT_PD_MEDIA_MASK        (0x10U)
#define RESETCON_PD_RSTSTAT_PD_MEDIA_SHIFT       (4U)
/*! PD_MEDIA - Media Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_MEDIA(x)          (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_MEDIA_SHIFT)) & RESETCON_PD_RSTSTAT_PD_MEDIA_MASK)

#define RESETCON_PD_RSTSTAT_PD_COMM_MASK         (0x20U)
#define RESETCON_PD_RSTSTAT_PD_COMM_SHIFT        (5U)
/*! PD_COMM - Communication Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset ongoing
 */
#define RESETCON_PD_RSTSTAT_PD_COMM(x)           (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_PD_COMM_SHIFT)) & RESETCON_PD_RSTSTAT_PD_COMM_MASK)
/*! @} */

/*! @name PD_RSTSTAT_STICKY - Sticky Power Domain Reset Status */
/*! @{ */

#define RESETCON_PD_RSTSTAT_STICKY_PD_WAKE_MASK  (0x1U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_WAKE_SHIFT (0U)
/*! PD_WAKE - Wake Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_WAKE(x)    (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_WAKE_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_WAKE_MASK)

#define RESETCON_PD_RSTSTAT_STICKY_PD_MAIN_MASK  (0x2U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_MAIN_SHIFT (1U)
/*! PD_MAIN - Main Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_MAIN(x)    (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_MAIN_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_MAIN_MASK)

#define RESETCON_PD_RSTSTAT_STICKY_PD_CPU_MASK   (0x4U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_CPU_SHIFT  (2U)
/*! PD_CPU - Cortex-M85 Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_CPU(x)     (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_CPU_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_CPU_MASK)

#define RESETCON_PD_RSTSTAT_STICKY_PD_NPU_MASK   (0x8U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_NPU_SHIFT  (3U)
/*! PD_NPU - NPU Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_NPU(x)     (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_NPU_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_NPU_MASK)

#define RESETCON_PD_RSTSTAT_STICKY_PD_MEDIA_MASK (0x10U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_MEDIA_SHIFT (4U)
/*! PD_MEDIA - Media Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_MEDIA(x)   (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_MEDIA_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_MEDIA_MASK)

#define RESETCON_PD_RSTSTAT_STICKY_PD_COMM_MASK  (0x20U)
#define RESETCON_PD_RSTSTAT_STICKY_PD_COMM_SHIFT (5U)
/*! PD_COMM - Communication Power Domain Reset Status
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTSTAT_STICKY_PD_COMM(x)    (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTSTAT_STICKY_PD_COMM_SHIFT)) & RESETCON_PD_RSTSTAT_STICKY_PD_COMM_MASK)
/*! @} */

/*! @name PD_RSTCTRL - Power Domain Reset Control */
/*! @{ */

#define RESETCON_PD_RSTCTRL_PD_NPU_MASK          (0x8U)
#define RESETCON_PD_RSTCTRL_PD_NPU_SHIFT         (3U)
/*! PD_NPU - NPU Power Domain Reset Control
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTCTRL_PD_NPU(x)            (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTCTRL_PD_NPU_SHIFT)) & RESETCON_PD_RSTCTRL_PD_NPU_MASK)

#define RESETCON_PD_RSTCTRL_PD_MEDIA_MASK        (0x10U)
#define RESETCON_PD_RSTCTRL_PD_MEDIA_SHIFT       (4U)
/*! PD_MEDIA - Media Power Domain Reset Control
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTCTRL_PD_MEDIA(x)          (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTCTRL_PD_MEDIA_SHIFT)) & RESETCON_PD_RSTCTRL_PD_MEDIA_MASK)

#define RESETCON_PD_RSTCTRL_PD_COMM_MASK         (0x20U)
#define RESETCON_PD_RSTCTRL_PD_COMM_SHIFT        (5U)
/*! PD_COMM - Communication Power Domain Reset Control
 *  0b0..Not reset
 *  0b1..Reset
 */
#define RESETCON_PD_RSTCTRL_PD_COMM(x)           (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTCTRL_PD_COMM_SHIFT)) & RESETCON_PD_RSTCTRL_PD_COMM_MASK)

#define RESETCON_PD_RSTCTRL_MAGIC_MASK           (0xFFFF0000U)
#define RESETCON_PD_RSTCTRL_MAGIC_SHIFT          (16U)
/*! MAGIC - Magic Value */
#define RESETCON_PD_RSTCTRL_MAGIC(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_PD_RSTCTRL_MAGIC_SHIFT)) & RESETCON_PD_RSTCTRL_MAGIC_MASK)
/*! @} */

/*! @name INITS - Initialization Status */
/*! @{ */

#define RESETCON_INITS_PMU_BE_MASK               (0x3FU)
#define RESETCON_INITS_PMU_BE_SHIFT              (0U)
/*! PMU_BE - PMU Boot Error Status */
#define RESETCON_INITS_PMU_BE(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_INITS_PMU_BE_SHIFT)) & RESETCON_INITS_PMU_BE_MASK)
/*! @} */

/*! @name ESCAEN - Reset Escalation Enable */
/*! @{ */

#define RESETCON_ESCAEN_PIN_RESET_MASK           (0x1U)
#define RESETCON_ESCAEN_PIN_RESET_SHIFT          (0U)
/*! PIN_RESET - RESET_b Pin Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_PIN_RESET(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_PIN_RESET_SHIFT)) & RESETCON_ESCAEN_PIN_RESET_MASK)

#define RESETCON_ESCAEN_RESET_SW_MASK            (0x2U)
#define RESETCON_ESCAEN_RESET_SW_SHIFT           (1U)
/*! RESET_SW - Software Reset Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_RESET_SW(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_RESET_SW_SHIFT)) & RESETCON_ESCAEN_RESET_SW_MASK)

#define RESETCON_ESCAEN_DAP_MASK                 (0x4U)
#define RESETCON_ESCAEN_DAP_SHIFT                (2U)
/*! DAP - DAP Reset Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_DAP(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_DAP_SHIFT)) & RESETCON_ESCAEN_DAP_MASK)

#define RESETCON_ESCAEN_JTAG_MASK                (0x8U)
#define RESETCON_ESCAEN_JTAG_SHIFT               (3U)
/*! JTAG - JTAG Reset Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_JTAG(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_JTAG_SHIFT)) & RESETCON_ESCAEN_JTAG_MASK)

#define RESETCON_ESCAEN_CPU0_SW_MASK             (0x10U)
#define RESETCON_ESCAEN_CPU0_SW_SHIFT            (4U)
/*! CPU0_SW - CPU0 Software Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_CPU0_SW(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_CPU0_SW_SHIFT)) & RESETCON_ESCAEN_CPU0_SW_MASK)

#define RESETCON_ESCAEN_CPU0_ERR_MASK            (0x20U)
#define RESETCON_ESCAEN_CPU0_ERR_SHIFT           (5U)
/*! CPU0_ERR - CPU0 Error Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_CPU0_ERR(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_CPU0_ERR_SHIFT)) & RESETCON_ESCAEN_CPU0_ERR_MASK)

#define RESETCON_ESCAEN_SWT0_MASK                (0x40U)
#define RESETCON_ESCAEN_SWT0_SHIFT               (6U)
/*! SWT0 - SWT_0 Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_SWT0(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_SWT0_SHIFT)) & RESETCON_ESCAEN_SWT0_MASK)

#define RESETCON_ESCAEN_SWT1_MASK                (0x80U)
#define RESETCON_ESCAEN_SWT1_SHIFT               (7U)
/*! SWT1 - SWT_1 Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_SWT1(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_SWT1_SHIFT)) & RESETCON_ESCAEN_SWT1_MASK)

#define RESETCON_ESCAEN_SECVIO_MASK              (0x100U)
#define RESETCON_ESCAEN_SECVIO_SHIFT             (8U)
/*! SECVIO - Security Violation Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_SECVIO(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_SECVIO_SHIFT)) & RESETCON_ESCAEN_SECVIO_MASK)

#define RESETCON_ESCAEN_TAMPER_MASK              (0x200U)
#define RESETCON_ESCAEN_TAMPER_SHIFT             (9U)
/*! TAMPER - Tamper Pin Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_TAMPER(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_TAMPER_SHIFT)) & RESETCON_ESCAEN_TAMPER_MASK)

#define RESETCON_ESCAEN_PMU_WARM_MASK            (0x400U)
#define RESETCON_ESCAEN_PMU_WARM_SHIFT           (10U)
/*! PMU_WARM - PMU Warm Reset Escalation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_ESCAEN_PMU_WARM(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_ESCAEN_PMU_WARM_SHIFT)) & RESETCON_ESCAEN_PMU_WARM_MASK)
/*! @} */

/*! @name RSTIE - Reset Interrupt Enable */
/*! @{ */

#define RESETCON_RSTIE_PIN_RESET_MASK            (0x1U)
#define RESETCON_RSTIE_PIN_RESET_SHIFT           (0U)
/*! PIN_RESET - RESET_b Pin Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_PIN_RESET(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_PIN_RESET_SHIFT)) & RESETCON_RSTIE_PIN_RESET_MASK)

#define RESETCON_RSTIE_DAP_MASK                  (0x4U)
#define RESETCON_RSTIE_DAP_SHIFT                 (2U)
/*! DAP - DAP Reset Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_DAP(x)                    (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_DAP_SHIFT)) & RESETCON_RSTIE_DAP_MASK)

#define RESETCON_RSTIE_JTAG_MASK                 (0x8U)
#define RESETCON_RSTIE_JTAG_SHIFT                (3U)
/*! JTAG - JTAG Reset Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_JTAG(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_JTAG_SHIFT)) & RESETCON_RSTIE_JTAG_MASK)

#define RESETCON_RSTIE_CPU0_SW_MASK              (0x10U)
#define RESETCON_RSTIE_CPU0_SW_SHIFT             (4U)
/*! CPU0_SW - CPU0 Software Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_CPU0_SW(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_CPU0_SW_SHIFT)) & RESETCON_RSTIE_CPU0_SW_MASK)

#define RESETCON_RSTIE_CPU0_ERR_MASK             (0x20U)
#define RESETCON_RSTIE_CPU0_ERR_SHIFT            (5U)
/*! CPU0_ERR - CPU0 Error Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_CPU0_ERR(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_CPU0_ERR_SHIFT)) & RESETCON_RSTIE_CPU0_ERR_MASK)

#define RESETCON_RSTIE_SWT0_MASK                 (0x40U)
#define RESETCON_RSTIE_SWT0_SHIFT                (6U)
/*! SWT0 - SWT_0 Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_SWT0(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_SWT0_SHIFT)) & RESETCON_RSTIE_SWT0_MASK)

#define RESETCON_RSTIE_SWT1_MASK                 (0x80U)
#define RESETCON_RSTIE_SWT1_SHIFT                (7U)
/*! SWT1 - SWT_1 Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_SWT1(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_SWT1_SHIFT)) & RESETCON_RSTIE_SWT1_MASK)

#define RESETCON_RSTIE_SECVIO_MASK               (0x100U)
#define RESETCON_RSTIE_SECVIO_SHIFT              (8U)
/*! SECVIO - Security Violation Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_SECVIO(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_SECVIO_SHIFT)) & RESETCON_RSTIE_SECVIO_MASK)

#define RESETCON_RSTIE_TAMPER_MASK               (0x200U)
#define RESETCON_RSTIE_TAMPER_SHIFT              (9U)
/*! TAMPER - Tamper Pin Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_TAMPER(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_TAMPER_SHIFT)) & RESETCON_RSTIE_TAMPER_MASK)

#define RESETCON_RSTIE_PMU_WARM_MASK             (0x400U)
#define RESETCON_RSTIE_PMU_WARM_SHIFT            (10U)
/*! PMU_WARM - PMU Warm Reset Interrupt Enable
 *  0b0..Disables interrupt
 *  0b1..Enables interrupt
 */
#define RESETCON_RSTIE_PMU_WARM(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIE_PMU_WARM_SHIFT)) & RESETCON_RSTIE_PMU_WARM_MASK)
/*! @} */

/*! @name RSTIS - Reset Interrupt Status */
/*! @{ */

#define RESETCON_RSTIS_PIN_RESET_MASK            (0x1U)
#define RESETCON_RSTIS_PIN_RESET_SHIFT           (0U)
/*! PIN_RESET - RESET_b Pin Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_PIN_RESET(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_PIN_RESET_SHIFT)) & RESETCON_RSTIS_PIN_RESET_MASK)

#define RESETCON_RSTIS_DAP_MASK                  (0x4U)
#define RESETCON_RSTIS_DAP_SHIFT                 (2U)
/*! DAP - DAP Reset Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_DAP(x)                    (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_DAP_SHIFT)) & RESETCON_RSTIS_DAP_MASK)

#define RESETCON_RSTIS_JTAG_MASK                 (0x8U)
#define RESETCON_RSTIS_JTAG_SHIFT                (3U)
/*! JTAG - JTAG Reset Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_JTAG(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_JTAG_SHIFT)) & RESETCON_RSTIS_JTAG_MASK)

#define RESETCON_RSTIS_CPU0_SW_MASK              (0x10U)
#define RESETCON_RSTIS_CPU0_SW_SHIFT             (4U)
/*! CPU0_SW - CPU0 Software Reset Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_CPU0_SW(x)                (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_CPU0_SW_SHIFT)) & RESETCON_RSTIS_CPU0_SW_MASK)

#define RESETCON_RSTIS_CPU0_ERR_MASK             (0x20U)
#define RESETCON_RSTIS_CPU0_ERR_SHIFT            (5U)
/*! CPU0_ERR - CPU0 Error Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_CPU0_ERR(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_CPU0_ERR_SHIFT)) & RESETCON_RSTIS_CPU0_ERR_MASK)

#define RESETCON_RSTIS_SWT0_MASK                 (0x40U)
#define RESETCON_RSTIS_SWT0_SHIFT                (6U)
/*! SWT0 - SWT_0 Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_SWT0(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_SWT0_SHIFT)) & RESETCON_RSTIS_SWT0_MASK)

#define RESETCON_RSTIS_SWT1_MASK                 (0x80U)
#define RESETCON_RSTIS_SWT1_SHIFT                (7U)
/*! SWT1 - SWT_1 Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_SWT1(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_SWT1_SHIFT)) & RESETCON_RSTIS_SWT1_MASK)

#define RESETCON_RSTIS_SECVIO_MASK               (0x100U)
#define RESETCON_RSTIS_SECVIO_SHIFT              (8U)
/*! SECVIO - Security Violation Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_SECVIO(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_SECVIO_SHIFT)) & RESETCON_RSTIS_SECVIO_MASK)

#define RESETCON_RSTIS_TAMPER_MASK               (0x200U)
#define RESETCON_RSTIS_TAMPER_SHIFT              (9U)
/*! TAMPER - Tamper Pin Escalation Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_TAMPER(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_TAMPER_SHIFT)) & RESETCON_RSTIS_TAMPER_MASK)

#define RESETCON_RSTIS_PMU_WARM_MASK             (0x400U)
#define RESETCON_RSTIS_PMU_WARM_SHIFT            (10U)
/*! PMU_WARM - PMU Warm Reset Interrupt Status
 *  0b0..Invalid
 *  0b1..Valid
 */
#define RESETCON_RSTIS_PMU_WARM(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTIS_PMU_WARM_SHIFT)) & RESETCON_RSTIS_PMU_WARM_MASK)
/*! @} */

/*! @name ITO - Reset Interrupt Timeout */
/*! @{ */

#define RESETCON_ITO_ITIMEOUT_MASK               (0xFFFFFFFFU)
#define RESETCON_ITO_ITIMEOUT_SHIFT              (0U)
/*! ITIMEOUT - Interrupt Timeout */
#define RESETCON_ITO_ITIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_ITO_ITIMEOUT_SHIFT)) & RESETCON_ITO_ITIMEOUT_MASK)
/*! @} */

/*! @name RSTCNT - Reset Count */
/*! @{ */

#define RESETCON_RSTCNT_RCNT_MASK                (0xFFFFFFFFU)
#define RESETCON_RSTCNT_RCNT_SHIFT               (0U)
/*! RCNT - Reset Count */
#define RESETCON_RSTCNT_RCNT(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_RSTCNT_RCNT_SHIFT)) & RESETCON_RSTCNT_RCNT_MASK)
/*! @} */

/*! @name RTO - Reset Timeout */
/*! @{ */

#define RESETCON_RTO_RTIMEOUT_MASK               (0xFFFU)
#define RESETCON_RTO_RTIMEOUT_SHIFT              (0U)
/*! RTIMEOUT - Reset Timeout */
#define RESETCON_RTO_RTIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_RTO_RTIMEOUT_SHIFT)) & RESETCON_RTO_RTIMEOUT_MASK)
/*! @} */

/*! @name FILTER - Reset Filter */
/*! @{ */

#define RESETCON_FILTER_FTIME_MASK               (0xFFFFU)
#define RESETCON_FILTER_FTIME_SHIFT              (0U)
/*! FTIME - Reset Filter */
#define RESETCON_FILTER_FTIME(x)                 (((uint32_t)(((uint32_t)(x)) << RESETCON_FILTER_FTIME_SHIFT)) & RESETCON_FILTER_FTIME_MASK)
/*! @} */

/*! @name ROUT - Reset Output */
/*! @{ */

#define RESETCON_ROUT_OUTEN_MASK                 (0x1U)
#define RESETCON_ROUT_OUTEN_SHIFT                (0U)
/*! OUTEN - Reset Output
 *  0b0..Disables RESET_b
 *  0b1..Enables RESET_b
 */
#define RESETCON_ROUT_OUTEN(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_ROUT_OUTEN_SHIFT)) & RESETCON_ROUT_OUTEN_MASK)
/*! @} */

/*! @name MODESTAT - Boot Mode Status */
/*! @{ */

#define RESETCON_MODESTAT_MS_MASK                (0x3U)
#define RESETCON_MODESTAT_MS_SHIFT               (0U)
/*! MS - Boot Mode Status */
#define RESETCON_MODESTAT_MS(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_MODESTAT_MS_SHIFT)) & RESETCON_MODESTAT_MS_MASK)
/*! @} */

/*! @name MODECTRL - Boot Mode Control */
/*! @{ */

#define RESETCON_MODECTRL_MC_MASK                (0x3U)
#define RESETCON_MODECTRL_MC_SHIFT               (0U)
/*! MC - Boot Mode Control */
#define RESETCON_MODECTRL_MC(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_MODECTRL_MC_SHIFT)) & RESETCON_MODECTRL_MC_MASK)

#define RESETCON_MODECTRL_ME_MASK                (0x80000000U)
#define RESETCON_MODECTRL_ME_SHIFT               (31U)
/*! ME - Boot Mode Control Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_MODECTRL_ME(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_MODECTRL_ME_SHIFT)) & RESETCON_MODECTRL_ME_MASK)
/*! @} */

/*! @name PORPC - POR_b Pin Reset Control */
/*! @{ */

#define RESETCON_PORPC_PFT_MASK                  (0xFFFFU)
#define RESETCON_PORPC_PFT_SHIFT                 (0U)
/*! PFT - POR_b Pin Filter */
#define RESETCON_PORPC_PFT(x)                    (((uint32_t)(((uint32_t)(x)) << RESETCON_PORPC_PFT_SHIFT)) & RESETCON_PORPC_PFT_MASK)

#define RESETCON_PORPC_TPC_MASK                  (0x10000U)
#define RESETCON_PORPC_TPC_SHIFT                 (16U)
/*! TPC - POR_b Pin Trigger PMU Restart
 *  0b0..Disables
 *  0b1..Enables
 */
#define RESETCON_PORPC_TPC(x)                    (((uint32_t)(((uint32_t)(x)) << RESETCON_PORPC_TPC_SHIFT)) & RESETCON_PORPC_TPC_MASK)
/*! @} */

/*! @name RMSK - Reset Mask */
/*! @{ */

#define RESETCON_RMSK_RMASK_MASK                 (0x7FFU)
#define RESETCON_RMSK_RMASK_SHIFT                (0U)
/*! RMASK - Reset Mask Enable
 *  0b00000000000..Disables
 *  0b00000000001..Enables (masks)
 */
#define RESETCON_RMSK_RMASK(x)                   (((uint32_t)(((uint32_t)(x)) << RESETCON_RMSK_RMASK_SHIFT)) & RESETCON_RMSK_RMASK_MASK)
/*! @} */

/*! @name RTM - Reset Trigger Mode */
/*! @{ */

#define RESETCON_RTM_RTRGM_MASK                  (0x7FFU)
#define RESETCON_RTM_RTRGM_SHIFT                 (0U)
/*! RTRGM - Reset Trigger Mode Control
 *  0b00000000000..Level trigger
 *  0b00000000001..Edge trigger
 */
#define RESETCON_RTM_RTRGM(x)                    (((uint32_t)(((uint32_t)(x)) << RESETCON_RTM_RTRGM_SHIFT)) & RESETCON_RTM_RTRGM_MASK)
/*! @} */

/*! @name MISCCTRL - Misc Control */
/*! @{ */

#define RESETCON_MISCCTRL_QRSP_EN_MASK           (0x1U)
#define RESETCON_MISCCTRL_QRSP_EN_SHIFT          (0U)
/*! QRSP_EN - Quick response warm reset enable
 *  0b0..Level trigger
 *  0b1..Edge trigger
 */
#define RESETCON_MISCCTRL_QRSP_EN(x)             (((uint32_t)(((uint32_t)(x)) << RESETCON_MISCCTRL_QRSP_EN_SHIFT)) & RESETCON_MISCCTRL_QRSP_EN_MASK)

#define RESETCON_MISCCTRL_ACGOV_MASK             (0x80000000U)
#define RESETCON_MISCCTRL_ACGOV_SHIFT            (31U)
/*! ACGOV - Auto clock gating override
 *  0b0..Disable (use auto clock gating)
 *  0b1..Enable (override auto clock gating then clock is free running)
 */
#define RESETCON_MISCCTRL_ACGOV(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_MISCCTRL_ACGOV_SHIFT)) & RESETCON_MISCCTRL_ACGOV_MASK)
/*! @} */

/*! @name GPR_LOCK - General Purpose Register Lock */
/*! @{ */

#define RESETCON_GPR_LOCK_LOCK0_MASK             (0x1U)
#define RESETCON_GPR_LOCK_LOCK0_SHIFT            (0U)
/*! LOCK0 - GPR0 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK0(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK0_SHIFT)) & RESETCON_GPR_LOCK_LOCK0_MASK)

#define RESETCON_GPR_LOCK_LOCK1_MASK             (0x2U)
#define RESETCON_GPR_LOCK_LOCK1_SHIFT            (1U)
/*! LOCK1 - GPR1 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK1(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK1_SHIFT)) & RESETCON_GPR_LOCK_LOCK1_MASK)

#define RESETCON_GPR_LOCK_LOCK2_MASK             (0x4U)
#define RESETCON_GPR_LOCK_LOCK2_SHIFT            (2U)
/*! LOCK2 - GPR2 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK2(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK2_SHIFT)) & RESETCON_GPR_LOCK_LOCK2_MASK)

#define RESETCON_GPR_LOCK_LOCK3_MASK             (0x8U)
#define RESETCON_GPR_LOCK_LOCK3_SHIFT            (3U)
/*! LOCK3 - GPR3 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK3(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK3_SHIFT)) & RESETCON_GPR_LOCK_LOCK3_MASK)

#define RESETCON_GPR_LOCK_LOCK4_MASK             (0x10U)
#define RESETCON_GPR_LOCK_LOCK4_SHIFT            (4U)
/*! LOCK4 - GPR4 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK4(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK4_SHIFT)) & RESETCON_GPR_LOCK_LOCK4_MASK)

#define RESETCON_GPR_LOCK_LOCK5_MASK             (0x20U)
#define RESETCON_GPR_LOCK_LOCK5_SHIFT            (5U)
/*! LOCK5 - GPR5 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK5(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK5_SHIFT)) & RESETCON_GPR_LOCK_LOCK5_MASK)

#define RESETCON_GPR_LOCK_LOCK6_MASK             (0x40U)
#define RESETCON_GPR_LOCK_LOCK6_SHIFT            (6U)
/*! LOCK6 - GPR6 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK6(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK6_SHIFT)) & RESETCON_GPR_LOCK_LOCK6_MASK)

#define RESETCON_GPR_LOCK_LOCK7_MASK             (0x80U)
#define RESETCON_GPR_LOCK_LOCK7_SHIFT            (7U)
/*! LOCK7 - GPR7 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK7(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK7_SHIFT)) & RESETCON_GPR_LOCK_LOCK7_MASK)

#define RESETCON_GPR_LOCK_LOCK8_MASK             (0x100U)
#define RESETCON_GPR_LOCK_LOCK8_SHIFT            (8U)
/*! LOCK8 - GPR8 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK8(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK8_SHIFT)) & RESETCON_GPR_LOCK_LOCK8_MASK)

#define RESETCON_GPR_LOCK_LOCK9_MASK             (0x200U)
#define RESETCON_GPR_LOCK_LOCK9_SHIFT            (9U)
/*! LOCK9 - GPR9 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK9(x)               (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK9_SHIFT)) & RESETCON_GPR_LOCK_LOCK9_MASK)

#define RESETCON_GPR_LOCK_LOCK10_MASK            (0x400U)
#define RESETCON_GPR_LOCK_LOCK10_SHIFT           (10U)
/*! LOCK10 - GPR10 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK10(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK10_SHIFT)) & RESETCON_GPR_LOCK_LOCK10_MASK)

#define RESETCON_GPR_LOCK_LOCK11_MASK            (0x800U)
#define RESETCON_GPR_LOCK_LOCK11_SHIFT           (11U)
/*! LOCK11 - GPR11 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK11(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK11_SHIFT)) & RESETCON_GPR_LOCK_LOCK11_MASK)

#define RESETCON_GPR_LOCK_LOCK12_MASK            (0x1000U)
#define RESETCON_GPR_LOCK_LOCK12_SHIFT           (12U)
/*! LOCK12 - GPR12 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK12(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK12_SHIFT)) & RESETCON_GPR_LOCK_LOCK12_MASK)

#define RESETCON_GPR_LOCK_LOCK13_MASK            (0x2000U)
#define RESETCON_GPR_LOCK_LOCK13_SHIFT           (13U)
/*! LOCK13 - GPR13 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK13(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK13_SHIFT)) & RESETCON_GPR_LOCK_LOCK13_MASK)

#define RESETCON_GPR_LOCK_LOCK14_MASK            (0x4000U)
#define RESETCON_GPR_LOCK_LOCK14_SHIFT           (14U)
/*! LOCK14 - GPR14 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK14(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK14_SHIFT)) & RESETCON_GPR_LOCK_LOCK14_MASK)

#define RESETCON_GPR_LOCK_LOCK15_MASK            (0x8000U)
#define RESETCON_GPR_LOCK_LOCK15_SHIFT           (15U)
/*! LOCK15 - GPR15 Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define RESETCON_GPR_LOCK_LOCK15(x)              (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_LOCK_LOCK15_SHIFT)) & RESETCON_GPR_LOCK_LOCK15_MASK)
/*! @} */

/*! @name GPR - General Purpose Register 0..General Purpose Register 15 */
/*! @{ */

#define RESETCON_GPR_USERDEF_MASK                (0xFFFFFFFFU)
#define RESETCON_GPR_USERDEF_SHIFT               (0U)
/*! USERDEF - User Defined Bits */
#define RESETCON_GPR_USERDEF(x)                  (((uint32_t)(((uint32_t)(x)) << RESETCON_GPR_USERDEF_SHIFT)) & RESETCON_GPR_USERDEF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RESETCON_Register_Masks */


/*!
 * @}
 */ /* end of group RESETCON_Peripheral_Access_Layer */


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


#endif  /* PERI_RESETCON_H_ */

