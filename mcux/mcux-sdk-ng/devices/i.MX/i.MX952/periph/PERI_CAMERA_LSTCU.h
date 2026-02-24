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
**         CMSIS Peripheral Access Layer for CAMERA_LSTCU
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
 * @file PERI_CAMERA_LSTCU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAMERA_LSTCU
 *
 * CMSIS Peripheral Access Layer for CAMERA_LSTCU
 */

#if !defined(PERI_CAMERA_LSTCU_H_)
#define PERI_CAMERA_LSTCU_H_                     /**< Symbol preventing repeated inclusion */

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
   -- CAMERA_LSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_LSTCU_Peripheral_Access_Layer CAMERA_LSTCU Peripheral Access Layer
 * @{
 */

/** CAMERA_LSTCU - Size of Registers Arrays */
#define CAMERA_LSTCU_MBIST_SCH_PTR_COUNT          1u

/** CAMERA_LSTCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t ERR_STAT;                          /**< Error Status, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ERR_FM;                            /**< Error Fault Mapping, offset: 0x10 */
       uint8_t RESERVED_2[76];
  __I  uint32_t MB_RSTAT0;                         /**< MBIST Run Status 0, offset: 0x60 */
       uint8_t RESERVED_3[284];
  __IO uint32_t MBFM0;                             /**< MBIST Fault Mapping 0, offset: 0x180 */
       uint8_t RESERVED_4[220];
  __IO uint32_t STAG;                              /**< Stagger, offset: 0x260 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PH1_DUR;                           /**< Phase 1 Duration, offset: 0x270 */
       uint8_t RESERVED_6[140];
  __IO uint32_t MBPTR[CAMERA_LSTCU_MBIST_SCH_PTR_COUNT]; /**< MBIST Scheduler Pointer, array offset: 0x300, array step: 0x4 */
} CAMERA_LSTCU_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_LSTCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_LSTCU_Register_Masks CAMERA_LSTCU Register Masks
 * @{
 */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define CAMERA_LSTCU_ERR_STAT_INVP_MB_MASK       (0x2U)
#define CAMERA_LSTCU_ERR_STAT_INVP_MB_SHIFT      (1U)
/*! INVP_MB - Invalid Pointer MBIST
 *  0b0..No invalid pointer
 *  0b1..Invalid BIST pointer specified
 */
#define CAMERA_LSTCU_ERR_STAT_INVP_MB(x)         (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_ERR_STAT_INVP_MB_SHIFT)) & CAMERA_LSTCU_ERR_STAT_INVP_MB_MASK)

#define CAMERA_LSTCU_ERR_STAT_UFSF_MASK          (0x10000U)
#define CAMERA_LSTCU_ERR_STAT_UFSF_SHIFT         (16U)
/*! UFSF - Unrecoverable Fault Status
 *  0b0..No unrecoverable fault
 *  0b1..Unrecoverable fault
 */
#define CAMERA_LSTCU_ERR_STAT_UFSF(x)            (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_ERR_STAT_UFSF_SHIFT)) & CAMERA_LSTCU_ERR_STAT_UFSF_MASK)

#define CAMERA_LSTCU_ERR_STAT_RFSF_MASK          (0x20000U)
#define CAMERA_LSTCU_ERR_STAT_RFSF_SHIFT         (17U)
/*! RFSF - Recoverable Fault Status
 *  0b0..No recoverable fault
 *  0b1..Recoverable fault
 */
#define CAMERA_LSTCU_ERR_STAT_RFSF(x)            (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_ERR_STAT_RFSF_SHIFT)) & CAMERA_LSTCU_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define CAMERA_LSTCU_ERR_FM_INVPFMMB_MASK        (0x2U)
#define CAMERA_LSTCU_ERR_FM_INVPFMMB_SHIFT       (1U)
/*! INVPFMMB - Invalid BIST Pointer Fault Mapping During MBIST Scheduling
 *  0b0..Recoverable
 *  0b1..Unrecoverable
 */
#define CAMERA_LSTCU_ERR_FM_INVPFMMB(x)          (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_ERR_FM_INVPFMMB_SHIFT)) & CAMERA_LSTCU_ERR_FM_INVPFMMB_MASK)
/*! @} */

/*! @name MB_RSTAT0 - MBIST Run Status 0 */
/*! @{ */

#define CAMERA_LSTCU_MB_RSTAT0_MBSTAT0_MASK      (0x1U)
#define CAMERA_LSTCU_MB_RSTAT0_MBSTAT0_SHIFT     (0U)
/*! MBSTAT0 - MBIST Run Result Status 0
 *  0b0..Pass
 *  0b1..Fail
 */
#define CAMERA_LSTCU_MB_RSTAT0_MBSTAT0(x)        (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_MB_RSTAT0_MBSTAT0_SHIFT)) & CAMERA_LSTCU_MB_RSTAT0_MBSTAT0_MASK)
/*! @} */

/*! @name MBFM0 - MBIST Fault Mapping 0 */
/*! @{ */

#define CAMERA_LSTCU_MBFM0_MBSTATFM0_MASK        (0x1U)
#define CAMERA_LSTCU_MBFM0_MBSTATFM0_SHIFT       (0U)
/*! MBSTATFM0 - MBIST Fault Mapping n
 *  0b0..Recoverable
 *  0b1..Unrecoverable
 */
#define CAMERA_LSTCU_MBFM0_MBSTATFM0(x)          (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_MBFM0_MBSTATFM0_SHIFT)) & CAMERA_LSTCU_MBFM0_MBSTATFM0_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define CAMERA_LSTCU_STAG_MB_DELAY_MASK          (0xFF00U)
#define CAMERA_LSTCU_STAG_MB_DELAY_SHIFT         (8U)
/*! MB_DELAY - MBIST Delay */
#define CAMERA_LSTCU_STAG_MB_DELAY(x)            (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_STAG_MB_DELAY_SHIFT)) & CAMERA_LSTCU_STAG_MB_DELAY_MASK)
/*! @} */

/*! @name PH1_DUR - Phase 1 Duration */
/*! @{ */

#define CAMERA_LSTCU_PH1_DUR_PH1DUR_MASK         (0x3FFU)
#define CAMERA_LSTCU_PH1_DUR_PH1DUR_SHIFT        (0U)
/*! PH1DUR - Phase 1 Duration */
#define CAMERA_LSTCU_PH1_DUR_PH1DUR(x)           (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_PH1_DUR_PH1DUR_SHIFT)) & CAMERA_LSTCU_PH1_DUR_PH1DUR_MASK)
/*! @} */

/*! @name MBPTR - MBIST Scheduler Pointer */
/*! @{ */

#define CAMERA_LSTCU_MBPTR_MBPTR_MASK            (0xFFU)
#define CAMERA_LSTCU_MBPTR_MBPTR_SHIFT           (0U)
/*! MBPTR - MBIST Pointer */
#define CAMERA_LSTCU_MBPTR_MBPTR(x)              (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_MBPTR_MBPTR_SHIFT)) & CAMERA_LSTCU_MBPTR_MBPTR_MASK)

#define CAMERA_LSTCU_MBPTR_MBCSM_MASK            (0x100U)
#define CAMERA_LSTCU_MBPTR_MBCSM_SHIFT           (8U)
/*! MBCSM - MBIST Mode
 *  0b0..Sequential
 *  0b1..Concurrent
 */
#define CAMERA_LSTCU_MBPTR_MBCSM(x)              (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_MBPTR_MBCSM_SHIFT)) & CAMERA_LSTCU_MBPTR_MBCSM_MASK)

#define CAMERA_LSTCU_MBPTR_MBEOL_MASK            (0x80000000U)
#define CAMERA_LSTCU_MBPTR_MBEOL_SHIFT           (31U)
/*! MBEOL - MBIST End of List
 *  0b0..Not end of list
 *  0b1..End of list
 */
#define CAMERA_LSTCU_MBPTR_MBEOL(x)              (((uint32_t)(((uint32_t)(x)) << CAMERA_LSTCU_MBPTR_MBEOL_SHIFT)) & CAMERA_LSTCU_MBPTR_MBEOL_MASK)
/*! @} */

/* The count of CAMERA_LSTCU_MBPTR */
#define CAMERA_LSTCU_MBPTR_COUNT                 (1U)


/*!
 * @}
 */ /* end of group CAMERA_LSTCU_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_LSTCU_Peripheral_Access_Layer */


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


#endif  /* PERI_CAMERA_LSTCU_H_ */

