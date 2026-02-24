/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_INTM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AON_INTM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AON_INTM
 *
 * CMSIS Peripheral Access Layer for AON_INTM
 */

#if !defined(PERI_AON_INTM_H_)
#define PERI_AON_INTM_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- AON_INTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_INTM_Peripheral_Access_Layer AON_INTM Peripheral Access Layer
 * @{
 */

/** AON_INTM - Size of Registers Arrays */
#define AON_INTM_MON_COUNT                        4u

/** AON_INTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t INTM_MM;                           /**< Monitor Mode, offset: 0x0 */
  __O  uint32_t INTM_IACK;                         /**< Interrupt Acknowledge, offset: 0x4 */
  struct {                                         /* offset: 0x8, array step: 0x10 */
    __IO uint32_t INTM_IRQSEL;                       /**< Interrupt Request Select for Monitor 0..Interrupt Request Select for Monitor 3, array offset: 0x8, array step: 0x10 */
    __IO uint32_t INTM_LATENCY;                      /**< Interrupt Latency for Monitor 0..Interrupt Latency for Monitor 3, array offset: 0xC, array step: 0x10 */
    __IO uint32_t INTM_TIMER;                        /**< Timer for Monitor 0..Timer for Monitor 3, array offset: 0x10, array step: 0x10 */
    __I  uint32_t INTM_STATUS;                       /**< Status for Monitor 0..Status for Monitor 3, array offset: 0x14, array step: 0x10 */
  } MON[AON_INTM_MON_COUNT];
} AON_INTM_Type;

/* ----------------------------------------------------------------------------
   -- AON_INTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_INTM_Register_Masks AON_INTM Register Masks
 * @{
 */

/*! @name INTM_MM - Monitor Mode */
/*! @{ */

#define AON_INTM_INTM_MM_MM_MASK                 (0x1U)
#define AON_INTM_INTM_MM_MM_SHIFT                (0U)
/*! MM - Monitor Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_INTM_INTM_MM_MM(x)                   (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_MM_MM_SHIFT)) & AON_INTM_INTM_MM_MM_MASK)
/*! @} */

/*! @name INTM_IACK - Interrupt Acknowledge */
/*! @{ */

#define AON_INTM_INTM_IACK_IRQ_MASK              (0x3FFU)
#define AON_INTM_INTM_IACK_IRQ_SHIFT             (0U)
/*! IRQ - Interrupt Request */
#define AON_INTM_INTM_IACK_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_IACK_IRQ_SHIFT)) & AON_INTM_INTM_IACK_IRQ_MASK)
/*! @} */

/*! @name INTM_IRQSEL - Interrupt Request Select for Monitor 0..Interrupt Request Select for Monitor 3 */
/*! @{ */

#define AON_INTM_INTM_IRQSEL_IRQ_MASK            (0x3FFU)
#define AON_INTM_INTM_IRQSEL_IRQ_SHIFT           (0U)
/*! IRQ - Interrupt Request */
#define AON_INTM_INTM_IRQSEL_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_IRQSEL_IRQ_SHIFT)) & AON_INTM_INTM_IRQSEL_IRQ_MASK)
/*! @} */

/* The count of AON_INTM_INTM_IRQSEL */
#define AON_INTM_INTM_IRQSEL_COUNT               (4U)

/*! @name INTM_LATENCY - Interrupt Latency for Monitor 0..Interrupt Latency for Monitor 3 */
/*! @{ */

#define AON_INTM_INTM_LATENCY_LAT_MASK           (0xFFFFFFU)
#define AON_INTM_INTM_LATENCY_LAT_SHIFT          (0U)
/*! LAT - Latency */
#define AON_INTM_INTM_LATENCY_LAT(x)             (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_LATENCY_LAT_SHIFT)) & AON_INTM_INTM_LATENCY_LAT_MASK)
/*! @} */

/* The count of AON_INTM_INTM_LATENCY */
#define AON_INTM_INTM_LATENCY_COUNT              (4U)

/*! @name INTM_TIMER - Timer for Monitor 0..Timer for Monitor 3 */
/*! @{ */

#define AON_INTM_INTM_TIMER_TIMER_MASK           (0xFFFFFFU)
#define AON_INTM_INTM_TIMER_TIMER_SHIFT          (0U)
/*! TIMER - Timer */
#define AON_INTM_INTM_TIMER_TIMER(x)             (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_TIMER_TIMER_SHIFT)) & AON_INTM_INTM_TIMER_TIMER_MASK)
/*! @} */

/* The count of AON_INTM_INTM_TIMER */
#define AON_INTM_INTM_TIMER_COUNT                (4U)

/*! @name INTM_STATUS - Status for Monitor 0..Status for Monitor 3 */
/*! @{ */

#define AON_INTM_INTM_STATUS_STATUS_MASK         (0x1U)
#define AON_INTM_INTM_STATUS_STATUS_SHIFT        (0U)
/*! STATUS - Monitor status
 *  0b0..Did not exceed
 *  0b1..Exceeded
 */
#define AON_INTM_INTM_STATUS_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << AON_INTM_INTM_STATUS_STATUS_SHIFT)) & AON_INTM_INTM_STATUS_STATUS_MASK)
/*! @} */

/* The count of AON_INTM_INTM_STATUS */
#define AON_INTM_INTM_STATUS_COUNT               (4U)


/*!
 * @}
 */ /* end of group AON_INTM_Register_Masks */


/*!
 * @}
 */ /* end of group AON_INTM_Peripheral_Access_Layer */


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


#endif  /* PERI_AON_INTM_H_ */

