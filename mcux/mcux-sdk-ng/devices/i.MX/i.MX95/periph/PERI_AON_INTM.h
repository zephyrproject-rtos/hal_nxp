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
**         CMSIS Peripheral Access Layer for AON_INTM
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
 * @file AON_INTM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_INTM
 *
 * CMSIS Peripheral Access Layer for AON_INTM
 */

#if !defined(AON_INTM_H_)
#define AON_INTM_H_                              /**< Symbol preventing repeated inclusion */

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
    __I  uint32_t INTM_TIMER;                        /**< Timer for Monitor 0..Timer for Monitor 3, array offset: 0x10, array step: 0x10 */
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
 *  0b1..Enable
 *  0b0..Disable
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
 *  0b1..Exceeded
 *  0b0..Did not exceed
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


#endif  /* AON_INTM_H_ */

