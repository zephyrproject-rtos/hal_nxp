/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 1.0, 2017-05-19
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ROM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ROM.h
 * @version 1.0
 * @date 2017-05-19
 * @brief CMSIS Peripheral Access Layer for ROM
 *
 * CMSIS Peripheral Access Layer for ROM
 */

#if !defined(ROM_H_)
#define ROM_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
   -- ROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Peripheral_Access_Layer ROM Peripheral Access Layer
 * @{
 */

/** ROM - Size of Registers Arrays */
#define ROM_ENTRY_COUNT                           1u
#define ROM_COMPID_COUNT                          4u

/** ROM - Register Layout Typedef */
typedef struct {
  __I  uint32_t ENTRY[ROM_ENTRY_COUNT];            /**< Entry, array offset: 0x0, array step: 0x4 */
  __I  uint32_t TABLEMARK;                         /**< End of Table Marker Register, offset: 0x4 */
       uint8_t RESERVED_0[4036];
  __I  uint32_t SYSACCESS;                         /**< System Access Register, offset: 0xFCC */
  __I  uint32_t PERIPHID4;                         /**< Peripheral ID Register, offset: 0xFD0 */
  __I  uint32_t PERIPHID5;                         /**< Peripheral ID Register, offset: 0xFD4 */
  __I  uint32_t PERIPHID6;                         /**< Peripheral ID Register, offset: 0xFD8 */
  __I  uint32_t PERIPHID7;                         /**< Peripheral ID Register, offset: 0xFDC */
  __I  uint32_t PERIPHID0;                         /**< Peripheral ID Register, offset: 0xFE0 */
  __I  uint32_t PERIPHID1;                         /**< Peripheral ID Register, offset: 0xFE4 */
  __I  uint32_t PERIPHID2;                         /**< Peripheral ID Register, offset: 0xFE8 */
  __I  uint32_t PERIPHID3;                         /**< Peripheral ID Register, offset: 0xFEC */
  __I  uint32_t COMPID[ROM_COMPID_COUNT];          /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} ROM_Type;

/* ----------------------------------------------------------------------------
   -- ROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Register_Masks ROM Register Masks
 * @{
 */

/*! @name ENTRY - Entry */
/*! @{ */

#define ROM_ENTRY_ENTRY_MASK                     (0xFFFFFFFFU)
#define ROM_ENTRY_ENTRY_SHIFT                    (0U)
/*! ENTRY - ENTRY */
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x)) << ROM_ENTRY_ENTRY_SHIFT)) & ROM_ENTRY_ENTRY_MASK)
/*! @} */

/*! @name TABLEMARK - End of Table Marker Register */
/*! @{ */

#define ROM_TABLEMARK_MARK_MASK                  (0xFFFFFFFFU)
#define ROM_TABLEMARK_MARK_SHIFT                 (0U)
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x)) << ROM_TABLEMARK_MARK_SHIFT)) & ROM_TABLEMARK_MARK_MASK)
/*! @} */

/*! @name SYSACCESS - System Access Register */
/*! @{ */

#define ROM_SYSACCESS_SYSACCESS_MASK             (0xFFFFFFFFU)
#define ROM_SYSACCESS_SYSACCESS_SHIFT            (0U)
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x)) << ROM_SYSACCESS_SYSACCESS_SHIFT)) & ROM_SYSACCESS_SYSACCESS_MASK)
/*! @} */

/*! @name PERIPHID4 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID4_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID4_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID4_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID4_PERIPHID_SHIFT)) & ROM_PERIPHID4_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID5 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID5_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID5_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID5_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID5_PERIPHID_SHIFT)) & ROM_PERIPHID5_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID6 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID6_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID6_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID6_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID6_PERIPHID_SHIFT)) & ROM_PERIPHID6_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID7 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID7_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID7_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID7_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID7_PERIPHID_SHIFT)) & ROM_PERIPHID7_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID0 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID0_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID0_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID0_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID0_PERIPHID_SHIFT)) & ROM_PERIPHID0_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID1 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID1_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID1_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID1_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID1_PERIPHID_SHIFT)) & ROM_PERIPHID1_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID2 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID2_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID2_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID2_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID2_PERIPHID_SHIFT)) & ROM_PERIPHID2_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID3 - Peripheral ID Register */
/*! @{ */

#define ROM_PERIPHID3_PERIPHID_MASK              (0xFFFFFFFFU)
#define ROM_PERIPHID3_PERIPHID_SHIFT             (0U)
#define ROM_PERIPHID3_PERIPHID(x)                (((uint32_t)(((uint32_t)(x)) << ROM_PERIPHID3_PERIPHID_SHIFT)) & ROM_PERIPHID3_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define ROM_COMPID_COMPID_MASK                   (0xFFFFFFFFU)
#define ROM_COMPID_COMPID_SHIFT                  (0U)
/*! COMPID - Component ID */
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x)) << ROM_COMPID_COMPID_SHIFT)) & ROM_COMPID_COMPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ROM_Register_Masks */


/*!
 * @}
 */ /* end of group ROM_Peripheral_Access_Layer */


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


#endif  /* ROM_H_ */

