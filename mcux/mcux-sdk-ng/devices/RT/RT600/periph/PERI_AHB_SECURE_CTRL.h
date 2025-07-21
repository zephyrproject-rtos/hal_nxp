/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AHB_SECURE_CTRL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHB_SECURE_CTRL
 *
 * CMSIS Peripheral Access Layer for AHB_SECURE_CTRL
 */

#if !defined(PERI_AHB_SECURE_CTRL_H_)
#define PERI_AHB_SECURE_CTRL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_COUNT        18u
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_COUNT   18u

/** AHB_SECURE_CTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ROM_MEM_RULE[AHB_SECURE_CTRL_ROM_MEM_RULE_COUNT]; /**< Memory ROM Rule(n) Register, array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t FLEXSPI0_REGION0_RULE[AHB_SECURE_CTRL_FLEXSPI0_REGION0_RULE_COUNT]; /**< FLEXSPI0 Region 0 Rule(n) Register, array offset: 0x30, array step: 0x4 */
  __IO uint32_t FLEXSPI0_REGION1_RULE0;            /**< FLEXSPI0 Region 1 Rule 0 Register, offset: 0x40 */
       uint8_t RESERVED_2[12];
  __IO uint32_t FLEXSPI0_REGION2_RULE0;            /**< FLEXSPI0 Region 2 Rule 0 Register, offset: 0x50 */
       uint8_t RESERVED_3[12];
  __IO uint32_t FLEXSPI0_REGION3_RULE0;            /**< FLEXSPI0 Region 3 Rule 0 Register, offset: 0x60 */
       uint8_t RESERVED_4[12];
  __IO uint32_t FLEXSPI0_REGION4_RULE0;            /**< FLEXSPI0 Region 4 Rule 0 Register, offset: 0x70 */
       uint8_t RESERVED_5[28];
  __IO uint32_t RAM00_RULE[AHB_SECURE_CTRL_RAM00_RULEN_COUNT]; /**< SRAM Partition 00 Rule(n) Register, array offset: 0x90, array step: 0x4 */
  __IO uint32_t RAM01_RULE[AHB_SECURE_CTRL_RAM01_RULEN_COUNT]; /**< SRAM Partition 01 Rule(n) Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_6[16];
  __IO uint32_t RAM02_RULE[AHB_SECURE_CTRL_RAM02_RULEN_COUNT]; /**< SRAM Partition 02 Rule(n) Register, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t RAM03_RULE[AHB_SECURE_CTRL_RAM03_RULEN_COUNT]; /**< SRAM Partition 03 Rule(n) Register, array offset: 0xD0, array step: 0x4 */
       uint8_t RESERVED_7[16];
  __IO uint32_t RAM04_RULE[AHB_SECURE_CTRL_RAM04_RULEN_COUNT]; /**< SRAM Partition 04 Rule(n) Register, array offset: 0xF0, array step: 0x4 */
  __IO uint32_t RAM05_RULE[AHB_SECURE_CTRL_RAM05_RULEN_COUNT]; /**< SRAM Partition 05 Rule(n) Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t RAM06_RULE[AHB_SECURE_CTRL_RAM06_RULEN_COUNT]; /**< SRAM Partition 06 Rule(n) Register, array offset: 0x110, array step: 0x4 */
  __IO uint32_t RAM07_RULE[AHB_SECURE_CTRL_RAM07_RULEN_COUNT]; /**< SRAM Partition 07 Rule(n) Register, array offset: 0x120, array step: 0x4 */
       uint8_t RESERVED_8[16];
  __IO uint32_t RAM08_RULE[AHB_SECURE_CTRL_RAM08_RULEN_COUNT]; /**< SRAM Partition 08 Rule(n) Register, array offset: 0x140, array step: 0x4 */
  __IO uint32_t RAM09_RULE[AHB_SECURE_CTRL_RAM09_RULEN_COUNT]; /**< SRAM Partition 09 Rule(n) Register, array offset: 0x150, array step: 0x4 */
  __IO uint32_t RAM10_RULE[AHB_SECURE_CTRL_RAM10_RULEN_COUNT]; /**< SRAM Partition 10 Rule(n) Register, array offset: 0x160, array step: 0x4 */
  __IO uint32_t RAM11_RULE[AHB_SECURE_CTRL_RAM11_RULEN_COUNT]; /**< SRAM Partition 11 Rule(n) Register, array offset: 0x170, array step: 0x4 */
       uint8_t RESERVED_9[16];
  __IO uint32_t RAM12_RULE[AHB_SECURE_CTRL_RAM12_RULEN_COUNT]; /**< SRAM Partition 12 Rule(n) Register, array offset: 0x190, array step: 0x4 */
  __IO uint32_t RAM13_RULE[AHB_SECURE_CTRL_RAM13_RULEN_COUNT]; /**< SRAM Partition 13 Rule(n) Register, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t RAM14_RULE[AHB_SECURE_CTRL_RAM14_RULEN_COUNT]; /**< SRAM Partition 14 Rule(n) Register, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t RAM15_RULE[AHB_SECURE_CTRL_RAM15_RULEN_COUNT]; /**< SRAM Partition 15 Rule(n) Register, array offset: 0x1C0, array step: 0x4 */
       uint8_t RESERVED_10[16];
  __IO uint32_t RAM16_RULE[AHB_SECURE_CTRL_RAM16_RULEN_COUNT]; /**< SRAM Partition 16 Rule(n) Register, array offset: 0x1E0, array step: 0x4 */
  __IO uint32_t RAM17_RULE[AHB_SECURE_CTRL_RAM17_RULEN_COUNT]; /**< SRAM Partition 17 Rule(n) Register, array offset: 0x1F0, array step: 0x4 */
  __IO uint32_t RAM18_RULE[AHB_SECURE_CTRL_RAM18_RULEN_COUNT]; /**< SRAM Partition 18 Rule(n) Register, array offset: 0x200, array step: 0x4 */
  __IO uint32_t RAM19_RULE[AHB_SECURE_CTRL_RAM19_RULEN_COUNT]; /**< SRAM Partition 19 Rule(n) Register, array offset: 0x210, array step: 0x4 */
       uint8_t RESERVED_11[16];
  __IO uint32_t RAM20_RULE[AHB_SECURE_CTRL_RAM20_RULEN_COUNT]; /**< SRAM Partition 20 Rule(n) Register, array offset: 0x230, array step: 0x4 */
  __IO uint32_t RAM21_RULE[AHB_SECURE_CTRL_RAM21_RULEN_COUNT]; /**< SRAM Partition 21 Rule(n) Register, array offset: 0x240, array step: 0x4 */
  __IO uint32_t RAM22_RULE[AHB_SECURE_CTRL_RAM22_RULEN_COUNT]; /**< SRAM Partition 22 Rule(n) Register, array offset: 0x250, array step: 0x4 */
  __IO uint32_t RAM23_RULE[AHB_SECURE_CTRL_RAM23_RULEN_COUNT]; /**< SRAM Partition 23 Rule(n) Register, array offset: 0x260, array step: 0x4 */
       uint8_t RESERVED_12[16];
  __IO uint32_t RAM24_RULE[AHB_SECURE_CTRL_RAM24_RULEN_COUNT]; /**< SRAM Partition 24 Rule(n) Register, array offset: 0x280, array step: 0x4 */
  __IO uint32_t RAM25_RULE[AHB_SECURE_CTRL_RAM25_RULEN_COUNT]; /**< SRAM Partition 25 Rule(n) Register, array offset: 0x290, array step: 0x4 */
  __IO uint32_t RAM26_RULE[AHB_SECURE_CTRL_RAM26_RULEN_COUNT]; /**< SRAM Partition 26 Rule(n) Register, array offset: 0x2A0, array step: 0x4 */
  __IO uint32_t RAM27_RULE[AHB_SECURE_CTRL_RAM27_RULEN_COUNT]; /**< SRAM Partition 27 Rule(n) Register, array offset: 0x2B0, array step: 0x4 */
       uint8_t RESERVED_13[16];
  __IO uint32_t RAM28_RULE[AHB_SECURE_CTRL_RAM28_RULEN_COUNT]; /**< SRAM Partition 28 Rule(n) Register, array offset: 0x2D0, array step: 0x4 */
  __IO uint32_t RAM29_RULE[AHB_SECURE_CTRL_RAM29_RULEN_COUNT]; /**< SRAM Partition 29 Rule(n) Register, array offset: 0x2E0, array step: 0x4 */
       uint8_t RESERVED_14[48];
  __IO uint32_t PIF_HIFI4_X_MEM_RULE0;             /**< Security access rules for HiFi 4 memory sectors (0x24000000--0x240FFFFF). Each sector is 32 Kbytes, there're 4 sectors in total., offset: 0x320 */
       uint8_t RESERVED_15[28];
  __IO uint32_t APB_GRP0_MEM_RULE0;                /**< Security access rules for APB Bridge 0 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x340 */
  __IO uint32_t APB_GRP0_MEM_RULE1;                /**< Security access rules for APB Bridge 0 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x344 */
       uint8_t RESERVED_16[8];
  __IO uint32_t APB_GRP1_MEM_RULE0;                /**< Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x350 */
  __IO uint32_t APB_GRP1_MEM_RULE1;                /**< Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x354 */
  __IO uint32_t APB_GRP1_MEM_RULE2;                /**< Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x358 */
       uint8_t RESERVED_17[4];
  __IO uint32_t AHB_PERIPH0_SLAVE_RULE0;           /**< Security access rules for AHB peripheral slaves area 0x40100000--0x4010FFFF, offset: 0x360 */
       uint8_t RESERVED_18[12];
  __IO uint32_t AIPS_BRIDGE0_MEM_RULE0;            /**< 0x40110000--0x4011FFFF, offset: 0x370 */
       uint8_t RESERVED_19[12];
  __IO uint32_t AHB_PERIPH1_SLAVE_RULE0;           /**< the memory map is 0x40120000--0x40127FFF, offset: 0x380 */
       uint8_t RESERVED_20[28];
  __IO uint32_t AIPS_BRIDGE1_MEM_RULE0;            /**< Security access rules for AIPS Bridge peripherals. Each AIPS bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x3A0 */
  __IO uint32_t AIPS_BRIDGE1_MEM_RULE1;            /**< Security access rules for AIPS Bridge peripherals. Each AIPS bridge sector is 4 Kbytes, there're 16 sectors in total., offset: 0x3A4 */
       uint8_t RESERVED_21[8];
  __IO uint32_t AHB_PERIPH2_SLAVE_RULE0;           /**< Security access rules for AHB peripheral slaves area 0x40140000--0x4014BFFF, offset: 0x3B0 */
       uint8_t RESERVED_22[12];
  __IO uint32_t SECURITY_CTRL_MEM_RULE0;           /**< 0x40148000--0x4014BFFF, offset: 0x3C0 */
       uint8_t RESERVED_23[12];
  __IO uint32_t AHB_PERIPH3_SLAVE_RULE0;           /**< Security access rules for AHB peripheral slaves area 0x40150000--0x40158FFF, offset: 0x3D0 */
       uint8_t RESERVED_24[2604];
  __I  uint32_t SEC_VIO_ADDR[AHB_SECURE_CTRL_SEC_VIO_ADDR_COUNT]; /**< most recent security violation address for AHB layer n, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_25[56];
  __I  uint32_t SEC_VIO_MISC_INFO[AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_COUNT]; /**< most recent security violation miscellaneous information for AHB layer n, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_26[56];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< security violation address/information registers valid flags, offset: 0xF00 */
       uint8_t RESERVED_27[124];
  __IO uint32_t SEC_GPIO_MASK0;                    /**< Secure GPIO mask for port 0 pins. This register is used to block leakage of Secure interface (GPIOs, I2C, UART configured as secure peripherals) pin states to non-secure world., offset: 0xF80 */
  __IO uint32_t SEC_GPIO_MASK1;                    /**< Secure GPIO mask for port 1 pins., offset: 0xF84 */
  __IO uint32_t SEC_GPIO_MASK2;                    /**< Secure GPIO mask for port 2 pins., offset: 0xF88 */
  __IO uint32_t SEC_GPIO_MASK3;                    /**< Secure GPIO mask for port 3 pins., offset: 0xF8C */
  __IO uint32_t SEC_GPIO_MASK4;                    /**< Secure GPIO mask for port 4 pins., offset: 0xF90 */
  __IO uint32_t SEC_GPIO_MASK5;                    /**< Secure GPIO mask for port 5 pins., offset: 0xF94 */
  __IO uint32_t SEC_GPIO_MASK6;                    /**< Secure GPIO mask for port 6 pins., offset: 0xF98 */
  __IO uint32_t SEC_GPIO_MASK7;                    /**< Secure GPIO mask for port 7 pins., offset: 0xF9C */
  __IO uint32_t SEC_DSP_INT_MASK;                  /**< secure general purpose register 8 used to mask interrupts to DSP for security purpose, offset: 0xFA0 */
       uint8_t RESERVED_28[24];
  __IO uint32_t SEC_MASK_LOCK;                     /**< sec_gp_reg write-lock bits, offset: 0xFBC */
       uint8_t RESERVED_29[16];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< master secure level register, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_LEVEL_ANTI_POL;         /**< master secure level anti-pole register, offset: 0xFD4 */
       uint8_t RESERVED_30[20];
  __IO uint32_t CM33_LOCK_REG;                     /**< m33 lock control register, offset: 0xFEC */
       uint8_t RESERVED_31[8];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< secure control duplicate register, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< secure control register, offset: 0xFFC */
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

/*! @name FLEXSPI0_REGION1_RULE0 - FLEXSPI0 Region 1 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION1_RULE0_RULE3_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION2_RULE0 - FLEXSPI0 Region 2 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION2_RULE0_RULE3_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION3_RULE0 - FLEXSPI0 Region 3 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION3_RULE0_RULE3_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION4_RULE0 - FLEXSPI0 Region 4 Rule 0 Register */
/*! @{ */

#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_FLEXSPI0_REGION4_RULE0_RULE3_MASK)
/*! @} */

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

/*! @name PIF_HIFI4_X_MEM_RULE0 - Security access rules for HiFi 4 memory sectors (0x24000000--0x240FFFFF). Each sector is 32 Kbytes, there're 4 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - secure control rule0. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - secure control rule1. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE4_MASK (0x30000U)
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE4_SHIFT (16U)
/*! RULE4 - secure control rule4. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE4_SHIFT)) & AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE4_MASK)

#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE5_MASK (0x300000U)
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE5_SHIFT (20U)
/*! RULE5 - secure control rule5. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE5_SHIFT)) & AHB_SECURE_CTRL_PIF_HIFI4_X_MEM_RULE0_RULE5_MASK)
/*! @} */

/*! @name APB_GRP0_MEM_RULE0 - Security access rules for APB Bridge 0 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_RSTCTL0_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_RSTCTL0_RULE_SHIFT (0U)
/*! RSTCTL0_RULE - 0x4000 0000--0x4000 0FFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_RSTCTL0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_RSTCTL0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_RSTCTL0_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_CLKCTL0_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_CLKCTL0_RULE_SHIFT (4U)
/*! CLKCTL0_RULE - 0x4000 1000--0x4000 1FFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_CLKCTL0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_CLKCTL0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_CLKCTL0_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_SYSCTL0_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_SYSCTL0_RULE_SHIFT (8U)
/*! SYSCTL0_RULE - 0x4000 2000--0x4000 2FFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_SYSCTL0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_SYSCTL0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_SYSCTL0_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_IOPCTL_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_IOPCTL_RULE_SHIFT (16U)
/*! IOPCTL_RULE - 0x4000 4000--0x4000 4FFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_IOPCTL_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_IOPCTL_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_IOPCTL_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_PUFCTRL_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_PUFCTRL_RULE_SHIFT (24U)
/*! PUFCTRL_RULE - 0x4000 6000--0x4000 6FFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_PUFCTRL_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_PUFCTRL_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE0_PUFCTRL_RULE_MASK)
/*! @} */

/*! @name APB_GRP0_MEM_RULE1 - Security access rules for APB Bridge 0 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_WWDT0_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_WWDT0_RULE_SHIFT (24U)
/*! WWDT0_RULE - 0x4000 E000--0x4000 EFFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_WWDT0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_WWDT0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_WWDT0_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_UTICK_RULE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_UTICK_RULE_SHIFT (28U)
/*! UTICK_RULE - 0x4000 F000--0x4000 FFFF */
#define AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_UTICK_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_UTICK_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP0_MEM_RULE1_UTICK_RULE_MASK)
/*! @} */

/*! @name APB_GRP1_MEM_RULE0 - Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_RSTCTL1_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_RSTCTL1_RULE_SHIFT (0U)
/*! RSTCTL1_RULE - 0x4002 0000--0x4002 0FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_RSTCTL1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_RSTCTL1_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_RSTCTL1_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_CLKCTL1_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_CLKCTL1_RULE_SHIFT (4U)
/*! CLKCTL1_RULE - 0x4002 1000--0x4002 1FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_CLKCTL1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_CLKCTL1_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_CLKCTL1_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_SYSCTL1_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_SYSCTL1_RULE_SHIFT (8U)
/*! SYSCTL1_RULE - 0x4002 2000--0x4002 2FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_SYSCTL1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_SYSCTL1_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_SYSCTL1_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_GPIO_INTR_CTRL_RULE_MASK (0x300000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_GPIO_INTR_CTRL_RULE_SHIFT (20U)
/*! GPIO_INTR_CTRL_RULE - 0x4002 5000--0x4002 5FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_GPIO_INTR_CTRL_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_GPIO_INTR_CTRL_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_GPIO_INTR_CTRL_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_PERIPH_INPUT_MUX_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_PERIPH_INPUT_MUX_RULE_SHIFT (24U)
/*! PERIPH_INPUT_MUX_RULE - 0x4002 6000--0x4002 6FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_PERIPH_INPUT_MUX_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_PERIPH_INPUT_MUX_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE0_PERIPH_INPUT_MUX_RULE_MASK)
/*! @} */

/*! @name APB_GRP1_MEM_RULE1 - Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT0_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT0_RULE_SHIFT (0U)
/*! CT32BIT0_RULE - 0x4002 8000--0x4002 8FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT0_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT1_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT1_RULE_SHIFT (4U)
/*! CT32BIT1_RULE - 0x4002 9000--0x4002 9FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT1_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT1_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT2_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT2_RULE_SHIFT (8U)
/*! CT32BIT2_RULE - 0x4002 A000--0x4002 AFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT2_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT2_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT2_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT3_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT3_RULE_SHIFT (12U)
/*! CT32BIT3_RULE - 0x4002 B000--0x4002 BFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT3_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT3_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT3_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT4_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT4_RULE_SHIFT (16U)
/*! CT32BIT4_RULE - 0x4002 C000--0x4002 CFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT4_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT4_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_CT32BIT4_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_MRT_RULE_MASK (0x300000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_MRT_RULE_SHIFT (20U)
/*! MRT_RULE - 0x4002 D000--0x4002 DFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_MRT_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_MRT_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_MRT_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_WWDT1_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_WWDT1_RULE_SHIFT (24U)
/*! WWDT1_RULE - 0x4002 E000--0x4002 EFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_WWDT1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_WWDT1_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_WWDT1_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_FREQME_RULE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_FREQME_RULE_SHIFT (28U)
/*! FREQME_RULE - 0x4002 F000--0x4002 FFFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_FREQME_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_FREQME_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE1_FREQME_RULE_MASK)
/*! @} */

/*! @name APB_GRP1_MEM_RULE2 - Security access rules for APB Bridge 1 peripherals. Each APB bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_RTC_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_RTC_RULE_SHIFT (0U)
/*! RTC_RULE - 0x4003 0000--0x4003 0FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_RTC_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_RTC_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_RTC_RULE_MASK)

#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_I3C0_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_I3C0_RULE_SHIFT (24U)
/*! I3C0_RULE - 0x4003 6000--0x4003 6FFF */
#define AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_I3C0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_I3C0_RULE_SHIFT)) & AHB_SECURE_CTRL_APB_GRP1_MEM_RULE2_I3C0_RULE_MASK)
/*! @} */

/*! @name AHB_PERIPH0_SLAVE_RULE0 - Security access rules for AHB peripheral slaves area 0x40100000--0x4010FFFF */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_RULE_SHIFT (0U)
/*! HSGPIO_RULE - 0x40100000--0x40103FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_HSGPIO_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_RULE_SHIFT (4U)
/*! DMA0_RULE - 0x40104000--0x40104FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA0_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_RULE_SHIFT (8U)
/*! DMA1_RULE - 0x40105000--0x40105FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DMA1_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_RULE_SHIFT (12U)
/*! FLEXCOMM0_RULE - 0x40106000--0x40106FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM0_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_RULE_SHIFT (16U)
/*! FLEXCOMM1_RULE - 0x40107000--0x40107FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM1_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_RULE_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_RULE_SHIFT (20U)
/*! FLEXCOMM2_RULE - 0x40108000--0x40108FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM2_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_RULE_SHIFT (24U)
/*! FLEXCOMM3_RULE - 0x40109000--0x40109FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_FLEXCOMM3_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_RULE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_RULE_SHIFT (28U)
/*! DEBUG_MAILBOX_RULE - 0x4010F000--0x4010FFFF */
#define AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH0_SLAVE_RULE0_DEBUG_MAILBOX_RULE_MASK)
/*! @} */

/*! @name AIPS_BRIDGE0_MEM_RULE0 - 0x40110000--0x4011FFFF */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_M33_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_M33_RULE_SHIFT (0U)
/*! MU0_M33_RULE - 0x4011 0000--0x4011 0FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_M33_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_M33_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_M33_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_DSP_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_DSP_RULE_SHIFT (4U)
/*! MU0_DSP_RULE - 0x4011 1000--0x4011 1FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_DSP_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_DSP_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_MU0_DSP_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_SEMAPHORE_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_SEMAPHORE_RULE_SHIFT (8U)
/*! SEMAPHORE_RULE - 0x4011 2000--0x4011 2FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_SEMAPHORE_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_SEMAPHORE_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_SEMAPHORE_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_M33_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_M33_RULE_SHIFT (12U)
/*! OS_EVENT_TIMER_M33_RULE - 0x4011 3000--0x4011 3FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_M33_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_M33_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_M33_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_DSP_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_DSP_RULE_SHIFT (16U)
/*! OS_EVENT_TIMER_DSP_RULE - 0x4011 4000--0x4011 4FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_DSP_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_DSP_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE0_MEM_RULE0_OS_EVENT_TIMER_DSP_RULE_MASK)
/*! @} */

/*! @name AHB_PERIPH1_SLAVE_RULE0 - the memory map is 0x40120000--0x40127FFF */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_RULE_SHIFT (0U)
/*! CRC_RULE - Security access rules for AHB peripheral slaves area 0x40120000--0x40120FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_CRC_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC_RULE_SHIFT (4U)
/*! DMIC_RULE - 0x40121000--0x40121FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_DMIC_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_RULE_SHIFT (8U)
/*! FLEXCOMM4_RULE - 0x40122000--0x40122FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM4_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_RULE_SHIFT (12U)
/*! FLEXCOMM5_RULE - 0x40123000--0x40123FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM5_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_RULE_SHIFT (16U)
/*! FLEXCOMM6_RULE - 0x40124000--0x40124FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM6_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_RULE_MASK (0x300000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_RULE_SHIFT (20U)
/*! FLEXCOMM7_RULE - 0x40125000--0x40125FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM7_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_RULE_SHIFT (24U)
/*! FLEXCOMM14_RULE - 0x40126000--0x40126FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM14_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_RULE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_RULE_SHIFT (28U)
/*! FLEXCOMM15_RULE - 0x40127000--0x40127FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH1_SLAVE_RULE0_FLEXCOMM15_RULE_MASK)
/*! @} */

/*! @name AIPS_BRIDGE1_MEM_RULE0 - Security access rules for AIPS Bridge peripherals. Each AIPS bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE0_SHIFT (0U)
/*! OTP_RULE0 - 0x4013 0000--0x4013 0FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE0_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE0_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE1_SHIFT (4U)
/*! OTP_RULE1 - 0x4013 1000--0x4013 1FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE1_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE1_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE2_SHIFT (8U)
/*! OTP_RULE2 - 0x4013 2000--0x4013 2FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE2_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE2_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE3_SHIFT (12U)
/*! OTP_RULE3 - 0x4013 3000--0x4013 3FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE3_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_OTP_RULE3_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_FLEXSPI_AND_OTFAD_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_FLEXSPI_AND_OTFAD_RULE_SHIFT (16U)
/*! FLEXSPI_AND_OTFAD_RULE - 0x4013 4000--0x4013 4FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_FLEXSPI_AND_OTFAD_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_FLEXSPI_AND_OTFAD_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_FLEXSPI_AND_OTFAD_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO0_RULE_MASK (0x3000000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO0_RULE_SHIFT (24U)
/*! SDIO0_RULE - 0x4013 6000--0x4013 6FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO0_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO0_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO1_RULE_MASK (0x30000000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO1_RULE_SHIFT (28U)
/*! SDIO1_RULE - 0x4013 7000--0x4013 7FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO1_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO1_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE0_SDIO1_RULE_MASK)
/*! @} */

/*! @name AIPS_BRIDGE1_MEM_RULE1 - Security access rules for AIPS Bridge peripherals. Each AIPS bridge sector is 4 Kbytes, there're 16 sectors in total. */
/*! @{ */

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_RNG_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_RNG_RULE_SHIFT (0U)
/*! RNG_RULE - 0x4013 8000--0x4013 8FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_RNG_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_RNG_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_RNG_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ACMP0_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ACMP0_RULE_SHIFT (4U)
/*! ACMP0_RULE - 0x4013 9000--0x4013 9FFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ACMP0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ACMP0_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ACMP0_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ADC0_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ADC0_RULE_SHIFT (8U)
/*! ADC0_RULE - 0x4013 A000--0x4013 AFFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ADC0_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ADC0_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_ADC0_RULE_MASK)

#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_USB_HS_PHY_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_USB_HS_PHY_RULE_SHIFT (12U)
/*! USB_HS_PHY_RULE - 0x4013 B000--0x4013 BFFF */
#define AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_USB_HS_PHY_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_USB_HS_PHY_RULE_SHIFT)) & AHB_SECURE_CTRL_AIPS_BRIDGE1_MEM_RULE1_USB_HS_PHY_RULE_MASK)
/*! @} */

/*! @name AHB_PERIPH2_SLAVE_RULE0 - Security access rules for AHB peripheral slaves area 0x40140000--0x4014BFFF */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_RULE_SHIFT (0U)
/*! USB_HS_RAM_RULE - 0x40140000--0x40143FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_RAM_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_RULE_SHIFT (4U)
/*! USB_HS_DEV_RULE - 0x40144000--0x40144FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_DEV_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_RULE_SHIFT (8U)
/*! USB_HS_HOST_RULE - 0x40145000--0x40145FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_USB_HS_HOST_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_RULE_SHIFT (12U)
/*! SCT_RULE - 0x40146000--0x40146FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH2_SLAVE_RULE0_SCT_RULE_MASK)
/*! @} */

/*! @name SECURITY_CTRL_MEM_RULE0 - 0x40148000--0x4014BFFF */
/*! @{ */

#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE0_MASK (0x3U)
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - secure control rule0. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE0_SHIFT)) & AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE0_MASK)

#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE1_MASK (0x30U)
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - secure control rule0. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE1_SHIFT)) & AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE1_MASK)

#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE2_MASK (0x300U)
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - secure control rule0. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE2_SHIFT)) & AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE2_MASK)

#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE3_MASK (0x3000U)
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - secure control rule0. it can be set when check_reg's write_lock is '0' */
#define AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE3_SHIFT)) & AHB_SECURE_CTRL_SECURITY_CTRL_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name AHB_PERIPH3_SLAVE_RULE0 - Security access rules for AHB peripheral slaves area 0x40150000--0x40158FFF */
/*! @{ */

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_PQ_COPRO_RULE_MASK (0x3U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_PQ_COPRO_RULE_SHIFT (0U)
/*! PQ_COPRO_RULE - 0x40150000--0x40150FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_PQ_COPRO_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_PQ_COPRO_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_PQ_COPRO_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_COPRO_RULE_MASK (0x30U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_COPRO_RULE_SHIFT (4U)
/*! CASPER_COPRO_RULE - 0x40151000--0x40151FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_COPRO_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_COPRO_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_COPRO_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_RULE_MASK (0x300U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_RULE_SHIFT (8U)
/*! CASPER_RAM_RULE - 0x40152000--0x40152FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_CASPER_RAM_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_RULE_MASK (0x3000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_RULE_SHIFT (12U)
/*! SECURE_GPIO_RULE - 0x40154000--0x40157FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_SECURE_GPIO_RULE_MASK)

#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_RULE_MASK (0x30000U)
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_RULE_SHIFT (16U)
/*! HASH_RULE - 0x40158000--0x40158FFF */
#define AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_RULE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_RULE_SHIFT)) & AHB_SECURE_CTRL_AHB_PERIPH3_SLAVE_RULE0_HASH_RULE_MASK)
/*! @} */

/*! @name SEC_VIO_ADDR - most recent security violation address for AHB layer n */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK (0xFFFFFFFFU)
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT (0U)
/*! SEC_VIO_ADDR - security violation address for AHB layer */
#define AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_ADDR(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/*! @name SEC_VIO_MISC_INFO - most recent security violation miscellaneous information for AHB layer n */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - security violation access read/write indicator, 0: read, 1: write */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - security violation access data/code indicator, 0: code, 1 */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - bit [5:4]: master sec level and privilege level bit [7:6]: anti-pol value for master sec level and privilege level */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0xF00U)
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - security violation master number */
#define AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/*! @name SEC_VIO_INFO_VALID - security violation address/information registers valid flags */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - violation information valid flag for AHB layer 0. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - violation information valid flag for AHB layer 1. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - violation information valid flag for AHB layer 2. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - violation information valid flag for AHB layer 3. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - violation information valid flag for AHB layer 4. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - violation information valid flag for AHB layer 5. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - violation information valid flag for AHB layer 6. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - violation information valid flag for AHB layer 7. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - violation information valid flag for AHB layer 8. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - violation information valid flag for AHB layer 9. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - violation information valid flag for AHB layer 10. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - violation information valid flag for AHB layer 11. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - violation information valid flag for AHB layer 12. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - violation information valid flag for AHB layer 13. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - violation information valid flag for AHB layer 14. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - violation information valid flag for AHB layer 15. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - violation information valid flag for AHB layer 16. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)

#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT (17U)
/*! VIO_INFO_VALID17 - violation information valid flag for AHB layer 17. 0: not valid. 1: valid (violation occurred). Write 1 to clear. */
#define AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT)) & AHB_SECURE_CTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK0 - Secure GPIO mask for port 0 pins. This register is used to block leakage of Secure interface (GPIOs, I2C, UART configured as secure peripherals) pin states to non-secure world. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK0_PIO0_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK1 - Secure GPIO mask for port 1 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK1_PIO1_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK2 - Secure GPIO mask for port 2 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK2_PIO2_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK3 - Secure GPIO mask for port 3 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK3_PIO3_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK4 - Secure GPIO mask for port 4 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK4_PIO4_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK5 - Secure GPIO mask for port 5 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK5_PIO5_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK6 - Secure GPIO mask for port 6 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK6_PIO6_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GPIO_MASK7 - Secure GPIO mask for port 7 pins. */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN0_SEC_MASK_MASK (0x1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN0_SEC_MASK_SHIFT (0U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN0_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN0_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN1_SEC_MASK_MASK (0x2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN1_SEC_MASK_SHIFT (1U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN1_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN1_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN2_SEC_MASK_MASK (0x4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN2_SEC_MASK_SHIFT (2U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN2_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN2_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN3_SEC_MASK_MASK (0x8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN3_SEC_MASK_SHIFT (3U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN3_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN3_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN4_SEC_MASK_MASK (0x10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN4_SEC_MASK_SHIFT (4U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN4_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN4_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN5_SEC_MASK_SHIFT (5U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN6_SEC_MASK_SHIFT (6U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN7_SEC_MASK_SHIFT (7U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN8_SEC_MASK_SHIFT (8U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN9_SEC_MASK_SHIFT (9U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN10_SEC_MASK_SHIFT (10U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN11_SEC_MASK_SHIFT (11U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN12_SEC_MASK_SHIFT (12U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN13_SEC_MASK_SHIFT (13U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN14_SEC_MASK_SHIFT (14U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN15_SEC_MASK_SHIFT (15U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN16_SEC_MASK_SHIFT (16U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN17_SEC_MASK_SHIFT (17U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN18_SEC_MASK_SHIFT (18U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN19_SEC_MASK_SHIFT (19U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN20_SEC_MASK_SHIFT (20U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN21_SEC_MASK_SHIFT (21U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN22_SEC_MASK_SHIFT (22U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN23_SEC_MASK_SHIFT (23U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN24_SEC_MASK_SHIFT (24U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN25_SEC_MASK_SHIFT (25U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN26_SEC_MASK_SHIFT (26U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN27_SEC_MASK_SHIFT (27U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN28_SEC_MASK_SHIFT (28U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN29_SEC_MASK_SHIFT (29U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN30_SEC_MASK_SHIFT (30U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN31_SEC_MASK_SHIFT (31U)
#define AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_GPIO_MASK7_PIO7_PIN31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_DSP_INT_MASK - secure general purpose register 8 used to mask interrupts to DSP for security purpose */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR5_SEC_MASK_MASK (0x20U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR5_SEC_MASK_SHIFT (5U)
/*! DSP_INTR5_SEC_MASK - 0: INTR5 is invisible to DSP, 1: INTR5 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR5_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR5_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR6_SEC_MASK_MASK (0x40U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR6_SEC_MASK_SHIFT (6U)
/*! DSP_INTR6_SEC_MASK - 0: INTR6 is invisible to DSP, 1: INTR6 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR6_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR6_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR7_SEC_MASK_MASK (0x80U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR7_SEC_MASK_SHIFT (7U)
/*! DSP_INTR7_SEC_MASK - 0: INTR7 is invisible to DSP, 1: INTR7 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR7_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR7_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR8_SEC_MASK_MASK (0x100U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR8_SEC_MASK_SHIFT (8U)
/*! DSP_INTR8_SEC_MASK - 0: INTR8 is invisible to DSP, 1: INTR8 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR8_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR8_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR9_SEC_MASK_MASK (0x200U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR9_SEC_MASK_SHIFT (9U)
/*! DSP_INTR9_SEC_MASK - 0: INTR9 is invisible to DSP, 1: INTR9 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR9_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR9_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR10_SEC_MASK_MASK (0x400U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR10_SEC_MASK_SHIFT (10U)
/*! DSP_INTR10_SEC_MASK - 0: INTR10 is invisible to DSP, 1: INTR10 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR10_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR10_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR11_SEC_MASK_MASK (0x800U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR11_SEC_MASK_SHIFT (11U)
/*! DSP_INTR11_SEC_MASK - 0: INTR11 is invisible to DSP, 1: INTR11 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR11_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR11_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR12_SEC_MASK_MASK (0x1000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR12_SEC_MASK_SHIFT (12U)
/*! DSP_INTR12_SEC_MASK - 0: INTR12 is invisible to DSP, 1: INTR12 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR12_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR12_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR13_SEC_MASK_MASK (0x2000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR13_SEC_MASK_SHIFT (13U)
/*! DSP_INTR13_SEC_MASK - 0: INTR13 is invisible to DSP, 1: INTR13 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR13_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR13_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR14_SEC_MASK_MASK (0x4000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR14_SEC_MASK_SHIFT (14U)
/*! DSP_INTR14_SEC_MASK - 0: INTR14 is invisible to DSP, 1: INTR14 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR14_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR14_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR15_SEC_MASK_MASK (0x8000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR15_SEC_MASK_SHIFT (15U)
/*! DSP_INTR15_SEC_MASK - 0: INTR15 is invisible to DSP, 1: INTR15 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR15_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR15_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR16_SEC_MASK_MASK (0x10000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR16_SEC_MASK_SHIFT (16U)
/*! DSP_INTR16_SEC_MASK - 0: INTR16 is invisible to DSP, 1: INTR16 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR16_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR16_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR17_SEC_MASK_MASK (0x20000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR17_SEC_MASK_SHIFT (17U)
/*! DSP_INTR17_SEC_MASK - 0: INTR17 is invisible to DSP, 1: INTR17 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR17_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR17_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR18_SEC_MASK_MASK (0x40000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR18_SEC_MASK_SHIFT (18U)
/*! DSP_INTR18_SEC_MASK - 0: INTR18 is invisible to DSP, 1: INTR18 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR18_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR18_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR19_SEC_MASK_MASK (0x80000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR19_SEC_MASK_SHIFT (19U)
/*! DSP_INTR19_SEC_MASK - 0: INTR19 is invisible to DSP, 1: INTR19 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR19_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR19_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR20_SEC_MASK_MASK (0x100000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR20_SEC_MASK_SHIFT (20U)
/*! DSP_INTR20_SEC_MASK - 0: INTR20 is invisible to DSP, 1: INTR20 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR20_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR20_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR21_SEC_MASK_MASK (0x200000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR21_SEC_MASK_SHIFT (21U)
/*! DSP_INTR21_SEC_MASK - 0: INTR21 is invisible to DSP, 1: INTR21 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR21_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR21_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR22_SEC_MASK_MASK (0x400000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR22_SEC_MASK_SHIFT (22U)
/*! DSP_INTR22_SEC_MASK - 0: INTR22 is invisible to DSP, 1: INTR22 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR22_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR22_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR23_SEC_MASK_MASK (0x800000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR23_SEC_MASK_SHIFT (23U)
/*! DSP_INTR23_SEC_MASK - 0: INTR23 is invisible to DSP, 1: INTR23 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR23_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR23_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR24_SEC_MASK_MASK (0x1000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR24_SEC_MASK_SHIFT (24U)
/*! DSP_INTR24_SEC_MASK - 0: INTR24 is invisible to DSP, 1: INTR24 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR24_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR24_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR25_SEC_MASK_MASK (0x2000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR25_SEC_MASK_SHIFT (25U)
/*! DSP_INTR25_SEC_MASK - 0: INTR25 is invisible to DSP, 1: INTR25 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR25_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR25_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR26_SEC_MASK_MASK (0x4000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR26_SEC_MASK_SHIFT (26U)
/*! DSP_INTR26_SEC_MASK - 0: INTR26 is invisible to DSP, 1: INTR26 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR26_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR26_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR27_SEC_MASK_MASK (0x8000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR27_SEC_MASK_SHIFT (27U)
/*! DSP_INTR27_SEC_MASK - 0: INTR27 is invisible to DSP, 1: INTR27 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR27_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR27_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR28_SEC_MASK_MASK (0x10000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR28_SEC_MASK_SHIFT (28U)
/*! DSP_INTR28_SEC_MASK - 0: INTR28 is invisible to DSP, 1: INTR28 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR28_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR28_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR29_SEC_MASK_MASK (0x20000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR29_SEC_MASK_SHIFT (29U)
/*! DSP_INTR29_SEC_MASK - 0: INTR29 is invisible to DSP, 1: INTR29 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR29_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR29_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR30_SEC_MASK_MASK (0x40000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR30_SEC_MASK_SHIFT (30U)
/*! DSP_INTR30_SEC_MASK - 0: INTR30 is invisible to DSP, 1: INTR30 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR30_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR30_SEC_MASK_MASK)

#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR31_SEC_MASK_MASK (0x80000000U)
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR31_SEC_MASK_SHIFT (31U)
/*! DSP_INTR31_SEC_MASK - 0: INTR31 is invisible to DSP, 1: INTR31 is visible to DSP */
#define AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR31_SEC_MASK_SHIFT)) & AHB_SECURE_CTRL_SEC_DSP_INT_MASK_DSP_INTR31_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_MASK_LOCK - sec_gp_reg write-lock bits */
/*! @{ */

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT (0U)
/*! SEC_GPIO_MASK0_LOCK - SEC_GPIO_MASK0 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK0_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_MASK (0xCU)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT (2U)
/*! SEC_GPIO_MASK1_LOCK - SEC_GPIO_MASK1 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK1_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_MASK (0x30U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT (4U)
/*! SEC_GPIO_MASK2_LOCK - SEC_GPIO_MASK2 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK2_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_MASK (0xC0U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT (6U)
/*! SEC_GPIO_MASK3_LOCK - SEC_GPIO_MASK3 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK3_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_MASK (0x300U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT (8U)
/*! SEC_GPIO_MASK4_LOCK - SEC_GPIO_MASK4 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK4_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_MASK (0xC00U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT (10U)
/*! SEC_GPIO_MASK5_LOCK - SEC_GPIO_MASK5 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK5_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_MASK (0x3000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT (12U)
/*! SEC_GPIO_MASK6_LOCK - SEC_GPIO_MASK6 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK6_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_MASK (0xC000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT (14U)
/*! SEC_GPIO_MASK7_LOCK - SEC_GPIO_MASK7 register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_GPIO_MASK7_LOCK_MASK)

#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_LOCK_MASK (0x30000U)
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_LOCK_SHIFT (16U)
/*! SEC_DSP_INT_LOCK - SEC_DSP_INT_MASK register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_LOCK_SHIFT)) & AHB_SECURE_CTRL_SEC_MASK_LOCK_SEC_DSP_INT_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - master secure level register */
/*! @{ */

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_POWERQUAD_SEC_MASK (0x30U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_POWERQUAD_SEC_SHIFT (4U)
/*! POWERQUAD_SEC - POWERQUAD master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_POWERQUAD_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_POWERQUAD_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_POWERQUAD_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SEC_MASK (0xC0U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SEC_SHIFT (6U)
/*! DSP_SEC - DSP master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DSP_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SEC_MASK (0x300U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SEC_SHIFT (8U)
/*! DMA0_SEC - DMA0 master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA0_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SEC_MASK (0xC00U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SEC_SHIFT (10U)
/*! DMA1_SEC - DMA1 master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_DMA1_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SEC_MASK (0x3000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SEC_SHIFT (12U)
/*! SDIO0_SEC - SDIO0 master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO0_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SEC_MASK (0xC000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SEC_SHIFT (14U)
/*! SDIO1_SEC - SDIO1 master secure level control.
 *  0b00..Non-secure and Non-priviledge user access allowed.
 *  0b01..Non-secure and Privilege access allowed.
 *  0b10..Secure and Non-priviledge user access allowed.
 *  0b11..Secure and Priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_SDIO1_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_LOCK - MASTER_SEC_LEVEL register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL_ANTI_POL - master secure level anti-pole register */
/*! @{ */

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_POWERQUAD_SEC_MASK (0x30U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_POWERQUAD_SEC_SHIFT (4U)
/*! POWERQUAD_SEC - POWERQUAD master secure level control anti-pole value (i.e It must be written
 *    with the inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_POWERQUAD_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_POWERQUAD_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_POWERQUAD_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DSP_SEC_MASK (0xC0U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DSP_SEC_SHIFT (6U)
/*! DSP_SEC - DSP master secure level control anti-pole value (i.e It must be written with the
 *    inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DSP_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DSP_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DSP_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA0_SEC_MASK (0x300U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA0_SEC_SHIFT (8U)
/*! DMA0_SEC - DMA0 master secure level control anti-pole value (i.e It must be written with the
 *    inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA0_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA0_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA0_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA1_SEC_MASK (0xC00U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA1_SEC_SHIFT (10U)
/*! DMA1_SEC - DMA1 master secure level control anti-pole value (i.e It must be written with the
 *    inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA1_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA1_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_DMA1_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO0_SEC_MASK (0x3000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO0_SEC_SHIFT (12U)
/*! SDIO0_SEC - SDIO0 master secure level control anti-pole value (i.e It must be written with the
 *    inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO0_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO0_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO0_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO1_SEC_MASK (0xC000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO1_SEC_SHIFT (14U)
/*! SDIO1_SEC - SDIO1 master secure level control anti-pole value (i.e It must be written with the
 *    inverted value of the corresponding field in master_sec_reg).
 *  0b00..Secure and Priviledge user access allowed.
 *  0b01..Secure and Non-priviledge user access allowed.
 *  0b10..Non-secure and Privilege access allowed.
 *  0b11..Non-secure and Non-priviledge user access allowed.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO1_SEC(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO1_SEC_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_SDIO1_SEC_MASK)

#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_MASTER_SEC_LEVEL_ANTI_POLE_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_MASTER_SEC_LEVEL_ANTI_POLE_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_ANTI_POLE_LOCK - MASTER_SEC_LEVEL_ANTI_POL register write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_MASTER_SEC_LEVEL_ANTI_POLE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_MASTER_SEC_LEVEL_ANTI_POLE_LOCK_SHIFT)) & AHB_SECURE_CTRL_MASTER_SEC_LEVEL_ANTI_POL_MASTER_SEC_LEVEL_ANTI_POLE_LOCK_MASK)
/*! @} */

/*! @name CM33_LOCK_REG - m33 lock control register */
/*! @{ */

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_MASK (0x3U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT (0U)
/*! LOCK_NS_VTOR - m33 LOCKNSVTOR write-lock.
 *  0b01..Restrictive mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_MASK (0xCU)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT (2U)
/*! LOCK_NS_MPU - m33 LOCKNSMPU write-lock.
 *  0b01..Restricted mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_MASK (0x30U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_SHIFT (4U)
/*! LOCK_S_VTOR - m33 LOCKSVTOR write-lock.
 *  0b01..Restricted mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_VTOR_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_MASK (0xC0U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_SHIFT (6U)
/*! LOCK_S_MPU - m33 LOCKSMPU write-lock.
 *  0b01..Restricted mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_S_MPU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_MASK (0x300U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_SHIFT (8U)
/*! LOCK_SAU - m33 LOCKSAU write-lock.
 *  0b01..Restricted mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_LOCK_SAU_MASK)

#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK (0xC0000000U)
#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT (30U)
/*! CM33_LOCK_REG_LOCK - CM33_LOCK_REG_LOCK write-lock.
 *  0b01..Restricted mode.
 *  0b10..Writable.
 */
#define AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT)) & AHB_SECURE_CTRL_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - secure control duplicate register */
/*! @{ */

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write lock.
 *  0b01..Restrictive mode.
 *  0b10..Secure control registers can be written.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - AHB bus matrix enable secure checking.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - AHB bus matrix enable secure privilege check.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - AHB bus matrix enable non-secure privilege check.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable secure violation abort.
 *  0b01..Violation assert secure_violation_irq.
 *  0b10..Violation causes abort.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK (0xC00U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT (10U)
/*! DISABLE_SIMPLE_MASTER_STRICT_MODE - Disable simple master strict mode.
 *  0b01..Simple master in tier mode.
 *  0b10..Simple master in strict mode.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK (0x3000U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT (12U)
/*! DISABLE_SMART_MASTER_STRICT_MODE - Disable smart master strict mode.
 *  0b01..Smart master in tier mode.
 *  0b10..Smart master in strict mode.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - Disable IDAU.
 *  0b01..IDAU is disabled.
 *  0b10..IDAU is enabled.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - secure control register */
/*! @{ */

#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_MASK (0x3U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write lock.
 *  0b01..Restrictive mode.
 *  0b10..Secure control registers can be written.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - AHB bus matrix enable secure checking.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - AHB bus matrix enable secure privilege check.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - AHB bus matrix enable non-secure privilege check.
 *  0b01..Restrictive mode.
 *  0b10..Disable check.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable secure violation abort.
 *  0b01..Violation assert secure_violation_irq.
 *  0b10..Violation causes abort.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK (0xC00U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT (10U)
/*! DISABLE_SIMPLE_MASTER_STRICT_MODE - Disable simple master strict mode.
 *  0b01..Simple master in tier mode.
 *  0b10..Simple master in strict mode.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SIMPLE_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK (0x3000U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT (12U)
/*! DISABLE_SMART_MASTER_STRICT_MODE - Disable smart master strict mode.
 *  0b01..Smart master in tier mode.
 *  0b10..Smart master in strict mode.
 */
#define AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_SHIFT)) & AHB_SECURE_CTRL_MISC_CTRL_REG_DISABLE_SMART_MASTER_STRICT_MODE_MASK)

#define AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_MASK (0xC000U)
#define AHB_SECURE_CTRL_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - Disable IDAU.
 *  0b01..IDAU is disabled.
 *  0b10..IDAU is enabled.
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

