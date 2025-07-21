/*
** ###################################################################
**     Processors:          MKE12Z512VLH9
**                          MKE12Z512VLL9
**                          MKE13Z512VLH9
**                          MKE13Z512VLL9
**                          MKE17Z512VLH9
**                          MKE17Z512VLL9
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MTBDWTROM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-03-01)
**         Initial version.
**     - rev. 2.0 (2023-10-08)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MTBDWTROM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MTBDWTROM
 *
 * CMSIS Peripheral Access Layer for MTBDWTROM
 */

#if !defined(PERI_MTBDWTROM_H_)
#define PERI_MTBDWTROM_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z512VLH9) || defined(CPU_MKE12Z512VLL9))
#include "MKE12Z9_COMMON.h"
#elif (defined(CPU_MKE13Z512VLH9) || defined(CPU_MKE13Z512VLL9))
#include "MKE13Z9_COMMON.h"
#elif (defined(CPU_MKE17Z512VLH9) || defined(CPU_MKE17Z512VLL9))
#include "MKE17Z9_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- MTBDWTROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWTROM_Peripheral_Access_Layer MTBDWTROM Peripheral Access Layer
 * @{
 */

/** MTBDWTROM - Size of Registers Arrays */
#define MTBDWTROM_ENTRY_COUNT                     4u
#define MTBDWTROM_PERIPHID_COUNT                  8u
#define MTBDWTROM_COMPID_COUNT                    4u

/** MTBDWTROM - Register Layout Typedef */
typedef struct {
  __I  uint32_t ENTRY[MTBDWTROM_ENTRY_COUNT];      /**< Entry, array offset: 0x0, array step: 0x4 */
  __I  uint32_t TABLEMARK;                         /**< End of Table Marker Register, offset: 0x10 */
       uint8_t RESERVED_0[4024];
  __I  uint32_t SYSACCESS;                         /**< System Access Register, offset: 0xFCC */
  __I  uint32_t PERIPHID[MTBDWTROM_PERIPHID_COUNT]; /**< Peripheral ID Register, array offset: 0xFD0, array step: 0x4 */
  __I  uint32_t COMPID[MTBDWTROM_COMPID_COUNT];    /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTBDWTROM_Type;

/* ----------------------------------------------------------------------------
   -- MTBDWTROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTBDWTROM_Register_Masks MTBDWTROM Register Masks
 * @{
 */

/*! @name ENTRY - Entry */
/*! @{ */

#define MTBDWTROM_ENTRY_ENTRY_MASK               (0xFFFFFFFFU)
#define MTBDWTROM_ENTRY_ENTRY_SHIFT              (0U)
/*! ENTRY - ENTRY */
#define MTBDWTROM_ENTRY_ENTRY(x)                 (((uint32_t)(((uint32_t)(x)) << MTBDWTROM_ENTRY_ENTRY_SHIFT)) & MTBDWTROM_ENTRY_ENTRY_MASK)
/*! @} */

/*! @name TABLEMARK - End of Table Marker Register */
/*! @{ */

#define MTBDWTROM_TABLEMARK_MARK_MASK            (0xFFFFFFFFU)
#define MTBDWTROM_TABLEMARK_MARK_SHIFT           (0U)
/*! MARK - MARK */
#define MTBDWTROM_TABLEMARK_MARK(x)              (((uint32_t)(((uint32_t)(x)) << MTBDWTROM_TABLEMARK_MARK_SHIFT)) & MTBDWTROM_TABLEMARK_MARK_MASK)
/*! @} */

/*! @name SYSACCESS - System Access Register */
/*! @{ */

#define MTBDWTROM_SYSACCESS_SYSACCESS_MASK       (0xFFFFFFFFU)
#define MTBDWTROM_SYSACCESS_SYSACCESS_SHIFT      (0U)
/*! SYSACCESS - SYSACCESS */
#define MTBDWTROM_SYSACCESS_SYSACCESS(x)         (((uint32_t)(((uint32_t)(x)) << MTBDWTROM_SYSACCESS_SYSACCESS_SHIFT)) & MTBDWTROM_SYSACCESS_SYSACCESS_MASK)
/*! @} */

/*! @name PERIPHID - Peripheral ID Register */
/*! @{ */

#define MTBDWTROM_PERIPHID_PERIPHID_MASK         (0xFFFFFFFFU)
#define MTBDWTROM_PERIPHID_PERIPHID_SHIFT        (0U)
/*! PERIPHID - PERIPHID */
#define MTBDWTROM_PERIPHID_PERIPHID(x)           (((uint32_t)(((uint32_t)(x)) << MTBDWTROM_PERIPHID_PERIPHID_SHIFT)) & MTBDWTROM_PERIPHID_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define MTBDWTROM_COMPID_COMPID_MASK             (0xFFFFFFFFU)
#define MTBDWTROM_COMPID_COMPID_SHIFT            (0U)
/*! COMPID - Component ID */
#define MTBDWTROM_COMPID_COMPID(x)               (((uint32_t)(((uint32_t)(x)) << MTBDWTROM_COMPID_COMPID_SHIFT)) & MTBDWTROM_COMPID_COMPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MTBDWTROM_Register_Masks */


/*!
 * @}
 */ /* end of group MTBDWTROM_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_MTBDWTROM_H_ */

