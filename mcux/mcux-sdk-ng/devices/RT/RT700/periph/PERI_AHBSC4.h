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
**         CMSIS Peripheral Access Layer for AHBSC4
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
 * @file PERI_AHBSC4.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBSC4
 *
 * CMSIS Peripheral Access Layer for AHBSC4
 */

#if !defined(PERI_AHBSC4_H_)
#define PERI_AHBSC4_H_                           /**< Symbol preventing repeated inclusion */

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
   -- AHBSC4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC4_Peripheral_Access_Layer AHBSC4 Peripheral Access Layer
 * @{
 */

/** AHBSC4 - Size of Registers Arrays */
#define AHBSC4_EZHV_SRAM_RULE_COUNT               4u
#define AHBSC4_SRAM_0_RULE_COUNT                  4u
#define AHBSC4_SRAM_1_RULE_COUNT                  4u
#define AHBSC4_SRAM_2_RULE_COUNT                  4u
#define AHBSC4_SRAM_3_RULE_COUNT                  4u
#define AHBSC4_SRAM_4_RULE_COUNT                  4u
#define AHBSC4_SRAM_5_RULE_COUNT                  4u
#define AHBSC4_SRAM_6_RULE_COUNT                  4u
#define AHBSC4_SRAM_7_RULE_COUNT                  4u
#define AHBSC4_SRAM_8_RULE_COUNT                  4u
#define AHBSC4_SRAM_9_RULE_COUNT                  4u
#define AHBSC4_SRAM_10_RULE_COUNT                 4u
#define AHBSC4_SRAM_11_RULE_COUNT                 4u
#define AHBSC4_SRAM_12_RULE_COUNT                 4u
#define AHBSC4_SRAM_13_RULE_COUNT                 4u
#define AHBSC4_SRAM_14_RULE_COUNT                 4u
#define AHBSC4_SRAM_15_RULE_COUNT                 4u
#define AHBSC4_SRAM_16_RULE_COUNT                 4u
#define AHBSC4_SRAM_17_RULE_COUNT                 4u
#define AHBSC4_SRAM_18_RULE_COUNT                 4u
#define AHBSC4_SRAM_19_RULE_COUNT                 4u
#define AHBSC4_SRAM_20_RULE_COUNT                 4u
#define AHBSC4_SRAM_21_RULE_COUNT                 4u
#define AHBSC4_SRAM_22_RULE_COUNT                 4u
#define AHBSC4_SRAM_23_RULE_COUNT                 4u
#define AHBSC4_SRAM_24_RULE_COUNT                 4u
#define AHBSC4_SRAM_25_RULE_COUNT                 4u
#define AHBSC4_SRAM_26_RULE_COUNT                 4u
#define AHBSC4_SRAM_27_RULE_COUNT                 4u
#define AHBSC4_SRAM_28_RULE_COUNT                 4u
#define AHBSC4_SRAM_29_RULE_COUNT                 4u
#define AHBSC4_XSPI2_REGION0_RULE_COUNT           4u
#define AHBSC4_XSPI2_REGION1_5_MEM_RULE_COUNT     5u
#define AHBSC4_SEC_VIO_ADDRN_COUNT                13u
#define AHBSC4_SEC_VIO_MISC_INFON_COUNT           13u

/** AHBSC4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0; /**< AHB peripheral 0 Rule Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_RULE0;  /**< AHB Secure Control Peripheral Rule Register 0, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t AIPS4_BRIDGE_MEM_RULE0;            /**< AIPS4 Bridge Rule Register 0, offset: 0x20 */
  __IO uint32_t AIPS4_BRIDGE_MEM_RULE1;            /**< AIPS4 Bridge Rule Register 1, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0; /**< AHB peripheral 1 Rule Register, offset: 0x30 */
       uint8_t RESERVED_3[28];
  __IO uint32_t MEDIA_APB_SLAVE_GROUP0_RULE0;      /**< APB Bridge Peripheral 0 Rule 0, offset: 0x50 */
  __IO uint32_t MEDIA_APB_SLAVE_GROUP0_RULE1;      /**< APB Bridge Peripheral 0 Rule Register 1, offset: 0x54 */
       uint8_t RESERVED_4[24];
  __IO uint32_t EZHV_SRAM_RULE[AHBSC4_EZHV_SRAM_RULE_COUNT]; /**< EZHV SRAM Rule Register, array offset: 0x70, array step: 0x4 */
  __IO uint32_t SRAM_0_RULE[AHBSC4_SRAM_0_RULE_COUNT]; /**< RAM partition 0 Memory Rule Register, array offset: 0x80, array step: 0x4 */
  __IO uint32_t SRAM_1_RULE[AHBSC4_SRAM_1_RULE_COUNT]; /**< RAM partition 1 Memory Rule Register, array offset: 0x90, array step: 0x4 */
  __IO uint32_t SRAM_2_RULE[AHBSC4_SRAM_2_RULE_COUNT]; /**< RAM partition 2 Memory Rule Register, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t SRAM_3_RULE[AHBSC4_SRAM_3_RULE_COUNT]; /**< RAM partition 3 Memory Rule Register, array offset: 0xB0, array step: 0x4 */
  __IO uint32_t SRAM_4_RULE[AHBSC4_SRAM_4_RULE_COUNT]; /**< RAM partition 4 Memory Rule Register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t SRAM_5_RULE[AHBSC4_SRAM_5_RULE_COUNT]; /**< RAM partition 5 Memory Rule Register, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t SRAM_6_RULE[AHBSC4_SRAM_6_RULE_COUNT]; /**< RAM partition 6 Memory Rule Register, array offset: 0xE0, array step: 0x4 */
  __IO uint32_t SRAM_7_RULE[AHBSC4_SRAM_7_RULE_COUNT]; /**< RAM partition 7 Memory Rule Register, array offset: 0xF0, array step: 0x4 */
  __IO uint32_t SRAM_8_RULE[AHBSC4_SRAM_8_RULE_COUNT]; /**< RAM partition 8 Memory Rule Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t SRAM_9_RULE[AHBSC4_SRAM_9_RULE_COUNT]; /**< RAM partition 9 Memory Rule Register, array offset: 0x110, array step: 0x4 */
  __IO uint32_t SRAM_10_RULE[AHBSC4_SRAM_10_RULE_COUNT]; /**< RAM partition 10 Memory Rule Register, array offset: 0x120, array step: 0x4 */
  __IO uint32_t SRAM_11_RULE[AHBSC4_SRAM_11_RULE_COUNT]; /**< RAM partition 11 Memory Rule Register, array offset: 0x130, array step: 0x4 */
  __IO uint32_t SRAM_12_RULE[AHBSC4_SRAM_12_RULE_COUNT]; /**< RAM partition 12 Memory Rule Register, array offset: 0x140, array step: 0x4 */
  __IO uint32_t SRAM_13_RULE[AHBSC4_SRAM_13_RULE_COUNT]; /**< RAM partition 13 Memory Rule Register, array offset: 0x150, array step: 0x4 */
  __IO uint32_t SRAM_14_RULE[AHBSC4_SRAM_14_RULE_COUNT]; /**< RAM partition 14 Memory Rule Register, array offset: 0x160, array step: 0x4 */
  __IO uint32_t SRAM_15_RULE[AHBSC4_SRAM_15_RULE_COUNT]; /**< RAM partition 15 Memory Rule Register, array offset: 0x170, array step: 0x4 */
  __IO uint32_t SRAM_16_RULE[AHBSC4_SRAM_16_RULE_COUNT]; /**< RAM partition 16 Memory Rule Register, array offset: 0x180, array step: 0x4 */
  __IO uint32_t SRAM_17_RULE[AHBSC4_SRAM_17_RULE_COUNT]; /**< RAM partition 17 Memory Rule Register, array offset: 0x190, array step: 0x4 */
  __IO uint32_t SRAM_18_RULE[AHBSC4_SRAM_18_RULE_COUNT]; /**< RAM partition 18 Memory Rule Register, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t SRAM_19_RULE[AHBSC4_SRAM_19_RULE_COUNT]; /**< RAM partition 19 Memory Rule Register, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t SRAM_20_RULE[AHBSC4_SRAM_20_RULE_COUNT]; /**< RAM partition 20 Memory Rule Register, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t SRAM_21_RULE[AHBSC4_SRAM_21_RULE_COUNT]; /**< RAM partition 21 Memory Rule Register, array offset: 0x1D0, array step: 0x4 */
  __IO uint32_t SRAM_22_RULE[AHBSC4_SRAM_22_RULE_COUNT]; /**< RAM partition 22 Memory Rule Register, array offset: 0x1E0, array step: 0x4 */
  __IO uint32_t SRAM_23_RULE[AHBSC4_SRAM_23_RULE_COUNT]; /**< RAM partition 23 Memory Rule Register, array offset: 0x1F0, array step: 0x4 */
  __IO uint32_t SRAM_24_RULE[AHBSC4_SRAM_24_RULE_COUNT]; /**< RAM partition 24 Memory Rule Register, array offset: 0x200, array step: 0x4 */
  __IO uint32_t SRAM_25_RULE[AHBSC4_SRAM_25_RULE_COUNT]; /**< RAM partition 25 Memory Rule Register, array offset: 0x210, array step: 0x4 */
  __IO uint32_t SRAM_26_RULE[AHBSC4_SRAM_26_RULE_COUNT]; /**< RAM partition 26 Memory Rule Register, array offset: 0x220, array step: 0x4 */
  __IO uint32_t SRAM_27_RULE[AHBSC4_SRAM_27_RULE_COUNT]; /**< RAM partition 27 Memory Rule Register, array offset: 0x230, array step: 0x4 */
  __IO uint32_t SRAM_28_RULE[AHBSC4_SRAM_28_RULE_COUNT]; /**< RAM partition 28 Memory Rule Register, array offset: 0x240, array step: 0x4 */
  __IO uint32_t SRAM_29_RULE[AHBSC4_SRAM_29_RULE_COUNT]; /**< RAM partition 29 Memory Rule Register, array offset: 0x250, array step: 0x4 */
  __IO uint32_t XSPI2_REGION0_MEM_RULE[AHBSC4_XSPI2_REGION0_RULE_COUNT]; /**< XSPI2 Region0 Memory Rule Register, array offset: 0x260, array step: 0x4 */
  struct {                                         /* offset: 0x270, array step: 0x10 */
    __IO uint32_t XSPI2_REGION_MEM_RULE0;            /**< XSPI2 Region 1 Memory Rule Register..XSPI2 Region 5 Memory Rule Register, array offset: 0x270, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } XSPI2_REGION1_5_MEM_RULE[AHBSC4_XSPI2_REGION1_5_MEM_RULE_COUNT];
       uint8_t RESERVED_5[2880];
  __I  uint32_t SEC_VIO_ADDR[AHBSC4_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_6[76];
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC4_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_7[76];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_8[204];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_9[32];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} AHBSC4_Type;

/* ----------------------------------------------------------------------------
   -- AHBSC4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC4_Register_Masks AHBSC4 Register Masks
 * @{
 */

/*! @name AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0 - AHB peripheral 0 Rule Register */
/*! @{ */

#define AHBSC4_AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0_LPSPI16_MASK (0x30U)
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0_LPSPI16_SHIFT (4U)
/*! LPSPI16 - LPSPI16
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0_LPSPI16(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0_LPSPI16_SHIFT)) & AHBSC4_AHB_PERIPHERAL_SLAVE_P0_SLAVE_RULE0_LPSPI16_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_RULE0 - AHB Secure Control Peripheral Rule Register 0 */
/*! @{ */

#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK (0x3U)
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT)) & AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK)

#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK (0x30U)
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT)) & AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK)

#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK (0x300U)
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT)) & AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK)

#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK (0x3000U)
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT)) & AHBSC4_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK)
/*! @} */

/*! @name AIPS4_BRIDGE_MEM_RULE0 - AIPS4 Bridge Rule Register 0 */
/*! @{ */

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_XSPI2_MASK (0x30U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_XSPI2_SHIFT (4U)
/*! XSPI2 - XSPI2 registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_XSPI2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_XSPI2_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_XSPI2_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC0_MASK (0x300U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC0_SHIFT (8U)
/*! USDHC0 - USDHC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC0(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC0_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC0_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC1_MASK (0x3000U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC1_SHIFT (12U)
/*! USDHC1 - USDHC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC1(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC1_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USDHC1_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USBPHY_MASK (0x30000U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USBPHY_SHIFT (16U)
/*! USBPHY - USBPHY registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USBPHY(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USBPHY_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_USBPHY_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_FLEXIO_MASK (0x3000000U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_FLEXIO_SHIFT (24U)
/*! FLEXIO - FLEXIO registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_FLEXIO(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_FLEXIO_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_FLEXIO_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_MIPI_DSI_HOST_MASK (0x30000000U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_MIPI_DSI_HOST_SHIFT (28U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Host Controller
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE0_MIPI_DSI_HOST(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE0_MIPI_DSI_HOST_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE0_MIPI_DSI_HOST_MASK)
/*! @} */

/*! @name AIPS4_BRIDGE_MEM_RULE1 - AIPS4 Bridge Rule Register 1 */
/*! @{ */

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB0_MASK  (0x3U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB0_SHIFT (0U)
/*! USB0 - USB0 registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB0_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB0_MASK)

#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB1_MASK  (0x30U)
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB1_SHIFT (4U)
/*! USB1 - USB1 registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB1_SHIFT)) & AHBSC4_AIPS4_BRIDGE_MEM_RULE1_USB1_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0 - AHB peripheral 1 Rule Register */
/*! @{ */

#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LCDIF_MASK (0x3U)
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LCDIF_SHIFT (0U)
/*! LCDIF - LCDIF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LCDIF(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LCDIF_SHIFT)) & AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LCDIF_MASK)

#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LPSPI14_MASK (0x30U)
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LPSPI14_SHIFT (4U)
/*! LPSPI14 - LPSPI14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LPSPI14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LPSPI14_SHIFT)) & AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_LPSPI14_MASK)

#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_VGPU_MASK (0x3000U)
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_VGPU_SHIFT (12U)
/*! VGPU - VGPU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_VGPU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_VGPU_SHIFT)) & AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_VGPU_MASK)

#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_NIC_MEDIA1_AXI_SWITCH_MASK (0x30000U)
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_NIC_MEDIA1_AXI_SWITCH_SHIFT (16U)
/*! NIC_MEDIA1_AXI_SWITCH - NIC_MEDIA1(AXI_SWITCH)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_NIC_MEDIA1_AXI_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_NIC_MEDIA1_AXI_SWITCH_SHIFT)) & AHBSC4_AHB_PERIPHERAL_SLAVE_P1_SLAVE_RULE0_NIC_MEDIA1_AXI_SWITCH_MASK)
/*! @} */

/*! @name MEDIA_APB_SLAVE_GROUP0_RULE0 - APB Bridge Peripheral 0 Rule 0 */
/*! @{ */

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_RSTCTL4_MASK (0x3U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_RSTCTL4_SHIFT (0U)
/*! RSTCTL4 - RSTCTL4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_RSTCTL4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_RSTCTL4_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_RSTCTL4_MASK)

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_CLKCTL4_MASK (0x30U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_CLKCTL4_SHIFT (4U)
/*! CLKCTL4 - CLKCTL4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_CLKCTL4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_CLKCTL4_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_CLKCTL4_MASK)

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_SYSCON4_MASK (0x300U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_SYSCON4_SHIFT (8U)
/*! SYSCON4 - SYSCON4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_SYSCON4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_SYSCON4_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_SYSCON4_MASK)

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_IOPCTL2_MASK (0x300000U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_IOPCTL2_SHIFT (20U)
/*! IOPCTL2 - IOPCTL2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_IOPCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_IOPCTL2_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_IOPCTL2_MASK)

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_JPEGDEC_MASK (0x3000000U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_JPEGDEC_SHIFT (24U)
/*! JPEGDEC - JPEGDEC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_JPEGDEC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_JPEGDEC_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_JPEGDEC_MASK)

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_PNGDEC_MASK (0x30000000U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_PNGDEC_SHIFT (28U)
/*! PNGDEC - JPEG
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_PNGDEC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_PNGDEC_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE0_PNGDEC_MASK)
/*! @} */

/*! @name MEDIA_APB_SLAVE_GROUP0_RULE1 - APB Bridge Peripheral 0 Rule Register 1 */
/*! @{ */

#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE1_MMU2_MASK (0x3U)
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE1_MMU2_SHIFT (0U)
/*! MMU2 - MMU2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE1_MMU2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE1_MMU2_SHIFT)) & AHBSC4_MEDIA_APB_SLAVE_GROUP0_RULE1_MMU2_MASK)
/*! @} */

/*! @name EZHV_SRAM_RULE - EZHV SRAM Rule Register */
/*! @{ */

#define AHBSC4_EZHV_SRAM_RULE_RULE0_MASK         (0x3U)
#define AHBSC4_EZHV_SRAM_RULE_RULE0_SHIFT        (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE0(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE0_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE0_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE1_MASK         (0x30U)
#define AHBSC4_EZHV_SRAM_RULE_RULE1_SHIFT        (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE1(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE1_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE1_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE2_MASK         (0x300U)
#define AHBSC4_EZHV_SRAM_RULE_RULE2_SHIFT        (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE2(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE2_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE2_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE3_MASK         (0x3000U)
#define AHBSC4_EZHV_SRAM_RULE_RULE3_SHIFT        (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE3(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE3_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE3_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE4_MASK         (0x30000U)
#define AHBSC4_EZHV_SRAM_RULE_RULE4_SHIFT        (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE4(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE4_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE4_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE5_MASK         (0x300000U)
#define AHBSC4_EZHV_SRAM_RULE_RULE5_SHIFT        (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE5(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE5_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE5_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE6_MASK         (0x3000000U)
#define AHBSC4_EZHV_SRAM_RULE_RULE6_SHIFT        (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE6(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE6_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE6_MASK)

#define AHBSC4_EZHV_SRAM_RULE_RULE7_MASK         (0x30000000U)
#define AHBSC4_EZHV_SRAM_RULE_RULE7_SHIFT        (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_EZHV_SRAM_RULE_RULE7(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_EZHV_SRAM_RULE_RULE7_SHIFT)) & AHBSC4_EZHV_SRAM_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_0_RULE - RAM partition 0 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_0_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_0_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE0_MASK)

#define AHBSC4_SRAM_0_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_0_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE1_MASK)

#define AHBSC4_SRAM_0_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_0_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE2_MASK)

#define AHBSC4_SRAM_0_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_0_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE3_MASK)

#define AHBSC4_SRAM_0_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_0_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE4_MASK)

#define AHBSC4_SRAM_0_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_0_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE5_MASK)

#define AHBSC4_SRAM_0_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_0_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE6_MASK)

#define AHBSC4_SRAM_0_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_0_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_0_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_0_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_0_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_1_RULE - RAM partition 1 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_1_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_1_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE0_MASK)

#define AHBSC4_SRAM_1_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_1_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE1_MASK)

#define AHBSC4_SRAM_1_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_1_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE2_MASK)

#define AHBSC4_SRAM_1_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_1_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE3_MASK)

#define AHBSC4_SRAM_1_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_1_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE4_MASK)

#define AHBSC4_SRAM_1_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_1_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE5_MASK)

#define AHBSC4_SRAM_1_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_1_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE6_MASK)

#define AHBSC4_SRAM_1_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_1_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_1_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_1_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_1_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_2_RULE - RAM partition 2 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_2_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_2_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE0_MASK)

#define AHBSC4_SRAM_2_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_2_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE1_MASK)

#define AHBSC4_SRAM_2_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_2_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE2_MASK)

#define AHBSC4_SRAM_2_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_2_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE3_MASK)

#define AHBSC4_SRAM_2_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_2_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE4_MASK)

#define AHBSC4_SRAM_2_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_2_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE5_MASK)

#define AHBSC4_SRAM_2_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_2_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE6_MASK)

#define AHBSC4_SRAM_2_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_2_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_2_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_2_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_2_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_3_RULE - RAM partition 3 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_3_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_3_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE0_MASK)

#define AHBSC4_SRAM_3_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_3_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE1_MASK)

#define AHBSC4_SRAM_3_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_3_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE2_MASK)

#define AHBSC4_SRAM_3_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_3_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE3_MASK)

#define AHBSC4_SRAM_3_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_3_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE4_MASK)

#define AHBSC4_SRAM_3_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_3_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE5_MASK)

#define AHBSC4_SRAM_3_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_3_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE6_MASK)

#define AHBSC4_SRAM_3_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_3_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_3_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_3_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_3_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_4_RULE - RAM partition 4 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_4_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_4_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE0_MASK)

#define AHBSC4_SRAM_4_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_4_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE1_MASK)

#define AHBSC4_SRAM_4_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_4_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE2_MASK)

#define AHBSC4_SRAM_4_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_4_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE3_MASK)

#define AHBSC4_SRAM_4_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_4_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE4_MASK)

#define AHBSC4_SRAM_4_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_4_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE5_MASK)

#define AHBSC4_SRAM_4_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_4_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE6_MASK)

#define AHBSC4_SRAM_4_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_4_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_4_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_4_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_4_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_5_RULE - RAM partition 5 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_5_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_5_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE0_MASK)

#define AHBSC4_SRAM_5_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_5_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE1_MASK)

#define AHBSC4_SRAM_5_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_5_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE2_MASK)

#define AHBSC4_SRAM_5_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_5_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE3_MASK)

#define AHBSC4_SRAM_5_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_5_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE4_MASK)

#define AHBSC4_SRAM_5_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_5_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE5_MASK)

#define AHBSC4_SRAM_5_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_5_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE6_MASK)

#define AHBSC4_SRAM_5_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_5_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_5_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_5_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_5_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_6_RULE - RAM partition 6 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_6_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_6_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE0_MASK)

#define AHBSC4_SRAM_6_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_6_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE1_MASK)

#define AHBSC4_SRAM_6_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_6_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE2_MASK)

#define AHBSC4_SRAM_6_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_6_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE3_MASK)

#define AHBSC4_SRAM_6_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_6_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE4_MASK)

#define AHBSC4_SRAM_6_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_6_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE5_MASK)

#define AHBSC4_SRAM_6_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_6_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE6_MASK)

#define AHBSC4_SRAM_6_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_6_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_6_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_6_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_6_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_7_RULE - RAM partition 7 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_7_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_7_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE0_MASK)

#define AHBSC4_SRAM_7_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_7_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE1_MASK)

#define AHBSC4_SRAM_7_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_7_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE2_MASK)

#define AHBSC4_SRAM_7_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_7_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE3_MASK)

#define AHBSC4_SRAM_7_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_7_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE4_MASK)

#define AHBSC4_SRAM_7_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_7_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE5_MASK)

#define AHBSC4_SRAM_7_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_7_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE6_MASK)

#define AHBSC4_SRAM_7_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_7_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_7_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_7_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_7_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_8_RULE - RAM partition 8 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_8_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_8_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE0_MASK)

#define AHBSC4_SRAM_8_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_8_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE1_MASK)

#define AHBSC4_SRAM_8_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_8_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE2_MASK)

#define AHBSC4_SRAM_8_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_8_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE3_MASK)

#define AHBSC4_SRAM_8_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_8_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE4_MASK)

#define AHBSC4_SRAM_8_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_8_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE5_MASK)

#define AHBSC4_SRAM_8_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_8_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE6_MASK)

#define AHBSC4_SRAM_8_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_8_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_8_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_8_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_8_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_9_RULE - RAM partition 9 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_9_RULE_RULE0_MASK            (0x3U)
#define AHBSC4_SRAM_9_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE0_MASK)

#define AHBSC4_SRAM_9_RULE_RULE1_MASK            (0x30U)
#define AHBSC4_SRAM_9_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE1_MASK)

#define AHBSC4_SRAM_9_RULE_RULE2_MASK            (0x300U)
#define AHBSC4_SRAM_9_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE2_MASK)

#define AHBSC4_SRAM_9_RULE_RULE3_MASK            (0x3000U)
#define AHBSC4_SRAM_9_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE3_MASK)

#define AHBSC4_SRAM_9_RULE_RULE4_MASK            (0x30000U)
#define AHBSC4_SRAM_9_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE4_MASK)

#define AHBSC4_SRAM_9_RULE_RULE5_MASK            (0x300000U)
#define AHBSC4_SRAM_9_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE5_MASK)

#define AHBSC4_SRAM_9_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC4_SRAM_9_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE6_MASK)

#define AHBSC4_SRAM_9_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC4_SRAM_9_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_9_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_9_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_9_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_10_RULE - RAM partition 10 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_10_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_10_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE0_MASK)

#define AHBSC4_SRAM_10_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_10_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE1_MASK)

#define AHBSC4_SRAM_10_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_10_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE2_MASK)

#define AHBSC4_SRAM_10_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_10_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE3_MASK)

#define AHBSC4_SRAM_10_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_10_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE4_MASK)

#define AHBSC4_SRAM_10_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_10_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE5_MASK)

#define AHBSC4_SRAM_10_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_10_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE6_MASK)

#define AHBSC4_SRAM_10_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_10_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_10_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_10_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_10_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_11_RULE - RAM partition 11 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_11_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_11_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE0_MASK)

#define AHBSC4_SRAM_11_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_11_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE1_MASK)

#define AHBSC4_SRAM_11_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_11_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE2_MASK)

#define AHBSC4_SRAM_11_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_11_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE3_MASK)

#define AHBSC4_SRAM_11_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_11_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE4_MASK)

#define AHBSC4_SRAM_11_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_11_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE5_MASK)

#define AHBSC4_SRAM_11_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_11_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE6_MASK)

#define AHBSC4_SRAM_11_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_11_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_11_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_11_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_11_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_12_RULE - RAM partition 12 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_12_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_12_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE0_MASK)

#define AHBSC4_SRAM_12_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_12_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE1_MASK)

#define AHBSC4_SRAM_12_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_12_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE2_MASK)

#define AHBSC4_SRAM_12_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_12_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE3_MASK)

#define AHBSC4_SRAM_12_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_12_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE4_MASK)

#define AHBSC4_SRAM_12_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_12_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE5_MASK)

#define AHBSC4_SRAM_12_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_12_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE6_MASK)

#define AHBSC4_SRAM_12_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_12_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_12_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_12_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_12_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_13_RULE - RAM partition 13 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_13_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_13_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE0_MASK)

#define AHBSC4_SRAM_13_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_13_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE1_MASK)

#define AHBSC4_SRAM_13_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_13_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE2_MASK)

#define AHBSC4_SRAM_13_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_13_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE3_MASK)

#define AHBSC4_SRAM_13_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_13_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE4_MASK)

#define AHBSC4_SRAM_13_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_13_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE5_MASK)

#define AHBSC4_SRAM_13_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_13_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE6_MASK)

#define AHBSC4_SRAM_13_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_13_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_13_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_13_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_13_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_14_RULE - RAM partition 14 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_14_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_14_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE0_MASK)

#define AHBSC4_SRAM_14_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_14_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE1_MASK)

#define AHBSC4_SRAM_14_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_14_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE2_MASK)

#define AHBSC4_SRAM_14_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_14_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE3_MASK)

#define AHBSC4_SRAM_14_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_14_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE4_MASK)

#define AHBSC4_SRAM_14_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_14_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE5_MASK)

#define AHBSC4_SRAM_14_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_14_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE6_MASK)

#define AHBSC4_SRAM_14_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_14_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_14_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_14_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_14_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_15_RULE - RAM partition 15 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_15_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_15_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE0_MASK)

#define AHBSC4_SRAM_15_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_15_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE1_MASK)

#define AHBSC4_SRAM_15_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_15_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE2_MASK)

#define AHBSC4_SRAM_15_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_15_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE3_MASK)

#define AHBSC4_SRAM_15_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_15_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE4_MASK)

#define AHBSC4_SRAM_15_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_15_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE5_MASK)

#define AHBSC4_SRAM_15_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_15_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE6_MASK)

#define AHBSC4_SRAM_15_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_15_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_15_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_15_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_15_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_16_RULE - RAM partition 16 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_16_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_16_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE0_MASK)

#define AHBSC4_SRAM_16_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_16_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE1_MASK)

#define AHBSC4_SRAM_16_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_16_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE2_MASK)

#define AHBSC4_SRAM_16_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_16_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE3_MASK)

#define AHBSC4_SRAM_16_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_16_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE4_MASK)

#define AHBSC4_SRAM_16_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_16_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE5_MASK)

#define AHBSC4_SRAM_16_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_16_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE6_MASK)

#define AHBSC4_SRAM_16_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_16_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_16_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_16_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_16_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_17_RULE - RAM partition 17 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_17_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_17_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE0_MASK)

#define AHBSC4_SRAM_17_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_17_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE1_MASK)

#define AHBSC4_SRAM_17_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_17_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE2_MASK)

#define AHBSC4_SRAM_17_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_17_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE3_MASK)

#define AHBSC4_SRAM_17_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_17_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE4_MASK)

#define AHBSC4_SRAM_17_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_17_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE5_MASK)

#define AHBSC4_SRAM_17_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_17_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE6_MASK)

#define AHBSC4_SRAM_17_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_17_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_17_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_17_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_17_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_18_RULE - RAM partition 18 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_18_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_18_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE0_MASK)

#define AHBSC4_SRAM_18_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_18_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE1_MASK)

#define AHBSC4_SRAM_18_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_18_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE2_MASK)

#define AHBSC4_SRAM_18_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_18_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE3_MASK)

#define AHBSC4_SRAM_18_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_18_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE4_MASK)

#define AHBSC4_SRAM_18_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_18_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE5_MASK)

#define AHBSC4_SRAM_18_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_18_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE6_MASK)

#define AHBSC4_SRAM_18_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_18_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_18_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_18_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_18_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_19_RULE - RAM partition 19 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_19_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_19_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE0_MASK)

#define AHBSC4_SRAM_19_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_19_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE1_MASK)

#define AHBSC4_SRAM_19_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_19_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE2_MASK)

#define AHBSC4_SRAM_19_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_19_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE3_MASK)

#define AHBSC4_SRAM_19_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_19_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE4_MASK)

#define AHBSC4_SRAM_19_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_19_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE5_MASK)

#define AHBSC4_SRAM_19_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_19_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE6_MASK)

#define AHBSC4_SRAM_19_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_19_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_19_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_19_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_19_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_20_RULE - RAM partition 20 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_20_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_20_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE0_MASK)

#define AHBSC4_SRAM_20_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_20_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE1_MASK)

#define AHBSC4_SRAM_20_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_20_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE2_MASK)

#define AHBSC4_SRAM_20_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_20_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE3_MASK)

#define AHBSC4_SRAM_20_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_20_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE4_MASK)

#define AHBSC4_SRAM_20_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_20_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE5_MASK)

#define AHBSC4_SRAM_20_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_20_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE6_MASK)

#define AHBSC4_SRAM_20_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_20_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_20_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_20_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_20_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_21_RULE - RAM partition 21 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_21_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_21_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE0_MASK)

#define AHBSC4_SRAM_21_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_21_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE1_MASK)

#define AHBSC4_SRAM_21_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_21_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE2_MASK)

#define AHBSC4_SRAM_21_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_21_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE3_MASK)

#define AHBSC4_SRAM_21_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_21_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE4_MASK)

#define AHBSC4_SRAM_21_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_21_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE5_MASK)

#define AHBSC4_SRAM_21_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_21_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE6_MASK)

#define AHBSC4_SRAM_21_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_21_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_21_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_21_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_21_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_22_RULE - RAM partition 22 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_22_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_22_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE0_MASK)

#define AHBSC4_SRAM_22_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_22_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE1_MASK)

#define AHBSC4_SRAM_22_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_22_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE2_MASK)

#define AHBSC4_SRAM_22_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_22_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE3_MASK)

#define AHBSC4_SRAM_22_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_22_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE4_MASK)

#define AHBSC4_SRAM_22_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_22_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE5_MASK)

#define AHBSC4_SRAM_22_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_22_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE6_MASK)

#define AHBSC4_SRAM_22_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_22_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_22_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_22_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_22_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_23_RULE - RAM partition 23 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_23_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_23_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE0_MASK)

#define AHBSC4_SRAM_23_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_23_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE1_MASK)

#define AHBSC4_SRAM_23_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_23_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE2_MASK)

#define AHBSC4_SRAM_23_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_23_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE3_MASK)

#define AHBSC4_SRAM_23_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_23_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE4_MASK)

#define AHBSC4_SRAM_23_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_23_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE5_MASK)

#define AHBSC4_SRAM_23_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_23_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE6_MASK)

#define AHBSC4_SRAM_23_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_23_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_23_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_23_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_23_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_24_RULE - RAM partition 24 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_24_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_24_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE0_MASK)

#define AHBSC4_SRAM_24_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_24_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE1_MASK)

#define AHBSC4_SRAM_24_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_24_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE2_MASK)

#define AHBSC4_SRAM_24_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_24_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE3_MASK)

#define AHBSC4_SRAM_24_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_24_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE4_MASK)

#define AHBSC4_SRAM_24_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_24_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE5_MASK)

#define AHBSC4_SRAM_24_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_24_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE6_MASK)

#define AHBSC4_SRAM_24_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_24_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_24_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_24_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_24_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_25_RULE - RAM partition 25 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_25_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_25_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE0_MASK)

#define AHBSC4_SRAM_25_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_25_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE1_MASK)

#define AHBSC4_SRAM_25_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_25_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE2_MASK)

#define AHBSC4_SRAM_25_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_25_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE3_MASK)

#define AHBSC4_SRAM_25_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_25_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE4_MASK)

#define AHBSC4_SRAM_25_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_25_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE5_MASK)

#define AHBSC4_SRAM_25_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_25_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE6_MASK)

#define AHBSC4_SRAM_25_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_25_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_25_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_25_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_25_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_26_RULE - RAM partition 26 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_26_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_26_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE0_MASK)

#define AHBSC4_SRAM_26_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_26_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE1_MASK)

#define AHBSC4_SRAM_26_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_26_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE2_MASK)

#define AHBSC4_SRAM_26_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_26_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE3_MASK)

#define AHBSC4_SRAM_26_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_26_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE4_MASK)

#define AHBSC4_SRAM_26_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_26_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE5_MASK)

#define AHBSC4_SRAM_26_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_26_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE6_MASK)

#define AHBSC4_SRAM_26_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_26_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_26_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_26_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_26_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_27_RULE - RAM partition 27 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_27_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_27_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE0_MASK)

#define AHBSC4_SRAM_27_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_27_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE1_MASK)

#define AHBSC4_SRAM_27_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_27_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE2_MASK)

#define AHBSC4_SRAM_27_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_27_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE3_MASK)

#define AHBSC4_SRAM_27_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_27_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE4_MASK)

#define AHBSC4_SRAM_27_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_27_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE5_MASK)

#define AHBSC4_SRAM_27_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_27_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE6_MASK)

#define AHBSC4_SRAM_27_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_27_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_27_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_27_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_27_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_28_RULE - RAM partition 28 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_28_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_28_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE0_MASK)

#define AHBSC4_SRAM_28_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_28_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE1_MASK)

#define AHBSC4_SRAM_28_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_28_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE2_MASK)

#define AHBSC4_SRAM_28_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_28_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE3_MASK)

#define AHBSC4_SRAM_28_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_28_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE4_MASK)

#define AHBSC4_SRAM_28_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_28_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE5_MASK)

#define AHBSC4_SRAM_28_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_28_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE6_MASK)

#define AHBSC4_SRAM_28_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_28_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_28_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_28_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_28_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_29_RULE - RAM partition 29 Memory Rule Register */
/*! @{ */

#define AHBSC4_SRAM_29_RULE_RULE0_MASK           (0x3U)
#define AHBSC4_SRAM_29_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE0_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE0_MASK)

#define AHBSC4_SRAM_29_RULE_RULE1_MASK           (0x30U)
#define AHBSC4_SRAM_29_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE1_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE1_MASK)

#define AHBSC4_SRAM_29_RULE_RULE2_MASK           (0x300U)
#define AHBSC4_SRAM_29_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE2_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE2_MASK)

#define AHBSC4_SRAM_29_RULE_RULE3_MASK           (0x3000U)
#define AHBSC4_SRAM_29_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE3_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE3_MASK)

#define AHBSC4_SRAM_29_RULE_RULE4_MASK           (0x30000U)
#define AHBSC4_SRAM_29_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE4_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE4_MASK)

#define AHBSC4_SRAM_29_RULE_RULE5_MASK           (0x300000U)
#define AHBSC4_SRAM_29_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE5_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE5_MASK)

#define AHBSC4_SRAM_29_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC4_SRAM_29_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE6_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE6_MASK)

#define AHBSC4_SRAM_29_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC4_SRAM_29_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_SRAM_29_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC4_SRAM_29_RULE_RULE7_SHIFT)) & AHBSC4_SRAM_29_RULE_RULE7_MASK)
/*! @} */

/*! @name XSPI2_REGION0_MEM_RULE - XSPI2 Region0 Memory Rule Register */
/*! @{ */

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE0_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE0_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE1_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE1_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE2_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE2_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE3_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE3_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE4(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE4_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE4_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE5(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE5_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE5_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE6(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE6_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE6_MASK)

#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_RULE7(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION0_MEM_RULE_RULE7_SHIFT)) & AHBSC4_XSPI2_REGION0_MEM_RULE_RULE7_MASK)
/*! @} */

/* The count of AHBSC4_XSPI2_REGION0_MEM_RULE */
#define AHBSC4_XSPI2_REGION0_MEM_RULE_COUNT      (4U)

/*! @name XSPI2_REGION_MEM_RULE0 - XSPI2 Region 1 Memory Rule Register..XSPI2 Region 5 Memory Rule Register */
/*! @{ */

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE0_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE0_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE1_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE1_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE2_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE2_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE3_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE3_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE4_MASK (0x30000U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE4(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE4_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE4_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE5_MASK (0x300000U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE5(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE5_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE5_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE6_MASK (0x3000000U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE6(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE6_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE6_MASK)

#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE7_MASK (0x30000000U)
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_RULE7(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_XSPI2_REGION_MEM_RULE0_RULE7_SHIFT)) & AHBSC4_XSPI2_REGION_MEM_RULE0_RULE7_MASK)
/*! @} */

/* The count of AHBSC4_XSPI2_REGION_MEM_RULE0 */
#define AHBSC4_XSPI2_REGION_MEM_RULE0_COUNT      (5U)

/*! @name SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC4_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK    (0xFFFFFFFFU)
#define AHBSC4_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT   (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC4_SEC_VIO_ADDR_SEC_VIO_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC4_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC4_SEC_VIO_ADDR */
#define AHBSC4_SEC_VIO_ADDR_COUNT                (13U)

/*! @name SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0x1F00U)
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - Security violation master number
 *  0b00000..CPU0 System
 *  0b00001..eDMA0
 *  0b00010..eDMA1
 *  0b00011..ELS
 *  0b00100..HIFI4
 *  0b00101..CPU1 system
 *  0b00110..eDMA2
 *  0b00111..eDMA3
 *  0b01000..HIFI1
 *  0b01001..EZH-V
 *  0b01010..PKC
 *  0b01011..USDHC0
 *  0b01100..USB0
 *  0b01101..GPU
 *  0b01110..ETR
 *  0b01111..DAP
 *  0b10000..CPU0 Code
 *  0b10001..Reserved
 *  0b10010..Reserved
 *  0b10011..Reserved
 *  0b10100..Reserved
 *  0b10101..CPU1 code
 *  0b10110..JPEGDEC
 *  0b10111..PNGDEC
 *  0b11000..Reserved
 *  0b11001..Reserved
 *  0b11010..Reserved
 *  0b11011..USDHC1
 *  0b11100..USB1
 *  0b11101..LCDIF
 *  0b11110..MTR
 *  0b11111..Test port
 */
#define AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC4_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC4_SEC_VIO_MISC_INFO */
#define AHBSC4_SEC_VIO_MISC_INFO_COUNT           (13U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHBSC4_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC4_MASTER_SEC_LEVEL_EZHV_MASK        (0x3U)
#define AHBSC4_MASTER_SEC_LEVEL_EZHV_SHIFT       (0U)
/*! EZHV - EZHV
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_EZHV(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_EZHV_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_EZHV_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_SDHC0_MASK       (0xCU)
#define AHBSC4_MASTER_SEC_LEVEL_SDHC0_SHIFT      (2U)
/*! SDHC0 - SDHC0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_SDHC0(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_SDHC0_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_SDHC0_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_SDHC1_MASK       (0x30U)
#define AHBSC4_MASTER_SEC_LEVEL_SDHC1_SHIFT      (4U)
/*! SDHC1 - SDHC1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_SDHC1(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_SDHC1_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_SDHC1_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_USB0_MASK        (0xC0U)
#define AHBSC4_MASTER_SEC_LEVEL_USB0_SHIFT       (6U)
/*! USB0 - USB0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_USB0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_USB0_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_USB0_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_USB1_MASK        (0x300U)
#define AHBSC4_MASTER_SEC_LEVEL_USB1_SHIFT       (8U)
/*! USB1 - USB1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_USB1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_USB1_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_USB1_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_LCDIF_MASK       (0xC00U)
#define AHBSC4_MASTER_SEC_LEVEL_LCDIF_SHIFT      (10U)
/*! LCDIF - LCDIF
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_LCDIF(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_LCDIF_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_LCDIF_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_GPU_MASK         (0x3000U)
#define AHBSC4_MASTER_SEC_LEVEL_GPU_SHIFT        (12U)
/*! GPU - GPU
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_GPU(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_GPU_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_GPU_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_JPEG_MASK        (0xC000U)
#define AHBSC4_MASTER_SEC_LEVEL_JPEG_SHIFT       (14U)
/*! JPEG - JPEG
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_JPEG(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_JPEG_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_JPEG_MASK)

#define AHBSC4_MASTER_SEC_LEVEL_PNG_MASK         (0x30000U)
#define AHBSC4_MASTER_SEC_LEVEL_PNG_SHIFT        (16U)
/*! PNG - PNG
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC4_MASTER_SEC_LEVEL_PNG(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_LEVEL_PNG_SHIFT)) & AHBSC4_MASTER_SEC_LEVEL_PNG_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_EZHV_MASK (0x3U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_EZHV_SHIFT (0U)
/*! EZHV - EZHV
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_EZHV(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_EZHV_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_EZHV_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC0_MASK (0xCU)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC0_SHIFT (2U)
/*! SDHC0 - SDHC0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC0(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC0_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC0_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC1_MASK (0x30U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC1_SHIFT (4U)
/*! SDHC1 - SDHC1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC1(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC1_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_SDHC1_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB0_MASK (0xC0U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB0_SHIFT (6U)
/*! USB0 - USB0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_USB0_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_USB0_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB1_MASK (0x300U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB1_SHIFT (8U)
/*! USB1 - USB1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_USB1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_USB1_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_USB1_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_LCDIF_MASK (0xC00U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_LCDIF_SHIFT (10U)
/*! LCDIF - LCDIF
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_LCDIF(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_LCDIF_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_LCDIF_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_GPU_MASK  (0x3000U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_GPU_SHIFT (12U)
/*! GPU - GPU
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_GPU(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_GPU_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_GPU_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_JPEG_MASK (0xC000U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_JPEG_SHIFT (14U)
/*! JPEG - JPEG
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_JPEG(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_JPEG_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_JPEG_MASK)

#define AHBSC4_MASTER_SEC_ANTI_POL_REG_PNG_MASK  (0x30000U)
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_PNG_SHIFT (16U)
/*! PNG - PNG
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC4_MASTER_SEC_ANTI_POL_REG_PNG(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC4_MASTER_SEC_ANTI_POL_REG_PNG_SHIFT)) & AHBSC4_MASTER_SEC_ANTI_POL_REG_PNG_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define AHBSC4_MISC_CTRL_DP_REG_WRITE_LOCK_MASK  (0x3U)
#define AHBSC4_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_WRITE_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC4_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC4_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHBSC4_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHBSC4_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define AHBSC4_MISC_CTRL_REG_WRITE_LOCK_MASK     (0x3U)
#define AHBSC4_MISC_CTRL_REG_WRITE_LOCK_SHIFT    (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_WRITE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHBSC4_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHBSC4_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC4_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC4_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC4_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC4_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC4_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC4_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC4_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC4_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC4_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC4_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC4_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC4_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC4_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC4_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC4_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC4_MISC_CTRL_REG_IDAU_ALL_NS_MASK    (0xC000U)
#define AHBSC4_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT   (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC4_MISC_CTRL_REG_IDAU_ALL_NS(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC4_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHBSC4_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBSC4_Register_Masks */


/*!
 * @}
 */ /* end of group AHBSC4_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBSC4_H_ */

