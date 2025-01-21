/*
** ###################################################################
**     Processors:          MCXW716AMFPA
**                          MCXW716AMFTA
**                          MCXW716CMFPA
**                          MCXW716CMFTA
**
**     Version:             rev. 1.0, 2024-03-21
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-21)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DSB.h
 * @version 1.0
 * @date 2024-03-21
 * @brief CMSIS Peripheral Access Layer for DSB
 *
 * CMSIS Peripheral Access Layer for DSB
 */

#if !defined(DSB_H_)
#define DSB_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW716AMFPA) || defined(CPU_MCXW716AMFTA))
#include "MCXW716A_COMMON.h"
#elif (defined(CPU_MCXW716CMFPA) || defined(CPU_MCXW716CMFTA))
#include "MCXW716C_COMMON.h"
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
   -- DSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSB_Peripheral_Access_Layer DSB Peripheral Access Layer
 * @{
 */

/** DSB - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Control Register, offset: 0x0 */
  __IO uint32_t INT;                               /**< Interrupt Request Status Register, offset: 0x4 */
  __IO uint32_t WMC;                               /**< Watermark Configuration Register, offset: 0x8 */
  __I  uint32_t RDATA;                             /**< FIFO Read Data Register, offset: 0xC */
  __IO uint32_t DADDR;                             /**< DMA Destination Address Register, offset: 0x10 */
  __IO uint32_t XCR;                               /**< DMA Transfer Count Register, offset: 0x14 */
} DSB_Type;

/* ----------------------------------------------------------------------------
   -- DSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSB_Register_Masks DSB Register Masks
 * @{
 */

/*! @name CSR - Control Register */
/*! @{ */

#define DSB_CSR_SFTRST_MASK                      (0x1U)
#define DSB_CSR_SFTRST_SHIFT                     (0U)
/*! SFTRST - Soft Reset
 *  0b0..No operation.
 *  0b1..Reset the data stream buffer.
 */
#define DSB_CSR_SFTRST(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_SFTRST_SHIFT)) & DSB_CSR_SFTRST_MASK)

#define DSB_CSR_DSB_EN_MASK                      (0x2U)
#define DSB_CSR_DSB_EN_SHIFT                     (1U)
/*! DSB_EN - Data Stream Buffer Enable
 *  0b0..Buffer is disabled.
 *  0b1..Buffer is enabled.
 */
#define DSB_CSR_DSB_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_DSB_EN_SHIFT)) & DSB_CSR_DSB_EN_MASK)

#define DSB_CSR_DMA_EN_MASK                      (0x4U)
#define DSB_CSR_DMA_EN_SHIFT                     (2U)
/*! DMA_EN - DMA Transfer Enable
 *  0b0..DMA transfers are disabled.
 *  0b1..DMA transfers are enabled.
 */
#define DSB_CSR_DMA_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_DMA_EN_SHIFT)) & DSB_CSR_DMA_EN_MASK)

#define DSB_CSR_INT_EN_MASK                      (0x8U)
#define DSB_CSR_INT_EN_SHIFT                     (3U)
/*! INT_EN - Interrupt Request Enable
 *  0b0..Interrupt requests on data ready or DMA done are disabled.
 *  0b1..Interrupt requests on data ready or DMA done are enabled.
 */
#define DSB_CSR_INT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_INT_EN_SHIFT)) & DSB_CSR_INT_EN_MASK)

#define DSB_CSR_ERR_EN_MASK                      (0x10U)
#define DSB_CSR_ERR_EN_SHIFT                     (4U)
/*! ERR_EN - Error Interrupt Request Enable
 *  0b0..Error interrupt requests on overflow, underrun, or bus error are disabled.
 *  0b1..Error interrupt requests on overflow, underrun, or bus error are enabled.
 */
#define DSB_CSR_ERR_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_ERR_EN_SHIFT)) & DSB_CSR_ERR_EN_MASK)

#define DSB_CSR_CBT_EN_MASK                      (0x20U)
#define DSB_CSR_CBT_EN_SHIFT                     (5U)
/*! CBT_EN - Continuous Burst Transfer Enable
 *  0b0..Continuous burst transfer mode is disabled.
 *  0b1..Continuous burst transfer mode is enabled.
 */
#define DSB_CSR_CBT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_CSR_CBT_EN_SHIFT)) & DSB_CSR_CBT_EN_MASK)
/*! @} */

/*! @name INT - Interrupt Request Status Register */
/*! @{ */

#define DSB_INT_DRDY_MASK                        (0x1U)
#define DSB_INT_DRDY_SHIFT                       (0U)
/*! DRDY - Data Ready
 *  0b0..No data to read (watermark has not been reached)
 *  0b1..Data is ready to read (watermark has been reached)
 */
#define DSB_INT_DRDY(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_DRDY_SHIFT)) & DSB_INT_DRDY_MASK)

#define DSB_INT_OVRF_MASK                        (0x2U)
#define DSB_INT_OVRF_SHIFT                       (1U)
/*! OVRF - Overflow Error
 *  0b0..No overflow error
 *  0b1..The last recorded error is a buffer overflow
 */
#define DSB_INT_OVRF(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_OVRF_SHIFT)) & DSB_INT_OVRF_MASK)

#define DSB_INT_UNDR_MASK                        (0x4U)
#define DSB_INT_UNDR_SHIFT                       (2U)
/*! UNDR - Underrun Error
 *  0b0..No underrun error
 *  0b1..The last recorded error is an underrun on a read
 */
#define DSB_INT_UNDR(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_UNDR_SHIFT)) & DSB_INT_UNDR_MASK)

#define DSB_INT_DBE_MASK                         (0x8U)
#define DSB_INT_DBE_SHIFT                        (3U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error is bus error on a write
 */
#define DSB_INT_DBE(x)                           (((uint32_t)(((uint32_t)(x)) << DSB_INT_DBE_SHIFT)) & DSB_INT_DBE_MASK)

#define DSB_INT_DONE_MASK                        (0x10U)
#define DSB_INT_DONE_SHIFT                       (4U)
/*! DONE - DMA Packet Transfer Complete
 *  0b0..Packet transfer not done; CCNT less than TCNT
 *  0b1..Packet transfer is done; TCNT 32-bit words transferred
 */
#define DSB_INT_DONE(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_INT_DONE_SHIFT)) & DSB_INT_DONE_MASK)
/*! @} */

/*! @name WMC - Watermark Configuration Register */
/*! @{ */

#define DSB_WMC_WMRK_MASK                        (0xFU)
#define DSB_WMC_WMRK_SHIFT                       (0U)
/*! WMRK - Watermark */
#define DSB_WMC_WMRK(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_WMC_WMRK_SHIFT)) & DSB_WMC_WMRK_MASK)

#define DSB_WMC_CNT_MASK                         (0x1F0000U)
#define DSB_WMC_CNT_SHIFT                        (16U)
/*! CNT - FIFO Count */
#define DSB_WMC_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << DSB_WMC_CNT_SHIFT)) & DSB_WMC_CNT_MASK)

#define DSB_WMC_SIZE_MASK                        (0x1F000000U)
#define DSB_WMC_SIZE_SHIFT                       (24U)
/*! SIZE - FIFO size */
#define DSB_WMC_SIZE(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_WMC_SIZE_SHIFT)) & DSB_WMC_SIZE_MASK)
/*! @} */

/*! @name RDATA - FIFO Read Data Register */
/*! @{ */

#define DSB_RDATA_DATA_MASK                      (0xFFFFFFFFU)
#define DSB_RDATA_DATA_SHIFT                     (0U)
/*! DATA - FIFO Data */
#define DSB_RDATA_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << DSB_RDATA_DATA_SHIFT)) & DSB_RDATA_DATA_MASK)
/*! @} */

/*! @name DADDR - DMA Destination Address Register */
/*! @{ */

#define DSB_DADDR_DADDR_MASK                     (0xFFFFFFFFU)
#define DSB_DADDR_DADDR_SHIFT                    (0U)
/*! DADDR - Destination Address */
#define DSB_DADDR_DADDR(x)                       (((uint32_t)(((uint32_t)(x)) << DSB_DADDR_DADDR_SHIFT)) & DSB_DADDR_DADDR_MASK)
/*! @} */

/*! @name XCR - DMA Transfer Count Register */
/*! @{ */

#define DSB_XCR_TCNT_MASK                        (0xFFFFU)
#define DSB_XCR_TCNT_SHIFT                       (0U)
/*! TCNT - Total Transfer Count */
#define DSB_XCR_TCNT(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_XCR_TCNT_SHIFT)) & DSB_XCR_TCNT_MASK)

#define DSB_XCR_CCNT_MASK                        (0xFFFF0000U)
#define DSB_XCR_CCNT_SHIFT                       (16U)
/*! CCNT - Current Transfer Count */
#define DSB_XCR_CCNT(x)                          (((uint32_t)(((uint32_t)(x)) << DSB_XCR_CCNT_SHIFT)) & DSB_XCR_CCNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSB_Register_Masks */


/*!
 * @}
 */ /* end of group DSB_Peripheral_Access_Layer */


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


#endif  /* DSB_H_ */

