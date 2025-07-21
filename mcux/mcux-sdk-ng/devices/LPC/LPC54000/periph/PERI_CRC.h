/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CRC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CRC
 *
 * CMSIS Peripheral Access Layer for CRC
 */

#if !defined(PERI_CRC_H_)
#define PERI_CRC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MODE;                              /**< CRC mode register, offset: 0x0 */
  __IO uint32_t SEED;                              /**< CRC seed register, offset: 0x4 */
  union {                                          /* offset: 0x8 */
    __I  uint32_t SUM;                               /**< CRC checksum register, offset: 0x8 */
    __O  uint32_t WR_DATA;                           /**< CRC data register, offset: 0x8 */
  };
} CRC_Type;

/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/*! @name MODE - CRC mode register */
/*! @{ */

#define CRC_MODE_CRC_POLY_MASK                   (0x3U)
#define CRC_MODE_CRC_POLY_SHIFT                  (0U)
/*! CRC_POLY - CRC polynomial: 1X = CRC-32 polynomial 01 = CRC-16 polynomial 00 = CRC-CCITT polynomial */
#define CRC_MODE_CRC_POLY(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CRC_POLY_SHIFT)) & CRC_MODE_CRC_POLY_MASK)

#define CRC_MODE_BIT_RVS_WR_MASK                 (0x4U)
#define CRC_MODE_BIT_RVS_WR_SHIFT                (2U)
/*! BIT_RVS_WR - Data bit order: 1 = Bit order reverse for CRC_WR_DATA (per byte) 0 = No bit order reverse for CRC_WR_DATA (per byte) */
#define CRC_MODE_BIT_RVS_WR(x)                   (((uint32_t)(((uint32_t)(x)) << CRC_MODE_BIT_RVS_WR_SHIFT)) & CRC_MODE_BIT_RVS_WR_MASK)

#define CRC_MODE_CMPL_WR_MASK                    (0x8U)
#define CRC_MODE_CMPL_WR_SHIFT                   (3U)
/*! CMPL_WR - Data complement: 1 = 1's complement for CRC_WR_DATA 0 = No 1's complement for CRC_WR_DATA */
#define CRC_MODE_CMPL_WR(x)                      (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CMPL_WR_SHIFT)) & CRC_MODE_CMPL_WR_MASK)

#define CRC_MODE_BIT_RVS_SUM_MASK                (0x10U)
#define CRC_MODE_BIT_RVS_SUM_SHIFT               (4U)
/*! BIT_RVS_SUM - CRC sum bit order: 1 = Bit order reverse for CRC_SUM 0 = No bit order reverse for CRC_SUM */
#define CRC_MODE_BIT_RVS_SUM(x)                  (((uint32_t)(((uint32_t)(x)) << CRC_MODE_BIT_RVS_SUM_SHIFT)) & CRC_MODE_BIT_RVS_SUM_MASK)

#define CRC_MODE_CMPL_SUM_MASK                   (0x20U)
#define CRC_MODE_CMPL_SUM_SHIFT                  (5U)
/*! CMPL_SUM - CRC sum complement: 1 = 1's complement for CRC_SUM 0 = No 1's complement for CRC_SUM */
#define CRC_MODE_CMPL_SUM(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_MODE_CMPL_SUM_SHIFT)) & CRC_MODE_CMPL_SUM_MASK)
/*! @} */

/*! @name SEED - CRC seed register */
/*! @{ */

#define CRC_SEED_CRC_SEED_MASK                   (0xFFFFFFFFU)
#define CRC_SEED_CRC_SEED_SHIFT                  (0U)
/*! CRC_SEED - A write access to this register will load CRC seed value to CRC_SUM register with
 *    selected bit order and 1's complement pre-processes. A write access to this register will
 *    overrule the CRC calculation in progresses.
 */
#define CRC_SEED_CRC_SEED(x)                     (((uint32_t)(((uint32_t)(x)) << CRC_SEED_CRC_SEED_SHIFT)) & CRC_SEED_CRC_SEED_MASK)
/*! @} */

/*! @name SUM - CRC checksum register */
/*! @{ */

#define CRC_SUM_CRC_SUM_MASK                     (0xFFFFFFFFU)
#define CRC_SUM_CRC_SUM_SHIFT                    (0U)
/*! CRC_SUM - The most recent CRC sum can be read through this register with selected bit order and 1's complement post-processes. */
#define CRC_SUM_CRC_SUM(x)                       (((uint32_t)(((uint32_t)(x)) << CRC_SUM_CRC_SUM_SHIFT)) & CRC_SUM_CRC_SUM_MASK)
/*! @} */

/*! @name WR_DATA - CRC data register */
/*! @{ */

#define CRC_WR_DATA_CRC_WR_DATA_MASK             (0xFFFFFFFFU)
#define CRC_WR_DATA_CRC_WR_DATA_SHIFT            (0U)
/*! CRC_WR_DATA - Data written to this register will be taken to perform CRC calculation with
 *    selected bit order and 1's complement pre-process. Any write size 8, 16 or 32-bit are allowed and
 *    accept back-to-back transactions.
 */
#define CRC_WR_DATA_CRC_WR_DATA(x)               (((uint32_t)(((uint32_t)(x)) << CRC_WR_DATA_CRC_WR_DATA_SHIFT)) & CRC_WR_DATA_CRC_WR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


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


#endif  /* PERI_CRC_H_ */

