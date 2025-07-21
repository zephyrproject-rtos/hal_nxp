/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SECTRL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SECTRL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SECTRL
 *
 * CMSIS Peripheral Access Layer for SECTRL
 */

#if !defined(PERI_SECTRL_H_)
#define PERI_SECTRL_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- SECTRL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECTRL_Peripheral_Access_Layer SECTRL Peripheral Access Layer
 * @{
 */

/** SECTRL - Size of Registers Arrays */
#define SECTRL_ROM_MEM_RULE_COUNT                 4u
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_COUNT    4u
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_COUNT  4u
#define SECTRL_SEC_VIO_ADDRN_COUNT                32u
#define SECTRL_SEC_VIO_MISC_INFON_COUNT           32u
#define SECTRL_SEC_GPIO_MASKN_COUNT               3u
#define SECTRL_CM33_LOCK_REGN_COUNT               3u

/** SECTRL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASH_MEM_RULE;                    /**< Flash Memory Rule, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t ROM_MEM_RULE[SECTRL_ROM_MEM_RULE_COUNT]; /**< ROM Memory Rule, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __IO uint32_t RAMX_MEM_RULE0;                    /**< RAMX Memory Rule 0, offset: 0x40 */
       uint8_t RESERVED_3[28];
  __IO uint32_t FLEXSPI0_REGION0_MEM_RULE[SECTRL_FLEXSPI0_REGION0_MEM_RULE_COUNT]; /**< FLEXSPI0 Region 0 Memory Rule, array offset: 0x60, array step: 0x4 */
  struct {                                         /* offset: 0x70, array step: 0x10 */
    __IO uint32_t FLEXSPI0_REGION_MEM_RULE0;         /**< FLEXSPI0 Region 1 Memory Rule 0..FLEXSPI0 Region 4 Memory Rule 0, array offset: 0x70, array step: 0x10 */
         uint8_t RESERVED_0[12];
  } FLEXSPI0_REGION1_4_MEM_RULE[SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_COUNT];
       uint8_t RESERVED_4[16];
  __IO uint32_t RAM00_MEM_RULE0;                   /**< SRAM0 Partition 0 Memory Rule, offset: 0xC0 */
       uint8_t RESERVED_5[28];
  __IO uint32_t RAM10_MEM_RULE0;                   /**< SRAM1 Partition 0 Memory Rule, offset: 0xE0 */
       uint8_t RESERVED_6[28];
  __IO uint32_t RAM20_MEM_RULE0;                   /**< SRAM2 Partition 0 Memory Rule, offset: 0x100 */
       uint8_t RESERVED_7[28];
  __IO uint32_t RAM30_MEM_RULE0;                   /**< SRAM Partition 0 Memory Rule, offset: 0x120 */
       uint8_t RESERVED_8[28];
  __IO uint32_t RAM40_MEM_RULE0;                   /**< SRAM4 Partition 0 Memory Rule, offset: 0x140 */
       uint8_t RESERVED_9[28];
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE0;   /**< APB Bridge Group 0 Memory Rule 0, offset: 0x160 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE1;   /**< APB Bridge Group 0 Memory Rule 1, offset: 0x164 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE2;   /**< APB Bridge Group 0 Rule 2, offset: 0x168 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE3;   /**< APB Bridge Group 0 Memory Rule 3, offset: 0x16C */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE0;   /**< APB Bridge Group 1 Memory Rule 0, offset: 0x170 */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE1;   /**< APB Bridge Group 1 Memory Rule 1, offset: 0x174 */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE2;   /**< APB Bridge Group 1 Memory Rule 2, offset: 0x178 */
  __IO uint32_t APB_PERIPHERAL_GROUP1_MEM_RULE3;   /**< APB Bridge Group 1 Memory Rule 3, offset: 0x17C */
       uint8_t RESERVED_10[16];
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0; /**< AHB Peripheral 0 Slave Port9 Rule 0, offset: 0x190 */
  __IO uint32_t AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1; /**< AHB Peripheral 0 Slave Port 9 Rule 1, offset: 0x194 */
       uint8_t RESERVED_11[8];
  __IO uint32_t AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0; /**< AHB Peripheral 1 Slave Port 10 Slave Rule 0, offset: 0x1A0 */
       uint8_t RESERVED_12[12];
  __IO uint32_t AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0; /**< AHB Peripheral 2 Slave Port 11 Slave Rule 0, offset: 0x1B0 */
       uint8_t RESERVED_13[12];
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0; /**< AHB Secure Control Peripheral Memory Rule 0, offset: 0x1C0 */
       uint8_t RESERVED_14[28];
  __IO uint32_t AIPS_BRIDGE_GROUP0_RULE0;          /**< AIPS Bridge Group 0 Rule 0, offset: 0x1E0 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_RULE1;          /**< AIPS Bridge Group 0 Rule 1, offset: 0x1E4 */
       uint8_t RESERVED_15[24];
  __IO uint32_t AIPS_BRIDGE_GROUP1_RULE0;          /**< AIPS Bridge Group 1 Rule 0, offset: 0x200 */
  __IO uint32_t AIPS_BRIDGE_GROUP1_RULE1;          /**< AIPS Bridge Group 1 Rule 1, offset: 0x204 */
       uint8_t RESERVED_16[3064];
  __I  uint32_t SEC_VIO_ADDR[SECTRL_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
  __I  uint32_t SEC_VIO_MISC_INFO[SECTRL_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_17[124];
  __IO uint32_t SEC_GPIO_MASK[SECTRL_SEC_GPIO_MASKN_COUNT]; /**< GPIO Mask for Port 0..GPIO Mask for Port 2, array offset: 0xF80, array step: 0x4 */
  __IO uint32_t SEC_GPIO_MASK3;                    /**< GPIO Mask for Port 3, offset: 0xF8C */
       uint8_t RESERVED_18[44];
  __IO uint32_t SEC_GP_REG_LOCK;                   /**< Secure Mask Lock, offset: 0xFBC */
       uint8_t RESERVED_19[16];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_20[20];
  __IO uint32_t CM33_LOCK_REG[SECTRL_CM33_LOCK_REGN_COUNT]; /**< Miscellaneous CPU0 Control Signals, array offset: 0xFEC, array step: 0x4 */
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} SECTRL_Type;

/* ----------------------------------------------------------------------------
   -- SECTRL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SECTRL_Register_Masks SECTRL Register Masks
 * @{
 */

/*! @name FLASH_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define SECTRL_FLASH_MEM_RULE_RULE0_MASK         (0x3U)
#define SECTRL_FLASH_MEM_RULE_RULE0_SHIFT        (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE0(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE0_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE0_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE1_MASK         (0x30U)
#define SECTRL_FLASH_MEM_RULE_RULE1_SHIFT        (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE1(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE1_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE1_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE2_MASK         (0x300U)
#define SECTRL_FLASH_MEM_RULE_RULE2_SHIFT        (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE2(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE2_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE2_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE3_MASK         (0x3000U)
#define SECTRL_FLASH_MEM_RULE_RULE3_SHIFT        (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE3(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE3_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE3_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE4_MASK         (0x30000U)
#define SECTRL_FLASH_MEM_RULE_RULE4_SHIFT        (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE4(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE4_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE4_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE5_MASK         (0x300000U)
#define SECTRL_FLASH_MEM_RULE_RULE5_SHIFT        (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE5(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE5_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE5_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE6_MASK         (0x3000000U)
#define SECTRL_FLASH_MEM_RULE_RULE6_SHIFT        (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE6(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE6_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE6_MASK)

#define SECTRL_FLASH_MEM_RULE_RULE7_MASK         (0x30000000U)
#define SECTRL_FLASH_MEM_RULE_RULE7_SHIFT        (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLASH_MEM_RULE_RULE7(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_FLASH_MEM_RULE_RULE7_SHIFT)) & SECTRL_FLASH_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name ROM_MEM_RULE - ROM Memory Rule */
/*! @{ */

#define SECTRL_ROM_MEM_RULE_RULE0_MASK           (0x3U)
#define SECTRL_ROM_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE0_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE0_MASK)

#define SECTRL_ROM_MEM_RULE_RULE1_MASK           (0x30U)
#define SECTRL_ROM_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE1_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE1_MASK)

#define SECTRL_ROM_MEM_RULE_RULE2_MASK           (0x300U)
#define SECTRL_ROM_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE2_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE2_MASK)

#define SECTRL_ROM_MEM_RULE_RULE3_MASK           (0x3000U)
#define SECTRL_ROM_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE3_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE3_MASK)

#define SECTRL_ROM_MEM_RULE_RULE4_MASK           (0x30000U)
#define SECTRL_ROM_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE4_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE4_MASK)

#define SECTRL_ROM_MEM_RULE_RULE5_MASK           (0x300000U)
#define SECTRL_ROM_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE5_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE5_MASK)

#define SECTRL_ROM_MEM_RULE_RULE6_MASK           (0x3000000U)
#define SECTRL_ROM_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE6_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE6_MASK)

#define SECTRL_ROM_MEM_RULE_RULE7_MASK           (0x30000000U)
#define SECTRL_ROM_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_ROM_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << SECTRL_ROM_MEM_RULE_RULE7_SHIFT)) & SECTRL_ROM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMX_MEM_RULE0 - RAMX Memory Rule 0 */
/*! @{ */

#define SECTRL_RAMX_MEM_RULE0_RULE0_MASK         (0x3U)
#define SECTRL_RAMX_MEM_RULE0_RULE0_SHIFT        (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAMX_MEM_RULE0_RULE0(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_RAMX_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAMX_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAMX_MEM_RULE0_RULE1_MASK         (0x30U)
#define SECTRL_RAMX_MEM_RULE0_RULE1_SHIFT        (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAMX_MEM_RULE0_RULE1(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_RAMX_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAMX_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAMX_MEM_RULE0_RULE2_MASK         (0x300U)
#define SECTRL_RAMX_MEM_RULE0_RULE2_SHIFT        (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAMX_MEM_RULE0_RULE2(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_RAMX_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAMX_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAMX_MEM_RULE0_RULE3_MASK         (0x3000U)
#define SECTRL_RAMX_MEM_RULE0_RULE3_SHIFT        (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAMX_MEM_RULE0_RULE3(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_RAMX_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAMX_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION0_MEM_RULE - FLEXSPI0 Region 0 Memory Rule */
/*! @{ */

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE0_MASK (0x3U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE0_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE0_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE1_MASK (0x30U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE1_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE1_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE2_MASK (0x300U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE2_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE2_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE3_MASK (0x3000U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE3_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE3_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE4_MASK (0x30000U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE4(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE4_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE4_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE5_MASK (0x300000U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE5(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE5_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE5_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE6_MASK (0x3000000U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE6(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE6_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE6_MASK)

#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE7_MASK (0x30000000U)
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE7(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE7_SHIFT)) & SECTRL_FLEXSPI0_REGION0_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 - FLEXSPI0 Region 1 Memory Rule 0..FLEXSPI0 Region 4 Memory Rule 0 */
/*! @{ */

#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK (0x3U)
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_SHIFT)) & SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE0_MASK)

#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK (0x30U)
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_SHIFT)) & SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE1_MASK)

#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK (0x300U)
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_SHIFT)) & SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE2_MASK)

#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK (0x3000U)
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_SHIFT)) & SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_RULE3_MASK)
/*! @} */

/* The count of SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0 */
#define SECTRL_FLEXSPI0_REGION1_4_MEM_RULE_FLEXSPI0_REGION_MEM_RULE0_COUNT (4U)

/*! @name RAM00_MEM_RULE0 - SRAM0 Partition 0 Memory Rule */
/*! @{ */

#define SECTRL_RAM00_MEM_RULE0_RULE0_MASK        (0x3U)
#define SECTRL_RAM00_MEM_RULE0_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM00_MEM_RULE0_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM00_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAM00_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAM00_MEM_RULE0_RULE1_MASK        (0x30U)
#define SECTRL_RAM00_MEM_RULE0_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM00_MEM_RULE0_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM00_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAM00_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAM00_MEM_RULE0_RULE2_MASK        (0x300U)
#define SECTRL_RAM00_MEM_RULE0_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM00_MEM_RULE0_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM00_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAM00_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAM00_MEM_RULE0_RULE3_MASK        (0x3000U)
#define SECTRL_RAM00_MEM_RULE0_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM00_MEM_RULE0_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM00_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAM00_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name RAM10_MEM_RULE0 - SRAM1 Partition 0 Memory Rule */
/*! @{ */

#define SECTRL_RAM10_MEM_RULE0_RULE0_MASK        (0x3U)
#define SECTRL_RAM10_MEM_RULE0_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM10_MEM_RULE0_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM10_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAM10_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAM10_MEM_RULE0_RULE1_MASK        (0x30U)
#define SECTRL_RAM10_MEM_RULE0_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM10_MEM_RULE0_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM10_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAM10_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAM10_MEM_RULE0_RULE2_MASK        (0x300U)
#define SECTRL_RAM10_MEM_RULE0_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM10_MEM_RULE0_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM10_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAM10_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAM10_MEM_RULE0_RULE3_MASK        (0x3000U)
#define SECTRL_RAM10_MEM_RULE0_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM10_MEM_RULE0_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM10_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAM10_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name RAM20_MEM_RULE0 - SRAM2 Partition 0 Memory Rule */
/*! @{ */

#define SECTRL_RAM20_MEM_RULE0_RULE0_MASK        (0x3U)
#define SECTRL_RAM20_MEM_RULE0_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM20_MEM_RULE0_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM20_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAM20_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAM20_MEM_RULE0_RULE1_MASK        (0x30U)
#define SECTRL_RAM20_MEM_RULE0_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM20_MEM_RULE0_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM20_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAM20_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAM20_MEM_RULE0_RULE2_MASK        (0x300U)
#define SECTRL_RAM20_MEM_RULE0_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM20_MEM_RULE0_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM20_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAM20_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAM20_MEM_RULE0_RULE3_MASK        (0x3000U)
#define SECTRL_RAM20_MEM_RULE0_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM20_MEM_RULE0_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM20_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAM20_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name RAM30_MEM_RULE0 - SRAM Partition 0 Memory Rule */
/*! @{ */

#define SECTRL_RAM30_MEM_RULE0_RULE0_MASK        (0x3U)
#define SECTRL_RAM30_MEM_RULE0_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM30_MEM_RULE0_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM30_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAM30_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAM30_MEM_RULE0_RULE1_MASK        (0x30U)
#define SECTRL_RAM30_MEM_RULE0_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM30_MEM_RULE0_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM30_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAM30_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAM30_MEM_RULE0_RULE2_MASK        (0x300U)
#define SECTRL_RAM30_MEM_RULE0_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM30_MEM_RULE0_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM30_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAM30_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAM30_MEM_RULE0_RULE3_MASK        (0x3000U)
#define SECTRL_RAM30_MEM_RULE0_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM30_MEM_RULE0_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM30_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAM30_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name RAM40_MEM_RULE0 - SRAM4 Partition 0 Memory Rule */
/*! @{ */

#define SECTRL_RAM40_MEM_RULE0_RULE0_MASK        (0x3U)
#define SECTRL_RAM40_MEM_RULE0_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM40_MEM_RULE0_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM40_MEM_RULE0_RULE0_SHIFT)) & SECTRL_RAM40_MEM_RULE0_RULE0_MASK)

#define SECTRL_RAM40_MEM_RULE0_RULE1_MASK        (0x30U)
#define SECTRL_RAM40_MEM_RULE0_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM40_MEM_RULE0_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM40_MEM_RULE0_RULE1_SHIFT)) & SECTRL_RAM40_MEM_RULE0_RULE1_MASK)

#define SECTRL_RAM40_MEM_RULE0_RULE2_MASK        (0x300U)
#define SECTRL_RAM40_MEM_RULE0_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM40_MEM_RULE0_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM40_MEM_RULE0_RULE2_SHIFT)) & SECTRL_RAM40_MEM_RULE0_RULE2_MASK)

#define SECTRL_RAM40_MEM_RULE0_RULE3_MASK        (0x3000U)
#define SECTRL_RAM40_MEM_RULE0_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_RAM40_MEM_RULE0_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_RAM40_MEM_RULE0_RULE3_SHIFT)) & SECTRL_RAM40_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE0 - APB Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_MASK (0x3U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_SHIFT (0U)
/*! SYSCON - SYSCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_SYSCON_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_IOCON_MASK (0x30U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_IOCON_SHIFT (4U)
/*! IOCON - IOCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_IOCON(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_IOCON_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_IOCON_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO0_MASK (0x300U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO0_SHIFT (8U)
/*! GPIO0 - GPIO0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO1_MASK (0x3000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO1_SHIFT (12U)
/*! GPIO1 - GPIO1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GPIO1_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_SHIFT (16U)
/*! PINT0 - PINT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT1_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT1_SHIFT (20U)
/*! PINT1 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_PINT1_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GINT1_MASK (0x3000000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GINT1_SHIFT (24U)
/*! GINT1 - GINT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GINT1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GINT1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE0_GINT1_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE1 - APB Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_MASK (0x3U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_SHIFT (0U)
/*! CTIMER0 - CTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_MASK (0x30U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_SHIFT (4U)
/*! CTIMER1 - CTIMER 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_CTIMER1_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT (16U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MRT_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MRT_SHIFT (20U)
/*! MRT - MRT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MRT(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MRT_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MRT_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MICRO_TICK_MASK (0x3000000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MICRO_TICK_SHIFT (24U)
/*! MICRO_TICK - MICRO_TICK
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MICRO_TICK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MICRO_TICK_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_MICRO_TICK_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_ITRC_MASK (0x30000000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_ITRC_SHIFT (28U)
/*! ITRC - ITRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_ITRC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_ITRC_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE1_ITRC_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE2 - APB Bridge Group 0 Rule 2 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_ANALOG_CTRL_MASK (0x3000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_ANALOG_CTRL_SHIFT (12U)
/*! ANALOG_CTRL - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_ANALOG_CTRL(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_ANALOG_CTRL_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_ANALOG_CTRL_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_eFUSE_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_eFUSE_SHIFT (20U)
/*! eFUSE - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_eFUSE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_eFUSE_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_eFUSE_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_I3C0_MASK (0x3000000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_I3C0_SHIFT (24U)
/*! I3C0 - I3C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_I3C0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_I3C0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE2_I3C0_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE3 - APB Bridge Group 0 Memory Rule 3 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE3_EZH_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE3_EZH_SHIFT (20U)
/*! EZH - EZH
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE3_EZH(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE3_EZH_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP0_MEM_RULE3_EZH_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE0 - APB Bridge Group 1 Memory Rule 0 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_PMC_MASK (0x3U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_PMC_SHIFT (0U)
/*! PMC - PMC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_PMC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_PMC_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_PMC_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SYSCTL_I2S_MASK (0x3000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SYSCTL_I2S_SHIFT (12U)
/*! SYSCTL_I2S - SYSCTL(I2S Pin Sharing)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SYSCTL_I2S(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SYSCTL_I2S_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SYSCTL_I2S_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SPI_MSFT_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SPI_MSFT_SHIFT (16U)
/*! SPI_MSFT - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SPI_MSFT(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SPI_MSFT_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE0_SPI_MSFT_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE1 - APB Bridge Group 1 Memory Rule 1 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER2_MASK (0x3U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER2_SHIFT (0U)
/*! CTIMER2 - CTIMER2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER2_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER2_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER3_MASK (0x30U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER3_SHIFT (4U)
/*! CTIMER3 - CTIMER3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER3_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER3_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER4_MASK (0x300U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER4_SHIFT (8U)
/*! CTIMER4 - CTIMER4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER4(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER4_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CTIMER4_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_RTC_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_RTC_SHIFT (16U)
/*! RTC - RTC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_RTC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_RTC_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_RTC_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_OS_EVENT_TIMER_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_OS_EVENT_TIMER_SHIFT (20U)
/*! OS_EVENT_TIMER - OS_EVENT_TIMER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_OS_EVENT_TIMER(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_OS_EVENT_TIMER_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_OS_EVENT_TIMER_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CACHE64_POLSEL_MASK (0x3000000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CACHE64_POLSEL_SHIFT (24U)
/*! CACHE64_POLSEL - CACHE64_POLSEL
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CACHE64_POLSEL(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CACHE64_POLSEL_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_CACHE64_POLSEL_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_MASK (0x30000000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_SHIFT (28U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE1_PKC_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE2 - APB Bridge Group 1 Memory Rule 2 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS0_MASK (0x3U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS0_SHIFT (0U)
/*! ELSMINI_ALIAS0 - ELSMINI ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS1_MASK (0x30U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS1_SHIFT (4U)
/*! ELSMINI_ALIAS1 - ELSMINI ALIAS1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS1_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS2_MASK (0x300U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS2_SHIFT (8U)
/*! ELSMINI_ALIAS2 - ELSMINI ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS2_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS2_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS3_MASK (0x3000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS3_SHIFT (12U)
/*! ELSMINI_ALIAS3 - ELSMINI ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS3_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_ELSMINI_ALIAS3_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_FLASH_CONTROLLER_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_FLASH_CONTROLLER_SHIFT (16U)
/*! FLASH_CONTROLLER - Flash controller
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_FLASH_CONTROLLER(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_FLASH_CONTROLLER_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_FLASH_CONTROLLER_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_PRINCE0_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_PRINCE0_SHIFT (20U)
/*! PRINCE0 - PRINCE0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_PRINCE0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_PRINCE0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE2_PRINCE0_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP1_MEM_RULE3 - APB Bridge Group 1 Memory Rule 3 */
/*! @{ */

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS0_MASK (0x300U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS0_SHIFT (8U)
/*! PUF_ALIAS0 - PUF_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS0_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS0_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS1_MASK (0x3000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS1_SHIFT (12U)
/*! PUF_ALIAS1 - PUF_ALIAS0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS1_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS1_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS2_MASK (0x30000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS2_SHIFT (16U)
/*! PUF_ALIAS2 - PUF_ALIAS2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS2_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS2_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS3_MASK (0x300000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS3_SHIFT (20U)
/*! PUF_ALIAS3 - PUF_ALIAS3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS3_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_PUF_ALIAS3_MASK)

#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_ROM_MASK (0x3000000U)
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_ROM_SHIFT (24U)
/*! ROM - ROM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_ROM(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_ROM_SHIFT)) & SECTRL_APB_PERIPHERAL_GROUP1_MEM_RULE3_ROM_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0 - AHB Peripheral 0 Slave Port9 Rule 0 */
/*! @{ */

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_DMA0_MASK (0x3U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_DMA0_SHIFT (0U)
/*! DMA0 - DMA0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_DMA0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_DMA0_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_DMA0_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_USB_FSD_MASK (0x30U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_USB_FSD_SHIFT (4U)
/*! USB_FSD - USB FSD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_USB_FSD(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_USB_FSD_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_USB_FSD_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_SCTIMER_MASK (0x300U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_SCTIMER_SHIFT (8U)
/*! SCTIMER - SCTIMER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_SCTIMER(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_SCTIMER_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_SCTIMER_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM0_MASK (0x3000U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM0_SHIFT (12U)
/*! FLEXCOMM0 - FLEXCOMM 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM0_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM0_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM1_MASK (0x30000U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM1_SHIFT (16U)
/*! FLEXCOMM1 - FLEXCOMM 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM1_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM1_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM2_MASK (0x300000U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM2_SHIFT (20U)
/*! FLEXCOMM2 - FLEXCOMM 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM2_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM2_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM3_MASK (0x3000000U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM3_SHIFT (24U)
/*! FLEXCOMM3 - FLEXCOMM 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM3_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM3_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM4_MASK (0x30000000U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM4_SHIFT (28U)
/*! FLEXCOMM4 - FLEXCOMM4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM4(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM4_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE0_FLEXCOMM4_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1 - AHB Peripheral 0 Slave Port 9 Rule 1 */
/*! @{ */

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_MAILBOX_MASK (0x3U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_MAILBOX_SHIFT (0U)
/*! MAILBOX - MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_MAILBOX_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_MAILBOX_MASK)

#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_GPIO_MASK (0x30U)
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_GPIO_SHIFT (4U)
/*! GPIO - GPIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_GPIO(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_GPIO_SHIFT)) & SECTRL_AHB_PERIPHERAL0_SLAVE_PORT_P9_SLAVE_RULE1_GPIO_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0 - AHB Peripheral 1 Slave Port 10 Slave Rule 0 */
/*! @{ */

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DMIC0_MASK (0x3U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DMIC0_SHIFT (0U)
/*! DMIC0 - DMIC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DMIC0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DMIC0_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DMIC0_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_CRC_MASK (0x30U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_CRC_SHIFT (4U)
/*! CRC - CRC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_CRC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_CRC_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_CRC_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM5_MASK (0x300U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM5_SHIFT (8U)
/*! FLEXCOMM5 - FLEXCOMM 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM5(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM5_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM5_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM6_MASK (0x3000U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM6_SHIFT (12U)
/*! FLEXCOMM6 - FLEXCOMM 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM6(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM6_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM6_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM7_MASK (0x30000U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM7_SHIFT (16U)
/*! FLEXCOMM7 - FLEXCOMM 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM7(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM7_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_FLEXCOMM7_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DEBUG_MAILBOX_MASK (0x300000U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DEBUG_MAILBOX_SHIFT (20U)
/*! DEBUG_MAILBOX - FLEXCOMM 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DEBUG_MAILBOX_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_DEBUG_MAILBOX_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_MCAN_MASK (0x3000000U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_MCAN_SHIFT (24U)
/*! MCAN - FLEXCOMM 14
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_MCAN(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_MCAN_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_MCAN_MASK)

#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_HS_LSPI_MASK (0x30000000U)
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_HS_LSPI_SHIFT (28U)
/*! HS_LSPI - FLEXCOMM 8
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_HS_LSPI(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_HS_LSPI_SHIFT)) & SECTRL_AHB_PERIPHERAL1_SLAVE_PORT_P10_SLAVE_0_HS_LSPI_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0 - AHB Peripheral 2 Slave Port 11 Slave Rule 0 */
/*! @{ */

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_ADC_MASK (0x3U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_ADC_SHIFT (0U)
/*! ADC - ADC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_ADC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_ADC_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_ADC_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_CDOG_MASK (0x30U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_CDOG_SHIFT (4U)
/*! CDOG - Code WatchDog Timer
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_CDOG(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_CDOG_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_CDOG_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_USB_FS_HOST_MASK (0x300U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_USB_FS_HOST_SHIFT (8U)
/*! USB_FS_HOST - USB FS HOST
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_USB_FS_HOST(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_USB_FS_HOST_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_USB_FS_HOST_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_POWERQUAD_MASK (0x3000U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_POWERQUAD_SHIFT (12U)
/*! POWERQUAD - POWERQUAD
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_POWERQUAD(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_POWERQUAD_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_POWERQUAD_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_DMA1_MASK (0x30000U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_DMA1_SHIFT (16U)
/*! DMA1 - DMA1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_DMA1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_DMA1_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_DMA1_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_SECGPIO_MASK (0x300000U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_SECGPIO_SHIFT (20U)
/*! SECGPIO - SECGPIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_SECGPIO(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_SECGPIO_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_SECGPIO_MASK)

#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_AHB_SECURE_MASK (0x3000000U)
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_AHB_SECURE_SHIFT (24U)
/*! AHB_SECURE - AHB_SECURE
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_AHB_SECURE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_AHB_SECURE_SHIFT)) & SECTRL_AHB_PERIPHERAL2_SLAVE_PORT_P11_SLAVE_RULE0_AHB_SECURE_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0 - AHB Secure Control Peripheral Memory Rule 0 */
/*! @{ */

#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE0_MASK (0x3U)
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE0_SHIFT)) & SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE0_MASK)

#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE1_MASK (0x30U)
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE1_SHIFT)) & SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE1_MASK)

#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE2_MASK (0x300U)
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE2_SHIFT)) & SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE2_MASK)

#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE3_MASK (0x3000U)
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE3_SHIFT)) & SECTRL_AHB_SECURE_CTRL_PERIPHERAL_MEM_RULE0_RULE3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_RULE0 - AIPS Bridge Group 0 Rule 0 */
/*! @{ */

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_ADC1_MASK (0x30U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_ADC1_SHIFT (4U)
/*! ADC1 - ADC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_ADC1(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_ADC1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_ADC1_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC0_MASK (0x300U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC0_SHIFT (8U)
/*! DAC0 - DAC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC0(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP0_MASK (0x3000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP0_SHIFT (12U)
/*! HSCOMP0 - HSCOMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_OPAMP0_MASK (0x30000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_OPAMP0_SHIFT (16U)
/*! OPAMP0 - OPAMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_OPAMP0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_OPAMP0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_OPAMP0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_VREF_MASK (0x300000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_VREF_SHIFT (20U)
/*! VREF - VREF
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_VREF(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_VREF_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_VREF_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC1_MASK (0x3000000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC1_SHIFT (24U)
/*! DAC1 - DAC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC1(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_DAC1_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP1_MASK (0x30000000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP1_SHIFT (28U)
/*! HSCOMP1 - HSCOMP1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE0_HSCOMP1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_RULE1 - AIPS Bridge Group 0 Rule 1 */
/*! @{ */

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP1_MASK (0x3U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP1_SHIFT (0U)
/*! OPAMP1 - OPAMP1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP1_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_DAC2_MASK (0x30U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_DAC2_SHIFT (4U)
/*! DAC2 - DAC2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_DAC2(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE1_DAC2_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE1_DAC2_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_HSCOMP2_MASK (0x300U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_HSCOMP2_SHIFT (8U)
/*! HSCOMP2 - HSCOMP2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_HSCOMP2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE1_HSCOMP2_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE1_HSCOMP2_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP2_MASK (0x3000U)
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP2_SHIFT (12U)
/*! OPAMP2 - OPAMP2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP2_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP0_RULE1_OPAMP2_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_RULE0 - AIPS Bridge Group 1 Rule 0 */
/*! @{ */

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI0_MASK (0x3U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI0_SHIFT (0U)
/*! FLEXSPI0 - FLEXSPI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_CMX_MASK (0x30U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_CMX_SHIFT (4U)
/*! FLEXSPI_CMX - FLEXSPI_CMX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_CMX(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_CMX_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_CMX_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_LPCAC_MASK (0x300U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_LPCAC_SHIFT (8U)
/*! LPCAC - LPCAC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_LPCAC(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_LPCAC_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_LPCAC_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXPWM0_MASK (0x3000U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXPWM0_SHIFT (12U)
/*! FLEXPWM0 - FLEXPWM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXPWM0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXPWM0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXPWM0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC0_MASK (0x30000U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC0_SHIFT (16U)
/*! ENC0 - FLEXSPI0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC0(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC0_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_PWM1_MASK (0x300000U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_PWM1_SHIFT (20U)
/*! FLEXSPI_PWM1 - FLEXSPI_PWM1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_PWM1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_PWM1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_FLEXSPI_PWM1_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC1_MASK (0x3000000U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC1_SHIFT (24U)
/*! ENC1 - ENC1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC1(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_ENC1_MASK)

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_AOI0_MASK (0x30000000U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_AOI0_SHIFT (28U)
/*! AOI0 - AOI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE0_AOI0(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE0_AOI0_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE0_AOI0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP1_RULE1 - AIPS Bridge Group 1 Rule 1 */
/*! @{ */

#define SECTRL_AIPS_BRIDGE_GROUP1_RULE1_AOI1_MASK (0x3U)
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE1_AOI1_SHIFT (0U)
/*! AOI1 - RNG (Random Number Generator)
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define SECTRL_AIPS_BRIDGE_GROUP1_RULE1_AOI1(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_AIPS_BRIDGE_GROUP1_RULE1_AOI1_SHIFT)) & SECTRL_AIPS_BRIDGE_GROUP1_RULE1_AOI1_MASK)
/*! @} */

/*! @name SEC_VIO_ADDRN_SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_MASK (0xFFFFFFFFU)
#define SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator */
#define SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_SHIFT)) & SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_SEC_VIO_INFO_WRITE_MASK)
/*! @} */

/* The count of SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR */
#define SECTRL_SEC_VIO_ADDRN_SEC_VIO_ADDR_COUNT  (32U)

/*! @name SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0xF00U)
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - Security violation master number
 *  0b0000..M33 Code
 *  0b0001..M33 System
 *  0b0010..DMA0
 *  0b0011..DMA1
 *  0b0100..USBFS Device
 *  0b0101..USBFS Host
 *  0b0110..EZH Instruction
 *  0b0111..EZH Data
 *  0b1000..ELS
 *  0b1001..MCAN
 *  0b1010..PKC M0
 *  0b1011..GPU
 *  0b1100..DSP Data
 *  0b1101..DSP Instruction
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO */
#define SECTRL_SEC_VIO_MISC_INFON_SEC_VIO_MISC_INFO_COUNT (32U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK (0x100U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT (8U)
/*! VIO_INFO_VALID8 - Violation information valid flag for AHB port 8
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID8_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK (0x200U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT (9U)
/*! VIO_INFO_VALID9 - Violation information valid flag for AHB port 9
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID9_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK (0x400U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT (10U)
/*! VIO_INFO_VALID10 - Violation information valid flag for AHB port 10
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID10_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK (0x800U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT (11U)
/*! VIO_INFO_VALID11 - Violation information valid flag for AHB port 11
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID11_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK (0x1000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT (12U)
/*! VIO_INFO_VALID12 - Violation information valid flag for AHB port 12
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID12_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK (0x2000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT (13U)
/*! VIO_INFO_VALID13 - Violation information valid flag for AHB port 13
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID13_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK (0x4000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT (14U)
/*! VIO_INFO_VALID14 - Violation information valid flag for AHB port 14
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID14_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK (0x8000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT (15U)
/*! VIO_INFO_VALID15 - Violation information valid flag for AHB port 15
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID15_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK (0x10000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT (16U)
/*! VIO_INFO_VALID16 - Violation information valid flag for AHB port 16
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID16_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK (0x20000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT (17U)
/*! VIO_INFO_VALID17 - Violation information valid flag for AHB port 17
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID17_MASK)

#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK (0x40000U)
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT (18U)
/*! VIO_INFO_VALID18 - Violation information valid flag for AHB port 18
 *  0b0..Not valid
 *  0b1..Valid
 */
#define SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_SHIFT)) & SECTRL_SEC_VIO_INFO_VALID_VIO_INFO_VALID18_MASK)
/*! @} */

/*! @name SEC_GPIO_MASKN_SEC_GPIO_MASK - GPIO Mask for Port 0..GPIO Mask for Port 2 */
/*! @{ */

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_MASK (0x1U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO0_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN0_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_MASK (0x1U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO1_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN0_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN0_SEC_MASK_MASK (0x1U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO2_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN0_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN0_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_MASK (0x2U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO0_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN1_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_MASK (0x2U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO1_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN1_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN1_SEC_MASK_MASK (0x2U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO2_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN1_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN1_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_MASK (0x4U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO0_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN2_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_MASK (0x4U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO1_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN2_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN2_SEC_MASK_MASK (0x4U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO2_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN2_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN2_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_MASK (0x8U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO0_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN3_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_MASK (0x8U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO1_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN3_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN3_SEC_MASK_MASK (0x8U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO2_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN3_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN3_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_MASK (0x10U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO0_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN4_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_MASK (0x10U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO1_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN4_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN4_SEC_MASK_MASK (0x10U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO2_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN4_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN4_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_MASK (0x20U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO0_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN5_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_MASK (0x20U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO1_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN5_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN5_SEC_MASK_MASK (0x20U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO2_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN5_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN5_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_MASK (0x40U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO0_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN6_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_MASK (0x40U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO1_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN6_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN6_SEC_MASK_MASK (0x40U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO2_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN6_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN6_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_MASK (0x80U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO0_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN7_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_MASK (0x80U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO1_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN7_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN7_SEC_MASK_MASK (0x80U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN7_SEC_MASK_SHIFT (7U)
/*! PIO2_PIN7_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN7_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN7_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN7_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_MASK (0x100U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO0_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN8_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_MASK (0x100U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO1_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN8_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN8_SEC_MASK_MASK (0x100U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN8_SEC_MASK_SHIFT (8U)
/*! PIO2_PIN8_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN8_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN8_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN8_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_MASK (0x200U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO0_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN9_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_MASK (0x200U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO1_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN9_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN9_SEC_MASK_MASK (0x200U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN9_SEC_MASK_SHIFT (9U)
/*! PIO2_PIN9_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN9_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN9_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN9_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_MASK (0x400U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO0_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN10_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_MASK (0x400U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO1_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN10_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN10_SEC_MASK_MASK (0x400U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN10_SEC_MASK_SHIFT (10U)
/*! PIO2_PIN10_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN10_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN10_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN10_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_MASK (0x800U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO0_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN11_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_MASK (0x800U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO1_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN11_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN11_SEC_MASK_MASK (0x800U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN11_SEC_MASK_SHIFT (11U)
/*! PIO2_PIN11_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN11_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN11_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN11_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_MASK (0x1000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO0_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN12_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_MASK (0x1000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO1_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN12_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN12_SEC_MASK_MASK (0x1000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN12_SEC_MASK_SHIFT (12U)
/*! PIO2_PIN12_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN12_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN12_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN12_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_MASK (0x2000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO0_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN13_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_MASK (0x2000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO1_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN13_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN13_SEC_MASK_MASK (0x2000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN13_SEC_MASK_SHIFT (13U)
/*! PIO2_PIN13_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN13_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN13_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN13_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_MASK (0x4000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO0_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN14_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_MASK (0x4000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO1_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN14_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN14_SEC_MASK_MASK (0x4000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN14_SEC_MASK_SHIFT (14U)
/*! PIO2_PIN14_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN14_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN14_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN14_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_MASK (0x8000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO0_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN15_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_MASK (0x8000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO1_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN15_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN15_SEC_MASK_MASK (0x8000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN15_SEC_MASK_SHIFT (15U)
/*! PIO2_PIN15_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN15_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN15_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN15_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_MASK (0x10000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO0_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN16_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_MASK (0x10000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO1_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN16_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN16_SEC_MASK_MASK (0x10000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN16_SEC_MASK_SHIFT (16U)
/*! PIO2_PIN16_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN16_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN16_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN16_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_MASK (0x20000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO0_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN17_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_MASK (0x20000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO1_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN17_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN17_SEC_MASK_MASK (0x20000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN17_SEC_MASK_SHIFT (17U)
/*! PIO2_PIN17_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN17_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN17_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN17_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_MASK (0x40000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO0_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN18_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_MASK (0x40000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO1_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN18_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN18_SEC_MASK_MASK (0x40000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN18_SEC_MASK_SHIFT (18U)
/*! PIO2_PIN18_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN18_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN18_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN18_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_MASK (0x80000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO0_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN19_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_MASK (0x80000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO1_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN19_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN19_SEC_MASK_MASK (0x80000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN19_SEC_MASK_SHIFT (19U)
/*! PIO2_PIN19_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN19_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN19_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN19_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_MASK (0x100000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO0_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN20_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_MASK (0x100000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO1_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN20_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN20_SEC_MASK_MASK (0x100000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN20_SEC_MASK_SHIFT (20U)
/*! PIO2_PIN20_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN20_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN20_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN20_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_MASK (0x200000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO0_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN21_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_MASK (0x200000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO1_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN21_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN21_SEC_MASK_MASK (0x200000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN21_SEC_MASK_SHIFT (21U)
/*! PIO2_PIN21_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN21_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN21_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN21_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_MASK (0x400000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO0_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN22_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_MASK (0x400000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO1_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN22_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN22_SEC_MASK_MASK (0x400000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN22_SEC_MASK_SHIFT (22U)
/*! PIO2_PIN22_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN22_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN22_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN22_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_MASK (0x800000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO0_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN23_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_MASK (0x800000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO1_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN23_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN23_SEC_MASK_MASK (0x800000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN23_SEC_MASK_SHIFT (23U)
/*! PIO2_PIN23_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN23_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN23_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN23_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_MASK (0x1000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO0_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN24_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_MASK (0x1000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO1_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN24_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN24_SEC_MASK_MASK (0x1000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN24_SEC_MASK_SHIFT (24U)
/*! PIO2_PIN24_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN24_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN24_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN24_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_MASK (0x2000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO0_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN25_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_MASK (0x2000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO1_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN25_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN25_SEC_MASK_MASK (0x2000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN25_SEC_MASK_SHIFT (25U)
/*! PIO2_PIN25_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN25_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN25_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN25_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_MASK (0x4000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO0_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN26_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_MASK (0x4000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO1_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN26_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN26_SEC_MASK_MASK (0x4000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN26_SEC_MASK_SHIFT (26U)
/*! PIO2_PIN26_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN26_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN26_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN26_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_MASK (0x8000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO0_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN27_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_MASK (0x8000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO1_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN27_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN27_SEC_MASK_MASK (0x8000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN27_SEC_MASK_SHIFT (27U)
/*! PIO2_PIN27_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN27_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN27_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN27_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_MASK (0x10000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO0_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN28_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_MASK (0x10000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO1_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN28_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN28_SEC_MASK_MASK (0x10000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN28_SEC_MASK_SHIFT (28U)
/*! PIO2_PIN28_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN28_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN28_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN28_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_MASK (0x20000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO0_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN29_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_MASK (0x20000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO1_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN29_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN29_SEC_MASK_MASK (0x20000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN29_SEC_MASK_SHIFT (29U)
/*! PIO2_PIN29_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN29_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN29_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN29_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_MASK (0x40000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO0_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN30_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_MASK (0x40000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO1_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN30_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN30_SEC_MASK_MASK (0x40000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN30_SEC_MASK_SHIFT (30U)
/*! PIO2_PIN30_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN30_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN30_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN30_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_MASK (0x80000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO0_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO0_PIN31_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_MASK (0x80000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO1_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO1_PIN31_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN31_SEC_MASK_MASK (0x80000000U)
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN31_SEC_MASK_SHIFT (31U)
/*! PIO2_PIN31_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN31_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN31_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_PIO2_PIN31_SEC_MASK_MASK)
/*! @} */

/* The count of SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK */
#define SECTRL_SEC_GPIO_MASKN_SEC_GPIO_MASK_COUNT (3U)

/*! @name SEC_GPIO_MASK3 - GPIO Mask for Port 3 */
/*! @{ */

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_MASK (0x1U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_SHIFT (0U)
/*! PIO3_PIN0_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN0_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_MASK (0x2U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_SHIFT (1U)
/*! PIO3_PIN1_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN1_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_MASK (0x4U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_SHIFT (2U)
/*! PIO3_PIN2_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN2_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_MASK (0x8U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_SHIFT (3U)
/*! PIO3_PIN3_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN3_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_MASK (0x10U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_SHIFT (4U)
/*! PIO3_PIN4_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN4_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_MASK (0x20U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_SHIFT (5U)
/*! PIO3_PIN5_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN5_SEC_MASK_MASK)

#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_MASK (0x40U)
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_SHIFT (6U)
/*! PIO3_PIN6_SEC_MASK - Mask bit
 *  0b0..Masked
 *  0b1..Not masked
 */
#define SECTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_SHIFT)) & SECTRL_SEC_GPIO_MASK3_PIO3_PIN6_SEC_MASK_MASK)
/*! @} */

/*! @name SEC_GP_REG_LOCK - Secure Mask Lock */
/*! @{ */

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_MASK (0x3U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT (0U)
/*! SEC_GPIO_MASK0_LOCK - Secure GPIO _MASK0 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK0 cannot be written
 *  0b10..SEC_GPIO_MASK0 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK0_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_MASK (0xCU)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT (2U)
/*! SEC_GPIO_MASK1_LOCK - Secure GPIO _MASK1 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK1 cannot be written
 *  0b10..SEC_GPIO_MASK1 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK1_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK2_LOCK_MASK (0x30U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT (4U)
/*! SEC_GPIO_MASK2_LOCK - Secure GPIO _MASK2 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK2 cannot be written
 *  0b10..SEC_GPIO_MASK2 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK2_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK2_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK2_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK3_LOCK_MASK (0xC0U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT (6U)
/*! SEC_GPIO_MASK3_LOCK - Secure GPIO _MASK3 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK3 cannot be written
 *  0b10..SEC_GPIO_MASK3 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK3_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK3_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK3_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK4_LOCK_MASK (0x300U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT (8U)
/*! SEC_GPIO_MASK4_LOCK - SEC_GPIO_MASK4 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK4_LOCK cannot be written
 *  0b10..SEC_GPIO_MASK4_LOCK can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK4_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK4_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK4_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK5_LOCK_MASK (0xC00U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT (10U)
/*! SEC_GPIO_MASK5_LOCK - SEC_GPIO_MASK5 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK5 cannot be written
 *  0b10..SEC_GPIO_MASK5 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK5_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK5_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK5_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK6_LOCK_MASK (0x3000U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT (12U)
/*! SEC_GPIO_MASK6_LOCK - SEC_GPIO_MASK6 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK6 cannot be written
 *  0b10..SEC_GPIO_MASK6 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK6_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK6_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK6_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK7_LOCK_MASK (0xC000U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT (14U)
/*! SEC_GPIO_MASK7_LOCK - SEC_GPIO_MASK7 Lock
 *  0b00..Reserved
 *  0b01..SEC_GPIO_MASK7 cannot be written
 *  0b10..SEC_GPIO_MASK7 can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK7_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK7_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_GPIO_MASK7_LOCK_MASK)

#define SECTRL_SEC_GP_REG_LOCK_SEC_DSP_INT_MASK_LOCK_MASK (0x30000U)
#define SECTRL_SEC_GP_REG_LOCK_SEC_DSP_INT_MASK_LOCK_SHIFT (16U)
/*! SEC_DSP_INT_MASK_LOCK - SEC_DSP_INT_MASK Lock
 *  0b00..Reserved
 *  0b01..SEC_DSP_INT_MASK cannot be written
 *  0b10..SEC_DSP_INT_MASK can be written
 *  0b11..Reserved
 */
#define SECTRL_SEC_GP_REG_LOCK_SEC_DSP_INT_MASK_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_SEC_GP_REG_LOCK_SEC_DSP_INT_MASK_LOCK_SHIFT)) & SECTRL_SEC_GP_REG_LOCK_SEC_DSP_INT_MASK_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define SECTRL_MASTER_SEC_LEVEL_DMA0_MASK        (0x30U)
#define SECTRL_MASTER_SEC_LEVEL_DMA0_SHIFT       (4U)
/*! DMA0 - DMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_DMA0(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_DMA0_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_DMA0_MASK)

#define SECTRL_MASTER_SEC_LEVEL_DMA1_MASK        (0xC0U)
#define SECTRL_MASTER_SEC_LEVEL_DMA1_SHIFT       (6U)
/*! DMA1 - DMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_DMA1(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_DMA1_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_DMA1_MASK)

#define SECTRL_MASTER_SEC_LEVEL_USBFSD_MASK      (0x300U)
#define SECTRL_MASTER_SEC_LEVEL_USBFSD_SHIFT     (8U)
/*! USBFSD - USBFS Device
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_USBFSD(x)        (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_USBFSD_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_USBFSD_MASK)

#define SECTRL_MASTER_SEC_LEVEL_USBFSH_MASK      (0xC00U)
#define SECTRL_MASTER_SEC_LEVEL_USBFSH_SHIFT     (10U)
/*! USBFSH - USBFS Host
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_USBFSH(x)        (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_USBFSH_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_USBFSH_MASK)

#define SECTRL_MASTER_SEC_LEVEL_EZH_D_MASK       (0x3000U)
#define SECTRL_MASTER_SEC_LEVEL_EZH_D_SHIFT      (12U)
/*! EZH_D - EZH Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_EZH_D(x)         (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_EZH_D_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_EZH_D_MASK)

#define SECTRL_MASTER_SEC_LEVEL_EZH_I_MASK       (0xC000U)
#define SECTRL_MASTER_SEC_LEVEL_EZH_I_SHIFT      (14U)
/*! EZH_I - EZH Instruction
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_EZH_I(x)         (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_EZH_I_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_EZH_I_MASK)

#define SECTRL_MASTER_SEC_LEVEL_MCAN_MASK        (0xC0000U)
#define SECTRL_MASTER_SEC_LEVEL_MCAN_SHIFT       (18U)
/*! MCAN - MCAN
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_MCAN(x)          (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_MCAN_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_MCAN_MASK)

#define SECTRL_MASTER_SEC_LEVEL_POWERQUAD_MASK   (0x300000U)
#define SECTRL_MASTER_SEC_LEVEL_POWERQUAD_SHIFT  (20U)
/*! POWERQUAD - POWERQUAD
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_POWERQUAD(x)     (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_POWERQUAD_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_POWERQUAD_MASK)

#define SECTRL_MASTER_SEC_LEVEL_PKC_MASK         (0xC00000U)
#define SECTRL_MASTER_SEC_LEVEL_PKC_SHIFT        (22U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_PKC(x)           (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_PKC_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_PKC_MASK)

#define SECTRL_MASTER_SEC_LEVEL_DSP_D_MASK       (0x3000000U)
#define SECTRL_MASTER_SEC_LEVEL_DSP_D_SHIFT      (24U)
/*! DSP_D - DSP Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_DSP_D(x)         (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_DSP_D_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_DSP_D_MASK)

#define SECTRL_MASTER_SEC_LEVEL_DSP_I_MASK       (0xC000000U)
#define SECTRL_MASTER_SEC_LEVEL_DSP_I_SHIFT      (26U)
/*! DSP_I - DSP Instruction
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_LEVEL_DSP_I(x)         (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_DSP_I_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_DSP_I_MASK)

#define SECTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK (0xC0000000U)
#define SECTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_LOCK - Master Security Level Lock
 *  0b00..Reserved
 *  0b01..Lock writing to this register, including these (MASTER_SEC_LEVEL_LOCK) bits
 *  0b10..This register can be written
 *  0b11..Reserved
 */
#define SECTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_SHIFT)) & SECTRL_MASTER_SEC_LEVEL_MASTER_SEC_LEVEL_LOCK_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA0_MASK (0x30U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT (4U)
/*! DMA0 - DMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA0(x)   (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_DMA0_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA1_MASK (0xC0U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT (6U)
/*! DMA1 - DMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DMA1(x)   (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_DMA1_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSD_MASK (0x300U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSD_SHIFT (8U)
/*! USBFSD - USBFS Device
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSD(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSD_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSD_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSH_MASK (0xC00U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSH_SHIFT (10U)
/*! USBFSH - USBFS Host
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSH(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSH_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_USBFSH_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_D_MASK (0x3000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_D_SHIFT (12U)
/*! EZH_D - EZH Data
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_D(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_D_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_D_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_I_MASK (0xC000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_I_SHIFT (14U)
/*! EZH_I - EZH Instruction
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_I(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_I_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_EZH_I_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_MCAN_MASK (0xC0000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_MCAN_SHIFT (18U)
/*! MCAN - MCAN
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_MCAN(x)   (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_MCAN_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_MCAN_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_POWERQUAD_MASK (0x300000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_POWERQUAD_SHIFT (20U)
/*! POWERQUAD - POWERQUAD
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_POWERQUAD(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_POWERQUAD_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_POWERQUAD_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_PKC_MASK  (0xC00000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT (22U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_PKC(x)    (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_PKC_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_D_MASK (0x3000000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_D_SHIFT (24U)
/*! DSP_D - DSP Data */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_D(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_D_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_D_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_I_MASK (0xC000000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_I_SHIFT (26U)
/*! DSP_I - DSP Instruction */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_I(x)  (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_I_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_DSP_I_MASK)

#define SECTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK (0xC0000000U)
#define SECTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT (30U)
/*! MASTER_SEC_LEVEL_ANTIPOL_LOCK - Master Security Level Antipole Lock
 *  0b00..Reserved
 *  0b01..Lock writing to this register, including these (MASTER_SEC_LEVEL_ANTIPOL_LOCK) bits
 *  0b10..This register can be written
 *  0b11..Reserved
 */
#define SECTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_SHIFT)) & SECTRL_MASTER_SEC_ANTI_POL_REG_MASTER_SEC_LEVEL_ANTIPOL_LOCK_MASK)
/*! @} */

/*! @name CM33_LOCK_REGN_CM33_LOCK_REG - Miscellaneous CPU0 Control Signals */
/*! @{ */

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_VTOR_MASK (0x3U)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU0) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_VTOR(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_VTOR_MASK)

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_MPU_MASK (0xCU)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_MPU(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_MPU_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_NS_MPU_MASK)

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_VTAIRCR_MASK (0x30U)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_VTAIRCR_SHIFT (4U)
/*! LOCK_S_VTAIRCR - LOCK_S_VTAIRCR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_VTAIRCR is 1
 *  0b10..CM33 (CPU0) LOCK_S_VTAIRCR is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_VTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_VTAIRCR_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_VTAIRCR_MASK)

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_MPU_MASK (0xC0U)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_MPU_SHIFT (6U)
/*! LOCK_S_MPU - LOCK_S_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_S_MPU is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_MPU(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_MPU_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_S_MPU_MASK)

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_SAU_MASK (0x300U)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_SAU_SHIFT (8U)
/*! LOCK_SAU - LOCK_SAU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_SAU is 1
 *  0b10..CM33 (CPU0) LOCK_SAU is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_SAU(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_SAU_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_LOCK_SAU_MASK)

#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK (0xC0000000U)
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT (30U)
/*! CM33_LOCK_REG_LOCK - CM33_LOCK_REG_LOCK
 *  0b00..Reserved
 *  0b01..CM33_LOCK_REG_LOCK is 1
 *  0b10..CM33_LOCK_REG_LOCK is 0
 *  0b11..Reserved
 */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_CM33_LOCK_REG_LOCK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_SHIFT)) & SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_CM33_LOCK_REG_LOCK_MASK)
/*! @} */

/* The count of SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG */
#define SECTRL_CM33_LOCK_REGN_CM33_LOCK_REG_COUNT (3U)

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define SECTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK  (0x3U)
#define SECTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_WRITE_LOCK(x)    (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define SECTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define SECTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define SECTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define SECTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define SECTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define SECTRL_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define SECTRL_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define SECTRL_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define SECTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK (0xC000U)
#define SECTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)   (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & SECTRL_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define SECTRL_MISC_CTRL_REG_WRITE_LOCK_MASK     (0x3U)
#define SECTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT    (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_WRITE_LOCK(x)       (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & SECTRL_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define SECTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define SECTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & SECTRL_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define SECTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define SECTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & SECTRL_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define SECTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define SECTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enabled (restrictive mode)
 *  0b10..Disabled
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & SECTRL_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define SECTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define SECTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & SECTRL_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define SECTRL_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define SECTRL_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..AHB master in strict mode
 *  0b01..AHB master in tier mode. Can read and write to memories at same or below level.
 *  0b10..AHB master in strict mode
 *  0b11..AHB master in strict mode
 */
#define SECTRL_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & SECTRL_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define SECTRL_MISC_CTRL_REG_IDAU_ALL_NS_MASK    (0xC000U)
#define SECTRL_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT   (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define SECTRL_MISC_CTRL_REG_IDAU_ALL_NS(x)      (((uint32_t)(((uint32_t)(x)) << SECTRL_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & SECTRL_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SECTRL_Register_Masks */


/*!
 * @}
 */ /* end of group SECTRL_Peripheral_Access_Layer */


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


#endif  /* PERI_SECTRL_H_ */

