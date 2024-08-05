/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_PMSS_SAFETY.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_PMSS_SAFETY
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
#if !defined(S32Z2_PMSS_SAFETY_H_)  /* Check if memory map has not been already included */
#define S32Z2_PMSS_SAFETY_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMSS_SAFETY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMSS_SAFETY_Peripheral_Access_Layer PMSS_SAFETY Peripheral Access Layer
 * @{
 */

/** PMSS_SAFETY - Register Layout Typedef */
typedef struct {
  __IO uint32_t P_UCSERR;                          /**< PMSS UCS ERR Register, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint32_t P_CSERR;                           /**< PMSS CS ERR Register, offset: 0x8 */
  uint8_t RESERVED_1[4];
  __O  uint32_t P_UCSERR_S;                        /**< PMSS UCS ERR Shadow Register, offset: 0x10 */
  __O  uint32_t P_CSERR_S;                         /**< PMSS CE ERR Shadow Register, offset: 0x14 */
  uint8_t RESERVED_2[4];
  __IO uint32_t P_CSERR_M;                         /**< PMSS CS ERR Mask Register, offset: 0x1C */
  uint8_t RESERVED_3[16];
  __IO uint32_t P_ECC_TCFG;                        /**< PMSS ECC TCFG Register, offset: 0x30 */
  __IO uint32_t P_ECC_TCFG_2;                      /**< PMSS ECC TCFG 2 Register, offset: 0x34 */
  uint8_t RESERVED_4[8];
  __IO uint32_t P_CTECC_TCFG;                      /**< PMSS CT ECC TCFG Register, offset: 0x40 */
  uint8_t RESERVED_5[12];
  __IO uint32_t P_BTBECC_TCFG;                     /**< PMSS BTB ECC TCFG Register, offset: 0x50 */
  uint8_t RESERVED_6[28];
  __I  uint32_t P_UCSERR_CNT;                      /**< PMSS UCSERR CNT Register, offset: 0x70 */
  __I  uint32_t P_CSERR_CNT;                       /**< PMSS CSERR CNT Register, offset: 0x74 */
  __IO uint32_t P_LPCS;                            /**< PMSS LPCS Register, offset: 0x78 */
} PMSS_SAFETY_Type, *PMSS_SAFETY_MemMapPtr;

/** Number of instances of the PMSS_SAFETY module. */
#define PMSS_SAFETY_INSTANCE_COUNT               (1u)

/* PMSS_SAFETY - Peripheral instance base addresses */
/** Peripheral CEVA_SPF2__PMSS_SAFETY base address */
#define IP_CEVA_SPF2__PMSS_SAFETY_BASE           (0x24400580u)
/** Peripheral CEVA_SPF2__PMSS_SAFETY base pointer */
#define IP_CEVA_SPF2__PMSS_SAFETY                ((PMSS_SAFETY_Type *)IP_CEVA_SPF2__PMSS_SAFETY_BASE)
/** Array initializer of PMSS_SAFETY peripheral base addresses */
#define IP_PMSS_SAFETY_BASE_ADDRS                { IP_CEVA_SPF2__PMSS_SAFETY_BASE }
/** Array initializer of PMSS_SAFETY peripheral base pointers */
#define IP_PMSS_SAFETY_BASE_PTRS                 { IP_CEVA_SPF2__PMSS_SAFETY }

/* ----------------------------------------------------------------------------
   -- PMSS_SAFETY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMSS_SAFETY_Register_Masks PMSS_SAFETY Register Masks
 * @{
 */

/*! @name P_UCSERR - PMSS UCS ERR Register */
/*! @{ */

#define PMSS_SAFETY_P_UCSERR_P_UCSERR_MASK       (0x1U)
#define PMSS_SAFETY_P_UCSERR_P_UCSERR_SHIFT      (0U)
#define PMSS_SAFETY_P_UCSERR_P_UCSERR_WIDTH      (1U)
#define PMSS_SAFETY_P_UCSERR_P_UCSERR(x)         (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_P_UCSERR_SHIFT)) & PMSS_SAFETY_P_UCSERR_P_UCSERR_MASK)

#define PMSS_SAFETY_P_UCSERR_P_CORE_PERR_MASK    (0x20U)
#define PMSS_SAFETY_P_UCSERR_P_CORE_PERR_SHIFT   (5U)
#define PMSS_SAFETY_P_UCSERR_P_CORE_PERR_WIDTH   (1U)
#define PMSS_SAFETY_P_UCSERR_P_CORE_PERR(x)      (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_P_CORE_PERR_SHIFT)) & PMSS_SAFETY_P_UCSERR_P_CORE_PERR_MASK)

#define PMSS_SAFETY_P_UCSERR_P_MSS_PERR_MASK     (0x40U)
#define PMSS_SAFETY_P_UCSERR_P_MSS_PERR_SHIFT    (6U)
#define PMSS_SAFETY_P_UCSERR_P_MSS_PERR_WIDTH    (1U)
#define PMSS_SAFETY_P_UCSERR_P_MSS_PERR(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_P_MSS_PERR_SHIFT)) & PMSS_SAFETY_P_UCSERR_P_MSS_PERR_MASK)

#define PMSS_SAFETY_P_UCSERR_P_UCECNTEV_MASK     (0x10000U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTEV_SHIFT    (16U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTEV_WIDTH    (1U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTEV(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_P_UCECNTEV_SHIFT)) & PMSS_SAFETY_P_UCSERR_P_UCECNTEV_MASK)

#define PMSS_SAFETY_P_UCSERR_P_UCECNTOV_MASK     (0x20000U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTOV_SHIFT    (17U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTOV_WIDTH    (1U)
#define PMSS_SAFETY_P_UCSERR_P_UCECNTOV(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_P_UCECNTOV_SHIFT)) & PMSS_SAFETY_P_UCSERR_P_UCECNTOV_MASK)
/*! @} */

/*! @name P_CSERR - PMSS CS ERR Register */
/*! @{ */

#define PMSS_SAFETY_P_CSERR_P_CSERR_MASK         (0x1U)
#define PMSS_SAFETY_P_CSERR_P_CSERR_SHIFT        (0U)
#define PMSS_SAFETY_P_CSERR_P_CSERR_WIDTH        (1U)
#define PMSS_SAFETY_P_CSERR_P_CSERR(x)           (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_CSERR_SHIFT)) & PMSS_SAFETY_P_CSERR_P_CSERR_MASK)

#define PMSS_SAFETY_P_CSERR_P_ECC_COR_MASK       (0x2U)
#define PMSS_SAFETY_P_CSERR_P_ECC_COR_SHIFT      (1U)
#define PMSS_SAFETY_P_CSERR_P_ECC_COR_WIDTH      (1U)
#define PMSS_SAFETY_P_CSERR_P_ECC_COR(x)         (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_ECC_COR_SHIFT)) & PMSS_SAFETY_P_CSERR_P_ECC_COR_MASK)

#define PMSS_SAFETY_P_CSERR_P_CTECC_COR_MASK     (0x4U)
#define PMSS_SAFETY_P_CSERR_P_CTECC_COR_SHIFT    (2U)
#define PMSS_SAFETY_P_CSERR_P_CTECC_COR_WIDTH    (1U)
#define PMSS_SAFETY_P_CSERR_P_CTECC_COR(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_CTECC_COR_SHIFT)) & PMSS_SAFETY_P_CSERR_P_CTECC_COR_MASK)

#define PMSS_SAFETY_P_CSERR_P_BTBECC_COR_MASK    (0x8U)
#define PMSS_SAFETY_P_CSERR_P_BTBECC_COR_SHIFT   (3U)
#define PMSS_SAFETY_P_CSERR_P_BTBECC_COR_WIDTH   (1U)
#define PMSS_SAFETY_P_CSERR_P_BTBECC_COR(x)      (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_BTBECC_COR_SHIFT)) & PMSS_SAFETY_P_CSERR_P_BTBECC_COR_MASK)

#define PMSS_SAFETY_P_CSERR_P_CECNTEV_MASK       (0x10000U)
#define PMSS_SAFETY_P_CSERR_P_CECNTEV_SHIFT      (16U)
#define PMSS_SAFETY_P_CSERR_P_CECNTEV_WIDTH      (1U)
#define PMSS_SAFETY_P_CSERR_P_CECNTEV(x)         (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_CECNTEV_SHIFT)) & PMSS_SAFETY_P_CSERR_P_CECNTEV_MASK)

#define PMSS_SAFETY_P_CSERR_P_CECNTOV_MASK       (0x20000U)
#define PMSS_SAFETY_P_CSERR_P_CECNTOV_SHIFT      (17U)
#define PMSS_SAFETY_P_CSERR_P_CECNTOV_WIDTH      (1U)
#define PMSS_SAFETY_P_CSERR_P_CECNTOV(x)         (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_P_CECNTOV_SHIFT)) & PMSS_SAFETY_P_CSERR_P_CECNTOV_MASK)
/*! @} */

/*! @name P_UCSERR_S - PMSS UCS ERR Shadow Register */
/*! @{ */

#define PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S_MASK (0x20U)
#define PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S_SHIFT (5U)
#define PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S_WIDTH (1U)
#define PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S(x)  (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S_SHIFT)) & PMSS_SAFETY_P_UCSERR_S_P_CORE_PERR_S_MASK)

#define PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S_MASK (0x40U)
#define PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S_SHIFT (6U)
#define PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S_WIDTH (1U)
#define PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S(x)   (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S_SHIFT)) & PMSS_SAFETY_P_UCSERR_S_P_MSS_PERR_S_MASK)
/*! @} */

/*! @name P_CSERR_S - PMSS CE ERR Shadow Register */
/*! @{ */

#define PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S_MASK   (0x2U)
#define PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S_SHIFT  (1U)
#define PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S_WIDTH  (1U)
#define PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S(x)     (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S_SHIFT)) & PMSS_SAFETY_P_CSERR_S_P_ECC_COR_S_MASK)

#define PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S_MASK (0x4U)
#define PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S_SHIFT (2U)
#define PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S_WIDTH (1U)
#define PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S(x)   (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S_SHIFT)) & PMSS_SAFETY_P_CSERR_S_P_CTECC_COR_S_MASK)

#define PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S_MASK (0x8U)
#define PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S_SHIFT (3U)
#define PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S_WIDTH (1U)
#define PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S(x)  (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S_SHIFT)) & PMSS_SAFETY_P_CSERR_S_P_BTBECC_COR_S_MASK)
/*! @} */

/*! @name P_CSERR_M - PMSS CS ERR Mask Register */
/*! @{ */

#define PMSS_SAFETY_P_CSERR_M_P_CSERR_M_MASK     (0x1U)
#define PMSS_SAFETY_P_CSERR_M_P_CSERR_M_SHIFT    (0U)
#define PMSS_SAFETY_P_CSERR_M_P_CSERR_M_WIDTH    (1U)
#define PMSS_SAFETY_P_CSERR_M_P_CSERR_M(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_M_P_CSERR_M_SHIFT)) & PMSS_SAFETY_P_CSERR_M_P_CSERR_M_MASK)

#define PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M_MASK   (0x2U)
#define PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M_SHIFT  (1U)
#define PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M_WIDTH  (1U)
#define PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M(x)     (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M_SHIFT)) & PMSS_SAFETY_P_CSERR_M_P_ECC_COR_M_MASK)

#define PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M_MASK (0x4U)
#define PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M_SHIFT (2U)
#define PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M_WIDTH (1U)
#define PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M(x)   (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M_SHIFT)) & PMSS_SAFETY_P_CSERR_M_P_CTECC_COR_M_MASK)

#define PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M_MASK (0x8U)
#define PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M_SHIFT (3U)
#define PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M_WIDTH (1U)
#define PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M(x)  (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M_SHIFT)) & PMSS_SAFETY_P_CSERR_M_P_BTBECC_COR_M_MASK)
/*! @} */

/*! @name P_ECC_TCFG - PMSS ECC TCFG Register */
/*! @{ */

#define PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG_MASK    (0xFFFFFFFFU)
#define PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG_SHIFT   (0U)
#define PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG_WIDTH   (32U)
#define PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG(x)      (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG_SHIFT)) & PMSS_SAFETY_P_ECC_TCFG_P_FLIPCFG_MASK)
/*! @} */

/*! @name P_ECC_TCFG_2 - PMSS ECC TCFG 2 Register */
/*! @{ */

#define PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE_MASK (0x7FU)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE_SHIFT (0U)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE_WIDTH (7U)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE(x)   (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE_SHIFT)) & PMSS_SAFETY_P_ECC_TCFG_2_P_FLIPCFGE_MASK)

#define PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG_MASK     (0x80000000U)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG_SHIFT    (31U)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG_WIDTH    (1U)
#define PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG(x)       (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG_SHIFT)) & PMSS_SAFETY_P_ECC_TCFG_2_P_TRIG_MASK)
/*! @} */

/*! @name P_CTECC_TCFG - PMSS CT ECC TCFG Register */
/*! @{ */

#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG_MASK (0x7FFU)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG_SHIFT (0U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG_WIDTH (11U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG(x)   (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG_SHIFT)) & PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFG_MASK)

#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE_MASK (0x7800U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE_SHIFT (11U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE_WIDTH (4U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE(x)  (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE_SHIFT)) & PMSS_SAFETY_P_CTECC_TCFG_PT_FLIPCFGE_MASK)

#define PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG_MASK    (0x80000000U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG_SHIFT   (31U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG_WIDTH   (1U)
#define PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG(x)      (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG_SHIFT)) & PMSS_SAFETY_P_CTECC_TCFG_PT_TRIG_MASK)
/*! @} */

/*! @name P_BTBECC_TCFG - PMSS BTB ECC TCFG Register */
/*! @{ */

#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG_MASK (0x7FFU)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG_SHIFT (0U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG_WIDTH (11U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG(x)  (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG_SHIFT)) & PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFG_MASK)

#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE_MASK (0x7800U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE_SHIFT (11U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE_WIDTH (4U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE(x) (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE_SHIFT)) & PMSS_SAFETY_P_BTBECC_TCFG_PB_FLIPCFGE_MASK)

#define PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG_MASK   (0x80000000U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG_SHIFT  (31U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG_WIDTH  (1U)
#define PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG(x)     (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG_SHIFT)) & PMSS_SAFETY_P_BTBECC_TCFG_PB_TRIG_MASK)
/*! @} */

/*! @name P_UCSERR_CNT - PMSS UCSERR CNT Register */
/*! @{ */

#define PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V_MASK (0xFFFFU)
#define PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V_SHIFT (0U)
#define PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V_WIDTH (16U)
#define PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V(x) (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V_SHIFT)) & PMSS_SAFETY_P_UCSERR_CNT_P_UCSERR_CNT_V_MASK)
/*! @} */

/*! @name P_CSERR_CNT - PMSS CSERR CNT Register */
/*! @{ */

#define PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V_MASK (0xFFFFU)
#define PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V_SHIFT (0U)
#define PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V_WIDTH (16U)
#define PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V(x) (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V_SHIFT)) & PMSS_SAFETY_P_CSERR_CNT_P_CSERR_CNT_V_MASK)
/*! @} */

/*! @name P_LPCS - PMSS LPCS Register */
/*! @{ */

#define PMSS_SAFETY_P_LPCS_TS_MASK               (0x1U)
#define PMSS_SAFETY_P_LPCS_TS_SHIFT              (0U)
#define PMSS_SAFETY_P_LPCS_TS_WIDTH              (1U)
#define PMSS_SAFETY_P_LPCS_TS(x)                 (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_LPCS_TS_SHIFT)) & PMSS_SAFETY_P_LPCS_TS_MASK)

#define PMSS_SAFETY_P_LPCS_WSEL_MASK             (0x30U)
#define PMSS_SAFETY_P_LPCS_WSEL_SHIFT            (4U)
#define PMSS_SAFETY_P_LPCS_WSEL_WIDTH            (2U)
#define PMSS_SAFETY_P_LPCS_WSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMSS_SAFETY_P_LPCS_WSEL_SHIFT)) & PMSS_SAFETY_P_LPCS_WSEL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMSS_SAFETY_Register_Masks */

/*!
 * @}
 */ /* end of group PMSS_SAFETY_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_PMSS_SAFETY_H_) */
