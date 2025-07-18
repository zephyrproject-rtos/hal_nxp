/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRGMUX
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
 * @file PERI_TRGMUX.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

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
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGCFG_COUNT                       40u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX ADC12_0 Register..TRGMUX CM7_RXEV Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX ADC12_0 Register..TRGMUX CM7_RXEV Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x7F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x7F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x7F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - TRGMUX register lock.
 *  0b0..Register can be written.
 *  0b1..Register cannot be written until the next system Reset.
 */
#define TRGMUX_TRGCFG_LK(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_LK_SHIFT)) & TRGMUX_TRGCFG_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */

#define TRGMUX_ADC12_0_INDEX 0
#define TRGMUX_ADC12_1_INDEX 1
#define TRGMUX_ADC12_2_INDEX 2
#define TRGMUX_LPCMP_0_INDEX 3
#define TRGMUX_LPCMP_1_INDEX 4
#define TRGMUX_LPCMP_2_INDEX 5
#define TRGMUX_BCTU_INDEX 6
#define TRGMUX_eMIOS012_ODIS_INDEX 7
#define TRGMUX_eMIOS0_0_INDEX 8
#define TRGMUX_eMIOS0_1_INDEX 9
#define TRGMUX_eMIOS0_2_INDEX 10
#define TRGMUX_eMIOS0_3_INDEX 11
#define TRGMUX_eMIOS1_0_INDEX 12
#define TRGMUX_eMIOS1_1_INDEX 13
#define TRGMUX_eMIOS1_2_INDEX 14
#define TRGMUX_eMIOS1_3_INDEX 15
#define TRGMUX_FlexIO_INDEX 16
#define TRGMUX_SIUL_OUT0_INDEX 17
#define TRGMUX_SIUL_OUT1_INDEX 18
#define TRGMUX_SIUL_OUT2_INDEX 19
#define TRGMUX_SIUL_OUT3_INDEX 20
#define TRGMUX_LPI2C_0_INDEX 21
#define TRGMUX_LPSPI_0_INDEX 22
#define TRGMUX_LPSPI_1_INDEX 23
#define TRGMUX_LPSPI_2_INDEX 24
#define TRGMUX_LPUART_0_INDEX 25
#define TRGMUX_LPUART_1_INDEX 26
#define TRGMUX_LPUART_2_INDEX 27
#define TRGMUX_LPUART_3_INDEX 28
#define TRGMUX_LCU0_SYNC_INDEX 29
#define TRGMUX_LCU0_FORCE_INDEX 30
#define TRGMUX_LCU0_0_INDEX 31
#define TRGMUX_LCU0_1_INDEX 32
#define TRGMUX_LCU0_2_INDEX 33
#define TRGMUX_LCU1_SYNC_INDEX 34
#define TRGMUX_LCU1_FORCE_INDEX 35
#define TRGMUX_LCU1_0_INDEX 36
#define TRGMUX_LCU1_1_INDEX 37
#define TRGMUX_LCU1_2_INDEX 38
#define TRGMUX_CM7_RXEV_INDEX 39


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_TRGMUX_H_ */

