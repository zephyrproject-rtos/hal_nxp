/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHBSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_AHBSC.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for AHBSC
 *
 * CMSIS Peripheral Access Layer for AHBSC
 */

#if !defined(PERI_AHBSC_H_)
#define PERI_AHBSC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- AHBSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC_Peripheral_Access_Layer AHBSC Peripheral Access Layer
 * @{
 */

/** AHBSC - Size of Registers Arrays */
#define AHBSC_FLASH00_MEM_RULE_COUNT              4u
#define AHBSC_FLASH01_MEM_RULE_COUNT              1u
#define AHBSC_FLASH02_MEM_RULE_COUNT              1u
#define AHBSC_ROM_MEM_RULE_COUNT                  4u
#define AHBSC_RAMX_MEM_RULE0_COUNT                1u
#define AHBSC_RAMA_MEM_RULE_COUNT                 4u
#define AHBSC_RAMB_MEM_RULE_COUNT                 4u
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_COUNT      1u
#define AHBSC_SEC_VIO_ADDRN_COUNT                 8u
#define AHBSC_SEC_VIO_MISC_INFON_COUNT            8u
#define AHBSC_SEC_GP_REG_COUNT                    9u

/** AHBSC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t FLASH00_MEM_RULE[AHBSC_FLASH00_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x10, array step: 0x4 */
  __IO uint32_t FLASH01_MEM_RULE[AHBSC_FLASH01_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FLASH02_MEM_RULE[AHBSC_FLASH02_MEM_RULE_COUNT]; /**< Flash Memory Rule, array offset: 0x30, array step: 0x4 */
       uint8_t RESERVED_2[28];
  __IO uint32_t ROM_MEM_RULE[AHBSC_ROM_MEM_RULE_COUNT]; /**< ROM Memory Rule, array offset: 0x50, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __IO uint32_t RAMX_MEM_RULE[AHBSC_RAMX_MEM_RULE0_COUNT]; /**< RAMX Memory Rule, array offset: 0x70, array step: 0x4 */
       uint8_t RESERVED_4[28];
  __IO uint32_t RAMA_MEM_RULE[AHBSC_RAMA_MEM_RULE_COUNT]; /**< RAMA Memory Rule, array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_5[16];
  __IO uint32_t RAMB_MEM_RULE[AHBSC_RAMB_MEM_RULE_COUNT]; /**< RAMB Memory Rule, array offset: 0xB0, array step: 0x4 */
  __IO uint32_t AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0; /**< AHB Peripheral Slave Port 5 Slave Rule 0, offset: 0xC0 */
  __IO uint32_t AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1; /**< AHB Peripheral Slave Port 5 Slave Rule 1, offset: 0xC4 */
       uint8_t RESERVED_6[8];
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE0;   /**< APB Bridge Group 0 Memory Rule 0, offset: 0xD0 */
  __IO uint32_t APB_PERIPHERAL_GROUP0_MEM_RULE1;   /**< APB Bridge Group 0 Memory Rule 1, offset: 0xD4 */
       uint8_t RESERVED_7[8];
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE0;      /**< AIPS Bridge Group 0 Memory Rule 0, offset: 0xE0 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE1;      /**< AIPS Bridge Group 0 Memory Rule 1, offset: 0xE4 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE2;      /**< AIPS Bridge Group 0 Memory Rule 2, offset: 0xE8 */
  __IO uint32_t AIPS_BRIDGE_GROUP0_MEM_RULE3;      /**< AIPS Bridge Group 0 Memory Rule 3, offset: 0xEC */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE0;      /**< AIPS Bridge Group 2 Memory Rule 0, offset: 0xF0 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE1;      /**< AIPS Bridge Group 2 Memory Rule 1, offset: 0xF4 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE2;      /**< AIPS Bridge Group 2 Memory Rule 2, offset: 0xF8 */
  __IO uint32_t AIPS_BRIDGE_GROUP2_MEM_RULE3;      /**< AIPS Bridge Group 2 Memory Rule 3, offset: 0xFC */
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE0;      /**< AIPS Bridge Group 3 Rule 0, offset: 0x100 */
       uint8_t RESERVED_8[4];
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE2;      /**< AIPS Bridge Group 3 Rule 2, offset: 0x108 */
  __IO uint32_t AIPS_BRIDGE_GROUP3_MEM_RULE3;      /**< AIPS Bridge Group 3 Rule 3, offset: 0x10C */
  __IO uint32_t AHB_SECURE_CTRL_PERIPHERAL_RULE0;  /**< AHB Secure Control Peripheral Rule 0, offset: 0x110 */
       uint8_t RESERVED_9[28];
  __IO uint32_t AON_DOMAIN_PERIPHERAL_MEM_RULE0;   /**< AON Domain Peripheral Rule 0, offset: 0x130 */
  __IO uint32_t AON_DOMAIN_PERIPHERAL_MEM_RULE1;   /**< AON Domain Peripheral Rule 1, offset: 0x134 */
  __IO uint32_t AON_DOMAIN_PERIPHERAL_MEM_RULE2;   /**< AON Domain Peripheral Rule 2, offset: 0x138 */
  __IO uint32_t AON_DOMAIN_PERIPHERAL_MEM_RULE3;   /**< AON Domain Peripheral Rule 3, offset: 0x13C */
       uint8_t RESERVED_10[16];
  __IO uint32_t AON_DOMAIN_SRAM_MEM_RULE[AHBSC_AON_DOMAIN_SRAM_MEM_RULE_COUNT]; /**< AON Domain SRAM Memory Rule, array offset: 0x150, array step: 0x4 */
       uint8_t RESERVED_11[3244];
  __I  uint32_t SEC_VIO_ADDR[AHBSC_SEC_VIO_ADDRN_COUNT]; /**< Security Violation Address, array offset: 0xE00, array step: 0x4 */
       uint8_t RESERVED_12[96];
  __I  uint32_t SEC_VIO_MISC_INFO[AHBSC_SEC_VIO_MISC_INFON_COUNT]; /**< Security Violation Miscellaneous Information at Address, array offset: 0xE80, array step: 0x4 */
       uint8_t RESERVED_13[96];
  __IO uint32_t SEC_VIO_INFO_VALID;                /**< Security Violation Info Validity for Address, offset: 0xF00 */
       uint8_t RESERVED_14[124];
  __IO uint32_t SEC_GP_REG[AHBSC_SEC_GP_REG_COUNT]; /**< Secure general purpose registers, array offset: 0xF80, array step: 0x4 */
       uint8_t RESERVED_15[44];
  __IO uint32_t MASTER_SEC_LEVEL;                  /**< Master Secure Level, offset: 0xFD0 */
  __IO uint32_t MASTER_SEC_ANTI_POL_REG;           /**< Master Secure Level, offset: 0xFD4 */
       uint8_t RESERVED_16[20];
  __IO uint32_t CPU0_LOCK_REG;                     /**< Miscellaneous CPU0 Control Signals, offset: 0xFEC */
       uint8_t RESERVED_17[8];
  __IO uint32_t MISC_CTRL_DP_REG;                  /**< Secure Control Duplicate, offset: 0xFF8 */
  __IO uint32_t MISC_CTRL_REG;                     /**< Secure Control, offset: 0xFFC */
} AHBSC_Type;

/* ----------------------------------------------------------------------------
   -- AHBSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBSC_Register_Masks AHBSC Register Masks
 * @{
 */

/*! @name FLASH00_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH00_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH00_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH00_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH00_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH00_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE3_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE4_MASK        (0x30000U)
#define AHBSC_FLASH00_MEM_RULE_RULE4_SHIFT       (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE4(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE4_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE4_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE5_MASK        (0x300000U)
#define AHBSC_FLASH00_MEM_RULE_RULE5_SHIFT       (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE5(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE5_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE5_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE6_MASK        (0x3000000U)
#define AHBSC_FLASH00_MEM_RULE_RULE6_SHIFT       (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE6(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE6_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE6_MASK)

#define AHBSC_FLASH00_MEM_RULE_RULE7_MASK        (0x30000000U)
#define AHBSC_FLASH00_MEM_RULE_RULE7_SHIFT       (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH00_MEM_RULE_RULE7(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH00_MEM_RULE_RULE7_SHIFT)) & AHBSC_FLASH00_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name FLASH01_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH01_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH01_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH01_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH01_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH01_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH01_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH01_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH01_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH01_MEM_RULE_RULE3_MASK)
/*! @} */

/*! @name FLASH02_MEM_RULE - Flash Memory Rule */
/*! @{ */

#define AHBSC_FLASH02_MEM_RULE_RULE0_MASK        (0x3U)
#define AHBSC_FLASH02_MEM_RULE_RULE0_SHIFT       (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE0(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE0_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE0_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE1_MASK        (0x30U)
#define AHBSC_FLASH02_MEM_RULE_RULE1_SHIFT       (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE1(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE1_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE1_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE2_MASK        (0x300U)
#define AHBSC_FLASH02_MEM_RULE_RULE2_SHIFT       (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE2(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE2_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE2_MASK)

#define AHBSC_FLASH02_MEM_RULE_RULE3_MASK        (0x3000U)
#define AHBSC_FLASH02_MEM_RULE_RULE3_SHIFT       (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_FLASH02_MEM_RULE_RULE3(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_FLASH02_MEM_RULE_RULE3_SHIFT)) & AHBSC_FLASH02_MEM_RULE_RULE3_MASK)
/*! @} */

/*! @name ROM_MEM_RULE - ROM Memory Rule */
/*! @{ */

#define AHBSC_ROM_MEM_RULE_RULE0_MASK            (0x3U)
#define AHBSC_ROM_MEM_RULE_RULE0_SHIFT           (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE0(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE0_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE0_MASK)

#define AHBSC_ROM_MEM_RULE_RULE1_MASK            (0x30U)
#define AHBSC_ROM_MEM_RULE_RULE1_SHIFT           (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE1(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE1_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE1_MASK)

#define AHBSC_ROM_MEM_RULE_RULE2_MASK            (0x300U)
#define AHBSC_ROM_MEM_RULE_RULE2_SHIFT           (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE2(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE2_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE2_MASK)

#define AHBSC_ROM_MEM_RULE_RULE3_MASK            (0x3000U)
#define AHBSC_ROM_MEM_RULE_RULE3_SHIFT           (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE3(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE3_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE3_MASK)

#define AHBSC_ROM_MEM_RULE_RULE4_MASK            (0x30000U)
#define AHBSC_ROM_MEM_RULE_RULE4_SHIFT           (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE4(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE4_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE4_MASK)

#define AHBSC_ROM_MEM_RULE_RULE5_MASK            (0x300000U)
#define AHBSC_ROM_MEM_RULE_RULE5_SHIFT           (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE5(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE5_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE5_MASK)

#define AHBSC_ROM_MEM_RULE_RULE6_MASK            (0x3000000U)
#define AHBSC_ROM_MEM_RULE_RULE6_SHIFT           (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE6(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE6_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE6_MASK)

#define AHBSC_ROM_MEM_RULE_RULE7_MASK            (0x30000000U)
#define AHBSC_ROM_MEM_RULE_RULE7_SHIFT           (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_ROM_MEM_RULE_RULE7(x)              (((uint32_t)(((uint32_t)(x)) << AHBSC_ROM_MEM_RULE_RULE7_SHIFT)) & AHBSC_ROM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMX_MEM_RULE - RAMX Memory Rule */
/*! @{ */

#define AHBSC_RAMX_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMX_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMX_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMX_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMX_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMX_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMX_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMX_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMX_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMX_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMX_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMX_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMX_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMX_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMX_MEM_RULE_RULE5_MASK)
/*! @} */

/* The count of AHBSC_RAMX_MEM_RULE */
#define AHBSC_RAMX_MEM_RULE_COUNT                (1U)

/*! @name RAMA_MEM_RULE - RAMA Memory Rule */
/*! @{ */

#define AHBSC_RAMA_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMA_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMA_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMA_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMA_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMA_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMA_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMA_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMA_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMA_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMA_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMA_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMA_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name RAMB_MEM_RULE - RAMB Memory Rule */
/*! @{ */

#define AHBSC_RAMB_MEM_RULE_RULE0_MASK           (0x3U)
#define AHBSC_RAMB_MEM_RULE_RULE0_SHIFT          (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE0(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE0_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE0_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE1_MASK           (0x30U)
#define AHBSC_RAMB_MEM_RULE_RULE1_SHIFT          (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE1(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE1_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE1_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE2_MASK           (0x300U)
#define AHBSC_RAMB_MEM_RULE_RULE2_SHIFT          (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE2(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE2_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE2_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE3_MASK           (0x3000U)
#define AHBSC_RAMB_MEM_RULE_RULE3_SHIFT          (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE3(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE3_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE3_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE4_MASK           (0x30000U)
#define AHBSC_RAMB_MEM_RULE_RULE4_SHIFT          (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE4(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE4_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE4_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE5_MASK           (0x300000U)
#define AHBSC_RAMB_MEM_RULE_RULE5_SHIFT          (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE5(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE5_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE5_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE6_MASK           (0x3000000U)
#define AHBSC_RAMB_MEM_RULE_RULE6_SHIFT          (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE6(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE6_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE6_MASK)

#define AHBSC_RAMB_MEM_RULE_RULE7_MASK           (0x30000000U)
#define AHBSC_RAMB_MEM_RULE_RULE7_SHIFT          (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_RAMB_MEM_RULE_RULE7(x)             (((uint32_t)(((uint32_t)(x)) << AHBSC_RAMB_MEM_RULE_RULE7_SHIFT)) & AHBSC_RAMB_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0 - AHB Peripheral Slave Port 5 Slave Rule 0 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_MASK (0x300000U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_SHIFT (20U)
/*! CDOG0 - CDOG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_CDOG0_MASK)

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_MASK (0x3000000U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT (24U)
/*! DEBUG_MAILBOX - DEBUG_MAILBOX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_DEBUG_MAILBOX_MASK)

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_GPIO1_MASK (0x30000000U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_GPIO1_SHIFT (28U)
/*! GPIO1 - GPIO1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_GPIO1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_GPIO1_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE0_GPIO1_MASK)
/*! @} */

/*! @name AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1 - AHB Peripheral Slave Port 5 Slave Rule 1 */
/*! @{ */

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO2_MASK (0x3U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO2_SHIFT (0U)
/*! GPIO2 - GPIO2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO2_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO2_MASK)

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO3_MASK (0x30U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO3_SHIFT (4U)
/*! GPIO3 - GPIO3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO3_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_GPIO3_MASK)

#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_CDOG1_MASK (0x300U)
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_CDOG1_SHIFT (8U)
/*! CDOG1 - CDOG1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_CDOG1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_CDOG1_SHIFT)) & AHBSC_AHB_PERIPHERAL_SLAVE_PORT_P5_SLAVE_RULE1_CDOG1_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE0 - APB Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX0_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX0_SHIFT (4U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_INPUTMUX0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_SHIFT (16U)
/*! CTIMER0 - CTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_MASK (0x300000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_SHIFT (20U)
/*! CTIMER1 - CTIMER1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER1_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_MASK (0x3000000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_SHIFT (24U)
/*! CTIMER2 - CTIMER2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE0_CTIMER2_MASK)
/*! @} */

/*! @name APB_PERIPHERAL_GROUP0_MEM_RULE1 - APB Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME00_MASK (0x30U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME00_SHIFT (4U)
/*! FREQME00 - FREQME00
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME00(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME00_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_FREQME00_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK0_MASK (0x3000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK0_SHIFT (12U)
/*! UTICK0 - UTICK0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_UTICK0_MASK)

#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK (0x30000U)
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT (16U)
/*! WWDT0 - WWDT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_SHIFT)) & AHBSC_APB_PERIPHERAL_GROUP0_MEM_RULE1_WWDT0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE0 - AIPS Bridge Group 0 Memory Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_MP_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_MP_SHIFT (0U)
/*! eDMA_0_MP - eDMA_0_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_MP_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD0_SHIFT (4U)
/*! eDMA_0_TCD0 - eDMA_0_TCD0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD1_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD1_SHIFT (8U)
/*! eDMA_0_TCD1 - eDMA_0_TCD1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD2_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD2_SHIFT (12U)
/*! eDMA_0_TCD2 - eDMA_0_TCD2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD3_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD3_SHIFT (16U)
/*! eDMA_0_TCD3 - FLEXSPI0 Registers
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE0_eDMA_0_TCD3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE1 - AIPS Bridge Group 0 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_AOI0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_AOI0_SHIFT (4U)
/*! AOI0 - AOI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_AOI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_AOI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_AOI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CRC0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CRC0_SHIFT (8U)
/*! CRC0 - CRC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CRC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CRC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CRC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CMC0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CMC0_SHIFT (12U)
/*! CMC0 - CMC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CMC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CMC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_CMC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ERM0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ERM0_SHIFT (20U)
/*! ERM0 - ERM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ERM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ERM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_ERM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_MBC0_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_MBC0_SHIFT (24U)
/*! MBC0 - MBC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_MBC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_MBC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_MBC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_SCG0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_SCG0_SHIFT (28U)
/*! SCG0 - SCG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_SCG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_SCG0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE1_SCG0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE2 - AIPS Bridge Group 0 Memory Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_SYSCON_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_SYSCON_SHIFT (4U)
/*! SYSCON - SYSCON
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_SYSCON(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_SYSCON_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_SYSCON_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_WUU0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_WUU0_SHIFT (8U)
/*! WUU0 - WUU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_WUU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_WUU0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_WUU0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMC0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMC0_SHIFT (16U)
/*! FMC0 - FMC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_SHIFT (20U)
/*! FMU0 - FMU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_TST_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_TST_SHIFT (24U)
/*! FMU0_TST - FMU0_TST
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_TST(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_TST_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE2_FMU0_TST_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP0_MEM_RULE3 - AIPS Bridge Group 0 Memory Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C0_SHIFT (8U)
/*! LPI2C0 - LPI2C0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C1_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C1_SHIFT (12U)
/*! LPI2C1 - LPI2C1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPI2C1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI0_SHIFT (16U)
/*! LPSPI0 - LPSPI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI1_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI1_SHIFT (20U)
/*! LPSPI1 - LPSPI1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPSPI1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPUART0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPUART0_SHIFT (28U)
/*! LPUART0 - LPUART0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPUART0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPUART0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP0_MEM_RULE3_LPUART0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE0 - AIPS Bridge Group 2 Memory Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_LPUART1_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_LPUART1_SHIFT (0U)
/*! LPUART1 - LPUART1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_LPUART1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_LPUART1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE0_LPUART1_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE1 - AIPS Bridge Group 2 Memory Rule 1 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_FLEXPWM0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_FLEXPWM0_SHIFT (4U)
/*! FLEXPWM0 - FLEXPWM0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_FLEXPWM0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_FLEXPWM0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_FLEXPWM0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_OSTIMER0_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_OSTIMER0_SHIFT (20U)
/*! OSTIMER0 - OSTIMER0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_OSTIMER0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_OSTIMER0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_OSTIMER0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_HSADC0_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_HSADC0_SHIFT (28U)
/*! HSADC0 - HSADC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_HSADC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_HSADC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE1_HSADC0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE2 - AIPS Bridge Group 2 Memory Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_CMP0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_CMP0_SHIFT (4U)
/*! CMP0 - CMP0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_CMP0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_CMP0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE2_CMP0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP2_MEM_RULE3 - AIPS Bridge Group 2 Memory Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT1_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT1_SHIFT (16U)
/*! PORT1 - PORT1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT2_MASK (0x300000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT2_SHIFT (20U)
/*! PORT2 - PORT2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT3_MASK (0x3000000U)
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT3_SHIFT (24U)
/*! PORT3 - PORT3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP2_MEM_RULE3_PORT3_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE0 - AIPS Bridge Group 3 Rule 0 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MU0_MASK (0x30000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MU0_SHIFT (16U)
/*! MU0 - MU0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MU0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MU0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE0_MU0_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE2 - AIPS Bridge Group 3 Rule 2 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PKC0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PKC0_SHIFT (0U)
/*! PKC0 - PKC0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PKC0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PKC0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_PKC0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_SGI0_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_SGI0_SHIFT (4U)
/*! SGI0 - SGI0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_SGI0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_SGI0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_SGI0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_TRNG0_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_TRNG0_SHIFT (8U)
/*! TRNG0 - TRNG0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_TRNG0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_TRNG0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_TRNG0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_UDF0_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_UDF0_SHIFT (12U)
/*! UDF0 - CAN0 RULE0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_UDF0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_UDF0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_UDF0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_eMDA_1_MP_MASK (0x30000000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_eMDA_1_MP_SHIFT (28U)
/*! eMDA_1_MP - eDMA_1_MP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_eMDA_1_MP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_eMDA_1_MP_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE2_eMDA_1_MP_MASK)
/*! @} */

/*! @name AIPS_BRIDGE_GROUP3_MEM_RULE3 - AIPS Bridge Group 3 Rule 3 */
/*! @{ */

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD0_MASK (0x3U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD0_SHIFT (0U)
/*! eDMA_1_TCD0 - eDMA_1_TCD0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD0_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD0_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD1_MASK (0x30U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD1_SHIFT (4U)
/*! eDMA_1_TCD1 - eDMA_1_TCD1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD1_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD1_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD2_MASK (0x300U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD2_SHIFT (8U)
/*! eDMA_1_TCD2 - eDMA_1_TCD2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD2_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD2_MASK)

#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD3_MASK (0x3000U)
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD3_SHIFT (12U)
/*! eDMA_1_TCD3 - eDMA_1_TCD3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD3_SHIFT)) & AHBSC_AIPS_BRIDGE_GROUP3_MEM_RULE3_eDMA_1_TCD3_MASK)
/*! @} */

/*! @name AHB_SECURE_CTRL_PERIPHERAL_RULE0 - AHB Secure Control Peripheral Rule 0 */
/*! @{ */

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK (0x3U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE0_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK (0x30U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE1_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK (0x300U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE2_MASK)

#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK (0x3000U)
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_SHIFT)) & AHBSC_AHB_SECURE_CTRL_PERIPHERAL_RULE0_RULE3_MASK)
/*! @} */

/*! @name AON_DOMAIN_PERIPHERAL_MEM_RULE0 - AON Domain Peripheral Rule 0 */
/*! @{ */

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPI2C_MASK (0x3U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPI2C_SHIFT (0U)
/*! LPI2C - LPI2C
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPI2C(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPI2C_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPI2C_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPUART_MASK (0x300U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPUART_SHIFT (8U)
/*! LPUART - LPUART
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPUART(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPUART_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_LPUART_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_MUB_MASK (0x30000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_MUB_SHIFT (16U)
/*! MUB - MUB
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_MUB(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_MUB_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_MUB_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_PORT0_MASK (0x300000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_PORT0_SHIFT (20U)
/*! PORT0 - PORT0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_PORT0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_PORT0_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_PORT0_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_ACMP_MASK (0x3000000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_ACMP_SHIFT (24U)
/*! ACMP - ACMP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_ACMP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_ACMP_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE0_ACMP_MASK)
/*! @} */

/*! @name AON_DOMAIN_PERIPHERAL_MEM_RULE1 - AON Domain Peripheral Rule 1 */
/*! @{ */

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_LPTIMER_MASK (0x3U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_LPTIMER_SHIFT (0U)
/*! LPTIMER - LPTIMER
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_LPTIMER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_LPTIMER_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_LPTIMER_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_0_MASK (0x3000000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_0_SHIFT (24U)
/*! QTMR32_0 - QTMR32_0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_0_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_0_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_1_MASK (0x30000000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_1_SHIFT (28U)
/*! QTMR32_1 - QTMR32_1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_1_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE1_QTMR32_1_MASK)
/*! @} */

/*! @name AON_DOMAIN_PERIPHERAL_MEM_RULE2 - AON Domain Peripheral Rule 2 */
/*! @{ */

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_GP_GPR_MASK (0x3U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_GP_GPR_SHIFT (0U)
/*! GP_GPR - GP_GPR
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_GP_GPR(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_GP_GPR_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_GP_GPR_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_INPUTMUX_MASK (0x30U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_INPUTMUX_SHIFT (4U)
/*! INPUTMUX - INPUTMUX
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_INPUTMUX(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_INPUTMUX_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_INPUTMUX_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_LPADC_MASK (0x300U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_LPADC_SHIFT (8U)
/*! LPADC - LPADC
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_LPADC(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_LPADC_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_LPADC_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_SGLCD_MASK (0x30000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_SGLCD_SHIFT (16U)
/*! SGLCD - SGLCD0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_SGLCD(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_SGLCD_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_SGLCD_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_KPP_MASK (0x300000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_KPP_SHIFT (20U)
/*! KPP - KPP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_KPP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_KPP_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_KPP_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_ADVC2_MASK (0x30000000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_ADVC2_SHIFT (28U)
/*! ADVC2 - KPP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_ADVC2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_ADVC2_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE2_ADVC2_MASK)
/*! @} */

/*! @name AON_DOMAIN_PERIPHERAL_MEM_RULE3 - AON Domain Peripheral Rule 3 */
/*! @{ */

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_PMIC_CTRL_MASK (0x3U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_PMIC_CTRL_SHIFT (0U)
/*! PMIC_CTRL - PMIC_CTRL
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_PMIC_CTRL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_PMIC_CTRL_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_PMIC_CTRL_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_CGU_MASK (0x30U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_CGU_SHIFT (4U)
/*! CGU - CGU
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_CGU(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_CGU_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_CGU_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_SMM_MASK (0x300U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_SMM_SHIFT (8U)
/*! SMM - SMM
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_SMM(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_SMM_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_SMM_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_LPCMP_MASK (0x3000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_LPCMP_SHIFT (12U)
/*! LPCMP - LPCMP
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_LPCMP(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_LPCMP_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_LPCMP_MASK)

#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_AON_GPIO_MASK (0x30000000U)
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_AON_GPIO_SHIFT (28U)
/*! AON_GPIO - AON_GPIO
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_AON_GPIO(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_AON_GPIO_SHIFT)) & AHBSC_AON_DOMAIN_PERIPHERAL_MEM_RULE3_AON_GPIO_MASK)
/*! @} */

/*! @name AON_DOMAIN_SRAM_MEM_RULE - AON Domain SRAM Memory Rule */
/*! @{ */

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE0_MASK (0x3U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE0_SHIFT (0U)
/*! RULE0 - Rule 0
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE0(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE0_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE0_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE1_MASK (0x30U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE1_SHIFT (4U)
/*! RULE1 - Rule 1
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE1(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE1_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE1_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE2_MASK (0x300U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE2_SHIFT (8U)
/*! RULE2 - Rule 2
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE2(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE2_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE2_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE3_MASK (0x3000U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE3_SHIFT (12U)
/*! RULE3 - Rule 3
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE3(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE3_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE3_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE4_MASK (0x30000U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE4_SHIFT (16U)
/*! RULE4 - Rule 4
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE4(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE4_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE4_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE5_MASK (0x300000U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE5_SHIFT (20U)
/*! RULE5 - Rule 5
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE5(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE5_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE5_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE6_MASK (0x3000000U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE6_SHIFT (24U)
/*! RULE6 - Rule 6
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE6(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE6_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE6_MASK)

#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE7_MASK (0x30000000U)
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE7_SHIFT (28U)
/*! RULE7 - Rule 7
 *  0b00..Non-secure and non-privilege user access allowed
 *  0b01..Non-secure and privilege access allowed
 *  0b10..Secure and non-privilege user access allowed
 *  0b11..Secure and privilege user access allowed
 */
#define AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE7(x)  (((uint32_t)(((uint32_t)(x)) << AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE7_SHIFT)) & AHBSC_AON_DOMAIN_SRAM_MEM_RULE_RULE7_MASK)
/*! @} */

/*! @name SEC_VIO_ADDR - Security Violation Address */
/*! @{ */

#define AHBSC_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK     (0xFFFFFFFFU)
#define AHBSC_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT    (0U)
/*! SEC_VIO_ADDR - Security violation address for AHB layer a reset value 0 */
#define AHBSC_SEC_VIO_ADDR_SEC_VIO_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_ADDR_SEC_VIO_ADDR_SHIFT)) & AHBSC_SEC_VIO_ADDR_SEC_VIO_ADDR_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_ADDR */
#define AHBSC_SEC_VIO_ADDR_COUNT                 (8U)

/*! @name SEC_VIO_MISC_INFO - Security Violation Miscellaneous Information at Address */
/*! @{ */

#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK (0x1U)
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT (0U)
/*! SEC_VIO_INFO_WRITE - Security violation access read/write indicator
 *  0b0..Read access
 *  0b1..Write access
 */
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_SHIFT)) & AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_WRITE_MASK)

#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK (0x2U)
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT (1U)
/*! SEC_VIO_INFO_DATA_ACCESS - Security Violation Info Data Access
 *  0b0..Code
 *  0b1..Data
 */
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_SHIFT)) & AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_DATA_ACCESS_MASK)

#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK (0xF0U)
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT (4U)
/*! SEC_VIO_INFO_MASTER_SEC_LEVEL - Security Violation Info Master Security Level */
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_SHIFT)) & AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SEC_LEVEL_MASK)

#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK (0x1F00U)
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT (8U)
/*! SEC_VIO_INFO_MASTER - Security violation master number
 *  0b00000..M33 Code
 *  0b00001..M33 System
 *  0b00101..DMA0
 *  0b00111..DMA1
 *  0b01100..PKC
 */
#define AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_SHIFT)) & AHBSC_SEC_VIO_MISC_INFO_SEC_VIO_INFO_MASTER_MASK)
/*! @} */

/* The count of AHBSC_SEC_VIO_MISC_INFO */
#define AHBSC_SEC_VIO_MISC_INFO_COUNT            (8U)

/*! @name SEC_VIO_INFO_VALID - Security Violation Info Validity for Address */
/*! @{ */

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK (0x1U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT (0U)
/*! VIO_INFO_VALID0 - Violation information valid flag for AHB port 0
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID0_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK (0x2U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT (1U)
/*! VIO_INFO_VALID1 - Violation information valid flag for AHB port 1
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID1_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK (0x4U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT (2U)
/*! VIO_INFO_VALID2 - Violation information valid flag for AHB port 2
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID2_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK (0x8U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT (3U)
/*! VIO_INFO_VALID3 - Violation information valid flag for AHB port 3
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID3_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK (0x10U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT (4U)
/*! VIO_INFO_VALID4 - Violation information valid flag for AHB port 4
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID4_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK (0x20U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT (5U)
/*! VIO_INFO_VALID5 - Violation information valid flag for AHB port 5
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID5_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK (0x40U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT (6U)
/*! VIO_INFO_VALID6 - Violation information valid flag for AHB port 6
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID6_MASK)

#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK (0x80U)
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT (7U)
/*! VIO_INFO_VALID7 - Violation information valid flag for AHB port 7
 *  0b0..Not valid
 *  0b1..Valid
 */
#define AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_SHIFT)) & AHBSC_SEC_VIO_INFO_VALID_VIO_INFO_VALID7_MASK)
/*! @} */

/*! @name SEC_GP_REG - Secure general purpose registers */
/*! @{ */

#define AHBSC_SEC_GP_REG_AON_GPIO_INT_0_MASK     (0x1U)
#define AHBSC_SEC_GP_REG_AON_GPIO_INT_0_SHIFT    (0U)
/*! AON_GPIO_INT_0 - AON_GPIO_INT_0
 *  0b0..Disabled
 *  0b1..The interrupt is masked reaching to CM0+
 */
#define AHBSC_SEC_GP_REG_AON_GPIO_INT_0(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_AON_GPIO_INT_0_SHIFT)) & AHBSC_SEC_GP_REG_AON_GPIO_INT_0_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_MASK     (0x1U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_SHIFT    (0U)
/*! DMA0_IPD_REQ_0 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_0_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_MASK     (0x1U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_SHIFT    (0U)
/*! DMA1_IPD_REQ_0 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_0_MASK)

#define AHBSC_SEC_GP_REG_AON_GPIO_INT_1_MASK     (0x2U)
#define AHBSC_SEC_GP_REG_AON_GPIO_INT_1_SHIFT    (1U)
/*! AON_GPIO_INT_1 - AON_GPIO_INT_1
 *  0b0..Disabled
 *  0b1..The interrupt is masked reaching to CM0+.
 */
#define AHBSC_SEC_GP_REG_AON_GPIO_INT_1(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_AON_GPIO_INT_1_SHIFT)) & AHBSC_SEC_GP_REG_AON_GPIO_INT_1_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_MASK     (0x2U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_SHIFT    (1U)
/*! DMA0_IPD_REQ_1 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_1_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_MASK     (0x2U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_SHIFT    (1U)
/*! DMA1_IPD_REQ_1 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_1_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_MASK     (0x4U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_SHIFT    (2U)
/*! DMA0_IPD_REQ_2 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_2_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_MASK     (0x4U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_SHIFT    (2U)
/*! DMA1_IPD_REQ_2 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_2_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_MASK     (0x8U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_SHIFT    (3U)
/*! DMA0_IPD_REQ_3 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_3_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_MASK     (0x8U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_SHIFT    (3U)
/*! DMA1_IPD_REQ_3 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_3_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_MASK     (0x10U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_SHIFT    (4U)
/*! DMA0_IPD_REQ_4 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_4_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_MASK     (0x10U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_SHIFT    (4U)
/*! DMA1_IPD_REQ_4 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_4_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_MASK     (0x20U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_SHIFT    (5U)
/*! DMA0_IPD_REQ_5 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_5_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_MASK     (0x20U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_SHIFT    (5U)
/*! DMA1_IPD_REQ_5 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_5_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_MASK     (0x40U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_SHIFT    (6U)
/*! DMA0_IPD_REQ_6 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_6_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_MASK     (0x40U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_SHIFT    (6U)
/*! DMA1_IPD_REQ_6 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_6_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_MASK     (0x80U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_SHIFT    (7U)
/*! DMA0_IPD_REQ_7 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_7_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_MASK     (0x80U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_SHIFT    (7U)
/*! DMA1_IPD_REQ_7 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_7_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_MASK     (0x100U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_SHIFT    (8U)
/*! DMA0_IPD_REQ_8 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_8_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_MASK     (0x100U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_SHIFT    (8U)
/*! DMA1_IPD_REQ_8 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_8_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_MASK     (0x200U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_SHIFT    (9U)
/*! DMA0_IPD_REQ_9 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_9_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_MASK     (0x200U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_SHIFT    (9U)
/*! DMA1_IPD_REQ_9 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_9_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_MASK    (0x400U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_SHIFT   (10U)
/*! DMA0_IPD_REQ_10 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_10_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_MASK    (0x400U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_SHIFT   (10U)
/*! DMA1_IPD_REQ_10 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_10_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_MASK    (0x800U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_SHIFT   (11U)
/*! DMA0_IPD_REQ_11 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_11_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_MASK    (0x800U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_SHIFT   (11U)
/*! DMA1_IPD_REQ_11 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_11_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_MASK    (0x1000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_SHIFT   (12U)
/*! DMA0_IPD_REQ_12 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_12_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_MASK    (0x1000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_SHIFT   (12U)
/*! DMA1_IPD_REQ_12 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_12_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_MASK    (0x2000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_SHIFT   (13U)
/*! DMA0_IPD_REQ_13 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_13_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_MASK    (0x2000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_SHIFT   (13U)
/*! DMA1_IPD_REQ_13 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_13_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_MASK    (0x4000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_SHIFT   (14U)
/*! DMA0_IPD_REQ_14 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_14_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_MASK    (0x4000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_SHIFT   (14U)
/*! DMA1_IPD_REQ_14 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_14_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_MASK    (0x8000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_SHIFT   (15U)
/*! DMA0_IPD_REQ_15 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_15_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_MASK    (0x8000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_SHIFT   (15U)
/*! DMA1_IPD_REQ_15 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_15_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_MASK    (0x10000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_SHIFT   (16U)
/*! DMA0_IPD_REQ_16 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_16_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_MASK    (0x10000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_SHIFT   (16U)
/*! DMA1_IPD_REQ_16 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_16_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_MASK    (0x20000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_SHIFT   (17U)
/*! DMA0_IPD_REQ_17 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_17_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_MASK    (0x20000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_SHIFT   (17U)
/*! DMA1_IPD_REQ_17 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_17_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_MASK    (0x40000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_SHIFT   (18U)
/*! DMA0_IPD_REQ_18 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_18_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_MASK    (0x40000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_SHIFT   (18U)
/*! DMA1_IPD_REQ_18 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_18_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_MASK    (0x80000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_SHIFT   (19U)
/*! DMA0_IPD_REQ_19 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_19_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_MASK    (0x80000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_SHIFT   (19U)
/*! DMA1_IPD_REQ_19 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_19_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_MASK    (0x100000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_SHIFT   (20U)
/*! DMA0_IPD_REQ_20 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_20_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_MASK    (0x100000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_SHIFT   (20U)
/*! DMA1_IPD_REQ_20 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_20_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_MASK    (0x200000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_SHIFT   (21U)
/*! DMA0_IPD_REQ_21 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_21_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_MASK    (0x200000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_SHIFT   (21U)
/*! DMA1_IPD_REQ_21 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_21_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_MASK    (0x400000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_SHIFT   (22U)
/*! DMA0_IPD_REQ_22 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_22_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_MASK    (0x400000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_SHIFT   (22U)
/*! DMA1_IPD_REQ_22 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_22_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_MASK    (0x800000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_SHIFT   (23U)
/*! DMA0_IPD_REQ_23 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_23_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_MASK    (0x800000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_SHIFT   (23U)
/*! DMA1_IPD_REQ_23 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_23_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_MASK    (0x1000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_SHIFT   (24U)
/*! DMA0_IPD_REQ_24 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_24_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_MASK    (0x1000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_SHIFT   (24U)
/*! DMA1_IPD_REQ_24 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_24_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_MASK    (0x2000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_SHIFT   (25U)
/*! DMA0_IPD_REQ_25 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_25_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_MASK    (0x2000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_SHIFT   (25U)
/*! DMA1_IPD_REQ_25 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_25_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_MASK    (0x4000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_SHIFT   (26U)
/*! DMA0_IPD_REQ_26 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_26_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_MASK    (0x4000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_SHIFT   (26U)
/*! DMA1_IPD_REQ_26 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_26_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_MASK    (0x8000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_SHIFT   (27U)
/*! DMA0_IPD_REQ_27 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_27_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_MASK    (0x8000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_SHIFT   (27U)
/*! DMA1_IPD_REQ_27 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_27_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_MASK    (0x10000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_SHIFT   (28U)
/*! DMA0_IPD_REQ_28 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_28_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_MASK    (0x10000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_SHIFT   (28U)
/*! DMA1_IPD_REQ_28 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_28_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_MASK    (0x20000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_SHIFT   (29U)
/*! DMA0_IPD_REQ_29 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_29_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_MASK    (0x20000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_SHIFT   (29U)
/*! DMA1_IPD_REQ_29 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_29_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_MASK    (0x40000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_SHIFT   (30U)
/*! DMA0_IPD_REQ_30 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_30_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_MASK    (0x40000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_SHIFT   (30U)
/*! DMA1_IPD_REQ_30 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_30_MASK)

#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_MASK    (0x80000000U)
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_SHIFT   (31U)
/*! DMA0_IPD_REQ_31 - DMA0 IPD_REQ
 *  0b0..Indicates that DMA0 is masked for IPD_REQ
 *  0b1..Indicates that DMA0 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_SHIFT)) & AHBSC_SEC_GP_REG_DMA0_IPD_REQ_31_MASK)

#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_MASK    (0x80000000U)
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_SHIFT   (31U)
/*! DMA1_IPD_REQ_31 - DMA1 IPD_REQ
 *  0b0..Indicates that DMA1 is masked for IPD_REQ
 *  0b1..Indicates that DMA1 is enabled for IPD_REQ
 */
#define AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_SHIFT)) & AHBSC_SEC_GP_REG_DMA1_IPD_REQ_31_MASK)
/*! @} */

/*! @name MASTER_SEC_LEVEL - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_LEVEL_DMA0_MASK         (0xCU)
#define AHBSC_MASTER_SEC_LEVEL_DMA0_SHIFT        (2U)
/*! DMA0 - DMA0
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_DMA0(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_DMA0_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_DMA0_MASK)

#define AHBSC_MASTER_SEC_LEVEL_PKC_MASK          (0x30U)
#define AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT         (4U)
/*! PKC - PKC
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_PKC(x)            (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_PKC_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_PKC_MASK)

#define AHBSC_MASTER_SEC_LEVEL_DMA1_MASK         (0xC0U)
#define AHBSC_MASTER_SEC_LEVEL_DMA1_SHIFT        (6U)
/*! DMA1 - DMA1
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define AHBSC_MASTER_SEC_LEVEL_DMA1(x)           (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_LEVEL_DMA1_SHIFT)) & AHBSC_MASTER_SEC_LEVEL_DMA1_MASK)
/*! @} */

/*! @name MASTER_SEC_ANTI_POL_REG - Master Secure Level */
/*! @{ */

#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_MASK  (0xCU)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT (2U)
/*! DMA0 - DMA0
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_DMA0_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK   (0x30U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT  (4U)
/*! PKC - PKC
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_PKC(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_PKC_MASK)

#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_MASK  (0xC0U)
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT (6U)
/*! DMA1 - DMA1
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_SHIFT)) & AHBSC_MASTER_SEC_ANTI_POL_REG_DMA1_MASK)
/*! @} */

/*! @name CPU0_LOCK_REG - Miscellaneous CPU0 Control Signals */
/*! @{ */

#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK    (0x3U)
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT   (0U)
/*! LOCK_NS_VTOR - LOCK_NS_VTOR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCKNSVTOR is 1
 *  0b10..CM33 (CPU0) LOCKNSVTOR is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR(x)      (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_NS_VTOR_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_MASK     (0xCU)
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT    (2U)
/*! LOCK_NS_MPU - LOCK_NS_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_NS_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_NS_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_NS_MPU_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK  (0x30U)
#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT (4U)
/*! LOCK_S_VTAIRCR - LOCK_S_VTAIRCR
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_VTAIRCR is 1
 *  0b10..CM33 (CPU0) LOCK_S_VTAIRCR is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_S_VTAIRCR_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_MASK      (0xC0U)
#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT     (6U)
/*! LOCK_S_MPU - LOCK_S_MPU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_S_MPU is 1
 *  0b10..CM33 (CPU0) LOCK_S_MPU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_S_MPU(x)        (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_S_MPU_MASK)

#define AHBSC_CPU0_LOCK_REG_LOCK_SAU_MASK        (0x300U)
#define AHBSC_CPU0_LOCK_REG_LOCK_SAU_SHIFT       (8U)
/*! LOCK_SAU - LOCK_SAU
 *  0b00..Reserved
 *  0b01..CM33 (CPU0) LOCK_SAU is 1
 *  0b10..CM33 (CPU0) LOCK_SAU is 0
 *  0b11..Reserved
 */
#define AHBSC_CPU0_LOCK_REG_LOCK_SAU(x)          (((uint32_t)(((uint32_t)(x)) << AHBSC_CPU0_LOCK_REG_LOCK_SAU_SHIFT)) & AHBSC_CPU0_LOCK_REG_LOCK_SAU_MASK)
/*! @} */

/*! @name MISC_CTRL_DP_REG - Secure Control Duplicate */
/*! @{ */

#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK   (0x3U)
#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT  (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK(x)     (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_WRITE_LOCK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enables secure checking. Violation can be detected when the security level of a transaction does not
 *        meet the security rule of the slave or memory to be accessed.
 *  0b10..Disables secure checking. Even if the security level of a transaction does not conform to the security
 *        rule of the slave or memory, it will not be detected as a violation.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables the privilege checking of secure mode access.
 *  0b10..Disables the privilege checking of secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables the privilege checking of non-secure mode access.
 *  0b10..Disables the privilege checking of non-secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..Reserved
 *  0b01..Master strict mode is disabled and can access memories and peripherals at the same level or below that level
 *  0b10..Master strict mode is enabled and can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK  (0xC000U)
#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS(x)    (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_SHIFT)) & AHBSC_MISC_CTRL_DP_REG_IDAU_ALL_NS_MASK)
/*! @} */

/*! @name MISC_CTRL_REG - Secure Control */
/*! @{ */

#define AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK      (0x3U)
#define AHBSC_MISC_CTRL_REG_WRITE_LOCK_SHIFT     (0U)
/*! WRITE_LOCK - Write Lock
 *  0b00..Reserved
 *  0b01..Writes to this register and to the Memory and Peripheral RULE registers are not allowed
 *  0b10..Writes to this register and to the Memory and Peripheral RULE registers are allowed
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_WRITE_LOCK(x)        (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_WRITE_LOCK_SHIFT)) & AHBSC_MISC_CTRL_REG_WRITE_LOCK_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK (0xCU)
#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT (2U)
/*! ENABLE_SECURE_CHECKING - Enable Secure Checking
 *  0b00..Reserved
 *  0b01..Enables secure checking. Violation can be detected when the security level of a transaction does not
 *        meet the security rule of the slave or memory to be accessed.
 *  0b10..Disables secure checking. Even if the security level of a transaction does not conform to the security
 *        rule of the slave or memory, it will not be detected as a violation.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_SECURE_CHECKING_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK (0x30U)
#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT (4U)
/*! ENABLE_S_PRIV_CHECK - Enable Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables privilege checking of secure mode access.
 *  0b10..Disables privilege checking of secure mode access.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_S_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK (0xC0U)
#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT (6U)
/*! ENABLE_NS_PRIV_CHECK - Enable Non-Secure Privilege Checking
 *  0b00..Reserved
 *  0b01..Enables privilege checking of non-secure mode access.
 *  0b10..Disables privilege checking of non-secure mode access is disabled.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_SHIFT)) & AHBSC_MISC_CTRL_REG_ENABLE_NS_PRIV_CHECK_MASK)

#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK (0x300U)
#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT (8U)
/*! DISABLE_VIOLATION_ABORT - Disable Violation Abort
 *  0b00..Reserved
 *  0b01..The violation detected by the secure checker will not cause an abort, but a secure_violation_irq
 *        (interrupt request) will still be asserted and serviced by ISR.
 *  0b10..The violation detected by the secure checker will cause an abort and a secure_violation_irq will also be generated.
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_SHIFT)) & AHBSC_MISC_CTRL_REG_DISABLE_VIOLATION_ABORT_MASK)

#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK (0xC00U)
#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT (10U)
/*! DISABLE_STRICT_MODE - Disable Strict Mode
 *  0b00..Reserved
 *  0b01..Master strict mode is disabled and can access memories and peripherals at the same level or below that level
 *  0b10..Master strict mode is enabled and can access memories and peripherals at same level only
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE(x) (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_SHIFT)) & AHBSC_MISC_CTRL_REG_DISABLE_STRICT_MODE_MASK)

#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK     (0xC000U)
#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT    (14U)
/*! IDAU_ALL_NS - IDAU All Non-Secure
 *  0b00..Reserved
 *  0b01..IDAU is disabled, which means that all memories are attributed as non-secure memory.
 *  0b10..IDAU is enabled (restrictive mode)
 *  0b11..Reserved
 */
#define AHBSC_MISC_CTRL_REG_IDAU_ALL_NS(x)       (((uint32_t)(((uint32_t)(x)) << AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_SHIFT)) & AHBSC_MISC_CTRL_REG_IDAU_ALL_NS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBSC_Register_Masks */


/*!
 * @}
 */ /* end of group AHBSC_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBSC_H_ */

