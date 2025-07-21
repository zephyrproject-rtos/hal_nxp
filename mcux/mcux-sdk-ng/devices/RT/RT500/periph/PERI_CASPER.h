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
**         CMSIS Peripheral Access Layer for CASPER
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
 * @file PERI_CASPER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CASPER
 *
 * CMSIS Peripheral Access Layer for CASPER
 */

#if !defined(PERI_CASPER_H_)
#define PERI_CASPER_H_                           /**< Symbol preventing repeated inclusion */

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
   -- CASPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CASPER_Peripheral_Access_Layer CASPER Peripheral Access Layer
 * @{
 */

/** CASPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL0;                             /**< Control 0, offset: 0x0 */
  __IO uint32_t CTRL1;                             /**< Control 1, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t STATUS;                            /**< Status, offset: 0xC */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable Set, offset: 0x10 */
  __IO uint32_t INTENCLR;                          /**< Interrupt Enable Clear, offset: 0x14 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t AREG;                              /**< A Register, offset: 0x20 */
  __IO uint32_t BREG;                              /**< B Register, offset: 0x24 */
  __IO uint32_t CREG;                              /**< C Register, offset: 0x28 */
  __IO uint32_t DREG;                              /**< D Register, offset: 0x2C */
  __IO uint32_t RES0;                              /**< Result Register 0, offset: 0x30 */
  __IO uint32_t RES1;                              /**< Result Register 1, offset: 0x34 */
  __IO uint32_t RES2;                              /**< Result Register 2, offset: 0x38 */
  __IO uint32_t RES3;                              /**< Result Register 3, offset: 0x3C */
       uint8_t RESERVED_2[32];
  __IO uint32_t MASK;                              /**< Mask, offset: 0x60 */
  __IO uint32_t REMASK;                            /**< Remask, offset: 0x64 */
       uint8_t RESERVED_3[24];
  __IO uint32_t LOCK;                              /**< Lock, offset: 0x80 */
} CASPER_Type;

/* ----------------------------------------------------------------------------
   -- CASPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CASPER_Register_Masks CASPER Register Masks
 * @{
 */

/*! @name CTRL0 - Control 0 */
/*! @{ */

#define CASPER_CTRL0_ABBPAIR_MASK                (0x1U)
#define CASPER_CTRL0_ABBPAIR_SHIFT               (0U)
/*! ABBPAIR - ABOFF Bank Pair
 *  0b0..Bank-pair 0 (1st)
 *  0b1..Bank-pair 1 (2nd)
 */
#define CASPER_CTRL0_ABBPAIR(x)                  (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL0_ABBPAIR_SHIFT)) & CASPER_CTRL0_ABBPAIR_MASK)

#define CASPER_CTRL0_ABOFF_MASK                  (0x4U)
#define CASPER_CTRL0_ABOFF_SHIFT                 (2U)
/*! ABOFF - AB Offset */
#define CASPER_CTRL0_ABOFF(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL0_ABOFF_SHIFT)) & CASPER_CTRL0_ABOFF_MASK)

#define CASPER_CTRL0_CDBPAIR_MASK                (0x10000U)
#define CASPER_CTRL0_CDBPAIR_SHIFT               (16U)
/*! CDBPAIR - CDOFF Bank Pair
 *  0b0..Bank-pair 0 (1st)
 *  0b1..Bank-pair 1 (2nd)
 */
#define CASPER_CTRL0_CDBPAIR(x)                  (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL0_CDBPAIR_SHIFT)) & CASPER_CTRL0_CDBPAIR_MASK)

#define CASPER_CTRL0_CDOFF_MASK                  (0x1FFC0000U)
#define CASPER_CTRL0_CDOFF_SHIFT                 (18U)
/*! CDOFF - CD Offset */
#define CASPER_CTRL0_CDOFF(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL0_CDOFF_SHIFT)) & CASPER_CTRL0_CDOFF_MASK)
/*! @} */

/*! @name CTRL1 - Control 1 */
/*! @{ */

#define CASPER_CTRL1_ITER_MASK                   (0xFFU)
#define CASPER_CTRL1_ITER_SHIFT                  (0U)
/*! ITER - Interation Counter */
#define CASPER_CTRL1_ITER(x)                     (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL1_ITER_SHIFT)) & CASPER_CTRL1_ITER_MASK)

#define CASPER_CTRL1_MODE_MASK                   (0xFF00U)
#define CASPER_CTRL1_MODE_SHIFT                  (8U)
/*! MODE - Mode */
#define CASPER_CTRL1_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL1_MODE_SHIFT)) & CASPER_CTRL1_MODE_MASK)

#define CASPER_CTRL1_RESBPAIR_MASK               (0x10000U)
#define CASPER_CTRL1_RESBPAIR_SHIFT              (16U)
/*! RESBPAIR - RESOFF Bank Pair
 *  0b0..Bank-pair 0 (1st)
 *  0b1..Bank-pair 1 (2nd)
 */
#define CASPER_CTRL1_RESBPAIR(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL1_RESBPAIR_SHIFT)) & CASPER_CTRL1_RESBPAIR_MASK)

#define CASPER_CTRL1_RESOFF_MASK                 (0x1FFC0000U)
#define CASPER_CTRL1_RESOFF_SHIFT                (18U)
/*! RESOFF - Result Offset */
#define CASPER_CTRL1_RESOFF(x)                   (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL1_RESOFF_SHIFT)) & CASPER_CTRL1_RESOFF_MASK)

#define CASPER_CTRL1_CSKIP_MASK                  (0xC0000000U)
#define CASPER_CTRL1_CSKIP_SHIFT                 (30U)
/*! CSKIP - Skip Rules on Carry
 *  0b00..No Skip
 *  0b01..Skip if Carry is 1
 *  0b10..Skip if Carry is 0
 *  0b11..Set CTRLOFF to CDOFF and Skip
 */
#define CASPER_CTRL1_CSKIP(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_CTRL1_CSKIP_SHIFT)) & CASPER_CTRL1_CSKIP_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define CASPER_STATUS_DONE_MASK                  (0x1U)
#define CASPER_STATUS_DONE_SHIFT                 (0U)
/*! DONE - Done
 *  0b0..Busy or just cleared
 *  0b1..Completed last operation
 */
#define CASPER_STATUS_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_STATUS_DONE_SHIFT)) & CASPER_STATUS_DONE_MASK)

#define CASPER_STATUS_CARRY_MASK                 (0x10U)
#define CASPER_STATUS_CARRY_SHIFT                (4U)
/*! CARRY - Carry
 *  0b0..Carry was 0 or no carry
 *  0b1..Carry was 1
 */
#define CASPER_STATUS_CARRY(x)                   (((uint32_t)(((uint32_t)(x)) << CASPER_STATUS_CARRY_SHIFT)) & CASPER_STATUS_CARRY_MASK)

#define CASPER_STATUS_BUSY_MASK                  (0x20U)
#define CASPER_STATUS_BUSY_SHIFT                 (5U)
/*! BUSY - Busy
 *  0b0..Not busy - is idle
 *  0b1..Is busy
 */
#define CASPER_STATUS_BUSY(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_STATUS_BUSY_SHIFT)) & CASPER_STATUS_BUSY_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable Set */
/*! @{ */

#define CASPER_INTENSET_DONE_MASK                (0x1U)
#define CASPER_INTENSET_DONE_SHIFT               (0U)
/*! DONE - Done
 *  0b0..Do not interrupt when done
 *  0b1..Interrupt when done
 */
#define CASPER_INTENSET_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << CASPER_INTENSET_DONE_SHIFT)) & CASPER_INTENSET_DONE_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Enable Clear */
/*! @{ */

#define CASPER_INTENCLR_DONE_MASK                (0x1U)
#define CASPER_INTENCLR_DONE_SHIFT               (0U)
/*! DONE - Done
 *  0b0..If written 0, ignored
 *  0b1..If written 1, do not interrupt when done.
 */
#define CASPER_INTENCLR_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << CASPER_INTENCLR_DONE_SHIFT)) & CASPER_INTENCLR_DONE_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status */
/*! @{ */

#define CASPER_INTSTAT_DONE_MASK                 (0x1U)
#define CASPER_INTSTAT_DONE_SHIFT                (0U)
/*! DONE - If set, interrupt is caused by accelerator being done.
 *  0b0..Not caused by accelerator being done
 *  0b1..Caused by accelerator being done
 */
#define CASPER_INTSTAT_DONE(x)                   (((uint32_t)(((uint32_t)(x)) << CASPER_INTSTAT_DONE_SHIFT)) & CASPER_INTSTAT_DONE_MASK)
/*! @} */

/*! @name AREG - A Register */
/*! @{ */

#define CASPER_AREG_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_AREG_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_AREG_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_AREG_REG_VALUE_SHIFT)) & CASPER_AREG_REG_VALUE_MASK)
/*! @} */

/*! @name BREG - B Register */
/*! @{ */

#define CASPER_BREG_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_BREG_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_BREG_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_BREG_REG_VALUE_SHIFT)) & CASPER_BREG_REG_VALUE_MASK)
/*! @} */

/*! @name CREG - C Register */
/*! @{ */

#define CASPER_CREG_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_CREG_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_CREG_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_CREG_REG_VALUE_SHIFT)) & CASPER_CREG_REG_VALUE_MASK)
/*! @} */

/*! @name DREG - D Register */
/*! @{ */

#define CASPER_DREG_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_DREG_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_DREG_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_DREG_REG_VALUE_SHIFT)) & CASPER_DREG_REG_VALUE_MASK)
/*! @} */

/*! @name RES0 - Result Register 0 */
/*! @{ */

#define CASPER_RES0_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_RES0_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_RES0_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_RES0_REG_VALUE_SHIFT)) & CASPER_RES0_REG_VALUE_MASK)
/*! @} */

/*! @name RES1 - Result Register 1 */
/*! @{ */

#define CASPER_RES1_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_RES1_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register to hold working result (from multiplier, adder/xor, etc). */
#define CASPER_RES1_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_RES1_REG_VALUE_SHIFT)) & CASPER_RES1_REG_VALUE_MASK)
/*! @} */

/*! @name RES2 - Result Register 2 */
/*! @{ */

#define CASPER_RES2_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_RES2_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register Value */
#define CASPER_RES2_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_RES2_REG_VALUE_SHIFT)) & CASPER_RES2_REG_VALUE_MASK)
/*! @} */

/*! @name RES3 - Result Register 3 */
/*! @{ */

#define CASPER_RES3_REG_VALUE_MASK               (0xFFFFFFFFU)
#define CASPER_RES3_REG_VALUE_SHIFT              (0U)
/*! REG_VALUE - Register to hold working result (from multiplier, adder/xor, etc). */
#define CASPER_RES3_REG_VALUE(x)                 (((uint32_t)(((uint32_t)(x)) << CASPER_RES3_REG_VALUE_SHIFT)) & CASPER_RES3_REG_VALUE_MASK)
/*! @} */

/*! @name MASK - Mask */
/*! @{ */

#define CASPER_MASK_MASK_MASK                    (0xFFFFFFFFU)
#define CASPER_MASK_MASK_SHIFT                   (0U)
/*! MASK - Mask */
#define CASPER_MASK_MASK(x)                      (((uint32_t)(((uint32_t)(x)) << CASPER_MASK_MASK_SHIFT)) & CASPER_MASK_MASK_MASK)
/*! @} */

/*! @name REMASK - Remask */
/*! @{ */

#define CASPER_REMASK_MASK_MASK                  (0xFFFFFFFFU)
#define CASPER_REMASK_MASK_SHIFT                 (0U)
/*! MASK - Mask */
#define CASPER_REMASK_MASK(x)                    (((uint32_t)(((uint32_t)(x)) << CASPER_REMASK_MASK_SHIFT)) & CASPER_REMASK_MASK_MASK)
/*! @} */

/*! @name LOCK - Lock */
/*! @{ */

#define CASPER_LOCK_LOCK_MASK                    (0x1U)
#define CASPER_LOCK_LOCK_SHIFT                   (0U)
/*! LOCK - Lock
 *  0b0..Unlock
 *  0b1..Lock to current security level
 */
#define CASPER_LOCK_LOCK(x)                      (((uint32_t)(((uint32_t)(x)) << CASPER_LOCK_LOCK_SHIFT)) & CASPER_LOCK_LOCK_MASK)

#define CASPER_LOCK_KEY_MASK                     (0x1FFF0U)
#define CASPER_LOCK_KEY_SHIFT                    (4U)
/*! KEY - Key
 *  0b0011100111101..Key Value
 */
#define CASPER_LOCK_KEY(x)                       (((uint32_t)(((uint32_t)(x)) << CASPER_LOCK_KEY_SHIFT)) & CASPER_LOCK_KEY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CASPER_Register_Masks */


/*!
 * @}
 */ /* end of group CASPER_Peripheral_Access_Layer */


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


#endif  /* PERI_CASPER_H_ */

