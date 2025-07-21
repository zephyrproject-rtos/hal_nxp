/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPDAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LPDAC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LPDAC
 *
 * CMSIS Peripheral Access Layer for LPDAC
 */

#if !defined(PERI_LPDAC_H_)
#define PERI_LPDAC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
  __I  uint32_t VERID;                             /**< Version Identifier Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t DATA;                              /**< DAC Data Register, offset: 0x8 */
  __IO uint32_t GCR;                               /**< DAC Global Control Register, offset: 0xC */
  __IO uint32_t FCR;                               /**< DAC FIFO Control Register, offset: 0x10 */
  __I  uint32_t FPR;                               /**< DAC FIFO Pointer Register, offset: 0x14 */
  __IO uint32_t FSR;                               /**< FIFO Status Register, offset: 0x18 */
  __IO uint32_t IER;                               /**< DAC Interrupt Enable Register, offset: 0x1C */
  __IO uint32_t DER;                               /**< DAC DMA Enable Register, offset: 0x20 */
  __IO uint32_t RCR;                               /**< DAC Reset Control Register, offset: 0x24 */
  __IO uint32_t TCR;                               /**< DAC Trigger Control Register, offset: 0x28 */
} LPDAC_Type;

/* ----------------------------------------------------------------------------
   -- LPDAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPDAC_Register_Masks LPDAC Register Masks
 * @{
 */

/*! @name VERID - Version Identifier Register */
/*! @{ */

#define LPDAC_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPDAC_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Feature Identification Number */
#define LPDAC_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_FEATURE_SHIFT)) & LPDAC_VERID_FEATURE_MASK)

#define LPDAC_VERID_MINOR_MASK                   (0xFF0000U)
#define LPDAC_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor version number */
#define LPDAC_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MINOR_SHIFT)) & LPDAC_VERID_MINOR_MASK)

#define LPDAC_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPDAC_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major version number */
#define LPDAC_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_VERID_MAJOR_SHIFT)) & LPDAC_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LPDAC_PARAM_FIFOSZ_MASK                  (0x7U)
#define LPDAC_PARAM_FIFOSZ_SHIFT                 (0U)
/*! FIFOSZ - FIFO size
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

/*! @name DATA - DAC Data Register */
/*! @{ */

#define LPDAC_DATA_DATA_MASK                     (0xFFFU)
#define LPDAC_DATA_DATA_SHIFT                    (0U)
/*! DATA - In FIFO mode or swing back mode, this is the FIFO data entry. In buffer mode, write to
 *    this field will push the data to analog without trigger support. This field is write only and
 *    always read zero.
 */
#define LPDAC_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_DATA_DATA_SHIFT)) & LPDAC_DATA_DATA_MASK)
/*! @} */

/*! @name GCR - DAC Global Control Register */
/*! @{ */

#define LPDAC_GCR_DACEN_MASK                     (0x1U)
#define LPDAC_GCR_DACEN_SHIFT                    (0U)
/*! DACEN - DAC Enable
 *  0b0..The DAC system is disabled.
 *  0b1..The DAC system is enabled.
 */
#define LPDAC_GCR_DACEN(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACEN_SHIFT)) & LPDAC_GCR_DACEN_MASK)

#define LPDAC_GCR_DACRFS_MASK                    (0x2U)
#define LPDAC_GCR_DACRFS_SHIFT                   (1U)
/*! DACRFS - DAC Reference Select
 *  0b0..The DAC selects VREFH_INT as the reference voltage.
 *  0b1..The DAC selects VREFH_EXT as the reference voltage.
 */
#define LPDAC_GCR_DACRFS(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_DACRFS_SHIFT)) & LPDAC_GCR_DACRFS_MASK)

#define LPDAC_GCR_LPEN_MASK                      (0x4U)
#define LPDAC_GCR_LPEN_SHIFT                     (2U)
/*! LPEN - Low Power Enable
 *  0b0..High-Power mode
 *  0b1..Low-Power mode
 */
#define LPDAC_GCR_LPEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_LPEN_SHIFT)) & LPDAC_GCR_LPEN_MASK)

#define LPDAC_GCR_FIFOEN_MASK                    (0x8U)
#define LPDAC_GCR_FIFOEN_SHIFT                   (3U)
/*! FIFOEN - FIFO Enable
 *  0b0..FIFO mode is disabled and buffer mode is enabled. Any data written to DATA[DATA] goes to buffer then goes to conversion.
 *  0b1..FIFO mode is enabled. Data will be first read from FIFO to buffer then goes to conversion
 */
#define LPDAC_GCR_FIFOEN(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_FIFOEN_SHIFT)) & LPDAC_GCR_FIFOEN_MASK)

#define LPDAC_GCR_SWMD_MASK                      (0x10U)
#define LPDAC_GCR_SWMD_SHIFT                     (4U)
/*! SWMD - Swing Back Mode
 *  0b0..Swing back mode disable
 *  0b1..Swing back mode enable
 */
#define LPDAC_GCR_SWMD(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_SWMD_SHIFT)) & LPDAC_GCR_SWMD_MASK)

#define LPDAC_GCR_TRGSEL_MASK                    (0x20U)
#define LPDAC_GCR_TRGSEL_SHIFT                   (5U)
/*! TRGSEL - DAC Trigger Select
 *  0b0..The DAC hardware trigger is selected.
 *  0b1..The DAC software trigger is selected.
 */
#define LPDAC_GCR_TRGSEL(x)                      (((uint32_t)(((uint32_t)(x)) << LPDAC_GCR_TRGSEL_SHIFT)) & LPDAC_GCR_TRGSEL_MASK)
/*! @} */

/*! @name FCR - DAC FIFO Control Register */
/*! @{ */

#define LPDAC_FCR_WML_MASK                       (0xFU)
#define LPDAC_FCR_WML_SHIFT                      (0U)
/*! WML - Watermark Level */
#define LPDAC_FCR_WML(x)                         (((uint32_t)(((uint32_t)(x)) << LPDAC_FCR_WML_SHIFT)) & LPDAC_FCR_WML_MASK)
/*! @} */

/*! @name FPR - DAC FIFO Pointer Register */
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

/*! @name FSR - FIFO Status Register */
/*! @{ */

#define LPDAC_FSR_FULL_MASK                      (0x1U)
#define LPDAC_FSR_FULL_SHIFT                     (0U)
/*! FULL - FIFO Full Flag
 *  0b0..FIFO is not full
 *  0b1..FIFO is full
 */
#define LPDAC_FSR_FULL(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_FULL_SHIFT)) & LPDAC_FSR_FULL_MASK)

#define LPDAC_FSR_EMPTY_MASK                     (0x2U)
#define LPDAC_FSR_EMPTY_SHIFT                    (1U)
/*! EMPTY - FIFO Empty Flag
 *  0b0..FIFO is not empty
 *  0b1..FIFO is empty
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
 *  0b0..No swing back cycle has completed since the last time the flag was cleared.
 *  0b1..At least one swing back cycle has occurred since the last time the flag was cleared.
 */
#define LPDAC_FSR_SWBK(x)                        (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_SWBK_SHIFT)) & LPDAC_FSR_SWBK_MASK)

#define LPDAC_FSR_OF_MASK                        (0x40U)
#define LPDAC_FSR_OF_SHIFT                       (6U)
/*! OF - FIFO Overflow Flag
 *  0b0..No overflow has occurred since the last time the flag was cleared.
 *  0b1..At least one FIFO overflow has occurred since the last time the flag was cleared.
 */
#define LPDAC_FSR_OF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_OF_SHIFT)) & LPDAC_FSR_OF_MASK)

#define LPDAC_FSR_UF_MASK                        (0x80U)
#define LPDAC_FSR_UF_SHIFT                       (7U)
/*! UF - FIFO Underflow Flag
 *  0b0..No underflow has occurred since the last time the flag was cleared.
 *  0b1..At least one trigger underflow has occurred since the last time the flag was cleared.
 */
#define LPDAC_FSR_UF(x)                          (((uint32_t)(((uint32_t)(x)) << LPDAC_FSR_UF_SHIFT)) & LPDAC_FSR_UF_MASK)
/*! @} */

/*! @name IER - DAC Interrupt Enable Register */
/*! @{ */

#define LPDAC_IER_FULL_IE_MASK                   (0x1U)
#define LPDAC_IER_FULL_IE_SHIFT                  (0U)
/*! FULL_IE - FIFO Full Interrupt Enable
 *  0b0..FIFO Full interrupt is disabled.
 *  0b1..FIFO Full interrupt is enabled.
 */
#define LPDAC_IER_FULL_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_FULL_IE_SHIFT)) & LPDAC_IER_FULL_IE_MASK)

#define LPDAC_IER_EMPTY_IE_MASK                  (0x2U)
#define LPDAC_IER_EMPTY_IE_SHIFT                 (1U)
/*! EMPTY_IE - FIFO Empty Interrupt Enable
 *  0b0..FIFO Empty interrupt is disabled.
 *  0b1..FIFO Empty interrupt is enabled.
 */
#define LPDAC_IER_EMPTY_IE(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_EMPTY_IE_SHIFT)) & LPDAC_IER_EMPTY_IE_MASK)

#define LPDAC_IER_WM_IE_MASK                     (0x4U)
#define LPDAC_IER_WM_IE_SHIFT                    (2U)
/*! WM_IE - FIFO Watermark Interrupt Enable
 *  0b0..Watermark interrupt is disabled.
 *  0b1..Watermark interrupt is enabled.
 */
#define LPDAC_IER_WM_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_WM_IE_SHIFT)) & LPDAC_IER_WM_IE_MASK)

#define LPDAC_IER_SWBK_IE_MASK                   (0x8U)
#define LPDAC_IER_SWBK_IE_SHIFT                  (3U)
/*! SWBK_IE - Swing back One Cycle Complete Interrupt Enable
 *  0b0..Swing back one time complete interrupt is disabled.
 *  0b1..Swing back one time complete interrupt is enabled.
 */
#define LPDAC_IER_SWBK_IE(x)                     (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_SWBK_IE_SHIFT)) & LPDAC_IER_SWBK_IE_MASK)

#define LPDAC_IER_OF_IE_MASK                     (0x40U)
#define LPDAC_IER_OF_IE_SHIFT                    (6U)
/*! OF_IE - FIFO Overflow Interrupt Enable
 *  0b0..Overflow interrupt is disabled
 *  0b1..Overflow interrupt is enabled.
 */
#define LPDAC_IER_OF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_OF_IE_SHIFT)) & LPDAC_IER_OF_IE_MASK)

#define LPDAC_IER_UF_IE_MASK                     (0x80U)
#define LPDAC_IER_UF_IE_SHIFT                    (7U)
/*! UF_IE - FIFO Underflow Interrupt Enable
 *  0b0..Underflow interrupt is disabled.
 *  0b1..Underflow interrupt is enabled.
 */
#define LPDAC_IER_UF_IE(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_IER_UF_IE_SHIFT)) & LPDAC_IER_UF_IE_MASK)
/*! @} */

/*! @name DER - DAC DMA Enable Register */
/*! @{ */

#define LPDAC_DER_EMPTY_DMAEN_MASK               (0x2U)
#define LPDAC_DER_EMPTY_DMAEN_SHIFT              (1U)
/*! EMPTY_DMAEN - FIFO Empty DMA Enable
 *  0b0..FIFO Empty DMA request is disabled.
 *  0b1..FIFO Empty DMA request is enabled.
 */
#define LPDAC_DER_EMPTY_DMAEN(x)                 (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_EMPTY_DMAEN_SHIFT)) & LPDAC_DER_EMPTY_DMAEN_MASK)

#define LPDAC_DER_WM_DMAEN_MASK                  (0x4U)
#define LPDAC_DER_WM_DMAEN_SHIFT                 (2U)
/*! WM_DMAEN - FIFO Watermark DMA Enable
 *  0b0..Watermark DMA request is disabled.
 *  0b1..Watermark DMA request is enabled.
 */
#define LPDAC_DER_WM_DMAEN(x)                    (((uint32_t)(((uint32_t)(x)) << LPDAC_DER_WM_DMAEN_SHIFT)) & LPDAC_DER_WM_DMAEN_MASK)
/*! @} */

/*! @name RCR - DAC Reset Control Register */
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

/*! @name TCR - DAC Trigger Control Register */
/*! @{ */

#define LPDAC_TCR_SWTRG_MASK                     (0x1U)
#define LPDAC_TCR_SWTRG_SHIFT                    (0U)
/*! SWTRG - Software Trigger
 *  0b0..The DAC soft trigger is not valid.
 *  0b1..The DAC soft trigger is valid.
 */
#define LPDAC_TCR_SWTRG(x)                       (((uint32_t)(((uint32_t)(x)) << LPDAC_TCR_SWTRG_SHIFT)) & LPDAC_TCR_SWTRG_MASK)
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


#endif  /* PERI_LPDAC_H_ */

