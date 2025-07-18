/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
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
**     - rev. 1.0 (2017-05-19)
**         Initial version.
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

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
  __IO uint8_t C1;                                 /**< SPI Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< SPI Control Register 2, offset: 0x1 */
  __IO uint8_t BR;                                 /**< SPI Baud Rate Register, offset: 0x2 */
  __IO uint8_t S;                                  /**< SPI Status Register, offset: 0x3 */
       uint8_t RESERVED_0[1];
  __IO uint8_t D;                                  /**< SPI Data Register, offset: 0x5 */
       uint8_t RESERVED_1[1];
  __IO uint8_t M;                                  /**< SPI Match Register, offset: 0x7 */
} SPI_Type;

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

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
/*! SPIE - SPI Interrupt Enable: for SPRF and MODF
 *  0b0..Interrupts from SPRF and MODF are inhibited-use polling
 *  0b1..Request a hardware interrupt when SPRF or MODF is 1
 */
#define SPI_C1_SPIE(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_C1_SPIE_SHIFT)) & SPI_C1_SPIE_MASK)
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

#define SPI_C2_SPMIE_MASK                        (0x80U)
#define SPI_C2_SPMIE_SHIFT                       (7U)
/*! SPMIE - SPI Match Interrupt Enable
 *  0b0..Interrupts from SPMF inhibited (use polling)
 *  0b1..When SPMF is 1, requests a hardware interrupt
 */
#define SPI_C2_SPMIE(x)                          (((uint8_t)(((uint8_t)(x)) << SPI_C2_SPMIE_SHIFT)) & SPI_C2_SPMIE_MASK)
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

/*! @name S - SPI Status Register */
/*! @{ */

#define SPI_S_MODF_MASK                          (0x10U)
#define SPI_S_MODF_SHIFT                         (4U)
/*! MODF - Master Mode Fault Flag
 *  0b0..No mode fault error
 *  0b1..Mode fault error detected
 */
#define SPI_S_MODF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_MODF_SHIFT)) & SPI_S_MODF_MASK)

#define SPI_S_SPTEF_MASK                         (0x20U)
#define SPI_S_SPTEF_SHIFT                        (5U)
/*! SPTEF - SPI Transmit Buffer Empty Flag
 *  0b0..SPI transmit buffer not empty
 *  0b1..SPI transmit buffer empty
 */
#define SPI_S_SPTEF(x)                           (((uint8_t)(((uint8_t)(x)) << SPI_S_SPTEF_SHIFT)) & SPI_S_SPTEF_MASK)

#define SPI_S_SPMF_MASK                          (0x40U)
#define SPI_S_SPMF_SHIFT                         (6U)
/*! SPMF - SPI Match Flag
 *  0b0..Value in the receive data buffer does not match the value in the M register
 *  0b1..Value in the receive data buffer matches the value in the M register
 */
#define SPI_S_SPMF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_SPMF_SHIFT)) & SPI_S_SPMF_MASK)

#define SPI_S_SPRF_MASK                          (0x80U)
#define SPI_S_SPRF_SHIFT                         (7U)
/*! SPRF - SPI Read Buffer Full Flag
 *  0b0..No data available in the receive data buffer
 *  0b1..Data available in the receive data buffer
 */
#define SPI_S_SPRF(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_S_SPRF_SHIFT)) & SPI_S_SPRF_MASK)
/*! @} */

/*! @name D - SPI Data Register */
/*! @{ */

#define SPI_D_Bits_MASK                          (0xFFU)
#define SPI_D_Bits_SHIFT                         (0U)
/*! Bits - Data (low byte) */
#define SPI_D_Bits(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_D_Bits_SHIFT)) & SPI_D_Bits_MASK)
/*! @} */

/*! @name M - SPI Match Register */
/*! @{ */

#define SPI_M_Bits_MASK                          (0xFFU)
#define SPI_M_Bits_SHIFT                         (0U)
/*! Bits - Hardware compare value (low byte) */
#define SPI_M_Bits(x)                            (((uint8_t)(((uint8_t)(x)) << SPI_M_Bits_SHIFT)) & SPI_M_Bits_MASK)
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

