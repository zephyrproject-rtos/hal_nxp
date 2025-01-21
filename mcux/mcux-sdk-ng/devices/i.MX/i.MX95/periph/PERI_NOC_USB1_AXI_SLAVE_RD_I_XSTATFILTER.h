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
**         CMSIS Peripheral Access Layer for NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER
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
 * @file NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER
 *
 * CMSIS Peripheral Access Layer for NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER
 */

#if !defined(NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_H_)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_H_   /**< Symbol preventing repeated inclusion */

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
   -- NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_Peripheral_Access_Layer NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER Peripheral Access Layer
 * @{
 */

/** NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID_COREID;                         /**< Core ID, offset: 0x0 */
  __I  uint32_t ID_REVISIONID;                     /**< Revision ID, offset: 0x4 */
  __IO uint32_t USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE; /**< offset: 0x8 */
  __IO uint32_t USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW; /**< offset: 0xC */
  __IO uint32_t USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH; /**< offset: 0x10 */
  __IO uint32_t USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE; /**< offset: 0x14 */
       uint8_t RESERVED_0[8];
  __IO uint32_t USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE; /**< offset: 0x20 */
} NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_Type;

/* ----------------------------------------------------------------------------
   -- NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_Register_Masks NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER Register Masks
 * @{
 */

/*! @name ID_COREID - Core ID */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORETYPEID_MASK (0xFFU)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORETYPEID_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORETYPEID(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORETYPEID_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORETYPEID_MASK)

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORECHECKSUM_MASK (0xFFFFFF00U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORECHECKSUM_SHIFT (8U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORECHECKSUM(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORECHECKSUM_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_COREID_CORECHECKSUM_MASK)
/*! @} */

/*! @name ID_REVISIONID - Revision ID */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_USERID_MASK (0xFFU)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_USERID_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_USERID(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_USERID_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_USERID_MASK)

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_NOCID_MASK (0xFFFFFF00U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_NOCID_SHIFT (8U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_NOCID(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_NOCID_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_ID_REVISIONID_NOCID_MASK)
/*! @} */

/*! @name USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE -  */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE_MODE_MASK (0x1U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE_MODE_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE_MODE(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE_MODE_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_MODE_MODE_MASK)
/*! @} */

/*! @name USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW -  */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW_ADDRBASE_LOW_MASK (0xFFFFFFFFU)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW_ADDRBASE_LOW_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW_ADDRBASE_LOW(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW_ADDRBASE_LOW_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_LOW_ADDRBASE_LOW_MASK)
/*! @} */

/*! @name USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH -  */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH_ADDRBASE_HIGH_MASK (0x1FFFFU)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH_ADDRBASE_HIGH_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH_ADDRBASE_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH_ADDRBASE_HIGH_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRBASE_HIGH_ADDRBASE_HIGH_MASK)
/*! @} */

/*! @name USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE -  */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE_ADDRWINDOWSIZE_MASK (0x3FU)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE_ADDRWINDOWSIZE_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE_ADDRWINDOWSIZE(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE_ADDRWINDOWSIZE_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_ADDRWINDOWSIZE_ADDRWINDOWSIZE_MASK)
/*! @} */

/*! @name USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE -  */
/*! @{ */

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_RDEN_MASK (0x1U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_RDEN_SHIFT (0U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_RDEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_RDEN_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_RDEN_MASK)

#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_WREN_MASK (0x2U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_WREN_SHIFT (1U)
#define NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_WREN(x) (((uint32_t)(((uint32_t)(x)) << NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_WREN_SHIFT)) & NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_USB1_AXI_SLAVE_RD_I_MAIN_TRANSACTIONSTATFILTER_OPCODE_WREN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_Peripheral_Access_Layer */


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


#endif  /* NOC_USB1_AXI_SLAVE_RD_I_XSTATFILTER_H_ */

