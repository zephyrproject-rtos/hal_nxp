/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 1.0, 2021-01-18
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RF_FMCCFG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file RF_FMCCFG.h
 * @version 1.0
 * @date 2021-01-18
 * @brief CMSIS Peripheral Access Layer for RF_FMCCFG
 *
 * CMSIS Peripheral Access Layer for RF_FMCCFG
 */

#if !defined(RF_FMCCFG_H_)
#define RF_FMCCFG_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
   -- RF_FMCCFG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RF_FMCCFG_Peripheral_Access_Layer RF_FMCCFG Peripheral Access Layer
 * @{
 */

/** RF_FMCCFG - Register Layout Typedef */
typedef struct {
  __IO uint32_t RFMCCFG;                           /**< Radio Flash Memory Controller Configuration Register, offset: 0x0 */
} RF_FMCCFG_Type;

/* ----------------------------------------------------------------------------
   -- RF_FMCCFG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RF_FMCCFG_Register_Masks RF_FMCCFG Register Masks
 * @{
 */

/*! @name RFMCCFG - Radio Flash Memory Controller Configuration Register */
/*! @{ */

#define RF_FMCCFG_RFMCCFG_RFCF0_MASK             (0x3U)
#define RF_FMCCFG_RFMCCFG_RFCF0_SHIFT            (0U)
/*! RFCF0 - Radio Flash Control Field 0 */
#define RF_FMCCFG_RFMCCFG_RFCF0(x)               (((uint32_t)(((uint32_t)(x)) << RF_FMCCFG_RFMCCFG_RFCF0_SHIFT)) & RF_FMCCFG_RFMCCFG_RFCF0_MASK)

#define RF_FMCCFG_RFMCCFG_RFCF1_MASK             (0xCU)
#define RF_FMCCFG_RFMCCFG_RFCF1_SHIFT            (2U)
/*! RFCF1 - Radio Flash Control Field 1 */
#define RF_FMCCFG_RFMCCFG_RFCF1(x)               (((uint32_t)(((uint32_t)(x)) << RF_FMCCFG_RFMCCFG_RFCF1_SHIFT)) & RF_FMCCFG_RFMCCFG_RFCF1_MASK)

#define RF_FMCCFG_RFMCCFG_RFCF2_MASK             (0x70U)
#define RF_FMCCFG_RFMCCFG_RFCF2_SHIFT            (4U)
/*! RFCF2 - Radio Flash Control Field 2 */
#define RF_FMCCFG_RFMCCFG_RFCF2(x)               (((uint32_t)(((uint32_t)(x)) << RF_FMCCFG_RFMCCFG_RFCF2_SHIFT)) & RF_FMCCFG_RFMCCFG_RFCF2_MASK)

#define RF_FMCCFG_RFMCCFG_RFCF3_MASK             (0xF00U)
#define RF_FMCCFG_RFMCCFG_RFCF3_SHIFT            (8U)
/*! RFCF3 - Radio Flash Control Field 3 */
#define RF_FMCCFG_RFMCCFG_RFCF3(x)               (((uint32_t)(((uint32_t)(x)) << RF_FMCCFG_RFMCCFG_RFCF3_SHIFT)) & RF_FMCCFG_RFMCCFG_RFCF3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RF_FMCCFG_Register_Masks */


/*!
 * @}
 */ /* end of group RF_FMCCFG_Peripheral_Access_Layer */


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


#endif  /* RF_FMCCFG_H_ */

