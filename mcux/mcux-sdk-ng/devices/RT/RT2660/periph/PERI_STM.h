/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for STM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_STM.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for STM
 *
 * CMSIS Peripheral Access Layer for STM
 */

#if !defined(PERI_STM_H_)
#define PERI_STM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- STM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STM_Peripheral_Access_Layer STM Peripheral Access Layer
 * @{
 */

/** STM - Size of Registers Arrays */
#define STM_CHANNEL_COUNT                         4u

/** STM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Count, offset: 0x4 */
       uint8_t RESERVED_0[8];
  struct {                                         /* offset: 0x10, array step: 0x10 */
    __IO uint32_t CCR;                               /**< Channel Control, array offset: 0x10, array step: 0x10 */
    __IO uint32_t CIR;                               /**< Channel Interrupt, array offset: 0x14, array step: 0x10 */
    __IO uint32_t CMP;                               /**< Channel Compare, array offset: 0x18, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } CHANNEL[STM_CHANNEL_COUNT];
} STM_Type;

/* ----------------------------------------------------------------------------
   -- STM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STM_Register_Masks STM Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define STM_CR_TEN_MASK                          (0x1U)
#define STM_CR_TEN_SHIFT                         (0U)
/*! TEN - Timer Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define STM_CR_TEN(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_TEN_SHIFT)) & STM_CR_TEN_MASK)

#define STM_CR_FRZ_MASK                          (0x2U)
#define STM_CR_FRZ_SHIFT                         (1U)
/*! FRZ - Freeze
 *  0b0..Timer runs in Debug mode
 *  0b1..Timer stops in Debug mode
 */
#define STM_CR_FRZ(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_FRZ_SHIFT)) & STM_CR_FRZ_MASK)

#define STM_CR_CPS_MASK                          (0xFF00U)
#define STM_CR_CPS_SHIFT                         (8U)
/*! CPS - Counter Prescaler */
#define STM_CR_CPS(x)                            (((uint32_t)(((uint32_t)(x)) << STM_CR_CPS_SHIFT)) & STM_CR_CPS_MASK)
/*! @} */

/*! @name CNT - Count */
/*! @{ */

#define STM_CNT_CNT_MASK                         (0xFFFFFFFFU)
#define STM_CNT_CNT_SHIFT                        (0U)
/*! CNT - Timer Count */
#define STM_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CNT_CNT_SHIFT)) & STM_CNT_CNT_MASK)
/*! @} */

/*! @name CCR - Channel Control */
/*! @{ */

#define STM_CCR_CEN_MASK                         (0x1U)
#define STM_CCR_CEN_SHIFT                        (0U)
/*! CEN - Channel Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define STM_CCR_CEN(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CCR_CEN_SHIFT)) & STM_CCR_CEN_MASK)
/*! @} */

/* The count of STM_CCR */
#define STM_CCR_COUNT                            (4U)

/*! @name CIR - Channel Interrupt */
/*! @{ */

#define STM_CIR_CIF_MASK                         (0x1U)
#define STM_CIR_CIF_SHIFT                        (0U)
/*! CIF - Channel Interrupt Flag
 *  0b0..Read: IRQ is not asserted. Write: No effect.
 *  0b1..Read: IRQ is asserted. Write: Clear the flag.
 */
#define STM_CIR_CIF(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CIR_CIF_SHIFT)) & STM_CIR_CIF_MASK)
/*! @} */

/* The count of STM_CIR */
#define STM_CIR_COUNT                            (4U)

/*! @name CMP - Channel Compare */
/*! @{ */

#define STM_CMP_CMP_MASK                         (0xFFFFFFFFU)
#define STM_CMP_CMP_SHIFT                        (0U)
/*! CMP - Channel Compare */
#define STM_CMP_CMP(x)                           (((uint32_t)(((uint32_t)(x)) << STM_CMP_CMP_SHIFT)) & STM_CMP_CMP_MASK)
/*! @} */

/* The count of STM_CMP */
#define STM_CMP_COUNT                            (4U)


/*!
 * @}
 */ /* end of group STM_Register_Masks */


/*!
 * @}
 */ /* end of group STM_Peripheral_Access_Layer */


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


#endif  /* PERI_STM_H_ */

