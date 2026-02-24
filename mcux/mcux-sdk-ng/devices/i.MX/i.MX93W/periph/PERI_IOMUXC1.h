/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260114
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOMUXC1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-12-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_IOMUXC1.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for IOMUXC1
 *
 * CMSIS Peripheral Access Layer for IOMUXC1
 */

#if !defined(PERI_IOMUXC1_H_)
#define PERI_IOMUXC1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX93W32610GCM_ca55))
#include "MIMX93W32_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W32610GCM_cm33))
#include "MIMX93W32_cm33_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_ca55))
#include "MIMX93W52_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_cm33))
#include "MIMX93W52_cm33_COMMON.h"
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

#if defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IOMUXC1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Peripheral_Access_Layer IOMUXC1 Peripheral Access Layer
 * @{
 */

/** IOMUXC1 - Size of Registers Arrays */
#define IOMUXC1_SW_MUX_CTL_PAD_COUNT              108u
#define IOMUXC1_SW_PAD_CTL_PAD_COUNT              108u
#define IOMUXC1_SELECT_INPUT_COUNT                68u

/** IOMUXC1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SW_MUX_CTL_PAD[IOMUXC1_SW_MUX_CTL_PAD_COUNT]; /**< SW_MUX_CTL_PAD_DAP_TDI SW MUX Control Register..SW_MUX_CTL_PAD_WDOG_ANY SW MUX Control Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t SW_PAD_CTL_PAD[IOMUXC1_SW_PAD_CTL_PAD_COUNT]; /**< SW_PAD_CTL_PAD_DAP_TDI SW PAD Control Register..SW_PAD_CTL_PAD_WDOG_ANY SW PAD Control Register, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t SELECT_INPUT[IOMUXC1_SELECT_INPUT_COUNT]; /**< CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..USDHC3_IPP_DAT3_IN_SELECT_INPUT DAISY Register, array offset: 0x360, array step: 0x4 */
} IOMUXC1_Type;

/* ----------------------------------------------------------------------------
   -- IOMUXC1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOMUXC1_Register_Masks IOMUXC1 Register Masks
 * @{
 */

/*! @name SW_MUX_CTL_PAD - SW_MUX_CTL_PAD_DAP_TDI SW MUX Control Register..SW_MUX_CTL_PAD_WDOG_ANY SW MUX Control Register */
/*! @{ */

#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_MASK     (0x7U)
#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_SHIFT    (0U)
/*! MUX_MODE - MUX Mode Select Field.
 *  0b000..Select mux mode: ALT0 mux port: GPIO2_IO14 of instance: gpio2
 *  0b001..Select mux mode: ALT1 mux port: LPUART3_TX of instance: lpuart3
 *  0b010..Select mux mode: ALT2 mux port: MEDIAMIX_CAM_DATA06 of instance: mediamix
 *  0b011..Select mux mode: ALT3 mux port: MEDIAMIX_DISP_DATA10 of instance: mediamix
 *  0b100..Select mux mode: ALT4 mux port: LPSPI8_SOUT of instance: lpspi8
 *  0b101..Select mux mode: ALT5 mux port: LPUART8_CTS_B of instance: lpuart8
 *  0b110..Select mux mode: ALT6 mux port: LPUART4_TX of instance: lpuart4
 *  0b111..Select mux mode: ALT7 mux port: FLEXIO1_FLEXIO14 of instance: flexio1
 */
#define IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE(x)       (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_MUX_MODE_MASK)

#define IOMUXC1_SW_MUX_CTL_PAD_SION_MASK         (0x10U)
#define IOMUXC1_SW_MUX_CTL_PAD_SION_SHIFT        (4U)
/*! SION - Software Input On Field.
 *  0b0..Input Path is determined by functionality
 *  0b1..Force input path of pad DAP_TDO_TRACESWO
 */
#define IOMUXC1_SW_MUX_CTL_PAD_SION(x)           (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_MUX_CTL_PAD_SION_SHIFT)) & IOMUXC1_SW_MUX_CTL_PAD_SION_MASK)
/*! @} */

/*! @name SW_PAD_CTL_PAD - SW_PAD_CTL_PAD_DAP_TDI SW PAD Control Register..SW_PAD_CTL_PAD_WDOG_ANY SW PAD Control Register */
/*! @{ */

#define IOMUXC1_SW_PAD_CTL_PAD_DSE_MASK          (0x7EU)
#define IOMUXC1_SW_PAD_CTL_PAD_DSE_SHIFT         (1U)
/*! DSE - Drive Strength Field
 *  0b000000..No drive
 *  0b000001..X1
 *  0b000011..X2
 *  0b000111..X3
 *  0b001111..X4
 *  0b011111..X5
 *  0b111111..X6
 */
#define IOMUXC1_SW_PAD_CTL_PAD_DSE(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_DSE_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_DSE_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_FSEL1_MASK        (0x180U)
#define IOMUXC1_SW_PAD_CTL_PAD_FSEL1_SHIFT       (7U)
/*! FSEL1 - Slew Rate Field
 *  0b00..Slow Slew Rate
 *  0b01..Slightly Slow Slew Rate
 *  0b10..Slightly Fast Slew Rate
 *  0b11..Fast Slew Rate
 */
#define IOMUXC1_SW_PAD_CTL_PAD_FSEL1(x)          (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_FSEL1_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_FSEL1_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_PU_MASK           (0x200U)
#define IOMUXC1_SW_PAD_CTL_PAD_PU_SHIFT          (9U)
/*! PU - Pull Up Field
 *  0b0..No pull up
 *  0b1..Pull up
 */
#define IOMUXC1_SW_PAD_CTL_PAD_PU(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_PU_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_PU_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_PD_MASK           (0x400U)
#define IOMUXC1_SW_PAD_CTL_PAD_PD_SHIFT          (10U)
/*! PD - Pull Down Field
 *  0b0..Not pull down
 *  0b1..Pull down
 */
#define IOMUXC1_SW_PAD_CTL_PAD_PD(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_PD_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_PD_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_OD_MASK           (0x800U)
#define IOMUXC1_SW_PAD_CTL_PAD_OD_SHIFT          (11U)
/*! OD - Open Drain Field
 *  0b0..Open Drain Disable
 *  0b1..Open Drain Enable
 */
#define IOMUXC1_SW_PAD_CTL_PAD_OD(x)             (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_OD_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_OD_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_HYS_MASK          (0x1000U)
#define IOMUXC1_SW_PAD_CTL_PAD_HYS_SHIFT         (12U)
/*! HYS - Schmitt trigger Field
 *  0b0..No Schmitt input
 *  0b1..Schmitt input
 */
#define IOMUXC1_SW_PAD_CTL_PAD_HYS(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_HYS_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_HYS_MASK)

#define IOMUXC1_SW_PAD_CTL_PAD_APC_MASK          (0xFF000000U)
#define IOMUXC1_SW_PAD_CTL_PAD_APC_SHIFT         (24U)
/*! APC - Domain Access Field */
#define IOMUXC1_SW_PAD_CTL_PAD_APC(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SW_PAD_CTL_PAD_APC_SHIFT)) & IOMUXC1_SW_PAD_CTL_PAD_APC_MASK)
/*! @} */

/*! @name SELECT_INPUT - CAN1_IPP_IND_CANRX_SELECT_INPUT DAISY Register..USDHC3_IPP_DAT3_IN_SELECT_INPUT DAISY Register */
/*! @{ */

#define IOMUXC1_SELECT_INPUT_DAISY_MASK          (0x3U)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
#define IOMUXC1_SELECT_INPUT_DAISY_SHIFT         (0U)
/*! DAISY - Selecting Pads Involved in Daisy Chain.
 *  0b00..Selecting Pad: DAP_TDO_TRACESWO for Mode: ALT3
 *  0b01..Selecting Pad: GPIO_IO27 for Mode: ALT2
 *  0b10..Selecting Pad: ENET1_TD2 for Mode: ALT2
 *  0b11..Selecting Pad: SD2_DATA1 for Mode: ALT2
 */
#define IOMUXC1_SELECT_INPUT_DAISY(x)            (((uint32_t)(((uint32_t)(x)) << IOMUXC1_SELECT_INPUT_DAISY_SHIFT)) & IOMUXC1_SELECT_INPUT_DAISY_MASK)  /* Merged from fields with different position or width, of widths (1, 2), largest definition used */
/*! @} */


/*!
 * @}
 */ /* end of group IOMUXC1_Register_Masks */


/*!
 * @}
 */ /* end of group IOMUXC1_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_IOMUXC1_H_ */

