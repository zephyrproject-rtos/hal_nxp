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
**         CMSIS Peripheral Access Layer for IRQSTEER
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
 * @file PERI_IRQSTEER.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IRQSTEER
 *
 * CMSIS Peripheral Access Layer for IRQSTEER
 */

#if !defined(PERI_IRQSTEER_H_)
#define PERI_IRQSTEER_H_                         /**< Symbol preventing repeated inclusion */

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
   -- IRQSTEER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Peripheral_Access_Layer IRQSTEER Peripheral Access Layer
 * @{
 */

/** IRQSTEER - Size of Registers Arrays */
#define IRQSTEER_CHN_MASK_COUNT                   24u
#define IRQSTEER_CHN_SET_COUNT                    24u
#define IRQSTEER_CHN_STATUS_COUNT                 24u

/** IRQSTEER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHN_MASK[IRQSTEER_CHN_MASK_COUNT]; /**< Channel n Interrupt Mask, array offset: 0x4, array step: 0x4 */
  __IO uint32_t CHN_SET[IRQSTEER_CHN_SET_COUNT];   /**< Channel n Interrupt Set, array offset: 0x64, array step: 0x4 */
  __I  uint32_t CHN_STATUS[IRQSTEER_CHN_STATUS_COUNT]; /**< Channel n Interrupt Status, array offset: 0xC4, array step: 0x4 */
  __IO uint32_t CHN_MINTDIS;                       /**< Channel n Group Interrupt Disable, offset: 0x124 */
  __I  uint32_t CHN_MSTRSTAT;                      /**< Channel n Group Status, offset: 0x128 */
} IRQSTEER_Type;

/* ----------------------------------------------------------------------------
   -- IRQSTEER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQSTEER_Register_Masks IRQSTEER Register Masks
 * @{
 */

/*! @name CHN_MASK - Channel n Interrupt Mask */
/*! @{ */

#define IRQSTEER_CHN_MASK_MASKFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHN_MASK_MASKFLD_SHIFT          (0U)
/*! MASKFLD - Masks */
#define IRQSTEER_CHN_MASK_MASKFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MASK_MASKFLD_SHIFT)) & IRQSTEER_CHN_MASK_MASKFLD_MASK)
/*! @} */

/*! @name CHN_SET - Channel n Interrupt Set */
/*! @{ */

#define IRQSTEER_CHN_SET_FORCEFLD_MASK           (0xFFFFFFFFU)
#define IRQSTEER_CHN_SET_FORCEFLD_SHIFT          (0U)
/*! FORCEFLD - Force Interrupt */
#define IRQSTEER_CHN_SET_FORCEFLD(x)             (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_SET_FORCEFLD_SHIFT)) & IRQSTEER_CHN_SET_FORCEFLD_MASK)
/*! @} */

/*! @name CHN_STATUS - Channel n Interrupt Status */
/*! @{ */

#define IRQSTEER_CHN_STATUS_STATUS_MASK          (0xFFFFFFFFU)
#define IRQSTEER_CHN_STATUS_STATUS_SHIFT         (0U)
/*! STATUS - Status of an interrupt */
#define IRQSTEER_CHN_STATUS_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_STATUS_STATUS_SHIFT)) & IRQSTEER_CHN_STATUS_STATUS_MASK)
/*! @} */

/*! @name CHN_MINTDIS - Channel n Group Interrupt Disable */
/*! @{ */

#define IRQSTEER_CHN_MINTDIS_DISABLE_MASK        (0xFFFU)
#define IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT       (0U)
/*! DISABLE - Interrupt Disable
 *  0b000000000000..Enable interrupts
 *  0b000000000001..Disable interrupts
 */
#define IRQSTEER_CHN_MINTDIS_DISABLE(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT)) & IRQSTEER_CHN_MINTDIS_DISABLE_MASK)
/*! @} */

/*! @name CHN_MSTRSTAT - Channel n Group Status */
/*! @{ */

#define IRQSTEER_CHN_MSTRSTAT_STATUS_MASK        (0x1U)
#define IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT       (0U)
/*! STATUS - Group Interrupt Status
 *  0b0..No interrupts are asserted.
 *  0b1..At least one interrupt is asserted.
 */
#define IRQSTEER_CHN_MSTRSTAT_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT)) & IRQSTEER_CHN_MSTRSTAT_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IRQSTEER_Register_Masks */


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


#endif  /* PERI_IRQSTEER_H_ */

