/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**                          MIMXRT1052CVJ5B
**                          MIMXRT1052CVL5B
**                          MIMXRT1052DVJ6B
**                          MIMXRT1052DVL6B
**                          MIMXRT105SDVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ROMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ROMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ROMC
 *
 * CMSIS Peripheral Access Layer for ROMC
 */

#if !defined(PERI_ROMC_H_)
#define PERI_ROMC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1051CVJ5B) || defined(CPU_MIMXRT1051CVL5B) || defined(CPU_MIMXRT1051DVJ6B) || defined(CPU_MIMXRT1051DVL6B))
#include "MIMXRT1051_COMMON.h"
#elif (defined(CPU_MIMXRT1052CVJ5B) || defined(CPU_MIMXRT1052CVL5B) || defined(CPU_MIMXRT1052DVJ6B) || defined(CPU_MIMXRT1052DVL6B))
#include "MIMXRT1052_COMMON.h"
#elif (defined(CPU_MIMXRT105SDVL6B))
#include "MIMXRT105S_COMMON.h"
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
   -- ROMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMC_Peripheral_Access_Layer ROMC Peripheral Access Layer
 * @{
 */

/** ROMC - Size of Registers Arrays */
#define ROMC_ROMPATCHD_COUNT                      8u
#define ROMC_ROMPATCHA_COUNT                      16u

/** ROMC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[212];
  __IO uint32_t ROMPATCHD[ROMC_ROMPATCHD_COUNT];   /**< ROMC Data Registers, array offset: 0xD4, array step: 0x4 */
  __IO uint32_t ROMPATCHCNTL;                      /**< ROMC Control Register, offset: 0xF4 */
       uint32_t ROMPATCHENH;                       /**< ROMC Enable Register High, offset: 0xF8 */
  __IO uint32_t ROMPATCHENL;                       /**< ROMC Enable Register Low, offset: 0xFC */
  __IO uint32_t ROMPATCHA[ROMC_ROMPATCHA_COUNT];   /**< ROMC Address Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[200];
  __IO uint32_t ROMPATCHSR;                        /**< ROMC Status Register, offset: 0x208 */
} ROMC_Type;

/* ----------------------------------------------------------------------------
   -- ROMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROMC_Register_Masks ROMC Register Masks
 * @{
 */

/*! @name ROMPATCHD - ROMC Data Registers */
/*! @{ */

#define ROMC_ROMPATCHD_DATAX_MASK                (0xFFFFFFFFU)
#define ROMC_ROMPATCHD_DATAX_SHIFT               (0U)
#define ROMC_ROMPATCHD_DATAX(x)                  (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHD_DATAX_SHIFT)) & ROMC_ROMPATCHD_DATAX_MASK)
/*! @} */

/*! @name ROMPATCHCNTL - ROMC Control Register */
/*! @{ */

#define ROMC_ROMPATCHCNTL_DATAFIX_MASK           (0xFFU)
#define ROMC_ROMPATCHCNTL_DATAFIX_SHIFT          (0U)
/*! DATAFIX
 *  0b00000000..Address comparator triggers a opcode patch
 *  0b00000001..Address comparator triggers a data fix
 */
#define ROMC_ROMPATCHCNTL_DATAFIX(x)             (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHCNTL_DATAFIX_SHIFT)) & ROMC_ROMPATCHCNTL_DATAFIX_MASK)

#define ROMC_ROMPATCHCNTL_DIS_MASK               (0x20000000U)
#define ROMC_ROMPATCHCNTL_DIS_SHIFT              (29U)
/*! DIS
 *  0b0..Does not affect any ROMC functions (default)
 *  0b1..Disable all ROMC functions: data fixing, and opcode patching
 */
#define ROMC_ROMPATCHCNTL_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHCNTL_DIS_SHIFT)) & ROMC_ROMPATCHCNTL_DIS_MASK)
/*! @} */

/*! @name ROMPATCHENL - ROMC Enable Register Low */
/*! @{ */

#define ROMC_ROMPATCHENL_ENABLE_MASK             (0xFFFFU)
#define ROMC_ROMPATCHENL_ENABLE_SHIFT            (0U)
/*! ENABLE
 *  0b0000000000000000..Address comparator disabled
 *  0b0000000000000001..Address comparator enabled, ROMC will trigger a opcode patch or data fix event upon matching of the associated address
 */
#define ROMC_ROMPATCHENL_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHENL_ENABLE_SHIFT)) & ROMC_ROMPATCHENL_ENABLE_MASK)
/*! @} */

/*! @name ROMPATCHA - ROMC Address Registers */
/*! @{ */

#define ROMC_ROMPATCHA_THUMBX_MASK               (0x1U)
#define ROMC_ROMPATCHA_THUMBX_SHIFT              (0U)
/*! THUMBX
 *  0b0..Arm patch
 *  0b1..THUMB patch (ignore if data fix)
 */
#define ROMC_ROMPATCHA_THUMBX(x)                 (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHA_THUMBX_SHIFT)) & ROMC_ROMPATCHA_THUMBX_MASK)

#define ROMC_ROMPATCHA_ADDRX_MASK                (0x7FFFFEU)
#define ROMC_ROMPATCHA_ADDRX_SHIFT               (1U)
#define ROMC_ROMPATCHA_ADDRX(x)                  (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHA_ADDRX_SHIFT)) & ROMC_ROMPATCHA_ADDRX_MASK)
/*! @} */

/*! @name ROMPATCHSR - ROMC Status Register */
/*! @{ */

#define ROMC_ROMPATCHSR_SOURCE_MASK              (0x3FU)
#define ROMC_ROMPATCHSR_SOURCE_SHIFT             (0U)
/*! SOURCE
 *  0b000000..Address Comparator 0 matched
 *  0b000001..Address Comparator 1 matched
 *  0b001111..Address Comparator 15 matched
 */
#define ROMC_ROMPATCHSR_SOURCE(x)                (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHSR_SOURCE_SHIFT)) & ROMC_ROMPATCHSR_SOURCE_MASK)

#define ROMC_ROMPATCHSR_SW_MASK                  (0x20000U)
#define ROMC_ROMPATCHSR_SW_SHIFT                 (17U)
/*! SW
 *  0b0..no event or comparator collisions
 *  0b1..a collision has occurred
 */
#define ROMC_ROMPATCHSR_SW(x)                    (((uint32_t)(((uint32_t)(x)) << ROMC_ROMPATCHSR_SW_SHIFT)) & ROMC_ROMPATCHSR_SW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ROMC_Register_Masks */


/*!
 * @}
 */ /* end of group ROMC_Peripheral_Access_Layer */


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


#endif  /* PERI_ROMC_H_ */

