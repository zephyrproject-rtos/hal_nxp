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
**     Version:             rev. 1.0, 2022-03-29
**     Build:               b241120
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ERM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-29)
**         Initial version based on v0.1UM
**
** ###################################################################
*/

/*!
 * @file ERM.h
 * @version 1.0
 * @date 2022-03-29
 * @brief CMSIS Peripheral Access Layer for ERM
 *
 * CMSIS Peripheral Access Layer for ERM
 */

#if !defined(ERM_H_)
#define ERM_H_                                   /**< Symbol preventing repeated inclusion */

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
#if !defined(ERM_MEMORY_CHANNEL_T_)
#define ERM_MEMORY_CHANNEL_T_
/*!
 * @addtogroup erm_memory_channel
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the erm_memory_channel
 *
 * Defines the structure for the ERM resource collections.
 */

typedef enum _erm_memory_channel
{
    kERM_MemoryChannelRAMA0         = 0U,          /**< Memory RAMA0 */
    kERM_MemoryChannelFLASH         = 1U,          /**< Memory FLASH */
} erm_memory_channel_t;

/* @} */
#endif /* ERM_MEMORY_CHANNEL_T_ */


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
   -- ERM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Peripheral_Access_Layer ERM Peripheral Access Layer
 * @{
 */

/** ERM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR0;                               /**< ERM Configuration Register 0, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t SR0;                               /**< ERM Status Register 0, offset: 0x10 */
       uint8_t RESERVED_1[236];
  __I  uint32_t EAR0;                              /**< ERM Memory 0 Error Address Register, offset: 0x100 */
  __I  uint32_t SYN0;                              /**< ERM Memory 0 Syndrome Register, offset: 0x104 */
  __IO uint32_t CORR_ERR_CNT0;                     /**< ERM Memory 0 Correctable Error Count Register, offset: 0x108 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CORR_ERR_CNT1;                     /**< ERM Memory 1 Correctable Error Count Register, offset: 0x118 */
} ERM_Type;

/* ----------------------------------------------------------------------------
   -- ERM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ERM_Register_Masks ERM Register Masks
 * @{
 */

/*! @name CR0 - ERM Configuration Register 0 */
/*! @{ */

#define ERM_CR0_ENCIE1_MASK                      (0x4000000U)
#define ERM_CR0_ENCIE1_SHIFT                     (26U)
/*! ENCIE1 - ENCIE1
 *  0b0..Interrupt notification of Memory 1 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 1 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE1(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE1_SHIFT)) & ERM_CR0_ENCIE1_MASK)

#define ERM_CR0_ESCIE1_MASK                      (0x8000000U)
#define ERM_CR0_ESCIE1_SHIFT                     (27U)
/*! ESCIE1 - ESCIE1
 *  0b0..Interrupt notification of Memory 1 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 1 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE1(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE1_SHIFT)) & ERM_CR0_ESCIE1_MASK)

#define ERM_CR0_ENCIE0_MASK                      (0x40000000U)
#define ERM_CR0_ENCIE0_SHIFT                     (30U)
/*! ENCIE0 - ENCIE0
 *  0b0..Interrupt notification of Memory 0 non-correctable error events is disabled.
 *  0b1..Interrupt notification of Memory 0 non-correctable error events is enabled.
 */
#define ERM_CR0_ENCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ENCIE0_SHIFT)) & ERM_CR0_ENCIE0_MASK)

#define ERM_CR0_ESCIE0_MASK                      (0x80000000U)
#define ERM_CR0_ESCIE0_SHIFT                     (31U)
/*! ESCIE0 - ESCIE0
 *  0b0..Interrupt notification of Memory 0 single-bit correction events is disabled.
 *  0b1..Interrupt notification of Memory 0 single-bit correction events is enabled.
 */
#define ERM_CR0_ESCIE0(x)                        (((uint32_t)(((uint32_t)(x)) << ERM_CR0_ESCIE0_SHIFT)) & ERM_CR0_ESCIE0_MASK)
/*! @} */

/*! @name SR0 - ERM Status Register 0 */
/*! @{ */

#define ERM_SR0_NCE1_MASK                        (0x4000000U)
#define ERM_SR0_NCE1_SHIFT                       (26U)
/*! NCE1 - NCE1
 *  0b0..No non-correctable error event on Memory 1 detected.
 *  0b1..Non-correctable error event on Memory 1 detected.
 */
#define ERM_SR0_NCE1(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE1_SHIFT)) & ERM_SR0_NCE1_MASK)

#define ERM_SR0_SBC1_MASK                        (0x8000000U)
#define ERM_SR0_SBC1_SHIFT                       (27U)
/*! SBC1 - SBC1
 *  0b0..No single-bit correction event on Memory 1 detected.
 *  0b1..Single-bit correction event on Memory 1 detected.
 */
#define ERM_SR0_SBC1(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC1_SHIFT)) & ERM_SR0_SBC1_MASK)

#define ERM_SR0_NCE0_MASK                        (0x40000000U)
#define ERM_SR0_NCE0_SHIFT                       (30U)
/*! NCE0 - NCE0
 *  0b0..No non-correctable error event on Memory 0 detected.
 *  0b1..Non-correctable error event on Memory 0 detected.
 */
#define ERM_SR0_NCE0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_NCE0_SHIFT)) & ERM_SR0_NCE0_MASK)

#define ERM_SR0_SBC0_MASK                        (0x80000000U)
#define ERM_SR0_SBC0_SHIFT                       (31U)
/*! SBC0 - SBC0
 *  0b0..No single-bit correction event on Memory 0 detected.
 *  0b1..Single-bit correction event on Memory 0 detected.
 */
#define ERM_SR0_SBC0(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_SR0_SBC0_SHIFT)) & ERM_SR0_SBC0_MASK)
/*! @} */

/*! @name EAR0 - ERM Memory 0 Error Address Register */
/*! @{ */

#define ERM_EAR0_EAR_MASK                        (0xFFFFFFFFU)
#define ERM_EAR0_EAR_SHIFT                       (0U)
/*! EAR - EAR */
#define ERM_EAR0_EAR(x)                          (((uint32_t)(((uint32_t)(x)) << ERM_EAR0_EAR_SHIFT)) & ERM_EAR0_EAR_MASK)
/*! @} */

/*! @name SYN0 - ERM Memory 0 Syndrome Register */
/*! @{ */

#define ERM_SYN0_SYNDROME_MASK                   (0xFF000000U)
#define ERM_SYN0_SYNDROME_SHIFT                  (24U)
/*! SYNDROME - SYNDROME */
#define ERM_SYN0_SYNDROME(x)                     (((uint32_t)(((uint32_t)(x)) << ERM_SYN0_SYNDROME_SHIFT)) & ERM_SYN0_SYNDROME_MASK)
/*! @} */

/*! @name CORR_ERR_CNT0 - ERM Memory 0 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT0_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT0_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT0_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT0_COUNT_SHIFT)) & ERM_CORR_ERR_CNT0_COUNT_MASK)
/*! @} */

/*! @name CORR_ERR_CNT1 - ERM Memory 1 Correctable Error Count Register */
/*! @{ */

#define ERM_CORR_ERR_CNT1_COUNT_MASK             (0xFFU)
#define ERM_CORR_ERR_CNT1_COUNT_SHIFT            (0U)
/*! COUNT - Memory n Correctable Error Count */
#define ERM_CORR_ERR_CNT1_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << ERM_CORR_ERR_CNT1_COUNT_SHIFT)) & ERM_CORR_ERR_CNT1_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ERM_Register_Masks */


/*!
 * @}
 */ /* end of group ERM_Peripheral_Access_Layer */


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


#endif  /* ERM_H_ */

