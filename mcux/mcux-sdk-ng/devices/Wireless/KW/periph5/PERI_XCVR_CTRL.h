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
**         CMSIS Peripheral Access Layer for XCVR_CTRL
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
 * @file XCVR_CTRL.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for XCVR_CTRL
 *
 * CMSIS Peripheral Access Layer for XCVR_CTRL
 */

#if !defined(XCVR_CTRL_H_)
#define XCVR_CTRL_H_                             /**< Symbol preventing repeated inclusion */

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
   -- XCVR_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_CTRL_Peripheral_Access_Layer XCVR_CTRL Peripheral Access Layer
 * @{
 */

/** XCVR_CTRL - Register Layout Typedef */
typedef struct {
  __IO uint32_t XCVR_CTRL;                         /**< TRANSCEIVER CONTROL, offset: 0x0 */
  __IO uint32_t XCVR_STATUS;                       /**< TRANSCEIVER STATUS, offset: 0x4 */
  __IO uint32_t BLE_ARB_CTRL;                      /**< BLE ARBITRATION CONTROL, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t OVERWRITE_VER;                     /**< OVERWRITE VERSION, offset: 0x10 */
  __IO uint32_t DMA_CTRL;                          /**< TRANSCEIVER DMA CONTROL, offset: 0x14 */
  __I  uint32_t DMA_DATA;                          /**< TRANSCEIVER DMA DATA, offset: 0x18 */
  __IO uint32_t DTEST_CTRL;                        /**< DIGITAL TEST MUX CONTROL, offset: 0x1C */
  __IO uint32_t PACKET_RAM_CTRL;                   /**< PACKET RAM CONTROL, offset: 0x20 */
  __IO uint32_t FAD_CTRL;                          /**< FAD CONTROL, offset: 0x24 */
  __IO uint32_t LPPS_CTRL;                         /**< LOW POWER PREAMBLE SEARCH CONTROL, offset: 0x28 */
  __IO uint32_t RF_NOT_ALLOWED_CTRL;               /**< WIFI COEXISTENCE CONTROL, offset: 0x2C */
  __IO uint32_t CRCW_CFG;                          /**< CRC/WHITENER CONTROL, offset: 0x30 */
  __I  uint32_t CRC_EC_MASK;                       /**< CRC ERROR CORRECTION MASK, offset: 0x34 */
  __I  uint32_t CRC_RES_OUT;                       /**< CRC RESULT, offset: 0x38 */
} XCVR_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- XCVR_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XCVR_CTRL_Register_Masks XCVR_CTRL Register Masks
 * @{
 */

/*! @name XCVR_CTRL - TRANSCEIVER CONTROL */
/*! @{ */

#define XCVR_CTRL_XCVR_CTRL_PROTOCOL_MASK        (0xFU)
#define XCVR_CTRL_XCVR_CTRL_PROTOCOL_SHIFT       (0U)
/*! PROTOCOL - Radio Protocol Selection
 *  0b0000..BLE
 *  0b0001..BLE in MBAN
 *  0b0010..BLE overlap MBAN
 *  0b0011..ANT
 *  0b0100..Zigbee
 *  0b0101..802.15.4j
 *  0b0110..128 Channel FSK
 *  0b0111..128 Channel GFSK
 *  0b1000..Generic FSK
 *  0b1001..MSK
 */
#define XCVR_CTRL_XCVR_CTRL_PROTOCOL(x)          (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_PROTOCOL_SHIFT)) & XCVR_CTRL_XCVR_CTRL_PROTOCOL_MASK)

#define XCVR_CTRL_XCVR_CTRL_TGT_PWR_SRC_MASK     (0x70U)
#define XCVR_CTRL_XCVR_CTRL_TGT_PWR_SRC_SHIFT    (4U)
/*! TGT_PWR_SRC - Target Power Source */
#define XCVR_CTRL_XCVR_CTRL_TGT_PWR_SRC(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_TGT_PWR_SRC_SHIFT)) & XCVR_CTRL_XCVR_CTRL_TGT_PWR_SRC_MASK)

#define XCVR_CTRL_XCVR_CTRL_REF_CLK_FREQ_MASK    (0x300U)
#define XCVR_CTRL_XCVR_CTRL_REF_CLK_FREQ_SHIFT   (8U)
/*! REF_CLK_FREQ - Radio Reference Clock Frequency
 *  0b00..32 MHz
 *  0b01..26 MHz
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define XCVR_CTRL_XCVR_CTRL_REF_CLK_FREQ(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_REF_CLK_FREQ_SHIFT)) & XCVR_CTRL_XCVR_CTRL_REF_CLK_FREQ_MASK)

#define XCVR_CTRL_XCVR_CTRL_SOC_RF_OSC_CLK_GATE_EN_MASK (0x800U)
#define XCVR_CTRL_XCVR_CTRL_SOC_RF_OSC_CLK_GATE_EN_SHIFT (11U)
/*! SOC_RF_OSC_CLK_GATE_EN - SOC_RF_OSC_CLK_GATE_EN */
#define XCVR_CTRL_XCVR_CTRL_SOC_RF_OSC_CLK_GATE_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_SOC_RF_OSC_CLK_GATE_EN_SHIFT)) & XCVR_CTRL_XCVR_CTRL_SOC_RF_OSC_CLK_GATE_EN_MASK)

#define XCVR_CTRL_XCVR_CTRL_DEMOD_SEL_MASK       (0x3000U)
#define XCVR_CTRL_XCVR_CTRL_DEMOD_SEL_SHIFT      (12U)
/*! DEMOD_SEL - Demodulator Selector
 *  0b00..No demodulator selected
 *  0b01..Use Freescale Constant Envelope demodulator
 *  0b10..Use Legacy 802.15.4 demodulator
 *  0b11..Reserved
 */
#define XCVR_CTRL_XCVR_CTRL_DEMOD_SEL(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_DEMOD_SEL_SHIFT)) & XCVR_CTRL_XCVR_CTRL_DEMOD_SEL_MASK)

#define XCVR_CTRL_XCVR_CTRL_RADIO0_IRQ_SEL_MASK  (0x70000U)
#define XCVR_CTRL_XCVR_CTRL_RADIO0_IRQ_SEL_SHIFT (16U)
/*! RADIO0_IRQ_SEL - RADIO0_IRQ_SEL
 *  0b000..Assign Radio #0 Interrupt to BLE
 *  0b001..Assign Radio #0 Interrupt to 802.15.4
 *  0b010..Assign Radio #0 Interrupt to ANT
 *  0b011..Assign Radio #0 Interrupt to GENERIC_FSK
 *  0b100..Radio #0 Interrupt unassigned
 *  0b101..Radio #0 Interrupt unassigned
 *  0b110..Radio #0 Interrupt unassigned
 *  0b111..Radio #0 Interrupt unassigned
 */
#define XCVR_CTRL_XCVR_CTRL_RADIO0_IRQ_SEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_RADIO0_IRQ_SEL_SHIFT)) & XCVR_CTRL_XCVR_CTRL_RADIO0_IRQ_SEL_MASK)

#define XCVR_CTRL_XCVR_CTRL_RADIO1_IRQ_SEL_MASK  (0x700000U)
#define XCVR_CTRL_XCVR_CTRL_RADIO1_IRQ_SEL_SHIFT (20U)
/*! RADIO1_IRQ_SEL - RADIO1_IRQ_SEL
 *  0b000..Assign Radio #1 Interrupt to BLE
 *  0b001..Assign Radio #1 Interrupt to 802.15.4
 *  0b010..Assign Radio #1 Interrupt to ANT
 *  0b011..Assign Radio #1 Interrupt to GENERIC_FSK
 *  0b100..Radio #1 Interrupt unassigned
 *  0b101..Radio #1 Interrupt unassigned
 *  0b110..Radio #1 Interrupt unassigned
 *  0b111..Radio #1 Interrupt unassigned
 */
#define XCVR_CTRL_XCVR_CTRL_RADIO1_IRQ_SEL(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_CTRL_RADIO1_IRQ_SEL_SHIFT)) & XCVR_CTRL_XCVR_CTRL_RADIO1_IRQ_SEL_MASK)
/*! @} */

/*! @name XCVR_STATUS - TRANSCEIVER STATUS */
/*! @{ */

#define XCVR_CTRL_XCVR_STATUS_TSM_COUNT_MASK     (0xFFU)
#define XCVR_CTRL_XCVR_STATUS_TSM_COUNT_SHIFT    (0U)
/*! TSM_COUNT - TSM_COUNT */
#define XCVR_CTRL_XCVR_STATUS_TSM_COUNT(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_TSM_COUNT_SHIFT)) & XCVR_CTRL_XCVR_STATUS_TSM_COUNT_MASK)

#define XCVR_CTRL_XCVR_STATUS_PLL_SEQ_STATE_MASK (0xF00U)
#define XCVR_CTRL_XCVR_STATUS_PLL_SEQ_STATE_SHIFT (8U)
/*! PLL_SEQ_STATE - PLL Sequence State
 *  0b0000..PLL OFF
 *  0b0010..CTUNE
 *  0b0011..CTUNE_SETTLE
 *  0b0110..HPMCAL1
 *  0b1000..HPMCAL1_SETTLE
 *  0b1010..HPMCAL2
 *  0b1100..HPMCAL2_SETTLE
 *  0b1111..PLLREADY
 */
#define XCVR_CTRL_XCVR_STATUS_PLL_SEQ_STATE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_PLL_SEQ_STATE_SHIFT)) & XCVR_CTRL_XCVR_STATUS_PLL_SEQ_STATE_MASK)

#define XCVR_CTRL_XCVR_STATUS_RX_MODE_MASK       (0x1000U)
#define XCVR_CTRL_XCVR_STATUS_RX_MODE_SHIFT      (12U)
/*! RX_MODE - Receive Mode */
#define XCVR_CTRL_XCVR_STATUS_RX_MODE(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_RX_MODE_SHIFT)) & XCVR_CTRL_XCVR_STATUS_RX_MODE_MASK)

#define XCVR_CTRL_XCVR_STATUS_TX_MODE_MASK       (0x2000U)
#define XCVR_CTRL_XCVR_STATUS_TX_MODE_SHIFT      (13U)
/*! TX_MODE - Transmit Mode */
#define XCVR_CTRL_XCVR_STATUS_TX_MODE(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_TX_MODE_SHIFT)) & XCVR_CTRL_XCVR_STATUS_TX_MODE_MASK)

#define XCVR_CTRL_XCVR_STATUS_BTLE_SYSCLK_REQ_MASK (0x10000U)
#define XCVR_CTRL_XCVR_STATUS_BTLE_SYSCLK_REQ_SHIFT (16U)
/*! BTLE_SYSCLK_REQ - BTLE System Clock Request */
#define XCVR_CTRL_XCVR_STATUS_BTLE_SYSCLK_REQ(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_BTLE_SYSCLK_REQ_SHIFT)) & XCVR_CTRL_XCVR_STATUS_BTLE_SYSCLK_REQ_MASK)

#define XCVR_CTRL_XCVR_STATUS_RIF_LL_ACTIVE_MASK (0x20000U)
#define XCVR_CTRL_XCVR_STATUS_RIF_LL_ACTIVE_SHIFT (17U)
/*! RIF_LL_ACTIVE - Link Layer Active Indication */
#define XCVR_CTRL_XCVR_STATUS_RIF_LL_ACTIVE(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_RIF_LL_ACTIVE_SHIFT)) & XCVR_CTRL_XCVR_STATUS_RIF_LL_ACTIVE_MASK)

#define XCVR_CTRL_XCVR_STATUS_XTAL_READY_MASK    (0x40000U)
#define XCVR_CTRL_XCVR_STATUS_XTAL_READY_SHIFT   (18U)
/*! XTAL_READY - RF Osciallator Xtal Ready
 *  0b0..Indicates that the RF Oscillator is disabled or has not completed its warmup.
 *  0b1..Indicates that the RF Oscillator has completed its warmup count and is ready for use.
 */
#define XCVR_CTRL_XCVR_STATUS_XTAL_READY(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_XTAL_READY_SHIFT)) & XCVR_CTRL_XCVR_STATUS_XTAL_READY_MASK)

#define XCVR_CTRL_XCVR_STATUS_SOC_USING_RF_OSC_CLK_MASK (0x80000U)
#define XCVR_CTRL_XCVR_STATUS_SOC_USING_RF_OSC_CLK_SHIFT (19U)
/*! SOC_USING_RF_OSC_CLK - SOC Using RF Clock Indication */
#define XCVR_CTRL_XCVR_STATUS_SOC_USING_RF_OSC_CLK(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_SOC_USING_RF_OSC_CLK_SHIFT)) & XCVR_CTRL_XCVR_STATUS_SOC_USING_RF_OSC_CLK_MASK)

#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ0_MASK      (0x1000000U)
#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ0_SHIFT     (24U)
/*! TSM_IRQ0 - TSM Interrupt #0
 *  0b0..TSM Interrupt #0 is not asserted.
 *  0b1..TSM Interrupt #0 is asserted. Write '1' to this bit to clear it.
 */
#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ0(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_TSM_IRQ0_SHIFT)) & XCVR_CTRL_XCVR_STATUS_TSM_IRQ0_MASK)

#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ1_MASK      (0x2000000U)
#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ1_SHIFT     (25U)
/*! TSM_IRQ1 - TSM Interrupt #1
 *  0b0..TSM Interrupt #1 is not asserted.
 *  0b1..TSM Interrupt #1 is asserted. Write '1' to this bit to clear it.
 */
#define XCVR_CTRL_XCVR_STATUS_TSM_IRQ1(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_XCVR_STATUS_TSM_IRQ1_SHIFT)) & XCVR_CTRL_XCVR_STATUS_TSM_IRQ1_MASK)
/*! @} */

/*! @name BLE_ARB_CTRL - BLE ARBITRATION CONTROL */
/*! @{ */

#define XCVR_CTRL_BLE_ARB_CTRL_BLE_RELINQUISH_MASK (0x1U)
#define XCVR_CTRL_BLE_ARB_CTRL_BLE_RELINQUISH_SHIFT (0U)
/*! BLE_RELINQUISH - BLE Relinquish Control */
#define XCVR_CTRL_BLE_ARB_CTRL_BLE_RELINQUISH(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_BLE_ARB_CTRL_BLE_RELINQUISH_SHIFT)) & XCVR_CTRL_BLE_ARB_CTRL_BLE_RELINQUISH_MASK)

#define XCVR_CTRL_BLE_ARB_CTRL_XCVR_BUSY_MASK    (0x2U)
#define XCVR_CTRL_BLE_ARB_CTRL_XCVR_BUSY_SHIFT   (1U)
/*! XCVR_BUSY - Transceiver Busy Status Bit
 *  0b0..RF Channel in available (TSM is idle)
 *  0b1..RF Channel in use (TSM is busy)
 */
#define XCVR_CTRL_BLE_ARB_CTRL_XCVR_BUSY(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_BLE_ARB_CTRL_XCVR_BUSY_SHIFT)) & XCVR_CTRL_BLE_ARB_CTRL_XCVR_BUSY_MASK)
/*! @} */

/*! @name OVERWRITE_VER - OVERWRITE VERSION */
/*! @{ */

#define XCVR_CTRL_OVERWRITE_VER_OVERWRITE_VER_MASK (0xFFU)
#define XCVR_CTRL_OVERWRITE_VER_OVERWRITE_VER_SHIFT (0U)
/*! OVERWRITE_VER - Overwrite Version Number. */
#define XCVR_CTRL_OVERWRITE_VER_OVERWRITE_VER(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_OVERWRITE_VER_OVERWRITE_VER_SHIFT)) & XCVR_CTRL_OVERWRITE_VER_OVERWRITE_VER_MASK)
/*! @} */

/*! @name DMA_CTRL - TRANSCEIVER DMA CONTROL */
/*! @{ */

#define XCVR_CTRL_DMA_CTRL_DMA_PAGE_MASK         (0xFU)
#define XCVR_CTRL_DMA_CTRL_DMA_PAGE_SHIFT        (0U)
/*! DMA_PAGE - Transceiver DMA Page Selector
 *  0b0000..DMA Idle
 *  0b0001..RX_DIG I and Q
 *  0b0010..RX_DIG I Only
 *  0b0011..RX_DIG Q Only
 *  0b0100..RAW ADC I and Q
 *  0b0101..RAW ADC I Only
 *  0b0110..RAW ADC Q only
 *  0b0111..DC Estimator I and Q
 *  0b1000..DC Estimator I Only
 *  0b1001..DC Estimator Q only
 *  0b1010..RX_DIG Phase Output
 *  0b1011..Demodulator Hard Decision
 *  0b1100..Demodulator Soft Decision
 *  0b1101..Demodulator Data Output
 *  0b1110..Demodulator CFO Phase Output
 *  0b1111..Reserved
 */
#define XCVR_CTRL_DMA_CTRL_DMA_PAGE(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_DMA_PAGE_SHIFT)) & XCVR_CTRL_DMA_CTRL_DMA_PAGE_MASK)

#define XCVR_CTRL_DMA_CTRL_SINGLE_REQ_MODE_MASK  (0x10U)
#define XCVR_CTRL_DMA_CTRL_SINGLE_REQ_MODE_SHIFT (4U)
/*! SINGLE_REQ_MODE - DMA Single Request Mode
 *  0b0..Disable Single Request Mode. The transceiver will assert ipd_req_radio_rx whenever it has a new sample ready for transfer.
 *  0b1..Enable Single Request Mode. A single initial request by the transceiver will transfer the entire DMA block of data
 */
#define XCVR_CTRL_DMA_CTRL_SINGLE_REQ_MODE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_SINGLE_REQ_MODE_SHIFT)) & XCVR_CTRL_DMA_CTRL_SINGLE_REQ_MODE_MASK)

#define XCVR_CTRL_DMA_CTRL_BYPASS_DMA_SYNC_MASK  (0x20U)
#define XCVR_CTRL_DMA_CTRL_BYPASS_DMA_SYNC_SHIFT (5U)
/*! BYPASS_DMA_SYNC - Bypass External DMA Synchronization
 *  0b0..Don't Bypass External Synchronization. Use this setting if SINGLE_REQ_MODE=1.
 *  0b1..Bypass External Synchronization. This setting is mandatory if SINGLE_REQ_MODE=0.
 */
#define XCVR_CTRL_DMA_CTRL_BYPASS_DMA_SYNC(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_BYPASS_DMA_SYNC_SHIFT)) & XCVR_CTRL_DMA_CTRL_BYPASS_DMA_SYNC_MASK)

#define XCVR_CTRL_DMA_CTRL_DMA_TRIGGERRED_MASK   (0x40U)
#define XCVR_CTRL_DMA_CTRL_DMA_TRIGGERRED_SHIFT  (6U)
/*! DMA_TRIGGERRED - DMA TRIGGERRED */
#define XCVR_CTRL_DMA_CTRL_DMA_TRIGGERRED(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_DMA_TRIGGERRED_SHIFT)) & XCVR_CTRL_DMA_CTRL_DMA_TRIGGERRED_MASK)

#define XCVR_CTRL_DMA_CTRL_DMA_TIMED_OUT_MASK    (0x80U)
#define XCVR_CTRL_DMA_CTRL_DMA_TIMED_OUT_SHIFT   (7U)
/*! DMA_TIMED_OUT - DMA Transfer Timed Out
 *  0b0..A DMA timeout has not occurred
 *  0b1..A DMA timeout has occurred in Single Request Mode since the last time this bit was cleared
 */
#define XCVR_CTRL_DMA_CTRL_DMA_TIMED_OUT(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_DMA_TIMED_OUT_SHIFT)) & XCVR_CTRL_DMA_CTRL_DMA_TIMED_OUT_MASK)

#define XCVR_CTRL_DMA_CTRL_DMA_TIMEOUT_MASK      (0xF00U)
#define XCVR_CTRL_DMA_CTRL_DMA_TIMEOUT_SHIFT     (8U)
/*! DMA_TIMEOUT - DMA Timeout */
#define XCVR_CTRL_DMA_CTRL_DMA_TIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_CTRL_DMA_TIMEOUT_SHIFT)) & XCVR_CTRL_DMA_CTRL_DMA_TIMEOUT_MASK)
/*! @} */

/*! @name DMA_DATA - TRANSCEIVER DMA DATA */
/*! @{ */

#define XCVR_CTRL_DMA_DATA_DMA_DATA_MASK         (0xFFFFFFFFU)
#define XCVR_CTRL_DMA_DATA_DMA_DATA_SHIFT        (0U)
/*! DMA_DATA - DMA Data Register */
#define XCVR_CTRL_DMA_DATA_DMA_DATA(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DMA_DATA_DMA_DATA_SHIFT)) & XCVR_CTRL_DMA_DATA_DMA_DATA_MASK)
/*! @} */

/*! @name DTEST_CTRL - DIGITAL TEST MUX CONTROL */
/*! @{ */

#define XCVR_CTRL_DTEST_CTRL_DTEST_PAGE_MASK     (0x3FU)
#define XCVR_CTRL_DTEST_CTRL_DTEST_PAGE_SHIFT    (0U)
/*! DTEST_PAGE - DTEST Page Selector */
#define XCVR_CTRL_DTEST_CTRL_DTEST_PAGE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_DTEST_PAGE_SHIFT)) & XCVR_CTRL_DTEST_CTRL_DTEST_PAGE_MASK)

#define XCVR_CTRL_DTEST_CTRL_DTEST_EN_MASK       (0x80U)
#define XCVR_CTRL_DTEST_CTRL_DTEST_EN_SHIFT      (7U)
/*! DTEST_EN - DTEST Enable
 *  0b0..Disables DTEST. The DTEST pins assume their mission function.
 *  0b1..Enables DTEST. The contents of the selected page (DTEST_PAGE) will appear on the DTEST output pins.
 */
#define XCVR_CTRL_DTEST_CTRL_DTEST_EN(x)         (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_DTEST_EN_SHIFT)) & XCVR_CTRL_DTEST_CTRL_DTEST_EN_MASK)

#define XCVR_CTRL_DTEST_CTRL_GPIO0_OVLAY_PIN_MASK (0xF00U)
#define XCVR_CTRL_DTEST_CTRL_GPIO0_OVLAY_PIN_SHIFT (8U)
/*! GPIO0_OVLAY_PIN - GPIO 0 Overlay Pin */
#define XCVR_CTRL_DTEST_CTRL_GPIO0_OVLAY_PIN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_GPIO0_OVLAY_PIN_SHIFT)) & XCVR_CTRL_DTEST_CTRL_GPIO0_OVLAY_PIN_MASK)

#define XCVR_CTRL_DTEST_CTRL_GPIO1_OVLAY_PIN_MASK (0xF000U)
#define XCVR_CTRL_DTEST_CTRL_GPIO1_OVLAY_PIN_SHIFT (12U)
/*! GPIO1_OVLAY_PIN - GPIO 1 Overlay Pin */
#define XCVR_CTRL_DTEST_CTRL_GPIO1_OVLAY_PIN(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_GPIO1_OVLAY_PIN_SHIFT)) & XCVR_CTRL_DTEST_CTRL_GPIO1_OVLAY_PIN_MASK)

#define XCVR_CTRL_DTEST_CTRL_TSM_GPIO_OVLAY_MASK (0x30000U)
#define XCVR_CTRL_DTEST_CTRL_TSM_GPIO_OVLAY_SHIFT (16U)
/*! TSM_GPIO_OVLAY - TSM GPIO Overlay Pin Control
 *  0b00..there is no overlay, and the DTEST Page Table dictates the node that appears on each DTEST pin.
 *  0b01..the register GPIO0_OVLAY_PIN[3:0] selects the DTEST pin on which GPIO0_TRIG_EN will appear.
 *  0b10..the register GPIO1_OVLAY_PIN[3:0] selects the DTEST pin on which GPIO1_TRIG_EN will appear.
 *  0b11..the register GPIO0_OVLAY_PIN[3:0] selects the DTEST pin on which GPIO0_TRIG_EN will appear, and the
 *        register GPIO1_OVLAY_PIN[3:0] selects the DTEST pin on which GPIO1_TRIG_EN will appear.
 */
#define XCVR_CTRL_DTEST_CTRL_TSM_GPIO_OVLAY(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_TSM_GPIO_OVLAY_SHIFT)) & XCVR_CTRL_DTEST_CTRL_TSM_GPIO_OVLAY_MASK)

#define XCVR_CTRL_DTEST_CTRL_DTEST_SHFT_MASK     (0x7000000U)
#define XCVR_CTRL_DTEST_CTRL_DTEST_SHFT_SHIFT    (24U)
/*! DTEST_SHFT - DTEST Shift Control */
#define XCVR_CTRL_DTEST_CTRL_DTEST_SHFT(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_DTEST_SHFT_SHIFT)) & XCVR_CTRL_DTEST_CTRL_DTEST_SHFT_MASK)

#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_I_MASK     (0x10000000U)
#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_I_SHIFT    (28U)
/*! RAW_MODE_I - DTEST Raw Mode Enable for I Channel */
#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_I(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_RAW_MODE_I_SHIFT)) & XCVR_CTRL_DTEST_CTRL_RAW_MODE_I_MASK)

#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_Q_MASK     (0x20000000U)
#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_Q_SHIFT    (29U)
/*! RAW_MODE_Q - DTEST Raw Mode Enable for Q Channel */
#define XCVR_CTRL_DTEST_CTRL_RAW_MODE_Q(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_DTEST_CTRL_RAW_MODE_Q_SHIFT)) & XCVR_CTRL_DTEST_CTRL_RAW_MODE_Q_MASK)
/*! @} */

/*! @name PACKET_RAM_CTRL - PACKET RAM CONTROL */
/*! @{ */

#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_PAGE_MASK  (0xFU)
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_PAGE_SHIFT (0U)
/*! DBG_PAGE - Packet RAM Debug Page Selector
 *  0b0000..Packet RAM Debug Mode Idle
 *  0b0001..RX_DIG I and Q
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..RAW ADC I and Q
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..DC Estimator I and Q
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..RX_DIG Phase Output
 *  0b1011..Demodulator Hard Decision
 *  0b1100..Demodulator Soft Decision
 *  0b1101..Demodulator Data Output
 *  0b1110..Demodulator CFO Phase Output
 *  0b1111..Reserved
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_PAGE(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_DBG_PAGE_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_DBG_PAGE_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_PB_PROTECT_MASK (0x10U)
#define XCVR_CTRL_PACKET_RAM_CTRL_PB_PROTECT_SHIFT (4U)
/*! PB_PROTECT - Packet Buffer Protect
 *  0b0..Incoming received packets overwrite Packet Buffer RX contents (default)
 *  0b1..Incoming received packets are blocked from overwriting Packet Buffer RX contents
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_PB_PROTECT(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_PB_PROTECT_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_PB_PROTECT_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_XCVR_RAM_ALLOW_MASK (0x20U)
#define XCVR_CTRL_PACKET_RAM_CTRL_XCVR_RAM_ALLOW_SHIFT (5U)
/*! XCVR_RAM_ALLOW - Allow Packet RAM Transceiver Access
 *  0b0..Protocol Engines, and associated IPS busses, have exclusive access to Packet RAM (mission mode)
 *  0b1..Transceiver-space access to Packet RAM, including Packet RAM debug mode, are allowed
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_XCVR_RAM_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_XCVR_RAM_ALLOW_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_XCVR_RAM_ALLOW_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_ALL_PROTOCOLS_ALLOW_MASK (0x40U)
#define XCVR_CTRL_PACKET_RAM_CTRL_ALL_PROTOCOLS_ALLOW_SHIFT (6U)
/*! ALL_PROTOCOLS_ALLOW - Allow IPS bus access to Packet RAM for any protocol at any time.
 *  0b0..IPS bus access to Packet RAM is restricted to the protocol engine currently selected by XCVR_CTRL[PROTOCOL].
 *  0b1..All IPS bus access to Packet RAM permitted, regardless of XCVR_CTRL[PROTOCOL] setting
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_ALL_PROTOCOLS_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_ALL_PROTOCOLS_ALLOW_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_ALL_PROTOCOLS_ALLOW_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_TRIGGERRED_MASK (0x80U)
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_TRIGGERRED_SHIFT (7U)
/*! DBG_TRIGGERRED - DBG_TRIGGERRED */
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_TRIGGERRED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_DBG_TRIGGERRED_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_DBG_TRIGGERRED_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_RAM_FULL_MASK (0x300U)
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_RAM_FULL_SHIFT (8U)
/*! DBG_RAM_FULL - DBG_RAM_FULL[1:0]
 *  0b00..Neither Packet RAM0 nor RAM1 is full
 *  0bx1..Packet RAM0 has been filled to capacity.
 *  0b1x..Packet RAM1 has been filled to capacity.
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_DBG_RAM_FULL(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_DBG_RAM_FULL_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_DBG_RAM_FULL_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_EN_MASK (0x400U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_EN_SHIFT (10U)
/*! RAM0_CLK_ON_OVRD_EN - Override control for RAM0 Clock Gate Enable
 *  0b0..Normal operation.
 *  0b1..Use the state of RAM0_CLK_ON_OVRD to override the RAM0 Clock Gate Enable.
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_EN_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_EN_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_MASK (0x800U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_SHIFT (11U)
/*! RAM0_CLK_ON_OVRD - Override value for RAM0 Clock Gate Enable */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CLK_ON_OVRD_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_EN_MASK (0x1000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_EN_SHIFT (12U)
/*! RAM1_CLK_ON_OVRD_EN - Override control for RAM1 Clock Gate Enable
 *  0b0..Normal operation.
 *  0b1..Use the state of RAM1_CLK_ON_OVRD to override the RAM1 Clock Gate Enable.
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_EN_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_EN_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_MASK (0x2000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_SHIFT (13U)
/*! RAM1_CLK_ON_OVRD - Override value for RAM1 Clock Gate Enable */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CLK_ON_OVRD_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_EN_MASK (0x4000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_EN_SHIFT (14U)
/*! RAM0_CE_ON_OVRD_EN - Override control for RAM0 CE (Chip Enable)
 *  0b0..Normal operation.
 *  0b1..Use the state of RAM0_CE_ON_OVRD to override the RAM0 CE.
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_EN_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_EN_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_MASK (0x8000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_SHIFT (15U)
/*! RAM0_CE_ON_OVRD - Override value for RAM0 CE (Chip Enable) */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM0_CE_ON_OVRD_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_EN_MASK (0x10000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_EN_SHIFT (16U)
/*! RAM1_CE_ON_OVRD_EN - Override control for RAM1 CE (Chip Enable)
 *  0b0..Normal operation.
 *  0b1..Use the state of RAM1_CE_ON_OVRD to override the RAM1 CE.
 */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_EN(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_EN_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_EN_MASK)

#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_MASK (0x20000U)
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_SHIFT (17U)
/*! RAM1_CE_ON_OVRD - Override value for RAM1 CE (Chip Enable) */
#define XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_SHIFT)) & XCVR_CTRL_PACKET_RAM_CTRL_RAM1_CE_ON_OVRD_MASK)
/*! @} */

/*! @name FAD_CTRL - FAD CONTROL */
/*! @{ */

#define XCVR_CTRL_FAD_CTRL_FAD_EN_MASK           (0x1U)
#define XCVR_CTRL_FAD_CTRL_FAD_EN_SHIFT          (0U)
/*! FAD_EN - Fast Antenna Diversity Enable
 *  0b0..Fast Antenna Diversity disabled
 *  0b1..Fast Antenna Diversity enabled for 802.15.4
 */
#define XCVR_CTRL_FAD_CTRL_FAD_EN(x)             (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_FAD_EN_SHIFT)) & XCVR_CTRL_FAD_CTRL_FAD_EN_MASK)

#define XCVR_CTRL_FAD_CTRL_ANTX_MASK             (0x2U)
#define XCVR_CTRL_FAD_CTRL_ANTX_SHIFT            (1U)
/*! ANTX - Antenna Selection State */
#define XCVR_CTRL_FAD_CTRL_ANTX(x)               (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_ANTX_SHIFT)) & XCVR_CTRL_FAD_CTRL_ANTX_MASK)

#define XCVR_CTRL_FAD_CTRL_ANTX_EN_MASK          (0x30U)
#define XCVR_CTRL_FAD_CTRL_ANTX_EN_SHIFT         (4U)
/*! ANTX_EN - FAD Antenna Controls Enable
 *  0b00..all disabled (held low)
 *  0b01..only RX/TX_SWITCH enabled
 *  0b10..only ANT_A/B enabled
 *  0b11..all enabled
 */
#define XCVR_CTRL_FAD_CTRL_ANTX_EN(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_ANTX_EN_SHIFT)) & XCVR_CTRL_FAD_CTRL_ANTX_EN_MASK)

#define XCVR_CTRL_FAD_CTRL_ANTX_HZ_MASK          (0x40U)
#define XCVR_CTRL_FAD_CTRL_ANTX_HZ_SHIFT         (6U)
/*! ANTX_HZ - FAD PAD Tristate Control
 *  0b0..ANT_A, ANT_B, RX_SWITCH and TX_SWITCH are actively driven outputs.
 *  0b1..Antenna controls high impedance- Set ANT_A, ANT_B, RX_SWITCH and TX_SWITCH in high impedance.
 */
#define XCVR_CTRL_FAD_CTRL_ANTX_HZ(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_ANTX_HZ_SHIFT)) & XCVR_CTRL_FAD_CTRL_ANTX_HZ_MASK)

#define XCVR_CTRL_FAD_CTRL_ANTX_CTRLMODE_MASK    (0x80U)
#define XCVR_CTRL_FAD_CTRL_ANTX_CTRLMODE_SHIFT   (7U)
/*! ANTX_CTRLMODE - Antenna Diversity Control Mode */
#define XCVR_CTRL_FAD_CTRL_ANTX_CTRLMODE(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_ANTX_CTRLMODE_SHIFT)) & XCVR_CTRL_FAD_CTRL_ANTX_CTRLMODE_MASK)

#define XCVR_CTRL_FAD_CTRL_ANTX_POL_MASK         (0xF00U)
#define XCVR_CTRL_FAD_CTRL_ANTX_POL_SHIFT        (8U)
/*! ANTX_POL - FAD Antenna Controls Polarity */
#define XCVR_CTRL_FAD_CTRL_ANTX_POL(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_ANTX_POL_SHIFT)) & XCVR_CTRL_FAD_CTRL_ANTX_POL_MASK)

#define XCVR_CTRL_FAD_CTRL_FAD_NOT_GPIO_MASK     (0xF000U)
#define XCVR_CTRL_FAD_CTRL_FAD_NOT_GPIO_SHIFT    (12U)
/*! FAD_NOT_GPIO - FAD versus GPIO Mode Selector */
#define XCVR_CTRL_FAD_CTRL_FAD_NOT_GPIO(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_FAD_CTRL_FAD_NOT_GPIO_SHIFT)) & XCVR_CTRL_FAD_CTRL_FAD_NOT_GPIO_MASK)
/*! @} */

/*! @name LPPS_CTRL - LOW POWER PREAMBLE SEARCH CONTROL */
/*! @{ */

#define XCVR_CTRL_LPPS_CTRL_LPPS_ENABLE_MASK     (0x1U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_ENABLE_SHIFT    (0U)
/*! LPPS_ENABLE - LPPS_ENABLE */
#define XCVR_CTRL_LPPS_CTRL_LPPS_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_ENABLE_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_ENABLE_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_TZA_ALLOW_MASK  (0x2U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_TZA_ALLOW_SHIFT (1U)
/*! LPPS_TZA_ALLOW - LPPS_TZA_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_TZA_ALLOW(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_TZA_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_TZA_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_BBA_ALLOW_MASK  (0x4U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_BBA_ALLOW_SHIFT (2U)
/*! LPPS_BBA_ALLOW - LPPS_BBA_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_BBA_ALLOW(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_BBA_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_BBA_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_ADC_ALLOW_MASK  (0x8U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_ADC_ALLOW_SHIFT (3U)
/*! LPPS_ADC_ALLOW - LPPS_ADC_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_ADC_ALLOW(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_ADC_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_ADC_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_ALLOW_MASK (0x10U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_ALLOW_SHIFT (4U)
/*! LPPS_DCOC_ALLOW - LPPS_DCOC_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_ALLOW(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_PDET_ALLOW_MASK (0x20U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_PDET_ALLOW_SHIFT (5U)
/*! LPPS_PDET_ALLOW - LPPS_PDET_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_PDET_ALLOW(x)   (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_PDET_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_PDET_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_ALLOW_MASK (0x40U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_ALLOW_SHIFT (6U)
/*! LPPS_SY_LO_ALLOW - LPPS_SY_LO_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_ALLOW(x)  (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_BUF_ALLOW_MASK (0x80U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_BUF_ALLOW_SHIFT (7U)
/*! LPPS_SY_LO_BUF_ALLOW - LPPS_SY_LO_BUF_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_BUF_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_BUF_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_SY_LO_BUF_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_RX_DIG_ALLOW_MASK (0x100U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_RX_DIG_ALLOW_SHIFT (8U)
/*! LPPS_RX_DIG_ALLOW - LPPS_RX_DIG_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_RX_DIG_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_RX_DIG_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_RX_DIG_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_DIG_ALLOW_MASK (0x200U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_DIG_ALLOW_SHIFT (9U)
/*! LPPS_DCOC_DIG_ALLOW - LPPS_DCOC_DIG_ALLOW */
#define XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_DIG_ALLOW(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_DIG_ALLOW_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_DCOC_DIG_ALLOW_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_START_RX_MASK   (0xFF0000U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_START_RX_SHIFT  (16U)
/*! LPPS_START_RX - LPPS Fast TSM RX Warmup "Jump-from" Point */
#define XCVR_CTRL_LPPS_CTRL_LPPS_START_RX(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_START_RX_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_START_RX_MASK)

#define XCVR_CTRL_LPPS_CTRL_LPPS_DEST_RX_MASK    (0xFF000000U)
#define XCVR_CTRL_LPPS_CTRL_LPPS_DEST_RX_SHIFT   (24U)
/*! LPPS_DEST_RX - LPPS Fast TSM RX Warmup "Jump-to" Point */
#define XCVR_CTRL_LPPS_CTRL_LPPS_DEST_RX(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_LPPS_CTRL_LPPS_DEST_RX_SHIFT)) & XCVR_CTRL_LPPS_CTRL_LPPS_DEST_RX_MASK)
/*! @} */

/*! @name RF_NOT_ALLOWED_CTRL - WIFI COEXISTENCE CONTROL */
/*! @{ */

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_TX_MASK (0x1U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_TX_SHIFT (0U)
/*! RF_NOT_ALLOWED_NO_TX - RF_NOT_ALLOWED_NO_TX
 *  0b0..Assertion on RF_NOT_ALLOWED has no effect on TX
 *  0b1..Assertion on RF_NOT_ALLOWED can abort TX
 */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_TX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_TX_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_TX_MASK)

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_RX_MASK (0x2U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_RX_SHIFT (1U)
/*! RF_NOT_ALLOWED_NO_RX - RF_NOT_ALLOWED_NO_RX
 *  0b0..Assertion on RF_NOT_ALLOWED has no effect on RX
 *  0b1..Assertion on RF_NOT_ALLOWED can abort RX
 */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_RX(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_RX_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_NO_RX_MASK)

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_ASSERTED_MASK (0x4U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_ASSERTED_SHIFT (2U)
/*! RF_NOT_ALLOWED_ASSERTED - RF_NOT_ALLOWED_ASSERTED
 *  0b0..Assertion on RF_NOT_ALLOWED has not occurred
 *  0b1..Assertion on RF_NOT_ALLOWED has occurred since the last time this bit was cleared
 */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_ASSERTED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_ASSERTED_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_ASSERTED_MASK)

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_TX_ABORT_MASK (0x8U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_TX_ABORT_SHIFT (3U)
/*! RF_NOT_ALLOWED_TX_ABORT - RF_NOT_ALLOWED_TX_ABORT
 *  0b0..A TX abort due to assertion on RF_NOT_ALLOWED has not occurred
 *  0b1..A TX abort due to assertion on RF_NOT_ALLOWED has occurred since the last time this bit was cleared
 */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_TX_ABORT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_TX_ABORT_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_TX_ABORT_MASK)

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_RX_ABORT_MASK (0x10U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_RX_ABORT_SHIFT (4U)
/*! RF_NOT_ALLOWED_RX_ABORT - RF_NOT_ALLOWED_RX_ABORT
 *  0b0..A RX abort due to assertion on RF_NOT_ALLOWED has not occurred
 *  0b1..A RX abort due to assertion on RF_NOT_ALLOWED has occurred since the last time this bit was cleared
 */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_RX_ABORT(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_RX_ABORT_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_RX_ABORT_MASK)

#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_MASK (0x20U)
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_SHIFT (5U)
/*! RF_NOT_ALLOWED - RF_NOT_ALLOWED */
#define XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED(x) (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_SHIFT)) & XCVR_CTRL_RF_NOT_ALLOWED_CTRL_RF_NOT_ALLOWED_MASK)
/*! @} */

/*! @name CRCW_CFG - CRC/WHITENER CONTROL */
/*! @{ */

#define XCVR_CTRL_CRCW_CFG_CRCW_EN_MASK          (0x1U)
#define XCVR_CTRL_CRCW_CFG_CRCW_EN_SHIFT         (0U)
/*! CRCW_EN - CRC calculation enable */
#define XCVR_CTRL_CRCW_CFG_CRCW_EN(x)            (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRCW_EN_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRCW_EN_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_ZERO_MASK         (0x2U)
#define XCVR_CTRL_CRCW_CFG_CRC_ZERO_SHIFT        (1U)
/*! CRC_ZERO - CRC zero */
#define XCVR_CTRL_CRCW_CFG_CRC_ZERO(x)           (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_ZERO_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_ZERO_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_EARLY_FAIL_MASK   (0x4U)
#define XCVR_CTRL_CRCW_CFG_CRC_EARLY_FAIL_SHIFT  (2U)
/*! CRC_EARLY_FAIL - CRC error correction fail */
#define XCVR_CTRL_CRCW_CFG_CRC_EARLY_FAIL(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_EARLY_FAIL_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_EARLY_FAIL_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_RES_OUT_VLD_MASK  (0x8U)
#define XCVR_CTRL_CRCW_CFG_CRC_RES_OUT_VLD_SHIFT (3U)
/*! CRC_RES_OUT_VLD - CRC result output valid */
#define XCVR_CTRL_CRCW_CFG_CRC_RES_OUT_VLD(x)    (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_RES_OUT_VLD_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_RES_OUT_VLD_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_EC_OFFSET_MASK    (0x7FF0000U)
#define XCVR_CTRL_CRCW_CFG_CRC_EC_OFFSET_SHIFT   (16U)
/*! CRC_EC_OFFSET - CRC error correction offset */
#define XCVR_CTRL_CRCW_CFG_CRC_EC_OFFSET(x)      (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_EC_OFFSET_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_EC_OFFSET_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_EC_DONE_MASK      (0x10000000U)
#define XCVR_CTRL_CRCW_CFG_CRC_EC_DONE_SHIFT     (28U)
/*! CRC_EC_DONE - CRC error correction done */
#define XCVR_CTRL_CRCW_CFG_CRC_EC_DONE(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_EC_DONE_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_EC_DONE_MASK)

#define XCVR_CTRL_CRCW_CFG_CRC_EC_FAIL_MASK      (0x20000000U)
#define XCVR_CTRL_CRCW_CFG_CRC_EC_FAIL_SHIFT     (29U)
/*! CRC_EC_FAIL - CRC error correction fail */
#define XCVR_CTRL_CRCW_CFG_CRC_EC_FAIL(x)        (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRCW_CFG_CRC_EC_FAIL_SHIFT)) & XCVR_CTRL_CRCW_CFG_CRC_EC_FAIL_MASK)
/*! @} */

/*! @name CRC_EC_MASK - CRC ERROR CORRECTION MASK */
/*! @{ */

#define XCVR_CTRL_CRC_EC_MASK_CRC_EC_MASK_MASK   (0xFFFFFFFFU)
#define XCVR_CTRL_CRC_EC_MASK_CRC_EC_MASK_SHIFT  (0U)
/*! CRC_EC_MASK - CRC error correction mask */
#define XCVR_CTRL_CRC_EC_MASK_CRC_EC_MASK(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRC_EC_MASK_CRC_EC_MASK_SHIFT)) & XCVR_CTRL_CRC_EC_MASK_CRC_EC_MASK_MASK)
/*! @} */

/*! @name CRC_RES_OUT - CRC RESULT */
/*! @{ */

#define XCVR_CTRL_CRC_RES_OUT_CRC_RES_OUT_MASK   (0xFFFFFFFFU)
#define XCVR_CTRL_CRC_RES_OUT_CRC_RES_OUT_SHIFT  (0U)
/*! CRC_RES_OUT - CRC result output */
#define XCVR_CTRL_CRC_RES_OUT_CRC_RES_OUT(x)     (((uint32_t)(((uint32_t)(x)) << XCVR_CTRL_CRC_RES_OUT_CRC_RES_OUT_SHIFT)) & XCVR_CTRL_CRC_RES_OUT_CRC_RES_OUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XCVR_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group XCVR_CTRL_Peripheral_Access_Layer */


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


#endif  /* XCVR_CTRL_H_ */

