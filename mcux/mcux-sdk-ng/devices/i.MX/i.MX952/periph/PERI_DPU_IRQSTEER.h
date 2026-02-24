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
**         CMSIS Peripheral Access Layer for DPU_IRQSTEER
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
 * @file PERI_DPU_IRQSTEER.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DPU_IRQSTEER
 *
 * CMSIS Peripheral Access Layer for DPU_IRQSTEER
 */

#if !defined(PERI_DPU_IRQSTEER_H_)
#define PERI_DPU_IRQSTEER_H_                     /**< Symbol preventing repeated inclusion */

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
/*!
 * @brief DPU IRQn.
 */
typedef enum DPU_IRQSTEER_IRQn
{
    /* DISPLAY_INT_OUT0 */
    CmdSeqError_DPU_IRQn = 0,
    SoftwareInt0_DPU_IRQn = 1,
    SoftwareInt1_DPU_IRQn = 2,
    SoftwareInt2_DPU_IRQn = 3,
    SoftwareInt3_DPU_IRQn = 4,

    /* DISPLAY_INT_OUT1 */
    ExtDst0ShadowLoad_DPU_IRQn = 64,
    ExtDst0FrameComplete_DPU_IRQn = 65,
    ExtDst0SeqComplete_DPU_IRQn = 66,
    ExtDst4ShadowLoad_DPU_IRQn = 67,
    ExtDst4FrameComplete_DPU_IRQn = 68,
    ExtDst4SeqComplete_DPU_IRQn = 69,
    DomainBlend0_ShdLoad_DPU_IRQn = 70,
    DomainBlend0_FrameComplete_DPU_IRQn = 71,
    DomainBlend0_SeqComplete_DPU_IRQn = 72,
    Display0ShadowLoad_DPU_IRQn = 73,
    Display0FrameComplete_DPU_IRQn = 74,
    Display0SeqComplete_DPU_IRQn = 75,
    FrameGen0Int0_DPU_IRQn = 76,
    FrameGen0Int1_DPU_IRQn = 77,
    FrameGen0Int2_DPU_IRQn = 78,
    FrameGen0Int3_DPU_IRQn = 79,
    Sig0ShadowLoad_DPU_IRQn = 80,
    Sig0Valid_DPU_IRQn = 81,
    Sig0Error_DPU_IRQn = 82,
    FrameGen0PrimSyncOn_DPU_IRQn = 93,
    FrameGen0PrimSyncOff_DPU_IRQn = 94,

    /* DISPLAY_INT_OUT3 */
    ExtDst1ShadowLoad_DPU_IRQn = 192,
    ExtDst1FrameComplete_DPU_IRQn = 193,
    ExtDst1SeqComplete_DPU_IRQn = 194,
    ExtDst5ShadowLoad_DPU_IRQn = 195,
    ExtDst5FrameComplete_DPU_IRQn = 196,
    ExtDst5SeqComplete_DPU_IRQn = 197,
    Display1ShadowLoad_DPU_IRQn = 201,
    Display1FrameComplete_DPU_IRQn = 202,
    Display1SeqComplete_DPU_IRQn = 203,
    FrameGen1Int0_DPU_IRQn = 204,
    FrameGen1Int1_DPU_IRQn = 205,
    FrameGen1Int2_DPU_IRQn = 206,
    FrameGen1Int3_DPU_IRQn = 207,
    Sig1ShadowLoad_DPU_IRQn = 208,
    Sig1Valid_DPU_IRQn = 209,
    Sig1Error_DPU_IRQn = 210,
    FrameGen1PrimSyncOn_DPU_IRQn = 213,
    FrameGen1PrimSyncOff_DPU_IRQn = 214,

    /* DISPLAY_INT_OUT7 */
    Store9ShadowLoad_DPU_IRQn = 448,
    Store9FrameComplete_DPU_IRQn = 449,
    Store9SeqComplete_DPU_IRQn = 450,
} DPU_IRQSTEER_IRQn_Type;



/* ----------------------------------------------------------------------------
   -- DPU_IRQSTEER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPU_IRQSTEER_Peripheral_Access_Layer DPU_IRQSTEER Peripheral Access Layer
 * @{
 */

/** DPU_IRQSTEER - Size of Registers Arrays */
#define DPU_IRQSTEER_CHN_MASK_COUNT               16u
#define DPU_IRQSTEER_CHN_SET_COUNT                16u
#define DPU_IRQSTEER_CHN_STATUS_COUNT             16u

/** DPU_IRQSTEER - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHN_MASK[DPU_IRQSTEER_CHN_MASK_COUNT]; /**< Channel n Interrupt Mask, array offset: 0x4, array step: 0x4 */
  __IO uint32_t CHN_SET[DPU_IRQSTEER_CHN_SET_COUNT]; /**< Channel n Interrupt Set, array offset: 0x44, array step: 0x4 */
  __I  uint32_t CHN_STATUS[DPU_IRQSTEER_CHN_STATUS_COUNT]; /**< Channel n Interrupt Status, array offset: 0x84, array step: 0x4 */
  __IO uint32_t CHN_MINTDIS;                       /**< Channel n Group Interrupt Disable, offset: 0xC4 */
  __I  uint32_t CHN_MSTRSTAT;                      /**< Channel n Group Status, offset: 0xC8 */
} DPU_IRQSTEER_Type;

/* ----------------------------------------------------------------------------
   -- DPU_IRQSTEER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPU_IRQSTEER_Register_Masks DPU_IRQSTEER Register Masks
 * @{
 */

/*! @name CHN_MASK - Channel n Interrupt Mask */
/*! @{ */

#define DPU_IRQSTEER_CHN_MASK_MASKFLD_MASK       (0xFFFFFFFFU)
#define DPU_IRQSTEER_CHN_MASK_MASKFLD_SHIFT      (0U)
/*! MASKFLD - Masks */
#define DPU_IRQSTEER_CHN_MASK_MASKFLD(x)         (((uint32_t)(((uint32_t)(x)) << DPU_IRQSTEER_CHN_MASK_MASKFLD_SHIFT)) & DPU_IRQSTEER_CHN_MASK_MASKFLD_MASK)
/*! @} */

/*! @name CHN_SET - Channel n Interrupt Set */
/*! @{ */

#define DPU_IRQSTEER_CHN_SET_FORCEFLD_MASK       (0xFFFFFFFFU)
#define DPU_IRQSTEER_CHN_SET_FORCEFLD_SHIFT      (0U)
/*! FORCEFLD - Force Interrupt */
#define DPU_IRQSTEER_CHN_SET_FORCEFLD(x)         (((uint32_t)(((uint32_t)(x)) << DPU_IRQSTEER_CHN_SET_FORCEFLD_SHIFT)) & DPU_IRQSTEER_CHN_SET_FORCEFLD_MASK)
/*! @} */

/*! @name CHN_STATUS - Channel n Interrupt Status */
/*! @{ */

#define DPU_IRQSTEER_CHN_STATUS_STATUS_MASK      (0xFFFFFFFFU)
#define DPU_IRQSTEER_CHN_STATUS_STATUS_SHIFT     (0U)
/*! STATUS - Status of an interrupt */
#define DPU_IRQSTEER_CHN_STATUS_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << DPU_IRQSTEER_CHN_STATUS_STATUS_SHIFT)) & DPU_IRQSTEER_CHN_STATUS_STATUS_MASK)
/*! @} */

/*! @name CHN_MINTDIS - Channel n Group Interrupt Disable */
/*! @{ */

#define DPU_IRQSTEER_CHN_MINTDIS_DISABLE_MASK    (0xFFU)
#define DPU_IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT   (0U)
/*! DISABLE - Interrupt Disable
 *  0b00000000..Enable interrupts
 *  0b00000001..Disable interrupts
 */
#define DPU_IRQSTEER_CHN_MINTDIS_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << DPU_IRQSTEER_CHN_MINTDIS_DISABLE_SHIFT)) & DPU_IRQSTEER_CHN_MINTDIS_DISABLE_MASK)
/*! @} */

/*! @name CHN_MSTRSTAT - Channel n Group Status */
/*! @{ */

#define DPU_IRQSTEER_CHN_MSTRSTAT_STATUS_MASK    (0x1U)
#define DPU_IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT   (0U)
/*! STATUS - Group Interrupt Status
 *  0b0..No interrupts are asserted.
 *  0b1..At least one interrupt is asserted.
 */
#define DPU_IRQSTEER_CHN_MSTRSTAT_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << DPU_IRQSTEER_CHN_MSTRSTAT_STATUS_SHIFT)) & DPU_IRQSTEER_CHN_MSTRSTAT_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DPU_IRQSTEER_Register_Masks */

/* Backward compatibility */
#define DPU_IRQSTEER_IRQS                            { DISP_IRQSTEER0_IRQn, DISP_IRQSTEER1_IRQn, DISP_IRQSTEER2_IRQn, DISP_IRQSTEER3_IRQn, DISP_IRQSTEER4_IRQn, DISP_IRQSTEER7_IRQn }


/*!
 * @}
 */ /* end of group DPU_IRQSTEER_Peripheral_Access_Layer */


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


#endif  /* PERI_DPU_IRQSTEER_H_ */

