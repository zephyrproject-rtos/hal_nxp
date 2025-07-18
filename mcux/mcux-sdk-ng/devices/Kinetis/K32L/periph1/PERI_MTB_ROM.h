/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MTB_ROM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MTB_ROM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MTB_ROM
 *
 * CMSIS Peripheral Access Layer for MTB_ROM
 */

#if !defined(PERI_MTB_ROM_H_)
#define PERI_MTB_ROM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
   -- MTB_ROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_ROM_Peripheral_Access_Layer MTB_ROM Peripheral Access Layer
 * @{
 */

/** MTB_ROM - Size of Registers Arrays */
#define MTB_ROM_ENTRY_COUNT                       4u
#define MTB_ROM_COMPID_COUNT                      4u

/** MTB_ROM - Register Layout Typedef */
typedef struct {
  __I  uint32_t ENTRY[MTB_ROM_ENTRY_COUNT];        /**< Entry, array offset: 0x0, array step: 0x4 */
  __I  uint32_t TABLEMARK;                         /**< End of Table Marker Register, offset: 0x10 */
       uint8_t RESERVED_0[4024];
  __I  uint32_t SYSACCESS;                         /**< System Access Register, offset: 0xFCC */
  __I  uint32_t PERIPHID4;                         /**< Peripheral ID Register, offset: 0xFD0 */
  __I  uint32_t PERIPHID5;                         /**< Peripheral ID Register, offset: 0xFD4 */
  __I  uint32_t PERIPHID6;                         /**< Peripheral ID Register, offset: 0xFD8 */
  __I  uint32_t PERIPHID7;                         /**< Peripheral ID Register, offset: 0xFDC */
  __I  uint32_t PERIPHID0;                         /**< Peripheral ID Register, offset: 0xFE0 */
  __I  uint32_t PERIPHID1;                         /**< Peripheral ID Register, offset: 0xFE4 */
  __I  uint32_t PERIPHID2;                         /**< Peripheral ID Register, offset: 0xFE8 */
  __I  uint32_t PERIPHID3;                         /**< Peripheral ID Register, offset: 0xFEC */
  __I  uint32_t COMPID[MTB_ROM_COMPID_COUNT];      /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTB_ROM_Type;

/* ----------------------------------------------------------------------------
   -- MTB_ROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_ROM_Register_Masks MTB_ROM Register Masks
 * @{
 */

/*! @name ENTRY - Entry */
/*! @{ */

#define MTB_ROM_ENTRY_ENTRY_MASK                 (0xFFFFFFFFU)
#define MTB_ROM_ENTRY_ENTRY_SHIFT                (0U)
/*! ENTRY - ENTRY */
#define MTB_ROM_ENTRY_ENTRY(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_ROM_ENTRY_ENTRY_SHIFT)) & MTB_ROM_ENTRY_ENTRY_MASK)
/*! @} */

/*! @name TABLEMARK - End of Table Marker Register */
/*! @{ */

#define MTB_ROM_TABLEMARK_MARK_MASK              (0xFFFFFFFFU)
#define MTB_ROM_TABLEMARK_MARK_SHIFT             (0U)
/*! MARK - MARK */
#define MTB_ROM_TABLEMARK_MARK(x)                (((uint32_t)(((uint32_t)(x)) << MTB_ROM_TABLEMARK_MARK_SHIFT)) & MTB_ROM_TABLEMARK_MARK_MASK)
/*! @} */

/*! @name SYSACCESS - System Access Register */
/*! @{ */

#define MTB_ROM_SYSACCESS_SYSACCESS_MASK         (0xFFFFFFFFU)
#define MTB_ROM_SYSACCESS_SYSACCESS_SHIFT        (0U)
/*! SYSACCESS - SYSACCESS */
#define MTB_ROM_SYSACCESS_SYSACCESS(x)           (((uint32_t)(((uint32_t)(x)) << MTB_ROM_SYSACCESS_SYSACCESS_SHIFT)) & MTB_ROM_SYSACCESS_SYSACCESS_MASK)
/*! @} */

/*! @name PERIPHID4 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID4_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID4_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID4_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID4_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID4_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID5 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID5_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID5_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID5_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID5_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID5_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID6 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID6_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID6_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID6_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID6_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID6_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID7 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID7_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID7_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID7_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID7_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID7_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID0 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID0_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID0_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID0_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID0_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID0_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID1 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID1_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID1_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID1_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID1_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID1_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID2 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID2_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID2_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID2_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID2_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID2_PERIPHID_MASK)
/*! @} */

/*! @name PERIPHID3 - Peripheral ID Register */
/*! @{ */

#define MTB_ROM_PERIPHID3_PERIPHID_MASK          (0xFFFFFFFFU)
#define MTB_ROM_PERIPHID3_PERIPHID_SHIFT         (0U)
/*! PERIPHID - PERIPHID */
#define MTB_ROM_PERIPHID3_PERIPHID(x)            (((uint32_t)(((uint32_t)(x)) << MTB_ROM_PERIPHID3_PERIPHID_SHIFT)) & MTB_ROM_PERIPHID3_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define MTB_ROM_COMPID_COMPID_MASK               (0xFFFFFFFFU)
#define MTB_ROM_COMPID_COMPID_SHIFT              (0U)
/*! COMPID - Component ID */
#define MTB_ROM_COMPID_COMPID(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_ROM_COMPID_COMPID_SHIFT)) & MTB_ROM_COMPID_COMPID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MTB_ROM_Register_Masks */


/*!
 * @}
 */ /* end of group MTB_ROM_Peripheral_Access_Layer */


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


#endif  /* PERI_MTB_ROM_H_ */

