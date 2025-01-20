/*
** ###################################################################
**     Processors:          MCXN546VDF_cm33_core0
**                          MCXN546VDF_cm33_core1
**                          MCXN546VKL_cm33_core0
**                          MCXN546VKL_cm33_core1
**                          MCXN546VNL_cm33_core0
**                          MCXN546VNL_cm33_core1
**                          MCXN546VPB_cm33_core0
**                          MCXN546VPB_cm33_core1
**                          MCXN547VDF_cm33_core0
**                          MCXN547VDF_cm33_core1
**                          MCXN547VKL_cm33_core0
**                          MCXN547VKL_cm33_core1
**                          MCXN547VNL_cm33_core0
**                          MCXN547VNL_cm33_core1
**                          MCXN547VPB_cm33_core0
**                          MCXN547VPB_cm33_core1
**                          MCXN946VDF_cm33_core0
**                          MCXN946VDF_cm33_core1
**                          MCXN946VKL_cm33_core0
**                          MCXN946VKL_cm33_core1
**                          MCXN946VNL_cm33_core0
**                          MCXN946VNL_cm33_core1
**                          MCXN946VPB_cm33_core0
**                          MCXN946VPB_cm33_core1
**                          MCXN947VDF_cm33_core0
**                          MCXN947VDF_cm33_core1
**                          MCXN947VKL_cm33_core0
**                          MCXN947VKL_cm33_core1
**                          MCXN947VNL_cm33_core0
**                          MCXN947VNL_cm33_core1
**                          MCXN947VPB_cm33_core0
**                          MCXN947VPB_cm33_core1
**
**     Version:             rev. 2.0, 2023-02-01
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MAILBOX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-10-01)
**         Initial version
**     - rev. 2.0 (2023-02-01)
**         Initial version based on Rev. 2 Draft B
**
** ###################################################################
*/

/*!
 * @file MAILBOX.h
 * @version 2.0
 * @date 2023-02-01
 * @brief CMSIS Peripheral Access Layer for MAILBOX
 *
 * CMSIS Peripheral Access Layer for MAILBOX
 */

#if !defined(MAILBOX_H_)
#define MAILBOX_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXN546VDF_cm33_core0) || defined(CPU_MCXN546VKL_cm33_core0) || defined(CPU_MCXN546VNL_cm33_core0) || defined(CPU_MCXN546VPB_cm33_core0))
#include "MCXN546_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN546VDF_cm33_core1) || defined(CPU_MCXN546VKL_cm33_core1) || defined(CPU_MCXN546VNL_cm33_core1) || defined(CPU_MCXN546VPB_cm33_core1))
#include "MCXN546_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core0) || defined(CPU_MCXN547VKL_cm33_core0) || defined(CPU_MCXN547VNL_cm33_core0) || defined(CPU_MCXN547VPB_cm33_core0))
#include "MCXN547_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN547VDF_cm33_core1) || defined(CPU_MCXN547VKL_cm33_core1) || defined(CPU_MCXN547VNL_cm33_core1) || defined(CPU_MCXN547VPB_cm33_core1))
#include "MCXN547_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core0) || defined(CPU_MCXN946VKL_cm33_core0) || defined(CPU_MCXN946VNL_cm33_core0) || defined(CPU_MCXN946VPB_cm33_core0))
#include "MCXN946_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN946VDF_cm33_core1) || defined(CPU_MCXN946VKL_cm33_core1) || defined(CPU_MCXN946VNL_cm33_core1) || defined(CPU_MCXN946VPB_cm33_core1))
#include "MCXN946_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core0) || defined(CPU_MCXN947VKL_cm33_core0) || defined(CPU_MCXN947VNL_cm33_core0) || defined(CPU_MCXN947VPB_cm33_core0))
#include "MCXN947_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXN947VDF_cm33_core1) || defined(CPU_MCXN947VKL_cm33_core1) || defined(CPU_MCXN947VNL_cm33_core1) || defined(CPU_MCXN947VPB_cm33_core1))
#include "MCXN947_cm33_core1_COMMON.h"
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
   -- MAILBOX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAILBOX_Peripheral_Access_Layer MAILBOX Peripheral Access Layer
 * @{
 */

/** MAILBOX - Size of Registers Arrays */
#define MAILBOX_MBOXIRQ_COUNT                     2u

/** MAILBOX - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10 */
    __IO uint32_t IRQ;                               /**< Cortex-M33 (CPU0) Interrupt..CoolFlux (CPU1) Interrupt, array offset: 0x0, array step: 0x10 */
    __O  uint32_t IRQSET;                            /**< Cortex-M33 (CPU0) Interrupt Set..CoolFlux (CPU1) Interrupt Set, array offset: 0x4, array step: 0x10 */
    __O  uint32_t IRQCLR;                            /**< Cortex-M33 (CPU0) Interrupt Clear..CoolFlux (CPU1) Interrupt Clear, array offset: 0x8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } MBOXIRQ[MAILBOX_MBOXIRQ_COUNT];
       uint8_t RESERVED_0[216];
  __IO uint32_t MUTEX;                             /**< Mutual Exclusion, offset: 0xF8 */
} MAILBOX_Type;

/* ----------------------------------------------------------------------------
   -- MAILBOX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAILBOX_Register_Masks MAILBOX Register Masks
 * @{
 */

/*! @name MBOXIRQ_IRQ - Cortex-M33 (CPU0) Interrupt..CoolFlux (CPU1) Interrupt */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQ_INTREQ_MASK          (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQ_INTREQ_SHIFT         (0U)
/*! INTREQ - Interrupt Request */
#define MAILBOX_MBOXIRQ_IRQ_INTREQ(x)            (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQ_INTREQ_SHIFT)) & MAILBOX_MBOXIRQ_IRQ_INTREQ_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQ */
#define MAILBOX_MBOXIRQ_IRQ_COUNT                (2U)

/*! @name MBOXIRQ_IRQSET - Cortex-M33 (CPU0) Interrupt Set..CoolFlux (CPU1) Interrupt Set */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET_MASK    (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET_SHIFT   (0U)
/*! INTREQSET - Interrupt Request Set 1 */
#define MAILBOX_MBOXIRQ_IRQSET_INTREQSET(x)      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQSET_INTREQSET_SHIFT)) & MAILBOX_MBOXIRQ_IRQSET_INTREQSET_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQSET */
#define MAILBOX_MBOXIRQ_IRQSET_COUNT             (2U)

/*! @name MBOXIRQ_IRQCLR - Cortex-M33 (CPU0) Interrupt Clear..CoolFlux (CPU1) Interrupt Clear */
/*! @{ */

#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_MASK    (0xFFFFFFFFU)
#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_SHIFT   (0U)
/*! INTREQCLR - Interrupt Request Clear 1 */
#define MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR(x)      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_SHIFT)) & MAILBOX_MBOXIRQ_IRQCLR_INTREQCLR_MASK)
/*! @} */

/* The count of MAILBOX_MBOXIRQ_IRQCLR */
#define MAILBOX_MBOXIRQ_IRQCLR_COUNT             (2U)

/*! @name MUTEX - Mutual Exclusion */
/*! @{ */

#define MAILBOX_MUTEX_EX_MASK                    (0x1U)
#define MAILBOX_MUTEX_EX_SHIFT                   (0U)
/*! EX - Mutual Exclusion Request
 *  0b0..Resource unavailable
 *  0b1..Resource available
 */
#define MAILBOX_MUTEX_EX(x)                      (((uint32_t)(((uint32_t)(x)) << MAILBOX_MUTEX_EX_SHIFT)) & MAILBOX_MUTEX_EX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MAILBOX_Register_Masks */


/*!
 * @}
 */ /* end of group MAILBOX_Peripheral_Access_Layer */


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


#endif  /* MAILBOX_H_ */

