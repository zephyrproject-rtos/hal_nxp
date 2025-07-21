/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PKC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PKC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PKC
 *
 * CMSIS Peripheral Access Layer for PKC
 */

#if !defined(PERI_PKC_H_)
#define PERI_PKC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- PKC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PKC_Peripheral_Access_Layer PKC Peripheral Access Layer
 * @{
 */

/** PKC - Register Layout Typedef */
typedef struct {
  __I  uint32_t PKC_STATUS;                        /**< Status register, offset: 0x0 */
  __IO uint32_t PKC_CTRL;                          /**< Control register, offset: 0x4 */
  __IO uint32_t PKC_CFG;                           /**< Configuration register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PKC_MODE1;                         /**< Mode register, parameter set 1, offset: 0x10 */
  __IO uint32_t PKC_XYPTR1;                        /**< X+Y pointer register, parameter set 1, offset: 0x14 */
  __IO uint32_t PKC_ZRPTR1;                        /**< Z+R pointer register, parameter set 1, offset: 0x18 */
  __IO uint32_t PKC_LEN1;                          /**< Length register, parameter set 1, offset: 0x1C */
  __IO uint32_t PKC_MODE2;                         /**< Mode register, parameter set 2, offset: 0x20 */
  __IO uint32_t PKC_XYPTR2;                        /**< X+Y pointer register, parameter set 2, offset: 0x24 */
  __IO uint32_t PKC_ZRPTR2;                        /**< Z+R pointer register, parameter set 2, offset: 0x28 */
  __IO uint32_t PKC_LEN2;                          /**< Length register, parameter set 2, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t PKC_UPTR;                          /**< Universal pointer FUP program, offset: 0x40 */
  __IO uint32_t PKC_UPTRT;                         /**< Universal pointer FUP table, offset: 0x44 */
  __IO uint32_t PKC_ULEN;                          /**< Universal pointer length, offset: 0x48 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PKC_MCDATA;                        /**< MC pattern data interface, offset: 0x50 */
       uint8_t RESERVED_3[12];
  __I  uint32_t PKC_VERSION;                       /**< PKC version register, offset: 0x60 */
       uint8_t RESERVED_4[3916];
  __O  uint32_t PKC_SOFT_RST;                      /**< Software reset, offset: 0xFB0 */
       uint8_t RESERVED_5[12];
  __I  uint32_t PKC_ACCESS_ERR;                    /**< Access Error, offset: 0xFC0 */
  __O  uint32_t PKC_ACCESS_ERR_CLR;                /**< Clear Access Error, offset: 0xFC4 */
       uint8_t RESERVED_6[16];
  __O  uint32_t PKC_INT_CLR_ENABLE;                /**< Interrupt enable clear, offset: 0xFD8 */
  __O  uint32_t PKC_INT_SET_ENABLE;                /**< Interrupt enable set, offset: 0xFDC */
  __I  uint32_t PKC_INT_STATUS;                    /**< Interrupt status, offset: 0xFE0 */
  __I  uint32_t PKC_INT_ENABLE;                    /**< Interrupt enable, offset: 0xFE4 */
  __O  uint32_t PKC_INT_CLR_STATUS;                /**< Interrupt status clear, offset: 0xFE8 */
  __O  uint32_t PKC_INT_SET_STATUS;                /**< Interrupt status set, offset: 0xFEC */
       uint8_t RESERVED_7[12];
  __I  uint32_t PKC_MODULE_ID;                     /**< Module ID, offset: 0xFFC */
} PKC_Type;

/* ----------------------------------------------------------------------------
   -- PKC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PKC_Register_Masks PKC Register Masks
 * @{
 */

/*! @name PKC_STATUS - Status register */
/*! @{ */

#define PKC_PKC_STATUS_ACTIV_MASK                (0x1U)
#define PKC_PKC_STATUS_ACTIV_SHIFT               (0U)
/*! activ - PKC active: ACTIV=1 signals that a calculation is in progress or about to start. At the
 *    end of a calculation ACTIV is automatically reset to logic 0 in case no further GO bit is set.
 *    If the next PKC operation has been started by setting a GO bit during a calculation, ACTIV
 *    remains high. ACTIV is always '1' in case PKC_STATUS.GOANY is set. ACTIV is always '0' in case
 *    PKC_CTRL_RESET is set.
 */
#define PKC_PKC_STATUS_ACTIV(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_ACTIV_SHIFT)) & PKC_PKC_STATUS_ACTIV_MASK)

#define PKC_PKC_STATUS_CARRY_MASK                (0x2U)
#define PKC_PKC_STATUS_CARRY_SHIFT               (1U)
/*! carry - Carry overflow flag: CARRY is set by the PKC at the end of a calculation in case */
#define PKC_PKC_STATUS_CARRY(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_CARRY_SHIFT)) & PKC_PKC_STATUS_CARRY_MASK)

#define PKC_PKC_STATUS_ZERO_MASK                 (0x4U)
#define PKC_PKC_STATUS_ZERO_SHIFT                (2U)
/*! zero - Zero result flag: ZERO is set by the PKC at the end of a calculation in case the result
 *    of the calculation is equal zero. ZERO is updated for each PKC calculation mode, except for
 *    MUL1 (opcode 0x20) and MUL1_GF2 (opcode 0x24).
 */
#define PKC_PKC_STATUS_ZERO(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_ZERO_SHIFT)) & PKC_PKC_STATUS_ZERO_MASK)

#define PKC_PKC_STATUS_GOANY_MASK                (0x8U)
#define PKC_PKC_STATUS_GOANY_SHIFT               (3U)
/*! goany - Combined GO status flag: GOANY is set in case either PKC_CTRL.GOD1, GOD2, GOM1, GOM2 or
 *    GOU is set. The 1-to-0 transition of GOANY indicates that a calculation has been started and
 *    that a new GO bit can be set. If GOANY is cleared also all PKC_STATUS.LOCKED bits are cleared
 *    to indicate that the parameter set can be updated. GOANY is always '0' in case PKC_CTRL.RESET
 *    is set.
 */
#define PKC_PKC_STATUS_GOANY(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_GOANY_SHIFT)) & PKC_PKC_STATUS_GOANY_MASK)

#define PKC_PKC_STATUS_RESERVED4_MASK            (0x10U)
#define PKC_PKC_STATUS_RESERVED4_SHIFT           (4U)
/*! reserved4 - reserved */
#define PKC_PKC_STATUS_RESERVED4(x)              (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_RESERVED4_SHIFT)) & PKC_PKC_STATUS_RESERVED4_MASK)

#define PKC_PKC_STATUS_LOCKED_MASK               (0x60U)
#define PKC_PKC_STATUS_LOCKED_SHIFT              (5U)
/*! locked - Parameter set locked: Indicates if parameter set is locked due to a pending calculation start or can be overwritten. */
#define PKC_PKC_STATUS_LOCKED(x)                 (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_LOCKED_SHIFT)) & PKC_PKC_STATUS_LOCKED_MASK)

#define PKC_PKC_STATUS_RESERVED31_MASK           (0xFFFFFF80U)
#define PKC_PKC_STATUS_RESERVED31_SHIFT          (7U)
/*! reserved31 - reserved */
#define PKC_PKC_STATUS_RESERVED31(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_STATUS_RESERVED31_SHIFT)) & PKC_PKC_STATUS_RESERVED31_MASK)
/*! @} */

/*! @name PKC_CTRL - Control register */
/*! @{ */

#define PKC_PKC_CTRL_RESET_MASK                  (0x1U)
#define PKC_PKC_CTRL_RESET_SHIFT                 (0U)
/*! reset - PKC reset control bit: RESET=1 enforces the PKC's reset state during which a calculation
 *    cannot be started and by which any ongoing calculation process is stopped. RESET can be
 *    set/cleared by the CPU in order to switch between PKC reset and calculation enable. RESET=1 is the
 *    default state after a chip reset.
 */
#define PKC_PKC_CTRL_RESET(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_RESET_SHIFT)) & PKC_PKC_CTRL_RESET_MASK)

#define PKC_PKC_CTRL_STOP_MASK                   (0x2U)
#define PKC_PKC_CTRL_STOP_SHIFT                  (1U)
/*! stop - Freeze PKC calculation: STOP=1 freezes all PKC activity incl. RAM accesses and reduces
 *    the PKC power consumption to its minimum. The difference compared to the reset of the PKC is
 *    that a stopped calculation can be continued when STOP is released (reset to '0') again. The
 *    status flags are not affected by the STOP control bit.
 */
#define PKC_PKC_CTRL_STOP(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_STOP_SHIFT)) & PKC_PKC_CTRL_STOP_MASK)

#define PKC_PKC_CTRL_GOD1_MASK                   (0x4U)
#define PKC_PKC_CTRL_GOD1_SHIFT                  (2U)
/*! god1 - Control bit to start direct operation using parameter set 1: If GOD1 is set PKC will
 *    start a direct / layer0 operation using parameter set 1 (PKC_MODE1, PKC_XYPTR1, PKC_ZRPTR1,
 *    PKC_LEN1).
 */
#define PKC_PKC_CTRL_GOD1(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GOD1_SHIFT)) & PKC_PKC_CTRL_GOD1_MASK)

#define PKC_PKC_CTRL_GOD2_MASK                   (0x8U)
#define PKC_PKC_CTRL_GOD2_SHIFT                  (3U)
/*! god2 - Control bit to start direct operation using parameter set 2: If GOD2 is set PKC will
 *    start a direct / layer0 operation using parameter set 2 (PKC_MODE2, PKC_XYPTR2, PKC_ZRPTR2,
 *    PKC_LEN2).
 */
#define PKC_PKC_CTRL_GOD2(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GOD2_SHIFT)) & PKC_PKC_CTRL_GOD2_MASK)

#define PKC_PKC_CTRL_GOM1_MASK                   (0x10U)
#define PKC_PKC_CTRL_GOM1_SHIFT                  (4U)
/*! gom1 - Control bit to start MC pattern using parameter set 1: If GOM1 is set PKC will start a MC
 *    pattern / layer1 operation using parameter set 1 (PKC_MODE1, PKC_XYPTR1, PKC_ZRPTR1,
 *    PKC_LEN1).
 */
#define PKC_PKC_CTRL_GOM1(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GOM1_SHIFT)) & PKC_PKC_CTRL_GOM1_MASK)

#define PKC_PKC_CTRL_GOM2_MASK                   (0x20U)
#define PKC_PKC_CTRL_GOM2_SHIFT                  (5U)
/*! gom2 - Control bit to start MC pattern using parameter set 2: If GOM2 is set PKC will start a MC
 *    pattern / layer1 operation using parameter set 2 (PKC_MODE2, PKC_XYPTR2, PKC_ZRPTR2,
 *    PKC_LEN2).
 */
#define PKC_PKC_CTRL_GOM2(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GOM2_SHIFT)) & PKC_PKC_CTRL_GOM2_MASK)

#define PKC_PKC_CTRL_GOU_MASK                    (0x40U)
#define PKC_PKC_CTRL_GOU_SHIFT                   (6U)
/*! gou - Control bit to start pipe operation: If GOU is set PKC will start the pipe / layer2
 *    operation (parameter fetch & calculation) described in section 'PKC Universal Pointer Fetch
 *    Operation'.
 */
#define PKC_PKC_CTRL_GOU(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GOU_SHIFT)) & PKC_PKC_CTRL_GOU_MASK)

#define PKC_PKC_CTRL_GF2CONV_MASK                (0x80U)
#define PKC_PKC_CTRL_GF2CONV_SHIFT               (7U)
/*! gf2conv - Convert to GF2 calculation modes: If GF2CONV is set operations are mapped to their GF(2) equivalent operation modes. */
#define PKC_PKC_CTRL_GF2CONV(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_GF2CONV_SHIFT)) & PKC_PKC_CTRL_GF2CONV_MASK)

#define PKC_PKC_CTRL_CLRCACHE_MASK               (0x100U)
#define PKC_PKC_CTRL_CLRCACHE_SHIFT              (8U)
/*! clrcache - Clear universal pointer cache: Invalidates the cache such that all previously fetched
 *    parameters are withdrawn and have to be fetched again via DMA accesses.
 */
#define PKC_PKC_CTRL_CLRCACHE(x)                 (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_CLRCACHE_SHIFT)) & PKC_PKC_CTRL_CLRCACHE_MASK)

#define PKC_PKC_CTRL_CACHE_EN_MASK               (0x200U)
#define PKC_PKC_CTRL_CACHE_EN_SHIFT              (9U)
/*! cache_en - Enable universal pointer cache: If CACHE_EN=1 the cache for the universal pointer
 *    parameters is enabled. In case a parameter value is found in the cache (from a previous fetch) no
 *    DMA access is triggered. As such the amount of DMA accesses for the parameter fetch vary
 *    between 0 and 4. To further optimize the cache utilization not used parameters, e.g. XPTR for a
 *    plain addition (opcode 0x0A), could be defined equal to a used one (e.g. equal YPTR or RPTR) or
 *    a previously fetched parameter.
 */
#define PKC_PKC_CTRL_CACHE_EN(x)                 (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_CACHE_EN_SHIFT)) & PKC_PKC_CTRL_CACHE_EN_MASK)

#define PKC_PKC_CTRL_REDMUL_MASK                 (0xC00U)
#define PKC_PKC_CTRL_REDMUL_SHIFT                (10U)
/*! redmul - Reduced multiplier mode: REDMUL defines the operand width processed by the PKC coprocessor.
 *  0b00..full size mode, 3 least significant bits of pointer and length are ignored, minimum supported length 0x0008
 *  0b01..RFU Error Generated if selected
 *  0b10..64-bit mode, 3 least significant bits of pointer and length are ignored, minimum supported length 0x0008
 *  0b11..RFU Error Generated if selected
 */
#define PKC_PKC_CTRL_REDMUL(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_REDMUL_SHIFT)) & PKC_PKC_CTRL_REDMUL_MASK)

#define PKC_PKC_CTRL_RESERVED31_MASK             (0xFFFFF000U)
#define PKC_PKC_CTRL_RESERVED31_SHIFT            (12U)
/*! reserved31 - reserved */
#define PKC_PKC_CTRL_RESERVED31(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CTRL_RESERVED31_SHIFT)) & PKC_PKC_CTRL_RESERVED31_MASK)
/*! @} */

/*! @name PKC_CFG - Configuration register */
/*! @{ */

#define PKC_PKC_CFG_IDLEOP_MASK                  (0x1U)
#define PKC_PKC_CFG_IDLEOP_SHIFT                 (0U)
/*! idleop - Idle operation feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_IDLEOP(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_IDLEOP_SHIFT)) & PKC_PKC_CFG_IDLEOP_MASK)

#define PKC_PKC_CFG_RFU1_MASK                    (0x2U)
#define PKC_PKC_CFG_RFU1_SHIFT                   (1U)
/*! rfu1 - RFU */
#define PKC_PKC_CFG_RFU1(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_RFU1_SHIFT)) & PKC_PKC_CFG_RFU1_MASK)

#define PKC_PKC_CFG_RFU2_MASK                    (0x4U)
#define PKC_PKC_CFG_RFU2_SHIFT                   (2U)
/*! rfu2 - RFU */
#define PKC_PKC_CFG_RFU2(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_RFU2_SHIFT)) & PKC_PKC_CFG_RFU2_MASK)

#define PKC_PKC_CFG_CLKRND_MASK                  (0x8U)
#define PKC_PKC_CFG_CLKRND_SHIFT                 (3U)
/*! clkrnd - Clock randomization feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_CLKRND(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_CLKRND_SHIFT)) & PKC_PKC_CFG_CLKRND_MASK)

#define PKC_PKC_CFG_REDMULNOISE_MASK             (0x10U)
#define PKC_PKC_CFG_REDMULNOISE_SHIFT            (4U)
/*! redmulnoise - Noise in reduced multiplier mode feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_REDMULNOISE(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_REDMULNOISE_SHIFT)) & PKC_PKC_CFG_REDMULNOISE_MASK)

#define PKC_PKC_CFG_RNDDLY_MASK                  (0xE0U)
#define PKC_PKC_CFG_RNDDLY_SHIFT                 (5U)
/*! rnddly - Random delay feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_RNDDLY(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_RNDDLY_SHIFT)) & PKC_PKC_CFG_RNDDLY_MASK)

#define PKC_PKC_CFG_SBXNOISE_MASK                (0x100U)
#define PKC_PKC_CFG_SBXNOISE_SHIFT               (8U)
/*! sbxnoise - Noise feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_SBXNOISE(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_SBXNOISE_SHIFT)) & PKC_PKC_CFG_SBXNOISE_MASK)

#define PKC_PKC_CFG_ALPNOISE_MASK                (0x200U)
#define PKC_PKC_CFG_ALPNOISE_SHIFT               (9U)
/*! alpnoise - Noise feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_ALPNOISE(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_ALPNOISE_SHIFT)) & PKC_PKC_CFG_ALPNOISE_MASK)

#define PKC_PKC_CFG_FMULNOISE_MASK               (0x400U)
#define PKC_PKC_CFG_FMULNOISE_SHIFT              (10U)
/*! fmulnoise - Noise feature not available in this version (flag is don't care). */
#define PKC_PKC_CFG_FMULNOISE(x)                 (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_FMULNOISE_SHIFT)) & PKC_PKC_CFG_FMULNOISE_MASK)

#define PKC_PKC_CFG_RESERVED31_MASK              (0xFFFFF800U)
#define PKC_PKC_CFG_RESERVED31_SHIFT             (11U)
/*! reserved31 - reserved */
#define PKC_PKC_CFG_RESERVED31(x)                (((uint32_t)(((uint32_t)(x)) << PKC_PKC_CFG_RESERVED31_SHIFT)) & PKC_PKC_CFG_RESERVED31_MASK)
/*! @} */

/*! @name PKC_MODE1 - Mode register, parameter set 1 */
/*! @{ */

#define PKC_PKC_MODE1_MODE_MASK                  (0xFFU)
#define PKC_PKC_MODE1_MODE_SHIFT                 (0U)
/*! mode - Calculation Mode / MC Start address: */
#define PKC_PKC_MODE1_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODE1_MODE_SHIFT)) & PKC_PKC_MODE1_MODE_MASK)

#define PKC_PKC_MODE1_RESERVED31_MASK            (0xFFFFFF00U)
#define PKC_PKC_MODE1_RESERVED31_SHIFT           (8U)
/*! reserved31 - reserved */
#define PKC_PKC_MODE1_RESERVED31(x)              (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODE1_RESERVED31_SHIFT)) & PKC_PKC_MODE1_RESERVED31_MASK)
/*! @} */

/*! @name PKC_XYPTR1 - X+Y pointer register, parameter set 1 */
/*! @{ */

#define PKC_PKC_XYPTR1_XPTR_MASK                 (0xFFFFU)
#define PKC_PKC_XYPTR1_XPTR_SHIFT                (0U)
/*! xptr - Start address of X operand in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_XYPTR1_XPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_XYPTR1_XPTR_SHIFT)) & PKC_PKC_XYPTR1_XPTR_MASK)

#define PKC_PKC_XYPTR1_YPTR_MASK                 (0xFFFF0000U)
#define PKC_PKC_XYPTR1_YPTR_SHIFT                (16U)
/*! yptr - Start address of Y operand in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_XYPTR1_YPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_XYPTR1_YPTR_SHIFT)) & PKC_PKC_XYPTR1_YPTR_MASK)
/*! @} */

/*! @name PKC_ZRPTR1 - Z+R pointer register, parameter set 1 */
/*! @{ */

#define PKC_PKC_ZRPTR1_ZPTR_MASK                 (0xFFFFU)
#define PKC_PKC_ZRPTR1_ZPTR_SHIFT                (0U)
/*! zptr - Start address of Z operand in PKCRAM with byte granularity or constant for calculation modes using CONST: */
#define PKC_PKC_ZRPTR1_ZPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ZRPTR1_ZPTR_SHIFT)) & PKC_PKC_ZRPTR1_ZPTR_MASK)

#define PKC_PKC_ZRPTR1_RPTR_MASK                 (0xFFFF0000U)
#define PKC_PKC_ZRPTR1_RPTR_SHIFT                (16U)
/*! rptr - Start address of R result in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_ZRPTR1_RPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ZRPTR1_RPTR_SHIFT)) & PKC_PKC_ZRPTR1_RPTR_MASK)
/*! @} */

/*! @name PKC_LEN1 - Length register, parameter set 1 */
/*! @{ */

#define PKC_PKC_LEN1_LEN_MASK                    (0xFFFFU)
#define PKC_PKC_LEN1_LEN_SHIFT                   (0U)
/*! len - Operand length: LEN defines the length of the operands and the result in bytes. The length
 *    of Y, Z and R depend furthermore on the selected calculation mode.
 */
#define PKC_PKC_LEN1_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_LEN1_LEN_SHIFT)) & PKC_PKC_LEN1_LEN_MASK)

#define PKC_PKC_LEN1_MCLEN_MASK                  (0xFFFF0000U)
#define PKC_PKC_LEN1_MCLEN_SHIFT                 (16U)
/*! mclen - Loop counter for microcode pattern: MCLEN defines the length of the loop counter that
 *    can be used in layer1 calculation mode, e.g. in MC opcode DecrTBNZ. For the hardcoded MC
 *    patterns Modular Multiplication (MC start address 0x00), Plain Multiplication (0x13), Plain
 *    Multiplication with Addition (0x1D) and Modular Reduction (0x33) MCLEN defines the length of the X
 *    operand in bytes.
 */
#define PKC_PKC_LEN1_MCLEN(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_LEN1_MCLEN_SHIFT)) & PKC_PKC_LEN1_MCLEN_MASK)
/*! @} */

/*! @name PKC_MODE2 - Mode register, parameter set 2 */
/*! @{ */

#define PKC_PKC_MODE2_MODE_MASK                  (0xFFU)
#define PKC_PKC_MODE2_MODE_SHIFT                 (0U)
/*! mode - Calculation Mode / MC Start address: */
#define PKC_PKC_MODE2_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODE2_MODE_SHIFT)) & PKC_PKC_MODE2_MODE_MASK)

#define PKC_PKC_MODE2_RESERVED31_MASK            (0xFFFFFF00U)
#define PKC_PKC_MODE2_RESERVED31_SHIFT           (8U)
/*! reserved31 - reserved */
#define PKC_PKC_MODE2_RESERVED31(x)              (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODE2_RESERVED31_SHIFT)) & PKC_PKC_MODE2_RESERVED31_MASK)
/*! @} */

/*! @name PKC_XYPTR2 - X+Y pointer register, parameter set 2 */
/*! @{ */

#define PKC_PKC_XYPTR2_XPTR_MASK                 (0xFFFFU)
#define PKC_PKC_XYPTR2_XPTR_SHIFT                (0U)
/*! xptr - Start address of X operand in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_XYPTR2_XPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_XYPTR2_XPTR_SHIFT)) & PKC_PKC_XYPTR2_XPTR_MASK)

#define PKC_PKC_XYPTR2_YPTR_MASK                 (0xFFFF0000U)
#define PKC_PKC_XYPTR2_YPTR_SHIFT                (16U)
/*! yptr - Start address of Y operand in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_XYPTR2_YPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_XYPTR2_YPTR_SHIFT)) & PKC_PKC_XYPTR2_YPTR_MASK)
/*! @} */

/*! @name PKC_ZRPTR2 - Z+R pointer register, parameter set 2 */
/*! @{ */

#define PKC_PKC_ZRPTR2_ZPTR_MASK                 (0xFFFFU)
#define PKC_PKC_ZRPTR2_ZPTR_SHIFT                (0U)
/*! zptr - Start address of Z operand in PKCRAM with byte granularity or constant for calculation modes using CONST: */
#define PKC_PKC_ZRPTR2_ZPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ZRPTR2_ZPTR_SHIFT)) & PKC_PKC_ZRPTR2_ZPTR_MASK)

#define PKC_PKC_ZRPTR2_RPTR_MASK                 (0xFFFF0000U)
#define PKC_PKC_ZRPTR2_RPTR_SHIFT                (16U)
/*! rptr - Start address of R result in PKCRAM with byte granularity: Least significant bits are
 *    ignored depending on PKC_CTRL.REDMUL setting. Most significant bits are ignored depending on
 *    available PKCRAM size.
 */
#define PKC_PKC_ZRPTR2_RPTR(x)                   (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ZRPTR2_RPTR_SHIFT)) & PKC_PKC_ZRPTR2_RPTR_MASK)
/*! @} */

/*! @name PKC_LEN2 - Length register, parameter set 2 */
/*! @{ */

#define PKC_PKC_LEN2_LEN_MASK                    (0xFFFFU)
#define PKC_PKC_LEN2_LEN_SHIFT                   (0U)
/*! len - Operand length: LEN defines the length of the operands and the result in bytes. The length
 *    of Y, Z and R depend furthermore on the selected calculation mode.
 */
#define PKC_PKC_LEN2_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_LEN2_LEN_SHIFT)) & PKC_PKC_LEN2_LEN_MASK)

#define PKC_PKC_LEN2_MCLEN_MASK                  (0xFFFF0000U)
#define PKC_PKC_LEN2_MCLEN_SHIFT                 (16U)
/*! mclen - Loop counter for microcode pattern: MCLEN defines the length of the loop counter that
 *    can be used in layer1 calculation mode, e.g. in MC opcode DecrTBNZ. For the hardcoded MC
 *    patterns Modular Multiplication (MC start address 0x00)
 */
#define PKC_PKC_LEN2_MCLEN(x)                    (((uint32_t)(((uint32_t)(x)) << PKC_PKC_LEN2_MCLEN_SHIFT)) & PKC_PKC_LEN2_MCLEN_MASK)
/*! @} */

/*! @name PKC_UPTR - Universal pointer FUP program */
/*! @{ */

#define PKC_PKC_UPTR_PTR_MASK                    (0xFFFFFFFFU)
#define PKC_PKC_UPTR_PTR_SHIFT                   (0U)
/*! ptr - Pointer to start address of PKC FUP program: PKC_UPTR needs to be defined before starting
 *    a universal pointer PKC calculation (layer2) via PKC_CTRL.GOU. The pointer address needs to be
 *    valid and the memory space the pointer addresses needs to be enabled for PKC access by the
 *    system. Otherwise a security alarm is triggered (PKC_ACCESS_ERR.AHB is set).
 */
#define PKC_PKC_UPTR_PTR(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_UPTR_PTR_SHIFT)) & PKC_PKC_UPTR_PTR_MASK)
/*! @} */

/*! @name PKC_UPTRT - Universal pointer FUP table */
/*! @{ */

#define PKC_PKC_UPTRT_PTR_MASK                   (0xFFFFFFFFU)
#define PKC_PKC_UPTRT_PTR_SHIFT                  (0U)
/*! ptr - Pointer to start address of PKC FUP table: PKC_UPTRT needs to be defined before starting a
 *    universal pointer PKC calculation (layer2) via PKC_CTRL.GOU. The pointer address needs to be
 *    valid and the memory space the pointer addresses needs to be enabled for PKC access by the
 *    system. Otherwise a security alarm is triggered (PKC_ACCESS_ERR.AHB is set).
 */
#define PKC_PKC_UPTRT_PTR(x)                     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_UPTRT_PTR_SHIFT)) & PKC_PKC_UPTRT_PTR_MASK)
/*! @} */

/*! @name PKC_ULEN - Universal pointer length */
/*! @{ */

#define PKC_PKC_ULEN_LEN_MASK                    (0xFFU)
#define PKC_PKC_ULEN_LEN_SHIFT                   (0U)
/*! len - Length of universal pointer calculation: PKC_ULEN defines how many FUP program entries
 *    shall be processed for one layer2 calculation started via PKC_CTRL.GOU. The FUP program entries
 *    include layer0 calculations, layer1 calculations and CRC entries for FUP program integrity
 *    protection.
 */
#define PKC_PKC_ULEN_LEN(x)                      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ULEN_LEN_SHIFT)) & PKC_PKC_ULEN_LEN_MASK)

#define PKC_PKC_ULEN_RESERVED31_MASK             (0xFFFFFF00U)
#define PKC_PKC_ULEN_RESERVED31_SHIFT            (8U)
/*! reserved31 - reserved */
#define PKC_PKC_ULEN_RESERVED31(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ULEN_RESERVED31_SHIFT)) & PKC_PKC_ULEN_RESERVED31_MASK)
/*! @} */

/*! @name PKC_MCDATA - MC pattern data interface */
/*! @{ */

#define PKC_PKC_MCDATA_MCDATA_MASK               (0xFFFFFFFFU)
#define PKC_PKC_MCDATA_MCDATA_SHIFT              (0U)
/*! mcdata - Microcode read/write data: This IP version does not support flexible MC patterns (only
 *    hard coded ones). Any read or write access to PKC_MCDATA triggers a security alarm
 *    (PKC_ACCESS_ERR.CTRL is set).
 */
#define PKC_PKC_MCDATA_MCDATA(x)                 (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MCDATA_MCDATA_SHIFT)) & PKC_PKC_MCDATA_MCDATA_MASK)
/*! @} */

/*! @name PKC_VERSION - PKC version register */
/*! @{ */

#define PKC_PKC_VERSION_MULSIZE_MASK             (0x3U)
#define PKC_PKC_VERSION_MULSIZE_SHIFT            (0U)
/*! mulsize - native multiplier size and operand granularity
 *  0b01..32-bit multiplier
 *  0b10..64-bit multiplier
 *  0b11..128-bit multiplier
 */
#define PKC_PKC_VERSION_MULSIZE(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_MULSIZE_SHIFT)) & PKC_PKC_VERSION_MULSIZE_MASK)

#define PKC_PKC_VERSION_MCAVAIL_MASK             (0x4U)
#define PKC_PKC_VERSION_MCAVAIL_SHIFT            (2U)
/*! mcavail - MC feature (layer1 calculation) is available */
#define PKC_PKC_VERSION_MCAVAIL(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_MCAVAIL_SHIFT)) & PKC_PKC_VERSION_MCAVAIL_MASK)

#define PKC_PKC_VERSION_UPAVAIL_MASK             (0x8U)
#define PKC_PKC_VERSION_UPAVAIL_SHIFT            (3U)
/*! upavail - UP feature (layer2 calculation) is available */
#define PKC_PKC_VERSION_UPAVAIL(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_UPAVAIL_SHIFT)) & PKC_PKC_VERSION_UPAVAIL_MASK)

#define PKC_PKC_VERSION_UPCACHEAVAIL_MASK        (0x10U)
#define PKC_PKC_VERSION_UPCACHEAVAIL_SHIFT       (4U)
/*! upcacheavail - UP cache is available */
#define PKC_PKC_VERSION_UPCACHEAVAIL(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_UPCACHEAVAIL_SHIFT)) & PKC_PKC_VERSION_UPCACHEAVAIL_MASK)

#define PKC_PKC_VERSION_GF2AVAIL_MASK            (0x20U)
#define PKC_PKC_VERSION_GF2AVAIL_SHIFT           (5U)
/*! gf2avail - GF2 calculation modes are available */
#define PKC_PKC_VERSION_GF2AVAIL(x)              (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_GF2AVAIL_SHIFT)) & PKC_PKC_VERSION_GF2AVAIL_MASK)

#define PKC_PKC_VERSION_PARAMNUM_MASK            (0xC0U)
#define PKC_PKC_VERSION_PARAMNUM_SHIFT           (6U)
/*! paramnum - Number of parameter sets for real calculation */
#define PKC_PKC_VERSION_PARAMNUM(x)              (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_PARAMNUM_SHIFT)) & PKC_PKC_VERSION_PARAMNUM_MASK)

#define PKC_PKC_VERSION_SBX0AVAIL_MASK           (0x100U)
#define PKC_PKC_VERSION_SBX0AVAIL_SHIFT          (8U)
/*! sbx0avail - SBX0 operation is available */
#define PKC_PKC_VERSION_SBX0AVAIL(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_SBX0AVAIL_SHIFT)) & PKC_PKC_VERSION_SBX0AVAIL_MASK)

#define PKC_PKC_VERSION_SBX1AVAIL_MASK           (0x200U)
#define PKC_PKC_VERSION_SBX1AVAIL_SHIFT          (9U)
/*! sbx1avail - SBX1 operation is available */
#define PKC_PKC_VERSION_SBX1AVAIL(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_SBX1AVAIL_SHIFT)) & PKC_PKC_VERSION_SBX1AVAIL_MASK)

#define PKC_PKC_VERSION_SBX2AVAIL_MASK           (0x400U)
#define PKC_PKC_VERSION_SBX2AVAIL_SHIFT          (10U)
/*! sbx2avail - SBX2 operation is available */
#define PKC_PKC_VERSION_SBX2AVAIL(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_SBX2AVAIL_SHIFT)) & PKC_PKC_VERSION_SBX2AVAIL_MASK)

#define PKC_PKC_VERSION_SBX3AVAIL_MASK           (0x800U)
#define PKC_PKC_VERSION_SBX3AVAIL_SHIFT          (11U)
/*! sbx3avail - SBX3 operation is available */
#define PKC_PKC_VERSION_SBX3AVAIL(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_SBX3AVAIL_SHIFT)) & PKC_PKC_VERSION_SBX3AVAIL_MASK)

#define PKC_PKC_VERSION_MCRECONF_SIZE_MASK       (0xFF000U)
#define PKC_PKC_VERSION_MCRECONF_SIZE_SHIFT      (12U)
/*! mcreconf_size - Size of reconfigurable MC table in bytes */
#define PKC_PKC_VERSION_MCRECONF_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_MCRECONF_SIZE_SHIFT)) & PKC_PKC_VERSION_MCRECONF_SIZE_MASK)

#define PKC_PKC_VERSION_RESERVED31_MASK          (0xFFF00000U)
#define PKC_PKC_VERSION_RESERVED31_SHIFT         (20U)
/*! reserved31 - reserved */
#define PKC_PKC_VERSION_RESERVED31(x)            (((uint32_t)(((uint32_t)(x)) << PKC_PKC_VERSION_RESERVED31_SHIFT)) & PKC_PKC_VERSION_RESERVED31_MASK)
/*! @} */

/*! @name PKC_SOFT_RST - Software reset */
/*! @{ */

#define PKC_PKC_SOFT_RST_SOFT_RST_MASK           (0x1U)
#define PKC_PKC_SOFT_RST_SOFT_RST_SHIFT          (0U)
/*! soft_rst - Write 1 to reset module (0 has no effect). All running and pending PKC calculation
 *    are stopped. All PKC SFRs are reset except PKC_ACCESS_ERR.
 */
#define PKC_PKC_SOFT_RST_SOFT_RST(x)             (((uint32_t)(((uint32_t)(x)) << PKC_PKC_SOFT_RST_SOFT_RST_SHIFT)) & PKC_PKC_SOFT_RST_SOFT_RST_MASK)

#define PKC_PKC_SOFT_RST_RESERVED31_MASK         (0xFFFFFFFEU)
#define PKC_PKC_SOFT_RST_RESERVED31_SHIFT        (1U)
/*! reserved31 - reserved */
#define PKC_PKC_SOFT_RST_RESERVED31(x)           (((uint32_t)(((uint32_t)(x)) << PKC_PKC_SOFT_RST_RESERVED31_SHIFT)) & PKC_PKC_SOFT_RST_RESERVED31_MASK)
/*! @} */

/*! @name PKC_ACCESS_ERR - Access Error */
/*! @{ */

#define PKC_PKC_ACCESS_ERR_APB_NOTAV_MASK        (0x1U)
#define PKC_PKC_ACCESS_ERR_APB_NOTAV_SHIFT       (0U)
/*! apb_notav - APB Error: address not available */
#define PKC_PKC_ACCESS_ERR_APB_NOTAV(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_APB_NOTAV_SHIFT)) & PKC_PKC_ACCESS_ERR_APB_NOTAV_MASK)

#define PKC_PKC_ACCESS_ERR_APB_WRGMD_MASK        (0x2U)
#define PKC_PKC_ACCESS_ERR_APB_WRGMD_SHIFT       (1U)
/*! apb_wrgmd - APB Error: Wrong access mode */
#define PKC_PKC_ACCESS_ERR_APB_WRGMD(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_APB_WRGMD_SHIFT)) & PKC_PKC_ACCESS_ERR_APB_WRGMD_MASK)

#define PKC_PKC_ACCESS_ERR_RESERVED3_MASK        (0xCU)
#define PKC_PKC_ACCESS_ERR_RESERVED3_SHIFT       (2U)
/*! reserved3 - reserved for future erors on APB I/F */
#define PKC_PKC_ACCESS_ERR_RESERVED3(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_RESERVED3_SHIFT)) & PKC_PKC_ACCESS_ERR_RESERVED3_MASK)

#define PKC_PKC_ACCESS_ERR_APB_MASTER_MASK       (0xF0U)
#define PKC_PKC_ACCESS_ERR_APB_MASTER_SHIFT      (4U)
/*! apb_master - APB Master that triggered first APB error (APB_WRGMD or APB_NOTAV) */
#define PKC_PKC_ACCESS_ERR_APB_MASTER(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_APB_MASTER_SHIFT)) & PKC_PKC_ACCESS_ERR_APB_MASTER_MASK)

#define PKC_PKC_ACCESS_ERR_RESERVED9_MASK        (0x300U)
#define PKC_PKC_ACCESS_ERR_RESERVED9_SHIFT       (8U)
/*! reserved9 - reserved for future erors on AHB I/F Layer2 Only */
#define PKC_PKC_ACCESS_ERR_RESERVED9(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_RESERVED9_SHIFT)) & PKC_PKC_ACCESS_ERR_RESERVED9_MASK)

#define PKC_PKC_ACCESS_ERR_AHB_MASK              (0x400U)
#define PKC_PKC_ACCESS_ERR_AHB_SHIFT             (10U)
/*! ahb - AHB Error: invalid AHB access Layer2 Only */
#define PKC_PKC_ACCESS_ERR_AHB(x)                (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_AHB_SHIFT)) & PKC_PKC_ACCESS_ERR_AHB_MASK)

#define PKC_PKC_ACCESS_ERR_RESERVED15_MASK       (0xF800U)
#define PKC_PKC_ACCESS_ERR_RESERVED15_SHIFT      (11U)
/*! reserved15 - reserved for future erors on AHB I/F Layer2 Only */
#define PKC_PKC_ACCESS_ERR_RESERVED15(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_RESERVED15_SHIFT)) & PKC_PKC_ACCESS_ERR_RESERVED15_MASK)

#define PKC_PKC_ACCESS_ERR_PKCC_MASK             (0x10000U)
#define PKC_PKC_ACCESS_ERR_PKCC_SHIFT            (16U)
/*! pkcc - Error in PKC coprocessor kernel */
#define PKC_PKC_ACCESS_ERR_PKCC(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_PKCC_SHIFT)) & PKC_PKC_ACCESS_ERR_PKCC_MASK)

#define PKC_PKC_ACCESS_ERR_FDET_MASK             (0x20000U)
#define PKC_PKC_ACCESS_ERR_FDET_SHIFT            (17U)
/*! fdet - Error due to error detection circuitry */
#define PKC_PKC_ACCESS_ERR_FDET(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_FDET_SHIFT)) & PKC_PKC_ACCESS_ERR_FDET_MASK)

#define PKC_PKC_ACCESS_ERR_CTRL_MASK             (0x40000U)
#define PKC_PKC_ACCESS_ERR_CTRL_SHIFT            (18U)
/*! ctrl - Error in PKC software control */
#define PKC_PKC_ACCESS_ERR_CTRL(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_CTRL_SHIFT)) & PKC_PKC_ACCESS_ERR_CTRL_MASK)

#define PKC_PKC_ACCESS_ERR_UCRC_MASK             (0x80000U)
#define PKC_PKC_ACCESS_ERR_UCRC_SHIFT            (19U)
/*! ucrc - Error in layer2 CRC check */
#define PKC_PKC_ACCESS_ERR_UCRC(x)               (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_UCRC_SHIFT)) & PKC_PKC_ACCESS_ERR_UCRC_MASK)

#define PKC_PKC_ACCESS_ERR_RESERVED20_MASK       (0x100000U)
#define PKC_PKC_ACCESS_ERR_RESERVED20_SHIFT      (20U)
/*! reserved20 - reserved */
#define PKC_PKC_ACCESS_ERR_RESERVED20(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_RESERVED20_SHIFT)) & PKC_PKC_ACCESS_ERR_RESERVED20_MASK)

#define PKC_PKC_ACCESS_ERR_RESERVED31_MASK       (0xFFE00000U)
#define PKC_PKC_ACCESS_ERR_RESERVED31_SHIFT      (21U)
/*! reserved31 - reserved for more block errors */
#define PKC_PKC_ACCESS_ERR_RESERVED31(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_RESERVED31_SHIFT)) & PKC_PKC_ACCESS_ERR_RESERVED31_MASK)
/*! @} */

/*! @name PKC_ACCESS_ERR_CLR - Clear Access Error */
/*! @{ */

#define PKC_PKC_ACCESS_ERR_CLR_ERR_CLR_MASK      (0x1U)
#define PKC_PKC_ACCESS_ERR_CLR_ERR_CLR_SHIFT     (0U)
/*! err_clr - Write 1 to reset PKC_ACCESS_ERR SFR. */
#define PKC_PKC_ACCESS_ERR_CLR_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_CLR_ERR_CLR_SHIFT)) & PKC_PKC_ACCESS_ERR_CLR_ERR_CLR_MASK)

#define PKC_PKC_ACCESS_ERR_CLR_RESERVED31_MASK   (0xFFFFFFFEU)
#define PKC_PKC_ACCESS_ERR_CLR_RESERVED31_SHIFT  (1U)
/*! reserved31 - reserved */
#define PKC_PKC_ACCESS_ERR_CLR_RESERVED31(x)     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_ACCESS_ERR_CLR_RESERVED31_SHIFT)) & PKC_PKC_ACCESS_ERR_CLR_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_CLR_ENABLE - Interrupt enable clear */
/*! @{ */

#define PKC_PKC_INT_CLR_ENABLE_EN_PDONE_MASK     (0x1U)
#define PKC_PKC_INT_CLR_ENABLE_EN_PDONE_SHIFT    (0U)
/*! en_pdone - Write to clear PDONE interrupt enable flag (PKC_INT_ENABLE.EN_PDONE=0). */
#define PKC_PKC_INT_CLR_ENABLE_EN_PDONE(x)       (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_ENABLE_EN_PDONE_SHIFT)) & PKC_PKC_INT_CLR_ENABLE_EN_PDONE_MASK)

#define PKC_PKC_INT_CLR_ENABLE_RESERVED1_MASK    (0x2U)
#define PKC_PKC_INT_CLR_ENABLE_RESERVED1_SHIFT   (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_CLR_ENABLE_RESERVED1(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_ENABLE_RESERVED1_SHIFT)) & PKC_PKC_INT_CLR_ENABLE_RESERVED1_MASK)

#define PKC_PKC_INT_CLR_ENABLE_RESERVED31_MASK   (0xFFFFFFFCU)
#define PKC_PKC_INT_CLR_ENABLE_RESERVED31_SHIFT  (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_CLR_ENABLE_RESERVED31(x)     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_ENABLE_RESERVED31_SHIFT)) & PKC_PKC_INT_CLR_ENABLE_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_SET_ENABLE - Interrupt enable set */
/*! @{ */

#define PKC_PKC_INT_SET_ENABLE_EN_PDONE_MASK     (0x1U)
#define PKC_PKC_INT_SET_ENABLE_EN_PDONE_SHIFT    (0U)
/*! en_pdone - Write to set PDONE interrupt enable flag (PKC_INT_ENABLE.EN_PDONE=1). */
#define PKC_PKC_INT_SET_ENABLE_EN_PDONE(x)       (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_ENABLE_EN_PDONE_SHIFT)) & PKC_PKC_INT_SET_ENABLE_EN_PDONE_MASK)

#define PKC_PKC_INT_SET_ENABLE_RESERVED1_MASK    (0x2U)
#define PKC_PKC_INT_SET_ENABLE_RESERVED1_SHIFT   (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_SET_ENABLE_RESERVED1(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_ENABLE_RESERVED1_SHIFT)) & PKC_PKC_INT_SET_ENABLE_RESERVED1_MASK)

#define PKC_PKC_INT_SET_ENABLE_RESERVED31_MASK   (0xFFFFFFFCU)
#define PKC_PKC_INT_SET_ENABLE_RESERVED31_SHIFT  (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_SET_ENABLE_RESERVED31(x)     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_ENABLE_RESERVED31_SHIFT)) & PKC_PKC_INT_SET_ENABLE_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_STATUS - Interrupt status */
/*! @{ */

#define PKC_PKC_INT_STATUS_INT_PDONE_MASK        (0x1U)
#define PKC_PKC_INT_STATUS_INT_PDONE_SHIFT       (0U)
/*! int_pdone - End-of-computation status flag: INT_PDONE is set after EACH single PKC layer0 or
 *    layer1 calculation. In case of a universal pointer calculation (layer2) INT_PDONE is set at the
 *    end of the pipe calculation when PKC_ULEN has been decremented to zero and the final PKC
 *    calculation has completed.
 */
#define PKC_PKC_INT_STATUS_INT_PDONE(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_STATUS_INT_PDONE_SHIFT)) & PKC_PKC_INT_STATUS_INT_PDONE_MASK)

#define PKC_PKC_INT_STATUS_RESERVED1_MASK        (0x2U)
#define PKC_PKC_INT_STATUS_RESERVED1_SHIFT       (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_STATUS_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_STATUS_RESERVED1_SHIFT)) & PKC_PKC_INT_STATUS_RESERVED1_MASK)

#define PKC_PKC_INT_STATUS_RESERVED31_MASK       (0xFFFFFFFCU)
#define PKC_PKC_INT_STATUS_RESERVED31_SHIFT      (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_STATUS_RESERVED31(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_STATUS_RESERVED31_SHIFT)) & PKC_PKC_INT_STATUS_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_ENABLE - Interrupt enable */
/*! @{ */

#define PKC_PKC_INT_ENABLE_EN_PDONE_MASK         (0x1U)
#define PKC_PKC_INT_ENABLE_EN_PDONE_SHIFT        (0U)
/*! en_pdone - PDONE interrupt enable flag: If EN_PDONE=1 an interrupt is triggered every time
 *    PKC_INT_STATUS.INT_PDONE is set. Otherwise the interrupt generation is suppressed.
 */
#define PKC_PKC_INT_ENABLE_EN_PDONE(x)           (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_ENABLE_EN_PDONE_SHIFT)) & PKC_PKC_INT_ENABLE_EN_PDONE_MASK)

#define PKC_PKC_INT_ENABLE_RESERVED1_MASK        (0x2U)
#define PKC_PKC_INT_ENABLE_RESERVED1_SHIFT       (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_ENABLE_RESERVED1(x)          (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_ENABLE_RESERVED1_SHIFT)) & PKC_PKC_INT_ENABLE_RESERVED1_MASK)

#define PKC_PKC_INT_ENABLE_RESERVED31_MASK       (0xFFFFFFFCU)
#define PKC_PKC_INT_ENABLE_RESERVED31_SHIFT      (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_ENABLE_RESERVED31(x)         (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_ENABLE_RESERVED31_SHIFT)) & PKC_PKC_INT_ENABLE_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_CLR_STATUS - Interrupt status clear */
/*! @{ */

#define PKC_PKC_INT_CLR_STATUS_INT_PDONE_MASK    (0x1U)
#define PKC_PKC_INT_CLR_STATUS_INT_PDONE_SHIFT   (0U)
/*! int_pdone - Write to clear End-of-computation status flag (PKC_INT_STATUS.INT_PDONE=0). */
#define PKC_PKC_INT_CLR_STATUS_INT_PDONE(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_STATUS_INT_PDONE_SHIFT)) & PKC_PKC_INT_CLR_STATUS_INT_PDONE_MASK)

#define PKC_PKC_INT_CLR_STATUS_RESERVED1_MASK    (0x2U)
#define PKC_PKC_INT_CLR_STATUS_RESERVED1_SHIFT   (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_CLR_STATUS_RESERVED1(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_STATUS_RESERVED1_SHIFT)) & PKC_PKC_INT_CLR_STATUS_RESERVED1_MASK)

#define PKC_PKC_INT_CLR_STATUS_RESERVED31_MASK   (0xFFFFFFFCU)
#define PKC_PKC_INT_CLR_STATUS_RESERVED31_SHIFT  (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_CLR_STATUS_RESERVED31(x)     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_CLR_STATUS_RESERVED31_SHIFT)) & PKC_PKC_INT_CLR_STATUS_RESERVED31_MASK)
/*! @} */

/*! @name PKC_INT_SET_STATUS - Interrupt status set */
/*! @{ */

#define PKC_PKC_INT_SET_STATUS_INT_PDONE_MASK    (0x1U)
#define PKC_PKC_INT_SET_STATUS_INT_PDONE_SHIFT   (0U)
/*! int_pdone - Write to set End-of-computation status flag (PKC_INT_STATUS.INT_PDONE=1) to trigger
 *    a PKC interrupt via software, e.g. for debug purposes.
 */
#define PKC_PKC_INT_SET_STATUS_INT_PDONE(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_STATUS_INT_PDONE_SHIFT)) & PKC_PKC_INT_SET_STATUS_INT_PDONE_MASK)

#define PKC_PKC_INT_SET_STATUS_RESERVED1_MASK    (0x2U)
#define PKC_PKC_INT_SET_STATUS_RESERVED1_SHIFT   (1U)
/*! reserved1 - reserved */
#define PKC_PKC_INT_SET_STATUS_RESERVED1(x)      (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_STATUS_RESERVED1_SHIFT)) & PKC_PKC_INT_SET_STATUS_RESERVED1_MASK)

#define PKC_PKC_INT_SET_STATUS_RESERVED31_MASK   (0xFFFFFFFCU)
#define PKC_PKC_INT_SET_STATUS_RESERVED31_SHIFT  (2U)
/*! reserved31 - reserved */
#define PKC_PKC_INT_SET_STATUS_RESERVED31(x)     (((uint32_t)(((uint32_t)(x)) << PKC_PKC_INT_SET_STATUS_RESERVED31_SHIFT)) & PKC_PKC_INT_SET_STATUS_RESERVED31_MASK)
/*! @} */

/*! @name PKC_MODULE_ID - Module ID */
/*! @{ */

#define PKC_PKC_MODULE_ID_SIZE_MASK              (0xFFU)
#define PKC_PKC_MODULE_ID_SIZE_SHIFT             (0U)
/*! size - Address space of the IP */
#define PKC_PKC_MODULE_ID_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODULE_ID_SIZE_SHIFT)) & PKC_PKC_MODULE_ID_SIZE_MASK)

#define PKC_PKC_MODULE_ID_MINOR_REV_MASK         (0xF00U)
#define PKC_PKC_MODULE_ID_MINOR_REV_SHIFT        (8U)
/*! minor_rev - Minor revision */
#define PKC_PKC_MODULE_ID_MINOR_REV(x)           (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODULE_ID_MINOR_REV_SHIFT)) & PKC_PKC_MODULE_ID_MINOR_REV_MASK)

#define PKC_PKC_MODULE_ID_MAJOR_REV_MASK         (0xF000U)
#define PKC_PKC_MODULE_ID_MAJOR_REV_SHIFT        (12U)
/*! major_rev - Major revision */
#define PKC_PKC_MODULE_ID_MAJOR_REV(x)           (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODULE_ID_MAJOR_REV_SHIFT)) & PKC_PKC_MODULE_ID_MAJOR_REV_MASK)

#define PKC_PKC_MODULE_ID_ID_MASK                (0xFFFF0000U)
#define PKC_PKC_MODULE_ID_ID_SHIFT               (16U)
/*! id - Module ID */
#define PKC_PKC_MODULE_ID_ID(x)                  (((uint32_t)(((uint32_t)(x)) << PKC_PKC_MODULE_ID_ID_SHIFT)) & PKC_PKC_MODULE_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PKC_Register_Masks */


/*!
 * @}
 */ /* end of group PKC_Peripheral_Access_Layer */


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


#endif  /* PERI_PKC_H_ */

