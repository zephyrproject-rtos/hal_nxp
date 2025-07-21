/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCON3
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCON3.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON3
 *
 * CMSIS Peripheral Access Layer for SYSCON3
 */

#if !defined(PERI_SYSCON3_H_)
#define PERI_SYSCON3_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- SYSCON3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON3_Peripheral_Access_Layer SYSCON3 Peripheral Access Layer
 * @{
 */

/** SYSCON3 - Size of Registers Arrays */
#define SYSCON3_GDET_CTRL_2_COUNT                 1u
#define SYSCON3_TEMPDETECT_CTRL_COUNT             2u
#define SYSCON3_SWD_ACCESS_CPU_COUNT              2u

/** SYSCON3 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SEC_CLK_CTRL;                      /**< Security Clock Control, offset: 0x0 */
  __O  uint32_t SEC_CLK_CTRL_SET;                  /**< Security Clock Control Set, offset: 0x4 */
  __O  uint32_t SEC_CLK_CTRL_CLR;                  /**< Security Clock Control Clear, offset: 0x8 */
  __IO uint32_t GDET_CTRL[SYSCON3_GDET_CTRL_2_COUNT]; /**< GDET3 Control, array offset: 0xC, array step: 0x4 */
       uint8_t RESERVED_0[112];
  __O  uint32_t RXEVPULSEGEN;                      /**< Receive Event Pulse Generator, offset: 0x80 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CPU_STATUS;                        /**< CPU Status, offset: 0x8C */
       uint8_t RESERVED_2[8];
  __IO uint32_t CPU1_SVTOR;                        /**< CPU1 Secure Vector Table Offset, offset: 0x98 */
  __IO uint32_t CPU1_NSVTOR;                       /**< CPU1 Non-Secure Vector Table Offset, offset: 0x9C */
       uint8_t RESERVED_3[36];
  __I  uint32_t SILICONREV_ID;                     /**< Silicon Revision ID, offset: 0xC4 */
       uint8_t RESERVED_4[76];
  __IO uint32_t AUTOCLKGATEOVERRIDE0;              /**< Automatic Clock Gate Override, offset: 0x114 */
  __IO uint32_t SRAM_CLKGATE_CTRL;                 /**< SRAM Clock Gating Control, offset: 0x118 */
       uint8_t RESERVED_5[356];
  __IO uint32_t SENSE_AUTOGATE_EN;                 /**< VDD1_SENSE Auto Gating Enable, offset: 0x280 */
       uint8_t RESERVED_6[656];
  __IO uint32_t TEMPDETECT_CTRL[SYSCON3_TEMPDETECT_CTRL_COUNT]; /**< TEMPDETECT0 Control..TEMPDETECT1 Control, array offset: 0x514, array step: 0x4 */
  __I  uint32_t TEMPDETECT_FLAGS;                  /**< TEMPDETECT Interrupts Output, offset: 0x51C */
       uint8_t RESERVED_7[736];
  __IO uint32_t SWD_ACCESS_CPU[SYSCON3_SWD_ACCESS_CPU_COUNT]; /**< CPU0 Software Debug Access..CPU1 Software Debug Access, array offset: 0x800, array step: 0x4 */
  __IO uint32_t SWD_ACCESS_APBAP;                  /**< APB-AP Software Debug Access, offset: 0x808 */
  __IO uint32_t SWD_ACCESS_AHBAP;                  /**< AHB-AP Software Debug Access, offset: 0x80C */
  __IO uint32_t TAP_ACCESS_EN;                     /**< JTAG Test Access Port Enable for Chip-TAP, offset: 0x810 */
  __IO uint32_t DEBUG_FEATURES;                    /**< Cortex Debug Features Control, offset: 0x814 */
  __IO uint32_t DEBUG_FEATURES_DP;                 /**< Cortex Debug Features Control, offset: 0x818 */
  __IO uint32_t DEBUG_AUTH_BEACON;                 /**< Debug Authentication Beacon, offset: 0x81C */
       uint8_t RESERVED_8[832];
  __IO uint32_t GRAY_CODE_LSB;                     /**< Gray to Binary Converter - Gray Code [31:0], offset: 0xB60 */
  __IO uint32_t GRAY_CODE_MSB;                     /**< Gray to Binary Converter - Gray Code [63:32], offset: 0xB64 */
  __I  uint32_t BINARY_CODE_LSB;                   /**< Gray to Binary Converter - Binary Code [31:0], offset: 0xB68 */
  __I  uint32_t BINARY_CODE_MSB;                   /**< Gray to Binary Converter - Binary Code [63:32], offset: 0xB6C */
} SYSCON3_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON3_Register_Masks SYSCON3 Register Masks
 * @{
 */

/*! @name SEC_CLK_CTRL - Security Clock Control */
/*! @{ */

#define SYSCON3_SEC_CLK_CTRL_GDET3_REFCLK_EN_MASK (0x2U)
#define SYSCON3_SEC_CLK_CTRL_GDET3_REFCLK_EN_SHIFT (1U)
/*! GDET3_REFCLK_EN - GDET3 Reference Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON3_SEC_CLK_CTRL_GDET3_REFCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_SEC_CLK_CTRL_GDET3_REFCLK_EN_SHIFT)) & SYSCON3_SEC_CLK_CTRL_GDET3_REFCLK_EN_MASK)
/*! @} */

/*! @name SEC_CLK_CTRL_SET - Security Clock Control Set */
/*! @{ */

#define SYSCON3_SEC_CLK_CTRL_SET_GDET3_REFCLK_EN_SET_MASK (0x2U)
#define SYSCON3_SEC_CLK_CTRL_SET_GDET3_REFCLK_EN_SET_SHIFT (1U)
/*! GDET3_REFCLK_EN_SET - GDET3 Reference Clock Enable Set
 *  0b0..Has no effect
 *  0b1..Sets SEC_CLK_CTRL[GDET3_REFCLK_EN] to 1
 */
#define SYSCON3_SEC_CLK_CTRL_SET_GDET3_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SEC_CLK_CTRL_SET_GDET3_REFCLK_EN_SET_SHIFT)) & SYSCON3_SEC_CLK_CTRL_SET_GDET3_REFCLK_EN_SET_MASK)
/*! @} */

/*! @name SEC_CLK_CTRL_CLR - Security Clock Control Clear */
/*! @{ */

#define SYSCON3_SEC_CLK_CTRL_CLR_GDET3_REFCLK_EN_CLR_MASK (0x2U)
#define SYSCON3_SEC_CLK_CTRL_CLR_GDET3_REFCLK_EN_CLR_SHIFT (1U)
/*! GDET3_REFCLK_EN_CLR - GDET3 Reference Clock Enable Clear
 *  0b0..Has no effect
 *  0b1..Clears SEC_CLK_CTRL[GDET3_REFCLK_EN] to 0
 */
#define SYSCON3_SEC_CLK_CTRL_CLR_GDET3_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SEC_CLK_CTRL_CLR_GDET3_REFCLK_EN_CLR_SHIFT)) & SYSCON3_SEC_CLK_CTRL_CLR_GDET3_REFCLK_EN_CLR_MASK)
/*! @} */

/*! @name GDET_CTRL - GDET3 Control */
/*! @{ */

#define SYSCON3_GDET_CTRL_GDET_EVTCNT_CLR_MASK   (0x1U)
#define SYSCON3_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT  (0U)
/*! GDET_EVTCNT_CLR - GDET Event Counter Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SYSCON3_GDET_CTRL_GDET_EVTCNT_CLR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT)) & SYSCON3_GDET_CTRL_GDET_EVTCNT_CLR_MASK)

#define SYSCON3_GDET_CTRL_GDET_ERR_CLR_MASK      (0x2U)
#define SYSCON3_GDET_CTRL_GDET_ERR_CLR_SHIFT     (1U)
/*! GDET_ERR_CLR - GDET Error Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SYSCON3_GDET_CTRL_GDET_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_GDET_ERR_CLR_SHIFT)) & SYSCON3_GDET_CTRL_GDET_ERR_CLR_MASK)

#define SYSCON3_GDET_CTRL_GDET_ISO_SW_MASK       (0xCU)
#define SYSCON3_GDET_CTRL_GDET_ISO_SW_SHIFT      (2U)
/*! GDET_ISO_SW - GDET Isolation Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCON3_GDET_CTRL_GDET_ISO_SW(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_GDET_ISO_SW_SHIFT)) & SYSCON3_GDET_CTRL_GDET_ISO_SW_MASK)

#define SYSCON3_GDET_CTRL_EVENT_CNT_MASK         (0xFF0000U)
#define SYSCON3_GDET_CTRL_EVENT_CNT_SHIFT        (16U)
/*! EVENT_CNT - Event Count Value */
#define SYSCON3_GDET_CTRL_EVENT_CNT(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_EVENT_CNT_SHIFT)) & SYSCON3_GDET_CTRL_EVENT_CNT_MASK)

#define SYSCON3_GDET_CTRL_POS_SYNC_MASK          (0x1000000U)
#define SYSCON3_GDET_CTRL_POS_SYNC_SHIFT         (24U)
/*! POS_SYNC - Positive Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SYSCON3_GDET_CTRL_POS_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_POS_SYNC_SHIFT)) & SYSCON3_GDET_CTRL_POS_SYNC_MASK)

#define SYSCON3_GDET_CTRL_NEG_SYNC_MASK          (0x2000000U)
#define SYSCON3_GDET_CTRL_NEG_SYNC_SHIFT         (25U)
/*! NEG_SYNC - Negative Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SYSCON3_GDET_CTRL_NEG_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_NEG_SYNC_SHIFT)) & SYSCON3_GDET_CTRL_NEG_SYNC_MASK)

#define SYSCON3_GDET_CTRL_EVENT_CLR_FLAG_MASK    (0x4000000U)
#define SYSCON3_GDET_CTRL_EVENT_CLR_FLAG_SHIFT   (26U)
/*! EVENT_CLR_FLAG - Event Counter Clear
 *  0b0..Not cleared
 *  0b1..Cleared
 */
#define SYSCON3_GDET_CTRL_EVENT_CLR_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON3_GDET_CTRL_EVENT_CLR_FLAG_SHIFT)) & SYSCON3_GDET_CTRL_EVENT_CLR_FLAG_MASK)
/*! @} */

/* The count of SYSCON3_GDET_CTRL */
#define SYSCON3_GDET_CTRL_COUNT                  (1U)

/*! @name RXEVPULSEGEN - Receive Event Pulse Generator */
/*! @{ */

#define SYSCON3_RXEVPULSEGEN_RXEVPULSEGEN_MASK   (0x1U)
#define SYSCON3_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT  (0U)
/*! RXEVPULSEGEN - Receive Event Pulse Generator
 *  0b0..No effect
 *  0b1..Pulse receive event high for one cycle
 */
#define SYSCON3_RXEVPULSEGEN_RXEVPULSEGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT)) & SYSCON3_RXEVPULSEGEN_RXEVPULSEGEN_MASK)
/*! @} */

/*! @name CPU_STATUS - CPU Status */
/*! @{ */

#define SYSCON3_CPU_STATUS_CPU_WAIT_MASK         (0x1U)
#define SYSCON3_CPU_STATUS_CPU_WAIT_SHIFT        (0U)
/*! CPU_WAIT - CPU1 Stall
 *  0b0..No stall
 *  0b1..Stall
 */
#define SYSCON3_CPU_STATUS_CPU_WAIT(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON3_CPU_STATUS_CPU_WAIT_SHIFT)) & SYSCON3_CPU_STATUS_CPU_WAIT_MASK)

#define SYSCON3_CPU_STATUS_CPU_LOCKUP_MASK       (0x2U)
#define SYSCON3_CPU_STATUS_CPU_LOCKUP_SHIFT      (1U)
/*! CPU_LOCKUP - CPU1 Lockup State
 *  0b0..Not in lockup
 *  0b1..In lockup
 */
#define SYSCON3_CPU_STATUS_CPU_LOCKUP(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON3_CPU_STATUS_CPU_LOCKUP_SHIFT)) & SYSCON3_CPU_STATUS_CPU_LOCKUP_MASK)
/*! @} */

/*! @name CPU1_SVTOR - CPU1 Secure Vector Table Offset */
/*! @{ */

#define SYSCON3_CPU1_SVTOR_CPU1_SVTOR_MASK       (0x1FFFFFFU)
#define SYSCON3_CPU1_SVTOR_CPU1_SVTOR_SHIFT      (0U)
/*! CPU1_SVTOR - Secure Vector Table Offset */
#define SYSCON3_CPU1_SVTOR_CPU1_SVTOR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON3_CPU1_SVTOR_CPU1_SVTOR_SHIFT)) & SYSCON3_CPU1_SVTOR_CPU1_SVTOR_MASK)
/*! @} */

/*! @name CPU1_NSVTOR - CPU1 Non-Secure Vector Table Offset */
/*! @{ */

#define SYSCON3_CPU1_NSVTOR_CPU1_NSVTOR_MASK     (0x1FFFFFFU)
#define SYSCON3_CPU1_NSVTOR_CPU1_NSVTOR_SHIFT    (0U)
/*! CPU1_NSVTOR - Non-Secure Vector Table Offset */
#define SYSCON3_CPU1_NSVTOR_CPU1_NSVTOR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON3_CPU1_NSVTOR_CPU1_NSVTOR_SHIFT)) & SYSCON3_CPU1_NSVTOR_CPU1_NSVTOR_MASK)
/*! @} */

/*! @name SILICONREV_ID - Silicon Revision ID */
/*! @{ */

#define SYSCON3_SILICONREV_ID_MINOR_MASK         (0xFU)
#define SYSCON3_SILICONREV_ID_MINOR_SHIFT        (0U)
/*! MINOR - Silicon Revision Minor Tag */
#define SYSCON3_SILICONREV_ID_MINOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON3_SILICONREV_ID_MINOR_SHIFT)) & SYSCON3_SILICONREV_ID_MINOR_MASK)

#define SYSCON3_SILICONREV_ID_MAJOR_MASK         (0xF0000U)
#define SYSCON3_SILICONREV_ID_MAJOR_SHIFT        (16U)
/*! MAJOR - Silicon Revision Major Tag */
#define SYSCON3_SILICONREV_ID_MAJOR(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON3_SILICONREV_ID_MAJOR_SHIFT)) & SYSCON3_SILICONREV_ID_MAJOR_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE0 - Automatic Clock Gate Override */
/*! @{ */

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION18_MASK (0x1U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION18_SHIFT (0U)
/*! PARTITION18 - Partition 18
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION18(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION18_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION18_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION19_MASK (0x2U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION19_SHIFT (1U)
/*! PARTITION19 - Partition 19
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION19(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION19_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION19_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION20_MASK (0x4U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION20_SHIFT (2U)
/*! PARTITION20 - Partition 20
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION20(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION20_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION20_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION21_MASK (0x8U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION21_SHIFT (3U)
/*! PARTITION21 - Partition 21
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION21(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION21_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION21_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION22_MASK (0x10U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION22_SHIFT (4U)
/*! PARTITION22 - Partition 22
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION22(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION22_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION22_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION23_MASK (0x20U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION23_SHIFT (5U)
/*! PARTITION23 - Partition 23
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION23(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION23_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION23_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION24_MASK (0x40U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION24_SHIFT (6U)
/*! PARTITION24 - Partition 24
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION24(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION24_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION24_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION25_MASK (0x80U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION25_SHIFT (7U)
/*! PARTITION25 - Partition 25
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION25(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION25_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION25_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION26_MASK (0x100U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION26_SHIFT (8U)
/*! PARTITION26 - Partition 26
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION26(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION26_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION26_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION27_MASK (0x200U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION27_SHIFT (9U)
/*! PARTITION27 - Partition 27
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION27(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION27_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION27_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION28_MASK (0x400U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION28_SHIFT (10U)
/*! PARTITION28 - Partition 28
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION28(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION28_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION28_MASK)

#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION29_MASK (0x800U)
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION29_SHIFT (11U)
/*! PARTITION29 - Partition 29
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION29(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION29_SHIFT)) & SYSCON3_AUTOCLKGATEOVERRIDE0_PARTITION29_MASK)
/*! @} */

/*! @name SRAM_CLKGATE_CTRL - SRAM Clock Gating Control */
/*! @{ */

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION18_MASK (0x1U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION18_SHIFT (0U)
/*! PARTITION18 - Partition 18
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION18(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION18_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION18_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION19_MASK (0x2U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION19_SHIFT (1U)
/*! PARTITION19 - Partition 19
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION19(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION19_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION19_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION20_MASK (0x4U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION20_SHIFT (2U)
/*! PARTITION20 - Partition 20
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION20(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION20_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION20_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION21_MASK (0x8U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION21_SHIFT (3U)
/*! PARTITION21 - Partition 21
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION21(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION21_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION21_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION22_MASK (0x10U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION22_SHIFT (4U)
/*! PARTITION22 - Partition 22
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION22(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION22_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION22_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION23_MASK (0x20U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION23_SHIFT (5U)
/*! PARTITION23 - Partition 23
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION23(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION23_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION23_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION24_MASK (0x40U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION24_SHIFT (6U)
/*! PARTITION24 - Partition 24
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION24(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION24_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION24_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION25_MASK (0x80U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION25_SHIFT (7U)
/*! PARTITION25 - Partition 25
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION25(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION25_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION25_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION26_MASK (0x100U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION26_SHIFT (8U)
/*! PARTITION26 - Partition 26
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION26(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION26_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION26_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION27_MASK (0x200U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION27_SHIFT (9U)
/*! PARTITION27 - Partition 27
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION27(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION27_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION27_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION28_MASK (0x400U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION28_SHIFT (10U)
/*! PARTITION28 - Partition 28
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION28(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION28_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION28_MASK)

#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION29_MASK (0x800U)
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION29_SHIFT (11U)
/*! PARTITION29 - Partition 29
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON3_SRAM_CLKGATE_CTRL_PARTITION29(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_SRAM_CLKGATE_CTRL_PARTITION29_SHIFT)) & SYSCON3_SRAM_CLKGATE_CTRL_PARTITION29_MASK)
/*! @} */

/*! @name SENSE_AUTOGATE_EN - VDD1_SENSE Auto Gating Enable */
/*! @{ */

#define SYSCON3_SENSE_AUTOGATE_EN_MATRIX_EN_MASK (0x1U)
#define SYSCON3_SENSE_AUTOGATE_EN_MATRIX_EN_SHIFT (0U)
/*! MATRIX_EN - Automatic Clock Gating Enable for S-Bus
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON3_SENSE_AUTOGATE_EN_MATRIX_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_SENSE_AUTOGATE_EN_MATRIX_EN_SHIFT)) & SYSCON3_SENSE_AUTOGATE_EN_MATRIX_EN_MASK)

#define SYSCON3_SENSE_AUTOGATE_EN_BRIDGE_EN_MASK (0x2U)
#define SYSCON3_SENSE_AUTOGATE_EN_BRIDGE_EN_SHIFT (1U)
/*! BRIDGE_EN - Automatic Clock Gating Enable for AHB to APB Bridge, AIPS and AXBS
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON3_SENSE_AUTOGATE_EN_BRIDGE_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_SENSE_AUTOGATE_EN_BRIDGE_EN_SHIFT)) & SYSCON3_SENSE_AUTOGATE_EN_BRIDGE_EN_MASK)
/*! @} */

/*! @name TEMPDETECT_CTRL - TEMPDETECT0 Control..TEMPDETECT1 Control */
/*! @{ */

#define SYSCON3_TEMPDETECT_CTRL_ENABLE_MASK      (0x1U)
#define SYSCON3_TEMPDETECT_CTRL_ENABLE_SHIFT     (0U)
/*! ENABLE - TEMPDETECT1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON3_TEMPDETECT_CTRL_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_CTRL_ENABLE_SHIFT)) & SYSCON3_TEMPDETECT_CTRL_ENABLE_MASK)

#define SYSCON3_TEMPDETECT_CTRL_TEMPSEL_MASK     (0xFF0U)
#define SYSCON3_TEMPDETECT_CTRL_TEMPSEL_SHIFT    (4U)
/*! TEMPSEL - TEMPDETECT1 Temperature Select
 *  0b00000000-0b11111111..See .
 */
#define SYSCON3_TEMPDETECT_CTRL_TEMPSEL(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_CTRL_TEMPSEL_SHIFT)) & SYSCON3_TEMPDETECT_CTRL_TEMPSEL_MASK)

#define SYSCON3_TEMPDETECT_CTRL_TEMP0_HIGH_DETECT_MASK (0x2000U)
#define SYSCON3_TEMPDETECT_CTRL_TEMP0_HIGH_DETECT_SHIFT (13U)
/*! TEMP0_HIGH_DETECT - TEMPDETECT1 High Or Low Detection
 *  0b0..Below
 *  0b1..Above
 */
#define SYSCON3_TEMPDETECT_CTRL_TEMP0_HIGH_DETECT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_CTRL_TEMP0_HIGH_DETECT_SHIFT)) & SYSCON3_TEMPDETECT_CTRL_TEMP0_HIGH_DETECT_MASK)

#define SYSCON3_TEMPDETECT_CTRL_INTERRUPT_CLEAR_MASK (0x80000000U)
#define SYSCON3_TEMPDETECT_CTRL_INTERRUPT_CLEAR_SHIFT (31U)
/*! INTERRUPT_CLEAR - TEMPDETECT1 Interrupt Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SYSCON3_TEMPDETECT_CTRL_INTERRUPT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_CTRL_INTERRUPT_CLEAR_SHIFT)) & SYSCON3_TEMPDETECT_CTRL_INTERRUPT_CLEAR_MASK)
/*! @} */

/*! @name TEMPDETECT_FLAGS - TEMPDETECT Interrupts Output */
/*! @{ */

#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT0_MASK (0x1U)
#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT0_SHIFT (0U)
/*! TEMPDETECT0 - TEMPDETECT0 Interrupt
 *  0b0..No Interrupt
 *  0b1..Interrupt
 */
#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT0_SHIFT)) & SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT0_MASK)

#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT1_MASK (0x2U)
#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT1_SHIFT (1U)
/*! TEMPDETECT1 - TEMPDETECT1 Interrupt
 *  0b0..No Interrupt
 *  0b1..Interrupt
 */
#define SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT1_SHIFT)) & SYSCON3_TEMPDETECT_FLAGS_TEMPDETECT1_MASK)
/*! @} */

/*! @name SWD_ACCESS_CPU - CPU0 Software Debug Access..CPU1 Software Debug Access */
/*! @{ */

#define SYSCON3_SWD_ACCESS_CPU_SEC_CODE_MASK     (0xFFFFFFFFU)
#define SYSCON3_SWD_ACCESS_CPU_SEC_CODE_SHIFT    (0U)
/*! SEC_CODE - CPU SWD-AP: 12345678h
 *  0b00000000000000000000000000000000..CPU DAP is not allowed. Reading back register will be read as 5h
 *  0b00010010001101000101011001111000..Value to write to enable CPU SWD access. Reading back register will be read as Ah
 */
#define SYSCON3_SWD_ACCESS_CPU_SEC_CODE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON3_SWD_ACCESS_CPU_SEC_CODE_SHIFT)) & SYSCON3_SWD_ACCESS_CPU_SEC_CODE_MASK)
/*! @} */

/*! @name SWD_ACCESS_APBAP - APB-AP Software Debug Access */
/*! @{ */

#define SYSCON3_SWD_ACCESS_APBAP_SEC_CODE_MASK   (0xFFFFFFFFU)
#define SYSCON3_SWD_ACCESS_APBAP_SEC_CODE_SHIFT  (0U)
/*! SEC_CODE - APB SWD-AP: 12345678h
 *  0b00000000000000000000000000000000..APB DAP is not allowed. Reading back register will be read as 5h
 *  0b00010010001101000101011001111000..Value to write to enable APB SWD access. Reading back register will be read as Ah
 */
#define SYSCON3_SWD_ACCESS_APBAP_SEC_CODE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_SWD_ACCESS_APBAP_SEC_CODE_SHIFT)) & SYSCON3_SWD_ACCESS_APBAP_SEC_CODE_MASK)
/*! @} */

/*! @name SWD_ACCESS_AHBAP - AHB-AP Software Debug Access */
/*! @{ */

#define SYSCON3_SWD_ACCESS_AHBAP_SEC_CODE_MASK   (0xFFFFFFFFU)
#define SYSCON3_SWD_ACCESS_AHBAP_SEC_CODE_SHIFT  (0U)
/*! SEC_CODE - AHB SWD-AP: 12345678h
 *  0b00000000000000000000000000000000..AHB DAP is not allowed. Reading back register will be read as 5h
 *  0b00010010001101000101011001111000..Value to write to enable AHB SWD access. Reading back register will be read as Ah
 */
#define SYSCON3_SWD_ACCESS_AHBAP_SEC_CODE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_SWD_ACCESS_AHBAP_SEC_CODE_SHIFT)) & SYSCON3_SWD_ACCESS_AHBAP_SEC_CODE_MASK)
/*! @} */

/*! @name TAP_ACCESS_EN - JTAG Test Access Port Enable for Chip-TAP */
/*! @{ */

#define SYSCON3_TAP_ACCESS_EN_SEC_CODE_MASK      (0xFFFFFFFFU)
#define SYSCON3_TAP_ACCESS_EN_SEC_CODE_SHIFT     (0U)
/*! SEC_CODE - JTAG Test Access Port Enable: 12345678h
 *  0b00000000000000000000000000000000..JTAG TAP is not allowed. Reading back register will be read as 5h
 *  0b00010010001101000101011001111000..Value to write to enable JTAG TAP. Reading back register will be read as Ah
 */
#define SYSCON3_TAP_ACCESS_EN_SEC_CODE(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON3_TAP_ACCESS_EN_SEC_CODE_SHIFT)) & SYSCON3_TAP_ACCESS_EN_SEC_CODE_MASK)
/*! @} */

/*! @name DEBUG_FEATURES - Cortex Debug Features Control */
/*! @{ */

#define SYSCON3_DEBUG_FEATURES_CPU0_NIDEN_MASK   (0x3U)
#define SYSCON3_DEBUG_FEATURES_CPU0_NIDEN_SHIFT  (0U)
/*! CPU0_NIDEN - CPU0 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU0_NIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU0_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU0_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU0_DBGEN_MASK   (0xCU)
#define SYSCON3_DEBUG_FEATURES_CPU0_DBGEN_SHIFT  (2U)
/*! CPU0_DBGEN - CPU0 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU0_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU0_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU0_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU0_SPNIDEN_MASK (0x30U)
#define SYSCON3_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT (4U)
/*! CPU0_SPNIDEN - CPU0 Secure Privileged Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU0_SPNIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU0_SPNIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU0_SPNIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU0_SPIDEN_MASK  (0xC0U)
#define SYSCON3_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT (6U)
/*! CPU0_SPIDEN - CPU0 Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU0_SPIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU0_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU0_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU1_NIDEN_MASK   (0x300U)
#define SYSCON3_DEBUG_FEATURES_CPU1_NIDEN_SHIFT  (8U)
/*! CPU1_NIDEN - CPU1 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU1_NIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU1_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU1_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU1_DBGEN_MASK   (0xC00U)
#define SYSCON3_DEBUG_FEATURES_CPU1_DBGEN_SHIFT  (10U)
/*! CPU1_DBGEN - CPU1 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU1_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU1_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU1_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU1_SPNIDEN_MASK (0x3000U)
#define SYSCON3_DEBUG_FEATURES_CPU1_SPNIDEN_SHIFT (12U)
/*! CPU1_SPNIDEN - CPU1 Secure Privileged Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU1_SPNIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU1_SPNIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU1_SPNIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CPU1_SPIDEN_MASK  (0xC000U)
#define SYSCON3_DEBUG_FEATURES_CPU1_SPIDEN_SHIFT (14U)
/*! CPU1_SPIDEN - CPU1 Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CPU1_SPIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CPU1_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CPU1_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_HIFI4_NIDEN_MASK  (0x30000U)
#define SYSCON3_DEBUG_FEATURES_HIFI4_NIDEN_SHIFT (16U)
/*! HIFI4_NIDEN - HiFi4 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_HIFI4_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_HIFI4_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_HIFI4_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_HIFI4_DBGEN_MASK  (0xC0000U)
#define SYSCON3_DEBUG_FEATURES_HIFI4_DBGEN_SHIFT (18U)
/*! HIFI4_DBGEN - HiFi4 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_HIFI4_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_HIFI4_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_HIFI4_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_HIFI1_NIDEN_MASK  (0x300000U)
#define SYSCON3_DEBUG_FEATURES_HIFI1_NIDEN_SHIFT (20U)
/*! HIFI1_NIDEN - HiFi1 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_HIFI1_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_HIFI1_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_HIFI1_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_HIFI1_DBGEN_MASK  (0xC00000U)
#define SYSCON3_DEBUG_FEATURES_HIFI1_DBGEN_SHIFT (22U)
/*! HIFI1_DBGEN - HiFi1 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_HIFI1_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_HIFI1_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_HIFI1_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_AHBAP_DBGEN_MASK  (0x3000000U)
#define SYSCON3_DEBUG_FEATURES_AHBAP_DBGEN_SHIFT (24U)
/*! AHBAP_DBGEN - AHB-AP Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_AHBAP_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_AHBAP_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_AHBAP_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_AHBAP_SPIDEN_MASK (0xC000000U)
#define SYSCON3_DEBUG_FEATURES_AHBAP_SPIDEN_SHIFT (26U)
/*! AHBAP_SPIDEN - AHB-AP Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_AHBAP_SPIDEN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_AHBAP_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_AHBAP_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_EZHV_DBGEN_MASK   (0x30000000U)
#define SYSCON3_DEBUG_FEATURES_EZHV_DBGEN_SHIFT  (28U)
/*! EZHV_DBGEN - EZH-V Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_EZHV_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_EZHV_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_EZHV_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_CORESIGHT_EN_MASK (0xC0000000U)
#define SYSCON3_DEBUG_FEATURES_CORESIGHT_EN_SHIFT (30U)
/*! CORESIGHT_EN - CoreSight Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_CORESIGHT_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_CORESIGHT_EN_SHIFT)) & SYSCON3_DEBUG_FEATURES_CORESIGHT_EN_MASK)
/*! @} */

/*! @name DEBUG_FEATURES_DP - Cortex Debug Features Control */
/*! @{ */

#define SYSCON3_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK (0x3U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT (0U)
/*! CPU0_NIDEN - CPU0 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_NIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU0_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU0_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK (0xCU)
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT (2U)
/*! CPU0_DBGEN - CPU0 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_DBGEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU0_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU0_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK (0x30U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT (4U)
/*! CPU0_SPNIDEN - CPU0 Secure Privileged Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU0_SPNIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU0_SPNIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK (0xC0U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT (6U)
/*! CPU0_SPIDEN - CPU0 Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU0_SPIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU0_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU0_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU1_NIDEN_MASK (0x300U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_NIDEN_SHIFT (8U)
/*! CPU1_NIDEN - CPU1 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_NIDEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU1_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU1_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU1_DBGEN_MASK (0xC00U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_DBGEN_SHIFT (10U)
/*! CPU1_DBGEN - CPU1 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_DBGEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU1_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU1_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPNIDEN_MASK (0x3000U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPNIDEN_SHIFT (12U)
/*! CPU1_SPNIDEN - CPU1 Secure Privileged Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPNIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU1_SPNIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU1_SPNIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPIDEN_MASK (0xC000U)
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPIDEN_SHIFT (14U)
/*! CPU1_SPIDEN - CPU1 Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CPU1_SPIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CPU1_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CPU1_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_NIDEN_MASK (0x30000U)
#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_NIDEN_SHIFT (16U)
/*! HIFI4_NIDEN - HiFi4 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_NIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_HIFI4_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_HIFI4_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_DBGEN_MASK (0xC0000U)
#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_DBGEN_SHIFT (18U)
/*! HIFI4_DBGEN - HiFi4 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_HIFI4_DBGEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_HIFI4_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_HIFI4_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_NIDEN_MASK (0x300000U)
#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_NIDEN_SHIFT (20U)
/*! HIFI1_NIDEN - HiFi1 Non-Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_NIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_HIFI1_NIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_HIFI1_NIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_DBGEN_MASK (0xC00000U)
#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_DBGEN_SHIFT (22U)
/*! HIFI1_DBGEN - HiFi1 Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_HIFI1_DBGEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_HIFI1_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_HIFI1_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_DBGEN_MASK (0x3000000U)
#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_DBGEN_SHIFT (24U)
/*! AHBAP_DBGEN - AHB-AP Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_DBGEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_AHBAP_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_AHBAP_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_SPIDEN_MASK (0xC000000U)
#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_SPIDEN_SHIFT (26U)
/*! AHBAP_SPIDEN - AHB-AP Secure Privileged Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_AHBAP_SPIDEN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_AHBAP_SPIDEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_AHBAP_SPIDEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_EZHV_DBGEN_MASK (0x30000000U)
#define SYSCON3_DEBUG_FEATURES_DP_EZHV_DBGEN_SHIFT (28U)
/*! EZHV_DBGEN - EZH-V Invasive Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_EZHV_DBGEN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_EZHV_DBGEN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_EZHV_DBGEN_MASK)

#define SYSCON3_DEBUG_FEATURES_DP_CORESIGHT_EN_MASK (0xC0000000U)
#define SYSCON3_DEBUG_FEATURES_DP_CORESIGHT_EN_SHIFT (30U)
/*! CORESIGHT_EN - CoreSight Debug Control
 *  0b01..Disables
 *  0b10..Enables
 */
#define SYSCON3_DEBUG_FEATURES_DP_CORESIGHT_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_FEATURES_DP_CORESIGHT_EN_SHIFT)) & SYSCON3_DEBUG_FEATURES_DP_CORESIGHT_EN_MASK)
/*! @} */

/*! @name DEBUG_AUTH_BEACON - Debug Authentication Beacon */
/*! @{ */

#define SYSCON3_DEBUG_AUTH_BEACON_BEACON_MASK    (0xFFFFFFFFU)
#define SYSCON3_DEBUG_AUTH_BEACON_BEACON_SHIFT   (0U)
/*! BEACON - Beacon */
#define SYSCON3_DEBUG_AUTH_BEACON_BEACON(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON3_DEBUG_AUTH_BEACON_BEACON_SHIFT)) & SYSCON3_DEBUG_AUTH_BEACON_BEACON_MASK)
/*! @} */

/*! @name GRAY_CODE_LSB - Gray to Binary Converter - Gray Code [31:0] */
/*! @{ */

#define SYSCON3_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK (0xFFFFFFFFU)
#define SYSCON3_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT (0U)
/*! CODE_GRAY_31_0 - Gray Code [31:0] */
#define SYSCON3_GRAY_CODE_LSB_CODE_GRAY_31_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON3_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT)) & SYSCON3_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK)
/*! @} */

/*! @name GRAY_CODE_MSB - Gray to Binary Converter - Gray Code [63:32] */
/*! @{ */

#define SYSCON3_GRAY_CODE_MSB_CODE_GRAY_63_32_MASK (0xFFFFFFFFU)
#define SYSCON3_GRAY_CODE_MSB_CODE_GRAY_63_32_SHIFT (0U)
/*! CODE_GRAY_63_32 - Gray Code [63:32] */
#define SYSCON3_GRAY_CODE_MSB_CODE_GRAY_63_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_GRAY_CODE_MSB_CODE_GRAY_63_32_SHIFT)) & SYSCON3_GRAY_CODE_MSB_CODE_GRAY_63_32_MASK)
/*! @} */

/*! @name BINARY_CODE_LSB - Gray to Binary Converter - Binary Code [31:0] */
/*! @{ */

#define SYSCON3_BINARY_CODE_LSB_CODE_BIN_31_0_MASK (0xFFFFFFFFU)
#define SYSCON3_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT (0U)
/*! CODE_BIN_31_0 - Binary Code [31:0] */
#define SYSCON3_BINARY_CODE_LSB_CODE_BIN_31_0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT)) & SYSCON3_BINARY_CODE_LSB_CODE_BIN_31_0_MASK)
/*! @} */

/*! @name BINARY_CODE_MSB - Gray to Binary Converter - Binary Code [63:32] */
/*! @{ */

#define SYSCON3_BINARY_CODE_MSB_CODE_BIN_63_32_MASK (0xFFFFFFFFU)
#define SYSCON3_BINARY_CODE_MSB_CODE_BIN_63_32_SHIFT (0U)
/*! CODE_BIN_63_32 - Binary Code [63:32] */
#define SYSCON3_BINARY_CODE_MSB_CODE_BIN_63_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON3_BINARY_CODE_MSB_CODE_BIN_63_32_SHIFT)) & SYSCON3_BINARY_CODE_MSB_CODE_BIN_63_32_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON3_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON3_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SYSCON3_H_ */

