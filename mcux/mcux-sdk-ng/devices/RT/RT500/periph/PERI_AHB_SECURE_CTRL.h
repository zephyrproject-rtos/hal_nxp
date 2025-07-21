/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHB_SECURE_CTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AHB_SECURE_CTRL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHB_SECURE_CTRL
 *
 * CMSIS Peripheral Access Layer for AHB_SECURE_CTRL
 */

#if !defined(PERI_AHB_SECURE_CTRL_H_)
#define PERI_AHB_SECURE_CTRL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- AHB_SECURE_CTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_SECURE_CTRL_Peripheral_Access_Layer AHB_SECURE_CTRL Peripheral Access Layer
 * @{
 */

/** AHB_SECURE_CTRL - Size of Registers Arrays */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_COUNT        4u
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_COUNT 4u
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_COUNT 4u
#define AHB_SECURE_CTRL_RAM00_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM01_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM02_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM03_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM04_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM05_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM06_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM07_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM08_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM09_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM10_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM11_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM12_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM13_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM14_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM15_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM16_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM17_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM18_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM19_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM20_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM21_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM22_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM23_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM24_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM25_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM26_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM27_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM28_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM29_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM30_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_RAM31_RULEN_COUNT         4u
#define AHB_SECURE_CTRL_SDMA_RAM_RULEN_COUNT      4u
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULEN_COUNT 4u
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_COUNT 4u
#define AHB_SECURE_CTRL_SEC_VIO_ADDRN_COUNT       18u
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFON_COUNT  18u

/** AHB_SECURE_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ROM_MEM_RULE[AHB_SECURE_CTRL_ROM_MEM_RULE_COUNT]; /**< Memory ROM Rule(n) Register, array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t FLEXSPI0_REGION0_RULE[AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_COUNT]; /**< FLEXSPI0 Region 0 Rule(n) Register, array offset: 0x30, array step: 0x4 */
  struct {                                         /* offset: 0x40, array step: 0x10 */
    __IO uint32_t FLEXSPI0_REGION_RULE0;             /**< FLEXSPI0 Region 1 Rule 0 Register..FLEXSPI0 Region 4 Rule 0 Register, array offset: 0x40, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI0_REGION1_4_RULE[AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_COUNT];
       uint8_t RESERVED_2[16];
  __IO uint32_t RAM00_RULE[AHB_SECURE_CTRL_RAM00_RULEN_COUNT]; /**< SRAM Partition 00 Rule(n) Register, array offset: 0x90, array step: 0x4 */
  __IO uint32_t RAM01_RULE[AHB_SECURE_CTRL_RAM01_RULEN_COUNT]; /**< SRAM Partition 01 Rule(n) Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t RAM02_RULE[AHB_SECURE_CTRL_RAM02_RULEN_COUNT]; /**< SRAM Partition 02 Rule(n) Register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t RAM03_RULE[AHB_SECURE_CTRL_RAM03_RULEN_COUNT]; /**< SRAM Partition 03 Rule(n) Register, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_4[16];
  __IO uint32_t RAM04_RULE[AHB_SECURE_CTRL_RAM04_RULEN_COUNT]; /**< SRAM Partition 04 Rule(n) Register, array offset: 0xF0, array step: 0x4 */
  __IO uint32_t RAM05_RULE[AHB_SECURE_CTRL_RAM05_RULEN_COUNT]; /**< SRAM Partition 05 Rule(n) Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t RAM06_RULE[AHB_SECURE_CTRL_RAM06_RULEN_COUNT]; /**< SRAM Partition 06 Rule(n) Register, array offset: 0x110, array step: 0x4 */
  __IO uint32_t RAM07_RULE[AHB_SECURE_CTRL_RAM07_RULEN_COUNT]; /**< SRAM Partition 07 Rule(n) Register, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t RAM08_RULE[AHB_SECURE_CTRL_RAM08_RULEN_COUNT]; /**< SRAM Partition 08 Rule(n) Register, array offset: 0x140, array step: 0x4 */
  __IO uint32_t RAM09_RULE[AHB_SECURE_CTRL_RAM09_RULEN_COUNT]; /**< SRAM Partition 09 Rule(n) Register, array offset: 0x150, array step: 0x4 */
  __IO uint32_t RAM10_RULE[AHB_SECURE_CTRL_RAM10_RULEN_COUNT]; /**< SRAM Partition 10 Rule(n) Register, array offset: 0x160, array step: 0x4 */
  __IO uint32_t RAM11_RULE[AHB_SECURE_CTRL_RAM11_RULEN_COUNT]; /**< SRAM Partition 11 Rule(n) Register, array offset: 0x170, array step: 0x4 */
       uint8_t RESERVED_6[16];
  __IO uint32_t RAM12_RULE[AHB_SECURE_CTRL_RAM12_RULEN_COUNT]; /**< SRAM Partition 12 Rule(n) Register, array offset: 0x190, array step: 0x4 */
  __IO uint32_t RAM13_RULE[AHB_SECURE_CTRL_RAM13_RULEN_COUNT]; /**< SRAM Partition 13 Rule(n) Register, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t RAM14_RULE[AHB_SECURE_CTRL_RAM14_RULEN_COUNT]; /**< SRAM Partition 14 Rule(n) Register, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t RAM15_RULE[AHB_SECURE_CTRL_RAM15_RULEN_COUNT]; /**< SRAM Partition 15 Rule(n) Register, array offset: 0x1C0, array step: 0x4 */
       uint8_t RESERVED_7[16];
  __IO uint32_t RAM16_RULE[AHB_SECURE_CTRL_RAM16_RULEN_COUNT]; /**< SRAM Partition 16 Rule(n) Register, array offset: 0x1E0, array step: 0x4 */
  __IO uint32_t RAM17_RULE[AHB_SECURE_CTRL_RAM17_RULEN_COUNT]; /**< SRAM Partition 17 Rule(n) Register, array offset: 0x1F0, array step: 0x4 */
  __IO uint32_t RAM18_RULE[AHB_SECURE_CTRL_RAM18_RULEN_COUNT]; /**< SRAM Partition 18 Rule(n) Register, array offset: 0x200, array step: 0x4 */
  __IO uint32_t RAM19_RULE[AHB_SECURE_CTRL_RAM19_RULEN_COUNT]; /**< SRAM Partition 19 Rule(n) Register, array offset: 0x210, array step: 0x4 */
       uint8_t RESERVED_8[16];
  __IO uint32_t RAM20_RULE[AHB_SECURE_CTRL_RAM20_RULEN_COUNT]; /**< SRAM Partition 20 Rule(n) Register, array offset: 0x230, array step: 0x4 */
  __IO uint32_t RAM21_RULE[AHB_SECURE_CTRL_RAM21_RULEN_COUNT]; /**< SRAM Partition 21 Rule(n) Register, array offset: 0x240, array step: 0x4 */
  __IO uint32_t RAM22_RULE[AHB_SECURE_CTRL_RAM22_RULEN_COUNT]; /**< SRAM Partition 22 Rule(n) Register, array offset: 0x250, array step: 0x4 */
  __IO uint32_t RAM23_RULE[AHB_SECURE_CTRL_RAM23_RULEN_COUNT]; /**< SRAM Partition 23 Rule(n) Register, array offset: 0x260, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t RAM24_RULE[AHB_SECURE_CTRL_RAM24_RULEN_COUNT]; /**< SRAM Partition 24 Rule(n) Register, array offset: 0x280, array step: 0x4 */
  __IO uint32_t RAM25_RULE[AHB_SECURE_CTRL_RAM25_RULEN_COUNT]; /**< SRAM Partition 25 Rule(n) Register, array offset: 0x290, array step: 0x4 */
  __IO uint32_t RAM26_RULE[AHB_SECURE_CTRL_RAM26_RULEN_COUNT]; /**< SRAM Partition 26 Rule(n) Register, array offset: 0x2A0, array step: 0x4 */
  __IO uint32_t RAM27_RULE[AHB_SECURE_CTRL_RAM27_RULEN_COUNT]; /**< SRAM Partition 27 Rule(n) Register, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t RAM28_RULE[AHB_SECURE_CTRL_RAM28_RULEN_COUNT]; /**< SRAM Partition 28 Rule(n) Register, array offset: 0x2D0, array step: 0x4 */
  __IO uint32_t RAM29_RULE[AHB_SECURE_CTRL_RAM29_RULEN_COUNT]; /**< SRAM Partition 29 Rule(n) Register, array offset: 0x2E0, array step: 0x4 */
  __IO uint32_t RAM30_RULE[AHB_SECURE_CTRL_RAM30_RULEN_COUNT]; /**< SRAM Partition 30 Rule(n) Register, array offset: 0x2F0, array step: 0x4 */
  __IO uint32_t RAM31_RULE[AHB_SECURE_CTRL_RAM31_RULEN_COUNT]; /**< SRAM Partition 31 Rule(n) Register, array offset: 0x300, array step: 0x4 */
       uint8_t RESERVED_11[16];
  __IO uint32_t SDMA_RAM_RULE[AHB_SECURE_CTRL_SDMA_RAM_RULEN_COUNT]; /**< Smart DMA (SDMA) RAM Rule(n) Register, array offset: 0x320, array step: 0x4 */
       uint8_t RESERVED_12[16];
  __IO uint32_t FLEXSPI1_REGION0_RULE[AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULEN_COUNT]; /**< FlexSPI1 Region 0 Rule(n) Register, array offset: 0x340, array step: 0x4 */
  struct {                                         /* offset: 0x350, array step: 0x10 */
    __IO uint32_t FLEXSPI1_REGION_RULE0;             /**< FlexSPI1 Region 1 Rule 0 Register..FlexSPI1 Region 4 Rule 0 Register, array offset: 0x350, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI1_REGIONN_RULE0[AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_COUNT];
       uint8_t RESERVED_13[16];
  __IO uint32_t APB_BRIDGE_PER0_RULE0;             /**< APB Bridge Peripheral 0 Rule 0 Register, offset: 0x3A0 */
  __IO uint32_t APB_BRIDGE_PER0_RULE1;             /**< APB Bridge Peripheral 0 Rule 1 Register, offset: 0x3A4 */
       uint8_t RESERVED_14[4];
  __IO uint32_t APB_BRIDGE_PER0_RULE3;             /**< APB Bridge Peripheral 0 Rule 3 Register, offset: 0x3AC */
  __IO uint32_t APB_BRIDGE_PER1_RULE0;             /**< APB Bridge Peripheral 1 Rule 0 Register, offset: 0x3B0 */
  __IO uint32_t APB_BRIDGE_PER1_RULE1;             /**< APB Bridge Peripheral 1 Rule 1 Register, offset: 0x3B4 */
  __IO uint32_t APB_BRIDGE_PER1_RULE2;             /**< APB Bridge Peripheral 1 Rule 2 Register, offset: 0x3B8 */
  __IO uint32_t APB_BRIDGE_PER1_RULE3;             /**< APB Bridge Peripheral 1 Rule 3 Register, offset: 0x3BC */
  __IO uint32_t AHB_PERIPH0_SLAVE_RULE0;           /**< AHB Peripheral 0 Slave Rule 0 Register, offset: 0x3C0 */
       uint8_t RESERVED_15[12];
  __IO uint32_t AIPS_BRIDGE0_PER_RULE0;            /**< AIPS Bridge Peripheral 0 Rule 0 Register, offset: 0x3D0 */
       uint8_t RESERVED_16[12];
  __IO uint32_t AHB_PERIPH1_SLAVE_RULE0;           /**< AHB Peripheral 1 Slave Rule 0 Register, offset: 0x3E0 */
  __IO uint32_t AHB_PERIPH1_SLAVE_RULE1;           /**< AHB Peripheral 1 Slave Rule 1 Register, offset: 0x3E4 */
       uint8_t RESERVED_17[24];
  __IO uint32_t AIPS_BRIDGE1_PER_RULE0;            /**< AIPS Bridge Peripheral 1 Rule 0 Register, offset: 0x400 */
  __IO uint32_t AIPS_BRIDGE1_PER_RULE1;            /**< AIPS Bridge Peripheral 1 Rule 1 Register, offset: 0x404 */
       uint8_t RESERVED_18[8];
  __IO uint32_t AHB_PERIPH2_SLAVE_RULE0;           /**< AHB Peripheral 2 Slave Rule 0 Register, offset: 0x410 */
       uint8_t RESERVED_19[12];
  __IO uint32_t AHB_SECURE_CTRL_PERIPH_RULE0;      /**< AHB Secure Control Peripheral Rule 0 Register, offset: 0x420 */
       uint8_t RESERVED_20[12];
  __IO uint32_t AHB_PERIPH3_SLAVE_RULE0;           /**< AHB Peripheral 3 Slave Rule 0 Register, offset: 0x430 */
  __IO uint32_t AHB_PERIPH3_SLAVE_RULE1;           /**< AHB Peripheral 3 Slave Rule 1 Register, offset: 0x434 */
       uint8_t RESERVED_21[2504];
  __I  uint32_t SEC_VIO_ADDR[AHB_SECURE_CTRL_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address(n) Register, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_22[56];
  __I  uint32_t SEC_VIO_MISC_INFO[AHB_SECURE_CTRL_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address(n) Register, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_23[56];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address(n) Register, offset: 0xF00 */
       uint8_t RESERVED_24[124];
  __IO uint32_t SEC_GPIO_MASK0;                    /**< GPIO Mask for Port 0 Register, offset: 0xF80 */
  __IO uint32_t SEC_GPIO_MASK1;                    /**< GPIO Mask for Port 1 Register, offset: 0xF84 */
  __IO uint32_t SEC_GPIO_MASK2;                    /**< GPIO Mask for Port 2 Register, offset: 0xF88 */
       uint8_t RESERVED_25[20];
  __IO uint32_t DSP_INT_MASK0;                     /**< Secure Interrupt Mask for DSP Register, offset: 0xFA0 */
       uint8_t RESERVED_26[24];
  __IO uint32_t SEC_MASK_LOCK;                     /**< Secure Mask Lock Register, offset: 0xFBC */
       uint8_t RESERVED_27[16];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level Register, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level Register, offset: 0xFD4 */
       uint8_t RESERVED_28[20];
  __IO uint32_t CM33_LOCK_REG;                     /**< Miscellaneous CPU0 Control Signals Register, offset: 0xFEC */
       uint8_t RESERVED_29[8];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate Register, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control Register, offset: 0xFFC */
} AHB_SECURE_CTRL_Type;

/* ----------------------------------------------------------------------------
   -- AHB_SECURE_CTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_SECURE_CTRL_Register_Masks AHB_SECURE_CTRL Register Masks
 * @{
 */

/*! @name ROM_MEM_RULE - Memory ROM Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE0_MASK  (0x3U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE0(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE1_MASK  (0x30U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE1(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE2_MASK  (0x300U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE2(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE3_MASK  (0x3000U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE3(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE4_MASK  (0x30000U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE4(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE5_MASK  (0x300000U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE5(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE6_MASK  (0x3000000U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE6(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE7_MASK  (0x30000000U)
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_ROM_MEM_RULE_RULE7(x)    (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_ROM_MEM_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_ROM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION0_RULE - FLEXSPI0 Region 0 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE4_MASK (0x30000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE5_MASK (0x300000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE6_MASK (0x3000000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE7_MASK (0x30000000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_RULE7_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0 - FLEXSPI0 Region 1 Rule 0 Register..FLEXSPI0 Region 4 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_RULE3_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_4_RULE_FLEXSPI0_REGION_RULE0_COUNT (4U)

/*! @name RAM00_RULE - SRAM Partition 00 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM00_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM00_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM00_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM00_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM00_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM00_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM00_RULE */
#define AHB_SECURE_CTRL_RAM00_RULE_COUNT         (4U)

/*! @name RAM01_RULE - SRAM Partition 01 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM01_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM01_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM01_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM01_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM01_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM01_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM01_RULE */
#define AHB_SECURE_CTRL_RAM01_RULE_COUNT         (4U)

/*! @name RAM02_RULE - SRAM Partition 02 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM02_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM02_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM02_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM02_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM02_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM02_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM02_RULE */
#define AHB_SECURE_CTRL_RAM02_RULE_COUNT         (4U)

/*! @name RAM03_RULE - SRAM Partition 03 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM03_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM03_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM03_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM03_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM03_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM03_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM03_RULE */
#define AHB_SECURE_CTRL_RAM03_RULE_COUNT         (4U)

/*! @name RAM04_RULE - SRAM Partition 04 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM04_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM04_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM04_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM04_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM04_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM04_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM04_RULE */
#define AHB_SECURE_CTRL_RAM04_RULE_COUNT         (4U)

/*! @name RAM05_RULE - SRAM Partition 05 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM05_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM05_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM05_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM05_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM05_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM05_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM05_RULE */
#define AHB_SECURE_CTRL_RAM05_RULE_COUNT         (4U)

/*! @name RAM06_RULE - SRAM Partition 06 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM06_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM06_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM06_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM06_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM06_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM06_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM06_RULE */
#define AHB_SECURE_CTRL_RAM06_RULE_COUNT         (4U)

/*! @name RAM07_RULE - SRAM Partition 07 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM07_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM07_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM07_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM07_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM07_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM07_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM07_RULE */
#define AHB_SECURE_CTRL_RAM07_RULE_COUNT         (4U)

/*! @name RAM08_RULE - SRAM Partition 08 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM08_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM08_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM08_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM08_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM08_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM08_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM08_RULE */
#define AHB_SECURE_CTRL_RAM08_RULE_COUNT         (4U)

/*! @name RAM09_RULE - SRAM Partition 09 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM09_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM09_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM09_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM09_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM09_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM09_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM09_RULE */
#define AHB_SECURE_CTRL_RAM09_RULE_COUNT         (4U)

/*! @name RAM10_RULE - SRAM Partition 10 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM10_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM10_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM10_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM10_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM10_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM10_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM10_RULE */
#define AHB_SECURE_CTRL_RAM10_RULE_COUNT         (4U)

/*! @name RAM11_RULE - SRAM Partition 11 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM11_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM11_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM11_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM11_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM11_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM11_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM11_RULE */
#define AHB_SECURE_CTRL_RAM11_RULE_COUNT         (4U)

/*! @name RAM12_RULE - SRAM Partition 12 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM12_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM12_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM12_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM12_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM12_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM12_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM12_RULE */
#define AHB_SECURE_CTRL_RAM12_RULE_COUNT         (4U)

/*! @name RAM13_RULE - SRAM Partition 13 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM13_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM13_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM13_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM13_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM13_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM13_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM13_RULE */
#define AHB_SECURE_CTRL_RAM13_RULE_COUNT         (4U)

/*! @name RAM14_RULE - SRAM Partition 14 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM14_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM14_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM14_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM14_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM14_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM14_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM14_RULE */
#define AHB_SECURE_CTRL_RAM14_RULE_COUNT         (4U)

/*! @name RAM15_RULE - SRAM Partition 15 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM15_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM15_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM15_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM15_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM15_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM15_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM15_RULE */
#define AHB_SECURE_CTRL_RAM15_RULE_COUNT         (4U)

/*! @name RAM16_RULE - SRAM Partition 16 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM16_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM16_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM16_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM16_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM16_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM16_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM16_RULE */
#define AHB_SECURE_CTRL_RAM16_RULE_COUNT         (4U)

/*! @name RAM17_RULE - SRAM Partition 17 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM17_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM17_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM17_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM17_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM17_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM17_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM17_RULE */
#define AHB_SECURE_CTRL_RAM17_RULE_COUNT         (4U)

/*! @name RAM18_RULE - SRAM Partition 18 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM18_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM18_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM18_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM18_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM18_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM18_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM18_RULE */
#define AHB_SECURE_CTRL_RAM18_RULE_COUNT         (4U)

/*! @name RAM19_RULE - SRAM Partition 19 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM19_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM19_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM19_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM19_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM19_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM19_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM19_RULE */
#define AHB_SECURE_CTRL_RAM19_RULE_COUNT         (4U)

/*! @name RAM20_RULE - SRAM Partition 20 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM20_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM20_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM20_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM20_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM20_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM20_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM20_RULE */
#define AHB_SECURE_CTRL_RAM20_RULE_COUNT         (4U)

/*! @name RAM21_RULE - SRAM Partition 21 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM21_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM21_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM21_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM21_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM21_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM21_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM21_RULE */
#define AHB_SECURE_CTRL_RAM21_RULE_COUNT         (4U)

/*! @name RAM22_RULE - SRAM Partition 22 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM22_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM22_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM22_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM22_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM22_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM22_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM22_RULE */
#define AHB_SECURE_CTRL_RAM22_RULE_COUNT         (4U)

/*! @name RAM23_RULE - SRAM Partition 23 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM23_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM23_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM23_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM23_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM23_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM23_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM23_RULE */
#define AHB_SECURE_CTRL_RAM23_RULE_COUNT         (4U)

/*! @name RAM24_RULE - SRAM Partition 24 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM24_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM24_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM24_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM24_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM24_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM24_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM24_RULE */
#define AHB_SECURE_CTRL_RAM24_RULE_COUNT         (4U)

/*! @name RAM25_RULE - SRAM Partition 25 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM25_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM25_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM25_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM25_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM25_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM25_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM25_RULE */
#define AHB_SECURE_CTRL_RAM25_RULE_COUNT         (4U)

/*! @name RAM26_RULE - SRAM Partition 26 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM26_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM26_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM26_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM26_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM26_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM26_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM26_RULE */
#define AHB_SECURE_CTRL_RAM26_RULE_COUNT         (4U)

/*! @name RAM27_RULE - SRAM Partition 27 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM27_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM27_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM27_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM27_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM27_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM27_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM27_RULE */
#define AHB_SECURE_CTRL_RAM27_RULE_COUNT         (4U)

/*! @name RAM28_RULE - SRAM Partition 28 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM28_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM28_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM28_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM28_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM28_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM28_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM28_RULE */
#define AHB_SECURE_CTRL_RAM28_RULE_COUNT         (4U)

/*! @name RAM29_RULE - SRAM Partition 29 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM29_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM29_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM29_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM29_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM29_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM29_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM29_RULE */
#define AHB_SECURE_CTRL_RAM29_RULE_COUNT         (4U)

/*! @name RAM30_RULE - SRAM Partition 30 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM30_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM30_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM30_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM30_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM30_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM30_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM30_RULE */
#define AHB_SECURE_CTRL_RAM30_RULE_COUNT         (4U)

/*! @name RAM31_RULE - SRAM Partition 31 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_RAM31_RULE_RULE0_MASK    (0x3U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE0_SHIFT   (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE0(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE1_MASK    (0x30U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE1_SHIFT   (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE1(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE2_MASK    (0x300U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE2_SHIFT   (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE2(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE3_MASK    (0x3000U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE3_SHIFT   (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE3(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE4_MASK    (0x30000U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE4_SHIFT   (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE4(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE5_MASK    (0x300000U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE5_SHIFT   (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE5(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE6_MASK    (0x3000000U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE6_SHIFT   (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE6(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_RAM31_RULE_RULE7_MASK    (0x30000000U)
#define AHB_SECURE_CTRL_RAM31_RULE_RULE7_SHIFT   (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_RAM31_RULE_RULE7(x)      (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_RAM31_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_RAM31_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_RAM31_RULE */
#define AHB_SECURE_CTRL_RAM31_RULE_COUNT         (4U)

/*! @name SDMA_RAM_RULE - Smart DMA (SDMA) RAM Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE0(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE1(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE2(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE3(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE4_MASK (0x30000U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE4(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE5_MASK (0x300000U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE5(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE6_MASK (0x3000000U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE6(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE7_MASK (0x30000000U)
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE7(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_SDMA_RAM_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_SDMA_RAM_RULE */
#define AHB_SECURE_CTRL_SDMA_RAM_RULE_COUNT      (4U)

/*! @name FLEXSPI1_REGION0_RULE - FlexSPI1 Region 0 Rule(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE3_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE4_MASK (0x30000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE4_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE4_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE5_MASK (0x300000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE5_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE5_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE6_MASK (0x3000000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE6_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE6_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE7_MASK (0x30000000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE7_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_RULE7_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE */
#define AHB_SECURE_CTRL_FLEXSPI1_REGION0_RULE_COUNT (4U)

/*! @name FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0 - FlexSPI1 Region 1 Rule 0 Register..FlexSPI1 Region 4 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_RULE3_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0 */
#define AHB_SECURE_CTRL_FLEXSPI1_REGIONN_RULE0_FLEXSPI1_REGION_RULE0_COUNT (4U)

/*! @name APB_BRIDGE_PER0_RULE0 - APB Bridge Peripheral 0 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_RSTCTL_A_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_RSTCTL_A_SHIFT (0U)
/*! RSTCTL_A - RSTCTL_A
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_RSTCTL_A(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_RSTCTL_A_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_RSTCTL_A_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_CLKCTL_A_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_CLKCTL_A_SHIFT (4U)
/*! CLKCTL_A - CLKCTL_A
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_CLKCTL_A(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_CLKCTL_A_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_CLKCTL_A_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_SYSCTL_A_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_SYSCTL_A_SHIFT (8U)
/*! SYSCTL_A - SYSCTL_A
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_SYSCTL_A(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_SYSCTL_A_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_SYSCTL_A_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PVT_MASK (0x3000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PVT_SHIFT (12U)
/*! PVT - PVT
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PVT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PVT_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PVT_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_IOCON_MASK (0x30000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_IOCON_SHIFT (16U)
/*! IOCON - IOCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_IOCON(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_IOCON_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_IOCON_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PUF_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PUF_SHIFT (24U)
/*! PUF - PUF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PUF(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PUF_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE0_PUF_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER0_RULE1 - APB Bridge Peripheral 0 Rule 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_WWDT0_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_WWDT0_SHIFT (24U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_WWDT0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_WWDT0_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_WWDT0_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_MICRO_TICK_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_MICRO_TICK_SHIFT (28U)
/*! MICRO_TICK - MICRO_TICK
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_MICRO_TICK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_MICRO_TICK_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE1_MICRO_TICK_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER0_RULE3 - APB Bridge Peripheral 0 Rule 3 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_SYNC_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_SYNC_SHIFT (24U)
/*! PROBE_IS_SYNC - PROBE_IS (SYNC)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_SYNC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_SYNC_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_SYNC_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_XVC_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_XVC_SHIFT (28U)
/*! PROBE_IS_XVC - PROBE_IS (XVC)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_XVC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_XVC_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER0_RULE3_PROBE_IS_XVC_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER1_RULE0 - APB Bridge Peripheral 1 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_RSTCTL_B_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_RSTCTL_B_SHIFT (0U)
/*! RSTCTL_B - RSTCTL_B
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_RSTCTL_B(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_RSTCTL_B_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_RSTCTL_B_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_CLKCTL_B_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_CLKCTL_B_SHIFT (4U)
/*! CLKCTL_B - CLKCTL_B
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_CLKCTL_B(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_CLKCTL_B_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_CLKCTL_B_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SYSCTL_B_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SYSCTL_B_SHIFT (8U)
/*! SYSCTL_B - SYSCTL_B
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SYSCTL_B(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SYSCTL_B_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SYSCTL_B_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_GPIO_INT_MASK (0x300000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_GPIO_INT_SHIFT (20U)
/*! GPIO_INT - GPIO_INT
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_GPIO_INT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_GPIO_INT_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_GPIO_INT_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_PERIPHERAL_MUXES_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_PERIPHERAL_MUXES_SHIFT (24U)
/*! PERIPHERAL_MUXES - Peripheral Muxes
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_PERIPHERAL_MUXES(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_PERIPHERAL_MUXES_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_PERIPHERAL_MUXES_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SDMA_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SDMA_SHIFT (28U)
/*! SDMA - Smart DMA (SDMA)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SDMA(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SDMA_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE0_SDMA_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER1_RULE1 - APB Bridge Peripheral 1 Rule 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B0_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B0_SHIFT (0U)
/*! CT32B0 - CT32B0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B0_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B0_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B1_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B1_SHIFT (4U)
/*! CT32B1 - CT32B1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B1_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B1_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B2_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B2_SHIFT (8U)
/*! CT32B2 - CT32B2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B2_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B2_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B3_MASK (0x3000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B3_SHIFT (12U)
/*! CT32B3 - CT32B3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B3_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B3_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B4_MASK (0x30000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B4_SHIFT (16U)
/*! CT32B4 - CT32B4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B4_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_CT32B4_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_MRT0_MASK (0x300000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_MRT0_SHIFT (20U)
/*! MRT0 - MRT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_MRT0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_MRT0_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_MRT0_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_WWDT1_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_WWDT1_SHIFT (24U)
/*! WWDT1 - WWDT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_WWDT1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_WWDT1_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_WWDT1_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_FREQMEASURE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_FREQMEASURE_SHIFT (28U)
/*! FREQMEASURE - FREQMEASURE
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_FREQMEASURE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_FREQMEASURE_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE1_FREQMEASURE_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER1_RULE2 - APB Bridge Peripheral 1 Rule 2 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_RTC_WAKEUP_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_RTC_WAKEUP_SHIFT (0U)
/*! RTC_WAKEUP - RTC Wakeup
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_RTC_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_RTC_WAKEUP_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_RTC_WAKEUP_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_DSI_HOST_CONTROLLER_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_DSI_HOST_CONTROLLER_SHIFT (4U)
/*! DSI_HOST_CONTROLLER - DSI Host Controller
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_DSI_HOST_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_DSI_HOST_CONTROLLER_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_DSI_HOST_CONTROLLER_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_FLEXIO_REGISTERS_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_FLEXIO_REGISTERS_SHIFT (8U)
/*! FLEXIO_REGISTERS - FLEXIO Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_FLEXIO_REGISTERS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_FLEXIO_REGISTERS_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_FLEXIO_REGISTERS_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_0_REGS_MASK (0x3000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_0_REGS_SHIFT (12U)
/*! CACHE_CONTROL_0_REGS - Cache Control 0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_0_REGS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_0_REGS_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_0_REGS_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_1_REGS_MASK (0x30000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_1_REGS_SHIFT (16U)
/*! CACHE_CONTROL_1_REGS - Cache Control 1 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_1_REGS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_1_REGS_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_CACHE_CONTROL_1_REGS_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C0_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C0_SHIFT (24U)
/*! I3C0 - I3C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C0_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C0_MASK)

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C1_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C1_SHIFT (28U)
/*! I3C1 - I3C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C1_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE2_I3C1_MASK)
/*! @} */

/*! @name APB_BRIDGE_PER1_RULE3 - APB Bridge Peripheral 1 Rule 3 Register */
/*! @{ */

#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE3_MRT1_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE3_MRT1_SHIFT (28U)
/*! MRT1 - MRT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE3_MRT1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE3_MRT1_SHIFT)) & AHB_SECURE_CTRL_APB_BRIDGE_PER1_RULE3_MRT1_MASK)
/*! @} */

/*! @name AHB_PERIPH0_SLAVE_RULE0 - AHB Peripheral 0 Slave Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_SHIFT (0U)
/*! HSGPIO - HSGPIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_SHIFT (4U)
/*! DMA0 - DMA 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_SHIFT (8U)
/*! DMA1 - DMA 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_SHIFT (12U)
/*! FLEXCOMM0 - FLEXCOMM 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_SHIFT (16U)
/*! FLEXCOMM1 - FLEXCOMM 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_SHIFT (20U)
/*! FLEXCOMM2 - FLEXCOMM 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_SHIFT (24U)
/*! FLEXCOMM3 - FLEXCOMM 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT (28U)
/*! DEBUG_MAILBOX - DEBUG_MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_MASK)
/*! @} */

/*! @name AIPS_BRIDGE0_PER_RULE0 - AIPS Bridge Peripheral 0 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU0_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU0_SHIFT (0U)
/*! MU0 - MU0 (M33 PORT)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU0_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU0_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU1_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU1_SHIFT (4U)
/*! MU1 - MU1 (DSP PORT)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU1_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_MU1_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_SEMAPHORE_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_SEMAPHORE_SHIFT (8U)
/*! SEMAPHORE - Semaphore
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_SEMAPHORE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_SEMAPHORE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_SEMAPHORE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_M33_PORT_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_M33_PORT_SHIFT (12U)
/*! OS_EVENT_TIMER_M33_PORT - OS_EVENT TIMER (M33 PORT)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_M33_PORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_M33_PORT_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_M33_PORT_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_DSP_PORT_MASK (0x30000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_DSP_PORT_SHIFT (16U)
/*! OS_EVENT_TIMER_DSP_PORT - OS_EVENT TIMER (DSP PORT)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_DSP_PORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_DSP_PORT_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_OS_EVENT_TIMER_DSP_PORT_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_ROM_MASK (0x300000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_ROM_SHIFT (20U)
/*! ROM - ROM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_ROM(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_ROM_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_PER_RULE0_ROM_MASK)
/*! @} */

/*! @name AHB_PERIPH1_SLAVE_RULE0 - AHB Peripheral 1 Slave Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_SHIFT (0U)
/*! CRC - CRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC0_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC0_SHIFT (4U)
/*! DMIC0 - DMIC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC0_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC0_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_SHIFT (8U)
/*! FLEXCOMM4 - FLEXCOMM 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_SHIFT (12U)
/*! FLEXCOMM5 - FLEXCOMM 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_SHIFT (16U)
/*! FLEXCOMM6 - FLEXCOMM 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_SHIFT (20U)
/*! FLEXCOMM7 - FLEXCOMM 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_SHIFT (24U)
/*! FLEXCOMM14 - FLEXCOMM 14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_SHIFT (28U)
/*! FLEXCOMM15 - FLEXCOMM 15
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_MASK)
/*! @} */

/*! @name AHB_PERIPH1_SLAVE_RULE1 - AHB Peripheral 1 Slave Rule 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE1_FLEXCOMM16_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE1_FLEXCOMM16_SHIFT (0U)
/*! FLEXCOMM16 - FLEXCOMM 16
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE1_FLEXCOMM16(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE1_FLEXCOMM16_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE1_FLEXCOMM16_MASK)
/*! @} */

/*! @name AIPS_BRIDGE1_PER_RULE0 - AIPS Bridge Peripheral 1 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_0_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_0_SHIFT (0U)
/*! OTP_CONTROLLER_0 - OTP Controller 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_0_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_0_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_1_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_1_SHIFT (4U)
/*! OTP_CONTROLLER_1 - OTP Controller 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_1_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_1_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_2_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_2_SHIFT (8U)
/*! OTP_CONTROLLER_2 - OTP Controller 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_2_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_2_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_3_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_3_SHIFT (12U)
/*! OTP_CONTROLLER_3 - OTP Controller 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_3_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_OTP_CONTROLLER_3_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_FLEXSPI0_REGISTERS_MASK (0x30000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_FLEXSPI0_REGISTERS_SHIFT (16U)
/*! FLEXSPI0_REGISTERS - FLEXSPI0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_FLEXSPI0_REGISTERS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_FLEXSPI0_REGISTERS_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_FLEXSPI0_REGISTERS_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_PMC_PMU_CONTROL_MASK (0x300000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_PMC_PMU_CONTROL_SHIFT (20U)
/*! PMC_PMU_CONTROL - PMC (PMU CONTROL)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_PMC_PMU_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_PMC_PMU_CONTROL_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_PMC_PMU_CONTROL_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO0_REGISTERS_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO0_REGISTERS_SHIFT (24U)
/*! SDIO0_REGISTERS - SDIO 0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO0_REGISTERS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO0_REGISTERS_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO0_REGISTERS_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO1_REGISTERS_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO1_REGISTERS_SHIFT (28U)
/*! SDIO1_REGISTERS - SDIO 1 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO1_REGISTERS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO1_REGISTERS_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE0_SDIO1_REGISTERS_MASK)
/*! @} */

/*! @name AIPS_BRIDGE1_PER_RULE1 - AIPS Bridge Peripheral 1 Rule 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_RNG_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_RNG_SHIFT (0U)
/*! RNG - RNG (Random Number Generator)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_RNG(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_RNG_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_RNG_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ACMP0_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ACMP0_SHIFT (4U)
/*! ACMP0 - ACMP 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ACMP0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ACMP0_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ACMP0_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ADC0_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ADC0_SHIFT (8U)
/*! ADC0 - ADC 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ADC0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ADC0_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_ADC0_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_HS_USB_PHY_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_HS_USB_PHY_SHIFT (12U)
/*! HS_USB_PHY - HS USB PHY
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_HS_USB_PHY(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_HS_USB_PHY_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_HS_USB_PHY_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_FLEXSPI1_REGISTERS_MASK (0x30000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_FLEXSPI1_REGISTERS_SHIFT (16U)
/*! FLEXSPI1_REGISTERS - FLEXSPI1 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_FLEXSPI1_REGISTERS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_FLEXSPI1_REGISTERS_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_PER_RULE1_FLEXSPI1_REGISTERS_MASK)
/*! @} */

/*! @name AHB_PERIPH2_SLAVE_RULE0 - AHB Peripheral 2 Slave Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_SHIFT (0U)
/*! USB_HS_RAM - USB HS RAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_SHIFT (4U)
/*! USB_HS_DEV - USB HS DEV
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_SHIFT (8U)
/*! USB_HS_HOST - USB HS HOST
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_SHIFT (12U)
/*! SCT - SCT
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPH_RULE0 - AHB Secure Control Peripheral Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_AHB_SECURE_CTRL_PERIPH_RULE0_RULE3_MASK)
/*! @} */

/*! @name AHB_PERIPH3_SLAVE_RULE0 - AHB Peripheral 3 Slave Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_POWERQUAD_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_POWERQUAD_SHIFT (0U)
/*! POWERQUAD - POWERQUAD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_POWERQUAD(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_POWERQUAD_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_POWERQUAD_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_SHIFT (4U)
/*! CASPER - CASPER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_SHIFT (8U)
/*! CASPER_RAM - CASPER RAM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_SHIFT (12U)
/*! SECURE_GPIO - Secure GPIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_SHIFT (16U)
/*! HASH - HASH
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM8_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM8_SHIFT (20U)
/*! FLEXCOMM8 - FLEXCOMM 8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM8(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM8_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM8_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM9_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM9_SHIFT (24U)
/*! FLEXCOMM9 - FLEXCOMM 9
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM9(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM9_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM9_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM10_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM10_SHIFT (28U)
/*! FLEXCOMM10 - FLEXCOMM 10
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM10(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM10_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_FLEXCOMM10_MASK)
/*! @} */

/*! @name AHB_PERIPH3_SLAVE_RULE1 - AHB Peripheral 3 Slave Rule 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM11_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM11_SHIFT (0U)
/*! FLEXCOMM11 - FLEXCOMM 11
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM11(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM11_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM11_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM12_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM12_SHIFT (4U)
/*! FLEXCOMM12 - FLEXCOMM 12
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM12(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM12_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM12_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM13_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM13_SHIFT (8U)
/*! FLEXCOMM13 - FLEXCOMM 13
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM13(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM13_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_FLEXCOMM13_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_LCDIF_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_LCDIF_SHIFT (12U)
/*! LCDIF - LCDIF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_LCDIF(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_LCDIF_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_LCDIF_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_GPU_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_GPU_SHIFT (16U)
/*! GPU - GPU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_GPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_GPU_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_GPU_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_AXI_SWITCH_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_AXI_SWITCH_SHIFT (20U)
/*! AXI_SWITCH - AXI Switch
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_AXI_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_AXI_SWITCH_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE1_AXI_SWITCH_MASK)
/*! @} */

/*! @name SEC_VIO_ADDR - Security Violation Address(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_MASK (0xFFFFFFFFU)
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator */
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_SEC_VIO_ADDR */
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_COUNT       (18U)

/*! @name SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0xF00U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - Security violation master number
 *  0b0000..M33 Code
 *  0b0001..M33 System
 *  0b0010..Powerquad
 *  0b0011..DSP
 *  0b0100..DMA0
 *  0b0101..DMA1
 *  0b0110..SDMA Instruction
 *  0b0111..SDMA Data
 *  0b1000..SDIO0
 *  0b1001..SDIO1
 *  0b1010..HASH
 *  0b1011..GPU
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHB_SECURE_CTRL_SEC_VIO_MISC_INFO */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_COUNT  (18U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address(n) Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - Violation information valid flag for AHB port 13
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - Violation information valid flag for AHB port 14
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - Violation information valid flag for AHB port 15
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - Violation information valid flag for AHB port 16
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT (17U)
/*! VIO_INFO_VALID17 - Violation information valid flag for AHB port 17
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT (18U)
/*! VIO_INFO_VALID18 - Violation information valid flag for AHB port 18
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK0 - GPIO Mask for Port 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO0_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO0_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO0_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO0_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO0_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO0_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO0_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO0_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO0_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO0_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO0_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO0_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO0_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO0_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO0_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO0_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO0_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO0_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO0_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO0_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO0_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO0_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO0_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO0_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO0_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO0_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO0_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO0_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO0_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO0_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO0_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO0_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK1 - GPIO Mask for Port 1 Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO1_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO1_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO1_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO1_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO1_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO1_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO1_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO1_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO1_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO1_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO1_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO1_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO1_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO1_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO1_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO1_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO1_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO1_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO1_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO1_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO1_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO1_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO1_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO1_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO1_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO1_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO1_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO1_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO1_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO1_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO1_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO1_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK2 - GPIO Mask for Port 2 Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO2_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO2_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO2_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO2_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO2_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO2_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO2_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO2_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO2_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO2_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO2_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO2_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO2_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO2_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO2_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO2_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO2_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO2_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO2_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO2_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO2_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO2_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO2_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO2_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO2_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO2_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO2_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO2_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO2_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO2_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO2_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO2_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name DSP_INT_MASK0 - Secure Interrupt Mask for DSP Register */
/*! @{ */

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT0_MASK (0x20U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT0_SHIFT (5U)
/*! PMUX_OUT0 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT0_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT0_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT1_MASK (0x40U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT1_SHIFT (6U)
/*! PMUX_OUT1 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT1_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT1_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT2_MASK (0x80U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT2_SHIFT (7U)
/*! PMUX_OUT2 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT2_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT2_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT3_MASK (0x100U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT3_SHIFT (8U)
/*! PMUX_OUT3 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT3_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT3_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT4_MASK (0x200U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT4_SHIFT (9U)
/*! PMUX_OUT4 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT4_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT4_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT5_MASK (0x400U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT5_SHIFT (10U)
/*! PMUX_OUT5 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT5_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT5_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT6_MASK (0x800U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT6_SHIFT (11U)
/*! PMUX_OUT6 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT6_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT6_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT7_MASK (0x1000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT7_SHIFT (12U)
/*! PMUX_OUT7 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT7_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT7_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT8_MASK (0x2000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT8_SHIFT (13U)
/*! PMUX_OUT8 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT8(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT8_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT8_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT9_MASK (0x4000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT9_SHIFT (14U)
/*! PMUX_OUT9 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT9(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT9_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT9_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT10_MASK (0x8000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT10_SHIFT (15U)
/*! PMUX_OUT10 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT10(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT10_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT10_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT11_MASK (0x10000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT11_SHIFT (16U)
/*! PMUX_OUT11 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT11(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT11_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT11_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT12_MASK (0x20000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT12_SHIFT (17U)
/*! PMUX_OUT12 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT12(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT12_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT12_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT13_MASK (0x40000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT13_SHIFT (18U)
/*! PMUX_OUT13 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT13(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT13_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT13_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT14_MASK (0x80000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT14_SHIFT (19U)
/*! PMUX_OUT14 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT14(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT14_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT14_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT15_MASK (0x100000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT15_SHIFT (20U)
/*! PMUX_OUT15 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT15(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT15_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT15_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT16_MASK (0x200000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT16_SHIFT (21U)
/*! PMUX_OUT16 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT16(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT16_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT16_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT17_MASK (0x400000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT17_SHIFT (22U)
/*! PMUX_OUT17 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT17(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT17_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT17_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT18_MASK (0x800000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT18_SHIFT (23U)
/*! PMUX_OUT18 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT18(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT18_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT18_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT19_MASK (0x1000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT19_SHIFT (24U)
/*! PMUX_OUT19 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT19(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT19_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT19_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT20_MASK (0x2000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT20_SHIFT (25U)
/*! PMUX_OUT20 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT20(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT20_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT20_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT21_MASK (0x4000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT21_SHIFT (26U)
/*! PMUX_OUT21 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT21(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT21_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT21_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT22_MASK (0x8000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT22_SHIFT (27U)
/*! PMUX_OUT22 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT22(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT22_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT22_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT23_MASK (0x10000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT23_SHIFT (28U)
/*! PMUX_OUT23 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT23(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT23_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT23_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT24_MASK (0x20000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT24_SHIFT (29U)
/*! PMUX_OUT24 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT24(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT24_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT24_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT25_MASK (0x40000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT25_SHIFT (30U)
/*! PMUX_OUT25 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT25(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT25_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT25_MASK)

#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT26_MASK (0x80000000U)
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT26_SHIFT (31U)
/*! PMUX_OUT26 - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT26(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT26_SHIFT)) & AHB_SECURE_CTRL_DSP_INT_MASK0_PMUX_OUT26_MASK)
/*! @} */

/*! @name SEC_MASK_LOCK - Secure Mask Lock Register */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT (0U)
/*! SEC_GPIO_MASK0_LOCK - Secure GPIO _MASK0 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK0 cannot be written
 *  0b10..SEC_GPIO_MASK0 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_MASK (0xCU)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT (2U)
/*! SEC_GPIO_MASK1_LOCK - Secure GPIO _MASK1 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK1 cannot be written
 *  0b10..SEC_GPIO_MASK1 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_MASK (0x30U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT (4U)
/*! SEC_GPIO_MASK2_LOCK - Secure GPIO _MASK2 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK2 cannot be written
 *  0b10..SEC_GPIO_MASK2 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_MASK (0xC0U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT (6U)
/*! SEC_GPIO_MASK3_LOCK - Secure GPIO _MASK3 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK3 cannot be written
 *  0b10..SEC_GPIO_MASK3 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_MASK (0x300U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT (8U)
/*! SEC_GPIO_MASK4_LOCK - SEC_GPIO_MASK4 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK4_LOCK cannot be written
 *  0b10..SEC_GPIO_MASK4_LOCK can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_MASK (0xC00U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT (10U)
/*! SEC_GPIO_MASK5_LOCK - SEC_GPIO_MASK5 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK5 cannot be written
 *  0b10..SEC_GPIO_MASK5 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_MASK (0x3000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT (12U)
/*! SEC_GPIO_MASK6_LOCK - SEC_GPIO_MASK6 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK6 cannot be written
 *  0b10..SEC_GPIO_MASK6 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_MASK (0xC000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT (14U)
/*! SEC_GPIO_MASK7_LOCK - SEC_GPIO_MASK7 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK7 cannot be written
 *  0b10..SEC_GPIO_MASK7 can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_MASK_LOCK_MASK (0x30000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_MASK_LOCK_SHIFT (16U)
/*! SEC_DSP_INT_MASK_LOCK - SEC_DSP_INT_MASK Lock
 *  0b00..Reserved
 *  0b01..SEC_DSP_INT_MASK cannot be written
 *  0b10..SEC_DSP_INT_MASK can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_MASK_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_MASK_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_MASK_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level Register */
/*! @{ */

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_PQ_MASK (0x30U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_PQ_SHIFT (4U)
/*! PQ - Power Quad
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_PQ(x)   (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_PQ_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_PQ_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_MASK (0xC0U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SHIFT (6U)
/*! DSP - DSP
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP(x)  (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_MASK (0x300U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SHIFT (8U)
/*! DMA0 - DMA 0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_MASK (0xC00U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SHIFT (10U)
/*! DMA1 - DMA 1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_I_MASK (0x3000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_I_SHIFT (12U)
/*! SDMA_I - Smart DMA (SDMA) Instruction
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_I(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_I_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_I_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_D_MASK (0xC000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_D_SHIFT (14U)
/*! SDMA_D - Smart DMA (SDMA) Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_D(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_D_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDMA_D_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_MASK (0x30000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SHIFT (16U)
/*! SDIO0 - SDIO 0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_MASK (0xC0000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SHIFT (18U)
/*! SDIO1 - SDIO 1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_GPU_MASK (0x300000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_GPU_SHIFT (20U)
/*! GPU - GPU
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_GPU(x)  (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_GPU_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_GPU_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_LOCK - Master Security Level Lock
 *  0b00..Reserved
 *  0b01..Lock writing to this register, including these (MASTER_SEC_LEVEL_LOCK) bits
 *  0b10..This register can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level Register */
/*! @{ */

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_PQ_MASK (0x30U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_PQ_SHIFT (4U)
/*! PQ - Power Quad */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_PQ(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_PQ_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_PQ_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DSP_MASK (0xC0U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DSP_SHIFT (6U)
/*! DSP - DSP */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DSP(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DSP_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DSP_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA0_MASK (0x300U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT (8U)
/*! DMA0 - DMA 0 */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA0_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA1_MASK (0xC00U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT (10U)
/*! DMA1 - DMA 1 */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_DMA1_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_I_MASK (0x3000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_I_SHIFT (12U)
/*! SDMA_I - Smart DMA (SDMA) Instruction */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_I(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_I_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_I_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_D_MASK (0xC000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_D_SHIFT (14U)
/*! SDMA_D - Smart DMA (SDMA) Data */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_D(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_D_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDMA_D_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO0_MASK (0x30000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO0_SHIFT (16U)
/*! SDIO0 - SDIO 0 */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO0_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO0_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO1_MASK (0xC0000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO1_SHIFT (18U)
/*! SDIO1 - SDIO 1 */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO1_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_SDIO1_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_GPU_MASK (0x300000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_GPU_SHIFT (20U)
/*! GPU - GPU */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_GPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_GPU_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_GPU_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_ANTIPOL_LOCK - Master Security Level Antipole Lock
 *  0b00..Reserved
 *  0b01..Lock writing to this register, including these (MASTER_SEC_LEVEL_ANTIPOL_LOCK) bits
 *  0b10..This register can be written
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK)
/*! @} */

/*! @name CM33_LOCK_REG - Miscellaneous CPU0 Control Signals Register */
/*! @{ */

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_MASK (0x3U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT (0U)
/*! LOCK_NS_VTOR - Lock Non-Secure VTOR
 *  0b00..Reserved
 *  0b01..Locks Non-Secure VTOR
 *  0b10..Non-Secure VTOR can be used
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_MASK (0xCU)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT (2U)
/*! LOCK_NS_MPU - Lock Non-Secure MPU
 *  0b00..Reserved
 *  0b01..Locks Non-Secure MPU
 *  0b10..Non-Secure MPU can be used
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_MASK (0x30U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_SHIFT (4U)
/*! LOCK_S_VTOR - Lock Secure VTOR
 *  0b00..Reserved
 *  0b01..Locks Secure VTOR
 *  0b10..Secure VTOR can be used
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_MASK (0xC0U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_SHIFT (6U)
/*! LOCK_S_MPU - Lock Secure MPU
 *  0b00..Reserved
 *  0b01..Locks Secure MPU
 *  0b10..Secure MPU can be used
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_MASK (0x300U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_SHIFT (8U)
/*! LOCK_SAU - Lock SAU
 *  0b00..Reserved
 *  0b01..SAU is locked
 *  0b10..SAU can be used
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT (30U)
/*! CM33_LOCK_REG_LOCK - Lock CM33 Lock Register
 *  0b00..Reserved
 *  0b01..Does not allow writing to this register
 *  0b10..Allows writing to this register
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate Register */
/*! @{ */

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK (0xC00U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT (10U)
/*! DISABLE_SIMPLE_MASTER_STRICT_MODE - Disable Simple Master Strict Mode
 *  0b00..Reserved
 *  0b01..Can access memories and peripherals at the same level or below that level
 *  0b10..Can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK (0x3000U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT (12U)
/*! DISABLE_SMART_MASTER_STRICT_MODE - Disable Smart Master Strict Mode
 *  0b00..Reserved
 *  0b01..Can access memories and peripherals at the same level or below that level
 *  0b10..Can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control Register */
/*! @{ */

#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK (0xC00U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT (10U)
/*! DISABLE_SIMPLE_MASTER_STRICT_MODE - Disable Simple Master Strict Mode
 *  0b00..Reserved
 *  0b01..Can access memories and peripherals at the same level or below that level
 *  0b10..Can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK (0x3000U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT (12U)
/*! DISABLE_SMART_MASTER_STRICT_MODE - Disable Smart Master Strict Mode
 *  0b00..Reserved
 *  0b01..Can access memories and peripherals at the same level or below that level
 *  0b10..Can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHB_SECURE_CTRL_Register_Masks */


/*!
 * @}
 */ /* end of group AHB_SECURE_CTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_AHB_SECURE_CTRL_H_ */

