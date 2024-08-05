/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_DMSS_SAFETY.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_DMSS_SAFETY
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
#if !defined(S32Z2_DMSS_SAFETY_H_)  /* Check if memory map has not been already included */
#define S32Z2_DMSS_SAFETY_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DMSS_SAFETY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMSS_SAFETY_Peripheral_Access_Layer DMSS_SAFETY Peripheral Access Layer
 * @{
 */

/** DMSS_SAFETY - Register Layout Typedef */
typedef struct {
  __IO uint32_t D_UCSERR;                          /**< DMSS UCS ERR Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint32_t D_CSERR;                           /**< DMSS CS ERR Register, offset: 0x8 */
  uint8_t RESERVED_1[4];
  __O  uint32_t D_UCSERR_S;                        /**< DMSS UCS ERR Shadow Register, offset: 0x10 */
  __O  uint32_t D_CSERR_S;                         /**< DMSS CS ERR Shadow Register, offset: 0x14 */
  uint8_t RESERVED_2[4];
  __IO uint32_t D_CSERR_M;                         /**< DMSS CS ERR Mask Register, offset: 0x1C */
  __IO uint32_t D_ECC_TCFG;                        /**< DMSS ECC TCFG Register, offset: 0x20 */
  __IO uint32_t D_ECC_TCFG_2;                      /**< DMSS ECC TCFG 2 Register, offset: 0x24 */
  uint8_t RESERVED_3[8];
  __IO uint32_t D_SFT_SCPD_0;                      /**< DMSS SFT SCPD 0 Register, offset: 0x30 */
  __IO uint32_t D_SFT_SCPD_1;                      /**< DMSS SFT SCPD 1 Register, offset: 0x34 */
  __IO uint32_t D_SFT_SCPD_2;                      /**< DMSS SFT SCPD 2 Register, offset: 0x38 */
  __IO uint32_t D_SFT_SCPD_3;                      /**< DMSS SFT SCPD 3 Register, offset: 0x3C */
  __I  uint32_t D_UCSERR_CNT;                      /**< DMSS UCS ERR Register, offset: 0x40 */
  __I  uint32_t D_CSERR_CNT;                       /**< DMSS CS ERR CNT Register, offset: 0x44 */
} DMSS_SAFETY_Type, *DMSS_SAFETY_MemMapPtr;

/** Number of instances of the DMSS_SAFETY module. */
#define DMSS_SAFETY_INSTANCE_COUNT               (1u)

/* DMSS_SAFETY - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__DMSS_SAFETY base address */
#define IP_CEVA_SPF2__DMSS_SAFETY_BASE           (0x244007B0u)
/** Peripheral CEVA_SPF2__DMSS_SAFETY base pointer */
#define IP_CEVA_SPF2__DMSS_SAFETY                ((DMSS_SAFETY_Type *)IP_CEVA_SPF2__DMSS_SAFETY_BASE)
/** Array initializer of DMSS_SAFETY peripheral base addresses */
#define IP_DMSS_SAFETY_BASE_ADDRS                { IP_CEVA_SPF2__DMSS_SAFETY_BASE }
/** Array initializer of DMSS_SAFETY peripheral base pointers */
#define IP_DMSS_SAFETY_BASE_PTRS                 { IP_CEVA_SPF2__DMSS_SAFETY }

/* ----------------------------------------------------------------------------
   -- DMSS_SAFETY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMSS_SAFETY_Register_Masks DMSS_SAFETY Register Masks
 * @{
 */

/*! @name D_UCSERR - DMSS UCS ERR Register */
/*! @{ */

#define DMSS_SAFETY_D_UCSERR_D_UCSERR_MASK       (0x1U)
#define DMSS_SAFETY_D_UCSERR_D_UCSERR_SHIFT      (0U)
#define DMSS_SAFETY_D_UCSERR_D_UCSERR_WIDTH      (1U)
#define DMSS_SAFETY_D_UCSERR_D_UCSERR(x)         (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_D_UCSERR_SHIFT)) & DMSS_SAFETY_D_UCSERR_D_UCSERR_MASK)

#define DMSS_SAFETY_D_UCSERR_D_ECC_ERR_MASK      (0x2U)
#define DMSS_SAFETY_D_UCSERR_D_ECC_ERR_SHIFT     (1U)
#define DMSS_SAFETY_D_UCSERR_D_ECC_ERR_WIDTH     (1U)
#define DMSS_SAFETY_D_UCSERR_D_ECC_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_D_ECC_ERR_SHIFT)) & DMSS_SAFETY_D_UCSERR_D_ECC_ERR_MASK)

#define DMSS_SAFETY_D_UCSERR_D_MSS_PERR_MASK     (0x200U)
#define DMSS_SAFETY_D_UCSERR_D_MSS_PERR_SHIFT    (9U)
#define DMSS_SAFETY_D_UCSERR_D_MSS_PERR_WIDTH    (1U)
#define DMSS_SAFETY_D_UCSERR_D_MSS_PERR(x)       (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_D_MSS_PERR_SHIFT)) & DMSS_SAFETY_D_UCSERR_D_MSS_PERR_MASK)

#define DMSS_SAFETY_D_UCSERR_D_UCECNTEV_MASK     (0x10000U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTEV_SHIFT    (16U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTEV_WIDTH    (1U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTEV(x)       (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_D_UCECNTEV_SHIFT)) & DMSS_SAFETY_D_UCSERR_D_UCECNTEV_MASK)

#define DMSS_SAFETY_D_UCSERR_D_UCECNTOV_MASK     (0x20000U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTOV_SHIFT    (17U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTOV_WIDTH    (1U)
#define DMSS_SAFETY_D_UCSERR_D_UCECNTOV(x)       (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_D_UCECNTOV_SHIFT)) & DMSS_SAFETY_D_UCSERR_D_UCECNTOV_MASK)

#define DMSS_SAFETY_D_UCSERR_CWDOGIRQ_MASK       (0x40000000U)
#define DMSS_SAFETY_D_UCSERR_CWDOGIRQ_SHIFT      (30U)
#define DMSS_SAFETY_D_UCSERR_CWDOGIRQ_WIDTH      (1U)
#define DMSS_SAFETY_D_UCSERR_CWDOGIRQ(x)         (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_CWDOGIRQ_SHIFT)) & DMSS_SAFETY_D_UCSERR_CWDOGIRQ_MASK)

#define DMSS_SAFETY_D_UCSERR_CENSIRQ_MASK        (0x80000000U)
#define DMSS_SAFETY_D_UCSERR_CENSIRQ_SHIFT       (31U)
#define DMSS_SAFETY_D_UCSERR_CENSIRQ_WIDTH       (1U)
#define DMSS_SAFETY_D_UCSERR_CENSIRQ(x)          (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_CENSIRQ_SHIFT)) & DMSS_SAFETY_D_UCSERR_CENSIRQ_MASK)
/*! @} */

/*! @name D_CSERR - DMSS CS ERR Register */
/*! @{ */

#define DMSS_SAFETY_D_CSERR_D_CSERR_MASK         (0x1U)
#define DMSS_SAFETY_D_CSERR_D_CSERR_SHIFT        (0U)
#define DMSS_SAFETY_D_CSERR_D_CSERR_WIDTH        (1U)
#define DMSS_SAFETY_D_CSERR_D_CSERR(x)           (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_D_CSERR_SHIFT)) & DMSS_SAFETY_D_CSERR_D_CSERR_MASK)

#define DMSS_SAFETY_D_CSERR_D_ECC_COR_MASK       (0x2U)
#define DMSS_SAFETY_D_CSERR_D_ECC_COR_SHIFT      (1U)
#define DMSS_SAFETY_D_CSERR_D_ECC_COR_WIDTH      (1U)
#define DMSS_SAFETY_D_CSERR_D_ECC_COR(x)         (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_D_ECC_COR_SHIFT)) & DMSS_SAFETY_D_CSERR_D_ECC_COR_MASK)

#define DMSS_SAFETY_D_CSERR_D_CECNTEV_MASK       (0x10000U)
#define DMSS_SAFETY_D_CSERR_D_CECNTEV_SHIFT      (16U)
#define DMSS_SAFETY_D_CSERR_D_CECNTEV_WIDTH      (1U)
#define DMSS_SAFETY_D_CSERR_D_CECNTEV(x)         (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_D_CECNTEV_SHIFT)) & DMSS_SAFETY_D_CSERR_D_CECNTEV_MASK)

#define DMSS_SAFETY_D_CSERR_D_CECNTOV_MASK       (0x20000U)
#define DMSS_SAFETY_D_CSERR_D_CECNTOV_SHIFT      (17U)
#define DMSS_SAFETY_D_CSERR_D_CECNTOV_WIDTH      (1U)
#define DMSS_SAFETY_D_CSERR_D_CECNTOV(x)         (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_D_CECNTOV_SHIFT)) & DMSS_SAFETY_D_CSERR_D_CECNTOV_MASK)

#define DMSS_SAFETY_D_CSERR_NNSE_MASK            (0x80000000U)
#define DMSS_SAFETY_D_CSERR_NNSE_SHIFT           (31U)
#define DMSS_SAFETY_D_CSERR_NNSE_WIDTH           (1U)
#define DMSS_SAFETY_D_CSERR_NNSE(x)              (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_NNSE_SHIFT)) & DMSS_SAFETY_D_CSERR_NNSE_MASK)
/*! @} */

/*! @name D_UCSERR_S - DMSS UCS ERR Shadow Register */
/*! @{ */

#define DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S_MASK  (0x2U)
#define DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S_SHIFT (1U)
#define DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S_WIDTH (1U)
#define DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S(x)    (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S_SHIFT)) & DMSS_SAFETY_D_UCSERR_S_D_ECC_ERR_S_MASK)

#define DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S_MASK (0x200U)
#define DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S_SHIFT (9U)
#define DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S_WIDTH (1U)
#define DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S(x)   (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S_SHIFT)) & DMSS_SAFETY_D_UCSERR_S_D_MSS_PERR_S_MASK)
/*! @} */

/*! @name D_CSERR_S - DMSS CS ERR Shadow Register */
/*! @{ */

#define DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S_MASK   (0x2U)
#define DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S_SHIFT  (1U)
#define DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S_WIDTH  (1U)
#define DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S(x)     (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S_SHIFT)) & DMSS_SAFETY_D_CSERR_S_D_ECC_COR_S_MASK)
/*! @} */

/*! @name D_CSERR_M - DMSS CS ERR Mask Register */
/*! @{ */

#define DMSS_SAFETY_D_CSERR_M_D_CSRERR_M_MASK    (0x1U)
#define DMSS_SAFETY_D_CSERR_M_D_CSRERR_M_SHIFT   (0U)
#define DMSS_SAFETY_D_CSERR_M_D_CSRERR_M_WIDTH   (1U)
#define DMSS_SAFETY_D_CSERR_M_D_CSRERR_M(x)      (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_M_D_CSRERR_M_SHIFT)) & DMSS_SAFETY_D_CSERR_M_D_CSRERR_M_MASK)

#define DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M_MASK   (0x2U)
#define DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M_SHIFT  (1U)
#define DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M_WIDTH  (1U)
#define DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M(x)     (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M_SHIFT)) & DMSS_SAFETY_D_CSERR_M_D_ECC_COR_M_MASK)
/*! @} */

/*! @name D_ECC_TCFG - DMSS ECC TCFG Register */
/*! @{ */

#define DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG_MASK    (0xFFFFFFFFU)
#define DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG_SHIFT   (0U)
#define DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG_WIDTH   (32U)
#define DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG(x)      (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG_SHIFT)) & DMSS_SAFETY_D_ECC_TCFG_D_FLIPCFG_MASK)
/*! @} */

/*! @name D_ECC_TCFG_2 - DMSS ECC TCFG 2 Register */
/*! @{ */

#define DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE_MASK (0x7FU)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE_SHIFT (0U)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE_WIDTH (7U)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE(x)   (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE_SHIFT)) & DMSS_SAFETY_D_ECC_TCFG_2_D_FLIPCFGE_MASK)

#define DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG_MASK     (0x80000000U)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG_SHIFT    (31U)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG_WIDTH    (1U)
#define DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG(x)       (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG_SHIFT)) & DMSS_SAFETY_D_ECC_TCFG_2_D_TRIG_MASK)
/*! @} */

/*! @name D_SFT_SCPD_0 - DMSS SFT SCPD 0 Register */
/*! @{ */

#define DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0_MASK  (0xFFFFFFFFU)
#define DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0_SHIFT (0U)
#define DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0_WIDTH (32U)
#define DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0(x)    (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0_SHIFT)) & DMSS_SAFETY_D_SFT_SCPD_0_SFT_SCPD0_MASK)
/*! @} */

/*! @name D_SFT_SCPD_1 - DMSS SFT SCPD 1 Register */
/*! @{ */

#define DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1_MASK  (0xFFFFFFFFU)
#define DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1_SHIFT (0U)
#define DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1_WIDTH (32U)
#define DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1(x)    (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1_SHIFT)) & DMSS_SAFETY_D_SFT_SCPD_1_SFT_SCPD1_MASK)
/*! @} */

/*! @name D_SFT_SCPD_2 - DMSS SFT SCPD 2 Register */
/*! @{ */

#define DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2_MASK  (0xFFFFFFFFU)
#define DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2_SHIFT (0U)
#define DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2_WIDTH (32U)
#define DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2(x)    (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2_SHIFT)) & DMSS_SAFETY_D_SFT_SCPD_2_SFT_SCPD2_MASK)
/*! @} */

/*! @name D_SFT_SCPD_3 - DMSS SFT SCPD 3 Register */
/*! @{ */

#define DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3_MASK  (0xFFFFFFFFU)
#define DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3_SHIFT (0U)
#define DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3_WIDTH (32U)
#define DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3(x)    (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3_SHIFT)) & DMSS_SAFETY_D_SFT_SCPD_3_SFT_SCPD3_MASK)
/*! @} */

/*! @name D_UCSERR_CNT - DMSS UCS ERR Register */
/*! @{ */

#define DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V_MASK (0xFFFFU)
#define DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V_SHIFT (0U)
#define DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V_WIDTH (16U)
#define DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V(x) (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V_SHIFT)) & DMSS_SAFETY_D_UCSERR_CNT_D_UCSERR_CNT_V_MASK)
/*! @} */

/*! @name D_CSERR_CNT - DMSS CS ERR CNT Register */
/*! @{ */

#define DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V_MASK (0xFFFFU)
#define DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V_SHIFT (0U)
#define DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V_WIDTH (16U)
#define DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V(x) (((uint32_t)(((uint32_t)(x)) << DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V_SHIFT)) & DMSS_SAFETY_D_CSERR_CNT_D_CSERR_CNT_V_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DMSS_SAFETY_Register_Masks */

/*!
 * @}
 */ /* end of group DMSS_SAFETY_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_DMSS_SAFETY_H_) */
