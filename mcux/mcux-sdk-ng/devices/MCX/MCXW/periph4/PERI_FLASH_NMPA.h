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
**         CMSIS Peripheral Access Layer for FLASH_NMPA
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
 * @file PERI_FLASH_NMPA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_NMPA
 *
 * CMSIS Peripheral Access Layer for FLASH_NMPA
 */

#if !defined(PERI_FLASH_NMPA_H_)
#define PERI_FLASH_NMPA_H_                       /**< Symbol preventing repeated inclusion */

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
   -- FLASH_NMPA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_NMPA_Peripheral_Access_Layer FLASH_NMPA Peripheral Access Layer
 * @{
 */

/** FLASH_NMPA - Size of Registers Arrays */
#define FLASH_NMPA_UUID_UUID_ARRAY_UUID_ARRAY_COUNT 4u

/** FLASH_NMPA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2912];
  __IO uint32_t DEVICE_TYPE;                       /**< offset: 0xB60 */
       uint8_t RESERVED_1[4];
  struct {                                         /* offset: 0xB68 */
    __IO uint32_t BLE_DEFAULT_ADDRESS0;              /**< BLE_DEFAULT_ADDRESS part 1, offset: 0xB68 */
    __IO uint32_t BLE_DEFAULT_ADDRESS1;              /**< BLE_DEFAULT_ADDRESS part 2, offset: 0xB6C */
  } BLE_DEFAULT_ADDRESS;
  union {                                          /* offset: 0xB70 */
    struct {                                         /* offset: 0xB70 */
      __IO uint32_t UUID_0;                            /**< offset: 0xB70 */
      __IO uint32_t UUID_1;                            /**< offset: 0xB74 */
      __IO uint32_t UUID_2;                            /**< offset: 0xB78 */
      __IO uint32_t UUID_3;                            /**< offset: 0xB7C */
    } UUID;
    __IO uint32_t UUID_ARRAY[FLASH_NMPA_UUID_UUID_ARRAY_UUID_ARRAY_COUNT];   /**< array offset: 0xB70, array step: 0x4 */
  };
       uint8_t RESERVED_2[44];
  __IO uint32_t BLE_TEST;                          /**< BLE_TEST, offset: 0xBAC */
       uint8_t RESERVED_3[1104];
  __IO uint32_t LOTID_0;                           /**< MCXW23 Lot ID, offset: 0x1000 */
  __IO uint32_t LOTID_1;                           /**< MCXW23 Lot ID, offset: 0x1004 */
  __IO uint32_t WAFERID;                           /**< MCXW23 Wafer ID, offset: 0x1008 */
  __IO uint32_t DIE_X_Y;                           /**< MCXW23 Die Coordinates, offset: 0x100C */
} FLASH_NMPA_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_NMPA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_NMPA_Register_Masks FLASH_NMPA Register Masks
 * @{
 */

/*! @name DEVICE_TYPE -  */
/*! @{ */

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK (0xFFFFU)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT (0U)
/*! DEVICE_TYPE_NUM - Device type number. (E.g : MCXW23 stored as 5204 decimal) */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK (0x10000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT (16U)
/*! DEVICE_TYPE_SEC - Security device type: 0: NHS52xx (Non Secure Family) 1: NHS52Sxx (Secure Family) */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK (0xF00000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT (20U)
/*! DEVICE_TYPE_PKG - Device package type: 0010 : HVQFN 0100 : VFBGA 1000 : WLCSP */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK (0xFF000000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT (24U)
/*! DEVICE_TYPE_PIN - Number of pins on the package. */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK)
/*! @} */

/*! @name BLE_DEFAULT_ADDRESS0 - BLE_DEFAULT_ADDRESS part 1 */
/*! @{ */

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_MASK (0xFFFFFFU)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_SHIFT (0U)
/*! BLE_DEFAULT_ADDRESS_23_0 - Bits 24 downto 0 of the BLE Default Address to be used when BLE_DEFAULT_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_MASK)

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_MASK (0xFF000000U)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_SHIFT (24U)
/*! BLE_DEFAULT_ADDRESS_VALID - Use 48-bit value from BLE_DEFAULT_ADDRESS field as BLE address when
 *    this field is equal to 0xA5 and BLE_DEFAULT_ADDRESS_VALID_DP = 0xC3. If these fields are
 *    different from 0xC3A5, use a random number as BLE address
 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_MASK)
/*! @} */

/*! @name BLE_DEFAULT_ADDRESS1 - BLE_DEFAULT_ADDRESS part 2 */
/*! @{ */

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_MASK (0xFFFFFFU)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_SHIFT (0U)
/*! BLE_DEFAULT_ADDRESS_47_24 - Bits 47 downto 24 of the BLE Default Address to be used when BLE_DEFAULT_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_MASK)

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_MASK (0xFF000000U)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_SHIFT (24U)
/*! BLE_DEFAULT_ADDRESS_VALID_DP - Use 48-bit value from BLE_DEFAULT_ADDRESS field as BLE address
 *    when this field is equal to 0xC3 and BLE_DEFAULT_ADDRESS_VALID = 0xA5. If these fields are
 *    different from 0xC3A5, use a random number as BLE address
 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_MASK)
/*! @} */

/*! @name UUID_0 -  */
/*! @{ */

#define FLASH_NMPA_UUID_0_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_0_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_0_FIELD_SHIFT)) & FLASH_NMPA_UUID_0_FIELD_MASK)
/*! @} */

/*! @name UUID_1 -  */
/*! @{ */

#define FLASH_NMPA_UUID_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_1_FIELD_SHIFT)) & FLASH_NMPA_UUID_1_FIELD_MASK)
/*! @} */

/*! @name UUID_2 -  */
/*! @{ */

#define FLASH_NMPA_UUID_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_2_FIELD_SHIFT)) & FLASH_NMPA_UUID_2_FIELD_MASK)
/*! @} */

/*! @name UUID_3 -  */
/*! @{ */

#define FLASH_NMPA_UUID_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_3_FIELD_SHIFT)) & FLASH_NMPA_UUID_3_FIELD_MASK)
/*! @} */

/*! @name UUID_ARRAY -  */
/*! @{ */

#define FLASH_NMPA_UUID_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_UUID_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_UUID_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_UUID_ARRAY */
#define FLASH_NMPA_UUID_ARRAY_COUNT              (4U)

/*! @name BLE_TEST - BLE_TEST */
/*! @{ */

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_MASK (0x10U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_SHIFT (4U)
/*! CHAN15_LRS8_PWR_LIMIT_SPUR - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_MASK (0x20U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_SHIFT (5U)
/*! CHAN31_LRS8_PWR_LIMIT_SPUR - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_MASK (0x40U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_SHIFT (6U)
/*! CHAN15_BLE1_PWR_LIMIT_SPUR - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_MASK (0x80U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_SHIFT (7U)
/*! CHAN31_BLE1_PWR_LIMIT_SPUR - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_MASK (0x100U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_SHIFT (8U)
/*! CHAN15_LRS8_PWR_LIMIT_NO_TEST - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_MASK (0x200U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_SHIFT (9U)
/*! CHAN31_LRS8_PWR_LIMIT_NO_TEST - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_MASK (0x400U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_SHIFT (10U)
/*! CHAN15_BLE1_PWR_LIMIT_NO_TEST - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_MASK (0x800U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_SHIFT (11U)
/*! CHAN31_BLE1_PWR_LIMIT_NO_TEST - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_MASK (0x100000U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_SHIFT (20U)
/*! CHAN15_LRS8_PWR_LIMIT_MOD - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_MASK (0x200000U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_SHIFT (21U)
/*! CHAN31_LRS8_PWR_LIMIT_MOD - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_MASK (0x400000U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_SHIFT (22U)
/*! CHAN15_BLE1_PWR_LIMIT_MOD - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_MASK (0x800000U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_SHIFT (23U)
/*! CHAN31_BLE1_PWR_LIMIT_MOD - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_MASK   (0x1000000U)
#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_SHIFT  (24U)
/*! BLE_SPUR_TEST - If 0x1, BLE SPUR production test is run and passing */
#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_MASK    (0x2000000U)
#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_SHIFT   (25U)
/*! BLE_MOD_TEST - If 0x1, BLE SPUR production test is run and passing */
#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST_MASK     (0x4000000U)
#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST_SHIFT    (26U)
/*! BLE_NO_TEST - If 0x1, BLE NO production test is run but tx power limit is forced */
#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_NO_TEST_MASK)
/*! @} */

/*! @name LOTID_0 - MCXW23 Lot ID */
/*! @{ */

#define FLASH_NMPA_LOTID_0_LOTID_31_0_MASK       (0xFFFFFFFFU)
#define FLASH_NMPA_LOTID_0_LOTID_31_0_SHIFT      (0U)
/*! LOTID_31_0 - Bits 31 downto 0 for LotID */
#define FLASH_NMPA_LOTID_0_LOTID_31_0(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LOTID_0_LOTID_31_0_SHIFT)) & FLASH_NMPA_LOTID_0_LOTID_31_0_MASK)
/*! @} */

/*! @name LOTID_1 - MCXW23 Lot ID */
/*! @{ */

#define FLASH_NMPA_LOTID_1_LOTID_63_32_MASK      (0xFFFFFFFFU)
#define FLASH_NMPA_LOTID_1_LOTID_63_32_SHIFT     (0U)
/*! LOTID_63_32 - Bits 63 downto 32 for LotID */
#define FLASH_NMPA_LOTID_1_LOTID_63_32(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LOTID_1_LOTID_63_32_SHIFT)) & FLASH_NMPA_LOTID_1_LOTID_63_32_MASK)
/*! @} */

/*! @name WAFERID - MCXW23 Wafer ID */
/*! @{ */

#define FLASH_NMPA_WAFERID_WAFERID_MASK          (0xFFFFFFFFU)
#define FLASH_NMPA_WAFERID_WAFERID_SHIFT         (0U)
/*! WAFERID - WaferID */
#define FLASH_NMPA_WAFERID_WAFERID(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_WAFERID_WAFERID_SHIFT)) & FLASH_NMPA_WAFERID_WAFERID_MASK)
/*! @} */

/*! @name DIE_X_Y - MCXW23 Die Coordinates */
/*! @{ */

#define FLASH_NMPA_DIE_X_Y_DIE_X_MASK            (0xFFFFU)
#define FLASH_NMPA_DIE_X_Y_DIE_X_SHIFT           (0U)
/*! DIE_X - Die X coordinates */
#define FLASH_NMPA_DIE_X_Y_DIE_X(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DIE_X_Y_DIE_X_SHIFT)) & FLASH_NMPA_DIE_X_Y_DIE_X_MASK)

#define FLASH_NMPA_DIE_X_Y_DIE_Y_MASK            (0xFFFF0000U)
#define FLASH_NMPA_DIE_X_Y_DIE_Y_SHIFT           (16U)
/*! DIE_Y - Die Y coordinates */
#define FLASH_NMPA_DIE_X_Y_DIE_Y(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DIE_X_Y_DIE_Y_SHIFT)) & FLASH_NMPA_DIE_X_Y_DIE_Y_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FLASH_NMPA_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_NMPA_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_NMPA_H_ */

