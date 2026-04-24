/*
** ###################################################################
**     Processors:          MCXC151VFG
**                          MCXC151VFK
**                          MCXC151VFM
**                          MCXC151VFT
**                          MCXC151VLF
**                          MCXC161VFG
**                          MCXC161VFK
**                          MCXC161VFM
**                          MCXC161VFT
**                          MCXC161VLF
**                          MCXC162VFG
**                          MCXC162VFK
**                          MCXC162VFM
**                          MCXC162VFT
**                          MCXC162VLF
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b260121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VBAT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_VBAT.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for VBAT
 *
 * CMSIS Peripheral Access Layer for VBAT
 */

#if !defined(PERI_VBAT_H_)
#define PERI_VBAT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC151VFG) || defined(CPU_MCXC151VFK) || defined(CPU_MCXC151VFM) || defined(CPU_MCXC151VFT) || defined(CPU_MCXC151VLF))
#include "MCXC151_COMMON.h"
#elif (defined(CPU_MCXC161VFG) || defined(CPU_MCXC161VFK) || defined(CPU_MCXC161VFM) || defined(CPU_MCXC161VFT) || defined(CPU_MCXC161VLF))
#include "MCXC161_COMMON.h"
#elif (defined(CPU_MCXC162VFG) || defined(CPU_MCXC162VFK) || defined(CPU_MCXC162VFM) || defined(CPU_MCXC162VFT) || defined(CPU_MCXC162VLF))
#include "MCXC162_COMMON.h"
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
   -- VBAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Peripheral_Access_Layer VBAT Peripheral Access Layer
 * @{
 */

/** VBAT - Size of Registers Arrays */
#define VBAT_WAKEUP_COUNT                         2u

/** VBAT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[252];
  __IO uint32_t OSCCTLA;                           /**< Oscillator Control A, offset: 0x100 */
       uint8_t RESERVED_1[4];
  __IO uint32_t OSCCFGA;                           /**< Oscillator Configuration A, offset: 0x108 */
       uint8_t RESERVED_2[12];
  __IO uint32_t OSCLCKA;                           /**< Oscillator Lock A, offset: 0x118 */
       uint8_t RESERVED_3[4];
  __IO uint32_t OSCCLKE;                           /**< Oscillator Clock Enable, offset: 0x120 */
       uint8_t RESERVED_4[220];
  __IO uint32_t FROCTLA;                           /**< FRO16K Control A, offset: 0x200 */
       uint8_t RESERVED_5[20];
  __IO uint32_t FROLCKA;                           /**< FRO16K Lock A, offset: 0x218 */
       uint8_t RESERVED_6[4];
  __IO uint32_t FROCLKE;                           /**< FRO16K Clock Enable, offset: 0x220 */
       uint8_t RESERVED_7[1244];
  struct {                                         /* offset: 0x700, array step: 0x8 */
    __IO uint32_t WAKEUPA;                           /**< Wakeup 0 Register A, array offset: 0x700, array step: 0x8 */
         uint8_t RESERVED_0[4];
  } WAKEUP[VBAT_WAKEUP_COUNT];
       uint8_t RESERVED_8[232];
  __IO uint32_t WAKLCKA;                           /**< Wakeup Lock A, offset: 0x7F8 */
} VBAT_Type;

/* ----------------------------------------------------------------------------
   -- VBAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Register_Masks VBAT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VBAT_VERID_FEATURE_MASK                  (0xFFFFU)
#define VBAT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number */
#define VBAT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_FEATURE_SHIFT)) & VBAT_VERID_FEATURE_MASK)

#define VBAT_VERID_MINOR_MASK                    (0xFF0000U)
#define VBAT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define VBAT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MINOR_SHIFT)) & VBAT_VERID_MINOR_MASK)

#define VBAT_VERID_MAJOR_MASK                    (0xFF000000U)
#define VBAT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define VBAT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MAJOR_SHIFT)) & VBAT_VERID_MAJOR_MASK)
/*! @} */

/*! @name OSCCTLA - Oscillator Control A */
/*! @{ */

#define VBAT_OSCCTLA_OSC_EN_MASK                 (0x1U)
#define VBAT_OSCCTLA_OSC_EN_SHIFT                (0U)
/*! OSC_EN - Crystal Oscillator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_OSCCTLA_OSC_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_OSC_EN_SHIFT)) & VBAT_OSCCTLA_OSC_EN_MASK)

#define VBAT_OSCCTLA_OSC_BYP_EN_MASK             (0x2U)
#define VBAT_OSCCTLA_OSC_BYP_EN_SHIFT            (1U)
/*! OSC_BYP_EN - Crystal Oscillator Bypass Enable
 *  0b0..Does not bypass
 *  0b1..Bypass
 */
#define VBAT_OSCCTLA_OSC_BYP_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_OSC_BYP_EN_SHIFT)) & VBAT_OSCCTLA_OSC_BYP_EN_MASK)

#define VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK        (0xCU)
#define VBAT_OSCCTLA_COARSE_AMP_GAIN_SHIFT       (2U)
/*! COARSE_AMP_GAIN - Amplifier Gain Coarse Adjustment
 *  0b00..ESR Range 0
 *  0b01..ESR Range 1
 *  0b10..ESR Range 2
 *  0b11..ESR Range 3
 */
#define VBAT_OSCCTLA_COARSE_AMP_GAIN(x)          (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_COARSE_AMP_GAIN_SHIFT)) & VBAT_OSCCTLA_COARSE_AMP_GAIN_MASK)

#define VBAT_OSCCTLA_CAP_SEL_EN_MASK             (0x80U)
#define VBAT_OSCCTLA_CAP_SEL_EN_SHIFT            (7U)
/*! CAP_SEL_EN - Crystal Load Capacitance Selection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_OSCCTLA_CAP_SEL_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_CAP_SEL_EN_SHIFT)) & VBAT_OSCCTLA_CAP_SEL_EN_MASK)

#define VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK          (0xF00U)
#define VBAT_OSCCTLA_EXTAL_CAP_SEL_SHIFT         (8U)
/*! EXTAL_CAP_SEL - Crystal Load Capacitance Selection
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define VBAT_OSCCTLA_EXTAL_CAP_SEL(x)            (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_EXTAL_CAP_SEL_SHIFT)) & VBAT_OSCCTLA_EXTAL_CAP_SEL_MASK)

#define VBAT_OSCCTLA_XTAL_CAP_SEL_MASK           (0xF000U)
#define VBAT_OSCCTLA_XTAL_CAP_SEL_SHIFT          (12U)
/*! XTAL_CAP_SEL - Crystal Load Capacitance Selection
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define VBAT_OSCCTLA_XTAL_CAP_SEL(x)             (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_XTAL_CAP_SEL_SHIFT)) & VBAT_OSCCTLA_XTAL_CAP_SEL_MASK)

#define VBAT_OSCCTLA_MODE_EN_MASK                (0x30000U)
#define VBAT_OSCCTLA_MODE_EN_SHIFT               (16U)
/*! MODE_EN - Mode Enable
 *  0b00..Normal mode
 *  0b01..Startup mode
 *  0b11..Low power mode
 */
#define VBAT_OSCCTLA_MODE_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_MODE_EN_SHIFT)) & VBAT_OSCCTLA_MODE_EN_MASK)

#define VBAT_OSCCTLA_SUPPLY_DET_MASK             (0xC0000U)
#define VBAT_OSCCTLA_SUPPLY_DET_SHIFT            (18U)
/*! SUPPLY_DET - Supply Detector Trim
 *  0b00..VBAT supply is less than 3V
 *  0b01..VBAT supply is greater than 3V
 */
#define VBAT_OSCCTLA_SUPPLY_DET(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCTLA_SUPPLY_DET_SHIFT)) & VBAT_OSCCTLA_SUPPLY_DET_MASK)
/*! @} */

/*! @name OSCCFGA - Oscillator Configuration A */
/*! @{ */

#define VBAT_OSCCFGA_CMP_TRIM_MASK               (0x3U)
#define VBAT_OSCCFGA_CMP_TRIM_SHIFT              (0U)
/*! CMP_TRIM - Comparator Trim
 *  0b00..760 mV
 *  0b01..770 mV
 *  0b11..740 mV
 */
#define VBAT_OSCCFGA_CMP_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CMP_TRIM_SHIFT)) & VBAT_OSCCFGA_CMP_TRIM_MASK)

#define VBAT_OSCCFGA_CAP2_TRIM_MASK              (0x4U)
#define VBAT_OSCCFGA_CAP2_TRIM_SHIFT             (2U)
/*! CAP2_TRIM - CAP2_TRIM */
#define VBAT_OSCCFGA_CAP2_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CAP2_TRIM_SHIFT)) & VBAT_OSCCFGA_CAP2_TRIM_MASK)

#define VBAT_OSCCFGA_DLY_TRIM_MASK               (0x78U)
#define VBAT_OSCCFGA_DLY_TRIM_SHIFT              (3U)
/*! DLY_TRIM - Delay Trim
 *  0b0000..P current 9(nA) and N Current 6(nA)
 *  0b0001..P current 13(nA) and N Current 6(nA)
 *  0b0011..P current 4(nA) and N Current 6(nA)
 *  0b0100..P current 9(nA) and N Current 4(nA)
 *  0b0101..P current 13(nA) and N Current 4(nA)
 *  0b0111..P current 4(nA) and N Current 4(nA)
 *  0b1000..P current 9(nA) and N Current 2(nA)
 *  0b1001..P current 13(nA) and N Current 2(nA)
 *  0b1011..P current 4(nA) and N Current 2(nA)
 */
#define VBAT_OSCCFGA_DLY_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_DLY_TRIM_SHIFT)) & VBAT_OSCCFGA_DLY_TRIM_MASK)

#define VBAT_OSCCFGA_CAP_TRIM_MASK               (0x180U)
#define VBAT_OSCCFGA_CAP_TRIM_SHIFT              (7U)
/*! CAP_TRIM - Capacitor Trim
 *  0b00..Default (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 00 )
 *  0b01..-1us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 01)
 *  0b10..-2us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 10) or or +3.5us (when CAP2_TRIM = 1 and CAP_TRIM[1:0] = 10)
 *  0b11..-2.5us (when CAP2_TRIM = 0 and CAP_TRIM[1:0] = 11) or +1us (when CAP2_TRIM = 1 and CAP_TRIM[1:0] = 11)
 */
#define VBAT_OSCCFGA_CAP_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_CAP_TRIM_SHIFT)) & VBAT_OSCCFGA_CAP_TRIM_MASK)

#define VBAT_OSCCFGA_INIT_TRIM_MASK              (0xE00U)
#define VBAT_OSCCFGA_INIT_TRIM_SHIFT             (9U)
/*! INIT_TRIM - Initialization Trim
 *  0b000..8 s
 *  0b001..4 s
 *  0b010..2 s
 *  0b011..1 s
 *  0b100..0.5 s
 *  0b101..0.25 s
 *  0b110..0.125 s
 *  0b111..0.5 ms
 */
#define VBAT_OSCCFGA_INIT_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCFGA_INIT_TRIM_SHIFT)) & VBAT_OSCCFGA_INIT_TRIM_MASK)
/*! @} */

/*! @name OSCLCKA - Oscillator Lock A */
/*! @{ */

#define VBAT_OSCLCKA_LOCK_MASK                   (0x1U)
#define VBAT_OSCLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_OSCLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_OSCLCKA_LOCK_SHIFT)) & VBAT_OSCLCKA_LOCK_MASK)
/*! @} */

/*! @name OSCCLKE - Oscillator Clock Enable */
/*! @{ */

#define VBAT_OSCCLKE_CLKE_MASK                   (0x3U)
#define VBAT_OSCCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_OSCCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_OSCCLKE_CLKE_SHIFT)) & VBAT_OSCCLKE_CLKE_MASK)
/*! @} */

/*! @name FROCTLA - FRO16K Control A */
/*! @{ */

#define VBAT_FROCTLA_FRO_EN_MASK                 (0x1U)
#define VBAT_FROCTLA_FRO_EN_SHIFT                (0U)
/*! FRO_EN - FRO16K Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_FROCTLA_FRO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_FROCTLA_FRO_EN_SHIFT)) & VBAT_FROCTLA_FRO_EN_MASK)
/*! @} */

/*! @name FROLCKA - FRO16K Lock A */
/*! @{ */

#define VBAT_FROLCKA_LOCK_MASK                   (0x1U)
#define VBAT_FROLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_FROLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROLCKA_LOCK_SHIFT)) & VBAT_FROLCKA_LOCK_MASK)
/*! @} */

/*! @name FROCLKE - FRO16K Clock Enable */
/*! @{ */

#define VBAT_FROCLKE_CLKE_MASK                   (0x3U)
#define VBAT_FROCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_FROCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROCLKE_CLKE_SHIFT)) & VBAT_FROCLKE_CLKE_MASK)
/*! @} */

/*! @name WAKEUP_WAKEUPA - Wakeup 0 Register A */
/*! @{ */

#define VBAT_WAKEUP_WAKEUPA_REG_MASK             (0xFFFFFFFFU)
#define VBAT_WAKEUP_WAKEUPA_REG_SHIFT            (0U)
/*! REG - Register */
#define VBAT_WAKEUP_WAKEUPA_REG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKEUP_WAKEUPA_REG_SHIFT)) & VBAT_WAKEUP_WAKEUPA_REG_MASK)
/*! @} */

/* The count of VBAT_WAKEUP_WAKEUPA */
#define VBAT_WAKEUP_WAKEUPA_COUNT                (2U)

/*! @name WAKLCKA - Wakeup Lock A */
/*! @{ */

#define VBAT_WAKLCKA_LOCK_MASK                   (0x1U)
#define VBAT_WAKLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Lock is disabled
 *  0b1..Lock is enabled
 */
#define VBAT_WAKLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_WAKLCKA_LOCK_SHIFT)) & VBAT_WAKLCKA_LOCK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VBAT_Register_Masks */


/*!
 * @}
 */ /* end of group VBAT_Peripheral_Access_Layer */


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


#endif  /* PERI_VBAT_H_ */

