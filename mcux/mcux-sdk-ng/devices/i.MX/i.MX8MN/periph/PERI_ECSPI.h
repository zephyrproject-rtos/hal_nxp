/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ECSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ECSPI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ECSPI
 *
 * CMSIS Peripheral Access Layer for ECSPI
 */

#if !defined(PERI_ECSPI_H_)
#define PERI_ECSPI_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- ECSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECSPI_Peripheral_Access_Layer ECSPI Peripheral Access Layer
 * @{
 */

/** ECSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t RXDATA;                            /**< Receive Data Register, offset: 0x0 */
  __O  uint32_t TXDATA;                            /**< Transmit Data Register, offset: 0x4 */
  __IO uint32_t CONREG;                            /**< Control Register, offset: 0x8 */
  __IO uint32_t CONFIGREG;                         /**< Config Register, offset: 0xC */
  __IO uint32_t INTREG;                            /**< Interrupt Control Register, offset: 0x10 */
  __IO uint32_t DMAREG;                            /**< DMA Control Register, offset: 0x14 */
  __IO uint32_t STATREG;                           /**< Status Register, offset: 0x18 */
  __IO uint32_t PERIODREG;                         /**< Sample Period Control Register, offset: 0x1C */
  __IO uint32_t TESTREG;                           /**< Test Control Register, offset: 0x20 */
       uint8_t RESERVED_0[28];
  __O  uint32_t MSGDATA;                           /**< Message Data Register, offset: 0x40 */
} ECSPI_Type;

/* ----------------------------------------------------------------------------
   -- ECSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ECSPI_Register_Masks ECSPI Register Masks
 * @{
 */

/*! @name RXDATA - Receive Data Register */
/*! @{ */

#define ECSPI_RXDATA_ECSPI_RXDATA_MASK           (0xFFFFFFFFU)
#define ECSPI_RXDATA_ECSPI_RXDATA_SHIFT          (0U)
#define ECSPI_RXDATA_ECSPI_RXDATA(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_RXDATA_ECSPI_RXDATA_SHIFT)) & ECSPI_RXDATA_ECSPI_RXDATA_MASK)
/*! @} */

/*! @name TXDATA - Transmit Data Register */
/*! @{ */

#define ECSPI_TXDATA_ECSPI_TXDATA_MASK           (0xFFFFFFFFU)
#define ECSPI_TXDATA_ECSPI_TXDATA_SHIFT          (0U)
#define ECSPI_TXDATA_ECSPI_TXDATA(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_TXDATA_ECSPI_TXDATA_SHIFT)) & ECSPI_TXDATA_ECSPI_TXDATA_MASK)
/*! @} */

/*! @name CONREG - Control Register */
/*! @{ */

#define ECSPI_CONREG_EN_MASK                     (0x1U)
#define ECSPI_CONREG_EN_SHIFT                    (0U)
/*! EN
 *  0b0..Disable the block.
 *  0b1..Enable the block.
 */
#define ECSPI_CONREG_EN(x)                       (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_EN_SHIFT)) & ECSPI_CONREG_EN_MASK)

#define ECSPI_CONREG_HT_MASK                     (0x2U)
#define ECSPI_CONREG_HT_SHIFT                    (1U)
/*! HT
 *  0b0..Disable HT mode.
 *  0b1..Enable HT mode.
 */
#define ECSPI_CONREG_HT(x)                       (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_HT_SHIFT)) & ECSPI_CONREG_HT_MASK)

#define ECSPI_CONREG_XCH_MASK                    (0x4U)
#define ECSPI_CONREG_XCH_SHIFT                   (2U)
/*! XCH
 *  0b0..Idle.
 *  0b1..Initiates exchange (write) or busy (read).
 */
#define ECSPI_CONREG_XCH(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_XCH_SHIFT)) & ECSPI_CONREG_XCH_MASK)

#define ECSPI_CONREG_SMC_MASK                    (0x8U)
#define ECSPI_CONREG_SMC_SHIFT                   (3U)
/*! SMC
 *  0b0..SPI Exchange Bit (XCH) controls when a SPI burst can start. Setting the XCH bit will start a SPI burst or
 *       multiple bursts. This is controlled by the SPI SS Wave Form Select (SS_CTL). Refer to XCH and SS_CTL
 *       descriptions.
 *  0b1..Immediately starts a SPI burst when data is written in TXFIFO.
 */
#define ECSPI_CONREG_SMC(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_SMC_SHIFT)) & ECSPI_CONREG_SMC_MASK)

#define ECSPI_CONREG_CHANNEL_MODE_MASK           (0xF0U)
#define ECSPI_CONREG_CHANNEL_MODE_SHIFT          (4U)
/*! CHANNEL_MODE
 *  0b0000..Slave mode.
 *  0b0001..Master mode.
 */
#define ECSPI_CONREG_CHANNEL_MODE(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_CHANNEL_MODE_SHIFT)) & ECSPI_CONREG_CHANNEL_MODE_MASK)

#define ECSPI_CONREG_POST_DIVIDER_MASK           (0xF00U)
#define ECSPI_CONREG_POST_DIVIDER_SHIFT          (8U)
/*! POST_DIVIDER
 *  0b0000..Divide by 1.
 *  0b0001..Divide by 2.
 *  0b0010..Divide by 4.
 *  0b1110..Divide by 2 14 .
 *  0b1111..Divide by 2 15 .
 */
#define ECSPI_CONREG_POST_DIVIDER(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_POST_DIVIDER_SHIFT)) & ECSPI_CONREG_POST_DIVIDER_MASK)

#define ECSPI_CONREG_PRE_DIVIDER_MASK            (0xF000U)
#define ECSPI_CONREG_PRE_DIVIDER_SHIFT           (12U)
/*! PRE_DIVIDER
 *  0b0000..Divide by 1.
 *  0b0001..Divide by 2.
 *  0b0010..Divide by 3.
 *  0b1101..Divide by 14.
 *  0b1110..Divide by 15.
 *  0b1111..Divide by 16.
 */
#define ECSPI_CONREG_PRE_DIVIDER(x)              (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_PRE_DIVIDER_SHIFT)) & ECSPI_CONREG_PRE_DIVIDER_MASK)

#define ECSPI_CONREG_DRCTL_MASK                  (0x30000U)
#define ECSPI_CONREG_DRCTL_SHIFT                 (16U)
/*! DRCTL
 *  0b00..The SPI_RDY signal is a don't care.
 *  0b01..Burst will be triggered by the falling edge of the SPI_RDY signal (edge-triggered).
 *  0b10..Burst will be triggered by a low level of the SPI_RDY signal (level-triggered).
 *  0b11..Reserved.
 */
#define ECSPI_CONREG_DRCTL(x)                    (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_DRCTL_SHIFT)) & ECSPI_CONREG_DRCTL_MASK)

#define ECSPI_CONREG_CHANNEL_SELECT_MASK         (0xC0000U)
#define ECSPI_CONREG_CHANNEL_SELECT_SHIFT        (18U)
/*! CHANNEL_SELECT
 *  0b00..Channel 0 is selected. Chip Select 0 (SS0) will be asserted.
 *  0b01..Channel 1 is selected. Chip Select 1 (SS1) will be asserted.
 *  0b10..Channel 2 is selected. Chip Select 2 (SS2) will be asserted.
 *  0b11..Channel 3 is selected. Chip Select 3 (SS3) will be asserted.
 */
#define ECSPI_CONREG_CHANNEL_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_CHANNEL_SELECT_SHIFT)) & ECSPI_CONREG_CHANNEL_SELECT_MASK)

#define ECSPI_CONREG_BURST_LENGTH_MASK           (0xFFF00000U)
#define ECSPI_CONREG_BURST_LENGTH_SHIFT          (20U)
/*! BURST_LENGTH
 *  0b000000000000..A SPI burst contains the 1 LSB in a word.
 *  0b000000000001..A SPI burst contains the 2 LSB in a word.
 *  0b000000000010..A SPI burst contains the 3 LSB in a word.
 *  0b000000011111..A SPI burst contains all 32 bits in a word.
 *  0b000000100000..A SPI burst contains the 1 LSB in first word and all 32 bits in second word.
 *  0b000000100001..A SPI burst contains the 2 LSB in first word and all 32 bits in second word.
 *  0b111111111110..A SPI burst contains the 31 LSB in first word and 2^7 -1 words.
 *  0b111111111111..A SPI burst contains 2^7 words.
 */
#define ECSPI_CONREG_BURST_LENGTH(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_CONREG_BURST_LENGTH_SHIFT)) & ECSPI_CONREG_BURST_LENGTH_MASK)
/*! @} */

/*! @name CONFIGREG - Config Register */
/*! @{ */

#define ECSPI_CONFIGREG_SCLK_PHA_MASK            (0xFU)
#define ECSPI_CONFIGREG_SCLK_PHA_SHIFT           (0U)
/*! SCLK_PHA
 *  0b0000..Phase 0 operation.
 *  0b0001..Phase 1 operation.
 */
#define ECSPI_CONFIGREG_SCLK_PHA(x)              (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_SCLK_PHA_SHIFT)) & ECSPI_CONFIGREG_SCLK_PHA_MASK)

#define ECSPI_CONFIGREG_SCLK_POL_MASK            (0xF0U)
#define ECSPI_CONFIGREG_SCLK_POL_SHIFT           (4U)
/*! SCLK_POL
 *  0b0000..Active high polarity (0 = Idle).
 *  0b0001..Active low polarity (1 = Idle).
 */
#define ECSPI_CONFIGREG_SCLK_POL(x)              (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_SCLK_POL_SHIFT)) & ECSPI_CONFIGREG_SCLK_POL_MASK)

#define ECSPI_CONFIGREG_SS_CTL_MASK              (0xF00U)
#define ECSPI_CONFIGREG_SS_CTL_SHIFT             (8U)
/*! SS_CTL
 *  0b0000..In master mode - only one SPI burst will be transmitted.
 *  0b0000..In slave mode - an SPI burst is completed when the number of bits received in the shift register is
 *          equal to (BURST LENGTH + 1). Only the n least-significant bits (n = BURST LENGTH[4:0] + 1) of the first
 *          received word are valid. All bits subsequent to the first received word in RXFIFO are valid.
 *  0b0001..In master mode - Negate Chip Select (SS) signal between SPI bursts. Multiple SPI bursts will be
 *          transmitted. The SPI transfer will automatically stop when the TXFIFO is empty.
 *  0b0001..Reserved
 */
#define ECSPI_CONFIGREG_SS_CTL(x)                (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_SS_CTL_SHIFT)) & ECSPI_CONFIGREG_SS_CTL_MASK)

#define ECSPI_CONFIGREG_SS_POL_MASK              (0xF000U)
#define ECSPI_CONFIGREG_SS_POL_SHIFT             (12U)
/*! SS_POL
 *  0b0000..Active low.
 *  0b0001..Active high.
 */
#define ECSPI_CONFIGREG_SS_POL(x)                (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_SS_POL_SHIFT)) & ECSPI_CONFIGREG_SS_POL_MASK)

#define ECSPI_CONFIGREG_DATA_CTL_MASK            (0xF0000U)
#define ECSPI_CONFIGREG_DATA_CTL_SHIFT           (16U)
/*! DATA_CTL
 *  0b0000..Stay high.
 *  0b0001..Stay low.
 */
#define ECSPI_CONFIGREG_DATA_CTL(x)              (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_DATA_CTL_SHIFT)) & ECSPI_CONFIGREG_DATA_CTL_MASK)

#define ECSPI_CONFIGREG_SCLK_CTL_MASK            (0xF00000U)
#define ECSPI_CONFIGREG_SCLK_CTL_SHIFT           (20U)
/*! SCLK_CTL
 *  0b0000..Stay low.
 *  0b0001..Stay high.
 */
#define ECSPI_CONFIGREG_SCLK_CTL(x)              (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_SCLK_CTL_SHIFT)) & ECSPI_CONFIGREG_SCLK_CTL_MASK)

#define ECSPI_CONFIGREG_HT_LENGTH_MASK           (0x1F000000U)
#define ECSPI_CONFIGREG_HT_LENGTH_SHIFT          (24U)
#define ECSPI_CONFIGREG_HT_LENGTH(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_CONFIGREG_HT_LENGTH_SHIFT)) & ECSPI_CONFIGREG_HT_LENGTH_MASK)
/*! @} */

/*! @name INTREG - Interrupt Control Register */
/*! @{ */

#define ECSPI_INTREG_TEEN_MASK                   (0x1U)
#define ECSPI_INTREG_TEEN_SHIFT                  (0U)
/*! TEEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_TEEN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_TEEN_SHIFT)) & ECSPI_INTREG_TEEN_MASK)

#define ECSPI_INTREG_TDREN_MASK                  (0x2U)
#define ECSPI_INTREG_TDREN_SHIFT                 (1U)
/*! TDREN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_TDREN(x)                    (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_TDREN_SHIFT)) & ECSPI_INTREG_TDREN_MASK)

#define ECSPI_INTREG_TFEN_MASK                   (0x4U)
#define ECSPI_INTREG_TFEN_SHIFT                  (2U)
/*! TFEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_TFEN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_TFEN_SHIFT)) & ECSPI_INTREG_TFEN_MASK)

#define ECSPI_INTREG_RREN_MASK                   (0x8U)
#define ECSPI_INTREG_RREN_SHIFT                  (3U)
/*! RREN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_RREN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_RREN_SHIFT)) & ECSPI_INTREG_RREN_MASK)

#define ECSPI_INTREG_RDREN_MASK                  (0x10U)
#define ECSPI_INTREG_RDREN_SHIFT                 (4U)
/*! RDREN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_RDREN(x)                    (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_RDREN_SHIFT)) & ECSPI_INTREG_RDREN_MASK)

#define ECSPI_INTREG_RFEN_MASK                   (0x20U)
#define ECSPI_INTREG_RFEN_SHIFT                  (5U)
/*! RFEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_RFEN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_RFEN_SHIFT)) & ECSPI_INTREG_RFEN_MASK)

#define ECSPI_INTREG_ROEN_MASK                   (0x40U)
#define ECSPI_INTREG_ROEN_SHIFT                  (6U)
/*! ROEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_ROEN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_ROEN_SHIFT)) & ECSPI_INTREG_ROEN_MASK)

#define ECSPI_INTREG_TCEN_MASK                   (0x80U)
#define ECSPI_INTREG_TCEN_SHIFT                  (7U)
/*! TCEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_INTREG_TCEN(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_INTREG_TCEN_SHIFT)) & ECSPI_INTREG_TCEN_MASK)
/*! @} */

/*! @name DMAREG - DMA Control Register */
/*! @{ */

#define ECSPI_DMAREG_TX_THRESHOLD_MASK           (0x3FU)
#define ECSPI_DMAREG_TX_THRESHOLD_SHIFT          (0U)
#define ECSPI_DMAREG_TX_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_TX_THRESHOLD_SHIFT)) & ECSPI_DMAREG_TX_THRESHOLD_MASK)

#define ECSPI_DMAREG_TEDEN_MASK                  (0x80U)
#define ECSPI_DMAREG_TEDEN_SHIFT                 (7U)
/*! TEDEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_DMAREG_TEDEN(x)                    (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_TEDEN_SHIFT)) & ECSPI_DMAREG_TEDEN_MASK)

#define ECSPI_DMAREG_RX_THRESHOLD_MASK           (0x3F0000U)
#define ECSPI_DMAREG_RX_THRESHOLD_SHIFT          (16U)
#define ECSPI_DMAREG_RX_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_RX_THRESHOLD_SHIFT)) & ECSPI_DMAREG_RX_THRESHOLD_MASK)

#define ECSPI_DMAREG_RXDEN_MASK                  (0x800000U)
#define ECSPI_DMAREG_RXDEN_SHIFT                 (23U)
/*! RXDEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_DMAREG_RXDEN(x)                    (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_RXDEN_SHIFT)) & ECSPI_DMAREG_RXDEN_MASK)

#define ECSPI_DMAREG_RX_DMA_LENGTH_MASK          (0x3F000000U)
#define ECSPI_DMAREG_RX_DMA_LENGTH_SHIFT         (24U)
#define ECSPI_DMAREG_RX_DMA_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_RX_DMA_LENGTH_SHIFT)) & ECSPI_DMAREG_RX_DMA_LENGTH_MASK)

#define ECSPI_DMAREG_RXTDEN_MASK                 (0x80000000U)
#define ECSPI_DMAREG_RXTDEN_SHIFT                (31U)
/*! RXTDEN
 *  0b0..Disable
 *  0b1..Enable
 */
#define ECSPI_DMAREG_RXTDEN(x)                   (((uint32_t)(((uint32_t)(x)) << ECSPI_DMAREG_RXTDEN_SHIFT)) & ECSPI_DMAREG_RXTDEN_MASK)
/*! @} */

/*! @name STATREG - Status Register */
/*! @{ */

#define ECSPI_STATREG_TE_MASK                    (0x1U)
#define ECSPI_STATREG_TE_SHIFT                   (0U)
/*! TE
 *  0b0..TXFIFO contains one or more words.
 *  0b1..TXFIFO is empty.
 */
#define ECSPI_STATREG_TE(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_TE_SHIFT)) & ECSPI_STATREG_TE_MASK)

#define ECSPI_STATREG_TDR_MASK                   (0x2U)
#define ECSPI_STATREG_TDR_SHIFT                  (1U)
/*! TDR
 *  0b0..Number of valid data slots in TXFIFO is greater than TX_THRESHOLD.
 *  0b1..Number of valid data slots in TXFIFO is not greater than TX_THRESHOLD.
 */
#define ECSPI_STATREG_TDR(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_TDR_SHIFT)) & ECSPI_STATREG_TDR_MASK)

#define ECSPI_STATREG_TF_MASK                    (0x4U)
#define ECSPI_STATREG_TF_SHIFT                   (2U)
/*! TF
 *  0b0..TXFIFO is not Full.
 *  0b1..TXFIFO is Full.
 */
#define ECSPI_STATREG_TF(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_TF_SHIFT)) & ECSPI_STATREG_TF_MASK)

#define ECSPI_STATREG_RR_MASK                    (0x8U)
#define ECSPI_STATREG_RR_SHIFT                   (3U)
/*! RR
 *  0b0..No valid data in RXFIFO.
 *  0b1..More than 1 word in RXFIFO.
 */
#define ECSPI_STATREG_RR(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_RR_SHIFT)) & ECSPI_STATREG_RR_MASK)

#define ECSPI_STATREG_RDR_MASK                   (0x10U)
#define ECSPI_STATREG_RDR_SHIFT                  (4U)
/*! RDR
 *  0b0..When RXTDE is clear - Number of data entries in the RXFIFO is not greater than RX_THRESHOLD.
 *  0b0..When RXTDE is set - Number of data entries in the RXFIFO is not greater than RX_THRESHOLD.
 *  0b1..When RXTDE is clear - Number of data entries in the RXFIFO is greater than RX_THRESHOLD.
 *  0b1..When RXTDE is set - Number of data entries in the RXFIFO is greater than RX_THRESHOLD or a DMA TAIL DMA condition exists.
 */
#define ECSPI_STATREG_RDR(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_RDR_SHIFT)) & ECSPI_STATREG_RDR_MASK)

#define ECSPI_STATREG_RF_MASK                    (0x20U)
#define ECSPI_STATREG_RF_SHIFT                   (5U)
/*! RF
 *  0b0..Not Full.
 *  0b1..Full.
 */
#define ECSPI_STATREG_RF(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_RF_SHIFT)) & ECSPI_STATREG_RF_MASK)

#define ECSPI_STATREG_RO_MASK                    (0x40U)
#define ECSPI_STATREG_RO_SHIFT                   (6U)
/*! RO
 *  0b0..RXFIFO has no overflow.
 *  0b1..RXFIFO has overflowed.
 */
#define ECSPI_STATREG_RO(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_RO_SHIFT)) & ECSPI_STATREG_RO_MASK)

#define ECSPI_STATREG_TC_MASK                    (0x80U)
#define ECSPI_STATREG_TC_SHIFT                   (7U)
/*! TC
 *  0b0..Transfer in progress.
 *  0b1..Transfer completed.
 */
#define ECSPI_STATREG_TC(x)                      (((uint32_t)(((uint32_t)(x)) << ECSPI_STATREG_TC_SHIFT)) & ECSPI_STATREG_TC_MASK)
/*! @} */

/*! @name PERIODREG - Sample Period Control Register */
/*! @{ */

#define ECSPI_PERIODREG_SAMPLE_PERIOD_MASK       (0x7FFFU)
#define ECSPI_PERIODREG_SAMPLE_PERIOD_SHIFT      (0U)
/*! SAMPLE_PERIOD
 *  0b000000000000000..0 wait states inserted
 *  0b000000000000001..1 wait state inserted
 *  0b111111111111110..32766 wait states inserted
 *  0b111111111111111..32767 wait states inserted
 */
#define ECSPI_PERIODREG_SAMPLE_PERIOD(x)         (((uint32_t)(((uint32_t)(x)) << ECSPI_PERIODREG_SAMPLE_PERIOD_SHIFT)) & ECSPI_PERIODREG_SAMPLE_PERIOD_MASK)

#define ECSPI_PERIODREG_CSRC_MASK                (0x8000U)
#define ECSPI_PERIODREG_CSRC_SHIFT               (15U)
/*! CSRC
 *  0b0..SPI Clock (SCLK)
 *  0b1..Low-Frequency Reference Clock (32.768 KHz)
 */
#define ECSPI_PERIODREG_CSRC(x)                  (((uint32_t)(((uint32_t)(x)) << ECSPI_PERIODREG_CSRC_SHIFT)) & ECSPI_PERIODREG_CSRC_MASK)

#define ECSPI_PERIODREG_CSD_CTL_MASK             (0x3F0000U)
#define ECSPI_PERIODREG_CSD_CTL_SHIFT            (16U)
#define ECSPI_PERIODREG_CSD_CTL(x)               (((uint32_t)(((uint32_t)(x)) << ECSPI_PERIODREG_CSD_CTL_SHIFT)) & ECSPI_PERIODREG_CSD_CTL_MASK)
/*! @} */

/*! @name TESTREG - Test Control Register */
/*! @{ */

#define ECSPI_TESTREG_TXCNT_MASK                 (0x7FU)
#define ECSPI_TESTREG_TXCNT_SHIFT                (0U)
#define ECSPI_TESTREG_TXCNT(x)                   (((uint32_t)(((uint32_t)(x)) << ECSPI_TESTREG_TXCNT_SHIFT)) & ECSPI_TESTREG_TXCNT_MASK)

#define ECSPI_TESTREG_RXCNT_MASK                 (0x7F00U)
#define ECSPI_TESTREG_RXCNT_SHIFT                (8U)
#define ECSPI_TESTREG_RXCNT(x)                   (((uint32_t)(((uint32_t)(x)) << ECSPI_TESTREG_RXCNT_SHIFT)) & ECSPI_TESTREG_RXCNT_MASK)

#define ECSPI_TESTREG_LBC_MASK                   (0x80000000U)
#define ECSPI_TESTREG_LBC_SHIFT                  (31U)
/*! LBC
 *  0b0..Not connected.
 *  0b1..Transmitter and receiver sections internally connected for Loopback.
 */
#define ECSPI_TESTREG_LBC(x)                     (((uint32_t)(((uint32_t)(x)) << ECSPI_TESTREG_LBC_SHIFT)) & ECSPI_TESTREG_LBC_MASK)
/*! @} */

/*! @name MSGDATA - Message Data Register */
/*! @{ */

#define ECSPI_MSGDATA_ECSPI_MSGDATA_MASK         (0xFFFFFFFFU)
#define ECSPI_MSGDATA_ECSPI_MSGDATA_SHIFT        (0U)
#define ECSPI_MSGDATA_ECSPI_MSGDATA(x)           (((uint32_t)(((uint32_t)(x)) << ECSPI_MSGDATA_ECSPI_MSGDATA_SHIFT)) & ECSPI_MSGDATA_ECSPI_MSGDATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ECSPI_Register_Masks */


/*!
 * @}
 */ /* end of group ECSPI_Peripheral_Access_Layer */


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


#endif  /* PERI_ECSPI_H_ */

