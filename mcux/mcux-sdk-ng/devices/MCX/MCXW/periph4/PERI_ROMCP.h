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
**         CMSIS Peripheral Access Layer for ROMCP
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
 * @file PERI_ROMCP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ROMCP
 *
 * CMSIS Peripheral Access Layer for ROMCP
 */

#if !defined(PERI_ROMCP_H_)
#define PERI_ROMCP_H_                            /**< Symbol preventing repeated inclusion */

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
   -- ROMCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMCP_Peripheral_Access_Layer ROMCP Peripheral Access Layer
 * @{
 */

/** ROMCP - Size of Registers Arrays */
#define ROMCP_ROMPATCHD_COUNT                     8u
#define ROMCP_ROMPATCHA_COUNT                     16u

/** ROMCP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[212];
  __IO uint32_t ROMPATCHD[ROMCP_ROMPATCHD_COUNT];  /**< ROMC Data Registers, array offset: 0xD4, array step: 0x4 */
  __IO uint32_t ROMPATCHCNTL;                      /**< ROMC Control Register, offset: 0xF4 */
       uint32_t ROMPATCHENH;                       /**< ROMC Enable Register High, offset: 0xF8 */
  __IO uint32_t ROMPATCHENL;                       /**< ROMC Enable Register Low, offset: 0xFC */
  __IO uint32_t ROMPATCHA[ROMCP_ROMPATCHA_COUNT];  /**< ROMC Address Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[200];
  __IO uint32_t ROMPATCHSR;                        /**< ROMC Status Register, offset: 0x208 */
} ROMCP_Type;

/* ----------------------------------------------------------------------------
   -- ROMCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMCP_Register_Masks ROMCP Register Masks
 * @{
 */

/*! @name ROMPATCHD - ROMC Data Registers */
/*! @{ */

#define ROMCP_ROMPATCHD_DATAX_MASK               (0xFFFFFFFFU)
#define ROMCP_ROMPATCHD_DATAX_SHIFT              (0U)
/*! DATAX - DATAX */
#define ROMCP_ROMPATCHD_DATAX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHD_DATAX_SHIFT)) & ROMCP_ROMPATCHD_DATAX_MASK)
/*! @} */

/*! @name ROMPATCHCNTL - ROMC Control Register */
/*! @{ */

#define ROMCP_ROMPATCHCNTL_DATAFIX_MASK          (0xFFU)
#define ROMCP_ROMPATCHCNTL_DATAFIX_SHIFT         (0U)
/*! DATAFIX - DATAFIX
 *  0b00000000..Address comparator triggers a opcode patch
 *  0b00000001..Address comparator triggers a data fix
 */
#define ROMCP_ROMPATCHCNTL_DATAFIX(x)            (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DATAFIX_SHIFT)) & ROMCP_ROMPATCHCNTL_DATAFIX_MASK)

#define ROMCP_ROMPATCHCNTL_DIS_MASK              (0x20000000U)
#define ROMCP_ROMPATCHCNTL_DIS_SHIFT             (29U)
/*! DIS - DIS
 *  0b0..Does not affect any ROMC functions (default)
 *  0b1..Disable all ROMC functions: data fixing, and opcode patching
 */
#define ROMCP_ROMPATCHCNTL_DIS(x)                (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHCNTL_DIS_SHIFT)) & ROMCP_ROMPATCHCNTL_DIS_MASK)
/*! @} */

/*! @name ROMPATCHENL - ROMC Enable Register Low */
/*! @{ */

#define ROMCP_ROMPATCHENL_ENABLE_MASK            (0xFFFFU)
#define ROMCP_ROMPATCHENL_ENABLE_SHIFT           (0U)
/*! ENABLE - ENABLE
 *  0b0000000000000000..Address comparator disabled
 *  0b0000000000000001..Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the associated address
 */
#define ROMCP_ROMPATCHENL_ENABLE(x)              (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHENL_ENABLE_SHIFT)) & ROMCP_ROMPATCHENL_ENABLE_MASK)
/*! @} */

/*! @name ROMPATCHA - ROMC Address Registers */
/*! @{ */

#define ROMCP_ROMPATCHA_THUMBX_MASK              (0x1U)
#define ROMCP_ROMPATCHA_THUMBX_SHIFT             (0U)
/*! THUMBX - THUMBX
 *  0b0..ARM patch
 *  0b1..THUMB patch (ignore if data fix)
 */
#define ROMCP_ROMPATCHA_THUMBX(x)                (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHA_THUMBX_SHIFT)) & ROMCP_ROMPATCHA_THUMBX_MASK)

#define ROMCP_ROMPATCHA_ADDRX_MASK               (0x7FFFFEU)
#define ROMCP_ROMPATCHA_ADDRX_SHIFT              (1U)
/*! ADDRX - ADDRX */
#define ROMCP_ROMPATCHA_ADDRX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHA_ADDRX_SHIFT)) & ROMCP_ROMPATCHA_ADDRX_MASK)
/*! @} */

/*! @name ROMPATCHSR - ROMC Status Register */
/*! @{ */

#define ROMCP_ROMPATCHSR_SOURCE_MASK             (0x3FU)
#define ROMCP_ROMPATCHSR_SOURCE_SHIFT            (0U)
/*! SOURCE - SOURCE
 *  0b000000..Address Comparator 0 matched
 *  0b000001..Address Comparator 1 matched
 *  0b000010..Address Comparator 2 matched
 *  0b000011..Address Comparator 3 matched
 *  0b000100..Address Comparator 4 matched
 *  0b000101..Address Comparator 5 matched
 *  0b000110..Address Comparator 6 matched
 *  0b000111..Address Comparator 7 matched
 *  0b001000..Address Comparator 8 matched
 *  0b001001..Address Comparator 9 matched
 *  0b001010..Address Comparator 10 matched
 *  0b001011..Address Comparator 11 matched
 *  0b001100..Address Comparator 12 matched
 *  0b001101..Address Comparator 13 matched
 *  0b001110..Address Comparator 14 matched
 *  0b001111..Address Comparator 15 matched
 */
#define ROMCP_ROMPATCHSR_SOURCE(x)               (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHSR_SOURCE_SHIFT)) & ROMCP_ROMPATCHSR_SOURCE_MASK)

#define ROMCP_ROMPATCHSR_SW_MASK                 (0x20000U)
#define ROMCP_ROMPATCHSR_SW_SHIFT                (17U)
/*! SW - SW
 *  0b0..no event or comparator collisions
 *  0b1..a collision has occurred
 */
#define ROMCP_ROMPATCHSR_SW(x)                   (((uint32_t)(((uint32_t)(x)) << ROMCP_ROMPATCHSR_SW_SHIFT)) & ROMCP_ROMPATCHSR_SW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ROMCP_Register_Masks */


/*!
 * @}
 */ /* end of group ROMCP_Peripheral_Access_Layer */


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


#endif  /* PERI_ROMCP_H_ */

