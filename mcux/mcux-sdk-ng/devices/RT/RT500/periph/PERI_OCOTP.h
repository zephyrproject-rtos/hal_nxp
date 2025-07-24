/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OCOTP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OCOTP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OCOTP
 *
 * CMSIS Peripheral Access Layer for OCOTP
 */

#if !defined(PERI_OCOTP_H_)
#define PERI_OCOTP_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OCOTP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Peripheral_Access_Layer OCOTP Peripheral Access Layer
 * @{
 */

/** OCOTP - Size of Registers Arrays */
#define OCOTP_OTP_SHADOW_COUNT                    496u

/** OCOTP - Register Layout Typedef */
typedef struct {
  __IO uint32_t OTP_SHADOW[OCOTP_OTP_SHADOW_COUNT]; /**< One Time Programmable Controller shadow, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[64];
  __IO uint32_t OTP_CTRL;                          /**< Control/Address, offset: 0x800 */
  __IO uint32_t OTP_PDN;                           /**< Power-down, offset: 0x804 */
  __IO uint32_t OTP_WRITE_DATA;                    /**< OTP programming data, offset: 0x808 */
  __IO uint32_t OTP_READ_CTRL;                     /**< OTP read start control, offset: 0x80C */
  __I  uint32_t OTP_READ_DATA;                     /**< OTP read data, offset: 0x810 */
  __IO uint32_t OTP_CLK_DIV;                       /**< OTP clock divider, offset: 0x814 */
       uint8_t RESERVED_1[4];
  __IO uint32_t OTP_CRC_ADDR;                      /**< CRC address range, offset: 0x81C */
  __I  uint32_t OTP_CRC_VALUE;                     /**< CRC result, offset: 0x820 */
  __IO uint32_t OTP_STATUS;                        /**< OTP Status, offset: 0x824 */
       uint8_t RESERVED_2[4];
  __I  uint32_t OTP_VERSION;                       /**< VERSION ID, offset: 0x82C */
} OCOTP_Type;

/* ----------------------------------------------------------------------------
   -- OCOTP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Register_Masks OCOTP Register Masks
 * @{
 */

/*! @name OTP_SHADOW - One Time Programmable Controller shadow */
/*! @{ */

#define OCOTP_OTP_SHADOW_SHADOW_MASK             (0xFFFFFFFFU)
#define OCOTP_OTP_SHADOW_SHADOW_SHIFT            (0U)
/*! SHADOW - OTP shadow */
#define OCOTP_OTP_SHADOW_SHADOW(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_SHADOW_SHADOW_SHIFT)) & OCOTP_OTP_SHADOW_SHADOW_MASK)
/*! @} */

/*! @name OTP_CTRL - Control/Address */
/*! @{ */

#define OCOTP_OTP_CTRL_ADDR_MASK                 (0x1FFU)
#define OCOTP_OTP_CTRL_ADDR_SHIFT                (0U)
/*! ADDR - OTP word address */
#define OCOTP_OTP_CTRL_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CTRL_ADDR_SHIFT)) & OCOTP_OTP_CTRL_ADDR_MASK)

#define OCOTP_OTP_CTRL_RELOAD_SHADOWS_MASK       (0x800U)
#define OCOTP_OTP_CTRL_RELOAD_SHADOWS_SHIFT      (11U)
/*! RELOAD_SHADOWS - Reload Shadow registers */
#define OCOTP_OTP_CTRL_RELOAD_SHADOWS(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CTRL_RELOAD_SHADOWS_SHIFT)) & OCOTP_OTP_CTRL_RELOAD_SHADOWS_MASK)

#define OCOTP_OTP_CTRL_CRC_TEST_MASK             (0x1000U)
#define OCOTP_OTP_CTRL_CRC_TEST_SHIFT            (12U)
/*! CRC_TEST - Set to start CRC calculation. */
#define OCOTP_OTP_CTRL_CRC_TEST(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CTRL_CRC_TEST_SHIFT)) & OCOTP_OTP_CTRL_CRC_TEST_MASK)

#define OCOTP_OTP_CTRL_WORDLOCK_MASK             (0x8000U)
#define OCOTP_OTP_CTRL_WORDLOCK_SHIFT            (15U)
/*! WORDLOCK - Wordlock */
#define OCOTP_OTP_CTRL_WORDLOCK(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CTRL_WORDLOCK_SHIFT)) & OCOTP_OTP_CTRL_WORDLOCK_MASK)

#define OCOTP_OTP_CTRL_WR_UNLOCK_MASK            (0xFFFF0000U)
#define OCOTP_OTP_CTRL_WR_UNLOCK_SHIFT           (16U)
/*! WR_UNLOCK - Write unlock */
#define OCOTP_OTP_CTRL_WR_UNLOCK(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CTRL_WR_UNLOCK_SHIFT)) & OCOTP_OTP_CTRL_WR_UNLOCK_MASK)
/*! @} */

/*! @name OTP_PDN - Power-down */
/*! @{ */

#define OCOTP_OTP_PDN_PDN_MASK                   (0x1U)
#define OCOTP_OTP_PDN_PDN_SHIFT                  (0U)
/*! PDN - Power-down */
#define OCOTP_OTP_PDN_PDN(x)                     (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_PDN_PDN_SHIFT)) & OCOTP_OTP_PDN_PDN_MASK)
/*! @} */

/*! @name OTP_WRITE_DATA - OTP programming data */
/*! @{ */

#define OCOTP_OTP_WRITE_DATA_WRITE_DATA_MASK     (0xFFFFFFFFU)
#define OCOTP_OTP_WRITE_DATA_WRITE_DATA_SHIFT    (0U)
/*! WRITE_DATA - Write data */
#define OCOTP_OTP_WRITE_DATA_WRITE_DATA(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_WRITE_DATA_WRITE_DATA_SHIFT)) & OCOTP_OTP_WRITE_DATA_WRITE_DATA_MASK)
/*! @} */

/*! @name OTP_READ_CTRL - OTP read start control */
/*! @{ */

#define OCOTP_OTP_READ_CTRL_READ_MASK            (0x1U)
#define OCOTP_OTP_READ_CTRL_READ_SHIFT           (0U)
/*! READ - Read operation */
#define OCOTP_OTP_READ_CTRL_READ(x)              (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_READ_CTRL_READ_SHIFT)) & OCOTP_OTP_READ_CTRL_READ_MASK)
/*! @} */

/*! @name OTP_READ_DATA - OTP read data */
/*! @{ */

#define OCOTP_OTP_READ_DATA_READ_DATA_MASK       (0xFFFFFFFFU)
#define OCOTP_OTP_READ_DATA_READ_DATA_SHIFT      (0U)
/*! READ_DATA - Fuse word read data from read operation */
#define OCOTP_OTP_READ_DATA_READ_DATA(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_READ_DATA_READ_DATA_SHIFT)) & OCOTP_OTP_READ_DATA_READ_DATA_MASK)
/*! @} */

/*! @name OTP_CLK_DIV - OTP clock divider */
/*! @{ */

#define OCOTP_OTP_CLK_DIV_DIV_MASK               (0xFU)
#define OCOTP_OTP_CLK_DIV_DIV_SHIFT              (0U)
/*! DIV - Clock divider value by -1 encoding
 *  0b0000..Divide by 1
 *  0b0001..Divide by 2
 *  0b0010..Divide by 3
 *  0b0011..Divide by 4
 *  0b0100..Divide by 5
 *  0b0101..Divide by 6
 *  0b0110..Divide by 7
 *  0b0111..Divide by 8
 *  0b1000..Divide by 9
 *  0b1001..Divide by 10
 *  0b1010..Divide by 11
 *  0b1011..Divide by 12
 *  0b1100..Divide by 13
 *  0b1101..Divide by 14
 *  0b1110..Divide by 15
 *  0b1111..Divide by 16
 */
#define OCOTP_OTP_CLK_DIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CLK_DIV_DIV_SHIFT)) & OCOTP_OTP_CLK_DIV_DIV_MASK)

#define OCOTP_OTP_CLK_DIV_RESET_MASK             (0x20000000U)
#define OCOTP_OTP_CLK_DIV_RESET_SHIFT            (29U)
/*! RESET - Resets the divider counter. Can be used to make sure a new divider value is used right
 *    away rather than completing the previous count.
 */
#define OCOTP_OTP_CLK_DIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CLK_DIV_RESET_SHIFT)) & OCOTP_OTP_CLK_DIV_RESET_MASK)

#define OCOTP_OTP_CLK_DIV_HALT_MASK              (0x40000000U)
#define OCOTP_OTP_CLK_DIV_HALT_SHIFT             (30U)
/*! HALT - Halts the divider counter */
#define OCOTP_OTP_CLK_DIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CLK_DIV_HALT_SHIFT)) & OCOTP_OTP_CLK_DIV_HALT_MASK)

#define OCOTP_OTP_CLK_DIV_REQFLAG_MASK           (0x80000000U)
#define OCOTP_OTP_CLK_DIV_REQFLAG_SHIFT          (31U)
/*! REQFLAG - Divider status flag */
#define OCOTP_OTP_CLK_DIV_REQFLAG(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CLK_DIV_REQFLAG_SHIFT)) & OCOTP_OTP_CLK_DIV_REQFLAG_MASK)
/*! @} */

/*! @name OTP_CRC_ADDR - CRC address range */
/*! @{ */

#define OCOTP_OTP_CRC_ADDR_CRC_START_ADDR_MASK   (0x1FFU)
#define OCOTP_OTP_CRC_ADDR_CRC_START_ADDR_SHIFT  (0U)
/*! CRC_START_ADDR - CRC starting fuse word address */
#define OCOTP_OTP_CRC_ADDR_CRC_START_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CRC_ADDR_CRC_START_ADDR_SHIFT)) & OCOTP_OTP_CRC_ADDR_CRC_START_ADDR_MASK)

#define OCOTP_OTP_CRC_ADDR_CRC_END_ADDR_MASK     (0x1FF000U)
#define OCOTP_OTP_CRC_ADDR_CRC_END_ADDR_SHIFT    (12U)
/*! CRC_END_ADDR - CRC ending fuse word address */
#define OCOTP_OTP_CRC_ADDR_CRC_END_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CRC_ADDR_CRC_END_ADDR_SHIFT)) & OCOTP_OTP_CRC_ADDR_CRC_END_ADDR_MASK)

#define OCOTP_OTP_CRC_ADDR_CRC_REF_ADDR_MASK     (0x7000000U)
#define OCOTP_OTP_CRC_ADDR_CRC_REF_ADDR_SHIFT    (24U)
/*! CRC_REF_ADDR - CRC reference address */
#define OCOTP_OTP_CRC_ADDR_CRC_REF_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CRC_ADDR_CRC_REF_ADDR_SHIFT)) & OCOTP_OTP_CRC_ADDR_CRC_REF_ADDR_MASK)
/*! @} */

/*! @name OTP_CRC_VALUE - CRC result */
/*! @{ */

#define OCOTP_OTP_CRC_VALUE_CRC_VALUE_MASK       (0xFFFFFFFFU)
#define OCOTP_OTP_CRC_VALUE_CRC_VALUE_SHIFT      (0U)
/*! CRC_VALUE - CRC result value. When it is locked, reading from it returns value 0xBADA_BADA. */
#define OCOTP_OTP_CRC_VALUE_CRC_VALUE(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_CRC_VALUE_CRC_VALUE_SHIFT)) & OCOTP_OTP_CRC_VALUE_CRC_VALUE_MASK)
/*! @} */

/*! @name OTP_STATUS - OTP Status */
/*! @{ */

#define OCOTP_OTP_STATUS_SEC_MASK                (0x200U)
#define OCOTP_OTP_STATUS_SEC_SHIFT               (9U)
/*! SEC - OTP Single Error Corrected status of ECC during read operation. Write 1 to clear. */
#define OCOTP_OTP_STATUS_SEC(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_SEC_SHIFT)) & OCOTP_OTP_STATUS_SEC_MASK)

#define OCOTP_OTP_STATUS_DED_MASK                (0x400U)
#define OCOTP_OTP_STATUS_DED_SHIFT               (10U)
/*! DED - OTP Double Error Detection status of ECC during read operation. Write 1 to clear. */
#define OCOTP_OTP_STATUS_DED(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_DED_SHIFT)) & OCOTP_OTP_STATUS_DED_MASK)

#define OCOTP_OTP_STATUS_LOCKED_MASK             (0x800U)
#define OCOTP_OTP_STATUS_LOCKED_SHIFT            (11U)
/*! LOCKED - OTP LOCKED status during read/write operation. Write 1 to clear. */
#define OCOTP_OTP_STATUS_LOCKED(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_LOCKED_SHIFT)) & OCOTP_OTP_STATUS_LOCKED_MASK)

#define OCOTP_OTP_STATUS_PROGFAIL_MASK           (0x1000U)
#define OCOTP_OTP_STATUS_PROGFAIL_SHIFT          (12U)
/*! PROGFAIL - OTP PROGFAIL status. Write 1 to clear. */
#define OCOTP_OTP_STATUS_PROGFAIL(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_PROGFAIL_SHIFT)) & OCOTP_OTP_STATUS_PROGFAIL_MASK)

#define OCOTP_OTP_STATUS_ACK_MASK                (0x2000U)
#define OCOTP_OTP_STATUS_ACK_SHIFT               (13U)
/*! ACK - OTP ACK value */
#define OCOTP_OTP_STATUS_ACK(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_ACK_SHIFT)) & OCOTP_OTP_STATUS_ACK_MASK)

#define OCOTP_OTP_STATUS_PWOK_MASK               (0x4000U)
#define OCOTP_OTP_STATUS_PWOK_SHIFT              (14U)
/*! PWOK - OTP Power OK status. Indicate that power VDD are in the operating range. */
#define OCOTP_OTP_STATUS_PWOK(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_PWOK_SHIFT)) & OCOTP_OTP_STATUS_PWOK_MASK)

#define OCOTP_OTP_STATUS_SEC_RELOAD_MASK         (0x100000U)
#define OCOTP_OTP_STATUS_SEC_RELOAD_SHIFT        (20U)
/*! SEC_RELOAD - OTP Single Error Corrected status of ECC during reload process. Write 1 to clear. */
#define OCOTP_OTP_STATUS_SEC_RELOAD(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_SEC_RELOAD_SHIFT)) & OCOTP_OTP_STATUS_SEC_RELOAD_MASK)

#define OCOTP_OTP_STATUS_DED_RELOAD_MASK         (0x200000U)
#define OCOTP_OTP_STATUS_DED_RELOAD_SHIFT        (21U)
/*! DED_RELOAD - OTP Double Error Detect status of ECC during reload process. Write 1 to clear. */
#define OCOTP_OTP_STATUS_DED_RELOAD(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_DED_RELOAD_SHIFT)) & OCOTP_OTP_STATUS_DED_RELOAD_MASK)

#define OCOTP_OTP_STATUS_BUSY_MASK               (0x400000U)
#define OCOTP_OTP_STATUS_BUSY_SHIFT              (22U)
/*! BUSY - OTP controller status */
#define OCOTP_OTP_STATUS_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_BUSY_SHIFT)) & OCOTP_OTP_STATUS_BUSY_MASK)

#define OCOTP_OTP_STATUS_ERROR_MASK              (0x800000U)
#define OCOTP_OTP_STATUS_ERROR_SHIFT             (23U)
/*! ERROR - Error */
#define OCOTP_OTP_STATUS_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_ERROR_SHIFT)) & OCOTP_OTP_STATUS_ERROR_MASK)

#define OCOTP_OTP_STATUS_CRC_FAIL_MASK           (0x1000000U)
#define OCOTP_OTP_STATUS_CRC_FAIL_SHIFT          (24U)
/*! CRC_FAIL - CRC failed when set by hardware for CRC operation. Write 1 to clear. */
#define OCOTP_OTP_STATUS_CRC_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_CRC_FAIL_SHIFT)) & OCOTP_OTP_STATUS_CRC_FAIL_MASK)

#define OCOTP_OTP_STATUS_FUSE_LATCHED_MASK       (0x2000000U)
#define OCOTP_OTP_STATUS_FUSE_LATCHED_SHIFT      (25U)
/*! FUSE_LATCHED - Indicate all shadows registers have been loaded with their corresponding fuse
 *    words when set by the controller after reset.
 */
#define OCOTP_OTP_STATUS_FUSE_LATCHED(x)         (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_STATUS_FUSE_LATCHED_SHIFT)) & OCOTP_OTP_STATUS_FUSE_LATCHED_MASK)
/*! @} */

/*! @name OTP_VERSION - VERSION ID */
/*! @{ */

#define OCOTP_OTP_VERSION_STEP_VER_MASK          (0xFFFFU)
#define OCOTP_OTP_VERSION_STEP_VER_SHIFT         (0U)
/*! STEP_VER - Step version */
#define OCOTP_OTP_VERSION_STEP_VER(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_VERSION_STEP_VER_SHIFT)) & OCOTP_OTP_VERSION_STEP_VER_MASK)

#define OCOTP_OTP_VERSION_MINOR_VER_MASK         (0xFF0000U)
#define OCOTP_OTP_VERSION_MINOR_VER_SHIFT        (16U)
/*! MINOR_VER - Minor version */
#define OCOTP_OTP_VERSION_MINOR_VER(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_VERSION_MINOR_VER_SHIFT)) & OCOTP_OTP_VERSION_MINOR_VER_MASK)

#define OCOTP_OTP_VERSION_MAJOR_VER_MASK         (0xFF000000U)
#define OCOTP_OTP_VERSION_MAJOR_VER_SHIFT        (24U)
/*! MAJOR_VER - Major version */
#define OCOTP_OTP_VERSION_MAJOR_VER(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_OTP_VERSION_MAJOR_VER_SHIFT)) & OCOTP_OTP_VERSION_MAJOR_VER_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OCOTP_Register_Masks */


/*!
 * @}
 */ /* end of group OCOTP_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OCOTP_H_ */

