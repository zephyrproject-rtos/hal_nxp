/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBHSH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBHSH.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBHSH
 *
 * CMSIS Peripheral Access Layer for USBHSH
 */

#if !defined(PERI_USBHSH_H_)
#define PERI_USBHSH_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- USBHSH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSH_Peripheral_Access_Layer USBHSH Peripheral Access Layer
 * @{
 */

/** USBHSH - Register Layout Typedef */
typedef struct {
  __I  uint32_t CAPLENGTH_CHIPID;                  /**< Version ID Register, offset: 0x0 */
  __I  uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x4 */
  __IO uint32_t HCCPARAMS;                         /**< INT PTD Base Address, offset: 0x8 */
  __IO uint32_t FLADJ_FRINDEX;                     /**< Frame Length Adjustment, offset: 0xC */
  __IO uint32_t ATL_PTD_BASE_ADDR;                 /**< ATL PTD Base Address, offset: 0x10 */
  __IO uint32_t ISO_PTD_BASE_ADDR;                 /**< ISO PTD Base Address, offset: 0x14 */
  __IO uint32_t INT_PTD_BASE_ADDR;                 /**< INT PTD Base Address, offset: 0x18 */
  __IO uint32_t DATA_PAYLOAD_BASE_ADDR;            /**< DATA PAYLOAD Base Address, offset: 0x1C */
  __IO uint32_t USBCMD;                            /**< USB Command, offset: 0x20 */
  __IO uint32_t USBSTS;                            /**< USB Interrupt Status, offset: 0x24 */
  __IO uint32_t USBINTR;                           /**< USB Interrupt Status, offset: 0x28 */
  __IO uint32_t PORTSC1;                           /**< Port Status and Control, offset: 0x2C */
  __IO uint32_t ATL_PTD_DONE_MAP;                  /**< ATL PTD Done Map, offset: 0x30 */
  __IO uint32_t ATL_PTD_SKIP_MAP;                  /**< ATL PTD Skip Map, offset: 0x34 */
  __IO uint32_t ISO_PTD_DONE_MAP;                  /**< ISO PTD Done Map, offset: 0x38 */
  __IO uint32_t ISO_PTD_SKIP_MAP;                  /**< ISO PTD Skip Map, offset: 0x3C */
  __IO uint32_t INT_PTD_DONE_MAP;                  /**< INT PTD Done Map, offset: 0x40 */
  __IO uint32_t INT_PTD_SKIP_MAP;                  /**< INT PTD Skip Map, offset: 0x44 */
  __IO uint32_t LAST_PTD_INUSE;                    /**< Last PTD in use, offset: 0x48 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PORTMODE;                          /**< Port Mode, offset: 0x50 */
} USBHSH_Type;

/* ----------------------------------------------------------------------------
   -- USBHSH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSH_Register_Masks USBHSH Register Masks
 * @{
 */

/*! @name CAPLENGTH_CHIPID - Version ID Register */
/*! @{ */

#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_MASK   (0xFFU)
#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_SHIFT  (0U)
/*! CAPLENGTH - Capability Length. */
#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_SHIFT)) & USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_MASK)

#define USBHSH_CAPLENGTH_CHIPID_CHIPID_MASK      (0xFFFF0000U)
#define USBHSH_CAPLENGTH_CHIPID_CHIPID_SHIFT     (16U)
/*! CHIPID - Chip identification. */
#define USBHSH_CAPLENGTH_CHIPID_CHIPID(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_CAPLENGTH_CHIPID_CHIPID_SHIFT)) & USBHSH_CAPLENGTH_CHIPID_CHIPID_MASK)
/*! @} */

/*! @name HCSPARAMS - Host Controller Structural Parameters */
/*! @{ */

#define USBHSH_HCSPARAMS_N_PORTS_MASK            (0xFU)
#define USBHSH_HCSPARAMS_N_PORTS_SHIFT           (0U)
/*! N_PORTS - Number of Physical downstream ports. */
#define USBHSH_HCSPARAMS_N_PORTS(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_N_PORTS_SHIFT)) & USBHSH_HCSPARAMS_N_PORTS_MASK)

#define USBHSH_HCSPARAMS_PPC_MASK                (0x10U)
#define USBHSH_HCSPARAMS_PPC_SHIFT               (4U)
/*! PPC - Port Power Control */
#define USBHSH_HCSPARAMS_PPC(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_PPC_SHIFT)) & USBHSH_HCSPARAMS_PPC_MASK)

#define USBHSH_HCSPARAMS_P_INDICATOR_MASK        (0x10000U)
#define USBHSH_HCSPARAMS_P_INDICATOR_SHIFT       (16U)
/*! P_INDICATOR - Port Indicator Control */
#define USBHSH_HCSPARAMS_P_INDICATOR(x)          (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_P_INDICATOR_SHIFT)) & USBHSH_HCSPARAMS_P_INDICATOR_MASK)
/*! @} */

/*! @name HCCPARAMS - INT PTD Base Address */
/*! @{ */

#define USBHSH_HCCPARAMS_LPMC_MASK               (0x20000U)
#define USBHSH_HCCPARAMS_LPMC_SHIFT              (17U)
/*! LPMC - Link Power Management Capability */
#define USBHSH_HCCPARAMS_LPMC(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_HCCPARAMS_LPMC_SHIFT)) & USBHSH_HCCPARAMS_LPMC_MASK)
/*! @} */

/*! @name FLADJ_FRINDEX - Frame Length Adjustment */
/*! @{ */

#define USBHSH_FLADJ_FRINDEX_FLADJ_MASK          (0x3FU)
#define USBHSH_FLADJ_FRINDEX_FLADJ_SHIFT         (0U)
/*! FLADJ - Frame Length Timing Value. */
#define USBHSH_FLADJ_FRINDEX_FLADJ(x)            (((uint32_t)(((uint32_t)(x)) << USBHSH_FLADJ_FRINDEX_FLADJ_SHIFT)) & USBHSH_FLADJ_FRINDEX_FLADJ_MASK)

#define USBHSH_FLADJ_FRINDEX_FRINDEX_MASK        (0x3FFF0000U)
#define USBHSH_FLADJ_FRINDEX_FRINDEX_SHIFT       (16U)
/*! FRINDEX - Frame Index */
#define USBHSH_FLADJ_FRINDEX_FRINDEX(x)          (((uint32_t)(((uint32_t)(x)) << USBHSH_FLADJ_FRINDEX_FRINDEX_SHIFT)) & USBHSH_FLADJ_FRINDEX_FRINDEX_MASK)
/*! @} */

/*! @name ATL_PTD_BASE_ADDR - ATL PTD Base Address */
/*! @{ */

#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_MASK    (0x1F0U)
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_SHIFT   (4U)
/*! ATL_CUR - Current PTD */
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_SHIFT)) & USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_MASK)

#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_MASK   (0xFFFFFE00U)
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_SHIFT  (9U)
/*! ATL_BASE - Start of ATL list. */
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_SHIFT)) & USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_MASK)
/*! @} */

/*! @name ISO_PTD_BASE_ADDR - ISO PTD Base Address */
/*! @{ */

#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_MASK  (0x3E0U)
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_SHIFT (5U)
/*! ISO_FIRST - First PTD in the ISO list */
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST(x)    (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_SHIFT)) & USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_MASK)

#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_MASK   (0xFFFFFC00U)
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_SHIFT  (10U)
/*! ISO_BASE - Start of ISO PTD list */
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_SHIFT)) & USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_MASK)
/*! @} */

/*! @name INT_PTD_BASE_ADDR - INT PTD Base Address */
/*! @{ */

#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_MASK  (0x3E0U)
#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_SHIFT (5U)
/*! INT_FIRST - First PTD in the INT list */
#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST(x)    (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_SHIFT)) & USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_MASK)

#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE_MASK   (0xFFFFFC00U)
#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE_SHIFT  (10U)
/*! INT_BASE - Start of INT PTD list */
#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_BASE_ADDR_INT_BASE_SHIFT)) & USBHSH_INT_PTD_BASE_ADDR_INT_BASE_MASK)
/*! @} */

/*! @name DATA_PAYLOAD_BASE_ADDR - DATA PAYLOAD Base Address */
/*! @{ */

#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_MASK (0xFFFF0000U)
#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_SHIFT (16U)
/*! DAT_BASE - Data Payload Section Base Address */
#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE(x) (((uint32_t)(((uint32_t)(x)) << USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_SHIFT)) & USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_MASK)
/*! @} */

/*! @name USBCMD - USB Command */
/*! @{ */

#define USBHSH_USBCMD_RS_MASK                    (0x1U)
#define USBHSH_USBCMD_RS_SHIFT                   (0U)
/*! RS - Run/Stop
 *  0b0..Stop
 *  0b1..Run
 */
#define USBHSH_USBCMD_RS(x)                      (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_RS_SHIFT)) & USBHSH_USBCMD_RS_MASK)

#define USBHSH_USBCMD_HCRESET_MASK               (0x2U)
#define USBHSH_USBCMD_HCRESET_SHIFT              (1U)
/*! HCRESET - Host Controller Reset */
#define USBHSH_USBCMD_HCRESET(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_HCRESET_SHIFT)) & USBHSH_USBCMD_HCRESET_MASK)

#define USBHSH_USBCMD_FLS_MASK                   (0xCU)
#define USBHSH_USBCMD_FLS_SHIFT                  (2U)
/*! FLS - Frame List Size
 *  0b00..1024 elements
 *  0b01..512 elements
 *  0b10..256 elements
 *  0b11..
 */
#define USBHSH_USBCMD_FLS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_FLS_SHIFT)) & USBHSH_USBCMD_FLS_MASK)

#define USBHSH_USBCMD_LHCR_MASK                  (0x80U)
#define USBHSH_USBCMD_LHCR_SHIFT                 (7U)
/*! LHCR - Light Host Controller Reset */
#define USBHSH_USBCMD_LHCR(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_LHCR_SHIFT)) & USBHSH_USBCMD_LHCR_MASK)

#define USBHSH_USBCMD_ATL_EN_MASK                (0x100U)
#define USBHSH_USBCMD_ATL_EN_SHIFT               (8U)
/*! ATL_EN - ATL List enabled */
#define USBHSH_USBCMD_ATL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_ATL_EN_SHIFT)) & USBHSH_USBCMD_ATL_EN_MASK)

#define USBHSH_USBCMD_ISO_EN_MASK                (0x200U)
#define USBHSH_USBCMD_ISO_EN_SHIFT               (9U)
/*! ISO_EN - ISO List enabled */
#define USBHSH_USBCMD_ISO_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_ISO_EN_SHIFT)) & USBHSH_USBCMD_ISO_EN_MASK)

#define USBHSH_USBCMD_INT_EN_MASK                (0x400U)
#define USBHSH_USBCMD_INT_EN_SHIFT               (10U)
/*! INT_EN - INT List enabled */
#define USBHSH_USBCMD_INT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_INT_EN_SHIFT)) & USBHSH_USBCMD_INT_EN_MASK)

#define USBHSH_USBCMD_HIRD_MASK                  (0xF000000U)
#define USBHSH_USBCMD_HIRD_SHIFT                 (24U)
/*! HIRD - Host-Initiated Resume Duration */
#define USBHSH_USBCMD_HIRD(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_HIRD_SHIFT)) & USBHSH_USBCMD_HIRD_MASK)

#define USBHSH_USBCMD_LPM_RWU_MASK               (0x10000000U)
#define USBHSH_USBCMD_LPM_RWU_SHIFT              (28U)
/*! LPM_RWU - Remote wake up. */
#define USBHSH_USBCMD_LPM_RWU(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_LPM_RWU_SHIFT)) & USBHSH_USBCMD_LPM_RWU_MASK)
/*! @} */

/*! @name USBSTS - USB Interrupt Status */
/*! @{ */

#define USBHSH_USBSTS_PCD_MASK                   (0x4U)
#define USBHSH_USBSTS_PCD_SHIFT                  (2U)
/*! PCD - Port Change Detect Interrupt Request
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBSTS_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_PCD_SHIFT)) & USBHSH_USBSTS_PCD_MASK)

#define USBHSH_USBSTS_FLR_MASK                   (0x8U)
#define USBHSH_USBSTS_FLR_SHIFT                  (3U)
/*! FLR - Frame List Rollover Interrupt Request */
#define USBHSH_USBSTS_FLR(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_FLR_SHIFT)) & USBHSH_USBSTS_FLR_MASK)

#define USBHSH_USBSTS_ATL_IRQ_MASK               (0x10000U)
#define USBHSH_USBSTS_ATL_IRQ_SHIFT              (16U)
/*! ATL_IRQ - ATL Interrupt Request Interrupt Request
 *  0b0..No ATL PTD event occurred.
 *  0b1..ATL PTD event occurred.
 */
#define USBHSH_USBSTS_ATL_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_ATL_IRQ_SHIFT)) & USBHSH_USBSTS_ATL_IRQ_MASK)

#define USBHSH_USBSTS_ISO_IRQ_MASK               (0x20000U)
#define USBHSH_USBSTS_ISO_IRQ_SHIFT              (17U)
/*! ISO_IRQ - ISO Interrupt Request
 *  0b0..No ISO PTD event occurred.
 *  0b1..ISO PTD event occurred.
 */
#define USBHSH_USBSTS_ISO_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_ISO_IRQ_SHIFT)) & USBHSH_USBSTS_ISO_IRQ_MASK)

#define USBHSH_USBSTS_INT_IRQ_MASK               (0x40000U)
#define USBHSH_USBSTS_INT_IRQ_SHIFT              (18U)
/*! INT_IRQ - INT Interrupt Request
 *  0b0..No INT PTD event occurred.
 *  0b1..INT PTD event occurred.
 */
#define USBHSH_USBSTS_INT_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_INT_IRQ_SHIFT)) & USBHSH_USBSTS_INT_IRQ_MASK)

#define USBHSH_USBSTS_SOF_IRQ_MASK               (0x80000U)
#define USBHSH_USBSTS_SOF_IRQ_SHIFT              (19U)
/*! SOF_IRQ - SOF Interrupt Request */
#define USBHSH_USBSTS_SOF_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_SOF_IRQ_SHIFT)) & USBHSH_USBSTS_SOF_IRQ_MASK)
/*! @} */

/*! @name USBINTR - USB Interrupt Status */
/*! @{ */

#define USBHSH_USBINTR_PCDE_MASK                 (0x4U)
#define USBHSH_USBINTR_PCDE_SHIFT                (2U)
/*! PCDE - Port Change Detect Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBINTR_PCDE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_PCDE_SHIFT)) & USBHSH_USBINTR_PCDE_MASK)

#define USBHSH_USBINTR_FLRE_MASK                 (0x8U)
#define USBHSH_USBINTR_FLRE_SHIFT                (3U)
/*! FLRE - Frame List Rollover Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBINTR_FLRE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_FLRE_SHIFT)) & USBHSH_USBINTR_FLRE_MASK)

#define USBHSH_USBINTR_ATL_IRQ_E_MASK            (0x10000U)
#define USBHSH_USBINTR_ATL_IRQ_E_SHIFT           (16U)
/*! ATL_IRQ_E - ATL Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBINTR_ATL_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_ATL_IRQ_E_SHIFT)) & USBHSH_USBINTR_ATL_IRQ_E_MASK)

#define USBHSH_USBINTR_ISO_IRQ_E_MASK            (0x20000U)
#define USBHSH_USBINTR_ISO_IRQ_E_SHIFT           (17U)
/*! ISO_IRQ_E - ISO Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBINTR_ISO_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_ISO_IRQ_E_SHIFT)) & USBHSH_USBINTR_ISO_IRQ_E_MASK)

#define USBHSH_USBINTR_INT_IRQ_E_MASK            (0x40000U)
#define USBHSH_USBINTR_INT_IRQ_E_SHIFT           (18U)
/*! INT_IRQ_E - INT Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBHSH_USBINTR_INT_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_INT_IRQ_E_SHIFT)) & USBHSH_USBINTR_INT_IRQ_E_MASK)

#define USBHSH_USBINTR_SOF_E_MASK                (0x80000U)
#define USBHSH_USBINTR_SOF_E_SHIFT               (19U)
/*! SOF_E - SOF Interrupt Request */
#define USBHSH_USBINTR_SOF_E(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_SOF_E_SHIFT)) & USBHSH_USBINTR_SOF_E_MASK)
/*! @} */

/*! @name PORTSC1 - Port Status and Control */
/*! @{ */

#define USBHSH_PORTSC1_CCS_MASK                  (0x1U)
#define USBHSH_PORTSC1_CCS_SHIFT                 (0U)
/*! CCS - Current Connect Status
 *  0b0..No Device is present
 *  0b1..Device is present
 */
#define USBHSH_PORTSC1_CCS(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_CCS_SHIFT)) & USBHSH_PORTSC1_CCS_MASK)

#define USBHSH_PORTSC1_CSC_MASK                  (0x2U)
#define USBHSH_PORTSC1_CSC_SHIFT                 (1U)
/*! CSC - Connect Status Change
 *  0b0..CCS value has not changed
 *  0b1..CCS value has changed
 */
#define USBHSH_PORTSC1_CSC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_CSC_SHIFT)) & USBHSH_PORTSC1_CSC_MASK)

#define USBHSH_PORTSC1_PED_MASK                  (0x4U)
#define USBHSH_PORTSC1_PED_SHIFT                 (2U)
/*! PED - Port Enabled/Disabled
 *  0b0..Port Disabled
 *  0b1..Port Enabled
 */
#define USBHSH_PORTSC1_PED(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PED_SHIFT)) & USBHSH_PORTSC1_PED_MASK)

#define USBHSH_PORTSC1_PEDC_MASK                 (0x8U)
#define USBHSH_PORTSC1_PEDC_SHIFT                (3U)
/*! PEDC - Port Enabled/Disabled Change
 *  0b0..PED value has not changed
 *  0b1..PED value has changed
 */
#define USBHSH_PORTSC1_PEDC(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PEDC_SHIFT)) & USBHSH_PORTSC1_PEDC_MASK)

#define USBHSH_PORTSC1_OCA_MASK                  (0x10U)
#define USBHSH_PORTSC1_OCA_SHIFT                 (4U)
/*! OCA - Over-current active
 *  0b0..Port does not have an over-current condition
 *  0b1..Port has an over-current condition
 */
#define USBHSH_PORTSC1_OCA(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_OCA_SHIFT)) & USBHSH_PORTSC1_OCA_MASK)

#define USBHSH_PORTSC1_OCC_MASK                  (0x20U)
#define USBHSH_PORTSC1_OCC_SHIFT                 (5U)
/*! OCC - Over-current active
 *  0b0..OCA value has not changed
 *  0b1..OCA value has changed
 */
#define USBHSH_PORTSC1_OCC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_OCC_SHIFT)) & USBHSH_PORTSC1_OCC_MASK)

#define USBHSH_PORTSC1_FPR_MASK                  (0x40U)
#define USBHSH_PORTSC1_FPR_SHIFT                 (6U)
/*! FPR - Force Port Resume
 *  0b0..No Resume (K-state) detected or driven on the port.
 *  0b1..Resume (K-state) detected or driven on the port.
 */
#define USBHSH_PORTSC1_FPR(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_FPR_SHIFT)) & USBHSH_PORTSC1_FPR_MASK)

#define USBHSH_PORTSC1_SUSP_MASK                 (0x80U)
#define USBHSH_PORTSC1_SUSP_SHIFT                (7U)
/*! SUSP - Suspend
 *  0b0..Enabled port is not suspended
 *  0b1..Enabled port is in the L1 or L2 suspend state
 */
#define USBHSH_PORTSC1_SUSP(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUSP_SHIFT)) & USBHSH_PORTSC1_SUSP_MASK)

#define USBHSH_PORTSC1_PR_MASK                   (0x100U)
#define USBHSH_PORTSC1_PR_SHIFT                  (8U)
/*! PR - Port Reset
 *  0b0..Port is not in the reset state
 *  0b1..Port is in the reset state
 */
#define USBHSH_PORTSC1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PR_SHIFT)) & USBHSH_PORTSC1_PR_MASK)

#define USBHSH_PORTSC1_SUS_L1_MASK               (0x200U)
#define USBHSH_PORTSC1_SUS_L1_SHIFT              (9U)
/*! SUS_L1 - Suspend using L1
 *  0b0..Suspend using L2
 *  0b1..Suspend using L1
 */
#define USBHSH_PORTSC1_SUS_L1(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUS_L1_SHIFT)) & USBHSH_PORTSC1_SUS_L1_MASK)

#define USBHSH_PORTSC1_LS_MASK                   (0xC00U)
#define USBHSH_PORTSC1_LS_SHIFT                  (10U)
/*! LS - Line Status */
#define USBHSH_PORTSC1_LS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_LS_SHIFT)) & USBHSH_PORTSC1_LS_MASK)

#define USBHSH_PORTSC1_PP_MASK                   (0x1000U)
#define USBHSH_PORTSC1_PP_SHIFT                  (12U)
/*! PP - Port Power */
#define USBHSH_PORTSC1_PP(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PP_SHIFT)) & USBHSH_PORTSC1_PP_MASK)

#define USBHSH_PORTSC1_PIC_MASK                  (0xC000U)
#define USBHSH_PORTSC1_PIC_SHIFT                 (14U)
/*! PIC - Port Indicator Control
 *  0b00..Port Indicators are off
 *  0b01..Amber
 *  0b10..Green
 *  0b11..Undefined
 */
#define USBHSH_PORTSC1_PIC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PIC_SHIFT)) & USBHSH_PORTSC1_PIC_MASK)

#define USBHSH_PORTSC1_PTC_MASK                  (0xF0000U)
#define USBHSH_PORTSC1_PTC_SHIFT                 (16U)
/*! PTC - Port Test Control
 *  0b0000..Test mode not enabled
 *  0b0001..Test J_STATE
 *  0b0010..Test K_STATE
 *  0b0011..TEST SE0_NAK
 *  0b0100..Test_Packet
 *  0b0101..Test Force_Enable
 */
#define USBHSH_PORTSC1_PTC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PTC_SHIFT)) & USBHSH_PORTSC1_PTC_MASK)

#define USBHSH_PORTSC1_PSPD_MASK                 (0x300000U)
#define USBHSH_PORTSC1_PSPD_SHIFT                (20U)
/*! PSPD - Port Speed
 *  0b00..Reserved
 *  0b01..Full-speed
 *  0b10..High-speed
 *  0b11..Reserved
 */
#define USBHSH_PORTSC1_PSPD(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PSPD_SHIFT)) & USBHSH_PORTSC1_PSPD_MASK)

#define USBHSH_PORTSC1_WOO_MASK                  (0x400000U)
#define USBHSH_PORTSC1_WOO_SHIFT                 (22U)
/*! WOO - Wake on overcurrent enable */
#define USBHSH_PORTSC1_WOO(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_WOO_SHIFT)) & USBHSH_PORTSC1_WOO_MASK)

#define USBHSH_PORTSC1_SUS_STAT_MASK             (0x1800000U)
#define USBHSH_PORTSC1_SUS_STAT_SHIFT            (23U)
/*! SUS_STAT - Suspend Status
 *  0b00..State transition was successful (ACK)
 *  0b01..Device was unable to enter the L1 state at this time (NYET)
 *  0b10..Device does not support the L1 state (STALL)
 *  0b11..Timeout/Error - Device failed to respond or an error occurred.
 */
#define USBHSH_PORTSC1_SUS_STAT(x)               (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUS_STAT_SHIFT)) & USBHSH_PORTSC1_SUS_STAT_MASK)

#define USBHSH_PORTSC1_DEV_ADD_MASK              (0xFE000000U)
#define USBHSH_PORTSC1_DEV_ADD_SHIFT             (25U)
/*! DEV_ADD - Device Address for LPM tokens */
#define USBHSH_PORTSC1_DEV_ADD(x)                (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_DEV_ADD_SHIFT)) & USBHSH_PORTSC1_DEV_ADD_MASK)
/*! @} */

/*! @name ATL_PTD_DONE_MAP - ATL PTD Done Map */
/*! @{ */

#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_SHIFT   (0U)
/*! ATL_DONE - ATL Done */
#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_SHIFT)) & USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_MASK)
/*! @} */

/*! @name ATL_PTD_SKIP_MAP - ATL PTD Skip Map */
/*! @{ */

#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_SHIFT   (0U)
/*! ATL_SKIP - ATL PTD Skip Map */
#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_SHIFT)) & USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_MASK)
/*! @} */

/*! @name ISO_PTD_DONE_MAP - ISO PTD Done Map */
/*! @{ */

#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_SHIFT   (0U)
/*! ISO_DONE - ISO Done */
#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_SHIFT)) & USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_MASK)
/*! @} */

/*! @name ISO_PTD_SKIP_MAP - ISO PTD Skip Map */
/*! @{ */

#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_SHIFT   (0U)
/*! ISO_SKIP - ISO Skip */
#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_SHIFT)) & USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_MASK)
/*! @} */

/*! @name INT_PTD_DONE_MAP - INT PTD Done Map */
/*! @{ */

#define USBHSH_INT_PTD_DONE_MAP_INT_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_INT_PTD_DONE_MAP_INT_DONE_SHIFT   (0U)
/*! INT_DONE - INT Done */
#define USBHSH_INT_PTD_DONE_MAP_INT_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_DONE_MAP_INT_DONE_SHIFT)) & USBHSH_INT_PTD_DONE_MAP_INT_DONE_MASK)
/*! @} */

/*! @name INT_PTD_SKIP_MAP - INT PTD Skip Map */
/*! @{ */

#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_SHIFT   (0U)
/*! INT_SKIP - INT Skip */
#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_SHIFT)) & USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_MASK)
/*! @} */

/*! @name LAST_PTD_INUSE - Last PTD in use */
/*! @{ */

#define USBHSH_LAST_PTD_INUSE_ATL_LAST_MASK      (0x1FU)
#define USBHSH_LAST_PTD_INUSE_ATL_LAST_SHIFT     (0U)
/*! ATL_LAST - Last PTD in ATL list */
#define USBHSH_LAST_PTD_INUSE_ATL_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_ATL_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_ATL_LAST_MASK)

#define USBHSH_LAST_PTD_INUSE_ISO_LAST_MASK      (0x1F00U)
#define USBHSH_LAST_PTD_INUSE_ISO_LAST_SHIFT     (8U)
/*! ISO_LAST - Last PTD in ISO list */
#define USBHSH_LAST_PTD_INUSE_ISO_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_ISO_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_ISO_LAST_MASK)

#define USBHSH_LAST_PTD_INUSE_INT_LAST_MASK      (0x1F0000U)
#define USBHSH_LAST_PTD_INUSE_INT_LAST_SHIFT     (16U)
/*! INT_LAST - Last PTD in INT list */
#define USBHSH_LAST_PTD_INUSE_INT_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_INT_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_INT_LAST_MASK)
/*! @} */

/*! @name PORTMODE - Port Mode */
/*! @{ */

#define USBHSH_PORTMODE_DEV_ENABLE_MASK          (0x10000U)
#define USBHSH_PORTMODE_DEV_ENABLE_SHIFT         (16U)
/*! DEV_ENABLE - If this bit is set to one, the port will behave as a USB device. If this bit is set
 *    to zero, the port will be controlled by the USB host block.
 */
#define USBHSH_PORTMODE_DEV_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_DEV_ENABLE_SHIFT)) & USBHSH_PORTMODE_DEV_ENABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBHSH_Register_Masks */


/*!
 * @}
 */ /* end of group USBHSH_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_USBHSH_H_ */

