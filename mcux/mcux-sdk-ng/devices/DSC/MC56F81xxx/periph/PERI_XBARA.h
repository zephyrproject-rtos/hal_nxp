/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBARA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-12-10)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XBARA.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBARA
 *
 * CMSIS Peripheral Access Layer for XBARA
 */

#if !defined(PERI_XBARA_H_)
#define PERI_XBARA_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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
#if !defined(XBAR_INPUT_SIGNAL_T_)
#define XBAR_INPUT_SIGNAL_T_
typedef enum _xbar_input_signal
{
    kXBARA_InputVss                 = 0U,          /**< VSS output assigned to XBARA_IN0 input. */
    kXBARA_InputVdd                 = 1U,          /**< VDD output assigned to XBARA_IN1 input. */
    kXBARA_InputXbIn2               = 2U,          /**< XB_IN2 output assigned to XBARA_IN2 input. */
    kXBARA_InputXbIn3               = 3U,          /**< XB_IN3 output assigned to XBARA_IN3 input. */
    kXBARA_InputXbIn4               = 4U,          /**< XB_IN4 output assigned to XBARA_IN4 input. */
    kXBARA_InputXbIn5               = 5U,          /**< XB_IN5 output assigned to XBARA_IN5 input. */
    kXBARA_InputXbIn6               = 6U,          /**< XB_IN6 output assigned to XBARA_IN6 input. */
    kXBARA_InputXbIn7               = 7U,          /**< XB_IN7 output assigned to XBARA_IN7 input. */
    kXBARA_InputXbIn8               = 8U,          /**< XB_IN8 output assigned to XBARA_IN8 input. */
    kXBARA_InputXbIn9               = 9U,          /**< XB_IN9 output assigned to XBARA_IN9 input. */
    kXBARA_InputLpi2c0MSTrig        = 10U,         /**< LPI2C0_M_S_TRIG output assigned to XBARA_IN10 input. */
    kXBARA_InputEwmOutB             = 11U,         /**< EWM_OUT_B output assigned to XBARA_IN11 input. */
    kXBARA_InputCmpaOut             = 12U,         /**< CMPA_OUT output assigned to XBARA_IN12 input. */
    kXBARA_InputCmpbOut             = 13U,         /**< CMPB_OUT output assigned to XBARA_IN13 input. */
    kXBARA_InputCmpcOut             = 14U,         /**< CMPC_OUT output assigned to XBARA_IN14 input. */
    kXBARA_InputCmpdOut             = 15U,         /**< CMPD_OUT output assigned to XBARA_IN15 input. */
    kXBARA_InputAn8Limit            = 16U,         /**< AN8_LIMIT output assigned to XBARA_IN16 input. */
    kXBARA_InputAn9Limit            = 17U,         /**< AN9_LIMIT output assigned to XBARA_IN17 input. */
    kXBARA_InputAn10Limit           = 18U,         /**< AN10_LIMIT output assigned to XBARA_IN18 input. */
    kXBARA_InputAn11Limit           = 19U,         /**< AN11_LIMIT output assigned to XBARA_IN19 input. */
    kXBARA_InputPwma0A              = 20U,         /**< PWMA0_A output assigned to XBARA_IN20 input. */
    kXBARA_InputPwma0B              = 21U,         /**< PWMA0_B output assigned to XBARA_IN21 input. */
    kXBARA_InputPwma1A              = 22U,         /**< PWMA1_A output assigned to XBARA_IN22 input. */
    kXBARA_InputPwma1B              = 23U,         /**< PWMA1_B output assigned to XBARA_IN23 input. */
    kXBARA_InputPwma2A              = 24U,         /**< PWMA2_A output assigned to XBARA_IN24 input. */
    kXBARA_InputPwma2B              = 25U,         /**< PWMA2_B output assigned to XBARA_IN25 input. */
    kXBARA_InputPwma3A              = 26U,         /**< PWMA3_A output assigned to XBARA_IN26 input. */
    kXBARA_InputPwma3B              = 27U,         /**< PWMA3_B output assigned to XBARA_IN27 input. */
    kXBARA_InputPwma0OutTrig0       = 28U,         /**< PWMA0_OUT_TRIG0 output assigned to XBARA_IN28 input. */
    kXBARA_InputPwma0OutTrig1       = 29U,         /**< PWMA0_OUT_TRIG1 output assigned to XBARA_IN29 input. */
    kXBARA_InputPwma1OutTrig0       = 30U,         /**< PWMA1_OUT_TRIG0 output assigned to XBARA_IN30 input. */
    kXBARA_InputPwma1OutTrig1       = 31U,         /**< PWMA1_OUT_TRIG1 output assigned to XBARA_IN31 input. */
    kXBARA_InputPwma2OutTrig0       = 32U,         /**< PWMA2_OUT_TRIG0 output assigned to XBARA_IN32 input. */
    kXBARA_InputPwma2OutTrig1       = 33U,         /**< PWMA2_OUT_TRIG1 output assigned to XBARA_IN33 input. */
    kXBARA_InputPwma3OutTrig0       = 34U,         /**< PWMA3_OUT_TRIG0 output assigned to XBARA_IN34 input. */
    kXBARA_InputPwma3OutTrig1       = 35U,         /**< PWMA3_OUT_TRIG1 output assigned to XBARA_IN35 input. */
    kXBARA_InputAn0LimitTa0Out      = 36U,         /**< AN0_LIMIT_TA0_OUT output assigned to XBARA_IN36 input. */
    kXBARA_InputAn1LimitTa1Out      = 37U,         /**< AN1_LIMIT_TA1_OUT output assigned to XBARA_IN37 input. */
    kXBARA_InputAn2LimitTa2Out      = 38U,         /**< AN2_LIMIT_TA2_OUT output assigned to XBARA_IN38 input. */
    kXBARA_InputAn3LimitTa3Out      = 39U,         /**< AN3_LIMIT_TA3_OUT output assigned to XBARA_IN39 input. */
    kXBARA_InputEvtg0Outa           = 40U,         /**< EVTG0_OUTA output assigned to XBARA_IN40 input. */
    kXBARA_InputEvtg1Outa           = 41U,         /**< EVTG1_OUTA output assigned to XBARA_IN41 input. */
    kXBARA_InputEvtg2Outa           = 42U,         /**< EVTG2_OUTA output assigned to XBARA_IN42 input. */
    kXBARA_InputEvtg3Outa           = 43U,         /**< EVTG3_OUTA output assigned to XBARA_IN43 input. */
    kXBARA_InputPit0SyncOut         = 44U,         /**< PIT0_SYNC_OUT output assigned to XBARA_IN44 input. */
    kXBARA_InputPit1SyncOut         = 45U,         /**< PIT1_SYNC_OUT output assigned to XBARA_IN45 input. */
    kXBARA_InputEvtg0Outb           = 46U,         /**< EVTG0_OUTB output assigned to XBARA_IN46 input. */
    kXBARA_InputEvtg1Outb           = 47U,         /**< EVTG1_OUTB output assigned to XBARA_IN47 input. */
    kXBARA_InputEvtg2Outb           = 48U,         /**< EVTG2_OUTB output assigned to XBARA_IN48 input. */
    kXBARA_InputEvtg3Outb           = 49U,         /**< EVTG3_OUTB output assigned to XBARA_IN49 input. */
    kXBARA_InputQdcPosmatch         = 50U,         /**< QDC_POSMATCH output assigned to XBARA_IN50 input. */
    kXBARA_InputPwmaAllTrig         = 51U,         /**< PWMA_ALL_TRIG output assigned to XBARA_IN51 input. */
    kXBARA_InputSci0RxFull          = 52U,         /**< SCI0_RX_FULL output assigned to XBARA_IN52 input. */
    kXBARA_InputLpi2c1MSTrig        = 53U,         /**< LPI2C1_M_S_TRIG output assigned to XBARA_IN53 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBARA_OutputDmaReq0            = 0U,          /**< XBARA_OUT0 output assigned to DMA_REQ0 */
    kXBARA_OutputDmaReq1            = 1U,          /**< XBARA_OUT1 output assigned to DMA_REQ1 */
    kXBARA_OutputDmaReq2            = 2U,          /**< XBARA_OUT2 output assigned to DMA_REQ2 */
    kXBARA_OutputDmaReq3            = 3U,          /**< XBARA_OUT3 output assigned to DMA_REQ3 */
    kXBARA_OutputXbOut4             = 4U,          /**< XBARA_OUT4 output assigned to XB_OUT4 */
    kXBARA_OutputXbOut5             = 5U,          /**< XBARA_OUT5 output assigned to XB_OUT5 */
    kXBARA_OutputXbOut6             = 6U,          /**< XBARA_OUT6 output assigned to XB_OUT6 */
    kXBARA_OutputXbOut7             = 7U,          /**< XBARA_OUT7 output assigned to XB_OUT7 */
    kXBARA_OutputXbOut8             = 8U,          /**< XBARA_OUT8 output assigned to XB_OUT8 */
    kXBARA_OutputXbOut9             = 9U,          /**< XBARA_OUT9 output assigned to XB_OUT9 */
    kXBARA_OutputXbOut10            = 10U,         /**< XBARA_OUT10 output assigned to XB_OUT10 */
    kXBARA_OutputXbOut11            = 11U,         /**< XBARA_OUT11 output assigned to XB_OUT11 */
    kXBARA_OutputAdcSync0           = 12U,         /**< XBARA_OUT12 output assigned to ADC_SYNC0 */
    kXBARA_OutputAdcSync1           = 13U,         /**< XBARA_OUT13 output assigned to ADC_SYNC1 */
    kXBARA_OutputOpampaOpampbCfgSelB1C1 = 14U,     /**< XBARA_OUT14 output assigned to OPAMPA_OPAMPB_CFG_SEL_B1_C1 */
    kXBARA_OutputDaca12bSync        = 15U,         /**< XBARA_OUT15 output assigned to DACA_12B_SYNC */
    kXBARA_OutputCmpa               = 16U,         /**< XBARA_OUT16 output assigned to CMPA */
    kXBARA_OutputCmpb               = 17U,         /**< XBARA_OUT17 output assigned to CMPB */
    kXBARA_OutputCmpc               = 18U,         /**< XBARA_OUT18 output assigned to CMPC */
    kXBARA_OutputCmpd               = 19U,         /**< XBARA_OUT19 output assigned to CMPD */
    kXBARA_OutputPwma0Exta          = 20U,         /**< XBARA_OUT20 output assigned to PWMA0_EXTA */
    kXBARA_OutputPwma1Exta          = 21U,         /**< XBARA_OUT21 output assigned to PWMA1_EXTA */
    kXBARA_OutputPwma2Exta          = 22U,         /**< XBARA_OUT22 output assigned to PWMA2_EXTA */
    kXBARA_OutputPwma3Exta          = 23U,         /**< XBARA_OUT23 output assigned to PWMA3_EXTA */
    kXBARA_OutputPwma0ExtSync       = 24U,         /**< XBARA_OUT24 output assigned to PWMA0_EXT_SYNC */
    kXBARA_OutputPwma1ExtSync       = 25U,         /**< XBARA_OUT25 output assigned to PWMA1_EXT_SYNC */
    kXBARA_OutputPwma2ExtSync       = 26U,         /**< XBARA_OUT26 output assigned to PWMA2_EXT_SYNC */
    kXBARA_OutputPwma3ExtSync       = 27U,         /**< XBARA_OUT27 output assigned to PWMA3_EXT_SYNC */
    kXBARA_OutputPwmaExtClk         = 28U,         /**< XBARA_OUT28 output assigned to PWMA_EXT_CLK */
    kXBARA_OutputPwmaFault0         = 29U,         /**< XBARA_OUT29 output assigned to PWMA_FAULT0 */
    kXBARA_OutputPwmaFault1         = 30U,         /**< XBARA_OUT30 output assigned to PWMA_FAULT1 */
    kXBARA_OutputPwmaFault2         = 31U,         /**< XBARA_OUT31 output assigned to PWMA_FAULT2 */
    kXBARA_OutputPwmaFault3         = 32U,         /**< XBARA_OUT32 output assigned to PWMA_FAULT3 */
    kXBARA_OutputPwmaForce          = 33U,         /**< XBARA_OUT33 output assigned to PWMA_FORCE */
    kXBARA_OutputOpampaCfgSelB0C0   = 34U,         /**< XBARA_OUT34 output assigned to OPAMPA_CFG_SEL_B0_C0 */
    kXBARA_OutputOpampbCfgSelB0C0   = 35U,         /**< XBARA_OUT35 output assigned to OPAMPB_CFG_SEL_B0_C0 */
    kXBARA_OutputSci0Rxd            = 36U,         /**< XBARA_OUT36 output assigned to SCI0_RXD */
    kXBARA_OutputSci1Rxd            = 37U,         /**< XBARA_OUT37 output assigned to SCI1_RXD */
    kXBARA_OutputTa0In              = 38U,         /**< XBARA_OUT38 output assigned to TA0_IN */
    kXBARA_OutputTa1In              = 39U,         /**< XBARA_OUT39 output assigned to TA1_IN */
    kXBARA_OutputTa2In              = 40U,         /**< XBARA_OUT40 output assigned to TA2_IN */
    kXBARA_OutputTa3In              = 41U,         /**< XBARA_OUT41 output assigned to TA3_IN */
    kXBARA_OutputQdcPha             = 42U,         /**< XBARA_OUT42 output assigned to QDC_PHA */
    kXBARA_OutputQdcPhb             = 43U,         /**< XBARA_OUT43 output assigned to QDC_PHB */
    kXBARA_OutputQdcIndex           = 44U,         /**< XBARA_OUT44 output assigned to QDC_INDEX */
    kXBARA_OutputQdcHome            = 45U,         /**< XBARA_OUT45 output assigned to QDC_HOME */
    kXBARA_OutputQdcTrig            = 46U,         /**< XBARA_OUT46 output assigned to QDC_TRIG */
    kXBARA_OutputEvtg0A             = 47U,         /**< XBARA_OUT47 output assigned to EVTG0_A */
    kXBARA_OutputEvtg0B             = 48U,         /**< XBARA_OUT48 output assigned to EVTG0_B */
    kXBARA_OutputEvtg0C             = 49U,         /**< XBARA_OUT49 output assigned to EVTG0_C */
    kXBARA_OutputEvtg0D             = 50U,         /**< XBARA_OUT50 output assigned to EVTG0_D */
    kXBARA_OutputEvtg1A             = 51U,         /**< XBARA_OUT51 output assigned to EVTG1_A */
    kXBARA_OutputEvtg1B             = 52U,         /**< XBARA_OUT52 output assigned to EVTG1_B */
    kXBARA_OutputEvtg1C             = 53U,         /**< XBARA_OUT53 output assigned to EVTG1_C */
    kXBARA_OutputEvtg1D             = 54U,         /**< XBARA_OUT54 output assigned to EVTG1_D */
    kXBARA_OutputEvtg2A             = 55U,         /**< XBARA_OUT55 output assigned to EVTG2_A */
    kXBARA_OutputEvtg2B             = 56U,         /**< XBARA_OUT56 output assigned to EVTG2_B */
    kXBARA_OutputEvtg2C             = 57U,         /**< XBARA_OUT57 output assigned to EVTG2_C */
    kXBARA_OutputEvtg2D             = 58U,         /**< XBARA_OUT58 output assigned to EVTG2_D */
    kXBARA_OutputEvtg3A             = 59U,         /**< XBARA_OUT59 output assigned to EVTG3_A */
    kXBARA_OutputEvtg3B             = 60U,         /**< XBARA_OUT60 output assigned to EVTG3_B */
    kXBARA_OutputEvtg3C             = 61U,         /**< XBARA_OUT61 output assigned to EVTG3_C */
    kXBARA_OutputEvtg3D             = 62U,         /**< XBARA_OUT62 output assigned to EVTG3_D */
    kXBARA_OutputEwmIn              = 63U,         /**< XBARA_OUT63 output assigned to EWM_IN */
    kXBARA_OutputLpi2c0InTrigHreq   = 64U,         /**< XBARA_OUT64 output assigned to LPI2C0_IN_TRIG_HREQ */
    kXBARA_OutputLpi2c1InTrigHreq   = 65U,         /**< XBARA_OUT65 output assigned to LPI2C1_IN_TRIG_HREQ */
} xbar_output_signal_t;
#endif /* XBAR_OUTPUT_SIGNAL_T_ */


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
   -- XBARA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Peripheral_Access_Layer XBARA Peripheral Access Layer
 * @{
 */

/** XBARA - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar A Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar A Select Register 1, offset: 0x1 */
  __IO uint16_t SEL2;                              /**< Crossbar A Select Register 2, offset: 0x2 */
  __IO uint16_t SEL3;                              /**< Crossbar A Select Register 3, offset: 0x3 */
  __IO uint16_t SEL4;                              /**< Crossbar A Select Register 4, offset: 0x4 */
  __IO uint16_t SEL5;                              /**< Crossbar A Select Register 5, offset: 0x5 */
  __IO uint16_t SEL6;                              /**< Crossbar A Select Register 6, offset: 0x6 */
  __IO uint16_t SEL7;                              /**< Crossbar A Select Register 7, offset: 0x7 */
  __IO uint16_t SEL8;                              /**< Crossbar A Select Register 8, offset: 0x8 */
  __IO uint16_t SEL9;                              /**< Crossbar A Select Register 9, offset: 0x9 */
  __IO uint16_t SEL10;                             /**< Crossbar A Select Register 10, offset: 0xA */
  __IO uint16_t SEL11;                             /**< Crossbar A Select Register 11, offset: 0xB */
  __IO uint16_t SEL12;                             /**< Crossbar A Select Register 12, offset: 0xC */
  __IO uint16_t SEL13;                             /**< Crossbar A Select Register 13, offset: 0xD */
  __IO uint16_t SEL14;                             /**< Crossbar A Select Register 14, offset: 0xE */
  __IO uint16_t SEL15;                             /**< Crossbar A Select Register 15, offset: 0xF */
  __IO uint16_t SEL16;                             /**< Crossbar A Select Register 16, offset: 0x10 */
  __IO uint16_t SEL17;                             /**< Crossbar A Select Register 17, offset: 0x11 */
  __IO uint16_t SEL18;                             /**< Crossbar A Select Register 18, offset: 0x12 */
  __IO uint16_t SEL19;                             /**< Crossbar A Select Register 19, offset: 0x13 */
  __IO uint16_t SEL20;                             /**< Crossbar A Select Register 20, offset: 0x14 */
  __IO uint16_t SEL21;                             /**< Crossbar A Select Register 21, offset: 0x15 */
  __IO uint16_t SEL22;                             /**< Crossbar A Select Register 22, offset: 0x16 */
  __IO uint16_t SEL23;                             /**< Crossbar A Select Register 23, offset: 0x17 */
  __IO uint16_t SEL24;                             /**< Crossbar A Select Register 24, offset: 0x18 */
  __IO uint16_t SEL25;                             /**< Crossbar A Select Register 25, offset: 0x19 */
  __IO uint16_t SEL26;                             /**< Crossbar A Select Register 26, offset: 0x1A */
  __IO uint16_t SEL27;                             /**< Crossbar A Select Register 27, offset: 0x1B */
  __IO uint16_t SEL28;                             /**< Crossbar A Select Register 28, offset: 0x1C */
  __IO uint16_t SEL29;                             /**< Crossbar A Select Register 29, offset: 0x1D */
  __IO uint16_t SEL30;                             /**< Crossbar A Select Register 30, offset: 0x1E */
  __IO uint16_t SEL31;                             /**< Crossbar A Select Register 31, offset: 0x1F */
  __IO uint16_t SEL32;                             /**< Crossbar A Select Register 31, offset: 0x20 */
  __IO uint16_t CTRL0;                             /**< Crossbar A Control Register 0, offset: 0x21 */
  __IO uint16_t CTRL1;                             /**< Crossbar A Control Register 1, offset: 0x22 */
} XBARA_Type;

/* ----------------------------------------------------------------------------
   -- XBARA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARA_Register_Masks XBARA Register Masks
 * @{
 */

/*! @name SEL0 - Crossbar A Select Register 0 */
/*! @{ */

#define XBARA_SEL0_SEL0_MASK                     (0x3FU)
#define XBARA_SEL0_SEL0_SHIFT                    (0U)
#define XBARA_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL0_SEL0_SHIFT)) & XBARA_SEL0_SEL0_MASK)

#define XBARA_SEL0_SEL1_MASK                     (0x3F00U)
#define XBARA_SEL0_SEL1_SHIFT                    (8U)
#define XBARA_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL0_SEL1_SHIFT)) & XBARA_SEL0_SEL1_MASK)
/*! @} */

/*! @name SEL1 - Crossbar A Select Register 1 */
/*! @{ */

#define XBARA_SEL1_SEL2_MASK                     (0x3FU)
#define XBARA_SEL1_SEL2_SHIFT                    (0U)
#define XBARA_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL1_SEL2_SHIFT)) & XBARA_SEL1_SEL2_MASK)

#define XBARA_SEL1_SEL3_MASK                     (0x3F00U)
#define XBARA_SEL1_SEL3_SHIFT                    (8U)
#define XBARA_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL1_SEL3_SHIFT)) & XBARA_SEL1_SEL3_MASK)
/*! @} */

/*! @name SEL2 - Crossbar A Select Register 2 */
/*! @{ */

#define XBARA_SEL2_SEL4_MASK                     (0x3FU)
#define XBARA_SEL2_SEL4_SHIFT                    (0U)
#define XBARA_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL2_SEL4_SHIFT)) & XBARA_SEL2_SEL4_MASK)

#define XBARA_SEL2_SEL5_MASK                     (0x3F00U)
#define XBARA_SEL2_SEL5_SHIFT                    (8U)
#define XBARA_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL2_SEL5_SHIFT)) & XBARA_SEL2_SEL5_MASK)
/*! @} */

/*! @name SEL3 - Crossbar A Select Register 3 */
/*! @{ */

#define XBARA_SEL3_SEL6_MASK                     (0x3FU)
#define XBARA_SEL3_SEL6_SHIFT                    (0U)
#define XBARA_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL3_SEL6_SHIFT)) & XBARA_SEL3_SEL6_MASK)

#define XBARA_SEL3_SEL7_MASK                     (0x3F00U)
#define XBARA_SEL3_SEL7_SHIFT                    (8U)
#define XBARA_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL3_SEL7_SHIFT)) & XBARA_SEL3_SEL7_MASK)
/*! @} */

/*! @name SEL4 - Crossbar A Select Register 4 */
/*! @{ */

#define XBARA_SEL4_SEL8_MASK                     (0x3FU)
#define XBARA_SEL4_SEL8_SHIFT                    (0U)
#define XBARA_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL4_SEL8_SHIFT)) & XBARA_SEL4_SEL8_MASK)

#define XBARA_SEL4_SEL9_MASK                     (0x3F00U)
#define XBARA_SEL4_SEL9_SHIFT                    (8U)
#define XBARA_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x)) << XBARA_SEL4_SEL9_SHIFT)) & XBARA_SEL4_SEL9_MASK)
/*! @} */

/*! @name SEL5 - Crossbar A Select Register 5 */
/*! @{ */

#define XBARA_SEL5_SEL10_MASK                    (0x3FU)
#define XBARA_SEL5_SEL10_SHIFT                   (0U)
#define XBARA_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL5_SEL10_SHIFT)) & XBARA_SEL5_SEL10_MASK)

#define XBARA_SEL5_SEL11_MASK                    (0x3F00U)
#define XBARA_SEL5_SEL11_SHIFT                   (8U)
#define XBARA_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL5_SEL11_SHIFT)) & XBARA_SEL5_SEL11_MASK)
/*! @} */

/*! @name SEL6 - Crossbar A Select Register 6 */
/*! @{ */

#define XBARA_SEL6_SEL12_MASK                    (0x3FU)
#define XBARA_SEL6_SEL12_SHIFT                   (0U)
#define XBARA_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL6_SEL12_SHIFT)) & XBARA_SEL6_SEL12_MASK)

#define XBARA_SEL6_SEL13_MASK                    (0x3F00U)
#define XBARA_SEL6_SEL13_SHIFT                   (8U)
#define XBARA_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL6_SEL13_SHIFT)) & XBARA_SEL6_SEL13_MASK)
/*! @} */

/*! @name SEL7 - Crossbar A Select Register 7 */
/*! @{ */

#define XBARA_SEL7_SEL14_MASK                    (0x3FU)
#define XBARA_SEL7_SEL14_SHIFT                   (0U)
#define XBARA_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL7_SEL14_SHIFT)) & XBARA_SEL7_SEL14_MASK)

#define XBARA_SEL7_SEL15_MASK                    (0x3F00U)
#define XBARA_SEL7_SEL15_SHIFT                   (8U)
#define XBARA_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL7_SEL15_SHIFT)) & XBARA_SEL7_SEL15_MASK)
/*! @} */

/*! @name SEL8 - Crossbar A Select Register 8 */
/*! @{ */

#define XBARA_SEL8_SEL16_MASK                    (0x3FU)
#define XBARA_SEL8_SEL16_SHIFT                   (0U)
#define XBARA_SEL8_SEL16(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL8_SEL16_SHIFT)) & XBARA_SEL8_SEL16_MASK)

#define XBARA_SEL8_SEL17_MASK                    (0x3F00U)
#define XBARA_SEL8_SEL17_SHIFT                   (8U)
#define XBARA_SEL8_SEL17(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL8_SEL17_SHIFT)) & XBARA_SEL8_SEL17_MASK)
/*! @} */

/*! @name SEL9 - Crossbar A Select Register 9 */
/*! @{ */

#define XBARA_SEL9_SEL18_MASK                    (0x3FU)
#define XBARA_SEL9_SEL18_SHIFT                   (0U)
#define XBARA_SEL9_SEL18(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL9_SEL18_SHIFT)) & XBARA_SEL9_SEL18_MASK)

#define XBARA_SEL9_SEL19_MASK                    (0x3F00U)
#define XBARA_SEL9_SEL19_SHIFT                   (8U)
#define XBARA_SEL9_SEL19(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_SEL9_SEL19_SHIFT)) & XBARA_SEL9_SEL19_MASK)
/*! @} */

/*! @name SEL10 - Crossbar A Select Register 10 */
/*! @{ */

#define XBARA_SEL10_SEL20_MASK                   (0x3FU)
#define XBARA_SEL10_SEL20_SHIFT                  (0U)
#define XBARA_SEL10_SEL20(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL10_SEL20_SHIFT)) & XBARA_SEL10_SEL20_MASK)

#define XBARA_SEL10_SEL21_MASK                   (0x3F00U)
#define XBARA_SEL10_SEL21_SHIFT                  (8U)
#define XBARA_SEL10_SEL21(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL10_SEL21_SHIFT)) & XBARA_SEL10_SEL21_MASK)
/*! @} */

/*! @name SEL11 - Crossbar A Select Register 11 */
/*! @{ */

#define XBARA_SEL11_SEL22_MASK                   (0x3FU)
#define XBARA_SEL11_SEL22_SHIFT                  (0U)
#define XBARA_SEL11_SEL22(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL11_SEL22_SHIFT)) & XBARA_SEL11_SEL22_MASK)

#define XBARA_SEL11_SEL23_MASK                   (0x3F00U)
#define XBARA_SEL11_SEL23_SHIFT                  (8U)
#define XBARA_SEL11_SEL23(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL11_SEL23_SHIFT)) & XBARA_SEL11_SEL23_MASK)
/*! @} */

/*! @name SEL12 - Crossbar A Select Register 12 */
/*! @{ */

#define XBARA_SEL12_SEL24_MASK                   (0x3FU)
#define XBARA_SEL12_SEL24_SHIFT                  (0U)
#define XBARA_SEL12_SEL24(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL12_SEL24_SHIFT)) & XBARA_SEL12_SEL24_MASK)

#define XBARA_SEL12_SEL25_MASK                   (0x3F00U)
#define XBARA_SEL12_SEL25_SHIFT                  (8U)
#define XBARA_SEL12_SEL25(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL12_SEL25_SHIFT)) & XBARA_SEL12_SEL25_MASK)
/*! @} */

/*! @name SEL13 - Crossbar A Select Register 13 */
/*! @{ */

#define XBARA_SEL13_SEL26_MASK                   (0x3FU)
#define XBARA_SEL13_SEL26_SHIFT                  (0U)
#define XBARA_SEL13_SEL26(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL13_SEL26_SHIFT)) & XBARA_SEL13_SEL26_MASK)

#define XBARA_SEL13_SEL27_MASK                   (0x3F00U)
#define XBARA_SEL13_SEL27_SHIFT                  (8U)
#define XBARA_SEL13_SEL27(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL13_SEL27_SHIFT)) & XBARA_SEL13_SEL27_MASK)
/*! @} */

/*! @name SEL14 - Crossbar A Select Register 14 */
/*! @{ */

#define XBARA_SEL14_SEL28_MASK                   (0x3FU)
#define XBARA_SEL14_SEL28_SHIFT                  (0U)
#define XBARA_SEL14_SEL28(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL14_SEL28_SHIFT)) & XBARA_SEL14_SEL28_MASK)

#define XBARA_SEL14_SEL29_MASK                   (0x3F00U)
#define XBARA_SEL14_SEL29_SHIFT                  (8U)
#define XBARA_SEL14_SEL29(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL14_SEL29_SHIFT)) & XBARA_SEL14_SEL29_MASK)
/*! @} */

/*! @name SEL15 - Crossbar A Select Register 15 */
/*! @{ */

#define XBARA_SEL15_SEL30_MASK                   (0x3FU)
#define XBARA_SEL15_SEL30_SHIFT                  (0U)
#define XBARA_SEL15_SEL30(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL15_SEL30_SHIFT)) & XBARA_SEL15_SEL30_MASK)

#define XBARA_SEL15_SEL31_MASK                   (0x3F00U)
#define XBARA_SEL15_SEL31_SHIFT                  (8U)
#define XBARA_SEL15_SEL31(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL15_SEL31_SHIFT)) & XBARA_SEL15_SEL31_MASK)
/*! @} */

/*! @name SEL16 - Crossbar A Select Register 16 */
/*! @{ */

#define XBARA_SEL16_SEL32_MASK                   (0x3FU)
#define XBARA_SEL16_SEL32_SHIFT                  (0U)
#define XBARA_SEL16_SEL32(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL16_SEL32_SHIFT)) & XBARA_SEL16_SEL32_MASK)

#define XBARA_SEL16_SEL33_MASK                   (0x3F00U)
#define XBARA_SEL16_SEL33_SHIFT                  (8U)
#define XBARA_SEL16_SEL33(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL16_SEL33_SHIFT)) & XBARA_SEL16_SEL33_MASK)
/*! @} */

/*! @name SEL17 - Crossbar A Select Register 17 */
/*! @{ */

#define XBARA_SEL17_SEL34_MASK                   (0x3FU)
#define XBARA_SEL17_SEL34_SHIFT                  (0U)
#define XBARA_SEL17_SEL34(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL17_SEL34_SHIFT)) & XBARA_SEL17_SEL34_MASK)

#define XBARA_SEL17_SEL35_MASK                   (0x3F00U)
#define XBARA_SEL17_SEL35_SHIFT                  (8U)
#define XBARA_SEL17_SEL35(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL17_SEL35_SHIFT)) & XBARA_SEL17_SEL35_MASK)
/*! @} */

/*! @name SEL18 - Crossbar A Select Register 18 */
/*! @{ */

#define XBARA_SEL18_SEL36_MASK                   (0x3FU)
#define XBARA_SEL18_SEL36_SHIFT                  (0U)
#define XBARA_SEL18_SEL36(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL18_SEL36_SHIFT)) & XBARA_SEL18_SEL36_MASK)

#define XBARA_SEL18_SEL37_MASK                   (0x3F00U)
#define XBARA_SEL18_SEL37_SHIFT                  (8U)
#define XBARA_SEL18_SEL37(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL18_SEL37_SHIFT)) & XBARA_SEL18_SEL37_MASK)
/*! @} */

/*! @name SEL19 - Crossbar A Select Register 19 */
/*! @{ */

#define XBARA_SEL19_SEL38_MASK                   (0x3FU)
#define XBARA_SEL19_SEL38_SHIFT                  (0U)
#define XBARA_SEL19_SEL38(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL19_SEL38_SHIFT)) & XBARA_SEL19_SEL38_MASK)

#define XBARA_SEL19_SEL39_MASK                   (0x3F00U)
#define XBARA_SEL19_SEL39_SHIFT                  (8U)
#define XBARA_SEL19_SEL39(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL19_SEL39_SHIFT)) & XBARA_SEL19_SEL39_MASK)
/*! @} */

/*! @name SEL20 - Crossbar A Select Register 20 */
/*! @{ */

#define XBARA_SEL20_SEL40_MASK                   (0x3FU)
#define XBARA_SEL20_SEL40_SHIFT                  (0U)
#define XBARA_SEL20_SEL40(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL20_SEL40_SHIFT)) & XBARA_SEL20_SEL40_MASK)

#define XBARA_SEL20_SEL41_MASK                   (0x3F00U)
#define XBARA_SEL20_SEL41_SHIFT                  (8U)
#define XBARA_SEL20_SEL41(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL20_SEL41_SHIFT)) & XBARA_SEL20_SEL41_MASK)
/*! @} */

/*! @name SEL21 - Crossbar A Select Register 21 */
/*! @{ */

#define XBARA_SEL21_SEL42_MASK                   (0x3FU)
#define XBARA_SEL21_SEL42_SHIFT                  (0U)
#define XBARA_SEL21_SEL42(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL21_SEL42_SHIFT)) & XBARA_SEL21_SEL42_MASK)

#define XBARA_SEL21_SEL43_MASK                   (0x3F00U)
#define XBARA_SEL21_SEL43_SHIFT                  (8U)
#define XBARA_SEL21_SEL43(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL21_SEL43_SHIFT)) & XBARA_SEL21_SEL43_MASK)
/*! @} */

/*! @name SEL22 - Crossbar A Select Register 22 */
/*! @{ */

#define XBARA_SEL22_SEL44_MASK                   (0x3FU)
#define XBARA_SEL22_SEL44_SHIFT                  (0U)
#define XBARA_SEL22_SEL44(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL22_SEL44_SHIFT)) & XBARA_SEL22_SEL44_MASK)

#define XBARA_SEL22_SEL45_MASK                   (0x3F00U)
#define XBARA_SEL22_SEL45_SHIFT                  (8U)
#define XBARA_SEL22_SEL45(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL22_SEL45_SHIFT)) & XBARA_SEL22_SEL45_MASK)
/*! @} */

/*! @name SEL23 - Crossbar A Select Register 23 */
/*! @{ */

#define XBARA_SEL23_SEL46_MASK                   (0x3FU)
#define XBARA_SEL23_SEL46_SHIFT                  (0U)
#define XBARA_SEL23_SEL46(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL23_SEL46_SHIFT)) & XBARA_SEL23_SEL46_MASK)

#define XBARA_SEL23_SEL47_MASK                   (0x3F00U)
#define XBARA_SEL23_SEL47_SHIFT                  (8U)
#define XBARA_SEL23_SEL47(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL23_SEL47_SHIFT)) & XBARA_SEL23_SEL47_MASK)
/*! @} */

/*! @name SEL24 - Crossbar A Select Register 24 */
/*! @{ */

#define XBARA_SEL24_SEL48_MASK                   (0x3FU)
#define XBARA_SEL24_SEL48_SHIFT                  (0U)
#define XBARA_SEL24_SEL48(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL24_SEL48_SHIFT)) & XBARA_SEL24_SEL48_MASK)

#define XBARA_SEL24_SEL49_MASK                   (0x3F00U)
#define XBARA_SEL24_SEL49_SHIFT                  (8U)
#define XBARA_SEL24_SEL49(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL24_SEL49_SHIFT)) & XBARA_SEL24_SEL49_MASK)
/*! @} */

/*! @name SEL25 - Crossbar A Select Register 25 */
/*! @{ */

#define XBARA_SEL25_SEL50_MASK                   (0x3FU)
#define XBARA_SEL25_SEL50_SHIFT                  (0U)
#define XBARA_SEL25_SEL50(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL25_SEL50_SHIFT)) & XBARA_SEL25_SEL50_MASK)

#define XBARA_SEL25_SEL51_MASK                   (0x3F00U)
#define XBARA_SEL25_SEL51_SHIFT                  (8U)
#define XBARA_SEL25_SEL51(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL25_SEL51_SHIFT)) & XBARA_SEL25_SEL51_MASK)
/*! @} */

/*! @name SEL26 - Crossbar A Select Register 26 */
/*! @{ */

#define XBARA_SEL26_SEL52_MASK                   (0x3FU)
#define XBARA_SEL26_SEL52_SHIFT                  (0U)
#define XBARA_SEL26_SEL52(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL26_SEL52_SHIFT)) & XBARA_SEL26_SEL52_MASK)

#define XBARA_SEL26_SEL53_MASK                   (0x3F00U)
#define XBARA_SEL26_SEL53_SHIFT                  (8U)
#define XBARA_SEL26_SEL53(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL26_SEL53_SHIFT)) & XBARA_SEL26_SEL53_MASK)
/*! @} */

/*! @name SEL27 - Crossbar A Select Register 27 */
/*! @{ */

#define XBARA_SEL27_SEL54_MASK                   (0x3FU)
#define XBARA_SEL27_SEL54_SHIFT                  (0U)
#define XBARA_SEL27_SEL54(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL27_SEL54_SHIFT)) & XBARA_SEL27_SEL54_MASK)

#define XBARA_SEL27_SEL55_MASK                   (0x3F00U)
#define XBARA_SEL27_SEL55_SHIFT                  (8U)
#define XBARA_SEL27_SEL55(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL27_SEL55_SHIFT)) & XBARA_SEL27_SEL55_MASK)
/*! @} */

/*! @name SEL28 - Crossbar A Select Register 28 */
/*! @{ */

#define XBARA_SEL28_SEL56_MASK                   (0x3FU)
#define XBARA_SEL28_SEL56_SHIFT                  (0U)
#define XBARA_SEL28_SEL56(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL28_SEL56_SHIFT)) & XBARA_SEL28_SEL56_MASK)

#define XBARA_SEL28_SEL57_MASK                   (0x3F00U)
#define XBARA_SEL28_SEL57_SHIFT                  (8U)
#define XBARA_SEL28_SEL57(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL28_SEL57_SHIFT)) & XBARA_SEL28_SEL57_MASK)
/*! @} */

/*! @name SEL29 - Crossbar A Select Register 29 */
/*! @{ */

#define XBARA_SEL29_SEL58_MASK                   (0x3FU)
#define XBARA_SEL29_SEL58_SHIFT                  (0U)
#define XBARA_SEL29_SEL58(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL29_SEL58_SHIFT)) & XBARA_SEL29_SEL58_MASK)

#define XBARA_SEL29_SEL59_MASK                   (0x3F00U)
#define XBARA_SEL29_SEL59_SHIFT                  (8U)
#define XBARA_SEL29_SEL59(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL29_SEL59_SHIFT)) & XBARA_SEL29_SEL59_MASK)
/*! @} */

/*! @name SEL30 - Crossbar A Select Register 30 */
/*! @{ */

#define XBARA_SEL30_SEL60_MASK                   (0x3FU)
#define XBARA_SEL30_SEL60_SHIFT                  (0U)
#define XBARA_SEL30_SEL60(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL30_SEL60_SHIFT)) & XBARA_SEL30_SEL60_MASK)

#define XBARA_SEL30_SEL61_MASK                   (0x3F00U)
#define XBARA_SEL30_SEL61_SHIFT                  (8U)
#define XBARA_SEL30_SEL61(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL30_SEL61_SHIFT)) & XBARA_SEL30_SEL61_MASK)
/*! @} */

/*! @name SEL31 - Crossbar A Select Register 31 */
/*! @{ */

#define XBARA_SEL31_SEL62_MASK                   (0x3FU)
#define XBARA_SEL31_SEL62_SHIFT                  (0U)
#define XBARA_SEL31_SEL62(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL31_SEL62_SHIFT)) & XBARA_SEL31_SEL62_MASK)

#define XBARA_SEL31_SEL63_MASK                   (0x3F00U)
#define XBARA_SEL31_SEL63_SHIFT                  (8U)
#define XBARA_SEL31_SEL63(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL31_SEL63_SHIFT)) & XBARA_SEL31_SEL63_MASK)
/*! @} */

/*! @name SEL32 - Crossbar A Select Register 31 */
/*! @{ */

#define XBARA_SEL32_SEL64_MASK                   (0x3FU)
#define XBARA_SEL32_SEL64_SHIFT                  (0U)
#define XBARA_SEL32_SEL64(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL32_SEL64_SHIFT)) & XBARA_SEL32_SEL64_MASK)

#define XBARA_SEL32_SEL65_MASK                   (0x3F00U)
#define XBARA_SEL32_SEL65_SHIFT                  (8U)
#define XBARA_SEL32_SEL65(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_SEL32_SEL65_SHIFT)) & XBARA_SEL32_SEL65_MASK)
/*! @} */

/*! @name CTRL0 - Crossbar A Control Register 0 */
/*! @{ */

#define XBARA_CTRL0_DEN0_MASK                    (0x1U)
#define XBARA_CTRL0_DEN0_SHIFT                   (0U)
/*! DEN0 - DMA Enable for XBAR_OUT0
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL0_DEN0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_DEN0_SHIFT)) & XBARA_CTRL0_DEN0_MASK)

#define XBARA_CTRL0_IEN0_MASK                    (0x2U)
#define XBARA_CTRL0_IEN0_SHIFT                   (1U)
/*! IEN0 - Interrupt Enable for XBAR_OUT0
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL0_IEN0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_IEN0_SHIFT)) & XBARA_CTRL0_IEN0_MASK)

#define XBARA_CTRL0_EDGE0_MASK                   (0xCU)
#define XBARA_CTRL0_EDGE0_SHIFT                  (2U)
/*! EDGE0 - Active edge for edge detection on XBAR_OUT0
 *  0b00..STS0 never asserts
 *  0b01..STS0 asserts on rising edges of XBAR_OUT0
 *  0b10..STS0 asserts on falling edges of XBAR_OUT0
 *  0b11..STS0 asserts on rising and falling edges of XBAR_OUT0
 */
#define XBARA_CTRL0_EDGE0(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_EDGE0_SHIFT)) & XBARA_CTRL0_EDGE0_MASK)

#define XBARA_CTRL0_STS0_MASK                    (0x10U)
#define XBARA_CTRL0_STS0_SHIFT                   (4U)
/*! STS0 - Edge detection status for XBAR_OUT0
 *  0b0..Active edge not yet detected on XBAR_OUT0
 *  0b1..Active edge detected on XBAR_OUT0
 */
#define XBARA_CTRL0_STS0(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_STS0_SHIFT)) & XBARA_CTRL0_STS0_MASK)

#define XBARA_CTRL0_DEN1_MASK                    (0x100U)
#define XBARA_CTRL0_DEN1_SHIFT                   (8U)
/*! DEN1 - DMA Enable for XBAR_OUT1
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL0_DEN1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_DEN1_SHIFT)) & XBARA_CTRL0_DEN1_MASK)

#define XBARA_CTRL0_IEN1_MASK                    (0x200U)
#define XBARA_CTRL0_IEN1_SHIFT                   (9U)
/*! IEN1 - Interrupt Enable for XBAR_OUT1
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL0_IEN1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_IEN1_SHIFT)) & XBARA_CTRL0_IEN1_MASK)

#define XBARA_CTRL0_EDGE1_MASK                   (0xC00U)
#define XBARA_CTRL0_EDGE1_SHIFT                  (10U)
/*! EDGE1 - Active edge for edge detection on XBAR_OUT1
 *  0b00..STS1 never asserts
 *  0b01..STS1 asserts on rising edges of XBAR_OUT1
 *  0b10..STS1 asserts on falling edges of XBAR_OUT1
 *  0b11..STS1 asserts on rising and falling edges of XBAR_OUT1
 */
#define XBARA_CTRL0_EDGE1(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_EDGE1_SHIFT)) & XBARA_CTRL0_EDGE1_MASK)

#define XBARA_CTRL0_STS1_MASK                    (0x1000U)
#define XBARA_CTRL0_STS1_SHIFT                   (12U)
/*! STS1 - Edge detection status for XBAR_OUT1
 *  0b0..Active edge not yet detected on XBAR_OUT1
 *  0b1..Active edge detected on XBAR_OUT1
 */
#define XBARA_CTRL0_STS1(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL0_STS1_SHIFT)) & XBARA_CTRL0_STS1_MASK)
/*! @} */

/*! @name CTRL1 - Crossbar A Control Register 1 */
/*! @{ */

#define XBARA_CTRL1_DEN2_MASK                    (0x1U)
#define XBARA_CTRL1_DEN2_SHIFT                   (0U)
/*! DEN2 - DMA Enable for XBAR_OUT2
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL1_DEN2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_DEN2_SHIFT)) & XBARA_CTRL1_DEN2_MASK)

#define XBARA_CTRL1_IEN2_MASK                    (0x2U)
#define XBARA_CTRL1_IEN2_SHIFT                   (1U)
/*! IEN2 - Interrupt Enable for XBAR_OUT2
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL1_IEN2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_IEN2_SHIFT)) & XBARA_CTRL1_IEN2_MASK)

#define XBARA_CTRL1_EDGE2_MASK                   (0xCU)
#define XBARA_CTRL1_EDGE2_SHIFT                  (2U)
/*! EDGE2 - Active edge for edge detection on XBAR_OUT2
 *  0b00..STS2 never asserts
 *  0b01..STS2 asserts on rising edges of XBAR_OUT2
 *  0b10..STS2 asserts on falling edges of XBAR_OUT2
 *  0b11..STS2 asserts on rising and falling edges of XBAR_OUT2
 */
#define XBARA_CTRL1_EDGE2(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_EDGE2_SHIFT)) & XBARA_CTRL1_EDGE2_MASK)

#define XBARA_CTRL1_STS2_MASK                    (0x10U)
#define XBARA_CTRL1_STS2_SHIFT                   (4U)
/*! STS2 - Edge detection status for XBAR_OUT2
 *  0b0..Active edge not yet detected on XBAR_OUT2
 *  0b1..Active edge detected on XBAR_OUT2
 */
#define XBARA_CTRL1_STS2(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_STS2_SHIFT)) & XBARA_CTRL1_STS2_MASK)

#define XBARA_CTRL1_DEN3_MASK                    (0x100U)
#define XBARA_CTRL1_DEN3_SHIFT                   (8U)
/*! DEN3 - DMA Enable for XBAR_OUT3
 *  0b0..DMA disabled
 *  0b1..DMA enabled
 */
#define XBARA_CTRL1_DEN3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_DEN3_SHIFT)) & XBARA_CTRL1_DEN3_MASK)

#define XBARA_CTRL1_IEN3_MASK                    (0x200U)
#define XBARA_CTRL1_IEN3_SHIFT                   (9U)
/*! IEN3 - Interrupt Enable for XBAR_OUT3
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define XBARA_CTRL1_IEN3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_IEN3_SHIFT)) & XBARA_CTRL1_IEN3_MASK)

#define XBARA_CTRL1_EDGE3_MASK                   (0xC00U)
#define XBARA_CTRL1_EDGE3_SHIFT                  (10U)
/*! EDGE3 - Active edge for edge detection on XBAR_OUT3
 *  0b00..STS3 never asserts
 *  0b01..STS3 asserts on rising edges of XBAR_OUT3
 *  0b10..STS3 asserts on falling edges of XBAR_OUT3
 *  0b11..STS3 asserts on rising and falling edges of XBAR_OUT3
 */
#define XBARA_CTRL1_EDGE3(x)                     (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_EDGE3_SHIFT)) & XBARA_CTRL1_EDGE3_MASK)

#define XBARA_CTRL1_STS3_MASK                    (0x1000U)
#define XBARA_CTRL1_STS3_SHIFT                   (12U)
/*! STS3 - Edge detection status for XBAR_OUT3
 *  0b0..Active edge not yet detected on XBAR_OUT3
 *  0b1..Active edge detected on XBAR_OUT3
 */
#define XBARA_CTRL1_STS3(x)                      (((uint16_t)(((uint16_t)(x)) << XBARA_CTRL1_STS3_SHIFT)) & XBARA_CTRL1_STS3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBARA_Register_Masks */


/*!
 * @}
 */ /* end of group XBARA_Peripheral_Access_Layer */


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


#endif  /* PERI_XBARA_H_ */

