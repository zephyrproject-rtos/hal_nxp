/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t REMAP;                             /**< Data Remap, offset: 0x20 */
       uint8_t RESERVED_1[988];
  __IO uint32_t FCCR;                              /**< Flash Cache Control Register, offset: 0x400 */
  __IO uint32_t FCAR;                              /**< Flash Cache Access Register, offset: 0x404 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FCTG;                              /**< Flash Cache Tag, offset: 0x40C */
       uint8_t RESERVED_3[16];
  __IO uint32_t FCLN0;                             /**< Flash Cache Line Num0, offset: 0x420 */
  __IO uint32_t FCLN1;                             /**< Flash Cache Line Num1, offset: 0x424 */
  __IO uint32_t FCLN2;                             /**< Flash Cache Line Num2, offset: 0x428 */
  __IO uint32_t FCLN3;                             /**< Flash Cache Line Num3, offset: 0x42C */
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name REMAP - Data Remap */
/*! @{ */

#define FMC_REMAP_REMAPLK_MASK                   (0x1U)
#define FMC_REMAP_REMAPLK_SHIFT                  (0U)
/*! REMAPLK - Remap Lock Enable
 *  0b0..Lock disabled: can write to REMAP
 *  0b1..Lock enabled: cannot write to REMAP
 */
#define FMC_REMAP_REMAPLK(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_REMAPLK_SHIFT)) & FMC_REMAP_REMAPLK_MASK)

#define FMC_REMAP_LIM_MASK                       (0x7F0000U)
#define FMC_REMAP_LIM_SHIFT                      (16U)
/*! LIM - LIM Remapping Address */
#define FMC_REMAP_LIM(x)                         (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_LIM_SHIFT)) & FMC_REMAP_LIM_MASK)

#define FMC_REMAP_LIMDP_MASK                     (0x7F000000U)
#define FMC_REMAP_LIMDP_SHIFT                    (24U)
/*! LIMDP - LIMDP Remapping Address */
#define FMC_REMAP_LIMDP(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_REMAP_LIMDP_SHIFT)) & FMC_REMAP_LIMDP_MASK)
/*! @} */

/*! @name FCCR - Flash Cache Control Register */
/*! @{ */

#define FMC_FCCR_WAY_LOCK_MASK                   (0xFU)
#define FMC_FCCR_WAY_LOCK_SHIFT                  (0U)
/*! WAY_LOCK - Cache Way Lock */
#define FMC_FCCR_WAY_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << FMC_FCCR_WAY_LOCK_SHIFT)) & FMC_FCCR_WAY_LOCK_MASK)

#define FMC_FCCR_LOCK_MASK                       (0x80000000U)
#define FMC_FCCR_LOCK_SHIFT                      (31U)
/*! LOCK - Lock Flash Cache Control
 *  0b0..Unlock flash cache
 *  0b1..Lock flash cache
 */
#define FMC_FCCR_LOCK(x)                         (((uint32_t)(((uint32_t)(x)) << FMC_FCCR_LOCK_SHIFT)) & FMC_FCCR_LOCK_MASK)
/*! @} */

/*! @name FCAR - Flash Cache Access Register */
/*! @{ */

#define FMC_FCAR_CACHES_WAY_NUM_MASK             (0x3U)
#define FMC_FCAR_CACHES_WAY_NUM_SHIFT            (0U)
/*! CACHES_WAY_NUM - Flash Cache Way Number
 *  0b00..way0
 *  0b01..way1
 *  0b10..way2
 *  0b11..way3
 */
#define FMC_FCAR_CACHES_WAY_NUM(x)               (((uint32_t)(((uint32_t)(x)) << FMC_FCAR_CACHES_WAY_NUM_SHIFT)) & FMC_FCAR_CACHES_WAY_NUM_MASK)

#define FMC_FCAR_CACHES_SET_NUM_MASK             (0x10U)
#define FMC_FCAR_CACHES_SET_NUM_SHIFT            (4U)
/*! CACHES_SET_NUM - Flash Cache Set Number */
#define FMC_FCAR_CACHES_SET_NUM(x)               (((uint32_t)(((uint32_t)(x)) << FMC_FCAR_CACHES_SET_NUM_SHIFT)) & FMC_FCAR_CACHES_SET_NUM_MASK)

#define FMC_FCAR_TYPE_MASK                       (0xC0000000U)
#define FMC_FCAR_TYPE_SHIFT                      (30U)
/*! TYPE - Operation of cache type
 *  0b00..No access.
 *  0b01..Read flash cache - the associated tag, valid and the content of the cache line specified by
 *        CACHES_SET_NUM and CACHES_WAY_NUM of FCAR are copied to FCTG and FCLN0-3.
 *  0b10..Write flash cache - the associated tag, valid and the content of the flash cache line specified by
 *        CACHES_SET_NUM and CACHES_WAY_NUM of FCAR are modified based on FCTG and FCLN0-3.
 *  0b11..No access.
 */
#define FMC_FCAR_TYPE(x)                         (((uint32_t)(((uint32_t)(x)) << FMC_FCAR_TYPE_SHIFT)) & FMC_FCAR_TYPE_MASK)
/*! @} */

/*! @name FCTG - Flash Cache Tag */
/*! @{ */

#define FMC_FCTG_VALID_MASK                      (0x1U)
#define FMC_FCTG_VALID_SHIFT                     (0U)
/*! VALID - Cache line Valid
 *  0b0..Tag is invalid. Cache line's cache hit cannot be triggered by flash read operation.
 *  0b1..Tag is valid. Cache line's cache hit can be triggered by flash read operation.
 */
#define FMC_FCTG_VALID(x)                        (((uint32_t)(((uint32_t)(x)) << FMC_FCTG_VALID_SHIFT)) & FMC_FCTG_VALID_MASK)

#define FMC_FCTG_ADDRESS_MASK                    (0xFFFFC0U)
#define FMC_FCTG_ADDRESS_SHIFT                   (6U)
/*! ADDRESS - Cache line Tag, which corresponds to flash address[23:6] */
#define FMC_FCTG_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_FCTG_ADDRESS_SHIFT)) & FMC_FCTG_ADDRESS_MASK)
/*! @} */

/*! @name FCLN0 - Flash Cache Line Num0 */
/*! @{ */

#define FMC_FCLN0_DATAWxSyLM_MASK                (0xFFFFFFFFU)
#define FMC_FCLN0_DATAWxSyLM_SHIFT               (0U)
/*! DATAWxSyLM - Cache Line Data[31:0] */
#define FMC_FCLN0_DATAWxSyLM(x)                  (((uint32_t)(((uint32_t)(x)) << FMC_FCLN0_DATAWxSyLM_SHIFT)) & FMC_FCLN0_DATAWxSyLM_MASK)
/*! @} */

/*! @name FCLN1 - Flash Cache Line Num1 */
/*! @{ */

#define FMC_FCLN1_DATAWxSyML_MASK                (0xFFFFFFFFU)
#define FMC_FCLN1_DATAWxSyML_SHIFT               (0U)
/*! DATAWxSyML - Cache Line Data[63:32] */
#define FMC_FCLN1_DATAWxSyML(x)                  (((uint32_t)(((uint32_t)(x)) << FMC_FCLN1_DATAWxSyML_SHIFT)) & FMC_FCLN1_DATAWxSyML_MASK)
/*! @} */

/*! @name FCLN2 - Flash Cache Line Num2 */
/*! @{ */

#define FMC_FCLN2_DATAWxSyMU_MASK                (0xFFFFFFFFU)
#define FMC_FCLN2_DATAWxSyMU_SHIFT               (0U)
/*! DATAWxSyMU - Cache Line Data[95:64] */
#define FMC_FCLN2_DATAWxSyMU(x)                  (((uint32_t)(((uint32_t)(x)) << FMC_FCLN2_DATAWxSyMU_SHIFT)) & FMC_FCLN2_DATAWxSyMU_MASK)
/*! @} */

/*! @name FCLN3 - Flash Cache Line Num3 */
/*! @{ */

#define FMC_FCLN3_DATAWxSyUM_MASK                (0xFFFFFFFFU)
#define FMC_FCLN3_DATAWxSyUM_SHIFT               (0U)
/*! DATAWxSyUM - Cache Line Data[127:96] */
#define FMC_FCLN3_DATAWxSyUM(x)                  (((uint32_t)(((uint32_t)(x)) << FMC_FCLN3_DATAWxSyUM_SHIFT)) & FMC_FCLN3_DATAWxSyUM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


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


#endif  /* PERI_FMC_H_ */

