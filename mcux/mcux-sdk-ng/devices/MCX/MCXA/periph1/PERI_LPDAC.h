/*
** ###################################################################
**     Processors:          MCXA144VFT
**                          MCXA144VLH
**                          MCXA144VLL
**                          MCXA144VMP
**                          MCXA144VPJ
**                          MCXA145VFT
**                          MCXA145VLH
**                          MCXA145VLL
**                          MCXA145VMP
**                          MCXA145VPJ
**                          MCXA146VFT
**                          MCXA146VLH
**                          MCXA146VLL
**                          MCXA146VMP
**                          MCXA146VPJ
**                          MCXA154VFT
**                          MCXA154VLH
**                          MCXA154VLL
**                          MCXA154VMP
**                          MCXA154VPJ
**                          MCXA155VFT
**                          MCXA155VLH
**                          MCXA155VLL
**                          MCXA155VMP
**                          MCXA155VPJ
**                          MCXA156VFT
**                          MCXA156VLH
**                          MCXA156VLL
**                          MCXA156VMP
**                          MCXA156VPJ
**
**     Version:             rev. 1.0, 2022-03-29
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPDAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-29)
**         Initial version based on v0.1UM
**
** ###################################################################
*/

/*!
 * @file LPDAC.h
 * @version 1.0
 * @date 2022-03-29
 * @brief CMSIS Peripheral Access Layer for LPDAC
 *
 * CMSIS Peripheral Access Layer for LPDAC
 */

#if !defined(LPDAC_H_)
#define LPDAC_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA144VFT) || defined(CPU_MCXA144VLH) || defined(CPU_MCXA144VLL) || defined(CPU_MCXA144VMP) || defined(CPU_MCXA144VPJ))
#include "MCXA144_COMMON.h"
#elif (defined(CPU_MCXA145VFT) || defined(CPU_MCXA145VLH) || defined(CPU_MCXA145VLL) || defined(CPU_MCXA145VMP) || defined(CPU_MCXA145VPJ))
#include "MCXA145_COMMON.h"
#elif (defined(CPU_MCXA146VFT) || defined(CPU_MCXA146VLH) || defined(CPU_MCXA146VLL) || defined(CPU_MCXA146VMP) || defined(CPU_MCXA146VPJ))
#include "MCXA146_COMMON.h"
#elif (defined(CPU_MCXA154VFT) || defined(CPU_MCXA154VLH) || defined(CPU_MCXA154VLL) || defined(CPU_MCXA154VMP) || defined(CPU_MCXA154VPJ))
#include "MCXA154_COMMON.h"
#elif (defined(CPU_MCXA155VFT) || defined(CPU_MCXA155VLH) || defined(CPU_MCXA155VLL) || defined(CPU_MCXA155VMP) || defined(CPU_MCXA155VPJ))
#include "MCXA155_COMMON.h"
#elif (defined(CPU_MCXA156VFT) || defined(CPU_MCXA156VLH) || defined(CPU_MCXA156VLL) || defined(CPU_MCXA156VMP) || defined(CPU_MCXA156VPJ))
#include "MCXA156_COMMON.h"
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
   -- LPDAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDAC_Peripheral_Access_Layer LPDAC Peripheral Access Layer
 * @{
 */

/** LPDAC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version Identifier, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
  __IO uint32_t DATA;                              /**< Data, offset: 0x8 */
  __IO uint32_t GCR;                               /**< Global Control, offset: 0xC */
  __IO uint32_t FCR;                               /**< DAC FIFO Control, offset: 0x10 */
  __I  uint32_t FPR;                               /**< DAC FIFO Pointer, offset: 0x14 */
  __IO uint32_t FSR;                               /**< FIFO Status, offset: 0x18 */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x1C */
  __IO uint32_t DER;                               /**< DMA Enable, offset: 0x20 */
  __IO uint32_t RCR;                               /**< Reset Control, offset: 0x24 */
  __IO uint32_t TCR;                               /**< Trigger Control, offset: 0x28 */
  __IO uint32_t PCR;                               /**< Periodic Trigger Control, offset: 0x2C */
} LPDAC_Type;

/* ----------------------------------------------------------------------------
   -- LPDAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDAC_Register_Masks LPDAC Register Masks
 * @{
 */

/*! @name VERID - Version Identifier */
/*! @{ */

#define LPDAC_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPDAC_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Identification Number */
#define LPDAC_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_FEATURE_SHIFT)) & LPDAC_VERID_FEATURE_MASK)

#define LPDAC_VERID_MINOR_MASK                   (0xFF0000U)
#define LPDAC_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPDAC_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MINOR_SHIFT)) & LPDAC_VERID_MINOR_MASK)

#define LPDAC_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPDAC_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPDAC_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MAJOR_SHIFT)) & LPDAC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter */
/*! @{ */

#define LPDAC_PARAM_FIFOSZ_MASK                  (0x7U)
#define LPDAC_PARAM_FIFOSZ_SHIFT                 (0U)
/*! FIFOSZ - FIFO Size
 *  0b000..Reserved
 *  0b001..FIFO depth is 4
 *  0b010..FIFO depth is 8
 *  0b011..FIFO depth is 16
 *  0b100..FIFO depth is 32
 *  0b101..FIFO depth is 64
 *  0b110..FIFO depth is 128
 *  0b111..FIFO depth is 256
 */
#define LPDAC_PARAM_FIFOSZ(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_PARAM_FIFOSZ_SHIFT)) & LPDAC_PARAM_FIFOSZ_MASK)
/*! @} */

/*! @name DATA - Data */
/*! @{ */

#define LPDAC_DATA_DATA_MASK                     (0xFFFU)
#define LPDAC_DATA_DATA_SHIFT                    (0U)
/*! DATA - FIFO Entry or Buffer Entry */
#define LPDAC_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_DATA_DATA_SHIFT)) & LPDAC_DATA_DATA_MASK)
/*! @} */

/*! @name GCR - Global Control */
/*! @{ */

#define LPDAC_GCR_DACEN_MASK                     (0x1U)
#define LPDAC_GCR_DACEN_SHIFT                    (0U)
/*! DACEN - DAC Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_DACEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACEN_SHIFT)) & LPDAC_GCR_DACEN_MASK)

#define LPDAC_GCR_DACRFS_MASK                    (0x6U)
#define LPDAC_GCR_DACRFS_SHIFT                   (1U)
/*! DACRFS - DAC Reference Select
 *  0b00..Selects VREFH0 as the reference voltage.
 *  0b01..Selects VREFH1 as the reference voltage.
 *  0b10..Selects VREFH2 as the reference voltage.
 *  0b11..Reserved.
 */
#define LPDAC_GCR_DACRFS(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACRFS_SHIFT)) & LPDAC_GCR_DACRFS_MASK)

#define LPDAC_GCR_FIFOEN_MASK                    (0x8U)
#define LPDAC_GCR_FIFOEN_SHIFT                   (3U)
/*! FIFOEN - FIFO Enable
 *  0b0..Enables FIFO mode and disables Buffer mode. Any data written to DATA[DATA] goes to buffer then goes to conversion.
 *  0b1..Enables FIFO mode. Data will be first read from FIFO to buffer and then goes to conversion.
 */
#define LPDAC_GCR_FIFOEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_FIFOEN_SHIFT)) & LPDAC_GCR_FIFOEN_MASK)

#define LPDAC_GCR_SWMD_MASK                      (0x10U)
#define LPDAC_GCR_SWMD_SHIFT                     (4U)
/*! SWMD - Swing Back Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_SWMD(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_SWMD_SHIFT)) & LPDAC_GCR_SWMD_MASK)

#define LPDAC_GCR_TRGSEL_MASK                    (0x20U)
#define LPDAC_GCR_TRGSEL_SHIFT                   (5U)
/*! TRGSEL - DAC Trigger Select
 *  0b0..Hardware trigger
 *  0b1..Software trigger
 */
#define LPDAC_GCR_TRGSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_TRGSEL_SHIFT)) & LPDAC_GCR_TRGSEL_MASK)

#define LPDAC_GCR_PTGEN_MASK                     (0x40U)
#define LPDAC_GCR_PTGEN_SHIFT                    (6U)
/*! PTGEN - DAC Periodic Trigger Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_GCR_PTGEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_PTGEN_SHIFT)) & LPDAC_GCR_PTGEN_MASK)

#define LPDAC_GCR_LATCH_CYC_MASK                 (0xF00U)
#define LPDAC_GCR_LATCH_CYC_SHIFT                (8U)
/*! LATCH_CYC - RCLK Cycles Before Data Latch */
#define LPDAC_GCR_LATCH_CYC(x)                   (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_LATCH_CYC_SHIFT)) & LPDAC_GCR_LATCH_CYC_MASK)

#define LPDAC_GCR_BUF_EN_MASK                    (0x20000U)
#define LPDAC_GCR_BUF_EN_SHIFT                   (17U)
/*! BUF_EN - Buffer Enable
 *  0b0..Not used
 *  0b1..Used
 */
#define LPDAC_GCR_BUF_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_BUF_EN_SHIFT)) & LPDAC_GCR_BUF_EN_MASK)

#define LPDAC_GCR_IREF_PTAT_EXT_SEL_MASK         (0x100000U)
#define LPDAC_GCR_IREF_PTAT_EXT_SEL_SHIFT        (20U)
/*! IREF_PTAT_EXT_SEL - External On-Chip PTAT Current Reference Select
 *  0b0..Not selected
 *  0b1..Selected
 */
#define LPDAC_GCR_IREF_PTAT_EXT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_IREF_PTAT_EXT_SEL_SHIFT)) & LPDAC_GCR_IREF_PTAT_EXT_SEL_MASK)

#define LPDAC_GCR_IREF_ZTC_EXT_SEL_MASK          (0x200000U)
#define LPDAC_GCR_IREF_ZTC_EXT_SEL_SHIFT         (21U)
/*! IREF_ZTC_EXT_SEL - External On-Chip ZTC Current Reference Select
 *  0b0..Not selected
 *  0b1..Selected
 */
#define LPDAC_GCR_IREF_ZTC_EXT_SEL(x)            (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_IREF_ZTC_EXT_SEL_SHIFT)) & LPDAC_GCR_IREF_ZTC_EXT_SEL_MASK)

#define LPDAC_GCR_BUF_SPD_CTRL_MASK              (0x800000U)
#define LPDAC_GCR_BUF_SPD_CTRL_SHIFT             (23U)
/*! BUF_SPD_CTRL - OPAMP as Buffer, Speed Control Signal
 *  0b0..Lower Low-Power mode
 *  0b1..Low-Power mode
 */
#define LPDAC_GCR_BUF_SPD_CTRL(x)                (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_BUF_SPD_CTRL_SHIFT)) & LPDAC_GCR_BUF_SPD_CTRL_MASK)
/*! @} */

/*! @name FCR - DAC FIFO Control */
/*! @{ */

#define LPDAC_FCR_WML_MASK                       (0xFU)
#define LPDAC_FCR_WML_SHIFT                      (0U)
/*! WML - Watermark Level */
#define LPDAC_FCR_WML(x)                         (((uint32_t)(((uint32_t)(x)) << LPDAC_FCR_WML_SHIFT)) & LPDAC_FCR_WML_MASK)
/*! @} */

/*! @name FPR - DAC FIFO Pointer */
/*! @{ */

#define LPDAC_FPR_FIFO_RPT_MASK                  (0xFU)
#define LPDAC_FPR_FIFO_RPT_SHIFT                 (0U)
/*! FIFO_RPT - FIFO Read Pointer */
#define LPDAC_FPR_FIFO_RPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_FPR_FIFO_RPT_SHIFT)) & LPDAC_FPR_FIFO_RPT_MASK)

#define LPDAC_FPR_FIFO_WPT_MASK                  (0xF0000U)
#define LPDAC_FPR_FIFO_WPT_SHIFT                 (16U)
/*! FIFO_WPT - FIFO Write Pointer */
#define LPDAC_FPR_FIFO_WPT(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_FPR_FIFO_WPT_SHIFT)) & LPDAC_FPR_FIFO_WPT_MASK)
/*! @} */

/*! @name FSR - FIFO Status */
/*! @{ */

#define LPDAC_FSR_FULL_MASK                      (0x1U)
#define LPDAC_FSR_FULL_SHIFT                     (0U)
/*! FULL - FIFO Full Flag
 *  0b0..Not full
 *  0b1..Full
 */
#define LPDAC_FSR_FULL(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_FULL_SHIFT)) & LPDAC_FSR_FULL_MASK)

#define LPDAC_FSR_EMPTY_MASK                     (0x2U)
#define LPDAC_FSR_EMPTY_SHIFT                    (1U)
/*! EMPTY - FIFO Empty Flag
 *  0b0..Not empty
 *  0b1..Empty
 */
#define LPDAC_FSR_EMPTY(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_EMPTY_SHIFT)) & LPDAC_FSR_EMPTY_MASK)

#define LPDAC_FSR_WM_MASK                        (0x4U)
#define LPDAC_FSR_WM_SHIFT                       (2U)
/*! WM - FIFO Watermark Status Flag
 *  0b0..Data in FIFO is more than watermark level
 *  0b1..Data in FIFO is less than or equal to watermark level
 */
#define LPDAC_FSR_WM(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_WM_SHIFT)) & LPDAC_FSR_WM_MASK)

#define LPDAC_FSR_SWBK_MASK                      (0x8U)
#define LPDAC_FSR_SWBK_SHIFT                     (3U)
/*! SWBK - Swing Back One Cycle Complete Flag
 *  0b0..No swing back cycle has completed since the last time the flag was cleared
 *  0b1..At least one swing back cycle has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_SWBK(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_SWBK_SHIFT)) & LPDAC_FSR_SWBK_MASK)

#define LPDAC_FSR_OF_MASK                        (0x40U)
#define LPDAC_FSR_OF_SHIFT                       (6U)
/*! OF - FIFO Overflow Flag
 *  0b0..No overflow has occurred since the last time the flag was cleared
 *  0b1..At least one FIFO overflow has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_OF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_OF_SHIFT)) & LPDAC_FSR_OF_MASK)

#define LPDAC_FSR_UF_MASK                        (0x80U)
#define LPDAC_FSR_UF_SHIFT                       (7U)
/*! UF - FIFO Underflow Flag
 *  0b0..No underflow has occurred since the last time the flag was cleared
 *  0b1..At least one trigger underflow has occurred since the last time the flag was cleared
 */
#define LPDAC_FSR_UF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_UF_SHIFT)) & LPDAC_FSR_UF_MASK)

#define LPDAC_FSR_PTGCOCO_MASK                   (0x100U)
#define LPDAC_FSR_PTGCOCO_SHIFT                  (8U)
/*! PTGCOCO - Period Trigger Mode Conversion Complete Flag
 *  0b0..Not completed or not started
 *  0b1..Completed
 */
#define LPDAC_FSR_PTGCOCO(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_PTGCOCO_SHIFT)) & LPDAC_FSR_PTGCOCO_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define LPDAC_IER_FULL_IE_MASK                   (0x1U)
#define LPDAC_IER_FULL_IE_SHIFT                  (0U)
/*! FULL_IE - FIFO Full Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_FULL_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_FULL_IE_SHIFT)) & LPDAC_IER_FULL_IE_MASK)

#define LPDAC_IER_EMPTY_IE_MASK                  (0x2U)
#define LPDAC_IER_EMPTY_IE_SHIFT                 (1U)
/*! EMPTY_IE - FIFO Empty Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_EMPTY_IE(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_EMPTY_IE_SHIFT)) & LPDAC_IER_EMPTY_IE_MASK)

#define LPDAC_IER_WM_IE_MASK                     (0x4U)
#define LPDAC_IER_WM_IE_SHIFT                    (2U)
/*! WM_IE - FIFO Watermark Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_WM_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_WM_IE_SHIFT)) & LPDAC_IER_WM_IE_MASK)

#define LPDAC_IER_SWBK_IE_MASK                   (0x8U)
#define LPDAC_IER_SWBK_IE_SHIFT                  (3U)
/*! SWBK_IE - Swing Back One Cycle Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_SWBK_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_SWBK_IE_SHIFT)) & LPDAC_IER_SWBK_IE_MASK)

#define LPDAC_IER_OF_IE_MASK                     (0x40U)
#define LPDAC_IER_OF_IE_SHIFT                    (6U)
/*! OF_IE - FIFO Overflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_OF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_OF_IE_SHIFT)) & LPDAC_IER_OF_IE_MASK)

#define LPDAC_IER_UF_IE_MASK                     (0x80U)
#define LPDAC_IER_UF_IE_SHIFT                    (7U)
/*! UF_IE - FIFO Underflow Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_UF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_UF_IE_SHIFT)) & LPDAC_IER_UF_IE_MASK)

#define LPDAC_IER_PTGCOCO_IE_MASK                (0x100U)
#define LPDAC_IER_PTGCOCO_IE_SHIFT               (8U)
/*! PTGCOCO_IE - PTG Mode Conversion Complete Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_IER_PTGCOCO_IE(x)                  (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_PTGCOCO_IE_SHIFT)) & LPDAC_IER_PTGCOCO_IE_MASK)
/*! @} */

/*! @name DER - DMA Enable */
/*! @{ */

#define LPDAC_DER_EMPTY_DMAEN_MASK               (0x2U)
#define LPDAC_DER_EMPTY_DMAEN_SHIFT              (1U)
/*! EMPTY_DMAEN - FIFO Empty DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_DER_EMPTY_DMAEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_EMPTY_DMAEN_SHIFT)) & LPDAC_DER_EMPTY_DMAEN_MASK)

#define LPDAC_DER_WM_DMAEN_MASK                  (0x4U)
#define LPDAC_DER_WM_DMAEN_SHIFT                 (2U)
/*! WM_DMAEN - FIFO Watermark DMA Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LPDAC_DER_WM_DMAEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_WM_DMAEN_SHIFT)) & LPDAC_DER_WM_DMAEN_MASK)
/*! @} */

/*! @name RCR - Reset Control */
/*! @{ */

#define LPDAC_RCR_SWRST_MASK                     (0x1U)
#define LPDAC_RCR_SWRST_SHIFT                    (0U)
/*! SWRST - Software Reset
 *  0b0..No effect
 *  0b1..Software reset
 */
#define LPDAC_RCR_SWRST(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_RCR_SWRST_SHIFT)) & LPDAC_RCR_SWRST_MASK)

#define LPDAC_RCR_FIFORST_MASK                   (0x2U)
#define LPDAC_RCR_FIFORST_SHIFT                  (1U)
/*! FIFORST - FIFO Reset
 *  0b0..No effect
 *  0b1..FIFO reset
 */
#define LPDAC_RCR_FIFORST(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_RCR_FIFORST_SHIFT)) & LPDAC_RCR_FIFORST_MASK)
/*! @} */

/*! @name TCR - Trigger Control */
/*! @{ */

#define LPDAC_TCR_SWTRG_MASK                     (0x1U)
#define LPDAC_TCR_SWTRG_SHIFT                    (0U)
/*! SWTRG - Software Trigger
 *  0b0..Not valid
 *  0b1..Valid
 */
#define LPDAC_TCR_SWTRG(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_TCR_SWTRG_SHIFT)) & LPDAC_TCR_SWTRG_MASK)
/*! @} */

/*! @name PCR - Periodic Trigger Control */
/*! @{ */

#define LPDAC_PCR_PTG_NUM_MASK                   (0xFFFFU)
#define LPDAC_PCR_PTG_NUM_SHIFT                  (0U)
/*! PTG_NUM - Periodic Trigger Number */
#define LPDAC_PCR_PTG_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_PCR_PTG_NUM_SHIFT)) & LPDAC_PCR_PTG_NUM_MASK)

#define LPDAC_PCR_PTG_PERIOD_MASK                (0xFFFF0000U)
#define LPDAC_PCR_PTG_PERIOD_SHIFT               (16U)
/*! PTG_PERIOD - Periodic Trigger Period Width */
#define LPDAC_PCR_PTG_PERIOD(x)                  (((uint32_t)(((uint32_t)(x)) << LPDAC_PCR_PTG_PERIOD_SHIFT)) & LPDAC_PCR_PTG_PERIOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPDAC_Register_Masks */


/*!
 * @}
 */ /* end of group LPDAC_Peripheral_Access_Layer */


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


#endif  /* LPDAC_H_ */

