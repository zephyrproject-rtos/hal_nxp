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
**         CMSIS Peripheral Access Layer for IDBG1
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
 * @file IDBG1.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for IDBG1
 *
 * CMSIS Peripheral Access Layer for IDBG1
 */

#if !defined(IDBG1_H_)
#define IDBG1_H_                                 /**< Symbol preventing repeated inclusion */

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
   -- IDBG1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDBG1_Peripheral_Access_Layer IDBG1 Peripheral Access Layer
 * @{
 */

/** IDBG1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LINE_NUM;                          /**< IMA Debug Line Number Register, offset: 0x0 */
  __I  uint32_t CURR_LINE_NUM;                     /**< IMA Debug Current Line Number Register, offset: 0x4 */
  __IO uint32_t IMA;                               /**< IMA Debug Address Register, offset: 0x8 */
  __IO uint32_t IMD;                               /**< IMA Debug Data Register, offset: 0xC */
  __I  uint32_t DONE_STAT;                         /**< Debug Line Done Status Register, offset: 0x10 */
} IDBG1_Type;

/* ----------------------------------------------------------------------------
   -- IDBG1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IDBG1_Register_Masks IDBG1 Register Masks
 * @{
 */

/*! @name LINE_NUM - IMA Debug Line Number Register */
/*! @{ */

#define IDBG1_LINE_NUM_LINE_NUM_MASK             (0x1FFFFU)
#define IDBG1_LINE_NUM_LINE_NUM_SHIFT            (0U)
#define IDBG1_LINE_NUM_LINE_NUM(x)               (((uint32_t)(((uint32_t)(x)) << IDBG1_LINE_NUM_LINE_NUM_SHIFT)) & IDBG1_LINE_NUM_LINE_NUM_MASK)
/*! @} */

/*! @name CURR_LINE_NUM - IMA Debug Current Line Number Register */
/*! @{ */

#define IDBG1_CURR_LINE_NUM_CURR_LINE_NUM_MASK   (0x1FFFFU)
#define IDBG1_CURR_LINE_NUM_CURR_LINE_NUM_SHIFT  (0U)
#define IDBG1_CURR_LINE_NUM_CURR_LINE_NUM(x)     (((uint32_t)(((uint32_t)(x)) << IDBG1_CURR_LINE_NUM_CURR_LINE_NUM_SHIFT)) & IDBG1_CURR_LINE_NUM_CURR_LINE_NUM_MASK)

#define IDBG1_CURR_LINE_NUM_DBG_HIT_MASK         (0x80000000U)
#define IDBG1_CURR_LINE_NUM_DBG_HIT_SHIFT        (31U)
#define IDBG1_CURR_LINE_NUM_DBG_HIT(x)           (((uint32_t)(((uint32_t)(x)) << IDBG1_CURR_LINE_NUM_DBG_HIT_SHIFT)) & IDBG1_CURR_LINE_NUM_DBG_HIT_MASK)
/*! @} */

/*! @name IMA - IMA Debug Address Register */
/*! @{ */

#define IDBG1_IMA_ADDR_MASK                      (0xFFFU)
#define IDBG1_IMA_ADDR_SHIFT                     (0U)
#define IDBG1_IMA_ADDR(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG1_IMA_ADDR_SHIFT)) & IDBG1_IMA_ADDR_MASK)

#define IDBG1_IMA_NAME_MASK                      (0x1F0000U)
#define IDBG1_IMA_NAME_SHIFT                     (16U)
#define IDBG1_IMA_NAME(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG1_IMA_NAME_SHIFT)) & IDBG1_IMA_NAME_MASK)

#define IDBG1_IMA_RDWF_MASK                      (0x30000000U)
#define IDBG1_IMA_RDWF_SHIFT                     (28U)
/*! RDWF
 *  0b00..4 Reads are required before incrementing line buffer address index
 *  0b01..3 Reads are required before incrementing line buffer address index
 *  0b10..2 Reads are required before incrementing line buffer address index
 *  0b11..Next read will increment line buffer address index
 */
#define IDBG1_IMA_RDWF(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG1_IMA_RDWF_SHIFT)) & IDBG1_IMA_RDWF_MASK)

#define IDBG1_IMA_WDWF_MASK                      (0xC0000000U)
#define IDBG1_IMA_WDWF_SHIFT                     (30U)
/*! WDWF
 *  0b00..4 Writes are required before incrementing line buffer address index
 *  0b01..3 Writes are required before incrementing line buffer address index
 *  0b10..2 Writes are required before incrementing line buffer address index
 *  0b11..Next write will increment line buffer address index
 */
#define IDBG1_IMA_WDWF(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG1_IMA_WDWF_SHIFT)) & IDBG1_IMA_WDWF_MASK)
/*! @} */

/*! @name IMD - IMA Debug Data Register */
/*! @{ */

#define IDBG1_IMD_DATA_MASK                      (0xFFFFFFFFU)
#define IDBG1_IMD_DATA_SHIFT                     (0U)
#define IDBG1_IMD_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << IDBG1_IMD_DATA_SHIFT)) & IDBG1_IMD_DATA_MASK)
/*! @} */

/*! @name DONE_STAT - Debug Line Done Status Register */
/*! @{ */

#define IDBG1_DONE_STAT_VIG_MASK                 (0x1U)
#define IDBG1_DONE_STAT_VIG_SHIFT                (0U)
#define IDBG1_DONE_STAT_VIG(x)                   (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_VIG_SHIFT)) & IDBG1_DONE_STAT_VIG_MASK)

#define IDBG1_DONE_STAT_IRCOMP_MASK              (0x2U)
#define IDBG1_DONE_STAT_IRCOMP_SHIFT             (1U)
#define IDBG1_DONE_STAT_IRCOMP(x)                (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_IRCOMP_SHIFT)) & IDBG1_DONE_STAT_IRCOMP_MASK)

#define IDBG1_DONE_STAT_HDRMERGE_MASK            (0x4U)
#define IDBG1_DONE_STAT_HDRMERGE_SHIFT           (2U)
#define IDBG1_DONE_STAT_HDRMERGE(x)              (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_HDRMERGE_SHIFT)) & IDBG1_DONE_STAT_HDRMERGE_MASK)

#define IDBG1_DONE_STAT_BNR0_MASK                (0x8U)
#define IDBG1_DONE_STAT_BNR0_SHIFT               (3U)
#define IDBG1_DONE_STAT_BNR0(x)                  (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_BNR0_SHIFT)) & IDBG1_DONE_STAT_BNR0_MASK)

#define IDBG1_DONE_STAT_STAT_MASK                (0x10U)
#define IDBG1_DONE_STAT_STAT_SHIFT               (4U)
#define IDBG1_DONE_STAT_STAT(x)                  (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_STAT_SHIFT)) & IDBG1_DONE_STAT_STAT_MASK)

#define IDBG1_DONE_STAT_CTEMP_MASK               (0x20U)
#define IDBG1_DONE_STAT_CTEMP_SHIFT              (5U)
#define IDBG1_DONE_STAT_CTEMP(x)                 (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_CTEMP_SHIFT)) & IDBG1_DONE_STAT_CTEMP_MASK)

#define IDBG1_DONE_STAT_OB_WB2_MASK              (0x40U)
#define IDBG1_DONE_STAT_OB_WB2_SHIFT             (6U)
#define IDBG1_DONE_STAT_OB_WB2(x)                (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_OB_WB2_SHIFT)) & IDBG1_DONE_STAT_OB_WB2_MASK)

#define IDBG1_DONE_STAT_OBWB1_MASK               (0x80U)
#define IDBG1_DONE_STAT_OBWB1_SHIFT              (7U)
#define IDBG1_DONE_STAT_OBWB1(x)                 (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_OBWB1_SHIFT)) & IDBG1_DONE_STAT_OBWB1_MASK)

#define IDBG1_DONE_STAT_OBWB0_MASK               (0x100U)
#define IDBG1_DONE_STAT_OBWB0_SHIFT              (8U)
#define IDBG1_DONE_STAT_OBWB0(x)                 (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_OBWB0_SHIFT)) & IDBG1_DONE_STAT_OBWB0_MASK)

#define IDBG1_DONE_STAT_HDRDECOMP1_MASK          (0x200U)
#define IDBG1_DONE_STAT_HDRDECOMP1_SHIFT         (9U)
#define IDBG1_DONE_STAT_HDRDECOMP1(x)            (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_HDRDECOMP1_SHIFT)) & IDBG1_DONE_STAT_HDRDECOMP1_MASK)

#define IDBG1_DONE_STAT_HDRDECOMP0_MASK          (0x400U)
#define IDBG1_DONE_STAT_HDRDECOMP0_SHIFT         (10U)
#define IDBG1_DONE_STAT_HDRDECOMP0(x)            (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_HDRDECOMP0_SHIFT)) & IDBG1_DONE_STAT_HDRDECOMP0_MASK)

#define IDBG1_DONE_STAT_HC_MASK                  (0x800U)
#define IDBG1_DONE_STAT_HC_SHIFT                 (11U)
#define IDBG1_DONE_STAT_HC(x)                    (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_HC_SHIFT)) & IDBG1_DONE_STAT_HC_MASK)

#define IDBG1_DONE_STAT_RGBIR_MASK               (0x1000U)
#define IDBG1_DONE_STAT_RGBIR_SHIFT              (12U)
#define IDBG1_DONE_STAT_RGBIR(x)                 (((uint32_t)(((uint32_t)(x)) << IDBG1_DONE_STAT_RGBIR_SHIFT)) & IDBG1_DONE_STAT_RGBIR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IDBG1_Register_Masks */


/*!
 * @}
 */ /* end of group IDBG1_Peripheral_Access_Layer */


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


#endif  /* IDBG1_H_ */

