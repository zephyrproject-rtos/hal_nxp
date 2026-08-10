/*
** ###################################################################
**     Processors:          MIMX9371xxVTx_ca55
**                          MIMX9371xxVTx_cm33
**                          MIMX9371xxVTx_cm7
**                          MIMX9373xxVTx_ca55
**                          MIMX9373xxVTx_cm33
**                          MIMX9373xxVTx_cm7
**                          MIMX9373xxVZx_ca55
**                          MIMX9373xxVZx_cm33
**                          MIMX9373xxVZx_cm7
**                          MIMX9375xxVTx_ca55
**                          MIMX9375xxVTx_cm33
**                          MIMX9375xxVTx_cm7
**                          MIMX9375xxVZx_ca55
**                          MIMX9375xxVZx_cm33
**                          MIMX9375xxVZx_cm7
**
**     Version:             rev. 1.0, 2026-04-09
**     Build:               b260624
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
**     - rev. 1.0 (2026-04-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC.h
 * @version 1.0
 * @date 2026-04-09
 * @brief CMSIS Peripheral Access Layer for IOMUXC
 *
 * CMSIS Peripheral Access Layer for IOMUXC
 */

#if !defined(PERI_IOMUXC_H_)
#define PERI_IOMUXC_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9371xxVTx_ca55))
#include "MIMX9371_ca55_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm33))
#include "MIMX9371_cm33_COMMON.h"
#elif (defined(CPU_MIMX9371xxVTx_cm7))
#include "MIMX9371_cm7_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_ca55) || defined(CPU_MIMX9373xxVZx_ca55))
#include "MIMX9373_ca55_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm33) || defined(CPU_MIMX9373xxVZx_cm33))
#include "MIMX9373_cm33_COMMON.h"
#elif (defined(CPU_MIMX9373xxVTx_cm7) || defined(CPU_MIMX9373xxVZx_cm7))
#include "MIMX9373_cm7_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_ca55) || defined(CPU_MIMX9375xxVZx_ca55))
#include "MIMX9375_ca55_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm33) || defined(CPU_MIMX9375xxVZx_cm33))
#include "MIMX9375_cm33_COMMON.h"
#elif (defined(CPU_MIMX9375xxVTx_cm7) || defined(CPU_MIMX9375xxVZx_cm7))
#include "MIMX9375_cm7_COMMON.h"
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
 *  0b000000..No drive
 *  0b000001..X1 (for 1.8 V and 3.3 V NVCC IO supply voltage)
 *  0b000011..X2 (for 1.8 V and 3.3 V NVCC IO supply voltage)
 *  0b000111..X3 (for 1.8 V and 3.3 V NVCC IO supply voltage)
 *  0b001111..X4 (for 1.8 V and 3.3 V NVCC IO supply voltage)
 *  0b011111..X5 (for 1.8 V NVCC IO supply voltage)
 *  0b111111..X6 (for 1.8 V NVCC IO supply voltage)
 */
#define IOMUXC_SW_PAD_CTL_PAD_DSE(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_FSEL1_MASK         (0x180U)
#define IOMUXC_SW_PAD_CTL_PAD_FSEL1_SHIFT        (7U)
/*! FSEL1 - Slew Rate Field
 *  0b00..Reserved
 *  0b01..Reserved
 *  0b10..Fast Slew Rate
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

#define IOMUXC_SW_PAD_CTL_PAD_APC_MASK           (0xF000000U)
#define IOMUXC_SW_PAD_CTL_PAD_APC_SHIFT          (24U)
/*! APC - Domain Access Field */
#define IOMUXC_SW_PAD_CTL_PAD_APC(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_APC_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_APC_MASK)

#define IOMUXC_SW_PAD_CTL_PAD_APC_LCK_MASK       (0xF0000000U)
#define IOMUXC_SW_PAD_CTL_PAD_APC_LCK_SHIFT      (28U)
/*! APC_LCK - APC lock bits */
#define IOMUXC_SW_PAD_CTL_PAD_APC_LCK(x)         (((uint32_t)(((uint32_t)(x)) << IOMUXC_SW_PAD_CTL_PAD_APC_LCK_SHIFT)) & IOMUXC_SW_PAD_CTL_PAD_APC_LCK_MASK)
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

