/*
** ###################################################################
**     Processors:          MKW21D256VHA5
**                          MKW21D512VHA5
**                          MKW22D512VHA5
**                          MKW24D512VHA5
**
**     Version:             rev. 2.0, 2015-01-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-22)
**         Initial version.
**     - rev. 2.0 (2015-01-06)
**         update of SystemInit() imlementation
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Register accessor macros added to the memory map.
**         MCG - bit LOLS in MCG_S register renamed to LOLS0.
**         DAC0 registers removed.
**
** ###################################################################
*/

/*!
 * @file CMT.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for CMT
 *
 * CMSIS Peripheral Access Layer for CMT
 */

#if !defined(CMT_H_)
#define CMT_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5_COMMON.h"
#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5WS_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5WS_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5WS_COMMON.h"
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
   -- CMT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMT_Peripheral_Access_Layer CMT Peripheral Access Layer
 * @{
 */

/** CMT - Register Layout Typedef */
typedef struct {
  __IO uint8_t CGH1;                               /**< CMT Carrier Generator High Data Register 1, offset: 0x0 */
  __IO uint8_t CGL1;                               /**< CMT Carrier Generator Low Data Register 1, offset: 0x1 */
  __IO uint8_t CGH2;                               /**< CMT Carrier Generator High Data Register 2, offset: 0x2 */
  __IO uint8_t CGL2;                               /**< CMT Carrier Generator Low Data Register 2, offset: 0x3 */
  __IO uint8_t OC;                                 /**< CMT Output Control Register, offset: 0x4 */
  __IO uint8_t MSC;                                /**< CMT Modulator Status and Control Register, offset: 0x5 */
  __IO uint8_t CMD1;                               /**< CMT Modulator Data Register Mark High, offset: 0x6 */
  __IO uint8_t CMD2;                               /**< CMT Modulator Data Register Mark Low, offset: 0x7 */
  __IO uint8_t CMD3;                               /**< CMT Modulator Data Register Space High, offset: 0x8 */
  __IO uint8_t CMD4;                               /**< CMT Modulator Data Register Space Low, offset: 0x9 */
  __IO uint8_t PPS;                                /**< CMT Primary Prescaler Register, offset: 0xA */
  __IO uint8_t DMA;                                /**< CMT Direct Memory Access Register, offset: 0xB */
} CMT_Type;

/* ----------------------------------------------------------------------------
   -- CMT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMT_Register_Masks CMT Register Masks
 * @{
 */

/*! @name CGH1 - CMT Carrier Generator High Data Register 1 */
/*! @{ */

#define CMT_CGH1_PH_MASK                         (0xFFU)
#define CMT_CGH1_PH_SHIFT                        (0U)
/*! PH - Primary Carrier High Time Data Value */
#define CMT_CGH1_PH(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CGH1_PH_SHIFT)) & CMT_CGH1_PH_MASK)
/*! @} */

/*! @name CGL1 - CMT Carrier Generator Low Data Register 1 */
/*! @{ */

#define CMT_CGL1_PL_MASK                         (0xFFU)
#define CMT_CGL1_PL_SHIFT                        (0U)
/*! PL - Primary Carrier Low Time Data Value */
#define CMT_CGL1_PL(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CGL1_PL_SHIFT)) & CMT_CGL1_PL_MASK)
/*! @} */

/*! @name CGH2 - CMT Carrier Generator High Data Register 2 */
/*! @{ */

#define CMT_CGH2_SH_MASK                         (0xFFU)
#define CMT_CGH2_SH_SHIFT                        (0U)
/*! SH - Secondary Carrier High Time Data Value */
#define CMT_CGH2_SH(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CGH2_SH_SHIFT)) & CMT_CGH2_SH_MASK)
/*! @} */

/*! @name CGL2 - CMT Carrier Generator Low Data Register 2 */
/*! @{ */

#define CMT_CGL2_SL_MASK                         (0xFFU)
#define CMT_CGL2_SL_SHIFT                        (0U)
/*! SL - Secondary Carrier Low Time Data Value */
#define CMT_CGL2_SL(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CGL2_SL_SHIFT)) & CMT_CGL2_SL_MASK)
/*! @} */

/*! @name OC - CMT Output Control Register */
/*! @{ */

#define CMT_OC_IROPEN_MASK                       (0x20U)
#define CMT_OC_IROPEN_SHIFT                      (5U)
/*! IROPEN - IRO Pin Enable
 *  0b0..The IRO signal is disabled.
 *  0b1..The IRO signal is enabled as output.
 */
#define CMT_OC_IROPEN(x)                         (((uint8_t)(((uint8_t)(x)) << CMT_OC_IROPEN_SHIFT)) & CMT_OC_IROPEN_MASK)

#define CMT_OC_CMTPOL_MASK                       (0x40U)
#define CMT_OC_CMTPOL_SHIFT                      (6U)
/*! CMTPOL - CMT Output Polarity
 *  0b0..The IRO signal is active-low.
 *  0b1..The IRO signal is active-high.
 */
#define CMT_OC_CMTPOL(x)                         (((uint8_t)(((uint8_t)(x)) << CMT_OC_CMTPOL_SHIFT)) & CMT_OC_CMTPOL_MASK)

#define CMT_OC_IROL_MASK                         (0x80U)
#define CMT_OC_IROL_SHIFT                        (7U)
/*! IROL - IRO Latch Control */
#define CMT_OC_IROL(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_OC_IROL_SHIFT)) & CMT_OC_IROL_MASK)
/*! @} */

/*! @name MSC - CMT Modulator Status and Control Register */
/*! @{ */

#define CMT_MSC_MCGEN_MASK                       (0x1U)
#define CMT_MSC_MCGEN_SHIFT                      (0U)
/*! MCGEN - Modulator and Carrier Generator Enable
 *  0b0..Modulator and carrier generator disabled
 *  0b1..Modulator and carrier generator enabled
 */
#define CMT_MSC_MCGEN(x)                         (((uint8_t)(((uint8_t)(x)) << CMT_MSC_MCGEN_SHIFT)) & CMT_MSC_MCGEN_MASK)

#define CMT_MSC_EOCIE_MASK                       (0x2U)
#define CMT_MSC_EOCIE_SHIFT                      (1U)
/*! EOCIE - End of Cycle Interrupt Enable
 *  0b0..CPU interrupt is disabled.
 *  0b1..CPU interrupt is enabled.
 */
#define CMT_MSC_EOCIE(x)                         (((uint8_t)(((uint8_t)(x)) << CMT_MSC_EOCIE_SHIFT)) & CMT_MSC_EOCIE_MASK)

#define CMT_MSC_FSK_MASK                         (0x4U)
#define CMT_MSC_FSK_SHIFT                        (2U)
/*! FSK - FSK Mode Select
 *  0b0..The CMT operates in Time or Baseband mode.
 *  0b1..The CMT operates in FSK mode.
 */
#define CMT_MSC_FSK(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_MSC_FSK_SHIFT)) & CMT_MSC_FSK_MASK)

#define CMT_MSC_BASE_MASK                        (0x8U)
#define CMT_MSC_BASE_SHIFT                       (3U)
/*! BASE - Baseband Enable
 *  0b0..Baseband mode is disabled.
 *  0b1..Baseband mode is enabled.
 */
#define CMT_MSC_BASE(x)                          (((uint8_t)(((uint8_t)(x)) << CMT_MSC_BASE_SHIFT)) & CMT_MSC_BASE_MASK)

#define CMT_MSC_EXSPC_MASK                       (0x10U)
#define CMT_MSC_EXSPC_SHIFT                      (4U)
/*! EXSPC - Extended Space Enable
 *  0b0..Extended space is disabled.
 *  0b1..Extended space is enabled.
 */
#define CMT_MSC_EXSPC(x)                         (((uint8_t)(((uint8_t)(x)) << CMT_MSC_EXSPC_SHIFT)) & CMT_MSC_EXSPC_MASK)

#define CMT_MSC_CMTDIV_MASK                      (0x60U)
#define CMT_MSC_CMTDIV_SHIFT                     (5U)
/*! CMTDIV - CMT Clock Divide Prescaler
 *  0b00..IF / 1
 *  0b01..IF / 2
 *  0b10..IF / 4
 *  0b11..IF / 8
 */
#define CMT_MSC_CMTDIV(x)                        (((uint8_t)(((uint8_t)(x)) << CMT_MSC_CMTDIV_SHIFT)) & CMT_MSC_CMTDIV_MASK)

#define CMT_MSC_EOCF_MASK                        (0x80U)
#define CMT_MSC_EOCF_SHIFT                       (7U)
/*! EOCF - End Of Cycle Status Flag
 *  0b0..End of modulation cycle has not occured since the flag last cleared.
 *  0b1..End of modulator cycle has occurred.
 */
#define CMT_MSC_EOCF(x)                          (((uint8_t)(((uint8_t)(x)) << CMT_MSC_EOCF_SHIFT)) & CMT_MSC_EOCF_MASK)
/*! @} */

/*! @name CMD1 - CMT Modulator Data Register Mark High */
/*! @{ */

#define CMT_CMD1_MB_MASK                         (0xFFU)
#define CMT_CMD1_MB_SHIFT                        (0U)
#define CMT_CMD1_MB(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CMD1_MB_SHIFT)) & CMT_CMD1_MB_MASK)
/*! @} */

/*! @name CMD2 - CMT Modulator Data Register Mark Low */
/*! @{ */

#define CMT_CMD2_MB_MASK                         (0xFFU)
#define CMT_CMD2_MB_SHIFT                        (0U)
#define CMT_CMD2_MB(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CMD2_MB_SHIFT)) & CMT_CMD2_MB_MASK)
/*! @} */

/*! @name CMD3 - CMT Modulator Data Register Space High */
/*! @{ */

#define CMT_CMD3_SB_MASK                         (0xFFU)
#define CMT_CMD3_SB_SHIFT                        (0U)
#define CMT_CMD3_SB(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CMD3_SB_SHIFT)) & CMT_CMD3_SB_MASK)
/*! @} */

/*! @name CMD4 - CMT Modulator Data Register Space Low */
/*! @{ */

#define CMT_CMD4_SB_MASK                         (0xFFU)
#define CMT_CMD4_SB_SHIFT                        (0U)
#define CMT_CMD4_SB(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_CMD4_SB_SHIFT)) & CMT_CMD4_SB_MASK)
/*! @} */

/*! @name PPS - CMT Primary Prescaler Register */
/*! @{ */

#define CMT_PPS_PPSDIV_MASK                      (0xFU)
#define CMT_PPS_PPSDIV_SHIFT                     (0U)
/*! PPSDIV - Primary Prescaler Divider
 *  0b0000..Bus clock / 1
 *  0b0001..Bus clock / 2
 *  0b0010..Bus clock / 3
 *  0b0011..Bus clock / 4
 *  0b0100..Bus clock / 5
 *  0b0101..Bus clock / 6
 *  0b0110..Bus clock / 7
 *  0b0111..Bus clock / 8
 *  0b1000..Bus clock / 9
 *  0b1001..Bus clock / 10
 *  0b1010..Bus clock / 11
 *  0b1011..Bus clock / 12
 *  0b1100..Bus clock / 13
 *  0b1101..Bus clock / 14
 *  0b1110..Bus clock / 15
 *  0b1111..Bus clock / 16
 */
#define CMT_PPS_PPSDIV(x)                        (((uint8_t)(((uint8_t)(x)) << CMT_PPS_PPSDIV_SHIFT)) & CMT_PPS_PPSDIV_MASK)
/*! @} */

/*! @name DMA - CMT Direct Memory Access Register */
/*! @{ */

#define CMT_DMA_DMA_MASK                         (0x1U)
#define CMT_DMA_DMA_SHIFT                        (0U)
/*! DMA - DMA Enable
 *  0b0..DMA transfer request and done are disabled.
 *  0b1..DMA transfer request and done are enabled.
 */
#define CMT_DMA_DMA(x)                           (((uint8_t)(((uint8_t)(x)) << CMT_DMA_DMA_SHIFT)) & CMT_DMA_DMA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMT_Register_Masks */


/*!
 * @}
 */ /* end of group CMT_Peripheral_Access_Layer */


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


#endif  /* CMT_H_ */

