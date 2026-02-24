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
**         CMSIS Peripheral Access Layer for WAKEUP_AUDMIX
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
 * @file PERI_WAKEUP_AUDMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WAKEUP_AUDMIX
 *
 * CMSIS Peripheral Access Layer for WAKEUP_AUDMIX
 */

#if !defined(PERI_WAKEUP_AUDMIX_H_)
#define PERI_WAKEUP_AUDMIX_H_                    /**< Symbol preventing repeated inclusion */

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
   -- WAKEUP_AUDMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AUDMIX_Peripheral_Access_Layer WAKEUP_AUDMIX Peripheral Access Layer
 * @{
 */

/** WAKEUP_AUDMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t CTR;                               /**< Control, offset: 0x200 */
  __I  uint32_t STR;                               /**< Status, offset: 0x204 */
  __IO uint32_t ATCR0;                             /**< Attenuation Control, offset: 0x208 */
  __IO uint32_t ATIVAL0;                           /**< Attenuation Initial Value, offset: 0x20C */
  __IO uint32_t ATSTPUP0;                          /**< Attenuation Step Up Factor, offset: 0x210 */
  __IO uint32_t ATSTPDN0;                          /**< Attenuation Step Down Factor, offset: 0x214 */
  __IO uint32_t ATSTPTGT0;                         /**< Attenuation Step Target, offset: 0x218 */
  __I  uint32_t ATTNVAL0;                          /**< Attenuation Value, offset: 0x21C */
  __I  uint32_t ATSTP0;                            /**< Attenuation Step Number, offset: 0x220 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ATCR1;                             /**< Attenuation Control, offset: 0x228 */
  __IO uint32_t ATIVAL1;                           /**< Attenuation Initial Value, offset: 0x22C */
  __IO uint32_t ATSTPUP1;                          /**< Attenuation Step Up Factor, offset: 0x230 */
  __IO uint32_t ATSTPDN1;                          /**< Attenuation Step Down Factor, offset: 0x234 */
  __IO uint32_t ATSTPTGT1;                         /**< Attenuation Step Target, offset: 0x238 */
  __I  uint32_t ATTNVAL1;                          /**< Attenuation Value, offset: 0x23C */
  __I  uint32_t ATSTP1;                            /**< Attenuation Step Number, offset: 0x240 */
} WAKEUP_AUDMIX_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_AUDMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AUDMIX_Register_Masks WAKEUP_AUDMIX Register Masks
 * @{
 */

/*! @name CTR - Control */
/*! @{ */

#define WAKEUP_AUDMIX_CTR_MIXCLK_MASK            (0x1U)
#define WAKEUP_AUDMIX_CTR_MIXCLK_SHIFT           (0U)
/*! MIXCLK - Mixing Clock Source Selection
 *  0b0..TDM 1 interface clock
 *  0b1..TDM 2 interface clock
 */
#define WAKEUP_AUDMIX_CTR_MIXCLK(x)              (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_MIXCLK_SHIFT)) & WAKEUP_AUDMIX_CTR_MIXCLK_MASK)

#define WAKEUP_AUDMIX_CTR_OUTSRC_MASK            (0x6U)
#define WAKEUP_AUDMIX_CTR_OUTSRC_SHIFT           (1U)
/*! OUTSRC - Output Source Selection
 *  0b00..Disabled
 *  0b01..TDM 1 audio
 *  0b10..TDM 2 audio
 *  0b11..Mixed audio
 */
#define WAKEUP_AUDMIX_CTR_OUTSRC(x)              (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_OUTSRC_SHIFT)) & WAKEUP_AUDMIX_CTR_OUTSRC_MASK)

#define WAKEUP_AUDMIX_CTR_OUTWIDTH_MASK          (0x38U)
#define WAKEUP_AUDMIX_CTR_OUTWIDTH_SHIFT         (3U)
/*! OUTWIDTH - Audio Sample Width in TDM Outgoing Frame
 *  0b000..16-bit
 *  0b001..18-bit
 *  0b010..20-bit
 *  0b011..24-bit
 *  0b100-0b111..32-bit
 */
#define WAKEUP_AUDMIX_CTR_OUTWIDTH(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_OUTWIDTH_SHIFT)) & WAKEUP_AUDMIX_CTR_OUTWIDTH_MASK)

#define WAKEUP_AUDMIX_CTR_OUTCKPOL_MASK          (0x40U)
#define WAKEUP_AUDMIX_CTR_OUTCKPOL_SHIFT         (6U)
/*! OUTCKPOL - Polarity of Bit Clock of TDM Out Interface
 *  0b0..Positive edge
 *  0b1..Negative edge
 */
#define WAKEUP_AUDMIX_CTR_OUTCKPOL(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_OUTCKPOL_SHIFT)) & WAKEUP_AUDMIX_CTR_OUTCKPOL_MASK)

#define WAKEUP_AUDMIX_CTR_MASKRTDF_MASK          (0x80U)
#define WAKEUP_AUDMIX_CTR_MASKRTDF_SHIFT         (7U)
/*! MASKRTDF - Mask Frame rate difference error
 *  0b0..Unmask error
 *  0b1..Mask error
 */
#define WAKEUP_AUDMIX_CTR_MASKRTDF(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_MASKRTDF_SHIFT)) & WAKEUP_AUDMIX_CTR_MASKRTDF_MASK)

#define WAKEUP_AUDMIX_CTR_MASKCKDF_MASK          (0x100U)
#define WAKEUP_AUDMIX_CTR_MASKCKDF_SHIFT         (8U)
/*! MASKCKDF - Mask Clock frequency difference error
 *  0b0..Unmask error
 *  0b1..Mask error
 */
#define WAKEUP_AUDMIX_CTR_MASKCKDF(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_MASKCKDF_SHIFT)) & WAKEUP_AUDMIX_CTR_MASKCKDF_MASK)

#define WAKEUP_AUDMIX_CTR_SYNCMODE_MASK          (0x200U)
#define WAKEUP_AUDMIX_CTR_SYNCMODE_SHIFT         (9U)
/*! SYNCMODE - Sync Mode Configuration Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define WAKEUP_AUDMIX_CTR_SYNCMODE(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_SYNCMODE_SHIFT)) & WAKEUP_AUDMIX_CTR_SYNCMODE_MASK)

#define WAKEUP_AUDMIX_CTR_SYNCSRC_MASK           (0x400U)
#define WAKEUP_AUDMIX_CTR_SYNCSRC_SHIFT          (10U)
/*! SYNCSRC - Sync Mode Cock Source
 *  0b0..TDM 1 interface
 *  0b1..TDM 2 interface
 */
#define WAKEUP_AUDMIX_CTR_SYNCSRC(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_CTR_SYNCSRC_SHIFT)) & WAKEUP_AUDMIX_CTR_SYNCSRC_MASK)
/*! @} */

/*! @name STR - Status */
/*! @{ */

#define WAKEUP_AUDMIX_STR_RATEDIFF_MASK          (0x1U)
#define WAKEUP_AUDMIX_STR_RATEDIFF_SHIFT         (0U)
/*! RATEDIFF - Rate Difference
 *  0b0..Match
 *  0b1..Mismatch
 */
#define WAKEUP_AUDMIX_STR_RATEDIFF(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_STR_RATEDIFF_SHIFT)) & WAKEUP_AUDMIX_STR_RATEDIFF_MASK)

#define WAKEUP_AUDMIX_STR_CLKDIFF_MASK           (0x2U)
#define WAKEUP_AUDMIX_STR_CLKDIFF_SHIFT          (1U)
/*! CLKDIFF - Bit Cock Difference
 *  0b0..Match
 *  0b1..Mismatch
 */
#define WAKEUP_AUDMIX_STR_CLKDIFF(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_STR_CLKDIFF_SHIFT)) & WAKEUP_AUDMIX_STR_CLKDIFF_MASK)

#define WAKEUP_AUDMIX_STR_MIXSTAT_MASK           (0xCU)
#define WAKEUP_AUDMIX_STR_MIXSTAT_SHIFT          (2U)
/*! MIXSTAT - Mixer Status
 *  0b00..Mixer in DISABLED state (no output)
 *  0b01..Mixer in TDM_1 state (output is TDM 1 stream)
 *  0b10..Mixer in TDM_2 state (output is TDM 2 stream)
 *  0b11..Mixer in MIXED state (output is MIXED stream of TDM 1 and TDM 2)
 */
#define WAKEUP_AUDMIX_STR_MIXSTAT(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_STR_MIXSTAT_SHIFT)) & WAKEUP_AUDMIX_STR_MIXSTAT_MASK)
/*! @} */

/*! @name ATCR0 - Attenuation Control */
/*! @{ */

#define WAKEUP_AUDMIX_ATCR0_AT_EN_MASK           (0x1U)
#define WAKEUP_AUDMIX_ATCR0_AT_EN_SHIFT          (0U)
/*! AT_EN - Attenuation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define WAKEUP_AUDMIX_ATCR0_AT_EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR0_AT_EN_SHIFT)) & WAKEUP_AUDMIX_ATCR0_AT_EN_MASK)

#define WAKEUP_AUDMIX_ATCR0_AT_UPDN_MASK         (0x2U)
#define WAKEUP_AUDMIX_ATCR0_AT_UPDN_SHIFT        (1U)
/*! AT_UPDN - Attenuation Direction
 *  0b0..Downward
 *  0b1..Upward
 */
#define WAKEUP_AUDMIX_ATCR0_AT_UPDN(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR0_AT_UPDN_SHIFT)) & WAKEUP_AUDMIX_ATCR0_AT_UPDN_MASK)

#define WAKEUP_AUDMIX_ATCR0_ATSTPDIV_MASK        (0x3FFCU)
#define WAKEUP_AUDMIX_ATCR0_ATSTPDIV_SHIFT       (2U)
/*! ATSTPDIV - Step Divider */
#define WAKEUP_AUDMIX_ATCR0_ATSTPDIV(x)          (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR0_ATSTPDIV_SHIFT)) & WAKEUP_AUDMIX_ATCR0_ATSTPDIV_MASK)
/*! @} */

/*! @name ATIVAL0 - Attenuation Initial Value */
/*! @{ */

#define WAKEUP_AUDMIX_ATIVAL0_ATINTVAL_MASK      (0x3FFFFU)
#define WAKEUP_AUDMIX_ATIVAL0_ATINTVAL_SHIFT     (0U)
/*! ATINTVAL - Attnuation Initial Value
 *  0b100000000000000000..0.5
 *  0b110000000000000000..0.75
 *  0b110000000000000001-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATIVAL0_ATINTVAL(x)        (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATIVAL0_ATINTVAL_SHIFT)) & WAKEUP_AUDMIX_ATIVAL0_ATINTVAL_MASK)
/*! @} */

/*! @name ATSTPUP0 - Attenuation Step Up Factor */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP_SHIFT    (0U)
/*! ATSTEPUP - Attnuation Step Up Factor
 *  0b100000000000000000..0.5
 *  0b100000000000000001-0b101010101010101001.....
 *  0b101010101010101010..0.666664124
 *  0b101010101010101011-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP_SHIFT)) & WAKEUP_AUDMIX_ATSTPUP0_ATSTEPUP_MASK)
/*! @} */

/*! @name ATSTPDN0 - Attenuation Step Down Factor */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN_SHIFT    (0U)
/*! ATSTEPDN - Attnuation Step Down Factor
 *  0b100000000000000000..0.5
 *  0b100000000000000001-0b101111111111111111.....
 *  0b110000000000000000..0.75
 *  0b110000000000000001-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN_SHIFT)) & WAKEUP_AUDMIX_ATSTPDN0_ATSTEPDN_MASK)
/*! @} */

/*! @name ATSTPTGT0 - Attenuation Step Target */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG_SHIFT    (0U)
/*! ATSTPTG - Attenuation Step Target Value */
#define WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG_SHIFT)) & WAKEUP_AUDMIX_ATSTPTGT0_ATSTPTG_MASK)
/*! @} */

/*! @name ATTNVAL0 - Attenuation Value */
/*! @{ */

#define WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_SHIFT    (0U)
/*! ATCURVAL - Current Value of Attenuation */
#define WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_SHIFT)) & WAKEUP_AUDMIX_ATTNVAL0_ATCURVAL_MASK)
/*! @} */

/*! @name ATSTP0 - Attenuation Step Number */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTP0_STPCTR_MASK         (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTP0_STPCTR_SHIFT        (0U)
/*! STPCTR - Step Counter Value */
#define WAKEUP_AUDMIX_ATSTP0_STPCTR(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTP0_STPCTR_SHIFT)) & WAKEUP_AUDMIX_ATSTP0_STPCTR_MASK)
/*! @} */

/*! @name ATCR1 - Attenuation Control */
/*! @{ */

#define WAKEUP_AUDMIX_ATCR1_AT_EN_MASK           (0x1U)
#define WAKEUP_AUDMIX_ATCR1_AT_EN_SHIFT          (0U)
/*! AT_EN - Attenuation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define WAKEUP_AUDMIX_ATCR1_AT_EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR1_AT_EN_SHIFT)) & WAKEUP_AUDMIX_ATCR1_AT_EN_MASK)

#define WAKEUP_AUDMIX_ATCR1_AT_UPDN_MASK         (0x2U)
#define WAKEUP_AUDMIX_ATCR1_AT_UPDN_SHIFT        (1U)
/*! AT_UPDN - Attenuation Direction
 *  0b0..Downward
 *  0b1..Upward
 */
#define WAKEUP_AUDMIX_ATCR1_AT_UPDN(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR1_AT_UPDN_SHIFT)) & WAKEUP_AUDMIX_ATCR1_AT_UPDN_MASK)

#define WAKEUP_AUDMIX_ATCR1_ATSTPDIV_MASK        (0x3FFCU)
#define WAKEUP_AUDMIX_ATCR1_ATSTPDIV_SHIFT       (2U)
/*! ATSTPDIV - Step Divider */
#define WAKEUP_AUDMIX_ATCR1_ATSTPDIV(x)          (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATCR1_ATSTPDIV_SHIFT)) & WAKEUP_AUDMIX_ATCR1_ATSTPDIV_MASK)
/*! @} */

/*! @name ATIVAL1 - Attenuation Initial Value */
/*! @{ */

#define WAKEUP_AUDMIX_ATIVAL1_ATINTVAL_MASK      (0x3FFFFU)
#define WAKEUP_AUDMIX_ATIVAL1_ATINTVAL_SHIFT     (0U)
/*! ATINTVAL - Attnuation Initial Value
 *  0b100000000000000000..0.5
 *  0b110000000000000000..0.75
 *  0b110000000000000001-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATIVAL1_ATINTVAL(x)        (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATIVAL1_ATINTVAL_SHIFT)) & WAKEUP_AUDMIX_ATIVAL1_ATINTVAL_MASK)
/*! @} */

/*! @name ATSTPUP1 - Attenuation Step Up Factor */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP_SHIFT    (0U)
/*! ATSTEPUP - Attnuation Step Up Factor
 *  0b100000000000000000..0.5
 *  0b100000000000000001-0b101010101010101001.....
 *  0b101010101010101010..0.666664124
 *  0b101010101010101011-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP_SHIFT)) & WAKEUP_AUDMIX_ATSTPUP1_ATSTEPUP_MASK)
/*! @} */

/*! @name ATSTPDN1 - Attenuation Step Down Factor */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN_SHIFT    (0U)
/*! ATSTEPDN - Attnuation Step Down Factor
 *  0b100000000000000000..0.5
 *  0b100000000000000001-0b101111111111111111.....
 *  0b110000000000000000..0.75
 *  0b110000000000000001-0b111111111111111110.....
 *  0b111111111111111111..0.999996185
 */
#define WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN_SHIFT)) & WAKEUP_AUDMIX_ATSTPDN1_ATSTEPDN_MASK)
/*! @} */

/*! @name ATSTPTGT1 - Attenuation Step Target */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG_SHIFT    (0U)
/*! ATSTPTG - Attenuation Step Target Value */
#define WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG_SHIFT)) & WAKEUP_AUDMIX_ATSTPTGT1_ATSTPTG_MASK)
/*! @} */

/*! @name ATTNVAL1 - Attenuation Value */
/*! @{ */

#define WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_MASK     (0x3FFFFU)
#define WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_SHIFT    (0U)
/*! ATCURVAL - Current Value of Attenuation */
#define WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_SHIFT)) & WAKEUP_AUDMIX_ATTNVAL1_ATCURVAL_MASK)
/*! @} */

/*! @name ATSTP1 - Attenuation Step Number */
/*! @{ */

#define WAKEUP_AUDMIX_ATSTP1_STPCTR_MASK         (0x3FFFFU)
#define WAKEUP_AUDMIX_ATSTP1_STPCTR_SHIFT        (0U)
/*! STPCTR - Step Counter Value */
#define WAKEUP_AUDMIX_ATSTP1_STPCTR(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_AUDMIX_ATSTP1_STPCTR_SHIFT)) & WAKEUP_AUDMIX_ATSTP1_STPCTR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_AUDMIX_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_AUDMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKEUP_AUDMIX_H_ */

