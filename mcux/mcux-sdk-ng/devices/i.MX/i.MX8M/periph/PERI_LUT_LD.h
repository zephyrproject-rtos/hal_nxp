/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LUT_LD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LUT_LD.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LUT_LD
 *
 * CMSIS Peripheral Access Layer for LUT_LD
 */

#if !defined(PERI_LUT_LD_H_)
#define PERI_LUT_LD_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- LUT_LD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LUT_LD_Peripheral_Access_Layer LUT_LD Peripheral Access Layer
 * @{
 */

/** LUT_LD - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control/Status register for LUT Loader., offset: 0x0 */
    __IO uint32_t SET;                               /**< Control/Status register for LUT Loader., offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control/Status register for LUT Loader., offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control/Status register for LUT Loader., offset: 0xC */
  } CTRL_STATUS;
  __IO uint32_t BASE_ADDR;                         /**< Address for data fetch., offset: 0x10 */
} LUT_LD_Type;

/* ----------------------------------------------------------------------------
   -- LUT_LD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LUT_LD_Register_Masks LUT_LD Register Masks
 * @{
 */

/*! @name CTRL_STATUS - Control/Status register for LUT Loader. */
/*! @{ */

#define LUT_LD_CTRL_STATUS_ENABLE_MASK           (0x1U)
#define LUT_LD_CTRL_STATUS_ENABLE_SHIFT          (0U)
/*! ENABLE - Enable LUT_LD */
#define LUT_LD_CTRL_STATUS_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << LUT_LD_CTRL_STATUS_ENABLE_SHIFT)) & LUT_LD_CTRL_STATUS_ENABLE_MASK)

#define LUT_LD_CTRL_STATUS_BYTES_PER_REQ_MASK    (0x2U)
#define LUT_LD_CTRL_STATUS_BYTES_PER_REQ_SHIFT   (1U)
/*! BYTES_PER_REQ - bytes per request control */
#define LUT_LD_CTRL_STATUS_BYTES_PER_REQ(x)      (((uint32_t)(((uint32_t)(x)) << LUT_LD_CTRL_STATUS_BYTES_PER_REQ_SHIFT)) & LUT_LD_CTRL_STATUS_BYTES_PER_REQ_MASK)

#define LUT_LD_CTRL_STATUS_RD_ERR_EN_MASK        (0x100U)
#define LUT_LD_CTRL_STATUS_RD_ERR_EN_SHIFT       (8U)
/*! RD_ERR_EN - AXI Read Error IRQ enable. */
#define LUT_LD_CTRL_STATUS_RD_ERR_EN(x)          (((uint32_t)(((uint32_t)(x)) << LUT_LD_CTRL_STATUS_RD_ERR_EN_SHIFT)) & LUT_LD_CTRL_STATUS_RD_ERR_EN_MASK)

#define LUT_LD_CTRL_STATUS_RD_ERR_MASK           (0x10000U)
#define LUT_LD_CTRL_STATUS_RD_ERR_SHIFT          (16U)
/*! RD_ERR - AXI Read Error. */
#define LUT_LD_CTRL_STATUS_RD_ERR(x)             (((uint32_t)(((uint32_t)(x)) << LUT_LD_CTRL_STATUS_RD_ERR_SHIFT)) & LUT_LD_CTRL_STATUS_RD_ERR_MASK)
/*! @} */

/*! @name BASE_ADDR - Address for data fetch. */
/*! @{ */

#define LUT_LD_BASE_ADDR_BASE_ADDR_MASK          (0xFFFFFFFFU)
#define LUT_LD_BASE_ADDR_BASE_ADDR_SHIFT         (0U)
/*! BASE_ADDR - Base Address */
#define LUT_LD_BASE_ADDR_BASE_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << LUT_LD_BASE_ADDR_BASE_ADDR_SHIFT)) & LUT_LD_BASE_ADDR_BASE_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LUT_LD_Register_Masks */


/*!
 * @}
 */ /* end of group LUT_LD_Peripheral_Access_Layer */


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


#endif  /* PERI_LUT_LD_H_ */

