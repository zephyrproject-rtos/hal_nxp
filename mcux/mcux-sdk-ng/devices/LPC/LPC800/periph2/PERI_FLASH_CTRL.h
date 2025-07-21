/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH_CTRL
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
 * @file PERI_FLASH_CTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_CTRL
 *
 * CMSIS Peripheral Access Layer for FLASH_CTRL
 */

#if !defined(PERI_FLASH_CTRL_H_)
#define PERI_FLASH_CTRL_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
   -- FLASH_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_CTRL_Peripheral_Access_Layer FLASH_CTRL Peripheral Access Layer
 * @{
 */

/** FLASH_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASHCFG;                          /**< Flash configuration register, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FMSSTART;                          /**< Flash signature start address register, offset: 0x20 */
  __IO uint32_t FMSSTOP;                           /**< Flash signaure stop address register, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __I  uint32_t FMSW0;                             /**< Flash signature generation result register returns the flash signature produced by the embedded signature generator.., offset: 0x2C */
       uint8_t RESERVED_3[4016];
  __I  uint32_t FMSTAT;                            /**< Flash signature generation status bit, offset: 0xFE0 */
       uint8_t RESERVED_4[4];
  __O  uint32_t FMSTATCLR;                         /**< Clear FLASH signature generation status bit, offset: 0xFE8 */
} FLASH_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_CTRL_Register_Masks FLASH_CTRL Register Masks
 * @{
 */

/*! @name FLASHCFG - Flash configuration register */
/*! @{ */

#define FLASH_CTRL_FLASHCFG_FLASHTIM_MASK        (0x3U)
#define FLASH_CTRL_FLASHCFG_FLASHTIM_SHIFT       (0U)
/*! FLASHTIM - Flash memory access time. FLASHTIM +1 is equal to the number of system clocks used for flash access.
 *  0b00..1 system clock flash access time.
 *  0b01..2 system clock flash access time.
 *  0b10..3 system clock flash access time.
 *  0b11..Reserved.
 */
#define FLASH_CTRL_FLASHCFG_FLASHTIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FLASHCFG_FLASHTIM_SHIFT)) & FLASH_CTRL_FLASHCFG_FLASHTIM_MASK)
/*! @} */

/*! @name FMSSTART - Flash signature start address register */
/*! @{ */

#define FLASH_CTRL_FMSSTART_START_MASK           (0x1FFFFU)
#define FLASH_CTRL_FMSSTART_START_SHIFT          (0U)
/*! START - Signature generation start address (corresponds to AHB byte address bits[18:2]). */
#define FLASH_CTRL_FMSSTART_START(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSSTART_START_SHIFT)) & FLASH_CTRL_FMSSTART_START_MASK)
/*! @} */

/*! @name FMSSTOP - Flash signaure stop address register */
/*! @{ */

#define FLASH_CTRL_FMSSTOP_STOPA_MASK            (0x1FFFFU)
#define FLASH_CTRL_FMSSTOP_STOPA_SHIFT           (0U)
/*! STOPA - Stop address for signature generation (the word specified by STOP is included in the
 *    address range). The address is in units of memory words, not bytes.
 */
#define FLASH_CTRL_FMSSTOP_STOPA(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSSTOP_STOPA_SHIFT)) & FLASH_CTRL_FMSSTOP_STOPA_MASK)

#define FLASH_CTRL_FMSSTOP_STRTBIST_MASK         (0x80000000U)
#define FLASH_CTRL_FMSSTOP_STRTBIST_SHIFT        (31U)
/*! STRTBIST - When this bit is written to 1, signature generation starts. At the end of signature
 *    generation, this bit is automatically cleared.
 */
#define FLASH_CTRL_FMSSTOP_STRTBIST(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSSTOP_STRTBIST_SHIFT)) & FLASH_CTRL_FMSSTOP_STRTBIST_MASK)
/*! @} */

/*! @name FMSW0 - Flash signature generation result register returns the flash signature produced by the embedded signature generator.. */
/*! @{ */

#define FLASH_CTRL_FMSW0_SIG_MASK                (0xFFFFFFFFU)
#define FLASH_CTRL_FMSW0_SIG_SHIFT               (0U)
/*! SIG - 32-bit signature. */
#define FLASH_CTRL_FMSW0_SIG(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSW0_SIG_SHIFT)) & FLASH_CTRL_FMSW0_SIG_MASK)
/*! @} */

/*! @name FMSTAT - Flash signature generation status bit */
/*! @{ */

#define FLASH_CTRL_FMSTAT_SIG_DONE_MASK          (0x2U)
#define FLASH_CTRL_FMSTAT_SIG_DONE_SHIFT         (1U)
/*! SIG_DONE - This status bit is set at the end of signature computation */
#define FLASH_CTRL_FMSTAT_SIG_DONE(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSTAT_SIG_DONE_SHIFT)) & FLASH_CTRL_FMSTAT_SIG_DONE_MASK)
/*! @} */

/*! @name FMSTATCLR - Clear FLASH signature generation status bit */
/*! @{ */

#define FLASH_CTRL_FMSTATCLR_SIG_DONE_CLR_MASK   (0x2U)
#define FLASH_CTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT  (1U)
/*! SIG_DONE_CLR - When the bit is written to 1, the SIGNATURE_DONE bit is cleared. */
#define FLASH_CTRL_FMSTATCLR_SIG_DONE_CLR(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_CTRL_FMSTATCLR_SIG_DONE_CLR_SHIFT)) & FLASH_CTRL_FMSTATCLR_SIG_DONE_CLR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_CTRL_H_ */

