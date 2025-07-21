/*
** ###################################################################
**     Processors:          MCXC143VFM
**                          MCXC143VFT
**                          MCXC144VFM
**                          MCXC144VFT
**                          MCXC243VFT
**                          MCXC244VFM
**                          MCXC244VFT
**                          MCXC443VLH
**                          MCXC443VMP
**                          MCXC444VLH
**                          MCXC444VMP
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NV
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-03-11)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NV.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NV
 *
 * CMSIS Peripheral Access Layer for NV
 */

#if !defined(PERI_NV_H_)
#define PERI_NV_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC143VFM) || defined(CPU_MCXC143VFT))
#include "MCXC143_COMMON.h"
#elif (defined(CPU_MCXC144VFM) || defined(CPU_MCXC144VFT))
#include "MCXC144_COMMON.h"
#elif (defined(CPU_MCXC243VFT))
#include "MCXC243_COMMON.h"
#elif (defined(CPU_MCXC244VFM) || defined(CPU_MCXC244VFT))
#include "MCXC244_COMMON.h"
#elif (defined(CPU_MCXC443VLH) || defined(CPU_MCXC443VMP))
#include "MCXC443_COMMON.h"
#elif (defined(CPU_MCXC444VLH) || defined(CPU_MCXC444VMP))
#include "MCXC444_COMMON.h"
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
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3., offset: 0x0 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2., offset: 0x1 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1., offset: 0x2 */
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0., offset: 0x3 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7., offset: 0x4 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6., offset: 0x5 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5., offset: 0x6 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4., offset: 0x7 */
  __I  uint8_t FPROT3;                             /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  __I  uint8_t FPROT2;                             /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  __I  uint8_t FPROT1;                             /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  __I  uint8_t FPROT0;                             /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xC */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xD */
} NV_Type;

/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/*! @name BACKKEY3 - Backdoor Comparison Key 3. */
/*! @{ */

#define NV_BACKKEY3_KEY_MASK                     (0xFFU)
#define NV_BACKKEY3_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY3_KEY_SHIFT)) & NV_BACKKEY3_KEY_MASK)
/*! @} */

/*! @name BACKKEY2 - Backdoor Comparison Key 2. */
/*! @{ */

#define NV_BACKKEY2_KEY_MASK                     (0xFFU)
#define NV_BACKKEY2_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY2_KEY_SHIFT)) & NV_BACKKEY2_KEY_MASK)
/*! @} */

/*! @name BACKKEY1 - Backdoor Comparison Key 1. */
/*! @{ */

#define NV_BACKKEY1_KEY_MASK                     (0xFFU)
#define NV_BACKKEY1_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY1_KEY_SHIFT)) & NV_BACKKEY1_KEY_MASK)
/*! @} */

/*! @name BACKKEY0 - Backdoor Comparison Key 0. */
/*! @{ */

#define NV_BACKKEY0_KEY_MASK                     (0xFFU)
#define NV_BACKKEY0_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY0_KEY_SHIFT)) & NV_BACKKEY0_KEY_MASK)
/*! @} */

/*! @name BACKKEY7 - Backdoor Comparison Key 7. */
/*! @{ */

#define NV_BACKKEY7_KEY_MASK                     (0xFFU)
#define NV_BACKKEY7_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY7_KEY_SHIFT)) & NV_BACKKEY7_KEY_MASK)
/*! @} */

/*! @name BACKKEY6 - Backdoor Comparison Key 6. */
/*! @{ */

#define NV_BACKKEY6_KEY_MASK                     (0xFFU)
#define NV_BACKKEY6_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY6_KEY_SHIFT)) & NV_BACKKEY6_KEY_MASK)
/*! @} */

/*! @name BACKKEY5 - Backdoor Comparison Key 5. */
/*! @{ */

#define NV_BACKKEY5_KEY_MASK                     (0xFFU)
#define NV_BACKKEY5_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY5_KEY_SHIFT)) & NV_BACKKEY5_KEY_MASK)
/*! @} */

/*! @name BACKKEY4 - Backdoor Comparison Key 4. */
/*! @{ */

#define NV_BACKKEY4_KEY_MASK                     (0xFFU)
#define NV_BACKKEY4_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY4_KEY_SHIFT)) & NV_BACKKEY4_KEY_MASK)
/*! @} */

/*! @name FPROT3 - Non-volatile P-Flash Protection 1 - Low Register */
/*! @{ */

#define NV_FPROT3_PROT_MASK                      (0xFFU)
#define NV_FPROT3_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT3_PROT_SHIFT)) & NV_FPROT3_PROT_MASK)
/*! @} */

/*! @name FPROT2 - Non-volatile P-Flash Protection 1 - High Register */
/*! @{ */

#define NV_FPROT2_PROT_MASK                      (0xFFU)
#define NV_FPROT2_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT2_PROT_SHIFT)) & NV_FPROT2_PROT_MASK)
/*! @} */

/*! @name FPROT1 - Non-volatile P-Flash Protection 0 - Low Register */
/*! @{ */

#define NV_FPROT1_PROT_MASK                      (0xFFU)
#define NV_FPROT1_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT1_PROT_SHIFT)) & NV_FPROT1_PROT_MASK)
/*! @} */

/*! @name FPROT0 - Non-volatile P-Flash Protection 0 - High Register */
/*! @{ */

#define NV_FPROT0_PROT_MASK                      (0xFFU)
#define NV_FPROT0_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT0_PROT_SHIFT)) & NV_FPROT0_PROT_MASK)
/*! @} */

/*! @name FSEC - Non-volatile Flash Security Register */
/*! @{ */

#define NV_FSEC_SEC_MASK                         (0x3U)
#define NV_FSEC_SEC_SHIFT                        (0U)
/*! SEC - Flash Security
 *  0b10..MCU security status is unsecure
 *  0b11..MCU security status is secure
 */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x)) << NV_FSEC_SEC_SHIFT)) & NV_FSEC_SEC_MASK)

#define NV_FSEC_FSLACC_MASK                      (0xCU)
#define NV_FSEC_FSLACC_SHIFT                     (2U)
/*! FSLACC - Freescale Failure Analysis Access Code
 *  0b10..Freescale factory access denied
 *  0b11..Freescale factory access granted
 */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FSEC_FSLACC_SHIFT)) & NV_FSEC_FSLACC_MASK)

#define NV_FSEC_MEEN_MASK                        (0x30U)
#define NV_FSEC_MEEN_SHIFT                       (4U)
/*! MEEN
 *  0b10..Mass erase is disabled
 *  0b11..Mass erase is enabled
 */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x)) << NV_FSEC_MEEN_SHIFT)) & NV_FSEC_MEEN_MASK)

#define NV_FSEC_KEYEN_MASK                       (0xC0U)
#define NV_FSEC_KEYEN_SHIFT                      (6U)
/*! KEYEN - Backdoor Key Security Enable
 *  0b10..Backdoor key access enabled
 *  0b11..Backdoor key access disabled
 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x)) << NV_FSEC_KEYEN_SHIFT)) & NV_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FOPT - Non-volatile Flash Option Register */
/*! @{ */

#define NV_FOPT_LPBOOT0_MASK                     (0x1U)
#define NV_FOPT_LPBOOT0_SHIFT                    (0U)
/*! LPBOOT0
 *  0b0..Core and system clock divider (OUTDIV1) is 0x7 (divide by 8) when LPBOOT1=0 or 0x1 (divide by 2) when LPBOOT1=1.
 *  0b1..Core and system clock divider (OUTDIV1) is 0x3 (divide by 4) when LPBOOT1=0 or 0x0 (divide by 1) when LPBOOT1=1.
 */
#define NV_FOPT_LPBOOT0(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FOPT_LPBOOT0_SHIFT)) & NV_FOPT_LPBOOT0_MASK)

#define NV_FOPT_BOOTPIN_OPT_MASK                 (0x2U)
#define NV_FOPT_BOOTPIN_OPT_SHIFT                (1U)
/*! BOOTPIN_OPT
 *  0b0..Force Boot from ROM if BOOTCFG0 asserted, where BOOTCFG0 is the boot config function which is muxed with NMI pin
 *  0b1..Boot source configured by FOPT (BOOTSRC_SEL) bits
 */
#define NV_FOPT_BOOTPIN_OPT(x)                   (((uint8_t)(((uint8_t)(x)) << NV_FOPT_BOOTPIN_OPT_SHIFT)) & NV_FOPT_BOOTPIN_OPT_MASK)

#define NV_FOPT_NMI_DIS_MASK                     (0x4U)
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)
/*! NMI_DIS
 *  0b0..NMI interrupts are always blocked
 *  0b1..NMI_b pin/interrupts reset default to enabled
 */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FOPT_NMI_DIS_SHIFT)) & NV_FOPT_NMI_DIS_MASK)

#define NV_FOPT_RESET_PIN_CFG_MASK               (0x8U)
#define NV_FOPT_RESET_PIN_CFG_SHIFT              (3U)
/*! RESET_PIN_CFG
 *  0b0..RESET pin is disabled following a POR and cannot be enabled as reset function
 *  0b1..RESET_b pin is dedicated
 */
#define NV_FOPT_RESET_PIN_CFG(x)                 (((uint8_t)(((uint8_t)(x)) << NV_FOPT_RESET_PIN_CFG_SHIFT)) & NV_FOPT_RESET_PIN_CFG_MASK)

#define NV_FOPT_LPBOOT1_MASK                     (0x10U)
#define NV_FOPT_LPBOOT1_SHIFT                    (4U)
/*! LPBOOT1
 *  0b0..Core and system clock divider (OUTDIV1) is 0x7 (divide by 8) when LPBOOT0=0 or 0x3 (divide by 4) when LPBOOT0=1.
 *  0b1..Core and system clock divider (OUTDIV1) is 0x1 (divide by 2) when LPBOOT0=0 or 0x0 (divide by 1) when LPBOOT0=1.
 */
#define NV_FOPT_LPBOOT1(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FOPT_LPBOOT1_SHIFT)) & NV_FOPT_LPBOOT1_MASK)

#define NV_FOPT_FAST_INIT_MASK                   (0x20U)
#define NV_FOPT_FAST_INIT_SHIFT                  (5U)
/*! FAST_INIT
 *  0b0..Slower initialization
 *  0b1..Fast Initialization
 */
#define NV_FOPT_FAST_INIT(x)                     (((uint8_t)(((uint8_t)(x)) << NV_FOPT_FAST_INIT_SHIFT)) & NV_FOPT_FAST_INIT_MASK)

#define NV_FOPT_BOOTSRC_SEL_MASK                 (0xC0U)
#define NV_FOPT_BOOTSRC_SEL_SHIFT                (6U)
/*! BOOTSRC_SEL - Boot source selection
 *  0b00..Boot from Flash
 *  0b10..Boot from ROM
 *  0b11..Boot from ROM
 */
#define NV_FOPT_BOOTSRC_SEL(x)                   (((uint8_t)(((uint8_t)(x)) << NV_FOPT_BOOTSRC_SEL_SHIFT)) & NV_FOPT_BOOTSRC_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NV_Register_Masks */


/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


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


#endif  /* PERI_NV_H_ */

