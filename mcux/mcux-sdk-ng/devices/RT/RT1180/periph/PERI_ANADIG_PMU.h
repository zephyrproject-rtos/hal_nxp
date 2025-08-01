/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANADIG_PMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ANADIG_PMU.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG_PMU
 *
 * CMSIS Peripheral Access Layer for ANADIG_PMU
 */

#if !defined(PERI_ANADIG_PMU_H_)
#define PERI_ANADIG_PMU_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- ANADIG_PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_PMU_Peripheral_Access_Layer ANADIG_PMU Peripheral Access Layer
 * @{
 */

/** ANADIG_PMU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[17920];
  __IO uint32_t PMU_BIAS_CTRL;                     /**< PMU_BIAS_CTRL_REGISTER, offset: 0x4600 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PMU_BIAS_CTRL2;                    /**< PMU_BIAS_CTRL2_REGISTER, offset: 0x4610 */
       uint8_t RESERVED_2[44];
  __IO uint32_t PMU_LDO_PLL;                       /**< PMU_LDO_PLL_REGISTER, offset: 0x4640 */
       uint8_t RESERVED_3[188];
  __IO uint32_t PMU_POWER_DETECT_CTRL;             /**< PMU_POWER_DETECT_CTRL_REGISTER, offset: 0x4700 */
       uint8_t RESERVED_4[12];
  __IO uint32_t PMU_REF_CTRL;                      /**< PMU_REF_CTRL_REGISTER, offset: 0x4710 */
} ANADIG_PMU_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_PMU_Register_Masks ANADIG_PMU Register Masks
 * @{
 */

/*! @name PMU_BIAS_CTRL - PMU_BIAS_CTRL_REGISTER */
/*! @{ */

#define ANADIG_PMU_PMU_BIAS_CTRL_WB_CFG_1P8_MASK (0x1FFFU)
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_CFG_1P8_SHIFT (0U)
/*! WB_CFG_1P8 - wb_cfg_1p8 */
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_CFG_1P8(x)   (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL_WB_CFG_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL_WB_CFG_1P8_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL_WB_VDD_SEL_1P8_MASK (0x4000U)
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_VDD_SEL_1P8_SHIFT (14U)
/*! WB_VDD_SEL_1P8 - wb_vdd_sel_1p8
 *  0b0..VDD_LV1
 *  0b1..VDD_LV2
 */
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_VDD_SEL_1P8(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL_WB_VDD_SEL_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL_WB_VDD_SEL_1P8_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL_FBB_M7_STBY_EN_MASK (0x8000U)
#define ANADIG_PMU_PMU_BIAS_CTRL_FBB_M7_STBY_EN_SHIFT (15U)
/*! FBB_M7_STBY_EN - standby enable bit of fbb m7
 *  0b0..FBB_M7 will be still on when gpc give standby request. After the mode is switched to gpc mode, keep this bit as it is.
 *  0b1..FBB_M7 will standby when gpc give standby request.
 */
#define ANADIG_PMU_PMU_BIAS_CTRL_FBB_M7_STBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL_FBB_M7_STBY_EN_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL_FBB_M7_STBY_EN_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL_WB_PW_LVL_1P8_MASK (0xF000000U)
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_PW_LVL_1P8_SHIFT (24U)
/*! WB_PW_LVL_1P8 - wb_pw_lvl_1p8 */
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_PW_LVL_1P8(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL_WB_PW_LVL_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL_WB_PW_LVL_1P8_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL_WB_NW_LVL_1P8_MASK (0xF0000000U)
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_NW_LVL_1P8_SHIFT (28U)
/*! WB_NW_LVL_1P8 - wb_nw_lvl_1p8 */
#define ANADIG_PMU_PMU_BIAS_CTRL_WB_NW_LVL_1P8(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL_WB_NW_LVL_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL_WB_NW_LVL_1P8_MASK)
/*! @} */

/*! @name PMU_BIAS_CTRL2 - PMU_BIAS_CTRL2_REGISTER */
/*! @{ */

#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_PWR_SW_EN_1P8_MASK (0x1000U)
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_PWR_SW_EN_1P8_SHIFT (12U)
/*! WB_PWR_SW_EN_1P8 - MODSEL_wb_tst_md_1p8
 *  0b0..WELL connected to no back-biasing power supplies
 *  0b1..WELL connected to back biasing generators.
 */
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_PWR_SW_EN_1P8(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL2_WB_PWR_SW_EN_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL2_WB_PWR_SW_EN_1P8_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_ADJ_1P8_MASK (0x1FE000U)
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_ADJ_1P8_SHIFT (13U)
/*! WB_ADJ_1P8 - wb_adj_1p8
 *  0b00000000..Cref= 0fF Cspl= 0fF DeltaC= 0fF
 *  0b00000001..Cref= 0fF Cspl= 30fF DeltaC= -30fF
 *  0b00000010..Cref= 0fF Cspl= 43fF DeltaC= -43fF
 *  0b00000011..Cref= 0fF Cspl= 62fF DeltaC=-62fF
 *  0b00000100..Cref= 0fF Cspl=105fF DeltaC=-105fF
 *  0b00000101..Cref= 30fF Cspl= 0fF DeltaC= 30fF
 *  0b00000110..Cref= 30fF Cspl= 43fF DeltaC= -12fF
 *  0b00000111..Cref= 30fF Cspl=105fF DeltaC= -75fF
 *  0b00001000..Cref= 43fF Cspl= 0fF DeltaC= 43fF
 *  0b00001001..Cref= 43fF Cspl= 30fF DeltaC= 13fF
 *  0b00001010..Cref= 43fF Cspl= 62fF DeltaC= -19fF
 *  0b00001011..Cref= 62fF Cspl= 0fF DeltaC= 62fF
 *  0b00001100..Cref= 62fF Cspl= 43fF DeltaC= 19fF
 *  0b00001101..Cref=105fF Cspl= 0fF DeltaC= 105fF
 *  0b00001110..Cref=105fF Cspl=30fF DeltaC= 75fF
 *  0b00001111..Cref=0fF Cspl=0fF DeltaC= 0fF
 */
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_ADJ_1P8(x)  (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL2_WB_ADJ_1P8_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL2_WB_ADJ_1P8_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_EN_MASK     (0x1000000U)
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_EN_SHIFT    (24U)
/*! WB_EN - wb_en
 *  0b0..disable
 *  0b1..Enable
 */
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_EN(x)       (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL2_WB_EN_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL2_WB_EN_MASK)

#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_OK_MASK     (0x4000000U)
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_OK_SHIFT    (26U)
/*! WB_OK - Digital Output pin.
 *  0b0..Regulator is unstable.
 *  0b1..Regulator is stable.
 */
#define ANADIG_PMU_PMU_BIAS_CTRL2_WB_OK(x)       (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_BIAS_CTRL2_WB_OK_SHIFT)) & ANADIG_PMU_PMU_BIAS_CTRL2_WB_OK_MASK)
/*! @} */

/*! @name PMU_LDO_PLL - PMU_LDO_PLL_REGISTER */
/*! @{ */

#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_CONTROL_MODE_MASK (0x2U)
#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_CONTROL_MODE_SHIFT (1U)
/*! LDO_PLL_CONTROL_MODE - LDO_PLL_CONTROL_MODE
 *  0b0..SW Control
 *  0b1..HW Control
 */
#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_CONTROL_MODE_SHIFT)) & ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_CONTROL_MODE_MASK)

#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_STBY_EN_MASK (0x4U)
#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_STBY_EN_SHIFT (2U)
/*! LDO_PLL_STBY_EN - standby enable bit of ldopll
 *  0b0..phy_ldo will be still on when gpc gives standby request. After the mode is switched to gpc mode, keep this bit as it is.
 *  0b1..phy_ldo will standby when gpc give standby request
 */
#define ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_STBY_EN(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_STBY_EN_SHIFT)) & ANADIG_PMU_PMU_LDO_PLL_LDO_PLL_STBY_EN_MASK)
/*! @} */

/*! @name PMU_POWER_DETECT_CTRL - PMU_POWER_DETECT_CTRL_REGISTER */
/*! @{ */

#define ANADIG_PMU_PMU_POWER_DETECT_CTRL_CKGB_AON1P0_MASK (0x100U)
#define ANADIG_PMU_PMU_POWER_DETECT_CTRL_CKGB_AON1P0_SHIFT (8U)
/*! CKGB_AON1P0 - ckgb_aon1p0
 *  0b0..To disable lpsr_1p0, ckgb need to be disabled first.
 *  0b1..After lpsr_1p0 start up, wait for 1ms and then set ckgb bit.
 */
#define ANADIG_PMU_PMU_POWER_DETECT_CTRL_CKGB_AON1P0(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_POWER_DETECT_CTRL_CKGB_AON1P0_SHIFT)) & ANADIG_PMU_PMU_POWER_DETECT_CTRL_CKGB_AON1P0_MASK)
/*! @} */

/*! @name PMU_REF_CTRL - PMU_REF_CTRL_REGISTER */
/*! @{ */

#define ANADIG_PMU_PMU_REF_CTRL_REF_CONTROL_MODE_MASK (0x8U)
#define ANADIG_PMU_PMU_REF_CTRL_REF_CONTROL_MODE_SHIFT (3U)
/*! REF_CONTROL_MODE - REF_CONTROL_MODE
 *  0b0..SW Control
 *  0b1..HW Control
 */
#define ANADIG_PMU_PMU_REF_CTRL_REF_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_REF_CTRL_REF_CONTROL_MODE_SHIFT)) & ANADIG_PMU_PMU_REF_CTRL_REF_CONTROL_MODE_MASK)

#define ANADIG_PMU_PMU_REF_CTRL_EN_PLL_VOL_REF_BUFFER_MASK (0x10U)
#define ANADIG_PMU_PMU_REF_CTRL_EN_PLL_VOL_REF_BUFFER_SHIFT (4U)
/*! EN_PLL_VOL_REF_BUFFER - en_pll_vol_ref_buffer */
#define ANADIG_PMU_PMU_REF_CTRL_EN_PLL_VOL_REF_BUFFER(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_REF_CTRL_EN_PLL_VOL_REF_BUFFER_SHIFT)) & ANADIG_PMU_PMU_REF_CTRL_EN_PLL_VOL_REF_BUFFER_MASK)

#define ANADIG_PMU_PMU_REF_CTRL_REF_STBY_EN_MASK (0x40U)
#define ANADIG_PMU_PMU_REF_CTRL_REF_STBY_EN_SHIFT (6U)
/*! REF_STBY_EN - standby enable bit of reftop */
#define ANADIG_PMU_PMU_REF_CTRL_REF_STBY_EN(x)   (((uint32_t)(((uint32_t)(x)) << ANADIG_PMU_PMU_REF_CTRL_REF_STBY_EN_SHIFT)) & ANADIG_PMU_PMU_REF_CTRL_REF_STBY_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_PMU_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_PMU_Peripheral_Access_Layer */


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


#endif  /* PERI_ANADIG_PMU_H_ */

