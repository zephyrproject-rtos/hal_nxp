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
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_SYSPM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
 * @file AON_SYSPM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_SYSPM
 *
 * CMSIS Peripheral Access Layer for AON_SYSPM
 */

#if !defined(AON_SYSPM_H_)
#define AON_SYSPM_H_                             /**< Symbol preventing repeated inclusion */

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
   -- AON_SYSPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_SYSPM_Peripheral_Access_Layer AON_SYSPM Peripheral Access Layer
 * @{
 */

/** AON_SYSPM - Size of Registers Arrays */
#define AON_SYSPM_PMCR_PMECTR_COUNT               3u
#define AON_SYSPM_PMCR_COUNT                      1u

/** AON_SYSPM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x30 */
    __IO uint32_t PMCR;                              /**< Performance Monitor Control, array offset: 0x0, array step: 0x30 */
         uint8_t RESERVED_0[12];
    __I  uint8_t PMICTR_HI;                          /**< Performance Monitor Instruction Counter, array offset: 0x10, array step: 0x30 */
         uint8_t RESERVED_1[3];
    __I  uint32_t PMICTR_LO;                         /**< Performance Monitor Instruction Counter, array offset: 0x14, array step: 0x30 */
    struct {                                         /* offset: 0x18, array step: index*0x30, index2*0x8 */
      __I  uint8_t HI;                                 /**< Performance Monitor Event Counter, array offset: 0x18, array step: index*0x30, index2*0x8 */
           uint8_t RESERVED_0[3];
      __I  uint32_t LO;                                /**< Performance Monitor Event Counter, array offset: 0x1C, array step: index*0x30, index2*0x8 */
    } PMECTR[AON_SYSPM_PMCR_PMECTR_COUNT];
  } PMCR[AON_SYSPM_PMCR_COUNT];
} AON_SYSPM_Type;

/* ----------------------------------------------------------------------------
   -- AON_SYSPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_SYSPM_Register_Masks AON_SYSPM Register Masks
 * @{
 */

/*! @name PMCR - Performance Monitor Control */
/*! @{ */

#define AON_SYSPM_PMCR_MENB_MASK                 (0x1U)
#define AON_SYSPM_PMCR_MENB_SHIFT                (0U)
/*! MENB - Module Is Enabled
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define AON_SYSPM_PMCR_MENB(x)                   (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_MENB_SHIFT)) & AON_SYSPM_PMCR_MENB_MASK)

#define AON_SYSPM_PMCR_SSC_MASK                  (0xEU)
#define AON_SYSPM_PMCR_SSC_SHIFT                 (1U)
/*! SSC - Start and Stop Control
 *  0b000..Idle or no-op
 *  0b001..Local stop
 *  0b010, 0b011..Local start
 *  0b100..
 *  0b101..
 *  0b110, 0b111..
 */
#define AON_SYSPM_PMCR_SSC(x)                    (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_SSC_SHIFT)) & AON_SYSPM_PMCR_SSC_MASK)

#define AON_SYSPM_PMCR_CMODE_MASK                (0x30U)
#define AON_SYSPM_PMCR_CMODE_SHIFT               (4U)
/*! CMODE - Count Mode
 *  0b00..Counted in both User and Privileged modes
 *  0b01..
 *  0b10..Counted only in User mode
 *  0b11..Counted only in Privileged mode
 */
#define AON_SYSPM_PMCR_CMODE(x)                  (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_CMODE_SHIFT)) & AON_SYSPM_PMCR_CMODE_MASK)

#define AON_SYSPM_PMCR_DCIFSH_MASK               (0x40U)
#define AON_SYSPM_PMCR_DCIFSH_SHIFT              (6U)
/*! DCIFSH - Disable Counters if Stopped or Halted
 *  0b0..Continue
 *  0b1..Stop
 */
#define AON_SYSPM_PMCR_DCIFSH(x)                 (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_DCIFSH_SHIFT)) & AON_SYSPM_PMCR_DCIFSH_MASK)

#define AON_SYSPM_PMCR_RICTR_MASK                (0x80U)
#define AON_SYSPM_PMCR_RICTR_SHIFT               (7U)
/*! RICTR - Reset Instruction Counter
 *  0b0..Do not reset
 *  0b1..Clear
 */
#define AON_SYSPM_PMCR_RICTR(x)                  (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_RICTR_SHIFT)) & AON_SYSPM_PMCR_RICTR_MASK)

#define AON_SYSPM_PMCR_RECTR1_MASK               (0x100U)
#define AON_SYSPM_PMCR_RECTR1_SHIFT              (8U)
/*! RECTR1 - Reset Event Counter 1
 *  0b0..Run normally
 *  0b1..Reset
 */
#define AON_SYSPM_PMCR_RECTR1(x)                 (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_RECTR1_SHIFT)) & AON_SYSPM_PMCR_RECTR1_MASK)

#define AON_SYSPM_PMCR_RECTR2_MASK               (0x200U)
#define AON_SYSPM_PMCR_RECTR2_SHIFT              (9U)
/*! RECTR2 - Reset Event Counter 2
 *  0b0..Run normally
 *  0b1..Reset
 */
#define AON_SYSPM_PMCR_RECTR2(x)                 (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_RECTR2_SHIFT)) & AON_SYSPM_PMCR_RECTR2_MASK)

#define AON_SYSPM_PMCR_RECTR3_MASK               (0x400U)
#define AON_SYSPM_PMCR_RECTR3_SHIFT              (10U)
/*! RECTR3 - Reset Event Counter 3
 *  0b0..Run normally
 *  0b1..Reset
 */
#define AON_SYSPM_PMCR_RECTR3(x)                 (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_RECTR3_SHIFT)) & AON_SYSPM_PMCR_RECTR3_MASK)

#define AON_SYSPM_PMCR_SELEVT1_MASK              (0x3F800U)
#define AON_SYSPM_PMCR_SELEVT1_SHIFT             (11U)
/*! SELEVT1 - Select Event 1 */
#define AON_SYSPM_PMCR_SELEVT1(x)                (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_SELEVT1_SHIFT)) & AON_SYSPM_PMCR_SELEVT1_MASK)

#define AON_SYSPM_PMCR_SELEVT2_MASK              (0x1FC0000U)
#define AON_SYSPM_PMCR_SELEVT2_SHIFT             (18U)
/*! SELEVT2 - Select Event 2 */
#define AON_SYSPM_PMCR_SELEVT2(x)                (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_SELEVT2_SHIFT)) & AON_SYSPM_PMCR_SELEVT2_MASK)

#define AON_SYSPM_PMCR_SELEVT3_MASK              (0xFE000000U)
#define AON_SYSPM_PMCR_SELEVT3_SHIFT             (25U)
/*! SELEVT3 - Select Event 3 */
#define AON_SYSPM_PMCR_SELEVT3(x)                (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMCR_SELEVT3_SHIFT)) & AON_SYSPM_PMCR_SELEVT3_MASK)
/*! @} */

/*! @name PMICTR_HI - Performance Monitor Instruction Counter */
/*! @{ */

#define AON_SYSPM_PMICTR_HI_ICTR_MASK            (0xFFU)
#define AON_SYSPM_PMICTR_HI_ICTR_SHIFT           (0U)
/*! ICTR - Instruction Counter */
#define AON_SYSPM_PMICTR_HI_ICTR(x)              (((uint8_t)(((uint8_t)(x)) << AON_SYSPM_PMICTR_HI_ICTR_SHIFT)) & AON_SYSPM_PMICTR_HI_ICTR_MASK)
/*! @} */

/* The count of AON_SYSPM_PMICTR_HI */
#define AON_SYSPM_PMICTR_HI_COUNT                (1U)

/*! @name PMICTR_LO - Performance Monitor Instruction Counter */
/*! @{ */

#define AON_SYSPM_PMICTR_LO_ICTR_MASK            (0xFFFFFFFFU)
#define AON_SYSPM_PMICTR_LO_ICTR_SHIFT           (0U)
/*! ICTR - Instruction Counter */
#define AON_SYSPM_PMICTR_LO_ICTR(x)              (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_PMICTR_LO_ICTR_SHIFT)) & AON_SYSPM_PMICTR_LO_ICTR_MASK)
/*! @} */

/* The count of AON_SYSPM_PMICTR_LO */
#define AON_SYSPM_PMICTR_LO_COUNT                (1U)

/*! @name HI - Performance Monitor Event Counter */
/*! @{ */

#define AON_SYSPM_HI_ECTR_MASK                   (0xFFU)
#define AON_SYSPM_HI_ECTR_SHIFT                  (0U)
/*! ECTR - Event Counter */
#define AON_SYSPM_HI_ECTR(x)                     (((uint8_t)(((uint8_t)(x)) << AON_SYSPM_HI_ECTR_SHIFT)) & AON_SYSPM_HI_ECTR_MASK)
/*! @} */

/* The count of AON_SYSPM_HI */
#define AON_SYSPM_HI_COUNT                       (1U)

/* The count of AON_SYSPM_HI */
#define AON_SYSPM_HI_COUNT2                      (3U)

/*! @name LO - Performance Monitor Event Counter */
/*! @{ */

#define AON_SYSPM_LO_ECTR_MASK                   (0xFFFFFFFFU)
#define AON_SYSPM_LO_ECTR_SHIFT                  (0U)
/*! ECTR - Event Counter */
#define AON_SYSPM_LO_ECTR(x)                     (((uint32_t)(((uint32_t)(x)) << AON_SYSPM_LO_ECTR_SHIFT)) & AON_SYSPM_LO_ECTR_MASK)
/*! @} */

/* The count of AON_SYSPM_LO */
#define AON_SYSPM_LO_COUNT                       (1U)

/* The count of AON_SYSPM_LO */
#define AON_SYSPM_LO_COUNT2                      (3U)


/*!
 * @}
 */ /* end of group AON_SYSPM_Register_Masks */


/*!
 * @}
 */ /* end of group AON_SYSPM_Peripheral_Access_Layer */


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


#endif  /* AON_SYSPM_H_ */

