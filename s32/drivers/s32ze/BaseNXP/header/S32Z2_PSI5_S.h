/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_PSI5_S.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_PSI5_S
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_PSI5_S_H_)  /* Check if memory map has not been already included */
#define S32Z2_PSI5_S_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PSI5_S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PSI5_S_Peripheral_Access_Layer PSI5_S Peripheral Access Layer
 * @{
 */

/** PSI5_S - Size of Registers Arrays */
#define PSI5_S_IRQ_COUNT                          8u
#define PSI5_S_CH_COUNT                           7u

/** PSI5_S - Register Layout Typedef */
typedef struct {
  __IO uint32_t LINCR1;                            /**< PSI5_S LIN Control Register 1, offset: 0x0 */
  __IO uint32_t LINIER;                            /**< PSI5_S LIN Interrupt enable register, offset: 0x4 */
  __I  uint32_t LINSR;                             /**< PSI5_S LIN Status Register, offset: 0x8 */
  uint8_t RESERVED_0[4];
  __IO uint32_t UARTCR;                            /**< PSI5_S UART Mode Control Register, offset: 0x10 */
  __IO uint32_t UARTSR;                            /**< PSI5_S UART Mode Status Register, offset: 0x14 */
  uint8_t RESERVED_1[12];
  __IO uint32_t LINFBRR;                           /**< PSI5_S LIN Fractional Baud Rate Register, offset: 0x24 */
  __IO uint32_t LINIBRR;                           /**< PSI5_S LIN Integer Baud Rate Register, offset: 0x28 */
  uint8_t RESERVED_2[4];
  __IO  uint32_t LINCR2;                           /**< PSI5_S LIN Control Register 2, offset: 0x30 */
  uint8_t RESERVED_3[4];
  __IO uint32_t BDRL;                              /**< PSI5_S Buffer Data Register Least Significant, offset: 0x38 */
  __IO uint32_t BDRM;                              /**< PSI5_S Buffer Data Register Most Significant, offset: 0x3C */
  uint8_t RESERVED_4[12];
  __IO  uint32_t GCR;                              /**< PSI5_S Global Control register, offset: 0x4C */
  __IO uint32_t UARTPTO;                           /**< PSI5_S UART Preset Timeout Register, offset: 0x50 */
  __I  uint32_t UARTCTO;                           /**< PSI5_S UART Current Timeout register, offset: 0x54 */
  __IO uint32_t DMATXE;                            /**< DMA Tx Enable Register, offset: 0x58 */
  __IO uint32_t DMARXE;                            /**< DMA Rx Enable Register, offset: 0x5C */
  __IO uint32_t PTD;                               /**< PSI5_S UART Tx Idle Delay Time Register, offset: 0x60 */
  uint8_t RESERVED_5[80];
  __IO uint32_t GLCR;                              /**< PSI5_S Global Control Register, offset: 0xB4 */
  __IO uint32_t GLSR;                              /**< PSI5_S Global Status Register, offset: 0xB8 */
  __IO uint32_t CH_BASE_ADDR;                      /**< PSI5_S CHANNEL_BASE_ADDRESS, offset: 0xBC */
  __I  uint32_t MRU_BUF2_REG0;                     /**< PSI5_S MRU OUTPUT BUFFER2 REGISTER0, offset: 0xC0 */
  __I  uint32_t MRU_BUF2_REG1;                     /**< PSI5_S MRU OUTPUT BUFFER2 REGISTER1, offset: 0xC4 */
  __I  uint32_t MRU_BUF2_REG2;                     /**< PSI5_S MRU OUTPUT BUFFER2 REGISTER2, offset: 0xC8 */
  __I  uint32_t MRU_BUF2_REG3;                     /**< PSI5_S MRU OUTPUT BUFFER2 REGISTER3, offset: 0xCC */
  uint8_t RESERVED_6[16];
  __I  uint32_t MBOX_SR_IRQ;                       /**< PSI5_S Mbox Status Irq, offset: 0xE0 */
  __IO uint32_t ERR_SR_IRQ;                        /**< PSI5_S Error Status IRQ, offset: 0xE4 */
  struct PSI5_S_IRQ {                              /* offset: 0xE8, array step: 0x8 */
    __IO uint32_t MBOX_SEL_IRQ;                      /**< PSI5_S Mailbox select IRQ[irq_n], array offset: 0xE8, array step: 0x8 */
    __IO uint32_t ERR_SEL_IRQ;                       /**< PSI5_S Error Select IRQ[irq_n], array offset: 0xEC, array step: 0x8 */
  } IRQ[PSI5_S_IRQ_COUNT];
  __I  uint32_t WDGTSSR;                           /**< PSI5_S Watchdog Error Status and Watchdog Timestamp status register, offset: 0x128 */
  __IO  uint32_t DIRCMD;                           /**< PSI5_S ECU to Sensor Direct Command Write register, offset: 0x12C */
  uint8_t RESERVED_7[60];
  __IO uint32_t CH0_MSGA;                          /**< PSI5_S channel 0 message configuration register A, offset: 0x16C */
  __IO uint32_t CH0_MSGB;                          /**< PSI5_S channel 0 message configuration register B, offset: 0x170 */
  uint8_t RESERVED_8[4];
  __IO uint32_t CH0_MBOX_SR;                       /**< PSI5_S Mailbox status register channel0, offset: 0x178 */
  uint8_t RESERVED_9[20];
  struct PSI5_S_CH {                               /* offset: 0x190, array step: 0x3C */
    __IO uint32_t MSGA;                              /**< PSI5_S channel message configuration register A, array offset: 0x190, array step: 0x3C */
    __IO uint32_t MSGB;                              /**< PSI5_S channel message configuration register B, array offset: 0x194, array step: 0x3C */
    uint8_t RESERVED_0[4];
    __IO uint32_t MBOX_SR;                           /**< PSI5_S Mailbox status register channel, array offset: 0x19C, array step: 0x3C */
    __IO uint32_t WD_CFGR;                           /**< PSI5_S channel watchdog configuration register, array offset: 0x1A0, array step: 0x3C */
    __IO uint32_t DDTRIG_OFFR;                       /**< PSI5_S DDSR Trigger offset register channel, array offset: 0x1A4, array step: 0x3C */
    __IO uint32_t DDTRIG_PERR;                       /**< PSI5_S DDSR Trigger period register channel, array offset: 0x1A8, array step: 0x3C */
    __IO uint32_t E2SCR;                             /**< PSI5_S ECU to Sensor Control Register, array offset: 0x1AC, array step: 0x3C */
    __IO uint32_t E2SSR;                             /**< PSI5_S ECU to Sensor Status Register, array offset: 0x1B0, array step: 0x3C */
    __I  uint32_t DDSR_H;                            /**< PSI5_S channel1 ECU to Sensor Downstream Data Shift Register High, array offset: 0x1B4, array step: 0x3C */
    __IO uint32_t DDSR_L;                            /**< PSI5_S channel1 ECU to Sensor Downstream Data Shift Register Low, array offset: 0x1B8, array step: 0x3C */
    uint8_t RESERVED_1[16];
  } CH[PSI5_S_CH_COUNT];
} PSI5_S_Type, *PSI5_S_MemMapPtr;

/** Number of instances of the PSI5_S module. */
#define PSI5_S_INSTANCE_COUNT                    (2u)

/* PSI5_S - Peripheral instance base addresses */
/** Peripheral PSI5_S_0 base address */
#define IP_PSI5_S_0_BASE                         (0x401F0000u)
/** Peripheral PSI5_S_0 base pointer */
#define IP_PSI5_S_0                              ((PSI5_S_Type *)IP_PSI5_S_0_BASE)
/** Peripheral PSI5_S_1 base address */
#define IP_PSI5_S_1_BASE                         (0x421F0000u)
/** Peripheral PSI5_S_1 base pointer */
#define IP_PSI5_S_1                              ((PSI5_S_Type *)IP_PSI5_S_1_BASE)
/** Array initializer of PSI5_S peripheral base addresses */
#define IP_PSI5_S_BASE_ADDRS                     { IP_PSI5_S_0_BASE, IP_PSI5_S_1_BASE }
/** Array initializer of PSI5_S peripheral base pointers */
#define IP_PSI5_S_BASE_PTRS                      { IP_PSI5_S_0, IP_PSI5_S_1 }

/* ----------------------------------------------------------------------------
   -- PSI5_S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PSI5_S_Register_Masks PSI5_S Register Masks
 * @{
 */

/*! @name LINCR1 - PSI5_S LIN Control Register 1 */
/*! @{ */

#define PSI5_S_LINCR1_INIT_MASK                  (0x1U)
#define PSI5_S_LINCR1_INIT_SHIFT                 (0U)
#define PSI5_S_LINCR1_INIT_WIDTH                 (1U)
#define PSI5_S_LINCR1_INIT(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_INIT_SHIFT)) & PSI5_S_LINCR1_INIT_MASK)

#define PSI5_S_LINCR1_SLEEP_MASK                 (0x2U)
#define PSI5_S_LINCR1_SLEEP_SHIFT                (1U)
#define PSI5_S_LINCR1_SLEEP_WIDTH                (1U)
#define PSI5_S_LINCR1_SLEEP(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_SLEEP_SHIFT)) & PSI5_S_LINCR1_SLEEP_MASK)

#define PSI5_S_LINCR1_RBLM_MASK                  (0x4U)
#define PSI5_S_LINCR1_RBLM_SHIFT                 (2U)
#define PSI5_S_LINCR1_RBLM_WIDTH                 (1U)
#define PSI5_S_LINCR1_RBLM(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_RBLM_SHIFT)) & PSI5_S_LINCR1_RBLM_MASK)

#define PSI5_S_LINCR1_LBKM_MASK                  (0x20U)
#define PSI5_S_LINCR1_LBKM_SHIFT                 (5U)
#define PSI5_S_LINCR1_LBKM_WIDTH                 (1U)
#define PSI5_S_LINCR1_LBKM(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_LBKM_SHIFT)) & PSI5_S_LINCR1_LBKM_MASK)

#define PSI5_S_LINCR1_SLFM_MASK                  (0x40U)
#define PSI5_S_LINCR1_SLFM_SHIFT                 (6U)
#define PSI5_S_LINCR1_SLFM_WIDTH                 (1U)
#define PSI5_S_LINCR1_SLFM(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_SLFM_SHIFT)) & PSI5_S_LINCR1_SLFM_MASK)

#define PSI5_S_LINCR1_AUTOWU_MASK                (0x1000U)
#define PSI5_S_LINCR1_AUTOWU_SHIFT               (12U)
#define PSI5_S_LINCR1_AUTOWU_WIDTH               (1U)
#define PSI5_S_LINCR1_AUTOWU(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR1_AUTOWU_SHIFT)) & PSI5_S_LINCR1_AUTOWU_MASK)
/*! @} */

/*! @name LINIER - PSI5_S LIN Interrupt enable register */
/*! @{ */

#define PSI5_S_LINIER_DTIE_MASK                  (0x2U)
#define PSI5_S_LINIER_DTIE_SHIFT                 (1U)
#define PSI5_S_LINIER_DTIE_WIDTH                 (1U)
#define PSI5_S_LINIER_DTIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_DTIE_SHIFT)) & PSI5_S_LINIER_DTIE_MASK)

#define PSI5_S_LINIER_DRIE_MASK                  (0x4U)
#define PSI5_S_LINIER_DRIE_SHIFT                 (2U)
#define PSI5_S_LINIER_DRIE_WIDTH                 (1U)
#define PSI5_S_LINIER_DRIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_DRIE_SHIFT)) & PSI5_S_LINIER_DRIE_MASK)

#define PSI5_S_LINIER_TOIE_MASK                  (0x8U)
#define PSI5_S_LINIER_TOIE_SHIFT                 (3U)
#define PSI5_S_LINIER_TOIE_WIDTH                 (1U)
#define PSI5_S_LINIER_TOIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_TOIE_SHIFT)) & PSI5_S_LINIER_TOIE_MASK)

#define PSI5_S_LINIER_WUIE_MASK                  (0x20U)
#define PSI5_S_LINIER_WUIE_SHIFT                 (5U)
#define PSI5_S_LINIER_WUIE_WIDTH                 (1U)
#define PSI5_S_LINIER_WUIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_WUIE_SHIFT)) & PSI5_S_LINIER_WUIE_MASK)

#define PSI5_S_LINIER_BOIE_MASK                  (0x80U)
#define PSI5_S_LINIER_BOIE_SHIFT                 (7U)
#define PSI5_S_LINIER_BOIE_WIDTH                 (1U)
#define PSI5_S_LINIER_BOIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_BOIE_SHIFT)) & PSI5_S_LINIER_BOIE_MASK)

#define PSI5_S_LINIER_FEIE_MASK                  (0x100U)
#define PSI5_S_LINIER_FEIE_SHIFT                 (8U)
#define PSI5_S_LINIER_FEIE_WIDTH                 (1U)
#define PSI5_S_LINIER_FEIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_FEIE_SHIFT)) & PSI5_S_LINIER_FEIE_MASK)

#define PSI5_S_LINIER_OCIE_MASK                  (0x4000U)
#define PSI5_S_LINIER_OCIE_SHIFT                 (14U)
#define PSI5_S_LINIER_OCIE_WIDTH                 (1U)
#define PSI5_S_LINIER_OCIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_OCIE_SHIFT)) & PSI5_S_LINIER_OCIE_MASK)

#define PSI5_S_LINIER_SZIE_MASK                  (0x8000U)
#define PSI5_S_LINIER_SZIE_SHIFT                 (15U)
#define PSI5_S_LINIER_SZIE_WIDTH                 (1U)
#define PSI5_S_LINIER_SZIE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIER_SZIE_SHIFT)) & PSI5_S_LINIER_SZIE_MASK)
/*! @} */

/*! @name LINSR - PSI5_S LIN Status Register */
/*! @{ */

#define PSI5_S_LINSR_LINS0_MASK                  (0x1000U)
#define PSI5_S_LINSR_LINS0_SHIFT                 (12U)
#define PSI5_S_LINSR_LINS0_WIDTH                 (1U)
#define PSI5_S_LINSR_LINS0(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINSR_LINS0_SHIFT)) & PSI5_S_LINSR_LINS0_MASK)

#define PSI5_S_LINSR_LINS1_MASK                  (0x2000U)
#define PSI5_S_LINSR_LINS1_SHIFT                 (13U)
#define PSI5_S_LINSR_LINS1_WIDTH                 (1U)
#define PSI5_S_LINSR_LINS1(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINSR_LINS1_SHIFT)) & PSI5_S_LINSR_LINS1_MASK)

#define PSI5_S_LINSR_LINS2_MASK                  (0x4000U)
#define PSI5_S_LINSR_LINS2_SHIFT                 (14U)
#define PSI5_S_LINSR_LINS2_WIDTH                 (1U)
#define PSI5_S_LINSR_LINS2(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINSR_LINS2_SHIFT)) & PSI5_S_LINSR_LINS2_MASK)

#define PSI5_S_LINSR_LINS3_MASK                  (0x8000U)
#define PSI5_S_LINSR_LINS3_SHIFT                 (15U)
#define PSI5_S_LINSR_LINS3_WIDTH                 (1U)
#define PSI5_S_LINSR_LINS3(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINSR_LINS3_SHIFT)) & PSI5_S_LINSR_LINS3_MASK)
/*! @} */

/*! @name UARTCR - PSI5_S UART Mode Control Register */
/*! @{ */

#define PSI5_S_UARTCR_UART_MASK                  (0x1U)
#define PSI5_S_UARTCR_UART_SHIFT                 (0U)
#define PSI5_S_UARTCR_UART_WIDTH                 (1U)
#define PSI5_S_UARTCR_UART(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_UART_SHIFT)) & PSI5_S_UARTCR_UART_MASK)

#define PSI5_S_UARTCR_WL0_MASK                   (0x2U)
#define PSI5_S_UARTCR_WL0_SHIFT                  (1U)
#define PSI5_S_UARTCR_WL0_WIDTH                  (1U)
#define PSI5_S_UARTCR_WL0(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_WL0_SHIFT)) & PSI5_S_UARTCR_WL0_MASK)

#define PSI5_S_UARTCR_PCE_Rx_MASK                (0x4U)
#define PSI5_S_UARTCR_PCE_Rx_SHIFT               (2U)
#define PSI5_S_UARTCR_PCE_Rx_WIDTH               (1U)
#define PSI5_S_UARTCR_PCE_Rx(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_PCE_Rx_SHIFT)) & PSI5_S_UARTCR_PCE_Rx_MASK)

#define PSI5_S_UARTCR_PC0_MASK                   (0x8U)
#define PSI5_S_UARTCR_PC0_SHIFT                  (3U)
#define PSI5_S_UARTCR_PC0_WIDTH                  (1U)
#define PSI5_S_UARTCR_PC0(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_PC0_SHIFT)) & PSI5_S_UARTCR_PC0_MASK)

#define PSI5_S_UARTCR_TxEn_MASK                  (0x10U)
#define PSI5_S_UARTCR_TxEn_SHIFT                 (4U)
#define PSI5_S_UARTCR_TxEn_WIDTH                 (1U)
#define PSI5_S_UARTCR_TxEn(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_TxEn_SHIFT)) & PSI5_S_UARTCR_TxEn_MASK)

#define PSI5_S_UARTCR_RxEn_MASK                  (0x20U)
#define PSI5_S_UARTCR_RxEn_SHIFT                 (5U)
#define PSI5_S_UARTCR_RxEn_WIDTH                 (1U)
#define PSI5_S_UARTCR_RxEn(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_RxEn_SHIFT)) & PSI5_S_UARTCR_RxEn_MASK)

#define PSI5_S_UARTCR_PC1_MASK                   (0x40U)
#define PSI5_S_UARTCR_PC1_SHIFT                  (6U)
#define PSI5_S_UARTCR_PC1_WIDTH                  (1U)
#define PSI5_S_UARTCR_PC1(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_PC1_SHIFT)) & PSI5_S_UARTCR_PC1_MASK)

#define PSI5_S_UARTCR_WL1_MASK                   (0x80U)
#define PSI5_S_UARTCR_WL1_SHIFT                  (7U)
#define PSI5_S_UARTCR_WL1_WIDTH                  (1U)
#define PSI5_S_UARTCR_WL1(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_WL1_SHIFT)) & PSI5_S_UARTCR_WL1_MASK)

#define PSI5_S_UARTCR_TFBM_MASK                  (0x100U)
#define PSI5_S_UARTCR_TFBM_SHIFT                 (8U)
#define PSI5_S_UARTCR_TFBM_WIDTH                 (1U)
#define PSI5_S_UARTCR_TFBM(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_TFBM_SHIFT)) & PSI5_S_UARTCR_TFBM_MASK)

#define PSI5_S_UARTCR_RFBM_MASK                  (0x200U)
#define PSI5_S_UARTCR_RFBM_SHIFT                 (9U)
#define PSI5_S_UARTCR_RFBM_WIDTH                 (1U)
#define PSI5_S_UARTCR_RFBM(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_RFBM_SHIFT)) & PSI5_S_UARTCR_RFBM_MASK)

#define PSI5_S_UARTCR_RDFLRFC_MASK               (0x1C00U)
#define PSI5_S_UARTCR_RDFLRFC_SHIFT              (10U)
#define PSI5_S_UARTCR_RDFLRFC_WIDTH              (3U)
#define PSI5_S_UARTCR_RDFLRFC(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_RDFLRFC_SHIFT)) & PSI5_S_UARTCR_RDFLRFC_MASK)

#define PSI5_S_UARTCR_TDFLTFC_MASK               (0xE000U)
#define PSI5_S_UARTCR_TDFLTFC_SHIFT              (13U)
#define PSI5_S_UARTCR_TDFLTFC_WIDTH              (3U)
#define PSI5_S_UARTCR_TDFLTFC(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_TDFLTFC_SHIFT)) & PSI5_S_UARTCR_TDFLTFC_MASK)

#define PSI5_S_UARTCR_WLS_MASK                   (0x10000U)
#define PSI5_S_UARTCR_WLS_SHIFT                  (16U)
#define PSI5_S_UARTCR_WLS_WIDTH                  (1U)
#define PSI5_S_UARTCR_WLS(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_WLS_SHIFT)) & PSI5_S_UARTCR_WLS_MASK)

#define PSI5_S_UARTCR_SBUR_MASK                  (0x60000U)
#define PSI5_S_UARTCR_SBUR_SHIFT                 (17U)
#define PSI5_S_UARTCR_SBUR_WIDTH                 (2U)
#define PSI5_S_UARTCR_SBUR(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_SBUR_SHIFT)) & PSI5_S_UARTCR_SBUR_MASK)

#define PSI5_S_UARTCR_PCE_TXDTU_MASK             (0x80000U)
#define PSI5_S_UARTCR_PCE_TXDTU_SHIFT            (19U)
#define PSI5_S_UARTCR_PCE_TXDTU_WIDTH            (1U)
#define PSI5_S_UARTCR_PCE_TXDTU(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_PCE_TXDTU_SHIFT)) & PSI5_S_UARTCR_PCE_TXDTU_MASK)

#define PSI5_S_UARTCR_NEF_MASK                   (0x700000U)
#define PSI5_S_UARTCR_NEF_SHIFT                  (20U)
#define PSI5_S_UARTCR_NEF_WIDTH                  (3U)
#define PSI5_S_UARTCR_NEF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_NEF_SHIFT)) & PSI5_S_UARTCR_NEF_MASK)

#define PSI5_S_UARTCR_ROSE_MASK                  (0x800000U)
#define PSI5_S_UARTCR_ROSE_SHIFT                 (23U)
#define PSI5_S_UARTCR_ROSE_WIDTH                 (1U)
#define PSI5_S_UARTCR_ROSE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_ROSE_SHIFT)) & PSI5_S_UARTCR_ROSE_MASK)

#define PSI5_S_UARTCR_OSR_MASK                   (0xF000000U)
#define PSI5_S_UARTCR_OSR_SHIFT                  (24U)
#define PSI5_S_UARTCR_OSR_WIDTH                  (4U)
#define PSI5_S_UARTCR_OSR(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_OSR_SHIFT)) & PSI5_S_UARTCR_OSR_MASK)

#define PSI5_S_UARTCR_CSP_MASK                   (0x70000000U)
#define PSI5_S_UARTCR_CSP_SHIFT                  (28U)
#define PSI5_S_UARTCR_CSP_WIDTH                  (3U)
#define PSI5_S_UARTCR_CSP(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_CSP_SHIFT)) & PSI5_S_UARTCR_CSP_MASK)

#define PSI5_S_UARTCR_MIS_MASK                   (0x80000000U)
#define PSI5_S_UARTCR_MIS_SHIFT                  (31U)
#define PSI5_S_UARTCR_MIS_WIDTH                  (1U)
#define PSI5_S_UARTCR_MIS(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCR_MIS_SHIFT)) & PSI5_S_UARTCR_MIS_MASK)
/*! @} */

/*! @name UARTSR - PSI5_S UART Mode Status Register */
/*! @{ */

#define PSI5_S_UARTSR_NF_MASK                    (0x1U)
#define PSI5_S_UARTSR_NF_SHIFT                   (0U)
#define PSI5_S_UARTSR_NF_WIDTH                   (1U)
#define PSI5_S_UARTSR_NF(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_NF_SHIFT)) & PSI5_S_UARTSR_NF_MASK)

#define PSI5_S_UARTSR_DTF_MASK                   (0x2U)
#define PSI5_S_UARTSR_DTF_SHIFT                  (1U)
#define PSI5_S_UARTSR_DTF_WIDTH                  (1U)
#define PSI5_S_UARTSR_DTF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_DTF_SHIFT)) & PSI5_S_UARTSR_DTF_MASK)

#define PSI5_S_UARTSR_DRF_MASK                   (0x4U)
#define PSI5_S_UARTSR_DRF_SHIFT                  (2U)
#define PSI5_S_UARTSR_DRF_WIDTH                  (1U)
#define PSI5_S_UARTSR_DRF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_DRF_SHIFT)) & PSI5_S_UARTSR_DRF_MASK)

#define PSI5_S_UARTSR_TO_MASK                    (0x8U)
#define PSI5_S_UARTSR_TO_SHIFT                   (3U)
#define PSI5_S_UARTSR_TO_WIDTH                   (1U)
#define PSI5_S_UARTSR_TO(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_TO_SHIFT)) & PSI5_S_UARTSR_TO_MASK)

#define PSI5_S_UARTSR_RFNE_MASK                  (0x10U)
#define PSI5_S_UARTSR_RFNE_SHIFT                 (4U)
#define PSI5_S_UARTSR_RFNE_WIDTH                 (1U)
#define PSI5_S_UARTSR_RFNE(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_RFNE_SHIFT)) & PSI5_S_UARTSR_RFNE_MASK)

#define PSI5_S_UARTSR_WUF_MASK                   (0x20U)
#define PSI5_S_UARTSR_WUF_SHIFT                  (5U)
#define PSI5_S_UARTSR_WUF_WIDTH                  (1U)
#define PSI5_S_UARTSR_WUF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_WUF_SHIFT)) & PSI5_S_UARTSR_WUF_MASK)

#define PSI5_S_UARTSR_RDI_MASK                   (0x40U)
#define PSI5_S_UARTSR_RDI_SHIFT                  (6U)
#define PSI5_S_UARTSR_RDI_WIDTH                  (1U)
#define PSI5_S_UARTSR_RDI(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_RDI_SHIFT)) & PSI5_S_UARTSR_RDI_MASK)

#define PSI5_S_UARTSR_BOF_MASK                   (0x80U)
#define PSI5_S_UARTSR_BOF_SHIFT                  (7U)
#define PSI5_S_UARTSR_BOF_WIDTH                  (1U)
#define PSI5_S_UARTSR_BOF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_BOF_SHIFT)) & PSI5_S_UARTSR_BOF_MASK)

#define PSI5_S_UARTSR_FEF_MASK                   (0x100U)
#define PSI5_S_UARTSR_FEF_SHIFT                  (8U)
#define PSI5_S_UARTSR_FEF_WIDTH                  (1U)
#define PSI5_S_UARTSR_FEF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_FEF_SHIFT)) & PSI5_S_UARTSR_FEF_MASK)

#define PSI5_S_UARTSR_RMB_MASK                   (0x200U)
#define PSI5_S_UARTSR_RMB_SHIFT                  (9U)
#define PSI5_S_UARTSR_RMB_WIDTH                  (1U)
#define PSI5_S_UARTSR_RMB(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_RMB_SHIFT)) & PSI5_S_UARTSR_RMB_MASK)

#define PSI5_S_UARTSR_PE0_MASK                   (0x400U)
#define PSI5_S_UARTSR_PE0_SHIFT                  (10U)
#define PSI5_S_UARTSR_PE0_WIDTH                  (1U)
#define PSI5_S_UARTSR_PE0(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_PE0_SHIFT)) & PSI5_S_UARTSR_PE0_MASK)

#define PSI5_S_UARTSR_PE1_MASK                   (0x800U)
#define PSI5_S_UARTSR_PE1_SHIFT                  (11U)
#define PSI5_S_UARTSR_PE1_WIDTH                  (1U)
#define PSI5_S_UARTSR_PE1(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_PE1_SHIFT)) & PSI5_S_UARTSR_PE1_MASK)

#define PSI5_S_UARTSR_PE2_MASK                   (0x1000U)
#define PSI5_S_UARTSR_PE2_SHIFT                  (12U)
#define PSI5_S_UARTSR_PE2_WIDTH                  (1U)
#define PSI5_S_UARTSR_PE2(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_PE2_SHIFT)) & PSI5_S_UARTSR_PE2_MASK)

#define PSI5_S_UARTSR_PE3_MASK                   (0x2000U)
#define PSI5_S_UARTSR_PE3_SHIFT                  (13U)
#define PSI5_S_UARTSR_PE3_WIDTH                  (1U)
#define PSI5_S_UARTSR_PE3(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_PE3_SHIFT)) & PSI5_S_UARTSR_PE3_MASK)

#define PSI5_S_UARTSR_OCF_MASK                   (0x4000U)
#define PSI5_S_UARTSR_OCF_SHIFT                  (14U)
#define PSI5_S_UARTSR_OCF_WIDTH                  (1U)
#define PSI5_S_UARTSR_OCF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_OCF_SHIFT)) & PSI5_S_UARTSR_OCF_MASK)

#define PSI5_S_UARTSR_SZF_MASK                   (0x8000U)
#define PSI5_S_UARTSR_SZF_SHIFT                  (15U)
#define PSI5_S_UARTSR_SZF_WIDTH                  (1U)
#define PSI5_S_UARTSR_SZF(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTSR_SZF_SHIFT)) & PSI5_S_UARTSR_SZF_MASK)
/*! @} */

/*! @name LINFBRR - PSI5_S LIN Fractional Baud Rate Register */
/*! @{ */

#define PSI5_S_LINFBRR_FBR_MASK                  (0xFU)
#define PSI5_S_LINFBRR_FBR_SHIFT                 (0U)
#define PSI5_S_LINFBRR_FBR_WIDTH                 (4U)
#define PSI5_S_LINFBRR_FBR(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINFBRR_FBR_SHIFT)) & PSI5_S_LINFBRR_FBR_MASK)
/*! @} */

/*! @name LINIBRR - PSI5_S LIN Integer Baud Rate Register */
/*! @{ */

#define PSI5_S_LINIBRR_IBR_MASK                  (0xFFFFFU)
#define PSI5_S_LINIBRR_IBR_SHIFT                 (0U)
#define PSI5_S_LINIBRR_IBR_WIDTH                 (20U)
#define PSI5_S_LINIBRR_IBR(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINIBRR_IBR_SHIFT)) & PSI5_S_LINIBRR_IBR_MASK)
/*! @} */

/*! @name LINCR2 - PSI5_S LIN Control Register 2 */
/*! @{ */

#define PSI5_S_LINCR2_ABRQ_MASK                  (0x200U)
#define PSI5_S_LINCR2_ABRQ_SHIFT                 (9U)
#define PSI5_S_LINCR2_ABRQ_WIDTH                 (1U)
#define PSI5_S_LINCR2_ABRQ(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_LINCR2_ABRQ_SHIFT)) & PSI5_S_LINCR2_ABRQ_MASK)
/*! @} */

/*! @name BDRL - PSI5_S Buffer Data Register Least Significant */
/*! @{ */

#define PSI5_S_BDRL_DATA_TX0_MASK                (0xFFU)
#define PSI5_S_BDRL_DATA_TX0_SHIFT               (0U)
#define PSI5_S_BDRL_DATA_TX0_WIDTH               (8U)
#define PSI5_S_BDRL_DATA_TX0(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRL_DATA_TX0_SHIFT)) & PSI5_S_BDRL_DATA_TX0_MASK)

#define PSI5_S_BDRL_DATA_TX1_MASK                (0xFF00U)
#define PSI5_S_BDRL_DATA_TX1_SHIFT               (8U)
#define PSI5_S_BDRL_DATA_TX1_WIDTH               (8U)
#define PSI5_S_BDRL_DATA_TX1(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRL_DATA_TX1_SHIFT)) & PSI5_S_BDRL_DATA_TX1_MASK)

#define PSI5_S_BDRL_DATA_TX2_MASK                (0xFF0000U)
#define PSI5_S_BDRL_DATA_TX2_SHIFT               (16U)
#define PSI5_S_BDRL_DATA_TX2_WIDTH               (8U)
#define PSI5_S_BDRL_DATA_TX2(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRL_DATA_TX2_SHIFT)) & PSI5_S_BDRL_DATA_TX2_MASK)

#define PSI5_S_BDRL_DATA_TX3_MASK                (0xFF000000U)
#define PSI5_S_BDRL_DATA_TX3_SHIFT               (24U)
#define PSI5_S_BDRL_DATA_TX3_WIDTH               (8U)
#define PSI5_S_BDRL_DATA_TX3(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRL_DATA_TX3_SHIFT)) & PSI5_S_BDRL_DATA_TX3_MASK)
/*! @} */

/*! @name BDRM - PSI5_S Buffer Data Register Most Significant */
/*! @{ */

#define PSI5_S_BDRM_DATA_RX0_MASK                (0xFFU)
#define PSI5_S_BDRM_DATA_RX0_SHIFT               (0U)
#define PSI5_S_BDRM_DATA_RX0_WIDTH               (8U)
#define PSI5_S_BDRM_DATA_RX0(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRM_DATA_RX0_SHIFT)) & PSI5_S_BDRM_DATA_RX0_MASK)

#define PSI5_S_BDRM_DATA_RX1_MASK                (0xFF00U)
#define PSI5_S_BDRM_DATA_RX1_SHIFT               (8U)
#define PSI5_S_BDRM_DATA_RX1_WIDTH               (8U)
#define PSI5_S_BDRM_DATA_RX1(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRM_DATA_RX1_SHIFT)) & PSI5_S_BDRM_DATA_RX1_MASK)

#define PSI5_S_BDRM_DATA_RX2_MASK                (0xFF0000U)
#define PSI5_S_BDRM_DATA_RX2_SHIFT               (16U)
#define PSI5_S_BDRM_DATA_RX2_WIDTH               (8U)
#define PSI5_S_BDRM_DATA_RX2(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRM_DATA_RX2_SHIFT)) & PSI5_S_BDRM_DATA_RX2_MASK)

#define PSI5_S_BDRM_DATA_RX3_MASK                (0xFF000000U)
#define PSI5_S_BDRM_DATA_RX3_SHIFT               (24U)
#define PSI5_S_BDRM_DATA_RX3_WIDTH               (8U)
#define PSI5_S_BDRM_DATA_RX3(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_BDRM_DATA_RX3_SHIFT)) & PSI5_S_BDRM_DATA_RX3_MASK)
/*! @} */

/*! @name GCR - PSI5_S Global Control register */
/*! @{ */

#define PSI5_S_GCR_SR_MASK                       (0x1U)
#define PSI5_S_GCR_SR_SHIFT                      (0U)
#define PSI5_S_GCR_SR_WIDTH                      (1U)
#define PSI5_S_GCR_SR(x)                         (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_SR_SHIFT)) & PSI5_S_GCR_SR_MASK)

#define PSI5_S_GCR_STOP_MASK                     (0x2U)
#define PSI5_S_GCR_STOP_SHIFT                    (1U)
#define PSI5_S_GCR_STOP_WIDTH                    (1U)
#define PSI5_S_GCR_STOP(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_STOP_SHIFT)) & PSI5_S_GCR_STOP_MASK)

#define PSI5_S_GCR_RDLIS_MASK                    (0x4U)
#define PSI5_S_GCR_RDLIS_SHIFT                   (2U)
#define PSI5_S_GCR_RDLIS_WIDTH                   (1U)
#define PSI5_S_GCR_RDLIS(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_RDLIS_SHIFT)) & PSI5_S_GCR_RDLIS_MASK)

#define PSI5_S_GCR_TDLIS_MASK                    (0x8U)
#define PSI5_S_GCR_TDLIS_SHIFT                   (3U)
#define PSI5_S_GCR_TDLIS_WIDTH                   (1U)
#define PSI5_S_GCR_TDLIS(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_TDLIS_SHIFT)) & PSI5_S_GCR_TDLIS_MASK)

#define PSI5_S_GCR_RDFBM_MASK                    (0x10U)
#define PSI5_S_GCR_RDFBM_SHIFT                   (4U)
#define PSI5_S_GCR_RDFBM_WIDTH                   (1U)
#define PSI5_S_GCR_RDFBM(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_RDFBM_SHIFT)) & PSI5_S_GCR_RDFBM_MASK)

#define PSI5_S_GCR_TDFBM_MASK                    (0x20U)
#define PSI5_S_GCR_TDFBM_SHIFT                   (5U)
#define PSI5_S_GCR_TDFBM_WIDTH                   (1U)
#define PSI5_S_GCR_TDFBM(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_GCR_TDFBM_SHIFT)) & PSI5_S_GCR_TDFBM_MASK)
/*! @} */

/*! @name UARTPTO - PSI5_S UART Preset Timeout Register */
/*! @{ */

#define PSI5_S_UARTPTO_PTO_MASK                  (0xFFFU)
#define PSI5_S_UARTPTO_PTO_SHIFT                 (0U)
#define PSI5_S_UARTPTO_PTO_WIDTH                 (12U)
#define PSI5_S_UARTPTO_PTO(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTPTO_PTO_SHIFT)) & PSI5_S_UARTPTO_PTO_MASK)
/*! @} */

/*! @name UARTCTO - PSI5_S UART Current Timeout register */
/*! @{ */

#define PSI5_S_UARTCTO_CTO_MASK                  (0xFFFU)
#define PSI5_S_UARTCTO_CTO_SHIFT                 (0U)
#define PSI5_S_UARTCTO_CTO_WIDTH                 (12U)
#define PSI5_S_UARTCTO_CTO(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_UARTCTO_CTO_SHIFT)) & PSI5_S_UARTCTO_CTO_MASK)
/*! @} */

/*! @name DMATXE - DMA Tx Enable Register */
/*! @{ */

#define PSI5_S_DMATXE_DTE0_MASK                  (0x1U)
#define PSI5_S_DMATXE_DTE0_SHIFT                 (0U)
#define PSI5_S_DMATXE_DTE0_WIDTH                 (1U)
#define PSI5_S_DMATXE_DTE0(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_DMATXE_DTE0_SHIFT)) & PSI5_S_DMATXE_DTE0_MASK)
/*! @} */

/*! @name DMARXE - DMA Rx Enable Register */
/*! @{ */

#define PSI5_S_DMARXE_DRE0_MASK                  (0x1U)
#define PSI5_S_DMARXE_DRE0_SHIFT                 (0U)
#define PSI5_S_DMARXE_DRE0_WIDTH                 (1U)
#define PSI5_S_DMARXE_DRE0(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_DMARXE_DRE0_SHIFT)) & PSI5_S_DMARXE_DRE0_MASK)
/*! @} */

/*! @name PTD - PSI5_S UART Tx Idle Delay Time Register */
/*! @{ */

#define PSI5_S_PTD_EN_MASK                       (0x1U)
#define PSI5_S_PTD_EN_SHIFT                      (0U)
#define PSI5_S_PTD_EN_WIDTH                      (1U)
#define PSI5_S_PTD_EN(x)                         (((uint32_t)(((uint32_t)(x)) << PSI5_S_PTD_EN_SHIFT)) & PSI5_S_PTD_EN_MASK)

#define PSI5_S_PTD_IFD_MASK                      (0x1EU)
#define PSI5_S_PTD_IFD_SHIFT                     (1U)
#define PSI5_S_PTD_IFD_WIDTH                     (4U)
#define PSI5_S_PTD_IFD(x)                        (((uint32_t)(((uint32_t)(x)) << PSI5_S_PTD_IFD_SHIFT)) & PSI5_S_PTD_IFD_MASK)
/*! @} */

/*! @name GLCR - PSI5_S Global Control Register */
/*! @{ */

#define PSI5_S_GLCR_GLOBAL_MODE_MASK             (0x7U)
#define PSI5_S_GLCR_GLOBAL_MODE_SHIFT            (0U)
#define PSI5_S_GLCR_GLOBAL_MODE_WIDTH            (3U)
#define PSI5_S_GLCR_GLOBAL_MODE(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_GLOBAL_MODE_SHIFT)) & PSI5_S_GLCR_GLOBAL_MODE_MASK)

#define PSI5_S_GLCR_TSCNTEN_G_L_MASK             (0x8U)
#define PSI5_S_GLCR_TSCNTEN_G_L_SHIFT            (3U)
#define PSI5_S_GLCR_TSCNTEN_G_L_WIDTH            (1U)
#define PSI5_S_GLCR_TSCNTEN_G_L(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCNTEN_G_L_SHIFT)) & PSI5_S_GLCR_TSCNTEN_G_L_MASK)

#define PSI5_S_GLCR_TSCNTEN_G_MASK               (0x10U)
#define PSI5_S_GLCR_TSCNTEN_G_SHIFT              (4U)
#define PSI5_S_GLCR_TSCNTEN_G_WIDTH              (1U)
#define PSI5_S_GLCR_TSCNTEN_G(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCNTEN_G_SHIFT)) & PSI5_S_GLCR_TSCNTEN_G_MASK)

#define PSI5_S_GLCR_TSCNT_EN_A_MASK              (0x20U)
#define PSI5_S_GLCR_TSCNT_EN_A_SHIFT             (5U)
#define PSI5_S_GLCR_TSCNT_EN_A_WIDTH             (1U)
#define PSI5_S_GLCR_TSCNT_EN_A(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCNT_EN_A_SHIFT)) & PSI5_S_GLCR_TSCNT_EN_A_MASK)

#define PSI5_S_GLCR_TSCNT_EN_B_MASK              (0x40U)
#define PSI5_S_GLCR_TSCNT_EN_B_SHIFT             (6U)
#define PSI5_S_GLCR_TSCNT_EN_B_WIDTH             (1U)
#define PSI5_S_GLCR_TSCNT_EN_B(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCNT_EN_B_SHIFT)) & PSI5_S_GLCR_TSCNT_EN_B_MASK)

#define PSI5_S_GLCR_CLRTSCNT_G_L_MASK            (0x80U)
#define PSI5_S_GLCR_CLRTSCNT_G_L_SHIFT           (7U)
#define PSI5_S_GLCR_CLRTSCNT_G_L_WIDTH           (1U)
#define PSI5_S_GLCR_CLRTSCNT_G_L(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_CLRTSCNT_G_L_SHIFT)) & PSI5_S_GLCR_CLRTSCNT_G_L_MASK)

#define PSI5_S_GLCR_CLRTSCNT_G_MASK              (0x100U)
#define PSI5_S_GLCR_CLRTSCNT_G_SHIFT             (8U)
#define PSI5_S_GLCR_CLRTSCNT_G_WIDTH             (1U)
#define PSI5_S_GLCR_CLRTSCNT_G(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_CLRTSCNT_G_SHIFT)) & PSI5_S_GLCR_CLRTSCNT_G_MASK)

#define PSI5_S_GLCR_CLR_CNTR_A_MASK              (0x200U)
#define PSI5_S_GLCR_CLR_CNTR_A_SHIFT             (9U)
#define PSI5_S_GLCR_CLR_CNTR_A_WIDTH             (1U)
#define PSI5_S_GLCR_CLR_CNTR_A(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_CLR_CNTR_A_SHIFT)) & PSI5_S_GLCR_CLR_CNTR_A_MASK)

#define PSI5_S_GLCR_CLR_CNTR_B_MASK              (0x400U)
#define PSI5_S_GLCR_CLR_CNTR_B_SHIFT             (10U)
#define PSI5_S_GLCR_CLR_CNTR_B_WIDTH             (1U)
#define PSI5_S_GLCR_CLR_CNTR_B(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_CLR_CNTR_B_SHIFT)) & PSI5_S_GLCR_CLR_CNTR_B_MASK)

#define PSI5_S_GLCR_TSCS_A_MASK                  (0x800U)
#define PSI5_S_GLCR_TSCS_A_SHIFT                 (11U)
#define PSI5_S_GLCR_TSCS_A_WIDTH                 (1U)
#define PSI5_S_GLCR_TSCS_A(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCS_A_SHIFT)) & PSI5_S_GLCR_TSCS_A_MASK)

#define PSI5_S_GLCR_TSCS_B_MASK                  (0x1000U)
#define PSI5_S_GLCR_TSCS_B_SHIFT                 (12U)
#define PSI5_S_GLCR_TSCS_B_WIDTH                 (1U)
#define PSI5_S_GLCR_TSCS_B(x)                    (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_TSCS_B_SHIFT)) & PSI5_S_GLCR_TSCS_B_MASK)

#define PSI5_S_GLCR_MRU_ERR_EN_MASK              (0x2000U)
#define PSI5_S_GLCR_MRU_ERR_EN_SHIFT             (13U)
#define PSI5_S_GLCR_MRU_ERR_EN_WIDTH             (1U)
#define PSI5_S_GLCR_MRU_ERR_EN(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_MRU_ERR_EN_SHIFT)) & PSI5_S_GLCR_MRU_ERR_EN_MASK)

#define PSI5_S_GLCR_GL_DDSR_TRIG_MASK            (0x8000U)
#define PSI5_S_GLCR_GL_DDSR_TRIG_SHIFT           (15U)
#define PSI5_S_GLCR_GL_DDSR_TRIG_WIDTH           (1U)
#define PSI5_S_GLCR_GL_DDSR_TRIG(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_GL_DDSR_TRIG_SHIFT)) & PSI5_S_GLCR_GL_DDSR_TRIG_MASK)

#define PSI5_S_GLCR_GTM_TRIG_SEL_MASK            (0x30000U)
#define PSI5_S_GLCR_GTM_TRIG_SEL_SHIFT           (16U)
#define PSI5_S_GLCR_GTM_TRIG_SEL_WIDTH           (2U)
#define PSI5_S_GLCR_GTM_TRIG_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_GTM_TRIG_SEL_SHIFT)) & PSI5_S_GLCR_GTM_TRIG_SEL_MASK)

#define PSI5_S_GLCR_DEBUG_EN_MASK                (0x40000U)
#define PSI5_S_GLCR_DEBUG_EN_SHIFT               (18U)
#define PSI5_S_GLCR_DEBUG_EN_WIDTH               (1U)
#define PSI5_S_GLCR_DEBUG_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_DEBUG_EN_SHIFT)) & PSI5_S_GLCR_DEBUG_EN_MASK)

#define PSI5_S_GLCR_IE_DIRCMD_RDY_MASK           (0x100000U)
#define PSI5_S_GLCR_IE_DIRCMD_RDY_SHIFT          (20U)
#define PSI5_S_GLCR_IE_DIRCMD_RDY_WIDTH          (1U)
#define PSI5_S_GLCR_IE_DIRCMD_RDY(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_IE_DIRCMD_RDY_SHIFT)) & PSI5_S_GLCR_IE_DIRCMD_RDY_MASK)

#define PSI5_S_GLCR_DIRCMD_LEN_MASK              (0xC00000U)
#define PSI5_S_GLCR_DIRCMD_LEN_SHIFT             (22U)
#define PSI5_S_GLCR_DIRCMD_LEN_WIDTH             (2U)
#define PSI5_S_GLCR_DIRCMD_LEN(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLCR_DIRCMD_LEN_SHIFT)) & PSI5_S_GLCR_DIRCMD_LEN_MASK)
/*! @} */

/*! @name GLSR - PSI5_S Global Status Register */
/*! @{ */

#define PSI5_S_GLSR_CHID_MASK                    (0x7U)
#define PSI5_S_GLSR_CHID_SHIFT                   (0U)
#define PSI5_S_GLSR_CHID_WIDTH                   (3U)
#define PSI5_S_GLSR_CHID(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLSR_CHID_SHIFT)) & PSI5_S_GLSR_CHID_MASK)

#define PSI5_S_GLSR_FID_MASK                     (0x38U)
#define PSI5_S_GLSR_FID_SHIFT                    (3U)
#define PSI5_S_GLSR_FID_WIDTH                    (3U)
#define PSI5_S_GLSR_FID(x)                       (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLSR_FID_SHIFT)) & PSI5_S_GLSR_FID_MASK)

#define PSI5_S_GLSR_MRU_ERR_MASK                 (0x2000U)
#define PSI5_S_GLSR_MRU_ERR_SHIFT                (13U)
#define PSI5_S_GLSR_MRU_ERR_WIDTH                (1U)
#define PSI5_S_GLSR_MRU_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLSR_MRU_ERR_SHIFT)) & PSI5_S_GLSR_MRU_ERR_MASK)

#define PSI5_S_GLSR_GL_MODETR_DONE_MASK          (0x4000U)
#define PSI5_S_GLSR_GL_MODETR_DONE_SHIFT         (14U)
#define PSI5_S_GLSR_GL_MODETR_DONE_WIDTH         (1U)
#define PSI5_S_GLSR_GL_MODETR_DONE(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLSR_GL_MODETR_DONE_SHIFT)) & PSI5_S_GLSR_GL_MODETR_DONE_MASK)

#define PSI5_S_GLSR_DIRCMD_RDY_MASK              (0x100000U)
#define PSI5_S_GLSR_DIRCMD_RDY_SHIFT             (20U)
#define PSI5_S_GLSR_DIRCMD_RDY_WIDTH             (1U)
#define PSI5_S_GLSR_DIRCMD_RDY(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_GLSR_DIRCMD_RDY_SHIFT)) & PSI5_S_GLSR_DIRCMD_RDY_MASK)
/*! @} */

/*! @name CH_BASE_ADDR - PSI5_S CHANNEL_BASE_ADDRESS */
/*! @{ */

#define PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_MASK (0xFFFFFFFFU)
#define PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_SHIFT (0U)
#define PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_WIDTH (32U)
#define PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_SHIFT)) & PSI5_S_CH_BASE_ADDR_MAILBOX_BASE_ADDR_MASK)
/*! @} */

/*! @name MRU_BUF2_REG0 - PSI5_S MRU OUTPUT BUFFER2 REGISTER0 */
/*! @{ */

#define PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR_MASK (0xFFFFFFFFU)
#define PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR_SHIFT (0U)
#define PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR_WIDTH (32U)
#define PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR_SHIFT)) & PSI5_S_MRU_BUF2_REG0_CHANNEL_SPECIFIC_MAILBOX_ADDR_MASK)
/*! @} */

/*! @name MRU_BUF2_REG1 - PSI5_S MRU OUTPUT BUFFER2 REGISTER1 */
/*! @{ */

#define PSI5_S_MRU_BUF2_REG1_XCRC_MASK           (0x3FU)
#define PSI5_S_MRU_BUF2_REG1_XCRC_SHIFT          (0U)
#define PSI5_S_MRU_BUF2_REG1_XCRC_WIDTH          (6U)
#define PSI5_S_MRU_BUF2_REG1_XCRC(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_XCRC_SHIFT)) & PSI5_S_MRU_BUF2_REG1_XCRC_MASK)

#define PSI5_S_MRU_BUF2_REG1_XCRC_ERR_MASK       (0x40U)
#define PSI5_S_MRU_BUF2_REG1_XCRC_ERR_SHIFT      (6U)
#define PSI5_S_MRU_BUF2_REG1_XCRC_ERR_WIDTH      (1U)
#define PSI5_S_MRU_BUF2_REG1_XCRC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_XCRC_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_XCRC_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_CRC_MASK            (0x380U)
#define PSI5_S_MRU_BUF2_REG1_CRC_SHIFT           (7U)
#define PSI5_S_MRU_BUF2_REG1_CRC_WIDTH           (3U)
#define PSI5_S_MRU_BUF2_REG1_CRC(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_CRC_SHIFT)) & PSI5_S_MRU_BUF2_REG1_CRC_MASK)

#define PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_MASK  (0x400U)
#define PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_SHIFT (10U)
#define PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_WIDTH (1U)
#define PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR(x)    (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_CRC_ERR_P_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_ERR_MASK            (0x1800U)
#define PSI5_S_MRU_BUF2_REG1_ERR_SHIFT           (11U)
#define PSI5_S_MRU_BUF2_REG1_ERR_WIDTH           (2U)
#define PSI5_S_MRU_BUF2_REG1_ERR(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_HD_ERR_MASK         (0x2000U)
#define PSI5_S_MRU_BUF2_REG1_HD_ERR_SHIFT        (13U)
#define PSI5_S_MRU_BUF2_REG1_HD_ERR_WIDTH        (1U)
#define PSI5_S_MRU_BUF2_REG1_HD_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_HD_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_HD_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_MASK      (0x4000U)
#define PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_SHIFT     (14U)
#define PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_WIDTH     (1U)
#define PSI5_S_MRU_BUF2_REG1_SCI_P_ERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_SCI_P_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_MASK      (0x8000U)
#define PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_SHIFT     (15U)
#define PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_WIDTH     (1U)
#define PSI5_S_MRU_BUF2_REG1_SCI_F_ERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_SCI_F_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_MASK      (0x10000U)
#define PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_SHIFT     (16U)
#define PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_WIDTH     (1U)
#define PSI5_S_MRU_BUF2_REG1_SCI_O_ERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_SCI_O_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_F_WD_ERR_MASK       (0x20000U)
#define PSI5_S_MRU_BUF2_REG1_F_WD_ERR_SHIFT      (17U)
#define PSI5_S_MRU_BUF2_REG1_F_WD_ERR_WIDTH      (1U)
#define PSI5_S_MRU_BUF2_REG1_F_WD_ERR(x)         (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_F_WD_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_F_WD_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_MASK      (0x40000U)
#define PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_SHIFT     (18U)
#define PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_WIDTH     (1U)
#define PSI5_S_MRU_BUF2_REG1_R_OVL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_R_OVL_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_FID_MASK            (0x380000U)
#define PSI5_S_MRU_BUF2_REG1_FID_SHIFT           (19U)
#define PSI5_S_MRU_BUF2_REG1_FID_WIDTH           (3U)
#define PSI5_S_MRU_BUF2_REG1_FID(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_FID_SHIFT)) & PSI5_S_MRU_BUF2_REG1_FID_MASK)

#define PSI5_S_MRU_BUF2_REG1_CHID_MASK           (0x1C00000U)
#define PSI5_S_MRU_BUF2_REG1_CHID_SHIFT          (22U)
#define PSI5_S_MRU_BUF2_REG1_CHID_WIDTH          (3U)
#define PSI5_S_MRU_BUF2_REG1_CHID(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_CHID_SHIFT)) & PSI5_S_MRU_BUF2_REG1_CHID_MASK)

#define PSI5_S_MRU_BUF2_REG1_N_ERR_MASK          (0x2000000U)
#define PSI5_S_MRU_BUF2_REG1_N_ERR_SHIFT         (25U)
#define PSI5_S_MRU_BUF2_REG1_N_ERR_WIDTH         (1U)
#define PSI5_S_MRU_BUF2_REG1_N_ERR(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_N_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_N_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_MASK      (0x4000000U)
#define PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_SHIFT     (26U)
#define PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_WIDTH     (1U)
#define PSI5_S_MRU_BUF2_REG1_R_UVL_ERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_SHIFT)) & PSI5_S_MRU_BUF2_REG1_R_UVL_ERR_MASK)

#define PSI5_S_MRU_BUF2_REG1_DCI_MASK            (0xF0000000U)
#define PSI5_S_MRU_BUF2_REG1_DCI_SHIFT           (28U)
#define PSI5_S_MRU_BUF2_REG1_DCI_WIDTH           (4U)
#define PSI5_S_MRU_BUF2_REG1_DCI(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG1_DCI_SHIFT)) & PSI5_S_MRU_BUF2_REG1_DCI_MASK)
/*! @} */

/*! @name MRU_BUF2_REG2 - PSI5_S MRU OUTPUT BUFFER2 REGISTER2 */
/*! @{ */

#define PSI5_S_MRU_BUF2_REG2_PS_DATA_MASK        (0xFFFFFFFU)
#define PSI5_S_MRU_BUF2_REG2_PS_DATA_SHIFT       (0U)
#define PSI5_S_MRU_BUF2_REG2_PS_DATA_WIDTH       (28U)
#define PSI5_S_MRU_BUF2_REG2_PS_DATA(x)          (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG2_PS_DATA_SHIFT)) & PSI5_S_MRU_BUF2_REG2_PS_DATA_MASK)

#define PSI5_S_MRU_BUF2_REG2_DCI_MASK            (0xF0000000U)
#define PSI5_S_MRU_BUF2_REG2_DCI_SHIFT           (28U)
#define PSI5_S_MRU_BUF2_REG2_DCI_WIDTH           (4U)
#define PSI5_S_MRU_BUF2_REG2_DCI(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG2_DCI_SHIFT)) & PSI5_S_MRU_BUF2_REG2_DCI_MASK)
/*! @} */

/*! @name MRU_BUF2_REG3 - PSI5_S MRU OUTPUT BUFFER2 REGISTER3 */
/*! @{ */

#define PSI5_S_MRU_BUF2_REG3_TIMESTAMP_MASK      (0xFFFFFFU)
#define PSI5_S_MRU_BUF2_REG3_TIMESTAMP_SHIFT     (0U)
#define PSI5_S_MRU_BUF2_REG3_TIMESTAMP_WIDTH     (24U)
#define PSI5_S_MRU_BUF2_REG3_TIMESTAMP(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG3_TIMESTAMP_SHIFT)) & PSI5_S_MRU_BUF2_REG3_TIMESTAMP_MASK)

#define PSI5_S_MRU_BUF2_REG3_DCI_MASK            (0xF0000000U)
#define PSI5_S_MRU_BUF2_REG3_DCI_SHIFT           (28U)
#define PSI5_S_MRU_BUF2_REG3_DCI_WIDTH           (4U)
#define PSI5_S_MRU_BUF2_REG3_DCI(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_MRU_BUF2_REG3_DCI_SHIFT)) & PSI5_S_MRU_BUF2_REG3_DCI_MASK)
/*! @} */

/*! @name MBOX_SR_IRQ - PSI5_S Mbox Status Irq */
/*! @{ */

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH0_MASK         (0x1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH0_SHIFT        (0U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH0_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH0(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH0_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH0_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH1_MASK         (0x2U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH1_SHIFT        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH1_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH1(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH1_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH1_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH2_MASK         (0x4U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH2_SHIFT        (2U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH2_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH2(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH2_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH2_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH3_MASK         (0x8U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH3_SHIFT        (3U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH3_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH3(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH3_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH3_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH4_MASK         (0x10U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH4_SHIFT        (4U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH4_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH4(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH4_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH4_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH5_MASK         (0x20U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH5_SHIFT        (5U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH5_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH5(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH5_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH5_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH6_MASK         (0x40U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH6_SHIFT        (6U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH6_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH6(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH6_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH6_MASK)

#define PSI5_S_MBOX_SR_IRQ_MBOX_CH7_MASK         (0x80U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH7_SHIFT        (7U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH7_WIDTH        (1U)
#define PSI5_S_MBOX_SR_IRQ_MBOX_CH7(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_IRQ_MBOX_CH7_SHIFT)) & PSI5_S_MBOX_SR_IRQ_MBOX_CH7_MASK)
/*! @} */

/*! @name ERR_SR_IRQ - PSI5_S Error Status IRQ */
/*! @{ */

#define PSI5_S_ERR_SR_IRQ_XCRC_ERR_MASK          (0x1U)
#define PSI5_S_ERR_SR_IRQ_XCRC_ERR_SHIFT         (0U)
#define PSI5_S_ERR_SR_IRQ_XCRC_ERR_WIDTH         (1U)
#define PSI5_S_ERR_SR_IRQ_XCRC_ERR(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_XCRC_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_XCRC_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_MASK     (0x2U)
#define PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_SHIFT    (1U)
#define PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_WIDTH    (1U)
#define PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR(x)       (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_CRC_ERR_P_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_HD_ERR_MASK            (0x4U)
#define PSI5_S_ERR_SR_IRQ_HD_ERR_SHIFT           (2U)
#define PSI5_S_ERR_SR_IRQ_HD_ERR_WIDTH           (1U)
#define PSI5_S_ERR_SR_IRQ_HD_ERR(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_HD_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_HD_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_SCI_P_ERR_MASK         (0x8U)
#define PSI5_S_ERR_SR_IRQ_SCI_P_ERR_SHIFT        (3U)
#define PSI5_S_ERR_SR_IRQ_SCI_P_ERR_WIDTH        (1U)
#define PSI5_S_ERR_SR_IRQ_SCI_P_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_SCI_P_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_SCI_P_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_SCI_F_ERR_MASK         (0x10U)
#define PSI5_S_ERR_SR_IRQ_SCI_F_ERR_SHIFT        (4U)
#define PSI5_S_ERR_SR_IRQ_SCI_F_ERR_WIDTH        (1U)
#define PSI5_S_ERR_SR_IRQ_SCI_F_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_SCI_F_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_SCI_F_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_SCI_O_ERR_MASK         (0x20U)
#define PSI5_S_ERR_SR_IRQ_SCI_O_ERR_SHIFT        (5U)
#define PSI5_S_ERR_SR_IRQ_SCI_O_ERR_WIDTH        (1U)
#define PSI5_S_ERR_SR_IRQ_SCI_O_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_SCI_O_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_SCI_O_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_F_WD_ERR_MASK          (0x40U)
#define PSI5_S_ERR_SR_IRQ_F_WD_ERR_SHIFT         (6U)
#define PSI5_S_ERR_SR_IRQ_F_WD_ERR_WIDTH         (1U)
#define PSI5_S_ERR_SR_IRQ_F_WD_ERR(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_F_WD_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_F_WD_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_R_OVL_ERR_MASK         (0x80U)
#define PSI5_S_ERR_SR_IRQ_R_OVL_ERR_SHIFT        (7U)
#define PSI5_S_ERR_SR_IRQ_R_OVL_ERR_WIDTH        (1U)
#define PSI5_S_ERR_SR_IRQ_R_OVL_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_R_OVL_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_R_OVL_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_N_ERR_MASK             (0x100U)
#define PSI5_S_ERR_SR_IRQ_N_ERR_SHIFT            (8U)
#define PSI5_S_ERR_SR_IRQ_N_ERR_WIDTH            (1U)
#define PSI5_S_ERR_SR_IRQ_N_ERR(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_N_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_N_ERR_MASK)

#define PSI5_S_ERR_SR_IRQ_R_UVL_ERR_MASK         (0x200U)
#define PSI5_S_ERR_SR_IRQ_R_UVL_ERR_SHIFT        (9U)
#define PSI5_S_ERR_SR_IRQ_R_UVL_ERR_WIDTH        (1U)
#define PSI5_S_ERR_SR_IRQ_R_UVL_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SR_IRQ_R_UVL_ERR_SHIFT)) & PSI5_S_ERR_SR_IRQ_R_UVL_ERR_MASK)
/*! @} */

/*! @name MBOX_SEL_IRQ - PSI5_S Mailbox select IRQ[irq_n] */
/*! @{ */

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_MASK    (0x1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_SHIFT   (0U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH0_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL_MASK    (0x2U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL_SHIFT   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH1_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL_MASK    (0x4U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL_SHIFT   (2U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH2_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL_MASK    (0x8U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL_SHIFT   (3U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH3_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL_MASK    (0x10U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL_SHIFT   (4U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH4_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL_MASK    (0x20U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL_SHIFT   (5U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH5_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL_MASK    (0x40U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL_SHIFT   (6U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH6_SEL_MASK)

#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL_MASK    (0x80U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL_SHIFT   (7U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL_WIDTH   (1U)
#define PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL_SHIFT)) & PSI5_S_MBOX_SEL_IRQ_MBOX_CH7_SEL_MASK)
/*! @} */

/*! @name ERR_SEL_IRQ - PSI5_S Error Select IRQ[irq_n] */
/*! @{ */

#define PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_MASK     (0x1U)
#define PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_SHIFT    (0U)
#define PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_WIDTH    (1U)
#define PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL(x)       (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_XCRC_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_MASK      (0x2U)
#define PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_SHIFT     (1U)
#define PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_WIDTH     (1U)
#define PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_CRC_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_MASK       (0x4U)
#define PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_SHIFT      (2U)
#define PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_WIDTH      (1U)
#define PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL(x)         (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_HD_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_MASK    (0x8U)
#define PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_SHIFT   (3U)
#define PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_WIDTH   (1U)
#define PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_SCI_P_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_MASK    (0x10U)
#define PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_SHIFT   (4U)
#define PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_WIDTH   (1U)
#define PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_SCI_F_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_MASK    (0x20U)
#define PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_SHIFT   (5U)
#define PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_WIDTH   (1U)
#define PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_SCI_O_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_MASK     (0x40U)
#define PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_SHIFT    (6U)
#define PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_WIDTH    (1U)
#define PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL(x)       (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_F_WD_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_MASK    (0x80U)
#define PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_SHIFT   (7U)
#define PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_WIDTH   (1U)
#define PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_R_OVL_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_MASK        (0x100U)
#define PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_SHIFT       (8U)
#define PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_WIDTH       (1U)
#define PSI5_S_ERR_SEL_IRQ_N_ERR_SEL(x)          (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_N_ERR_SEL_MASK)

#define PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_MASK    (0x200U)
#define PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_SHIFT   (9U)
#define PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_WIDTH   (1U)
#define PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL(x)      (((uint32_t)(((uint32_t)(x)) << PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_SHIFT)) & PSI5_S_ERR_SEL_IRQ_R_UVL_ERR_SEL_MASK)
/*! @} */

/*! @name WDGTSSR - PSI5_S Watchdog Error Status and Watchdog Timestamp status register */
/*! @{ */

#define PSI5_S_WDGTSSR_WDTS_STATUS_MASK          (0xFFFFFFU)
#define PSI5_S_WDGTSSR_WDTS_STATUS_SHIFT         (0U)
#define PSI5_S_WDGTSSR_WDTS_STATUS_WIDTH         (24U)
#define PSI5_S_WDGTSSR_WDTS_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_WDGTSSR_WDTS_STATUS_SHIFT)) & PSI5_S_WDGTSSR_WDTS_STATUS_MASK)

#define PSI5_S_WDGTSSR_F_WD_ERR_STATUS_MASK      (0xFE000000U)
#define PSI5_S_WDGTSSR_F_WD_ERR_STATUS_SHIFT     (25U)
#define PSI5_S_WDGTSSR_F_WD_ERR_STATUS_WIDTH     (7U)
#define PSI5_S_WDGTSSR_F_WD_ERR_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_WDGTSSR_F_WD_ERR_STATUS_SHIFT)) & PSI5_S_WDGTSSR_F_WD_ERR_STATUS_MASK)
/*! @} */

/*! @name DIRCMD - PSI5_S ECU to Sensor Direct Command Write register */
/*! @{ */

#define PSI5_S_DIRCMD_DIRCMD_BYTE0_MASK          (0xFFU)
#define PSI5_S_DIRCMD_DIRCMD_BYTE0_SHIFT         (0U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE0_WIDTH         (8U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE0(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_DIRCMD_DIRCMD_BYTE0_SHIFT)) & PSI5_S_DIRCMD_DIRCMD_BYTE0_MASK)

#define PSI5_S_DIRCMD_DIRCMD_BYTE1_MASK          (0xFF00U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE1_SHIFT         (8U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE1_WIDTH         (8U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE1(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_DIRCMD_DIRCMD_BYTE1_SHIFT)) & PSI5_S_DIRCMD_DIRCMD_BYTE1_MASK)

#define PSI5_S_DIRCMD_DIRCMD_BYTE2_MASK          (0xFF0000U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE2_SHIFT         (16U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE2_WIDTH         (8U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE2(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_DIRCMD_DIRCMD_BYTE2_SHIFT)) & PSI5_S_DIRCMD_DIRCMD_BYTE2_MASK)

#define PSI5_S_DIRCMD_DIRCMD_BYTE3_MASK          (0xFF000000U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE3_SHIFT         (24U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE3_WIDTH         (8U)
#define PSI5_S_DIRCMD_DIRCMD_BYTE3(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_DIRCMD_DIRCMD_BYTE3_SHIFT)) & PSI5_S_DIRCMD_DIRCMD_BYTE3_MASK)
/*! @} */

/*! @name CH0_MSGA - PSI5_S channel 0 message configuration register A */
/*! @{ */

#define PSI5_S_CH0_MSGA_TSBUF_EN_MASK            (0x4U)
#define PSI5_S_CH0_MSGA_TSBUF_EN_SHIFT           (2U)
#define PSI5_S_CH0_MSGA_TSBUF_EN_WIDTH           (1U)
#define PSI5_S_CH0_MSGA_TSBUF_EN(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MSGA_TSBUF_EN_SHIFT)) & PSI5_S_CH0_MSGA_TSBUF_EN_MASK)

#define PSI5_S_CH0_MSGA_TSBUF_CLR_MASK           (0x8U)
#define PSI5_S_CH0_MSGA_TSBUF_CLR_SHIFT          (3U)
#define PSI5_S_CH0_MSGA_TSBUF_CLR_WIDTH          (1U)
#define PSI5_S_CH0_MSGA_TSBUF_CLR(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MSGA_TSBUF_CLR_SHIFT)) & PSI5_S_CH0_MSGA_TSBUF_CLR_MASK)

#define PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL_MASK   (0x20U)
#define PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL_SHIFT  (5U)
#define PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL_WIDTH  (1U)
#define PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL(x)     (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL_SHIFT)) & PSI5_S_CH0_MSGA_TIMESTAMP_A_B_SEL_MASK)

#define PSI5_S_CH0_MSGA_F0_BYTE_MASK             (0x700U)
#define PSI5_S_CH0_MSGA_F0_BYTE_SHIFT            (8U)
#define PSI5_S_CH0_MSGA_F0_BYTE_WIDTH            (3U)
#define PSI5_S_CH0_MSGA_F0_BYTE(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MSGA_F0_BYTE_SHIFT)) & PSI5_S_CH0_MSGA_F0_BYTE_MASK)
/*! @} */

/*! @name CH0_MSGB - PSI5_S channel 0 message configuration register B */
/*! @{ */

#define PSI5_S_CH0_MSGB_F0_payload_MASK          (0x1FU)
#define PSI5_S_CH0_MSGB_F0_payload_SHIFT         (0U)
#define PSI5_S_CH0_MSGB_F0_payload_WIDTH         (5U)
#define PSI5_S_CH0_MSGB_F0_payload(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MSGB_F0_payload_SHIFT)) & PSI5_S_CH0_MSGB_F0_payload_MASK)
/*! @} */

/*! @name CH0_MBOX_SR - PSI5_S Mailbox status register channel0 */
/*! @{ */

#define PSI5_S_CH0_MBOX_SR_F0_READ_MASK          (0x1U)
#define PSI5_S_CH0_MBOX_SR_F0_READ_SHIFT         (0U)
#define PSI5_S_CH0_MBOX_SR_F0_READ_WIDTH         (1U)
#define PSI5_S_CH0_MBOX_SR_F0_READ(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F0_READ_SHIFT)) & PSI5_S_CH0_MBOX_SR_F0_READ_MASK)

#define PSI5_S_CH0_MBOX_SR_F0_OV_MASK            (0x2U)
#define PSI5_S_CH0_MBOX_SR_F0_OV_SHIFT           (1U)
#define PSI5_S_CH0_MBOX_SR_F0_OV_WIDTH           (1U)
#define PSI5_S_CH0_MBOX_SR_F0_OV(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F0_OV_SHIFT)) & PSI5_S_CH0_MBOX_SR_F0_OV_MASK)

#define PSI5_S_CH0_MBOX_SR_F0_ERR_MASK           (0x4U)
#define PSI5_S_CH0_MBOX_SR_F0_ERR_SHIFT          (2U)
#define PSI5_S_CH0_MBOX_SR_F0_ERR_WIDTH          (1U)
#define PSI5_S_CH0_MBOX_SR_F0_ERR(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F0_ERR_SHIFT)) & PSI5_S_CH0_MBOX_SR_F0_ERR_MASK)

#define PSI5_S_CH0_MBOX_SR_F1_READ_MASK          (0x8U)
#define PSI5_S_CH0_MBOX_SR_F1_READ_SHIFT         (3U)
#define PSI5_S_CH0_MBOX_SR_F1_READ_WIDTH         (1U)
#define PSI5_S_CH0_MBOX_SR_F1_READ(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F1_READ_SHIFT)) & PSI5_S_CH0_MBOX_SR_F1_READ_MASK)

#define PSI5_S_CH0_MBOX_SR_F1_OV_MASK            (0x10U)
#define PSI5_S_CH0_MBOX_SR_F1_OV_SHIFT           (4U)
#define PSI5_S_CH0_MBOX_SR_F1_OV_WIDTH           (1U)
#define PSI5_S_CH0_MBOX_SR_F1_OV(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F1_OV_SHIFT)) & PSI5_S_CH0_MBOX_SR_F1_OV_MASK)

#define PSI5_S_CH0_MBOX_SR_F1_ERR_MASK           (0x20U)
#define PSI5_S_CH0_MBOX_SR_F1_ERR_SHIFT          (5U)
#define PSI5_S_CH0_MBOX_SR_F1_ERR_WIDTH          (1U)
#define PSI5_S_CH0_MBOX_SR_F1_ERR(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_CH0_MBOX_SR_F1_ERR_SHIFT)) & PSI5_S_CH0_MBOX_SR_F1_ERR_MASK)
/*! @} */

/*! @name MSGA - PSI5_S channel message configuration register A */
/*! @{ */

#define PSI5_S_MSGA_CH_EN_MASK                   (0x1U)
#define PSI5_S_MSGA_CH_EN_SHIFT                  (0U)
#define PSI5_S_MSGA_CH_EN_WIDTH                  (1U)
#define PSI5_S_MSGA_CH_EN(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_CH_EN_SHIFT)) & PSI5_S_MSGA_CH_EN_MASK)

#define PSI5_S_MSGA_G_PC_MASK                    (0x2U)
#define PSI5_S_MSGA_G_PC_SHIFT                   (1U)
#define PSI5_S_MSGA_G_PC_WIDTH                   (1U)
#define PSI5_S_MSGA_G_PC(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_G_PC_SHIFT)) & PSI5_S_MSGA_G_PC_MASK)

#define PSI5_S_MSGA_TSBUF_EN_MASK                (0x4U)
#define PSI5_S_MSGA_TSBUF_EN_SHIFT               (2U)
#define PSI5_S_MSGA_TSBUF_EN_WIDTH               (1U)
#define PSI5_S_MSGA_TSBUF_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_TSBUF_EN_SHIFT)) & PSI5_S_MSGA_TSBUF_EN_MASK)

#define PSI5_S_MSGA_TSBUF_CLR_MASK               (0x8U)
#define PSI5_S_MSGA_TSBUF_CLR_SHIFT              (3U)
#define PSI5_S_MSGA_TSBUF_CLR_WIDTH              (1U)
#define PSI5_S_MSGA_TSBUF_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_TSBUF_CLR_SHIFT)) & PSI5_S_MSGA_TSBUF_CLR_MASK)

#define PSI5_S_MSGA_TMSG_TCMD_MASK               (0x10U)
#define PSI5_S_MSGA_TMSG_TCMD_SHIFT              (4U)
#define PSI5_S_MSGA_TMSG_TCMD_WIDTH              (1U)
#define PSI5_S_MSGA_TMSG_TCMD(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_TMSG_TCMD_SHIFT)) & PSI5_S_MSGA_TMSG_TCMD_MASK)

#define PSI5_S_MSGA_TIME_STAMP_A_B_SEL_MASK      (0x20U)
#define PSI5_S_MSGA_TIME_STAMP_A_B_SEL_SHIFT     (5U)
#define PSI5_S_MSGA_TIME_STAMP_A_B_SEL_WIDTH     (1U)
#define PSI5_S_MSGA_TIME_STAMP_A_B_SEL(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_TIME_STAMP_A_B_SEL_SHIFT)) & PSI5_S_MSGA_TIME_STAMP_A_B_SEL_MASK)

#define PSI5_S_MSGA_MODE_MASK                    (0x40U)
#define PSI5_S_MSGA_MODE_SHIFT                   (6U)
#define PSI5_S_MSGA_MODE_WIDTH                   (1U)
#define PSI5_S_MSGA_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_MODE_SHIFT)) & PSI5_S_MSGA_MODE_MASK)

#define PSI5_S_MSGA_L_PC0_MASK                   (0x80U)
#define PSI5_S_MSGA_L_PC0_SHIFT                  (7U)
#define PSI5_S_MSGA_L_PC0_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC0(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC0_SHIFT)) & PSI5_S_MSGA_L_PC0_MASK)

#define PSI5_S_MSGA_F0_BYTE_MASK                 (0x700U)
#define PSI5_S_MSGA_F0_BYTE_SHIFT                (8U)
#define PSI5_S_MSGA_F0_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F0_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F0_BYTE_SHIFT)) & PSI5_S_MSGA_F0_BYTE_MASK)

#define PSI5_S_MSGA_L_PC1_MASK                   (0x800U)
#define PSI5_S_MSGA_L_PC1_SHIFT                  (11U)
#define PSI5_S_MSGA_L_PC1_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC1(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC1_SHIFT)) & PSI5_S_MSGA_L_PC1_MASK)

#define PSI5_S_MSGA_F1_BYTE_MASK                 (0x7000U)
#define PSI5_S_MSGA_F1_BYTE_SHIFT                (12U)
#define PSI5_S_MSGA_F1_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F1_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F1_BYTE_SHIFT)) & PSI5_S_MSGA_F1_BYTE_MASK)

#define PSI5_S_MSGA_L_PC2_MASK                   (0x8000U)
#define PSI5_S_MSGA_L_PC2_SHIFT                  (15U)
#define PSI5_S_MSGA_L_PC2_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC2(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC2_SHIFT)) & PSI5_S_MSGA_L_PC2_MASK)

#define PSI5_S_MSGA_F2_BYTE_MASK                 (0x70000U)
#define PSI5_S_MSGA_F2_BYTE_SHIFT                (16U)
#define PSI5_S_MSGA_F2_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F2_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F2_BYTE_SHIFT)) & PSI5_S_MSGA_F2_BYTE_MASK)

#define PSI5_S_MSGA_L_PC3_MASK                   (0x80000U)
#define PSI5_S_MSGA_L_PC3_SHIFT                  (19U)
#define PSI5_S_MSGA_L_PC3_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC3(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC3_SHIFT)) & PSI5_S_MSGA_L_PC3_MASK)

#define PSI5_S_MSGA_F3_BYTE_MASK                 (0x700000U)
#define PSI5_S_MSGA_F3_BYTE_SHIFT                (20U)
#define PSI5_S_MSGA_F3_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F3_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F3_BYTE_SHIFT)) & PSI5_S_MSGA_F3_BYTE_MASK)

#define PSI5_S_MSGA_L_PC4_MASK                   (0x800000U)
#define PSI5_S_MSGA_L_PC4_SHIFT                  (23U)
#define PSI5_S_MSGA_L_PC4_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC4(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC4_SHIFT)) & PSI5_S_MSGA_L_PC4_MASK)

#define PSI5_S_MSGA_F4_BYTE_MASK                 (0x7000000U)
#define PSI5_S_MSGA_F4_BYTE_SHIFT                (24U)
#define PSI5_S_MSGA_F4_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F4_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F4_BYTE_SHIFT)) & PSI5_S_MSGA_F4_BYTE_MASK)

#define PSI5_S_MSGA_L_PC5_MASK                   (0x8000000U)
#define PSI5_S_MSGA_L_PC5_SHIFT                  (27U)
#define PSI5_S_MSGA_L_PC5_WIDTH                  (1U)
#define PSI5_S_MSGA_L_PC5(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC5_SHIFT)) & PSI5_S_MSGA_L_PC5_MASK)

#define PSI5_S_MSGA_F5_BYTE_MASK                 (0x70000000U)
#define PSI5_S_MSGA_F5_BYTE_SHIFT                (28U)
#define PSI5_S_MSGA_F5_BYTE_WIDTH                (3U)
#define PSI5_S_MSGA_F5_BYTE(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_F5_BYTE_SHIFT)) & PSI5_S_MSGA_F5_BYTE_MASK)

#define PSI5_S_MSGA_L_PC_EN_MASK                 (0x80000000U)
#define PSI5_S_MSGA_L_PC_EN_SHIFT                (31U)
#define PSI5_S_MSGA_L_PC_EN_WIDTH                (1U)
#define PSI5_S_MSGA_L_PC_EN(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGA_L_PC_EN_SHIFT)) & PSI5_S_MSGA_L_PC_EN_MASK)
/*! @} */

/*! @name MSGB - PSI5_S channel message configuration register B */
/*! @{ */

#define PSI5_S_MSGB_F0_payload_MASK              (0x1FU)
#define PSI5_S_MSGB_F0_payload_SHIFT             (0U)
#define PSI5_S_MSGB_F0_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F0_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F0_payload_SHIFT)) & PSI5_S_MSGB_F0_payload_MASK)

#define PSI5_S_MSGB_F1_payload_MASK              (0x3E0U)
#define PSI5_S_MSGB_F1_payload_SHIFT             (5U)
#define PSI5_S_MSGB_F1_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F1_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F1_payload_SHIFT)) & PSI5_S_MSGB_F1_payload_MASK)

#define PSI5_S_MSGB_F2_payload_MASK              (0x7C00U)
#define PSI5_S_MSGB_F2_payload_SHIFT             (10U)
#define PSI5_S_MSGB_F2_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F2_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F2_payload_SHIFT)) & PSI5_S_MSGB_F2_payload_MASK)

#define PSI5_S_MSGB_F3_payload_MASK              (0xF8000U)
#define PSI5_S_MSGB_F3_payload_SHIFT             (15U)
#define PSI5_S_MSGB_F3_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F3_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F3_payload_SHIFT)) & PSI5_S_MSGB_F3_payload_MASK)

#define PSI5_S_MSGB_F4_payload_MASK              (0x1F00000U)
#define PSI5_S_MSGB_F4_payload_SHIFT             (20U)
#define PSI5_S_MSGB_F4_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F4_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F4_payload_SHIFT)) & PSI5_S_MSGB_F4_payload_MASK)

#define PSI5_S_MSGB_F5_payload_MASK              (0x3E000000U)
#define PSI5_S_MSGB_F5_payload_SHIFT             (25U)
#define PSI5_S_MSGB_F5_payload_WIDTH             (5U)
#define PSI5_S_MSGB_F5_payload(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MSGB_F5_payload_SHIFT)) & PSI5_S_MSGB_F5_payload_MASK)
/*! @} */

/*! @name MBOX_SR - PSI5_S Mailbox status register channel */
/*! @{ */

#define PSI5_S_MBOX_SR_F0_READ_MASK              (0x1U)
#define PSI5_S_MBOX_SR_F0_READ_SHIFT             (0U)
#define PSI5_S_MBOX_SR_F0_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F0_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F0_READ_SHIFT)) & PSI5_S_MBOX_SR_F0_READ_MASK)

#define PSI5_S_MBOX_SR_F0_OV_MASK                (0x2U)
#define PSI5_S_MBOX_SR_F0_OV_SHIFT               (1U)
#define PSI5_S_MBOX_SR_F0_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F0_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F0_OV_SHIFT)) & PSI5_S_MBOX_SR_F0_OV_MASK)

#define PSI5_S_MBOX_SR_F0_ERR_MASK               (0x4U)
#define PSI5_S_MBOX_SR_F0_ERR_SHIFT              (2U)
#define PSI5_S_MBOX_SR_F0_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F0_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F0_ERR_SHIFT)) & PSI5_S_MBOX_SR_F0_ERR_MASK)

#define PSI5_S_MBOX_SR_F1_READ_MASK              (0x8U)
#define PSI5_S_MBOX_SR_F1_READ_SHIFT             (3U)
#define PSI5_S_MBOX_SR_F1_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F1_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F1_READ_SHIFT)) & PSI5_S_MBOX_SR_F1_READ_MASK)

#define PSI5_S_MBOX_SR_F1_OV_MASK                (0x10U)
#define PSI5_S_MBOX_SR_F1_OV_SHIFT               (4U)
#define PSI5_S_MBOX_SR_F1_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F1_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F1_OV_SHIFT)) & PSI5_S_MBOX_SR_F1_OV_MASK)

#define PSI5_S_MBOX_SR_F1_ERR_MASK               (0x20U)
#define PSI5_S_MBOX_SR_F1_ERR_SHIFT              (5U)
#define PSI5_S_MBOX_SR_F1_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F1_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F1_ERR_SHIFT)) & PSI5_S_MBOX_SR_F1_ERR_MASK)

#define PSI5_S_MBOX_SR_F2_READ_MASK              (0x40U)
#define PSI5_S_MBOX_SR_F2_READ_SHIFT             (6U)
#define PSI5_S_MBOX_SR_F2_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F2_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F2_READ_SHIFT)) & PSI5_S_MBOX_SR_F2_READ_MASK)

#define PSI5_S_MBOX_SR_F2_OV_MASK                (0x80U)
#define PSI5_S_MBOX_SR_F2_OV_SHIFT               (7U)
#define PSI5_S_MBOX_SR_F2_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F2_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F2_OV_SHIFT)) & PSI5_S_MBOX_SR_F2_OV_MASK)

#define PSI5_S_MBOX_SR_F2_ERR_MASK               (0x100U)
#define PSI5_S_MBOX_SR_F2_ERR_SHIFT              (8U)
#define PSI5_S_MBOX_SR_F2_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F2_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F2_ERR_SHIFT)) & PSI5_S_MBOX_SR_F2_ERR_MASK)

#define PSI5_S_MBOX_SR_F3_READ_MASK              (0x200U)
#define PSI5_S_MBOX_SR_F3_READ_SHIFT             (9U)
#define PSI5_S_MBOX_SR_F3_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F3_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F3_READ_SHIFT)) & PSI5_S_MBOX_SR_F3_READ_MASK)

#define PSI5_S_MBOX_SR_F3_OV_MASK                (0x400U)
#define PSI5_S_MBOX_SR_F3_OV_SHIFT               (10U)
#define PSI5_S_MBOX_SR_F3_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F3_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F3_OV_SHIFT)) & PSI5_S_MBOX_SR_F3_OV_MASK)

#define PSI5_S_MBOX_SR_F3_ERR_MASK               (0x800U)
#define PSI5_S_MBOX_SR_F3_ERR_SHIFT              (11U)
#define PSI5_S_MBOX_SR_F3_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F3_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F3_ERR_SHIFT)) & PSI5_S_MBOX_SR_F3_ERR_MASK)

#define PSI5_S_MBOX_SR_F4_READ_MASK              (0x1000U)
#define PSI5_S_MBOX_SR_F4_READ_SHIFT             (12U)
#define PSI5_S_MBOX_SR_F4_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F4_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F4_READ_SHIFT)) & PSI5_S_MBOX_SR_F4_READ_MASK)

#define PSI5_S_MBOX_SR_F4_OV_MASK                (0x2000U)
#define PSI5_S_MBOX_SR_F4_OV_SHIFT               (13U)
#define PSI5_S_MBOX_SR_F4_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F4_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F4_OV_SHIFT)) & PSI5_S_MBOX_SR_F4_OV_MASK)

#define PSI5_S_MBOX_SR_F4_ERR_MASK               (0x4000U)
#define PSI5_S_MBOX_SR_F4_ERR_SHIFT              (14U)
#define PSI5_S_MBOX_SR_F4_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F4_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F4_ERR_SHIFT)) & PSI5_S_MBOX_SR_F4_ERR_MASK)

#define PSI5_S_MBOX_SR_F5_READ_MASK              (0x8000U)
#define PSI5_S_MBOX_SR_F5_READ_SHIFT             (15U)
#define PSI5_S_MBOX_SR_F5_READ_WIDTH             (1U)
#define PSI5_S_MBOX_SR_F5_READ(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F5_READ_SHIFT)) & PSI5_S_MBOX_SR_F5_READ_MASK)

#define PSI5_S_MBOX_SR_F5_OV_MASK                (0x10000U)
#define PSI5_S_MBOX_SR_F5_OV_SHIFT               (16U)
#define PSI5_S_MBOX_SR_F5_OV_WIDTH               (1U)
#define PSI5_S_MBOX_SR_F5_OV(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F5_OV_SHIFT)) & PSI5_S_MBOX_SR_F5_OV_MASK)

#define PSI5_S_MBOX_SR_F5_ERR_MASK               (0x20000U)
#define PSI5_S_MBOX_SR_F5_ERR_SHIFT              (17U)
#define PSI5_S_MBOX_SR_F5_ERR_WIDTH              (1U)
#define PSI5_S_MBOX_SR_F5_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_MBOX_SR_F5_ERR_SHIFT)) & PSI5_S_MBOX_SR_F5_ERR_MASK)
/*! @} */

/*! @name WD_CFGR - PSI5_S channel watchdog configuration register */
/*! @{ */

#define PSI5_S_WD_CFGR_WD_TO_MASK                (0xFFFFFFU)
#define PSI5_S_WD_CFGR_WD_TO_SHIFT               (0U)
#define PSI5_S_WD_CFGR_WD_TO_WIDTH               (24U)
#define PSI5_S_WD_CFGR_WD_TO(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_WD_CFGR_WD_TO_SHIFT)) & PSI5_S_WD_CFGR_WD_TO_MASK)

#define PSI5_S_WD_CFGR_WDEN_MASK                 (0x2000000U)
#define PSI5_S_WD_CFGR_WDEN_SHIFT                (25U)
#define PSI5_S_WD_CFGR_WDEN_WIDTH                (1U)
#define PSI5_S_WD_CFGR_WDEN(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_WD_CFGR_WDEN_SHIFT)) & PSI5_S_WD_CFGR_WDEN_MASK)

#define PSI5_S_WD_CFGR_WDCS_MASK                 (0x4000000U)
#define PSI5_S_WD_CFGR_WDCS_SHIFT                (26U)
#define PSI5_S_WD_CFGR_WDCS_WIDTH                (1U)
#define PSI5_S_WD_CFGR_WDCS(x)                   (((uint32_t)(((uint32_t)(x)) << PSI5_S_WD_CFGR_WDCS_SHIFT)) & PSI5_S_WD_CFGR_WDCS_MASK)

#define PSI5_S_WD_CFGR_WDRST_MASK                (0x8000000U)
#define PSI5_S_WD_CFGR_WDRST_SHIFT               (27U)
#define PSI5_S_WD_CFGR_WDRST_WIDTH               (1U)
#define PSI5_S_WD_CFGR_WDRST(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_WD_CFGR_WDRST_SHIFT)) & PSI5_S_WD_CFGR_WDRST_MASK)
/*! @} */

/*! @name DDTRIG_OFFR - PSI5_S DDSR Trigger offset register channel */
/*! @{ */

#define PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR_MASK      (0xFFFFU)
#define PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR_SHIFT     (0U)
#define PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR_WIDTH     (16U)
#define PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR_SHIFT)) & PSI5_S_DDTRIG_OFFR_DDTRIG_OFFR_MASK)
/*! @} */

/*! @name DDTRIG_PERR - PSI5_S DDSR Trigger period register channel */
/*! @{ */

#define PSI5_S_DDTRIG_PERR_DDTRIG_PERR_MASK      (0xFFFFU)
#define PSI5_S_DDTRIG_PERR_DDTRIG_PERR_SHIFT     (0U)
#define PSI5_S_DDTRIG_PERR_DDTRIG_PERR_WIDTH     (16U)
#define PSI5_S_DDTRIG_PERR_DDTRIG_PERR(x)        (((uint32_t)(((uint32_t)(x)) << PSI5_S_DDTRIG_PERR_DDTRIG_PERR_SHIFT)) & PSI5_S_DDTRIG_PERR_DDTRIG_PERR_MASK)
/*! @} */

/*! @name E2SCR - PSI5_S ECU to Sensor Control Register */
/*! @{ */

#define PSI5_S_E2SCR_CMD_TYPE_MASK               (0x7U)
#define PSI5_S_E2SCR_CMD_TYPE_SHIFT              (0U)
#define PSI5_S_E2SCR_CMD_TYPE_WIDTH              (3U)
#define PSI5_S_E2SCR_CMD_TYPE(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CMD_TYPE_SHIFT)) & PSI5_S_E2SCR_CMD_TYPE_MASK)

#define PSI5_S_E2SCR_DDSR_RDY_IE_MASK            (0x20U)
#define PSI5_S_E2SCR_DDSR_RDY_IE_SHIFT           (5U)
#define PSI5_S_E2SCR_DDSR_RDY_IE_WIDTH           (1U)
#define PSI5_S_E2SCR_DDSR_RDY_IE(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_DDSR_RDY_IE_SHIFT)) & PSI5_S_E2SCR_DDSR_RDY_IE_MASK)

#define PSI5_S_E2SCR_CMDPR_BZY_IE_MASK           (0x40U)
#define PSI5_S_E2SCR_CMDPR_BZY_IE_SHIFT          (6U)
#define PSI5_S_E2SCR_CMDPR_BZY_IE_WIDTH          (1U)
#define PSI5_S_E2SCR_CMDPR_BZY_IE(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CMDPR_BZY_IE_SHIFT)) & PSI5_S_E2SCR_CMDPR_BZY_IE_MASK)

#define PSI5_S_E2SCR_CMDTR_NWRT_IE_MASK          (0x80U)
#define PSI5_S_E2SCR_CMDTR_NWRT_IE_SHIFT         (7U)
#define PSI5_S_E2SCR_CMDTR_NWRT_IE_WIDTH         (1U)
#define PSI5_S_E2SCR_CMDTR_NWRT_IE(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CMDTR_NWRT_IE_SHIFT)) & PSI5_S_E2SCR_CMDTR_NWRT_IE_MASK)

#define PSI5_S_E2SCR_SYNCHRO_OVF_IE_MASK         (0x200U)
#define PSI5_S_E2SCR_SYNCHRO_OVF_IE_SHIFT        (9U)
#define PSI5_S_E2SCR_SYNCHRO_OVF_IE_WIDTH        (1U)
#define PSI5_S_E2SCR_SYNCHRO_OVF_IE(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_SYNCHRO_OVF_IE_SHIFT)) & PSI5_S_E2SCR_SYNCHRO_OVF_IE_MASK)

#define PSI5_S_E2SCR_CMDTR_SW_CTRL_MASK          (0x800U)
#define PSI5_S_E2SCR_CMDTR_SW_CTRL_SHIFT         (11U)
#define PSI5_S_E2SCR_CMDTR_SW_CTRL_WIDTH         (1U)
#define PSI5_S_E2SCR_CMDTR_SW_CTRL(x)            (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CMDTR_SW_CTRL_SHIFT)) & PSI5_S_E2SCR_CMDTR_SW_CTRL_MASK)

#define PSI5_S_E2SCR_DDSR_CLK_SEL_MASK           (0x1000U)
#define PSI5_S_E2SCR_DDSR_CLK_SEL_SHIFT          (12U)
#define PSI5_S_E2SCR_DDSR_CLK_SEL_WIDTH          (1U)
#define PSI5_S_E2SCR_DDSR_CLK_SEL(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_DDSR_CLK_SEL_SHIFT)) & PSI5_S_E2SCR_DDSR_CLK_SEL_MASK)

#define PSI5_S_E2SCR_DDSR_CLR_MASK               (0x2000U)
#define PSI5_S_E2SCR_DDSR_CLR_SHIFT              (13U)
#define PSI5_S_E2SCR_DDSR_CLR_WIDTH              (1U)
#define PSI5_S_E2SCR_DDSR_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_DDSR_CLR_SHIFT)) & PSI5_S_E2SCR_DDSR_CLR_MASK)

#define PSI5_S_E2SCR_DDSR_SHIFT_SEL_MASK         (0x4000U)
#define PSI5_S_E2SCR_DDSR_SHIFT_SEL_SHIFT        (14U)
#define PSI5_S_E2SCR_DDSR_SHIFT_SEL_WIDTH        (1U)
#define PSI5_S_E2SCR_DDSR_SHIFT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_DDSR_SHIFT_SEL_SHIFT)) & PSI5_S_E2SCR_DDSR_SHIFT_SEL_MASK)

#define PSI5_S_E2SCR_DEFAULT_SYNC_MASK           (0x8000U)
#define PSI5_S_E2SCR_DEFAULT_SYNC_SHIFT          (15U)
#define PSI5_S_E2SCR_DEFAULT_SYNC_WIDTH          (1U)
#define PSI5_S_E2SCR_DEFAULT_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_DEFAULT_SYNC_SHIFT)) & PSI5_S_E2SCR_DEFAULT_SYNC_MASK)

#define PSI5_S_E2SCR_GL_TRIG_SEL_MASK            (0x10000U)
#define PSI5_S_E2SCR_GL_TRIG_SEL_SHIFT           (16U)
#define PSI5_S_E2SCR_GL_TRIG_SEL_WIDTH           (1U)
#define PSI5_S_E2SCR_GL_TRIG_SEL(x)              (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_GL_TRIG_SEL_SHIFT)) & PSI5_S_E2SCR_GL_TRIG_SEL_MASK)

#define PSI5_S_E2SCR_CH_TRIG_MASK                (0x20000U)
#define PSI5_S_E2SCR_CH_TRIG_SHIFT               (17U)
#define PSI5_S_E2SCR_CH_TRIG_WIDTH               (1U)
#define PSI5_S_E2SCR_CH_TRIG(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CH_TRIG_SHIFT)) & PSI5_S_E2SCR_CH_TRIG_MASK)

#define PSI5_S_E2SCR_ACMD_MASK                   (0x1F00000U)
#define PSI5_S_E2SCR_ACMD_SHIFT                  (20U)
#define PSI5_S_E2SCR_ACMD_WIDTH                  (5U)
#define PSI5_S_E2SCR_ACMD(x)                     (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_ACMD_SHIFT)) & PSI5_S_E2SCR_ACMD_MASK)

#define PSI5_S_E2SCR_CMD_MASK                    (0x7C000000U)
#define PSI5_S_E2SCR_CMD_SHIFT                   (26U)
#define PSI5_S_E2SCR_CMD_WIDTH                   (5U)
#define PSI5_S_E2SCR_CMD(x)                      (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SCR_CMD_SHIFT)) & PSI5_S_E2SCR_CMD_MASK)
/*! @} */

/*! @name E2SSR - PSI5_S ECU to Sensor Status Register */
/*! @{ */

#define PSI5_S_E2SSR_DDSR_RDY_MASK               (0x20U)
#define PSI5_S_E2SSR_DDSR_RDY_SHIFT              (5U)
#define PSI5_S_E2SSR_DDSR_RDY_WIDTH              (1U)
#define PSI5_S_E2SSR_DDSR_RDY(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SSR_DDSR_RDY_SHIFT)) & PSI5_S_E2SSR_DDSR_RDY_MASK)

#define PSI5_S_E2SSR_CMDPR_BZY_MASK              (0x40U)
#define PSI5_S_E2SSR_CMDPR_BZY_SHIFT             (6U)
#define PSI5_S_E2SSR_CMDPR_BZY_WIDTH             (1U)
#define PSI5_S_E2SSR_CMDPR_BZY(x)                (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SSR_CMDPR_BZY_SHIFT)) & PSI5_S_E2SSR_CMDPR_BZY_MASK)

#define PSI5_S_E2SSR_CMDTR_NWRT_MASK             (0x80U)
#define PSI5_S_E2SSR_CMDTR_NWRT_SHIFT            (7U)
#define PSI5_S_E2SSR_CMDTR_NWRT_WIDTH            (1U)
#define PSI5_S_E2SSR_CMDTR_NWRT(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SSR_CMDTR_NWRT_SHIFT)) & PSI5_S_E2SSR_CMDTR_NWRT_MASK)

#define PSI5_S_E2SSR_SYCHRO_OVF_MASK             (0x200U)
#define PSI5_S_E2SSR_SYCHRO_OVF_SHIFT            (9U)
#define PSI5_S_E2SSR_SYCHRO_OVF_WIDTH            (1U)
#define PSI5_S_E2SSR_SYCHRO_OVF(x)               (((uint32_t)(((uint32_t)(x)) << PSI5_S_E2SSR_SYCHRO_OVF_SHIFT)) & PSI5_S_E2SSR_SYCHRO_OVF_MASK)
/*! @} */

/*! @name DDSR_H - PSI5_S channel1 ECU to Sensor Downstream Data Shift Register High */
/*! @{ */

#define PSI5_S_DDSR_H_DDSR_H_MASK                (0x7FFU)
#define PSI5_S_DDSR_H_DDSR_H_SHIFT               (0U)
#define PSI5_S_DDSR_H_DDSR_H_WIDTH               (11U)
#define PSI5_S_DDSR_H_DDSR_H(x)                  (((uint32_t)(((uint32_t)(x)) << PSI5_S_DDSR_H_DDSR_H_SHIFT)) & PSI5_S_DDSR_H_DDSR_H_MASK)
/*! @} */

/*! @name DDSR_L - PSI5_S channel1 ECU to Sensor Downstream Data Shift Register Low */
/*! @{ */

#define PSI5_S_DDSR_L_DDSR_L2_MASK               (0xFFFFFFU)
#define PSI5_S_DDSR_L_DDSR_L2_SHIFT              (0U)
#define PSI5_S_DDSR_L_DDSR_L2_WIDTH              (24U)
#define PSI5_S_DDSR_L_DDSR_L2(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_DDSR_L_DDSR_L2_SHIFT)) & PSI5_S_DDSR_L_DDSR_L2_MASK)

#define PSI5_S_DDSR_L_DDSR_L1_MASK               (0xFF000000U)
#define PSI5_S_DDSR_L_DDSR_L1_SHIFT              (24U)
#define PSI5_S_DDSR_L_DDSR_L1_WIDTH              (8U)
#define PSI5_S_DDSR_L_DDSR_L1(x)                 (((uint32_t)(((uint32_t)(x)) << PSI5_S_DDSR_L_DDSR_L1_SHIFT)) & PSI5_S_DDSR_L_DDSR_L1_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PSI5_S_Register_Masks */

/*!
 * @}
 */ /* end of group PSI5_S_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_PSI5_S_H_) */
