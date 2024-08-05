/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SDA_AP.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SDA_AP
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_SDA_AP_H_)  /* Check if memory map has not been already included */
#define S32Z2_SDA_AP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SDA_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDA_AP_Peripheral_Access_Layer SDA_AP Peripheral Access Layer
 * @{
 */

/** SDA_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t AUTHSTTS;                          /**< Authentication status register, offset: 0x0 */
  __O  uint32_t AUTHCTL;                           /**< Authentication Control Register, offset: 0x4 */
  uint8_t RESERVED_0[8];
  __I  uint32_t KEYCHAL0;                          /**< Key Challenge 0 register, offset: 0x10 */
  __I  uint32_t KEYCHAL1;                          /**< Key Challenge 1 register, offset: 0x14 */
  __I  uint32_t KEYCHAL2;                          /**< Key Challenge 2 register, offset: 0x18 */
  __I  uint32_t KEYCHAL3;                          /**< Key Challenge 3 register, offset: 0x1C */
  __I  uint32_t KEYCHAL4;                          /**< Key Challenge 4 register, offset: 0x20 */
  __I  uint32_t KEYCHAL5;                          /**< Key Challenge 5 register, offset: 0x24 */
  __I  uint32_t KEYCHAL6;                          /**< Key Challenge 6 register, offset: 0x28 */
  __I  uint32_t KEYCHAL7;                          /**< Key Challenge 7 register, offset: 0x2C */
  __IO uint32_t KEYRESP0;                          /**< Key Response 0 register, offset: 0x30 */
  __IO uint32_t KEYRESP1;                          /**< Key Response 1 register, offset: 0x34 */
  __IO uint32_t KEYRESP2;                          /**< Key Response 2 register, offset: 0x38 */
  __IO uint32_t KEYRESP3;                          /**< Key Response 3 register, offset: 0x3C */
  __IO uint32_t KEYRESP4;                          /**< Key Response 4 register, offset: 0x40 */
  __IO uint32_t KEYRESP5;                          /**< Key Response 5 register, offset: 0x44 */
  __IO uint32_t KEYRESP6;                          /**< Key Response 6 register, offset: 0x48 */
  __IO uint32_t KEYRESP7;                          /**< Key Response 7 register, offset: 0x4C */
  uint8_t RESERVED_1[32];
  __I  uint32_t SDAUIDL;                           /**< UID Low Register, offset: 0x70 */
  __I  uint32_t SDAUIDH;                           /**< UID High Register, offset: 0x74 */
  uint8_t RESERVED_2[8];
  __I  uint32_t SDASYSRSTS;                        /**< System reset status register, offset: 0x80 */
  uint8_t RESERVED_3[4];
  __IO uint32_t SDASYSRSTC;                        /**< System Reset Control Register, offset: 0x88 */
  uint8_t RESERVED_4[4];
  __IO uint32_t SDARSTCTRL;                        /**< Reset Control Register, offset: 0x90 */
  __IO uint32_t SDARSTMASK;                        /**< Reset Control Mask Register, offset: 0x94 */
  uint8_t RESERVED_5[3428];
  __I  uint32_t IDR;                               /**< Identification Register, offset: 0xDFC */
  uint8_t RESERVED_6[444];
  __I  uint32_t DEVARCH;                           /**< CoreSight Device Architecture Register, offset: 0xFBC */
  uint8_t RESERVED_7[12];
  __I  uint32_t DEVTYPE;                           /**< CoreSight Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PIDR4;                             /**< CoreSight Peripheral Identification Register 4, offset: 0xFD0 */
  uint8_t RESERVED_8[12];
  __I  uint32_t PIDR0;                             /**< CoreSight Peripheral Identification Register 0, offset: 0xFE0 */
  __I  uint32_t PIDR1;                             /**< CoreSight Peripheral Identification Register 1, offset: 0xFE4 */
  __I  uint32_t PIDR2;                             /**< CoreSight Peripheral Identification Register 2, offset: 0xFE8 */
  __I  uint32_t PIDR3;                             /**< CoreSight Peripheral Identification Register 3, offset: 0xFEC */
  __I  uint32_t CIDR0;                             /**< CoreSight Component Identification Register 0, offset: 0xFF0 */
  __I  uint32_t CIDR1;                             /**< CoreSight Component Identification Register 1, offset: 0xFF4 */
  __I  uint32_t CIDR2;                             /**< CoreSight Component Identification Register 2, offset: 0xFF8 */
  __I  uint32_t CIDR3;                             /**< CoreSight Component Identification Register 3, offset: 0xFFC */
} SDA_AP_Type, *SDA_AP_MemMapPtr;

/** Number of instances of the SDA_AP module. */
#define SDA_AP_INSTANCE_COUNT                    (1u)

/* SDA_AP - Peripheral instance base addresses */
/** Peripheral SDA_AP base address */
#define IP_SDA_AP_BASE                           (0x4DC71000u)
/** Peripheral SDA_AP base pointer */
#define IP_SDA_AP                                ((SDA_AP_Type *)IP_SDA_AP_BASE)
/** Array initializer of SDA_AP peripheral base addresses */
#define IP_SDA_AP_BASE_ADDRS                     { IP_SDA_AP_BASE }
/** Array initializer of SDA_AP peripheral base pointers */
#define IP_SDA_AP_BASE_PTRS                      { IP_SDA_AP }

/* ----------------------------------------------------------------------------
   -- SDA_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDA_AP_Register_Masks SDA_AP Register Masks
 * @{
 */

/*! @name AUTHSTTS - Authentication status register */
/*! @{ */

#define SDA_AP_AUTHSTTS_CHALRDY_MASK             (0x1U)
#define SDA_AP_AUTHSTTS_CHALRDY_SHIFT            (0U)
#define SDA_AP_AUTHSTTS_CHALRDY_WIDTH            (1U)
#define SDA_AP_AUTHSTTS_CHALRDY(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_CHALRDY_SHIFT)) & SDA_AP_AUTHSTTS_CHALRDY_MASK)

#define SDA_AP_AUTHSTTS_UIDRDY_MASK              (0x4U)
#define SDA_AP_AUTHSTTS_UIDRDY_SHIFT             (2U)
#define SDA_AP_AUTHSTTS_UIDRDY_WIDTH             (1U)
#define SDA_AP_AUTHSTTS_UIDRDY(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_UIDRDY_SHIFT)) & SDA_AP_AUTHSTTS_UIDRDY_MASK)

#define SDA_AP_AUTHSTTS_APPDBGEN_MASK            (0x40000000U)
#define SDA_AP_AUTHSTTS_APPDBGEN_SHIFT           (30U)
#define SDA_AP_AUTHSTTS_APPDBGEN_WIDTH           (1U)
#define SDA_AP_AUTHSTTS_APPDBGEN(x)              (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_APPDBGEN_SHIFT)) & SDA_AP_AUTHSTTS_APPDBGEN_MASK)
/*! @} */

/*! @name AUTHCTL - Authentication Control Register */
/*! @{ */

#define SDA_AP_AUTHCTL_HSEAUTHREQ_MASK           (0x1U)
#define SDA_AP_AUTHCTL_HSEAUTHREQ_SHIFT          (0U)
#define SDA_AP_AUTHCTL_HSEAUTHREQ_WIDTH          (1U)
#define SDA_AP_AUTHCTL_HSEAUTHREQ(x)             (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHCTL_HSEAUTHREQ_SHIFT)) & SDA_AP_AUTHCTL_HSEAUTHREQ_MASK)
/*! @} */

/*! @name KEYCHAL0 - Key Challenge 0 register */
/*! @{ */

#define SDA_AP_KEYCHAL0_KEYCAL0_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL0_KEYCAL0_SHIFT            (0U)
#define SDA_AP_KEYCHAL0_KEYCAL0_WIDTH            (32U)
#define SDA_AP_KEYCHAL0_KEYCAL0(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL0_KEYCAL0_SHIFT)) & SDA_AP_KEYCHAL0_KEYCAL0_MASK)
/*! @} */

/*! @name KEYCHAL1 - Key Challenge 1 register */
/*! @{ */

#define SDA_AP_KEYCHAL1_KEYCAL1_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL1_KEYCAL1_SHIFT            (0U)
#define SDA_AP_KEYCHAL1_KEYCAL1_WIDTH            (32U)
#define SDA_AP_KEYCHAL1_KEYCAL1(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL1_KEYCAL1_SHIFT)) & SDA_AP_KEYCHAL1_KEYCAL1_MASK)
/*! @} */

/*! @name KEYCHAL2 - Key Challenge 2 register */
/*! @{ */

#define SDA_AP_KEYCHAL2_KEYCAL2_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL2_KEYCAL2_SHIFT            (0U)
#define SDA_AP_KEYCHAL2_KEYCAL2_WIDTH            (32U)
#define SDA_AP_KEYCHAL2_KEYCAL2(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL2_KEYCAL2_SHIFT)) & SDA_AP_KEYCHAL2_KEYCAL2_MASK)
/*! @} */

/*! @name KEYCHAL3 - Key Challenge 3 register */
/*! @{ */

#define SDA_AP_KEYCHAL3_KEYCAL3_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL3_KEYCAL3_SHIFT            (0U)
#define SDA_AP_KEYCHAL3_KEYCAL3_WIDTH            (32U)
#define SDA_AP_KEYCHAL3_KEYCAL3(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL3_KEYCAL3_SHIFT)) & SDA_AP_KEYCHAL3_KEYCAL3_MASK)
/*! @} */

/*! @name KEYCHAL4 - Key Challenge 4 register */
/*! @{ */

#define SDA_AP_KEYCHAL4_KEYCAL4_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL4_KEYCAL4_SHIFT            (0U)
#define SDA_AP_KEYCHAL4_KEYCAL4_WIDTH            (32U)
#define SDA_AP_KEYCHAL4_KEYCAL4(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL4_KEYCAL4_SHIFT)) & SDA_AP_KEYCHAL4_KEYCAL4_MASK)
/*! @} */

/*! @name KEYCHAL5 - Key Challenge 5 register */
/*! @{ */

#define SDA_AP_KEYCHAL5_KEYCAL5_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL5_KEYCAL5_SHIFT            (0U)
#define SDA_AP_KEYCHAL5_KEYCAL5_WIDTH            (32U)
#define SDA_AP_KEYCHAL5_KEYCAL5(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL5_KEYCAL5_SHIFT)) & SDA_AP_KEYCHAL5_KEYCAL5_MASK)
/*! @} */

/*! @name KEYCHAL6 - Key Challenge 6 register */
/*! @{ */

#define SDA_AP_KEYCHAL6_KEYCAL6_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL6_KEYCAL6_SHIFT            (0U)
#define SDA_AP_KEYCHAL6_KEYCAL6_WIDTH            (32U)
#define SDA_AP_KEYCHAL6_KEYCAL6(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL6_KEYCAL6_SHIFT)) & SDA_AP_KEYCHAL6_KEYCAL6_MASK)
/*! @} */

/*! @name KEYCHAL7 - Key Challenge 7 register */
/*! @{ */

#define SDA_AP_KEYCHAL7_KEYCAL7_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL7_KEYCAL7_SHIFT            (0U)
#define SDA_AP_KEYCHAL7_KEYCAL7_WIDTH            (32U)
#define SDA_AP_KEYCHAL7_KEYCAL7(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL7_KEYCAL7_SHIFT)) & SDA_AP_KEYCHAL7_KEYCAL7_MASK)
/*! @} */

/*! @name KEYRESP0 - Key Response 0 register */
/*! @{ */

#define SDA_AP_KEYRESP0_KEYCAL0_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP0_KEYCAL0_SHIFT            (0U)
#define SDA_AP_KEYRESP0_KEYCAL0_WIDTH            (32U)
#define SDA_AP_KEYRESP0_KEYCAL0(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP0_KEYCAL0_SHIFT)) & SDA_AP_KEYRESP0_KEYCAL0_MASK)
/*! @} */

/*! @name KEYRESP1 - Key Response 1 register */
/*! @{ */

#define SDA_AP_KEYRESP1_KEYCAL1_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP1_KEYCAL1_SHIFT            (0U)
#define SDA_AP_KEYRESP1_KEYCAL1_WIDTH            (32U)
#define SDA_AP_KEYRESP1_KEYCAL1(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP1_KEYCAL1_SHIFT)) & SDA_AP_KEYRESP1_KEYCAL1_MASK)
/*! @} */

/*! @name KEYRESP2 - Key Response 2 register */
/*! @{ */

#define SDA_AP_KEYRESP2_KEYCAL2_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP2_KEYCAL2_SHIFT            (0U)
#define SDA_AP_KEYRESP2_KEYCAL2_WIDTH            (32U)
#define SDA_AP_KEYRESP2_KEYCAL2(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP2_KEYCAL2_SHIFT)) & SDA_AP_KEYRESP2_KEYCAL2_MASK)
/*! @} */

/*! @name KEYRESP3 - Key Response 3 register */
/*! @{ */

#define SDA_AP_KEYRESP3_KEYCAL3_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP3_KEYCAL3_SHIFT            (0U)
#define SDA_AP_KEYRESP3_KEYCAL3_WIDTH            (32U)
#define SDA_AP_KEYRESP3_KEYCAL3(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP3_KEYCAL3_SHIFT)) & SDA_AP_KEYRESP3_KEYCAL3_MASK)
/*! @} */

/*! @name KEYRESP4 - Key Response 4 register */
/*! @{ */

#define SDA_AP_KEYRESP4_KEYCAL4_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP4_KEYCAL4_SHIFT            (0U)
#define SDA_AP_KEYRESP4_KEYCAL4_WIDTH            (32U)
#define SDA_AP_KEYRESP4_KEYCAL4(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP4_KEYCAL4_SHIFT)) & SDA_AP_KEYRESP4_KEYCAL4_MASK)
/*! @} */

/*! @name KEYRESP5 - Key Response 5 register */
/*! @{ */

#define SDA_AP_KEYRESP5_KEYCAL5_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP5_KEYCAL5_SHIFT            (0U)
#define SDA_AP_KEYRESP5_KEYCAL5_WIDTH            (32U)
#define SDA_AP_KEYRESP5_KEYCAL5(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP5_KEYCAL5_SHIFT)) & SDA_AP_KEYRESP5_KEYCAL5_MASK)
/*! @} */

/*! @name KEYRESP6 - Key Response 6 register */
/*! @{ */

#define SDA_AP_KEYRESP6_KEYCAL6_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP6_KEYCAL6_SHIFT            (0U)
#define SDA_AP_KEYRESP6_KEYCAL6_WIDTH            (32U)
#define SDA_AP_KEYRESP6_KEYCAL6(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP6_KEYCAL6_SHIFT)) & SDA_AP_KEYRESP6_KEYCAL6_MASK)
/*! @} */

/*! @name KEYRESP7 - Key Response 7 register */
/*! @{ */

#define SDA_AP_KEYRESP7_KEYCAL7_MASK             (0xFFFFFFFFU)
#define SDA_AP_KEYRESP7_KEYCAL7_SHIFT            (0U)
#define SDA_AP_KEYRESP7_KEYCAL7_WIDTH            (32U)
#define SDA_AP_KEYRESP7_KEYCAL7(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP7_KEYCAL7_SHIFT)) & SDA_AP_KEYRESP7_KEYCAL7_MASK)
/*! @} */

/*! @name SDAUIDL - UID Low Register */
/*! @{ */

#define SDA_AP_SDAUIDL_SDAUIDL_MASK              (0xFFFFFFFFU)
#define SDA_AP_SDAUIDL_SDAUIDL_SHIFT             (0U)
#define SDA_AP_SDAUIDL_SDAUIDL_WIDTH             (32U)
#define SDA_AP_SDAUIDL_SDAUIDL(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAUIDL_SDAUIDL_SHIFT)) & SDA_AP_SDAUIDL_SDAUIDL_MASK)
/*! @} */

/*! @name SDAUIDH - UID High Register */
/*! @{ */

#define SDA_AP_SDAUIDH_SDAUIDH_MASK              (0xFFFFFFFFU)
#define SDA_AP_SDAUIDH_SDAUIDH_SHIFT             (0U)
#define SDA_AP_SDAUIDH_SDAUIDH_WIDTH             (32U)
#define SDA_AP_SDAUIDH_SDAUIDH(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAUIDH_SDAUIDH_SHIFT)) & SDA_AP_SDAUIDH_SDAUIDH_MASK)
/*! @} */

/*! @name SDASYSRSTS - System reset status register */
/*! @{ */

#define SDA_AP_SDASYSRSTS_DESTRUCT_RESET_MASK    (0x2U)
#define SDA_AP_SDASYSRSTS_DESTRUCT_RESET_SHIFT   (1U)
#define SDA_AP_SDASYSRSTS_DESTRUCT_RESET_WIDTH   (1U)
#define SDA_AP_SDASYSRSTS_DESTRUCT_RESET(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDASYSRSTS_DESTRUCT_RESET_SHIFT)) & SDA_AP_SDASYSRSTS_DESTRUCT_RESET_MASK)

#define SDA_AP_SDASYSRSTS_SYSTEM_RESET_MASK      (0x4U)
#define SDA_AP_SDASYSRSTS_SYSTEM_RESET_SHIFT     (2U)
#define SDA_AP_SDASYSRSTS_SYSTEM_RESET_WIDTH     (1U)
#define SDA_AP_SDASYSRSTS_SYSTEM_RESET(x)        (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDASYSRSTS_SYSTEM_RESET_SHIFT)) & SDA_AP_SDASYSRSTS_SYSTEM_RESET_MASK)
/*! @} */

/*! @name SDASYSRSTC - System Reset Control Register */
/*! @{ */

#define SDA_AP_SDASYSRSTC_SYSRESTREQ_MASK        (0x10U)
#define SDA_AP_SDASYSRSTC_SYSRESTREQ_SHIFT       (4U)
#define SDA_AP_SDASYSRSTC_SYSRESTREQ_WIDTH       (1U)
#define SDA_AP_SDASYSRSTC_SYSRESTREQ(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDASYSRSTC_SYSRESTREQ_SHIFT)) & SDA_AP_SDASYSRSTC_SYSRESTREQ_MASK)

#define SDA_AP_SDASYSRSTC_SYSFUNCREQ_MASK        (0x20U)
#define SDA_AP_SDASYSRSTC_SYSFUNCREQ_SHIFT       (5U)
#define SDA_AP_SDASYSRSTC_SYSFUNCREQ_WIDTH       (1U)
#define SDA_AP_SDASYSRSTC_SYSFUNCREQ(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDASYSRSTC_SYSFUNCREQ_SHIFT)) & SDA_AP_SDASYSRSTC_SYSFUNCREQ_MASK)
/*! @} */

/*! @name SDARSTCTRL - Reset Control Register */
/*! @{ */

#define SDA_AP_SDARSTCTRL_RSTWAITCEB_MASK        (0x800U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEB_SHIFT       (11U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEB_WIDTH       (1U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEB(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTWAITCEB_SHIFT)) & SDA_AP_SDARSTCTRL_RSTWAITCEB_MASK)

#define SDA_AP_SDARSTCTRL_RSTWAITCEA_MASK        (0x1000U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEA_SHIFT       (12U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEA_WIDTH       (1U)
#define SDA_AP_SDARSTCTRL_RSTWAITCEA(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTWAITCEA_SHIFT)) & SDA_AP_SDARSTCTRL_RSTWAITCEA_MASK)

#define SDA_AP_SDARSTCTRL_RSTWAITSMU_MASK        (0x8000U)
#define SDA_AP_SDARSTCTRL_RSTWAITSMU_SHIFT       (15U)
#define SDA_AP_SDARSTCTRL_RSTWAITSMU_WIDTH       (1U)
#define SDA_AP_SDARSTCTRL_RSTWAITSMU(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTWAITSMU_SHIFT)) & SDA_AP_SDARSTCTRL_RSTWAITSMU_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS_MASK    (0x10000U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS_SHIFT   (16U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS_WIDTH   (1U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELSPF2_SYS_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE_MASK   (0x20000U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE_SHIFT  (17U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE_WIDTH  (1U)
#define SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE(x)     (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELSPF2_CORE_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C3_MASK     (0x100000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C3_SHIFT    (20U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C3_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C3(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU1_C3_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU1_C3_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C2_MASK     (0x200000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C2_SHIFT    (21U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C2_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C2(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU1_C2_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU1_C2_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C1_MASK     (0x400000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C1_SHIFT    (22U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C1_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU1_C1(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU1_C1_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU1_C1_MASK)

#define SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0_MASK    (0x800000U)
#define SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0_SHIFT   (23U)
#define SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0_WIDTH   (1U)
#define SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0_SHIFT)) & SDA_AP_SDARSTCTRL_RSTREL_RTU1_C0_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C3_MASK     (0x10000000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C3_SHIFT    (28U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C3_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C3(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU0_C3_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU0_C3_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C2_MASK     (0x20000000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C2_SHIFT    (29U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C2_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C2(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU0_C2_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU0_C2_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C1_MASK     (0x40000000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C1_SHIFT    (30U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C1_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C1(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU0_C1_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU0_C1_MASK)

#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C0_MASK     (0x80000000U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C0_SHIFT    (31U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C0_WIDTH    (1U)
#define SDA_AP_SDARSTCTRL_RSTRELRTU0_C0(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTCTRL_RSTRELRTU0_C0_SHIFT)) & SDA_AP_SDARSTCTRL_RSTRELRTU0_C0_MASK)
/*! @} */

/*! @name SDARSTMASK - Reset Control Mask Register */
/*! @{ */

#define SDA_AP_SDARSTMASK_RSTMSKRTU1_POR_MASK    (0x80000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_POR_SHIFT   (19U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_POR_WIDTH   (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_POR(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU1_POR_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU1_POR_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C3_MASK     (0x100000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C3_SHIFT    (20U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C3_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C3(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU1_C3_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU1_C3_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C2_MASK     (0x200000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C2_SHIFT    (21U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C2_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C2(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU1_C2_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU1_C2_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C1_MASK     (0x400000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C1_SHIFT    (22U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C1_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU1_C1(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU1_C1_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU1_C1_MASK)

#define SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0_MASK    (0x800000U)
#define SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0_SHIFT   (23U)
#define SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0_WIDTH   (1U)
#define SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSK_RTU1_C0_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU0_POR_MASK    (0x8000000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_POR_SHIFT   (27U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_POR_WIDTH   (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_POR(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU0_POR_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU0_POR_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C3_MASK     (0x10000000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C3_SHIFT    (28U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C3_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C3(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU0_C3_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU0_C3_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C2_MASK     (0x20000000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C2_SHIFT    (29U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C2_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C2(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU0_C2_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU0_C2_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C1_MASK     (0x40000000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C1_SHIFT    (30U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C1_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C1(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU0_C1_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU0_C1_MASK)

#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C0_MASK     (0x80000000U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C0_SHIFT    (31U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C0_WIDTH    (1U)
#define SDA_AP_SDARSTMASK_RSTMSKRTU0_C0(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDARSTMASK_RSTMSKRTU0_C0_SHIFT)) & SDA_AP_SDARSTMASK_RSTMSKRTU0_C0_MASK)
/*! @} */

/*! @name IDR - Identification Register */
/*! @{ */

#define SDA_AP_IDR_Type_MASK                     (0xFU)
#define SDA_AP_IDR_Type_SHIFT                    (0U)
#define SDA_AP_IDR_Type_WIDTH                    (4U)
#define SDA_AP_IDR_Type(x)                       (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_Type_SHIFT)) & SDA_AP_IDR_Type_MASK)

#define SDA_AP_IDR_Variant_MASK                  (0xF0U)
#define SDA_AP_IDR_Variant_SHIFT                 (4U)
#define SDA_AP_IDR_Variant_WIDTH                 (4U)
#define SDA_AP_IDR_Variant(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_Variant_SHIFT)) & SDA_AP_IDR_Variant_MASK)

#define SDA_AP_IDR_Class_MASK                    (0x1E000U)
#define SDA_AP_IDR_Class_SHIFT                   (13U)
#define SDA_AP_IDR_Class_WIDTH                   (4U)
#define SDA_AP_IDR_Class(x)                      (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_Class_SHIFT)) & SDA_AP_IDR_Class_MASK)

#define SDA_AP_IDR_JEDEC_code_MASK               (0xFE0000U)
#define SDA_AP_IDR_JEDEC_code_SHIFT              (17U)
#define SDA_AP_IDR_JEDEC_code_WIDTH              (7U)
#define SDA_AP_IDR_JEDEC_code(x)                 (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_JEDEC_code_SHIFT)) & SDA_AP_IDR_JEDEC_code_MASK)

#define SDA_AP_IDR_JEDEC_bank_MASK               (0xF000000U)
#define SDA_AP_IDR_JEDEC_bank_SHIFT              (24U)
#define SDA_AP_IDR_JEDEC_bank_WIDTH              (4U)
#define SDA_AP_IDR_JEDEC_bank(x)                 (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_JEDEC_bank_SHIFT)) & SDA_AP_IDR_JEDEC_bank_MASK)

#define SDA_AP_IDR_REVISION_MASK                 (0xF0000000U)
#define SDA_AP_IDR_REVISION_SHIFT                (28U)
#define SDA_AP_IDR_REVISION_WIDTH                (4U)
#define SDA_AP_IDR_REVISION(x)                   (((uint32_t)(((uint32_t)(x)) << SDA_AP_IDR_REVISION_SHIFT)) & SDA_AP_IDR_REVISION_MASK)
/*! @} */

/*! @name DEVARCH - CoreSight Device Architecture Register */
/*! @{ */

#define SDA_AP_DEVARCH_ARCHID_MASK               (0xFFFFU)
#define SDA_AP_DEVARCH_ARCHID_SHIFT              (0U)
#define SDA_AP_DEVARCH_ARCHID_WIDTH              (16U)
#define SDA_AP_DEVARCH_ARCHID(x)                 (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVARCH_ARCHID_SHIFT)) & SDA_AP_DEVARCH_ARCHID_MASK)

#define SDA_AP_DEVARCH_REVISION_MASK             (0xF0000U)
#define SDA_AP_DEVARCH_REVISION_SHIFT            (16U)
#define SDA_AP_DEVARCH_REVISION_WIDTH            (4U)
#define SDA_AP_DEVARCH_REVISION(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVARCH_REVISION_SHIFT)) & SDA_AP_DEVARCH_REVISION_MASK)

#define SDA_AP_DEVARCH_PRESENT_MASK              (0x100000U)
#define SDA_AP_DEVARCH_PRESENT_SHIFT             (20U)
#define SDA_AP_DEVARCH_PRESENT_WIDTH             (1U)
#define SDA_AP_DEVARCH_PRESENT(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVARCH_PRESENT_SHIFT)) & SDA_AP_DEVARCH_PRESENT_MASK)

#define SDA_AP_DEVARCH_ARCHITECT_MASK            (0xFFE00000U)
#define SDA_AP_DEVARCH_ARCHITECT_SHIFT           (21U)
#define SDA_AP_DEVARCH_ARCHITECT_WIDTH           (11U)
#define SDA_AP_DEVARCH_ARCHITECT(x)              (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVARCH_ARCHITECT_SHIFT)) & SDA_AP_DEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name DEVTYPE - CoreSight Device Type Identifier Register */
/*! @{ */

#define SDA_AP_DEVTYPE_MAJOR_MASK                (0xFU)
#define SDA_AP_DEVTYPE_MAJOR_SHIFT               (0U)
#define SDA_AP_DEVTYPE_MAJOR_WIDTH               (4U)
#define SDA_AP_DEVTYPE_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVTYPE_MAJOR_SHIFT)) & SDA_AP_DEVTYPE_MAJOR_MASK)

#define SDA_AP_DEVTYPE_SUB_MASK                  (0xF0U)
#define SDA_AP_DEVTYPE_SUB_SHIFT                 (4U)
#define SDA_AP_DEVTYPE_SUB_WIDTH                 (4U)
#define SDA_AP_DEVTYPE_SUB(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_DEVTYPE_SUB_SHIFT)) & SDA_AP_DEVTYPE_SUB_MASK)
/*! @} */

/*! @name PIDR4 - CoreSight Peripheral Identification Register 4 */
/*! @{ */

#define SDA_AP_PIDR4_DES_2_MASK                  (0xFU)
#define SDA_AP_PIDR4_DES_2_SHIFT                 (0U)
#define SDA_AP_PIDR4_DES_2_WIDTH                 (4U)
#define SDA_AP_PIDR4_DES_2(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR4_DES_2_SHIFT)) & SDA_AP_PIDR4_DES_2_MASK)

#define SDA_AP_PIDR4_SIZE_MASK                   (0xF0U)
#define SDA_AP_PIDR4_SIZE_SHIFT                  (4U)
#define SDA_AP_PIDR4_SIZE_WIDTH                  (4U)
#define SDA_AP_PIDR4_SIZE(x)                     (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR4_SIZE_SHIFT)) & SDA_AP_PIDR4_SIZE_MASK)
/*! @} */

/*! @name PIDR0 - CoreSight Peripheral Identification Register 0 */
/*! @{ */

#define SDA_AP_PIDR0_PART_0_MASK                 (0xFFU)
#define SDA_AP_PIDR0_PART_0_SHIFT                (0U)
#define SDA_AP_PIDR0_PART_0_WIDTH                (8U)
#define SDA_AP_PIDR0_PART_0(x)                   (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR0_PART_0_SHIFT)) & SDA_AP_PIDR0_PART_0_MASK)
/*! @} */

/*! @name PIDR1 - CoreSight Peripheral Identification Register 1 */
/*! @{ */

#define SDA_AP_PIDR1_PART_1_MASK                 (0xFU)
#define SDA_AP_PIDR1_PART_1_SHIFT                (0U)
#define SDA_AP_PIDR1_PART_1_WIDTH                (4U)
#define SDA_AP_PIDR1_PART_1(x)                   (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR1_PART_1_SHIFT)) & SDA_AP_PIDR1_PART_1_MASK)

#define SDA_AP_PIDR1_DES_0_MASK                  (0xF0U)
#define SDA_AP_PIDR1_DES_0_SHIFT                 (4U)
#define SDA_AP_PIDR1_DES_0_WIDTH                 (4U)
#define SDA_AP_PIDR1_DES_0(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR1_DES_0_SHIFT)) & SDA_AP_PIDR1_DES_0_MASK)
/*! @} */

/*! @name PIDR2 - CoreSight Peripheral Identification Register 2 */
/*! @{ */

#define SDA_AP_PIDR2_DES_1_MASK                  (0x7U)
#define SDA_AP_PIDR2_DES_1_SHIFT                 (0U)
#define SDA_AP_PIDR2_DES_1_WIDTH                 (3U)
#define SDA_AP_PIDR2_DES_1(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR2_DES_1_SHIFT)) & SDA_AP_PIDR2_DES_1_MASK)

#define SDA_AP_PIDR2_JEDEC_MASK                  (0x8U)
#define SDA_AP_PIDR2_JEDEC_SHIFT                 (3U)
#define SDA_AP_PIDR2_JEDEC_WIDTH                 (1U)
#define SDA_AP_PIDR2_JEDEC(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR2_JEDEC_SHIFT)) & SDA_AP_PIDR2_JEDEC_MASK)

#define SDA_AP_PIDR2_REVISION_MASK               (0xF0U)
#define SDA_AP_PIDR2_REVISION_SHIFT              (4U)
#define SDA_AP_PIDR2_REVISION_WIDTH              (4U)
#define SDA_AP_PIDR2_REVISION(x)                 (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR2_REVISION_SHIFT)) & SDA_AP_PIDR2_REVISION_MASK)
/*! @} */

/*! @name PIDR3 - CoreSight Peripheral Identification Register 3 */
/*! @{ */

#define SDA_AP_PIDR3_CMOD_MASK                   (0xFU)
#define SDA_AP_PIDR3_CMOD_SHIFT                  (0U)
#define SDA_AP_PIDR3_CMOD_WIDTH                  (4U)
#define SDA_AP_PIDR3_CMOD(x)                     (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR3_CMOD_SHIFT)) & SDA_AP_PIDR3_CMOD_MASK)

#define SDA_AP_PIDR3_REVAND_MASK                 (0xF0U)
#define SDA_AP_PIDR3_REVAND_SHIFT                (4U)
#define SDA_AP_PIDR3_REVAND_WIDTH                (4U)
#define SDA_AP_PIDR3_REVAND(x)                   (((uint32_t)(((uint32_t)(x)) << SDA_AP_PIDR3_REVAND_SHIFT)) & SDA_AP_PIDR3_REVAND_MASK)
/*! @} */

/*! @name CIDR0 - CoreSight Component Identification Register 0 */
/*! @{ */

#define SDA_AP_CIDR0_PRMBL_0_MASK                (0xFFU)
#define SDA_AP_CIDR0_PRMBL_0_SHIFT               (0U)
#define SDA_AP_CIDR0_PRMBL_0_WIDTH               (8U)
#define SDA_AP_CIDR0_PRMBL_0(x)                  (((uint32_t)(((uint32_t)(x)) << SDA_AP_CIDR0_PRMBL_0_SHIFT)) & SDA_AP_CIDR0_PRMBL_0_MASK)
/*! @} */

/*! @name CIDR1 - CoreSight Component Identification Register 1 */
/*! @{ */

#define SDA_AP_CIDR1_PRMBL_1_MASK                (0xFU)
#define SDA_AP_CIDR1_PRMBL_1_SHIFT               (0U)
#define SDA_AP_CIDR1_PRMBL_1_WIDTH               (4U)
#define SDA_AP_CIDR1_PRMBL_1(x)                  (((uint32_t)(((uint32_t)(x)) << SDA_AP_CIDR1_PRMBL_1_SHIFT)) & SDA_AP_CIDR1_PRMBL_1_MASK)

#define SDA_AP_CIDR1_CLASS_MASK                  (0xF0U)
#define SDA_AP_CIDR1_CLASS_SHIFT                 (4U)
#define SDA_AP_CIDR1_CLASS_WIDTH                 (4U)
#define SDA_AP_CIDR1_CLASS(x)                    (((uint32_t)(((uint32_t)(x)) << SDA_AP_CIDR1_CLASS_SHIFT)) & SDA_AP_CIDR1_CLASS_MASK)
/*! @} */

/*! @name CIDR2 - CoreSight Component Identification Register 2 */
/*! @{ */

#define SDA_AP_CIDR2_PRMBL_2_MASK                (0xFFU)
#define SDA_AP_CIDR2_PRMBL_2_SHIFT               (0U)
#define SDA_AP_CIDR2_PRMBL_2_WIDTH               (8U)
#define SDA_AP_CIDR2_PRMBL_2(x)                  (((uint32_t)(((uint32_t)(x)) << SDA_AP_CIDR2_PRMBL_2_SHIFT)) & SDA_AP_CIDR2_PRMBL_2_MASK)
/*! @} */

/*! @name CIDR3 - CoreSight Component Identification Register 3 */
/*! @{ */

#define SDA_AP_CIDR3_PRMBL_3_MASK                (0xFFU)
#define SDA_AP_CIDR3_PRMBL_3_SHIFT               (0U)
#define SDA_AP_CIDR3_PRMBL_3_WIDTH               (8U)
#define SDA_AP_CIDR3_PRMBL_3(x)                  (((uint32_t)(((uint32_t)(x)) << SDA_AP_CIDR3_PRMBL_3_SHIFT)) & SDA_AP_CIDR3_PRMBL_3_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SDA_AP_Register_Masks */

/*!
 * @}
 */ /* end of group SDA_AP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SDA_AP_H_) */
