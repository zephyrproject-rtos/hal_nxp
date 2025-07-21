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
**         CMSIS Peripheral Access Layer for AHBSC3
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
 * @file PERI_AHBSC3.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBSC3
 *
 * CMSIS Peripheral Access Layer for AHBSC3
 */

#if !defined(PERI_AHBSC3_H_)
#define PERI_AHBSC3_H_                           /**< Symbol preventing repeated inclusion */

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
   -- AHBSC3 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC3_Peripheral_Access_Layer AHBSC3 Peripheral Access Layer
 * @{
 */

/** AHBSC3 - Size of Registers Arrays */
#define AHBSC3_SRAM_0_RULE_COUNT                  4u
#define AHBSC3_SRAM_1_RULE_COUNT                  4u
#define AHBSC3_SRAM_2_RULE_COUNT                  4u
#define AHBSC3_SRAM_3_RULE_COUNT                  4u
#define AHBSC3_SRAM_4_RULE_COUNT                  4u
#define AHBSC3_SRAM_5_RULE_COUNT                  4u
#define AHBSC3_SRAM_6_RULE_COUNT                  4u
#define AHBSC3_SRAM_7_RULE_COUNT                  4u
#define AHBSC3_SRAM_8_RULE_COUNT                  4u
#define AHBSC3_SRAM_9_RULE_COUNT                  4u
#define AHBSC3_SRAM_10_RULE_COUNT                 4u
#define AHBSC3_SRAM_11_RULE_COUNT                 4u
#define AHBSC3_SRAM_12_RULE_COUNT                 4u
#define AHBSC3_SRAM_13_RULE_COUNT                 4u
#define AHBSC3_SRAM_14_RULE_COUNT                 4u
#define AHBSC3_SRAM_15_RULE_COUNT                 4u
#define AHBSC3_SRAM_16_RULE_COUNT                 4u
#define AHBSC3_SRAM_17_RULE_COUNT                 4u
#define AHBSC3_SRAM_18_RULE_COUNT                 4u
#define AHBSC3_SRAM_19_RULE_COUNT                 4u
#define AHBSC3_SRAM_20_RULE_COUNT                 4u
#define AHBSC3_SRAM_21_RULE_COUNT                 4u
#define AHBSC3_SRAM_22_RULE_COUNT                 4u
#define AHBSC3_SRAM_23_RULE_COUNT                 4u
#define AHBSC3_SRAM_24_RULE_COUNT                 4u
#define AHBSC3_SRAM_25_RULE_COUNT                 4u
#define AHBSC3_SRAM_26_RULE_COUNT                 4u
#define AHBSC3_SRAM_27_RULE_COUNT                 4u
#define AHBSC3_SRAM_28_RULE_COUNT                 4u
#define AHBSC3_SRAM_29_RULE_COUNT                 4u
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPION_RULE_COUNT 3u
#define AHBSC3_SEC_VIO_ADDRN_COUNT                17u
#define AHBSC3_SEC_VIO_MISC_INFON_COUNT           17u

/** AHBSC3 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SRAM_0_RULE[AHBSC3_SRAM_0_RULE_COUNT]; /**< RAM partition 0 Memory Rule Register, array offset: 0x10, array step: 0x4 */
  __IO uint32_t SRAM_1_RULE[AHBSC3_SRAM_1_RULE_COUNT]; /**< RAM partition 1 Memory Rule Register, array offset: 0x20, array step: 0x4 */
  __IO uint32_t SRAM_2_RULE[AHBSC3_SRAM_2_RULE_COUNT]; /**< RAM partition 2 Memory Rule Register, array offset: 0x30, array step: 0x4 */
  __IO uint32_t SRAM_3_RULE[AHBSC3_SRAM_3_RULE_COUNT]; /**< RAM partition 3 Memory Rule Register, array offset: 0x40, array step: 0x4 */
  __IO uint32_t SRAM_4_RULE[AHBSC3_SRAM_4_RULE_COUNT]; /**< RAM partition 4 Memory Rule Register, array offset: 0x50, array step: 0x4 */
  __IO uint32_t SRAM_5_RULE[AHBSC3_SRAM_5_RULE_COUNT]; /**< RAM partition 5 Memory Rule Register, array offset: 0x60, array step: 0x4 */
  __IO uint32_t SRAM_6_RULE[AHBSC3_SRAM_6_RULE_COUNT]; /**< RAM partition 6 Memory Rule Register, array offset: 0x70, array step: 0x4 */
  __IO uint32_t SRAM_7_RULE[AHBSC3_SRAM_7_RULE_COUNT]; /**< RAM partition 7 Memory Rule Register, array offset: 0x80, array step: 0x4 */
  __IO uint32_t SRAM_8_RULE[AHBSC3_SRAM_8_RULE_COUNT]; /**< RAM partition 8 Memory Rule Register, array offset: 0x90, array step: 0x4 */
  __IO uint32_t SRAM_9_RULE[AHBSC3_SRAM_9_RULE_COUNT]; /**< RAM partition 9 Memory Rule Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t SRAM_10_RULE[AHBSC3_SRAM_10_RULE_COUNT]; /**< RAM partition 10 Memory Rule Register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t SRAM_11_RULE[AHBSC3_SRAM_11_RULE_COUNT]; /**< RAM partition 11 Memory Rule Register, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t SRAM_12_RULE[AHBSC3_SRAM_12_RULE_COUNT]; /**< RAM partition 12 Memory Rule Register, array offset: 0xF0, array step: 0x4 */
  __IO uint32_t SRAM_13_RULE[AHBSC3_SRAM_13_RULE_COUNT]; /**< RAM partition 13 Memory Rule Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t SRAM_14_RULE[AHBSC3_SRAM_14_RULE_COUNT]; /**< RAM partition 14 Memory Rule Register, array offset: 0x120, array step: 0x4 */
  __IO uint32_t SRAM_15_RULE[AHBSC3_SRAM_15_RULE_COUNT]; /**< RAM partition 15 Memory Rule Register, array offset: 0x130, array step: 0x4 */
       uint8_t RESERVED_4[16];
  __IO uint32_t SRAM_16_RULE[AHBSC3_SRAM_16_RULE_COUNT]; /**< RAM partition 16 Memory Rule Register, array offset: 0x150, array step: 0x4 */
  __IO uint32_t SRAM_17_RULE[AHBSC3_SRAM_17_RULE_COUNT]; /**< RAM partition 17 Memory Rule Register, array offset: 0x160, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t SRAM_18_RULE[AHBSC3_SRAM_18_RULE_COUNT]; /**< RAM partition 18 Memory Rule Register, array offset: 0x180, array step: 0x4 */
  __IO uint32_t SRAM_19_RULE[AHBSC3_SRAM_19_RULE_COUNT]; /**< RAM partition 19 Memory Rule Register, array offset: 0x190, array step: 0x4 */
  __IO uint32_t SRAM_20_RULE[AHBSC3_SRAM_20_RULE_COUNT]; /**< RAM partition 20 Memory Rule Register, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t SRAM_21_RULE[AHBSC3_SRAM_21_RULE_COUNT]; /**< RAM partition 21 Memory Rule Register, array offset: 0x1B0, array step: 0x4 */
       uint8_t RESERVED_6[16];
  __IO uint32_t SRAM_22_RULE[AHBSC3_SRAM_22_RULE_COUNT]; /**< RAM partition 22 Memory Rule Register, array offset: 0x1D0, array step: 0x4 */
  __IO uint32_t SRAM_23_RULE[AHBSC3_SRAM_23_RULE_COUNT]; /**< RAM partition 23 Memory Rule Register, array offset: 0x1E0, array step: 0x4 */
       uint8_t RESERVED_7[16];
  __IO uint32_t SRAM_24_RULE[AHBSC3_SRAM_24_RULE_COUNT]; /**< RAM partition 24 Memory Rule Register, array offset: 0x200, array step: 0x4 */
  __IO uint32_t SRAM_25_RULE[AHBSC3_SRAM_25_RULE_COUNT]; /**< RAM partition 25 Memory Rule Register, array offset: 0x210, array step: 0x4 */
       uint8_t RESERVED_8[16];
  __IO uint32_t SRAM_26_RULE[AHBSC3_SRAM_26_RULE_COUNT]; /**< RAM partition 26 Memory Rule Register, array offset: 0x230, array step: 0x4 */
  __IO uint32_t SRAM_27_RULE[AHBSC3_SRAM_27_RULE_COUNT]; /**< RAM partition 27 Memory Rule Register, array offset: 0x240, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t SRAM_28_RULE[AHBSC3_SRAM_28_RULE_COUNT]; /**< RAM partition 28 Memory Rule Register, array offset: 0x260, array step: 0x4 */
  __IO uint32_t SRAM_29_RULE[AHBSC3_SRAM_29_RULE_COUNT]; /**< RAM partition 29 Memory Rule Register, array offset: 0x270, array step: 0x4 */
  __IO uint32_t AHB_PERIPHERAL10_SLAVE_RULE0;      /**< AHB Peripheral 10 Slaves Rule Register 0, offset: 0x280 */
  __IO uint32_t AHB_PERIPHERAL10_SLAVE_RULE1;      /**< AHB Peripheral 10 Slaves Rule Register 1, offset: 0x284 */
       uint8_t RESERVED_10[8];
  __IO uint32_t AIPS5_BRIDGE_GROUP0_MEM_RULE0;     /**< AIPS5 Bridge Group 0 Memory Rule Register 0, offset: 0x290 */
  __IO uint32_t AIPS5_BRIDGE_GROUP0_MEM_RULE1;     /**< AIPS5 Bridge Group 0 Memory Rule Register 1, offset: 0x294 */
  __IO uint32_t AIPS5_BRIDGE_GROUP0_MEM_RULE2;     /**< AIPS5 Bridge Group 0 Memory Rule Register 2, offset: 0x298 */
  __IO uint32_t AIPS5_BRIDGE_GROUP0_MEM_RULE3;     /**< AIPS5 Bridge Group 0 Memory Rule Register 3, offset: 0x29C */
  struct {                                         /* offset: 0x2A0, array step: 0x10 */
    __IO uint32_t AHB_PERIPHERAL10_SLAVE_GPIO_RULE;   /**< AHB Peripheral 10 Slaves GPIO8 Rule Register..AHB Peripheral 10 Slaves GPIO10 Rule Register, array offset: 0x2A0, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } AHB_PERIPHERAL10_SLAVE_GPION_RULE[AHBSC3_AHB_PERIPHERAL10_SLAVE_GPION_RULE_COUNT];
       uint8_t RESERVED_11[16];
  __IO uint32_t AIPS2_BRIDGE_GROUP0_MEM_RULE0;     /**< AIPS2 Bridge Group 0 Memory Rule Register 0, offset: 0x2E0 */
  __IO uint32_t AIPS2_BRIDGE_GROUP0_MEM_RULE1;     /**< AIPS2 Bridge Group 0 Memory Rule Register 1, offset: 0x2E4 */
       uint8_t RESERVED_12[8];
  __IO uint32_t AIPS2_BRIDGE_GROUP1_MEM_RULE0;     /**< AIPS2 Bridge Group 1 Memory Rule Register 0, offset: 0x2F0 */
       uint8_t RESERVED_13[12];
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_RULE0;  /**< AHB Secure Control Peripheral Rule 0, offset: 0x300 */
       uint8_t RESERVED_14[44];
  __IO uint32_t SENSE_APB_SLAVE_GROUP0_RULE0;      /**< APB Bridge Peripheral 0 Rule 0, offset: 0x330 */
  __IO uint32_t SENSE_APB_SLAVE_GROUP0_RULE1;      /**< APB Bridge Peripheral 0 Rule Register 1, offset: 0x334 */
  __IO uint32_t SENSE_APB_SLAVE_GROUP0_RULE2;      /**< APB Bridge Peripheral 0 Rule Register 2, offset: 0x338 */
       uint8_t RESERVED_15[4];
  __IO uint32_t SHARED_APB_SLAVE_GROUP0_RULE0;     /**< Shared APB Bridge Peripheral 0 Rule 0, offset: 0x340 */
  __IO uint32_t SHARED_APB_SLAVE_GROUP0_RULE1;     /**< Shared APB Bridge Peripheral 0 Rule 1, offset: 0x344 */
       uint8_t RESERVED_16[8];
  __IO uint32_t SENSE2MEDIA_RULE;                  /**< SENSE domain to MEDIA domain Access Rule Register, offset: 0x350 */
       uint8_t RESERVED_17[12];
  __IO uint32_t MEDIA_AHB_PERIPHERAL_SLAVE_RULE0;  /**< MEDIA domain AHB peripheral slave, offset: 0x360 */
       uint8_t RESERVED_18[12];
  __IO uint32_t MEDIA_APB_PERIPHERAL_SLAVE_RULE0;  /**< MEDIA domain APB peripheral slave Rule Register, offset: 0x370 */
       uint8_t RESERVED_19[12];
  __IO uint32_t EZHV_SRAM_RULE0;                   /**< EZHV SRAM Memory Rule Register, offset: 0x380 */
       uint8_t RESERVED_20[2684];
  __I  uint32_t SEC_VIO_ADDR[AHBSC3_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_21[60];
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC3_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_22[60];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_23[124];
  __IO uint32_t COMPUTE_ARB1RAM_ACCESS_ENABLE;     /**< Access enable for COMPUTE domain masters to RAM partitions., offset: 0xF80 */
  __IO uint32_t SENSE_ARB1RAM_ACCESS_ENABLE;       /**< Access enable for SENSE domain masters to RAM partitions., offset: 0xF84 */
  __IO uint32_t MEDIA_ARB1RAM_ACCESS_ENABLE;       /**< Access enable for MEDIA domain masters to RAM partitions., offset: 0xF88 */
  __IO uint32_t NPU_ARB1RAM_ACCESS_ENABLE;         /**< Access enable for NPU to RAM partitions., offset: 0xF8C */
  __IO uint32_t HIFI4_ARB1RAM_ACCESS_ENABLE;       /**< Access enable for HIFI4 to RAM partitions., offset: 0xF90 */
  __IO uint32_t HIFI1_ARB1RAM_ACCESS_ENABLE;       /**< Access enable for HIFI1 to RAM partitions., offset: 0xF94 */
       uint8_t RESERVED_24[8];
  __IO uint32_t COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE; /**< Access enable for COMPUTE domain masters to common APB peripherals., offset: 0xFA0 */
  __IO uint32_t SENSE_APB_PERIPHERAL_ACCESS_ENABLE; /**< Access enable for SENSE domain masters to common APB peripherals., offset: 0xFA4 */
       uint8_t RESERVED_25[8];
  __IO uint32_t COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE; /**< Access enable for COMPUTE domain masters to common AIPS peripherals., offset: 0xFB0 */
  __IO uint32_t SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE; /**< Access enable for SENSE domain masters to common AIPS peripherals., offset: 0xFB4 */
       uint8_t RESERVED_26[24];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_27[20];
  __IO uint32_t CPU1_LOCK_REG;                     /**< Miscellaneous CPU1 Control Signals, offset: 0xFEC */
       uint8_t RESERVED_28[8];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} AHBSC3_Type;

/* ----------------------------------------------------------------------------
   -- AHBSC3 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC3_Register_Masks AHBSC3 Register Masks
 * @{
 */

/*! @name SRAM_0_RULE - RAM partition 0 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_0_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_0_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE0_MASK)

#define AHBSC3_SRAM_0_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_0_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE1_MASK)

#define AHBSC3_SRAM_0_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_0_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE2_MASK)

#define AHBSC3_SRAM_0_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_0_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE3_MASK)

#define AHBSC3_SRAM_0_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_0_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE4_MASK)

#define AHBSC3_SRAM_0_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_0_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE5_MASK)

#define AHBSC3_SRAM_0_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_0_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE6_MASK)

#define AHBSC3_SRAM_0_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_0_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_0_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_0_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_0_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_1_RULE - RAM partition 1 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_1_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_1_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE0_MASK)

#define AHBSC3_SRAM_1_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_1_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE1_MASK)

#define AHBSC3_SRAM_1_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_1_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE2_MASK)

#define AHBSC3_SRAM_1_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_1_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE3_MASK)

#define AHBSC3_SRAM_1_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_1_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE4_MASK)

#define AHBSC3_SRAM_1_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_1_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE5_MASK)

#define AHBSC3_SRAM_1_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_1_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE6_MASK)

#define AHBSC3_SRAM_1_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_1_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_1_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_1_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_1_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_2_RULE - RAM partition 2 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_2_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_2_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE0_MASK)

#define AHBSC3_SRAM_2_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_2_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE1_MASK)

#define AHBSC3_SRAM_2_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_2_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE2_MASK)

#define AHBSC3_SRAM_2_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_2_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE3_MASK)

#define AHBSC3_SRAM_2_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_2_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE4_MASK)

#define AHBSC3_SRAM_2_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_2_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE5_MASK)

#define AHBSC3_SRAM_2_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_2_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE6_MASK)

#define AHBSC3_SRAM_2_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_2_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_2_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_2_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_2_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_3_RULE - RAM partition 3 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_3_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_3_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE0_MASK)

#define AHBSC3_SRAM_3_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_3_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE1_MASK)

#define AHBSC3_SRAM_3_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_3_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE2_MASK)

#define AHBSC3_SRAM_3_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_3_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE3_MASK)

#define AHBSC3_SRAM_3_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_3_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE4_MASK)

#define AHBSC3_SRAM_3_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_3_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE5_MASK)

#define AHBSC3_SRAM_3_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_3_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE6_MASK)

#define AHBSC3_SRAM_3_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_3_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_3_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_3_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_3_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_4_RULE - RAM partition 4 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_4_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_4_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE0_MASK)

#define AHBSC3_SRAM_4_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_4_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE1_MASK)

#define AHBSC3_SRAM_4_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_4_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE2_MASK)

#define AHBSC3_SRAM_4_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_4_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE3_MASK)

#define AHBSC3_SRAM_4_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_4_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE4_MASK)

#define AHBSC3_SRAM_4_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_4_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE5_MASK)

#define AHBSC3_SRAM_4_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_4_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE6_MASK)

#define AHBSC3_SRAM_4_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_4_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_4_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_4_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_4_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_5_RULE - RAM partition 5 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_5_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_5_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE0_MASK)

#define AHBSC3_SRAM_5_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_5_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE1_MASK)

#define AHBSC3_SRAM_5_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_5_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE2_MASK)

#define AHBSC3_SRAM_5_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_5_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE3_MASK)

#define AHBSC3_SRAM_5_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_5_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE4_MASK)

#define AHBSC3_SRAM_5_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_5_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE5_MASK)

#define AHBSC3_SRAM_5_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_5_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE6_MASK)

#define AHBSC3_SRAM_5_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_5_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_5_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_5_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_5_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_6_RULE - RAM partition 6 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_6_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_6_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE0_MASK)

#define AHBSC3_SRAM_6_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_6_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE1_MASK)

#define AHBSC3_SRAM_6_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_6_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE2_MASK)

#define AHBSC3_SRAM_6_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_6_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE3_MASK)

#define AHBSC3_SRAM_6_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_6_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE4_MASK)

#define AHBSC3_SRAM_6_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_6_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE5_MASK)

#define AHBSC3_SRAM_6_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_6_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE6_MASK)

#define AHBSC3_SRAM_6_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_6_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_6_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_6_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_6_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_7_RULE - RAM partition 7 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_7_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_7_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE0_MASK)

#define AHBSC3_SRAM_7_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_7_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE1_MASK)

#define AHBSC3_SRAM_7_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_7_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE2_MASK)

#define AHBSC3_SRAM_7_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_7_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE3_MASK)

#define AHBSC3_SRAM_7_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_7_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE4_MASK)

#define AHBSC3_SRAM_7_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_7_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE5_MASK)

#define AHBSC3_SRAM_7_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_7_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE6_MASK)

#define AHBSC3_SRAM_7_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_7_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_7_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_7_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_7_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_8_RULE - RAM partition 8 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_8_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_8_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE0_MASK)

#define AHBSC3_SRAM_8_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_8_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE1_MASK)

#define AHBSC3_SRAM_8_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_8_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE2_MASK)

#define AHBSC3_SRAM_8_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_8_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE3_MASK)

#define AHBSC3_SRAM_8_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_8_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE4_MASK)

#define AHBSC3_SRAM_8_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_8_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE5_MASK)

#define AHBSC3_SRAM_8_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_8_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE6_MASK)

#define AHBSC3_SRAM_8_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_8_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_8_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_8_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_8_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_9_RULE - RAM partition 9 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_9_RULE_RULE0_MASK            (0x3U)
#define AHBSC3_SRAM_9_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE0_MASK)

#define AHBSC3_SRAM_9_RULE_RULE1_MASK            (0x30U)
#define AHBSC3_SRAM_9_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE1_MASK)

#define AHBSC3_SRAM_9_RULE_RULE2_MASK            (0x300U)
#define AHBSC3_SRAM_9_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE2_MASK)

#define AHBSC3_SRAM_9_RULE_RULE3_MASK            (0x3000U)
#define AHBSC3_SRAM_9_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE3_MASK)

#define AHBSC3_SRAM_9_RULE_RULE4_MASK            (0x30000U)
#define AHBSC3_SRAM_9_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE4_MASK)

#define AHBSC3_SRAM_9_RULE_RULE5_MASK            (0x300000U)
#define AHBSC3_SRAM_9_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE5_MASK)

#define AHBSC3_SRAM_9_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC3_SRAM_9_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE6_MASK)

#define AHBSC3_SRAM_9_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC3_SRAM_9_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_9_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_9_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_9_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_10_RULE - RAM partition 10 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_10_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_10_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE0_MASK)

#define AHBSC3_SRAM_10_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_10_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE1_MASK)

#define AHBSC3_SRAM_10_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_10_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE2_MASK)

#define AHBSC3_SRAM_10_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_10_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE3_MASK)

#define AHBSC3_SRAM_10_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_10_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE4_MASK)

#define AHBSC3_SRAM_10_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_10_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE5_MASK)

#define AHBSC3_SRAM_10_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_10_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE6_MASK)

#define AHBSC3_SRAM_10_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_10_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_10_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_10_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_10_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_11_RULE - RAM partition 11 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_11_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_11_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE0_MASK)

#define AHBSC3_SRAM_11_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_11_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE1_MASK)

#define AHBSC3_SRAM_11_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_11_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE2_MASK)

#define AHBSC3_SRAM_11_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_11_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE3_MASK)

#define AHBSC3_SRAM_11_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_11_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE4_MASK)

#define AHBSC3_SRAM_11_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_11_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE5_MASK)

#define AHBSC3_SRAM_11_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_11_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE6_MASK)

#define AHBSC3_SRAM_11_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_11_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_11_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_11_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_11_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_12_RULE - RAM partition 12 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_12_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_12_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE0_MASK)

#define AHBSC3_SRAM_12_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_12_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE1_MASK)

#define AHBSC3_SRAM_12_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_12_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE2_MASK)

#define AHBSC3_SRAM_12_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_12_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE3_MASK)

#define AHBSC3_SRAM_12_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_12_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE4_MASK)

#define AHBSC3_SRAM_12_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_12_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE5_MASK)

#define AHBSC3_SRAM_12_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_12_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE6_MASK)

#define AHBSC3_SRAM_12_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_12_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_12_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_12_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_12_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_13_RULE - RAM partition 13 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_13_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_13_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE0_MASK)

#define AHBSC3_SRAM_13_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_13_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE1_MASK)

#define AHBSC3_SRAM_13_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_13_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE2_MASK)

#define AHBSC3_SRAM_13_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_13_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE3_MASK)

#define AHBSC3_SRAM_13_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_13_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE4_MASK)

#define AHBSC3_SRAM_13_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_13_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE5_MASK)

#define AHBSC3_SRAM_13_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_13_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE6_MASK)

#define AHBSC3_SRAM_13_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_13_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_13_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_13_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_13_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_14_RULE - RAM partition 14 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_14_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_14_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE0_MASK)

#define AHBSC3_SRAM_14_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_14_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE1_MASK)

#define AHBSC3_SRAM_14_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_14_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE2_MASK)

#define AHBSC3_SRAM_14_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_14_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE3_MASK)

#define AHBSC3_SRAM_14_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_14_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE4_MASK)

#define AHBSC3_SRAM_14_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_14_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE5_MASK)

#define AHBSC3_SRAM_14_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_14_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE6_MASK)

#define AHBSC3_SRAM_14_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_14_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_14_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_14_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_14_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_15_RULE - RAM partition 15 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_15_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_15_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE0_MASK)

#define AHBSC3_SRAM_15_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_15_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE1_MASK)

#define AHBSC3_SRAM_15_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_15_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE2_MASK)

#define AHBSC3_SRAM_15_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_15_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE3_MASK)

#define AHBSC3_SRAM_15_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_15_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE4_MASK)

#define AHBSC3_SRAM_15_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_15_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE5_MASK)

#define AHBSC3_SRAM_15_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_15_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE6_MASK)

#define AHBSC3_SRAM_15_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_15_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_15_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_15_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_15_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_16_RULE - RAM partition 16 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_16_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_16_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE0_MASK)

#define AHBSC3_SRAM_16_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_16_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE1_MASK)

#define AHBSC3_SRAM_16_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_16_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE2_MASK)

#define AHBSC3_SRAM_16_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_16_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE3_MASK)

#define AHBSC3_SRAM_16_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_16_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE4_MASK)

#define AHBSC3_SRAM_16_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_16_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE5_MASK)

#define AHBSC3_SRAM_16_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_16_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE6_MASK)

#define AHBSC3_SRAM_16_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_16_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_16_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_16_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_16_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_17_RULE - RAM partition 17 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_17_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_17_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE0_MASK)

#define AHBSC3_SRAM_17_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_17_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE1_MASK)

#define AHBSC3_SRAM_17_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_17_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE2_MASK)

#define AHBSC3_SRAM_17_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_17_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE3_MASK)

#define AHBSC3_SRAM_17_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_17_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE4_MASK)

#define AHBSC3_SRAM_17_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_17_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE5_MASK)

#define AHBSC3_SRAM_17_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_17_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE6_MASK)

#define AHBSC3_SRAM_17_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_17_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_17_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_17_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_17_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_18_RULE - RAM partition 18 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_18_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_18_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE0_MASK)

#define AHBSC3_SRAM_18_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_18_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE1_MASK)

#define AHBSC3_SRAM_18_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_18_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE2_MASK)

#define AHBSC3_SRAM_18_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_18_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE3_MASK)

#define AHBSC3_SRAM_18_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_18_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE4_MASK)

#define AHBSC3_SRAM_18_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_18_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE5_MASK)

#define AHBSC3_SRAM_18_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_18_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE6_MASK)

#define AHBSC3_SRAM_18_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_18_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_18_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_18_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_18_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_19_RULE - RAM partition 19 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_19_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_19_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE0_MASK)

#define AHBSC3_SRAM_19_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_19_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE1_MASK)

#define AHBSC3_SRAM_19_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_19_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE2_MASK)

#define AHBSC3_SRAM_19_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_19_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE3_MASK)

#define AHBSC3_SRAM_19_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_19_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE4_MASK)

#define AHBSC3_SRAM_19_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_19_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE5_MASK)

#define AHBSC3_SRAM_19_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_19_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE6_MASK)

#define AHBSC3_SRAM_19_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_19_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_19_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_19_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_19_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_20_RULE - RAM partition 20 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_20_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_20_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE0_MASK)

#define AHBSC3_SRAM_20_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_20_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE1_MASK)

#define AHBSC3_SRAM_20_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_20_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE2_MASK)

#define AHBSC3_SRAM_20_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_20_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE3_MASK)

#define AHBSC3_SRAM_20_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_20_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE4_MASK)

#define AHBSC3_SRAM_20_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_20_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE5_MASK)

#define AHBSC3_SRAM_20_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_20_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE6_MASK)

#define AHBSC3_SRAM_20_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_20_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_20_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_20_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_20_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_21_RULE - RAM partition 21 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_21_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_21_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE0_MASK)

#define AHBSC3_SRAM_21_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_21_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE1_MASK)

#define AHBSC3_SRAM_21_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_21_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE2_MASK)

#define AHBSC3_SRAM_21_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_21_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE3_MASK)

#define AHBSC3_SRAM_21_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_21_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE4_MASK)

#define AHBSC3_SRAM_21_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_21_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE5_MASK)

#define AHBSC3_SRAM_21_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_21_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE6_MASK)

#define AHBSC3_SRAM_21_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_21_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_21_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_21_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_21_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_22_RULE - RAM partition 22 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_22_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_22_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE0_MASK)

#define AHBSC3_SRAM_22_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_22_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE1_MASK)

#define AHBSC3_SRAM_22_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_22_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE2_MASK)

#define AHBSC3_SRAM_22_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_22_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE3_MASK)

#define AHBSC3_SRAM_22_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_22_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE4_MASK)

#define AHBSC3_SRAM_22_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_22_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE5_MASK)

#define AHBSC3_SRAM_22_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_22_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE6_MASK)

#define AHBSC3_SRAM_22_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_22_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_22_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_22_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_22_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_23_RULE - RAM partition 23 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_23_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_23_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE0_MASK)

#define AHBSC3_SRAM_23_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_23_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE1_MASK)

#define AHBSC3_SRAM_23_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_23_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE2_MASK)

#define AHBSC3_SRAM_23_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_23_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE3_MASK)

#define AHBSC3_SRAM_23_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_23_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE4_MASK)

#define AHBSC3_SRAM_23_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_23_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE5_MASK)

#define AHBSC3_SRAM_23_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_23_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE6_MASK)

#define AHBSC3_SRAM_23_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_23_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_23_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_23_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_23_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_24_RULE - RAM partition 24 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_24_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_24_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE0_MASK)

#define AHBSC3_SRAM_24_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_24_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE1_MASK)

#define AHBSC3_SRAM_24_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_24_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE2_MASK)

#define AHBSC3_SRAM_24_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_24_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE3_MASK)

#define AHBSC3_SRAM_24_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_24_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE4_MASK)

#define AHBSC3_SRAM_24_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_24_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE5_MASK)

#define AHBSC3_SRAM_24_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_24_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE6_MASK)

#define AHBSC3_SRAM_24_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_24_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_24_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_24_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_24_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_25_RULE - RAM partition 25 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_25_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_25_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE0_MASK)

#define AHBSC3_SRAM_25_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_25_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE1_MASK)

#define AHBSC3_SRAM_25_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_25_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE2_MASK)

#define AHBSC3_SRAM_25_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_25_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE3_MASK)

#define AHBSC3_SRAM_25_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_25_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE4_MASK)

#define AHBSC3_SRAM_25_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_25_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE5_MASK)

#define AHBSC3_SRAM_25_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_25_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE6_MASK)

#define AHBSC3_SRAM_25_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_25_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_25_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_25_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_25_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_26_RULE - RAM partition 26 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_26_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_26_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE0_MASK)

#define AHBSC3_SRAM_26_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_26_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE1_MASK)

#define AHBSC3_SRAM_26_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_26_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE2_MASK)

#define AHBSC3_SRAM_26_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_26_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE3_MASK)

#define AHBSC3_SRAM_26_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_26_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE4_MASK)

#define AHBSC3_SRAM_26_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_26_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE5_MASK)

#define AHBSC3_SRAM_26_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_26_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE6_MASK)

#define AHBSC3_SRAM_26_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_26_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_26_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_26_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_26_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_27_RULE - RAM partition 27 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_27_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_27_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE0_MASK)

#define AHBSC3_SRAM_27_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_27_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE1_MASK)

#define AHBSC3_SRAM_27_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_27_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE2_MASK)

#define AHBSC3_SRAM_27_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_27_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE3_MASK)

#define AHBSC3_SRAM_27_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_27_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE4_MASK)

#define AHBSC3_SRAM_27_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_27_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE5_MASK)

#define AHBSC3_SRAM_27_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_27_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE6_MASK)

#define AHBSC3_SRAM_27_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_27_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_27_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_27_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_27_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_28_RULE - RAM partition 28 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_28_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_28_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE0_MASK)

#define AHBSC3_SRAM_28_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_28_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE1_MASK)

#define AHBSC3_SRAM_28_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_28_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE2_MASK)

#define AHBSC3_SRAM_28_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_28_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE3_MASK)

#define AHBSC3_SRAM_28_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_28_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE4_MASK)

#define AHBSC3_SRAM_28_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_28_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE5_MASK)

#define AHBSC3_SRAM_28_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_28_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE6_MASK)

#define AHBSC3_SRAM_28_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_28_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_28_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_28_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_28_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_29_RULE - RAM partition 29 Memory Rule Register */
/*! @{ */

#define AHBSC3_SRAM_29_RULE_RULE0_MASK           (0x3U)
#define AHBSC3_SRAM_29_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE0_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE0_MASK)

#define AHBSC3_SRAM_29_RULE_RULE1_MASK           (0x30U)
#define AHBSC3_SRAM_29_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE1_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE1_MASK)

#define AHBSC3_SRAM_29_RULE_RULE2_MASK           (0x300U)
#define AHBSC3_SRAM_29_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE2_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE2_MASK)

#define AHBSC3_SRAM_29_RULE_RULE3_MASK           (0x3000U)
#define AHBSC3_SRAM_29_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE3_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE3_MASK)

#define AHBSC3_SRAM_29_RULE_RULE4_MASK           (0x30000U)
#define AHBSC3_SRAM_29_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE4_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE4_MASK)

#define AHBSC3_SRAM_29_RULE_RULE5_MASK           (0x300000U)
#define AHBSC3_SRAM_29_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE5_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE5_MASK)

#define AHBSC3_SRAM_29_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC3_SRAM_29_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE6_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE6_MASK)

#define AHBSC3_SRAM_29_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC3_SRAM_29_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SRAM_29_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC3_SRAM_29_RULE_RULE7_SHIFT)) & AHBSC3_SRAM_29_RULE_RULE7_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL10_SLAVE_RULE0 - AHB Peripheral 10 Slaves Rule Register 0 */
/*! @{ */

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM17_MASK (0x30000U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM17_SHIFT (16U)
/*! LP_FLEXCOMM17 - LP_FLEXCOMM17
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM17(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM17_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM17_MASK)

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM18_MASK (0x300000U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM18_SHIFT (20U)
/*! LP_FLEXCOMM18 - LP_FLEXCOMM18
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM18(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM18_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM18_MASK)

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM19_MASK (0x3000000U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM19_SHIFT (24U)
/*! LP_FLEXCOMM19 - LP_FLEXCOMM19
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM19(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM19_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM19_MASK)

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM20_MASK (0x30000000U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM20_SHIFT (28U)
/*! LP_FLEXCOMM20 - LP_FLEXCOMM20
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM20(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM20_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE0_LP_FLEXCOMM20_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL10_SLAVE_RULE1 - AHB Peripheral 10 Slaves Rule Register 1 */
/*! @{ */

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG4_MASK (0x3U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG4_SHIFT (0U)
/*! CDOG4 - CDOG4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG4_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG4_MASK)

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG3_MASK (0x30U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG3_SHIFT (4U)
/*! CDOG3 - CDOG3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG3_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_RULE1_CDOG3_MASK)
/*! @} */

/*! @name AIPS5_BRIDGE_GROUP0_MEM_RULE0 - AIPS5 Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_MP_MASK (0x3U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_MP_SHIFT (0U)
/*! eDMA2_MP - eDMA2_MP management
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_MP_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_MP_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH0_MASK (0x30U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH0_SHIFT (4U)
/*! eDMA2_CH0 - eDMA2_CH0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH0_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH0_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH1_MASK (0x300U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH1_SHIFT (8U)
/*! eDMA2_CH1 - eDMA2_CH1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH1_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH1_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH2_MASK (0x3000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH2_SHIFT (12U)
/*! eDMA2_CH2 - eDMA2_CH2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH2_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH2_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH3_MASK (0x30000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH3_SHIFT (16U)
/*! eDMA2_CH3 - eDMA2_CH3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH3_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH3_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH4_MASK (0x300000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH4_SHIFT (20U)
/*! eDMA2_CH4 - eDMA2_CH4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH4_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH4_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH5_MASK (0x3000000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH5_SHIFT (24U)
/*! eDMA2_CH5 - eDMA2_CH5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH5_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH5_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH6_MASK (0x30000000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH6_SHIFT (28U)
/*! eDMA2_CH6 - eDMA2_CH6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH6_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE0_eDMA2_CH6_MASK)
/*! @} */

/*! @name AIPS5_BRIDGE_GROUP0_MEM_RULE1 - AIPS5 Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE1_eDMA2_CH7_MASK (0x3U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE1_eDMA2_CH7_SHIFT (0U)
/*! eDMA2_CH7 - eDMA2_CH7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE1_eDMA2_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE1_eDMA2_CH7_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE1_eDMA2_CH7_MASK)
/*! @} */

/*! @name AIPS5_BRIDGE_GROUP0_MEM_RULE2 - AIPS5 Bridge Group 0 Memory Rule Register 2 */
/*! @{ */

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_MP_MASK (0x3U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_MP_SHIFT (0U)
/*! DMA_3_MP - DMA1 management
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_MP_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_MP_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH0_MASK (0x30U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH0_SHIFT (4U)
/*! DMA_3_CH0 - DMA1 channel 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH0_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH0_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH1_MASK (0x300U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH1_SHIFT (8U)
/*! DMA_3_CH1 - DMA1 channel 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH1_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH1_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH2_MASK (0x3000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH2_SHIFT (12U)
/*! DMA_3_CH2 - DMA1 channel 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH2_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH2_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH3_MASK (0x30000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH3_SHIFT (16U)
/*! DMA_3_CH3 - DMA1 channel 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH3_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH3_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH4_MASK (0x300000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH4_SHIFT (20U)
/*! DMA_3_CH4 - DMA1 channel 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH4_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH4_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH5_MASK (0x3000000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH5_SHIFT (24U)
/*! DMA_3_CH5 - DMA1 channel 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH5_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH5_MASK)

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH6_MASK (0x30000000U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH6_SHIFT (28U)
/*! DMA_3_CH6 - DMA1 channel 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH6_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE2_DMA_3_CH6_MASK)
/*! @} */

/*! @name AIPS5_BRIDGE_GROUP0_MEM_RULE3 - AIPS5 Bridge Group 0 Memory Rule Register 3 */
/*! @{ */

#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE3_DMA_3_CH7_MASK (0x3U)
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE3_DMA_3_CH7_SHIFT (0U)
/*! DMA_3_CH7 - DMA1 channel 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE3_DMA_3_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE3_DMA_3_CH7_SHIFT)) & AHBSC3_AIPS5_BRIDGE_GROUP0_MEM_RULE3_DMA_3_CH7_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL10_SLAVE_GPIO_RULE - AHB Peripheral 10 Slaves GPIO8 Rule Register..AHB Peripheral 10 Slaves GPIO10 Rule Register */
/*! @{ */

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_MASK (0x3U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_SHIFT (0U)
/*! GPIOn - GPIOn_RULE0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_MASK)

#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_ALIAS_MASK (0x30U)
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_ALIAS_SHIFT (4U)
/*! GPIOn_ALIAS - GPIOn_ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_ALIAS_SHIFT)) & AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_GPIOn_ALIAS_MASK)
/*! @} */

/* The count of AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE */
#define AHBSC3_AHB_PERIPHERAL10_SLAVE_GPIO_RULE_COUNT (3U)

/*! @name AIPS2_BRIDGE_GROUP0_MEM_RULE0 - AIPS2 Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_B_MASK (0x30U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_B_SHIFT (4U)
/*! MU0_B - MU0_B (HIFI1 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_B_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_B_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_B_MASK (0x3000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_B_SHIFT (12U)
/*! MU1_B - MU1_B (M33_SENSE port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_B_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_B_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_B_MASK (0x300000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_B_SHIFT (20U)
/*! MU2_B - MU2_B (M33_SENSE port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_B_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_B_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEM42_0_MASK (0x3000000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEM42_0_SHIFT (24U)
/*! SEM42_0 - SEM42_0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEM42_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEM42_0_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEM42_0_MASK)
/*! @} */

/*! @name AIPS2_BRIDGE_GROUP0_MEM_RULE1 - AIPS2 Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS2_MASK (0x30U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS2_SHIFT (4U)
/*! OSTIMER_ALIAS2 - OSTIMER_ALIAS2 (M33 sense port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS2_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS2_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS3_MASK (0x300U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS3_SHIFT (8U)
/*! OSTIMER_ALIAS3 - OSTIMER_ALIAS3 (HIFI1 sense port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS3_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS3_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_MASK (0x3000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_SHIFT (12U)
/*! ACMP0 - ACMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_MASK (0x30000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_SHIFT (16U)
/*! ADC0 - ADC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_MASK (0x300000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_SHIFT (20U)
/*! SDADC - SDADC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_MASK (0x3000000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_SHIFT (24U)
/*! MICFIL - MICFIL
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_MASK)
/*! @} */

/*! @name AIPS2_BRIDGE_GROUP1_MEM_RULE0 - AIPS2 Bridge Group 1 Memory Rule Register 0 */
/*! @{ */

#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_PMC1_MASK (0x3U)
#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_PMC1_SHIFT (0U)
/*! PMC1 - PMC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_PMC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_PMC1_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_PMC1_MASK)

#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_MASK (0x3000U)
#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_SHIFT (12U)
/*! LPI2C15 - LPI2C15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_SHIFT)) & AHBSC3_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_RULE0 - AHB Secure Control Peripheral Rule 0 */
/*! @{ */

#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK (0x3U)
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT)) & AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK)

#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK (0x30U)
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT)) & AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK)

#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK (0x300U)
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT)) & AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK)

#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK (0x3000U)
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT)) & AHBSC3_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK)
/*! @} */

/*! @name SENSE_APB_SLAVE_GROUP0_RULE0 - APB Bridge Peripheral 0 Rule 0 */
/*! @{ */

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_RSTCTL1_MASK (0x3U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_RSTCTL1_SHIFT (0U)
/*! RSTCTL1 - RSTCTL1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_RSTCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_RSTCTL1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_RSTCTL1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_CLKCTL1_MASK (0x30U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_CLKCTL1_SHIFT (4U)
/*! CLKCTL1 - CLKCTL1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_CLKCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_CLKCTL1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_CLKCTL1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SYSCON1_MASK (0x300U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SYSCON1_SHIFT (8U)
/*! SYSCON1 - SYSCON1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SYSCON1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SYSCON1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SYSCON1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PVTS1_MASK (0x3000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PVTS1_SHIFT (12U)
/*! PVTS1 - PVTS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PVTS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PVTS1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PVTS1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SLEEPCON1_MASK (0x30000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SLEEPCON1_SHIFT (16U)
/*! SLEEPCON1 - SLEEPCON1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SLEEPCON1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SLEEPCON1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_SLEEPCON1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PINT1_MASK (0x300000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PINT1_SHIFT (20U)
/*! PINT1 - PINT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PINT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PINT1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_PINT1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_INPUTMUX1_MASK (0x3000000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_INPUTMUX1_SHIFT (24U)
/*! INPUTMUX1 - INPUTMUX1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_INPUTMUX1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_INPUTMUX1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE0_INPUTMUX1_MASK)
/*! @} */

/*! @name SENSE_APB_SLAVE_GROUP0_RULE1 - APB Bridge Peripheral 0 Rule Register 1 */
/*! @{ */

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER5_MASK (0x3U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER5_SHIFT (0U)
/*! CTIMER5 - CTIMER5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER5_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER5_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER6_MASK (0x30U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER6_SHIFT (4U)
/*! CTIMER6 - CTIMER6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER6_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER6_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER7_MASK (0x300U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER7_SHIFT (8U)
/*! CTIMER7 - CTIMER7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER7_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_CTIMER7_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_MRT1_MASK (0x300000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_MRT1_SHIFT (20U)
/*! MRT1 - MRT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_MRT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_MRT1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE1_MRT1_MASK)
/*! @} */

/*! @name SENSE_APB_SLAVE_GROUP0_RULE2 - APB Bridge Peripheral 0 Rule Register 2 */
/*! @{ */

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT2_MASK (0x3U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT2_SHIFT (0U)
/*! WWDT2 - WWDT2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT2_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT2_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT3_MASK (0x30U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT3_SHIFT (4U)
/*! WWDT3 - WWDT3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT3_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_WWDT3_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_UTICK1_MASK (0x300U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_UTICK1_SHIFT (8U)
/*! UTICK1 - UTICK1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_UTICK1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_UTICK1_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_UTICK1_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C2_MASK (0x3000000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C2_SHIFT (24U)
/*! I3C2 - I3C2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C2_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C2_MASK)

#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C3_MASK (0x30000000U)
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C3_SHIFT (28U)
/*! I3C3 - I3C3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C3_SHIFT)) & AHBSC3_SENSE_APB_SLAVE_GROUP0_RULE2_I3C3_MASK)
/*! @} */

/*! @name SHARED_APB_SLAVE_GROUP0_RULE0 - Shared APB Bridge Peripheral 0 Rule 0 */
/*! @{ */

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_MASK (0x3U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_SHIFT (0U)
/*! RSTCTL3 - RSTCTL3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_MASK (0x30U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_SHIFT (4U)
/*! CLKCTL3 - CLKCTL3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_MASK (0x300U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_SHIFT (8U)
/*! SYSCON3 - SYSCON3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_MASK (0x3000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_SHIFT (12U)
/*! OSC32KNP - OSC32KNP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_MASK (0x30000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_SHIFT (16U)
/*! IOPCTL1 - IOPCTL1 for sense domain
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_MASK (0x300000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_SHIFT (20U)
/*! CLKCTL2 - Clock for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_MASK (0x3000000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_SHIFT (24U)
/*! SYSCON2 - CLKCTL for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_MASK (0x30000000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_SHIFT (28U)
/*! RSTCTL2 - RSTCTL for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_MASK)
/*! @} */

/*! @name SHARED_APB_SLAVE_GROUP0_RULE1 - Shared APB Bridge Peripheral 0 Rule 1 */
/*! @{ */

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS0_MASK (0x3U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS0_SHIFT (0U)
/*! RTC_SS0 - RTC_SS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS0_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS0_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS1_MASK (0x30U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS1_SHIFT (4U)
/*! RTC_SS1 - RTC_SS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS1_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_RTC_SS1_MASK)

#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_MASK (0x3000U)
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_SHIFT (12U)
/*! GDET3 - GDET3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_SHIFT)) & AHBSC3_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_MASK)
/*! @} */

/*! @name SENSE2MEDIA_RULE - SENSE domain to MEDIA domain Access Rule Register */
/*! @{ */

#define AHBSC3_SENSE2MEDIA_RULE_XSPI2_MASK       (0x3U)
#define AHBSC3_SENSE2MEDIA_RULE_XSPI2_SHIFT      (0U)
/*! XSPI2 - XSPI2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_SENSE2MEDIA_RULE_XSPI2(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE2MEDIA_RULE_XSPI2_SHIFT)) & AHBSC3_SENSE2MEDIA_RULE_XSPI2_MASK)
/*! @} */

/*! @name MEDIA_AHB_PERIPHERAL_SLAVE_RULE0 - MEDIA domain AHB peripheral slave */
/*! @{ */

#define AHBSC3_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_MASK (0x3U)
#define AHBSC3_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_SHIFT (0U)
/*! MEDIA_AHB_PERIPHERAL - MEDIA domain AHB Peripheral Slave Rule Register
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_SHIFT)) & AHBSC3_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_MASK)
/*! @} */

/*! @name MEDIA_APB_PERIPHERAL_SLAVE_RULE0 - MEDIA domain APB peripheral slave Rule Register */
/*! @{ */

#define AHBSC3_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_MASK (0x3U)
#define AHBSC3_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_SHIFT (0U)
/*! MEDIA_APB_PERIPHERAL - MEDIA domain APB Peripheral Slave
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_SHIFT)) & AHBSC3_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_MASK)
/*! @} */

/*! @name EZHV_SRAM_RULE0 - EZHV SRAM Memory Rule Register */
/*! @{ */

#define AHBSC3_EZHV_SRAM_RULE0_EZHV_SRAM_MASK    (0x3U)
#define AHBSC3_EZHV_SRAM_RULE0_EZHV_SRAM_SHIFT   (0U)
/*! EZHV_SRAM - EZHV SRAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC3_EZHV_SRAM_RULE0_EZHV_SRAM(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC3_EZHV_SRAM_RULE0_EZHV_SRAM_SHIFT)) & AHBSC3_EZHV_SRAM_RULE0_EZHV_SRAM_MASK)
/*! @} */

/*! @name SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC3_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK    (0xFFFFFFFFU)
#define AHBSC3_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT   (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC3_SEC_VIO_ADDR_SEC_VIO_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC3_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC3_SEC_VIO_ADDR */
#define AHBSC3_SEC_VIO_ADDR_COUNT                (17U)

/*! @name SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0x1F00U)
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
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
#define AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC3_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC3_SEC_VIO_MISC_INFO */
#define AHBSC3_SEC_VIO_MISC_INFO_COUNT           (17U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - Violation information valid flag for AHB port 13
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - Violation information valid flag for AHB port 14
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - Violation information valid flag for AHB port 15
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - Violation information valid flag for AHB port 16
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & AHBSC3_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)
/*! @} */

/*! @name COMPUTE_ARB1RAM_ACCESS_ENABLE - Access enable for COMPUTE domain masters to RAM partitions. */
/*! @{ */

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_COMPUTE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name SENSE_ARB1RAM_ACCESS_ENABLE - Access enable for SENSE domain masters to RAM partitions. */
/*! @{ */

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_SENSE_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name MEDIA_ARB1RAM_ACCESS_ENABLE - Access enable for MEDIA domain masters to RAM partitions. */
/*! @{ */

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_MEDIA_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name NPU_ARB1RAM_ACCESS_ENABLE - Access enable for NPU to RAM partitions. */
/*! @{ */

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_NPU_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name HIFI4_ARB1RAM_ACCESS_ENABLE - Access enable for HIFI4 to RAM partitions. */
/*! @{ */

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_HIFI4_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name HIFI1_ARB1RAM_ACCESS_ENABLE - Access enable for HIFI1 to RAM partitions. */
/*! @{ */

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC3_HIFI1_ARB1RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)
/*! @} */

/*! @name COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE - Access enable for COMPUTE domain masters to common APB peripherals. */
/*! @{ */

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_MASK (0x1U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_SHIFT (0U)
/*! RSTCTL3 - Enable access to the common APB peripheral RSTCTL3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_MASK (0x2U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_SHIFT (1U)
/*! CLKCTL3 - Enable access to the common APB peripheral CLKCTL3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_MASK (0x4U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_SHIFT (2U)
/*! SYSCON3 - Enable access to the common APB peripheral SYSCON3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_MASK (0x8U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_SHIFT (3U)
/*! OSC32KNP - Enable access to the common APB peripheral OSC32KNP
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_MASK (0x10U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_SHIFT (4U)
/*! IOPCTL1 - Enable access to the common APB peripheral IOPCTL1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_MASK (0x20U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_SHIFT (5U)
/*! CLKCTL2 - Enable access to the common APB peripheral CLKCTL2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_MASK (0x40U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_SHIFT (6U)
/*! SYSCON2 - Enable access to the common APB peripheral SYSCON2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_MASK (0x80U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_SHIFT (7U)
/*! RSTCTL2 - Enable access to the common APB peripheral RSTCTL2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_MASK (0x100U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_SHIFT (8U)
/*! RTC0 - Enable access to the common APB peripheral RTC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_MASK (0x200U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_SHIFT (9U)
/*! RTC1 - Enable access to the common APB peripheral RTC1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_MASK)

#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_MASK (0x800U)
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_SHIFT (11U)
/*! GDET3 - Enable access to the common APB peripheral GDET3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_SHIFT)) & AHBSC3_COMPUTE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_MASK)
/*! @} */

/*! @name SENSE_APB_PERIPHERAL_ACCESS_ENABLE - Access enable for SENSE domain masters to common APB peripherals. */
/*! @{ */

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_MASK (0x1U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_SHIFT (0U)
/*! RSTCTL3 - Enable access to the common APB peripheral RSTCTL3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL3_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_MASK (0x2U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_SHIFT (1U)
/*! CLKCTL3 - Enable access to the common APB peripheral CLKCTL3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL3_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_MASK (0x4U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_SHIFT (2U)
/*! SYSCON3 - Enable access to the common APB peripheral SYSCON3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON3_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_MASK (0x8U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_SHIFT (3U)
/*! OSC32KNP - Enable access to the common APB peripheral OSC32KNP
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_OSC32KNP_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_MASK (0x10U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_SHIFT (4U)
/*! IOPCTL1 - Enable access to the common APB peripheral IOPCTL1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_IOPCTL1_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_MASK (0x20U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_SHIFT (5U)
/*! CLKCTL2 - Enable access to the common APB peripheral CLKCTL2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_CLKCTL2_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_MASK (0x40U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_SHIFT (6U)
/*! SYSCON2 - Enable access to the common APB peripheral SYSCON2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_SYSCON2_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_MASK (0x80U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_SHIFT (7U)
/*! RSTCTL2 - Enable access to the common APB peripheral RSTCTL2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RSTCTL2_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_MASK (0x100U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_SHIFT (8U)
/*! RTC0 - Enable access to the common APB peripheral RTC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC0_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_MASK (0x200U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_SHIFT (9U)
/*! RTC1 - Enable access to the common APB peripheral RTC1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_RTC1_MASK)

#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_MASK (0x800U)
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_SHIFT (11U)
/*! GDET3 - Enable access to the common APB peripheral GDET3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_SHIFT)) & AHBSC3_SENSE_APB_PERIPHERAL_ACCESS_ENABLE_GDET3_MASK)
/*! @} */

/*! @name COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE - Access enable for COMPUTE domain masters to common AIPS peripherals. */
/*! @{ */

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_A_MASK (0x1U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_A_SHIFT (0U)
/*! MU0_A - Enable access to MU0_A
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_A_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_A_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_A_MASK (0x4U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_A_SHIFT (2U)
/*! MU1_A - Enable access to MU1_A
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_A_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_A_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_A_MASK (0x10U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_A_SHIFT (4U)
/*! MU2_A - Enable access to MU2_A
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_A_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_A_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_MASK (0x40U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_SHIFT (6U)
/*! SEMA42_0 - Enable access to SEMA42_0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_MASK (0x80U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_SHIFT (7U)
/*! OSTIMER - Enable access to OSTIMER
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS1_MASK (0x100U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS1_SHIFT (8U)
/*! OSTIMER_ALIAS1 - Enable access to OSTIMER_ALIAS1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS1_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS1_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_MASK (0x800U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_SHIFT (11U)
/*! ACMP0 - Enable access to ACMP0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_MASK (0x1000U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_SHIFT (12U)
/*! ADC0 - Enable access to ADC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_MASK (0x2000U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_SHIFT (13U)
/*! SDADC - Enable access to SDADC
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_MASK (0x4000U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_SHIFT (14U)
/*! MICFIL - Enable access to MICFIL
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC0_MASK (0x8000U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC0_SHIFT (15U)
/*! PMC0 - Enable access to PMC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC0_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC0_MASK)

#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_MASK (0x80000U)
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_SHIFT (19U)
/*! LPI2C15 - Enable access to LPI2C15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_SHIFT)) & AHBSC3_COMPUTE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_MASK)
/*! @} */

/*! @name SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE - Access enable for SENSE domain masters to common AIPS peripherals. */
/*! @{ */

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_B_MASK (0x2U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_B_SHIFT (1U)
/*! MU0_B - Enable access to MU0_B
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_B_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU0_B_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_B_MASK (0x8U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_B_SHIFT (3U)
/*! MU1_B - Enable access to MU1_B
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_B_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU1_B_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_B_MASK (0x20U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_B_SHIFT (5U)
/*! MU2_B - Enable access to MU2_B
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_B_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MU2_B_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_MASK (0x40U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_SHIFT (6U)
/*! SEMA42_0 - Enable access to SEMA42_0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SEMA42_0_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS2_MASK (0x200U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS2_SHIFT (9U)
/*! OSTIMER_ALIAS2 - Enable access to OSTIMER_ALIAS2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS2_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS2_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS3_MASK (0x400U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS3_SHIFT (10U)
/*! OSTIMER_ALIAS3 - Enable access to OSTIMER_ALIAS3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS3_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_OSTIMER_ALIAS3_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_MASK (0x800U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_SHIFT (11U)
/*! ACMP0 - Enable access to ACMP0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ACMP0_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_MASK (0x1000U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_SHIFT (12U)
/*! ADC0 - Enable access to ADC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_ADC0_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_MASK (0x2000U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_SHIFT (13U)
/*! SDADC - Enable access to SDADC
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_SDADC_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_MASK (0x4000U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_SHIFT (14U)
/*! MICFIL - Enable access to MICFIL
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_MICFIL_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC1_MASK (0x10000U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC1_SHIFT (16U)
/*! PMC1 - Enable access to PMC0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC1_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_PMC1_MASK)

#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_MASK (0x80000U)
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_SHIFT (19U)
/*! LPI2C15 - Enable access to LPI2C15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_SHIFT)) & AHBSC3_SENSE_AIPS_PERIPHERAL_ACCESS_ENABLE_LPI2C15_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC3_MASTER_SEC_LEVEL_HIFI1_MASK       (0x3U)
#define AHBSC3_MASTER_SEC_LEVEL_HIFI1_SHIFT      (0U)
/*! HIFI1 - HIFI1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC3_MASTER_SEC_LEVEL_HIFI1(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_LEVEL_HIFI1_SHIFT)) & AHBSC3_MASTER_SEC_LEVEL_HIFI1_MASK)

#define AHBSC3_MASTER_SEC_LEVEL_MEDIA_MASK       (0xCU)
#define AHBSC3_MASTER_SEC_LEVEL_MEDIA_SHIFT      (2U)
/*! MEDIA - MEDIA
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC3_MASTER_SEC_LEVEL_MEDIA(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_LEVEL_MEDIA_SHIFT)) & AHBSC3_MASTER_SEC_LEVEL_MEDIA_MASK)

#define AHBSC3_MASTER_SEC_LEVEL_DMA2_MASK        (0x30U)
#define AHBSC3_MASTER_SEC_LEVEL_DMA2_SHIFT       (4U)
/*! DMA2 - DMA2
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC3_MASTER_SEC_LEVEL_DMA2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_LEVEL_DMA2_SHIFT)) & AHBSC3_MASTER_SEC_LEVEL_DMA2_MASK)

#define AHBSC3_MASTER_SEC_LEVEL_DMA3_MASK        (0xC0U)
#define AHBSC3_MASTER_SEC_LEVEL_DMA3_SHIFT       (6U)
/*! DMA3 - DMA3
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC3_MASTER_SEC_LEVEL_DMA3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_LEVEL_DMA3_SHIFT)) & AHBSC3_MASTER_SEC_LEVEL_DMA3_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC3_MASTER_SEC_ANTI_POL_REG_HIFI1_MASK (0x3U)
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_HIFI1_SHIFT (0U)
/*! HIFI1 - HIFI1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_HIFI1(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_ANTI_POL_REG_HIFI1_SHIFT)) & AHBSC3_MASTER_SEC_ANTI_POL_REG_HIFI1_MASK)

#define AHBSC3_MASTER_SEC_ANTI_POL_REG_MEDIA_MASK (0xCU)
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_MEDIA_SHIFT (2U)
/*! MEDIA - MEDIA
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_MEDIA(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_ANTI_POL_REG_MEDIA_SHIFT)) & AHBSC3_MASTER_SEC_ANTI_POL_REG_MEDIA_MASK)

#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA2_MASK (0x30U)
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA2_SHIFT (4U)
/*! DMA2 - DMA2
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA2_SHIFT)) & AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA2_MASK)

#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA3_MASK (0xC0U)
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA3_SHIFT (6U)
/*! DMA3 - DMA3
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA3_SHIFT)) & AHBSC3_MASTER_SEC_ANTI_POL_REG_DMA3_MASK)
/*! @} */

/*! @name CPU1_LOCK_REG - Miscellaneous CPU1 Control Signals */
/*! @{ */

#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_VTOR_MASK   (0x3U)
#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_VTOR_SHIFT  (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU1) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU1) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_VTOR(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC3_CPU1_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHBSC3_CPU1_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_MPU_MASK    (0xCU)
#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_MPU_SHIFT   (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU1) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU1) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC3_CPU1_LOCK_REG_LOCK_NS_MPU(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC3_CPU1_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHBSC3_CPU1_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHBSC3_CPU1_LOCK_REG_LOCK_S_VTAIRCR_MASK (0x30U)
#define AHBSC3_CPU1_LOCK_REG_LOCK_S_VTAIRCR_SHIFT (4U)
/*! LOCK_S_VTAIRCR - LOCK_S_VTAIRCR
 *  0b00..Reserved
 *  0b01..CM33 (CPU1) LOCK_S_VTAIRCR is 1
 *  0b10..CM33 (CPU1) LOCK_S_VTAIRCR is 0
 *  0b11..Reserved
 */
#define AHBSC3_CPU1_LOCK_REG_LOCK_S_VTAIRCR(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC3_CPU1_LOCK_REG_LOCK_S_VTAIRCR_SHIFT)) & AHBSC3_CPU1_LOCK_REG_LOCK_S_VTAIRCR_MASK)

#define AHBSC3_CPU1_LOCK_REG_LOCK_S_MPU_MASK     (0xC0U)
#define AHBSC3_CPU1_LOCK_REG_LOCK_S_MPU_SHIFT    (6U)
/*! LOCK_S_MPU - LOCK_S_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU1) LOCK_S_MPU is 1
 *  0b10..CM33 (CPU1) LOCK_S_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC3_CPU1_LOCK_REG_LOCK_S_MPU(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC3_CPU1_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHBSC3_CPU1_LOCK_REG_LOCK_S_MPU_MASK)

#define AHBSC3_CPU1_LOCK_REG_LOCK_SAU_MASK       (0x300U)
#define AHBSC3_CPU1_LOCK_REG_LOCK_SAU_SHIFT      (8U)
/*! LOCK_SAU - LOCK_SAU
 *  0b00..Reserved
 *  0b01..CM33 (CPU1) LOCK_SAU is 1
 *  0b10..CM33 (CPU1) LOCK_SAU is 0
 *  0b11..Reserved
 */
#define AHBSC3_CPU1_LOCK_REG_LOCK_SAU(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC3_CPU1_LOCK_REG_LOCK_SAU_SHIFT)) & AHBSC3_CPU1_LOCK_REG_LOCK_SAU_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define AHBSC3_MISC_CTRL_DP_REG_WRITE_LOCK_MASK  (0x3U)
#define AHBSC3_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_WRITE_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC3_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC3_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHBSC3_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHBSC3_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define AHBSC3_MISC_CTRL_REG_WRITE_LOCK_MASK     (0x3U)
#define AHBSC3_MISC_CTRL_REG_WRITE_LOCK_SHIFT    (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_WRITE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHBSC3_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHBSC3_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC3_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC3_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC3_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC3_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC3_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC3_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC3_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC3_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC3_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC3_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC3_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC3_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC3_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC3_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC3_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC3_MISC_CTRL_REG_IDAU_ALL_NS_MASK    (0xC000U)
#define AHBSC3_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT   (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC3_MISC_CTRL_REG_IDAU_ALL_NS(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC3_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHBSC3_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBSC3_Register_Masks */


/*!
 * @}
 */ /* end of group AHBSC3_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBSC3_H_ */

