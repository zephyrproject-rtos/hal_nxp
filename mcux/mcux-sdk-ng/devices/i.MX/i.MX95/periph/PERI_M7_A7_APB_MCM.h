/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for M7_A7_APB_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file M7_A7_APB_MCM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for M7_A7_APB_MCM
 *
 * CMSIS Peripheral Access Layer for M7_A7_APB_MCM
 */

#if !defined(M7_A7_APB_MCM_H_)
#define M7_A7_APB_MCM_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- M7_A7_APB_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_A7_APB_MCM_Peripheral_Access_Layer M7_A7_APB_MCM Peripheral Access Layer
 * @{
 */

/** M7_A7_APB_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[36];
  __IO uint32_t ERR_INFO_EN;                       /**< Error Info Enable, offset: 0x24 */
       uint8_t RESERVED_1[20];
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
       uint8_t RESERVED_2[16];
  __IO uint32_t FCCU_SW_FAULTS;                    /**< FCCU Software Faults, offset: 0x9C */
} M7_A7_APB_MCM_Type;

/* ----------------------------------------------------------------------------
   -- M7_A7_APB_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_A7_APB_MCM_Register_Masks M7_A7_APB_MCM Register Masks
 * @{
 */

/*! @name ERR_INFO_EN - Error Info Enable */
/*! @{ */

#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRM_INFO_EN_MASK (0x100U)
#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRM_INFO_EN_SHIFT (8U)
/*! ITCM_ERRM_INFO_EN - ITCM Access multi bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRM_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRM_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRM_INFO_EN_MASK)

#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRS_INFO_EN_MASK (0x200U)
#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRS_INFO_EN_SHIFT (9U)
/*! ITCM_ERRS_INFO_EN - ITCM Access single bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRS_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRS_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_ITCM_ERRS_INFO_EN_MASK)

#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRM_INFO_EN_MASK (0x400U)
#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRM_INFO_EN_SHIFT (10U)
/*! D0TCM_ERRM_INFO_EN - D0TCM Access multi bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRM_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRM_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRM_INFO_EN_MASK)

#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRS_INFO_EN_MASK (0x800U)
#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRS_INFO_EN_SHIFT (11U)
/*! D0TCM_ERRS_INFO_EN - D0TCM Access single bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRS_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRS_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_D0TCM_ERRS_INFO_EN_MASK)

#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRM_INFO_EN_MASK (0x1000U)
#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRM_INFO_EN_SHIFT (12U)
/*! D1TCM_ERRM_INFO_EN - D1TCM Access multi bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRM_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRM_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRM_INFO_EN_MASK)

#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRS_INFO_EN_MASK (0x2000U)
#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRS_INFO_EN_SHIFT (13U)
/*! D1TCM_ERRS_INFO_EN - D1TCM Access single bit ECC Error Info Status Enable
 *  0b0..Masked
 *  0b1..Enabled
 */
#define M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRS_INFO_EN(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRS_INFO_EN_SHIFT)) & M7_A7_APB_MCM_ERR_INFO_EN_D1TCM_ERRS_INFO_EN_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_INFO - ITCM single-bit ECC Error Information */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT (0U)
/*! ITCM_ECCS_EFW - Read or write of the access
 *  0b0..Read
 *  0b1..Write
 */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFW_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT (1U)
/*! ITCM_ECCS_EFSIZ - Size of the access
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100-0b111..
 */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFSIZ_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT (4U)
/*! ITCM_ECCS_EFMST - Encodes the requestor of the access
 *  0b0000..Instruction fetch.
 *  0b0001..Data access.
 *  0b0010..Vector fetch on automated exception entry.
 *  0b0011..AHB slave access.
 *  0b0100..Debugger access.
 *  0b0101..MBIST access.
 *  0b1001..Software data access from store queue.
 *  0b1011..AHB slave access from store queue.
 *  0b1100..Debugger access from store queue.
 *  0b0110..
 *  0b0111..
 *  0b1000..
 *  0b1010..
 *  0b1101..
 *  0b1110..
 *  0b1111..
 */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFMST_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT (8U)
/*! ITCM_ECCS_EFPRT - Privilege level of access
 *  0b0000..User
 *  0b0010..Privileged
 *  0b0001..
 *  0b0011-0b1111..
 */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_ITCM_ECCS_EFPRT_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF00000U)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_ADDR - ITCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCS_ERRED_ADDR - ITCM single-bit ECC error address */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_ADDR_ITCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_LSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_LSB - ITCM single-bit ECC error data [31:0] */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_LSB_ITCM_ECCS_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_SINGLE_ERROR_DATA_MSB - ITCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCS_ERRED_DATA_MSB - ITCM single-bit ECC error data [63:32] */
#define M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_SINGLE_ERROR_DATA_MSB_ITCM_ECCS_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_INFO - ITCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT (0U)
/*! ITCM_ECCM_EFW - ITCM multi-bit ECC error corresponding tcm_wr value */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFW_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT (1U)
/*! ITCM_ECCM_EFSIZ - ITCM multi-bit ECC error corresponding tcm access size */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFSIZ_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT (4U)
/*! ITCM_ECCM_EFMST - ITCM multi-bit ECC error corresponding tcm_master */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFMST_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT (8U)
/*! ITCM_ECCM_EFPRT - ITCM multi-bit ECC error corresponding tcm_priv */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_ITCM_ECCM_EFPRT_MASK)

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF00000U)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (20U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_ADDR - ITCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! ITCM_ECCM_ERRED_ADDR - ITCM multi-bit ECC error address */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_ADDR_ITCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_LSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_LSB - ITCM multi-bit ECC error data [31:0] */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_LSB_ITCM_ECCM_ERRED_DATA_LSB_MASK)
/*! @} */

/*! @name ITCM_ECC_MULTI_ERROR_DATA_MSB - ITCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT (0U)
/*! ITCM_ECCM_ERRED_DATA_MSB - ITCM multi-bit ECC error data [63:32] */
#define M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_SHIFT)) & M7_A7_APB_MCM_ITCM_ECC_MULTI_ERROR_DATA_MSB_ITCM_ECCM_ERRED_DATA_MSB_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_INFO - D0TCM single-bit ECC Error Information Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_SHIFT (0U)
/*! D0TCM_ECCS_EFW - D0TCM single-bit ECC error corresponding tcm_wr value */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFW_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_SHIFT (1U)
/*! D0TCM_ECCS_EFSIZ - D0TCM single-bit ECC error corresponding tcm access size */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFSIZ_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_SHIFT (4U)
/*! D0TCM_ECCS_EFMST - D0TCM single-bit ECC error corresponding tcm_master */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFMST_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_SHIFT (8U)
/*! D0TCM_ECCS_EFPRT - D0TCM single-bit ECC error corresponding tcm_priv */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_D0TCM_ECCS_EFPRT_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_ADDR - D0TCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! D0TCM_ECCS_ERRED_ADDR - D0TCM single-bit ECC error address */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_ADDR_D0TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name D0TCM_ECC_SINGLE_ERROR_DATA - D0TCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! D0TCM_ECCS_ERRED_DATA - D0TCM single-bit ECC error data */
#define M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_SINGLE_ERROR_DATA_D0TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_INFO - D0TCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_SHIFT (0U)
/*! D0TCM_ECCM_EFW - D0TCM multi-bit ECC error corresponding tcm_wr value */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFW_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_SHIFT (1U)
/*! D0TCM_ECCM_EFSIZ - D0TCM multi-bit ECC error corresponding tcm access size */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFSIZ_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_SHIFT (4U)
/*! D0TCM_ECCM_EFMST - D0TCM multi-bit ECC error corresponding tcm_master */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFMST_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_SHIFT (8U)
/*! D0TCM_ECCM_EFPRT - D0TCM multi-bit ECC error corresponding tcm_priv */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_D0TCM_ECCM_EFPRT_MASK)

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_ADDR - D0TCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! D0TCM_ECCM_ERRED_ADDR - D0TCM multi-bit ECC error address */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_ADDR_D0TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name D0TCM_ECC_MULTI_ERROR_DATA - D0TCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! D0TCM_ECCM_ERRED_DATA - D0TCM multi-bit ECC error data */
#define M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_SHIFT)) & M7_A7_APB_MCM_D0TCM_ECC_MULTI_ERROR_DATA_D0TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_INFO - D1TCM single-bit ECC Error Information Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_SHIFT (0U)
/*! D1TCM_ECCS_EFW - D1TCM single-bit ECC error corresponding tcm_wr value */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFW_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_SHIFT (1U)
/*! D1TCM_ECCS_EFSIZ - D1TCM single-bit ECC error corresponding tcm access size */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFSIZ_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_SHIFT (4U)
/*! D1TCM_ECCS_EFMST - D1TCM single-bit ECC error corresponding tcm_master */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFMST_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_SHIFT (8U)
/*! D1TCM_ECCS_EFPRT - D1TCM single-bit ECC error corresponding tcm_priv */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_D1TCM_ECCS_EFPRT_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_ADDR - D1TCM single-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_SHIFT (0U)
/*! D1TCM_ECCS_ERRED_ADDR - D1TCM single-bit ECC error address */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_ADDR_D1TCM_ECCS_ERRED_ADDR_MASK)
/*! @} */

/*! @name D1TCM_ECC_SINGLE_ERROR_DATA - D1TCM single-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_SHIFT (0U)
/*! D1TCM_ECCS_ERRED_DATA - D1TCM single-bit ECC error data */
#define M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_SINGLE_ERROR_DATA_D1TCM_ECCS_ERRED_DATA_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_INFO - D1TCM multi-bit ECC Error Information Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_MASK (0x1U)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_SHIFT (0U)
/*! D1TCM_ECCM_EFW - D1TCM multi-bit ECC error corresponding tcm_wr value */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFW_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_MASK (0xEU)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_SHIFT (1U)
/*! D1TCM_ECCM_EFSIZ - D1TCM multi-bit ECC error corresponding tcm access size */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFSIZ_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_MASK (0xF0U)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_SHIFT (4U)
/*! D1TCM_ECCM_EFMST - D1TCM multi-bit ECC error corresponding tcm_master */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFMST_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_MASK (0xF00U)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_SHIFT (8U)
/*! D1TCM_ECCM_EFPRT - D1TCM multi-bit ECC error corresponding tcm_priv */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_D1TCM_ECCM_EFPRT_MASK)

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK (0xFFF80000U)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT (19U)
/*! Reserved - Reserved */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_INFO_Reserved_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_ADDR - D1TCM multi-bit ECC Error Address Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_SHIFT (0U)
/*! D1TCM_ECCM_ERRED_ADDR - D1TCM multi-bit ECC error address */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_ADDR_D1TCM_ECCM_ERRED_ADDR_MASK)
/*! @} */

/*! @name D1TCM_ECC_MULTI_ERROR_DATA - D1TCM multi-bit ECC Error Data Register */
/*! @{ */

#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_MASK (0xFFFFFFFFU)
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_SHIFT (0U)
/*! D1TCM_ECCM_ERRED_DATA - D1TCM multi-bit ECC error data */
#define M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_SHIFT)) & M7_A7_APB_MCM_D1TCM_ECC_MULTI_ERROR_DATA_D1TCM_ECCM_ERRED_DATA_MASK)
/*! @} */

/*! @name FCCU_SW_FAULTS - FCCU Software Faults */
/*! @{ */

#define M7_A7_APB_MCM_FCCU_SW_FAULTS_FCCU_SW_FAULTS_MASK (0x3FU)
#define M7_A7_APB_MCM_FCCU_SW_FAULTS_FCCU_SW_FAULTS_SHIFT (0U)
/*! FCCU_SW_FAULTS - FCCU Software Faults */
#define M7_A7_APB_MCM_FCCU_SW_FAULTS_FCCU_SW_FAULTS(x) (((uint32_t)(((uint32_t)(x)) << M7_A7_APB_MCM_FCCU_SW_FAULTS_FCCU_SW_FAULTS_SHIFT)) & M7_A7_APB_MCM_FCCU_SW_FAULTS_FCCU_SW_FAULTS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group M7_A7_APB_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group M7_A7_APB_MCM_Peripheral_Access_Layer */


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


#endif  /* M7_A7_APB_MCM_H_ */

