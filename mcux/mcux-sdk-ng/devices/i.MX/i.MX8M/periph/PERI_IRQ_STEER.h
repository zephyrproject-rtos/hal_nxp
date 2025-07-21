/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IRQ_STEER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IRQ_STEER.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IRQ_STEER
 *
 * CMSIS Peripheral Access Layer for IRQ_STEER
 */

#if !defined(PERI_IRQ_STEER_H_)
#define PERI_IRQ_STEER_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- IRQ_STEER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_STEER_Peripheral_Access_Layer IRQ_STEER Peripheral Access Layer
 * @{
 */

/** IRQ_STEER - Size of Registers Arrays */
#define IRQ_STEER_CHN_MASK_COUNT                  16u
#define IRQ_STEER_CHN_SET_COUNT                   16u
#define IRQ_STEER_CHN_STATUS_COUNT                16u

/** IRQ_STEER - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHANNCTL;                          /**< Channel n Control Register, offset: 0x0 */
  __IO uint32_t CHN_MASK[IRQ_STEER_CHN_MASK_COUNT]; /**< Channel n Interrupt Mask Register, array offset: 0x4, array step: 0x4 */
  __IO uint32_t CHN_SET[IRQ_STEER_CHN_SET_COUNT];  /**< Channel n Interrupt Set Register, array offset: 0x44, array step: 0x4 */
  __I  uint32_t CHN_STATUS[IRQ_STEER_CHN_STATUS_COUNT]; /**< Channel n Interrupt Status Register, array offset: 0x84, array step: 0x4 */
  __IO uint32_t CHN_MINTDIS;                       /**< Channel n Master Interrupt Disable Register, offset: 0xC4 */
  __I  uint32_t CHN_MSTRSTAT;                      /**< Channel n Master Status Register, offset: 0xC8 */
} IRQ_STEER_Type;

/* ----------------------------------------------------------------------------
   -- IRQ_STEER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_STEER_Register_Masks IRQ_STEER Register Masks
 * @{
 */

/*! @name CHANNCTL - Channel n Control Register */
/*! @{ */

#define IRQ_STEER_CHANNCTL_CH0_MASK              (0x1U)
#define IRQ_STEER_CHANNCTL_CH0_SHIFT             (0U)
/*! CH0 - Channel 0 control
 *  0b0..Disable channel 0
 *  0b1..Enable channel 0
 */
#define IRQ_STEER_CHANNCTL_CH0(x)                (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHANNCTL_CH0_SHIFT)) & IRQ_STEER_CHANNCTL_CH0_MASK)

#define IRQ_STEER_CHANNCTL_CH1_MASK              (0x2U)
#define IRQ_STEER_CHANNCTL_CH1_SHIFT             (1U)
/*! CH1 - Channel 1 control
 *  0b0..Disable channel 1
 *  0b1..Enable channel 1
 */
#define IRQ_STEER_CHANNCTL_CH1(x)                (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHANNCTL_CH1_SHIFT)) & IRQ_STEER_CHANNCTL_CH1_MASK)

#define IRQ_STEER_CHANNCTL_CH2_MASK              (0x4U)
#define IRQ_STEER_CHANNCTL_CH2_SHIFT             (2U)
/*! CH2 - Channel 2 control
 *  0b0..Disable channel 2
 *  0b1..Enable channel 2
 */
#define IRQ_STEER_CHANNCTL_CH2(x)                (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHANNCTL_CH2_SHIFT)) & IRQ_STEER_CHANNCTL_CH2_MASK)

#define IRQ_STEER_CHANNCTL_CH3_MASK              (0x8U)
#define IRQ_STEER_CHANNCTL_CH3_SHIFT             (3U)
/*! CH3 - Channel 3 control
 *  0b0..Disable channel 3
 *  0b1..Enable channel 3
 */
#define IRQ_STEER_CHANNCTL_CH3(x)                (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHANNCTL_CH3_SHIFT)) & IRQ_STEER_CHANNCTL_CH3_MASK)

#define IRQ_STEER_CHANNCTL_CH4_MASK              (0x10U)
#define IRQ_STEER_CHANNCTL_CH4_SHIFT             (4U)
/*! CH4 - Channel 4 control
 *  0b0..Disable channel 4
 *  0b1..Enable channel 4
 */
#define IRQ_STEER_CHANNCTL_CH4(x)                (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHANNCTL_CH4_SHIFT)) & IRQ_STEER_CHANNCTL_CH4_MASK)
/*! @} */

/*! @name CHN_MASK - Channel n Interrupt Mask Register */
/*! @{ */

#define IRQ_STEER_CHN_MASK_MASKFLD_MASK          (0xFFFFFFFFU)
#define IRQ_STEER_CHN_MASK_MASKFLD_SHIFT         (0U)
/*! MASKFLD - Mask bits
 *  0b00000000000000000000000000000000..Mask interrupt
 *  0b00000000000000000000000000000001..Do not mask interrupt
 */
#define IRQ_STEER_CHN_MASK_MASKFLD(x)            (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHN_MASK_MASKFLD_SHIFT)) & IRQ_STEER_CHN_MASK_MASKFLD_MASK)
/*! @} */

/*! @name CHN_SET - Channel n Interrupt Set Register */
/*! @{ */

#define IRQ_STEER_CHN_SET_FORCEFLD_MASK          (0xFFFFFFFFU)
#define IRQ_STEER_CHN_SET_FORCEFLD_SHIFT         (0U)
/*! FORCEFLD - Brief bitfield description.
 *  0b00000000000000000000000000000000..Normal operation
 *  0b00000000000000000000000000000001..Force interrupt
 */
#define IRQ_STEER_CHN_SET_FORCEFLD(x)            (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHN_SET_FORCEFLD_SHIFT)) & IRQ_STEER_CHN_SET_FORCEFLD_MASK)
/*! @} */

/*! @name CHN_STATUS - Channel n Interrupt Status Register */
/*! @{ */

#define IRQ_STEER_CHN_STATUS_STATUS_MASK         (0xFFFFFFFFU)
#define IRQ_STEER_CHN_STATUS_STATUS_SHIFT        (0U)
/*! STATUS - Status of an interrupt
 *  0b00000000000000000000000000000000..Interrupt is not set.
 *  0b00000000000000000000000000000001..Interrupt is set.
 */
#define IRQ_STEER_CHN_STATUS_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHN_STATUS_STATUS_SHIFT)) & IRQ_STEER_CHN_STATUS_STATUS_MASK)
/*! @} */

/*! @name CHN_MINTDIS - Channel n Master Interrupt Disable Register */
/*! @{ */

#define IRQ_STEER_CHN_MINTDIS_DISABLE_MASK       (0xFFU)
#define IRQ_STEER_CHN_MINTDIS_DISABLE_SHIFT      (0U)
/*! DISABLE - Each bit of this field disables the corresponding interrupts in table above.
 *  0b00000000..Enable interrupts
 *  0b00000001..Disable interrupts
 */
#define IRQ_STEER_CHN_MINTDIS_DISABLE(x)         (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHN_MINTDIS_DISABLE_SHIFT)) & IRQ_STEER_CHN_MINTDIS_DISABLE_MASK)
/*! @} */

/*! @name CHN_MSTRSTAT - Channel n Master Status Register */
/*! @{ */

#define IRQ_STEER_CHN_MSTRSTAT_STATUS_MASK       (0x1U)
#define IRQ_STEER_CHN_MSTRSTAT_STATUS_SHIFT      (0U)
/*! STATUS - Status of all interrupts
 *  0b0..No interrupts are asserted.
 *  0b1..At least one interrupt is asserted.
 */
#define IRQ_STEER_CHN_MSTRSTAT_STATUS(x)         (((uint32_t)(((uint32_t)(x)) << IRQ_STEER_CHN_MSTRSTAT_STATUS_SHIFT)) & IRQ_STEER_CHN_MSTRSTAT_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IRQ_STEER_Register_Masks */


/*!
 * @}
 */ /* end of group IRQ_STEER_Peripheral_Access_Layer */


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


#endif  /* PERI_IRQ_STEER_H_ */

