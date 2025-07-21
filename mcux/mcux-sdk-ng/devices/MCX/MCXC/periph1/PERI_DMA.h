/*
** ###################################################################
**     Processors:          MCXC141VFM
**                          MCXC141VLH
**                          MCXC142VFM
**                          MCXC242VFM
**                          MCXC242VLH
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-05-12)
**         Initial version.
**     - rev. 1.1 (2014-07-10)
**         UART0 - UART0 module renamed to UART2.
**     - rev. 1.2 (2014-08-12)
**         CRC - CRC register renamed to DATA.
**     - rev. 1.3 (2014-09-02)
**         USB - USB0_CTL0 was renamed to USB0_OTGCTL register.
**         USB - USB0_CTL1 was renamed to USB0_CTL register.
**         USB - Two new bitfields (STOP_ACK_DLY_EN, AHB_DLY_EN) was added to the USB0_KEEP_ALIVE_CTRL register.
**     - rev. 1.4 (2014-09-22)
**         FLEXIO - Offsets of the SHIFTBUFBIS registers were interchanged with offsets of the SHIFTBUFBBS registers.
**         SIM - Changed bitfield value MCGIRCLK to LIRC_CLK of bitfield CLKOUTSEL in SOPT2 register.
**         SIM - Removed bitfield DIEID in SDID register.
**         UART2 - Removed ED register.
**         UART2 - Removed MODEM register.
**         UART2 - Removed IR register.
**         UART2 - Removed PFIFO register.
**         UART2 - Removed CFIFO register.
**         UART2 - Removed SFIFO register.
**         UART2 - Removed TWFIFO register.
**         UART2 - Removed TCFIFO register.
**         UART2 - Removed RWFIFO register.
**         UART2 - Removed RCFIFO register.
**         USB - Removed bitfield REG_EN in CLK_RECOVER_IRC_EN register.
**         USB - Renamed USBEN bitfield of USB0_CTL was renamed to USBENSOFEN.
**     - rev. 1.5 (2016-02-02)
**         FGPIO - Add FGPIO registers.
**     - rev. 1.6 (2016-06-24)
**         USB - OTGCTL register was removed.
**         USB - Bit RESUME was added in CTL register.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC141VFM) || defined(CPU_MCXC141VLH))
#include "MCXC141_COMMON.h"
#elif (defined(CPU_MCXC142VFM))
#include "MCXC142_COMMON.h"
#elif (defined(CPU_MCXC242VFM) || defined(CPU_MCXC242VLH))
#include "MCXC242_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(DMA_REQUEST_SOURCE_T_)
#define DMA_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    kDmaRequestMux0Disable          = 0|0x100U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMux0Reserved1        = 1|0x100U,    /**< Reserved1 */
    kDmaRequestMux0LPUART0Rx        = 2|0x100U,    /**< LPUART0 Receive */
    kDmaRequestMux0LPUART0Tx        = 3|0x100U,    /**< LPUART0 Transmit */
    kDmaRequestMux0LPUART1Rx        = 4|0x100U,    /**< LPUART1 Receive */
    kDmaRequestMux0LPUART1Tx        = 5|0x100U,    /**< LPUART1 Transmit */
    kDmaRequestMux0UART2Rx          = 6|0x100U,    /**< UART2 Receive */
    kDmaRequestMux0UART2Tx          = 7|0x100U,    /**< UART2 Transmit */
    kDmaRequestMux0Reserved8        = 8|0x100U,    /**< Reserved8 */
    kDmaRequestMux0Reserved9        = 9|0x100U,    /**< Reserved9 */
    kDmaRequestMux0FlexIOChannel0   = 10|0x100U,   /**< FLEXIO Channel 0 */
    kDmaRequestMux0FlexIOChannel1   = 11|0x100U,   /**< FLEXIO Channel 1 */
    kDmaRequestMux0FlexIOChannel2   = 12|0x100U,   /**< FLEXIO Channel 2 */
    kDmaRequestMux0FlexIOChannel3   = 13|0x100U,   /**< FLEXIO Channel 3 */
    kDmaRequestMux0Reserved14       = 14|0x100U,   /**< Reserved14 */
    kDmaRequestMux0Reserved15       = 15|0x100U,   /**< Reserved15 */
    kDmaRequestMux0SPI0Rx           = 16|0x100U,   /**< SPI0 Receive */
    kDmaRequestMux0SPI0Tx           = 17|0x100U,   /**< SPI0 Transmit */
    kDmaRequestMux0SPI1Rx           = 18|0x100U,   /**< SPI1 Receive */
    kDmaRequestMux0SPI1Tx           = 19|0x100U,   /**< SPI1 Transmit */
    kDmaRequestMux0Reserved20       = 20|0x100U,   /**< Reserved20 */
    kDmaRequestMux0Reserved21       = 21|0x100U,   /**< Reserved21 */
    kDmaRequestMux0I2C0             = 22|0x100U,   /**< I2C0 */
    kDmaRequestMux0I2C1             = 23|0x100U,   /**< I2C1 */
    kDmaRequestMux0TPM0Channel0     = 24|0x100U,   /**< TPM0 Channel0 */
    kDmaRequestMux0TPM0Channel1     = 25|0x100U,   /**< TPM0 Channel1 */
    kDmaRequestMux0TPM0Channel2     = 26|0x100U,   /**< TPM0 Channel2 */
    kDmaRequestMux0TPM0Channel3     = 27|0x100U,   /**< TPM0 Channel3 */
    kDmaRequestMux0TPM0Channel4     = 28|0x100U,   /**< TPM0 Channel4 */
    kDmaRequestMux0TPM0Channel5     = 29|0x100U,   /**< TPM0 Channel5 */
    kDmaRequestMux0Reserved30       = 30|0x100U,   /**< Reserved30 */
    kDmaRequestMux0Reserved31       = 31|0x100U,   /**< Reserved31 */
    kDmaRequestMux0TPM1Channel0     = 32|0x100U,   /**< TPM1 Channel0 */
    kDmaRequestMux0TPM1Channel1     = 33|0x100U,   /**< TPM1 Channel1 */
    kDmaRequestMux0TPM2Channel0     = 34|0x100U,   /**< TPM2 Channel0 */
    kDmaRequestMux0TPM2Channel1     = 35|0x100U,   /**< TPM2 Channel1 */
    kDmaRequestMux0Reserved36       = 36|0x100U,   /**< Reserved36 */
    kDmaRequestMux0Reserved37       = 37|0x100U,   /**< Reserved37 */
    kDmaRequestMux0Reserved38       = 38|0x100U,   /**< Reserved38 */
    kDmaRequestMux0Reserved39       = 39|0x100U,   /**< Reserved39 */
    kDmaRequestMux0ADC0             = 40|0x100U,   /**< ADC0 */
    kDmaRequestMux0Reserved41       = 41|0x100U,   /**< Reserved41 */
    kDmaRequestMux0CMP0             = 42|0x100U,   /**< CMP0 */
    kDmaRequestMux0Reserved43       = 43|0x100U,   /**< Reserved43 */
    kDmaRequestMux0Reserved44       = 44|0x100U,   /**< Reserved44 */
    kDmaRequestMux0Reserved45       = 45|0x100U,   /**< Reserved45 */
    kDmaRequestMux0Reserved46       = 46|0x100U,   /**< Reserved46 */
    kDmaRequestMux0Reserved47       = 47|0x100U,   /**< Reserved47 */
    kDmaRequestMux0Reserved48       = 48|0x100U,   /**< Reserved48 */
    kDmaRequestMux0PortA            = 49|0x100U,   /**< PTA */
    kDmaRequestMux0PortB            = 50|0x100U,   /**< PTB */
    kDmaRequestMux0PortC            = 51|0x100U,   /**< PTC */
    kDmaRequestMux0PortD            = 52|0x100U,   /**< PTD */
    kDmaRequestMux0PortE            = 53|0x100U,   /**< PTE */
    kDmaRequestMux0TPM0Overflow     = 54|0x100U,   /**< TPM0 */
    kDmaRequestMux0TPM1Overflow     = 55|0x100U,   /**< TPM1 */
    kDmaRequestMux0TPM2Overflow     = 56|0x100U,   /**< TPM2 */
    kDmaRequestMux0Reserved57       = 57|0x100U,   /**< Reserved57 */
    kDmaRequestMux0Reserved58       = 58|0x100U,   /**< Reserved58 */
    kDmaRequestMux0Reserved59       = 59|0x100U,   /**< Reserved59 */
    kDmaRequestMux0AlwaysOn60       = 60|0x100U,   /**< DMAMUX Always Enabled slot */
    kDmaRequestMux0AlwaysOn61       = 61|0x100U,   /**< DMAMUX Always Enabled slot */
    kDmaRequestMux0AlwaysOn62       = 62|0x100U,   /**< DMAMUX Always Enabled slot */
    kDmaRequestMux0AlwaysOn63       = 63|0x100U,   /**< DMAMUX Always Enabled slot */
} dma_request_source_t;

/* @} */
#endif /* DMA_REQUEST_SOURCE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_DMA_COUNT                             4u

/** DMA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t SAR;                               /**< Source Address Register, array offset: 0x100, array step: 0x10 */
    __IO uint32_t DAR;                               /**< Destination Address Register, array offset: 0x104, array step: 0x10 */
    union {                                          /* offset: 0x108, array step: 0x10 */
      struct {                                         /* offset: 0x108, array step: 0x10 */
             uint8_t RESERVED_0[3];
             uint8_t DSR;                                /**< DMA_DSR0 register...DMA_DSR3 register., array offset: 0x10B, array step: 0x10 */
      } DMA_DSR_ACCESS8BIT;
      __IO uint32_t DSR_BCR;                           /**< DMA Status Register / Byte Count Register, array offset: 0x108, array step: 0x10 */
    };
    __IO uint32_t DCR;                               /**< DMA Control Register, array offset: 0x10C, array step: 0x10 */
  } DMA[DMA_DMA_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name SAR - Source Address Register */
/*! @{ */

#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFU)
#define DMA_SAR_SAR_SHIFT                        (0U)
/*! SAR - SAR */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_SAR_SAR_SHIFT)) & DMA_SAR_SAR_MASK)
/*! @} */

/* The count of DMA_SAR */
#define DMA_SAR_COUNT                            (4U)

/*! @name DAR - Destination Address Register */
/*! @{ */

#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFU)
#define DMA_DAR_DAR_SHIFT                        (0U)
/*! DAR - DAR */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DAR_DAR_SHIFT)) & DMA_DAR_DAR_MASK)
/*! @} */

/* The count of DMA_DAR */
#define DMA_DAR_COUNT                            (4U)

/* The count of DMA_DSR */
#define DMA_DSR_COUNT                            (4U)

/*! @name DSR_BCR - DMA Status Register / Byte Count Register */
/*! @{ */

#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFU)
#define DMA_DSR_BCR_BCR_SHIFT                    (0U)
/*! BCR - BCR */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BCR_SHIFT)) & DMA_DSR_BCR_BCR_MASK)

#define DMA_DSR_BCR_DONE_MASK                    (0x1000000U)
#define DMA_DSR_BCR_DONE_SHIFT                   (24U)
/*! DONE - Transactions Done
 *  0b0..DMA transfer is not yet complete. Writing a 0 has no effect.
 *  0b1..DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an
 *       interrupt service routine to clear the DMA interrupt and error bits.
 */
#define DMA_DSR_BCR_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_DONE_SHIFT)) & DMA_DSR_BCR_DONE_MASK)

#define DMA_DSR_BCR_BSY_MASK                     (0x2000000U)
#define DMA_DSR_BCR_BSY_SHIFT                    (25U)
/*! BSY - Busy
 *  0b0..DMA channel is inactive. Cleared when the DMA has finished the last transaction.
 *  0b1..BSY is set the first time the channel is enabled after a transfer is initiated.
 */
#define DMA_DSR_BCR_BSY(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BSY_SHIFT)) & DMA_DSR_BCR_BSY_MASK)

#define DMA_DSR_BCR_REQ_MASK                     (0x4000000U)
#define DMA_DSR_BCR_REQ_SHIFT                    (26U)
/*! REQ - Request
 *  0b0..No request is pending or the channel is currently active. Cleared when the channel is selected.
 *  0b1..The DMA channel has a transfer remaining and the channel is not selected.
 */
#define DMA_DSR_BCR_REQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_REQ_SHIFT)) & DMA_DSR_BCR_REQ_MASK)

#define DMA_DSR_BCR_BED_MASK                     (0x10000000U)
#define DMA_DSR_BCR_BED_SHIFT                    (28U)
/*! BED - Bus Error on Destination
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the write portion of a transfer.
 */
#define DMA_DSR_BCR_BED(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BED_SHIFT)) & DMA_DSR_BCR_BED_MASK)

#define DMA_DSR_BCR_BES_MASK                     (0x20000000U)
#define DMA_DSR_BCR_BES_SHIFT                    (29U)
/*! BES - Bus Error on Source
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the read portion of a transfer.
 */
#define DMA_DSR_BCR_BES(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BES_SHIFT)) & DMA_DSR_BCR_BES_MASK)

#define DMA_DSR_BCR_CE_MASK                      (0x40000000U)
#define DMA_DSR_BCR_CE_SHIFT                     (30U)
/*! CE - Configuration Error
 *  0b0..No configuration error exists.
 *  0b1..A configuration error has occurred.
 */
#define DMA_DSR_BCR_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_CE_SHIFT)) & DMA_DSR_BCR_CE_MASK)
/*! @} */

/* The count of DMA_DSR_BCR */
#define DMA_DSR_BCR_COUNT                        (4U)

/*! @name DCR - DMA Control Register */
/*! @{ */

#define DMA_DCR_LCH2_MASK                        (0x3U)
#define DMA_DCR_LCH2_SHIFT                       (0U)
/*! LCH2 - Link Channel 2
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH2_SHIFT)) & DMA_DCR_LCH2_MASK)

#define DMA_DCR_LCH1_MASK                        (0xCU)
#define DMA_DCR_LCH1_SHIFT                       (2U)
/*! LCH1 - Link Channel 1
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH1_SHIFT)) & DMA_DCR_LCH1_MASK)

#define DMA_DCR_LINKCC_MASK                      (0x30U)
#define DMA_DCR_LINKCC_SHIFT                     (4U)
/*! LINKCC - Link Channel Control
 *  0b00..No channel-to-channel linking
 *  0b01..Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to 0.
 *  0b10..Perform a link to channel LCH1 after each cycle-steal transfer
 *  0b11..Perform a link to channel LCH1 after the BCR decrements to 0.
 */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LINKCC_SHIFT)) & DMA_DCR_LINKCC_MASK)

#define DMA_DCR_D_REQ_MASK                       (0x80U)
#define DMA_DCR_D_REQ_SHIFT                      (7U)
/*! D_REQ - Disable Request
 *  0b0..ERQ bit is not affected.
 *  0b1..ERQ bit is cleared when the BCR is exhausted.
 */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_D_REQ_SHIFT)) & DMA_DCR_D_REQ_MASK)

#define DMA_DCR_DMOD_MASK                        (0xF00U)
#define DMA_DCR_DMOD_SHIFT                       (8U)
/*! DMOD - Destination Address Modulo
 *  0b0000..Buffer disabled
 *  0b0001..Circular buffer size is 16 bytes
 *  0b0010..Circular buffer size is 32 bytes
 *  0b0011..Circular buffer size is 64 bytes
 *  0b0100..Circular buffer size is 128 bytes
 *  0b0101..Circular buffer size is 256 bytes
 *  0b0110..Circular buffer size is 512 bytes
 *  0b0111..Circular buffer size is 1 KB
 *  0b1000..Circular buffer size is 2 KB
 *  0b1001..Circular buffer size is 4 KB
 *  0b1010..Circular buffer size is 8 KB
 *  0b1011..Circular buffer size is 16 KB
 *  0b1100..Circular buffer size is 32 KB
 *  0b1101..Circular buffer size is 64 KB
 *  0b1110..Circular buffer size is 128 KB
 *  0b1111..Circular buffer size is 256 KB
 */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DMOD_SHIFT)) & DMA_DCR_DMOD_MASK)

#define DMA_DCR_SMOD_MASK                        (0xF000U)
#define DMA_DCR_SMOD_SHIFT                       (12U)
/*! SMOD - Source Address Modulo
 *  0b0000..Buffer disabled
 *  0b0001..Circular buffer size is 16 bytes.
 *  0b0010..Circular buffer size is 32 bytes.
 *  0b0011..Circular buffer size is 64 bytes.
 *  0b0100..Circular buffer size is 128 bytes.
 *  0b0101..Circular buffer size is 256 bytes.
 *  0b0110..Circular buffer size is 512 bytes.
 *  0b0111..Circular buffer size is 1 KB.
 *  0b1000..Circular buffer size is 2 KB.
 *  0b1001..Circular buffer size is 4 KB.
 *  0b1010..Circular buffer size is 8 KB.
 *  0b1011..Circular buffer size is 16 KB.
 *  0b1100..Circular buffer size is 32 KB.
 *  0b1101..Circular buffer size is 64 KB.
 *  0b1110..Circular buffer size is 128 KB.
 *  0b1111..Circular buffer size is 256 KB.
 */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SMOD_SHIFT)) & DMA_DCR_SMOD_MASK)

#define DMA_DCR_START_MASK                       (0x10000U)
#define DMA_DCR_START_SHIFT                      (16U)
/*! START - Start Transfer
 *  0b0..DMA inactive
 *  0b1..The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after
 *       one module clock and always reads as logic 0.
 */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_START_SHIFT)) & DMA_DCR_START_MASK)

#define DMA_DCR_DSIZE_MASK                       (0x60000U)
#define DMA_DCR_DSIZE_SHIFT                      (17U)
/*! DSIZE - Destination Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DSIZE_SHIFT)) & DMA_DCR_DSIZE_MASK)

#define DMA_DCR_DINC_MASK                        (0x80000U)
#define DMA_DCR_DINC_SHIFT                       (19U)
/*! DINC - Destination Increment
 *  0b0..No change to the DAR after a successful transfer.
 *  0b1..The DAR increments by 1, 2, 4 depending upon the size of the transfer.
 */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DINC_SHIFT)) & DMA_DCR_DINC_MASK)

#define DMA_DCR_SSIZE_MASK                       (0x300000U)
#define DMA_DCR_SSIZE_SHIFT                      (20U)
/*! SSIZE - Source Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SSIZE_SHIFT)) & DMA_DCR_SSIZE_MASK)

#define DMA_DCR_SINC_MASK                        (0x400000U)
#define DMA_DCR_SINC_SHIFT                       (22U)
/*! SINC - Source Increment
 *  0b0..No change to SAR after a successful transfer.
 *  0b1..The SAR increments by 1, 2, 4 as determined by the transfer size.
 */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SINC_SHIFT)) & DMA_DCR_SINC_MASK)

#define DMA_DCR_EADREQ_MASK                      (0x800000U)
#define DMA_DCR_EADREQ_SHIFT                     (23U)
/*! EADREQ - Enable asynchronous DMA requests
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DMA_DCR_EADREQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DCR_EADREQ_SHIFT)) & DMA_DCR_EADREQ_MASK)

#define DMA_DCR_AA_MASK                          (0x10000000U)
#define DMA_DCR_AA_SHIFT                         (28U)
/*! AA - Auto-align
 *  0b0..Auto-align disabled
 *  0b1..If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise,
 *       destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If
 *       auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.
 */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_AA_SHIFT)) & DMA_DCR_AA_MASK)

#define DMA_DCR_CS_MASK                          (0x20000000U)
#define DMA_DCR_CS_SHIFT                         (29U)
/*! CS - Cycle Steal
 *  0b0..DMA continuously makes read/write transfers until the BCR decrements to 0.
 *  0b1..Forces a single read/write transfer per request.
 */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_CS_SHIFT)) & DMA_DCR_CS_MASK)

#define DMA_DCR_ERQ_MASK                         (0x40000000U)
#define DMA_DCR_ERQ_SHIFT                        (30U)
/*! ERQ - Enable Peripheral Request
 *  0b0..Peripheral request is ignored.
 *  0b1..Enables peripheral request to initiate transfer. A software-initiated request (setting START) is always enabled.
 */
#define DMA_DCR_ERQ(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DCR_ERQ_SHIFT)) & DMA_DCR_ERQ_MASK)

#define DMA_DCR_EINT_MASK                        (0x80000000U)
#define DMA_DCR_EINT_SHIFT                       (31U)
/*! EINT - Enable Interrupt on Completion of Transfer
 *  0b0..No interrupt is generated.
 *  0b1..Interrupt signal is enabled.
 */
#define DMA_DCR_EINT(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_EINT_SHIFT)) & DMA_DCR_EINT_MASK)
/*! @} */

/* The count of DMA_DCR */
#define DMA_DCR_COUNT                            (4U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */

