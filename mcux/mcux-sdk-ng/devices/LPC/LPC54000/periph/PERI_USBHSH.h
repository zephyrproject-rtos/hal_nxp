/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBHSH.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBHSH
 *
 * CMSIS Peripheral Access Layer for USBHSH
 */

#if !defined(PERI_USBHSH_H_)
#define PERI_USBHSH_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- USBHSH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSH_Peripheral_Access_Layer USBHSH Peripheral Access Layer
 * @{
 */

/** USBHSH - Register Layout Typedef */
typedef struct {
  __I  uint32_t CAPLENGTH_CHIPID;                  /**< This register contains the offset value towards the start of the operational register space and the version number of the IP block, offset: 0x0 */
  __I  uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x4 */
  __I  uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x8 */
  __IO uint32_t FLADJ_FRINDEX;                     /**< Frame Length Adjustment, offset: 0xC */
  __IO uint32_t ATL_PTD_BASE_ADDR;                 /**< Memory base address where ATL PTD0 is stored, offset: 0x10 */
  __IO uint32_t ISO_PTD_BASE_ADDR;                 /**< Memory base address where ISO PTD0 is stored, offset: 0x14 */
  __IO uint32_t INT_PTD_BASE_ADDR;                 /**< Memory base address where INT PTD0 is stored, offset: 0x18 */
  __IO uint32_t DATA_PAYLOAD_BASE_ADDR;            /**< Memory base address that indicates the start of the data payload buffers, offset: 0x1C */
  __IO uint32_t USBCMD;                            /**< USB Command register, offset: 0x20 */
  __IO uint32_t USBSTS;                            /**< USB Interrupt Status register, offset: 0x24 */
  __IO uint32_t USBINTR;                           /**< USB Interrupt Enable register, offset: 0x28 */
  __IO uint32_t PORTSC1;                           /**< Port Status and Control register, offset: 0x2C */
  __IO uint32_t ATL_PTD_DONE_MAP;                  /**< Done map for each ATL PTD, offset: 0x30 */
  __IO uint32_t ATL_PTD_SKIP_MAP;                  /**< Skip map for each ATL PTD, offset: 0x34 */
  __IO uint32_t ISO_PTD_DONE_MAP;                  /**< Done map for each ISO PTD, offset: 0x38 */
  __IO uint32_t ISO_PTD_SKIP_MAP;                  /**< Skip map for each ISO PTD, offset: 0x3C */
  __IO uint32_t INT_PTD_DONE_MAP;                  /**< Done map for each INT PTD, offset: 0x40 */
  __IO uint32_t INT_PTD_SKIP_MAP;                  /**< Skip map for each INT PTD, offset: 0x44 */
  __IO uint32_t LAST_PTD_INUSE;                    /**< Marks the last PTD in the list for ISO, INT and ATL, offset: 0x48 */
  __IO uint32_t UTMIPLUS_ULPI_DEBUG;               /**< Register to read/write registers in the attached USB PHY, offset: 0x4C */
  __IO uint32_t PORTMODE;                          /**< Controls the port if it is attached to the host block or the device block, offset: 0x50 */
} USBHSH_Type;

/* ----------------------------------------------------------------------------
   -- USBHSH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBHSH_Register_Masks USBHSH Register Masks
 * @{
 */

/*! @name CAPLENGTH_CHIPID - This register contains the offset value towards the start of the operational register space and the version number of the IP block */
/*! @{ */

#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_MASK   (0xFFU)
#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_SHIFT  (0U)
/*! CAPLENGTH - Capability Length: This is used as an offset. */
#define USBHSH_CAPLENGTH_CHIPID_CAPLENGTH(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_SHIFT)) & USBHSH_CAPLENGTH_CHIPID_CAPLENGTH_MASK)

#define USBHSH_CAPLENGTH_CHIPID_CHIPID_MASK      (0xFFFF0000U)
#define USBHSH_CAPLENGTH_CHIPID_CHIPID_SHIFT     (16U)
/*! CHIPID - Chip identification: indicates major and minor revision of the IP: [31:24] = Major
 *    revision [23:16] = Minor revision Major revisions used: 0x01: USB2.
 */
#define USBHSH_CAPLENGTH_CHIPID_CHIPID(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_CAPLENGTH_CHIPID_CHIPID_SHIFT)) & USBHSH_CAPLENGTH_CHIPID_CHIPID_MASK)
/*! @} */

/*! @name HCSPARAMS - Host Controller Structural Parameters */
/*! @{ */

#define USBHSH_HCSPARAMS_N_PORTS_MASK            (0xFU)
#define USBHSH_HCSPARAMS_N_PORTS_SHIFT           (0U)
/*! N_PORTS - This register specifies the number of physical downstream ports implemented on this host controller. */
#define USBHSH_HCSPARAMS_N_PORTS(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_N_PORTS_SHIFT)) & USBHSH_HCSPARAMS_N_PORTS_MASK)

#define USBHSH_HCSPARAMS_PPC_MASK                (0x10U)
#define USBHSH_HCSPARAMS_PPC_SHIFT               (4U)
/*! PPC - This field indicates whether the host controller implementation includes port power control. */
#define USBHSH_HCSPARAMS_PPC(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_PPC_SHIFT)) & USBHSH_HCSPARAMS_PPC_MASK)

#define USBHSH_HCSPARAMS_P_INDICATOR_MASK        (0x10000U)
#define USBHSH_HCSPARAMS_P_INDICATOR_SHIFT       (16U)
/*! P_INDICATOR - This bit indicates whether the ports support port indicator control. */
#define USBHSH_HCSPARAMS_P_INDICATOR(x)          (((uint32_t)(((uint32_t)(x)) << USBHSH_HCSPARAMS_P_INDICATOR_SHIFT)) & USBHSH_HCSPARAMS_P_INDICATOR_MASK)
/*! @} */

/*! @name HCCPARAMS - Host Controller Capability Parameters */
/*! @{ */

#define USBHSH_HCCPARAMS_LPMC_MASK               (0x20000U)
#define USBHSH_HCCPARAMS_LPMC_SHIFT              (17U)
/*! LPMC - Link Power Management Capability. */
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
/*! FRINDEX - Frame Index: Bits 29 to16 in this register are used for the frame number field in the SOF packet. */
#define USBHSH_FLADJ_FRINDEX_FRINDEX(x)          (((uint32_t)(((uint32_t)(x)) << USBHSH_FLADJ_FRINDEX_FRINDEX_SHIFT)) & USBHSH_FLADJ_FRINDEX_FRINDEX_MASK)
/*! @} */

/*! @name ATL_PTD_BASE_ADDR - Memory base address where ATL PTD0 is stored */
/*! @{ */

#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_MASK    (0x1F0U)
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_SHIFT   (4U)
/*! ATL_CUR - This indicates the current PTD that is used by the hardware when it is processing the ATL list. */
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_SHIFT)) & USBHSH_ATL_PTD_BASE_ADDR_ATL_CUR_MASK)

#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_MASK   (0xFFFFFE00U)
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_SHIFT  (9U)
/*! ATL_BASE - Base address to be used by the hardware to find the start of the ATL list. */
#define USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_SHIFT)) & USBHSH_ATL_PTD_BASE_ADDR_ATL_BASE_MASK)
/*! @} */

/*! @name ISO_PTD_BASE_ADDR - Memory base address where ISO PTD0 is stored */
/*! @{ */

#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_MASK  (0x3E0U)
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_SHIFT (5U)
/*! ISO_FIRST - This indicates the first PTD that is used by the hardware when it is processing the ISO list. */
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST(x)    (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_SHIFT)) & USBHSH_ISO_PTD_BASE_ADDR_ISO_FIRST_MASK)

#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_MASK   (0xFFFFFC00U)
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_SHIFT  (10U)
/*! ISO_BASE - Base address to be used by the hardware to find the start of the ISO list. */
#define USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_SHIFT)) & USBHSH_ISO_PTD_BASE_ADDR_ISO_BASE_MASK)
/*! @} */

/*! @name INT_PTD_BASE_ADDR - Memory base address where INT PTD0 is stored */
/*! @{ */

#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_MASK  (0x3E0U)
#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_SHIFT (5U)
/*! INT_FIRST - This indicates the first PTD that is used by the hardware when it is processing the INT list. */
#define USBHSH_INT_PTD_BASE_ADDR_INT_FIRST(x)    (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_SHIFT)) & USBHSH_INT_PTD_BASE_ADDR_INT_FIRST_MASK)

#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE_MASK   (0xFFFFFC00U)
#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE_SHIFT  (10U)
/*! INT_BASE - Base address to be used by the hardware to find the start of the INT list. */
#define USBHSH_INT_PTD_BASE_ADDR_INT_BASE(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_BASE_ADDR_INT_BASE_SHIFT)) & USBHSH_INT_PTD_BASE_ADDR_INT_BASE_MASK)
/*! @} */

/*! @name DATA_PAYLOAD_BASE_ADDR - Memory base address that indicates the start of the data payload buffers */
/*! @{ */

#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_MASK (0xFFFF0000U)
#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_SHIFT (16U)
/*! DAT_BASE - Base address to be used by the hardware to find the start of the data payload section. */
#define USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE(x) (((uint32_t)(((uint32_t)(x)) << USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_SHIFT)) & USBHSH_DATA_PAYLOAD_BASE_ADDR_DAT_BASE_MASK)
/*! @} */

/*! @name USBCMD - USB Command register */
/*! @{ */

#define USBHSH_USBCMD_RS_MASK                    (0x1U)
#define USBHSH_USBCMD_RS_SHIFT                   (0U)
/*! RS - Run/Stop: 1b = Run. */
#define USBHSH_USBCMD_RS(x)                      (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_RS_SHIFT)) & USBHSH_USBCMD_RS_MASK)

#define USBHSH_USBCMD_HCRESET_MASK               (0x2U)
#define USBHSH_USBCMD_HCRESET_SHIFT              (1U)
/*! HCRESET - Host Controller Reset: This control bit is used by the software to reset the host controller. */
#define USBHSH_USBCMD_HCRESET(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_HCRESET_SHIFT)) & USBHSH_USBCMD_HCRESET_MASK)

#define USBHSH_USBCMD_FLS_MASK                   (0xCU)
#define USBHSH_USBCMD_FLS_SHIFT                  (2U)
/*! FLS - Frame List Size: This field specifies the size of the frame list. */
#define USBHSH_USBCMD_FLS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_FLS_SHIFT)) & USBHSH_USBCMD_FLS_MASK)

#define USBHSH_USBCMD_LHCR_MASK                  (0x80U)
#define USBHSH_USBCMD_LHCR_SHIFT                 (7U)
/*! LHCR - Light Host Controller Reset: This bit allows the driver software to reset the host
 *    controller without affecting the state of the ports.
 */
#define USBHSH_USBCMD_LHCR(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_LHCR_SHIFT)) & USBHSH_USBCMD_LHCR_MASK)

#define USBHSH_USBCMD_ATL_EN_MASK                (0x100U)
#define USBHSH_USBCMD_ATL_EN_SHIFT               (8U)
/*! ATL_EN - ATL List enabled. */
#define USBHSH_USBCMD_ATL_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_ATL_EN_SHIFT)) & USBHSH_USBCMD_ATL_EN_MASK)

#define USBHSH_USBCMD_ISO_EN_MASK                (0x200U)
#define USBHSH_USBCMD_ISO_EN_SHIFT               (9U)
/*! ISO_EN - ISO List enabled. */
#define USBHSH_USBCMD_ISO_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_ISO_EN_SHIFT)) & USBHSH_USBCMD_ISO_EN_MASK)

#define USBHSH_USBCMD_INT_EN_MASK                (0x400U)
#define USBHSH_USBCMD_INT_EN_SHIFT               (10U)
/*! INT_EN - INT List enabled. */
#define USBHSH_USBCMD_INT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_INT_EN_SHIFT)) & USBHSH_USBCMD_INT_EN_MASK)

#define USBHSH_USBCMD_HIRD_MASK                  (0xF000000U)
#define USBHSH_USBCMD_HIRD_SHIFT                 (24U)
/*! HIRD - Host-Initiated Resume Duration. */
#define USBHSH_USBCMD_HIRD(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_HIRD_SHIFT)) & USBHSH_USBCMD_HIRD_MASK)

#define USBHSH_USBCMD_LPM_RWU_MASK               (0x10000000U)
#define USBHSH_USBCMD_LPM_RWU_SHIFT              (28U)
/*! LPM_RWU - bRemoteWake field. */
#define USBHSH_USBCMD_LPM_RWU(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBCMD_LPM_RWU_SHIFT)) & USBHSH_USBCMD_LPM_RWU_MASK)
/*! @} */

/*! @name USBSTS - USB Interrupt Status register */
/*! @{ */

#define USBHSH_USBSTS_PCD_MASK                   (0x4U)
#define USBHSH_USBSTS_PCD_SHIFT                  (2U)
/*! PCD - Port Change Detect: The host controller sets this bit to logic 1 when any port has a
 *    change bit transition from a 0 to a one or a Force Port Resume bit transition from a 0 to a 1 as a
 *    result of a J-K transition detected on a suspended port.
 */
#define USBHSH_USBSTS_PCD(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_PCD_SHIFT)) & USBHSH_USBSTS_PCD_MASK)

#define USBHSH_USBSTS_FLR_MASK                   (0x8U)
#define USBHSH_USBSTS_FLR_SHIFT                  (3U)
/*! FLR - Frame List Rollover: The host controller sets this bit to logic 1 when the frame list
 *    index rolls over its maximum value to 0.
 */
#define USBHSH_USBSTS_FLR(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_FLR_SHIFT)) & USBHSH_USBSTS_FLR_MASK)

#define USBHSH_USBSTS_ATL_IRQ_MASK               (0x10000U)
#define USBHSH_USBSTS_ATL_IRQ_SHIFT              (16U)
/*! ATL_IRQ - ATL IRQ: Indicates that an ATL PTD (with I-bit set) was completed. */
#define USBHSH_USBSTS_ATL_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_ATL_IRQ_SHIFT)) & USBHSH_USBSTS_ATL_IRQ_MASK)

#define USBHSH_USBSTS_ISO_IRQ_MASK               (0x20000U)
#define USBHSH_USBSTS_ISO_IRQ_SHIFT              (17U)
/*! ISO_IRQ - ISO IRQ: Indicates that an ISO PTD (with I-bit set) was completed. */
#define USBHSH_USBSTS_ISO_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_ISO_IRQ_SHIFT)) & USBHSH_USBSTS_ISO_IRQ_MASK)

#define USBHSH_USBSTS_INT_IRQ_MASK               (0x40000U)
#define USBHSH_USBSTS_INT_IRQ_SHIFT              (18U)
/*! INT_IRQ - INT IRQ: Indicates that an INT PTD (with I-bit set) was completed. */
#define USBHSH_USBSTS_INT_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_INT_IRQ_SHIFT)) & USBHSH_USBSTS_INT_IRQ_MASK)

#define USBHSH_USBSTS_SOF_IRQ_MASK               (0x80000U)
#define USBHSH_USBSTS_SOF_IRQ_SHIFT              (19U)
/*! SOF_IRQ - SOF interrupt: Every time when the host sends a Start of Frame token on the USB bus, this bit is set. */
#define USBHSH_USBSTS_SOF_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_USBSTS_SOF_IRQ_SHIFT)) & USBHSH_USBSTS_SOF_IRQ_MASK)
/*! @} */

/*! @name USBINTR - USB Interrupt Enable register */
/*! @{ */

#define USBHSH_USBINTR_PCDE_MASK                 (0x4U)
#define USBHSH_USBINTR_PCDE_SHIFT                (2U)
/*! PCDE - Port Change Detect Interrupt Enable: 1: enable 0: disable. */
#define USBHSH_USBINTR_PCDE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_PCDE_SHIFT)) & USBHSH_USBINTR_PCDE_MASK)

#define USBHSH_USBINTR_FLRE_MASK                 (0x8U)
#define USBHSH_USBINTR_FLRE_SHIFT                (3U)
/*! FLRE - Frame List Rollover Interrupt Enable: 1: enable 0: disable. */
#define USBHSH_USBINTR_FLRE(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_FLRE_SHIFT)) & USBHSH_USBINTR_FLRE_MASK)

#define USBHSH_USBINTR_ATL_IRQ_E_MASK            (0x10000U)
#define USBHSH_USBINTR_ATL_IRQ_E_SHIFT           (16U)
/*! ATL_IRQ_E - ATL IRQ Enable bit: 1: enable 0: disable. */
#define USBHSH_USBINTR_ATL_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_ATL_IRQ_E_SHIFT)) & USBHSH_USBINTR_ATL_IRQ_E_MASK)

#define USBHSH_USBINTR_ISO_IRQ_E_MASK            (0x20000U)
#define USBHSH_USBINTR_ISO_IRQ_E_SHIFT           (17U)
/*! ISO_IRQ_E - ISO IRQ Enable bit: 1: enable 0: disable. */
#define USBHSH_USBINTR_ISO_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_ISO_IRQ_E_SHIFT)) & USBHSH_USBINTR_ISO_IRQ_E_MASK)

#define USBHSH_USBINTR_INT_IRQ_E_MASK            (0x40000U)
#define USBHSH_USBINTR_INT_IRQ_E_SHIFT           (18U)
/*! INT_IRQ_E - INT IRQ Enable bit: 1: enable 0: disable. */
#define USBHSH_USBINTR_INT_IRQ_E(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_INT_IRQ_E_SHIFT)) & USBHSH_USBINTR_INT_IRQ_E_MASK)

#define USBHSH_USBINTR_SOF_E_MASK                (0x80000U)
#define USBHSH_USBINTR_SOF_E_SHIFT               (19U)
/*! SOF_E - SOF Interrupt Enable bit: 1: enable 0: disable. */
#define USBHSH_USBINTR_SOF_E(x)                  (((uint32_t)(((uint32_t)(x)) << USBHSH_USBINTR_SOF_E_SHIFT)) & USBHSH_USBINTR_SOF_E_MASK)
/*! @} */

/*! @name PORTSC1 - Port Status and Control register */
/*! @{ */

#define USBHSH_PORTSC1_CCS_MASK                  (0x1U)
#define USBHSH_PORTSC1_CCS_SHIFT                 (0U)
/*! CCS - Current Connect Status: Logic 1 indicates a device is present on the port. */
#define USBHSH_PORTSC1_CCS(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_CCS_SHIFT)) & USBHSH_PORTSC1_CCS_MASK)

#define USBHSH_PORTSC1_CSC_MASK                  (0x2U)
#define USBHSH_PORTSC1_CSC_SHIFT                 (1U)
/*! CSC - Connect Status Change: Logic 1 means that the value of CCS has changed. */
#define USBHSH_PORTSC1_CSC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_CSC_SHIFT)) & USBHSH_PORTSC1_CSC_MASK)

#define USBHSH_PORTSC1_PED_MASK                  (0x4U)
#define USBHSH_PORTSC1_PED_SHIFT                 (2U)
/*! PED - Port Enabled/Disabled. */
#define USBHSH_PORTSC1_PED(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PED_SHIFT)) & USBHSH_PORTSC1_PED_MASK)

#define USBHSH_PORTSC1_PEDC_MASK                 (0x8U)
#define USBHSH_PORTSC1_PEDC_SHIFT                (3U)
/*! PEDC - Port Enabled/Disabled Change: Logic 1 means that the value of PED has changed. */
#define USBHSH_PORTSC1_PEDC(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PEDC_SHIFT)) & USBHSH_PORTSC1_PEDC_MASK)

#define USBHSH_PORTSC1_OCA_MASK                  (0x10U)
#define USBHSH_PORTSC1_OCA_SHIFT                 (4U)
/*! OCA - Over-current active: Logic 1 means that this port has an over-current condition. */
#define USBHSH_PORTSC1_OCA(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_OCA_SHIFT)) & USBHSH_PORTSC1_OCA_MASK)

#define USBHSH_PORTSC1_OCC_MASK                  (0x20U)
#define USBHSH_PORTSC1_OCC_SHIFT                 (5U)
/*! OCC - Over-current change: Logic 1 means that the value of OCA has changed. */
#define USBHSH_PORTSC1_OCC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_OCC_SHIFT)) & USBHSH_PORTSC1_OCC_MASK)

#define USBHSH_PORTSC1_FPR_MASK                  (0x40U)
#define USBHSH_PORTSC1_FPR_SHIFT                 (6U)
/*! FPR - Force Port Resume: Logic 1 means resume (K-state) detected or driven on the port. */
#define USBHSH_PORTSC1_FPR(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_FPR_SHIFT)) & USBHSH_PORTSC1_FPR_MASK)

#define USBHSH_PORTSC1_SUSP_MASK                 (0x80U)
#define USBHSH_PORTSC1_SUSP_SHIFT                (7U)
/*! SUSP - Suspend: Logic 1 means port is in the suspend state. */
#define USBHSH_PORTSC1_SUSP(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUSP_SHIFT)) & USBHSH_PORTSC1_SUSP_MASK)

#define USBHSH_PORTSC1_PR_MASK                   (0x100U)
#define USBHSH_PORTSC1_PR_SHIFT                  (8U)
/*! PR - Port Reset: Logic 1 means the port is in the reset state. */
#define USBHSH_PORTSC1_PR(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PR_SHIFT)) & USBHSH_PORTSC1_PR_MASK)

#define USBHSH_PORTSC1_SUS_L1_MASK               (0x200U)
#define USBHSH_PORTSC1_SUS_L1_SHIFT              (9U)
/*! SUS_L1 - Suspend using L1 0b = Suspend using L2 1b = Suspend using L1 When this bit is set to a
 *    1 and a non-zero value is specified in the Device Address field, the host controller will
 *    generate an LPM Token to enter the L1 state whenever software writes a one to the Suspend bit, as
 *    well as L1 exit timing during any device or host-initiated resume.
 */
#define USBHSH_PORTSC1_SUS_L1(x)                 (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUS_L1_SHIFT)) & USBHSH_PORTSC1_SUS_L1_MASK)

#define USBHSH_PORTSC1_LS_MASK                   (0xC00U)
#define USBHSH_PORTSC1_LS_SHIFT                  (10U)
/*! LS - Line Status: This field reflects the current logical levels of the DP (bit 11) and DM (bit 10) signal lines. */
#define USBHSH_PORTSC1_LS(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_LS_SHIFT)) & USBHSH_PORTSC1_LS_MASK)

#define USBHSH_PORTSC1_PP_MASK                   (0x1000U)
#define USBHSH_PORTSC1_PP_SHIFT                  (12U)
/*! PP - Port Power: The function of this bit depends on the value of the Port Power Control (PPC) bit in the HCSPARAMS register. */
#define USBHSH_PORTSC1_PP(x)                     (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PP_SHIFT)) & USBHSH_PORTSC1_PP_MASK)

#define USBHSH_PORTSC1_PIC_MASK                  (0xC000U)
#define USBHSH_PORTSC1_PIC_SHIFT                 (14U)
/*! PIC - Port Indicator Control : Writing to this field has no effect if the P_INDICATOR bit in the
 *    HCSPARAMS register is logic 0.
 */
#define USBHSH_PORTSC1_PIC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PIC_SHIFT)) & USBHSH_PORTSC1_PIC_MASK)

#define USBHSH_PORTSC1_PTC_MASK                  (0xF0000U)
#define USBHSH_PORTSC1_PTC_SHIFT                 (16U)
/*! PTC - Port Test Control: A non-zero value indicates that the port is operating in the test mode as indicated by the value. */
#define USBHSH_PORTSC1_PTC(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PTC_SHIFT)) & USBHSH_PORTSC1_PTC_MASK)

#define USBHSH_PORTSC1_PSPD_MASK                 (0x300000U)
#define USBHSH_PORTSC1_PSPD_SHIFT                (20U)
/*! PSPD - Port Speed: 00b: Low-speed 01b: Full-speed 10b: High-speed 11b: Reserved. */
#define USBHSH_PORTSC1_PSPD(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_PSPD_SHIFT)) & USBHSH_PORTSC1_PSPD_MASK)

#define USBHSH_PORTSC1_WOO_MASK                  (0x400000U)
#define USBHSH_PORTSC1_WOO_SHIFT                 (22U)
/*! WOO - Wake on overcurrent enable: Writing this bit to a one enables the port to be sensitive to
 *    overcurrent conditions as wake-up events.
 */
#define USBHSH_PORTSC1_WOO(x)                    (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_WOO_SHIFT)) & USBHSH_PORTSC1_WOO_MASK)

#define USBHSH_PORTSC1_SUS_STAT_MASK             (0x1800000U)
#define USBHSH_PORTSC1_SUS_STAT_SHIFT            (23U)
/*! SUS_STAT - These two bits are used by software to determine whether the most recent L1 suspend
 *    request was successful: 00b: Success-state transition was successful (ACK) 01b: Not Yet -
 *    Device was unable to enter the L1 state at this time (NYET) 10b: Not supported - Device does not
 *    support the L1 state (STALL) 11b: Timeout/Error - Device failed to respond or an error occurred.
 */
#define USBHSH_PORTSC1_SUS_STAT(x)               (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_SUS_STAT_SHIFT)) & USBHSH_PORTSC1_SUS_STAT_MASK)

#define USBHSH_PORTSC1_DEV_ADD_MASK              (0xFE000000U)
#define USBHSH_PORTSC1_DEV_ADD_SHIFT             (25U)
/*! DEV_ADD - Device Address for LPM tokens. */
#define USBHSH_PORTSC1_DEV_ADD(x)                (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTSC1_DEV_ADD_SHIFT)) & USBHSH_PORTSC1_DEV_ADD_MASK)
/*! @} */

/*! @name ATL_PTD_DONE_MAP - Done map for each ATL PTD */
/*! @{ */

#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_SHIFT   (0U)
/*! ATL_DONE - The bit corresponding to a certain PTD will be set to logic 1 as soon as that PTD execution is completed. */
#define USBHSH_ATL_PTD_DONE_MAP_ATL_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_SHIFT)) & USBHSH_ATL_PTD_DONE_MAP_ATL_DONE_MASK)
/*! @} */

/*! @name ATL_PTD_SKIP_MAP - Skip map for each ATL PTD */
/*! @{ */

#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_SHIFT   (0U)
/*! ATL_SKIP - When a bit in the PTD Skip Map is set to logic 1, the corresponding PTD will be
 *    skipped, independent of the V bit setting.
 */
#define USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_SHIFT)) & USBHSH_ATL_PTD_SKIP_MAP_ATL_SKIP_MASK)
/*! @} */

/*! @name ISO_PTD_DONE_MAP - Done map for each ISO PTD */
/*! @{ */

#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_SHIFT   (0U)
/*! ISO_DONE - The bit corresponding to a certain PTD will be set to logic 1 as soon as that PTD execution is completed. */
#define USBHSH_ISO_PTD_DONE_MAP_ISO_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_SHIFT)) & USBHSH_ISO_PTD_DONE_MAP_ISO_DONE_MASK)
/*! @} */

/*! @name ISO_PTD_SKIP_MAP - Skip map for each ISO PTD */
/*! @{ */

#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_SHIFT   (0U)
/*! ISO_SKIP - The bit corresponding to a certain PTD will be set to logic 1 as soon as that PTD execution is completed. */
#define USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_SHIFT)) & USBHSH_ISO_PTD_SKIP_MAP_ISO_SKIP_MASK)
/*! @} */

/*! @name INT_PTD_DONE_MAP - Done map for each INT PTD */
/*! @{ */

#define USBHSH_INT_PTD_DONE_MAP_INT_DONE_MASK    (0xFFFFFFFFU)
#define USBHSH_INT_PTD_DONE_MAP_INT_DONE_SHIFT   (0U)
/*! INT_DONE - The bit corresponding to a certain PTD will be set to logic 1 as soon as that PTD execution is completed. */
#define USBHSH_INT_PTD_DONE_MAP_INT_DONE(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_DONE_MAP_INT_DONE_SHIFT)) & USBHSH_INT_PTD_DONE_MAP_INT_DONE_MASK)
/*! @} */

/*! @name INT_PTD_SKIP_MAP - Skip map for each INT PTD */
/*! @{ */

#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_MASK    (0xFFFFFFFFU)
#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_SHIFT   (0U)
/*! INT_SKIP - When a bit in the PTD Skip Map is set to logic 1, the corresponding PTD will be
 *    skipped, independent of the V bit setting.
 */
#define USBHSH_INT_PTD_SKIP_MAP_INT_SKIP(x)      (((uint32_t)(((uint32_t)(x)) << USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_SHIFT)) & USBHSH_INT_PTD_SKIP_MAP_INT_SKIP_MASK)
/*! @} */

/*! @name LAST_PTD_INUSE - Marks the last PTD in the list for ISO, INT and ATL */
/*! @{ */

#define USBHSH_LAST_PTD_INUSE_ATL_LAST_MASK      (0x1FU)
#define USBHSH_LAST_PTD_INUSE_ATL_LAST_SHIFT     (0U)
/*! ATL_LAST - If hardware has reached this PTD and the J bit is not set, it will go to PTD0 as the next PTD to be processed. */
#define USBHSH_LAST_PTD_INUSE_ATL_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_ATL_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_ATL_LAST_MASK)

#define USBHSH_LAST_PTD_INUSE_ISO_LAST_MASK      (0x1F00U)
#define USBHSH_LAST_PTD_INUSE_ISO_LAST_SHIFT     (8U)
/*! ISO_LAST - This indicates the last PTD in the ISO list. */
#define USBHSH_LAST_PTD_INUSE_ISO_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_ISO_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_ISO_LAST_MASK)

#define USBHSH_LAST_PTD_INUSE_INT_LAST_MASK      (0x1F0000U)
#define USBHSH_LAST_PTD_INUSE_INT_LAST_SHIFT     (16U)
/*! INT_LAST - This indicates the last PTD in the INT list. */
#define USBHSH_LAST_PTD_INUSE_INT_LAST(x)        (((uint32_t)(((uint32_t)(x)) << USBHSH_LAST_PTD_INUSE_INT_LAST_SHIFT)) & USBHSH_LAST_PTD_INUSE_INT_LAST_MASK)
/*! @} */

/*! @name UTMIPLUS_ULPI_DEBUG - Register to read/write registers in the attached USB PHY */
/*! @{ */

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ADDR_MASK (0xFFU)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ADDR_SHIFT (0U)
/*! PHY_ADDR - UTMI+ mode: Bits 3:0 are used to control VControl signal on Vendor Interface of UTMI+
 *    ULPI mode: Bits 7:0 are used as the address when doing a register access over the ULPI
 *    interface.
 */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ADDR(x)   (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ADDR_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ADDR_MASK)

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_WDATA_MASK (0xFF00U)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_WDATA_SHIFT (8U)
/*! PHY_WDATA - UTMI+ mode: Reserved. */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_WDATA(x)  (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_WDATA_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_WDATA_MASK)

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RDATA_MASK (0xFF0000U)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RDATA_SHIFT (16U)
/*! PHY_RDATA - UTMI+ mode: Bits 7:0 contains the value returned by the VStatus signal on Vendor
 *    Interface of UTMI+ ULPI mode: Bits 7:0 are used for the read data when reading a value to a ULPI
 *    PHY register.
 */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RDATA(x)  (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RDATA_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RDATA_MASK)

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RW_MASK   (0x1000000U)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RW_SHIFT  (24U)
/*! PHY_RW - UTMI+ mode: Reserved. */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RW(x)     (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RW_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_RW_MASK)

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ACCESS_MASK (0x2000000U)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ACCESS_SHIFT (25U)
/*! PHY_ACCESS - Software writes this bit to one to start a read or write operation. */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ACCESS_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_ACCESS_MASK)

#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_MODE_MASK (0x80000000U)
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_MODE_SHIFT (31U)
/*! PHY_MODE - This bit indicates if the interface between the controller is UTMI+ or ULPI 0b: UTMI+
 *    1b: ULPI If the hardware supports both modes, this bit is RW by SW.
 */
#define USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_MODE(x)   (((uint32_t)(((uint32_t)(x)) << USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_MODE_SHIFT)) & USBHSH_UTMIPLUS_ULPI_DEBUG_PHY_MODE_MASK)
/*! @} */

/*! @name PORTMODE - Controls the port if it is attached to the host block or the device block */
/*! @{ */

#define USBHSH_PORTMODE_ID0_MASK                 (0x1U)
#define USBHSH_PORTMODE_ID0_SHIFT                (0U)
/*! ID0 - Port 0 ID pin value. */
#define USBHSH_PORTMODE_ID0(x)                   (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_ID0_SHIFT)) & USBHSH_PORTMODE_ID0_MASK)

#define USBHSH_PORTMODE_ID0_EN_MASK              (0x100U)
#define USBHSH_PORTMODE_ID0_EN_SHIFT             (8U)
/*! ID0_EN - Port 0 ID pin pull-up enable. */
#define USBHSH_PORTMODE_ID0_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_ID0_EN_SHIFT)) & USBHSH_PORTMODE_ID0_EN_MASK)

#define USBHSH_PORTMODE_DEV_ENABLE_MASK          (0x10000U)
#define USBHSH_PORTMODE_DEV_ENABLE_SHIFT         (16U)
/*! DEV_ENABLE - If this bit is set to one, one of the ports will behave as a USB device. */
#define USBHSH_PORTMODE_DEV_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_DEV_ENABLE_SHIFT)) & USBHSH_PORTMODE_DEV_ENABLE_MASK)

#define USBHSH_PORTMODE_SW_CTRL_PDCOM_MASK       (0x40000U)
#define USBHSH_PORTMODE_SW_CTRL_PDCOM_SHIFT      (18U)
/*! SW_CTRL_PDCOM - This bit indicates if the PHY power-down input is controlled by software or by hardware. */
#define USBHSH_PORTMODE_SW_CTRL_PDCOM(x)         (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_SW_CTRL_PDCOM_SHIFT)) & USBHSH_PORTMODE_SW_CTRL_PDCOM_MASK)

#define USBHSH_PORTMODE_SW_PDCOM_MASK            (0x80000U)
#define USBHSH_PORTMODE_SW_PDCOM_SHIFT           (19U)
/*! SW_PDCOM - This bit is only used when SW_CTRL_PDCOM is set to 1b. */
#define USBHSH_PORTMODE_SW_PDCOM(x)              (((uint32_t)(((uint32_t)(x)) << USBHSH_PORTMODE_SW_PDCOM_SHIFT)) & USBHSH_PORTMODE_SW_PDCOM_MASK)
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_USBHSH_H_ */

