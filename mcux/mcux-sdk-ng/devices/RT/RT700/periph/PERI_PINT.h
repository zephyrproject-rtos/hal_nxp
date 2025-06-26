/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 2.0, 2024-05-28
**     Build:               b241121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PINT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**
** ###################################################################
*/

/*!
 * @file PINT.h
 * @version 2.0
 * @date 2024-05-28
 * @brief CMSIS Peripheral Access Layer for PINT
 *
 * CMSIS Peripheral Access Layer for PINT
 */

#if !defined(PINT_H_)
#define PINT_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- PINT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Peripheral_Access_Layer PINT Peripheral Access Layer
 * @{
 */

/** PINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISEL;                              /**< Pin Interrupt Mode, offset: 0x0 */
  __IO uint32_t IENR;                              /**< Pin Interrupt Level or Rising-Edge Interrupt Enable, offset: 0x4 */
  __IO uint32_t SIENR;                             /**< Pin Interrupt Level or Rising-Edge Interrupt Set, offset: 0x8 */
  __IO uint32_t CIENR;                             /**< Pin Interrupt Level (Rising-Edge Interrupt) Clear, offset: 0xC */
  __IO uint32_t IENF;                              /**< Pin Interrupt Active Level or Falling-Edge Interrupt Enable, offset: 0x10 */
  __IO uint32_t SIENF;                             /**< Pin Interrupt Active Level or Falling-Edge Interrupt Set, offset: 0x14 */
  __IO uint32_t CIENF;                             /**< Pin Interrupt Active Level or Falling-Edge Interrupt Clear, offset: 0x18 */
  __IO uint32_t RISE;                              /**< Pin Interrupt Rising Edge, offset: 0x1C */
  __IO uint32_t FALL;                              /**< Pin Interrupt Falling Edge, offset: 0x20 */
  __IO uint32_t IST;                               /**< Pin Interrupt Status, offset: 0x24 */
  __IO uint32_t PMCTRL;                            /**< Pattern-Match Interrupt Control, offset: 0x28 */
  __IO uint32_t PMSRC;                             /**< Pattern-Match Interrupt Bit-Slice Source, offset: 0x2C */
  __IO uint32_t PMCFG;                             /**< Pattern-Match Interrupt Bit Slice Configuration, offset: 0x30 */
} PINT_Type;

/* ----------------------------------------------------------------------------
   -- PINT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Register_Masks PINT Register Masks
 * @{
 */

/*! @name ISEL - Pin Interrupt Mode */
/*! @{ */

#define PINT_ISEL_PMODE_MASK                     (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_ISEL_PMODE_SHIFT                    (0U)
/*! PMODE - Interrupt mode
 *  0b00000000..In bit n configures the interrupt to be edge-sensitive
 *  0b00000001..In bit n configures the interrupt to be level-sensitive
 */
#define PINT_ISEL_PMODE(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_ISEL_PMODE_SHIFT)) & PINT_ISEL_PMODE_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name IENR - Pin Interrupt Level or Rising-Edge Interrupt Enable */
/*! @{ */

#define PINT_IENR_ENRL_MASK                      (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_IENR_ENRL_SHIFT                     (0U)
/*! ENRL - Enables Interrupt
 *  0b00000000..In bit n disables the corresponding interrupt
 *  0b00000001..In bit n enables the corresponding interrupt
 */
#define PINT_IENR_ENRL(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENR_ENRL_SHIFT)) & PINT_IENR_ENRL_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name SIENR - Pin Interrupt Level or Rising-Edge Interrupt Set */
/*! @{ */

#define PINT_SIENR_SETENRL_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_SIENR_SETENRL_SHIFT                 (0U)
/*! SETENRL - Configures IENR
 *  0b00000000..No operation for interrupt n
 *  0b00000001..Enable rising edge or level interrupt for interrupt n
 */
#define PINT_SIENR_SETENRL(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENR_SETENRL_SHIFT)) & PINT_SIENR_SETENRL_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name CIENR - Pin Interrupt Level (Rising-Edge Interrupt) Clear */
/*! @{ */

#define PINT_CIENR_CENRL_MASK                    (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_CIENR_CENRL_SHIFT                   (0U)
/*! CENRL - Clear bits in IENR
 *  0b00000000..No operation
 *  0b00000001..Disable rising edge or level interrupt
 */
#define PINT_CIENR_CENRL(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENR_CENRL_SHIFT)) & PINT_CIENR_CENRL_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name IENF - Pin Interrupt Active Level or Falling-Edge Interrupt Enable */
/*! @{ */

#define PINT_IENF_ENAF_MASK                      (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_IENF_ENAF_SHIFT                     (0U)
/*! ENAF - Enables Interrupt
 *  0b00000000..Disable (set active interrupt level LOW)
 *  0b00000001..Enable (set active interrupt level HIGH)
 */
#define PINT_IENF_ENAF(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENF_ENAF_SHIFT)) & PINT_IENF_ENAF_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name SIENF - Pin Interrupt Active Level or Falling-Edge Interrupt Set */
/*! @{ */

#define PINT_SIENF_SETENAF_MASK                  (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_SIENF_SETENAF_SHIFT                 (0U)
/*! SETENAF
 *  0b00000000..Writes 0 to IENF.
 *  0b00000001..Select HIGH-active interrupt or enable falling-edge interrupt
 */
#define PINT_SIENF_SETENAF(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENF_SETENAF_SHIFT)) & PINT_SIENF_SETENAF_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name CIENF - Pin Interrupt Active Level or Falling-Edge Interrupt Clear */
/*! @{ */

#define PINT_CIENF_CENAF_MASK                    (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_CIENF_CENAF_SHIFT                   (0U)
/*! CENAF - Writes 0 to IENF
 *  0b00000000..No operation
 *  0b00000001..LOW-active interrupt selected or falling-edge interrupt disabled
 */
#define PINT_CIENF_CENAF(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENF_CENAF_SHIFT)) & PINT_CIENF_CENAF_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name RISE - Pin Interrupt Rising Edge */
/*! @{ */

#define PINT_RISE_RDET_MASK                      (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_RISE_RDET_SHIFT                     (0U)
/*! RDET - Rising-Edge Detect
 *  0b00000000..Read 0- No rising edge (since Reset or you wrote a 1 to this field last time), Write 0- No operation
 *  0b00000001..Read 1- Rising edge (since Reset or you wrote a 1 to this field last time), Write 1- Clear rising-edge detection for this pin
 */
#define PINT_RISE_RDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_RISE_RDET_SHIFT)) & PINT_RISE_RDET_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name FALL - Pin Interrupt Falling Edge */
/*! @{ */

#define PINT_FALL_FDET_MASK                      (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_FALL_FDET_SHIFT                     (0U)
/*! FDET - Falling-Edge Detect
 *  0b00000000..Read 0- No falling edge (since Reset or you wrote a 1 to this field last time), Write 0- No operation
 *  0b00000001..Read 1- Falling edge (since Reset or you wrote a 1 to this field last time), Write 1- Clear falling-edge detection for this bit
 */
#define PINT_FALL_FDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_FALL_FDET_SHIFT)) & PINT_FALL_FDET_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name IST - Pin Interrupt Status */
/*! @{ */

#define PINT_IST_PSTAT_MASK                      (0xFFU)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
#define PINT_IST_PSTAT_SHIFT                     (0U)
/*! PSTAT - Pin Interrupt Status
 *  0b00000000..Read 0- Interrupt is not requested, Write 0- No operation
 *  0b00000001..Read 1- Interrupt is requested, Write 1 (edge-sensitive)- clear rising- and falling-edge detection
 *              for this pin, Write 1 (level-sensitive)- switch the active level for this pin in
 */
#define PINT_IST_PSTAT(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IST_PSTAT_SHIFT)) & PINT_IST_PSTAT_MASK)  /* Merged from fields with different position or width, of widths (4, 8), largest definition used */
/*! @} */

/*! @name PMCTRL - Pattern-Match Interrupt Control */
/*! @{ */

#define PINT_PMCTRL_SEL_PMATCH_MASK              (0x1U)
#define PINT_PMCTRL_SEL_PMATCH_SHIFT             (0U)
/*! SEL_PMATCH - Specifies whether the pin interrupts are controlled by the pin interrupt function
 *    or by the pattern-match function. If this value is 0b, interrupts are driven in response to the
 *    standard pin interrupt function. If this value is 1b, interrupts are driven in response to
 *    pattern matches.
 *  0b0..Pin interrupt
 *  0b1..Pattern match
 */
#define PINT_PMCTRL_SEL_PMATCH(x)                (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_SEL_PMATCH_SHIFT)) & PINT_PMCTRL_SEL_PMATCH_MASK)

#define PINT_PMCTRL_ENA_RXEV_MASK                (0x2U)
#define PINT_PMCTRL_ENA_RXEV_SHIFT               (1U)
/*! ENA_RXEV - Enables the RXEV output to the CPU and/or to a GPIO output, when the specified
 *    Boolean expression evaluates to true. If this value is 0b, RXEV output to the CPU is disabled. If
 *    this value is 1b, RXEV output to the CPU is enabled.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PINT_PMCTRL_ENA_RXEV(x)                  (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_ENA_RXEV_SHIFT)) & PINT_PMCTRL_ENA_RXEV_MASK)

#define PINT_PMCTRL_PMAT_MASK                    (0xFF000000U)
#define PINT_PMCTRL_PMAT_SHIFT                   (24U)
/*! PMAT - Pattern Matches
 *  0b00000001..The corresponding product term is matched by the current state of the appropriate inputs
 */
#define PINT_PMCTRL_PMAT(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_PMAT_SHIFT)) & PINT_PMCTRL_PMAT_MASK)
/*! @} */

/*! @name PMSRC - Pattern-Match Interrupt Bit-Slice Source */
/*! @{ */

#define PINT_PMSRC_SRC0_MASK                     (0x700U)
#define PINT_PMSRC_SRC0_SHIFT                    (8U)
/*! SRC0 - Selects the input source for bit slice 0
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC0_SHIFT)) & PINT_PMSRC_SRC0_MASK)

#define PINT_PMSRC_SRC1_MASK                     (0x3800U)
#define PINT_PMSRC_SRC1_SHIFT                    (11U)
/*! SRC1 - Selects the input source for bit slice 1
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC1_SHIFT)) & PINT_PMSRC_SRC1_MASK)

#define PINT_PMSRC_SRC2_MASK                     (0x1C000U)
#define PINT_PMSRC_SRC2_SHIFT                    (14U)
/*! SRC2 - Selects the input source for bit slice 2
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC2_SHIFT)) & PINT_PMSRC_SRC2_MASK)

#define PINT_PMSRC_SRC3_MASK                     (0xE0000U)
#define PINT_PMSRC_SRC3_SHIFT                    (17U)
/*! SRC3 - Selects the input source for bit slice 3
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC3_SHIFT)) & PINT_PMSRC_SRC3_MASK)

#define PINT_PMSRC_SRC4_MASK                     (0x700000U)
#define PINT_PMSRC_SRC4_SHIFT                    (20U)
/*! SRC4 - Selects the input source for bit slice 4
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC4_SHIFT)) & PINT_PMSRC_SRC4_MASK)

#define PINT_PMSRC_SRC5_MASK                     (0x3800000U)
#define PINT_PMSRC_SRC5_SHIFT                    (23U)
/*! SRC5 - Selects the input source for bit slice 5
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC5_SHIFT)) & PINT_PMSRC_SRC5_MASK)

#define PINT_PMSRC_SRC6_MASK                     (0x1C000000U)
#define PINT_PMSRC_SRC6_SHIFT                    (26U)
/*! SRC6 - Selects the input source for bit slice 6
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC6_SHIFT)) & PINT_PMSRC_SRC6_MASK)

#define PINT_PMSRC_SRC7_MASK                     (0xE0000000U)
#define PINT_PMSRC_SRC7_SHIFT                    (29U)
/*! SRC7 - Selects the input source for bit slice 7
 *  0b000..Input 0 (selects the pin identified in PINT_TRIG0)
 *  0b001..Input 1 (selects the pin identified in PINT_TRIG1)
 *  0b010..Input 2 (selects the pin identified in PINT_TRIG2)
 *  0b011..Input 3 (selects the pin identified in PINT_TRIG3)
 *  0b100..Input 4 (selects the pin identified in PINT_TRIG4)
 *  0b101..Input 5 (selects the pin identified in PINT_TRIG5)
 *  0b110..Input 6 (selects the pin identified in PINT_TRIG6)
 *  0b111..Input 7 (selects the pin identified in PINT_TRIG7)
 */
#define PINT_PMSRC_SRC7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC7_SHIFT)) & PINT_PMSRC_SRC7_MASK)
/*! @} */

/*! @name PMCFG - Pattern-Match Interrupt Bit Slice Configuration */
/*! @{ */

#define PINT_PMCFG_PROD_ENDPTS0_MASK             (0x1U)
#define PINT_PMCFG_PROD_ENDPTS0_SHIFT            (0U)
/*! PROD_ENDPTS0 - Determines whether slice 0 is an endpoint. Slice 0 is not an endpoint. Slice 0 is
 *    the endpoint of a product term (minterm). Pin interrupt 0 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS0(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS0_SHIFT)) & PINT_PMCFG_PROD_ENDPTS0_MASK)

#define PINT_PMCFG_PROD_ENDPTS1_MASK             (0x2U)
#define PINT_PMCFG_PROD_ENDPTS1_SHIFT            (1U)
/*! PROD_ENDPTS1 - Determines whether slice 1 is an endpoint. Slice 1 is not an endpoint. Slice 1 is
 *    the endpoint of a product term (minterm). Pin interrupt 1 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS1(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS1_SHIFT)) & PINT_PMCFG_PROD_ENDPTS1_MASK)

#define PINT_PMCFG_PROD_ENDPTS2_MASK             (0x4U)
#define PINT_PMCFG_PROD_ENDPTS2_SHIFT            (2U)
/*! PROD_ENDPTS2 - Determines whether slice 2 is an endpoint. Slice 2 is not an endpoint. Slice 2 is
 *    the endpoint of a product term (minterm). Pin interrupt 2 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS2(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS2_SHIFT)) & PINT_PMCFG_PROD_ENDPTS2_MASK)

#define PINT_PMCFG_PROD_ENDPTS3_MASK             (0x8U)
#define PINT_PMCFG_PROD_ENDPTS3_SHIFT            (3U)
/*! PROD_ENDPTS3 - Determines whether slice 3 is an endpoint. Slice 3 is not an endpoint. Slice 3 is
 *    the endpoint of a product term (minterm). Pin interrupt 3 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS3(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS3_SHIFT)) & PINT_PMCFG_PROD_ENDPTS3_MASK)

#define PINT_PMCFG_PROD_ENDPTS4_MASK             (0x10U)
#define PINT_PMCFG_PROD_ENDPTS4_SHIFT            (4U)
/*! PROD_ENDPTS4 - Determines whether slice 4 is an endpoint. Slice 4 is not an endpoint. Slice 4 is
 *    the endpoint of a product term (minterm). Pin interrupt 4 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS4(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS4_SHIFT)) & PINT_PMCFG_PROD_ENDPTS4_MASK)

#define PINT_PMCFG_PROD_ENDPTS5_MASK             (0x20U)
#define PINT_PMCFG_PROD_ENDPTS5_SHIFT            (5U)
/*! PROD_ENDPTS5 - Determines whether slice 5 is an endpoint. Slice 5 is not an endpoint. Slice 5 is
 *    the endpoint of a product term (minterm). Pin interrupt 5 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS5(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS5_SHIFT)) & PINT_PMCFG_PROD_ENDPTS5_MASK)

#define PINT_PMCFG_PROD_ENDPTS6_MASK             (0x40U)
#define PINT_PMCFG_PROD_ENDPTS6_SHIFT            (6U)
/*! PROD_ENDPTS6 - Determines whether slice 6 is an endpoint. Slice 6 is not an endpoint. Slice 6 is
 *    the endpoint of a product term (minterm). Pin interrupt 6 in the NVIC is raised if the
 *    minterm evaluates as true.
 *  0b0..No effect
 *  0b1..Endpoint
 */
#define PINT_PMCFG_PROD_ENDPTS6(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS6_SHIFT)) & PINT_PMCFG_PROD_ENDPTS6_MASK)

#define PINT_PMCFG_CFG0_MASK                     (0x700U)
#define PINT_PMCFG_CFG0_SHIFT                    (8U)
/*! CFG0 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG0_SHIFT)) & PINT_PMCFG_CFG0_MASK)

#define PINT_PMCFG_CFG1_MASK                     (0x3800U)
#define PINT_PMCFG_CFG1_SHIFT                    (11U)
/*! CFG1 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG1_SHIFT)) & PINT_PMCFG_CFG1_MASK)

#define PINT_PMCFG_CFG2_MASK                     (0x1C000U)
#define PINT_PMCFG_CFG2_SHIFT                    (14U)
/*! CFG2 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG2_SHIFT)) & PINT_PMCFG_CFG2_MASK)

#define PINT_PMCFG_CFG3_MASK                     (0xE0000U)
#define PINT_PMCFG_CFG3_SHIFT                    (17U)
/*! CFG3 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG3_SHIFT)) & PINT_PMCFG_CFG3_MASK)

#define PINT_PMCFG_CFG4_MASK                     (0x700000U)
#define PINT_PMCFG_CFG4_SHIFT                    (20U)
/*! CFG4 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG4_SHIFT)) & PINT_PMCFG_CFG4_MASK)

#define PINT_PMCFG_CFG5_MASK                     (0x3800000U)
#define PINT_PMCFG_CFG5_SHIFT                    (23U)
/*! CFG5 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG5_SHIFT)) & PINT_PMCFG_CFG5_MASK)

#define PINT_PMCFG_CFG6_MASK                     (0x1C000000U)
#define PINT_PMCFG_CFG6_SHIFT                    (26U)
/*! CFG6 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG6_SHIFT)) & PINT_PMCFG_CFG6_MASK)

#define PINT_PMCFG_CFG7_MASK                     (0xE0000000U)
#define PINT_PMCFG_CFG7_SHIFT                    (29U)
/*! CFG7 - Match Configuration
 *  0b000..Constant HIGH
 *  0b001..Sticky rising edge
 *  0b010..Sticky falling edge
 *  0b011..Sticky rising or falling edge
 *  0b100..High level
 *  0b101..Low level
 *  0b110..Constant 0
 *  0b111..Event (Nonsticky rising or falling edge)
 */
#define PINT_PMCFG_CFG7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG7_SHIFT)) & PINT_PMCFG_CFG7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PINT_Register_Masks */


/*!
 * @}
 */ /* end of group PINT_Peripheral_Access_Layer */


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


#endif  /* PINT_H_ */

