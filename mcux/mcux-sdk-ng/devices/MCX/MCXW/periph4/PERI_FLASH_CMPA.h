/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH_CMPA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLASH_CMPA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_CMPA
 *
 * CMSIS Peripheral Access Layer for FLASH_CMPA
 */

#if !defined(PERI_FLASH_CMPA_H_)
#define PERI_FLASH_CMPA_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
   -- FLASH_CMPA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_CMPA_Peripheral_Access_Layer FLASH_CMPA Peripheral Access Layer
 * @{
 */

/** FLASH_CMPA - Size of Registers Arrays */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_COUNT       4u
#define FLASH_CMPA_ROTKH_COUNT                    8u
#define FLASH_CMPA_CUSTOMER_DEFINED_COUNT         88u
#define FLASH_CMPA_SHA256_DIGEST_COUNT            8u

/** FLASH_CMPA - Register Layout Typedef */
typedef struct {
  __IO uint32_t BOOT_CFG;                          /**< Boot Configuration, offset: 0x0 */
  __IO uint32_t SPI_FLASH_CFG;                     /**< SPI Flash Configuration, offset: 0x4 */
  __IO uint32_t DCFG_CC_SOCU_PIN;                  /**< ., offset: 0x8 */
  __IO uint32_t DCFG_CC_SOCU_DFLT;                 /**< ., offset: 0xC */
  __IO uint32_t VENDOR_USAGE;                      /**< ., offset: 0x10 */
  __IO uint32_t SECURE_BOOT_CFG;                   /**< ., offset: 0x14 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PRINCE_CFG;                        /**< Prince Configuration, offset: 0x1C */
  __IO uint32_t BMAPCTX[FLASH_CMPA_NPX_REGION_KEY_DIR_COUNT]; /**< Bitmap Control for Memory Context 0..Bitmap Control for Memory Context 3, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[32];
  struct {                                         /* offset: 0x50 */
    __IO uint32_t BLE_UNIQUE_ADDRESS0;               /**< BLE_UNIQUE_ADDRESS part 1, offset: 0x50 */
    __IO uint32_t BLE_UNIQUE_ADDRESS1;               /**< BLE_UNIQUE_ADDRESS part 2, offset: 0x54 */
  } BLE_UNIQUE_ADDRESS;
  __IO uint32_t FLASH_REMAP_SIZE;                  /**< This 32-bit register contains the size of the image to remap, in bytes., offset: 0x58 */
  __IO uint32_t FLASH_REMAP_OFFSET;                /**< This 32-bit register contains the offset by which the image is to be remapped., offset: 0x5C */
  __IO uint32_t ROTKH[FLASH_CMPA_ROTKH_COUNT];     /**< ROTKH0 for Root of Trust Keys Table hash[255:224]..ROTKH7 for Root of Trust Keys Table hash[31:0], array offset: 0x60, array step: 0x4 */
  __IO uint32_t CUSTOMER_DEFINED[FLASH_CMPA_CUSTOMER_DEFINED_COUNT]; /**< Customer Defined (Programable through ROM API), array offset: 0x80, array step: 0x4 */
  __IO uint32_t SHA256_DIGEST[FLASH_CMPA_SHA256_DIGEST_COUNT]; /**< SHA256_DIGEST0 for DIGEST[31:0]..SHA256_DIGEST7 for DIGEST[255:224], array offset: 0x1E0, array step: 0x4 */
} FLASH_CMPA_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_CMPA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_CMPA_Register_Masks FLASH_CMPA Register Masks
 * @{
 */

/*! @name BOOT_CFG - Boot Configuration */
/*! @{ */

#define FLASH_CMPA_BOOT_CFG_DEFAULT_ISP_MODE_MASK (0x70U)
#define FLASH_CMPA_BOOT_CFG_DEFAULT_ISP_MODE_SHIFT (4U)
/*! DEFAULT_ISP_MODE - Default ISP mode:
 *  0b000..Auto ISP
 *  0b001..Reserved
 *  0b010..UART ISP
 *  0b011..SPI Slave ISP
 *  0b100..I2C Slave ISP
 *  0b111..Disable ISP fall through
 */
#define FLASH_CMPA_BOOT_CFG_DEFAULT_ISP_MODE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BOOT_CFG_DEFAULT_ISP_MODE_SHIFT)) & FLASH_CMPA_BOOT_CFG_DEFAULT_ISP_MODE_MASK)

#define FLASH_CMPA_BOOT_CFG_BOOT_SPEED_MASK      (0x180U)
#define FLASH_CMPA_BOOT_CFG_BOOT_SPEED_SHIFT     (7U)
/*! BOOT_SPEED - Core clock:
 *  0b00..Defined by NMPA.SYSTEM_SPEED_CODE
 *  0b01..12MHz FRO
 *  0b10..32MHz FRO
 */
#define FLASH_CMPA_BOOT_CFG_BOOT_SPEED(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BOOT_CFG_BOOT_SPEED_SHIFT)) & FLASH_CMPA_BOOT_CFG_BOOT_SPEED_MASK)

#define FLASH_CMPA_BOOT_CFG_BOOT_FAILURE_PIN_MASK (0xFF000000U)
#define FLASH_CMPA_BOOT_CFG_BOOT_FAILURE_PIN_SHIFT (24U)
/*! BOOT_FAILURE_PIN - GPIO port and pin number to use for indicating failure reason. The toggle
 *    rate of the pin is used to decode the error type. [2:0] - Defines GPIO port [7:3] - Defines GPIO
 *    pin
 */
#define FLASH_CMPA_BOOT_CFG_BOOT_FAILURE_PIN(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BOOT_CFG_BOOT_FAILURE_PIN_SHIFT)) & FLASH_CMPA_BOOT_CFG_BOOT_FAILURE_PIN_MASK)
/*! @} */

/*! @name SPI_FLASH_CFG - SPI Flash Configuration */
/*! @{ */

#define FLASH_CMPA_SPI_FLASH_CFG_SPI_RECOVERY_BOOT_EN_MASK (0x1FU)
#define FLASH_CMPA_SPI_FLASH_CFG_SPI_RECOVERY_BOOT_EN_SHIFT (0U)
/*! SPI_RECOVERY_BOOT_EN - SPI flash recovery boot is enabled, if non-zero value is written to this field. */
#define FLASH_CMPA_SPI_FLASH_CFG_SPI_RECOVERY_BOOT_EN(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SPI_FLASH_CFG_SPI_RECOVERY_BOOT_EN_SHIFT)) & FLASH_CMPA_SPI_FLASH_CFG_SPI_RECOVERY_BOOT_EN_MASK)
/*! @} */

/*! @name DCFG_CC_SOCU_PIN - . */
/*! @{ */

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_NIDEN_MASK   (0x1U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_NIDEN_SHIFT  (0U)
/*! NIDEN - Non Secure non-invasive debug enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_NIDEN(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_NIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_NIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_DBGEN_MASK   (0x2U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_DBGEN_SHIFT  (1U)
/*! DBGEN - Non Secure debug enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_DBGEN(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_DBGEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_DBGEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPNIDEN_MASK (0x4U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPNIDEN_SHIFT (2U)
/*! SPNIDEN - Secure non-invasive debug enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPNIDEN(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_SPNIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_SPNIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPIDEN_MASK  (0x8U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPIDEN_SHIFT (3U)
/*! SPIDEN - Secure invasive debug enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_SPIDEN(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_SPIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_SPIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_TAPEN_MASK   (0x10U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_TAPEN_SHIFT  (4U)
/*! TAPEN - JTAG TAP enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_TAPEN(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_TAPEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_TAPEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_ISPCMDEN_MASK (0x40U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_ISPCMDEN_SHIFT (6U)
/*! ISPCMDEN - ISP Boot Command enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_ISPCMDEN(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_ISPCMDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_ISPCMDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_PMCMDEN_MASK (0x80U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_PMCMDEN_SHIFT (7U)
/*! PMCMDEN - Programmers Mode Command enable
 *  0b0..Use DAP to enable
 *  0b1..Fixed state
 */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_PMCMDEN(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_PMCMDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_PMCMDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_UUID_CHECK_MASK (0x8000U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_UUID_CHECK_SHIFT (15U)
/*! UUID_CHECK - Enforce UUID match during Debug authentication. */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_UUID_CHECK(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_UUID_CHECK_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_UUID_CHECK_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_PIN_INVERSE_VALUE_MASK (0xFFFF0000U)
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_INVERSE_VALUE_SHIFT (16U)
/*! INVERSE_VALUE - inverse value of bits [15:0] */
#define FLASH_CMPA_DCFG_CC_SOCU_PIN_INVERSE_VALUE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_PIN_INVERSE_VALUE_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_PIN_INVERSE_VALUE_MASK)
/*! @} */

/*! @name DCFG_CC_SOCU_DFLT - . */
/*! @{ */

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_NIDEN_MASK  (0x1U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_NIDEN_SHIFT (0U)
/*! NIDEN - Non Secure non-invasive debug fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_NIDEN(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_NIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_NIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_DBGEN_MASK  (0x2U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_DBGEN_SHIFT (1U)
/*! DBGEN - Non Secure debug fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_DBGEN(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_DBGEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_DBGEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPNIDEN_MASK (0x4U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPNIDEN_SHIFT (2U)
/*! SPNIDEN - Secure non-invasive debug fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPNIDEN(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPNIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPNIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPIDEN_MASK (0x8U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPIDEN_SHIFT (3U)
/*! SPIDEN - Secure invasive debug fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPIDEN(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPIDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_SPIDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_TAPEN_MASK  (0x10U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_TAPEN_SHIFT (4U)
/*! TAPEN - JTAG TAP fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_TAPEN(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_TAPEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_TAPEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_ISPCMDEN_MASK (0x40U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_ISPCMDEN_SHIFT (6U)
/*! ISPCMDEN - ISP Boot Command fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_ISPCMDEN(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_ISPCMDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_ISPCMDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_PMCMDEN_MASK (0x80U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_PMCMDEN_SHIFT (7U)
/*! PMCMDEN - Programmers Mode fixed state
 *  0b0..Disable
 *  0b1..Enable
 */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_PMCMDEN(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_PMCMDEN_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_PMCMDEN_MASK)

#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_INVERSE_VALUE_MASK (0xFFFF0000U)
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_INVERSE_VALUE_SHIFT (16U)
/*! INVERSE_VALUE - inverse value of bits [15:0] */
#define FLASH_CMPA_DCFG_CC_SOCU_DFLT_INVERSE_VALUE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_DCFG_CC_SOCU_DFLT_INVERSE_VALUE_SHIFT)) & FLASH_CMPA_DCFG_CC_SOCU_DFLT_INVERSE_VALUE_MASK)
/*! @} */

/*! @name VENDOR_USAGE - . */
/*! @{ */

#define FLASH_CMPA_VENDOR_USAGE_VENDOR_USAGE_MASK (0xFFFF0000U)
#define FLASH_CMPA_VENDOR_USAGE_VENDOR_USAGE_SHIFT (16U)
/*! VENDOR_USAGE - Upper 16 bits of vendor usage field defined in DAP. */
#define FLASH_CMPA_VENDOR_USAGE_VENDOR_USAGE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_VENDOR_USAGE_VENDOR_USAGE_SHIFT)) & FLASH_CMPA_VENDOR_USAGE_VENDOR_USAGE_MASK)
/*! @} */

/*! @name SECURE_BOOT_CFG - . */
/*! @{ */

#define FLASH_CMPA_SECURE_BOOT_CFG_RSA4K_MASK    (0x3U)
#define FLASH_CMPA_SECURE_BOOT_CFG_RSA4K_SHIFT   (0U)
/*! RSA4K - Use RSA4096 keys only.
 *  0b00..Allow RSA2048 and higher
 *  0b01..RSA4096 only
 *  0b10..RSA4096 only
 *  0b11..RSA4096 only
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_RSA4K(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_RSA4K_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_RSA4K_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_TZM_IMAGE_TYPE_MASK (0x300U)
#define FLASH_CMPA_SECURE_BOOT_CFG_TZM_IMAGE_TYPE_SHIFT (8U)
/*! TZM_IMAGE_TYPE - TrustZone-M mode
 *  0b00..TZ-M image mode is taken from application image header
 *  0b01..TZ-M disabled image, boots to non-secure mode
 *  0b10..TZ-M enabled image, boots to secure mode
 *  0b11..TZ-M enabled image with TZ-M preset, boot to secure mode TZ-M pre-configured by data from application image header
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_TZM_IMAGE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_TZM_IMAGE_TYPE_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_TZM_IMAGE_TYPE_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_BLOCK_SET_KEY_MASK (0xC00U)
#define FLASH_CMPA_SECURE_BOOT_CFG_BLOCK_SET_KEY_SHIFT (10U)
/*! BLOCK_SET_KEY - Block PUF key code generation
 *  0b00..Allow PUF Key Code generation
 *  0b01..Disable PUF Key Code generation
 *  0b10..Disable PUF Key Code generation
 *  0b11..Disable PUF Key Code generation
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_BLOCK_SET_KEY(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_BLOCK_SET_KEY_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_BLOCK_SET_KEY_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_SKIP_BOOT_SEED_MASK (0x30000U)
#define FLASH_CMPA_SECURE_BOOT_CFG_SKIP_BOOT_SEED_SHIFT (16U)
/*! SKIP_BOOT_SEED - Skip boot seed computation
 *  0b00..Enable BOOT_SEED
 *  0b01..Disable BOOT_SEED
 *  0b10..Disable BOOT_SEED
 *  0b11..Disable BOOT_SEED
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_SKIP_BOOT_SEED(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_SKIP_BOOT_SEED_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_SKIP_BOOT_SEED_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_NXP_CFG_MASK (0xC0000U)
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_NXP_CFG_SHIFT (18U)
/*! BOOT_SEED_INC_NXP_CFG - Include NXP area in BOOT SEED computation
 *  0b00..not included
 *  0b01..included
 *  0b10..included
 *  0b11..included
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_NXP_CFG(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_NXP_CFG_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_NXP_CFG_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_CUST_CFG_MASK (0x300000U)
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_CUST_CFG_SHIFT (20U)
/*! BOOT_SEED_CUST_CFG - Include Customer factory area (including keys) in BOOT SEED computation.
 *  0b00..not included
 *  0b01..included
 *  0b10..included
 *  0b11..included
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_CUST_CFG(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_CUST_CFG_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_CUST_CFG_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_SEC_EPOCH_MASK (0xC00000U)
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_SEC_EPOCH_SHIFT (22U)
/*! BOOT_SEED_INC_SEC_EPOCH - Include security EPOCH in BOOT_SEED computation.
 *  0b00..not included
 *  0b01..included
 *  0b10..included
 *  0b11..included
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_SEC_EPOCH(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_SEC_EPOCH_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_BOOT_SEED_INC_SEC_EPOCH_MASK)

#define FLASH_CMPA_SECURE_BOOT_CFG_SEC_BOOT_EN_MASK (0xC0000000U)
#define FLASH_CMPA_SECURE_BOOT_CFG_SEC_BOOT_EN_SHIFT (30U)
/*! SEC_BOOT_EN - Secure boot enable
 *  0b00..Plain image (internal flash with or without CRC)
 *  0b01..Boot signed images. (internal flash, RSA signed)
 *  0b10..Boot signed images. (internal flash, RSA signed)
 *  0b11..Boot signed images. (internal flash, RSA signed)
 */
#define FLASH_CMPA_SECURE_BOOT_CFG_SEC_BOOT_EN(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SECURE_BOOT_CFG_SEC_BOOT_EN_SHIFT)) & FLASH_CMPA_SECURE_BOOT_CFG_SEC_BOOT_EN_MASK)
/*! @} */

/*! @name PRINCE_CFG - Prince Configuration */
/*! @{ */

#define FLASH_CMPA_PRINCE_CFG_GEE_MASK           (0x2U)
#define FLASH_CMPA_PRINCE_CFG_GEE_SHIFT          (1U)
/*! GEE - Global Encryption Enable */
#define FLASH_CMPA_PRINCE_CFG_GEE(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_PRINCE_CFG_GEE_SHIFT)) & FLASH_CMPA_PRINCE_CFG_GEE_MASK)

#define FLASH_CMPA_PRINCE_CFG_GDE_MASK           (0x20U)
#define FLASH_CMPA_PRINCE_CFG_GDE_SHIFT          (5U)
/*! GDE - Global Decryption Enable */
#define FLASH_CMPA_PRINCE_CFG_GDE(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_PRINCE_CFG_GDE_SHIFT)) & FLASH_CMPA_PRINCE_CFG_GDE_MASK)

#define FLASH_CMPA_PRINCE_CFG_SLK_MASK           (0x200U)
#define FLASH_CMPA_PRINCE_CFG_SLK_SHIFT          (9U)
/*! SLK - System Lock Enable */
#define FLASH_CMPA_PRINCE_CFG_SLK(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_PRINCE_CFG_SLK_SHIFT)) & FLASH_CMPA_PRINCE_CFG_SLK_MASK)

#define FLASH_CMPA_PRINCE_CFG_GLK_MASK           (0x2000U)
#define FLASH_CMPA_PRINCE_CFG_GLK_SHIFT          (13U)
/*! GLK - Global Lock Enable */
#define FLASH_CMPA_PRINCE_CFG_GLK(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_PRINCE_CFG_GLK_SHIFT)) & FLASH_CMPA_PRINCE_CFG_GLK_MASK)
/*! @} */

/*! @name NPX_REGION_KEY_DIR_BMAPCTX - Bitmap Control for Memory Context 0..Bitmap Control for Memory Context 3 */
/*! @{ */

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_MASK (0x1U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_SHIFT (0U)
/*! BEN0 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN0(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_MASK (0x2U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_SHIFT (1U)
/*! BEN1 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN1(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_MASK (0x4U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_SHIFT (2U)
/*! BEN2 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN2(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_MASK (0x8U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_SHIFT (3U)
/*! BEN3 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN3(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_MASK (0x10U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_SHIFT (4U)
/*! BEN4 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN4(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_MASK (0x20U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_SHIFT (5U)
/*! BEN5 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN5(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_MASK (0x40U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_SHIFT (6U)
/*! BEN6 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN6(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_MASK (0x80U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_SHIFT (7U)
/*! BEN7 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN7(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_MASK (0x100U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_SHIFT (8U)
/*! BEN8 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN8(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_MASK (0x200U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_SHIFT (9U)
/*! BEN9 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN9(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_MASK (0x400U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_SHIFT (10U)
/*! BEN10 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN10(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_MASK (0x800U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_SHIFT (11U)
/*! BEN11 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN11(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_MASK (0x1000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_SHIFT (12U)
/*! BEN12 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN12(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_MASK (0x2000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_SHIFT (13U)
/*! BEN13 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN13(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_MASK (0x4000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_SHIFT (14U)
/*! BEN14 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN14(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_MASK (0x8000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_SHIFT (15U)
/*! BEN15 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN15(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_MASK (0x10000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_SHIFT (16U)
/*! BEN16 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN16(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_MASK (0x20000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_SHIFT (17U)
/*! BEN17 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN17(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_MASK (0x40000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_SHIFT (18U)
/*! BEN18 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN18(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_MASK (0x80000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_SHIFT (19U)
/*! BEN19 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN19(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_MASK (0x100000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_SHIFT (20U)
/*! BEN20 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN20(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_MASK (0x200000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_SHIFT (21U)
/*! BEN21 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN21(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_MASK (0x400000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_SHIFT (22U)
/*! BEN22 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN22(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_MASK (0x800000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_SHIFT (23U)
/*! BEN23 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN23(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_MASK (0x1000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_SHIFT (24U)
/*! BEN24 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN24(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_MASK (0x2000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_SHIFT (25U)
/*! BEN25 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN25(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_MASK (0x4000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_SHIFT (26U)
/*! BEN26 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN26(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_MASK (0x8000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_SHIFT (27U)
/*! BEN27 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN27(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_MASK (0x10000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_SHIFT (28U)
/*! BEN28 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN28(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_MASK (0x20000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_SHIFT (29U)
/*! BEN29 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN29(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_MASK (0x40000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_SHIFT (30U)
/*! BEN30 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN30(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_MASK)

#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_MASK (0x80000000U)
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_SHIFT (31U)
/*! BEN31 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN31(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_SHIFT)) & FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_MASK)
/*! @} */

/* The count of FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX */
#define FLASH_CMPA_NPX_REGION_KEY_DIR_BMAPCTX_COUNT (4U)

/*! @name BLE_UNIQUE_ADDRESS0 - BLE_UNIQUE_ADDRESS part 1 */
/*! @{ */

#define FLASH_CMPA_BLE_UNIQUE_ADDRESS0_BLE_UNIQUE_ADDRESS_31_0_MASK (0xFFFFFFFFU)
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS0_BLE_UNIQUE_ADDRESS_31_0_SHIFT (0U)
/*! BLE_UNIQUE_ADDRESS_31_0 - Bits 31 downto 0 of the BLE Unique Address to be used when BLE_UNIQUE_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS0_BLE_UNIQUE_ADDRESS_31_0(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BLE_UNIQUE_ADDRESS0_BLE_UNIQUE_ADDRESS_31_0_SHIFT)) & FLASH_CMPA_BLE_UNIQUE_ADDRESS0_BLE_UNIQUE_ADDRESS_31_0_MASK)
/*! @} */

/*! @name BLE_UNIQUE_ADDRESS1 - BLE_UNIQUE_ADDRESS part 2 */
/*! @{ */

#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_47_32_MASK (0xFFFFU)
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_47_32_SHIFT (0U)
/*! BLE_UNIQUE_ADDRESS_47_32 - Bits 47 downto 32 of the BLE Unique Address to be used when BLE_UNIQUE_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_47_32(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_47_32_SHIFT)) & FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_47_32_MASK)

#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_MASK (0xFFFF0000U)
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_SHIFT (16U)
/*! BLE_UNIQUE_ADDRESS_VALID - Use 48-bit value from BLE_UNIQUE_ADDRESS field as BLE address when
 *    this field is equal to 0xC3A5. If this field is different from 0xC3A5, check
 *    BLE_DEFAULT_ADDRESS_VALID field in NMPA to know which address to use.
 */
#define FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_SHIFT)) & FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_MASK)
/*! @} */

/*! @name FLASH_REMAP_SIZE - This 32-bit register contains the size of the image to remap, in bytes. */
/*! @{ */

#define FLASH_CMPA_FLASH_REMAP_SIZE_FLASH_REMAP_SIZE_MASK (0xFFFFFFFFU)
#define FLASH_CMPA_FLASH_REMAP_SIZE_FLASH_REMAP_SIZE_SHIFT (0U)
/*! FLASH_REMAP_SIZE - This 32-bit register contains the size of the image to remap, in bytes. */
#define FLASH_CMPA_FLASH_REMAP_SIZE_FLASH_REMAP_SIZE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_FLASH_REMAP_SIZE_FLASH_REMAP_SIZE_SHIFT)) & FLASH_CMPA_FLASH_REMAP_SIZE_FLASH_REMAP_SIZE_MASK)
/*! @} */

/*! @name FLASH_REMAP_OFFSET - This 32-bit register contains the offset by which the image is to be remapped. */
/*! @{ */

#define FLASH_CMPA_FLASH_REMAP_OFFSET_FLASH_REMAP_OFFSET_MASK (0xFFFFFFFFU)
#define FLASH_CMPA_FLASH_REMAP_OFFSET_FLASH_REMAP_OFFSET_SHIFT (0U)
/*! FLASH_REMAP_OFFSET - This 32-bit register contains the offset by which the image is to be remapped. */
#define FLASH_CMPA_FLASH_REMAP_OFFSET_FLASH_REMAP_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_FLASH_REMAP_OFFSET_FLASH_REMAP_OFFSET_SHIFT)) & FLASH_CMPA_FLASH_REMAP_OFFSET_FLASH_REMAP_OFFSET_MASK)
/*! @} */

/*! @name ROTKH - ROTKH0 for Root of Trust Keys Table hash[255:224]..ROTKH7 for Root of Trust Keys Table hash[31:0] */
/*! @{ */

#define FLASH_CMPA_ROTKH_FIELD_MASK              (0xFFFFFFFFU)
#define FLASH_CMPA_ROTKH_FIELD_SHIFT             (0U)
#define FLASH_CMPA_ROTKH_FIELD(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_ROTKH_FIELD_SHIFT)) & FLASH_CMPA_ROTKH_FIELD_MASK)
/*! @} */

/*! @name CUSTOMER_DEFINED - Customer Defined (Programable through ROM API) */
/*! @{ */

#define FLASH_CMPA_CUSTOMER_DEFINED_FIELD_MASK   (0xFFFFFFFFU)
#define FLASH_CMPA_CUSTOMER_DEFINED_FIELD_SHIFT  (0U)
/*! FIELD - . */
#define FLASH_CMPA_CUSTOMER_DEFINED_FIELD(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_CUSTOMER_DEFINED_FIELD_SHIFT)) & FLASH_CMPA_CUSTOMER_DEFINED_FIELD_MASK)
/*! @} */

/*! @name SHA256_DIGEST - SHA256_DIGEST0 for DIGEST[31:0]..SHA256_DIGEST7 for DIGEST[255:224] */
/*! @{ */

#define FLASH_CMPA_SHA256_DIGEST_FIELD_MASK      (0xFFFFFFFFU)
#define FLASH_CMPA_SHA256_DIGEST_FIELD_SHIFT     (0U)
/*! FIELD - . */
#define FLASH_CMPA_SHA256_DIGEST_FIELD(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_CMPA_SHA256_DIGEST_FIELD_SHIFT)) & FLASH_CMPA_SHA256_DIGEST_FIELD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_CMPA_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_CMPA_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_CMPA_H_ */

