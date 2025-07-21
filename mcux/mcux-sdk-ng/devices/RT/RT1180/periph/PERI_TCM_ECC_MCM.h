/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TCM_ECC_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TCM_ECC_MCM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TCM_ECC_MCM
 *
 * CMSIS Peripheral Access Layer for TCM_ECC_MCM
 */

#if !defined(PERI_TCM_ECC_MCM_H_)
#define PERI_TCM_ECC_MCM_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- TCM_ECC_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TCM_ECC_MCM_Peripheral_Access_Layer TCM_ECC_MCM Peripheral Access Layer
 * @{
 */

/** TCM_ECC_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t TCMECCR;                           /**< TCM ECC Control, offset: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status, offset: 0x20 */
  __IO uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable, offset: 0x24 */
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Enable, offset: 0x28 */
       uint8_t RESERVED_2[48];
  __I  uint32_t CODE_TCM_ECC_SINGLE_ERROR_INFO;    /**< Code TCM Single-Bit ECC Error Information, offset: 0x5C */
  __I  uint32_t CODE_TCM_ECC_SINGLE_ERROR_ADDR;    /**< Code TCM Single-Bit ECC Error Address, offset: 0x60 */
       uint8_t RESERVED_3[4];
  __I  uint32_t CODE_TCM_ECC_MULTI_ERROR_INFO;     /**< Code TCM Multibit ECC Error Information, offset: 0x68 */
  __I  uint32_t CODE_TCM_ECC_MULTI_ERROR_ADDR;     /**< Code TCM Multibit ECC Error Address, offset: 0x6C */
       uint8_t RESERVED_4[4];
  __I  uint32_t SYS_TCM_ECC_SINGLE_ERROR_INFO;     /**< System TCM Single-Bit ECC Error Information, offset: 0x74 */
  __I  uint32_t SYS_TCM_ECC_SINGLE_ERROR_ADDR;     /**< System TCM Single-Bit ECC Error Address, offset: 0x78 */
       uint8_t RESERVED_5[4];
  __I  uint32_t SYS_TCM_ECC_MULTI_ERROR_INFO;      /**< System TCM Multibit ECC Error Information, offset: 0x80 */
  __I  uint32_t SYS_TCM_ECC_MULTI_ERROR_ADDR;      /**< System TCM Multibit ECC Error Address, offset: 0x84 */
       uint8_t RESERVED_6[12];
  __IO uint32_t CODE_TCM_ECC_ERROR_INJEC;          /**< Code TCM ECC Error Injection, offset: 0x94 */
  __IO uint32_t SYS_TCM_ECC_ERROR_INJEC;           /**< System TCM ECC Error Injection, offset: 0x98 */
} TCM_ECC_MCM_Type;

/* ----------------------------------------------------------------------------
   -- TCM_ECC_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TCM_ECC_MCM_Register_Masks TCM_ECC_MCM Register Masks
 * @{
 */

/*! @name TCMECCR - TCM ECC Control */
/*! @{ */

#define TCM_ECC_MCM_TCMECCR_WECC_DIS_MASK        (0x1U)
#define TCM_ECC_MCM_TCMECCR_WECC_DIS_SHIFT       (0U)
/*! WECC_DIS - TCM ECC Write Generation Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define TCM_ECC_MCM_TCMECCR_WECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_TCMECCR_WECC_DIS_SHIFT)) & TCM_ECC_MCM_TCMECCR_WECC_DIS_MASK)

#define TCM_ECC_MCM_TCMECCR_RECC_DIS_MASK        (0x2U)
#define TCM_ECC_MCM_TCMECCR_RECC_DIS_SHIFT       (1U)
/*! RECC_DIS - TCM ECC Read Check Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define TCM_ECC_MCM_TCMECCR_RECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_TCMECCR_RECC_DIS_SHIFT)) & TCM_ECC_MCM_TCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status */
/*! @{ */

#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK (0x400U)
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT (10U)
/*! CODE_TCM_ECC_ERRM_INT - Code TCM Access Multibit ECC Error Interrupt Status
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRM_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK (0x800U)
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT (11U)
/*! CODE_TCM_ECC_ERRS_INT - Code TCM Access Single-Bit ECC Error Interrupt Status
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_CODE_TCM_ECC_ERRS_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK (0x1000U)
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT (12U)
/*! SYS_TCM_ECC_ERRM_INT - System TCM Access Multibit ECC Error Interrupt Status
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRM_INT_MASK)

#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK (0x2000U)
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT (13U)
/*! SYS_TCM_ECC_ERRS_INT - System TCM Access Single-Bit ECC Error Interrupt Status
 *  0b0..No effect
 *  0b0..No error
 *  0b1..Clear the flag
 *  0b1..Error
 */
#define TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_SHIFT)) & TCM_ECC_MCM_INT_STATUS_SYS_TCM_ECC_ERRS_INT_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable */
/*! @{ */

#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK (0x400U)
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_EN - Code TCM Access Multibit ECC Error Interrupt Status Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRM_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK (0x800U)
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_EN - Code TCM Access Single-Bit ECC Error Interrupt Status Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_CODE_TCM_ERRS_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK (0x1000U)
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_EN - System TCM Access Multibit ECC Error Interrupt Status Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRM_INT_EN_MASK)

#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK (0x2000U)
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_EN - System TCM Access Single-Bit ECC Error Interrupt Status Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_SHIFT)) & TCM_ECC_MCM_INT_STAT_EN_SYS_TCM_ERRS_INT_EN_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable */
/*! @{ */

#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK (0x400U)
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT (10U)
/*! CODE_TCM_ERRM_INT_SIG_EN - Code TCM Access Multibit ECC Error Interrupt Signal Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRM_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK (0x800U)
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT (11U)
/*! CODE_TCM_ERRS_INT_SIG_EN - Code TCM Access Single-Bit ECC Error Interrupt Signal Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_CODE_TCM_ERRS_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK (0x1000U)
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT (12U)
/*! SYS_TCM_ERRM_INT_SIG_EN - System TCM Access Multibit ECC Error Interrupt Signal Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRM_INT_SIG_EN_MASK)

#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK (0x2000U)
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT (13U)
/*! SYS_TCM_ERRS_INT_SIG_EN - System TCM Access Single-Bit ECC Error Interrupt Signal Enable
 *  0b0..Mask
 *  0b1..Enable
 */
#define TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_SHIFT)) & TCM_ECC_MCM_INT_SIG_EN_SYS_TCM_ERRS_INT_SIG_EN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_INFO - Code TCM Single-Bit ECC Error Information */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCS_EFSIZ - Code TCM Single-Bit ECC Error for Corresponding TCM Access Size */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSIZ_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCS_EFMST - Code TCM Single-Bit ECC Error for Corresponding TCM Master */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFMST_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCS_EFPRT - Code TCM Single-Bit ECC Error for Corresponding TCM Access Protection */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFPRT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCS_EFSYN - Code TCM Single-Bit ECC Error Corresponding Syndrome */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_INFO_CODE_TCM_ECCS_EFSYN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_SINGLE_ERROR_ADDR - Code TCM Single-Bit ECC Error Address */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCS_ERRED_ADDR - Code TCM Single-Bit ECC Error Address */
#define TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_SINGLE_ERROR_ADDR_CODE_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_INFO - Code TCM Multibit ECC Error Information */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! CODE_TCM_ECCM_EFSIZ - Code TCM Multibit ECC Error for Corresponding TCM Access Size */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSIZ_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT (4U)
/*! CODE_TCM_ECCM_EFMST - Code TCM Multibit ECC Error for Corresponding TCM Master */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFMST_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT (8U)
/*! CODE_TCM_ECCM_EFPRT - CODE_TCM Multibit ECC Error for Corresponding Access Protection Attribute */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFPRT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT (12U)
/*! CODE_TCM_ECCM_EFSYN - Code TCM Multibit ECC Error for Corresponding Syndrome */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_INFO_CODE_TCM_ECCM_EFSYN_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_MULTI_ERROR_ADDR - Code TCM Multibit ECC Error Address */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! CODE_TCM_ECCM_ERRED_ADDR - Code TCM Multibit ECC Error Address */
#define TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_MULTI_ERROR_ADDR_CODE_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_INFO - System TCM Single-Bit ECC Error Information */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCS_EFSIZ - System TCM Single-Bit ECC Error for Corresponding TCM Access Size */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSIZ_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCS_EFMST - System TCM Single-Bit ECC Error for Corresponding TCM Master */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFMST_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCS_EFPRT - System TCM Single-Bit ECC Error for Corresponding Access Protection Attribute */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFPRT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCS_EFSYN - System TCM Single-Bit ECC Error for Corresponding Syndrome */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_INFO_SYS_TCM_ECCS_EFSYN_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_SINGLE_ERROR_ADDR - System TCM Single-Bit ECC Error Address */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCS_ERRED_ADDR - System TCM Single-Bit ECC Error Address */
#define TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_SINGLE_ERROR_ADDR_SYS_TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_INFO - System TCM Multibit ECC Error Information */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK (0xEU)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT (1U)
/*! SYS_TCM_ECCM_EFSIZ - System TCM Multibit ECC Error for Corresponding TCM Access Size */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSIZ_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK (0xF0U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT (4U)
/*! SYS_TCM_ECCM_EFMST - System TCM Multibit ECC Error for Corresponding TCM Master */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFMST_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK (0xF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT (8U)
/*! SYS_TCM_ECCM_EFPRT - System TCM Multibit ECC Error for Corresponding Access Protection Attribute */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFPRT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK (0x7F000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT (12U)
/*! SYS_TCM_ECCM_EFSYN - System TCM Multibit ECC Error for Corresponding Syndrome */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_INFO_SYS_TCM_ECCM_EFSYN_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_MULTI_ERROR_ADDR - System TCM Multibit ECC Error Address */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! SYS_TCM_ECCM_ERRED_ADDR - System TCM Multibit ECC Error Address */
#define TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_MULTI_ERROR_ADDR_SYS_TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name CODE_TCM_ECC_ERROR_INJEC - Code TCM ECC Error Injection */
/*! @{ */

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK (0xFFU)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT (0U)
/*! CODE_TCM_ERR1BIT - Position of First Bit to Inject ECC Error */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR1BIT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK (0xFF00U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT (8U)
/*! CODE_TCM_ERR2BIT - Position of Second Bit to Inject ECC Error */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_ERR2BIT_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK (0x10000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT (16U)
/*! CODE_TCM_FR11BI - Force One 1-Bit Data Inversion on Code TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR11BI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK (0x20000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT (17U)
/*! CODE_TCM_FR1NCI - Force One Noncorrectable Data Inversion on Code TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FR1NCI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK (0x40000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT (18U)
/*! CODE_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions on Code TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRC1BI_MASK)

#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK (0x80000U)
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT (19U)
/*! CODE_TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions on Code TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_SHIFT)) & TCM_ECC_MCM_CODE_TCM_ECC_ERROR_INJEC_CODE_TCM_FRCNCI_MASK)
/*! @} */

/*! @name SYS_TCM_ECC_ERROR_INJEC - System TCM ECC Error Injection */
/*! @{ */

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK (0xFFU)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT (0U)
/*! SYS_TCM_ERR1BIT - Position of First Bit to Inject ECC Error */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR1BIT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK (0xFF00U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT (8U)
/*! SYS_TCM_ERR2BIT - Position of Second Bit to Inject ECC Error */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_ERR2BIT_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK (0x10000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT (16U)
/*! SYS_TCM_FR11BI - Force One 1-Bit Data Inversion on System TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR11BI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK (0x20000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT (17U)
/*! SYS_TCM_FR1NCI - Force One Noncorrectable Data Inversion on System TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FR1NCI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK (0x40000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT (18U)
/*! SYS_TCM_FRC1BI - Force Continuous 1-Bit Data Inversions on System TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRC1BI_MASK)

#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK (0x80000U)
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT (19U)
/*! SYS_TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions on System TCM Write Access
 *  0b0..Disable injection
 *  0b1..Enable injection
 */
#define TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_SHIFT)) & TCM_ECC_MCM_SYS_TCM_ECC_ERROR_INJEC_SYS_TCM_FRCNCI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TCM_ECC_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group TCM_ECC_MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_TCM_ECC_MCM_H_ */

