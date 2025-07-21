/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSCCA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OSCCA.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSCCA
 *
 * CMSIS Peripheral Access Layer for OSCCA
 */

#if !defined(PERI_OSCCA_H_)
#define PERI_OSCCA_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OSCCA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSCCA_Peripheral_Access_Layer OSCCA Peripheral Access Layer
 * @{
 */

/** OSCCA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t SAFO_SGI_DATIN0A;                  /**< Input Data register 0 lower-bank low, offset: 0x200 */
  __IO uint32_t SAFO_SGI_DATIN0B;                  /**< Input Data register 0 lower-bank high, offset: 0x204 */
  __IO uint32_t SAFO_SGI_DATIN0C;                  /**< Input Data register 0 upper-bank low, offset: 0x208 */
  __IO uint32_t SAFO_SGI_DATIN0D;                  /**< Input Data register 0 upper-bank high, offset: 0x20C */
  __IO uint32_t SAFO_SGI_DATIN1A;                  /**< Input Data register 1 lower-bank low, offset: 0x210 */
  __IO uint32_t SAFO_SGI_DATIN1B;                  /**< Input Data register 1 lower-bank high, offset: 0x214 */
  __IO uint32_t SAFO_SGI_DATIN1C;                  /**< Input Data register 1 upper-bank low, offset: 0x218 */
  __IO uint32_t SAFO_SGI_DATIN1D;                  /**< Input Data register 1 upper-bank high, offset: 0x21C */
       uint8_t RESERVED_1[32];
  __IO uint32_t SAFO_SGI_KEY0A;                    /**< Input Key register 0 lower-bank low, offset: 0x240 */
  __IO uint32_t SAFO_SGI_KEY0B;                    /**< Input Key register 0 lower-bank high, offset: 0x244 */
  __IO uint32_t SAFO_SGI_KEY0C;                    /**< Input Key register 0 upper-bank low, offset: 0x248 */
  __IO uint32_t SAFO_SGI_KEY0D;                    /**< Input Key register 0 upper-bank high, offset: 0x24C */
  __IO uint32_t SAFO_SGI_KEY1A;                    /**< Input Key register 1 lower-bank low, offset: 0x250 */
  __IO uint32_t SAFO_SGI_KEY1B;                    /**< Input Key register 1 lower-bank high, offset: 0x254 */
  __IO uint32_t SAFO_SGI_KEY1C;                    /**< Input Key register 1 upper-bank low, offset: 0x258 */
  __IO uint32_t SAFO_SGI_KEY1D;                    /**< Input Key register 1 upper-bank high, offset: 0x25C */
       uint8_t RESERVED_2[96];
  __I  uint32_t SAFO_SGI_DATOUTA;                  /**< Output Data register lower-bank low, offset: 0x2C0 */
  __I  uint32_t SAFO_SGI_DATOUTB;                  /**< Ouput Data register lower-bank high, offset: 0x2C4 */
  __I  uint32_t SAFO_SGI_DATOUTC;                  /**< Ouput Data register upper-bank low, offset: 0x2C8 */
  __I  uint32_t SAFO_SGI_DATOUTD;                  /**< Output Data register upper-bank high, offset: 0x2CC */
       uint8_t RESERVED_3[2352];
  __I  uint32_t SAFO_SGI_STATUS;                   /**< Status Register, offset: 0xC00 */
  __IO uint32_t SAFO_SGI_COUNT;                    /**< Calculation Counter, offset: 0xC04 */
       uint8_t RESERVED_4[248];
  __IO uint32_t SAFO_SGI_CTRL;                     /**< SGI Control Register, offset: 0xD00 */
  __IO uint32_t SAFO_SGI_CTRL2;                    /**< SGI Control Register 2, offset: 0xD04 */
       uint8_t RESERVED_5[12];
  __IO uint32_t SAFO_SGI_SM3_CTRL;                 /**< SM3 Control Register, offset: 0xD14 */
  __IO uint32_t SAFO_SGI_SM3_FIFO;                 /**< SM3 FIFO Register, offset: 0xD18 */
  __I  uint32_t SAFO_SGI_CONFIG;                   /**< SGI Configuration Register, offset: 0xD1C */
       uint8_t RESERVED_6[708];
  __IO uint32_t SAFO_SGI_INT_ENABLE;               /**< Interrupt Enable, offset: 0xFE4 */
  __O  uint32_t SAFO_SGI_INT_STATUS_CLR;           /**< Interrupt Status Clear, offset: 0xFE8 */
  __O  uint32_t SAFO_SGI_INT_STATUS_SET;           /**< Interrupt Status Set, offset: 0xFEC */
} OSCCA_Type;

/* ----------------------------------------------------------------------------
   -- OSCCA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSCCA_Register_Masks OSCCA Register Masks
 * @{
 */

/*! @name SAFO_SGI_DATIN0A - Input Data register 0 lower-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN0A_DATIN0A_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN0A_DATIN0A_SHIFT     (0U)
/*! DATIN0A - Input Data register */
#define OSCCA_SAFO_SGI_DATIN0A_DATIN0A(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN0A_DATIN0A_SHIFT)) & OSCCA_SAFO_SGI_DATIN0A_DATIN0A_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN0B - Input Data register 0 lower-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN0B_DATIN0B_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN0B_DATIN0B_SHIFT     (0U)
/*! DATIN0B - Input Data register */
#define OSCCA_SAFO_SGI_DATIN0B_DATIN0B(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN0B_DATIN0B_SHIFT)) & OSCCA_SAFO_SGI_DATIN0B_DATIN0B_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN0C - Input Data register 0 upper-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN0C_DATIN0C_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN0C_DATIN0C_SHIFT     (0U)
/*! DATIN0C - Input Data register */
#define OSCCA_SAFO_SGI_DATIN0C_DATIN0C(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN0C_DATIN0C_SHIFT)) & OSCCA_SAFO_SGI_DATIN0C_DATIN0C_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN0D - Input Data register 0 upper-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN0D_DATIN0D_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN0D_DATIN0D_SHIFT     (0U)
/*! DATIN0D - Input Data register */
#define OSCCA_SAFO_SGI_DATIN0D_DATIN0D(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN0D_DATIN0D_SHIFT)) & OSCCA_SAFO_SGI_DATIN0D_DATIN0D_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN1A - Input Data register 1 lower-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN1A_DATIN1A_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN1A_DATIN1A_SHIFT     (0U)
/*! DATIN1A - Input Data register */
#define OSCCA_SAFO_SGI_DATIN1A_DATIN1A(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN1A_DATIN1A_SHIFT)) & OSCCA_SAFO_SGI_DATIN1A_DATIN1A_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN1B - Input Data register 1 lower-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN1B_DATIN1B_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN1B_DATIN1B_SHIFT     (0U)
/*! DATIN1B - Input Data register */
#define OSCCA_SAFO_SGI_DATIN1B_DATIN1B(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN1B_DATIN1B_SHIFT)) & OSCCA_SAFO_SGI_DATIN1B_DATIN1B_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN1C - Input Data register 1 upper-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN1C_DATIN1C_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN1C_DATIN1C_SHIFT     (0U)
/*! DATIN1C - Input Data register */
#define OSCCA_SAFO_SGI_DATIN1C_DATIN1C(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN1C_DATIN1C_SHIFT)) & OSCCA_SAFO_SGI_DATIN1C_DATIN1C_MASK)
/*! @} */

/*! @name SAFO_SGI_DATIN1D - Input Data register 1 upper-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATIN1D_DATIN1D_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATIN1D_DATIN1D_SHIFT     (0U)
/*! DATIN1D - Input Data register */
#define OSCCA_SAFO_SGI_DATIN1D_DATIN1D(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATIN1D_DATIN1D_SHIFT)) & OSCCA_SAFO_SGI_DATIN1D_DATIN1D_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY0A - Input Key register 0 lower-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY0A_KEY0A_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY0A_KEY0A_SHIFT         (0U)
/*! KEY0A - Input Key register */
#define OSCCA_SAFO_SGI_KEY0A_KEY0A(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY0A_KEY0A_SHIFT)) & OSCCA_SAFO_SGI_KEY0A_KEY0A_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY0B - Input Key register 0 lower-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY0B_KEY0B_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY0B_KEY0B_SHIFT         (0U)
/*! KEY0B - Input Key register */
#define OSCCA_SAFO_SGI_KEY0B_KEY0B(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY0B_KEY0B_SHIFT)) & OSCCA_SAFO_SGI_KEY0B_KEY0B_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY0C - Input Key register 0 upper-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY0C_KEY0C_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY0C_KEY0C_SHIFT         (0U)
/*! KEY0C - Input Key register */
#define OSCCA_SAFO_SGI_KEY0C_KEY0C(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY0C_KEY0C_SHIFT)) & OSCCA_SAFO_SGI_KEY0C_KEY0C_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY0D - Input Key register 0 upper-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY0D_KEY0D_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY0D_KEY0D_SHIFT         (0U)
/*! KEY0D - Input Key register */
#define OSCCA_SAFO_SGI_KEY0D_KEY0D(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY0D_KEY0D_SHIFT)) & OSCCA_SAFO_SGI_KEY0D_KEY0D_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY1A - Input Key register 1 lower-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY1A_KEY1A_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY1A_KEY1A_SHIFT         (0U)
/*! KEY1A - Input Key register */
#define OSCCA_SAFO_SGI_KEY1A_KEY1A(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY1A_KEY1A_SHIFT)) & OSCCA_SAFO_SGI_KEY1A_KEY1A_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY1B - Input Key register 1 lower-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY1B_KEY1B_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY1B_KEY1B_SHIFT         (0U)
/*! KEY1B - Input Key register */
#define OSCCA_SAFO_SGI_KEY1B_KEY1B(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY1B_KEY1B_SHIFT)) & OSCCA_SAFO_SGI_KEY1B_KEY1B_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY1C - Input Key register 1 upper-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY1C_KEY1C_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY1C_KEY1C_SHIFT         (0U)
/*! KEY1C - Input Key register */
#define OSCCA_SAFO_SGI_KEY1C_KEY1C(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY1C_KEY1C_SHIFT)) & OSCCA_SAFO_SGI_KEY1C_KEY1C_MASK)
/*! @} */

/*! @name SAFO_SGI_KEY1D - Input Key register 1 upper-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_KEY1D_KEY1D_MASK          (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_KEY1D_KEY1D_SHIFT         (0U)
/*! KEY1D - Input Key register */
#define OSCCA_SAFO_SGI_KEY1D_KEY1D(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_KEY1D_KEY1D_SHIFT)) & OSCCA_SAFO_SGI_KEY1D_KEY1D_MASK)
/*! @} */

/*! @name SAFO_SGI_DATOUTA - Output Data register lower-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATOUTA_DATOUTA_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATOUTA_DATOUTA_SHIFT     (0U)
/*! DATOUTA - Output Data register */
#define OSCCA_SAFO_SGI_DATOUTA_DATOUTA(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATOUTA_DATOUTA_SHIFT)) & OSCCA_SAFO_SGI_DATOUTA_DATOUTA_MASK)
/*! @} */

/*! @name SAFO_SGI_DATOUTB - Ouput Data register lower-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATOUTB_DATOUTB_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATOUTB_DATOUTB_SHIFT     (0U)
/*! DATOUTB - Ouput Data register */
#define OSCCA_SAFO_SGI_DATOUTB_DATOUTB(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATOUTB_DATOUTB_SHIFT)) & OSCCA_SAFO_SGI_DATOUTB_DATOUTB_MASK)
/*! @} */

/*! @name SAFO_SGI_DATOUTC - Ouput Data register upper-bank low */
/*! @{ */

#define OSCCA_SAFO_SGI_DATOUTC_DATOUTC_MASK      (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATOUTC_DATOUTC_SHIFT     (0U)
/*! DATOUTC - Ouput Data register */
#define OSCCA_SAFO_SGI_DATOUTC_DATOUTC(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATOUTC_DATOUTC_SHIFT)) & OSCCA_SAFO_SGI_DATOUTC_DATOUTC_MASK)
/*! @} */

/*! @name SAFO_SGI_DATOUTD - Output Data register upper-bank high */
/*! @{ */

#define OSCCA_SAFO_SGI_DATOUTD_DOUTD_MASK        (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_DATOUTD_DOUTD_SHIFT       (0U)
/*! DOUTD - Output Data register */
#define OSCCA_SAFO_SGI_DATOUTD_DOUTD(x)          (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_DATOUTD_DOUTD_SHIFT)) & OSCCA_SAFO_SGI_DATOUTD_DOUTD_MASK)
/*! @} */

/*! @name SAFO_SGI_STATUS - Status Register */
/*! @{ */

#define OSCCA_SAFO_SGI_STATUS_BUSY_MASK          (0x1U)
#define OSCCA_SAFO_SGI_STATUS_BUSY_SHIFT         (0U)
/*! BUSY - Busy Flag */
#define OSCCA_SAFO_SGI_STATUS_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_BUSY_SHIFT)) & OSCCA_SAFO_SGI_STATUS_BUSY_MASK)

#define OSCCA_SAFO_SGI_STATUS_OFLOW_MASK         (0x2U)
#define OSCCA_SAFO_SGI_STATUS_OFLOW_SHIFT        (1U)
/*! OFLOW - Overflow Flag */
#define OSCCA_SAFO_SGI_STATUS_OFLOW(x)           (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_OFLOW_SHIFT)) & OSCCA_SAFO_SGI_STATUS_OFLOW_MASK)

#define OSCCA_SAFO_SGI_STATUS_PRNG_RDY_MASK      (0x4U)
#define OSCCA_SAFO_SGI_STATUS_PRNG_RDY_SHIFT     (2U)
/*! PRNG_RDY - PRNG Ready */
#define OSCCA_SAFO_SGI_STATUS_PRNG_RDY(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_PRNG_RDY_SHIFT)) & OSCCA_SAFO_SGI_STATUS_PRNG_RDY_MASK)

#define OSCCA_SAFO_SGI_STATUS_ERROR_MASK         (0x38U)
#define OSCCA_SAFO_SGI_STATUS_ERROR_SHIFT        (3U)
/*! ERROR - Error Indicator */
#define OSCCA_SAFO_SGI_STATUS_ERROR(x)           (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_ERROR_SHIFT)) & OSCCA_SAFO_SGI_STATUS_ERROR_MASK)

#define OSCCA_SAFO_SGI_STATUS_SM3_BUSY_MASK      (0x40U)
#define OSCCA_SAFO_SGI_STATUS_SM3_BUSY_SHIFT     (6U)
/*! SM3_BUSY - SM3 Busy Status Flag */
#define OSCCA_SAFO_SGI_STATUS_SM3_BUSY(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_SM3_BUSY_SHIFT)) & OSCCA_SAFO_SGI_STATUS_SM3_BUSY_MASK)

#define OSCCA_SAFO_SGI_STATUS_IRQ_MASK           (0x80U)
#define OSCCA_SAFO_SGI_STATUS_IRQ_SHIFT          (7U)
/*! IRQ - Interrupt Status Flag */
#define OSCCA_SAFO_SGI_STATUS_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_IRQ_SHIFT)) & OSCCA_SAFO_SGI_STATUS_IRQ_MASK)

#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_FULL_MASK (0x100U)
#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_FULL_SHIFT (8U)
/*! SM3_FIFO_FULL - SM3 FIFO Full Indicator */
#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_FULL(x)   (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_SM3_FIFO_FULL_SHIFT)) & OSCCA_SAFO_SGI_STATUS_SM3_FIFO_FULL_MASK)

#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_LEVEL_MASK (0x7E00U)
#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_LEVEL_SHIFT (9U)
/*! SM3_FIFO_LEVEL - SM3 FIFO Level */
#define OSCCA_SAFO_SGI_STATUS_SM3_FIFO_LEVEL(x)  (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_SM3_FIFO_LEVEL_SHIFT)) & OSCCA_SAFO_SGI_STATUS_SM3_FIFO_LEVEL_MASK)

#define OSCCA_SAFO_SGI_STATUS_SM3_ERROR_MASK     (0x8000U)
#define OSCCA_SAFO_SGI_STATUS_SM3_ERROR_SHIFT    (15U)
/*! SM3_ERROR - SM3 ERROR */
#define OSCCA_SAFO_SGI_STATUS_SM3_ERROR(x)       (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_STATUS_SM3_ERROR_SHIFT)) & OSCCA_SAFO_SGI_STATUS_SM3_ERROR_MASK)
/*! @} */

/*! @name SAFO_SGI_COUNT - Calculation Counter */
/*! @{ */

#define OSCCA_SAFO_SGI_COUNT_COUNT_MASK          (0xFFFFU)
#define OSCCA_SAFO_SGI_COUNT_COUNT_SHIFT         (0U)
/*! COUNT - Calculation Counter */
#define OSCCA_SAFO_SGI_COUNT_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_COUNT_COUNT_SHIFT)) & OSCCA_SAFO_SGI_COUNT_COUNT_MASK)
/*! @} */

/*! @name SAFO_SGI_CTRL - SGI Control Register */
/*! @{ */

#define OSCCA_SAFO_SGI_CTRL_START_MASK           (0x1U)
#define OSCCA_SAFO_SGI_CTRL_START_SHIFT          (0U)
/*! START - Start Crypto Operation */
#define OSCCA_SAFO_SGI_CTRL_START(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_START_SHIFT)) & OSCCA_SAFO_SGI_CTRL_START_MASK)

#define OSCCA_SAFO_SGI_CTRL_DECRYPT_MASK         (0x2U)
#define OSCCA_SAFO_SGI_CTRL_DECRYPT_SHIFT        (1U)
/*! DECRYPT - Sets Cipher direction(SM4) */
#define OSCCA_SAFO_SGI_CTRL_DECRYPT(x)           (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_DECRYPT_SHIFT)) & OSCCA_SAFO_SGI_CTRL_DECRYPT_MASK)

#define OSCCA_SAFO_SGI_CTRL_CRYPTO_OP_MASK       (0x70U)
#define OSCCA_SAFO_SGI_CTRL_CRYPTO_OP_SHIFT      (4U)
/*! CRYPTO_OP - Crypto Operation Type */
#define OSCCA_SAFO_SGI_CTRL_CRYPTO_OP(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_CRYPTO_OP_SHIFT)) & OSCCA_SAFO_SGI_CTRL_CRYPTO_OP_MASK)

#define OSCCA_SAFO_SGI_CTRL_INSEL_MASK           (0x780U)
#define OSCCA_SAFO_SGI_CTRL_INSEL_SHIFT          (7U)
/*! INSEL - Kernel Input Configuration */
#define OSCCA_SAFO_SGI_CTRL_INSEL(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_INSEL_SHIFT)) & OSCCA_SAFO_SGI_CTRL_INSEL_MASK)

#define OSCCA_SAFO_SGI_CTRL_OUTSEL_MASK          (0x3800U)
#define OSCCA_SAFO_SGI_CTRL_OUTSEL_SHIFT         (11U)
/*! OUTSEL - Kernel Input Configuration */
#define OSCCA_SAFO_SGI_CTRL_OUTSEL(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_OUTSEL_SHIFT)) & OSCCA_SAFO_SGI_CTRL_OUTSEL_MASK)

#define OSCCA_SAFO_SGI_CTRL_DATOUT_RES_MASK      (0xC000U)
#define OSCCA_SAFO_SGI_CTRL_DATOUT_RES_SHIFT     (14U)
/*! DATOUT_RES - Kernels Data Out Options */
#define OSCCA_SAFO_SGI_CTRL_DATOUT_RES(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_DATOUT_RES_SHIFT)) & OSCCA_SAFO_SGI_CTRL_DATOUT_RES_MASK)

#define OSCCA_SAFO_SGI_CTRL_INKEYSEL_MASK        (0x1F00000U)
#define OSCCA_SAFO_SGI_CTRL_INKEYSEL_SHIFT       (20U)
/*! INKEYSEL - Input key selection */
#define OSCCA_SAFO_SGI_CTRL_INKEYSEL(x)          (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_INKEYSEL_SHIFT)) & OSCCA_SAFO_SGI_CTRL_INKEYSEL_MASK)

#define OSCCA_SAFO_SGI_CTRL_SM4_EN_MASK          (0x8000000U)
#define OSCCA_SAFO_SGI_CTRL_SM4_EN_SHIFT         (27U)
/*! SM4_EN - SM4 Kernel Enable */
#define OSCCA_SAFO_SGI_CTRL_SM4_EN(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_SM4_EN_SHIFT)) & OSCCA_SAFO_SGI_CTRL_SM4_EN_MASK)

#define OSCCA_SAFO_SGI_CTRL_SM4_NO_KL_MASK       (0x10000000U)
#define OSCCA_SAFO_SGI_CTRL_SM4_NO_KL_SHIFT      (28U)
/*! SM4_NO_KL - SM4 No Decryption Key Schedule */
#define OSCCA_SAFO_SGI_CTRL_SM4_NO_KL(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL_SM4_NO_KL_SHIFT)) & OSCCA_SAFO_SGI_CTRL_SM4_NO_KL_MASK)
/*! @} */

/*! @name SAFO_SGI_CTRL2 - SGI Control Register 2 */
/*! @{ */

#define OSCCA_SAFO_SGI_CTRL2_FLUSH_MASK          (0x1U)
#define OSCCA_SAFO_SGI_CTRL2_FLUSH_SHIFT         (0U)
/*! FLUSH - Start Full SGI Flush */
#define OSCCA_SAFO_SGI_CTRL2_FLUSH(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_FLUSH_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_FLUSH_MASK)

#define OSCCA_SAFO_SGI_CTRL2_KEY_FLUSH_MASK      (0x2U)
#define OSCCA_SAFO_SGI_CTRL2_KEY_FLUSH_SHIFT     (1U)
/*! KEY_FLUSH - Start KEY register-bank Flush */
#define OSCCA_SAFO_SGI_CTRL2_KEY_FLUSH(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_KEY_FLUSH_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_KEY_FLUSH_MASK)

#define OSCCA_SAFO_SGI_CTRL2_DATIN_FLUSH_MASK    (0x4U)
#define OSCCA_SAFO_SGI_CTRL2_DATIN_FLUSH_SHIFT   (2U)
/*! DATIN_FLUSH - Start DATIN register-bank Flush */
#define OSCCA_SAFO_SGI_CTRL2_DATIN_FLUSH(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_DATIN_FLUSH_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_DATIN_FLUSH_MASK)

#define OSCCA_SAFO_SGI_CTRL2_INCR_MASK           (0x8U)
#define OSCCA_SAFO_SGI_CTRL2_INCR_SHIFT          (3U)
/*! INCR - Increment(Triggered by SFR write) */
#define OSCCA_SAFO_SGI_CTRL2_INCR(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_INCR_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_INCR_MASK)

#define OSCCA_SAFO_SGI_CTRL2_XORWR_MASK          (0x10U)
#define OSCCA_SAFO_SGI_CTRL2_XORWR_SHIFT         (4U)
/*! XORWR - Write-XOR control */
#define OSCCA_SAFO_SGI_CTRL2_XORWR(x)            (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_XORWR_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_XORWR_MASK)

#define OSCCA_SAFO_SGI_CTRL2_FLUSHWR_MASK        (0x20U)
#define OSCCA_SAFO_SGI_CTRL2_FLUSHWR_SHIFT       (5U)
/*! FLUSHWR - Flush Write control */
#define OSCCA_SAFO_SGI_CTRL2_FLUSHWR(x)          (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_FLUSHWR_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_FLUSHWR_MASK)

#define OSCCA_SAFO_SGI_CTRL2_INCR_CIN_MASK       (0x40U)
#define OSCCA_SAFO_SGI_CTRL2_INCR_CIN_SHIFT      (6U)
/*! INCR_CIN - Increment Carry-In control */
#define OSCCA_SAFO_SGI_CTRL2_INCR_CIN(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_INCR_CIN_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_INCR_CIN_MASK)

#define OSCCA_SAFO_SGI_CTRL2_KEYRES_MASK         (0x1F0000U)
#define OSCCA_SAFO_SGI_CTRL2_KEYRES_SHIFT        (16U)
/*! KEYRES - Selects key registers to be updated when RKEY=1 */
#define OSCCA_SAFO_SGI_CTRL2_KEYRES(x)           (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_KEYRES_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_KEYRES_MASK)

#define OSCCA_SAFO_SGI_CTRL2_RKEY_MASK           (0x200000U)
#define OSCCA_SAFO_SGI_CTRL2_RKEY_SHIFT          (21U)
/*! RKEY - Crypto result location */
#define OSCCA_SAFO_SGI_CTRL2_RKEY(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_RKEY_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_RKEY_MASK)

#define OSCCA_SAFO_SGI_CTRL2_BYTES_ORDER_MASK    (0x400000U)
#define OSCCA_SAFO_SGI_CTRL2_BYTES_ORDER_SHIFT   (22U)
/*! BYTES_ORDER - Byte order of regbank read/write data */
#define OSCCA_SAFO_SGI_CTRL2_BYTES_ORDER(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CTRL2_BYTES_ORDER_SHIFT)) & OSCCA_SAFO_SGI_CTRL2_BYTES_ORDER_MASK)
/*! @} */

/*! @name SAFO_SGI_SM3_CTRL - SM3 Control Register */
/*! @{ */

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_MODE_MASK    (0x2U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_MODE_SHIFT   (1U)
/*! SM3_MODE - SM3 mode normal or automatic */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_MODE(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_MODE_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_MODE_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_LOW_LIM_MASK (0xF0U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_LOW_LIM_SHIFT (4U)
/*! SM3_LOW_LIM - SM3 FIFO low limit */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_LOW_LIM(x)   (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_LOW_LIM_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_LOW_LIM_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_HIGH_LIM_MASK (0xF00U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_HIGH_LIM_SHIFT (8U)
/*! SM3_HIGH_LIM - SM3 FIFO high limit */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_HIGH_LIM(x)  (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_HIGH_LIM_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_HIGH_LIM_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_COUNT_EN_MASK (0x1000U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_COUNT_EN_SHIFT (12U)
/*! SM3_COUNT_EN - SM3 Calculation Counter Enable */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_COUNT_EN(x)  (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_COUNT_EN_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_COUNT_EN_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_HASH_RELOAD_MASK (0x2000U)
#define OSCCA_SAFO_SGI_SM3_CTRL_HASH_RELOAD_SHIFT (13U)
/*! HASH_RELOAD - SM3 HASH reload */
#define OSCCA_SAFO_SGI_SM3_CTRL_HASH_RELOAD(x)   (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_HASH_RELOAD_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_HASH_RELOAD_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_STOP_MASK    (0x4000U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_STOP_SHIFT   (14U)
/*! SM3_STOP - STOP SM3 AUTO mode */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_STOP(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_STOP_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_STOP_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_NO_AUTO_INIT_MASK (0x8000U)
#define OSCCA_SAFO_SGI_SM3_CTRL_NO_AUTO_INIT_SHIFT (15U)
/*! NO_AUTO_INIT - SM3 no automatic HASH initialisation */
#define OSCCA_SAFO_SGI_SM3_CTRL_NO_AUTO_INIT(x)  (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_NO_AUTO_INIT_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_NO_AUTO_INIT_MASK)

#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_EN_MASK      (0x10000U)
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_EN_SHIFT     (16U)
/*! SM3_EN - SM3 enable */
#define OSCCA_SAFO_SGI_SM3_CTRL_SM3_EN(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_CTRL_SM3_EN_SHIFT)) & OSCCA_SAFO_SGI_SM3_CTRL_SM3_EN_MASK)
/*! @} */

/*! @name SAFO_SGI_SM3_FIFO - SM3 FIFO Register */
/*! @{ */

#define OSCCA_SAFO_SGI_SM3_FIFO_FIFO_MASK        (0xFFFFFFFFU)
#define OSCCA_SAFO_SGI_SM3_FIFO_FIFO_SHIFT       (0U)
/*! FIFO - SM3 FIFO Register */
#define OSCCA_SAFO_SGI_SM3_FIFO_FIFO(x)          (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_SM3_FIFO_FIFO_SHIFT)) & OSCCA_SAFO_SGI_SM3_FIFO_FIFO_MASK)
/*! @} */

/*! @name SAFO_SGI_CONFIG - SGI Configuration Register */
/*! @{ */

#define OSCCA_SAFO_SGI_CONFIG_HAS_CMAC_MASK      (0x80U)
#define OSCCA_SAFO_SGI_CONFIG_HAS_CMAC_SHIFT     (7U)
/*! HAS_CMAC - Has CMAC */
#define OSCCA_SAFO_SGI_CONFIG_HAS_CMAC(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_HAS_CMAC_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_HAS_CMAC_MASK)

#define OSCCA_SAFO_SGI_CONFIG_HAS_GFMUL_MASK     (0x100U)
#define OSCCA_SAFO_SGI_CONFIG_HAS_GFMUL_SHIFT    (8U)
/*! HAS_GFMUL - Has GFMUL */
#define OSCCA_SAFO_SGI_CONFIG_HAS_GFMUL(x)       (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_HAS_GFMUL_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_HAS_GFMUL_MASK)

#define OSCCA_SAFO_SGI_CONFIG_INTERNAL_PRNG_MASK (0x200U)
#define OSCCA_SAFO_SGI_CONFIG_INTERNAL_PRNG_SHIFT (9U)
/*! INTERNAL_PRNG - Has internal PRNG */
#define OSCCA_SAFO_SGI_CONFIG_INTERNAL_PRNG(x)   (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_INTERNAL_PRNG_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_INTERNAL_PRNG_MASK)

#define OSCCA_SAFO_SGI_CONFIG_KEY_DIGEST_MASK    (0x400U)
#define OSCCA_SAFO_SGI_CONFIG_KEY_DIGEST_SHIFT   (10U)
/*! KEY_DIGEST - Has key digest */
#define OSCCA_SAFO_SGI_CONFIG_KEY_DIGEST(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_KEY_DIGEST_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_KEY_DIGEST_MASK)

#define OSCCA_SAFO_SGI_CONFIG_FA_MASK            (0x2000U)
#define OSCCA_SAFO_SGI_CONFIG_FA_SHIFT           (13U)
/*! FA - Has FA protection */
#define OSCCA_SAFO_SGI_CONFIG_FA(x)              (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_FA_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_FA_MASK)

#define OSCCA_SAFO_SGI_CONFIG_BUS_WIDTH_MASK     (0x8000U)
#define OSCCA_SAFO_SGI_CONFIG_BUS_WIDTH_SHIFT    (15U)
/*! BUS_WIDTH - Bus width */
#define OSCCA_SAFO_SGI_CONFIG_BUS_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_BUS_WIDTH_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_BUS_WIDTH_MASK)

#define OSCCA_SAFO_SGI_CONFIG_NUM_DATIN_MASK     (0x30000U)
#define OSCCA_SAFO_SGI_CONFIG_NUM_DATIN_SHIFT    (16U)
/*! NUM_DATIN - Number DATIN */
#define OSCCA_SAFO_SGI_CONFIG_NUM_DATIN(x)       (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_NUM_DATIN_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_NUM_DATIN_MASK)

#define OSCCA_SAFO_SGI_CONFIG_NUM_KEY_MASK       (0x1C0000U)
#define OSCCA_SAFO_SGI_CONFIG_NUM_KEY_SHIFT      (18U)
/*! NUM_KEY - Number KEY */
#define OSCCA_SAFO_SGI_CONFIG_NUM_KEY(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_NUM_KEY_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_NUM_KEY_MASK)

#define OSCCA_SAFO_SGI_CONFIG_EDC_MASK           (0x200000U)
#define OSCCA_SAFO_SGI_CONFIG_EDC_SHIFT          (21U)
/*! EDC - EDC enable */
#define OSCCA_SAFO_SGI_CONFIG_EDC(x)             (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_EDC_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_EDC_MASK)

#define OSCCA_SAFO_SGI_CONFIG_DUAL_SGI_MASK      (0x400000U)
#define OSCCA_SAFO_SGI_CONFIG_DUAL_SGI_SHIFT     (22U)
/*! DUAL_SGI - Has dual SGI */
#define OSCCA_SAFO_SGI_CONFIG_DUAL_SGI(x)        (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_DUAL_SGI_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_DUAL_SGI_MASK)

#define OSCCA_SAFO_SGI_CONFIG_SHA_256_ONLY_MASK  (0x1000000U)
#define OSCCA_SAFO_SGI_CONFIG_SHA_256_ONLY_SHIFT (24U)
/*! SHA_256_ONLY - Has SHA 256 only */
#define OSCCA_SAFO_SGI_CONFIG_SHA_256_ONLY(x)    (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_SHA_256_ONLY_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_SHA_256_ONLY_MASK)

#define OSCCA_SAFO_SGI_CONFIG_SPB_SUPPORT_MASK   (0x2000000U)
#define OSCCA_SAFO_SGI_CONFIG_SPB_SUPPORT_SHIFT  (25U)
/*! SPB_SUPPORT - ID_CFG_SPB_SUPPORT is set */
#define OSCCA_SAFO_SGI_CONFIG_SPB_SUPPORT(x)     (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_SPB_SUPPORT_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_SPB_SUPPORT_MASK)

#define OSCCA_SAFO_SGI_CONFIG_SPB_MASKING_MASK   (0x4000000U)
#define OSCCA_SAFO_SGI_CONFIG_SPB_MASKING_SHIFT  (26U)
/*! SPB_MASKING - ID_CFG_SAFO_SGI_SPB_MASKING is set */
#define OSCCA_SAFO_SGI_CONFIG_SPB_MASKING(x)     (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_SPB_MASKING_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_SPB_MASKING_MASK)

#define OSCCA_SAFO_SGI_CONFIG_SFR_SW_MASK_MASK   (0x8000000U)
#define OSCCA_SAFO_SGI_CONFIG_SFR_SW_MASK_SHIFT  (27U)
/*! SFR_SW_MASK - ID_CFG_SAFO_SGI_USE_SFR_SW_MASK is set */
#define OSCCA_SAFO_SGI_CONFIG_SFR_SW_MASK(x)     (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_SFR_SW_MASK_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_SFR_SW_MASK_MASK)

#define OSCCA_SAFO_SGI_CONFIG_HAS_SM3_MASK       (0x10000000U)
#define OSCCA_SAFO_SGI_CONFIG_HAS_SM3_SHIFT      (28U)
/*! HAS_SM3 - Has SM3 */
#define OSCCA_SAFO_SGI_CONFIG_HAS_SM3(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_HAS_SM3_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_HAS_SM3_MASK)

#define OSCCA_SAFO_SGI_CONFIG_HAS_SM4_MASK       (0x20000000U)
#define OSCCA_SAFO_SGI_CONFIG_HAS_SM4_SHIFT      (29U)
/*! HAS_SM4 - Has SM4 */
#define OSCCA_SAFO_SGI_CONFIG_HAS_SM4(x)         (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_CONFIG_HAS_SM4_SHIFT)) & OSCCA_SAFO_SGI_CONFIG_HAS_SM4_MASK)
/*! @} */

/*! @name SAFO_SGI_INT_ENABLE - Interrupt Enable */
/*! @{ */

#define OSCCA_SAFO_SGI_INT_ENABLE_INT_EN_MASK    (0x1U)
#define OSCCA_SAFO_SGI_INT_ENABLE_INT_EN_SHIFT   (0U)
/*! INT_EN - Interrupt enable bit */
#define OSCCA_SAFO_SGI_INT_ENABLE_INT_EN(x)      (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_INT_ENABLE_INT_EN_SHIFT)) & OSCCA_SAFO_SGI_INT_ENABLE_INT_EN_MASK)
/*! @} */

/*! @name SAFO_SGI_INT_STATUS_CLR - Interrupt Status Clear */
/*! @{ */

#define OSCCA_SAFO_SGI_INT_STATUS_CLR_INT_CLR_MASK (0x1U)
#define OSCCA_SAFO_SGI_INT_STATUS_CLR_INT_CLR_SHIFT (0U)
/*! INT_CLR - Interrupt Status Clear */
#define OSCCA_SAFO_SGI_INT_STATUS_CLR_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_INT_STATUS_CLR_INT_CLR_SHIFT)) & OSCCA_SAFO_SGI_INT_STATUS_CLR_INT_CLR_MASK)
/*! @} */

/*! @name SAFO_SGI_INT_STATUS_SET - Interrupt Status Set */
/*! @{ */

#define OSCCA_SAFO_SGI_INT_STATUS_SET_INT_SET_MASK (0x1U)
#define OSCCA_SAFO_SGI_INT_STATUS_SET_INT_SET_SHIFT (0U)
/*! INT_SET - Set Interrupt by SW */
#define OSCCA_SAFO_SGI_INT_STATUS_SET_INT_SET(x) (((uint32_t)(((uint32_t)(x)) << OSCCA_SAFO_SGI_INT_STATUS_SET_INT_SET_SHIFT)) & OSCCA_SAFO_SGI_INT_STATUS_SET_INT_SET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSCCA_Register_Masks */


/*!
 * @}
 */ /* end of group OSCCA_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OSCCA_H_ */

