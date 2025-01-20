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
**         CMSIS Peripheral Access Layer for SRC_MEM
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
 * @file SRC_MEM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for SRC_MEM
 *
 * CMSIS Peripheral Access Layer for SRC_MEM
 */

#if !defined(SRC_MEM_H_)
#define SRC_MEM_H_                               /**< Symbol preventing repeated inclusion */

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
   -- SRC_MEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MEM_Peripheral_Access_Layer SRC_MEM Peripheral Access Layer
 * @{
 */

/** SRC_MEM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t MEM_CTRL;                          /**< MEM Low Power Control, offset: 0x4 */
  __IO uint32_t MEMLP_CTRL_0;                      /**< MEM Low Power Control_0, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MEMLP_CTRL_1;                      /**< MEM Low Power Control_1, offset: 0x10 */
  __IO uint32_t MEMLP_CTRL_2;                      /**< MEM Low Power Control_2, offset: 0x14 */
  __I  uint32_t MEM_STAT;                          /**< MEM Status, offset: 0x18 */
} SRC_MEM_Type;

/* ----------------------------------------------------------------------------
   -- SRC_MEM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRC_MEM_Register_Masks SRC_MEM Register Masks
 * @{
 */

/*! @name MEM_CTRL - MEM Low Power Control */
/*! @{ */

#define SRC_MEM_MEM_CTRL_MEM_LP_MODE_MASK        (0x2U)
#define SRC_MEM_MEM_CTRL_MEM_LP_MODE_SHIFT       (1U)
/*! MEM_LP_MODE - Memory Low Power Mode configuration. Locked by LOCK_CFG field.
 *  0b0..Power Down
 *  0b1..Retention Mode
 */
#define SRC_MEM_MEM_CTRL_MEM_LP_MODE(x)          (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_CTRL_MEM_LP_MODE_SHIFT)) & SRC_MEM_MEM_CTRL_MEM_LP_MODE_MASK)

#define SRC_MEM_MEM_CTRL_MEM_LF_CNT_CFG_MASK     (0xFF00U)
#define SRC_MEM_MEM_CTRL_MEM_LF_CNT_CFG_SHIFT    (8U)
/*! MEM_LF_CNT_CFG - MEM power up counter */
#define SRC_MEM_MEM_CTRL_MEM_LF_CNT_CFG(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_CTRL_MEM_LF_CNT_CFG_SHIFT)) & SRC_MEM_MEM_CTRL_MEM_LF_CNT_CFG_MASK)

#define SRC_MEM_MEM_CTRL_MEM_HF_CNT_CFG_MASK     (0xFF0000U)
#define SRC_MEM_MEM_CTRL_MEM_HF_CNT_CFG_SHIFT    (16U)
/*! MEM_HF_CNT_CFG - MEM power up counter */
#define SRC_MEM_MEM_CTRL_MEM_HF_CNT_CFG(x)       (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_CTRL_MEM_HF_CNT_CFG_SHIFT)) & SRC_MEM_MEM_CTRL_MEM_HF_CNT_CFG_MASK)

#define SRC_MEM_MEM_CTRL_LOCK_CFG_MASK           (0x1000000U)
#define SRC_MEM_MEM_CTRL_LOCK_CFG_SHIFT          (24U)
/*! LOCK_CFG - Configuration lock
 *  0b0..Not locked.
 *  0b1..Locked.
 */
#define SRC_MEM_MEM_CTRL_LOCK_CFG(x)             (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_CTRL_LOCK_CFG_SHIFT)) & SRC_MEM_MEM_CTRL_LOCK_CFG_MASK)
/*! @} */

/*! @name MEMLP_CTRL_0 - MEM Low Power Control_0 */
/*! @{ */

#define SRC_MEM_MEMLP_CTRL_0_MEMLP_ENT_CNT_MASK  (0xFFFFFFFFU)
#define SRC_MEM_MEMLP_CTRL_0_MEMLP_ENT_CNT_SHIFT (0U)
/*! MEMLP_ENT_CNT - Delay counter to start entering to memory low power mode. Locked by LOCK_CFG field */
#define SRC_MEM_MEMLP_CTRL_0_MEMLP_ENT_CNT(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEMLP_CTRL_0_MEMLP_ENT_CNT_SHIFT)) & SRC_MEM_MEMLP_CTRL_0_MEMLP_ENT_CNT_MASK)
/*! @} */

/*! @name MEMLP_CTRL_1 - MEM Low Power Control_1 */
/*! @{ */

#define SRC_MEM_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_MASK (0xFFFFFFFFU)
#define SRC_MEM_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_SHIFT (0U)
/*! MEMLP_RET_PGEN_CNT - Delay counter to interval for retn to pgen. Locked by LOCK_CFG field */
#define SRC_MEM_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT(x) (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_SHIFT)) & SRC_MEM_MEMLP_CTRL_1_MEMLP_RET_PGEN_CNT_MASK)
/*! @} */

/*! @name MEMLP_CTRL_2 - MEM Low Power Control_2 */
/*! @{ */

#define SRC_MEM_MEMLP_CTRL_2_MEMLP_EXT_CNT_MASK  (0xFFFFFFFFU)
#define SRC_MEM_MEMLP_CTRL_2_MEMLP_EXT_CNT_SHIFT (0U)
/*! MEMLP_EXT_CNT - Delay counter to start exiting from memory low power mode. Locked by LOCK_CFG field */
#define SRC_MEM_MEMLP_CTRL_2_MEMLP_EXT_CNT(x)    (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEMLP_CTRL_2_MEMLP_EXT_CNT_SHIFT)) & SRC_MEM_MEMLP_CTRL_2_MEMLP_EXT_CNT_MASK)
/*! @} */

/*! @name MEM_STAT - MEM Status */
/*! @{ */

#define SRC_MEM_MEM_STAT_MEM_FSM_STAT_MASK       (0xFU)
#define SRC_MEM_MEM_STAT_MEM_FSM_STAT_SHIFT      (0U)
/*! MEM_FSM_STAT - MEM FSM status
 *  0b0000..MEM_IDLE_POR
 *  0b0001..MEM_IDLE_RUN
 *  0b0010..MEM_OFF_PRE
 *  0b0011..MEM_ENT_RET
 *  0b0100..MEM_ENT_PGEN
 *  0b0101..MEM_OFF_RSP
 *  0b0110..MEM_IDLE_SLEEP
 *  0b0111..MEM_ON_PRE
 *  0b1000..MEM_EXT_PGEN
 *  0b1001..MEM_EXT_RET
 *  0b1010..MEM_ON_RSP
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define SRC_MEM_MEM_STAT_MEM_FSM_STAT(x)         (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_STAT_MEM_FSM_STAT_SHIFT)) & SRC_MEM_MEM_STAT_MEM_FSM_STAT_MASK)

#define SRC_MEM_MEM_STAT_RET2N_STAT_MASK         (0x10U)
#define SRC_MEM_MEM_STAT_RET2N_STAT_SHIFT        (4U)
/*! RET2N_STAT - RET2N status
 *  0b0..Memory RET2N pin is low
 *  0b1..Memory RET2N pin is high
 */
#define SRC_MEM_MEM_STAT_RET2N_STAT(x)           (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_STAT_RET2N_STAT_SHIFT)) & SRC_MEM_MEM_STAT_RET2N_STAT_MASK)

#define SRC_MEM_MEM_STAT_RET1N_STAT_MASK         (0x20U)
#define SRC_MEM_MEM_STAT_RET1N_STAT_SHIFT        (5U)
/*! RET1N_STAT - RET1N status
 *  0b1..Memory RET1N pin is high
 *  0b0..Memory RET1N pin is low
 */
#define SRC_MEM_MEM_STAT_RET1N_STAT(x)           (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_STAT_RET1N_STAT_SHIFT)) & SRC_MEM_MEM_STAT_RET1N_STAT_MASK)

#define SRC_MEM_MEM_STAT_PGEN_STAT_MASK          (0x40U)
#define SRC_MEM_MEM_STAT_PGEN_STAT_SHIFT         (6U)
/*! PGEN_STAT - Power gate enable status
 *  0b0..Memory PGEN pin is low
 *  0b1..Memory PGEN pin is high
 */
#define SRC_MEM_MEM_STAT_PGEN_STAT(x)            (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_STAT_PGEN_STAT_SHIFT)) & SRC_MEM_MEM_STAT_PGEN_STAT_MASK)

#define SRC_MEM_MEM_STAT_MEM_STAT_MASK           (0x100U)
#define SRC_MEM_MEM_STAT_MEM_STAT_SHIFT          (8U)
/*! MEM_STAT - MEM status
 *  0b0..MEM exit low power
 *  0b1..MEM enter low power - retention1 mode or power down mode
 */
#define SRC_MEM_MEM_STAT_MEM_STAT(x)             (((uint32_t)(((uint32_t)(x)) << SRC_MEM_MEM_STAT_MEM_STAT_SHIFT)) & SRC_MEM_MEM_STAT_MEM_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SRC_MEM_Register_Masks */


/*!
 * @}
 */ /* end of group SRC_MEM_Peripheral_Access_Layer */


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


#endif  /* SRC_MEM_H_ */

