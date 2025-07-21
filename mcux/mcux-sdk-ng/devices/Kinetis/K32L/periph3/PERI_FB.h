/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FB
 *
 * CMSIS Peripheral Access Layer for FB
 */

#if !defined(PERI_FB_H_)
#define PERI_FB_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- FB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FB_Peripheral_Access_Layer FB Peripheral Access Layer
 * @{
 */

/** FB - Size of Registers Arrays */
#define FB_CS_COUNT                               6u

/** FB - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0xC */
    __IO uint32_t CSAR;                              /**< Chip Select Address Register, array offset: 0x0, array step: 0xC */
    __IO uint32_t CSMR;                              /**< Chip Select Mask Register, array offset: 0x4, array step: 0xC */
    __IO uint32_t CSCR;                              /**< Chip Select Control Register, array offset: 0x8, array step: 0xC */
  } CS[FB_CS_COUNT];
       uint8_t RESERVED_0[24];
  __IO uint32_t CSPMCR;                            /**< Chip Select Port Multiplexing Control Register, offset: 0x60 */
} FB_Type;

/* ----------------------------------------------------------------------------
   -- FB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FB_Register_Masks FB Register Masks
 * @{
 */

/*! @name CSAR - Chip Select Address Register */
/*! @{ */

#define FB_CSAR_BA_MASK                          (0xFFFF0000U)
#define FB_CSAR_BA_SHIFT                         (16U)
/*! BA - Base Address */
#define FB_CSAR_BA(x)                            (((uint32_t)(((uint32_t)(x)) << FB_CSAR_BA_SHIFT)) & FB_CSAR_BA_MASK)
/*! @} */

/* The count of FB_CSAR */
#define FB_CSAR_COUNT                            (6U)

/*! @name CSMR - Chip Select Mask Register */
/*! @{ */

#define FB_CSMR_V_MASK                           (0x1U)
#define FB_CSMR_V_SHIFT                          (0U)
/*! V - Valid
 *  0b0..Chip-select is invalid.
 *  0b1..Chip-select is valid.
 */
#define FB_CSMR_V(x)                             (((uint32_t)(((uint32_t)(x)) << FB_CSMR_V_SHIFT)) & FB_CSMR_V_MASK)

#define FB_CSMR_WP_MASK                          (0x100U)
#define FB_CSMR_WP_SHIFT                         (8U)
/*! WP - Write Protect
 *  0b0..Write accesses are allowed.
 *  0b1..Write accesses are not allowed. Attempting to write to the range of addresses for which the WP bit is set
 *       results in a bus error termination of the internal cycle and no external cycle.
 */
#define FB_CSMR_WP(x)                            (((uint32_t)(((uint32_t)(x)) << FB_CSMR_WP_SHIFT)) & FB_CSMR_WP_MASK)

#define FB_CSMR_BAM_MASK                         (0xFFFF0000U)
#define FB_CSMR_BAM_SHIFT                        (16U)
/*! BAM - Base Address Mask
 *  0b0000000000000000..The corresponding address bit in CSAR is used in the chip-select decode.
 *  0b0000000000000001..The corresponding address bit in CSAR is a don't care in the chip-select decode.
 */
#define FB_CSMR_BAM(x)                           (((uint32_t)(((uint32_t)(x)) << FB_CSMR_BAM_SHIFT)) & FB_CSMR_BAM_MASK)
/*! @} */

/* The count of FB_CSMR */
#define FB_CSMR_COUNT                            (6U)

/*! @name CSCR - Chip Select Control Register */
/*! @{ */

#define FB_CSCR_BSTW_MASK                        (0x8U)
#define FB_CSCR_BSTW_SHIFT                       (3U)
/*! BSTW - Burst-Write Enable
 *  0b0..Disabled. Data exceeding the specified port size is broken into individual, port-sized, non-burst writes.
 *       For example, a 32-bit write to an 8-bit port takes four byte writes.
 *  0b1..Enabled. Enables burst write of data larger than the specified port size, including 32-bit writes to 8-
 *       and 16-bit ports, 16-bit writes to 8-bit ports, and line writes to 8-, 16-, and 32-bit ports.
 */
#define FB_CSCR_BSTW(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_BSTW_SHIFT)) & FB_CSCR_BSTW_MASK)

#define FB_CSCR_BSTR_MASK                        (0x10U)
#define FB_CSCR_BSTR_SHIFT                       (4U)
/*! BSTR - Burst-Read Enable
 *  0b0..Disabled. Data exceeding the specified port size is broken into individual, port-sized, non-burst reads.
 *       For example, a 32-bit read from an 8-bit port is broken into four 8-bit reads.
 *  0b1..Enabled. Enables data burst reads larger than the specified port size, including 32-bit reads from 8- and
 *       16-bit ports, 16-bit reads from 8-bit ports, and line reads from 8-, 16-, and 32-bit ports.
 */
#define FB_CSCR_BSTR(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_BSTR_SHIFT)) & FB_CSCR_BSTR_MASK)

#define FB_CSCR_BEM_MASK                         (0x20U)
#define FB_CSCR_BEM_SHIFT                        (5U)
/*! BEM - Byte-Enable Mode
 *  0b0..FB_BE_B is asserted for data write only.
 *  0b1..FB_BE_B is asserted for data read and write accesses.
 */
#define FB_CSCR_BEM(x)                           (((uint32_t)(((uint32_t)(x)) << FB_CSCR_BEM_SHIFT)) & FB_CSCR_BEM_MASK)

#define FB_CSCR_PS_MASK                          (0xC0U)
#define FB_CSCR_PS_SHIFT                         (6U)
/*! PS - Port Size
 *  0b00..32-bit port size. Valid data is sampled and driven on FB_D[31:0].
 *  0b01..8-bit port size. Valid data is sampled and driven on FB_D[31:24] when BLS is 0b, or FB_D[7:0] when BLS is 1b.
 *  0b1x..16-bit port size. Valid data is sampled and driven on FB_D[31:16] when BLS is 0b, or FB_D[15:0] when BLS is 1b.
 */
#define FB_CSCR_PS(x)                            (((uint32_t)(((uint32_t)(x)) << FB_CSCR_PS_SHIFT)) & FB_CSCR_PS_MASK)

#define FB_CSCR_AA_MASK                          (0x100U)
#define FB_CSCR_AA_SHIFT                         (8U)
/*! AA - Auto-Acknowledge Enable
 *  0b0..Disabled. No internal transfer acknowledge is asserted and the cycle is terminated externally.
 *  0b1..Enabled. Internal transfer acknowledge is asserted as specified by WS.
 */
#define FB_CSCR_AA(x)                            (((uint32_t)(((uint32_t)(x)) << FB_CSCR_AA_SHIFT)) & FB_CSCR_AA_MASK)

#define FB_CSCR_BLS_MASK                         (0x200U)
#define FB_CSCR_BLS_SHIFT                        (9U)
/*! BLS - Byte-Lane Shift
 *  0b0..Not shifted. Data is left-aligned on FB_AD.
 *  0b1..Shifted. Data is right-aligned on FB_AD.
 */
#define FB_CSCR_BLS(x)                           (((uint32_t)(((uint32_t)(x)) << FB_CSCR_BLS_SHIFT)) & FB_CSCR_BLS_MASK)

#define FB_CSCR_WS_MASK                          (0xFC00U)
#define FB_CSCR_WS_SHIFT                         (10U)
/*! WS - Wait States */
#define FB_CSCR_WS(x)                            (((uint32_t)(((uint32_t)(x)) << FB_CSCR_WS_SHIFT)) & FB_CSCR_WS_MASK)

#define FB_CSCR_WRAH_MASK                        (0x30000U)
#define FB_CSCR_WRAH_SHIFT                       (16U)
/*! WRAH - Write Address Hold or Deselect
 *  0b00..1 cycle (default for all but FB_CS0_B)
 *  0b01..2 cycles
 *  0b10..3 cycles
 *  0b11..4 cycles (default for FB_CS0_B)
 */
#define FB_CSCR_WRAH(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_WRAH_SHIFT)) & FB_CSCR_WRAH_MASK)

#define FB_CSCR_RDAH_MASK                        (0xC0000U)
#define FB_CSCR_RDAH_SHIFT                       (18U)
/*! RDAH - Read Address Hold or Deselect
 *  0b00..When AA is 1b, 1 cycle. When AA is 0b, 0 cycles.
 *  0b01..When AA is 1b, 2 cycles. When AA is 0b, 1 cycle.
 *  0b10..When AA is 1b, 3 cycles. When AA is 0b, 2 cycles.
 *  0b11..When AA is 1b, 4 cycles. When AA is 0b, 3 cycles.
 */
#define FB_CSCR_RDAH(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_RDAH_SHIFT)) & FB_CSCR_RDAH_MASK)

#define FB_CSCR_ASET_MASK                        (0x300000U)
#define FB_CSCR_ASET_SHIFT                       (20U)
/*! ASET - Address Setup
 *  0b00..Assert FB_CSn_B on the first rising clock edge after the address is asserted (default for all but FB_CS0_B).
 *  0b01..Assert FB_CSn_B on the second rising clock edge after the address is asserted.
 *  0b10..Assert FB_CSn_B on the third rising clock edge after the address is asserted.
 *  0b11..Assert FB_CSn_B on the fourth rising clock edge after the address is asserted (default for FB_CS0_B ).
 */
#define FB_CSCR_ASET(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_ASET_SHIFT)) & FB_CSCR_ASET_MASK)

#define FB_CSCR_EXTS_MASK                        (0x400000U)
#define FB_CSCR_EXTS_SHIFT                       (22U)
/*! EXTS - EXTS
 *  0b0..Disabled. FB_TS_B/FB_ALE asserts for one bus clock cycle.
 *  0b1..Enabled. FB_TS_B/FB_ALE remains asserted until the first positive clock edge after FB_CSn_B asserts.
 */
#define FB_CSCR_EXTS(x)                          (((uint32_t)(((uint32_t)(x)) << FB_CSCR_EXTS_SHIFT)) & FB_CSCR_EXTS_MASK)

#define FB_CSCR_SWSEN_MASK                       (0x800000U)
#define FB_CSCR_SWSEN_SHIFT                      (23U)
/*! SWSEN - Secondary Wait State Enable
 *  0b0..Disabled. A number of wait states (specified by WS) are inserted before an internal transfer acknowledge is generated for all transfers.
 *  0b1..Enabled. A number of wait states (specified by SWS) are inserted before an internal transfer acknowledge
 *       is generated for burst transfer secondary terminations.
 */
#define FB_CSCR_SWSEN(x)                         (((uint32_t)(((uint32_t)(x)) << FB_CSCR_SWSEN_SHIFT)) & FB_CSCR_SWSEN_MASK)

#define FB_CSCR_SWS_MASK                         (0xFC000000U)
#define FB_CSCR_SWS_SHIFT                        (26U)
/*! SWS - Secondary Wait States */
#define FB_CSCR_SWS(x)                           (((uint32_t)(((uint32_t)(x)) << FB_CSCR_SWS_SHIFT)) & FB_CSCR_SWS_MASK)
/*! @} */

/* The count of FB_CSCR */
#define FB_CSCR_COUNT                            (6U)

/*! @name CSPMCR - Chip Select Port Multiplexing Control Register */
/*! @{ */

#define FB_CSPMCR_GROUP5_MASK                    (0xF000U)
#define FB_CSPMCR_GROUP5_SHIFT                   (12U)
/*! GROUP5 - FlexBus Signal Group 5 Multiplex control
 *  0b0000..FB_TA_B
 *  0b0001..FB_CS3_B. You must also write 1b to CSCR[AA].
 *  0b0010..FB_BE_7_0_B. You must also write 1b to CSCR[AA].
 */
#define FB_CSPMCR_GROUP5(x)                      (((uint32_t)(((uint32_t)(x)) << FB_CSPMCR_GROUP5_SHIFT)) & FB_CSPMCR_GROUP5_MASK)

#define FB_CSPMCR_GROUP4_MASK                    (0xF0000U)
#define FB_CSPMCR_GROUP4_SHIFT                   (16U)
/*! GROUP4 - FlexBus Signal Group 4 Multiplex control
 *  0b0000..FB_TBST_B
 *  0b0001..FB_CS2_B
 *  0b0010..FB_BE_15_8_B
 */
#define FB_CSPMCR_GROUP4(x)                      (((uint32_t)(((uint32_t)(x)) << FB_CSPMCR_GROUP4_SHIFT)) & FB_CSPMCR_GROUP4_MASK)

#define FB_CSPMCR_GROUP3_MASK                    (0xF00000U)
#define FB_CSPMCR_GROUP3_SHIFT                   (20U)
/*! GROUP3 - FlexBus Signal Group 3 Multiplex control
 *  0b0000..FB_CS5_B
 *  0b0001..FB_TSIZ1
 *  0b0010..FB_BE_23_16_B
 */
#define FB_CSPMCR_GROUP3(x)                      (((uint32_t)(((uint32_t)(x)) << FB_CSPMCR_GROUP3_SHIFT)) & FB_CSPMCR_GROUP3_MASK)

#define FB_CSPMCR_GROUP2_MASK                    (0xF000000U)
#define FB_CSPMCR_GROUP2_SHIFT                   (24U)
/*! GROUP2 - FlexBus Signal Group 2 Multiplex control
 *  0b0000..FB_CS4_B
 *  0b0001..FB_TSIZ0
 *  0b0010..FB_BE_31_24_B
 */
#define FB_CSPMCR_GROUP2(x)                      (((uint32_t)(((uint32_t)(x)) << FB_CSPMCR_GROUP2_SHIFT)) & FB_CSPMCR_GROUP2_MASK)

#define FB_CSPMCR_GROUP1_MASK                    (0xF0000000U)
#define FB_CSPMCR_GROUP1_SHIFT                   (28U)
/*! GROUP1 - FlexBus Signal Group 1 Multiplex control
 *  0b0000..FB_ALE
 *  0b0001..FB_CS1_B
 *  0b0010..FB_TS_B
 */
#define FB_CSPMCR_GROUP1(x)                      (((uint32_t)(((uint32_t)(x)) << FB_CSPMCR_GROUP1_SHIFT)) & FB_CSPMCR_GROUP1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FB_Register_Masks */


/*!
 * @}
 */ /* end of group FB_Peripheral_Access_Layer */


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


#endif  /* PERI_FB_H_ */

