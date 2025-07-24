/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ESPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ESPI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ESPI
 *
 * CMSIS Peripheral Access Layer for ESPI
 */

#if !defined(PERI_ESPI_H_)
#define PERI_ESPI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
   -- ESPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ESPI_Peripheral_Access_Layer ESPI Peripheral Access Layer
 * @{
 */

/** ESPI - Size of Registers Arrays */
#define ESPI_PORT_COUNT                           5u

/** ESPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCTRL;                             /**< Master Control for whole peripheral, offset: 0x0 */
  __IO uint32_t MSTAT;                             /**< Master Status of whole peripheral, offset: 0x4 */
  __IO uint32_t INTENSET;                          /**< Interrupt Set (enable), offset: 0x8 */
  __IO uint32_t INTENCLR;                          /**< Interrupt Clear (disable), offset: 0xC */
  __IO uint32_t INTSTAT;                           /**< Masked interrupt status (causes), offset: 0x10 */
  __IO uint32_t DMACTRL;                           /**< Selects DMA for Ports (if used), offset: 0x14 */
  __IO uint32_t RAMBASE;                           /**< Address of RAM to use for data. This tells the application where the RAM is located (up to 16K addressable)., offset: 0x18 */
  __IO uint32_t MAPBASE;                           /**< Base0 and Base1 mapped offsets for ports, offset: 0x1C */
  __IO uint32_t IRQPUSH;                           /**< IRQ to drive into Host (with eSPI), offset: 0x20 */
  __IO uint32_t WIREWO;                            /**< Wire states for Host to see; if LPC, this is the IRQ states., offset: 0x24 */
  __I  uint32_t WIRERO;                            /**< Wire states from Host, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t P80STAT;                           /**< Port 80 Status (byte and prev byte), offset: 0x30 */
  __IO uint32_t STATADDR;                          /**< Location of Status block in memory space, if enabled., offset: 0x34 */
       uint8_t RESERVED_1[8];
  __IO uint32_t ESPICAP;                           /**< eSPI Capabilities of MCU to send to Host, offset: 0x40 */
  __I  uint32_t ESPICFG;                           /**< eSPI Configuration settings from eSPI, offset: 0x44 */
  __IO uint32_t ESPIMISC;                          /**< Miscellaneous uses, such as Alert pin as GPIO (when not used for Alert)., offset: 0x48 */
       uint8_t RESERVED_2[180];
  struct {                                         /* offset: 0x100, array step: 0x20 */
    __IO uint32_t CFG;                               /**< array offset: 0x100, array step: 0x20 */
    __IO uint32_t STAT;                              /**< array offset: 0x104, array step: 0x20 */
    __IO uint32_t IRULESTAT;                         /**< array offset: 0x108, array step: 0x20 */
    union {                                          /* offset: 0x10C, array step: 0x20 */
      __IO uint32_t ADDR;                              /**< array offset: 0x10C, array step: 0x20 */
      __IO uint32_t OMFLEN;                            /**< array offset: 0x10C, array step: 0x20 */
    };
    __I  uint32_t DATAIN;                            /**< array offset: 0x110, array step: 0x20 */
    union {                                          /* offset: 0x114, array step: 0x20 */
      __IO uint32_t DATAOUT;                           /**< array offset: 0x114, array step: 0x20 */
      __IO uint32_t RAMUSE;                            /**< array offset: 0x114, array step: 0x20 */
    };
         uint8_t RESERVED_0[8];
  } PORT[ESPI_PORT_COUNT];
} ESPI_Type;

/* ----------------------------------------------------------------------------
   -- ESPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ESPI_Register_Masks ESPI Register Masks
 * @{
 */

/*! @name MCTRL - Master Control for whole peripheral */
/*! @{ */

#define ESPI_MCTRL_ENABLE_MASK                   (0x3U)
#define ESPI_MCTRL_ENABLE_SHIFT                  (0U)
/*! ENABLE
 *  0b00..Disabled. Block is not operational
 *  0b01..eSPI
 *  0b10..LPC
 *  0b11..Reserved
 */
#define ESPI_MCTRL_ENABLE(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_ENABLE_SHIFT)) & ESPI_MCTRL_ENABLE_MASK)

#define ESPI_MCTRL_PENA_MASK                     (0x1F00U)
#define ESPI_MCTRL_PENA_SHIFT                    (8U)
/*! PENA - Port enable bits. */
#define ESPI_MCTRL_PENA(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_PENA_SHIFT)) & ESPI_MCTRL_PENA_MASK)

#define ESPI_MCTRL_P80ENA_MASK                   (0x10000U)
#define ESPI_MCTRL_P80ENA_SHIFT                  (16U)
/*! P80ENA - Port 80 enable. */
#define ESPI_MCTRL_P80ENA(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_P80ENA_SHIFT)) & ESPI_MCTRL_P80ENA_MASK)

#define ESPI_MCTRL_SBLKENA_MASK                  (0x20000U)
#define ESPI_MCTRL_SBLKENA_SHIFT                 (17U)
/*! SBLKENA - Status block is enabled and mapped according to the STATADDR register. */
#define ESPI_MCTRL_SBLKENA(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_SBLKENA_SHIFT)) & ESPI_MCTRL_SBLKENA_MASK)

#define ESPI_MCTRL_USE60MHZ_MASK                 (0x100000U)
#define ESPI_MCTRL_USE60MHZ_SHIFT                (20U)
#define ESPI_MCTRL_USE60MHZ(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_MCTRL_USE60MHZ_SHIFT)) & ESPI_MCTRL_USE60MHZ_MASK)
/*! @} */

/*! @name MSTAT - Master Status of whole peripheral */
/*! @{ */

#define ESPI_MSTAT_PORTINT_MASK                  (0x1FU)
#define ESPI_MSTAT_PORTINT_SHIFT                 (0U)
#define ESPI_MSTAT_PORTINT(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_PORTINT_SHIFT)) & ESPI_MSTAT_PORTINT_MASK)

#define ESPI_MSTAT_P80INT_MASK                   (0x100U)
#define ESPI_MSTAT_P80INT_SHIFT                  (8U)
#define ESPI_MSTAT_P80INT(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_P80INT_SHIFT)) & ESPI_MSTAT_P80INT_MASK)

#define ESPI_MSTAT_BUSRST_MASK                   (0x200U)
#define ESPI_MSTAT_BUSRST_SHIFT                  (9U)
#define ESPI_MSTAT_BUSRST(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_BUSRST_SHIFT)) & ESPI_MSTAT_BUSRST_MASK)

#define ESPI_MSTAT_IRQUPD_MASK                   (0x400U)
#define ESPI_MSTAT_IRQUPD_SHIFT                  (10U)
#define ESPI_MSTAT_IRQUPD(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_IRQUPD_SHIFT)) & ESPI_MSTAT_IRQUPD_MASK)

#define ESPI_MSTAT_WIRECHG_MASK                  (0x800U)
#define ESPI_MSTAT_WIRECHG_SHIFT                 (11U)
#define ESPI_MSTAT_WIRECHG(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_WIRECHG_SHIFT)) & ESPI_MSTAT_WIRECHG_MASK)

#define ESPI_MSTAT_HSTALL_MASK                   (0x1000U)
#define ESPI_MSTAT_HSTALL_SHIFT                  (12U)
#define ESPI_MSTAT_HSTALL(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_HSTALL_SHIFT)) & ESPI_MSTAT_HSTALL_MASK)

#define ESPI_MSTAT_CRCERR_MASK                   (0x2000U)
#define ESPI_MSTAT_CRCERR_SHIFT                  (13U)
#define ESPI_MSTAT_CRCERR(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_CRCERR_SHIFT)) & ESPI_MSTAT_CRCERR_MASK)

#define ESPI_MSTAT_GPIO_MASK                     (0x4000U)
#define ESPI_MSTAT_GPIO_SHIFT                    (14U)
#define ESPI_MSTAT_GPIO(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_GPIO_SHIFT)) & ESPI_MSTAT_GPIO_MASK)

#define ESPI_MSTAT_BUSY_MASK                     (0x10000U)
#define ESPI_MSTAT_BUSY_SHIFT                    (16U)
#define ESPI_MSTAT_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_BUSY_SHIFT)) & ESPI_MSTAT_BUSY_MASK)

#define ESPI_MSTAT_INRST_MASK                    (0x20000U)
#define ESPI_MSTAT_INRST_SHIFT                   (17U)
#define ESPI_MSTAT_INRST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_INRST_SHIFT)) & ESPI_MSTAT_INRST_MASK)

#define ESPI_MSTAT_COMPPEND_MASK                 (0x40000U)
#define ESPI_MSTAT_COMPPEND_SHIFT                (18U)
#define ESPI_MSTAT_COMPPEND(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_COMPPEND_SHIFT)) & ESPI_MSTAT_COMPPEND_MASK)

#define ESPI_MSTAT_MASTPEND_MASK                 (0x80000U)
#define ESPI_MSTAT_MASTPEND_SHIFT                (19U)
#define ESPI_MSTAT_MASTPEND(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_MASTPEND_SHIFT)) & ESPI_MSTAT_MASTPEND_MASK)

#define ESPI_MSTAT_ALERTPEND_MASK                (0x100000U)
#define ESPI_MSTAT_ALERTPEND_SHIFT               (20U)
#define ESPI_MSTAT_ALERTPEND(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_MSTAT_ALERTPEND_SHIFT)) & ESPI_MSTAT_ALERTPEND_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Set (enable) */
/*! @{ */

#define ESPI_INTENSET_PORTINT_MASK               (0x1FU)
#define ESPI_INTENSET_PORTINT_SHIFT              (0U)
#define ESPI_INTENSET_PORTINT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_PORTINT_SHIFT)) & ESPI_INTENSET_PORTINT_MASK)

#define ESPI_INTENSET_P80INT_MASK                (0x100U)
#define ESPI_INTENSET_P80INT_SHIFT               (8U)
#define ESPI_INTENSET_P80INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_P80INT_SHIFT)) & ESPI_INTENSET_P80INT_MASK)

#define ESPI_INTENSET_BUSRST_MASK                (0x200U)
#define ESPI_INTENSET_BUSRST_SHIFT               (9U)
#define ESPI_INTENSET_BUSRST(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_BUSRST_SHIFT)) & ESPI_INTENSET_BUSRST_MASK)

#define ESPI_INTENSET_IRQUPD_MASK                (0x400U)
#define ESPI_INTENSET_IRQUPD_SHIFT               (10U)
#define ESPI_INTENSET_IRQUPD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_IRQUPD_SHIFT)) & ESPI_INTENSET_IRQUPD_MASK)

#define ESPI_INTENSET_WIRECHG_MASK               (0x800U)
#define ESPI_INTENSET_WIRECHG_SHIFT              (11U)
#define ESPI_INTENSET_WIRECHG(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_WIRECHG_SHIFT)) & ESPI_INTENSET_WIRECHG_MASK)

#define ESPI_INTENSET_HSTALL_MASK                (0x1000U)
#define ESPI_INTENSET_HSTALL_SHIFT               (12U)
#define ESPI_INTENSET_HSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_HSTALL_SHIFT)) & ESPI_INTENSET_HSTALL_MASK)

#define ESPI_INTENSET_CRCERR_MASK                (0x2000U)
#define ESPI_INTENSET_CRCERR_SHIFT               (13U)
#define ESPI_INTENSET_CRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_CRCERR_SHIFT)) & ESPI_INTENSET_CRCERR_MASK)

#define ESPI_INTENSET_GPIO_MASK                  (0x4000U)
#define ESPI_INTENSET_GPIO_SHIFT                 (14U)
#define ESPI_INTENSET_GPIO(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_INTENSET_GPIO_SHIFT)) & ESPI_INTENSET_GPIO_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Clear (disable) */
/*! @{ */

#define ESPI_INTENCLR_PORTINT_MASK               (0x1FU)
#define ESPI_INTENCLR_PORTINT_SHIFT              (0U)
#define ESPI_INTENCLR_PORTINT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_PORTINT_SHIFT)) & ESPI_INTENCLR_PORTINT_MASK)

#define ESPI_INTENCLR_P80INT_MASK                (0x100U)
#define ESPI_INTENCLR_P80INT_SHIFT               (8U)
#define ESPI_INTENCLR_P80INT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_P80INT_SHIFT)) & ESPI_INTENCLR_P80INT_MASK)

#define ESPI_INTENCLR_BUSRST_MASK                (0x200U)
#define ESPI_INTENCLR_BUSRST_SHIFT               (9U)
#define ESPI_INTENCLR_BUSRST(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_BUSRST_SHIFT)) & ESPI_INTENCLR_BUSRST_MASK)

#define ESPI_INTENCLR_IRQUPD_MASK                (0x400U)
#define ESPI_INTENCLR_IRQUPD_SHIFT               (10U)
#define ESPI_INTENCLR_IRQUPD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_IRQUPD_SHIFT)) & ESPI_INTENCLR_IRQUPD_MASK)

#define ESPI_INTENCLR_WIRECHG_MASK               (0x800U)
#define ESPI_INTENCLR_WIRECHG_SHIFT              (11U)
#define ESPI_INTENCLR_WIRECHG(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_WIRECHG_SHIFT)) & ESPI_INTENCLR_WIRECHG_MASK)

#define ESPI_INTENCLR_HSTALL_MASK                (0x1000U)
#define ESPI_INTENCLR_HSTALL_SHIFT               (12U)
#define ESPI_INTENCLR_HSTALL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_HSTALL_SHIFT)) & ESPI_INTENCLR_HSTALL_MASK)

#define ESPI_INTENCLR_CRCERR_MASK                (0x2000U)
#define ESPI_INTENCLR_CRCERR_SHIFT               (13U)
#define ESPI_INTENCLR_CRCERR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_CRCERR_SHIFT)) & ESPI_INTENCLR_CRCERR_MASK)

#define ESPI_INTENCLR_GPIO_MASK                  (0x4000U)
#define ESPI_INTENCLR_GPIO_SHIFT                 (14U)
#define ESPI_INTENCLR_GPIO(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_INTENCLR_GPIO_SHIFT)) & ESPI_INTENCLR_GPIO_MASK)
/*! @} */

/*! @name INTSTAT - Masked interrupt status (causes) */
/*! @{ */

#define ESPI_INTSTAT_PORTINT_MASK                (0x1FU)
#define ESPI_INTSTAT_PORTINT_SHIFT               (0U)
#define ESPI_INTSTAT_PORTINT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_PORTINT_SHIFT)) & ESPI_INTSTAT_PORTINT_MASK)

#define ESPI_INTSTAT_P80INT_MASK                 (0x100U)
#define ESPI_INTSTAT_P80INT_SHIFT                (8U)
#define ESPI_INTSTAT_P80INT(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_P80INT_SHIFT)) & ESPI_INTSTAT_P80INT_MASK)

#define ESPI_INTSTAT_BUSRST_MASK                 (0x200U)
#define ESPI_INTSTAT_BUSRST_SHIFT                (9U)
#define ESPI_INTSTAT_BUSRST(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_BUSRST_SHIFT)) & ESPI_INTSTAT_BUSRST_MASK)

#define ESPI_INTSTAT_IRQUPD_MASK                 (0x400U)
#define ESPI_INTSTAT_IRQUPD_SHIFT                (10U)
#define ESPI_INTSTAT_IRQUPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_IRQUPD_SHIFT)) & ESPI_INTSTAT_IRQUPD_MASK)

#define ESPI_INTSTAT_WIRECHG_MASK                (0x800U)
#define ESPI_INTSTAT_WIRECHG_SHIFT               (11U)
#define ESPI_INTSTAT_WIRECHG(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_WIRECHG_SHIFT)) & ESPI_INTSTAT_WIRECHG_MASK)

#define ESPI_INTSTAT_HSTALL_MASK                 (0x1000U)
#define ESPI_INTSTAT_HSTALL_SHIFT                (12U)
#define ESPI_INTSTAT_HSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_HSTALL_SHIFT)) & ESPI_INTSTAT_HSTALL_MASK)

#define ESPI_INTSTAT_CRCERR_MASK                 (0x2000U)
#define ESPI_INTSTAT_CRCERR_SHIFT                (13U)
#define ESPI_INTSTAT_CRCERR(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_CRCERR_SHIFT)) & ESPI_INTSTAT_CRCERR_MASK)

#define ESPI_INTSTAT_GPIO_MASK                   (0x4000U)
#define ESPI_INTSTAT_GPIO_SHIFT                  (14U)
#define ESPI_INTSTAT_GPIO(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_INTSTAT_GPIO_SHIFT)) & ESPI_INTSTAT_GPIO_MASK)
/*! @} */

/*! @name DMACTRL - Selects DMA for Ports (if used) */
/*! @{ */

#define ESPI_DMACTRL_DMA0EN_MASK                 (0x3U)
#define ESPI_DMACTRL_DMA0EN_SHIFT                (0U)
/*! DMA0EN
 *  0b00..Disabled. The DMA channel is not used
 *  0b01..Triggers on Host Read empty (whether endpoint and a byte or mailbox and many bytes). Allows reload of memory
 *  0b10..Triggers on Host Write complete/ready (whether endpoint and a byte or mailbox and many bytes).
 *  0b11..reserved
 */
#define ESPI_DMACTRL_DMA0EN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA0EN_SHIFT)) & ESPI_DMACTRL_DMA0EN_MASK)

#define ESPI_DMACTRL_DMA1EN_MASK                 (0xCU)
#define ESPI_DMACTRL_DMA1EN_SHIFT                (2U)
/*! DMA1EN
 *  0b00..Disabled. The DMA channel is not used
 *  0b01..Triggers on Host Read empty (whether endpoint and a byte or mailbox and many bytes). Allows reload of memory
 *  0b10..Triggers on Host Write complete/ready (whether endpoint and a byte or mailbox and many bytes).
 *  0b11..reserved
 */
#define ESPI_DMACTRL_DMA1EN(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA1EN_SHIFT)) & ESPI_DMACTRL_DMA1EN_MASK)

#define ESPI_DMACTRL_DMA0PORT_MASK               (0xF00U)
#define ESPI_DMACTRL_DMA0PORT_SHIFT              (8U)
#define ESPI_DMACTRL_DMA0PORT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA0PORT_SHIFT)) & ESPI_DMACTRL_DMA0PORT_MASK)

#define ESPI_DMACTRL_DMA1PORT_MASK               (0xF000U)
#define ESPI_DMACTRL_DMA1PORT_SHIFT              (12U)
#define ESPI_DMACTRL_DMA1PORT(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_DMA1PORT_SHIFT)) & ESPI_DMACTRL_DMA1PORT_MASK)

#define ESPI_DMACTRL_CNT0_MASK                   (0x7F0000U)
#define ESPI_DMACTRL_CNT0_SHIFT                  (16U)
#define ESPI_DMACTRL_CNT0(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_CNT0_SHIFT)) & ESPI_DMACTRL_CNT0_MASK)

#define ESPI_DMACTRL_CNT1_MASK                   (0x7F000000U)
#define ESPI_DMACTRL_CNT1_SHIFT                  (24U)
#define ESPI_DMACTRL_CNT1(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DMACTRL_CNT1_SHIFT)) & ESPI_DMACTRL_CNT1_MASK)
/*! @} */

/*! @name RAMBASE - Address of RAM to use for data. This tells the application where the RAM is located (up to 16K addressable). */
/*! @{ */

#define ESPI_RAMBASE_ZERO_MASK                   (0xFFFU)
#define ESPI_RAMBASE_ZERO_SHIFT                  (0U)
/*! ZERO - Always 0 */
#define ESPI_RAMBASE_ZERO(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_RAMBASE_ZERO_SHIFT)) & ESPI_RAMBASE_ZERO_MASK)

#define ESPI_RAMBASE_RAM_MASK                    (0xFFFFF000U)
#define ESPI_RAMBASE_RAM_SHIFT                   (12U)
#define ESPI_RAMBASE_RAM(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_RAMBASE_RAM_SHIFT)) & ESPI_RAMBASE_RAM_MASK)
/*! @} */

/*! @name MAPBASE - Base0 and Base1 mapped offsets for ports */
/*! @{ */

#define ESPI_MAPBASE_BASE0_MASK                  (0xFFFFU)
#define ESPI_MAPBASE_BASE0_SHIFT                 (0U)
#define ESPI_MAPBASE_BASE0(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MAPBASE_BASE0_SHIFT)) & ESPI_MAPBASE_BASE0_MASK)

#define ESPI_MAPBASE_BASE1_MASK                  (0xFFFF0000U)
#define ESPI_MAPBASE_BASE1_SHIFT                 (16U)
#define ESPI_MAPBASE_BASE1(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_MAPBASE_BASE1_SHIFT)) & ESPI_MAPBASE_BASE1_MASK)
/*! @} */

/*! @name IRQPUSH - IRQ to drive into Host (with eSPI) */
/*! @{ */

#define ESPI_IRQPUSH_IRQ_MASK                    (0xFFU)
#define ESPI_IRQPUSH_IRQ_SHIFT                   (0U)
#define ESPI_IRQPUSH_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_IRQPUSH_IRQ_SHIFT)) & ESPI_IRQPUSH_IRQ_MASK)

#define ESPI_IRQPUSH_DONE_MASK                   (0x100U)
#define ESPI_IRQPUSH_DONE_SHIFT                  (8U)
#define ESPI_IRQPUSH_DONE(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_IRQPUSH_DONE_SHIFT)) & ESPI_IRQPUSH_DONE_MASK)
/*! @} */

/*! @name WIREWO - Wire states for Host to see; if LPC, this is the IRQ states. */
/*! @{ */

#define ESPI_WIREWO_WIRES_MASK                   (0x3FFFFU)
#define ESPI_WIREWO_WIRES_SHIFT                  (0U)
#define ESPI_WIREWO_WIRES(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_WIRES_SHIFT)) & ESPI_WIREWO_WIRES_MASK)

#define ESPI_WIREWO_DONE_MASK                    (0x80000000U)
#define ESPI_WIREWO_DONE_SHIFT                   (31U)
#define ESPI_WIREWO_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_WIREWO_DONE_SHIFT)) & ESPI_WIREWO_DONE_MASK)
/*! @} */

/*! @name WIRERO - Wire states from Host */
/*! @{ */

#define ESPI_WIRERO_WIRES_MASK                   (0x3FFFFFU)
#define ESPI_WIRERO_WIRES_SHIFT                  (0U)
#define ESPI_WIRERO_WIRES(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_WIRERO_WIRES_SHIFT)) & ESPI_WIRERO_WIRES_MASK)
/*! @} */

/*! @name P80STAT - Port 80 Status (byte and prev byte) */
/*! @{ */

#define ESPI_P80STAT_CURR_MASK                   (0xFFU)
#define ESPI_P80STAT_CURR_SHIFT                  (0U)
/*! CURR - Has the Current Port80 value. */
#define ESPI_P80STAT_CURR(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_CURR_SHIFT)) & ESPI_P80STAT_CURR_MASK)

#define ESPI_P80STAT_PREV_MASK                   (0xFF00U)
#define ESPI_P80STAT_PREV_SHIFT                  (8U)
/*! PREV - Has the previous Port80 value. */
#define ESPI_P80STAT_PREV(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_PREV_SHIFT)) & ESPI_P80STAT_PREV_MASK)

#define ESPI_P80STAT_CNT_MASK                    (0xF0000U)
#define ESPI_P80STAT_CNT_SHIFT                   (16U)
/*! CNT - A counter (set to 0 on enable of p80) which increments with each new value. Will wrap back to 0. */
#define ESPI_P80STAT_CNT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_CNT_SHIFT)) & ESPI_P80STAT_CNT_MASK)

#define ESPI_P80STAT_RST_MASK                    (0x100000U)
#define ESPI_P80STAT_RST_SHIFT                   (20U)
/*! RST - Resets counter, CNT, back to 0. */
#define ESPI_P80STAT_RST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_P80STAT_RST_SHIFT)) & ESPI_P80STAT_RST_MASK)
/*! @} */

/*! @name STATADDR - Location of Status block in memory space, if enabled. */
/*! @{ */

#define ESPI_STATADDR_OFF_MASK                   (0xFFF8U)
#define ESPI_STATADDR_OFF_SHIFT                  (3U)
#define ESPI_STATADDR_OFF(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_STATADDR_OFF_SHIFT)) & ESPI_STATADDR_OFF_MASK)

#define ESPI_STATADDR_BASE_MASK                  (0x30000U)
#define ESPI_STATADDR_BASE_SHIFT                 (16U)
/*! BASE - The meaning is dependent on type of port:
 *  0b00..Is offset from 0 in host memory or IO space.
 *  0b01..Uses Base1 offset in host memory (see MAPBASE reg)
 *  0b10..Uses Base2 offset in host memory (see MAPBASE reg)
 *  0b11..Reserved
 */
#define ESPI_STATADDR_BASE(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_STATADDR_BASE_SHIFT)) & ESPI_STATADDR_BASE_MASK)
/*! @} */

/*! @name ESPICAP - eSPI Capabilities of MCU to send to Host */
/*! @{ */

#define ESPI_ESPICAP_SPICAP_MASK                 (0x3U)
#define ESPI_ESPICAP_SPICAP_SHIFT                (0U)
/*! SPICAP - SPI mode allowed (host still has to select):
 *  0b00..SPI only
 *  0b01..BiSPI and SPI
 *  0b10..FLEXSPI and SPI
 *  0b11..any
 */
#define ESPI_ESPICAP_SPICAP(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SPICAP_SHIFT)) & ESPI_ESPICAP_SPICAP_MASK)

#define ESPI_ESPICAP_MAXSPD_MASK                 (0x70U)
#define ESPI_ESPICAP_MAXSPD_SHIFT                (4U)
/*! MAXSPD - Maximum SPI Clock speed to allow (host still chooses):
 *  0b000..<=20MHz
 *  0b001..<=25MHz (may be 24Mhz)
 *  0b010..<=33MHz (may be 30MHz)
 *  0b011..<=50MHz (may be 48MHz)
 *  0b100..<= 66MHz (may be 60MHz)
 */
#define ESPI_ESPICAP_MAXSPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_MAXSPD_SHIFT)) & ESPI_ESPICAP_MAXSPD_MASK)

#define ESPI_ESPICAP_ALPIN_MASK                  (0x80U)
#define ESPI_ESPICAP_ALPIN_SHIFT                 (7U)
/*! ALPIN - Allow Alert to be a pin if the Host wants */
#define ESPI_ESPICAP_ALPIN(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_ALPIN_SHIFT)) & ESPI_ESPICAP_ALPIN_MASK)

#define ESPI_ESPICAP_OOBOK_MASK                  (0x100U)
#define ESPI_ESPICAP_OOBOK_SHIFT                 (8U)
/*! OOBOK - If 1, allow OOB */
#define ESPI_ESPICAP_OOBOK(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_OOBOK_SHIFT)) & ESPI_ESPICAP_OOBOK_MASK)

#define ESPI_ESPICAP_MEMMX_MASK                  (0x200U)
#define ESPI_ESPICAP_MEMMX_SHIFT                 (9U)
/*! MEMMX - If 1, allow 128 byte payload for memory and OOB access, else limit to 64 */
#define ESPI_ESPICAP_MEMMX(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_MEMMX_SHIFT)) & ESPI_ESPICAP_MEMMX_MASK)

#define ESPI_ESPICAP_FLASHMX_MASK                (0xC00U)
#define ESPI_ESPICAP_FLASHMX_SHIFT               (10U)
/*! FLASHMX - Selects max Flash payload size to allow:
 *  0b00..64 bytes
 *  0b01..128 bytes
 *  0b10..256 bytes
 *  0b11..512 bytes
 */
#define ESPI_ESPICAP_FLASHMX(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_FLASHMX_SHIFT)) & ESPI_ESPICAP_FLASHMX_MASK)

#define ESPI_ESPICAP_SAF_MASK                    (0x1000U)
#define ESPI_ESPICAP_SAF_SHIFT                   (12U)
#define ESPI_ESPICAP_SAF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SAF_SHIFT)) & ESPI_ESPICAP_SAF_MASK)

#define ESPI_ESPICAP_SAFERA_MASK                 (0x6000U)
#define ESPI_ESPICAP_SAFERA_SHIFT                (13U)
/*! SAFERA
 *  0b00..Minimally 2KB
 *  0b01..Minimally 4KB
 *  0b10..Minimally 8KB
 *  0b11..Minimally 16KB
 */
#define ESPI_ESPICAP_SAFERA(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICAP_SAFERA_SHIFT)) & ESPI_ESPICAP_SAFERA_MASK)
/*! @} */

/*! @name ESPICFG - eSPI Configuration settings from eSPI */
/*! @{ */

#define ESPI_ESPICFG_MEMSZ_MASK                  (0x1U)
#define ESPI_ESPICFG_MEMSZ_SHIFT                 (0U)
#define ESPI_ESPICFG_MEMSZ(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_MEMSZ_SHIFT)) & ESPI_ESPICFG_MEMSZ_MASK)

#define ESPI_ESPICFG_FLASHSZ_MASK                (0x6U)
#define ESPI_ESPICFG_FLASHSZ_SHIFT               (1U)
#define ESPI_ESPICFG_FLASHSZ(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLASHSZ_SHIFT)) & ESPI_ESPICFG_FLASHSZ_MASK)

#define ESPI_ESPICFG_SPIMOD_MASK                 (0x18U)
#define ESPI_ESPICFG_SPIMOD_SHIFT                (3U)
/*! SPIMOD
 *  0b00..SPI
 *  0b01..BiSPI
 *  0b10..FLEXSPI
 */
#define ESPI_ESPICFG_SPIMOD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SPIMOD_SHIFT)) & ESPI_ESPICFG_SPIMOD_MASK)

#define ESPI_ESPICFG_ALERT_MASK                  (0x20U)
#define ESPI_ESPICFG_ALERT_SHIFT                 (5U)
/*! ALERT - Alert is a pin vs. MISO */
#define ESPI_ESPICFG_ALERT(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_ALERT_SHIFT)) & ESPI_ESPICFG_ALERT_MASK)

#define ESPI_ESPICFG_ALERTOD_MASK                (0x40U)
#define ESPI_ESPICFG_ALERTOD_SHIFT               (6U)
/*! ALERTOD - Alert is OD as a pin */
#define ESPI_ESPICFG_ALERTOD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_ALERTOD_SHIFT)) & ESPI_ESPICFG_ALERTOD_MASK)

#define ESPI_ESPICFG_SPISPD_MASK                 (0x380U)
#define ESPI_ESPICFG_SPISPD_SHIFT                (7U)
/*! SPISPD
 *  0b000..20MHz or less
 *  0b001..25MHz or 24MHz
 *  0b010..33MHz or 30MHz
 *  0b011..50MHz or 48MHz
 *  0b100..66MHz or 60MHz
 */
#define ESPI_ESPICFG_SPISPD(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SPISPD_SHIFT)) & ESPI_ESPICFG_SPISPD_MASK)

#define ESPI_ESPICFG_CRC_MASK                    (0x400U)
#define ESPI_ESPICFG_CRC_SHIFT                   (10U)
/*! CRC - CRC checking is enabled */
#define ESPI_ESPICFG_CRC(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_CRC_SHIFT)) & ESPI_ESPICFG_CRC_MASK)

#define ESPI_ESPICFG_BUSMOK_MASK                 (0x800U)
#define ESPI_ESPICFG_BUSMOK_SHIFT                (11U)
/*! BUSMOK - Bus Master is OK */
#define ESPI_ESPICFG_BUSMOK(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_BUSMOK_SHIFT)) & ESPI_ESPICFG_BUSMOK_MASK)

#define ESPI_ESPICFG_MEMENA_MASK                 (0x1000U)
#define ESPI_ESPICFG_MEMENA_SHIFT                (12U)
/*! MEMENA - Channel 0 (memory) is enabled */
#define ESPI_ESPICFG_MEMENA(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_MEMENA_SHIFT)) & ESPI_ESPICFG_MEMENA_MASK)

#define ESPI_ESPICFG_VWOK_MASK                   (0x2000U)
#define ESPI_ESPICFG_VWOK_SHIFT                  (13U)
/*! VWOK - Channel 1 (Vwire) is enabled */
#define ESPI_ESPICFG_VWOK(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_VWOK_SHIFT)) & ESPI_ESPICFG_VWOK_MASK)

#define ESPI_ESPICFG_OOBOK_MASK                  (0x4000U)
#define ESPI_ESPICFG_OOBOK_SHIFT                 (14U)
/*! OOBOK - Channel 2 (OOB) is enabled */
#define ESPI_ESPICFG_OOBOK(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_OOBOK_SHIFT)) & ESPI_ESPICFG_OOBOK_MASK)

#define ESPI_ESPICFG_FLSHERA_MASK                (0x38000U)
#define ESPI_ESPICFG_FLSHERA_SHIFT               (15U)
/*! FLSHERA - Flash erase size (and if enabled):
 *  0b000..Flash is not enabled
 *  0b001..Erase is 4K
 *  0b010..Erase is 64K
 *  0b011..Erase allows 4K and 64K
 *  0b100..Erase is 128K
 *  0b101..Erase is 256K
 */
#define ESPI_ESPICFG_FLSHERA(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLSHERA_SHIFT)) & ESPI_ESPICFG_FLSHERA_MASK)

#define ESPI_ESPICFG_FLSHOK_MASK                 (0x40000U)
#define ESPI_ESPICFG_FLSHOK_SHIFT                (18U)
/*! FLSHOK - Channel 3 (Flash) is enabled. */
#define ESPI_ESPICFG_FLSHOK(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_FLSHOK_SHIFT)) & ESPI_ESPICFG_FLSHOK_MASK)

#define ESPI_ESPICFG_SAF_MASK                    (0x80000U)
#define ESPI_ESPICFG_SAF_SHIFT                   (19U)
/*! SAF - Is 1 if Slave Attached Flash is enabled. Only possible if SAF is set in ESPICAP. */
#define ESPI_ESPICFG_SAF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ESPICFG_SAF_SHIFT)) & ESPI_ESPICFG_SAF_MASK)
/*! @} */

/*! @name ESPIMISC - Miscellaneous uses, such as Alert pin as GPIO (when not used for Alert). */
/*! @{ */

#define ESPI_ESPIMISC_GPIO_OE_MASK               (0x1U)
#define ESPI_ESPIMISC_GPIO_OE_SHIFT              (0U)
#define ESPI_ESPIMISC_GPIO_OE(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OE_SHIFT)) & ESPI_ESPIMISC_GPIO_OE_MASK)

#define ESPI_ESPIMISC_GPIO_OD_MASK               (0x2U)
#define ESPI_ESPIMISC_GPIO_OD_SHIFT              (1U)
#define ESPI_ESPIMISC_GPIO_OD(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OD_SHIFT)) & ESPI_ESPIMISC_GPIO_OD_MASK)

#define ESPI_ESPIMISC_GPIO_OUT_MASK              (0x4U)
#define ESPI_ESPIMISC_GPIO_OUT_SHIFT             (2U)
#define ESPI_ESPIMISC_GPIO_OUT(x)                (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_OUT_SHIFT)) & ESPI_ESPIMISC_GPIO_OUT_MASK)

#define ESPI_ESPIMISC_GPIO_IN_MASK               (0x8U)
#define ESPI_ESPIMISC_GPIO_IN_SHIFT              (3U)
#define ESPI_ESPIMISC_GPIO_IN(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_GPIO_IN_SHIFT)) & ESPI_ESPIMISC_GPIO_IN_MASK)

#define ESPI_ESPIMISC_RISGP_MASK                 (0x10U)
#define ESPI_ESPIMISC_RISGP_SHIFT                (4U)
#define ESPI_ESPIMISC_RISGP(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_RISGP_SHIFT)) & ESPI_ESPIMISC_RISGP_MASK)

#define ESPI_ESPIMISC_PWRSAV_MASK                (0x80000000U)
#define ESPI_ESPIMISC_PWRSAV_SHIFT               (31U)
#define ESPI_ESPIMISC_PWRSAV(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_ESPIMISC_PWRSAV_SHIFT)) & ESPI_ESPIMISC_PWRSAV_MASK)
/*! @} */

/*! @name CFG -  */
/*! @{ */

#define ESPI_CFG_TYPE_MASK                       (0xFU)
#define ESPI_CFG_TYPE_SHIFT                      (0U)
/*! Type
 *  0b0000..Unconfigured (reset condition)
 *  0b0001..ACPI style Endpoint
 *  0b0010..ACPI style Index/Data
 *  0b0011..reserved
 *  0b0100..Bus Master Mem Single
 *  0b0101..Bus Master Flash Single
 *  0b0110..reserved
 *  0b0111..reserved
 *  0b1000..Mailbox Shared
 *  0b1001..Mailbox Single
 *  0b1010..Mailbox Split
 *  0b1011..Mailbox OOB Split
 *  0b1100..Mailbox OEM
 *  0b1101..reserved
 *  0b1110..reserved
 *  0b1111..reserved
 */
#define ESPI_CFG_TYPE(x)                         (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_TYPE_SHIFT)) & ESPI_CFG_TYPE_MASK)

#define ESPI_CFG_DIRECTION_MASK                  (0x60U)
#define ESPI_CFG_DIRECTION_SHIFT                 (5U)
#define ESPI_CFG_DIRECTION(x)                    (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_DIRECTION_SHIFT)) & ESPI_CFG_DIRECTION_MASK)

#define ESPI_CFG_MBINTALL_MASK                   (0x80U)
#define ESPI_CFG_MBINTALL_SHIFT                  (7U)
#define ESPI_CFG_MBINTALL(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_MBINTALL_SHIFT)) & ESPI_CFG_MBINTALL_MASK)

#define ESPI_CFG_STALLRD_MASK                    (0x100U)
#define ESPI_CFG_STALLRD_SHIFT                   (8U)
#define ESPI_CFG_STALLRD(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_STALLRD_SHIFT)) & ESPI_CFG_STALLRD_MASK)

#define ESPI_CFG_STALLWR_MASK                    (0x200U)
#define ESPI_CFG_STALLWR_SHIFT                   (9U)
#define ESPI_CFG_STALLWR(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_STALLWR_SHIFT)) & ESPI_CFG_STALLWR_MASK)

#define ESPI_CFG_ERRORIGN_MASK                   (0x400U)
#define ESPI_CFG_ERRORIGN_SHIFT                  (10U)
#define ESPI_CFG_ERRORIGN(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_CFG_ERRORIGN_SHIFT)) & ESPI_CFG_ERRORIGN_MASK)
/*! @} */

/* The count of ESPI_CFG */
#define ESPI_CFG_COUNT                           (5U)

/*! @name STAT -  */
/*! @{ */

#define ESPI_STAT_RDSTAT_MASK                    (0x3U)
#define ESPI_STAT_RDSTAT_SHIFT                   (0U)
#define ESPI_STAT_RDSTAT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_RDSTAT_SHIFT)) & ESPI_STAT_RDSTAT_MASK)

#define ESPI_STAT_WRSTAT_MASK                    (0xCU)
#define ESPI_STAT_WRSTAT_SHIFT                   (2U)
#define ESPI_STAT_WRSTAT(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_WRSTAT_SHIFT)) & ESPI_STAT_WRSTAT_MASK)

#define ESPI_STAT_INTERR_MASK                    (0x100U)
#define ESPI_STAT_INTERR_SHIFT                   (8U)
#define ESPI_STAT_INTERR(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTERR_SHIFT)) & ESPI_STAT_INTERR_MASK)

#define ESPI_STAT_INTRD_MASK                     (0x200U)
#define ESPI_STAT_INTRD_SHIFT                    (9U)
#define ESPI_STAT_INTRD(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTRD_SHIFT)) & ESPI_STAT_INTRD_MASK)

#define ESPI_STAT_INTWR_MASK                     (0x400U)
#define ESPI_STAT_INTWR_SHIFT                    (10U)
#define ESPI_STAT_INTWR(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTWR_SHIFT)) & ESPI_STAT_INTWR_MASK)

#define ESPI_STAT_INTSPC_MASK                    (0x7800U)
#define ESPI_STAT_INTSPC_SHIFT                   (11U)
#define ESPI_STAT_INTSPC(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_INTSPC_SHIFT)) & ESPI_STAT_INTSPC_MASK)

#define ESPI_STAT_ERR_MASK                       (0xF0000U)
#define ESPI_STAT_ERR_SHIFT                      (16U)
#define ESPI_STAT_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << ESPI_STAT_ERR_SHIFT)) & ESPI_STAT_ERR_MASK)
/*! @} */

/* The count of ESPI_STAT */
#define ESPI_STAT_COUNT                          (5U)

/*! @name IRULESTAT -  */
/*! @{ */

#define ESPI_IRULESTAT_USTAT_MASK                (0x1FU)
#define ESPI_IRULESTAT_USTAT_SHIFT               (0U)
/*! USTAT - User defined status bits. These are salted into the status register as specified in section 4.1 and 4.6. */
#define ESPI_IRULESTAT_USTAT(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_USTAT_SHIFT)) & ESPI_IRULESTAT_USTAT_MASK)

#define ESPI_IRULESTAT_INTERR_MASK               (0x100U)
#define ESPI_IRULESTAT_INTERR_SHIFT              (8U)
/*! INTERR - Interrupt if an error is detected (classes of error defined in section 2.14) */
#define ESPI_IRULESTAT_INTERR(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTERR_SHIFT)) & ESPI_IRULESTAT_INTERR_MASK)

#define ESPI_IRULESTAT_INTRD_MASK                (0x200U)
#define ESPI_IRULESTAT_INTRD_SHIFT               (9U)
/*! INTRD - Interrupt if Read or 1st Read or Bus master Started. */
#define ESPI_IRULESTAT_INTRD(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTRD_SHIFT)) & ESPI_IRULESTAT_INTRD_MASK)

#define ESPI_IRULESTAT_INTWR_MASK                (0x400U)
#define ESPI_IRULESTAT_INTWR_SHIFT               (10U)
/*! INTWR - Interrupt if Write or 1st Write or Bus master Finished. */
#define ESPI_IRULESTAT_INTWR(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTWR_SHIFT)) & ESPI_IRULESTAT_INTWR_MASK)

#define ESPI_IRULESTAT_INTSPC_MASK               (0x7800U)
#define ESPI_IRULESTAT_INTSPC_SHIFT              (11U)
#define ESPI_IRULESTAT_INTSPC(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_INTSPC_SHIFT)) & ESPI_IRULESTAT_INTSPC_MASK)

#define ESPI_IRULESTAT_SSTCL_MASK                (0xF0000U)
#define ESPI_IRULESTAT_SSTCL_SHIFT               (16U)
#define ESPI_IRULESTAT_SSTCL(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_SSTCL_SHIFT)) & ESPI_IRULESTAT_SSTCL_MASK)

#define ESPI_IRULESTAT_SRST_MASK                 (0x100000U)
#define ESPI_IRULESTAT_SRST_SHIFT                (20U)
#define ESPI_IRULESTAT_SRST(x)                   (((uint32_t)(((uint32_t)(x)) << ESPI_IRULESTAT_SRST_SHIFT)) & ESPI_IRULESTAT_SRST_MASK)
/*! @} */

/* The count of ESPI_IRULESTAT */
#define ESPI_IRULESTAT_COUNT                     (5U)

/*! @name ADDR -  */
/*! @{ */

#define ESPI_ADDR_OFF_MASK                       (0xFFFFU)
#define ESPI_ADDR_OFF_SHIFT                      (0U)
#define ESPI_ADDR_OFF(x)                         (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_OFF_SHIFT)) & ESPI_ADDR_OFF_MASK)

#define ESPI_ADDR_BASE_OR_ASZ_MASK               (0x30000U)
#define ESPI_ADDR_BASE_OR_ASZ_SHIFT              (16U)
/*! BASE_or_ASZ - The meaning is dependent on type of port:
 *  0b00..Is offset from 0 in host memory or IO space.
 *  0b01..Uses BASE0 offset in host memory
 *  0b10..Uses BASE1 offset in host memory
 *  0b11..Reserved - do not use
 */
#define ESPI_ADDR_BASE_OR_ASZ(x)                 (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_BASE_OR_ASZ_SHIFT)) & ESPI_ADDR_BASE_OR_ASZ_MASK)

#define ESPI_ADDR_IDXOFF_MASK                    (0xF000000U)
#define ESPI_ADDR_IDXOFF_SHIFT                   (24U)
#define ESPI_ADDR_IDXOFF(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_IDXOFF_SHIFT)) & ESPI_ADDR_IDXOFF_MASK)

#define ESPI_ADDR_IDX1ST_MASK                    (0x10000000U)
#define ESPI_ADDR_IDX1ST_SHIFT                   (28U)
#define ESPI_ADDR_IDX1ST(x)                      (((uint32_t)(((uint32_t)(x)) << ESPI_ADDR_IDX1ST_SHIFT)) & ESPI_ADDR_IDX1ST_MASK)
/*! @} */

/* The count of ESPI_ADDR */
#define ESPI_ADDR_COUNT                          (5U)

/*! @name OMFLEN -  */
/*! @{ */

#define ESPI_OMFLEN_LEN_MASK                     (0x7FU)
#define ESPI_OMFLEN_LEN_SHIFT                    (0U)
#define ESPI_OMFLEN_LEN(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_OMFLEN_LEN_SHIFT)) & ESPI_OMFLEN_LEN_MASK)

#define ESPI_OMFLEN_TRANS_MASK                   (0x3000U)
#define ESPI_OMFLEN_TRANS_SHIFT                  (12U)
#define ESPI_OMFLEN_TRANS(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_OMFLEN_TRANS_SHIFT)) & ESPI_OMFLEN_TRANS_MASK)
/*! @} */

/* The count of ESPI_OMFLEN */
#define ESPI_OMFLEN_COUNT                        (5U)

/*! @name DATAIN -  */
/*! @{ */

#define ESPI_DATAIN_DATA_LEN_MASK                (0xFFU)
#define ESPI_DATAIN_DATA_LEN_SHIFT               (0U)
#define ESPI_DATAIN_DATA_LEN(x)                  (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_DATA_LEN_SHIFT)) & ESPI_DATAIN_DATA_LEN_MASK)

#define ESPI_DATAIN_DIR_MASK                     (0x100U)
#define ESPI_DATAIN_DIR_SHIFT                    (8U)
#define ESPI_DATAIN_DIR(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_DIR_SHIFT)) & ESPI_DATAIN_DIR_MASK)

#define ESPI_DATAIN_IDX_MASK                     (0x3FF0000U)
#define ESPI_DATAIN_IDX_SHIFT                    (16U)
#define ESPI_DATAIN_IDX(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_DATAIN_IDX_SHIFT)) & ESPI_DATAIN_IDX_MASK)
/*! @} */

/* The count of ESPI_DATAIN */
#define ESPI_DATAIN_COUNT                        (5U)

/*! @name DATAOUT -  */
/*! @{ */

#define ESPI_DATAOUT_DATA_MASK                   (0xFFU)
#define ESPI_DATAOUT_DATA_SHIFT                  (0U)
#define ESPI_DATAOUT_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << ESPI_DATAOUT_DATA_SHIFT)) & ESPI_DATAOUT_DATA_MASK)
/*! @} */

/* The count of ESPI_DATAOUT */
#define ESPI_DATAOUT_COUNT                       (5U)

/*! @name RAMUSE -  */
/*! @{ */

#define ESPI_RAMUSE_OFF_MASK                     (0xFFFU)
#define ESPI_RAMUSE_OFF_SHIFT                    (0U)
#define ESPI_RAMUSE_OFF(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_RAMUSE_OFF_SHIFT)) & ESPI_RAMUSE_OFF_MASK)

#define ESPI_RAMUSE_LEN_MASK                     (0x70000U)
#define ESPI_RAMUSE_LEN_SHIFT                    (16U)
#define ESPI_RAMUSE_LEN(x)                       (((uint32_t)(((uint32_t)(x)) << ESPI_RAMUSE_LEN_SHIFT)) & ESPI_RAMUSE_LEN_MASK)
/*! @} */

/* The count of ESPI_RAMUSE */
#define ESPI_RAMUSE_COUNT                        (5U)


/*!
 * @}
 */ /* end of group ESPI_Register_Masks */


/*!
 * @}
 */ /* end of group ESPI_Peripheral_Access_Layer */


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


#endif  /* PERI_ESPI_H_ */

