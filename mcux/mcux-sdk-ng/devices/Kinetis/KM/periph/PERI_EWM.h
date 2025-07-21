/*
** ###################################################################
**     Processors:          MKM14Z128ACHH5
**                          MKM14Z64ACHH5
**                          MKM33Z128ACLH5
**                          MKM33Z128ACLL5
**                          MKM33Z64ACLH5
**                          MKM33Z64ACLL5
**                          MKM34Z128ACLL5
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EWM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2014-07-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EWM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EWM
 *
 * CMSIS Peripheral Access Layer for EWM
 */

#if !defined(PERI_EWM_H_)
#define PERI_EWM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM14Z128ACHH5) || defined(CPU_MKM14Z64ACHH5))
#include "MKM14ZA5_COMMON.h"
#elif (defined(CPU_MKM33Z128ACLH5) || defined(CPU_MKM33Z128ACLL5) || defined(CPU_MKM33Z64ACLH5) || defined(CPU_MKM33Z64ACLL5))
#include "MKM33ZA5_COMMON.h"
#elif (defined(CPU_MKM34Z128ACLL5))
#include "MKM34ZA5_COMMON.h"
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
  __IO uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
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


#endif  /* PERI_EWM_H_ */

