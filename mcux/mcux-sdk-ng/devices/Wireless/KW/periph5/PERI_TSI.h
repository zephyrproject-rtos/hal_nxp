/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TSI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file TSI.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for TSI
 *
 * CMSIS Peripheral Access Layer for TSI
 */

#if !defined(TSI_H_)
#define TSI_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Peripheral_Access_Layer TSI Peripheral Access Layer
 * @{
 */

/** TSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t GENCS;                             /**< TSI General Control and Status Register, offset: 0x0 */
  __IO uint32_t DATA;                              /**< TSI DATA Register, offset: 0x4 */
  __IO uint32_t TSHD;                              /**< TSI Threshold Register, offset: 0x8 */
} TSI_Type;

/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/*! @name GENCS - TSI General Control and Status Register */
/*! @{ */

#define TSI_GENCS_CURSW_MASK                     (0x2U)
#define TSI_GENCS_CURSW_SHIFT                    (1U)
/*! CURSW - CURSW
 *  0b0..The current source pair are not swapped.
 *  0b1..The current source pair are swapped.
 */
#define TSI_GENCS_CURSW(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_CURSW_SHIFT)) & TSI_GENCS_CURSW_MASK)

#define TSI_GENCS_EOSF_MASK                      (0x4U)
#define TSI_GENCS_EOSF_SHIFT                     (2U)
/*! EOSF - End of Scan Flag
 *  0b0..Scan not complete.
 *  0b1..Scan complete.
 */
#define TSI_GENCS_EOSF(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_EOSF_SHIFT)) & TSI_GENCS_EOSF_MASK)

#define TSI_GENCS_SCNIP_MASK                     (0x8U)
#define TSI_GENCS_SCNIP_SHIFT                    (3U)
/*! SCNIP - Scan In Progress Status
 *  0b0..No scan in progress.
 *  0b1..Scan in progress.
 */
#define TSI_GENCS_SCNIP(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_SCNIP_SHIFT)) & TSI_GENCS_SCNIP_MASK)

#define TSI_GENCS_STM_MASK                       (0x10U)
#define TSI_GENCS_STM_SHIFT                      (4U)
/*! STM - Scan Trigger Mode
 *  0b0..Software trigger scan.
 *  0b1..Hardware trigger scan.
 */
#define TSI_GENCS_STM(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_STM_SHIFT)) & TSI_GENCS_STM_MASK)

#define TSI_GENCS_STPE_MASK                      (0x20U)
#define TSI_GENCS_STPE_SHIFT                     (5U)
/*! STPE - TSI STOP Enable
 *  0b0..TSI is disabled when MCU goes into low power mode.
 *  0b1..Allows TSI to continue running in all low power modes.
 */
#define TSI_GENCS_STPE(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_STPE_SHIFT)) & TSI_GENCS_STPE_MASK)

#define TSI_GENCS_TSIIEN_MASK                    (0x40U)
#define TSI_GENCS_TSIIEN_SHIFT                   (6U)
/*! TSIIEN - Touch Sensing Input Interrupt Enable
 *  0b0..TSI interrupt is disabled.
 *  0b1..TSI interrupt is enabled.
 */
#define TSI_GENCS_TSIIEN(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSIIEN_SHIFT)) & TSI_GENCS_TSIIEN_MASK)

#define TSI_GENCS_TSIEN_MASK                     (0x80U)
#define TSI_GENCS_TSIEN_SHIFT                    (7U)
/*! TSIEN - Touch Sensing Input Module Enable
 *  0b0..TSI module disabled.
 *  0b1..TSI module enabled.
 */
#define TSI_GENCS_TSIEN(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSIEN_SHIFT)) & TSI_GENCS_TSIEN_MASK)

#define TSI_GENCS_NSCN_MASK                      (0x1F00U)
#define TSI_GENCS_NSCN_SHIFT                     (8U)
/*! NSCN - NSCN
 *  0b00000..Once per electrode
 *  0b00001..Twice per electrode
 *  0b00010..3 times per electrode
 *  0b00011..4 times per electrode
 *  0b00100..5 times per electrode
 *  0b00101..6 times per electrode
 *  0b00110..7 times per electrode
 *  0b00111..8 times per electrode
 *  0b01000..9 times per electrode
 *  0b01001..10 times per electrode
 *  0b01010..11 times per electrode
 *  0b01011..12 times per electrode
 *  0b01100..13 times per electrode
 *  0b01101..14 times per electrode
 *  0b01110..15 times per electrode
 *  0b01111..16 times per electrode
 *  0b10000..17 times per electrode
 *  0b10001..18 times per electrode
 *  0b10010..19 times per electrode
 *  0b10011..20 times per electrode
 *  0b10100..21 times per electrode
 *  0b10101..22 times per electrode
 *  0b10110..23 times per electrode
 *  0b10111..24 times per electrode
 *  0b11000..25 times per electrode
 *  0b11001..26 times per electrode
 *  0b11010..27 times per electrode
 *  0b11011..28 times per electrode
 *  0b11100..29 times per electrode
 *  0b11101..30 times per electrode
 *  0b11110..31 times per electrode
 *  0b11111..32 times per electrode
 */
#define TSI_GENCS_NSCN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_NSCN_SHIFT)) & TSI_GENCS_NSCN_MASK)

#define TSI_GENCS_PS_MASK                        (0xE000U)
#define TSI_GENCS_PS_SHIFT                       (13U)
/*! PS - PS
 *  0b000..Electrode Oscillator Frequency divided by 1
 *  0b001..Electrode Oscillator Frequency divided by 2
 *  0b010..Electrode Oscillator Frequency divided by 4
 *  0b011..Electrode Oscillator Frequency divided by 8
 *  0b100..Electrode Oscillator Frequency divided by 16
 *  0b101..Electrode Oscillator Frequency divided by 32
 *  0b110..Electrode Oscillator Frequency divided by 64
 *  0b111..Electrode Oscillator Frequency divided by 128
 */
#define TSI_GENCS_PS(x)                          (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_PS_SHIFT)) & TSI_GENCS_PS_MASK)

#define TSI_GENCS_EXTCHRG_MASK                   (0x70000U)
#define TSI_GENCS_EXTCHRG_SHIFT                  (16U)
/*! EXTCHRG - EXTCHRG
 *  0b000..500 nA.
 *  0b001..1 uA.
 *  0b010..2 uA.
 *  0b011..4 uA.
 *  0b100..8 uA.
 *  0b101..16 uA.
 *  0b110..32 uA.
 *  0b111..64 uA.
 */
#define TSI_GENCS_EXTCHRG(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_EXTCHRG_SHIFT)) & TSI_GENCS_EXTCHRG_MASK)

#define TSI_GENCS_DVOLT_MASK                     (0x180000U)
#define TSI_GENCS_DVOLT_SHIFT                    (19U)
/*! DVOLT - DVOLT
 *  0b00..DV = 1.026 V; VP = 1.328 V; Vm = 0.302 V.
 *  0b01..DV = 0.592 V; VP = 1.111 V; Vm = 0.519 V.
 *  0b10..DV = 0.342 V; VP = 0.986 V; Vm = 0.644 V.
 *  0b11..DV = 0.197 V; VP = 0.914 V; Vm = 0.716 V.
 */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DVOLT_SHIFT)) & TSI_GENCS_DVOLT_MASK)

#define TSI_GENCS_REFCHRG_MASK                   (0xE00000U)
#define TSI_GENCS_REFCHRG_SHIFT                  (21U)
/*! REFCHRG - REFCHRG
 *  0b000..500 nA.
 *  0b001..1 uA.
 *  0b010..2 uA.
 *  0b011..4 uA.
 *  0b100..8 uA.
 *  0b101..16 uA.
 *  0b110..32 uA.
 *  0b111..64 uA.
 */
#define TSI_GENCS_REFCHRG(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_REFCHRG_SHIFT)) & TSI_GENCS_REFCHRG_MASK)

#define TSI_GENCS_MODE_MASK                      (0xF000000U)
#define TSI_GENCS_MODE_SHIFT                     (24U)
/*! MODE - TSI analog modes setup and status bits.
 *  0b0000..Set TSI in capacitive sensing(non-noise detection) mode.
 *  0b0100..Set TSI analog to work in single threshold noise detection mode and the frequency limitation circuit is disabled.
 *  0b1000..Set TSI analog to work in single threshold noise detection mode and the frequency limitation circuit
 *          is enabled to work in higher frequencies operations.
 *  0b1100..Set TSI analog to work in automatic noise detection mode.
 */
#define TSI_GENCS_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_MODE_SHIFT)) & TSI_GENCS_MODE_MASK)

#define TSI_GENCS_ESOR_MASK                      (0x10000000U)
#define TSI_GENCS_ESOR_SHIFT                     (28U)
/*! ESOR - End-of-scan or Out-of-Range Interrupt Selection
 *  0b0..Out-of-range interrupt is allowed.
 *  0b1..End-of-scan interrupt is allowed.
 */
#define TSI_GENCS_ESOR(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_ESOR_SHIFT)) & TSI_GENCS_ESOR_MASK)

#define TSI_GENCS_OUTRGF_MASK                    (0x80000000U)
#define TSI_GENCS_OUTRGF_SHIFT                   (31U)
/*! OUTRGF - Out of Range Flag. */
#define TSI_GENCS_OUTRGF(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_OUTRGF_SHIFT)) & TSI_GENCS_OUTRGF_MASK)
/*! @} */

/*! @name DATA - TSI DATA Register */
/*! @{ */

#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)
#define TSI_DATA_TSICNT_SHIFT                    (0U)
/*! TSICNT - TSI Conversion Counter Value */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICNT_SHIFT)) & TSI_DATA_TSICNT_MASK)

#define TSI_DATA_SWTS_MASK                       (0x400000U)
#define TSI_DATA_SWTS_SHIFT                      (22U)
/*! SWTS - Software Trigger Start
 *  0b0..No effect.
 *  0b1..Start a scan to determine which channel is specified by TSI_DATA[TSICH].
 */
#define TSI_DATA_SWTS(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_DATA_SWTS_SHIFT)) & TSI_DATA_SWTS_MASK)

#define TSI_DATA_DMAEN_MASK                      (0x800000U)
#define TSI_DATA_DMAEN_SHIFT                     (23U)
/*! DMAEN - DMA Transfer Enabled
 *  0b0..Interrupt is selected when the interrupt enable bit is set and the corresponding TSI events assert.
 *  0b1..DMA transfer request is selected when the interrupt enable bit is set and the corresponding TSI events assert.
 */
#define TSI_DATA_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_DATA_DMAEN_SHIFT)) & TSI_DATA_DMAEN_MASK)

#define TSI_DATA_TSICH_MASK                      (0xF0000000U)
#define TSI_DATA_TSICH_SHIFT                     (28U)
/*! TSICH - TSICH
 *  0b0000..Channel 0.
 *  0b0001..Channel 1.
 *  0b0010..Channel 2.
 *  0b0011..Channel 3.
 *  0b0100..Channel 4.
 *  0b0101..Channel 5.
 *  0b0110..Channel 6.
 *  0b0111..Channel 7.
 *  0b1000..Channel 8.
 *  0b1001..Channel 9.
 *  0b1010..Channel 10.
 *  0b1011..Channel 11.
 *  0b1100..Channel 12.
 *  0b1101..Channel 13.
 *  0b1110..Channel 14.
 *  0b1111..Channel 15.
 */
#define TSI_DATA_TSICH(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICH_SHIFT)) & TSI_DATA_TSICH_MASK)
/*! @} */

/*! @name TSHD - TSI Threshold Register */
/*! @{ */

#define TSI_TSHD_THRESL_MASK                     (0xFFFFU)
#define TSI_TSHD_THRESL_SHIFT                    (0U)
/*! THRESL - TSI Wakeup Channel Low-threshold */
#define TSI_TSHD_THRESL(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESL_SHIFT)) & TSI_TSHD_THRESL_MASK)

#define TSI_TSHD_THRESH_MASK                     (0xFFFF0000U)
#define TSI_TSHD_THRESH_SHIFT                    (16U)
/*! THRESH - TSI Wakeup Channel High-threshold */
#define TSI_TSHD_THRESH(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_TSHD_THRESH_SHIFT)) & TSI_TSHD_THRESH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TSI_Register_Masks */


/*!
 * @}
 */ /* end of group TSI_Peripheral_Access_Layer */


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


#endif  /* TSI_H_ */

