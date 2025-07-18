/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLEXSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLEXSPI.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLEXSPI
 *
 * CMSIS Peripheral Access Layer for FLEXSPI
 */

#if !defined(PERI_FLEXSPI_H_)
#define PERI_FLEXSPI_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- FLEXSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_Peripheral_Access_Layer FLEXSPI Peripheral Access Layer
 * @{
 */

/** FLEXSPI - Size of Registers Arrays */
#define FLEXSPI_AHBRXBUFCR0_COUNT                 8u
#define FLEXSPI_FLSHCR0_COUNT                     4u
#define FLEXSPI_FLSHCR1_COUNT                     4u
#define FLEXSPI_FLSHCR2_COUNT                     4u
#define FLEXSPI_DLLCR_COUNT                       2u
#define FLEXSPI_RFDR_COUNT                        32u
#define FLEXSPI_TFDR_COUNT                        32u
#define FLEXSPI_LUT_COUNT                         64u

/** FLEXSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR0;                              /**< Module Control Register 0, offset: 0x0 */
  __IO uint32_t MCR1;                              /**< Module Control Register 1, offset: 0x4 */
  __IO uint32_t MCR2;                              /**< Module Control Register 2, offset: 0x8 */
  __IO uint32_t AHBCR;                             /**< AHB Bus Control Register, offset: 0xC */
  __IO uint32_t INTEN;                             /**< Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t INTR;                              /**< Interrupt Register, offset: 0x14 */
  __IO uint32_t LUTKEY;                            /**< LUT Key Register, offset: 0x18 */
  __IO uint32_t LUTCR;                             /**< LUT Control Register, offset: 0x1C */
  __IO uint32_t AHBRXBUFCR0[FLEXSPI_AHBRXBUFCR0_COUNT]; /**< AHB RX Buffer 0 Control Register 0..AHB RX Buffer 7 Control Register 0, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_0[32];
  __IO uint32_t FLSHCR0[FLEXSPI_FLSHCR0_COUNT];    /**< Flash Control Register 0, array offset: 0x60, array step: 0x4 */
  __IO uint32_t FLSHCR1[FLEXSPI_FLSHCR1_COUNT];    /**< Flash Control Register 1, array offset: 0x70, array step: 0x4 */
  __IO uint32_t FLSHCR2[FLEXSPI_FLSHCR2_COUNT];    /**< Flash Control Register 2, array offset: 0x80, array step: 0x4 */
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
  __IO uint32_t DLLCR[FLEXSPI_DLLCR_COUNT];        /**< DLL Control Register 0, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_4[24];
  __I  uint32_t STS0;                              /**< Status Register 0, offset: 0xE0 */
  __I  uint32_t STS1;                              /**< Status Register 1, offset: 0xE4 */
  __I  uint32_t STS2;                              /**< Status Register 2, offset: 0xE8 */
  __I  uint32_t AHBSPNDSTS;                        /**< AHB Suspend Status Register, offset: 0xEC */
  __I  uint32_t IPRXFSTS;                          /**< IP RX FIFO Status Register, offset: 0xF0 */
  __I  uint32_t IPTXFSTS;                          /**< IP TX FIFO Status Register, offset: 0xF4 */
       uint8_t RESERVED_5[8];
  __I  uint32_t RFDR[FLEXSPI_RFDR_COUNT];          /**< IP RX FIFO Data Register 0..IP RX FIFO Data Register 31, array offset: 0x100, array step: 0x4 */
  __O  uint32_t TFDR[FLEXSPI_TFDR_COUNT];          /**< IP TX FIFO Data Register 0..IP TX FIFO Data Register 31, array offset: 0x180, array step: 0x4 */
  __IO uint32_t LUT[FLEXSPI_LUT_COUNT];            /**< LUT 0..LUT 63, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_6[288];
  __IO uint32_t HADDRSTART;                        /**< HADDR REMAP START ADDR, offset: 0x420, available only on: FLEXSPI0 (missing on FLEXSPI1) */
  __IO uint32_t HADDREND;                          /**< HADDR REMAP END ADDR, offset: 0x424, available only on: FLEXSPI0 (missing on FLEXSPI1) */
  __IO uint32_t HADDROFFSET;                       /**< HADDR REMAP OFFSET, offset: 0x428, available only on: FLEXSPI0 (missing on FLEXSPI1) */
} FLEXSPI_Type;

/* ----------------------------------------------------------------------------
   -- FLEXSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLEXSPI_Register_Masks FLEXSPI Register Masks
 * @{
 */

/*! @name MCR0 - Module Control Register 0 */
/*! @{ */

#define FLEXSPI_MCR0_SWRESET_MASK                (0x1U)
#define FLEXSPI_MCR0_SWRESET_SHIFT               (0U)
/*! SWRESET - Software Reset
 *  0b0..No impact
 *  0b1..Software reset
 */
#define FLEXSPI_MCR0_SWRESET(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SWRESET_SHIFT)) & FLEXSPI_MCR0_SWRESET_MASK)

#define FLEXSPI_MCR0_MDIS_MASK                   (0x2U)
#define FLEXSPI_MCR0_MDIS_SHIFT                  (1U)
/*! MDIS - Module Disable
 *  0b0..No impact
 *  0b1..Module disable
 */
#define FLEXSPI_MCR0_MDIS(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_MDIS_SHIFT)) & FLEXSPI_MCR0_MDIS_MASK)

#define FLEXSPI_MCR0_RXCLKSRC_MASK               (0x30U)
#define FLEXSPI_MCR0_RXCLKSRC_SHIFT              (4U)
/*! RXCLKSRC - Sample Clock source selection for Flash Reading
 *  0b00..Dummy Read strobe generated by FlexSPI Controller and loopback internally.
 *  0b01..Dummy Read strobe generated by FlexSPI Controller and loopback from DQS pad.
 *  0b10..Reserved
 *  0b11..Flash provided Read strobe and input from DQS pad
 */
#define FLEXSPI_MCR0_RXCLKSRC(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_RXCLKSRC_SHIFT)) & FLEXSPI_MCR0_RXCLKSRC_MASK)

#define FLEXSPI_MCR0_SERCLKDIV_MASK              (0x700U)
#define FLEXSPI_MCR0_SERCLKDIV_SHIFT             (8U)
/*! SERCLKDIV - Serial root clock
 *  0b000..Divided by 1
 *  0b001..Divided by 2
 *  0b010..Divided by 3
 *  0b011..Divided by 4
 *  0b100..Divided by 5
 *  0b101..Divided by 6
 *  0b110..Divided by 7
 *  0b111..Divided by 8
 */
#define FLEXSPI_MCR0_SERCLKDIV(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SERCLKDIV_SHIFT)) & FLEXSPI_MCR0_SERCLKDIV_MASK)

#define FLEXSPI_MCR0_HSEN_MASK                   (0x800U)
#define FLEXSPI_MCR0_HSEN_SHIFT                  (11U)
/*! HSEN - Half Speed Serial Flash Access Enable.
 *  0b0..Disable divide by 2 of serial flash clock for half clock frequency.
 *  0b1..Enable divide by 2 of serial flash clock for half clock frequency.
 */
#define FLEXSPI_MCR0_HSEN(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_HSEN_SHIFT)) & FLEXSPI_MCR0_HSEN_MASK)

#define FLEXSPI_MCR0_DOZEEN_MASK                 (0x1000U)
#define FLEXSPI_MCR0_DOZEEN_SHIFT                (12U)
/*! DOZEEN - Doze mode enable bit
 *  0b0..Doze mode support disabled. AHB clock and serial clock will not be gated off when there is doze mode request from system.
 *  0b1..Doze mode support enabled. AHB clock and serial clock will be gated off when there is doze mode request from system.
 */
#define FLEXSPI_MCR0_DOZEEN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_DOZEEN_SHIFT)) & FLEXSPI_MCR0_DOZEEN_MASK)

#define FLEXSPI_MCR0_SCKFREERUNEN_MASK           (0x4000U)
#define FLEXSPI_MCR0_SCKFREERUNEN_SHIFT          (14U)
/*! SCKFREERUNEN - This bit is used to enable SCLK output free-running. For FPGA applications, the
 *    external device may use SCLK as reference clock to its internal PLL.
 *  0b0..Disable SCLK output free-running.
 *  0b1..Enable SCLK output free-running.
 */
#define FLEXSPI_MCR0_SCKFREERUNEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_SCKFREERUNEN_SHIFT)) & FLEXSPI_MCR0_SCKFREERUNEN_MASK)

#define FLEXSPI_MCR0_LEARNEN_MASK                (0x8000U)
#define FLEXSPI_MCR0_LEARNEN_SHIFT               (15U)
/*! LEARNEN - This bit is used to enable/disable the data learning feature.
 *  0b0..Disable the data learning feature.
 *  0b1..Enable the data learning feature.
 */
#define FLEXSPI_MCR0_LEARNEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_LEARNEN_SHIFT)) & FLEXSPI_MCR0_LEARNEN_MASK)

#define FLEXSPI_MCR0_IPGRANTWAIT_MASK            (0xFF0000U)
#define FLEXSPI_MCR0_IPGRANTWAIT_SHIFT           (16U)
/*! IPGRANTWAIT - Timeout wait cycle for IP command grant. */
#define FLEXSPI_MCR0_IPGRANTWAIT(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_IPGRANTWAIT_SHIFT)) & FLEXSPI_MCR0_IPGRANTWAIT_MASK)

#define FLEXSPI_MCR0_AHBGRANTWAIT_MASK           (0xFF000000U)
#define FLEXSPI_MCR0_AHBGRANTWAIT_SHIFT          (24U)
/*! AHBGRANTWAIT - Timeout wait cycle for AHB command grant. */
#define FLEXSPI_MCR0_AHBGRANTWAIT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR0_AHBGRANTWAIT_SHIFT)) & FLEXSPI_MCR0_AHBGRANTWAIT_MASK)
/*! @} */

/*! @name MCR1 - Module Control Register 1 */
/*! @{ */

#define FLEXSPI_MCR1_AHBBUSWAIT_MASK             (0xFFFFU)
#define FLEXSPI_MCR1_AHBBUSWAIT_SHIFT            (0U)
/*! AHBBUSWAIT - AHB Bus wait */
#define FLEXSPI_MCR1_AHBBUSWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR1_AHBBUSWAIT_SHIFT)) & FLEXSPI_MCR1_AHBBUSWAIT_MASK)

#define FLEXSPI_MCR1_SEQWAIT_MASK                (0xFFFF0000U)
#define FLEXSPI_MCR1_SEQWAIT_SHIFT               (16U)
/*! SEQWAIT - Command Sequence Execution will timeout and abort after SEQWAIT * 1024 Serial Root
 *    Clock cycles. When sequence execution timeout occurs, there will be an interrupt generated
 *    (INTR[SEQTIMEOUT]) if this interrupt is enabled (INTEN[SEQTIMEOUTEN] is set 0x1) and AHB command is
 *    ignored by arbitrator.
 */
#define FLEXSPI_MCR1_SEQWAIT(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR1_SEQWAIT_SHIFT)) & FLEXSPI_MCR1_SEQWAIT_MASK)
/*! @} */

/*! @name MCR2 - Module Control Register 2 */
/*! @{ */

#define FLEXSPI_MCR2_CLRAHBBUFOPT_MASK           (0x800U)
#define FLEXSPI_MCR2_CLRAHBBUFOPT_SHIFT          (11U)
/*! CLRAHBBUFOPT - Clear AHB buffer
 *  0b0..AHB RX/TX Buffer will not be cleared automatically when FlexSPI returns Stop mode ACK.
 *  0b1..AHB RX/TX Buffer will be cleared automatically when FlexSPI returns Stop mode ACK.
 */
#define FLEXSPI_MCR2_CLRAHBBUFOPT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_CLRAHBBUFOPT_SHIFT)) & FLEXSPI_MCR2_CLRAHBBUFOPT_MASK)

#define FLEXSPI_MCR2_CLRLEARNPHASE_MASK          (0x4000U)
#define FLEXSPI_MCR2_CLRLEARNPHASE_SHIFT         (14U)
/*! CLRLEARNPHASE - The sampling clock phase selection will be reset to phase 0 when this bit is
 *    written with 0x1. This bit will be auto-cleared immediately.
 *  0b0..No impact
 *  0b1..The sampling clock phase selection will be reset to phase 0 when this bit is written with 0x1. This bit will be auto-cleared immediately.
 */
#define FLEXSPI_MCR2_CLRLEARNPHASE(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_CLRLEARNPHASE_SHIFT)) & FLEXSPI_MCR2_CLRLEARNPHASE_MASK)

#define FLEXSPI_MCR2_SAMEDEVICEEN_MASK           (0x8000U)
#define FLEXSPI_MCR2_SAMEDEVICEEN_SHIFT          (15U)
/*! SAMEDEVICEEN - All external devices are same devices (both in type and size) for A1/A2/B1/B2.
 *  0b0..In Individual mode, FLSHA1CRx/FLSHA2CRx/FLSHB1CRx/FLSHB2CRx register setting will be applied to Flash
 *       A1/A2/B1/B2 separately. In Parallel mode, FLSHA1CRx register setting will be applied to Flash A1 and B1,
 *       FLSHA2CRx register setting will be applied to Flash A2 and B2. FLSHB1CRx/FLSHB2CRx register setting will be
 *       ignored.
 *  0b1..FLSHA1CR0/FLSHA1CR1/FLSHA1CR2 register setting will be applied to Flash A1/A2/B1/B2. FLSHA2CRx/FLSHB1CRx/FLSHB2CRx will be ignored.
 */
#define FLEXSPI_MCR2_SAMEDEVICEEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_SAMEDEVICEEN_SHIFT)) & FLEXSPI_MCR2_SAMEDEVICEEN_MASK)

#define FLEXSPI_MCR2_RESUMEWAIT_MASK             (0xFF000000U)
#define FLEXSPI_MCR2_RESUMEWAIT_SHIFT            (24U)
/*! RESUMEWAIT - Wait cycle (in AHB clock cycle) for idle state before suspended command sequence resumed. */
#define FLEXSPI_MCR2_RESUMEWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_MCR2_RESUMEWAIT_SHIFT)) & FLEXSPI_MCR2_RESUMEWAIT_MASK)
/*! @} */

/*! @name AHBCR - AHB Bus Control Register */
/*! @{ */

#define FLEXSPI_AHBCR_APAREN_MASK                (0x1U)
#define FLEXSPI_AHBCR_APAREN_SHIFT               (0U)
/*! APAREN - Parallel mode enabled for AHB triggered Command (both read and write).
 *  0b0..Flash will be accessed in Individual mode.
 *  0b1..Flash will be accessed in Parallel mode.
 */
#define FLEXSPI_AHBCR_APAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_APAREN_SHIFT)) & FLEXSPI_AHBCR_APAREN_MASK)

#define FLEXSPI_AHBCR_CLRAHBTXBUF_MASK           (0x4U)
#define FLEXSPI_AHBCR_CLRAHBTXBUF_SHIFT          (2U)
/*! CLRAHBTXBUF - Clear the status/pointers of AHB TX Buffer. Auto-cleared.
 *  0b0..No function.
 *  0b1..Clear operation enable.
 */
#define FLEXSPI_AHBCR_CLRAHBTXBUF(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_CLRAHBTXBUF_SHIFT)) & FLEXSPI_AHBCR_CLRAHBTXBUF_MASK)

#define FLEXSPI_AHBCR_CACHABLEEN_MASK            (0x8U)
#define FLEXSPI_AHBCR_CACHABLEEN_SHIFT           (3U)
/*! CACHABLEEN - Enable AHB bus cachable read access support.
 *  0b0..Disabled. When there is AHB bus cachable read access, FlexSPI will not check whether it hit AHB TX Buffer.
 *  0b1..Enabled. When there is AHB bus cachable read access, FlexSPI will check whether it hit AHB TX Buffer first.
 */
#define FLEXSPI_AHBCR_CACHABLEEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_CACHABLEEN_SHIFT)) & FLEXSPI_AHBCR_CACHABLEEN_MASK)

#define FLEXSPI_AHBCR_BUFFERABLEEN_MASK          (0x10U)
#define FLEXSPI_AHBCR_BUFFERABLEEN_SHIFT         (4U)
/*! BUFFERABLEEN - Enable AHB bus bufferable write access support.
 *  0b0..Disabled. For all AHB write accesses (bufferable or non-bufferable), FlexSPI will return AHB Bus ready
 *       after all data is transmitted to external device and AHB command finished.
 *  0b1..Enabled. For AHB bufferable write access, FlexSPI will return AHB Bus ready when the AHB command is
 *       granted by arbitrator and will not wait for AHB command finished.
 */
#define FLEXSPI_AHBCR_BUFFERABLEEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_BUFFERABLEEN_SHIFT)) & FLEXSPI_AHBCR_BUFFERABLEEN_MASK)

#define FLEXSPI_AHBCR_PREFETCHEN_MASK            (0x20U)
#define FLEXSPI_AHBCR_PREFETCHEN_SHIFT           (5U)
/*! PREFETCHEN - AHB Read Prefetch Enable. */
#define FLEXSPI_AHBCR_PREFETCHEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_PREFETCHEN_SHIFT)) & FLEXSPI_AHBCR_PREFETCHEN_MASK)

#define FLEXSPI_AHBCR_READADDROPT_MASK           (0x40U)
#define FLEXSPI_AHBCR_READADDROPT_SHIFT          (6U)
/*! READADDROPT - AHB Read Address option bit. This option bit is intended to remove AHB burst start address alignment limitation.
 *  0b0..There is AHB read burst start address alignment limitation when flash is accessed in parallel mode or flash is word-addressable.
 *  0b1..There is no AHB read burst start address alignment limitation. FlexSPI will fetch more data than AHB
 *       burst required to meet the alignment requirement.
 */
#define FLEXSPI_AHBCR_READADDROPT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_READADDROPT_SHIFT)) & FLEXSPI_AHBCR_READADDROPT_MASK)

#define FLEXSPI_AHBCR_RESUMEDISABLE_MASK         (0x80U)
#define FLEXSPI_AHBCR_RESUMEDISABLE_SHIFT        (7U)
/*! RESUMEDISABLE - AHB Read Resume Disable
 *  0b0..Suspended AHB read prefetch will start to resume when AHB is IDLE
 *  0b1..Suspended AHB read prefetch will not resume once it is aborted
 */
#define FLEXSPI_AHBCR_RESUMEDISABLE(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_RESUMEDISABLE_SHIFT)) & FLEXSPI_AHBCR_RESUMEDISABLE_MASK)

#define FLEXSPI_AHBCR_READSZALIGN_MASK           (0x400U)
#define FLEXSPI_AHBCR_READSZALIGN_SHIFT          (10U)
/*! READSZALIGN - AHB Read Size Alignment
 *  0b0..AHB read size will be decided by other register setting like PREFETCH_EN,OTFAD_EN...
 *  0b1..AHB read size to up size to 8 bytes aligned, no prefetching
 */
#define FLEXSPI_AHBCR_READSZALIGN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBCR_READSZALIGN_SHIFT)) & FLEXSPI_AHBCR_READSZALIGN_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable Register */
/*! @{ */

#define FLEXSPI_INTEN_IPCMDDONEEN_MASK           (0x1U)
#define FLEXSPI_INTEN_IPCMDDONEEN_SHIFT          (0U)
/*! IPCMDDONEEN - IP triggered Command Sequences Execution finished interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDDONEEN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDDONEEN_SHIFT)) & FLEXSPI_INTEN_IPCMDDONEEN_MASK)

#define FLEXSPI_INTEN_IPCMDGEEN_MASK             (0x2U)
#define FLEXSPI_INTEN_IPCMDGEEN_SHIFT            (1U)
/*! IPCMDGEEN - IP triggered Command Sequences Grant Timeout interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDGEEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDGEEN_SHIFT)) & FLEXSPI_INTEN_IPCMDGEEN_MASK)

#define FLEXSPI_INTEN_AHBCMDGEEN_MASK            (0x4U)
#define FLEXSPI_INTEN_AHBCMDGEEN_SHIFT           (2U)
/*! AHBCMDGEEN - AHB triggered Command Sequences Grant Timeout interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBCMDGEEN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBCMDGEEN_SHIFT)) & FLEXSPI_INTEN_AHBCMDGEEN_MASK)

#define FLEXSPI_INTEN_IPCMDERREN_MASK            (0x8U)
#define FLEXSPI_INTEN_IPCMDERREN_SHIFT           (3U)
/*! IPCMDERREN - IP triggered Command Sequences Error Detected interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPCMDERREN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPCMDERREN_SHIFT)) & FLEXSPI_INTEN_IPCMDERREN_MASK)

#define FLEXSPI_INTEN_AHBCMDERREN_MASK           (0x10U)
#define FLEXSPI_INTEN_AHBCMDERREN_SHIFT          (4U)
/*! AHBCMDERREN - AHB triggered Command Sequences Error Detected interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBCMDERREN(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBCMDERREN_SHIFT)) & FLEXSPI_INTEN_AHBCMDERREN_MASK)

#define FLEXSPI_INTEN_IPRXWAEN_MASK              (0x20U)
#define FLEXSPI_INTEN_IPRXWAEN_SHIFT             (5U)
/*! IPRXWAEN - IP RX FIFO WaterMark available interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPRXWAEN(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPRXWAEN_SHIFT)) & FLEXSPI_INTEN_IPRXWAEN_MASK)

#define FLEXSPI_INTEN_IPTXWEEN_MASK              (0x40U)
#define FLEXSPI_INTEN_IPTXWEEN_SHIFT             (6U)
/*! IPTXWEEN - IP TX FIFO WaterMark empty interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_IPTXWEEN(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_IPTXWEEN_SHIFT)) & FLEXSPI_INTEN_IPTXWEEN_MASK)

#define FLEXSPI_INTEN_DATALEARNFAILEN_MASK       (0x80U)
#define FLEXSPI_INTEN_DATALEARNFAILEN_SHIFT      (7U)
/*! DATALEARNFAILEN - Data Learning failed interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_DATALEARNFAILEN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_DATALEARNFAILEN_SHIFT)) & FLEXSPI_INTEN_DATALEARNFAILEN_MASK)

#define FLEXSPI_INTEN_SCKSTOPBYRDEN_MASK         (0x100U)
#define FLEXSPI_INTEN_SCKSTOPBYRDEN_SHIFT        (8U)
/*! SCKSTOPBYRDEN - SCLK is stopped during command sequence because Async RX FIFO full interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SCKSTOPBYRDEN(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SCKSTOPBYRDEN_SHIFT)) & FLEXSPI_INTEN_SCKSTOPBYRDEN_MASK)

#define FLEXSPI_INTEN_SCKSTOPBYWREN_MASK         (0x200U)
#define FLEXSPI_INTEN_SCKSTOPBYWREN_SHIFT        (9U)
/*! SCKSTOPBYWREN - SCLK is stopped during command sequence because Async TX FIFO empty interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SCKSTOPBYWREN(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SCKSTOPBYWREN_SHIFT)) & FLEXSPI_INTEN_SCKSTOPBYWREN_MASK)

#define FLEXSPI_INTEN_AHBBUSERROREN_MASK         (0x400U)
#define FLEXSPI_INTEN_AHBBUSERROREN_SHIFT        (10U)
/*! AHBBUSERROREN - AHB Bus error interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBBUSERROREN(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBBUSERROREN_SHIFT)) & FLEXSPI_INTEN_AHBBUSERROREN_MASK)

#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN_MASK       (0x400U)
#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT      (10U)
/*! AHBBUSTIMEOUTEN - AHB Bus timeout interrupt.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_AHBBUSTIMEOUTEN(x)         (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_AHBBUSTIMEOUTEN_SHIFT)) & FLEXSPI_INTEN_AHBBUSTIMEOUTEN_MASK)

#define FLEXSPI_INTEN_SEQTIMEOUTEN_MASK          (0x800U)
#define FLEXSPI_INTEN_SEQTIMEOUTEN_SHIFT         (11U)
/*! SEQTIMEOUTEN - Sequence execution timeout interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_SEQTIMEOUTEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_SEQTIMEOUTEN_SHIFT)) & FLEXSPI_INTEN_SEQTIMEOUTEN_MASK)

#define FLEXSPI_INTEN_KEYDONEEN_MASK             (0x1000U)
#define FLEXSPI_INTEN_KEYDONEEN_SHIFT            (12U)
/*! KEYDONEEN - OTFAD key blob processing done interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_KEYDONEEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_KEYDONEEN_SHIFT)) & FLEXSPI_INTEN_KEYDONEEN_MASK)

#define FLEXSPI_INTEN_KEYERROREN_MASK            (0x2000U)
#define FLEXSPI_INTEN_KEYERROREN_SHIFT           (13U)
/*! KEYERROREN - OTFAD key blob processing error interrupt enable.
 *  0b0..Disable interrupt or no impact
 *  0b1..Enable interrupt
 */
#define FLEXSPI_INTEN_KEYERROREN(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTEN_KEYERROREN_SHIFT)) & FLEXSPI_INTEN_KEYERROREN_MASK)
/*! @} */

/*! @name INTR - Interrupt Register */
/*! @{ */

#define FLEXSPI_INTR_IPCMDDONE_MASK              (0x1U)
#define FLEXSPI_INTR_IPCMDDONE_SHIFT             (0U)
/*! IPCMDDONE - IP triggered Command Sequences Execution finished interrupt. This interrupt is also
 *    generated when there is IPCMDGE or IPCMDERR interrupt generated.
 */
#define FLEXSPI_INTR_IPCMDDONE(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDDONE_SHIFT)) & FLEXSPI_INTR_IPCMDDONE_MASK)

#define FLEXSPI_INTR_IPCMDGE_MASK                (0x2U)
#define FLEXSPI_INTR_IPCMDGE_SHIFT               (1U)
/*! IPCMDGE - IP triggered Command Sequences Grant Timeout interrupt. */
#define FLEXSPI_INTR_IPCMDGE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDGE_SHIFT)) & FLEXSPI_INTR_IPCMDGE_MASK)

#define FLEXSPI_INTR_AHBCMDGE_MASK               (0x4U)
#define FLEXSPI_INTR_AHBCMDGE_SHIFT              (2U)
/*! AHBCMDGE - AHB triggered Command Sequences Grant Timeout interrupt. */
#define FLEXSPI_INTR_AHBCMDGE(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBCMDGE_SHIFT)) & FLEXSPI_INTR_AHBCMDGE_MASK)

#define FLEXSPI_INTR_IPCMDERR_MASK               (0x8U)
#define FLEXSPI_INTR_IPCMDERR_SHIFT              (3U)
/*! IPCMDERR - IP triggered Command Sequences Error Detected interrupt. When an error detected for
 *    IP command, this command will be ignored and not executed at all.
 */
#define FLEXSPI_INTR_IPCMDERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPCMDERR_SHIFT)) & FLEXSPI_INTR_IPCMDERR_MASK)

#define FLEXSPI_INTR_AHBCMDERR_MASK              (0x10U)
#define FLEXSPI_INTR_AHBCMDERR_SHIFT             (4U)
/*! AHBCMDERR - AHB triggered Command Sequences Error Detected interrupt. When an error detected for
 *    AHB command, this command will be ignored and not executed at all.
 */
#define FLEXSPI_INTR_AHBCMDERR(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBCMDERR_SHIFT)) & FLEXSPI_INTR_AHBCMDERR_MASK)

#define FLEXSPI_INTR_IPRXWA_MASK                 (0x20U)
#define FLEXSPI_INTR_IPRXWA_SHIFT                (5U)
/*! IPRXWA - IP RX FIFO watermark available interrupt. */
#define FLEXSPI_INTR_IPRXWA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPRXWA_SHIFT)) & FLEXSPI_INTR_IPRXWA_MASK)

#define FLEXSPI_INTR_IPTXWE_MASK                 (0x40U)
#define FLEXSPI_INTR_IPTXWE_SHIFT                (6U)
/*! IPTXWE - IP TX FIFO watermark empty interrupt. */
#define FLEXSPI_INTR_IPTXWE(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_IPTXWE_SHIFT)) & FLEXSPI_INTR_IPTXWE_MASK)

#define FLEXSPI_INTR_DATALEARNFAIL_MASK          (0x80U)
#define FLEXSPI_INTR_DATALEARNFAIL_SHIFT         (7U)
/*! DATALEARNFAIL - Data Learning failed interrupt. */
#define FLEXSPI_INTR_DATALEARNFAIL(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_DATALEARNFAIL_SHIFT)) & FLEXSPI_INTR_DATALEARNFAIL_MASK)

#define FLEXSPI_INTR_SCKSTOPBYRD_MASK            (0x100U)
#define FLEXSPI_INTR_SCKSTOPBYRD_SHIFT           (8U)
/*! SCKSTOPBYRD - SCLK is stopped during command sequence because Async RX FIFO full interrupt. */
#define FLEXSPI_INTR_SCKSTOPBYRD(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SCKSTOPBYRD_SHIFT)) & FLEXSPI_INTR_SCKSTOPBYRD_MASK)

#define FLEXSPI_INTR_SCKSTOPBYWR_MASK            (0x200U)
#define FLEXSPI_INTR_SCKSTOPBYWR_SHIFT           (9U)
/*! SCKSTOPBYWR - SCLK is stopped during command sequence because Async TX FIFO empty interrupt. */
#define FLEXSPI_INTR_SCKSTOPBYWR(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SCKSTOPBYWR_SHIFT)) & FLEXSPI_INTR_SCKSTOPBYWR_MASK)

#define FLEXSPI_INTR_AHBBUSERROR_MASK            (0x400U)
#define FLEXSPI_INTR_AHBBUSERROR_SHIFT           (10U)
/*! AHBBUSERROR - AHB Bus timeout or AHB bus illegal access Flash during OTFAD key blob processing interrupt. */
#define FLEXSPI_INTR_AHBBUSERROR(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBBUSERROR_SHIFT)) & FLEXSPI_INTR_AHBBUSERROR_MASK)

#define FLEXSPI_INTR_AHBBUSTIMEOUT_MASK          (0x400U)
#define FLEXSPI_INTR_AHBBUSTIMEOUT_SHIFT         (10U)
/*! AHBBUSTIMEOUT - AHB Bus timeout interrupt. */
#define FLEXSPI_INTR_AHBBUSTIMEOUT(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_AHBBUSTIMEOUT_SHIFT)) & FLEXSPI_INTR_AHBBUSTIMEOUT_MASK)

#define FLEXSPI_INTR_SEQTIMEOUT_MASK             (0x800U)
#define FLEXSPI_INTR_SEQTIMEOUT_SHIFT            (11U)
/*! SEQTIMEOUT - Sequence execution timeout interrupt. */
#define FLEXSPI_INTR_SEQTIMEOUT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_SEQTIMEOUT_SHIFT)) & FLEXSPI_INTR_SEQTIMEOUT_MASK)

#define FLEXSPI_INTR_KEYDONE_MASK                (0x1000U)
#define FLEXSPI_INTR_KEYDONE_SHIFT               (12U)
/*! KEYDONE - OTFAD key blob processing done interrupt. */
#define FLEXSPI_INTR_KEYDONE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_KEYDONE_SHIFT)) & FLEXSPI_INTR_KEYDONE_MASK)

#define FLEXSPI_INTR_KEYERROR_MASK               (0x2000U)
#define FLEXSPI_INTR_KEYERROR_SHIFT              (13U)
/*! KEYERROR - OTFAD key blob processing error interrupt. */
#define FLEXSPI_INTR_KEYERROR(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_INTR_KEYERROR_SHIFT)) & FLEXSPI_INTR_KEYERROR_MASK)
/*! @} */

/*! @name LUTKEY - LUT Key Register */
/*! @{ */

#define FLEXSPI_LUTKEY_KEY_MASK                  (0xFFFFFFFFU)
#define FLEXSPI_LUTKEY_KEY_SHIFT                 (0U)
/*! KEY - The Key to lock or unlock LUT. */
#define FLEXSPI_LUTKEY_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTKEY_KEY_SHIFT)) & FLEXSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LUTCR - LUT Control Register */
/*! @{ */

#define FLEXSPI_LUTCR_LOCK_MASK                  (0x1U)
#define FLEXSPI_LUTCR_LOCK_SHIFT                 (0U)
/*! LOCK - Lock LUT
 *  0b0..No impact
 *  0b1..Lock LUT, LUT will be locked and can't be written
 */
#define FLEXSPI_LUTCR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTCR_LOCK_SHIFT)) & FLEXSPI_LUTCR_LOCK_MASK)

#define FLEXSPI_LUTCR_UNLOCK_MASK                (0x2U)
#define FLEXSPI_LUTCR_UNLOCK_SHIFT               (1U)
/*! UNLOCK - Unlock LUT
 *  0b0..No impact
 *  0b1..Unlock LUT, the LUT can be written
 */
#define FLEXSPI_LUTCR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUTCR_UNLOCK_SHIFT)) & FLEXSPI_LUTCR_UNLOCK_MASK)
/*! @} */

/*! @name AHBRXBUFCR0 - AHB RX Buffer 0 Control Register 0..AHB RX Buffer 7 Control Register 0 */
/*! @{ */

#define FLEXSPI_AHBRXBUFCR0_BUFSZ_MASK           (0x1FFU)  /* Merged from fields with different position or width, of widths (8, 9), largest definition used */
#define FLEXSPI_AHBRXBUFCR0_BUFSZ_SHIFT          (0U)
/*! BUFSZ - AHB RX Buffer Size in 64 bits. */
#define FLEXSPI_AHBRXBUFCR0_BUFSZ(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_BUFSZ_SHIFT)) & FLEXSPI_AHBRXBUFCR0_BUFSZ_MASK)  /* Merged from fields with different position or width, of widths (8, 9), largest definition used */

#define FLEXSPI_AHBRXBUFCR0_MSTRID_MASK          (0xF0000U)
#define FLEXSPI_AHBRXBUFCR0_MSTRID_SHIFT         (16U)
/*! MSTRID - This AHB RX Buffer is assigned according to AHB Master with ID (MSTR_ID). */
#define FLEXSPI_AHBRXBUFCR0_MSTRID(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_MSTRID_SHIFT)) & FLEXSPI_AHBRXBUFCR0_MSTRID_MASK)

#define FLEXSPI_AHBRXBUFCR0_PRIORITY_MASK        (0x7000000U)
#define FLEXSPI_AHBRXBUFCR0_PRIORITY_SHIFT       (24U)
/*! PRIORITY - This priority for AHB Master Read which this AHB RX Buffer is assigned. 7 is the highest priority, 0 the lowest. */
#define FLEXSPI_AHBRXBUFCR0_PRIORITY(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_PRIORITY_SHIFT)) & FLEXSPI_AHBRXBUFCR0_PRIORITY_MASK)

#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN_MASK      (0x80000000U)
#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT     (31U)
/*! PREFETCHEN - AHB Read Prefetch Enable for current AHB RX Buffer corresponding Master.
 *  0b0..No prefetch
 *  0b1..Prefetch enable
 */
#define FLEXSPI_AHBRXBUFCR0_PREFETCHEN(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBRXBUFCR0_PREFETCHEN_SHIFT)) & FLEXSPI_AHBRXBUFCR0_PREFETCHEN_MASK)
/*! @} */

/*! @name FLSHCR0 - Flash Control Register 0 */
/*! @{ */

#define FLEXSPI_FLSHCR0_FLSHSZ_MASK              (0x7FFFFFU)
#define FLEXSPI_FLSHCR0_FLSHSZ_SHIFT             (0U)
/*! FLSHSZ - Flash Size in KByte. */
#define FLEXSPI_FLSHCR0_FLSHSZ(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR0_FLSHSZ_SHIFT)) & FLEXSPI_FLSHCR0_FLSHSZ_MASK)
/*! @} */

/*! @name FLSHCR1 - Flash Control Register 1 */
/*! @{ */

#define FLEXSPI_FLSHCR1_TCSS_MASK                (0x1FU)
#define FLEXSPI_FLSHCR1_TCSS_SHIFT               (0U)
/*! TCSS - Serial Flash CS setup time. */
#define FLEXSPI_FLSHCR1_TCSS(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_TCSS_SHIFT)) & FLEXSPI_FLSHCR1_TCSS_MASK)

#define FLEXSPI_FLSHCR1_TCSH_MASK                (0x3E0U)
#define FLEXSPI_FLSHCR1_TCSH_SHIFT               (5U)
/*! TCSH - Serial Flash CS Hold time. */
#define FLEXSPI_FLSHCR1_TCSH(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_TCSH_SHIFT)) & FLEXSPI_FLSHCR1_TCSH_MASK)

#define FLEXSPI_FLSHCR1_WA_MASK                  (0x400U)
#define FLEXSPI_FLSHCR1_WA_SHIFT                 (10U)
/*! WA - Word Addressable.
 *  0b0..This bit should be set as 0 when external Flash is byte addressable.
 *  0b1..This bit should be set as 1 when external Flash is word addressable. If Flash is word addressable, it
 *       should be accessed in terms of 16 bits. At this time, FlexSPI will not transmit Flash address bit 0 to
 *       external Flash.
 */
#define FLEXSPI_FLSHCR1_WA(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_WA_SHIFT)) & FLEXSPI_FLSHCR1_WA_MASK)

#define FLEXSPI_FLSHCR1_CAS_MASK                 (0x7800U)
#define FLEXSPI_FLSHCR1_CAS_SHIFT                (11U)
/*! CAS - Column Address Size. */
#define FLEXSPI_FLSHCR1_CAS(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CAS_SHIFT)) & FLEXSPI_FLSHCR1_CAS_MASK)

#define FLEXSPI_FLSHCR1_CSINTERVALUNIT_MASK      (0x8000U)
#define FLEXSPI_FLSHCR1_CSINTERVALUNIT_SHIFT     (15U)
/*! CSINTERVALUNIT - CS interval unit
 *  0b0..The CS interval unit is 1 serial clock cycle
 *  0b1..The CS interval unit is 256 serial clock cycle
 */
#define FLEXSPI_FLSHCR1_CSINTERVALUNIT(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CSINTERVALUNIT_SHIFT)) & FLEXSPI_FLSHCR1_CSINTERVALUNIT_MASK)

#define FLEXSPI_FLSHCR1_CSINTERVAL_MASK          (0xFFFF0000U)
#define FLEXSPI_FLSHCR1_CSINTERVAL_SHIFT         (16U)
/*! CSINTERVAL - This field is used to set the minimum interval between flash device chip select
 *    deassertion and flash device chip select assertion. If external flash has a limitation on the
 *    interval between command sequences, this field should be set accordingly. If there is no
 *    limitation, set this field with value 0x0.
 */
#define FLEXSPI_FLSHCR1_CSINTERVAL(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR1_CSINTERVAL_SHIFT)) & FLEXSPI_FLSHCR1_CSINTERVAL_MASK)
/*! @} */

/*! @name FLSHCR2 - Flash Control Register 2 */
/*! @{ */

#define FLEXSPI_FLSHCR2_ARDSEQID_MASK            (0xFU)
#define FLEXSPI_FLSHCR2_ARDSEQID_SHIFT           (0U)
/*! ARDSEQID - Sequence Index for AHB Read triggered Command in LUT. */
#define FLEXSPI_FLSHCR2_ARDSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_ARDSEQID_SHIFT)) & FLEXSPI_FLSHCR2_ARDSEQID_MASK)

#define FLEXSPI_FLSHCR2_ARDSEQNUM_MASK           (0xE0U)
#define FLEXSPI_FLSHCR2_ARDSEQNUM_SHIFT          (5U)
/*! ARDSEQNUM - Sequence Number for AHB Read triggered Command in LUT. */
#define FLEXSPI_FLSHCR2_ARDSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_ARDSEQNUM_SHIFT)) & FLEXSPI_FLSHCR2_ARDSEQNUM_MASK)

#define FLEXSPI_FLSHCR2_AWRSEQID_MASK            (0xF00U)
#define FLEXSPI_FLSHCR2_AWRSEQID_SHIFT           (8U)
/*! AWRSEQID - Sequence Index for AHB Write triggered Command. */
#define FLEXSPI_FLSHCR2_AWRSEQID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRSEQID_SHIFT)) & FLEXSPI_FLSHCR2_AWRSEQID_MASK)

#define FLEXSPI_FLSHCR2_AWRSEQNUM_MASK           (0xE000U)
#define FLEXSPI_FLSHCR2_AWRSEQNUM_SHIFT          (13U)
/*! AWRSEQNUM - Sequence Number for AHB Write triggered Command. */
#define FLEXSPI_FLSHCR2_AWRSEQNUM(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRSEQNUM_SHIFT)) & FLEXSPI_FLSHCR2_AWRSEQNUM_MASK)

#define FLEXSPI_FLSHCR2_AWRWAIT_MASK             (0xFFF0000U)
#define FLEXSPI_FLSHCR2_AWRWAIT_SHIFT            (16U)
/*! AWRWAIT - For certain devices (such as FPGA), it need some time to write data into internal
 *    memory after the command sequences finished on FlexSPI interface. If another Read command sequence
 *    comes before previous programming finished internally, the read data may be wrong. This field
 *    is used to hold AHB Bus ready for AHB write access to wait the programming finished in
 *    external device. Then there will be no AHB read command triggered before the programming finished in
 *    external device. The Wait cycle between AHB triggered command sequences finished on FlexSPI
 *    interface and AHB return Bus ready: AWRWAIT * AWRWAITUNIT
 */
#define FLEXSPI_FLSHCR2_AWRWAIT(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRWAIT_SHIFT)) & FLEXSPI_FLSHCR2_AWRWAIT_MASK)

#define FLEXSPI_FLSHCR2_AWRWAITUNIT_MASK         (0x70000000U)
#define FLEXSPI_FLSHCR2_AWRWAITUNIT_SHIFT        (28U)
/*! AWRWAITUNIT - AWRWAIT unit
 *  0b000..The AWRWAIT unit is 2 AHB clock cycle
 *  0b001..The AWRWAIT unit is 8 AHB clock cycle
 *  0b010..The AWRWAIT unit is 32 AHB clock cycle
 *  0b011..The AWRWAIT unit is 128 AHB clock cycle
 *  0b100..The AWRWAIT unit is 512 AHB clock cycle
 *  0b101..The AWRWAIT unit is 2048 AHB clock cycle
 *  0b110..The AWRWAIT unit is 8192 AHB clock cycle
 *  0b111..The AWRWAIT unit is 32768 AHB clock cycle
 */
#define FLEXSPI_FLSHCR2_AWRWAITUNIT(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_AWRWAITUNIT_SHIFT)) & FLEXSPI_FLSHCR2_AWRWAITUNIT_MASK)

#define FLEXSPI_FLSHCR2_CLRINSTRPTR_MASK         (0x80000000U)
#define FLEXSPI_FLSHCR2_CLRINSTRPTR_SHIFT        (31U)
/*! CLRINSTRPTR - Clear the instruction pointer which is internally saved pointer by JMP_ON_CS. */
#define FLEXSPI_FLSHCR2_CLRINSTRPTR(x)           (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR2_CLRINSTRPTR_SHIFT)) & FLEXSPI_FLSHCR2_CLRINSTRPTR_MASK)
/*! @} */

/*! @name FLSHCR4 - Flash Control Register 4 */
/*! @{ */

#define FLEXSPI_FLSHCR4_WMOPT1_MASK              (0x1U)
#define FLEXSPI_FLSHCR4_WMOPT1_SHIFT             (0U)
/*! WMOPT1 - Write mask option bit 1. This option bit could be used to remove AHB and IP write burst
 *    start address alignment limitation.
 *  0b0..DQS pin will be used as Write Mask when writing to external device. There is no limitation on AHB/IP
 *       write burst start address alignment when flash is accessed in individual mode.
 *  0b1..DQS pin will not be used as Write Mask when writing to external device. There is limitation on AHB/IP
 *       write burst start address alignment when flash is accessed in individual mode.
 */
#define FLEXSPI_FLSHCR4_WMOPT1(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR4_WMOPT1_SHIFT)) & FLEXSPI_FLSHCR4_WMOPT1_MASK)

#define FLEXSPI_FLSHCR4_WMENA_MASK               (0x4U)
#define FLEXSPI_FLSHCR4_WMENA_SHIFT              (2U)
/*! WMENA - Write mask enable bit for flash device on port A. When write mask function is needed for
 *    memory device on port A, this bit must be set.
 *  0b0..Write mask is disabled, DQS(RWDS) pin will not be driven when writing to external device.
 *  0b1..Write mask is enabled, DQS(RWDS) pin will be driven by FlexSPI as write mask output when writing to external device.
 */
#define FLEXSPI_FLSHCR4_WMENA(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_FLSHCR4_WMENA_SHIFT)) & FLEXSPI_FLSHCR4_WMENA_MASK)
/*! @} */

/*! @name IPCR0 - IP Control Register 0 */
/*! @{ */

#define FLEXSPI_IPCR0_SFAR_MASK                  (0xFFFFFFFFU)
#define FLEXSPI_IPCR0_SFAR_SHIFT                 (0U)
/*! SFAR - Serial Flash Address for IP command. */
#define FLEXSPI_IPCR0_SFAR(x)                    (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR0_SFAR_SHIFT)) & FLEXSPI_IPCR0_SFAR_MASK)
/*! @} */

/*! @name IPCR1 - IP Control Register 1 */
/*! @{ */

#define FLEXSPI_IPCR1_IDATSZ_MASK                (0xFFFFU)
#define FLEXSPI_IPCR1_IDATSZ_SHIFT               (0U)
/*! IDATSZ - Flash Read/Program Data Size (in Bytes) for IP command. */
#define FLEXSPI_IPCR1_IDATSZ(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_IDATSZ_SHIFT)) & FLEXSPI_IPCR1_IDATSZ_MASK)

#define FLEXSPI_IPCR1_ISEQID_MASK                (0xF0000U)
#define FLEXSPI_IPCR1_ISEQID_SHIFT               (16U)
/*! ISEQID - Sequence Index in LUT for IP command. */
#define FLEXSPI_IPCR1_ISEQID(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_ISEQID_SHIFT)) & FLEXSPI_IPCR1_ISEQID_MASK)

#define FLEXSPI_IPCR1_ISEQNUM_MASK               (0x7000000U)
#define FLEXSPI_IPCR1_ISEQNUM_SHIFT              (24U)
/*! ISEQNUM - Sequence Number for IP command: ISEQNUM+1. */
#define FLEXSPI_IPCR1_ISEQNUM(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_ISEQNUM_SHIFT)) & FLEXSPI_IPCR1_ISEQNUM_MASK)

#define FLEXSPI_IPCR1_IPAREN_MASK                (0x80000000U)
#define FLEXSPI_IPCR1_IPAREN_SHIFT               (31U)
/*! IPAREN - Parallel mode Enabled for IP command.
 *  0b0..Flash will be accessed in Individual mode.
 *  0b1..Flash will be accessed in Parallel mode.
 */
#define FLEXSPI_IPCR1_IPAREN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCR1_IPAREN_SHIFT)) & FLEXSPI_IPCR1_IPAREN_MASK)
/*! @} */

/*! @name IPCMD - IP Command Register */
/*! @{ */

#define FLEXSPI_IPCMD_TRG_MASK                   (0x1U)
#define FLEXSPI_IPCMD_TRG_SHIFT                  (0U)
/*! TRG - Setting this bit will trigger an IP Command. */
#define FLEXSPI_IPCMD_TRG(x)                     (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPCMD_TRG_SHIFT)) & FLEXSPI_IPCMD_TRG_MASK)
/*! @} */

/*! @name DLPR - Data Learn Pattern Register */
/*! @{ */

#define FLEXSPI_DLPR_DLP_MASK                    (0xFFFFFFFFU)
#define FLEXSPI_DLPR_DLP_SHIFT                   (0U)
/*! DLP - Data Learning Pattern. */
#define FLEXSPI_DLPR_DLP(x)                      (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLPR_DLP_SHIFT)) & FLEXSPI_DLPR_DLP_MASK)
/*! @} */

/*! @name IPRXFCR - IP RX FIFO Control Register */
/*! @{ */

#define FLEXSPI_IPRXFCR_CLRIPRXF_MASK            (0x1U)
#define FLEXSPI_IPRXFCR_CLRIPRXF_SHIFT           (0U)
/*! CLRIPRXF - Clear all valid data entries in IP RX FIFO.
 *  0b0..No function.
 *  0b1..A clock cycle pulse to clear all valid data entries in IP RX FIFO.
 */
#define FLEXSPI_IPRXFCR_CLRIPRXF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_CLRIPRXF_SHIFT)) & FLEXSPI_IPRXFCR_CLRIPRXF_MASK)

#define FLEXSPI_IPRXFCR_RXDMAEN_MASK             (0x2U)
#define FLEXSPI_IPRXFCR_RXDMAEN_SHIFT            (1U)
/*! RXDMAEN - IP RX FIFO reading by DMA enabled.
 *  0b0..IP RX FIFO would be read by processor.
 *  0b1..IP RX FIFO would be read by DMA.
 */
#define FLEXSPI_IPRXFCR_RXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_RXDMAEN_SHIFT)) & FLEXSPI_IPRXFCR_RXDMAEN_MASK)

#define FLEXSPI_IPRXFCR_RXWMRK_MASK              (0x1FCU)
#define FLEXSPI_IPRXFCR_RXWMRK_SHIFT             (2U)
/*! RXWMRK - Watermark level is (RXWMRK+1)*64 bits. */
#define FLEXSPI_IPRXFCR_RXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFCR_RXWMRK_SHIFT)) & FLEXSPI_IPRXFCR_RXWMRK_MASK)
/*! @} */

/*! @name IPTXFCR - IP TX FIFO Control Register */
/*! @{ */

#define FLEXSPI_IPTXFCR_CLRIPTXF_MASK            (0x1U)
#define FLEXSPI_IPTXFCR_CLRIPTXF_SHIFT           (0U)
/*! CLRIPTXF - Clear all valid data entries in IP TX FIFO.
 *  0b0..No function.
 *  0b1..A clock cycle pulse to clear all valid data entries in IP TX FIFO.
 */
#define FLEXSPI_IPTXFCR_CLRIPTXF(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_CLRIPTXF_SHIFT)) & FLEXSPI_IPTXFCR_CLRIPTXF_MASK)

#define FLEXSPI_IPTXFCR_TXDMAEN_MASK             (0x2U)
#define FLEXSPI_IPTXFCR_TXDMAEN_SHIFT            (1U)
/*! TXDMAEN - IP TX FIFO filling by DMA enabled.
 *  0b0..IP TX FIFO would be filled by processor.
 *  0b1..IP TX FIFO would be filled by DMA.
 */
#define FLEXSPI_IPTXFCR_TXDMAEN(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_TXDMAEN_SHIFT)) & FLEXSPI_IPTXFCR_TXDMAEN_MASK)

#define FLEXSPI_IPTXFCR_TXWMRK_MASK              (0x1FCU)
#define FLEXSPI_IPTXFCR_TXWMRK_SHIFT             (2U)
/*! TXWMRK - Watermark level is (TXWMRK+1)*64 Bits. */
#define FLEXSPI_IPTXFCR_TXWMRK(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFCR_TXWMRK_SHIFT)) & FLEXSPI_IPTXFCR_TXWMRK_MASK)
/*! @} */

/*! @name DLLCR - DLL Control Register 0 */
/*! @{ */

#define FLEXSPI_DLLCR_DLLEN_MASK                 (0x1U)
#define FLEXSPI_DLLCR_DLLEN_SHIFT                (0U)
/*! DLLEN - DLL calibration enable.
 *  0b0..DLL calibration is disabled
 *  0b1..DLL calibration is enabled
 */
#define FLEXSPI_DLLCR_DLLEN(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_DLLEN_SHIFT)) & FLEXSPI_DLLCR_DLLEN_MASK)

#define FLEXSPI_DLLCR_DLLRESET_MASK              (0x2U)
#define FLEXSPI_DLLCR_DLLRESET_SHIFT             (1U)
/*! DLLRESET - DLL reset
 *  0b0..No function.
 *  0b1..Software could force a reset on DLL by setting this field to 0x1.
 */
#define FLEXSPI_DLLCR_DLLRESET(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_DLLRESET_SHIFT)) & FLEXSPI_DLLCR_DLLRESET_MASK)

#define FLEXSPI_DLLCR_SLVDLYTARGET_MASK          (0x78U)
#define FLEXSPI_DLLCR_SLVDLYTARGET_SHIFT         (3U)
/*! SLVDLYTARGET - The delay target for slave delay line is: ((SLVDLYTARGET+1) * 1/32 * clock cycle
 *    of reference clock (serial root clock). If serial root clock is >= 100 MHz, DLLEN set to 0x1,
 *    OVRDEN set to =0x0, then SLVDLYTARGET setting of 0 is recommended.
 */
#define FLEXSPI_DLLCR_SLVDLYTARGET(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_SLVDLYTARGET_SHIFT)) & FLEXSPI_DLLCR_SLVDLYTARGET_MASK)

#define FLEXSPI_DLLCR_OVRDEN_MASK                (0x100U)
#define FLEXSPI_DLLCR_OVRDEN_SHIFT               (8U)
/*! OVRDEN - Slave clock delay line delay cell number selection override enable.
 *  0b0..Slave clock delay line delay cell number selection override is disabled.
 *  0b1..Slave clock delay line delay cell number selection override is enabled.
 */
#define FLEXSPI_DLLCR_OVRDEN(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_OVRDEN_SHIFT)) & FLEXSPI_DLLCR_OVRDEN_MASK)

#define FLEXSPI_DLLCR_OVRDVAL_MASK               (0x7E00U)
#define FLEXSPI_DLLCR_OVRDVAL_SHIFT              (9U)
/*! OVRDVAL - Slave clock delay line delay cell number selection override value. */
#define FLEXSPI_DLLCR_OVRDVAL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_DLLCR_OVRDVAL_SHIFT)) & FLEXSPI_DLLCR_OVRDVAL_MASK)
/*! @} */

/*! @name STS0 - Status Register 0 */
/*! @{ */

#define FLEXSPI_STS0_SEQIDLE_MASK                (0x1U)
#define FLEXSPI_STS0_SEQIDLE_SHIFT               (0U)
/*! SEQIDLE - This status bit indicates the state machine in SEQ_CTL is idle and there is command
 *    sequence executing on FlexSPI interface.
 *  0b0..State machine in SEQ_CTL is not idle.
 *  0b1..State machine in SEQ_CTL is idle.
 */
#define FLEXSPI_STS0_SEQIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_SEQIDLE_SHIFT)) & FLEXSPI_STS0_SEQIDLE_MASK)

#define FLEXSPI_STS0_ARBIDLE_MASK                (0x2U)
#define FLEXSPI_STS0_ARBIDLE_SHIFT               (1U)
/*! ARBIDLE - This status bit indicates the state machine in ARB_CTL is busy and there is command
 *    sequence granted by arbitrator and not finished yet on FlexSPI interface. When ARB_CTL state
 *    (ARBIDLE=0x1) is idle, there will be no transaction on FlexSPI interface also (SEQIDLE=0x1). So
 *    this bit should be polled to wait for FlexSPI controller become idle instead of SEQIDLE.
 */
#define FLEXSPI_STS0_ARBIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_ARBIDLE_SHIFT)) & FLEXSPI_STS0_ARBIDLE_MASK)

#define FLEXSPI_STS0_ARBCMDSRC_MASK              (0xCU)
#define FLEXSPI_STS0_ARBCMDSRC_SHIFT             (2U)
/*! ARBCMDSRC - This status field indicates the trigger source of current command sequence granted
 *    by arbitrator. This field value is meaningless when ARB_CTL is not busy (STS0[ARBIDLE]=0x1).
 *  0b00..Triggered by AHB read command.
 *  0b01..Triggered by AHB write command.
 *  0b10..Triggered by IP command (triggered by setting register bit IPCMD[TRG]).
 *  0b11..Triggered by suspended command (resumed).
 */
#define FLEXSPI_STS0_ARBCMDSRC(x)                (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_ARBCMDSRC_SHIFT)) & FLEXSPI_STS0_ARBCMDSRC_MASK)

#define FLEXSPI_STS0_DATALEARNPHASEA_MASK        (0xF0U)
#define FLEXSPI_STS0_DATALEARNPHASEA_SHIFT       (4U)
/*! DATALEARNPHASEA - Indicate the sampling clock phase selection on Port A after Data Learning. */
#define FLEXSPI_STS0_DATALEARNPHASEA(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS0_DATALEARNPHASEA_SHIFT)) & FLEXSPI_STS0_DATALEARNPHASEA_MASK)
/*! @} */

/*! @name STS1 - Status Register 1 */
/*! @{ */

#define FLEXSPI_STS1_AHBCMDERRID_MASK            (0xFU)
#define FLEXSPI_STS1_AHBCMDERRID_SHIFT           (0U)
/*! AHBCMDERRID - Indicates the sequence index when an AHB command error is detected. This field
 *    will be cleared when INTR[AHBCMDERR] is write-1-clear(w1c).
 */
#define FLEXSPI_STS1_AHBCMDERRID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_AHBCMDERRID_SHIFT)) & FLEXSPI_STS1_AHBCMDERRID_MASK)

#define FLEXSPI_STS1_AHBCMDERRCODE_MASK          (0xF00U)
#define FLEXSPI_STS1_AHBCMDERRCODE_SHIFT         (8U)
/*! AHBCMDERRCODE - Indicates the Error Code when AHB command Error detected. This field will be
 *    cleared when INTR[AHBCMDERR] is write-1-clear(w1c).
 *  0b0000..No error.
 *  0b0010..AHB Write command with JMP_ON_CS instruction used in the sequence.
 *  0b0011..There is unknown instruction opcode in the sequence.
 *  0b0100..Instruction DUMMY_SDR/DUMMY_RWDS_SDR used in DDR sequence.
 *  0b0101..Instruction DUMMY_DDR/DUMMY_RWDS_DDR used in SDR sequence.
 *  0b1110..Sequence execution timeout.
 */
#define FLEXSPI_STS1_AHBCMDERRCODE(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_AHBCMDERRCODE_SHIFT)) & FLEXSPI_STS1_AHBCMDERRCODE_MASK)

#define FLEXSPI_STS1_IPCMDERRID_MASK             (0xF0000U)
#define FLEXSPI_STS1_IPCMDERRID_SHIFT            (16U)
/*! IPCMDERRID - Indicates the sequence Index when IP command error detected. */
#define FLEXSPI_STS1_IPCMDERRID(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_IPCMDERRID_SHIFT)) & FLEXSPI_STS1_IPCMDERRID_MASK)

#define FLEXSPI_STS1_IPCMDERRCODE_MASK           (0xF000000U)
#define FLEXSPI_STS1_IPCMDERRCODE_SHIFT          (24U)
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
#define FLEXSPI_STS1_IPCMDERRCODE(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS1_IPCMDERRCODE_SHIFT)) & FLEXSPI_STS1_IPCMDERRCODE_MASK)
/*! @} */

/*! @name STS2 - Status Register 2 */
/*! @{ */

#define FLEXSPI_STS2_ASLVLOCK_MASK               (0x1U)
#define FLEXSPI_STS2_ASLVLOCK_SHIFT              (0U)
/*! ASLVLOCK - Flash A sample clock slave delay line locked.
 *  0b0..Flash A sample clock slave delay line is not locked
 *  0b1..Flash A sample clock slave delay line is locked
 */
#define FLEXSPI_STS2_ASLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_ASLVLOCK_SHIFT)) & FLEXSPI_STS2_ASLVLOCK_MASK)

#define FLEXSPI_STS2_AREFLOCK_MASK               (0x2U)
#define FLEXSPI_STS2_AREFLOCK_SHIFT              (1U)
/*! AREFLOCK - Flash A sample clock reference delay line locked.
 *  0b0..Flash A sample clock reference delay line is not locked
 *  0b1..Flash A sample clock reference delay line is locked
 */
#define FLEXSPI_STS2_AREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_AREFLOCK_SHIFT)) & FLEXSPI_STS2_AREFLOCK_MASK)

#define FLEXSPI_STS2_ASLVSEL_MASK                (0xFCU)
#define FLEXSPI_STS2_ASLVSEL_SHIFT               (2U)
/*! ASLVSEL - Flash A sample clock slave delay line delay cell number selection . */
#define FLEXSPI_STS2_ASLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_ASLVSEL_SHIFT)) & FLEXSPI_STS2_ASLVSEL_MASK)

#define FLEXSPI_STS2_AREFSEL_MASK                (0x3F00U)
#define FLEXSPI_STS2_AREFSEL_SHIFT               (8U)
/*! AREFSEL - Flash A sample clock reference delay line delay cell number selection. */
#define FLEXSPI_STS2_AREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_AREFSEL_SHIFT)) & FLEXSPI_STS2_AREFSEL_MASK)

#define FLEXSPI_STS2_BSLVLOCK_MASK               (0x10000U)
#define FLEXSPI_STS2_BSLVLOCK_SHIFT              (16U)
/*! BSLVLOCK - Flash B sample clock slave delay line locked.
 *  0b0..Flash B sample clock slave delay line is not locked.
 *  0b1..Flash B sample clock slave delay line is locked.
 */
#define FLEXSPI_STS2_BSLVLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BSLVLOCK_SHIFT)) & FLEXSPI_STS2_BSLVLOCK_MASK)

#define FLEXSPI_STS2_BREFLOCK_MASK               (0x20000U)
#define FLEXSPI_STS2_BREFLOCK_SHIFT              (17U)
/*! BREFLOCK - Flash B sample clock reference delay line locked.
 *  0b0..Flash B sample clock reference delay line is not locked.
 *  0b1..Flash B sample clock reference delay line is locked.
 */
#define FLEXSPI_STS2_BREFLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BREFLOCK_SHIFT)) & FLEXSPI_STS2_BREFLOCK_MASK)

#define FLEXSPI_STS2_BSLVSEL_MASK                (0xFC0000U)
#define FLEXSPI_STS2_BSLVSEL_SHIFT               (18U)
/*! BSLVSEL - Flash B sample clock slave delay line delay cell number selection. */
#define FLEXSPI_STS2_BSLVSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BSLVSEL_SHIFT)) & FLEXSPI_STS2_BSLVSEL_MASK)

#define FLEXSPI_STS2_BREFSEL_MASK                (0x3F000000U)
#define FLEXSPI_STS2_BREFSEL_SHIFT               (24U)
/*! BREFSEL - Flash B sample clock reference delay line delay cell number selection. */
#define FLEXSPI_STS2_BREFSEL(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_STS2_BREFSEL_SHIFT)) & FLEXSPI_STS2_BREFSEL_MASK)
/*! @} */

/*! @name AHBSPNDSTS - AHB Suspend Status Register */
/*! @{ */

#define FLEXSPI_AHBSPNDSTS_ACTIVE_MASK           (0x1U)
#define FLEXSPI_AHBSPNDSTS_ACTIVE_SHIFT          (0U)
/*! ACTIVE - Indicates if an AHB read prefetch command sequence has been suspended.
 *  0b0..No suspended AHB read prefetch command.
 *  0b1..An AHB read prefetch command sequence has been suspended.
 */
#define FLEXSPI_AHBSPNDSTS_ACTIVE(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_ACTIVE_SHIFT)) & FLEXSPI_AHBSPNDSTS_ACTIVE_MASK)

#define FLEXSPI_AHBSPNDSTS_BUFID_MASK            (0xEU)
#define FLEXSPI_AHBSPNDSTS_BUFID_SHIFT           (1U)
/*! BUFID - AHB RX BUF ID for suspended command sequence. */
#define FLEXSPI_AHBSPNDSTS_BUFID(x)              (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_BUFID_SHIFT)) & FLEXSPI_AHBSPNDSTS_BUFID_MASK)

#define FLEXSPI_AHBSPNDSTS_DATLFT_MASK           (0xFFFF0000U)
#define FLEXSPI_AHBSPNDSTS_DATLFT_SHIFT          (16U)
/*! DATLFT - The Data size left for suspended command sequence (in byte). */
#define FLEXSPI_AHBSPNDSTS_DATLFT(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_AHBSPNDSTS_DATLFT_SHIFT)) & FLEXSPI_AHBSPNDSTS_DATLFT_MASK)
/*! @} */

/*! @name IPRXFSTS - IP RX FIFO Status Register */
/*! @{ */

#define FLEXSPI_IPRXFSTS_FILL_MASK               (0xFFU)
#define FLEXSPI_IPRXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill level of IP RX FIFO. */
#define FLEXSPI_IPRXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFSTS_FILL_SHIFT)) & FLEXSPI_IPRXFSTS_FILL_MASK)

#define FLEXSPI_IPRXFSTS_RDCNTR_MASK             (0xFFFF0000U)
#define FLEXSPI_IPRXFSTS_RDCNTR_SHIFT            (16U)
/*! RDCNTR - Total Read Data Counter: RDCNTR * 64 Bits. */
#define FLEXSPI_IPRXFSTS_RDCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPRXFSTS_RDCNTR_SHIFT)) & FLEXSPI_IPRXFSTS_RDCNTR_MASK)
/*! @} */

/*! @name IPTXFSTS - IP TX FIFO Status Register */
/*! @{ */

#define FLEXSPI_IPTXFSTS_FILL_MASK               (0xFFU)
#define FLEXSPI_IPTXFSTS_FILL_SHIFT              (0U)
/*! FILL - Fill level of IP TX FIFO. */
#define FLEXSPI_IPTXFSTS_FILL(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFSTS_FILL_SHIFT)) & FLEXSPI_IPTXFSTS_FILL_MASK)

#define FLEXSPI_IPTXFSTS_WRCNTR_MASK             (0xFFFF0000U)
#define FLEXSPI_IPTXFSTS_WRCNTR_SHIFT            (16U)
/*! WRCNTR - Total Write Data Counter: WRCNTR * 64 Bits. */
#define FLEXSPI_IPTXFSTS_WRCNTR(x)               (((uint32_t)(((uint32_t)(x)) << FLEXSPI_IPTXFSTS_WRCNTR_SHIFT)) & FLEXSPI_IPTXFSTS_WRCNTR_MASK)
/*! @} */

/*! @name RFDR - IP RX FIFO Data Register 0..IP RX FIFO Data Register 31 */
/*! @{ */

#define FLEXSPI_RFDR_RXDATA_MASK                 (0xFFFFFFFFU)
#define FLEXSPI_RFDR_RXDATA_SHIFT                (0U)
/*! RXDATA - RX Data. */
#define FLEXSPI_RFDR_RXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_RFDR_RXDATA_SHIFT)) & FLEXSPI_RFDR_RXDATA_MASK)
/*! @} */

/*! @name TFDR - IP TX FIFO Data Register 0..IP TX FIFO Data Register 31 */
/*! @{ */

#define FLEXSPI_TFDR_TXDATA_MASK                 (0xFFFFFFFFU)
#define FLEXSPI_TFDR_TXDATA_SHIFT                (0U)
/*! TXDATA - TX Data */
#define FLEXSPI_TFDR_TXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_TFDR_TXDATA_SHIFT)) & FLEXSPI_TFDR_TXDATA_MASK)
/*! @} */

/*! @name LUT - LUT 0..LUT 63 */
/*! @{ */

#define FLEXSPI_LUT_OPERAND0_MASK                (0xFFU)
#define FLEXSPI_LUT_OPERAND0_SHIFT               (0U)
/*! OPERAND0 - OPERAND0 */
#define FLEXSPI_LUT_OPERAND0(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPERAND0_SHIFT)) & FLEXSPI_LUT_OPERAND0_MASK)

#define FLEXSPI_LUT_NUM_PADS0_MASK               (0x300U)
#define FLEXSPI_LUT_NUM_PADS0_SHIFT              (8U)
/*! NUM_PADS0 - NUM_PADS0 */
#define FLEXSPI_LUT_NUM_PADS0(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_NUM_PADS0_SHIFT)) & FLEXSPI_LUT_NUM_PADS0_MASK)

#define FLEXSPI_LUT_OPCODE0_MASK                 (0xFC00U)
#define FLEXSPI_LUT_OPCODE0_SHIFT                (10U)
/*! OPCODE0 - OPCODE */
#define FLEXSPI_LUT_OPCODE0(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPCODE0_SHIFT)) & FLEXSPI_LUT_OPCODE0_MASK)

#define FLEXSPI_LUT_OPERAND1_MASK                (0xFF0000U)
#define FLEXSPI_LUT_OPERAND1_SHIFT               (16U)
/*! OPERAND1 - OPERAND1 */
#define FLEXSPI_LUT_OPERAND1(x)                  (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPERAND1_SHIFT)) & FLEXSPI_LUT_OPERAND1_MASK)

#define FLEXSPI_LUT_NUM_PADS1_MASK               (0x3000000U)
#define FLEXSPI_LUT_NUM_PADS1_SHIFT              (24U)
/*! NUM_PADS1 - NUM_PADS1 */
#define FLEXSPI_LUT_NUM_PADS1(x)                 (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_NUM_PADS1_SHIFT)) & FLEXSPI_LUT_NUM_PADS1_MASK)

#define FLEXSPI_LUT_OPCODE1_MASK                 (0xFC000000U)
#define FLEXSPI_LUT_OPCODE1_SHIFT                (26U)
/*! OPCODE1 - OPCODE1 */
#define FLEXSPI_LUT_OPCODE1(x)                   (((uint32_t)(((uint32_t)(x)) << FLEXSPI_LUT_OPCODE1_SHIFT)) & FLEXSPI_LUT_OPCODE1_MASK)
/*! @} */

/*! @name HADDRSTART - HADDR REMAP START ADDR */
/*! @{ */

#define FLEXSPI_HADDRSTART_REMAPEN_MASK          (0x1U)
#define FLEXSPI_HADDRSTART_REMAPEN_SHIFT         (0U)
/*! REMAPEN - AHB Bus address remap function enable
 *  0b0..HADDR REMAP Disabled
 *  0b1..HADDR REMAP Enabled
 */
#define FLEXSPI_HADDRSTART_REMAPEN(x)            (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDRSTART_REMAPEN_SHIFT)) & FLEXSPI_HADDRSTART_REMAPEN_MASK)

#define FLEXSPI_HADDRSTART_ADDRSTART_MASK        (0xFFFFF000U)
#define FLEXSPI_HADDRSTART_ADDRSTART_SHIFT       (12U)
/*! ADDRSTART - HADDR start address */
#define FLEXSPI_HADDRSTART_ADDRSTART(x)          (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDRSTART_ADDRSTART_SHIFT)) & FLEXSPI_HADDRSTART_ADDRSTART_MASK)
/*! @} */

/*! @name HADDREND - HADDR REMAP END ADDR */
/*! @{ */

#define FLEXSPI_HADDREND_ENDSTART_MASK           (0xFFFFF000U)
#define FLEXSPI_HADDREND_ENDSTART_SHIFT          (12U)
/*! ENDSTART - HADDR remap range's end address, 4K aligned */
#define FLEXSPI_HADDREND_ENDSTART(x)             (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDREND_ENDSTART_SHIFT)) & FLEXSPI_HADDREND_ENDSTART_MASK)
/*! @} */

/*! @name HADDROFFSET - HADDR REMAP OFFSET */
/*! @{ */

#define FLEXSPI_HADDROFFSET_ADDROFFSET_MASK      (0xFFFFF000U)
#define FLEXSPI_HADDROFFSET_ADDROFFSET_SHIFT     (12U)
/*! ADDROFFSET - HADDR offset field, remapped address will be ADDR[31:12]=ADDR_original[31:12]+ADDROFFSET */
#define FLEXSPI_HADDROFFSET_ADDROFFSET(x)        (((uint32_t)(((uint32_t)(x)) << FLEXSPI_HADDROFFSET_ADDROFFSET_SHIFT)) & FLEXSPI_HADDROFFSET_ADDROFFSET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLEXSPI_Register_Masks */


/*!
 * @}
 */ /* end of group FLEXSPI_Peripheral_Access_Layer */


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


#endif  /* PERI_FLEXSPI_H_ */

