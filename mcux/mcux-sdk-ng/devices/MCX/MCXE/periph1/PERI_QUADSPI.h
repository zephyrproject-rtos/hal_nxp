/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250515
**
**     Abstract:
**         CMSIS Peripheral Access Layer for QuadSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_QuadSPI.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for QuadSPI
 *
 * CMSIS Peripheral Access Layer for QuadSPI
 */

#if !defined(PERI_QUADSPI_H_)
#define PERI_QUADSPI_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- QuadSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_Peripheral_Access_Layer QuadSPI Peripheral Access Layer
 * @{
 */

/** QuadSPI - Size of Registers Arrays */
#define QuadSPI_RBDR_COUNT                        32u
#define QuadSPI_LUT_COUNT                         20u

/** QuadSPI - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IPCR;                              /**< IP Configuration Register, offset: 0x8 */
  __IO uint32_t FLSHCR;                            /**< Flash Memory Configuration Register, offset: 0xC */
  __IO uint32_t BUF0CR;                            /**< Buffer 0 Configuration Register, offset: 0x10 */
  __IO uint32_t BUF1CR;                            /**< Buffer 1 Configuration Register, offset: 0x14 */
  __IO uint32_t BUF2CR;                            /**< Buffer 2 Configuration Register, offset: 0x18 */
  __IO uint32_t BUF3CR;                            /**< Buffer 3 Configuration Register, offset: 0x1C */
  __IO uint32_t BFGENCR;                           /**< Buffer Generic Configuration Register, offset: 0x20 */
  __IO uint32_t SOCCR;                             /**< SOC Configuration Register, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t BUF0IND;                           /**< Buffer 0 Top Index Register, offset: 0x30 */
  __IO uint32_t BUF1IND;                           /**< Buffer 1 Top Index Register, offset: 0x34 */
  __IO uint32_t BUF2IND;                           /**< Buffer 2 Top Index Register, offset: 0x38 */
       uint8_t RESERVED_2[36];
  __IO uint32_t DLLCRA;                            /**< DLL Flash Memory A Configuration Register, offset: 0x60 */
       uint8_t RESERVED_3[156];
  __IO uint32_t SFAR;                              /**< Serial Flash Memory Address Register, offset: 0x100 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SMPR;                              /**< Sampling Register, offset: 0x108 */
  __I  uint32_t RBSR;                              /**< RX Buffer Status Register, offset: 0x10C */
  __IO uint32_t RBCT;                              /**< RX Buffer Control Register, offset: 0x110 */
       uint8_t RESERVED_5[32];
  __I  uint32_t DLSR_FA;                           /**< Data Learning Status Flash Memory A Register, offset: 0x134 */
       uint8_t RESERVED_6[24];
  __I  uint32_t TBSR;                              /**< TX Buffer Status Register, offset: 0x150 */
  __IO uint32_t TBDR;                              /**< TX Buffer Data Register, offset: 0x154 */
  __IO uint32_t TBCT;                              /**< TX Buffer Control Register, offset: 0x158 */
  __I  uint32_t SR;                                /**< Status Register, offset: 0x15C */
  __IO uint32_t FR;                                /**< Flag Register, offset: 0x160 */
  __IO uint32_t RSER;                              /**< Interrupt and DMA Request Select and Enable Register, offset: 0x164 */
       uint8_t RESERVED_7[4];
  __IO uint32_t SPTRCLR;                           /**< Sequence Pointer Clear Register, offset: 0x16C */
       uint8_t RESERVED_8[16];
  __IO uint32_t SFA1AD;                            /**< Serial Flash Memory A1 Top Address Register, offset: 0x180 */
  __IO uint32_t SFA2AD;                            /**< Serial Flash Memory A2 Top Address Register, offset: 0x184 */
  __IO uint32_t SFB1AD;                            /**< Serial Flash Memory B1 Top Address Register, offset: 0x188 */
  __IO uint32_t SFB2AD;                            /**< Serial Flash Memory B2 Top Address Register, offset: 0x18C */
       uint8_t RESERVED_9[112];
  __I  uint32_t RBDR[QuadSPI_RBDR_COUNT];          /**< RX Buffer Data Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_10[128];
  __IO uint32_t LUTKEY;                            /**< LUT Key Register, offset: 0x300 */
  __IO uint32_t LCKCR;                             /**< LUT Lock Configuration Register, offset: 0x304 */
       uint8_t RESERVED_11[8];
  __IO uint32_t LUT[QuadSPI_LUT_COUNT];            /**< LUT Register, array offset: 0x310, array step: 0x4 */
} QuadSPI_Type;

/* ----------------------------------------------------------------------------
   -- QuadSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup QuadSPI_Register_Masks QuadSPI Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define QuadSPI_MCR_SWRSTSD_MASK                 (0x1U)
#define QuadSPI_MCR_SWRSTSD_SHIFT                (0U)
/*! SWRSTSD - Software reset for serial flash memory domain */
#define QuadSPI_MCR_SWRSTSD(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_SWRSTSD_SHIFT)) & QuadSPI_MCR_SWRSTSD_MASK)

#define QuadSPI_MCR_SWRSTHD_MASK                 (0x2U)
#define QuadSPI_MCR_SWRSTHD_SHIFT                (1U)
/*! SWRSTHD - Software reset for AHB domain */
#define QuadSPI_MCR_SWRSTHD(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_SWRSTHD_SHIFT)) & QuadSPI_MCR_SWRSTHD_MASK)

#define QuadSPI_MCR_CLR_RXF_MASK                 (0x400U)
#define QuadSPI_MCR_CLR_RXF_SHIFT                (10U)
/*! CLR_RXF - Clear RX FIFO
 *  0b0..No action
 *  0b1..Read and write pointers of the RX buffer are reset to 0 and RBSR[RDBFL] is reset to 0.
 */
#define QuadSPI_MCR_CLR_RXF(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_CLR_RXF_SHIFT)) & QuadSPI_MCR_CLR_RXF_MASK)

#define QuadSPI_MCR_CLR_TXF_MASK                 (0x800U)
#define QuadSPI_MCR_CLR_TXF_SHIFT                (11U)
/*! CLR_TXF - Clear TX FIFO/buffer
 *  0b0..No action
 *  0b1..Read and write pointers of the TX buffer are reset to 0 and TBSR[TRCTR] is reset to 0.
 */
#define QuadSPI_MCR_CLR_TXF(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_CLR_TXF_SHIFT)) & QuadSPI_MCR_CLR_TXF_MASK)

#define QuadSPI_MCR_MDIS_MASK                    (0x4000U)
#define QuadSPI_MCR_MDIS_SHIFT                   (14U)
/*! MDIS - Module disable
 *  0b0..Enable QuadSPI clocks
 *  0b1..Allow external logic to disable QuadSPI clocks
 */
#define QuadSPI_MCR_MDIS(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_MDIS_SHIFT)) & QuadSPI_MCR_MDIS_MASK)

#define QuadSPI_MCR_DQS_FA_SEL_MASK              (0x3000000U)
#define QuadSPI_MCR_DQS_FA_SEL_SHIFT             (24U)
/*! DQS_FA_SEL - DQS clock for sampling read data at flash memory A */
#define QuadSPI_MCR_DQS_FA_SEL(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_MCR_DQS_FA_SEL_SHIFT)) & QuadSPI_MCR_DQS_FA_SEL_MASK)
/*! @} */

/*! @name IPCR - IP Configuration Register */
/*! @{ */

#define QuadSPI_IPCR_IDATSZ_MASK                 (0xFFFFU)
#define QuadSPI_IPCR_IDATSZ_SHIFT                (0U)
/*! IDATSZ - IP data transfer size */
#define QuadSPI_IPCR_IDATSZ(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_IPCR_IDATSZ_SHIFT)) & QuadSPI_IPCR_IDATSZ_MASK)

#define QuadSPI_IPCR_SEQID_MASK                  (0xF000000U)
#define QuadSPI_IPCR_SEQID_SHIFT                 (24U)
/*! SEQID - Points to a sequence in the LUT */
#define QuadSPI_IPCR_SEQID(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_IPCR_SEQID_SHIFT)) & QuadSPI_IPCR_SEQID_MASK)
/*! @} */

/*! @name FLSHCR - Flash Memory Configuration Register */
/*! @{ */

#define QuadSPI_FLSHCR_TCSS_MASK                 (0xFU)
#define QuadSPI_FLSHCR_TCSS_SHIFT                (0U)
/*! TCSS - Serial flash memory CS setup time */
#define QuadSPI_FLSHCR_TCSS(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_FLSHCR_TCSS_SHIFT)) & QuadSPI_FLSHCR_TCSS_MASK)

#define QuadSPI_FLSHCR_TCSH_MASK                 (0xF00U)
#define QuadSPI_FLSHCR_TCSH_SHIFT                (8U)
/*! TCSH - Serial flash memory CS hold time */
#define QuadSPI_FLSHCR_TCSH(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_FLSHCR_TCSH_SHIFT)) & QuadSPI_FLSHCR_TCSH_MASK)
/*! @} */

/*! @name BUF0CR - Buffer 0 Configuration Register */
/*! @{ */

#define QuadSPI_BUF0CR_MSTRID_MASK               (0xFU)
#define QuadSPI_BUF0CR_MSTRID_SHIFT              (0U)
/*! MSTRID - Master ID */
#define QuadSPI_BUF0CR_MSTRID(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF0CR_MSTRID_SHIFT)) & QuadSPI_BUF0CR_MSTRID_MASK)

#define QuadSPI_BUF0CR_ADATSZ_MASK               (0x3F00U)
#define QuadSPI_BUF0CR_ADATSZ_SHIFT              (8U)
/*! ADATSZ - AHB data transfer size */
#define QuadSPI_BUF0CR_ADATSZ(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF0CR_ADATSZ_SHIFT)) & QuadSPI_BUF0CR_ADATSZ_MASK)
/*! @} */

/*! @name BUF1CR - Buffer 1 Configuration Register */
/*! @{ */

#define QuadSPI_BUF1CR_MSTRID_MASK               (0xFU)
#define QuadSPI_BUF1CR_MSTRID_SHIFT              (0U)
/*! MSTRID - Master ID */
#define QuadSPI_BUF1CR_MSTRID(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF1CR_MSTRID_SHIFT)) & QuadSPI_BUF1CR_MSTRID_MASK)

#define QuadSPI_BUF1CR_ADATSZ_MASK               (0x3F00U)
#define QuadSPI_BUF1CR_ADATSZ_SHIFT              (8U)
/*! ADATSZ - AHB data transfer size */
#define QuadSPI_BUF1CR_ADATSZ(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF1CR_ADATSZ_SHIFT)) & QuadSPI_BUF1CR_ADATSZ_MASK)
/*! @} */

/*! @name BUF2CR - Buffer 2 Configuration Register */
/*! @{ */

#define QuadSPI_BUF2CR_MSTRID_MASK               (0xFU)
#define QuadSPI_BUF2CR_MSTRID_SHIFT              (0U)
/*! MSTRID - Master ID */
#define QuadSPI_BUF2CR_MSTRID(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF2CR_MSTRID_SHIFT)) & QuadSPI_BUF2CR_MSTRID_MASK)

#define QuadSPI_BUF2CR_ADATSZ_MASK               (0x3F00U)
#define QuadSPI_BUF2CR_ADATSZ_SHIFT              (8U)
/*! ADATSZ - AHB data transfer size */
#define QuadSPI_BUF2CR_ADATSZ(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF2CR_ADATSZ_SHIFT)) & QuadSPI_BUF2CR_ADATSZ_MASK)
/*! @} */

/*! @name BUF3CR - Buffer 3 Configuration Register */
/*! @{ */

#define QuadSPI_BUF3CR_MSTRID_MASK               (0xFU)
#define QuadSPI_BUF3CR_MSTRID_SHIFT              (0U)
/*! MSTRID - Master ID */
#define QuadSPI_BUF3CR_MSTRID(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF3CR_MSTRID_SHIFT)) & QuadSPI_BUF3CR_MSTRID_MASK)

#define QuadSPI_BUF3CR_ADATSZ_MASK               (0x3F00U)
#define QuadSPI_BUF3CR_ADATSZ_SHIFT              (8U)
/*! ADATSZ - AHB data transfer size */
#define QuadSPI_BUF3CR_ADATSZ(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF3CR_ADATSZ_SHIFT)) & QuadSPI_BUF3CR_ADATSZ_MASK)

#define QuadSPI_BUF3CR_ALLMST_MASK               (0x80000000U)
#define QuadSPI_BUF3CR_ALLMST_SHIFT              (31U)
/*! ALLMST - All master enable */
#define QuadSPI_BUF3CR_ALLMST(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF3CR_ALLMST_SHIFT)) & QuadSPI_BUF3CR_ALLMST_MASK)
/*! @} */

/*! @name BFGENCR - Buffer Generic Configuration Register */
/*! @{ */

#define QuadSPI_BFGENCR_SEQID_MASK               (0xF000U)
#define QuadSPI_BFGENCR_SEQID_SHIFT              (12U)
/*! SEQID - Points to a sequence in the LUT */
#define QuadSPI_BFGENCR_SEQID(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_BFGENCR_SEQID_SHIFT)) & QuadSPI_BFGENCR_SEQID_MASK)
/*! @} */

/*! @name SOCCR - SOC Configuration Register */
/*! @{ */

#define QuadSPI_SOCCR_SOCCFG_MASK                (0xFFFFFFFFU)
#define QuadSPI_SOCCR_SOCCFG_SHIFT               (0U)
/*! SOCCFG - SOC configuration */
#define QuadSPI_SOCCR_SOCCFG(x)                  (((uint32_t)(((uint32_t)(x)) << QuadSPI_SOCCR_SOCCFG_SHIFT)) & QuadSPI_SOCCR_SOCCFG_MASK)
/*! @} */

/*! @name BUF0IND - Buffer 0 Top Index Register */
/*! @{ */

#define QuadSPI_BUF0IND_TPINDX0_MASK             (0x1F8U)
#define QuadSPI_BUF0IND_TPINDX0_SHIFT            (3U)
/*! TPINDX0 - Top index of buffer 0 */
#define QuadSPI_BUF0IND_TPINDX0(x)               (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF0IND_TPINDX0_SHIFT)) & QuadSPI_BUF0IND_TPINDX0_MASK)
/*! @} */

/*! @name BUF1IND - Buffer 1 Top Index Register */
/*! @{ */

#define QuadSPI_BUF1IND_TPINDX1_MASK             (0x1F8U)
#define QuadSPI_BUF1IND_TPINDX1_SHIFT            (3U)
/*! TPINDX1 - Top index of buffer 1 */
#define QuadSPI_BUF1IND_TPINDX1(x)               (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF1IND_TPINDX1_SHIFT)) & QuadSPI_BUF1IND_TPINDX1_MASK)
/*! @} */

/*! @name BUF2IND - Buffer 2 Top Index Register */
/*! @{ */

#define QuadSPI_BUF2IND_TPINDX2_MASK             (0x1F8U)
#define QuadSPI_BUF2IND_TPINDX2_SHIFT            (3U)
/*! TPINDX2 - Top index of buffer 2 */
#define QuadSPI_BUF2IND_TPINDX2(x)               (((uint32_t)(((uint32_t)(x)) << QuadSPI_BUF2IND_TPINDX2_SHIFT)) & QuadSPI_BUF2IND_TPINDX2_MASK)
/*! @} */

/*! @name DLLCRA - DLL Flash Memory A Configuration Register */
/*! @{ */

#define QuadSPI_DLLCRA_SLV_UPD_MASK              (0x1U)
#define QuadSPI_DLLCRA_SLV_UPD_SHIFT             (0U)
/*! SLV_UPD - Slave update
 *  0b0..Disables any further update on DQS slave delay chain.
 *  0b1..Updates the DQS slave delay chain with either ref-delay or bypass slave delay value, and should be set in the absence of the DQS clock.
 */
#define QuadSPI_DLLCRA_SLV_UPD(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_UPD_SHIFT)) & QuadSPI_DLLCRA_SLV_UPD_MASK)

#define QuadSPI_DLLCRA_SLV_DLL_BYPASS_MASK       (0x2U)
#define QuadSPI_DLLCRA_SLV_DLL_BYPASS_SHIFT      (1U)
/*! SLV_DLL_BYPASS - Slave DLL bypass
 *  0b0..Disables manual selection of coarse delays in the slave delay chain.
 *  0b1..Enables selection of number of delays in each slave delay tap, based on DLLCRA[SLV_DLY_COARSE].
 */
#define QuadSPI_DLLCRA_SLV_DLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_DLL_BYPASS_SHIFT)) & QuadSPI_DLLCRA_SLV_DLL_BYPASS_MASK)

#define QuadSPI_DLLCRA_SLV_EN_MASK               (0x4U)
#define QuadSPI_DLLCRA_SLV_EN_SHIFT              (2U)
/*! SLV_EN - Slave enable
 *  0b0..DLL slave logic remains in reset, and its value should be 0 for at least three flash memory clock cycles for reset.
 *  0b1..Enables DQS slave delay chain, and should be 1 before any slave configuration settings take place.
 */
#define QuadSPI_DLLCRA_SLV_EN(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_EN_SHIFT)) & QuadSPI_DLLCRA_SLV_EN_MASK)

#define QuadSPI_DLLCRA_SLV_DLY_COARSE_MASK       (0xF00U)
#define QuadSPI_DLLCRA_SLV_DLY_COARSE_SHIFT      (8U)
/*! SLV_DLY_COARSE - Delay elements in each delay tap */
#define QuadSPI_DLLCRA_SLV_DLY_COARSE(x)         (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_DLY_COARSE_SHIFT)) & QuadSPI_DLLCRA_SLV_DLY_COARSE_MASK)

#define QuadSPI_DLLCRA_SLV_DLY_OFFSET_MASK       (0x7000U)
#define QuadSPI_DLLCRA_SLV_DLY_OFFSET_SHIFT      (12U)
/*! SLV_DLY_OFFSET - T/16 offset delay elements in incoming DQS */
#define QuadSPI_DLLCRA_SLV_DLY_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_DLY_OFFSET_SHIFT)) & QuadSPI_DLLCRA_SLV_DLY_OFFSET_MASK)

#define QuadSPI_DLLCRA_SLV_FINE_OFFSET_MASK      (0xF0000U)
#define QuadSPI_DLLCRA_SLV_FINE_OFFSET_SHIFT     (16U)
/*! SLV_FINE_OFFSET - Fine offset delay elements in incoming DQS */
#define QuadSPI_DLLCRA_SLV_FINE_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_SLV_FINE_OFFSET_SHIFT)) & QuadSPI_DLLCRA_SLV_FINE_OFFSET_MASK)

#define QuadSPI_DLLCRA_FREQEN_MASK               (0x40000000U)
#define QuadSPI_DLLCRA_FREQEN_SHIFT              (30U)
/*! FREQEN - Frequency enable
 *  0b0..Selects delay chain for low frequency of operation
 *  0b1..Selects delay chain for high frequency of operation
 */
#define QuadSPI_DLLCRA_FREQEN(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLLCRA_FREQEN_SHIFT)) & QuadSPI_DLLCRA_FREQEN_MASK)
/*! @} */

/*! @name SFAR - Serial Flash Memory Address Register */
/*! @{ */

#define QuadSPI_SFAR_SFADR_MASK                  (0xFFFFFFFFU)
#define QuadSPI_SFAR_SFADR_SHIFT                 (0U)
/*! SFADR - Serial flash memory address */
#define QuadSPI_SFAR_SFADR(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SFAR_SFADR_SHIFT)) & QuadSPI_SFAR_SFADR_MASK)
/*! @} */

/*! @name SMPR - Sampling Register */
/*! @{ */

#define QuadSPI_SMPR_FSPHS_MASK                  (0x20U)
#define QuadSPI_SMPR_FSPHS_SHIFT                 (5U)
/*! FSPHS - Full-speed phase selection for SDR instructions */
#define QuadSPI_SMPR_FSPHS(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SMPR_FSPHS_SHIFT)) & QuadSPI_SMPR_FSPHS_MASK)

#define QuadSPI_SMPR_FSDLY_MASK                  (0x40U)
#define QuadSPI_SMPR_FSDLY_SHIFT                 (6U)
/*! FSDLY - Full speed delay selection for SDR instructions */
#define QuadSPI_SMPR_FSDLY(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SMPR_FSDLY_SHIFT)) & QuadSPI_SMPR_FSDLY_MASK)

#define QuadSPI_SMPR_DLLFSMPFA_MASK              (0x7000000U)
#define QuadSPI_SMPR_DLLFSMPFA_SHIFT             (24U)
/*! DLLFSMPFA - Selects the nth tap provided by slave delay chain for flash memory A */
#define QuadSPI_SMPR_DLLFSMPFA(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_SMPR_DLLFSMPFA_SHIFT)) & QuadSPI_SMPR_DLLFSMPFA_MASK)
/*! @} */

/*! @name RBSR - RX Buffer Status Register */
/*! @{ */

#define QuadSPI_RBSR_RDBFL_MASK                  (0x3FU)
#define QuadSPI_RBSR_RDBFL_SHIFT                 (0U)
/*! RDBFL - RX buffer fill level */
#define QuadSPI_RBSR_RDBFL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RBSR_RDBFL_SHIFT)) & QuadSPI_RBSR_RDBFL_MASK)

#define QuadSPI_RBSR_RDCTR_MASK                  (0xFFFF0000U)
#define QuadSPI_RBSR_RDCTR_SHIFT                 (16U)
/*! RDCTR - Read counter */
#define QuadSPI_RBSR_RDCTR(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RBSR_RDCTR_SHIFT)) & QuadSPI_RBSR_RDCTR_MASK)
/*! @} */

/*! @name RBCT - RX Buffer Control Register */
/*! @{ */

#define QuadSPI_RBCT_WMRK_MASK                   (0x1FU)
#define QuadSPI_RBCT_WMRK_SHIFT                  (0U)
/*! WMRK - RX buffer watermark */
#define QuadSPI_RBCT_WMRK(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_RBCT_WMRK_SHIFT)) & QuadSPI_RBCT_WMRK_MASK)

#define QuadSPI_RBCT_RXBRD_MASK                  (0x100U)
#define QuadSPI_RBCT_RXBRD_SHIFT                 (8U)
/*! RXBRD - RX buffer readout */
#define QuadSPI_RBCT_RXBRD(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RBCT_RXBRD_SHIFT)) & QuadSPI_RBCT_RXBRD_MASK)
/*! @} */

/*! @name DLSR_FA - Data Learning Status Flash Memory A Register */
/*! @{ */

#define QuadSPI_DLSR_FA_NEG_EDGE_MASK            (0xFFU)
#define QuadSPI_DLSR_FA_NEG_EDGE_SHIFT           (0U)
#define QuadSPI_DLSR_FA_NEG_EDGE(x)              (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLSR_FA_NEG_EDGE_SHIFT)) & QuadSPI_DLSR_FA_NEG_EDGE_MASK)

#define QuadSPI_DLSR_FA_POS_EDGE_MASK            (0xFF00U)
#define QuadSPI_DLSR_FA_POS_EDGE_SHIFT           (8U)
#define QuadSPI_DLSR_FA_POS_EDGE(x)              (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLSR_FA_POS_EDGE_SHIFT)) & QuadSPI_DLSR_FA_POS_EDGE_MASK)

#define QuadSPI_DLSR_FA_DLPFFA_MASK              (0x80000000U)
#define QuadSPI_DLSR_FA_DLPFFA_SHIFT             (31U)
/*! DLPFFA - Data learning pattern fail */
#define QuadSPI_DLSR_FA_DLPFFA(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_DLSR_FA_DLPFFA_SHIFT)) & QuadSPI_DLSR_FA_DLPFFA_MASK)
/*! @} */

/*! @name TBSR - TX Buffer Status Register */
/*! @{ */

#define QuadSPI_TBSR_TRBFL_MASK                  (0x3FU)
#define QuadSPI_TBSR_TRBFL_SHIFT                 (0U)
/*! TRBFL - TX buffer fill level */
#define QuadSPI_TBSR_TRBFL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_TBSR_TRBFL_SHIFT)) & QuadSPI_TBSR_TRBFL_MASK)

#define QuadSPI_TBSR_TRCTR_MASK                  (0xFFFF0000U)
#define QuadSPI_TBSR_TRCTR_SHIFT                 (16U)
/*! TRCTR - Transmit counter */
#define QuadSPI_TBSR_TRCTR(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_TBSR_TRCTR_SHIFT)) & QuadSPI_TBSR_TRCTR_MASK)
/*! @} */

/*! @name TBDR - TX Buffer Data Register */
/*! @{ */

#define QuadSPI_TBDR_TXDATA_MASK                 (0xFFFFFFFFU)
#define QuadSPI_TBDR_TXDATA_SHIFT                (0U)
/*! TXDATA - TX data */
#define QuadSPI_TBDR_TXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_TBDR_TXDATA_SHIFT)) & QuadSPI_TBDR_TXDATA_MASK)
/*! @} */

/*! @name TBCT - TX Buffer Control Register */
/*! @{ */

#define QuadSPI_TBCT_WMRK_MASK                   (0x1FU)
#define QuadSPI_TBCT_WMRK_SHIFT                  (0U)
/*! WMRK - Watermark for TX buffer */
#define QuadSPI_TBCT_WMRK(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_TBCT_WMRK_SHIFT)) & QuadSPI_TBCT_WMRK_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define QuadSPI_SR_BUSY_MASK                     (0x1U)
#define QuadSPI_SR_BUSY_SHIFT                    (0U)
/*! BUSY - Module busy */
#define QuadSPI_SR_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_BUSY_SHIFT)) & QuadSPI_SR_BUSY_MASK)

#define QuadSPI_SR_IP_ACC_MASK                   (0x2U)
#define QuadSPI_SR_IP_ACC_SHIFT                  (1U)
/*! IP_ACC - IP access */
#define QuadSPI_SR_IP_ACC(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_IP_ACC_SHIFT)) & QuadSPI_SR_IP_ACC_MASK)

#define QuadSPI_SR_AHB_ACC_MASK                  (0x4U)
#define QuadSPI_SR_AHB_ACC_SHIFT                 (2U)
/*! AHB_ACC - AHB read access */
#define QuadSPI_SR_AHB_ACC(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB_ACC_SHIFT)) & QuadSPI_SR_AHB_ACC_MASK)

#define QuadSPI_SR_AHBTRN_MASK                   (0x40U)
#define QuadSPI_SR_AHBTRN_SHIFT                  (6U)
/*! AHBTRN - AHB access transaction pending */
#define QuadSPI_SR_AHBTRN(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHBTRN_SHIFT)) & QuadSPI_SR_AHBTRN_MASK)

#define QuadSPI_SR_AHB0NE_MASK                   (0x80U)
#define QuadSPI_SR_AHB0NE_SHIFT                  (7U)
/*! AHB0NE - AHB 0 buffer not empty */
#define QuadSPI_SR_AHB0NE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB0NE_SHIFT)) & QuadSPI_SR_AHB0NE_MASK)

#define QuadSPI_SR_AHB1NE_MASK                   (0x100U)
#define QuadSPI_SR_AHB1NE_SHIFT                  (8U)
/*! AHB1NE - AHB 1 buffer not empty */
#define QuadSPI_SR_AHB1NE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB1NE_SHIFT)) & QuadSPI_SR_AHB1NE_MASK)

#define QuadSPI_SR_AHB2NE_MASK                   (0x200U)
#define QuadSPI_SR_AHB2NE_SHIFT                  (9U)
/*! AHB2NE - AHB 2 buffer not empty */
#define QuadSPI_SR_AHB2NE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB2NE_SHIFT)) & QuadSPI_SR_AHB2NE_MASK)

#define QuadSPI_SR_AHB3NE_MASK                   (0x400U)
#define QuadSPI_SR_AHB3NE_SHIFT                  (10U)
/*! AHB3NE - AHB 3 buffer not empty */
#define QuadSPI_SR_AHB3NE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB3NE_SHIFT)) & QuadSPI_SR_AHB3NE_MASK)

#define QuadSPI_SR_AHB0FUL_MASK                  (0x800U)
#define QuadSPI_SR_AHB0FUL_SHIFT                 (11U)
/*! AHB0FUL - AHB 0 buffer full */
#define QuadSPI_SR_AHB0FUL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB0FUL_SHIFT)) & QuadSPI_SR_AHB0FUL_MASK)

#define QuadSPI_SR_AHB1FUL_MASK                  (0x1000U)
#define QuadSPI_SR_AHB1FUL_SHIFT                 (12U)
/*! AHB1FUL - AHB 1 buffer full */
#define QuadSPI_SR_AHB1FUL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB1FUL_SHIFT)) & QuadSPI_SR_AHB1FUL_MASK)

#define QuadSPI_SR_AHB2FUL_MASK                  (0x2000U)
#define QuadSPI_SR_AHB2FUL_SHIFT                 (13U)
/*! AHB2FUL - AHB 2 buffer full */
#define QuadSPI_SR_AHB2FUL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB2FUL_SHIFT)) & QuadSPI_SR_AHB2FUL_MASK)

#define QuadSPI_SR_AHB3FUL_MASK                  (0x4000U)
#define QuadSPI_SR_AHB3FUL_SHIFT                 (14U)
/*! AHB3FUL - AHB 3 buffer full */
#define QuadSPI_SR_AHB3FUL(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_AHB3FUL_SHIFT)) & QuadSPI_SR_AHB3FUL_MASK)

#define QuadSPI_SR_RXWE_MASK                     (0x10000U)
#define QuadSPI_SR_RXWE_SHIFT                    (16U)
/*! RXWE - RX buffer watermark exceeded */
#define QuadSPI_SR_RXWE(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_RXWE_SHIFT)) & QuadSPI_SR_RXWE_MASK)

#define QuadSPI_SR_RXFULL_MASK                   (0x80000U)
#define QuadSPI_SR_RXFULL_SHIFT                  (19U)
/*! RXFULL - RX buffer full */
#define QuadSPI_SR_RXFULL(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_RXFULL_SHIFT)) & QuadSPI_SR_RXFULL_MASK)

#define QuadSPI_SR_RXDMA_MASK                    (0x800000U)
#define QuadSPI_SR_RXDMA_SHIFT                   (23U)
/*! RXDMA - RX buffer DMA */
#define QuadSPI_SR_RXDMA(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_RXDMA_SHIFT)) & QuadSPI_SR_RXDMA_MASK)

#define QuadSPI_SR_TXNE_MASK                     (0x1000000U)
#define QuadSPI_SR_TXNE_SHIFT                    (24U)
/*! TXNE - TX buffer not empty */
#define QuadSPI_SR_TXNE(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_TXNE_SHIFT)) & QuadSPI_SR_TXNE_MASK)

#define QuadSPI_SR_TXWA_MASK                     (0x2000000U)
#define QuadSPI_SR_TXWA_SHIFT                    (25U)
/*! TXWA - TX buffer watermark available */
#define QuadSPI_SR_TXWA(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_TXWA_SHIFT)) & QuadSPI_SR_TXWA_MASK)

#define QuadSPI_SR_TXDMA_MASK                    (0x4000000U)
#define QuadSPI_SR_TXDMA_SHIFT                   (26U)
/*! TXDMA - TX DMA */
#define QuadSPI_SR_TXDMA(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_TXDMA_SHIFT)) & QuadSPI_SR_TXDMA_MASK)

#define QuadSPI_SR_TXFULL_MASK                   (0x8000000U)
#define QuadSPI_SR_TXFULL_SHIFT                  (27U)
/*! TXFULL - TX buffer full */
#define QuadSPI_SR_TXFULL(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_SR_TXFULL_SHIFT)) & QuadSPI_SR_TXFULL_MASK)
/*! @} */

/*! @name FR - Flag Register */
/*! @{ */

#define QuadSPI_FR_TFF_MASK                      (0x1U)
#define QuadSPI_FR_TFF_SHIFT                     (0U)
/*! TFF - IP command transaction finished flag */
#define QuadSPI_FR_TFF(x)                        (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_TFF_SHIFT)) & QuadSPI_FR_TFF_MASK)

#define QuadSPI_FR_IPIEF_MASK                    (0x40U)
#define QuadSPI_FR_IPIEF_SHIFT                   (6U)
/*! IPIEF - IP command trigger could not be executed error flag */
#define QuadSPI_FR_IPIEF(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_IPIEF_SHIFT)) & QuadSPI_FR_IPIEF_MASK)

#define QuadSPI_FR_IPAEF_MASK                    (0x80U)
#define QuadSPI_FR_IPAEF_SHIFT                   (7U)
/*! IPAEF - IP command trigger during AHB access error flag */
#define QuadSPI_FR_IPAEF(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_IPAEF_SHIFT)) & QuadSPI_FR_IPAEF_MASK)

#define QuadSPI_FR_ABOF_MASK                     (0x1000U)
#define QuadSPI_FR_ABOF_SHIFT                    (12U)
/*! ABOF - AHB buffer overflow flag */
#define QuadSPI_FR_ABOF(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_ABOF_SHIFT)) & QuadSPI_FR_ABOF_MASK)

#define QuadSPI_FR_AIBSEF_MASK                   (0x2000U)
#define QuadSPI_FR_AIBSEF_SHIFT                  (13U)
/*! AIBSEF - AHB illegal burst size error flag */
#define QuadSPI_FR_AIBSEF(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_AIBSEF_SHIFT)) & QuadSPI_FR_AIBSEF_MASK)

#define QuadSPI_FR_AITEF_MASK                    (0x4000U)
#define QuadSPI_FR_AITEF_SHIFT                   (14U)
/*! AITEF - AHB illegal transaction error flag */
#define QuadSPI_FR_AITEF(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_AITEF_SHIFT)) & QuadSPI_FR_AITEF_MASK)

#define QuadSPI_FR_RBDF_MASK                     (0x10000U)
#define QuadSPI_FR_RBDF_SHIFT                    (16U)
/*! RBDF - RX buffer drain flag */
#define QuadSPI_FR_RBDF(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_RBDF_SHIFT)) & QuadSPI_FR_RBDF_MASK)

#define QuadSPI_FR_RBOF_MASK                     (0x20000U)
#define QuadSPI_FR_RBOF_SHIFT                    (17U)
/*! RBOF - RX buffer overflow flag */
#define QuadSPI_FR_RBOF(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_RBOF_SHIFT)) & QuadSPI_FR_RBOF_MASK)

#define QuadSPI_FR_ILLINE_MASK                   (0x800000U)
#define QuadSPI_FR_ILLINE_SHIFT                  (23U)
/*! ILLINE - Illegal instruction error flag */
#define QuadSPI_FR_ILLINE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_ILLINE_SHIFT)) & QuadSPI_FR_ILLINE_MASK)

#define QuadSPI_FR_TBUF_MASK                     (0x4000000U)
#define QuadSPI_FR_TBUF_SHIFT                    (26U)
/*! TBUF - TX buffer underrun flag */
#define QuadSPI_FR_TBUF(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_TBUF_SHIFT)) & QuadSPI_FR_TBUF_MASK)

#define QuadSPI_FR_TBFF_MASK                     (0x8000000U)
#define QuadSPI_FR_TBFF_SHIFT                    (27U)
/*! TBFF - TX buffer fill flag */
#define QuadSPI_FR_TBFF(x)                       (((uint32_t)(((uint32_t)(x)) << QuadSPI_FR_TBFF_SHIFT)) & QuadSPI_FR_TBFF_MASK)
/*! @} */

/*! @name RSER - Interrupt and DMA Request Select and Enable Register */
/*! @{ */

#define QuadSPI_RSER_TFIE_MASK                   (0x1U)
#define QuadSPI_RSER_TFIE_SHIFT                  (0U)
/*! TFIE - Transaction finished interrupt enable flag
 *  0b0..No TFF interrupt is generated.
 *  0b1..TFF interrupt is generated.
 */
#define QuadSPI_RSER_TFIE(x)                     (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_TFIE_SHIFT)) & QuadSPI_RSER_TFIE_MASK)

#define QuadSPI_RSER_IPIEIE_MASK                 (0x40U)
#define QuadSPI_RSER_IPIEIE_SHIFT                (6U)
/*! IPIEIE - IP command trigger during IP access error interrupt enable flag
 *  0b0..No IPIEF interrupt is generated
 *  0b1..IPIEF interrupt is generated
 */
#define QuadSPI_RSER_IPIEIE(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_IPIEIE_SHIFT)) & QuadSPI_RSER_IPIEIE_MASK)

#define QuadSPI_RSER_IPAEIE_MASK                 (0x80U)
#define QuadSPI_RSER_IPAEIE_SHIFT                (7U)
/*! IPAEIE - IP command trigger during AHB read access error interrupt enable flag
 *  0b0..No IPAEF interrupt is generated
 *  0b1..IPAEF interrupt is generated
 */
#define QuadSPI_RSER_IPAEIE(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_IPAEIE_SHIFT)) & QuadSPI_RSER_IPAEIE_MASK)

#define QuadSPI_RSER_ABOIE_MASK                  (0x1000U)
#define QuadSPI_RSER_ABOIE_SHIFT                 (12U)
/*! ABOIE - AHB buffer overflow interrupt enable flag
 *  0b0..No ABOF interrupt is generated.
 *  0b1..ABOF interrupt is generated.
 */
#define QuadSPI_RSER_ABOIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_ABOIE_SHIFT)) & QuadSPI_RSER_ABOIE_MASK)

#define QuadSPI_RSER_AIBSIE_MASK                 (0x2000U)
#define QuadSPI_RSER_AIBSIE_SHIFT                (13U)
/*! AIBSIE - AHB illegal burst size interrupt enable flag
 *  0b0..No AIBSEF interrupt is generated.
 *  0b1..AIBSEF interrupt is generated.
 */
#define QuadSPI_RSER_AIBSIE(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_AIBSIE_SHIFT)) & QuadSPI_RSER_AIBSIE_MASK)

#define QuadSPI_RSER_AITIE_MASK                  (0x4000U)
#define QuadSPI_RSER_AITIE_SHIFT                 (14U)
/*! AITIE - AHB illegal transaction interrupt enable flag
 *  0b0..No AITEF interrupt is generated.
 *  0b1..AITEF interrupt is generated.
 */
#define QuadSPI_RSER_AITIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_AITIE_SHIFT)) & QuadSPI_RSER_AITIE_MASK)

#define QuadSPI_RSER_RBDIE_MASK                  (0x10000U)
#define QuadSPI_RSER_RBDIE_SHIFT                 (16U)
/*! RBDIE - RX buffer drain interrupt enable
 *  0b0..No RBDF interrupt is generated.
 *  0b1..RBDF Interrupt is generated.
 */
#define QuadSPI_RSER_RBDIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_RBDIE_SHIFT)) & QuadSPI_RSER_RBDIE_MASK)

#define QuadSPI_RSER_RBOIE_MASK                  (0x20000U)
#define QuadSPI_RSER_RBOIE_SHIFT                 (17U)
/*! RBOIE - RX buffer overflow interrupt enable
 *  0b0..No RBOF interrupt is generated.
 *  0b1..RBOF interrupt is generated.
 */
#define QuadSPI_RSER_RBOIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_RBOIE_SHIFT)) & QuadSPI_RSER_RBOIE_MASK)

#define QuadSPI_RSER_RBDDE_MASK                  (0x200000U)
#define QuadSPI_RSER_RBDDE_SHIFT                 (21U)
/*! RBDDE - RX buffer drain DMA enable
 *  0b0..No DMA request is generated.
 *  0b1..DMA request is generated.
 */
#define QuadSPI_RSER_RBDDE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_RBDDE_SHIFT)) & QuadSPI_RSER_RBDDE_MASK)

#define QuadSPI_RSER_ILLINIE_MASK                (0x800000U)
#define QuadSPI_RSER_ILLINIE_SHIFT               (23U)
/*! ILLINIE - Illegal instruction error interrupt enable
 *  0b0..No ILLINE interrupt is generated.
 *  0b1..ILLINE interrupt is generated.
 */
#define QuadSPI_RSER_ILLINIE(x)                  (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_ILLINIE_SHIFT)) & QuadSPI_RSER_ILLINIE_MASK)

#define QuadSPI_RSER_TBFDE_MASK                  (0x2000000U)
#define QuadSPI_RSER_TBFDE_SHIFT                 (25U)
/*! TBFDE - TX buffer fill DMA enable
 *  0b0..No DMA request is generated
 *  0b1..DMA request is generated
 */
#define QuadSPI_RSER_TBFDE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_TBFDE_SHIFT)) & QuadSPI_RSER_TBFDE_MASK)

#define QuadSPI_RSER_TBUIE_MASK                  (0x4000000U)
#define QuadSPI_RSER_TBUIE_SHIFT                 (26U)
/*! TBUIE - TX buffer underrun interrupt enable flag
 *  0b0..No TBUF interrupt is generated
 *  0b1..TBUF interrupt is generated
 */
#define QuadSPI_RSER_TBUIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_TBUIE_SHIFT)) & QuadSPI_RSER_TBUIE_MASK)

#define QuadSPI_RSER_TBFIE_MASK                  (0x8000000U)
#define QuadSPI_RSER_TBFIE_SHIFT                 (27U)
/*! TBFIE - TX buffer fill interrupt enable flag
 *  0b0..No TBFF interrupt is generated.
 *  0b1..TBFF interrupt is generated.
 */
#define QuadSPI_RSER_TBFIE(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_RSER_TBFIE_SHIFT)) & QuadSPI_RSER_TBFIE_MASK)
/*! @} */

/*! @name SPTRCLR - Sequence Pointer Clear Register */
/*! @{ */

#define QuadSPI_SPTRCLR_BFPTRC_MASK              (0x1U)
#define QuadSPI_SPTRCLR_BFPTRC_SHIFT             (0U)
/*! BFPTRC - Buffer pointer clear
 *  0b1..Clears the sequence pointer for AHB read accesses as defined in BFGENCR.
 */
#define QuadSPI_SPTRCLR_BFPTRC(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_SPTRCLR_BFPTRC_SHIFT)) & QuadSPI_SPTRCLR_BFPTRC_MASK)

#define QuadSPI_SPTRCLR_IPPTRC_MASK              (0x100U)
#define QuadSPI_SPTRCLR_IPPTRC_SHIFT             (8U)
/*! IPPTRC - IP pointer clear
 *  0b1..Clears the sequence pointer for IP accesses as defined in IPCR.
 */
#define QuadSPI_SPTRCLR_IPPTRC(x)                (((uint32_t)(((uint32_t)(x)) << QuadSPI_SPTRCLR_IPPTRC_SHIFT)) & QuadSPI_SPTRCLR_IPPTRC_MASK)
/*! @} */

/*! @name SFA1AD - Serial Flash Memory A1 Top Address Register */
/*! @{ */

#define QuadSPI_SFA1AD_TPADA1_MASK               (0xFFFFFC00U)
#define QuadSPI_SFA1AD_TPADA1_SHIFT              (10U)
/*! TPADA1 - Top address for serial flash memory A1 */
#define QuadSPI_SFA1AD_TPADA1(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_SFA1AD_TPADA1_SHIFT)) & QuadSPI_SFA1AD_TPADA1_MASK)
/*! @} */

/*! @name SFA2AD - Serial Flash Memory A2 Top Address Register */
/*! @{ */

#define QuadSPI_SFA2AD_TPADA2_MASK               (0xFFFFFC00U)
#define QuadSPI_SFA2AD_TPADA2_SHIFT              (10U)
/*! TPADA2 - Top address for serial flash memory A2 */
#define QuadSPI_SFA2AD_TPADA2(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_SFA2AD_TPADA2_SHIFT)) & QuadSPI_SFA2AD_TPADA2_MASK)
/*! @} */

/*! @name SFB1AD - Serial Flash Memory B1 Top Address Register */
/*! @{ */

#define QuadSPI_SFB1AD_TPADB1_MASK               (0xFFFFFC00U)
#define QuadSPI_SFB1AD_TPADB1_SHIFT              (10U)
/*! TPADB1 - Top address for serial flash memory B1. */
#define QuadSPI_SFB1AD_TPADB1(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_SFB1AD_TPADB1_SHIFT)) & QuadSPI_SFB1AD_TPADB1_MASK)
/*! @} */

/*! @name SFB2AD - Serial Flash Memory B2 Top Address Register */
/*! @{ */

#define QuadSPI_SFB2AD_TPADB2_MASK               (0xFFFFFC00U)
#define QuadSPI_SFB2AD_TPADB2_SHIFT              (10U)
/*! TPADB2 - Top address for serial flash memory B2. */
#define QuadSPI_SFB2AD_TPADB2(x)                 (((uint32_t)(((uint32_t)(x)) << QuadSPI_SFB2AD_TPADB2_SHIFT)) & QuadSPI_SFB2AD_TPADB2_MASK)
/*! @} */

/*! @name RBDR - RX Buffer Data Register */
/*! @{ */

#define QuadSPI_RBDR_RXDATA_MASK                 (0xFFFFFFFFU)
#define QuadSPI_RBDR_RXDATA_SHIFT                (0U)
/*! RXDATA - RX data */
#define QuadSPI_RBDR_RXDATA(x)                   (((uint32_t)(((uint32_t)(x)) << QuadSPI_RBDR_RXDATA_SHIFT)) & QuadSPI_RBDR_RXDATA_MASK)
/*! @} */

/*! @name LUTKEY - LUT Key Register */
/*! @{ */

#define QuadSPI_LUTKEY_KEY_MASK                  (0xFFFFFFFFU)
#define QuadSPI_LUTKEY_KEY_SHIFT                 (0U)
/*! KEY - Key to lock or unlock the LUT */
#define QuadSPI_LUTKEY_KEY(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUTKEY_KEY_SHIFT)) & QuadSPI_LUTKEY_KEY_MASK)
/*! @} */

/*! @name LCKCR - LUT Lock Configuration Register */
/*! @{ */

#define QuadSPI_LCKCR_LOCK_MASK                  (0x1U)
#define QuadSPI_LCKCR_LOCK_SHIFT                 (0U)
/*! LOCK - Lock LUT */
#define QuadSPI_LCKCR_LOCK(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LCKCR_LOCK_SHIFT)) & QuadSPI_LCKCR_LOCK_MASK)

#define QuadSPI_LCKCR_UNLOCK_MASK                (0x2U)
#define QuadSPI_LCKCR_UNLOCK_SHIFT               (1U)
/*! UNLOCK - Unlock LUT */
#define QuadSPI_LCKCR_UNLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << QuadSPI_LCKCR_UNLOCK_SHIFT)) & QuadSPI_LCKCR_UNLOCK_MASK)
/*! @} */

/*! @name LUT - LUT Register */
/*! @{ */

#define QuadSPI_LUT_OPRND0_MASK                  (0xFFU)
#define QuadSPI_LUT_OPRND0_SHIFT                 (0U)
/*! OPRND0 - Operand for INSTR0 */
#define QuadSPI_LUT_OPRND0(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_OPRND0_SHIFT)) & QuadSPI_LUT_OPRND0_MASK)

#define QuadSPI_LUT_PAD0_MASK                    (0x300U)
#define QuadSPI_LUT_PAD0_SHIFT                   (8U)
/*! PAD0 - Pad information for INSTR0
 *  0b00..1 Pad
 *  0b01..2 Pads
 *  0b10..4 Pads
 *  0b11..NA
 */
#define QuadSPI_LUT_PAD0(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_PAD0_SHIFT)) & QuadSPI_LUT_PAD0_MASK)

#define QuadSPI_LUT_INSTR0_MASK                  (0xFC00U)
#define QuadSPI_LUT_INSTR0_SHIFT                 (10U)
/*! INSTR0 - Instruction 0 */
#define QuadSPI_LUT_INSTR0(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_INSTR0_SHIFT)) & QuadSPI_LUT_INSTR0_MASK)

#define QuadSPI_LUT_OPRND1_MASK                  (0xFF0000U)
#define QuadSPI_LUT_OPRND1_SHIFT                 (16U)
/*! OPRND1 - Operand for INSTR1 */
#define QuadSPI_LUT_OPRND1(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_OPRND1_SHIFT)) & QuadSPI_LUT_OPRND1_MASK)

#define QuadSPI_LUT_PAD1_MASK                    (0x3000000U)
#define QuadSPI_LUT_PAD1_SHIFT                   (24U)
/*! PAD1 - Pad information for INSTR1
 *  0b00..1 Pad
 *  0b01..2 Pads
 *  0b10..4 Pads
 *  0b11..NA
 */
#define QuadSPI_LUT_PAD1(x)                      (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_PAD1_SHIFT)) & QuadSPI_LUT_PAD1_MASK)

#define QuadSPI_LUT_INSTR1_MASK                  (0xFC000000U)
#define QuadSPI_LUT_INSTR1_SHIFT                 (26U)
/*! INSTR1 - Instruction 1 */
#define QuadSPI_LUT_INSTR1(x)                    (((uint32_t)(((uint32_t)(x)) << QuadSPI_LUT_INSTR1_SHIFT)) & QuadSPI_LUT_INSTR1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group QuadSPI_Register_Masks */


/*!
 * @}
 */ /* end of group QuadSPI_Peripheral_Access_Layer */


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


#endif  /* PERI_QUADSPI_H_ */

