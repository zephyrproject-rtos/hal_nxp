/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PORT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PORT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PORT
 *
 * CMSIS Peripheral Access Layer for PORT
 */

#if !defined(PERI_PORT_H_)
#define PERI_PORT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t IOFLT;                             /**< Port Filter Register, offset: 0x0 */
  __IO uint32_t PUEL;                              /**< Port Pullup Enable Low Register, offset: 0x4 */
  __IO uint32_t PUEH;                              /**< Port Pullup Enable High Register, offset: 0x8 */
  __IO uint32_t HDRVE;                             /**< Port High Drive Enable Register, offset: 0xC */
} PORT_Type;

/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/*! @name IOFLT - Port Filter Register */
/*! @{ */

#define PORT_IOFLT_FLTA_MASK                     (0x3U)
#define PORT_IOFLT_FLTA_SHIFT                    (0U)
/*! FLTA - Filter Selection for Input from PTA
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTA(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTA_SHIFT)) & PORT_IOFLT_FLTA_MASK)

#define PORT_IOFLT_FLTB_MASK                     (0xCU)
#define PORT_IOFLT_FLTB_SHIFT                    (2U)
/*! FLTB - Filter Selection for Input from PTB
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTB(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTB_SHIFT)) & PORT_IOFLT_FLTB_MASK)

#define PORT_IOFLT_FLTC_MASK                     (0x30U)
#define PORT_IOFLT_FLTC_SHIFT                    (4U)
/*! FLTC - Filter Selection for Input from PTC
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTC(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTC_SHIFT)) & PORT_IOFLT_FLTC_MASK)

#define PORT_IOFLT_FLTD_MASK                     (0xC0U)
#define PORT_IOFLT_FLTD_SHIFT                    (6U)
/*! FLTD - Filter Selection for Input from PTD
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTD(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTD_SHIFT)) & PORT_IOFLT_FLTD_MASK)

#define PORT_IOFLT_FLTE_MASK                     (0x300U)
#define PORT_IOFLT_FLTE_SHIFT                    (8U)
/*! FLTE - Filter Selection for Input from PTD
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTE(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTE_SHIFT)) & PORT_IOFLT_FLTE_MASK)

#define PORT_IOFLT_FLTF_MASK                     (0xC00U)
#define PORT_IOFLT_FLTF_SHIFT                    (10U)
/*! FLTF - Filter Selection for Input from PTF
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTF(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTF_SHIFT)) & PORT_IOFLT_FLTF_MASK)

#define PORT_IOFLT_FLTG_MASK                     (0x3000U)
#define PORT_IOFLT_FLTG_SHIFT                    (12U)
/*! FLTG - Filter Selection for Input from PTG
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTG(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTG_SHIFT)) & PORT_IOFLT_FLTG_MASK)

#define PORT_IOFLT_FLTH_MASK                     (0xC000U)
#define PORT_IOFLT_FLTH_SHIFT                    (14U)
/*! FLTH - Filter Selection for Input from PTH
 *  0b00..BUSCLK
 *  0b01..FLTDIV1
 *  0b10..FLTDIV2
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTH(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTH_SHIFT)) & PORT_IOFLT_FLTH_MASK)

#define PORT_IOFLT_FLTRST_MASK                   (0x30000U)
#define PORT_IOFLT_FLTRST_SHIFT                  (16U)
/*! FLTRST - Filter Selection for Input from RESET/IRQ
 *  0b00..No filter.
 *  0b01..Selects FLTDIV1, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b10..Selects FLTDIV2, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTRST(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTRST_SHIFT)) & PORT_IOFLT_FLTRST_MASK)

#define PORT_IOFLT_FLTKBI0_MASK                  (0xC0000U)
#define PORT_IOFLT_FLTKBI0_SHIFT                 (18U)
/*! FLTKBI0 - Filter selection for Input from KBI0
 *  0b00..No filter.
 *  0b01..Selects FLTDIV1, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b10..Selects FLTDIV2, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTKBI0(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTKBI0_SHIFT)) & PORT_IOFLT_FLTKBI0_MASK)

#define PORT_IOFLT_FLTKBI1_MASK                  (0x300000U)
#define PORT_IOFLT_FLTKBI1_SHIFT                 (20U)
/*! FLTKBI1 - Filter Selection for Input from KBI1
 *  0b00..No filter
 *  0b01..Selects FLTDIV1, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b10..Selects FLTDIV2, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTKBI1(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTKBI1_SHIFT)) & PORT_IOFLT_FLTKBI1_MASK)

#define PORT_IOFLT_FLTNMI_MASK                   (0xC00000U)
#define PORT_IOFLT_FLTNMI_SHIFT                  (22U)
/*! FLTNMI - Filter Selection for Input from NMI
 *  0b00..No filter.
 *  0b01..Selects FLTDIV1, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b10..Selects FLTDIV2, and will switch to FLTDIV3 in Stop mode automatically.
 *  0b11..FLTDIV3
 */
#define PORT_IOFLT_FLTNMI(x)                     (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTNMI_SHIFT)) & PORT_IOFLT_FLTNMI_MASK)

#define PORT_IOFLT_FLTDIV1_MASK                  (0x3000000U)
#define PORT_IOFLT_FLTDIV1_SHIFT                 (24U)
/*! FLTDIV1 - Filter Division Set 1
 *  0b00..BUSCLK/2
 *  0b01..BUSCLK/4
 *  0b10..BUSCLK/8
 *  0b11..BUSCLK/16
 */
#define PORT_IOFLT_FLTDIV1(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTDIV1_SHIFT)) & PORT_IOFLT_FLTDIV1_MASK)

#define PORT_IOFLT_FLTDIV2_MASK                  (0x1C000000U)
#define PORT_IOFLT_FLTDIV2_SHIFT                 (26U)
/*! FLTDIV2 - Filter Division Set 2
 *  0b000..BUSCLK/32
 *  0b001..BUSCLK/64
 *  0b010..BUSCLK/128
 *  0b011..BUSCLK/256
 *  0b100..BUSCLK/512
 *  0b101..BUSCLK/1024
 *  0b110..BUSCLK/2048
 *  0b111..BUSCLK/4096
 */
#define PORT_IOFLT_FLTDIV2(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTDIV2_SHIFT)) & PORT_IOFLT_FLTDIV2_MASK)

#define PORT_IOFLT_FLTDIV3_MASK                  (0xE0000000U)
#define PORT_IOFLT_FLTDIV3_SHIFT                 (29U)
/*! FLTDIV3 - Filter Division Set 3
 *  0b000..LPOCLK
 *  0b001..LPOCLK/2
 *  0b010..LPOCLK/4
 *  0b011..LPOCLK/8
 *  0b100..LPOCLK/16
 *  0b101..LPOCLK/32
 *  0b110..LPOCLK/64
 *  0b111..LPOCLK/128
 */
#define PORT_IOFLT_FLTDIV3(x)                    (((uint32_t)(((uint32_t)(x)) << PORT_IOFLT_FLTDIV3_SHIFT)) & PORT_IOFLT_FLTDIV3_MASK)
/*! @} */

/*! @name PUEL - Port Pullup Enable Low Register */
/*! @{ */

#define PORT_PUEL_PTAPE0_MASK                    (0x1U)
#define PORT_PUEL_PTAPE0_SHIFT                   (0U)
/*! PTAPE0 - Pull Enable for Port A Bit 0
 *  0b0..Pullup is disabled for port A bit 0.
 *  0b1..Pullup is enabled for port A bit 0.
 */
#define PORT_PUEL_PTAPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE0_SHIFT)) & PORT_PUEL_PTAPE0_MASK)

#define PORT_PUEL_PTAPE1_MASK                    (0x2U)
#define PORT_PUEL_PTAPE1_SHIFT                   (1U)
/*! PTAPE1 - Pull Enable for Port A Bit 1
 *  0b0..Pullup is disabled for port A bit 1.
 *  0b1..Pullup is enabled for port A bit 1.
 */
#define PORT_PUEL_PTAPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE1_SHIFT)) & PORT_PUEL_PTAPE1_MASK)

#define PORT_PUEL_PTAPE2_MASK                    (0x4U)
#define PORT_PUEL_PTAPE2_SHIFT                   (2U)
/*! PTAPE2 - Pull Enable for Port A Bit 2
 *  0b0..Pullup is disabled for port A bit 2.
 *  0b1..Pullup is enabled for port A bit 2.
 */
#define PORT_PUEL_PTAPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE2_SHIFT)) & PORT_PUEL_PTAPE2_MASK)

#define PORT_PUEL_PTAPE3_MASK                    (0x8U)
#define PORT_PUEL_PTAPE3_SHIFT                   (3U)
/*! PTAPE3 - Pull Enable for Port A Bit 3
 *  0b0..Pullup is disabled for port A bit 3.
 *  0b1..Pullup is enabled for port A bit 3.
 */
#define PORT_PUEL_PTAPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE3_SHIFT)) & PORT_PUEL_PTAPE3_MASK)

#define PORT_PUEL_PTAPE4_MASK                    (0x10U)
#define PORT_PUEL_PTAPE4_SHIFT                   (4U)
/*! PTAPE4 - Pull Enable for Port A Bit 4
 *  0b0..Pullup is disabled for port A bit 4.
 *  0b1..Pullup is enabled for port A bit 4.
 */
#define PORT_PUEL_PTAPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE4_SHIFT)) & PORT_PUEL_PTAPE4_MASK)

#define PORT_PUEL_PTAPE5_MASK                    (0x20U)
#define PORT_PUEL_PTAPE5_SHIFT                   (5U)
/*! PTAPE5 - Pull Enable for Port A Bit 5
 *  0b0..Pullup is disabled for port A bit 5.
 *  0b1..Pullup is enabled for port A bit 5.
 */
#define PORT_PUEL_PTAPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE5_SHIFT)) & PORT_PUEL_PTAPE5_MASK)

#define PORT_PUEL_PTAPE6_MASK                    (0x40U)
#define PORT_PUEL_PTAPE6_SHIFT                   (6U)
/*! PTAPE6 - Pull Enable for Port A Bit 6
 *  0b0..Pullup is disabled for port A bit 6.
 *  0b1..Pullup is enabled for port A bit 6.
 */
#define PORT_PUEL_PTAPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE6_SHIFT)) & PORT_PUEL_PTAPE6_MASK)

#define PORT_PUEL_PTAPE7_MASK                    (0x80U)
#define PORT_PUEL_PTAPE7_SHIFT                   (7U)
/*! PTAPE7 - Pull Enable for Port A Bit 7
 *  0b0..Pullup is disabled for port A bit 7.
 *  0b1..Pullup is enabled for port A bit 7.
 */
#define PORT_PUEL_PTAPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTAPE7_SHIFT)) & PORT_PUEL_PTAPE7_MASK)

#define PORT_PUEL_PTBPE0_MASK                    (0x100U)
#define PORT_PUEL_PTBPE0_SHIFT                   (8U)
/*! PTBPE0 - Pull Enable for Port B Bit 0
 *  0b0..Pullup is disabled for port B bit 0.
 *  0b1..Pullup is enabled for port B bit 0.
 */
#define PORT_PUEL_PTBPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE0_SHIFT)) & PORT_PUEL_PTBPE0_MASK)

#define PORT_PUEL_PTBPE1_MASK                    (0x200U)
#define PORT_PUEL_PTBPE1_SHIFT                   (9U)
/*! PTBPE1 - Pull Enable for Port B Bit 1
 *  0b0..Pullup is disabled for port B bit 1.
 *  0b1..Pullup is enabled for port B bit 1.
 */
#define PORT_PUEL_PTBPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE1_SHIFT)) & PORT_PUEL_PTBPE1_MASK)

#define PORT_PUEL_PTBPE2_MASK                    (0x400U)
#define PORT_PUEL_PTBPE2_SHIFT                   (10U)
/*! PTBPE2 - Pull Enable for Port B Bit 2
 *  0b0..Pullup is disabled for port B bit 2.
 *  0b1..Pullup is enabled for port B bit 2.
 */
#define PORT_PUEL_PTBPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE2_SHIFT)) & PORT_PUEL_PTBPE2_MASK)

#define PORT_PUEL_PTBPE3_MASK                    (0x800U)
#define PORT_PUEL_PTBPE3_SHIFT                   (11U)
/*! PTBPE3 - Pull Enable for Port B Bit 3
 *  0b0..Pullup is disabled for port B bit 3.
 *  0b1..Pullup is enabled for port B bit 3.
 */
#define PORT_PUEL_PTBPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE3_SHIFT)) & PORT_PUEL_PTBPE3_MASK)

#define PORT_PUEL_PTBPE4_MASK                    (0x1000U)
#define PORT_PUEL_PTBPE4_SHIFT                   (12U)
/*! PTBPE4 - Pull Enable for Port B Bit 4
 *  0b0..Pullup is disabled for port B bit 4.
 *  0b1..Pullup is enabled for port B bit 4.
 */
#define PORT_PUEL_PTBPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE4_SHIFT)) & PORT_PUEL_PTBPE4_MASK)

#define PORT_PUEL_PTBPE5_MASK                    (0x2000U)
#define PORT_PUEL_PTBPE5_SHIFT                   (13U)
/*! PTBPE5 - Pull Enable for Port B Bit 5
 *  0b0..Pullup is disabled for port B bit 5.
 *  0b1..Pullup is enabled for port B bit 5.
 */
#define PORT_PUEL_PTBPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE5_SHIFT)) & PORT_PUEL_PTBPE5_MASK)

#define PORT_PUEL_PTBPE6_MASK                    (0x4000U)
#define PORT_PUEL_PTBPE6_SHIFT                   (14U)
/*! PTBPE6 - Pull Enable for Port B Bit 6
 *  0b0..Pullup is disabled for port B bit 6.
 *  0b1..Pullup is enabled for port B bit 6.
 */
#define PORT_PUEL_PTBPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE6_SHIFT)) & PORT_PUEL_PTBPE6_MASK)

#define PORT_PUEL_PTBPE7_MASK                    (0x8000U)
#define PORT_PUEL_PTBPE7_SHIFT                   (15U)
/*! PTBPE7 - Pull Enable for Port B Bit 7
 *  0b0..Pullup is disabled for port B bit 7.
 *  0b1..Pullup is enabled for port B bit 7.
 */
#define PORT_PUEL_PTBPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTBPE7_SHIFT)) & PORT_PUEL_PTBPE7_MASK)

#define PORT_PUEL_PTCPE0_MASK                    (0x10000U)
#define PORT_PUEL_PTCPE0_SHIFT                   (16U)
/*! PTCPE0 - Pull Enable for Port C Bit 0
 *  0b0..Pullup is disabled for port C bit 0.
 *  0b1..Pullup is enabled for port C bit 0.
 */
#define PORT_PUEL_PTCPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE0_SHIFT)) & PORT_PUEL_PTCPE0_MASK)

#define PORT_PUEL_PTCPE1_MASK                    (0x20000U)
#define PORT_PUEL_PTCPE1_SHIFT                   (17U)
/*! PTCPE1 - Pull Enable for Port C Bit 1
 *  0b0..Pullup is disabled for port C bit 1.
 *  0b1..Pullup is enabled for port C bit 1.
 */
#define PORT_PUEL_PTCPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE1_SHIFT)) & PORT_PUEL_PTCPE1_MASK)

#define PORT_PUEL_PTCPE2_MASK                    (0x40000U)
#define PORT_PUEL_PTCPE2_SHIFT                   (18U)
/*! PTCPE2 - Pull Enable for Port C Bit 2
 *  0b0..Pullup is disabled for port C bit 2.
 *  0b1..Pullup is enabled for port C bit 2.
 */
#define PORT_PUEL_PTCPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE2_SHIFT)) & PORT_PUEL_PTCPE2_MASK)

#define PORT_PUEL_PTCPE3_MASK                    (0x80000U)
#define PORT_PUEL_PTCPE3_SHIFT                   (19U)
/*! PTCPE3 - Pull Enable for Port C Bit 3
 *  0b0..Pullup is disabled for port C bit 3.
 *  0b1..Pullup is enabled for port C bit 3.
 */
#define PORT_PUEL_PTCPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE3_SHIFT)) & PORT_PUEL_PTCPE3_MASK)

#define PORT_PUEL_PTCPE4_MASK                    (0x100000U)
#define PORT_PUEL_PTCPE4_SHIFT                   (20U)
/*! PTCPE4 - Pull Enable for Port C Bit 4
 *  0b0..Pullup is disabled for port C bit 4.
 *  0b1..Pullup is enabled for port C bit 4.
 */
#define PORT_PUEL_PTCPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE4_SHIFT)) & PORT_PUEL_PTCPE4_MASK)

#define PORT_PUEL_PTCPE5_MASK                    (0x200000U)
#define PORT_PUEL_PTCPE5_SHIFT                   (21U)
/*! PTCPE5 - Pull Enable for Port C Bit 5
 *  0b0..Pullup is disabled for port C bit 5.
 *  0b1..Pullup is enabled for port C bit 5.
 */
#define PORT_PUEL_PTCPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE5_SHIFT)) & PORT_PUEL_PTCPE5_MASK)

#define PORT_PUEL_PTCPE6_MASK                    (0x400000U)
#define PORT_PUEL_PTCPE6_SHIFT                   (22U)
/*! PTCPE6 - Pull Enable for Port C Bit 6
 *  0b0..Pullup is disabled for port C bit 6.
 *  0b1..Pullup is enabled for port C bit 6.
 */
#define PORT_PUEL_PTCPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE6_SHIFT)) & PORT_PUEL_PTCPE6_MASK)

#define PORT_PUEL_PTCPE7_MASK                    (0x800000U)
#define PORT_PUEL_PTCPE7_SHIFT                   (23U)
/*! PTCPE7 - Pull Enable for Port C Bit 7
 *  0b0..Pullup is disabled for port C bit 7.
 *  0b1..Pullup is enabled for port C bit 7.
 */
#define PORT_PUEL_PTCPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTCPE7_SHIFT)) & PORT_PUEL_PTCPE7_MASK)

#define PORT_PUEL_PTDPE0_MASK                    (0x1000000U)
#define PORT_PUEL_PTDPE0_SHIFT                   (24U)
/*! PTDPE0 - Pull Enable for Port D Bit 0
 *  0b0..Pullup is disabled for port D bit 0.
 *  0b1..Pullup is enabled for port D bit 0.
 */
#define PORT_PUEL_PTDPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE0_SHIFT)) & PORT_PUEL_PTDPE0_MASK)

#define PORT_PUEL_PTDPE1_MASK                    (0x2000000U)
#define PORT_PUEL_PTDPE1_SHIFT                   (25U)
/*! PTDPE1 - Pull Enable for Port D Bit 1
 *  0b0..Pullup is disabled for port D bit 1.
 *  0b1..Pullup is enabled for port D bit 1.
 */
#define PORT_PUEL_PTDPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE1_SHIFT)) & PORT_PUEL_PTDPE1_MASK)

#define PORT_PUEL_PTDPE2_MASK                    (0x4000000U)
#define PORT_PUEL_PTDPE2_SHIFT                   (26U)
/*! PTDPE2 - Pull Enable for Port D Bit 2
 *  0b0..Pullup is disabled for port D bit 2.
 *  0b1..Pullup is enabled for port D bit 2.
 */
#define PORT_PUEL_PTDPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE2_SHIFT)) & PORT_PUEL_PTDPE2_MASK)

#define PORT_PUEL_PTDPE3_MASK                    (0x8000000U)
#define PORT_PUEL_PTDPE3_SHIFT                   (27U)
/*! PTDPE3 - Pull Enable for Port D Bit 3
 *  0b0..Pullup is disabled for port D bit 3.
 *  0b1..Pullup is enabled for port D bit 3.
 */
#define PORT_PUEL_PTDPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE3_SHIFT)) & PORT_PUEL_PTDPE3_MASK)

#define PORT_PUEL_PTDPE4_MASK                    (0x10000000U)
#define PORT_PUEL_PTDPE4_SHIFT                   (28U)
/*! PTDPE4 - Pull Enable for Port D Bit 4
 *  0b0..Pullup is disabled for port D bit 4.
 *  0b1..Pullup is enabled for port D bit 4.
 */
#define PORT_PUEL_PTDPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE4_SHIFT)) & PORT_PUEL_PTDPE4_MASK)

#define PORT_PUEL_PTDPE5_MASK                    (0x20000000U)
#define PORT_PUEL_PTDPE5_SHIFT                   (29U)
/*! PTDPE5 - Pull Enable for Port D Bit 5
 *  0b0..Pullup is disabled for port D bit 5.
 *  0b1..Pullup is enabled for port D bit 5.
 */
#define PORT_PUEL_PTDPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE5_SHIFT)) & PORT_PUEL_PTDPE5_MASK)

#define PORT_PUEL_PTDPE6_MASK                    (0x40000000U)
#define PORT_PUEL_PTDPE6_SHIFT                   (30U)
/*! PTDPE6 - Pull Enable for Port D Bit 6
 *  0b0..Pullup is disabled for port D bit 6.
 *  0b1..Pullup is enabled for port D bit 6.
 */
#define PORT_PUEL_PTDPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE6_SHIFT)) & PORT_PUEL_PTDPE6_MASK)

#define PORT_PUEL_PTDPE7_MASK                    (0x80000000U)
#define PORT_PUEL_PTDPE7_SHIFT                   (31U)
/*! PTDPE7 - Pull Enable for Port D Bit 7
 *  0b0..Pullup is disabled for port D bit 7.
 *  0b1..Pullup is enabled for port D bit 7.
 */
#define PORT_PUEL_PTDPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEL_PTDPE7_SHIFT)) & PORT_PUEL_PTDPE7_MASK)
/*! @} */

/*! @name PUEH - Port Pullup Enable High Register */
/*! @{ */

#define PORT_PUEH_PTEPE0_MASK                    (0x1U)
#define PORT_PUEH_PTEPE0_SHIFT                   (0U)
/*! PTEPE0 - Pull Enable for Port E Bit 0
 *  0b0..Pullup is disabled for port E bit 0.
 *  0b1..Pullup is enabled for port E bit 0.
 */
#define PORT_PUEH_PTEPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE0_SHIFT)) & PORT_PUEH_PTEPE0_MASK)

#define PORT_PUEH_PTEPE1_MASK                    (0x2U)
#define PORT_PUEH_PTEPE1_SHIFT                   (1U)
/*! PTEPE1 - Pull Enable for Port E Bit 1
 *  0b0..Pullup is disabled for port E bit 1.
 *  0b1..Pullup is enabled for port E bit 1.
 */
#define PORT_PUEH_PTEPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE1_SHIFT)) & PORT_PUEH_PTEPE1_MASK)

#define PORT_PUEH_PTEPE2_MASK                    (0x4U)
#define PORT_PUEH_PTEPE2_SHIFT                   (2U)
/*! PTEPE2 - Pull Enable for Port E Bit 2
 *  0b0..Pullup is disabled for port E bit 2.
 *  0b1..Pullup is enabled for port E bit 2.
 */
#define PORT_PUEH_PTEPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE2_SHIFT)) & PORT_PUEH_PTEPE2_MASK)

#define PORT_PUEH_PTEPE3_MASK                    (0x8U)
#define PORT_PUEH_PTEPE3_SHIFT                   (3U)
/*! PTEPE3 - Pull Enable for Port E Bit 3
 *  0b0..Pullup is disabled for port E bit 3.
 *  0b1..Pullup is enabled for port E bit 3.
 */
#define PORT_PUEH_PTEPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE3_SHIFT)) & PORT_PUEH_PTEPE3_MASK)

#define PORT_PUEH_PTEPE4_MASK                    (0x10U)
#define PORT_PUEH_PTEPE4_SHIFT                   (4U)
/*! PTEPE4 - Pull Enable for Port E Bit 4
 *  0b0..Pullup is disabled for port E bit 4.
 *  0b1..Pullup is enabled for port E bit 4.
 */
#define PORT_PUEH_PTEPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE4_SHIFT)) & PORT_PUEH_PTEPE4_MASK)

#define PORT_PUEH_PTEPE5_MASK                    (0x20U)
#define PORT_PUEH_PTEPE5_SHIFT                   (5U)
/*! PTEPE5 - Pull Enable for Port E Bit 5
 *  0b0..Pullup is disabled for port E bit 5.
 *  0b1..Pullup is enabled for port E bit 5.
 */
#define PORT_PUEH_PTEPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE5_SHIFT)) & PORT_PUEH_PTEPE5_MASK)

#define PORT_PUEH_PTEPE6_MASK                    (0x40U)
#define PORT_PUEH_PTEPE6_SHIFT                   (6U)
/*! PTEPE6 - Pull Enable for Port E Bit 6
 *  0b0..Pullup is disabled for port E bit 6.
 *  0b1..Pullup is enabled for port E bit 6.
 */
#define PORT_PUEH_PTEPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE6_SHIFT)) & PORT_PUEH_PTEPE6_MASK)

#define PORT_PUEH_PTEPE7_MASK                    (0x80U)
#define PORT_PUEH_PTEPE7_SHIFT                   (7U)
/*! PTEPE7 - Pull Enable for Port E Bit 7
 *  0b0..Pullup is disabled for port E bit 7.
 *  0b1..Pullup is enabled for port E bit 7.
 */
#define PORT_PUEH_PTEPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTEPE7_SHIFT)) & PORT_PUEH_PTEPE7_MASK)

#define PORT_PUEH_PTFPE0_MASK                    (0x100U)
#define PORT_PUEH_PTFPE0_SHIFT                   (8U)
/*! PTFPE0 - Pull Enable for Port F Bit 0
 *  0b0..Pullup is disabled for port F bit 0.
 *  0b1..Pullup is enabled for port F bit 0.
 */
#define PORT_PUEH_PTFPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE0_SHIFT)) & PORT_PUEH_PTFPE0_MASK)

#define PORT_PUEH_PTFPE1_MASK                    (0x200U)
#define PORT_PUEH_PTFPE1_SHIFT                   (9U)
/*! PTFPE1 - Pull Enable for Port F Bit 1
 *  0b0..Pullup is disabled for port F bit 1.
 *  0b1..Pullup is enabled for port F bit 1.
 */
#define PORT_PUEH_PTFPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE1_SHIFT)) & PORT_PUEH_PTFPE1_MASK)

#define PORT_PUEH_PTFPE2_MASK                    (0x400U)
#define PORT_PUEH_PTFPE2_SHIFT                   (10U)
/*! PTFPE2 - Pull Enable for Port F Bit 2
 *  0b0..Pullup is disabled for port F bit 2.
 *  0b1..Pullup is enabled for port F bit 2.
 */
#define PORT_PUEH_PTFPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE2_SHIFT)) & PORT_PUEH_PTFPE2_MASK)

#define PORT_PUEH_PTFPE3_MASK                    (0x800U)
#define PORT_PUEH_PTFPE3_SHIFT                   (11U)
/*! PTFPE3 - Pull Enable for Port F Bit 3
 *  0b0..Pullup is disabled for port F bit 3.
 *  0b1..Pullup is enabled for port F bit 3.
 */
#define PORT_PUEH_PTFPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE3_SHIFT)) & PORT_PUEH_PTFPE3_MASK)

#define PORT_PUEH_PTFPE4_MASK                    (0x1000U)
#define PORT_PUEH_PTFPE4_SHIFT                   (12U)
/*! PTFPE4 - Pull Enable for Port F Bit 4
 *  0b0..Pullup is disabled for port F bit 4.
 *  0b1..Pullup is enabled for port F bit 4.
 */
#define PORT_PUEH_PTFPE4(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE4_SHIFT)) & PORT_PUEH_PTFPE4_MASK)

#define PORT_PUEH_PTFPE5_MASK                    (0x2000U)
#define PORT_PUEH_PTFPE5_SHIFT                   (13U)
/*! PTFPE5 - Pull Enable for Port F Bit 5
 *  0b0..Pullup is disabled for port F bit 5.
 *  0b1..Pullup is enabled for port F bit 5.
 */
#define PORT_PUEH_PTFPE5(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE5_SHIFT)) & PORT_PUEH_PTFPE5_MASK)

#define PORT_PUEH_PTFPE6_MASK                    (0x4000U)
#define PORT_PUEH_PTFPE6_SHIFT                   (14U)
/*! PTFPE6 - Pull Enable for Port F Bit 6
 *  0b0..Pullup is disabled for port F bit 6.
 *  0b1..Pullup is enabled for port F bit 6.
 */
#define PORT_PUEH_PTFPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE6_SHIFT)) & PORT_PUEH_PTFPE6_MASK)

#define PORT_PUEH_PTFPE7_MASK                    (0x8000U)
#define PORT_PUEH_PTFPE7_SHIFT                   (15U)
/*! PTFPE7 - Pull Enable for Port F Bit 7
 *  0b0..Pullup is disabled for port F bit 7.
 *  0b1..Pullup is enabled for port F bit 7.
 */
#define PORT_PUEH_PTFPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTFPE7_SHIFT)) & PORT_PUEH_PTFPE7_MASK)

#define PORT_PUEH_PTGPE0_MASK                    (0x10000U)
#define PORT_PUEH_PTGPE0_SHIFT                   (16U)
/*! PTGPE0 - Pull Enable for Port G Bit 0
 *  0b0..Pullup is disabled for port G bit 0.
 *  0b1..Pullup is enabled for port G bit 0.
 */
#define PORT_PUEH_PTGPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTGPE0_SHIFT)) & PORT_PUEH_PTGPE0_MASK)

#define PORT_PUEH_PTGPE1_MASK                    (0x20000U)
#define PORT_PUEH_PTGPE1_SHIFT                   (17U)
/*! PTGPE1 - Pull Enable for Port G Bit 1
 *  0b0..Pullup is disabled for port G bit 1.
 *  0b1..Pullup is enabled for port G bit 1.
 */
#define PORT_PUEH_PTGPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTGPE1_SHIFT)) & PORT_PUEH_PTGPE1_MASK)

#define PORT_PUEH_PTGPE2_MASK                    (0x40000U)
#define PORT_PUEH_PTGPE2_SHIFT                   (18U)
/*! PTGPE2 - Pull Enable for Port G Bit 2
 *  0b0..Pullup is disabled for port G bit 2.
 *  0b1..Pullup is enabled for port G bit 2.
 */
#define PORT_PUEH_PTGPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTGPE2_SHIFT)) & PORT_PUEH_PTGPE2_MASK)

#define PORT_PUEH_PTGPE3_MASK                    (0x80000U)
#define PORT_PUEH_PTGPE3_SHIFT                   (19U)
/*! PTGPE3 - Pull Enable for Port G Bit 3
 *  0b0..Pullup is disabled for port G bit 3.
 *  0b1..Pullup is enabled for port G bit 3.
 */
#define PORT_PUEH_PTGPE3(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTGPE3_SHIFT)) & PORT_PUEH_PTGPE3_MASK)

#define PORT_PUEH_PTHPE0_MASK                    (0x1000000U)
#define PORT_PUEH_PTHPE0_SHIFT                   (24U)
/*! PTHPE0 - Pull Enable for Port H Bit 0
 *  0b0..Pullup is disabled for port H bit 0.
 *  0b1..Pullup is enabled for port H bit 0.
 */
#define PORT_PUEH_PTHPE0(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTHPE0_SHIFT)) & PORT_PUEH_PTHPE0_MASK)

#define PORT_PUEH_PTHPE1_MASK                    (0x2000000U)
#define PORT_PUEH_PTHPE1_SHIFT                   (25U)
/*! PTHPE1 - Pull Enable for Port H Bit 1
 *  0b0..Pullup is disabled for port H bit 1.
 *  0b1..Pullup is enabled for port H bit 1.
 */
#define PORT_PUEH_PTHPE1(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTHPE1_SHIFT)) & PORT_PUEH_PTHPE1_MASK)

#define PORT_PUEH_PTHPE2_MASK                    (0x4000000U)
#define PORT_PUEH_PTHPE2_SHIFT                   (26U)
/*! PTHPE2 - Pull Enable for Port H Bit 2
 *  0b0..Pullup is disabled for port H bit 2.
 *  0b1..Pullup is enabled for port H bit 2.
 */
#define PORT_PUEH_PTHPE2(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTHPE2_SHIFT)) & PORT_PUEH_PTHPE2_MASK)

#define PORT_PUEH_PTHPE6_MASK                    (0x40000000U)
#define PORT_PUEH_PTHPE6_SHIFT                   (30U)
/*! PTHPE6 - Pull Enable for Port H Bit 6
 *  0b0..Pullup is disabled for port H bit 6.
 *  0b1..Pullup is enabled for port H bit 6.
 */
#define PORT_PUEH_PTHPE6(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTHPE6_SHIFT)) & PORT_PUEH_PTHPE6_MASK)

#define PORT_PUEH_PTHPE7_MASK                    (0x80000000U)
#define PORT_PUEH_PTHPE7_SHIFT                   (31U)
/*! PTHPE7 - Pull Enable for Port H Bit 7
 *  0b0..Pullup is disabled for port H bit 7.
 *  0b1..Pullup is enabled for port H bit 7.
 */
#define PORT_PUEH_PTHPE7(x)                      (((uint32_t)(((uint32_t)(x)) << PORT_PUEH_PTHPE7_SHIFT)) & PORT_PUEH_PTHPE7_MASK)
/*! @} */

/*! @name HDRVE - Port High Drive Enable Register */
/*! @{ */

#define PORT_HDRVE_PTB4_MASK                     (0x1U)
#define PORT_HDRVE_PTB4_SHIFT                    (0U)
/*! PTB4 - High Current Drive Capability of PTB4
 *  0b0..PTB4 is disabled to offer high current drive capability.
 *  0b1..PTB4 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTB4(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTB4_SHIFT)) & PORT_HDRVE_PTB4_MASK)

#define PORT_HDRVE_PTB5_MASK                     (0x2U)
#define PORT_HDRVE_PTB5_SHIFT                    (1U)
/*! PTB5 - High Current Drive Capability of PTB5
 *  0b0..PTB5 is disabled to offer high current drive capability.
 *  0b1..PTB5 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTB5(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTB5_SHIFT)) & PORT_HDRVE_PTB5_MASK)

#define PORT_HDRVE_PTD0_MASK                     (0x4U)
#define PORT_HDRVE_PTD0_SHIFT                    (2U)
/*! PTD0 - High Current Drive Capability of PTD0
 *  0b0..PTD0 is disabled to offer high current drive capability.
 *  0b1..PTD0 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTD0(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTD0_SHIFT)) & PORT_HDRVE_PTD0_MASK)

#define PORT_HDRVE_PTD1_MASK                     (0x8U)
#define PORT_HDRVE_PTD1_SHIFT                    (3U)
/*! PTD1 - High Current Drive Capability of PTD1
 *  0b0..PTD1 is disabled to offer high current drive capability.
 *  0b1..PTD1 is enable to offer high current drive capability.
 */
#define PORT_HDRVE_PTD1(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTD1_SHIFT)) & PORT_HDRVE_PTD1_MASK)

#define PORT_HDRVE_PTE0_MASK                     (0x10U)
#define PORT_HDRVE_PTE0_SHIFT                    (4U)
/*! PTE0 - High Current Drive Capability of PTE0
 *  0b0..PTE0 is disabled to offer high current drive capability.
 *  0b1..PTE0 is enable to offer high current drive capability.
 */
#define PORT_HDRVE_PTE0(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTE0_SHIFT)) & PORT_HDRVE_PTE0_MASK)

#define PORT_HDRVE_PTE1_MASK                     (0x20U)
#define PORT_HDRVE_PTE1_SHIFT                    (5U)
/*! PTE1 - High Current Drive Capability of PTE1
 *  0b0..PTE1 is disabled to offer high current drive capability.
 *  0b1..PTE1 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTE1(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTE1_SHIFT)) & PORT_HDRVE_PTE1_MASK)

#define PORT_HDRVE_PTH0_MASK                     (0x40U)
#define PORT_HDRVE_PTH0_SHIFT                    (6U)
/*! PTH0 - High Current Drive Capability of PTH0
 *  0b0..PTH0 is disabled to offer high current drive capability.
 *  0b1..PTH0 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTH0(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTH0_SHIFT)) & PORT_HDRVE_PTH0_MASK)

#define PORT_HDRVE_PTH1_MASK                     (0x80U)
#define PORT_HDRVE_PTH1_SHIFT                    (7U)
/*! PTH1 - High Current Drive Capability of PTH1
 *  0b0..PTH1 is disabled to offer high current drive capability.
 *  0b1..PTH1 is enabled to offer high current drive capability.
 */
#define PORT_HDRVE_PTH1(x)                       (((uint32_t)(((uint32_t)(x)) << PORT_HDRVE_PTH1_SHIFT)) & PORT_HDRVE_PTH1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


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


#endif  /* PERI_PORT_H_ */

