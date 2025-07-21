/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BCTU
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
 * @file PERI_BCTU.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for BCTU
 *
 * CMSIS Peripheral Access Layer for BCTU
 */

#if !defined(PERI_BCTU_H_)
#define PERI_BCTU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
#if !defined(BCTU_TRIG_SOURCE_T_)
#define BCTU_TRIG_SOURCE_T_
/*!
 * @brief BCTU hardware trigger source enumeration
 */
typedef enum _bctu_trig_source
{
    kBCTU_TrigSourceEmios0Ch0       = 0U,          /**< EMIOS0 Channel0 */
    kBCTU_TrigSourceEmios0Ch1       = 1U,          /**< EMIOS0 Channel1 */
    kBCTU_TrigSourceEmios0Ch2       = 2U,          /**< EMIOS0 Channel2 */
    kBCTU_TrigSourceEmios0Ch3       = 3U,          /**< EMIOS0 Channel3 */
    kBCTU_TrigSourceEmios0Ch4       = 4U,          /**< EMIOS0 Channel4 */
    kBCTU_TrigSourceEmios0Ch5       = 5U,          /**< EMIOS0 Channel5 */
    kBCTU_TrigSourceEmios0Ch6       = 6U,          /**< EMIOS0 Channel6 */
    kBCTU_TrigSourceEmios0Ch7       = 7U,          /**< EMIOS0 Channel7 */
    kBCTU_TrigSourceEmios0Ch8       = 8U,          /**< EMIOS0 Channel8 */
    kBCTU_TrigSourceEmios0Ch9       = 9U,          /**< EMIOS0 Channel9 */
    kBCTU_TrigSourceEmios0Ch10      = 10U,         /**< EMIOS0 Channel10 */
    kBCTU_TrigSourceEmios0Ch11      = 11U,         /**< EMIOS0 Channel11 */
    kBCTU_TrigSourceEmios0Ch12      = 12U,         /**< EMIOS0 Channel12 */
    kBCTU_TrigSourceEmios0Ch13      = 13U,         /**< EMIOS0 Channel13 */
    kBCTU_TrigSourceEmios0Ch14      = 14U,         /**< EMIOS0 Channel14 */
    kBCTU_TrigSourceEmios0Ch15      = 15U,         /**< EMIOS0 Channel15 */
    kBCTU_TrigSourceEmios0Ch16      = 16U,         /**< EMIOS0 Channel16 */
    kBCTU_TrigSourceEmios0Ch17      = 17U,         /**< EMIOS0 Channel17 */
    kBCTU_TrigSourceEmios0Ch18      = 18U,         /**< EMIOS0 Channel18 */
    kBCTU_TrigSourceEmios0Ch19      = 19U,         /**< EMIOS0 Channel19 */
    kBCTU_TrigSourceEmios0Ch20      = 20U,         /**< EMIOS0 Channel20 */
    kBCTU_TrigSourceEmios0Ch21      = 21U,         /**< EMIOS0 Channel21 */
    kBCTU_TrigSourceEmios0Ch22      = 22U,         /**< EMIOS0 Channel22 */
    kBCTU_TrigSourceTrgmuxTrg1      = 23U,         /**< TRGMUX Trigger1 */
    kBCTU_TrigSourceEmios1Ch0       = 24U,         /**< EMIOS1 Channel0 */
    kBCTU_TrigSourceEmios1Ch1       = 25U,         /**< EMIOS1 Channel1 */
    kBCTU_TrigSourceEmios1Ch2       = 26U,         /**< EMIOS1 Channel2 */
    kBCTU_TrigSourceEmios1Ch3       = 27U,         /**< EMIOS1 Channel3 */
    kBCTU_TrigSourceEmios1Ch4       = 28U,         /**< EMIOS1 Channel4 */
    kBCTU_TrigSourceEmios1Ch5       = 29U,         /**< EMIOS1 Channel5 */
    kBCTU_TrigSourceEmios1Ch6       = 30U,         /**< EMIOS1 Channel6 */
    kBCTU_TrigSourceEmios1Ch7       = 31U,         /**< EMIOS1 Channel7 */
    kBCTU_TrigSourceEmios1Ch8       = 32U,         /**< EMIOS1 Channel8 */
    kBCTU_TrigSourceEmios1Ch9       = 33U,         /**< EMIOS1 Channel9 */
    kBCTU_TrigSourceEmios1Ch10      = 34U,         /**< EMIOS1 Channel10 */
    kBCTU_TrigSourceEmios1Ch11      = 35U,         /**< EMIOS1 Channel11 */
    kBCTU_TrigSourceEmios1Ch12      = 36U,         /**< EMIOS1 Channel12 */
    kBCTU_TrigSourceEmios1Ch13      = 37U,         /**< EMIOS1 Channel13 */
    kBCTU_TrigSourceEmios1Ch14      = 38U,         /**< EMIOS1 Channel14 */
    kBCTU_TrigSourceEmios1Ch15      = 39U,         /**< EMIOS1 Channel15 */
    kBCTU_TrigSourceEmios1Ch16      = 40U,         /**< EMIOS1 Channel16 */
    kBCTU_TrigSourceEmios1Ch17      = 41U,         /**< EMIOS1 Channel17 */
    kBCTU_TrigSourceEmios1Ch18      = 42U,         /**< EMIOS1 Channel18 */
    kBCTU_TrigSourceEmios1Ch19      = 43U,         /**< EMIOS1 Channel19 */
    kBCTU_TrigSourceEmios1Ch20      = 44U,         /**< EMIOS1 Channel20 */
    kBCTU_TrigSourceEmios1Ch21      = 45U,         /**< EMIOS1 Channel21 */
    kBCTU_TrigSourceEmios1Ch22      = 46U,         /**< EMIOS1 Channel22 */
    kBCTU_TrigSourceTrgmuxTrg2      = 47U,         /**< TRGMUX Trigger2 */
} bctu_trig_source_t;
#endif /* BCTU_TRIG_SOURCE_T_ */


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
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- BCTU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BCTU_Peripheral_Access_Layer BCTU Peripheral Access Layer
 * @{
 */

/** BCTU - Size of Registers Arrays */
#define BCTU_TRGCFG_COUNT                         48u
#define BCTU_ADCDR_COUNT                          2u
#define BCTU_LISTCHR_COUNT                        16u

/** BCTU - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t MSR;                               /**< Module Status, offset: 0x8 */
       uint8_t RESERVED_1[12];
  __IO uint32_t TRGCFG[BCTU_TRGCFG_COUNT];         /**< Trigger Configuration, array offset: 0x18, array step: 0x4 */
       uint8_t RESERVED_2[336];
  __IO uint32_t WRPROT;                            /**< Write Protection, offset: 0x228 */
  __IO uint32_t SFTRGR1;                           /**< Software Trigger 1, offset: 0x22C */
  __IO uint32_t SFTRGR2;                           /**< Software Trigger 2, offset: 0x230 */
       uint8_t RESERVED_3[8];
  __I  uint32_t ADCDR[BCTU_ADCDR_COUNT];           /**< ADC0 Result Data..ADC1 Result Data, array offset: 0x23C, array step: 0x4 */
       uint8_t RESERVED_4[8];
  __I  uint32_t LISTSTAR;                          /**< CL Size Status, offset: 0x24C */
  __IO uint32_t LISTCHR[BCTU_LISTCHR_COUNT];       /**< CL Channel Address, array offset: 0x250, array step: 0x4 */
       uint8_t RESERVED_5[448];
  __I  uint32_t FIFO1DR;                           /**< FIFO Result Data, offset: 0x450 */
  __I  uint32_t FIFO2DR;                           /**< FIFO Result Data, offset: 0x454 */
       uint8_t RESERVED_6[8];
  __IO uint32_t FIFOCR;                            /**< FIFO Control, offset: 0x460 */
  __IO uint32_t FIFOWM;                            /**< FIFO Watermark Configuration, offset: 0x464 */
  __IO uint32_t FIFOERR;                           /**< FIFO Error/Status, offset: 0x468 */
  __I  uint32_t FIFOSR;                            /**< FIFO Status, offset: 0x46C */
  __I  uint32_t FIFOCNTR;                          /**< FIFO Counter, offset: 0x470 */
} BCTU_Type;

/* ----------------------------------------------------------------------------
   -- BCTU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BCTU_Register_Masks BCTU Register Masks
 * @{
 */

/*! @name MCR - Module Configuration */
/*! @{ */

#define BCTU_MCR_IEN0_MASK                       (0x1U)
#define BCTU_MCR_IEN0_SHIFT                      (0U)
/*! IEN0 - Interrupt Enable For ADC0DR
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_IEN0(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_IEN0_SHIFT)) & BCTU_MCR_IEN0_MASK)

#define BCTU_MCR_IEN1_MASK                       (0x2U)
#define BCTU_MCR_IEN1_SHIFT                      (1U)
/*! IEN1 - Interrupt Enable For ADC1DR
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_IEN1(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_IEN1_SHIFT)) & BCTU_MCR_IEN1_MASK)

#define BCTU_MCR_LIST_IEN_MASK                   (0x20U)
#define BCTU_MCR_LIST_IEN_SHIFT                  (5U)
/*! LIST_IEN - CL Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_LIST_IEN(x)                     (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_LIST_IEN_SHIFT)) & BCTU_MCR_LIST_IEN_MASK)

#define BCTU_MCR_TRGEN_MASK                      (0x80U)
#define BCTU_MCR_TRGEN_SHIFT                     (7U)
/*! TRGEN - Trigger Interrupt Request Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_TRGEN(x)                        (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_TRGEN_SHIFT)) & BCTU_MCR_TRGEN_MASK)

#define BCTU_MCR_DMA0_MASK                       (0x10000U)
#define BCTU_MCR_DMA0_SHIFT                      (16U)
/*! DMA0 - Enable ADC0DR DMA
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_DMA0(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_DMA0_SHIFT)) & BCTU_MCR_DMA0_MASK)

#define BCTU_MCR_DMA1_MASK                       (0x20000U)
#define BCTU_MCR_DMA1_SHIFT                      (17U)
/*! DMA1 - Enable ADC1DR DMA
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_DMA1(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_DMA1_SHIFT)) & BCTU_MCR_DMA1_MASK)

#define BCTU_MCR_GTRGEN_MASK                     (0x4000000U)
#define BCTU_MCR_GTRGEN_SHIFT                    (26U)
/*! GTRGEN - Global Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_MCR_GTRGEN(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_GTRGEN_SHIFT)) & BCTU_MCR_GTRGEN_MASK)

#define BCTU_MCR_FRZ_MASK                        (0x20000000U)
#define BCTU_MCR_FRZ_SHIFT                       (29U)
/*! FRZ - Debug Freeze
 *  0b0..Disables
 *  0b1..Enables
 */
#define BCTU_MCR_FRZ(x)                          (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_FRZ_SHIFT)) & BCTU_MCR_FRZ_MASK)

#define BCTU_MCR_MDIS_MASK                       (0x40000000U)
#define BCTU_MCR_MDIS_SHIFT                      (30U)
/*! MDIS - Module Disable
 *  0b0..Enable (normal operation)
 *  0b1..Disable (low-power operation)
 */
#define BCTU_MCR_MDIS(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_MDIS_SHIFT)) & BCTU_MCR_MDIS_MASK)

#define BCTU_MCR_Software_Reset_MASK             (0x80000000U)
#define BCTU_MCR_Software_Reset_SHIFT            (31U)
/*! Software_Reset - Software Reset
 *  0b0..Deasserts
 *  0b1..Asserts
 */
#define BCTU_MCR_Software_Reset(x)               (((uint32_t)(((uint32_t)(x)) << BCTU_MCR_Software_Reset_SHIFT)) & BCTU_MCR_Software_Reset_MASK)
/*! @} */

/*! @name MSR - Module Status */
/*! @{ */

#define BCTU_MSR_NDATA0_MASK                     (0x1U)
#define BCTU_MSR_NDATA0_SHIFT                    (0U)
/*! NDATA0 - New Data 0
 *  0b0..Not available
 *  0b1..Available
 */
#define BCTU_MSR_NDATA0(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_NDATA0_SHIFT)) & BCTU_MSR_NDATA0_MASK)

#define BCTU_MSR_NDATA1_MASK                     (0x2U)
#define BCTU_MSR_NDATA1_SHIFT                    (1U)
/*! NDATA1 - New Data 1
 *  0b0..Not available
 *  0b1..Available
 */
#define BCTU_MSR_NDATA1(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_NDATA1_SHIFT)) & BCTU_MSR_NDATA1_MASK)

#define BCTU_MSR_DATAOVR0_MASK                   (0x10U)
#define BCTU_MSR_DATAOVR0_SHIFT                  (4U)
/*! DATAOVR0 - Data Overrun 0
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define BCTU_MSR_DATAOVR0(x)                     (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_DATAOVR0_SHIFT)) & BCTU_MSR_DATAOVR0_MASK)

#define BCTU_MSR_DATAOVR1_MASK                   (0x20U)
#define BCTU_MSR_DATAOVR1_SHIFT                  (5U)
/*! DATAOVR1 - Data Overrun 1
 *  0b0..Data not overwritten
 *  0b1..Data overwritten
 */
#define BCTU_MSR_DATAOVR1(x)                     (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_DATAOVR1_SHIFT)) & BCTU_MSR_DATAOVR1_MASK)

#define BCTU_MSR_LIST0_Last_MASK                 (0x100U)
#define BCTU_MSR_LIST0_Last_SHIFT                (8U)
/*! LIST0_Last - CL 0 Last Conversion
 *  0b0..Last conversion not complete
 *  0b1..Last conversion complete
 */
#define BCTU_MSR_LIST0_Last(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_LIST0_Last_SHIFT)) & BCTU_MSR_LIST0_Last_MASK)

#define BCTU_MSR_LIST1_Last_MASK                 (0x200U)
#define BCTU_MSR_LIST1_Last_SHIFT                (9U)
/*! LIST1_Last - CL 1 Last Conversion
 *  0b0..Last conversion not complete
 *  0b1..Last conversion complete
 */
#define BCTU_MSR_LIST1_Last(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_LIST1_Last_SHIFT)) & BCTU_MSR_LIST1_Last_MASK)

#define BCTU_MSR_TRGF_MASK                       (0x8000U)
#define BCTU_MSR_TRGF_SHIFT                      (15U)
/*! TRGF - Trigger Flag
 *  0b0..No ADC triggered
 *  0b1..An ADC was triggered
 */
#define BCTU_MSR_TRGF(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_TRGF_SHIFT)) & BCTU_MSR_TRGF_MASK)

#define BCTU_MSR_NDATA0_CLR_MASK                 (0x10000U)
#define BCTU_MSR_NDATA0_CLR_SHIFT                (16U)
/*! NDATA0_CLR - New Data Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_NDATA0_CLR(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_NDATA0_CLR_SHIFT)) & BCTU_MSR_NDATA0_CLR_MASK)

#define BCTU_MSR_NDATA1_CLR_MASK                 (0x20000U)
#define BCTU_MSR_NDATA1_CLR_SHIFT                (17U)
/*! NDATA1_CLR - New Data Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_NDATA1_CLR(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_NDATA1_CLR_SHIFT)) & BCTU_MSR_NDATA1_CLR_MASK)

#define BCTU_MSR_DATAOVR0_CLR_MASK               (0x100000U)
#define BCTU_MSR_DATAOVR0_CLR_SHIFT              (20U)
/*! DATAOVR0_CLR - DATAOVR0 Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_DATAOVR0_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_DATAOVR0_CLR_SHIFT)) & BCTU_MSR_DATAOVR0_CLR_MASK)

#define BCTU_MSR_DATAOVR1_CLR_MASK               (0x200000U)
#define BCTU_MSR_DATAOVR1_CLR_SHIFT              (21U)
/*! DATAOVR1_CLR - DATAOVR1 Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_DATAOVR1_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_DATAOVR1_CLR_SHIFT)) & BCTU_MSR_DATAOVR1_CLR_MASK)

#define BCTU_MSR_LIST0_Last_CLR_MASK             (0x1000000U)
#define BCTU_MSR_LIST0_Last_CLR_SHIFT            (24U)
/*! LIST0_Last_CLR - CL 0 Last Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_LIST0_Last_CLR(x)               (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_LIST0_Last_CLR_SHIFT)) & BCTU_MSR_LIST0_Last_CLR_MASK)

#define BCTU_MSR_LIST1_Last_CLR_MASK             (0x2000000U)
#define BCTU_MSR_LIST1_Last_CLR_SHIFT            (25U)
/*! LIST1_Last_CLR - CL 1 Last Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_LIST1_Last_CLR(x)               (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_LIST1_Last_CLR_SHIFT)) & BCTU_MSR_LIST1_Last_CLR_MASK)

#define BCTU_MSR_TRGF_CLR_MASK                   (0x80000000U)
#define BCTU_MSR_TRGF_CLR_SHIFT                  (31U)
/*! TRGF_CLR - TRGF Clear
 *  0b0..No action
 *  0b1..Changes to 0
 */
#define BCTU_MSR_TRGF_CLR(x)                     (((uint32_t)(((uint32_t)(x)) << BCTU_MSR_TRGF_CLR_SHIFT)) & BCTU_MSR_TRGF_CLR_MASK)
/*! @} */

/*! @name TRGCFG - Trigger Configuration */
/*! @{ */

#define BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_MASK  (0x7FU)
#define BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_SHIFT (0U)
/*! CHANNEL_VALUE_OR_LADDR - Channel or CL Address */
#define BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR(x)    (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_SHIFT)) & BCTU_TRGCFG_CHANNEL_VALUE_OR_LADDR_MASK)

#define BCTU_TRGCFG_ADC_SEL0_MASK                (0x100U)
#define BCTU_TRGCFG_ADC_SEL0_SHIFT               (8U)
/*! ADC_SEL0 - ADC Select 0
 *  0b0..Deselects
 *  0b1..Selects
 */
#define BCTU_TRGCFG_ADC_SEL0(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_ADC_SEL0_SHIFT)) & BCTU_TRGCFG_ADC_SEL0_MASK)

#define BCTU_TRGCFG_ADC_SEL1_MASK                (0x200U)
#define BCTU_TRGCFG_ADC_SEL1_SHIFT               (9U)
/*! ADC_SEL1 - ADC Select 1
 *  0b0..Deselects
 *  0b1..Selects
 */
#define BCTU_TRGCFG_ADC_SEL1(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_ADC_SEL1_SHIFT)) & BCTU_TRGCFG_ADC_SEL1_MASK)

#define BCTU_TRGCFG_TRS_MASK                     (0x2000U)
#define BCTU_TRGCFG_TRS_SHIFT                    (13U)
/*! TRS - Trigger Resolution
 *  0b0..Single conversion
 *  0b1..CL conversions
 */
#define BCTU_TRGCFG_TRS(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_TRS_SHIFT)) & BCTU_TRGCFG_TRS_MASK)

#define BCTU_TRGCFG_TRG_FLAG_MASK                (0x4000U)
#define BCTU_TRGCFG_TRG_FLAG_SHIFT               (14U)
/*! TRG_FLAG - Trigger Flag
 *  0b0..No action
 *  0b0..No ongoing ADC conversion initiated
 *  0b1..Changes to 0
 *  0b1..Ongoing ADC conversion initiated
 */
#define BCTU_TRGCFG_TRG_FLAG(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_TRG_FLAG_SHIFT)) & BCTU_TRGCFG_TRG_FLAG_MASK)

#define BCTU_TRGCFG_TRIGEN_MASK                  (0x8000U)
#define BCTU_TRGCFG_TRIGEN_SHIFT                 (15U)
/*! TRIGEN - Trigger Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_TRGCFG_TRIGEN(x)                    (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_TRIGEN_SHIFT)) & BCTU_TRGCFG_TRIGEN_MASK)

#define BCTU_TRGCFG_DATA_DEST_MASK               (0x70000000U)
#define BCTU_TRGCFG_DATA_DEST_SHIFT              (28U)
/*! DATA_DEST - Data Destination
 *  0b000..ADC-specific data registers
 *  0b001..FIFO1
 *  0b010..FIFO2
 *  0b011..
 */
#define BCTU_TRGCFG_DATA_DEST(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_DATA_DEST_SHIFT)) & BCTU_TRGCFG_DATA_DEST_MASK)

#define BCTU_TRGCFG_LOOP_MASK                    (0x80000000U)
#define BCTU_TRGCFG_LOOP_SHIFT                   (31U)
/*! LOOP - Loop
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_TRGCFG_LOOP(x)                      (((uint32_t)(((uint32_t)(x)) << BCTU_TRGCFG_LOOP_SHIFT)) & BCTU_TRGCFG_LOOP_MASK)
/*! @} */

/*! @name WRPROT - Write Protection */
/*! @{ */

#define BCTU_WRPROT_PROTEC_CODE_MASK             (0xFU)
#define BCTU_WRPROT_PROTEC_CODE_SHIFT            (0U)
/*! PROTEC_CODE - Protection Code
 *  0b0000..Enable protection
 *  0b1001..Disable protection for one write cycle
 *  0b1010..Disable protection permanently
 */
#define BCTU_WRPROT_PROTEC_CODE(x)               (((uint32_t)(((uint32_t)(x)) << BCTU_WRPROT_PROTEC_CODE_SHIFT)) & BCTU_WRPROT_PROTEC_CODE_MASK)
/*! @} */

/*! @name SFTRGR1 - Software Trigger 1 */
/*! @{ */

#define BCTU_SFTRGR1_SFTRG0_MASK                 (0x1U)
#define BCTU_SFTRGR1_SFTRG0_SHIFT                (0U)
/*! SFTRG0 - Software Trigger 0
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG0(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG0_SHIFT)) & BCTU_SFTRGR1_SFTRG0_MASK)

#define BCTU_SFTRGR1_SFTRG1_MASK                 (0x2U)
#define BCTU_SFTRGR1_SFTRG1_SHIFT                (1U)
/*! SFTRG1 - Software Trigger 1
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG1(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG1_SHIFT)) & BCTU_SFTRGR1_SFTRG1_MASK)

#define BCTU_SFTRGR1_SFTRG2_MASK                 (0x4U)
#define BCTU_SFTRGR1_SFTRG2_SHIFT                (2U)
/*! SFTRG2 - Software Trigger 2
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG2(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG2_SHIFT)) & BCTU_SFTRGR1_SFTRG2_MASK)

#define BCTU_SFTRGR1_SFTRG3_MASK                 (0x8U)
#define BCTU_SFTRGR1_SFTRG3_SHIFT                (3U)
/*! SFTRG3 - Software Trigger 3
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG3(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG3_SHIFT)) & BCTU_SFTRGR1_SFTRG3_MASK)

#define BCTU_SFTRGR1_SFTRG4_MASK                 (0x10U)
#define BCTU_SFTRGR1_SFTRG4_SHIFT                (4U)
/*! SFTRG4 - Software Trigger 4
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG4(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG4_SHIFT)) & BCTU_SFTRGR1_SFTRG4_MASK)

#define BCTU_SFTRGR1_SFTRG5_MASK                 (0x20U)
#define BCTU_SFTRGR1_SFTRG5_SHIFT                (5U)
/*! SFTRG5 - Software Trigger 5
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG5(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG5_SHIFT)) & BCTU_SFTRGR1_SFTRG5_MASK)

#define BCTU_SFTRGR1_SFTRG6_MASK                 (0x40U)
#define BCTU_SFTRGR1_SFTRG6_SHIFT                (6U)
/*! SFTRG6 - Software Trigger 6
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG6(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG6_SHIFT)) & BCTU_SFTRGR1_SFTRG6_MASK)

#define BCTU_SFTRGR1_SFTRG7_MASK                 (0x80U)
#define BCTU_SFTRGR1_SFTRG7_SHIFT                (7U)
/*! SFTRG7 - Software Trigger 7
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG7(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG7_SHIFT)) & BCTU_SFTRGR1_SFTRG7_MASK)

#define BCTU_SFTRGR1_SFTRG8_MASK                 (0x100U)
#define BCTU_SFTRGR1_SFTRG8_SHIFT                (8U)
/*! SFTRG8 - Software Trigger 8
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG8(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG8_SHIFT)) & BCTU_SFTRGR1_SFTRG8_MASK)

#define BCTU_SFTRGR1_SFTRG9_MASK                 (0x200U)
#define BCTU_SFTRGR1_SFTRG9_SHIFT                (9U)
/*! SFTRG9 - Software Trigger 9
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG9(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG9_SHIFT)) & BCTU_SFTRGR1_SFTRG9_MASK)

#define BCTU_SFTRGR1_SFTRG10_MASK                (0x400U)
#define BCTU_SFTRGR1_SFTRG10_SHIFT               (10U)
/*! SFTRG10 - Software Trigger 10
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG10(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG10_SHIFT)) & BCTU_SFTRGR1_SFTRG10_MASK)

#define BCTU_SFTRGR1_SFTRG11_MASK                (0x800U)
#define BCTU_SFTRGR1_SFTRG11_SHIFT               (11U)
/*! SFTRG11 - Software Trigger 11
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG11(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG11_SHIFT)) & BCTU_SFTRGR1_SFTRG11_MASK)

#define BCTU_SFTRGR1_SFTRG12_MASK                (0x1000U)
#define BCTU_SFTRGR1_SFTRG12_SHIFT               (12U)
/*! SFTRG12 - Software Trigger 12
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG12(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG12_SHIFT)) & BCTU_SFTRGR1_SFTRG12_MASK)

#define BCTU_SFTRGR1_SFTRG13_MASK                (0x2000U)
#define BCTU_SFTRGR1_SFTRG13_SHIFT               (13U)
/*! SFTRG13 - Software Trigger 13
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG13(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG13_SHIFT)) & BCTU_SFTRGR1_SFTRG13_MASK)

#define BCTU_SFTRGR1_SFTRG14_MASK                (0x4000U)
#define BCTU_SFTRGR1_SFTRG14_SHIFT               (14U)
/*! SFTRG14 - Software Trigger 14
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG14(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG14_SHIFT)) & BCTU_SFTRGR1_SFTRG14_MASK)

#define BCTU_SFTRGR1_SFTRG15_MASK                (0x8000U)
#define BCTU_SFTRGR1_SFTRG15_SHIFT               (15U)
/*! SFTRG15 - Software Trigger 15
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG15(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG15_SHIFT)) & BCTU_SFTRGR1_SFTRG15_MASK)

#define BCTU_SFTRGR1_SFTRG16_MASK                (0x10000U)
#define BCTU_SFTRGR1_SFTRG16_SHIFT               (16U)
/*! SFTRG16 - Software Trigger 16
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG16(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG16_SHIFT)) & BCTU_SFTRGR1_SFTRG16_MASK)

#define BCTU_SFTRGR1_SFTRG17_MASK                (0x20000U)
#define BCTU_SFTRGR1_SFTRG17_SHIFT               (17U)
/*! SFTRG17 - Software Trigger 17
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG17(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG17_SHIFT)) & BCTU_SFTRGR1_SFTRG17_MASK)

#define BCTU_SFTRGR1_SFTRG18_MASK                (0x40000U)
#define BCTU_SFTRGR1_SFTRG18_SHIFT               (18U)
/*! SFTRG18 - Software Trigger 18
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG18(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG18_SHIFT)) & BCTU_SFTRGR1_SFTRG18_MASK)

#define BCTU_SFTRGR1_SFTRG19_MASK                (0x80000U)
#define BCTU_SFTRGR1_SFTRG19_SHIFT               (19U)
/*! SFTRG19 - Software Trigger 19
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG19(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG19_SHIFT)) & BCTU_SFTRGR1_SFTRG19_MASK)

#define BCTU_SFTRGR1_SFTRG20_MASK                (0x100000U)
#define BCTU_SFTRGR1_SFTRG20_SHIFT               (20U)
/*! SFTRG20 - Software Trigger 20
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG20(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG20_SHIFT)) & BCTU_SFTRGR1_SFTRG20_MASK)

#define BCTU_SFTRGR1_SFTRG21_MASK                (0x200000U)
#define BCTU_SFTRGR1_SFTRG21_SHIFT               (21U)
/*! SFTRG21 - Software Trigger 21
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG21(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG21_SHIFT)) & BCTU_SFTRGR1_SFTRG21_MASK)

#define BCTU_SFTRGR1_SFTRG22_MASK                (0x400000U)
#define BCTU_SFTRGR1_SFTRG22_SHIFT               (22U)
/*! SFTRG22 - Software Trigger 22
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG22(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG22_SHIFT)) & BCTU_SFTRGR1_SFTRG22_MASK)

#define BCTU_SFTRGR1_SFTRG23_MASK                (0x800000U)
#define BCTU_SFTRGR1_SFTRG23_SHIFT               (23U)
/*! SFTRG23 - Software Trigger 23
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG23(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG23_SHIFT)) & BCTU_SFTRGR1_SFTRG23_MASK)

#define BCTU_SFTRGR1_SFTRG24_MASK                (0x1000000U)
#define BCTU_SFTRGR1_SFTRG24_SHIFT               (24U)
/*! SFTRG24 - Software Trigger 24
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG24(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG24_SHIFT)) & BCTU_SFTRGR1_SFTRG24_MASK)

#define BCTU_SFTRGR1_SFTRG25_MASK                (0x2000000U)
#define BCTU_SFTRGR1_SFTRG25_SHIFT               (25U)
/*! SFTRG25 - Software Trigger 25
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG25(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG25_SHIFT)) & BCTU_SFTRGR1_SFTRG25_MASK)

#define BCTU_SFTRGR1_SFTRG26_MASK                (0x4000000U)
#define BCTU_SFTRGR1_SFTRG26_SHIFT               (26U)
/*! SFTRG26 - Software Trigger 26
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG26(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG26_SHIFT)) & BCTU_SFTRGR1_SFTRG26_MASK)

#define BCTU_SFTRGR1_SFTRG27_MASK                (0x8000000U)
#define BCTU_SFTRGR1_SFTRG27_SHIFT               (27U)
/*! SFTRG27 - Software Trigger 27
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG27(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG27_SHIFT)) & BCTU_SFTRGR1_SFTRG27_MASK)

#define BCTU_SFTRGR1_SFTRG28_MASK                (0x10000000U)
#define BCTU_SFTRGR1_SFTRG28_SHIFT               (28U)
/*! SFTRG28 - Software Trigger 28
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG28(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG28_SHIFT)) & BCTU_SFTRGR1_SFTRG28_MASK)

#define BCTU_SFTRGR1_SFTRG29_MASK                (0x20000000U)
#define BCTU_SFTRGR1_SFTRG29_SHIFT               (29U)
/*! SFTRG29 - Software Trigger 29
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG29(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG29_SHIFT)) & BCTU_SFTRGR1_SFTRG29_MASK)

#define BCTU_SFTRGR1_SFTRG30_MASK                (0x40000000U)
#define BCTU_SFTRGR1_SFTRG30_SHIFT               (30U)
/*! SFTRG30 - Software Trigger 30
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG30(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG30_SHIFT)) & BCTU_SFTRGR1_SFTRG30_MASK)

#define BCTU_SFTRGR1_SFTRG31_MASK                (0x80000000U)
#define BCTU_SFTRGR1_SFTRG31_SHIFT               (31U)
/*! SFTRG31 - Software Trigger 31
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR1_SFTRG31(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR1_SFTRG31_SHIFT)) & BCTU_SFTRGR1_SFTRG31_MASK)
/*! @} */

/*! @name SFTRGR2 - Software Trigger 2 */
/*! @{ */

#define BCTU_SFTRGR2_SFTRG32_MASK                (0x1U)
#define BCTU_SFTRGR2_SFTRG32_SHIFT               (0U)
/*! SFTRG32 - Software Trigger 32
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG32(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG32_SHIFT)) & BCTU_SFTRGR2_SFTRG32_MASK)

#define BCTU_SFTRGR2_SFTRG33_MASK                (0x2U)
#define BCTU_SFTRGR2_SFTRG33_SHIFT               (1U)
/*! SFTRG33 - Software Trigger 33
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG33(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG33_SHIFT)) & BCTU_SFTRGR2_SFTRG33_MASK)

#define BCTU_SFTRGR2_SFTRG34_MASK                (0x4U)
#define BCTU_SFTRGR2_SFTRG34_SHIFT               (2U)
/*! SFTRG34 - Software Trigger 34
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG34(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG34_SHIFT)) & BCTU_SFTRGR2_SFTRG34_MASK)

#define BCTU_SFTRGR2_SFTRG35_MASK                (0x8U)
#define BCTU_SFTRGR2_SFTRG35_SHIFT               (3U)
/*! SFTRG35 - Software Trigger 35
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG35(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG35_SHIFT)) & BCTU_SFTRGR2_SFTRG35_MASK)

#define BCTU_SFTRGR2_SFTRG36_MASK                (0x10U)
#define BCTU_SFTRGR2_SFTRG36_SHIFT               (4U)
/*! SFTRG36 - Software Trigger 36
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG36(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG36_SHIFT)) & BCTU_SFTRGR2_SFTRG36_MASK)

#define BCTU_SFTRGR2_SFTRG37_MASK                (0x20U)
#define BCTU_SFTRGR2_SFTRG37_SHIFT               (5U)
/*! SFTRG37 - Software Trigger 37
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG37(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG37_SHIFT)) & BCTU_SFTRGR2_SFTRG37_MASK)

#define BCTU_SFTRGR2_SFTRG38_MASK                (0x40U)
#define BCTU_SFTRGR2_SFTRG38_SHIFT               (6U)
/*! SFTRG38 - Software Trigger 38
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG38(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG38_SHIFT)) & BCTU_SFTRGR2_SFTRG38_MASK)

#define BCTU_SFTRGR2_SFTRG39_MASK                (0x80U)
#define BCTU_SFTRGR2_SFTRG39_SHIFT               (7U)
/*! SFTRG39 - Software Trigger 39
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG39(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG39_SHIFT)) & BCTU_SFTRGR2_SFTRG39_MASK)

#define BCTU_SFTRGR2_SFTRG40_MASK                (0x100U)
#define BCTU_SFTRGR2_SFTRG40_SHIFT               (8U)
/*! SFTRG40 - Software Trigger 40
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG40(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG40_SHIFT)) & BCTU_SFTRGR2_SFTRG40_MASK)

#define BCTU_SFTRGR2_SFTRG41_MASK                (0x200U)
#define BCTU_SFTRGR2_SFTRG41_SHIFT               (9U)
/*! SFTRG41 - Software Trigger 41
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG41(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG41_SHIFT)) & BCTU_SFTRGR2_SFTRG41_MASK)

#define BCTU_SFTRGR2_SFTRG42_MASK                (0x400U)
#define BCTU_SFTRGR2_SFTRG42_SHIFT               (10U)
/*! SFTRG42 - Software Trigger 42
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG42(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG42_SHIFT)) & BCTU_SFTRGR2_SFTRG42_MASK)

#define BCTU_SFTRGR2_SFTRG43_MASK                (0x800U)
#define BCTU_SFTRGR2_SFTRG43_SHIFT               (11U)
/*! SFTRG43 - Software Trigger 43
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG43(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG43_SHIFT)) & BCTU_SFTRGR2_SFTRG43_MASK)

#define BCTU_SFTRGR2_SFTRG44_MASK                (0x1000U)
#define BCTU_SFTRGR2_SFTRG44_SHIFT               (12U)
/*! SFTRG44 - Software Trigger 44
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG44(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG44_SHIFT)) & BCTU_SFTRGR2_SFTRG44_MASK)

#define BCTU_SFTRGR2_SFTRG45_MASK                (0x2000U)
#define BCTU_SFTRGR2_SFTRG45_SHIFT               (13U)
/*! SFTRG45 - Software Trigger 45
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG45(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG45_SHIFT)) & BCTU_SFTRGR2_SFTRG45_MASK)

#define BCTU_SFTRGR2_SFTRG46_MASK                (0x4000U)
#define BCTU_SFTRGR2_SFTRG46_SHIFT               (14U)
/*! SFTRG46 - Software Trigger 46
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG46(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG46_SHIFT)) & BCTU_SFTRGR2_SFTRG46_MASK)

#define BCTU_SFTRGR2_SFTRG47_MASK                (0x8000U)
#define BCTU_SFTRGR2_SFTRG47_SHIFT               (15U)
/*! SFTRG47 - Software Trigger 47
 *  0b0..No effect
 *  0b1..Trigger conversion
 */
#define BCTU_SFTRGR2_SFTRG47(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_SFTRGR2_SFTRG47_SHIFT)) & BCTU_SFTRGR2_SFTRG47_MASK)
/*! @} */

/*! @name ADCDR - ADC0 Result Data..ADC1 Result Data */
/*! @{ */

#define BCTU_ADCDR_ADC_DATA_MASK                 (0x7FFFU)
#define BCTU_ADCDR_ADC_DATA_SHIFT                (0U)
/*! ADC_DATA - ADC Data */
#define BCTU_ADCDR_ADC_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_ADCDR_ADC_DATA_SHIFT)) & BCTU_ADCDR_ADC_DATA_MASK)

#define BCTU_ADCDR_LAST_MASK                     (0x10000U)
#define BCTU_ADCDR_LAST_SHIFT                    (16U)
/*! LAST - Last
 *  0b0..Not the last conversion of a CL, or not a CL conversion
 *  0b1..Last conversion of a CL
 */
#define BCTU_ADCDR_LAST(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_ADCDR_LAST_SHIFT)) & BCTU_ADCDR_LAST_MASK)

#define BCTU_ADCDR_LIST_MASK                     (0x20000U)
#define BCTU_ADCDR_LIST_SHIFT                    (17U)
/*! LIST - List
 *  0b0..Single conversion
 *  0b1..CL
 */
#define BCTU_ADCDR_LIST(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_ADCDR_LIST_SHIFT)) & BCTU_ADCDR_LIST_MASK)

#define BCTU_ADCDR_CH_MASK                       (0x1FC0000U)
#define BCTU_ADCDR_CH_SHIFT                      (18U)
/*! CH - Channel */
#define BCTU_ADCDR_CH(x)                         (((uint32_t)(((uint32_t)(x)) << BCTU_ADCDR_CH_SHIFT)) & BCTU_ADCDR_CH_MASK)

#define BCTU_ADCDR_TRG_SRC_MASK                  (0xFE000000U)
#define BCTU_ADCDR_TRG_SRC_SHIFT                 (25U)
/*! TRG_SRC - Trigger Source */
#define BCTU_ADCDR_TRG_SRC(x)                    (((uint32_t)(((uint32_t)(x)) << BCTU_ADCDR_TRG_SRC_SHIFT)) & BCTU_ADCDR_TRG_SRC_MASK)
/*! @} */

/*! @name LISTSTAR - CL Size Status */
/*! @{ */

#define BCTU_LISTSTAR_LISTSZ_MASK                (0xFFU)
#define BCTU_LISTSTAR_LISTSZ_SHIFT               (0U)
/*! LISTSZ - CL Size */
#define BCTU_LISTSTAR_LISTSZ(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_LISTSTAR_LISTSZ_SHIFT)) & BCTU_LISTSTAR_LISTSZ_MASK)
/*! @} */

/*! @name LISTCHR - CL Channel Address */
/*! @{ */

#define BCTU_LISTCHR_ADC_CHL_y_plus_1_MASK       (0x7FU)
#define BCTU_LISTCHR_ADC_CHL_y_plus_1_SHIFT      (0U)
/*! ADC_CHL_y_plus_1 - ADC Channel Selection Plus 1 */
#define BCTU_LISTCHR_ADC_CHL_y_plus_1(x)         (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_ADC_CHL_y_plus_1_SHIFT)) & BCTU_LISTCHR_ADC_CHL_y_plus_1_MASK)

#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_MASK (0x4000U)
#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_SHIFT (14U)
/*! NEXT_CH_WAIT_ON_TRIG_y_plus_1 - Next Channel Wait For Trigger Plus 1
 *  0b0..CL executes continuously
 *  0b1..CL stops executing
 */
#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1(x) (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_SHIFT)) & BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_plus_1_MASK)

#define BCTU_LISTCHR_LAST_y_plus_1_MASK          (0x8000U)
#define BCTU_LISTCHR_LAST_y_plus_1_SHIFT         (15U)
/*! LAST_y_plus_1 - Last Channel Plus 1
 *  0b0..Not next-to-last
 *  0b1..Next-to-last channel in CL
 */
#define BCTU_LISTCHR_LAST_y_plus_1(x)            (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_LAST_y_plus_1_SHIFT)) & BCTU_LISTCHR_LAST_y_plus_1_MASK)

#define BCTU_LISTCHR_ADC_CH_y_MASK               (0x7F0000U)
#define BCTU_LISTCHR_ADC_CH_y_SHIFT              (16U)
/*! ADC_CH_y - ADC Channel Selection */
#define BCTU_LISTCHR_ADC_CH_y(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_ADC_CH_y_SHIFT)) & BCTU_LISTCHR_ADC_CH_y_MASK)

#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_MASK (0x40000000U)
#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_SHIFT (30U)
/*! NEXT_CH_WAIT_ON_TRIG_y - Next Channel Wait For Trigger
 *  0b0..CL executes continuously
 *  0b1..CL stops executing
 */
#define BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y(x)   (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_SHIFT)) & BCTU_LISTCHR_NEXT_CH_WAIT_ON_TRIG_y_MASK)

#define BCTU_LISTCHR_LAST_y_MASK                 (0x80000000U)
#define BCTU_LISTCHR_LAST_y_SHIFT                (31U)
/*! LAST_y - Last Channel
 *  0b0..Not last
 *  0b1..Last channel in CL
 */
#define BCTU_LISTCHR_LAST_y(x)                   (((uint32_t)(((uint32_t)(x)) << BCTU_LISTCHR_LAST_y_SHIFT)) & BCTU_LISTCHR_LAST_y_MASK)
/*! @} */

/*! @name FIFO1DR - FIFO Result Data */
/*! @{ */

#define BCTU_FIFO1DR_ADC_DATA_MASK               (0x7FFFU)
#define BCTU_FIFO1DR_ADC_DATA_SHIFT              (0U)
/*! ADC_DATA - ADC Data */
#define BCTU_FIFO1DR_ADC_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO1DR_ADC_DATA_SHIFT)) & BCTU_FIFO1DR_ADC_DATA_MASK)

#define BCTU_FIFO1DR_ADC_NUM_MASK                (0x30000U)
#define BCTU_FIFO1DR_ADC_NUM_SHIFT               (16U)
/*! ADC_NUM - ADC Number
 *  0b00..ADC 0
 *  0b01..ADC 1
 *  0b10..ADC 2
 *  0b11..ADC 3
 */
#define BCTU_FIFO1DR_ADC_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO1DR_ADC_NUM_SHIFT)) & BCTU_FIFO1DR_ADC_NUM_MASK)

#define BCTU_FIFO1DR_CH_MASK                     (0x1FC0000U)
#define BCTU_FIFO1DR_CH_SHIFT                    (18U)
/*! CH - Channel */
#define BCTU_FIFO1DR_CH(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO1DR_CH_SHIFT)) & BCTU_FIFO1DR_CH_MASK)

#define BCTU_FIFO1DR_TRG_SRC_MASK                (0xFE000000U)
#define BCTU_FIFO1DR_TRG_SRC_SHIFT               (25U)
/*! TRG_SRC - Trigger Source */
#define BCTU_FIFO1DR_TRG_SRC(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO1DR_TRG_SRC_SHIFT)) & BCTU_FIFO1DR_TRG_SRC_MASK)
/*! @} */

/*! @name FIFO2DR - FIFO Result Data */
/*! @{ */

#define BCTU_FIFO2DR_ADC_DATA_MASK               (0x7FFFU)
#define BCTU_FIFO2DR_ADC_DATA_SHIFT              (0U)
/*! ADC_DATA - ADC Data */
#define BCTU_FIFO2DR_ADC_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO2DR_ADC_DATA_SHIFT)) & BCTU_FIFO2DR_ADC_DATA_MASK)

#define BCTU_FIFO2DR_ADC_NUM_MASK                (0x30000U)
#define BCTU_FIFO2DR_ADC_NUM_SHIFT               (16U)
/*! ADC_NUM - ADC Number
 *  0b00..ADC 0
 *  0b01..ADC 1
 *  0b10..ADC 2
 *  0b11..ADC 3
 */
#define BCTU_FIFO2DR_ADC_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO2DR_ADC_NUM_SHIFT)) & BCTU_FIFO2DR_ADC_NUM_MASK)

#define BCTU_FIFO2DR_CH_MASK                     (0x1FC0000U)
#define BCTU_FIFO2DR_CH_SHIFT                    (18U)
/*! CH - Channel */
#define BCTU_FIFO2DR_CH(x)                       (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO2DR_CH_SHIFT)) & BCTU_FIFO2DR_CH_MASK)

#define BCTU_FIFO2DR_TRG_SRC_MASK                (0xFE000000U)
#define BCTU_FIFO2DR_TRG_SRC_SHIFT               (25U)
/*! TRG_SRC - Trigger Source */
#define BCTU_FIFO2DR_TRG_SRC(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFO2DR_TRG_SRC_SHIFT)) & BCTU_FIFO2DR_TRG_SRC_MASK)
/*! @} */

/*! @name FIFOCR - FIFO Control */
/*! @{ */

#define BCTU_FIFOCR_IEN_FIFO1_MASK               (0x10000U)
#define BCTU_FIFOCR_IEN_FIFO1_SHIFT              (16U)
/*! IEN_FIFO1 - FIFO1 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_FIFOCR_IEN_FIFO1(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCR_IEN_FIFO1_SHIFT)) & BCTU_FIFOCR_IEN_FIFO1_MASK)

#define BCTU_FIFOCR_IEN_FIFO2_MASK               (0x20000U)
#define BCTU_FIFOCR_IEN_FIFO2_SHIFT              (17U)
/*! IEN_FIFO2 - FIFO2 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_FIFOCR_IEN_FIFO2(x)                 (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCR_IEN_FIFO2_SHIFT)) & BCTU_FIFOCR_IEN_FIFO2_MASK)

#define BCTU_FIFOCR_DMA_EN_FIFO1_MASK            (0x1000000U)
#define BCTU_FIFOCR_DMA_EN_FIFO1_SHIFT           (24U)
/*! DMA_EN_FIFO1 - FIFO1 DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_FIFOCR_DMA_EN_FIFO1(x)              (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCR_DMA_EN_FIFO1_SHIFT)) & BCTU_FIFOCR_DMA_EN_FIFO1_MASK)

#define BCTU_FIFOCR_DMA_EN_FIFO2_MASK            (0x2000000U)
#define BCTU_FIFOCR_DMA_EN_FIFO2_SHIFT           (25U)
/*! DMA_EN_FIFO2 - FIFO2 DMA Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BCTU_FIFOCR_DMA_EN_FIFO2(x)              (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCR_DMA_EN_FIFO2_SHIFT)) & BCTU_FIFOCR_DMA_EN_FIFO2_MASK)
/*! @} */

/*! @name FIFOWM - FIFO Watermark Configuration */
/*! @{ */

#define BCTU_FIFOWM_WM_FIFO1_MASK                (0xFU)
#define BCTU_FIFOWM_WM_FIFO1_SHIFT               (0U)
/*! WM_FIFO1 - FIFO1 Watermark Level */
#define BCTU_FIFOWM_WM_FIFO1(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOWM_WM_FIFO1_SHIFT)) & BCTU_FIFOWM_WM_FIFO1_MASK)

#define BCTU_FIFOWM_WM_FIFO2_MASK                (0x700U)
#define BCTU_FIFOWM_WM_FIFO2_SHIFT               (8U)
/*! WM_FIFO2 - FIFO2 Watermark Level */
#define BCTU_FIFOWM_WM_FIFO2(x)                  (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOWM_WM_FIFO2_SHIFT)) & BCTU_FIFOWM_WM_FIFO2_MASK)
/*! @} */

/*! @name FIFOERR - FIFO Error/Status */
/*! @{ */

#define BCTU_FIFOERR_WM_INT_FIFO1_MASK           (0x10000U)
#define BCTU_FIFOERR_WM_INT_FIFO1_SHIFT          (16U)
/*! WM_INT_FIFO1 - FIFO Watermark Interrupt Status
 *  0b0..Does not exceed watermark
 *  0b1..Exceeds watermark
 */
#define BCTU_FIFOERR_WM_INT_FIFO1(x)             (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_WM_INT_FIFO1_SHIFT)) & BCTU_FIFOERR_WM_INT_FIFO1_MASK)

#define BCTU_FIFOERR_WM_INT_FIFO2_MASK           (0x20000U)
#define BCTU_FIFOERR_WM_INT_FIFO2_SHIFT          (17U)
/*! WM_INT_FIFO2 - FIFO Watermark Interrupt Status
 *  0b0..Does not exceed watermark
 *  0b1..Exceeds watermark
 */
#define BCTU_FIFOERR_WM_INT_FIFO2(x)             (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_WM_INT_FIFO2_SHIFT)) & BCTU_FIFOERR_WM_INT_FIFO2_MASK)

#define BCTU_FIFOERR_OVR_ERR_FIFO1_MASK          (0x1000000U)
#define BCTU_FIFOERR_OVR_ERR_FIFO1_SHIFT         (24U)
/*! OVR_ERR_FIFO1 - Overrun Error Flag
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define BCTU_FIFOERR_OVR_ERR_FIFO1(x)            (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_OVR_ERR_FIFO1_SHIFT)) & BCTU_FIFOERR_OVR_ERR_FIFO1_MASK)

#define BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK         (0x2000000U)
#define BCTU_FIFOERR_UNDR_ERR_FIFO1_SHIFT        (25U)
/*! UNDR_ERR_FIFO1 - Underrun Error Flag
 *  0b0..No underrun
 *  0b1..Underrun
 */
#define BCTU_FIFOERR_UNDR_ERR_FIFO1(x)           (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_UNDR_ERR_FIFO1_SHIFT)) & BCTU_FIFOERR_UNDR_ERR_FIFO1_MASK)

#define BCTU_FIFOERR_OVR_ERR_FIFO2_MASK          (0x4000000U)
#define BCTU_FIFOERR_OVR_ERR_FIFO2_SHIFT         (26U)
/*! OVR_ERR_FIFO2 - Overrun Error Flag
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define BCTU_FIFOERR_OVR_ERR_FIFO2(x)            (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_OVR_ERR_FIFO2_SHIFT)) & BCTU_FIFOERR_OVR_ERR_FIFO2_MASK)

#define BCTU_FIFOERR_UNDR_ERR_FIFO2_MASK         (0x8000000U)
#define BCTU_FIFOERR_UNDR_ERR_FIFO2_SHIFT        (27U)
/*! UNDR_ERR_FIFO2 - Underrun Error Flag
 *  0b0..No underrun
 *  0b1..Underrun
 */
#define BCTU_FIFOERR_UNDR_ERR_FIFO2(x)           (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOERR_UNDR_ERR_FIFO2_SHIFT)) & BCTU_FIFOERR_UNDR_ERR_FIFO2_MASK)
/*! @} */

/*! @name FIFOSR - FIFO Status */
/*! @{ */

#define BCTU_FIFOSR_FULL_FIFO1_MASK              (0x1U)
#define BCTU_FIFOSR_FULL_FIFO1_SHIFT             (0U)
/*! FULL_FIFO1 - FIFO Full
 *  0b0..Not full
 *  0b1..Full
 */
#define BCTU_FIFOSR_FULL_FIFO1(x)                (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOSR_FULL_FIFO1_SHIFT)) & BCTU_FIFOSR_FULL_FIFO1_MASK)

#define BCTU_FIFOSR_FULL_FIFO2_MASK              (0x2U)
#define BCTU_FIFOSR_FULL_FIFO2_SHIFT             (1U)
/*! FULL_FIFO2 - FIFO Full
 *  0b0..Not full
 *  0b1..Full
 */
#define BCTU_FIFOSR_FULL_FIFO2(x)                (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOSR_FULL_FIFO2_SHIFT)) & BCTU_FIFOSR_FULL_FIFO2_MASK)
/*! @} */

/*! @name FIFOCNTR - FIFO Counter */
/*! @{ */

#define BCTU_FIFOCNTR_CNTR_FIFO1_MASK            (0x1FU)
#define BCTU_FIFOCNTR_CNTR_FIFO1_SHIFT           (0U)
/*! CNTR_FIFO1 - FIFO1 Counter */
#define BCTU_FIFOCNTR_CNTR_FIFO1(x)              (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCNTR_CNTR_FIFO1_SHIFT)) & BCTU_FIFOCNTR_CNTR_FIFO1_MASK)

#define BCTU_FIFOCNTR_CNTR_FIFO2_MASK            (0xF00U)
#define BCTU_FIFOCNTR_CNTR_FIFO2_SHIFT           (8U)
/*! CNTR_FIFO2 - FIFO2 Counter */
#define BCTU_FIFOCNTR_CNTR_FIFO2(x)              (((uint32_t)(((uint32_t)(x)) << BCTU_FIFOCNTR_CNTR_FIFO2_SHIFT)) & BCTU_FIFOCNTR_CNTR_FIFO2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BCTU_Register_Masks */


/*!
 * @}
 */ /* end of group BCTU_Peripheral_Access_Layer */


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


#endif  /* PERI_BCTU_H_ */

