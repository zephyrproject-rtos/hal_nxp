/*
** ###################################################################
**     Processors:          LPC54018J2MET180
**                          LPC54018J4MET180
**                          LPC54S018J2MET180
**                          LPC54S018J4MET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SHA
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
 * @file PERI_SHA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SHA
 *
 * CMSIS Peripheral Access Layer for SHA
 */

#if !defined(PERI_SHA_H_)
#define PERI_SHA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54018J2MET180) || defined(CPU_LPC54018J4MET180))
#include "LPC54018M_COMMON.h"
#elif (defined(CPU_LPC54S018J2MET180) || defined(CPU_LPC54S018J4MET180))
#include "LPC54S018M_COMMON.h"
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
   -- SHA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SHA_Peripheral_Access_Layer SHA Peripheral Access Layer
 * @{
 */

/** SHA - Size of Registers Arrays */
#define SHA_ALIAS_COUNT                           7u
#define SHA_DIGEST_COUNT                          8u

/** SHA - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control register, offset: 0x0 */
  __IO uint32_t STATUS;                            /**< Status register, offset: 0x4 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable register, offset: 0x8 */
  __O  uint32_t INTENCLR;                          /**< Interrupt Clear register, offset: 0xC */
  __IO uint32_t MEMCTRL;                           /**< Memory Control register, offset: 0x10 */
  __IO uint32_t MEMADDR;                           /**< Memory Address register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __O  uint32_t INDATA;                            /**< Input Data register, offset: 0x20 */
  __O  uint32_t ALIAS[SHA_ALIAS_COUNT];            /**< Alias register, array offset: 0x24, array step: 0x4 */
  __I  uint32_t DIGEST[SHA_DIGEST_COUNT];          /**< Digest register, array offset: 0x40, array step: 0x4 */
} SHA_Type;

/* ----------------------------------------------------------------------------
   -- SHA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SHA_Register_Masks SHA Register Masks
 * @{
 */

/*! @name CTRL - Control register */
/*! @{ */

#define SHA_CTRL_MODE_MASK                       (0x3U)
#define SHA_CTRL_MODE_SHIFT                      (0U)
/*! MODE - This field is used to select the operational mode of SHA block. */
#define SHA_CTRL_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << SHA_CTRL_MODE_SHIFT)) & SHA_CTRL_MODE_MASK)

#define SHA_CTRL_NEW_MASK                        (0x10U)
#define SHA_CTRL_NEW_SHIFT                       (4U)
/*! NEW - When this bit is set, a new hash operation is started. */
#define SHA_CTRL_NEW(x)                          (((uint32_t)(((uint32_t)(x)) << SHA_CTRL_NEW_SHIFT)) & SHA_CTRL_NEW_MASK)

#define SHA_CTRL_DMA_MASK                        (0x100U)
#define SHA_CTRL_DMA_SHIFT                       (8U)
/*! DMA - When this bit is set, the DMA is used to fill INDATA. */
#define SHA_CTRL_DMA(x)                          (((uint32_t)(((uint32_t)(x)) << SHA_CTRL_DMA_SHIFT)) & SHA_CTRL_DMA_MASK)
/*! @} */

/*! @name STATUS - Status register */
/*! @{ */

#define SHA_STATUS_WAITING_MASK                  (0x1U)
#define SHA_STATUS_WAITING_SHIFT                 (0U)
/*! WAITING - This field indicates if the block is waiting for more data to process. */
#define SHA_STATUS_WAITING(x)                    (((uint32_t)(((uint32_t)(x)) << SHA_STATUS_WAITING_SHIFT)) & SHA_STATUS_WAITING_MASK)

#define SHA_STATUS_DIGEST_MASK                   (0x2U)
#define SHA_STATUS_DIGEST_SHIFT                  (1U)
/*! DIGEST - This field indicates if a DIGEST is ready and waiting and there is no active next block that has already started. */
#define SHA_STATUS_DIGEST(x)                     (((uint32_t)(((uint32_t)(x)) << SHA_STATUS_DIGEST_SHIFT)) & SHA_STATUS_DIGEST_MASK)

#define SHA_STATUS_ERROR_MASK                    (0x4U)
#define SHA_STATUS_ERROR_SHIFT                   (2U)
/*! ERROR - This field indicates if an error has occurred. */
#define SHA_STATUS_ERROR(x)                      (((uint32_t)(((uint32_t)(x)) << SHA_STATUS_ERROR_SHIFT)) & SHA_STATUS_ERROR_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable register */
/*! @{ */

#define SHA_INTENSET_WAITING_MASK                (0x1U)
#define SHA_INTENSET_WAITING_SHIFT               (0U)
/*! WAITING - This field indicates if interrupt should be enabled when waiting for input data. */
#define SHA_INTENSET_WAITING(x)                  (((uint32_t)(((uint32_t)(x)) << SHA_INTENSET_WAITING_SHIFT)) & SHA_INTENSET_WAITING_MASK)

#define SHA_INTENSET_DIGEST_MASK                 (0x2U)
#define SHA_INTENSET_DIGEST_SHIFT                (1U)
/*! DIGEST - This field indicates if interrupt is generated when Digest is ready (completed a Hash or completed a full sequence). */
#define SHA_INTENSET_DIGEST(x)                   (((uint32_t)(((uint32_t)(x)) << SHA_INTENSET_DIGEST_SHIFT)) & SHA_INTENSET_DIGEST_MASK)

#define SHA_INTENSET_ERROR_MASK                  (0x4U)
#define SHA_INTENSET_ERROR_SHIFT                 (2U)
/*! ERROR - This field indicates if interrupt is generated on an ERROR (as defined in STAT register). */
#define SHA_INTENSET_ERROR(x)                    (((uint32_t)(((uint32_t)(x)) << SHA_INTENSET_ERROR_SHIFT)) & SHA_INTENSET_ERROR_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Clear register */
/*! @{ */

#define SHA_INTENCLR_WAITING_MASK                (0x1U)
#define SHA_INTENCLR_WAITING_SHIFT               (0U)
/*! WAITING - Writing a 1 clears the interrupt enabled by the INTENSET register. */
#define SHA_INTENCLR_WAITING(x)                  (((uint32_t)(((uint32_t)(x)) << SHA_INTENCLR_WAITING_SHIFT)) & SHA_INTENCLR_WAITING_MASK)

#define SHA_INTENCLR_DIGEST_MASK                 (0x2U)
#define SHA_INTENCLR_DIGEST_SHIFT                (1U)
/*! DIGEST - Writing a 1 clears the interrupt enabled by the INTENSET register. */
#define SHA_INTENCLR_DIGEST(x)                   (((uint32_t)(((uint32_t)(x)) << SHA_INTENCLR_DIGEST_SHIFT)) & SHA_INTENCLR_DIGEST_MASK)

#define SHA_INTENCLR_ERROR_MASK                  (0x4U)
#define SHA_INTENCLR_ERROR_SHIFT                 (2U)
/*! ERROR - Writing a 1 clears the interrupt enabled by the INTENSET register. */
#define SHA_INTENCLR_ERROR(x)                    (((uint32_t)(((uint32_t)(x)) << SHA_INTENCLR_ERROR_SHIFT)) & SHA_INTENCLR_ERROR_MASK)
/*! @} */

/*! @name MEMCTRL - Memory Control register */
/*! @{ */

#define SHA_MEMCTRL_MASTER_MASK                  (0x1U)
#define SHA_MEMCTRL_MASTER_SHIFT                 (0U)
/*! MASTER - This field is used to enable SHA block as AHB bus master. */
#define SHA_MEMCTRL_MASTER(x)                    (((uint32_t)(((uint32_t)(x)) << SHA_MEMCTRL_MASTER_SHIFT)) & SHA_MEMCTRL_MASTER_MASK)

#define SHA_MEMCTRL_COUNT_MASK                   (0x7FF0000U)
#define SHA_MEMCTRL_COUNT_SHIFT                  (16U)
/*! COUNT - This field indicates the number of 512-bit blocks to copy starting at MEMADDR. */
#define SHA_MEMCTRL_COUNT(x)                     (((uint32_t)(((uint32_t)(x)) << SHA_MEMCTRL_COUNT_SHIFT)) & SHA_MEMCTRL_COUNT_MASK)
/*! @} */

/*! @name MEMADDR - Memory Address register */
/*! @{ */

#define SHA_MEMADDR_BASEADDR_MASK                (0xFFFFFFFFU)
#define SHA_MEMADDR_BASEADDR_SHIFT               (0U)
/*! BASEADDR - This field indicates the base address in Internal Flash, SRAM0, SRAMX, or SPIFI to start copying from. */
#define SHA_MEMADDR_BASEADDR(x)                  (((uint32_t)(((uint32_t)(x)) << SHA_MEMADDR_BASEADDR_SHIFT)) & SHA_MEMADDR_BASEADDR_MASK)
/*! @} */

/*! @name INDATA - Input Data register */
/*! @{ */

#define SHA_INDATA_DATA_MASK                     (0xFFFFFFFFU)
#define SHA_INDATA_DATA_SHIFT                    (0U)
/*! DATA - In this field the next word is written in little-endian format. */
#define SHA_INDATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << SHA_INDATA_DATA_SHIFT)) & SHA_INDATA_DATA_MASK)
/*! @} */

/*! @name ALIAS - Alias register */
/*! @{ */

#define SHA_ALIAS_DATA_MASK                      (0xFFFFFFFFU)
#define SHA_ALIAS_DATA_SHIFT                     (0U)
/*! DATA - In this field the next word is written in little-endian format. */
#define SHA_ALIAS_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << SHA_ALIAS_DATA_SHIFT)) & SHA_ALIAS_DATA_MASK)
/*! @} */

/*! @name DIGEST - Digest register */
/*! @{ */

#define SHA_DIGEST_DIGEST_MASK                   (0xFFFFFFFFU)
#define SHA_DIGEST_DIGEST_SHIFT                  (0U)
/*! DIGEST - This field contains one word of the Digest. */
#define SHA_DIGEST_DIGEST(x)                     (((uint32_t)(((uint32_t)(x)) << SHA_DIGEST_DIGEST_SHIFT)) & SHA_DIGEST_DIGEST_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SHA_Register_Masks */


/*!
 * @}
 */ /* end of group SHA_Peripheral_Access_Layer */


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


#endif  /* PERI_SHA_H_ */

