/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RADIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_RADIO.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RADIO
 *
 * CMSIS Peripheral Access Layer for RADIO
 */

#if !defined(PERI_RADIO_H_)
#define PERI_RADIO_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
   -- RADIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RADIO_Peripheral_Access_Layer RADIO Peripheral Access Layer
 * @{
 */

/** RADIO - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[255];
  __IO uint32_t PAGE_SELECT;                       /**< BLE Radio register map page select, offset: 0xFF */
} RADIO_Type;

/* ----------------------------------------------------------------------------
   -- RADIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RADIO_Register_Masks RADIO Register Masks
 * @{
 */

/*! @name PAGE_SELECT - BLE Radio register map page select */
/*! @{ */

#define RADIO_PAGE_SELECT_PAGE_SELECT_MASK       (0x3U)
#define RADIO_PAGE_SELECT_PAGE_SELECT_SHIFT      (0U)
/*! PAGE_SELECT - BLE Radio register map page select */
#define RADIO_PAGE_SELECT_PAGE_SELECT(x)         (((uint32_t)(((uint32_t)(x)) << RADIO_PAGE_SELECT_PAGE_SELECT_SHIFT)) & RADIO_PAGE_SELECT_PAGE_SELECT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RADIO_Register_Masks */


/*!
 * @}
 */ /* end of group RADIO_Peripheral_Access_Layer */


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


#endif  /* PERI_RADIO_H_ */

