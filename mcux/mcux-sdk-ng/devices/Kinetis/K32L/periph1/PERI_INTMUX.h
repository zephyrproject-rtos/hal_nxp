/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INTMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_INTMUX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INTMUX
 *
 * CMSIS Peripheral Access Layer for INTMUX
 */

#if !defined(PERI_INTMUX_H_)
#define PERI_INTMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- INTMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Peripheral_Access_Layer INTMUX Peripheral Access Layer
 * @{
 */

/** INTMUX - Size of Registers Arrays */
#define INTMUX_CHANNEL_COUNT                      4u

/** INTMUX - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x40 */
    __IO uint32_t CHn_CSR;                           /**< Channel n Control Status Register, array offset: 0x0, array step: 0x40 */
    __I  uint32_t CHn_VEC;                           /**< Channel n Vector Number Register, array offset: 0x4, array step: 0x40 */
         uint8_t RESERVED_0[8];
    __IO uint32_t CHn_IER_31_0;                      /**< Channel n Interrupt Enable Register, array offset: 0x10, array step: 0x40 */
         uint8_t RESERVED_1[12];
    __I  uint32_t CHn_IPR_31_0;                      /**< Channel n Interrupt Pending Register, array offset: 0x20, array step: 0x40 */
         uint8_t RESERVED_2[28];
  } CHANNEL[INTMUX_CHANNEL_COUNT];
} INTMUX_Type;

/* ----------------------------------------------------------------------------
   -- INTMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTMUX_Register_Masks INTMUX Register Masks
 * @{
 */

/*! @name CHn_CSR - Channel n Control Status Register */
/*! @{ */

#define INTMUX_CHn_CSR_RST_MASK                  (0x1U)
#define INTMUX_CHn_CSR_RST_SHIFT                 (0U)
/*! RST - Software Reset
 *  0b0..No operation.
 *  0b1..Perform a software reset on this channel.
 */
#define INTMUX_CHn_CSR_RST(x)                    (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_CSR_RST_SHIFT)) & INTMUX_CHn_CSR_RST_MASK)

#define INTMUX_CHn_CSR_AND_MASK                  (0x2U)
#define INTMUX_CHn_CSR_AND_SHIFT                 (1U)
/*! AND - Logic AND
 *  0b0..Logic OR all enabled interrupt inputs.
 *  0b1..Logic AND all enabled interrupt inputs.
 */
#define INTMUX_CHn_CSR_AND(x)                    (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_CSR_AND_SHIFT)) & INTMUX_CHn_CSR_AND_MASK)

#define INTMUX_CHn_CSR_IRQN_MASK                 (0x30U)
#define INTMUX_CHn_CSR_IRQN_SHIFT                (4U)
/*! IRQN - Channel Input Number
 *  0b00..32 interrupt inputs
 *  0b01..Reserved
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define INTMUX_CHn_CSR_IRQN(x)                   (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_CSR_IRQN_SHIFT)) & INTMUX_CHn_CSR_IRQN_MASK)

#define INTMUX_CHn_CSR_CHIN_MASK                 (0xF00U)
#define INTMUX_CHn_CSR_CHIN_SHIFT                (8U)
/*! CHIN - Channel Instance Number */
#define INTMUX_CHn_CSR_CHIN(x)                   (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_CSR_CHIN_SHIFT)) & INTMUX_CHn_CSR_CHIN_MASK)

#define INTMUX_CHn_CSR_IRQP_MASK                 (0x80000000U)
#define INTMUX_CHn_CSR_IRQP_SHIFT                (31U)
/*! IRQP - Channel Interrupt Request Pending
 *  0b0..No interrupt is pending.
 *  0b1..The interrupt output of this channel is pending.
 */
#define INTMUX_CHn_CSR_IRQP(x)                   (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_CSR_IRQP_SHIFT)) & INTMUX_CHn_CSR_IRQP_MASK)
/*! @} */

/* The count of INTMUX_CHn_CSR */
#define INTMUX_CHn_CSR_COUNT                     (4U)

/*! @name CHn_VEC - Channel n Vector Number Register */
/*! @{ */

#define INTMUX_CHn_VEC_VECN_MASK                 (0x3FFCU)
#define INTMUX_CHn_VEC_VECN_SHIFT                (2U)
/*! VECN - Vector Number */
#define INTMUX_CHn_VEC_VECN(x)                   (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_VEC_VECN_SHIFT)) & INTMUX_CHn_VEC_VECN_MASK)
/*! @} */

/* The count of INTMUX_CHn_VEC */
#define INTMUX_CHn_VEC_COUNT                     (4U)

/*! @name CHn_IER_31_0 - Channel n Interrupt Enable Register */
/*! @{ */

#define INTMUX_CHn_IER_31_0_INTE_MASK            (0xFFFFFFFFU)
#define INTMUX_CHn_IER_31_0_INTE_SHIFT           (0U)
/*! INTE - Interrupt Enable
 *  0b00000000000000000000000000000000..Interrupt is disabled.
 *  0b00000000000000000000000000000001..Interrupt is enabled.
 */
#define INTMUX_CHn_IER_31_0_INTE(x)              (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_IER_31_0_INTE_SHIFT)) & INTMUX_CHn_IER_31_0_INTE_MASK)
/*! @} */

/* The count of INTMUX_CHn_IER_31_0 */
#define INTMUX_CHn_IER_31_0_COUNT                (4U)

/*! @name CHn_IPR_31_0 - Channel n Interrupt Pending Register */
/*! @{ */

#define INTMUX_CHn_IPR_31_0_INTP_MASK            (0xFFFFFFFFU)
#define INTMUX_CHn_IPR_31_0_INTP_SHIFT           (0U)
/*! INTP - Interrupt Pending
 *  0b00000000000000000000000000000000..No interrupt.
 *  0b00000000000000000000000000000001..Interrupt is pending.
 */
#define INTMUX_CHn_IPR_31_0_INTP(x)              (((uint32_t)(((uint32_t)(x)) << INTMUX_CHn_IPR_31_0_INTP_SHIFT)) & INTMUX_CHn_IPR_31_0_INTP_MASK)
/*! @} */

/* The count of INTMUX_CHn_IPR_31_0 */
#define INTMUX_CHn_IPR_31_0_COUNT                (4U)


/*!
 * @}
 */ /* end of group INTMUX_Register_Masks */


/*!
 * @}
 */ /* end of group INTMUX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_INTMUX_H_ */

