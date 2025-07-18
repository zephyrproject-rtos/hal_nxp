/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XBARB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XBARB.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XBARB
 *
 * CMSIS Peripheral Access Layer for XBARB
 */

#if !defined(PERI_XBARB_H_)
#define PERI_XBARB_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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
    kXBARA_InputVss                 = 0|0x100U,    /**< VSS output assigned to XBARA_IN0 input. */
    kXBARA_InputVdd                 = 1|0x100U,    /**< VDD output assigned to XBARA_IN1 input. */
    kXBARA_InputXbIn2               = 2|0x100U,    /**< XB_IN2 output assigned to XBARA_IN2 input. */
    kXBARA_InputXbIn3               = 3|0x100U,    /**< XB_IN3 output assigned to XBARA_IN3 input. */
    kXBARA_InputXbIn4               = 4|0x100U,    /**< XB_IN4 output assigned to XBARA_IN4 input. */
    kXBARA_InputXbIn5               = 5|0x100U,    /**< XB_IN5 output assigned to XBARA_IN5 input. */
    kXBARA_InputXbIn6               = 6|0x100U,    /**< XB_IN6 output assigned to XBARA_IN6 input. */
    kXBARA_InputXbIn7               = 7|0x100U,    /**< XB_IN7 output assigned to XBARA_IN7 input. */
    kXBARA_InputXbIn8               = 8|0x100U,    /**< XB_IN8 output assigned to XBARA_IN8 input. */
    kXBARA_InputXbIn9               = 9|0x100U,    /**< XB_IN9 output assigned to XBARA_IN9 input. */
    kXBARA_InputXbIn10              = 10|0x100U,   /**< XB_IN10 output assigned to XBARA_IN10 input. */
    kXBARA_InputXbIn11              = 11|0x100U,   /**< XB_IN11 output assigned to XBARA_IN11 input. */
    kXBARA_InputCmpaOut             = 12|0x100U,   /**< CMPA_OUT output assigned to XBARA_IN12 input. */
    kXBARA_InputCmpbOut             = 13|0x100U,   /**< CMPB_OUT output assigned to XBARA_IN13 input. */
    kXBARA_InputCmpcOut             = 14|0x100U,   /**< CMPC_OUT output assigned to XBARA_IN14 input. */
    kXBARA_InputCmpdOut             = 15|0x100U,   /**< CMPD_OUT output assigned to XBARA_IN15 input. */
    kXBARA_InputTb0Out              = 16|0x100U,   /**< TB0_OUT output assigned to XBARA_IN16 input. */
    kXBARA_InputTb1Out              = 17|0x100U,   /**< TB1_OUT output assigned to XBARA_IN17 input. */
    kXBARA_InputTb2Out              = 18|0x100U,   /**< TB2_OUT output assigned to XBARA_IN18 input. */
    kXBARA_InputTb3Out              = 19|0x100U,   /**< TB3_OUT output assigned to XBARA_IN19 input. */
    kXBARA_InputPwma0OutTrig0       = 20|0x100U,   /**< PWMA0_OUT_TRIG0 output assigned to XBARA_IN20 input. */
    kXBARA_InputPwma0OutTrig1       = 21|0x100U,   /**< PWMA0_OUT_TRIG1 output assigned to XBARA_IN21 input. */
    kXBARA_InputPwma1OutTrig0       = 22|0x100U,   /**< PWMA1_OUT_TRIG0 output assigned to XBARA_IN22 input. */
    kXBARA_InputPwma1OutTrig1       = 23|0x100U,   /**< PWMA1_OUT_TRIG1 output assigned to XBARA_IN23 input. */
    kXBARA_InputPwma2OutTrig0       = 24|0x100U,   /**< PWMA2_OUT_TRIG0 output assigned to XBARA_IN24 input. */
    kXBARA_InputPwma2OutTrig1       = 25|0x100U,   /**< PWMA2_OUT_TRIG1 output assigned to XBARA_IN25 input. */
    kXBARA_InputPwma3OutTrig0       = 26|0x100U,   /**< PWMA3_OUT_TRIG0 output assigned to XBARA_IN26 input. */
    kXBARA_InputPwma3OutTrig1       = 27|0x100U,   /**< PWMA3_OUT_TRIG1 output assigned to XBARA_IN27 input. */
    kXBARA_InputPdb0OutA            = 28|0x100U,   /**< PDB0_OUT_A output assigned to XBARA_IN28 input. */
    kXBARA_InputPdb0OutB            = 29|0x100U,   /**< PDB0_OUT_B output assigned to XBARA_IN29 input. */
    kXBARA_InputPdb0OutC            = 30|0x100U,   /**< PDB0_OUT_C output assigned to XBARA_IN30 input. */
    kXBARA_InputPdb0OutD            = 31|0x100U,   /**< PDB0_OUT_D output assigned to XBARA_IN31 input. */
    kXBARA_InputPdb1OutA            = 32|0x100U,   /**< PDB1_OUT_A output assigned to XBARA_IN32 input. */
    kXBARA_InputPdb1OutB            = 33|0x100U,   /**< PDB1_OUT_B output assigned to XBARA_IN33 input. */
    kXBARA_InputPdb1OutC            = 34|0x100U,   /**< PDB1_OUT_C output assigned to XBARA_IN34 input. */
    kXBARA_InputPdb1OutD            = 35|0x100U,   /**< PDB1_OUT_D output assigned to XBARA_IN35 input. */
    kXBARA_InputTa0Out              = 36|0x100U,   /**< TA0_OUT output assigned to XBARA_IN36 input. */
    kXBARA_InputTa1Out              = 37|0x100U,   /**< TA1_OUT output assigned to XBARA_IN37 input. */
    kXBARA_InputTa2Out              = 38|0x100U,   /**< TA2_OUT output assigned to XBARA_IN38 input. */
    kXBARA_InputTa3Out              = 39|0x100U,   /**< TA3_OUT output assigned to XBARA_IN39 input. */
    kXBARA_InputPwmb0OutTrig0Pwmb0OutTrig1 = 40|0x100U, /**< PWMB0_OUT_TRIG0_PWMB0_OUT_TRIG1 output assigned to XBARA_IN40 input. */
    kXBARA_InputPwmb1OutTrig0Pwmb1OutTrig1 = 41|0x100U, /**< PWMB1_OUT_TRIG0_PWMB1_OUT_TRIG1 output assigned to XBARA_IN41 input. */
    kXBARA_InputPwmb2OutTrig0Pwmb2OutTrig1 = 42|0x100U, /**< PWMB2_OUT_TRIG0_PWMB2_OUT_TRIG1 output assigned to XBARA_IN42 input. */
    kXBARA_InputPwmb3OutTrig0       = 43|0x100U,   /**< PWMB3_OUT_TRIG0 output assigned to XBARA_IN43 input. */
    kXBARA_InputPwmb3OutTrig1       = 44|0x100U,   /**< PWMB3_OUT_TRIG1 output assigned to XBARA_IN44 input. */
    kXBARA_InputQdcPosmatch         = 45|0x100U,   /**< QDC_POSMATCH output assigned to XBARA_IN45 input. */
    kXBARA_InputAndOrInvert0        = 46|0x100U,   /**< AND_OR_INVERT_0 output assigned to XBARA_IN46 input. */
    kXBARA_InputAndOrInvert1        = 47|0x100U,   /**< AND_OR_INVERT_1 output assigned to XBARA_IN47 input. */
    kXBARA_InputAndOrInvert2        = 48|0x100U,   /**< AND_OR_INVERT_2 output assigned to XBARA_IN48 input. */
    kXBARA_InputAndOrInvert3        = 49|0x100U,   /**< AND_OR_INVERT_3 output assigned to XBARA_IN49 input. */
    kXBARB_InputCmpaOut             = 0|0x200U,    /**< CMPA_OUT output assigned to XBARB_IN0 input. */
    kXBARB_InputCmpbOut             = 1|0x200U,    /**< CMPB_OUT output assigned to XBARB_IN1 input. */
    kXBARB_InputCmpcOut             = 2|0x200U,    /**< CMPC_OUT output assigned to XBARB_IN2 input. */
    kXBARB_InputCmpdOut             = 3|0x200U,    /**< CMPD_OUT output assigned to XBARB_IN3 input. */
    kXBARB_InputTb0Out              = 4|0x200U,    /**< TB0_OUT output assigned to XBARB_IN4 input. */
    kXBARB_InputTb1Out              = 5|0x200U,    /**< TB1_OUT output assigned to XBARB_IN5 input. */
    kXBARB_InputTb2Out              = 6|0x200U,    /**< TB2_OUT output assigned to XBARB_IN6 input. */
    kXBARB_InputTb3Out              = 7|0x200U,    /**< TB3_OUT output assigned to XBARB_IN7 input. */
    kXBARB_InputPwma0OutTrig0Pwma0OutTrig1 = 8|0x200U, /**< PWMA0_OUT_TRIG0_PWMA0_OUT_TRIG1 output assigned to XBARB_IN8 input. */
    kXBARB_InputPwma1OutTrig0Pwma1OutTrig1 = 9|0x200U, /**< PWMA1_OUT_TRIG0_PWMA1_OUT_TRIG1 output assigned to XBARB_IN9 input. */
    kXBARB_InputPwma2OutTrig0Pwma2OutTrig1 = 10|0x200U, /**< PWMA2_OUT_TRIG0_PWMA2_OUT_TRIG1 output assigned to XBARB_IN10 input. */
    kXBARB_InputPwma3OutTrig0Pwma3OutTrig1 = 11|0x200U, /**< PWMA3_OUT_TRIG0_PWMA3_OUT_TRIG1 output assigned to XBARB_IN11 input. */
    kXBARB_InputPdb0OutBPdb0OutD    = 12|0x200U,   /**< PDB0_OUT_B_PDB0_OUT_D output assigned to XBARB_IN12 input. */
    kXBARB_InputPdb1OutBPdb1OutD    = 13|0x200U,   /**< PDB1_OUT_B_PDB1_OUT_D output assigned to XBARB_IN13 input. */
    kXBARB_InputXbIn2               = 14|0x200U,   /**< XB_IN2 output assigned to XBARB_IN14 input. */
    kXBARB_InputXbIn3               = 15|0x200U,   /**< XB_IN3 output assigned to XBARB_IN15 input. */
    kXBARB_InputTa0Out              = 16|0x200U,   /**< TA0_OUT output assigned to XBARB_IN16 input. */
    kXBARB_InputTa1Out              = 17|0x200U,   /**< TA1_OUT output assigned to XBARB_IN17 input. */
    kXBARB_InputTa2Out              = 18|0x200U,   /**< TA2_OUT output assigned to XBARB_IN18 input. */
    kXBARB_InputTa3Out              = 19|0x200U,   /**< TA3_OUT output assigned to XBARB_IN19 input. */
    kXBARB_InputXbIn10              = 20|0x200U,   /**< XB_IN10 output assigned to XBARB_IN20 input. */
    kXBARB_InputXbIn11              = 21|0x200U,   /**< XB_IN11 output assigned to XBARB_IN21 input. */
    kXBARB_InputPwmb0OutTrig0Pwmb0OutTrig1 = 22|0x200U, /**< PWMB0_OUT_TRIG0_PWMB0_OUT_TRIG1 output assigned to XBARB_IN22 input. */
    kXBARB_InputPwmb1OutTrig0Pwmb1OutTrig1 = 23|0x200U, /**< PWMB1_OUT_TRIG0_PWMB1_OUT_TRIG1 output assigned to XBARB_IN23 input. */
    kXBARB_InputPwmb2OutTrig0Pwmb2OutTrig1 = 24|0x200U, /**< PWMB2_OUT_TRIG0_PWMB2_OUT_TRIG1 output assigned to XBARB_IN24 input. */
    kXBARB_InputPwmb3OutTrig0Pwmb3OutTrig1 = 25|0x200U, /**< PWMB3_OUT_TRIG0_PWMB3_OUT_TRIG1 output assigned to XBARB_IN25 input. */
} xbar_input_signal_t;
#endif /* XBAR_INPUT_SIGNAL_T_ */

#if !defined(XBAR_OUTPUT_SIGNAL_T_)
#define XBAR_OUTPUT_SIGNAL_T_
typedef enum _xbar_output_signal
{
    kXBARA_OutputDmaReq0            = 0|0x100U,    /**< XBARA_OUT0 output assigned to DMA_REQ0 */
    kXBARA_OutputDmaReq1            = 1|0x100U,    /**< XBARA_OUT1 output assigned to DMA_REQ1 */
    kXBARA_OutputDmaReq2            = 2|0x100U,    /**< XBARA_OUT2 output assigned to DMA_REQ2 */
    kXBARA_OutputDmaReq3            = 3|0x100U,    /**< XBARA_OUT3 output assigned to DMA_REQ3 */
    kXBARA_OutputXbOut4             = 4|0x100U,    /**< XBARA_OUT4 output assigned to XB_OUT4 */
    kXBARA_OutputXbOut5             = 5|0x100U,    /**< XBARA_OUT5 output assigned to XB_OUT5 */
    kXBARA_OutputXbOut6             = 6|0x100U,    /**< XBARA_OUT6 output assigned to XB_OUT6 */
    kXBARA_OutputXbOut7             = 7|0x100U,    /**< XBARA_OUT7 output assigned to XB_OUT7 */
    kXBARA_OutputXbOut8             = 8|0x100U,    /**< XBARA_OUT8 output assigned to XB_OUT8 */
    kXBARA_OutputXbOut9             = 9|0x100U,    /**< XBARA_OUT9 output assigned to XB_OUT9 */
    kXBARA_OutputXbOut10            = 10|0x100U,   /**< XBARA_OUT10 output assigned to XB_OUT10 */
    kXBARA_OutputXbOut11            = 11|0x100U,   /**< XBARA_OUT11 output assigned to XB_OUT11 */
    kXBARA_OutputAdcaSync           = 12|0x100U,   /**< XBARA_OUT12 output assigned to ADCA_SYNC */
    kXBARA_OutputAdcbSync           = 13|0x100U,   /**< XBARA_OUT13 output assigned to ADCB_SYNC */
    kXBARA_OutputAdccTrg            = 14|0x100U,   /**< XBARA_OUT14 output assigned to ADCC_TRG */
    kXBARA_OutputDac12bSync         = 15|0x100U,   /**< XBARA_OUT15 output assigned to DAC_12B_SYNC */
    kXBARA_OutputCmpa               = 16|0x100U,   /**< XBARA_OUT16 output assigned to CMPA */
    kXBARA_OutputCmpb               = 17|0x100U,   /**< XBARA_OUT17 output assigned to CMPB */
    kXBARA_OutputCmpc               = 18|0x100U,   /**< XBARA_OUT18 output assigned to CMPC */
    kXBARA_OutputCmpd               = 19|0x100U,   /**< XBARA_OUT19 output assigned to CMPD */
    kXBARA_OutputPwma0Pwmb0Exta     = 20|0x100U,   /**< XBARA_OUT20 output assigned to PWMA0_PWMB0_EXTA */
    kXBARA_OutputPwma1Pwmb1Exta     = 21|0x100U,   /**< XBARA_OUT21 output assigned to PWMA1_PWMB1_EXTA */
    kXBARA_OutputPwma2Pwmb2Exta     = 22|0x100U,   /**< XBARA_OUT22 output assigned to PWMA2_PWMB2_EXTA */
    kXBARA_OutputPwma3Pwmb3Exta     = 23|0x100U,   /**< XBARA_OUT23 output assigned to PWMA3_PWMB3_EXTA */
    kXBARA_OutputPwma0ExtSync       = 24|0x100U,   /**< XBARA_OUT24 output assigned to PWMA0_EXT_SYNC */
    kXBARA_OutputPwma1ExtSync       = 25|0x100U,   /**< XBARA_OUT25 output assigned to PWMA1_EXT_SYNC */
    kXBARA_OutputPwma2ExtSync       = 26|0x100U,   /**< XBARA_OUT26 output assigned to PWMA2_EXT_SYNC */
    kXBARA_OutputPwma3ExtSync       = 27|0x100U,   /**< XBARA_OUT27 output assigned to PWMA3_EXT_SYNC */
    kXBARA_OutputPwmaPwmbExtClk     = 28|0x100U,   /**< XBARA_OUT28 output assigned to PWMA_PWMB_EXT_CLK */
    kXBARA_OutputPwmaPwmbFault0     = 29|0x100U,   /**< XBARA_OUT29 output assigned to PWMA_PWMB_FAULT0 */
    kXBARA_OutputPwmaPwmbFault1     = 30|0x100U,   /**< XBARA_OUT30 output assigned to PWMA_PWMB_FAULT1 */
    kXBARA_OutputPwmaPwmbFault2     = 31|0x100U,   /**< XBARA_OUT31 output assigned to PWMA_PWMB_FAULT2 */
    kXBARA_OutputPwmaPwmbFault3     = 32|0x100U,   /**< XBARA_OUT32 output assigned to PWMA_PWMB_FAULT3 */
    kXBARA_OutputPwmaForce          = 33|0x100U,   /**< XBARA_OUT33 output assigned to PWMA_FORCE */
    kXBARA_OutputTb0In              = 34|0x100U,   /**< XBARA_OUT34 output assigned to TB0_IN */
    kXBARA_OutputTb1In              = 35|0x100U,   /**< XBARA_OUT35 output assigned to TB1_IN */
    kXBARA_OutputTb2In              = 36|0x100U,   /**< XBARA_OUT36 output assigned to TB2_IN */
    kXBARA_OutputTb3In              = 37|0x100U,   /**< XBARA_OUT37 output assigned to TB3_IN */
    kXBARA_OutputPdb0InTrig0        = 38|0x100U,   /**< XBARA_OUT38 output assigned to PDB0_IN_TRIG0 */
    kXBARA_OutputPdb0Faulta         = 39|0x100U,   /**< XBARA_OUT39 output assigned to PDB0_FAULTA */
    kXBARA_OutputPdb0Faultc         = 40|0x100U,   /**< XBARA_OUT40 output assigned to PDB0_FAULTC */
    kXBARA_OutputPdb1InTrig0        = 41|0x100U,   /**< XBARA_OUT41 output assigned to PDB1_IN_TRIG0 */
    kXBARA_OutputPdb1Faulta         = 42|0x100U,   /**< XBARA_OUT42 output assigned to PDB1_FAULTA */
    kXBARA_OutputPdb1Faultc         = 43|0x100U,   /**< XBARA_OUT43 output assigned to PDB1_FAULTC */
    kXBARA_OutputQdcPha             = 44|0x100U,   /**< XBARA_OUT44 output assigned to QDC_PHA */
    kXBARA_OutputQdcPhb             = 45|0x100U,   /**< XBARA_OUT45 output assigned to QDC_PHB */
    kXBARA_OutputQdcIndex           = 46|0x100U,   /**< XBARA_OUT46 output assigned to QDC_INDEX */
    kXBARA_OutputQdcHome            = 47|0x100U,   /**< XBARA_OUT47 output assigned to QDC_HOME */
    kXBARA_OutputQdcTrig            = 48|0x100U,   /**< XBARA_OUT48 output assigned to QDC_TRIG */
    kXBARA_OutputTa0In              = 49|0x100U,   /**< XBARA_OUT49 output assigned to TA0_IN */
    kXBARA_OutputTa1In              = 50|0x100U,   /**< XBARA_OUT50 output assigned to TA1_IN */
    kXBARA_OutputTa2In              = 51|0x100U,   /**< XBARA_OUT51 output assigned to TA2_IN */
    kXBARA_OutputTa3In              = 52|0x100U,   /**< XBARA_OUT52 output assigned to TA3_IN */
    kXBARA_OutputPwmb0ExtSync       = 53|0x100U,   /**< XBARA_OUT53 output assigned to PWMB0_EXT_SYNC */
    kXBARA_OutputPwmb1ExtSync       = 54|0x100U,   /**< XBARA_OUT54 output assigned to PWMB1_EXT_SYNC */
    kXBARA_OutputPwmb2ExtSync       = 55|0x100U,   /**< XBARA_OUT55 output assigned to PWMB2_EXT_SYNC */
    kXBARA_OutputPwmb3ExtSync       = 56|0x100U,   /**< XBARA_OUT56 output assigned to PWMB3_EXT_SYNC */
    kXBARA_OutputPwmbForce          = 57|0x100U,   /**< XBARA_OUT57 output assigned to PWMB_FORCE */
    kXBARA_OutputEwmIn              = 58|0x100U,   /**< XBARA_OUT58 output assigned to EWM_IN */
    kXBARB_OutputAoiA0              = 0|0x200U,    /**< XBARB_OUT0 output assigned to AOI_A0 */
    kXBARB_OutputAoiB0              = 1|0x200U,    /**< XBARB_OUT1 output assigned to AOI_B0 */
    kXBARB_OutputAoiC0              = 2|0x200U,    /**< XBARB_OUT2 output assigned to AOI_C0 */
    kXBARB_OutputAoiD0              = 3|0x200U,    /**< XBARB_OUT3 output assigned to AOI_D0 */
    kXBARB_OutputAoiA1              = 4|0x200U,    /**< XBARB_OUT4 output assigned to AOI_A1 */
    kXBARB_OutputAoiB1              = 5|0x200U,    /**< XBARB_OUT5 output assigned to AOI_B1 */
    kXBARB_OutputAoiC1              = 6|0x200U,    /**< XBARB_OUT6 output assigned to AOI_C1 */
    kXBARB_OutputAoiD1              = 7|0x200U,    /**< XBARB_OUT7 output assigned to AOI_D1 */
    kXBARB_OutputAoiA2              = 8|0x200U,    /**< XBARB_OUT8 output assigned to AOI_A2 */
    kXBARB_OutputAoiB2              = 9|0x200U,    /**< XBARB_OUT9 output assigned to AOI_B2 */
    kXBARB_OutputAoiC2              = 10|0x200U,   /**< XBARB_OUT10 output assigned to AOI_C2 */
    kXBARB_OutputAoiD2              = 11|0x200U,   /**< XBARB_OUT11 output assigned to AOI_D2 */
    kXBARB_OutputAoiA3              = 12|0x200U,   /**< XBARB_OUT12 output assigned to AOI_A3 */
    kXBARB_OutputAoiB3              = 13|0x200U,   /**< XBARB_OUT13 output assigned to AOI_B3 */
    kXBARB_OutputAoiC3              = 14|0x200U,   /**< XBARB_OUT14 output assigned to AOI_C3 */
    kXBARB_OutputAoiD3              = 15|0x200U,   /**< XBARB_OUT15 output assigned to AOI_D3 */
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
   -- XBARB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Peripheral_Access_Layer XBARB Peripheral Access Layer
 * @{
 */

/** XBARB - Register Layout Typedef */
typedef struct {
  __IO uint16_t SEL0;                              /**< Crossbar B Select Register 0, offset: 0x0 */
  __IO uint16_t SEL1;                              /**< Crossbar B Select Register 1, offset: 0x1 */
  __IO uint16_t SEL2;                              /**< Crossbar B Select Register 2, offset: 0x2 */
  __IO uint16_t SEL3;                              /**< Crossbar B Select Register 3, offset: 0x3 */
  __IO uint16_t SEL4;                              /**< Crossbar B Select Register 4, offset: 0x4 */
  __IO uint16_t SEL5;                              /**< Crossbar B Select Register 5, offset: 0x5 */
  __IO uint16_t SEL6;                              /**< Crossbar B Select Register 6, offset: 0x6 */
  __IO uint16_t SEL7;                              /**< Crossbar B Select Register 7, offset: 0x7 */
} XBARB_Type;

/* ----------------------------------------------------------------------------
   -- XBARB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XBARB_Register_Masks XBARB Register Masks
 * @{
 */

/*! @name SEL0 - Crossbar B Select Register 0 */
/*! @{ */

#define XBARB_SEL0_SEL0_MASK                     (0x1FU)
#define XBARB_SEL0_SEL0_SHIFT                    (0U)
#define XBARB_SEL0_SEL0(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL0_SEL0_SHIFT)) & XBARB_SEL0_SEL0_MASK)

#define XBARB_SEL0_SEL1_MASK                     (0x1F00U)
#define XBARB_SEL0_SEL1_SHIFT                    (8U)
#define XBARB_SEL0_SEL1(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL0_SEL1_SHIFT)) & XBARB_SEL0_SEL1_MASK)
/*! @} */

/*! @name SEL1 - Crossbar B Select Register 1 */
/*! @{ */

#define XBARB_SEL1_SEL2_MASK                     (0x1FU)
#define XBARB_SEL1_SEL2_SHIFT                    (0U)
#define XBARB_SEL1_SEL2(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL1_SEL2_SHIFT)) & XBARB_SEL1_SEL2_MASK)

#define XBARB_SEL1_SEL3_MASK                     (0x1F00U)
#define XBARB_SEL1_SEL3_SHIFT                    (8U)
#define XBARB_SEL1_SEL3(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL1_SEL3_SHIFT)) & XBARB_SEL1_SEL3_MASK)
/*! @} */

/*! @name SEL2 - Crossbar B Select Register 2 */
/*! @{ */

#define XBARB_SEL2_SEL4_MASK                     (0x1FU)
#define XBARB_SEL2_SEL4_SHIFT                    (0U)
#define XBARB_SEL2_SEL4(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL2_SEL4_SHIFT)) & XBARB_SEL2_SEL4_MASK)

#define XBARB_SEL2_SEL5_MASK                     (0x1F00U)
#define XBARB_SEL2_SEL5_SHIFT                    (8U)
#define XBARB_SEL2_SEL5(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL2_SEL5_SHIFT)) & XBARB_SEL2_SEL5_MASK)
/*! @} */

/*! @name SEL3 - Crossbar B Select Register 3 */
/*! @{ */

#define XBARB_SEL3_SEL6_MASK                     (0x1FU)
#define XBARB_SEL3_SEL6_SHIFT                    (0U)
#define XBARB_SEL3_SEL6(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL3_SEL6_SHIFT)) & XBARB_SEL3_SEL6_MASK)

#define XBARB_SEL3_SEL7_MASK                     (0x1F00U)
#define XBARB_SEL3_SEL7_SHIFT                    (8U)
#define XBARB_SEL3_SEL7(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL3_SEL7_SHIFT)) & XBARB_SEL3_SEL7_MASK)
/*! @} */

/*! @name SEL4 - Crossbar B Select Register 4 */
/*! @{ */

#define XBARB_SEL4_SEL8_MASK                     (0x1FU)
#define XBARB_SEL4_SEL8_SHIFT                    (0U)
#define XBARB_SEL4_SEL8(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL4_SEL8_SHIFT)) & XBARB_SEL4_SEL8_MASK)

#define XBARB_SEL4_SEL9_MASK                     (0x1F00U)
#define XBARB_SEL4_SEL9_SHIFT                    (8U)
#define XBARB_SEL4_SEL9(x)                       (((uint16_t)(((uint16_t)(x)) << XBARB_SEL4_SEL9_SHIFT)) & XBARB_SEL4_SEL9_MASK)
/*! @} */

/*! @name SEL5 - Crossbar B Select Register 5 */
/*! @{ */

#define XBARB_SEL5_SEL10_MASK                    (0x1FU)
#define XBARB_SEL5_SEL10_SHIFT                   (0U)
#define XBARB_SEL5_SEL10(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL5_SEL10_SHIFT)) & XBARB_SEL5_SEL10_MASK)

#define XBARB_SEL5_SEL11_MASK                    (0x1F00U)
#define XBARB_SEL5_SEL11_SHIFT                   (8U)
#define XBARB_SEL5_SEL11(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL5_SEL11_SHIFT)) & XBARB_SEL5_SEL11_MASK)
/*! @} */

/*! @name SEL6 - Crossbar B Select Register 6 */
/*! @{ */

#define XBARB_SEL6_SEL12_MASK                    (0x1FU)
#define XBARB_SEL6_SEL12_SHIFT                   (0U)
#define XBARB_SEL6_SEL12(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL6_SEL12_SHIFT)) & XBARB_SEL6_SEL12_MASK)

#define XBARB_SEL6_SEL13_MASK                    (0x1F00U)
#define XBARB_SEL6_SEL13_SHIFT                   (8U)
#define XBARB_SEL6_SEL13(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL6_SEL13_SHIFT)) & XBARB_SEL6_SEL13_MASK)
/*! @} */

/*! @name SEL7 - Crossbar B Select Register 7 */
/*! @{ */

#define XBARB_SEL7_SEL14_MASK                    (0x1FU)
#define XBARB_SEL7_SEL14_SHIFT                   (0U)
#define XBARB_SEL7_SEL14(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL7_SEL14_SHIFT)) & XBARB_SEL7_SEL14_MASK)

#define XBARB_SEL7_SEL15_MASK                    (0x1F00U)
#define XBARB_SEL7_SEL15_SHIFT                   (8U)
#define XBARB_SEL7_SEL15(x)                      (((uint16_t)(((uint16_t)(x)) << XBARB_SEL7_SEL15_SHIFT)) & XBARB_SEL7_SEL15_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XBARB_Register_Masks */


/*!
 * @}
 */ /* end of group XBARB_Peripheral_Access_Layer */


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


#endif  /* PERI_XBARB_H_ */

