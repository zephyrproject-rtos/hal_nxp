/*
** ###################################################################
**     Processors:          MCXC143VFM
**                          MCXC143VFT
**                          MCXC144VFM
**                          MCXC144VFT
**                          MCXC243VFT
**                          MCXC244VFM
**                          MCXC244VFT
**                          MCXC443VLH
**                          MCXC443VMP
**                          MCXC444VLH
**                          MCXC444VMP
**
**     Version:             rev. 1.0, 2024-03-11
**     Build:               b240705
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
**     - rev. 1.0 (2024-03-11)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DMAMUX.h
 * @version 1.0
 * @date 2024-03-11
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(DMAMUX_H_)
#define DMAMUX_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC143VFM) || defined(CPU_MCXC143VFT))
#include "MCXC143_COMMON.h"
#elif (defined(CPU_MCXC144VFM) || defined(CPU_MCXC144VFT))
#include "MCXC144_COMMON.h"
#elif (defined(CPU_MCXC243VFT))
#include "MCXC243_COMMON.h"
#elif (defined(CPU_MCXC244VFM) || defined(CPU_MCXC244VFT))
#include "MCXC244_COMMON.h"
#elif (defined(CPU_MCXC443VLH) || defined(CPU_MCXC443VMP))
#include "MCXC443_COMMON.h"
#elif (defined(CPU_MCXC444VLH) || defined(CPU_MCXC444VMP))
#include "MCXC444_COMMON.h"
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
#define DMAMUX_CHCFG_COUNT                        4u

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
 *  0b000010..LPUART0_Rx_Signal
 *  0b000011..LPUART0_Tx_Signal
 *  0b000100..LPUART1_Rx_Signal
 *  0b000101..LPUART1_Tx_Signal
 *  0b000110..UART2_Rx_Signal
 *  0b000111..UART2_Tx_Signal
 *  0b001010..FlexIO_Channel0_Signal
 *  0b001011..FlexIO_Channel1_Signal
 *  0b001100..FlexIO_Channel2_Signal
 *  0b001101..FlexIO_Channel3_Signal
 *  0b001110..I2S0_Rx_Signal
 *  0b001111..I2S0_Tx_Signal
 *  0b010000..SPI0_Rx_Signal
 *  0b010001..SPI0_Tx_Signal
 *  0b010010..SPI1_Rx_Signal
 *  0b010011..SPI1_Tx_Signal
 *  0b010110..I2C0_Signal
 *  0b010111..I2C1_Signal
 *  0b011000..TPM0_Channel0_Signal
 *  0b011001..TPM0_Channel1_Signal
 *  0b011010..TPM0_Channel2_Signal
 *  0b011011..TPM0_Channel3_Signal
 *  0b011100..TPM0_Channel4_Signal
 *  0b011101..TPM0_Channel5_Signal
 *  0b100000..TPM1_Channel0_Signal
 *  0b100001..TPM1_Channel1_Signal
 *  0b100010..TPM2_Channel0_Signal
 *  0b100011..TPM2_Channel1_Signal
 *  0b101000..ADC0_Signal
 *  0b101010..CMP0_Signal
 *  0b101101..DAC0_Signal
 *  0b110001..Port_A_Signal
 *  0b110011..Port_C_Signal
 *  0b110100..Port_D_Signal
 *  0b110110..TPM0_Overflow_Signal
 *  0b110111..TPM1_Overflow_Signal
 *  0b111000..TPM2_Overflow_Signal
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

