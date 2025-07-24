/*
** ###################################################################
**     Processors:          MIMXRT1165CVM5A_cm4
**                          MIMXRT1165CVM5A_cm7
**                          MIMXRT1165DVM6A_cm4
**                          MIMXRT1165DVM6A_cm7
**                          MIMXRT1165XVM5A_cm4
**                          MIMXRT1165XVM5A_cm7
**                          MIMXRT1166CVM5A_cm4
**                          MIMXRT1166CVM5A_cm7
**                          MIMXRT1166DVM6A_cm4
**                          MIMXRT1166DVM6A_cm7
**                          MIMXRT1166XVM5A_cm4
**                          MIMXRT1166XVM5A_cm7
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCIC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2020-12-29)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DCIC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DCIC
 *
 * CMSIS Peripheral Access Layer for DCIC
 */

#if !defined(PERI_DCIC_H_)
#define PERI_DCIC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1165CVM5A_cm4) || defined(CPU_MIMXRT1165DVM6A_cm4) || defined(CPU_MIMXRT1165XVM5A_cm4))
#include "MIMXRT1165_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1165CVM5A_cm7) || defined(CPU_MIMXRT1165DVM6A_cm7) || defined(CPU_MIMXRT1165XVM5A_cm7))
#include "MIMXRT1165_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm4) || defined(CPU_MIMXRT1166DVM6A_cm4) || defined(CPU_MIMXRT1166XVM5A_cm4))
#include "MIMXRT1166_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1166CVM5A_cm7) || defined(CPU_MIMXRT1166DVM6A_cm7) || defined(CPU_MIMXRT1166XVM5A_cm7))
#include "MIMXRT1166_cm7_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DCIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCIC_Peripheral_Access_Layer DCIC Peripheral Access Layer
 * @{
 */

/** DCIC - Size of Registers Arrays */
#define DCIC_REGION_COUNT                         16u

/** DCIC - Register Layout Typedef */
typedef struct {
  __IO uint32_t DCICC;                             /**< DCIC Control Register, offset: 0x0 */
  __IO uint32_t DCICIC;                            /**< DCIC Interrupt Control Register, offset: 0x4 */
  __IO uint32_t DCICS;                             /**< DCIC Status Register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x10, array step: 0x10 */
    __IO uint32_t DCICRC;                            /**< DCIC ROI Config Register, array offset: 0x10, array step: 0x10 */
    __IO uint32_t DCICRS;                            /**< DCIC ROI Size Register, array offset: 0x14, array step: 0x10 */
    __IO uint32_t DCICRRS;                           /**< DCIC ROI Reference Signature Register, array offset: 0x18, array step: 0x10 */
    __I  uint32_t DCICRCS;                           /**< DCIC ROI Calculated Signature Register, array offset: 0x1C, array step: 0x10 */
  } REGION[DCIC_REGION_COUNT];
} DCIC_Type;

/* ----------------------------------------------------------------------------
   -- DCIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCIC_Register_Masks DCIC Register Masks
 * @{
 */

/*! @name DCICC - DCIC Control Register */
/*! @{ */

#define DCIC_DCICC_IC_EN_MASK                    (0x1U)
#define DCIC_DCICC_IC_EN_SHIFT                   (0U)
/*! IC_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCIC_DCICC_IC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << DCIC_DCICC_IC_EN_SHIFT)) & DCIC_DCICC_IC_EN_MASK)

#define DCIC_DCICC_DE_POL_MASK                   (0x10U)
#define DCIC_DCICC_DE_POL_SHIFT                  (4U)
/*! DE_POL
 *  0b0..Active High.
 *  0b1..Active Low.
 */
#define DCIC_DCICC_DE_POL(x)                     (((uint32_t)(((uint32_t)(x)) << DCIC_DCICC_DE_POL_SHIFT)) & DCIC_DCICC_DE_POL_MASK)

#define DCIC_DCICC_HSYNC_POL_MASK                (0x20U)
#define DCIC_DCICC_HSYNC_POL_SHIFT               (5U)
/*! HSYNC_POL
 *  0b0..Active High.
 *  0b1..Active Low.
 */
#define DCIC_DCICC_HSYNC_POL(x)                  (((uint32_t)(((uint32_t)(x)) << DCIC_DCICC_HSYNC_POL_SHIFT)) & DCIC_DCICC_HSYNC_POL_MASK)

#define DCIC_DCICC_VSYNC_POL_MASK                (0x40U)
#define DCIC_DCICC_VSYNC_POL_SHIFT               (6U)
/*! VSYNC_POL
 *  0b0..Active High.
 *  0b1..Active Low.
 */
#define DCIC_DCICC_VSYNC_POL(x)                  (((uint32_t)(((uint32_t)(x)) << DCIC_DCICC_VSYNC_POL_SHIFT)) & DCIC_DCICC_VSYNC_POL_MASK)

#define DCIC_DCICC_CLK_POL_MASK                  (0x80U)
#define DCIC_DCICC_CLK_POL_SHIFT                 (7U)
/*! CLK_POL
 *  0b0..Not inverted (default).
 *  0b1..Inverted.
 */
#define DCIC_DCICC_CLK_POL(x)                    (((uint32_t)(((uint32_t)(x)) << DCIC_DCICC_CLK_POL_SHIFT)) & DCIC_DCICC_CLK_POL_MASK)
/*! @} */

/*! @name DCICIC - DCIC Interrupt Control Register */
/*! @{ */

#define DCIC_DCICIC_EI_MASK_MASK                 (0x1U)
#define DCIC_DCICIC_EI_MASK_SHIFT                (0U)
/*! EI_MASK
 *  0b0..Mask disabled - Interrupt assertion enabled
 *  0b1..Mask enabled - Interrupt assertion disabled
 */
#define DCIC_DCICIC_EI_MASK(x)                   (((uint32_t)(((uint32_t)(x)) << DCIC_DCICIC_EI_MASK_SHIFT)) & DCIC_DCICIC_EI_MASK_MASK)

#define DCIC_DCICIC_FI_MASK_MASK                 (0x2U)
#define DCIC_DCICIC_FI_MASK_SHIFT                (1U)
/*! FI_MASK
 *  0b0..Mask disabled - Interrupt assertion enabled
 *  0b1..Mask enabled - Interrupt assertion disabled
 */
#define DCIC_DCICIC_FI_MASK(x)                   (((uint32_t)(((uint32_t)(x)) << DCIC_DCICIC_FI_MASK_SHIFT)) & DCIC_DCICIC_FI_MASK_MASK)

#define DCIC_DCICIC_FREEZE_MASK_MASK             (0x8U)
#define DCIC_DCICIC_FREEZE_MASK_SHIFT            (3U)
/*! FREEZE_MASK
 *  0b0..Masks change allowed
 *  0b1..Masks are frozen
 */
#define DCIC_DCICIC_FREEZE_MASK(x)               (((uint32_t)(((uint32_t)(x)) << DCIC_DCICIC_FREEZE_MASK_SHIFT)) & DCIC_DCICIC_FREEZE_MASK_MASK)

#define DCIC_DCICIC_EXT_SIG_EN_MASK              (0x10000U)
#define DCIC_DCICIC_EXT_SIG_EN_SHIFT             (16U)
/*! EXT_SIG_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCIC_DCICIC_EXT_SIG_EN(x)                (((uint32_t)(((uint32_t)(x)) << DCIC_DCICIC_EXT_SIG_EN_SHIFT)) & DCIC_DCICIC_EXT_SIG_EN_MASK)
/*! @} */

/*! @name DCICS - DCIC Status Register */
/*! @{ */

#define DCIC_DCICS_ROI_MATCH_STAT_MASK           (0xFFFFU)
#define DCIC_DCICS_ROI_MATCH_STAT_SHIFT          (0U)
/*! ROI_MATCH_STAT
 *  0b0000000000000000..ROI calculated CRC matches expected signature
 *  0b0000000000000001..Mismatch at ROI calculated CRC
 */
#define DCIC_DCICS_ROI_MATCH_STAT(x)             (((uint32_t)(((uint32_t)(x)) << DCIC_DCICS_ROI_MATCH_STAT_SHIFT)) & DCIC_DCICS_ROI_MATCH_STAT_MASK)

#define DCIC_DCICS_EI_STAT_MASK                  (0x10000U)
#define DCIC_DCICS_EI_STAT_SHIFT                 (16U)
/*! EI_STAT
 *  0b0..No pending Interrupt
 *  0b1..Pending Interrupt
 */
#define DCIC_DCICS_EI_STAT(x)                    (((uint32_t)(((uint32_t)(x)) << DCIC_DCICS_EI_STAT_SHIFT)) & DCIC_DCICS_EI_STAT_MASK)

#define DCIC_DCICS_FI_STAT_MASK                  (0x20000U)
#define DCIC_DCICS_FI_STAT_SHIFT                 (17U)
/*! FI_STAT
 *  0b0..No pending Interrupt
 *  0b1..Pending Interrupt
 */
#define DCIC_DCICS_FI_STAT(x)                    (((uint32_t)(((uint32_t)(x)) << DCIC_DCICS_FI_STAT_SHIFT)) & DCIC_DCICS_FI_STAT_MASK)
/*! @} */

/*! @name DCICRC - DCIC ROI Config Register */
/*! @{ */

#define DCIC_DCICRC_START_OFFSET_X_MASK          (0x1FFFU)
#define DCIC_DCICRC_START_OFFSET_X_SHIFT         (0U)
#define DCIC_DCICRC_START_OFFSET_X(x)            (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRC_START_OFFSET_X_SHIFT)) & DCIC_DCICRC_START_OFFSET_X_MASK)

#define DCIC_DCICRC_START_OFFSET_Y_MASK          (0xFFF0000U)
#define DCIC_DCICRC_START_OFFSET_Y_SHIFT         (16U)
#define DCIC_DCICRC_START_OFFSET_Y(x)            (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRC_START_OFFSET_Y_SHIFT)) & DCIC_DCICRC_START_OFFSET_Y_MASK)

#define DCIC_DCICRC_ROI_FREEZE_MASK              (0x40000000U)
#define DCIC_DCICRC_ROI_FREEZE_SHIFT             (30U)
/*! ROI_FREEZE
 *  0b0..ROI configuration can be changed
 *  0b1..ROI configuration is frozen
 */
#define DCIC_DCICRC_ROI_FREEZE(x)                (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRC_ROI_FREEZE_SHIFT)) & DCIC_DCICRC_ROI_FREEZE_MASK)

#define DCIC_DCICRC_ROI_EN_MASK                  (0x80000000U)
#define DCIC_DCICRC_ROI_EN_SHIFT                 (31U)
/*! ROI_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCIC_DCICRC_ROI_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRC_ROI_EN_SHIFT)) & DCIC_DCICRC_ROI_EN_MASK)
/*! @} */

/* The count of DCIC_DCICRC */
#define DCIC_DCICRC_COUNT                        (16U)

/*! @name DCICRS - DCIC ROI Size Register */
/*! @{ */

#define DCIC_DCICRS_END_OFFSET_X_MASK            (0x1FFFU)
#define DCIC_DCICRS_END_OFFSET_X_SHIFT           (0U)
#define DCIC_DCICRS_END_OFFSET_X(x)              (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRS_END_OFFSET_X_SHIFT)) & DCIC_DCICRS_END_OFFSET_X_MASK)

#define DCIC_DCICRS_END_OFFSET_Y_MASK            (0xFFF0000U)
#define DCIC_DCICRS_END_OFFSET_Y_SHIFT           (16U)
#define DCIC_DCICRS_END_OFFSET_Y(x)              (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRS_END_OFFSET_Y_SHIFT)) & DCIC_DCICRS_END_OFFSET_Y_MASK)
/*! @} */

/* The count of DCIC_DCICRS */
#define DCIC_DCICRS_COUNT                        (16U)

/*! @name DCICRRS - DCIC ROI Reference Signature Register */
/*! @{ */

#define DCIC_DCICRRS_REFERENCE_SIGNATURE_MASK    (0xFFFFFFFFU)
#define DCIC_DCICRRS_REFERENCE_SIGNATURE_SHIFT   (0U)
#define DCIC_DCICRRS_REFERENCE_SIGNATURE(x)      (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRRS_REFERENCE_SIGNATURE_SHIFT)) & DCIC_DCICRRS_REFERENCE_SIGNATURE_MASK)
/*! @} */

/* The count of DCIC_DCICRRS */
#define DCIC_DCICRRS_COUNT                       (16U)

/*! @name DCICRCS - DCIC ROI Calculated Signature Register */
/*! @{ */

#define DCIC_DCICRCS_CALCULATED_SIGNATURE_MASK   (0xFFFFFFFFU)
#define DCIC_DCICRCS_CALCULATED_SIGNATURE_SHIFT  (0U)
#define DCIC_DCICRCS_CALCULATED_SIGNATURE(x)     (((uint32_t)(((uint32_t)(x)) << DCIC_DCICRCS_CALCULATED_SIGNATURE_SHIFT)) & DCIC_DCICRCS_CALCULATED_SIGNATURE_MASK)
/*! @} */

/* The count of DCIC_DCICRCS */
#define DCIC_DCICRCS_COUNT                       (16U)


/*!
 * @}
 */ /* end of group DCIC_Register_Masks */


/*!
 * @}
 */ /* end of group DCIC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_DCIC_H_ */

