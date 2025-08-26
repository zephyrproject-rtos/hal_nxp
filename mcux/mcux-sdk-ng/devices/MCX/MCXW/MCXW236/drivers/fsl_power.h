/*
 * Copyright 2017,2020-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_POWER_H_
#define _FSL_POWER_H_

#include "fsl_common.h"
#include "fsl_device_registers.h"
#include <stdint.h>

/*!
 * @addtogroup power
 * @{
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

 /*! @name Driver version */
/*@{*/
/*! @brief POWER driver version 2.0.0. */
#define FSL_POWER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief Power library status.
 */
enum _power_status
{
    kStatus_Power_Success                    = kStatus_Success,
    kStatus_Power_SupplyModeModeNotSupported = MAKE_STATUS(kStatusGroup_POWER, 1U),
    kStatus_Power_SupplyModeModeInvalid      = MAKE_STATUS(kStatusGroup_POWER, 2U),
};

/**
 * @brief List of BOD levels
 */
typedef enum bod_level_s
{
    kBOD_LEVEL_1100mv = 0x102U,
    kBOD_LEVEL_1125mv = 0x002U,
    kBOD_LEVEL_1150mv = 0x103U,
    kBOD_LEVEL_1175mv = 0x003U,
    kBOD_LEVEL_1200mv = 0x104U,
    kBOD_LEVEL_1225mv = 0x004U,
    kBOD_LEVEL_1250mv = 0x105U,
    kBOD_LEVEL_1275mv = 0x005U,
    kBOD_LEVEL_1300mv = 0x106U,
    kBOD_LEVEL_1325mv = 0x006U,
    kBOD_LEVEL_1350mv = 0x107U,
    kBOD_LEVEL_1375mv = 0x007U,
    kBOD_LEVEL_1400mv = 0x108U,
    kBOD_LEVEL_1425mv = 0x008U,
    kBOD_LEVEL_1450mv = 0x109U,
    kBOD_LEVEL_1475mv = 0x009U,
    kBOD_LEVEL_1500mv = 0x10AU,
    kBOD_LEVEL_1525mv = 0x00AU,
    kBOD_LEVEL_1550mv = 0x02AU,
    kBOD_LEVEL_1575mv = 0x04AU,
    kBOD_LEVEL_1600mv = 0x10BU,
    kBOD_LEVEL_1625mv = 0x00BU,
    kBOD_LEVEL_1650mv = 0x02BU,
    kBOD_LEVEL_1675mv = 0x04BU,
    kBOD_LEVEL_1700mv = 0x10CU,
    kBOD_LEVEL_1725mv = 0x00CU,
    kBOD_LEVEL_1750mv = 0x02CU,
    kBOD_LEVEL_1775mv = 0x04CU,
    kBOD_LEVEL_1800mv = 0x10DU,
    kBOD_LEVEL_1825mv = 0x00DU,
    kBOD_LEVEL_1850mv = 0x02DU,
    kBOD_LEVEL_1875mv = 0x04DU,
    kBOD_LEVEL_1900mv = 0x10EU,
    kBOD_LEVEL_1925mv = 0x00EU,
    kBOD_LEVEL_1950mv = 0x02EU,
    kBOD_LEVEL_1975mv = 0x04EU,
    kBOD_LEVEL_2000mv = 0x10FU,
    kBOD_LEVEL_2025mv = 0x00FU,
    kBOD_LEVEL_2050mv = 0x02FU,
    kBOD_LEVEL_2075mv = 0x04FU,
    kBOD_LEVEL_2100mv = 0x110U,
    kBOD_LEVEL_2125mv = 0x010U,
    kBOD_LEVEL_2150mv = 0x030U,
    kBOD_LEVEL_2175mv = 0x050U,
    kBOD_LEVEL_2200mv = 0x111U,
    kBOD_LEVEL_2225mv = 0x011U,
    kBOD_LEVEL_2250mv = 0x031U,
    kBOD_LEVEL_2275mv = 0x051U,
    kBOD_LEVEL_2300mv = 0x112U,
    kBOD_LEVEL_2325mv = 0x012U,
    kBOD_LEVEL_2350mv = 0x032U,
    kBOD_LEVEL_2375mv = 0x052U,
    kBOD_LEVEL_2400mv = 0x113U,
    kBOD_LEVEL_2425mv = 0x013U,
    kBOD_LEVEL_2450mv = 0x033U,
    kBOD_LEVEL_2475mv = 0x053U,
    kBOD_LEVEL_2500mv = 0x114U,
    kBOD_LEVEL_2525mv = 0x014U,
    kBOD_LEVEL_2550mv = 0x034U,
    kBOD_LEVEL_2575mv = 0x054U,
    kBOD_LEVEL_2600mv = 0x115U,
    kBOD_LEVEL_2625mv = 0x015U,
    kBOD_LEVEL_2650mv = 0x035U,
    kBOD_LEVEL_2675mv = 0x055U,
    kBOD_LEVEL_2700mv = 0x116U,
    kBOD_LEVEL_2725mv = 0x016U,
    kBOD_LEVEL_2750mv = 0x036U,
    kBOD_LEVEL_2775mv = 0x056U,
    kBOD_LEVEL_2800mv = 0x117U,
    kBOD_LEVEL_2825mv = 0x017U,
    kBOD_LEVEL_2850mv = 0x037U,
    kBOD_LEVEL_2875mv = 0x057U,
    kBOD_LEVEL_2900mv = 0x118U,
    kBOD_LEVEL_2925mv = 0x018U,
    kBOD_LEVEL_2950mv = 0x038U,
    kBOD_LEVEL_2975mv = 0x058U,
    kBOD_LEVEL_3000mv = 0x119U,
    kBOD_LEVEL_3025mv = 0x019U,
    kBOD_LEVEL_3050mv = 0x039U,
    kBOD_LEVEL_3075mv = 0x059U,
    kBOD_LEVEL_3100mv = 0x11AU,
} bod_level_t;

/**
 * @brief List of reset actions when BOD occurs
 */
typedef enum bod_action_s
{
    kBOD_NO_ACTION = 0U,
    kBOD_RESET     = 1U,
    kBOD_INTERRUPT = 2U
} bod_action_t;

/**
 * @brief List of supply modes
 */
typedef enum dcdc_mode_s
{
    kDCDC_MODE_HV_SM    = 1U, /*!< HV supplied */
    kDCDC_MODE_LV_SM    = 2U, /*!< LV supplied */
    kDCDC_MODE_XR_SM_SS = 3U, /*!< HV and LV supplied and equal (Single Supply) */
    kDCDC_MODE_XR_SM_DS = 4U, /*!< HV and LV supplied and not equal (Dual Supply) */
} dcdc_mode_t;

/**
 * @brief List of reset causes
 */
typedef enum reset_cause_s
{
    kRESET_CAUSE_POR    = PMC_RESETCAUSE_POR_MASK,               /*!< Power On Reset */
    kRESET_CAUSE_PAD    = PMC_RESETCAUSE_PADRESET_MASK,          /*!< Pin Reset */
    kRESET_CAUSE_BOD    = PMC_RESETCAUSE_BODRESET_MASK,          /*!< Brown Out Detector */
    kRESET_CAUSE_SYS    = PMC_RESETCAUSE_SYSTEMRESET_MASK,       /*!< System Reset requested by the ARM CPU */
    kRESET_CAUSE_WDT    = PMC_RESETCAUSE_WDTRESET_MASK,          /*!< Watchdog Timer */
    kRESET_CAUSE_SWR    = PMC_RESETCAUSE_SWRRESET_MASK,          /*!< Software reset */
    kRESET_CAUSE_DPD_IO = PMC_RESETCAUSE_DPDRESET_WAKEUPIO_MASK, /*!< Wake-up I/O reset event during DEEP POWER DOWN */
    kRESET_CAUSE_RTC    = PMC_RESETCAUSE_DPDRESET_RTC_MASK,      /*!< Real Time Clock*/
    kRESET_CAUSE_OST    = PMC_RESETCAUSE_DPDRESET_OSTIMER_MASK,  /*!< OS Event Timer */
    kRESET_CAUSE_CDOG   = PMC_RESETCAUSE_CDOGRESET_MASK,         /*!< code Watchdog */
    kRESET_CAUSE_BLE    = PMC_RESETCAUSE_BLEWUP_MASK,            /*!< BLE Timer wakeup */
} reset_cause_t;

/**
 * @brief List of DC/DC outputs when configured in boost mode
 */
typedef enum dcdc_boost_output_level_s
{
    kDCDC_BOOST_OUTPUT_1700mv = 0U,
    kDCDC_BOOST_OUTPUT_1800mv = 1U,
    kDCDC_BOOST_OUTPUT_1900mv = 2U,
    kDCDC_BOOST_OUTPUT_2000mv = 3U,
    kDCDC_BOOST_OUTPUT_2100mv = 4U,
    kDCDC_BOOST_OUTPUT_2200mv = 5U,
    kDCDC_BOOST_OUTPUT_2300mv = 6U,
    kDCDC_BOOST_OUTPUT_2400mv = 7U,
    kDCDC_BOOST_OUTPUT_2500mv = 8U,
    kDCDC_BOOST_OUTPUT_2600mv = 9U,
    kDCDC_BOOST_OUTPUT_2700mv = 10U,
    kDCDC_BOOST_OUTPUT_2800mv = 11U,
    kDCDC_BOOST_OUTPUT_2900mv = 12U,
    kDCDC_BOOST_OUTPUT_3000mv = 13U,
    kDCDC_BOOST_OUTPUT_3100mv = 14U,
    kDCDC_BOOST_OUTPUT_3200mv = 15U
} dcdc_boost_output_level_t;

/**
 * @brief List of DC/DC outputs when configured in buck mode
 */
typedef enum dcdc_buck_output_level_s
{
    kDCDC_BUCK_OUTPUT_1100mv = 0U,
    kDCDC_BUCK_OUTPUT_1200mv = 1U,
    kDCDC_BUCK_OUTPUT_1300mv = 2U,
    kDCDC_BUCK_OUTPUT_1400mv = 3U,
    kDCDC_BUCK_OUTPUT_1500mv = 4U,
    kDCDC_BUCK_OUTPUT_1600mv = 5U,
    kDCDC_BUCK_OUTPUT_1700mv = 6U,
    kDCDC_BUCK_OUTPUT_1800mv = 7U
} dcdc_buck_output_level_t;

typedef enum
{
    kBIAS_0_66V_LOW_POWER_MODE     = 0u, /**< This is intended to be used for retention mode of memory or digital */
    kBIAS_0_63V_HIGH_ACCURACY_MODE = 1u, /**< During active mode, the bias must be set in high accuracy mode */
    kBIAS_DISABLED                 = 2u, /**< Bias disabled */
    kBIAS_DISABLED2                = 3u  /**< Bias disabled */
} bias_pden_bias_t;

/**
 * @brief List of analog peripherals bits that can be powered on (see POWER_PeripheralPowerOn()) or off (see
 * POWER_PeripheralPowerOff()) in active mode
 */
typedef enum power_config_bit_s
{
    kPOWERCFG_DCDC    = (1UL << PMC_PDRUNCFG0_PDEN_DCDC_SHIFT),
    kPOWERCFG_BIAS    = (3UL << PMC_PDRUNCFG0_PDEN_BIAS_SHIFT), /* includes 0.66V/0.63V */
    kPOWERCFG_BOD1    = (1UL << PMC_PDRUNCFG0_PDEN_BOD1_SHIFT),
    kPOWERCFG_BOD2    = (1UL << PMC_PDRUNCFG0_PDEN_BOD2_SHIFT),
    kPOWERCFG_FRO192M = (1UL << PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT),
    kPOWERCFG_FRO1M   = (1UL << PMC_PDRUNCFG0_PDEN_FRO1M_SHIFT),
    kPOWERCFG_FRO32K  = (1UL << PMC_PDRUNCFG0_PDEN_FRO32K_SHIFT),
    kPOWERCFG_XTAL32K = (1UL << PMC_PDRUNCFG0_PDEN_XTAL32K_SHIFT),
    kPOWERCFG_BLE     = (1UL << PMC_PDRUNCFG0_PDEN_BLE_SHIFT),
    kPOWERCFG_RNG     = (1UL << PMC_PDRUNCFG0_PDEN_RNG_SHIFT)
} power_config_bit_t;

/**
 * @brief List of analog peripherals bits that can be excluded from being powered off when entering a low power mode.
 * The comment next to each item of the list specifies in which low power modes the peripheral can be excluded.
 * Note: (*) is always excluded for this power mode
 *
 * On DCDC_BYPASS:
 * VDD_IO needs to be supplied in the low power modes in order to enable the IO functionality (wakeup pin,
 * flexcom wakeup, reset, ...) The application needs to guarantee this supply by connecting the VDD_IO to the battery
 * directly or an external PMIC device. In case the VDD_IO is supplied by the output of the MCXW23x DC/DC converter,
 * the DC/DC convertor can't be switched off but must be put in bypass mode. Enabling the bypass switch will put the
 * DC/DC input level to the output minus the drop over the switch (typical xx mV). Enabling the bypass switch increased
 * also the leakage in power-off mode (see datasheet for typical value).
 *
 */
typedef enum low_power_config_bit_s
{
    kLOWPOWERCFG_DCDC = (1UL << PMC_PDSLEEPCFG0_PDEN_DCDC_SHIFT), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_BOD1 = (1UL << PMC_PDSLEEPCFG0_PDEN_BOD1_SHIFT), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_BOD2 = (1UL << PMC_PDSLEEPCFG0_PDEN_BOD2_SHIFT), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_FRO192M = (1UL << PMC_PDSLEEPCFG0_PDEN_FRO192M_SHIFT), /**< [DEEP SLEEP] */
    kLOWPOWERCFG_FRO32K =
        (1UL << PMC_PDSLEEPCFG0_PDEN_FRO32K_SHIFT), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_XTAL32K =
        (1UL << PMC_PDSLEEPCFG0_PDEN_XTAL32K_SHIFT),                /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_FRO1M = (1UL << PMC_PDSLEEPCFG0_PDEN_FRO1M_SHIFT), /**< [DEEP SLEEP,    POWER DOWN]                  */
    kLOWPOWERCFG_TRNG  = (1UL << PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT),   /**< [DEEP SLEEP,    POWER DOWN]               */
    kLOWPOWERCFG_DCDC_BYPASS =
        (1UL << (PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT + 1)), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_BLE_WUP =
        (1UL << (PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT + 2)), /**< [DEEP SLEEP,    POWER DOWN, DEEP POWER DOWN] */
    kLOWPOWERCFG_HFDSM = (1UL << (PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT + 3)) /**< [DEEP SLEEP] */
} low_power_config_bit_t;

/**
 * @brief List CPU retention configurations
 */
typedef enum cpu_retention_config_s
{
    kCPU_RETENTION_DISABLE = 0U,
    kCPU_RETENTION_ENABLE  = 1U
} cpu_retention_config_t;

#define kLOWPOWERCFG_DCDC_BYPASS_SHIFT (PMC_PDSLEEPCFG0_PDEN_RNG_SHIFT + 1)

/**
 * @brief Defines of analog peripherals bits that can be excluded from being powered off grouped per low power mode.
 */
#define kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPSLEEP                                                                     \
    (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2 | kLOWPOWERCFG_FRO192M | kLOWPOWERCFG_FRO32K |          \
     kLOWPOWERCFG_XTAL32K | kLOWPOWERCFG_FRO1M | kLOWPOWERCFG_TRNG | kLOWPOWERCFG_DCDC_BYPASS | kLOWPOWERCFG_BLE_WUP | \
     kLOWPOWERCFG_HFDSM)

#define kEXCLUDE_FROM_PD_LIMITATION_MASK_POWERDOWN                                                            \
    (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2 | kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K | \
     kLOWPOWERCFG_FRO1M | kLOWPOWERCFG_DCDC_BYPASS | kLOWPOWERCFG_BLE_WUP)

#define kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPPOWERDOWN                                                        \
    (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2 | kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K | \
     kLOWPOWERCFG_DCDC_BYPASS)

#define kEXCLUDE_FROM_PD_LIMITATION_MASK_POWEROFF (0U)

/**
 * @brief List of SRAM control bits.  Each bit represents an SRAM segment.
 */
typedef enum sram_ctrl_bit_s
{
    kSRAM_CTRL_RAMX0      = (1UL << 0U),
    kSRAM_CTRL_RAMX1      = (1UL << 1U),
    kSRAM_CTRL_RAMX2      = (1UL << 2U),
    kSRAM_CTRL_RAMX3      = (1UL << 3U),
    kSRAM_CTRL_RAM00      = (1UL << 4U),
    kSRAM_CTRL_RAM10      = (1UL << 5U),
    kSRAM_CTRL_RAM20      = (1UL << 6U),
    kSRAM_CTRL_RAMBLEDATA = (1UL << 7U),
    kSRAM_CTRL_RAMBLESEQL = (1UL << 8U)
} sram_ctrl_bit_t;

/**
 * @brief List of wakup IO control bits. Only used in deep power down and power off mode.
 */
typedef enum wakeup_io_bits_s
{
    kWAKEUP_PIN_ENABLE          = (1UL << PMC_WAKEUPIOCTRL_ENABLE_SHIFT),
    kWAKEUP_PIN_DISABLE         = (0UL << PMC_WAKEUPIOCTRL_ENABLE_SHIFT),
    kWAKEUP_PIN_PUP_EN          = (1UL << PMC_WAKEUPIOCTRL_PUP_EN_SHIFT),
    kWAKEUP_PIN_PUP_DIS         = (0UL << PMC_WAKEUPIOCTRL_PUP_EN_SHIFT),
    kWAKEUP_PIN_PDN_EN          = (1UL << PMC_WAKEUPIOCTRL_PDN_EN_SHIFT),
    kWAKEUP_PIN_PDN_DIS         = (0UL << PMC_WAKEUPIOCTRL_PDN_EN_SHIFT),
    kWAKEUP_PIN_WAKEUP_HIGH_LVL = (1UL << PMC_WAKEUPIOCTRL_LVL_SHIFT),
    kWAKEUP_PIN_WAKEUP_LOW_LVL  = (0UL << PMC_WAKEUPIOCTRL_LVL_SHIFT)
} wakeup_io_bits_t;

/**
 * @brief List of wake up interrupts to wake up from deep sleep, power down or deep power down. Note that any kind
 * of interrupt (also interrupts not listed here) can cause a wakeup from sleep mode.
 */
typedef enum wakeup_irq_s
{
    kWAKEUP_SYS                = (1ULL << WDT_BOD_IRQn),     /**< [DEEP SLEEP] (depends on syscon NMISRC config)*/
    kWAKEUP_DMA0               = (1ULL << DMA0_IRQn),        /**< [DEEP SLEEP] */
    kWAKEUP_GINT0              = (1ULL << GINT0_IRQn),       /**< [DEEP SLEEP, POWER DOWN] */
    kWAKEUP_PIN_INT0           = (1ULL << PIN_INT0_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT1           = (1ULL << PIN_INT1_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT2           = (1ULL << PIN_INT2_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT3           = (1ULL << PIN_INT3_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_UTICK              = (1ULL << UTICK0_IRQn),      /**< [DEEP SLEEP] */
    kWAKEUP_MRT                = (1ULL << MRT0_IRQn),        /**< [DEEP SLEEP] */
    kWAKEUP_CTIMER0            = (1ULL << CTIMER0_IRQn),     /**< [DEEP SLEEP] */
    kWAKEUP_CTIMER1            = (1ULL << CTIMER1_IRQn),     /**< [DEEP SLEEP] */
    kWAKEUP_SCT                = (1ULL << SCT0_IRQn),        /**< [DEEP SLEEP] */
    kWAKEUP_CTIMER3            = (1ULL << CTIMER3_IRQn),     /**< [DEEP SLEEP] */
    kWAKEUP_FLEXCOMM0          = (1ULL << FLEXCOMM0_IRQn),   /**< [DEEP SLEEP, POWER DOWN] */
    kWAKEUP_FLEXCOMM1          = (1ULL << FLEXCOMM1_IRQn),   /**< [DEEP SLEEP] */
    kWAKEUP_FLEXCOMM2          = (1ULL << FLEXCOMM2_IRQn),   /**< [DEEP SLEEP] */
    kWAKEUP_BLE_LL             = (1ULL << BLE_LL_IRQn),      /**< [DEEP SLEEP] */
    kWAKEUP_BLE_SLP_TMR        = (1ULL << BLE_SLP_TMR_IRQn), /**< [DEEP SLEEP, POWER DOWN]  */
    kWAKEUP_WDT                = (1ULL << WDT_IRQn),         /**< [DEEP SLEEP] (depends on syscon NMISRC config)*/
    kWAKEUP_BOD1               = (1ULL << BOD1_IRQn),        /**< [DEEP SLEEP] */
    kWAKEUP_BOD2               = (1ULL << BOD2_IRQn),        /**< [DEEP SLEEP] */
    kWAKEUP_RTC                = (1ULL << RTC_IRQn),         /**< [DEEP SLEEP, POWER DOWN, DEEP POWER DOWN] */
    kWAKEUP_WAKE_DSLP          = (1ULL << WAKE_DSLP_IRQn),   /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT4           = (1ULL << PIN_INT4_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT5           = (1ULL << PIN_INT5_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT6           = (1ULL << PIN_INT6_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_PIN_INT7           = (1ULL << PIN_INT7_IRQn),    /**< [DEEP SLEEP] */
    kWAKEUP_CTIMER2            = (1ULL << CTIMER2_IRQn),     /**< [DEEP SLEEP] */
    kWAKEUP_CTIMER4            = (1ULL << CTIMER4_IRQn),     /**< [DEEP SLEEP] */
    kWAKEUP_OS_EVENT           = (1ULL << OS_EVENT_IRQn),    /**< [DEEP SLEEP, POWER DOWN, DEEP POWER DOWN] */
    kWAKEUP_SPIFI              = (1ULL << SPIFI_IRQn),       /**< [DEEP SLEEP] */
    kWAKEUP_SEC_GPIO_INT0_IRQ0 = (1ULL << SEC_GPIO_INT0_IRQ0_IRQn), /**< [DEEP SLEEP] */
    kWAKEUP_SEC_GPIO_INT0_IRQ1 = (1ULL << SEC_GPIO_INT0_IRQ1_IRQn), /**< [DEEP SLEEP] */
    kWAKEUP_PLU                = (1ULL << PLU_IRQn),                /**< [DEEP SLEEP] */
    kWAKEUP_SEC_VIO            = (1ULL << SEC_VIO_IRQn),            /**< [DEEP SLEEP] */
    kWAKEUP_TRNG               = (1ULL << TRNG_IRQn),               /**< [DEEP SLEEP] */
    kWAKEUP_DMA1               = (1ULL << DMA1_IRQn),               /**< [DEEP SLEEP] */
    kWAKEUP_WAKE_PAD           = (1ULL << WAKE_PAD_IRQn),           /**< [DEEP POWER DOWN, POWER OFF] */
} wakeup_irq_t;

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief Function to initialize the library.
 */
void POWER_Init(void);

/*!
 * @brief Function to reset device. This will result in a full boot cycle.
 */
void POWER_Reset(void);

/*!
 * @brief Function to return the library version.
 * @return version number of the power library
 */
uint32_t POWER_GetLibVersion(void);

/*!
 * @brief Function to disable the power of an analog peripheral when the device is in active mode.
 * @param powerConfigBit    peripheral for which to disable the power
 */
void POWER_PeripheralPowerOff(power_config_bit_t powerConfigBit);

/*!
 * @brief Function to enable the power of an analog peripheral when the device is in active mode.
 * @param powerConfigBit    peripheral for which to enable the power
 */
void POWER_PeripheralPowerOn(power_config_bit_t powerConfigBit);

/*!
 * @brief Function to power off certain SRAM segments.
 * @param sramCtrl    mask of sram_ctrl_bit_t bits to power off.
 */
void POWER_DisableSRAM(uint32_t sramCtrl);

/*!
 * @brief Function to power on certain SRAM segments. By default all SRAM segments are on.
 * @param sramCtrl    mask of sram_ctrl_bit_t bits to power on.
 */
void POWER_EnableSRAM(uint32_t sramCtrl);

/*!
 * @brief Function to return power status of all SRAM segments.
 * @return sram_ctrl_bit_t bits of enabled SRAM segments.
 */
uint32_t POWER_GetSRAMConfig(void);

/*!
 * @brief Function to configure the detection level of BOD1.
 * @param level      BOD1 detect level
 * @post             BOD1 is configured to kBOD_NO_ACTION
 * @post             this call must be followed by POWER_ConfigureBOD1() if reset or interrupt is required
 */
void POWER_SetBod1Level(bod_level_t level);

/*!
 * @brief Function to configure the detection level of BOD2.
 * @param level      BOD2 detect level
 * @post             BOD2 is configured to kBOD_NO_ACTION
 * @post             this call must be followed by POWER_ConfigureBOD2() if reset or interrupt is required
 */
void POWER_SetBod2Level(bod_level_t level);

/*!
 * @brief Function to configure the BOD1 action. Note that BOD is disabled automatically when BOD reset is triggered but
 * the settings remain.
 * @param action     the action to take when a BOD is detected
 * @note Set the desired threshold voltage using POWER_SetBod1Level() before enabling BOD interrupt or BOD reset.
 */
void POWER_ConfigureBOD1(bod_action_t action);

/*!
 * @brief Function to configure the BOD2 action. Note that BOD is disabled automatically when BOD reset is triggered but
 * the settings remain.
 * @param action     the action to take when a BOD is detected
 * @note Set the desired threshold voltage using POWER_SetBod2Level() before enabling BOD interrupt or BOD reset.
 */
void POWER_ConfigureBOD2(bod_action_t action);

/*!
 * @brief Function to clear the BOD1 interrupt. It does not
 *        clear the interrupt in the NVIC.
 */
void POWER_ClearBOD1Interrupt(void);

/*!
 * @brief Function to clear the BOD2 interrupt. It does not
 *        clear the interrupt in the NVIC.
 */
void POWER_ClearBOD2Interrupt(void);

/*!
 * @brief Function to retrieve the BOD1 status.
 * @return true as long as BOD1 detects a voltage below the threshold
 */
bool POWER_IsBOD1Active(void);

/*!
 * @brief Function to retrieve the BOD2 status.
 * @return true as long as BOD2 detects a voltage below the threshold
 */
bool POWER_IsBOD2Active(void);

/**
 * @brief Function to enter sleep: stop CPU, continues execution after wake up by any interrupt.
 */
void POWER_EnterSleep(void);

/**
 * @brief Function to enter deep sleep mode: stop CPU and power down flash, active srams put in retention, continues
 * execution after wakeup
 * @param excludeFromPd       mask of power domain peripheral bits to specify which not to power down during
 *                              the low power mode. See comments in low_power_config_bit_t to understand which values
 *                              are valid for this power mode.
 * @param wakeupInterrupts     mask of wake up interrupt bits (see wakeup_irq_t) to specify which interrupt sources can
 *                              cause a wake up from the low power mode. See comments in wakeup_irq_t to understand
 *                              which values are valid for this power mode.
 * @note If any interrupt that is used as wake up source is pending, the system will not go to the low power mode. To
 * avoid this, all interrupts that are configured as wakeupInterrupts will be briefly enabled in the NVIC so they can
 * be handled just before entering the low power mode. This means that the application must have an interrupt handler
 *       installed for every interrupt that is used as a wakeup source. Special care must be given to WDT, BOD1 and BOD2
 *       because they can be handled by the kWAKEUP_SYS interrupt or by their individual kWAKEUP_WDT, kWAKEUP_BOD1 or
 * kWAKEUP_BOD2 interrupt. Please make sure that if using e.g. kWAKEUP_WDT that a handler is installed for WDT_IRQn,
 * otherwise the default handler will be called when this interrupt is briefly enabled. This default handler will block
 * the system forever.
 * @retval kStatus_Success Successfully woken up from low power mode.
 * @retval kStatus_InvalidArgument Invalid argument(s), low power mode was never entered.
 *  Reasons why this function could return kStatus_InvalidArgument:
 *  @li Non existing low_power_config_bit_t value passed to excludeFromPd
 *  @li FRO32K or XTAL32K not enabled (not added to excludeFromPd), when BLE_WUP is exluded from pd (BLE can only
 * remain on, if it has a clock)
 *  @li FRO192M excluded from pd, but HFDSM not
 *  @li BOD Resets enabled (using POWER_ConfigureBOD1 and POWER_ConfigureBOD2) but BOD not powered (using
 * POWER_PeripheralPowerOn)
 *  @li utick timer clock enabled, while going to deep sleep, but HFDSM not added to exclude from pd list.
 *  @li FRO1M clock routed to ctimerX, while going to deep sleep, but HFDSM not added to exclude from pd list.
 */
status_t POWER_EnterDeepSleep(uint32_t excludeFromPd, uint64_t wakeupInterrupts);

/**
 * @brief Function to enter power down mode: power down flash and CPU, active srams put in retention, continues
 * execution after wakeup if CPU retention is enabled and resets after wake up if CPU retention is disabled.
 * interrupt
 * @param excludeFromPd       mask of power domain peripheral bits to specify which not to power down during
 *                              the low power mode. See comments in low_power_config_bit_t to understand which values
 *                              are valid for this power mode.
 * @param wakeupInterrupts     mask of wake up interrupt bits (see wakeup_irq_t) to specify which interrupt sources can
 *                              cause a wake up from the low power mode. See comments in wakeup_irq_t to understand
 *                              which values are valid for this power mode.
 * @param cpuRetentionCtrl    0 = CPU retention is disable / 1 = CPU retention is enabled, all other values are
 * RESERVED (see cpu_retention_config_t).
 * @note If any interrupt that is used as wake up source is pending, the system will not go to the low power mode. To
 * avoid this, all interrupts that are configured as wakeupInterrupts will be briefly enabled in the NVIC so they can
 * be handled just before entering the low power mode. This means that the application must have an interrupt handler
 *       installed for every interrupt that is used as a wakeup source.
 * @retval kStatus_Success Successfully woken up from low power mode if CPU retention was enabled. If CPU retention was
 * not enabled, function will never return because application reboot is expected.
 * @retval kStatus_InvalidArgument Invalid argument(s), low power mode was never entered.
 *  Reasons why this function could return kStatus_InvalidArgument:
 *  @li Non existing low_power_config_bit_t value passed to excludeFromPd
 *  @li FRO32K or XTAL32K not enabled (not added to excludeFromPd), when BLE_WUP is exluded from pd (BLE can only
 * remain on, if it has a clock)
 *  @li BOD Resets enabled (using POWER_ConfigureBOD1 and POWER_ConfigureBOD2) but BOD not powered (using
 * POWER_PeripheralPowerOn)
 *  @li Invalid wake up interrupt used for this power mode.
 */
status_t POWER_EnterPowerDown(uint32_t excludeFromPd, uint64_t wakeupInterrupts, uint32_t cpuRetentionCtrl);

/**
 * @brief Function to enter deep power down mode: power down almost whole chip, reset/wake up by pin, RTC or OS Timer
 * @param excludeFromPd       mask of power domain peripheral bits to specify which not to power down during
 *                              the low power mode. See comments in low_power_config_bit_t to understand which values
 *                              are valid for this power mode.
 * @param wakeupInterrupts     mask of wake up interrupt bits (see wakeup_irq_t) to specify which interrupt sources can
 *                              cause a wake up from the low power mode. See comments in wakeup_irq_t to understand
 *                              values are valid for this power mode.
 * @param wakeupIoCtrl        mask of wake up pin control bits (see wakeup_io_bits_t) to configure the wakeup pin.
 * @note If any interrupt that is used as wake up source is pending, the system will not go to the low power mode. To
 * avoid this, all interrupts that are configured as wakeupInterrupts will be briefly enabled in the NVIC so they can
 * be handled just before entering the low power mode. This means that the application must have an interrupt handler
 *       installed for every interrupt that is used as a wakeup source.
 * @retval kStatus_InvalidArgument Invalid argument(s), low power mode was never entered (in case of successful
 * execution, function will never return because application reboot is expected).
 *  Reasons why this function could return kStatus_InvalidArgument:
 *  @li Non existing low_power_config_bit_t value passed to excludeFromPd
 *  @li BOD Resets enabled (using POWER_ConfigureBOD1 and POWER_ConfigureBOD2) but BOD not powered (using
 * POWER_PeripheralPowerOn)
 *  @li Invalid wake up interrupt used for this power mode.
 */
status_t POWER_EnterDeepPowerDown(uint32_t excludeFromPd, uint64_t wakeupInterrupts, uint32_t wakeupIoCtrl);

/**
 * @brief Function to enter power off mode: power down almost whole chip, reset/wake up by pin only
 * @param excludeFromPd       mask of power domain peripheral bits to specify which not to power down during
 *                              the low power mode. See comments in low_power_config_bit_t to understand which values
 *                              are valid for this power mode.
 * @param wakeupIoCtrl        mask of wake up pin control bits (see wakeup_io_bits_t) to configure the wakeup pin.
 * @retval kStatus_InvalidArgument Invalid argument(s), low power mode was never entered (in case of successful
 * execution, function will never return because application reboot is expected).
 *  Reasons why this function could return kStatus_InvalidArgument:
 *  @li Non existing low_power_config_bit_t value passed to excludeFromPd
 */
status_t POWER_EnterPowerOff(uint32_t excludeFromPd, uint32_t wakeupIoCtrl);

/*!
 * @brief Function that returns the Supply Mode.
 * @return Supply Mode.
 */
dcdc_mode_t POWER_DCDC_GetSupplyMode(void);

/*!
 * @brief Function that sets the Supply mode
 * @retval kStatus_Success Successfully set the supply mode.
 * @retval kStatus_Power_SupplyModeModeInvalid The supply mode is not valid given the startup state of PMC (can be
 * retrieved using POWER_DCDC_GetSupplyMode).
 *       @li PMC reports kDCDC_MODE_HV_SM but chosen mode is kDCDC_MODE_LV_SM
 *       @li PMC reports kDCDC_MODE_LV_SM but chosen mode is kDCDC_MODE_HV_SM
 * @retval kStatus_Power_SupplyModeModeNotSupported The given supply mode is not supported on this silicon version (See
 * @ref SYSTEM_GetChipVersion).
 */
status_t POWER_DCDC_SetSupplyMode(dcdc_mode_t mode);

/*!
 * @brief Function to disable DC/DC convertor. When the device is using an external supply mode, the DC/DC convertor
 * should be disabled. When supply mode is kDCDC_MODE_HV_SM , the DCDC can't be disabled.
 */
void POWER_DCDC_Disable(void);

/*!
 * @brief Function to enable DC/DC convertor.
 */
void POWER_DCDC_Enable(void);

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in buck mode.
 * @pre Can only be used supply mode kDCDC_MODE_HV_SM is used.
 * @param outputLvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBuckOutput(dcdc_buck_output_level_t outputLvl);

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in boost mode.
 * @pre Can only be used supply mode kDCDC_MODE_LV_SM is used.
 * @param outputLvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBoostOutput(dcdc_boost_output_level_t outputLvl);

/*!
 * @brief Function to retrieve the time it took for the DC/DC to have stable output level. Note that the measurement
 * circuit saturates at 0xFFFF (65535 us). The times it takes for the DC/DC to stabilize the output can be used to fine
 * tune the BLE wake up timer. The BLE stack needs to enable 'correction' of the BLE wakeup timer based on how long it
 * takes for the DC/DC to stabilize.
 * @return value that indicates how long it took for DC/DC convertor to have a stable output in us.
 */
uint16_t POWER_DCDC_GetStartupDuration(void);

/*!
 * @brief Function to retrieve the reset cause.
 * @pre
 * @return reset cause register content when it was saved by bootloader - only significant bits
 */
reset_cause_t POWER_GetResetCause(void);

/*!
 * @brief Function to configure the caps of the 32KHz xtal
 * @param capIn The capIn setting
 * @param capOut The capOut setting
 */
void POWER_XTAL32K_ConfigureCaps(uint8_t capIn, uint8_t capOut);

/*!
 * @brief Function to configure the reference output current of the 32KHz xtal (reset value = 1)
 * @param gm The reference output current selection setting (0, 1, 2 or 3)
 */
void POWER_XTAL32K_ConfigureReferenceOutputCurrent(uint8_t gm);

/*!
 * @brief Function to configure the oscillator amplitude of the 32KHz xtal (reset value = 1)
 * @param ampl The oscillator amplitude setting (0, 1, 2 or 3)
 */
void POWER_XTAL32K_ConfigureOscillatorAmplitude(uint8_t ampl);

/*!
 * @brief Function to configure 32k xtal to bypass mode.  Caps will be set to 0 and XO32K block will be powered when
 * bypass is enabled.
 * @param enable True to put xtal in bypass mode, false otherwise
 */
void POWER_XTAL32K_EnableBypass(bool enable);

/*!
 * @brief Function to configure XTAL oscillator start up time.
 *        This function overrides the default start up time of 500 ms.
 * @param delay    delay time in ms
 */
void POWER_XTAL32K_SetStartupTime(uint32_t startupTime);

/*!
 * @brief Function to gate 32M BLE xtal
 * @param enable True to pass clock to BLE block, false otherwise
 */
void POWER_XTAL32M_BLE_GateEnable(bool enable);

/*!
 * @brief Function to configure 32MHz XTAL oscillator start up time.
 *        This function overrides the default start up time of 288 us.
 *        The resolution is 32 us. Only values from 1 until 15 are allowed (1=32us, 15=480us).
 * @param startupTime    startup time in steps of 32 us.
 * @retval kStatus_Success The startup time was successfully configured.
 * @retval kStatus_InvalidArgument The startup time was not between 1 and 15.
 */
status_t POWER_XTAL32M_SetStartupTime(uint8_t startupTime);

/**
 * Measure the voltage on Vbat_hv using BOD1.
 *
 * Normal operation of BOD1 is suspended during the conversion.
 * Voltage must remain stable during conversion in order to get accurate results
 * Note that WDT_BOD_IRQn is disabled during the measurement but is restored afterwards.
 *
 * @param voltage pointer to variable that'll hold the measured voltage in millivolts
 * @return kStatus_Success in case of success.
 */
status_t POWER_MeasureVoltageWithBod1(uint32_t *voltage);

/**
 * Measure the voltage on Vbat_hv using BOD2.
 *
 * Normal operation of BOD2 is suspended during the conversion.
 * Voltage must remain stable during conversion in order to get accurate results
 * Note that WDT_BOD_IRQn is disabled during the measurement but is restored afterwards.
 *
 * @param voltage pointer to variable that'll hold the measured voltage in millivolts
 * @return kStatus_Success in case of success.
 */
status_t POWER_MeasureVoltageWithBod2(uint32_t *voltage);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

#endif /* _FSL_POWER_H_ */
