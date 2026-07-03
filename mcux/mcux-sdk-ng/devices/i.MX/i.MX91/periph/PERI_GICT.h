/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GICT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_GICT.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for GICT
 *
 * CMSIS Peripheral Access Layer for GICT
 */

#if !defined(PERI_GICT_H_)
#define PERI_GICT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- GICT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICT_Peripheral_Access_Layer GICT Peripheral Access Layer
 * @{
 */

/** GICT - Register Layout Typedef */
typedef struct {
  __I  uint64_t GICT_ERR0FR;                       /**< GICT_ERR0FR, offset: 0x0 */
  __IO uint64_t GICT_ERR0CTLR;                     /**< GICT_ERR0CTLR, offset: 0x8 */
  __IO uint64_t GICT_ERR0STATUS;                   /**< GICT_ERR0STATUS, offset: 0x10 */
  __I  uint64_t GICT_ERR0ADDR;                     /**< GICT_ERR0ADDR, offset: 0x18 */
  __IO uint64_t GICT_ERR0MISC0;                    /**< GICT_ERR0MISC0, offset: 0x20 */
  __IO uint64_t GICT_ERR0MISC1;                    /**< GICT_ERR0MISC1, offset: 0x28 */
       uint8_t RESERVED_0[16];
  __I  uint64_t GICT_ERR1FR;                       /**< GICT_ERR1FR, offset: 0x40 */
  __IO uint64_t GICT_ERR1CTLR;                     /**< GICT_ERR1CTLR, offset: 0x48 */
  __IO uint64_t GICT_ERR1STATUS;                   /**< GICT_ERR1STATUS, offset: 0x50 */
       uint8_t RESERVED_1[8];
  __IO uint64_t GICT_ERR1MISC0;                    /**< GICT_ERR1MISC0, offset: 0x60 */
  __IO uint64_t GICT_ERR1MISC1;                    /**< GICT_ERR1MISC1, offset: 0x68 */
       uint8_t RESERVED_2[16];
  __I  uint64_t GICT_ERR2FR;                       /**< GICT_ERR2FR, offset: 0x80 */
  __IO uint64_t GICT_ERR2CTLR;                     /**< GICT_ERR2CTLR, offset: 0x88 */
  __IO uint64_t GICT_ERR2STATUS;                   /**< GICT_ERR2STATUS, offset: 0x90 */
       uint8_t RESERVED_3[8];
  __IO uint64_t GICT_ERR2MISC0;                    /**< GICT_ERR2MISC0, offset: 0xA0 */
  __IO uint64_t GICT_ERR2MISC1;                    /**< GICT_ERR2MISC1, offset: 0xA8 */
       uint8_t RESERVED_4[16];
  __I  uint64_t GICT_ERR3FR;                       /**< GICT_ERR3FR, offset: 0xC0 */
  __IO uint64_t GICT_ERR3CTLR;                     /**< GICT_ERR3CTLR, offset: 0xC8 */
  __IO uint64_t GICT_ERR3STATUS;                   /**< GICT_ERR3STATUS, offset: 0xD0 */
       uint8_t RESERVED_5[8];
  __IO uint64_t GICT_ERR3MISC0;                    /**< GICT_ERR3MISC0, offset: 0xE0 */
  __IO uint64_t GICT_ERR3MISC1;                    /**< GICT_ERR3MISC1, offset: 0xE8 */
       uint8_t RESERVED_6[16];
  __I  uint64_t GICT_ERR4FR;                       /**< GICT_ERR4FR, offset: 0x100 */
  __IO uint64_t GICT_ERR4CTLR;                     /**< GICT_ERR4CTLR, offset: 0x108 */
  __IO uint64_t GICT_ERR4STATUS;                   /**< GICT_ERR4STATUS, offset: 0x110 */
       uint8_t RESERVED_7[8];
  __IO uint64_t GICT_ERR4MISC0;                    /**< GICT_ERR4MISC0, offset: 0x120 */
  __IO uint64_t GICT_ERR4MISC1;                    /**< GICT_ERR4MISC1, offset: 0x128 */
       uint8_t RESERVED_8[16];
  __I  uint64_t GICT_ERR5FR;                       /**< GICT_ERR5FR, offset: 0x140 */
  __IO uint64_t GICT_ERR5CTLR;                     /**< GICT_ERR5CTLR, offset: 0x148 */
  __IO uint64_t GICT_ERR5STATUS;                   /**< GICT_ERR5STATUS, offset: 0x150 */
       uint8_t RESERVED_9[8];
  __IO uint64_t GICT_ERR5MISC0;                    /**< GICT_ERR5MISC0, offset: 0x160 */
  __IO uint64_t GICT_ERR5MISC1;                    /**< GICT_ERR5MISC1, offset: 0x168 */
       uint8_t RESERVED_10[16];
  __I  uint64_t GICT_ERR6FR;                       /**< GICT_ERR6FR, offset: 0x180 */
  __IO uint64_t GICT_ERR6CTLR;                     /**< GICT_ERR6CTLR, offset: 0x188 */
  __IO uint64_t GICT_ERR6STATUS;                   /**< GICT_ERR6STATUS, offset: 0x190 */
       uint8_t RESERVED_11[8];
  __IO uint64_t GICT_ERR6MISC0;                    /**< GICT_ERR6MISC0, offset: 0x1A0 */
  __IO uint64_t GICT_ERR6MISC1;                    /**< GICT_ERR6MISC1, offset: 0x1A8 */
       uint8_t RESERVED_12[16];
  __I  uint64_t GICT_ERR7FR;                       /**< GICT_ERR7FR, offset: 0x1C0 */
  __IO uint64_t GICT_ERR7CTLR;                     /**< GICT_ERR7CTLR, offset: 0x1C8 */
  __IO uint64_t GICT_ERR7STATUS;                   /**< GICT_ERR7STATUS, offset: 0x1D0 */
       uint8_t RESERVED_13[8];
  __IO uint64_t GICT_ERR7MISC0;                    /**< GICT_ERR7MISC0, offset: 0x1E0 */
  __IO uint64_t GICT_ERR7MISC1;                    /**< GICT_ERR7MISC1, offset: 0x1E8 */
       uint8_t RESERVED_14[16];
  __I  uint64_t GICT_ERR8FR;                       /**< GICT_ERR8FR, offset: 0x200 */
  __IO uint64_t GICT_ERR8CTLR;                     /**< GICT_ERR8CTLR, offset: 0x208 */
  __IO uint64_t GICT_ERR8STATUS;                   /**< GICT_ERR8STATUS, offset: 0x210 */
       uint8_t RESERVED_15[8];
  __IO uint64_t GICT_ERR8MISC0;                    /**< GICT_ERR8MISC0, offset: 0x220 */
  __IO uint64_t GICT_ERR8MISC1;                    /**< GICT_ERR8MISC1, offset: 0x228 */
       uint8_t RESERVED_16[56784];
  __I  uint64_t GICT_ERRGSR0;                      /**< GICT_ERRGSR0, offset: 0xE000 */
       uint8_t RESERVED_17[2040];
  __IO uint64_t GICT_ERRIRQCR0;                    /**< GICT_ERRIRQCR0, offset: 0xE800 */
  __IO uint64_t GICT_ERRIRQCR1;                    /**< GICT_ERRIRQCR1, offset: 0xE808 */
       uint8_t RESERVED_18[6060];
  __I  uint32_t GICT_DEVARCH;                      /**< GICT_DEVARCH, offset: 0xFFBC */
       uint8_t RESERVED_19[8];
  __I  uint32_t GICT_DEVID;                        /**< GICT_DEVID, offset: 0xFFC8 */
       uint8_t RESERVED_20[4];
  __I  uint32_t GICT_PIDR4;                        /**< GICT_PIDR4, offset: 0xFFD0 */
  __I  uint32_t GICT_PIDR5;                        /**< GICT_PIDR5, offset: 0xFFD4 */
  __I  uint32_t GICT_PIDR6;                        /**< GICT_PIDR6, offset: 0xFFD8 */
  __I  uint32_t GICT_PIDR7;                        /**< GICT_PIDR7, offset: 0xFFDC */
  __I  uint32_t GICT_PIDR0;                        /**< GICT_PIDR0, offset: 0xFFE0 */
  __I  uint32_t GICT_PIDR1;                        /**< GICT_PIDR1, offset: 0xFFE4 */
  __I  uint32_t GICT_PIDR2;                        /**< GICT_PIDR2, offset: 0xFFE8 */
  __I  uint32_t GICT_PIDR3;                        /**< GICT_PIDR3, offset: 0xFFEC */
  __I  uint32_t GICT_CIDR0;                        /**< GICT_CIDR0, offset: 0xFFF0 */
  __I  uint32_t GICT_CIDR1;                        /**< GICT_CIDR1, offset: 0xFFF4 */
  __I  uint32_t GICT_CIDR2;                        /**< GICT_CIDR2, offset: 0xFFF8 */
  __I  uint32_t GICT_CIDR3;                        /**< GICT_CIDR3, offset: 0xFFFC */
} GICT_Type;

/* ----------------------------------------------------------------------------
   -- GICT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GICT_Register_Masks GICT Register Masks
 * @{
 */

/*! @name GICT_ERR0FR - GICT_ERR0FR */
/*! @{ */

#define GICT_GICT_ERR0FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR0FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR0FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_ED_SHIFT)) & GICT_GICT_ERR0FR_ED_MASK)

#define GICT_GICT_ERR0FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR0FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR0FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_DE_SHIFT)) & GICT_GICT_ERR0FR_DE_MASK)

#define GICT_GICT_ERR0FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR0FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR0FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_UI_SHIFT)) & GICT_GICT_ERR0FR_UI_MASK)

#define GICT_GICT_ERR0FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR0FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR0FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_FI_SHIFT)) & GICT_GICT_ERR0FR_FI_MASK)

#define GICT_GICT_ERR0FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR0FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR0FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_UE_SHIFT)) & GICT_GICT_ERR0FR_UE_MASK)

#define GICT_GICT_ERR0FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR0FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR0FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_CFI_SHIFT)) & GICT_GICT_ERR0FR_CFI_MASK)

#define GICT_GICT_ERR0FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR0FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR0FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_CEC_SHIFT)) & GICT_GICT_ERR0FR_CEC_MASK)

#define GICT_GICT_ERR0FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR0FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR0FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_RP_SHIFT)) & GICT_GICT_ERR0FR_RP_MASK)

#define GICT_GICT_ERR0FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR0FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR0FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0FR_RESERVED0_SHIFT)) & GICT_GICT_ERR0FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR0CTLR - GICT_ERR0CTLR */
/*! @{ */

#define GICT_GICT_ERR0CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR0CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR0CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR0CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR0CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR0CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR0CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_UI_SHIFT)) & GICT_GICT_ERR0CTLR_UI_MASK)

#define GICT_GICT_ERR0CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR0CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR0CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_FI_SHIFT)) & GICT_GICT_ERR0CTLR_FI_MASK)

#define GICT_GICT_ERR0CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR0CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR0CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_UE_SHIFT)) & GICT_GICT_ERR0CTLR_UE_MASK)

#define GICT_GICT_ERR0CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR0CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR0CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR0CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR0CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR0CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR0CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_CFI_SHIFT)) & GICT_GICT_ERR0CTLR_CFI_MASK)

#define GICT_GICT_ERR0CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR0CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR0CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR0CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR0CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR0CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR0CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_RP_SHIFT)) & GICT_GICT_ERR0CTLR_RP_MASK)

#define GICT_GICT_ERR0CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR0CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR0CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR0CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR0STATUS - GICT_ERR0STATUS */
/*! @{ */

#define GICT_GICT_ERR0STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR0STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR0STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_SERR_SHIFT)) & GICT_GICT_ERR0STATUS_SERR_MASK)

#define GICT_GICT_ERR0STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR0STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR0STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_IERR_SHIFT)) & GICT_GICT_ERR0STATUS_IERR_MASK)

#define GICT_GICT_ERR0STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR0STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR0STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR0STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR0STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR0STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR0STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_UET_SHIFT)) & GICT_GICT_ERR0STATUS_UET_MASK)

#define GICT_GICT_ERR0STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR0STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR0STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR0STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR0STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR0STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR0STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_CE_SHIFT)) & GICT_GICT_ERR0STATUS_CE_MASK)

#define GICT_GICT_ERR0STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR0STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR0STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_MV_SHIFT)) & GICT_GICT_ERR0STATUS_MV_MASK)

#define GICT_GICT_ERR0STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR0STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR0STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_OF_SHIFT)) & GICT_GICT_ERR0STATUS_OF_MASK)

#define GICT_GICT_ERR0STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR0STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR0STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_ER_SHIFT)) & GICT_GICT_ERR0STATUS_ER_MASK)

#define GICT_GICT_ERR0STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR0STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR0STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_UE_SHIFT)) & GICT_GICT_ERR0STATUS_UE_MASK)

#define GICT_GICT_ERR0STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR0STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR0STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_V_SHIFT)) & GICT_GICT_ERR0STATUS_V_MASK)

#define GICT_GICT_ERR0STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR0STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR0STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_AV_SHIFT)) & GICT_GICT_ERR0STATUS_AV_MASK)

#define GICT_GICT_ERR0STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR0STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR0STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR0STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR0ADDR - GICT_ERR0ADDR */
/*! @{ */

#define GICT_GICT_ERR0ADDR_PADDR_MASK            (0xFFFFFFFFFFFFU)
#define GICT_GICT_ERR0ADDR_PADDR_SHIFT           (0U)
/*! PADDR - PADDR */
#define GICT_GICT_ERR0ADDR_PADDR(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0ADDR_PADDR_SHIFT)) & GICT_GICT_ERR0ADDR_PADDR_MASK)

#define GICT_GICT_ERR0ADDR_RESERVED0_MASK        (0x7FFF000000000000U)
#define GICT_GICT_ERR0ADDR_RESERVED0_SHIFT       (48U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR0ADDR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0ADDR_RESERVED0_SHIFT)) & GICT_GICT_ERR0ADDR_RESERVED0_MASK)

#define GICT_GICT_ERR0ADDR_NS_MASK               (0x8000000000000000U)
#define GICT_GICT_ERR0ADDR_NS_SHIFT              (63U)
/*! NS - NS */
#define GICT_GICT_ERR0ADDR_NS(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0ADDR_NS_SHIFT)) & GICT_GICT_ERR0ADDR_NS_MASK)
/*! @} */

/*! @name GICT_ERR0MISC0 - GICT_ERR0MISC0 */
/*! @{ */

#define GICT_GICT_ERR0MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR0MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR0MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC0_Data_SHIFT)) & GICT_GICT_ERR0MISC0_Data_MASK)

#define GICT_GICT_ERR0MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR0MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR0MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC0_CNT_SHIFT)) & GICT_GICT_ERR0MISC0_CNT_MASK)

#define GICT_GICT_ERR0MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR0MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR0MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC0_OF_SHIFT)) & GICT_GICT_ERR0MISC0_OF_MASK)

#define GICT_GICT_ERR0MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR0MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR0MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC0_RE_SHIFT)) & GICT_GICT_ERR0MISC0_RE_MASK)

#define GICT_GICT_ERR0MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR0MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR0MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR0MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR0MISC1 - GICT_ERR0MISC1 */
/*! @{ */

#define GICT_GICT_ERR0MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR0MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR0MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR0MISC1_DATA_SHIFT)) & GICT_GICT_ERR0MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR1FR - GICT_ERR1FR */
/*! @{ */

#define GICT_GICT_ERR1FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR1FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR1FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_ED_SHIFT)) & GICT_GICT_ERR1FR_ED_MASK)

#define GICT_GICT_ERR1FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR1FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR1FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_DE_SHIFT)) & GICT_GICT_ERR1FR_DE_MASK)

#define GICT_GICT_ERR1FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR1FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR1FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_UI_SHIFT)) & GICT_GICT_ERR1FR_UI_MASK)

#define GICT_GICT_ERR1FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR1FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR1FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_FI_SHIFT)) & GICT_GICT_ERR1FR_FI_MASK)

#define GICT_GICT_ERR1FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR1FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR1FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_UE_SHIFT)) & GICT_GICT_ERR1FR_UE_MASK)

#define GICT_GICT_ERR1FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR1FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR1FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_CFI_SHIFT)) & GICT_GICT_ERR1FR_CFI_MASK)

#define GICT_GICT_ERR1FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR1FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR1FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_CEC_SHIFT)) & GICT_GICT_ERR1FR_CEC_MASK)

#define GICT_GICT_ERR1FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR1FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR1FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_RP_SHIFT)) & GICT_GICT_ERR1FR_RP_MASK)

#define GICT_GICT_ERR1FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR1FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR1FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1FR_RESERVED0_SHIFT)) & GICT_GICT_ERR1FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR1CTLR - GICT_ERR1CTLR */
/*! @{ */

#define GICT_GICT_ERR1CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR1CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR1CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR1CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR1CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR1CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR1CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_UI_SHIFT)) & GICT_GICT_ERR1CTLR_UI_MASK)

#define GICT_GICT_ERR1CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR1CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR1CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_FI_SHIFT)) & GICT_GICT_ERR1CTLR_FI_MASK)

#define GICT_GICT_ERR1CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR1CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR1CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_UE_SHIFT)) & GICT_GICT_ERR1CTLR_UE_MASK)

#define GICT_GICT_ERR1CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR1CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR1CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR1CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR1CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR1CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR1CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_CFI_SHIFT)) & GICT_GICT_ERR1CTLR_CFI_MASK)

#define GICT_GICT_ERR1CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR1CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR1CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR1CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR1CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR1CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR1CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_RP_SHIFT)) & GICT_GICT_ERR1CTLR_RP_MASK)

#define GICT_GICT_ERR1CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR1CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR1CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR1CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR1STATUS - GICT_ERR1STATUS */
/*! @{ */

#define GICT_GICT_ERR1STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR1STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR1STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_SERR_SHIFT)) & GICT_GICT_ERR1STATUS_SERR_MASK)

#define GICT_GICT_ERR1STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR1STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR1STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_IERR_SHIFT)) & GICT_GICT_ERR1STATUS_IERR_MASK)

#define GICT_GICT_ERR1STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR1STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR1STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR1STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR1STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR1STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR1STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_UET_SHIFT)) & GICT_GICT_ERR1STATUS_UET_MASK)

#define GICT_GICT_ERR1STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR1STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR1STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR1STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR1STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR1STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR1STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_CE_SHIFT)) & GICT_GICT_ERR1STATUS_CE_MASK)

#define GICT_GICT_ERR1STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR1STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR1STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_MV_SHIFT)) & GICT_GICT_ERR1STATUS_MV_MASK)

#define GICT_GICT_ERR1STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR1STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR1STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_OF_SHIFT)) & GICT_GICT_ERR1STATUS_OF_MASK)

#define GICT_GICT_ERR1STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR1STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR1STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_ER_SHIFT)) & GICT_GICT_ERR1STATUS_ER_MASK)

#define GICT_GICT_ERR1STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR1STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR1STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_UE_SHIFT)) & GICT_GICT_ERR1STATUS_UE_MASK)

#define GICT_GICT_ERR1STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR1STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR1STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_V_SHIFT)) & GICT_GICT_ERR1STATUS_V_MASK)

#define GICT_GICT_ERR1STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR1STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR1STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_AV_SHIFT)) & GICT_GICT_ERR1STATUS_AV_MASK)

#define GICT_GICT_ERR1STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR1STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR1STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR1STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR1MISC0 - GICT_ERR1MISC0 */
/*! @{ */

#define GICT_GICT_ERR1MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR1MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR1MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC0_Data_SHIFT)) & GICT_GICT_ERR1MISC0_Data_MASK)

#define GICT_GICT_ERR1MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR1MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR1MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC0_CNT_SHIFT)) & GICT_GICT_ERR1MISC0_CNT_MASK)

#define GICT_GICT_ERR1MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR1MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR1MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC0_OF_SHIFT)) & GICT_GICT_ERR1MISC0_OF_MASK)

#define GICT_GICT_ERR1MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR1MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR1MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC0_RE_SHIFT)) & GICT_GICT_ERR1MISC0_RE_MASK)

#define GICT_GICT_ERR1MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR1MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR1MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR1MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR1MISC1 - GICT_ERR1MISC1 */
/*! @{ */

#define GICT_GICT_ERR1MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR1MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR1MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR1MISC1_DATA_SHIFT)) & GICT_GICT_ERR1MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR2FR - GICT_ERR2FR */
/*! @{ */

#define GICT_GICT_ERR2FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR2FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR2FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_ED_SHIFT)) & GICT_GICT_ERR2FR_ED_MASK)

#define GICT_GICT_ERR2FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR2FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR2FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_DE_SHIFT)) & GICT_GICT_ERR2FR_DE_MASK)

#define GICT_GICT_ERR2FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR2FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR2FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_UI_SHIFT)) & GICT_GICT_ERR2FR_UI_MASK)

#define GICT_GICT_ERR2FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR2FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR2FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_FI_SHIFT)) & GICT_GICT_ERR2FR_FI_MASK)

#define GICT_GICT_ERR2FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR2FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR2FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_UE_SHIFT)) & GICT_GICT_ERR2FR_UE_MASK)

#define GICT_GICT_ERR2FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR2FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR2FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_CFI_SHIFT)) & GICT_GICT_ERR2FR_CFI_MASK)

#define GICT_GICT_ERR2FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR2FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR2FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_CEC_SHIFT)) & GICT_GICT_ERR2FR_CEC_MASK)

#define GICT_GICT_ERR2FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR2FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR2FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_RP_SHIFT)) & GICT_GICT_ERR2FR_RP_MASK)

#define GICT_GICT_ERR2FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR2FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR2FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2FR_RESERVED0_SHIFT)) & GICT_GICT_ERR2FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR2CTLR - GICT_ERR2CTLR */
/*! @{ */

#define GICT_GICT_ERR2CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR2CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR2CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR2CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR2CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR2CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR2CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_UI_SHIFT)) & GICT_GICT_ERR2CTLR_UI_MASK)

#define GICT_GICT_ERR2CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR2CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR2CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_FI_SHIFT)) & GICT_GICT_ERR2CTLR_FI_MASK)

#define GICT_GICT_ERR2CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR2CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR2CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_UE_SHIFT)) & GICT_GICT_ERR2CTLR_UE_MASK)

#define GICT_GICT_ERR2CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR2CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR2CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR2CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR2CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR2CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR2CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_CFI_SHIFT)) & GICT_GICT_ERR2CTLR_CFI_MASK)

#define GICT_GICT_ERR2CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR2CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR2CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR2CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR2CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR2CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR2CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_RP_SHIFT)) & GICT_GICT_ERR2CTLR_RP_MASK)

#define GICT_GICT_ERR2CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR2CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR2CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR2CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR2STATUS - GICT_ERR2STATUS */
/*! @{ */

#define GICT_GICT_ERR2STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR2STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR2STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_SERR_SHIFT)) & GICT_GICT_ERR2STATUS_SERR_MASK)

#define GICT_GICT_ERR2STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR2STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR2STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_IERR_SHIFT)) & GICT_GICT_ERR2STATUS_IERR_MASK)

#define GICT_GICT_ERR2STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR2STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR2STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR2STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR2STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR2STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR2STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_UET_SHIFT)) & GICT_GICT_ERR2STATUS_UET_MASK)

#define GICT_GICT_ERR2STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR2STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR2STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR2STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR2STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR2STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR2STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_CE_SHIFT)) & GICT_GICT_ERR2STATUS_CE_MASK)

#define GICT_GICT_ERR2STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR2STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR2STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_MV_SHIFT)) & GICT_GICT_ERR2STATUS_MV_MASK)

#define GICT_GICT_ERR2STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR2STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR2STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_OF_SHIFT)) & GICT_GICT_ERR2STATUS_OF_MASK)

#define GICT_GICT_ERR2STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR2STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR2STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_ER_SHIFT)) & GICT_GICT_ERR2STATUS_ER_MASK)

#define GICT_GICT_ERR2STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR2STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR2STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_UE_SHIFT)) & GICT_GICT_ERR2STATUS_UE_MASK)

#define GICT_GICT_ERR2STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR2STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR2STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_V_SHIFT)) & GICT_GICT_ERR2STATUS_V_MASK)

#define GICT_GICT_ERR2STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR2STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR2STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_AV_SHIFT)) & GICT_GICT_ERR2STATUS_AV_MASK)

#define GICT_GICT_ERR2STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR2STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR2STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR2STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR2MISC0 - GICT_ERR2MISC0 */
/*! @{ */

#define GICT_GICT_ERR2MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR2MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR2MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC0_Data_SHIFT)) & GICT_GICT_ERR2MISC0_Data_MASK)

#define GICT_GICT_ERR2MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR2MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR2MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC0_CNT_SHIFT)) & GICT_GICT_ERR2MISC0_CNT_MASK)

#define GICT_GICT_ERR2MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR2MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR2MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC0_OF_SHIFT)) & GICT_GICT_ERR2MISC0_OF_MASK)

#define GICT_GICT_ERR2MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR2MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR2MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC0_RE_SHIFT)) & GICT_GICT_ERR2MISC0_RE_MASK)

#define GICT_GICT_ERR2MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR2MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR2MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR2MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR2MISC1 - GICT_ERR2MISC1 */
/*! @{ */

#define GICT_GICT_ERR2MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR2MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR2MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR2MISC1_DATA_SHIFT)) & GICT_GICT_ERR2MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR3FR - GICT_ERR3FR */
/*! @{ */

#define GICT_GICT_ERR3FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR3FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR3FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_ED_SHIFT)) & GICT_GICT_ERR3FR_ED_MASK)

#define GICT_GICT_ERR3FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR3FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR3FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_DE_SHIFT)) & GICT_GICT_ERR3FR_DE_MASK)

#define GICT_GICT_ERR3FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR3FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR3FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_UI_SHIFT)) & GICT_GICT_ERR3FR_UI_MASK)

#define GICT_GICT_ERR3FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR3FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR3FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_FI_SHIFT)) & GICT_GICT_ERR3FR_FI_MASK)

#define GICT_GICT_ERR3FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR3FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR3FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_UE_SHIFT)) & GICT_GICT_ERR3FR_UE_MASK)

#define GICT_GICT_ERR3FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR3FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR3FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_CFI_SHIFT)) & GICT_GICT_ERR3FR_CFI_MASK)

#define GICT_GICT_ERR3FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR3FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR3FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_CEC_SHIFT)) & GICT_GICT_ERR3FR_CEC_MASK)

#define GICT_GICT_ERR3FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR3FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR3FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_RP_SHIFT)) & GICT_GICT_ERR3FR_RP_MASK)

#define GICT_GICT_ERR3FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR3FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR3FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3FR_RESERVED0_SHIFT)) & GICT_GICT_ERR3FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR3CTLR - GICT_ERR3CTLR */
/*! @{ */

#define GICT_GICT_ERR3CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR3CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR3CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR3CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR3CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR3CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR3CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_UI_SHIFT)) & GICT_GICT_ERR3CTLR_UI_MASK)

#define GICT_GICT_ERR3CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR3CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR3CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_FI_SHIFT)) & GICT_GICT_ERR3CTLR_FI_MASK)

#define GICT_GICT_ERR3CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR3CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR3CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_UE_SHIFT)) & GICT_GICT_ERR3CTLR_UE_MASK)

#define GICT_GICT_ERR3CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR3CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR3CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR3CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR3CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR3CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR3CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_CFI_SHIFT)) & GICT_GICT_ERR3CTLR_CFI_MASK)

#define GICT_GICT_ERR3CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR3CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR3CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR3CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR3CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR3CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR3CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_RP_SHIFT)) & GICT_GICT_ERR3CTLR_RP_MASK)

#define GICT_GICT_ERR3CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR3CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR3CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR3CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR3STATUS - GICT_ERR3STATUS */
/*! @{ */

#define GICT_GICT_ERR3STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR3STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR3STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_SERR_SHIFT)) & GICT_GICT_ERR3STATUS_SERR_MASK)

#define GICT_GICT_ERR3STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR3STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR3STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_IERR_SHIFT)) & GICT_GICT_ERR3STATUS_IERR_MASK)

#define GICT_GICT_ERR3STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR3STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR3STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR3STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR3STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR3STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR3STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_UET_SHIFT)) & GICT_GICT_ERR3STATUS_UET_MASK)

#define GICT_GICT_ERR3STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR3STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR3STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR3STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR3STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR3STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR3STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_CE_SHIFT)) & GICT_GICT_ERR3STATUS_CE_MASK)

#define GICT_GICT_ERR3STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR3STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR3STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_MV_SHIFT)) & GICT_GICT_ERR3STATUS_MV_MASK)

#define GICT_GICT_ERR3STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR3STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR3STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_OF_SHIFT)) & GICT_GICT_ERR3STATUS_OF_MASK)

#define GICT_GICT_ERR3STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR3STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR3STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_ER_SHIFT)) & GICT_GICT_ERR3STATUS_ER_MASK)

#define GICT_GICT_ERR3STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR3STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR3STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_UE_SHIFT)) & GICT_GICT_ERR3STATUS_UE_MASK)

#define GICT_GICT_ERR3STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR3STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR3STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_V_SHIFT)) & GICT_GICT_ERR3STATUS_V_MASK)

#define GICT_GICT_ERR3STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR3STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR3STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_AV_SHIFT)) & GICT_GICT_ERR3STATUS_AV_MASK)

#define GICT_GICT_ERR3STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR3STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR3STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR3STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR3MISC0 - GICT_ERR3MISC0 */
/*! @{ */

#define GICT_GICT_ERR3MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR3MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR3MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC0_Data_SHIFT)) & GICT_GICT_ERR3MISC0_Data_MASK)

#define GICT_GICT_ERR3MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR3MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR3MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC0_CNT_SHIFT)) & GICT_GICT_ERR3MISC0_CNT_MASK)

#define GICT_GICT_ERR3MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR3MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR3MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC0_OF_SHIFT)) & GICT_GICT_ERR3MISC0_OF_MASK)

#define GICT_GICT_ERR3MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR3MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR3MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC0_RE_SHIFT)) & GICT_GICT_ERR3MISC0_RE_MASK)

#define GICT_GICT_ERR3MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR3MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR3MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR3MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR3MISC1 - GICT_ERR3MISC1 */
/*! @{ */

#define GICT_GICT_ERR3MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR3MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR3MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR3MISC1_DATA_SHIFT)) & GICT_GICT_ERR3MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR4FR - GICT_ERR4FR */
/*! @{ */

#define GICT_GICT_ERR4FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR4FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR4FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_ED_SHIFT)) & GICT_GICT_ERR4FR_ED_MASK)

#define GICT_GICT_ERR4FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR4FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR4FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_DE_SHIFT)) & GICT_GICT_ERR4FR_DE_MASK)

#define GICT_GICT_ERR4FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR4FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR4FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_UI_SHIFT)) & GICT_GICT_ERR4FR_UI_MASK)

#define GICT_GICT_ERR4FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR4FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR4FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_FI_SHIFT)) & GICT_GICT_ERR4FR_FI_MASK)

#define GICT_GICT_ERR4FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR4FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR4FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_UE_SHIFT)) & GICT_GICT_ERR4FR_UE_MASK)

#define GICT_GICT_ERR4FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR4FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR4FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_CFI_SHIFT)) & GICT_GICT_ERR4FR_CFI_MASK)

#define GICT_GICT_ERR4FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR4FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR4FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_CEC_SHIFT)) & GICT_GICT_ERR4FR_CEC_MASK)

#define GICT_GICT_ERR4FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR4FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR4FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_RP_SHIFT)) & GICT_GICT_ERR4FR_RP_MASK)

#define GICT_GICT_ERR4FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR4FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR4FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4FR_RESERVED0_SHIFT)) & GICT_GICT_ERR4FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR4CTLR - GICT_ERR4CTLR */
/*! @{ */

#define GICT_GICT_ERR4CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR4CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR4CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR4CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR4CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR4CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR4CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_UI_SHIFT)) & GICT_GICT_ERR4CTLR_UI_MASK)

#define GICT_GICT_ERR4CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR4CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR4CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_FI_SHIFT)) & GICT_GICT_ERR4CTLR_FI_MASK)

#define GICT_GICT_ERR4CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR4CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR4CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_UE_SHIFT)) & GICT_GICT_ERR4CTLR_UE_MASK)

#define GICT_GICT_ERR4CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR4CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR4CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR4CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR4CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR4CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR4CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_CFI_SHIFT)) & GICT_GICT_ERR4CTLR_CFI_MASK)

#define GICT_GICT_ERR4CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR4CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR4CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR4CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR4CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR4CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR4CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_RP_SHIFT)) & GICT_GICT_ERR4CTLR_RP_MASK)

#define GICT_GICT_ERR4CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR4CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR4CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR4CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR4STATUS - GICT_ERR4STATUS */
/*! @{ */

#define GICT_GICT_ERR4STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR4STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR4STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_SERR_SHIFT)) & GICT_GICT_ERR4STATUS_SERR_MASK)

#define GICT_GICT_ERR4STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR4STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR4STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_IERR_SHIFT)) & GICT_GICT_ERR4STATUS_IERR_MASK)

#define GICT_GICT_ERR4STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR4STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR4STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR4STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR4STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR4STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR4STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_UET_SHIFT)) & GICT_GICT_ERR4STATUS_UET_MASK)

#define GICT_GICT_ERR4STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR4STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR4STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR4STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR4STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR4STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR4STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_CE_SHIFT)) & GICT_GICT_ERR4STATUS_CE_MASK)

#define GICT_GICT_ERR4STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR4STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR4STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_MV_SHIFT)) & GICT_GICT_ERR4STATUS_MV_MASK)

#define GICT_GICT_ERR4STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR4STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR4STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_OF_SHIFT)) & GICT_GICT_ERR4STATUS_OF_MASK)

#define GICT_GICT_ERR4STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR4STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR4STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_ER_SHIFT)) & GICT_GICT_ERR4STATUS_ER_MASK)

#define GICT_GICT_ERR4STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR4STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR4STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_UE_SHIFT)) & GICT_GICT_ERR4STATUS_UE_MASK)

#define GICT_GICT_ERR4STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR4STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR4STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_V_SHIFT)) & GICT_GICT_ERR4STATUS_V_MASK)

#define GICT_GICT_ERR4STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR4STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR4STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_AV_SHIFT)) & GICT_GICT_ERR4STATUS_AV_MASK)

#define GICT_GICT_ERR4STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR4STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR4STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR4STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR4MISC0 - GICT_ERR4MISC0 */
/*! @{ */

#define GICT_GICT_ERR4MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR4MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR4MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC0_Data_SHIFT)) & GICT_GICT_ERR4MISC0_Data_MASK)

#define GICT_GICT_ERR4MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR4MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR4MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC0_CNT_SHIFT)) & GICT_GICT_ERR4MISC0_CNT_MASK)

#define GICT_GICT_ERR4MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR4MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR4MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC0_OF_SHIFT)) & GICT_GICT_ERR4MISC0_OF_MASK)

#define GICT_GICT_ERR4MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR4MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR4MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC0_RE_SHIFT)) & GICT_GICT_ERR4MISC0_RE_MASK)

#define GICT_GICT_ERR4MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR4MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR4MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR4MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR4MISC1 - GICT_ERR4MISC1 */
/*! @{ */

#define GICT_GICT_ERR4MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR4MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR4MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR4MISC1_DATA_SHIFT)) & GICT_GICT_ERR4MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR5FR - GICT_ERR5FR */
/*! @{ */

#define GICT_GICT_ERR5FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR5FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR5FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_ED_SHIFT)) & GICT_GICT_ERR5FR_ED_MASK)

#define GICT_GICT_ERR5FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR5FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR5FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_DE_SHIFT)) & GICT_GICT_ERR5FR_DE_MASK)

#define GICT_GICT_ERR5FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR5FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR5FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_UI_SHIFT)) & GICT_GICT_ERR5FR_UI_MASK)

#define GICT_GICT_ERR5FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR5FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR5FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_FI_SHIFT)) & GICT_GICT_ERR5FR_FI_MASK)

#define GICT_GICT_ERR5FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR5FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR5FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_UE_SHIFT)) & GICT_GICT_ERR5FR_UE_MASK)

#define GICT_GICT_ERR5FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR5FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR5FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_CFI_SHIFT)) & GICT_GICT_ERR5FR_CFI_MASK)

#define GICT_GICT_ERR5FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR5FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR5FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_CEC_SHIFT)) & GICT_GICT_ERR5FR_CEC_MASK)

#define GICT_GICT_ERR5FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR5FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR5FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_RP_SHIFT)) & GICT_GICT_ERR5FR_RP_MASK)

#define GICT_GICT_ERR5FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR5FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR5FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5FR_RESERVED0_SHIFT)) & GICT_GICT_ERR5FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR5CTLR - GICT_ERR5CTLR */
/*! @{ */

#define GICT_GICT_ERR5CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR5CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR5CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR5CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR5CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR5CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR5CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_UI_SHIFT)) & GICT_GICT_ERR5CTLR_UI_MASK)

#define GICT_GICT_ERR5CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR5CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR5CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_FI_SHIFT)) & GICT_GICT_ERR5CTLR_FI_MASK)

#define GICT_GICT_ERR5CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR5CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR5CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_UE_SHIFT)) & GICT_GICT_ERR5CTLR_UE_MASK)

#define GICT_GICT_ERR5CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR5CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR5CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR5CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR5CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR5CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR5CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_CFI_SHIFT)) & GICT_GICT_ERR5CTLR_CFI_MASK)

#define GICT_GICT_ERR5CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR5CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR5CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR5CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR5CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR5CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR5CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_RP_SHIFT)) & GICT_GICT_ERR5CTLR_RP_MASK)

#define GICT_GICT_ERR5CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR5CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR5CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR5CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR5STATUS - GICT_ERR5STATUS */
/*! @{ */

#define GICT_GICT_ERR5STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR5STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR5STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_SERR_SHIFT)) & GICT_GICT_ERR5STATUS_SERR_MASK)

#define GICT_GICT_ERR5STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR5STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR5STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_IERR_SHIFT)) & GICT_GICT_ERR5STATUS_IERR_MASK)

#define GICT_GICT_ERR5STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR5STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR5STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR5STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR5STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR5STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR5STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_UET_SHIFT)) & GICT_GICT_ERR5STATUS_UET_MASK)

#define GICT_GICT_ERR5STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR5STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR5STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR5STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR5STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR5STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR5STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_CE_SHIFT)) & GICT_GICT_ERR5STATUS_CE_MASK)

#define GICT_GICT_ERR5STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR5STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR5STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_MV_SHIFT)) & GICT_GICT_ERR5STATUS_MV_MASK)

#define GICT_GICT_ERR5STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR5STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR5STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_OF_SHIFT)) & GICT_GICT_ERR5STATUS_OF_MASK)

#define GICT_GICT_ERR5STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR5STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR5STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_ER_SHIFT)) & GICT_GICT_ERR5STATUS_ER_MASK)

#define GICT_GICT_ERR5STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR5STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR5STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_UE_SHIFT)) & GICT_GICT_ERR5STATUS_UE_MASK)

#define GICT_GICT_ERR5STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR5STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR5STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_V_SHIFT)) & GICT_GICT_ERR5STATUS_V_MASK)

#define GICT_GICT_ERR5STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR5STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR5STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_AV_SHIFT)) & GICT_GICT_ERR5STATUS_AV_MASK)

#define GICT_GICT_ERR5STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR5STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR5STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR5STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR5MISC0 - GICT_ERR5MISC0 */
/*! @{ */

#define GICT_GICT_ERR5MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR5MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR5MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC0_Data_SHIFT)) & GICT_GICT_ERR5MISC0_Data_MASK)

#define GICT_GICT_ERR5MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR5MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR5MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC0_CNT_SHIFT)) & GICT_GICT_ERR5MISC0_CNT_MASK)

#define GICT_GICT_ERR5MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR5MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR5MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC0_OF_SHIFT)) & GICT_GICT_ERR5MISC0_OF_MASK)

#define GICT_GICT_ERR5MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR5MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR5MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC0_RE_SHIFT)) & GICT_GICT_ERR5MISC0_RE_MASK)

#define GICT_GICT_ERR5MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR5MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR5MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR5MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR5MISC1 - GICT_ERR5MISC1 */
/*! @{ */

#define GICT_GICT_ERR5MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR5MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR5MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR5MISC1_DATA_SHIFT)) & GICT_GICT_ERR5MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR6FR - GICT_ERR6FR */
/*! @{ */

#define GICT_GICT_ERR6FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR6FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR6FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_ED_SHIFT)) & GICT_GICT_ERR6FR_ED_MASK)

#define GICT_GICT_ERR6FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR6FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR6FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_DE_SHIFT)) & GICT_GICT_ERR6FR_DE_MASK)

#define GICT_GICT_ERR6FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR6FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR6FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_UI_SHIFT)) & GICT_GICT_ERR6FR_UI_MASK)

#define GICT_GICT_ERR6FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR6FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR6FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_FI_SHIFT)) & GICT_GICT_ERR6FR_FI_MASK)

#define GICT_GICT_ERR6FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR6FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR6FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_UE_SHIFT)) & GICT_GICT_ERR6FR_UE_MASK)

#define GICT_GICT_ERR6FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR6FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR6FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_CFI_SHIFT)) & GICT_GICT_ERR6FR_CFI_MASK)

#define GICT_GICT_ERR6FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR6FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR6FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_CEC_SHIFT)) & GICT_GICT_ERR6FR_CEC_MASK)

#define GICT_GICT_ERR6FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR6FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR6FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_RP_SHIFT)) & GICT_GICT_ERR6FR_RP_MASK)

#define GICT_GICT_ERR6FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR6FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR6FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6FR_RESERVED0_SHIFT)) & GICT_GICT_ERR6FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR6CTLR - GICT_ERR6CTLR */
/*! @{ */

#define GICT_GICT_ERR6CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR6CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR6CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR6CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR6CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR6CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR6CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_UI_SHIFT)) & GICT_GICT_ERR6CTLR_UI_MASK)

#define GICT_GICT_ERR6CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR6CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR6CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_FI_SHIFT)) & GICT_GICT_ERR6CTLR_FI_MASK)

#define GICT_GICT_ERR6CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR6CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR6CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_UE_SHIFT)) & GICT_GICT_ERR6CTLR_UE_MASK)

#define GICT_GICT_ERR6CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR6CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR6CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR6CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR6CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR6CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR6CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_CFI_SHIFT)) & GICT_GICT_ERR6CTLR_CFI_MASK)

#define GICT_GICT_ERR6CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR6CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR6CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR6CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR6CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR6CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR6CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_RP_SHIFT)) & GICT_GICT_ERR6CTLR_RP_MASK)

#define GICT_GICT_ERR6CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR6CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR6CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR6CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR6STATUS - GICT_ERR6STATUS */
/*! @{ */

#define GICT_GICT_ERR6STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR6STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR6STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_SERR_SHIFT)) & GICT_GICT_ERR6STATUS_SERR_MASK)

#define GICT_GICT_ERR6STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR6STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR6STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_IERR_SHIFT)) & GICT_GICT_ERR6STATUS_IERR_MASK)

#define GICT_GICT_ERR6STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR6STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR6STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR6STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR6STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR6STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR6STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_UET_SHIFT)) & GICT_GICT_ERR6STATUS_UET_MASK)

#define GICT_GICT_ERR6STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR6STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR6STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR6STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR6STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR6STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR6STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_CE_SHIFT)) & GICT_GICT_ERR6STATUS_CE_MASK)

#define GICT_GICT_ERR6STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR6STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR6STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_MV_SHIFT)) & GICT_GICT_ERR6STATUS_MV_MASK)

#define GICT_GICT_ERR6STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR6STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR6STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_OF_SHIFT)) & GICT_GICT_ERR6STATUS_OF_MASK)

#define GICT_GICT_ERR6STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR6STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR6STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_ER_SHIFT)) & GICT_GICT_ERR6STATUS_ER_MASK)

#define GICT_GICT_ERR6STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR6STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR6STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_UE_SHIFT)) & GICT_GICT_ERR6STATUS_UE_MASK)

#define GICT_GICT_ERR6STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR6STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR6STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_V_SHIFT)) & GICT_GICT_ERR6STATUS_V_MASK)

#define GICT_GICT_ERR6STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR6STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR6STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_AV_SHIFT)) & GICT_GICT_ERR6STATUS_AV_MASK)

#define GICT_GICT_ERR6STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR6STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR6STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR6STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR6MISC0 - GICT_ERR6MISC0 */
/*! @{ */

#define GICT_GICT_ERR6MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR6MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR6MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC0_Data_SHIFT)) & GICT_GICT_ERR6MISC0_Data_MASK)

#define GICT_GICT_ERR6MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR6MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR6MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC0_CNT_SHIFT)) & GICT_GICT_ERR6MISC0_CNT_MASK)

#define GICT_GICT_ERR6MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR6MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR6MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC0_OF_SHIFT)) & GICT_GICT_ERR6MISC0_OF_MASK)

#define GICT_GICT_ERR6MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR6MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR6MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC0_RE_SHIFT)) & GICT_GICT_ERR6MISC0_RE_MASK)

#define GICT_GICT_ERR6MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR6MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR6MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR6MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR6MISC1 - GICT_ERR6MISC1 */
/*! @{ */

#define GICT_GICT_ERR6MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR6MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR6MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR6MISC1_DATA_SHIFT)) & GICT_GICT_ERR6MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR7FR - GICT_ERR7FR */
/*! @{ */

#define GICT_GICT_ERR7FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR7FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR7FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_ED_SHIFT)) & GICT_GICT_ERR7FR_ED_MASK)

#define GICT_GICT_ERR7FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR7FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR7FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_DE_SHIFT)) & GICT_GICT_ERR7FR_DE_MASK)

#define GICT_GICT_ERR7FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR7FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR7FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_UI_SHIFT)) & GICT_GICT_ERR7FR_UI_MASK)

#define GICT_GICT_ERR7FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR7FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR7FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_FI_SHIFT)) & GICT_GICT_ERR7FR_FI_MASK)

#define GICT_GICT_ERR7FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR7FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR7FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_UE_SHIFT)) & GICT_GICT_ERR7FR_UE_MASK)

#define GICT_GICT_ERR7FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR7FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR7FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_CFI_SHIFT)) & GICT_GICT_ERR7FR_CFI_MASK)

#define GICT_GICT_ERR7FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR7FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR7FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_CEC_SHIFT)) & GICT_GICT_ERR7FR_CEC_MASK)

#define GICT_GICT_ERR7FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR7FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR7FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_RP_SHIFT)) & GICT_GICT_ERR7FR_RP_MASK)

#define GICT_GICT_ERR7FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR7FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR7FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7FR_RESERVED0_SHIFT)) & GICT_GICT_ERR7FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR7CTLR - GICT_ERR7CTLR */
/*! @{ */

#define GICT_GICT_ERR7CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR7CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR7CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR7CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR7CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR7CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR7CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_UI_SHIFT)) & GICT_GICT_ERR7CTLR_UI_MASK)

#define GICT_GICT_ERR7CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR7CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR7CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_FI_SHIFT)) & GICT_GICT_ERR7CTLR_FI_MASK)

#define GICT_GICT_ERR7CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR7CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR7CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_UE_SHIFT)) & GICT_GICT_ERR7CTLR_UE_MASK)

#define GICT_GICT_ERR7CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR7CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR7CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR7CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR7CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR7CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR7CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_CFI_SHIFT)) & GICT_GICT_ERR7CTLR_CFI_MASK)

#define GICT_GICT_ERR7CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR7CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR7CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR7CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR7CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR7CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR7CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_RP_SHIFT)) & GICT_GICT_ERR7CTLR_RP_MASK)

#define GICT_GICT_ERR7CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR7CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR7CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR7CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR7STATUS - GICT_ERR7STATUS */
/*! @{ */

#define GICT_GICT_ERR7STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR7STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR7STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_SERR_SHIFT)) & GICT_GICT_ERR7STATUS_SERR_MASK)

#define GICT_GICT_ERR7STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR7STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR7STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_IERR_SHIFT)) & GICT_GICT_ERR7STATUS_IERR_MASK)

#define GICT_GICT_ERR7STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR7STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR7STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR7STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR7STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR7STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR7STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_UET_SHIFT)) & GICT_GICT_ERR7STATUS_UET_MASK)

#define GICT_GICT_ERR7STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR7STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR7STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR7STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR7STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR7STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR7STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_CE_SHIFT)) & GICT_GICT_ERR7STATUS_CE_MASK)

#define GICT_GICT_ERR7STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR7STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR7STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_MV_SHIFT)) & GICT_GICT_ERR7STATUS_MV_MASK)

#define GICT_GICT_ERR7STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR7STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR7STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_OF_SHIFT)) & GICT_GICT_ERR7STATUS_OF_MASK)

#define GICT_GICT_ERR7STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR7STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR7STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_ER_SHIFT)) & GICT_GICT_ERR7STATUS_ER_MASK)

#define GICT_GICT_ERR7STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR7STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR7STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_UE_SHIFT)) & GICT_GICT_ERR7STATUS_UE_MASK)

#define GICT_GICT_ERR7STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR7STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR7STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_V_SHIFT)) & GICT_GICT_ERR7STATUS_V_MASK)

#define GICT_GICT_ERR7STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR7STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR7STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_AV_SHIFT)) & GICT_GICT_ERR7STATUS_AV_MASK)

#define GICT_GICT_ERR7STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR7STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR7STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR7STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR7MISC0 - GICT_ERR7MISC0 */
/*! @{ */

#define GICT_GICT_ERR7MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR7MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR7MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC0_Data_SHIFT)) & GICT_GICT_ERR7MISC0_Data_MASK)

#define GICT_GICT_ERR7MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR7MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR7MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC0_CNT_SHIFT)) & GICT_GICT_ERR7MISC0_CNT_MASK)

#define GICT_GICT_ERR7MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR7MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR7MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC0_OF_SHIFT)) & GICT_GICT_ERR7MISC0_OF_MASK)

#define GICT_GICT_ERR7MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR7MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR7MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC0_RE_SHIFT)) & GICT_GICT_ERR7MISC0_RE_MASK)

#define GICT_GICT_ERR7MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR7MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR7MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR7MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR7MISC1 - GICT_ERR7MISC1 */
/*! @{ */

#define GICT_GICT_ERR7MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR7MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR7MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR7MISC1_DATA_SHIFT)) & GICT_GICT_ERR7MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERR8FR - GICT_ERR8FR */
/*! @{ */

#define GICT_GICT_ERR8FR_ED_MASK                 (0x3U)
#define GICT_GICT_ERR8FR_ED_SHIFT                (0U)
/*! ED - ED */
#define GICT_GICT_ERR8FR_ED(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_ED_SHIFT)) & GICT_GICT_ERR8FR_ED_MASK)

#define GICT_GICT_ERR8FR_DE_MASK                 (0xCU)
#define GICT_GICT_ERR8FR_DE_SHIFT                (2U)
/*! DE - DE */
#define GICT_GICT_ERR8FR_DE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_DE_SHIFT)) & GICT_GICT_ERR8FR_DE_MASK)

#define GICT_GICT_ERR8FR_UI_MASK                 (0x30U)
#define GICT_GICT_ERR8FR_UI_SHIFT                (4U)
/*! UI - UI */
#define GICT_GICT_ERR8FR_UI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_UI_SHIFT)) & GICT_GICT_ERR8FR_UI_MASK)

#define GICT_GICT_ERR8FR_FI_MASK                 (0xC0U)
#define GICT_GICT_ERR8FR_FI_SHIFT                (6U)
/*! FI - FI */
#define GICT_GICT_ERR8FR_FI(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_FI_SHIFT)) & GICT_GICT_ERR8FR_FI_MASK)

#define GICT_GICT_ERR8FR_UE_MASK                 (0x300U)
#define GICT_GICT_ERR8FR_UE_SHIFT                (8U)
/*! UE - UE */
#define GICT_GICT_ERR8FR_UE(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_UE_SHIFT)) & GICT_GICT_ERR8FR_UE_MASK)

#define GICT_GICT_ERR8FR_CFI_MASK                (0xC00U)
#define GICT_GICT_ERR8FR_CFI_SHIFT               (10U)
/*! CFI - CFI */
#define GICT_GICT_ERR8FR_CFI(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_CFI_SHIFT)) & GICT_GICT_ERR8FR_CFI_MASK)

#define GICT_GICT_ERR8FR_CEC_MASK                (0x7000U)
#define GICT_GICT_ERR8FR_CEC_SHIFT               (12U)
/*! CEC - CEC */
#define GICT_GICT_ERR8FR_CEC(x)                  (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_CEC_SHIFT)) & GICT_GICT_ERR8FR_CEC_MASK)

#define GICT_GICT_ERR8FR_RP_MASK                 (0x8000U)
#define GICT_GICT_ERR8FR_RP_SHIFT                (15U)
/*! RP - RP */
#define GICT_GICT_ERR8FR_RP(x)                   (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_RP_SHIFT)) & GICT_GICT_ERR8FR_RP_MASK)

#define GICT_GICT_ERR8FR_RESERVED0_MASK          (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR8FR_RESERVED0_SHIFT         (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR8FR_RESERVED0(x)            (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8FR_RESERVED0_SHIFT)) & GICT_GICT_ERR8FR_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR8CTLR - GICT_ERR8CTLR */
/*! @{ */

#define GICT_GICT_ERR8CTLR_RESERVED0_MASK        (0x3U)
#define GICT_GICT_ERR8CTLR_RESERVED0_SHIFT       (0U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR8CTLR_RESERVED0(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_RESERVED0_SHIFT)) & GICT_GICT_ERR8CTLR_RESERVED0_MASK)

#define GICT_GICT_ERR8CTLR_UI_MASK               (0x4U)
#define GICT_GICT_ERR8CTLR_UI_SHIFT              (2U)
/*! UI - UI */
#define GICT_GICT_ERR8CTLR_UI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_UI_SHIFT)) & GICT_GICT_ERR8CTLR_UI_MASK)

#define GICT_GICT_ERR8CTLR_FI_MASK               (0x8U)
#define GICT_GICT_ERR8CTLR_FI_SHIFT              (3U)
/*! FI - FI */
#define GICT_GICT_ERR8CTLR_FI(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_FI_SHIFT)) & GICT_GICT_ERR8CTLR_FI_MASK)

#define GICT_GICT_ERR8CTLR_UE_MASK               (0x10U)
#define GICT_GICT_ERR8CTLR_UE_SHIFT              (4U)
/*! UE - UE */
#define GICT_GICT_ERR8CTLR_UE(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_UE_SHIFT)) & GICT_GICT_ERR8CTLR_UE_MASK)

#define GICT_GICT_ERR8CTLR_RESERVED1_MASK        (0xE0U)
#define GICT_GICT_ERR8CTLR_RESERVED1_SHIFT       (5U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR8CTLR_RESERVED1(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_RESERVED1_SHIFT)) & GICT_GICT_ERR8CTLR_RESERVED1_MASK)

#define GICT_GICT_ERR8CTLR_CFI_MASK              (0x100U)
#define GICT_GICT_ERR8CTLR_CFI_SHIFT             (8U)
/*! CFI - CFI */
#define GICT_GICT_ERR8CTLR_CFI(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_CFI_SHIFT)) & GICT_GICT_ERR8CTLR_CFI_MASK)

#define GICT_GICT_ERR8CTLR_RESERVED2_MASK        (0x7E00U)
#define GICT_GICT_ERR8CTLR_RESERVED2_SHIFT       (9U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR8CTLR_RESERVED2(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_RESERVED2_SHIFT)) & GICT_GICT_ERR8CTLR_RESERVED2_MASK)

#define GICT_GICT_ERR8CTLR_RP_MASK               (0x8000U)
#define GICT_GICT_ERR8CTLR_RP_SHIFT              (15U)
/*! RP - RP */
#define GICT_GICT_ERR8CTLR_RP(x)                 (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_RP_SHIFT)) & GICT_GICT_ERR8CTLR_RP_MASK)

#define GICT_GICT_ERR8CTLR_RESERVED3_MASK        (0xFFFFFFFFFFFF0000U)
#define GICT_GICT_ERR8CTLR_RESERVED3_SHIFT       (16U)
/*! RESERVED3 - RESERVED3 */
#define GICT_GICT_ERR8CTLR_RESERVED3(x)          (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8CTLR_RESERVED3_SHIFT)) & GICT_GICT_ERR8CTLR_RESERVED3_MASK)
/*! @} */

/*! @name GICT_ERR8STATUS - GICT_ERR8STATUS */
/*! @{ */

#define GICT_GICT_ERR8STATUS_SERR_MASK           (0xFFU)
#define GICT_GICT_ERR8STATUS_SERR_SHIFT          (0U)
/*! SERR - SERR */
#define GICT_GICT_ERR8STATUS_SERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_SERR_SHIFT)) & GICT_GICT_ERR8STATUS_SERR_MASK)

#define GICT_GICT_ERR8STATUS_IERR_MASK           (0xFF00U)
#define GICT_GICT_ERR8STATUS_IERR_SHIFT          (8U)
/*! IERR - IERR */
#define GICT_GICT_ERR8STATUS_IERR(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_IERR_SHIFT)) & GICT_GICT_ERR8STATUS_IERR_MASK)

#define GICT_GICT_ERR8STATUS_RESERVED0_MASK      (0xF0000U)
#define GICT_GICT_ERR8STATUS_RESERVED0_SHIFT     (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR8STATUS_RESERVED0(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_RESERVED0_SHIFT)) & GICT_GICT_ERR8STATUS_RESERVED0_MASK)

#define GICT_GICT_ERR8STATUS_UET_MASK            (0x300000U)
#define GICT_GICT_ERR8STATUS_UET_SHIFT           (20U)
/*! UET - UET */
#define GICT_GICT_ERR8STATUS_UET(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_UET_SHIFT)) & GICT_GICT_ERR8STATUS_UET_MASK)

#define GICT_GICT_ERR8STATUS_RESERVED1_MASK      (0xC00000U)
#define GICT_GICT_ERR8STATUS_RESERVED1_SHIFT     (22U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_ERR8STATUS_RESERVED1(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_RESERVED1_SHIFT)) & GICT_GICT_ERR8STATUS_RESERVED1_MASK)

#define GICT_GICT_ERR8STATUS_CE_MASK             (0x3000000U)
#define GICT_GICT_ERR8STATUS_CE_SHIFT            (24U)
/*! CE - CE */
#define GICT_GICT_ERR8STATUS_CE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_CE_SHIFT)) & GICT_GICT_ERR8STATUS_CE_MASK)

#define GICT_GICT_ERR8STATUS_MV_MASK             (0x4000000U)
#define GICT_GICT_ERR8STATUS_MV_SHIFT            (26U)
/*! MV - MV */
#define GICT_GICT_ERR8STATUS_MV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_MV_SHIFT)) & GICT_GICT_ERR8STATUS_MV_MASK)

#define GICT_GICT_ERR8STATUS_OF_MASK             (0x8000000U)
#define GICT_GICT_ERR8STATUS_OF_SHIFT            (27U)
/*! OF - OF */
#define GICT_GICT_ERR8STATUS_OF(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_OF_SHIFT)) & GICT_GICT_ERR8STATUS_OF_MASK)

#define GICT_GICT_ERR8STATUS_ER_MASK             (0x10000000U)
#define GICT_GICT_ERR8STATUS_ER_SHIFT            (28U)
/*! ER - ER */
#define GICT_GICT_ERR8STATUS_ER(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_ER_SHIFT)) & GICT_GICT_ERR8STATUS_ER_MASK)

#define GICT_GICT_ERR8STATUS_UE_MASK             (0x20000000U)
#define GICT_GICT_ERR8STATUS_UE_SHIFT            (29U)
/*! UE - UE */
#define GICT_GICT_ERR8STATUS_UE(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_UE_SHIFT)) & GICT_GICT_ERR8STATUS_UE_MASK)

#define GICT_GICT_ERR8STATUS_V_MASK              (0x40000000U)
#define GICT_GICT_ERR8STATUS_V_SHIFT             (30U)
/*! V - V */
#define GICT_GICT_ERR8STATUS_V(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_V_SHIFT)) & GICT_GICT_ERR8STATUS_V_MASK)

#define GICT_GICT_ERR8STATUS_AV_MASK             (0x80000000U)
#define GICT_GICT_ERR8STATUS_AV_SHIFT            (31U)
/*! AV - AV */
#define GICT_GICT_ERR8STATUS_AV(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_AV_SHIFT)) & GICT_GICT_ERR8STATUS_AV_MASK)

#define GICT_GICT_ERR8STATUS_RESERVED2_MASK      (0xFFFFFFFF00000000U)
#define GICT_GICT_ERR8STATUS_RESERVED2_SHIFT     (32U)
/*! RESERVED2 - RESERVED2 */
#define GICT_GICT_ERR8STATUS_RESERVED2(x)        (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8STATUS_RESERVED2_SHIFT)) & GICT_GICT_ERR8STATUS_RESERVED2_MASK)
/*! @} */

/*! @name GICT_ERR8MISC0 - GICT_ERR8MISC0 */
/*! @{ */

#define GICT_GICT_ERR8MISC0_Data_MASK            (0xFFFFFFFFU)
#define GICT_GICT_ERR8MISC0_Data_SHIFT           (0U)
/*! Data - Data */
#define GICT_GICT_ERR8MISC0_Data(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC0_Data_SHIFT)) & GICT_GICT_ERR8MISC0_Data_MASK)

#define GICT_GICT_ERR8MISC0_CNT_MASK             (0xFF00000000U)
#define GICT_GICT_ERR8MISC0_CNT_SHIFT            (32U)
/*! CNT - CNT */
#define GICT_GICT_ERR8MISC0_CNT(x)               (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC0_CNT_SHIFT)) & GICT_GICT_ERR8MISC0_CNT_MASK)

#define GICT_GICT_ERR8MISC0_OF_MASK              (0x10000000000U)
#define GICT_GICT_ERR8MISC0_OF_SHIFT             (40U)
/*! OF - OF */
#define GICT_GICT_ERR8MISC0_OF(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC0_OF_SHIFT)) & GICT_GICT_ERR8MISC0_OF_MASK)

#define GICT_GICT_ERR8MISC0_RE_MASK              (0x20000000000U)
#define GICT_GICT_ERR8MISC0_RE_SHIFT             (41U)
/*! RE - RE */
#define GICT_GICT_ERR8MISC0_RE(x)                (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC0_RE_SHIFT)) & GICT_GICT_ERR8MISC0_RE_MASK)

#define GICT_GICT_ERR8MISC0_RESERVED0_MASK       (0xFFFFFC0000000000U)
#define GICT_GICT_ERR8MISC0_RESERVED0_SHIFT      (42U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERR8MISC0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC0_RESERVED0_SHIFT)) & GICT_GICT_ERR8MISC0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERR8MISC1 - GICT_ERR8MISC1 */
/*! @{ */

#define GICT_GICT_ERR8MISC1_DATA_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERR8MISC1_DATA_SHIFT           (0U)
/*! DATA - DATA */
#define GICT_GICT_ERR8MISC1_DATA(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERR8MISC1_DATA_SHIFT)) & GICT_GICT_ERR8MISC1_DATA_MASK)
/*! @} */

/*! @name GICT_ERRGSR0 - GICT_ERRGSR0 */
/*! @{ */

#define GICT_GICT_ERRGSR0_Status_MASK            (0xFFFFFFFFFFFFFFFFU)
#define GICT_GICT_ERRGSR0_Status_SHIFT           (0U)
/*! Status - Status */
#define GICT_GICT_ERRGSR0_Status(x)              (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERRGSR0_Status_SHIFT)) & GICT_GICT_ERRGSR0_Status_MASK)
/*! @} */

/*! @name GICT_ERRIRQCR0 - GICT_ERRIRQCR0 */
/*! @{ */

#define GICT_GICT_ERRIRQCR0_SPIID_MASK           (0x3FFU)
#define GICT_GICT_ERRIRQCR0_SPIID_SHIFT          (0U)
/*! SPIID - SPIID */
#define GICT_GICT_ERRIRQCR0_SPIID(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERRIRQCR0_SPIID_SHIFT)) & GICT_GICT_ERRIRQCR0_SPIID_MASK)

#define GICT_GICT_ERRIRQCR0_RESERVED0_MASK       (0xFFFFFFFFFFFFFC00U)
#define GICT_GICT_ERRIRQCR0_RESERVED0_SHIFT      (10U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERRIRQCR0_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERRIRQCR0_RESERVED0_SHIFT)) & GICT_GICT_ERRIRQCR0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_ERRIRQCR1 - GICT_ERRIRQCR1 */
/*! @{ */

#define GICT_GICT_ERRIRQCR1_SPIID_MASK           (0x3FFU)
#define GICT_GICT_ERRIRQCR1_SPIID_SHIFT          (0U)
/*! SPIID - SPIID */
#define GICT_GICT_ERRIRQCR1_SPIID(x)             (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERRIRQCR1_SPIID_SHIFT)) & GICT_GICT_ERRIRQCR1_SPIID_MASK)

#define GICT_GICT_ERRIRQCR1_RESERVED0_MASK       (0xFFFFFFFFFFFFFC00U)
#define GICT_GICT_ERRIRQCR1_RESERVED0_SHIFT      (10U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_ERRIRQCR1_RESERVED0(x)         (((uint64_t)(((uint64_t)(x)) << GICT_GICT_ERRIRQCR1_RESERVED0_SHIFT)) & GICT_GICT_ERRIRQCR1_RESERVED0_MASK)
/*! @} */

/*! @name GICT_DEVARCH - GICT_DEVARCH */
/*! @{ */

#define GICT_GICT_DEVARCH_ARCHID_MASK            (0xFFFU)
#define GICT_GICT_DEVARCH_ARCHID_SHIFT           (0U)
/*! ARCHID - ARCHID */
#define GICT_GICT_DEVARCH_ARCHID(x)              (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVARCH_ARCHID_SHIFT)) & GICT_GICT_DEVARCH_ARCHID_MASK)

#define GICT_GICT_DEVARCH_RESERVED0_MASK         (0xF000U)
#define GICT_GICT_DEVARCH_RESERVED0_SHIFT        (12U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_DEVARCH_RESERVED0(x)           (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVARCH_RESERVED0_SHIFT)) & GICT_GICT_DEVARCH_RESERVED0_MASK)

#define GICT_GICT_DEVARCH_REVISION_MASK          (0xF0000U)
#define GICT_GICT_DEVARCH_REVISION_SHIFT         (16U)
/*! REVISION - REVISION */
#define GICT_GICT_DEVARCH_REVISION(x)            (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVARCH_REVISION_SHIFT)) & GICT_GICT_DEVARCH_REVISION_MASK)

#define GICT_GICT_DEVARCH_PRESENT_MASK           (0x100000U)
#define GICT_GICT_DEVARCH_PRESENT_SHIFT          (20U)
/*! PRESENT - PRESENT */
#define GICT_GICT_DEVARCH_PRESENT(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVARCH_PRESENT_SHIFT)) & GICT_GICT_DEVARCH_PRESENT_MASK)

#define GICT_GICT_DEVARCH_ARCHITECT_MASK         (0xFFE00000U)
#define GICT_GICT_DEVARCH_ARCHITECT_SHIFT        (21U)
/*! ARCHITECT - ARCHITECT */
#define GICT_GICT_DEVARCH_ARCHITECT(x)           (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVARCH_ARCHITECT_SHIFT)) & GICT_GICT_DEVARCH_ARCHITECT_MASK)
/*! @} */

/*! @name GICT_DEVID - GICT_DEVID */
/*! @{ */

#define GICT_GICT_DEVID_NumRecords_MASK          (0xFFFFU)
#define GICT_GICT_DEVID_NumRecords_SHIFT         (0U)
/*! NumRecords - NumRecords */
#define GICT_GICT_DEVID_NumRecords(x)            (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVID_NumRecords_SHIFT)) & GICT_GICT_DEVID_NumRecords_MASK)

#define GICT_GICT_DEVID_RESERVED0_MASK           (0xFFFF0000U)
#define GICT_GICT_DEVID_RESERVED0_SHIFT          (16U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_DEVID_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_DEVID_RESERVED0_SHIFT)) & GICT_GICT_DEVID_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR4 - GICT_PIDR4 */
/*! @{ */

#define GICT_GICT_PIDR4_DES_2_MASK               (0xFU)
#define GICT_GICT_PIDR4_DES_2_SHIFT              (0U)
/*! DES_2 - DES_2 */
#define GICT_GICT_PIDR4_DES_2(x)                 (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR4_DES_2_SHIFT)) & GICT_GICT_PIDR4_DES_2_MASK)

#define GICT_GICT_PIDR4_SIZE_MASK                (0xF0U)
#define GICT_GICT_PIDR4_SIZE_SHIFT               (4U)
/*! SIZE - SIZE */
#define GICT_GICT_PIDR4_SIZE(x)                  (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR4_SIZE_SHIFT)) & GICT_GICT_PIDR4_SIZE_MASK)

#define GICT_GICT_PIDR4_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR4_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR4_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR4_RESERVED0_SHIFT)) & GICT_GICT_PIDR4_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR5 - GICT_PIDR5 */
/*! @{ */

#define GICT_GICT_PIDR5_RESERVED_MASK            (0xFFU)
#define GICT_GICT_PIDR5_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICT_GICT_PIDR5_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR5_RESERVED_SHIFT)) & GICT_GICT_PIDR5_RESERVED_MASK)

#define GICT_GICT_PIDR5_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR5_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR5_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR5_RESERVED0_SHIFT)) & GICT_GICT_PIDR5_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR6 - GICT_PIDR6 */
/*! @{ */

#define GICT_GICT_PIDR6_RESERVED_MASK            (0xFFU)
#define GICT_GICT_PIDR6_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICT_GICT_PIDR6_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR6_RESERVED_SHIFT)) & GICT_GICT_PIDR6_RESERVED_MASK)

#define GICT_GICT_PIDR6_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR6_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR6_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR6_RESERVED0_SHIFT)) & GICT_GICT_PIDR6_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR7 - GICT_PIDR7 */
/*! @{ */

#define GICT_GICT_PIDR7_RESERVED_MASK            (0xFFU)
#define GICT_GICT_PIDR7_RESERVED_SHIFT           (0U)
/*! RESERVED - RESERVED */
#define GICT_GICT_PIDR7_RESERVED(x)              (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR7_RESERVED_SHIFT)) & GICT_GICT_PIDR7_RESERVED_MASK)

#define GICT_GICT_PIDR7_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR7_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR7_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR7_RESERVED0_SHIFT)) & GICT_GICT_PIDR7_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR0 - GICT_PIDR0 */
/*! @{ */

#define GICT_GICT_PIDR0_PART_0_MASK              (0xFFU)
#define GICT_GICT_PIDR0_PART_0_SHIFT             (0U)
/*! PART_0 - PART_0 */
#define GICT_GICT_PIDR0_PART_0(x)                (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR0_PART_0_SHIFT)) & GICT_GICT_PIDR0_PART_0_MASK)

#define GICT_GICT_PIDR0_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR0_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR0_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR0_RESERVED0_SHIFT)) & GICT_GICT_PIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR1 - GICT_PIDR1 */
/*! @{ */

#define GICT_GICT_PIDR1_PART_1_MASK              (0xFU)
#define GICT_GICT_PIDR1_PART_1_SHIFT             (0U)
/*! PART_1 - PART_1 */
#define GICT_GICT_PIDR1_PART_1(x)                (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR1_PART_1_SHIFT)) & GICT_GICT_PIDR1_PART_1_MASK)

#define GICT_GICT_PIDR1_DES_0_MASK               (0xF0U)
#define GICT_GICT_PIDR1_DES_0_SHIFT              (4U)
/*! DES_0 - DES_0 */
#define GICT_GICT_PIDR1_DES_0(x)                 (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR1_DES_0_SHIFT)) & GICT_GICT_PIDR1_DES_0_MASK)

#define GICT_GICT_PIDR1_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR1_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR1_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR1_RESERVED0_SHIFT)) & GICT_GICT_PIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR2 - GICT_PIDR2 */
/*! @{ */

#define GICT_GICT_PIDR2_DES_1_MASK               (0x7U)
#define GICT_GICT_PIDR2_DES_1_SHIFT              (0U)
/*! DES_1 - DES_1 */
#define GICT_GICT_PIDR2_DES_1(x)                 (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR2_DES_1_SHIFT)) & GICT_GICT_PIDR2_DES_1_MASK)

#define GICT_GICT_PIDR2_JEDEC_MASK               (0x8U)
#define GICT_GICT_PIDR2_JEDEC_SHIFT              (3U)
/*! JEDEC - JEDEC */
#define GICT_GICT_PIDR2_JEDEC(x)                 (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR2_JEDEC_SHIFT)) & GICT_GICT_PIDR2_JEDEC_MASK)

#define GICT_GICT_PIDR2_REVISION_MASK            (0xF0U)
#define GICT_GICT_PIDR2_REVISION_SHIFT           (4U)
/*! REVISION - REVISION */
#define GICT_GICT_PIDR2_REVISION(x)              (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR2_REVISION_SHIFT)) & GICT_GICT_PIDR2_REVISION_MASK)

#define GICT_GICT_PIDR2_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR2_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR2_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR2_RESERVED0_SHIFT)) & GICT_GICT_PIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICT_PIDR3 - GICT_PIDR3 */
/*! @{ */

#define GICT_GICT_PIDR3_CMOD_MASK                (0x7U)
#define GICT_GICT_PIDR3_CMOD_SHIFT               (0U)
/*! CMOD - CMOD */
#define GICT_GICT_PIDR3_CMOD(x)                  (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR3_CMOD_SHIFT)) & GICT_GICT_PIDR3_CMOD_MASK)

#define GICT_GICT_PIDR3_RESERVED0_MASK           (0x8U)
#define GICT_GICT_PIDR3_RESERVED0_SHIFT          (3U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_PIDR3_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR3_RESERVED0_SHIFT)) & GICT_GICT_PIDR3_RESERVED0_MASK)

#define GICT_GICT_PIDR3_REVAND_MASK              (0xF0U)
#define GICT_GICT_PIDR3_REVAND_SHIFT             (4U)
/*! REVAND - REVAND */
#define GICT_GICT_PIDR3_REVAND(x)                (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR3_REVAND_SHIFT)) & GICT_GICT_PIDR3_REVAND_MASK)

#define GICT_GICT_PIDR3_RESERVED1_MASK           (0xFFFFFF00U)
#define GICT_GICT_PIDR3_RESERVED1_SHIFT          (8U)
/*! RESERVED1 - RESERVED1 */
#define GICT_GICT_PIDR3_RESERVED1(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_PIDR3_RESERVED1_SHIFT)) & GICT_GICT_PIDR3_RESERVED1_MASK)
/*! @} */

/*! @name GICT_CIDR0 - GICT_CIDR0 */
/*! @{ */

#define GICT_GICT_CIDR0_PRMBL_0_MASK             (0xFFU)
#define GICT_GICT_CIDR0_PRMBL_0_SHIFT            (0U)
/*! PRMBL_0 - PRMBL_0 */
#define GICT_GICT_CIDR0_PRMBL_0(x)               (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR0_PRMBL_0_SHIFT)) & GICT_GICT_CIDR0_PRMBL_0_MASK)

#define GICT_GICT_CIDR0_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_CIDR0_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_CIDR0_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR0_RESERVED0_SHIFT)) & GICT_GICT_CIDR0_RESERVED0_MASK)
/*! @} */

/*! @name GICT_CIDR1 - GICT_CIDR1 */
/*! @{ */

#define GICT_GICT_CIDR1_PRMBL_1_MASK             (0xFU)
#define GICT_GICT_CIDR1_PRMBL_1_SHIFT            (0U)
/*! PRMBL_1 - PRMBL_1 */
#define GICT_GICT_CIDR1_PRMBL_1(x)               (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR1_PRMBL_1_SHIFT)) & GICT_GICT_CIDR1_PRMBL_1_MASK)

#define GICT_GICT_CIDR1_CLASS_MASK               (0xF0U)
#define GICT_GICT_CIDR1_CLASS_SHIFT              (4U)
/*! CLASS - CLASS */
#define GICT_GICT_CIDR1_CLASS(x)                 (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR1_CLASS_SHIFT)) & GICT_GICT_CIDR1_CLASS_MASK)

#define GICT_GICT_CIDR1_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_CIDR1_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_CIDR1_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR1_RESERVED0_SHIFT)) & GICT_GICT_CIDR1_RESERVED0_MASK)
/*! @} */

/*! @name GICT_CIDR2 - GICT_CIDR2 */
/*! @{ */

#define GICT_GICT_CIDR2_PRMBL_2_MASK             (0xFFU)
#define GICT_GICT_CIDR2_PRMBL_2_SHIFT            (0U)
/*! PRMBL_2 - PRMBL_2 */
#define GICT_GICT_CIDR2_PRMBL_2(x)               (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR2_PRMBL_2_SHIFT)) & GICT_GICT_CIDR2_PRMBL_2_MASK)

#define GICT_GICT_CIDR2_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_CIDR2_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_CIDR2_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR2_RESERVED0_SHIFT)) & GICT_GICT_CIDR2_RESERVED0_MASK)
/*! @} */

/*! @name GICT_CIDR3 - GICT_CIDR3 */
/*! @{ */

#define GICT_GICT_CIDR3_PRMBL_3_MASK             (0xFFU)
#define GICT_GICT_CIDR3_PRMBL_3_SHIFT            (0U)
/*! PRMBL_3 - PRMBL_3 */
#define GICT_GICT_CIDR3_PRMBL_3(x)               (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR3_PRMBL_3_SHIFT)) & GICT_GICT_CIDR3_PRMBL_3_MASK)

#define GICT_GICT_CIDR3_RESERVED0_MASK           (0xFFFFFF00U)
#define GICT_GICT_CIDR3_RESERVED0_SHIFT          (8U)
/*! RESERVED0 - RESERVED0 */
#define GICT_GICT_CIDR3_RESERVED0(x)             (((uint32_t)(((uint32_t)(x)) << GICT_GICT_CIDR3_RESERVED0_SHIFT)) & GICT_GICT_CIDR3_RESERVED0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GICT_Register_Masks */


/*!
 * @}
 */ /* end of group GICT_Peripheral_Access_Layer */


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


#endif  /* PERI_GICT_H_ */
