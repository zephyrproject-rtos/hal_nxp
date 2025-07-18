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
**     - rev. 0.1 (2020-12-11)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

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
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(DMA_CHANNEL_REQUEST_SOURCE_T_)
#define DMA_CHANNEL_REQUEST_SOURCE_T_
/*!
 * @brief DMA channel request source
 *
 * Enumeration member bitfield:
 *   BIT8~BIT15: DMA Channel Number.
 *   BIT0~BIT7: DMA Channel Input.
 */
typedef enum _dma_channel_request_source
{
    kDmaCH0_SCI0_TE                 = 0x0000U,     /**< SCI0 Transmitter Empty */
    kDmaCH0_SPI0_RF                 = 0x0002U,     /**< SPI0 Receiver Full */
    kDmaCH0_IIC_ipd_Req             = 0x0004U,     /**< IIC DMA Req */
    kDmaCH0_TMRA0_CP                = 0x0005U,     /**< TMRA0 Capture */
    kDmaCH0_TMRA0_CMPLD1orTMRA1_CMPLD2 = 0x0006U,  /**< TMRA0 Compare1 or TMRA1 Compare2 */
    kDmaCH0_PWMA3_CP                = 0x0009U,     /**< Submodule3 Capture DMA Req */
    kDmaCH0_PWMA0_WR                = 0x000AU,     /**< SubModule0 Value write DMA Req */
    kDmaCH0_ADCA_ES                 = 0x000CU,     /**< ADCA(Cyclic) End of Scan */
    kDmaCH0_ADCB_ES                 = 0x000DU,     /**< ADCB(Cyclic) End of Scan */
    kDmaCH0_XBAR_DSC0               = 0x000FU,     /**< XBAR DMA Req 0 */
    kDmaCH1_SCI0_RF                 = 0x0101U,     /**< SCI0 Receiver Full */
    kDmaCH1_SPI0_TE                 = 0x0102U,     /**< SPI0 Transmitter Empty */
    kDmaCH1_IIC_ipd_Req             = 0x0104U,     /**< IIC DMA Req */
    kDmaCH1_TMRA1_CP                = 0x0105U,     /**< TMRA1 Capture */
    kDmaCH1_TMRA0_CMPLD2orTMRA1_CMPLD1 = 0x0106U,  /**< TMRA0 Compare2 or TMRA1 Compare1 */
    kDmaCH1_PWMA2_CP                = 0x0109U,     /**< Submodule2 Capture DMA Req */
    kDmaCH1_PWMA1_WR                = 0x010AU,     /**< SubModule1 Value write DMA Req */
    kDmaCH1_ADCA_ES                 = 0x010CU,     /**< ADCA(Cyclic) End of Scan */
    kDmaCH1_ADCB_ES                 = 0x010DU,     /**< ADCB(Cyclic) End of Scan */
    kDmaCH1_XBAR_DSC1               = 0x010FU,     /**< XBAR DMA Req 1 */
    kDmaCH2_SCI0_RF                 = 0x0201U,     /**< SCI0 Receiver Full */
    kDmaCH2_SPI0_RF                 = 0x0202U,     /**< SPI0 Receiver Full */
    kDmaCH2_IIC_ipd_Req             = 0x0204U,     /**< IIC DMA Req */
    kDmaCH2_TMRA2_CP                = 0x0205U,     /**< TMRA2 Capture */
    kDmaCH2_TMRA2_CMPLD1orTMRA3_CMPLD2 = 0x0206U,  /**< TMRA2 Compare1 or TMRA3 Compare2 */
    kDmaCH2_PWMA1_CP                = 0x0209U,     /**< Submodule1 Capture DMA Req */
    kDmaCH2_PWMA2_WR                = 0x020AU,     /**< SubModule2 Value write DMA Req */
    kDmaCH2_ADCA_ES                 = 0x020CU,     /**< ADCA(Cyclic) End of Scan */
    kDmaCH2_ADCB_ES                 = 0x020DU,     /**< ADCB(Cyclic) End of Scan */
    kDmaCH2_XBAR_DSC2               = 0x020FU,     /**< XBAR DMA Req 2 */
    kDmaCH3_SCI0_TE                 = 0x0300U,     /**< SCI0 Transmitter Empty */
    kDmaCH3_SPI0_TE                 = 0x0302U,     /**< SPI0 Transmitter Empty */
    kDmaCH3_IIC_ipd_Req             = 0x0304U,     /**< IIC DMA Req */
    kDmaCH3_TMRA3_CP                = 0x0305U,     /**< TMRA3 Capture */
    kDmaCH3_TMRA2_CMPLD2orTMRA3_CMPLD1 = 0x0306U,  /**< TMRA2 Compare2 or TMRA3 Compare1 */
    kDmaCH3_PWMA0_CP                = 0x0309U,     /**< Submodule0 Capture DMA Req */
    kDmaCH3_PWMA3_WR                = 0x030AU,     /**< SubModule3 Value write DMA Req */
    kDmaCH3_ADCA_ES                 = 0x030CU,     /**< ADCA(Cyclic) End of Scan */
    kDmaCH3_ADCB_ES                 = 0x030DU,     /**< ADCB(Cyclic) End of Scan */
    kDmaCH3_XBAR_DSC3               = 0x030FU,     /**< XBAR DMA Req 3 */
    kDmaCH0_SCI1_RF                 = 0x0001U,     /**< SCI1 Receiver Full */
    kDmaCH0_DACB_FIFO               = 0x000BU,     /**< 12bit DACB FIFO Water Mark */
    kDmaCH1_SCI1_TE                 = 0x0100U,     /**< SCI1 Transmitter Empty */
    kDmaCH1_DACA_FIFO               = 0x010BU,     /**< 12bit DACA FIFO Water Mark */
    kDmaCH2_SCI1_TE                 = 0x0200U,     /**< SCI1 Transmitter Empty */
    kDmaCH2_DACB_FIFO               = 0x020BU,     /**< 12bit DACB FIFO Water Mark */
    kDmaCH3_SCI1_RF                 = 0x0301U,     /**< SCI1 Receiver Full */
    kDmaCH3_DACA_FIFO               = 0x030BU,     /**< 12bit DACA FIFO Water Mark */
    kDmaCH0_SPI1_TE                 = 0x0003U,     /**< SPI1 Transmitter Empty */
    kDmaCH1_SPI1_RF                 = 0x0103U,     /**< SPI1 Receiver Full */
    kDmaCH2_SPI1_TE                 = 0x0203U,     /**< SPI1 Transmitter Empty */
    kDmaCH3_SPI1_RF                 = 0x0303U,     /**< SPI1 Receiver Full */
} dma_channel_request_source_t;
#endif /* DMA_CHANNEL_REQUEST_SOURCE_T_ */


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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
  __IO uint32_t REQC;                              /**< DMA Request Control Register, offset: 0x0 */
       uint16_t RESERVED_0[126];
  struct {                                         /* offset: 0x80, array step: 0x8 */
    __IO uint32_t SAR;                               /**< Source Address Register, array offset: 0x80, array step: 0x8 */
    __IO uint32_t DAR;                               /**< Destination Address Register, array offset: 0x82, array step: 0x8 */
    __IO uint32_t DSR_BCR;                           /**< DMA Status Register / Byte Count Register, array offset: 0x84, array step: 0x8 */
    __IO uint32_t DCR;                               /**< DMA Control Register, array offset: 0x86, array step: 0x8 */
  } DMA[DMA_DMA_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name REQC - DMA Request Control Register */
/*! @{ */

#define DMA_REQC_DMAC3_MASK                      (0xFUL)
#define DMA_REQC_DMAC3_SHIFT                     (0UL)
/*! DMAC3 - DMA channel 3
 *  0b0000..Select request 0 as the source
 *  0b0001..Select request 1 as the source
 *  0b0010..Select request 2 as the source
 *  0b0011..Select request 3 as the source
 *  0b0100..Select request 4 as the source
 *  0b0101..Select request 5 as the source
 *  0b0110..Select request 6 as the source
 *  0b0111..Select request 7 as the source
 *  0b1000..Select request 8 as the source
 *  0b1001..Select request 9 as the source
 *  0b1010..Select request 10 as the source
 *  0b1011..Select request 11 as the source
 *  0b1100..Select request 12 as the source
 *  0b1101..Select request 13 as the source
 *  0b1110..Select request 14 as the source
 *  0b1111..Select request 15 as the source
 */
#define DMA_REQC_DMAC3(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_DMAC3_SHIFT)) & DMA_REQC_DMAC3_MASK)

#define DMA_REQC_CFSM3_MASK                      (0x80UL)
#define DMA_REQC_CFSM3_SHIFT                     (7UL)
/*! CFSM3 - Clear state machine control 3
 *  0b0..No effect
 *  0b1..Clear state machine for DMA channel 3
 */
#define DMA_REQC_CFSM3(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_CFSM3_SHIFT)) & DMA_REQC_CFSM3_MASK)

#define DMA_REQC_DMAC2_MASK                      (0xF00UL)
#define DMA_REQC_DMAC2_SHIFT                     (8UL)
/*! DMAC2 - DMA channel 2
 *  0b0000..Select request 0 as the source
 *  0b0001..Select request 1 as the source
 *  0b0010..Select request 2 as the source
 *  0b0011..Select request 3 as the source
 *  0b0100..Select request 4 as the source
 *  0b0101..Select request 5 as the source
 *  0b0110..Select request 6 as the source
 *  0b0111..Select request 7 as the source
 *  0b1000..Select request 8 as the source
 *  0b1001..Select request 9 as the source
 *  0b1010..Select request 10 as the source
 *  0b1011..Select request 11 as the source
 *  0b1100..Select request 12 as the source
 *  0b1101..Select request 13 as the source
 *  0b1110..Select request 14 as the source
 *  0b1111..Select request 15 as the source
 */
#define DMA_REQC_DMAC2(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_DMAC2_SHIFT)) & DMA_REQC_DMAC2_MASK)

#define DMA_REQC_CFSM2_MASK                      (0x8000UL)
#define DMA_REQC_CFSM2_SHIFT                     (15UL)
/*! CFSM2 - Clear state machine control 2
 *  0b0..No effect
 *  0b1..Clear state machine for DMA channel 2
 */
#define DMA_REQC_CFSM2(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_CFSM2_SHIFT)) & DMA_REQC_CFSM2_MASK)

#define DMA_REQC_DMAC1_MASK                      (0xF0000UL)
#define DMA_REQC_DMAC1_SHIFT                     (16UL)
/*! DMAC1 - DMA channel 1
 *  0b0000..Select request 0 as the source
 *  0b0001..Select request 1 as the source
 *  0b0010..Select request 2 as the source
 *  0b0011..Select request 3 as the source
 *  0b0100..Select request 4 as the source
 *  0b0101..Select request 5 as the source
 *  0b0110..Select request 6 as the source
 *  0b0111..Select request 7 as the source
 *  0b1000..Select request 8 as the source
 *  0b1001..Select request 9 as the source
 *  0b1010..Select request 10 as the source
 *  0b1011..Select request 11 as the source
 *  0b1100..Select request 12 as the source
 *  0b1101..Select request 13 as the source
 *  0b1110..Select request 14 as the source
 *  0b1111..Select request 15 as the source
 */
#define DMA_REQC_DMAC1(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_DMAC1_SHIFT)) & DMA_REQC_DMAC1_MASK)

#define DMA_REQC_CFSM1_MASK                      (0x800000UL)
#define DMA_REQC_CFSM1_SHIFT                     (23UL)
/*! CFSM1 - Clear state machine control 1
 *  0b0..No effect
 *  0b1..Clear state machine for DMA channel 1
 */
#define DMA_REQC_CFSM1(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_CFSM1_SHIFT)) & DMA_REQC_CFSM1_MASK)

#define DMA_REQC_DMAC0_MASK                      (0xF000000UL)
#define DMA_REQC_DMAC0_SHIFT                     (24UL)
/*! DMAC0 - DMA channel 0
 *  0b0000..Select request 0 as the source
 *  0b0001..Select request 1 as the source
 *  0b0010..Select request 2 as the source
 *  0b0011..Select request 3 as the source
 *  0b0100..Select request 4 as the source
 *  0b0101..Select request 5 as the source
 *  0b0110..Select request 6 as the source
 *  0b0111..Select request 7 as the source
 *  0b1000..Select request 8 as the source
 *  0b1001..Select request 9 as the source
 *  0b1010..Select request 10 as the source
 *  0b1011..Select request 11 as the source
 *  0b1100..Select request 12 as the source
 *  0b1101..Select request 13 as the source
 *  0b1110..Select request 14 as the source
 *  0b1111..Select request 15 as the source
 */
#define DMA_REQC_DMAC0(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_DMAC0_SHIFT)) & DMA_REQC_DMAC0_MASK)

#define DMA_REQC_CFSM0_MASK                      (0x80000000UL)
#define DMA_REQC_CFSM0_SHIFT                     (31UL)
/*! CFSM0 - Clear state machine control 0
 *  0b0..No effect
 *  0b1..Clear state machine for DMA channel 0
 */
#define DMA_REQC_CFSM0(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_REQC_CFSM0_SHIFT)) & DMA_REQC_CFSM0_MASK)
/*! @} */

/*! @name SAR - Source Address Register */
/*! @{ */

#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFUL)
#define DMA_SAR_SAR_SHIFT                        (0UL)
/*! SAR - SAR */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_SAR_SAR_SHIFT)) & DMA_SAR_SAR_MASK)
/*! @} */

/* The count of DMA_SAR */
#define DMA_SAR_COUNT                            (4U)

/*! @name DAR - Destination Address Register */
/*! @{ */

#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFUL)
#define DMA_DAR_DAR_SHIFT                        (0UL)
/*! DAR - DAR */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DAR_DAR_SHIFT)) & DMA_DAR_DAR_MASK)
/*! @} */

/* The count of DMA_DAR */
#define DMA_DAR_COUNT                            (4U)

/*! @name DSR_BCR - DMA Status Register / Byte Count Register */
/*! @{ */

#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFUL)
#define DMA_DSR_BCR_BCR_SHIFT                    (0UL)
/*! BCR - BCR */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BCR_SHIFT)) & DMA_DSR_BCR_BCR_MASK)

#define DMA_DSR_BCR_DONE_MASK                    (0x1000000UL)
#define DMA_DSR_BCR_DONE_SHIFT                   (24UL)
/*! DONE - Transactions Done
 *  0b0..DMA transfer is not yet complete. Writing a 0 has no effect.
 *  0b1..DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an
 *       interrupt service routine to clear the DMA interrupt and error bits.
 */
#define DMA_DSR_BCR_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_DONE_SHIFT)) & DMA_DSR_BCR_DONE_MASK)

#define DMA_DSR_BCR_BSY_MASK                     (0x2000000UL)
#define DMA_DSR_BCR_BSY_SHIFT                    (25UL)
/*! BSY - Busy
 *  0b0..DMA channel is inactive. Cleared when the DMA has finished the last transaction.
 *  0b1..BSY is set the first time the channel is enabled after a transfer is initiated.
 */
#define DMA_DSR_BCR_BSY(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BSY_SHIFT)) & DMA_DSR_BCR_BSY_MASK)

#define DMA_DSR_BCR_REQ_MASK                     (0x4000000UL)
#define DMA_DSR_BCR_REQ_SHIFT                    (26UL)
/*! REQ - Request
 *  0b0..No request is pending or the channel is currently active. Cleared when the channel is selected.
 *  0b1..The DMA channel has a transfer remaining and the channel is not selected.
 */
#define DMA_DSR_BCR_REQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_REQ_SHIFT)) & DMA_DSR_BCR_REQ_MASK)

#define DMA_DSR_BCR_BED_MASK                     (0x10000000UL)
#define DMA_DSR_BCR_BED_SHIFT                    (28UL)
/*! BED - Bus Error on Destination
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the write portion of a transfer.
 */
#define DMA_DSR_BCR_BED(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BED_SHIFT)) & DMA_DSR_BCR_BED_MASK)

#define DMA_DSR_BCR_BES_MASK                     (0x20000000UL)
#define DMA_DSR_BCR_BES_SHIFT                    (29UL)
/*! BES - Bus Error on Source
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the read portion of a transfer.
 */
#define DMA_DSR_BCR_BES(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BES_SHIFT)) & DMA_DSR_BCR_BES_MASK)

#define DMA_DSR_BCR_CE_MASK                      (0x40000000UL)
#define DMA_DSR_BCR_CE_SHIFT                     (30UL)
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

#define DMA_DCR_LCH2_MASK                        (0x3UL)
#define DMA_DCR_LCH2_SHIFT                       (0UL)
/*! LCH2 - Link Channel 2
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH2_SHIFT)) & DMA_DCR_LCH2_MASK)

#define DMA_DCR_LCH1_MASK                        (0xCUL)
#define DMA_DCR_LCH1_SHIFT                       (2UL)
/*! LCH1 - Link Channel 1
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH1_SHIFT)) & DMA_DCR_LCH1_MASK)

#define DMA_DCR_LINKCC_MASK                      (0x30UL)
#define DMA_DCR_LINKCC_SHIFT                     (4UL)
/*! LINKCC - Link Channel Control
 *  0b00..No channel-to-channel linking
 *  0b01..Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to 0.
 *  0b10..Perform a link to channel LCH1 after each cycle-steal transfer
 *  0b11..Perform a link to channel LCH1 after the BCR decrements to 0.
 */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LINKCC_SHIFT)) & DMA_DCR_LINKCC_MASK)

#define DMA_DCR_D_REQ_MASK                       (0x80UL)
#define DMA_DCR_D_REQ_SHIFT                      (7UL)
/*! D_REQ - Disable Request
 *  0b0..ERQ bit is not affected.
 *  0b1..ERQ bit is cleared when the BCR is exhausted.
 */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_D_REQ_SHIFT)) & DMA_DCR_D_REQ_MASK)

#define DMA_DCR_DMOD_MASK                        (0xF00UL)
#define DMA_DCR_DMOD_SHIFT                       (8UL)
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

#define DMA_DCR_SMOD_MASK                        (0xF000UL)
#define DMA_DCR_SMOD_SHIFT                       (12UL)
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

#define DMA_DCR_START_MASK                       (0x10000UL)
#define DMA_DCR_START_SHIFT                      (16UL)
/*! START - Start Transfer
 *  0b0..DMA inactive
 *  0b1..The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after
 *       one module clock and always reads as logic 0.
 */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_START_SHIFT)) & DMA_DCR_START_MASK)

#define DMA_DCR_DSIZE_MASK                       (0x60000UL)
#define DMA_DCR_DSIZE_SHIFT                      (17UL)
/*! DSIZE - Destination Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DSIZE_SHIFT)) & DMA_DCR_DSIZE_MASK)

#define DMA_DCR_DINC_MASK                        (0x80000UL)
#define DMA_DCR_DINC_SHIFT                       (19UL)
/*! DINC - Destination Increment
 *  0b0..No change to the DAR after a successful transfer.
 *  0b1..The DAR increments by 1, 2, 4 depending upon the size of the transfer.
 */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DINC_SHIFT)) & DMA_DCR_DINC_MASK)

#define DMA_DCR_SSIZE_MASK                       (0x300000UL)
#define DMA_DCR_SSIZE_SHIFT                      (20UL)
/*! SSIZE - Source Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SSIZE_SHIFT)) & DMA_DCR_SSIZE_MASK)

#define DMA_DCR_SINC_MASK                        (0x400000UL)
#define DMA_DCR_SINC_SHIFT                       (22UL)
/*! SINC - Source Increment
 *  0b0..No change to SAR after a successful transfer.
 *  0b1..The SAR increments by 1, 2, 4 as determined by the transfer size.
 */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SINC_SHIFT)) & DMA_DCR_SINC_MASK)

#define DMA_DCR_AA_MASK                          (0x10000000UL)
#define DMA_DCR_AA_SHIFT                         (28UL)
/*! AA - Auto-align
 *  0b0..Auto-align disabled
 *  0b1..If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise,
 *       destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If
 *       auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.
 */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_AA_SHIFT)) & DMA_DCR_AA_MASK)

#define DMA_DCR_CS_MASK                          (0x20000000UL)
#define DMA_DCR_CS_SHIFT                         (29UL)
/*! CS - Cycle Steal
 *  0b0..DMA continuously makes read/write transfers until the BCR decrements to 0.
 *  0b1..Forces a single read/write transfer per request.
 */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_CS_SHIFT)) & DMA_DCR_CS_MASK)

#define DMA_DCR_ERQ_MASK                         (0x40000000UL)
#define DMA_DCR_ERQ_SHIFT                        (30UL)
/*! ERQ - Enable Peripheral Request
 *  0b0..Peripheral request is ignored.
 *  0b1..Enables peripheral request, defined by the appropriate REQC[DMACn] field, to initiate transfer. A
 *       software-initiated request (setting START) is always enabled.
 */
#define DMA_DCR_ERQ(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DCR_ERQ_SHIFT)) & DMA_DCR_ERQ_MASK)

#define DMA_DCR_EINT_MASK                        (0x80000000UL)
#define DMA_DCR_EINT_SHIFT                       (31UL)
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

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DMA_H_ */

