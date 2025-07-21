/*
** ###################################################################
**     Processors:          LPC51U68JBD48
**                          LPC51U68JBD64
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-12-15)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FMC
 *
 * CMSIS Peripheral Access Layer for FMC
 */

#if !defined(PERI_FMC_H_)
#define PERI_FMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC51U68JBD48) || defined(CPU_LPC51U68JBD64))
#include "LPC51U68_COMMON.h"
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
   -- FMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Peripheral_Access_Layer FMC Peripheral Access Layer
 * @{
 */

/** FMC - Size of Registers Arrays */
#define FMC_FMSW_COUNT                            4u

/** FMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t FCTR;                              /**< Control register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t FBWST;                             /**< Wait state register, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FMSSTART;                          /**< Signature start address register, offset: 0x20 */
  __IO uint32_t FMSSTOP;                           /**< Signature stop-address register, offset: 0x24 */
       uint8_t RESERVED_2[4];
  __I  uint32_t FMSW[FMC_FMSW_COUNT];              /**< Words of 128-bit signature word, array offset: 0x2C, array step: 0x4 */
       uint8_t RESERVED_3[4004];
  __I  uint32_t FMSTAT;                            /**< Signature generation status register, offset: 0xFE0 */
       uint8_t RESERVED_4[4];
  __O  uint32_t FMSTATCLR;                         /**< Signature generation status clear register, offset: 0xFE8 */
} FMC_Type;

/* ----------------------------------------------------------------------------
   -- FMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FMC_Register_Masks FMC Register Masks
 * @{
 */

/*! @name FCTR - Control register */
/*! @{ */

#define FMC_FCTR_FS_RD0_MASK                     (0x8U)
#define FMC_FCTR_FS_RD0_SHIFT                    (3U)
/*! FS_RD0 - Value must be 0 for signature generation. */
#define FMC_FCTR_FS_RD0(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_FCTR_FS_RD0_SHIFT)) & FMC_FCTR_FS_RD0_MASK)

#define FMC_FCTR_FS_RD1_MASK                     (0x10U)
#define FMC_FCTR_FS_RD1_SHIFT                    (4U)
/*! FS_RD1 - Value must be 1 for signature generation. */
#define FMC_FCTR_FS_RD1(x)                       (((uint32_t)(((uint32_t)(x)) << FMC_FCTR_FS_RD1_SHIFT)) & FMC_FCTR_FS_RD1_MASK)
/*! @} */

/*! @name FBWST - Wait state register */
/*! @{ */

#define FMC_FBWST_WAITSTATES_MASK                (0xFFU)
#define FMC_FBWST_WAITSTATES_SHIFT               (0U)
/*! WAITSTATES - Wait states for signature generation. */
#define FMC_FBWST_WAITSTATES(x)                  (((uint32_t)(((uint32_t)(x)) << FMC_FBWST_WAITSTATES_SHIFT)) & FMC_FBWST_WAITSTATES_MASK)
/*! @} */

/*! @name FMSSTART - Signature start address register */
/*! @{ */

#define FMC_FMSSTART_START_MASK                  (0x1FFFFU)
#define FMC_FMSSTART_START_SHIFT                 (0U)
/*! START - Signature generation start address (corresponds to AHB byte address bits[20:4]). */
#define FMC_FMSSTART_START(x)                    (((uint32_t)(((uint32_t)(x)) << FMC_FMSSTART_START_SHIFT)) & FMC_FMSSTART_START_MASK)
/*! @} */

/*! @name FMSSTOP - Signature stop-address register */
/*! @{ */

#define FMC_FMSSTOP_STOP_MASK                    (0x1FFFFU)
#define FMC_FMSSTOP_STOP_SHIFT                   (0U)
/*! STOP - Stop address for signature generation (the word specified by STOP is included in the address range). */
#define FMC_FMSSTOP_STOP(x)                      (((uint32_t)(((uint32_t)(x)) << FMC_FMSSTOP_STOP_SHIFT)) & FMC_FMSSTOP_STOP_MASK)

#define FMC_FMSSTOP_SIG_START_MASK               (0x20000U)
#define FMC_FMSSTOP_SIG_START_SHIFT              (17U)
/*! SIG_START - When this bit is written to 1, signature generation starts. */
#define FMC_FMSSTOP_SIG_START(x)                 (((uint32_t)(((uint32_t)(x)) << FMC_FMSSTOP_SIG_START_SHIFT)) & FMC_FMSSTOP_SIG_START_MASK)
/*! @} */

/*! @name FMSW - Words of 128-bit signature word */
/*! @{ */

#define FMC_FMSW_SW_MASK                         (0xFFFFFFFFU)
#define FMC_FMSW_SW_SHIFT                        (0U)
/*! SW - Words of 128-bit signature (bits). */
#define FMC_FMSW_SW(x)                           (((uint32_t)(((uint32_t)(x)) << FMC_FMSW_SW_SHIFT)) & FMC_FMSW_SW_MASK)
/*! @} */

/*! @name FMSTAT - Signature generation status register */
/*! @{ */

#define FMC_FMSTAT_SIG_DONE_MASK                 (0x4U)
#define FMC_FMSTAT_SIG_DONE_SHIFT                (2U)
/*! SIG_DONE - When 1, a previously started signature generation has completed. */
#define FMC_FMSTAT_SIG_DONE(x)                   (((uint32_t)(((uint32_t)(x)) << FMC_FMSTAT_SIG_DONE_SHIFT)) & FMC_FMSTAT_SIG_DONE_MASK)
/*! @} */

/*! @name FMSTATCLR - Signature generation status clear register */
/*! @{ */

#define FMC_FMSTATCLR_SIG_DONE_CLR_MASK          (0x4U)
#define FMC_FMSTATCLR_SIG_DONE_CLR_SHIFT         (2U)
/*! SIG_DONE_CLR - Writing a 1 to this bits clears the signature generation completion flag (SIG_DONE) in the FMSTAT register. */
#define FMC_FMSTATCLR_SIG_DONE_CLR(x)            (((uint32_t)(((uint32_t)(x)) << FMC_FMSTATCLR_SIG_DONE_CLR_SHIFT)) & FMC_FMSTATCLR_SIG_DONE_CLR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FMC_Register_Masks */


/*!
 * @}
 */ /* end of group FMC_Peripheral_Access_Layer */


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


#endif  /* PERI_FMC_H_ */

