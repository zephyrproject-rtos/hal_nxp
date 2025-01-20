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
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IDBG2
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
 * @file IDBG2.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for IDBG2
 *
 * CMSIS Peripheral Access Layer for IDBG2
 */

#if !defined(IDBG2_H_)
#define IDBG2_H_                                 /**< Symbol preventing repeated inclusion */

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
   -- IDBG2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDBG2_Peripheral_Access_Layer IDBG2 Peripheral Access Layer
 * @{
 */

/** IDBG2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LINE_NUM;                          /**< IMA Debug Line Number Register, offset: 0x0 */
  __I  uint32_t CURR_LINE_NUM;                     /**< IMA Debug Current Line Number Register, offset: 0x4 */
  __IO uint32_t IMA;                               /**< IMA Debug Address Register, offset: 0x8 */
  __IO uint32_t IMD;                               /**< IMA Debug Data Register, offset: 0xC */
  __I  uint32_t DONE_STAT;                         /**< Debug Line Done Status Register, offset: 0x10 */
} IDBG2_Type;

/* ----------------------------------------------------------------------------
   -- IDBG2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDBG2_Register_Masks IDBG2 Register Masks
 * @{
 */

/*! @name LINE_NUM - IMA Debug Line Number Register */
/*! @{ */

#define IDBG2_LINE_NUM_LINE_NUM_MASK             (0x1FFFFU)
#define IDBG2_LINE_NUM_LINE_NUM_SHIFT            (0U)
#define IDBG2_LINE_NUM_LINE_NUM(x)               (((uint32_t)(((uint32_t)(x)) << IDBG2_LINE_NUM_LINE_NUM_SHIFT)) & IDBG2_LINE_NUM_LINE_NUM_MASK)
/*! @} */

/*! @name CURR_LINE_NUM - IMA Debug Current Line Number Register */
/*! @{ */

#define IDBG2_CURR_LINE_NUM_CURR_LINE_NUM_MASK   (0x1FFFFU)
#define IDBG2_CURR_LINE_NUM_CURR_LINE_NUM_SHIFT  (0U)
#define IDBG2_CURR_LINE_NUM_CURR_LINE_NUM(x)     (((uint32_t)(((uint32_t)(x)) << IDBG2_CURR_LINE_NUM_CURR_LINE_NUM_SHIFT)) & IDBG2_CURR_LINE_NUM_CURR_LINE_NUM_MASK)

#define IDBG2_CURR_LINE_NUM_DBG_HIT_MASK         (0x80000000U)
#define IDBG2_CURR_LINE_NUM_DBG_HIT_SHIFT        (31U)
#define IDBG2_CURR_LINE_NUM_DBG_HIT(x)           (((uint32_t)(((uint32_t)(x)) << IDBG2_CURR_LINE_NUM_DBG_HIT_SHIFT)) & IDBG2_CURR_LINE_NUM_DBG_HIT_MASK)
/*! @} */

/*! @name IMA - IMA Debug Address Register */
/*! @{ */

#define IDBG2_IMA_ADDR_MASK                      (0xFFFU)
#define IDBG2_IMA_ADDR_SHIFT                     (0U)
#define IDBG2_IMA_ADDR(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG2_IMA_ADDR_SHIFT)) & IDBG2_IMA_ADDR_MASK)

#define IDBG2_IMA_NAME_MASK                      (0x3F0000U)
#define IDBG2_IMA_NAME_SHIFT                     (16U)
#define IDBG2_IMA_NAME(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG2_IMA_NAME_SHIFT)) & IDBG2_IMA_NAME_MASK)

#define IDBG2_IMA_RDWF_MASK                      (0x30000000U)
#define IDBG2_IMA_RDWF_SHIFT                     (28U)
/*! RDWF
 *  0b00..4 Reads are required before incrementing line buffer address index
 *  0b01..3 Reads are required before incrementing line buffer address index
 *  0b10..2 Reads are required before incrementing line buffer address index
 *  0b11..Next read will increment line buffer address index
 */
#define IDBG2_IMA_RDWF(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG2_IMA_RDWF_SHIFT)) & IDBG2_IMA_RDWF_MASK)

#define IDBG2_IMA_WDWF_MASK                      (0xC0000000U)
#define IDBG2_IMA_WDWF_SHIFT                     (30U)
/*! WDWF
 *  0b00..4 Writes are required before incrementing line buffer address index
 *  0b01..3 Writes are required before incrementing line buffer address index
 *  0b10..2 Writes are required before incrementing line buffer address index
 *  0b11..Next write will increment line buffer address index
 */
#define IDBG2_IMA_WDWF(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG2_IMA_WDWF_SHIFT)) & IDBG2_IMA_WDWF_MASK)
/*! @} */

/*! @name IMD - IMA Debug Data Register */
/*! @{ */

#define IDBG2_IMD_DATA_MASK                      (0xFFFFFFFFU)
#define IDBG2_IMD_DATA_SHIFT                     (0U)
#define IDBG2_IMD_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG2_IMD_DATA_SHIFT)) & IDBG2_IMD_DATA_MASK)
/*! @} */

/*! @name DONE_STAT - Debug Line Done Status Register */
/*! @{ */

#define IDBG2_DONE_STAT_AF_MASK                  (0x1U)
#define IDBG2_DONE_STAT_AF_SHIFT                 (0U)
#define IDBG2_DONE_STAT_AF(x)                    (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_AF_SHIFT)) & IDBG2_DONE_STAT_AF_MASK)

#define IDBG2_DONE_STAT_GCM_MASK                 (0x2U)
#define IDBG2_DONE_STAT_GCM_SHIFT                (1U)
#define IDBG2_DONE_STAT_GCM(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_GCM_SHIFT)) & IDBG2_DONE_STAT_GCM_MASK)

#define IDBG2_DONE_STAT_CAS_MASK                 (0x4U)
#define IDBG2_DONE_STAT_CAS_SHIFT                (2U)
#define IDBG2_DONE_STAT_CAS(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_CAS_SHIFT)) & IDBG2_DONE_STAT_CAS_MASK)

#define IDBG2_DONE_STAT_CCONVMED_MASK            (0x8U)
#define IDBG2_DONE_STAT_CCONVMED_SHIFT           (3U)
#define IDBG2_DONE_STAT_CCONVMED(x)              (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_CCONVMED_SHIFT)) & IDBG2_DONE_STAT_CCONVMED_MASK)

#define IDBG2_DONE_STAT_EE_MASK                  (0x10U)
#define IDBG2_DONE_STAT_EE_SHIFT                 (4U)
#define IDBG2_DONE_STAT_EE(x)                    (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_EE_SHIFT)) & IDBG2_DONE_STAT_EE_MASK)

#define IDBG2_DONE_STAT_DF_MASK                  (0x20U)
#define IDBG2_DONE_STAT_DF_SHIFT                 (5U)
#define IDBG2_DONE_STAT_DF(x)                    (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_DF_SHIFT)) & IDBG2_DONE_STAT_DF_MASK)

#define IDBG2_DONE_STAT_DMAP_MASK                (0x40U)
#define IDBG2_DONE_STAT_DMAP_SHIFT               (6U)
#define IDBG2_DONE_STAT_DMAP(x)                  (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_DMAP_SHIFT)) & IDBG2_DONE_STAT_DMAP_MASK)

#define IDBG2_DONE_STAT_NR_MASK                  (0x80U)
#define IDBG2_DONE_STAT_NR_SHIFT                 (7U)
#define IDBG2_DONE_STAT_NR(x)                    (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_NR_SHIFT)) & IDBG2_DONE_STAT_NR_MASK)

#define IDBG2_DONE_STAT_DEMOSAIC_MASK            (0x100U)
#define IDBG2_DONE_STAT_DEMOSAIC_SHIFT           (8U)
#define IDBG2_DONE_STAT_DEMOSAIC(x)              (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_DEMOSAIC_SHIFT)) & IDBG2_DONE_STAT_DEMOSAIC_MASK)

#define IDBG2_DONE_STAT_CSC_MASK                 (0x200U)
#define IDBG2_DONE_STAT_CSC_SHIFT                (9U)
#define IDBG2_DONE_STAT_CSC(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_CSC_SHIFT)) & IDBG2_DONE_STAT_CSC_MASK)

#define IDBG2_DONE_STAT_DRC_MASK                 (0x400U)
#define IDBG2_DONE_STAT_DRC_SHIFT                (10U)
#define IDBG2_DONE_STAT_DRC(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_DRC_SHIFT)) & IDBG2_DONE_STAT_DRC_MASK)

#define IDBG2_DONE_STAT_PKT_MASK                 (0x800U)
#define IDBG2_DONE_STAT_PKT_SHIFT                (11U)
#define IDBG2_DONE_STAT_PKT(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG2_DONE_STAT_PKT_SHIFT)) & IDBG2_DONE_STAT_PKT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IDBG2_Register_Masks */


/*!
 * @}
 */ /* end of group IDBG2_Peripheral_Access_Layer */


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


#endif  /* IDBG2_H_ */

