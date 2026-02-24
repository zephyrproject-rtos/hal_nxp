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
**         CMSIS Peripheral Access Layer for DISPLAY_CM0_CSR
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
 * @file PERI_DISPLAY_CM0_CSR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_CM0_CSR
 *
 * CMSIS Peripheral Access Layer for DISPLAY_CM0_CSR
 */

#if !defined(PERI_DISPLAY_CM0_CSR_H_)
#define PERI_DISPLAY_CM0_CSR_H_                  /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_CM0_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_CM0_CSR_Peripheral_Access_Layer DISPLAY_CM0_CSR Peripheral Access Layer
 * @{
 */

/** DISPLAY_CM0_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM0P_CLOCK_GATING;                 /**< CM0P and LPCAC Clock Gating Control, offset: 0x0 */
  __IO uint32_t CM0P_ADDR_OFFSET1;                 /**< Cortex-M0+ Address Offset 1, offset: 0x4 */
  __IO uint32_t CM0P_ADDR_OFFSET2;                 /**< Cortex-M0+ Address Offset 2, offset: 0x8 */
  __IO uint32_t CM0P_CPUWAIT;                      /**< Cortex-M0+ LPCAC CPUWAIT Software Reset Control, offset: 0xC */
  __IO uint32_t CM0P_CTL;                          /**< Cortex-M0+ Control, offset: 0x10 */
  __I  uint32_t CM0P_STAT;                         /**< Cortex-M0+ Status, offset: 0x14 */
  __IO uint32_t LPCAC_ERROR;                       /**< LPCAC Error, offset: 0x18 */
} DISPLAY_CM0_CSR_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_CM0_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_CM0_CSR_Register_Masks DISPLAY_CM0_CSR Register Masks
 * @{
 */

/*! @name CM0P_CLOCK_GATING - CM0P and LPCAC Clock Gating Control */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_CLOCK_GATING_DISP_CM0P_CLK_MASK (0x1U)
#define DISPLAY_CM0_CSR_CM0P_CLOCK_GATING_DISP_CM0P_CLK_SHIFT (0U)
/*! DISP_CM0P_CLK - CM0P and LPCAC Clock Gating Control
 *  0b0..Not gated
 *  0b1..Gated
 */
#define DISPLAY_CM0_CSR_CM0P_CLOCK_GATING_DISP_CM0P_CLK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CLOCK_GATING_DISP_CM0P_CLK_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CLOCK_GATING_DISP_CM0P_CLK_MASK)
/*! @} */

/*! @name CM0P_ADDR_OFFSET1 - Cortex-M0+ Address Offset 1 */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET1_OFFSET_MASK (0xFFFFFF00U)
#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET1_OFFSET_SHIFT (8U)
/*! OFFSET - CM0P Address Offset 1 */
#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET1_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET1_OFFSET_SHIFT)) & DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET1_OFFSET_MASK)
/*! @} */

/*! @name CM0P_ADDR_OFFSET2 - Cortex-M0+ Address Offset 2 */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET2_OFFSET_MASK (0xFFFFFF00U)
#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET2_OFFSET_SHIFT (8U)
/*! OFFSET - CM0P Address Offset 2 */
#define DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET2_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET2_OFFSET_SHIFT)) & DISPLAY_CM0_CSR_CM0P_ADDR_OFFSET2_OFFSET_MASK)
/*! @} */

/*! @name CM0P_CPUWAIT - Cortex-M0+ LPCAC CPUWAIT Software Reset Control */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_CPW_MASK    (0x1U)
#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_CPW_SHIFT   (0U)
/*! CPW - CM0P CPUWAIT Input Signal Control
 *  0b0..Processor is running
 *  0b1..Processor is waiting
 */
#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_CPW(x)      (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CPUWAIT_CPW_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CPUWAIT_CPW_MASK)

#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_RST_MASK    (0x2U)
#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_RST_SHIFT   (1U)
/*! RST - CM0P and LPCAC Software Reset
 *  0b0..CM0P logic is held in reset
 *  0b1..CM0P logic is not in reset
 */
#define DISPLAY_CM0_CSR_CM0P_CPUWAIT_RST(x)      (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CPUWAIT_RST_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CPUWAIT_RST_MASK)
/*! @} */

/*! @name CM0P_CTL - Cortex-M0+ Control */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_CTL_ILT_MASK        (0x3FCU)
#define DISPLAY_CM0_CSR_CM0P_CTL_ILT_SHIFT       (2U)
/*! ILT - CM0Px IRQLATENCY[7:0] Input Control */
#define DISPLAY_CM0_CSR_CM0P_CTL_ILT(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_ILT_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_ILT_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_CLR_MASK        (0x400U)
#define DISPLAY_CM0_CSR_CM0P_CTL_CLR_SHIFT       (10U)
/*! CLR - LPCAC Data Cache Clear Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_CLR(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_CLR_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_CLR_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_NAL_MASK        (0x800U)
#define DISPLAY_CM0_CSR_CM0P_CTL_NAL_SHIFT       (11U)
/*! NAL - LPCAC Data Cache Allocation Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_NAL(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_NAL_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_NAL_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_DWB_MASK        (0x1000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_DWB_SHIFT       (12U)
/*! DWB - LPCAC Write Buffer Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_DWB(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_DWB_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_DWB_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_DIS_MASK        (0x2000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_DIS_SHIFT       (13U)
/*! DIS - LPCAC Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_DIS(x)          (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_DIS_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_DIS_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_Boot_MASK       (0x8000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_Boot_SHIFT      (15U)
/*! Boot - Boot Source Select
 *  0b0..OCRAM_L
 *  0b1..DDR
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_Boot(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_Boot_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_Boot_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_lim_lpcac_wtbf_MASK (0x10000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_lim_lpcac_wtbf_SHIFT (16U)
/*! lim_lpcac_wtbf - Write Buffer Limit
 *  0b0..If write buffer is enabled, buffer all writes to spaces those are bufferable.
 *  0b1..If write buffer is enabled, buffer all writes to spaces those are both bufferable and cacheable.
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_lim_lpcac_wtbf(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_lim_lpcac_wtbf_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_lim_lpcac_wtbf_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_parity_miss_en_MASK (0x20000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_parity_miss_en_SHIFT (17U)
/*! parity_miss_en - Parity Error Miss Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_parity_miss_en(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_parity_miss_en_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_parity_miss_en_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_parity_fault_en_MASK (0x40000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_parity_fault_en_SHIFT (18U)
/*! parity_fault_en - Parity Error Reporting Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DISPLAY_CM0_CSR_CM0P_CTL_parity_fault_en(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_parity_fault_en_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_parity_fault_en_MASK)

#define DISPLAY_CM0_CSR_CM0P_CTL_OCRAM__in_init_req_MASK (0x80000U)
#define DISPLAY_CM0_CSR_CM0P_CTL_OCRAM__in_init_req_SHIFT (19U)
/*! OCRAM__in_init_req - RAM Initialization Request */
#define DISPLAY_CM0_CSR_CM0P_CTL_OCRAM__in_init_req(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_CTL_OCRAM__in_init_req_SHIFT)) & DISPLAY_CM0_CSR_CM0P_CTL_OCRAM__in_init_req_MASK)
/*! @} */

/*! @name CM0P_STAT - Cortex-M0+ Status */
/*! @{ */

#define DISPLAY_CM0_CSR_CM0P_STAT_LKP_MASK       (0x1U)
#define DISPLAY_CM0_CSR_CM0P_STAT_LKP_SHIFT      (0U)
/*! LKP - CM0P LOCKUP Output Signal Value
 *  0b0..Processor is not in LOCKUP state
 *  0b1..Processor is in LOCKUP state, as a result of an unrecoverable exception.
 */
#define DISPLAY_CM0_CSR_CM0P_STAT_LKP(x)         (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_CM0P_STAT_LKP_SHIFT)) & DISPLAY_CM0_CSR_CM0P_STAT_LKP_MASK)
/*! @} */

/*! @name LPCAC_ERROR - LPCAC Error */
/*! @{ */

#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_PE_MASK (0x1U)
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_PE_SHIFT (0U)
/*! CACHE_PE - Cache Data Parity Error */
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_PE(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_PE_SHIFT)) & DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_PE_MASK)

#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_WE_MASK (0x2U)
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_WE_SHIFT (1U)
/*! CACHE_WE - Cache Write-buffer Error */
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_WE(x)  (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_WE_SHIFT)) & DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_WE_MASK)

#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_IRQ_CLR_MASK (0x80000000U)
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_IRQ_CLR_SHIFT (31U)
/*! CACHE_IRQ_CLR - Cache Interrupt Clear */
#define DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_IRQ_CLR_SHIFT)) & DISPLAY_CM0_CSR_LPCAC_ERROR_CACHE_IRQ_CLR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_CM0_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_CM0_CSR_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_CM0_CSR_H_ */

