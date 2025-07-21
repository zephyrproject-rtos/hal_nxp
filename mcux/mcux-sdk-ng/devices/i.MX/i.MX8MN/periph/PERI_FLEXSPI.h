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
**         CMSIS Peripheral Access Layer for FlexSPI
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
 * @file PERI_FLEXSPI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FlexSPI
 *
 * CMSIS Peripheral Access Layer for FlexSPI
 */

#if !defined(PERI_FLEXSPI_H_)
#define PERI_FLEXSPI_H_                          /**< Symbol preventing repeated inclusion */

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
   -- FlexSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FlexSPI_Peripheral_Access_Layer FlexSPI Peripheral Access Layer
 * @{
 */

/** FlexSPI - Size of Registers Arrays */
#define FlexSPI_AHBRXBUFXCR0_COUNT                8u
#define FlexSPI_FLSHXCR0_COUNT                    4u
#define FlexSPI_FLSHXCR1_COUNT                    4u
#define FlexSPI_FLSHXCR2_COUNT                    4u
#define FlexSPI_DLLXCR_COUNT                      2u
#define FlexSPI_RFDR_COUNT                        32u
#define FlexSPI_TFDR_COUNT                        32u
#define FlexSPI_LUT_COUNT                         128u

/** FlexSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR0;                              /**< Module Control Register 0, offset: 0x0 */
  __IO uint32_t MCR1;                              /**< Module Control Register 1, offset: 0x4 */
  __IO uint32_t MCR2;                              /**< Module Control Register 2, offset: 0x8 */
  __IO uint32_t AHBCR;                             /**< AHB Bus Control Register, offset: 0xC */
  __IO uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t INTR;                              /**< Interrupt Register, offset: 0x14 */
  __IO uint32_t LUTKEY;                            /**< LUT Key Register, offset: 0x18 */
  __IO uint32_t LUTCR;                             /**< LUT Control Register, offset: 0x1C */
  __IO uint32_t AHBRXBUFCR0[FlexSPI_AHBRXBUFXCR0_COUNT]; /**< AHB RX Buffer 0 Control Register 0..AHB RX Buffer 7 Control Register 0, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[32];
  __IO uint32_t FLSHCR0[FlexSPI_FLSHXCR0_COUNT];   /**< Flash Control Register 0, array offset: 0x60, array step: 0x4 */
  __IO uint32_t FLSHCR1[FlexSPI_FLSHXCR1_COUNT];   /**< Flash Control Register 1, array offset: 0x70, array step: 0x4 */
  __IO uint32_t FLSHCR2[FlexSPI_FLSHXCR2_COUNT];   /**< Flash Control Register 2, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[4];
  __IO uint32_t FLSHCR4;                           /**< Flash Control Register 4, offset: 0x94 */
       uint8_t RESERVED_2[8];
  __IO uint32_t IPCR0;                             /**< IP Control Register 0, offset: 0xA0 */
  __IO uint32_t IPCR1;                             /**< IP Control Register 1, offset: 0xA4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t IPCMD;                             /**< IP Command Register, offset: 0xB0 */
  __IO uint32_t DLPR;                              /**< Data Learn Pattern Register, offset: 0xB4 */
  __IO uint32_t IPRXFCR;                           /**< IP RX FIFO Control Register, offset: 0xB8 */
  __IO uint32_t IPTXFCR;                           /**< IP TX FIFO Control Register, offset: 0xBC */
  __IO uint32_t DLLCR[FlexSPI_DLLXCR_COUNT];       /**< DLL Control Register 0, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __I  uint32_t STS0;                              /**< Status Register 0, offset: 0xE0 */
  __I  uint32_t STS1;                              /**< Status Register 1, offset: 0xE4 */
  __I  uint32_t STS2;                              /**< Status Register 2, offset: 0xE8 */
  __I  uint32_t AHBSPNDSTS;                        /**< AHB Suspend Status Register, offset: 0xEC */
  __I  uint32_t IPRXFSTS;                          /**< IP RX FIFO Status Register, offset: 0xF0 */
  __I  uint32_t IPTXFSTS;                          /**< IP TX FIFO Status Register, offset: 0xF4 */
       uint8_t RESERVED_5[8];
  __I  uint32_t RFDR[FlexSPI_RFDR_COUNT];          /**< IP RX FIFO Data Register 0..IP RX FIFO Data Register 31, array offset: 0x100, array step: 0x4 */
  __O  uint32_t TFDR[FlexSPI_TFDR_COUNT];          /**< IP TX FIFO Data Register 0..IP TX FIFO Data Register 31, array offset: 0x180, array step: 0x4 */
  __IO uint32_t LUT[FlexSPI_LUT_COUNT];            /**< LUT 0..LUT 127, array offset: 0x200, array step: 0x4 */
} FlexSPI_Type;

/* ----------------------------------------------------------------------------
   -- FlexSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FlexSPI_Register_Masks FlexSPI Register Masks
 * @{
 */

/*! @name MCR0 - Module Control Register 0 */
/*! @{ */

#define FlexSPI_MCR0_SWRESET_MASK                (0x1U)
#define FlexSPI_MCR0_SWRESET_SHIFT               (0U)
/*! SWRESET - Software Reset */
#define FlexSPI_MCR0_SWRESET(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_SWRESET_SHIFT)) & FlexSPI_MCR0_SWRESET_MASK)

#define FlexSPI_MCR0_MDIS_MASK                   (0x2U)
#define FlexSPI_MCR0_MDIS_SHIFT                  (1U)
/*! MDIS - Module Disable */
#define FlexSPI_MCR0_MDIS(x)                     (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_MDIS_SHIFT)) & FlexSPI_MCR0_MDIS_MASK)

#define FlexSPI_MCR0_RXCLKSRC_MASK               (0x30U)
#define FlexSPI_MCR0_RXCLKSRC_SHIFT              (4U)
/*! RXCLKSRC - Sample Clock source selection for Flash Reading
 *  0b00..Dummy Read strobe generated by FlexSPI Controller and loopback internally.
 *  0b01..Dummy Read strobe generated by FlexSPI Controller and loopback from DQS pad.
 *  0b10..Reserved
 *  0b11..Flash provided Read strobe and input from DQS pad
 */
#define FlexSPI_MCR0_RXCLKSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_RXCLKSRC_SHIFT)) & FlexSPI_MCR0_RXCLKSRC_MASK)

#define FlexSPI_MCR0_ARDFEN_MASK                 (0x40U)
#define FlexSPI_MCR0_ARDFEN_SHIFT                (6U)
/*! ARDFEN - Enable AHB bus Read Access to IP RX FIFO.
 *  0b0..IP RX FIFO should be read by IP Bus. AHB Bus read access to IP RX FIFO memory space will get bus error response.
 *  0b1..IP RX FIFO should be read by AHB Bus. IP Bus read access to IP RX FIFO memory space will always return data zero but no bus error response.
 */
#define FlexSPI_MCR0_ARDFEN(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_ARDFEN_SHIFT)) & FlexSPI_MCR0_ARDFEN_MASK)

#define FlexSPI_MCR0_ATDFEN_MASK                 (0x80U)
#define FlexSPI_MCR0_ATDFEN_SHIFT                (7U)
/*! ATDFEN - Enable AHB bus Write Access to IP TX FIFO.
 *  0b0..IP TX FIFO should be written by IP Bus. AHB Bus write access to IP TX FIFO memory space will get bus error response.
 *  0b1..IP TX FIFO should be written by AHB Bus. IP Bus write access to IP TX FIFO memory space will be ignored but no bus error response.
 */
#define FlexSPI_MCR0_ATDFEN(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_ATDFEN_SHIFT)) & FlexSPI_MCR0_ATDFEN_MASK)

#define FlexSPI_MCR0_SERCLKDIV_MASK              (0x700U)
#define FlexSPI_MCR0_SERCLKDIV_SHIFT             (8U)
/*! SERCLKDIV - The serial root clock could be divided inside FlexSPI . Refer Clocks chapter for more details on clocking.
 *  0b000..Divided by 1
 *  0b001..Divided by 2
 *  0b010..Divided by 3
 *  0b011..Divided by 4
 *  0b100..Divided by 5
 *  0b101..Divided by 6
 *  0b110..Divided by 7
 *  0b111..Divided by 8
 */
#define FlexSPI_MCR0_SERCLKDIV(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_SERCLKDIV_SHIFT)) & FlexSPI_MCR0_SERCLKDIV_MASK)

#define FlexSPI_MCR0_HSEN_MASK                   (0x800U)
#define FlexSPI_MCR0_HSEN_SHIFT                  (11U)
/*! HSEN - Half Speed Serial Flash access Enable.
 *  0b0..Disable divide by 2 of serial flash clock for half speed commands.
 *  0b1..Enable divide by 2 of serial flash clock for half speed commands.
 */
#define FlexSPI_MCR0_HSEN(x)                     (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_HSEN_SHIFT)) & FlexSPI_MCR0_HSEN_MASK)

#define FlexSPI_MCR0_DOZEEN_MASK                 (0x1000U)
#define FlexSPI_MCR0_DOZEEN_SHIFT                (12U)
/*! DOZEEN - Doze mode enable bit
 *  0b0..Doze mode support disabled. AHB clock and serial clock will not be gated off when there is doze mode request from system.
 *  0b1..Doze mode support enabled. AHB clock and serial clock will be gated off when there is doze mode request from system.
 */
#define FlexSPI_MCR0_DOZEEN(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_DOZEEN_SHIFT)) & FlexSPI_MCR0_DOZEEN_MASK)

#define FlexSPI_MCR0_COMBINATIONEN_MASK          (0x2000U)
#define FlexSPI_MCR0_COMBINATIONEN_SHIFT         (13U)
/*! COMBINATIONEN - This bit is to support Flash Octal mode access by combining Port A and B Data pins (A_DATA[3:0] and B_DATA[3:0]).
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define FlexSPI_MCR0_COMBINATIONEN(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_COMBINATIONEN_SHIFT)) & FlexSPI_MCR0_COMBINATIONEN_MASK)

#define FlexSPI_MCR0_SCKFREERUNEN_MASK           (0x4000U)
#define FlexSPI_MCR0_SCKFREERUNEN_SHIFT          (14U)
/*! SCKFREERUNEN - This bit is used to force SCLK output free-running. For FPGA applications,
 *    external device may use SCLK as reference clock to its internal PLL. If SCLK free-running is
 *    enabled, data sampling with loopback clock from SCLK pad is not supported (MCR0[RXCLKSRC]=2).
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define FlexSPI_MCR0_SCKFREERUNEN(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_SCKFREERUNEN_SHIFT)) & FlexSPI_MCR0_SCKFREERUNEN_MASK)

#define FlexSPI_MCR0_LEARNEN_MASK                (0x8000U)
#define FlexSPI_MCR0_LEARNEN_SHIFT               (15U)
/*! LEARNEN - This bit is used to enable/disable data learning feature. When data learning is
 *    disabled, the sampling clock phase 0 is always used for RX data sampling even if LEARN instruction
 *    is correctly executed.
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define FlexSPI_MCR0_LEARNEN(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_LEARNEN_SHIFT)) & FlexSPI_MCR0_LEARNEN_MASK)

#define FlexSPI_MCR0_IPGRANTWAIT_MASK            (0xFF0000U)
#define FlexSPI_MCR0_IPGRANTWAIT_SHIFT           (16U)
/*! IPGRANTWAIT - Time out wait cycle for IP command grant. */
#define FlexSPI_MCR0_IPGRANTWAIT(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_IPGRANTWAIT_SHIFT)) & FlexSPI_MCR0_IPGRANTWAIT_MASK)

#define FlexSPI_MCR0_AHBGRANTWAIT_MASK           (0xFF000000U)
#define FlexSPI_MCR0_AHBGRANTWAIT_SHIFT          (24U)
/*! AHBGRANTWAIT - Timeout wait cycle for AHB command grant. */
#define FlexSPI_MCR0_AHBGRANTWAIT(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR0_AHBGRANTWAIT_SHIFT)) & FlexSPI_MCR0_AHBGRANTWAIT_MASK)
/*! @} */

/*! @name MCR1 - Module Control Register 1 */
/*! @{ */

#define FlexSPI_MCR1_AHBBUSWAIT_MASK             (0xFFFFU)
#define FlexSPI_MCR1_AHBBUSWAIT_SHIFT            (0U)
#define FlexSPI_MCR1_AHBBUSWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR1_AHBBUSWAIT_SHIFT)) & FlexSPI_MCR1_AHBBUSWAIT_MASK)

#define FlexSPI_MCR1_SEQWAIT_MASK                (0xFFFF0000U)
#define FlexSPI_MCR1_SEQWAIT_SHIFT               (16U)
#define FlexSPI_MCR1_SEQWAIT(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR1_SEQWAIT_SHIFT)) & FlexSPI_MCR1_SEQWAIT_MASK)
/*! @} */

/*! @name MCR2 - Module Control Register 2 */
/*! @{ */

#define FlexSPI_MCR2_CLRAHBBUFOPT_MASK           (0x800U)
#define FlexSPI_MCR2_CLRAHBBUFOPT_SHIFT          (11U)
/*! CLRAHBBUFOPT - This bit determines whether AHB RX Buffer and AHB TX Buffer will be cleaned
 *    automatically when FlexSPI returns STOP mode ACK. Software should set this bit if AHB RX Buffer or
 *    AHB TX Buffer will be powered off in STOP mode. Otherwise AHB read access after exiting STOP
 *    mode may hit AHB RX Buffer or AHB TX Buffer but their data entries are invalid.
 *  0b0..AHB RX/TX Buffer will not be cleaned automatically when FlexSPI return Stop mode ACK.
 *  0b1..AHB RX/TX Buffer will be cleaned automatically when FlexSPI return Stop mode ACK.
 */
#define FlexSPI_MCR2_CLRAHBBUFOPT(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR2_CLRAHBBUFOPT_SHIFT)) & FlexSPI_MCR2_CLRAHBBUFOPT_MASK)

#define FlexSPI_MCR2_CLRLEARNPHASE_MASK          (0x4000U)
#define FlexSPI_MCR2_CLRLEARNPHASE_SHIFT         (14U)
/*! CLRLEARNPHASE - The sampling clock phase selection will be reset to phase 0 when this bit is
 *    written with 0x1. This bit will be auto-cleared immediately.
 */
#define FlexSPI_MCR2_CLRLEARNPHASE(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR2_CLRLEARNPHASE_SHIFT)) & FlexSPI_MCR2_CLRLEARNPHASE_MASK)

#define FlexSPI_MCR2_SAMEDEVICEEN_MASK           (0x8000U)
#define FlexSPI_MCR2_SAMEDEVICEEN_SHIFT          (15U)
/*! SAMEDEVICEEN - All external devices are same devices (both in types and size) for A1/A2/B1/B2.
 *  0b0..In Individual mode, FLSHA1CRx/FLSHA2CRx/FLSHB1CRx/FLSHB2CRx register setting will be applied to Flash
 *       A1/A2/B1/B2 separately. In Parallel mode, FLSHA1CRx register setting will be applied to Flash A1 and B1,
 *       FLSHA2CRx register setting will be applied to Flash A2 and B2. FLSHB1CRx/FLSHB2CRx register settings will be
 *       ignored.
 *  0b1..FLSHA1CR0/FLSHA1CR1/FLSHA1CR2 register settings will be applied to Flash A1/A2/B1/B2. FLSHA2CRx/FLSHB1CRx/FLSHB2CRx will be ignored.
 */
#define FlexSPI_MCR2_SAMEDEVICEEN(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR2_SAMEDEVICEEN_SHIFT)) & FlexSPI_MCR2_SAMEDEVICEEN_MASK)

#define FlexSPI_MCR2_SCKBDIFFOPT_MASK            (0x80000U)
#define FlexSPI_MCR2_SCKBDIFFOPT_SHIFT           (19U)
/*! SCKBDIFFOPT - B_SCLK pad can be used as A_SCLK differential clock output (inverted clock to
 *    A_SCLK). In this case, port B flash access is not available. After changing the value of this
 *    field, MCR0[SWRESET] should be set.
 *  0b1..B_SCLK pad is used as port A SCLK inverted clock output (Differential clock to A_SCLK). Port B flash access is not available.
 *  0b0..B_SCLK pad is used as port B SCLK clock output. Port B flash access is available.
 */
#define FlexSPI_MCR2_SCKBDIFFOPT(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR2_SCKBDIFFOPT_SHIFT)) & FlexSPI_MCR2_SCKBDIFFOPT_MASK)

#define FlexSPI_MCR2_RESUMEWAIT_MASK             (0xFF000000U)
#define FlexSPI_MCR2_RESUMEWAIT_SHIFT            (24U)
/*! RESUMEWAIT - Wait cycle (in AHB clock cycle) for idle state before suspended command sequence resumed. */
#define FlexSPI_MCR2_RESUMEWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_MCR2_RESUMEWAIT_SHIFT)) & FlexSPI_MCR2_RESUMEWAIT_MASK)
/*! @} */

/*! @name AHBCR - AHB Bus Control Register */
/*! @{ */

#define FlexSPI_AHBCR_APAREN_MASK                (0x1U)
#define FlexSPI_AHBCR_APAREN_SHIFT               (0U)
/*! APAREN - Parallel mode enabled for AHB triggered Command (both read and write) .
 *  0b0..Flash will be accessed in Individual mode.
 *  0b1..Flash will be accessed in Parallel mode.
 */
#define FlexSPI_AHBCR_APAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBCR_APAREN_SHIFT)) & FlexSPI_AHBCR_APAREN_MASK)

#define FlexSPI_AHBCR_CACHABLEEN_MASK            (0x8U)
#define FlexSPI_AHBCR_CACHABLEEN_SHIFT           (3U)
/*! CACHABLEEN - Enable AHB bus cachable read access support.
 *  0b0..Disabled. When there is AHB bus cachable read access, FlexSPI will not check whether it hit AHB TX Buffer.
 *  0b1..Enabled. When there is AHB bus cachable read access, FlexSPI will check whether it hit AHB TX Buffer first.
 */
#define FlexSPI_AHBCR_CACHABLEEN(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBCR_CACHABLEEN_SHIFT)) & FlexSPI_AHBCR_CACHABLEEN_MASK)

#define FlexSPI_AHBCR_BUFFERABLEEN_MASK          (0x10U)
#define FlexSPI_AHBCR_BUFFERABLEEN_SHIFT         (4U)
/*! BUFFERABLEEN - Enable AHB bus bufferable write access support. This field affects the last beat
 *    of AHB write access, refer for more details about AHB bufferable write.
 *  0b0..Disabled. For all AHB write access (no matter bufferable or non-bufferable ), FlexSPI will return AHB Bus
 *       ready after all data is transmitted to External device and AHB command finished.
 *  0b1..Enabled. For AHB bufferable write access, FlexSPI will return AHB Bus ready when the AHB command is
 *       granted by arbitrator and will not wait for AHB command finished.
 */
#define FlexSPI_AHBCR_BUFFERABLEEN(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBCR_BUFFERABLEEN_SHIFT)) & FlexSPI_AHBCR_BUFFERABLEEN_MASK)

#define FlexSPI_AHBCR_PREFETCHEN_MASK            (0x20U)
#define FlexSPI_AHBCR_PREFETCHEN_SHIFT           (5U)
/*! PREFETCHEN - AHB Read Prefetch Enable. */
#define FlexSPI_AHBCR_PREFETCHEN(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBCR_PREFETCHEN_SHIFT)) & FlexSPI_AHBCR_PREFETCHEN_MASK)

#define FlexSPI_AHBCR_READADDROPT_MASK           (0x40U)
#define FlexSPI_AHBCR_READADDROPT_SHIFT          (6U)
/*! READADDROPT - AHB Read Address option bit. This option bit is intend to remove AHB burst start address alignment limitation.
 *  0b0..There is AHB read burst start address alignment limitation when flash is accessed in parallel mode or flash is wordaddressable.
 *  0b1..There is no AHB read burst start address alignment limitation. FlexSPI will fetch more data than AHB
 *       burst required to meet the alignment requirement.
 */
#define FlexSPI_AHBCR_READADDROPT(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBCR_READADDROPT_SHIFT)) & FlexSPI_AHBCR_READADDROPT_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable Register */
/*! @{ */

#define FlexSPI_INTEN_IPCMDDONEEN_MASK           (0x1U)
#define FlexSPI_INTEN_IPCMDDONEEN_SHIFT          (0U)
/*! IPCMDDONEEN - IP triggered Command Sequences Execution finished interrupt enable. */
#define FlexSPI_INTEN_IPCMDDONEEN(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_IPCMDDONEEN_SHIFT)) & FlexSPI_INTEN_IPCMDDONEEN_MASK)

#define FlexSPI_INTEN_IPCMDGEEN_MASK             (0x2U)
#define FlexSPI_INTEN_IPCMDGEEN_SHIFT            (1U)
/*! IPCMDGEEN - IP triggered Command Sequences Grant Timeout interrupt enable. */
#define FlexSPI_INTEN_IPCMDGEEN(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_IPCMDGEEN_SHIFT)) & FlexSPI_INTEN_IPCMDGEEN_MASK)

#define FlexSPI_INTEN_AHBCMDGEEN_MASK            (0x4U)
#define FlexSPI_INTEN_AHBCMDGEEN_SHIFT           (2U)
/*! AHBCMDGEEN - AHB triggered Command Sequences Grant Timeout interrupt enable. */
#define FlexSPI_INTEN_AHBCMDGEEN(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_AHBCMDGEEN_SHIFT)) & FlexSPI_INTEN_AHBCMDGEEN_MASK)

#define FlexSPI_INTEN_IPCMDERREN_MASK            (0x8U)
#define FlexSPI_INTEN_IPCMDERREN_SHIFT           (3U)
/*! IPCMDERREN - IP triggered Command Sequences Error Detected interrupt enable. */
#define FlexSPI_INTEN_IPCMDERREN(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_IPCMDERREN_SHIFT)) & FlexSPI_INTEN_IPCMDERREN_MASK)

#define FlexSPI_INTEN_AHBCMDERREN_MASK           (0x10U)
#define FlexSPI_INTEN_AHBCMDERREN_SHIFT          (4U)
/*! AHBCMDERREN - AHB triggered Command Sequences Error Detected interrupt enable. */
#define FlexSPI_INTEN_AHBCMDERREN(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_AHBCMDERREN_SHIFT)) & FlexSPI_INTEN_AHBCMDERREN_MASK)

#define FlexSPI_INTEN_IPRXWAEN_MASK              (0x20U)
#define FlexSPI_INTEN_IPRXWAEN_SHIFT             (5U)
/*! IPRXWAEN - IP RX FIFO WaterMark available interrupt enable. */
#define FlexSPI_INTEN_IPRXWAEN(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_IPRXWAEN_SHIFT)) & FlexSPI_INTEN_IPRXWAEN_MASK)

#define FlexSPI_INTEN_IPTXWEEN_MASK              (0x40U)
#define FlexSPI_INTEN_IPTXWEEN_SHIFT             (6U)
/*! IPTXWEEN - IP TX FIFO WaterMark empty interrupt enable. */
#define FlexSPI_INTEN_IPTXWEEN(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_IPTXWEEN_SHIFT)) & FlexSPI_INTEN_IPTXWEEN_MASK)

#define FlexSPI_INTEN_DATALEARNFAILEN_MASK       (0x80U)
#define FlexSPI_INTEN_DATALEARNFAILEN_SHIFT      (7U)
/*! DATALEARNFAILEN - Data Learning failed interrupt enable. */
#define FlexSPI_INTEN_DATALEARNFAILEN(x)         (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_DATALEARNFAILEN_SHIFT)) & FlexSPI_INTEN_DATALEARNFAILEN_MASK)

#define FlexSPI_INTEN_SCKSTOPBYRDEN_MASK         (0x100U)
#define FlexSPI_INTEN_SCKSTOPBYRDEN_SHIFT        (8U)
/*! SCKSTOPBYRDEN - SCLK is stopped during command sequence because Async RX FIFO full interrupt enable. */
#define FlexSPI_INTEN_SCKSTOPBYRDEN(x)           (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_SCKSTOPBYRDEN_SHIFT)) & FlexSPI_INTEN_SCKSTOPBYRDEN_MASK)

#define FlexSPI_INTEN_SCKSTOPBYWREN_MASK         (0x200U)
#define FlexSPI_INTEN_SCKSTOPBYWREN_SHIFT        (9U)
/*! SCKSTOPBYWREN - SCLK is stopped during command sequence because Async TX FIFO empty interrupt enable. */
#define FlexSPI_INTEN_SCKSTOPBYWREN(x)           (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_SCKSTOPBYWREN_SHIFT)) & FlexSPI_INTEN_SCKSTOPBYWREN_MASK)

#define FlexSPI_INTEN_AHBBUSTIMEOUTEN_MASK       (0x400U)
#define FlexSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT      (10U)
/*! AHBBUSTIMEOUTEN - AHB Bus timeout interrupt.Refer Interrupts chapter for more details. */
#define FlexSPI_INTEN_AHBBUSTIMEOUTEN(x)         (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT)) & FlexSPI_INTEN_AHBBUSTIMEOUTEN_MASK)

#define FlexSPI_INTEN_SEQTIMEOUTEN_MASK          (0x800U)
#define FlexSPI_INTEN_SEQTIMEOUTEN_SHIFT         (11U)
/*! SEQTIMEOUTEN - Sequence execution timeout interrupt enable.Refer Interrupts chapter for more details. */
#define FlexSPI_INTEN_SEQTIMEOUTEN(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTEN_SEQTIMEOUTEN_SHIFT)) & FlexSPI_INTEN_SEQTIMEOUTEN_MASK)
/*! @} */

/*! @name INTR - Interrupt Register */
/*! @{ */

#define FlexSPI_INTR_IPCMDDONE_MASK              (0x1U)
#define FlexSPI_INTR_IPCMDDONE_SHIFT             (0U)
/*! IPCMDDONE - IP triggered Command Sequences Execution finished interrupt. This interrupt is also
 *    generated when there is IPCMDGE or IPCMDERR interrupt generated.
 */
#define FlexSPI_INTR_IPCMDDONE(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_IPCMDDONE_SHIFT)) & FlexSPI_INTR_IPCMDDONE_MASK)

#define FlexSPI_INTR_IPCMDGE_MASK                (0x2U)
#define FlexSPI_INTR_IPCMDGE_SHIFT               (1U)
/*! IPCMDGE - IP triggered Command Sequences Grant Timeout interrupt. */
#define FlexSPI_INTR_IPCMDGE(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_IPCMDGE_SHIFT)) & FlexSPI_INTR_IPCMDGE_MASK)

#define FlexSPI_INTR_AHBCMDGE_MASK               (0x4U)
#define FlexSPI_INTR_AHBCMDGE_SHIFT              (2U)
/*! AHBCMDGE - AHB triggered Command Sequences Grant Timeout interrupt. */
#define FlexSPI_INTR_AHBCMDGE(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_AHBCMDGE_SHIFT)) & FlexSPI_INTR_AHBCMDGE_MASK)

#define FlexSPI_INTR_IPCMDERR_MASK               (0x8U)
#define FlexSPI_INTR_IPCMDERR_SHIFT              (3U)
/*! IPCMDERR - IP triggered Command Sequences Error Detected interrupt. When an error detected for
 *    IP command, this command will be ignored and not executed at all.
 */
#define FlexSPI_INTR_IPCMDERR(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_IPCMDERR_SHIFT)) & FlexSPI_INTR_IPCMDERR_MASK)

#define FlexSPI_INTR_AHBCMDERR_MASK              (0x10U)
#define FlexSPI_INTR_AHBCMDERR_SHIFT             (4U)
/*! AHBCMDERR - AHB triggered Command Sequences Error Detected interrupt. When an error detected for
 *    AHB command, this command will be ignored and not executed at all.
 */
#define FlexSPI_INTR_AHBCMDERR(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_AHBCMDERR_SHIFT)) & FlexSPI_INTR_AHBCMDERR_MASK)

#define FlexSPI_INTR_IPRXWA_MASK                 (0x20U)
#define FlexSPI_INTR_IPRXWA_SHIFT                (5U)
/*! IPRXWA - IP RX FIFO watermark available interrupt. */
#define FlexSPI_INTR_IPRXWA(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_IPRXWA_SHIFT)) & FlexSPI_INTR_IPRXWA_MASK)

#define FlexSPI_INTR_IPTXWE_MASK                 (0x40U)
#define FlexSPI_INTR_IPTXWE_SHIFT                (6U)
/*! IPTXWE - IP TX FIFO watermark empty interrupt. */
#define FlexSPI_INTR_IPTXWE(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_IPTXWE_SHIFT)) & FlexSPI_INTR_IPTXWE_MASK)

#define FlexSPI_INTR_DATALEARNFAIL_MASK          (0x80U)
#define FlexSPI_INTR_DATALEARNFAIL_SHIFT         (7U)
/*! DATALEARNFAIL - Data Learning failed interrupt. */
#define FlexSPI_INTR_DATALEARNFAIL(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_DATALEARNFAIL_SHIFT)) & FlexSPI_INTR_DATALEARNFAIL_MASK)

#define FlexSPI_INTR_SCKSTOPBYRD_MASK            (0x100U)
#define FlexSPI_INTR_SCKSTOPBYRD_SHIFT           (8U)
/*! SCKSTOPBYRD - SCLK is stopped during command sequence because Async RX FIFO full interrupt. */
#define FlexSPI_INTR_SCKSTOPBYRD(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_SCKSTOPBYRD_SHIFT)) & FlexSPI_INTR_SCKSTOPBYRD_MASK)

#define FlexSPI_INTR_SCKSTOPBYWR_MASK            (0x200U)
#define FlexSPI_INTR_SCKSTOPBYWR_SHIFT           (9U)
/*! SCKSTOPBYWR - SCLK is stopped during command sequence because Async TX FIFO empty interrupt. */
#define FlexSPI_INTR_SCKSTOPBYWR(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_SCKSTOPBYWR_SHIFT)) & FlexSPI_INTR_SCKSTOPBYWR_MASK)

#define FlexSPI_INTR_AHBBUSTIMEOUT_MASK          (0x400U)
#define FlexSPI_INTR_AHBBUSTIMEOUT_SHIFT         (10U)
/*! AHBBUSTIMEOUT - AHB Bus timeout interrupt.Refer Interrupts chapter for more details. */
#define FlexSPI_INTR_AHBBUSTIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_AHBBUSTIMEOUT_SHIFT)) & FlexSPI_INTR_AHBBUSTIMEOUT_MASK)

#define FlexSPI_INTR_SEQTIMEOUT_MASK             (0x800U)
#define FlexSPI_INTR_SEQTIMEOUT_SHIFT            (11U)
/*! SEQTIMEOUT - Sequence execution timeout interrupt. */
#define FlexSPI_INTR_SEQTIMEOUT(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_INTR_SEQTIMEOUT_SHIFT)) & FlexSPI_INTR_SEQTIMEOUT_MASK)
/*! @} */

/*! @name LUTKEY - LUT Key Register */
/*! @{ */

#define FlexSPI_LUTKEY_KEY_MASK                  (0xFFFFFFFFU)
#define FlexSPI_LUTKEY_KEY_SHIFT                 (0U)
/*! KEY - The Key to lock or unlock LUT. */
#define FlexSPI_LUTKEY_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUTKEY_KEY_SHIFT)) & FlexSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LUTCR - LUT Control Register */
/*! @{ */

#define FlexSPI_LUTCR_LOCK_MASK                  (0x1U)
#define FlexSPI_LUTCR_LOCK_SHIFT                 (0U)
/*! LOCK - Lock LUT */
#define FlexSPI_LUTCR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUTCR_LOCK_SHIFT)) & FlexSPI_LUTCR_LOCK_MASK)

#define FlexSPI_LUTCR_UNLOCK_MASK                (0x2U)
#define FlexSPI_LUTCR_UNLOCK_SHIFT               (1U)
/*! UNLOCK - Unlock LUT */
#define FlexSPI_LUTCR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUTCR_UNLOCK_SHIFT)) & FlexSPI_LUTCR_UNLOCK_MASK)
/*! @} */

/*! @name AHBRXBUFCR0 - AHB RX Buffer 0 Control Register 0..AHB RX Buffer 7 Control Register 0 */
/*! @{ */

#define FlexSPI_AHBRXBUFCR0_BUFSZ_MASK           (0x1FFU)
#define FlexSPI_AHBRXBUFCR0_BUFSZ_SHIFT          (0U)
/*! BUFSZ - AHB RX Buffer Size in 64 bits. */
#define FlexSPI_AHBRXBUFCR0_BUFSZ(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBRXBUFCR0_BUFSZ_SHIFT)) & FlexSPI_AHBRXBUFCR0_BUFSZ_MASK)

#define FlexSPI_AHBRXBUFCR0_MSTRID_MASK          (0xF0000U)
#define FlexSPI_AHBRXBUFCR0_MSTRID_SHIFT         (16U)
/*! MSTRID - This AHB RX Buffer is assigned according to AHB Master with ID (MSTR_ID). */
#define FlexSPI_AHBRXBUFCR0_MSTRID(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBRXBUFCR0_MSTRID_SHIFT)) & FlexSPI_AHBRXBUFCR0_MSTRID_MASK)

#define FlexSPI_AHBRXBUFCR0_PRIORITY_MASK        (0x7000000U)
#define FlexSPI_AHBRXBUFCR0_PRIORITY_SHIFT       (24U)
/*! PRIORITY - This priority for AHB Master Read which this AHB RX Buffer is assigned. */
#define FlexSPI_AHBRXBUFCR0_PRIORITY(x)          (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBRXBUFCR0_PRIORITY_SHIFT)) & FlexSPI_AHBRXBUFCR0_PRIORITY_MASK)

#define FlexSPI_AHBRXBUFCR0_PREFETCHEN_MASK      (0x80000000U)
#define FlexSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT     (31U)
/*! PREFETCHEN - AHB Read Prefetch Enable for current AHB RX Buffer corresponding Master. */
#define FlexSPI_AHBRXBUFCR0_PREFETCHEN(x)        (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT)) & FlexSPI_AHBRXBUFCR0_PREFETCHEN_MASK)
/*! @} */

/* The count of FlexSPI_AHBRXBUFCR0 */
#define FlexSPI_AHBRXBUFCR0_COUNT                (8U)

/*! @name FLSHCR0 - Flash Control Register 0 */
/*! @{ */

#define FlexSPI_FLSHCR0_FLSHSZ_MASK              (0x7FFFFFU)
#define FlexSPI_FLSHCR0_FLSHSZ_SHIFT             (0U)
/*! FLSHSZ - Flash Size in KByte. */
#define FlexSPI_FLSHCR0_FLSHSZ(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR0_FLSHSZ_SHIFT)) & FlexSPI_FLSHCR0_FLSHSZ_MASK)
/*! @} */

/* The count of FlexSPI_FLSHCR0 */
#define FlexSPI_FLSHCR0_COUNT                    (4U)

/*! @name FLSHCR1 - Flash Control Register 1 */
/*! @{ */

#define FlexSPI_FLSHCR1_TCSS_MASK                (0x1FU)
#define FlexSPI_FLSHCR1_TCSS_SHIFT               (0U)
/*! TCSS - Serial Flash CS setup time. */
#define FlexSPI_FLSHCR1_TCSS(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_TCSS_SHIFT)) & FlexSPI_FLSHCR1_TCSS_MASK)

#define FlexSPI_FLSHCR1_TCSH_MASK                (0x3E0U)
#define FlexSPI_FLSHCR1_TCSH_SHIFT               (5U)
/*! TCSH - Serial Flash CS Hold time. */
#define FlexSPI_FLSHCR1_TCSH(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_TCSH_SHIFT)) & FlexSPI_FLSHCR1_TCSH_MASK)

#define FlexSPI_FLSHCR1_WA_MASK                  (0x400U)
#define FlexSPI_FLSHCR1_WA_SHIFT                 (10U)
/*! WA - Word Addressable. */
#define FlexSPI_FLSHCR1_WA(x)                    (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_WA_SHIFT)) & FlexSPI_FLSHCR1_WA_MASK)

#define FlexSPI_FLSHCR1_CAS_MASK                 (0x7800U)
#define FlexSPI_FLSHCR1_CAS_SHIFT                (11U)
/*! CAS - Column Address Size. */
#define FlexSPI_FLSHCR1_CAS(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_CAS_SHIFT)) & FlexSPI_FLSHCR1_CAS_MASK)

#define FlexSPI_FLSHCR1_CSINTERVALUNIT_MASK      (0x8000U)
#define FlexSPI_FLSHCR1_CSINTERVALUNIT_SHIFT     (15U)
/*! CSINTERVALUNIT - CS interval unit
 *  0b0..The CS interval unit is 1 serial clock cycle
 *  0b1..The CS interval unit is 256 serial clock cycle
 */
#define FlexSPI_FLSHCR1_CSINTERVALUNIT(x)        (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_CSINTERVALUNIT_SHIFT)) & FlexSPI_FLSHCR1_CSINTERVALUNIT_MASK)

#define FlexSPI_FLSHCR1_CSINTERVAL_MASK          (0xFFFF0000U)
#define FlexSPI_FLSHCR1_CSINTERVAL_SHIFT         (16U)
/*! CSINTERVAL - This field is used to set the minimum interval between flash device Chip selection
 *    deassertion and flash device Chip selection assertion. If external flash has a limitation on
 *    the interval between command sequences, this field should be set accordingly. If there is no
 *    limitation, set this field with value 0x0.
 */
#define FlexSPI_FLSHCR1_CSINTERVAL(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR1_CSINTERVAL_SHIFT)) & FlexSPI_FLSHCR1_CSINTERVAL_MASK)
/*! @} */

/* The count of FlexSPI_FLSHCR1 */
#define FlexSPI_FLSHCR1_COUNT                    (4U)

/*! @name FLSHCR2 - Flash Control Register 2 */
/*! @{ */

#define FlexSPI_FLSHCR2_ARDSEQID_MASK            (0x1FU)
#define FlexSPI_FLSHCR2_ARDSEQID_SHIFT           (0U)
/*! ARDSEQID - Sequence Index for AHB Read triggered Command in LUT. */
#define FlexSPI_FLSHCR2_ARDSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_ARDSEQID_SHIFT)) & FlexSPI_FLSHCR2_ARDSEQID_MASK)

#define FlexSPI_FLSHCR2_ARDSEQNUM_MASK           (0xE0U)
#define FlexSPI_FLSHCR2_ARDSEQNUM_SHIFT          (5U)
/*! ARDSEQNUM - Sequence Number for AHB Read triggered Command in LUT. */
#define FlexSPI_FLSHCR2_ARDSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_ARDSEQNUM_SHIFT)) & FlexSPI_FLSHCR2_ARDSEQNUM_MASK)

#define FlexSPI_FLSHCR2_AWRSEQID_MASK            (0x1F00U)
#define FlexSPI_FLSHCR2_AWRSEQID_SHIFT           (8U)
/*! AWRSEQID - Sequence Index for AHB Write triggered Command. */
#define FlexSPI_FLSHCR2_AWRSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_AWRSEQID_SHIFT)) & FlexSPI_FLSHCR2_AWRSEQID_MASK)

#define FlexSPI_FLSHCR2_AWRSEQNUM_MASK           (0xE000U)
#define FlexSPI_FLSHCR2_AWRSEQNUM_SHIFT          (13U)
/*! AWRSEQNUM - Sequence Number for AHB Write triggered Command. */
#define FlexSPI_FLSHCR2_AWRSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_AWRSEQNUM_SHIFT)) & FlexSPI_FLSHCR2_AWRSEQNUM_MASK)

#define FlexSPI_FLSHCR2_AWRWAIT_MASK             (0xFFF0000U)
#define FlexSPI_FLSHCR2_AWRWAIT_SHIFT            (16U)
#define FlexSPI_FLSHCR2_AWRWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_AWRWAIT_SHIFT)) & FlexSPI_FLSHCR2_AWRWAIT_MASK)

#define FlexSPI_FLSHCR2_AWRWAITUNIT_MASK         (0x70000000U)
#define FlexSPI_FLSHCR2_AWRWAITUNIT_SHIFT        (28U)
/*! AWRWAITUNIT - AWRWAIT unit
 *  0b000..The AWRWAIT unit is 2 ahb clock cycle
 *  0b001..The AWRWAIT unit is 8 ahb clock cycle
 *  0b010..The AWRWAIT unit is 32 ahb clock cycle
 *  0b011..The AWRWAIT unit is 128 ahb clock cycle
 *  0b100..The AWRWAIT unit is 512 ahb clock cycle
 *  0b101..The AWRWAIT unit is 2048 ahb clock cycle
 *  0b110..The AWRWAIT unit is 8192 ahb clock cycle
 *  0b111..The AWRWAIT unit is 32768 ahb clock cycle
 */
#define FlexSPI_FLSHCR2_AWRWAITUNIT(x)           (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_AWRWAITUNIT_SHIFT)) & FlexSPI_FLSHCR2_AWRWAITUNIT_MASK)

#define FlexSPI_FLSHCR2_CLRINSTRPTR_MASK         (0x80000000U)
#define FlexSPI_FLSHCR2_CLRINSTRPTR_SHIFT        (31U)
/*! CLRINSTRPTR - Clear the instruction pointer which is internally saved pointer by JMP_ON_CS.
 *    Refer Programmable Sequence Engine for details.
 */
#define FlexSPI_FLSHCR2_CLRINSTRPTR(x)           (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR2_CLRINSTRPTR_SHIFT)) & FlexSPI_FLSHCR2_CLRINSTRPTR_MASK)
/*! @} */

/* The count of FlexSPI_FLSHCR2 */
#define FlexSPI_FLSHCR2_COUNT                    (4U)

/*! @name FLSHCR4 - Flash Control Register 4 */
/*! @{ */

#define FlexSPI_FLSHCR4_WMOPT1_MASK              (0x1U)
#define FlexSPI_FLSHCR4_WMOPT1_SHIFT             (0U)
/*! WMOPT1 - Write mask option bit 1. This option bit could be used to remove AHB write burst start address alignment limitation.
 *  0b0..DQS pin will be used as Write Mask when writing to external device. There is no limitation on AHB write
 *       burst start address alignment when flash is accessed in individual mode.
 *  0b1..DQS pin will not be used as Write Mask when writing to external device. There is limitation on AHB write
 *       burst start address alignment when flash is accessed in individual mode.
 */
#define FlexSPI_FLSHCR4_WMOPT1(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR4_WMOPT1_SHIFT)) & FlexSPI_FLSHCR4_WMOPT1_MASK)

#define FlexSPI_FLSHCR4_WMENA_MASK               (0x4U)
#define FlexSPI_FLSHCR4_WMENA_SHIFT              (2U)
/*! WMENA - Write mask enable bit for flash device on port A. When write mask function is needed for
 *    memory device on port A, this bit must be set.
 *  0b0..Write mask is disabled, DQS(RWDS) pin will be un-driven when writing to external device.
 *  0b1..Write mask is enabled, DQS(RWDS) pin will be driven by FlexSPI as write mask output when writing to external device.
 */
#define FlexSPI_FLSHCR4_WMENA(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR4_WMENA_SHIFT)) & FlexSPI_FLSHCR4_WMENA_MASK)

#define FlexSPI_FLSHCR4_WMENB_MASK               (0x8U)
#define FlexSPI_FLSHCR4_WMENB_SHIFT              (3U)
/*! WMENB - Write mask enable bit for flash device on port B. When write mask function is needed for
 *    memory device on port B, this bit must be set.
 *  0b0..Write mask is disabled, DQS(RWDS) pin will be un-driven when writing to external device.
 *  0b1..Write mask is enabled, DQS(RWDS) pin will be driven by FlexSPI as write mask output when writing to external device.
 */
#define FlexSPI_FLSHCR4_WMENB(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_FLSHCR4_WMENB_SHIFT)) & FlexSPI_FLSHCR4_WMENB_MASK)
/*! @} */

/*! @name IPCR0 - IP Control Register 0 */
/*! @{ */

#define FlexSPI_IPCR0_SFAR_MASK                  (0xFFFFFFFFU)
#define FlexSPI_IPCR0_SFAR_SHIFT                 (0U)
/*! SFAR - Serial Flash Address for IP command. */
#define FlexSPI_IPCR0_SFAR(x)                    (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCR0_SFAR_SHIFT)) & FlexSPI_IPCR0_SFAR_MASK)
/*! @} */

/*! @name IPCR1 - IP Control Register 1 */
/*! @{ */

#define FlexSPI_IPCR1_IDATSZ_MASK                (0xFFFFU)
#define FlexSPI_IPCR1_IDATSZ_SHIFT               (0U)
/*! IDATSZ - Flash Read/Program Data Size (in Bytes) for IP command. */
#define FlexSPI_IPCR1_IDATSZ(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCR1_IDATSZ_SHIFT)) & FlexSPI_IPCR1_IDATSZ_MASK)

#define FlexSPI_IPCR1_ISEQID_MASK                (0x1F0000U)
#define FlexSPI_IPCR1_ISEQID_SHIFT               (16U)
/*! ISEQID - Sequence Index in LUT for IP command. */
#define FlexSPI_IPCR1_ISEQID(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCR1_ISEQID_SHIFT)) & FlexSPI_IPCR1_ISEQID_MASK)

#define FlexSPI_IPCR1_ISEQNUM_MASK               (0x7000000U)
#define FlexSPI_IPCR1_ISEQNUM_SHIFT              (24U)
/*! ISEQNUM - Sequence Number for IP command: ISEQNUM+1. */
#define FlexSPI_IPCR1_ISEQNUM(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCR1_ISEQNUM_SHIFT)) & FlexSPI_IPCR1_ISEQNUM_MASK)

#define FlexSPI_IPCR1_IPAREN_MASK                (0x80000000U)
#define FlexSPI_IPCR1_IPAREN_SHIFT               (31U)
/*! IPAREN - Parallel mode Enabled for IP command.
 *  0b0..Flash will be accessed in Individual mode.
 *  0b1..Flash will be accessed in Parallel mode.
 */
#define FlexSPI_IPCR1_IPAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCR1_IPAREN_SHIFT)) & FlexSPI_IPCR1_IPAREN_MASK)
/*! @} */

/*! @name IPCMD - IP Command Register */
/*! @{ */

#define FlexSPI_IPCMD_TRG_MASK                   (0x1U)
#define FlexSPI_IPCMD_TRG_SHIFT                  (0U)
/*! TRG - Setting this bit will trigger an IP Command. */
#define FlexSPI_IPCMD_TRG(x)                     (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPCMD_TRG_SHIFT)) & FlexSPI_IPCMD_TRG_MASK)
/*! @} */

/*! @name DLPR - Data Learn Pattern Register */
/*! @{ */

#define FlexSPI_DLPR_DLP_MASK                    (0xFFFFFFFFU)
#define FlexSPI_DLPR_DLP_SHIFT                   (0U)
/*! DLP - Data Learning Pattern. */
#define FlexSPI_DLPR_DLP(x)                      (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLPR_DLP_SHIFT)) & FlexSPI_DLPR_DLP_MASK)
/*! @} */

/*! @name IPRXFCR - IP RX FIFO Control Register */
/*! @{ */

#define FlexSPI_IPRXFCR_CLRIPRXF_MASK            (0x1U)
#define FlexSPI_IPRXFCR_CLRIPRXF_SHIFT           (0U)
/*! CLRIPRXF - Clear all valid data entries in IP RX FIFO. */
#define FlexSPI_IPRXFCR_CLRIPRXF(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPRXFCR_CLRIPRXF_SHIFT)) & FlexSPI_IPRXFCR_CLRIPRXF_MASK)

#define FlexSPI_IPRXFCR_RXDMAEN_MASK             (0x2U)
#define FlexSPI_IPRXFCR_RXDMAEN_SHIFT            (1U)
/*! RXDMAEN - IP RX FIFO reading by DMA enabled.
 *  0b0..IP RX FIFO would be read by processor.
 *  0b1..IP RX FIFO would be read by DMA.
 */
#define FlexSPI_IPRXFCR_RXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPRXFCR_RXDMAEN_SHIFT)) & FlexSPI_IPRXFCR_RXDMAEN_MASK)

#define FlexSPI_IPRXFCR_RXWMRK_MASK              (0xFCU)
#define FlexSPI_IPRXFCR_RXWMRK_SHIFT             (2U)
/*! RXWMRK - Watermark level is (RXWMRK+1)*64 Bits. */
#define FlexSPI_IPRXFCR_RXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPRXFCR_RXWMRK_SHIFT)) & FlexSPI_IPRXFCR_RXWMRK_MASK)
/*! @} */

/*! @name IPTXFCR - IP TX FIFO Control Register */
/*! @{ */

#define FlexSPI_IPTXFCR_CLRIPTXF_MASK            (0x1U)
#define FlexSPI_IPTXFCR_CLRIPTXF_SHIFT           (0U)
/*! CLRIPTXF - Clear all valid data entries in IP TX FIFO. */
#define FlexSPI_IPTXFCR_CLRIPTXF(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPTXFCR_CLRIPTXF_SHIFT)) & FlexSPI_IPTXFCR_CLRIPTXF_MASK)

#define FlexSPI_IPTXFCR_TXDMAEN_MASK             (0x2U)
#define FlexSPI_IPTXFCR_TXDMAEN_SHIFT            (1U)
/*! TXDMAEN - IP TX FIFO filling by DMA enabled.
 *  0b0..IP TX FIFO would be filled by processor.
 *  0b1..IP TX FIFO would be filled by DMA.
 */
#define FlexSPI_IPTXFCR_TXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPTXFCR_TXDMAEN_SHIFT)) & FlexSPI_IPTXFCR_TXDMAEN_MASK)

#define FlexSPI_IPTXFCR_TXWMRK_MASK              (0x1FCU)
#define FlexSPI_IPTXFCR_TXWMRK_SHIFT             (2U)
/*! TXWMRK - Watermark level is (TXWMRK+1)*64 Bits. */
#define FlexSPI_IPTXFCR_TXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPTXFCR_TXWMRK_SHIFT)) & FlexSPI_IPTXFCR_TXWMRK_MASK)
/*! @} */

/*! @name DLLCR - DLL Control Register 0 */
/*! @{ */

#define FlexSPI_DLLCR_DLLEN_MASK                 (0x1U)
#define FlexSPI_DLLCR_DLLEN_SHIFT                (0U)
/*! DLLEN - DLL calibration enable. */
#define FlexSPI_DLLCR_DLLEN(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLLCR_DLLEN_SHIFT)) & FlexSPI_DLLCR_DLLEN_MASK)

#define FlexSPI_DLLCR_DLLRESET_MASK              (0x2U)
#define FlexSPI_DLLCR_DLLRESET_SHIFT             (1U)
/*! DLLRESET - Software could force a reset on DLL by setting this field to 0x1. This will cause the
 *    DLL to lose lock and re-calibrate to detect an ref_clock half period phase shift. The reset
 *    action is edge triggered, so software need to clear this bit after set this bit (no delay
 *    limitation).
 */
#define FlexSPI_DLLCR_DLLRESET(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLLCR_DLLRESET_SHIFT)) & FlexSPI_DLLCR_DLLRESET_MASK)

#define FlexSPI_DLLCR_SLVDLYTARGET_MASK          (0x78U)
#define FlexSPI_DLLCR_SLVDLYTARGET_SHIFT         (3U)
/*! SLVDLYTARGET - The delay target for slave delay line is: ((SLVDLYTARGET+1) * 1/32 * clock cycle of reference clock (serial root clock). */
#define FlexSPI_DLLCR_SLVDLYTARGET(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLLCR_SLVDLYTARGET_SHIFT)) & FlexSPI_DLLCR_SLVDLYTARGET_MASK)

#define FlexSPI_DLLCR_OVRDEN_MASK                (0x100U)
#define FlexSPI_DLLCR_OVRDEN_SHIFT               (8U)
/*! OVRDEN - Slave clock delay line delay cell number selection override enable. */
#define FlexSPI_DLLCR_OVRDEN(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLLCR_OVRDEN_SHIFT)) & FlexSPI_DLLCR_OVRDEN_MASK)

#define FlexSPI_DLLCR_OVRDVAL_MASK               (0x7E00U)
#define FlexSPI_DLLCR_OVRDVAL_SHIFT              (9U)
/*! OVRDVAL - Slave clock delay line delay cell number selection override value. */
#define FlexSPI_DLLCR_OVRDVAL(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_DLLCR_OVRDVAL_SHIFT)) & FlexSPI_DLLCR_OVRDVAL_MASK)
/*! @} */

/* The count of FlexSPI_DLLCR */
#define FlexSPI_DLLCR_COUNT                      (2U)

/*! @name STS0 - Status Register 0 */
/*! @{ */

#define FlexSPI_STS0_SEQIDLE_MASK                (0x1U)
#define FlexSPI_STS0_SEQIDLE_SHIFT               (0U)
/*! SEQIDLE - This status bit indicates the state machine in SEQ_CTL is idle and there is command
 *    sequence executing on FlexSPI interface.
 */
#define FlexSPI_STS0_SEQIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS0_SEQIDLE_SHIFT)) & FlexSPI_STS0_SEQIDLE_MASK)

#define FlexSPI_STS0_ARBIDLE_MASK                (0x2U)
#define FlexSPI_STS0_ARBIDLE_SHIFT               (1U)
/*! ARBIDLE - This status bit indicates the state machine in ARB_CTL is busy and there is command
 *    sequence granted by arbitrator and not finished yet on FlexSPI interface. When ARB_CTL state
 *    (ARBIDLE=0x1) is idle, there will be no transaction on FlexSPI interface also (SEQIDLE=0x1). So
 *    this bit should be polled to wait for FlexSPI controller become idle instead of SEQIDLE.
 */
#define FlexSPI_STS0_ARBIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS0_ARBIDLE_SHIFT)) & FlexSPI_STS0_ARBIDLE_MASK)

#define FlexSPI_STS0_ARBCMDSRC_MASK              (0xCU)
#define FlexSPI_STS0_ARBCMDSRC_SHIFT             (2U)
/*! ARBCMDSRC - This status field indicates the trigger source of current command sequence granted
 *    by arbitrator. This field value is meaningless when ARB_CTL is not busy (STS0[ARBIDLE]=0x1).
 *  0b00..Triggered by AHB read command (triggered by AHB read).
 *  0b01..Triggered by AHB write command (triggered by AHB Write).
 *  0b10..Triggered by IP command (triggered by setting register bit IPCMD.TRG).
 *  0b11..Triggered by suspended command (resumed).
 */
#define FlexSPI_STS0_ARBCMDSRC(x)                (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS0_ARBCMDSRC_SHIFT)) & FlexSPI_STS0_ARBCMDSRC_MASK)

#define FlexSPI_STS0_DATALEARNPHASEA_MASK        (0xF0U)
#define FlexSPI_STS0_DATALEARNPHASEA_SHIFT       (4U)
/*! DATALEARNPHASEA - Indicate the sampling clock phase selection on Port A after Data Learning. */
#define FlexSPI_STS0_DATALEARNPHASEA(x)          (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS0_DATALEARNPHASEA_SHIFT)) & FlexSPI_STS0_DATALEARNPHASEA_MASK)

#define FlexSPI_STS0_DATALEARNPHASEB_MASK        (0xF00U)
#define FlexSPI_STS0_DATALEARNPHASEB_SHIFT       (8U)
/*! DATALEARNPHASEB - Indicate the sampling clock phase selection on Port B after Data Learning. */
#define FlexSPI_STS0_DATALEARNPHASEB(x)          (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS0_DATALEARNPHASEB_SHIFT)) & FlexSPI_STS0_DATALEARNPHASEB_MASK)
/*! @} */

/*! @name STS1 - Status Register 1 */
/*! @{ */

#define FlexSPI_STS1_AHBCMDERRID_MASK            (0x1FU)
#define FlexSPI_STS1_AHBCMDERRID_SHIFT           (0U)
/*! AHBCMDERRID - Indicates the sequence index when an AHB command error is detected. This field
 *    will be cleared when INTR[AHBCMDERR] is write-1-clear(w1c).
 */
#define FlexSPI_STS1_AHBCMDERRID(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS1_AHBCMDERRID_SHIFT)) & FlexSPI_STS1_AHBCMDERRID_MASK)

#define FlexSPI_STS1_AHBCMDERRCODE_MASK          (0xF00U)
#define FlexSPI_STS1_AHBCMDERRCODE_SHIFT         (8U)
/*! AHBCMDERRCODE - Indicates the Error Code when AHB command Error detected. This field will be
 *    cleared when INTR[AHBCMDERR] is write-1-clear(w1c).
 *  0b0000..No error.
 *  0b0010..AHB Write command with JMP_ON_CS instruction used in the sequence.
 *  0b0011..There is unknown instruction opcode in the sequence.
 *  0b0100..Instruction DUMMY_SDR/DUMMY_RWDS_SDR used in DDR sequence.
 *  0b0101..Instruction DUMMY_DDR/DUMMY_RWDS_DDR used in SDR sequence.
 *  0b1110..Sequence execution timeout.
 */
#define FlexSPI_STS1_AHBCMDERRCODE(x)            (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS1_AHBCMDERRCODE_SHIFT)) & FlexSPI_STS1_AHBCMDERRCODE_MASK)

#define FlexSPI_STS1_IPCMDERRID_MASK             (0x1F0000U)
#define FlexSPI_STS1_IPCMDERRID_SHIFT            (16U)
/*! IPCMDERRID - Indicates the sequence Index when IP command error detected. This field will be
 *    cleared when INTR[IPCMDERR] is write-1-clear(w1c).
 */
#define FlexSPI_STS1_IPCMDERRID(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS1_IPCMDERRID_SHIFT)) & FlexSPI_STS1_IPCMDERRID_MASK)

#define FlexSPI_STS1_IPCMDERRCODE_MASK           (0xF000000U)
#define FlexSPI_STS1_IPCMDERRCODE_SHIFT          (24U)
/*! IPCMDERRCODE - Indicates the Error Code when IP command Error detected. This field will be
 *    cleared when INTR[IPCMDERR] is write-1-clear(w1c).
 *  0b0000..No error.
 *  0b0010..IP command with JMP_ON_CS instruction used in the sequence.
 *  0b0011..There is unknown instruction opcode in the sequence.
 *  0b0100..Instruction DUMMY_SDR/DUMMY_RWDS_SDR used in DDR sequence.
 *  0b0101..Instruction DUMMY_DDR/DUMMY_RWDS_DDR used in SDR sequence.
 *  0b0110..Flash access start address exceed the whole flash address range (A1/A2/B1/B2).
 *  0b1110..Sequence execution timeout.
 *  0b1111..Flash boundary crossed.
 */
#define FlexSPI_STS1_IPCMDERRCODE(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS1_IPCMDERRCODE_SHIFT)) & FlexSPI_STS1_IPCMDERRCODE_MASK)
/*! @} */

/*! @name STS2 - Status Register 2 */
/*! @{ */

#define FlexSPI_STS2_ASLVLOCK_MASK               (0x1U)
#define FlexSPI_STS2_ASLVLOCK_SHIFT              (0U)
/*! ASLVLOCK - Flash A sample clock slave delay line locked. */
#define FlexSPI_STS2_ASLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_ASLVLOCK_SHIFT)) & FlexSPI_STS2_ASLVLOCK_MASK)

#define FlexSPI_STS2_AREFLOCK_MASK               (0x2U)
#define FlexSPI_STS2_AREFLOCK_SHIFT              (1U)
/*! AREFLOCK - Flash A sample clock reference delay line locked. */
#define FlexSPI_STS2_AREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_AREFLOCK_SHIFT)) & FlexSPI_STS2_AREFLOCK_MASK)

#define FlexSPI_STS2_ASLVSEL_MASK                (0xFCU)
#define FlexSPI_STS2_ASLVSEL_SHIFT               (2U)
/*! ASLVSEL - Flash A sample clock slave delay line delay cell number selection . */
#define FlexSPI_STS2_ASLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_ASLVSEL_SHIFT)) & FlexSPI_STS2_ASLVSEL_MASK)

#define FlexSPI_STS2_AREFSEL_MASK                (0x3F00U)
#define FlexSPI_STS2_AREFSEL_SHIFT               (8U)
/*! AREFSEL - Flash A sample clock reference delay line delay cell number selection. */
#define FlexSPI_STS2_AREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_AREFSEL_SHIFT)) & FlexSPI_STS2_AREFSEL_MASK)

#define FlexSPI_STS2_BSLVLOCK_MASK               (0x10000U)
#define FlexSPI_STS2_BSLVLOCK_SHIFT              (16U)
/*! BSLVLOCK - Flash B sample clock slave delay line locked. */
#define FlexSPI_STS2_BSLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_BSLVLOCK_SHIFT)) & FlexSPI_STS2_BSLVLOCK_MASK)

#define FlexSPI_STS2_BREFLOCK_MASK               (0x20000U)
#define FlexSPI_STS2_BREFLOCK_SHIFT              (17U)
/*! BREFLOCK - Flash B sample clock reference delay line locked. */
#define FlexSPI_STS2_BREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_BREFLOCK_SHIFT)) & FlexSPI_STS2_BREFLOCK_MASK)

#define FlexSPI_STS2_BSLVSEL_MASK                (0xFC0000U)
#define FlexSPI_STS2_BSLVSEL_SHIFT               (18U)
/*! BSLVSEL - Flash B sample clock slave delay line delay cell number selection. */
#define FlexSPI_STS2_BSLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_BSLVSEL_SHIFT)) & FlexSPI_STS2_BSLVSEL_MASK)

#define FlexSPI_STS2_BREFSEL_MASK                (0x3F000000U)
#define FlexSPI_STS2_BREFSEL_SHIFT               (24U)
/*! BREFSEL - Flash B sample clock reference delay line delay cell number selection. */
#define FlexSPI_STS2_BREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_STS2_BREFSEL_SHIFT)) & FlexSPI_STS2_BREFSEL_MASK)
/*! @} */

/*! @name AHBSPNDSTS - AHB Suspend Status Register */
/*! @{ */

#define FlexSPI_AHBSPNDSTS_ACTIVE_MASK           (0x1U)
#define FlexSPI_AHBSPNDSTS_ACTIVE_SHIFT          (0U)
/*! ACTIVE - Indicates if an AHB read prefetch command sequence has been suspended. */
#define FlexSPI_AHBSPNDSTS_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBSPNDSTS_ACTIVE_SHIFT)) & FlexSPI_AHBSPNDSTS_ACTIVE_MASK)

#define FlexSPI_AHBSPNDSTS_BUFID_MASK            (0xEU)
#define FlexSPI_AHBSPNDSTS_BUFID_SHIFT           (1U)
/*! BUFID - AHB RX BUF ID for suspended command sequence. */
#define FlexSPI_AHBSPNDSTS_BUFID(x)              (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBSPNDSTS_BUFID_SHIFT)) & FlexSPI_AHBSPNDSTS_BUFID_MASK)

#define FlexSPI_AHBSPNDSTS_DATLFT_MASK           (0xFFFF0000U)
#define FlexSPI_AHBSPNDSTS_DATLFT_SHIFT          (16U)
/*! DATLFT - Left Data size for suspended command sequence (in byte). */
#define FlexSPI_AHBSPNDSTS_DATLFT(x)             (((uint32_t)(((uint32_t)(x)) << FlexSPI_AHBSPNDSTS_DATLFT_SHIFT)) & FlexSPI_AHBSPNDSTS_DATLFT_MASK)
/*! @} */

/*! @name IPRXFSTS - IP RX FIFO Status Register */
/*! @{ */

#define FlexSPI_IPRXFSTS_FILL_MASK               (0xFFU)
#define FlexSPI_IPRXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill level of IP RX FIFO. */
#define FlexSPI_IPRXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPRXFSTS_FILL_SHIFT)) & FlexSPI_IPRXFSTS_FILL_MASK)

#define FlexSPI_IPRXFSTS_RDCNTR_MASK             (0xFFFF0000U)
#define FlexSPI_IPRXFSTS_RDCNTR_SHIFT            (16U)
/*! RDCNTR - Total Read Data Counter: RDCNTR * 64 Bits. */
#define FlexSPI_IPRXFSTS_RDCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPRXFSTS_RDCNTR_SHIFT)) & FlexSPI_IPRXFSTS_RDCNTR_MASK)
/*! @} */

/*! @name IPTXFSTS - IP TX FIFO Status Register */
/*! @{ */

#define FlexSPI_IPTXFSTS_FILL_MASK               (0xFFU)
#define FlexSPI_IPTXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill level of IP TX FIFO. */
#define FlexSPI_IPTXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPTXFSTS_FILL_SHIFT)) & FlexSPI_IPTXFSTS_FILL_MASK)

#define FlexSPI_IPTXFSTS_WRCNTR_MASK             (0xFFFF0000U)
#define FlexSPI_IPTXFSTS_WRCNTR_SHIFT            (16U)
/*! WRCNTR - Total Write Data Counter: WRCNTR * 64 Bits. */
#define FlexSPI_IPTXFSTS_WRCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FlexSPI_IPTXFSTS_WRCNTR_SHIFT)) & FlexSPI_IPTXFSTS_WRCNTR_MASK)
/*! @} */

/*! @name RFDR - IP RX FIFO Data Register 0..IP RX FIFO Data Register 31 */
/*! @{ */

#define FlexSPI_RFDR_RXDATA_MASK                 (0xFFFFFFFFU)
#define FlexSPI_RFDR_RXDATA_SHIFT                (0U)
/*! RXDATA - RX Data */
#define FlexSPI_RFDR_RXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_RFDR_RXDATA_SHIFT)) & FlexSPI_RFDR_RXDATA_MASK)
/*! @} */

/*! @name TFDR - IP TX FIFO Data Register 0..IP TX FIFO Data Register 31 */
/*! @{ */

#define FlexSPI_TFDR_TXDATA_MASK                 (0xFFFFFFFFU)
#define FlexSPI_TFDR_TXDATA_SHIFT                (0U)
/*! TXDATA - TX Data */
#define FlexSPI_TFDR_TXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_TFDR_TXDATA_SHIFT)) & FlexSPI_TFDR_TXDATA_MASK)
/*! @} */

/*! @name LUT - LUT 0..LUT 127 */
/*! @{ */

#define FlexSPI_LUT_OPERAND0_MASK                (0xFFU)
#define FlexSPI_LUT_OPERAND0_SHIFT               (0U)
/*! OPERAND0 - OPERAND0 */
#define FlexSPI_LUT_OPERAND0(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_OPERAND0_SHIFT)) & FlexSPI_LUT_OPERAND0_MASK)

#define FlexSPI_LUT_NUM_PADS0_MASK               (0x300U)
#define FlexSPI_LUT_NUM_PADS0_SHIFT              (8U)
/*! NUM_PADS0 - NUM_PADS0 */
#define FlexSPI_LUT_NUM_PADS0(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_NUM_PADS0_SHIFT)) & FlexSPI_LUT_NUM_PADS0_MASK)

#define FlexSPI_LUT_OPCODE0_MASK                 (0xFC00U)
#define FlexSPI_LUT_OPCODE0_SHIFT                (10U)
/*! OPCODE0 - OPCODE */
#define FlexSPI_LUT_OPCODE0(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_OPCODE0_SHIFT)) & FlexSPI_LUT_OPCODE0_MASK)

#define FlexSPI_LUT_OPERAND1_MASK                (0xFF0000U)
#define FlexSPI_LUT_OPERAND1_SHIFT               (16U)
/*! OPERAND1 - OPERAND1 */
#define FlexSPI_LUT_OPERAND1(x)                  (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_OPERAND1_SHIFT)) & FlexSPI_LUT_OPERAND1_MASK)

#define FlexSPI_LUT_NUM_PADS1_MASK               (0x3000000U)
#define FlexSPI_LUT_NUM_PADS1_SHIFT              (24U)
/*! NUM_PADS1 - NUM_PADS1 */
#define FlexSPI_LUT_NUM_PADS1(x)                 (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_NUM_PADS1_SHIFT)) & FlexSPI_LUT_NUM_PADS1_MASK)

#define FlexSPI_LUT_OPCODE1_MASK                 (0xFC000000U)
#define FlexSPI_LUT_OPCODE1_SHIFT                (26U)
/*! OPCODE1 - OPCODE1 */
#define FlexSPI_LUT_OPCODE1(x)                   (((uint32_t)(((uint32_t)(x)) << FlexSPI_LUT_OPCODE1_SHIFT)) & FlexSPI_LUT_OPCODE1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FlexSPI_Register_Masks */


/*!
 * @}
 */ /* end of group FlexSPI_Peripheral_Access_Layer */


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


#endif  /* PERI_FLEXSPI_H_ */

