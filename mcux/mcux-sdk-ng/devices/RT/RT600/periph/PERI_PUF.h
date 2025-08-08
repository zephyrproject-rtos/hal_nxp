/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PUF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PUF
 *
 * CMSIS Peripheral Access Layer for PUF
 */

#if !defined(PERI_PUF_H_)
#define PERI_PUF_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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

/** PUF - Size of Registers Arrays */
#define PUF_KEYMASK_COUNT                         2u

/** PUF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< PUF Control, offset: 0x0 */
  __IO uint32_t KEYINDEX;                          /**< PUF Key Index, offset: 0x4 */
  __IO uint32_t KEYSIZE;                           /**< PUF Key Size, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __I  uint32_t STAT;                              /**< PUF Status, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t ALLOW;                             /**< PUF Allow, offset: 0x28 */
       uint8_t RESERVED_2[20];
  __O  uint32_t KEYINPUT;                          /**< PUF Key Input, offset: 0x40 */
  __O  uint32_t CODEINPUT;                         /**< PUF Code Input, offset: 0x44 */
  __I  uint32_t CODEOUTPUT;                        /**< PUF Code Output, offset: 0x48 */
       uint8_t RESERVED_3[20];
  __I  uint32_t KEYOUTINDEX;                       /**< PUF Key Output Index, offset: 0x60 */
  __I  uint32_t KEYOUTPUT;                         /**< PUF Key Output, offset: 0x64 */
       uint8_t RESERVED_4[116];
  __IO uint32_t IFSTAT;                            /**< PUF Interface Status and Clear, offset: 0xDC */
       uint8_t RESERVED_5[28];
  __I  uint32_t VERSION;                           /**< PUF Version, offset: 0xFC */
  __IO uint32_t INTEN;                             /**< PUF Interrupt Enable, offset: 0x100 */
  __IO uint32_t INTSTAT;                           /**< PUF Interrupt Status, offset: 0x104 */
  __IO uint32_t PWRCTRL;                           /**< PUF Power Control, offset: 0x108 */
  __IO uint32_t CFG;                               /**< PUF Configuration, offset: 0x10C */
       uint8_t RESERVED_6[240];
  __IO uint32_t KEYLOCK;                           /**< Key Lock, offset: 0x200 */
  __IO uint32_t KEYENABLE;                         /**< Key Enable, offset: 0x204 */
  __O  uint32_t KEYRESET;                          /**< Key Reset, offset: 0x208 */
  __IO uint32_t IDXBLK_L;                          /**< Index Block Low, offset: 0x20C */
  __IO uint32_t IDXBLK_H_DP;                       /**< Index Block High Duplicate, offset: 0x210 */
  __O  uint32_t KEYMASK[PUF_KEYMASK_COUNT];        /**< Key Mask 0..Key Mask 1, array offset: 0x214, array step: 0x4 */
       uint8_t RESERVED_7[56];
  __IO uint32_t IDXBLK_H;                          /**< Index Block High, offset: 0x254 */
  __IO uint32_t IDXBLK_L_DP;                       /**< Index Block Low Duplicate, offset: 0x258 */
} PUF_Type;

/* ----------------------------------------------------------------------------
   -- PUF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Register_Masks PUF Register Masks
 * @{
 */

/*! @name CTRL - PUF Control */
/*! @{ */

#define PUF_CTRL_ZEROIZE_MASK                    (0x1U)
#define PUF_CTRL_ZEROIZE_SHIFT                   (0U)
#define PUF_CTRL_ZEROIZE(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_ZEROIZE_SHIFT)) & PUF_CTRL_ZEROIZE_MASK)

#define PUF_CTRL_ENROLL_MASK                     (0x2U)
#define PUF_CTRL_ENROLL_SHIFT                    (1U)
#define PUF_CTRL_ENROLL(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_ENROLL_SHIFT)) & PUF_CTRL_ENROLL_MASK)

#define PUF_CTRL_START_MASK                      (0x4U)
#define PUF_CTRL_START_SHIFT                     (2U)
#define PUF_CTRL_START(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_START_SHIFT)) & PUF_CTRL_START_MASK)

#define PUF_CTRL_GENERATEKEY_MASK                (0x8U)
#define PUF_CTRL_GENERATEKEY_SHIFT               (3U)
#define PUF_CTRL_GENERATEKEY(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_GENERATEKEY_SHIFT)) & PUF_CTRL_GENERATEKEY_MASK)

#define PUF_CTRL_SETKEY_MASK                     (0x10U)
#define PUF_CTRL_SETKEY_SHIFT                    (4U)
#define PUF_CTRL_SETKEY(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_SETKEY_SHIFT)) & PUF_CTRL_SETKEY_MASK)

#define PUF_CTRL_GETKEY_MASK                     (0x40U)
#define PUF_CTRL_GETKEY_SHIFT                    (6U)
#define PUF_CTRL_GETKEY(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CTRL_GETKEY_SHIFT)) & PUF_CTRL_GETKEY_MASK)
/*! @} */

/*! @name KEYINDEX - PUF Key Index */
/*! @{ */

#define PUF_KEYINDEX_KEYIDX_MASK                 (0xFU)
#define PUF_KEYINDEX_KEYIDX_SHIFT                (0U)
#define PUF_KEYINDEX_KEYIDX(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_KEYINDEX_KEYIDX_SHIFT)) & PUF_KEYINDEX_KEYIDX_MASK)
/*! @} */

/*! @name KEYSIZE - PUF Key Size */
/*! @{ */

#define PUF_KEYSIZE_KEYSIZE_MASK                 (0x3FU)
#define PUF_KEYSIZE_KEYSIZE_SHIFT                (0U)
/*! KEYSIZE - Key Size for Set Key operations */
#define PUF_KEYSIZE_KEYSIZE(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_KEYSIZE_KEYSIZE_SHIFT)) & PUF_KEYSIZE_KEYSIZE_MASK)
/*! @} */

/*! @name STAT - PUF Status */
/*! @{ */

#define PUF_STAT_BUSY_MASK                       (0x1U)
#define PUF_STAT_BUSY_SHIFT                      (0U)
/*! BUSY - Busy */
#define PUF_STAT_BUSY(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_STAT_BUSY_SHIFT)) & PUF_STAT_BUSY_MASK)

#define PUF_STAT_SUCCESS_MASK                    (0x2U)
#define PUF_STAT_SUCCESS_SHIFT                   (1U)
/*! SUCCESS - Success */
#define PUF_STAT_SUCCESS(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_STAT_SUCCESS_SHIFT)) & PUF_STAT_SUCCESS_MASK)

#define PUF_STAT_ERROR_MASK                      (0x4U)
#define PUF_STAT_ERROR_SHIFT                     (2U)
/*! ERROR - Error */
#define PUF_STAT_ERROR(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_STAT_ERROR_SHIFT)) & PUF_STAT_ERROR_MASK)

#define PUF_STAT_KEYINREQ_MASK                   (0x10U)
#define PUF_STAT_KEYINREQ_SHIFT                  (4U)
/*! KEYINREQ - Key In Request */
#define PUF_STAT_KEYINREQ(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_STAT_KEYINREQ_SHIFT)) & PUF_STAT_KEYINREQ_MASK)

#define PUF_STAT_KEYOUTAVAIL_MASK                (0x20U)
#define PUF_STAT_KEYOUTAVAIL_SHIFT               (5U)
/*! KEYOUTAVAIL - Key Out Available */
#define PUF_STAT_KEYOUTAVAIL(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_STAT_KEYOUTAVAIL_SHIFT)) & PUF_STAT_KEYOUTAVAIL_MASK)

#define PUF_STAT_CODEINREQ_MASK                  (0x40U)
#define PUF_STAT_CODEINREQ_SHIFT                 (6U)
/*! CODEINREQ - Code In Request */
#define PUF_STAT_CODEINREQ(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_STAT_CODEINREQ_SHIFT)) & PUF_STAT_CODEINREQ_MASK)

#define PUF_STAT_CODEOUTAVAIL_MASK               (0x80U)
#define PUF_STAT_CODEOUTAVAIL_SHIFT              (7U)
/*! CODEOUTAVAIL - Code Out Available */
#define PUF_STAT_CODEOUTAVAIL(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_STAT_CODEOUTAVAIL_SHIFT)) & PUF_STAT_CODEOUTAVAIL_MASK)
/*! @} */

/*! @name ALLOW - PUF Allow */
/*! @{ */

#define PUF_ALLOW_ALLOWENROLL_MASK               (0x1U)
#define PUF_ALLOW_ALLOWENROLL_SHIFT              (0U)
/*! ALLOWENROLL - Allow Enroll */
#define PUF_ALLOW_ALLOWENROLL(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWENROLL_SHIFT)) & PUF_ALLOW_ALLOWENROLL_MASK)

#define PUF_ALLOW_ALLOWSTART_MASK                (0x2U)
#define PUF_ALLOW_ALLOWSTART_SHIFT               (1U)
/*! ALLOWSTART - Allow Start */
#define PUF_ALLOW_ALLOWSTART(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWSTART_SHIFT)) & PUF_ALLOW_ALLOWSTART_MASK)

#define PUF_ALLOW_ALLOWSETKEY_MASK               (0x4U)
#define PUF_ALLOW_ALLOWSETKEY_SHIFT              (2U)
/*! ALLOWSETKEY - Allow Set Key */
#define PUF_ALLOW_ALLOWSETKEY(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWSETKEY_SHIFT)) & PUF_ALLOW_ALLOWSETKEY_MASK)

#define PUF_ALLOW_ALLOWGETKEY_MASK               (0x8U)
#define PUF_ALLOW_ALLOWGETKEY_SHIFT              (3U)
/*! ALLOWGETKEY - Allow Get Key */
#define PUF_ALLOW_ALLOWGETKEY(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_ALLOW_ALLOWGETKEY_SHIFT)) & PUF_ALLOW_ALLOWGETKEY_MASK)
/*! @} */

/*! @name KEYINPUT - PUF Key Input */
/*! @{ */

#define PUF_KEYINPUT_KEYIN_MASK                  (0xFFFFFFFFU)
#define PUF_KEYINPUT_KEYIN_SHIFT                 (0U)
/*! KEYIN - Key Input Data */
#define PUF_KEYINPUT_KEYIN(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYINPUT_KEYIN_SHIFT)) & PUF_KEYINPUT_KEYIN_MASK)
/*! @} */

/*! @name CODEINPUT - PUF Code Input */
/*! @{ */

#define PUF_CODEINPUT_CODEIN_MASK                (0xFFFFFFFFU)
#define PUF_CODEINPUT_CODEIN_SHIFT               (0U)
/*! CODEIN - AC/KC Input Data */
#define PUF_CODEINPUT_CODEIN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_CODEINPUT_CODEIN_SHIFT)) & PUF_CODEINPUT_CODEIN_MASK)
/*! @} */

/*! @name CODEOUTPUT - PUF Code Output */
/*! @{ */

#define PUF_CODEOUTPUT_CODEOUT_MASK              (0xFFFFFFFFU)
#define PUF_CODEOUTPUT_CODEOUT_SHIFT             (0U)
/*! CODEOUT - AC/KC Output Data */
#define PUF_CODEOUTPUT_CODEOUT(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CODEOUTPUT_CODEOUT_SHIFT)) & PUF_CODEOUTPUT_CODEOUT_MASK)
/*! @} */

/*! @name KEYOUTINDEX - PUF Key Output Index */
/*! @{ */

#define PUF_KEYOUTINDEX_KEYOUTIDX_MASK           (0xFU)
#define PUF_KEYOUTINDEX_KEYOUTIDX_SHIFT          (0U)
/*! KEYOUTIDX - Key Output Index */
#define PUF_KEYOUTINDEX_KEYOUTIDX(x)             (((uint32_t)(((uint32_t)(x)) << PUF_KEYOUTINDEX_KEYOUTIDX_SHIFT)) & PUF_KEYOUTINDEX_KEYOUTIDX_MASK)
/*! @} */

/*! @name KEYOUTPUT - PUF Key Output */
/*! @{ */

#define PUF_KEYOUTPUT_KEYOUT_MASK                (0xFFFFFFFFU)
#define PUF_KEYOUTPUT_KEYOUT_SHIFT               (0U)
/*! KEYOUT - Key Output Data */
#define PUF_KEYOUTPUT_KEYOUT(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_KEYOUTPUT_KEYOUT_SHIFT)) & PUF_KEYOUTPUT_KEYOUT_MASK)
/*! @} */

/*! @name IFSTAT - PUF Interface Status and Clear */
/*! @{ */

#define PUF_IFSTAT_ERROR_MASK                    (0x1U)
#define PUF_IFSTAT_ERROR_SHIFT                   (0U)
/*! ERROR - Error */
#define PUF_IFSTAT_ERROR(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_IFSTAT_ERROR_SHIFT)) & PUF_IFSTAT_ERROR_MASK)
/*! @} */

/*! @name VERSION - PUF Version */
/*! @{ */

#define PUF_VERSION_VERSION_MASK                 (0xFFFFFFFFU)
#define PUF_VERSION_VERSION_SHIFT                (0U)
/*! VERSION - Version */
#define PUF_VERSION_VERSION(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_VERSION_VERSION_SHIFT)) & PUF_VERSION_VERSION_MASK)
/*! @} */

/*! @name INTEN - PUF Interrupt Enable */
/*! @{ */

#define PUF_INTEN_READYEN_MASK                   (0x1U)
#define PUF_INTEN_READYEN_SHIFT                  (0U)
/*! READYEN - Enable corresponding interrupt in STAT, which indicates that the initialization or a operation is completed. */
#define PUF_INTEN_READYEN(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_READYEN_SHIFT)) & PUF_INTEN_READYEN_MASK)

#define PUF_INTEN_SUCCESEN_MASK                  (0x2U)
#define PUF_INTEN_SUCCESEN_SHIFT                 (1U)
/*! SUCCESEN - Enable corresponding interrupt in STAT, which indicates last operation was successful. */
#define PUF_INTEN_SUCCESEN(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_SUCCESEN_SHIFT)) & PUF_INTEN_SUCCESEN_MASK)

#define PUF_INTEN_ERROREN_MASK                   (0x4U)
#define PUF_INTEN_ERROREN_SHIFT                  (2U)
/*! ERROREN - Enable corresponding interrupt in STAT, which indicates that PUF is in the error state
 *    and no operations can be performed.
 */
#define PUF_INTEN_ERROREN(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_ERROREN_SHIFT)) & PUF_INTEN_ERROREN_MASK)

#define PUF_INTEN_KEYINREQEN_MASK                (0x10U)
#define PUF_INTEN_KEYINREQEN_SHIFT               (4U)
/*! KEYINREQEN - Enable corresponding interrupt in STAT, which is request for next part of key. */
#define PUF_INTEN_KEYINREQEN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_KEYINREQEN_SHIFT)) & PUF_INTEN_KEYINREQEN_MASK)

#define PUF_INTEN_KEYOUTAVAILEN_MASK             (0x20U)
#define PUF_INTEN_KEYOUTAVAILEN_SHIFT            (5U)
/*! KEYOUTAVAILEN - Enable corresponding interrupt in STAT, which is next part of key is available. */
#define PUF_INTEN_KEYOUTAVAILEN(x)               (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_KEYOUTAVAILEN_SHIFT)) & PUF_INTEN_KEYOUTAVAILEN_MASK)

#define PUF_INTEN_CODEINREQEN_MASK               (0x40U)
#define PUF_INTEN_CODEINREQEN_SHIFT              (6U)
/*! CODEINREQEN - Enable corresponding interrupt in STAT, which is request for next part of AC/KC. */
#define PUF_INTEN_CODEINREQEN(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_CODEINREQEN_SHIFT)) & PUF_INTEN_CODEINREQEN_MASK)

#define PUF_INTEN_CODEOUTAVAILEN_MASK            (0x80U)
#define PUF_INTEN_CODEOUTAVAILEN_SHIFT           (7U)
/*! CODEOUTAVAILEN - Enable corresponding interrupt in STAT, which is next part of AC/KC is available. */
#define PUF_INTEN_CODEOUTAVAILEN(x)              (((uint32_t)(((uint32_t)(x)) << PUF_INTEN_CODEOUTAVAILEN_SHIFT)) & PUF_INTEN_CODEOUTAVAILEN_MASK)
/*! @} */

/*! @name INTSTAT - PUF Interrupt Status */
/*! @{ */

#define PUF_INTSTAT_READY_MASK                   (0x1U)
#define PUF_INTSTAT_READY_SHIFT                  (0U)
/*! READY - Ready */
#define PUF_INTSTAT_READY(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_READY_SHIFT)) & PUF_INTSTAT_READY_MASK)

#define PUF_INTSTAT_SUCCESS_MASK                 (0x2U)
#define PUF_INTSTAT_SUCCESS_SHIFT                (1U)
/*! SUCCESS - Success */
#define PUF_INTSTAT_SUCCESS(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_SUCCESS_SHIFT)) & PUF_INTSTAT_SUCCESS_MASK)

#define PUF_INTSTAT_ERROR_MASK                   (0x4U)
#define PUF_INTSTAT_ERROR_SHIFT                  (2U)
/*! ERROR - Error */
#define PUF_INTSTAT_ERROR(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_ERROR_SHIFT)) & PUF_INTSTAT_ERROR_MASK)

#define PUF_INTSTAT_KEYINREQ_MASK                (0x10U)
#define PUF_INTSTAT_KEYINREQ_SHIFT               (4U)
/*! KEYINREQ - Key In Request */
#define PUF_INTSTAT_KEYINREQ(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_KEYINREQ_SHIFT)) & PUF_INTSTAT_KEYINREQ_MASK)

#define PUF_INTSTAT_KEYOUTAVAIL_MASK             (0x20U)
#define PUF_INTSTAT_KEYOUTAVAIL_SHIFT            (5U)
/*! KEYOUTAVAIL - Key Out Available */
#define PUF_INTSTAT_KEYOUTAVAIL(x)               (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_KEYOUTAVAIL_SHIFT)) & PUF_INTSTAT_KEYOUTAVAIL_MASK)

#define PUF_INTSTAT_CODEINREQ_MASK               (0x40U)
#define PUF_INTSTAT_CODEINREQ_SHIFT              (6U)
/*! CODEINREQ - Code In Request */
#define PUF_INTSTAT_CODEINREQ(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_CODEINREQ_SHIFT)) & PUF_INTSTAT_CODEINREQ_MASK)

#define PUF_INTSTAT_CODEOUTAVAIL_MASK            (0x80U)
#define PUF_INTSTAT_CODEOUTAVAIL_SHIFT           (7U)
/*! CODEOUTAVAIL - Code Out Available */
#define PUF_INTSTAT_CODEOUTAVAIL(x)              (((uint32_t)(((uint32_t)(x)) << PUF_INTSTAT_CODEOUTAVAIL_SHIFT)) & PUF_INTSTAT_CODEOUTAVAIL_MASK)
/*! @} */

/*! @name PWRCTRL - PUF Power Control */
/*! @{ */

#define PUF_PWRCTRL_RAM_ON_MASK                  (0x1U)
#define PUF_PWRCTRL_RAM_ON_SHIFT                 (0U)
/*! RAM_ON - RAM Power On
 *  0b0..Power Off
 *  0b1..Power On
 */
#define PUF_PWRCTRL_RAM_ON(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_PWRCTRL_RAM_ON_SHIFT)) & PUF_PWRCTRL_RAM_ON_MASK)

#define PUF_PWRCTRL_CK_DIS_MASK                  (0x4U)
#define PUF_PWRCTRL_CK_DIS_SHIFT                 (2U)
/*! CK_DIS - PUF Clock control.
 *  0b0..PUF RAM clock is disabled.
 *  0b1..PUF RAM clock is enabled.
 */
#define PUF_PWRCTRL_CK_DIS(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_PWRCTRL_CK_DIS_SHIFT)) & PUF_PWRCTRL_CK_DIS_MASK)
/*! @} */

/*! @name CFG - PUF Configuration */
/*! @{ */

#define PUF_CFG_BLOCKENROLL_SETKEY_MASK          (0x1U)
#define PUF_CFG_BLOCKENROLL_SETKEY_SHIFT         (0U)
/*! BLOCKENROLL_SETKEY - Block Enroll and Set Key Operation
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PUF_CFG_BLOCKENROLL_SETKEY(x)            (((uint32_t)(((uint32_t)(x)) << PUF_CFG_BLOCKENROLL_SETKEY_SHIFT)) & PUF_CFG_BLOCKENROLL_SETKEY_MASK)

#define PUF_CFG_BLOCKKEYOUTPUT_MASK              (0x2U)
#define PUF_CFG_BLOCKKEYOUTPUT_SHIFT             (1U)
/*! BLOCKKEYOUTPUT - Block Key Output Data
 *  0b0..Disabled. BLOCKKEYOUTPUT is cleared on reset.
 *  0b1..Enabled.
 */
#define PUF_CFG_BLOCKKEYOUTPUT(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CFG_BLOCKKEYOUTPUT_SHIFT)) & PUF_CFG_BLOCKKEYOUTPUT_MASK)
/*! @} */

/*! @name KEYLOCK - Key Lock */
/*! @{ */

#define PUF_KEYLOCK_KEY0_MASK                    (0x3U)
#define PUF_KEYLOCK_KEY0_SHIFT                   (0U)
/*! KEY0 - Key 0
 *  0b00, 0b01, 0b11..Write access to KEY0MASK, KEYENABLE[KEY0] and KEYRESET[KEY0] is NOT allowed.
 *  0b10..Write access to KEY0MASK, KEYENABLE[KEY0] and KEYRESET[KEY0] is allowed.
 */
#define PUF_KEYLOCK_KEY0(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_KEYLOCK_KEY0_SHIFT)) & PUF_KEYLOCK_KEY0_MASK)

#define PUF_KEYLOCK_KEY1_MASK                    (0xCU)
#define PUF_KEYLOCK_KEY1_SHIFT                   (2U)
/*! KEY1 - Key 1
 *  0b00, 0b01, 0b11..Write access to KEY1MASK, KEYENABLE[KEY1] and KEYRESET[KEY1] is NOT allowed.
 *  0b10..Write access to KEY1MASK, KEYENABLE[KEY1] and KEYRESET[KEY1] is allowed.
 */
#define PUF_KEYLOCK_KEY1(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_KEYLOCK_KEY1_SHIFT)) & PUF_KEYLOCK_KEY1_MASK)

#define PUF_KEYLOCK_KEY2_MASK                    (0x30U)
#define PUF_KEYLOCK_KEY2_SHIFT                   (4U)
/*! KEY2 - Key 2
 *  0b00, 0b01, 0b11..Write access to KEY2MASK, KEYENABLE[KEY2] and KEYRESET[KEY2] is NOT allowed.
 *  0b10..Write access to KEY2MASK, KEYENABLE[KEY2] and KEYRESET[KEY2] is allowed.
 */
#define PUF_KEYLOCK_KEY2(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_KEYLOCK_KEY2_SHIFT)) & PUF_KEYLOCK_KEY2_MASK)

#define PUF_KEYLOCK_KEY3_MASK                    (0xC0U)
#define PUF_KEYLOCK_KEY3_SHIFT                   (6U)
/*! KEY3 - Key 3
 *  0b00, 0b01, 0b11..Write access to KEY3MASK, KEYENABLE[KEY3] and KEYRESET[KEY3] is NOT allowed.
 *  0b10..Write access to KEY3MASK, KEYENABLE[KEY3] and KEYRESET[KEY3] is allowed.
 */
#define PUF_KEYLOCK_KEY3(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_KEYLOCK_KEY3_SHIFT)) & PUF_KEYLOCK_KEY3_MASK)
/*! @} */

/*! @name KEYENABLE - Key Enable */
/*! @{ */

#define PUF_KEYENABLE_KEY0_MASK                  (0x3U)
#define PUF_KEYENABLE_KEY0_SHIFT                 (0U)
/*! KEY0 - Key 0
 *  0b00, 0b01, 0b11..Data coming from the PUF Index 0 interface are NOT shifted in the KEY0 register.
 *  0b10..Data coming from the PUF Index 0 interface are shifted in the KEY0 register.
 */
#define PUF_KEYENABLE_KEY0(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYENABLE_KEY0_SHIFT)) & PUF_KEYENABLE_KEY0_MASK)

#define PUF_KEYENABLE_KEY1_MASK                  (0xCU)
#define PUF_KEYENABLE_KEY1_SHIFT                 (2U)
/*! KEY1 - Key 1
 *  0b00, 0b01, 0b11..Data coming from the PUF Index 0 interface are NOT shifted in the KEY1 register.
 *  0b10..Data coming from the PUF Index 0 interface are shifted in the KEY1 register.
 */
#define PUF_KEYENABLE_KEY1(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYENABLE_KEY1_SHIFT)) & PUF_KEYENABLE_KEY1_MASK)

#define PUF_KEYENABLE_KEY2_MASK                  (0x30U)
#define PUF_KEYENABLE_KEY2_SHIFT                 (4U)
/*! KEY2 - Key 2
 *  0b00, 0b01, 0b11..Data coming from the PUF Index 0 interface are NOT shifted in the KEY2 register.
 *  0b10..Data coming from the PUF Index 0 interface are shifted in the KEY2 register.
 */
#define PUF_KEYENABLE_KEY2(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYENABLE_KEY2_SHIFT)) & PUF_KEYENABLE_KEY2_MASK)

#define PUF_KEYENABLE_KEY3_MASK                  (0xC0U)
#define PUF_KEYENABLE_KEY3_SHIFT                 (6U)
/*! KEY3 - Key 3
 *  0b00, 0b01, 0b11..Data coming from the PUF Index 0 interface are NOT shifted in the KEY3 register.
 *  0b10..Data coming from the PUF Index 0 interface are shifted in the KEY3 register.
 */
#define PUF_KEYENABLE_KEY3(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_KEYENABLE_KEY3_SHIFT)) & PUF_KEYENABLE_KEY3_MASK)
/*! @} */

/*! @name KEYRESET - Key Reset */
/*! @{ */

#define PUF_KEYRESET_KEY0_MASK                   (0x3U)
#define PUF_KEYRESET_KEY0_SHIFT                  (0U)
/*! KEY0 - Key 0
 *  0b10..Reset KEY0 Hold register and SHIFT_STATUS[KEY0].
 */
#define PUF_KEYRESET_KEY0(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_KEYRESET_KEY0_SHIFT)) & PUF_KEYRESET_KEY0_MASK)

#define PUF_KEYRESET_KEY1_MASK                   (0xCU)
#define PUF_KEYRESET_KEY1_SHIFT                  (2U)
/*! KEY1 - Key 1
 *  0b10..Reset KEY1 Hold register and SHIFT_STATUS[KEY1].
 */
#define PUF_KEYRESET_KEY1(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_KEYRESET_KEY1_SHIFT)) & PUF_KEYRESET_KEY1_MASK)

#define PUF_KEYRESET_KEY2_MASK                   (0x30U)
#define PUF_KEYRESET_KEY2_SHIFT                  (4U)
/*! KEY2 - Key 2
 *  0b10..Reset KEY2 Hold register and SHIFT_STATUS[KEY2].
 */
#define PUF_KEYRESET_KEY2(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_KEYRESET_KEY2_SHIFT)) & PUF_KEYRESET_KEY2_MASK)

#define PUF_KEYRESET_KEY3_MASK                   (0xC0U)
#define PUF_KEYRESET_KEY3_SHIFT                  (6U)
/*! KEY3 - Key 3
 *  0b10..Reset KEY3 Hold register and SHIFT_STATUS[KEY3].
 */
#define PUF_KEYRESET_KEY3(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_KEYRESET_KEY3_SHIFT)) & PUF_KEYRESET_KEY3_MASK)
/*! @} */

/*! @name IDXBLK_L - Index Block Low */
/*! @{ */

#define PUF_IDXBLK_L_IDX1_MASK                   (0xCU)
#define PUF_IDXBLK_L_IDX1_SHIFT                  (2U)
/*! IDX1 - Index 1 */
#define PUF_IDXBLK_L_IDX1(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX1_SHIFT)) & PUF_IDXBLK_L_IDX1_MASK)

#define PUF_IDXBLK_L_IDX2_MASK                   (0x30U)
#define PUF_IDXBLK_L_IDX2_SHIFT                  (4U)
/*! IDX2 - Index 2 */
#define PUF_IDXBLK_L_IDX2(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX2_SHIFT)) & PUF_IDXBLK_L_IDX2_MASK)

#define PUF_IDXBLK_L_IDX3_MASK                   (0xC0U)
#define PUF_IDXBLK_L_IDX3_SHIFT                  (6U)
/*! IDX3 - Index 3 */
#define PUF_IDXBLK_L_IDX3(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX3_SHIFT)) & PUF_IDXBLK_L_IDX3_MASK)

#define PUF_IDXBLK_L_IDX4_MASK                   (0x300U)
#define PUF_IDXBLK_L_IDX4_SHIFT                  (8U)
/*! IDX4 - Index 4 */
#define PUF_IDXBLK_L_IDX4(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX4_SHIFT)) & PUF_IDXBLK_L_IDX4_MASK)

#define PUF_IDXBLK_L_IDX5_MASK                   (0xC00U)
#define PUF_IDXBLK_L_IDX5_SHIFT                  (10U)
/*! IDX5 - Index 5 */
#define PUF_IDXBLK_L_IDX5(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX5_SHIFT)) & PUF_IDXBLK_L_IDX5_MASK)

#define PUF_IDXBLK_L_IDX6_MASK                   (0x3000U)
#define PUF_IDXBLK_L_IDX6_SHIFT                  (12U)
/*! IDX6 - Index 6 */
#define PUF_IDXBLK_L_IDX6(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX6_SHIFT)) & PUF_IDXBLK_L_IDX6_MASK)

#define PUF_IDXBLK_L_IDX7_MASK                   (0xC000U)
#define PUF_IDXBLK_L_IDX7_SHIFT                  (14U)
/*! IDX7 - Index 7 */
#define PUF_IDXBLK_L_IDX7(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_IDX7_SHIFT)) & PUF_IDXBLK_L_IDX7_MASK)

#define PUF_IDXBLK_L_LOCK_IDX_MASK               (0xC0000000U)
#define PUF_IDXBLK_L_LOCK_IDX_SHIFT              (30U)
/*! LOCK_IDX - Lock Index */
#define PUF_IDXBLK_L_LOCK_IDX(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_LOCK_IDX_SHIFT)) & PUF_IDXBLK_L_LOCK_IDX_MASK)
/*! @} */

/*! @name IDXBLK_H_DP - Index Block High Duplicate */
/*! @{ */

#define PUF_IDXBLK_H_DP_IDX8_MASK                (0x3U)
#define PUF_IDXBLK_H_DP_IDX8_SHIFT               (0U)
/*! IDX8 - Index 8 */
#define PUF_IDXBLK_H_DP_IDX8(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX8_SHIFT)) & PUF_IDXBLK_H_DP_IDX8_MASK)

#define PUF_IDXBLK_H_DP_IDX9_MASK                (0xCU)
#define PUF_IDXBLK_H_DP_IDX9_SHIFT               (2U)
/*! IDX9 - Index 9 */
#define PUF_IDXBLK_H_DP_IDX9(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX9_SHIFT)) & PUF_IDXBLK_H_DP_IDX9_MASK)

#define PUF_IDXBLK_H_DP_IDX10_MASK               (0x30U)
#define PUF_IDXBLK_H_DP_IDX10_SHIFT              (4U)
/*! IDX10 - Index 10 */
#define PUF_IDXBLK_H_DP_IDX10(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX10_SHIFT)) & PUF_IDXBLK_H_DP_IDX10_MASK)

#define PUF_IDXBLK_H_DP_IDX11_MASK               (0xC0U)
#define PUF_IDXBLK_H_DP_IDX11_SHIFT              (6U)
/*! IDX11 - Index 11 */
#define PUF_IDXBLK_H_DP_IDX11(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX11_SHIFT)) & PUF_IDXBLK_H_DP_IDX11_MASK)

#define PUF_IDXBLK_H_DP_IDX12_MASK               (0x300U)
#define PUF_IDXBLK_H_DP_IDX12_SHIFT              (8U)
/*! IDX12 - Index 12 */
#define PUF_IDXBLK_H_DP_IDX12(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX12_SHIFT)) & PUF_IDXBLK_H_DP_IDX12_MASK)

#define PUF_IDXBLK_H_DP_IDX13_MASK               (0xC00U)
#define PUF_IDXBLK_H_DP_IDX13_SHIFT              (10U)
/*! IDX13 - Index 13 */
#define PUF_IDXBLK_H_DP_IDX13(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX13_SHIFT)) & PUF_IDXBLK_H_DP_IDX13_MASK)

#define PUF_IDXBLK_H_DP_IDX14_MASK               (0x3000U)
#define PUF_IDXBLK_H_DP_IDX14_SHIFT              (12U)
/*! IDX14 - Index 14 */
#define PUF_IDXBLK_H_DP_IDX14(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX14_SHIFT)) & PUF_IDXBLK_H_DP_IDX14_MASK)

#define PUF_IDXBLK_H_DP_IDX15_MASK               (0xC000U)
#define PUF_IDXBLK_H_DP_IDX15_SHIFT              (14U)
/*! IDX15 - Index 15 */
#define PUF_IDXBLK_H_DP_IDX15(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_DP_IDX15_SHIFT)) & PUF_IDXBLK_H_DP_IDX15_MASK)
/*! @} */

/*! @name KEYMASK - Key Mask 0..Key Mask 1 */
/*! @{ */

#define PUF_KEYMASK_KEYMASK_MASK                 (0xFFFFFFFFU)
#define PUF_KEYMASK_KEYMASK_SHIFT                (0U)
/*! KEYMASK - Key a Mask */
#define PUF_KEYMASK_KEYMASK(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_KEYMASK_KEYMASK_SHIFT)) & PUF_KEYMASK_KEYMASK_MASK)
/*! @} */

/*! @name IDXBLK_H - Index Block High */
/*! @{ */

#define PUF_IDXBLK_H_IDX8_MASK                   (0x3U)
#define PUF_IDXBLK_H_IDX8_SHIFT                  (0U)
/*! IDX8 - Index 8 */
#define PUF_IDXBLK_H_IDX8(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX8_SHIFT)) & PUF_IDXBLK_H_IDX8_MASK)

#define PUF_IDXBLK_H_IDX9_MASK                   (0xCU)
#define PUF_IDXBLK_H_IDX9_SHIFT                  (2U)
/*! IDX9 - Index 9 */
#define PUF_IDXBLK_H_IDX9(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX9_SHIFT)) & PUF_IDXBLK_H_IDX9_MASK)

#define PUF_IDXBLK_H_IDX10_MASK                  (0x30U)
#define PUF_IDXBLK_H_IDX10_SHIFT                 (4U)
/*! IDX10 - Index 10 */
#define PUF_IDXBLK_H_IDX10(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX10_SHIFT)) & PUF_IDXBLK_H_IDX10_MASK)

#define PUF_IDXBLK_H_IDX11_MASK                  (0xC0U)
#define PUF_IDXBLK_H_IDX11_SHIFT                 (6U)
/*! IDX11 - Index 11 */
#define PUF_IDXBLK_H_IDX11(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX11_SHIFT)) & PUF_IDXBLK_H_IDX11_MASK)

#define PUF_IDXBLK_H_IDX12_MASK                  (0x300U)
#define PUF_IDXBLK_H_IDX12_SHIFT                 (8U)
/*! IDX12 - Index 12 */
#define PUF_IDXBLK_H_IDX12(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX12_SHIFT)) & PUF_IDXBLK_H_IDX12_MASK)

#define PUF_IDXBLK_H_IDX13_MASK                  (0xC00U)
#define PUF_IDXBLK_H_IDX13_SHIFT                 (10U)
/*! IDX13 - Index 13 */
#define PUF_IDXBLK_H_IDX13(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX13_SHIFT)) & PUF_IDXBLK_H_IDX13_MASK)

#define PUF_IDXBLK_H_IDX14_MASK                  (0x3000U)
#define PUF_IDXBLK_H_IDX14_SHIFT                 (12U)
/*! IDX14 - Index 14 */
#define PUF_IDXBLK_H_IDX14(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX14_SHIFT)) & PUF_IDXBLK_H_IDX14_MASK)

#define PUF_IDXBLK_H_IDX15_MASK                  (0xC000U)
#define PUF_IDXBLK_H_IDX15_SHIFT                 (14U)
/*! IDX15 - Index 15 */
#define PUF_IDXBLK_H_IDX15(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_IDX15_SHIFT)) & PUF_IDXBLK_H_IDX15_MASK)

#define PUF_IDXBLK_H_LOCK_IDX_MASK               (0xC0000000U)
#define PUF_IDXBLK_H_LOCK_IDX_SHIFT              (30U)
/*! LOCK_IDX - Lock Index */
#define PUF_IDXBLK_H_LOCK_IDX(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_H_LOCK_IDX_SHIFT)) & PUF_IDXBLK_H_LOCK_IDX_MASK)
/*! @} */

/*! @name IDXBLK_L_DP - Index Block Low Duplicate */
/*! @{ */

#define PUF_IDXBLK_L_DP_IDX0_MASK                (0x3U)
#define PUF_IDXBLK_L_DP_IDX0_SHIFT               (0U)
/*! IDX0 - Index 0 */
#define PUF_IDXBLK_L_DP_IDX0(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX0_SHIFT)) & PUF_IDXBLK_L_DP_IDX0_MASK)

#define PUF_IDXBLK_L_DP_IDX1_MASK                (0xCU)
#define PUF_IDXBLK_L_DP_IDX1_SHIFT               (2U)
/*! IDX1 - Index 1 */
#define PUF_IDXBLK_L_DP_IDX1(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX1_SHIFT)) & PUF_IDXBLK_L_DP_IDX1_MASK)

#define PUF_IDXBLK_L_DP_IDX2_MASK                (0x30U)
#define PUF_IDXBLK_L_DP_IDX2_SHIFT               (4U)
/*! IDX2 - Index 2 */
#define PUF_IDXBLK_L_DP_IDX2(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX2_SHIFT)) & PUF_IDXBLK_L_DP_IDX2_MASK)

#define PUF_IDXBLK_L_DP_IDX3_MASK                (0xC0U)
#define PUF_IDXBLK_L_DP_IDX3_SHIFT               (6U)
/*! IDX3 - Index 3 */
#define PUF_IDXBLK_L_DP_IDX3(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX3_SHIFT)) & PUF_IDXBLK_L_DP_IDX3_MASK)

#define PUF_IDXBLK_L_DP_IDX4_MASK                (0x300U)
#define PUF_IDXBLK_L_DP_IDX4_SHIFT               (8U)
/*! IDX4 - Index 4 */
#define PUF_IDXBLK_L_DP_IDX4(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX4_SHIFT)) & PUF_IDXBLK_L_DP_IDX4_MASK)

#define PUF_IDXBLK_L_DP_IDX5_MASK                (0xC00U)
#define PUF_IDXBLK_L_DP_IDX5_SHIFT               (10U)
/*! IDX5 - Index 5 */
#define PUF_IDXBLK_L_DP_IDX5(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX5_SHIFT)) & PUF_IDXBLK_L_DP_IDX5_MASK)

#define PUF_IDXBLK_L_DP_IDX6_MASK                (0x3000U)
#define PUF_IDXBLK_L_DP_IDX6_SHIFT               (12U)
/*! IDX6 - Index 6 */
#define PUF_IDXBLK_L_DP_IDX6(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX6_SHIFT)) & PUF_IDXBLK_L_DP_IDX6_MASK)

#define PUF_IDXBLK_L_DP_IDX7_MASK                (0xC000U)
#define PUF_IDXBLK_L_DP_IDX7_SHIFT               (14U)
/*! IDX7 - Index 7 */
#define PUF_IDXBLK_L_DP_IDX7(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IDXBLK_L_DP_IDX7_SHIFT)) & PUF_IDXBLK_L_DP_IDX7_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_PUF_H_ */

