/*
** ###################################################################
**     Processors:          MKE12Z128VLF7
**                          MKE12Z128VLH7
**                          MKE12Z128VLL7
**                          MKE12Z256VLF7
**                          MKE12Z256VLH7
**                          MKE12Z256VLL7
**                          MKE13Z128VLF7
**                          MKE13Z128VLH7
**                          MKE13Z128VLL7
**                          MKE13Z256VLF7
**                          MKE13Z256VLH7
**                          MKE13Z256VLL7
**                          MKE17Z128VLF7
**                          MKE17Z128VLH7
**                          MKE17Z128VLL7
**                          MKE17Z256VLF7
**                          MKE17Z256VLH7
**                          MKE17Z256VLL7
**
**     Version:             rev. 3.0, 2021-10-08
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMAMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-12-10)
**         Initial version.
**     - rev. 2.0 (2021-06-25)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2021-10-08)
**         Add 48LQFP parts.
**
** ###################################################################
*/

/*!
 * @file DMAMUX.h
 * @version 3.0
 * @date 2021-10-08
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(DMAMUX_H_)
#define DMAMUX_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z128VLF7) || defined(CPU_MKE12Z128VLH7) || defined(CPU_MKE12Z128VLL7) || defined(CPU_MKE12Z256VLF7) || defined(CPU_MKE12Z256VLH7) || defined(CPU_MKE12Z256VLL7))
#include "MKE12Z7_COMMON.h"
#elif (defined(CPU_MKE13Z128VLF7) || defined(CPU_MKE13Z128VLH7) || defined(CPU_MKE13Z128VLL7) || defined(CPU_MKE13Z256VLF7) || defined(CPU_MKE13Z256VLH7) || defined(CPU_MKE13Z256VLL7))
#include "MKE13Z7_COMMON.h"
#elif (defined(CPU_MKE17Z128VLF7) || defined(CPU_MKE17Z128VLH7) || defined(CPU_MKE17Z128VLL7) || defined(CPU_MKE17Z256VLF7) || defined(CPU_MKE17Z256VLH7) || defined(CPU_MKE17Z256VLL7))
#include "MKE17Z7_COMMON.h"
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
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */
#define DMAMUX_CHCFG_COUNT                        8u

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[DMAMUX_CHCFG_COUNT];          /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel Configuration register */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
/*! SOURCE - DMA Channel Source (Slot)
 *  0b000000..Disable_Signal
 *  0b000001..TSI0_Signal
 *  0b000010..LPUART0_Rx_Signal
 *  0b000011..LPUART0_Tx_Signal
 *  0b000100..LPUART1_Rx_Signal
 *  0b000101..LPUART1_Tx_Signal
 *  0b000110..LPUART2_Rx_Signal
 *  0b000111..LPUART2_Tx_Signal
 *  0b001010..FlexIO_Channel0_Signal
 *  0b001011..FlexIO_Channel1_Signal
 *  0b001100..FlexIO_Channel2_Signal
 *  0b001101..FlexIO_Channel3_Signal
 *  0b001110..LPSPI0_Rx_Signal
 *  0b001111..LPSPI0_Tx_Signal
 *  0b010010..LPI2C0_Rx_Signal
 *  0b010011..LPI2C0_Tx_Signal
 *  0b010100..FTM0_Channel0_Signal
 *  0b010101..FTM0_Channel1_Signal
 *  0b010110..FTM0_Channel2_Signal
 *  0b010111..FTM0_Channel3_Signal
 *  0b011000..FTM0_Channel4_Signal
 *  0b011001..FTM0_Channel5_Signal
 *  0b011010..FTM0_Channel6_Signal
 *  0b011011..FTM0_Channel7_Signal
 *  0b011100..FTM1_Channel0_Signal
 *  0b011101..FTM1_Channel1_Signal
 *  0b011110..FTM2_Channel0_Signal
 *  0b011111..FTM2_Channel1_Signal
 *  0b101000..ADC0_Signal
 *  0b101011..CMP0_Signal
 *  0b110000..TSI1_Signal
 *  0b110001..PortA_Signal
 *  0b110010..PortB_Signal
 *  0b110011..PortC_Signal
 *  0b110100..PortD_Signal
 *  0b110101..PortE_Signal
 *  0b111001..FTM1_Channel2_Signal
 *  0b111010..FTM2_Channel2_Signal
 *  0b111011..LPTMR0_Signal
 *  0b111100..AlwaysOn60_Signal
 *  0b111101..AlwaysOn61_Signal
 *  0b111110..AlwaysOn62_Signal
 *  0b111111..AlwaysOn63_Signal
 */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)

#define DMAMUX_CHCFG_TRIG_MASK                   (0x40U)
#define DMAMUX_CHCFG_TRIG_SHIFT                  (6U)
/*! TRIG - DMA Channel Trigger Enable
 *  0b0..Triggering is disabled. If triggering is disabled and ENBL is set, the DMA Channel will simply route the
 *       specified source to the DMA channel. (Normal mode)
 *  0b1..Triggering is enabled. If triggering is enabled and ENBL is set, the DMAMUX is in Periodic Trigger mode.
 */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_TRIG_SHIFT)) & DMAMUX_CHCFG_TRIG_MASK)

#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)
/*! ENBL - DMA Channel Enable
 *  0b0..DMA channel is disabled. This mode is primarily used during configuration of the DMAMux. The DMA has
 *       separate channel enables/disables, which should be used to disable or reconfigure a DMA channel.
 *  0b1..DMA channel is enabled
 */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


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


#endif  /* DMAMUX_H_ */

