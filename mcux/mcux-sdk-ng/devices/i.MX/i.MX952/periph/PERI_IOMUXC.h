/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOMUXC
 *
 * CMSIS Peripheral Access Layer for IOMUXC
 */

#if !defined(PERI_IOMUXC_H_)
#define PERI_IOMUXC_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- IOMUXC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Peripheral_Access_Layer IOMUXC Peripheral Access Layer
 * @{
 */

/** IOMUXC - Size of Registers Arrays */
#define IOMUXC_SW_MUX_CTL_PAD_COUNT               140u
#define IOMUXC_SW_PAD_CTL_PAD_COUNT               140u
#define IOMUXC_SELECT_INPUT_COUNT                 135u

/** IOMUXC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_DAP_TDI SW MUX Control Register..SW_MUX_CTL_PAD_FCCU_ERR0 SW MUX Control Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_DAP_TDI SW PAD Control Register..SW_PAD_CTL_PAD_FCCU_ERR0 SW PAD Control Register, array offset: 0x230, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[IOMUXC_SELECT_INPUT_COUNT]; /**< IMX952_AONMIX_TOP_CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..IMX952_WAKEUPMIX_TOP_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_7 DAISY Register, array offset: 0x460, array step: 0x4 */
} IOMUXC_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC_Register_Masks IOMUXC Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_DAP_TDI SW MUX Control Register..SW_MUX_CTL_PAD_FCCU_ERR0 SW MUX Control Register */
/*! @{ */

#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK      (0x7U)
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT     (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: IMX952_WAKEUPMIX_TOP_GPIO2_IO19 of instance: imx952_wakeupmix_top
 *  0b001..Select mux mode: ALT1 mux port: IMX952_WAKEUPMIX_TOP_SAI3_RX_SYNC of instance: imx952_wakeupmix_top
 *  0b010..Select mux mode: ALT2 mux port: IMX952_AONMIX_TOP_PDM_BIT_STREAM03 of instance: imx952_aonmix_top
 *  0b011..Select mux mode: ALT3 mux port: IMX952_WAKEUPMIX_TOP_FLEXIO1_FLEXIO19 of instance: imx952_wakeupmix_top
 *  0b100..Select mux mode: ALT4 mux port: IMX952_WAKEUPMIX_TOP_LPSPI5_SIN of instance: imx952_wakeupmix_top
 *  0b101..Select mux mode: ALT5 mux port: IMX952_WAKEUPMIX_TOP_LPSPI4_SIN of instance: imx952_wakeupmix_top
 *  0b110..Select mux mode: ALT6 mux port: IMX952_WAKEUPMIX_TOP_TPM6_CH2 of instance: imx952_wakeupmix_top
 *  0b111..Select mux mode: ALT7 mux port: IMX952_WAKEUPMIX_TOP_AUDMIX_TDM_OUT_TXDATA of instance: imx952_wakeupmix_top
 */
#define IOMUXC_SW_MUX_CTL_PAD_MUX_MODE(x)        (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC_SW_MUX_CTL_PAD_SION_MASK          (0x10U)
#define IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT         (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad DAP_TDO_TRACESWO
 */
#define IOMUXC_SW_MUX_CTL_PAD_SION(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_DAP_TDI SW PAD Control Register..SW_PAD_CTL_PAD_FCCU_ERR0 SW PAD Control Register */
/*! @{ */

#define IOMUXC_SW_PAD_CTL_PAD_DSE_MASK           (0x7EU)
#define IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT          (1U)
/*! DSE - Drive Strength Field
 *  0b000000..
 *  0b000001..
 *  0b000010..
 *  0b000011..
 *  0b000100..
 *  0b000101..
 *  0b000110..
 *  0b000111..
 *  0b001000..
 *  0b001001..
 *  0b001010..
 *  0b001011..
 *  0b001100..
 *  0b001101..
 *  0b001110..
 *  0b001111..
 *  0b010000..
 *  0b010001..
 *  0b010010..
 *  0b010011..
 *  0b010100..
 *  0b010101..
 *  0b010110..
 *  0b010111..
 *  0b011000..
 *  0b011001..
 *  0b011010..
 *  0b011011..
 *  0b011100..
 *  0b011101..
 *  0b011110..
 *  0b011111..
 *  0b100000..
 *  0b100001..
 *  0b100010..
 *  0b100011..
 *  0b100100..
 *  0b100101..
 *  0b100110..
 *  0b100111..
 *  0b101000..
 *  0b101001..
 *  0b101010..
 *  0b101011..
 *  0b101100..
 *  0b101101..
 *  0b101110..
 *  0b101111..
 *  0b110000..
 *  0b110001..
 *  0b110010..
 *  0b110011..
 *  0b110100..
 *  0b110101..
 *  0b110110..
 *  0b110111..
 *  0b111000..
 *  0b111001..
 *  0b111010..
 *  0b111011..
 *  0b111100..
 *  0b111101..
 *  0b111110..
 *  0b111111..X6
 */
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_FSEL1_MASK         (0x180U)
#define IOMUXC_SW_PAD_CTL_PAD_FSEL1_SHIFT        (7U)
/*! FSEL1 - Slew Rate Field
 *  0b00..
 *  0b01..
 *  0b10..Slight Fast Slew Rate
 *  0b11..Fast Slew Rate
 */
#define IOMUXC_SW_PAD_CTL_PAD_FSEL1(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_FSEL1_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_FSEL1_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PU_MASK            (0x200U)
#define IOMUXC_SW_PAD_CTL_PAD_PU_SHIFT           (9U)
/*! PU - Pull Up Field
 *  0b0..No pull up
 *  0b1..Pull up
 */
#define IOMUXC_SW_PAD_CTL_PAD_PU(x)              (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PU_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PU_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_PD_MASK            (0x400U)
#define IOMUXC_SW_PAD_CTL_PAD_PD_SHIFT           (10U)
/*! PD - Pull Down Field
 *  0b0..Not pull down
 *  0b1..Pull down
 */
#define IOMUXC_SW_PAD_CTL_PAD_PD(x)              (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_PD_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_PD_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_OD_MASK            (0x800U)
#define IOMUXC_SW_PAD_CTL_PAD_OD_SHIFT           (11U)
/*! OD - Open Drain Field
 *  0b0..Open Drain Disable
 *  0b1..Open Drain Enable
 */
#define IOMUXC_SW_PAD_CTL_PAD_OD(x)              (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_OD_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_OD_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_HYS_MASK           (0x1000U)
#define IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT          (12U)
/*! HYS - Schmitt trigger Field
 *  0b0..No Schmitt input
 *  0b1..Schmitt input
 */
#define IOMUXC_SW_PAD_CTL_PAD_HYS(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_HYS_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_HYS_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_SMC0_MASK          (0x2000U)
#define IOMUXC_SW_PAD_CTL_PAD_SMC0_SHIFT         (13U)
/*! SMC0 - Safe Mode Control 0 Field
 *  0b0..Output buffer disabled during safe mode
 *  0b1..Output buffer enabled during safe mode
 */
#define IOMUXC_SW_PAD_CTL_PAD_SMC0(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SMC0_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SMC0_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_SMC1_MASK          (0x4000U)
#define IOMUXC_SW_PAD_CTL_PAD_SMC1_SHIFT         (14U)
/*! SMC1 - Safe Mode Control 1 Field
 *  0b0..Output buffer disabled during safe mode
 *  0b1..Output buffer enabled during safe mode
 */
#define IOMUXC_SW_PAD_CTL_PAD_SMC1(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SMC1_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SMC1_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_SMC2_MASK          (0x8000U)
#define IOMUXC_SW_PAD_CTL_PAD_SMC2_SHIFT         (15U)
/*! SMC2 - Safe Mode Control 2 Field
 *  0b0..Output buffer disabled during safe mode
 *  0b1..Output buffer enabled during safe mode
 */
#define IOMUXC_SW_PAD_CTL_PAD_SMC2(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_SMC2_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_SMC2_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_APC_MASK           (0xFF000000U)
#define IOMUXC_SW_PAD_CTL_PAD_APC_SHIFT          (24U)
/*! APC - Domain Access Field
 *  0b00000000..
 *  0b00000001..
 *  0b00000010..
 *  0b00000011..
 *  0b00000100..
 *  0b00000101..
 *  0b00000110..
 *  0b00000111..
 *  0b00001000..
 *  0b00001001..
 *  0b00001010..
 *  0b00001011..
 *  0b00001100..
 *  0b00001101..
 *  0b00001110..
 *  0b00001111..
 *  0b00010000..
 *  0b00010001..
 *  0b00010010..
 *  0b00010011..
 *  0b00010100..
 *  0b00010101..
 *  0b00010110..
 *  0b00010111..
 *  0b00011000..
 *  0b00011001..
 *  0b00011010..
 *  0b00011011..
 *  0b00011100..
 *  0b00011101..
 *  0b00011110..
 *  0b00011111..
 *  0b00100000..
 *  0b00100001..
 *  0b00100010..
 *  0b00100011..
 *  0b00100100..
 *  0b00100101..
 *  0b00100110..
 *  0b00100111..
 *  0b00101000..
 *  0b00101001..
 *  0b00101010..
 *  0b00101011..
 *  0b00101100..
 *  0b00101101..
 *  0b00101110..
 *  0b00101111..
 *  0b00110000..
 *  0b00110001..
 *  0b00110010..
 *  0b00110011..
 *  0b00110100..
 *  0b00110101..
 *  0b00110110..
 *  0b00110111..
 *  0b00111000..
 *  0b00111001..
 *  0b00111010..
 *  0b00111011..
 *  0b00111100..
 *  0b00111101..
 *  0b00111110..
 *  0b00111111..
 *  0b01000000..
 *  0b01000001..
 *  0b01000010..
 *  0b01000011..
 *  0b01000100..
 *  0b01000101..
 *  0b01000110..
 *  0b01000111..
 *  0b01001000..
 *  0b01001001..
 *  0b01001010..
 *  0b01001011..
 *  0b01001100..
 *  0b01001101..
 *  0b01001110..
 *  0b01001111..
 *  0b01010000..
 *  0b01010001..
 *  0b01010010..
 *  0b01010011..
 *  0b01010100..
 *  0b01010101..
 *  0b01010110..
 *  0b01010111..
 *  0b01011000..
 *  0b01011001..
 *  0b01011010..
 *  0b01011011..
 *  0b01011100..
 *  0b01011101..
 *  0b01011110..
 *  0b01011111..
 *  0b01100000..
 *  0b01100001..
 *  0b01100010..
 *  0b01100011..
 *  0b01100100..
 *  0b01100101..
 *  0b01100110..
 *  0b01100111..
 *  0b01101000..
 *  0b01101001..
 *  0b01101010..
 *  0b01101011..
 *  0b01101100..
 *  0b01101101..
 *  0b01101110..
 *  0b01101111..
 *  0b01110000..
 *  0b01110001..
 *  0b01110010..
 *  0b01110011..
 *  0b01110100..
 *  0b01110101..
 *  0b01110110..
 *  0b01110111..
 *  0b01111000..
 *  0b01111001..
 *  0b01111010..
 *  0b01111011..
 *  0b01111100..
 *  0b01111101..
 *  0b01111110..
 *  0b01111111..
 *  0b10000000..
 *  0b10000001..
 *  0b10000010..
 *  0b10000011..
 *  0b10000100..
 *  0b10000101..
 *  0b10000110..
 *  0b10000111..
 *  0b10001000..
 *  0b10001001..
 *  0b10001010..
 *  0b10001011..
 *  0b10001100..
 *  0b10001101..
 *  0b10001110..
 *  0b10001111..
 *  0b10010000..
 *  0b10010001..
 *  0b10010010..
 *  0b10010011..
 *  0b10010100..
 *  0b10010101..
 *  0b10010110..
 *  0b10010111..
 *  0b10011000..
 *  0b10011001..
 *  0b10011010..
 *  0b10011011..
 *  0b10011100..
 *  0b10011101..
 *  0b10011110..
 *  0b10011111..
 *  0b10100000..
 *  0b10100001..
 *  0b10100010..
 *  0b10100011..
 *  0b10100100..
 *  0b10100101..
 *  0b10100110..
 *  0b10100111..
 *  0b10101000..
 *  0b10101001..
 *  0b10101010..
 *  0b10101011..
 *  0b10101100..
 *  0b10101101..
 *  0b10101110..
 *  0b10101111..
 *  0b10110000..
 *  0b10110001..
 *  0b10110010..
 *  0b10110011..
 *  0b10110100..
 *  0b10110101..
 *  0b10110110..
 *  0b10110111..
 *  0b10111000..
 *  0b10111001..
 *  0b10111010..
 *  0b10111011..
 *  0b10111100..
 *  0b10111101..
 *  0b10111110..
 *  0b10111111..
 *  0b11000000..
 *  0b11000001..
 *  0b11000010..
 *  0b11000011..
 *  0b11000100..
 *  0b11000101..
 *  0b11000110..
 *  0b11000111..
 *  0b11001000..
 *  0b11001001..
 *  0b11001010..
 *  0b11001011..
 *  0b11001100..
 *  0b11001101..
 *  0b11001110..
 *  0b11001111..
 *  0b11010000..
 *  0b11010001..
 *  0b11010010..
 *  0b11010011..
 *  0b11010100..
 *  0b11010101..
 *  0b11010110..
 *  0b11010111..
 *  0b11011000..
 *  0b11011001..
 *  0b11011010..
 *  0b11011011..
 *  0b11011100..
 *  0b11011101..
 *  0b11011110..
 *  0b11011111..
 *  0b11100000..
 *  0b11100001..
 *  0b11100010..
 *  0b11100011..
 *  0b11100100..
 *  0b11100101..
 *  0b11100110..
 *  0b11100111..
 *  0b11101000..
 *  0b11101001..
 *  0b11101010..
 *  0b11101011..
 *  0b11101100..
 *  0b11101101..
 *  0b11101110..
 *  0b11101111..
 *  0b11110000..
 *  0b11110001..
 *  0b11110010..
 *  0b11110011..
 *  0b11110100..
 *  0b11110101..
 *  0b11110110..
 *  0b11110111..
 *  0b11111000..
 *  0b11111001..
 *  0b11111010..
 *  0b11111011..
 *  0b11111100..
 *  0b11111101..
 *  0b11111110..
 *  0b11111111..
 */
#define IOMUXC_SW_PAD_CTL_PAD_APC(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_APC_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_APC_MASK)
/*! @} */

/*! @name SELECT_INPUT - IMX952_AONMIX_TOP_CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..IMX952_WAKEUPMIX_TOP_XSPI_SLV_IPP_IND_IO_SELECT_INPUT_7 DAISY Register */
/*! @{ */

#define IOMUXC_SELECT_INPUT_DAISY_MASK           (0x3U)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
#define IOMUXC_SELECT_INPUT_DAISY_SHIFT          (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b00..Selecting Pad: DAP_TDO_TRACESWO for Mode: ALT3
 *  0b01..Selecting Pad: ENET1_TD2 for Mode: ALT2
 *  0b10..Selecting Pad: GPIO_IO27 for Mode: ALT2
 *  0b11..Selecting Pad: SD2_DATA1 for Mode: ALT2
 */
#define IOMUXC_SELECT_INPUT_DAISY(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC_Peripheral_Access_Layer */


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


#endif  /* PERI_IOMUXC_H_ */

