/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SPI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPI
 *
 * CMSIS Peripheral Access Layer for SPI
 */

#if !defined(PERI_SPI_H_)
#define PERI_SPI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint8_t S;                                  /**< SPI Status Register, offset: 0x0 */
  __IO uint8_t BR;                                 /**< SPI Baud Rate Register, offset: 0x1 */
  __IO uint8_t C2;                                 /**< SPI Control Register 2, offset: 0x2 */
  __IO uint8_t C1;                                 /**< SPI Control Register 1, offset: 0x3 */
  __IO uint8_t ML;                                 /**< SPI Match Register low, offset: 0x4 */
  __IO uint8_t MH;                                 /**< SPI match register high, offset: 0x5 */
  __IO uint8_t DL;                                 /**< SPI Data Register low, offset: 0x6 */
  __IO uint8_t DH;                                 /**< SPI data register high, offset: 0x7 */
       uint8_t RESERVED_0[2];
  __IO uint8_t CI;                                 /**< SPI clear interrupt register, offset: 0xA, available only on: SPI1 (missing on SPI0) */
  __IO uint8_t C3;                                 /**< SPI control register 3, offset: 0xB, available only on: SPI1 (missing on SPI0) */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/*! @name S - SPI Status Register */
/*! @{ */

#define SPI_S_RFIFOEF_MASK                       (0x1U)
#define SPI_S_RFIFOEF_SHIFT                      (0U)
/*! RFIFOEF - SPI read FIFO empty flag
 *  0b0..Read FIFO has data. Reads of the DH:DL registers in 16-bit mode or the DL register in 8-bit mode will empty the read FIFO.
 *  0b1..Read FIFO is empty.
 */
#define SPI_S_RFIFOEF(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_S_RFIFOEF_SHIFT)) & SPI_S_RFIFOEF_MASK)

#define SPI_S_TXFULLF_MASK                       (0x2U)
#define SPI_S_TXFULLF_SHIFT                      (1U)
/*! TXFULLF - Transmit FIFO full flag
 *  0b0..Transmit FIFO has less than 8 bytes
 *  0b1..Transmit FIFO has 8 bytes of data
 */
#define SPI_S_TXFULLF(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_S_TXFULLF_SHIFT)) & SPI_S_TXFULLF_MASK)

#define SPI_S_TNEAREF_MASK                       (0x4U)
#define SPI_S_TNEAREF_SHIFT                      (2U)
/*! TNEAREF - Transmit FIFO nearly empty flag
 *  0b0..Transmit FIFO has more than 16 bits (when C3[TNEAREF_MARK] is 0) or more than 32 bits (when C3[TNEAREF_MARK] is 1) remaining to transmit
 *  0b1..Transmit FIFO has an amount of data equal to or less than 16 bits (when C3[TNEAREF_MARK] is 0) or 32 bits
 *       (when C3[TNEAREF_MARK] is 1) remaining to transmit
 */
#define SPI_S_TNEAREF(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_S_TNEAREF_SHIFT)) & SPI_S_TNEAREF_MASK)

#define SPI_S_RNFULLF_MASK                       (0x8U)
#define SPI_S_RNFULLF_SHIFT                      (3U)
/*! RNFULLF - Receive FIFO nearly full flag
 *  0b0..Receive FIFO has received less than 48 bits (when C3[RNFULLF_MARK] is 0) or less than 32 bits (when C3[RNFULLF_MARK] is 1)
 *  0b1..Receive FIFO has received data of an amount equal to or greater than 48 bits (when C3[RNFULLF_MARK] is 0)
 *       or 32 bits (when C3[RNFULLF_MARK] is 1)
 */
#define SPI_S_RNFULLF(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_S_RNFULLF_SHIFT)) & SPI_S_RNFULLF_MASK)

#define SPI_S_MODF_MASK                          (0x10U)
#define SPI_S_MODF_SHIFT                         (4U)
/*! MODF - Master Mode Fault Flag
 *  0b0..No mode fault error
 *  0b1..Mode fault error detected
 */
#define SPI_S_MODF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_MODF_SHIFT)) & SPI_S_MODF_MASK)

#define SPI_S_SPTEF_MASK                         (0x20U)
#define SPI_S_SPTEF_SHIFT                        (5U)
/*! SPTEF - SPI Transmit Buffer Empty Flag (when FIFO is not supported or not enabled) or SPI
 *    transmit FIFO empty flag (when FIFO is supported and enabled)
 *  0b0..SPI transmit buffer not empty (when FIFOMODE is not present or is 0) or SPI FIFO not empty (when FIFOMODE is 1)
 *  0b1..SPI transmit buffer empty (when FIFOMODE is not present or is 0) or SPI FIFO empty (when FIFOMODE is 1)
 */
#define SPI_S_SPTEF(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_S_SPTEF_SHIFT)) & SPI_S_SPTEF_MASK)

#define SPI_S_SPMF_MASK                          (0x40U)
#define SPI_S_SPMF_SHIFT                         (6U)
/*! SPMF - SPI Match Flag
 *  0b0..Value in the receive data buffer does not match the value in the MH:ML registers
 *  0b1..Value in the receive data buffer matches the value in the MH:ML registers
 */
#define SPI_S_SPMF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_SPMF_SHIFT)) & SPI_S_SPMF_MASK)

#define SPI_S_SPRF_MASK                          (0x80U)
#define SPI_S_SPRF_SHIFT                         (7U)
/*! SPRF - SPI Read Buffer Full Flag (when FIFO is not supported or not enabled) or SPI read FIFO
 *    FULL flag (when FIFO is supported and enabled)
 *  0b0..No data available in the receive data buffer (when FIFOMODE is not present or is 0) or Read FIFO is not full (when FIFOMODE is 1)
 *  0b1..Data available in the receive data buffer (when FIFOMODE is not present or is 0) or Read FIFO is full (when FIFOMODE is 1)
 */
#define SPI_S_SPRF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_SPRF_SHIFT)) & SPI_S_SPRF_MASK)
/*! @} */

/*! @name BR - SPI Baud Rate Register */
/*! @{ */

#define SPI_BR_SPR_MASK                          (0xFU)
#define SPI_BR_SPR_SHIFT                         (0U)
/*! SPR - SPI Baud Rate Divisor
 *  0b0000..Baud rate divisor is 2.
 *  0b0001..Baud rate divisor is 4.
 *  0b0010..Baud rate divisor is 8.
 *  0b0011..Baud rate divisor is 16.
 *  0b0100..Baud rate divisor is 32.
 *  0b0101..Baud rate divisor is 64.
 *  0b0110..Baud rate divisor is 128.
 *  0b0111..Baud rate divisor is 256.
 *  0b1000..Baud rate divisor is 512.
 */
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_BR_SPR_SHIFT)) & SPI_BR_SPR_MASK)

#define SPI_BR_SPPR_MASK                         (0x70U)
#define SPI_BR_SPPR_SHIFT                        (4U)
/*! SPPR - SPI Baud Rate Prescale Divisor
 *  0b000..Baud rate prescaler divisor is 1.
 *  0b001..Baud rate prescaler divisor is 2.
 *  0b010..Baud rate prescaler divisor is 3.
 *  0b011..Baud rate prescaler divisor is 4.
 *  0b100..Baud rate prescaler divisor is 5.
 *  0b101..Baud rate prescaler divisor is 6.
 *  0b110..Baud rate prescaler divisor is 7.
 *  0b111..Baud rate prescaler divisor is 8.
 */
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_BR_SPPR_SHIFT)) & SPI_BR_SPPR_MASK)
/*! @} */

/*! @name C2 - SPI Control Register 2 */
/*! @{ */

#define SPI_C2_SPC0_MASK                         (0x1U)
#define SPI_C2_SPC0_SHIFT                        (0U)
/*! SPC0 - SPI Pin Control 0
 *  0b0..SPI uses separate pins for data input and data output (pin mode is normal). In master mode of operation:
 *       MISO is master in and MOSI is master out. In slave mode of operation: MISO is slave out and MOSI is slave
 *       in.
 *  0b1..SPI configured for single-wire bidirectional operation (pin mode is bidirectional). In master mode of
 *       operation: MISO is not used by SPI; MOSI is master in when BIDIROE is 0 or master I/O when BIDIROE is 1. In
 *       slave mode of operation: MISO is slave in when BIDIROE is 0 or slave I/O when BIDIROE is 1; MOSI is not
 *       used by SPI.
 */
#define SPI_C2_SPC0(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C2_SPC0_SHIFT)) & SPI_C2_SPC0_MASK)

#define SPI_C2_SPISWAI_MASK                      (0x2U)
#define SPI_C2_SPISWAI_SHIFT                     (1U)
/*! SPISWAI - SPI Stop in Wait Mode
 *  0b0..SPI clocks continue to operate in Wait mode.
 *  0b1..SPI clocks stop when the MCU enters Wait mode.
 */
#define SPI_C2_SPISWAI(x)                        (((uint8_t)(((uint8_t)(x)) << SPI_C2_SPISWAI_SHIFT)) & SPI_C2_SPISWAI_MASK)

#define SPI_C2_RXDMAE_MASK                       (0x4U)
#define SPI_C2_RXDMAE_SHIFT                      (2U)
/*! RXDMAE - Receive DMA enable
 *  0b0..DMA request for receive is disabled and interrupt from SPRF is allowed
 *  0b1..DMA request for receive is enabled and interrupt from SPRF is disabled
 */
#define SPI_C2_RXDMAE(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_C2_RXDMAE_SHIFT)) & SPI_C2_RXDMAE_MASK)

#define SPI_C2_BIDIROE_MASK                      (0x8U)
#define SPI_C2_BIDIROE_SHIFT                     (3U)
/*! BIDIROE - Bidirectional Mode Output Enable
 *  0b0..Output driver disabled so SPI data I/O pin acts as an input
 *  0b1..SPI I/O pin enabled as an output
 */
#define SPI_C2_BIDIROE(x)                        (((uint8_t)(((uint8_t)(x)) << SPI_C2_BIDIROE_SHIFT)) & SPI_C2_BIDIROE_MASK)

#define SPI_C2_MODFEN_MASK                       (0x10U)
#define SPI_C2_MODFEN_SHIFT                      (4U)
/*! MODFEN - Master Mode-Fault Function Enable
 *  0b0..Mode fault function disabled, master SS pin reverts to general-purpose I/O not controlled by SPI
 *  0b1..Mode fault function enabled, master SS pin acts as the mode fault input or the slave select output
 */
#define SPI_C2_MODFEN(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_C2_MODFEN_SHIFT)) & SPI_C2_MODFEN_MASK)

#define SPI_C2_TXDMAE_MASK                       (0x20U)
#define SPI_C2_TXDMAE_SHIFT                      (5U)
/*! TXDMAE - Transmit DMA enable
 *  0b0..DMA request for transmit is disabled and interrupt from SPTEF is allowed
 *  0b1..DMA request for transmit is enabled and interrupt from SPTEF is disabled
 */
#define SPI_C2_TXDMAE(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_C2_TXDMAE_SHIFT)) & SPI_C2_TXDMAE_MASK)

#define SPI_C2_SPIMODE_MASK                      (0x40U)
#define SPI_C2_SPIMODE_SHIFT                     (6U)
/*! SPIMODE - SPI 8-bit or 16-bit mode
 *  0b0..8-bit SPI shift register, match register, and buffers
 *  0b1..16-bit SPI shift register, match register, and buffers
 */
#define SPI_C2_SPIMODE(x)                        (((uint8_t)(((uint8_t)(x)) << SPI_C2_SPIMODE_SHIFT)) & SPI_C2_SPIMODE_MASK)

#define SPI_C2_SPMIE_MASK                        (0x80U)
#define SPI_C2_SPMIE_SHIFT                       (7U)
/*! SPMIE - SPI Match Interrupt Enable
 *  0b0..Interrupts from SPMF inhibited (use polling)
 *  0b1..When SPMF is 1, requests a hardware interrupt
 */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_C2_SPMIE_SHIFT)) & SPI_C2_SPMIE_MASK)
/*! @} */

/*! @name C1 - SPI Control Register 1 */
/*! @{ */

#define SPI_C1_LSBFE_MASK                        (0x1U)
#define SPI_C1_LSBFE_SHIFT                       (0U)
/*! LSBFE - LSB First (shifter direction)
 *  0b0..SPI serial data transfers start with the most significant bit.
 *  0b1..SPI serial data transfers start with the least significant bit.
 */
#define SPI_C1_LSBFE(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_C1_LSBFE_SHIFT)) & SPI_C1_LSBFE_MASK)

#define SPI_C1_SSOE_MASK                         (0x2U)
#define SPI_C1_SSOE_SHIFT                        (1U)
/*! SSOE - Slave Select Output Enable
 *  0b0..When C2[MODFEN] is 0: In master mode, SS pin function is general-purpose I/O (not SPI). In slave mode, SS
 *       pin function is slave select input. When C2[MODFEN] is 1: In master mode, SS pin function is SS input for
 *       mode fault. In slave mode, SS pin function is slave select input.
 *  0b1..When C2[MODFEN] is 0: In master mode, SS pin function is general-purpose I/O (not SPI). In slave mode, SS
 *       pin function is slave select input. When C2[MODFEN] is 1: In master mode, SS pin function is automatic SS
 *       output. In slave mode: SS pin function is slave select input.
 */
#define SPI_C1_SSOE(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_SSOE_SHIFT)) & SPI_C1_SSOE_MASK)

#define SPI_C1_CPHA_MASK                         (0x4U)
#define SPI_C1_CPHA_SHIFT                        (2U)
/*! CPHA - Clock Phase
 *  0b0..First edge on SPSCK occurs at the middle of the first cycle of a data transfer.
 *  0b1..First edge on SPSCK occurs at the start of the first cycle of a data transfer.
 */
#define SPI_C1_CPHA(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_CPHA_SHIFT)) & SPI_C1_CPHA_MASK)

#define SPI_C1_CPOL_MASK                         (0x8U)
#define SPI_C1_CPOL_SHIFT                        (3U)
/*! CPOL - Clock Polarity
 *  0b0..Active-high SPI clock (idles low)
 *  0b1..Active-low SPI clock (idles high)
 */
#define SPI_C1_CPOL(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_CPOL_SHIFT)) & SPI_C1_CPOL_MASK)

#define SPI_C1_MSTR_MASK                         (0x10U)
#define SPI_C1_MSTR_SHIFT                        (4U)
/*! MSTR - Master/Slave Mode Select
 *  0b0..SPI module configured as a slave SPI device
 *  0b1..SPI module configured as a master SPI device
 */
#define SPI_C1_MSTR(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_MSTR_SHIFT)) & SPI_C1_MSTR_MASK)

#define SPI_C1_SPTIE_MASK                        (0x20U)
#define SPI_C1_SPTIE_SHIFT                       (5U)
/*! SPTIE - SPI Transmit Interrupt Enable
 *  0b0..Interrupts from SPTEF inhibited (use polling)
 *  0b1..When SPTEF is 1, hardware interrupt requested
 */
#define SPI_C1_SPTIE(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_C1_SPTIE_SHIFT)) & SPI_C1_SPTIE_MASK)

#define SPI_C1_SPE_MASK                          (0x40U)
#define SPI_C1_SPE_SHIFT                         (6U)
/*! SPE - SPI System Enable
 *  0b0..SPI system inactive
 *  0b1..SPI system enabled
 */
#define SPI_C1_SPE(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_C1_SPE_SHIFT)) & SPI_C1_SPE_MASK)

#define SPI_C1_SPIE_MASK                         (0x80U)
#define SPI_C1_SPIE_SHIFT                        (7U)
/*! SPIE - SPI Interrupt Enable: for SPRF and MODF (when FIFO is not supported or not enabled) or
 *    for read FIFO (when FIFO is supported and enabled)
 *  0b0..Interrupts from SPRF and MODF are inhibited-use polling (when FIFOMODE is not present or is 0) or Read
 *       FIFO Full Interrupts are disabled (when FIFOMODE is 1)
 *  0b1..Request a hardware interrupt when SPRF or MODF is 1 (when FIFOMODE is not present or is 0) or Read FIFO
 *       Full Interrupts are enabled (when FIFOMODE is 1)
 */
#define SPI_C1_SPIE(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_SPIE_SHIFT)) & SPI_C1_SPIE_MASK)
/*! @} */

/*! @name ML - SPI Match Register low */
/*! @{ */

#define SPI_ML_Bits_MASK                         (0xFFU)
#define SPI_ML_Bits_SHIFT                        (0U)
/*! Bits - Hardware compare value (low byte) */
#define SPI_ML_Bits(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_ML_Bits_SHIFT)) & SPI_ML_Bits_MASK)
/*! @} */

/*! @name MH - SPI match register high */
/*! @{ */

#define SPI_MH_Bits_MASK                         (0xFFU)
#define SPI_MH_Bits_SHIFT                        (0U)
/*! Bits - Hardware compare value (high byte) */
#define SPI_MH_Bits(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_MH_Bits_SHIFT)) & SPI_MH_Bits_MASK)
/*! @} */

/*! @name DL - SPI Data Register low */
/*! @{ */

#define SPI_DL_Bits_MASK                         (0xFFU)
#define SPI_DL_Bits_SHIFT                        (0U)
/*! Bits - Data (low byte) */
#define SPI_DL_Bits(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_DL_Bits_SHIFT)) & SPI_DL_Bits_MASK)
/*! @} */

/*! @name DH - SPI data register high */
/*! @{ */

#define SPI_DH_Bits_MASK                         (0xFFU)
#define SPI_DH_Bits_SHIFT                        (0U)
/*! Bits - Data (high byte) */
#define SPI_DH_Bits(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_DH_Bits_SHIFT)) & SPI_DH_Bits_MASK)
/*! @} */

/*! @name CI - SPI clear interrupt register */
/*! @{ */

#define SPI_CI_SPRFCI_MASK                       (0x1U)
#define SPI_CI_SPRFCI_SHIFT                      (0U)
/*! SPRFCI - Receive FIFO full flag clear interrupt */
#define SPI_CI_SPRFCI(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_CI_SPRFCI_SHIFT)) & SPI_CI_SPRFCI_MASK)

#define SPI_CI_SPTEFCI_MASK                      (0x2U)
#define SPI_CI_SPTEFCI_SHIFT                     (1U)
/*! SPTEFCI - Transmit FIFO empty flag clear interrupt */
#define SPI_CI_SPTEFCI(x)                        (((uint8_t)(((uint8_t)(x)) << SPI_CI_SPTEFCI_SHIFT)) & SPI_CI_SPTEFCI_MASK)

#define SPI_CI_RNFULLFCI_MASK                    (0x4U)
#define SPI_CI_RNFULLFCI_SHIFT                   (2U)
/*! RNFULLFCI - Receive FIFO nearly full flag clear interrupt */
#define SPI_CI_RNFULLFCI(x)                      (((uint8_t)(((uint8_t)(x)) << SPI_CI_RNFULLFCI_SHIFT)) & SPI_CI_RNFULLFCI_MASK)

#define SPI_CI_TNEAREFCI_MASK                    (0x8U)
#define SPI_CI_TNEAREFCI_SHIFT                   (3U)
/*! TNEAREFCI - Transmit FIFO nearly empty flag clear interrupt */
#define SPI_CI_TNEAREFCI(x)                      (((uint8_t)(((uint8_t)(x)) << SPI_CI_TNEAREFCI_SHIFT)) & SPI_CI_TNEAREFCI_MASK)

#define SPI_CI_RXFOF_MASK                        (0x10U)
#define SPI_CI_RXFOF_SHIFT                       (4U)
/*! RXFOF - Receive FIFO overflow flag
 *  0b0..Receive FIFO overflow condition has not occurred
 *  0b1..Receive FIFO overflow condition occurred
 */
#define SPI_CI_RXFOF(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_CI_RXFOF_SHIFT)) & SPI_CI_RXFOF_MASK)

#define SPI_CI_TXFOF_MASK                        (0x20U)
#define SPI_CI_TXFOF_SHIFT                       (5U)
/*! TXFOF - Transmit FIFO overflow flag
 *  0b0..Transmit FIFO overflow condition has not occurred
 *  0b1..Transmit FIFO overflow condition occurred
 */
#define SPI_CI_TXFOF(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_CI_TXFOF_SHIFT)) & SPI_CI_TXFOF_MASK)

#define SPI_CI_RXFERR_MASK                       (0x40U)
#define SPI_CI_RXFERR_SHIFT                      (6U)
/*! RXFERR - Receive FIFO error flag
 *  0b0..No receive FIFO error occurred
 *  0b1..A receive FIFO error occurred
 */
#define SPI_CI_RXFERR(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_CI_RXFERR_SHIFT)) & SPI_CI_RXFERR_MASK)

#define SPI_CI_TXFERR_MASK                       (0x80U)
#define SPI_CI_TXFERR_SHIFT                      (7U)
/*! TXFERR - Transmit FIFO error flag
 *  0b0..No transmit FIFO error occurred
 *  0b1..A transmit FIFO error occurred
 */
#define SPI_CI_TXFERR(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_CI_TXFERR_SHIFT)) & SPI_CI_TXFERR_MASK)
/*! @} */

/*! @name C3 - SPI control register 3 */
/*! @{ */

#define SPI_C3_FIFOMODE_MASK                     (0x1U)
#define SPI_C3_FIFOMODE_SHIFT                    (0U)
/*! FIFOMODE - FIFO mode enable
 *  0b0..FIFO mode disabled
 *  0b1..FIFO mode enabled
 */
#define SPI_C3_FIFOMODE(x)                       (((uint8_t)(((uint8_t)(x)) << SPI_C3_FIFOMODE_SHIFT)) & SPI_C3_FIFOMODE_MASK)

#define SPI_C3_RNFULLIEN_MASK                    (0x2U)
#define SPI_C3_RNFULLIEN_SHIFT                   (1U)
/*! RNFULLIEN - Receive FIFO nearly full interrupt enable
 *  0b0..No interrupt upon RNFULLF being set
 *  0b1..Enable interrupts upon RNFULLF being set
 */
#define SPI_C3_RNFULLIEN(x)                      (((uint8_t)(((uint8_t)(x)) << SPI_C3_RNFULLIEN_SHIFT)) & SPI_C3_RNFULLIEN_MASK)

#define SPI_C3_TNEARIEN_MASK                     (0x4U)
#define SPI_C3_TNEARIEN_SHIFT                    (2U)
/*! TNEARIEN - Transmit FIFO nearly empty interrupt enable
 *  0b0..No interrupt upon TNEAREF being set
 *  0b1..Enable interrupts upon TNEAREF being set
 */
#define SPI_C3_TNEARIEN(x)                       (((uint8_t)(((uint8_t)(x)) << SPI_C3_TNEARIEN_SHIFT)) & SPI_C3_TNEARIEN_MASK)

#define SPI_C3_INTCLR_MASK                       (0x8U)
#define SPI_C3_INTCLR_SHIFT                      (3U)
/*! INTCLR - Interrupt clearing mechanism select
 *  0b0..These interrupts are cleared when the corresponding flags are cleared depending on the state of the FIFOs
 *  0b1..These interrupts are cleared by writing the corresponding bits in the CI register
 */
#define SPI_C3_INTCLR(x)                         (((uint8_t)(((uint8_t)(x)) << SPI_C3_INTCLR_SHIFT)) & SPI_C3_INTCLR_MASK)

#define SPI_C3_RNFULLF_MARK_MASK                 (0x10U)
#define SPI_C3_RNFULLF_MARK_SHIFT                (4U)
/*! RNFULLF_MARK - Receive FIFO nearly full watermark
 *  0b0..RNFULLF is set when the receive FIFO has 48 bits or more
 *  0b1..RNFULLF is set when the receive FIFO has 32 bits or more
 */
#define SPI_C3_RNFULLF_MARK(x)                   (((uint8_t)(((uint8_t)(x)) << SPI_C3_RNFULLF_MARK_SHIFT)) & SPI_C3_RNFULLF_MARK_MASK)

#define SPI_C3_TNEAREF_MARK_MASK                 (0x20U)
#define SPI_C3_TNEAREF_MARK_SHIFT                (5U)
/*! TNEAREF_MARK - Transmit FIFO nearly empty watermark
 *  0b0..TNEAREF is set when the transmit FIFO has 16 bits or less
 *  0b1..TNEAREF is set when the transmit FIFO has 32 bits or less
 */
#define SPI_C3_TNEAREF_MARK(x)                   (((uint8_t)(((uint8_t)(x)) << SPI_C3_TNEAREF_MARK_SHIFT)) & SPI_C3_TNEAREF_MARK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */


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


#endif  /* PERI_SPI_H_ */

