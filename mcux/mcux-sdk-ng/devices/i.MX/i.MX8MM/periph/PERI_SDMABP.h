/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDMABP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SDMABP.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SDMABP
 *
 * CMSIS Peripheral Access Layer for SDMABP
 */

#if !defined(PERI_SDMABP_H_)
#define PERI_SDMABP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- SDMABP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMABP_Peripheral_Access_Layer SDMABP Peripheral Access Layer
 * @{
 */

/** SDMABP - Register Layout Typedef */
typedef struct {
  __IO uint32_t DC0PTR;                            /**< Channel 0 Pointer, offset: 0x0 */
  __IO uint32_t INTR;                              /**< Channel Interrupts, offset: 0x4 */
  __IO uint32_t STOP_STAT;                         /**< Channel Stop/Channel Status, offset: 0x8 */
  __I  uint32_t DSTART;                            /**< Channel Start, offset: 0xC */
       uint8_t RESERVED_0[24];
  __I  uint32_t EVTERR;                            /**< DMA Request Error Register, offset: 0x28 */
  __IO uint32_t INTRMASK;                          /**< Channel DSP Interrupt Mask, offset: 0x2C */
       uint8_t RESERVED_1[4];
  __I  uint32_t EVTERRDBG;                         /**< DMA Request Error Register, offset: 0x34 */
} SDMABP_Type;

/* ----------------------------------------------------------------------------
   -- SDMABP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMABP_Register_Masks SDMABP Register Masks
 * @{
 */

/*! @name DC0PTR - Channel 0 Pointer */
/*! @{ */

#define SDMABP_DC0PTR_DC0PTR_MASK                (0xFFFFFFFFU)
#define SDMABP_DC0PTR_DC0PTR_SHIFT               (0U)
#define SDMABP_DC0PTR_DC0PTR(x)                  (((uint32_t)(((uint32_t)(x)) << SDMABP_DC0PTR_DC0PTR_SHIFT)) & SDMABP_DC0PTR_DC0PTR_MASK)
/*! @} */

/*! @name INTR - Channel Interrupts */
/*! @{ */

#define SDMABP_INTR_DI_MASK                      (0xFFFFFFFFU)
#define SDMABP_INTR_DI_SHIFT                     (0U)
#define SDMABP_INTR_DI(x)                        (((uint32_t)(((uint32_t)(x)) << SDMABP_INTR_DI_SHIFT)) & SDMABP_INTR_DI_MASK)
/*! @} */

/*! @name STOP_STAT - Channel Stop/Channel Status */
/*! @{ */

#define SDMABP_STOP_STAT_DE_MASK                 (0xFFFFFFFFU)
#define SDMABP_STOP_STAT_DE_SHIFT                (0U)
#define SDMABP_STOP_STAT_DE(x)                   (((uint32_t)(((uint32_t)(x)) << SDMABP_STOP_STAT_DE_SHIFT)) & SDMABP_STOP_STAT_DE_MASK)
/*! @} */

/*! @name DSTART - Channel Start */
/*! @{ */

#define SDMABP_DSTART_DSTART_DE_MASK             (0xFFFFFFFFU)
#define SDMABP_DSTART_DSTART_DE_SHIFT            (0U)
#define SDMABP_DSTART_DSTART_DE(x)               (((uint32_t)(((uint32_t)(x)) << SDMABP_DSTART_DSTART_DE_SHIFT)) & SDMABP_DSTART_DSTART_DE_MASK)
/*! @} */

/*! @name EVTERR - DMA Request Error Register */
/*! @{ */

#define SDMABP_EVTERR_CHNERR_MASK                (0xFFFFFFFFU)
#define SDMABP_EVTERR_CHNERR_SHIFT               (0U)
#define SDMABP_EVTERR_CHNERR(x)                  (((uint32_t)(((uint32_t)(x)) << SDMABP_EVTERR_CHNERR_SHIFT)) & SDMABP_EVTERR_CHNERR_MASK)
/*! @} */

/*! @name INTRMASK - Channel DSP Interrupt Mask */
/*! @{ */

#define SDMABP_INTRMASK_DIMASK_MASK              (0xFFFFFFFFU)
#define SDMABP_INTRMASK_DIMASK_SHIFT             (0U)
#define SDMABP_INTRMASK_DIMASK(x)                (((uint32_t)(((uint32_t)(x)) << SDMABP_INTRMASK_DIMASK_SHIFT)) & SDMABP_INTRMASK_DIMASK_MASK)
/*! @} */

/*! @name EVTERRDBG - DMA Request Error Register */
/*! @{ */

#define SDMABP_EVTERRDBG_CHNERR_MASK             (0xFFFFFFFFU)
#define SDMABP_EVTERRDBG_CHNERR_SHIFT            (0U)
#define SDMABP_EVTERRDBG_CHNERR(x)               (((uint32_t)(((uint32_t)(x)) << SDMABP_EVTERRDBG_CHNERR_SHIFT)) & SDMABP_EVTERRDBG_CHNERR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDMABP_Register_Masks */


/*!
 * @}
 */ /* end of group SDMABP_Peripheral_Access_Layer */


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


#endif  /* PERI_SDMABP_H_ */

