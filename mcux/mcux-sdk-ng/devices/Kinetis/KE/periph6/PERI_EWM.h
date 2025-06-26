/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 6.0, 2016-09-20
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EWM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**
** ###################################################################
*/

/*!
 * @file EWM.h
 * @version 6.0
 * @date 2016-09-20
 * @brief CMSIS Peripheral Access Layer for EWM
 *
 * CMSIS Peripheral Access Layer for EWM
 */

#if !defined(EWM_H_)
#define EWM_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
       uint8_t RESERVED_0[1];
  __IO uint8_t CLKPRESCALER;                       /**< Clock Prescaler Register, offset: 0x5 */
} EWM_Type;

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define EWM_CTRL_EWMEN_MASK                      (0x1U)
#define EWM_CTRL_EWMEN_SHIFT                     (0U)
/*! EWMEN - EWM enable. */
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_EWMEN_SHIFT)) & EWM_CTRL_EWMEN_MASK)

#define EWM_CTRL_ASSIN_MASK                      (0x2U)
#define EWM_CTRL_ASSIN_SHIFT                     (1U)
/*! ASSIN - EWM_in's Assertion State Select. */
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_ASSIN_SHIFT)) & EWM_CTRL_ASSIN_MASK)

#define EWM_CTRL_INEN_MASK                       (0x4U)
#define EWM_CTRL_INEN_SHIFT                      (2U)
/*! INEN - Input Enable. */
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INEN_SHIFT)) & EWM_CTRL_INEN_MASK)

#define EWM_CTRL_INTEN_MASK                      (0x8U)
#define EWM_CTRL_INTEN_SHIFT                     (3U)
/*! INTEN - Interrupt Enable. */
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INTEN_SHIFT)) & EWM_CTRL_INTEN_MASK)
/*! @} */

/*! @name SERV - Service Register */
/*! @{ */

#define EWM_SERV_SERVICE_MASK                    (0xFFU)
#define EWM_SERV_SERVICE_SHIFT                   (0U)
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x)) << EWM_SERV_SERVICE_SHIFT)) & EWM_SERV_SERVICE_MASK)
/*! @} */

/*! @name CMPL - Compare Low Register */
/*! @{ */

#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPL_COMPAREL_SHIFT)) & EWM_CMPL_COMPAREL_MASK)
/*! @} */

/*! @name CMPH - Compare High Register */
/*! @{ */

#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPH_COMPAREH_SHIFT)) & EWM_CMPH_COMPAREH_MASK)
/*! @} */

/*! @name CLKPRESCALER - Clock Prescaler Register */
/*! @{ */

#define EWM_CLKPRESCALER_CLK_DIV_MASK            (0xFFU)
#define EWM_CLKPRESCALER_CLK_DIV_SHIFT           (0U)
#define EWM_CLKPRESCALER_CLK_DIV(x)              (((uint8_t)(((uint8_t)(x)) << EWM_CLKPRESCALER_CLK_DIV_SHIFT)) & EWM_CLKPRESCALER_CLK_DIV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EWM_Register_Masks */


/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */


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


#endif  /* EWM_H_ */

