/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBFSH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBFSH.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBFSH
 *
 * CMSIS Peripheral Access Layer for USBFSH
 */

#if !defined(PERI_USBFSH_H_)
#define PERI_USBFSH_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- USBFSH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBFSH_Peripheral_Access_Layer USBFSH Peripheral Access Layer
 * @{
 */

/** USBFSH - Register Layout Typedef */
typedef struct {
  __I  uint32_t HCREVISION;                        /**< Host controller revision, offset: 0x0 */
  __IO uint32_t HCCONTROL;                         /**< Host controller control, offset: 0x4 */
  __IO uint32_t HCCOMMANDSTATUS;                   /**< Host controller command status, offset: 0x8 */
  __IO uint32_t HCINTERRUPTSTATUS;                 /**< Host controller interrupt status, offset: 0xC */
  __IO uint32_t HCINTERRUPTENABLE;                 /**< Host Controller interrupt enable, offset: 0x10 */
  __IO uint32_t HCINTERRUPTDISABLE;                /**< The bits in this register are used to disable corresponding bits in the HCInterruptStatus register and in turn disable that event leading to hardware interrupt., offset: 0x14 */
  __IO uint32_t HCHCCA;                            /**< Host controller communication area, offset: 0x18 */
  __I  uint32_t HCPERIODCURRENTED;                 /**< Host controller period current endpoint descriptor, offset: 0x1C */
  __IO uint32_t HCCONTROLHEADED;                   /**< Host controller control head endpoint descriptor, offset: 0x20 */
  __IO uint32_t HCCONTROLCURRENTED;                /**< Host controller control current endpoint descriptor, offset: 0x24 */
  __IO uint32_t HCBULKHEADED;                      /**< Host controller bulk head endpoint descriptor, offset: 0x28 */
  __IO uint32_t HCBULKCURRENTED;                   /**< Host controller bulk current endpoint descriptor, offset: 0x2C */
  __I  uint32_t HCDONEHEAD;                        /**< Host controller done head, offset: 0x30 */
  __IO uint32_t HCFMINTERVAL;                      /**< Host controller frame interval, offset: 0x34 */
  __I  uint32_t HCFMREMAINING;                     /**< Host controller frame remaining, offset: 0x38 */
  __I  uint32_t HCFMNUMBER;                        /**< Host controller frame number, offset: 0x3C */
  __IO uint32_t HCPERIODICSTART;                   /**< Host controller periodic start, offset: 0x40 */
  __IO uint32_t HCLSTHRESHOLD;                     /**< Host controller low speed threshold, offset: 0x44 */
  __IO uint32_t HCRHDESCRIPTORA;                   /**< Host controller root hub descriptor A, offset: 0x48 */
  __IO uint32_t HCRHDESCRIPTORB;                   /**< Host controller root hub descriptor B, offset: 0x4C */
  __IO uint32_t HCRHSTATUS;                        /**< offset: 0x50 */
  __IO uint32_t HCRHPORTSTATUS;                    /**< Host controller root hub port status, offset: 0x54 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PORTMODE;                          /**< Port Mode, offset: 0x5C */
} USBFSH_Type;

/* ----------------------------------------------------------------------------
   -- USBFSH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBFSH_Register_Masks USBFSH Register Masks
 * @{
 */

/*! @name HCREVISION - Host controller revision */
/*! @{ */

#define USBFSH_HCREVISION_REV_MASK               (0xFFU)
#define USBFSH_HCREVISION_REV_SHIFT              (0U)
/*! REV - Revision */
#define USBFSH_HCREVISION_REV(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_HCREVISION_REV_SHIFT)) & USBFSH_HCREVISION_REV_MASK)
/*! @} */

/*! @name HCCONTROL - Host controller control */
/*! @{ */

#define USBFSH_HCCONTROL_CBSR_MASK               (0x3U)
#define USBFSH_HCCONTROL_CBSR_SHIFT              (0U)
/*! CBSR - ControlBulkServiceRatio. */
#define USBFSH_HCCONTROL_CBSR(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_CBSR_SHIFT)) & USBFSH_HCCONTROL_CBSR_MASK)

#define USBFSH_HCCONTROL_PLE_MASK                (0x4U)
#define USBFSH_HCCONTROL_PLE_SHIFT               (2U)
/*! PLE - PeriodicListEnable. */
#define USBFSH_HCCONTROL_PLE(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_PLE_SHIFT)) & USBFSH_HCCONTROL_PLE_MASK)

#define USBFSH_HCCONTROL_IE_MASK                 (0x8U)
#define USBFSH_HCCONTROL_IE_SHIFT                (3U)
/*! IE - IsochronousEnable. */
#define USBFSH_HCCONTROL_IE(x)                   (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_IE_SHIFT)) & USBFSH_HCCONTROL_IE_MASK)

#define USBFSH_HCCONTROL_CLE_MASK                (0x10U)
#define USBFSH_HCCONTROL_CLE_SHIFT               (4U)
/*! CLE - ControlListEnable. */
#define USBFSH_HCCONTROL_CLE(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_CLE_SHIFT)) & USBFSH_HCCONTROL_CLE_MASK)

#define USBFSH_HCCONTROL_BLE_MASK                (0x20U)
#define USBFSH_HCCONTROL_BLE_SHIFT               (5U)
/*! BLE - BulkListEnable This bit is set to enable the processing of the Bulk list in the next Frame. */
#define USBFSH_HCCONTROL_BLE(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_BLE_SHIFT)) & USBFSH_HCCONTROL_BLE_MASK)

#define USBFSH_HCCONTROL_HCFS_MASK               (0xC0U)
#define USBFSH_HCCONTROL_HCFS_SHIFT              (6U)
/*! HCFS - HostControllerFunctionalState
 *  0b00..USBRESET
 *  0b01..USBRESUME
 *  0b10..USBOPERATIONAL
 *  0b11..USBSUSPEND
 */
#define USBFSH_HCCONTROL_HCFS(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_HCFS_SHIFT)) & USBFSH_HCCONTROL_HCFS_MASK)

#define USBFSH_HCCONTROL_IR_MASK                 (0x100U)
#define USBFSH_HCCONTROL_IR_SHIFT                (8U)
/*! IR - InterruptRouting */
#define USBFSH_HCCONTROL_IR(x)                   (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_IR_SHIFT)) & USBFSH_HCCONTROL_IR_MASK)

#define USBFSH_HCCONTROL_RWC_MASK                (0x200U)
#define USBFSH_HCCONTROL_RWC_SHIFT               (9U)
/*! RWC - RemoteWakeupConnected This bit indicates whether HC supports remote wake-up signaling. */
#define USBFSH_HCCONTROL_RWC(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_RWC_SHIFT)) & USBFSH_HCCONTROL_RWC_MASK)

#define USBFSH_HCCONTROL_RWE_MASK                (0x400U)
#define USBFSH_HCCONTROL_RWE_SHIFT               (10U)
/*! RWE - RemoteWakeupEnable This bit is used by HCD to enable or disable the remote wake-up feature
 *    upon the detection of upstream resume signaling.
 */
#define USBFSH_HCCONTROL_RWE(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROL_RWE_SHIFT)) & USBFSH_HCCONTROL_RWE_MASK)
/*! @} */

/*! @name HCCOMMANDSTATUS - Host controller command status */
/*! @{ */

#define USBFSH_HCCOMMANDSTATUS_HCR_MASK          (0x1U)
#define USBFSH_HCCOMMANDSTATUS_HCR_SHIFT         (0U)
/*! HCR - HostControllerReset */
#define USBFSH_HCCOMMANDSTATUS_HCR(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCOMMANDSTATUS_HCR_SHIFT)) & USBFSH_HCCOMMANDSTATUS_HCR_MASK)

#define USBFSH_HCCOMMANDSTATUS_CLF_MASK          (0x2U)
#define USBFSH_HCCOMMANDSTATUS_CLF_SHIFT         (1U)
/*! CLF - ControlListFilled This bit is used to indicate whether there are any TDs on the Control list. */
#define USBFSH_HCCOMMANDSTATUS_CLF(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCOMMANDSTATUS_CLF_SHIFT)) & USBFSH_HCCOMMANDSTATUS_CLF_MASK)

#define USBFSH_HCCOMMANDSTATUS_BLF_MASK          (0x4U)
#define USBFSH_HCCOMMANDSTATUS_BLF_SHIFT         (2U)
/*! BLF - BulkListFilled This bit is used to indicate whether there are any TDs on the Bulk list. */
#define USBFSH_HCCOMMANDSTATUS_BLF(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCOMMANDSTATUS_BLF_SHIFT)) & USBFSH_HCCOMMANDSTATUS_BLF_MASK)

#define USBFSH_HCCOMMANDSTATUS_OCR_MASK          (0x8U)
#define USBFSH_HCCOMMANDSTATUS_OCR_SHIFT         (3U)
/*! OCR - OwnershipChangeRequest This bit is set by an OS HCD to request a change of control of the HC. */
#define USBFSH_HCCOMMANDSTATUS_OCR(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCOMMANDSTATUS_OCR_SHIFT)) & USBFSH_HCCOMMANDSTATUS_OCR_MASK)

#define USBFSH_HCCOMMANDSTATUS_SOC_MASK          (0xC0U)
#define USBFSH_HCCOMMANDSTATUS_SOC_SHIFT         (6U)
/*! SOC - SchedulingOverrunCount These bits are incremented on each scheduling overrun error. */
#define USBFSH_HCCOMMANDSTATUS_SOC(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCOMMANDSTATUS_SOC_SHIFT)) & USBFSH_HCCOMMANDSTATUS_SOC_MASK)
/*! @} */

/*! @name HCINTERRUPTSTATUS - Host controller interrupt status */
/*! @{ */

#define USBFSH_HCINTERRUPTSTATUS_SO_MASK         (0x1U)
#define USBFSH_HCINTERRUPTSTATUS_SO_SHIFT        (0U)
/*! SO - SchedulingOverrun */
#define USBFSH_HCINTERRUPTSTATUS_SO(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_SO_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_SO_MASK)

#define USBFSH_HCINTERRUPTSTATUS_WDH_MASK        (0x2U)
#define USBFSH_HCINTERRUPTSTATUS_WDH_SHIFT       (1U)
/*! WDH - WritebackDoneHead */
#define USBFSH_HCINTERRUPTSTATUS_WDH(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_WDH_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_WDH_MASK)

#define USBFSH_HCINTERRUPTSTATUS_SF_MASK         (0x4U)
#define USBFSH_HCINTERRUPTSTATUS_SF_SHIFT        (2U)
/*! SF - StartofFrame */
#define USBFSH_HCINTERRUPTSTATUS_SF(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_SF_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_SF_MASK)

#define USBFSH_HCINTERRUPTSTATUS_RD_MASK         (0x8U)
#define USBFSH_HCINTERRUPTSTATUS_RD_SHIFT        (3U)
/*! RD - ResumeDetected */
#define USBFSH_HCINTERRUPTSTATUS_RD(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_RD_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_RD_MASK)

#define USBFSH_HCINTERRUPTSTATUS_UE_MASK         (0x10U)
#define USBFSH_HCINTERRUPTSTATUS_UE_SHIFT        (4U)
/*! UE - UnrecoverableError */
#define USBFSH_HCINTERRUPTSTATUS_UE(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_UE_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_UE_MASK)

#define USBFSH_HCINTERRUPTSTATUS_FNO_MASK        (0x20U)
#define USBFSH_HCINTERRUPTSTATUS_FNO_SHIFT       (5U)
/*! FNO - FrameNumberOverflow */
#define USBFSH_HCINTERRUPTSTATUS_FNO(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_FNO_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_FNO_MASK)

#define USBFSH_HCINTERRUPTSTATUS_RHSC_MASK       (0x40U)
#define USBFSH_HCINTERRUPTSTATUS_RHSC_SHIFT      (6U)
/*! RHSC - RootHubStatusChange This bit is set when the content of HcRhStatus or the content of any
 *    of HcRhPortStatus[NumberofDownstreamPort] has changed.
 */
#define USBFSH_HCINTERRUPTSTATUS_RHSC(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_RHSC_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_RHSC_MASK)

#define USBFSH_HCINTERRUPTSTATUS_OC_MASK         (0xFFFFFC00U)
#define USBFSH_HCINTERRUPTSTATUS_OC_SHIFT        (10U)
/*! OC - OwnershipChange */
#define USBFSH_HCINTERRUPTSTATUS_OC(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTSTATUS_OC_SHIFT)) & USBFSH_HCINTERRUPTSTATUS_OC_MASK)
/*! @} */

/*! @name HCINTERRUPTENABLE - Host Controller interrupt enable */
/*! @{ */

#define USBFSH_HCINTERRUPTENABLE_SO_MASK         (0x1U)
#define USBFSH_HCINTERRUPTENABLE_SO_SHIFT        (0U)
/*! SO - Scheduling Overrun interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_SO(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_SO_SHIFT)) & USBFSH_HCINTERRUPTENABLE_SO_MASK)

#define USBFSH_HCINTERRUPTENABLE_WDH_MASK        (0x2U)
#define USBFSH_HCINTERRUPTENABLE_WDH_SHIFT       (1U)
/*! WDH - HcDoneHead Writeback interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_WDH(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_WDH_SHIFT)) & USBFSH_HCINTERRUPTENABLE_WDH_MASK)

#define USBFSH_HCINTERRUPTENABLE_SF_MASK         (0x4U)
#define USBFSH_HCINTERRUPTENABLE_SF_SHIFT        (2U)
/*! SF - Start of Frame interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_SF(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_SF_SHIFT)) & USBFSH_HCINTERRUPTENABLE_SF_MASK)

#define USBFSH_HCINTERRUPTENABLE_RD_MASK         (0x8U)
#define USBFSH_HCINTERRUPTENABLE_RD_SHIFT        (3U)
/*! RD - Resume Detect interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_RD(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_RD_SHIFT)) & USBFSH_HCINTERRUPTENABLE_RD_MASK)

#define USBFSH_HCINTERRUPTENABLE_UE_MASK         (0x10U)
#define USBFSH_HCINTERRUPTENABLE_UE_SHIFT        (4U)
/*! UE - Unrecoverable Error interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_UE(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_UE_SHIFT)) & USBFSH_HCINTERRUPTENABLE_UE_MASK)

#define USBFSH_HCINTERRUPTENABLE_FNO_MASK        (0x20U)
#define USBFSH_HCINTERRUPTENABLE_FNO_SHIFT       (5U)
/*! FNO - Frame Number Overflow interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_FNO(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_FNO_SHIFT)) & USBFSH_HCINTERRUPTENABLE_FNO_MASK)

#define USBFSH_HCINTERRUPTENABLE_RHSC_MASK       (0x40U)
#define USBFSH_HCINTERRUPTENABLE_RHSC_SHIFT      (6U)
/*! RHSC - Root Hub Status Change interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_RHSC(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_RHSC_SHIFT)) & USBFSH_HCINTERRUPTENABLE_RHSC_MASK)

#define USBFSH_HCINTERRUPTENABLE_OC_MASK         (0x40000000U)
#define USBFSH_HCINTERRUPTENABLE_OC_SHIFT        (30U)
/*! OC - Ownership Change interrupt.
 *  0b0..No effect
 *  0b1..Enables interrupt
 */
#define USBFSH_HCINTERRUPTENABLE_OC(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_OC_SHIFT)) & USBFSH_HCINTERRUPTENABLE_OC_MASK)

#define USBFSH_HCINTERRUPTENABLE_MIE_MASK        (0x80000000U)
#define USBFSH_HCINTERRUPTENABLE_MIE_SHIFT       (31U)
/*! MIE - Master Interrupt Enable. */
#define USBFSH_HCINTERRUPTENABLE_MIE(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTENABLE_MIE_SHIFT)) & USBFSH_HCINTERRUPTENABLE_MIE_MASK)
/*! @} */

/*! @name HCINTERRUPTDISABLE - The bits in this register are used to disable corresponding bits in the HCInterruptStatus register and in turn disable that event leading to hardware interrupt. */
/*! @{ */

#define USBFSH_HCINTERRUPTDISABLE_SO_MASK        (0x1U)
#define USBFSH_HCINTERRUPTDISABLE_SO_SHIFT       (0U)
/*! SO - Scheduling Overrun interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_SO(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_SO_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_SO_MASK)

#define USBFSH_HCINTERRUPTDISABLE_WDH_MASK       (0x2U)
#define USBFSH_HCINTERRUPTDISABLE_WDH_SHIFT      (1U)
/*! WDH - HcDoneHead Writeback interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_WDH(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_WDH_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_WDH_MASK)

#define USBFSH_HCINTERRUPTDISABLE_SF_MASK        (0x4U)
#define USBFSH_HCINTERRUPTDISABLE_SF_SHIFT       (2U)
/*! SF - Start of Frame interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_SF(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_SF_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_SF_MASK)

#define USBFSH_HCINTERRUPTDISABLE_RD_MASK        (0x8U)
#define USBFSH_HCINTERRUPTDISABLE_RD_SHIFT       (3U)
/*! RD - Resume Detect interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_RD(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_RD_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_RD_MASK)

#define USBFSH_HCINTERRUPTDISABLE_UE_MASK        (0x10U)
#define USBFSH_HCINTERRUPTDISABLE_UE_SHIFT       (4U)
/*! UE - Unrecoverable Error interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_UE(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_UE_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_UE_MASK)

#define USBFSH_HCINTERRUPTDISABLE_FNO_MASK       (0x20U)
#define USBFSH_HCINTERRUPTDISABLE_FNO_SHIFT      (5U)
/*! FNO - Frame Number Overflow interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_FNO(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_FNO_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_FNO_MASK)

#define USBFSH_HCINTERRUPTDISABLE_RHSC_MASK      (0x40U)
#define USBFSH_HCINTERRUPTDISABLE_RHSC_SHIFT     (6U)
/*! RHSC - Root Hub Status Change interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_RHSC(x)        (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_RHSC_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_RHSC_MASK)

#define USBFSH_HCINTERRUPTDISABLE_OC_MASK        (0x40000000U)
#define USBFSH_HCINTERRUPTDISABLE_OC_SHIFT       (30U)
/*! OC - Ownership Change interrupt.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_OC(x)          (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_OC_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_OC_MASK)

#define USBFSH_HCINTERRUPTDISABLE_MIE_MASK       (0x80000000U)
#define USBFSH_HCINTERRUPTDISABLE_MIE_SHIFT      (31U)
/*! MIE - A 0 written to this field is ignored by HC.
 *  0b0..No effect
 *  0b1..Disables interrupt
 */
#define USBFSH_HCINTERRUPTDISABLE_MIE(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCINTERRUPTDISABLE_MIE_SHIFT)) & USBFSH_HCINTERRUPTDISABLE_MIE_MASK)
/*! @} */

/*! @name HCHCCA - Host controller communication area */
/*! @{ */

#define USBFSH_HCHCCA_HCCA_MASK                  (0xFFFFFF00U)
#define USBFSH_HCHCCA_HCCA_SHIFT                 (8U)
/*! HCCA - Host Controller Communication Area */
#define USBFSH_HCHCCA_HCCA(x)                    (((uint32_t)(((uint32_t)(x)) << USBFSH_HCHCCA_HCCA_SHIFT)) & USBFSH_HCHCCA_HCCA_MASK)
/*! @} */

/*! @name HCPERIODCURRENTED - Host controller period current endpoint descriptor */
/*! @{ */

#define USBFSH_HCPERIODCURRENTED_PCED_MASK       (0xFFFFFFF0U)
#define USBFSH_HCPERIODCURRENTED_PCED_SHIFT      (4U)
/*! PCED - The content of this register is updated by HC after a periodic ED is processed. */
#define USBFSH_HCPERIODCURRENTED_PCED(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCPERIODCURRENTED_PCED_SHIFT)) & USBFSH_HCPERIODCURRENTED_PCED_MASK)
/*! @} */

/*! @name HCCONTROLHEADED - Host controller control head endpoint descriptor */
/*! @{ */

#define USBFSH_HCCONTROLHEADED_CHED_MASK         (0xFFFFFFF0U)
#define USBFSH_HCCONTROLHEADED_CHED_SHIFT        (4U)
/*! CHED - HC traverses the Control list starting with the HcControlHeadED pointer. */
#define USBFSH_HCCONTROLHEADED_CHED(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROLHEADED_CHED_SHIFT)) & USBFSH_HCCONTROLHEADED_CHED_MASK)
/*! @} */

/*! @name HCCONTROLCURRENTED - Host controller control current endpoint descriptor */
/*! @{ */

#define USBFSH_HCCONTROLCURRENTED_CCED_MASK      (0xFFFFFFF0U)
#define USBFSH_HCCONTROLCURRENTED_CCED_SHIFT     (4U)
/*! CCED - ControlCurrentED */
#define USBFSH_HCCONTROLCURRENTED_CCED(x)        (((uint32_t)(((uint32_t)(x)) << USBFSH_HCCONTROLCURRENTED_CCED_SHIFT)) & USBFSH_HCCONTROLCURRENTED_CCED_MASK)
/*! @} */

/*! @name HCBULKHEADED - Host controller bulk head endpoint descriptor */
/*! @{ */

#define USBFSH_HCBULKHEADED_BHED_MASK            (0xFFFFFFF0U)
#define USBFSH_HCBULKHEADED_BHED_SHIFT           (4U)
/*! BHED - BulkHeadED HC traverses the bulk list starting with the HcBulkHeadED pointer. */
#define USBFSH_HCBULKHEADED_BHED(x)              (((uint32_t)(((uint32_t)(x)) << USBFSH_HCBULKHEADED_BHED_SHIFT)) & USBFSH_HCBULKHEADED_BHED_MASK)
/*! @} */

/*! @name HCBULKCURRENTED - Host controller bulk current endpoint descriptor */
/*! @{ */

#define USBFSH_HCBULKCURRENTED_BCED_MASK         (0xFFFFFFF0U)
#define USBFSH_HCBULKCURRENTED_BCED_SHIFT        (4U)
/*! BCED - BulkCurrentED */
#define USBFSH_HCBULKCURRENTED_BCED(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCBULKCURRENTED_BCED_SHIFT)) & USBFSH_HCBULKCURRENTED_BCED_MASK)
/*! @} */

/*! @name HCDONEHEAD - Host controller done head */
/*! @{ */

#define USBFSH_HCDONEHEAD_DH_MASK                (0xFFFFFFF0U)
#define USBFSH_HCDONEHEAD_DH_SHIFT               (4U)
/*! DH - DoneHead When a TD is completed, HC writes the content of HcDoneHead to the NextTD field of the TD. */
#define USBFSH_HCDONEHEAD_DH(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCDONEHEAD_DH_SHIFT)) & USBFSH_HCDONEHEAD_DH_MASK)
/*! @} */

/*! @name HCFMINTERVAL - Host controller frame interval */
/*! @{ */

#define USBFSH_HCFMINTERVAL_FI_MASK              (0x3FFFU)
#define USBFSH_HCFMINTERVAL_FI_SHIFT             (0U)
/*! FI - FrameInterval This specifies the interval between two consecutive SOFs in bit times. */
#define USBFSH_HCFMINTERVAL_FI(x)                (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMINTERVAL_FI_SHIFT)) & USBFSH_HCFMINTERVAL_FI_MASK)

#define USBFSH_HCFMINTERVAL_FSMPS_MASK           (0x7FFF0000U)
#define USBFSH_HCFMINTERVAL_FSMPS_SHIFT          (16U)
/*! FSMPS - FSLargestDataPacket This field specifies a value which is loaded into the Largest Data
 *    Packet Counter at the beginning of each frame.
 */
#define USBFSH_HCFMINTERVAL_FSMPS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMINTERVAL_FSMPS_SHIFT)) & USBFSH_HCFMINTERVAL_FSMPS_MASK)

#define USBFSH_HCFMINTERVAL_FIT_MASK             (0x80000000U)
#define USBFSH_HCFMINTERVAL_FIT_SHIFT            (31U)
/*! FIT - FrameIntervalToggle */
#define USBFSH_HCFMINTERVAL_FIT(x)               (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMINTERVAL_FIT_SHIFT)) & USBFSH_HCFMINTERVAL_FIT_MASK)
/*! @} */

/*! @name HCFMREMAINING - Host controller frame remaining */
/*! @{ */

#define USBFSH_HCFMREMAINING_FR_MASK             (0x3FFFU)
#define USBFSH_HCFMREMAINING_FR_SHIFT            (0U)
/*! FR - FrameRemaining */
#define USBFSH_HCFMREMAINING_FR(x)               (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMREMAINING_FR_SHIFT)) & USBFSH_HCFMREMAINING_FR_MASK)

#define USBFSH_HCFMREMAINING_FRT_MASK            (0x80000000U)
#define USBFSH_HCFMREMAINING_FRT_SHIFT           (31U)
/*! FRT - FrameRemainingToggle */
#define USBFSH_HCFMREMAINING_FRT(x)              (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMREMAINING_FRT_SHIFT)) & USBFSH_HCFMREMAINING_FRT_MASK)
/*! @} */

/*! @name HCFMNUMBER - Host controller frame number */
/*! @{ */

#define USBFSH_HCFMNUMBER_FN_MASK                (0xFFFFU)
#define USBFSH_HCFMNUMBER_FN_SHIFT               (0U)
/*! FN - FrameNumber */
#define USBFSH_HCFMNUMBER_FN(x)                  (((uint32_t)(((uint32_t)(x)) << USBFSH_HCFMNUMBER_FN_SHIFT)) & USBFSH_HCFMNUMBER_FN_MASK)
/*! @} */

/*! @name HCPERIODICSTART - Host controller periodic start */
/*! @{ */

#define USBFSH_HCPERIODICSTART_PS_MASK           (0x3FFFU)
#define USBFSH_HCPERIODICSTART_PS_SHIFT          (0U)
/*! PS - PeriodicStart */
#define USBFSH_HCPERIODICSTART_PS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCPERIODICSTART_PS_SHIFT)) & USBFSH_HCPERIODICSTART_PS_MASK)
/*! @} */

/*! @name HCLSTHRESHOLD - Host controller low speed threshold */
/*! @{ */

#define USBFSH_HCLSTHRESHOLD_LST_MASK            (0xFFFU)
#define USBFSH_HCLSTHRESHOLD_LST_SHIFT           (0U)
/*! LST - LSThreshold */
#define USBFSH_HCLSTHRESHOLD_LST(x)              (((uint32_t)(((uint32_t)(x)) << USBFSH_HCLSTHRESHOLD_LST_SHIFT)) & USBFSH_HCLSTHRESHOLD_LST_MASK)
/*! @} */

/*! @name HCRHDESCRIPTORA - Host controller root hub descriptor A */
/*! @{ */

#define USBFSH_HCRHDESCRIPTORA_NDP_MASK          (0xFFU)
#define USBFSH_HCRHDESCRIPTORA_NDP_SHIFT         (0U)
/*! NDP - NumberDownstreamPorts */
#define USBFSH_HCRHDESCRIPTORA_NDP(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_NDP_SHIFT)) & USBFSH_HCRHDESCRIPTORA_NDP_MASK)

#define USBFSH_HCRHDESCRIPTORA_PSM_MASK          (0x100U)
#define USBFSH_HCRHDESCRIPTORA_PSM_SHIFT         (8U)
/*! PSM - PowerSwitchingMode
 *  0b0..All ports are powered at the same time
 *  0b1..Each port is powered individually.
 */
#define USBFSH_HCRHDESCRIPTORA_PSM(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_PSM_SHIFT)) & USBFSH_HCRHDESCRIPTORA_PSM_MASK)

#define USBFSH_HCRHDESCRIPTORA_NPS_MASK          (0x200U)
#define USBFSH_HCRHDESCRIPTORA_NPS_SHIFT         (9U)
/*! NPS - NoPowerSwitching
 *  0b0..Ports are power switched
 *  0b1..Ports are always powered on when the host controller is powered on
 */
#define USBFSH_HCRHDESCRIPTORA_NPS(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_NPS_SHIFT)) & USBFSH_HCRHDESCRIPTORA_NPS_MASK)

#define USBFSH_HCRHDESCRIPTORA_DT_MASK           (0x400U)
#define USBFSH_HCRHDESCRIPTORA_DT_SHIFT          (10U)
/*! DT - DeviceType */
#define USBFSH_HCRHDESCRIPTORA_DT(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_DT_SHIFT)) & USBFSH_HCRHDESCRIPTORA_DT_MASK)

#define USBFSH_HCRHDESCRIPTORA_OCPM_MASK         (0x800U)
#define USBFSH_HCRHDESCRIPTORA_OCPM_SHIFT        (11U)
/*! OCPM - OverCurrentProtectionMode This bit describes how the overcurrent status for the root hub ports are reported.
 *  0b0..Over-current status is reported collectively for all downstream ports
 *  0b1..Over-current status is reported on a per-port basis
 */
#define USBFSH_HCRHDESCRIPTORA_OCPM(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_OCPM_SHIFT)) & USBFSH_HCRHDESCRIPTORA_OCPM_MASK)

#define USBFSH_HCRHDESCRIPTORA_NOCP_MASK         (0x1000U)
#define USBFSH_HCRHDESCRIPTORA_NOCP_SHIFT        (12U)
/*! NOCP - NoOverCurrentProtection This bit describes how the overcurrent status for the root hub ports are reported.
 *  0b0..Over-current status is reported collectively for all downstream ports
 *  0b1..No overcurrent protection supported
 */
#define USBFSH_HCRHDESCRIPTORA_NOCP(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_NOCP_SHIFT)) & USBFSH_HCRHDESCRIPTORA_NOCP_MASK)

#define USBFSH_HCRHDESCRIPTORA_POTPGT_MASK       (0xFF000000U)
#define USBFSH_HCRHDESCRIPTORA_POTPGT_SHIFT      (24U)
/*! POTPGT - PowerOnToPowerGoodTime */
#define USBFSH_HCRHDESCRIPTORA_POTPGT(x)         (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORA_POTPGT_SHIFT)) & USBFSH_HCRHDESCRIPTORA_POTPGT_MASK)
/*! @} */

/*! @name HCRHDESCRIPTORB - Host controller root hub descriptor B */
/*! @{ */

#define USBFSH_HCRHDESCRIPTORB_DR_MASK           (0xFFFFU)
#define USBFSH_HCRHDESCRIPTORB_DR_SHIFT          (0U)
/*! DR - DeviceRemovable */
#define USBFSH_HCRHDESCRIPTORB_DR(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORB_DR_SHIFT)) & USBFSH_HCRHDESCRIPTORB_DR_MASK)

#define USBFSH_HCRHDESCRIPTORB_PPCM_MASK         (0xFFFF0000U)
#define USBFSH_HCRHDESCRIPTORB_PPCM_SHIFT        (16U)
/*! PPCM - PortPowerControlMask */
#define USBFSH_HCRHDESCRIPTORB_PPCM(x)           (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHDESCRIPTORB_PPCM_SHIFT)) & USBFSH_HCRHDESCRIPTORB_PPCM_MASK)
/*! @} */

/*! @name HCRHSTATUS -  */
/*! @{ */

#define USBFSH_HCRHSTATUS_LPS_MASK               (0x1U)
#define USBFSH_HCRHSTATUS_LPS_SHIFT              (0U)
/*! LPS - (read) LocalPowerStatus (write) ClearGlobalPower */
#define USBFSH_HCRHSTATUS_LPS(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_LPS_SHIFT)) & USBFSH_HCRHSTATUS_LPS_MASK)

#define USBFSH_HCRHSTATUS_OCI_MASK               (0x2U)
#define USBFSH_HCRHSTATUS_OCI_SHIFT              (1U)
/*! OCI - OverCurrentIndicator */
#define USBFSH_HCRHSTATUS_OCI(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_OCI_SHIFT)) & USBFSH_HCRHSTATUS_OCI_MASK)

#define USBFSH_HCRHSTATUS_DRWE_MASK              (0x8000U)
#define USBFSH_HCRHSTATUS_DRWE_SHIFT             (15U)
/*! DRWE - (read) DeviceRemoteWakeupEnable (Write) SetRemoteWakeupEnable
 *  0b0..ConnectStatusChange is not a remote wakeup event
 *  0b1..ConnectStatusChange is a remote wakeup event
 */
#define USBFSH_HCRHSTATUS_DRWE(x)                (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_DRWE_SHIFT)) & USBFSH_HCRHSTATUS_DRWE_MASK)

#define USBFSH_HCRHSTATUS_LPSC_MASK              (0x10000U)
#define USBFSH_HCRHSTATUS_LPSC_SHIFT             (16U)
/*! LPSC - (read) LocalPowerStatusChange(Write) SetGlobalPower . */
#define USBFSH_HCRHSTATUS_LPSC(x)                (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_LPSC_SHIFT)) & USBFSH_HCRHSTATUS_LPSC_MASK)

#define USBFSH_HCRHSTATUS_OCIC_MASK              (0x20000U)
#define USBFSH_HCRHSTATUS_OCIC_SHIFT             (17U)
/*! OCIC - OverCurrentIndicatorChange */
#define USBFSH_HCRHSTATUS_OCIC(x)                (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_OCIC_SHIFT)) & USBFSH_HCRHSTATUS_OCIC_MASK)

#define USBFSH_HCRHSTATUS_CRWE_MASK              (0x80000000U)
#define USBFSH_HCRHSTATUS_CRWE_SHIFT             (31U)
/*! CRWE - (write) ClearRemoteWakeupEnable . */
#define USBFSH_HCRHSTATUS_CRWE(x)                (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHSTATUS_CRWE_SHIFT)) & USBFSH_HCRHSTATUS_CRWE_MASK)
/*! @} */

/*! @name HCRHPORTSTATUS - Host controller root hub port status */
/*! @{ */

#define USBFSH_HCRHPORTSTATUS_CCS_MASK           (0x1U)
#define USBFSH_HCRHPORTSTATUS_CCS_SHIFT          (0U)
/*! CCS - CurrentConnectStatus
 *  0b0..Device is not connected
 *  0b1..Device is connected
 */
#define USBFSH_HCRHPORTSTATUS_CCS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_CCS_SHIFT)) & USBFSH_HCRHPORTSTATUS_CCS_MASK)

#define USBFSH_HCRHPORTSTATUS_PES_MASK           (0x2U)
#define USBFSH_HCRHPORTSTATUS_PES_SHIFT          (1U)
/*! PES - (Read)PortEnableStatus
 *  0b0..Port is disabled
 *  0b1..Port is enabled
 */
#define USBFSH_HCRHPORTSTATUS_PES(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PES_SHIFT)) & USBFSH_HCRHPORTSTATUS_PES_MASK)

#define USBFSH_HCRHPORTSTATUS_PSS_MASK           (0x4U)
#define USBFSH_HCRHPORTSTATUS_PSS_SHIFT          (2U)
/*! PSS - (Read) PortSuspendStatus
 *  0b0..Port is not suspended
 *  0b1..Port is suspended
 */
#define USBFSH_HCRHPORTSTATUS_PSS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PSS_SHIFT)) & USBFSH_HCRHPORTSTATUS_PSS_MASK)

#define USBFSH_HCRHPORTSTATUS_POCI_MASK          (0x8U)
#define USBFSH_HCRHPORTSTATUS_POCI_SHIFT         (3U)
/*! POCI - (read) PortOverCurrentIndicator
 *  0b0..Overcurrent condition is not detected
 *  0b1..Overcurrent condition is detected
 */
#define USBFSH_HCRHPORTSTATUS_POCI(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_POCI_SHIFT)) & USBFSH_HCRHPORTSTATUS_POCI_MASK)

#define USBFSH_HCRHPORTSTATUS_PRS_MASK           (0x10U)
#define USBFSH_HCRHPORTSTATUS_PRS_SHIFT          (4U)
/*! PRS - (read) PortResetStatus When this bit is set by a write to SetPortReset, port reset signaling is asserted.
 *  0b0..Port reset signal is not active
 *  0b1..Port reset signal is active
 */
#define USBFSH_HCRHPORTSTATUS_PRS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PRS_SHIFT)) & USBFSH_HCRHPORTSTATUS_PRS_MASK)

#define USBFSH_HCRHPORTSTATUS_PPS_MASK           (0x100U)
#define USBFSH_HCRHPORTSTATUS_PPS_SHIFT          (8U)
/*! PPS - (read) PortPowerStatus
 *  0b0..Port power is off
 *  0b1..Port power is on
 */
#define USBFSH_HCRHPORTSTATUS_PPS(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PPS_SHIFT)) & USBFSH_HCRHPORTSTATUS_PPS_MASK)

#define USBFSH_HCRHPORTSTATUS_LSDA_MASK          (0x200U)
#define USBFSH_HCRHPORTSTATUS_LSDA_SHIFT         (9U)
/*! LSDA - (read) LowSpeedDeviceAttached
 *  0b0..Full speed device is attached
 *  0b1..Low speed device is attached
 */
#define USBFSH_HCRHPORTSTATUS_LSDA(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_LSDA_SHIFT)) & USBFSH_HCRHPORTSTATUS_LSDA_MASK)

#define USBFSH_HCRHPORTSTATUS_CSC_MASK           (0x10000U)
#define USBFSH_HCRHPORTSTATUS_CSC_SHIFT          (16U)
/*! CSC - ConnectStatusChange
 *  0b0..CurrentConnectStatus has not changed
 *  0b1..CurrentConnectStatus has changed
 */
#define USBFSH_HCRHPORTSTATUS_CSC(x)             (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_CSC_SHIFT)) & USBFSH_HCRHPORTSTATUS_CSC_MASK)

#define USBFSH_HCRHPORTSTATUS_PESC_MASK          (0x20000U)
#define USBFSH_HCRHPORTSTATUS_PESC_SHIFT         (17U)
/*! PESC - PortEnableStatusChange
 *  0b0..PortEnableStatus has not changed
 *  0b1..PortEnableStatus has changed
 */
#define USBFSH_HCRHPORTSTATUS_PESC(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PESC_SHIFT)) & USBFSH_HCRHPORTSTATUS_PESC_MASK)

#define USBFSH_HCRHPORTSTATUS_PSSC_MASK          (0x40000U)
#define USBFSH_HCRHPORTSTATUS_PSSC_SHIFT         (18U)
/*! PSSC - PortSuspendStatusChange
 *  0b0..Resume sequence is not complete
 *  0b1..Resume sequence is complete
 */
#define USBFSH_HCRHPORTSTATUS_PSSC(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PSSC_SHIFT)) & USBFSH_HCRHPORTSTATUS_PSSC_MASK)

#define USBFSH_HCRHPORTSTATUS_OCIC_MASK          (0x80000U)
#define USBFSH_HCRHPORTSTATUS_OCIC_SHIFT         (19U)
/*! OCIC - PortOverCurrentIndicatorChange
 *  0b0..PortOverCurrentIndicator has not changed
 *  0b1..PortOverCurrentIndicator has changed
 */
#define USBFSH_HCRHPORTSTATUS_OCIC(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_OCIC_SHIFT)) & USBFSH_HCRHPORTSTATUS_OCIC_MASK)

#define USBFSH_HCRHPORTSTATUS_PRSC_MASK          (0x100000U)
#define USBFSH_HCRHPORTSTATUS_PRSC_SHIFT         (20U)
/*! PRSC - PortResetStatusChange
 *  0b0..Port reset is not complete
 *  0b1..Port reset is complete
 */
#define USBFSH_HCRHPORTSTATUS_PRSC(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_HCRHPORTSTATUS_PRSC_SHIFT)) & USBFSH_HCRHPORTSTATUS_PRSC_MASK)
/*! @} */

/*! @name PORTMODE - Port Mode */
/*! @{ */

#define USBFSH_PORTMODE_ID_MASK                  (0x1U)
#define USBFSH_PORTMODE_ID_SHIFT                 (0U)
/*! ID - Port ID pin value. */
#define USBFSH_PORTMODE_ID(x)                    (((uint32_t)(((uint32_t)(x)) << USBFSH_PORTMODE_ID_SHIFT)) & USBFSH_PORTMODE_ID_MASK)

#define USBFSH_PORTMODE_ID_EN_MASK               (0x100U)
#define USBFSH_PORTMODE_ID_EN_SHIFT              (8U)
/*! ID_EN - Port ID pin pull-up enable. */
#define USBFSH_PORTMODE_ID_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USBFSH_PORTMODE_ID_EN_SHIFT)) & USBFSH_PORTMODE_ID_EN_MASK)

#define USBFSH_PORTMODE_DEV_ENABLE_MASK          (0x10000U)
#define USBFSH_PORTMODE_DEV_ENABLE_SHIFT         (16U)
/*! DEV_ENABLE - Device Enable
 *  0b0..Device
 *  0b1..Host
 */
#define USBFSH_PORTMODE_DEV_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << USBFSH_PORTMODE_DEV_ENABLE_SHIFT)) & USBFSH_PORTMODE_DEV_ENABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBFSH_Register_Masks */


/*!
 * @}
 */ /* end of group USBFSH_Peripheral_Access_Layer */


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


#endif  /* PERI_USBFSH_H_ */

