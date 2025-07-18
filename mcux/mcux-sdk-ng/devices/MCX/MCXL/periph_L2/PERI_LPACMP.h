/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPACMP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_LPACMP.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for LPACMP
 *
 * CMSIS Peripheral Access Layer for LPACMP
 */

#if !defined(PERI_LPACMP_H_)
#define PERI_LPACMP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- LPACMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPACMP_Peripheral_Access_Layer LPACMP Peripheral Access Layer
 * @{
 */

/** LPACMP - Size of Registers Arrays */
#define LPACMP_EXT_TRIG_COUNT                     4u

/** LPACMP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
  __IO uint32_t INTERVAL;                          /**< Interval, offset: 0x4 */
  __IO uint32_t COMP_IF;                           /**< Comparison, offset: 0x8 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x10, array step: 0x10 */
    __IO uint32_t SEL;                               /**< Select, array offset: 0x10, array step: 0x10 */
    __IO uint32_t DELAY;                             /**< Delay, array offset: 0x14, array step: 0x10 */
    __IO uint32_t STATUS;                            /**< Status, array offset: 0x18, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } EXT_TRIG[LPACMP_EXT_TRIG_COUNT];
} LPACMP_Type;

/* ----------------------------------------------------------------------------
   -- LPACMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPACMP_Register_Masks LPACMP Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define LPACMP_CTRL_BLOCK_EN_MASK                (0x1U)
#define LPACMP_CTRL_BLOCK_EN_SHIFT               (0U)
/*! BLOCK_EN - Comparator Block Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPACMP_CTRL_BLOCK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << LPACMP_CTRL_BLOCK_EN_SHIFT)) & LPACMP_CTRL_BLOCK_EN_MASK)

#define LPACMP_CTRL_MODE_MASK                    (0x6U)
#define LPACMP_CTRL_MODE_SHIFT                   (1U)
/*! MODE - Comparator Mode
 *  0b00..Continuous (the analog comparator block is active all the time)
 *  0b01..Interval (the analog comparator block is not active all the time)
 *  0b10..Trigger (receives a trigger from one of the channels)
 */
#define LPACMP_CTRL_MODE(x)                      (((uint32_t)(((uint32_t)(x)) << LPACMP_CTRL_MODE_SHIFT)) & LPACMP_CTRL_MODE_MASK)
/*! @} */

/*! @name INTERVAL - Interval */
/*! @{ */

#define LPACMP_INTERVAL_INVL_MASK                (0xFFFFU)
#define LPACMP_INTERVAL_INVL_SHIFT               (0U)
/*! INVL - Interval Value Select */
#define LPACMP_INTERVAL_INVL(x)                  (((uint32_t)(((uint32_t)(x)) << LPACMP_INTERVAL_INVL_SHIFT)) & LPACMP_INTERVAL_INVL_MASK)
/*! @} */

/*! @name COMP_IF - Comparison */
/*! @{ */

#define LPACMP_COMP_IF_MATCH_IF_MASK             (0xFFU)
#define LPACMP_COMP_IF_MATCH_IF_SHIFT            (0U)
/*! MATCH_IF - Comparator Value Comparison
 *  0b00000000..Comparison did not occur
 *  0b00000000..No effect
 *  0b00000001..Clear the flag
 *  0b00000001..Comparison occurred
 */
#define LPACMP_COMP_IF_MATCH_IF(x)               (((uint32_t)(((uint32_t)(x)) << LPACMP_COMP_IF_MATCH_IF_SHIFT)) & LPACMP_COMP_IF_MATCH_IF_MASK)
/*! @} */

/*! @name SEL - Select */
/*! @{ */

#define LPACMP_SEL_INP_SEL_MASK                  (0x7U)
#define LPACMP_SEL_INP_SEL_SHIFT                 (0U)
/*! INP_SEL - Comparator Input Select
 *  0b000..comp_in4
 *  0b001..comp_in5
 *  0b010..comp_in0
 *  0b011..comp_in1
 *  0b100..comp_in2
 *  0b101..comp_in3
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define LPACMP_SEL_INP_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPACMP_SEL_INP_SEL_SHIFT)) & LPACMP_SEL_INP_SEL_MASK)

#define LPACMP_SEL_HIGHER_MASK                   (0x8U)
#define LPACMP_SEL_HIGHER_SHIFT                  (3U)
/*! HIGHER - Comparator Voltage Compare
 *  0b0..When the value we are checking is lower than the reference value
 *  0b1..When the value we are checking is higher than the reference value
 */
#define LPACMP_SEL_HIGHER(x)                     (((uint32_t)(((uint32_t)(x)) << LPACMP_SEL_HIGHER_SHIFT)) & LPACMP_SEL_HIGHER_MASK)

#define LPACMP_SEL_INN_SEL_MASK                  (0xF00U)
#define LPACMP_SEL_INN_SEL_SHIFT                 (8U)
/*! INN_SEL - Reference Value Select
 *  0b0000..Internal VREF value of - 1 x AVDD/15
 *  0b0001..Internal VREF value of - 2 x AVDD/15
 *  0b0010..Internal VREF value of - 3 x AVDD/15
 *  0b0011..Internal VREF value of - 4 x AVDD/15
 *  0b0100..Internal VREF value of - 5 x AVDD/15
 *  0b0101..Internal VREF value of - 6 x AVDD/15
 *  0b0110..Internal VREF value of - 7 x AVDD/15
 *  0b0111..Internal VREF value of - 8 x AVDD/15
 *  0b1000..Internal VREF value of - 9 x AVDD/15
 *  0b1001..Internal VREF value of - 10 x AVDD/15
 *  0b1010..Internal VREF value of - 11 x AVDD/15
 *  0b1011..Internal VREF value of - 12 x AVDD/15
 *  0b1100..Internal VREF value of - 13 x AVDD/15
 *  0b1101..Internal VREF value of - 14 x AVDD/15
 *  0b1110..External input connected to I/O pads comp_in4
 *  0b1111..External input connected to I/O pads comp_in5
 */
#define LPACMP_SEL_INN_SEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPACMP_SEL_INN_SEL_SHIFT)) & LPACMP_SEL_INN_SEL_MASK)
/*! @} */

/* The count of LPACMP_SEL */
#define LPACMP_SEL_COUNT                         (4U)

/*! @name DELAY - Delay */
/*! @{ */

#define LPACMP_DELAY_DEL_MASK                    (0xFFFFU)
#define LPACMP_DELAY_DEL_SHIFT                   (0U)
/*! DEL - Delay Value Select */
#define LPACMP_DELAY_DEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPACMP_DELAY_DEL_SHIFT)) & LPACMP_DELAY_DEL_MASK)
/*! @} */

/* The count of LPACMP_DELAY */
#define LPACMP_DELAY_COUNT                       (4U)

/*! @name STATUS - Status */
/*! @{ */

#define LPACMP_STATUS_CHNL_EN_MASK               (0x1U)
#define LPACMP_STATUS_CHNL_EN_SHIFT              (0U)
/*! CHNL_EN - Channel Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPACMP_STATUS_CHNL_EN(x)                 (((uint32_t)(((uint32_t)(x)) << LPACMP_STATUS_CHNL_EN_SHIFT)) & LPACMP_STATUS_CHNL_EN_MASK)

#define LPACMP_STATUS_MATCH_IE_MASK              (0x2U)
#define LPACMP_STATUS_MATCH_IE_SHIFT             (1U)
/*! MATCH_IE - Enable Comparator Value Match Interrupt
 *  0b0..Interrupt is not allowed
 *  0b1..Interrupt is allowed
 */
#define LPACMP_STATUS_MATCH_IE(x)                (((uint32_t)(((uint32_t)(x)) << LPACMP_STATUS_MATCH_IE_SHIFT)) & LPACMP_STATUS_MATCH_IE_MASK)

#define LPACMP_STATUS_TRGOP_EN_MASK              (0x4U)
#define LPACMP_STATUS_TRGOP_EN_SHIFT             (2U)
/*! TRGOP_EN - Trigger Output Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPACMP_STATUS_TRGOP_EN(x)                (((uint32_t)(((uint32_t)(x)) << LPACMP_STATUS_TRGOP_EN_SHIFT)) & LPACMP_STATUS_TRGOP_EN_MASK)

#define LPACMP_STATUS_WAKEUPEN_MASK              (0x8U)
#define LPACMP_STATUS_WAKEUPEN_SHIFT             (3U)
/*! WAKEUPEN - Wakeup Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LPACMP_STATUS_WAKEUPEN(x)                (((uint32_t)(((uint32_t)(x)) << LPACMP_STATUS_WAKEUPEN_SHIFT)) & LPACMP_STATUS_WAKEUPEN_MASK)

#define LPACMP_STATUS_TRGOPWDH_MASK              (0xFF00U)
#define LPACMP_STATUS_TRGOPWDH_SHIFT             (8U)
/*! TRGOPWDH - Trigger Output Width */
#define LPACMP_STATUS_TRGOPWDH(x)                (((uint32_t)(((uint32_t)(x)) << LPACMP_STATUS_TRGOPWDH_SHIFT)) & LPACMP_STATUS_TRGOPWDH_MASK)
/*! @} */

/* The count of LPACMP_STATUS */
#define LPACMP_STATUS_COUNT                      (4U)


/*!
 * @}
 */ /* end of group LPACMP_Register_Masks */


/*!
 * @}
 */ /* end of group LPACMP_Peripheral_Access_Layer */


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


#endif  /* PERI_LPACMP_H_ */

