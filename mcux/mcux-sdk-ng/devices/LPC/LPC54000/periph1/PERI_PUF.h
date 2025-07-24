/*
** ###################################################################
**     Processors:          LPC54005JBD100
**                          LPC54005JET100
**                          LPC54016JBD100
**                          LPC54016JBD208
**                          LPC54016JET100
**                          LPC54016JET180
**                          LPC54018JBD208
**                          LPC54018JET180
**                          LPC54S005JBD100
**                          LPC54S005JET100
**                          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**                          LPC54S018JBD208
**                          LPC54S018JET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PUF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PUF.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PUF
 *
 * CMSIS Peripheral Access Layer for PUF
 */

#if !defined(PERI_PUF_H_)
#define PERI_PUF_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54005JBD100) || defined(CPU_LPC54005JET100))
#include "LPC54005_COMMON.h"
#elif (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || defined(CPU_LPC54016JET180))
#include "LPC54016_COMMON.h"
#elif (defined(CPU_LPC54018JBD208) || defined(CPU_LPC54018JET180))
#include "LPC54018_COMMON.h"
#elif (defined(CPU_LPC54S005JBD100) || defined(CPU_LPC54S005JET100))
#include "LPC54S005_COMMON.h"
#elif (defined(CPU_LPC54S016JBD100) || defined(CPU_LPC54S016JBD208) || defined(CPU_LPC54S016JET100) || defined(CPU_LPC54S016JET180))
#include "LPC54S016_COMMON.h"
#elif (defined(CPU_LPC54S018JBD208) || defined(CPU_LPC54S018JET180))
#include "LPC54S018_COMMON.h"
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
   -- PUF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Peripheral_Access_Layer PUF Peripheral Access Layer
 * @{
 */

/** PUF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< PUF Control register, offset: 0x0 */
  __IO uint32_t KEYINDEX;                          /**< PUF Key Index register, offset: 0x4 */
  __IO uint32_t KEYSIZE;                           /**< PUF Key Size register, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __I  uint32_t STAT;                              /**< PUF Status register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t ALLOW;                             /**< PUF Allow register, offset: 0x28 */
       uint8_t RESERVED_2[20];
  __O  uint32_t KEYINPUT;                          /**< PUF Key Input register, offset: 0x40 */
  __O  uint32_t CODEINPUT;                         /**< PUF Code Input register, offset: 0x44 */
  __I  uint32_t CODEOUTPUT;                        /**< PUF Code Output register, offset: 0x48 */
       uint8_t RESERVED_3[20];
  __I  uint32_t KEYOUTINDEX;                       /**< PUF Key Output Index register, offset: 0x60 */
  __I  uint32_t KEYOUTPUT;                         /**< PUF Key Output register, offset: 0x64 */
       uint8_t RESERVED_4[116];
  __IO uint32_t IFSTAT;                            /**< PUF Interface Status and clear register, offset: 0xDC */
       uint8_t RESERVED_5[32];
  __IO uint32_t INTEN;                             /**< PUF Interrupt Enable, offset: 0x100 */
  __IO uint32_t INTSTAT;                           /**< PUF interrupt status, offset: 0x104 */
  __IO uint32_t PWRCTRL;                           /**< PUF RAM Power Control, offset: 0x108 */
  __IO uint32_t CFG;                               /**< PUF config register for block bits, offset: 0x10C */
} PUF_Type;

/* ----------------------------------------------------------------------------
   -- PUF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Register_Masks PUF Register Masks
 * @{
 */

/*! @name CTRL - PUF Control register */
/*! @{ */

#define PUF_CTRL_ZEROIZE_MASK                    (0x1U)
#define PUF_CTRL_ZEROIZE_SHIFT                   (0U)
/*! zeroize - Begin Zeroize operation for Quiddikey and go to Error state */
#define PUF_CTRL_ZEROIZE(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_ZEROIZE_SHIFT)) & PUF_CTRL_ZEROIZE_MASK)

#define PUF_CTRL_ENROLL_MASK                     (0x2U)
#define PUF_CTRL_ENROLL_SHIFT                    (1U)
/*! enroll - Begin Enroll operation */
#define PUF_CTRL_ENROLL(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_ENROLL_SHIFT)) & PUF_CTRL_ENROLL_MASK)

#define PUF_CTRL_START_MASK                      (0x4U)
#define PUF_CTRL_START_SHIFT                     (2U)
/*! start - Begin Start operation */
#define PUF_CTRL_START(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_START_SHIFT)) & PUF_CTRL_START_MASK)

#define PUF_CTRL_GENERATEKEY_MASK                (0x8U)
#define PUF_CTRL_GENERATEKEY_SHIFT               (3U)
/*! GENERATEKEY - Begin Set Intrinsic Key operation */
#define PUF_CTRL_GENERATEKEY(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_GENERATEKEY_SHIFT)) & PUF_CTRL_GENERATEKEY_MASK)

#define PUF_CTRL_SETKEY_MASK                     (0x10U)
#define PUF_CTRL_SETKEY_SHIFT                    (4U)
/*! SETKEY - Begin Set User Key operation */
#define PUF_CTRL_SETKEY(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_SETKEY_SHIFT)) & PUF_CTRL_SETKEY_MASK)

#define PUF_CTRL_GETKEY_MASK                     (0x40U)
#define PUF_CTRL_GETKEY_SHIFT                    (6U)
/*! GETKEY - Begin Get Key operation */
#define PUF_CTRL_GETKEY(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_GETKEY_SHIFT)) & PUF_CTRL_GETKEY_MASK)
/*! @} */

/*! @name KEYINDEX - PUF Key Index register */
/*! @{ */

#define PUF_KEYINDEX_KEYIDX_MASK                 (0xFU)
#define PUF_KEYINDEX_KEYIDX_SHIFT                (0U)
/*! KEYIDX - Key index for Set Key operations */
#define PUF_KEYINDEX_KEYIDX(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_KEYINDEX_KEYIDX_SHIFT)) & PUF_KEYINDEX_KEYIDX_MASK)
/*! @} */

/*! @name KEYSIZE - PUF Key Size register */
/*! @{ */

#define PUF_KEYSIZE_KEYSIZE_MASK                 (0x3FU)
#define PUF_KEYSIZE_KEYSIZE_SHIFT                (0U)
/*! KEYSIZE - Key size for Set Key operations */
#define PUF_KEYSIZE_KEYSIZE(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_KEYSIZE_KEYSIZE_SHIFT)) & PUF_KEYSIZE_KEYSIZE_MASK)
/*! @} */

/*! @name STAT - PUF Status register */
/*! @{ */

#define PUF_STAT_BUSY_MASK                       (0x1U)
#define PUF_STAT_BUSY_SHIFT                      (0U)
/*! busy - Indicates that operation is in progress */
#define PUF_STAT_BUSY(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_STAT_BUSY_SHIFT)) & PUF_STAT_BUSY_MASK)

#define PUF_STAT_SUCCESS_MASK                    (0x2U)
#define PUF_STAT_SUCCESS_SHIFT                   (1U)
/*! SUCCESS - Last operation was successful */
#define PUF_STAT_SUCCESS(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_STAT_SUCCESS_SHIFT)) & PUF_STAT_SUCCESS_MASK)

#define PUF_STAT_ERROR_MASK                      (0x4U)
#define PUF_STAT_ERROR_SHIFT                     (2U)
/*! error - Quiddikey is in the Error state and no operations can be performed */
#define PUF_STAT_ERROR(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_STAT_ERROR_SHIFT)) & PUF_STAT_ERROR_MASK)

#define PUF_STAT_KEYINREQ_MASK                   (0x10U)
#define PUF_STAT_KEYINREQ_SHIFT                  (4U)
/*! KEYINREQ - Request for next part of key */
#define PUF_STAT_KEYINREQ(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_STAT_KEYINREQ_SHIFT)) & PUF_STAT_KEYINREQ_MASK)

#define PUF_STAT_KEYOUTAVAIL_MASK                (0x20U)
#define PUF_STAT_KEYOUTAVAIL_SHIFT               (5U)
/*! KEYOUTAVAIL - Next part of key is available */
#define PUF_STAT_KEYOUTAVAIL(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_STAT_KEYOUTAVAIL_SHIFT)) & PUF_STAT_KEYOUTAVAIL_MASK)

#define PUF_STAT_CODEINREQ_MASK                  (0x40U)
#define PUF_STAT_CODEINREQ_SHIFT                 (6U)
/*! CODEINREQ - Request for next part of AC/KC */
#define PUF_STAT_CODEINREQ(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_STAT_CODEINREQ_SHIFT)) & PUF_STAT_CODEINREQ_MASK)

#define PUF_STAT_CODEOUTAVAIL_MASK               (0x80U)
#define PUF_STAT_CODEOUTAVAIL_SHIFT              (7U)
/*! CODEOUTAVAIL - Next part of AC/KC is available */
#define PUF_STAT_CODEOUTAVAIL(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_STAT_CODEOUTAVAIL_SHIFT)) & PUF_STAT_CODEOUTAVAIL_MASK)
/*! @} */

/*! @name ALLOW - PUF Allow register */
/*! @{ */

#define PUF_ALLOW_ALLOWENROLL_MASK               (0x1U)
#define PUF_ALLOW_ALLOWENROLL_SHIFT              (0U)
/*! ALLOWENROLL - Enroll operation is allowed */
#define PUF_ALLOW_ALLOWENROLL(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWENROLL_SHIFT)) & PUF_ALLOW_ALLOWENROLL_MASK)

#define PUF_ALLOW_ALLOWSTART_MASK                (0x2U)
#define PUF_ALLOW_ALLOWSTART_SHIFT               (1U)
/*! ALLOWSTART - Start operation is allowed */
#define PUF_ALLOW_ALLOWSTART(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWSTART_SHIFT)) & PUF_ALLOW_ALLOWSTART_MASK)

#define PUF_ALLOW_ALLOWSETKEY_MASK               (0x4U)
#define PUF_ALLOW_ALLOWSETKEY_SHIFT              (2U)
/*! ALLOWSETKEY - Set Key operations are allowed */
#define PUF_ALLOW_ALLOWSETKEY(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWSETKEY_SHIFT)) & PUF_ALLOW_ALLOWSETKEY_MASK)

#define PUF_ALLOW_ALLOWGETKEY_MASK               (0x8U)
#define PUF_ALLOW_ALLOWGETKEY_SHIFT              (3U)
/*! ALLOWGETKEY - Get Key operation is allowed */
#define PUF_ALLOW_ALLOWGETKEY(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWGETKEY_SHIFT)) & PUF_ALLOW_ALLOWGETKEY_MASK)
/*! @} */

/*! @name KEYINPUT - PUF Key Input register */
/*! @{ */

#define PUF_KEYINPUT_KEYIN_MASK                  (0xFFFFFFFFU)
#define PUF_KEYINPUT_KEYIN_SHIFT                 (0U)
/*! KEYIN - Key input data */
#define PUF_KEYINPUT_KEYIN(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYINPUT_KEYIN_SHIFT)) & PUF_KEYINPUT_KEYIN_MASK)
/*! @} */

/*! @name CODEINPUT - PUF Code Input register */
/*! @{ */

#define PUF_CODEINPUT_CODEIN_MASK                (0xFFFFFFFFU)
#define PUF_CODEINPUT_CODEIN_SHIFT               (0U)
/*! CODEIN - AC/KC input data */
#define PUF_CODEINPUT_CODEIN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_CODEINPUT_CODEIN_SHIFT)) & PUF_CODEINPUT_CODEIN_MASK)
/*! @} */

/*! @name CODEOUTPUT - PUF Code Output register */
/*! @{ */

#define PUF_CODEOUTPUT_CODEOUT_MASK              (0xFFFFFFFFU)
#define PUF_CODEOUTPUT_CODEOUT_SHIFT             (0U)
/*! CODEOUT - AC/KC output data */
#define PUF_CODEOUTPUT_CODEOUT(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CODEOUTPUT_CODEOUT_SHIFT)) & PUF_CODEOUTPUT_CODEOUT_MASK)
/*! @} */

/*! @name KEYOUTINDEX - PUF Key Output Index register */
/*! @{ */

#define PUF_KEYOUTINDEX_KEYOUTIDX_MASK           (0xFU)
#define PUF_KEYOUTINDEX_KEYOUTIDX_SHIFT          (0U)
/*! KEYOUTIDX - Key index for the key that is currently output via the Key Output register */
#define PUF_KEYOUTINDEX_KEYOUTIDX(x)             (((uint32_t)(((uint32_t)(x)) << PUF_KEYOUTINDEX_KEYOUTIDX_SHIFT)) & PUF_KEYOUTINDEX_KEYOUTIDX_MASK)
/*! @} */

/*! @name KEYOUTPUT - PUF Key Output register */
/*! @{ */

#define PUF_KEYOUTPUT_KEYOUT_MASK                (0xFFFFFFFFU)
#define PUF_KEYOUTPUT_KEYOUT_SHIFT               (0U)
/*! KEYOUT - Key output data */
#define PUF_KEYOUTPUT_KEYOUT(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_KEYOUTPUT_KEYOUT_SHIFT)) & PUF_KEYOUTPUT_KEYOUT_MASK)
/*! @} */

/*! @name IFSTAT - PUF Interface Status and clear register */
/*! @{ */

#define PUF_IFSTAT_ERROR_MASK                    (0x1U)
#define PUF_IFSTAT_ERROR_SHIFT                   (0U)
/*! ERROR - Indicates that an APB error has occurred,Writing logic1 clears the if_error bit */
#define PUF_IFSTAT_ERROR(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_IFSTAT_ERROR_SHIFT)) & PUF_IFSTAT_ERROR_MASK)
/*! @} */

/*! @name INTEN - PUF Interrupt Enable */
/*! @{ */

#define PUF_INTEN_READYEN_MASK                   (0x1U)
#define PUF_INTEN_READYEN_SHIFT                  (0U)
/*! READYEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_READYEN(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_READYEN_SHIFT)) & PUF_INTEN_READYEN_MASK)

#define PUF_INTEN_SUCCESEN_MASK                  (0x2U)
#define PUF_INTEN_SUCCESEN_SHIFT                 (1U)
/*! SUCCESEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_SUCCESEN(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_SUCCESEN_SHIFT)) & PUF_INTEN_SUCCESEN_MASK)

#define PUF_INTEN_ERROREN_MASK                   (0x4U)
#define PUF_INTEN_ERROREN_SHIFT                  (2U)
/*! ERROREN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_ERROREN(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_ERROREN_SHIFT)) & PUF_INTEN_ERROREN_MASK)

#define PUF_INTEN_KEYINREQEN_MASK                (0x10U)
#define PUF_INTEN_KEYINREQEN_SHIFT               (4U)
/*! KEYINREQEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_KEYINREQEN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_KEYINREQEN_SHIFT)) & PUF_INTEN_KEYINREQEN_MASK)

#define PUF_INTEN_KEYOUTAVAILEN_MASK             (0x20U)
#define PUF_INTEN_KEYOUTAVAILEN_SHIFT            (5U)
/*! KEYOUTAVAILEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_KEYOUTAVAILEN(x)               (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_KEYOUTAVAILEN_SHIFT)) & PUF_INTEN_KEYOUTAVAILEN_MASK)

#define PUF_INTEN_CODEINREQEN_MASK               (0x40U)
#define PUF_INTEN_CODEINREQEN_SHIFT              (6U)
/*! CODEINREQEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_CODEINREQEN(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_CODEINREQEN_SHIFT)) & PUF_INTEN_CODEINREQEN_MASK)

#define PUF_INTEN_CODEOUTAVAILEN_MASK            (0x80U)
#define PUF_INTEN_CODEOUTAVAILEN_SHIFT           (7U)
/*! CODEOUTAVAILEN - Enable corresponding interrupt. Note that bit numbers match those assigned in QK_SR (Quiddikey Status Register) */
#define PUF_INTEN_CODEOUTAVAILEN(x)              (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_CODEOUTAVAILEN_SHIFT)) & PUF_INTEN_CODEOUTAVAILEN_MASK)
/*! @} */

/*! @name INTSTAT - PUF interrupt status */
/*! @{ */

#define PUF_INTSTAT_READY_MASK                   (0x1U)
#define PUF_INTSTAT_READY_SHIFT                  (0U)
/*! READY - Triggers on falling edge of busy, write 1 to clear */
#define PUF_INTSTAT_READY(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_READY_SHIFT)) & PUF_INTSTAT_READY_MASK)

#define PUF_INTSTAT_SUCCESS_MASK                 (0x2U)
#define PUF_INTSTAT_SUCCESS_SHIFT                (1U)
/*! SUCCESS - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_SUCCESS(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_SUCCESS_SHIFT)) & PUF_INTSTAT_SUCCESS_MASK)

#define PUF_INTSTAT_ERROR_MASK                   (0x4U)
#define PUF_INTSTAT_ERROR_SHIFT                  (2U)
/*! ERROR - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_ERROR(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_ERROR_SHIFT)) & PUF_INTSTAT_ERROR_MASK)

#define PUF_INTSTAT_KEYINREQ_MASK                (0x10U)
#define PUF_INTSTAT_KEYINREQ_SHIFT               (4U)
/*! KEYINREQ - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_KEYINREQ(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_KEYINREQ_SHIFT)) & PUF_INTSTAT_KEYINREQ_MASK)

#define PUF_INTSTAT_KEYOUTAVAIL_MASK             (0x20U)
#define PUF_INTSTAT_KEYOUTAVAIL_SHIFT            (5U)
/*! KEYOUTAVAIL - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_KEYOUTAVAIL(x)               (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_KEYOUTAVAIL_SHIFT)) & PUF_INTSTAT_KEYOUTAVAIL_MASK)

#define PUF_INTSTAT_CODEINREQ_MASK               (0x40U)
#define PUF_INTSTAT_CODEINREQ_SHIFT              (6U)
/*! CODEINREQ - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_CODEINREQ(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_CODEINREQ_SHIFT)) & PUF_INTSTAT_CODEINREQ_MASK)

#define PUF_INTSTAT_CODEOUTAVAIL_MASK            (0x80U)
#define PUF_INTSTAT_CODEOUTAVAIL_SHIFT           (7U)
/*! CODEOUTAVAIL - Level sensitive interrupt, cleared when interrupt source clears */
#define PUF_INTSTAT_CODEOUTAVAIL(x)              (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_CODEOUTAVAIL_SHIFT)) & PUF_INTSTAT_CODEOUTAVAIL_MASK)
/*! @} */

/*! @name PWRCTRL - PUF RAM Power Control */
/*! @{ */

#define PUF_PWRCTRL_RAMON_MASK                   (0x1U)
#define PUF_PWRCTRL_RAMON_SHIFT                  (0U)
/*! RAMON - Power on the PUF RAM. */
#define PUF_PWRCTRL_RAMON(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_PWRCTRL_RAMON_SHIFT)) & PUF_PWRCTRL_RAMON_MASK)

#define PUF_PWRCTRL_RAMSTAT_MASK                 (0x2U)
#define PUF_PWRCTRL_RAMSTAT_SHIFT                (1U)
/*! RAMSTAT - PUF RAM status. */
#define PUF_PWRCTRL_RAMSTAT(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_PWRCTRL_RAMSTAT_SHIFT)) & PUF_PWRCTRL_RAMSTAT_MASK)
/*! @} */

/*! @name CFG - PUF config register for block bits */
/*! @{ */

#define PUF_CFG_BLOCKENROLL_SETKEY_MASK          (0x1U)
#define PUF_CFG_BLOCKENROLL_SETKEY_SHIFT         (0U)
/*! BLOCKENROLL_SETKEY - Block enroll operation. Write 1 to set, cleared on reset. */
#define PUF_CFG_BLOCKENROLL_SETKEY(x)            (((uint32_t)(((uint32_t)(x)) << PUF_CFG_BLOCKENROLL_SETKEY_SHIFT)) & PUF_CFG_BLOCKENROLL_SETKEY_MASK)

#define PUF_CFG_BLOCKKEYOUTPUT_MASK              (0x2U)
#define PUF_CFG_BLOCKKEYOUTPUT_SHIFT             (1U)
/*! BLOCKKEYOUTPUT - Block set key operation. Write 1 to set, cleared on reset. */
#define PUF_CFG_BLOCKKEYOUTPUT(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CFG_BLOCKKEYOUTPUT_SHIFT)) & PUF_CFG_BLOCKKEYOUTPUT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PUF_Register_Masks */


/*!
 * @}
 */ /* end of group PUF_Peripheral_Access_Layer */


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


#endif  /* PERI_PUF_H_ */

