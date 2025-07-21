/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPM
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
 * @file PERI_SPM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPM
 *
 * CMSIS Peripheral Access Layer for SPM
 */

#if !defined(PERI_SPM_H_)
#define PERI_SPM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- SPM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPM_Peripheral_Access_Layer SPM Peripheral Access Layer
 * @{
 */

/** SPM - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __I  uint32_t RSR;                               /**< Regulator Status Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t RCTRL;                             /**< Run Control Register, offset: 0x10 */
  __IO uint32_t LPCTRL;                            /**< Low Power Control Register, offset: 0x14 */
       uint8_t RESERVED_2[232];
  __IO uint32_t CORERCNFG;                         /**< CORE LDO RUN Configuration Register, offset: 0x100 */
  __IO uint32_t CORELPCNFG;                        /**< CORE LDO Low Power Configuration register, offset: 0x104 */
  __IO uint32_t CORESC;                            /**< Core LDO Status And Control register, offset: 0x108 */
  __IO uint32_t LVDSC1;                            /**< Low Voltage Detect Status and Control 1 register, offset: 0x10C */
  __IO uint32_t LVDSC2;                            /**< Low Voltage Detect Status and Control 2 register, offset: 0x110 */
  __IO uint32_t HVDSC1;                            /**< High Voltage Detect Status And Control 1 register, offset: 0x114 */
       uint8_t RESERVED_3[232];
  __IO uint32_t AUXLDOLPCNFG;                      /**< AUX LDO Low Power Configuration register, offset: 0x200 */
  __IO uint32_t AUXLDOSC;                          /**< AUX LDO Status And Control register, offset: 0x204 */
       uint8_t RESERVED_4[252];
  __IO uint32_t DCDCSC;                            /**< DCDC Status Control Register, offset: 0x304 */
       uint8_t RESERVED_5[4];
  __IO uint32_t DCDCC1;                            /**< DCDC Control Register 1, offset: 0x30C */
  __IO uint32_t DCDCC2;                            /**< DCDC Control Register 2, offset: 0x310 */
  __IO uint32_t DCDCC3;                            /**< DCDC Control Register 3, offset: 0x314 */
  __IO uint32_t DCDCC4;                            /**< DCDC Control Register 4, offset: 0x318 */
       uint8_t RESERVED_6[4];
  __IO uint32_t DCDCC6;                            /**< DCDC Control Register 6, offset: 0x320 */
       uint8_t RESERVED_7[232];
  __IO uint32_t LPREQPINCNTRL;                     /**< LP Request Pin Control Register, offset: 0x40C */
} SPM_Type;

/* ----------------------------------------------------------------------------
   -- SPM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPM_Register_Masks SPM Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define SPM_VERID_FEATURE_MASK                   (0xFFFFU)
#define SPM_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented.
 */
#define SPM_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << SPM_VERID_FEATURE_SHIFT)) & SPM_VERID_FEATURE_MASK)

#define SPM_VERID_MINOR_MASK                     (0xFF0000U)
#define SPM_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - MINOR */
#define SPM_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << SPM_VERID_MINOR_SHIFT)) & SPM_VERID_MINOR_MASK)

#define SPM_VERID_MAJOR_MASK                     (0xFF000000U)
#define SPM_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - MAJOR */
#define SPM_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << SPM_VERID_MAJOR_SHIFT)) & SPM_VERID_MAJOR_MASK)
/*! @} */

/*! @name RSR - Regulator Status Register */
/*! @{ */

#define SPM_RSR_REGSEL_MASK                      (0x7U)
#define SPM_RSR_REGSEL_SHIFT                     (0U)
/*! REGSEL - REGSEL */
#define SPM_RSR_REGSEL(x)                        (((uint32_t)(((uint32_t)(x)) << SPM_RSR_REGSEL_SHIFT)) & SPM_RSR_REGSEL_MASK)

#define SPM_RSR_MCUPMSTAT_MASK                   (0x1F0000U)
#define SPM_RSR_MCUPMSTAT_SHIFT                  (16U)
/*! MCUPMSTAT - MCU Power Mode Status
 *  0b00000..Reserved
 *  0b00001..Last Low Power mode is STOP.
 *  0b00010..Last Low Power mode is VLPS.
 *  0b00100..Last Low Power mode is LLS.
 *  0b01000..Last Low Power mode is VLLS23.
 *  0b10000..Last Low Power mode is VLLS01.
 */
#define SPM_RSR_MCUPMSTAT(x)                     (((uint32_t)(((uint32_t)(x)) << SPM_RSR_MCUPMSTAT_SHIFT)) & SPM_RSR_MCUPMSTAT_MASK)
/*! @} */

/*! @name RCTRL - Run Control Register */
/*! @{ */

#define SPM_RCTRL_REGSEL_MASK                    (0x7U)
#define SPM_RCTRL_REGSEL_SHIFT                   (0U)
/*! REGSEL - REGSEL */
#define SPM_RCTRL_REGSEL(x)                      (((uint32_t)(((uint32_t)(x)) << SPM_RCTRL_REGSEL_SHIFT)) & SPM_RCTRL_REGSEL_MASK)
/*! @} */

/*! @name LPCTRL - Low Power Control Register */
/*! @{ */

#define SPM_LPCTRL_REGSEL_MASK                   (0x7U)
#define SPM_LPCTRL_REGSEL_SHIFT                  (0U)
/*! REGSEL - REGSEL */
#define SPM_LPCTRL_REGSEL(x)                     (((uint32_t)(((uint32_t)(x)) << SPM_LPCTRL_REGSEL_SHIFT)) & SPM_LPCTRL_REGSEL_MASK)
/*! @} */

/*! @name CORERCNFG - CORE LDO RUN Configuration Register */
/*! @{ */

#define SPM_CORERCNFG_VDDIOVDDMEN_MASK           (0x10000U)
#define SPM_CORERCNFG_VDDIOVDDMEN_SHIFT          (16U)
/*! VDDIOVDDMEN - VDDIOVDDMEN
 *  0b0..VDDIO voltage monitor disabled in run modes.
 *  0b1..VDDIO voltage monitor enabled in run modes.
 */
#define SPM_CORERCNFG_VDDIOVDDMEN(x)             (((uint32_t)(((uint32_t)(x)) << SPM_CORERCNFG_VDDIOVDDMEN_SHIFT)) & SPM_CORERCNFG_VDDIOVDDMEN_MASK)

#define SPM_CORERCNFG_USBVDDMEN_MASK             (0x20000U)
#define SPM_CORERCNFG_USBVDDMEN_SHIFT            (17U)
/*! USBVDDMEN - USBVDDMEN
 *  0b0..USB voltage monitor disabled in run modes.
 *  0b1..USB voltage monitor enabled in run modes.
 */
#define SPM_CORERCNFG_USBVDDMEN(x)               (((uint32_t)(((uint32_t)(x)) << SPM_CORERCNFG_USBVDDMEN_SHIFT)) & SPM_CORERCNFG_USBVDDMEN_MASK)

#define SPM_CORERCNFG_RTCVDDMEN_MASK             (0x40000U)
#define SPM_CORERCNFG_RTCVDDMEN_SHIFT            (18U)
/*! RTCVDDMEN - RTCVDDMEN
 *  0b0..RTC voltage monitor disabled in run modes.
 *  0b1..RTC voltage monitor enabled in run modes.
 */
#define SPM_CORERCNFG_RTCVDDMEN(x)               (((uint32_t)(((uint32_t)(x)) << SPM_CORERCNFG_RTCVDDMEN_SHIFT)) & SPM_CORERCNFG_RTCVDDMEN_MASK)
/*! @} */

/*! @name CORELPCNFG - CORE LDO Low Power Configuration register */
/*! @{ */

#define SPM_CORELPCNFG_LPSEL_MASK                (0x2U)
#define SPM_CORELPCNFG_LPSEL_SHIFT               (1U)
/*! LPSEL - LPSEL
 *  0b0..Core LDO enters low power state in VLP/Stop modes.
 *  0b1..Core LDO remains in high power state in VLP/Stop modes. If LPSEL = 1 in a low power mode then BGEN must also be set to 1.
 */
#define SPM_CORELPCNFG_LPSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_LPSEL_SHIFT)) & SPM_CORELPCNFG_LPSEL_MASK)

#define SPM_CORELPCNFG_BGEN_MASK                 (0x4U)
#define SPM_CORELPCNFG_BGEN_SHIFT                (2U)
/*! BGEN - Bandgap Enable In Low Power Mode Operation
 *  0b0..Bandgap is disabled in STOP/VLP/LLS and VLLS modes.
 *  0b1..Bandgap remains enabled in STOP/VLP/LLS and VLLS modes.
 */
#define SPM_CORELPCNFG_BGEN(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_BGEN_SHIFT)) & SPM_CORELPCNFG_BGEN_MASK)

#define SPM_CORELPCNFG_BGBEN_MASK                (0x8U)
#define SPM_CORELPCNFG_BGBEN_SHIFT               (3U)
/*! BGBEN - Bandgap Buffer Enable
 *  0b0..Bandgap buffer not enabled
 *  0b1..Bandgap buffer enabled BGEN must be set when this bit is also set.
 */
#define SPM_CORELPCNFG_BGBEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_BGBEN_SHIFT)) & SPM_CORELPCNFG_BGBEN_MASK)

#define SPM_CORELPCNFG_BGBDS_MASK                (0x10U)
#define SPM_CORELPCNFG_BGBDS_SHIFT               (4U)
/*! BGBDS - Bandgap Buffer Drive Select
 *  0b0..Low Drive
 *  0b1..High Drive
 */
#define SPM_CORELPCNFG_BGBDS(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_BGBDS_SHIFT)) & SPM_CORELPCNFG_BGBDS_MASK)

#define SPM_CORELPCNFG_LPOEN_MASK                (0x80U)
#define SPM_CORELPCNFG_LPOEN_SHIFT               (7U)
/*! LPOEN - LPO Enabled
 *  0b0..LPO is disabled in VLLS0/1 modes.
 *  0b1..LPO remains enabled in VLLS0/1 modes.
 */
#define SPM_CORELPCNFG_LPOEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_LPOEN_SHIFT)) & SPM_CORELPCNFG_LPOEN_MASK)

#define SPM_CORELPCNFG_POREN_MASK                (0x100U)
#define SPM_CORELPCNFG_POREN_SHIFT               (8U)
/*! POREN - POR Enabled
 *  0b0..POR brownout is disabled in VLLS0/1 mode.
 *  0b1..POR brownout remains enabled in VLLS0/1 mode.
 */
#define SPM_CORELPCNFG_POREN(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_POREN_SHIFT)) & SPM_CORELPCNFG_POREN_MASK)

#define SPM_CORELPCNFG_LVDEN_MASK                (0x200U)
#define SPM_CORELPCNFG_LVDEN_SHIFT               (9U)
/*! LVDEN - LVD Enabled
 *  0b0..LVD/HVD is disabled in low power modes.
 *  0b1..LVD/HVD remains enabled in low power modes. BGEN must be set when this bit is also set.
 */
#define SPM_CORELPCNFG_LVDEN(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_LVDEN_SHIFT)) & SPM_CORELPCNFG_LVDEN_MASK)

#define SPM_CORELPCNFG_LPHIDRIVE_MASK            (0x4000U)
#define SPM_CORELPCNFG_LPHIDRIVE_SHIFT           (14U)
/*! LPHIDRIVE - LPHIDRIVE
 *  0b0..High Drive disabled.
 *  0b1..High Drive enabled.
 */
#define SPM_CORELPCNFG_LPHIDRIVE(x)              (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_LPHIDRIVE_SHIFT)) & SPM_CORELPCNFG_LPHIDRIVE_MASK)

#define SPM_CORELPCNFG_ALLREFEN_MASK             (0x8000U)
#define SPM_CORELPCNFG_ALLREFEN_SHIFT            (15U)
/*! ALLREFEN - All Reference Enable. This bit only has an affect in VLLS0/1.
 *  0b0..All references are disabled in VLLS0/1.
 *  0b1..All references are enabled in VLLS0/1.
 */
#define SPM_CORELPCNFG_ALLREFEN(x)               (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_ALLREFEN_SHIFT)) & SPM_CORELPCNFG_ALLREFEN_MASK)

#define SPM_CORELPCNFG_VDDIOVDDMEN_MASK          (0x10000U)
#define SPM_CORELPCNFG_VDDIOVDDMEN_SHIFT         (16U)
/*! VDDIOVDDMEN - VDDIOVDDMEN
 *  0b0..VDDIO voltage monitor disabled in lp modes.
 *  0b1..VDDIO voltage monitor enabled in lp modes. Note: voltage monitor is always disabled in VLLS0/1 modes.
 */
#define SPM_CORELPCNFG_VDDIOVDDMEN(x)            (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_VDDIOVDDMEN_SHIFT)) & SPM_CORELPCNFG_VDDIOVDDMEN_MASK)

#define SPM_CORELPCNFG_USBVDDMEN_MASK            (0x20000U)
#define SPM_CORELPCNFG_USBVDDMEN_SHIFT           (17U)
/*! USBVDDMEN - USBVDDMEN
 *  0b0..USB voltage monitor disabled in lp modes.
 *  0b1..USB voltage monitor enabled in lp modes. Note: voltage monitor is always disabled in VLLS0/1 modes.
 */
#define SPM_CORELPCNFG_USBVDDMEN(x)              (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_USBVDDMEN_SHIFT)) & SPM_CORELPCNFG_USBVDDMEN_MASK)

#define SPM_CORELPCNFG_RTCVDDMEN_MASK            (0x40000U)
#define SPM_CORELPCNFG_RTCVDDMEN_SHIFT           (18U)
/*! RTCVDDMEN - RTCVDDMEN
 *  0b0..RTC voltage monitor disabled in lp modes.
 *  0b1..RTC voltage monitor enabled in lp modes. Note: voltage monitor is always disabled in VLLS0/1 modes.
 */
#define SPM_CORELPCNFG_RTCVDDMEN(x)              (((uint32_t)(((uint32_t)(x)) << SPM_CORELPCNFG_RTCVDDMEN_SHIFT)) & SPM_CORELPCNFG_RTCVDDMEN_MASK)
/*! @} */

/*! @name CORESC - Core LDO Status And Control register */
/*! @{ */

#define SPM_CORESC_VSEL_OFFSET_MASK              (0x2U)
#define SPM_CORESC_VSEL_OFFSET_SHIFT             (1U)
/*! VSEL_OFFSET - Voltage Offset Select
 *  0b0..Core LDO offset not applied.
 *  0b1..Core LDO offset is applied.
 */
#define SPM_CORESC_VSEL_OFFSET(x)                (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_VSEL_OFFSET_SHIFT)) & SPM_CORESC_VSEL_OFFSET_MASK)

#define SPM_CORESC_REGONS_MASK                   (0x4U)
#define SPM_CORESC_REGONS_SHIFT                  (2U)
/*! REGONS - CORE LDO Regulator in Run Regulation Status
 *  0b0..Regulator is in low power state or in transition to/from it.
 *  0b1..Regulator is in high power state.
 */
#define SPM_CORESC_REGONS(x)                     (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_REGONS_SHIFT)) & SPM_CORESC_REGONS_MASK)

#define SPM_CORESC_ACKISO_MASK                   (0x8U)
#define SPM_CORESC_ACKISO_SHIFT                  (3U)
/*! ACKISO - Acknowledge Isolation
 *  0b0..Peripherals and I/O pads are in normal run state.
 *  0b1..Certain peripherals and I/O pads are in a isolated and latched state.
 */
#define SPM_CORESC_ACKISO(x)                     (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_ACKISO_SHIFT)) & SPM_CORESC_ACKISO_MASK)

#define SPM_CORESC_TRIM_MASK                     (0x3F00U)
#define SPM_CORESC_TRIM_SHIFT                    (8U)
/*! TRIM - Core LDO Regulator TRIM value */
#define SPM_CORESC_TRIM(x)                       (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_TRIM_SHIFT)) & SPM_CORESC_TRIM_MASK)

#define SPM_CORESC_VDDIOOVRIDE_MASK              (0x10000U)
#define SPM_CORESC_VDDIOOVRIDE_SHIFT             (16U)
/*! VDDIOOVRIDE - VDDIOOVRIDE
 *  0b0..VDDIOOK status set to 1'b0.
 *  0b1..VDDIOOK status set to 1'b1.
 */
#define SPM_CORESC_VDDIOOVRIDE(x)                (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_VDDIOOVRIDE_SHIFT)) & SPM_CORESC_VDDIOOVRIDE_MASK)

#define SPM_CORESC_USBOVRIDE_MASK                (0x20000U)
#define SPM_CORESC_USBOVRIDE_SHIFT               (17U)
/*! USBOVRIDE - USBOVRIDE
 *  0b0..USBVDDOK status set to 1'b0.
 *  0b1..USBVDDOK status set to 1'b1.
 */
#define SPM_CORESC_USBOVRIDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_USBOVRIDE_SHIFT)) & SPM_CORESC_USBOVRIDE_MASK)

#define SPM_CORESC_RTCOVRIDE_MASK                (0x40000U)
#define SPM_CORESC_RTCOVRIDE_SHIFT               (18U)
/*! RTCOVRIDE - RTCOVRIDE
 *  0b0..RTCVDDOK status set to 1'b0.
 *  0b1..RTCVDDOK status set to 1'b1.
 */
#define SPM_CORESC_RTCOVRIDE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_RTCOVRIDE_SHIFT)) & SPM_CORESC_RTCOVRIDE_MASK)

#define SPM_CORESC_VDDIOOK_MASK                  (0x1000000U)
#define SPM_CORESC_VDDIOOK_SHIFT                 (24U)
/*! VDDIOOK - VDDIOOK */
#define SPM_CORESC_VDDIOOK(x)                    (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_VDDIOOK_SHIFT)) & SPM_CORESC_VDDIOOK_MASK)

#define SPM_CORESC_USBVDDOK_MASK                 (0x2000000U)
#define SPM_CORESC_USBVDDOK_SHIFT                (25U)
/*! USBVDDOK - USBVDDOK */
#define SPM_CORESC_USBVDDOK(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_USBVDDOK_SHIFT)) & SPM_CORESC_USBVDDOK_MASK)

#define SPM_CORESC_RTCVDDOK_MASK                 (0x4000000U)
#define SPM_CORESC_RTCVDDOK_SHIFT                (26U)
/*! RTCVDDOK - RTCVDDOK */
#define SPM_CORESC_RTCVDDOK(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_CORESC_RTCVDDOK_SHIFT)) & SPM_CORESC_RTCVDDOK_MASK)
/*! @} */

/*! @name LVDSC1 - Low Voltage Detect Status and Control 1 register */
/*! @{ */

#define SPM_LVDSC1_COREVDD_LVDRE_MASK            (0x10U)
#define SPM_LVDSC1_COREVDD_LVDRE_SHIFT           (4U)
/*! COREVDD_LVDRE - Core Low-Voltage Detect Reset Enable
 *  0b0..COREVDD_LVDF does not generate hardware resets
 *  0b1..Force an MCU reset when CORE_LVDF = 1
 */
#define SPM_LVDSC1_COREVDD_LVDRE(x)              (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_COREVDD_LVDRE_SHIFT)) & SPM_LVDSC1_COREVDD_LVDRE_MASK)

#define SPM_LVDSC1_COREVDD_LVDIE_MASK            (0x20U)
#define SPM_LVDSC1_COREVDD_LVDIE_SHIFT           (5U)
/*! COREVDD_LVDIE - Low-Voltage Detect Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when LVDF = 1
 */
#define SPM_LVDSC1_COREVDD_LVDIE(x)              (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_COREVDD_LVDIE_SHIFT)) & SPM_LVDSC1_COREVDD_LVDIE_MASK)

#define SPM_LVDSC1_COREVDD_LVDACK_MASK           (0x40U)
#define SPM_LVDSC1_COREVDD_LVDACK_SHIFT          (6U)
/*! COREVDD_LVDACK - Low-Voltage Detect Acknowledge */
#define SPM_LVDSC1_COREVDD_LVDACK(x)             (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_COREVDD_LVDACK_SHIFT)) & SPM_LVDSC1_COREVDD_LVDACK_MASK)

#define SPM_LVDSC1_COREVDD_LVDF_MASK             (0x80U)
#define SPM_LVDSC1_COREVDD_LVDF_SHIFT            (7U)
/*! COREVDD_LVDF - Low-Voltage Detect Flag
 *  0b0..Low-voltage event not detected
 *  0b1..Low-voltage event detected
 */
#define SPM_LVDSC1_COREVDD_LVDF(x)               (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_COREVDD_LVDF_SHIFT)) & SPM_LVDSC1_COREVDD_LVDF_MASK)

#define SPM_LVDSC1_VDD_LVDV_MASK                 (0x30000U)
#define SPM_LVDSC1_VDD_LVDV_SHIFT                (16U)
/*! VDD_LVDV - VDD Low-Voltage Detect Voltage Select
 *  0b00..Low trip point selected (V LVD = V LVDL )
 *  0b01..High trip point selected (V LVD = V LVDH )
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define SPM_LVDSC1_VDD_LVDV(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_VDD_LVDV_SHIFT)) & SPM_LVDSC1_VDD_LVDV_MASK)

#define SPM_LVDSC1_VDD_LVDRE_MASK                (0x100000U)
#define SPM_LVDSC1_VDD_LVDRE_SHIFT               (20U)
/*! VDD_LVDRE - VDD Low-Voltage Detect Reset Enable
 *  0b0..VDD_LVDF does not generate hardware resets
 *  0b1..Force an MCU reset when VDD_LVDF = 1
 */
#define SPM_LVDSC1_VDD_LVDRE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_VDD_LVDRE_SHIFT)) & SPM_LVDSC1_VDD_LVDRE_MASK)

#define SPM_LVDSC1_VDD_LVDIE_MASK                (0x200000U)
#define SPM_LVDSC1_VDD_LVDIE_SHIFT               (21U)
/*! VDD_LVDIE - VDD Low-Voltage Detect Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when VDD_LVDF = 1
 */
#define SPM_LVDSC1_VDD_LVDIE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_VDD_LVDIE_SHIFT)) & SPM_LVDSC1_VDD_LVDIE_MASK)

#define SPM_LVDSC1_VDD_LVDACK_MASK               (0x400000U)
#define SPM_LVDSC1_VDD_LVDACK_SHIFT              (22U)
/*! VDD_LVDACK - VDD Low-Voltage Detect Acknowledge */
#define SPM_LVDSC1_VDD_LVDACK(x)                 (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_VDD_LVDACK_SHIFT)) & SPM_LVDSC1_VDD_LVDACK_MASK)

#define SPM_LVDSC1_VDD_LVDF_MASK                 (0x800000U)
#define SPM_LVDSC1_VDD_LVDF_SHIFT                (23U)
/*! VDD_LVDF - VDD Low-Voltage Detect Flag
 *  0b0..Low-voltage event not detected
 *  0b1..Low-voltage event detected
 */
#define SPM_LVDSC1_VDD_LVDF(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC1_VDD_LVDF_SHIFT)) & SPM_LVDSC1_VDD_LVDF_MASK)
/*! @} */

/*! @name LVDSC2 - Low Voltage Detect Status and Control 2 register */
/*! @{ */

#define SPM_LVDSC2_VDD_LVWV_MASK                 (0x30000U)
#define SPM_LVDSC2_VDD_LVWV_SHIFT                (16U)
/*! VDD_LVWV - VDD Low-Voltage Warning Voltage Select
 *  0b00..Low trip point selected (V LVW = VLVW1)
 *  0b01..Mid 1 trip point selected (V LVW = VLVW2)
 *  0b10..Mid 2 trip point selected (V LVW = VLVW3)
 *  0b11..High trip point selected (V LVW = VLVW4)
 */
#define SPM_LVDSC2_VDD_LVWV(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC2_VDD_LVWV_SHIFT)) & SPM_LVDSC2_VDD_LVWV_MASK)

#define SPM_LVDSC2_VDD_LVWIE_MASK                (0x200000U)
#define SPM_LVDSC2_VDD_LVWIE_SHIFT               (21U)
/*! VDD_LVWIE - VDD Low-Voltage Warning Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when VDD_LVWF = 1
 */
#define SPM_LVDSC2_VDD_LVWIE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC2_VDD_LVWIE_SHIFT)) & SPM_LVDSC2_VDD_LVWIE_MASK)

#define SPM_LVDSC2_VDD_LVWACK_MASK               (0x400000U)
#define SPM_LVDSC2_VDD_LVWACK_SHIFT              (22U)
/*! VDD_LVWACK - VDD Low-Voltage Warning Acknowledge */
#define SPM_LVDSC2_VDD_LVWACK(x)                 (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC2_VDD_LVWACK_SHIFT)) & SPM_LVDSC2_VDD_LVWACK_MASK)

#define SPM_LVDSC2_VDD_LVWF_MASK                 (0x800000U)
#define SPM_LVDSC2_VDD_LVWF_SHIFT                (23U)
/*! VDD_LVWF - VDD Low-Voltage Warning Flag
 *  0b0..Low-voltage warning event not detected
 *  0b1..Low-voltage warning event detected
 */
#define SPM_LVDSC2_VDD_LVWF(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_LVDSC2_VDD_LVWF_SHIFT)) & SPM_LVDSC2_VDD_LVWF_MASK)
/*! @} */

/*! @name HVDSC1 - High Voltage Detect Status And Control 1 register */
/*! @{ */

#define SPM_HVDSC1_VDD_HVDV_MASK                 (0x10000U)
#define SPM_HVDSC1_VDD_HVDV_SHIFT                (16U)
/*! VDD_HVDV - VDD High-Voltage Detect Voltage Select
 *  0b0..Low trip point selected (V VDD = V VDD_HVDL )
 *  0b1..High trip point selected (V VDD = V VDD_HVDH )
 */
#define SPM_HVDSC1_VDD_HVDV(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_HVDSC1_VDD_HVDV_SHIFT)) & SPM_HVDSC1_VDD_HVDV_MASK)

#define SPM_HVDSC1_VDD_HVDRE_MASK                (0x100000U)
#define SPM_HVDSC1_VDD_HVDRE_SHIFT               (20U)
/*! VDD_HVDRE - VDD High-Voltage Detect Reset Enable
 *  0b0..VDD HVDF does not generate hardware resets
 *  0b1..Force an MCU reset when VDD_HVDF = 1
 */
#define SPM_HVDSC1_VDD_HVDRE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_HVDSC1_VDD_HVDRE_SHIFT)) & SPM_HVDSC1_VDD_HVDRE_MASK)

#define SPM_HVDSC1_VDD_HVDIE_MASK                (0x200000U)
#define SPM_HVDSC1_VDD_HVDIE_SHIFT               (21U)
/*! VDD_HVDIE - VDD High-Voltage Detect Interrupt Enable
 *  0b0..Hardware interrupt disabled (use polling)
 *  0b1..Request a hardware interrupt when HVDF = 1
 */
#define SPM_HVDSC1_VDD_HVDIE(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_HVDSC1_VDD_HVDIE_SHIFT)) & SPM_HVDSC1_VDD_HVDIE_MASK)

#define SPM_HVDSC1_VDD_HVDACK_MASK               (0x400000U)
#define SPM_HVDSC1_VDD_HVDACK_SHIFT              (22U)
/*! VDD_HVDACK - VDD High-Voltage Detect Acknowledge */
#define SPM_HVDSC1_VDD_HVDACK(x)                 (((uint32_t)(((uint32_t)(x)) << SPM_HVDSC1_VDD_HVDACK_SHIFT)) & SPM_HVDSC1_VDD_HVDACK_MASK)

#define SPM_HVDSC1_VDD_HVDF_MASK                 (0x800000U)
#define SPM_HVDSC1_VDD_HVDF_SHIFT                (23U)
/*! VDD_HVDF - VDD High-Voltage Detect Flag
 *  0b0..Vdd High-voltage event not detected
 *  0b1..Vdd High-voltage event detected
 */
#define SPM_HVDSC1_VDD_HVDF(x)                   (((uint32_t)(((uint32_t)(x)) << SPM_HVDSC1_VDD_HVDF_SHIFT)) & SPM_HVDSC1_VDD_HVDF_MASK)
/*! @} */

/*! @name AUXLDOLPCNFG - AUX LDO Low Power Configuration register */
/*! @{ */

#define SPM_AUXLDOLPCNFG_LPSEL_MASK              (0x2U)
#define SPM_AUXLDOLPCNFG_LPSEL_SHIFT             (1U)
/*! LPSEL - LPSEL
 *  0b0..AUX LDO regulator enters low power state in VLP/Stop modes.
 *  0b1..AUX LDO regulator remains in high power state in VLP/Stop modes.
 */
#define SPM_AUXLDOLPCNFG_LPSEL(x)                (((uint32_t)(((uint32_t)(x)) << SPM_AUXLDOLPCNFG_LPSEL_SHIFT)) & SPM_AUXLDOLPCNFG_LPSEL_MASK)
/*! @} */

/*! @name AUXLDOSC - AUX LDO Status And Control register */
/*! @{ */

#define SPM_AUXLDOSC_AUXREGVSEL_MASK             (0x1U)
#define SPM_AUXLDOSC_AUXREGVSEL_SHIFT            (0U)
/*! AUXREGVSEL - Auxiliary Regulator Voltage Select
 *  0b0..Regulate to 1.8V.
 *  0b1..Regulate to 1.5V.
 */
#define SPM_AUXLDOSC_AUXREGVSEL(x)               (((uint32_t)(((uint32_t)(x)) << SPM_AUXLDOSC_AUXREGVSEL_SHIFT)) & SPM_AUXLDOSC_AUXREGVSEL_MASK)

#define SPM_AUXLDOSC_AUXREGVSEL_OFFSET_MASK      (0x2U)
#define SPM_AUXLDOSC_AUXREGVSEL_OFFSET_SHIFT     (1U)
/*! AUXREGVSEL_OFFSET - Auxiliary Regulator Offset Voltage Select
 *  0b0..The AUXREG offset is not applied.
 *  0b1..The AUXREG offset is applied.
 */
#define SPM_AUXLDOSC_AUXREGVSEL_OFFSET(x)        (((uint32_t)(((uint32_t)(x)) << SPM_AUXLDOSC_AUXREGVSEL_OFFSET_SHIFT)) & SPM_AUXLDOSC_AUXREGVSEL_OFFSET_MASK)

#define SPM_AUXLDOSC_AUXTRIM_MASK                (0x1F00U)
#define SPM_AUXLDOSC_AUXTRIM_SHIFT               (8U)
/*! AUXTRIM - Auxiliary Regulator TRIM value */
#define SPM_AUXLDOSC_AUXTRIM(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_AUXLDOSC_AUXTRIM_SHIFT)) & SPM_AUXLDOSC_AUXTRIM_MASK)

#define SPM_AUXLDOSC_IOSSSEL_MASK                (0x70000U)
#define SPM_AUXLDOSC_IOSSSEL_SHIFT               (16U)
/*! IOSSSEL - IO 1.8 Reg Soft Start Select
 *  0b000..Soft Start duration set to 110us.
 *  0b001..Soft Start duration set to 95us.
 *  0b010..Soft Start duration set to 60us.
 *  0b011..Soft Start duration set to 48us.
 *  0b100..Soft Start duration set to 38us.
 *  0b101..Soft Start duration set to 30us.
 *  0b110..Soft Start duration set to 24us.
 *  0b111..Soft Start duration set to 17us.
 */
#define SPM_AUXLDOSC_IOSSSEL(x)                  (((uint32_t)(((uint32_t)(x)) << SPM_AUXLDOSC_IOSSSEL_SHIFT)) & SPM_AUXLDOSC_IOSSSEL_MASK)
/*! @} */

/*! @name DCDCSC - DCDC Status Control Register */
/*! @{ */

#define SPM_DCDCSC_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK (0x2U)
#define SPM_DCDCSC_DCDC_DISABLE_AUTO_CLK_SWITCH_SHIFT (1U)
/*! DCDC_DISABLE_AUTO_CLK_SWITCH - DCDC_DISABLE_AUTO_CLK_SWITCH */
#define SPM_DCDCSC_DCDC_DISABLE_AUTO_CLK_SWITCH(x) (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_DISABLE_AUTO_CLK_SWITCH_SHIFT)) & SPM_DCDCSC_DCDC_DISABLE_AUTO_CLK_SWITCH_MASK)

#define SPM_DCDCSC_DCDC_SEL_CLK_MASK             (0x4U)
#define SPM_DCDCSC_DCDC_SEL_CLK_SHIFT            (2U)
/*! DCDC_SEL_CLK - DCDC_SEL_CLK */
#define SPM_DCDCSC_DCDC_SEL_CLK(x)               (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_SEL_CLK_SHIFT)) & SPM_DCDCSC_DCDC_SEL_CLK_MASK)

#define SPM_DCDCSC_DCDC_PWD_OSC_INT_MASK         (0x8U)
#define SPM_DCDCSC_DCDC_PWD_OSC_INT_SHIFT        (3U)
/*! DCDC_PWD_OSC_INT - DCDC_PWD_OSC_INT */
#define SPM_DCDCSC_DCDC_PWD_OSC_INT(x)           (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_PWD_OSC_INT_SHIFT)) & SPM_DCDCSC_DCDC_PWD_OSC_INT_MASK)

#define SPM_DCDCSC_DCDC_VBAT_DIV_CTRL_MASK       (0xC00U)
#define SPM_DCDCSC_DCDC_VBAT_DIV_CTRL_SHIFT      (10U)
/*! DCDC_VBAT_DIV_CTRL - DCDC_VBAT_DIV_CTRL
 *  0b00..OFF
 *  0b01..VBAT
 *  0b10..VBAT / 2
 *  0b11..VBAT / 4
 */
#define SPM_DCDCSC_DCDC_VBAT_DIV_CTRL(x)         (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_VBAT_DIV_CTRL_SHIFT)) & SPM_DCDCSC_DCDC_VBAT_DIV_CTRL_MASK)

#define SPM_DCDCSC_DCDC_LESS_I_MASK              (0x2000000U)
#define SPM_DCDCSC_DCDC_LESS_I_SHIFT             (25U)
/*! DCDC_LESS_I - DCDC_LESS_I */
#define SPM_DCDCSC_DCDC_LESS_I(x)                (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_LESS_I_SHIFT)) & SPM_DCDCSC_DCDC_LESS_I_MASK)

#define SPM_DCDCSC_PWD_CMP_OFFSET_MASK           (0x4000000U)
#define SPM_DCDCSC_PWD_CMP_OFFSET_SHIFT          (26U)
/*! PWD_CMP_OFFSET - PWD_CMP_OFFSET */
#define SPM_DCDCSC_PWD_CMP_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_PWD_CMP_OFFSET_SHIFT)) & SPM_DCDCSC_PWD_CMP_OFFSET_MASK)

#define SPM_DCDCSC_CLKFLT_FAULT_MASK             (0x40000000U)
#define SPM_DCDCSC_CLKFLT_FAULT_SHIFT            (30U)
/*! CLKFLT_FAULT - DCDC CLKFLT Fault Status Flag */
#define SPM_DCDCSC_CLKFLT_FAULT(x)               (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_CLKFLT_FAULT_SHIFT)) & SPM_DCDCSC_CLKFLT_FAULT_MASK)

#define SPM_DCDCSC_DCDC_STS_DC_OK_MASK           (0x80000000U)
#define SPM_DCDCSC_DCDC_STS_DC_OK_SHIFT          (31U)
/*! DCDC_STS_DC_OK - DCDC_STS_DC_OK */
#define SPM_DCDCSC_DCDC_STS_DC_OK(x)             (((uint32_t)(((uint32_t)(x)) << SPM_DCDCSC_DCDC_STS_DC_OK_SHIFT)) & SPM_DCDCSC_DCDC_STS_DC_OK_MASK)
/*! @} */

/*! @name DCDCC1 - DCDC Control Register 1 */
/*! @{ */

#define SPM_DCDCC1_POSLIMIT_BUCK_IN_MASK         (0x7FU)
#define SPM_DCDCC1_POSLIMIT_BUCK_IN_SHIFT        (0U)
/*! POSLIMIT_BUCK_IN - POSLIMIT_BUCK_IN */
#define SPM_DCDCC1_POSLIMIT_BUCK_IN(x)           (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC1_POSLIMIT_BUCK_IN_SHIFT)) & SPM_DCDCC1_POSLIMIT_BUCK_IN_MASK)

#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_CM_HYST_MASK (0x4000000U)
#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_CM_HYST_SHIFT (26U)
/*! DCDC_LOOPCTRL_EN_CM_HYST - DCDC_LOOPCTRL_EN_CM_HYST */
#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_CM_HYST(x)   (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC1_DCDC_LOOPCTRL_EN_CM_HYST_SHIFT)) & SPM_DCDCC1_DCDC_LOOPCTRL_EN_CM_HYST_MASK)

#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_DF_HYST_MASK (0x8000000U)
#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_DF_HYST_SHIFT (27U)
/*! DCDC_LOOPCTRL_EN_DF_HYST - DCDC_LOOPCTRL_EN_DF_HYST */
#define SPM_DCDCC1_DCDC_LOOPCTRL_EN_DF_HYST(x)   (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC1_DCDC_LOOPCTRL_EN_DF_HYST_SHIFT)) & SPM_DCDCC1_DCDC_LOOPCTRL_EN_DF_HYST_MASK)
/*! @} */

/*! @name DCDCC2 - DCDC Control Register 2 */
/*! @{ */

#define SPM_DCDCC2_DCDC_LOOPCTRL_HYST_SIGN_MASK  (0x2000U)
#define SPM_DCDCC2_DCDC_LOOPCTRL_HYST_SIGN_SHIFT (13U)
/*! DCDC_LOOPCTRL_HYST_SIGN - DCDC_LOOPCTRL_HYST_SIGN */
#define SPM_DCDCC2_DCDC_LOOPCTRL_HYST_SIGN(x)    (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC2_DCDC_LOOPCTRL_HYST_SIGN_SHIFT)) & SPM_DCDCC2_DCDC_LOOPCTRL_HYST_SIGN_MASK)

#define SPM_DCDCC2_DCDC_BATTMONITOR_EN_BATADJ_MASK (0x8000U)
#define SPM_DCDCC2_DCDC_BATTMONITOR_EN_BATADJ_SHIFT (15U)
/*! DCDC_BATTMONITOR_EN_BATADJ - DCDC_BATTMONITOR_EN_BATADJ */
#define SPM_DCDCC2_DCDC_BATTMONITOR_EN_BATADJ(x) (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC2_DCDC_BATTMONITOR_EN_BATADJ_SHIFT)) & SPM_DCDCC2_DCDC_BATTMONITOR_EN_BATADJ_MASK)

#define SPM_DCDCC2_DCDC_BATTMONITOR_BATT_VAL_MASK (0x3FF0000U)
#define SPM_DCDCC2_DCDC_BATTMONITOR_BATT_VAL_SHIFT (16U)
/*! DCDC_BATTMONITOR_BATT_VAL - DCDC_BATTMONITOR_BATT_VAL */
#define SPM_DCDCC2_DCDC_BATTMONITOR_BATT_VAL(x)  (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC2_DCDC_BATTMONITOR_BATT_VAL_SHIFT)) & SPM_DCDCC2_DCDC_BATTMONITOR_BATT_VAL_MASK)
/*! @} */

/*! @name DCDCC3 - DCDC Control Register 3 */
/*! @{ */

#define SPM_DCDCC3_DCDC_BYPASS_ADC_MEAS_MASK     (0x1U)
#define SPM_DCDCC3_DCDC_BYPASS_ADC_MEAS_SHIFT    (0U)
/*! DCDC_BYPASS_ADC_MEAS - DCDC_BYPASS_ADC_MEAS */
#define SPM_DCDCC3_DCDC_BYPASS_ADC_MEAS(x)       (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_BYPASS_ADC_MEAS_SHIFT)) & SPM_DCDCC3_DCDC_BYPASS_ADC_MEAS_MASK)

#define SPM_DCDCC3_DCDC_VBAT_VALUE_MASK          (0x1CU)
#define SPM_DCDCC3_DCDC_VBAT_VALUE_SHIFT         (2U)
/*! DCDC_VBAT_VALUE - DCDC_VBAT_VALUE */
#define SPM_DCDCC3_DCDC_VBAT_VALUE(x)            (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_VBAT_VALUE_SHIFT)) & SPM_DCDCC3_DCDC_VBAT_VALUE_MASK)

#define SPM_DCDCC3_DCDC_VDD1P2CTRL_ADJTN_MASK    (0xF0000U)
#define SPM_DCDCC3_DCDC_VDD1P2CTRL_ADJTN_SHIFT   (16U)
/*! DCDC_VDD1P2CTRL_ADJTN - DCDC_VDD1P2CTRL_ADJTN */
#define SPM_DCDCC3_DCDC_VDD1P2CTRL_ADJTN(x)      (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_VDD1P2CTRL_ADJTN_SHIFT)) & SPM_DCDCC3_DCDC_VDD1P2CTRL_ADJTN_MASK)

#define SPM_DCDCC3_DCDC_MINPWR_DC_HALFCLK_MASK   (0x1000000U)
#define SPM_DCDCC3_DCDC_MINPWR_DC_HALFCLK_SHIFT  (24U)
/*! DCDC_MINPWR_DC_HALFCLK - DCDC_MINPWR_DC_HALFCLK */
#define SPM_DCDCC3_DCDC_MINPWR_DC_HALFCLK(x)     (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_MINPWR_DC_HALFCLK_SHIFT)) & SPM_DCDCC3_DCDC_MINPWR_DC_HALFCLK_MASK)

#define SPM_DCDCC3_DCDC_MINPWR_EXTRA_DOUBLE_FETS_MASK (0x2000000U)
#define SPM_DCDCC3_DCDC_MINPWR_EXTRA_DOUBLE_FETS_SHIFT (25U)
/*! DCDC_MINPWR_EXTRA_DOUBLE_FETS - DCDC_MINPWR_EXTRA_DOUBLE_FETS */
#define SPM_DCDCC3_DCDC_MINPWR_EXTRA_DOUBLE_FETS(x) (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_MINPWR_EXTRA_DOUBLE_FETS_SHIFT)) & SPM_DCDCC3_DCDC_MINPWR_EXTRA_DOUBLE_FETS_MASK)

#define SPM_DCDCC3_DCDC_MINPWR_DOUBLE_FETS_MASK  (0x4000000U)
#define SPM_DCDCC3_DCDC_MINPWR_DOUBLE_FETS_SHIFT (26U)
/*! DCDC_MINPWR_DOUBLE_FETS - DCDC_MINPWR_DOUBLE_FETS */
#define SPM_DCDCC3_DCDC_MINPWR_DOUBLE_FETS(x)    (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_MINPWR_DOUBLE_FETS_SHIFT)) & SPM_DCDCC3_DCDC_MINPWR_DOUBLE_FETS_MASK)

#define SPM_DCDCC3_DCDC_MINPWR_HALF_FETS_MASK    (0x8000000U)
#define SPM_DCDCC3_DCDC_MINPWR_HALF_FETS_SHIFT   (27U)
/*! DCDC_MINPWR_HALF_FETS - DCDC_MINPWR_HALF_FETS */
#define SPM_DCDCC3_DCDC_MINPWR_HALF_FETS(x)      (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_MINPWR_HALF_FETS_SHIFT)) & SPM_DCDCC3_DCDC_MINPWR_HALF_FETS_MASK)

#define SPM_DCDCC3_DCDC_VDD1P2CTRL_DISABLE_STEP_MASK (0x40000000U)
#define SPM_DCDCC3_DCDC_VDD1P2CTRL_DISABLE_STEP_SHIFT (30U)
/*! DCDC_VDD1P2CTRL_DISABLE_STEP - DCDC_VDD1P2CTRL_DISABLE_STEP */
#define SPM_DCDCC3_DCDC_VDD1P2CTRL_DISABLE_STEP(x) (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_VDD1P2CTRL_DISABLE_STEP_SHIFT)) & SPM_DCDCC3_DCDC_VDD1P2CTRL_DISABLE_STEP_MASK)

#define SPM_DCDCC3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK (0x80000000U)
#define SPM_DCDCC3_DCDC_VDD1P8CTRL_DISABLE_STEP_SHIFT (31U)
/*! DCDC_VDD1P8CTRL_DISABLE_STEP - DCDC_VDD1P8CTRL_DISABLE_STEP */
#define SPM_DCDCC3_DCDC_VDD1P8CTRL_DISABLE_STEP(x) (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC3_DCDC_VDD1P8CTRL_DISABLE_STEP_SHIFT)) & SPM_DCDCC3_DCDC_VDD1P8CTRL_DISABLE_STEP_MASK)
/*! @} */

/*! @name DCDCC4 - DCDC Control Register 4 */
/*! @{ */

#define SPM_DCDCC4_INTEGRATOR_VALUE_MASK         (0x7FFFFU)
#define SPM_DCDCC4_INTEGRATOR_VALUE_SHIFT        (0U)
/*! INTEGRATOR_VALUE - INTEGRATOR VALUE */
#define SPM_DCDCC4_INTEGRATOR_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC4_INTEGRATOR_VALUE_SHIFT)) & SPM_DCDCC4_INTEGRATOR_VALUE_MASK)

#define SPM_DCDCC4_INTEGRATOR_VALUE_SELECT_MASK  (0x80000U)
#define SPM_DCDCC4_INTEGRATOR_VALUE_SELECT_SHIFT (19U)
/*! INTEGRATOR_VALUE_SELECT - INTEGRATOR VALUE SELECT
 *  0b0..Select the saved value in hardware
 *  0b1..Select the integrator value in this register
 */
#define SPM_DCDCC4_INTEGRATOR_VALUE_SELECT(x)    (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC4_INTEGRATOR_VALUE_SELECT_SHIFT)) & SPM_DCDCC4_INTEGRATOR_VALUE_SELECT_MASK)

#define SPM_DCDCC4_PULSE_RUN_SPEEDUP_MASK        (0x100000U)
#define SPM_DCDCC4_PULSE_RUN_SPEEDUP_SHIFT       (20U)
/*! PULSE_RUN_SPEEDUP - PULSE RUN SPEEDUP */
#define SPM_DCDCC4_PULSE_RUN_SPEEDUP(x)          (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC4_PULSE_RUN_SPEEDUP_SHIFT)) & SPM_DCDCC4_PULSE_RUN_SPEEDUP_MASK)
/*! @} */

/*! @name DCDCC6 - DCDC Control Register 6 */
/*! @{ */

#define SPM_DCDCC6_DCDC_VDD1P8CTRL_TRG_MASK      (0x1FU)
#define SPM_DCDCC6_DCDC_VDD1P8CTRL_TRG_SHIFT     (0U)
/*! DCDC_VDD1P8CTRL_TRG - DCDC_VDD1P8CTRL_TRG */
#define SPM_DCDCC6_DCDC_VDD1P8CTRL_TRG(x)        (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC6_DCDC_VDD1P8CTRL_TRG_SHIFT)) & SPM_DCDCC6_DCDC_VDD1P8CTRL_TRG_MASK)

#define SPM_DCDCC6_DCDC_VDD1P2CTRL_TRG_BUCK_MASK (0xF00U)
#define SPM_DCDCC6_DCDC_VDD1P2CTRL_TRG_BUCK_SHIFT (8U)
/*! DCDC_VDD1P2CTRL_TRG_BUCK - DCDC_VDD1P2CTRL_TRG_BUCK */
#define SPM_DCDCC6_DCDC_VDD1P2CTRL_TRG_BUCK(x)   (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC6_DCDC_VDD1P2CTRL_TRG_BUCK_SHIFT)) & SPM_DCDCC6_DCDC_VDD1P2CTRL_TRG_BUCK_MASK)

#define SPM_DCDCC6_DCDC_HSVDD_TRIM_MASK          (0xF000000U)
#define SPM_DCDCC6_DCDC_HSVDD_TRIM_SHIFT         (24U)
/*! DCDC_HSVDD_TRIM - DCDC_HSVDD_TRIM */
#define SPM_DCDCC6_DCDC_HSVDD_TRIM(x)            (((uint32_t)(((uint32_t)(x)) << SPM_DCDCC6_DCDC_HSVDD_TRIM_SHIFT)) & SPM_DCDCC6_DCDC_HSVDD_TRIM_MASK)
/*! @} */

/*! @name LPREQPINCNTRL - LP Request Pin Control Register */
/*! @{ */

#define SPM_LPREQPINCNTRL_LPREQOE_MASK           (0x1U)
#define SPM_LPREQPINCNTRL_LPREQOE_SHIFT          (0U)
/*! LPREQOE - Low Power Request Output Enable Register
 *  0b0..Low Power request output pin not enabled.
 *  0b1..Low Power request output pin enabled.
 */
#define SPM_LPREQPINCNTRL_LPREQOE(x)             (((uint32_t)(((uint32_t)(x)) << SPM_LPREQPINCNTRL_LPREQOE_SHIFT)) & SPM_LPREQPINCNTRL_LPREQOE_MASK)

#define SPM_LPREQPINCNTRL_POLARITY_MASK          (0x2U)
#define SPM_LPREQPINCNTRL_POLARITY_SHIFT         (1U)
/*! POLARITY - Low Power Request Output Pin Polarity Control Register
 *  0b0..High true polarity.
 *  0b1..Low true polarity.
 */
#define SPM_LPREQPINCNTRL_POLARITY(x)            (((uint32_t)(((uint32_t)(x)) << SPM_LPREQPINCNTRL_POLARITY_SHIFT)) & SPM_LPREQPINCNTRL_POLARITY_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPM_Register_Masks */


/*!
 * @}
 */ /* end of group SPM_Peripheral_Access_Layer */


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


#endif  /* PERI_SPM_H_ */

