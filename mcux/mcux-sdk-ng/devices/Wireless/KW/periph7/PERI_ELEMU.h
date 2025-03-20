/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 1.0, 2020-05-12
**     Build:               b240715
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ELEMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ELEMU.h
 * @version 1.0
 * @date 2020-05-12
 * @brief CMSIS Peripheral Access Layer for ELEMU
 *
 * CMSIS Peripheral Access Layer for ELEMU
 */

#if !defined(ELEMU_H_)
#define ELEMU_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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
   -- ELEMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELEMU_Peripheral_Access_Layer ELEMU Peripheral Access Layer
 * @{
 */

/** ELEMU - Size of Registers Arrays */
#define ELEMU_TR_COUNT                            16u
#define ELEMU_RR_COUNT                            2u

/** ELEMU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER;                               /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PAR;                               /**< Parameter Register, offset: 0x4 */
       uint32_t UNUSED0;                           /**< Unused Register 0, offset: 0x8 */
  __I  uint32_t SR;                                /**< Status Register, offset: 0xC */
       uint8_t RESERVED_0[272];
  __IO uint32_t TCR;                               /**< Transmit Control Register, offset: 0x120 */
  __I  uint32_t TSR;                               /**< Transmit Status Register, offset: 0x124 */
       uint8_t RESERVED_1[4];
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x12C */
       uint8_t RESERVED_2[204];
  __IO uint32_t UNUSED1;                           /**< Unused Register 1, offset: 0x1FC */
  __O  uint32_t TR[ELEMU_TR_COUNT];                /**< Transmit Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_3[64];
  __I  uint32_t RR[ELEMU_RR_COUNT];                /**< Receive Register, array offset: 0x280, array step: 0x4 */
       uint8_t RESERVED_4[376];
  __I  uint32_t SEMA4_SR;                          /**< Semaphore Status Register, offset: 0x400 */
       uint8_t RESERVED_5[112];
  __I  uint32_t SEMA4_OWNR;                        /**< Semaphore Ownership Register, offset: 0x474 */
       uint8_t RESERVED_6[1312];
  __I  uint32_t SEMA4_ACQ;                         /**< Semaphore Acquire Register, offset: 0x998 */
       uint8_t RESERVED_7[304];
  __I  uint32_t SEMA4_REL;                         /**< Semaphore Release Register, offset: 0xACC */
       uint8_t RESERVED_8[212];
  __I  uint32_t SEMA4_FREL;                        /**< Semaphore Forced Release Register, offset: 0xBA4 */
} ELEMU_Type;

/* ----------------------------------------------------------------------------
   -- ELEMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELEMU_Register_Masks ELEMU Register Masks
 * @{
 */

/*! @name VER - Version ID Register */
/*! @{ */

#define ELEMU_VER_FEATURE_MASK                   (0xFFFFU)
#define ELEMU_VER_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Set Number
 *  0b0000000000000000..Standard features are implemented.
 */
#define ELEMU_VER_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << ELEMU_VER_FEATURE_SHIFT)) & ELEMU_VER_FEATURE_MASK)

#define ELEMU_VER_MINOR_MASK                     (0xFF0000U)
#define ELEMU_VER_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number (0x00 ) */
#define ELEMU_VER_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << ELEMU_VER_MINOR_SHIFT)) & ELEMU_VER_MINOR_MASK)

#define ELEMU_VER_MAJOR_MASK                     (0xFF000000U)
#define ELEMU_VER_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number (0x01 ) */
#define ELEMU_VER_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << ELEMU_VER_MAJOR_SHIFT)) & ELEMU_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR - Parameter Register */
/*! @{ */

#define ELEMU_PAR_TR_NUM_MASK                    (0xFFU)
#define ELEMU_PAR_TR_NUM_SHIFT                   (0U)
/*! TR_NUM - Number of Transmit (TRn) registers (8'd16) */
#define ELEMU_PAR_TR_NUM(x)                      (((uint32_t)(((uint32_t)(x)) << ELEMU_PAR_TR_NUM_SHIFT)) & ELEMU_PAR_TR_NUM_MASK)

#define ELEMU_PAR_RR_NUM_MASK                    (0xFF00U)
#define ELEMU_PAR_RR_NUM_SHIFT                   (8U)
/*! RR_NUM - Number of Receive (RRn) registers (8'd2) */
#define ELEMU_PAR_RR_NUM(x)                      (((uint32_t)(((uint32_t)(x)) << ELEMU_PAR_RR_NUM_SHIFT)) & ELEMU_PAR_RR_NUM_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define ELEMU_SR_TEP_MASK                        (0x20U)
#define ELEMU_SR_TEP_SHIFT                       (5U)
/*! TEP - Transmit Empty Pending */
#define ELEMU_SR_TEP(x)                          (((uint32_t)(((uint32_t)(x)) << ELEMU_SR_TEP_SHIFT)) & ELEMU_SR_TEP_MASK)

#define ELEMU_SR_RFP_MASK                        (0x40U)
#define ELEMU_SR_RFP_SHIFT                       (6U)
/*! RFP - Receive Full Pending Flag
 *  0b0..No data is ready to be read. All RSR[RFn] bits are clear.
 *  0b1..Data is ready to be read. One or more RSR[RFn] bits are set.
 */
#define ELEMU_SR_RFP(x)                          (((uint32_t)(((uint32_t)(x)) << ELEMU_SR_RFP_SHIFT)) & ELEMU_SR_RFP_MASK)
/*! @} */

/*! @name TCR - Transmit Control Register */
/*! @{ */

#define ELEMU_TCR_TEIEn_MASK                     (0xFFFFU)
#define ELEMU_TCR_TEIEn_SHIFT                    (0U)
/*! TEIEn - Transmit Register n Empty Interrupt Enable */
#define ELEMU_TCR_TEIEn(x)                       (((uint32_t)(((uint32_t)(x)) << ELEMU_TCR_TEIEn_SHIFT)) & ELEMU_TCR_TEIEn_MASK)
/*! @} */

/*! @name TSR - Transmit Status Register */
/*! @{ */

#define ELEMU_TSR_TEn_MASK                       (0xFFFFU)
#define ELEMU_TSR_TEn_SHIFT                      (0U)
/*! TEn - Transmit Register n Empty */
#define ELEMU_TSR_TEn(x)                         (((uint32_t)(((uint32_t)(x)) << ELEMU_TSR_TEn_SHIFT)) & ELEMU_TSR_TEn_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define ELEMU_RSR_RFn_MASK                       (0x3U)
#define ELEMU_RSR_RFn_SHIFT                      (0U)
/*! RFn - Receive Register n Full */
#define ELEMU_RSR_RFn(x)                         (((uint32_t)(((uint32_t)(x)) << ELEMU_RSR_RFn_SHIFT)) & ELEMU_RSR_RFn_MASK)
/*! @} */

/*! @name UNUSED1 - Unused Register 1 */
/*! @{ */

#define ELEMU_UNUSED1_DATA16_MASK                (0xFFFFU)
#define ELEMU_UNUSED1_DATA16_SHIFT               (0U)
/*! DATA16 - Unused 16-bit Register */
#define ELEMU_UNUSED1_DATA16(x)                  (((uint32_t)(((uint32_t)(x)) << ELEMU_UNUSED1_DATA16_SHIFT)) & ELEMU_UNUSED1_DATA16_MASK)
/*! @} */

/*! @name TR - Transmit Register */
/*! @{ */

#define ELEMU_TR_TR_DATA_MASK                    (0xFFFFFFFFU)
#define ELEMU_TR_TR_DATA_SHIFT                   (0U)
/*! TR_DATA - Transmit Data */
#define ELEMU_TR_TR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ELEMU_TR_TR_DATA_SHIFT)) & ELEMU_TR_TR_DATA_MASK)
/*! @} */

/*! @name RR - Receive Register */
/*! @{ */

#define ELEMU_RR_RR_DATA_MASK                    (0xFFFFFFFFU)
#define ELEMU_RR_RR_DATA_SHIFT                   (0U)
/*! RR_DATA - Receive Data */
#define ELEMU_RR_RR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ELEMU_RR_RR_DATA_SHIFT)) & ELEMU_RR_RR_DATA_MASK)
/*! @} */

/*! @name SEMA4_SR - Semaphore Status Register */
/*! @{ */

#define ELEMU_SEMA4_SR_OWNR16_MASK               (0xFFFFU)
#define ELEMU_SEMA4_SR_OWNR16_SHIFT              (0U)
/*! OWNR16 - Semaphore Owner */
#define ELEMU_SEMA4_SR_OWNR16(x)                 (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_OWNR16_SHIFT)) & ELEMU_SEMA4_SR_OWNR16_MASK)

#define ELEMU_SEMA4_SR_SSS_CIP2_MASK             (0x10000U)
#define ELEMU_SEMA4_SR_SSS_CIP2_SHIFT            (16U)
/*! SSS_CIP2 - Security SubSystem (ELE) command group 2 in progress
 *  0b0..Service request group 2 not being processed by ELE
 *  0b1..Service request group 2 being processed by ELE
 */
#define ELEMU_SEMA4_SR_SSS_CIP2(x)               (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_SSS_CIP2_SHIFT)) & ELEMU_SEMA4_SR_SSS_CIP2_MASK)

#define ELEMU_SEMA4_SR_SSS_CIP1_MASK             (0x20000U)
#define ELEMU_SEMA4_SR_SSS_CIP1_SHIFT            (17U)
/*! SSS_CIP1 - Security SubSystem (ELE) command group 1 in progress
 *  0b0..Service request group 1 not being processed by ELE
 *  0b1..Service request group 1 being processed by ELE
 */
#define ELEMU_SEMA4_SR_SSS_CIP1(x)               (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_SSS_CIP1_SHIFT)) & ELEMU_SEMA4_SR_SSS_CIP1_MASK)

#define ELEMU_SEMA4_SR_SSS_LCK_MASK              (0x1000000U)
#define ELEMU_SEMA4_SR_SSS_LCK_SHIFT             (24U)
/*! SSS_LCK - Security SubSystem (ELE) lockup
 *  0b0..Edgelock enclave is not locked up
 *  0b1..Edgelock enclave is locked up in an unrecoverable state
 */
#define ELEMU_SEMA4_SR_SSS_LCK(x)                (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_SSS_LCK_SHIFT)) & ELEMU_SEMA4_SR_SSS_LCK_MASK)

#define ELEMU_SEMA4_SR_MISC_BSY_MASK             (0x7E000000U)
#define ELEMU_SEMA4_SR_MISC_BSY_SHIFT            (25U)
/*! MISC_BSY - Miscellaneous ELE Busy Indicators */
#define ELEMU_SEMA4_SR_MISC_BSY(x)               (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_MISC_BSY_SHIFT)) & ELEMU_SEMA4_SR_MISC_BSY_MASK)

#define ELEMU_SEMA4_SR_SSS_BSY_MASK              (0x80000000U)
#define ELEMU_SEMA4_SR_SSS_BSY_SHIFT             (31U)
/*! SSS_BSY - Security SubSystem (ELE) Busy
 *  0b0..Edgelock enclave is not busy
 *  0b1..Edgelock enclave CPU is busy
 */
#define ELEMU_SEMA4_SR_SSS_BSY(x)                (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_SR_SSS_BSY_SHIFT)) & ELEMU_SEMA4_SR_SSS_BSY_MASK)
/*! @} */

/*! @name SEMA4_OWNR - Semaphore Ownership Register */
/*! @{ */

#define ELEMU_SEMA4_OWNR_OWNR32_MASK             (0xFFFFFFFFU)
#define ELEMU_SEMA4_OWNR_OWNR32_SHIFT            (0U)
/*! OWNR32 - Semaphore Owner */
#define ELEMU_SEMA4_OWNR_OWNR32(x)               (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_OWNR_OWNR32_SHIFT)) & ELEMU_SEMA4_OWNR_OWNR32_MASK)
/*! @} */

/*! @name SEMA4_ACQ - Semaphore Acquire Register */
/*! @{ */

#define ELEMU_SEMA4_ACQ_OWNR32_MASK              (0xFFFFFFFFU)
#define ELEMU_SEMA4_ACQ_OWNR32_SHIFT             (0U)
/*! OWNR32 - Semaphore Owner */
#define ELEMU_SEMA4_ACQ_OWNR32(x)                (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_ACQ_OWNR32_SHIFT)) & ELEMU_SEMA4_ACQ_OWNR32_MASK)
/*! @} */

/*! @name SEMA4_REL - Semaphore Release Register */
/*! @{ */

#define ELEMU_SEMA4_REL_OWNR32_MASK              (0xFFFFFFFFU)
#define ELEMU_SEMA4_REL_OWNR32_SHIFT             (0U)
/*! OWNR32 - Semaphore Owner */
#define ELEMU_SEMA4_REL_OWNR32(x)                (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_REL_OWNR32_SHIFT)) & ELEMU_SEMA4_REL_OWNR32_MASK)
/*! @} */

/*! @name SEMA4_FREL - Semaphore Forced Release Register */
/*! @{ */

#define ELEMU_SEMA4_FREL_OWNR32_MASK             (0xFFFFFFFFU)
#define ELEMU_SEMA4_FREL_OWNR32_SHIFT            (0U)
/*! OWNR32 - Semaphore Owner */
#define ELEMU_SEMA4_FREL_OWNR32(x)               (((uint32_t)(((uint32_t)(x)) << ELEMU_SEMA4_FREL_OWNR32_SHIFT)) & ELEMU_SEMA4_FREL_OWNR32_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ELEMU_Register_Masks */


/*!
 * @}
 */ /* end of group ELEMU_Peripheral_Access_Layer */


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


#endif  /* ELEMU_H_ */

