/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OPAMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-12-10)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OPAMP.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OPAMP
 *
 * CMSIS Peripheral Access Layer for OPAMP
 */

#if !defined(PERI_OPAMP_H_)
#define PERI_OPAMP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OPAMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OPAMP_Peripheral_Access_Layer OPAMP Peripheral Access Layer
 * @{
 */

/** OPAMP - Size of Registers Arrays */
#define OPAMP_CFGX_COUNT                          4u

/** OPAMP - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL;                              /**< Control register, offset: 0x0 */
  __IO uint16_t STAT;                              /**< Status register, offset: 0x1 */
  __IO uint16_t CFG[OPAMP_CFGX_COUNT];             /**< Configuration register, array offset: 0x2, array step: 0x1 */
} OPAMP_Type;

/* ----------------------------------------------------------------------------
   -- OPAMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OPAMP_Register_Masks OPAMP Register Masks
 * @{
 */

/*! @name CTRL - Control register */
/*! @{ */

#define OPAMP_CTRL_EN_MASK                       (0x1U)
#define OPAMP_CTRL_EN_SHIFT                      (0U)
/*! EN - Enables OPAMP and switch registers
 *  0b0..OPAMP is disabled. CTRL[WP], CTRL[LDOK], STAT[WR_CLR] and STAT[LDCMF] are not readable and writable.
 *  0b1..OPAMP is enabled. CTRL[WP], CTRL[LDOK], STAT[WP_CLR] and STAT[LDCMF] are readable and writable.
 */
#define OPAMP_CTRL_EN(x)                         (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_EN_SHIFT)) & OPAMP_CTRL_EN_MASK)

#define OPAMP_CTRL_PMOD_MASK                     (0x2U)
#define OPAMP_CTRL_PMOD_SHIFT                    (1U)
/*! PMOD - Power Mode Select
 *  0b0..Low power mode.
 *  0b1..High speed mode.
 */
#define OPAMP_CTRL_PMOD(x)                       (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_PMOD_SHIFT)) & OPAMP_CTRL_PMOD_MASK)

#define OPAMP_CTRL_LDOK_MASK                     (0x4U)
#define OPAMP_CTRL_LDOK_SHIFT                    (2U)
/*! LDOK - Load Okay
 *  0b0..Values in CFGx registers are not ready to be loaded into their buffers.
 *  0b1..Values in CFGx registers are ready to be loaded into their buffers.
 */
#define OPAMP_CTRL_LDOK(x)                       (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_LDOK_SHIFT)) & OPAMP_CTRL_LDOK_MASK)

#define OPAMP_CTRL_LDMOD_MASK                    (0x8U)
#define OPAMP_CTRL_LDMOD_SHIFT                   (3U)
/*! LDMOD - Load Mode Select
 *  0b0..Values of CFGx registers are loaded into the corresponding buffers cfg_buf_x when cfg_set_opt[1:0] signal
 *       is changed and CTRL[LDOK] has been set to 1. CTRL[LDOK] is automatically cleared after CFGx register
 *       values are loaded into their buffers.
 *  0b1..Values of CFGx registers are loaded into the corresponding buffers cfg_buf_x when CTRL[LDOK] is set to 1.
 *       CTRL[LDOK] is automatically cleared after CFGx register values are loaded into their buffers.
 */
#define OPAMP_CTRL_LDMOD(x)                      (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_LDMOD_SHIFT)) & OPAMP_CTRL_LDMOD_MASK)

#define OPAMP_CTRL_WP_MASK                       (0x80U)
#define OPAMP_CTRL_WP_SHIFT                      (7U)
/*! WP - Register Write Protection
 *  0b0..Write and read.
 *  0b1..Read only.
 */
#define OPAMP_CTRL_WP(x)                         (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_WP_SHIFT)) & OPAMP_CTRL_WP_MASK)

#define OPAMP_CTRL_CONFIG_SEL_MASK               (0x300U)
#define OPAMP_CTRL_CONFIG_SEL_SHIFT              (8U)
/*! CONFIG_SEL - Configuration register software selection
 *  0b00..CFG0 activated
 *  0b01..CFG1 activated
 *  0b10..CFG2 activated
 *  0b11..CFG3 activated
 */
#define OPAMP_CTRL_CONFIG_SEL(x)                 (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_CONFIG_SEL_SHIFT)) & OPAMP_CTRL_CONFIG_SEL_MASK)

#define OPAMP_CTRL_CFG_SLL_MASK                  (0x1800U)
#define OPAMP_CTRL_CFG_SLL_SHIFT                 (11U)
/*! CFG_SLL - Configuration register selection source signal low select
 *  0b00..CONFIG_SEL[0] bit selects configuration register.
 *  0b01..External signal CFGSELA0 selects configuration register.
 *  0b10..External signal CFGSELB0 selects configuration register.
 *  0b11..External signal CFGSELC0 selects configuration register.
 */
#define OPAMP_CTRL_CFG_SLL(x)                    (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_CFG_SLL_SHIFT)) & OPAMP_CTRL_CFG_SLL_MASK)

#define OPAMP_CTRL_CFG_SLH_MASK                  (0x6000U)
#define OPAMP_CTRL_CFG_SLH_SHIFT                 (13U)
/*! CFG_SLH - Configuration register selection source signal high select
 *  0b00..CONFIG_SEL[1] bit selects configuration register.
 *  0b01..External signal CFGSELA1 selects configuration register.
 *  0b10..External signal CFGSELB1 selects configuration register.
 *  0b11..External signal CFGSELC1 selects configuration register.
 */
#define OPAMP_CTRL_CFG_SLH(x)                    (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_CFG_SLH_SHIFT)) & OPAMP_CTRL_CFG_SLH_MASK)

#define OPAMP_CTRL_LDCMIE_MASK                   (0x8000U)
#define OPAMP_CTRL_LDCMIE_SHIFT                  (15U)
/*! LDCMIE - Load Completion Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define OPAMP_CTRL_LDCMIE(x)                     (((uint16_t)(((uint16_t)(x)) << OPAMP_CTRL_LDCMIE_SHIFT)) & OPAMP_CTRL_LDCMIE_MASK)
/*! @} */

/*! @name STAT - Status register */
/*! @{ */

#define OPAMP_STAT_CURRENT_CFG_MASK              (0x3U)
#define OPAMP_STAT_CURRENT_CFG_SHIFT             (0U)
/*! CURRENT_CFG - Current effective Configuration register */
#define OPAMP_STAT_CURRENT_CFG(x)                (((uint16_t)(((uint16_t)(x)) << OPAMP_STAT_CURRENT_CFG_SHIFT)) & OPAMP_STAT_CURRENT_CFG_MASK)

#define OPAMP_STAT_WP_CLR_MASK                   (0xCU)
#define OPAMP_STAT_WP_CLR_SHIFT                  (2U)
/*! WP_CLR - Clears the CTRL[WP] bit */
#define OPAMP_STAT_WP_CLR(x)                     (((uint16_t)(((uint16_t)(x)) << OPAMP_STAT_WP_CLR_SHIFT)) & OPAMP_STAT_WP_CLR_MASK)

#define OPAMP_STAT_LDCMF_MASK                    (0x8000U)
#define OPAMP_STAT_LDCMF_SHIFT                   (15U)
/*! LDCMF - Load Completion Flag */
#define OPAMP_STAT_LDCMF(x)                      (((uint16_t)(((uint16_t)(x)) << OPAMP_STAT_LDCMF_SHIFT)) & OPAMP_STAT_LDCMF_MASK)
/*! @} */

/*! @name CFG - Configuration register */
/*! @{ */

#define OPAMP_CFG_GAIN_EN_MASK                   (0x1U)
#define OPAMP_CFG_GAIN_EN_SHIFT                  (0U)
/*! GAIN_EN - Gain Enable
 *  0b0..Internal gain is disabled.
 *  0b1..Internal gain is enabled.
 */
#define OPAMP_CFG_GAIN_EN(x)                     (((uint16_t)(((uint16_t)(x)) << OPAMP_CFG_GAIN_EN_SHIFT)) & OPAMP_CFG_GAIN_EN_MASK)

#define OPAMP_CFG_GAIN_SEL_MASK                  (0x6U)
#define OPAMP_CFG_GAIN_SEL_SHIFT                 (1U)
/*! GAIN_SEL - Gain Selection
 *  0b00..Gain value 2X.
 *  0b01..Gain value 4X.
 *  0b10..Gain value 8X.
 *  0b11..Gain value 16X.
 */
#define OPAMP_CFG_GAIN_SEL(x)                    (((uint16_t)(((uint16_t)(x)) << OPAMP_CFG_GAIN_SEL_SHIFT)) & OPAMP_CFG_GAIN_SEL_MASK)

#define OPAMP_CFG_VNEG_EN_MASK                   (0x8U)
#define OPAMP_CFG_VNEG_EN_SHIFT                  (3U)
/*! VNEG_EN - External VNEG Enable */
#define OPAMP_CFG_VNEG_EN(x)                     (((uint16_t)(((uint16_t)(x)) << OPAMP_CFG_VNEG_EN_SHIFT)) & OPAMP_CFG_VNEG_EN_MASK)

#define OPAMP_CFG_VNEG_SEL_MASK                  (0x30U)
#define OPAMP_CFG_VNEG_SEL_SHIFT                 (4U)
/*! VNEG_SEL - VNEGx Selection
 *  0b00..Selects VNEG0.
 *  0b01..Selects VNEG1.
 *  0b10..Selects VNEG2.
 *  0b11..Selects VNEG3.
 */
#define OPAMP_CFG_VNEG_SEL(x)                    (((uint16_t)(((uint16_t)(x)) << OPAMP_CFG_VNEG_SEL_SHIFT)) & OPAMP_CFG_VNEG_SEL_MASK)

#define OPAMP_CFG_VPOS_SEL_MASK                  (0xC0U)
#define OPAMP_CFG_VPOS_SEL_SHIFT                 (6U)
/*! VPOS_SEL - VPOS Selection
 *  0b00..Selects VPOS0.
 *  0b01..Selects VPOS1.
 *  0b10..Selects VPOS2.
 *  0b11..Selects VPOS3.
 */
#define OPAMP_CFG_VPOS_SEL(x)                    (((uint16_t)(((uint16_t)(x)) << OPAMP_CFG_VPOS_SEL_SHIFT)) & OPAMP_CFG_VPOS_SEL_MASK)
/*! @} */

/* The count of OPAMP_CFG */
#define OPAMP_CFG_COUNT                          (4U)


/*!
 * @}
 */ /* end of group OPAMP_Register_Masks */


/*!
 * @}
 */ /* end of group OPAMP_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OPAMP_H_ */

