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
**         CMSIS Peripheral Access Layer for TRGSYNC
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
 * @file PERI_TRGSYNC.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for TRGSYNC
 *
 * CMSIS Peripheral Access Layer for TRGSYNC
 */

#if !defined(PERI_TRGSYNC_H_)
#define PERI_TRGSYNC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- TRGSYNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGSYNC_Peripheral_Access_Layer TRGSYNC Peripheral Access Layer
 * @{
 */

/** TRGSYNC - Size of Registers Arrays */
#define TRGSYNC_CHANNEL_COUNT                     8u

/** TRGSYNC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHANNEL[TRGSYNC_CHANNEL_COUNT];    /**< Channel, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGSYNC_Type;

/* ----------------------------------------------------------------------------
   -- TRGSYNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGSYNC_Register_Masks TRGSYNC Register Masks
 * @{
 */

/*! @name CHANNEL - Channel */
/*! @{ */

#define TRGSYNC_CHANNEL_CH_ENA_MASK              (0x1U)
#define TRGSYNC_CHANNEL_CH_ENA_SHIFT             (0U)
/*! CH_ENA - Channel Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TRGSYNC_CHANNEL_CH_ENA(x)                (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_CH_ENA_SHIFT)) & TRGSYNC_CHANNEL_CH_ENA_MASK)

#define TRGSYNC_CHANNEL_POL_SEL_MASK             (0x2U)
#define TRGSYNC_CHANNEL_POL_SEL_SHIFT            (1U)
/*! POL_SEL - Polarity Select
 *  0b0..Does not invert polarity
 *  0b1..Inverts polarity
 */
#define TRGSYNC_CHANNEL_POL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_POL_SEL_SHIFT)) & TRGSYNC_CHANNEL_POL_SEL_MASK)

#define TRGSYNC_CHANNEL_STRETCH_WIDTH_MASK       (0x7CU)
#define TRGSYNC_CHANNEL_STRETCH_WIDTH_SHIFT      (2U)
/*! STRETCH_WIDTH - Stretch Width Configure */
#define TRGSYNC_CHANNEL_STRETCH_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_STRETCH_WIDTH_SHIFT)) & TRGSYNC_CHANNEL_STRETCH_WIDTH_MASK)

#define TRGSYNC_CHANNEL_FUNC_CK_ENA_MASK         (0x80U)
#define TRGSYNC_CHANNEL_FUNC_CK_ENA_SHIFT        (7U)
/*! FUNC_CK_ENA - Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define TRGSYNC_CHANNEL_FUNC_CK_ENA(x)           (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_FUNC_CK_ENA_SHIFT)) & TRGSYNC_CHANNEL_FUNC_CK_ENA_MASK)

#define TRGSYNC_CHANNEL_FUNC_CK_MUX_MASK         (0x100U)
#define TRGSYNC_CHANNEL_FUNC_CK_MUX_SHIFT        (8U)
/*! FUNC_CK_MUX - Function Clock MUX
 *  0b0..Selects clock source0
 *  0b1..Selects clock source1
 */
#define TRGSYNC_CHANNEL_FUNC_CK_MUX(x)           (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_FUNC_CK_MUX_SHIFT)) & TRGSYNC_CHANNEL_FUNC_CK_MUX_MASK)

#define TRGSYNC_CHANNEL_LOCK_MASK                (0x80000000U)
#define TRGSYNC_CHANNEL_LOCK_SHIFT               (31U)
/*! LOCK - Lock
 *  0b0..Does not lock
 *  0b1..Locks
 */
#define TRGSYNC_CHANNEL_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << TRGSYNC_CHANNEL_LOCK_SHIFT)) & TRGSYNC_CHANNEL_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGSYNC_Register_Masks */


/*!
 * @}
 */ /* end of group TRGSYNC_Peripheral_Access_Layer */


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


#endif  /* PERI_TRGSYNC_H_ */

