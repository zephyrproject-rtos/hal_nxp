/*
** ###################################################################
**     Processors:          LPC54005JBD100
**                          LPC54005JET100
**                          LPC54016JBD100
**                          LPC54016JBD208
**                          LPC54016JET100
**                          LPC54016JET180
**                          LPC54018JBD208
**                          LPC54018JET180
**                          LPC54S005JBD100
**                          LPC54S005JET100
**                          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**                          LPC54S018JBD208
**                          LPC54S018JET180
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

#if (defined(CPU_LPC54005JBD100) || defined(CPU_LPC54005JET100))
#include "LPC54005_COMMON.h"
#elif (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || defined(CPU_LPC54016JET180))
#include "LPC54016_COMMON.h"
#elif (defined(CPU_LPC54018JBD208) || defined(CPU_LPC54018JET180))
#include "LPC54018_COMMON.h"
#elif (defined(CPU_LPC54S005JBD100) || defined(CPU_LPC54S005JET100))
#include "LPC54S005_COMMON.h"
#elif (defined(CPU_LPC54S016JBD100) || defined(CPU_LPC54S016JBD208) || defined(CPU_LPC54S016JET100) || defined(CPU_LPC54S016JET180))
#include "LPC54S016_COMMON.h"
#elif (defined(CPU_LPC54S018JBD208) || defined(CPU_LPC54S018JET180))
#include "LPC54S018_COMMON.h"
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

/** OTPC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[48];
  __I  uint32_t BOOTROM;                           /**< Boot ROM control data., offset: 0x30 */
} OTPC_Type;

/* ----------------------------------------------------------------------------
   -- OTPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OTPC_Register_Masks OTPC Register Masks
 * @{
 */

/*! @name BOOTROM - Boot ROM control data. */
/*! @{ */

#define OTPC_BOOTROM_PARITY_MASK                 (0x3U)
#define OTPC_BOOTROM_PARITY_SHIFT                (0U)
/*! PARITY - Parity of bit14 to bit2. */
#define OTPC_BOOTROM_PARITY(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_PARITY_SHIFT)) & OTPC_BOOTROM_PARITY_MASK)

#define OTPC_BOOTROM_SECUREBOOTEN_MASK           (0x4U)
#define OTPC_BOOTROM_SECUREBOOTEN_SHIFT          (2U)
/*! SECUREBOOTEN - Secure boot enable. When set, all images must be signed and/or encrypted. */
#define OTPC_BOOTROM_SECUREBOOTEN(x)             (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_SECUREBOOTEN_SHIFT)) & OTPC_BOOTROM_SECUREBOOTEN_MASK)

#define OTPC_BOOTROM_SECUREBOOTTYPE_MASK         (0x18U)
#define OTPC_BOOTROM_SECUREBOOTTYPE_SHIFT        (3U)
/*! SECUREBOOTTYPE - Secure Boot Type. */
#define OTPC_BOOTROM_SECUREBOOTTYPE(x)           (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_SECUREBOOTTYPE_SHIFT)) & OTPC_BOOTROM_SECUREBOOTTYPE_MASK)

#define OTPC_BOOTROM_SIGNATURE_PREFORMAT_MASK    (0x20U)
#define OTPC_BOOTROM_SIGNATURE_PREFORMAT_SHIFT   (5U)
/*! SIGNATURE_PREFORMAT - Image signature and signature in NXP certificate are pre-formatted. */
#define OTPC_BOOTROM_SIGNATURE_PREFORMAT(x)      (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_SIGNATURE_PREFORMAT_SHIFT)) & OTPC_BOOTROM_SIGNATURE_PREFORMAT_MASK)

#define OTPC_BOOTROM_SWDEN0_MASK                 (0x40U)
#define OTPC_BOOTROM_SWDEN0_SHIFT                (6U)
/*! SWDEN0 - This bit along with bit SWDEN1 is used to control enabling/disabling SWD. */
#define OTPC_BOOTROM_SWDEN0(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_SWDEN0_SHIFT)) & OTPC_BOOTROM_SWDEN0_MASK)

#define OTPC_BOOTROM_ISP_PINS_DISABLED_MASK      (0x80U)
#define OTPC_BOOTROM_ISP_PINS_DISABLED_SHIFT     (7U)
/*! ISP_PINS_DISABLED - This bit controls the ability to enter ISP mode with pin selection. */
#define OTPC_BOOTROM_ISP_PINS_DISABLED(x)        (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_ISP_PINS_DISABLED_SHIFT)) & OTPC_BOOTROM_ISP_PINS_DISABLED_MASK)

#define OTPC_BOOTROM_ISP_IAP_DISABLED_MASK       (0x100U)
#define OTPC_BOOTROM_ISP_IAP_DISABLED_SHIFT      (8U)
/*! ISP_IAP_DISABLED - ISP entry through IAP API. */
#define OTPC_BOOTROM_ISP_IAP_DISABLED(x)         (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_ISP_IAP_DISABLED_SHIFT)) & OTPC_BOOTROM_ISP_IAP_DISABLED_MASK)

#define OTPC_BOOTROM_BOOT_SRC_MASK               (0x600U)
#define OTPC_BOOTROM_BOOT_SRC_SHIFT              (9U)
/*! BOOT_SRC - Boot source. */
#define OTPC_BOOTROM_BOOT_SRC(x)                 (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_BOOT_SRC_SHIFT)) & OTPC_BOOTROM_BOOT_SRC_MASK)

#define OTPC_BOOTROM_ISP_MODE_MASK               (0x1800U)
#define OTPC_BOOTROM_ISP_MODE_SHIFT              (11U)
/*! ISP_MODE - Fall through ISP mode. */
#define OTPC_BOOTROM_ISP_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_ISP_MODE_SHIFT)) & OTPC_BOOTROM_ISP_MODE_MASK)

#define OTPC_BOOTROM_SWDEN1_MASK                 (0x2000U)
#define OTPC_BOOTROM_SWDEN1_SHIFT                (13U)
/*! SWDEN1 - This bit along with bit SWD_EN0 is used to control enabling/disabling. */
#define OTPC_BOOTROM_SWDEN1(x)                   (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_SWDEN1_SHIFT)) & OTPC_BOOTROM_SWDEN1_MASK)

#define OTPC_BOOTROM_USE_PUF_MASK                (0x4000U)
#define OTPC_BOOTROM_USE_PUF_SHIFT               (14U)
/*! USE_PUF - Encryption key supplied by PUF. */
#define OTPC_BOOTROM_USE_PUF(x)                  (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_USE_PUF_SHIFT)) & OTPC_BOOTROM_USE_PUF_MASK)

#define OTPC_BOOTROM_BLOCK_PUF_ENROLL_KEY_CODE_MASK (0x8000U)
#define OTPC_BOOTROM_BLOCK_PUF_ENROLL_KEY_CODE_SHIFT (15U)
/*! BLOCK_PUF_ENROLL_KEY_CODE - Block PUF enrollment and key code generation. */
#define OTPC_BOOTROM_BLOCK_PUF_ENROLL_KEY_CODE(x) (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_BLOCK_PUF_ENROLL_KEY_CODE_SHIFT)) & OTPC_BOOTROM_BLOCK_PUF_ENROLL_KEY_CODE_MASK)

#define OTPC_BOOTROM_QSPI_DELAY_MASK             (0xE0000U)
#define OTPC_BOOTROM_QSPI_DELAY_SHIFT            (17U)
/*! QSPI_DELAY - Amount of delay ROM has o wait after POR reset before access QSPI flash device. */
#define OTPC_BOOTROM_QSPI_DELAY(x)               (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_QSPI_DELAY_SHIFT)) & OTPC_BOOTROM_QSPI_DELAY_MASK)

#define OTPC_BOOTROM_USER_APPLICATION_MASK       (0xF00000U)
#define OTPC_BOOTROM_USER_APPLICATION_SHIFT      (20U)
/*! USER_APPLICATION - Fall through ISP mode. */
#define OTPC_BOOTROM_USER_APPLICATION(x)         (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_USER_APPLICATION_SHIFT)) & OTPC_BOOTROM_USER_APPLICATION_MASK)

#define OTPC_BOOTROM_REVOKE_ID_MASK              (0xFF000000U)
#define OTPC_BOOTROM_REVOKE_ID_SHIFT             (24U)
/*! REVOKE_ID - Key and image revocation identifier in secure authenticated mode. */
#define OTPC_BOOTROM_REVOKE_ID(x)                (((uint32_t)(((uint32_t)(x)) << OTPC_BOOTROM_REVOKE_ID_SHIFT)) & OTPC_BOOTROM_REVOKE_ID_MASK)
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

