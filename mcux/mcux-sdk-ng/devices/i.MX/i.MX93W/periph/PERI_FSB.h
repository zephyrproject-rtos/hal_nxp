/*
** ###################################################################
**     Processors:          MIMX93W32610GCM_ca55
**                          MIMX93W32610GCM_cm33
**                          MIMX93W52610GCM_ca55
**                          MIMX93W52610GCM_cm33
**
**     Version:             rev. 1.0, 2025-12-13
**     Build:               b260114
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FSB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-12-13)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_FSB.h
 * @version 1.0
 * @date 2025-12-13
 * @brief CMSIS Peripheral Access Layer for FSB
 *
 * CMSIS Peripheral Access Layer for FSB
 */

#if !defined(PERI_FSB_H_)
#define PERI_FSB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX93W32610GCM_ca55))
#include "MIMX93W32_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W32610GCM_cm33))
#include "MIMX93W32_cm33_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_ca55))
#include "MIMX93W52_ca55_COMMON.h"
#elif (defined(CPU_MIMX93W52610GCM_cm33))
#include "MIMX93W52_cm33_COMMON.h"
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

#if defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- FSB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Peripheral_Access_Layer FSB Peripheral Access Layer
 * @{
 */

/** FSB - Size of Registers Arrays */
#define FSB_FUSE_ARRAY_COUNT                      512u

/** FSB - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< FSB Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[24];
  __I  uint32_t FSB_STATUS;                        /**< FSB Status Register, offset: 0x1C */
       uint8_t RESERVED_1[68];
  __IO uint32_t ACCESS_COUNT;                      /**< Access Count Register, offset: 0x64 */
       uint8_t RESERVED_2[3992];
  __IO uint32_t FUSE_STAT;                         /**< Fuse Status Register, offset: 0x1000 */
  __IO uint32_t FUSE_EVNT;                         /**< Fuse Event Register, offset: 0x1004 */
  __IO uint32_t FUSE_INT_EN;                       /**< Fuse Interrupt Enable Register, offset: 0x1008 */
  __I  uint32_t FUSE_INT;                          /**< Fuse Interrupt Register, offset: 0x100C */
       uint8_t RESERVED_3[112];
  __I  uint32_t UNPROG_CTR;                        /**< Unprogrammed Fuse Counter, offset: 0x1080 */
       uint8_t RESERVED_4[28540];
  __I  uint32_t FUSE[FSB_FUSE_ARRAY_COUNT];        /**< Fuse Value Registers, array offset: 0x8000, array step: 0x4 */
} FSB_Type;

/* ----------------------------------------------------------------------------
   -- FSB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FSB_Register_Masks FSB Register Masks
 * @{
 */

/*! @name VERID - FSB Version ID Register */
/*! @{ */

#define FSB_VERID_MISC_MASK                      (0xFFU)
#define FSB_VERID_MISC_SHIFT                     (0U)
/*! MISC - Feature Specification
 *  0bxxxxxx1x..MU IRQ steering is enabled.
 *  0bxxxxxxx1..Support for aborted transfers to OCOTP fuse space on the FSB slave APB is enabled.
 */
#define FSB_VERID_MISC(x)                        (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MISC_SHIFT)) & FSB_VERID_MISC_MASK)

#define FSB_VERID_ECO_MASK                       (0xFF00U)
#define FSB_VERID_ECO_SHIFT                      (8U)
/*! ECO - ECO Version Number */
#define FSB_VERID_ECO(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_VERID_ECO_SHIFT)) & FSB_VERID_ECO_MASK)

#define FSB_VERID_MINOR_MASK                     (0xFF0000U)
#define FSB_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define FSB_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MINOR_SHIFT)) & FSB_VERID_MINOR_MASK)

#define FSB_VERID_MAJOR_MASK                     (0xFF000000U)
#define FSB_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define FSB_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << FSB_VERID_MAJOR_SHIFT)) & FSB_VERID_MAJOR_MASK)
/*! @} */

/*! @name FSB_STATUS - FSB Status Register */
/*! @{ */

#define FSB_FSB_STATUS_VMTR_MASK                 (0x1U)
#define FSB_FSB_STATUS_VMTR_SHIFT                (0U)
/*! VMTR - MTR Trim fuses valid. */
#define FSB_FSB_STATUS_VMTR(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VMTR_SHIFT)) & FSB_FSB_STATUS_VMTR_MASK)

#define FSB_FSB_STATUS_VERL_MASK                 (0x2U)
#define FSB_FSB_STATUS_VERL_SHIFT                (1U)
/*! VERL - Early fuses valid. */
#define FSB_FSB_STATUS_VERL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VERL_SHIFT)) & FSB_FSB_STATUS_VERL_MASK)

#define FSB_FSB_STATUS_VMED_MASK                 (0x4U)
#define FSB_FSB_STATUS_VMED_SHIFT                (2U)
/*! VMED - Medium fuses valid. */
#define FSB_FSB_STATUS_VMED(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VMED_SHIFT)) & FSB_FSB_STATUS_VMED_MASK)

#define FSB_FSB_STATUS_VALL_MASK                 (0x8U)
#define FSB_FSB_STATUS_VALL_SHIFT                (3U)
/*! VALL - All fuses valid. */
#define FSB_FSB_STATUS_VALL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_VALL_SHIFT)) & FSB_FSB_STATUS_VALL_MASK)

#define FSB_FSB_STATUS_LMTR_MASK                 (0x10U)
#define FSB_FSB_STATUS_LMTR_SHIFT                (4U)
/*! LMTR - MTR Trim fuses loaded. */
#define FSB_FSB_STATUS_LMTR(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LMTR_SHIFT)) & FSB_FSB_STATUS_LMTR_MASK)

#define FSB_FSB_STATUS_LERL_MASK                 (0x20U)
#define FSB_FSB_STATUS_LERL_SHIFT                (5U)
/*! LERL - Early fuses loaded. */
#define FSB_FSB_STATUS_LERL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LERL_SHIFT)) & FSB_FSB_STATUS_LERL_MASK)

#define FSB_FSB_STATUS_LMED_MASK                 (0x40U)
#define FSB_FSB_STATUS_LMED_SHIFT                (6U)
/*! LMED - Medium fuses loaded. */
#define FSB_FSB_STATUS_LMED(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LMED_SHIFT)) & FSB_FSB_STATUS_LMED_MASK)

#define FSB_FSB_STATUS_LALL_MASK                 (0x80U)
#define FSB_FSB_STATUS_LALL_SHIFT                (7U)
/*! LALL - All fuses loaded. */
#define FSB_FSB_STATUS_LALL(x)                   (((uint32_t)(((uint32_t)(x)) << FSB_FSB_STATUS_LALL_SHIFT)) & FSB_FSB_STATUS_LALL_MASK)
/*! @} */

/*! @name ACCESS_COUNT - Access Count Register */
/*! @{ */

#define FSB_ACCESS_COUNT_COUNT_MASK              (0xFFFFFFFFU)
#define FSB_ACCESS_COUNT_COUNT_SHIFT             (0U)
/*! COUNT - Access Count Register. */
#define FSB_ACCESS_COUNT_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << FSB_ACCESS_COUNT_COUNT_SHIFT)) & FSB_ACCESS_COUNT_COUNT_MASK)
/*! @} */

/*! @name FUSE_STAT - Fuse Status Register */
/*! @{ */

#define FSB_FUSE_STAT_FUSE_ADDR_MASK             (0xFFFFU)
#define FSB_FUSE_STAT_FUSE_ADDR_SHIFT            (0U)
/*! FUSE_ADDR - Fuse address */
#define FSB_FUSE_STAT_FUSE_ADDR(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_FUSE_ADDR_SHIFT)) & FSB_FUSE_STAT_FUSE_ADDR_MASK)

#define FSB_FUSE_STAT_SHDW_ZERO_MASK             (0x1000000U)
#define FSB_FUSE_STAT_SHDW_ZERO_SHIFT            (24U)
/*! SHDW_ZERO - Shadow zeroized */
#define FSB_FUSE_STAT_SHDW_ZERO(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_SHDW_ZERO_SHIFT)) & FSB_FUSE_STAT_SHDW_ZERO_MASK)

#define FSB_FUSE_STAT_SHDW_UNPROG_MASK           (0x2000000U)
#define FSB_FUSE_STAT_SHDW_UNPROG_SHIFT          (25U)
/*! SHDW_UNPROG - Shadow unprogrammed */
#define FSB_FUSE_STAT_SHDW_UNPROG(x)             (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_SHDW_UNPROG_SHIFT)) & FSB_FUSE_STAT_SHDW_UNPROG_MASK)

#define FSB_FUSE_STAT_FUSE_ERR_MASK              (0x4000000U)
#define FSB_FUSE_STAT_FUSE_ERR_SHIFT             (26U)
/*! FUSE_ERR - Fuse error */
#define FSB_FUSE_STAT_FUSE_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_FUSE_ERR_SHIFT)) & FSB_FUSE_STAT_FUSE_ERR_MASK)

#define FSB_FUSE_STAT_LOADING_MASK               (0x8000000U)
#define FSB_FUSE_STAT_LOADING_SHIFT              (27U)
/*! LOADING - Shadow loading */
#define FSB_FUSE_STAT_LOADING(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_LOADING_SHIFT)) & FSB_FUSE_STAT_LOADING_MASK)

#define FSB_FUSE_STAT_RLD_ERR_MASK               (0x10000000U)
#define FSB_FUSE_STAT_RLD_ERR_SHIFT              (28U)
/*! RLD_ERR - Reload error */
#define FSB_FUSE_STAT_RLD_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_RLD_ERR_SHIFT)) & FSB_FUSE_STAT_RLD_ERR_MASK)

#define FSB_FUSE_STAT_RD_ERR_MASK                (0x20000000U)
#define FSB_FUSE_STAT_RD_ERR_SHIFT               (29U)
/*! RD_ERR - Read error */
#define FSB_FUSE_STAT_RD_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_RD_ERR_SHIFT)) & FSB_FUSE_STAT_RD_ERR_MASK)

#define FSB_FUSE_STAT_ADDR_ERR_MASK              (0x80000000U)
#define FSB_FUSE_STAT_ADDR_ERR_SHIFT             (31U)
/*! ADDR_ERR - Address error */
#define FSB_FUSE_STAT_ADDR_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_STAT_ADDR_ERR_SHIFT)) & FSB_FUSE_STAT_ADDR_ERR_MASK)
/*! @} */

/*! @name FUSE_EVNT - Fuse Event Register */
/*! @{ */

#define FSB_FUSE_EVNT_SHDW_ZERO_MASK             (0x1000000U)
#define FSB_FUSE_EVNT_SHDW_ZERO_SHIFT            (24U)
/*! SHDW_ZERO - Shadow zeroized */
#define FSB_FUSE_EVNT_SHDW_ZERO(x)               (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_SHDW_ZERO_SHIFT)) & FSB_FUSE_EVNT_SHDW_ZERO_MASK)

#define FSB_FUSE_EVNT_SHDW_UNPROG_MASK           (0x2000000U)
#define FSB_FUSE_EVNT_SHDW_UNPROG_SHIFT          (25U)
/*! SHDW_UNPROG - Shadow unprogrammed */
#define FSB_FUSE_EVNT_SHDW_UNPROG(x)             (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_SHDW_UNPROG_SHIFT)) & FSB_FUSE_EVNT_SHDW_UNPROG_MASK)

#define FSB_FUSE_EVNT_FUSE_ERR_MASK              (0x4000000U)
#define FSB_FUSE_EVNT_FUSE_ERR_SHIFT             (26U)
/*! FUSE_ERR - Fuse error */
#define FSB_FUSE_EVNT_FUSE_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_FUSE_ERR_SHIFT)) & FSB_FUSE_EVNT_FUSE_ERR_MASK)

#define FSB_FUSE_EVNT_LOADING_MASK               (0x8000000U)
#define FSB_FUSE_EVNT_LOADING_SHIFT              (27U)
/*! LOADING - Shadow loading */
#define FSB_FUSE_EVNT_LOADING(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_LOADING_SHIFT)) & FSB_FUSE_EVNT_LOADING_MASK)

#define FSB_FUSE_EVNT_RLD_ERR_MASK               (0x10000000U)
#define FSB_FUSE_EVNT_RLD_ERR_SHIFT              (28U)
/*! RLD_ERR - Reload error */
#define FSB_FUSE_EVNT_RLD_ERR(x)                 (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_RLD_ERR_SHIFT)) & FSB_FUSE_EVNT_RLD_ERR_MASK)

#define FSB_FUSE_EVNT_RD_ERR_MASK                (0x20000000U)
#define FSB_FUSE_EVNT_RD_ERR_SHIFT               (29U)
/*! RD_ERR - Read error */
#define FSB_FUSE_EVNT_RD_ERR(x)                  (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_RD_ERR_SHIFT)) & FSB_FUSE_EVNT_RD_ERR_MASK)

#define FSB_FUSE_EVNT_ADDR_ERR_MASK              (0x80000000U)
#define FSB_FUSE_EVNT_ADDR_ERR_SHIFT             (31U)
/*! ADDR_ERR - Address error */
#define FSB_FUSE_EVNT_ADDR_ERR(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_EVNT_ADDR_ERR_SHIFT)) & FSB_FUSE_EVNT_ADDR_ERR_MASK)
/*! @} */

/*! @name FUSE_INT_EN - Fuse Interrupt Enable Register */
/*! @{ */

#define FSB_FUSE_INT_EN_INT_EN_MASK              (0xFF000000U)
#define FSB_FUSE_INT_EN_INT_EN_SHIFT             (24U)
/*! INT_EN - Interrupt Enables */
#define FSB_FUSE_INT_EN_INT_EN(x)                (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_INT_EN_INT_EN_SHIFT)) & FSB_FUSE_INT_EN_INT_EN_MASK)
/*! @} */

/*! @name FUSE_INT - Fuse Interrupt Register */
/*! @{ */

#define FSB_FUSE_INT_INT_MASK                    (0xFF000000U)
#define FSB_FUSE_INT_INT_SHIFT                   (24U)
/*! INT - Interrupts */
#define FSB_FUSE_INT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_INT_INT_SHIFT)) & FSB_FUSE_INT_INT_MASK)
/*! @} */

/*! @name UNPROG_CTR - Unprogrammed Fuse Counter */
/*! @{ */

#define FSB_UNPROG_CTR_CTR_MASK                  (0xFFFFU)
#define FSB_UNPROG_CTR_CTR_SHIFT                 (0U)
/*! CTR - Unprogrammed Fuse Counter */
#define FSB_UNPROG_CTR_CTR(x)                    (((uint32_t)(((uint32_t)(x)) << FSB_UNPROG_CTR_CTR_SHIFT)) & FSB_UNPROG_CTR_CTR_MASK)
/*! @} */

/*! @name FUSE - Fuse Value Registers */
/*! @{ */

#define FSB_FUSE_FUSE_MASK                       (0xFFFFFFFFU)
#define FSB_FUSE_FUSE_SHIFT                      (0U)
/*! FUSE - Fuse Values */
#define FSB_FUSE_FUSE(x)                         (((uint32_t)(((uint32_t)(x)) << FSB_FUSE_FUSE_SHIFT)) & FSB_FUSE_FUSE_MASK)
/*! @} */

/* The count of FSB_FUSE */
#define FSB_FUSE_COUNT                           (512U)


/*!
 * @}
 */ /* end of group FSB_Register_Masks */


/*!
 * @}
 */ /* end of group FSB_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_FSB_H_ */

