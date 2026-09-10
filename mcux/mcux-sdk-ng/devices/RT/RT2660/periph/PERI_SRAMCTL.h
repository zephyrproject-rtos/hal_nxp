/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SRAMCTL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_SRAMCTL.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for SRAMCTL
 *
 * CMSIS Peripheral Access Layer for SRAMCTL
 */

#if !defined(PERI_SRAMCTL_H_)
#define PERI_SRAMCTL_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- SRAMCTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAMCTL_Peripheral_Access_Layer SRAMCTL Peripheral Access Layer
 * @{
 */

/** SRAMCTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t RAMCR;                             /**< RAM Control, offset: 0x0 */
  __IO uint32_t RAMIAS;                            /**< RAM Initialization Address Start, offset: 0x4 */
  __IO uint32_t RAMIAE;                            /**< RAM Initialization Address End, offset: 0x8 */
  __IO uint32_t RAMSR;                             /**< RAM Status, offset: 0xC */
  __I  uint32_t RAMMEMA;                           /**< RAM ECC Address, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __I  uint32_t RAMSYSA;                           /**< RAM System Address, offset: 0x18 */
  __IO uint32_t RAMECCNT;                          /**< RAM Correctable Error Count, offset: 0x1C */
  __IO uint32_t RAMEID0;                           /**< RAM Error Injection Data 0, offset: 0x20 */
  __IO uint32_t RAMEID1;                           /**< RAM Error Injection Data 1, offset: 0x24 */
  __IO uint32_t RAMEIDC;                           /**< RAM Error Injection Data Control, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RAMEIA;                            /**< RAM Error Injection Base Address, offset: 0x30 */
  __IO uint32_t RAMEIAM;                           /**< RAM Error Injection Address Mask, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t RAMMAXA;                           /**< RAM Maximum-Value Address, offset: 0x40 */
       uint8_t RESERVED_3[60];
  __IO uint32_t RAMCR2;                            /**< RAM Control 2, offset: 0x80 */
} SRAMCTL_Type;

/* ----------------------------------------------------------------------------
   -- SRAMCTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRAMCTL_Register_Masks SRAMCTL Register Masks
 * @{
 */

/*! @name RAMCR - RAM Control */
/*! @{ */

#define SRAMCTL_RAMCR_INIT_MASK                  (0x1U)
#define SRAMCTL_RAMCR_INIT_SHIFT                 (0U)
/*! INIT - Initialization Request
 *  0b0..Not requested
 *  0b1..Requested
 */
#define SRAMCTL_RAMCR_INIT(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMCR_INIT_SHIFT)) & SRAMCTL_RAMCR_INIT_MASK)

#define SRAMCTL_RAMCR_IWS_MASK                   (0x6U)
#define SRAMCTL_RAMCR_IWS_SHIFT                  (1U)
/*! IWS - Initialization Wait States
 *  0b00..Zero
 *  0b01..One
 *  0b10..Two
 *  0b11..Three
 */
#define SRAMCTL_RAMCR_IWS(x)                     (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMCR_IWS_SHIFT)) & SRAMCTL_RAMCR_IWS_MASK)

#define SRAMCTL_RAMCR_INIT_SYSA_MASK             (0x100U)
#define SRAMCTL_RAMCR_INIT_SYSA_SHIFT            (8U)
/*! INIT_SYSA - Initialize With System Address
 *  0b0..Local
 *  0b1..System
 */
#define SRAMCTL_RAMCR_INIT_SYSA(x)               (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMCR_INIT_SYSA_SHIFT)) & SRAMCTL_RAMCR_INIT_SYSA_MASK)
/*! @} */

/*! @name RAMIAS - RAM Initialization Address Start */
/*! @{ */

#define SRAMCTL_RAMIAS_IAS_MASK                  (0xFFFFFFFFU)
#define SRAMCTL_RAMIAS_IAS_SHIFT                 (0U)
/*! IAS - Initialization Address Start */
#define SRAMCTL_RAMIAS_IAS(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMIAS_IAS_SHIFT)) & SRAMCTL_RAMIAS_IAS_MASK)
/*! @} */

/*! @name RAMIAE - RAM Initialization Address End */
/*! @{ */

#define SRAMCTL_RAMIAE_IAE_MASK                  (0xFFFFFFFFU)
#define SRAMCTL_RAMIAE_IAE_SHIFT                 (0U)
/*! IAE - Initialization Address End */
#define SRAMCTL_RAMIAE_IAE(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMIAE_IAE_SHIFT)) & SRAMCTL_RAMIAE_IAE_MASK)
/*! @} */

/*! @name RAMSR - RAM Status */
/*! @{ */

#define SRAMCTL_RAMSR_IDONE_MASK                 (0x1U)
#define SRAMCTL_RAMSR_IDONE_SHIFT                (0U)
/*! IDONE - Initialization Done
 *  0b0..An initialization was not requested, is in progress, or did not complete
 *  0b1..An initialization completed successfully
 */
#define SRAMCTL_RAMSR_IDONE(x)                   (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_IDONE_SHIFT)) & SRAMCTL_RAMSR_IDONE_MASK)

#define SRAMCTL_RAMSR_BUSERR_MASK                (0x2U)
#define SRAMCTL_RAMSR_BUSERR_SHIFT               (1U)
/*! BUSERR - Bus Error
 *  0b0..No error occurred since the last time this field was cleared
 *  0b1..An error occurred
 */
#define SRAMCTL_RAMSR_BUSERR(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_BUSERR_SHIFT)) & SRAMCTL_RAMSR_BUSERR_MASK)

#define SRAMCTL_RAMSR_IPEND_MASK                 (0x4U)
#define SRAMCTL_RAMSR_IPEND_SHIFT                (2U)
/*! IPEND - Initialization Pending
 *  0b0..Not in progress
 *  0b1..In progress
 */
#define SRAMCTL_RAMSR_IPEND(x)                   (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_IPEND_SHIFT)) & SRAMCTL_RAMSR_IPEND_MASK)

#define SRAMCTL_RAMSR_AVALID_MASK                (0x8U)
#define SRAMCTL_RAMSR_AVALID_SHIFT               (3U)
/*! AVALID - Addresses Valid
 *  0b0..Addresses do not correspond to an event
 *  0b1..Addresses correspond to an event
 */
#define SRAMCTL_RAMSR_AVALID(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_AVALID_SHIFT)) & SRAMCTL_RAMSR_AVALID_MASK)

#define SRAMCTL_RAMSR_AERR_MASK                  (0x20U)
#define SRAMCTL_RAMSR_AERR_SHIFT                 (5U)
/*! AERR - ECC Address Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define SRAMCTL_RAMSR_AERR(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_AERR_SHIFT)) & SRAMCTL_RAMSR_AERR_MASK)

#define SRAMCTL_RAMSR_MLTERR_MASK                (0x40U)
#define SRAMCTL_RAMSR_MLTERR_SHIFT               (6U)
/*! MLTERR - ECC Multi-Bit Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define SRAMCTL_RAMSR_MLTERR(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_MLTERR_SHIFT)) & SRAMCTL_RAMSR_MLTERR_MASK)

#define SRAMCTL_RAMSR_SGLERR_MASK                (0x80U)
#define SRAMCTL_RAMSR_SGLERR_SHIFT               (7U)
/*! SGLERR - ECC Single-Bit Error
 *  0b0..No error occurred
 *  0b1..An error occurred
 */
#define SRAMCTL_RAMSR_SGLERR(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_SGLERR_SHIFT)) & SRAMCTL_RAMSR_SGLERR_MASK)

#define SRAMCTL_RAMSR_SYND_MASK                  (0xFF00U)
#define SRAMCTL_RAMSR_SYND_SHIFT                 (8U)
/*! SYND - ECC Syndrome Value */
#define SRAMCTL_RAMSR_SYND(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_SYND_SHIFT)) & SRAMCTL_RAMSR_SYND_MASK)

#define SRAMCTL_RAMSR_EINFO_MASK                 (0xFF0000U)
#define SRAMCTL_RAMSR_EINFO_SHIFT                (16U)
/*! EINFO - Event Information */
#define SRAMCTL_RAMSR_EINFO(x)                   (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_EINFO_SHIFT)) & SRAMCTL_RAMSR_EINFO_MASK)

#define SRAMCTL_RAMSR_ERW_MASK                   (0x2000000U)
#define SRAMCTL_RAMSR_ERW_SHIFT                  (25U)
/*! ERW - Error for Read or Write Access
 *  0b0..Read
 *  0b1..Write
 */
#define SRAMCTL_RAMSR_ERW(x)                     (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSR_ERW_SHIFT)) & SRAMCTL_RAMSR_ERW_MASK)
/*! @} */

/*! @name RAMMEMA - RAM ECC Address */
/*! @{ */

#define SRAMCTL_RAMMEMA_MEMA_MASK                (0x1FFFFU)
#define SRAMCTL_RAMMEMA_MEMA_SHIFT               (0U)
/*! MEMA - RAM Bank Address */
#define SRAMCTL_RAMMEMA_MEMA(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMMEMA_MEMA_SHIFT)) & SRAMCTL_RAMMEMA_MEMA_MASK)

#define SRAMCTL_RAMMEMA_BANK_MASK                (0x1F00000U)
#define SRAMCTL_RAMMEMA_BANK_SHIFT               (20U)
/*! BANK - RAM Bank ID */
#define SRAMCTL_RAMMEMA_BANK(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMMEMA_BANK_SHIFT)) & SRAMCTL_RAMMEMA_BANK_MASK)
/*! @} */

/*! @name RAMSYSA - RAM System Address */
/*! @{ */

#define SRAMCTL_RAMSYSA_SYSA_MASK                (0xFFFFFFFFU)
#define SRAMCTL_RAMSYSA_SYSA_SHIFT               (0U)
/*! SYSA - System Address */
#define SRAMCTL_RAMSYSA_SYSA(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMSYSA_SYSA_SHIFT)) & SRAMCTL_RAMSYSA_SYSA_MASK)
/*! @} */

/*! @name RAMECCNT - RAM Correctable Error Count */
/*! @{ */

#define SRAMCTL_RAMECCNT_ECCNT_MASK              (0xFFU)
#define SRAMCTL_RAMECCNT_ECCNT_SHIFT             (0U)
/*! ECCNT - ECC Correctable Error Count */
#define SRAMCTL_RAMECCNT_ECCNT(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMECCNT_ECCNT_SHIFT)) & SRAMCTL_RAMECCNT_ECCNT_MASK)
/*! @} */

/*! @name RAMEID0 - RAM Error Injection Data 0 */
/*! @{ */

#define SRAMCTL_RAMEID0_EID_W0_MASK              (0xFFFFFFFFU)
#define SRAMCTL_RAMEID0_EID_W0_SHIFT             (0U)
/*! EID_W0 - Error Injection Data Word 0 */
#define SRAMCTL_RAMEID0_EID_W0(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEID0_EID_W0_SHIFT)) & SRAMCTL_RAMEID0_EID_W0_MASK)
/*! @} */

/*! @name RAMEID1 - RAM Error Injection Data 1 */
/*! @{ */

#define SRAMCTL_RAMEID1_EID_W1_MASK              (0xFFFFFFFFU)
#define SRAMCTL_RAMEID1_EID_W1_SHIFT             (0U)
/*! EID_W1 - Error Injection Data Word 1 */
#define SRAMCTL_RAMEID1_EID_W1(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEID1_EID_W1_SHIFT)) & SRAMCTL_RAMEID1_EID_W1_MASK)
/*! @} */

/*! @name RAMEIDC - RAM Error Injection Data Control */
/*! @{ */

#define SRAMCTL_RAMEIDC_EID_CKB_MASK             (0xFFU)
#define SRAMCTL_RAMEIDC_EID_CKB_SHIFT            (0U)
/*! EID_CKB - Error Injection Data Checkbits */
#define SRAMCTL_RAMEIDC_EID_CKB(x)               (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIDC_EID_CKB_SHIFT)) & SRAMCTL_RAMEIDC_EID_CKB_MASK)

#define SRAMCTL_RAMEIDC_EI_EN_MASK               (0x1000000U)
#define SRAMCTL_RAMEIDC_EI_EN_SHIFT              (24U)
/*! EI_EN - Error Injection Enable
 *  0b0..Memory
 *  0b1..Pipeline
 */
#define SRAMCTL_RAMEIDC_EI_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIDC_EI_EN_SHIFT)) & SRAMCTL_RAMEIDC_EI_EN_MASK)

#define SRAMCTL_RAMEIDC_EIA_EN_MASK              (0x40000000U)
#define SRAMCTL_RAMEIDC_EIA_EN_SHIFT             (30U)
/*! EIA_EN - Error Injection Address Enable
 *  0b0..Ignore RAMEIA and RAMEIAM
 *  0b1..Enable RAMEIA and RAMEIAM
 */
#define SRAMCTL_RAMEIDC_EIA_EN(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIDC_EIA_EN_SHIFT)) & SRAMCTL_RAMEIDC_EIA_EN_MASK)

#define SRAMCTL_RAMEIDC_EID_EN_MASK              (0x80000000U)
#define SRAMCTL_RAMEIDC_EID_EN_SHIFT             (31U)
/*! EID_EN - Error Injection Data Enable
 *  0b0..No injection
 *  0b1..Local injection
 */
#define SRAMCTL_RAMEIDC_EID_EN(x)                (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIDC_EID_EN_SHIFT)) & SRAMCTL_RAMEIDC_EID_EN_MASK)
/*! @} */

/*! @name RAMEIA - RAM Error Injection Base Address */
/*! @{ */

#define SRAMCTL_RAMEIA_EIA_MASK                  (0xFFFFFFFFU)
#define SRAMCTL_RAMEIA_EIA_SHIFT                 (0U)
/*! EIA - Error Injection Base Address */
#define SRAMCTL_RAMEIA_EIA(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIA_EIA_SHIFT)) & SRAMCTL_RAMEIA_EIA_MASK)
/*! @} */

/*! @name RAMEIAM - RAM Error Injection Address Mask */
/*! @{ */

#define SRAMCTL_RAMEIAM_EIAM_MASK                (0xFFFFFFFFU)
#define SRAMCTL_RAMEIAM_EIAM_SHIFT               (0U)
/*! EIAM - Error Injection Address Mask */
#define SRAMCTL_RAMEIAM_EIAM(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMEIAM_EIAM_SHIFT)) & SRAMCTL_RAMEIAM_EIAM_MASK)
/*! @} */

/*! @name RAMMAXA - RAM Maximum-Value Address */
/*! @{ */

#define SRAMCTL_RAMMAXA_MAXA_MASK                (0xFFFFFFFFU)
#define SRAMCTL_RAMMAXA_MAXA_SHIFT               (0U)
/*! MAXA - Maximum Address */
#define SRAMCTL_RAMMAXA_MAXA(x)                  (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMMAXA_MAXA_SHIFT)) & SRAMCTL_RAMMAXA_MAXA_MASK)
/*! @} */

/*! @name RAMCR2 - RAM Control 2 */
/*! @{ */

#define SRAMCTL_RAMCR2_DEM_MASK                  (0x8U)
#define SRAMCTL_RAMCR2_DEM_SHIFT                 (3U)
/*! DEM - Disable Exclusive Monitor
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define SRAMCTL_RAMCR2_DEM(x)                    (((uint32_t)(((uint32_t)(x)) << SRAMCTL_RAMCR2_DEM_SHIFT)) & SRAMCTL_RAMCR2_DEM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRAMCTL_Register_Masks */


/*!
 * @}
 */ /* end of group SRAMCTL_Peripheral_Access_Layer */


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


#endif  /* PERI_SRAMCTL_H_ */

