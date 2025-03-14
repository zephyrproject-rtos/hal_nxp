/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IRQSTEER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file IRQSTEER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for IRQSTEER
 *
 * CMSIS Peripheral Access Layer for IRQSTEER
 */

#if !defined(IRQSTEER_H_)
#define IRQSTEER_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- IRQSTEER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Peripheral_Access_Layer IRQSTEER Peripheral Access Layer
 * @{
 */

/** IRQSTEER - Size of Registers Arrays */
#define IRQSTEER_CHn_MASK_COUNT                   20u
#define IRQSTEER_CHn_SET_COUNT                    20u
#define IRQSTEER_CHn_STATUS_COUNT                 20u

/** IRQSTEER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHn_MASK[IRQSTEER_CHn_MASK_COUNT]; /**< Channel n Interrupt Mask Register, array offset: 0x4, array step: 0x4 */
  __IO uint32_t CHn_SET[IRQSTEER_CHn_SET_COUNT];   /**< Channel n Interrupt Set Register, array offset: 0x54, array step: 0x4 */
  __I  uint32_t CHn_STATUS[IRQSTEER_CHn_STATUS_COUNT]; /**< Channel n Interrupt Status Register, array offset: 0xA4, array step: 0x4 */
  __IO uint32_t CHn_MINTDIS;                       /**< Channel n Master Interrupt Disable Register., offset: 0xF4 */
  __I  uint32_t CHn_MSTRSTAT;                      /**< Channel n Master Status Register, offset: 0xF8 */
} IRQSTEER_Type;

/* ----------------------------------------------------------------------------
   -- IRQSTEER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Register_Masks IRQSTEER Register Masks
 * @{
 */

/*! @name CHn_MASK - Channel n Interrupt Mask Register */
/*! @{ */

#define IRQSTEER_CHn_MASK_MASKFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHn_MASK_MASKFLD_SHIFT          (0U)
/*! MASKFLD - Mask bits
 *  0b00000000000000000000000000000000..Mask interrupt
 *  0b00000000000000000000000000000001..Do not mask interrupt
 */
#define IRQSTEER_CHn_MASK_MASKFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHn_MASK_MASKFLD_SHIFT)) & IRQSTEER_CHn_MASK_MASKFLD_MASK)
/*! @} */

/*! @name CHn_SET - Channel n Interrupt Set Register */
/*! @{ */

#define IRQSTEER_CHn_SET_FORCEFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHn_SET_FORCEFLD_SHIFT          (0U)
/*! FORCEFLD - Force interrupt.
 *  0b00000000000000000000000000000000..Normal operation
 *  0b00000000000000000000000000000001..Force interrupt
 */
#define IRQSTEER_CHn_SET_FORCEFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHn_SET_FORCEFLD_SHIFT)) & IRQSTEER_CHn_SET_FORCEFLD_MASK)
/*! @} */

/*! @name CHn_STATUS - Channel n Interrupt Status Register */
/*! @{ */

#define IRQSTEER_CHn_STATUS_STATUS_MASK          (0xFFFFFFFFU)
#define IRQSTEER_CHn_STATUS_STATUS_SHIFT         (0U)
/*! STATUS - Status of an interrupt
 *  0b00000000000000000000000000000000..Interrupt is not set.
 *  0b00000000000000000000000000000001..Interrupt is set.
 */
#define IRQSTEER_CHn_STATUS_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHn_STATUS_STATUS_SHIFT)) & IRQSTEER_CHn_STATUS_STATUS_MASK)
/*! @} */

/*! @name CHn_MINTDIS - Channel n Master Interrupt Disable Register. */
/*! @{ */

#define IRQSTEER_CHn_MINTDIS_DISABLE_MASK        (0x3FFU)
#define IRQSTEER_CHn_MINTDIS_DISABLE_SHIFT       (0U)
/*! DISABLE - Each bit of this field disables the corresponding interrupts in table above.
 *  0b0000000000..Enable interrupts
 *  0b0000000001..Disable interrupts
 */
#define IRQSTEER_CHn_MINTDIS_DISABLE(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHn_MINTDIS_DISABLE_SHIFT)) & IRQSTEER_CHn_MINTDIS_DISABLE_MASK)
/*! @} */

/*! @name CHn_MSTRSTAT - Channel n Master Status Register */
/*! @{ */

#define IRQSTEER_CHn_MSTRSTAT_STATUS_MASK        (0x1U)
#define IRQSTEER_CHn_MSTRSTAT_STATUS_SHIFT       (0U)
/*! STATUS - Status of all interrupts
 *  0b0..No interrupts are asserted.
 *  0b1..At least one interrupt is asserted.
 */
#define IRQSTEER_CHn_MSTRSTAT_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHn_MSTRSTAT_STATUS_SHIFT)) & IRQSTEER_CHn_MSTRSTAT_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IRQSTEER_Register_Masks */

/* Backward compatibility */
#define IRQSTEER_IRQS                            { IRQSTEER_0_IRQn, IRQSTEER_1_IRQn, IRQSTEER_2_IRQn, IRQSTEER_3_IRQn, IRQSTEER_4_IRQn, IRQSTEER_5_IRQn, IRQSTEER_6_IRQn, IRQSTEER_7_IRQn, IRQSTEER_8_IRQn, IRQSTEER_9_IRQn}


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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* IRQSTEER_H_ */

