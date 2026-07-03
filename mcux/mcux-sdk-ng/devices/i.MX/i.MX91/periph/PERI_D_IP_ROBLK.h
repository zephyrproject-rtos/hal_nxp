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
**         CMSIS Peripheral Access Layer for D_IP_ROBLK
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
 * @file PERI_D_IP_ROBLK.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for D_IP_ROBLK
 *
 * CMSIS Peripheral Access Layer for D_IP_ROBLK
 */

#if !defined(PERI_D_IP_ROBLK_H_)
#define PERI_D_IP_ROBLK_H_                       /**< Symbol preventing repeated inclusion */

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
   -- D_IP_ROBLK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup D_IP_ROBLK_Peripheral_Access_Layer D_IP_ROBLK Peripheral Access Layer
 * @{
 */

/** D_IP_ROBLK - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL1;                             /**< Control Register CTRL, offset: 0x0 */
  __IO uint32_t CTRL2;                             /**< Control Register CTRL2, offset: 0x4 */
} D_IP_ROBLK_Type;

/* ----------------------------------------------------------------------------
   -- D_IP_ROBLK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup D_IP_ROBLK_Register_Masks D_IP_ROBLK Register Masks
 * @{
 */

/*! @name CTRL1 - Control Register CTRL */
/*! @{ */

#define D_IP_ROBLK_CTRL1_EN_MASK                 (0x3FFFFU)
#define D_IP_ROBLK_CTRL1_EN_SHIFT                (0U)
/*! EN - 18 Dut Ring Oscillator enable */
#define D_IP_ROBLK_CTRL1_EN(x)                   (((uint32_t)(((uint32_t)(x)) << D_IP_ROBLK_CTRL1_EN_SHIFT)) & D_IP_ROBLK_CTRL1_EN_MASK)

#define D_IP_ROBLK_CTRL1_DIV_MASK                (0x7000000U)
#define D_IP_ROBLK_CTRL1_DIV_SHIFT               (24U)
/*! DIV - Programmable Divider bits
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 *  0b110..Divide by 64
 *  0b111..Divide by 128
 */
#define D_IP_ROBLK_CTRL1_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << D_IP_ROBLK_CTRL1_DIV_SHIFT)) & D_IP_ROBLK_CTRL1_DIV_MASK)
/*! @} */

/*! @name CTRL2 - Control Register CTRL2 */
/*! @{ */

#define D_IP_ROBLK_CTRL2_CLKGEN_MASK             (0x3FFFFU)
#define D_IP_ROBLK_CTRL2_CLKGEN_SHIFT            (0U)
/*! CLKGEN - 18 Dut Ring Oscillator (RO) Clock Gate enable */
#define D_IP_ROBLK_CTRL2_CLKGEN(x)               (((uint32_t)(((uint32_t)(x)) << D_IP_ROBLK_CTRL2_CLKGEN_SHIFT)) & D_IP_ROBLK_CTRL2_CLKGEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group D_IP_ROBLK_Register_Masks */


/*!
 * @}
 */ /* end of group D_IP_ROBLK_Peripheral_Access_Layer */


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


#endif  /* PERI_D_IP_ROBLK_H_ */
