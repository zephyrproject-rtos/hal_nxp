/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NETC_PRIV
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NETC_PRIV.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NETC_PRIV
 *
 * CMSIS Peripheral Access Layer for NETC_PRIV
 */

#if !defined(PERI_NETC_PRIV_H_)
#define PERI_NETC_PRIV_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- NETC_PRIV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Peripheral_Access_Layer NETC_PRIV Peripheral Access Layer
 * @{
 */

/** NETC_PRIV - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t NETCRR;                            /**< NETC reset register, offset: 0x100 */
  __I  uint32_t NETCSR;                            /**< NETC status register, offset: 0x104 */
       uint8_t RESERVED_1[256];
  __IO uint32_t MEICR;                             /**< Memory Error Injection Config Register, offset: 0x208 */
       uint8_t RESERVED_2[3060];
  __IO uint32_t CMECR;                             /**< Correctable memory error configuration register, offset: 0xE00 */
  __IO uint32_t CMESR;                             /**< Correctable memory error status register, offset: 0xE04 */
       uint8_t RESERVED_3[4];
  __I  uint32_t CMECTR;                            /**< Correctable memory error count register, offset: 0xE0C */
       uint8_t RESERVED_4[32];
  __IO uint32_t UNMECR;                            /**< Uncorrectable non-fatal memory error configuration register, offset: 0xE30 */
  __IO uint32_t UNMESR0;                           /**< Uncorrectable non-fatal memory error status register 0, offset: 0xE34 */
  __I  uint32_t UNMESR1;                           /**< Uncorrectable non-fatal memory error status register 1, offset: 0xE38 */
  __I  uint32_t UNMECTR;                           /**< Uncorrectable non-fatal memory error count register, offset: 0xE3C */
  __IO uint32_t UFMECR;                            /**< Uncorrectable fatal memory error configuration register, offset: 0xE40 */
  __IO uint32_t UFMESR0;                           /**< Uncorrectable fatal memory error status register 0, offset: 0xE44 */
  __I  uint32_t UFMESR1;                           /**< Uncorrectable fatal memory error status register 1, offset: 0xE48 */
} NETC_PRIV_Type;

/* ----------------------------------------------------------------------------
   -- NETC_PRIV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PRIV_Register_Masks NETC_PRIV Register Masks
 * @{
 */

/*! @name NETCRR - NETC reset register */
/*! @{ */

#define NETC_PRIV_NETCRR_SR_MASK                 (0x1U)
#define NETC_PRIV_NETCRR_SR_SHIFT                (0U)
/*! SR - Soft reset */
#define NETC_PRIV_NETCRR_SR(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_SR_SHIFT)) & NETC_PRIV_NETCRR_SR_MASK)

#define NETC_PRIV_NETCRR_LOCK_MASK               (0x2U)
#define NETC_PRIV_NETCRR_LOCK_SHIFT              (1U)
/*! LOCK - Lock */
#define NETC_PRIV_NETCRR_LOCK(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCRR_LOCK_SHIFT)) & NETC_PRIV_NETCRR_LOCK_MASK)
/*! @} */

/*! @name NETCSR - NETC status register */
/*! @{ */

#define NETC_PRIV_NETCSR_ERROR_MASK              (0x1U)
#define NETC_PRIV_NETCSR_ERROR_SHIFT             (0U)
/*! ERROR - Error */
#define NETC_PRIV_NETCSR_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_ERROR_SHIFT)) & NETC_PRIV_NETCSR_ERROR_MASK)

#define NETC_PRIV_NETCSR_STATE_MASK              (0x2U)
#define NETC_PRIV_NETCSR_STATE_SHIFT             (1U)
/*! STATE - Indicates NETC's global operational state */
#define NETC_PRIV_NETCSR_STATE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_NETCSR_STATE_SHIFT)) & NETC_PRIV_NETCSR_STATE_MASK)
/*! @} */

/*! @name MEICR - Memory Error Injection Config Register */
/*! @{ */

#define NETC_PRIV_MEICR_MEM_ID_MASK              (0x1FU)
#define NETC_PRIV_MEICR_MEM_ID_SHIFT             (0U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_MEICR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_MEM_ID_SHIFT)) & NETC_PRIV_MEICR_MEM_ID_MASK)

#define NETC_PRIV_MEICR_ARM_MASK                 (0xC00000U)
#define NETC_PRIV_MEICR_ARM_SHIFT                (22U)
/*! ARM - Armed */
#define NETC_PRIV_MEICR_ARM(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_ARM_SHIFT)) & NETC_PRIV_MEICR_ARM_MASK)

#define NETC_PRIV_MEICR_EN_MASK                  (0xFF000000U)
#define NETC_PRIV_MEICR_EN_SHIFT                 (24U)
/*! EN - Enable */
#define NETC_PRIV_MEICR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_MEICR_EN_SHIFT)) & NETC_PRIV_MEICR_EN_MASK)
/*! @} */

/*! @name CMECR - Correctable memory error configuration register */
/*! @{ */

#define NETC_PRIV_CMECR_THRESHOLD_MASK           (0xFFU)
#define NETC_PRIV_CMECR_THRESHOLD_SHIFT          (0U)
/*! THRESHOLD - Threshold */
#define NETC_PRIV_CMECR_THRESHOLD(x)             (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECR_THRESHOLD_SHIFT)) & NETC_PRIV_CMECR_THRESHOLD_MASK)
/*! @} */

/*! @name CMESR - Correctable memory error status register */
/*! @{ */

#define NETC_PRIV_CMESR_MEM_ID_MASK              (0x1F0000U)
#define NETC_PRIV_CMESR_MEM_ID_SHIFT             (16U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_CMESR_MEM_ID(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_MEM_ID_SHIFT)) & NETC_PRIV_CMESR_MEM_ID_MASK)

#define NETC_PRIV_CMESR_SBEE_MASK                (0x80000000U)
#define NETC_PRIV_CMESR_SBEE_SHIFT               (31U)
/*! SBEE - Single-bit ECC error */
#define NETC_PRIV_CMESR_SBEE(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMESR_SBEE_SHIFT)) & NETC_PRIV_CMESR_SBEE_MASK)
/*! @} */

/*! @name CMECTR - Correctable memory error count register */
/*! @{ */

#define NETC_PRIV_CMECTR_COUNT_MASK              (0xFFU)
#define NETC_PRIV_CMECTR_COUNT_SHIFT             (0U)
/*! COUNT - Count */
#define NETC_PRIV_CMECTR_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_CMECTR_COUNT_SHIFT)) & NETC_PRIV_CMECTR_COUNT_MASK)
/*! @} */

/*! @name UNMECR - Uncorrectable non-fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UNMECR_THRESHOLD_MASK          (0xFFU)
#define NETC_PRIV_UNMECR_THRESHOLD_SHIFT         (0U)
/*! THRESHOLD - Threshold */
#define NETC_PRIV_UNMECR_THRESHOLD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_THRESHOLD_SHIFT)) & NETC_PRIV_UNMECR_THRESHOLD_MASK)

#define NETC_PRIV_UNMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UNMECR_RD_SHIFT                (31U)
/*! RD - Report disable */
#define NETC_PRIV_UNMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECR_RD_SHIFT)) & NETC_PRIV_UNMECR_RD_MASK)
/*! @} */

/*! @name UNMESR0 - Uncorrectable non-fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UNMESR0_SYNDROME_MASK          (0x7FFU)
#define NETC_PRIV_UNMESR0_SYNDROME_SHIFT         (0U)
/*! SYNDROME - Syndrome */
#define NETC_PRIV_UNMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UNMESR0_SYNDROME_MASK)

#define NETC_PRIV_UNMESR0_MEM_ID_MASK            (0x1F0000U)
#define NETC_PRIV_UNMESR0_MEM_ID_SHIFT           (16U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_UNMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UNMESR0_MEM_ID_MASK)

#define NETC_PRIV_UNMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UNMESR0_MBEE_SHIFT             (31U)
/*! MBEE - Multi-bit ECC error */
#define NETC_PRIV_UNMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR0_MBEE_SHIFT)) & NETC_PRIV_UNMESR0_MBEE_MASK)
/*! @} */

/*! @name UNMESR1 - Uncorrectable non-fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UNMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UNMESR1_ADDR_SHIFT             (0U)
/*! ADDR - Address */
#define NETC_PRIV_UNMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMESR1_ADDR_SHIFT)) & NETC_PRIV_UNMESR1_ADDR_MASK)
/*! @} */

/*! @name UNMECTR - Uncorrectable non-fatal memory error count register */
/*! @{ */

#define NETC_PRIV_UNMECTR_COUNT_MASK             (0xFFU)
#define NETC_PRIV_UNMECTR_COUNT_SHIFT            (0U)
/*! COUNT - Count */
#define NETC_PRIV_UNMECTR_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UNMECTR_COUNT_SHIFT)) & NETC_PRIV_UNMECTR_COUNT_MASK)
/*! @} */

/*! @name UFMECR - Uncorrectable fatal memory error configuration register */
/*! @{ */

#define NETC_PRIV_UFMECR_RD_MASK                 (0x80000000U)
#define NETC_PRIV_UFMECR_RD_SHIFT                (31U)
/*! RD - Report disable */
#define NETC_PRIV_UFMECR_RD(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMECR_RD_SHIFT)) & NETC_PRIV_UFMECR_RD_MASK)
/*! @} */

/*! @name UFMESR0 - Uncorrectable fatal memory error status register 0 */
/*! @{ */

#define NETC_PRIV_UFMESR0_SYNDROME_MASK          (0x7FFU)
#define NETC_PRIV_UFMESR0_SYNDROME_SHIFT         (0U)
/*! SYNDROME - Syndrome */
#define NETC_PRIV_UFMESR0_SYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_SYNDROME_SHIFT)) & NETC_PRIV_UFMESR0_SYNDROME_MASK)

#define NETC_PRIV_UFMESR0_MEM_ID_MASK            (0x1F0000U)
#define NETC_PRIV_UFMESR0_MEM_ID_SHIFT           (16U)
/*! MEM_ID - Memory ID */
#define NETC_PRIV_UFMESR0_MEM_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MEM_ID_SHIFT)) & NETC_PRIV_UFMESR0_MEM_ID_MASK)

#define NETC_PRIV_UFMESR0_M_MASK                 (0x40000000U)
#define NETC_PRIV_UFMESR0_M_SHIFT                (30U)
/*! M - Multiple */
#define NETC_PRIV_UFMESR0_M(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_M_SHIFT)) & NETC_PRIV_UFMESR0_M_MASK)

#define NETC_PRIV_UFMESR0_MBEE_MASK              (0x80000000U)
#define NETC_PRIV_UFMESR0_MBEE_SHIFT             (31U)
/*! MBEE - Multi-bit ECC error */
#define NETC_PRIV_UFMESR0_MBEE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR0_MBEE_SHIFT)) & NETC_PRIV_UFMESR0_MBEE_MASK)
/*! @} */

/*! @name UFMESR1 - Uncorrectable fatal memory error status register 1 */
/*! @{ */

#define NETC_PRIV_UFMESR1_ADDR_MASK              (0xFFFFFFFFU)
#define NETC_PRIV_UFMESR1_ADDR_SHIFT             (0U)
/*! ADDR - Address */
#define NETC_PRIV_UFMESR1_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << NETC_PRIV_UFMESR1_ADDR_SHIFT)) & NETC_PRIV_UFMESR1_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_PRIV_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_PRIV_Peripheral_Access_Layer */


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


#endif  /* PERI_NETC_PRIV_H_ */

