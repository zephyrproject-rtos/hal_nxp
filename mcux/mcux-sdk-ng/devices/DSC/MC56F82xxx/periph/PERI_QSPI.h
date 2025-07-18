/*
** ###################################################################
**     Processors:          MC56F82313VLC
**                          MC56F82316VLF
**                          MC56F82323VFM
**                          MC56F82623VLC
**                          MC56F82643VLC
**                          MC56F82646VLF
**                          MC56F82723VFM
**                          MC56F82723VLC
**                          MC56F82726VLF
**                          MC56F82728VLH
**                          MC56F82733MFM
**                          MC56F82733VFM
**                          MC56F82733VLC
**                          MC56F82736VLF
**                          MC56F82738VLH
**                          MC56F82743VFM
**                          MC56F82743VLC
**                          MC56F82746MLF
**                          MC56F82746VLF
**                          MC56F82748MLH
**                          MC56F82748VLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for QSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_QSPI.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for QSPI
 *
 * CMSIS Peripheral Access Layer for QSPI
 */

#if !defined(PERI_QSPI_H_)
#define PERI_QSPI_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F82313VLC))
#include "MC56F82313_COMMON.h"
#elif (defined(CPU_MC56F82316VLF))
#include "MC56F82316_COMMON.h"
#elif (defined(CPU_MC56F82323VFM))
#include "MC56F82323_COMMON.h"
#elif (defined(CPU_MC56F82623VLC))
#include "MC56F82623_COMMON.h"
#elif (defined(CPU_MC56F82643VLC))
#include "MC56F82643_COMMON.h"
#elif (defined(CPU_MC56F82646VLF))
#include "MC56F82646_COMMON.h"
#elif (defined(CPU_MC56F82723VFM) || defined(CPU_MC56F82723VLC))
#include "MC56F82723_COMMON.h"
#elif (defined(CPU_MC56F82726VLF))
#include "MC56F82726_COMMON.h"
#elif (defined(CPU_MC56F82728VLH))
#include "MC56F82728_COMMON.h"
#elif (defined(CPU_MC56F82733MFM) || defined(CPU_MC56F82733VFM) || defined(CPU_MC56F82733VLC))
#include "MC56F82733_COMMON.h"
#elif (defined(CPU_MC56F82736VLF))
#include "MC56F82736_COMMON.h"
#elif (defined(CPU_MC56F82738VLH))
#include "MC56F82738_COMMON.h"
#elif (defined(CPU_MC56F82743VFM) || defined(CPU_MC56F82743VLC))
#include "MC56F82743_COMMON.h"
#elif (defined(CPU_MC56F82746MLF) || defined(CPU_MC56F82746VLF))
#include "MC56F82746_COMMON.h"
#elif (defined(CPU_MC56F82748MLH) || defined(CPU_MC56F82748VLH))
#include "MC56F82748_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- QSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QSPI_Peripheral_Access_Layer QSPI Peripheral Access Layer
 * @{
 */

/** QSPI - Register Layout Typedef */
typedef struct {
  __IO uint16_t SPSCR;                             /**< SPI Status and Control Register, offset: 0x0 */
  __IO uint16_t SPDSR;                             /**< SPI Data Size and Control Register, offset: 0x1 */
  __I  uint16_t SPDRR;                             /**< SPI Data Receive Register, offset: 0x2 */
  __O  uint16_t SPDTR;                             /**< SPI Data Transmit Register, offset: 0x3 */
  __IO uint16_t SPFIFO;                            /**< SPI FIFO Control Register, offset: 0x4 */
  __IO uint16_t SPWAIT;                            /**< SPI Word Delay Register, offset: 0x5 */
  __IO uint16_t SPCTL2;                            /**< SPI Control Register 2, offset: 0x6 */
} QSPI_Type;

/* ----------------------------------------------------------------------------
   -- QSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QSPI_Register_Masks QSPI Register Masks
 * @{
 */

/*! @name SPSCR - SPI Status and Control Register */
/*! @{ */

#define QSPI_SPSCR_SPTE_MASK                     (0x1U)
#define QSPI_SPSCR_SPTE_SHIFT                    (0U)
/*! SPTE - SPI Transmitter Empty
 *  0b0..Transmit data register or FIFO is not empty. (If using the FIFO, read TFCNT to determine how many words can be written safely.)
 *  0b1..Transmit data register or FIFO is empty.
 */
#define QSPI_SPSCR_SPTE(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPTE_SHIFT)) & QSPI_SPSCR_SPTE_MASK)

#define QSPI_SPSCR_MODF_MASK                     (0x2U)
#define QSPI_SPSCR_MODF_SHIFT                    (1U)
/*! MODF - Mode Fault
 *  0b0..SS_B pin at appropriate logic level
 *  0b1..SS_B pin at inappropriate logic level
 */
#define QSPI_SPSCR_MODF(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_MODF_SHIFT)) & QSPI_SPSCR_MODF_MASK)

#define QSPI_SPSCR_OVRF_MASK                     (0x4U)
#define QSPI_SPSCR_OVRF_SHIFT                    (2U)
/*! OVRF - Overflow
 *  0b0..No overflow
 *  0b1..Overflow
 */
#define QSPI_SPSCR_OVRF(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_OVRF_SHIFT)) & QSPI_SPSCR_OVRF_MASK)

#define QSPI_SPSCR_SPRF_MASK                     (0x8U)
#define QSPI_SPSCR_SPRF_SHIFT                    (3U)
/*! SPRF - SPI Receiver Full
 *  0b0..Receive data register or FIFO is not full. (If using the FIFO, read RFCNT to determine the number of valid words available.)
 *  0b1..Receive data register or FIFO is full.
 */
#define QSPI_SPSCR_SPRF(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPRF_SHIFT)) & QSPI_SPSCR_SPRF_MASK)

#define QSPI_SPSCR_SPTIE_MASK                    (0x10U)
#define QSPI_SPSCR_SPTIE_SHIFT                   (4U)
/*! SPTIE - Transmit Interrupt Enable
 *  0b0..SPTE interrupt requests disabled
 *  0b1..SPTE interrupt requests enabled
 */
#define QSPI_SPSCR_SPTIE(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPTIE_SHIFT)) & QSPI_SPSCR_SPTIE_MASK)

#define QSPI_SPSCR_SPE_MASK                      (0x20U)
#define QSPI_SPSCR_SPE_SHIFT                     (5U)
/*! SPE - SPI Enable
 *  0b0..SPI module disabled
 *  0b1..SPI module enabled
 */
#define QSPI_SPSCR_SPE(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPE_SHIFT)) & QSPI_SPSCR_SPE_MASK)

#define QSPI_SPSCR_CPHA_MASK                     (0x40U)
#define QSPI_SPSCR_CPHA_SHIFT                    (6U)
/*! CPHA - Clock Phase */
#define QSPI_SPSCR_CPHA(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_CPHA_SHIFT)) & QSPI_SPSCR_CPHA_MASK)

#define QSPI_SPSCR_CPOL_MASK                     (0x80U)
#define QSPI_SPSCR_CPOL_SHIFT                    (7U)
/*! CPOL - Clock Polarity
 *  0b0..Rising edge of SCLK starts transaction
 *  0b1..Falling edge of SCLK starts transaction
 */
#define QSPI_SPSCR_CPOL(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_CPOL_SHIFT)) & QSPI_SPSCR_CPOL_MASK)

#define QSPI_SPSCR_SPMSTR_MASK                   (0x100U)
#define QSPI_SPSCR_SPMSTR_SHIFT                  (8U)
/*! SPMSTR - SPI Master
 *  0b0..Slave mode
 *  0b1..Master mode
 */
#define QSPI_SPSCR_SPMSTR(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPMSTR_SHIFT)) & QSPI_SPSCR_SPMSTR_MASK)

#define QSPI_SPSCR_SPRIE_MASK                    (0x200U)
#define QSPI_SPSCR_SPRIE_SHIFT                   (9U)
/*! SPRIE - SPI Receiver Interrupt Enable
 *  0b0..SPRF interrupt requests disabled
 *  0b1..SPRF interrupt requests enabled
 */
#define QSPI_SPSCR_SPRIE(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPRIE_SHIFT)) & QSPI_SPSCR_SPRIE_MASK)

#define QSPI_SPSCR_MODFEN_MASK                   (0x400U)
#define QSPI_SPSCR_MODFEN_SHIFT                  (10U)
/*! MODFEN - Mode Fault Enable */
#define QSPI_SPSCR_MODFEN(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_MODFEN_SHIFT)) & QSPI_SPSCR_MODFEN_MASK)

#define QSPI_SPSCR_ERRIE_MASK                    (0x800U)
#define QSPI_SPSCR_ERRIE_SHIFT                   (11U)
/*! ERRIE - Error Interrupt Enable
 *  0b0..MODF and OVRF cannot generate device interrupt requests
 *  0b1..MODF and OVRF can generate device interrupt requests
 */
#define QSPI_SPSCR_ERRIE(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_ERRIE_SHIFT)) & QSPI_SPSCR_ERRIE_MASK)

#define QSPI_SPSCR_DSO_MASK                      (0x1000U)
#define QSPI_SPSCR_DSO_SHIFT                     (12U)
/*! DSO - Data Shift Order
 *  0b0..MSB transmitted first (MSB -> LSB)
 *  0b1..LSB transmitted first (LSB -> MSB)
 */
#define QSPI_SPSCR_DSO(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_DSO_SHIFT)) & QSPI_SPSCR_DSO_MASK)

#define QSPI_SPSCR_SPR_MASK                      (0xE000U)
#define QSPI_SPSCR_SPR_SHIFT                     (13U)
/*! SPR - SPI Baud Rate Select
 *  0b000..BD = 2 when SPR3 = 0, BD = 512 when SPR3 = 1 (double BD when BD2X = 1)
 *  0b001..BD = 4 when SPR3 = 0, BD = 1024 when SPR3 = 1 (double BD when BD2X = 1)
 *  0b010..BD = 8 when SPR3 = 0, BD = 2048 when SPR3 = 1 (double BD when BD2X = 1)
 *  0b011..BD = 16 when SPR3 = 0, BD = 4096 when SPR3 = 1 (double BD when BD2X = 1)
 *  0b100..BD = 32 when SPR3 = 0, BD = 8192 when SPR3 = 1 (double BD when BD2X = 1)
 *  0b101..BD = 64 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
 *  0b110..BD = 128 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
 *  0b111..BD = 256 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
 */
#define QSPI_SPSCR_SPR(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPSCR_SPR_SHIFT)) & QSPI_SPSCR_SPR_MASK)
/*! @} */

/*! @name SPDSR - SPI Data Size and Control Register */
/*! @{ */

#define QSPI_SPDSR_DS_MASK                       (0xFU)
#define QSPI_SPDSR_DS_SHIFT                      (0U)
/*! DS - Transaction data size
 *  0b0000..Not allowed
 *  0b0001..2 bits transaction data size
 *  0b0010..3 bits transaction data size
 *  0b0011..4 bits transaction data size
 *  0b0100..5 bits transaction data size
 *  0b0101..6 bits transaction data size
 *  0b0110..7 bits transaction data size
 *  0b0111..8 bits transaction data size
 *  0b1000..9 bits transaction data size
 *  0b1001..10 bits transaction data size
 *  0b1010..11 bits transaction data size
 *  0b1011..12 bits transaction data size
 *  0b1100..13 bits transaction data size
 *  0b1101..14 bits transaction data size
 *  0b1110..15 bits transaction data size
 *  0b1111..16 bits transaction data size
 */
#define QSPI_SPDSR_DS(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_DS_SHIFT)) & QSPI_SPDSR_DS_MASK)

#define QSPI_SPDSR_SPR3_MASK                     (0x10U)
#define QSPI_SPDSR_SPR3_SHIFT                    (4U)
/*! SPR3 - SPI Baud Rate Select */
#define QSPI_SPDSR_SPR3(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SPR3_SHIFT)) & QSPI_SPDSR_SPR3_MASK)

#define QSPI_SPDSR_SSB_OVER_MASK                 (0x20U)
#define QSPI_SPDSR_SSB_OVER_SHIFT                (5U)
/*! SSB_OVER - SS_B Override
 *  0b0..SS_B internal module input is selected to be connected to a GPIO pin.
 *  0b1..SS_B internal module input is selected to be equal to SPMSTR.
 */
#define QSPI_SPDSR_SSB_OVER(x)                   (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_OVER_SHIFT)) & QSPI_SPDSR_SSB_OVER_MASK)

#define QSPI_SPDSR_SSB_STRB_MASK                 (0x40U)
#define QSPI_SPDSR_SSB_STRB_SHIFT                (6U)
/*! SSB_STRB - SS_B Strobe Mode
 *  0b0..No SS_B pulse between words.
 *  0b1..SS_B output signal is pulsed high between words. This adds 1.5 baud clocks to the total word period. The
 *       idle state of SS_B is low unless SSB_AUTO is high and then the idle state is high. Do not use if MODFEN =
 *       1.
 */
#define QSPI_SPDSR_SSB_STRB(x)                   (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_STRB_SHIFT)) & QSPI_SPDSR_SSB_STRB_MASK)

#define QSPI_SPDSR_SSB_DDR_MASK                  (0x80U)
#define QSPI_SPDSR_SSB_DDR_SHIFT                 (7U)
/*! SSB_DDR - SS_B Data Direction
 *  0b0..SS_B is configured as an input pin. Use this setting in slave mode or in master mode with MODFEN=1.
 *  0b1..SS_B is configured as an output pin. Use this setting in master mode with MODFEN=0.
 */
#define QSPI_SPDSR_SSB_DDR(x)                    (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_DDR_SHIFT)) & QSPI_SPDSR_SSB_DDR_MASK)

#define QSPI_SPDSR_SSB_AUTO_MASK                 (0x100U)
#define QSPI_SPDSR_SSB_AUTO_SHIFT                (8U)
/*! SSB_AUTO - SS_B Automatic Mode
 *  0b0..SS_B output signal is software generated by directly manipulating the various bits in this register or
 *       the GPIO registers (compatible with legacy SPI software).
 *  0b1..SS_B output signal is hardware generated to create the initial falling edge and final rising edge. The
 *       idle state of the SS_B is high. Do not use if MODFEN = 1.
 */
#define QSPI_SPDSR_SSB_AUTO(x)                   (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_AUTO_SHIFT)) & QSPI_SPDSR_SSB_AUTO_MASK)

#define QSPI_SPDSR_SSB_ODM_MASK                  (0x200U)
#define QSPI_SPDSR_SSB_ODM_SHIFT                 (9U)
/*! SSB_ODM - SS_B Open Drain Mode
 *  0b0..SS_B is configured for high and low drive. This mode is generally used in single master systems.
 *  0b1..SS_B is configured as an open drain pin (only drives low output level). This mode is useful for multiple master systems.
 */
#define QSPI_SPDSR_SSB_ODM(x)                    (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_ODM_SHIFT)) & QSPI_SPDSR_SSB_ODM_MASK)

#define QSPI_SPDSR_SSB_DATA_MASK                 (0x400U)
#define QSPI_SPDSR_SSB_DATA_SHIFT                (10U)
/*! SSB_DATA - SS_B Data
 *  0b0..SS_B pin is driven low if SSB_DDR=1
 *  0b1..SS_B pin is driven high if SSB_DDR=1
 */
#define QSPI_SPDSR_SSB_DATA(x)                   (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_DATA_SHIFT)) & QSPI_SPDSR_SSB_DATA_MASK)

#define QSPI_SPDSR_SSB_IN_MASK                   (0x800U)
#define QSPI_SPDSR_SSB_IN_SHIFT                  (11U)
/*! SSB_IN - SS_B Input */
#define QSPI_SPDSR_SSB_IN(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_SSB_IN_SHIFT)) & QSPI_SPDSR_SSB_IN_MASK)

#define QSPI_SPDSR_BD2X_MASK                     (0x1000U)
#define QSPI_SPDSR_BD2X_SHIFT                    (12U)
/*! BD2X - Baud Divisor Times */
#define QSPI_SPDSR_BD2X(x)                       (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_BD2X_SHIFT)) & QSPI_SPDSR_BD2X_MASK)

#define QSPI_SPDSR_RDMAEN_MASK                   (0x2000U)
#define QSPI_SPDSR_RDMAEN_SHIFT                  (13U)
/*! RDMAEN - Receive DMA Enable */
#define QSPI_SPDSR_RDMAEN(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_RDMAEN_SHIFT)) & QSPI_SPDSR_RDMAEN_MASK)

#define QSPI_SPDSR_TDMAEN_MASK                   (0x4000U)
#define QSPI_SPDSR_TDMAEN_SHIFT                  (14U)
/*! TDMAEN - Transmit DMA Enable */
#define QSPI_SPDSR_TDMAEN(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_TDMAEN_SHIFT)) & QSPI_SPDSR_TDMAEN_MASK)

#define QSPI_SPDSR_WOM_MASK                      (0x8000U)
#define QSPI_SPDSR_WOM_SHIFT                     (15U)
/*! WOM - Wired-OR Mode
 *  0b0..The SPI pins are configured as push-pull drivers.
 *  0b1..The SPI pins are configured as open-drain drivers with the pull-ups disabled.
 */
#define QSPI_SPDSR_WOM(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDSR_WOM_SHIFT)) & QSPI_SPDSR_WOM_MASK)
/*! @} */

/*! @name SPDRR - SPI Data Receive Register */
/*! @{ */

#define QSPI_SPDRR_R0_MASK                       (0x1U)
#define QSPI_SPDRR_R0_SHIFT                      (0U)
/*! R0 - Receive Data Bit 0 */
#define QSPI_SPDRR_R0(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R0_SHIFT)) & QSPI_SPDRR_R0_MASK)

#define QSPI_SPDRR_R1_MASK                       (0x2U)
#define QSPI_SPDRR_R1_SHIFT                      (1U)
/*! R1 - Receive Data Bit 1 */
#define QSPI_SPDRR_R1(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R1_SHIFT)) & QSPI_SPDRR_R1_MASK)

#define QSPI_SPDRR_R2_MASK                       (0x4U)
#define QSPI_SPDRR_R2_SHIFT                      (2U)
/*! R2 - Receive Data Bit 2 */
#define QSPI_SPDRR_R2(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R2_SHIFT)) & QSPI_SPDRR_R2_MASK)

#define QSPI_SPDRR_R3_MASK                       (0x8U)
#define QSPI_SPDRR_R3_SHIFT                      (3U)
/*! R3 - Receive Data Bit 3 */
#define QSPI_SPDRR_R3(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R3_SHIFT)) & QSPI_SPDRR_R3_MASK)

#define QSPI_SPDRR_R4_MASK                       (0x10U)
#define QSPI_SPDRR_R4_SHIFT                      (4U)
/*! R4 - Receive Data Bit 4 */
#define QSPI_SPDRR_R4(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R4_SHIFT)) & QSPI_SPDRR_R4_MASK)

#define QSPI_SPDRR_R5_MASK                       (0x20U)
#define QSPI_SPDRR_R5_SHIFT                      (5U)
/*! R5 - Receive Data Bit 5 */
#define QSPI_SPDRR_R5(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R5_SHIFT)) & QSPI_SPDRR_R5_MASK)

#define QSPI_SPDRR_R6_MASK                       (0x40U)
#define QSPI_SPDRR_R6_SHIFT                      (6U)
/*! R6 - Receive Data Bit 6 */
#define QSPI_SPDRR_R6(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R6_SHIFT)) & QSPI_SPDRR_R6_MASK)

#define QSPI_SPDRR_R7_MASK                       (0x80U)
#define QSPI_SPDRR_R7_SHIFT                      (7U)
/*! R7 - Receive Data Bit 7 */
#define QSPI_SPDRR_R7(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R7_SHIFT)) & QSPI_SPDRR_R7_MASK)

#define QSPI_SPDRR_R8_MASK                       (0x100U)
#define QSPI_SPDRR_R8_SHIFT                      (8U)
/*! R8 - Receive Data Bit 8 */
#define QSPI_SPDRR_R8(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R8_SHIFT)) & QSPI_SPDRR_R8_MASK)

#define QSPI_SPDRR_R9_MASK                       (0x200U)
#define QSPI_SPDRR_R9_SHIFT                      (9U)
/*! R9 - Receive Data Bit 9 */
#define QSPI_SPDRR_R9(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R9_SHIFT)) & QSPI_SPDRR_R9_MASK)

#define QSPI_SPDRR_R10_MASK                      (0x400U)
#define QSPI_SPDRR_R10_SHIFT                     (10U)
/*! R10 - Receive Data Bit 10 */
#define QSPI_SPDRR_R10(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R10_SHIFT)) & QSPI_SPDRR_R10_MASK)

#define QSPI_SPDRR_R11_MASK                      (0x800U)
#define QSPI_SPDRR_R11_SHIFT                     (11U)
/*! R11 - Receive Data Bit 11 */
#define QSPI_SPDRR_R11(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R11_SHIFT)) & QSPI_SPDRR_R11_MASK)

#define QSPI_SPDRR_R12_MASK                      (0x1000U)
#define QSPI_SPDRR_R12_SHIFT                     (12U)
/*! R12 - Receive Data Bit 12 */
#define QSPI_SPDRR_R12(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R12_SHIFT)) & QSPI_SPDRR_R12_MASK)

#define QSPI_SPDRR_R13_MASK                      (0x2000U)
#define QSPI_SPDRR_R13_SHIFT                     (13U)
/*! R13 - Receive Data Bit 13 */
#define QSPI_SPDRR_R13(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R13_SHIFT)) & QSPI_SPDRR_R13_MASK)

#define QSPI_SPDRR_R14_MASK                      (0x4000U)
#define QSPI_SPDRR_R14_SHIFT                     (14U)
/*! R14 - Receive Data Bit 14 */
#define QSPI_SPDRR_R14(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R14_SHIFT)) & QSPI_SPDRR_R14_MASK)

#define QSPI_SPDRR_R15_MASK                      (0x8000U)
#define QSPI_SPDRR_R15_SHIFT                     (15U)
/*! R15 - Receive Data Bit 15 */
#define QSPI_SPDRR_R15(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDRR_R15_SHIFT)) & QSPI_SPDRR_R15_MASK)
/*! @} */

/*! @name SPDTR - SPI Data Transmit Register */
/*! @{ */

#define QSPI_SPDTR_T0_MASK                       (0x1U)
#define QSPI_SPDTR_T0_SHIFT                      (0U)
/*! T0 - Transmit Data Bit 0 */
#define QSPI_SPDTR_T0(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T0_SHIFT)) & QSPI_SPDTR_T0_MASK)

#define QSPI_SPDTR_T1_MASK                       (0x2U)
#define QSPI_SPDTR_T1_SHIFT                      (1U)
/*! T1 - Transmit Data Bit 1 */
#define QSPI_SPDTR_T1(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T1_SHIFT)) & QSPI_SPDTR_T1_MASK)

#define QSPI_SPDTR_T2_MASK                       (0x4U)
#define QSPI_SPDTR_T2_SHIFT                      (2U)
/*! T2 - Transmit Data Bit 2 */
#define QSPI_SPDTR_T2(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T2_SHIFT)) & QSPI_SPDTR_T2_MASK)

#define QSPI_SPDTR_T3_MASK                       (0x8U)
#define QSPI_SPDTR_T3_SHIFT                      (3U)
/*! T3 - Transmit Data Bit 3 */
#define QSPI_SPDTR_T3(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T3_SHIFT)) & QSPI_SPDTR_T3_MASK)

#define QSPI_SPDTR_T4_MASK                       (0x10U)
#define QSPI_SPDTR_T4_SHIFT                      (4U)
/*! T4 - Transmit Data Bit 4 */
#define QSPI_SPDTR_T4(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T4_SHIFT)) & QSPI_SPDTR_T4_MASK)

#define QSPI_SPDTR_T5_MASK                       (0x20U)
#define QSPI_SPDTR_T5_SHIFT                      (5U)
/*! T5 - Transmit Data Bit 5 */
#define QSPI_SPDTR_T5(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T5_SHIFT)) & QSPI_SPDTR_T5_MASK)

#define QSPI_SPDTR_T6_MASK                       (0x40U)
#define QSPI_SPDTR_T6_SHIFT                      (6U)
/*! T6 - Transmit Data Bit 6 */
#define QSPI_SPDTR_T6(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T6_SHIFT)) & QSPI_SPDTR_T6_MASK)

#define QSPI_SPDTR_T7_MASK                       (0x80U)
#define QSPI_SPDTR_T7_SHIFT                      (7U)
/*! T7 - Transmit Data Bit 7 */
#define QSPI_SPDTR_T7(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T7_SHIFT)) & QSPI_SPDTR_T7_MASK)

#define QSPI_SPDTR_T8_MASK                       (0x100U)
#define QSPI_SPDTR_T8_SHIFT                      (8U)
/*! T8 - Transmit Data Bit 8 */
#define QSPI_SPDTR_T8(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T8_SHIFT)) & QSPI_SPDTR_T8_MASK)

#define QSPI_SPDTR_T9_MASK                       (0x200U)
#define QSPI_SPDTR_T9_SHIFT                      (9U)
/*! T9 - Transmit Data Bit 9 */
#define QSPI_SPDTR_T9(x)                         (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T9_SHIFT)) & QSPI_SPDTR_T9_MASK)

#define QSPI_SPDTR_T10_MASK                      (0x400U)
#define QSPI_SPDTR_T10_SHIFT                     (10U)
/*! T10 - Transmit Data Bit 10 */
#define QSPI_SPDTR_T10(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T10_SHIFT)) & QSPI_SPDTR_T10_MASK)

#define QSPI_SPDTR_T11_MASK                      (0x800U)
#define QSPI_SPDTR_T11_SHIFT                     (11U)
/*! T11 - Transmit Data Bit 11 */
#define QSPI_SPDTR_T11(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T11_SHIFT)) & QSPI_SPDTR_T11_MASK)

#define QSPI_SPDTR_T12_MASK                      (0x1000U)
#define QSPI_SPDTR_T12_SHIFT                     (12U)
/*! T12 - Transmit Data Bit 12 */
#define QSPI_SPDTR_T12(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T12_SHIFT)) & QSPI_SPDTR_T12_MASK)

#define QSPI_SPDTR_T13_MASK                      (0x2000U)
#define QSPI_SPDTR_T13_SHIFT                     (13U)
/*! T13 - Transmit Data Bit 13 */
#define QSPI_SPDTR_T13(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T13_SHIFT)) & QSPI_SPDTR_T13_MASK)

#define QSPI_SPDTR_T14_MASK                      (0x4000U)
#define QSPI_SPDTR_T14_SHIFT                     (14U)
/*! T14 - Transmit Data Bit 14 */
#define QSPI_SPDTR_T14(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T14_SHIFT)) & QSPI_SPDTR_T14_MASK)

#define QSPI_SPDTR_T15_MASK                      (0x8000U)
#define QSPI_SPDTR_T15_SHIFT                     (15U)
/*! T15 - Transmit Data Bit 15 */
#define QSPI_SPDTR_T15(x)                        (((uint16_t)(((uint16_t)(x)) << QSPI_SPDTR_T15_SHIFT)) & QSPI_SPDTR_T15_MASK)
/*! @} */

/*! @name SPFIFO - SPI FIFO Control Register */
/*! @{ */

#define QSPI_SPFIFO_FIFO_ENA_MASK                (0x1U)
#define QSPI_SPFIFO_FIFO_ENA_SHIFT               (0U)
/*! FIFO_ENA - FIFO Enable
 *  0b0..FIFOs are disabled and reset.
 *  0b1..FIFOs are enabled. FIFOs retain their status even if SPE is set to 0.
 */
#define QSPI_SPFIFO_FIFO_ENA(x)                  (((uint16_t)(((uint16_t)(x)) << QSPI_SPFIFO_FIFO_ENA_SHIFT)) & QSPI_SPFIFO_FIFO_ENA_MASK)

#define QSPI_SPFIFO_RFWM_MASK                    (0xCU)
#define QSPI_SPFIFO_RFWM_SHIFT                   (2U)
/*! RFWM - Rx FIFO Watermark
 *  0b00..Receive interrupt active when Rx FIFO has at least one word used
 *  0b01..Receive interrupt active when Rx FIFO has at least two words used
 *  0b10..Receive interrupt active when Rx FIFO has at least three words used
 *  0b11..Receive interrupt active when Rx FIFO is full
 */
#define QSPI_SPFIFO_RFWM(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPFIFO_RFWM_SHIFT)) & QSPI_SPFIFO_RFWM_MASK)

#define QSPI_SPFIFO_TFWM_MASK                    (0x60U)
#define QSPI_SPFIFO_TFWM_SHIFT                   (5U)
/*! TFWM - Tx FIFO Watermark
 *  0b00..Transmit interrupt active when Tx FIFO is empty
 *  0b01..Transmit interrupt active when Tx FIFO has one or fewer words available
 *  0b10..Transmit interrupt active when Tx FIFO has two or fewer words available
 *  0b11..Transmit interrupt active when Tx FIFO has three or fewer words available
 */
#define QSPI_SPFIFO_TFWM(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPFIFO_TFWM_SHIFT)) & QSPI_SPFIFO_TFWM_MASK)

#define QSPI_SPFIFO_RFCNT_MASK                   (0x700U)
#define QSPI_SPFIFO_RFCNT_SHIFT                  (8U)
/*! RFCNT - RX FIFO Level
 *  0b000..Rx FIFO empty
 *  0b001..One word used in Rx FIFO
 *  0b010..Two words used in Rx FIFO
 *  0b011..Three words used in Rx FIFO
 *  0b100..Rx FIFO full (if enabled Receiver Full Interrupt asserted)
 */
#define QSPI_SPFIFO_RFCNT(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPFIFO_RFCNT_SHIFT)) & QSPI_SPFIFO_RFCNT_MASK)

#define QSPI_SPFIFO_TFCNT_MASK                   (0x7000U)
#define QSPI_SPFIFO_TFCNT_SHIFT                  (12U)
/*! TFCNT - TX FIFO Level
 *  0b000..Tx FIFO empty (if enabled Transmit Empty Interrupt asserted)
 *  0b001..One word used in Tx FIFO
 *  0b010..Two words used in Tx FIFO
 *  0b011..Three words used in Tx FIFO
 *  0b100..Tx FIFO full
 */
#define QSPI_SPFIFO_TFCNT(x)                     (((uint16_t)(((uint16_t)(x)) << QSPI_SPFIFO_TFCNT_SHIFT)) & QSPI_SPFIFO_TFCNT_MASK)
/*! @} */

/*! @name SPWAIT - SPI Word Delay Register */
/*! @{ */

#define QSPI_SPWAIT_WAIT_MASK                    (0x1FFFU)
#define QSPI_SPWAIT_WAIT_SHIFT                   (0U)
/*! WAIT - Wait Delay */
#define QSPI_SPWAIT_WAIT(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPWAIT_WAIT_SHIFT)) & QSPI_SPWAIT_WAIT_MASK)
/*! @} */

/*! @name SPCTL2 - SPI Control Register 2 */
/*! @{ */

#define QSPI_SPCTL2_SHEN_MASK                    (0x1U)
#define QSPI_SPCTL2_SHEN_SHIFT                   (0U)
/*! SHEN - Stop Mode Holdoff Enable
 *  0b0..Disable stop mode holdoff .
 *  0b1..Enable stop mode holdoff while the SPI is transmitting/receiving.
 */
#define QSPI_SPCTL2_SHEN(x)                      (((uint16_t)(((uint16_t)(x)) << QSPI_SPCTL2_SHEN_SHIFT)) & QSPI_SPCTL2_SHEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QSPI_Register_Masks */


/*!
 * @}
 */ /* end of group QSPI_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_QSPI_H_ */

