/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_OCOTP.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_OCOTP
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
#if !defined(S32Z2_OCOTP_H_)  /* Check if memory map has not been already included */
#define S32Z2_OCOTP_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- OCOTP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Peripheral_Access_Layer OCOTP Peripheral Access Layer
 * @{
 */

/** OCOTP - Size of Registers Arrays */
#define OCOTP_GPR_COUNT                           2u
#define OCOTP_STICKY_REG_COUNT                    2u
#define OCOTP_SEC_COUNT                           4u
#define OCOTP_DED_COUNT                           4u
#define OCOTP_SHADOWS_COUNT                       128u

/** OCOTP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL_SYS;                          /**< System master's control, offset: 0x0 */
  __IO uint32_t ADDR_SYS;                          /**< System master's eFuse address for read or write operation, offset: 0x4 */
  __IO uint32_t WRDATA_SYS;                        /**< System master's eFuse write data, offset: 0x8 */
  __I  uint32_t RDATA_SYS;                         /**< System master's eFuse read data, offset: 0xC */
  uint8_t RESERVED_0[32];
  __IO uint32_t CTRL_FBX;                          /**< FBXC control, offset: 0x30 */
  __IO uint32_t CRC_RGN_SYS;                       /**< eFuse region for CRC validation, offset: 0x34 */
  __IO uint32_t CRC_ADDR_SYS;                      /**< Pre-calculated CRC eFuse address for comparison, offset: 0x38 */
  __I  uint32_t CRC_VALUE_SYS;                     /**< CRC calculated from the eFuses, offset: 0x3C */
  __IO uint32_t GPR[OCOTP_GPR_COUNT];              /**< General purpose, array offset: 0x40, array step: 0x4 */
  uint8_t RESERVED_1[8];
  __IO uint32_t STATUS_SYS;                        /**< System master's access status, offset: 0x50 */
  uint8_t RESERVED_2[8];
  __I  uint32_t VERSION;                           /**< OCOTP design version, offset: 0x5C */
  __IO uint32_t STR[OCOTP_STICKY_REG_COUNT];       /**< Sticky, array offset: 0x60, array step: 0x4 */
  uint8_t RESERVED_3[8];
  __I  uint32_t SEC[OCOTP_SEC_COUNT];              /**< ECC status for single-bit ECC error, array offset: 0x70, array step: 0x4 */
  uint8_t RESERVED_4[48];
  __I  uint32_t DED[OCOTP_DED_COUNT];              /**< ECC status for double-bit ECC error, array offset: 0xB0, array step: 0x4 */
  uint8_t RESERVED_5[48];
  __IO uint32_t ERR_INJCTR;                        /**< ECC error injector, offset: 0xF0 */
  uint8_t RESERVED_6[268];
  __IO uint32_t SHADOWS[OCOTP_SHADOWS_COUNT];      /**< Shadow, array offset: 0x200, array step: 0x4 */
} OCOTP_Type, *OCOTP_MemMapPtr;

/** Number of instances of the OCOTP module. */
#define OCOTP_INSTANCE_COUNT                     (1u)

/* OCOTP - Peripheral instance base addresses */
/** Peripheral OCOTP base address */
#define IP_OCOTP_BASE                            (0x423B0000u)
/** Peripheral OCOTP base pointer */
#define IP_OCOTP                                 ((OCOTP_Type *)IP_OCOTP_BASE)
/** Array initializer of OCOTP peripheral base addresses */
#define IP_OCOTP_BASE_ADDRS                      { IP_OCOTP_BASE }
/** Array initializer of OCOTP peripheral base pointers */
#define IP_OCOTP_BASE_PTRS                       { IP_OCOTP }

/* ----------------------------------------------------------------------------
   -- OCOTP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OCOTP_Register_Masks OCOTP Register Masks
 * @{
 */

/*! @name CTRL_SYS - System master's control */
/*! @{ */

#define OCOTP_CTRL_SYS_CRC_TEST_MASK             (0x2U)
#define OCOTP_CTRL_SYS_CRC_TEST_SHIFT            (1U)
#define OCOTP_CTRL_SYS_CRC_TEST_WIDTH            (1U)
#define OCOTP_CTRL_SYS_CRC_TEST(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SYS_CRC_TEST_SHIFT)) & OCOTP_CTRL_SYS_CRC_TEST_MASK)

#define OCOTP_CTRL_SYS_RD_WR_MASK                (0x3CU)
#define OCOTP_CTRL_SYS_RD_WR_SHIFT               (2U)
#define OCOTP_CTRL_SYS_RD_WR_WIDTH               (4U)
#define OCOTP_CTRL_SYS_RD_WR(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SYS_RD_WR_SHIFT)) & OCOTP_CTRL_SYS_RD_WR_MASK)

#define OCOTP_CTRL_SYS_AUTH_KEY_MASK             (0xFFFF0000U)
#define OCOTP_CTRL_SYS_AUTH_KEY_SHIFT            (16U)
#define OCOTP_CTRL_SYS_AUTH_KEY_WIDTH            (16U)
#define OCOTP_CTRL_SYS_AUTH_KEY(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_SYS_AUTH_KEY_SHIFT)) & OCOTP_CTRL_SYS_AUTH_KEY_MASK)
/*! @} */

/*! @name ADDR_SYS - System master's eFuse address for read or write operation */
/*! @{ */

#define OCOTP_ADDR_SYS_ADDR_MASK                 (0xFFFFU)
#define OCOTP_ADDR_SYS_ADDR_SHIFT                (0U)
#define OCOTP_ADDR_SYS_ADDR_WIDTH                (16U)
#define OCOTP_ADDR_SYS_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_ADDR_SYS_ADDR_SHIFT)) & OCOTP_ADDR_SYS_ADDR_MASK)
/*! @} */

/*! @name WRDATA_SYS - System master's eFuse write data */
/*! @{ */

#define OCOTP_WRDATA_SYS_DATA_MASK               (0xFFFFFFFFU)
#define OCOTP_WRDATA_SYS_DATA_SHIFT              (0U)
#define OCOTP_WRDATA_SYS_DATA_WIDTH              (32U)
#define OCOTP_WRDATA_SYS_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_WRDATA_SYS_DATA_SHIFT)) & OCOTP_WRDATA_SYS_DATA_MASK)
/*! @} */

/*! @name RDATA_SYS - System master's eFuse read data */
/*! @{ */

#define OCOTP_RDATA_SYS_DATA_MASK                (0xFFFFFFFFU)
#define OCOTP_RDATA_SYS_DATA_SHIFT               (0U)
#define OCOTP_RDATA_SYS_DATA_WIDTH               (32U)
#define OCOTP_RDATA_SYS_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_RDATA_SYS_DATA_SHIFT)) & OCOTP_RDATA_SYS_DATA_MASK)
/*! @} */

/*! @name CTRL_FBX - FBXC control */
/*! @{ */

#define OCOTP_CTRL_FBX_SEC_RST_MASK              (0x1U)
#define OCOTP_CTRL_FBX_SEC_RST_SHIFT             (0U)
#define OCOTP_CTRL_FBX_SEC_RST_WIDTH             (1U)
#define OCOTP_CTRL_FBX_SEC_RST(x)                (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_FBX_SEC_RST_SHIFT)) & OCOTP_CTRL_FBX_SEC_RST_MASK)

#define OCOTP_CTRL_FBX_SEC_MODE_MASK             (0x100U)
#define OCOTP_CTRL_FBX_SEC_MODE_SHIFT            (8U)
#define OCOTP_CTRL_FBX_SEC_MODE_WIDTH            (1U)
#define OCOTP_CTRL_FBX_SEC_MODE(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_FBX_SEC_MODE_SHIFT)) & OCOTP_CTRL_FBX_SEC_MODE_MASK)

#define OCOTP_CTRL_FBX_IPG_STOP_MASK             (0x20000U)
#define OCOTP_CTRL_FBX_IPG_STOP_SHIFT            (17U)
#define OCOTP_CTRL_FBX_IPG_STOP_WIDTH            (1U)
#define OCOTP_CTRL_FBX_IPG_STOP(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_FBX_IPG_STOP_SHIFT)) & OCOTP_CTRL_FBX_IPG_STOP_MASK)

#define OCOTP_CTRL_FBX_IPG_STOP_ACK_MASK         (0x40000U)
#define OCOTP_CTRL_FBX_IPG_STOP_ACK_SHIFT        (18U)
#define OCOTP_CTRL_FBX_IPG_STOP_ACK_WIDTH        (1U)
#define OCOTP_CTRL_FBX_IPG_STOP_ACK(x)           (((uint32_t)(((uint32_t)(x)) << OCOTP_CTRL_FBX_IPG_STOP_ACK_SHIFT)) & OCOTP_CTRL_FBX_IPG_STOP_ACK_MASK)
/*! @} */

/*! @name CRC_RGN_SYS - eFuse region for CRC validation */
/*! @{ */

#define OCOTP_CRC_RGN_SYS_START_ADDR_MASK        (0xFFFFU)
#define OCOTP_CRC_RGN_SYS_START_ADDR_SHIFT       (0U)
#define OCOTP_CRC_RGN_SYS_START_ADDR_WIDTH       (16U)
#define OCOTP_CRC_RGN_SYS_START_ADDR(x)          (((uint32_t)(((uint32_t)(x)) << OCOTP_CRC_RGN_SYS_START_ADDR_SHIFT)) & OCOTP_CRC_RGN_SYS_START_ADDR_MASK)

#define OCOTP_CRC_RGN_SYS_END_ADDR_MASK          (0xFFFF0000U)
#define OCOTP_CRC_RGN_SYS_END_ADDR_SHIFT         (16U)
#define OCOTP_CRC_RGN_SYS_END_ADDR_WIDTH         (16U)
#define OCOTP_CRC_RGN_SYS_END_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << OCOTP_CRC_RGN_SYS_END_ADDR_SHIFT)) & OCOTP_CRC_RGN_SYS_END_ADDR_MASK)
/*! @} */

/*! @name CRC_ADDR_SYS - Pre-calculated CRC eFuse address for comparison */
/*! @{ */

#define OCOTP_CRC_ADDR_SYS_ADDR_MASK             (0xFFFFU)
#define OCOTP_CRC_ADDR_SYS_ADDR_SHIFT            (0U)
#define OCOTP_CRC_ADDR_SYS_ADDR_WIDTH            (16U)
#define OCOTP_CRC_ADDR_SYS_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CRC_ADDR_SYS_ADDR_SHIFT)) & OCOTP_CRC_ADDR_SYS_ADDR_MASK)
/*! @} */

/*! @name CRC_VALUE_SYS - CRC calculated from the eFuses */
/*! @{ */

#define OCOTP_CRC_VALUE_SYS_CRC_MASK             (0xFFFFFFFFU)
#define OCOTP_CRC_VALUE_SYS_CRC_SHIFT            (0U)
#define OCOTP_CRC_VALUE_SYS_CRC_WIDTH            (32U)
#define OCOTP_CRC_VALUE_SYS_CRC(x)               (((uint32_t)(((uint32_t)(x)) << OCOTP_CRC_VALUE_SYS_CRC_SHIFT)) & OCOTP_CRC_VALUE_SYS_CRC_MASK)
/*! @} */

/*! @name GPR - General purpose */
/*! @{ */

#define OCOTP_GPR_GPR_MASK                       (0xFFFFFFFFU)
#define OCOTP_GPR_GPR_SHIFT                      (0U)
#define OCOTP_GPR_GPR_WIDTH                      (32U)
#define OCOTP_GPR_GPR(x)                         (((uint32_t)(((uint32_t)(x)) << OCOTP_GPR_GPR_SHIFT)) & OCOTP_GPR_GPR_MASK)
/*! @} */

/*! @name STATUS_SYS - System master's access status */
/*! @{ */

#define OCOTP_STATUS_SYS_BUSY_MASK               (0x1U)
#define OCOTP_STATUS_SYS_BUSY_SHIFT              (0U)
#define OCOTP_STATUS_SYS_BUSY_WIDTH              (1U)
#define OCOTP_STATUS_SYS_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_STATUS_SYS_BUSY_SHIFT)) & OCOTP_STATUS_SYS_BUSY_MASK)

#define OCOTP_STATUS_SYS_CRC_FAIL_MASK           (0x2U)
#define OCOTP_STATUS_SYS_CRC_FAIL_SHIFT          (1U)
#define OCOTP_STATUS_SYS_CRC_FAIL_WIDTH          (1U)
#define OCOTP_STATUS_SYS_CRC_FAIL(x)             (((uint32_t)(((uint32_t)(x)) << OCOTP_STATUS_SYS_CRC_FAIL_SHIFT)) & OCOTP_STATUS_SYS_CRC_FAIL_MASK)

#define OCOTP_STATUS_SYS_ERROR_MASK              (0x4U)
#define OCOTP_STATUS_SYS_ERROR_SHIFT             (2U)
#define OCOTP_STATUS_SYS_ERROR_WIDTH             (1U)
#define OCOTP_STATUS_SYS_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << OCOTP_STATUS_SYS_ERROR_SHIFT)) & OCOTP_STATUS_SYS_ERROR_MASK)
/*! @} */

/*! @name VERSION - OCOTP design version */
/*! @{ */

#define OCOTP_VERSION_STEP_MASK                  (0xFFFFU)
#define OCOTP_VERSION_STEP_SHIFT                 (0U)
#define OCOTP_VERSION_STEP_WIDTH                 (16U)
#define OCOTP_VERSION_STEP(x)                    (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_STEP_SHIFT)) & OCOTP_VERSION_STEP_MASK)

#define OCOTP_VERSION_MINOR_MASK                 (0xFF0000U)
#define OCOTP_VERSION_MINOR_SHIFT                (16U)
#define OCOTP_VERSION_MINOR_WIDTH                (8U)
#define OCOTP_VERSION_MINOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MINOR_SHIFT)) & OCOTP_VERSION_MINOR_MASK)

#define OCOTP_VERSION_MAJOR_MASK                 (0xFF000000U)
#define OCOTP_VERSION_MAJOR_SHIFT                (24U)
#define OCOTP_VERSION_MAJOR_WIDTH                (8U)
#define OCOTP_VERSION_MAJOR(x)                   (((uint32_t)(((uint32_t)(x)) << OCOTP_VERSION_MAJOR_SHIFT)) & OCOTP_VERSION_MAJOR_MASK)
/*! @} */

/*! @name STR - Sticky */
/*! @{ */

#define OCOTP_STR_STR_MASK                       (0xFFFFFFFFU)
#define OCOTP_STR_STR_SHIFT                      (0U)
#define OCOTP_STR_STR_WIDTH                      (32U)
#define OCOTP_STR_STR(x)                         (((uint32_t)(((uint32_t)(x)) << OCOTP_STR_STR_SHIFT)) & OCOTP_STR_STR_MASK)
/*! @} */

/*! @name SEC - ECC status for single-bit ECC error */
/*! @{ */

#define OCOTP_SEC_SEC1_MASK                      (0x1U)
#define OCOTP_SEC_SEC1_SHIFT                     (0U)
#define OCOTP_SEC_SEC1_WIDTH                     (1U)
#define OCOTP_SEC_SEC1(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC1_SHIFT)) & OCOTP_SEC_SEC1_MASK)

#define OCOTP_SEC_SEC2_MASK                      (0x2U)
#define OCOTP_SEC_SEC2_SHIFT                     (1U)
#define OCOTP_SEC_SEC2_WIDTH                     (1U)
#define OCOTP_SEC_SEC2(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC2_SHIFT)) & OCOTP_SEC_SEC2_MASK)

#define OCOTP_SEC_SEC3_MASK                      (0x4U)
#define OCOTP_SEC_SEC3_SHIFT                     (2U)
#define OCOTP_SEC_SEC3_WIDTH                     (1U)
#define OCOTP_SEC_SEC3(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC3_SHIFT)) & OCOTP_SEC_SEC3_MASK)

#define OCOTP_SEC_SEC4_MASK                      (0x8U)
#define OCOTP_SEC_SEC4_SHIFT                     (3U)
#define OCOTP_SEC_SEC4_WIDTH                     (1U)
#define OCOTP_SEC_SEC4(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC4_SHIFT)) & OCOTP_SEC_SEC4_MASK)

#define OCOTP_SEC_SEC5_MASK                      (0x10U)
#define OCOTP_SEC_SEC5_SHIFT                     (4U)
#define OCOTP_SEC_SEC5_WIDTH                     (1U)
#define OCOTP_SEC_SEC5(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC5_SHIFT)) & OCOTP_SEC_SEC5_MASK)

#define OCOTP_SEC_SEC6_MASK                      (0x20U)
#define OCOTP_SEC_SEC6_SHIFT                     (5U)
#define OCOTP_SEC_SEC6_WIDTH                     (1U)
#define OCOTP_SEC_SEC6(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC6_SHIFT)) & OCOTP_SEC_SEC6_MASK)

#define OCOTP_SEC_SEC7_MASK                      (0x40U)
#define OCOTP_SEC_SEC7_SHIFT                     (6U)
#define OCOTP_SEC_SEC7_WIDTH                     (1U)
#define OCOTP_SEC_SEC7(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC7_SHIFT)) & OCOTP_SEC_SEC7_MASK)

#define OCOTP_SEC_SEC8_MASK                      (0x80U)
#define OCOTP_SEC_SEC8_SHIFT                     (7U)
#define OCOTP_SEC_SEC8_WIDTH                     (1U)
#define OCOTP_SEC_SEC8(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC8_SHIFT)) & OCOTP_SEC_SEC8_MASK)

#define OCOTP_SEC_SEC9_MASK                      (0x100U)
#define OCOTP_SEC_SEC9_SHIFT                     (8U)
#define OCOTP_SEC_SEC9_WIDTH                     (1U)
#define OCOTP_SEC_SEC9(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC9_SHIFT)) & OCOTP_SEC_SEC9_MASK)

#define OCOTP_SEC_SEC10_MASK                     (0x200U)
#define OCOTP_SEC_SEC10_SHIFT                    (9U)
#define OCOTP_SEC_SEC10_WIDTH                    (1U)
#define OCOTP_SEC_SEC10(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC10_SHIFT)) & OCOTP_SEC_SEC10_MASK)

#define OCOTP_SEC_SEC11_MASK                     (0x400U)
#define OCOTP_SEC_SEC11_SHIFT                    (10U)
#define OCOTP_SEC_SEC11_WIDTH                    (1U)
#define OCOTP_SEC_SEC11(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC11_SHIFT)) & OCOTP_SEC_SEC11_MASK)

#define OCOTP_SEC_SEC12_MASK                     (0x800U)
#define OCOTP_SEC_SEC12_SHIFT                    (11U)
#define OCOTP_SEC_SEC12_WIDTH                    (1U)
#define OCOTP_SEC_SEC12(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC12_SHIFT)) & OCOTP_SEC_SEC12_MASK)

#define OCOTP_SEC_SEC13_MASK                     (0x1000U)
#define OCOTP_SEC_SEC13_SHIFT                    (12U)
#define OCOTP_SEC_SEC13_WIDTH                    (1U)
#define OCOTP_SEC_SEC13(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC13_SHIFT)) & OCOTP_SEC_SEC13_MASK)

#define OCOTP_SEC_SEC14_MASK                     (0x2000U)
#define OCOTP_SEC_SEC14_SHIFT                    (13U)
#define OCOTP_SEC_SEC14_WIDTH                    (1U)
#define OCOTP_SEC_SEC14(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC14_SHIFT)) & OCOTP_SEC_SEC14_MASK)

#define OCOTP_SEC_SEC15_MASK                     (0x4000U)
#define OCOTP_SEC_SEC15_SHIFT                    (14U)
#define OCOTP_SEC_SEC15_WIDTH                    (1U)
#define OCOTP_SEC_SEC15(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC15_SHIFT)) & OCOTP_SEC_SEC15_MASK)

#define OCOTP_SEC_SEC16_MASK                     (0x8000U)
#define OCOTP_SEC_SEC16_SHIFT                    (15U)
#define OCOTP_SEC_SEC16_WIDTH                    (1U)
#define OCOTP_SEC_SEC16(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC16_SHIFT)) & OCOTP_SEC_SEC16_MASK)

#define OCOTP_SEC_SEC17_MASK                     (0x10000U)
#define OCOTP_SEC_SEC17_SHIFT                    (16U)
#define OCOTP_SEC_SEC17_WIDTH                    (1U)
#define OCOTP_SEC_SEC17(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC17_SHIFT)) & OCOTP_SEC_SEC17_MASK)

#define OCOTP_SEC_SEC18_MASK                     (0x20000U)
#define OCOTP_SEC_SEC18_SHIFT                    (17U)
#define OCOTP_SEC_SEC18_WIDTH                    (1U)
#define OCOTP_SEC_SEC18(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC18_SHIFT)) & OCOTP_SEC_SEC18_MASK)

#define OCOTP_SEC_SEC19_MASK                     (0x40000U)
#define OCOTP_SEC_SEC19_SHIFT                    (18U)
#define OCOTP_SEC_SEC19_WIDTH                    (1U)
#define OCOTP_SEC_SEC19(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC19_SHIFT)) & OCOTP_SEC_SEC19_MASK)

#define OCOTP_SEC_SEC20_MASK                     (0x80000U)
#define OCOTP_SEC_SEC20_SHIFT                    (19U)
#define OCOTP_SEC_SEC20_WIDTH                    (1U)
#define OCOTP_SEC_SEC20(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC20_SHIFT)) & OCOTP_SEC_SEC20_MASK)

#define OCOTP_SEC_SEC21_MASK                     (0x100000U)
#define OCOTP_SEC_SEC21_SHIFT                    (20U)
#define OCOTP_SEC_SEC21_WIDTH                    (1U)
#define OCOTP_SEC_SEC21(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC21_SHIFT)) & OCOTP_SEC_SEC21_MASK)

#define OCOTP_SEC_SEC22_MASK                     (0x200000U)
#define OCOTP_SEC_SEC22_SHIFT                    (21U)
#define OCOTP_SEC_SEC22_WIDTH                    (1U)
#define OCOTP_SEC_SEC22(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC22_SHIFT)) & OCOTP_SEC_SEC22_MASK)

#define OCOTP_SEC_SEC23_MASK                     (0x400000U)
#define OCOTP_SEC_SEC23_SHIFT                    (22U)
#define OCOTP_SEC_SEC23_WIDTH                    (1U)
#define OCOTP_SEC_SEC23(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC23_SHIFT)) & OCOTP_SEC_SEC23_MASK)

#define OCOTP_SEC_SEC24_MASK                     (0x800000U)
#define OCOTP_SEC_SEC24_SHIFT                    (23U)
#define OCOTP_SEC_SEC24_WIDTH                    (1U)
#define OCOTP_SEC_SEC24(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC24_SHIFT)) & OCOTP_SEC_SEC24_MASK)

#define OCOTP_SEC_SEC25_MASK                     (0x1000000U)
#define OCOTP_SEC_SEC25_SHIFT                    (24U)
#define OCOTP_SEC_SEC25_WIDTH                    (1U)
#define OCOTP_SEC_SEC25(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC25_SHIFT)) & OCOTP_SEC_SEC25_MASK)

#define OCOTP_SEC_SEC26_MASK                     (0x2000000U)
#define OCOTP_SEC_SEC26_SHIFT                    (25U)
#define OCOTP_SEC_SEC26_WIDTH                    (1U)
#define OCOTP_SEC_SEC26(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC26_SHIFT)) & OCOTP_SEC_SEC26_MASK)

#define OCOTP_SEC_SEC27_MASK                     (0x4000000U)
#define OCOTP_SEC_SEC27_SHIFT                    (26U)
#define OCOTP_SEC_SEC27_WIDTH                    (1U)
#define OCOTP_SEC_SEC27(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC27_SHIFT)) & OCOTP_SEC_SEC27_MASK)

#define OCOTP_SEC_SEC28_MASK                     (0x8000000U)
#define OCOTP_SEC_SEC28_SHIFT                    (27U)
#define OCOTP_SEC_SEC28_WIDTH                    (1U)
#define OCOTP_SEC_SEC28(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC28_SHIFT)) & OCOTP_SEC_SEC28_MASK)

#define OCOTP_SEC_SEC29_MASK                     (0x10000000U)
#define OCOTP_SEC_SEC29_SHIFT                    (28U)
#define OCOTP_SEC_SEC29_WIDTH                    (1U)
#define OCOTP_SEC_SEC29(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC29_SHIFT)) & OCOTP_SEC_SEC29_MASK)

#define OCOTP_SEC_SEC30_MASK                     (0x20000000U)
#define OCOTP_SEC_SEC30_SHIFT                    (29U)
#define OCOTP_SEC_SEC30_WIDTH                    (1U)
#define OCOTP_SEC_SEC30(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC30_SHIFT)) & OCOTP_SEC_SEC30_MASK)

#define OCOTP_SEC_SEC31_MASK                     (0x40000000U)
#define OCOTP_SEC_SEC31_SHIFT                    (30U)
#define OCOTP_SEC_SEC31_WIDTH                    (1U)
#define OCOTP_SEC_SEC31(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC31_SHIFT)) & OCOTP_SEC_SEC31_MASK)

#define OCOTP_SEC_SEC32_MASK                     (0x80000000U)
#define OCOTP_SEC_SEC32_SHIFT                    (31U)
#define OCOTP_SEC_SEC32_WIDTH                    (1U)
#define OCOTP_SEC_SEC32(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC32_SHIFT)) & OCOTP_SEC_SEC32_MASK)

#define OCOTP_SEC_SEC33_MASK                     (0x1U)
#define OCOTP_SEC_SEC33_SHIFT                    (0U)
#define OCOTP_SEC_SEC33_WIDTH                    (1U)
#define OCOTP_SEC_SEC33(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC33_SHIFT)) & OCOTP_SEC_SEC33_MASK)

#define OCOTP_SEC_SEC34_MASK                     (0x2U)
#define OCOTP_SEC_SEC34_SHIFT                    (1U)
#define OCOTP_SEC_SEC34_WIDTH                    (1U)
#define OCOTP_SEC_SEC34(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC34_SHIFT)) & OCOTP_SEC_SEC34_MASK)

#define OCOTP_SEC_SEC35_MASK                     (0x4U)
#define OCOTP_SEC_SEC35_SHIFT                    (2U)
#define OCOTP_SEC_SEC35_WIDTH                    (1U)
#define OCOTP_SEC_SEC35(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC35_SHIFT)) & OCOTP_SEC_SEC35_MASK)

#define OCOTP_SEC_SEC36_MASK                     (0x8U)
#define OCOTP_SEC_SEC36_SHIFT                    (3U)
#define OCOTP_SEC_SEC36_WIDTH                    (1U)
#define OCOTP_SEC_SEC36(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC36_SHIFT)) & OCOTP_SEC_SEC36_MASK)

#define OCOTP_SEC_SEC37_MASK                     (0x10U)
#define OCOTP_SEC_SEC37_SHIFT                    (4U)
#define OCOTP_SEC_SEC37_WIDTH                    (1U)
#define OCOTP_SEC_SEC37(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC37_SHIFT)) & OCOTP_SEC_SEC37_MASK)

#define OCOTP_SEC_SEC38_MASK                     (0x20U)
#define OCOTP_SEC_SEC38_SHIFT                    (5U)
#define OCOTP_SEC_SEC38_WIDTH                    (1U)
#define OCOTP_SEC_SEC38(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC38_SHIFT)) & OCOTP_SEC_SEC38_MASK)

#define OCOTP_SEC_SEC39_MASK                     (0x40U)
#define OCOTP_SEC_SEC39_SHIFT                    (6U)
#define OCOTP_SEC_SEC39_WIDTH                    (1U)
#define OCOTP_SEC_SEC39(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC39_SHIFT)) & OCOTP_SEC_SEC39_MASK)

#define OCOTP_SEC_SEC40_MASK                     (0x80U)
#define OCOTP_SEC_SEC40_SHIFT                    (7U)
#define OCOTP_SEC_SEC40_WIDTH                    (1U)
#define OCOTP_SEC_SEC40(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC40_SHIFT)) & OCOTP_SEC_SEC40_MASK)

#define OCOTP_SEC_SEC41_MASK                     (0x100U)
#define OCOTP_SEC_SEC41_SHIFT                    (8U)
#define OCOTP_SEC_SEC41_WIDTH                    (1U)
#define OCOTP_SEC_SEC41(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC41_SHIFT)) & OCOTP_SEC_SEC41_MASK)

#define OCOTP_SEC_SEC42_MASK                     (0x200U)
#define OCOTP_SEC_SEC42_SHIFT                    (9U)
#define OCOTP_SEC_SEC42_WIDTH                    (1U)
#define OCOTP_SEC_SEC42(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC42_SHIFT)) & OCOTP_SEC_SEC42_MASK)

#define OCOTP_SEC_SEC43_MASK                     (0x400U)
#define OCOTP_SEC_SEC43_SHIFT                    (10U)
#define OCOTP_SEC_SEC43_WIDTH                    (1U)
#define OCOTP_SEC_SEC43(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC43_SHIFT)) & OCOTP_SEC_SEC43_MASK)

#define OCOTP_SEC_SEC44_MASK                     (0x800U)
#define OCOTP_SEC_SEC44_SHIFT                    (11U)
#define OCOTP_SEC_SEC44_WIDTH                    (1U)
#define OCOTP_SEC_SEC44(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC44_SHIFT)) & OCOTP_SEC_SEC44_MASK)

#define OCOTP_SEC_SEC45_MASK                     (0x1000U)
#define OCOTP_SEC_SEC45_SHIFT                    (12U)
#define OCOTP_SEC_SEC45_WIDTH                    (1U)
#define OCOTP_SEC_SEC45(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC45_SHIFT)) & OCOTP_SEC_SEC45_MASK)

#define OCOTP_SEC_SEC46_MASK                     (0x2000U)
#define OCOTP_SEC_SEC46_SHIFT                    (13U)
#define OCOTP_SEC_SEC46_WIDTH                    (1U)
#define OCOTP_SEC_SEC46(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC46_SHIFT)) & OCOTP_SEC_SEC46_MASK)

#define OCOTP_SEC_SEC47_MASK                     (0x4000U)
#define OCOTP_SEC_SEC47_SHIFT                    (14U)
#define OCOTP_SEC_SEC47_WIDTH                    (1U)
#define OCOTP_SEC_SEC47(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC47_SHIFT)) & OCOTP_SEC_SEC47_MASK)

#define OCOTP_SEC_SEC48_MASK                     (0x8000U)
#define OCOTP_SEC_SEC48_SHIFT                    (15U)
#define OCOTP_SEC_SEC48_WIDTH                    (1U)
#define OCOTP_SEC_SEC48(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC48_SHIFT)) & OCOTP_SEC_SEC48_MASK)

#define OCOTP_SEC_SEC49_MASK                     (0x10000U)
#define OCOTP_SEC_SEC49_SHIFT                    (16U)
#define OCOTP_SEC_SEC49_WIDTH                    (1U)
#define OCOTP_SEC_SEC49(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC49_SHIFT)) & OCOTP_SEC_SEC49_MASK)

#define OCOTP_SEC_SEC50_MASK                     (0x20000U)
#define OCOTP_SEC_SEC50_SHIFT                    (17U)
#define OCOTP_SEC_SEC50_WIDTH                    (1U)
#define OCOTP_SEC_SEC50(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC50_SHIFT)) & OCOTP_SEC_SEC50_MASK)

#define OCOTP_SEC_SEC51_MASK                     (0x40000U)
#define OCOTP_SEC_SEC51_SHIFT                    (18U)
#define OCOTP_SEC_SEC51_WIDTH                    (1U)
#define OCOTP_SEC_SEC51(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC51_SHIFT)) & OCOTP_SEC_SEC51_MASK)

#define OCOTP_SEC_SEC52_MASK                     (0x80000U)
#define OCOTP_SEC_SEC52_SHIFT                    (19U)
#define OCOTP_SEC_SEC52_WIDTH                    (1U)
#define OCOTP_SEC_SEC52(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC52_SHIFT)) & OCOTP_SEC_SEC52_MASK)

#define OCOTP_SEC_SEC53_MASK                     (0x100000U)
#define OCOTP_SEC_SEC53_SHIFT                    (20U)
#define OCOTP_SEC_SEC53_WIDTH                    (1U)
#define OCOTP_SEC_SEC53(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC53_SHIFT)) & OCOTP_SEC_SEC53_MASK)

#define OCOTP_SEC_SEC54_MASK                     (0x200000U)
#define OCOTP_SEC_SEC54_SHIFT                    (21U)
#define OCOTP_SEC_SEC54_WIDTH                    (1U)
#define OCOTP_SEC_SEC54(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC54_SHIFT)) & OCOTP_SEC_SEC54_MASK)

#define OCOTP_SEC_SEC55_MASK                     (0x400000U)
#define OCOTP_SEC_SEC55_SHIFT                    (22U)
#define OCOTP_SEC_SEC55_WIDTH                    (1U)
#define OCOTP_SEC_SEC55(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC55_SHIFT)) & OCOTP_SEC_SEC55_MASK)

#define OCOTP_SEC_SEC56_MASK                     (0x800000U)
#define OCOTP_SEC_SEC56_SHIFT                    (23U)
#define OCOTP_SEC_SEC56_WIDTH                    (1U)
#define OCOTP_SEC_SEC56(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC56_SHIFT)) & OCOTP_SEC_SEC56_MASK)

#define OCOTP_SEC_SEC57_MASK                     (0x1000000U)
#define OCOTP_SEC_SEC57_SHIFT                    (24U)
#define OCOTP_SEC_SEC57_WIDTH                    (1U)
#define OCOTP_SEC_SEC57(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC57_SHIFT)) & OCOTP_SEC_SEC57_MASK)

#define OCOTP_SEC_SEC58_MASK                     (0x2000000U)
#define OCOTP_SEC_SEC58_SHIFT                    (25U)
#define OCOTP_SEC_SEC58_WIDTH                    (1U)
#define OCOTP_SEC_SEC58(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC58_SHIFT)) & OCOTP_SEC_SEC58_MASK)

#define OCOTP_SEC_SEC59_MASK                     (0x4000000U)
#define OCOTP_SEC_SEC59_SHIFT                    (26U)
#define OCOTP_SEC_SEC59_WIDTH                    (1U)
#define OCOTP_SEC_SEC59(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC59_SHIFT)) & OCOTP_SEC_SEC59_MASK)

#define OCOTP_SEC_SEC60_MASK                     (0x8000000U)
#define OCOTP_SEC_SEC60_SHIFT                    (27U)
#define OCOTP_SEC_SEC60_WIDTH                    (1U)
#define OCOTP_SEC_SEC60(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC60_SHIFT)) & OCOTP_SEC_SEC60_MASK)

#define OCOTP_SEC_SEC61_MASK                     (0x10000000U)
#define OCOTP_SEC_SEC61_SHIFT                    (28U)
#define OCOTP_SEC_SEC61_WIDTH                    (1U)
#define OCOTP_SEC_SEC61(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC61_SHIFT)) & OCOTP_SEC_SEC61_MASK)

#define OCOTP_SEC_SEC62_MASK                     (0x20000000U)
#define OCOTP_SEC_SEC62_SHIFT                    (29U)
#define OCOTP_SEC_SEC62_WIDTH                    (1U)
#define OCOTP_SEC_SEC62(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC62_SHIFT)) & OCOTP_SEC_SEC62_MASK)

#define OCOTP_SEC_SEC63_MASK                     (0x40000000U)
#define OCOTP_SEC_SEC63_SHIFT                    (30U)
#define OCOTP_SEC_SEC63_WIDTH                    (1U)
#define OCOTP_SEC_SEC63(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC63_SHIFT)) & OCOTP_SEC_SEC63_MASK)

#define OCOTP_SEC_SEC64_MASK                     (0x80000000U)
#define OCOTP_SEC_SEC64_SHIFT                    (31U)
#define OCOTP_SEC_SEC64_WIDTH                    (1U)
#define OCOTP_SEC_SEC64(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC64_SHIFT)) & OCOTP_SEC_SEC64_MASK)

#define OCOTP_SEC_SEC65_MASK                     (0x1U)
#define OCOTP_SEC_SEC65_SHIFT                    (0U)
#define OCOTP_SEC_SEC65_WIDTH                    (1U)
#define OCOTP_SEC_SEC65(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC65_SHIFT)) & OCOTP_SEC_SEC65_MASK)

#define OCOTP_SEC_SEC66_MASK                     (0x2U)
#define OCOTP_SEC_SEC66_SHIFT                    (1U)
#define OCOTP_SEC_SEC66_WIDTH                    (1U)
#define OCOTP_SEC_SEC66(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC66_SHIFT)) & OCOTP_SEC_SEC66_MASK)

#define OCOTP_SEC_SEC67_MASK                     (0x4U)
#define OCOTP_SEC_SEC67_SHIFT                    (2U)
#define OCOTP_SEC_SEC67_WIDTH                    (1U)
#define OCOTP_SEC_SEC67(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC67_SHIFT)) & OCOTP_SEC_SEC67_MASK)

#define OCOTP_SEC_SEC68_MASK                     (0x8U)
#define OCOTP_SEC_SEC68_SHIFT                    (3U)
#define OCOTP_SEC_SEC68_WIDTH                    (1U)
#define OCOTP_SEC_SEC68(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC68_SHIFT)) & OCOTP_SEC_SEC68_MASK)

#define OCOTP_SEC_SEC69_MASK                     (0x10U)
#define OCOTP_SEC_SEC69_SHIFT                    (4U)
#define OCOTP_SEC_SEC69_WIDTH                    (1U)
#define OCOTP_SEC_SEC69(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC69_SHIFT)) & OCOTP_SEC_SEC69_MASK)

#define OCOTP_SEC_SEC70_MASK                     (0x20U)
#define OCOTP_SEC_SEC70_SHIFT                    (5U)
#define OCOTP_SEC_SEC70_WIDTH                    (1U)
#define OCOTP_SEC_SEC70(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC70_SHIFT)) & OCOTP_SEC_SEC70_MASK)

#define OCOTP_SEC_SEC71_MASK                     (0x40U)
#define OCOTP_SEC_SEC71_SHIFT                    (6U)
#define OCOTP_SEC_SEC71_WIDTH                    (1U)
#define OCOTP_SEC_SEC71(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC71_SHIFT)) & OCOTP_SEC_SEC71_MASK)

#define OCOTP_SEC_SEC72_MASK                     (0x80U)
#define OCOTP_SEC_SEC72_SHIFT                    (7U)
#define OCOTP_SEC_SEC72_WIDTH                    (1U)
#define OCOTP_SEC_SEC72(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC72_SHIFT)) & OCOTP_SEC_SEC72_MASK)

#define OCOTP_SEC_SEC73_MASK                     (0x100U)
#define OCOTP_SEC_SEC73_SHIFT                    (8U)
#define OCOTP_SEC_SEC73_WIDTH                    (1U)
#define OCOTP_SEC_SEC73(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC73_SHIFT)) & OCOTP_SEC_SEC73_MASK)

#define OCOTP_SEC_SEC74_MASK                     (0x200U)
#define OCOTP_SEC_SEC74_SHIFT                    (9U)
#define OCOTP_SEC_SEC74_WIDTH                    (1U)
#define OCOTP_SEC_SEC74(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC74_SHIFT)) & OCOTP_SEC_SEC74_MASK)

#define OCOTP_SEC_SEC75_MASK                     (0x400U)
#define OCOTP_SEC_SEC75_SHIFT                    (10U)
#define OCOTP_SEC_SEC75_WIDTH                    (1U)
#define OCOTP_SEC_SEC75(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC75_SHIFT)) & OCOTP_SEC_SEC75_MASK)

#define OCOTP_SEC_SEC76_MASK                     (0x800U)
#define OCOTP_SEC_SEC76_SHIFT                    (11U)
#define OCOTP_SEC_SEC76_WIDTH                    (1U)
#define OCOTP_SEC_SEC76(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC76_SHIFT)) & OCOTP_SEC_SEC76_MASK)

#define OCOTP_SEC_SEC77_MASK                     (0x1000U)
#define OCOTP_SEC_SEC77_SHIFT                    (12U)
#define OCOTP_SEC_SEC77_WIDTH                    (1U)
#define OCOTP_SEC_SEC77(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC77_SHIFT)) & OCOTP_SEC_SEC77_MASK)

#define OCOTP_SEC_SEC78_MASK                     (0x2000U)
#define OCOTP_SEC_SEC78_SHIFT                    (13U)
#define OCOTP_SEC_SEC78_WIDTH                    (1U)
#define OCOTP_SEC_SEC78(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC78_SHIFT)) & OCOTP_SEC_SEC78_MASK)

#define OCOTP_SEC_SEC79_MASK                     (0x4000U)
#define OCOTP_SEC_SEC79_SHIFT                    (14U)
#define OCOTP_SEC_SEC79_WIDTH                    (1U)
#define OCOTP_SEC_SEC79(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC79_SHIFT)) & OCOTP_SEC_SEC79_MASK)

#define OCOTP_SEC_SEC80_MASK                     (0x8000U)
#define OCOTP_SEC_SEC80_SHIFT                    (15U)
#define OCOTP_SEC_SEC80_WIDTH                    (1U)
#define OCOTP_SEC_SEC80(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC80_SHIFT)) & OCOTP_SEC_SEC80_MASK)

#define OCOTP_SEC_SEC81_MASK                     (0x10000U)
#define OCOTP_SEC_SEC81_SHIFT                    (16U)
#define OCOTP_SEC_SEC81_WIDTH                    (1U)
#define OCOTP_SEC_SEC81(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC81_SHIFT)) & OCOTP_SEC_SEC81_MASK)

#define OCOTP_SEC_SEC82_MASK                     (0x20000U)
#define OCOTP_SEC_SEC82_SHIFT                    (17U)
#define OCOTP_SEC_SEC82_WIDTH                    (1U)
#define OCOTP_SEC_SEC82(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC82_SHIFT)) & OCOTP_SEC_SEC82_MASK)

#define OCOTP_SEC_SEC83_MASK                     (0x40000U)
#define OCOTP_SEC_SEC83_SHIFT                    (18U)
#define OCOTP_SEC_SEC83_WIDTH                    (1U)
#define OCOTP_SEC_SEC83(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC83_SHIFT)) & OCOTP_SEC_SEC83_MASK)

#define OCOTP_SEC_SEC84_MASK                     (0x80000U)
#define OCOTP_SEC_SEC84_SHIFT                    (19U)
#define OCOTP_SEC_SEC84_WIDTH                    (1U)
#define OCOTP_SEC_SEC84(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC84_SHIFT)) & OCOTP_SEC_SEC84_MASK)

#define OCOTP_SEC_SEC85_MASK                     (0x100000U)
#define OCOTP_SEC_SEC85_SHIFT                    (20U)
#define OCOTP_SEC_SEC85_WIDTH                    (1U)
#define OCOTP_SEC_SEC85(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC85_SHIFT)) & OCOTP_SEC_SEC85_MASK)

#define OCOTP_SEC_SEC86_MASK                     (0x200000U)
#define OCOTP_SEC_SEC86_SHIFT                    (21U)
#define OCOTP_SEC_SEC86_WIDTH                    (1U)
#define OCOTP_SEC_SEC86(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC86_SHIFT)) & OCOTP_SEC_SEC86_MASK)

#define OCOTP_SEC_SEC87_MASK                     (0x400000U)
#define OCOTP_SEC_SEC87_SHIFT                    (22U)
#define OCOTP_SEC_SEC87_WIDTH                    (1U)
#define OCOTP_SEC_SEC87(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC87_SHIFT)) & OCOTP_SEC_SEC87_MASK)

#define OCOTP_SEC_SEC88_MASK                     (0x800000U)
#define OCOTP_SEC_SEC88_SHIFT                    (23U)
#define OCOTP_SEC_SEC88_WIDTH                    (1U)
#define OCOTP_SEC_SEC88(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC88_SHIFT)) & OCOTP_SEC_SEC88_MASK)

#define OCOTP_SEC_SEC89_MASK                     (0x1000000U)
#define OCOTP_SEC_SEC89_SHIFT                    (24U)
#define OCOTP_SEC_SEC89_WIDTH                    (1U)
#define OCOTP_SEC_SEC89(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC89_SHIFT)) & OCOTP_SEC_SEC89_MASK)

#define OCOTP_SEC_SEC90_MASK                     (0x2000000U)
#define OCOTP_SEC_SEC90_SHIFT                    (25U)
#define OCOTP_SEC_SEC90_WIDTH                    (1U)
#define OCOTP_SEC_SEC90(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC90_SHIFT)) & OCOTP_SEC_SEC90_MASK)

#define OCOTP_SEC_SEC91_MASK                     (0x4000000U)
#define OCOTP_SEC_SEC91_SHIFT                    (26U)
#define OCOTP_SEC_SEC91_WIDTH                    (1U)
#define OCOTP_SEC_SEC91(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC91_SHIFT)) & OCOTP_SEC_SEC91_MASK)

#define OCOTP_SEC_SEC92_MASK                     (0x8000000U)
#define OCOTP_SEC_SEC92_SHIFT                    (27U)
#define OCOTP_SEC_SEC92_WIDTH                    (1U)
#define OCOTP_SEC_SEC92(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC92_SHIFT)) & OCOTP_SEC_SEC92_MASK)

#define OCOTP_SEC_SEC93_MASK                     (0x10000000U)
#define OCOTP_SEC_SEC93_SHIFT                    (28U)
#define OCOTP_SEC_SEC93_WIDTH                    (1U)
#define OCOTP_SEC_SEC93(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC93_SHIFT)) & OCOTP_SEC_SEC93_MASK)

#define OCOTP_SEC_SEC94_MASK                     (0x20000000U)
#define OCOTP_SEC_SEC94_SHIFT                    (29U)
#define OCOTP_SEC_SEC94_WIDTH                    (1U)
#define OCOTP_SEC_SEC94(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC94_SHIFT)) & OCOTP_SEC_SEC94_MASK)

#define OCOTP_SEC_SEC95_MASK                     (0x40000000U)
#define OCOTP_SEC_SEC95_SHIFT                    (30U)
#define OCOTP_SEC_SEC95_WIDTH                    (1U)
#define OCOTP_SEC_SEC95(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC95_SHIFT)) & OCOTP_SEC_SEC95_MASK)

#define OCOTP_SEC_SEC96_MASK                     (0x80000000U)
#define OCOTP_SEC_SEC96_SHIFT                    (31U)
#define OCOTP_SEC_SEC96_WIDTH                    (1U)
#define OCOTP_SEC_SEC96(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC96_SHIFT)) & OCOTP_SEC_SEC96_MASK)

#define OCOTP_SEC_SEC97_MASK                     (0x1U)
#define OCOTP_SEC_SEC97_SHIFT                    (0U)
#define OCOTP_SEC_SEC97_WIDTH                    (1U)
#define OCOTP_SEC_SEC97(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_SEC_SEC97_SHIFT)) & OCOTP_SEC_SEC97_MASK)
/*! @} */

/*! @name DED - ECC status for double-bit ECC error */
/*! @{ */

#define OCOTP_DED_DED1_MASK                      (0x1U)
#define OCOTP_DED_DED1_SHIFT                     (0U)
#define OCOTP_DED_DED1_WIDTH                     (1U)
#define OCOTP_DED_DED1(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED1_SHIFT)) & OCOTP_DED_DED1_MASK)

#define OCOTP_DED_DED2_MASK                      (0x2U)
#define OCOTP_DED_DED2_SHIFT                     (1U)
#define OCOTP_DED_DED2_WIDTH                     (1U)
#define OCOTP_DED_DED2(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED2_SHIFT)) & OCOTP_DED_DED2_MASK)

#define OCOTP_DED_DED3_MASK                      (0x4U)
#define OCOTP_DED_DED3_SHIFT                     (2U)
#define OCOTP_DED_DED3_WIDTH                     (1U)
#define OCOTP_DED_DED3(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED3_SHIFT)) & OCOTP_DED_DED3_MASK)

#define OCOTP_DED_DED4_MASK                      (0x8U)
#define OCOTP_DED_DED4_SHIFT                     (3U)
#define OCOTP_DED_DED4_WIDTH                     (1U)
#define OCOTP_DED_DED4(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED4_SHIFT)) & OCOTP_DED_DED4_MASK)

#define OCOTP_DED_DED5_MASK                      (0x10U)
#define OCOTP_DED_DED5_SHIFT                     (4U)
#define OCOTP_DED_DED5_WIDTH                     (1U)
#define OCOTP_DED_DED5(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED5_SHIFT)) & OCOTP_DED_DED5_MASK)

#define OCOTP_DED_DED6_MASK                      (0x20U)
#define OCOTP_DED_DED6_SHIFT                     (5U)
#define OCOTP_DED_DED6_WIDTH                     (1U)
#define OCOTP_DED_DED6(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED6_SHIFT)) & OCOTP_DED_DED6_MASK)

#define OCOTP_DED_DED7_MASK                      (0x40U)
#define OCOTP_DED_DED7_SHIFT                     (6U)
#define OCOTP_DED_DED7_WIDTH                     (1U)
#define OCOTP_DED_DED7(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED7_SHIFT)) & OCOTP_DED_DED7_MASK)

#define OCOTP_DED_DED8_MASK                      (0x80U)
#define OCOTP_DED_DED8_SHIFT                     (7U)
#define OCOTP_DED_DED8_WIDTH                     (1U)
#define OCOTP_DED_DED8(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED8_SHIFT)) & OCOTP_DED_DED8_MASK)

#define OCOTP_DED_DED9_MASK                      (0x100U)
#define OCOTP_DED_DED9_SHIFT                     (8U)
#define OCOTP_DED_DED9_WIDTH                     (1U)
#define OCOTP_DED_DED9(x)                        (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED9_SHIFT)) & OCOTP_DED_DED9_MASK)

#define OCOTP_DED_DED10_MASK                     (0x200U)
#define OCOTP_DED_DED10_SHIFT                    (9U)
#define OCOTP_DED_DED10_WIDTH                    (1U)
#define OCOTP_DED_DED10(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED10_SHIFT)) & OCOTP_DED_DED10_MASK)

#define OCOTP_DED_DED11_MASK                     (0x400U)
#define OCOTP_DED_DED11_SHIFT                    (10U)
#define OCOTP_DED_DED11_WIDTH                    (1U)
#define OCOTP_DED_DED11(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED11_SHIFT)) & OCOTP_DED_DED11_MASK)

#define OCOTP_DED_DED12_MASK                     (0x800U)
#define OCOTP_DED_DED12_SHIFT                    (11U)
#define OCOTP_DED_DED12_WIDTH                    (1U)
#define OCOTP_DED_DED12(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED12_SHIFT)) & OCOTP_DED_DED12_MASK)

#define OCOTP_DED_DED13_MASK                     (0x1000U)
#define OCOTP_DED_DED13_SHIFT                    (12U)
#define OCOTP_DED_DED13_WIDTH                    (1U)
#define OCOTP_DED_DED13(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED13_SHIFT)) & OCOTP_DED_DED13_MASK)

#define OCOTP_DED_DED14_MASK                     (0x2000U)
#define OCOTP_DED_DED14_SHIFT                    (13U)
#define OCOTP_DED_DED14_WIDTH                    (1U)
#define OCOTP_DED_DED14(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED14_SHIFT)) & OCOTP_DED_DED14_MASK)

#define OCOTP_DED_DED15_MASK                     (0x4000U)
#define OCOTP_DED_DED15_SHIFT                    (14U)
#define OCOTP_DED_DED15_WIDTH                    (1U)
#define OCOTP_DED_DED15(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED15_SHIFT)) & OCOTP_DED_DED15_MASK)

#define OCOTP_DED_DED16_MASK                     (0x8000U)
#define OCOTP_DED_DED16_SHIFT                    (15U)
#define OCOTP_DED_DED16_WIDTH                    (1U)
#define OCOTP_DED_DED16(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED16_SHIFT)) & OCOTP_DED_DED16_MASK)

#define OCOTP_DED_DED17_MASK                     (0x10000U)
#define OCOTP_DED_DED17_SHIFT                    (16U)
#define OCOTP_DED_DED17_WIDTH                    (1U)
#define OCOTP_DED_DED17(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED17_SHIFT)) & OCOTP_DED_DED17_MASK)

#define OCOTP_DED_DED18_MASK                     (0x20000U)
#define OCOTP_DED_DED18_SHIFT                    (17U)
#define OCOTP_DED_DED18_WIDTH                    (1U)
#define OCOTP_DED_DED18(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED18_SHIFT)) & OCOTP_DED_DED18_MASK)

#define OCOTP_DED_DED19_MASK                     (0x40000U)
#define OCOTP_DED_DED19_SHIFT                    (18U)
#define OCOTP_DED_DED19_WIDTH                    (1U)
#define OCOTP_DED_DED19(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED19_SHIFT)) & OCOTP_DED_DED19_MASK)

#define OCOTP_DED_DED20_MASK                     (0x80000U)
#define OCOTP_DED_DED20_SHIFT                    (19U)
#define OCOTP_DED_DED20_WIDTH                    (1U)
#define OCOTP_DED_DED20(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED20_SHIFT)) & OCOTP_DED_DED20_MASK)

#define OCOTP_DED_DED21_MASK                     (0x100000U)
#define OCOTP_DED_DED21_SHIFT                    (20U)
#define OCOTP_DED_DED21_WIDTH                    (1U)
#define OCOTP_DED_DED21(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED21_SHIFT)) & OCOTP_DED_DED21_MASK)

#define OCOTP_DED_DED22_MASK                     (0x200000U)
#define OCOTP_DED_DED22_SHIFT                    (21U)
#define OCOTP_DED_DED22_WIDTH                    (1U)
#define OCOTP_DED_DED22(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED22_SHIFT)) & OCOTP_DED_DED22_MASK)

#define OCOTP_DED_DED23_MASK                     (0x400000U)
#define OCOTP_DED_DED23_SHIFT                    (22U)
#define OCOTP_DED_DED23_WIDTH                    (1U)
#define OCOTP_DED_DED23(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED23_SHIFT)) & OCOTP_DED_DED23_MASK)

#define OCOTP_DED_DED24_MASK                     (0x800000U)
#define OCOTP_DED_DED24_SHIFT                    (23U)
#define OCOTP_DED_DED24_WIDTH                    (1U)
#define OCOTP_DED_DED24(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED24_SHIFT)) & OCOTP_DED_DED24_MASK)

#define OCOTP_DED_DED25_MASK                     (0x1000000U)
#define OCOTP_DED_DED25_SHIFT                    (24U)
#define OCOTP_DED_DED25_WIDTH                    (1U)
#define OCOTP_DED_DED25(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED25_SHIFT)) & OCOTP_DED_DED25_MASK)

#define OCOTP_DED_DED26_MASK                     (0x2000000U)
#define OCOTP_DED_DED26_SHIFT                    (25U)
#define OCOTP_DED_DED26_WIDTH                    (1U)
#define OCOTP_DED_DED26(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED26_SHIFT)) & OCOTP_DED_DED26_MASK)

#define OCOTP_DED_DED27_MASK                     (0x4000000U)
#define OCOTP_DED_DED27_SHIFT                    (26U)
#define OCOTP_DED_DED27_WIDTH                    (1U)
#define OCOTP_DED_DED27(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED27_SHIFT)) & OCOTP_DED_DED27_MASK)

#define OCOTP_DED_DED28_MASK                     (0x8000000U)
#define OCOTP_DED_DED28_SHIFT                    (27U)
#define OCOTP_DED_DED28_WIDTH                    (1U)
#define OCOTP_DED_DED28(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED28_SHIFT)) & OCOTP_DED_DED28_MASK)

#define OCOTP_DED_DED29_MASK                     (0x10000000U)
#define OCOTP_DED_DED29_SHIFT                    (28U)
#define OCOTP_DED_DED29_WIDTH                    (1U)
#define OCOTP_DED_DED29(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED29_SHIFT)) & OCOTP_DED_DED29_MASK)

#define OCOTP_DED_DED30_MASK                     (0x20000000U)
#define OCOTP_DED_DED30_SHIFT                    (29U)
#define OCOTP_DED_DED30_WIDTH                    (1U)
#define OCOTP_DED_DED30(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED30_SHIFT)) & OCOTP_DED_DED30_MASK)

#define OCOTP_DED_DED31_MASK                     (0x40000000U)
#define OCOTP_DED_DED31_SHIFT                    (30U)
#define OCOTP_DED_DED31_WIDTH                    (1U)
#define OCOTP_DED_DED31(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED31_SHIFT)) & OCOTP_DED_DED31_MASK)

#define OCOTP_DED_DED32_MASK                     (0x80000000U)
#define OCOTP_DED_DED32_SHIFT                    (31U)
#define OCOTP_DED_DED32_WIDTH                    (1U)
#define OCOTP_DED_DED32(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED32_SHIFT)) & OCOTP_DED_DED32_MASK)

#define OCOTP_DED_DED33_MASK                     (0x1U)
#define OCOTP_DED_DED33_SHIFT                    (0U)
#define OCOTP_DED_DED33_WIDTH                    (1U)
#define OCOTP_DED_DED33(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED33_SHIFT)) & OCOTP_DED_DED33_MASK)

#define OCOTP_DED_DED34_MASK                     (0x2U)
#define OCOTP_DED_DED34_SHIFT                    (1U)
#define OCOTP_DED_DED34_WIDTH                    (1U)
#define OCOTP_DED_DED34(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED34_SHIFT)) & OCOTP_DED_DED34_MASK)

#define OCOTP_DED_DED35_MASK                     (0x4U)
#define OCOTP_DED_DED35_SHIFT                    (2U)
#define OCOTP_DED_DED35_WIDTH                    (1U)
#define OCOTP_DED_DED35(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED35_SHIFT)) & OCOTP_DED_DED35_MASK)

#define OCOTP_DED_DED36_MASK                     (0x8U)
#define OCOTP_DED_DED36_SHIFT                    (3U)
#define OCOTP_DED_DED36_WIDTH                    (1U)
#define OCOTP_DED_DED36(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED36_SHIFT)) & OCOTP_DED_DED36_MASK)

#define OCOTP_DED_DED37_MASK                     (0x10U)
#define OCOTP_DED_DED37_SHIFT                    (4U)
#define OCOTP_DED_DED37_WIDTH                    (1U)
#define OCOTP_DED_DED37(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED37_SHIFT)) & OCOTP_DED_DED37_MASK)

#define OCOTP_DED_DED38_MASK                     (0x20U)
#define OCOTP_DED_DED38_SHIFT                    (5U)
#define OCOTP_DED_DED38_WIDTH                    (1U)
#define OCOTP_DED_DED38(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED38_SHIFT)) & OCOTP_DED_DED38_MASK)

#define OCOTP_DED_DED39_MASK                     (0x40U)
#define OCOTP_DED_DED39_SHIFT                    (6U)
#define OCOTP_DED_DED39_WIDTH                    (1U)
#define OCOTP_DED_DED39(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED39_SHIFT)) & OCOTP_DED_DED39_MASK)

#define OCOTP_DED_DED40_MASK                     (0x80U)
#define OCOTP_DED_DED40_SHIFT                    (7U)
#define OCOTP_DED_DED40_WIDTH                    (1U)
#define OCOTP_DED_DED40(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED40_SHIFT)) & OCOTP_DED_DED40_MASK)

#define OCOTP_DED_DED41_MASK                     (0x100U)
#define OCOTP_DED_DED41_SHIFT                    (8U)
#define OCOTP_DED_DED41_WIDTH                    (1U)
#define OCOTP_DED_DED41(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED41_SHIFT)) & OCOTP_DED_DED41_MASK)

#define OCOTP_DED_DED42_MASK                     (0x200U)
#define OCOTP_DED_DED42_SHIFT                    (9U)
#define OCOTP_DED_DED42_WIDTH                    (1U)
#define OCOTP_DED_DED42(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED42_SHIFT)) & OCOTP_DED_DED42_MASK)

#define OCOTP_DED_DED43_MASK                     (0x400U)
#define OCOTP_DED_DED43_SHIFT                    (10U)
#define OCOTP_DED_DED43_WIDTH                    (1U)
#define OCOTP_DED_DED43(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED43_SHIFT)) & OCOTP_DED_DED43_MASK)

#define OCOTP_DED_DED44_MASK                     (0x800U)
#define OCOTP_DED_DED44_SHIFT                    (11U)
#define OCOTP_DED_DED44_WIDTH                    (1U)
#define OCOTP_DED_DED44(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED44_SHIFT)) & OCOTP_DED_DED44_MASK)

#define OCOTP_DED_DED45_MASK                     (0x1000U)
#define OCOTP_DED_DED45_SHIFT                    (12U)
#define OCOTP_DED_DED45_WIDTH                    (1U)
#define OCOTP_DED_DED45(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED45_SHIFT)) & OCOTP_DED_DED45_MASK)

#define OCOTP_DED_DED46_MASK                     (0x2000U)
#define OCOTP_DED_DED46_SHIFT                    (13U)
#define OCOTP_DED_DED46_WIDTH                    (1U)
#define OCOTP_DED_DED46(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED46_SHIFT)) & OCOTP_DED_DED46_MASK)

#define OCOTP_DED_DED47_MASK                     (0x4000U)
#define OCOTP_DED_DED47_SHIFT                    (14U)
#define OCOTP_DED_DED47_WIDTH                    (1U)
#define OCOTP_DED_DED47(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED47_SHIFT)) & OCOTP_DED_DED47_MASK)

#define OCOTP_DED_DED48_MASK                     (0x8000U)
#define OCOTP_DED_DED48_SHIFT                    (15U)
#define OCOTP_DED_DED48_WIDTH                    (1U)
#define OCOTP_DED_DED48(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED48_SHIFT)) & OCOTP_DED_DED48_MASK)

#define OCOTP_DED_DED49_MASK                     (0x10000U)
#define OCOTP_DED_DED49_SHIFT                    (16U)
#define OCOTP_DED_DED49_WIDTH                    (1U)
#define OCOTP_DED_DED49(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED49_SHIFT)) & OCOTP_DED_DED49_MASK)

#define OCOTP_DED_DED50_MASK                     (0x20000U)
#define OCOTP_DED_DED50_SHIFT                    (17U)
#define OCOTP_DED_DED50_WIDTH                    (1U)
#define OCOTP_DED_DED50(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED50_SHIFT)) & OCOTP_DED_DED50_MASK)

#define OCOTP_DED_DED51_MASK                     (0x40000U)
#define OCOTP_DED_DED51_SHIFT                    (18U)
#define OCOTP_DED_DED51_WIDTH                    (1U)
#define OCOTP_DED_DED51(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED51_SHIFT)) & OCOTP_DED_DED51_MASK)

#define OCOTP_DED_DED52_MASK                     (0x80000U)
#define OCOTP_DED_DED52_SHIFT                    (19U)
#define OCOTP_DED_DED52_WIDTH                    (1U)
#define OCOTP_DED_DED52(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED52_SHIFT)) & OCOTP_DED_DED52_MASK)

#define OCOTP_DED_DED53_MASK                     (0x100000U)
#define OCOTP_DED_DED53_SHIFT                    (20U)
#define OCOTP_DED_DED53_WIDTH                    (1U)
#define OCOTP_DED_DED53(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED53_SHIFT)) & OCOTP_DED_DED53_MASK)

#define OCOTP_DED_DED54_MASK                     (0x200000U)
#define OCOTP_DED_DED54_SHIFT                    (21U)
#define OCOTP_DED_DED54_WIDTH                    (1U)
#define OCOTP_DED_DED54(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED54_SHIFT)) & OCOTP_DED_DED54_MASK)

#define OCOTP_DED_DED55_MASK                     (0x400000U)
#define OCOTP_DED_DED55_SHIFT                    (22U)
#define OCOTP_DED_DED55_WIDTH                    (1U)
#define OCOTP_DED_DED55(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED55_SHIFT)) & OCOTP_DED_DED55_MASK)

#define OCOTP_DED_DED56_MASK                     (0x800000U)
#define OCOTP_DED_DED56_SHIFT                    (23U)
#define OCOTP_DED_DED56_WIDTH                    (1U)
#define OCOTP_DED_DED56(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED56_SHIFT)) & OCOTP_DED_DED56_MASK)

#define OCOTP_DED_DED57_MASK                     (0x1000000U)
#define OCOTP_DED_DED57_SHIFT                    (24U)
#define OCOTP_DED_DED57_WIDTH                    (1U)
#define OCOTP_DED_DED57(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED57_SHIFT)) & OCOTP_DED_DED57_MASK)

#define OCOTP_DED_DED58_MASK                     (0x2000000U)
#define OCOTP_DED_DED58_SHIFT                    (25U)
#define OCOTP_DED_DED58_WIDTH                    (1U)
#define OCOTP_DED_DED58(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED58_SHIFT)) & OCOTP_DED_DED58_MASK)

#define OCOTP_DED_DED59_MASK                     (0x4000000U)
#define OCOTP_DED_DED59_SHIFT                    (26U)
#define OCOTP_DED_DED59_WIDTH                    (1U)
#define OCOTP_DED_DED59(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED59_SHIFT)) & OCOTP_DED_DED59_MASK)

#define OCOTP_DED_DED60_MASK                     (0x8000000U)
#define OCOTP_DED_DED60_SHIFT                    (27U)
#define OCOTP_DED_DED60_WIDTH                    (1U)
#define OCOTP_DED_DED60(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED60_SHIFT)) & OCOTP_DED_DED60_MASK)

#define OCOTP_DED_DED61_MASK                     (0x10000000U)
#define OCOTP_DED_DED61_SHIFT                    (28U)
#define OCOTP_DED_DED61_WIDTH                    (1U)
#define OCOTP_DED_DED61(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED61_SHIFT)) & OCOTP_DED_DED61_MASK)

#define OCOTP_DED_DED62_MASK                     (0x20000000U)
#define OCOTP_DED_DED62_SHIFT                    (29U)
#define OCOTP_DED_DED62_WIDTH                    (1U)
#define OCOTP_DED_DED62(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED62_SHIFT)) & OCOTP_DED_DED62_MASK)

#define OCOTP_DED_DED63_MASK                     (0x40000000U)
#define OCOTP_DED_DED63_SHIFT                    (30U)
#define OCOTP_DED_DED63_WIDTH                    (1U)
#define OCOTP_DED_DED63(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED63_SHIFT)) & OCOTP_DED_DED63_MASK)

#define OCOTP_DED_DED64_MASK                     (0x80000000U)
#define OCOTP_DED_DED64_SHIFT                    (31U)
#define OCOTP_DED_DED64_WIDTH                    (1U)
#define OCOTP_DED_DED64(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED64_SHIFT)) & OCOTP_DED_DED64_MASK)

#define OCOTP_DED_DED65_MASK                     (0x1U)
#define OCOTP_DED_DED65_SHIFT                    (0U)
#define OCOTP_DED_DED65_WIDTH                    (1U)
#define OCOTP_DED_DED65(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED65_SHIFT)) & OCOTP_DED_DED65_MASK)

#define OCOTP_DED_DED66_MASK                     (0x2U)
#define OCOTP_DED_DED66_SHIFT                    (1U)
#define OCOTP_DED_DED66_WIDTH                    (1U)
#define OCOTP_DED_DED66(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED66_SHIFT)) & OCOTP_DED_DED66_MASK)

#define OCOTP_DED_DED67_MASK                     (0x4U)
#define OCOTP_DED_DED67_SHIFT                    (2U)
#define OCOTP_DED_DED67_WIDTH                    (1U)
#define OCOTP_DED_DED67(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED67_SHIFT)) & OCOTP_DED_DED67_MASK)

#define OCOTP_DED_DED68_MASK                     (0x8U)
#define OCOTP_DED_DED68_SHIFT                    (3U)
#define OCOTP_DED_DED68_WIDTH                    (1U)
#define OCOTP_DED_DED68(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED68_SHIFT)) & OCOTP_DED_DED68_MASK)

#define OCOTP_DED_DED69_MASK                     (0x10U)
#define OCOTP_DED_DED69_SHIFT                    (4U)
#define OCOTP_DED_DED69_WIDTH                    (1U)
#define OCOTP_DED_DED69(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED69_SHIFT)) & OCOTP_DED_DED69_MASK)

#define OCOTP_DED_DED70_MASK                     (0x20U)
#define OCOTP_DED_DED70_SHIFT                    (5U)
#define OCOTP_DED_DED70_WIDTH                    (1U)
#define OCOTP_DED_DED70(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED70_SHIFT)) & OCOTP_DED_DED70_MASK)

#define OCOTP_DED_DED71_MASK                     (0x40U)
#define OCOTP_DED_DED71_SHIFT                    (6U)
#define OCOTP_DED_DED71_WIDTH                    (1U)
#define OCOTP_DED_DED71(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED71_SHIFT)) & OCOTP_DED_DED71_MASK)

#define OCOTP_DED_DED72_MASK                     (0x80U)
#define OCOTP_DED_DED72_SHIFT                    (7U)
#define OCOTP_DED_DED72_WIDTH                    (1U)
#define OCOTP_DED_DED72(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED72_SHIFT)) & OCOTP_DED_DED72_MASK)

#define OCOTP_DED_DED73_MASK                     (0x100U)
#define OCOTP_DED_DED73_SHIFT                    (8U)
#define OCOTP_DED_DED73_WIDTH                    (1U)
#define OCOTP_DED_DED73(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED73_SHIFT)) & OCOTP_DED_DED73_MASK)

#define OCOTP_DED_DED74_MASK                     (0x200U)
#define OCOTP_DED_DED74_SHIFT                    (9U)
#define OCOTP_DED_DED74_WIDTH                    (1U)
#define OCOTP_DED_DED74(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED74_SHIFT)) & OCOTP_DED_DED74_MASK)

#define OCOTP_DED_DED75_MASK                     (0x400U)
#define OCOTP_DED_DED75_SHIFT                    (10U)
#define OCOTP_DED_DED75_WIDTH                    (1U)
#define OCOTP_DED_DED75(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED75_SHIFT)) & OCOTP_DED_DED75_MASK)

#define OCOTP_DED_DED76_MASK                     (0x800U)
#define OCOTP_DED_DED76_SHIFT                    (11U)
#define OCOTP_DED_DED76_WIDTH                    (1U)
#define OCOTP_DED_DED76(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED76_SHIFT)) & OCOTP_DED_DED76_MASK)

#define OCOTP_DED_DED77_MASK                     (0x1000U)
#define OCOTP_DED_DED77_SHIFT                    (12U)
#define OCOTP_DED_DED77_WIDTH                    (1U)
#define OCOTP_DED_DED77(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED77_SHIFT)) & OCOTP_DED_DED77_MASK)

#define OCOTP_DED_DED78_MASK                     (0x2000U)
#define OCOTP_DED_DED78_SHIFT                    (13U)
#define OCOTP_DED_DED78_WIDTH                    (1U)
#define OCOTP_DED_DED78(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED78_SHIFT)) & OCOTP_DED_DED78_MASK)

#define OCOTP_DED_DED79_MASK                     (0x4000U)
#define OCOTP_DED_DED79_SHIFT                    (14U)
#define OCOTP_DED_DED79_WIDTH                    (1U)
#define OCOTP_DED_DED79(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED79_SHIFT)) & OCOTP_DED_DED79_MASK)

#define OCOTP_DED_DED80_MASK                     (0x8000U)
#define OCOTP_DED_DED80_SHIFT                    (15U)
#define OCOTP_DED_DED80_WIDTH                    (1U)
#define OCOTP_DED_DED80(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED80_SHIFT)) & OCOTP_DED_DED80_MASK)

#define OCOTP_DED_DED81_MASK                     (0x10000U)
#define OCOTP_DED_DED81_SHIFT                    (16U)
#define OCOTP_DED_DED81_WIDTH                    (1U)
#define OCOTP_DED_DED81(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED81_SHIFT)) & OCOTP_DED_DED81_MASK)

#define OCOTP_DED_DED82_MASK                     (0x20000U)
#define OCOTP_DED_DED82_SHIFT                    (17U)
#define OCOTP_DED_DED82_WIDTH                    (1U)
#define OCOTP_DED_DED82(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED82_SHIFT)) & OCOTP_DED_DED82_MASK)

#define OCOTP_DED_DED83_MASK                     (0x40000U)
#define OCOTP_DED_DED83_SHIFT                    (18U)
#define OCOTP_DED_DED83_WIDTH                    (1U)
#define OCOTP_DED_DED83(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED83_SHIFT)) & OCOTP_DED_DED83_MASK)

#define OCOTP_DED_DED84_MASK                     (0x80000U)
#define OCOTP_DED_DED84_SHIFT                    (19U)
#define OCOTP_DED_DED84_WIDTH                    (1U)
#define OCOTP_DED_DED84(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED84_SHIFT)) & OCOTP_DED_DED84_MASK)

#define OCOTP_DED_DED85_MASK                     (0x100000U)
#define OCOTP_DED_DED85_SHIFT                    (20U)
#define OCOTP_DED_DED85_WIDTH                    (1U)
#define OCOTP_DED_DED85(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED85_SHIFT)) & OCOTP_DED_DED85_MASK)

#define OCOTP_DED_DED86_MASK                     (0x200000U)
#define OCOTP_DED_DED86_SHIFT                    (21U)
#define OCOTP_DED_DED86_WIDTH                    (1U)
#define OCOTP_DED_DED86(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED86_SHIFT)) & OCOTP_DED_DED86_MASK)

#define OCOTP_DED_DED87_MASK                     (0x400000U)
#define OCOTP_DED_DED87_SHIFT                    (22U)
#define OCOTP_DED_DED87_WIDTH                    (1U)
#define OCOTP_DED_DED87(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED87_SHIFT)) & OCOTP_DED_DED87_MASK)

#define OCOTP_DED_DED88_MASK                     (0x800000U)
#define OCOTP_DED_DED88_SHIFT                    (23U)
#define OCOTP_DED_DED88_WIDTH                    (1U)
#define OCOTP_DED_DED88(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED88_SHIFT)) & OCOTP_DED_DED88_MASK)

#define OCOTP_DED_DED89_MASK                     (0x1000000U)
#define OCOTP_DED_DED89_SHIFT                    (24U)
#define OCOTP_DED_DED89_WIDTH                    (1U)
#define OCOTP_DED_DED89(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED89_SHIFT)) & OCOTP_DED_DED89_MASK)

#define OCOTP_DED_DED90_MASK                     (0x2000000U)
#define OCOTP_DED_DED90_SHIFT                    (25U)
#define OCOTP_DED_DED90_WIDTH                    (1U)
#define OCOTP_DED_DED90(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED90_SHIFT)) & OCOTP_DED_DED90_MASK)

#define OCOTP_DED_DED91_MASK                     (0x4000000U)
#define OCOTP_DED_DED91_SHIFT                    (26U)
#define OCOTP_DED_DED91_WIDTH                    (1U)
#define OCOTP_DED_DED91(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED91_SHIFT)) & OCOTP_DED_DED91_MASK)

#define OCOTP_DED_DED92_MASK                     (0x8000000U)
#define OCOTP_DED_DED92_SHIFT                    (27U)
#define OCOTP_DED_DED92_WIDTH                    (1U)
#define OCOTP_DED_DED92(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED92_SHIFT)) & OCOTP_DED_DED92_MASK)

#define OCOTP_DED_DED93_MASK                     (0x10000000U)
#define OCOTP_DED_DED93_SHIFT                    (28U)
#define OCOTP_DED_DED93_WIDTH                    (1U)
#define OCOTP_DED_DED93(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED93_SHIFT)) & OCOTP_DED_DED93_MASK)

#define OCOTP_DED_DED94_MASK                     (0x20000000U)
#define OCOTP_DED_DED94_SHIFT                    (29U)
#define OCOTP_DED_DED94_WIDTH                    (1U)
#define OCOTP_DED_DED94(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED94_SHIFT)) & OCOTP_DED_DED94_MASK)

#define OCOTP_DED_DED95_MASK                     (0x40000000U)
#define OCOTP_DED_DED95_SHIFT                    (30U)
#define OCOTP_DED_DED95_WIDTH                    (1U)
#define OCOTP_DED_DED95(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED95_SHIFT)) & OCOTP_DED_DED95_MASK)

#define OCOTP_DED_DED96_MASK                     (0x80000000U)
#define OCOTP_DED_DED96_SHIFT                    (31U)
#define OCOTP_DED_DED96_WIDTH                    (1U)
#define OCOTP_DED_DED96(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED96_SHIFT)) & OCOTP_DED_DED96_MASK)

#define OCOTP_DED_DED97_MASK                     (0x1U)
#define OCOTP_DED_DED97_SHIFT                    (0U)
#define OCOTP_DED_DED97_WIDTH                    (1U)
#define OCOTP_DED_DED97(x)                       (((uint32_t)(((uint32_t)(x)) << OCOTP_DED_DED97_SHIFT)) & OCOTP_DED_DED97_MASK)
/*! @} */

/*! @name ERR_INJCTR - ECC error injector */
/*! @{ */

#define OCOTP_ERR_INJCTR_ADDR_MASK               (0xFFFU)
#define OCOTP_ERR_INJCTR_ADDR_SHIFT              (0U)
#define OCOTP_ERR_INJCTR_ADDR_WIDTH              (12U)
#define OCOTP_ERR_INJCTR_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << OCOTP_ERR_INJCTR_ADDR_SHIFT)) & OCOTP_ERR_INJCTR_ADDR_MASK)
/*! @} */

/*! @name SHADOWS - Shadow */
/*! @{ */

#define OCOTP_SHADOWS_EFUSES_MASK                (0xFFFFFFFFU)
#define OCOTP_SHADOWS_EFUSES_SHIFT               (0U)
#define OCOTP_SHADOWS_EFUSES_WIDTH               (32U)
#define OCOTP_SHADOWS_EFUSES(x)                  (((uint32_t)(((uint32_t)(x)) << OCOTP_SHADOWS_EFUSES_SHIFT)) & OCOTP_SHADOWS_EFUSES_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group OCOTP_Register_Masks */

/*!
 * @}
 */ /* end of group OCOTP_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_OCOTP_H_) */
