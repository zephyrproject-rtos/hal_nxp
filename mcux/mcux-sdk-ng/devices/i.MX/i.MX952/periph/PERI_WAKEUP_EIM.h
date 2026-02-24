/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKEUP_EIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WAKEUP_EIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WAKEUP_EIM
 *
 * CMSIS Peripheral Access Layer for WAKEUP_EIM
 */

#if !defined(PERI_WAKEUP_EIM_H_)
#define PERI_WAKEUP_EIM_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- WAKEUP_EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_EIM_Peripheral_Access_Layer WAKEUP_EIM Peripheral Access Layer
 * @{
 */

/** WAKEUP_EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
       uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108 */
       uint8_t RESERVED_1[52];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
       uint8_t RESERVED_2[188];
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
       uint8_t RESERVED_3[120];
  __IO uint32_t EICHD6_WORD0;                      /**< Error Injection Channel Descriptor 6, Word0, offset: 0x280 */
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
       uint8_t RESERVED_4[56];
  __IO uint32_t EICHD7_WORD0;                      /**< Error Injection Channel Descriptor 7, Word0, offset: 0x2C0 */
  __IO uint32_t EICHD7_WORD1;                      /**< Error Injection Channel Descriptor 7, Word1, offset: 0x2C4 */
  __IO uint32_t EICHD7_WORD2;                      /**< Error Injection Channel Descriptor 7, Word2, offset: 0x2C8 */
} WAKEUP_EIM_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_EIM_Register_Masks WAKEUP_EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define WAKEUP_EIM_EIMCR_GEIEN_MASK              (0x1U)
#define WAKEUP_EIM_EIMCR_GEIEN_SHIFT             (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define WAKEUP_EIM_EIMCR_GEIEN(x)                (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EIMCR_GEIEN_SHIFT)) & WAKEUP_EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define WAKEUP_EIM_EICHEN_EICH7EN_MASK           (0x1000000U)
#define WAKEUP_EIM_EICHEN_EICH7EN_SHIFT          (24U)
/*! EICH7EN - Error Injection Channel 7 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 7
 *  0b1..Error injection is enabled on Error Injection Channel 7
 */
#define WAKEUP_EIM_EICHEN_EICH7EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH7EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH7EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH6EN_MASK           (0x2000000U)
#define WAKEUP_EIM_EICHEN_EICH6EN_SHIFT          (25U)
/*! EICH6EN - Error Injection Channel 6 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 6
 *  0b1..Error injection is enabled on Error Injection Channel 6
 */
#define WAKEUP_EIM_EICHEN_EICH6EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH6EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH6EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH4EN_MASK           (0x8000000U)
#define WAKEUP_EIM_EICHEN_EICH4EN_SHIFT          (27U)
/*! EICH4EN - Error Injection Channel 4 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 4
 *  0b1..Error injection is enabled on Error Injection Channel 4
 */
#define WAKEUP_EIM_EICHEN_EICH4EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH4EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH4EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH1EN_MASK           (0x40000000U)
#define WAKEUP_EIM_EICHEN_EICH1EN_SHIFT          (30U)
/*! EICH1EN - Error Injection Channel 1 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 1
 *  0b1..Error injection is enabled on Error Injection Channel 1
 */
#define WAKEUP_EIM_EICHEN_EICH1EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH1EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH1EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH0EN_MASK           (0x80000000U)
#define WAKEUP_EIM_EICHEN_EICH0EN_SHIFT          (31U)
/*! EICH0EN - Error Injection Channel 0 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 0
 *  0b1..Error injection is enabled on Error Injection Channel 0
 */
#define WAKEUP_EIM_EICHEN_EICH0EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH0EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define WAKEUP_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD0_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK (0xF8000000U)
#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT (27U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD0 - Error Injection Channel Descriptor 6, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK (0xFFF00000U)
#define WAKEUP_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT (20U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD6_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD6_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD6_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD0 - Error Injection Channel Descriptor 7, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define WAKEUP_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD7_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD7_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD7_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD1 - Error Injection Channel Descriptor 7, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD7_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD7_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD7_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD7_WORD2 - Error Injection Channel Descriptor 7, Word2 */
/*! @{ */

#define WAKEUP_EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Field */
#define WAKEUP_EIM_EICHD7_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD7_WORD2_B4_7DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD7_WORD2_B4_7DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_EIM_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_EIM_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKEUP_EIM_H_ */

