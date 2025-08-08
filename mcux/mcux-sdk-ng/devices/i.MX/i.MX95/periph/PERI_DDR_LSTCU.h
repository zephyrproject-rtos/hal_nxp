/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DDR_LSTCU
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
**
** ###################################################################
*/

/*!
 * @file DDR_LSTCU.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DDR_LSTCU
 *
 * CMSIS Peripheral Access Layer for DDR_LSTCU
 */

#if !defined(DDR_LSTCU_H_)
#define DDR_LSTCU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- DDR_LSTCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_LSTCU_Peripheral_Access_Layer DDR_LSTCU Peripheral Access Layer
 * @{
 */

/** DDR_LSTCU - Size of Registers Arrays */
#define DDR_LSTCU_MBIST_SCH_PTR_COUNT             1u

/** DDR_LSTCU - Register Layout Typedef */
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
  __IO uint32_t MBPTR[DDR_LSTCU_MBIST_SCH_PTR_COUNT]; /**< MBIST Scheduler Pointer, array offset: 0x300, array step: 0x4 */
} DDR_LSTCU_Type;

/* ----------------------------------------------------------------------------
   -- DDR_LSTCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DDR_LSTCU_Register_Masks DDR_LSTCU Register Masks
 * @{
 */

/*! @name ERR_STAT - Error Status */
/*! @{ */

#define DDR_LSTCU_ERR_STAT_INVP_MB_MASK          (0x2U)
#define DDR_LSTCU_ERR_STAT_INVP_MB_SHIFT         (1U)
/*! INVP_MB - Invalid Pointer MBIST
 *  0b0..No invalid pointer
 *  0b1..Invalid BIST pointer specified
 */
#define DDR_LSTCU_ERR_STAT_INVP_MB(x)            (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_ERR_STAT_INVP_MB_SHIFT)) & DDR_LSTCU_ERR_STAT_INVP_MB_MASK)

#define DDR_LSTCU_ERR_STAT_UFSF_MASK             (0x10000U)
#define DDR_LSTCU_ERR_STAT_UFSF_SHIFT            (16U)
/*! UFSF - Unrecoverable Fault Status
 *  0b0..No unrecoverable fault
 *  0b1..Unrecoverable fault
 */
#define DDR_LSTCU_ERR_STAT_UFSF(x)               (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_ERR_STAT_UFSF_SHIFT)) & DDR_LSTCU_ERR_STAT_UFSF_MASK)

#define DDR_LSTCU_ERR_STAT_RFSF_MASK             (0x20000U)
#define DDR_LSTCU_ERR_STAT_RFSF_SHIFT            (17U)
/*! RFSF - Recoverable Fault Status
 *  0b0..No recoverable fault
 *  0b1..Recoverable fault
 */
#define DDR_LSTCU_ERR_STAT_RFSF(x)               (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_ERR_STAT_RFSF_SHIFT)) & DDR_LSTCU_ERR_STAT_RFSF_MASK)
/*! @} */

/*! @name ERR_FM - Error Fault Mapping */
/*! @{ */

#define DDR_LSTCU_ERR_FM_INVPFMMB_MASK           (0x2U)
#define DDR_LSTCU_ERR_FM_INVPFMMB_SHIFT          (1U)
/*! INVPFMMB - Invalid BIST Pointer Fault Mapping During MBIST Scheduling
 *  0b0..Recoverable
 *  0b1..Unrecoverable
 */
#define DDR_LSTCU_ERR_FM_INVPFMMB(x)             (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_ERR_FM_INVPFMMB_SHIFT)) & DDR_LSTCU_ERR_FM_INVPFMMB_MASK)
/*! @} */

/*! @name MB_RSTAT0 - MBIST Run Status 0 */
/*! @{ */

#define DDR_LSTCU_MB_RSTAT0_MBSTAT0_MASK         (0x1U)
#define DDR_LSTCU_MB_RSTAT0_MBSTAT0_SHIFT        (0U)
/*! MBSTAT0 - MBIST Run Result Status 0
 *  0b0..Pass
 *  0b1..Fail
 */
#define DDR_LSTCU_MB_RSTAT0_MBSTAT0(x)           (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_MB_RSTAT0_MBSTAT0_SHIFT)) & DDR_LSTCU_MB_RSTAT0_MBSTAT0_MASK)
/*! @} */

/*! @name MBFM0 - MBIST Fault Mapping 0 */
/*! @{ */

#define DDR_LSTCU_MBFM0_MBSTATFM0_MASK           (0x1U)
#define DDR_LSTCU_MBFM0_MBSTATFM0_SHIFT          (0U)
/*! MBSTATFM0 - MBIST Fault Mapping n
 *  0b0..Recoverable
 *  0b1..Unrecoverable
 */
#define DDR_LSTCU_MBFM0_MBSTATFM0(x)             (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_MBFM0_MBSTATFM0_SHIFT)) & DDR_LSTCU_MBFM0_MBSTATFM0_MASK)
/*! @} */

/*! @name STAG - Stagger */
/*! @{ */

#define DDR_LSTCU_STAG_MB_DELAY_MASK             (0xFF00U)
#define DDR_LSTCU_STAG_MB_DELAY_SHIFT            (8U)
/*! MB_DELAY - MBIST Delay */
#define DDR_LSTCU_STAG_MB_DELAY(x)               (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_STAG_MB_DELAY_SHIFT)) & DDR_LSTCU_STAG_MB_DELAY_MASK)
/*! @} */

/*! @name PH1_DUR - Phase 1 Duration */
/*! @{ */

#define DDR_LSTCU_PH1_DUR_PH1DUR_MASK            (0x3FFU)
#define DDR_LSTCU_PH1_DUR_PH1DUR_SHIFT           (0U)
/*! PH1DUR - Phase 1 Duration */
#define DDR_LSTCU_PH1_DUR_PH1DUR(x)              (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_PH1_DUR_PH1DUR_SHIFT)) & DDR_LSTCU_PH1_DUR_PH1DUR_MASK)
/*! @} */

/*! @name MBPTR - MBIST Scheduler Pointer */
/*! @{ */

#define DDR_LSTCU_MBPTR_MBPTR_MASK               (0xFFU)
#define DDR_LSTCU_MBPTR_MBPTR_SHIFT              (0U)
/*! MBPTR - MBIST Pointer */
#define DDR_LSTCU_MBPTR_MBPTR(x)                 (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_MBPTR_MBPTR_SHIFT)) & DDR_LSTCU_MBPTR_MBPTR_MASK)

#define DDR_LSTCU_MBPTR_MBCSM_MASK               (0x100U)
#define DDR_LSTCU_MBPTR_MBCSM_SHIFT              (8U)
/*! MBCSM - MBIST Mode
 *  0b0..Sequential
 *  0b1..Concurrent
 */
#define DDR_LSTCU_MBPTR_MBCSM(x)                 (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_MBPTR_MBCSM_SHIFT)) & DDR_LSTCU_MBPTR_MBCSM_MASK)

#define DDR_LSTCU_MBPTR_MBEOL_MASK               (0x80000000U)
#define DDR_LSTCU_MBPTR_MBEOL_SHIFT              (31U)
/*! MBEOL - MBIST End of List
 *  0b0..Not end of list
 *  0b1..End of list
 */
#define DDR_LSTCU_MBPTR_MBEOL(x)                 (((uint32_t)(((uint32_t)(x)) << DDR_LSTCU_MBPTR_MBEOL_SHIFT)) & DDR_LSTCU_MBPTR_MBEOL_MASK)
/*! @} */

/* The count of DDR_LSTCU_MBPTR */
#define DDR_LSTCU_MBPTR_COUNT                    (1U)


/*!
 * @}
 */ /* end of group DDR_LSTCU_Register_Masks */


/*!
 * @}
 */ /* end of group DDR_LSTCU_Peripheral_Access_Layer */


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


#endif  /* DDR_LSTCU_H_ */

