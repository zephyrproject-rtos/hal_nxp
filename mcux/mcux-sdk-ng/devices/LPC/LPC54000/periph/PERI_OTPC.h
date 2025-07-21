/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OTPC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OTPC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OTPC
 *
 * CMSIS Peripheral Access Layer for OTPC
 */

#if !defined(PERI_OTPC_H_)
#define PERI_OTPC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- OTPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTPC_Peripheral_Access_Layer OTPC Peripheral Access Layer
 * @{
 */

/** OTPC - Size of Registers Arrays */
#define OTPC_AESKEY_COUNT                         8u

/** OTPC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __I  uint32_t AESKEY[OTPC_AESKEY_COUNT];         /**< Register for reading the AES key., array offset: 0x10, array step: 0x4 */
  __I  uint32_t ECRP;                              /**< ECRP options., offset: 0x30 */
       uint8_t RESERVED_1[4];
  __I  uint32_t USER0;                             /**< User application specific options., offset: 0x38 */
  __I  uint32_t USER1;                             /**< User application specific options., offset: 0x3C */
} OTPC_Type;

/* ----------------------------------------------------------------------------
   -- OTPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTPC_Register_Masks OTPC Register Masks
 * @{
 */

/*! @name AESKEY - Register for reading the AES key. */
/*! @{ */

#define OTPC_AESKEY_KEY_MASK                     (0xFFFFFFFFU)
#define OTPC_AESKEY_KEY_SHIFT                    (0U)
/*! KEY - AES key. */
#define OTPC_AESKEY_KEY(x)                       (((uint32_t)(((uint32_t)(x)) << OTPC_AESKEY_KEY_SHIFT)) & OTPC_AESKEY_KEY_MASK)
/*! @} */

/*! @name ECRP - ECRP options. */
/*! @{ */

#define OTPC_ECRP_SWD_DISABLE_L_MASK             (0x8U)
#define OTPC_ECRP_SWD_DISABLE_L_SHIFT            (3U)
/*! SWD_DISABLE_L - Bits 3 and 10 control the ability to enable and disable SWD. */
#define OTPC_ECRP_SWD_DISABLE_L(x)               (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_SWD_DISABLE_L_SHIFT)) & OTPC_ECRP_SWD_DISABLE_L_MASK)

#define OTPC_ECRP_CRP_MASS_ERASE_DISABLE_MASK    (0x10U)
#define OTPC_ECRP_CRP_MASS_ERASE_DISABLE_SHIFT   (4U)
/*! CRP_MASS_ERASE_DISABLE - Disable or enable CRP mass erase. */
#define OTPC_ECRP_CRP_MASS_ERASE_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_CRP_MASS_ERASE_DISABLE_SHIFT)) & OTPC_ECRP_CRP_MASS_ERASE_DISABLE_MASK)

#define OTPC_ECRP_IAP_PROTECTION_ENABLE_MASK     (0x20U)
#define OTPC_ECRP_IAP_PROTECTION_ENABLE_SHIFT    (5U)
/*! IAP_PROTECTION_ENABLE - This bit controls the ability to enable checking for ECRP in IAP functions. */
#define OTPC_ECRP_IAP_PROTECTION_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_IAP_PROTECTION_ENABLE_SHIFT)) & OTPC_ECRP_IAP_PROTECTION_ENABLE_MASK)

#define OTPC_ECRP_CRP_ISP_DISABLE_PIN_MASK       (0x40U)
#define OTPC_ECRP_CRP_ISP_DISABLE_PIN_SHIFT      (6U)
/*! CRP_ISP_DISABLE_PIN - This bit controls the ability to enter ISP mode using the ISP pin. */
#define OTPC_ECRP_CRP_ISP_DISABLE_PIN(x)         (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_CRP_ISP_DISABLE_PIN_SHIFT)) & OTPC_ECRP_CRP_ISP_DISABLE_PIN_MASK)

#define OTPC_ECRP_CRP_ISP_DISABLE_IAP_MASK       (0x80U)
#define OTPC_ECRP_CRP_ISP_DISABLE_IAP_SHIFT      (7U)
/*! CRP_ISP_DISABLE_IAP - This bit controls the ability to re-invoke ISP using IAP routines. */
#define OTPC_ECRP_CRP_ISP_DISABLE_IAP(x)         (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_CRP_ISP_DISABLE_IAP_SHIFT)) & OTPC_ECRP_CRP_ISP_DISABLE_IAP_MASK)

#define OTPC_ECRP_CRP_ALLOW_ZERO_MASK            (0x200U)
#define OTPC_ECRP_CRP_ALLOW_ZERO_SHIFT           (9U)
/*! CRP_ALLOW_ZERO - This bit controls how 0 is treated when read as a ECRP value.. */
#define OTPC_ECRP_CRP_ALLOW_ZERO(x)              (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_CRP_ALLOW_ZERO_SHIFT)) & OTPC_ECRP_CRP_ALLOW_ZERO_MASK)

#define OTPC_ECRP_SWD_DISABLE_H_MASK             (0x400U)
#define OTPC_ECRP_SWD_DISABLE_H_SHIFT            (10U)
/*! SWD_DISABLE_H - Bits 10 and 3 control the ability to enable and disable SWD. */
#define OTPC_ECRP_SWD_DISABLE_H(x)               (((uint32_t)(((uint32_t)(x)) << OTPC_ECRP_SWD_DISABLE_H_SHIFT)) & OTPC_ECRP_SWD_DISABLE_H_MASK)
/*! @} */

/*! @name USER0 - User application specific options. */
/*! @{ */

#define OTPC_USER0_USER0_MASK                    (0xFFFFFFFFU)
#define OTPC_USER0_USER0_SHIFT                   (0U)
/*! USER0 - User application specific option. */
#define OTPC_USER0_USER0(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_USER0_USER0_SHIFT)) & OTPC_USER0_USER0_MASK)
/*! @} */

/*! @name USER1 - User application specific options. */
/*! @{ */

#define OTPC_USER1_USER1_MASK                    (0xFFFFFFFFU)
#define OTPC_USER1_USER1_SHIFT                   (0U)
/*! USER1 - User application specific option. */
#define OTPC_USER1_USER1(x)                      (((uint32_t)(((uint32_t)(x)) << OTPC_USER1_USER1_SHIFT)) & OTPC_USER1_USER1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OTPC_Register_Masks */


/*!
 * @}
 */ /* end of group OTPC_Peripheral_Access_Layer */


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


#endif  /* PERI_OTPC_H_ */

