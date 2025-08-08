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
**         CMSIS Peripheral Access Layer for AHBSC0
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
 * @file PERI_AHBSC0.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBSC0
 *
 * CMSIS Peripheral Access Layer for AHBSC0
 */

#if !defined(PERI_AHBSC0_H_)
#define PERI_AHBSC0_H_                           /**< Symbol preventing repeated inclusion */

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
   -- AHBSC0 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC0_Peripheral_Access_Layer AHBSC0 Peripheral Access Layer
 * @{
 */

/** AHBSC0 - Size of Registers Arrays */
#define AHBSC0_ROM_MEM_RULE_COUNT                 4u
#define AHBSC0_XSPI1_REGION0_MEM_RULE_COUNT       4u
#define AHBSC0_XSPI1_REGION1_4_MEM_RULE_COUNT     4u
#define AHBSC0_XSPI0_REGION0_MEM_RULE_COUNT       4u
#define AHBSC0_XSPI0_REGION1_4_MEM_RULE_COUNT     4u
#define AHBSC0_PKC_RAM_RULE_COUNT                 1u
#define AHBSC0_SRAM_0_RULE_COUNT                  4u
#define AHBSC0_SRAM_1_RULE_COUNT                  4u
#define AHBSC0_SRAM_2_RULE_COUNT                  4u
#define AHBSC0_SRAM_3_RULE_COUNT                  4u
#define AHBSC0_SRAM_4_RULE_COUNT                  4u
#define AHBSC0_SRAM_5_RULE_COUNT                  4u
#define AHBSC0_SRAM_6_RULE_COUNT                  4u
#define AHBSC0_SRAM_7_RULE_COUNT                  4u
#define AHBSC0_SRAM_8_RULE_COUNT                  4u
#define AHBSC0_SRAM_9_RULE_COUNT                  4u
#define AHBSC0_SRAM_10_RULE_COUNT                 4u
#define AHBSC0_SRAM_11_RULE_COUNT                 4u
#define AHBSC0_SRAM_12_RULE_COUNT                 4u
#define AHBSC0_SRAM_13_RULE_COUNT                 4u
#define AHBSC0_SRAM_14_RULE_COUNT                 4u
#define AHBSC0_SRAM_15_RULE_COUNT                 4u
#define AHBSC0_SRAM_16_RULE_COUNT                 4u
#define AHBSC0_SRAM_17_RULE_COUNT                 4u
#define AHBSC0_SRAM_18_RULE_COUNT                 4u
#define AHBSC0_SRAM_19_RULE_COUNT                 4u
#define AHBSC0_SRAM_20_RULE_COUNT                 4u
#define AHBSC0_SRAM_21_RULE_COUNT                 4u
#define AHBSC0_SRAM_22_RULE_COUNT                 4u
#define AHBSC0_SRAM_23_RULE_COUNT                 4u
#define AHBSC0_SRAM_24_RULE_COUNT                 4u
#define AHBSC0_SRAM_25_RULE_COUNT                 4u
#define AHBSC0_SRAM_26_RULE_COUNT                 4u
#define AHBSC0_SRAM_27_RULE_COUNT                 4u
#define AHBSC0_SRAM_28_RULE_COUNT                 4u
#define AHBSC0_SRAM_29_RULE_COUNT                 4u
#define AHBSC0_HIFI4_TCM_RULE_COUNT               1u
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPION_RULE_COUNT 8u
#define AHBSC0_SEC_VIO_ADDRN_COUNT                29u
#define AHBSC0_SEC_VIO_MISC_INFON_COUNT           29u

/** AHBSC0 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ROM_MEM_RULE[AHBSC0_ROM_MEM_RULE_COUNT]; /**< ROM Memory Rule Register, array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t XSPI1_REGION0_MEM_RULE[AHBSC0_XSPI1_REGION0_MEM_RULE_COUNT]; /**< XSPI1 Region 0 Memory Rule Register, array offset: 0x30, array step: 0x4 */
  struct {                                         /* offset: 0x40, array step: 0x10 */
    __IO uint32_t XSPI1_REGION_MEM_RULE0;            /**< XSPI1 Region 1 Memory Rule Register..XSPI1 Region 4 Memory Rule Register, array offset: 0x40, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } XSPI1_REGION1_4_MEM_RULE[AHBSC0_XSPI1_REGION1_4_MEM_RULE_COUNT];
       uint8_t RESERVED_2[16];
  __IO uint32_t XSPI0_REGION0_MEM_RULE[AHBSC0_XSPI0_REGION0_MEM_RULE_COUNT]; /**< XSPI0 Region 0 Memory Rule, array offset: 0x90, array step: 0x4 */
  struct {                                         /* offset: 0xA0, array step: 0x10 */
    __IO uint32_t XSPI0_REGION_MEM_RULE0;            /**< XSPI0 Region 1 Memory Rule Register..XSPI0 Region 4 Memory Rule Register, array offset: 0xA0, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } XSPI0_REGION1_4_MEM_RULE[AHBSC0_XSPI0_REGION1_4_MEM_RULE_COUNT];
       uint8_t RESERVED_3[16];
  __IO uint32_t PKC_RAM_RULE[AHBSC0_PKC_RAM_RULE_COUNT]; /**< PKC RAM Memory Rule Register, array offset: 0xF0, array step: 0x4 */
       uint8_t RESERVED_4[28];
  __IO uint32_t SRAM_0_RULE[AHBSC0_SRAM_0_RULE_COUNT]; /**< RAM partition 0 Memory Rule Register, array offset: 0x110, array step: 0x4 */
  __IO uint32_t SRAM_1_RULE[AHBSC0_SRAM_1_RULE_COUNT]; /**< RAM partition 1 Memory Rule Register, array offset: 0x120, array step: 0x4 */
  __IO uint32_t SRAM_2_RULE[AHBSC0_SRAM_2_RULE_COUNT]; /**< RAM partition 2 Memory Rule Register, array offset: 0x130, array step: 0x4 */
  __IO uint32_t SRAM_3_RULE[AHBSC0_SRAM_3_RULE_COUNT]; /**< RAM partition 3 Memory Rule Register, array offset: 0x140, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t SRAM_4_RULE[AHBSC0_SRAM_4_RULE_COUNT]; /**< RAM partition 4 Memory Rule Register, array offset: 0x160, array step: 0x4 */
  __IO uint32_t SRAM_5_RULE[AHBSC0_SRAM_5_RULE_COUNT]; /**< RAM partition 5 Memory Rule Register, array offset: 0x170, array step: 0x4 */
       uint8_t RESERVED_6[16];
  __IO uint32_t SRAM_6_RULE[AHBSC0_SRAM_6_RULE_COUNT]; /**< RAM partition 6 Memory Rule Register, array offset: 0x190, array step: 0x4 */
  __IO uint32_t SRAM_7_RULE[AHBSC0_SRAM_7_RULE_COUNT]; /**< RAM partition 7 Memory Rule Register, array offset: 0x1A0, array step: 0x4 */
       uint8_t RESERVED_7[16];
  __IO uint32_t SRAM_8_RULE[AHBSC0_SRAM_8_RULE_COUNT]; /**< RAM partition 8 Memory Rule Register, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t SRAM_9_RULE[AHBSC0_SRAM_9_RULE_COUNT]; /**< RAM partition 9 Memory Rule Register, array offset: 0x1D0, array step: 0x4 */
       uint8_t RESERVED_8[16];
  __IO uint32_t SRAM_10_RULE[AHBSC0_SRAM_10_RULE_COUNT]; /**< RAM partition 10 Memory Rule Register, array offset: 0x1F0, array step: 0x4 */
  __IO uint32_t SRAM_11_RULE[AHBSC0_SRAM_11_RULE_COUNT]; /**< RAM partition 11 Memory Rule Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t SRAM_12_RULE[AHBSC0_SRAM_12_RULE_COUNT]; /**< RAM partition 12 Memory Rule Register, array offset: 0x220, array step: 0x4 */
  __IO uint32_t SRAM_13_RULE[AHBSC0_SRAM_13_RULE_COUNT]; /**< RAM partition 13 Memory Rule Register, array offset: 0x230, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t SRAM_14_RULE[AHBSC0_SRAM_14_RULE_COUNT]; /**< RAM partition 14 Memory Rule Register, array offset: 0x250, array step: 0x4 */
  __IO uint32_t SRAM_15_RULE[AHBSC0_SRAM_15_RULE_COUNT]; /**< RAM partition 15 Memory Rule Register, array offset: 0x260, array step: 0x4 */
       uint8_t RESERVED_11[16];
  __IO uint32_t SRAM_16_RULE[AHBSC0_SRAM_16_RULE_COUNT]; /**< RAM partition 16 Memory Rule Register, array offset: 0x280, array step: 0x4 */
  __IO uint32_t SRAM_17_RULE[AHBSC0_SRAM_17_RULE_COUNT]; /**< RAM partition 17 Memory Rule Register, array offset: 0x290, array step: 0x4 */
       uint8_t RESERVED_12[16];
  __IO uint32_t SRAM_18_RULE[AHBSC0_SRAM_18_RULE_COUNT]; /**< RAM partition 18 Memory Rule Register, array offset: 0x2B0, array step: 0x4 */
  __IO uint32_t SRAM_19_RULE[AHBSC0_SRAM_19_RULE_COUNT]; /**< RAM partition 19 Memory Rule Register, array offset: 0x2C0, array step: 0x4 */
  __IO uint32_t SRAM_20_RULE[AHBSC0_SRAM_20_RULE_COUNT]; /**< RAM partition 20 Memory Rule Register, array offset: 0x2D0, array step: 0x4 */
  __IO uint32_t SRAM_21_RULE[AHBSC0_SRAM_21_RULE_COUNT]; /**< RAM partition 21 Memory Rule Register, array offset: 0x2E0, array step: 0x4 */
  __IO uint32_t SRAM_22_RULE[AHBSC0_SRAM_22_RULE_COUNT]; /**< RAM partition 22 Memory Rule Register, array offset: 0x2F0, array step: 0x4 */
  __IO uint32_t SRAM_23_RULE[AHBSC0_SRAM_23_RULE_COUNT]; /**< RAM partition 23 Memory Rule Register, array offset: 0x300, array step: 0x4 */
  __IO uint32_t SRAM_24_RULE[AHBSC0_SRAM_24_RULE_COUNT]; /**< RAM partition 24 Memory Rule Register, array offset: 0x310, array step: 0x4 */
  __IO uint32_t SRAM_25_RULE[AHBSC0_SRAM_25_RULE_COUNT]; /**< RAM partition 25 Memory Rule Register, array offset: 0x320, array step: 0x4 */
       uint8_t RESERVED_13[16];
  __IO uint32_t SRAM_26_RULE[AHBSC0_SRAM_26_RULE_COUNT]; /**< RAM partition 26 Memory Rule Register, array offset: 0x340, array step: 0x4 */
  __IO uint32_t SRAM_27_RULE[AHBSC0_SRAM_27_RULE_COUNT]; /**< RAM partition 27 Memory Rule Register, array offset: 0x350, array step: 0x4 */
  __IO uint32_t SRAM_28_RULE[AHBSC0_SRAM_28_RULE_COUNT]; /**< RAM partition 28 Memory Rule Register, array offset: 0x360, array step: 0x4 */
  __IO uint32_t SRAM_29_RULE[AHBSC0_SRAM_29_RULE_COUNT]; /**< RAM partition 29 Memory Rule Register, array offset: 0x370, array step: 0x4 */
       uint8_t RESERVED_14[16];
  __IO uint32_t HIFI4_TCM_RULE[AHBSC0_HIFI4_TCM_RULE_COUNT]; /**< HIFI4 TCM Memory Rule Register, array offset: 0x390, array step: 0x4 */
       uint8_t RESERVED_15[12];
  __IO uint32_t COMPUTE2MEDIA_RULE;                /**< COMPUTE domain to MEDIA domain Access Rule Register, offset: 0x3A0 */
       uint8_t RESERVED_16[12];
  __IO uint32_t MBUS2PBUS_RULE;                    /**< COMPUTE Pbus domain Rule Register, offset: 0x3B0 */
       uint8_t RESERVED_17[16];
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_RULE1;       /**< AHB Peripheral 0 Slaves Rule Register 1, offset: 0x3C4 */
       uint8_t RESERVED_18[8];
  struct {                                         /* offset: 0x3D0, array step: 0x10 */
    __IO uint32_t AHB_PERIPHERAL0_SLAVE_GPIO_RULE;   /**< AHB Peripheral 0 Slaves GPIO0 Rule Register..AHB Peripheral 0 Slaves GPIO7 Rule Register, array offset: 0x3D0, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } AHB_PERIPHERAL0_SLAVE_GPION_RULE[AHBSC0_AHB_PERIPHERAL0_SLAVE_GPION_RULE_COUNT];
  __IO uint32_t AHB_PERIPHERAL1_SLAVE_RULE;        /**< AHB Peripheral 1 Slaves Rule Register, offset: 0x450 */
       uint8_t RESERVED_19[12];
  __IO uint32_t AIPS1_BRIDGE_GROUP0_MEM_RULE0;     /**< AIPS1 Bridge Group 0 Memory Rule Register 0, offset: 0x460 */
  __IO uint32_t AIPS1_BRIDGE_GROUP0_MEM_RULE1;     /**< AIPS1 Bridge Group 0 Memory Rule Register 1, offset: 0x464 */
  __IO uint32_t AIPS1_BRIDGE_GROUP0_MEM_RULE2;     /**< AIPS1 Bridge Group 0 Memory Rule Register 2, offset: 0x468 */
       uint8_t RESERVED_20[4];
  __IO uint32_t AIPS1_BRIDGE_GROUP1_MEM_RULE0;     /**< AIPS1 Bridge Group 1 Memory Rule Register 0, offset: 0x470 */
  __IO uint32_t AIPS1_BRIDGE_GROUP1_MEM_RULE1;     /**< AIPS1 Bridge Group 1 Memory Rule Register 1, offset: 0x474 */
       uint8_t RESERVED_21[8];
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_RULE0;  /**< AHB Secure Control Peripheral Rule 0, offset: 0x480 */
       uint8_t RESERVED_22[12];
  __IO uint32_t AHB_PERIPHERAL2_SLAVE_RULE0;       /**< AHB Peripheral 2 Slave Rule Register 0, offset: 0x490 */
  __IO uint32_t AHB_PERIPHERAL2_SLAVE_RULE1;       /**< AHB Peripheral 2 Slave Rule Register 1, offset: 0x494 */
       uint8_t RESERVED_23[8];
  __IO uint32_t AIPS0_BRIDGE_GROUP0_MEM_RULE0;     /**< AIPS0 Bridge Group 0 Memory Rule Register 0, offset: 0x4A0 */
  __IO uint32_t AIPS0_BRIDGE_GROUP0_MEM_RULE1;     /**< AIPS0 Bridge Group 0 Memory Rule Register 1, offset: 0x4A4 */
       uint8_t RESERVED_24[8];
  __IO uint32_t AIPS0_BRIDGE_GROUP1_MEM_RULE0;     /**< AIPS0 Bridge Group 1 Memory Rule Register 0, offset: 0x4B0 */
       uint8_t RESERVED_25[28];
  __IO uint32_t APB_SLAVE_GROUP0_RULE0;            /**< APB Bridge Peripheral 0 Rule 0, offset: 0x4D0 */
  __IO uint32_t APB_SLAVE_GROUP0_RULE1;            /**< APB Bridge Peripheral 0 Rule Register 1, offset: 0x4D4 */
  __IO uint32_t APB_SLAVE_GROUP0_RULE2;            /**< APB Bridge Peripheral 0 Rule Register 2, offset: 0x4D8 */
  __IO uint32_t APB_SLAVE_GROUP0_RULE3;            /**< APB Bridge Peripheral 0 Rule Register 3, offset: 0x4DC */
  __IO uint32_t APB_SLAVE_GROUP1_RULE0;            /**< APB Bridge Peripheral 1 Rule Register 0, offset: 0x4E0 */
  __IO uint32_t APB_SLAVE_GROUP1_RULE1;            /**< APB Bridge Peripheral 1 Rule Register 1, offset: 0x4E4 */
  __IO uint32_t APB_SLAVE_GROUP1_RULE2;            /**< APB Bridge Peripheral 1 Rule 2 Register, offset: 0x4E8 */
  __IO uint32_t APB_SLAVE_GROUP1_RULE3;            /**< APB Bridge Peripheral 1 Rule 3 Register, offset: 0x4EC */
  __IO uint32_t SHARED_APB_SLAVE_GROUP0_RULE0;     /**< Shared APB Bridge Peripheral 0 Rule 0, offset: 0x4F0 */
  __IO uint32_t SHARED_APB_SLAVE_GROUP0_RULE1;     /**< Shared APB Bridge Peripheral 0 Rule 1, offset: 0x4F4 */
       uint8_t RESERVED_26[24];
  __IO uint32_t AIPS2_BRIDGE_GROUP0_MEM_RULE0;     /**< AIPS2 Bridge Group 0 Memory Rule Register 0, offset: 0x510 */
  __IO uint32_t AIPS2_BRIDGE_GROUP0_MEM_RULE1;     /**< AIPS2 Bridge Group 0 Memory Rule Register 1, offset: 0x514 */
       uint8_t RESERVED_27[8];
  __IO uint32_t AIPS2_BRIDGE_GROUP1_MEM_RULE0;     /**< AIPS2 Bridge Group 1 Memory Rule Register 0, offset: 0x520 */
       uint8_t RESERVED_28[12];
  __IO uint32_t AHB_SECURE_CTRL_SENSE_RULE0;       /**< Sense Domain AHB Secure Control Peripheral Rule 0, offset: 0x530 */
       uint8_t RESERVED_29[28];
  __IO uint32_t MEDIA_AHB_PERIPHERAL_SLAVE_RULE0;  /**< MEDIA domain AHB peripheral slave, offset: 0x550 */
       uint8_t RESERVED_30[12];
  __IO uint32_t MEDIA_APB_PERIPHERAL_SLAVE_RULE0;  /**< MEDIA domain APB peripheral slave Rule Register, offset: 0x560 */
       uint8_t RESERVED_31[12];
  __IO uint32_t EZHV_SRAM_RULE0;                   /**< EZHV SRAM Memory Rule Register, offset: 0x570 */
       uint8_t RESERVED_32[2188];
  __I  uint32_t SEC_VIO_ADDR[AHBSC0_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_33[12];
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC0_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_34[12];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_35[124];
  __IO uint32_t COMPUTE_ARB0RAM_ACCESS_ENABLE;     /**< Access enable for COMPUTE domain masters to RAM partitions., offset: 0xF80 */
  __IO uint32_t SENSE_ARB0RAM_ACCESS_ENABLE;       /**< Access enable for SENSE domain masters to RAM partitions., offset: 0xF84 */
  __IO uint32_t MEDIA_ARB0RAM_ACCESS_ENABLE;       /**< Access enable for MEDIA domain masters to RAM partitions., offset: 0xF88 */
  __IO uint32_t NPU_ARB0RAM_ACCESS_ENABLE;         /**< Access enable for NPU domain masters to RAM partitions., offset: 0xF8C */
  __IO uint32_t HIFI4_ARB0RAM_ACCESS_ENABLE;       /**< Access enable for HIFI4 to RAM partitions., offset: 0xF90 */
       uint8_t RESERVED_36[60];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_37[20];
  __IO uint32_t CPU0_LOCK_REG;                     /**< Miscellaneous CPU0 Control Signals, offset: 0xFEC */
       uint8_t RESERVED_38[8];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} AHBSC0_Type;

/* ----------------------------------------------------------------------------
   -- AHBSC0 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC0_Register_Masks AHBSC0 Register Masks
 * @{
 */

/*! @name ROM_MEM_RULE - ROM Memory Rule Register */
/*! @{ */

#define AHBSC0_ROM_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_ROM_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE0_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE0_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_ROM_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE1_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE1_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_ROM_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE2_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE2_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_ROM_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE3_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE3_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_ROM_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE4_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE4_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_ROM_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE5_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE5_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_ROM_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE6_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE6_MASK)

#define AHBSC0_ROM_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_ROM_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_ROM_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_ROM_MEM_RULE_RULE7_SHIFT)) & AHBSC0_ROM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name XSPI1_REGION0_MEM_RULE - XSPI1 Region 0 Memory Rule Register */
/*! @{ */

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE0_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE0_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE1_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE1_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE2_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE2_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE3_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE3_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE4(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE4_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE4_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE5(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE5_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE5_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE6(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE6_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE6_MASK)

#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION0_MEM_RULE_RULE7(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION0_MEM_RULE_RULE7_SHIFT)) & AHBSC0_XSPI1_REGION0_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name XSPI1_REGION_MEM_RULE0 - XSPI1 Region 1 Memory Rule Register..XSPI1 Region 4 Memory Rule Register */
/*! @{ */

#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION_MEM_RULE0_RULE0_SHIFT)) & AHBSC0_XSPI1_REGION_MEM_RULE0_RULE0_MASK)

#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION_MEM_RULE0_RULE1_SHIFT)) & AHBSC0_XSPI1_REGION_MEM_RULE0_RULE1_MASK)

#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION_MEM_RULE0_RULE2_SHIFT)) & AHBSC0_XSPI1_REGION_MEM_RULE0_RULE2_MASK)

#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI1_REGION_MEM_RULE0_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI1_REGION_MEM_RULE0_RULE3_SHIFT)) & AHBSC0_XSPI1_REGION_MEM_RULE0_RULE3_MASK)
/*! @} */

/* The count of AHBSC0_XSPI1_REGION_MEM_RULE0 */
#define AHBSC0_XSPI1_REGION_MEM_RULE0_COUNT      (4U)

/*! @name XSPI0_REGION0_MEM_RULE - XSPI0 Region 0 Memory Rule */
/*! @{ */

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE0_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE0_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE1_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE1_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE2_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE2_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE3_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE3_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE4(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE4_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE4_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE5(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE5_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE5_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE6(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE6_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE6_MASK)

#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION0_MEM_RULE_RULE7(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION0_MEM_RULE_RULE7_SHIFT)) & AHBSC0_XSPI0_REGION0_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name XSPI0_REGION_MEM_RULE0 - XSPI0 Region 1 Memory Rule Register..XSPI0 Region 4 Memory Rule Register */
/*! @{ */

#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION_MEM_RULE0_RULE0_SHIFT)) & AHBSC0_XSPI0_REGION_MEM_RULE0_RULE0_MASK)

#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION_MEM_RULE0_RULE1_SHIFT)) & AHBSC0_XSPI0_REGION_MEM_RULE0_RULE1_MASK)

#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION_MEM_RULE0_RULE2_SHIFT)) & AHBSC0_XSPI0_REGION_MEM_RULE0_RULE2_MASK)

#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_XSPI0_REGION_MEM_RULE0_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_XSPI0_REGION_MEM_RULE0_RULE3_SHIFT)) & AHBSC0_XSPI0_REGION_MEM_RULE0_RULE3_MASK)
/*! @} */

/* The count of AHBSC0_XSPI0_REGION_MEM_RULE0 */
#define AHBSC0_XSPI0_REGION_MEM_RULE0_COUNT      (4U)

/*! @name PKC_RAM_RULE - PKC RAM Memory Rule Register */
/*! @{ */

#define AHBSC0_PKC_RAM_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_PKC_RAM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_PKC_RAM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_PKC_RAM_RULE_RULE0_SHIFT)) & AHBSC0_PKC_RAM_RULE_RULE0_MASK)

#define AHBSC0_PKC_RAM_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_PKC_RAM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_PKC_RAM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_PKC_RAM_RULE_RULE1_SHIFT)) & AHBSC0_PKC_RAM_RULE_RULE1_MASK)
/*! @} */

/*! @name SRAM_0_RULE - RAM partition 0 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_0_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_0_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE0_MASK)

#define AHBSC0_SRAM_0_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_0_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE1_MASK)

#define AHBSC0_SRAM_0_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_0_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE2_MASK)

#define AHBSC0_SRAM_0_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_0_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE3_MASK)

#define AHBSC0_SRAM_0_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_0_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE4_MASK)

#define AHBSC0_SRAM_0_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_0_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE5_MASK)

#define AHBSC0_SRAM_0_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_0_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE6_MASK)

#define AHBSC0_SRAM_0_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_0_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_0_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_0_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_0_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_1_RULE - RAM partition 1 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_1_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_1_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE0_MASK)

#define AHBSC0_SRAM_1_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_1_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE1_MASK)

#define AHBSC0_SRAM_1_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_1_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE2_MASK)

#define AHBSC0_SRAM_1_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_1_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE3_MASK)

#define AHBSC0_SRAM_1_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_1_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE4_MASK)

#define AHBSC0_SRAM_1_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_1_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE5_MASK)

#define AHBSC0_SRAM_1_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_1_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE6_MASK)

#define AHBSC0_SRAM_1_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_1_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_1_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_1_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_1_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_2_RULE - RAM partition 2 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_2_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_2_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE0_MASK)

#define AHBSC0_SRAM_2_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_2_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE1_MASK)

#define AHBSC0_SRAM_2_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_2_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE2_MASK)

#define AHBSC0_SRAM_2_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_2_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE3_MASK)

#define AHBSC0_SRAM_2_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_2_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE4_MASK)

#define AHBSC0_SRAM_2_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_2_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE5_MASK)

#define AHBSC0_SRAM_2_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_2_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE6_MASK)

#define AHBSC0_SRAM_2_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_2_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_2_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_2_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_2_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_3_RULE - RAM partition 3 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_3_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_3_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE0_MASK)

#define AHBSC0_SRAM_3_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_3_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE1_MASK)

#define AHBSC0_SRAM_3_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_3_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE2_MASK)

#define AHBSC0_SRAM_3_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_3_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE3_MASK)

#define AHBSC0_SRAM_3_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_3_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE4_MASK)

#define AHBSC0_SRAM_3_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_3_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE5_MASK)

#define AHBSC0_SRAM_3_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_3_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE6_MASK)

#define AHBSC0_SRAM_3_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_3_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_3_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_3_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_3_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_4_RULE - RAM partition 4 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_4_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_4_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE0_MASK)

#define AHBSC0_SRAM_4_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_4_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE1_MASK)

#define AHBSC0_SRAM_4_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_4_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE2_MASK)

#define AHBSC0_SRAM_4_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_4_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE3_MASK)

#define AHBSC0_SRAM_4_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_4_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE4_MASK)

#define AHBSC0_SRAM_4_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_4_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE5_MASK)

#define AHBSC0_SRAM_4_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_4_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE6_MASK)

#define AHBSC0_SRAM_4_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_4_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_4_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_4_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_4_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_5_RULE - RAM partition 5 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_5_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_5_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE0_MASK)

#define AHBSC0_SRAM_5_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_5_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE1_MASK)

#define AHBSC0_SRAM_5_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_5_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE2_MASK)

#define AHBSC0_SRAM_5_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_5_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE3_MASK)

#define AHBSC0_SRAM_5_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_5_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE4_MASK)

#define AHBSC0_SRAM_5_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_5_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE5_MASK)

#define AHBSC0_SRAM_5_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_5_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE6_MASK)

#define AHBSC0_SRAM_5_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_5_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_5_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_5_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_5_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_6_RULE - RAM partition 6 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_6_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_6_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE0_MASK)

#define AHBSC0_SRAM_6_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_6_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE1_MASK)

#define AHBSC0_SRAM_6_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_6_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE2_MASK)

#define AHBSC0_SRAM_6_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_6_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE3_MASK)

#define AHBSC0_SRAM_6_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_6_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE4_MASK)

#define AHBSC0_SRAM_6_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_6_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE5_MASK)

#define AHBSC0_SRAM_6_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_6_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE6_MASK)

#define AHBSC0_SRAM_6_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_6_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_6_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_6_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_6_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_7_RULE - RAM partition 7 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_7_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_7_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE0_MASK)

#define AHBSC0_SRAM_7_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_7_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE1_MASK)

#define AHBSC0_SRAM_7_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_7_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE2_MASK)

#define AHBSC0_SRAM_7_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_7_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE3_MASK)

#define AHBSC0_SRAM_7_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_7_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE4_MASK)

#define AHBSC0_SRAM_7_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_7_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE5_MASK)

#define AHBSC0_SRAM_7_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_7_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE6_MASK)

#define AHBSC0_SRAM_7_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_7_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_7_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_7_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_7_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_8_RULE - RAM partition 8 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_8_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_8_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE0_MASK)

#define AHBSC0_SRAM_8_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_8_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE1_MASK)

#define AHBSC0_SRAM_8_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_8_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE2_MASK)

#define AHBSC0_SRAM_8_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_8_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE3_MASK)

#define AHBSC0_SRAM_8_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_8_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE4_MASK)

#define AHBSC0_SRAM_8_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_8_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE5_MASK)

#define AHBSC0_SRAM_8_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_8_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE6_MASK)

#define AHBSC0_SRAM_8_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_8_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_8_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_8_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_8_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_9_RULE - RAM partition 9 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_9_RULE_RULE0_MASK            (0x3U)
#define AHBSC0_SRAM_9_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE0_MASK)

#define AHBSC0_SRAM_9_RULE_RULE1_MASK            (0x30U)
#define AHBSC0_SRAM_9_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE1_MASK)

#define AHBSC0_SRAM_9_RULE_RULE2_MASK            (0x300U)
#define AHBSC0_SRAM_9_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE2_MASK)

#define AHBSC0_SRAM_9_RULE_RULE3_MASK            (0x3000U)
#define AHBSC0_SRAM_9_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE3_MASK)

#define AHBSC0_SRAM_9_RULE_RULE4_MASK            (0x30000U)
#define AHBSC0_SRAM_9_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE4_MASK)

#define AHBSC0_SRAM_9_RULE_RULE5_MASK            (0x300000U)
#define AHBSC0_SRAM_9_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE5_MASK)

#define AHBSC0_SRAM_9_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC0_SRAM_9_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE6_MASK)

#define AHBSC0_SRAM_9_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC0_SRAM_9_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_9_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_9_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_9_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_10_RULE - RAM partition 10 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_10_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_10_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE0_MASK)

#define AHBSC0_SRAM_10_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_10_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE1_MASK)

#define AHBSC0_SRAM_10_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_10_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE2_MASK)

#define AHBSC0_SRAM_10_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_10_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE3_MASK)

#define AHBSC0_SRAM_10_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_10_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE4_MASK)

#define AHBSC0_SRAM_10_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_10_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE5_MASK)

#define AHBSC0_SRAM_10_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_10_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE6_MASK)

#define AHBSC0_SRAM_10_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_10_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_10_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_10_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_10_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_11_RULE - RAM partition 11 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_11_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_11_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE0_MASK)

#define AHBSC0_SRAM_11_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_11_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE1_MASK)

#define AHBSC0_SRAM_11_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_11_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE2_MASK)

#define AHBSC0_SRAM_11_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_11_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE3_MASK)

#define AHBSC0_SRAM_11_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_11_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE4_MASK)

#define AHBSC0_SRAM_11_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_11_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE5_MASK)

#define AHBSC0_SRAM_11_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_11_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE6_MASK)

#define AHBSC0_SRAM_11_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_11_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_11_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_11_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_11_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_12_RULE - RAM partition 12 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_12_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_12_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE0_MASK)

#define AHBSC0_SRAM_12_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_12_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE1_MASK)

#define AHBSC0_SRAM_12_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_12_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE2_MASK)

#define AHBSC0_SRAM_12_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_12_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE3_MASK)

#define AHBSC0_SRAM_12_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_12_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE4_MASK)

#define AHBSC0_SRAM_12_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_12_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE5_MASK)

#define AHBSC0_SRAM_12_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_12_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE6_MASK)

#define AHBSC0_SRAM_12_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_12_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_12_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_12_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_12_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_13_RULE - RAM partition 13 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_13_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_13_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE0_MASK)

#define AHBSC0_SRAM_13_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_13_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE1_MASK)

#define AHBSC0_SRAM_13_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_13_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE2_MASK)

#define AHBSC0_SRAM_13_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_13_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE3_MASK)

#define AHBSC0_SRAM_13_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_13_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE4_MASK)

#define AHBSC0_SRAM_13_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_13_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE5_MASK)

#define AHBSC0_SRAM_13_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_13_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE6_MASK)

#define AHBSC0_SRAM_13_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_13_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_13_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_13_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_13_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_14_RULE - RAM partition 14 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_14_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_14_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE0_MASK)

#define AHBSC0_SRAM_14_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_14_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE1_MASK)

#define AHBSC0_SRAM_14_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_14_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE2_MASK)

#define AHBSC0_SRAM_14_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_14_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE3_MASK)

#define AHBSC0_SRAM_14_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_14_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE4_MASK)

#define AHBSC0_SRAM_14_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_14_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE5_MASK)

#define AHBSC0_SRAM_14_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_14_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE6_MASK)

#define AHBSC0_SRAM_14_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_14_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_14_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_14_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_14_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_15_RULE - RAM partition 15 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_15_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_15_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE0_MASK)

#define AHBSC0_SRAM_15_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_15_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE1_MASK)

#define AHBSC0_SRAM_15_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_15_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE2_MASK)

#define AHBSC0_SRAM_15_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_15_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE3_MASK)

#define AHBSC0_SRAM_15_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_15_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE4_MASK)

#define AHBSC0_SRAM_15_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_15_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE5_MASK)

#define AHBSC0_SRAM_15_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_15_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE6_MASK)

#define AHBSC0_SRAM_15_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_15_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_15_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_15_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_15_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_16_RULE - RAM partition 16 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_16_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_16_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE0_MASK)

#define AHBSC0_SRAM_16_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_16_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE1_MASK)

#define AHBSC0_SRAM_16_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_16_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE2_MASK)

#define AHBSC0_SRAM_16_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_16_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE3_MASK)

#define AHBSC0_SRAM_16_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_16_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE4_MASK)

#define AHBSC0_SRAM_16_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_16_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE5_MASK)

#define AHBSC0_SRAM_16_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_16_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE6_MASK)

#define AHBSC0_SRAM_16_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_16_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_16_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_16_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_16_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_17_RULE - RAM partition 17 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_17_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_17_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE0_MASK)

#define AHBSC0_SRAM_17_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_17_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE1_MASK)

#define AHBSC0_SRAM_17_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_17_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE2_MASK)

#define AHBSC0_SRAM_17_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_17_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE3_MASK)

#define AHBSC0_SRAM_17_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_17_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE4_MASK)

#define AHBSC0_SRAM_17_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_17_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE5_MASK)

#define AHBSC0_SRAM_17_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_17_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE6_MASK)

#define AHBSC0_SRAM_17_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_17_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_17_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_17_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_17_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_18_RULE - RAM partition 18 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_18_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_18_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE0_MASK)

#define AHBSC0_SRAM_18_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_18_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE1_MASK)

#define AHBSC0_SRAM_18_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_18_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE2_MASK)

#define AHBSC0_SRAM_18_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_18_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE3_MASK)

#define AHBSC0_SRAM_18_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_18_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE4_MASK)

#define AHBSC0_SRAM_18_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_18_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE5_MASK)

#define AHBSC0_SRAM_18_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_18_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE6_MASK)

#define AHBSC0_SRAM_18_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_18_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_18_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_18_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_18_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_19_RULE - RAM partition 19 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_19_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_19_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE0_MASK)

#define AHBSC0_SRAM_19_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_19_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE1_MASK)

#define AHBSC0_SRAM_19_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_19_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE2_MASK)

#define AHBSC0_SRAM_19_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_19_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE3_MASK)

#define AHBSC0_SRAM_19_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_19_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE4_MASK)

#define AHBSC0_SRAM_19_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_19_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE5_MASK)

#define AHBSC0_SRAM_19_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_19_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE6_MASK)

#define AHBSC0_SRAM_19_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_19_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_19_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_19_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_19_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_20_RULE - RAM partition 20 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_20_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_20_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE0_MASK)

#define AHBSC0_SRAM_20_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_20_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE1_MASK)

#define AHBSC0_SRAM_20_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_20_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE2_MASK)

#define AHBSC0_SRAM_20_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_20_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE3_MASK)

#define AHBSC0_SRAM_20_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_20_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE4_MASK)

#define AHBSC0_SRAM_20_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_20_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE5_MASK)

#define AHBSC0_SRAM_20_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_20_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE6_MASK)

#define AHBSC0_SRAM_20_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_20_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_20_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_20_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_20_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_21_RULE - RAM partition 21 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_21_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_21_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE0_MASK)

#define AHBSC0_SRAM_21_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_21_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE1_MASK)

#define AHBSC0_SRAM_21_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_21_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE2_MASK)

#define AHBSC0_SRAM_21_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_21_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE3_MASK)

#define AHBSC0_SRAM_21_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_21_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE4_MASK)

#define AHBSC0_SRAM_21_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_21_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE5_MASK)

#define AHBSC0_SRAM_21_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_21_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE6_MASK)

#define AHBSC0_SRAM_21_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_21_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_21_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_21_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_21_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_22_RULE - RAM partition 22 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_22_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_22_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE0_MASK)

#define AHBSC0_SRAM_22_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_22_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE1_MASK)

#define AHBSC0_SRAM_22_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_22_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE2_MASK)

#define AHBSC0_SRAM_22_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_22_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE3_MASK)

#define AHBSC0_SRAM_22_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_22_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE4_MASK)

#define AHBSC0_SRAM_22_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_22_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE5_MASK)

#define AHBSC0_SRAM_22_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_22_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE6_MASK)

#define AHBSC0_SRAM_22_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_22_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_22_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_22_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_22_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_23_RULE - RAM partition 23 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_23_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_23_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE0_MASK)

#define AHBSC0_SRAM_23_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_23_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE1_MASK)

#define AHBSC0_SRAM_23_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_23_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE2_MASK)

#define AHBSC0_SRAM_23_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_23_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE3_MASK)

#define AHBSC0_SRAM_23_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_23_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE4_MASK)

#define AHBSC0_SRAM_23_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_23_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE5_MASK)

#define AHBSC0_SRAM_23_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_23_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE6_MASK)

#define AHBSC0_SRAM_23_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_23_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_23_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_23_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_23_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_24_RULE - RAM partition 24 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_24_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_24_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE0_MASK)

#define AHBSC0_SRAM_24_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_24_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE1_MASK)

#define AHBSC0_SRAM_24_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_24_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE2_MASK)

#define AHBSC0_SRAM_24_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_24_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE3_MASK)

#define AHBSC0_SRAM_24_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_24_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE4_MASK)

#define AHBSC0_SRAM_24_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_24_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE5_MASK)

#define AHBSC0_SRAM_24_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_24_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE6_MASK)

#define AHBSC0_SRAM_24_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_24_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_24_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_24_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_24_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_25_RULE - RAM partition 25 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_25_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_25_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE0_MASK)

#define AHBSC0_SRAM_25_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_25_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE1_MASK)

#define AHBSC0_SRAM_25_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_25_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE2_MASK)

#define AHBSC0_SRAM_25_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_25_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE3_MASK)

#define AHBSC0_SRAM_25_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_25_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE4_MASK)

#define AHBSC0_SRAM_25_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_25_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE5_MASK)

#define AHBSC0_SRAM_25_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_25_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE6_MASK)

#define AHBSC0_SRAM_25_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_25_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_25_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_25_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_25_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_26_RULE - RAM partition 26 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_26_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_26_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE0_MASK)

#define AHBSC0_SRAM_26_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_26_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE1_MASK)

#define AHBSC0_SRAM_26_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_26_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE2_MASK)

#define AHBSC0_SRAM_26_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_26_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE3_MASK)

#define AHBSC0_SRAM_26_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_26_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE4_MASK)

#define AHBSC0_SRAM_26_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_26_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE5_MASK)

#define AHBSC0_SRAM_26_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_26_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE6_MASK)

#define AHBSC0_SRAM_26_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_26_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_26_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_26_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_26_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_27_RULE - RAM partition 27 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_27_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_27_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE0_MASK)

#define AHBSC0_SRAM_27_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_27_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE1_MASK)

#define AHBSC0_SRAM_27_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_27_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE2_MASK)

#define AHBSC0_SRAM_27_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_27_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE3_MASK)

#define AHBSC0_SRAM_27_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_27_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE4_MASK)

#define AHBSC0_SRAM_27_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_27_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE5_MASK)

#define AHBSC0_SRAM_27_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_27_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE6_MASK)

#define AHBSC0_SRAM_27_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_27_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_27_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_27_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_27_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_28_RULE - RAM partition 28 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_28_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_28_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE0_MASK)

#define AHBSC0_SRAM_28_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_28_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE1_MASK)

#define AHBSC0_SRAM_28_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_28_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE2_MASK)

#define AHBSC0_SRAM_28_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_28_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE3_MASK)

#define AHBSC0_SRAM_28_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_28_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE4_MASK)

#define AHBSC0_SRAM_28_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_28_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE5_MASK)

#define AHBSC0_SRAM_28_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_28_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE6_MASK)

#define AHBSC0_SRAM_28_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_28_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_28_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_28_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_28_RULE_RULE7_MASK)
/*! @} */

/*! @name SRAM_29_RULE - RAM partition 29 Memory Rule Register */
/*! @{ */

#define AHBSC0_SRAM_29_RULE_RULE0_MASK           (0x3U)
#define AHBSC0_SRAM_29_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE0_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE0_MASK)

#define AHBSC0_SRAM_29_RULE_RULE1_MASK           (0x30U)
#define AHBSC0_SRAM_29_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE1_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE1_MASK)

#define AHBSC0_SRAM_29_RULE_RULE2_MASK           (0x300U)
#define AHBSC0_SRAM_29_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE2_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE2_MASK)

#define AHBSC0_SRAM_29_RULE_RULE3_MASK           (0x3000U)
#define AHBSC0_SRAM_29_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE3_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE3_MASK)

#define AHBSC0_SRAM_29_RULE_RULE4_MASK           (0x30000U)
#define AHBSC0_SRAM_29_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE4_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE4_MASK)

#define AHBSC0_SRAM_29_RULE_RULE5_MASK           (0x300000U)
#define AHBSC0_SRAM_29_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE5_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE5_MASK)

#define AHBSC0_SRAM_29_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC0_SRAM_29_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE6_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE6_MASK)

#define AHBSC0_SRAM_29_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC0_SRAM_29_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SRAM_29_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC0_SRAM_29_RULE_RULE7_SHIFT)) & AHBSC0_SRAM_29_RULE_RULE7_MASK)
/*! @} */

/*! @name HIFI4_TCM_RULE - HIFI4 TCM Memory Rule Register */
/*! @{ */

#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE0_MASK (0x3U)
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE0_SHIFT (0U)
/*! HIFI4_DTCM_RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE0_SHIFT)) & AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE0_MASK)

#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE1_MASK (0x30U)
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE1_SHIFT (4U)
/*! HIFI4_DTCM_RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE1_SHIFT)) & AHBSC0_HIFI4_TCM_RULE_HIFI4_DTCM_RULE1_MASK)

#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE0_MASK (0x30000U)
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE0_SHIFT (16U)
/*! HIFI4_ITCM_RULE0 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE0_SHIFT)) & AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE0_MASK)

#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE1_MASK (0x300000U)
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE1_SHIFT (20U)
/*! HIFI4_ITCM_RULE1 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE1_SHIFT)) & AHBSC0_HIFI4_TCM_RULE_HIFI4_ITCM_RULE1_MASK)
/*! @} */

/*! @name COMPUTE2MEDIA_RULE - COMPUTE domain to MEDIA domain Access Rule Register */
/*! @{ */

#define AHBSC0_COMPUTE2MEDIA_RULE_XSPI2_MASK     (0x3U)
#define AHBSC0_COMPUTE2MEDIA_RULE_XSPI2_SHIFT    (0U)
/*! XSPI2 - XSPI2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_COMPUTE2MEDIA_RULE_XSPI2(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE2MEDIA_RULE_XSPI2_SHIFT)) & AHBSC0_COMPUTE2MEDIA_RULE_XSPI2_MASK)
/*! @} */

/*! @name MBUS2PBUS_RULE - COMPUTE Pbus domain Rule Register */
/*! @{ */

#define AHBSC0_MBUS2PBUS_RULE_PBUS_DOMAIN_MASK   (0x3U)
#define AHBSC0_MBUS2PBUS_RULE_PBUS_DOMAIN_SHIFT  (0U)
/*! PBUS_DOMAIN - COMPUTE Pbus domain
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_MBUS2PBUS_RULE_PBUS_DOMAIN(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC0_MBUS2PBUS_RULE_PBUS_DOMAIN_SHIFT)) & AHBSC0_MBUS2PBUS_RULE_PBUS_DOMAIN_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_RULE1 - AHB Peripheral 0 Slaves Rule Register 1 */
/*! @{ */

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM0_MASK (0x3U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM0_SHIFT (0U)
/*! LP_FLEXCOMM0 - LP_FLEXCOMM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM0_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM0_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM1_MASK (0x30U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM1_SHIFT (4U)
/*! LP_FLEXCOMM1 - LP_FLEXCOMM1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM1_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM1_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM2_MASK (0x300U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM2_SHIFT (8U)
/*! LP_FLEXCOMM2 - LP_FLEXCOMM2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM2_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM2_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM3_MASK (0x3000U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM3_SHIFT (12U)
/*! LP_FLEXCOMM3 - FLEXCOMM3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM3_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_LP_FLEXCOMM3_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_SCT0_MASK (0x30000U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_SCT0_SHIFT (16U)
/*! SCT0 - SCT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_SCT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_SCT0_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_SCT0_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG0_MASK (0x300000U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG0_SHIFT (20U)
/*! CDOG0 - CDOG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG0_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG0_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG1_MASK (0x3000000U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG1_SHIFT (24U)
/*! CDOG1 - CDOG1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG1_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG1_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG2_MASK (0x30000000U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG2_SHIFT (28U)
/*! CDOG2 - CDOG2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG2_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_RULE1_CDOG2_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_GPIO_RULE - AHB Peripheral 0 Slaves GPIO0 Rule Register..AHB Peripheral 0 Slaves GPIO7 Rule Register */
/*! @{ */

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_MASK (0x3U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_SHIFT (0U)
/*! GPIOn - GPIOn
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_MASK)

#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_ALIAS_MASK (0x30U)
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_ALIAS_SHIFT (4U)
/*! GPIOn_ALIAS - GPIOn ALIAS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_ALIAS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_ALIAS_SHIFT)) & AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_GPIOn_ALIAS_MASK)
/*! @} */

/* The count of AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE */
#define AHBSC0_AHB_PERIPHERAL0_SLAVE_GPIO_RULE_COUNT (8U)

/*! @name AHB_PERIPHERAL1_SLAVE_RULE - AHB Peripheral 1 Slaves Rule Register */
/*! @{ */

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_eDMA1_CH15_MASK (0x300U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_eDMA1_CH15_SHIFT (8U)
/*! eDMA1_CH15 - DMA_1_CH15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_eDMA1_CH15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_eDMA1_CH15_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_eDMA1_CH15_MASK)

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM4_MASK (0x3000U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM4_SHIFT (12U)
/*! FLEXCOMM4 - FLEXCOMM4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM4_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM4_MASK)

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM5_MASK (0x30000U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM5_SHIFT (16U)
/*! FLEXCOMM5 - FLEXCOMM5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM5_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM5_MASK)

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM6_MASK (0x300000U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM6_SHIFT (20U)
/*! FLEXCOMM6 - FLEXCOMM6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM6_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM6_MASK)

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM7_MASK (0x3000000U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM7_SHIFT (24U)
/*! FLEXCOMM7 - FLEXCOMM7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM7_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_FLEXCOMM7_MASK)

#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_NPU_MASK (0x30000000U)
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_NPU_SHIFT (28U)
/*! NPU - NPU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_NPU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_NPU_SHIFT)) & AHBSC0_AHB_PERIPHERAL1_SLAVE_RULE_NPU_MASK)
/*! @} */

/*! @name AIPS1_BRIDGE_GROUP0_MEM_RULE0 - AIPS1 Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_MP_MASK (0x3U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_MP_SHIFT (0U)
/*! eDMA0_MP - eDMA0 management
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_MP_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_MP_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH0_MASK (0x30U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH0_SHIFT (4U)
/*! eDMA0_CH0 - eDMA0 channel 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH0_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH0_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH1_MASK (0x300U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH1_SHIFT (8U)
/*! eDMA0_CH1 - eDMA0 channel 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH1_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH1_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH2_MASK (0x3000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH2_SHIFT (12U)
/*! eDMA0_CH2 - eDMA0 channel 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH2_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH2_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH3_MASK (0x30000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH3_SHIFT (16U)
/*! eDMA0_CH3 - eDMA0 channel 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH3_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH3_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH4_MASK (0x300000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH4_SHIFT (20U)
/*! eDMA0_CH4 - eDMA0 channel 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH4_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH4_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH5_MASK (0x3000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH5_SHIFT (24U)
/*! eDMA0_CH5 - eDMA0 channel 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH5_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH5_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH6_MASK (0x30000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH6_SHIFT (28U)
/*! eDMA0_CH6 - eDMA0 channel 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH6_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE0_eDMA0_CH6_MASK)
/*! @} */

/*! @name AIPS1_BRIDGE_GROUP0_MEM_RULE1 - AIPS1 Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH7_MASK (0x3U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH7_SHIFT (0U)
/*! eDMA0_CH7 - eDMA0 channel 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH7_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH7_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH8_MASK (0x30U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH8_SHIFT (4U)
/*! eDMA0_CH8 - eDMA0 channel 8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH8_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH8_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH9_MASK (0x300U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH9_SHIFT (8U)
/*! eDMA0_CH9 - eDMA0 channel
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH9_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH9_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH10_MASK (0x3000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH10_SHIFT (12U)
/*! eDMA0_CH10 - eDMA0 channel 10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH10_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH10_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA_CH11_MASK (0x30000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA_CH11_SHIFT (16U)
/*! eDMA_CH11 - eDMA0 channel 11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA_CH11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA_CH11_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA_CH11_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH12_MASK (0x300000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH12_SHIFT (20U)
/*! eDMA0_CH12 - eDMA0 channel 12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH12_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH12_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH13_MASK (0x3000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH13_SHIFT (24U)
/*! eDMA0_CH13 - eDMA0 channel 13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH13_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH13_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH14_MASK (0x30000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH14_SHIFT (28U)
/*! eDMA0_CH14 - DMA0 channel 14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH14_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE1_eDMA0_CH14_MASK)
/*! @} */

/*! @name AIPS1_BRIDGE_GROUP0_MEM_RULE2 - AIPS1 Bridge Group 0 Memory Rule Register 2 */
/*! @{ */

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_eDMA0_CH15_MASK (0x3U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_eDMA0_CH15_SHIFT (0U)
/*! eDMA0_CH15 - eDMA0 channel 15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_eDMA0_CH15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_eDMA0_CH15_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_eDMA0_CH15_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_CRC_MASK (0x30U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_CRC_SHIFT (4U)
/*! CRC - CRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_CRC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_CRC_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_CRC_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI0_MASK (0x300U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI0_SHIFT (8U)
/*! SAI0 - SAI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI0_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI0_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI1_MASK (0x3000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI1_SHIFT (12U)
/*! SAI1 - SAI1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI1_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI1_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI2_MASK (0x30000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI2_SHIFT (16U)
/*! SAI2 - SAI2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI2_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP0_MEM_RULE2_SAI2_MASK)
/*! @} */

/*! @name AIPS1_BRIDGE_GROUP1_MEM_RULE0 - AIPS1 Bridge Group 1 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_MP_MASK (0x3U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_MP_SHIFT (0U)
/*! DMA_1_MP - DMA1 management
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_MP_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_MP_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH0_MASK (0x30U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH0_SHIFT (4U)
/*! DMA_1_CH0 - DMA1 channel 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH0_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH0_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH1_MASK (0x300U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH1_SHIFT (8U)
/*! DMA_1_CH1 - DMA1 channel 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH1_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH1_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH2_MASK (0x3000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH2_SHIFT (12U)
/*! DMA_1_CH2 - DMA1 channel 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH2_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH2_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH3_MASK (0x30000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH3_SHIFT (16U)
/*! DMA_1_CH3 - DMA1 channel 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH3_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH3_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH4_MASK (0x300000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH4_SHIFT (20U)
/*! DMA_1_CH4 - DMA1 channel 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH4_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH4_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH5_MASK (0x3000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH5_SHIFT (24U)
/*! DMA_1_CH5 - DMA1 channel 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH5_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH5_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH6_MASK (0x30000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH6_SHIFT (28U)
/*! DMA_1_CH6 - DMA1 channel 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH6_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE0_DMA_1_CH6_MASK)
/*! @} */

/*! @name AIPS1_BRIDGE_GROUP1_MEM_RULE1 - AIPS1 Bridge Group 1 Memory Rule Register 1 */
/*! @{ */

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH7_MASK (0x3U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH7_SHIFT (0U)
/*! DMA_1_CH7 - DMA1 channel 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH7_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH7_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH8_MASK (0x30U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH8_SHIFT (4U)
/*! DMA_1_CH8 - DMA1 channel 8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH8_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH8_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH9_MASK (0x300U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH9_SHIFT (8U)
/*! DMA_1_CH9 - DMA1 channel 9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH9_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH9_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH10_MASK (0x3000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH10_SHIFT (12U)
/*! DMA_1_CH10 - DMA1 channel 10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH10_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH10_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH11_MASK (0x30000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH11_SHIFT (16U)
/*! DMA_1_CH11 - DMA1 channel 11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH11_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH11_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH12_MASK (0x300000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH12_SHIFT (20U)
/*! DMA_1_CH12 - DMA1 channel 12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH12_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH12_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH13_MASK (0x3000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH13_SHIFT (24U)
/*! DMA_1_CH13 - DMA1 channel 13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH13_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH13_MASK)

#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH14_MASK (0x30000000U)
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH14_SHIFT (28U)
/*! DMA_1_CH14 - DMA1 channel 14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH14_SHIFT)) & AHBSC0_AIPS1_BRIDGE_GROUP1_MEM_RULE1_DMA_1_CH14_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_RULE0 - AHB Secure Control Peripheral Rule 0 */
/*! @{ */

#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK (0x3U)
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK)

#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK (0x30U)
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK)

#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK (0x300U)
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK)

#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK (0x3000U)
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL2_SLAVE_RULE0 - AHB Peripheral 2 Slave Rule Register 0 */
/*! @{ */

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_DEBUG_MAILBOX_MASK (0x300U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT (8U)
/*! DEBUG_MAILBOX - sw debug mailbox
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_DEBUG_MAILBOX_MASK)

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM8_MASK (0x3000U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM8_SHIFT (12U)
/*! FLEXCOMM8 - FLEXCOMM8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM8_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM8_MASK)

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM9_MASK (0x30000U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM9_SHIFT (16U)
/*! FLEXCOMM9 - FLEXCOMM9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM9_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM9_MASK)

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM10_MASK (0x300000U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM10_SHIFT (20U)
/*! FLEXCOMM10 - FLEXCOMM10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM10_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM10_MASK)

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM11_MASK (0x3000000U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM11_SHIFT (24U)
/*! FLEXCOMM11 - FLEXCOMM11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM11_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM11_MASK)

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM12_MASK (0x30000000U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM12_SHIFT (28U)
/*! FLEXCOMM12 - FLEXCOMM12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM12_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE0_FLEXCOMM12_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL2_SLAVE_RULE1 - AHB Peripheral 2 Slave Rule Register 1 */
/*! @{ */

#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE1_FLEXCOMM13_MASK (0x3U)
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE1_FLEXCOMM13_SHIFT (0U)
/*! FLEXCOMM13 - FLEXCOMM13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE1_FLEXCOMM13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE1_FLEXCOMM13_SHIFT)) & AHBSC0_AHB_PERIPHERAL2_SLAVE_RULE1_FLEXCOMM13_MASK)
/*! @} */

/*! @name AIPS0_BRIDGE_GROUP0_MEM_RULE0 - AIPS0 Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI0_MASK (0x30000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI0_SHIFT (16U)
/*! XSPI0 - XSPI0 register
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI0_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI0_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI1_MASK (0x300000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI1_SHIFT (20U)
/*! XSPI1 - XSPI1 register
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI1_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_XSPI1_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_TRNG_MASK (0x30000000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_TRNG_SHIFT (28U)
/*! TRNG - TRNG
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_TRNG(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_TRNG_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE0_TRNG_MASK)
/*! @} */

/*! @name AIPS0_BRIDGE_GROUP0_MEM_RULE1 - AIPS0 Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_B_MASK (0x3U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_B_SHIFT (0U)
/*! MU4_B - MU4_B
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_B(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_B_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_B_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_A_MASK (0x30U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_A_SHIFT (4U)
/*! MU4_A - MU4_A
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_A_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_MU4_A_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_SEMA42_4_MASK (0x300U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_SEMA42_4_SHIFT (8U)
/*! SEMA42_4 - SEMA42_4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_SEMA42_4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_SEMA42_4_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_SEMA42_4_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON0_MASK (0x30000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON0_SHIFT (16U)
/*! CMX_PERFMON0 - CMX_PERFMON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON0_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON0_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON1_MASK (0x300000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON1_SHIFT (20U)
/*! CMX_PERFMON1 - CMX_PERFMON1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON1_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON1_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON2_MASK (0x3000000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON2_SHIFT (24U)
/*! CMX_PERFMON2 - CMX_PERFMON2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON2_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON2_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON3_MASK (0x30000000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON3_SHIFT (28U)
/*! CMX_PERFMON3 - CMX_PERFMON3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON3_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP0_MEM_RULE1_CMX_PERFMON3_MASK)
/*! @} */

/*! @name AIPS0_BRIDGE_GROUP1_MEM_RULE0 - AIPS0 Bridge Group 1 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_MASK (0x3U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_SHIFT (0U)
/*! ELS - ELS
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS1_MASK (0x30U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS1_SHIFT (4U)
/*! ELS_ALIAS1 - ELS_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS1_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS1_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS2_MASK (0x300U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS2_SHIFT (8U)
/*! ELS_ALIAS2 - ELS_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS2_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS2_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS3_MASK (0x3000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS3_SHIFT (12U)
/*! ELS_ALIAS3 - ELS_ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS3_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_ELS_ALIAS3_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_MASK (0x30000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_SHIFT (16U)
/*! PUF - PUF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS1_MASK (0x300000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS1_SHIFT (20U)
/*! PUF_ALIAS1 - PUF_ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS1_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS1_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS2_MASK (0x3000000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS2_SHIFT (24U)
/*! PUF_ALIAS2 - PUF_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS2_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS2_MASK)

#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS3_MASK (0x30000000U)
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS3_SHIFT (28U)
/*! PUF_ALIAS3 - PUF_ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS3_SHIFT)) & AHBSC0_AIPS0_BRIDGE_GROUP1_MEM_RULE0_PUF_ALIAS3_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP0_RULE0 - APB Bridge Peripheral 0 Rule 0 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_RSTCTL0_MASK (0x3U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_RSTCTL0_SHIFT (0U)
/*! RSTCTL0 - RSTCTL0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_RSTCTL0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_RSTCTL0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_RSTCTL0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_CLKCTL0_MASK (0x30U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_CLKCTL0_SHIFT (4U)
/*! CLKCTL0 - CLKCTL0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_CLKCTL0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_CLKCTL0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_CLKCTL0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SYSCON0_MASK (0x300U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SYSCON0_SHIFT (8U)
/*! SYSCON0 - SYSCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SYSCON0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_SYSCON0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_SYSCON0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SLEEPCON0_MASK (0x3000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SLEEPCON0_SHIFT (12U)
/*! SLEEPCON0 - SLEEPCON0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_SLEEPCON0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_SLEEPCON0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_SLEEPCON0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_IOCON0_MASK (0x30000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_IOCON0_SHIFT (16U)
/*! IOCON0 - IOCON0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_IOCON0(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_IOCON0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_IOCON0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE0_PVTS0_MASK (0x300000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_PVTS0_SHIFT (20U)
/*! PVTS0 - PVTS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE0_PVTS0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE0_PVTS0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE0_PVTS0_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP0_RULE1 - APB Bridge Peripheral 0 Rule Register 1 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP0_RULE1_WWDT0_MASK (0x3000000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE1_WWDT0_SHIFT (24U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE1_WWDT0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE1_WWDT0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE1_WWDT0_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE1_UTICK0_MASK (0x30000000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE1_UTICK0_SHIFT (28U)
/*! UTICK0 - UTICK0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE1_UTICK0(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE1_UTICK0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE1_UTICK0_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP0_RULE2 - APB Bridge Peripheral 0 Rule Register 2 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP0_RULE2_PKC_MASK   (0x30U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_PKC_SHIFT  (4U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_PKC(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE2_PKC_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE2_PKC_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE2_ITRC_MASK  (0x300U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_ITRC_SHIFT (8U)
/*! ITRC - ITRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_ITRC(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE2_ITRC_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE2_ITRC_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE2_GDET0_MASK (0x3000U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_GDET0_SHIFT (12U)
/*! GDET0 - GDET0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE2_GDET0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE2_GDET0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE2_GDET0_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP0_RULE3 - APB Bridge Peripheral 0 Rule Register 3 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP0_RULE3_OCOTP_MASK (0x3U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE3_OCOTP_SHIFT (0U)
/*! OCOTP - OCOTP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE3_OCOTP(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE3_OCOTP_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE3_OCOTP_MASK)

#define AHBSC0_APB_SLAVE_GROUP0_RULE3_SAFO_SGI_MASK (0x300U)
#define AHBSC0_APB_SLAVE_GROUP0_RULE3_SAFO_SGI_SHIFT (8U)
/*! SAFO_SGI - SAFO_SGI
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP0_RULE3_SAFO_SGI(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP0_RULE3_SAFO_SGI_SHIFT)) & AHBSC0_APB_SLAVE_GROUP0_RULE3_SAFO_SGI_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP1_RULE0 - APB Bridge Peripheral 1 Rule Register 0 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP1_RULE0_FREQME_MASK (0x3000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_FREQME_SHIFT (12U)
/*! FREQME - FREQME
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_FREQME(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE0_FREQME_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE0_FREQME_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE0_PINT0_MASK (0x300000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_PINT0_SHIFT (20U)
/*! PINT0 - PINT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_PINT0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE0_PINT0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE0_PINT0_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE0_INPUTMUX0_MASK (0x3000000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_INPUTMUX0_SHIFT (24U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE0_INPUTMUX0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE0_INPUTMUX0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE0_INPUTMUX0_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP1_RULE1 - APB Bridge Peripheral 1 Rule Register 1 */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER0_MASK (0x3U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER0_SHIFT (0U)
/*! CTIMER0 - CTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER0_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER1_MASK (0x30U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER1_SHIFT (4U)
/*! CTIMER1 - CTIMER1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER1_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER1_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER2_MASK (0x300U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER2_SHIFT (8U)
/*! CTIMER2 - CTIMER2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER2_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER2_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER3_MASK (0x3000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER3_SHIFT (12U)
/*! CTIMER3 - CTIMER3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER3_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER3_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER4_MASK (0x30000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER4_SHIFT (16U)
/*! CTIMER4 - CTIMER4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER4_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_CTIMER4_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_MRT0_MASK  (0x300000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_MRT0_SHIFT (20U)
/*! MRT0 - MRT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_MRT0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_MRT0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_MRT0_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE1_WWDT1_MASK (0x3000000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_WWDT1_SHIFT (24U)
/*! WWDT1 - WWDT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE1_WWDT1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE1_WWDT1_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE1_WWDT1_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP1_RULE2 - APB Bridge Peripheral 1 Rule 2 Register */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU0_MASK  (0x3U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU0_SHIFT (0U)
/*! MMU0 - MMU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU0_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU1_MASK  (0x30U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU1_SHIFT (4U)
/*! MMU1 - MMU1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU1_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_MMU1_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE0_MASK (0x3000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE0_SHIFT (12U)
/*! XCACHE0 - Cache Control 0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE0_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE1_MASK (0x30000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE1_SHIFT (16U)
/*! XCACHE1 - Cache Control 1 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE1_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE1_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE2_MASK (0x300000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE2_SHIFT (20U)
/*! XCACHE2 - Cache Control 2 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE2_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE2_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE3_MASK (0x3000000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE3_SHIFT (24U)
/*! XCACHE3 - Cache Control 3 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE3_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_XCACHE3_MASK)

#define AHBSC0_APB_SLAVE_GROUP1_RULE2_I3C0_MASK  (0x30000000U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_I3C0_SHIFT (28U)
/*! I3C0 - I3C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE2_I3C0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE2_I3C0_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE2_I3C0_MASK)
/*! @} */

/*! @name APB_SLAVE_GROUP1_RULE3 - APB Bridge Peripheral 1 Rule 3 Register */
/*! @{ */

#define AHBSC0_APB_SLAVE_GROUP1_RULE3_I3C1_MASK  (0x3U)
#define AHBSC0_APB_SLAVE_GROUP1_RULE3_I3C1_SHIFT (0U)
/*! I3C1 - I3C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_APB_SLAVE_GROUP1_RULE3_I3C1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_APB_SLAVE_GROUP1_RULE3_I3C1_SHIFT)) & AHBSC0_APB_SLAVE_GROUP1_RULE3_I3C1_MASK)
/*! @} */

/*! @name SHARED_APB_SLAVE_GROUP0_RULE0 - Shared APB Bridge Peripheral 0 Rule 0 */
/*! @{ */

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_MASK (0x3U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_SHIFT (0U)
/*! RSTCTL3 - RSTCTL3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL3_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_MASK (0x30U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_SHIFT (4U)
/*! CLKCTL3 - CLKCTL3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL3_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_MASK (0x300U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_SHIFT (8U)
/*! SYSCON3 - SYSCON3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON3_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_MASK (0x3000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_SHIFT (12U)
/*! OSC32KNP - OSC32KNP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_OSC32KNP_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_MASK (0x30000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_SHIFT (16U)
/*! IOPCTL1 - IOPCTL1 for sense domain
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_IOPCTL1_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_MASK (0x300000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_SHIFT (20U)
/*! CLKCTL2 - Clock for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_CLKCTL2_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_MASK (0x3000000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_SHIFT (24U)
/*! SYSCON2 - SYSCON2 for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_SYSCON2_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_MASK (0x30000000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_SHIFT (28U)
/*! RSTCTL2 - RSTCTL2 for common VDDN
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE0_RSTCTL2_MASK)
/*! @} */

/*! @name SHARED_APB_SLAVE_GROUP0_RULE1 - Shared APB Bridge Peripheral 0 Rule 1 */
/*! @{ */

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC0_MASK (0x3U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC0_SHIFT (0U)
/*! RTC0 - RTC0 (compute domain)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC0_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC0_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC1_MASK (0x30U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC1_SHIFT (4U)
/*! RTC1 - RTC1 (sense domain)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC1_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_RTC1_MASK)

#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_MASK (0x3000U)
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_SHIFT (12U)
/*! GDET3 - GDET3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_SHIFT)) & AHBSC0_SHARED_APB_SLAVE_GROUP0_RULE1_GDET3_MASK)
/*! @} */

/*! @name AIPS2_BRIDGE_GROUP0_MEM_RULE0 - AIPS2 Bridge Group 0 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_A_MASK (0x3U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_A_SHIFT (0U)
/*! MU0_A - MU0_A (M33 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_A_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU0_A_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_A_MASK (0x300U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_A_SHIFT (8U)
/*! MU1_A - MU1_A (M33 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_A_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU1_A_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_A_MASK (0x30000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_A_SHIFT (16U)
/*! MU2_A - MU2_A (HIFI4 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_A(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_A_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_MU2_A_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEMA42_0_MASK (0x3000000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEMA42_0_SHIFT (24U)
/*! SEMA42_0 - SEMA42_0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEMA42_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEMA42_0_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_SEMA42_0_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_OSTIMER_MASK (0x30000000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_OSTIMER_SHIFT (28U)
/*! OSTIMER - OSTIMER (M33 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_OSTIMER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_OSTIMER_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE0_OSTIMER_MASK)
/*! @} */

/*! @name AIPS2_BRIDGE_GROUP0_MEM_RULE1 - AIPS2 Bridge Group 0 Memory Rule Register 1 */
/*! @{ */

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS1_MASK (0x3U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS1_SHIFT (0U)
/*! OSTIMER_ALIAS1 - OSTIMER ALIAS1 (HIFI4 port)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS1_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_OSTIMER_ALIAS1_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_MASK (0x3000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_SHIFT (12U)
/*! ACMP0 - ACMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ACMP0_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_MASK (0x30000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_SHIFT (16U)
/*! ADC0 - ADC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_ADC0_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_MASK (0x300000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_SHIFT (20U)
/*! SDADC - SDADC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_SDADC_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_MASK (0x3000000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_SHIFT (24U)
/*! MICFIL - MICFIL
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_MICFIL_MASK)

#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_PMC0_MASK (0x30000000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_PMC0_SHIFT (28U)
/*! PMC0 - PMC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_PMC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_PMC0_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP0_MEM_RULE1_PMC0_MASK)
/*! @} */

/*! @name AIPS2_BRIDGE_GROUP1_MEM_RULE0 - AIPS2 Bridge Group 1 Memory Rule Register 0 */
/*! @{ */

#define AHBSC0_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_MASK (0x3000U)
#define AHBSC0_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_SHIFT (12U)
/*! LPI2C15 - LPI2C15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_SHIFT)) & AHBSC0_AIPS2_BRIDGE_GROUP1_MEM_RULE0_LPI2C15_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_SENSE_RULE0 - Sense Domain AHB Secure Control Peripheral Rule 0 */
/*! @{ */

#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE0_MASK (0x3U)
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE0_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE0_MASK)

#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE1_MASK (0x30U)
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE1_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE1_MASK)

#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE2_MASK (0x300U)
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE2_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE2_MASK)

#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE3_MASK (0x3000U)
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE3_SHIFT)) & AHBSC0_AHB_SECURE_CTRL_SENSE_RULE0_RULE3_MASK)
/*! @} */

/*! @name MEDIA_AHB_PERIPHERAL_SLAVE_RULE0 - MEDIA domain AHB peripheral slave */
/*! @{ */

#define AHBSC0_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_MASK (0x3U)
#define AHBSC0_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_SHIFT (0U)
/*! MEDIA_AHB_PERIPHERAL - MEDIA domain AHB Peripheral Slave Rule Register
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_SHIFT)) & AHBSC0_MEDIA_AHB_PERIPHERAL_SLAVE_RULE0_MEDIA_AHB_PERIPHERAL_MASK)
/*! @} */

/*! @name MEDIA_APB_PERIPHERAL_SLAVE_RULE0 - MEDIA domain APB peripheral slave Rule Register */
/*! @{ */

#define AHBSC0_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_MASK (0x3U)
#define AHBSC0_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_SHIFT (0U)
/*! MEDIA_APB_PERIPHERAL - MEDIA domain APB Peripheral Slave
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_SHIFT)) & AHBSC0_MEDIA_APB_PERIPHERAL_SLAVE_RULE0_MEDIA_APB_PERIPHERAL_MASK)
/*! @} */

/*! @name EZHV_SRAM_RULE0 - EZHV SRAM Memory Rule Register */
/*! @{ */

#define AHBSC0_EZHV_SRAM_RULE0_EZHV_SRAM_MASK    (0x3U)
#define AHBSC0_EZHV_SRAM_RULE0_EZHV_SRAM_SHIFT   (0U)
/*! EZHV_SRAM - EZHV SRAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC0_EZHV_SRAM_RULE0_EZHV_SRAM(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC0_EZHV_SRAM_RULE0_EZHV_SRAM_SHIFT)) & AHBSC0_EZHV_SRAM_RULE0_EZHV_SRAM_MASK)
/*! @} */

/*! @name SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC0_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK    (0xFFFFFFFFU)
#define AHBSC0_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT   (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC0_SEC_VIO_ADDR_SEC_VIO_ADDR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC0_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC0_SEC_VIO_ADDR */
#define AHBSC0_SEC_VIO_ADDR_COUNT                (29U)

/*! @name SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0x1F00U)
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
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
 *  0b11111..Test port
 */
#define AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC0_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC0_SEC_VIO_MISC_INFO */
#define AHBSC0_SEC_VIO_MISC_INFO_COUNT           (29U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - Violation information valid flag for AHB port 13
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - Violation information valid flag for AHB port 14
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - Violation information valid flag for AHB port 15
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - Violation information valid flag for AHB port 16
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK (0x20000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT (17U)
/*! VIO_INFO_VALID17 - Violation information valid flag for AHB port 17
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID17(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK (0x40000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT (18U)
/*! VIO_INFO_VALID18 - Violation information valid flag for AHB port 18
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID18(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID19_MASK (0x80000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID19_SHIFT (19U)
/*! VIO_INFO_VALID19 - Violation information valid flag for AHB port 19
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID19(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID19_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID19_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID20_MASK (0x100000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID20_SHIFT (20U)
/*! VIO_INFO_VALID20 - Violation information valid flag for AHB port 20
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID20(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID20_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID20_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID21_MASK (0x200000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID21_SHIFT (21U)
/*! VIO_INFO_VALID21 - Violation information valid flag for AHB port 21
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID21(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID21_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID21_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID22_MASK (0x400000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID22_SHIFT (22U)
/*! VIO_INFO_VALID22 - Violation information valid flag for AHB port 22
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID22(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID22_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID22_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID23_MASK (0x800000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID23_SHIFT (23U)
/*! VIO_INFO_VALID23 - Violation information valid flag for AHB port 23
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID23(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID23_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID23_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID24_MASK (0x1000000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID24_SHIFT (24U)
/*! VIO_INFO_VALID24 - Violation information valid flag for AHB port 24
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID24(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID24_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID24_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID25_MASK (0x2000000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID25_SHIFT (25U)
/*! VIO_INFO_VALID25 - Violation information valid flag for AHB port 25
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID25(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID25_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID25_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID26_MASK (0x4000000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID26_SHIFT (26U)
/*! VIO_INFO_VALID26 - Violation information valid flag for AHB port 26
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID26(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID26_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID26_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID27_MASK (0x8000000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID27_SHIFT (27U)
/*! VIO_INFO_VALID27 - Violation information valid flag for AHB port 27
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID27(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID27_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID27_MASK)

#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID28_MASK (0x10000000U)
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID28_SHIFT (28U)
/*! VIO_INFO_VALID28 - Violation information valid flag for AHB port 28
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID28(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID28_SHIFT)) & AHBSC0_SEC_VIO_INFO_VALID_VIO_INFO_VALID28_MASK)
/*! @} */

/*! @name COMPUTE_ARB0RAM_ACCESS_ENABLE - Access enable for COMPUTE domain masters to RAM partitions. */
/*! @{ */

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK (0x1000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT (12U)
/*! RAM_PARTITION_12_ACCESS_EN - Enable access to the Shared RAM partition 12
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK (0x2000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT (13U)
/*! RAM_PARTITION_13_ACCESS_EN - Enable access to the Shared RAM partition 13
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK (0x4000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT (14U)
/*! RAM_PARTITION_14_ACCESS_EN - Enable access to the Shared RAM partition 14
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK (0x8000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT (15U)
/*! RAM_PARTITION_15_ACCESS_EN - Enable access to the Shared RAM partition 15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK (0x10000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT (16U)
/*! RAM_PARTITION_16_ACCESS_EN - Enable access to the Shared RAM partition 16
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK)

#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK (0x20000U)
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT (17U)
/*! RAM_PARTITION_17_ACCESS_EN - Enable access to the Shared RAM partition 17
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT)) & AHBSC0_COMPUTE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK)
/*! @} */

/*! @name SENSE_ARB0RAM_ACCESS_ENABLE - Access enable for SENSE domain masters to RAM partitions. */
/*! @{ */

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK (0x1000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT (12U)
/*! RAM_PARTITION_12_ACCESS_EN - Enable access to the Shared RAM partition 12
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK (0x2000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT (13U)
/*! RAM_PARTITION_13_ACCESS_EN - Enable access to the Shared RAM partition 13
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK (0x4000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT (14U)
/*! RAM_PARTITION_14_ACCESS_EN - Enable access to the Shared RAM partition 14
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK (0x8000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT (15U)
/*! RAM_PARTITION_15_ACCESS_EN - Enable access to the Shared RAM partition 15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK (0x10000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT (16U)
/*! RAM_PARTITION_16_ACCESS_EN - Enable access to the Shared RAM partition 16
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK)

#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK (0x20000U)
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT (17U)
/*! RAM_PARTITION_17_ACCESS_EN - Enable access to the Shared RAM partition 17
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT)) & AHBSC0_SENSE_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK)
/*! @} */

/*! @name MEDIA_ARB0RAM_ACCESS_ENABLE - Access enable for MEDIA domain masters to RAM partitions. */
/*! @{ */

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK (0x1000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT (12U)
/*! RAM_PARTITION_12_ACCESS_EN - Enable access to the Shared RAM partition 12
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK (0x2000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT (13U)
/*! RAM_PARTITION_13_ACCESS_EN - Enable access to the Shared RAM partition 13
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK (0x4000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT (14U)
/*! RAM_PARTITION_14_ACCESS_EN - Enable access to the Shared RAM partition 14
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK (0x8000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT (15U)
/*! RAM_PARTITION_15_ACCESS_EN - Enable access to the Shared RAM partition 15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK (0x10000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT (16U)
/*! RAM_PARTITION_16_ACCESS_EN - Enable access to the Shared RAM partition 16
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK)

#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK (0x20000U)
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT (17U)
/*! RAM_PARTITION_17_ACCESS_EN - Enable access to the Shared RAM partition 17
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT)) & AHBSC0_MEDIA_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK)
/*! @} */

/*! @name NPU_ARB0RAM_ACCESS_ENABLE - Access enable for NPU domain masters to RAM partitions. */
/*! @{ */

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK (0x1000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT (12U)
/*! RAM_PARTITION_12_ACCESS_EN - Enable access to the Shared RAM partition 12
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK (0x2000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT (13U)
/*! RAM_PARTITION_13_ACCESS_EN - Enable access to the Shared RAM partition 13
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK (0x4000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT (14U)
/*! RAM_PARTITION_14_ACCESS_EN - Enable access to the Shared RAM partition 14
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK (0x8000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT (15U)
/*! RAM_PARTITION_15_ACCESS_EN - Enable access to the Shared RAM partition 15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK (0x10000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT (16U)
/*! RAM_PARTITION_16_ACCESS_EN - Enable access to the Shared RAM partition 16
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK)

#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK (0x20000U)
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT (17U)
/*! RAM_PARTITION_17_ACCESS_EN - Enable access to the Shared RAM partition 17
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT)) & AHBSC0_NPU_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK)
/*! @} */

/*! @name HIFI4_ARB0RAM_ACCESS_ENABLE - Access enable for HIFI4 to RAM partitions. */
/*! @{ */

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK (0x1U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT (0U)
/*! RAM_PARTITION_0_ACCESS_EN - Enable access to the Shared RAM partition 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_0_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK (0x2U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT (1U)
/*! RAM_PARTITION_1_ACCESS_EN - Enable access to the Shared RAM partition 1
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_1_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK (0x4U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT (2U)
/*! RAM_PARTITION_2_ACCESS_EN - Enable access to the Shared RAM partition 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_2_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK (0x8U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT (3U)
/*! RAM_PARTITION_3_ACCESS_EN - Enable access to the Shared RAM partition 3
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_3_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK (0x10U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT (4U)
/*! RAM_PARTITION_4_ACCESS_EN - Enable access to the Shared RAM partition 4
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_4_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK (0x20U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT (5U)
/*! RAM_PARTITION_5_ACCESS_EN - Enable access to the Shared RAM partition 5
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_5_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK (0x40U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT (6U)
/*! RAM_PARTITION_6_ACCESS_EN - Enable access to the Shared RAM partition 6
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_6_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK (0x80U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT (7U)
/*! RAM_PARTITION_7_ACCESS_EN - Enable access to the Shared RAM partition 7
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_7_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK (0x100U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT (8U)
/*! RAM_PARTITION_8_ACCESS_EN - Enable access to the Shared RAM partition 8
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_8_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK (0x200U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT (9U)
/*! RAM_PARTITION_9_ACCESS_EN - Enable access to the Shared RAM partition 9
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_9_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK (0x400U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT (10U)
/*! RAM_PARTITION_10_ACCESS_EN - Enable access to the Shared RAM partition 10
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_10_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK (0x800U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT (11U)
/*! RAM_PARTITION_11_ACCESS_EN - Enable access to the Shared RAM partition 11
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_11_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK (0x1000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT (12U)
/*! RAM_PARTITION_12_ACCESS_EN - Enable access to the Shared RAM partition 12
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_12_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK (0x2000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT (13U)
/*! RAM_PARTITION_13_ACCESS_EN - Enable access to the Shared RAM partition 13
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_13_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK (0x4000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT (14U)
/*! RAM_PARTITION_14_ACCESS_EN - Enable access to the Shared RAM partition 14
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_14_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK (0x8000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT (15U)
/*! RAM_PARTITION_15_ACCESS_EN - Enable access to the Shared RAM partition 15
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_15_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK (0x10000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT (16U)
/*! RAM_PARTITION_16_ACCESS_EN - Enable access to the Shared RAM partition 16
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_16_ACCESS_EN_MASK)

#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK (0x20000U)
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT (17U)
/*! RAM_PARTITION_17_ACCESS_EN - Enable access to the Shared RAM partition 17
 *  0b0..Disable
 *  0b1..Enable
 */
#define AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_SHIFT)) & AHBSC0_HIFI4_ARB0RAM_ACCESS_ENABLE_RAM_PARTITION_17_ACCESS_EN_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC0_MASTER_SEC_LEVEL_HIFI4_MASK       (0x3U)
#define AHBSC0_MASTER_SEC_LEVEL_HIFI4_SHIFT      (0U)
/*! HIFI4 - HIFI4
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_HIFI4(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_HIFI4_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_HIFI4_MASK)

#define AHBSC0_MASTER_SEC_LEVEL_MEDIA_MASK       (0xCU)
#define AHBSC0_MASTER_SEC_LEVEL_MEDIA_SHIFT      (2U)
/*! MEDIA - MEDIA
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_MEDIA(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_MEDIA_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_MEDIA_MASK)

#define AHBSC0_MASTER_SEC_LEVEL_DMA0_MASK        (0x30U)
#define AHBSC0_MASTER_SEC_LEVEL_DMA0_SHIFT       (4U)
/*! DMA0 - DMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_DMA0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_DMA0_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_DMA0_MASK)

#define AHBSC0_MASTER_SEC_LEVEL_DMA1_MASK        (0xC0U)
#define AHBSC0_MASTER_SEC_LEVEL_DMA1_SHIFT       (6U)
/*! DMA1 - DMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_DMA1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_DMA1_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_DMA1_MASK)

#define AHBSC0_MASTER_SEC_LEVEL_PKC_MASK         (0x300U)
#define AHBSC0_MASTER_SEC_LEVEL_PKC_SHIFT        (8U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_PKC(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_PKC_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_PKC_MASK)

#define AHBSC0_MASTER_SEC_LEVEL_ETR_MASK         (0xC00U)
#define AHBSC0_MASTER_SEC_LEVEL_ETR_SHIFT        (10U)
/*! ETR - ETR
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC0_MASTER_SEC_LEVEL_ETR(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_LEVEL_ETR_SHIFT)) & AHBSC0_MASTER_SEC_LEVEL_ETR_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_HIFI4_MASK (0x3U)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_HIFI4_SHIFT (0U)
/*! HIFI4 - HIFI4
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_HIFI4(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_HIFI4_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_HIFI4_MASK)

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_MEDIA_MASK (0xCU)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_MEDIA_SHIFT (2U)
/*! MEDIA - MEDIA
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_MEDIA(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_MEDIA_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_MEDIA_MASK)

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA0_MASK (0x30U)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT (4U)
/*! DMA0 - DMA0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA0(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA0_MASK)

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA1_MASK (0xC0U)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT (6U)
/*! DMA1 - DMA1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA1(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_DMA1_MASK)

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_PKC_MASK  (0x300U)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT (8U)
/*! PKC - PKC
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_PKC(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_PKC_MASK)

#define AHBSC0_MASTER_SEC_ANTI_POL_REG_ETR_MASK  (0xC00U)
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_ETR_SHIFT (10U)
/*! ETR - ETR
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC0_MASTER_SEC_ANTI_POL_REG_ETR(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_MASTER_SEC_ANTI_POL_REG_ETR_SHIFT)) & AHBSC0_MASTER_SEC_ANTI_POL_REG_ETR_MASK)
/*! @} */

/*! @name CPU0_LOCK_REG - Miscellaneous CPU0 Control Signals */
/*! @{ */

#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK   (0x3U)
#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT  (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU0) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_VTOR(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC0_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHBSC0_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_MPU_MASK    (0xCU)
#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT   (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC0_CPU0_LOCK_REG_LOCK_NS_MPU(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC0_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHBSC0_CPU0_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHBSC0_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK (0x30U)
#define AHBSC0_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT (4U)
/*! LOCK_S_VTAIRCR - LOCK_S_VTAIRCR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_VTAIRCR is 1
 *  0b10..CM33 (CPU0) LOCK_S_VTAIRCR is 0
 *  0b11..Reserved
 */
#define AHBSC0_CPU0_LOCK_REG_LOCK_S_VTAIRCR(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT)) & AHBSC0_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK)

#define AHBSC0_CPU0_LOCK_REG_LOCK_S_MPU_MASK     (0xC0U)
#define AHBSC0_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT    (6U)
/*! LOCK_S_MPU - LOCK_S_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_S_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC0_CPU0_LOCK_REG_LOCK_S_MPU(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC0_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHBSC0_CPU0_LOCK_REG_LOCK_S_MPU_MASK)

#define AHBSC0_CPU0_LOCK_REG_LOCK_SAU_MASK       (0x300U)
#define AHBSC0_CPU0_LOCK_REG_LOCK_SAU_SHIFT      (8U)
/*! LOCK_SAU - LOCK_SAU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_SAU is 1
 *  0b10..CM33 (CPU0) LOCK_SAU is 0
 *  0b11..Reserved
 */
#define AHBSC0_CPU0_LOCK_REG_LOCK_SAU(x)         (((uint32_t)(((uint32_t)(x)) << AHBSC0_CPU0_LOCK_REG_LOCK_SAU_SHIFT)) & AHBSC0_CPU0_LOCK_REG_LOCK_SAU_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define AHBSC0_MISC_CTRL_DP_REG_WRITE_LOCK_MASK  (0x3U)
#define AHBSC0_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_WRITE_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC0_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC0_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHBSC0_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)   (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHBSC0_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define AHBSC0_MISC_CTRL_REG_WRITE_LOCK_MASK     (0x3U)
#define AHBSC0_MISC_CTRL_REG_WRITE_LOCK_SHIFT    (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_WRITE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHBSC0_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHBSC0_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC0_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC0_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC0_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC0_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC0_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC0_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC0_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC0_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC0_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC0_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC0_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC0_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC0_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define AHBSC0_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC0_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC0_MISC_CTRL_REG_IDAU_ALL_NS_MASK    (0xC000U)
#define AHBSC0_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT   (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC0_MISC_CTRL_REG_IDAU_ALL_NS(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC0_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHBSC0_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBSC0_Register_Masks */


/*!
 * @}
 */ /* end of group AHBSC0_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBSC0_H_ */

