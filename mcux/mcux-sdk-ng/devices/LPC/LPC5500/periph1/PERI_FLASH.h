/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLASH.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH
 *
 * CMSIS Peripheral Access Layer for FLASH
 */

#if !defined(PERI_FLASH_H_)
#define PERI_FLASH_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- FLASH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Peripheral_Access_Layer FLASH Peripheral Access Layer
 * @{
 */

/** FLASH - Size of Registers Arrays */
#define FLASH_DATAW_COUNT                         4u

/** FLASH - Register Layout Typedef */
typedef struct {
  __O  uint32_t CMD;                               /**< Command, offset: 0x0 */
  __O  uint32_t EVENT;                             /**< Event, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t STARTA;                            /**< Start address for next flash command, offset: 0x10 */
  __IO uint32_t STOPA;                             /**< End address for next flash command, offset: 0x14 */
       uint8_t RESERVED_1[104];
  __IO uint32_t DATAW[FLASH_DATAW_COUNT];          /**< Data register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_2[3912];
  __O  uint32_t INTEN_CLR;                         /**< Clear interrupt enables, offset: 0xFD8 */
  __O  uint32_t INTEN_SET;                         /**< Set interrupt enables, offset: 0xFDC */
  __I  uint32_t INTSTAT;                           /**< Interrupt status, offset: 0xFE0 */
  __I  uint32_t INTEN;                             /**< Interrupt enable, offset: 0xFE4 */
  __O  uint32_t INTSTAT_CLR;                       /**< Clear interrupt status, offset: 0xFE8 */
  __O  uint32_t INTSTAT_SET;                       /**< Set interrupt status, offset: 0xFEC */
       uint8_t RESERVED_3[12];
  __I  uint32_t MODULE_ID;                         /**< Module identification, offset: 0xFFC */
} FLASH_Type;

/* ----------------------------------------------------------------------------
   -- FLASH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_Register_Masks FLASH Register Masks
 * @{
 */

/*! @name CMD - Command */
/*! @{ */

#define FLASH_CMD_CMD_MASK                       (0xFFFFFFFFU)
#define FLASH_CMD_CMD_SHIFT                      (0U)
/*! CMD - command register. */
#define FLASH_CMD_CMD(x)                         (((uint32_t)(((uint32_t)(x)) << FLASH_CMD_CMD_SHIFT)) & FLASH_CMD_CMD_MASK)
/*! @} */

/*! @name EVENT - Event */
/*! @{ */

#define FLASH_EVENT_RST_MASK                     (0x1U)
#define FLASH_EVENT_RST_SHIFT                    (0U)
/*! RST - When bit is set, the controller and flash are reset. */
#define FLASH_EVENT_RST(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_EVENT_RST_SHIFT)) & FLASH_EVENT_RST_MASK)

#define FLASH_EVENT_WAKEUP_MASK                  (0x2U)
#define FLASH_EVENT_WAKEUP_SHIFT                 (1U)
/*! WAKEUP - When bit is set, the controller wakes up from whatever low power or powerdown mode was active. */
#define FLASH_EVENT_WAKEUP(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_EVENT_WAKEUP_SHIFT)) & FLASH_EVENT_WAKEUP_MASK)

#define FLASH_EVENT_ABORT_MASK                   (0x4U)
#define FLASH_EVENT_ABORT_SHIFT                  (2U)
/*! ABORT - When bit is set, a running program/erase command is aborted. */
#define FLASH_EVENT_ABORT(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_EVENT_ABORT_SHIFT)) & FLASH_EVENT_ABORT_MASK)
/*! @} */

/*! @name STARTA - Start address for next flash command */
/*! @{ */

#define FLASH_STARTA_STARTA_MASK                 (0x3FFFU)
#define FLASH_STARTA_STARTA_SHIFT                (0U)
/*! STARTA - Address / Start address for commands that take an address (range) as a parameter. */
#define FLASH_STARTA_STARTA(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_STARTA_STARTA_SHIFT)) & FLASH_STARTA_STARTA_MASK)
/*! @} */

/*! @name STOPA - End address for next flash command */
/*! @{ */

#define FLASH_STOPA_STOPA_MASK                   (0x3FFFFU)
#define FLASH_STOPA_STOPA_SHIFT                  (0U)
/*! STOPA - Stop address for commands that take an address range as a parameter (the word specified
 *    by STOPA is included in the address range).
 */
#define FLASH_STOPA_STOPA(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_STOPA_STOPA_SHIFT)) & FLASH_STOPA_STOPA_MASK)
/*! @} */

/*! @name DATAW - Data register */
/*! @{ */

#define FLASH_DATAW_DATAW_MASK                   (0xFFFFFFFFU)
#define FLASH_DATAW_DATAW_SHIFT                  (0U)
/*! DATAW - Memory data, or command parameter, or command result. */
#define FLASH_DATAW_DATAW(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_DATAW_DATAW_SHIFT)) & FLASH_DATAW_DATAW_MASK)
/*! @} */

/*! @name INTEN_CLR - Clear interrupt enables */
/*! @{ */

#define FLASH_INTEN_CLR_FAIL_MASK                (0x1U)
#define FLASH_INTEN_CLR_FAIL_SHIFT               (0U)
/*! FAIL - Clears the fail interrupt. */
#define FLASH_INTEN_CLR_FAIL(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_CLR_FAIL_SHIFT)) & FLASH_INTEN_CLR_FAIL_MASK)

#define FLASH_INTEN_CLR_ERR_MASK                 (0x2U)
#define FLASH_INTEN_CLR_ERR_SHIFT                (1U)
/*! ERR - Clears the error interrupt. */
#define FLASH_INTEN_CLR_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_CLR_ERR_SHIFT)) & FLASH_INTEN_CLR_ERR_MASK)

#define FLASH_INTEN_CLR_DONE_MASK                (0x4U)
#define FLASH_INTEN_CLR_DONE_SHIFT               (2U)
/*! DONE - Clears the done interrupt. */
#define FLASH_INTEN_CLR_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_CLR_DONE_SHIFT)) & FLASH_INTEN_CLR_DONE_MASK)

#define FLASH_INTEN_CLR_ECC_ERR_MASK             (0x8U)
#define FLASH_INTEN_CLR_ECC_ERR_SHIFT            (3U)
/*! ECC_ERR - Clears the ECC error interrupt. */
#define FLASH_INTEN_CLR_ECC_ERR(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_CLR_ECC_ERR_SHIFT)) & FLASH_INTEN_CLR_ECC_ERR_MASK)
/*! @} */

/*! @name INTEN_SET - Set interrupt enables */
/*! @{ */

#define FLASH_INTEN_SET_FAIL_MASK                (0x1U)
#define FLASH_INTEN_SET_FAIL_SHIFT               (0U)
/*! FAIL - Sets Fail interrupt. */
#define FLASH_INTEN_SET_FAIL(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_SET_FAIL_SHIFT)) & FLASH_INTEN_SET_FAIL_MASK)

#define FLASH_INTEN_SET_ERR_MASK                 (0x2U)
#define FLASH_INTEN_SET_ERR_SHIFT                (1U)
/*! ERR - Sets error interrupt */
#define FLASH_INTEN_SET_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_SET_ERR_SHIFT)) & FLASH_INTEN_SET_ERR_MASK)

#define FLASH_INTEN_SET_DONE_MASK                (0x4U)
#define FLASH_INTEN_SET_DONE_SHIFT               (2U)
/*! DONE - Sets done interrupt. */
#define FLASH_INTEN_SET_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_SET_DONE_SHIFT)) & FLASH_INTEN_SET_DONE_MASK)

#define FLASH_INTEN_SET_ECC_ERR_MASK             (0x8U)
#define FLASH_INTEN_SET_ECC_ERR_SHIFT            (3U)
/*! ECC_ERR - Sets ECC error interrupt. */
#define FLASH_INTEN_SET_ECC_ERR(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_SET_ECC_ERR_SHIFT)) & FLASH_INTEN_SET_ECC_ERR_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status */
/*! @{ */

#define FLASH_INTSTAT_FAIL_MASK                  (0x1U)
#define FLASH_INTSTAT_FAIL_SHIFT                 (0U)
/*! FAIL - This status bit is set if execution of a (legal) command failed. */
#define FLASH_INTSTAT_FAIL(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_FAIL_SHIFT)) & FLASH_INTSTAT_FAIL_MASK)

#define FLASH_INTSTAT_ERR_MASK                   (0x2U)
#define FLASH_INTSTAT_ERR_SHIFT                  (1U)
/*! ERR - This status bit is set if execution of an illegal command is detected. */
#define FLASH_INTSTAT_ERR(x)                     (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_ERR_SHIFT)) & FLASH_INTSTAT_ERR_MASK)

#define FLASH_INTSTAT_DONE_MASK                  (0x4U)
#define FLASH_INTSTAT_DONE_SHIFT                 (2U)
/*! DONE - This status bit is set at the end of command execution. */
#define FLASH_INTSTAT_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_DONE_SHIFT)) & FLASH_INTSTAT_DONE_MASK)

#define FLASH_INTSTAT_ECC_ERR_MASK               (0x8U)
#define FLASH_INTSTAT_ECC_ERR_SHIFT              (3U)
/*! ECC_ERR - This status bit is set if, during a memory read operation (either a user-requested
 *    read, or a speculative read, or reads performed by a controller command), a correctable or
 *    uncorrectable error is detected by ECC decoding logic.
 */
#define FLASH_INTSTAT_ECC_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_ECC_ERR_SHIFT)) & FLASH_INTSTAT_ECC_ERR_MASK)
/*! @} */

/*! @name INTEN - Interrupt enable */
/*! @{ */

#define FLASH_INTEN_FAIL_MASK                    (0x1U)
#define FLASH_INTEN_FAIL_SHIFT                   (0U)
/*! FAIL - Enables fail interrupt. */
#define FLASH_INTEN_FAIL(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_FAIL_SHIFT)) & FLASH_INTEN_FAIL_MASK)

#define FLASH_INTEN_ERR_MASK                     (0x2U)
#define FLASH_INTEN_ERR_SHIFT                    (1U)
/*! ERR - Enables error interrupt. */
#define FLASH_INTEN_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_ERR_SHIFT)) & FLASH_INTEN_ERR_MASK)

#define FLASH_INTEN_DONE_MASK                    (0x4U)
#define FLASH_INTEN_DONE_SHIFT                   (2U)
/*! DONE - Enables done interrupt. */
#define FLASH_INTEN_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_DONE_SHIFT)) & FLASH_INTEN_DONE_MASK)

#define FLASH_INTEN_ECC_ERR_MASK                 (0x8U)
#define FLASH_INTEN_ECC_ERR_SHIFT                (3U)
/*! ECC_ERR - Enables ECC error interrupt. */
#define FLASH_INTEN_ECC_ERR(x)                   (((uint32_t)(((uint32_t)(x)) << FLASH_INTEN_ECC_ERR_SHIFT)) & FLASH_INTEN_ECC_ERR_MASK)
/*! @} */

/*! @name INTSTAT_CLR - Clear interrupt status */
/*! @{ */

#define FLASH_INTSTAT_CLR_FAIL_MASK              (0x1U)
#define FLASH_INTSTAT_CLR_FAIL_SHIFT             (0U)
/*! FAIL - Clears fail interrupt status. */
#define FLASH_INTSTAT_CLR_FAIL(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_CLR_FAIL_SHIFT)) & FLASH_INTSTAT_CLR_FAIL_MASK)

#define FLASH_INTSTAT_CLR_ERR_MASK               (0x2U)
#define FLASH_INTSTAT_CLR_ERR_SHIFT              (1U)
/*! ERR - Clears error interrupt status. */
#define FLASH_INTSTAT_CLR_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_CLR_ERR_SHIFT)) & FLASH_INTSTAT_CLR_ERR_MASK)

#define FLASH_INTSTAT_CLR_DONE_MASK              (0x4U)
#define FLASH_INTSTAT_CLR_DONE_SHIFT             (2U)
/*! DONE - Clears done interrupt status. */
#define FLASH_INTSTAT_CLR_DONE(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_CLR_DONE_SHIFT)) & FLASH_INTSTAT_CLR_DONE_MASK)

#define FLASH_INTSTAT_CLR_ECC_ERR_MASK           (0x8U)
#define FLASH_INTSTAT_CLR_ECC_ERR_SHIFT          (3U)
/*! ECC_ERR - Clears ECC error interrupt status. */
#define FLASH_INTSTAT_CLR_ECC_ERR(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_CLR_ECC_ERR_SHIFT)) & FLASH_INTSTAT_CLR_ECC_ERR_MASK)
/*! @} */

/*! @name INTSTAT_SET - Set interrupt status */
/*! @{ */

#define FLASH_INTSTAT_SET_FAIL_MASK              (0x1U)
#define FLASH_INTSTAT_SET_FAIL_SHIFT             (0U)
/*! FAIL - Sets fail interrupt status. */
#define FLASH_INTSTAT_SET_FAIL(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_SET_FAIL_SHIFT)) & FLASH_INTSTAT_SET_FAIL_MASK)

#define FLASH_INTSTAT_SET_ERR_MASK               (0x2U)
#define FLASH_INTSTAT_SET_ERR_SHIFT              (1U)
/*! ERR - Sets error interrupt status. */
#define FLASH_INTSTAT_SET_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_SET_ERR_SHIFT)) & FLASH_INTSTAT_SET_ERR_MASK)

#define FLASH_INTSTAT_SET_DONE_MASK              (0x4U)
#define FLASH_INTSTAT_SET_DONE_SHIFT             (2U)
/*! DONE - Sets done interrupt status. */
#define FLASH_INTSTAT_SET_DONE(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_SET_DONE_SHIFT)) & FLASH_INTSTAT_SET_DONE_MASK)

#define FLASH_INTSTAT_SET_ECC_ERR_MASK           (0x8U)
#define FLASH_INTSTAT_SET_ECC_ERR_SHIFT          (3U)
/*! ECC_ERR - Sets ECC error interrupt status. */
#define FLASH_INTSTAT_SET_ECC_ERR(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_INTSTAT_SET_ECC_ERR_SHIFT)) & FLASH_INTSTAT_SET_ECC_ERR_MASK)
/*! @} */

/*! @name MODULE_ID - Module identification */
/*! @{ */

#define FLASH_MODULE_ID_MINOR_REV_MASK           (0xF00U)
#define FLASH_MODULE_ID_MINOR_REV_SHIFT          (8U)
/*! MINOR_REV - Minor revision i. */
#define FLASH_MODULE_ID_MINOR_REV(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_MINOR_REV_SHIFT)) & FLASH_MODULE_ID_MINOR_REV_MASK)

#define FLASH_MODULE_ID_MAJOR_REV_MASK           (0xF000U)
#define FLASH_MODULE_ID_MAJOR_REV_SHIFT          (12U)
/*! MAJOR_REV - Major revision i. */
#define FLASH_MODULE_ID_MAJOR_REV(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_MAJOR_REV_SHIFT)) & FLASH_MODULE_ID_MAJOR_REV_MASK)

#define FLASH_MODULE_ID_ID_MASK                  (0xFFFF0000U)
#define FLASH_MODULE_ID_ID_SHIFT                 (16U)
/*! ID - Identifier. */
#define FLASH_MODULE_ID_ID(x)                    (((uint32_t)(((uint32_t)(x)) << FLASH_MODULE_ID_ID_SHIFT)) & FLASH_MODULE_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_H_ */

