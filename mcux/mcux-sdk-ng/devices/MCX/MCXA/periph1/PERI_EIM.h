/*
** ###################################################################
**     Processors:          MCXA144VFT
**                          MCXA144VLH
**                          MCXA144VLL
**                          MCXA144VMP
**                          MCXA144VPJ
**                          MCXA145VFT
**                          MCXA145VLH
**                          MCXA145VLL
**                          MCXA145VMP
**                          MCXA145VPJ
**                          MCXA146VFT
**                          MCXA146VLH
**                          MCXA146VLL
**                          MCXA146VMP
**                          MCXA146VPJ
**                          MCXA154VFT
**                          MCXA154VLH
**                          MCXA154VLL
**                          MCXA154VMP
**                          MCXA154VPJ
**                          MCXA155VFT
**                          MCXA155VLH
**                          MCXA155VLL
**                          MCXA155VMP
**                          MCXA155VPJ
**                          MCXA156VFT
**                          MCXA156VLH
**                          MCXA156VLL
**                          MCXA156VMP
**                          MCXA156VPJ
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-29)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EIM
 *
 * CMSIS Peripheral Access Layer for EIM
 */

#if !defined(PERI_EIM_H_)
#define PERI_EIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA144VFT) || defined(CPU_MCXA144VLH) || defined(CPU_MCXA144VLL) || defined(CPU_MCXA144VMP) || defined(CPU_MCXA144VPJ))
#include "MCXA144_COMMON.h"
#elif (defined(CPU_MCXA145VFT) || defined(CPU_MCXA145VLH) || defined(CPU_MCXA145VLL) || defined(CPU_MCXA145VMP) || defined(CPU_MCXA145VPJ))
#include "MCXA145_COMMON.h"
#elif (defined(CPU_MCXA146VFT) || defined(CPU_MCXA146VLH) || defined(CPU_MCXA146VLL) || defined(CPU_MCXA146VMP) || defined(CPU_MCXA146VPJ))
#include "MCXA146_COMMON.h"
#elif (defined(CPU_MCXA154VFT) || defined(CPU_MCXA154VLH) || defined(CPU_MCXA154VLL) || defined(CPU_MCXA154VMP) || defined(CPU_MCXA154VPJ))
#include "MCXA154_COMMON.h"
#elif (defined(CPU_MCXA155VFT) || defined(CPU_MCXA155VLH) || defined(CPU_MCXA155VLL) || defined(CPU_MCXA155VMP) || defined(CPU_MCXA155VPJ))
#include "MCXA155_COMMON.h"
#elif (defined(CPU_MCXA156VFT) || defined(CPU_MCXA156VLH) || defined(CPU_MCXA156VLL) || defined(CPU_MCXA156VMP) || defined(CPU_MCXA156VPJ))
#include "MCXA156_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(EIM_MEMORY_CHANNEL_T_)
#define EIM_MEMORY_CHANNEL_T_
/*!
 * @addtogroup eim_memory_channel
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_memory_channel
 *
 * Defines the structure for the EIM resource collections.
 */

typedef enum _eim_memory_channel
{
    kEIM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
} eim_memory_channel_t;

/* @} */
#endif /* EIM_MEMORY_CHANNEL_T_ */

#if !defined(EIM_ERROR_INJECTION_CHANNEL_ENABLE_T_)
#define EIM_ERROR_INJECTION_CHANNEL_ENABLE_T_
/*!
 * @addtogroup eim_error_injection_channel_enable
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the eim_error_injection_channel_enable
 *
 * Defines the structure for the EIM error injection resource collections.
 */

typedef enum _eim_error_injection_channel_enable
{
    kEIM_MemoryChannelRAMAEnable    = 0x80000000U, /**< Memory channel 0(RAMA0) error injection enable */
} eim_error_injection_channel_enable_t;

/* @} */
#endif /* EIM_ERROR_INJECTION_CHANNEL_ENABLE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
       uint8_t RESERVED_0[248];
  __IO uint32_t EICHD0_WORD0;                      /**< Error Injection Channel Descriptor 0, Word0, offset: 0x100 */
  __IO uint32_t EICHD0_WORD1;                      /**< Error Injection Channel Descriptor 0, Word1, offset: 0x104 */
} EIM_Type;

/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Register_Masks EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_EIMCR_GEIEN_MASK                     (0x1U)
#define EIM_EIMCR_GEIEN_SHIFT                    (0U)
/*! GEIEN - Global Error Injection Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define EIM_EIMCR_GEIEN(x)                       (((uint32_t)(((uint32_t)(x)) << EIM_EIMCR_GEIEN_SHIFT)) & EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_EICHEN_EICH0EN_MASK                  (0x80000000U)
#define EIM_EICHEN_EICH0EN_SHIFT                 (31U)
/*! EICH0EN - Error Injection Channel 0 Enable
 *  0b0..Error injection is disabled on Error Injection Channel 0
 *  0b1..Error injection is enabled on Error Injection Channel 0
 */
#define EIM_EICHEN_EICH0EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH0EN_SHIFT)) & EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHD0_WORD0 - Error Injection Channel Descriptor 0, Word0 */
/*! @{ */

#define EIM_EICHD0_WORD0_CHKBIT_MASK_MASK        (0xFE000000U)
#define EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT       (25U)
/*! CHKBIT_MASK - Checkbit Mask */
#define EIM_EICHD0_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHD0_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHD0_WORD1 - Error Injection Channel Descriptor 0, Word1 */
/*! @{ */

#define EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT     (0U)
/*! B0_3DATA_MASK - Data Mask Bytes 0-3 */
#define EIM_EICHD0_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHD0_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHD0_WORD1_B0_3DATA_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EIM_Register_Masks */


/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */


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


#endif  /* PERI_EIM_H_ */

