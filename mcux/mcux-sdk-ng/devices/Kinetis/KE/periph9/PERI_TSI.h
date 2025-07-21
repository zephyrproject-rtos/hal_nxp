/*
** ###################################################################
**     Processors:          MKE12Z512VLH9
**                          MKE12Z512VLL9
**                          MKE13Z512VLH9
**                          MKE13Z512VLL9
**                          MKE17Z512VLH9
**                          MKE17Z512VLL9
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TSI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-03-01)
**         Initial version.
**     - rev. 2.0 (2023-10-08)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TSI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TSI
 *
 * CMSIS Peripheral Access Layer for TSI
 */

#if !defined(PERI_TSI_H_)
#define PERI_TSI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z512VLH9) || defined(CPU_MKE12Z512VLL9))
#include "MKE12Z9_COMMON.h"
#elif (defined(CPU_MKE13Z512VLH9) || defined(CPU_MKE13Z512VLL9))
#include "MKE13Z9_COMMON.h"
#elif (defined(CPU_MKE17Z512VLH9) || defined(CPU_MKE17Z512VLL9))
#include "MKE17Z9_COMMON.h"
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
   -- TSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Peripheral_Access_Layer TSI Peripheral Access Layer
 * @{
 */

/** TSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t GENCS;                             /**< TSI general control and status register, offset: 0x0 */
  __IO uint32_t DATA;                              /**< TSI DATA register, offset: 0x4 */
  __IO uint32_t TSHD;                              /**< TSI threshold register, offset: 0x8 */
  __IO uint32_t MODE;                              /**< TSI MODE register, offset: 0xC */
  __IO uint32_t MUL0;                              /**< TSI MUTUAL-CAP Register 0, offset: 0x10 */
  __IO uint32_t MUL1;                              /**< TSI MUTUAL-CAP register 1, offset: 0x14 */
  __IO uint32_t SINC;                              /**< TSI SINC filter register, offset: 0x18 */
  __IO uint32_t SSC0;                              /**< TSI SSC register 0, offset: 0x1C */
  __IO uint32_t SSC1;                              /**< TSI SSC register 1, offset: 0x20 */
  __IO uint32_t SSC2;                              /**< TSI SSC register 2, offset: 0x24 */
  __IO uint32_t SHIELD;                            /**< TSI shield register, offset: 0x28 */
} TSI_Type;

/* ----------------------------------------------------------------------------
   -- TSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TSI_Register_Masks TSI Register Masks
 * @{
 */

/*! @name GENCS - TSI general control and status register */
/*! @{ */

#define TSI_GENCS_EOSDMEO_MASK                   (0x1U)
#define TSI_GENCS_EOSDMEO_SHIFT                  (0U)
/*! EOSDMEO - End-of-Scan DMA Transfer Request Enable Only
 *  0b0..Do not enable the End-of-Scan DMA transfer request only. Depending on ESOR state, either Out-of-Range or
 *       End-of-Scan can trigger a DMA transfer request and interrupt.
 *  0b1..Only the End-of-Scan event can trigger a DMA transfer request. The Out-of-Range event only and always triggers an interrupt if TSIIE is set.
 */
#define TSI_GENCS_EOSDMEO(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_EOSDMEO_SHIFT)) & TSI_GENCS_EOSDMEO_MASK)

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

#define TSI_GENCS_CLKSOC_SEL_MASK                (0x800U)
#define TSI_GENCS_CLKSOC_SEL_SHIFT               (11U)
/*! CLKSOC_SEL - CLKSOC_SEL */
#define TSI_GENCS_CLKSOC_SEL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_CLKSOC_SEL_SHIFT)) & TSI_GENCS_CLKSOC_SEL_MASK)

#define TSI_GENCS_RUN_CTRL_MASK                  (0x1000U)
#define TSI_GENCS_RUN_CTRL_SHIFT                 (12U)
/*! RUN_CTRL - RUN_CTRL */
#define TSI_GENCS_RUN_CTRL(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_RUN_CTRL_SHIFT)) & TSI_GENCS_RUN_CTRL_MASK)

#define TSI_GENCS_TSI_ANA_TEST_MASK              (0xE000U)
#define TSI_GENCS_TSI_ANA_TEST_SHIFT             (13U)
/*! TSI_ANA_TEST - TSI_ANA_TEST */
#define TSI_GENCS_TSI_ANA_TEST(x)                (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_TSI_ANA_TEST_SHIFT)) & TSI_GENCS_TSI_ANA_TEST_MASK)

#define TSI_GENCS_DVOLT_MASK                     (0x180000U)
#define TSI_GENCS_DVOLT_SHIFT                    (19U)
/*! DVOLT - DVOLT
 *  0b00..Vm=0.3V; Vp=1.3V; dvolt=1.0V.
 *  0b01..Vm=0.3V; Vp=1.6V; dvolt=1.3V.
 *  0b10..Vm=0.3V; Vp=1.9V; dvolt=1.6V.
 *  0b11..Vm=0.3V; Vp=2.3V; dvolt=2.0V.
 */
#define TSI_GENCS_DVOLT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_GENCS_DVOLT_SHIFT)) & TSI_GENCS_DVOLT_MASK)

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

/*! @name DATA - TSI DATA register */
/*! @{ */

#define TSI_DATA_TSICNT_MASK                     (0xFFFFU)
#define TSI_DATA_TSICNT_SHIFT                    (0U)
/*! TSICNT - TSI Conversion Counter Value */
#define TSI_DATA_TSICNT(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICNT_SHIFT)) & TSI_DATA_TSICNT_MASK)

#define TSI_DATA_SWTS_MASK                       (0x400000U)
#define TSI_DATA_SWTS_SHIFT                      (22U)
/*! SWTS - Software Trigger Start
 *  0b0..No effect.
 *  0b1..Start a scan.
 */
#define TSI_DATA_SWTS(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_DATA_SWTS_SHIFT)) & TSI_DATA_SWTS_MASK)

#define TSI_DATA_DMAEN_MASK                      (0x800000U)
#define TSI_DATA_DMAEN_SHIFT                     (23U)
/*! DMAEN - DMA Transfer Enabled
 *  0b0..Interrupt is selected when the interrupt enable bit is set and the corresponding TSI events assert.
 *  0b1..DMA transfer request is selected when the interrupt enable bit is set and the corresponding TSI events assert.
 */
#define TSI_DATA_DMAEN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_DATA_DMAEN_SHIFT)) & TSI_DATA_DMAEN_MASK)

#define TSI_DATA_TSICH_MASK                      (0xF8000000U)
#define TSI_DATA_TSICH_SHIFT                     (27U)
/*! TSICH - TSICH
 *  0b00000..For self-cap mode: Channel 0.
 *  0b00001..For self-cap mode: Channel 1.
 *  0b00010..For self-cap mode: Channel 2.
 *  0b00011..For self-cap mode: Channel 3.
 *  0b00100..For self-cap mode: Channel 4.
 *  0b00101..For self-cap mode: Channel 5.
 *  0b00110..For self-cap mode: Channel 6.
 *  0b00111..For self-cap mode: Channel 7.
 *  0b01000..For self-cap mode: Channel 8.
 *  0b01001..For self-cap mode: Channel 9.
 *  0b01010..For self-cap mode: Channel 10.
 *  0b01011..For self-cap mode: Channel 11.
 *  0b01100..For self-cap mode: Channel 12.
 *  0b01101..For self-cap mode: Channel 13.
 *  0b01110..For self-cap mode: Channel 14.
 *  0b01111..For self-cap mode: Channel 15.
 *  0b10000..For self-cap mode: Channel 16.
 *  0b10001..For self-cap mode: Channel 17.
 *  0b10010..For self-cap mode: Channel 18.
 *  0b10011..For self-cap mode: Channel 19.
 *  0b10100..For self-cap mode: Channel 20.
 *  0b10101..For self-cap mode: Channel 21.
 *  0b10110..For self-cap mode: Channel 22.
 *  0b10111..For self-cap mode: Channel 23.
 *  0b11000..For self-cap mode: Channel 24.
 */
#define TSI_DATA_TSICH(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_DATA_TSICH_SHIFT)) & TSI_DATA_TSICH_MASK)
/*! @} */

/*! @name TSHD - TSI threshold register */
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

/*! @name MODE - TSI MODE register */
/*! @{ */

#define TSI_MODE_S_NOISE_MASK                    (0x1U)
#define TSI_MODE_S_NOISE_SHIFT                   (0U)
/*! S_NOISE - S_NOISE
 *  0b0..noise cancellation off.
 *  0b1..noise cancellation on.
 */
#define TSI_MODE_S_NOISE(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_NOISE_SHIFT)) & TSI_MODE_S_NOISE_MASK)

#define TSI_MODE_MODE_MASK                       (0x2U)
#define TSI_MODE_MODE_SHIFT                      (1U)
/*! MODE - MODE
 *  0b0..self-cap mode.
 *  0b1..mutual-cap mode.
 */
#define TSI_MODE_MODE(x)                         (((uint32_t)(((uint32_t)(x)) << TSI_MODE_MODE_SHIFT)) & TSI_MODE_MODE_MASK)

#define TSI_MODE_SETCLK_MASK                     (0x60U)
#define TSI_MODE_SETCLK_SHIFT                    (5U)
/*! SETCLK - SETCLK
 *  0b00..20.72MHz.
 *  0b01..16.65MHz.
 *  0b10..13.87MHz.
 *  0b11..11.91MHz.
 */
#define TSI_MODE_SETCLK(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_MODE_SETCLK_SHIFT)) & TSI_MODE_SETCLK_MASK)

#define TSI_MODE_S_XCH_MASK                      (0x7000U)
#define TSI_MODE_S_XCH_SHIFT                     (12U)
/*! S_XCH - S_XCH
 *  0b000..1/16.
 *  0b001..1/8.
 *  0b010..1/4.
 *  0b011..1/2.
 *  0b100..NA.
 *  0b101..NA.
 *  0b110..NA.
 *  0b111..NA.
 */
#define TSI_MODE_S_XCH(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_XCH_SHIFT)) & TSI_MODE_S_XCH_MASK)

#define TSI_MODE_S_XIN_MASK                      (0x40000U)
#define TSI_MODE_S_XIN_SHIFT                     (18U)
/*! S_XIN - S_XIN
 *  0b0..1/8.
 *  0b1..1/4.
 */
#define TSI_MODE_S_XIN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_XIN_SHIFT)) & TSI_MODE_S_XIN_MASK)

#define TSI_MODE_S_CTRIM_MASK                    (0x380000U)
#define TSI_MODE_S_CTRIM_SHIFT                   (19U)
/*! S_CTRIM - Capacitor trim setting
 *  0b000..Ctrim=2.5p.
 *  0b001..Ctrim=5.0p.
 *  0b010..Ctrim=7.5p.
 *  0b011..Ctrim=10p.
 *  0b100..Ctrim=12.5p.
 *  0b101..Ctrim=15p.
 *  0b110..Ctrim=17.5p.
 *  0b111..Ctrim=20p.
 */
#define TSI_MODE_S_CTRIM(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_CTRIM_SHIFT)) & TSI_MODE_S_CTRIM_MASK)

#define TSI_MODE_S_SEN_MASK                      (0x400000U)
#define TSI_MODE_S_SEN_SHIFT                     (22U)
/*! S_SEN - S_SEN
 *  0b0..Sensitivity boost off.
 *  0b1..Sensitivity boost on.
 */
#define TSI_MODE_S_SEN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_SEN_SHIFT)) & TSI_MODE_S_SEN_MASK)

#define TSI_MODE_S_XDN_MASK                      (0x70000000U)
#define TSI_MODE_S_XDN_SHIFT                     (28U)
/*! S_XDN - S_XDN
 *  0b000..1/16.
 *  0b001..1/8.
 *  0b010..1/4.
 *  0b011..1/2.
 *  0b100..NA.
 *  0b101..NA.
 *  0b110..NA.
 *  0b111..NA.
 */
#define TSI_MODE_S_XDN(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_MODE_S_XDN_SHIFT)) & TSI_MODE_S_XDN_MASK)
/*! @} */

/*! @name MUL0 - TSI MUTUAL-CAP Register 0 */
/*! @{ */

#define TSI_MUL0_M_SEL_RX_MASK                   (0x7U)
#define TSI_MUL0_M_SEL_RX_SHIFT                  (0U)
/*! M_SEL_RX - M_SEL_RX
 *  0b000..select channel 6 as rx6.
 *  0b001..select channel 7 as rx7.
 *  0b010..select channel 8 as rx8.
 *  0b011..select channel 9 as rx9.
 *  0b100..select channel 10 as rx10.
 *  0b101..select channel 11 as rx11.
 *  0b110..NA.
 *  0b111..NA.
 */
#define TSI_MUL0_M_SEL_RX(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_SEL_RX_SHIFT)) & TSI_MUL0_M_SEL_RX_MASK)

#define TSI_MUL0_M_SEL_TX_MASK                   (0x70U)
#define TSI_MUL0_M_SEL_TX_SHIFT                  (4U)
/*! M_SEL_TX - M_SEL_TX
 *  0b000..select channel 0 as tx0.
 *  0b001..select channel 1 as tx1.
 *  0b010..select channel 2 as tx2.
 *  0b011..select channel 3 as tx3.
 *  0b100..select channel 4 as tx4.
 *  0b101..select channel 5 as tx5.
 *  0b110..NA.
 *  0b111..NA.
 */
#define TSI_MUL0_M_SEL_TX(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_SEL_TX_SHIFT)) & TSI_MUL0_M_SEL_TX_MASK)

#define TSI_MUL0_M_SEN_RES_MASK                  (0xF00U)
#define TSI_MUL0_M_SEN_RES_SHIFT                 (8U)
/*! M_SEN_RES - M_SEN_RES
 *  0b0000..2.5k.
 *  0b0001..5k.
 *  0b0010..7.5k.
 *  0b0011..10k.
 *  0b0100..12.5k.
 *  0b0101..15k.
 *  0b0110..17.5k.
 *  0b0111..20k.
 *  0b1000..22.5k.
 *  0b1001..25k.
 *  0b1010..27.5k.
 *  0b1011..30k.
 *  0b1100..32.5k.
 *  0b1101..35k.
 *  0b1110..37.5k.
 *  0b1111..40k.
 */
#define TSI_MUL0_M_SEN_RES(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_SEN_RES_SHIFT)) & TSI_MUL0_M_SEN_RES_MASK)

#define TSI_MUL0_M_PRE_RES_MASK                  (0xE000U)
#define TSI_MUL0_M_PRE_RES_SHIFT                 (13U)
/*! M_PRE_RES - M_PRE_RES
 *  0b000..1k.
 *  0b001..2k.
 *  0b010..3k.
 *  0b011..4k.
 *  0b100..5k.
 *  0b101..6k.
 *  0b110..7k.
 *  0b111..8k.
 */
#define TSI_MUL0_M_PRE_RES(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_PRE_RES_SHIFT)) & TSI_MUL0_M_PRE_RES_MASK)

#define TSI_MUL0_M_TX_USED_MASK                  (0x3F0000U)
#define TSI_MUL0_M_TX_USED_SHIFT                 (16U)
/*! M_TX_USED - M_TX_USED */
#define TSI_MUL0_M_TX_USED(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_TX_USED_SHIFT)) & TSI_MUL0_M_TX_USED_MASK)

#define TSI_MUL0_M_PRE_CURRENT_MASK              (0xE0000000U)
#define TSI_MUL0_M_PRE_CURRENT_SHIFT             (29U)
/*! M_PRE_CURRENT - M_PRE_CURRENT
 *  0b000..1uA.
 *  0b001..2uA.
 *  0b010..3uA.
 *  0b011..4uA.
 *  0b100..5uA.
 *  0b101..6uA.
 *  0b110..7uA.
 *  0b111..8uA.
 */
#define TSI_MUL0_M_PRE_CURRENT(x)                (((uint32_t)(((uint32_t)(x)) << TSI_MUL0_M_PRE_CURRENT_SHIFT)) & TSI_MUL0_M_PRE_CURRENT_MASK)
/*! @} */

/*! @name MUL1 - TSI MUTUAL-CAP register 1 */
/*! @{ */

#define TSI_MUL1_M_NMIR_CTRL_MASK                (0x1U)
#define TSI_MUL1_M_NMIR_CTRL_SHIFT               (0U)
/*! M_NMIR_CTRL - M_NMIR_CTRL
 *  0b0..Enable NMOS mirror.
 *  0b1..Disable NMOS mirror.
 */
#define TSI_MUL1_M_NMIR_CTRL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_NMIR_CTRL_SHIFT)) & TSI_MUL1_M_NMIR_CTRL_MASK)

#define TSI_MUL1_M_NMIRROR_MASK                  (0x6U)
#define TSI_MUL1_M_NMIRROR_SHIFT                 (1U)
/*! M_NMIRROR - M_NMIRROR
 *  0b00..m=1.
 *  0b01..m=2.
 *  0b10..m=3.
 *  0b11..m=4.
 */
#define TSI_MUL1_M_NMIRROR(x)                    (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_NMIRROR_SHIFT)) & TSI_MUL1_M_NMIRROR_MASK)

#define TSI_MUL1_M_PMIRRORR_MASK                 (0x18U)
#define TSI_MUL1_M_PMIRRORR_SHIFT                (3U)
/*! M_PMIRRORR - M_PMIRRORR
 *  0b00..m=1.
 *  0b01..m=2.
 *  0b10..m=3.
 *  0b11..m=4.
 */
#define TSI_MUL1_M_PMIRRORR(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_PMIRRORR_SHIFT)) & TSI_MUL1_M_PMIRRORR_MASK)

#define TSI_MUL1_M_PMIRRORL_MASK                 (0xE0U)
#define TSI_MUL1_M_PMIRRORL_SHIFT                (5U)
/*! M_PMIRRORL - M_PMIRRORL
 *  0b000..m=4.
 *  0b001..m=8.
 *  0b010..m=12.
 *  0b011..m=16.
 *  0b100..m=20.
 *  0b101..m=24.
 *  0b110..m=28.
 *  0b111..m=32.
 */
#define TSI_MUL1_M_PMIRRORL(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_PMIRRORL_SHIFT)) & TSI_MUL1_M_PMIRRORL_MASK)

#define TSI_MUL1_M_TRIM2_MASK                    (0xFF00U)
#define TSI_MUL1_M_TRIM2_SHIFT                   (8U)
/*! M_TRIM2 - M_TRIM2 */
#define TSI_MUL1_M_TRIM2(x)                      (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_TRIM2_SHIFT)) & TSI_MUL1_M_TRIM2_MASK)

#define TSI_MUL1_M_VPRE_CHOOSE_MASK              (0x10000U)
#define TSI_MUL1_M_VPRE_CHOOSE_SHIFT             (16U)
/*! M_VPRE_CHOOSE - M_VPRE_CHOOSE
 *  0b0..Internal 1.2V voltage.
 *  0b1..1.2V PMC output.
 */
#define TSI_MUL1_M_VPRE_CHOOSE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_VPRE_CHOOSE_SHIFT)) & TSI_MUL1_M_VPRE_CHOOSE_MASK)

#define TSI_MUL1_M_MODE_MASK                     (0x40000U)
#define TSI_MUL1_M_MODE_SHIFT                    (18U)
/*! M_MODE - M_MODE
 *  0b0..-5V~+5V.
 *  0b1..0V~+5V.
 */
#define TSI_MUL1_M_MODE(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_MODE_SHIFT)) & TSI_MUL1_M_MODE_MASK)

#define TSI_MUL1_M_SEN_BOOST_MASK                (0xF80000U)
#define TSI_MUL1_M_SEN_BOOST_SHIFT               (19U)
/*! M_SEN_BOOST - M_SEN_BOOST
 *  0b00000..0u.
 *  0b00001..2u.
 *  0b00010..4u.
 *  0b00011..6u.
 *  0b00100..8u.
 *  0b00101..10u.
 *  0b00110..12u.
 *  0b00111..14u
 *  0b01000..16u.
 *  0b01001..18u.
 *  0b01010..20u.
 *  0b01011..22u.
 *  0b01100..24u.
 *  0b01101..26u.
 *  0b01110..28u.
 *  0b01111..30u.
 *  0b10000..32u.
 *  0b10001..34u.
 *  0b10010..36u.
 *  0b10011..38u.
 *  0b10100..40u.
 *  0b10101..42u.
 *  0b10110..44u.
 *  0b10111..46u.
 *  0b11000..48u.
 *  0b11001..50u.
 *  0b11010..52u.
 *  0b11011..54u.
 *  0b11100..56u.
 *  0b11101..58u.
 *  0b11110..60u.
 *  0b11111..62u.
 */
#define TSI_MUL1_M_SEN_BOOST(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_MUL1_M_SEN_BOOST_SHIFT)) & TSI_MUL1_M_SEN_BOOST_MASK)
/*! @} */

/*! @name SINC - TSI SINC filter register */
/*! @{ */

#define TSI_SINC_SSC_CONTROL_OUT_MASK            (0x1U)
#define TSI_SINC_SSC_CONTROL_OUT_SHIFT           (0U)
/*! SSC_CONTROL_OUT - SSC_CONTROL_OUT
 *  0b0..SSC output value is 0.
 *  0b1..SSC output value is 1.
 */
#define TSI_SINC_SSC_CONTROL_OUT(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SSC_CONTROL_OUT_SHIFT)) & TSI_SINC_SSC_CONTROL_OUT_MASK)

#define TSI_SINC_SINC_VALID_MASK                 (0x2U)
#define TSI_SINC_SINC_VALID_SHIFT                (1U)
/*! SINC_VALID - SINC_VALID
 *  0b0..SINC filter is disabled.
 *  0b1..SINC filter is enabled.
 */
#define TSI_SINC_SINC_VALID(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_VALID_SHIFT)) & TSI_SINC_SINC_VALID_MASK)

#define TSI_SINC_SINC_OVERFLOW_FLAG_MASK         (0x4U)
#define TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT        (2U)
/*! SINC_OVERFLOW_FLAG - SINC_OVERFLOW_FLAG
 *  0b0..The counter result has no overflow occurrence in the last scan process.
 *  0b1..The counter result has an overflow occurrence in the last scan process.
 */
#define TSI_SINC_SINC_OVERFLOW_FLAG(x)           (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SINC_OVERFLOW_FLAG_SHIFT)) & TSI_SINC_SINC_OVERFLOW_FLAG_MASK)

#define TSI_SINC_SWITCH_ENABLE_MASK              (0x8U)
#define TSI_SINC_SWITCH_ENABLE_SHIFT             (3U)
/*! SWITCH_ENABLE - SWITCH_ENABLE
 *  0b0..SSC function is disabled.
 *  0b1..SSC function is enabled.
 */
#define TSI_SINC_SWITCH_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SINC_SWITCH_ENABLE_SHIFT)) & TSI_SINC_SWITCH_ENABLE_MASK)

#define TSI_SINC_DECIMATION_MASK                 (0x1F0000U)
#define TSI_SINC_DECIMATION_SHIFT                (16U)
/*! DECIMATION - DECIMATION
 *  0b00000..The TSI_DATA[TSICNT] bits is the counter value of 1 scan period.
 *  0b00001..The TSI_DATA[TSICNT] bits is the counter value of 2 scan periods.
 *  0b00010..The TSI_DATA[TSICNT] bits is the counter value of 3 scan periods.
 *  0b00011..The TSI_DATA[TSICNT] bits is the counter value of 4 scan periods.
 *  0b00100..The TSI_DATA[TSICNT] bits is the counter value of 5 scan periods.
 *  0b00101..The TSI_DATA[TSICNT] bits is the counter value of 6 scan periods.
 *  0b00110..The TSI_DATA[TSICNT] bits is the counter value of 7 scan periods.
 *  0b00111..The TSI_DATA[TSICNT] bits is the counter value of 8 scan periods.
 *  0b01000..The TSI_DATA[TSICNT] bits is the counter value of 9 scan periods.
 *  0b01001..The TSI_DATA[TSICNT] bits is the counter value of 10 scan periods.
 *  0b01010..The TSI_DATA[TSICNT] bits is the counter value of 11 scan periods.
 *  0b01011..The TSI_DATA[TSICNT] bits is the counter value of 12 scan periods.
 *  0b01100..The TSI_DATA[TSICNT] bits is the counter value of 13 scan periods.
 *  0b01101..The TSI_DATA[TSICNT] bits is the counter value of 14 scan periods.
 *  0b01110..The TSI_DATA[TSICNT] bits is the counter value of 15 scan periods.
 *  0b01111..The TSI_DATA[TSICNT] bits is the counter value of 16 scan periods.
 *  0b10000..The TSI_DATA[TSICNT] bits is the counter value of 17 scan periods.
 *  0b10001..The TSI_DATA[TSICNT] bits is the counter value of 18 scan periods.
 *  0b10010..The TSI_DATA[TSICNT] bits is the counter value of 19 scan periods.
 *  0b10011..The TSI_DATA[TSICNT] bits is the counter value of 20 scan periods.
 *  0b10100..The TSI_DATA[TSICNT] bits is the counter value of 21 scan periods.
 *  0b10101..The TSI_DATA[TSICNT] bits is the counter value of 22 scan periods.
 *  0b10110..The TSI_DATA[TSICNT] bits is the counter value of 23 scan periods.
 *  0b10111..The TSI_DATA[TSICNT] bits is the counter value of 24 scan periods.
 *  0b11000..The TSI_DATA[TSICNT] bits is the counter value of 25 scan periods.
 *  0b11001..The TSI_DATA[TSICNT] bits is the counter value of 26 scan periods.
 *  0b11010..The TSI_DATA[TSICNT] bits is the counter value of 27 scan periods.
 *  0b11011..The TSI_DATA[TSICNT] bits is the counter value of 28 scan periods.
 *  0b11100..The TSI_DATA[TSICNT] bits is the counter value of 29 scan periods.
 *  0b11101..The TSI_DATA[TSICNT] bits is the counter value of 30 scan periods.
 *  0b11110..The TSI_DATA[TSICNT] bits is the counter value of 31 scan periods.
 *  0b11111..The TSI_DATA[TSICNT] bits is the counter value of 32 scan periods.
 */
#define TSI_SINC_DECIMATION(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SINC_DECIMATION_SHIFT)) & TSI_SINC_DECIMATION_MASK)

#define TSI_SINC_ORDER_MASK                      (0x200000U)
#define TSI_SINC_ORDER_SHIFT                     (21U)
/*! ORDER - ORDER
 *  0b0..Using 1 order SINC filter.
 *  0b1..Using 2 order SINC filter.
 */
#define TSI_SINC_ORDER(x)                        (((uint32_t)(((uint32_t)(x)) << TSI_SINC_ORDER_SHIFT)) & TSI_SINC_ORDER_MASK)

#define TSI_SINC_CUTOFF_MASK                     (0xF000000U)
#define TSI_SINC_CUTOFF_SHIFT                    (24U)
/*! CUTOFF - CUTOFF
 *  0b0000..div=1.
 *  0b0001..div=2.
 *  0b0010..div=4.
 *  0b0011..div=8.
 *  0b0100..div=16.
 *  0b0101..div=32.
 *  0b0110..div=64.
 *  0b0111..div=128.
 *  0b1000..NC.
 *  0b1001..NC.
 *  0b1010..NC.
 *  0b1011..NC.
 *  0b1100..NC.
 *  0b1101..NC
 *  0b1110..NC.
 *  0b1111..NC.
 */
#define TSI_SINC_CUTOFF(x)                       (((uint32_t)(((uint32_t)(x)) << TSI_SINC_CUTOFF_SHIFT)) & TSI_SINC_CUTOFF_MASK)
/*! @} */

/*! @name SSC0 - TSI SSC register 0 */
/*! @{ */

#define TSI_SSC0_SSC_PRESCALE_NUM_MASK           (0xFFU)
#define TSI_SSC0_SSC_PRESCALE_NUM_SHIFT          (0U)
/*! SSC_PRESCALE_NUM - SSC_PRESCALE_NUM
 *  0b00000000..div1
 *  0b00000001..div2
 *  0b00000011..div4
 *  0b00000111..div8
 *  0b00001111..div16
 *  0b00011111..div32
 *  0b00111111..div64
 *  0b01111111..div128
 *  0b11111111..div256
 */
#define TSI_SSC0_SSC_PRESCALE_NUM(x)             (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_PRESCALE_NUM_SHIFT)) & TSI_SSC0_SSC_PRESCALE_NUM_MASK)

#define TSI_SSC0_BASE_NOCHARGE_NUM_MASK          (0xF0000U)
#define TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT         (16U)
/*! BASE_NOCHARGE_NUM - BASE_NOCHARGE_NUM
 *  0b0000..The SSC output bit 1's basic period will be 1 clock cycle of system clock.
 *  0b0001..The SSC output bit 1's basic period will be 2 clock cycles of system clock.
 *  0b0010..The SSC output bit 1's basic period will be 3 clock cycles of system clock.
 *  0b0011..The SSC output bit 1's basic period will be 4 clock cycles of system clock.
 *  0b0100..The SSC output bit 1's basic period will be 5 clock cycles of system clock.
 *  0b0101..The SSC output bit 1's basic period will be 6 clock cycles of system clock.
 *  0b0110..The SSC output bit 1's basic period will be 7 clock cycles of system clock.
 *  0b0111..The SSC output bit 1's basic period will be 8 clock cycles of system clock.
 *  0b1000..The SSC output bit 1's basic period will be 9 clock cycles of system clock.
 *  0b1001..The SSC output bit 1's basic period will be 10 clock cycles of system clock.
 *  0b1010..The SSC output bit 1's basic period will be 11 clock cycles of system clock.
 *  0b1011..The SSC output bit 1's basic period will be 12 clock cycles of system clock.
 *  0b1100..The SSC output bit 1's basic period will be 13 clock cycles of system clock.
 *  0b1101..The SSC output bit 1's basic period will be 14 clock cycles of system clock.
 *  0b1110..The SSC output bit 1's basic period will be 15 clock cycles of system clock.
 *  0b1111..The SSC output bit 1's basic period will be 16 clock cycles of system clock.
 */
#define TSI_SSC0_BASE_NOCHARGE_NUM(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_BASE_NOCHARGE_NUM_SHIFT)) & TSI_SSC0_BASE_NOCHARGE_NUM_MASK)

#define TSI_SSC0_CHARGE_NUM_MASK                 (0xF00000U)
#define TSI_SSC0_CHARGE_NUM_SHIFT                (20U)
/*! CHARGE_NUM - CHARGE_NUM
 *  0b0000..The SSC output bit 0's period will be 1 clock cycle of system clock.
 *  0b0001..The SSC output bit 0's period will be 2 clock cycles of system clock.
 *  0b0010..The SSC output bit 0's period will be 3 clock cycles of system clock.
 *  0b0011..The SSC output bit 0's period will be 4 clock cycles of system clock.
 *  0b0100..The SSC output bit 0's period will be 5 clock cycles of system clock.
 *  0b0101..The SSC output bit 0's period will be 6 clock cycles of system clock.
 *  0b0110..The SSC output bit 0's period will be 7 clock cycles of system clock.
 *  0b0111..The SSC output bit 0's period will be 8 clock cycles of system clock.
 *  0b1000..The SSC output bit 0's period will be 9 clock cycles of system clock.
 *  0b1001..The SSC output bit 0's period will be 10 clock cycles of system clock.
 *  0b1010..The SSC output bit 0's period will be 11 clock cycles of system clock.
 *  0b1011..The SSC output bit 0's period will be 12 clock cycles of system clock.
 *  0b1100..The SSC output bit 0's period will be 13 clock cycles of system clock.
 *  0b1101..The SSC output bit 0's period will be 14 clock cycles of system clock.
 *  0b1110..The SSC output bit 0's period will be 15 clock cycles of system clock.
 *  0b1111..The SSC output bit 0's period will be 16 clock cycles of system clock.
 */
#define TSI_SSC0_CHARGE_NUM(x)                   (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_CHARGE_NUM_SHIFT)) & TSI_SSC0_CHARGE_NUM_MASK)

#define TSI_SSC0_SSC_CONTROL_REVERSE_MASK        (0x1000000U)
#define TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT       (24U)
/*! SSC_CONTROL_REVERSE - SSC_CONTROL_REVERSE
 *  0b0..Keep the polarity of the SSC output bit.
 *  0b1..Reverse the polarity of the SSC output bit.
 */
#define TSI_SSC0_SSC_CONTROL_REVERSE(x)          (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_CONTROL_REVERSE_SHIFT)) & TSI_SSC0_SSC_CONTROL_REVERSE_MASK)

#define TSI_SSC0_SSC_MODE_MASK                   (0x6000000U)
#define TSI_SSC0_SSC_MODE_SHIFT                  (25U)
/*! SSC_MODE - SSC_MODE
 *  0b00..Using PRBS method generating SSC output bit.
 *  0b01..Using up-down counter generating SSC output bit.
 *  0b10..SSC function is disabled.
 *  0b11..NC.
 */
#define TSI_SSC0_SSC_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_SSC_MODE_SHIFT)) & TSI_SSC0_SSC_MODE_MASK)

#define TSI_SSC0_PRBS_OUTSEL_MASK                (0xF0000000U)
#define TSI_SSC0_PRBS_OUTSEL_SHIFT               (28U)
/*! PRBS_OUTSEL - PRBS_OUTSEL
 *  0b0000..NC.
 *  0b0001..NC.
 *  0b0010..The length of the PRBS is 2.
 *  0b0011..The length of the PRBS is 3.
 *  0b0100..The length of the PRBS is 4.
 *  0b0101..The length of the PRBS is 5.
 *  0b0110..The length of the PRBS is 6.
 *  0b0111..The length of the PRBS is 7.
 *  0b1000..The length of the PRBS is 8.
 *  0b1001..The length of the PRBS is 9.
 *  0b1010..The length of the PRBS is 10.
 *  0b1011..The length of the PRBS is 11.
 *  0b1100..The length of the PRBS is 12.
 *  0b1101..The length of the PRBS is 13.
 *  0b1110..The length of the PRBS is 14.
 *  0b1111..The length of the PRBS is 15.
 */
#define TSI_SSC0_PRBS_OUTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << TSI_SSC0_PRBS_OUTSEL_SHIFT)) & TSI_SSC0_PRBS_OUTSEL_MASK)
/*! @} */

/*! @name SSC1 - TSI SSC register 1 */
/*! @{ */

#define TSI_SSC1_PRBS_SEED_LO_MASK               (0xFFU)
#define TSI_SSC1_PRBS_SEED_LO_SHIFT              (0U)
/*! PRBS_SEED_LO - PRBS_SEED_LO */
#define TSI_SSC1_PRBS_SEED_LO(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_LO_SHIFT)) & TSI_SSC1_PRBS_SEED_LO_MASK)

#define TSI_SSC1_PRBS_SEED_HI_MASK               (0xFF00U)
#define TSI_SSC1_PRBS_SEED_HI_SHIFT              (8U)
/*! PRBS_SEED_HI - PRBS_SEED_HI */
#define TSI_SSC1_PRBS_SEED_HI(x)                 (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_SEED_HI_SHIFT)) & TSI_SSC1_PRBS_SEED_HI_MASK)

#define TSI_SSC1_PRBS_WEIGHT_LO_MASK             (0xFF0000U)
#define TSI_SSC1_PRBS_WEIGHT_LO_SHIFT            (16U)
/*! PRBS_WEIGHT_LO - PRBS_WEIGHT_LO */
#define TSI_SSC1_PRBS_WEIGHT_LO(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_LO_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_LO_MASK)

#define TSI_SSC1_PRBS_WEIGHT_HI_MASK             (0xFF000000U)
#define TSI_SSC1_PRBS_WEIGHT_HI_SHIFT            (24U)
/*! PRBS_WEIGHT_HI - PRBS_WEIGHT_HI */
#define TSI_SSC1_PRBS_WEIGHT_HI(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC1_PRBS_WEIGHT_HI_SHIFT)) & TSI_SSC1_PRBS_WEIGHT_HI_MASK)
/*! @} */

/*! @name SSC2 - TSI SSC register 2 */
/*! @{ */

#define TSI_SSC2_MOVE_REPEAT_NUM_MASK            (0x1FU)
#define TSI_SSC2_MOVE_REPEAT_NUM_SHIFT           (0U)
/*! MOVE_REPEAT_NUM - MOVE_REPEAT_NUM
 *  0b00000..The up_down counter will be updated for every sample-charge cycle.
 *  0b00001..The up_down counter will be updated for every 2 sample-charge cycles.
 *  0b00010..The up_down counter will be updated for every 3 sample-charge cycles.
 *  0b00011..The up_down counter will be updated for every 4 sample-charge cycles.
 *  0b00100..The up_down counter will be updated for every 5 sample-charge cycles.
 *  0b00101..The up_down counter will be updated for every 6 sample-charge cycles.
 *  0b00110..The up_down counter will be updated for every 7 sample-charge cycles.
 */
#define TSI_SSC2_MOVE_REPEAT_NUM(x)              (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_REPEAT_NUM_SHIFT)) & TSI_SSC2_MOVE_REPEAT_NUM_MASK)

#define TSI_SSC2_MOVE_STEPS_NUM_MASK             (0x700U)
#define TSI_SSC2_MOVE_STEPS_NUM_SHIFT            (8U)
/*! MOVE_STEPS_NUM - MOVE_STEPS_NUM
 *  0b000..The added value for up-down counter is 0.
 *  0b001..The added value for up-down counter is 1.
 *  0b010..The added value for up-down counter is 2.
 *  0b011..The added value for up-down counter is 3.
 *  0b100..The added value for up-down counter is 4.
 *  0b101..The added value for up-down counter is 5.
 *  0b110..The added value for up-down counter is 6.
 *  0b111..The added value for up-down counter is 7.
 */
#define TSI_SSC2_MOVE_STEPS_NUM(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_STEPS_NUM_SHIFT)) & TSI_SSC2_MOVE_STEPS_NUM_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MAX_MASK          (0x3F0000U)
#define TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT         (16U)
/*! MOVE_NOCHARGE_MAX - MOVE_NOCHARGE_MAX */
#define TSI_SSC2_MOVE_NOCHARGE_MAX(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MAX_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MAX_MASK)

#define TSI_SSC2_MOVE_NOCHARGE_MIN_MASK          (0xF0000000U)
#define TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT         (28U)
/*! MOVE_NOCHARGE_MIN - MOVE_NOCHARGE_MIN
 *  0b0000..The SSC output bit 1's min period will be (1 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycle of divided system clock.
 *  0b0001..The SSC output bit 1's min period will be (2 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0010..The SSC output bit 1's min period will be (3 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0011..The SSC output bit 1's min period will be (4 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0100..The SSC output bit 1's min period will be (5 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0101..The SSC output bit 1's min period will be (6 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0110..The SSC output bit 1's min period will be (7 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b0111..The SSC output bit 1's min period will be (8 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1000..The SSC output bit 1's min period will be (9 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1001..The SSC output bit 1's min period will be (10 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1010..The SSC output bit 1's min period will be (11 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1011..The SSC output bit 1's min period will be (12 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1100..The SSC output bit 1's min period will be (13 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1101..The SSC output bit 1's min period will be (14 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1110..The SSC output bit 1's min period will be (15 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 *  0b1111..The SSC output bit 1's min period will be (16 + TSI_SSC0[BASE_ NOCHARGE_NUM]) clock cycles of divided system clock.
 */
#define TSI_SSC2_MOVE_NOCHARGE_MIN(x)            (((uint32_t)(((uint32_t)(x)) << TSI_SSC2_MOVE_NOCHARGE_MIN_SHIFT)) & TSI_SSC2_MOVE_NOCHARGE_MIN_MASK)
/*! @} */

/*! @name SHIELD - TSI shield register */
/*! @{ */

#define TSI_SHIELD_SHIELD_SEL0_MASK              (0x1U)
#define TSI_SHIELD_SHIELD_SEL0_SHIFT             (0U)
/*! SHIELD_SEL0 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL0(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL0_SHIFT)) & TSI_SHIELD_SHIELD_SEL0_MASK)

#define TSI_SHIELD_SHIELD_SEL1_MASK              (0x2U)
#define TSI_SHIELD_SHIELD_SEL1_SHIFT             (1U)
/*! SHIELD_SEL1 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL1(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL1_SHIFT)) & TSI_SHIELD_SHIELD_SEL1_MASK)

#define TSI_SHIELD_SHIELD_SEL2_MASK              (0x4U)
#define TSI_SHIELD_SHIELD_SEL2_SHIFT             (2U)
/*! SHIELD_SEL2 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL2(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL2_SHIFT)) & TSI_SHIELD_SHIELD_SEL2_MASK)

#define TSI_SHIELD_SHIELD_SEL3_MASK              (0x8U)
#define TSI_SHIELD_SHIELD_SEL3_SHIFT             (3U)
/*! SHIELD_SEL3 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL3(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL3_SHIFT)) & TSI_SHIELD_SHIELD_SEL3_MASK)

#define TSI_SHIELD_SHIELD_SEL4_MASK              (0x10U)
#define TSI_SHIELD_SHIELD_SEL4_SHIFT             (4U)
/*! SHIELD_SEL4 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL4(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL4_SHIFT)) & TSI_SHIELD_SHIELD_SEL4_MASK)

#define TSI_SHIELD_SHIELD_SEL5_MASK              (0x20U)
#define TSI_SHIELD_SHIELD_SEL5_SHIFT             (5U)
/*! SHIELD_SEL5 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL5(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL5_SHIFT)) & TSI_SHIELD_SHIELD_SEL5_MASK)

#define TSI_SHIELD_SHIELD_SEL6_MASK              (0x40U)
#define TSI_SHIELD_SHIELD_SEL6_SHIFT             (6U)
/*! SHIELD_SEL6 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL6(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL6_SHIFT)) & TSI_SHIELD_SHIELD_SEL6_MASK)

#define TSI_SHIELD_SHIELD_SEL7_MASK              (0x80U)
#define TSI_SHIELD_SHIELD_SEL7_SHIFT             (7U)
/*! SHIELD_SEL7 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL7(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL7_SHIFT)) & TSI_SHIELD_SHIELD_SEL7_MASK)

#define TSI_SHIELD_SHIELD_SEL8_MASK              (0x100U)
#define TSI_SHIELD_SHIELD_SEL8_SHIFT             (8U)
/*! SHIELD_SEL8 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL8(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL8_SHIFT)) & TSI_SHIELD_SHIELD_SEL8_MASK)

#define TSI_SHIELD_SHIELD_SEL9_MASK              (0x200U)
#define TSI_SHIELD_SHIELD_SEL9_SHIFT             (9U)
/*! SHIELD_SEL9 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL9(x)                (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL9_SHIFT)) & TSI_SHIELD_SHIELD_SEL9_MASK)

#define TSI_SHIELD_SHIELD_SEL10_MASK             (0x400U)
#define TSI_SHIELD_SHIELD_SEL10_SHIFT            (10U)
/*! SHIELD_SEL10 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL10(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL10_SHIFT)) & TSI_SHIELD_SHIELD_SEL10_MASK)

#define TSI_SHIELD_SHIELD_SEL11_MASK             (0x800U)
#define TSI_SHIELD_SHIELD_SEL11_SHIFT            (11U)
/*! SHIELD_SEL11 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL11(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL11_SHIFT)) & TSI_SHIELD_SHIELD_SEL11_MASK)

#define TSI_SHIELD_SHIELD_SEL12_MASK             (0x1000U)
#define TSI_SHIELD_SHIELD_SEL12_SHIFT            (12U)
/*! SHIELD_SEL12 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL12(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL12_SHIFT)) & TSI_SHIELD_SHIELD_SEL12_MASK)

#define TSI_SHIELD_SHIELD_SEL13_MASK             (0x2000U)
#define TSI_SHIELD_SHIELD_SEL13_SHIFT            (13U)
/*! SHIELD_SEL13 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL13(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL13_SHIFT)) & TSI_SHIELD_SHIELD_SEL13_MASK)

#define TSI_SHIELD_SHIELD_SEL14_MASK             (0x4000U)
#define TSI_SHIELD_SHIELD_SEL14_SHIFT            (14U)
/*! SHIELD_SEL14 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL14(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL14_SHIFT)) & TSI_SHIELD_SHIELD_SEL14_MASK)

#define TSI_SHIELD_SHIELD_SEL15_MASK             (0x8000U)
#define TSI_SHIELD_SHIELD_SEL15_SHIFT            (15U)
/*! SHIELD_SEL15 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL15(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL15_SHIFT)) & TSI_SHIELD_SHIELD_SEL15_MASK)

#define TSI_SHIELD_SHIELD_SEL16_MASK             (0x10000U)
#define TSI_SHIELD_SHIELD_SEL16_SHIFT            (16U)
/*! SHIELD_SEL16 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL16(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL16_SHIFT)) & TSI_SHIELD_SHIELD_SEL16_MASK)

#define TSI_SHIELD_SHIELD_SEL17_MASK             (0x20000U)
#define TSI_SHIELD_SHIELD_SEL17_SHIFT            (17U)
/*! SHIELD_SEL17 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL17(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL17_SHIFT)) & TSI_SHIELD_SHIELD_SEL17_MASK)

#define TSI_SHIELD_SHIELD_SEL18_MASK             (0x40000U)
#define TSI_SHIELD_SHIELD_SEL18_SHIFT            (18U)
/*! SHIELD_SEL18 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL18(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL18_SHIFT)) & TSI_SHIELD_SHIELD_SEL18_MASK)

#define TSI_SHIELD_SHIELD_SEL19_MASK             (0x80000U)
#define TSI_SHIELD_SHIELD_SEL19_SHIFT            (19U)
/*! SHIELD_SEL19 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL19(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL19_SHIFT)) & TSI_SHIELD_SHIELD_SEL19_MASK)

#define TSI_SHIELD_SHIELD_SEL20_MASK             (0x100000U)
#define TSI_SHIELD_SHIELD_SEL20_SHIFT            (20U)
/*! SHIELD_SEL20 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL20(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL20_SHIFT)) & TSI_SHIELD_SHIELD_SEL20_MASK)

#define TSI_SHIELD_SHIELD_SEL21_MASK             (0x200000U)
#define TSI_SHIELD_SHIELD_SEL21_SHIFT            (21U)
/*! SHIELD_SEL21 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL21(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL21_SHIFT)) & TSI_SHIELD_SHIELD_SEL21_MASK)

#define TSI_SHIELD_SHIELD_SEL22_MASK             (0x400000U)
#define TSI_SHIELD_SHIELD_SEL22_SHIFT            (22U)
/*! SHIELD_SEL22 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL22(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL22_SHIFT)) & TSI_SHIELD_SHIELD_SEL22_MASK)

#define TSI_SHIELD_SHIELD_SEL23_MASK             (0x800000U)
#define TSI_SHIELD_SHIELD_SEL23_SHIFT            (23U)
/*! SHIELD_SEL23 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL23(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL23_SHIFT)) & TSI_SHIELD_SHIELD_SEL23_MASK)

#define TSI_SHIELD_SHIELD_SEL24_MASK             (0x1000000U)
#define TSI_SHIELD_SHIELD_SEL24_SHIFT            (24U)
/*! SHIELD_SEL24 - Selects shield channels.
 *  0b0..The channel is not configured as shield channel.
 *  0b1..The channel is configured as shield channel.
 */
#define TSI_SHIELD_SHIELD_SEL24(x)               (((uint32_t)(((uint32_t)(x)) << TSI_SHIELD_SHIELD_SEL24_SHIFT)) & TSI_SHIELD_SHIELD_SEL24_MASK)
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


#endif  /* PERI_TSI_H_ */

