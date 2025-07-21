/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**                          MIMXRT1052CVJ5B
**                          MIMXRT1052CVL5B
**                          MIMXRT1052DVJ6B
**                          MIMXRT1052DVL6B
**                          MIMXRT105SDVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SEMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SEMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SEMC
 *
 * CMSIS Peripheral Access Layer for SEMC
 */

#if !defined(PERI_SEMC_H_)
#define PERI_SEMC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1051CVJ5B) || defined(CPU_MIMXRT1051CVL5B) || defined(CPU_MIMXRT1051DVJ6B) || defined(CPU_MIMXRT1051DVL6B))
#include "MIMXRT1051_COMMON.h"
#elif (defined(CPU_MIMXRT1052CVJ5B) || defined(CPU_MIMXRT1052CVL5B) || defined(CPU_MIMXRT1052DVJ6B) || defined(CPU_MIMXRT1052DVL6B))
#include "MIMXRT1052_COMMON.h"
#elif (defined(CPU_MIMXRT105SDVL6B))
#include "MIMXRT105S_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SEMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMC_Peripheral_Access_Layer SEMC Peripheral Access Layer
 * @{
 */

/** SEMC - Size of Registers Arrays */
#define SEMC_BR_COUNT                             9u

/** SEMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x0 */
  __IO uint32_t IOCR;                              /**< IO Mux Control Register, offset: 0x4 */
  __IO uint32_t BMCR0;                             /**< Bus (AXI) Master Control Register 0, offset: 0x8 */
  __IO uint32_t BMCR1;                             /**< Bus (AXI) Master Control Register 1, offset: 0xC */
  __IO uint32_t BR[SEMC_BR_COUNT];                 /**< Base Register 0 (For SDRAM CS0 device)..Base Register 8 (For NAND device), array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x38 */
  __IO uint32_t INTR;                              /**< Interrupt Enable Register, offset: 0x3C */
  __IO uint32_t SDRAMCR0;                          /**< SDRAM control register 0, offset: 0x40 */
  __IO uint32_t SDRAMCR1;                          /**< SDRAM control register 1, offset: 0x44 */
  __IO uint32_t SDRAMCR2;                          /**< SDRAM control register 2, offset: 0x48 */
  __IO uint32_t SDRAMCR3;                          /**< SDRAM control register 3, offset: 0x4C */
  __IO uint32_t NANDCR0;                           /**< NAND control register 0, offset: 0x50 */
  __IO uint32_t NANDCR1;                           /**< NAND control register 1, offset: 0x54 */
  __IO uint32_t NANDCR2;                           /**< NAND control register 2, offset: 0x58 */
  __IO uint32_t NANDCR3;                           /**< NAND control register 3, offset: 0x5C */
  __IO uint32_t NORCR0;                            /**< NOR control register 0, offset: 0x60 */
  __IO uint32_t NORCR1;                            /**< NOR control register 1, offset: 0x64 */
  __IO uint32_t NORCR2;                            /**< NOR control register 2, offset: 0x68 */
       uint32_t NORCR3;                            /**< NOR control register 3, offset: 0x6C */
  __IO uint32_t SRAMCR0;                           /**< SRAM control register 0, offset: 0x70 */
  __IO uint32_t SRAMCR1;                           /**< SRAM control register 1, offset: 0x74 */
  __IO uint32_t SRAMCR2;                           /**< SRAM control register 2, offset: 0x78 */
       uint32_t SRAMCR3;                           /**< SRAM control register 3, offset: 0x7C */
  __IO uint32_t DBICR0;                            /**< DBI-B control register 0, offset: 0x80 */
  __IO uint32_t DBICR1;                            /**< DBI-B control register 1, offset: 0x84 */
       uint8_t RESERVED_1[8];
  __IO uint32_t IPCR0;                             /**< IP Command control register 0, offset: 0x90 */
  __IO uint32_t IPCR1;                             /**< IP Command control register 1, offset: 0x94 */
  __IO uint32_t IPCR2;                             /**< IP Command control register 2, offset: 0x98 */
  __IO uint32_t IPCMD;                             /**< IP Command register, offset: 0x9C */
  __IO uint32_t IPTXDAT;                           /**< TX DATA register (for IP Command), offset: 0xA0 */
       uint8_t RESERVED_2[12];
  __I  uint32_t IPRXDAT;                           /**< RX DATA register (for IP Command), offset: 0xB0 */
       uint8_t RESERVED_3[12];
  __I  uint32_t STS0;                              /**< Status register 0, offset: 0xC0 */
       uint32_t STS1;                              /**< Status register 1, offset: 0xC4 */
  __I  uint32_t STS2;                              /**< Status register 2, offset: 0xC8 */
       uint32_t STS3;                              /**< Status register 3, offset: 0xCC */
       uint32_t STS4;                              /**< Status register 4, offset: 0xD0 */
       uint32_t STS5;                              /**< Status register 5, offset: 0xD4 */
       uint32_t STS6;                              /**< Status register 6, offset: 0xD8 */
       uint32_t STS7;                              /**< Status register 7, offset: 0xDC */
       uint32_t STS8;                              /**< Status register 8, offset: 0xE0 */
       uint32_t STS9;                              /**< Status register 9, offset: 0xE4 */
       uint32_t STS10;                             /**< Status register 10, offset: 0xE8 */
       uint32_t STS11;                             /**< Status register 11, offset: 0xEC */
  __I  uint32_t STS12;                             /**< Status register 12, offset: 0xF0 */
       uint32_t STS13;                             /**< Status register 13, offset: 0xF4 */
       uint32_t STS14;                             /**< Status register 14, offset: 0xF8 */
       uint32_t STS15;                             /**< Status register 15, offset: 0xFC */
} SEMC_Type;

/* ----------------------------------------------------------------------------
   -- SEMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMC_Register_Masks SEMC Register Masks
 * @{
 */

/*! @name MCR - Module Control Register */
/*! @{ */

#define SEMC_MCR_SWRST_MASK                      (0x1U)
#define SEMC_MCR_SWRST_SHIFT                     (0U)
/*! SWRST - Software Reset */
#define SEMC_MCR_SWRST(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_SWRST_SHIFT)) & SEMC_MCR_SWRST_MASK)

#define SEMC_MCR_MDIS_MASK                       (0x2U)
#define SEMC_MCR_MDIS_SHIFT                      (1U)
/*! MDIS - Module Disable
 *  0b0..Module enabled
 *  0b1..Module disabled
 */
#define SEMC_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_MDIS_SHIFT)) & SEMC_MCR_MDIS_MASK)

#define SEMC_MCR_DQSMD_MASK                      (0x4U)
#define SEMC_MCR_DQSMD_SHIFT                     (2U)
/*! DQSMD - DQS (read strobe) mode
 *  0b0..Dummy read strobe loopbacked internally
 *  0b1..Dummy read strobe loopbacked from DQS pad
 */
#define SEMC_MCR_DQSMD(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_DQSMD_SHIFT)) & SEMC_MCR_DQSMD_MASK)

#define SEMC_MCR_WPOL0_MASK                      (0x40U)
#define SEMC_MCR_WPOL0_SHIFT                     (6U)
/*! WPOL0 - WAIT/RDY# polarity for NOR/PSRAM
 *  0b0..Active low
 *  0b1..Active high
 */
#define SEMC_MCR_WPOL0(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_WPOL0_SHIFT)) & SEMC_MCR_WPOL0_MASK)

#define SEMC_MCR_WPOL1_MASK                      (0x80U)
#define SEMC_MCR_WPOL1_SHIFT                     (7U)
/*! WPOL1 - WAIT/RDY# polarity for NAND
 *  0b0..Active low
 *  0b1..Active high
 */
#define SEMC_MCR_WPOL1(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_WPOL1_SHIFT)) & SEMC_MCR_WPOL1_MASK)

#define SEMC_MCR_CTO_MASK                        (0xFF0000U)
#define SEMC_MCR_CTO_SHIFT                       (16U)
/*! CTO - Command Execution timeout cycles */
#define SEMC_MCR_CTO(x)                          (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_CTO_SHIFT)) & SEMC_MCR_CTO_MASK)

#define SEMC_MCR_BTO_MASK                        (0x1F000000U)
#define SEMC_MCR_BTO_SHIFT                       (24U)
/*! BTO - Bus timeout cycles
 *  0b00000..255*1
 *  0b00001-0b11110..255*2 - 255*2^30
 *  0b11111..255*2^31
 */
#define SEMC_MCR_BTO(x)                          (((uint32_t)(((uint32_t)(x)) << SEMC_MCR_BTO_SHIFT)) & SEMC_MCR_BTO_MASK)
/*! @} */

/*! @name IOCR - IO Mux Control Register */
/*! @{ */

#define SEMC_IOCR_MUX_A8_MASK                    (0x7U)
#define SEMC_IOCR_MUX_A8_SHIFT                   (0U)
/*! MUX_A8 - SEMC_A8 output selection
 *  0b000..SDRAM Address bit (A8)
 *  0b001..NAND CE#
 *  0b010..NOR CE#
 *  0b011..PSRAM CE#
 *  0b100..DBI CSX
 *  0b101..SDRAM Address bit (A8)
 *  0b110..SDRAM Address bit (A8)
 *  0b111..SDRAM Address bit (A8)
 */
#define SEMC_IOCR_MUX_A8(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_A8_SHIFT)) & SEMC_IOCR_MUX_A8_MASK)

#define SEMC_IOCR_MUX_CSX0_MASK                  (0x38U)
#define SEMC_IOCR_MUX_CSX0_SHIFT                 (3U)
/*! MUX_CSX0 - SEMC_CSX0 output selection
 *  0b000..NOR/PSRAM Address bit 24 (A24)
 *  0b001..SDRAM CS1
 *  0b010..SDRAM CS2
 *  0b011..SDRAM CS3
 *  0b100..NAND CE#
 *  0b101..NOR CE#
 *  0b110..PSRAM CE#
 *  0b111..DBI CSX
 */
#define SEMC_IOCR_MUX_CSX0(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_CSX0_SHIFT)) & SEMC_IOCR_MUX_CSX0_MASK)

#define SEMC_IOCR_MUX_CSX1_MASK                  (0x1C0U)
#define SEMC_IOCR_MUX_CSX1_SHIFT                 (6U)
/*! MUX_CSX1 - SEMC_CSX1 output selection
 *  0b000..NOR/PSRAM Address bit 25 (A25)
 *  0b001..SDRAM CS1
 *  0b010..SDRAM CS2
 *  0b011..SDRAM CS3
 *  0b100..NAND CE#
 *  0b101..NOR CE#
 *  0b110..PSRAM CE#
 *  0b111..DBI CSX
 */
#define SEMC_IOCR_MUX_CSX1(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_CSX1_SHIFT)) & SEMC_IOCR_MUX_CSX1_MASK)

#define SEMC_IOCR_MUX_CSX2_MASK                  (0xE00U)
#define SEMC_IOCR_MUX_CSX2_SHIFT                 (9U)
/*! MUX_CSX2 - SEMC_CSX2 output selection
 *  0b000..NOR/PSRAM Address bit 26 (A26)
 *  0b001..SDRAM CS1
 *  0b010..SDRAM CS2
 *  0b011..SDRAM CS3
 *  0b100..NAND CE#
 *  0b101..NOR CE#
 *  0b110..PSRAM CE#
 *  0b111..DBI CSX
 */
#define SEMC_IOCR_MUX_CSX2(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_CSX2_SHIFT)) & SEMC_IOCR_MUX_CSX2_MASK)

#define SEMC_IOCR_MUX_CSX3_MASK                  (0x7000U)
#define SEMC_IOCR_MUX_CSX3_SHIFT                 (12U)
/*! MUX_CSX3 - SEMC_CSX3 output selection
 *  0b000..NOR/PSRAM Address bit 27 (A27)
 *  0b001..SDRAM CS1
 *  0b010..SDRAM CS2
 *  0b011..SDRAM CS3
 *  0b100..NAND CE#
 *  0b101..NOR CE#
 *  0b110..PSRAM CE#
 *  0b111..DBI CSX
 */
#define SEMC_IOCR_MUX_CSX3(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_CSX3_SHIFT)) & SEMC_IOCR_MUX_CSX3_MASK)

#define SEMC_IOCR_MUX_RDY_MASK                   (0x38000U)
#define SEMC_IOCR_MUX_RDY_SHIFT                  (15U)
/*! MUX_RDY - SEMC_RDY function selection
 *  0b000..NAND Ready/Wait# input
 *  0b001..SDRAM CS1
 *  0b010..SDRAM CS2
 *  0b011..SDRAM CS3
 *  0b100..NOR CE#
 *  0b101..PSRAM CE#
 *  0b110..DBI CSX
 *  0b111..NOR/PSRAM Address bit 27
 */
#define SEMC_IOCR_MUX_RDY(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_IOCR_MUX_RDY_SHIFT)) & SEMC_IOCR_MUX_RDY_MASK)
/*! @} */

/*! @name BMCR0 - Bus (AXI) Master Control Register 0 */
/*! @{ */

#define SEMC_BMCR0_WQOS_MASK                     (0xFU)
#define SEMC_BMCR0_WQOS_SHIFT                    (0U)
/*! WQOS - Weight of QOS calculation. AXI bus access has AxQOS signal set, which is used as a
 *    priority indicator for the associated write or read transaction. A higher value indicates a higher
 *    priority transaction. AxQOS is multiplied by WQOS to get weight score.
 */
#define SEMC_BMCR0_WQOS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR0_WQOS_SHIFT)) & SEMC_BMCR0_WQOS_MASK)

#define SEMC_BMCR0_WAGE_MASK                     (0xF0U)
#define SEMC_BMCR0_WAGE_SHIFT                    (4U)
/*! WAGE - Weight of AGE calculation. Each command in queue has an age signal to indicate its wait
 *    period. It is multiplied by WAGE to get weight score.
 */
#define SEMC_BMCR0_WAGE(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR0_WAGE_SHIFT)) & SEMC_BMCR0_WAGE_MASK)

#define SEMC_BMCR0_WSH_MASK                      (0xFF00U)
#define SEMC_BMCR0_WSH_SHIFT                     (8U)
/*! WSH - Weight of Slave Hit without read/write switch. This weight score is valid when queue
 *    command's slave is same as current executing command without read/write operation switch.
 */
#define SEMC_BMCR0_WSH(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR0_WSH_SHIFT)) & SEMC_BMCR0_WSH_MASK)

#define SEMC_BMCR0_WRWS_MASK                     (0xFF0000U)
#define SEMC_BMCR0_WRWS_SHIFT                    (16U)
/*! WRWS - Weight of slave hit with Read/Write Switch. This weight score is valid when queue
 *    command's slave is same as current executing command with read/write operation switch.
 */
#define SEMC_BMCR0_WRWS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR0_WRWS_SHIFT)) & SEMC_BMCR0_WRWS_MASK)
/*! @} */

/*! @name BMCR1 - Bus (AXI) Master Control Register 1 */
/*! @{ */

#define SEMC_BMCR1_WQOS_MASK                     (0xFU)
#define SEMC_BMCR1_WQOS_SHIFT                    (0U)
/*! WQOS - Weight of QOS calculation. AXI bus access has AxQOS signal set, which is used as a
 *    priority indicator for the associated write or read transaction. A higher value indicates a higher
 *    priority transaction. AxQOS is multiplied by WQOS to get weight score.
 */
#define SEMC_BMCR1_WQOS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR1_WQOS_SHIFT)) & SEMC_BMCR1_WQOS_MASK)

#define SEMC_BMCR1_WAGE_MASK                     (0xF0U)
#define SEMC_BMCR1_WAGE_SHIFT                    (4U)
/*! WAGE - Weight of AGE calculation. Each command in queue has an age signal to indicate its wait
 *    period. It is multiplied by WAGE to get weight score.
 */
#define SEMC_BMCR1_WAGE(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR1_WAGE_SHIFT)) & SEMC_BMCR1_WAGE_MASK)

#define SEMC_BMCR1_WPH_MASK                      (0xFF00U)
#define SEMC_BMCR1_WPH_SHIFT                     (8U)
/*! WPH - Weight of Page Hit. This weight score is valid when queue command's page hits current executing command. */
#define SEMC_BMCR1_WPH(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR1_WPH_SHIFT)) & SEMC_BMCR1_WPH_MASK)

#define SEMC_BMCR1_WRWS_MASK                     (0xFF0000U)
#define SEMC_BMCR1_WRWS_SHIFT                    (16U)
/*! WRWS - Weight of slave hit without Read/Write Switch. This weight score is valid when queue
 *    command's read/write operation is same as current executing command.
 */
#define SEMC_BMCR1_WRWS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR1_WRWS_SHIFT)) & SEMC_BMCR1_WRWS_MASK)

#define SEMC_BMCR1_WBR_MASK                      (0xFF000000U)
#define SEMC_BMCR1_WBR_SHIFT                     (24U)
/*! WBR - Weight of Bank Rotation. This weight score is valid when queue command's bank is not same as current executing command. */
#define SEMC_BMCR1_WBR(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_BMCR1_WBR_SHIFT)) & SEMC_BMCR1_WBR_MASK)
/*! @} */

/*! @name BR - Base Register 0 (For SDRAM CS0 device)..Base Register 8 (For NAND device) */
/*! @{ */

#define SEMC_BR_VLD_MASK                         (0x1U)
#define SEMC_BR_VLD_SHIFT                        (0U)
/*! VLD - Valid */
#define SEMC_BR_VLD(x)                           (((uint32_t)(((uint32_t)(x)) << SEMC_BR_VLD_SHIFT)) & SEMC_BR_VLD_MASK)

#define SEMC_BR_MS_MASK                          (0x3EU)
#define SEMC_BR_MS_SHIFT                         (1U)
/*! MS - Memory size
 *  0b00000..4KB
 *  0b00001..8KB
 *  0b00010..16KB
 *  0b00011..32KB
 *  0b00100..64KB
 *  0b00101..128KB
 *  0b00110..256KB
 *  0b00111..512KB
 *  0b01000..1MB
 *  0b01001..2MB
 *  0b01010..4MB
 *  0b01011..8MB
 *  0b01100..16MB
 *  0b01101..32MB
 *  0b01110..64MB
 *  0b01111..128MB
 *  0b10000..256MB
 *  0b10001..512MB
 *  0b10010..1GB
 *  0b10011..2GB
 *  0b10100-0b11111..4GB
 */
#define SEMC_BR_MS(x)                            (((uint32_t)(((uint32_t)(x)) << SEMC_BR_MS_SHIFT)) & SEMC_BR_MS_MASK)

#define SEMC_BR_BA_MASK                          (0xFFFFF000U)
#define SEMC_BR_BA_SHIFT                         (12U)
/*! BA - Base Address */
#define SEMC_BR_BA(x)                            (((uint32_t)(((uint32_t)(x)) << SEMC_BR_BA_SHIFT)) & SEMC_BR_BA_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable Register */
/*! @{ */

#define SEMC_INTEN_IPCMDDONEEN_MASK              (0x1U)
#define SEMC_INTEN_IPCMDDONEEN_SHIFT             (0U)
/*! IPCMDDONEEN - IP command done interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_IPCMDDONEEN(x)                (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_IPCMDDONEEN_SHIFT)) & SEMC_INTEN_IPCMDDONEEN_MASK)

#define SEMC_INTEN_IPCMDERREN_MASK               (0x2U)
#define SEMC_INTEN_IPCMDERREN_SHIFT              (1U)
/*! IPCMDERREN - IP command error interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_IPCMDERREN(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_IPCMDERREN_SHIFT)) & SEMC_INTEN_IPCMDERREN_MASK)

#define SEMC_INTEN_AXICMDERREN_MASK              (0x4U)
#define SEMC_INTEN_AXICMDERREN_SHIFT             (2U)
/*! AXICMDERREN - AXI command error interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_AXICMDERREN(x)                (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_AXICMDERREN_SHIFT)) & SEMC_INTEN_AXICMDERREN_MASK)

#define SEMC_INTEN_AXIBUSERREN_MASK              (0x8U)
#define SEMC_INTEN_AXIBUSERREN_SHIFT             (3U)
/*! AXIBUSERREN - AXI bus error interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_AXIBUSERREN(x)                (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_AXIBUSERREN_SHIFT)) & SEMC_INTEN_AXIBUSERREN_MASK)

#define SEMC_INTEN_NDPAGEENDEN_MASK              (0x10U)
#define SEMC_INTEN_NDPAGEENDEN_SHIFT             (4U)
/*! NDPAGEENDEN - NAND page end interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_NDPAGEENDEN(x)                (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_NDPAGEENDEN_SHIFT)) & SEMC_INTEN_NDPAGEENDEN_MASK)

#define SEMC_INTEN_NDNOPENDEN_MASK               (0x20U)
#define SEMC_INTEN_NDNOPENDEN_SHIFT              (5U)
/*! NDNOPENDEN - NAND no pending AXI access interrupt enable
 *  0b0..Interrupt is disabled
 *  0b1..Interrupt is enabled
 */
#define SEMC_INTEN_NDNOPENDEN(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_INTEN_NDNOPENDEN_SHIFT)) & SEMC_INTEN_NDNOPENDEN_MASK)
/*! @} */

/*! @name INTR - Interrupt Enable Register */
/*! @{ */

#define SEMC_INTR_IPCMDDONE_MASK                 (0x1U)
#define SEMC_INTR_IPCMDDONE_SHIFT                (0U)
/*! IPCMDDONE - IP command normal done interrupt */
#define SEMC_INTR_IPCMDDONE(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_IPCMDDONE_SHIFT)) & SEMC_INTR_IPCMDDONE_MASK)

#define SEMC_INTR_IPCMDERR_MASK                  (0x2U)
#define SEMC_INTR_IPCMDERR_SHIFT                 (1U)
/*! IPCMDERR - IP command error done interrupt */
#define SEMC_INTR_IPCMDERR(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_IPCMDERR_SHIFT)) & SEMC_INTR_IPCMDERR_MASK)

#define SEMC_INTR_AXICMDERR_MASK                 (0x4U)
#define SEMC_INTR_AXICMDERR_SHIFT                (2U)
/*! AXICMDERR - AXI command error interrupt */
#define SEMC_INTR_AXICMDERR(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_AXICMDERR_SHIFT)) & SEMC_INTR_AXICMDERR_MASK)

#define SEMC_INTR_AXIBUSERR_MASK                 (0x8U)
#define SEMC_INTR_AXIBUSERR_SHIFT                (3U)
/*! AXIBUSERR - AXI bus error interrupt */
#define SEMC_INTR_AXIBUSERR(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_AXIBUSERR_SHIFT)) & SEMC_INTR_AXIBUSERR_MASK)

#define SEMC_INTR_NDPAGEEND_MASK                 (0x10U)
#define SEMC_INTR_NDPAGEEND_SHIFT                (4U)
/*! NDPAGEEND - NAND page end interrupt */
#define SEMC_INTR_NDPAGEEND(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_NDPAGEEND_SHIFT)) & SEMC_INTR_NDPAGEEND_MASK)

#define SEMC_INTR_NDNOPEND_MASK                  (0x20U)
#define SEMC_INTR_NDNOPEND_SHIFT                 (5U)
/*! NDNOPEND - NAND no pending AXI access interrupt */
#define SEMC_INTR_NDNOPEND(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_INTR_NDNOPEND_SHIFT)) & SEMC_INTR_NDNOPEND_MASK)
/*! @} */

/*! @name SDRAMCR0 - SDRAM control register 0 */
/*! @{ */

#define SEMC_SDRAMCR0_PS_MASK                    (0x1U)
#define SEMC_SDRAMCR0_PS_SHIFT                   (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define SEMC_SDRAMCR0_PS(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR0_PS_SHIFT)) & SEMC_SDRAMCR0_PS_MASK)

#define SEMC_SDRAMCR0_BL_MASK                    (0x70U)
#define SEMC_SDRAMCR0_BL_SHIFT                   (4U)
/*! BL - Burst Length
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..8
 *  0b101..8
 *  0b110..8
 *  0b111..8
 */
#define SEMC_SDRAMCR0_BL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR0_BL_SHIFT)) & SEMC_SDRAMCR0_BL_MASK)

#define SEMC_SDRAMCR0_COL_MASK                   (0x300U)
#define SEMC_SDRAMCR0_COL_SHIFT                  (8U)
/*! COL - Column address bit number
 *  0b00..12 bit
 *  0b01..11 bit
 *  0b10..10 bit
 *  0b11..9 bit
 */
#define SEMC_SDRAMCR0_COL(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR0_COL_SHIFT)) & SEMC_SDRAMCR0_COL_MASK)

#define SEMC_SDRAMCR0_CL_MASK                    (0xC00U)
#define SEMC_SDRAMCR0_CL_SHIFT                   (10U)
/*! CL - CAS Latency
 *  0b00..1
 *  0b01..1
 *  0b10..2
 *  0b11..3
 */
#define SEMC_SDRAMCR0_CL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR0_CL_SHIFT)) & SEMC_SDRAMCR0_CL_MASK)
/*! @} */

/*! @name SDRAMCR1 - SDRAM control register 1 */
/*! @{ */

#define SEMC_SDRAMCR1_PRE2ACT_MASK               (0xFU)
#define SEMC_SDRAMCR1_PRE2ACT_SHIFT              (0U)
/*! PRE2ACT - PRECHARGE to ACT/Refresh wait time */
#define SEMC_SDRAMCR1_PRE2ACT(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_PRE2ACT_SHIFT)) & SEMC_SDRAMCR1_PRE2ACT_MASK)

#define SEMC_SDRAMCR1_ACT2RW_MASK                (0xF0U)
#define SEMC_SDRAMCR1_ACT2RW_SHIFT               (4U)
/*! ACT2RW - ACT to Read/Write wait time */
#define SEMC_SDRAMCR1_ACT2RW(x)                  (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_ACT2RW_SHIFT)) & SEMC_SDRAMCR1_ACT2RW_MASK)

#define SEMC_SDRAMCR1_RFRC_MASK                  (0x1F00U)
#define SEMC_SDRAMCR1_RFRC_SHIFT                 (8U)
/*! RFRC - Refresh recovery time */
#define SEMC_SDRAMCR1_RFRC(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_RFRC_SHIFT)) & SEMC_SDRAMCR1_RFRC_MASK)

#define SEMC_SDRAMCR1_WRC_MASK                   (0xE000U)
#define SEMC_SDRAMCR1_WRC_SHIFT                  (13U)
/*! WRC - Write recovery time */
#define SEMC_SDRAMCR1_WRC(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_WRC_SHIFT)) & SEMC_SDRAMCR1_WRC_MASK)

#define SEMC_SDRAMCR1_CKEOFF_MASK                (0xF0000U)
#define SEMC_SDRAMCR1_CKEOFF_SHIFT               (16U)
/*! CKEOFF - CKE OFF minimum time */
#define SEMC_SDRAMCR1_CKEOFF(x)                  (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_CKEOFF_SHIFT)) & SEMC_SDRAMCR1_CKEOFF_MASK)

#define SEMC_SDRAMCR1_ACT2PRE_MASK               (0xF00000U)
#define SEMC_SDRAMCR1_ACT2PRE_SHIFT              (20U)
/*! ACT2PRE - ACT to Precharge minimum time */
#define SEMC_SDRAMCR1_ACT2PRE(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR1_ACT2PRE_SHIFT)) & SEMC_SDRAMCR1_ACT2PRE_MASK)
/*! @} */

/*! @name SDRAMCR2 - SDRAM control register 2 */
/*! @{ */

#define SEMC_SDRAMCR2_SRRC_MASK                  (0xFFU)
#define SEMC_SDRAMCR2_SRRC_SHIFT                 (0U)
/*! SRRC - Self Refresh Recovery time */
#define SEMC_SDRAMCR2_SRRC(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR2_SRRC_SHIFT)) & SEMC_SDRAMCR2_SRRC_MASK)

#define SEMC_SDRAMCR2_REF2REF_MASK               (0xFF00U)
#define SEMC_SDRAMCR2_REF2REF_SHIFT              (8U)
/*! REF2REF - Refresh to Refresh wait time */
#define SEMC_SDRAMCR2_REF2REF(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR2_REF2REF_SHIFT)) & SEMC_SDRAMCR2_REF2REF_MASK)

#define SEMC_SDRAMCR2_ACT2ACT_MASK               (0xFF0000U)
#define SEMC_SDRAMCR2_ACT2ACT_SHIFT              (16U)
/*! ACT2ACT - ACT to ACT wait time */
#define SEMC_SDRAMCR2_ACT2ACT(x)                 (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR2_ACT2ACT_SHIFT)) & SEMC_SDRAMCR2_ACT2ACT_MASK)

#define SEMC_SDRAMCR2_ITO_MASK                   (0xFF000000U)
#define SEMC_SDRAMCR2_ITO_SHIFT                  (24U)
/*! ITO - SDRAM Idle timeout
 *  0b00000000..IDLE timeout period is 256*Prescale period.
 *  0b00000001-0b11111111..IDLE timeout period is ITO*Prescale period.
 */
#define SEMC_SDRAMCR2_ITO(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR2_ITO_SHIFT)) & SEMC_SDRAMCR2_ITO_MASK)
/*! @} */

/*! @name SDRAMCR3 - SDRAM control register 3 */
/*! @{ */

#define SEMC_SDRAMCR3_REN_MASK                   (0x1U)
#define SEMC_SDRAMCR3_REN_SHIFT                  (0U)
/*! REN - Refresh enable */
#define SEMC_SDRAMCR3_REN(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR3_REN_SHIFT)) & SEMC_SDRAMCR3_REN_MASK)

#define SEMC_SDRAMCR3_REBL_MASK                  (0xEU)
#define SEMC_SDRAMCR3_REBL_SHIFT                 (1U)
/*! REBL - Refresh burst length
 *  0b000..1
 *  0b001..2
 *  0b010..3
 *  0b011..4
 *  0b100..5
 *  0b101..6
 *  0b110..7
 *  0b111..8
 */
#define SEMC_SDRAMCR3_REBL(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR3_REBL_SHIFT)) & SEMC_SDRAMCR3_REBL_MASK)

#define SEMC_SDRAMCR3_PRESCALE_MASK              (0xFF00U)
#define SEMC_SDRAMCR3_PRESCALE_SHIFT             (8U)
/*! PRESCALE - Prescaler timer period
 *  0b00000000..256*16 clock cycles
 *  0b00000001-0b11111111..PRESCALE*16 clock cycles
 */
#define SEMC_SDRAMCR3_PRESCALE(x)                (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR3_PRESCALE_SHIFT)) & SEMC_SDRAMCR3_PRESCALE_MASK)

#define SEMC_SDRAMCR3_RT_MASK                    (0xFF0000U)
#define SEMC_SDRAMCR3_RT_SHIFT                   (16U)
/*! RT - Refresh timer period
 *  0b00000000..256*Prescaler period
 *  0b00000001-0b11111111..RT*Prescaler period
 */
#define SEMC_SDRAMCR3_RT(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR3_RT_SHIFT)) & SEMC_SDRAMCR3_RT_MASK)

#define SEMC_SDRAMCR3_UT_MASK                    (0xFF000000U)
#define SEMC_SDRAMCR3_UT_SHIFT                   (24U)
/*! UT - Refresh urgent threshold
 *  0b00000000..256*Prescaler period
 *  0b00000001-0b11111111..UT*Prescaler period
 */
#define SEMC_SDRAMCR3_UT(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SDRAMCR3_UT_SHIFT)) & SEMC_SDRAMCR3_UT_MASK)
/*! @} */

/*! @name NANDCR0 - NAND control register 0 */
/*! @{ */

#define SEMC_NANDCR0_PS_MASK                     (0x1U)
#define SEMC_NANDCR0_PS_SHIFT                    (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define SEMC_NANDCR0_PS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR0_PS_SHIFT)) & SEMC_NANDCR0_PS_MASK)

#define SEMC_NANDCR0_BL_MASK                     (0x70U)
#define SEMC_NANDCR0_BL_SHIFT                    (4U)
/*! BL - Burst Length
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..64
 */
#define SEMC_NANDCR0_BL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR0_BL_SHIFT)) & SEMC_NANDCR0_BL_MASK)

#define SEMC_NANDCR0_EDO_MASK                    (0x80U)
#define SEMC_NANDCR0_EDO_SHIFT                   (7U)
/*! EDO - EDO mode enabled
 *  0b0..EDO mode disabled
 *  0b1..EDO mode enabled
 */
#define SEMC_NANDCR0_EDO(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR0_EDO_SHIFT)) & SEMC_NANDCR0_EDO_MASK)

#define SEMC_NANDCR0_COL_MASK                    (0x700U)
#define SEMC_NANDCR0_COL_SHIFT                   (8U)
/*! COL - Column address bit number
 *  0b000..16
 *  0b001..15
 *  0b010..14
 *  0b011..13
 *  0b100..12
 *  0b101..11
 *  0b110..10
 *  0b111..9
 */
#define SEMC_NANDCR0_COL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR0_COL_SHIFT)) & SEMC_NANDCR0_COL_MASK)
/*! @} */

/*! @name NANDCR1 - NAND control register 1 */
/*! @{ */

#define SEMC_NANDCR1_CES_MASK                    (0xFU)
#define SEMC_NANDCR1_CES_SHIFT                   (0U)
/*! CES - CE setup time */
#define SEMC_NANDCR1_CES(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_CES_SHIFT)) & SEMC_NANDCR1_CES_MASK)

#define SEMC_NANDCR1_CEH_MASK                    (0xF0U)
#define SEMC_NANDCR1_CEH_SHIFT                   (4U)
/*! CEH - CE hold time */
#define SEMC_NANDCR1_CEH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_CEH_SHIFT)) & SEMC_NANDCR1_CEH_MASK)

#define SEMC_NANDCR1_WEL_MASK                    (0xF00U)
#define SEMC_NANDCR1_WEL_SHIFT                   (8U)
/*! WEL - WE# low time */
#define SEMC_NANDCR1_WEL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_WEL_SHIFT)) & SEMC_NANDCR1_WEL_MASK)

#define SEMC_NANDCR1_WEH_MASK                    (0xF000U)
#define SEMC_NANDCR1_WEH_SHIFT                   (12U)
/*! WEH - WE# high time */
#define SEMC_NANDCR1_WEH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_WEH_SHIFT)) & SEMC_NANDCR1_WEH_MASK)

#define SEMC_NANDCR1_REL_MASK                    (0xF0000U)
#define SEMC_NANDCR1_REL_SHIFT                   (16U)
/*! REL - RE# low time */
#define SEMC_NANDCR1_REL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_REL_SHIFT)) & SEMC_NANDCR1_REL_MASK)

#define SEMC_NANDCR1_REH_MASK                    (0xF00000U)
#define SEMC_NANDCR1_REH_SHIFT                   (20U)
/*! REH - RE# high time */
#define SEMC_NANDCR1_REH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_REH_SHIFT)) & SEMC_NANDCR1_REH_MASK)

#define SEMC_NANDCR1_TA_MASK                     (0xF000000U)
#define SEMC_NANDCR1_TA_SHIFT                    (24U)
/*! TA - Turnaround time */
#define SEMC_NANDCR1_TA(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_TA_SHIFT)) & SEMC_NANDCR1_TA_MASK)

#define SEMC_NANDCR1_CEITV_MASK                  (0xF0000000U)
#define SEMC_NANDCR1_CEITV_SHIFT                 (28U)
/*! CEITV - CE# interval time */
#define SEMC_NANDCR1_CEITV(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR1_CEITV_SHIFT)) & SEMC_NANDCR1_CEITV_MASK)
/*! @} */

/*! @name NANDCR2 - NAND control register 2 */
/*! @{ */

#define SEMC_NANDCR2_TWHR_MASK                   (0x3FU)
#define SEMC_NANDCR2_TWHR_SHIFT                  (0U)
/*! TWHR - WE# high to RE# low wait time */
#define SEMC_NANDCR2_TWHR(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR2_TWHR_SHIFT)) & SEMC_NANDCR2_TWHR_MASK)

#define SEMC_NANDCR2_TRHW_MASK                   (0xFC0U)
#define SEMC_NANDCR2_TRHW_SHIFT                  (6U)
/*! TRHW - RE# high to WE# low wait time */
#define SEMC_NANDCR2_TRHW(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR2_TRHW_SHIFT)) & SEMC_NANDCR2_TRHW_MASK)

#define SEMC_NANDCR2_TADL_MASK                   (0x3F000U)
#define SEMC_NANDCR2_TADL_SHIFT                  (12U)
/*! TADL - ALE to write data start wait time */
#define SEMC_NANDCR2_TADL(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR2_TADL_SHIFT)) & SEMC_NANDCR2_TADL_MASK)

#define SEMC_NANDCR2_TRR_MASK                    (0xFC0000U)
#define SEMC_NANDCR2_TRR_SHIFT                   (18U)
/*! TRR - Ready to RE# low wait time */
#define SEMC_NANDCR2_TRR(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR2_TRR_SHIFT)) & SEMC_NANDCR2_TRR_MASK)

#define SEMC_NANDCR2_TWB_MASK                    (0x3F000000U)
#define SEMC_NANDCR2_TWB_SHIFT                   (24U)
/*! TWB - WE# high to busy wait time */
#define SEMC_NANDCR2_TWB(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR2_TWB_SHIFT)) & SEMC_NANDCR2_TWB_MASK)
/*! @} */

/*! @name NANDCR3 - NAND control register 3 */
/*! @{ */

#define SEMC_NANDCR3_NDOPT1_MASK                 (0x1U)
#define SEMC_NANDCR3_NDOPT1_SHIFT                (0U)
/*! NDOPT1 - NAND option bit 1 */
#define SEMC_NANDCR3_NDOPT1(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR3_NDOPT1_SHIFT)) & SEMC_NANDCR3_NDOPT1_MASK)

#define SEMC_NANDCR3_NDOPT2_MASK                 (0x2U)
#define SEMC_NANDCR3_NDOPT2_SHIFT                (1U)
/*! NDOPT2 - NAND option bit 2 */
#define SEMC_NANDCR3_NDOPT2(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR3_NDOPT2_SHIFT)) & SEMC_NANDCR3_NDOPT2_MASK)

#define SEMC_NANDCR3_NDOPT3_MASK                 (0x4U)
#define SEMC_NANDCR3_NDOPT3_SHIFT                (2U)
/*! NDOPT3 - NAND option bit 3 */
#define SEMC_NANDCR3_NDOPT3(x)                   (((uint32_t)(((uint32_t)(x)) << SEMC_NANDCR3_NDOPT3_SHIFT)) & SEMC_NANDCR3_NDOPT3_MASK)
/*! @} */

/*! @name NORCR0 - NOR control register 0 */
/*! @{ */

#define SEMC_NORCR0_PS_MASK                      (0x1U)
#define SEMC_NORCR0_PS_SHIFT                     (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define SEMC_NORCR0_PS(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR0_PS_SHIFT)) & SEMC_NORCR0_PS_MASK)

#define SEMC_NORCR0_BL_MASK                      (0x70U)
#define SEMC_NORCR0_BL_SHIFT                     (4U)
/*! BL - Burst Length
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..64
 */
#define SEMC_NORCR0_BL(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR0_BL_SHIFT)) & SEMC_NORCR0_BL_MASK)

#define SEMC_NORCR0_AM_MASK                      (0x300U)
#define SEMC_NORCR0_AM_SHIFT                     (8U)
/*! AM - Address Mode
 *  0b00..Address/Data MUX mode (ADMUX)
 *  0b01..Advanced Address/Data MUX mode (AADM)
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SEMC_NORCR0_AM(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR0_AM_SHIFT)) & SEMC_NORCR0_AM_MASK)

#define SEMC_NORCR0_ADVP_MASK                    (0x400U)
#define SEMC_NORCR0_ADVP_SHIFT                   (10U)
/*! ADVP - ADV# polarity
 *  0b0..ADV# is active low.
 *  0b1..ADV# is active high.
 */
#define SEMC_NORCR0_ADVP(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR0_ADVP_SHIFT)) & SEMC_NORCR0_ADVP_MASK)

#define SEMC_NORCR0_COL_MASK                     (0xF000U)
#define SEMC_NORCR0_COL_SHIFT                    (12U)
/*! COL - Column Address bit width
 *  0b0000..12 Bits
 *  0b0001..11 Bits
 *  0b0010..10 Bits
 *  0b0011..9 Bits
 *  0b0100..8 Bits
 *  0b0101..7 Bits
 *  0b0110..6 Bits
 *  0b0111..5 Bits
 *  0b1000..4 Bits
 *  0b1001..3 Bits
 *  0b1010..2 Bits
 *  0b1011..12 Bits
 *  0b1100..12 Bits
 *  0b1101..12 Bits
 *  0b1110..12 Bits
 *  0b1111..12 Bits
 */
#define SEMC_NORCR0_COL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR0_COL_SHIFT)) & SEMC_NORCR0_COL_MASK)
/*! @} */

/*! @name NORCR1 - NOR control register 1 */
/*! @{ */

#define SEMC_NORCR1_CES_MASK                     (0xFU)
#define SEMC_NORCR1_CES_SHIFT                    (0U)
/*! CES - CE setup time */
#define SEMC_NORCR1_CES(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_CES_SHIFT)) & SEMC_NORCR1_CES_MASK)

#define SEMC_NORCR1_CEH_MASK                     (0xF0U)
#define SEMC_NORCR1_CEH_SHIFT                    (4U)
/*! CEH - CE hold time */
#define SEMC_NORCR1_CEH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_CEH_SHIFT)) & SEMC_NORCR1_CEH_MASK)

#define SEMC_NORCR1_AS_MASK                      (0xF00U)
#define SEMC_NORCR1_AS_SHIFT                     (8U)
/*! AS - Address setup time */
#define SEMC_NORCR1_AS(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_AS_SHIFT)) & SEMC_NORCR1_AS_MASK)

#define SEMC_NORCR1_AH_MASK                      (0xF000U)
#define SEMC_NORCR1_AH_SHIFT                     (12U)
/*! AH - Address hold time */
#define SEMC_NORCR1_AH(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_AH_SHIFT)) & SEMC_NORCR1_AH_MASK)

#define SEMC_NORCR1_WEL_MASK                     (0xF0000U)
#define SEMC_NORCR1_WEL_SHIFT                    (16U)
/*! WEL - WE low time */
#define SEMC_NORCR1_WEL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_WEL_SHIFT)) & SEMC_NORCR1_WEL_MASK)

#define SEMC_NORCR1_WEH_MASK                     (0xF00000U)
#define SEMC_NORCR1_WEH_SHIFT                    (20U)
/*! WEH - WE high time */
#define SEMC_NORCR1_WEH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_WEH_SHIFT)) & SEMC_NORCR1_WEH_MASK)

#define SEMC_NORCR1_REL_MASK                     (0xF000000U)
#define SEMC_NORCR1_REL_SHIFT                    (24U)
/*! REL - RE low time */
#define SEMC_NORCR1_REL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_REL_SHIFT)) & SEMC_NORCR1_REL_MASK)

#define SEMC_NORCR1_REH_MASK                     (0xF0000000U)
#define SEMC_NORCR1_REH_SHIFT                    (28U)
/*! REH - RE high time */
#define SEMC_NORCR1_REH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR1_REH_SHIFT)) & SEMC_NORCR1_REH_MASK)
/*! @} */

/*! @name NORCR2 - NOR control register 2 */
/*! @{ */

#define SEMC_NORCR2_TA_MASK                      (0xF00U)
#define SEMC_NORCR2_TA_SHIFT                     (8U)
/*! TA - Turnaround time */
#define SEMC_NORCR2_TA(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR2_TA_SHIFT)) & SEMC_NORCR2_TA_MASK)

#define SEMC_NORCR2_AWDH_MASK                    (0xF000U)
#define SEMC_NORCR2_AWDH_SHIFT                   (12U)
/*! AWDH - Address to write data hold time */
#define SEMC_NORCR2_AWDH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR2_AWDH_SHIFT)) & SEMC_NORCR2_AWDH_MASK)

#define SEMC_NORCR2_CEITV_MASK                   (0xF000000U)
#define SEMC_NORCR2_CEITV_SHIFT                  (24U)
/*! CEITV - CE# interval time */
#define SEMC_NORCR2_CEITV(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_NORCR2_CEITV_SHIFT)) & SEMC_NORCR2_CEITV_MASK)
/*! @} */

/*! @name SRAMCR0 - SRAM control register 0 */
/*! @{ */

#define SEMC_SRAMCR0_PS_MASK                     (0x1U)
#define SEMC_SRAMCR0_PS_SHIFT                    (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define SEMC_SRAMCR0_PS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR0_PS_SHIFT)) & SEMC_SRAMCR0_PS_MASK)

#define SEMC_SRAMCR0_BL_MASK                     (0x70U)
#define SEMC_SRAMCR0_BL_SHIFT                    (4U)
/*! BL - Burst Length
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..64
 */
#define SEMC_SRAMCR0_BL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR0_BL_SHIFT)) & SEMC_SRAMCR0_BL_MASK)

#define SEMC_SRAMCR0_AM_MASK                     (0x300U)
#define SEMC_SRAMCR0_AM_SHIFT                    (8U)
/*! AM - Address Mode
 *  0b00..Address/Data MUX mode (ADMUX)
 *  0b01..Advanced Address/Data MUX mode (AADM)
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SEMC_SRAMCR0_AM(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR0_AM_SHIFT)) & SEMC_SRAMCR0_AM_MASK)

#define SEMC_SRAMCR0_ADVP_MASK                   (0x400U)
#define SEMC_SRAMCR0_ADVP_SHIFT                  (10U)
/*! ADVP - ADV# polarity
 *  0b0..ADV# is active low.
 *  0b1..ADV# is active high.
 */
#define SEMC_SRAMCR0_ADVP(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR0_ADVP_SHIFT)) & SEMC_SRAMCR0_ADVP_MASK)

#define SEMC_SRAMCR0_COL_MASK                    (0xF000U)
#define SEMC_SRAMCR0_COL_SHIFT                   (12U)
/*! COL - Column Address bit width
 *  0b0000..12 Bits
 *  0b0001..11 Bits
 *  0b0010..10 Bits
 *  0b0011..9 Bits
 *  0b0100..8 Bits
 *  0b0101..7 Bits
 *  0b0110..6 Bits
 *  0b0111..5 Bits
 *  0b1000..4 Bits
 *  0b1001..3 Bits
 *  0b1010..2 Bits
 *  0b1011..12 Bits
 *  0b1100..12 Bits
 *  0b1101..12 Bits
 *  0b1110..12 Bits
 *  0b1111..12 Bits
 */
#define SEMC_SRAMCR0_COL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR0_COL_SHIFT)) & SEMC_SRAMCR0_COL_MASK)
/*! @} */

/*! @name SRAMCR1 - SRAM control register 1 */
/*! @{ */

#define SEMC_SRAMCR1_CES_MASK                    (0xFU)
#define SEMC_SRAMCR1_CES_SHIFT                   (0U)
/*! CES - CE setup time */
#define SEMC_SRAMCR1_CES(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_CES_SHIFT)) & SEMC_SRAMCR1_CES_MASK)

#define SEMC_SRAMCR1_CEH_MASK                    (0xF0U)
#define SEMC_SRAMCR1_CEH_SHIFT                   (4U)
/*! CEH - CE hold time */
#define SEMC_SRAMCR1_CEH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_CEH_SHIFT)) & SEMC_SRAMCR1_CEH_MASK)

#define SEMC_SRAMCR1_AS_MASK                     (0xF00U)
#define SEMC_SRAMCR1_AS_SHIFT                    (8U)
/*! AS - Address setup time */
#define SEMC_SRAMCR1_AS(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_AS_SHIFT)) & SEMC_SRAMCR1_AS_MASK)

#define SEMC_SRAMCR1_AH_MASK                     (0xF000U)
#define SEMC_SRAMCR1_AH_SHIFT                    (12U)
/*! AH - Address hold time */
#define SEMC_SRAMCR1_AH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_AH_SHIFT)) & SEMC_SRAMCR1_AH_MASK)

#define SEMC_SRAMCR1_WEL_MASK                    (0xF0000U)
#define SEMC_SRAMCR1_WEL_SHIFT                   (16U)
/*! WEL - WE low time */
#define SEMC_SRAMCR1_WEL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_WEL_SHIFT)) & SEMC_SRAMCR1_WEL_MASK)

#define SEMC_SRAMCR1_WEH_MASK                    (0xF00000U)
#define SEMC_SRAMCR1_WEH_SHIFT                   (20U)
/*! WEH - WE high time */
#define SEMC_SRAMCR1_WEH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_WEH_SHIFT)) & SEMC_SRAMCR1_WEH_MASK)

#define SEMC_SRAMCR1_REL_MASK                    (0xF000000U)
#define SEMC_SRAMCR1_REL_SHIFT                   (24U)
/*! REL - RE low time */
#define SEMC_SRAMCR1_REL(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_REL_SHIFT)) & SEMC_SRAMCR1_REL_MASK)

#define SEMC_SRAMCR1_REH_MASK                    (0xF0000000U)
#define SEMC_SRAMCR1_REH_SHIFT                   (28U)
/*! REH - RE high time */
#define SEMC_SRAMCR1_REH(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR1_REH_SHIFT)) & SEMC_SRAMCR1_REH_MASK)
/*! @} */

/*! @name SRAMCR2 - SRAM control register 2 */
/*! @{ */

#define SEMC_SRAMCR2_TA_MASK                     (0xF00U)
#define SEMC_SRAMCR2_TA_SHIFT                    (8U)
/*! TA - Turnaround time */
#define SEMC_SRAMCR2_TA(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR2_TA_SHIFT)) & SEMC_SRAMCR2_TA_MASK)

#define SEMC_SRAMCR2_AWDH_MASK                   (0xF000U)
#define SEMC_SRAMCR2_AWDH_SHIFT                  (12U)
/*! AWDH - Address to write data hold time */
#define SEMC_SRAMCR2_AWDH(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR2_AWDH_SHIFT)) & SEMC_SRAMCR2_AWDH_MASK)

#define SEMC_SRAMCR2_CEITV_MASK                  (0xF000000U)
#define SEMC_SRAMCR2_CEITV_SHIFT                 (24U)
/*! CEITV - CE# interval time */
#define SEMC_SRAMCR2_CEITV(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_SRAMCR2_CEITV_SHIFT)) & SEMC_SRAMCR2_CEITV_MASK)
/*! @} */

/*! @name DBICR0 - DBI-B control register 0 */
/*! @{ */

#define SEMC_DBICR0_PS_MASK                      (0x1U)
#define SEMC_DBICR0_PS_SHIFT                     (0U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define SEMC_DBICR0_PS(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR0_PS_SHIFT)) & SEMC_DBICR0_PS_MASK)

#define SEMC_DBICR0_BL_MASK                      (0x70U)
#define SEMC_DBICR0_BL_SHIFT                     (4U)
/*! BL - Burst Length
 *  0b000..1
 *  0b001..2
 *  0b010..4
 *  0b011..8
 *  0b100..16
 *  0b101..32
 *  0b110..64
 *  0b111..64
 */
#define SEMC_DBICR0_BL(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR0_BL_SHIFT)) & SEMC_DBICR0_BL_MASK)

#define SEMC_DBICR0_COL_MASK                     (0xF000U)
#define SEMC_DBICR0_COL_SHIFT                    (12U)
/*! COL - Column Address bit width
 *  0b0000..12 Bits
 *  0b0001..11 Bits
 *  0b0010..10 Bits
 *  0b0011..9 Bits
 *  0b0100..8 Bits
 *  0b0101..7 Bits
 *  0b0110..6 Bits
 *  0b0111..5 Bits
 *  0b1000..4 Bits
 *  0b1001..3 Bits
 *  0b1010..2 Bits
 *  0b1011..12 Bits
 *  0b1100..12 Bits
 *  0b1101..12 Bits
 *  0b1110..12 Bits
 *  0b1111..12 Bits
 */
#define SEMC_DBICR0_COL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR0_COL_SHIFT)) & SEMC_DBICR0_COL_MASK)
/*! @} */

/*! @name DBICR1 - DBI-B control register 1 */
/*! @{ */

#define SEMC_DBICR1_CES_MASK                     (0xFU)
#define SEMC_DBICR1_CES_SHIFT                    (0U)
/*! CES - CSX Setup Time */
#define SEMC_DBICR1_CES(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_CES_SHIFT)) & SEMC_DBICR1_CES_MASK)

#define SEMC_DBICR1_CEH_MASK                     (0xF0U)
#define SEMC_DBICR1_CEH_SHIFT                    (4U)
/*! CEH - CSX Hold Time */
#define SEMC_DBICR1_CEH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_CEH_SHIFT)) & SEMC_DBICR1_CEH_MASK)

#define SEMC_DBICR1_WEL_MASK                     (0xF00U)
#define SEMC_DBICR1_WEL_SHIFT                    (8U)
/*! WEL - WRX Low Time */
#define SEMC_DBICR1_WEL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_WEL_SHIFT)) & SEMC_DBICR1_WEL_MASK)

#define SEMC_DBICR1_WEH_MASK                     (0xF000U)
#define SEMC_DBICR1_WEH_SHIFT                    (12U)
/*! WEH - WRX High Time */
#define SEMC_DBICR1_WEH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_WEH_SHIFT)) & SEMC_DBICR1_WEH_MASK)

#define SEMC_DBICR1_REL_MASK                     (0xF0000U)
#define SEMC_DBICR1_REL_SHIFT                    (16U)
/*! REL - RDX Low Time bit [3:0] */
#define SEMC_DBICR1_REL(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_REL_SHIFT)) & SEMC_DBICR1_REL_MASK)

#define SEMC_DBICR1_REH_MASK                     (0xF00000U)
#define SEMC_DBICR1_REH_SHIFT                    (20U)
/*! REH - RDX High Time bit [3:0] */
#define SEMC_DBICR1_REH(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_REH_SHIFT)) & SEMC_DBICR1_REH_MASK)

#define SEMC_DBICR1_CEITV_MASK                   (0xF000000U)
#define SEMC_DBICR1_CEITV_SHIFT                  (24U)
/*! CEITV - CSX interval time */
#define SEMC_DBICR1_CEITV(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_CEITV_SHIFT)) & SEMC_DBICR1_CEITV_MASK)

#define SEMC_DBICR1_REL2_MASK                    (0x30000000U)
#define SEMC_DBICR1_REL2_SHIFT                   (28U)
/*! REL2 - RDX Low Time bit [5:4] */
#define SEMC_DBICR1_REL2(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_REL2_SHIFT)) & SEMC_DBICR1_REL2_MASK)

#define SEMC_DBICR1_REH2_MASK                    (0xC0000000U)
#define SEMC_DBICR1_REH2_SHIFT                   (30U)
/*! REH2 - RDX High Time bit [5:4] */
#define SEMC_DBICR1_REH2(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_DBICR1_REH2_SHIFT)) & SEMC_DBICR1_REH2_MASK)
/*! @} */

/*! @name IPCR0 - IP Command control register 0 */
/*! @{ */

#define SEMC_IPCR0_SA_MASK                       (0xFFFFFFFFU)
#define SEMC_IPCR0_SA_SHIFT                      (0U)
/*! SA - Slave address */
#define SEMC_IPCR0_SA(x)                         (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR0_SA_SHIFT)) & SEMC_IPCR0_SA_MASK)
/*! @} */

/*! @name IPCR1 - IP Command control register 1 */
/*! @{ */

#define SEMC_IPCR1_DATSZ_MASK                    (0x7U)
#define SEMC_IPCR1_DATSZ_SHIFT                   (0U)
/*! DATSZ - Data Size in Byte
 *  0b000..4
 *  0b001..1
 *  0b010..2
 *  0b011..3
 *  0b100..4
 *  0b101..4
 *  0b110..4
 *  0b111..4
 */
#define SEMC_IPCR1_DATSZ(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR1_DATSZ_SHIFT)) & SEMC_IPCR1_DATSZ_MASK)
/*! @} */

/*! @name IPCR2 - IP Command control register 2 */
/*! @{ */

#define SEMC_IPCR2_BM0_MASK                      (0x1U)
#define SEMC_IPCR2_BM0_SHIFT                     (0U)
/*! BM0 - Byte Mask for Byte 0 (IPTXD bit 7:0)
 *  0b0..Byte Unmasked
 *  0b1..Byte Masked
 */
#define SEMC_IPCR2_BM0(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR2_BM0_SHIFT)) & SEMC_IPCR2_BM0_MASK)

#define SEMC_IPCR2_BM1_MASK                      (0x2U)
#define SEMC_IPCR2_BM1_SHIFT                     (1U)
/*! BM1 - Byte Mask for Byte 1 (IPTXD bit 15:8)
 *  0b0..Byte Unmasked
 *  0b1..Byte Masked
 */
#define SEMC_IPCR2_BM1(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR2_BM1_SHIFT)) & SEMC_IPCR2_BM1_MASK)

#define SEMC_IPCR2_BM2_MASK                      (0x4U)
#define SEMC_IPCR2_BM2_SHIFT                     (2U)
/*! BM2 - Byte Mask for Byte 2 (IPTXD bit 23:16)
 *  0b0..Byte Unmasked
 *  0b1..Byte Masked
 */
#define SEMC_IPCR2_BM2(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR2_BM2_SHIFT)) & SEMC_IPCR2_BM2_MASK)

#define SEMC_IPCR2_BM3_MASK                      (0x8U)
#define SEMC_IPCR2_BM3_SHIFT                     (3U)
/*! BM3 - Byte Mask for Byte 3 (IPTXD bit 31:24)
 *  0b0..Byte Unmasked
 *  0b1..Byte Masked
 */
#define SEMC_IPCR2_BM3(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCR2_BM3_SHIFT)) & SEMC_IPCR2_BM3_MASK)
/*! @} */

/*! @name IPCMD - IP Command register */
/*! @{ */

#define SEMC_IPCMD_CMD_MASK                      (0xFFFFU)
#define SEMC_IPCMD_CMD_SHIFT                     (0U)
#define SEMC_IPCMD_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCMD_CMD_SHIFT)) & SEMC_IPCMD_CMD_MASK)

#define SEMC_IPCMD_KEY_MASK                      (0xFFFF0000U)
#define SEMC_IPCMD_KEY_SHIFT                     (16U)
/*! KEY - This field should be written with 0xA55A when trigging an IP command. */
#define SEMC_IPCMD_KEY(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_IPCMD_KEY_SHIFT)) & SEMC_IPCMD_KEY_MASK)
/*! @} */

/*! @name IPTXDAT - TX DATA register (for IP Command) */
/*! @{ */

#define SEMC_IPTXDAT_DAT_MASK                    (0xFFFFFFFFU)
#define SEMC_IPTXDAT_DAT_SHIFT                   (0U)
/*! DAT - data */
#define SEMC_IPTXDAT_DAT(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_IPTXDAT_DAT_SHIFT)) & SEMC_IPTXDAT_DAT_MASK)
/*! @} */

/*! @name IPRXDAT - RX DATA register (for IP Command) */
/*! @{ */

#define SEMC_IPRXDAT_DAT_MASK                    (0xFFFFFFFFU)
#define SEMC_IPRXDAT_DAT_SHIFT                   (0U)
/*! DAT - data */
#define SEMC_IPRXDAT_DAT(x)                      (((uint32_t)(((uint32_t)(x)) << SEMC_IPRXDAT_DAT_SHIFT)) & SEMC_IPRXDAT_DAT_MASK)
/*! @} */

/*! @name STS0 - Status register 0 */
/*! @{ */

#define SEMC_STS0_IDLE_MASK                      (0x1U)
#define SEMC_STS0_IDLE_SHIFT                     (0U)
/*! IDLE - Indicating whether SEMC is in IDLE state. */
#define SEMC_STS0_IDLE(x)                        (((uint32_t)(((uint32_t)(x)) << SEMC_STS0_IDLE_SHIFT)) & SEMC_STS0_IDLE_MASK)

#define SEMC_STS0_NARDY_MASK                     (0x2U)
#define SEMC_STS0_NARDY_SHIFT                    (1U)
/*! NARDY - Indicating NAND device Ready/WAIT# pin level.
 *  0b0..NAND device is not ready
 *  0b1..NAND device is ready
 */
#define SEMC_STS0_NARDY(x)                       (((uint32_t)(((uint32_t)(x)) << SEMC_STS0_NARDY_SHIFT)) & SEMC_STS0_NARDY_MASK)
/*! @} */

/*! @name STS2 - Status register 2 */
/*! @{ */

#define SEMC_STS2_NDWRPEND_MASK                  (0x8U)
#define SEMC_STS2_NDWRPEND_SHIFT                 (3U)
/*! NDWRPEND - This field indicating whether there is pending AXI command (write) to NAND device.
 *  0b0..No pending
 *  0b1..Pending
 */
#define SEMC_STS2_NDWRPEND(x)                    (((uint32_t)(((uint32_t)(x)) << SEMC_STS2_NDWRPEND_SHIFT)) & SEMC_STS2_NDWRPEND_MASK)
/*! @} */

/*! @name STS12 - Status register 12 */
/*! @{ */

#define SEMC_STS12_NDADDR_MASK                   (0xFFFFFFFFU)
#define SEMC_STS12_NDADDR_SHIFT                  (0U)
/*! NDADDR - This field indicating the last write address (AXI command) to NAND device (without base address in SEMC_BR4). */
#define SEMC_STS12_NDADDR(x)                     (((uint32_t)(((uint32_t)(x)) << SEMC_STS12_NDADDR_SHIFT)) & SEMC_STS12_NDADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SEMC_Register_Masks */


/*!
 * @}
 */ /* end of group SEMC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_SEMC_H_ */

