/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**                          LPC804UK
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DAC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DAC
 *
 * CMSIS Peripheral Access Layer for DAC
 */

#if !defined(PERI_DAC_H_)
#define PERI_DAC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC804M101JDH20) || defined(CPU_LPC804M101JDH24) || defined(CPU_LPC804M101JHI33) || defined(CPU_LPC804M111JDH24) || defined(CPU_LPC804UK))
#include "LPC804_COMMON.h"
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
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit., offset: 0x0 */
  __IO uint32_t CTRL;                              /**< DAC Control register. This register controls DMA and timer operation., offset: 0x4 */
  __IO uint32_t CNTVAL;                            /**< DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer., offset: 0x8 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name CR - D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit. */
/*! @{ */

#define DAC_CR_VALUE_MASK                        (0xFFC0U)
#define DAC_CR_VALUE_SHIFT                       (6U)
/*! VALUE - After the selected settling time after this field is written with a new VALUE, the
 *    voltage on the DAC_OUT pin (with respect to VSSA) is VALUE (VREFP - VREFN)/1024 + VREFN.
 */
#define DAC_CR_VALUE(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_VALUE_SHIFT)) & DAC_CR_VALUE_MASK)

#define DAC_CR_BIAS_MASK                         (0x10000U)
#define DAC_CR_BIAS_SHIFT                        (16U)
/*! BIAS - The settling time of the DAC
 *  0b0..The settling time of the DAC is 1 us max, and the maximum current is 700 uA. This allows a maximum update rate of 1 MHz.
 *  0b1..The settling time of the DAC is 2.5 us and the maximum current is 350 uA. This allows a maximum update rate of 400 kHz.
 */
#define DAC_CR_BIAS(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_BIAS_SHIFT)) & DAC_CR_BIAS_MASK)
/*! @} */

/*! @name CTRL - DAC Control register. This register controls DMA and timer operation. */
/*! @{ */

#define DAC_CTRL_INT_CPU_REQ_MASK                (0x1U)
#define DAC_CTRL_INT_CPU_REQ_SHIFT               (0U)
/*! INT_CPU_REQ - Interrupt request to CPU. This interrupt request is handled by the CPU.
 *  0b0..Clear on any write to the CR register.
 *  0b1..Set by hardware when the timer times out.
 */
#define DAC_CTRL_INT_CPU_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_INT_CPU_REQ_SHIFT)) & DAC_CTRL_INT_CPU_REQ_MASK)

#define DAC_CTRL_DBLBUF_ENA_MASK                 (0x2U)
#define DAC_CTRL_DBLBUF_ENA_SHIFT                (1U)
/*! DBLBUF_ENA - dacr double buffer
 *  0b0..DACR double-buffering is disabled.
 *  0b1..When this bit and the CNT_ENA bit are both set, the double-buffering feature in the DACR register will be
 *       enabled. Writes to the DACR register are written to a pre-buffer and then transferred to the DACR on the
 *       next time-out of the counter.
 */
#define DAC_CTRL_DBLBUF_ENA(x)                   (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_DBLBUF_ENA_SHIFT)) & DAC_CTRL_DBLBUF_ENA_MASK)

#define DAC_CTRL_CNT_ENA_MASK                    (0x4U)
#define DAC_CTRL_CNT_ENA_SHIFT                   (2U)
/*! CNT_ENA - time-out counter operation
 *  0b0..Time-out counter operation is disabled.
 *  0b1..Time-out counter operation is enabled.
 */
#define DAC_CTRL_CNT_ENA(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_CNT_ENA_SHIFT)) & DAC_CTRL_CNT_ENA_MASK)
/*! @} */

/*! @name CNTVAL - DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer. */
/*! @{ */

#define DAC_CNTVAL_VALUE_MASK                    (0xFFFFU)
#define DAC_CNTVAL_VALUE_SHIFT                   (0U)
/*! VALUE - 16-bit reload value for the DAC interrupt/DMA timer. */
#define DAC_CNTVAL_VALUE(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CNTVAL_VALUE_SHIFT)) & DAC_CNTVAL_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


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


#endif  /* PERI_DAC_H_ */

