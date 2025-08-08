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
**         CMSIS Peripheral Access Layer for NPU_EIM
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
 * @file NPU_EIM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NPU_EIM
 *
 * CMSIS Peripheral Access Layer for NPU_EIM
 */

#if !defined(NPU_EIM_H_)
#define NPU_EIM_H_                               /**< Symbol preventing repeated inclusion */

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
   -- NPU_EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_EIM_Peripheral_Access_Layer NPU_EIM Peripheral Access Layer
 * @{
 */

/** NPU_EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
       uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
  __IO uint32_t EICHD0_WORD2;                      /**< Error Injection Channel Descriptor 0, Word2, offset: 0x108 */
  __IO uint32_t EICHD0_WORD3;                      /**< Error Injection Channel Descriptor 0, Word3, offset: 0x10C */
  __IO uint32_t EICHD0_WORD4;                      /**< Error Injection Channel Descriptor 0, Word4, offset: 0x110 */
       uint8_t RESERVED_1[44];
  __IO uint32_t EICHD1_WORD0;                      /**< Error Injection Channel Descriptor 1, Word0, offset: 0x140 */
  __IO uint32_t EICHD1_WORD1;                      /**< Error Injection Channel Descriptor 1, Word1, offset: 0x144 */
} NPU_EIM_Type;

/* ----------------------------------------------------------------------------
   -- NPU_EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_EIM_Register_Masks NPU_EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define NPU_EIM_EIMCR_GEIEN_MASK                 (0x1U)
#define NPU_EIM_EIMCR_GEIEN_SHIFT                (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define NPU_EIM_EIMCR_GEIEN(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EIMCR_GEIEN_SHIFT)) & NPU_EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define NPU_EIM_EICHEN_EICH1EN_MASK              (0x40000000U)
#define NPU_EIM_EICHEN_EICH1EN_SHIFT             (30U)
/*! EICH1EN - Error Injection Channel 1 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 1
 *  0b1..Error injection is enabled on Error Injection Channel 1
 */
#define NPU_EIM_EICHEN_EICH1EN(x)                (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHEN_EICH1EN_SHIFT)) & NPU_EIM_EICHEN_EICH1EN_MASK)

#define NPU_EIM_EICHEN_EICH0EN_MASK              (0x80000000U)
#define NPU_EIM_EICHEN_EICH0EN_SHIFT             (31U)
/*! EICH0EN - Error Injection Channel 0 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 0
 *  0b1..Error injection is enabled on Error Injection Channel 0
 */
#define NPU_EIM_EICHEN_EICH0EN(x)                (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHEN_EICH0EN_SHIFT)) & NPU_EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define NPU_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK    (0xFFFFF000U)
#define NPU_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT   (12U)
/*! CHKBIT_MASK - Checkbit Mask */
#define NPU_EIM_EICHD0_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & NPU_EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define NPU_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK  (0xFFFFFFFFU)
#define NPU_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define NPU_EIM_EICHD0_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & NPU_EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD2 - Error Injection Channel Descriptor 0, Word2 */
/*! @{ */

#define NPU_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK  (0xFFFFFFFFU)
#define NPU_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT (0U)
/*! B4_7DATA_MASK - Data Mask Bytes 4-7 */
#define NPU_EIM_EICHD0_WORD2_B4_7DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD0_WORD2_B4_7DATA_MASK_SHIFT)) & NPU_EIM_EICHD0_WORD2_B4_7DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD3 - Error Injection Channel Descriptor 0, Word3 */
/*! @{ */

#define NPU_EIM_EICHD0_WORD3_B8_11DATA_MASK_MASK (0xFFFFFFFFU)
#define NPU_EIM_EICHD0_WORD3_B8_11DATA_MASK_SHIFT (0U)
/*! B8_11DATA_MASK - Data Mask Bytes 8-11 */
#define NPU_EIM_EICHD0_WORD3_B8_11DATA_MASK(x)   (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD0_WORD3_B8_11DATA_MASK_SHIFT)) & NPU_EIM_EICHD0_WORD3_B8_11DATA_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD4 - Error Injection Channel Descriptor 0, Word4 */
/*! @{ */

#define NPU_EIM_EICHD0_WORD4_B12_15DATA_MASK_MASK (0xFFFFFFFFU)
#define NPU_EIM_EICHD0_WORD4_B12_15DATA_MASK_SHIFT (0U)
/*! B12_15DATA_MASK - Data Mask Bytes 12-15 */
#define NPU_EIM_EICHD0_WORD4_B12_15DATA_MASK(x)  (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD0_WORD4_B12_15DATA_MASK_SHIFT)) & NPU_EIM_EICHD0_WORD4_B12_15DATA_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD0 - Error Injection Channel Descriptor 1, Word0 */
/*! @{ */

#define NPU_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK    (0x80000000U)
#define NPU_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT   (31U)
/*! CHKBIT_MASK - Checkbit Mask */
#define NPU_EIM_EICHD1_WORD0_CHKBIT_MASK(x)      (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD1_WORD0_CHKBIT_MASK_SHIFT)) & NPU_EIM_EICHD1_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD1_WORD1 - Error Injection Channel Descriptor 1, Word1 */
/*! @{ */

#define NPU_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK  (0x1U)
#define NPU_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define NPU_EIM_EICHD1_WORD1_B0_3DATA_MASK(x)    (((uint32_t)(((uint32_t)(x)) << NPU_EIM_EICHD1_WORD1_B0_3DATA_MASK_SHIFT)) & NPU_EIM_EICHD1_WORD1_B0_3DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_EIM_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_EIM_Peripheral_Access_Layer */


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


#endif  /* NPU_EIM_H_ */

