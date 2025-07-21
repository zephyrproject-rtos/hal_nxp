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
**         CMSIS Peripheral Access Layer for SYSCON0
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
 * @file PERI_SYSCON0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON0
 *
 * CMSIS Peripheral Access Layer for SYSCON0
 */

#if !defined(PERI_SYSCON0_H_)
#define PERI_SYSCON0_H_                          /**< Symbol preventing repeated inclusion */

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
   -- SYSCON0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON0_Peripheral_Access_Layer SYSCON0 Peripheral Access Layer
 * @{
 */

/** SYSCON0 - Size of Registers Arrays */
#define SYSCON0_GDET_CTRL_1_COUNT                 1u
#define SYSCON0_ELS_AS_UUID_COUNT                 4u

/** SYSCON0 - Register Layout Typedef */
typedef struct {
  __IO uint32_t SEC_CLK_CTRL;                      /**< Security Clock Control, offset: 0x0 */
  __O  uint32_t SEC_CLK_CTRL_SET;                  /**< Security Clock Control Set, offset: 0x4 */
  __O  uint32_t SEC_CLK_CTRL_CLR;                  /**< Security Clock Control Clear, offset: 0x8 */
  __IO uint32_t GDET_CTRL[SYSCON0_GDET_CTRL_1_COUNT]; /**< GDET0 Control, array offset: 0xC, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t NMISRC;                            /**< NMI Source Select, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CTIMERGLOBALSTARTEN;               /**< CTIMER Global Start Enable, offset: 0x1C */
       uint8_t RESERVED_2[16];
  __I  uint32_t FUSEACSTATUS;                      /**< Fuse Access Status, offset: 0x30 */
       uint8_t RESERVED_3[68];
  __IO uint32_t AHBMATPRIO;                        /**< Bus Matrix Priority, offset: 0x78 */
       uint8_t RESERVED_4[4];
  __O  uint32_t RXEVPULSEGEN;                      /**< Receive Event Pulse Generator, offset: 0x80 */
  __IO uint32_t LATCHED_CM33_TXEV;                 /**< Latched Cortex-M33 Transmit Event, offset: 0x84 */
       uint8_t RESERVED_5[8];
  __IO uint32_t SYSTEM_STICK_CALIB;                /**< System Secure Tick Calibration, offset: 0x90 */
  __IO uint32_t SYSTEM_NSTICK_CALIB;               /**< System Non-Secure Tick Calibration, offset: 0x94 */
  __I  uint32_t CPU0_STATUS;                       /**< CPU0 Status, offset: 0x98 */
       uint8_t RESERVED_6[52];
  __IO uint32_t GPIO_PSYNC;                        /**< GPIO Synchronization Stages, offset: 0xD0 */
       uint8_t RESERVED_7[64];
  __IO uint32_t AUTOCLKGATEOVERRIDE0;              /**< Automatic Clock Gate Override, offset: 0x114 */
  __IO uint32_t SRAM_CLKGATE_CTRL;                 /**< SRAM Clock Gating Control, offset: 0x118 */
       uint8_t RESERVED_8[8];
  __IO uint32_t OCOTP_MEM_CTL;                     /**< OCOTP Memory Control, offset: 0x124 */
  __IO uint32_t ELS_MEM_CTL;                       /**< ELS Memory Control, offset: 0x128 */
       uint8_t RESERVED_9[4];
  __IO uint32_t MMU0_MEM_CTRL;                     /**< MMU0 Memory Control, offset: 0x130 */
       uint8_t RESERVED_10[12];
  __IO uint32_t EDMA0_MEM_CTRL;                    /**< eDMA0 Memory Control, offset: 0x140 */
  __IO uint32_t EDMA1_MEM_CTRL;                    /**< eDMA1 Memory Control, offset: 0x144 */
       uint8_t RESERVED_11[4];
  __IO uint32_t ETF_MEM_CTRL;                      /**< ETF Memory Control, offset: 0x14C */
  __IO uint32_t MMU1_MEM_CTRL;                     /**< MMU1 Memory Control, offset: 0x150 */
  __IO uint32_t XSPI0_MEM_CTRL;                    /**< XSPI0 Memory Control, offset: 0x154 */
  __IO uint32_t XSPI1_MEM_CTRL;                    /**< XSPI1 Memory Control, offset: 0x158 */
  __IO uint32_t XSPI0_DATA_MEM_CTRL;               /**< CACHE64_CTRL0 Data Memory Control, offset: 0x15C */
  __IO uint32_t XSPI1_DATA_MEM_CTRL;               /**< CACHE64_CTRL1 Data Memory Control, offset: 0x160 */
  __IO uint32_t NPU_MEM_CTRL;                      /**< NPU Memory Control, offset: 0x164 */
  __IO uint32_t PKC0_MEM_CTRL;                     /**< PKC Memory 0 Control, offset: 0x168 */
  __IO uint32_t PKC1_MEM_CTRL;                     /**< PKC Memory 1 Control, offset: 0x16C */
       uint8_t RESERVED_12[4];
  __IO uint32_t CM33_MEM_DATA_CTRL;                /**< CPU0 Memory Data Control, offset: 0x174 */
  __IO uint32_t CM33_MEM_TAG_CTRL;                 /**< CPU0 Memory Tag Control, offset: 0x178 */
       uint8_t RESERVED_13[140];
  __IO uint32_t HIFI4_MEM_CTL;                     /**< HiFi4 Memory Control, offset: 0x208 */
       uint8_t RESERVED_14[52];
  __IO uint32_t SAI0_MCLK_CTRL;                    /**< SAI0-2 MCLK IO Direction Control, offset: 0x240 */
       uint8_t RESERVED_15[24];
  __IO uint32_t XSPI0_TAG_MEM_CTRL;                /**< CACHE64_CTRL0 Tag Memory Control, offset: 0x25C */
  __IO uint32_t XSPI1_TAG_MEM_CTRL;                /**< CACHE64_CTRL1 Tag Memory Control, offset: 0x260 */
       uint8_t RESERVED_16[28];
  __IO uint32_t COMP_AUTOGATE_EN;                  /**< VDD2_COMP Auto Gating Enable, offset: 0x280 */
       uint8_t RESERVED_17[12];
  __IO uint32_t COMP_DEBUG_HALTED_SEL;             /**< VDD2_COMP Debug Halted Select, offset: 0x290 */
       uint8_t RESERVED_18[108];
  __IO uint32_t DSPSTALL;                          /**< HiFi4 Stall, offset: 0x300 */
  __IO uint32_t OCDHALTONRESET;                    /**< HiFi4 OCDHaltOnReset, offset: 0x304 */
  __I  uint32_t HIFI4_GPR0;                        /**< HiFi4 General Purpose Register 0, offset: 0x308 */
       uint8_t RESERVED_19[8];
  __I  uint32_t HIFI4_GPR1;                        /**< HiFi4 General Purpose Register 1, offset: 0x314 */
  __I  uint32_t HIFI4_GPR2;                        /**< HiFi4 General Purpose Register 2, offset: 0x318 */
  __IO uint32_t DSP_VECT_REMAP;                    /**< HiFi4 DSP Vector Remap, offset: 0x31C */
       uint8_t RESERVED_20[256];
  __IO uint32_t EDMA0_EN0;                         /**< eDMA0 Request Enable 0, offset: 0x420 */
  __IO uint32_t EDMA0_EN1;                         /**< eDMA0 Request Enable 1, offset: 0x424 */
  __IO uint32_t EDMA0_EN2;                         /**< eDMA0 Request Enable 2, offset: 0x428 */
  __IO uint32_t EDMA0_EN3;                         /**< eDMA0 Request Enable 3, offset: 0x42C */
  __IO uint32_t EDMA1_EN0;                         /**< eDMA1 Request Enable 0, offset: 0x430 */
  __IO uint32_t EDMA1_EN1;                         /**< eDMA1 Request Enable 1, offset: 0x434 */
  __IO uint32_t EDMA1_EN2;                         /**< eDMA1 Request Enable 2, offset: 0x438 */
  __IO uint32_t EDMA1_EN3;                         /**< eDMA1 Request Enable 3, offset: 0x43C */
       uint8_t RESERVED_21[448];
  __IO uint32_t AXBS_CTRL;                         /**< AXBS Control, offset: 0x600 */
       uint8_t RESERVED_22[36];
  __IO uint32_t I3C_ASYNC_WAKEUP_CTRL;             /**< I3C Asynchronous Wake-up Control, offset: 0x628 */
       uint8_t RESERVED_23[36];
  __IO uint32_t GRAY_CODE_LSB;                     /**< Gray to Binary Converter - Gray Code [31:0], offset: 0x650 */
  __IO uint32_t GRAY_CODE_MSB;                     /**< Gray to Binary Converter - Gray Code [63:32], offset: 0x654 */
  __I  uint32_t BINARY_CODE_LSB;                   /**< Gray to Binary Converter - Binary Code [31:0], offset: 0x658 */
  __I  uint32_t BINARY_CODE_MSB;                   /**< Gray to Binary Converter - Binary Code [63:32], offset: 0x65C */
       uint8_t RESERVED_24[928];
  __I  uint32_t SEC_BUSY_STATE;                    /**< Secure IP Busy State, offset: 0xA00 */
       uint8_t RESERVED_25[252];
  __I  uint32_t ELS_OTP_LC_STATE;                  /**< Lifecycle State, offset: 0xB00 */
  __I  uint32_t ELS_OTP_LC_STATE_DP;               /**< Lifecycle State, offset: 0xB04 */
  __IO uint32_t ELS_TEMPORAL_STATE;                /**< ELS Temporal State, offset: 0xB08 */
  __IO uint32_t ELS_KDF_MASK;                      /**< Key Derivation Function Mask, offset: 0xB0C */
       uint8_t RESERVED_26[44];
  __I  uint32_t ELS_BOOT_STATE1;                   /**< ELS Boot State 1, offset: 0xB3C */
       uint8_t RESERVED_27[40];
  __IO uint32_t ELS_ASSET_PROT;                    /**< ELS Asset Protection, offset: 0xB68 */
       uint8_t RESERVED_28[84];
  __I  uint32_t ELS_AS_UUID[SYSCON0_ELS_AS_UUID_COUNT]; /**< ELS AS UUID, array offset: 0xBC0, array step: 0x4 */
  __I  uint32_t ELS_AS_CFG0;                       /**< ELS AS Configuration 0, offset: 0xBD0 */
  __I  uint32_t ELS_AS_CFG1;                       /**< ELS AS Configuration 1, offset: 0xBD4 */
       uint8_t RESERVED_29[4];
  __I  uint32_t ELS_AS_CFG3;                       /**< ELS AS Configuration 3, offset: 0xBDC */
  __I  uint32_t ELS_AS_ST0;                        /**< ELS AS State 0, offset: 0xBE0 */
  __I  uint32_t ELS_AS_ST1;                        /**< ELS AS State 1, offset: 0xBE4 */
       uint8_t RESERVED_30[16];
  __I  uint32_t ELS_AS_FLAG0;                      /**< ELS AS Flag 0, offset: 0xBF8 */
  __I  uint32_t ELS_AS_FLAG1;                      /**< ELS AS Flag 1, offset: 0xBFC */
       uint8_t RESERVED_31[560];
  __IO uint32_t CLK_OVERRIDE_RAMPKC;               /**< PKC RAM Clock Override, offset: 0xE30 */
} SYSCON0_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON0_Register_Masks SYSCON0 Register Masks
 * @{
 */

/*! @name SEC_CLK_CTRL - Security Clock Control */
/*! @{ */

#define SYSCON0_SEC_CLK_CTRL_GDET0_REFCLK_EN_MASK (0x1U)
#define SYSCON0_SEC_CLK_CTRL_GDET0_REFCLK_EN_SHIFT (0U)
/*! GDET0_REFCLK_EN - GDET0 Reference Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_SEC_CLK_CTRL_GDET0_REFCLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_GDET0_REFCLK_EN_SHIFT)) & SYSCON0_SEC_CLK_CTRL_GDET0_REFCLK_EN_MASK)

#define SYSCON0_SEC_CLK_CTRL_TRNG_REFCLK_EN_MASK (0x4U)
#define SYSCON0_SEC_CLK_CTRL_TRNG_REFCLK_EN_SHIFT (2U)
/*! TRNG_REFCLK_EN - True Random Number Generator (TRNG) Reference Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_SEC_CLK_CTRL_TRNG_REFCLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_TRNG_REFCLK_EN_SHIFT)) & SYSCON0_SEC_CLK_CTRL_TRNG_REFCLK_EN_MASK)

#define SYSCON0_SEC_CLK_CTRL_ELS_CLK_EN_MASK     (0x8U)
#define SYSCON0_SEC_CLK_CTRL_ELS_CLK_EN_SHIFT    (3U)
/*! ELS_CLK_EN - EdgeLock Secure Subsystem (ELS) Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_SEC_CLK_CTRL_ELS_CLK_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_ELS_CLK_EN_SHIFT)) & SYSCON0_SEC_CLK_CTRL_ELS_CLK_EN_MASK)

#define SYSCON0_SEC_CLK_CTRL_ITRC_CLK_EN_MASK    (0x10U)
#define SYSCON0_SEC_CLK_CTRL_ITRC_CLK_EN_SHIFT   (4U)
/*! ITRC_CLK_EN - Intrusion and Tamper Response Controller (ITRC) Reference Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_SEC_CLK_CTRL_ITRC_CLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_ITRC_CLK_EN_SHIFT)) & SYSCON0_SEC_CLK_CTRL_ITRC_CLK_EN_MASK)
/*! @} */

/*! @name SEC_CLK_CTRL_SET - Security Clock Control Set */
/*! @{ */

#define SYSCON0_SEC_CLK_CTRL_SET_GDET0_REFCLK_EN_SET_MASK (0x1U)
#define SYSCON0_SEC_CLK_CTRL_SET_GDET0_REFCLK_EN_SET_SHIFT (0U)
/*! GDET0_REFCLK_EN_SET - GDET0 Reference Clock Enable Set
 *  0b0..Has no effect
 *  0b1..Sets SEC_CLK_CTRL[GDET0_REFCLK_EN] to 1
 */
#define SYSCON0_SEC_CLK_CTRL_SET_GDET0_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_SET_GDET0_REFCLK_EN_SET_SHIFT)) & SYSCON0_SEC_CLK_CTRL_SET_GDET0_REFCLK_EN_SET_MASK)

#define SYSCON0_SEC_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_MASK (0x4U)
#define SYSCON0_SEC_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_SHIFT (2U)
/*! TRNG_REFCLK_EN_SET - TRNG Reference Clock Enable Set
 *  0b0..Has no effect
 *  0b1..Sets SEC_CLK_CTRL[TRNG_REFCLK_EN] to 1
 */
#define SYSCON0_SEC_CLK_CTRL_SET_TRNG_REFCLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_SHIFT)) & SYSCON0_SEC_CLK_CTRL_SET_TRNG_REFCLK_EN_SET_MASK)

#define SYSCON0_SEC_CLK_CTRL_SET_ELS_CLK_EN_SET_MASK (0x8U)
#define SYSCON0_SEC_CLK_CTRL_SET_ELS_CLK_EN_SET_SHIFT (3U)
/*! ELS_CLK_EN_SET - ELS Clock Enable Set
 *  0b0..Has no effect
 *  0b1..Sets SEC_CLK_CTRL[ELS_CLK_EN] to 1
 */
#define SYSCON0_SEC_CLK_CTRL_SET_ELS_CLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_SET_ELS_CLK_EN_SET_SHIFT)) & SYSCON0_SEC_CLK_CTRL_SET_ELS_CLK_EN_SET_MASK)

#define SYSCON0_SEC_CLK_CTRL_SET_ITRC_CLK_EN_SET_MASK (0x10U)
#define SYSCON0_SEC_CLK_CTRL_SET_ITRC_CLK_EN_SET_SHIFT (4U)
/*! ITRC_CLK_EN_SET - ITRC Clock Enable Set
 *  0b0..Has no effect
 *  0b1..Sets SEC_CLK_CTRL[ITRC_CLK_EN] to 1
 */
#define SYSCON0_SEC_CLK_CTRL_SET_ITRC_CLK_EN_SET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_SET_ITRC_CLK_EN_SET_SHIFT)) & SYSCON0_SEC_CLK_CTRL_SET_ITRC_CLK_EN_SET_MASK)
/*! @} */

/*! @name SEC_CLK_CTRL_CLR - Security Clock Control Clear */
/*! @{ */

#define SYSCON0_SEC_CLK_CTRL_CLR_GDET0_REFCLK_EN_CLR_MASK (0x1U)
#define SYSCON0_SEC_CLK_CTRL_CLR_GDET0_REFCLK_EN_CLR_SHIFT (0U)
/*! GDET0_REFCLK_EN_CLR - GDET0 Reference Clock Enable Clear
 *  0b0..Has no effect
 *  0b1..Clears SEC_CLK_CTRL[GDET0_REFCLK_EN] to 0
 */
#define SYSCON0_SEC_CLK_CTRL_CLR_GDET0_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_CLR_GDET0_REFCLK_EN_CLR_SHIFT)) & SYSCON0_SEC_CLK_CTRL_CLR_GDET0_REFCLK_EN_CLR_MASK)

#define SYSCON0_SEC_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_MASK (0x4U)
#define SYSCON0_SEC_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_SHIFT (2U)
/*! TRNG_REFCLK_EN_CLR - TRNG Reference Clock Enable Clear
 *  0b0..Has no effect
 *  0b1..Clears SEC_CLK_CTRL[TRNG_REFCLK_EN] to 0
 */
#define SYSCON0_SEC_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_SHIFT)) & SYSCON0_SEC_CLK_CTRL_CLR_TRNG_REFCLK_EN_CLR_MASK)

#define SYSCON0_SEC_CLK_CTRL_CLR_ELS_CLK_EN_CLR_MASK (0x8U)
#define SYSCON0_SEC_CLK_CTRL_CLR_ELS_CLK_EN_CLR_SHIFT (3U)
/*! ELS_CLK_EN_CLR - ELS Clock Enable Clear
 *  0b0..Has no effect
 *  0b1..Clears SEC_CLK_CTRL[ELS_CLK_EN] to 0
 */
#define SYSCON0_SEC_CLK_CTRL_CLR_ELS_CLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_CLR_ELS_CLK_EN_CLR_SHIFT)) & SYSCON0_SEC_CLK_CTRL_CLR_ELS_CLK_EN_CLR_MASK)

#define SYSCON0_SEC_CLK_CTRL_CLR_ITRC_CLK_EN_CLR_MASK (0x10U)
#define SYSCON0_SEC_CLK_CTRL_CLR_ITRC_CLK_EN_CLR_SHIFT (4U)
/*! ITRC_CLK_EN_CLR - ITRC Clock Enable Clear
 *  0b0..Has no effect
 *  0b1..Clears SEC_CLK_CTRL[ITRC_CLK_EN] to 0
 */
#define SYSCON0_SEC_CLK_CTRL_CLR_ITRC_CLK_EN_CLR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_CLK_CTRL_CLR_ITRC_CLK_EN_CLR_SHIFT)) & SYSCON0_SEC_CLK_CTRL_CLR_ITRC_CLK_EN_CLR_MASK)
/*! @} */

/*! @name GDET_CTRL - GDET0 Control */
/*! @{ */

#define SYSCON0_GDET_CTRL_GDET_EVTCNT_CLR_MASK   (0x1U)
#define SYSCON0_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT  (0U)
/*! GDET_EVTCNT_CLR - GDET Event Counter Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SYSCON0_GDET_CTRL_GDET_EVTCNT_CLR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_GDET_EVTCNT_CLR_SHIFT)) & SYSCON0_GDET_CTRL_GDET_EVTCNT_CLR_MASK)

#define SYSCON0_GDET_CTRL_GDET_ERR_CLR_MASK      (0x2U)
#define SYSCON0_GDET_CTRL_GDET_ERR_CLR_SHIFT     (1U)
/*! GDET_ERR_CLR - GDET Error Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define SYSCON0_GDET_CTRL_GDET_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_GDET_ERR_CLR_SHIFT)) & SYSCON0_GDET_CTRL_GDET_ERR_CLR_MASK)

#define SYSCON0_GDET_CTRL_GDET_ISO_SW_MASK       (0xCU)
#define SYSCON0_GDET_CTRL_GDET_ISO_SW_SHIFT      (2U)
/*! GDET_ISO_SW - GDET Isolation Control
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define SYSCON0_GDET_CTRL_GDET_ISO_SW(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_GDET_ISO_SW_SHIFT)) & SYSCON0_GDET_CTRL_GDET_ISO_SW_MASK)

#define SYSCON0_GDET_CTRL_EVENT_CNT_MASK         (0xFF0000U)
#define SYSCON0_GDET_CTRL_EVENT_CNT_SHIFT        (16U)
/*! EVENT_CNT - Event Count Value */
#define SYSCON0_GDET_CTRL_EVENT_CNT(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_EVENT_CNT_SHIFT)) & SYSCON0_GDET_CTRL_EVENT_CNT_MASK)

#define SYSCON0_GDET_CTRL_POS_SYNC_MASK          (0x1000000U)
#define SYSCON0_GDET_CTRL_POS_SYNC_SHIFT         (24U)
/*! POS_SYNC - Positive Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SYSCON0_GDET_CTRL_POS_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_POS_SYNC_SHIFT)) & SYSCON0_GDET_CTRL_POS_SYNC_MASK)

#define SYSCON0_GDET_CTRL_NEG_SYNC_MASK          (0x2000000U)
#define SYSCON0_GDET_CTRL_NEG_SYNC_SHIFT         (25U)
/*! NEG_SYNC - Negative Glitch Detection
 *  0b0..Not detected
 *  0b1..Detected
 */
#define SYSCON0_GDET_CTRL_NEG_SYNC(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_NEG_SYNC_SHIFT)) & SYSCON0_GDET_CTRL_NEG_SYNC_MASK)

#define SYSCON0_GDET_CTRL_EVENT_CLR_FLAG_MASK    (0x4000000U)
#define SYSCON0_GDET_CTRL_EVENT_CLR_FLAG_SHIFT   (26U)
/*! EVENT_CLR_FLAG - Event Counter Clear
 *  0b0..Not cleared
 *  0b1..Cleared
 */
#define SYSCON0_GDET_CTRL_EVENT_CLR_FLAG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_GDET_CTRL_EVENT_CLR_FLAG_SHIFT)) & SYSCON0_GDET_CTRL_EVENT_CLR_FLAG_MASK)
/*! @} */

/* The count of SYSCON0_GDET_CTRL */
#define SYSCON0_GDET_CTRL_COUNT                  (1U)

/*! @name NMISRC - NMI Source Select */
/*! @{ */

#define SYSCON0_NMISRC_IRQCPU0_MASK              (0xFFU)
#define SYSCON0_NMISRC_IRQCPU0_SHIFT             (0U)
/*! IRQCPU0 - The IRQ number of the interrupt that acts as the NMI for CPU0, if enabled by NMIENCPU0 */
#define SYSCON0_NMISRC_IRQCPU0(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON0_NMISRC_IRQCPU0_SHIFT)) & SYSCON0_NMISRC_IRQCPU0_MASK)

#define SYSCON0_NMISRC_NMIENCPU0_MASK            (0x80000000U)
#define SYSCON0_NMISRC_NMIENCPU0_SHIFT           (31U)
/*! NMIENCPU0 - Enables the Non-Maskable Interrupt (NMI) source selected by IRQCPU0
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_NMISRC_NMIENCPU0(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON0_NMISRC_NMIENCPU0_SHIFT)) & SYSCON0_NMISRC_NMIENCPU0_MASK)
/*! @} */

/*! @name CTIMERGLOBALSTARTEN - CTIMER Global Start Enable */
/*! @{ */

#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK (0x1U)
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT (0U)
/*! CTIMER0_CLK_EN - CTIMER0 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_SHIFT)) & SYSCON0_CTIMERGLOBALSTARTEN_CTIMER0_CLK_EN_MASK)

#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK (0x2U)
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT (1U)
/*! CTIMER1_CLK_EN - CTIMER1 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_SHIFT)) & SYSCON0_CTIMERGLOBALSTARTEN_CTIMER1_CLK_EN_MASK)

#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK (0x4U)
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT (2U)
/*! CTIMER2_CLK_EN - CTIMER2 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_SHIFT)) & SYSCON0_CTIMERGLOBALSTARTEN_CTIMER2_CLK_EN_MASK)

#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK (0x8U)
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT (3U)
/*! CTIMER3_CLK_EN - CTIMER3 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_SHIFT)) & SYSCON0_CTIMERGLOBALSTARTEN_CTIMER3_CLK_EN_MASK)

#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK (0x10U)
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT (4U)
/*! CTIMER4_CLK_EN - CTIMER4 Function Clock Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_SHIFT)) & SYSCON0_CTIMERGLOBALSTARTEN_CTIMER4_CLK_EN_MASK)
/*! @} */

/*! @name FUSEACSTATUS - Fuse Access Status */
/*! @{ */

#define SYSCON0_FUSEACSTATUS_FUSE_CALIB_MASK     (0x1U)
#define SYSCON0_FUSEACSTATUS_FUSE_CALIB_SHIFT    (0U)
/*! FUSE_CALIB - Fuse Calibrate Flag
 *  0b0..Not calibrated
 *  0b1..Calibrated
 */
#define SYSCON0_FUSEACSTATUS_FUSE_CALIB(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_FUSEACSTATUS_FUSE_CALIB_SHIFT)) & SYSCON0_FUSEACSTATUS_FUSE_CALIB_MASK)

#define SYSCON0_FUSEACSTATUS_STATUS_BUSY_MASK    (0x2U)
#define SYSCON0_FUSEACSTATUS_STATUS_BUSY_SHIFT   (1U)
/*! STATUS_BUSY - OCOTP Status
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SYSCON0_FUSEACSTATUS_STATUS_BUSY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_FUSEACSTATUS_STATUS_BUSY_SHIFT)) & SYSCON0_FUSEACSTATUS_STATUS_BUSY_MASK)
/*! @} */

/*! @name AHBMATPRIO - Bus Matrix Priority */
/*! @{ */

#define SYSCON0_AHBMATPRIO_MBUS_M0_MASK          (0x3U)
#define SYSCON0_AHBMATPRIO_MBUS_M0_SHIFT         (0U)
/*! MBUS_M0 - M-Bus M0 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M0_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M0_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M1_MASK          (0xCU)
#define SYSCON0_AHBMATPRIO_MBUS_M1_SHIFT         (2U)
/*! MBUS_M1 - M-Bus M1 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M1_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M1_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M2_MASK          (0x30U)
#define SYSCON0_AHBMATPRIO_MBUS_M2_SHIFT         (4U)
/*! MBUS_M2 - M-Bus M2 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M2_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M2_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M3_MASK          (0xC0U)
#define SYSCON0_AHBMATPRIO_MBUS_M3_SHIFT         (6U)
/*! MBUS_M3 - M-Bus M3 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M3_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M3_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M4_MASK          (0x300U)
#define SYSCON0_AHBMATPRIO_MBUS_M4_SHIFT         (8U)
/*! MBUS_M4 - M-Bus M4 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M4(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M4_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M4_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M5_MASK          (0xC00U)
#define SYSCON0_AHBMATPRIO_MBUS_M5_SHIFT         (10U)
/*! MBUS_M5 - M-Bus M5 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M5(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M5_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M5_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M6_MASK          (0x3000U)
#define SYSCON0_AHBMATPRIO_MBUS_M6_SHIFT         (12U)
/*! MBUS_M6 - M-Bus M6 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M6(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M6_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M6_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M7_MASK          (0xC000U)
#define SYSCON0_AHBMATPRIO_MBUS_M7_SHIFT         (14U)
/*! MBUS_M7 - M-Bus M7 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M7(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M7_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M7_MASK)

#define SYSCON0_AHBMATPRIO_MBUS_M8_MASK          (0x30000U)
#define SYSCON0_AHBMATPRIO_MBUS_M8_SHIFT         (16U)
/*! MBUS_M8 - M-Bus M8 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_MBUS_M8(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_MBUS_M8_SHIFT)) & SYSCON0_AHBMATPRIO_MBUS_M8_MASK)

#define SYSCON0_AHBMATPRIO_PBUS_M0_MASK          (0x3000000U)
#define SYSCON0_AHBMATPRIO_PBUS_M0_SHIFT         (24U)
/*! PBUS_M0 - P-Bus M0 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_PBUS_M0(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_PBUS_M0_SHIFT)) & SYSCON0_AHBMATPRIO_PBUS_M0_MASK)

#define SYSCON0_AHBMATPRIO_PBUS_M1_MASK          (0xC000000U)
#define SYSCON0_AHBMATPRIO_PBUS_M1_SHIFT         (26U)
/*! PBUS_M1 - P-Bus M1 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_PBUS_M1(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_PBUS_M1_SHIFT)) & SYSCON0_AHBMATPRIO_PBUS_M1_MASK)

#define SYSCON0_AHBMATPRIO_PBUS_M2_MASK          (0x30000000U)
#define SYSCON0_AHBMATPRIO_PBUS_M2_SHIFT         (28U)
/*! PBUS_M2 - P-Bus M2 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_PBUS_M2(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_PBUS_M2_SHIFT)) & SYSCON0_AHBMATPRIO_PBUS_M2_MASK)

#define SYSCON0_AHBMATPRIO_PBUS_M3_MASK          (0xC0000000U)
#define SYSCON0_AHBMATPRIO_PBUS_M3_SHIFT         (30U)
/*! PBUS_M3 - P-Bus M3 Priority
 *  0b00..Level 0
 *  0b01..Level 1
 *  0b10..Level 2
 *  0b11..Level 3
 */
#define SYSCON0_AHBMATPRIO_PBUS_M3(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_AHBMATPRIO_PBUS_M3_SHIFT)) & SYSCON0_AHBMATPRIO_PBUS_M3_MASK)
/*! @} */

/*! @name RXEVPULSEGEN - Receive Event Pulse Generator */
/*! @{ */

#define SYSCON0_RXEVPULSEGEN_RXEVPULSEGEN_MASK   (0x1U)
#define SYSCON0_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT  (0U)
/*! RXEVPULSEGEN - Receive Event Pulse Generator
 *  0b0..No effect
 *  0b1..Pulse receive event high for one cycle
 */
#define SYSCON0_RXEVPULSEGEN_RXEVPULSEGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT)) & SYSCON0_RXEVPULSEGEN_RXEVPULSEGEN_MASK)
/*! @} */

/*! @name LATCHED_CM33_TXEV - Latched Cortex-M33 Transmit Event */
/*! @{ */

#define SYSCON0_LATCHED_CM33_TXEV_LATCHED_TXEV_MASK (0x1U)
#define SYSCON0_LATCHED_CM33_TXEV_LATCHED_TXEV_SHIFT (0U)
/*! LATCHED_TXEV - Cortex-M33 Transmit Event
 *  0b0..No effect
 *  0b1..Clear the event flag
 */
#define SYSCON0_LATCHED_CM33_TXEV_LATCHED_TXEV(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_LATCHED_CM33_TXEV_LATCHED_TXEV_SHIFT)) & SYSCON0_LATCHED_CM33_TXEV_LATCHED_TXEV_MASK)
/*! @} */

/*! @name SYSTEM_STICK_CALIB - System Secure Tick Calibration */
/*! @{ */

#define SYSCON0_SYSTEM_STICK_CALIB_TENMS_MASK    (0xFFFFFFU)
#define SYSCON0_SYSTEM_STICK_CALIB_TENMS_SHIFT   (0U)
/*! TENMS - Ten Milliseconds */
#define SYSCON0_SYSTEM_STICK_CALIB_TENMS(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_STICK_CALIB_TENMS_SHIFT)) & SYSCON0_SYSTEM_STICK_CALIB_TENMS_MASK)

#define SYSCON0_SYSTEM_STICK_CALIB_SKEW_MASK     (0x1000000U)
#define SYSCON0_SYSTEM_STICK_CALIB_SKEW_SHIFT    (24U)
/*! SKEW - Skew
 *  0b0..Exact
 *  0b1..Inexact, or not given
 */
#define SYSCON0_SYSTEM_STICK_CALIB_SKEW(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_STICK_CALIB_SKEW_SHIFT)) & SYSCON0_SYSTEM_STICK_CALIB_SKEW_MASK)

#define SYSCON0_SYSTEM_STICK_CALIB_NOREF_MASK    (0x2000000U)
#define SYSCON0_SYSTEM_STICK_CALIB_NOREF_SHIFT   (25U)
/*! NOREF - No Reference Clock
 *  0b0..Provides
 *  0b1..Not provide
 */
#define SYSCON0_SYSTEM_STICK_CALIB_NOREF(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_STICK_CALIB_NOREF_SHIFT)) & SYSCON0_SYSTEM_STICK_CALIB_NOREF_MASK)
/*! @} */

/*! @name SYSTEM_NSTICK_CALIB - System Non-Secure Tick Calibration */
/*! @{ */

#define SYSCON0_SYSTEM_NSTICK_CALIB_TENMS_MASK   (0xFFFFFFU)
#define SYSCON0_SYSTEM_NSTICK_CALIB_TENMS_SHIFT  (0U)
/*! TENMS - Ten Milliseconds */
#define SYSCON0_SYSTEM_NSTICK_CALIB_TENMS(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_NSTICK_CALIB_TENMS_SHIFT)) & SYSCON0_SYSTEM_NSTICK_CALIB_TENMS_MASK)

#define SYSCON0_SYSTEM_NSTICK_CALIB_SKEW_MASK    (0x1000000U)
#define SYSCON0_SYSTEM_NSTICK_CALIB_SKEW_SHIFT   (24U)
/*! SKEW - Skew
 *  0b0..Exact
 *  0b1..Inexact, or not given
 */
#define SYSCON0_SYSTEM_NSTICK_CALIB_SKEW(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_NSTICK_CALIB_SKEW_SHIFT)) & SYSCON0_SYSTEM_NSTICK_CALIB_SKEW_MASK)

#define SYSCON0_SYSTEM_NSTICK_CALIB_NOREF_MASK   (0x2000000U)
#define SYSCON0_SYSTEM_NSTICK_CALIB_NOREF_SHIFT  (25U)
/*! NOREF - No Reference Clock
 *  0b0..Provides
 *  0b1..Not provide
 */
#define SYSCON0_SYSTEM_NSTICK_CALIB_NOREF(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_SYSTEM_NSTICK_CALIB_NOREF_SHIFT)) & SYSCON0_SYSTEM_NSTICK_CALIB_NOREF_MASK)
/*! @} */

/*! @name CPU0_STATUS - CPU0 Status */
/*! @{ */

#define SYSCON0_CPU0_STATUS_CPU0_LOCKUP_MASK     (0x1U)
#define SYSCON0_CPU0_STATUS_CPU0_LOCKUP_SHIFT    (0U)
/*! CPU0_LOCKUP - CPU0 Lockup State
 *  0b0..Not in lockup
 *  0b1..In lockup
 */
#define SYSCON0_CPU0_STATUS_CPU0_LOCKUP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_CPU0_STATUS_CPU0_LOCKUP_SHIFT)) & SYSCON0_CPU0_STATUS_CPU0_LOCKUP_MASK)
/*! @} */

/*! @name GPIO_PSYNC - GPIO Synchronization Stages */
/*! @{ */

#define SYSCON0_GPIO_PSYNC_PSYNC_MASK            (0x1U)
#define SYSCON0_GPIO_PSYNC_PSYNC_SHIFT           (0U)
/*! PSYNC - Synchronization Stage Setting
 *  0b0..2-stage sync
 *  0b1..1-stage sync
 */
#define SYSCON0_GPIO_PSYNC_PSYNC(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON0_GPIO_PSYNC_PSYNC_SHIFT)) & SYSCON0_GPIO_PSYNC_PSYNC_MASK)
/*! @} */

/*! @name AUTOCLKGATEOVERRIDE0 - Automatic Clock Gate Override */
/*! @{ */

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION0_MASK (0x1U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION0_SHIFT (0U)
/*! PARTITION0 - Partition 0
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION0_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION0_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION1_MASK (0x2U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION1_SHIFT (1U)
/*! PARTITION1 - Partition 1
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION1_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION1_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION2_MASK (0x4U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION2_SHIFT (2U)
/*! PARTITION2 - Partition 2
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION2(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION2_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION2_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION3_MASK (0x8U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION3_SHIFT (3U)
/*! PARTITION3 - Partition 3
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION3(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION3_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION3_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION4_MASK (0x10U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION4_SHIFT (4U)
/*! PARTITION4 - Partition 4
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION4(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION4_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION4_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION5_MASK (0x20U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION5_SHIFT (5U)
/*! PARTITION5 - Partition 5
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION5(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION5_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION5_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION6_MASK (0x40U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION6_SHIFT (6U)
/*! PARTITION6 - Partition 6
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION6(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION6_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION6_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION7_MASK (0x80U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION7_SHIFT (7U)
/*! PARTITION7 - Partition 7
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION7(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION7_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION7_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION8_MASK (0x100U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION8_SHIFT (8U)
/*! PARTITION8 - Partition 8
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION8(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION8_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION8_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION9_MASK (0x200U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION9_SHIFT (9U)
/*! PARTITION9 - Partition 9
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION9(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION9_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION9_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION10_MASK (0x400U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION10_SHIFT (10U)
/*! PARTITION10 - Partition 10
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION10(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION10_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION10_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION11_MASK (0x800U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION11_SHIFT (11U)
/*! PARTITION11 - Partition 11
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION11(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION11_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION11_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION12_MASK (0x1000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION12_SHIFT (12U)
/*! PARTITION12 - Partition 12
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION12(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION12_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION12_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION13_MASK (0x2000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION13_SHIFT (13U)
/*! PARTITION13 - Partition 13
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION13(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION13_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION13_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION14_MASK (0x4000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION14_SHIFT (14U)
/*! PARTITION14 - Partition 14
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION14(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION14_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION14_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION15_MASK (0x8000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION15_SHIFT (15U)
/*! PARTITION15 - Partition 15
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION15(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION15_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION15_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION16_MASK (0x10000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION16_SHIFT (16U)
/*! PARTITION16 - Partition 16
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION16(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION16_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION16_MASK)

#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION17_MASK (0x20000U)
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION17_SHIFT (17U)
/*! PARTITION17 - Partition 17
 *  0b0..Enables clock gating
 *  0b1..Continuous clocking
 */
#define SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION17(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION17_SHIFT)) & SYSCON0_AUTOCLKGATEOVERRIDE0_PARTITION17_MASK)
/*! @} */

/*! @name SRAM_CLKGATE_CTRL - SRAM Clock Gating Control */
/*! @{ */

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION0_MASK (0x1U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION0_SHIFT (0U)
/*! PARTITION0 - Partition 0
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION0_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION0_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION1_MASK (0x2U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION1_SHIFT (1U)
/*! PARTITION1 - Partition 1
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION1(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION1_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION1_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION2_MASK (0x4U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION2_SHIFT (2U)
/*! PARTITION2 - Partition 2
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION2(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION2_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION2_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION3_MASK (0x8U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION3_SHIFT (3U)
/*! PARTITION3 - Partition 3
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION3(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION3_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION3_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION4_MASK (0x10U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION4_SHIFT (4U)
/*! PARTITION4 - Partition 4
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION4(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION4_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION4_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION5_MASK (0x20U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION5_SHIFT (5U)
/*! PARTITION5 - Partition 5
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION5(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION5_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION5_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION6_MASK (0x40U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION6_SHIFT (6U)
/*! PARTITION6 - Partition 6
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION6(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION6_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION6_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION7_MASK (0x80U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION7_SHIFT (7U)
/*! PARTITION7 - Partition 7
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION7(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION7_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION7_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION8_MASK (0x100U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION8_SHIFT (8U)
/*! PARTITION8 - Partition 8
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION8(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION8_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION8_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION9_MASK (0x200U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION9_SHIFT (9U)
/*! PARTITION9 - Partition 9
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION9(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION9_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION9_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION10_MASK (0x400U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION10_SHIFT (10U)
/*! PARTITION10 - Partition 10
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION10(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION10_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION10_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION11_MASK (0x800U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION11_SHIFT (11U)
/*! PARTITION11 - Partition 11
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION11(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION11_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION11_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION12_MASK (0x1000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION12_SHIFT (12U)
/*! PARTITION12 - Partition 12
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION12(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION12_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION12_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION13_MASK (0x2000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION13_SHIFT (13U)
/*! PARTITION13 - Partition 13
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION13(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION13_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION13_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION14_MASK (0x4000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION14_SHIFT (14U)
/*! PARTITION14 - Partition 14
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION14(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION14_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION14_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION15_MASK (0x8000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION15_SHIFT (15U)
/*! PARTITION15 - Partition 15
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION15(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION15_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION15_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION16_MASK (0x10000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION16_SHIFT (16U)
/*! PARTITION16 - Partition 16
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION16(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION16_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION16_MASK)

#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION17_MASK (0x20000U)
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION17_SHIFT (17U)
/*! PARTITION17 - Partition 17
 *  0b0..Bus clock input gated
 *  0b1..No effects
 */
#define SYSCON0_SRAM_CLKGATE_CTRL_PARTITION17(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_SRAM_CLKGATE_CTRL_PARTITION17_SHIFT)) & SYSCON0_SRAM_CLKGATE_CTRL_PARTITION17_MASK)
/*! @} */

/*! @name OCOTP_MEM_CTL - OCOTP Memory Control */
/*! @{ */

#define SYSCON0_OCOTP_MEM_CTL_SRAM_WLPD_MASK     (0x80U)
#define SYSCON0_OCOTP_MEM_CTL_SRAM_WLPD_SHIFT    (7U)
/*! SRAM_WLPD - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_OCOTP_MEM_CTL_SRAM_WLPD(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_OCOTP_MEM_CTL_SRAM_WLPD_SHIFT)) & SYSCON0_OCOTP_MEM_CTL_SRAM_WLPD_MASK)

#define SYSCON0_OCOTP_MEM_CTL_SRAM_IG_MASK       (0x100U)
#define SYSCON0_OCOTP_MEM_CTL_SRAM_IG_SHIFT      (8U)
/*! SRAM_IG - SRAM Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_OCOTP_MEM_CTL_SRAM_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_OCOTP_MEM_CTL_SRAM_IG_SHIFT)) & SYSCON0_OCOTP_MEM_CTL_SRAM_IG_MASK)
/*! @} */

/*! @name ELS_MEM_CTL - ELS Memory Control */
/*! @{ */

#define SYSCON0_ELS_MEM_CTL_MEM_WLPD_MASK        (0x80U)
#define SYSCON0_ELS_MEM_CTL_MEM_WLPD_SHIFT       (7U)
/*! MEM_WLPD - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_ELS_MEM_CTL_MEM_WLPD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_MEM_CTL_MEM_WLPD_SHIFT)) & SYSCON0_ELS_MEM_CTL_MEM_WLPD_MASK)

#define SYSCON0_ELS_MEM_CTL_MEM_IG_MASK          (0x100U)
#define SYSCON0_ELS_MEM_CTL_MEM_IG_SHIFT         (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_ELS_MEM_CTL_MEM_IG(x)            (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_MEM_CTL_MEM_IG_SHIFT)) & SYSCON0_ELS_MEM_CTL_MEM_IG_MASK)
/*! @} */

/*! @name MMU0_MEM_CTRL - MMU0 Memory Control */
/*! @{ */

#define SYSCON0_MMU0_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON0_MMU0_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_MMU0_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_MMU0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_MMU0_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_MMU0_MEM_CTRL_MEM_IG_MASK        (0x100U)
#define SYSCON0_MMU0_MEM_CTRL_MEM_IG_SHIFT       (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_MMU0_MEM_CTRL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_MMU0_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_MMU0_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name EDMA0_MEM_CTRL - eDMA0 Memory Control */
/*! @{ */

#define SYSCON0_EDMA0_MEM_CTRL_PWR_STDBY_MASK    (0x80U)
#define SYSCON0_EDMA0_MEM_CTRL_PWR_STDBY_SHIFT   (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_EDMA0_MEM_CTRL_PWR_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_EDMA0_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON0_EDMA0_MEM_CTRL_PWR_IG_MASK       (0x100U)
#define SYSCON0_EDMA0_MEM_CTRL_PWR_IG_SHIFT      (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_EDMA0_MEM_CTRL_PWR_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON0_EDMA0_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name EDMA1_MEM_CTRL - eDMA1 Memory Control */
/*! @{ */

#define SYSCON0_EDMA1_MEM_CTRL_PWR_STDBY_MASK    (0x80U)
#define SYSCON0_EDMA1_MEM_CTRL_PWR_STDBY_SHIFT   (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_EDMA1_MEM_CTRL_PWR_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_EDMA1_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON0_EDMA1_MEM_CTRL_PWR_IG_MASK       (0x100U)
#define SYSCON0_EDMA1_MEM_CTRL_PWR_IG_SHIFT      (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_EDMA1_MEM_CTRL_PWR_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON0_EDMA1_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name ETF_MEM_CTRL - ETF Memory Control */
/*! @{ */

#define SYSCON0_ETF_MEM_CTRL_MEM_STDBY_MASK      (0x80U)
#define SYSCON0_ETF_MEM_CTRL_MEM_STDBY_SHIFT     (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_ETF_MEM_CTRL_MEM_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_ETF_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_ETF_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_ETF_MEM_CTRL_MEM_IG_MASK         (0x100U)
#define SYSCON0_ETF_MEM_CTRL_MEM_IG_SHIFT        (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_ETF_MEM_CTRL_MEM_IG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON0_ETF_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_ETF_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name MMU1_MEM_CTRL - MMU1 Memory Control */
/*! @{ */

#define SYSCON0_MMU1_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON0_MMU1_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_MMU1_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_MMU1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_MMU1_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_MMU1_MEM_CTRL_MEM_IG_MASK        (0x100U)
#define SYSCON0_MMU1_MEM_CTRL_MEM_IG_SHIFT       (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_MMU1_MEM_CTRL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_MMU1_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_MMU1_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name XSPI0_MEM_CTRL - XSPI0 Memory Control */
/*! @{ */

#define SYSCON0_XSPI0_MEM_CTRL_MEM_STDBY_MASK    (0x80U)
#define SYSCON0_XSPI0_MEM_CTRL_MEM_STDBY_SHIFT   (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_MEM_CTRL_MEM_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI0_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI0_MEM_CTRL_MEM_WIG_MASK      (0x100U)
#define SYSCON0_XSPI0_MEM_CTRL_MEM_WIG_SHIFT     (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_MEM_CTRL_MEM_WIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON0_XSPI0_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON0_XSPI0_MEM_CTRL_MEM_RIG_MASK      (0x200U)
#define SYSCON0_XSPI0_MEM_CTRL_MEM_RIG_SHIFT     (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_MEM_CTRL_MEM_RIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON0_XSPI0_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name XSPI1_MEM_CTRL - XSPI1 Memory Control */
/*! @{ */

#define SYSCON0_XSPI1_MEM_CTRL_MEM_STDBY_MASK    (0x80U)
#define SYSCON0_XSPI1_MEM_CTRL_MEM_STDBY_SHIFT   (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_MEM_CTRL_MEM_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI1_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI1_MEM_CTRL_MEM_WIG_MASK      (0x100U)
#define SYSCON0_XSPI1_MEM_CTRL_MEM_WIG_SHIFT     (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_MEM_CTRL_MEM_WIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON0_XSPI1_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON0_XSPI1_MEM_CTRL_MEM_RIG_MASK      (0x200U)
#define SYSCON0_XSPI1_MEM_CTRL_MEM_RIG_SHIFT     (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_MEM_CTRL_MEM_RIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON0_XSPI1_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name XSPI0_DATA_MEM_CTRL - CACHE64_CTRL0 Data Memory Control */
/*! @{ */

#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_STDBY_MASK (0x80U)
#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_STDBY_SHIFT (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_STDBY(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_IG_MASK  (0x100U)
#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_IG_SHIFT (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_IG(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_XSPI0_DATA_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name XSPI1_DATA_MEM_CTRL - CACHE64_CTRL1 Data Memory Control */
/*! @{ */

#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_STDBY_MASK (0x80U)
#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_STDBY_SHIFT (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_STDBY(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_IG_MASK  (0x100U)
#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_IG_SHIFT (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_IG(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_XSPI1_DATA_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name NPU_MEM_CTRL - NPU Memory Control */
/*! @{ */

#define SYSCON0_NPU_MEM_CTRL_PWR_STDBY_MASK      (0x80U)
#define SYSCON0_NPU_MEM_CTRL_PWR_STDBY_SHIFT     (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_NPU_MEM_CTRL_PWR_STDBY(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_NPU_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_NPU_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON0_NPU_MEM_CTRL_PWR_IG_MASK         (0x100U)
#define SYSCON0_NPU_MEM_CTRL_PWR_IG_SHIFT        (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_NPU_MEM_CTRL_PWR_IG(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON0_NPU_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON0_NPU_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name PKC0_MEM_CTRL - PKC Memory 0 Control */
/*! @{ */

#define SYSCON0_PKC0_MEM_CTRL_PWR_STDBY_MASK     (0x80U)
#define SYSCON0_PKC0_MEM_CTRL_PWR_STDBY_SHIFT    (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_PKC0_MEM_CTRL_PWR_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_PKC0_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_PKC0_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON0_PKC0_MEM_CTRL_PWR_IG_MASK        (0x100U)
#define SYSCON0_PKC0_MEM_CTRL_PWR_IG_SHIFT       (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_PKC0_MEM_CTRL_PWR_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_PKC0_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON0_PKC0_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name PKC1_MEM_CTRL - PKC Memory 1 Control */
/*! @{ */

#define SYSCON0_PKC1_MEM_CTRL_PWR_STDBY_MASK     (0x80U)
#define SYSCON0_PKC1_MEM_CTRL_PWR_STDBY_SHIFT    (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_PKC1_MEM_CTRL_PWR_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_PKC1_MEM_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_PKC1_MEM_CTRL_PWR_STDBY_MASK)

#define SYSCON0_PKC1_MEM_CTRL_PWR_IG_MASK        (0x100U)
#define SYSCON0_PKC1_MEM_CTRL_PWR_IG_SHIFT       (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_PKC1_MEM_CTRL_PWR_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_PKC1_MEM_CTRL_PWR_IG_SHIFT)) & SYSCON0_PKC1_MEM_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name CM33_MEM_DATA_CTRL - CPU0 Memory Data Control */
/*! @{ */

#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_STDBY_MASK (0x80U)
#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_STDBY_SHIFT (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_STDBY(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_CM33_MEM_DATA_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_CM33_MEM_DATA_CTRL_PWR_STDBY_MASK)

#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_IG_MASK   (0x100U)
#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_IG_SHIFT  (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_CM33_MEM_DATA_CTRL_PWR_IG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_CM33_MEM_DATA_CTRL_PWR_IG_SHIFT)) & SYSCON0_CM33_MEM_DATA_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name CM33_MEM_TAG_CTRL - CPU0 Memory Tag Control */
/*! @{ */

#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_STDBY_MASK (0x80U)
#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_STDBY_SHIFT (7U)
/*! PWR_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_STDBY(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON0_CM33_MEM_TAG_CTRL_PWR_STDBY_SHIFT)) & SYSCON0_CM33_MEM_TAG_CTRL_PWR_STDBY_MASK)

#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_IG_MASK    (0x100U)
#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_IG_SHIFT   (8U)
/*! PWR_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_CM33_MEM_TAG_CTRL_PWR_IG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_CM33_MEM_TAG_CTRL_PWR_IG_SHIFT)) & SYSCON0_CM33_MEM_TAG_CTRL_PWR_IG_MASK)
/*! @} */

/*! @name HIFI4_MEM_CTL - HiFi4 Memory Control */
/*! @{ */

#define SYSCON0_HIFI4_MEM_CTL_MEM_STDBY_MASK     (0x80U)
#define SYSCON0_HIFI4_MEM_CTL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_HIFI4_MEM_CTL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_MEM_CTL_MEM_STDBY_SHIFT)) & SYSCON0_HIFI4_MEM_CTL_MEM_STDBY_MASK)

#define SYSCON0_HIFI4_MEM_CTL_MEM_IG_MASK        (0x100U)
#define SYSCON0_HIFI4_MEM_CTL_MEM_IG_SHIFT       (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_HIFI4_MEM_CTL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_MEM_CTL_MEM_IG_SHIFT)) & SYSCON0_HIFI4_MEM_CTL_MEM_IG_MASK)
/*! @} */

/*! @name SAI0_MCLK_CTRL - SAI0-2 MCLK IO Direction Control */
/*! @{ */

#define SYSCON0_SAI0_MCLK_CTRL_SAIMCLKDIR_MASK   (0x1U)
#define SYSCON0_SAI0_MCLK_CTRL_SAIMCLKDIR_SHIFT  (0U)
/*! SAIMCLKDIR - SAI0-2 MCLK Direction Control
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCON0_SAI0_MCLK_CTRL_SAIMCLKDIR(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_SAI0_MCLK_CTRL_SAIMCLKDIR_SHIFT)) & SYSCON0_SAI0_MCLK_CTRL_SAIMCLKDIR_MASK)
/*! @} */

/*! @name XSPI0_TAG_MEM_CTRL - CACHE64_CTRL0 Tag Memory Control */
/*! @{ */

#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_STDBY_MASK (0x80U)
#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_STDBY_SHIFT (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_STDBY(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_IG_MASK   (0x100U)
#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_IG_SHIFT  (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_IG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_XSPI0_TAG_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name XSPI1_TAG_MEM_CTRL - CACHE64_CTRL1 Tag Memory Control */
/*! @{ */

#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_STDBY_MASK (0x80U)
#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_STDBY_SHIFT (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_STDBY(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_IG_MASK   (0x100U)
#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_IG_SHIFT  (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_IG(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON0_XSPI1_TAG_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name COMP_AUTOGATE_EN - VDD2_COMP Auto Gating Enable */
/*! @{ */

#define SYSCON0_COMP_AUTOGATE_EN_MBUS_EN_MASK    (0x1U)
#define SYSCON0_COMP_AUTOGATE_EN_MBUS_EN_SHIFT   (0U)
/*! MBUS_EN - Automatic Clock Gating Enable for M-bus
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON0_COMP_AUTOGATE_EN_MBUS_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_COMP_AUTOGATE_EN_MBUS_EN_SHIFT)) & SYSCON0_COMP_AUTOGATE_EN_MBUS_EN_MASK)

#define SYSCON0_COMP_AUTOGATE_EN_PBUS_EN_MASK    (0x2U)
#define SYSCON0_COMP_AUTOGATE_EN_PBUS_EN_SHIFT   (1U)
/*! PBUS_EN - Automatic Clock Gating Enable for P-bus
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON0_COMP_AUTOGATE_EN_PBUS_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_COMP_AUTOGATE_EN_PBUS_EN_SHIFT)) & SYSCON0_COMP_AUTOGATE_EN_PBUS_EN_MASK)

#define SYSCON0_COMP_AUTOGATE_EN_BRIDGE_EN_MASK  (0x4U)
#define SYSCON0_COMP_AUTOGATE_EN_BRIDGE_EN_SHIFT (2U)
/*! BRIDGE_EN - Automatic Clock Gating Enable for AHB2APB bridge, AIPS and AXBS
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON0_COMP_AUTOGATE_EN_BRIDGE_EN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_COMP_AUTOGATE_EN_BRIDGE_EN_SHIFT)) & SYSCON0_COMP_AUTOGATE_EN_BRIDGE_EN_MASK)
/*! @} */

/*! @name COMP_DEBUG_HALTED_SEL - VDD2_COMP Debug Halted Select */
/*! @{ */

#define SYSCON0_COMP_DEBUG_HALTED_SEL_WWDT1_SEL_MASK (0x1U)
#define SYSCON0_COMP_DEBUG_HALTED_SEL_WWDT1_SEL_SHIFT (0U)
/*! WWDT1_SEL - WWDT1 Select
 *  0b0..XOCD mode from HiFi4 will be used for WWDT1
 *  0b1..HALTED from CPU0 will be used for WWDT1
 */
#define SYSCON0_COMP_DEBUG_HALTED_SEL_WWDT1_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_COMP_DEBUG_HALTED_SEL_WWDT1_SEL_SHIFT)) & SYSCON0_COMP_DEBUG_HALTED_SEL_WWDT1_SEL_MASK)

#define SYSCON0_COMP_DEBUG_HALTED_SEL_CDOG2_SEL_MASK (0x2U)
#define SYSCON0_COMP_DEBUG_HALTED_SEL_CDOG2_SEL_SHIFT (1U)
/*! CDOG2_SEL - CDOG2 Select
 *  0b0..XOCD mode from HiFi4 will be used for CDOG2
 *  0b1..HALTED from CPU0 will be used for CDOG2
 */
#define SYSCON0_COMP_DEBUG_HALTED_SEL_CDOG2_SEL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_COMP_DEBUG_HALTED_SEL_CDOG2_SEL_SHIFT)) & SYSCON0_COMP_DEBUG_HALTED_SEL_CDOG2_SEL_MASK)
/*! @} */

/*! @name DSPSTALL - HiFi4 Stall */
/*! @{ */

#define SYSCON0_DSPSTALL_DSPSTALL_MASK           (0x1U)
#define SYSCON0_DSPSTALL_DSPSTALL_SHIFT          (0U)
/*! DSPSTALL - Run and Stall Control
 *  0b0..Run (normal mode)
 *  0b1..Stall mode
 */
#define SYSCON0_DSPSTALL_DSPSTALL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON0_DSPSTALL_DSPSTALL_SHIFT)) & SYSCON0_DSPSTALL_DSPSTALL_MASK)
/*! @} */

/*! @name OCDHALTONRESET - HiFi4 OCDHaltOnReset */
/*! @{ */

#define SYSCON0_OCDHALTONRESET_OCDHALTONRESET_MASK (0x1U)
#define SYSCON0_OCDHALTONRESET_OCDHALTONRESET_SHIFT (0U)
/*! OCDHALTONRESET - OCDHaltOnReset
 *  0b0..Allow normal operation when HiFi4 exits reset (starts fetching and executing instructions from memory)
 *  0b1..Force HiFi4 to enter OCD Halt mode when HiFi4 exits reset
 */
#define SYSCON0_OCDHALTONRESET_OCDHALTONRESET(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_OCDHALTONRESET_OCDHALTONRESET_SHIFT)) & SYSCON0_OCDHALTONRESET_OCDHALTONRESET_MASK)
/*! @} */

/*! @name HIFI4_GPR0 - HiFi4 General Purpose Register 0 */
/*! @{ */

#define SYSCON0_HIFI4_GPR0_PFAULTINFOVLD_MASK    (0x1U)
#define SYSCON0_HIFI4_GPR0_PFAULTINFOVLD_SHIFT   (0U)
/*! PFAULTINFOVLD - PFaultInfoValid
 *  0b0..Not asserted
 *  0b1..Asserted
 */
#define SYSCON0_HIFI4_GPR0_PFAULTINFOVLD(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_GPR0_PFAULTINFOVLD_SHIFT)) & SYSCON0_HIFI4_GPR0_PFAULTINFOVLD_MASK)

#define SYSCON0_HIFI4_GPR0_PFATALERR_MASK        (0x2U)
#define SYSCON0_HIFI4_GPR0_PFATALERR_SHIFT       (1U)
/*! PFATALERR - PFatalError
 *  0b0..No error occurs
 *  0b1..Error occurs
 */
#define SYSCON0_HIFI4_GPR0_PFATALERR(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_GPR0_PFATALERR_SHIFT)) & SYSCON0_HIFI4_GPR0_PFATALERR_MASK)

#define SYSCON0_HIFI4_GPR0_EXCEPTIONERR_MASK     (0x4U)
#define SYSCON0_HIFI4_GPR0_EXCEPTIONERR_SHIFT    (2U)
/*! EXCEPTIONERR - DoubleExceptionError
 *  0b0..No error occurs
 *  0b1..Error occurs
 */
#define SYSCON0_HIFI4_GPR0_EXCEPTIONERR(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_GPR0_EXCEPTIONERR_SHIFT)) & SYSCON0_HIFI4_GPR0_EXCEPTIONERR_MASK)
/*! @} */

/*! @name HIFI4_GPR1 - HiFi4 General Purpose Register 1 */
/*! @{ */

#define SYSCON0_HIFI4_GPR1_PFAULTINFO_MASK       (0xFFFFFFFFU)
#define SYSCON0_HIFI4_GPR1_PFAULTINFO_SHIFT      (0U)
/*! PFAULTINFO - PFaultInfo */
#define SYSCON0_HIFI4_GPR1_PFAULTINFO(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_GPR1_PFAULTINFO_SHIFT)) & SYSCON0_HIFI4_GPR1_PFAULTINFO_MASK)
/*! @} */

/*! @name HIFI4_GPR2 - HiFi4 General Purpose Register 2 */
/*! @{ */

#define SYSCON0_HIFI4_GPR2_TIE_EXPSTATE_MASK     (0xFFFFFFFFU)
#define SYSCON0_HIFI4_GPR2_TIE_EXPSTATE_SHIFT    (0U)
/*! TIE_EXPSTATE - GPIO32 Option TIE Output State */
#define SYSCON0_HIFI4_GPR2_TIE_EXPSTATE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_HIFI4_GPR2_TIE_EXPSTATE_SHIFT)) & SYSCON0_HIFI4_GPR2_TIE_EXPSTATE_MASK)
/*! @} */

/*! @name DSP_VECT_REMAP - HiFi4 DSP Vector Remap */
/*! @{ */

#define SYSCON0_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK (0x1FFFU)
#define SYSCON0_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT (0U)
/*! DSP_VECT_REMAP - DSP Vector Remap */
#define SYSCON0_DSP_VECT_REMAP_DSP_VECT_REMAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_DSP_VECT_REMAP_DSP_VECT_REMAP_SHIFT)) & SYSCON0_DSP_VECT_REMAP_DSP_VECT_REMAP_MASK)

#define SYSCON0_DSP_VECT_REMAP_STATVECSELECT_MASK (0x2000U)
#define SYSCON0_DSP_VECT_REMAP_STATVECSELECT_SHIFT (13U)
/*! STATVECSELECT - HiFi4 Remap Function Enable
 *  0b0..Remap function disabled
 *  0b1..Remap function enabled
 */
#define SYSCON0_DSP_VECT_REMAP_STATVECSELECT(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_DSP_VECT_REMAP_STATVECSELECT_SHIFT)) & SYSCON0_DSP_VECT_REMAP_STATVECSELECT_MASK)
/*! @} */

/*! @name EDMA0_EN0 - eDMA0 Request Enable 0 */
/*! @{ */

#define SYSCON0_EDMA0_EN0_MICFIL_EN_MASK         (0x2U)
#define SYSCON0_EDMA0_EN0_MICFIL_EN_SHIFT        (1U)
/*! MICFIL_EN - MICFIL Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_MICFIL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_MICFIL_EN_SHIFT)) & SYSCON0_EDMA0_EN0_MICFIL_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI0_RX_EN_MASK       (0x4U)
#define SYSCON0_EDMA0_EN0_XSPI0_RX_EN_SHIFT      (2U)
/*! XSPI0_RX_EN - XSPI0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI0_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI0_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI0_RX_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI0_TX_EN_MASK       (0x8U)
#define SYSCON0_EDMA0_EN0_XSPI0_TX_EN_SHIFT      (3U)
/*! XSPI0_TX_EN - XSPI0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI0_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI0_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI0_TX_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI1_RX_EN_MASK       (0x10U)
#define SYSCON0_EDMA0_EN0_XSPI1_RX_EN_SHIFT      (4U)
/*! XSPI1_RX_EN - XSPI1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI1_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI1_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI1_RX_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI1_TX_EN_MASK       (0x20U)
#define SYSCON0_EDMA0_EN0_XSPI1_TX_EN_SHIFT      (5U)
/*! XSPI1_TX_EN - XSPI1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI1_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI1_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI1_TX_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI2_RX_EN_MASK       (0x40U)
#define SYSCON0_EDMA0_EN0_XSPI2_RX_EN_SHIFT      (6U)
/*! XSPI2_RX_EN - XSPI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI2_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI2_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI2_RX_EN_MASK)

#define SYSCON0_EDMA0_EN0_XSPI2_TX_EN_MASK       (0x80U)
#define SYSCON0_EDMA0_EN0_XSPI2_TX_EN_SHIFT      (7U)
/*! XSPI2_TX_EN - XSPI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_XSPI2_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_XSPI2_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN0_XSPI2_TX_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ0_EN_MASK     (0x100U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ0_EN_SHIFT    (8U)
/*! PINT0_IRQ0_EN - PINT0 Interrupt 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ0_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ1_EN_MASK     (0x200U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ1_EN_SHIFT    (9U)
/*! PINT0_IRQ1_EN - PINT0 Interrupt 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ1_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ2_EN_MASK     (0x400U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ2_EN_SHIFT    (10U)
/*! PINT0_IRQ2_EN - PINT0 Interrupt 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ2_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ2_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ2_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ3_EN_MASK     (0x800U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ3_EN_SHIFT    (11U)
/*! PINT0_IRQ3_EN - PINT0 Interrupt 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ3_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ3_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ3_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ4_EN_MASK     (0x1000U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ4_EN_SHIFT    (12U)
/*! PINT0_IRQ4_EN - PINT0 Interrupt 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ4_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ4_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ4_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ5_EN_MASK     (0x2000U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ5_EN_SHIFT    (13U)
/*! PINT0_IRQ5_EN - PINT0 Interrupt 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ5_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ5_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ5_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ6_EN_MASK     (0x4000U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ6_EN_SHIFT    (14U)
/*! PINT0_IRQ6_EN - PINT0 Interrupt 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ6_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ6_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ6_EN_MASK)

#define SYSCON0_EDMA0_EN0_PINT0_IRQ7_EN_MASK     (0x8000U)
#define SYSCON0_EDMA0_EN0_PINT0_IRQ7_EN_SHIFT    (15U)
/*! PINT0_IRQ7_EN - PINT0 Interrupt 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_PINT0_IRQ7_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_PINT0_IRQ7_EN_SHIFT)) & SYSCON0_EDMA0_EN0_PINT0_IRQ7_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER0_M0_EN_MASK     (0x10000U)
#define SYSCON0_EDMA0_EN0_CTIMER0_M0_EN_SHIFT    (16U)
/*! CTIMER0_M0_EN - CTIMER0 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER0_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER0_M0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER0_M0_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER0_M1_EN_MASK     (0x20000U)
#define SYSCON0_EDMA0_EN0_CTIMER0_M1_EN_SHIFT    (17U)
/*! CTIMER0_M1_EN - CTIMER0 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER0_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER0_M1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER0_M1_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER1_M0_EN_MASK     (0x40000U)
#define SYSCON0_EDMA0_EN0_CTIMER1_M0_EN_SHIFT    (18U)
/*! CTIMER1_M0_EN - CTIMER1 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER1_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER1_M0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER1_M0_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER1_M1_EN_MASK     (0x80000U)
#define SYSCON0_EDMA0_EN0_CTIMER1_M1_EN_SHIFT    (19U)
/*! CTIMER1_M1_EN - CTIMER1 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER1_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER1_M1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER1_M1_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER2_M0_EN_MASK     (0x100000U)
#define SYSCON0_EDMA0_EN0_CTIMER2_M0_EN_SHIFT    (20U)
/*! CTIMER2_M0_EN - CTIMER2 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER2_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER2_M0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER2_M0_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER2_M1_EN_MASK     (0x200000U)
#define SYSCON0_EDMA0_EN0_CTIMER2_M1_EN_SHIFT    (21U)
/*! CTIMER2_M1_EN - CTIMER2 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER2_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER2_M1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER2_M1_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER3_M0_EN_MASK     (0x400000U)
#define SYSCON0_EDMA0_EN0_CTIMER3_M0_EN_SHIFT    (22U)
/*! CTIMER3_M0_EN - CTIMER3 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER3_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER3_M0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER3_M0_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER3_M1_EN_MASK     (0x800000U)
#define SYSCON0_EDMA0_EN0_CTIMER3_M1_EN_SHIFT    (23U)
/*! CTIMER3_M1_EN - CTIMER3 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER3_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER3_M1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER3_M1_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER4_M0_EN_MASK     (0x1000000U)
#define SYSCON0_EDMA0_EN0_CTIMER4_M0_EN_SHIFT    (24U)
/*! CTIMER4_M0_EN - CTIMER4 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER4_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER4_M0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER4_M0_EN_MASK)

#define SYSCON0_EDMA0_EN0_CTIMER4_M1_EN_MASK     (0x2000000U)
#define SYSCON0_EDMA0_EN0_CTIMER4_M1_EN_SHIFT    (25U)
/*! CTIMER4_M1_EN - CTIMER4 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_CTIMER4_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_CTIMER4_M1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_CTIMER4_M1_EN_MASK)

#define SYSCON0_EDMA0_EN0_SCT0_DMAA_EN_MASK      (0x4000000U)
#define SYSCON0_EDMA0_EN0_SCT0_DMAA_EN_SHIFT     (26U)
/*! SCT0_DMAA_EN - SCT0 DMA A Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_SCT0_DMAA_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_SCT0_DMAA_EN_SHIFT)) & SYSCON0_EDMA0_EN0_SCT0_DMAA_EN_MASK)

#define SYSCON0_EDMA0_EN0_SCT0_DMAB_EN_MASK      (0x8000000U)
#define SYSCON0_EDMA0_EN0_SCT0_DMAB_EN_SHIFT     (27U)
/*! SCT0_DMAB_EN - SCT0 DMA B Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_SCT0_DMAB_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_SCT0_DMAB_EN_SHIFT)) & SYSCON0_EDMA0_EN0_SCT0_DMAB_EN_MASK)

#define SYSCON0_EDMA0_EN0_ADC0_FIFO0_EN_MASK     (0x10000000U)
#define SYSCON0_EDMA0_EN0_ADC0_FIFO0_EN_SHIFT    (28U)
/*! ADC0_FIFO0_EN - ADC0 FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_ADC0_FIFO0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_ADC0_FIFO0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_ADC0_FIFO0_EN_MASK)

#define SYSCON0_EDMA0_EN0_ADC0_FIFO1_EN_MASK     (0x20000000U)
#define SYSCON0_EDMA0_EN0_ADC0_FIFO1_EN_SHIFT    (29U)
/*! ADC0_FIFO1_EN - ADC0 FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_ADC0_FIFO1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_ADC0_FIFO1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_ADC0_FIFO1_EN_MASK)

#define SYSCON0_EDMA0_EN0_SDADC_FIFO0_EN_MASK    (0x40000000U)
#define SYSCON0_EDMA0_EN0_SDADC_FIFO0_EN_SHIFT   (30U)
/*! SDADC_FIFO0_EN - SDADC FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_SDADC_FIFO0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_SDADC_FIFO0_EN_SHIFT)) & SYSCON0_EDMA0_EN0_SDADC_FIFO0_EN_MASK)

#define SYSCON0_EDMA0_EN0_SDADC_FIFO1_EN_MASK    (0x80000000U)
#define SYSCON0_EDMA0_EN0_SDADC_FIFO1_EN_SHIFT   (31U)
/*! SDADC_FIFO1_EN - SDADC FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN0_SDADC_FIFO1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN0_SDADC_FIFO1_EN_SHIFT)) & SYSCON0_EDMA0_EN0_SDADC_FIFO1_EN_MASK)
/*! @} */

/*! @name EDMA0_EN1 - eDMA0 Request Enable 1 */
/*! @{ */

#define SYSCON0_EDMA0_EN1_SDADC_FIFO2_EN_MASK    (0x1U)
#define SYSCON0_EDMA0_EN1_SDADC_FIFO2_EN_SHIFT   (0U)
/*! SDADC_FIFO2_EN - SDADC FIFO2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_SDADC_FIFO2_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_SDADC_FIFO2_EN_SHIFT)) & SYSCON0_EDMA0_EN1_SDADC_FIFO2_EN_MASK)

#define SYSCON0_EDMA0_EN1_SDADC_FIFO3_EN_MASK    (0x2U)
#define SYSCON0_EDMA0_EN1_SDADC_FIFO3_EN_SHIFT   (1U)
/*! SDADC_FIFO3_EN - SDADC FIFO3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_SDADC_FIFO3_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_SDADC_FIFO3_EN_SHIFT)) & SYSCON0_EDMA0_EN1_SDADC_FIFO3_EN_MASK)

#define SYSCON0_EDMA0_EN1_ACMP_EN_MASK           (0x4U)
#define SYSCON0_EDMA0_EN1_ACMP_EN_SHIFT          (2U)
/*! ACMP_EN - ACMP0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_ACMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_ACMP_EN_SHIFT)) & SYSCON0_EDMA0_EN1_ACMP_EN_MASK)

#define SYSCON0_EDMA0_EN1_ITRC_TAMPER0_EN_MASK   (0x8U)
#define SYSCON0_EDMA0_EN1_ITRC_TAMPER0_EN_SHIFT  (3U)
/*! ITRC_TAMPER0_EN - ITRC Tamper 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_ITRC_TAMPER0_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_ITRC_TAMPER0_EN_SHIFT)) & SYSCON0_EDMA0_EN1_ITRC_TAMPER0_EN_MASK)

#define SYSCON0_EDMA0_EN1_ITRC_TAMPER1_EN_MASK   (0x10U)
#define SYSCON0_EDMA0_EN1_ITRC_TAMPER1_EN_SHIFT  (4U)
/*! ITRC_TAMPER1_EN - ITRC Tamper 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_ITRC_TAMPER1_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_ITRC_TAMPER1_EN_SHIFT)) & SYSCON0_EDMA0_EN1_ITRC_TAMPER1_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER0_EN_MASK (0x20U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER0_EN_SHIFT (5U)
/*! FLEXIO_SHFT_TIMER0_EN - FLEXIO Shift Timer 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER0_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER0_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER0_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER1_EN_MASK (0x40U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER1_EN_SHIFT (6U)
/*! FLEXIO_SHFT_TIMER1_EN - FLEXIO Shift Timer 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER1_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER1_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER1_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER2_EN_MASK (0x80U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER2_EN_SHIFT (7U)
/*! FLEXIO_SHFT_TIMER2_EN - FLEXIO Shift Timer 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER2_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER2_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER2_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER3_EN_MASK (0x100U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER3_EN_SHIFT (8U)
/*! FLEXIO_SHFT_TIMER3_EN - FLEXIO Shift Timer 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER3_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER3_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER3_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER4_EN_MASK (0x200U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER4_EN_SHIFT (9U)
/*! FLEXIO_SHFT_TIMER4_EN - FLEXIO Shift Timer 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER4_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER4_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER4_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER5_EN_MASK (0x400U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER5_EN_SHIFT (10U)
/*! FLEXIO_SHFT_TIMER5_EN - FLEXIO Shift Timer 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER5_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER5_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER5_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER6_EN_MASK (0x800U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER6_EN_SHIFT (11U)
/*! FLEXIO_SHFT_TIMER6_EN - FLEXIO Shift Timer 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER6_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER6_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER6_EN_MASK)

#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER7_EN_MASK (0x1000U)
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER7_EN_SHIFT (12U)
/*! FLEXIO_SHFT_TIMER7_EN - FLEXIO Shift Timer 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER7_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER7_EN_SHIFT)) & SYSCON0_EDMA0_EN1_FLEXIO_SHFT_TIMER7_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_RX_EN_MASK (0x2000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_RX_EN_SHIFT (13U)
/*! LP_FLEXCOMM0_RX_EN - LP_FLEXCOMM0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_TX_EN_MASK (0x4000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_TX_EN_SHIFT (14U)
/*! LP_FLEXCOMM0_TX_EN - LP_FLEXCOMM0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM0_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_RX_EN_MASK (0x8000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_RX_EN_SHIFT (15U)
/*! LP_FLEXCOMM1_RX_EN - LP_FLEXCOMM1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_TX_EN_MASK (0x10000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_TX_EN_SHIFT (16U)
/*! LP_FLEXCOMM1_TX_EN - LP_FLEXCOMM1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM1_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_RX_EN_MASK (0x20000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_RX_EN_SHIFT (17U)
/*! LP_FLEXCOMM2_RX_EN - LP_FLEXCOMM2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_TX_EN_MASK (0x40000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_TX_EN_SHIFT (18U)
/*! LP_FLEXCOMM2_TX_EN - LP_FLEXCOMM2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM2_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_RX_EN_MASK (0x80000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_RX_EN_SHIFT (19U)
/*! LP_FLEXCOMM3_RX_EN - LP_FLEXCOMM3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_TX_EN_MASK (0x100000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_TX_EN_SHIFT (20U)
/*! LP_FLEXCOMM3_TX_EN - LP_FLEXCOMM3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM3_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_RX_EN_MASK (0x200000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_RX_EN_SHIFT (21U)
/*! LP_FLEXCOMM4_RX_EN - LP_FLEXCOMM4 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_TX_EN_MASK (0x400000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_TX_EN_SHIFT (22U)
/*! LP_FLEXCOMM4_TX_EN - LP_FLEXCOMM4 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM4_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_RX_EN_MASK (0x800000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_RX_EN_SHIFT (23U)
/*! LP_FLEXCOMM5_RX_EN - LP_FLEXCOMM5 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_TX_EN_MASK (0x1000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_TX_EN_SHIFT (24U)
/*! LP_FLEXCOMM5_TX_EN - LP_FLEXCOMM5 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM5_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_RX_EN_MASK (0x2000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_RX_EN_SHIFT (25U)
/*! LP_FLEXCOMM6_RX_EN - LP_FLEXCOMM6 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_TX_EN_MASK (0x4000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_TX_EN_SHIFT (26U)
/*! LP_FLEXCOMM6_TX_EN - LP_FLEXCOMM6 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM6_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_RX_EN_MASK (0x8000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_RX_EN_SHIFT (27U)
/*! LP_FLEXCOMM7_RX_EN - LP_FLEXCOMM7 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_TX_EN_MASK (0x10000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_TX_EN_SHIFT (28U)
/*! LP_FLEXCOMM7_TX_EN - LP_FLEXCOMM7 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM7_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_RX_EN_MASK (0x20000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_RX_EN_SHIFT (29U)
/*! LP_FLEXCOMM8_RX_EN - LP_FLEXCOMM8 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_RX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_TX_EN_MASK (0x40000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_TX_EN_SHIFT (30U)
/*! LP_FLEXCOMM8_TX_EN - LP_FLEXCOMM8 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM8_TX_EN_MASK)

#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM9_RX_EN_MASK (0x80000000U)
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM9_RX_EN_SHIFT (31U)
/*! LP_FLEXCOMM9_RX_EN - LP_FLEXCOMM9 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN1_LP_FLEXCOMM9_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN1_LP_FLEXCOMM9_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN1_LP_FLEXCOMM9_RX_EN_MASK)
/*! @} */

/*! @name EDMA0_EN2 - eDMA0 Request Enable 2 */
/*! @{ */

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM9_TX_EN_MASK (0x1U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM9_TX_EN_SHIFT (0U)
/*! LP_FLEXCOMM9_TX_EN - LP_FLEXCOMM9 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM9_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM9_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM9_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_RX_EN_MASK (0x2U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_RX_EN_SHIFT (1U)
/*! LP_FLEXCOMM10_RX_EN - LP_FLEXCOMM10 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_TX_EN_MASK (0x4U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_TX_EN_SHIFT (2U)
/*! LP_FLEXCOMM10_TX_EN - LP_FLEXCOMM10 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM10_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_RX_EN_MASK (0x8U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_RX_EN_SHIFT (3U)
/*! LP_FLEXCOMM11_RX_EN - LP_FLEXCOMM11 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_TX_EN_MASK (0x10U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_TX_EN_SHIFT (4U)
/*! LP_FLEXCOMM11_TX_EN - LP_FLEXCOMM11 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM11_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_RX_EN_MASK (0x20U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_RX_EN_SHIFT (5U)
/*! LP_FLEXCOMM12_RX_EN - LP_FLEXCOMM12 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_TX_EN_MASK (0x40U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_TX_EN_SHIFT (6U)
/*! LP_FLEXCOMM12_TX_EN - LP_FLEXCOMM12 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM12_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_RX_EN_MASK (0x80U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_RX_EN_SHIFT (7U)
/*! LP_FLEXCOMM13_RX_EN - LP_FLEXCOMM13 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_TX_EN_MASK (0x100U)
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_TX_EN_SHIFT (8U)
/*! LP_FLEXCOMM13_TX_EN - LP_FLEXCOMM13 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LP_FLEXCOMM13_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LPSPI14_RX_EN_MASK     (0x200U)
#define SYSCON0_EDMA0_EN2_LPSPI14_RX_EN_SHIFT    (9U)
/*! LPSPI14_RX_EN - LPSPI14 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LPSPI14_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LPSPI14_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LPSPI14_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LPSPI14_TX_EN_MASK     (0x400U)
#define SYSCON0_EDMA0_EN2_LPSPI14_TX_EN_SHIFT    (10U)
/*! LPSPI14_TX_EN - LPSPI14 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LPSPI14_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LPSPI14_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LPSPI14_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LPSPI16_RX_EN_MASK     (0x800U)
#define SYSCON0_EDMA0_EN2_LPSPI16_RX_EN_SHIFT    (11U)
/*! LPSPI16_RX_EN - LPSPI16 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LPSPI16_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LPSPI16_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LPSPI16_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_LPSPI16_TX_EN_MASK     (0x1000U)
#define SYSCON0_EDMA0_EN2_LPSPI16_TX_EN_SHIFT    (12U)
/*! LPSPI16_TX_EN - LPSPI16 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_LPSPI16_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_LPSPI16_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_LPSPI16_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_I3C0_RX_EN_MASK        (0x2000U)
#define SYSCON0_EDMA0_EN2_I3C0_RX_EN_SHIFT       (13U)
/*! I3C0_RX_EN - I3C0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_I3C0_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_I3C0_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_I3C0_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_I3C0_TX_EN_MASK        (0x4000U)
#define SYSCON0_EDMA0_EN2_I3C0_TX_EN_SHIFT       (14U)
/*! I3C0_TX_EN - I3C0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_I3C0_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_I3C0_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_I3C0_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_I3C1_RX_EN_MASK        (0x8000U)
#define SYSCON0_EDMA0_EN2_I3C1_RX_EN_SHIFT       (15U)
/*! I3C1_RX_EN - I3C1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_I3C1_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_I3C1_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_I3C1_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_I3C1_TX_EN_MASK        (0x10000U)
#define SYSCON0_EDMA0_EN2_I3C1_TX_EN_SHIFT       (16U)
/*! I3C1_TX_EN - I3C1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_I3C1_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_I3C1_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_I3C1_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI0_RX_EN_MASK        (0x20000U)
#define SYSCON0_EDMA0_EN2_SAI0_RX_EN_SHIFT       (17U)
/*! SAI0_RX_EN - SAI0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI0_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI0_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI0_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI0_TX_EN_MASK        (0x40000U)
#define SYSCON0_EDMA0_EN2_SAI0_TX_EN_SHIFT       (18U)
/*! SAI0_TX_EN - SAI0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI0_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI0_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI0_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI1_RX_EN_MASK        (0x80000U)
#define SYSCON0_EDMA0_EN2_SAI1_RX_EN_SHIFT       (19U)
/*! SAI1_RX_EN - SAI1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI1_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI1_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI1_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI1_TX_EN_MASK        (0x100000U)
#define SYSCON0_EDMA0_EN2_SAI1_TX_EN_SHIFT       (20U)
/*! SAI1_TX_EN - SAI1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI1_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI1_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI1_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI2_RX_EN_MASK        (0x200000U)
#define SYSCON0_EDMA0_EN2_SAI2_RX_EN_SHIFT       (21U)
/*! SAI2_RX_EN - SAI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI2_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI2_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI2_RX_EN_MASK)

#define SYSCON0_EDMA0_EN2_SAI2_TX_EN_MASK        (0x400000U)
#define SYSCON0_EDMA0_EN2_SAI2_TX_EN_SHIFT       (22U)
/*! SAI2_TX_EN - SAI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_SAI2_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_SAI2_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN2_SAI2_TX_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO0_DMA0_EN_MASK     (0x800000U)
#define SYSCON0_EDMA0_EN2_GPIO0_DMA0_EN_SHIFT    (23U)
/*! GPIO0_DMA0_EN - GPIO0 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO0_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO0_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO0_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO0_DMA1_EN_MASK     (0x1000000U)
#define SYSCON0_EDMA0_EN2_GPIO0_DMA1_EN_SHIFT    (24U)
/*! GPIO0_DMA1_EN - GPIO0 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO0_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO0_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO0_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO1_DMA0_EN_MASK     (0x2000000U)
#define SYSCON0_EDMA0_EN2_GPIO1_DMA0_EN_SHIFT    (25U)
/*! GPIO1_DMA0_EN - GPIO1 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO1_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO1_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO1_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO1_DMA1_EN_MASK     (0x4000000U)
#define SYSCON0_EDMA0_EN2_GPIO1_DMA1_EN_SHIFT    (26U)
/*! GPIO1_DMA1_EN - GPIO1 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO1_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO1_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO1_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO2_DMA0_EN_MASK     (0x8000000U)
#define SYSCON0_EDMA0_EN2_GPIO2_DMA0_EN_SHIFT    (27U)
/*! GPIO2_DMA0_EN - GPIO2 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO2_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO2_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO2_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO2_DMA1_EN_MASK     (0x10000000U)
#define SYSCON0_EDMA0_EN2_GPIO2_DMA1_EN_SHIFT    (28U)
/*! GPIO2_DMA1_EN - GPIO2 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO2_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO2_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO2_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO3_DMA0_EN_MASK     (0x20000000U)
#define SYSCON0_EDMA0_EN2_GPIO3_DMA0_EN_SHIFT    (29U)
/*! GPIO3_DMA0_EN - GPIO3 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO3_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO3_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO3_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO3_DMA1_EN_MASK     (0x40000000U)
#define SYSCON0_EDMA0_EN2_GPIO3_DMA1_EN_SHIFT    (30U)
/*! GPIO3_DMA1_EN - GPIO3 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO3_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO3_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO3_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN2_GPIO4_DMA0_EN_MASK     (0x80000000U)
#define SYSCON0_EDMA0_EN2_GPIO4_DMA0_EN_SHIFT    (31U)
/*! GPIO4_DMA0_EN - GPIO4 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN2_GPIO4_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN2_GPIO4_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN2_GPIO4_DMA0_EN_MASK)
/*! @} */

/*! @name EDMA0_EN3 - eDMA0 Request Enable 3 */
/*! @{ */

#define SYSCON0_EDMA0_EN3_GPIO4_DMA1_EN_MASK     (0x1U)
#define SYSCON0_EDMA0_EN3_GPIO4_DMA1_EN_SHIFT    (0U)
/*! GPIO4_DMA1_EN - GPIO4 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO4_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO4_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO4_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO5_DMA0_EN_MASK     (0x2U)
#define SYSCON0_EDMA0_EN3_GPIO5_DMA0_EN_SHIFT    (1U)
/*! GPIO5_DMA0_EN - GPIO5 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO5_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO5_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO5_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO5_DMA1_EN_MASK     (0x4U)
#define SYSCON0_EDMA0_EN3_GPIO5_DMA1_EN_SHIFT    (2U)
/*! GPIO5_DMA1_EN - GPIO5 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO5_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO5_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO5_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO6_DMA0_EN_MASK     (0x8U)
#define SYSCON0_EDMA0_EN3_GPIO6_DMA0_EN_SHIFT    (3U)
/*! GPIO6_DMA0_EN - GPIO6 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO6_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO6_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO6_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO6_DMA1_EN_MASK     (0x10U)
#define SYSCON0_EDMA0_EN3_GPIO6_DMA1_EN_SHIFT    (4U)
/*! GPIO6_DMA1_EN - GPIO6 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO6_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO6_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO6_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO7_DMA0_EN_MASK     (0x20U)
#define SYSCON0_EDMA0_EN3_GPIO7_DMA0_EN_SHIFT    (5U)
/*! GPIO7_DMA0_EN - GPIO7 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO7_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO7_DMA0_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO7_DMA0_EN_MASK)

#define SYSCON0_EDMA0_EN3_GPIO7_DMA1_EN_MASK     (0x40U)
#define SYSCON0_EDMA0_EN3_GPIO7_DMA1_EN_SHIFT    (6U)
/*! GPIO7_DMA1_EN - GPIO7 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_GPIO7_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_GPIO7_DMA1_EN_SHIFT)) & SYSCON0_EDMA0_EN3_GPIO7_DMA1_EN_MASK)

#define SYSCON0_EDMA0_EN3_LPI2C15_RX_EN_MASK     (0x80U)
#define SYSCON0_EDMA0_EN3_LPI2C15_RX_EN_SHIFT    (7U)
/*! LPI2C15_RX_EN - LPI2C15 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_LPI2C15_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_LPI2C15_RX_EN_SHIFT)) & SYSCON0_EDMA0_EN3_LPI2C15_RX_EN_MASK)

#define SYSCON0_EDMA0_EN3_LPI2C15_TX_EN_MASK     (0x100U)
#define SYSCON0_EDMA0_EN3_LPI2C15_TX_EN_SHIFT    (8U)
/*! LPI2C15_TX_EN - LPI2C15 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA0_EN3_LPI2C15_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA0_EN3_LPI2C15_TX_EN_SHIFT)) & SYSCON0_EDMA0_EN3_LPI2C15_TX_EN_MASK)
/*! @} */

/*! @name EDMA1_EN0 - eDMA1 Request Enable 0 */
/*! @{ */

#define SYSCON0_EDMA1_EN0_MICFIL_EN_MASK         (0x2U)
#define SYSCON0_EDMA1_EN0_MICFIL_EN_SHIFT        (1U)
/*! MICFIL_EN - MICFIL Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_MICFIL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_MICFIL_EN_SHIFT)) & SYSCON0_EDMA1_EN0_MICFIL_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI0_RX_EN_MASK       (0x4U)
#define SYSCON0_EDMA1_EN0_XSPI0_RX_EN_SHIFT      (2U)
/*! XSPI0_RX_EN - XSPI0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI0_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI0_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI0_RX_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI0_TX_EN_MASK       (0x8U)
#define SYSCON0_EDMA1_EN0_XSPI0_TX_EN_SHIFT      (3U)
/*! XSPI0_TX_EN - XSPI0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI0_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI0_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI0_TX_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI1_RX_EN_MASK       (0x10U)
#define SYSCON0_EDMA1_EN0_XSPI1_RX_EN_SHIFT      (4U)
/*! XSPI1_RX_EN - XSPI1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI1_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI1_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI1_RX_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI1_TX_EN_MASK       (0x20U)
#define SYSCON0_EDMA1_EN0_XSPI1_TX_EN_SHIFT      (5U)
/*! XSPI1_TX_EN - XSPI1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI1_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI1_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI1_TX_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI2_RX_EN_MASK       (0x40U)
#define SYSCON0_EDMA1_EN0_XSPI2_RX_EN_SHIFT      (6U)
/*! XSPI2_RX_EN - XSPI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI2_RX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI2_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI2_RX_EN_MASK)

#define SYSCON0_EDMA1_EN0_XSPI2_TX_EN_MASK       (0x80U)
#define SYSCON0_EDMA1_EN0_XSPI2_TX_EN_SHIFT      (7U)
/*! XSPI2_TX_EN - XSPI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_XSPI2_TX_EN(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_XSPI2_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN0_XSPI2_TX_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ0_EN_MASK     (0x100U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ0_EN_SHIFT    (8U)
/*! PINT0_IRQ0_EN - PINT0 Interrupt 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ0_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ1_EN_MASK     (0x200U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ1_EN_SHIFT    (9U)
/*! PINT0_IRQ1_EN - PINT0 Interrupt 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ1_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ2_EN_MASK     (0x400U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ2_EN_SHIFT    (10U)
/*! PINT0_IRQ2_EN - PINT0 Interrupt 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ2_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ2_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ2_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ3_EN_MASK     (0x800U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ3_EN_SHIFT    (11U)
/*! PINT0_IRQ3_EN - PINT0 Interrupt 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ3_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ3_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ3_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ4_EN_MASK     (0x1000U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ4_EN_SHIFT    (12U)
/*! PINT0_IRQ4_EN - PINT0 Interrupt 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ4_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ4_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ4_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ5_EN_MASK     (0x2000U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ5_EN_SHIFT    (13U)
/*! PINT0_IRQ5_EN - PINT0 Interrupt 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ5_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ5_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ5_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ6_EN_MASK     (0x4000U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ6_EN_SHIFT    (14U)
/*! PINT0_IRQ6_EN - PINT0 Interrupt 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ6_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ6_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ6_EN_MASK)

#define SYSCON0_EDMA1_EN0_PINT0_IRQ7_EN_MASK     (0x8000U)
#define SYSCON0_EDMA1_EN0_PINT0_IRQ7_EN_SHIFT    (15U)
/*! PINT0_IRQ7_EN - PINT0 Interrupt 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_PINT0_IRQ7_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_PINT0_IRQ7_EN_SHIFT)) & SYSCON0_EDMA1_EN0_PINT0_IRQ7_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER0_M0_EN_MASK     (0x10000U)
#define SYSCON0_EDMA1_EN0_CTIMER0_M0_EN_SHIFT    (16U)
/*! CTIMER0_M0_EN - CTIMER0 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER0_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER0_M0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER0_M0_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER0_M1_EN_MASK     (0x20000U)
#define SYSCON0_EDMA1_EN0_CTIMER0_M1_EN_SHIFT    (17U)
/*! CTIMER0_M1_EN - CTIMER0 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER0_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER0_M1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER0_M1_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER1_M0_EN_MASK     (0x40000U)
#define SYSCON0_EDMA1_EN0_CTIMER1_M0_EN_SHIFT    (18U)
/*! CTIMER1_M0_EN - CTIMER1 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER1_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER1_M0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER1_M0_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER1_M1_EN_MASK     (0x80000U)
#define SYSCON0_EDMA1_EN0_CTIMER1_M1_EN_SHIFT    (19U)
/*! CTIMER1_M1_EN - CTIMER1 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER1_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER1_M1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER1_M1_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER2_M0_EN_MASK     (0x100000U)
#define SYSCON0_EDMA1_EN0_CTIMER2_M0_EN_SHIFT    (20U)
/*! CTIMER2_M0_EN - CTIMER2 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER2_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER2_M0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER2_M0_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER2_M1_EN_MASK     (0x200000U)
#define SYSCON0_EDMA1_EN0_CTIMER2_M1_EN_SHIFT    (21U)
/*! CTIMER2_M1_EN - CTIMER2 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER2_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER2_M1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER2_M1_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER3_M0_EN_MASK     (0x400000U)
#define SYSCON0_EDMA1_EN0_CTIMER3_M0_EN_SHIFT    (22U)
/*! CTIMER3_M0_EN - CTIMER3 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER3_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER3_M0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER3_M0_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER3_M1_EN_MASK     (0x800000U)
#define SYSCON0_EDMA1_EN0_CTIMER3_M1_EN_SHIFT    (23U)
/*! CTIMER3_M1_EN - CTIMER3 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER3_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER3_M1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER3_M1_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER4_M0_EN_MASK     (0x1000000U)
#define SYSCON0_EDMA1_EN0_CTIMER4_M0_EN_SHIFT    (24U)
/*! CTIMER4_M0_EN - CTIMER4 M0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER4_M0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER4_M0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER4_M0_EN_MASK)

#define SYSCON0_EDMA1_EN0_CTIMER4_M1_EN_MASK     (0x2000000U)
#define SYSCON0_EDMA1_EN0_CTIMER4_M1_EN_SHIFT    (25U)
/*! CTIMER4_M1_EN - CTIMER4 M1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_CTIMER4_M1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_CTIMER4_M1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_CTIMER4_M1_EN_MASK)

#define SYSCON0_EDMA1_EN0_SCT0_DMAA_EN_MASK      (0x4000000U)
#define SYSCON0_EDMA1_EN0_SCT0_DMAA_EN_SHIFT     (26U)
/*! SCT0_DMAA_EN - SCT0 DMA A Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_SCT0_DMAA_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_SCT0_DMAA_EN_SHIFT)) & SYSCON0_EDMA1_EN0_SCT0_DMAA_EN_MASK)

#define SYSCON0_EDMA1_EN0_SCT0_DMAB_EN_MASK      (0x8000000U)
#define SYSCON0_EDMA1_EN0_SCT0_DMAB_EN_SHIFT     (27U)
/*! SCT0_DMAB_EN - SCT0 DMA B Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_SCT0_DMAB_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_SCT0_DMAB_EN_SHIFT)) & SYSCON0_EDMA1_EN0_SCT0_DMAB_EN_MASK)

#define SYSCON0_EDMA1_EN0_ADC0_FIFO0_EN_MASK     (0x10000000U)
#define SYSCON0_EDMA1_EN0_ADC0_FIFO0_EN_SHIFT    (28U)
/*! ADC0_FIFO0_EN - ADC0 FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_ADC0_FIFO0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_ADC0_FIFO0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_ADC0_FIFO0_EN_MASK)

#define SYSCON0_EDMA1_EN0_ADC0_FIFO1_EN_MASK     (0x20000000U)
#define SYSCON0_EDMA1_EN0_ADC0_FIFO1_EN_SHIFT    (29U)
/*! ADC0_FIFO1_EN - ADC0 FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_ADC0_FIFO1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_ADC0_FIFO1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_ADC0_FIFO1_EN_MASK)

#define SYSCON0_EDMA1_EN0_SDADC_FIFO0_EN_MASK    (0x40000000U)
#define SYSCON0_EDMA1_EN0_SDADC_FIFO0_EN_SHIFT   (30U)
/*! SDADC_FIFO0_EN - SDADC FIFO0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_SDADC_FIFO0_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_SDADC_FIFO0_EN_SHIFT)) & SYSCON0_EDMA1_EN0_SDADC_FIFO0_EN_MASK)

#define SYSCON0_EDMA1_EN0_SDADC_FIFO1_EN_MASK    (0x80000000U)
#define SYSCON0_EDMA1_EN0_SDADC_FIFO1_EN_SHIFT   (31U)
/*! SDADC_FIFO1_EN - SDADC FIFO1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN0_SDADC_FIFO1_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN0_SDADC_FIFO1_EN_SHIFT)) & SYSCON0_EDMA1_EN0_SDADC_FIFO1_EN_MASK)
/*! @} */

/*! @name EDMA1_EN1 - eDMA1 Request Enable 1 */
/*! @{ */

#define SYSCON0_EDMA1_EN1_SDADC_FIFO2_EN_MASK    (0x1U)
#define SYSCON0_EDMA1_EN1_SDADC_FIFO2_EN_SHIFT   (0U)
/*! SDADC_FIFO2_EN - SDADC FIFO2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_SDADC_FIFO2_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_SDADC_FIFO2_EN_SHIFT)) & SYSCON0_EDMA1_EN1_SDADC_FIFO2_EN_MASK)

#define SYSCON0_EDMA1_EN1_SDADC_FIFO3_EN_MASK    (0x2U)
#define SYSCON0_EDMA1_EN1_SDADC_FIFO3_EN_SHIFT   (1U)
/*! SDADC_FIFO3_EN - SDADC FIFO3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_SDADC_FIFO3_EN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_SDADC_FIFO3_EN_SHIFT)) & SYSCON0_EDMA1_EN1_SDADC_FIFO3_EN_MASK)

#define SYSCON0_EDMA1_EN1_ACMP_EN_MASK           (0x4U)
#define SYSCON0_EDMA1_EN1_ACMP_EN_SHIFT          (2U)
/*! ACMP_EN - ACMP0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_ACMP_EN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_ACMP_EN_SHIFT)) & SYSCON0_EDMA1_EN1_ACMP_EN_MASK)

#define SYSCON0_EDMA1_EN1_ITRC_TAMPER0_EN_MASK   (0x8U)
#define SYSCON0_EDMA1_EN1_ITRC_TAMPER0_EN_SHIFT  (3U)
/*! ITRC_TAMPER0_EN - ITRC Tamper 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_ITRC_TAMPER0_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_ITRC_TAMPER0_EN_SHIFT)) & SYSCON0_EDMA1_EN1_ITRC_TAMPER0_EN_MASK)

#define SYSCON0_EDMA1_EN1_ITRC_TAMPER1_EN_MASK   (0x10U)
#define SYSCON0_EDMA1_EN1_ITRC_TAMPER1_EN_SHIFT  (4U)
/*! ITRC_TAMPER1_EN - ITRC Tamper 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_ITRC_TAMPER1_EN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_ITRC_TAMPER1_EN_SHIFT)) & SYSCON0_EDMA1_EN1_ITRC_TAMPER1_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER0_EN_MASK (0x20U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER0_EN_SHIFT (5U)
/*! FLEXIO_SHFT_TIMER0_EN - FLEXIO Shift Timer 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER0_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER0_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER0_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER1_EN_MASK (0x40U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER1_EN_SHIFT (6U)
/*! FLEXIO_SHFT_TIMER1_EN - FLEXIO Shift Timer 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER1_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER1_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER1_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER2_EN_MASK (0x80U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER2_EN_SHIFT (7U)
/*! FLEXIO_SHFT_TIMER2_EN - FLEXIO Shift Timer 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER2_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER2_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER2_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER3_EN_MASK (0x100U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER3_EN_SHIFT (8U)
/*! FLEXIO_SHFT_TIMER3_EN - FLEXIO Shift Timer 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER3_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER3_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER3_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER4_EN_MASK (0x200U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER4_EN_SHIFT (9U)
/*! FLEXIO_SHFT_TIMER4_EN - FLEXIO Shift Timer 4 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER4_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER4_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER4_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER5_EN_MASK (0x400U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER5_EN_SHIFT (10U)
/*! FLEXIO_SHFT_TIMER5_EN - FLEXIO Shift Timer 5 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER5_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER5_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER5_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER6_EN_MASK (0x800U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER6_EN_SHIFT (11U)
/*! FLEXIO_SHFT_TIMER6_EN - FLEXIO Shift Timer 6 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER6_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER6_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER6_EN_MASK)

#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER7_EN_MASK (0x1000U)
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER7_EN_SHIFT (12U)
/*! FLEXIO_SHFT_TIMER7_EN - FLEXIO Shift Timer 7 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER7_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER7_EN_SHIFT)) & SYSCON0_EDMA1_EN1_FLEXIO_SHFT_TIMER7_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_RX_EN_MASK (0x2000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_RX_EN_SHIFT (13U)
/*! LP_FLEXCOMM0_RX_EN - LP_FLEXCOMM0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_TX_EN_MASK (0x4000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_TX_EN_SHIFT (14U)
/*! LP_FLEXCOMM0_TX_EN - LP_FLEXCOMM0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM0_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_RX_EN_MASK (0x8000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_RX_EN_SHIFT (15U)
/*! LP_FLEXCOMM1_RX_EN - LP_FLEXCOMM1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_TX_EN_MASK (0x10000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_TX_EN_SHIFT (16U)
/*! LP_FLEXCOMM1_TX_EN - LP_FLEXCOMM1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM1_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_RX_EN_MASK (0x20000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_RX_EN_SHIFT (17U)
/*! LP_FLEXCOMM2_RX_EN - LP_FLEXCOMM2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_TX_EN_MASK (0x40000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_TX_EN_SHIFT (18U)
/*! LP_FLEXCOMM2_TX_EN - LP_FLEXCOMM2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM2_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_RX_EN_MASK (0x80000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_RX_EN_SHIFT (19U)
/*! LP_FLEXCOMM3_RX_EN - LP_FLEXCOMM3 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_TX_EN_MASK (0x100000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_TX_EN_SHIFT (20U)
/*! LP_FLEXCOMM3_TX_EN - LP_FLEXCOMM3 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM3_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_RX_EN_MASK (0x200000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_RX_EN_SHIFT (21U)
/*! LP_FLEXCOMM4_RX_EN - LP_FLEXCOMM4 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_TX_EN_MASK (0x400000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_TX_EN_SHIFT (22U)
/*! LP_FLEXCOMM4_TX_EN - LP_FLEXCOMM4 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM4_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_RX_EN_MASK (0x800000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_RX_EN_SHIFT (23U)
/*! LP_FLEXCOMM5_RX_EN - LP_FLEXCOMM5 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_TX_EN_MASK (0x1000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_TX_EN_SHIFT (24U)
/*! LP_FLEXCOMM5_TX_EN - LP_FLEXCOMM5 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM5_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_RX_EN_MASK (0x2000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_RX_EN_SHIFT (25U)
/*! LP_FLEXCOMM6_RX_EN - LP_FLEXCOMM6 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_TX_EN_MASK (0x4000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_TX_EN_SHIFT (26U)
/*! LP_FLEXCOMM6_TX_EN - LP_FLEXCOMM6 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM6_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_RX_EN_MASK (0x8000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_RX_EN_SHIFT (27U)
/*! LP_FLEXCOMM7_RX_EN - LP_FLEXCOMM7 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_TX_EN_MASK (0x10000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_TX_EN_SHIFT (28U)
/*! LP_FLEXCOMM7_TX_EN - LP_FLEXCOMM7 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM7_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_RX_EN_MASK (0x20000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_RX_EN_SHIFT (29U)
/*! LP_FLEXCOMM8_RX_EN - LP_FLEXCOMM8 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_RX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_TX_EN_MASK (0x40000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_TX_EN_SHIFT (30U)
/*! LP_FLEXCOMM8_TX_EN - LP_FLEXCOMM8 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM8_TX_EN_MASK)

#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM9_RX_EN_MASK (0x80000000U)
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM9_RX_EN_SHIFT (31U)
/*! LP_FLEXCOMM9_RX_EN - LP_FLEXCOMM9 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN1_LP_FLEXCOMM9_RX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN1_LP_FLEXCOMM9_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN1_LP_FLEXCOMM9_RX_EN_MASK)
/*! @} */

/*! @name EDMA1_EN2 - eDMA1 Request Enable 2 */
/*! @{ */

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM9_TX_EN_MASK (0x1U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM9_TX_EN_SHIFT (0U)
/*! LP_FLEXCOMM9_TX_EN - LP_FLEXCOMM9 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM9_TX_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM9_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM9_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_RX_EN_MASK (0x2U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_RX_EN_SHIFT (1U)
/*! LP_FLEXCOMM10_RX_EN - LP_FLEXCOMM10 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_TX_EN_MASK (0x4U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_TX_EN_SHIFT (2U)
/*! LP_FLEXCOMM10_TX_EN - LP_FLEXCOMM10 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM10_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_RX_EN_MASK (0x8U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_RX_EN_SHIFT (3U)
/*! LP_FLEXCOMM11_RX_EN - LP_FLEXCOMM11 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_TX_EN_MASK (0x10U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_TX_EN_SHIFT (4U)
/*! LP_FLEXCOMM11_TX_EN - LP_FLEXCOMM11 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM11_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_RX_EN_MASK (0x20U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_RX_EN_SHIFT (5U)
/*! LP_FLEXCOMM12_RX_EN - LP_FLEXCOMM12 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_TX_EN_MASK (0x40U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_TX_EN_SHIFT (6U)
/*! LP_FLEXCOMM12_TX_EN - LP_FLEXCOMM12 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM12_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_RX_EN_MASK (0x80U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_RX_EN_SHIFT (7U)
/*! LP_FLEXCOMM13_RX_EN - LP_FLEXCOMM13 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_RX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_TX_EN_MASK (0x100U)
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_TX_EN_SHIFT (8U)
/*! LP_FLEXCOMM13_TX_EN - LP_FLEXCOMM13 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LP_FLEXCOMM13_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LPSPI14_RX_EN_MASK     (0x200U)
#define SYSCON0_EDMA1_EN2_LPSPI14_RX_EN_SHIFT    (9U)
/*! LPSPI14_RX_EN - LPSPI14 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LPSPI14_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LPSPI14_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LPSPI14_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LPSPI14_TX_EN_MASK     (0x400U)
#define SYSCON0_EDMA1_EN2_LPSPI14_TX_EN_SHIFT    (10U)
/*! LPSPI14_TX_EN - LPSPI14 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LPSPI14_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LPSPI14_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LPSPI14_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LPSPI16_RX_EN_MASK     (0x800U)
#define SYSCON0_EDMA1_EN2_LPSPI16_RX_EN_SHIFT    (11U)
/*! LPSPI16_RX_EN - LPSPI16 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LPSPI16_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LPSPI16_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LPSPI16_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_LPSPI16_TX_EN_MASK     (0x1000U)
#define SYSCON0_EDMA1_EN2_LPSPI16_TX_EN_SHIFT    (12U)
/*! LPSPI16_TX_EN - LPSPI16 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_LPSPI16_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_LPSPI16_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_LPSPI16_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_I3C0_RX_EN_MASK        (0x2000U)
#define SYSCON0_EDMA1_EN2_I3C0_RX_EN_SHIFT       (13U)
/*! I3C0_RX_EN - I3C0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_I3C0_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_I3C0_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_I3C0_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_I3C0_TX_EN_MASK        (0x4000U)
#define SYSCON0_EDMA1_EN2_I3C0_TX_EN_SHIFT       (14U)
/*! I3C0_TX_EN - I3C0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_I3C0_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_I3C0_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_I3C0_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_I3C1_RX_EN_MASK        (0x8000U)
#define SYSCON0_EDMA1_EN2_I3C1_RX_EN_SHIFT       (15U)
/*! I3C1_RX_EN - I3C1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_I3C1_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_I3C1_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_I3C1_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_I3C1_TX_EN_MASK        (0x10000U)
#define SYSCON0_EDMA1_EN2_I3C1_TX_EN_SHIFT       (16U)
/*! I3C1_TX_EN - I3C1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_I3C1_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_I3C1_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_I3C1_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI0_RX_EN_MASK        (0x20000U)
#define SYSCON0_EDMA1_EN2_SAI0_RX_EN_SHIFT       (17U)
/*! SAI0_RX_EN - SAI0 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI0_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI0_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI0_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI0_TX_EN_MASK        (0x40000U)
#define SYSCON0_EDMA1_EN2_SAI0_TX_EN_SHIFT       (18U)
/*! SAI0_TX_EN - SAI0 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI0_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI0_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI0_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI1_RX_EN_MASK        (0x80000U)
#define SYSCON0_EDMA1_EN2_SAI1_RX_EN_SHIFT       (19U)
/*! SAI1_RX_EN - SAI1 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI1_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI1_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI1_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI1_TX_EN_MASK        (0x100000U)
#define SYSCON0_EDMA1_EN2_SAI1_TX_EN_SHIFT       (20U)
/*! SAI1_TX_EN - SAI1 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI1_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI1_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI1_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI2_RX_EN_MASK        (0x200000U)
#define SYSCON0_EDMA1_EN2_SAI2_RX_EN_SHIFT       (21U)
/*! SAI2_RX_EN - SAI2 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI2_RX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI2_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI2_RX_EN_MASK)

#define SYSCON0_EDMA1_EN2_SAI2_TX_EN_MASK        (0x400000U)
#define SYSCON0_EDMA1_EN2_SAI2_TX_EN_SHIFT       (22U)
/*! SAI2_TX_EN - SAI2 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_SAI2_TX_EN(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_SAI2_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN2_SAI2_TX_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO0_DMA0_EN_MASK     (0x800000U)
#define SYSCON0_EDMA1_EN2_GPIO0_DMA0_EN_SHIFT    (23U)
/*! GPIO0_DMA0_EN - GPIO0 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO0_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO0_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO0_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO0_DMA1_EN_MASK     (0x1000000U)
#define SYSCON0_EDMA1_EN2_GPIO0_DMA1_EN_SHIFT    (24U)
/*! GPIO0_DMA1_EN - GPIO0 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO0_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO0_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO0_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO1_DMA0_EN_MASK     (0x2000000U)
#define SYSCON0_EDMA1_EN2_GPIO1_DMA0_EN_SHIFT    (25U)
/*! GPIO1_DMA0_EN - GPIO1 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO1_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO1_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO1_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO1_DMA1_EN_MASK     (0x4000000U)
#define SYSCON0_EDMA1_EN2_GPIO1_DMA1_EN_SHIFT    (26U)
/*! GPIO1_DMA1_EN - GPIO1 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO1_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO1_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO1_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO2_DMA0_EN_MASK     (0x8000000U)
#define SYSCON0_EDMA1_EN2_GPIO2_DMA0_EN_SHIFT    (27U)
/*! GPIO2_DMA0_EN - GPIO2 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO2_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO2_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO2_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO2_DMA1_EN_MASK     (0x10000000U)
#define SYSCON0_EDMA1_EN2_GPIO2_DMA1_EN_SHIFT    (28U)
/*! GPIO2_DMA1_EN - GPIO2 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO2_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO2_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO2_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO3_DMA0_EN_MASK     (0x20000000U)
#define SYSCON0_EDMA1_EN2_GPIO3_DMA0_EN_SHIFT    (29U)
/*! GPIO3_DMA0_EN - GPIO3 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO3_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO3_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO3_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO3_DMA1_EN_MASK     (0x40000000U)
#define SYSCON0_EDMA1_EN2_GPIO3_DMA1_EN_SHIFT    (30U)
/*! GPIO3_DMA1_EN - GPIO3 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO3_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO3_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO3_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN2_GPIO4_DMA0_EN_MASK     (0x80000000U)
#define SYSCON0_EDMA1_EN2_GPIO4_DMA0_EN_SHIFT    (31U)
/*! GPIO4_DMA0_EN - GPIO4 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN2_GPIO4_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN2_GPIO4_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN2_GPIO4_DMA0_EN_MASK)
/*! @} */

/*! @name EDMA1_EN3 - eDMA1 Request Enable 3 */
/*! @{ */

#define SYSCON0_EDMA1_EN3_GPIO4_DMA1_EN_MASK     (0x1U)
#define SYSCON0_EDMA1_EN3_GPIO4_DMA1_EN_SHIFT    (0U)
/*! GPIO4_DMA1_EN - GPIO4 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO4_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO4_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO4_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO5_DMA0_EN_MASK     (0x2U)
#define SYSCON0_EDMA1_EN3_GPIO5_DMA0_EN_SHIFT    (1U)
/*! GPIO5_DMA0_EN - GPIO5 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO5_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO5_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO5_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO5_DMA1_EN_MASK     (0x4U)
#define SYSCON0_EDMA1_EN3_GPIO5_DMA1_EN_SHIFT    (2U)
/*! GPIO5_DMA1_EN - GPIO5 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO5_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO5_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO5_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO6_DMA0_EN_MASK     (0x8U)
#define SYSCON0_EDMA1_EN3_GPIO6_DMA0_EN_SHIFT    (3U)
/*! GPIO6_DMA0_EN - GPIO6 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO6_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO6_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO6_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO6_DMA1_EN_MASK     (0x10U)
#define SYSCON0_EDMA1_EN3_GPIO6_DMA1_EN_SHIFT    (4U)
/*! GPIO6_DMA1_EN - GPIO6 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO6_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO6_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO6_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO7_DMA0_EN_MASK     (0x20U)
#define SYSCON0_EDMA1_EN3_GPIO7_DMA0_EN_SHIFT    (5U)
/*! GPIO7_DMA0_EN - GPIO7 eDMA Request 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO7_DMA0_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO7_DMA0_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO7_DMA0_EN_MASK)

#define SYSCON0_EDMA1_EN3_GPIO7_DMA1_EN_MASK     (0x40U)
#define SYSCON0_EDMA1_EN3_GPIO7_DMA1_EN_SHIFT    (6U)
/*! GPIO7_DMA1_EN - GPIO7 eDMA Request 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_GPIO7_DMA1_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_GPIO7_DMA1_EN_SHIFT)) & SYSCON0_EDMA1_EN3_GPIO7_DMA1_EN_MASK)

#define SYSCON0_EDMA1_EN3_LPI2C15_RX_EN_MASK     (0x80U)
#define SYSCON0_EDMA1_EN3_LPI2C15_RX_EN_SHIFT    (7U)
/*! LPI2C15_RX_EN - LPI2C15 RX FIFO Drain Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_LPI2C15_RX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_LPI2C15_RX_EN_SHIFT)) & SYSCON0_EDMA1_EN3_LPI2C15_RX_EN_MASK)

#define SYSCON0_EDMA1_EN3_LPI2C15_TX_EN_MASK     (0x100U)
#define SYSCON0_EDMA1_EN3_LPI2C15_TX_EN_SHIFT    (8U)
/*! LPI2C15_TX_EN - LPI2C15 TX FIFO Fill Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON0_EDMA1_EN3_LPI2C15_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_EDMA1_EN3_LPI2C15_TX_EN_SHIFT)) & SYSCON0_EDMA1_EN3_LPI2C15_TX_EN_MASK)
/*! @} */

/*! @name AXBS_CTRL - AXBS Control */
/*! @{ */

#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M0_MASK (0x1U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M0_SHIFT (0U)
/*! AXBS_XSPI0_PRIORITY_M0 - AXBS for XSPI0 M0 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M0_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M0_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M1_MASK (0x2U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M1_SHIFT (1U)
/*! AXBS_XSPI0_PRIORITY_M1 - AXBS for XSPI0 M1 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M1_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M1_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M2_MASK (0x4U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M2_SHIFT (2U)
/*! AXBS_XSPI0_PRIORITY_M2 - AXBS for XSPI0 M2 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M2(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M2_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI0_PRIORITY_M2_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_FORCE_RR_MASK (0x8000U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_FORCE_RR_SHIFT (15U)
/*! AXBS_XSPI0_FORCE_RR - AXBS for XSPI0 Force Round-Robin
 *  0b0..Fixed priority arbitration
 *  0b1..Round-robin arbitration
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI0_FORCE_RR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI0_FORCE_RR_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI0_FORCE_RR_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M0_MASK (0x10000U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M0_SHIFT (16U)
/*! AXBS_XSPI1_PRIORITY_M0 - AXBS for XSPI1 M0 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M0_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M0_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M1_MASK (0x20000U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M1_SHIFT (17U)
/*! AXBS_XSPI1_PRIORITY_M1 - AXBS for XSPI1 M1 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M1_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M1_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M2_MASK (0x40000U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M2_SHIFT (18U)
/*! AXBS_XSPI1_PRIORITY_M2 - AXBS for XSPI1 M2 Priority
 *  0b0..Low
 *  0b1..High
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M2(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M2_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI1_PRIORITY_M2_MASK)

#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_FORCE_RR_MASK (0x80000000U)
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_FORCE_RR_SHIFT (31U)
/*! AXBS_XSPI1_FORCE_RR - AXBS for XSPI1 Force Round-Robin
 *  0b0..Fixed priority arbitration
 *  0b1..Round-robin arbitration
 */
#define SYSCON0_AXBS_CTRL_AXBS_XSPI1_FORCE_RR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_AXBS_CTRL_AXBS_XSPI1_FORCE_RR_SHIFT)) & SYSCON0_AXBS_CTRL_AXBS_XSPI1_FORCE_RR_MASK)
/*! @} */

/*! @name I3C_ASYNC_WAKEUP_CTRL - I3C Asynchronous Wake-up Control */
/*! @{ */

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN0_MASK (0x1U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN0_SHIFT (0U)
/*! IRQ_EN0 - I3C0 Controller Mode Asynchronous Wake-up Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN0_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN0_MASK)

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR0_MASK (0x2U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR0_SHIFT (1U)
/*! IRQ_CLR0 - I3C0 Asynchronous Wake-up Interrupt Clear
 *  0b0..Interrupt not cleared
 *  0b1..Interrupt cleared
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR0_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR0_MASK)

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS0_MASK (0x80U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS0_SHIFT (7U)
/*! IRQ_STATUS0 - I3C0 Asynchronous Wake-up Interrupt Status
 *  0b0..Interrupt not asserted
 *  0b1..Interrupt asserted
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS0_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS0_MASK)

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN1_MASK (0x100U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN1_SHIFT (8U)
/*! IRQ_EN1 - I3C1 Controller Mode Asynchronous Wake-up Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN1_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_EN1_MASK)

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR1_MASK (0x200U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR1_SHIFT (9U)
/*! IRQ_CLR1 - I3C1 Asynchronous Wake-up Interrupt Clear
 *  0b0..Interrupt not cleared
 *  0b1..Interrupt cleared
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR1_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_CLR1_MASK)

#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS1_MASK (0x8000U)
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS1_SHIFT (15U)
/*! IRQ_STATUS1 - I3C1 Asynchronous Wake-up Interrupt Status
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS1_SHIFT)) & SYSCON0_I3C_ASYNC_WAKEUP_CTRL_IRQ_STATUS1_MASK)
/*! @} */

/*! @name GRAY_CODE_LSB - Gray to Binary Converter - Gray Code [31:0] */
/*! @{ */

#define SYSCON0_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK (0xFFFFFFFFU)
#define SYSCON0_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT (0U)
/*! CODE_GRAY_31_0 - Gray Code [31:0] */
#define SYSCON0_GRAY_CODE_LSB_CODE_GRAY_31_0(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_GRAY_CODE_LSB_CODE_GRAY_31_0_SHIFT)) & SYSCON0_GRAY_CODE_LSB_CODE_GRAY_31_0_MASK)
/*! @} */

/*! @name GRAY_CODE_MSB - Gray to Binary Converter - Gray Code [63:32] */
/*! @{ */

#define SYSCON0_GRAY_CODE_MSB_CODE_GRAY_63_32_MASK (0xFFFFFFFFU)
#define SYSCON0_GRAY_CODE_MSB_CODE_GRAY_63_32_SHIFT (0U)
/*! CODE_GRAY_63_32 - Gray Code [63:32] */
#define SYSCON0_GRAY_CODE_MSB_CODE_GRAY_63_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_GRAY_CODE_MSB_CODE_GRAY_63_32_SHIFT)) & SYSCON0_GRAY_CODE_MSB_CODE_GRAY_63_32_MASK)
/*! @} */

/*! @name BINARY_CODE_LSB - Gray to Binary Converter - Binary Code [31:0] */
/*! @{ */

#define SYSCON0_BINARY_CODE_LSB_CODE_BIN_31_0_MASK (0xFFFFFFFFU)
#define SYSCON0_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT (0U)
/*! CODE_BIN_31_0 - Binary Code [31:0] */
#define SYSCON0_BINARY_CODE_LSB_CODE_BIN_31_0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_BINARY_CODE_LSB_CODE_BIN_31_0_SHIFT)) & SYSCON0_BINARY_CODE_LSB_CODE_BIN_31_0_MASK)
/*! @} */

/*! @name BINARY_CODE_MSB - Gray to Binary Converter - Binary Code [63:32] */
/*! @{ */

#define SYSCON0_BINARY_CODE_MSB_CODE_BIN_63_32_MASK (0xFFFFFFFFU)
#define SYSCON0_BINARY_CODE_MSB_CODE_BIN_63_32_SHIFT (0U)
/*! CODE_BIN_63_32 - Binary Code [63:32] */
#define SYSCON0_BINARY_CODE_MSB_CODE_BIN_63_32(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_BINARY_CODE_MSB_CODE_BIN_63_32_SHIFT)) & SYSCON0_BINARY_CODE_MSB_CODE_BIN_63_32_MASK)
/*! @} */

/*! @name SEC_BUSY_STATE - Secure IP Busy State */
/*! @{ */

#define SYSCON0_SEC_BUSY_STATE_SAFO_BUSY_MASK    (0x1U)
#define SYSCON0_SEC_BUSY_STATE_SAFO_BUSY_SHIFT   (0U)
/*! SAFO_BUSY - SAFO-SGI Busy State
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SYSCON0_SEC_BUSY_STATE_SAFO_BUSY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_BUSY_STATE_SAFO_BUSY_SHIFT)) & SYSCON0_SEC_BUSY_STATE_SAFO_BUSY_MASK)

#define SYSCON0_SEC_BUSY_STATE_ELS_BUSY_MASK     (0x2U)
#define SYSCON0_SEC_BUSY_STATE_ELS_BUSY_SHIFT    (1U)
/*! ELS_BUSY - ELS Busy State
 *  0b0..Not busy
 *  0b1..Busy
 */
#define SYSCON0_SEC_BUSY_STATE_ELS_BUSY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_SEC_BUSY_STATE_ELS_BUSY_SHIFT)) & SYSCON0_SEC_BUSY_STATE_ELS_BUSY_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE - Lifecycle State */
/*! @{ */

#define SYSCON0_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK (0xFFU)
#define SYSCON0_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT (0U)
/*! OTP_LC_STATE - OTP Lifecycle State */
#define SYSCON0_ELS_OTP_LC_STATE_OTP_LC_STATE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_OTP_LC_STATE_OTP_LC_STATE_SHIFT)) & SYSCON0_ELS_OTP_LC_STATE_OTP_LC_STATE_MASK)
/*! @} */

/*! @name ELS_OTP_LC_STATE_DP - Lifecycle State */
/*! @{ */

#define SYSCON0_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK (0xFFU)
#define SYSCON0_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT (0U)
/*! OTP_LC_STATE_DP - OTP Lifecycle State */
#define SYSCON0_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_SHIFT)) & SYSCON0_ELS_OTP_LC_STATE_DP_OTP_LC_STATE_DP_MASK)
/*! @} */

/*! @name ELS_TEMPORAL_STATE - ELS Temporal State */
/*! @{ */

#define SYSCON0_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON0_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT (0U)
/*! TEMPORAL_STATE - Temporal State */
#define SYSCON0_ELS_TEMPORAL_STATE_TEMPORAL_STATE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_TEMPORAL_STATE_TEMPORAL_STATE_SHIFT)) & SYSCON0_ELS_TEMPORAL_STATE_TEMPORAL_STATE_MASK)
/*! @} */

/*! @name ELS_KDF_MASK - Key Derivation Function Mask */
/*! @{ */

#define SYSCON0_ELS_KDF_MASK_KDF_MASK_MASK       (0xFFFFFFFFU)
#define SYSCON0_ELS_KDF_MASK_KDF_MASK_SHIFT      (0U)
/*! KDF_MASK - Key Derivation Function Mask */
#define SYSCON0_ELS_KDF_MASK_KDF_MASK(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_KDF_MASK_KDF_MASK_SHIFT)) & SYSCON0_ELS_KDF_MASK_KDF_MASK_MASK)
/*! @} */

/*! @name ELS_BOOT_STATE1 - ELS Boot State 1 */
/*! @{ */

#define SYSCON0_ELS_BOOT_STATE1_ROOT_KEY_INDEX_MASK (0x3U)
#define SYSCON0_ELS_BOOT_STATE1_ROOT_KEY_INDEX_SHIFT (0U)
/*! ROOT_KEY_INDEX - Root Key Index */
#define SYSCON0_ELS_BOOT_STATE1_ROOT_KEY_INDEX(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_ROOT_KEY_INDEX_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_ROOT_KEY_INDEX_MASK)

#define SYSCON0_ELS_BOOT_STATE1_FIPS_SELF_TEST_MASK (0x3FCU)
#define SYSCON0_ELS_BOOT_STATE1_FIPS_SELF_TEST_SHIFT (2U)
/*! FIPS_SELF_TEST - FIPS Self-Test
 *  0b00000010..FIPS_SHA_STEN
 *  0b00000011..FIPS_AES_STEN
 *  0b00000100..FIPS_ECDSA_STEN
 *  0b00000101..FIPS_DRBG_STEN
 *  0b00000110..FIPS_CMAC_STEN
 *  0b00000111..FIPS_CKDF_STEN
 *  0b00001000..FIPS_HKDF_STEN
 *  0b00001001..
 */
#define SYSCON0_ELS_BOOT_STATE1_FIPS_SELF_TEST(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_FIPS_SELF_TEST_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_FIPS_SELF_TEST_MASK)

#define SYSCON0_ELS_BOOT_STATE1_SB3_TYP_MASK     (0xC00U)
#define SYSCON0_ELS_BOOT_STATE1_SB3_TYP_SHIFT    (10U)
/*! SB3_TYP - SB3 Type
 *  0b00..Customer firmware load and update file
 *  0b01..NXP provisioning firmware
 *  0b10..Customer manufacturing firmware (device HSM)
 */
#define SYSCON0_ELS_BOOT_STATE1_SB3_TYP(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_SB3_TYP_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_SB3_TYP_MASK)

#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_19_18_MASK (0x3000U)
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_19_18_SHIFT (12U)
/*! PMC0_FLAGS_19_18 - PMC0.FLAGS[19:18] */
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_19_18(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_19_18_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_19_18_MASK)

#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_22_21_MASK (0x18000U)
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_22_21_SHIFT (15U)
/*! PMC0_FLAGS_22_21 - PMC0.FLAGS[22:21] */
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_22_21(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_22_21_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_22_21_MASK)

#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_17_16_MASK (0xC0000U)
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_17_16_SHIFT (18U)
/*! PMC0_FLAGS_17_16 - PMC0.FLAGS[17:16] */
#define SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_17_16(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_17_16_SHIFT)) & SYSCON0_ELS_BOOT_STATE1_PMC0_FLAGS_17_16_MASK)
/*! @} */

/*! @name ELS_ASSET_PROT - ELS Asset Protection */
/*! @{ */

#define SYSCON0_ELS_ASSET_PROT_ASSET_PROTECTION_MASK (0x3U)
#define SYSCON0_ELS_ASSET_PROT_ASSET_PROTECTION_SHIFT (0U)
/*! ASSET_PROTECTION - Asset Protection
 *  0b01..NOT protected
 *  *..Protected
 */
#define SYSCON0_ELS_ASSET_PROT_ASSET_PROTECTION(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_ASSET_PROT_ASSET_PROTECTION_SHIFT)) & SYSCON0_ELS_ASSET_PROT_ASSET_PROTECTION_MASK)
/*! @} */

/*! @name ELS_AS_UUID - ELS AS UUID */
/*! @{ */

#define SYSCON0_ELS_AS_UUID_UUIDN_MASK           (0xFFFFFFFFU)
#define SYSCON0_ELS_AS_UUID_UUIDN_SHIFT          (0U)
/*! UUIDN - UUIDn 32-Bit Data Register */
#define SYSCON0_ELS_AS_UUID_UUIDN(x)             (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_UUID_UUIDN_SHIFT)) & SYSCON0_ELS_AS_UUID_UUIDN_MASK)
/*! @} */

/*! @name ELS_AS_CFG0 - ELS AS Configuration 0 */
/*! @{ */

#define SYSCON0_ELS_AS_CFG0_CFG_LC_STATE_MASK    (0xFFU)
#define SYSCON0_ELS_AS_CFG0_CFG_LC_STATE_SHIFT   (0U)
/*! CFG_LC_STATE - Lifecycle State Configuration */
#define SYSCON0_ELS_AS_CFG0_CFG_LC_STATE(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_LC_STATE_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_LC_STATE_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD1_ENABLED_MASK (0x100U)
#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD1_ENABLED_SHIFT (8U)
/*! CFG_HVD_VDD1_ENABLED - HVD for VDD1 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD1_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD1_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD1_ENABLED_MASK (0x200U)
#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD1_ENABLED_SHIFT (9U)
/*! CFG_LVD_VDD1_ENABLED - LVD for VDD1 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD1_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD1_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD2_ENABLED_MASK (0x400U)
#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD2_ENABLED_SHIFT (10U)
/*! CFG_HVD_VDD2_ENABLED - HVD for VDD2 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD2_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_HVD_VDD2_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD2_ENABLED_MASK (0x800U)
#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD2_ENABLED_SHIFT (11U)
/*! CFG_LVD_VDD2_ENABLED - LVD for VDD2 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD2_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_LVD_VDD2_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_VDD2_HGDET0_ENABLED_MASK (0x1000U)
#define SYSCON0_ELS_AS_CFG0_CFG_VDD2_HGDET0_ENABLED_SHIFT (12U)
/*! CFG_VDD2_HGDET0_ENABLED - VDD2 High-Range GDET0
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_VDD2_HGDET0_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_VDD2_HGDET0_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_VDD2_HGDET0_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_VDD1_HGDET3_ENABLED_MASK (0x8000U)
#define SYSCON0_ELS_AS_CFG0_CFG_VDD1_HGDET3_ENABLED_SHIFT (15U)
/*! CFG_VDD1_HGDET3_ENABLED - VDD1 High-Range GDET3
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_VDD1_HGDET3_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_VDD1_HGDET3_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_VDD1_HGDET3_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_WWDT0_ENABLED_MASK (0x10000U)
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT0_ENABLED_SHIFT (16U)
/*! CFG_WWDT0_ENABLED - WWDT0 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT0_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_WWDT0_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_WWDT0_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_WWDT1_ENABLED_MASK (0x20000U)
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT1_ENABLED_SHIFT (17U)
/*! CFG_WWDT1_ENABLED - WWDT1 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_WWDT1_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_WWDT1_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_WWDT2_ENABLED_MASK (0x40000U)
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT2_ENABLED_SHIFT (18U)
/*! CFG_WWDT2_ENABLED - WWDT2 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_WWDT2_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_WWDT2_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_WWDT3_ENABLED_MASK (0x80000U)
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT3_ENABLED_SHIFT (19U)
/*! CFG_WWDT3_ENABLED - WWDT3 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_WWDT3_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_WWDT3_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_WWDT3_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CDOG0_ENABLED_MASK (0x100000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG0_ENABLED_SHIFT (20U)
/*! CFG_CDOG0_ENABLED - CDOG0 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG0_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CDOG0_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CDOG0_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CDOG1_ENABLED_MASK (0x200000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG1_ENABLED_SHIFT (21U)
/*! CFG_CDOG1_ENABLED - CDOG1 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CDOG1_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CDOG1_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CDOG2_ENABLED_MASK (0x400000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG2_ENABLED_SHIFT (22U)
/*! CFG_CDOG2_ENABLED - CDOG2 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CDOG2_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CDOG2_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CDOG3_ENABLED_MASK (0x800000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG3_ENABLED_SHIFT (23U)
/*! CFG_CDOG3_ENABLED - CDOG3 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG3_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CDOG3_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CDOG3_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CDOG4_ENABLED_MASK (0x1000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG4_ENABLED_SHIFT (24U)
/*! CFG_CDOG4_ENABLED - CDOG4 Configuration
 *  0b0..Not activated
 *  0b1..Activated
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CDOG4_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CDOG4_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CDOG4_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD1_ENABLED_MASK (0x2000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD1_ENABLED_SHIFT (25U)
/*! CFG_AGLITCH_VDD1_ENABLED - Analog Glitch Detector for VDD1 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD1_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD1_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD1_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD2_ENABLED_MASK (0x4000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD2_ENABLED_SHIFT (26U)
/*! CFG_AGLITCH_VDD2_ENABLED - Analog Glitch Detector for VDD2 Power Rail
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD2_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD2_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_AGLITCH_VDD2_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_MASK (0x8000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_SHIFT (27U)
/*! CFG_CLKTAMPER_DET_ENABLED - Clock Tamper Detector in OSC32KNP for 32 kHz RTC XTAL Clock
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_CLKTAMPER_DET_ENABLED_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_ENROLL_MASK (0x10000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_ENROLL_SHIFT (28U)
/*! CFG_PUF_DISABLE_ENROLL - PUF Disable Enroll */
#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_ENROLL(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_ENROLL_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_ENROLL_MASK)

#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_WRAP_MASK (0x20000000U)
#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_WRAP_SHIFT (29U)
/*! CFG_PUF_DISABLE_WRAP - PUF Disable Wrap */
#define SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_WRAP(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_WRAP_SHIFT)) & SYSCON0_ELS_AS_CFG0_CFG_PUF_DISABLE_WRAP_MASK)
/*! @} */

/*! @name ELS_AS_CFG1 - ELS AS Configuration 1 */
/*! @{ */

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_STRICT_MODE_MASK (0x1U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_STRICT_MODE_SHIFT (0U)
/*! CFG_CSEC_DIS_STRICT_MODE - Disable Strict Mode in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_STRICT_MODE_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_STRICT_MODE_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_VIOL_ABORT_MASK (0x2U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_VIOL_ABORT_SHIFT (1U)
/*! CFG_CSEC_DIS_VIOL_ABORT - Disable Violation Abort in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_VIOL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_VIOL_ABORT_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_DIS_VIOL_ABORT_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_NS_PRIV_CHK_MASK (0x4U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_NS_PRIV_CHK_SHIFT (2U)
/*! CFG_CSEC_ENA_NS_PRIV_CHK - Enable Non-Secure Privacy Check in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_NS_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_NS_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_NS_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_S_PRIV_CHK_MASK (0x8U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_S_PRIV_CHK_SHIFT (3U)
/*! CFG_CSEC_ENA_S_PRIV_CHK - Enable Secure Privacy Check in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_S_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_S_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_S_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_SEC_CHK_MASK (0x10U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_SEC_CHK_SHIFT (4U)
/*! CFG_CSEC_ENA_SEC_CHK - Enable Security Check in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_SEC_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_SEC_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_ENA_SEC_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_IDAU_ALLNS_MASK (0x20U)
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_IDAU_ALLNS_SHIFT (5U)
/*! CFG_CSEC_IDAU_ALLNS - IDAU All Non-Secure in VDD2_COMP Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_CSEC_IDAU_ALLNS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CSEC_IDAU_ALLNS_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CSEC_IDAU_ALLNS_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_MPU_MASK (0x40U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_MPU_SHIFT (6U)
/*! CFG_CPU0_LOCK_NS_MPU - CPU0 Lock Non-Secure MPU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_MPU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_MPU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_VTOR_MASK (0x80U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_VTOR_SHIFT (7U)
/*! CFG_CPU0_LOCK_NS_VTOR - CPU0 Lock Non-Secure VTOR */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_VTOR_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_NS_VTOR_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_MPU_MASK (0x100U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_MPU_SHIFT (8U)
/*! CFG_CPU0_LOCK_S_MPU - CPU0 Lock Secure MPU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_MPU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_MPU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_VTAIRCR_MASK (0x200U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_VTAIRCR_SHIFT (9U)
/*! CFG_CPU0_LOCK_S_VTAIRCR - CPU0 Lock Secure VTAIRCR */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_VTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_VTAIRCR_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_S_VTAIRCR_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_SAU_MASK (0x400U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_SAU_SHIFT (10U)
/*! CFG_CPU0_LOCK_SAU - CPU0 Lock SAU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_SAU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_SAU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU0_LOCK_SAU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_STRICT_MODE_MASK (0x800U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_STRICT_MODE_SHIFT (11U)
/*! CFG_SSEC_DIS_STRICT_MODE - Disable Strict Mode in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_STRICT_MODE_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_STRICT_MODE_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_VIOL_ABORT_MASK (0x1000U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_VIOL_ABORT_SHIFT (12U)
/*! CFG_SSEC_DIS_VIOL_ABORT - Disable Violation Abort in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_VIOL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_VIOL_ABORT_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_DIS_VIOL_ABORT_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_NS_PRIV_CHK_MASK (0x2000U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_NS_PRIV_CHK_SHIFT (13U)
/*! CFG_SSEC_ENA_NS_PRIV_CHK - Enable Non-Secure Privacy Check in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_NS_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_NS_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_NS_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_S_PRIV_CHK_MASK (0x4000U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_S_PRIV_CHK_SHIFT (14U)
/*! CFG_SSEC_ENA_S_PRIV_CHK - Enable Secure Privacy Check in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_S_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_S_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_S_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_SEC_CHK_MASK (0x8000U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_SEC_CHK_SHIFT (15U)
/*! CFG_SSEC_ENA_SEC_CHK - Enable Security Check in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_SEC_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_SEC_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_ENA_SEC_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_IDAU_ALLNS_MASK (0x10000U)
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_IDAU_ALLNS_SHIFT (16U)
/*! CFG_SSEC_IDAU_ALLNS - IDAU All Non-Secure in VDD1_SENSE Domain */
#define SYSCON0_ELS_AS_CFG1_CFG_SSEC_IDAU_ALLNS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_SSEC_IDAU_ALLNS_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_SSEC_IDAU_ALLNS_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_MPU_MASK (0x20000U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_MPU_SHIFT (17U)
/*! CFG_CPU1_LOCK_NS_MPU - CPU1 Lock Non-Secure MPU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_MPU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_MPU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_VTOR_MASK (0x40000U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_VTOR_SHIFT (18U)
/*! CFG_CPU1_LOCK_NS_VTOR - CPU1 Lock Non-Secure VTOR */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_VTOR_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_NS_VTOR_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_MPU_MASK (0x80000U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_MPU_SHIFT (19U)
/*! CFG_CPU1_LOCK_S_MPU - CPU1 Lock Secure MPU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_MPU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_MPU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_VTAIRCR_MASK (0x100000U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_VTAIRCR_SHIFT (20U)
/*! CFG_CPU1_LOCK_S_VTAIRCR - CPU1 Lock Secure VTAIRCR */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_VTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_VTAIRCR_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_S_VTAIRCR_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_SAU_MASK (0x200000U)
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_SAU_SHIFT (21U)
/*! CFG_CPU1_LOCK_SAU - CPU1 Lock SAU */
#define SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_SAU(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_SAU_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_CPU1_LOCK_SAU_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_STRICT_MODE_MASK (0x400000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_STRICT_MODE_SHIFT (22U)
/*! CFG_MSEC_DIS_STRICT_MODE - Disable Strict Mode in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_STRICT_MODE_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_STRICT_MODE_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_VIOL_ABORT_MASK (0x800000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_VIOL_ABORT_SHIFT (23U)
/*! CFG_MSEC_DIS_VIOL_ABORT - Disable Violation Abort in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_VIOL_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_VIOL_ABORT_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_DIS_VIOL_ABORT_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_NS_PRIV_CHK_MASK (0x1000000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_NS_PRIV_CHK_SHIFT (24U)
/*! CFG_MSEC_ENA_NS_PRIV_CHK - Enable Non-Secure Privacy Check in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_NS_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_NS_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_NS_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_S_PRIV_CHK_MASK (0x2000000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_S_PRIV_CHK_SHIFT (25U)
/*! CFG_MSEC_ENA_S_PRIV_CHK - Enable Secure Privacy Check in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_S_PRIV_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_S_PRIV_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_S_PRIV_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_SEC_CHK_MASK (0x4000000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_SEC_CHK_SHIFT (26U)
/*! CFG_MSEC_ENA_SEC_CHK - Enable Security Check in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_SEC_CHK(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_SEC_CHK_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_ENA_SEC_CHK_MASK)

#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_IDAU_ALLNS_MASK (0x8000000U)
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_IDAU_ALLNS_SHIFT (27U)
/*! CFG_MSEC_IDAU_ALLNS - IDAU All Non-Secure in VDD2_MEDIA */
#define SYSCON0_ELS_AS_CFG1_CFG_MSEC_IDAU_ALLNS(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG1_CFG_MSEC_IDAU_ALLNS_SHIFT)) & SYSCON0_ELS_AS_CFG1_CFG_MSEC_IDAU_ALLNS_MASK)
/*! @} */

/*! @name ELS_AS_CFG3 - ELS AS Configuration 3 */
/*! @{ */

#define SYSCON0_ELS_AS_CFG3_METAL_VERSION_MASK   (0xF0000U)
#define SYSCON0_ELS_AS_CFG3_METAL_VERSION_SHIFT  (16U)
/*! METAL_VERSION - Metal version */
#define SYSCON0_ELS_AS_CFG3_METAL_VERSION(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG3_METAL_VERSION_SHIFT)) & SYSCON0_ELS_AS_CFG3_METAL_VERSION_MASK)

#define SYSCON0_ELS_AS_CFG3_ROM_MINOR_VER_MASK   (0xF00000U)
#define SYSCON0_ELS_AS_CFG3_ROM_MINOR_VER_SHIFT  (20U)
/*! ROM_MINOR_VER - ROM minor version */
#define SYSCON0_ELS_AS_CFG3_ROM_MINOR_VER(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG3_ROM_MINOR_VER_SHIFT)) & SYSCON0_ELS_AS_CFG3_ROM_MINOR_VER_MASK)

#define SYSCON0_ELS_AS_CFG3_ROM_PATCH_MFG_VERSION_MASK (0xF000000U)
#define SYSCON0_ELS_AS_CFG3_ROM_PATCH_MFG_VERSION_SHIFT (24U)
/*! ROM_PATCH_MFG_VERSION - ROM major version */
#define SYSCON0_ELS_AS_CFG3_ROM_PATCH_MFG_VERSION(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG3_ROM_PATCH_MFG_VERSION_SHIFT)) & SYSCON0_ELS_AS_CFG3_ROM_PATCH_MFG_VERSION_MASK)

#define SYSCON0_ELS_AS_CFG3_PATCH_OTA_VERSION_HEXCODE_MASK (0xF0000000U)
#define SYSCON0_ELS_AS_CFG3_PATCH_OTA_VERSION_HEXCODE_SHIFT (28U)
/*! PATCH_OTA_VERSION_HEXCODE - Patch version */
#define SYSCON0_ELS_AS_CFG3_PATCH_OTA_VERSION_HEXCODE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_CFG3_PATCH_OTA_VERSION_HEXCODE_SHIFT)) & SYSCON0_ELS_AS_CFG3_PATCH_OTA_VERSION_HEXCODE_MASK)
/*! @} */

/*! @name ELS_AS_ST0 - ELS AS State 0 */
/*! @{ */

#define SYSCON0_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK (0xFU)
#define SYSCON0_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT (0U)
/*! ST_TEMPORAL_STATE - Temporal State */
#define SYSCON0_ELS_AS_ST0_ST_TEMPORAL_STATE(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_TEMPORAL_STATE_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_TEMPORAL_STATE_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU0_DBGEN_MASK    (0x10U)
#define SYSCON0_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT   (4U)
/*! ST_CPU0_DBGEN - CPU0 Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU0_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU0_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU0_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU0_NIDEN_MASK    (0x20U)
#define SYSCON0_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT   (5U)
/*! ST_CPU0_NIDEN - CPU0 Non-Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU0_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU0_NIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU0_NIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK   (0x40U)
#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT  (6U)
/*! ST_CPU0_SPIDEN - CPU0 Secure Privileged Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU0_SPIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU0_SPIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK  (0x80U)
#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT (7U)
/*! ST_CPU0_SPNIDEN - CPU0 Secure Privileged Non-Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU0_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU0_SPNIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU0_SPNIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU1_DBGEN_MASK    (0x100U)
#define SYSCON0_ELS_AS_ST0_ST_CPU1_DBGEN_SHIFT   (8U)
/*! ST_CPU1_DBGEN - CPU1 Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU1_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU1_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU1_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU1_NIDEN_MASK    (0x200U)
#define SYSCON0_ELS_AS_ST0_ST_CPU1_NIDEN_SHIFT   (9U)
/*! ST_CPU1_NIDEN - CPU1 Non-Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU1_NIDEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU1_NIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU1_NIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPIDEN_MASK   (0x400U)
#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPIDEN_SHIFT  (10U)
/*! ST_CPU1_SPIDEN - CPU1 Secure Privileged Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU1_SPIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU1_SPIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPNIDEN_MASK  (0x800U)
#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPNIDEN_SHIFT (11U)
/*! ST_CPU1_SPNIDEN - CPU1 Secure Privileged Non-Invasive Debug State */
#define SYSCON0_ELS_AS_ST0_ST_CPU1_SPNIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CPU1_SPNIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CPU1_SPNIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_HIFI4_DBGEN_MASK   (0x1000U)
#define SYSCON0_ELS_AS_ST0_ST_HIFI4_DBGEN_SHIFT  (12U)
/*! ST_HIFI4_DBGEN - HiFi4 Invasive Debug Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_HIFI4_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_HIFI4_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_HIFI4_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_HIFI4_NIDEN_MASK   (0x2000U)
#define SYSCON0_ELS_AS_ST0_ST_HIFI4_NIDEN_SHIFT  (13U)
/*! ST_HIFI4_NIDEN - HiFi4 Non-Invasive Debug Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_HIFI4_NIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_HIFI4_NIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_HIFI4_NIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_HIFI1_DBGEN_MASK   (0x4000U)
#define SYSCON0_ELS_AS_ST0_ST_HIFI1_DBGEN_SHIFT  (14U)
/*! ST_HIFI1_DBGEN - HiFi1 Invasive Debug Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_HIFI1_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_HIFI1_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_HIFI1_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_HIFI1_NIDEN_MASK   (0x8000U)
#define SYSCON0_ELS_AS_ST0_ST_HIFI1_NIDEN_SHIFT  (15U)
/*! ST_HIFI1_NIDEN - HiFi1 Non-Invasive Debug Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_HIFI1_NIDEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_HIFI1_NIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_HIFI1_NIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_AHBAP_DBGEN_MASK   (0x10000U)
#define SYSCON0_ELS_AS_ST0_ST_AHBAP_DBGEN_SHIFT  (16U)
/*! ST_AHBAP_DBGEN - Non-Secure Memory Space Access through AHB-AP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_AHBAP_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_AHBAP_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_AHBAP_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_AHBAP_SPIDEN_MASK  (0x20000U)
#define SYSCON0_ELS_AS_ST0_ST_AHBAP_SPIDEN_SHIFT (17U)
/*! ST_AHBAP_SPIDEN - Secure Memory Space Access through AHB-AP
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_AHBAP_SPIDEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_AHBAP_SPIDEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_AHBAP_SPIDEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_EZHV_DBGEN_MASK    (0x40000U)
#define SYSCON0_ELS_AS_ST0_ST_EZHV_DBGEN_SHIFT   (18U)
/*! ST_EZHV_DBGEN - EZH-V Invasive Debug Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_EZHV_DBGEN(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_EZHV_DBGEN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_EZHV_DBGEN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_CORESIGHT_EN_MASK  (0x80000U)
#define SYSCON0_ELS_AS_ST0_ST_CORESIGHT_EN_SHIFT (19U)
/*! ST_CORESIGHT_EN - CoreSight Debug Components Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_CORESIGHT_EN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_CORESIGHT_EN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_CORESIGHT_EN_MASK)

#define SYSCON0_ELS_AS_ST0_ST_TEST_ACCES_EN_MASK (0x100000U)
#define SYSCON0_ELS_AS_ST0_ST_TEST_ACCES_EN_SHIFT (20U)
/*! ST_TEST_ACCES_EN - Test Port Access
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SYSCON0_ELS_AS_ST0_ST_TEST_ACCES_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST0_ST_TEST_ACCES_EN_SHIFT)) & SYSCON0_ELS_AS_ST0_ST_TEST_ACCES_EN_MASK)
/*! @} */

/*! @name ELS_AS_ST1 - ELS AS State 1 */
/*! @{ */

#define SYSCON0_ELS_AS_ST1_ST_PUF_SCORE_MASK     (0xFU)
#define SYSCON0_ELS_AS_ST1_ST_PUF_SCORE_SHIFT    (0U)
/*! ST_PUF_SCORE - PUF Score State */
#define SYSCON0_ELS_AS_ST1_ST_PUF_SCORE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST1_ST_PUF_SCORE_SHIFT)) & SYSCON0_ELS_AS_ST1_ST_PUF_SCORE_MASK)

#define SYSCON0_ELS_AS_ST1_ST_PUF_ZEROIZED_MASK  (0x10U)
#define SYSCON0_ELS_AS_ST1_ST_PUF_ZEROIZED_SHIFT (4U)
/*! ST_PUF_ZEROIZED - PUF Zeroization State */
#define SYSCON0_ELS_AS_ST1_ST_PUF_ZEROIZED(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST1_ST_PUF_ZEROIZED_SHIFT)) & SYSCON0_ELS_AS_ST1_ST_PUF_ZEROIZED_MASK)

#define SYSCON0_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK (0x20U)
#define SYSCON0_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT (5U)
/*! ST_MAIN_CLK_IS_EXT - Main Clock Source External */
#define SYSCON0_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_SHIFT)) & SYSCON0_ELS_AS_ST1_ST_MAIN_CLK_IS_EXT_MASK)

#define SYSCON0_ELS_AS_ST1_ST_BOOT_MODE_MASK     (0xC00U)
#define SYSCON0_ELS_AS_ST1_ST_BOOT_MODE_SHIFT    (10U)
/*! ST_BOOT_MODE - Boot Mode Setting */
#define SYSCON0_ELS_AS_ST1_ST_BOOT_MODE(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_ST1_ST_BOOT_MODE_SHIFT)) & SYSCON0_ELS_AS_ST1_ST_BOOT_MODE_MASK)
/*! @} */

/*! @name ELS_AS_FLAG0 - ELS AS Flag 0 */
/*! @{ */

#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK (0x1U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT (0U)
/*! FLAG_AP_ENABLE_CPU0 - CPU0 AP0 Enable
 *  0b0..No such event
 *  0b1..DAP enables AP0 for CPU0 (Cortex-M33) debug access
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU0_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_MASK (0x2U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_SHIFT (1U)
/*! FLAG_AP_ENABLE_CPU1 - CPU1 AP1 Enable
 *  0b0..No such event
 *  0b1..DAP enables AP1 for CPU1 (Cortex-M33) debug access
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_AP_ENABLE_CPU1_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_AHBAP_ENABLE_MASK (0x4U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_AHBAP_ENABLE_SHIFT (2U)
/*! FLAG_AHBAP_ENABLE - AHB-AP Enable
 *  0b0..No such event
 *  0b1..DAP enables AHB-AP for memory access through SWD interface
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_AHBAP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_AHBAP_ENABLE_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_AHBAP_ENABLE_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_APBAP_ENABLE_MASK (0x8U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_APBAP_ENABLE_SHIFT (3U)
/*! FLAG_APBAP_ENABLE - APB-AP Enable
 *  0b0..No such event
 *  0b1..DAP enables APB-AP for debug access of HiFi4, HiFi1 or EZH-V
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_APBAP_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_APBAP_ENABLE_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_APBAP_ENABLE_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD1_OCCURED_MASK (0x10U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD1_OCCURED_SHIFT (4U)
/*! FLAG_LVD_VDD1_OCCURED - VDD1 LVD Event
 *  0b0..No such event
 *  0b1..LVD from VDD1 power rail is triggered
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD1_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD1_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD1_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD1_OCCURED_MASK (0x20U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD1_OCCURED_SHIFT (5U)
/*! FLAG_HVD_VDD1_OCCURED - VDD1 HVD Event
 *  0b0..No such event
 *  0b1..HVD from VDD1 power rail is triggered
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD1_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD1_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD1_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD2_OCCURED_MASK (0x40U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD2_OCCURED_SHIFT (6U)
/*! FLAG_LVD_VDD2_OCCURED - VDD2 LVD Event
 *  0b0..No such event
 *  0b1..LVD from VDD2 power rail is triggered
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD2_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD2_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_LVD_VDD2_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD2_OCCURED_MASK (0x80U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD2_OCCURED_SHIFT (7U)
/*! FLAG_HVD_VDD2_OCCURED - VDD2 HVD Event
 *  0b0..No such event
 *  0b1..HVD from VDD2 power rail is triggered
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD2_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD2_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_HVD_VDD2_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_PUF_ERROR_MASK (0x1000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_PUF_ERROR_SHIFT (12U)
/*! FLAG_PUF_ERROR - PUF Error
 *  0b0..No such event
 *  0b1..Error is flagged from PUF block
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_PUF_ERROR(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_PUF_ERROR_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_PUF_ERROR_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD1_DETECTED_MASK (0x2000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD1_DETECTED_SHIFT (13U)
/*! FLAG_GDET_GLITCH_VDD1_DETECTED - VDD1 aGDET Glitch Detected
 *  0b0..No such event
 *  0b1..aGDET error is flagged
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD1_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD1_DETECTED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD1_DETECTED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD2_DETECTED_MASK (0x4000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD2_DETECTED_SHIFT (14U)
/*! FLAG_GDET_GLITCH_VDD2_DETECTED - VDD2 aGDET Glitch Detected
 *  0b0..No such event
 *  0b1..aGDET error is flagged
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD2_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD2_DETECTED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_GDET_GLITCH_VDD2_DETECTED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD1_DETECTED_MASK (0x8000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD1_DETECTED_SHIFT (15U)
/*! FLAG_ANA_GLITCH_VDD1_DETECTED - VDD1 Analog Glitch Detected
 *  0b0..No such event
 *  0b1..Analog GDET error is flagged
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD1_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD1_DETECTED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD1_DETECTED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD2_DETECTED_MASK (0x10000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD2_DETECTED_SHIFT (16U)
/*! FLAG_ANA_GLITCH_VDD2_DETECTED - VDD2 Analog Glitch Detected
 *  0b0..No such event
 *  0b1..Analog GDET error is flagged
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD2_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD2_DETECTED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_ANA_GLITCH_VDD2_DETECTED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CSEC_VIOL_IRQ_OCURRED_MASK (0x20000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CSEC_VIOL_IRQ_OCURRED_SHIFT (17U)
/*! FLAG_CSEC_VIOL_IRQ_OCURRED - Security Violation Interrupt in VDD2_COMP Domain
 *  0b0..No such event
 *  0b1..Security violation is indicated from AHBSC0
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CSEC_VIOL_IRQ_OCURRED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CSEC_VIOL_IRQ_OCURRED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CSEC_VIOL_IRQ_OCURRED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_SSEC_VIOL_IRQ_OCURRED_MASK (0x40000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_SSEC_VIOL_IRQ_OCURRED_SHIFT (18U)
/*! FLAG_SSEC_VIOL_IRQ_OCURRED - Security Violation Interrupt in VDD1_SENSE Domain
 *  0b0..No such event
 *  0b1..Security violation is indicated from AHBSC3
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_SSEC_VIOL_IRQ_OCURRED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_SSEC_VIOL_IRQ_OCURRED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_SSEC_VIOL_IRQ_OCURRED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_MSEC_VIOL_IRQ_OCURRED_MASK (0x80000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_MSEC_VIOL_IRQ_OCURRED_SHIFT (19U)
/*! FLAG_MSEC_VIOL_IRQ_OCURRED - Security Violation Interrupt in VDD2_MEDIA
 *  0b0..No such event
 *  0b1..Security violation is indicated from AHBSC4
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_MSEC_VIOL_IRQ_OCURRED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_MSEC_VIOL_IRQ_OCURRED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_MSEC_VIOL_IRQ_OCURRED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK (0x100000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT (20U)
/*! FLAG_CPU0_NS_C_ACC_OCCURED - CPU0 Non-Secure Code Access
 *  0b0..No such event
 *  0b1..CPU0 (Cortex-M33) makes non-secure code transactions
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_C_ACC_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK (0x200000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT (21U)
/*! FLAG_CPU0_NS_D_ACC_OCCURED - CPU0 Non-Secure Data Access
 *  0b0..No such event
 *  0b1..CPU0 (Cortex-M33) makes non-secure data transactions
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CPU0_NS_D_ACC_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_C_ACC_OCCURED_MASK (0x400000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_C_ACC_OCCURED_SHIFT (22U)
/*! FLAG_CPU1_NS_C_ACC_OCCURED - CPU1 Non-Secure Code Access
 *  0b0..No such event
 *  0b1..CPU1 (Cortex-M33) makes non-secure code transactions
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_C_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_C_ACC_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_C_ACC_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_D_ACC_OCCURED_MASK (0x800000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_D_ACC_OCCURED_SHIFT (23U)
/*! FLAG_CPU1_NS_D_ACC_OCCURED - CPU1 Non-Secure Data Access
 *  0b0..No such event
 *  0b1..CPU1 (Cortex-M33) makes non-secure data transactions
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_D_ACC_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_D_ACC_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CPU1_NS_D_ACC_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_OTPC_EFUSE_O_ATTACK_DETECT_MASK (0x1000000U)
#define SYSCON0_ELS_AS_FLAG0_OTPC_EFUSE_O_ATTACK_DETECT_SHIFT (24U)
/*! OTPC_EFUSE_O_ATTACK_DETECT - OTPC E-Fuse Output Attack Detect */
#define SYSCON0_ELS_AS_FLAG0_OTPC_EFUSE_O_ATTACK_DETECT(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_OTPC_EFUSE_O_ATTACK_DETECT_SHIFT)) & SYSCON0_ELS_AS_FLAG0_OTPC_EFUSE_O_ATTACK_DETECT_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_MASK (0x2000000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_SHIFT (25U)
/*! FLAG_CLKTAMPER_DET_IRQ_OCCURED - Clock Tamper Flag
 *  0b0..No detected
 *  0b1..Detected
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_CLKTAMPER_DET_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_MASK (0x4000000U)
#define SYSCON0_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_SHIFT (26U)
/*! FLAG_TEMPTAMPER_DET_IRQ_OCCURED - Temperature Tamper Flag
 *  0b0..No detected
 *  0b1..Detected
 */
#define SYSCON0_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG0_FLAG_TEMPTAMPER_DET_IRQ_OCCURED_MASK)
/*! @} */

/*! @name ELS_AS_FLAG1 - ELS AS Flag 1 */
/*! @{ */

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_RESET_OCCURED_MASK (0x1U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_RESET_OCCURED_SHIFT (0U)
/*! FLAG_WWDT0_RESET_OCCURED - WWDT0 Reset
 *  0b0..No such event
 *  0b1..WWDT0 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_RESET_OCCURED_MASK (0x2U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_RESET_OCCURED_SHIFT (1U)
/*! FLAG_WWDT1_RESET_OCCURED - WWDT1 Reset
 *  0b0..No such event
 *  0b1..WWDT1 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_RESET_OCCURED_MASK (0x4U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_RESET_OCCURED_SHIFT (2U)
/*! FLAG_WWDT2_RESET_OCCURED - WWDT2 Reset
 *  0b0..No such event
 *  0b1..WWDT2 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_RESET_OCCURED_MASK (0x8U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_RESET_OCCURED_SHIFT (3U)
/*! FLAG_WWDT3_RESET_OCCURED - WWDT3 Reset
 *  0b0..No such event
 *  0b1..WWDT3 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_RESET_OCCURED_MASK (0x10U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_RESET_OCCURED_SHIFT (4U)
/*! FLAG_CDOG0_RESET_OCCURED - CDOG0 Reset
 *  0b0..No such event
 *  0b1..CDOG0 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_RESET_OCCURED_MASK (0x20U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_RESET_OCCURED_SHIFT (5U)
/*! FLAG_CDOG1_RESET_OCCURED - CDOG1 Reset
 *  0b0..No such event
 *  0b1..CDOG1 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_RESET_OCCURED_MASK (0x40U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_RESET_OCCURED_SHIFT (6U)
/*! FLAG_CDOG2_RESET_OCCURED - CDOG2 Reset
 *  0b0..No such event
 *  0b1..CDOG2 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_RESET_OCCURED_MASK (0x80U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_RESET_OCCURED_SHIFT (7U)
/*! FLAG_CDOG3_RESET_OCCURED - CDOG3 Reset
 *  0b0..No such event
 *  0b1..CDOG3 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_RESET_OCCURED_MASK (0x100U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_RESET_OCCURED_SHIFT (8U)
/*! FLAG_CDOG4_RESET_OCCURED - CDOG4 Reset
 *  0b0..No such event
 *  0b1..CDOG4 reset is enabled and reset event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_RESET_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_RESET_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_RESET_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_IRQ_OCCURED_MASK (0x200U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_IRQ_OCCURED_SHIFT (9U)
/*! FLAG_WWDT0_IRQ_OCCURED - WWDT0 Interrupt
 *  0b0..No such event
 *  0b1..WWDT0 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT0_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_IRQ_OCCURED_MASK (0x400U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_IRQ_OCCURED_SHIFT (10U)
/*! FLAG_WWDT1_IRQ_OCCURED - WWDT1 Interrupt
 *  0b0..No such event
 *  0b1..WWDT1 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT1_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_IRQ_OCCURED_MASK (0x800U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_IRQ_OCCURED_SHIFT (11U)
/*! FLAG_WWDT2_IRQ_OCCURED - WWDT2 Interrupt
 *  0b0..No such event
 *  0b1..WWDT2 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT2_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_IRQ_OCCURED_MASK (0x1000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_IRQ_OCCURED_SHIFT (12U)
/*! FLAG_WWDT3_IRQ_OCCURED - WWDT3 Interrupt
 *  0b0..No such event
 *  0b1..WWDT3 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_WWDT3_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_IRQ_OCCURED_MASK (0x2000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_IRQ_OCCURED_SHIFT (13U)
/*! FLAG_CDOG0_IRQ_OCCURED - CDOG0 Interrupt
 *  0b0..No such event
 *  0b1..CDOG0 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG0_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_IRQ_OCCURED_MASK (0x4000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_IRQ_OCCURED_SHIFT (14U)
/*! FLAG_CDOG1_IRQ_OCCURED - CDOG1 Interrupt
 *  0b0..No such event
 *  0b1..CDOG1 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG1_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_IRQ_OCCURED_MASK (0x8000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_IRQ_OCCURED_SHIFT (15U)
/*! FLAG_CDOG2_IRQ_OCCURED - CDOG2 Interrupt
 *  0b0..No such event
 *  0b1..CDOG2 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG2_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_IRQ_OCCURED_MASK (0x10000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_IRQ_OCCURED_SHIFT (16U)
/*! FLAG_CDOG3_IRQ_OCCURED - CDOG3 Interrupt
 *  0b0..No such event
 *  0b1..CDOG3 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG3_IRQ_OCCURED_MASK)

#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_IRQ_OCCURED_MASK (0x20000U)
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_IRQ_OCCURED_SHIFT (17U)
/*! FLAG_CDOG4_IRQ_OCCURED - CDOG4 Interrupt
 *  0b0..No such event
 *  0b1..CDOG4 interrupt is enabled and interrupt event is triggered
 */
#define SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_IRQ_OCCURED(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_IRQ_OCCURED_SHIFT)) & SYSCON0_ELS_AS_FLAG1_FLAG_CDOG4_IRQ_OCCURED_MASK)
/*! @} */

/*! @name CLK_OVERRIDE_RAMPKC - PKC RAM Clock Override */
/*! @{ */

#define SYSCON0_CLK_OVERRIDE_RAMPKC_CLK_OVERRIDE_RAMPKC_MASK (0x1U)
#define SYSCON0_CLK_OVERRIDE_RAMPKC_CLK_OVERRIDE_RAMPKC_SHIFT (0U)
/*! CLK_OVERRIDE_RAMPKC - PKC_RAM_CTRL Clock Override
 *  0b0..Clock gating is not overridden
 *  0b1..Clock gating is overridden (automatic clock gating is disabled)
 */
#define SYSCON0_CLK_OVERRIDE_RAMPKC_CLK_OVERRIDE_RAMPKC(x) (((uint32_t)(((uint32_t)(x)) << SYSCON0_CLK_OVERRIDE_RAMPKC_CLK_OVERRIDE_RAMPKC_SHIFT)) & SYSCON0_CLK_OVERRIDE_RAMPKC_CLK_OVERRIDE_RAMPKC_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON0_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON0_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON0_H_ */

