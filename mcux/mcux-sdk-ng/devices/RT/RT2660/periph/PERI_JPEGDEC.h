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
**         CMSIS Peripheral Access Layer for JPEGDEC
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
 * @file PERI_JPEGDEC.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for JPEGDEC
 *
 * CMSIS Peripheral Access Layer for JPEGDEC
 */

#if !defined(PERI_JPEGDEC_H_)
#define PERI_JPEGDEC_H_                          /**< Symbol preventing repeated inclusion */

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
   -- JPEGDEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPEGDEC_Peripheral_Access_Layer JPEGDEC Peripheral Access Layer
 * @{
 */

/** JPEGDEC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[52];
  __IO uint32_t CTRL;                              /**< Control, offset: 0x34 */
} JPEGDEC_Type;

/* ----------------------------------------------------------------------------
   -- JPEGDEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPEGDEC_Register_Masks JPEGDEC Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define JPEGDEC_CTRL_LP_MASK                     (0x1U)
#define JPEGDEC_CTRL_LP_SHIFT                    (0U)
/*! LP - Low Power
 *  0b0..No effect
 *  0b1..Enable
 */
#define JPEGDEC_CTRL_LP(x)                       (((uint32_t)(((uint32_t)(x)) << JPEGDEC_CTRL_LP_SHIFT)) & JPEGDEC_CTRL_LP_MASK)

#define JPEGDEC_CTRL_SWR_MASK                    (0x2U)
#define JPEGDEC_CTRL_SWR_SHIFT                   (1U)
/*! SWR - Soft Reset
 *  0b0..No effect
 *  0b1..Enable
 */
#define JPEGDEC_CTRL_SWR(x)                      (((uint32_t)(((uint32_t)(x)) << JPEGDEC_CTRL_SWR_SHIFT)) & JPEGDEC_CTRL_SWR_MASK)

#define JPEGDEC_CTRL_GO_MASK                     (0x4U)
#define JPEGDEC_CTRL_GO_SHIFT                    (2U)
/*! GO - Go
 *  0b0..No effect
 *  0b1..Enable
 */
#define JPEGDEC_CTRL_GO(x)                       (((uint32_t)(((uint32_t)(x)) << JPEGDEC_CTRL_GO_SHIFT)) & JPEGDEC_CTRL_GO_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group JPEGDEC_Register_Masks */


/*!
 * @}
 */ /* end of group JPEGDEC_Peripheral_Access_Layer */


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


#endif  /* PERI_JPEGDEC_H_ */

