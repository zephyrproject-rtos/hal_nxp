/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ASRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ASRC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ASRC
 *
 * CMSIS Peripheral Access Layer for ASRC
 */

#if !defined(PERI_ASRC_H_)
#define PERI_ASRC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(ASRC_CLOCK_SOURCE_T_)
#define ASRC_CLOCK_SOURCE_T_
/*!
 * @addtogroup asrc_clock_source_mapping
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The ASRC clock source
 */
typedef enum _asrc_clock_source
{
    kASRC_ClockSourceNotAvalible    = -1,          /**< not avalible */
    kASRC_ClockSourceBitClock0_SAI1_TX = 0U,       /**< SAI1 TX */
    kASRC_ClockSourceBitClock1_SAI1_RX = 1U,       /**< SAI1 RX */
    kASRC_ClockSourceBitClock2_SAI2_TX = 2U,       /**< SAI2 TX */
    kASRC_ClockSourceBitClock3_SAI2_RX = 3U,       /**< SAI2 RX */
    kASRC_ClockSourceBitClock4_SAI3_TX = 4U,       /**< SAI3 TX */
    kASRC_ClockSourceBitClock5_SAI3_RX = 5U,       /**< SAI3 RX */
    kASRC_ClockSourceBitClock6_SAI4_TX = 6U,       /**< SAI4 TX */
    kASRC_ClockSourceBitClock7_SAI4_RX = 7U,       /**< SAI4 RX */
    kASRC_ClockSourceBitClock8_SPDIF_TX = 8U,      /**< SPDIF TX */
    kASRC_ClockSourceBitClock9_SPDIF_RX = 9U,      /**< SPDIF RX */
    kASRC_ClockSourceBitClocka_SAI2_CLOCK_ROOT = 10U, /**< SAI2 CLOCK ROOT */
    kASRC_ClockSourceBitClockb_SAI3_CLOCK_ROOT = 11U, /**< SAI3 CLOCK ROOT */
    kASRC_ClockSourceBitClockc_SAI4_CLOCK_ROOT = 12U, /**< SAI4 CLOCK ROOT */
    kASRC_ClockSourceBitClockd_MIC_CLOCK_ROOT = 13U, /**< MIC CLOCK ROOT */
    kASRC_ClockSourceBitClocke_MQS_CLOCK_ROOT = 14U, /**< MQS CLOCK ROOT */
} asrc_clock_source_t;

/* @} */
#endif /* ASRC_CLOCK_SOURCE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- ASRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASRC_Peripheral_Access_Layer ASRC Peripheral Access Layer
 * @{
 */

/** ASRC - Size of Registers Arrays */
#define ASRC_ASRPM_COUNT                          5u
#define ASRC_ASRMCR1_COUNT                        3u

/** ASRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t ASRCTR;                            /**< ASRC Control, offset: 0x0 */
  __IO uint32_t ASRIER;                            /**< ASRC Interrupt Enable, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ASRCNCR;                           /**< ASRC Channel Number Configuration, offset: 0xC */
  __IO uint32_t ASRCFG;                            /**< ASRC Filter Configuration Status, offset: 0x10 */
  __IO uint32_t ASRCSR;                            /**< ASRC Clock Source, offset: 0x14 */
  __IO uint32_t ASRCDR1;                           /**< ASRC Clock Divider 1, offset: 0x18 */
  __IO uint32_t ASRCDR2;                           /**< ASRC Clock Divider 2, offset: 0x1C */
  __I  uint32_t ASRSTR;                            /**< ASRC Status, offset: 0x20 */
       uint8_t RESERVED_1[28];
  __IO uint32_t ASRPM[ASRC_ASRPM_COUNT];           /**< ASRC Parameter x, array offset: 0x40, array step: 0x4 */
  __IO uint32_t ASRTFR1;                           /**< ASRC Task Queue FIFO 1, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __IO uint32_t ASRCCR;                            /**< ASRC Channel Counter, offset: 0x5C */
  __O  uint32_t ASRDIA;                            /**< ASRC Data Input for Pair x, offset: 0x60 */
  __I  uint32_t ASRDOA;                            /**< ASRC Data Output for Pair x, offset: 0x64 */
  __O  uint32_t ASRDIB;                            /**< ASRC Data Input for Pair x, offset: 0x68 */
  __I  uint32_t ASRDOB;                            /**< ASRC Data Output for Pair x, offset: 0x6C */
  __O  uint32_t ASRDIC;                            /**< ASRC Data Input for Pair x, offset: 0x70 */
  __I  uint32_t ASRDOC;                            /**< ASRC Data Output for Pair x, offset: 0x74 */
       uint8_t RESERVED_3[8];
  __IO uint32_t ASRIDRHA;                          /**< ASRC Ideal Ratio for Pair A-High Part, offset: 0x80 */
  __IO uint32_t ASRIDRLA;                          /**< ASRC Ideal Ratio for Pair A -Low Part, offset: 0x84 */
  __IO uint32_t ASRIDRHB;                          /**< ASRC Ideal Ratio for Pair B-High Part, offset: 0x88 */
  __IO uint32_t ASRIDRLB;                          /**< ASRC Ideal Ratio for Pair B-Low Part, offset: 0x8C */
  __IO uint32_t ASRIDRHC;                          /**< ASRC Ideal Ratio for Pair C-High Part, offset: 0x90 */
  __IO uint32_t ASRIDRLC;                          /**< ASRC Ideal Ratio for Pair C-Low Part, offset: 0x94 */
  __IO uint32_t ASR76K;                            /**< ASRC 76 kHz Period, offset: 0x98 */
  __IO uint32_t ASR56K;                            /**< ASRC 56 kHz Period, offset: 0x9C */
  __IO uint32_t ASRMCRA;                           /**< ASRC Misc Control for Pair A, offset: 0xA0 */
  __I  uint32_t ASRFSTA;                           /**< ASRC FIFO Status for Pair A, offset: 0xA4 */
  __IO uint32_t ASRMCRB;                           /**< ASRC Misc Control for Pair B, offset: 0xA8 */
  __I  uint32_t ASRFSTB;                           /**< ASRC FIFO Status for Pair B, offset: 0xAC */
  __IO uint32_t ASRMCRC;                           /**< ASRC Misc Control for Pair C, offset: 0xB0 */
  __I  uint32_t ASRFSTC;                           /**< ASRC FIFO Status for Pair C, offset: 0xB4 */
       uint8_t RESERVED_4[8];
  __IO uint32_t ASRMCR1[ASRC_ASRMCR1_COUNT];       /**< ASRC Misc Control 1 for Pair X, array offset: 0xC0, array step: 0x4 */
} ASRC_Type;

/* ----------------------------------------------------------------------------
   -- ASRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASRC_Register_Masks ASRC Register Masks
 * @{
 */

/*! @name ASRCTR - ASRC Control */
/*! @{ */

#define ASRC_ASRCTR_ASRCEN_MASK                  (0x1U)
#define ASRC_ASRCTR_ASRCEN_SHIFT                 (0U)
/*! ASRCEN - ASRC Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRCTR_ASRCEN(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ASRCEN_SHIFT)) & ASRC_ASRCTR_ASRCEN_MASK)

#define ASRC_ASRCTR_ASREA_MASK                   (0x2U)
#define ASRC_ASRCTR_ASREA_SHIFT                  (1U)
/*! ASREA - ASRC Enable A
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRCTR_ASREA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ASREA_SHIFT)) & ASRC_ASRCTR_ASREA_MASK)

#define ASRC_ASRCTR_ASREB_MASK                   (0x4U)
#define ASRC_ASRCTR_ASREB_SHIFT                  (2U)
/*! ASREB - ASRC Enable B
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRCTR_ASREB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ASREB_SHIFT)) & ASRC_ASRCTR_ASREB_MASK)

#define ASRC_ASRCTR_ASREC_MASK                   (0x8U)
#define ASRC_ASRCTR_ASREC_SHIFT                  (3U)
/*! ASREC - ASRC Enable C
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRCTR_ASREC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ASREC_SHIFT)) & ASRC_ASRCTR_ASREC_MASK)

#define ASRC_ASRCTR_SRST_MASK                    (0x10U)
#define ASRC_ASRCTR_SRST_SHIFT                   (4U)
/*! SRST - Software Reset
 *  0b0..ASRC Software reset cleared
 *  0b1..ASRC Software reset generated. NOTE: This is a self-clear bit
 */
#define ASRC_ASRCTR_SRST(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_SRST_SHIFT)) & ASRC_ASRCTR_SRST_MASK)

#define ASRC_ASRCTR_IDRA_MASK                    (0x2000U)
#define ASRC_ASRCTR_IDRA_SHIFT                   (13U)
/*! IDRA - Use Ideal Ratio for Pair A
 *  0b0..ASRC internal measured ratio is used
 *  0b1..Ideal ratio from the interface register ASRIDRHA, ASRIDRLA is used
 */
#define ASRC_ASRCTR_IDRA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_IDRA_SHIFT)) & ASRC_ASRCTR_IDRA_MASK)

#define ASRC_ASRCTR_USRA_MASK                    (0x4000U)
#define ASRC_ASRCTR_USRA_SHIFT                   (14U)
/*! USRA - Use Ratio for Pair A
 *  0b0..Do not use ratio as the input to ASRC for pair A
 *  0b1..Use ratio as the input to ASRC for pair A
 */
#define ASRC_ASRCTR_USRA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_USRA_SHIFT)) & ASRC_ASRCTR_USRA_MASK)

#define ASRC_ASRCTR_IDRB_MASK                    (0x8000U)
#define ASRC_ASRCTR_IDRB_SHIFT                   (15U)
/*! IDRB - Use Ideal Ratio for Pair B
 *  0b0..ASRC internal measured ratio is used
 *  0b1..Ideal ratio from the interface register ASRIDRHB, ASRIDRLB is used
 */
#define ASRC_ASRCTR_IDRB(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_IDRB_SHIFT)) & ASRC_ASRCTR_IDRB_MASK)

#define ASRC_ASRCTR_USRB_MASK                    (0x10000U)
#define ASRC_ASRCTR_USRB_SHIFT                   (16U)
/*! USRB - Use Ratio for Pair B
 *  0b0..Do not use ratio as the input to ASRC for pair B
 *  0b1..Use ratio as the input to ASRC for pair B
 */
#define ASRC_ASRCTR_USRB(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_USRB_SHIFT)) & ASRC_ASRCTR_USRB_MASK)

#define ASRC_ASRCTR_IDRC_MASK                    (0x20000U)
#define ASRC_ASRCTR_IDRC_SHIFT                   (17U)
/*! IDRC - Use Ideal Ratio for Pair C
 *  0b0..ASRC internal measured ratio is used
 *  0b1..Ideal ratio from the interface register ASRIDRHC, ASRIDRLC is used
 */
#define ASRC_ASRCTR_IDRC(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_IDRC_SHIFT)) & ASRC_ASRCTR_IDRC_MASK)

#define ASRC_ASRCTR_USRC_MASK                    (0x40000U)
#define ASRC_ASRCTR_USRC_SHIFT                   (18U)
/*! USRC - Use Ratio for Pair C
 *  0b0..Do not use ratio as the input to ASRC for pair C
 *  0b1..Use ratio as the input to ASRC for pair C
 */
#define ASRC_ASRCTR_USRC(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_USRC_SHIFT)) & ASRC_ASRCTR_USRC_MASK)

#define ASRC_ASRCTR_ATSA_MASK                    (0x100000U)
#define ASRC_ASRCTR_ATSA_SHIFT                   (20U)
/*! ATSA - ASRC Pair A Automatic Selection For Processing Options
 *  0b0..Pair A does not automatically update its pre-processing and post-processing options
 *  0b1..Pair A automatically updates its pre-processing and post-processing options
 */
#define ASRC_ASRCTR_ATSA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ATSA_SHIFT)) & ASRC_ASRCTR_ATSA_MASK)

#define ASRC_ASRCTR_ATSB_MASK                    (0x200000U)
#define ASRC_ASRCTR_ATSB_SHIFT                   (21U)
/*! ATSB - ASRC Pair B Automatic Selection For Processing Options
 *  0b0..Pair B does not automatically update its pre-processing and post-processing options
 *  0b1..Pair B automatically updates its pre-processing and post-processing options
 */
#define ASRC_ASRCTR_ATSB(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ATSB_SHIFT)) & ASRC_ASRCTR_ATSB_MASK)

#define ASRC_ASRCTR_ATSC_MASK                    (0x400000U)
#define ASRC_ASRCTR_ATSC_SHIFT                   (22U)
/*! ATSC - ASRC Pair C Automatic Selection For Processing Options
 *  0b0..Pair C does not automatically update its pre-processing and post-processing options
 *  0b1..Pair C automatically updates its pre-processing and post-processing options
 */
#define ASRC_ASRCTR_ATSC(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCTR_ATSC_SHIFT)) & ASRC_ASRCTR_ATSC_MASK)
/*! @} */

/*! @name ASRIER - ASRC Interrupt Enable */
/*! @{ */

#define ASRC_ASRIER_ADIEA_MASK                   (0x1U)
#define ASRC_ASRIER_ADIEA_SHIFT                  (0U)
/*! ADIEA - Pair A Data Input Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADIEA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADIEA_SHIFT)) & ASRC_ASRIER_ADIEA_MASK)

#define ASRC_ASRIER_ADIEB_MASK                   (0x2U)
#define ASRC_ASRIER_ADIEB_SHIFT                  (1U)
/*! ADIEB - Pair B Data Input Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADIEB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADIEB_SHIFT)) & ASRC_ASRIER_ADIEB_MASK)

#define ASRC_ASRIER_ADIEC_MASK                   (0x4U)
#define ASRC_ASRIER_ADIEC_SHIFT                  (2U)
/*! ADIEC - Pair C Data Input Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADIEC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADIEC_SHIFT)) & ASRC_ASRIER_ADIEC_MASK)

#define ASRC_ASRIER_ADOEA_MASK                   (0x8U)
#define ASRC_ASRIER_ADOEA_SHIFT                  (3U)
/*! ADOEA - Pair A Data Output Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADOEA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADOEA_SHIFT)) & ASRC_ASRIER_ADOEA_MASK)

#define ASRC_ASRIER_ADOEB_MASK                   (0x10U)
#define ASRC_ASRIER_ADOEB_SHIFT                  (4U)
/*! ADOEB - Pair B Data Output Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADOEB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADOEB_SHIFT)) & ASRC_ASRIER_ADOEB_MASK)

#define ASRC_ASRIER_ADOEC_MASK                   (0x20U)
#define ASRC_ASRIER_ADOEC_SHIFT                  (5U)
/*! ADOEC - Pair C Data Output Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_ADOEC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_ADOEC_SHIFT)) & ASRC_ASRIER_ADOEC_MASK)

#define ASRC_ASRIER_AOLIE_MASK                   (0x40U)
#define ASRC_ASRIER_AOLIE_SHIFT                  (6U)
/*! AOLIE - Overload Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_AOLIE(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_AOLIE_SHIFT)) & ASRC_ASRIER_AOLIE_MASK)

#define ASRC_ASRIER_AFPWE_MASK                   (0x80U)
#define ASRC_ASRIER_AFPWE_SHIFT                  (7U)
/*! AFPWE - FP in Wait State Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ASRC_ASRIER_AFPWE(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIER_AFPWE_SHIFT)) & ASRC_ASRIER_AFPWE_MASK)
/*! @} */

/*! @name ASRCNCR - ASRC Channel Number Configuration */
/*! @{ */

#define ASRC_ASRCNCR_ANCA_MASK                   (0xFU)
#define ASRC_ASRCNCR_ANCA_SHIFT                  (0U)
/*! ANCA - Number of A Channels
 *  0b0000..0 channels in A (Pair A is disabled)
 *  0b0001..1 channel in A
 *  0b0010..2 channels in A
 *  0b0011..3 channels in A
 *  0b0100..4 channels in A
 *  0b0101..5 channels in A
 *  0b0110..6 channels in A
 *  0b0111..7 channels in A
 *  0b1000..8 channels in A
 *  0b1001..9 channels in A
 *  0b1010..10 channels in A
 *  0b1011-0b1111..Should not be used.
 */
#define ASRC_ASRCNCR_ANCA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCNCR_ANCA_SHIFT)) & ASRC_ASRCNCR_ANCA_MASK)

#define ASRC_ASRCNCR_ANCB_MASK                   (0xF0U)
#define ASRC_ASRCNCR_ANCB_SHIFT                  (4U)
/*! ANCB - Number of B Channels
 *  0b0000..0 channels in B (Pair B is disabled)
 *  0b0001..1 channel in B
 *  0b0010..2 channels in B
 *  0b0011..3 channels in B
 *  0b0100..4 channels in B
 *  0b0101..5 channels in B
 *  0b0110..6 channels in B
 *  0b0111..7 channels in B
 *  0b1000..8 channels in B
 *  0b1001..9 channels in B
 *  0b1010..10 channels in B
 *  0b1011-0b1111..Should not be used.
 */
#define ASRC_ASRCNCR_ANCB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCNCR_ANCB_SHIFT)) & ASRC_ASRCNCR_ANCB_MASK)

#define ASRC_ASRCNCR_ANCC_MASK                   (0xF00U)
#define ASRC_ASRCNCR_ANCC_SHIFT                  (8U)
/*! ANCC - Number of C Channels
 *  0b0000..0 channels in C (Pair C is disabled)
 *  0b0001..1 channel in C
 *  0b0010..2 channels in C
 *  0b0011..3 channels in C
 *  0b0100..4 channels in C
 *  0b0101..5 channels in C
 *  0b0110..6 channels in C
 *  0b0111..7 channels in C
 *  0b1000..8 channels in C
 *  0b1001..9 channels in C
 *  0b1010..10 channels in C
 *  0b1011-0b1111..Should not be used.
 */
#define ASRC_ASRCNCR_ANCC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCNCR_ANCC_SHIFT)) & ASRC_ASRCNCR_ANCC_MASK)
/*! @} */

/*! @name ASRCFG - ASRC Filter Configuration Status */
/*! @{ */

#define ASRC_ASRCFG_PREMODA_MASK                 (0xC0U)
#define ASRC_ASRCFG_PREMODA_SHIFT                (6U)
/*! PREMODA - Pre-Processing Configuration for Conversion Pair A
 *  0b00..Select Upsampling-by-2
 *  0b01..Select Direct-Connection
 *  0b10..Select Downsampling-by-2
 *  0b11..Select passthrough mode. In this case, POSTMODA[1:0] have no use.
 */
#define ASRC_ASRCFG_PREMODA(x)                   (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_PREMODA_SHIFT)) & ASRC_ASRCFG_PREMODA_MASK)

#define ASRC_ASRCFG_POSTMODA_MASK                (0x300U)
#define ASRC_ASRCFG_POSTMODA_SHIFT               (8U)
/*! POSTMODA - Post-Processing Configuration for Conversion Pair A
 *  0b00..Select Upsampling-by-2
 *  0b01..Select Direct-Connection
 *  0b10..Select Downsampling-by-2
 *  0b11..Reserved.
 */
#define ASRC_ASRCFG_POSTMODA(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_POSTMODA_SHIFT)) & ASRC_ASRCFG_POSTMODA_MASK)

#define ASRC_ASRCFG_PREMODB_MASK                 (0xC00U)
#define ASRC_ASRCFG_PREMODB_SHIFT                (10U)
/*! PREMODB - Pre-Processing Configuration for Conversion Pair B
 *  0b00..Select Upsampling-by-2
 *  0b01..Select Direct-Connection
 *  0b10..Select Downsampling-by-2
 *  0b11..Select passthrough mode. In this case, POSTMODB[1:0] have no use.
 */
#define ASRC_ASRCFG_PREMODB(x)                   (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_PREMODB_SHIFT)) & ASRC_ASRCFG_PREMODB_MASK)

#define ASRC_ASRCFG_POSTMODB_MASK                (0x3000U)
#define ASRC_ASRCFG_POSTMODB_SHIFT               (12U)
/*! POSTMODB - Post-Processing Configuration for Conversion Pair B
 *  0b00..Select Upsampling-by-2
 *  0b01..Select Direct-Connection
 *  0b10..Select Downsampling-by-2
 *  0b11..Reserved.
 */
#define ASRC_ASRCFG_POSTMODB(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_POSTMODB_SHIFT)) & ASRC_ASRCFG_POSTMODB_MASK)

#define ASRC_ASRCFG_PREMODC_MASK                 (0xC000U)
#define ASRC_ASRCFG_PREMODC_SHIFT                (14U)
/*! PREMODC - Pre-Processing Configuration for Conversion Pair C
 *  0b00..Select Upsampling-by-2
 *  0b01..Select Direct-Connection
 *  0b10..Select Downsampling-by-2
 *  0b11..Select passthrough mode. In this case, POSTMODC[1:0] have no use.
 */
#define ASRC_ASRCFG_PREMODC(x)                   (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_PREMODC_SHIFT)) & ASRC_ASRCFG_PREMODC_MASK)

#define ASRC_ASRCFG_POSTMODC_MASK                (0x30000U)
#define ASRC_ASRCFG_POSTMODC_SHIFT               (16U)
/*! POSTMODC - Post-Processing Configuration for Conversion Pair C
 *  0b00..Select Upsampling-by-2 as defined in Signal Processing Flow.
 *  0b01..Select Direct-Connection as defined in Signal Processing Flow.
 *  0b10..Select Downsampling-by-2 as defined in Signal Processing Flow.
 *  0b11..Reserved.
 */
#define ASRC_ASRCFG_POSTMODC(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_POSTMODC_SHIFT)) & ASRC_ASRCFG_POSTMODC_MASK)

#define ASRC_ASRCFG_NDPRA_MASK                   (0x40000U)
#define ASRC_ASRCFG_NDPRA_SHIFT                  (18U)
/*! NDPRA - Not Use Default Parameters for RAM-stored Parameters For Conversion Pair A
 *  0b0..Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 *  0b1..Don't use default parameters for RAM-stored parameters. Use the parameters already stored in RAM.
 */
#define ASRC_ASRCFG_NDPRA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_NDPRA_SHIFT)) & ASRC_ASRCFG_NDPRA_MASK)

#define ASRC_ASRCFG_NDPRB_MASK                   (0x80000U)
#define ASRC_ASRCFG_NDPRB_SHIFT                  (19U)
/*! NDPRB - Not Use Default Parameters for RAM-Stored Parameters For Conversion Pair B
 *  0b0..Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 *  0b1..Don't use default parameters for RAM-stored parameter. Use the parameters already stored in RAM.
 */
#define ASRC_ASRCFG_NDPRB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_NDPRB_SHIFT)) & ASRC_ASRCFG_NDPRB_MASK)

#define ASRC_ASRCFG_NDPRC_MASK                   (0x100000U)
#define ASRC_ASRCFG_NDPRC_SHIFT                  (20U)
/*! NDPRC - Not Use Default Parameters for RAM-Stored Parameters For Conversion Pair C
 *  0b0..Use default parameters for RAM-stored parameters. Override any parameters already in RAM.
 *  0b1..Don't use default parameters for RAM-stored parameters. Use the parameters already stored in RAM.
 */
#define ASRC_ASRCFG_NDPRC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_NDPRC_SHIFT)) & ASRC_ASRCFG_NDPRC_MASK)

#define ASRC_ASRCFG_INIRQA_MASK                  (0x200000U)
#define ASRC_ASRCFG_INIRQA_SHIFT                 (21U)
/*! INIRQA - Initialization for Conversion Pair A is served
 *  0b0..Initialization for Conversion Pair A not served
 *  0b1..Initialization for Conversion Pair A served
 */
#define ASRC_ASRCFG_INIRQA(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_INIRQA_SHIFT)) & ASRC_ASRCFG_INIRQA_MASK)

#define ASRC_ASRCFG_INIRQB_MASK                  (0x400000U)
#define ASRC_ASRCFG_INIRQB_SHIFT                 (22U)
/*! INIRQB - Initialization for Conversion Pair B is Served
 *  0b0..Initialization for Conversion Pair B not served
 *  0b1..Initialization for Conversion Pair B served
 */
#define ASRC_ASRCFG_INIRQB(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_INIRQB_SHIFT)) & ASRC_ASRCFG_INIRQB_MASK)

#define ASRC_ASRCFG_INIRQC_MASK                  (0x800000U)
#define ASRC_ASRCFG_INIRQC_SHIFT                 (23U)
/*! INIRQC - Initialization for Conversion Pair C is Served
 *  0b0..Initialization for Conversion Pair C not served
 *  0b1..Initialization for Conversion Pair C served
 */
#define ASRC_ASRCFG_INIRQC(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCFG_INIRQC_SHIFT)) & ASRC_ASRCFG_INIRQC_MASK)
/*! @} */

/*! @name ASRCSR - ASRC Clock Source */
/*! @{ */

#define ASRC_ASRCSR_AICSA_MASK                   (0xFU)
#define ASRC_ASRCSR_AICSA_SHIFT                  (0U)
/*! AICSA - Input Clock Source A
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AICSA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AICSA_SHIFT)) & ASRC_ASRCSR_AICSA_MASK)

#define ASRC_ASRCSR_AICSB_MASK                   (0xF0U)
#define ASRC_ASRCSR_AICSB_SHIFT                  (4U)
/*! AICSB - Input Clock Source B
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AICSB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AICSB_SHIFT)) & ASRC_ASRCSR_AICSB_MASK)

#define ASRC_ASRCSR_AICSC_MASK                   (0xF00U)
#define ASRC_ASRCSR_AICSC_SHIFT                  (8U)
/*! AICSC - Input Clock Source C
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AICSC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AICSC_SHIFT)) & ASRC_ASRCSR_AICSC_MASK)

#define ASRC_ASRCSR_AOCSA_MASK                   (0xF000U)
#define ASRC_ASRCSR_AOCSA_SHIFT                  (12U)
/*! AOCSA - Output Clock Source A
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AOCSA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AOCSA_SHIFT)) & ASRC_ASRCSR_AOCSA_MASK)

#define ASRC_ASRCSR_AOCSB_MASK                   (0xF0000U)
#define ASRC_ASRCSR_AOCSB_SHIFT                  (16U)
/*! AOCSB - Output Clock Source B
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AOCSB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AOCSB_SHIFT)) & ASRC_ASRCSR_AOCSB_MASK)

#define ASRC_ASRCSR_AOCSC_MASK                   (0xF00000U)
#define ASRC_ASRCSR_AOCSC_SHIFT                  (20U)
/*! AOCSC - Output Clock Source C
 *  0b0000..Bit clock 0
 *  0b0001..Bit clock 1
 *  0b0010..Bit clock 2
 *  0b0011..Bit clock 3
 *  0b0100..Bit clock 4
 *  0b0101..Bit clock 5
 *  0b0110..Bit clock 6
 *  0b0111..Bit clock 7
 *  0b1000..Bit clock 8
 *  0b1001..Bit clock 9
 *  0b1010..Bit clock A
 *  0b1011..Bit clock B
 *  0b1100..Bit clock C
 *  0b1101..Bit clock D
 *  0b1110..Bit clock E
 *  0b1111..Clock disabled, connected to zero
 */
#define ASRC_ASRCSR_AOCSC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCSR_AOCSC_SHIFT)) & ASRC_ASRCSR_AOCSC_MASK)
/*! @} */

/*! @name ASRCDR1 - ASRC Clock Divider 1 */
/*! @{ */

#define ASRC_ASRCDR1_AICPA_MASK                  (0x7U)
#define ASRC_ASRCDR1_AICPA_SHIFT                 (0U)
/*! AICPA - Input Clock Prescaler A */
#define ASRC_ASRCDR1_AICPA(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AICPA_SHIFT)) & ASRC_ASRCDR1_AICPA_MASK)

#define ASRC_ASRCDR1_AICDA_MASK                  (0x38U)
#define ASRC_ASRCDR1_AICDA_SHIFT                 (3U)
/*! AICDA - Input Clock Divider A */
#define ASRC_ASRCDR1_AICDA(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AICDA_SHIFT)) & ASRC_ASRCDR1_AICDA_MASK)

#define ASRC_ASRCDR1_AICPB_MASK                  (0x1C0U)
#define ASRC_ASRCDR1_AICPB_SHIFT                 (6U)
/*! AICPB - Input Clock Prescaler B */
#define ASRC_ASRCDR1_AICPB(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AICPB_SHIFT)) & ASRC_ASRCDR1_AICPB_MASK)

#define ASRC_ASRCDR1_AICDB_MASK                  (0xE00U)
#define ASRC_ASRCDR1_AICDB_SHIFT                 (9U)
/*! AICDB - Input Clock Divider B */
#define ASRC_ASRCDR1_AICDB(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AICDB_SHIFT)) & ASRC_ASRCDR1_AICDB_MASK)

#define ASRC_ASRCDR1_AOCPA_MASK                  (0x7000U)
#define ASRC_ASRCDR1_AOCPA_SHIFT                 (12U)
/*! AOCPA - Output Clock Prescaler A */
#define ASRC_ASRCDR1_AOCPA(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AOCPA_SHIFT)) & ASRC_ASRCDR1_AOCPA_MASK)

#define ASRC_ASRCDR1_AOCDA_MASK                  (0x38000U)
#define ASRC_ASRCDR1_AOCDA_SHIFT                 (15U)
/*! AOCDA - Output Clock Divider A */
#define ASRC_ASRCDR1_AOCDA(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AOCDA_SHIFT)) & ASRC_ASRCDR1_AOCDA_MASK)

#define ASRC_ASRCDR1_AOCPB_MASK                  (0x1C0000U)
#define ASRC_ASRCDR1_AOCPB_SHIFT                 (18U)
/*! AOCPB - Output Clock Prescaler B */
#define ASRC_ASRCDR1_AOCPB(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AOCPB_SHIFT)) & ASRC_ASRCDR1_AOCPB_MASK)

#define ASRC_ASRCDR1_AOCDB_MASK                  (0xE00000U)
#define ASRC_ASRCDR1_AOCDB_SHIFT                 (21U)
/*! AOCDB - Output Clock Divider B */
#define ASRC_ASRCDR1_AOCDB(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR1_AOCDB_SHIFT)) & ASRC_ASRCDR1_AOCDB_MASK)
/*! @} */

/*! @name ASRCDR2 - ASRC Clock Divider 2 */
/*! @{ */

#define ASRC_ASRCDR2_AICPC_MASK                  (0x7U)
#define ASRC_ASRCDR2_AICPC_SHIFT                 (0U)
/*! AICPC - Input Clock Prescaler C */
#define ASRC_ASRCDR2_AICPC(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR2_AICPC_SHIFT)) & ASRC_ASRCDR2_AICPC_MASK)

#define ASRC_ASRCDR2_AICDC_MASK                  (0x38U)
#define ASRC_ASRCDR2_AICDC_SHIFT                 (3U)
/*! AICDC - Input Clock Divider C */
#define ASRC_ASRCDR2_AICDC(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR2_AICDC_SHIFT)) & ASRC_ASRCDR2_AICDC_MASK)

#define ASRC_ASRCDR2_AOCPC_MASK                  (0x1C0U)
#define ASRC_ASRCDR2_AOCPC_SHIFT                 (6U)
/*! AOCPC - Output Clock Prescaler C */
#define ASRC_ASRCDR2_AOCPC(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR2_AOCPC_SHIFT)) & ASRC_ASRCDR2_AOCPC_MASK)

#define ASRC_ASRCDR2_AOCDC_MASK                  (0xE00U)
#define ASRC_ASRCDR2_AOCDC_SHIFT                 (9U)
/*! AOCDC - Output Clock Divider C */
#define ASRC_ASRCDR2_AOCDC(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCDR2_AOCDC_SHIFT)) & ASRC_ASRCDR2_AOCDC_MASK)
/*! @} */

/*! @name ASRSTR - ASRC Status */
/*! @{ */

#define ASRC_ASRSTR_AIDEA_MASK                   (0x1U)
#define ASRC_ASRSTR_AIDEA_SHIFT                  (0U)
/*! AIDEA - Number of Data in Input Data Buffer A is Less than Threshold
 *  0b0..The threshold has been met and no data input A interrupt is generated
 *  0b1..When AIDEA is set, the ASRC generates data input A interrupt request to the processor if ASRIER[AIDEA] = 1
 */
#define ASRC_ASRSTR_AIDEA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDEA_SHIFT)) & ASRC_ASRSTR_AIDEA_MASK)

#define ASRC_ASRSTR_AIDEB_MASK                   (0x2U)
#define ASRC_ASRSTR_AIDEB_SHIFT                  (1U)
/*! AIDEB - Number of Data in Input Data Buffer B is Less than Threshold
 *  0b0..The threshold has been met and no data input B interrupt is generated
 *  0b1..When AIDEB is set, the ASRC generates data input B interrupt request to the processor if ASRIER[AIDEB] = 1
 */
#define ASRC_ASRSTR_AIDEB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDEB_SHIFT)) & ASRC_ASRSTR_AIDEB_MASK)

#define ASRC_ASRSTR_AIDEC_MASK                   (0x4U)
#define ASRC_ASRSTR_AIDEC_SHIFT                  (2U)
/*! AIDEC - Number of Data in Input Data Buffer C is Less than Threshold
 *  0b0..The threshold has been met and no data input C interrupt is generated
 *  0b1..When AIDEC is set, the ASRC generates data input C interrupt request to the processor if ASRIER[AIDEC] = 1
 */
#define ASRC_ASRSTR_AIDEC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDEC_SHIFT)) & ASRC_ASRSTR_AIDEC_MASK)

#define ASRC_ASRSTR_AODFA_MASK                   (0x8U)
#define ASRC_ASRSTR_AODFA_SHIFT                  (3U)
/*! AODFA - Number of Data in Output Data Buffer A is Greater than Threshold
 *  0b0..The threshold has not yet been met and no data output A interrupt is generated
 *  0b1..When AODFA is set, the ASRC generates data output A interrupt request to the processor if ASRIER[ADOEA] = 1
 */
#define ASRC_ASRSTR_AODFA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODFA_SHIFT)) & ASRC_ASRSTR_AODFA_MASK)

#define ASRC_ASRSTR_AODFB_MASK                   (0x10U)
#define ASRC_ASRSTR_AODFB_SHIFT                  (4U)
/*! AODFB - Number of data in Output Data Buffer B is Greater than Threshold
 *  0b0..The threshold has not yet been met and no data output B interrupt is generated
 *  0b1..When AODFB is set, the ASRC generates data output B interrupt request to the processor if ASRIER[ADOEB] = 1
 */
#define ASRC_ASRSTR_AODFB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODFB_SHIFT)) & ASRC_ASRSTR_AODFB_MASK)

#define ASRC_ASRSTR_AODFC_MASK                   (0x20U)
#define ASRC_ASRSTR_AODFC_SHIFT                  (5U)
/*! AODFC - Number of data in Output Data Buffer C is Greater than Threshold
 *  0b0..The threshold has not yet been met and no data output C interrupt is generated
 *  0b1..When AODFC is set, the ASRC generates data output C interrupt request to the processor if ASRIER[ADOEC] = 1
 */
#define ASRC_ASRSTR_AODFC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODFC_SHIFT)) & ASRC_ASRSTR_AODFC_MASK)

#define ASRC_ASRSTR_AOLE_MASK                    (0x40U)
#define ASRC_ASRSTR_AOLE_SHIFT                   (6U)
/*! AOLE - Overload Error Flag
 *  0b0..No overload
 *  0b1..Task rate is too high
 */
#define ASRC_ASRSTR_AOLE(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AOLE_SHIFT)) & ASRC_ASRSTR_AOLE_MASK)

#define ASRC_ASRSTR_FPWT_MASK                    (0x80U)
#define ASRC_ASRSTR_FPWT_SHIFT                   (7U)
/*! FPWT - FP is in Wait States
 *  0b0..ASRC is not in wait state
 *  0b1..ASRC is in wait state
 */
#define ASRC_ASRSTR_FPWT(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_FPWT_SHIFT)) & ASRC_ASRSTR_FPWT_MASK)

#define ASRC_ASRSTR_AIDUA_MASK                   (0x100U)
#define ASRC_ASRSTR_AIDUA_SHIFT                  (8U)
/*! AIDUA - Input Data Buffer A has Underflowed
 *  0b0..No Underflow in Input data buffer A
 *  0b1..Underflow in Input data buffer A
 */
#define ASRC_ASRSTR_AIDUA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDUA_SHIFT)) & ASRC_ASRSTR_AIDUA_MASK)

#define ASRC_ASRSTR_AIDUB_MASK                   (0x200U)
#define ASRC_ASRSTR_AIDUB_SHIFT                  (9U)
/*! AIDUB - Input Data Buffer B has Underflowed
 *  0b0..No Underflow in Input data buffer B
 *  0b1..Underflow in Input data buffer B
 */
#define ASRC_ASRSTR_AIDUB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDUB_SHIFT)) & ASRC_ASRSTR_AIDUB_MASK)

#define ASRC_ASRSTR_AIDUC_MASK                   (0x400U)
#define ASRC_ASRSTR_AIDUC_SHIFT                  (10U)
/*! AIDUC - Input Data Buffer C has Underflowed
 *  0b0..No Underflow in Input data buffer C
 *  0b1..Underflow in Input data buffer C
 */
#define ASRC_ASRSTR_AIDUC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIDUC_SHIFT)) & ASRC_ASRSTR_AIDUC_MASK)

#define ASRC_ASRSTR_AODOA_MASK                   (0x800U)
#define ASRC_ASRSTR_AODOA_SHIFT                  (11U)
/*! AODOA - Output Data Buffer A has Overflowed
 *  0b0..No Overflow in Output data buffer A
 *  0b1..Overflow in Output data buffer A
 */
#define ASRC_ASRSTR_AODOA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODOA_SHIFT)) & ASRC_ASRSTR_AODOA_MASK)

#define ASRC_ASRSTR_AODOB_MASK                   (0x1000U)
#define ASRC_ASRSTR_AODOB_SHIFT                  (12U)
/*! AODOB - Output Data Buffer B has Overflowed
 *  0b0..No Overflow in Output data buffer B
 *  0b1..Overflow in Output data buffer B
 */
#define ASRC_ASRSTR_AODOB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODOB_SHIFT)) & ASRC_ASRSTR_AODOB_MASK)

#define ASRC_ASRSTR_AODOC_MASK                   (0x2000U)
#define ASRC_ASRSTR_AODOC_SHIFT                  (13U)
/*! AODOC - Output Data Buffer C has Overflowed
 *  0b0..No Overflow in Output data buffer C
 *  0b1..Overflow in Output data buffer C
 */
#define ASRC_ASRSTR_AODOC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AODOC_SHIFT)) & ASRC_ASRSTR_AODOC_MASK)

#define ASRC_ASRSTR_AIOLA_MASK                   (0x4000U)
#define ASRC_ASRSTR_AIOLA_SHIFT                  (14U)
/*! AIOLA - Pair A Input Task Overload
 *  0b0..Pair A input task is not overloaded
 *  0b1..Pair A input task is overloaded
 */
#define ASRC_ASRSTR_AIOLA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIOLA_SHIFT)) & ASRC_ASRSTR_AIOLA_MASK)

#define ASRC_ASRSTR_AIOLB_MASK                   (0x8000U)
#define ASRC_ASRSTR_AIOLB_SHIFT                  (15U)
/*! AIOLB - Pair B Input Task Overload
 *  0b0..Pair B input task is not overloaded
 *  0b1..Pair B input task is overloaded
 */
#define ASRC_ASRSTR_AIOLB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIOLB_SHIFT)) & ASRC_ASRSTR_AIOLB_MASK)

#define ASRC_ASRSTR_AIOLC_MASK                   (0x10000U)
#define ASRC_ASRSTR_AIOLC_SHIFT                  (16U)
/*! AIOLC - Pair C Input Task Overload
 *  0b0..Pair C input task is not overloaded
 *  0b1..Pair C input task is overloaded
 */
#define ASRC_ASRSTR_AIOLC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AIOLC_SHIFT)) & ASRC_ASRSTR_AIOLC_MASK)

#define ASRC_ASRSTR_AOOLA_MASK                   (0x20000U)
#define ASRC_ASRSTR_AOOLA_SHIFT                  (17U)
/*! AOOLA - Pair A Output Task Overload
 *  0b0..Pair A output task is not overloaded
 *  0b1..Pair A output task is overloaded
 */
#define ASRC_ASRSTR_AOOLA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AOOLA_SHIFT)) & ASRC_ASRSTR_AOOLA_MASK)

#define ASRC_ASRSTR_AOOLB_MASK                   (0x40000U)
#define ASRC_ASRSTR_AOOLB_SHIFT                  (18U)
/*! AOOLB - Pair B Output Task Overload
 *  0b0..Pair B output task is not overloaded
 *  0b1..Pair B output task is overloaded
 */
#define ASRC_ASRSTR_AOOLB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AOOLB_SHIFT)) & ASRC_ASRSTR_AOOLB_MASK)

#define ASRC_ASRSTR_AOOLC_MASK                   (0x80000U)
#define ASRC_ASRSTR_AOOLC_SHIFT                  (19U)
/*! AOOLC - Pair C Output Task Overload
 *  0b0..Pair C output task is not overloaded
 *  0b1..Pair C output task is overloaded
 */
#define ASRC_ASRSTR_AOOLC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_AOOLC_SHIFT)) & ASRC_ASRSTR_AOOLC_MASK)

#define ASRC_ASRSTR_ATQOL_MASK                   (0x100000U)
#define ASRC_ASRSTR_ATQOL_SHIFT                  (20U)
/*! ATQOL - Task Queue FIFO overload
 *  0b0..Task queue FIFO logic is not overloaded
 *  0b1..Task queue FIFO logic is overloaded
 */
#define ASRC_ASRSTR_ATQOL(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_ATQOL_SHIFT)) & ASRC_ASRSTR_ATQOL_MASK)

#define ASRC_ASRSTR_DSLCNT_MASK                  (0x200000U)
#define ASRC_ASRSTR_DSLCNT_SHIFT                 (21U)
/*! DSLCNT - Digital Servo Loop (DSL) Counter Input to FIFO Ready
 *  0b0..New DSL counter information is in the process of storage into the internal ASRC FIFO
 *  0b1..New DSL counter information is stored in the internal ASRC FIFO
 */
#define ASRC_ASRSTR_DSLCNT(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASRSTR_DSLCNT_SHIFT)) & ASRC_ASRSTR_DSLCNT_MASK)
/*! @} */

/*! @name ASRPM - ASRC Parameter x */
/*! @{ */

#define ASRC_ASRPM_PARAMETER_VALUE_MASK          (0xFFFFFFU)
#define ASRC_ASRPM_PARAMETER_VALUE_SHIFT         (0U)
/*! PARAMETER_VALUE - Parameter Value */
#define ASRC_ASRPM_PARAMETER_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_ASRPM_PARAMETER_VALUE_SHIFT)) & ASRC_ASRPM_PARAMETER_VALUE_MASK)
/*! @} */

/*! @name ASRTFR1 - ASRC Task Queue FIFO 1 */
/*! @{ */

#define ASRC_ASRTFR1_TF_BASE_MASK                (0x1FC0U)
#define ASRC_ASRTFR1_TF_BASE_SHIFT               (6U)
/*! TF_BASE - Base Address for Task Queue FIFO */
#define ASRC_ASRTFR1_TF_BASE(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRTFR1_TF_BASE_SHIFT)) & ASRC_ASRTFR1_TF_BASE_MASK)

#define ASRC_ASRTFR1_TF_FILL_MASK                (0xFE000U)
#define ASRC_ASRTFR1_TF_FILL_SHIFT               (13U)
/*! TF_FILL - Current Number of Entries in Task Queue FIFO */
#define ASRC_ASRTFR1_TF_FILL(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRTFR1_TF_FILL_SHIFT)) & ASRC_ASRTFR1_TF_FILL_MASK)
/*! @} */

/*! @name ASRCCR - ASRC Channel Counter */
/*! @{ */

#define ASRC_ASRCCR_ACIA_MASK                    (0xFU)
#define ASRC_ASRCCR_ACIA_SHIFT                   (0U)
/*! ACIA - Channel Counter for Pair A's Input FIFO */
#define ASRC_ASRCCR_ACIA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACIA_SHIFT)) & ASRC_ASRCCR_ACIA_MASK)

#define ASRC_ASRCCR_ACIB_MASK                    (0xF0U)
#define ASRC_ASRCCR_ACIB_SHIFT                   (4U)
/*! ACIB - Channel Counter for Pair B's Input FIFO */
#define ASRC_ASRCCR_ACIB(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACIB_SHIFT)) & ASRC_ASRCCR_ACIB_MASK)

#define ASRC_ASRCCR_ACIC_MASK                    (0xF00U)
#define ASRC_ASRCCR_ACIC_SHIFT                   (8U)
/*! ACIC - Channel Counter for Pair C's Input FIFO */
#define ASRC_ASRCCR_ACIC(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACIC_SHIFT)) & ASRC_ASRCCR_ACIC_MASK)

#define ASRC_ASRCCR_ACOA_MASK                    (0xF000U)
#define ASRC_ASRCCR_ACOA_SHIFT                   (12U)
/*! ACOA - Channel Counter for Pair A's Output FIFO */
#define ASRC_ASRCCR_ACOA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACOA_SHIFT)) & ASRC_ASRCCR_ACOA_MASK)

#define ASRC_ASRCCR_ACOB_MASK                    (0xF0000U)
#define ASRC_ASRCCR_ACOB_SHIFT                   (16U)
/*! ACOB - Channel Counter for Pair B's Output FIFO */
#define ASRC_ASRCCR_ACOB(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACOB_SHIFT)) & ASRC_ASRCCR_ACOB_MASK)

#define ASRC_ASRCCR_ACOC_MASK                    (0xF00000U)
#define ASRC_ASRCCR_ACOC_SHIFT                   (20U)
/*! ACOC - Channel Counter for Pair C's Output FIFO */
#define ASRC_ASRCCR_ACOC(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRCCR_ACOC_SHIFT)) & ASRC_ASRCCR_ACOC_MASK)
/*! @} */

/*! @name ASRDIA - ASRC Data Input for Pair x */
/*! @{ */

#define ASRC_ASRDIA_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDIA_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDIA_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDIA_DATA_SHIFT)) & ASRC_ASRDIA_DATA_MASK)
/*! @} */

/*! @name ASRDOA - ASRC Data Output for Pair x */
/*! @{ */

#define ASRC_ASRDOA_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDOA_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDOA_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDOA_DATA_SHIFT)) & ASRC_ASRDOA_DATA_MASK)
/*! @} */

/*! @name ASRDIB - ASRC Data Input for Pair x */
/*! @{ */

#define ASRC_ASRDIB_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDIB_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDIB_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDIB_DATA_SHIFT)) & ASRC_ASRDIB_DATA_MASK)
/*! @} */

/*! @name ASRDOB - ASRC Data Output for Pair x */
/*! @{ */

#define ASRC_ASRDOB_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDOB_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDOB_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDOB_DATA_SHIFT)) & ASRC_ASRDOB_DATA_MASK)
/*! @} */

/*! @name ASRDIC - ASRC Data Input for Pair x */
/*! @{ */

#define ASRC_ASRDIC_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDIC_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDIC_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDIC_DATA_SHIFT)) & ASRC_ASRDIC_DATA_MASK)
/*! @} */

/*! @name ASRDOC - ASRC Data Output for Pair x */
/*! @{ */

#define ASRC_ASRDOC_DATA_MASK                    (0xFFFFFFU)
#define ASRC_ASRDOC_DATA_SHIFT                   (0U)
/*! DATA - Data */
#define ASRC_ASRDOC_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRDOC_DATA_SHIFT)) & ASRC_ASRDOC_DATA_MASK)
/*! @} */

/*! @name ASRIDRHA - ASRC Ideal Ratio for Pair A-High Part */
/*! @{ */

#define ASRC_ASRIDRHA_IDRATIOA_H_MASK            (0xFFU)
#define ASRC_ASRIDRHA_IDRATIOA_H_SHIFT           (0U)
/*! IDRATIOA_H - Ideal Ratio A High */
#define ASRC_ASRIDRHA_IDRATIOA_H(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRHA_IDRATIOA_H_SHIFT)) & ASRC_ASRIDRHA_IDRATIOA_H_MASK)
/*! @} */

/*! @name ASRIDRLA - ASRC Ideal Ratio for Pair A -Low Part */
/*! @{ */

#define ASRC_ASRIDRLA_IDRATIOA_L_MASK            (0xFFFFFFU)
#define ASRC_ASRIDRLA_IDRATIOA_L_SHIFT           (0U)
/*! IDRATIOA_L - Ideal Ratio A Low */
#define ASRC_ASRIDRLA_IDRATIOA_L(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRLA_IDRATIOA_L_SHIFT)) & ASRC_ASRIDRLA_IDRATIOA_L_MASK)
/*! @} */

/*! @name ASRIDRHB - ASRC Ideal Ratio for Pair B-High Part */
/*! @{ */

#define ASRC_ASRIDRHB_IDRATIOB_H_MASK            (0xFFU)
#define ASRC_ASRIDRHB_IDRATIOB_H_SHIFT           (0U)
/*! IDRATIOB_H - Ideal Ratio B High */
#define ASRC_ASRIDRHB_IDRATIOB_H(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRHB_IDRATIOB_H_SHIFT)) & ASRC_ASRIDRHB_IDRATIOB_H_MASK)
/*! @} */

/*! @name ASRIDRLB - ASRC Ideal Ratio for Pair B-Low Part */
/*! @{ */

#define ASRC_ASRIDRLB_IDRATIOB_L_MASK            (0xFFFFFFU)
#define ASRC_ASRIDRLB_IDRATIOB_L_SHIFT           (0U)
/*! IDRATIOB_L - Ideal Ratio B Low */
#define ASRC_ASRIDRLB_IDRATIOB_L(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRLB_IDRATIOB_L_SHIFT)) & ASRC_ASRIDRLB_IDRATIOB_L_MASK)
/*! @} */

/*! @name ASRIDRHC - ASRC Ideal Ratio for Pair C-High Part */
/*! @{ */

#define ASRC_ASRIDRHC_IDRATIOC_H_MASK            (0xFFU)
#define ASRC_ASRIDRHC_IDRATIOC_H_SHIFT           (0U)
/*! IDRATIOC_H - Ideal Ratio C High */
#define ASRC_ASRIDRHC_IDRATIOC_H(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRHC_IDRATIOC_H_SHIFT)) & ASRC_ASRIDRHC_IDRATIOC_H_MASK)
/*! @} */

/*! @name ASRIDRLC - ASRC Ideal Ratio for Pair C-Low Part */
/*! @{ */

#define ASRC_ASRIDRLC_IDRATIOC_L_MASK            (0xFFFFFFU)
#define ASRC_ASRIDRLC_IDRATIOC_L_SHIFT           (0U)
/*! IDRATIOC_L - Ideal Ratio C Low */
#define ASRC_ASRIDRLC_IDRATIOC_L(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRIDRLC_IDRATIOC_L_SHIFT)) & ASRC_ASRIDRLC_IDRATIOC_L_MASK)
/*! @} */

/*! @name ASR76K - ASRC 76 kHz Period */
/*! @{ */

#define ASRC_ASR76K_ASR76K_MASK                  (0x1FFFFU)
#define ASRC_ASR76K_ASR76K_SHIFT                 (0U)
/*! ASR76K - Value for the Period of the 76 kHz Sampling Clock */
#define ASRC_ASR76K_ASR76K(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASR76K_ASR76K_SHIFT)) & ASRC_ASR76K_ASR76K_MASK)
/*! @} */

/*! @name ASR56K - ASRC 56 kHz Period */
/*! @{ */

#define ASRC_ASR56K_ASR56K_MASK                  (0x1FFFFU)
#define ASRC_ASR56K_ASR56K_SHIFT                 (0U)
/*! ASR56K - Value for the Period of the 56 kHz Sampling Clock */
#define ASRC_ASR56K_ASR56K(x)                    (((uint32_t)(((uint32_t)(x)) << ASRC_ASR56K_ASR56K_SHIFT)) & ASRC_ASR56K_ASR56K_MASK)
/*! @} */

/*! @name ASRMCRA - ASRC Misc Control for Pair A */
/*! @{ */

#define ASRC_ASRMCRA_INFIFO_THRESHOLDA_MASK      (0x3FU)
#define ASRC_ASRMCRA_INFIFO_THRESHOLDA_SHIFT     (0U)
/*! INFIFO_THRESHOLDA - Threshold for Pair A's Input FIFO per Channel */
#define ASRC_ASRMCRA_INFIFO_THRESHOLDA(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_INFIFO_THRESHOLDA_SHIFT)) & ASRC_ASRMCRA_INFIFO_THRESHOLDA_MASK)

#define ASRC_ASRMCRA_RSYNOFA_MASK                (0x400U)
#define ASRC_ASRMCRA_RSYNOFA_SHIFT               (10U)
/*! RSYNOFA - Re-sync Output FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACOA]
 *  0b1..Force ASRCCR[ACOA]=0
 */
#define ASRC_ASRMCRA_RSYNOFA(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_RSYNOFA_SHIFT)) & ASRC_ASRMCRA_RSYNOFA_MASK)

#define ASRC_ASRMCRA_RSYNIFA_MASK                (0x800U)
#define ASRC_ASRMCRA_RSYNIFA_SHIFT               (11U)
/*! RSYNIFA - Re-sync Input FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACIA]
 *  0b1..Force ASRCCR[ACIA]=0
 */
#define ASRC_ASRMCRA_RSYNIFA(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_RSYNIFA_SHIFT)) & ASRC_ASRMCRA_RSYNIFA_MASK)

#define ASRC_ASRMCRA_OUTFIFO_THRESHOLDA_MASK     (0x3F000U)
#define ASRC_ASRMCRA_OUTFIFO_THRESHOLDA_SHIFT    (12U)
/*! OUTFIFO_THRESHOLDA - Threshold for Pair A's Output FIFO per Channel */
#define ASRC_ASRMCRA_OUTFIFO_THRESHOLDA(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_OUTFIFO_THRESHOLDA_SHIFT)) & ASRC_ASRMCRA_OUTFIFO_THRESHOLDA_MASK)

#define ASRC_ASRMCRA_BYPASSPOLYA_MASK            (0x100000U)
#define ASRC_ASRMCRA_BYPASSPOLYA_SHIFT           (20U)
/*! BYPASSPOLYA - Bypass Polyphase Filtering for Pair A
 *  0b0..Don't bypass polyphase filtering.
 *  0b1..Bypass polyphase filtering.
 */
#define ASRC_ASRMCRA_BYPASSPOLYA(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_BYPASSPOLYA_SHIFT)) & ASRC_ASRMCRA_BYPASSPOLYA_MASK)

#define ASRC_ASRMCRA_BUFSTALLA_MASK              (0x200000U)
#define ASRC_ASRMCRA_BUFSTALLA_SHIFT             (21U)
/*! BUFSTALLA - Stall Pair A Conversion in Case of Buffer Near Empty/Full Condition
 *  0b0..Don't stall Pair A conversion even in case of near empty/full FIFO conditions.
 *  0b1..Stall Pair A conversion in case of near empty/full FIFO conditions.
 */
#define ASRC_ASRMCRA_BUFSTALLA(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_BUFSTALLA_SHIFT)) & ASRC_ASRMCRA_BUFSTALLA_MASK)

#define ASRC_ASRMCRA_EXTTHRSHA_MASK              (0x400000U)
#define ASRC_ASRMCRA_EXTTHRSHA_SHIFT             (22U)
/*! EXTTHRSHA - Use External Thresholds for FIFO Control of Pair A
 *  0b0..Use default thresholds.
 *  0b1..Use external defined thresholds.
 */
#define ASRC_ASRMCRA_EXTTHRSHA(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_EXTTHRSHA_SHIFT)) & ASRC_ASRMCRA_EXTTHRSHA_MASK)

#define ASRC_ASRMCRA_ZEROBUFA_MASK               (0x800000U)
#define ASRC_ASRMCRA_ZEROBUFA_SHIFT              (23U)
/*! ZEROBUFA - Zero Buffer A
 *  0b0..Zeroize the buffer
 *  0b1..Don't zeroize the buffer
 */
#define ASRC_ASRMCRA_ZEROBUFA(x)                 (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRA_ZEROBUFA_SHIFT)) & ASRC_ASRMCRA_ZEROBUFA_MASK)
/*! @} */

/*! @name ASRFSTA - ASRC FIFO Status for Pair A */
/*! @{ */

#define ASRC_ASRFSTA_INFIFO_FILLA_MASK           (0x7FU)
#define ASRC_ASRFSTA_INFIFO_FILLA_SHIFT          (0U)
/*! INFIFO_FILLA - Fillings for Pair A's Input FIFO per Channel */
#define ASRC_ASRFSTA_INFIFO_FILLA(x)             (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTA_INFIFO_FILLA_SHIFT)) & ASRC_ASRFSTA_INFIFO_FILLA_MASK)

#define ASRC_ASRFSTA_IAEA_MASK                   (0x800U)
#define ASRC_ASRFSTA_IAEA_SHIFT                  (11U)
/*! IAEA - Input FIFO is Near Empty for Pair A
 *  0b0..Input FIFO is not near empty for Pair A
 *  0b1..Input FIFO is near empty for Pair A
 */
#define ASRC_ASRFSTA_IAEA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTA_IAEA_SHIFT)) & ASRC_ASRFSTA_IAEA_MASK)

#define ASRC_ASRFSTA_OUTFIFO_FILLA_MASK          (0x7F000U)
#define ASRC_ASRFSTA_OUTFIFO_FILLA_SHIFT         (12U)
/*! OUTFIFO_FILLA - Fillings for Pair A's Output FIFO per Channel */
#define ASRC_ASRFSTA_OUTFIFO_FILLA(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTA_OUTFIFO_FILLA_SHIFT)) & ASRC_ASRFSTA_OUTFIFO_FILLA_MASK)

#define ASRC_ASRFSTA_OAFA_MASK                   (0x800000U)
#define ASRC_ASRFSTA_OAFA_SHIFT                  (23U)
/*! OAFA - Output FIFO is Near Full for Pair A
 *  0b0..Output FIFO is not near full for Pair A
 *  0b1..Output FIFO is near full for Pair A
 */
#define ASRC_ASRFSTA_OAFA(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTA_OAFA_SHIFT)) & ASRC_ASRFSTA_OAFA_MASK)
/*! @} */

/*! @name ASRMCRB - ASRC Misc Control for Pair B */
/*! @{ */

#define ASRC_ASRMCRB_INFIFO_THRESHOLDB_MASK      (0x3FU)
#define ASRC_ASRMCRB_INFIFO_THRESHOLDB_SHIFT     (0U)
/*! INFIFO_THRESHOLDB - Threshold for Pair B's Input FIFO per Channel */
#define ASRC_ASRMCRB_INFIFO_THRESHOLDB(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_INFIFO_THRESHOLDB_SHIFT)) & ASRC_ASRMCRB_INFIFO_THRESHOLDB_MASK)

#define ASRC_ASRMCRB_RSYNOFB_MASK                (0x400U)
#define ASRC_ASRMCRB_RSYNOFB_SHIFT               (10U)
/*! RSYNOFB - Re-sync Output FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACOB]
 *  0b1..Force ASRCCR[ACOB]=0
 */
#define ASRC_ASRMCRB_RSYNOFB(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_RSYNOFB_SHIFT)) & ASRC_ASRMCRB_RSYNOFB_MASK)

#define ASRC_ASRMCRB_RSYNIFB_MASK                (0x800U)
#define ASRC_ASRMCRB_RSYNIFB_SHIFT               (11U)
/*! RSYNIFB - Re-sync Input FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACIB]
 *  0b1..Force ASRCCR[ACIB]=0
 */
#define ASRC_ASRMCRB_RSYNIFB(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_RSYNIFB_SHIFT)) & ASRC_ASRMCRB_RSYNIFB_MASK)

#define ASRC_ASRMCRB_OUTFIFO_THRESHOLDB_MASK     (0x3F000U)
#define ASRC_ASRMCRB_OUTFIFO_THRESHOLDB_SHIFT    (12U)
/*! OUTFIFO_THRESHOLDB - Threshold for Pair B's Output FIFO per Channel */
#define ASRC_ASRMCRB_OUTFIFO_THRESHOLDB(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_OUTFIFO_THRESHOLDB_SHIFT)) & ASRC_ASRMCRB_OUTFIFO_THRESHOLDB_MASK)

#define ASRC_ASRMCRB_BYPASSPOLYB_MASK            (0x100000U)
#define ASRC_ASRMCRB_BYPASSPOLYB_SHIFT           (20U)
/*! BYPASSPOLYB - Bypass Polyphase Filtering for Pair B
 *  0b0..Don't bypass polyphase filtering.
 *  0b1..Bypass polyphase filtering.
 */
#define ASRC_ASRMCRB_BYPASSPOLYB(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_BYPASSPOLYB_SHIFT)) & ASRC_ASRMCRB_BYPASSPOLYB_MASK)

#define ASRC_ASRMCRB_BUFSTALLB_MASK              (0x200000U)
#define ASRC_ASRMCRB_BUFSTALLB_SHIFT             (21U)
/*! BUFSTALLB - Stall Pair B Conversion in Case of Buffer Near Empty/Full Condition
 *  0b0..Don't stall Pair B conversion even in case of near empty/full FIFO conditions.
 *  0b1..Stall Pair B conversion in case of near empty/full FIFO conditions.
 */
#define ASRC_ASRMCRB_BUFSTALLB(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_BUFSTALLB_SHIFT)) & ASRC_ASRMCRB_BUFSTALLB_MASK)

#define ASRC_ASRMCRB_EXTTHRSHB_MASK              (0x400000U)
#define ASRC_ASRMCRB_EXTTHRSHB_SHIFT             (22U)
/*! EXTTHRSHB - Use External Thresholds for FIFO Control of Pair B
 *  0b0..Use default thresholds.
 *  0b1..Use external defined thresholds.
 */
#define ASRC_ASRMCRB_EXTTHRSHB(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_EXTTHRSHB_SHIFT)) & ASRC_ASRMCRB_EXTTHRSHB_MASK)

#define ASRC_ASRMCRB_ZEROBUFB_MASK               (0x800000U)
#define ASRC_ASRMCRB_ZEROBUFB_SHIFT              (23U)
/*! ZEROBUFB - Zero Buffer B
 *  0b0..Zeroize the buffer
 *  0b1..Don't zeroize the buffer
 */
#define ASRC_ASRMCRB_ZEROBUFB(x)                 (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRB_ZEROBUFB_SHIFT)) & ASRC_ASRMCRB_ZEROBUFB_MASK)
/*! @} */

/*! @name ASRFSTB - ASRC FIFO Status for Pair B */
/*! @{ */

#define ASRC_ASRFSTB_INFIFO_FILLB_MASK           (0x7FU)
#define ASRC_ASRFSTB_INFIFO_FILLB_SHIFT          (0U)
/*! INFIFO_FILLB - Fillings for Pair B's Input FIFO per Channel */
#define ASRC_ASRFSTB_INFIFO_FILLB(x)             (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTB_INFIFO_FILLB_SHIFT)) & ASRC_ASRFSTB_INFIFO_FILLB_MASK)

#define ASRC_ASRFSTB_IAEB_MASK                   (0x800U)
#define ASRC_ASRFSTB_IAEB_SHIFT                  (11U)
/*! IAEB - Input FIFO is Near Empty for Pair B
 *  0b0..Input FIFO is not near empty for Pair B
 *  0b1..Input FIFO is near empty for Pair B
 */
#define ASRC_ASRFSTB_IAEB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTB_IAEB_SHIFT)) & ASRC_ASRFSTB_IAEB_MASK)

#define ASRC_ASRFSTB_OUTFIFO_FILLB_MASK          (0x7F000U)
#define ASRC_ASRFSTB_OUTFIFO_FILLB_SHIFT         (12U)
/*! OUTFIFO_FILLB - Fillings for Pair B's Output FIFO per Channel */
#define ASRC_ASRFSTB_OUTFIFO_FILLB(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTB_OUTFIFO_FILLB_SHIFT)) & ASRC_ASRFSTB_OUTFIFO_FILLB_MASK)

#define ASRC_ASRFSTB_OAFB_MASK                   (0x800000U)
#define ASRC_ASRFSTB_OAFB_SHIFT                  (23U)
/*! OAFB - Output FIFO is Near Full for Pair B
 *  0b0..Output FIFO is not near full for Pair B
 *  0b1..Output FIFO is near full for Pair B
 */
#define ASRC_ASRFSTB_OAFB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTB_OAFB_SHIFT)) & ASRC_ASRFSTB_OAFB_MASK)
/*! @} */

/*! @name ASRMCRC - ASRC Misc Control for Pair C */
/*! @{ */

#define ASRC_ASRMCRC_INFIFO_THRESHOLDC_MASK      (0x3FU)
#define ASRC_ASRMCRC_INFIFO_THRESHOLDC_SHIFT     (0U)
/*! INFIFO_THRESHOLDC - Threshold for Pair C's Input FIFO per Channel */
#define ASRC_ASRMCRC_INFIFO_THRESHOLDC(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_INFIFO_THRESHOLDC_SHIFT)) & ASRC_ASRMCRC_INFIFO_THRESHOLDC_MASK)

#define ASRC_ASRMCRC_RSYNOFC_MASK                (0x400U)
#define ASRC_ASRMCRC_RSYNOFC_SHIFT               (10U)
/*! RSYNOFC - Re-sync Output FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACOC]
 *  0b1..Force ASRCCR[ACOC]=0
 */
#define ASRC_ASRMCRC_RSYNOFC(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_RSYNOFC_SHIFT)) & ASRC_ASRMCRC_RSYNOFC_MASK)

#define ASRC_ASRMCRC_RSYNIFC_MASK                (0x800U)
#define ASRC_ASRMCRC_RSYNIFC_SHIFT               (11U)
/*! RSYNIFC - Re-sync Input FIFO Channel Counter
 *  0b0..Do not touch ASRCCR[ACIC]
 *  0b1..Force ASRCCR[ACIC]=0
 */
#define ASRC_ASRMCRC_RSYNIFC(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_RSYNIFC_SHIFT)) & ASRC_ASRMCRC_RSYNIFC_MASK)

#define ASRC_ASRMCRC_OUTFIFO_THRESHOLDC_MASK     (0x3F000U)
#define ASRC_ASRMCRC_OUTFIFO_THRESHOLDC_SHIFT    (12U)
/*! OUTFIFO_THRESHOLDC - Threshold for Pair C's Output FIFO per Channel */
#define ASRC_ASRMCRC_OUTFIFO_THRESHOLDC(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_OUTFIFO_THRESHOLDC_SHIFT)) & ASRC_ASRMCRC_OUTFIFO_THRESHOLDC_MASK)

#define ASRC_ASRMCRC_BYPASSPOLYC_MASK            (0x100000U)
#define ASRC_ASRMCRC_BYPASSPOLYC_SHIFT           (20U)
/*! BYPASSPOLYC - Bypass Polyphase Filtering for Pair C
 *  0b0..Don't bypass polyphase filtering.
 *  0b1..Bypass polyphase filtering.
 */
#define ASRC_ASRMCRC_BYPASSPOLYC(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_BYPASSPOLYC_SHIFT)) & ASRC_ASRMCRC_BYPASSPOLYC_MASK)

#define ASRC_ASRMCRC_BUFSTALLC_MASK              (0x200000U)
#define ASRC_ASRMCRC_BUFSTALLC_SHIFT             (21U)
/*! BUFSTALLC - Stall Pair C Conversion in Case of Buffer Near Empty/Full Condition
 *  0b0..Don't stall Pair C conversion even in case of near empty/full FIFO conditions.
 *  0b1..Stall Pair C conversion in case of near empty/full FIFO conditions.
 */
#define ASRC_ASRMCRC_BUFSTALLC(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_BUFSTALLC_SHIFT)) & ASRC_ASRMCRC_BUFSTALLC_MASK)

#define ASRC_ASRMCRC_EXTTHRSHC_MASK              (0x400000U)
#define ASRC_ASRMCRC_EXTTHRSHC_SHIFT             (22U)
/*! EXTTHRSHC - Use External Thresholds for FIFO Control of Pair C
 *  0b0..Use default thresholds.
 *  0b1..Use external defined thresholds.
 */
#define ASRC_ASRMCRC_EXTTHRSHC(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_EXTTHRSHC_SHIFT)) & ASRC_ASRMCRC_EXTTHRSHC_MASK)

#define ASRC_ASRMCRC_ZEROBUFC_MASK               (0x800000U)
#define ASRC_ASRMCRC_ZEROBUFC_SHIFT              (23U)
/*! ZEROBUFC - Zero Buffer C
 *  0b0..Zeroize the buffer
 *  0b1..Don't zeroize the buffer
 */
#define ASRC_ASRMCRC_ZEROBUFC(x)                 (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCRC_ZEROBUFC_SHIFT)) & ASRC_ASRMCRC_ZEROBUFC_MASK)
/*! @} */

/*! @name ASRFSTC - ASRC FIFO Status for Pair C */
/*! @{ */

#define ASRC_ASRFSTC_INFIFO_FILLC_MASK           (0x7FU)
#define ASRC_ASRFSTC_INFIFO_FILLC_SHIFT          (0U)
/*! INFIFO_FILLC - Fillings for Pair C's Input FIFO per Channel */
#define ASRC_ASRFSTC_INFIFO_FILLC(x)             (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTC_INFIFO_FILLC_SHIFT)) & ASRC_ASRFSTC_INFIFO_FILLC_MASK)

#define ASRC_ASRFSTC_IAEC_MASK                   (0x800U)
#define ASRC_ASRFSTC_IAEC_SHIFT                  (11U)
/*! IAEC - Input FIFO is Near Empty for Pair C
 *  0b0..Input FIFO is not near empty for Pair C
 *  0b1..Input FIFO is near empty for Pair C
 */
#define ASRC_ASRFSTC_IAEC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTC_IAEC_SHIFT)) & ASRC_ASRFSTC_IAEC_MASK)

#define ASRC_ASRFSTC_OUTFIFO_FILLC_MASK          (0x7F000U)
#define ASRC_ASRFSTC_OUTFIFO_FILLC_SHIFT         (12U)
/*! OUTFIFO_FILLC - Fillings for Pair C's Output FIFO per Channel */
#define ASRC_ASRFSTC_OUTFIFO_FILLC(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTC_OUTFIFO_FILLC_SHIFT)) & ASRC_ASRFSTC_OUTFIFO_FILLC_MASK)

#define ASRC_ASRFSTC_OAFC_MASK                   (0x800000U)
#define ASRC_ASRFSTC_OAFC_SHIFT                  (23U)
/*! OAFC - Output FIFO is Near Full for Pair C
 *  0b0..Output FIFO is not near full for Pair C
 *  0b1..Output FIFO is near full for Pair C
 */
#define ASRC_ASRFSTC_OAFC(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRFSTC_OAFC_SHIFT)) & ASRC_ASRFSTC_OAFC_MASK)
/*! @} */

/*! @name ASRMCR1 - ASRC Misc Control 1 for Pair X */
/*! @{ */

#define ASRC_ASRMCR1_OW16_MASK                   (0x1U)
#define ASRC_ASRMCR1_OW16_SHIFT                  (0U)
/*! OW16 - Bit Width Option of the Output FIFO
 *  0b0..24-bit output data
 *  0b1..16-bit output data
 */
#define ASRC_ASRMCR1_OW16(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCR1_OW16_SHIFT)) & ASRC_ASRMCR1_OW16_MASK)

#define ASRC_ASRMCR1_OSGN_MASK                   (0x2U)
#define ASRC_ASRMCR1_OSGN_SHIFT                  (1U)
/*! OSGN - Sign Extension Option of the Output FIFO
 *  0b0..No sign extension
 *  0b1..Sign extension
 */
#define ASRC_ASRMCR1_OSGN(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCR1_OSGN_SHIFT)) & ASRC_ASRMCR1_OSGN_MASK)

#define ASRC_ASRMCR1_OMSB_MASK                   (0x4U)
#define ASRC_ASRMCR1_OMSB_SHIFT                  (2U)
/*! OMSB - Data Alignment of the Output FIFO
 *  0b0..LSB aligned
 *  0b1..MSB aligned
 */
#define ASRC_ASRMCR1_OMSB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCR1_OMSB_SHIFT)) & ASRC_ASRMCR1_OMSB_MASK)

#define ASRC_ASRMCR1_IMSB_MASK                   (0x100U)
#define ASRC_ASRMCR1_IMSB_SHIFT                  (8U)
/*! IMSB - Data Alignment of the Input FIFO
 *  0b0..LSB aligned
 *  0b1..MSB aligned
 */
#define ASRC_ASRMCR1_IMSB(x)                     (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCR1_IMSB_SHIFT)) & ASRC_ASRMCR1_IMSB_MASK)

#define ASRC_ASRMCR1_IWD_MASK                    (0x600U)
#define ASRC_ASRMCR1_IWD_SHIFT                   (9U)
/*! IWD - Data Width of the Input FIFO
 *  0b00..24-bit audio data.
 *  0b01..16-bit audio data.
 *  0b10..8-bit audio data.
 *  0b11..Reserved.
 */
#define ASRC_ASRMCR1_IWD(x)                      (((uint32_t)(((uint32_t)(x)) << ASRC_ASRMCR1_IWD_SHIFT)) & ASRC_ASRMCR1_IWD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ASRC_Register_Masks */


/*!
 * @}
 */ /* end of group ASRC_Peripheral_Access_Layer */


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


#endif  /* PERI_ASRC_H_ */

