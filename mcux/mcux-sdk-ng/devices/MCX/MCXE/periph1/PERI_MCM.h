/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MCM.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Size of Registers Arrays */
#define MCM_LMEM_DESC__COUNT                      5u

/** MCM - Register Layout Typedef */
typedef struct {
  __I  uint16_t PLREV;                             /**< SoC-defined Platform Revision, offset: 0x0 */
  __I  uint16_t PCT;                               /**< Processor Core Type, offset: 0x2 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CPCR;                              /**< Core Platform Control, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control, offset: 0x10 */
       uint8_t RESERVED_1[1004];
  __I  uint32_t LMEM_DESC[MCM_LMEM_DESC__COUNT];   /**< Local Memory Descriptor 0..Local Memory Descriptor 4, array offset: 0x400, array step: 0x4 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLREV - SoC-defined Platform Revision */
/*! @{ */

#define MCM_PLREV_PLREV_MASK                     (0xFFFFU)
#define MCM_PLREV_PLREV_SHIFT                    (0U)
/*! PLREV - The PLREV[15:0] field is specified by a platform input signal to define a software-visible revision number. */
#define MCM_PLREV_PLREV(x)                       (((uint16_t)(((uint16_t)(x)) << MCM_PLREV_PLREV_SHIFT)) & MCM_PLREV_PLREV_MASK)
/*! @} */

/*! @name PCT - Processor Core Type */
/*! @{ */

#define MCM_PCT_PCT_MASK                         (0xFFFFU)
#define MCM_PCT_PCT_SHIFT                        (0U)
/*! PCT - This MCM design supports the Arm Cortex M7 core. The following value identifies this core complex.
 *  0b1010110001110000..Arm Cortex M7
 */
#define MCM_PCT_PCT(x)                           (((uint16_t)(((uint16_t)(x)) << MCM_PCT_PCT_SHIFT)) & MCM_PCT_PCT_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control */
/*! @{ */

#define MCM_CPCR_CM7_AHBSPRI_MASK                (0x8000000U)
#define MCM_CPCR_CM7_AHBSPRI_SHIFT               (27U)
/*! CM7_AHBSPRI - AHB Slave Priority
 *  0b0..Uses a round-robin arbitration scheme
 *  0b1..AHB-slave access has priority over a core access
 */
#define MCM_CPCR_CM7_AHBSPRI(x)                  (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CM7_AHBSPRI_SHIFT)) & MCM_CPCR_CM7_AHBSPRI_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define MCM_ISCR_WABS_MASK                       (0x20U)
#define MCM_ISCR_WABS_SHIFT                      (5U)
/*! WABS - Write Abort on Slave
 *  0b0..No write abort occurred on AHBS interface
 *  0b1..Write abort occurred on AHBS interface
 */
#define MCM_ISCR_WABS(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_WABS_SHIFT)) & MCM_ISCR_WABS_MASK)

#define MCM_ISCR_WABSO_MASK                      (0x40U)
#define MCM_ISCR_WABSO_SHIFT                     (6U)
/*! WABSO - Write Abort on Slave Overrun
 *  0b0..No write abort overrun
 *  0b1..Write abort overrun occurred
 */
#define MCM_ISCR_WABSO(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_WABSO_SHIFT)) & MCM_ISCR_WABSO_MASK)

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
/*! FUFC - FPU Underflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_WABE_MASK                       (0x200000U)
#define MCM_ISCR_WABE_SHIFT                      (21U)
/*! WABE - TCM Write Abort Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable Interrupt
 */
#define MCM_ISCR_WABE(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_WABE_SHIFT)) & MCM_ISCR_WABE_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name LMEM_DESC - Local Memory Descriptor 0..Local Memory Descriptor 4 */
/*! @{ */

#define MCM_LMEM_DESC_MT_MASK                    (0xE000U)
#define MCM_LMEM_DESC_MT_SHIFT                   (13U)
/*! MT - Memory Type
 *  0b000..ITCM
 *  0b001..DTCM
 *  0b010..ICACHE
 *  0b011..DCACHE
 */
#define MCM_LMEM_DESC_MT(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_MT_SHIFT)) & MCM_LMEM_DESC_MT_MASK)

#define MCM_LMEM_DESC_DPW_MASK                   (0xE0000U)
#define MCM_LMEM_DESC_DPW_SHIFT                  (17U)
/*! DPW - Data Path Width
 *  0b000-0b001..Reserved
 *  0b010..LMEMn is 32-bits wide
 *  0b011..LMEMn is 64-bits wide
 *  0b100-0b111..Reserved
 */
#define MCM_LMEM_DESC_DPW(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_DPW_SHIFT)) & MCM_LMEM_DESC_DPW_MASK)

#define MCM_LMEM_DESC_WY_MASK                    (0xF00000U)
#define MCM_LMEM_DESC_WY_SHIFT                   (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No cache
 *  0b0010..2-way set associative
 *  0b0100..4-way set associative
 */
#define MCM_LMEM_DESC_WY(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_WY_SHIFT)) & MCM_LMEM_DESC_WY_MASK)

#define MCM_LMEM_DESC_LMSZ_MASK                  (0xF000000U)
#define MCM_LMEM_DESC_LMSZ_SHIFT                 (24U)
/*! LMSZ - Local Memory Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 *  0b0111..64 KB
 *  0b1000..128 KB
 *  0b1001..256 KB
 *  0b1010..512 KB
 *  0b1011..1024 KB
 *  0b1100..2048 KB
 *  0b1101..4096 KB
 *  0b1110..8192 KB
 *  0b1111..16384 KB
 */
#define MCM_LMEM_DESC_LMSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_LMSZ_SHIFT)) & MCM_LMEM_DESC_LMSZ_MASK)

#define MCM_LMEM_DESC_LMSZH_MASK                 (0x10000000U)
#define MCM_LMEM_DESC_LMSZH_SHIFT                (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEMn is a power-of-2 capacity
 *  0b1..LMEMn is not a power-of-2, with capacity of 0.75 x LMSZ
 */
#define MCM_LMEM_DESC_LMSZH(x)                   (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_LMSZH_SHIFT)) & MCM_LMEM_DESC_LMSZH_MASK)

#define MCM_LMEM_DESC_LMV_MASK                   (0x80000000U)
#define MCM_LMEM_DESC_LMV_SHIFT                  (31U)
/*! LMV - Local Memory Valid
 *  0b0..LMEMn not present
 *  0b1..LMEMn present
 */
#define MCM_LMEM_DESC_LMV(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMEM_DESC_LMV_SHIFT)) & MCM_LMEM_DESC_LMV_MASK)
/*! @} */

/* The count of MCM_LMEM_DESC */
#define MCM_LMEM_DESC_COUNT                      (5U)


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */

