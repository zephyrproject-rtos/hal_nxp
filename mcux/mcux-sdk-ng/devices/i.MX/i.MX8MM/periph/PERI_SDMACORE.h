/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDMACORE
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SDMACORE.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SDMACORE
 *
 * CMSIS Peripheral Access Layer for SDMACORE
 */

#if !defined(PERI_SDMACORE_H_)
#define PERI_SDMACORE_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- SDMACORE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMACORE_Peripheral_Access_Layer SDMACORE Peripheral Access Layer
 * @{
 */

/** SDMACORE - Register Layout Typedef */
typedef struct {
  __I  uint32_t MC0PTR;                            /**< Arm platform Channel 0 Pointer, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t CCPTR;                             /**< Current Channel Pointer, offset: 0x8 */
  __I  uint32_t CCR;                               /**< Current Channel Register, offset: 0xC */
  __I  uint32_t NCR;                               /**< Highest Pending Channel Register, offset: 0x10 */
  __I  uint32_t EVENTS;                            /**< External DMA Requests Mirror, offset: 0x14 */
  __I  uint32_t CCPRI;                             /**< Current Channel Priority, offset: 0x18 */
  __I  uint32_t NCPRI;                             /**< Next Channel Priority, offset: 0x1C */
  __IO uint32_t ECOUNT;                            /**< OnCE Event Cell Counter, offset: 0x20 */
  __IO uint32_t ECTL;                              /**< OnCE Event Cell Control Register, offset: 0x24 */
  __IO uint32_t EAA;                               /**< OnCE Event Address Register A, offset: 0x28 */
  __IO uint32_t EAB;                               /**< OnCE Event Cell Address Register B, offset: 0x2C */
  __IO uint32_t EAM;                               /**< OnCE Event Cell Address Mask, offset: 0x30 */
  __IO uint32_t ED;                                /**< OnCE Event Cell Data Register, offset: 0x34 */
  __IO uint32_t EDM;                               /**< OnCE Event Cell Data Mask, offset: 0x38 */
  __IO uint32_t RTB;                               /**< OnCE Real-Time Buffer, offset: 0x3C */
  __I  uint32_t TB;                                /**< OnCE Trace Buffer, offset: 0x40 */
  __I  uint32_t OSTAT;                             /**< OnCE Status, offset: 0x44 */
  __I  uint32_t MCHN0ADDR;                         /**< Channel 0 Boot Address, offset: 0x48 */
  __I  uint32_t ENDIANNESS;                        /**< ENDIAN Status Register, offset: 0x4C */
       uint8_t RESERVED_1[4];
  __I  uint32_t SDMA_LOCK;                         /**< Lock Status Register, offset: 0x54 */
  __I  uint32_t EVENTS2;                           /**< External DMA Requests Mirror #2, offset: 0x58 */
} SDMACORE_Type;

/* ----------------------------------------------------------------------------
   -- SDMACORE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMACORE_Register_Masks SDMACORE Register Masks
 * @{
 */

/*! @name MC0PTR - Arm platform Channel 0 Pointer */
/*! @{ */

#define SDMACORE_MC0PTR_MC0PTR_MASK              (0xFFFFFFFFU)
#define SDMACORE_MC0PTR_MC0PTR_SHIFT             (0U)
#define SDMACORE_MC0PTR_MC0PTR(x)                (((uint32_t)(((uint32_t)(x)) << SDMACORE_MC0PTR_MC0PTR_SHIFT)) & SDMACORE_MC0PTR_MC0PTR_MASK)
/*! @} */

/*! @name CCPTR - Current Channel Pointer */
/*! @{ */

#define SDMACORE_CCPTR_CCPTR_MASK                (0xFFFFU)
#define SDMACORE_CCPTR_CCPTR_SHIFT               (0U)
#define SDMACORE_CCPTR_CCPTR(x)                  (((uint32_t)(((uint32_t)(x)) << SDMACORE_CCPTR_CCPTR_SHIFT)) & SDMACORE_CCPTR_CCPTR_MASK)
/*! @} */

/*! @name CCR - Current Channel Register */
/*! @{ */

#define SDMACORE_CCR_CCR_MASK                    (0x1FU)
#define SDMACORE_CCR_CCR_SHIFT                   (0U)
#define SDMACORE_CCR_CCR(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_CCR_CCR_SHIFT)) & SDMACORE_CCR_CCR_MASK)
/*! @} */

/*! @name NCR - Highest Pending Channel Register */
/*! @{ */

#define SDMACORE_NCR_NCR_MASK                    (0x1FU)
#define SDMACORE_NCR_NCR_SHIFT                   (0U)
#define SDMACORE_NCR_NCR(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_NCR_NCR_SHIFT)) & SDMACORE_NCR_NCR_MASK)
/*! @} */

/*! @name EVENTS - External DMA Requests Mirror */
/*! @{ */

#define SDMACORE_EVENTS_EVENTS_MASK              (0xFFFFFFFFU)
#define SDMACORE_EVENTS_EVENTS_SHIFT             (0U)
#define SDMACORE_EVENTS_EVENTS(x)                (((uint32_t)(((uint32_t)(x)) << SDMACORE_EVENTS_EVENTS_SHIFT)) & SDMACORE_EVENTS_EVENTS_MASK)
/*! @} */

/*! @name CCPRI - Current Channel Priority */
/*! @{ */

#define SDMACORE_CCPRI_CCPRI_MASK                (0x7U)
#define SDMACORE_CCPRI_CCPRI_SHIFT               (0U)
/*! CCPRI
 *  0b000..no running channel
 */
#define SDMACORE_CCPRI_CCPRI(x)                  (((uint32_t)(((uint32_t)(x)) << SDMACORE_CCPRI_CCPRI_SHIFT)) & SDMACORE_CCPRI_CCPRI_MASK)
/*! @} */

/*! @name NCPRI - Next Channel Priority */
/*! @{ */

#define SDMACORE_NCPRI_NCPRI_MASK                (0x7U)
#define SDMACORE_NCPRI_NCPRI_SHIFT               (0U)
#define SDMACORE_NCPRI_NCPRI(x)                  (((uint32_t)(((uint32_t)(x)) << SDMACORE_NCPRI_NCPRI_SHIFT)) & SDMACORE_NCPRI_NCPRI_MASK)
/*! @} */

/*! @name ECOUNT - OnCE Event Cell Counter */
/*! @{ */

#define SDMACORE_ECOUNT_ECOUNT_MASK              (0xFFFFU)
#define SDMACORE_ECOUNT_ECOUNT_SHIFT             (0U)
#define SDMACORE_ECOUNT_ECOUNT(x)                (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECOUNT_ECOUNT_SHIFT)) & SDMACORE_ECOUNT_ECOUNT_MASK)
/*! @} */

/*! @name ECTL - OnCE Event Cell Control Register */
/*! @{ */

#define SDMACORE_ECTL_ATS_MASK                   (0x3U)
#define SDMACORE_ECTL_ATS_SHIFT                  (0U)
/*! ATS
 *  0b00..read ONLY
 *  0b01..write ONLY
 *  0b10..read or write
 *  0b11..-
 */
#define SDMACORE_ECTL_ATS(x)                     (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_ATS_SHIFT)) & SDMACORE_ECTL_ATS_MASK)

#define SDMACORE_ECTL_AATC_MASK                  (0xCU)
#define SDMACORE_ECTL_AATC_SHIFT                 (2U)
/*! AATC
 *  0b00..equal
 *  0b01..not equal
 *  0b10..greater than
 *  0b11..less than
 */
#define SDMACORE_ECTL_AATC(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_AATC_SHIFT)) & SDMACORE_ECTL_AATC_MASK)

#define SDMACORE_ECTL_ABTC_MASK                  (0x30U)
#define SDMACORE_ECTL_ABTC_SHIFT                 (4U)
/*! ABTC
 *  0b00..equal
 *  0b01..not equal
 *  0b10..greater than
 *  0b11..less than
 */
#define SDMACORE_ECTL_ABTC(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_ABTC_SHIFT)) & SDMACORE_ECTL_ABTC_MASK)

#define SDMACORE_ECTL_ATC_MASK                   (0xC0U)
#define SDMACORE_ECTL_ATC_SHIFT                  (6U)
/*! ATC
 *  0b00..addressA ONLY
 *  0b01..addrA AND addrB
 *  0b10..addrA OR addrB
 *  0b11..reserved
 */
#define SDMACORE_ECTL_ATC(x)                     (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_ATC_SHIFT)) & SDMACORE_ECTL_ATC_MASK)

#define SDMACORE_ECTL_DTC_MASK                   (0x300U)
#define SDMACORE_ECTL_DTC_SHIFT                  (8U)
/*! DTC
 *  0b00..equal
 *  0b01..not equal
 *  0b10..greater than
 *  0b11..less than
 */
#define SDMACORE_ECTL_DTC(x)                     (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_DTC_SHIFT)) & SDMACORE_ECTL_DTC_MASK)

#define SDMACORE_ECTL_ECTC_MASK                  (0xC00U)
#define SDMACORE_ECTL_ECTC_SHIFT                 (10U)
/*! ECTC
 *  0b00..address ONLY
 *  0b01..data ONLY
 *  0b10..address AND data
 *  0b11..address OR data
 */
#define SDMACORE_ECTL_ECTC(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_ECTC_SHIFT)) & SDMACORE_ECTL_ECTC_MASK)

#define SDMACORE_ECTL_CNT_MASK                   (0x1000U)
#define SDMACORE_ECTL_CNT_SHIFT                  (12U)
/*! CNT
 *  0b0..Counter is disabled.
 *  0b1..Counter is enabled.
 */
#define SDMACORE_ECTL_CNT(x)                     (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_CNT_SHIFT)) & SDMACORE_ECTL_CNT_MASK)

#define SDMACORE_ECTL_EN_MASK                    (0x2000U)
#define SDMACORE_ECTL_EN_SHIFT                   (13U)
/*! EN
 *  0b0..Cell is disabled.
 *  0b1..Cell is enabled.
 */
#define SDMACORE_ECTL_EN(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_ECTL_EN_SHIFT)) & SDMACORE_ECTL_EN_MASK)
/*! @} */

/*! @name EAA - OnCE Event Address Register A */
/*! @{ */

#define SDMACORE_EAA_EAA_MASK                    (0xFFFFU)
#define SDMACORE_EAA_EAA_SHIFT                   (0U)
#define SDMACORE_EAA_EAA(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_EAA_EAA_SHIFT)) & SDMACORE_EAA_EAA_MASK)
/*! @} */

/*! @name EAB - OnCE Event Cell Address Register B */
/*! @{ */

#define SDMACORE_EAB_EAB_MASK                    (0xFFFFU)
#define SDMACORE_EAB_EAB_SHIFT                   (0U)
#define SDMACORE_EAB_EAB(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_EAB_EAB_SHIFT)) & SDMACORE_EAB_EAB_MASK)
/*! @} */

/*! @name EAM - OnCE Event Cell Address Mask */
/*! @{ */

#define SDMACORE_EAM_EAM_MASK                    (0xFFFFU)
#define SDMACORE_EAM_EAM_SHIFT                   (0U)
#define SDMACORE_EAM_EAM(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_EAM_EAM_SHIFT)) & SDMACORE_EAM_EAM_MASK)
/*! @} */

/*! @name ED - OnCE Event Cell Data Register */
/*! @{ */

#define SDMACORE_ED_ED_MASK                      (0xFFFFFFFFU)
#define SDMACORE_ED_ED_SHIFT                     (0U)
#define SDMACORE_ED_ED(x)                        (((uint32_t)(((uint32_t)(x)) << SDMACORE_ED_ED_SHIFT)) & SDMACORE_ED_ED_MASK)
/*! @} */

/*! @name EDM - OnCE Event Cell Data Mask */
/*! @{ */

#define SDMACORE_EDM_EDM_MASK                    (0xFFFFFFFFU)
#define SDMACORE_EDM_EDM_SHIFT                   (0U)
#define SDMACORE_EDM_EDM(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_EDM_EDM_SHIFT)) & SDMACORE_EDM_EDM_MASK)
/*! @} */

/*! @name RTB - OnCE Real-Time Buffer */
/*! @{ */

#define SDMACORE_RTB_RTB_MASK                    (0xFFFFFFFFU)
#define SDMACORE_RTB_RTB_SHIFT                   (0U)
#define SDMACORE_RTB_RTB(x)                      (((uint32_t)(((uint32_t)(x)) << SDMACORE_RTB_RTB_SHIFT)) & SDMACORE_RTB_RTB_MASK)
/*! @} */

/*! @name TB - OnCE Trace Buffer */
/*! @{ */

#define SDMACORE_TB_CHFADDR_MASK                 (0x3FFFU)
#define SDMACORE_TB_CHFADDR_SHIFT                (0U)
#define SDMACORE_TB_CHFADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SDMACORE_TB_CHFADDR_SHIFT)) & SDMACORE_TB_CHFADDR_MASK)

#define SDMACORE_TB_TADDR_MASK                   (0xFFFC000U)
#define SDMACORE_TB_TADDR_SHIFT                  (14U)
#define SDMACORE_TB_TADDR(x)                     (((uint32_t)(((uint32_t)(x)) << SDMACORE_TB_TADDR_SHIFT)) & SDMACORE_TB_TADDR_MASK)

#define SDMACORE_TB_TBF_MASK                     (0x10000000U)
#define SDMACORE_TB_TBF_SHIFT                    (28U)
/*! TBF
 *  0b0..Invalid information
 *  0b1..Valid information
 */
#define SDMACORE_TB_TBF(x)                       (((uint32_t)(((uint32_t)(x)) << SDMACORE_TB_TBF_SHIFT)) & SDMACORE_TB_TBF_MASK)
/*! @} */

/*! @name OSTAT - OnCE Status */
/*! @{ */

#define SDMACORE_OSTAT_ECDR_MASK                 (0x7U)
#define SDMACORE_OSTAT_ECDR_SHIFT                (0U)
/*! ECDR
 *  0b000..1 matched addressA condition
 *  0b001..1 matched addressB condition
 *  0b010..1 matched data condition
 */
#define SDMACORE_OSTAT_ECDR(x)                   (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_ECDR_SHIFT)) & SDMACORE_OSTAT_ECDR_MASK)

#define SDMACORE_OSTAT_MST_MASK                  (0x80U)
#define SDMACORE_OSTAT_MST_SHIFT                 (7U)
/*! MST
 *  0b0..JTAG interface controls the OnCE.
 *  0b1..Arm platform peripheral interface controls the OnCE.
 */
#define SDMACORE_OSTAT_MST(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_MST_SHIFT)) & SDMACORE_OSTAT_MST_MASK)

#define SDMACORE_OSTAT_SWB_MASK                  (0x100U)
#define SDMACORE_OSTAT_SWB_SHIFT                 (8U)
#define SDMACORE_OSTAT_SWB(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_SWB_SHIFT)) & SDMACORE_OSTAT_SWB_MASK)

#define SDMACORE_OSTAT_ODR_MASK                  (0x200U)
#define SDMACORE_OSTAT_ODR_SHIFT                 (9U)
#define SDMACORE_OSTAT_ODR(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_ODR_SHIFT)) & SDMACORE_OSTAT_ODR_MASK)

#define SDMACORE_OSTAT_EDR_MASK                  (0x400U)
#define SDMACORE_OSTAT_EDR_SHIFT                 (10U)
#define SDMACORE_OSTAT_EDR(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_EDR_SHIFT)) & SDMACORE_OSTAT_EDR_MASK)

#define SDMACORE_OSTAT_RCV_MASK                  (0x800U)
#define SDMACORE_OSTAT_RCV_SHIFT                 (11U)
#define SDMACORE_OSTAT_RCV(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_RCV_SHIFT)) & SDMACORE_OSTAT_RCV_MASK)

#define SDMACORE_OSTAT_PST_MASK                  (0xF000U)
#define SDMACORE_OSTAT_PST_SHIFT                 (12U)
/*! PST
 *  0b0000..Program
 *  0b0001..Data
 *  0b0010..Change of Flow
 *  0b0010..Change of Flow in Sleep
 *  0b0011..Change Flow Loop Sleep
 *  0b0011..Change of Flow in Loop
 *  0b0100..Debug
 *  0b0101..Functional Unit
 *  0b0110..Sleep
 *  0b0111..Save
 *  0b1000..Program in Sleep
 *  0b1001..Data in Sleep
 *  0b1100..Debug in Sleep
 *  0b1101..Functional Unit in Sleep
 *  0b1110..Sleep after Reset
 *  0b1111..Restore
 */
#define SDMACORE_OSTAT_PST(x)                    (((uint32_t)(((uint32_t)(x)) << SDMACORE_OSTAT_PST_SHIFT)) & SDMACORE_OSTAT_PST_MASK)
/*! @} */

/*! @name MCHN0ADDR - Channel 0 Boot Address */
/*! @{ */

#define SDMACORE_MCHN0ADDR_CHN0ADDR_MASK         (0x3FFFU)
#define SDMACORE_MCHN0ADDR_CHN0ADDR_SHIFT        (0U)
#define SDMACORE_MCHN0ADDR_CHN0ADDR(x)           (((uint32_t)(((uint32_t)(x)) << SDMACORE_MCHN0ADDR_CHN0ADDR_SHIFT)) & SDMACORE_MCHN0ADDR_CHN0ADDR_MASK)

#define SDMACORE_MCHN0ADDR_SMSZ_MASK             (0x4000U)
#define SDMACORE_MCHN0ADDR_SMSZ_SHIFT            (14U)
/*! SMSZ
 *  0b0..24 words per context
 *  0b1..32 words per context
 */
#define SDMACORE_MCHN0ADDR_SMSZ(x)               (((uint32_t)(((uint32_t)(x)) << SDMACORE_MCHN0ADDR_SMSZ_SHIFT)) & SDMACORE_MCHN0ADDR_SMSZ_MASK)
/*! @} */

/*! @name ENDIANNESS - ENDIAN Status Register */
/*! @{ */

#define SDMACORE_ENDIANNESS_APEND_MASK           (0x1U)
#define SDMACORE_ENDIANNESS_APEND_SHIFT          (0U)
/*! APEND
 *  0b0..- Arm platform is in big-endian mode
 *  0b1..- Arm platform is in little-endian mode
 */
#define SDMACORE_ENDIANNESS_APEND(x)             (((uint32_t)(((uint32_t)(x)) << SDMACORE_ENDIANNESS_APEND_SHIFT)) & SDMACORE_ENDIANNESS_APEND_MASK)
/*! @} */

/*! @name SDMA_LOCK - Lock Status Register */
/*! @{ */

#define SDMACORE_SDMA_LOCK_LOCK_MASK             (0x1U)
#define SDMACORE_SDMA_LOCK_LOCK_SHIFT            (0U)
/*! LOCK
 *  0b0..- LOCK bit clear
 *  0b1..- LOCK bit set
 */
#define SDMACORE_SDMA_LOCK_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << SDMACORE_SDMA_LOCK_LOCK_SHIFT)) & SDMACORE_SDMA_LOCK_LOCK_MASK)
/*! @} */

/*! @name EVENTS2 - External DMA Requests Mirror #2 */
/*! @{ */

#define SDMACORE_EVENTS2_EVENTS_MASK             (0xFFFFU)
#define SDMACORE_EVENTS2_EVENTS_SHIFT            (0U)
#define SDMACORE_EVENTS2_EVENTS(x)               (((uint32_t)(((uint32_t)(x)) << SDMACORE_EVENTS2_EVENTS_SHIFT)) & SDMACORE_EVENTS2_EVENTS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDMACORE_Register_Masks */


/*!
 * @}
 */ /* end of group SDMACORE_Peripheral_Access_Layer */


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


#endif  /* PERI_SDMACORE_H_ */

