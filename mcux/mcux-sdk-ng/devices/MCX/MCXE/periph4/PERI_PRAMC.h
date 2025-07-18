/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PRAMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_PRAMC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for PRAMC
 *
 * CMSIS Peripheral Access Layer for PRAMC
 */

#if !defined(PERI_PRAMC_H_)
#define PERI_PRAMC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- PRAMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PRAMC_Peripheral_Access_Layer PRAMC Peripheral Access Layer
 * @{
 */

/** PRAMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRCR1;                             /**< Platform RAM Configuration register 1, offset: 0x0 */
} PRAMC_Type;

/* ----------------------------------------------------------------------------
   -- PRAMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PRAMC_Register_Masks PRAMC Register Masks
 * @{
 */

/*! @name PRCR1 - Platform RAM Configuration register 1 */
/*! @{ */

#define PRAMC_PRCR1_FT_DIS_MASK                  (0x1U)
#define PRAMC_PRCR1_FT_DIS_SHIFT                 (0U)
/*! FT_DIS - Flow-through disabled
 *  0b0..RAM read data is passed directly to the system bus, incurring no additional latency
 *  0b1..RAM read data is registered prior to returning on the system bus, incurring one extra cycle of latency
 */
#define PRAMC_PRCR1_FT_DIS(x)                    (((uint32_t)(((uint32_t)(x)) << PRAMC_PRCR1_FT_DIS_SHIFT)) & PRAMC_PRCR1_FT_DIS_MASK)

#define PRAMC_PRCR1_P0_BO_DIS_MASK               (0x40U)
#define PRAMC_PRCR1_P0_BO_DIS_SHIFT              (6U)
/*! P0_BO_DIS - Port p0 read burst optimization disable.
 *  0b0..64-bit WRP4 read bursts are optimized such that the controller returns a 2-1-1-1 response when PRCR1[FT_DIS ]=1
 *  0b1..64-bit WRP4 read bursts are not optimized; the controller returns a 2-2-2-2 response when PRCR1[FT_DIS ]=1
 */
#define PRAMC_PRCR1_P0_BO_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << PRAMC_PRCR1_P0_BO_DIS_SHIFT)) & PRAMC_PRCR1_P0_BO_DIS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PRAMC_Register_Masks */


/*!
 * @}
 */ /* end of group PRAMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PRAMC_H_ */

