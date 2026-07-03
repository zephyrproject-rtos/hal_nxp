/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_DDRMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_DDRMIX.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_DDRMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_DDRMIX
 */

#if !defined(PERI_BLK_CTRL_DDRMIX_H_)
#define PERI_BLK_CTRL_DDRMIX_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- BLK_CTRL_DDRMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_DDRMIX_Peripheral_Access_Layer BLK_CTRL_DDRMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_DDRMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t HWFFC_CTRL;                        /**< DDRPHY DfiClk, DflCtlClk HWFFC Control, offset: 0x0 */
  __IO uint32_t CA55_SEL_CTRL;                     /**< CA55 Arm PLL, Anamix PLL Observe Select, offset: 0x4 */
  __IO uint32_t VREF_PSW_CTRL;                     /**< DRAM_VREF power switch, offset: 0x8 */
  __IO uint32_t DDRC_STOP_CTRL;                    /**< DDR Controller ipg_stop SW control, offset: 0xC */
  __IO uint32_t AUTO_CG_CTRL;                      /**< DDR Controller automatic clock gating, offset: 0x10 */
  __IO uint32_t SSI_LP_CTRL;                       /**< DDRMIX SSI Slave low power signal control, offset: 0x14 */
} BLK_CTRL_DDRMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_DDRMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_DDRMIX_Register_Masks BLK_CTRL_DDRMIX Register Masks
 * @{
 */

/*! @name HWFFC_CTRL - DDRPHY DfiClk, DflCtlClk HWFFC Control */
/*! @{ */

#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK (0x1U)
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT (0U)
/*! HWFFC_EN - DDRPHY DfiClk, DfiCtlClk HWFFC Enable
 *  0b0..DDRPHY HWFFC is disabled
 *  0b1..DDRPHY HWFFC is enabled
 */
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_SHIFT)) & BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_EN_MASK)

#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK (0x2U)
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT (1U)
/*! HWFFC_SEL - DDRPHY DfiClk, DfiCtlClk HWFFC Select
 *  0b0..Normal clock is selected
 *  0b1..Div2 frequency clock is selected
 */
#define BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_SHIFT)) & BLK_CTRL_DDRMIX_HWFFC_CTRL_HWFFC_SEL_MASK)
/*! @} */

/*! @name CA55_SEL_CTRL - CA55 Arm PLL, Anamix PLL Observe Select */
/*! @{ */

#define BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_MASK (0x3U)
#define BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_SHIFT (0U)
/*! CA55_SEL - CA55 Arm PLL/Anamix PLL output select into DDRPHY
 *  0b00..Normal DfiClk from DRAM PLL is selected
 *  0b01..Anamix PLL output is selected
 *  0b10..Normal DfiClk from DRAM PLL is selected
 *  0b11..CA55 mix Arm PLL is selected
 */
#define BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_SHIFT)) & BLK_CTRL_DDRMIX_CA55_SEL_CTRL_CA55_SEL_MASK)
/*! @} */

/*! @name VREF_PSW_CTRL - DRAM_VREF power switch */
/*! @{ */

#define BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_MASK (0x1U)
#define BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_SHIFT (0U)
/*! VREF_PSW - DDRPHY DRAM_VREF Power Switch
 *  0b0..Power switch is closed to prevent leakage
 *  0b1..Power switch is opened and is set together with DDRPHY[VrefInGlobal]
 */
#define BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_SHIFT)) & BLK_CTRL_DDRMIX_VREF_PSW_CTRL_VREF_PSW_MASK)
/*! @} */

/*! @name DDRC_STOP_CTRL - DDR Controller ipg_stop SW control */
/*! @{ */

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK (0x1U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT (0U)
/*! DDRC_STOP - DDR Controller ipg_stop
 *  0b0..Clear DDR Controller ipg_stop signal
 *  0b1..Set DDR Controller ipg_stop signal
 */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_MASK)

#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK (0x2U)
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT (1U)
/*! DDRC_STOP_ACK - DDR Controller ipg_stop_ack
 *  0b0..DDR Controller ipg_stop_ack is a 0
 *  0b1..DDR Controller ipg_stop_ack is a 1
 */
#define BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_SHIFT)) & BLK_CTRL_DDRMIX_DDRC_STOP_CTRL_DDRC_STOP_ACK_MASK)
/*! @} */

/*! @name AUTO_CG_CTRL - DDR Controller automatic clock gating */
/*! @{ */

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK (0xFFFFU)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT (0U)
/*! SSI_IDLE_STRAP - SSI Idle Strap */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_SSI_IDLE_STRAP_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK (0x10000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT (16U)
/*! AUTO_CG_ENA - DDR Controller automatic clock gating enable
 *  0b0..DDR Controller automatic clock gating is disabled
 *  0b1..DDR Controller automatic clock gating is enabled
 */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_AUTO_CG_ENA_MASK)

#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK (0x20000U)
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT (17U)
/*! HWFFC_ACG_FORCE_B - DDR Controller hwffc and auto CG send ipg_stop allow
 *  0b0..DDR Controller hwffc and auto CG cannot send ipg_stop
 *  0b1..DDR Controller hwffc and auto CG can send ipg_stop
 */
#define BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_SHIFT)) & BLK_CTRL_DDRMIX_AUTO_CG_CTRL_HWFFC_ACG_FORCE_B_MASK)
/*! @} */

/*! @name SSI_LP_CTRL - DDRMIX SSI Slave low power signal control */
/*! @{ */

#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_ISO_CTRL_MASK (0x1U)
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_ISO_CTRL_SHIFT (0U)
/*! SSI_ISO_CTRL - DDRMIX SSI isolation mode control
 *  0b0..in normal mode
 *  0b1..enter pause mode
 */
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_ISO_CTRL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_ISO_CTRL_SHIFT)) & BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_ISO_CTRL_MASK)

#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_POW_CTRL_MASK (0x2U)
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_POW_CTRL_SHIFT (1U)
/*! SSI_POW_CTRL - DDRMIX SSI power control
 *  0b0..enter no power mode for SSI
 *  0b1..power mode for SSI
 */
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_POW_CTRL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_POW_CTRL_SHIFT)) & BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_POW_CTRL_MASK)

#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_IDLE_MASK (0x4U)
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_IDLE_SHIFT (2U)
/*! SSI_IDLE - DDRMIX SSI idle signal
 *  0b0..means SSI is not idle
 *  0b1..means SSI is idle
 */
#define BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_IDLE(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_IDLE_SHIFT)) & BLK_CTRL_DDRMIX_SSI_LP_CTRL_SSI_IDLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_DDRMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_DDRMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_DDRMIX_H_ */
