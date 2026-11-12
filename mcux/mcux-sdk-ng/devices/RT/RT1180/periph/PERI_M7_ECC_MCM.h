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
**                          MIMXRT1183CHM8C_cm33
**                          MIMXRT1183CHM8C_cm7
**                          MIMXRT1184CHM8C_cm33
**                          MIMXRT1184CHM8C_cm7
**                          MIMXRT1185CVJ8C_cm33
**                          MIMXRT1185CVJ8C_cm7
**                          MIMXRT1185XVJ8C_cm33
**                          MIMXRT1185XVJ8C_cm7
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
**                          MIMXRT118CCVJ8C_cm33
**                          MIMXRT118CCVJ8C_cm7
**                          MIMXRT118CXVJ8C_cm33
**                          MIMXRT118CXVJ8C_cm7
**                          MIMXRT118DCHM8C_cm33
**                          MIMXRT118DCHM8C_cm7
**                          MIMXRT118DXHM8C_cm33
**                          MIMXRT118DXHM8C_cm7
**                          MIMXRT118ECHM8C_cm33
**                          MIMXRT118ECHM8C_cm7
**                          MIMXRT118EXHM8C_cm33
**                          MIMXRT118EXHM8C_cm7
**
**     Version:             rev. 4.0, 2026-08-14
**     Build:               b260822
**
**     Abstract:
**         CMSIS Peripheral Access Layer for M7_ECC_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
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
**     - rev. 4.0 (2026-08-14)
**         Based on RM Rev 10.
**
** ###################################################################
*/

/*!
 * @file PERI_M7_ECC_MCM.h
 * @version 4.0
 * @date 2026-08-14
 * @brief CMSIS Peripheral Access Layer for M7_ECC_MCM
 *
 * CMSIS Peripheral Access Layer for M7_ECC_MCM
 */

#if !defined(PERI_M7_ECC_MCM_H_)
#define PERI_M7_ECC_MCM_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1183CHM8C_cm33))
#include "MIMXRT1183_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1183CHM8C_cm7))
#include "MIMXRT1183_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1184CHM8C_cm33))
#include "MIMXRT1184_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1184CHM8C_cm7))
#include "MIMXRT1184_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1185CVJ8C_cm33) || defined(CPU_MIMXRT1185XVJ8C_cm33))
#include "MIMXRT1185_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1185CVJ8C_cm7) || defined(CPU_MIMXRT1185XVJ8C_cm7))
#include "MIMXRT1185_cm7_COMMON.h"
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
#elif (defined(CPU_MIMXRT118CCVJ8C_cm33) || defined(CPU_MIMXRT118CXVJ8C_cm33))
#include "MIMXRT118C_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT118CCVJ8C_cm7) || defined(CPU_MIMXRT118CXVJ8C_cm7))
#include "MIMXRT118C_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT118DCHM8C_cm33) || defined(CPU_MIMXRT118DXHM8C_cm33))
#include "MIMXRT118D_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT118DCHM8C_cm7) || defined(CPU_MIMXRT118DXHM8C_cm7))
#include "MIMXRT118D_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT118ECHM8C_cm33) || defined(CPU_MIMXRT118EXHM8C_cm33))
#include "MIMXRT118E_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT118ECHM8C_cm7) || defined(CPU_MIMXRT118EXHM8C_cm7))
#include "MIMXRT118E_cm7_COMMON.h"
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
   -- M7_ECC_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_ECC_MCM_Peripheral_Access_Layer M7_ECC_MCM Peripheral Access Layer
 * @{
 */

/** M7_ECC_MCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t ITCMECCR;                          /**< ITCM ECC Control Register, offset: 0x0 */
  __IO uint32_t DTCMECCR;                          /**< DTCM ECC Control Register, offset: 0x4 */
       uint8_t RESERVED_0[24];
  __IO uint32_t INT_STATUS;                        /**< Interrupt Status Register, offset: 0x20 */
  __IO uint32_t INT_STAT_EN;                       /**< Interrupt Status Enable Register, offset: 0x24 */
  __IO uint32_t INT_SIG_EN;                        /**< Interrupt Enable Register, offset: 0x28 */
       uint8_t RESERVED_1[16];
  __I  uint32_t ITCM_ECC_SINGLE_ERROR_INFO;        /**< ITCM single-bit ECC Error Information, offset: 0x3C */
  __I  uint32_t ITCM_ECC_SINGLE_ERROR_ADDR;        /**< ITCM single-bit ECC Error Address Register, offset: 0x40 */
  __I  uint32_t ITCM_ECC_SINGLE_ERROR_DATA_LSB;    /**< ITCM single-bit ECC Error Data Register, offset: 0x44 */
  __I  uint32_t ITCM_ECC_SINGLE_ERROR_DATA_MSB;    /**< ITCM single-bit ECC Error Data Register, offset: 0x48 */
  __I  uint32_t ITCM_ECC_MULTI_ERROR_INFO;         /**< ITCM multi-bit ECC Error Information Register, offset: 0x4C */
  __I  uint32_t ITCM_ECC_MULTI_ERROR_ADDR;         /**< ITCM multi-bit ECC Error Address Register, offset: 0x50 */
  __I  uint32_t ITCM_ECC_MULTI_ERROR_DATA_LSB;     /**< ITCM multi-bit ECC Error Data Register, offset: 0x54 */
  __I  uint32_t ITCM_ECC_MULTI_ERROR_DATA_MSB;     /**< ITCM multi-bit ECC Error Data Register, offset: 0x58 */
  __I  uint32_t D0TCM_ECC_SINGLE_ERROR_INFO;       /**< D0TCM single-bit ECC Error Information Register, offset: 0x5C */
  __I  uint32_t D0TCM_ECC_SINGLE_ERROR_ADDR;       /**< D0TCM single-bit ECC Error Address Register, offset: 0x60 */
  __I  uint32_t D0TCM_ECC_SINGLE_ERROR_DATA;       /**< D0TCM single-bit ECC Error Data Register, offset: 0x64 */
  __I  uint32_t D0TCM_ECC_MULTI_ERROR_INFO;        /**< D0TCM multi-bit ECC Error Information Register, offset: 0x68 */
  __I  uint32_t D0TCM_ECC_MULTI_ERROR_ADDR;        /**< D0TCM multi-bit ECC Error Address Register, offset: 0x6C */
  __I  uint32_t D0TCM_ECC_MULTI_ERROR_DATA;        /**< D0TCM multi-bit ECC Error Data Register, offset: 0x70 */
  __I  uint32_t D1TCM_ECC_SINGLE_ERROR_INFO;       /**< D1TCM single-bit ECC Error Information Register, offset: 0x74 */
  __I  uint32_t D1TCM_ECC_SINGLE_ERROR_ADDR;       /**< D1TCM single-bit ECC Error Address Register, offset: 0x78 */
  __I  uint32_t D1TCM_ECC_SINGLE_ERROR_DATA;       /**< D1TCM single-bit ECC Error Data Register, offset: 0x7C */
  __I  uint32_t D1TCM_ECC_MULTI_ERROR_INFO;        /**< D1TCM multi-bit ECC Error Information Register, offset: 0x80 */
  __I  uint32_t D1TCM_ECC_MULTI_ERROR_ADDR;        /**< D1TCM multi-bit ECC Error Address Register, offset: 0x84 */
  __I  uint32_t D1TCM_ECC_MULTI_ERROR_DATA;        /**< D1TCM multi-bit ECC Error Data Register, offset: 0x88 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ITCM_ECC_ERROR_INJEC;              /**< ITCM ECC Error Injection Register, offset: 0x90 */
  __IO uint32_t D0TCM_ECC_ERROR_INJEC;             /**< D0TCM ECC Error Injection Register, offset: 0x94 */
  __IO uint32_t D1TCM_ECC_ERROR_INJEC;             /**< D1TCM ECC Error Injection Register, offset: 0x98 */
} M7_ECC_MCM_Type;

/* ----------------------------------------------------------------------------
   -- M7_ECC_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_ECC_MCM_Register_Masks M7_ECC_MCM Register Masks
 * @{
 */

/*! @name ITCMECCR - ITCM ECC Control Register */
/*! @{ */

#define M7_ECC_MCM_ITCMECCR_WECC_DIS_MASK        (0x1U)
#define M7_ECC_MCM_ITCMECCR_WECC_DIS_SHIFT       (0U)
/*! WECC_DIS - Disable ITCM ECC Write Generation
 *  0b0..Enable ECC generation on ITCM write data
 *  0b1..Disable ECC generation on ITCM write data
 */
#define M7_ECC_MCM_ITCMECCR_WECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCMECCR_WECC_DIS_SHIFT)) & M7_ECC_MCM_ITCMECCR_WECC_DIS_MASK)

#define M7_ECC_MCM_ITCMECCR_RECC_DIS_MASK        (0x2U)
#define M7_ECC_MCM_ITCMECCR_RECC_DIS_SHIFT       (1U)
/*! RECC_DIS - Disable ITCM ECC Read Check
 *  0b0..Enable ECC check on ITCM read data
 *  0b1..Disable ECC check on ITCM read data
 */
#define M7_ECC_MCM_ITCMECCR_RECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCMECCR_RECC_DIS_SHIFT)) & M7_ECC_MCM_ITCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name DTCMECCR - DTCM ECC Control Register */
/*! @{ */

#define M7_ECC_MCM_DTCMECCR_WECC_DIS_MASK        (0x1U)
#define M7_ECC_MCM_DTCMECCR_WECC_DIS_SHIFT       (0U)
/*! WECC_DIS - Disable DTCM ECC Write Generation
 *  0b0..Enable ECC generation on DTCM write data
 *  0b1..Disable ECC generation on DTCM write data
 */
#define M7_ECC_MCM_DTCMECCR_WECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_DTCMECCR_WECC_DIS_SHIFT)) & M7_ECC_MCM_DTCMECCR_WECC_DIS_MASK)

#define M7_ECC_MCM_DTCMECCR_RECC_DIS_MASK        (0x2U)
#define M7_ECC_MCM_DTCMECCR_RECC_DIS_SHIFT       (1U)
/*! RECC_DIS - Disable DTCM ECC Read Check
 *  0b0..Enable ECC check on DTCM read data
 *  0b1..Disable ECC check on DTCM read data
 */
#define M7_ECC_MCM_DTCMECCR_RECC_DIS(x)          (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_DTCMECCR_RECC_DIS_SHIFT)) & M7_ECC_MCM_DTCMECCR_RECC_DIS_MASK)
/*! @} */

/*! @name INT_STATUS - Interrupt Status Register */
/*! @{ */

#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_MASK (0x100U)
#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_SHIFT (8U)
/*! ITCM_ECC_ERRM_INT - ITCM Access multi-bit ECC Error Interrupt Status
 *  0b0..ITCM multi-bit ECC error does not happen
 *  0b1..ITCM multi-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRM_INT_MASK)

#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_MASK (0x200U)
#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_SHIFT (9U)
/*! ITCM_ECC_ERRS_INT - ITCM access single-bit ECC Error Interrupt Status
 *  0b0..ITCM single-bit ECC error does not happen
 *  0b1..ITCM single-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_ITCM_ECC_ERRS_INT_MASK)

#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRM_INT_MASK (0x400U)
#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRM_INT_SHIFT (10U)
/*! D0TCM_ECC_ERRM_INT - D0TCM access multi-bit ECC Error Interrupt Status
 *  0b0..D0TCM multi-bit ECC error does not happen
 *  0b1..D0TCM multi-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRM_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRM_INT_MASK)

#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRS_INT_MASK (0x800U)
#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRS_INT_SHIFT (11U)
/*! D0TCM_ECC_ERRS_INT - D0TCM access single-bit ECC Error Interrupt Status
 *  0b0..D0TCM single-bit ECC error does not happen
 *  0b1..D0TCM single-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRS_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_D0TCM_ECC_ERRS_INT_MASK)

#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRM_INT_MASK (0x1000U)
#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRM_INT_SHIFT (12U)
/*! D1TCM_ECC_ERRM_INT - D1TCM access multi-bit ECC Error Interrupt Status
 *  0b0..D1TCM multi-bit ECC error does not happen
 *  0b1..D1TCM multi-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRM_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRM_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRM_INT_MASK)

#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRS_INT_MASK (0x2000U)
#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRS_INT_SHIFT (13U)
/*! D1TCM_ECC_ERRS_INT - D1TCM access single-bit ECC Error Interrupt Status
 *  0b0..D1TCM single-bit ECC error does not happen
 *  0b1..D1TCM single-bit ECC error happens.
 */
#define M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRS_INT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRS_INT_SHIFT)) & M7_ECC_MCM_INT_STATUS_D1TCM_ECC_ERRS_INT_MASK)
/*! @} */

/*! @name INT_STAT_EN - Interrupt Status Enable Register */
/*! @{ */

#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_MASK (0x100U)
#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_SHIFT (8U)
/*! ITCM_ERRM_INT_EN - ITCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_ITCM_ERRM_INT_EN_MASK)

#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_MASK (0x200U)
#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_SHIFT (9U)
/*! ITCM_ERRS_INT_EN - ITCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_ITCM_ERRS_INT_EN_MASK)

#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRM_INT_EN_MASK (0x400U)
#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRM_INT_EN_SHIFT (10U)
/*! D0TCM_ERRM_INT_EN - D0TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRM_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRM_INT_EN_MASK)

#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRS_INT_EN_MASK (0x800U)
#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRS_INT_EN_SHIFT (11U)
/*! D0TCM_ERRS_INT_EN - D0TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRS_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_D0TCM_ERRS_INT_EN_MASK)

#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRM_INT_EN_MASK (0x1000U)
#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRM_INT_EN_SHIFT (12U)
/*! D1TCM_ERRM_INT_EN - D1TCM Access multi bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRM_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRM_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRM_INT_EN_MASK)

#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRS_INT_EN_MASK (0x2000U)
#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRS_INT_EN_SHIFT (13U)
/*! D1TCM_ERRS_INT_EN - D1TCM Access single bit ECC Error Interrupt Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRS_INT_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRS_INT_EN_SHIFT)) & M7_ECC_MCM_INT_STAT_EN_D1TCM_ERRS_INT_EN_MASK)
/*! @} */

/*! @name INT_SIG_EN - Interrupt Enable Register */
/*! @{ */

#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_MASK (0x100U)
#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_SHIFT (8U)
/*! ITCM_ERRM_INT_SIG_EN - ITCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_ITCM_ERRM_INT_SIG_EN_MASK)

#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_MASK (0x200U)
#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_SHIFT (9U)
/*! ITCM_ERRS_INT_SIG_EN - ITCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_ITCM_ERRS_INT_SIG_EN_MASK)

#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRM_INT_SIG_EN_MASK (0x400U)
#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRM_INT_SIG_EN_SHIFT (10U)
/*! D0TCM_ERRM_INT_SIG_EN - D0TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRM_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRM_INT_SIG_EN_MASK)

#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRS_INT_SIG_EN_MASK (0x800U)
#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRS_INT_SIG_EN_SHIFT (11U)
/*! D0TCM_ERRS_INT_SIG_EN - D0TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRS_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_D0TCM_ERRS_INT_SIG_EN_MASK)

#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRM_INT_SIG_EN_MASK (0x1000U)
#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRM_INT_SIG_EN_SHIFT (12U)
/*! D1TCM_ERRM_INT_SIG_EN - D1TCM Access multi bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRM_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRM_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRM_INT_SIG_EN_MASK)

#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRS_INT_SIG_EN_MASK (0x2000U)
#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRS_INT_SIG_EN_SHIFT (13U)
/*! D1TCM_ERRS_INT_SIG_EN - D1TCM Access single bit ECC Error Interrupt Signal Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRS_INT_SIG_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRS_INT_SIG_EN_SHIFT)) & M7_ECC_MCM_INT_SIG_EN_D1TCM_ERRS_INT_SIG_EN_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_INFO - ITCM single-bit ECC Error Information */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK (0x1U)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT (0U)
/*! ITCM_ECCS_EFW - Read or write of the access
 *  0b0..Read
 *  0b1..Write
 */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK)

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT (1U)
/*! ITCM_ECCS_EFSIZ - Size of the access
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100-0b111..
 */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK)

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT (4U)
/*! ITCM_ECCS_EFMST - Encodes the requestor of the access
 *  0b0000..Instruction fetch.
 *  0b0001..Data access.
 *  0b0010..Vector fetch on automated exception entry.
 *  0b0011..AHB slave access.
 *  0b0100..Debugger access.
 *  0b0101..MBIST access.
 *  0b0110..
 *  0b0111..
 *  0b1000..
 *  0b1001..Software data access from store queue.
 *  0b1010..
 *  0b1011..AHB slave access from store queue.
 *  0b1100..Debugger access from store queue.
 *  0b1101..
 *  0b1110..
 *  0b1111..
 */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK)

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT (8U)
/*! ITCM_ECCS_EFPRT - Privilege level of access
 *  0b0000..User
 *  0b0001..
 *  0b0010..Privileged
 *  0b0011-0b1111..
 */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK)

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF00000U)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_ADDR - ITCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCS_ERRED_ADDR - ITCM single-bit ECC error address */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_LSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_LSB - ITCM single-bit ECC error data [31:0] */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_MSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_MSB - ITCM single-bit ECC error data [63:32] */
#define M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT)) & M7_ECC_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_INFO - ITCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK (0x1U)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT (0U)
/*! ITCM_ECCM_EFW - ITCM multi-bit ECC error corresponding tcm_wr value */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK)

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT (1U)
/*! ITCM_ECCM_EFSIZ - ITCM multi-bit ECC error corresponding tcm access size */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK)

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT (4U)
/*! ITCM_ECCM_EFMST - ITCM multi-bit ECC error corresponding tcm_master */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK)

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT (8U)
/*! ITCM_ECCM_EFPRT - ITCM multi-bit ECC error corresponding tcm_priv */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK)

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF00000U)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_ADDR - ITCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCM_ERRED_ADDR - ITCM multi-bit ECC error address */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_LSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_LSB - ITCM multi-bit ECC error data [31:0] */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_MSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_MSB - ITCM multi-bit ECC error data [63:32] */
#define M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT)) & M7_ECC_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_INFO - D0TCM single-bit ECC Error Information Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_MASK (0x1U)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_SHIFT (0U)
/*! D0TCM_ECCS_EFW - D0TCM single-bit ECC error corresponding tcm_wr value */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_MASK)

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_SHIFT (1U)
/*! D0TCM_ECCS_EFSIZ - D0TCM single-bit ECC error corresponding tcm access size */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_MASK)

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_SHIFT (4U)
/*! D0TCM_ECCS_EFMST - D0TCM single-bit ECC error corresponding tcm_master */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_MASK)

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_SHIFT (8U)
/*! D0TCM_ECCS_EFPRT - D0TCM single-bit ECC error corresponding tcm_priv */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_MASK)

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_ADDR - D0TCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! D0TCM_ECCS_ERRED_ADDR - D0TCM single-bit ECC error address */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_DATA - D0TCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! D0TCM_ECCS_ERRED_DATA - D0TCM single-bit ECC error data */
#define M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_INFO - D0TCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_MASK (0x1U)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_SHIFT (0U)
/*! D0TCM_ECCM_EFW - D0TCM multi-bit ECC error corresponding tcm_wr value */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_MASK)

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_SHIFT (1U)
/*! D0TCM_ECCM_EFSIZ - D0TCM multi-bit ECC error corresponding tcm access size */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_MASK)

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_SHIFT (4U)
/*! D0TCM_ECCM_EFMST - D0TCM multi-bit ECC error corresponding tcm_master */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_MASK)

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_SHIFT (8U)
/*! D0TCM_ECCM_EFPRT - D0TCM multi-bit ECC error corresponding tcm_priv */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_MASK)

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_ADDR - D0TCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! D0TCM_ECCM_ERRED_ADDR - D0TCM multi-bit ECC error address */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_DATA - D0TCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! D0TCM_ECCM_ERRED_DATA - D0TCM multi-bit ECC error data */
#define M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_INFO - D1TCM single-bit ECC Error Information Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_MASK (0x1U)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_SHIFT (0U)
/*! D1TCM_ECCS_EFW - D1TCM single-bit ECC error corresponding tcm_wr value */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_MASK)

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_SHIFT (1U)
/*! D1TCM_ECCS_EFSIZ - D1TCM single-bit ECC error corresponding tcm access size */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_MASK)

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_SHIFT (4U)
/*! D1TCM_ECCS_EFMST - D1TCM single-bit ECC error corresponding tcm_master */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_MASK)

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_SHIFT (8U)
/*! D1TCM_ECCS_EFPRT - D1TCM single-bit ECC error corresponding tcm_priv */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_MASK)

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_ADDR - D1TCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! D1TCM_ECCS_ERRED_ADDR - D1TCM single-bit ECC error address */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_DATA - D1TCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! D1TCM_ECCS_ERRED_DATA - D1TCM single-bit ECC error data */
#define M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_INFO - D1TCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_MASK (0x1U)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_SHIFT (0U)
/*! D1TCM_ECCM_EFW - D1TCM multi-bit ECC error corresponding tcm_wr value */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_MASK)

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_SHIFT (1U)
/*! D1TCM_ECCM_EFSIZ - D1TCM multi-bit ECC error corresponding tcm access size */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_MASK)

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_MASK (0xF0U)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_SHIFT (4U)
/*! D1TCM_ECCM_EFMST - D1TCM multi-bit ECC error corresponding tcm_master */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_MASK)

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_SHIFT (8U)
/*! D1TCM_ECCM_EFPRT - D1TCM multi-bit ECC error corresponding tcm_priv */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_MASK)

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_ADDR - D1TCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! D1TCM_ECCM_ERRED_ADDR - D1TCM multi-bit ECC error address */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_DATA - D1TCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! D1TCM_ECCM_ERRED_DATA - D1TCM multi-bit ECC error data */
#define M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name ITCM_ECC_ERROR_INJEC - ITCM ECC Error Injection Register */
/*! @{ */

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_MASK (0xFFU)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_SHIFT (0U)
/*! ITCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error injection. */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR1BIT_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_MASK (0xFF00U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_SHIFT (8U)
/*! ITCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error. */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_ERR2BIT_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_MASK (0x10000U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_SHIFT (16U)
/*! ITCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on ITCM write access */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR11BI_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_MASK (0x20000U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_SHIFT (17U)
/*! ITCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on ITCM write access */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FR1NCI_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_MASK (0x40000U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_SHIFT (18U)
/*! ITCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on ITCM write access */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRC1BI_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_MASK (0x80000U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_SHIFT (19U)
/*! ITCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on ITCM write access */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_ITCM_FRCNCI_MASK)

#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_Reserved_MASK (0xFFF00000U)
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & M7_ECC_MCM_ITCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */

/*! @name D0TCM_ECC_ERROR_INJEC - D0TCM ECC Error Injection Register */
/*! @{ */

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR1BIT_MASK (0xFFU)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR1BIT_SHIFT (0U)
/*! D0TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error injection. */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR1BIT_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR1BIT_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR2BIT_MASK (0xFF00U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR2BIT_SHIFT (8U)
/*! D0TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR2BIT_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_ERR2BIT_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR11BI_MASK (0x10000U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR11BI_SHIFT (16U)
/*! D0TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on D0TCM write access */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR11BI_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR11BI_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR1NCI_MASK (0x20000U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR1NCI_SHIFT (17U)
/*! D0TCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on D0TCM write access */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR1NCI_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FR1NCI_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRC1BI_MASK (0x40000U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRC1BI_SHIFT (18U)
/*! D0TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on D0TCM write access */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRC1BI_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRC1BI_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRCNCI_MASK (0x80000U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRCNCI_SHIFT (19U)
/*! D0TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on D0TCM write access */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRCNCI_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_D0TCM_FRCNCI_MASK)

#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_Reserved_MASK (0xFFF00000U)
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & M7_ECC_MCM_D0TCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */

/*! @name D1TCM_ECC_ERROR_INJEC - D1TCM ECC Error Injection Register */
/*! @{ */

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR1BIT_MASK (0xFFU)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR1BIT_SHIFT (0U)
/*! D1TCM_ERR1BIT - Bit position of the bit to inject ECC Error. Can be used for single-bit and multi-bit ECC Error injection */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR1BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR1BIT_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR1BIT_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR2BIT_MASK (0xFF00U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR2BIT_SHIFT (8U)
/*! D1TCM_ERR2BIT - Bit position of the second bit to inject multi-bit ECC Error */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR2BIT(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR2BIT_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_ERR2BIT_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR11BI_MASK (0x10000U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR11BI_SHIFT (16U)
/*! D1TCM_FR11BI - Force One 1-Bit Data Inversion(single-bit ECC error) on D1TCM write access */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR11BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR11BI_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR11BI_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR1NCI_MASK (0x20000U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR1NCI_SHIFT (17U)
/*! D1TCM_FR1NCI - Force One Noncorrectable Data Inversion(multi-bit ECC error) on D1TCM write access */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR1NCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR1NCI_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FR1NCI_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRC1BI_MASK (0x40000U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRC1BI_SHIFT (18U)
/*! D1TCM_FRC1BI - Force Continuous 1-Bit Data Inversions (single-bit ECC error) on D1TCM write access */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRC1BI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRC1BI_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRC1BI_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRCNCI_MASK (0x80000U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRCNCI_SHIFT (19U)
/*! D1TCM_FRCNCI - Force Continuous Noncorrectable Data Inversions (multi-bit ECC error) on D1TCM write access */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRCNCI(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRCNCI_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_D1TCM_FRCNCI_MASK)

#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_Reserved_MASK (0xFFF00000U)
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_Reserved_SHIFT)) & M7_ECC_MCM_D1TCM_ECC_ERROR_INJEC_Reserved_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group M7_ECC_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group M7_ECC_MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_M7_ECC_MCM_H_ */

