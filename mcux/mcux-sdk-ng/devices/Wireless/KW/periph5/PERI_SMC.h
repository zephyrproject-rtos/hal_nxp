/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file SMC.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for SMC
 *
 * CMSIS Peripheral Access Layer for SMC
 */

#if !defined(SMC_H_)
#define SMC_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- SMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Peripheral_Access_Layer SMC Peripheral Access Layer
 * @{
 */

/** SMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t PMPROT;                             /**< Power Mode Protection register, offset: 0x0 */
  __IO uint8_t PMCTRL;                             /**< Power Mode Control register, offset: 0x1 */
  __IO uint8_t STOPCTRL;                           /**< Stop Control Register, offset: 0x2 */
  __I  uint8_t PMSTAT;                             /**< Power Mode Status register, offset: 0x3 */
} SMC_Type;

/* ----------------------------------------------------------------------------
   -- SMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMC_Register_Masks SMC Register Masks
 * @{
 */

/*! @name PMPROT - Power Mode Protection register */
/*! @{ */

#define SMC_PMPROT_AVLLS_MASK                    (0x2U)
#define SMC_PMPROT_AVLLS_SHIFT                   (1U)
/*! AVLLS - Allow Very-Low-Leakage Stop Mode
 *  0b0..Any VLLSx mode is not allowed
 *  0b1..Any VLLSx mode is allowed
 */
#define SMC_PMPROT_AVLLS(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_AVLLS_SHIFT)) & SMC_PMPROT_AVLLS_MASK)

#define SMC_PMPROT_ALLS_MASK                     (0x8U)
#define SMC_PMPROT_ALLS_SHIFT                    (3U)
/*! ALLS - Allow Low-Leakage Stop Mode
 *  0b0..Any LLSx mode is not allowed
 *  0b1..Any LLSx mode is allowed
 */
#define SMC_PMPROT_ALLS(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_ALLS_SHIFT)) & SMC_PMPROT_ALLS_MASK)

#define SMC_PMPROT_AVLP_MASK                     (0x20U)
#define SMC_PMPROT_AVLP_SHIFT                    (5U)
/*! AVLP - Allow Very-Low-Power Modes
 *  0b0..VLPR, VLPW, and VLPS are not allowed.
 *  0b1..VLPR, VLPW, and VLPS are allowed.
 */
#define SMC_PMPROT_AVLP(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMPROT_AVLP_SHIFT)) & SMC_PMPROT_AVLP_MASK)
/*! @} */

/*! @name PMCTRL - Power Mode Control register */
/*! @{ */

#define SMC_PMCTRL_STOPM_MASK                    (0x7U)
#define SMC_PMCTRL_STOPM_SHIFT                   (0U)
/*! STOPM - Stop Mode Control
 *  0b000..Normal Stop (STOP)
 *  0b001..Reserved
 *  0b010..Very-Low-Power Stop (VLPS)
 *  0b011..Low-Leakage Stop (LLSx)
 *  0b100..Very-Low-Leakage Stop (VLLSx)
 *  0b101..Reserved
 *  0b110..Reseved
 *  0b111..Reserved
 */
#define SMC_PMCTRL_STOPM(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_STOPM_SHIFT)) & SMC_PMCTRL_STOPM_MASK)

#define SMC_PMCTRL_STOPA_MASK                    (0x8U)
#define SMC_PMCTRL_STOPA_SHIFT                   (3U)
/*! STOPA - Stop Aborted
 *  0b0..The previous stop mode entry was successful.
 *  0b1..The previous stop mode entry was aborted.
 */
#define SMC_PMCTRL_STOPA(x)                      (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_STOPA_SHIFT)) & SMC_PMCTRL_STOPA_MASK)

#define SMC_PMCTRL_RUNM_MASK                     (0x60U)
#define SMC_PMCTRL_RUNM_SHIFT                    (5U)
/*! RUNM - Run Mode Control
 *  0b00..Normal Run mode (RUN)
 *  0b01..Reserved
 *  0b10..Very-Low-Power Run mode (VLPR)
 *  0b11..Reserved
 */
#define SMC_PMCTRL_RUNM(x)                       (((uint8_t)(((uint8_t)(x)) << SMC_PMCTRL_RUNM_SHIFT)) & SMC_PMCTRL_RUNM_MASK)
/*! @} */

/*! @name STOPCTRL - Stop Control Register */
/*! @{ */

#define SMC_STOPCTRL_LLSM_MASK                   (0x7U)
#define SMC_STOPCTRL_LLSM_SHIFT                  (0U)
/*! LLSM - LLS or VLLS Mode Control
 *  0b000..VLLS0 if PMCTRL[STOPM]=VLLSx, reserved if PMCTRL[STOPM]=LLSx
 *  0b001..VLLS1 if PMCTRL[STOPM]=VLLSx, reserved if PMCTRL[STOPM]=LLSx
 *  0b010..VLLS2 if PMCTRL[STOPM]=VLLSx, LLS2 if PMCTRL[STOPM]=LLSx
 *  0b011..VLLS3 if PMCTRL[STOPM]=VLLSx, LLS3 if PMCTRL[STOPM]=LLSx
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define SMC_STOPCTRL_LLSM(x)                     (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_LLSM_SHIFT)) & SMC_STOPCTRL_LLSM_MASK)

#define SMC_STOPCTRL_RAM2PO_MASK                 (0x10U)
#define SMC_STOPCTRL_RAM2PO_SHIFT                (4U)
/*! RAM2PO - RAM2 Power Option
 *  0b0..RAM2 not powered in LLS2/VLLS2
 *  0b1..RAM2 powered in LLS2/VLLS2
 */
#define SMC_STOPCTRL_RAM2PO(x)                   (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_RAM2PO_SHIFT)) & SMC_STOPCTRL_RAM2PO_MASK)

#define SMC_STOPCTRL_PORPO_MASK                  (0x20U)
#define SMC_STOPCTRL_PORPO_SHIFT                 (5U)
/*! PORPO - POR Power Option
 *  0b0..POR detect circuit is enabled in VLLS0
 *  0b1..POR detect circuit is disabled in VLLS0
 */
#define SMC_STOPCTRL_PORPO(x)                    (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_PORPO_SHIFT)) & SMC_STOPCTRL_PORPO_MASK)

#define SMC_STOPCTRL_PSTOPO_MASK                 (0xC0U)
#define SMC_STOPCTRL_PSTOPO_SHIFT                (6U)
/*! PSTOPO - Partial Stop Option
 *  0b00..STOP - Normal Stop mode
 *  0b01..PSTOP1 - Partial Stop with both system and bus clocks disabled
 *  0b10..PSTOP2 - Partial Stop with system clock disabled and bus clock enabled
 *  0b11..Reserved
 */
#define SMC_STOPCTRL_PSTOPO(x)                   (((uint8_t)(((uint8_t)(x)) << SMC_STOPCTRL_PSTOPO_SHIFT)) & SMC_STOPCTRL_PSTOPO_MASK)
/*! @} */

/*! @name PMSTAT - Power Mode Status register */
/*! @{ */

#define SMC_PMSTAT_PMSTAT_MASK                   (0xFFU)
#define SMC_PMSTAT_PMSTAT_SHIFT                  (0U)
/*! PMSTAT - Power Mode Status */
#define SMC_PMSTAT_PMSTAT(x)                     (((uint8_t)(((uint8_t)(x)) << SMC_PMSTAT_PMSTAT_SHIFT)) & SMC_PMSTAT_PMSTAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMC_Register_Masks */


/*!
 * @}
 */ /* end of group SMC_Peripheral_Access_Layer */


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


#endif  /* SMC_H_ */

