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
**     Build:               b250106
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
**
** ###################################################################
*/

/*!
 * @file WAKEUP_EIM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for WAKEUP_EIM
 *
 * CMSIS Peripheral Access Layer for WAKEUP_EIM
 */

#if !defined(WAKEUP_EIM_H_)
#define WAKEUP_EIM_H_                            /**< Symbol preventing repeated inclusion */

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
       uint8_t RESERVED_2[56];
  __IO uint32_t EICHD2_WORD0;                      /**< Error Injection Channel Descriptor 2, Word0, offset: 0x180 */
  __IO uint32_t EICHD2_WORD1;                      /**< Error Injection Channel Descriptor 2, Word1, offset: 0x184 */
       uint8_t RESERVED_3[124];
  __IO uint32_t EICHD4_WORD1;                      /**< Error Injection Channel Descriptor 4, Word1, offset: 0x204 */
       uint8_t RESERVED_4[60];
  __IO uint32_t EICHD5_WORD1;                      /**< Error Injection Channel Descriptor 5, Word1, offset: 0x244 */
       uint8_t RESERVED_5[60];
  __IO uint32_t EICHD6_WORD1;                      /**< Error Injection Channel Descriptor 6, Word1, offset: 0x284 */
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

#define WAKEUP_EIM_EICHEN_EICH6EN_MASK           (0x2000000U)
#define WAKEUP_EIM_EICHEN_EICH6EN_SHIFT          (25U)
/*! EICH6EN - Error Injection Channel 6 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 6
 *  0b1..Error injection is enabled on Error Injection Channel 6
 */
#define WAKEUP_EIM_EICHEN_EICH6EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH6EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH6EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH5EN_MASK           (0x4000000U)
#define WAKEUP_EIM_EICHEN_EICH5EN_SHIFT          (26U)
/*! EICH5EN - Error Injection Channel 5 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 5
 *  0b1..Error injection is enabled on Error Injection Channel 5
 */
#define WAKEUP_EIM_EICHEN_EICH5EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH5EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH5EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH4EN_MASK           (0x8000000U)
#define WAKEUP_EIM_EICHEN_EICH4EN_SHIFT          (27U)
/*! EICH4EN - Error Injection Channel 4 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 4
 *  0b1..Error injection is enabled on Error Injection Channel 4
 */
#define WAKEUP_EIM_EICHEN_EICH4EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH4EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH4EN_MASK)

#define WAKEUP_EIM_EICHEN_EICH2EN_MASK           (0x20000000U)
#define WAKEUP_EIM_EICHEN_EICH2EN_SHIFT          (29U)
/*! EICH2EN - Error Injection Channel 2 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 2
 *  0b1..Error injection is enabled on Error Injection Channel 2
 */
#define WAKEUP_EIM_EICHEN_EICH2EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHEN_EICH2EN_SHIFT)) & WAKEUP_EIM_EICHEN_EICH2EN_MASK)

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
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD0 - Error Injection Channel Descriptor 2, Word0 */
/*! @{ */

#define WAKEUP_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK (0xFF000000U)
#define WAKEUP_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT (24U)
/*! CHKBIT_MASK - Checkbit Mask */
#define WAKEUP_EIM_EICHD2_WORD0_CHKBIT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD2_WORD0_CHKBIT_MASK_SHIFT)) & WAKEUP_EIM_EICHD2_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD2_WORD1 - Error Injection Channel Descriptor 2, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK (0x1U)
#define WAKEUP_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD2_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD2_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD2_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD4_WORD1 - Error Injection Channel Descriptor 4, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD4_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD5_WORD1 - Error Injection Channel Descriptor 5, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK (0xFFFFFFFFU)
#define WAKEUP_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD5_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD5_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD5_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD6_WORD1 - Error Injection Channel Descriptor 6, Word1 */
/*! @{ */

#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK (0xFFU)
#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK(x) (((uint32_t)(((uint32_t)(x)) << WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_SHIFT)) & WAKEUP_EIM_EICHD6_WORD1_B0_3DATA_MASK_MASK)
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


#endif  /* WAKEUP_EIM_H_ */

