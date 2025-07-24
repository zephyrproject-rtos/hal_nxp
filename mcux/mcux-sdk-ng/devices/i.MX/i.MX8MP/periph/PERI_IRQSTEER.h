/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IRQSTEER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IRQSTEER.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IRQSTEER
 *
 * CMSIS Peripheral Access Layer for IRQSTEER
 */

#if !defined(PERI_IRQSTEER_H_)
#define PERI_IRQSTEER_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- IRQSTEER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Peripheral_Access_Layer IRQSTEER Peripheral Access Layer
 * @{
 */

/** IRQSTEER - Size of Registers Arrays */
#define IRQSTEER_CHN_MASK_COUNT                   5u
#define IRQSTEER_CHN_SET_COUNT                    5u
#define IRQSTEER_CHN_STATUS_COUNT                 5u

/** IRQSTEER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHN_MASK[IRQSTEER_CHN_MASK_COUNT]; /**< Channel n Interrupt Mask Register, array offset: 0x4, array step: 0x4 */
  __IO uint32_t CHN_SET[IRQSTEER_CHN_SET_COUNT];   /**< Channel n Interrupt Set Register, array offset: 0x18, array step: 0x4 */
  __I  uint32_t CHN_STATUS[IRQSTEER_CHN_STATUS_COUNT]; /**< Channel n Interrupt Status Register, array offset: 0x2C, array step: 0x4 */
  __IO uint32_t CHN_MINTDIS;                       /**< Channel n Master Interrupt Disable Register, offset: 0x40 */
  __I  uint32_t CHN_MSTRSTAT;                      /**< Channel n Master Status Register, offset: 0x44 */
} IRQSTEER_Type;

/* ----------------------------------------------------------------------------
   -- IRQSTEER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Register_Masks IRQSTEER Register Masks
 * @{
 */

/*! @name CHN_MASK - Channel n Interrupt Mask Register */
/*! @{ */

#define IRQSTEER_CHN_MASK_MASKFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHN_MASK_MASKFLD_SHIFT          (0U)
/*! MASKFLD - Mask bits
 *  0b00000000000000000000000000000000..Mask interrupt
 *  0b00000000000000000000000000000001..Do not mask interrupt
 */
#define IRQSTEER_CHN_MASK_MASKFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MASK_MASKFLD_SHIFT)) & IRQSTEER_CHN_MASK_MASKFLD_MASK)
/*! @} */

/*! @name CHN_SET - Channel n Interrupt Set Register */
/*! @{ */

#define IRQSTEER_CHN_SET_FORCEFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHN_SET_FORCEFLD_SHIFT          (0U)
/*! FORCEFLD - Force interrupt.
 *  0b00000000000000000000000000000000..Normal operation
 *  0b00000000000000000000000000000001..Force interrupt
 */
#define IRQSTEER_CHN_SET_FORCEFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_SET_FORCEFLD_SHIFT)) & IRQSTEER_CHN_SET_FORCEFLD_MASK)
/*! @} */

/*! @name CHN_STATUS - Channel n Interrupt Status Register */
/*! @{ */

#define IRQSTEER_CHN_STATUS_STATUS_MASK          (0xFFFFFFFFU)
#define IRQSTEER_CHN_STATUS_STATUS_SHIFT         (0U)
/*! STATUS - Status of an interrupt
 *  0b00000000000000000000000000000000..Interrupt is not set.
 *  0b00000000000000000000000000000001..Interrupt is set.
 */
#define IRQSTEER_CHN_STATUS_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_STATUS_STATUS_SHIFT)) & IRQSTEER_CHN_STATUS_STATUS_MASK)
/*! @} */

/*! @name CHN_MINTDIS - Channel n Master Interrupt Disable Register */
/*! @{ */

#define IRQSTEER_CHN_MINTDIS_DISABLE_MASK        (0x7U)
#define IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT       (0U)
/*! DISABLE - Each bit of this field disables the corresponding interrupts in table above.
 *  0b000..Enable interrupts
 *  0b001..Disable interrupts
 */
#define IRQSTEER_CHN_MINTDIS_DISABLE(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT)) & IRQSTEER_CHN_MINTDIS_DISABLE_MASK)
/*! @} */

/*! @name CHN_MSTRSTAT - Channel n Master Status Register */
/*! @{ */

#define IRQSTEER_CHN_MSTRSTAT_STATUS_MASK        (0x1U)
#define IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT       (0U)
/*! STATUS - Status of all interrupts
 *  0b0..No interrupts are asserted.
 *  0b1..At least one interrupt is asserted.
 */
#define IRQSTEER_CHN_MSTRSTAT_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT)) & IRQSTEER_CHN_MSTRSTAT_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IRQSTEER_Register_Masks */


/*!
 * @}
 */ /* end of group IRQSTEER_Peripheral_Access_Layer */


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


#endif  /* PERI_IRQSTEER_H_ */

