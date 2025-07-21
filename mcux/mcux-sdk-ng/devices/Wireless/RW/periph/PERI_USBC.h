/*
** ###################################################################
**     Processors:          RW610ETA2I
**                          RW610HNA2I
**                          RW610UKA2I
**                          RW612ETA2I
**                          RW612HNA2I
**                          RW612UKA2I
**
**     Version:             rev. 3.0, 2025-04-07
**     Build:               b250519
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-16)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 3.0 (2025-04-07)
**         Based on CRR Rev9.1.
**
** ###################################################################
*/

/*!
 * @file PERI_USBC.h
 * @version 3.0
 * @date 2025-04-07
 * @brief CMSIS Peripheral Access Layer for USBC
 *
 * CMSIS Peripheral Access Layer for USBC
 */

#if !defined(PERI_USBC_H_)
#define PERI_USBC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_RW610ETA2I) || defined(CPU_RW610HNA2I) || defined(CPU_RW610UKA2I))
#include "RW610_COMMON.h"
#elif (defined(CPU_RW612ETA2I) || defined(CPU_RW612HNA2I) || defined(CPU_RW612UKA2I))
#include "RW612_COMMON.h"
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
   -- USBC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBC_Peripheral_Access_Layer USBC Peripheral Access Layer
 * @{
 */

/** USBC - Size of Registers Arrays */
#define USBC_ENDPTCTRL_COUNT                      7u

/** USBC - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID;                                /**< Identification, offset: 0x0 */
  __I  uint32_t HWGENERAL;                         /**< General Hardware Parameters, offset: 0x4 */
  __I  uint32_t HWHOST;                            /**< Host Hardware Parameters, offset: 0x8 */
  __I  uint32_t HWDEVICE;                          /**< Device Hardware Parameters, offset: 0xC */
  __I  uint32_t HWTXBUF;                           /**< TX Buffer Hardware Parameters, offset: 0x10 */
  __I  uint32_t HWRXBUF;                           /**< RX Buffer Hardware Parameters, offset: 0x14 */
  __IO uint32_t HWTXBUF_CTRL0;                     /**< Tx Buffer Hardware Control 0, offset: 0x18 */
       uint8_t RESERVED_0[100];
  __IO uint32_t GPTIMER0LD;                        /**< General Purpose Timer 0 Load, offset: 0x80 */
  __IO uint32_t GPTIMER0CTRL;                      /**< General Purpose Timer 0 Control, offset: 0x84 */
  __IO uint32_t GPTIMER1LD;                        /**< General Purpose Timer 1 Load, offset: 0x88 */
  __IO uint32_t GPTIMER1CTRL;                      /**< General Purpose Timer 1 Control, offset: 0x8C */
  __IO uint32_t SBUSCFG;                           /**< System Bus Config, offset: 0x90 */
       uint8_t RESERVED_1[108];
  __I  uint32_t CAPLENGTH;                         /**< Capability Registers Length and Host Controller Interface Version, offset: 0x100 */
  __I  uint32_t HCSPARAMS;                         /**< Host Controller Structural Parameters, offset: 0x104 */
  __I  uint32_t HCCPARAMS;                         /**< Host Controller Capability Parameters, offset: 0x108 */
       uint8_t RESERVED_2[20];
  __I  uint32_t DCIVERSION;                        /**< Device Controller Interface Version, offset: 0x120 */
  __I  uint32_t DCCPARAMS;                         /**< Device Controller Capability Parameters, offset: 0x124 */
  union {                                          /* offset: 0x128 */
    __IO uint32_t DEVLPMCSR;                         /**< Device Mode LPM Control and Status Register, offset: 0x128 */
    __IO uint32_t HSTLPMCSR;                         /**< Host Mode LPM Control and Status Register, offset: 0x128 */
  };
       uint8_t RESERVED_3[20];
  __IO uint32_t USBCMD;                            /**< USB Command, offset: 0x140 */
  __IO uint32_t USBSTS;                            /**< USB Status/Interrupt, offset: 0x144 */
  __IO uint32_t USBINTR;                           /**< USB Interrupt Enable, offset: 0x148 */
  __IO uint32_t FRINDEX;                           /**< USB Frame Index, offset: 0x14C */
       uint8_t RESERVED_4[4];
  union {                                          /* offset: 0x154 */
    __IO uint32_t DEVICEADDR;                        /**< Device Address, offset: 0x154 */
    __IO uint32_t PERIODICLISTBASE;                  /**< Periodic Frame List Base Address, offset: 0x154 */
  };
  union {                                          /* offset: 0x158 */
    __IO uint32_t ASYNCLISTADDR;                     /**< Next Asynch. Address, offset: 0x158 */
    __IO uint32_t ENDPOINTLISTADDR;                  /**< Endpoint List Address, offset: 0x158 */
  };
       uint8_t RESERVED_5[4];
  __IO uint32_t BURSTSIZE;                         /**< Programmable Burst Size, offset: 0x160 */
  __IO uint32_t TXFILLTUNING;                      /**< TX FIFO Fill Tuning, offset: 0x164 */
       uint8_t RESERVED_6[16];
  __IO uint32_t ENDPTNAK;                          /**< Endpoint NAK, offset: 0x178 */
  __IO uint32_t ENDPTNAKEN;                        /**< Endpoint NAK Interrupt Enable, offset: 0x17C */
       uint8_t RESERVED_7[4];
  __IO uint32_t PORTSC1;                           /**< Port Status and Control, offset: 0x184 */
       uint8_t RESERVED_8[28];
  __IO uint32_t OTGSC;                             /**< On-The-Go Status and Control, offset: 0x1A4 */
  __IO uint32_t USBMODE;                           /**< USB Mode Selection, offset: 0x1A8 */
  __IO uint32_t ENDPTSETUPSTAT;                    /**< Endpoint Setup Status, offset: 0x1AC */
  __IO uint32_t ENDPTPRIME;                        /**< Endpoint Prime, offset: 0x1B0 */
  __IO uint32_t ENDPTFLUSH;                        /**< Endpoint Flush, offset: 0x1B4 */
  __I  uint32_t ENDPTSTAT;                         /**< Endpoint Status, offset: 0x1B8 */
  __IO uint32_t ENDPTCOMPLETE;                     /**< Endpoint Complete, offset: 0x1BC */
  __IO uint32_t ENDPTCTRL0;                        /**< Endpoint Control 0, offset: 0x1C0 */
  __IO uint32_t ENDPTCTRL[USBC_ENDPTCTRL_COUNT];   /**< Endpoint Control 1..Endpoint Control 7, array offset: 0x1C4, array step: 0x4 */
       uint8_t RESERVED_9[32];
  __IO uint32_t PLL_CONTROL_0;                     /**< PLL Control 0, offset: 0x200 */
  __IO uint32_t PLL_CONTROL_1;                     /**< PLL Control 1, offset: 0x204 */
  __IO uint32_t CALIBRATION_CONTROL;               /**< Calibration Control, offset: 0x208 */
  __IO uint32_t TX_CHANNEL_CONTRL_0;               /**< Tx Channel Contrl 0, offset: 0x20C */
       uint8_t RESERVED_10[4];
  __IO uint32_t RX_CHANNEL_CONTRL_0;               /**< Rx Channel_Contrl 0, offset: 0x214 */
  __IO uint32_t RX_CHANNEL_CONTRL_1;               /**< Rx Channel Contrl 1, offset: 0x218 */
  __IO uint32_t DIGITAL_CONTRL_0;                  /**< Digital Contrl 0, offset: 0x21C */
  __IO uint32_t DIGITAL_CONTRL_1;                  /**< Digital Contrl 1, offset: 0x220 */
  __IO uint32_t TEST_CONTRL_AND_STATUS_0;          /**< Test Contrl and Status 0, offset: 0x224 */
  __IO uint32_t TEST_CONTRL_AND_STATUS_1;          /**< Test Contrl and Status 1, offset: 0x228 */
       uint8_t RESERVED_11[8];
  __IO uint32_t PHY_REG_OTG_CONTROL;               /**< OTG Control, offset: 0x234 */
  __IO uint32_t PHY_REG_CHGDTC_CONTRL_1;           /**< Charger Detector Control, offset: 0x238 */
} USBC_Type;

/* ----------------------------------------------------------------------------
   -- USBC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBC_Register_Masks USBC Register Masks
 * @{
 */

/*! @name ID - Identification */
/*! @{ */

#define USBC_ID_ID_MASK                          (0x3FU)
#define USBC_ID_ID_SHIFT                         (0U)
/*! ID - Configuration Number */
#define USBC_ID_ID(x)                            (((uint32_t)(((uint32_t)(x)) << USBC_ID_ID_SHIFT)) & USBC_ID_ID_MASK)

#define USBC_ID_NID_MASK                         (0x3F00U)
#define USBC_ID_NID_SHIFT                        (8U)
/*! NID - Complement Version of ID */
#define USBC_ID_NID(x)                           (((uint32_t)(((uint32_t)(x)) << USBC_ID_NID_SHIFT)) & USBC_ID_NID_MASK)

#define USBC_ID_TAG_MASK                         (0x1F0000U)
#define USBC_ID_TAG_SHIFT                        (16U)
/*! TAG - Identifies the tag of the core */
#define USBC_ID_TAG(x)                           (((uint32_t)(((uint32_t)(x)) << USBC_ID_TAG_SHIFT)) & USBC_ID_TAG_MASK)

#define USBC_ID_REVISION_MASK                    (0x1E00000U)
#define USBC_ID_REVISION_SHIFT                   (21U)
/*! REVISION - Revision number of the core */
#define USBC_ID_REVISION(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_ID_REVISION_SHIFT)) & USBC_ID_REVISION_MASK)

#define USBC_ID_VERSION_MASK                     (0x1E000000U)
#define USBC_ID_VERSION_SHIFT                    (25U)
/*! VERSION - Identifies the version of the core */
#define USBC_ID_VERSION(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_ID_VERSION_SHIFT)) & USBC_ID_VERSION_MASK)

#define USBC_ID_CIVERSION_MASK                   (0xE0000000U)
#define USBC_ID_CIVERSION_SHIFT                  (29U)
/*! CIVERSION - Identifies the CI version */
#define USBC_ID_CIVERSION(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_ID_CIVERSION_SHIFT)) & USBC_ID_CIVERSION_MASK)
/*! @} */

/*! @name HWGENERAL - General Hardware Parameters */
/*! @{ */

#define USBC_HWGENERAL_RT_MASK                   (0x1U)
#define USBC_HWGENERAL_RT_SHIFT                  (0U)
/*! RT - Reset type used in the core */
#define USBC_HWGENERAL_RT(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_HWGENERAL_RT_SHIFT)) & USBC_HWGENERAL_RT_MASK)

#define USBC_HWGENERAL_CLKC_MASK                 (0x6U)
#define USBC_HWGENERAL_CLKC_SHIFT                (1U)
/*! CLKC - Clocking scheme used in the core. */
#define USBC_HWGENERAL_CLKC(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HWGENERAL_CLKC_SHIFT)) & USBC_HWGENERAL_CLKC_MASK)

#define USBC_HWGENERAL_PHYW_MASK                 (0x30U)
#define USBC_HWGENERAL_PHYW_SHIFT                (4U)
/*! PHYW - Data width of the transciever connected to the controller core. */
#define USBC_HWGENERAL_PHYW(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HWGENERAL_PHYW_SHIFT)) & USBC_HWGENERAL_PHYW_MASK)

#define USBC_HWGENERAL_PHYM_MASK                 (0x3C0U)
#define USBC_HWGENERAL_PHYM_SHIFT                (6U)
/*! PHYM - Transceiver type */
#define USBC_HWGENERAL_PHYM(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HWGENERAL_PHYM_SHIFT)) & USBC_HWGENERAL_PHYM_MASK)

#define USBC_HWGENERAL_SM_MASK                   (0xC00U)
#define USBC_HWGENERAL_SM_SHIFT                  (10U)
/*! SM - Serial interface mode capability */
#define USBC_HWGENERAL_SM(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_HWGENERAL_SM_SHIFT)) & USBC_HWGENERAL_SM_MASK)
/*! @} */

/*! @name HWHOST - Host Hardware Parameters */
/*! @{ */

#define USBC_HWHOST_HC_MASK                      (0x1U)
#define USBC_HWHOST_HC_SHIFT                     (0U)
/*! HC - Host Capable */
#define USBC_HWHOST_HC(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_HWHOST_HC_SHIFT)) & USBC_HWHOST_HC_MASK)

#define USBC_HWHOST_NPORT_MASK                   (0xEU)
#define USBC_HWHOST_NPORT_SHIFT                  (1U)
/*! NPORT - The Number of downstream ports supported by the host controller. */
#define USBC_HWHOST_NPORT(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_HWHOST_NPORT_SHIFT)) & USBC_HWHOST_NPORT_MASK)
/*! @} */

/*! @name HWDEVICE - Device Hardware Parameters */
/*! @{ */

#define USBC_HWDEVICE_DC_MASK                    (0x1U)
#define USBC_HWDEVICE_DC_SHIFT                   (0U)
/*! DC - Device Capable */
#define USBC_HWDEVICE_DC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_HWDEVICE_DC_SHIFT)) & USBC_HWDEVICE_DC_MASK)

#define USBC_HWDEVICE_DEVEP_MASK                 (0x3EU)
#define USBC_HWDEVICE_DEVEP_SHIFT                (1U)
/*! DEVEP - Total Number of Device Endpoint */
#define USBC_HWDEVICE_DEVEP(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HWDEVICE_DEVEP_SHIFT)) & USBC_HWDEVICE_DEVEP_MASK)
/*! @} */

/*! @name HWTXBUF - TX Buffer Hardware Parameters */
/*! @{ */

#define USBC_HWTXBUF_TXBURST_MASK                (0xFFU)
#define USBC_HWTXBUF_TXBURST_SHIFT               (0U)
/*! TXBURST - Default burst size for memory to TX buffer transfer */
#define USBC_HWTXBUF_TXBURST(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_TXBURST_SHIFT)) & USBC_HWTXBUF_TXBURST_MASK)

#define USBC_HWTXBUF_TXADD_MASK                  (0xFF00U)
#define USBC_HWTXBUF_TXADD_SHIFT                 (8U)
/*! TXADD - Address Bits for Tx Buffer */
#define USBC_HWTXBUF_TXADD(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_TXADD_SHIFT)) & USBC_HWTXBUF_TXADD_MASK)

#define USBC_HWTXBUF_TXCHANADD_MASK              (0xFF0000U)
#define USBC_HWTXBUF_TXCHANADD_SHIFT             (16U)
/*! TXCHANADD - Address Bits for Tx Buffer Per Channel/Endpoint */
#define USBC_HWTXBUF_TXCHANADD(x)                (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_TXCHANADD_SHIFT)) & USBC_HWTXBUF_TXCHANADD_MASK)
/*! @} */

/*! @name HWRXBUF - RX Buffer Hardware Parameters */
/*! @{ */

#define USBC_HWRXBUF_RXBURST_MASK                (0xFFU)
#define USBC_HWRXBUF_RXBURST_SHIFT               (0U)
/*! RXBURST - Default burst size for memory to RX buffer transfer */
#define USBC_HWRXBUF_RXBURST(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_HWRXBUF_RXBURST_SHIFT)) & USBC_HWRXBUF_RXBURST_MASK)

#define USBC_HWRXBUF_RXADD_MASK                  (0xFF00U)
#define USBC_HWRXBUF_RXADD_SHIFT                 (8U)
/*! RXADD - Address Bits for Rx Buffer */
#define USBC_HWRXBUF_RXADD(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HWRXBUF_RXADD_SHIFT)) & USBC_HWRXBUF_RXADD_MASK)
/*! @} */

/*! @name HWTXBUF_CTRL0 - Tx Buffer Hardware Control 0 */
/*! @{ */

#define USBC_HWTXBUF_CTRL0_EP0_TXFIFO_SIZE_MASK  (0xFU)
#define USBC_HWTXBUF_CTRL0_EP0_TXFIFO_SIZE_SHIFT (0U)
/*! EP0_TXFIFO_SIZE - Endpoint 0 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP0_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP0_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP0_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP1_TXFIFO_SIZE_MASK  (0xF0U)
#define USBC_HWTXBUF_CTRL0_EP1_TXFIFO_SIZE_SHIFT (4U)
/*! EP1_TXFIFO_SIZE - Endpoint 1 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP1_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP1_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP1_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP2_TXFIFO_SIZE_MASK  (0xF00U)
#define USBC_HWTXBUF_CTRL0_EP2_TXFIFO_SIZE_SHIFT (8U)
/*! EP2_TXFIFO_SIZE - Endpoint 2 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP2_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP2_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP2_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP3_TXFIFO_SIZE_MASK  (0xF000U)
#define USBC_HWTXBUF_CTRL0_EP3_TXFIFO_SIZE_SHIFT (12U)
/*! EP3_TXFIFO_SIZE - Endpoint 3 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP3_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP3_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP3_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP4_TXFIFO_SIZE_MASK  (0xF0000U)
#define USBC_HWTXBUF_CTRL0_EP4_TXFIFO_SIZE_SHIFT (16U)
/*! EP4_TXFIFO_SIZE - Endpoint 4 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP4_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP4_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP4_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP5_TXFIFO_SIZE_MASK  (0xF00000U)
#define USBC_HWTXBUF_CTRL0_EP5_TXFIFO_SIZE_SHIFT (20U)
/*! EP5_TXFIFO_SIZE - Endpoint 5 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP5_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP5_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP5_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP6_TXFIFO_SIZE_MASK  (0xF000000U)
#define USBC_HWTXBUF_CTRL0_EP6_TXFIFO_SIZE_SHIFT (24U)
/*! EP6_TXFIFO_SIZE - Endpoint 6 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP6_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP6_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP6_TXFIFO_SIZE_MASK)

#define USBC_HWTXBUF_CTRL0_EP7_TXFIFO_SIZE_MASK  (0xF0000000U)
#define USBC_HWTXBUF_CTRL0_EP7_TXFIFO_SIZE_SHIFT (28U)
/*! EP7_TXFIFO_SIZE - Endpoint 7 TX FIFO Size */
#define USBC_HWTXBUF_CTRL0_EP7_TXFIFO_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << USBC_HWTXBUF_CTRL0_EP7_TXFIFO_SIZE_SHIFT)) & USBC_HWTXBUF_CTRL0_EP7_TXFIFO_SIZE_MASK)
/*! @} */

/*! @name GPTIMER0LD - General Purpose Timer 0 Load */
/*! @{ */

#define USBC_GPTIMER0LD_GPTLD_MASK               (0xFFFFFFU)
#define USBC_GPTIMER0LD_GPTLD_SHIFT              (0U)
/*! GPTLD - General Purpose Timer 0 Load Value */
#define USBC_GPTIMER0LD_GPTLD(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER0LD_GPTLD_SHIFT)) & USBC_GPTIMER0LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER0CTRL - General Purpose Timer 0 Control */
/*! @{ */

#define USBC_GPTIMER0CTRL_GPTCNT_MASK            (0xFFFFFFU)
#define USBC_GPTIMER0CTRL_GPTCNT_SHIFT           (0U)
/*! GPTCNT - General Purpose Timer Counter */
#define USBC_GPTIMER0CTRL_GPTCNT(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER0CTRL_GPTCNT_SHIFT)) & USBC_GPTIMER0CTRL_GPTCNT_MASK)

#define USBC_GPTIMER0CTRL_GPTMODE_MASK           (0x1000000U)
#define USBC_GPTIMER0CTRL_GPTMODE_SHIFT          (24U)
/*! GPTMODE - General Purpose Timer Mode */
#define USBC_GPTIMER0CTRL_GPTMODE(x)             (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER0CTRL_GPTMODE_SHIFT)) & USBC_GPTIMER0CTRL_GPTMODE_MASK)

#define USBC_GPTIMER0CTRL_GPTRST_MASK            (0x40000000U)
#define USBC_GPTIMER0CTRL_GPTRST_SHIFT           (30U)
/*! GPTRST - General Purpose Timer Reset */
#define USBC_GPTIMER0CTRL_GPTRST(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER0CTRL_GPTRST_SHIFT)) & USBC_GPTIMER0CTRL_GPTRST_MASK)

#define USBC_GPTIMER0CTRL_GPTRUN_MASK            (0x80000000U)
#define USBC_GPTIMER0CTRL_GPTRUN_SHIFT           (31U)
/*! GPTRUN - General Purpose Timer Run */
#define USBC_GPTIMER0CTRL_GPTRUN(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER0CTRL_GPTRUN_SHIFT)) & USBC_GPTIMER0CTRL_GPTRUN_MASK)
/*! @} */

/*! @name GPTIMER1LD - General Purpose Timer 1 Load */
/*! @{ */

#define USBC_GPTIMER1LD_GPTLD_MASK               (0xFFFFFFU)
#define USBC_GPTIMER1LD_GPTLD_SHIFT              (0U)
/*! GPTLD - General Purpose Timer 1 Load Value */
#define USBC_GPTIMER1LD_GPTLD(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER1LD_GPTLD_SHIFT)) & USBC_GPTIMER1LD_GPTLD_MASK)
/*! @} */

/*! @name GPTIMER1CTRL - General Purpose Timer 1 Control */
/*! @{ */

#define USBC_GPTIMER1CTRL_GPTCNT_MASK            (0xFFFFFFU)
#define USBC_GPTIMER1CTRL_GPTCNT_SHIFT           (0U)
/*! GPTCNT - General Purpose Timer Counter */
#define USBC_GPTIMER1CTRL_GPTCNT(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER1CTRL_GPTCNT_SHIFT)) & USBC_GPTIMER1CTRL_GPTCNT_MASK)

#define USBC_GPTIMER1CTRL_GPTMODE_MASK           (0x1000000U)
#define USBC_GPTIMER1CTRL_GPTMODE_SHIFT          (24U)
/*! GPTMODE - General Purpose Timer Mode */
#define USBC_GPTIMER1CTRL_GPTMODE(x)             (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER1CTRL_GPTMODE_SHIFT)) & USBC_GPTIMER1CTRL_GPTMODE_MASK)

#define USBC_GPTIMER1CTRL_GPTRST_MASK            (0x40000000U)
#define USBC_GPTIMER1CTRL_GPTRST_SHIFT           (30U)
/*! GPTRST - General Purpose Timer Reset */
#define USBC_GPTIMER1CTRL_GPTRST(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER1CTRL_GPTRST_SHIFT)) & USBC_GPTIMER1CTRL_GPTRST_MASK)

#define USBC_GPTIMER1CTRL_GPTRUN_MASK            (0x80000000U)
#define USBC_GPTIMER1CTRL_GPTRUN_SHIFT           (31U)
/*! GPTRUN - General Purpose Timer Run */
#define USBC_GPTIMER1CTRL_GPTRUN(x)              (((uint32_t)(((uint32_t)(x)) << USBC_GPTIMER1CTRL_GPTRUN_SHIFT)) & USBC_GPTIMER1CTRL_GPTRUN_MASK)
/*! @} */

/*! @name SBUSCFG - System Bus Config */
/*! @{ */

#define USBC_SBUSCFG_AHBBRST_MASK                (0x7U)
#define USBC_SBUSCFG_AHBBRST_SHIFT               (0U)
/*! AHBBRST - AHB master interface Burst configuration
 *  0b000..Incremental burst of unspecified length only
 *  0b001..INCR4 burst, then single transfer
 *  0b010..INCR8 burst, INCR4 burst, then single transfer
 *  0b011..INCR16 burst, INCR8 burst, INCR4 burst, then single transfer
 *  0b100..Reserved, don't use
 *  0b101..INCR4 burst, then incremental burst of unspecified length
 *  0b110..INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 *  0b111..INCR16 burst, INCR8 burst, INCR4 burst, then incremental burst of unspecified length
 */
#define USBC_SBUSCFG_AHBBRST(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_SBUSCFG_AHBBRST_SHIFT)) & USBC_SBUSCFG_AHBBRST_MASK)

#define USBC_SBUSCFG_BARD_MASK                   (0x38U)
#define USBC_SBUSCFG_BARD_SHIFT                  (3U)
/*! BARD - AMBA Burst Alignment for Reads */
#define USBC_SBUSCFG_BARD(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_SBUSCFG_BARD_SHIFT)) & USBC_SBUSCFG_BARD_MASK)

#define USBC_SBUSCFG_BAWR_MASK                   (0x1C0U)
#define USBC_SBUSCFG_BAWR_SHIFT                  (6U)
/*! BAWR - AMBA Burst Alignment for Writes
 *  0b000..Disable burst alignment
 *  0b001..Align bursts for packets larger than 512 bytes
 *  0b010..Align bursts for packets larger than 256 bytes
 *  0b011..Align bursts for packets larger than 128 bytes
 *  0b100..Align bursts for packets larger than 64 bytes
 *  0b101..Align bursts for packets larger than 32 bytes
 *  0b110..Align bursts for packets larger than 16 bytes
 *  0b111..Align bursts for all packets
 */
#define USBC_SBUSCFG_BAWR(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_SBUSCFG_BAWR_SHIFT)) & USBC_SBUSCFG_BAWR_MASK)
/*! @} */

/*! @name CAPLENGTH - Capability Registers Length and Host Controller Interface Version */
/*! @{ */

#define USBC_CAPLENGTH_CAPLENGTH_MASK            (0xFFU)
#define USBC_CAPLENGTH_CAPLENGTH_SHIFT           (0U)
/*! CAPLENGTH - Capability Registers Length */
#define USBC_CAPLENGTH_CAPLENGTH(x)              (((uint32_t)(((uint32_t)(x)) << USBC_CAPLENGTH_CAPLENGTH_SHIFT)) & USBC_CAPLENGTH_CAPLENGTH_MASK)

#define USBC_CAPLENGTH_HCIVERSION_MASK           (0xFFFF0000U)
#define USBC_CAPLENGTH_HCIVERSION_SHIFT          (16U)
/*! HCIVERSION - Host Controller Interface Version */
#define USBC_CAPLENGTH_HCIVERSION(x)             (((uint32_t)(((uint32_t)(x)) << USBC_CAPLENGTH_HCIVERSION_SHIFT)) & USBC_CAPLENGTH_HCIVERSION_MASK)
/*! @} */

/*! @name HCSPARAMS - Host Controller Structural Parameters */
/*! @{ */

#define USBC_HCSPARAMS_N_PORTS_MASK              (0xFU)
#define USBC_HCSPARAMS_N_PORTS_SHIFT             (0U)
/*! N_PORTS - Number of Downstream Ports */
#define USBC_HCSPARAMS_N_PORTS(x)                (((uint32_t)(((uint32_t)(x)) << USBC_HCSPARAMS_N_PORTS_SHIFT)) & USBC_HCSPARAMS_N_PORTS_MASK)

#define USBC_HCSPARAMS_PPC_MASK                  (0x10U)
#define USBC_HCSPARAMS_PPC_SHIFT                 (4U)
/*! PPC - Port Power Control */
#define USBC_HCSPARAMS_PPC(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HCSPARAMS_PPC_SHIFT)) & USBC_HCSPARAMS_PPC_MASK)

#define USBC_HCSPARAMS_N_CC_MASK                 (0xF000U)
#define USBC_HCSPARAMS_N_CC_SHIFT                (12U)
/*! N_CC - Number of Companion Controller */
#define USBC_HCSPARAMS_N_CC(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HCSPARAMS_N_CC_SHIFT)) & USBC_HCSPARAMS_N_CC_MASK)

#define USBC_HCSPARAMS_PI_MASK                   (0x10000U)
#define USBC_HCSPARAMS_PI_SHIFT                  (16U)
/*! PI - Port Indicators */
#define USBC_HCSPARAMS_PI(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_HCSPARAMS_PI_SHIFT)) & USBC_HCSPARAMS_PI_MASK)

#define USBC_HCSPARAMS_N_TT_MASK                 (0xF000000U)
#define USBC_HCSPARAMS_N_TT_SHIFT                (24U)
/*! N_TT - Number of Transaction Translators */
#define USBC_HCSPARAMS_N_TT(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_HCSPARAMS_N_TT_SHIFT)) & USBC_HCSPARAMS_N_TT_MASK)
/*! @} */

/*! @name HCCPARAMS - Host Controller Capability Parameters */
/*! @{ */

#define USBC_HCCPARAMS_ADC_MASK                  (0x1U)
#define USBC_HCCPARAMS_ADC_SHIFT                 (0U)
/*! ADC - 64-bit Addressing Capability */
#define USBC_HCCPARAMS_ADC(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HCCPARAMS_ADC_SHIFT)) & USBC_HCCPARAMS_ADC_MASK)

#define USBC_HCCPARAMS_PFL_MASK                  (0x2U)
#define USBC_HCCPARAMS_PFL_SHIFT                 (1U)
/*! PFL - Programmable Frame List Flag */
#define USBC_HCCPARAMS_PFL(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HCCPARAMS_PFL_SHIFT)) & USBC_HCCPARAMS_PFL_MASK)

#define USBC_HCCPARAMS_ASP_MASK                  (0x4U)
#define USBC_HCCPARAMS_ASP_SHIFT                 (2U)
/*! ASP - Asynchronous Schedule Park Capability */
#define USBC_HCCPARAMS_ASP(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_HCCPARAMS_ASP_SHIFT)) & USBC_HCCPARAMS_ASP_MASK)
/*! @} */

/*! @name DCIVERSION - Device Controller Interface Version */
/*! @{ */

#define USBC_DCIVERSION_DCIVERSION_MASK          (0xFFFFU)
#define USBC_DCIVERSION_DCIVERSION_SHIFT         (0U)
/*! DCIVERSION - Device Controller Interface Version Number */
#define USBC_DCIVERSION_DCIVERSION(x)            (((uint32_t)(((uint32_t)(x)) << USBC_DCIVERSION_DCIVERSION_SHIFT)) & USBC_DCIVERSION_DCIVERSION_MASK)
/*! @} */

/*! @name DCCPARAMS - Device Controller Capability Parameters */
/*! @{ */

#define USBC_DCCPARAMS_DEN_MASK                  (0x1FU)
#define USBC_DCCPARAMS_DEN_SHIFT                 (0U)
/*! DEN - Device Endpoint Number */
#define USBC_DCCPARAMS_DEN(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_DCCPARAMS_DEN_SHIFT)) & USBC_DCCPARAMS_DEN_MASK)

#define USBC_DCCPARAMS_DC_MASK                   (0x80U)
#define USBC_DCCPARAMS_DC_SHIFT                  (7U)
/*! DC - Device Capable */
#define USBC_DCCPARAMS_DC(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_DCCPARAMS_DC_SHIFT)) & USBC_DCCPARAMS_DC_MASK)

#define USBC_DCCPARAMS_HC_MASK                   (0x100U)
#define USBC_DCCPARAMS_HC_SHIFT                  (8U)
/*! HC - Host Capable */
#define USBC_DCCPARAMS_HC(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_DCCPARAMS_HC_SHIFT)) & USBC_DCCPARAMS_HC_MASK)

#define USBC_DCCPARAMS_LPM_EN_MASK               (0x80000000U)
#define USBC_DCCPARAMS_LPM_EN_SHIFT              (31U)
/*! LPM_EN - LPM Enhancement */
#define USBC_DCCPARAMS_LPM_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_DCCPARAMS_LPM_EN_SHIFT)) & USBC_DCCPARAMS_LPM_EN_MASK)
/*! @} */

/*! @name DEVLPMCSR - Device Mode LPM Control and Status Register */
/*! @{ */

#define USBC_DEVLPMCSR_INT_L1RSM_MASK            (0x1U)
#define USBC_DEVLPMCSR_INT_L1RSM_SHIFT           (0U)
/*! INT_L1RSM - L1 Resume Detected */
#define USBC_DEVLPMCSR_INT_L1RSM(x)              (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_INT_L1RSM_SHIFT)) & USBC_DEVLPMCSR_INT_L1RSM_MASK)

#define USBC_DEVLPMCSR_INT_LPMPKT_MASK           (0x2U)
#define USBC_DEVLPMCSR_INT_LPMPKT_SHIFT          (1U)
/*! INT_LPMPKT - LPM Packet Received */
#define USBC_DEVLPMCSR_INT_LPMPKT(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_INT_LPMPKT_SHIFT)) & USBC_DEVLPMCSR_INT_LPMPKT_MASK)

#define USBC_DEVLPMCSR_INT_LPMACK_MASK           (0x4U)
#define USBC_DEVLPMCSR_INT_LPMACK_SHIFT          (2U)
/*! INT_LPMACK - LPM Handshake Sent to Host */
#define USBC_DEVLPMCSR_INT_LPMACK(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_INT_LPMACK_SHIFT)) & USBC_DEVLPMCSR_INT_LPMACK_MASK)

#define USBC_DEVLPMCSR_INT_LPMERR_MASK           (0x8U)
#define USBC_DEVLPMCSR_INT_LPMERR_SHIFT          (3U)
/*! INT_LPMERR - LPM Error Detected */
#define USBC_DEVLPMCSR_INT_LPMERR(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_INT_LPMERR_SHIFT)) & USBC_DEVLPMCSR_INT_LPMERR_MASK)

#define USBC_DEVLPMCSR_IE_L1RSM_MASK             (0x10U)
#define USBC_DEVLPMCSR_IE_L1RSM_SHIFT            (4U)
/*! IE_L1RSM - Interrupt Enable for L1 Resume Detected Event */
#define USBC_DEVLPMCSR_IE_L1RSM(x)               (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_IE_L1RSM_SHIFT)) & USBC_DEVLPMCSR_IE_L1RSM_MASK)

#define USBC_DEVLPMCSR_IE_LPMPKT_MASK            (0x20U)
#define USBC_DEVLPMCSR_IE_LPMPKT_SHIFT           (5U)
/*! IE_LPMPKT - Interrupt Enable for LPM Packet Received Event */
#define USBC_DEVLPMCSR_IE_LPMPKT(x)              (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_IE_LPMPKT_SHIFT)) & USBC_DEVLPMCSR_IE_LPMPKT_MASK)

#define USBC_DEVLPMCSR_IE_LPMACK_MASK            (0x40U)
#define USBC_DEVLPMCSR_IE_LPMACK_SHIFT           (6U)
/*! IE_LPMACK - Interrupt Enable for LPM Handshake Sent to Host Event */
#define USBC_DEVLPMCSR_IE_LPMACK(x)              (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_IE_LPMACK_SHIFT)) & USBC_DEVLPMCSR_IE_LPMACK_MASK)

#define USBC_DEVLPMCSR_IE_LPMERR_MASK            (0x80U)
#define USBC_DEVLPMCSR_IE_LPMERR_SHIFT           (7U)
/*! IE_LPMERR - Interrupt Enable for LPM Error Detected Event */
#define USBC_DEVLPMCSR_IE_LPMERR(x)              (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_IE_LPMERR_SHIFT)) & USBC_DEVLPMCSR_IE_LPMERR_MASK)

#define USBC_DEVLPMCSR_RWAKE_EN_MASK             (0x100U)
#define USBC_DEVLPMCSR_RWAKE_EN_SHIFT            (8U)
/*! RWAKE_EN - Remote Wakeup Enable */
#define USBC_DEVLPMCSR_RWAKE_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_RWAKE_EN_SHIFT)) & USBC_DEVLPMCSR_RWAKE_EN_MASK)

#define USBC_DEVLPMCSR_L1STATE_MASK              (0x200U)
#define USBC_DEVLPMCSR_L1STATE_SHIFT             (9U)
/*! L1STATE - L1 Sleep Mode */
#define USBC_DEVLPMCSR_L1STATE(x)                (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_L1STATE_SHIFT)) & USBC_DEVLPMCSR_L1STATE_MASK)

#define USBC_DEVLPMCSR_IE_L1STATE_MASK           (0x400U)
#define USBC_DEVLPMCSR_IE_L1STATE_SHIFT          (10U)
/*! IE_L1STATE - Interrupt Enable for L1 Sleep Mode Event */
#define USBC_DEVLPMCSR_IE_L1STATE(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_IE_L1STATE_SHIFT)) & USBC_DEVLPMCSR_IE_L1STATE_MASK)

#define USBC_DEVLPMCSR_ACK_OK_MASK               (0x800U)
#define USBC_DEVLPMCSR_ACK_OK_SHIFT              (11U)
/*! ACK_OK - OK to Send ACK Handshake to LPM transaction */
#define USBC_DEVLPMCSR_ACK_OK(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_ACK_OK_SHIFT)) & USBC_DEVLPMCSR_ACK_OK_MASK)

#define USBC_DEVLPMCSR_STALL_OK_MASK             (0x1000U)
#define USBC_DEVLPMCSR_STALL_OK_SHIFT            (12U)
/*! STALL_OK - OK to Send STALL Handshake to LPM transaction */
#define USBC_DEVLPMCSR_STALL_OK(x)               (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_STALL_OK_SHIFT)) & USBC_DEVLPMCSR_STALL_OK_MASK)

#define USBC_DEVLPMCSR_MIN_SLP_EN_MASK           (0x2000U)
#define USBC_DEVLPMCSR_MIN_SLP_EN_SHIFT          (13U)
/*! MIN_SLP_EN - Minimum L1 Sleep Residency Time Enable */
#define USBC_DEVLPMCSR_MIN_SLP_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_MIN_SLP_EN_SHIFT)) & USBC_DEVLPMCSR_MIN_SLP_EN_MASK)

#define USBC_DEVLPMCSR_ALWAYS_LOG_MASK           (0x4000U)
#define USBC_DEVLPMCSR_ALWAYS_LOG_SHIFT          (14U)
/*! ALWAYS_LOG - Always Log LPM Packet Info */
#define USBC_DEVLPMCSR_ALWAYS_LOG(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_ALWAYS_LOG_SHIFT)) & USBC_DEVLPMCSR_ALWAYS_LOG_MASK)

#define USBC_DEVLPMCSR_LPM_ON_MASK               (0x8000U)
#define USBC_DEVLPMCSR_LPM_ON_SHIFT              (15U)
/*! LPM_ON - LPM Enable */
#define USBC_DEVLPMCSR_LPM_ON(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_LPM_ON_SHIFT)) & USBC_DEVLPMCSR_LPM_ON_MASK)

#define USBC_DEVLPMCSR_HST_RSM_EN_MASK           (0x10000U)
#define USBC_DEVLPMCSR_HST_RSM_EN_SHIFT          (16U)
/*! HST_RSM_EN - Host Resume Enable */
#define USBC_DEVLPMCSR_HST_RSM_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_HST_RSM_EN_SHIFT)) & USBC_DEVLPMCSR_HST_RSM_EN_MASK)

#define USBC_DEVLPMCSR_HIRD_MASK                 (0xF00000U)
#define USBC_DEVLPMCSR_HIRD_SHIFT                (20U)
/*! HIRD - Received HIRD */
#define USBC_DEVLPMCSR_HIRD(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_HIRD_SHIFT)) & USBC_DEVLPMCSR_HIRD_MASK)

#define USBC_DEVLPMCSR_LINKSTATE_MASK            (0xF000000U)
#define USBC_DEVLPMCSR_LINKSTATE_SHIFT           (24U)
/*! LINKSTATE - Received bLinkState in sub PID packet */
#define USBC_DEVLPMCSR_LINKSTATE(x)              (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_LINKSTATE_SHIFT)) & USBC_DEVLPMCSR_LINKSTATE_MASK)

#define USBC_DEVLPMCSR_BRMTWAKE_MASK             (0x10000000U)
#define USBC_DEVLPMCSR_BRMTWAKE_SHIFT            (28U)
/*! BRMTWAKE - Received bRemoteWake bit in sub PID packet */
#define USBC_DEVLPMCSR_BRMTWAKE(x)               (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_BRMTWAKE_SHIFT)) & USBC_DEVLPMCSR_BRMTWAKE_MASK)

#define USBC_DEVLPMCSR_LPM_PHCD_ONLY_MASK        (0x20000000U)
#define USBC_DEVLPMCSR_LPM_PHCD_ONLY_SHIFT       (29U)
/*! LPM_PHCD_ONLY - LPM PHY Clock Disble */
#define USBC_DEVLPMCSR_LPM_PHCD_ONLY(x)          (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_LPM_PHCD_ONLY_SHIFT)) & USBC_DEVLPMCSR_LPM_PHCD_ONLY_MASK)

#define USBC_DEVLPMCSR_LPM_RSP_MASK              (0xC0000000U)
#define USBC_DEVLPMCSR_LPM_RSP_SHIFT             (30U)
/*! LPM_RSP - LPM Response
 *  0b00..No handshake
 *  0b01..STALL
 *  0b10..NYET
 *  0b11..ACK
 */
#define USBC_DEVLPMCSR_LPM_RSP(x)                (((uint32_t)(((uint32_t)(x)) << USBC_DEVLPMCSR_LPM_RSP_SHIFT)) & USBC_DEVLPMCSR_LPM_RSP_MASK)
/*! @} */

/*! @name HSTLPMCSR - Host Mode LPM Control and Status Register */
/*! @{ */

#define USBC_HSTLPMCSR_LPM_ADDR_MASK             (0x7FU)
#define USBC_HSTLPMCSR_LPM_ADDR_SHIFT            (0U)
/*! LPM_ADDR - Device Address for LPM transaction */
#define USBC_HSTLPMCSR_LPM_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_ADDR_SHIFT)) & USBC_HSTLPMCSR_LPM_ADDR_MASK)

#define USBC_HSTLPMCSR_LPM_SUSP_EN_MASK          (0x80U)
#define USBC_HSTLPMCSR_LPM_SUSP_EN_SHIFT         (7U)
/*! LPM_SUSP_EN - LPM Suspend PHY Clock Disable */
#define USBC_HSTLPMCSR_LPM_SUSP_EN(x)            (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_SUSP_EN_SHIFT)) & USBC_HSTLPMCSR_LPM_SUSP_EN_MASK)

#define USBC_HSTLPMCSR_LPM_ENDP_MASK             (0xF00U)
#define USBC_HSTLPMCSR_LPM_ENDP_SHIFT            (8U)
/*! LPM_ENDP - Device Endpoint Number for LPM transaction */
#define USBC_HSTLPMCSR_LPM_ENDP(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_ENDP_SHIFT)) & USBC_HSTLPMCSR_LPM_ENDP_MASK)

#define USBC_HSTLPMCSR_LPM_FLAG_MASK             (0x3000U)
#define USBC_HSTLPMCSR_LPM_FLAG_SHIFT            (12U)
/*! LPM_FLAG - LPM Flag
 *  0b00..L0
 *  0b01..L1 suspend
 *  0b10..L2 resume/wakeup
 *  0b11..L1 resume/wakeup
 */
#define USBC_HSTLPMCSR_LPM_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_FLAG_SHIFT)) & USBC_HSTLPMCSR_LPM_FLAG_MASK)

#define USBC_HSTLPMCSR_LPM_INT_MASK              (0x4000U)
#define USBC_HSTLPMCSR_LPM_INT_SHIFT             (14U)
/*! LPM_INT - LPM Interrupt Status */
#define USBC_HSTLPMCSR_LPM_INT(x)                (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_INT_SHIFT)) & USBC_HSTLPMCSR_LPM_INT_MASK)

#define USBC_HSTLPMCSR_LPM_INT_EN_MASK           (0x8000U)
#define USBC_HSTLPMCSR_LPM_INT_EN_SHIFT          (15U)
/*! LPM_INT_EN - LPM Interrupt Enable */
#define USBC_HSTLPMCSR_LPM_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_INT_EN_SHIFT)) & USBC_HSTLPMCSR_LPM_INT_EN_MASK)

#define USBC_HSTLPMCSR_LPM_BESL_MASK             (0x10000U)
#define USBC_HSTLPMCSR_LPM_BESL_SHIFT            (16U)
/*! LPM_BESL - LPM Resume Time Table Select */
#define USBC_HSTLPMCSR_LPM_BESL(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_BESL_SHIFT)) & USBC_HSTLPMCSR_LPM_BESL_MASK)

#define USBC_HSTLPMCSR_LPM_RETRYCNT_MASK         (0xE0000U)
#define USBC_HSTLPMCSR_LPM_RETRYCNT_SHIFT        (17U)
/*! LPM_RETRYCNT - LPM Retry Count */
#define USBC_HSTLPMCSR_LPM_RETRYCNT(x)           (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_RETRYCNT_SHIFT)) & USBC_HSTLPMCSR_LPM_RETRYCNT_MASK)

#define USBC_HSTLPMCSR_LPM_HIRD_MASK             (0xF00000U)
#define USBC_HSTLPMCSR_LPM_HIRD_SHIFT            (20U)
/*! LPM_HIRD - LPM Host Initiated Resume Duration (BESL/HIRD) */
#define USBC_HSTLPMCSR_LPM_HIRD(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_HIRD_SHIFT)) & USBC_HSTLPMCSR_LPM_HIRD_MASK)

#define USBC_HSTLPMCSR_LPM_LINKSTATE_MASK        (0xF000000U)
#define USBC_HSTLPMCSR_LPM_LINKSTATE_SHIFT       (24U)
/*! LPM_LINKSTATE - bLinkState in LPM token */
#define USBC_HSTLPMCSR_LPM_LINKSTATE(x)          (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_LINKSTATE_SHIFT)) & USBC_HSTLPMCSR_LPM_LINKSTATE_MASK)

#define USBC_HSTLPMCSR_BRMTWAKE_MASK             (0x10000000U)
#define USBC_HSTLPMCSR_BRMTWAKE_SHIFT            (28U)
/*! BRMTWAKE - bRemoteWake in LPM token */
#define USBC_HSTLPMCSR_BRMTWAKE(x)               (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_BRMTWAKE_SHIFT)) & USBC_HSTLPMCSR_BRMTWAKE_MASK)

#define USBC_HSTLPMCSR_LPM_SNDLPM_MASK           (0x20000000U)
#define USBC_HSTLPMCSR_LPM_SNDLPM_SHIFT          (29U)
/*! LPM_SNDLPM - Send LPM to Device */
#define USBC_HSTLPMCSR_LPM_SNDLPM(x)             (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_SNDLPM_SHIFT)) & USBC_HSTLPMCSR_LPM_SNDLPM_MASK)

#define USBC_HSTLPMCSR_LPM_RSP_MASK              (0xC0000000U)
#define USBC_HSTLPMCSR_LPM_RSP_SHIFT             (30U)
/*! LPM_RSP - LPM Response Received from Device
 *  0b00..No handshake
 *  0b01..STALL
 *  0b10..NYET(NOT YET)
 *  0b11..ACK
 */
#define USBC_HSTLPMCSR_LPM_RSP(x)                (((uint32_t)(((uint32_t)(x)) << USBC_HSTLPMCSR_LPM_RSP_SHIFT)) & USBC_HSTLPMCSR_LPM_RSP_MASK)
/*! @} */

/*! @name USBCMD - USB Command */
/*! @{ */

#define USBC_USBCMD_RS_MASK                      (0x1U)
#define USBC_USBCMD_RS_SHIFT                     (0U)
/*! RS - Run/Stop
 *  0b0..Stop
 *  0b1..Run
 */
#define USBC_USBCMD_RS(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_RS_SHIFT)) & USBC_USBCMD_RS_MASK)

#define USBC_USBCMD_RST_MASK                     (0x2U)
#define USBC_USBCMD_RST_SHIFT                    (1U)
/*! RST - Controller Reset */
#define USBC_USBCMD_RST(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_RST_SHIFT)) & USBC_USBCMD_RST_MASK)

#define USBC_USBCMD_FS_1_MASK                    (0xCU)
#define USBC_USBCMD_FS_1_SHIFT                   (2U)
/*! FS_1 - Frame List Size */
#define USBC_USBCMD_FS_1(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_FS_1_SHIFT)) & USBC_USBCMD_FS_1_MASK)

#define USBC_USBCMD_PSE_MASK                     (0x10U)
#define USBC_USBCMD_PSE_SHIFT                    (4U)
/*! PSE - Periodic Schedule Enable */
#define USBC_USBCMD_PSE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_PSE_SHIFT)) & USBC_USBCMD_PSE_MASK)

#define USBC_USBCMD_ASE_MASK                     (0x20U)
#define USBC_USBCMD_ASE_SHIFT                    (5U)
/*! ASE - Asynchronous Schedule Enable */
#define USBC_USBCMD_ASE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_ASE_SHIFT)) & USBC_USBCMD_ASE_MASK)

#define USBC_USBCMD_IAA_MASK                     (0x40U)
#define USBC_USBCMD_IAA_SHIFT                    (6U)
/*! IAA - Interrupt on Async Advance Doorbell */
#define USBC_USBCMD_IAA(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_IAA_SHIFT)) & USBC_USBCMD_IAA_MASK)

#define USBC_USBCMD_ASP_MASK                     (0x300U)
#define USBC_USBCMD_ASP_SHIFT                    (8U)
/*! ASP - Asynchronous Schedule Park Mode Count */
#define USBC_USBCMD_ASP(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_ASP_SHIFT)) & USBC_USBCMD_ASP_MASK)

#define USBC_USBCMD_ASPE_MASK                    (0x800U)
#define USBC_USBCMD_ASPE_SHIFT                   (11U)
/*! ASPE - Asynchronous Schedule Park Mode Enable */
#define USBC_USBCMD_ASPE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_ASPE_SHIFT)) & USBC_USBCMD_ASPE_MASK)

#define USBC_USBCMD_SUTW_MASK                    (0x2000U)
#define USBC_USBCMD_SUTW_SHIFT                   (13U)
/*! SUTW - Setup TripWire */
#define USBC_USBCMD_SUTW(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_SUTW_SHIFT)) & USBC_USBCMD_SUTW_MASK)

#define USBC_USBCMD_ATDTW_MASK                   (0x4000U)
#define USBC_USBCMD_ATDTW_SHIFT                  (14U)
/*! ATDTW - Add dTD TripWire */
#define USBC_USBCMD_ATDTW(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_ATDTW_SHIFT)) & USBC_USBCMD_ATDTW_MASK)

#define USBC_USBCMD_FS_2_MASK                    (0x8000U)
#define USBC_USBCMD_FS_2_SHIFT                   (15U)
/*! FS_2 - Frame List Size */
#define USBC_USBCMD_FS_2(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_FS_2_SHIFT)) & USBC_USBCMD_FS_2_MASK)

#define USBC_USBCMD_ITC_MASK                     (0xFF0000U)
#define USBC_USBCMD_ITC_SHIFT                    (16U)
/*! ITC - Interrupt Threshold Control
 *  0b00000000..Immediate (no threshold)
 *  0b00000001..1 micro-frame
 *  0b00000010..2 micro-frames
 *  0b00000100..4 micro-frames
 *  0b00001000..8 micro-frames
 *  0b00010000..16 micro-frames
 *  0b00100000..32 micro-frames
 *  0b01000000..64 micro-frames
 */
#define USBC_USBCMD_ITC(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBCMD_ITC_SHIFT)) & USBC_USBCMD_ITC_MASK)
/*! @} */

/*! @name USBSTS - USB Status/Interrupt */
/*! @{ */

#define USBC_USBSTS_UI_MASK                      (0x1U)
#define USBC_USBSTS_UI_SHIFT                     (0U)
/*! UI - USB Interrupt (USBINT) */
#define USBC_USBSTS_UI(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_UI_SHIFT)) & USBC_USBSTS_UI_MASK)

#define USBC_USBSTS_UEI_MASK                     (0x2U)
#define USBC_USBSTS_UEI_SHIFT                    (1U)
/*! UEI - USB Error Interrupt (USBERRINT) */
#define USBC_USBSTS_UEI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_UEI_SHIFT)) & USBC_USBSTS_UEI_MASK)

#define USBC_USBSTS_PCI_MASK                     (0x4U)
#define USBC_USBSTS_PCI_SHIFT                    (2U)
/*! PCI - Port Change Detect */
#define USBC_USBSTS_PCI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_PCI_SHIFT)) & USBC_USBSTS_PCI_MASK)

#define USBC_USBSTS_FRI_MASK                     (0x8U)
#define USBC_USBSTS_FRI_SHIFT                    (3U)
/*! FRI - Frame List Rollover */
#define USBC_USBSTS_FRI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_FRI_SHIFT)) & USBC_USBSTS_FRI_MASK)

#define USBC_USBSTS_SEI_MASK                     (0x10U)
#define USBC_USBSTS_SEI_SHIFT                    (4U)
/*! SEI - System Error */
#define USBC_USBSTS_SEI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_SEI_SHIFT)) & USBC_USBSTS_SEI_MASK)

#define USBC_USBSTS_AAI_MASK                     (0x20U)
#define USBC_USBSTS_AAI_SHIFT                    (5U)
/*! AAI - Interrupt on Async Advance */
#define USBC_USBSTS_AAI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_AAI_SHIFT)) & USBC_USBSTS_AAI_MASK)

#define USBC_USBSTS_URI_MASK                     (0x40U)
#define USBC_USBSTS_URI_SHIFT                    (6U)
/*! URI - USB Reset Received */
#define USBC_USBSTS_URI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_URI_SHIFT)) & USBC_USBSTS_URI_MASK)

#define USBC_USBSTS_SRI_MASK                     (0x80U)
#define USBC_USBSTS_SRI_SHIFT                    (7U)
/*! SRI - SOF Received */
#define USBC_USBSTS_SRI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_SRI_SHIFT)) & USBC_USBSTS_SRI_MASK)

#define USBC_USBSTS_SLI_MASK                     (0x100U)
#define USBC_USBSTS_SLI_SHIFT                    (8U)
/*! SLI - Sleep Interrupt */
#define USBC_USBSTS_SLI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_SLI_SHIFT)) & USBC_USBSTS_SLI_MASK)

#define USBC_USBSTS_HCH_MASK                     (0x1000U)
#define USBC_USBSTS_HCH_SHIFT                    (12U)
/*! HCH - Host Controller Halted */
#define USBC_USBSTS_HCH(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_HCH_SHIFT)) & USBC_USBSTS_HCH_MASK)

#define USBC_USBSTS_RCL_MASK                     (0x2000U)
#define USBC_USBSTS_RCL_SHIFT                    (13U)
/*! RCL - Reclamation */
#define USBC_USBSTS_RCL(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_RCL_SHIFT)) & USBC_USBSTS_RCL_MASK)

#define USBC_USBSTS_PS_MASK                      (0x4000U)
#define USBC_USBSTS_PS_SHIFT                     (14U)
/*! PS - Periodic Schedule Status */
#define USBC_USBSTS_PS(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_PS_SHIFT)) & USBC_USBSTS_PS_MASK)

#define USBC_USBSTS_AS_MASK                      (0x8000U)
#define USBC_USBSTS_AS_SHIFT                     (15U)
/*! AS - Asynchronous Schedule Status */
#define USBC_USBSTS_AS(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_AS_SHIFT)) & USBC_USBSTS_AS_MASK)

#define USBC_USBSTS_NAKI_MASK                    (0x10000U)
#define USBC_USBSTS_NAKI_SHIFT                   (16U)
/*! NAKI - NAK Interrupt */
#define USBC_USBSTS_NAKI(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_NAKI_SHIFT)) & USBC_USBSTS_NAKI_MASK)

#define USBC_USBSTS_UAI_MASK                     (0x40000U)
#define USBC_USBSTS_UAI_SHIFT                    (18U)
/*! UAI - USB Host Asynchronous Interrupt (USBHSTASYNCINT) */
#define USBC_USBSTS_UAI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_UAI_SHIFT)) & USBC_USBSTS_UAI_MASK)

#define USBC_USBSTS_UPI_MASK                     (0x80000U)
#define USBC_USBSTS_UPI_SHIFT                    (19U)
/*! UPI - USB Host Periodic Interrupt (USBHSTPERINT) */
#define USBC_USBSTS_UPI(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_UPI_SHIFT)) & USBC_USBSTS_UPI_MASK)

#define USBC_USBSTS_TI0_MASK                     (0x1000000U)
#define USBC_USBSTS_TI0_SHIFT                    (24U)
/*! TI0 - General Purpose Timer Interrupt 0 (GPTINT0) */
#define USBC_USBSTS_TI0(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_TI0_SHIFT)) & USBC_USBSTS_TI0_MASK)

#define USBC_USBSTS_TI1_MASK                     (0x2000000U)
#define USBC_USBSTS_TI1_SHIFT                    (25U)
/*! TI1 - General Purpose Timer Interrupt 1 (GPTINT1) */
#define USBC_USBSTS_TI1(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBSTS_TI1_SHIFT)) & USBC_USBSTS_TI1_MASK)
/*! @} */

/*! @name USBINTR - USB Interrupt Enable */
/*! @{ */

#define USBC_USBINTR_UE_MASK                     (0x1U)
#define USBC_USBINTR_UE_SHIFT                    (0U)
/*! UE - USB Interrupt Enable */
#define USBC_USBINTR_UE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_UE_SHIFT)) & USBC_USBINTR_UE_MASK)

#define USBC_USBINTR_UEE_MASK                    (0x2U)
#define USBC_USBINTR_UEE_SHIFT                   (1U)
/*! UEE - USB Error Interrupt Enable */
#define USBC_USBINTR_UEE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_UEE_SHIFT)) & USBC_USBINTR_UEE_MASK)

#define USBC_USBINTR_PCE_MASK                    (0x4U)
#define USBC_USBINTR_PCE_SHIFT                   (2U)
/*! PCE - Port Change Detect Interrupt Enable */
#define USBC_USBINTR_PCE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_PCE_SHIFT)) & USBC_USBINTR_PCE_MASK)

#define USBC_USBINTR_FRE_MASK                    (0x8U)
#define USBC_USBINTR_FRE_SHIFT                   (3U)
/*! FRE - Frame List Rollover Interrupt Enable */
#define USBC_USBINTR_FRE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_FRE_SHIFT)) & USBC_USBINTR_FRE_MASK)

#define USBC_USBINTR_SEE_MASK                    (0x10U)
#define USBC_USBINTR_SEE_SHIFT                   (4U)
/*! SEE - System Error Interrupt Enable */
#define USBC_USBINTR_SEE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_SEE_SHIFT)) & USBC_USBINTR_SEE_MASK)

#define USBC_USBINTR_AAE_MASK                    (0x20U)
#define USBC_USBINTR_AAE_SHIFT                   (5U)
/*! AAE - Async Advance Interrupt Enable */
#define USBC_USBINTR_AAE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_AAE_SHIFT)) & USBC_USBINTR_AAE_MASK)

#define USBC_USBINTR_URE_MASK                    (0x40U)
#define USBC_USBINTR_URE_SHIFT                   (6U)
/*! URE - USB Reset Interrupt Enable */
#define USBC_USBINTR_URE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_URE_SHIFT)) & USBC_USBINTR_URE_MASK)

#define USBC_USBINTR_SRE_MASK                    (0x80U)
#define USBC_USBINTR_SRE_SHIFT                   (7U)
/*! SRE - SOF Received Interrupt Enable */
#define USBC_USBINTR_SRE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_SRE_SHIFT)) & USBC_USBINTR_SRE_MASK)

#define USBC_USBINTR_SLE_MASK                    (0x100U)
#define USBC_USBINTR_SLE_SHIFT                   (8U)
/*! SLE - Sleep Interrupt Enable */
#define USBC_USBINTR_SLE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_SLE_SHIFT)) & USBC_USBINTR_SLE_MASK)

#define USBC_USBINTR_NAKE_MASK                   (0x10000U)
#define USBC_USBINTR_NAKE_SHIFT                  (16U)
/*! NAKE - NAK Interrupt Enable */
#define USBC_USBINTR_NAKE(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_NAKE_SHIFT)) & USBC_USBINTR_NAKE_MASK)

#define USBC_USBINTR_UAIE_MASK                   (0x40000U)
#define USBC_USBINTR_UAIE_SHIFT                  (18U)
/*! UAIE - USB Host Asynchronous Interrupt Enable */
#define USBC_USBINTR_UAIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_UAIE_SHIFT)) & USBC_USBINTR_UAIE_MASK)

#define USBC_USBINTR_UPIE_MASK                   (0x80000U)
#define USBC_USBINTR_UPIE_SHIFT                  (19U)
/*! UPIE - USB Host Periodic Interrupt Enable */
#define USBC_USBINTR_UPIE(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_UPIE_SHIFT)) & USBC_USBINTR_UPIE_MASK)

#define USBC_USBINTR_TIE0_MASK                   (0x1000000U)
#define USBC_USBINTR_TIE0_SHIFT                  (24U)
/*! TIE0 - General Purpose Timer 0 Interrupt Enable */
#define USBC_USBINTR_TIE0(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_TIE0_SHIFT)) & USBC_USBINTR_TIE0_MASK)

#define USBC_USBINTR_TIE1_MASK                   (0x2000000U)
#define USBC_USBINTR_TIE1_SHIFT                  (25U)
/*! TIE1 - General Purpose Timer 1 Interrupt Enable */
#define USBC_USBINTR_TIE1(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBINTR_TIE1_SHIFT)) & USBC_USBINTR_TIE1_MASK)
/*! @} */

/*! @name FRINDEX - USB Frame Index */
/*! @{ */

#define USBC_FRINDEX_FRINDEX_MASK                (0x3FFFU)
#define USBC_FRINDEX_FRINDEX_SHIFT               (0U)
/*! FRINDEX - Frame Index */
#define USBC_FRINDEX_FRINDEX(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_FRINDEX_FRINDEX_SHIFT)) & USBC_FRINDEX_FRINDEX_MASK)
/*! @} */

/*! @name DEVICEADDR - Device Address */
/*! @{ */

#define USBC_DEVICEADDR_USBADRA_MASK             (0x1000000U)
#define USBC_DEVICEADDR_USBADRA_SHIFT            (24U)
/*! USBADRA - Device Address Advance */
#define USBC_DEVICEADDR_USBADRA(x)               (((uint32_t)(((uint32_t)(x)) << USBC_DEVICEADDR_USBADRA_SHIFT)) & USBC_DEVICEADDR_USBADRA_MASK)

#define USBC_DEVICEADDR_USBADR_MASK              (0xFE000000U)
#define USBC_DEVICEADDR_USBADR_SHIFT             (25U)
/*! USBADR - USB Device Address */
#define USBC_DEVICEADDR_USBADR(x)                (((uint32_t)(((uint32_t)(x)) << USBC_DEVICEADDR_USBADR_SHIFT)) & USBC_DEVICEADDR_USBADR_MASK)
/*! @} */

/*! @name PERIODICLISTBASE - Periodic Frame List Base Address */
/*! @{ */

#define USBC_PERIODICLISTBASE_PERBASE_MASK       (0xFFFFF000U)
#define USBC_PERIODICLISTBASE_PERBASE_SHIFT      (12U)
/*! PERBASE - Periodic Frame List Base Address */
#define USBC_PERIODICLISTBASE_PERBASE(x)         (((uint32_t)(((uint32_t)(x)) << USBC_PERIODICLISTBASE_PERBASE_SHIFT)) & USBC_PERIODICLISTBASE_PERBASE_MASK)
/*! @} */

/*! @name ASYNCLISTADDR - Next Asynch. Address */
/*! @{ */

#define USBC_ASYNCLISTADDR_ASYBASE_MASK          (0xFFFFFFE0U)
#define USBC_ASYNCLISTADDR_ASYBASE_SHIFT         (5U)
/*! ASYBASE - Asynchronous List Base Address */
#define USBC_ASYNCLISTADDR_ASYBASE(x)            (((uint32_t)(((uint32_t)(x)) << USBC_ASYNCLISTADDR_ASYBASE_SHIFT)) & USBC_ASYNCLISTADDR_ASYBASE_MASK)
/*! @} */

/*! @name ENDPOINTLISTADDR - Endpoint List Address */
/*! @{ */

#define USBC_ENDPOINTLISTADDR_EPBASE_MASK        (0xFFFFF800U)
#define USBC_ENDPOINTLISTADDR_EPBASE_SHIFT       (11U)
/*! EPBASE - Endpoint List Base Address */
#define USBC_ENDPOINTLISTADDR_EPBASE(x)          (((uint32_t)(((uint32_t)(x)) << USBC_ENDPOINTLISTADDR_EPBASE_SHIFT)) & USBC_ENDPOINTLISTADDR_EPBASE_MASK)
/*! @} */

/*! @name BURSTSIZE - Programmable Burst Size */
/*! @{ */

#define USBC_BURSTSIZE_RXPBURST_MASK             (0xFFU)
#define USBC_BURSTSIZE_RXPBURST_SHIFT            (0U)
/*! RXPBURST - Programmable RX Burst Size */
#define USBC_BURSTSIZE_RXPBURST(x)               (((uint32_t)(((uint32_t)(x)) << USBC_BURSTSIZE_RXPBURST_SHIFT)) & USBC_BURSTSIZE_RXPBURST_MASK)

#define USBC_BURSTSIZE_TXPBURST_MASK             (0xFF00U)
#define USBC_BURSTSIZE_TXPBURST_SHIFT            (8U)
/*! TXPBURST - Programmable TX Burst Size */
#define USBC_BURSTSIZE_TXPBURST(x)               (((uint32_t)(((uint32_t)(x)) << USBC_BURSTSIZE_TXPBURST_SHIFT)) & USBC_BURSTSIZE_TXPBURST_MASK)
/*! @} */

/*! @name TXFILLTUNING - TX FIFO Fill Tuning */
/*! @{ */

#define USBC_TXFILLTUNING_TXSCHOH_MASK           (0x7FU)
#define USBC_TXFILLTUNING_TXSCHOH_SHIFT          (0U)
/*! TXSCHOH - Scheduler Overhead */
#define USBC_TXFILLTUNING_TXSCHOH(x)             (((uint32_t)(((uint32_t)(x)) << USBC_TXFILLTUNING_TXSCHOH_SHIFT)) & USBC_TXFILLTUNING_TXSCHOH_MASK)

#define USBC_TXFILLTUNING_TXSCHHEALTH_MASK       (0x1F00U)
#define USBC_TXFILLTUNING_TXSCHHEALTH_SHIFT      (8U)
/*! TXSCHHEALTH - Scheduler Health Counter */
#define USBC_TXFILLTUNING_TXSCHHEALTH(x)         (((uint32_t)(((uint32_t)(x)) << USBC_TXFILLTUNING_TXSCHHEALTH_SHIFT)) & USBC_TXFILLTUNING_TXSCHHEALTH_MASK)

#define USBC_TXFILLTUNING_TXFIFOTHRES_MASK       (0x3F0000U)
#define USBC_TXFILLTUNING_TXFIFOTHRES_SHIFT      (16U)
/*! TXFIFOTHRES - FIFO Burst Threshold */
#define USBC_TXFILLTUNING_TXFIFOTHRES(x)         (((uint32_t)(((uint32_t)(x)) << USBC_TXFILLTUNING_TXFIFOTHRES_SHIFT)) & USBC_TXFILLTUNING_TXFIFOTHRES_MASK)
/*! @} */

/*! @name ENDPTNAK - Endpoint NAK */
/*! @{ */

#define USBC_ENDPTNAK_EPRN_MASK                  (0xFFU)
#define USBC_ENDPTNAK_EPRN_SHIFT                 (0U)
/*! EPRN - RX Endpoint NAK */
#define USBC_ENDPTNAK_EPRN(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTNAK_EPRN_SHIFT)) & USBC_ENDPTNAK_EPRN_MASK)

#define USBC_ENDPTNAK_EPTN_MASK                  (0xFF0000U)
#define USBC_ENDPTNAK_EPTN_SHIFT                 (16U)
/*! EPTN - TX Endpoint NAK */
#define USBC_ENDPTNAK_EPTN(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTNAK_EPTN_SHIFT)) & USBC_ENDPTNAK_EPTN_MASK)
/*! @} */

/*! @name ENDPTNAKEN - Endpoint NAK Interrupt Enable */
/*! @{ */

#define USBC_ENDPTNAKEN_EPRNE_MASK               (0xFFU)
#define USBC_ENDPTNAKEN_EPRNE_SHIFT              (0U)
/*! EPRNE - RX Endpoint NAK Interrupt Enable */
#define USBC_ENDPTNAKEN_EPRNE(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTNAKEN_EPRNE_SHIFT)) & USBC_ENDPTNAKEN_EPRNE_MASK)

#define USBC_ENDPTNAKEN_EPTNE_MASK               (0xFF0000U)
#define USBC_ENDPTNAKEN_EPTNE_SHIFT              (16U)
/*! EPTNE - TX Endpoint NAK Interrupt Enable */
#define USBC_ENDPTNAKEN_EPTNE(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTNAKEN_EPTNE_SHIFT)) & USBC_ENDPTNAKEN_EPTNE_MASK)
/*! @} */

/*! @name PORTSC1 - Port Status and Control */
/*! @{ */

#define USBC_PORTSC1_CCS_MASK                    (0x1U)
#define USBC_PORTSC1_CCS_SHIFT                   (0U)
/*! CCS - Current Connect Status */
#define USBC_PORTSC1_CCS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_CCS_SHIFT)) & USBC_PORTSC1_CCS_MASK)

#define USBC_PORTSC1_CSC_MASK                    (0x2U)
#define USBC_PORTSC1_CSC_SHIFT                   (1U)
/*! CSC - Connect Status Change */
#define USBC_PORTSC1_CSC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_CSC_SHIFT)) & USBC_PORTSC1_CSC_MASK)

#define USBC_PORTSC1_PE_MASK                     (0x4U)
#define USBC_PORTSC1_PE_SHIFT                    (2U)
/*! PE - Port Enabled/Disabled */
#define USBC_PORTSC1_PE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PE_SHIFT)) & USBC_PORTSC1_PE_MASK)

#define USBC_PORTSC1_PEC_MASK                    (0x8U)
#define USBC_PORTSC1_PEC_SHIFT                   (3U)
/*! PEC - Port Enable/Disable Change */
#define USBC_PORTSC1_PEC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PEC_SHIFT)) & USBC_PORTSC1_PEC_MASK)

#define USBC_PORTSC1_OCA_MASK                    (0x10U)
#define USBC_PORTSC1_OCA_SHIFT                   (4U)
/*! OCA - Over-Current Active */
#define USBC_PORTSC1_OCA(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_OCA_SHIFT)) & USBC_PORTSC1_OCA_MASK)

#define USBC_PORTSC1_OCC_MASK                    (0x20U)
#define USBC_PORTSC1_OCC_SHIFT                   (5U)
/*! OCC - Over-current Change */
#define USBC_PORTSC1_OCC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_OCC_SHIFT)) & USBC_PORTSC1_OCC_MASK)

#define USBC_PORTSC1_FPR_MASK                    (0x40U)
#define USBC_PORTSC1_FPR_SHIFT                   (6U)
/*! FPR - Force Port Resume */
#define USBC_PORTSC1_FPR(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_FPR_SHIFT)) & USBC_PORTSC1_FPR_MASK)

#define USBC_PORTSC1_SUSP_MASK                   (0x80U)
#define USBC_PORTSC1_SUSP_SHIFT                  (7U)
/*! SUSP - Suspend */
#define USBC_PORTSC1_SUSP(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_SUSP_SHIFT)) & USBC_PORTSC1_SUSP_MASK)

#define USBC_PORTSC1_PR_MASK                     (0x100U)
#define USBC_PORTSC1_PR_SHIFT                    (8U)
/*! PR - Port Reset */
#define USBC_PORTSC1_PR(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PR_SHIFT)) & USBC_PORTSC1_PR_MASK)

#define USBC_PORTSC1_HSP_MASK                    (0x200U)
#define USBC_PORTSC1_HSP_SHIFT                   (9U)
/*! HSP - High-Speed Port */
#define USBC_PORTSC1_HSP(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_HSP_SHIFT)) & USBC_PORTSC1_HSP_MASK)

#define USBC_PORTSC1_LS_MASK                     (0xC00U)
#define USBC_PORTSC1_LS_SHIFT                    (10U)
/*! LS - Line State
 *  0b00..SE0
 *  0b01..K-state
 *  0b10..J-state
 *  0b11..Undefined
 */
#define USBC_PORTSC1_LS(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_LS_SHIFT)) & USBC_PORTSC1_LS_MASK)

#define USBC_PORTSC1_PP_MASK                     (0x1000U)
#define USBC_PORTSC1_PP_SHIFT                    (12U)
/*! PP - Port Power */
#define USBC_PORTSC1_PP(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PP_SHIFT)) & USBC_PORTSC1_PP_MASK)

#define USBC_PORTSC1_PO_MASK                     (0x2000U)
#define USBC_PORTSC1_PO_SHIFT                    (13U)
/*! PO - Port Owner */
#define USBC_PORTSC1_PO(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PO_SHIFT)) & USBC_PORTSC1_PO_MASK)

#define USBC_PORTSC1_PIC_MASK                    (0xC000U)
#define USBC_PORTSC1_PIC_SHIFT                   (14U)
/*! PIC - Port Indicator Control
 *  0b00..Port indicators are off
 *  0b01..Amber
 *  0b10..Green
 *  0b11..Undefined
 */
#define USBC_PORTSC1_PIC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PIC_SHIFT)) & USBC_PORTSC1_PIC_MASK)

#define USBC_PORTSC1_PTC_MASK                    (0xF0000U)
#define USBC_PORTSC1_PTC_SHIFT                   (16U)
/*! PTC - Port Test Control
 *  0b0000..TEST_MODE_DISABLE
 *  0b0001..J_STATE
 *  0b0010..K_STATE
 *  0b0011..SE0 (host) / NAK (device)
 *  0b0100..Packet
 *  0b0101..FORCE_ENABLE_HS
 *  0b0110..FORCE_ENABLE_FS
 *  0b0111..FORCE_ENABLE_LS
 *  0b1000-0b1111..Reserved
 */
#define USBC_PORTSC1_PTC(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PTC_SHIFT)) & USBC_PORTSC1_PTC_MASK)

#define USBC_PORTSC1_WKCN_MASK                   (0x100000U)
#define USBC_PORTSC1_WKCN_SHIFT                  (20U)
/*! WKCN - Wake on Connect Enable (WKCNNT_E) */
#define USBC_PORTSC1_WKCN(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_WKCN_SHIFT)) & USBC_PORTSC1_WKCN_MASK)

#define USBC_PORTSC1_WKDS_MASK                   (0x200000U)
#define USBC_PORTSC1_WKDS_SHIFT                  (21U)
/*! WKDS - Wake on Disconnect Enable (WKDSCNNT_E) */
#define USBC_PORTSC1_WKDS(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_WKDS_SHIFT)) & USBC_PORTSC1_WKDS_MASK)

#define USBC_PORTSC1_WKOC_MASK                   (0x400000U)
#define USBC_PORTSC1_WKOC_SHIFT                  (22U)
/*! WKOC - Wake on Over-current Enable (WKOC_E) */
#define USBC_PORTSC1_WKOC(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_WKOC_SHIFT)) & USBC_PORTSC1_WKOC_MASK)

#define USBC_PORTSC1_PHCD_MASK                   (0x800000U)
#define USBC_PORTSC1_PHCD_SHIFT                  (23U)
/*! PHCD - PHY Low Power Suspend/Clock Disable (PLPSCD)
 *  0b0..Enable PHY clock
 *  0b1..Disable PHY clock
 */
#define USBC_PORTSC1_PHCD(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PHCD_SHIFT)) & USBC_PORTSC1_PHCD_MASK)

#define USBC_PORTSC1_PFSC_MASK                   (0x1000000U)
#define USBC_PORTSC1_PFSC_SHIFT                  (24U)
/*! PFSC - Port Force Full Speed Connect
 *  0b0..Normal operation
 *  0b1..Forced to full speed
 */
#define USBC_PORTSC1_PFSC(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PFSC_SHIFT)) & USBC_PORTSC1_PFSC_MASK)

#define USBC_PORTSC1_PTS2_MASK                   (0x2000000U)
#define USBC_PORTSC1_PTS2_SHIFT                  (25U)
/*! PTS2 - Parallel Transceiver Select Bit 2 */
#define USBC_PORTSC1_PTS2(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PTS2_SHIFT)) & USBC_PORTSC1_PTS2_MASK)

#define USBC_PORTSC1_PSPD_MASK                   (0xC000000U)
#define USBC_PORTSC1_PSPD_SHIFT                  (26U)
/*! PSPD - Port Speed
 *  0b00..Full Speed
 *  0b01..Low Speed
 *  0b10..High Speed
 *  0b11..Undefined
 */
#define USBC_PORTSC1_PSPD(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PSPD_SHIFT)) & USBC_PORTSC1_PSPD_MASK)

#define USBC_PORTSC1_PTW_MASK                    (0x10000000U)
#define USBC_PORTSC1_PTW_SHIFT                   (28U)
/*! PTW - Parallel Transceiver Width - Read/Write */
#define USBC_PORTSC1_PTW(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PTW_SHIFT)) & USBC_PORTSC1_PTW_MASK)

#define USBC_PORTSC1_PTS_MASK                    (0xC0000000U)
#define USBC_PORTSC1_PTS_SHIFT                   (30U)
/*! PTS - Parallel Transceiver Select */
#define USBC_PORTSC1_PTS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_PORTSC1_PTS_SHIFT)) & USBC_PORTSC1_PTS_MASK)
/*! @} */

/*! @name OTGSC - On-The-Go Status and Control */
/*! @{ */

#define USBC_OTGSC_VD_MASK                       (0x1U)
#define USBC_OTGSC_VD_SHIFT                      (0U)
/*! VD - VBUS Discharge */
#define USBC_OTGSC_VD(x)                         (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_VD_SHIFT)) & USBC_OTGSC_VD_MASK)

#define USBC_OTGSC_VC_MASK                       (0x2U)
#define USBC_OTGSC_VC_SHIFT                      (1U)
/*! VC - VBUS Charge */
#define USBC_OTGSC_VC(x)                         (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_VC_SHIFT)) & USBC_OTGSC_VC_MASK)

#define USBC_OTGSC_HAAR_MASK                     (0x4U)
#define USBC_OTGSC_HAAR_SHIFT                    (2U)
/*! HAAR - Hardware Assist Auto */
#define USBC_OTGSC_HAAR(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_HAAR_SHIFT)) & USBC_OTGSC_HAAR_MASK)

#define USBC_OTGSC_OT_MASK                       (0x8U)
#define USBC_OTGSC_OT_SHIFT                      (3U)
/*! OT - OTG Termination */
#define USBC_OTGSC_OT(x)                         (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_OT_SHIFT)) & USBC_OTGSC_OT_MASK)

#define USBC_OTGSC_DP_MASK                       (0x10U)
#define USBC_OTGSC_DP_SHIFT                      (4U)
/*! DP - Data Pulsing */
#define USBC_OTGSC_DP(x)                         (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_DP_SHIFT)) & USBC_OTGSC_DP_MASK)

#define USBC_OTGSC_IDPU_MASK                     (0x20U)
#define USBC_OTGSC_IDPU_SHIFT                    (5U)
/*! IDPU - ID Pullup
 *  0b0..Off
 *  0b1..On
 */
#define USBC_OTGSC_IDPU(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_IDPU_SHIFT)) & USBC_OTGSC_IDPU_MASK)

#define USBC_OTGSC_HADP_MASK                     (0x40U)
#define USBC_OTGSC_HADP_SHIFT                    (6U)
/*! HADP - Hardware Assist Data-Pulse */
#define USBC_OTGSC_HADP(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_HADP_SHIFT)) & USBC_OTGSC_HADP_MASK)

#define USBC_OTGSC_HABA_MASK                     (0x80U)
#define USBC_OTGSC_HABA_SHIFT                    (7U)
/*! HABA - Hardware Assist B-Disconnect to A-connect */
#define USBC_OTGSC_HABA(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_HABA_SHIFT)) & USBC_OTGSC_HABA_MASK)

#define USBC_OTGSC_ID_MASK                       (0x100U)
#define USBC_OTGSC_ID_SHIFT                      (8U)
/*! ID - USB ID */
#define USBC_OTGSC_ID(x)                         (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_ID_SHIFT)) & USBC_OTGSC_ID_MASK)

#define USBC_OTGSC_AVV_MASK                      (0x200U)
#define USBC_OTGSC_AVV_SHIFT                     (9U)
/*! AVV - A VBus Valid */
#define USBC_OTGSC_AVV(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_AVV_SHIFT)) & USBC_OTGSC_AVV_MASK)

#define USBC_OTGSC_ASV_MASK                      (0x400U)
#define USBC_OTGSC_ASV_SHIFT                     (10U)
/*! ASV - A Session Valid */
#define USBC_OTGSC_ASV(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_ASV_SHIFT)) & USBC_OTGSC_ASV_MASK)

#define USBC_OTGSC_BSV_MASK                      (0x800U)
#define USBC_OTGSC_BSV_SHIFT                     (11U)
/*! BSV - B Session Valid */
#define USBC_OTGSC_BSV(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSV_SHIFT)) & USBC_OTGSC_BSV_MASK)

#define USBC_OTGSC_BSE_MASK                      (0x1000U)
#define USBC_OTGSC_BSE_SHIFT                     (12U)
/*! BSE - B Session End */
#define USBC_OTGSC_BSE(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSE_SHIFT)) & USBC_OTGSC_BSE_MASK)

#define USBC_OTGSC_TOG_1MS_MASK                  (0x2000U)
#define USBC_OTGSC_TOG_1MS_SHIFT                 (13U)
/*! TOG_1MS - 1 Millisecond Timer Toggle */
#define USBC_OTGSC_TOG_1MS(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_TOG_1MS_SHIFT)) & USBC_OTGSC_TOG_1MS_MASK)

#define USBC_OTGSC_DPS_MASK                      (0x4000U)
#define USBC_OTGSC_DPS_SHIFT                     (14U)
/*! DPS - Data Bus Pulsing Status */
#define USBC_OTGSC_DPS(x)                        (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_DPS_SHIFT)) & USBC_OTGSC_DPS_MASK)

#define USBC_OTGSC_IDIS_MASK                     (0x10000U)
#define USBC_OTGSC_IDIS_SHIFT                    (16U)
/*! IDIS - USB ID Interrupt Status */
#define USBC_OTGSC_IDIS(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_IDIS_SHIFT)) & USBC_OTGSC_IDIS_MASK)

#define USBC_OTGSC_AVVIS_MASK                    (0x20000U)
#define USBC_OTGSC_AVVIS_SHIFT                   (17U)
/*! AVVIS - A VBus Valid Interrupt Status */
#define USBC_OTGSC_AVVIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_AVVIS_SHIFT)) & USBC_OTGSC_AVVIS_MASK)

#define USBC_OTGSC_ASVIS_MASK                    (0x40000U)
#define USBC_OTGSC_ASVIS_SHIFT                   (18U)
/*! ASVIS - A Session Valid Interrupt Status */
#define USBC_OTGSC_ASVIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_ASVIS_SHIFT)) & USBC_OTGSC_ASVIS_MASK)

#define USBC_OTGSC_BSVIS_MASK                    (0x80000U)
#define USBC_OTGSC_BSVIS_SHIFT                   (19U)
/*! BSVIS - B Session Valid Interrupt Status */
#define USBC_OTGSC_BSVIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSVIS_SHIFT)) & USBC_OTGSC_BSVIS_MASK)

#define USBC_OTGSC_BSEIS_MASK                    (0x100000U)
#define USBC_OTGSC_BSEIS_SHIFT                   (20U)
/*! BSEIS - B Session End Interrupt Status */
#define USBC_OTGSC_BSEIS(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSEIS_SHIFT)) & USBC_OTGSC_BSEIS_MASK)

#define USBC_OTGSC_STATUS_1MS_MASK               (0x200000U)
#define USBC_OTGSC_STATUS_1MS_SHIFT              (21U)
/*! STATUS_1MS - 1 Millisecond Timer Interrupt Status */
#define USBC_OTGSC_STATUS_1MS(x)                 (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_STATUS_1MS_SHIFT)) & USBC_OTGSC_STATUS_1MS_MASK)

#define USBC_OTGSC_DPIS_MASK                     (0x400000U)
#define USBC_OTGSC_DPIS_SHIFT                    (22U)
/*! DPIS - Data Pulse Interrupt Status */
#define USBC_OTGSC_DPIS(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_DPIS_SHIFT)) & USBC_OTGSC_DPIS_MASK)

#define USBC_OTGSC_IDIE_MASK                     (0x1000000U)
#define USBC_OTGSC_IDIE_SHIFT                    (24U)
/*! IDIE - USB ID Interrupt Enable */
#define USBC_OTGSC_IDIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_IDIE_SHIFT)) & USBC_OTGSC_IDIE_MASK)

#define USBC_OTGSC_AVVIE_MASK                    (0x2000000U)
#define USBC_OTGSC_AVVIE_SHIFT                   (25U)
/*! AVVIE - A VBus Valid Interrupt Enable */
#define USBC_OTGSC_AVVIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_AVVIE_SHIFT)) & USBC_OTGSC_AVVIE_MASK)

#define USBC_OTGSC_ASVIE_MASK                    (0x4000000U)
#define USBC_OTGSC_ASVIE_SHIFT                   (26U)
/*! ASVIE - A Session Valid Interrupt Enable */
#define USBC_OTGSC_ASVIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_ASVIE_SHIFT)) & USBC_OTGSC_ASVIE_MASK)

#define USBC_OTGSC_BSVIE_MASK                    (0x8000000U)
#define USBC_OTGSC_BSVIE_SHIFT                   (27U)
/*! BSVIE - B Session Valid Interrupt Enable */
#define USBC_OTGSC_BSVIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSVIE_SHIFT)) & USBC_OTGSC_BSVIE_MASK)

#define USBC_OTGSC_BSEIE_MASK                    (0x10000000U)
#define USBC_OTGSC_BSEIE_SHIFT                   (28U)
/*! BSEIE - B Session End Interrupt Enable */
#define USBC_OTGSC_BSEIE(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_BSEIE_SHIFT)) & USBC_OTGSC_BSEIE_MASK)

#define USBC_OTGSC_EN_1MS_MASK                   (0x20000000U)
#define USBC_OTGSC_EN_1MS_SHIFT                  (29U)
/*! EN_1MS - 1 Millisecond Timer Interrupt Enable */
#define USBC_OTGSC_EN_1MS(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_EN_1MS_SHIFT)) & USBC_OTGSC_EN_1MS_MASK)

#define USBC_OTGSC_DPIE_MASK                     (0x40000000U)
#define USBC_OTGSC_DPIE_SHIFT                    (30U)
/*! DPIE - Data Pulse Interrupt Enable */
#define USBC_OTGSC_DPIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_OTGSC_DPIE_SHIFT)) & USBC_OTGSC_DPIE_MASK)
/*! @} */

/*! @name USBMODE - USB Mode Selection */
/*! @{ */

#define USBC_USBMODE_CM_MASK                     (0x3U)
#define USBC_USBMODE_CM_SHIFT                    (0U)
/*! CM - Controller Mode
 *  0b00..Idle [Default for combination host/device]
 *  0b01..Reserved
 *  0b10..Device Controller [Default for device only controller]
 *  0b11..Host Controller [Default for host only controller]
 */
#define USBC_USBMODE_CM(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBMODE_CM_SHIFT)) & USBC_USBMODE_CM_MASK)

#define USBC_USBMODE_ES_MASK                     (0x4U)
#define USBC_USBMODE_ES_SHIFT                    (2U)
/*! ES - Endian Select
 *  0b0..Little Endian [Default]
 *  0b1..Big Endian
 */
#define USBC_USBMODE_ES(x)                       (((uint32_t)(((uint32_t)(x)) << USBC_USBMODE_ES_SHIFT)) & USBC_USBMODE_ES_MASK)

#define USBC_USBMODE_SLOM_MASK                   (0x8U)
#define USBC_USBMODE_SLOM_SHIFT                  (3U)
/*! SLOM - Setup Lockout Mode
 *  0b0..Setup Lockouts On (default).
 *  0b1..Setup Lockouts Off (DCD requires use of Setup Data Buffer Tripwire in USBCMD).
 */
#define USBC_USBMODE_SLOM(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBMODE_SLOM_SHIFT)) & USBC_USBMODE_SLOM_MASK)

#define USBC_USBMODE_SDIS_MASK                   (0x10U)
#define USBC_USBMODE_SDIS_SHIFT                  (4U)
/*! SDIS - Stream Disable Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define USBC_USBMODE_SDIS(x)                     (((uint32_t)(((uint32_t)(x)) << USBC_USBMODE_SDIS_SHIFT)) & USBC_USBMODE_SDIS_MASK)

#define USBC_USBMODE_ALP_MASK                    (0x10000U)
#define USBC_USBMODE_ALP_SHIFT                   (16U)
/*! ALP - Auto Low Power */
#define USBC_USBMODE_ALP(x)                      (((uint32_t)(((uint32_t)(x)) << USBC_USBMODE_ALP_SHIFT)) & USBC_USBMODE_ALP_MASK)
/*! @} */

/*! @name ENDPTSETUPSTAT - Endpoint Setup Status */
/*! @{ */

#define USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK  (0xFFU)
#define USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT (0U)
/*! ENDPTSETUPSTAT - Endpoint Setup Status */
#define USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT)) & USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK)
/*! @} */

/*! @name ENDPTPRIME - Endpoint Prime */
/*! @{ */

#define USBC_ENDPTPRIME_PERB_MASK                (0xFFU)
#define USBC_ENDPTPRIME_PERB_SHIFT               (0U)
/*! PERB - Prime Endpoint Receive Buffer */
#define USBC_ENDPTPRIME_PERB(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTPRIME_PERB_SHIFT)) & USBC_ENDPTPRIME_PERB_MASK)

#define USBC_ENDPTPRIME_PETB_MASK                (0xFF0000U)
#define USBC_ENDPTPRIME_PETB_SHIFT               (16U)
/*! PETB - Prime Endpoint Transmit Buffer */
#define USBC_ENDPTPRIME_PETB(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTPRIME_PETB_SHIFT)) & USBC_ENDPTPRIME_PETB_MASK)
/*! @} */

/*! @name ENDPTFLUSH - Endpoint Flush */
/*! @{ */

#define USBC_ENDPTFLUSH_FERB_MASK                (0xFFU)
#define USBC_ENDPTFLUSH_FERB_SHIFT               (0U)
/*! FERB - Flush Endpoint Receive Buffer */
#define USBC_ENDPTFLUSH_FERB(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTFLUSH_FERB_SHIFT)) & USBC_ENDPTFLUSH_FERB_MASK)

#define USBC_ENDPTFLUSH_FETB_MASK                (0xFF0000U)
#define USBC_ENDPTFLUSH_FETB_SHIFT               (16U)
/*! FETB - Flush Endpoint Transmit Buffer */
#define USBC_ENDPTFLUSH_FETB(x)                  (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTFLUSH_FETB_SHIFT)) & USBC_ENDPTFLUSH_FETB_MASK)
/*! @} */

/*! @name ENDPTSTAT - Endpoint Status */
/*! @{ */

#define USBC_ENDPTSTAT_ERBR_MASK                 (0xFFU)
#define USBC_ENDPTSTAT_ERBR_SHIFT                (0U)
/*! ERBR - Endpoint Receive Buffer Ready */
#define USBC_ENDPTSTAT_ERBR(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTSTAT_ERBR_SHIFT)) & USBC_ENDPTSTAT_ERBR_MASK)

#define USBC_ENDPTSTAT_ETBR_MASK                 (0xFF0000U)
#define USBC_ENDPTSTAT_ETBR_SHIFT                (16U)
/*! ETBR - Endpoint Transmit Buffer Ready */
#define USBC_ENDPTSTAT_ETBR(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTSTAT_ETBR_SHIFT)) & USBC_ENDPTSTAT_ETBR_MASK)
/*! @} */

/*! @name ENDPTCOMPLETE - Endpoint Complete */
/*! @{ */

#define USBC_ENDPTCOMPLETE_ERCE_MASK             (0xFFU)
#define USBC_ENDPTCOMPLETE_ERCE_SHIFT            (0U)
/*! ERCE - Endpoint Receive Complete Event */
#define USBC_ENDPTCOMPLETE_ERCE(x)               (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCOMPLETE_ERCE_SHIFT)) & USBC_ENDPTCOMPLETE_ERCE_MASK)

#define USBC_ENDPTCOMPLETE_ETCE_MASK             (0xFF0000U)
#define USBC_ENDPTCOMPLETE_ETCE_SHIFT            (16U)
/*! ETCE - Endpoint Transmit Complete Event */
#define USBC_ENDPTCOMPLETE_ETCE(x)               (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCOMPLETE_ETCE_SHIFT)) & USBC_ENDPTCOMPLETE_ETCE_MASK)
/*! @} */

/*! @name ENDPTCTRL0 - Endpoint Control 0 */
/*! @{ */

#define USBC_ENDPTCTRL0_RXS_MASK                 (0x1U)
#define USBC_ENDPTCTRL0_RXS_SHIFT                (0U)
/*! RXS - RX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBC_ENDPTCTRL0_RXS(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_RXS_SHIFT)) & USBC_ENDPTCTRL0_RXS_MASK)

#define USBC_ENDPTCTRL0_RXT_MASK                 (0xCU)
#define USBC_ENDPTCTRL0_RXT_SHIFT                (2U)
/*! RXT - RX Endpoint Type */
#define USBC_ENDPTCTRL0_RXT(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_RXT_SHIFT)) & USBC_ENDPTCTRL0_RXT_MASK)

#define USBC_ENDPTCTRL0_RXE_MASK                 (0x80U)
#define USBC_ENDPTCTRL0_RXE_SHIFT                (7U)
/*! RXE - RX Endpoint Enable */
#define USBC_ENDPTCTRL0_RXE(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_RXE_SHIFT)) & USBC_ENDPTCTRL0_RXE_MASK)

#define USBC_ENDPTCTRL0_TXS_MASK                 (0x10000U)
#define USBC_ENDPTCTRL0_TXS_SHIFT                (16U)
/*! TXS - TX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBC_ENDPTCTRL0_TXS(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_TXS_SHIFT)) & USBC_ENDPTCTRL0_TXS_MASK)

#define USBC_ENDPTCTRL0_TXT_MASK                 (0xC0000U)
#define USBC_ENDPTCTRL0_TXT_SHIFT                (18U)
/*! TXT - TX Endpoint Type */
#define USBC_ENDPTCTRL0_TXT(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_TXT_SHIFT)) & USBC_ENDPTCTRL0_TXT_MASK)

#define USBC_ENDPTCTRL0_TXE_MASK                 (0x800000U)
#define USBC_ENDPTCTRL0_TXE_SHIFT                (23U)
/*! TXE - TX Endpoint Enable */
#define USBC_ENDPTCTRL0_TXE(x)                   (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL0_TXE_SHIFT)) & USBC_ENDPTCTRL0_TXE_MASK)
/*! @} */

/*! @name ENDPTCTRL - Endpoint Control 1..Endpoint Control 7 */
/*! @{ */

#define USBC_ENDPTCTRL_RXS_MASK                  (0x1U)
#define USBC_ENDPTCTRL_RXS_SHIFT                 (0U)
/*! RXS - RX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBC_ENDPTCTRL_RXS(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXS_SHIFT)) & USBC_ENDPTCTRL_RXS_MASK)

#define USBC_ENDPTCTRL_RXD_MASK                  (0x2U)
#define USBC_ENDPTCTRL_RXD_SHIFT                 (1U)
/*! RXD - RX Endpoint Data Sink */
#define USBC_ENDPTCTRL_RXD(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXD_SHIFT)) & USBC_ENDPTCTRL_RXD_MASK)

#define USBC_ENDPTCTRL_RXT_MASK                  (0xCU)
#define USBC_ENDPTCTRL_RXT_SHIFT                 (2U)
/*! RXT - RX Endpoint Type
 *  0b00..Control
 *  0b01..Isochronous
 *  0b10..Bulk
 *  0b11..Interrupt
 */
#define USBC_ENDPTCTRL_RXT(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXT_SHIFT)) & USBC_ENDPTCTRL_RXT_MASK)

#define USBC_ENDPTCTRL_RXI_MASK                  (0x20U)
#define USBC_ENDPTCTRL_RXI_SHIFT                 (5U)
/*! RXI - RX Data Toggle Inhibit
 *  0b0..PID Sequencing Enabled
 *  0b1..PID Sequencing Disabled
 */
#define USBC_ENDPTCTRL_RXI(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXI_SHIFT)) & USBC_ENDPTCTRL_RXI_MASK)

#define USBC_ENDPTCTRL_RXR_MASK                  (0x40U)
#define USBC_ENDPTCTRL_RXR_SHIFT                 (6U)
/*! RXR - RX Data Toggle Reset (WS) */
#define USBC_ENDPTCTRL_RXR(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXR_SHIFT)) & USBC_ENDPTCTRL_RXR_MASK)

#define USBC_ENDPTCTRL_RXE_MASK                  (0x80U)
#define USBC_ENDPTCTRL_RXE_SHIFT                 (7U)
/*! RXE - RX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBC_ENDPTCTRL_RXE(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_RXE_SHIFT)) & USBC_ENDPTCTRL_RXE_MASK)

#define USBC_ENDPTCTRL_TXS_MASK                  (0x10000U)
#define USBC_ENDPTCTRL_TXS_SHIFT                 (16U)
/*! TXS - TX Endpoint Stall
 *  0b0..Endpoint OK
 *  0b1..Endpoint stalled
 */
#define USBC_ENDPTCTRL_TXS(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXS_SHIFT)) & USBC_ENDPTCTRL_TXS_MASK)

#define USBC_ENDPTCTRL_TXD_MASK                  (0x20000U)
#define USBC_ENDPTCTRL_TXD_SHIFT                 (17U)
/*! TXD - TX Endpoint Data Source */
#define USBC_ENDPTCTRL_TXD(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXD_SHIFT)) & USBC_ENDPTCTRL_TXD_MASK)

#define USBC_ENDPTCTRL_TXT_MASK                  (0xC0000U)
#define USBC_ENDPTCTRL_TXT_SHIFT                 (18U)
/*! TXT - TX Endpoint Type
 *  0b00..Control
 *  0b01..Isochronous
 *  0b10..Bulk
 *  0b11..Interrupt
 */
#define USBC_ENDPTCTRL_TXT(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXT_SHIFT)) & USBC_ENDPTCTRL_TXT_MASK)

#define USBC_ENDPTCTRL_TXI_MASK                  (0x200000U)
#define USBC_ENDPTCTRL_TXI_SHIFT                 (21U)
/*! TXI - TX Data Toggle Inhibit
 *  0b0..PID Sequencing Enabled
 *  0b1..PID Sequencing Disabled
 */
#define USBC_ENDPTCTRL_TXI(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXI_SHIFT)) & USBC_ENDPTCTRL_TXI_MASK)

#define USBC_ENDPTCTRL_TXR_MASK                  (0x400000U)
#define USBC_ENDPTCTRL_TXR_SHIFT                 (22U)
/*! TXR - TX Data Toggle Reset (WS) */
#define USBC_ENDPTCTRL_TXR(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXR_SHIFT)) & USBC_ENDPTCTRL_TXR_MASK)

#define USBC_ENDPTCTRL_TXE_MASK                  (0x800000U)
#define USBC_ENDPTCTRL_TXE_SHIFT                 (23U)
/*! TXE - TX Endpoint Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define USBC_ENDPTCTRL_TXE(x)                    (((uint32_t)(((uint32_t)(x)) << USBC_ENDPTCTRL_TXE_SHIFT)) & USBC_ENDPTCTRL_TXE_MASK)
/*! @} */

/*! @name PLL_CONTROL_0 - PLL Control 0 */
/*! @{ */

#define USBC_PLL_CONTROL_0_REFDIV_MASK           (0x7FU)
#define USBC_PLL_CONTROL_0_REFDIV_SHIFT          (0U)
/*! REFDIV - REFDIV */
#define USBC_PLL_CONTROL_0_REFDIV(x)             (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_REFDIV_SHIFT)) & USBC_PLL_CONTROL_0_REFDIV_MASK)

#define USBC_PLL_CONTROL_0_ICP_MASK              (0xF00U)
#define USBC_PLL_CONTROL_0_ICP_SHIFT             (8U)
/*! ICP - PLL Charge-Pump Current Select */
#define USBC_PLL_CONTROL_0_ICP(x)                (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_ICP_SHIFT)) & USBC_PLL_CONTROL_0_ICP_MASK)

#define USBC_PLL_CONTROL_0_VDDM_MASK             (0x3000U)
#define USBC_PLL_CONTROL_0_VDDM_SHIFT            (12U)
/*! VDDM - 1.8V Regulator Voltage Control */
#define USBC_PLL_CONTROL_0_VDDM(x)               (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_VDDM_SHIFT)) & USBC_PLL_CONTROL_0_VDDM_MASK)

#define USBC_PLL_CONTROL_0_VDDL_MASK             (0xC000U)
#define USBC_PLL_CONTROL_0_VDDL_SHIFT            (14U)
/*! VDDL - PLL 1.1V Regulator Output Voltage Control */
#define USBC_PLL_CONTROL_0_VDDL(x)               (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_VDDL_SHIFT)) & USBC_PLL_CONTROL_0_VDDL_MASK)

#define USBC_PLL_CONTROL_0_FBDIV_MASK            (0x1FF0000U)
#define USBC_PLL_CONTROL_0_FBDIV_SHIFT           (16U)
/*! FBDIV - Feedback Clock Divider Select */
#define USBC_PLL_CONTROL_0_FBDIV(x)              (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_FBDIV_SHIFT)) & USBC_PLL_CONTROL_0_FBDIV_MASK)

#define USBC_PLL_CONTROL_0_SEL_LPFR_MASK         (0x30000000U)
#define USBC_PLL_CONTROL_0_SEL_LPFR_SHIFT        (28U)
/*! SEL_LPFR - Select LPFR */
#define USBC_PLL_CONTROL_0_SEL_LPFR(x)           (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_SEL_LPFR_SHIFT)) & USBC_PLL_CONTROL_0_SEL_LPFR_MASK)

#define USBC_PLL_CONTROL_0_R_ROTATE_MASK         (0x40000000U)
#define USBC_PLL_CONTROL_0_R_ROTATE_SHIFT        (30U)
/*! R_ROTATE - Rotate Select */
#define USBC_PLL_CONTROL_0_R_ROTATE(x)           (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_R_ROTATE_SHIFT)) & USBC_PLL_CONTROL_0_R_ROTATE_MASK)

#define USBC_PLL_CONTROL_0_PLL_READY_MASK        (0x80000000U)
#define USBC_PLL_CONTROL_0_PLL_READY_SHIFT       (31U)
/*! PLL_READY - PLL Ready */
#define USBC_PLL_CONTROL_0_PLL_READY(x)          (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_0_PLL_READY_SHIFT)) & USBC_PLL_CONTROL_0_PLL_READY_MASK)
/*! @} */

/*! @name PLL_CONTROL_1 - PLL Control 1 */
/*! @{ */

#define USBC_PLL_CONTROL_1_PU_PLL_MASK           (0x1U)
#define USBC_PLL_CONTROL_1_PU_PLL_SHIFT          (0U)
/*! PU_PLL - PLL Power Up Control */
#define USBC_PLL_CONTROL_1_PU_PLL(x)             (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_1_PU_PLL_SHIFT)) & USBC_PLL_CONTROL_1_PU_PLL_MASK)

#define USBC_PLL_CONTROL_1_PU_PLL_BY_REG_MASK    (0x2U)
#define USBC_PLL_CONTROL_1_PU_PLL_BY_REG_SHIFT   (1U)
/*! PU_PLL_BY_REG - PLL Power Up Control Select */
#define USBC_PLL_CONTROL_1_PU_PLL_BY_REG(x)      (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_1_PU_PLL_BY_REG_SHIFT)) & USBC_PLL_CONTROL_1_PU_PLL_BY_REG_MASK)

#define USBC_PLL_CONTROL_1_PLL_RESET_MASK        (0x4U)
#define USBC_PLL_CONTROL_1_PLL_RESET_SHIFT       (2U)
/*! PLL_RESET - PLL Reset */
#define USBC_PLL_CONTROL_1_PLL_RESET(x)          (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_1_PLL_RESET_SHIFT)) & USBC_PLL_CONTROL_1_PLL_RESET_MASK)

#define USBC_PLL_CONTROL_1_PLL_SUSPEND_EN_MASK   (0x8U)
#define USBC_PLL_CONTROL_1_PLL_SUSPEND_EN_SHIFT  (3U)
/*! PLL_SUSPEND_EN - PLL Suspend Enable */
#define USBC_PLL_CONTROL_1_PLL_SUSPEND_EN(x)     (((uint32_t)(((uint32_t)(x)) << USBC_PLL_CONTROL_1_PLL_SUSPEND_EN_SHIFT)) & USBC_PLL_CONTROL_1_PLL_SUSPEND_EN_MASK)
/*! @} */

/*! @name CALIBRATION_CONTROL - Calibration Control */
/*! @{ */

#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP_MASK (0xFU)
#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP_SHIFT (0U)
/*! EXT_FS_IMP - FS driver Impedance register control
 *  0b0000..Impedance (SE) : 900/12 = 75 ohms
 *  0b0001..Impedance (SE) : 900/13 = 69 ohms
 *  0b0010..Impedance (SE) : 900/14 = 64 ohms
 *  0b0011..Impedance (SE) : 900/15 = 60 ohms
 *  0b0100..Impedance (SE) : 900/16 = 56 ohms
 *  0b0101..Impedance (SE) : 900/17 = 53 ohms
 *  0b0110..Impedance (SE) : 900/18 = 50 ohms
 *  0b0111..Impedance (SE) : 900/19 = 47 ohms
 *  0b1000..Impedance (SE) : 900/20 = 45 ohms
 *  0b1001..Impedance (SE) : 900/21 = 43 ohms
 *  0b1010..Impedance (SE) : 900/22 = 41 ohms
 *  0b1011..Impedance (SE) : 900/23 = 39 ohms
 *  0b1100..Impedance (SE) : 900/24 = 38 ohms
 *  0b1101..Impedance (SE) : 900/25 = 36 ohms
 *  0b1110..Impedance (SE) : 900/26 = 35 ohms
 *  0b1111..Impedance (SE) : 900/27 = 33 ohms
 */
#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP(x)   (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_EXT_FS_IMP_SHIFT)) & USBC_CALIBRATION_CONTROL_EXT_FS_IMP_MASK)

#define USBC_CALIBRATION_CONTROL_IMPCAL_VTH_MASK (0x700U)
#define USBC_CALIBRATION_CONTROL_IMPCAL_VTH_SHIFT (8U)
/*! IMPCAL_VTH - Impedance Calibration Threshold Setting
 *  0b000..Impedance : 900/16 = 56 ohms
 *  0b001..Impedance : 900/17 = 53 ohms
 *  0b010..Impedance : 900/18 = 50 ohms
 *  0b011..Impedance : 900/19 = 47 ohms
 *  0b100..Impedance : 900/20 = 45 ohms
 *  0b101..Impedance : 900/21 = 43 ohms
 *  0b110..Impedance : 900/22 = 41 ohms
 *  0b111..Impedance : 900/23 = 39 ohms
 */
#define USBC_CALIBRATION_CONTROL_IMPCAL_VTH(x)   (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_IMPCAL_VTH_SHIFT)) & USBC_CALIBRATION_CONTROL_IMPCAL_VTH_MASK)

#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP_EN_MASK (0x800U)
#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP_EN_SHIFT (11U)
/*! EXT_FS_IMP_EN - FS Impedance Control Selection */
#define USBC_CALIBRATION_CONTROL_EXT_FS_IMP_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_EXT_FS_IMP_EN_SHIFT)) & USBC_CALIBRATION_CONTROL_EXT_FS_IMP_EN_MASK)

#define USBC_CALIBRATION_CONTROL_IMPCAL_START_MASK (0x2000U)
#define USBC_CALIBRATION_CONTROL_IMPCAL_START_SHIFT (13U)
/*! IMPCAL_START - Impedance Calibration Start */
#define USBC_CALIBRATION_CONTROL_IMPCAL_START(x) (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_IMPCAL_START_SHIFT)) & USBC_CALIBRATION_CONTROL_IMPCAL_START_MASK)

#define USBC_CALIBRATION_CONTROL_IMPCAL_POL_MASK (0x4000U)
#define USBC_CALIBRATION_CONTROL_IMPCAL_POL_SHIFT (14U)
/*! IMPCAL_POL - Impedance Calibration Polarity
 *  0b0..Use up/down signal from analog part
 *  0b1..Invert up/down signal polarity
 */
#define USBC_CALIBRATION_CONTROL_IMPCAL_POL(x)   (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_IMPCAL_POL_SHIFT)) & USBC_CALIBRATION_CONTROL_IMPCAL_POL_MASK)

#define USBC_CALIBRATION_CONTROL_VCOCAL_POL_MASK (0x8000U)
#define USBC_CALIBRATION_CONTROL_VCOCAL_POL_SHIFT (15U)
/*! VCOCAL_POL - VCO Calibration Polarity
 *  0b0..Use up/down signal from analog part
 *  0b1..Invert up/down signal polarity
 */
#define USBC_CALIBRATION_CONTROL_VCOCAL_POL(x)   (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_VCOCAL_POL_SHIFT)) & USBC_CALIBRATION_CONTROL_VCOCAL_POL_MASK)

#define USBC_CALIBRATION_CONTROL_KVCO_MASK       (0x70000U)
#define USBC_CALIBRATION_CONTROL_KVCO_SHIFT      (16U)
/*! KVCO - PLL Kvco Register Control */
#define USBC_CALIBRATION_CONTROL_KVCO(x)         (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_KVCO_SHIFT)) & USBC_CALIBRATION_CONTROL_KVCO_MASK)

#define USBC_CALIBRATION_CONTROL_KVCO_EXT_MASK   (0x80000U)
#define USBC_CALIBRATION_CONTROL_KVCO_EXT_SHIFT  (19U)
/*! KVCO_EXT - PLL KVCO Control Selection */
#define USBC_CALIBRATION_CONTROL_KVCO_EXT(x)     (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_KVCO_EXT_SHIFT)) & USBC_CALIBRATION_CONTROL_KVCO_EXT_MASK)

#define USBC_CALIBRATION_CONTROL_PLLCAL_MASK     (0x300000U)
#define USBC_CALIBRATION_CONTROL_PLLCAL_SHIFT    (20U)
/*! PLLCAL - PLL VCO Calibration Voltage
 *  0b00..VDD
 *  0b01..1.0V
 *  0b10..1.05V
 *  0b11..1.1V
 */
#define USBC_CALIBRATION_CONTROL_PLLCAL(x)       (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_PLLCAL_SHIFT)) & USBC_CALIBRATION_CONTROL_PLLCAL_MASK)

#define USBC_CALIBRATION_CONTROL_PLLCAL_START_MASK (0x400000U)
#define USBC_CALIBRATION_CONTROL_PLLCAL_START_SHIFT (22U)
/*! PLLCAL_START - PLL Calibration Start */
#define USBC_CALIBRATION_CONTROL_PLLCAL_START(x) (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_PLLCAL_START_SHIFT)) & USBC_CALIBRATION_CONTROL_PLLCAL_START_MASK)

#define USBC_CALIBRATION_CONTROL_IMPCAL_DONE_MASK (0x800000U)
#define USBC_CALIBRATION_CONTROL_IMPCAL_DONE_SHIFT (23U)
/*! IMPCAL_DONE - Impedance Calibration Done */
#define USBC_CALIBRATION_CONTROL_IMPCAL_DONE(x)  (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_IMPCAL_DONE_SHIFT)) & USBC_CALIBRATION_CONTROL_IMPCAL_DONE_MASK)

#define USBC_CALIBRATION_CONTROL_CURRENT_IMP_MASK (0xF000000U)
#define USBC_CALIBRATION_CONTROL_CURRENT_IMP_SHIFT (24U)
/*! CURRENT_IMP - Current Impedance */
#define USBC_CALIBRATION_CONTROL_CURRENT_IMP(x)  (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_CURRENT_IMP_SHIFT)) & USBC_CALIBRATION_CONTROL_CURRENT_IMP_MASK)

#define USBC_CALIBRATION_CONTROL_CURRENT_KVCO_MASK (0x70000000U)
#define USBC_CALIBRATION_CONTROL_CURRENT_KVCO_SHIFT (28U)
/*! CURRENT_KVCO - Current Kvco */
#define USBC_CALIBRATION_CONTROL_CURRENT_KVCO(x) (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_CURRENT_KVCO_SHIFT)) & USBC_CALIBRATION_CONTROL_CURRENT_KVCO_MASK)

#define USBC_CALIBRATION_CONTROL_PLLCAL_DONE_MASK (0x80000000U)
#define USBC_CALIBRATION_CONTROL_PLLCAL_DONE_SHIFT (31U)
/*! PLLCAL_DONE - PLL Calibration Done */
#define USBC_CALIBRATION_CONTROL_PLLCAL_DONE(x)  (((uint32_t)(((uint32_t)(x)) << USBC_CALIBRATION_CONTROL_PLLCAL_DONE_SHIFT)) & USBC_CALIBRATION_CONTROL_PLLCAL_DONE_MASK)
/*! @} */

/*! @name TX_CHANNEL_CONTRL_0 - Tx Channel Contrl 0 */
/*! @{ */

#define USBC_TX_CHANNEL_CONTRL_0_HSDRV_EN_MASK   (0xFU)
#define USBC_TX_CHANNEL_CONTRL_0_HSDRV_EN_SHIFT  (0U)
/*! HSDRV_EN - HS Driver Enable */
#define USBC_TX_CHANNEL_CONTRL_0_HSDRV_EN(x)     (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_HSDRV_EN_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_HSDRV_EN_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_HS_SR_SEL_MASK  (0x30U)
#define USBC_TX_CHANNEL_CONTRL_0_HS_SR_SEL_SHIFT (4U)
/*! HS_SR_SEL - HS Transmitter Slew Rate Select */
#define USBC_TX_CHANNEL_CONTRL_0_HS_SR_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_HS_SR_SEL_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_HS_SR_SEL_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_LOWVDD_EN_MASK  (0x40U)
#define USBC_TX_CHANNEL_CONTRL_0_LOWVDD_EN_SHIFT (6U)
/*! LOWVDD_EN - Low Regulator Voltage Enable */
#define USBC_TX_CHANNEL_CONTRL_0_LOWVDD_EN(x)    (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_LOWVDD_EN_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_LOWVDD_EN_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_FSDRV_EN_MASK   (0x700U)
#define USBC_TX_CHANNEL_CONTRL_0_FSDRV_EN_SHIFT  (8U)
/*! FSDRV_EN - FS Driver Enable */
#define USBC_TX_CHANNEL_CONTRL_0_FSDRV_EN(x)     (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_FSDRV_EN_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_FSDRV_EN_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_DRV_EN_LS_MASK  (0x7000U)
#define USBC_TX_CHANNEL_CONTRL_0_DRV_EN_LS_SHIFT (12U)
/*! DRV_EN_LS - LS TX Driver Strength Coarse Control */
#define USBC_TX_CHANNEL_CONTRL_0_DRV_EN_LS(x)    (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_DRV_EN_LS_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_DRV_EN_LS_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_IMP_SEL_LS_MASK (0xF0000U)
#define USBC_TX_CHANNEL_CONTRL_0_IMP_SEL_LS_SHIFT (16U)
/*! IMP_SEL_LS - LS TX Driver Fine Adjustment */
#define USBC_TX_CHANNEL_CONTRL_0_IMP_SEL_LS(x)   (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_IMP_SEL_LS_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_IMP_SEL_LS_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_AMP_MASK        (0x700000U)
#define USBC_TX_CHANNEL_CONTRL_0_AMP_SHIFT       (20U)
/*! AMP - Tx Output Driver Amplitude Control */
#define USBC_TX_CHANNEL_CONTRL_0_AMP(x)          (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_AMP_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_AMP_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_PU_VDDR18_MASK  (0x800000U)
#define USBC_TX_CHANNEL_CONTRL_0_PU_VDDR18_SHIFT (23U)
/*! PU_VDDR18 - Power Up VDDR18 */
#define USBC_TX_CHANNEL_CONTRL_0_PU_VDDR18(x)    (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_PU_VDDR18_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_PU_VDDR18_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_PU_ANA_MASK     (0x1000000U)
#define USBC_TX_CHANNEL_CONTRL_0_PU_ANA_SHIFT    (24U)
/*! PU_ANA - Transceiver Channel Power Control */
#define USBC_TX_CHANNEL_CONTRL_0_PU_ANA(x)       (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_PU_ANA_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_PU_ANA_MASK)

#define USBC_TX_CHANNEL_CONTRL_0_PU_BY_REG_MASK  (0x2000000U)
#define USBC_TX_CHANNEL_CONTRL_0_PU_BY_REG_SHIFT (25U)
/*! PU_BY_REG - Transceiver Channel Power Control Select */
#define USBC_TX_CHANNEL_CONTRL_0_PU_BY_REG(x)    (((uint32_t)(((uint32_t)(x)) << USBC_TX_CHANNEL_CONTRL_0_PU_BY_REG_SHIFT)) & USBC_TX_CHANNEL_CONTRL_0_PU_BY_REG_MASK)
/*! @} */

/*! @name RX_CHANNEL_CONTRL_0 - Rx Channel_Contrl 0 */
/*! @{ */

#define USBC_RX_CHANNEL_CONTRL_0_SQ_THRESH_MASK  (0xFU)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_THRESH_SHIFT (0U)
/*! SQ_THRESH - Legacy Squelch and Un-squelch Threshold Select */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_THRESH(x)    (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_THRESH_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_THRESH_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_RXVDD18_MASK    (0x30U)
#define USBC_RX_CHANNEL_CONTRL_0_RXVDD18_SHIFT   (4U)
/*! RXVDD18 - 1.8V regulator voltage control */
#define USBC_RX_CHANNEL_CONTRL_0_RXVDD18(x)      (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_RXVDD18_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_RXVDD18_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_RXVDDL_MASK     (0xC0U)
#define USBC_RX_CHANNEL_CONTRL_0_RXVDDL_SHIFT    (6U)
/*! RXVDDL - Rx Regulator Output Voltage Control */
#define USBC_RX_CHANNEL_CONTRL_0_RXVDDL(x)       (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_RXVDDL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_RXVDDL_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_DISCON_THRESH_MASK (0x300U)
#define USBC_RX_CHANNEL_CONTRL_0_DISCON_THRESH_SHIFT (8U)
/*! DISCON_THRESH - Host Disconnect Detector Threshold Select */
#define USBC_RX_CHANNEL_CONTRL_0_DISCON_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_DISCON_THRESH_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_DISCON_THRESH_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_LINESTATE_EN_MASK (0x400U)
#define USBC_RX_CHANNEL_CONTRL_0_LINESTATE_EN_SHIFT (10U)
/*! LINESTATE_EN - Linestate Enable */
#define USBC_RX_CHANNEL_CONTRL_0_LINESTATE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_LINESTATE_EN_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_LINESTATE_EN_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_DLY_SEL_MASK (0x3000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_DLY_SEL_SHIFT (12U)
/*! SQ_DLY_SEL - SQ delay select */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_DLY_SEL(x)   (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_DLY_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_DLY_SEL_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_CM_SEL_MASK  (0x4000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_CM_SEL_SHIFT (14U)
/*! SQ_CM_SEL - Squelch and Non-Squelch Threshold Common Mode Voltage */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_CM_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_CM_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_CM_SEL_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_DET_EN_MASK  (0x8000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_DET_EN_SHIFT (15U)
/*! SQ_DET_EN - Legacy Squelch Detection Enable */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_DET_EN(x)    (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_DET_EN_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_DET_EN_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_VHL_SEL_MASK (0x10000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_VHL_SEL_SHIFT (16U)
/*! SQ_VHL_SEL - SQ Threshold Select */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_VHL_SEL(x)   (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_VHL_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_VHL_SEL_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_EN_MASK (0x1000000U)
#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_EN_SHIFT (24U)
/*! RESET_EXT_EN - Reset Signal Select */
#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_EN_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_EN_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_MASK  (0x2000000U)
#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_SHIFT (25U)
/*! RESET_EXT - Register-controlled reset signal for receiver analog circuit */
#define USBC_RX_CHANNEL_CONTRL_0_RESET_EXT(x)    (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_RESET_EXT_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_VREF_MASK (0xC000000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_VREF_SHIFT (26U)
/*! SQ_ANA_VREF - Analog Squelch Detect Reference Voltage */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_VREF(x)  (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_VREF_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_VREF_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_DTC_SEL_MASK (0x10000000U)
#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_DTC_SEL_SHIFT (28U)
/*! SQ_ANA_DTC_SEL - Analog Squelch Detect Enable */
#define USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_DTC_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_DTC_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_SQ_ANA_DTC_SEL_MASK)

#define USBC_RX_CHANNEL_CONTRL_0_CHIRPMODE_SEL_MASK (0x20000000U)
#define USBC_RX_CHANNEL_CONTRL_0_CHIRPMODE_SEL_SHIFT (29U)
/*! CHIRPMODE_SEL - Chirp Mode Select */
#define USBC_RX_CHANNEL_CONTRL_0_CHIRPMODE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_0_CHIRPMODE_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_0_CHIRPMODE_SEL_MASK)
/*! @} */

/*! @name RX_CHANNEL_CONTRL_1 - Rx Channel Contrl 1 */
/*! @{ */

#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_MASK (0x7U)
#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_SHIFT (0U)
/*! EXT_SQ_AMP_CAL - Squelch Threshold Register Control */
#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_MASK)

#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_EN_MASK (0x8U)
#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_EN_SHIFT (3U)
/*! EXT_SQ_AMP_CAL_EN - Analog Squelch Threshold Control Selection */
#define USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_EN_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_EXT_SQ_AMP_CAL_EN_MASK)

#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_START_MASK (0x10U)
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_START_SHIFT (4U)
/*! REG_SQCAL_START - Squelch Calibration Start */
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_START(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_START_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_START_MASK)

#define USBC_RX_CHANNEL_CONTRL_1_REG_SQ_UD_SWAP_MASK (0x20U)
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQ_UD_SWAP_SHIFT (5U)
/*! REG_SQ_UD_SWAP - Squelch Calibration Up/Down Swap */
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQ_UD_SWAP(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_REG_SQ_UD_SWAP_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_REG_SQ_UD_SWAP_MASK)

#define USBC_RX_CHANNEL_CONTRL_1_SQ_DPDM_AMP_SEL_MASK (0xC0U)
#define USBC_RX_CHANNEL_CONTRL_1_SQ_DPDM_AMP_SEL_SHIFT (6U)
/*! SQ_DPDM_AMP_SEL - Analog Squelch Calibration Threshold Select */
#define USBC_RX_CHANNEL_CONTRL_1_SQ_DPDM_AMP_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_SQ_DPDM_AMP_SEL_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_SQ_DPDM_AMP_SEL_MASK)

#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_DONE_MASK (0x80000000U)
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_DONE_SHIFT (31U)
/*! REG_SQCAL_DONE - Analog Squelch Threshold Calibration Done */
#define USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_DONE(x) (((uint32_t)(((uint32_t)(x)) << USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_DONE_SHIFT)) & USBC_RX_CHANNEL_CONTRL_1_REG_SQCAL_DONE_MASK)
/*! @} */

/*! @name DIGITAL_CONTRL_0 - Digital Contrl 0 */
/*! @{ */

#define USBC_DIGITAL_CONTRL_0_SYNC_NUM_MASK      (0x3U)
#define USBC_DIGITAL_CONTRL_0_SYNC_NUM_SHIFT     (0U)
/*! SYNC_NUM - Minimum SYNC Detect Number of Bits */
#define USBC_DIGITAL_CONTRL_0_SYNC_NUM(x)        (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SYNC_NUM_SHIFT)) & USBC_DIGITAL_CONTRL_0_SYNC_NUM_MASK)

#define USBC_DIGITAL_CONTRL_0_SYNCDET_WIN32_MASK (0x4U)
#define USBC_DIGITAL_CONTRL_0_SYNCDET_WIN32_SHIFT (2U)
/*! SYNCDET_WIN32 - SYNC Detect Window Select */
#define USBC_DIGITAL_CONTRL_0_SYNCDET_WIN32(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SYNCDET_WIN32_SHIFT)) & USBC_DIGITAL_CONTRL_0_SYNCDET_WIN32_MASK)

#define USBC_DIGITAL_CONTRL_0_SYNCDET_WINDOW_EN_MASK (0x8U)
#define USBC_DIGITAL_CONTRL_0_SYNCDET_WINDOW_EN_SHIFT (3U)
/*! SYNCDET_WINDOW_EN - SYNC Detection Window Enable */
#define USBC_DIGITAL_CONTRL_0_SYNCDET_WINDOW_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SYNCDET_WINDOW_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_SYNCDET_WINDOW_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL0_MASK (0x10U)
#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL0_SHIFT (4U)
/*! HOST_DISCON_SEL0 - Host Disconnect Select 0 */
#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL0(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL0_SHIFT)) & USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL0_MASK)

#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL1_MASK (0x20U)
#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL1_SHIFT (5U)
/*! HOST_DISCON_SEL1 - Host Disconnect Select 1 */
#define USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL1(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL1_SHIFT)) & USBC_DIGITAL_CONTRL_0_HOST_DISCON_SEL1_MASK)

#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_BYPASS_MASK (0x80U)
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_BYPASS_SHIFT (7U)
/*! PLL_LOCK_BYPASS - PLL Lock Bypass */
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_PLL_LOCK_BYPASS_SHIFT)) & USBC_DIGITAL_CONTRL_0_PLL_LOCK_BYPASS_MASK)

#define USBC_DIGITAL_CONTRL_0_LONG_EOP_MASK      (0x100U)
#define USBC_DIGITAL_CONTRL_0_LONG_EOP_SHIFT     (8U)
/*! LONG_EOP - Long EOP */
#define USBC_DIGITAL_CONTRL_0_LONG_EOP(x)        (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_LONG_EOP_SHIFT)) & USBC_DIGITAL_CONTRL_0_LONG_EOP_MASK)

#define USBC_DIGITAL_CONTRL_0_RXFILT1_EN_MASK    (0x200U)
#define USBC_DIGITAL_CONTRL_0_RXFILT1_EN_SHIFT   (9U)
/*! RXFILT1_EN - Rx Data Sample Filter 1 Enable */
#define USBC_DIGITAL_CONTRL_0_RXFILT1_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_RXFILT1_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_RXFILT1_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_RXFILT2_EN_MASK    (0x400U)
#define USBC_DIGITAL_CONTRL_0_RXFILT2_EN_SHIFT   (10U)
/*! RXFILT2_EN - Rx Data Sample Filter 2 Enable */
#define USBC_DIGITAL_CONTRL_0_RXFILT2_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_RXFILT2_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_RXFILT2_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_EARLY_TX_ENABLE_MASK (0x800U)
#define USBC_DIGITAL_CONTRL_0_EARLY_TX_ENABLE_SHIFT (11U)
/*! EARLY_TX_ENABLE - Early Tx Enable */
#define USBC_DIGITAL_CONTRL_0_EARLY_TX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_EARLY_TX_ENABLE_SHIFT)) & USBC_DIGITAL_CONTRL_0_EARLY_TX_ENABLE_MASK)

#define USBC_DIGITAL_CONTRL_0_SQ_BLK_MASK        (0x7000U)
#define USBC_DIGITAL_CONTRL_0_SQ_BLK_SHIFT       (12U)
/*! SQ_BLK - Squelch Block */
#define USBC_DIGITAL_CONTRL_0_SQ_BLK(x)          (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SQ_BLK_SHIFT)) & USBC_DIGITAL_CONTRL_0_SQ_BLK_MASK)

#define USBC_DIGITAL_CONTRL_0_RXFILT3_EN_MASK    (0x8000U)
#define USBC_DIGITAL_CONTRL_0_RXFILT3_EN_SHIFT   (15U)
/*! RXFILT3_EN - Rx Data Sample Filter 3 Enable */
#define USBC_DIGITAL_CONTRL_0_RXFILT3_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_RXFILT3_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_RXFILT3_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_SQ_FILT_MASK       (0x70000U)
#define USBC_DIGITAL_CONTRL_0_SQ_FILT_SHIFT      (16U)
/*! SQ_FILT - SQ Glitch Filtering Width Select */
#define USBC_DIGITAL_CONTRL_0_SQ_FILT(x)         (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SQ_FILT_SHIFT)) & USBC_DIGITAL_CONTRL_0_SQ_FILT_MASK)

#define USBC_DIGITAL_CONTRL_0_FIFOOVF_EN_MASK    (0x80000U)
#define USBC_DIGITAL_CONTRL_0_FIFOOVF_EN_SHIFT   (19U)
/*! FIFOOVF_EN - FIFO Overflow Error Enable */
#define USBC_DIGITAL_CONTRL_0_FIFOOVF_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_FIFOOVF_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_FIFOOVF_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_LOSSOFSYNC_EN_MASK (0x100000U)
#define USBC_DIGITAL_CONTRL_0_LOSSOFSYNC_EN_SHIFT (20U)
/*! LOSSOFSYNC_EN - Loss of SYNC Error Enable */
#define USBC_DIGITAL_CONTRL_0_LOSSOFSYNC_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_LOSSOFSYNC_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_LOSSOFSYNC_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_RX_RUNAWAY_EN_MASK (0x200000U)
#define USBC_DIGITAL_CONTRL_0_RX_RUNAWAY_EN_SHIFT (21U)
/*! RX_RUNAWAY_EN - Rx Run Away Enable */
#define USBC_DIGITAL_CONTRL_0_RX_RUNAWAY_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_RX_RUNAWAY_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_RX_RUNAWAY_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_STOP_AT_RXERR_MASK (0x400000U)
#define USBC_DIGITAL_CONTRL_0_STOP_AT_RXERR_SHIFT (22U)
/*! STOP_AT_RXERR - Stop At RX_ERROR */
#define USBC_DIGITAL_CONTRL_0_STOP_AT_RXERR(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_STOP_AT_RXERR_SHIFT)) & USBC_DIGITAL_CONTRL_0_STOP_AT_RXERR_MASK)

#define USBC_DIGITAL_CONTRL_0_EDGE_OPT_EN_MASK   (0x800000U)
#define USBC_DIGITAL_CONTRL_0_EDGE_OPT_EN_SHIFT  (23U)
/*! EDGE_OPT_EN - Edge Optimization Enable */
#define USBC_DIGITAL_CONTRL_0_EDGE_OPT_EN(x)     (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_EDGE_OPT_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_EDGE_OPT_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_SE0_FILT_SEL_MASK  (0x1000000U)
#define USBC_DIGITAL_CONTRL_0_SE0_FILT_SEL_SHIFT (24U)
/*! SE0_FILT_SEL - Linestate SE0 Filter Select */
#define USBC_DIGITAL_CONTRL_0_SE0_FILT_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SE0_FILT_SEL_SHIFT)) & USBC_DIGITAL_CONTRL_0_SE0_FILT_SEL_MASK)

#define USBC_DIGITAL_CONTRL_0_SE1_FILT_SEL_MASK  (0x2000000U)
#define USBC_DIGITAL_CONTRL_0_SE1_FILT_SEL_SHIFT (25U)
/*! SE1_FILT_SEL - Linestate SE1 Filter Select */
#define USBC_DIGITAL_CONTRL_0_SE1_FILT_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_SE1_FILT_SEL_SHIFT)) & USBC_DIGITAL_CONTRL_0_SE1_FILT_SEL_MASK)

#define USBC_DIGITAL_CONTRL_0_CORE_UTMI_SEL_MASK (0x4000000U)
#define USBC_DIGITAL_CONTRL_0_CORE_UTMI_SEL_SHIFT (26U)
/*! CORE_UTMI_SEL - UTMI Signal Select */
#define USBC_DIGITAL_CONTRL_0_CORE_UTMI_SEL(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_CORE_UTMI_SEL_SHIFT)) & USBC_DIGITAL_CONTRL_0_CORE_UTMI_SEL_MASK)

#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_VAL_MASK (0x8000000U)
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_VAL_SHIFT (27U)
/*! PLL_LOCK_FORCE_VAL - PLL Lock Force Value */
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_VAL_SHIFT)) & USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_VAL_MASK)

#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_EN_MASK (0x10000000U)
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_EN_SHIFT (28U)
/*! PLL_LOCK_FORCE_EN - PLL Lock Force Enable */
#define USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_EN_SHIFT)) & USBC_DIGITAL_CONTRL_0_PLL_LOCK_FORCE_EN_MASK)

#define USBC_DIGITAL_CONTRL_0_FIFO_OVF_ERROR_MASK (0x20000000U)
#define USBC_DIGITAL_CONTRL_0_FIFO_OVF_ERROR_SHIFT (29U)
/*! FIFO_OVF_ERROR - HS Rx FIFO Overflow Error Flag */
#define USBC_DIGITAL_CONTRL_0_FIFO_OVF_ERROR(x)  (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_FIFO_OVF_ERROR_SHIFT)) & USBC_DIGITAL_CONTRL_0_FIFO_OVF_ERROR_MASK)

#define USBC_DIGITAL_CONTRL_0_LOSS_OF_SYNC_ERROR_MASK (0x40000000U)
#define USBC_DIGITAL_CONTRL_0_LOSS_OF_SYNC_ERROR_SHIFT (30U)
/*! LOSS_OF_SYNC_ERROR - HS Loss of SYNC Error Flag */
#define USBC_DIGITAL_CONTRL_0_LOSS_OF_SYNC_ERROR(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_LOSS_OF_SYNC_ERROR_SHIFT)) & USBC_DIGITAL_CONTRL_0_LOSS_OF_SYNC_ERROR_MASK)

#define USBC_DIGITAL_CONTRL_0_BITSTUFFING_ERROR_MASK (0x80000000U)
#define USBC_DIGITAL_CONTRL_0_BITSTUFFING_ERROR_SHIFT (31U)
/*! BITSTUFFING_ERROR - HS Bit Stuffing Error Flag */
#define USBC_DIGITAL_CONTRL_0_BITSTUFFING_ERROR(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_0_BITSTUFFING_ERROR_SHIFT)) & USBC_DIGITAL_CONTRL_0_BITSTUFFING_ERROR_MASK)
/*! @} */

/*! @name DIGITAL_CONTRL_1 - Digital Contrl 1 */
/*! @{ */

#define USBC_DIGITAL_CONTRL_1_REG_FORCE_END_EN_MASK (0x1U)
#define USBC_DIGITAL_CONTRL_1_REG_FORCE_END_EN_SHIFT (0U)
/*! REG_FORCE_END_EN - Force RX_ACTIVE to End */
#define USBC_DIGITAL_CONTRL_1_REG_FORCE_END_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FORCE_END_EN_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FORCE_END_EN_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE_MASK (0x2U)
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE_SHIFT (1U)
/*! REG_FS_RX_ERROR_MODE - FS RX_ERROR Mode */
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE1_MASK (0x4U)
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE1_SHIFT (2U)
/*! REG_FS_RX_ERROR_MODE1 - FS RX_ERROR Mode 1 */
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE1(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE1_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE1_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE2_MASK (0x8U)
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE2_SHIFT (3U)
/*! REG_FS_RX_ERROR_MODE2 - FS RX_ERROR Mode 2 */
#define USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE2(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE2_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FS_RX_ERROR_MODE2_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_ARC_DPDM_MODE_MASK (0x10U)
#define USBC_DIGITAL_CONTRL_1_REG_ARC_DPDM_MODE_SHIFT (4U)
/*! REG_ARC_DPDM_MODE - DP/DM Pulldown Mode */
#define USBC_DIGITAL_CONTRL_1_REG_ARC_DPDM_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_ARC_DPDM_MODE_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_ARC_DPDM_MODE_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_DM_PULLDOWN_MASK (0x20U)
#define USBC_DIGITAL_CONTRL_1_REG_DM_PULLDOWN_SHIFT (5U)
/*! REG_DM_PULLDOWN - DM Pulldown Control */
#define USBC_DIGITAL_CONTRL_1_REG_DM_PULLDOWN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_DM_PULLDOWN_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_DM_PULLDOWN_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_DP_PULLDOWN_MASK (0x40U)
#define USBC_DIGITAL_CONTRL_1_REG_DP_PULLDOWN_SHIFT (6U)
/*! REG_DP_PULLDOWN - DP Pulldown Control */
#define USBC_DIGITAL_CONTRL_1_REG_DP_PULLDOWN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_DP_PULLDOWN_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_DP_PULLDOWN_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FS_EOP_MODE_MASK (0x80U)
#define USBC_DIGITAL_CONTRL_1_REG_FS_EOP_MODE_SHIFT (7U)
/*! REG_FS_EOP_MODE - FS EOP Mode */
#define USBC_DIGITAL_CONTRL_1_REG_FS_EOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FS_EOP_MODE_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FS_EOP_MODE_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_NOVBUS_DPDM00_MASK (0x400U)
#define USBC_DIGITAL_CONTRL_1_REG_NOVBUS_DPDM00_SHIFT (10U)
/*! REG_NOVBUS_DPDM00 - No VBUS DP/DM Pulldown Mode */
#define USBC_DIGITAL_CONTRL_1_REG_NOVBUS_DPDM00(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_NOVBUS_DPDM00_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_NOVBUS_DPDM00_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FREERUNCLK_EN_MASK (0x800U)
#define USBC_DIGITAL_CONTRL_1_REG_FREERUNCLK_EN_SHIFT (11U)
/*! REG_FREERUNCLK_EN - Free Running Clock Output Enable */
#define USBC_DIGITAL_CONTRL_1_REG_FREERUNCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FREERUNCLK_EN_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FREERUNCLK_EN_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_FLSMODELP_EN_MASK (0x1000U)
#define USBC_DIGITAL_CONTRL_1_REG_FLSMODELP_EN_SHIFT (12U)
/*! REG_FLSMODELP_EN - FS/LS Serial Mode Low Power Enable */
#define USBC_DIGITAL_CONTRL_1_REG_FLSMODELP_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_FLSMODELP_EN_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_FLSMODELP_EN_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_OPMODE_SEL_MASK (0x2000U)
#define USBC_DIGITAL_CONTRL_1_REG_OPMODE_SEL_SHIFT (13U)
/*! REG_OPMODE_SEL - OPMODE Select */
#define USBC_DIGITAL_CONTRL_1_REG_OPMODE_SEL(x)  (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_OPMODE_SEL_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_OPMODE_SEL_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_LAT_UTMI_MASK  (0x4000U)
#define USBC_DIGITAL_CONTRL_1_REG_LAT_UTMI_SHIFT (14U)
/*! REG_LAT_UTMI - Latch UTMI Signals */
#define USBC_DIGITAL_CONTRL_1_REG_LAT_UTMI(x)    (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_LAT_UTMI_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_LAT_UTMI_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_SWAP_DPDM_MASK (0x8000U)
#define USBC_DIGITAL_CONTRL_1_REG_SWAP_DPDM_SHIFT (15U)
/*! REG_SWAP_DPDM - Swap DP/DM pad */
#define USBC_DIGITAL_CONTRL_1_REG_SWAP_DPDM(x)   (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_SWAP_DPDM_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_SWAP_DPDM_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_SAMPLEROFF_DLY_MASK (0xF0000U)
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLEROFF_DLY_SHIFT (16U)
/*! REG_SAMPLEROFF_DLY - Sampler Turn Off Delay */
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLEROFF_DLY(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_SAMPLEROFF_DLY_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_SAMPLEROFF_DLY_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_ON_MASK (0x100000U)
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_ON_SHIFT (20U)
/*! REG_SAMPLER_ON - Sampler On Control */
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_ON(x)  (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_SAMPLER_ON_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_SAMPLER_ON_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_PREOFF_MASK (0x200000U)
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_PREOFF_SHIFT (21U)
/*! REG_SAMPLER_PREOFF - Sampler Pre Off Control */
#define USBC_DIGITAL_CONTRL_1_REG_SAMPLER_PREOFF(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_SAMPLER_PREOFF_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_SAMPLER_PREOFF_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_CLK_OUT_DLY_MASK (0x3FC00000U)
#define USBC_DIGITAL_CONTRL_1_REG_CLK_OUT_DLY_SHIFT (22U)
/*! REG_CLK_OUT_DLY - CLK_OUT Delay Control */
#define USBC_DIGITAL_CONTRL_1_REG_CLK_OUT_DLY(x) (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_CLK_OUT_DLY_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_CLK_OUT_DLY_MASK)

#define USBC_DIGITAL_CONTRL_1_REG_LSIDLE_PRE_MASK (0x40000000U)
#define USBC_DIGITAL_CONTRL_1_REG_LSIDLE_PRE_SHIFT (30U)
/*! REG_LSIDLE_PRE - LS Idle after PRE */
#define USBC_DIGITAL_CONTRL_1_REG_LSIDLE_PRE(x)  (((uint32_t)(((uint32_t)(x)) << USBC_DIGITAL_CONTRL_1_REG_LSIDLE_PRE_SHIFT)) & USBC_DIGITAL_CONTRL_1_REG_LSIDLE_PRE_MASK)
/*! @} */

/*! @name TEST_CONTRL_AND_STATUS_0 - Test Contrl and Status 0 */
/*! @{ */

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_PATTERN_MASK (0xFFU)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_PATTERN_SHIFT (0U)
/*! REG_TEST_TX_PATTERN - Programmable Tx Pattern */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_PATTERN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_PATTERN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_MODE_MASK (0x300U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_MODE_SHIFT (8U)
/*! REG_TEST_MODE - Programmable Predefined Tx Pattern */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_MODE_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_MODE_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SKIP_MASK (0x7000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SKIP_SHIFT (12U)
/*! REG_TEST_SKIP - Digital Loopback Starting Position */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SKIP(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SKIP_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SKIP_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_OP_MODE_MASK (0x30000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_OP_MODE_SHIFT (16U)
/*! REG_TEST_OP_MODE - UTMI Test Mode OP_MODE */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_OP_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_OP_MODE_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_OP_MODE_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_XVCR_SELECT_MASK (0xC0000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_XVCR_SELECT_SHIFT (18U)
/*! REG_TEST_XVCR_SELECT - UTMI Test Mode XCVR_SELECT */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_XVCR_SELECT(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_XVCR_SELECT_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_XVCR_SELECT_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TERM_SELECT_MASK (0x100000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TERM_SELECT_SHIFT (20U)
/*! REG_TEST_TERM_SELECT - UTMI Test Mode TERM_SELECT */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TERM_SELECT(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TERM_SELECT_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TERM_SELECT_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_RESET_MASK (0x200000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_RESET_SHIFT (21U)
/*! REG_TEST_RESET - UTMI Test Mode Reset */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_RESET(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_RESET_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_RESET_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SUSPENDM_MASK (0x400000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SUSPENDM_SHIFT (22U)
/*! REG_TEST_SUSPENDM - UTMI Test Mode SUSPENDM */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SUSPENDM(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SUSPENDM_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_SUSPENDM_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_BITSTUFF_EN_MASK (0x800000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_BITSTUFF_EN_SHIFT (23U)
/*! REG_TEST_TX_BITSTUFF_EN - UTMI Test Mode TX_BITSTUFF_EN */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_BITSTUFF_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_BITSTUFF_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_TX_BITSTUFF_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_UTMI_SEL_MASK (0x2000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_UTMI_SEL_SHIFT (25U)
/*! REG_TEST_UTMI_SEL - UTMI Test Mode UTMI Test Register Select */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_UTMI_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_UTMI_SEL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_UTMI_SEL_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_BYPASS_MASK (0x4000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_BYPASS_SHIFT (26U)
/*! REG_TEST_BYPASS - Enable Bypass Mode (Bypass bitstuff/encoder) */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_BYPASS_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_BYPASS_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_ANA_LPBK_MASK (0x8000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_ANA_LPBK_SHIFT (27U)
/*! REG_TEST_ANA_LPBK - Enable Analog Loopback Test Mode */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_ANA_LPBK(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_ANA_LPBK_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_ANA_LPBK_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_DIG_LPBK_MASK (0x10000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_DIG_LPBK_SHIFT (28U)
/*! REG_TEST_DIG_LPBK - Enable Digital Loopback Test Mode */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_DIG_LPBK(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_DIG_LPBK_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_DIG_LPBK_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_EN_MASK (0x20000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_EN_SHIFT (29U)
/*! REG_TEST_EN - Test Enable */
#define USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_REG_TEST_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_DONE_MASK (0x40000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_DONE_SHIFT (30U)
/*! TEST_DONE - Test Finish Indicator */
#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_DONE(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_TEST_DONE_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_TEST_DONE_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_FAIL_MASK (0x80000000U)
#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_FAIL_SHIFT (31U)
/*! TEST_FAIL - Test Error Flag */
#define USBC_TEST_CONTRL_AND_STATUS_0_TEST_FAIL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_0_TEST_FAIL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_0_TEST_FAIL_MASK)
/*! @} */

/*! @name TEST_CONTRL_AND_STATUS_1 - Test Contrl and Status 1 */
/*! @{ */

#define USBC_TEST_CONTRL_AND_STATUS_1_TEST_LEN_MASK (0x7FFU)
#define USBC_TEST_CONTRL_AND_STATUS_1_TEST_LEN_SHIFT (0U)
/*! TEST_LEN - Loopback Test Length */
#define USBC_TEST_CONTRL_AND_STATUS_1_TEST_LEN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_TEST_LEN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_TEST_LEN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_N_MASK (0x1000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_N_SHIFT (12U)
/*! FLS_RX_N - Force Value for RX_N when fls_rx_force_en = 1 */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_N(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_N_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_N_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_P_MASK (0x2000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_P_SHIFT (13U)
/*! FLS_RX_P - Force value for RX_P when fls_rx_force_en = 1 */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_P(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_P_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_P_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_FS_LS_MASK (0x4000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_FS_LS_SHIFT (14U)
/*! DOUT_FS_LS - Force value for dout_fs_ls when fls_rx_force_en = 1 */
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_FS_LS(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_DOUT_FS_LS_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_DOUT_FS_LS_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_FORCE_EN_MASK (0x8000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_FORCE_EN_SHIFT (15U)
/*! FLS_RX_FORCE_EN - FS/LS RX Signal Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_RX_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_VAL_MASK (0x30000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_VAL_SHIFT (16U)
/*! LINESTATE_FORCE_VAL - Linestate Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_VAL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_VAL_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_EN_MASK (0x40000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_EN_SHIFT (18U)
/*! LINESTATE_FORCE_EN - Linestate Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_LINESTATE_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_VAL_MASK (0x80000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_VAL_SHIFT (19U)
/*! DISCON_FORCE_VAL - host_disconnect Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_VAL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_VAL_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_EN_MASK (0x100000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_EN_SHIFT (20U)
/*! DISCON_FORCE_EN - host_disconnect Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_DISCON_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_VAL_MASK (0x200000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_VAL_SHIFT (21U)
/*! SQ_FORCE_VAL - Squelch Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_VAL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_VAL_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_EN_MASK (0x400000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_EN_SHIFT (22U)
/*! SQ_FORCE_EN - Squelch Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_SQ_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_VAL_MASK (0x800000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_VAL_SHIFT (23U)
/*! DOUT_HS_FORCE_VAL - dout_hs Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_VAL(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_VAL_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_VAL_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_EN_MASK (0x1000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_EN_SHIFT (24U)
/*! DOUT_HS_FORCE_EN - dout_hs Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_DOUT_HS_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_DATA_MASK (0x2000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_DATA_SHIFT (25U)
/*! HS_TX_DATA - HS TX Data Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_DATA(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_DATA_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_DATA_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_ENABLE_MASK (0x4000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_ENABLE_SHIFT (26U)
/*! HS_TX_ENABLE - HS TX Enable Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_ENABLE_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_ENABLE_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_FORCE_EN_MASK (0x8000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_FORCE_EN_SHIFT (27U)
/*! HS_TX_FORCE_EN - HS TX Output Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_HS_TX_FORCE_EN_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_DAT_MASK (0x10000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_DAT_SHIFT (28U)
/*! FLS_TX_DAT - FS/LS TX Data Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_DAT(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_DAT_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_DAT_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_SE0_MASK (0x20000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_SE0_SHIFT (29U)
/*! FLS_TX_SE0 - FS/LS TX SE0 Control Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_SE0(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_SE0_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_SE0_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_ENABLE_MASK (0x40000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_ENABLE_SHIFT (30U)
/*! FLS_TX_ENABLE - FS/LS TX Enable Force Value */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_ENABLE_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_ENABLE_MASK)

#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_FORCE_EN_MASK (0x80000000U)
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_FORCE_EN_SHIFT (31U)
/*! FLS_TX_FORCE_EN - FS/LS TX Output Force Enable */
#define USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_FORCE_EN_SHIFT)) & USBC_TEST_CONTRL_AND_STATUS_1_FLS_TX_FORCE_EN_MASK)
/*! @} */

/*! @name PHY_REG_OTG_CONTROL - OTG Control */
/*! @{ */

#define USBC_PHY_REG_OTG_CONTROL_PU_OTG_MASK     (0x10U)
#define USBC_PHY_REG_OTG_CONTROL_PU_OTG_SHIFT    (4U)
/*! PU_OTG - OTG power control */
#define USBC_PHY_REG_OTG_CONTROL_PU_OTG(x)       (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_OTG_CONTROL_PU_OTG_SHIFT)) & USBC_PHY_REG_OTG_CONTROL_PU_OTG_MASK)

#define USBC_PHY_REG_OTG_CONTROL_OTG_CONTROL_BY_PIN_MASK (0x20U)
#define USBC_PHY_REG_OTG_CONTROL_OTG_CONTROL_BY_PIN_SHIFT (5U)
/*! OTG_CONTROL_BY_PIN - OTG Power Controll Select */
#define USBC_PHY_REG_OTG_CONTROL_OTG_CONTROL_BY_PIN(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_OTG_CONTROL_OTG_CONTROL_BY_PIN_SHIFT)) & USBC_PHY_REG_OTG_CONTROL_OTG_CONTROL_BY_PIN_MASK)
/*! @} */

/*! @name PHY_REG_CHGDTC_CONTRL_1 - Charger Detector Control */
/*! @{ */

#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_EN_MASK (0x4U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_EN_SHIFT (2U)
/*! CDP_EN - Charging Downstream Port Mode Enable */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_EN_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_EN_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_DCP_EN_MASK (0x8U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_DCP_EN_SHIFT (3U)
/*! DCP_EN - Dedicated Charging Port Mode Enable */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_DCP_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_DCP_EN_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_DCP_EN_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_PD_EN_MASK  (0x10U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_PD_EN_SHIFT (4U)
/*! PD_EN - Portable Device Mode Enable */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_PD_EN(x)    (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_PD_EN_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_PD_EN_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_PU_CHRG_DTC_MASK (0x20U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_PU_CHRG_DTC_SHIFT (5U)
/*! PU_CHRG_DTC - Powe Up Charge Detector */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_PU_CHRG_DTC(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_PU_CHRG_DTC_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_PU_CHRG_DTC_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_DP_DM_SWAP_CTRL_MASK (0x40U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_DP_DM_SWAP_CTRL_SHIFT (6U)
/*! DP_DM_SWAP_CTRL - DP/DM Swap Control */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_DP_DM_SWAP_CTRL(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_DP_DM_SWAP_CTRL_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_DP_DM_SWAP_CTRL_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_DM_AUTO_SWITCH_MASK (0x80U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_DM_AUTO_SWITCH_SHIFT (7U)
/*! CDP_DM_AUTO_SWITCH - CDP Mode DM Port Automatic Switch */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_DM_AUTO_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_DM_AUTO_SWITCH_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_CDP_DM_AUTO_SWITCH_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_VDAT_CHARGE_MASK (0x300U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_VDAT_CHARGE_SHIFT (8U)
/*! VDAT_CHARGE - VDAT Reference Voltage Control */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_VDAT_CHARGE(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_VDAT_CHARGE_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_VDAT_CHARGE_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_VSRC_CHARGE_MASK (0xC00U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_VSRC_CHARGE_SHIFT (10U)
/*! VSRC_CHARGE - VSRC Reference Voltage Control */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_VSRC_CHARGE(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_VSRC_CHARGE_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_VSRC_CHARGE_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DP_MASK (0x1000U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DP_SHIFT (12U)
/*! ENABLE_SWITCH_DP - Enable DP Port Switch */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DP(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DP_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DP_MASK)

#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DM_MASK (0x2000U)
#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DM_SHIFT (13U)
/*! ENABLE_SWITCH_DM - Enable DM Port Switch */
#define USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DM(x) (((uint32_t)(((uint32_t)(x)) << USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DM_SHIFT)) & USBC_PHY_REG_CHGDTC_CONTRL_1_ENABLE_SWITCH_DM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBC_Register_Masks */

/* Backward compatibility */
#define GPTIMER0CTL                              GPTIMER0CTRL
#define GPTIMER1CTL                              GPTIMER1CTRL
#define USBC_SBUSCFG                             SBUSCFG
#define EPLISTADDR                               ENDPOINTLISTADDR
#define EPSETUPSR                                ENDPTSETUPSTAT
#define EPPRIME                                  ENDPTPRIME
#define EPFLUSH                                  ENDPTFLUSH
#define EPSR                                     ENDPTSTAT
#define EPCOMPLETE                               ENDPTCOMPLETE
#define EPCR                                     ENDPTCTRL
#define EPCR0                                    ENDPTCTRL0
#define USBHS_ID_ID_MASK                         USBC_ID_ID_MASK
#define USBHS_ID_ID_SHIFT                        USBC_ID_ID_SHIFT
#define USBHS_ID_ID(x)                           USBC_ID_ID(x)
#define USBHS_ID_NID_MASK                        USBC_ID_NID_MASK
#define USBHS_ID_NID_SHIFT                       USBC_ID_NID_SHIFT
#define USBHS_ID_NID(x)                          USBC_ID_NID(x)
#define USBHS_ID_REVISION_MASK                   USBC_ID_REVISION_MASK
#define USBHS_ID_REVISION_SHIFT                  USBC_ID_REVISION_SHIFT
#define USBHS_ID_REVISION(x)                     USBC_ID_REVISION(x)
#define USBHS_HWGENERAL_PHYW_MASK                USBC_HWGENERAL_PHYW_MASK
#define USBHS_HWGENERAL_PHYW_SHIFT               USBC_HWGENERAL_PHYW_SHIFT
#define USBHS_HWGENERAL_PHYW(x)                  USBC_HWGENERAL_PHYW(x)
#define USBHS_HWGENERAL_PHYM_MASK                USBC_HWGENERAL_PHYM_MASK
#define USBHS_HWGENERAL_PHYM_SHIFT               USBC_HWGENERAL_PHYM_SHIFT
#define USBHS_HWGENERAL_PHYM(x)                  USBC_HWGENERAL_PHYM(x)
#define USBHS_HWGENERAL_SM_MASK                  USBC_HWGENERAL_SM_MASK
#define USBHS_HWGENERAL_SM_SHIFT                 USBC_HWGENERAL_SM_SHIFT
#define USBHS_HWGENERAL_SM(x)                    USBC_HWGENERAL_SM(x)
#define USBHS_HWHOST_HC_MASK                     USBC_HWHOST_HC_MASK
#define USBHS_HWHOST_HC_SHIFT                    USBC_HWHOST_HC_SHIFT
#define USBHS_HWHOST_HC(x)                       USBC_HWHOST_HC(x)
#define USBHS_HWHOST_NPORT_MASK                  USBC_HWHOST_NPORT_MASK
#define USBHS_HWHOST_NPORT_SHIFT                 USBC_HWHOST_NPORT_SHIFT
#define USBHS_HWHOST_NPORT(x)                    USBC_HWHOST_NPORT(x)
#define USBHS_HWDEVICE_DC_MASK                   USBC_HWDEVICE_DC_MASK
#define USBHS_HWDEVICE_DC_SHIFT                  USBC_HWDEVICE_DC_SHIFT
#define USBHS_HWDEVICE_DC(x)                     USBC_HWDEVICE_DC(x)
#define USBHS_HWDEVICE_DEVEP_MASK                USBC_HWDEVICE_DEVEP_MASK
#define USBHS_HWDEVICE_DEVEP_SHIFT               USBC_HWDEVICE_DEVEP_SHIFT
#define USBHS_HWDEVICE_DEVEP(x)                  USBC_HWDEVICE_DEVEP(x)
#define USBHS_HWTXBUF_TXBURST_MASK               USBC_HWTXBUF_TXBURST_MASK
#define USBHS_HWTXBUF_TXBURST_SHIFT              USBC_HWTXBUF_TXBURST_SHIFT
#define USBHS_HWTXBUF_TXBURST(x)                 USBC_HWTXBUF_TXBURST(x)
#define USBHS_HWTXBUF_TXCHANADD_MASK             USBC_HWTXBUF_TXCHANADD_MASK
#define USBHS_HWTXBUF_TXCHANADD_SHIFT            USBC_HWTXBUF_TXCHANADD_SHIFT
#define USBHS_HWTXBUF_TXCHANADD(x)               USBC_HWTXBUF_TXCHANADD(x)
#define USBHS_HWRXBUF_RXBURST_MASK               USBC_HWRXBUF_RXBURST_MASK
#define USBHS_HWRXBUF_RXBURST_SHIFT              USBC_HWRXBUF_RXBURST_SHIFT
#define USBHS_HWRXBUF_RXBURST(x)                 USBC_HWRXBUF_RXBURST(x)
#define USBHS_HWRXBUF_RXADD_MASK                 USBC_HWRXBUF_RXADD_MASK
#define USBHS_HWRXBUF_RXADD_SHIFT                USBC_HWRXBUF_RXADD_SHIFT
#define USBHS_HWRXBUF_RXADD(x)                   USBC_HWRXBUF_RXADD(x)
#define USBHS_GPTIMER0LD_GPTLD_MASK              USBC_GPTIMER0LD_GPTLD_MASK
#define USBHS_GPTIMER0LD_GPTLD_SHIFT             USBC_GPTIMER0LD_GPTLD_SHIFT
#define USBHS_GPTIMER0LD_GPTLD(x)                USBC_GPTIMER0LD_GPTLD(x)
#define USBHS_GPTIMER0CTL_GPTCNT_MASK            USBC_GPTIMER0CTRL_GPTCNT_MASK
#define USBHS_GPTIMER0CTL_GPTCNT_SHIFT           USBC_GPTIMER0CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER0CTL_GPTCNT(x)              USBC_GPTIMER0CTRL_GPTCNT(x)
#define USBHS_GPTIMER0CTL_MODE_MASK              USBC_GPTIMER0CTRL_GPTMODE_MASK
#define USBHS_GPTIMER0CTL_MODE_SHIFT             USBC_GPTIMER0CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER0CTL_MODE(x)                USBC_GPTIMER0CTRL_GPTMODE(x)
#define USBHS_GPTIMER0CTL_RST_MASK               USBC_GPTIMER0CTRL_GPTRST_MASK
#define USBHS_GPTIMER0CTL_RST_SHIFT              USBC_GPTIMER0CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER0CTL_RST(x)                 USBC_GPTIMER0CTRL_GPTRST(x)
#define USBHS_GPTIMER0CTL_RUN_MASK               USBC_GPTIMER0CTRL_GPTRUN_MASK
#define USBHS_GPTIMER0CTL_RUN_SHIFT              USBC_GPTIMER0CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER0CTL_RUN(x)                 USBC_GPTIMER0CTRL_GPTRUN(x)
#define USBHS_GPTIMER1LD_GPTLD_MASK              USBC_GPTIMER1LD_GPTLD_MASK
#define USBHS_GPTIMER1LD_GPTLD_SHIFT             USBC_GPTIMER1LD_GPTLD_SHIFT
#define USBHS_GPTIMER1LD_GPTLD(x)                USBC_GPTIMER1LD_GPTLD(x)
#define USBHS_GPTIMER1CTL_GPTCNT_MASK            USBC_GPTIMER1CTRL_GPTCNT_MASK
#define USBHS_GPTIMER1CTL_GPTCNT_SHIFT           USBC_GPTIMER1CTRL_GPTCNT_SHIFT
#define USBHS_GPTIMER1CTL_GPTCNT(x)              USBC_GPTIMER1CTRL_GPTCNT(x)
#define USBHS_GPTIMER1CTL_MODE_MASK              USBC_GPTIMER1CTRL_GPTMODE_MASK
#define USBHS_GPTIMER1CTL_MODE_SHIFT             USBC_GPTIMER1CTRL_GPTMODE_SHIFT
#define USBHS_GPTIMER1CTL_MODE(x)                USBC_GPTIMER1CTRL_GPTMODE(x)
#define USBHS_GPTIMER1CTL_RST_MASK               USBC_GPTIMER1CTRL_GPTRST_MASK
#define USBHS_GPTIMER1CTL_RST_SHIFT              USBC_GPTIMER1CTRL_GPTRST_SHIFT
#define USBHS_GPTIMER1CTL_RST(x)                 USBC_GPTIMER1CTRL_GPTRST(x)
#define USBHS_GPTIMER1CTL_RUN_MASK               USBC_GPTIMER1CTRL_GPTRUN_MASK
#define USBHS_GPTIMER1CTL_RUN_SHIFT              USBC_GPTIMER1CTRL_GPTRUN_SHIFT
#define USBHS_GPTIMER1CTL_RUN(x)                 USBC_GPTIMER1CTRL_GPTRUN(x)
#define USBHS_USBC_SBUSCFG_BURSTMODE_MASK        USBC_SBUSCFG_AHBBRST_MASK
#define USBHS_USBC_SBUSCFG_BURSTMODE_SHIFT       USBC_SBUSCFG_AHBBRST_SHIFT
#define USBHS_USBC_SBUSCFG_BURSTMODE(x)          USBC_SBUSCFG_AHBBRST(x)
#define USBHS_CAPLENGTH_CAPLENGTH_MASK           USBC_CAPLENGTH_CAPLENGTH_MASK
#define USBHS_CAPLENGTH_CAPLENGTH_SHIFT          USBC_CAPLENGTH_CAPLENGTH_SHIFT
#define USBHS_CAPLENGTH_CAPLENGTH(x)             USBC_CAPLENGTH_CAPLENGTH(x)
#define USBHS_CAPLENGTH_HCIVERSION_MASK          USBC_CAPLENGTH_HCIVERSION_MASK
#define USBHS_CAPLENGTH_HCIVERSION_SHIFT         USBC_CAPLENGTH_HCIVERSION_SHIFT
#define USBHS_CAPLENGTH_HCIVERSION(x)            USBC_CAPLENGTH_HCIVERSION(x)
#define USBHS_HCSPARAMS_N_PORTS_MASK             USBC_HCSPARAMS_N_PORTS_MASK
#define USBHS_HCSPARAMS_N_PORTS_SHIFT            USBC_HCSPARAMS_N_PORTS_SHIFT
#define USBHS_HCSPARAMS_N_PORTS(x)               USBC_HCSPARAMS_N_PORTS(x)
#define USBHS_HCSPARAMS_PPC_MASK                 USBC_HCSPARAMS_PPC_MASK
#define USBHS_HCSPARAMS_PPC_SHIFT                USBC_HCSPARAMS_PPC_SHIFT
#define USBHS_HCSPARAMS_PPC(x)                   USBC_HCSPARAMS_PPC(x)
#define USBHS_HCSPARAMS_N_PCC_MASK               USBC_HCSPARAMS_N_PCC_MASK
#define USBHS_HCSPARAMS_N_PCC_SHIFT              USBC_HCSPARAMS_N_PCC_SHIFT
#define USBHS_HCSPARAMS_N_PCC(x)                 USBC_HCSPARAMS_N_PCC(x)
#define USBHS_HCSPARAMS_N_CC_MASK                USBC_HCSPARAMS_N_CC_MASK
#define USBHS_HCSPARAMS_N_CC_SHIFT               USBC_HCSPARAMS_N_CC_SHIFT
#define USBHS_HCSPARAMS_N_CC(x)                  USBC_HCSPARAMS_N_CC(x)
#define USBHS_HCSPARAMS_PI_MASK                  USBC_HCSPARAMS_PI_MASK
#define USBHS_HCSPARAMS_PI_SHIFT                 USBC_HCSPARAMS_PI_SHIFT
#define USBHS_HCSPARAMS_PI(x)                    USBC_HCSPARAMS_PI(x)
#define USBHS_HCSPARAMS_N_PTT_MASK               USBC_HCSPARAMS_N_PTT_MASK
#define USBHS_HCSPARAMS_N_PTT_SHIFT              USBC_HCSPARAMS_N_PTT_SHIFT
#define USBHS_HCSPARAMS_N_PTT(x)                 USBC_HCSPARAMS_N_PTT(x)
#define USBHS_HCSPARAMS_N_TT_MASK                USBC_HCSPARAMS_N_TT_MASK
#define USBHS_HCSPARAMS_N_TT_SHIFT               USBC_HCSPARAMS_N_TT_SHIFT
#define USBHS_HCSPARAMS_N_TT(x)                  USBC_HCSPARAMS_N_TT(x)
#define USBHS_HCCPARAMS_ADC_MASK                 USBC_HCCPARAMS_ADC_MASK
#define USBHS_HCCPARAMS_ADC_SHIFT                USBC_HCCPARAMS_ADC_SHIFT
#define USBHS_HCCPARAMS_ADC(x)                   USBC_HCCPARAMS_ADC(x)
#define USBHS_HCCPARAMS_PFL_MASK                 USBC_HCCPARAMS_PFL_MASK
#define USBHS_HCCPARAMS_PFL_SHIFT                USBC_HCCPARAMS_PFL_SHIFT
#define USBHS_HCCPARAMS_PFL(x)                   USBC_HCCPARAMS_PFL(x)
#define USBHS_HCCPARAMS_ASP_MASK                 USBC_HCCPARAMS_ASP_MASK
#define USBHS_HCCPARAMS_ASP_SHIFT                USBC_HCCPARAMS_ASP_SHIFT
#define USBHS_HCCPARAMS_ASP(x)                   USBC_HCCPARAMS_ASP(x)
#define USBHS_HCCPARAMS_IST_MASK                 USBC_HCCPARAMS_IST_MASK
#define USBHS_HCCPARAMS_IST_SHIFT                USBC_HCCPARAMS_IST_SHIFT
#define USBHS_HCCPARAMS_IST(x)                   USBC_HCCPARAMS_IST(x)
#define USBHS_HCCPARAMS_EECP_MASK                USBC_HCCPARAMS_EECP_MASK
#define USBHS_HCCPARAMS_EECP_SHIFT               USBC_HCCPARAMS_EECP_SHIFT
#define USBHS_HCCPARAMS_EECP(x)                  USBC_HCCPARAMS_EECP(x)
#define USBHS_DCIVERSION_DCIVERSION_MASK         USBC_DCIVERSION_DCIVERSION_MASK
#define USBHS_DCIVERSION_DCIVERSION_SHIFT        USBC_DCIVERSION_DCIVERSION_SHIFT
#define USBHS_DCIVERSION_DCIVERSION(x)           USBC_DCIVERSION_DCIVERSION(x)
#define USBHS_DCCPARAMS_DEN_MASK                 USBC_DCCPARAMS_DEN_MASK
#define USBHS_DCCPARAMS_DEN_SHIFT                USBC_DCCPARAMS_DEN_SHIFT
#define USBHS_DCCPARAMS_DEN(x)                   USBC_DCCPARAMS_DEN(x)
#define USBHS_DCCPARAMS_DC_MASK                  USBC_DCCPARAMS_DC_MASK
#define USBHS_DCCPARAMS_DC_SHIFT                 USBC_DCCPARAMS_DC_SHIFT
#define USBHS_DCCPARAMS_DC(x)                    USBC_DCCPARAMS_DC(x)
#define USBHS_DCCPARAMS_HC_MASK                  USBC_DCCPARAMS_HC_MASK
#define USBHS_DCCPARAMS_HC_SHIFT                 USBC_DCCPARAMS_HC_SHIFT
#define USBHS_DCCPARAMS_HC(x)                    USBC_DCCPARAMS_HC(x)
#define USBHS_USBCMD_RS_MASK                     USBC_USBCMD_RS_MASK
#define USBHS_USBCMD_RS_SHIFT                    USBC_USBCMD_RS_SHIFT
#define USBHS_USBCMD_RS(x)                       USBC_USBCMD_RS(x)
#define USBHS_USBCMD_RST_MASK                    USBC_USBCMD_RST_MASK
#define USBHS_USBCMD_RST_SHIFT                   USBC_USBCMD_RST_SHIFT
#define USBHS_USBCMD_RST(x)                      USBC_USBCMD_RST(x)
#define USBHS_USBCMD_FS_MASK                     USBC_USBCMD_FS_1_MASK
#define USBHS_USBCMD_FS_SHIFT                    USBC_USBCMD_FS_1_SHIFT
#define USBHS_USBCMD_FS(x)                       USBC_USBCMD_FS_1(x))
#define USBHS_USBCMD_PSE_MASK                    USBC_USBCMD_PSE_MASK
#define USBHS_USBCMD_PSE_SHIFT                   USBC_USBCMD_PSE_SHIFT
#define USBHS_USBCMD_PSE(x)                      USBC_USBCMD_PSE(x)
#define USBHS_USBCMD_ASE_MASK                    USBC_USBCMD_ASE_MASK
#define USBHS_USBCMD_ASE_SHIFT                   USBC_USBCMD_ASE_SHIFT
#define USBHS_USBCMD_ASE(x)                      USBC_USBCMD_ASE(x)
#define USBHS_USBCMD_IAA_MASK                    USBC_USBCMD_IAA_MASK
#define USBHS_USBCMD_IAA_SHIFT                   USBC_USBCMD_IAA_SHIFT
#define USBHS_USBCMD_IAA(x)                      USBC_USBCMD_IAA(x)
#define USBHS_USBCMD_ASP_MASK                    USBC_USBCMD_ASP_MASK
#define USBHS_USBCMD_ASP_SHIFT                   USBC_USBCMD_ASP_SHIFT
#define USBHS_USBCMD_ASP(x)                      USBC_USBCMD_ASP(x)
#define USBHS_USBCMD_ASPE_MASK                   USBC_USBCMD_ASPE_MASK
#define USBHS_USBCMD_ASPE_SHIFT                  USBC_USBCMD_ASPE_SHIFT
#define USBHS_USBCMD_ASPE(x)                     USBC_USBCMD_ASPE(x)
#define USBHS_USBCMD_ATDTW_MASK                  USBC_USBCMD_ATDTW_MASK
#define USBHS_USBCMD_ATDTW_SHIFT                 USBC_USBCMD_ATDTW_SHIFT
#define USBHS_USBCMD_ATDTW(x)                    USBC_USBCMD_ATDTW(x)
#define USBHS_USBCMD_SUTW_MASK                   USBC_USBCMD_SUTW_MASK
#define USBHS_USBCMD_SUTW_SHIFT                  USBC_USBCMD_SUTW_SHIFT
#define USBHS_USBCMD_SUTW(x)                     USBC_USBCMD_SUTW(x)
#define USBHS_USBCMD_FS2_MASK                    USBC_USBCMD_FS_2_MASK
#define USBHS_USBCMD_FS2_SHIFT                   USBC_USBCMD_FS_2_SHIFT
#define USBHS_USBCMD_FS2(x)                      USBC_USBCMD_FS_2(x)
#define USBHS_USBCMD_ITC_MASK                    USBC_USBCMD_ITC_MASK
#define USBHS_USBCMD_ITC_SHIFT                   USBC_USBCMD_ITC_SHIFT
#define USBHS_USBCMD_ITC(x)                      USBC_USBCMD_ITC(x)
#define USBHS_USBSTS_UI_MASK                     USBC_USBSTS_UI_MASK
#define USBHS_USBSTS_UI_SHIFT                    USBC_USBSTS_UI_SHIFT
#define USBHS_USBSTS_UI(x)                       USBC_USBSTS_UI(x)
#define USBHS_USBSTS_UEI_MASK                    USBC_USBSTS_UEI_MASK
#define USBHS_USBSTS_UEI_SHIFT                   USBC_USBSTS_UEI_SHIFT
#define USBHS_USBSTS_UEI(x)                      USBC_USBSTS_UEI(x)
#define USBHS_USBSTS_PCI_MASK                    USBC_USBSTS_PCI_MASK
#define USBHS_USBSTS_PCI_SHIFT                   USBC_USBSTS_PCI_SHIFT
#define USBHS_USBSTS_PCI(x)                      USBC_USBSTS_PCI(x)
#define USBHS_USBSTS_FRI_MASK                    USBC_USBSTS_FRI_MASK
#define USBHS_USBSTS_FRI_SHIFT                   USBC_USBSTS_FRI_SHIFT
#define USBHS_USBSTS_FRI(x)                      USBC_USBSTS_FRI(x)
#define USBHS_USBSTS_SEI_MASK                    USBC_USBSTS_SEI_MASK
#define USBHS_USBSTS_SEI_SHIFT                   USBC_USBSTS_SEI_SHIFT
#define USBHS_USBSTS_SEI(x)                      USBC_USBSTS_SEI(x)
#define USBHS_USBSTS_AAI_MASK                    USBC_USBSTS_AAI_MASK
#define USBHS_USBSTS_AAI_SHIFT                   USBC_USBSTS_AAI_SHIFT
#define USBHS_USBSTS_AAI(x)                      USBC_USBSTS_AAI(x)
#define USBHS_USBSTS_URI_MASK                    USBC_USBSTS_URI_MASK
#define USBHS_USBSTS_URI_SHIFT                   USBC_USBSTS_URI_SHIFT
#define USBHS_USBSTS_URI(x)                      USBC_USBSTS_URI(x)
#define USBHS_USBSTS_SRI_MASK                    USBC_USBSTS_SRI_MASK
#define USBHS_USBSTS_SRI_SHIFT                   USBC_USBSTS_SRI_SHIFT
#define USBHS_USBSTS_SRI(x)                      USBC_USBSTS_SRI(x)
#define USBHS_USBSTS_SLI_MASK                    USBC_USBSTS_SLI_MASK
#define USBHS_USBSTS_SLI_SHIFT                   USBC_USBSTS_SLI_SHIFT
#define USBHS_USBSTS_SLI(x)                      USBC_USBSTS_SLI(x)
#define USBHS_USBSTS_ULPII_MASK                  USBC_USBSTS_ULPII_MASK
#define USBHS_USBSTS_ULPII_SHIFT                 USBC_USBSTS_ULPII_SHIFT
#define USBHS_USBSTS_ULPII(x)                    USBC_USBSTS_ULPII(x)
#define USBHS_USBSTS_HCH_MASK                    USBC_USBSTS_HCH_MASK
#define USBHS_USBSTS_HCH_SHIFT                   USBC_USBSTS_HCH_SHIFT
#define USBHS_USBSTS_HCH(x)                      USBC_USBSTS_HCH(x)
#define USBHS_USBSTS_RCL_MASK                    USBC_USBSTS_RCL_MASK
#define USBHS_USBSTS_RCL_SHIFT                   USBC_USBSTS_RCL_SHIFT
#define USBHS_USBSTS_RCL(x)                      USBC_USBSTS_RCL(x)
#define USBHS_USBSTS_PS_MASK                     USBC_USBSTS_PS_MASK
#define USBHS_USBSTS_PS_SHIFT                    USBC_USBSTS_PS_SHIFT
#define USBHS_USBSTS_PS(x)                       USBC_USBSTS_PS(x)
#define USBHS_USBSTS_AS_MASK                     USBC_USBSTS_AS_MASK
#define USBHS_USBSTS_AS_SHIFT                    USBC_USBSTS_AS_SHIFT
#define USBHS_USBSTS_AS(x)                       USBC_USBSTS_AS(x)
#define USBHS_USBSTS_NAKI_MASK                   USBC_USBSTS_NAKI_MASK
#define USBHS_USBSTS_NAKI_SHIFT                  USBC_USBSTS_NAKI_SHIFT
#define USBHS_USBSTS_NAKI(x)                     USBC_USBSTS_NAKI(x)
#define USBHS_USBSTS_TI0_MASK                    USBC_USBSTS_TI0_MASK
#define USBHS_USBSTS_TI0_SHIFT                   USBC_USBSTS_TI0_SHIFT
#define USBHS_USBSTS_TI0(x)                      USBC_USBSTS_TI0(x)
#define USBHS_USBSTS_TI1_MASK                    USBC_USBSTS_TI1_MASK
#define USBHS_USBSTS_TI1_SHIFT                   USBC_USBSTS_TI1_SHIFT
#define USBHS_USBSTS_TI1(x)                      USBC_USBSTS_TI1(x)
#define USBHS_USBINTR_UE_MASK                    USBC_USBINTR_UE_MASK
#define USBHS_USBINTR_UE_SHIFT                   USBC_USBINTR_UE_SHIFT
#define USBHS_USBINTR_UE(x)                      USBC_USBINTR_UE(x)
#define USBHS_USBINTR_UEE_MASK                   USBC_USBINTR_UEE_MASK
#define USBHS_USBINTR_UEE_SHIFT                  USBC_USBINTR_UEE_SHIFT
#define USBHS_USBINTR_UEE(x)                     USBC_USBINTR_UEE(x)
#define USBHS_USBINTR_PCE_MASK                   USBC_USBINTR_PCE_MASK
#define USBHS_USBINTR_PCE_SHIFT                  USBC_USBINTR_PCE_SHIFT
#define USBHS_USBINTR_PCE(x)                     USBC_USBINTR_PCE(x)
#define USBHS_USBINTR_FRE_MASK                   USBC_USBINTR_FRE_MASK
#define USBHS_USBINTR_FRE_SHIFT                  USBC_USBINTR_FRE_SHIFT
#define USBHS_USBINTR_FRE(x)                     USBC_USBINTR_FRE(x)
#define USBHS_USBINTR_SEE_MASK                   USBC_USBINTR_SEE_MASK
#define USBHS_USBINTR_SEE_SHIFT                  USBC_USBINTR_SEE_SHIFT
#define USBHS_USBINTR_SEE(x)                     USBC_USBINTR_SEE(x)
#define USBHS_USBINTR_AAE_MASK                   USBC_USBINTR_AAE_MASK
#define USBHS_USBINTR_AAE_SHIFT                  USBC_USBINTR_AAE_SHIFT
#define USBHS_USBINTR_AAE(x)                     USBC_USBINTR_AAE(x)
#define USBHS_USBINTR_URE_MASK                   USBC_USBINTR_URE_MASK
#define USBHS_USBINTR_URE_SHIFT                  USBC_USBINTR_URE_SHIFT
#define USBHS_USBINTR_URE(x)                     USBC_USBINTR_URE(x)
#define USBHS_USBINTR_SRE_MASK                   USBC_USBINTR_SRE_MASK
#define USBHS_USBINTR_SRE_SHIFT                  USBC_USBINTR_SRE_SHIFT
#define USBHS_USBINTR_SRE(x)                     USBC_USBINTR_SRE(x)
#define USBHS_USBINTR_SLE_MASK                   USBC_USBINTR_SLE_MASK
#define USBHS_USBINTR_SLE_SHIFT                  USBC_USBINTR_SLE_SHIFT
#define USBHS_USBINTR_SLE(x)                     USBC_USBINTR_SLE(x)
#define USBHS_USBINTR_ULPIE_MASK                 USBC_USBINTR_ULPIE_MASK
#define USBHS_USBINTR_ULPIE_SHIFT                USBC_USBINTR_ULPIE_SHIFT
#define USBHS_USBINTR_ULPIE(x)                   USBC_USBINTR_ULPIE(x)
#define USBHS_USBINTR_NAKE_MASK                  USBC_USBINTR_NAKE_MASK
#define USBHS_USBINTR_NAKE_SHIFT                 USBC_USBINTR_NAKE_SHIFT
#define USBHS_USBINTR_NAKE(x)                    USBC_USBINTR_NAKE(x)
#define USBHS_USBINTR_UAIE_MASK                  USBC_USBINTR_UAIE_MASK
#define USBHS_USBINTR_UAIE_SHIFT                 USBC_USBINTR_UAIE_SHIFT
#define USBHS_USBINTR_UAIE(x)                    USBC_USBINTR_UAIE(x)
#define USBHS_USBINTR_UPIE_MASK                  USBC_USBINTR_UPIE_MASK
#define USBHS_USBINTR_UPIE_SHIFT                 USBC_USBINTR_UPIE_SHIFT
#define USBHS_USBINTR_UPIE(x)                    USBC_USBINTR_UPIE(x)
#define USBHS_USBINTR_TIE0_MASK                  USBC_USBINTR_TIE0_MASK
#define USBHS_USBINTR_TIE0_SHIFT                 USBC_USBINTR_TIE0_SHIFT
#define USBHS_USBINTR_TIE0(x)                    USBC_USBINTR_TIE0(x)
#define USBHS_USBINTR_TIE1_MASK                  USBC_USBINTR_TIE1_MASK
#define USBHS_USBINTR_TIE1_SHIFT                 USBC_USBINTR_TIE1_SHIFT
#define USBHS_USBINTR_TIE1(x)                    USBC_USBINTR_TIE1(x)
#define USBHS_FRINDEX_FRINDEX_MASK               USBC_FRINDEX_FRINDEX_MASK
#define USBHS_FRINDEX_FRINDEX_SHIFT              USBC_FRINDEX_FRINDEX_SHIFT
#define USBHS_FRINDEX_FRINDEX(x)                 USBC_FRINDEX_FRINDEX(x)
#define USBHS_DEVICEADDR_USBADRA_MASK            USBC_DEVICEADDR_USBADRA_MASK
#define USBHS_DEVICEADDR_USBADRA_SHIFT           USBC_DEVICEADDR_USBADRA_SHIFT
#define USBHS_DEVICEADDR_USBADRA(x)              USBC_DEVICEADDR_USBADRA(x)
#define USBHS_DEVICEADDR_USBADR_MASK             USBC_DEVICEADDR_USBADR_MASK
#define USBHS_DEVICEADDR_USBADR_SHIFT            USBC_DEVICEADDR_USBADR_SHIFT
#define USBHS_DEVICEADDR_USBADR(x)               USBC_DEVICEADDR_USBADR(x)
#define USBHS_PERIODICLISTBASE_PERBASE_MASK      USBC_PERIODICLISTBASE_PERBASE_MASK
#define USBHS_PERIODICLISTBASE_PERBASE_SHIFT     USBC_PERIODICLISTBASE_PERBASE_SHIFT
#define USBHS_PERIODICLISTBASE_PERBASE(x)        USBC_PERIODICLISTBASE_PERBASE(x)
#define USBHS_ASYNCLISTADDR_ASYBASE_MASK         USBC_ASYNCLISTADDR_ASYBASE_MASK
#define USBHS_ASYNCLISTADDR_ASYBASE_SHIFT        USBC_ASYNCLISTADDR_ASYBASE_SHIFT
#define USBHS_ASYNCLISTADDR_ASYBASE(x)           USBC_ASYNCLISTADDR_ASYBASE(x)
#define USBHS_EPLISTADDR_EPBASE_MASK             USBC_ENDPOINTLISTADDR_EPBASE_MASK
#define USBHS_EPLISTADDR_EPBASE_SHIFT            USBC_ENDPOINTLISTADDR_EPBASE_SHIFT
#define USBHS_EPLISTADDR_EPBASE(x)               USBC_ENDPOINTLISTADDR_EPBASE(x)
#define USBHS_BURSTSIZE_RXPBURST_MASK            USBC_BURSTSIZE_RXPBURST_MASK
#define USBHS_BURSTSIZE_RXPBURST_SHIFT           USBC_BURSTSIZE_RXPBURST_SHIFT
#define USBHS_BURSTSIZE_RXPBURST(x)              USBC_BURSTSIZE_RXPBURST(x)
#define USBHS_BURSTSIZE_TXPBURST_MASK            USBC_BURSTSIZE_TXPBURST_MASK
#define USBHS_BURSTSIZE_TXPBURST_SHIFT           USBC_BURSTSIZE_TXPBURST_SHIFT
#define USBHS_BURSTSIZE_TXPBURST(x)              USBC_BURSTSIZE_TXPBURST(x)
#define USBHS_TXFILLTUNING_TXSCHOH_MASK          USBC_TXFILLTUNING_TXSCHOH_MASK
#define USBHS_TXFILLTUNING_TXSCHOH_SHIFT         USBC_TXFILLTUNING_TXSCHOH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHOH(x)            USBC_TXFILLTUNING_TXSCHOH(x)
#define USBHS_TXFILLTUNING_TXSCHHEALTH_MASK      USBC_TXFILLTUNING_TXSCHHEALTH_MASK
#define USBHS_TXFILLTUNING_TXSCHHEALTH_SHIFT     USBC_TXFILLTUNING_TXSCHHEALTH_SHIFT
#define USBHS_TXFILLTUNING_TXSCHHEALTH(x)        USBC_TXFILLTUNING_TXSCHHEALTH(x)
#define USBHS_TXFILLTUNING_TXFIFOTHRES_MASK      USBC_TXFILLTUNING_TXFIFOTHRES_MASK
#define USBHS_TXFILLTUNING_TXFIFOTHRES_SHIFT     USBC_TXFILLTUNING_TXFIFOTHRES_SHIFT
#define USBHS_TXFILLTUNING_TXFIFOTHRES(x)        USBC_TXFILLTUNING_TXFIFOTHRES(x)
#define USBHS_ENDPTNAK_EPRN_MASK                 USBC_ENDPTNAK_EPRN_MASK
#define USBHS_ENDPTNAK_EPRN_SHIFT                USBC_ENDPTNAK_EPRN_SHIFT
#define USBHS_ENDPTNAK_EPRN(x)                   USBC_ENDPTNAK_EPRN(x)
#define USBHS_ENDPTNAK_EPTN_MASK                 USBC_ENDPTNAK_EPTN_MASK
#define USBHS_ENDPTNAK_EPTN_SHIFT                USBC_ENDPTNAK_EPTN_SHIFT
#define USBHS_ENDPTNAK_EPTN(x)                   USBC_ENDPTNAK_EPTN(x)
#define USBHS_ENDPTNAKEN_EPRNE_MASK              USBC_ENDPTNAKEN_EPRNE_MASK
#define USBHS_ENDPTNAKEN_EPRNE_SHIFT             USBC_ENDPTNAKEN_EPRNE_SHIFT
#define USBHS_ENDPTNAKEN_EPRNE(x)                USBC_ENDPTNAKEN_EPRNE(x)
#define USBHS_ENDPTNAKEN_EPTNE_MASK              USBC_ENDPTNAKEN_EPTNE_MASK
#define USBHS_ENDPTNAKEN_EPTNE_SHIFT             USBC_ENDPTNAKEN_EPTNE_SHIFT
#define USBHS_ENDPTNAKEN_EPTNE(x)                USBC_ENDPTNAKEN_EPTNE(x)
#define USBHS_CONFIGFLAG_CF_MASK                 USBC_CONFIGFLAG_CF_MASK
#define USBHS_CONFIGFLAG_CF_SHIFT                USBC_CONFIGFLAG_CF_SHIFT
#define USBHS_CONFIGFLAG_CF(x)                   USBC_CONFIGFLAG_CF(x)
#define USBHS_PORTSC1_CCS_MASK                   USBC_PORTSC1_CCS_MASK
#define USBHS_PORTSC1_CCS_SHIFT                  USBC_PORTSC1_CCS_SHIFT
#define USBHS_PORTSC1_CCS(x)                     USBC_PORTSC1_CCS(x)
#define USBHS_PORTSC1_CSC_MASK                   USBC_PORTSC1_CSC_MASK
#define USBHS_PORTSC1_CSC_SHIFT                  USBC_PORTSC1_CSC_SHIFT
#define USBHS_PORTSC1_CSC(x)                     USBC_PORTSC1_CSC(x)
#define USBHS_PORTSC1_PE_MASK                    USBC_PORTSC1_PE_MASK
#define USBHS_PORTSC1_PE_SHIFT                   USBC_PORTSC1_PE_SHIFT
#define USBHS_PORTSC1_PE(x)                      USBC_PORTSC1_PE(x)
#define USBHS_PORTSC1_PEC_MASK                   USBC_PORTSC1_PEC_MASK
#define USBHS_PORTSC1_PEC_SHIFT                  USBC_PORTSC1_PEC_SHIFT
#define USBHS_PORTSC1_PEC(x)                     USBC_PORTSC1_PEC(x)
#define USBHS_PORTSC1_OCA_MASK                   USBC_PORTSC1_OCA_MASK
#define USBHS_PORTSC1_OCA_SHIFT                  USBC_PORTSC1_OCA_SHIFT
#define USBHS_PORTSC1_OCA(x)                     USBC_PORTSC1_OCA(x)
#define USBHS_PORTSC1_OCC_MASK                   USBC_PORTSC1_OCC_MASK
#define USBHS_PORTSC1_OCC_SHIFT                  USBC_PORTSC1_OCC_SHIFT
#define USBHS_PORTSC1_OCC(x)                     USBC_PORTSC1_OCC(x)
#define USBHS_PORTSC1_FPR_MASK                   USBC_PORTSC1_FPR_MASK
#define USBHS_PORTSC1_FPR_SHIFT                  USBC_PORTSC1_FPR_SHIFT
#define USBHS_PORTSC1_FPR(x)                     USBC_PORTSC1_FPR(x)
#define USBHS_PORTSC1_SUSP_MASK                  USBC_PORTSC1_SUSP_MASK
#define USBHS_PORTSC1_SUSP_SHIFT                 USBC_PORTSC1_SUSP_SHIFT
#define USBHS_PORTSC1_SUSP(x)                    USBC_PORTSC1_SUSP(x)
#define USBHS_PORTSC1_PR_MASK                    USBC_PORTSC1_PR_MASK
#define USBHS_PORTSC1_PR_SHIFT                   USBC_PORTSC1_PR_SHIFT
#define USBHS_PORTSC1_PR(x)                      USBC_PORTSC1_PR(x)
#define USBHS_PORTSC1_HSP_MASK                   USBC_PORTSC1_HSP_MASK
#define USBHS_PORTSC1_HSP_SHIFT                  USBC_PORTSC1_HSP_SHIFT
#define USBHS_PORTSC1_HSP(x)                     USBC_PORTSC1_HSP(x)
#define USBHS_PORTSC1_LS_MASK                    USBC_PORTSC1_LS_MASK
#define USBHS_PORTSC1_LS_SHIFT                   USBC_PORTSC1_LS_SHIFT
#define USBHS_PORTSC1_LS(x)                      USBC_PORTSC1_LS(x)
#define USBHS_PORTSC1_PP_MASK                    USBC_PORTSC1_PP_MASK
#define USBHS_PORTSC1_PP_SHIFT                   USBC_PORTSC1_PP_SHIFT
#define USBHS_PORTSC1_PP(x)                      USBC_PORTSC1_PP(x)
#define USBHS_PORTSC1_PO_MASK                    USBC_PORTSC1_PO_MASK
#define USBHS_PORTSC1_PO_SHIFT                   USBC_PORTSC1_PO_SHIFT
#define USBHS_PORTSC1_PO(x)                      USBC_PORTSC1_PO(x)
#define USBHS_PORTSC1_PIC_MASK                   USBC_PORTSC1_PIC_MASK
#define USBHS_PORTSC1_PIC_SHIFT                  USBC_PORTSC1_PIC_SHIFT
#define USBHS_PORTSC1_PIC(x)                     USBC_PORTSC1_PIC(x)
#define USBHS_PORTSC1_PTC_MASK                   USBC_PORTSC1_PTC_MASK
#define USBHS_PORTSC1_PTC_SHIFT                  USBC_PORTSC1_PTC_SHIFT
#define USBHS_PORTSC1_PTC(x)                     USBC_PORTSC1_PTC(x)
#define USBHS_PORTSC1_WKCN_MASK                  USBC_PORTSC1_WKCN_MASK
#define USBHS_PORTSC1_WKCN_SHIFT                 USBC_PORTSC1_WKCN_SHIFT
#define USBHS_PORTSC1_WKCN(x)                    USBC_PORTSC1_WKCN(x)
#define USBHS_PORTSC1_WKDS_MASK                  USBC_PORTSC1_WKDS_MASK
#define USBHS_PORTSC1_WKDS_SHIFT                 USBC_PORTSC1_WKDS_SHIFT
#define USBHS_PORTSC1_WKDS(x)                    USBC_PORTSC1_WKDS(x)
#define USBHS_PORTSC1_WKOC_MASK                  USBC_PORTSC1_WKOC_MASK
#define USBHS_PORTSC1_WKOC_SHIFT                 USBC_PORTSC1_WKOC_SHIFT
#define USBHS_PORTSC1_WKOC(x)                    USBC_PORTSC1_WKOC(x)
#define USBHS_PORTSC1_PHCD_MASK                  USBC_PORTSC1_PHCD_MASK
#define USBHS_PORTSC1_PHCD_SHIFT                 USBC_PORTSC1_PHCD_SHIFT
#define USBHS_PORTSC1_PHCD(x)                    USBC_PORTSC1_PHCD(x)
#define USBHS_PORTSC1_PFSC_MASK                  USBC_PORTSC1_PFSC_MASK
#define USBHS_PORTSC1_PFSC_SHIFT                 USBC_PORTSC1_PFSC_SHIFT
#define USBHS_PORTSC1_PFSC(x)                    USBC_PORTSC1_PFSC(x)
#define USBHS_PORTSC1_PTS2_MASK                  USBC_PORTSC1_PTS_2_MASK
#define USBHS_PORTSC1_PTS2_SHIFT                 USBC_PORTSC1_PTS_2_SHIFT
#define USBHS_PORTSC1_PTS2(x)                    USBC_PORTSC1_PTS_2(x)
#define USBHS_PORTSC1_PSPD_MASK                  USBC_PORTSC1_PSPD_MASK
#define USBHS_PORTSC1_PSPD_SHIFT                 USBC_PORTSC1_PSPD_SHIFT
#define USBHS_PORTSC1_PSPD(x)                    USBC_PORTSC1_PSPD(x)
#define USBHS_PORTSC1_PTW_MASK                   USBC_PORTSC1_PTW_MASK
#define USBHS_PORTSC1_PTW_SHIFT                  USBC_PORTSC1_PTW_SHIFT
#define USBHS_PORTSC1_PTW(x)                     USBC_PORTSC1_PTW(x)
#define USBHS_PORTSC1_STS_MASK                   USBC_PORTSC1_STS_MASK
#define USBHS_PORTSC1_STS_SHIFT                  USBC_PORTSC1_STS_SHIFT
#define USBHS_PORTSC1_STS(x)                     USBC_PORTSC1_STS(x)
#define USBHS_PORTSC1_PTS_MASK                   USBC_PORTSC1_PTS_1_MASK
#define USBHS_PORTSC1_PTS_SHIFT                  USBC_PORTSC1_PTS_1_SHIFT
#define USBHS_PORTSC1_PTS(x)                     USBC_PORTSC1_PTS_1(x)
#define USBHS_OTGSC_VD_MASK                      USBC_OTGSC_VD_MASK
#define USBHS_OTGSC_VD_SHIFT                     USBC_OTGSC_VD_SHIFT
#define USBHS_OTGSC_VD(x)                        USBC_OTGSC_VD(x)
#define USBHS_OTGSC_VC_MASK                      USBC_OTGSC_VC_MASK
#define USBHS_OTGSC_VC_SHIFT                     USBC_OTGSC_VC_SHIFT
#define USBHS_OTGSC_VC(x)                        USBC_OTGSC_VC(x)
#define USBHS_OTGSC_OT_MASK                      USBC_OTGSC_OT_MASK
#define USBHS_OTGSC_OT_SHIFT                     USBC_OTGSC_OT_SHIFT
#define USBHS_OTGSC_OT(x)                        USBC_OTGSC_OT(x)
#define USBHS_OTGSC_DP_MASK                      USBC_OTGSC_DP_MASK
#define USBHS_OTGSC_DP_SHIFT                     USBC_OTGSC_DP_SHIFT
#define USBHS_OTGSC_DP(x)                        USBC_OTGSC_DP(x)
#define USBHS_OTGSC_IDPU_MASK                    USBC_OTGSC_IDPU_MASK
#define USBHS_OTGSC_IDPU_SHIFT                   USBC_OTGSC_IDPU_SHIFT
#define USBHS_OTGSC_IDPU(x)                      USBC_OTGSC_IDPU(x)
#define USBHS_OTGSC_ID_MASK                      USBC_OTGSC_ID_MASK
#define USBHS_OTGSC_ID_SHIFT                     USBC_OTGSC_ID_SHIFT
#define USBHS_OTGSC_ID(x)                        USBC_OTGSC_ID(x)
#define USBHS_OTGSC_AVV_MASK                     USBC_OTGSC_AVV_MASK
#define USBHS_OTGSC_AVV_SHIFT                    USBC_OTGSC_AVV_SHIFT
#define USBHS_OTGSC_AVV(x)                       USBC_OTGSC_AVV(x)
#define USBHS_OTGSC_ASV_MASK                     USBC_OTGSC_ASV_MASK
#define USBHS_OTGSC_ASV_SHIFT                    USBC_OTGSC_ASV_SHIFT
#define USBHS_OTGSC_ASV(x)                       USBC_OTGSC_ASV(x)
#define USBHS_OTGSC_BSV_MASK                     USBC_OTGSC_BSV_MASK
#define USBHS_OTGSC_BSV_SHIFT                    USBC_OTGSC_BSV_SHIFT
#define USBHS_OTGSC_BSV(x)                       USBC_OTGSC_BSV(x)
#define USBHS_OTGSC_BSE_MASK                     USBC_OTGSC_BSE_MASK
#define USBHS_OTGSC_BSE_SHIFT                    USBC_OTGSC_BSE_SHIFT
#define USBHS_OTGSC_BSE(x)                       USBC_OTGSC_BSE(x)
#define USBHS_OTGSC_MST_MASK                     USBC_OTGSC_TOG_1MS_MASK
#define USBHS_OTGSC_MST_SHIFT                    USBC_OTGSC_TOG_1MS_SHIFT
#define USBHS_OTGSC_MST(x)                       USBC_OTGSC_TOG_1MS(x)
#define USBHS_OTGSC_DPS_MASK                     USBC_OTGSC_DPS_MASK
#define USBHS_OTGSC_DPS_SHIFT                    USBC_OTGSC_DPS_SHIFT
#define USBHS_OTGSC_DPS(x)                       USBC_OTGSC_DPS(x)
#define USBHS_OTGSC_IDIS_MASK                    USBC_OTGSC_IDIS_MASK
#define USBHS_OTGSC_IDIS_SHIFT                   USBC_OTGSC_IDIS_SHIFT
#define USBHS_OTGSC_IDIS(x)                      USBC_OTGSC_IDIS(x)
#define USBHS_OTGSC_AVVIS_MASK                   USBC_OTGSC_AVVIS_MASK
#define USBHS_OTGSC_AVVIS_SHIFT                  USBC_OTGSC_AVVIS_SHIFT
#define USBHS_OTGSC_AVVIS(x)                     USBC_OTGSC_AVVIS(x)
#define USBHS_OTGSC_ASVIS_MASK                   USBC_OTGSC_ASVIS_MASK
#define USBHS_OTGSC_ASVIS_SHIFT                  USBC_OTGSC_ASVIS_SHIFT
#define USBHS_OTGSC_ASVIS(x)                     USBC_OTGSC_ASVIS(x)
#define USBHS_OTGSC_BSVIS_MASK                   USBC_OTGSC_BSVIS_MASK
#define USBHS_OTGSC_BSVIS_SHIFT                  USBC_OTGSC_BSVIS_SHIFT
#define USBHS_OTGSC_BSVIS(x)                     USBC_OTGSC_BSVIS(x)
#define USBHS_OTGSC_BSEIS_MASK                   USBC_OTGSC_BSEIS_MASK
#define USBHS_OTGSC_BSEIS_SHIFT                  USBC_OTGSC_BSEIS_SHIFT
#define USBHS_OTGSC_BSEIS(x)                     USBC_OTGSC_BSEIS(x)
#define USBHS_OTGSC_MSS_MASK                     USBC_OTGSC_STATUS_1MS_MASK
#define USBHS_OTGSC_MSS_SHIFT                    USBC_OTGSC_STATUS_1MS_SHIFT
#define USBHS_OTGSC_MSS(x)                       USBC_OTGSC_STATUS_1MS(x)
#define USBHS_OTGSC_DPIS_MASK                    USBC_OTGSC_DPIS_MASK
#define USBHS_OTGSC_DPIS_SHIFT                   USBC_OTGSC_DPIS_SHIFT
#define USBHS_OTGSC_DPIS(x)                      USBC_OTGSC_DPIS(x)
#define USBHS_OTGSC_IDIE_MASK                    USBC_OTGSC_IDIE_MASK
#define USBHS_OTGSC_IDIE_SHIFT                   USBC_OTGSC_IDIE_SHIFT
#define USBHS_OTGSC_IDIE(x)                      USBC_OTGSC_IDIE(x)
#define USBHS_OTGSC_AVVIE_MASK                   USBC_OTGSC_AVVIE_MASK
#define USBHS_OTGSC_AVVIE_SHIFT                  USBC_OTGSC_AVVIE_SHIFT
#define USBHS_OTGSC_AVVIE(x)                     USBC_OTGSC_AVVIE(x)
#define USBHS_OTGSC_ASVIE_MASK                   USBC_OTGSC_ASVIE_MASK
#define USBHS_OTGSC_ASVIE_SHIFT                  USBC_OTGSC_ASVIE_SHIFT
#define USBHS_OTGSC_ASVIE(x)                     USBC_OTGSC_ASVIE(x)
#define USBHS_OTGSC_BSVIE_MASK                   USBC_OTGSC_BSVIE_MASK
#define USBHS_OTGSC_BSVIE_SHIFT                  USBC_OTGSC_BSVIE_SHIFT
#define USBHS_OTGSC_BSVIE(x)                     USBC_OTGSC_BSVIE(x)
#define USBHS_OTGSC_BSEIE_MASK                   USBC_OTGSC_BSEIE_MASK
#define USBHS_OTGSC_BSEIE_SHIFT                  USBC_OTGSC_BSEIE_SHIFT
#define USBHS_OTGSC_BSEIE(x)                     USBC_OTGSC_BSEIE(x)
#define USBHS_OTGSC_MSE_MASK                     USBC_OTGSC_EN_1MS_MASK
#define USBHS_OTGSC_MSE_SHIFT                    USBC_OTGSC_EN_1MS_SHIFT
#define USBHS_OTGSC_MSE(x)                       USBC_OTGSC_EN_1MS(x)
#define USBHS_OTGSC_DPIE_MASK                    USBC_OTGSC_DPIE_MASK
#define USBHS_OTGSC_DPIE_SHIFT                   USBC_OTGSC_DPIE_SHIFT
#define USBHS_OTGSC_DPIE(x)                      USBC_OTGSC_DPIE(x)
#define USBHS_USBMODE_CM_MASK                    USBC_USBMODE_CM_MASK
#define USBHS_USBMODE_CM_SHIFT                   USBC_USBMODE_CM_SHIFT
#define USBHS_USBMODE_CM(x)                      USBC_USBMODE_CM(x)
#define USBHS_USBMODE_ES_MASK                    USBC_USBMODE_ES_MASK
#define USBHS_USBMODE_ES_SHIFT                   USBC_USBMODE_ES_SHIFT
#define USBHS_USBMODE_ES(x)                      USBC_USBMODE_ES(x)
#define USBHS_USBMODE_SLOM_MASK                  USBC_USBMODE_SLOM_MASK
#define USBHS_USBMODE_SLOM_SHIFT                 USBC_USBMODE_SLOM_SHIFT
#define USBHS_USBMODE_SLOM(x)                    USBC_USBMODE_SLOM(x)
#define USBHS_USBMODE_SDIS_MASK                  USBC_USBMODE_SDIS_MASK
#define USBHS_USBMODE_SDIS_SHIFT                 USBC_USBMODE_SDIS_SHIFT
#define USBHS_USBMODE_SDIS(x)                    USBC_USBMODE_SDIS(x)
#define USBHS_EPSETUPSR_EPSETUPSTAT_MASK         USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_MASK
#define USBHS_EPSETUPSR_EPSETUPSTAT_SHIFT        USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT_SHIFT
#define USBHS_EPSETUPSR_EPSETUPSTAT(x)           USBC_ENDPTSETUPSTAT_ENDPTSETUPSTAT(x)
#define USBHS_EPPRIME_PERB_MASK                  USBC_ENDPTPRIME_PERB_MASK
#define USBHS_EPPRIME_PERB_SHIFT                 USBC_ENDPTPRIME_PERB_SHIFT
#define USBHS_EPPRIME_PERB(x)                    USBC_ENDPTPRIME_PERB(x)
#define USBHS_EPPRIME_PETB_MASK                  USBC_ENDPTPRIME_PETB_MASK
#define USBHS_EPPRIME_PETB_SHIFT                 USBC_ENDPTPRIME_PETB_SHIFT
#define USBHS_EPPRIME_PETB(x)                    USBC_ENDPTPRIME_PETB(x)
#define USBHS_EPFLUSH_FERB_MASK                  USBC_ENDPTFLUSH_FERB_MASK
#define USBHS_EPFLUSH_FERB_SHIFT                 USBC_ENDPTFLUSH_FERB_SHIFT
#define USBHS_EPFLUSH_FERB(x)                    USBC_ENDPTFLUSH_FERB(x)
#define USBHS_EPFLUSH_FETB_MASK                  USBC_ENDPTFLUSH_FETB_MASK
#define USBHS_EPFLUSH_FETB_SHIFT                 USBC_ENDPTFLUSH_FETB_SHIFT
#define USBHS_EPFLUSH_FETB(x)                    USBC_ENDPTFLUSH_FETB(x)
#define USBHS_EPSR_ERBR_MASK                     USBC_ENDPTSTAT_ERBR_MASK
#define USBHS_EPSR_ERBR_SHIFT                    USBC_ENDPTSTAT_ERBR_SHIFT
#define USBHS_EPSR_ERBR(x)                       USBC_ENDPTSTAT_ERBR(x)
#define USBHS_EPSR_ETBR_MASK                     USBC_ENDPTSTAT_ETBR_MASK
#define USBHS_EPSR_ETBR_SHIFT                    USBC_ENDPTSTAT_ETBR_SHIFT
#define USBHS_EPSR_ETBR(x)                       USBC_ENDPTSTAT_ETBR(x)
#define USBHS_EPCOMPLETE_ERCE_MASK               USBC_ENDPTCOMPLETE_ERCE_MASK
#define USBHS_EPCOMPLETE_ERCE_SHIFT              USBC_ENDPTCOMPLETE_ERCE_SHIFT
#define USBHS_EPCOMPLETE_ERCE(x)                 USBC_ENDPTCOMPLETE_ERCE(x)
#define USBHS_EPCOMPLETE_ETCE_MASK               USBC_ENDPTCOMPLETE_ETCE_MASK
#define USBHS_EPCOMPLETE_ETCE_SHIFT              USBC_ENDPTCOMPLETE_ETCE_SHIFT
#define USBHS_EPCOMPLETE_ETCE(x)                 USBC_ENDPTCOMPLETE_ETCE(x)
#define USBHS_EPCR0_RXS_MASK                     USBC_ENDPTCTRL0_RXS_MASK
#define USBHS_EPCR0_RXS_SHIFT                    USBC_ENDPTCTRL0_RXS_SHIFT
#define USBHS_EPCR0_RXS(x)                       USBC_ENDPTCTRL0_RXS(x)
#define USBHS_EPCR0_RXT_MASK                     USBC_ENDPTCTRL0_RXT_MASK
#define USBHS_EPCR0_RXT_SHIFT                    USBC_ENDPTCTRL0_RXT_SHIFT
#define USBHS_EPCR0_RXT(x)                       USBC_ENDPTCTRL0_RXT(x)
#define USBHS_EPCR0_RXE_MASK                     USBC_ENDPTCTRL0_RXE_MASK
#define USBHS_EPCR0_RXE_SHIFT                    USBC_ENDPTCTRL0_RXE_SHIFT
#define USBHS_EPCR0_RXE(x)                       USBC_ENDPTCTRL0_RXE(x)
#define USBHS_EPCR0_TXS_MASK                     USBC_ENDPTCTRL0_TXS_MASK
#define USBHS_EPCR0_TXS_SHIFT                    USBC_ENDPTCTRL0_TXS_SHIFT
#define USBHS_EPCR0_TXS(x)                       USBC_ENDPTCTRL0_TXS(x)
#define USBHS_EPCR0_TXT_MASK                     USBC_ENDPTCTRL0_TXT_MASK
#define USBHS_EPCR0_TXT_SHIFT                    USBC_ENDPTCTRL0_TXT_SHIFT
#define USBHS_EPCR0_TXT(x)                       USBC_ENDPTCTRL0_TXT(x)
#define USBHS_EPCR0_TXE_MASK                     USBC_ENDPTCTRL0_TXE_MASK
#define USBHS_EPCR0_TXE_SHIFT                    USBC_ENDPTCTRL0_TXE_SHIFT
#define USBHS_EPCR0_TXE(x)                       USBC_ENDPTCTRL0_TXE(x)
#define USBHS_EPCR_RXS_MASK                      USBC_ENDPTCTRL_RXS_MASK
#define USBHS_EPCR_RXS_SHIFT                     USBC_ENDPTCTRL_RXS_SHIFT
#define USBHS_EPCR_RXS(x)                        USBC_ENDPTCTRL_RXS(x)
#define USBHS_EPCR_RXD_MASK                      USBC_ENDPTCTRL_RXD_MASK
#define USBHS_EPCR_RXD_SHIFT                     USBC_ENDPTCTRL_RXD_SHIFT
#define USBHS_EPCR_RXD(x)                        USBC_ENDPTCTRL_RXD(x)
#define USBHS_EPCR_RXT_MASK                      USBC_ENDPTCTRL_RXT_MASK
#define USBHS_EPCR_RXT_SHIFT                     USBC_ENDPTCTRL_RXT_SHIFT
#define USBHS_EPCR_RXT(x)                        USBC_ENDPTCTRL_RXT(x)
#define USBHS_EPCR_RXI_MASK                      USBC_ENDPTCTRL_RXI_MASK
#define USBHS_EPCR_RXI_SHIFT                     USBC_ENDPTCTRL_RXI_SHIFT
#define USBHS_EPCR_RXI(x)                        USBC_ENDPTCTRL_RXI(x)
#define USBHS_EPCR_RXR_MASK                      USBC_ENDPTCTRL_RXR_MASK
#define USBHS_EPCR_RXR_SHIFT                     USBC_ENDPTCTRL_RXR_SHIFT
#define USBHS_EPCR_RXR(x)                        USBC_ENDPTCTRL_RXR(x)
#define USBHS_EPCR_RXE_MASK                      USBC_ENDPTCTRL_RXE_MASK
#define USBHS_EPCR_RXE_SHIFT                     USBC_ENDPTCTRL_RXE_SHIFT
#define USBHS_EPCR_RXE(x)                        USBC_ENDPTCTRL_RXE(x)
#define USBHS_EPCR_TXS_MASK                      USBC_ENDPTCTRL_TXS_MASK
#define USBHS_EPCR_TXS_SHIFT                     USBC_ENDPTCTRL_TXS_SHIFT
#define USBHS_EPCR_TXS(x)                        USBC_ENDPTCTRL_TXS(x)
#define USBHS_EPCR_TXD_MASK                      USBC_ENDPTCTRL_TXD_MASK
#define USBHS_EPCR_TXD_SHIFT                     USBC_ENDPTCTRL_TXD_SHIFT
#define USBHS_EPCR_TXD(x)                        USBC_ENDPTCTRL_TXD(x)
#define USBHS_EPCR_TXT_MASK                      USBC_ENDPTCTRL_TXT_MASK
#define USBHS_EPCR_TXT_SHIFT                     USBC_ENDPTCTRL_TXT_SHIFT
#define USBHS_EPCR_TXT(x)                        USBC_ENDPTCTRL_TXT(x)
#define USBHS_EPCR_TXI_MASK                      USBC_ENDPTCTRL_TXI_MASK
#define USBHS_EPCR_TXI_SHIFT                     USBC_ENDPTCTRL_TXI_SHIFT
#define USBHS_EPCR_TXI(x)                        USBC_ENDPTCTRL_TXI(x)
#define USBHS_EPCR_TXR_MASK                      USBC_ENDPTCTRL_TXR_MASK
#define USBHS_EPCR_TXR_SHIFT                     USBC_ENDPTCTRL_TXR_SHIFT
#define USBHS_EPCR_TXR(x)                        USBC_ENDPTCTRL_TXR(x)
#define USBHS_EPCR_TXE_MASK                      USBC_ENDPTCTRL_TXE_MASK
#define USBHS_EPCR_TXE_SHIFT                     USBC_ENDPTCTRL_TXE_SHIFT
#define USBHS_EPCR_TXE(x)                        USBC_ENDPTCTRL_TXE(x)
#define USBHS_EPCR_COUNT                         USBC_ENDPTCTRL_COUNT
#define USBHS_Type                               USBC_Type
#define USBHS_BASE_ADDRS                         { USBOTG_BASE }
#define USBHS_IRQS                               { USB_IRQn }
#define USBHS_IRQHandler                         USB_IRQHandler


/*!
 * @}
 */ /* end of group USBC_Peripheral_Access_Layer */


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


#endif  /* PERI_USBC_H_ */

