/*
 * Copyright 2016,2020-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_power.h"
#include "fsl_system.h"
#include "fsl_rom_api.h"

#include "llhwc_cmn.h"
#include "reg_field_name_add.h"
#include "dslp_reg_field_name_add.h"
#include "evnt_schdlr.h"
#include "fsl_gpio.h"
#include "fsl_debug_console.h"

/*! @name Driver version */
/*@{*/
/*! @brief MCXW23 power control version. */
#define FSL_MCXW23_POWER_CONTROL_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/* The settling time in microseconds of the BOD. After changing BOD level, POWER_IsBODActive is only valid after this
 * time */
#define STABILIZATION_TIME_IN_US (40)

// defines that should have been in the header file

/*! LPMODE - Power Mode Control.
 *  0b00..ACTIVE power mode.
 *  0b01..DEEP SLEEP low power mode.
 *  0b10..POWER DOWN low power mode.
 *  0b11..DEEP POWER DOWN low power mode.
 */
#define PMC_CTRL_LPMODE_ACTIVE          (0U)
#define PMC_CTRL_LPMODE_DEEP_SLEEP      (1U)
#define PMC_CTRL_LPMODE_POWER_DOWN      (2U)
#define PMC_CTRL_LPMODE_DEEP_POWER_DOWN (3U)

/*! SELCLOCK - Select the Power Management Controller (PMC) functional clock : .
 *  0b00..1 MHz Free Running Oscillator.
 *  0b01..12 MHz Free Running Oscillator.
 *  0b10..32kHz RTC clock.
 */
#define PMC_CTRL_SELCLOCK_1MHZ_FRO        (0U)
#define PMC_CTRL_SELCLOCK_12MHZ_FRO       (1U)
#define PMC_CTRL_SELCLOCK_32kHZ_RTC_CLOCK (2U)

/*! PDEN_BIAS - Enable or disable bandgap in high or low power mode.
 *  0b00..Bias 0.66V low power mode enabled. This is intended to be used for retention mode of memory or digital
 *  0b01..Bias 0.63V high accuracy mode enabled. During active mode, the bias must be set in high accuracy mode
 *  0b1x..Bias disabled.
 */
#define PMC_PDSLEEPCFG0_PDEN_BIAS_0_66     (0 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_0_63     (1 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_DISABLED (2 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)

/*******************
 * EXPORTED MACROS  *
 ********************/

/* Low Power modes  */
#define LOWPOWER_CTRL_LPMODE_INDEX   PMC_CTRL_LPMODE_SHIFT
#define LOWPOWER_CTRL_LPMODE_MASK    PMC_CTRL_LPMODE_MASK
#define LOWPOWER_CTRL_SELCLOCK_INDEX PMC_CTRL_SELCLOCK_SHIFT
#define LOWPOWER_CTRL_SELCLOCK_MASK  PMC_CTRL_SELCLOCK_MASK
#define LOWPOWER_CTRL_POFFMODE_INDEX PMC_CTRL_POFFMODE_SHIFT
#define LOWPOWER_CTRL_POFFMODE_MASK  PMC_CTRL_POFFMODE_MASK

#define LOWPOWER_CTRL_LPMODE_ACTIVE        0 /*!< ACTIVE mode          */
#define LOWPOWER_CTRL_LPMODE_DEEPSLEEP     1 /*!< DEEP SLEEP mode      */
#define LOWPOWER_CTRL_LPMODE_POWERDOWN     2 /*!< POWER DOWN mode      */
#define LOWPOWER_CTRL_LPMODE_DEEPPOWERDOWN 3 /*!< DEEP POWER DOWN mode */

#define LOWPOWER_CTRL_SELCLOCK_1MHZ 0 /*!< The 1 MHz clock is used during the configuration of the PMC */
#define LOWPOWER_CTRL_SELCLOCK_12MHZ \
    1 /*!< The 12 MHz clock is used during the configuration of the PMC (to speed up PMC configuration process)*/
#define LOWPOWER_CTRL_SELCLOCK_32KHZ 2 /*!< 32kHz clock */

#define LOWPOWER_CTRL_POFFMODE_OFF 0 /*!< Power mode defined by LPMODE */
#define LOWPOWER_CTRL_POFFMODE_ON  1 /*!< Power off */

/* exclude_from_pd direct hardware bits mask */
#define EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK                                                                    \
    (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2 | kLOWPOWERCFG_FRO1M | kLOWPOWERCFG_FRO192M | \
     kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K | kLOWPOWERCFG_TRNG)

/**
 * @brief Wake up timers configuration in Low Power Modes
 */
#define LOWPOWER_TIMERCFG_CTRL_INDEX   0
#define LOWPOWER_TIMERCFG_CTRL_MASK    (0x1UL << LOWPOWER_TIMERCFG_CTRL_INDEX)
#define LOWPOWER_TIMERCFG_TIMER_INDEX  1
#define LOWPOWER_TIMERCFG_TIMER_MASK   (0x7UL << LOWPOWER_TIMERCFG_TIMER_INDEX)
#define LOWPOWER_TIMERCFG_OSC32K_INDEX 4
#define LOWPOWER_TIMERCFG_OSC32K_MASK  (0x1UL << LOWPOWER_TIMERCFG_OSC32K_INDEX)

#define LOWPOWER_TIMERCFG_CTRL_DISABLE 0 /*!< Wake Timer Disable */
#define LOWPOWER_TIMERCFG_CTRL_ENABLE  1 /*!< Wake Timer Enable  */

/**
 * @brief Primary Wake up timers configuration in Low Power Modes
 */
#define LOWPOWER_TIMERCFG_TIMER_RTC1KHZ 0 /*!< 1 KHz Real Time Counter (RTC) used as wake up source */
#define LOWPOWER_TIMERCFG_TIMER_RTC1HZ  1 /*!< 1 Hz Real Time Counter (RTC) used as wake up source  */
#define LOWPOWER_TIMERCFG_TIMER_OSTIMER 2 /*!< OS Event Timer used as wake up source                */

#define LOWPOWER_TIMERCFG_OSC32K_FRO32KHZ  0 /*!< Wake up Timers uses FRO 32 KHz as clock source      */
#define LOWPOWER_TIMERCFG_OSC32K_XTAL32KHZ 1 /*!< Wake up Timers uses Chrystal 32 KHz as clock source */

/*
 * defines for functions uint32_t CLOCK_GetCoreSysClkConfiguration(void) and void
 * CLOCK_SetCoreSysClkConfiguration(uint32_t configuration);
 */
#define SYSCON_MAINCLKSELA_SEL_BITS               3
#define SYSCON_MAINCLKSELB_SEL_BITS               3
#define SYSCON_AHBCLKDIV_DIV_BITS                 8
#define ANACTRL_FRO192M_CTRL_ENA_BITS             5
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS          1
#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS 1
#define PMC_PDRUNCFG0_PDEN_FRO192M_BITS           1

#define CONFIGURATION_SYSCON_MAINCLKSELA_SHIFT       (0)
#define CONFIGURATION_SYSCON_MAINCLKSELB_SHIFT       (CONFIGURATION_SYSCON_MAINCLKSELA_SHIFT + SYSCON_MAINCLKSELA_SEL_BITS)
#define CONFIGURATION_SYSCON_AHBCLKDIV_SHIFT         (CONFIGURATION_SYSCON_MAINCLKSELB_SHIFT + SYSCON_MAINCLKSELB_SEL_BITS)
#define CONFIGURATION_ANACTRL_FRO192M_CTRL_ENA_SHIFT (CONFIGURATION_SYSCON_AHBCLKDIV_SHIFT + SYSCON_AHBCLKDIV_DIV_BITS)
#define CONFIGURATION_SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT \
    (CONFIGURATION_ANACTRL_FRO192M_CTRL_ENA_SHIFT + ANACTRL_FRO192M_CTRL_ENA_BITS)
#define CONFIGURATION_SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT \
    (CONFIGURATION_SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT + SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS)
#define CONFIGURATION_PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT \
    (CONFIGURATION_SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT + SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS)

#define CPU_RETENTION_RAMX_STORAGE_START_ADDR (0x4002000) //  beginning of SRAM_X2

#define XO_SLAVE_EN (1)

typedef enum dcdc_exclude_config_s
{
    kDCDC_EXCLUDE_CONFIG_A0_A1_A2 = 0U,
    kDCDC_EXCLUDE_CONFIG_A3_A4    = 1U,
    kDCDC_EXCLUDE_CONFIG_A5       = 2U,
    kDCDC_EXCLUDE_CONFIG_COUNT    = 3U,
} dcdc_exclude_config_t;

typedef enum ldo_dig_vadj_s
{
    kLDO_DIG_900mv  = 0U,
    kLDO_DIG_950mv  = 1U,
    kLDO_DIG_1000mv = 2U,
    kLDO_DIG_1050mv = 3U,
} ldo_dig_vadj_t;

typedef enum ldo_mem_vadj_s
{
    kLDO_MEM_900mv  = 0U,
    kLDO_MEM_950mv  = 1U,
    kLDO_MEM_1000mv = 2U,
    kLDO_MEM_1050mv = 3U,
} ldo_mem_vadj_t;

/*
 * AOREG1 defines that match with bootloader
 */
#define kAOREG1_DCDC_MODE_XR_SM_SS_SHIFT (24)
#define kAOREG1_DCDC_MODE_XR_SM_SS_MASK  (1 << kAOREG1_DCDC_MODE_XR_SM_SS_SHIFT)
#define kAOREG1_DCDC_MODE_XR_SM_DS_SHIFT (25)
#define kAOREG1_DCDC_MODE_XR_SM_DS_MASK  (1 << kAOREG1_DCDC_MODE_XR_SM_DS_SHIFT)

#define kAOREG1_BOD1_SHIFT (26)
#define kAOREG1_BOD1_MASK  (1 << kAOREG1_BOD1_SHIFT)
#define kAOREG1_BOD2_SHIFT (27)
#define kAOREG1_BOD2_MASK  (1 << kAOREG1_BOD2_SHIFT)

/* On silicon A0 and A2 silicon, when in XRSM mode, startup value of DC/DC was important for further configuration,
that's why the variants XR_SS_BOOST/XR_SS_BUCK/DS_BOOST/DS_BUCK exist (they have nothing to do with actual buck or
boost). From A3 onwards, when in XRSM mode, DC/DC always startups in Buck. */
typedef enum supply_mode_s
{
    kSUPPLY_MODE_HV_SM       = 0U,
    kSUPPLY_MODE_XR_SS_BOOST = 1U,
    kSUPPLY_MODE_XR_SS_BUCK  = 2U,
    kSUPPLY_MODE_XR_DS_BOOST = 3U,
    kSUPPLY_MODE_XR_DS_BUCK  = 4U,
    kSUPPLY_MODE_LV_SM       = 5U,
    kSUPPLY_MODE_COUNT       = 6U,
} supply_mode_t;

typedef enum lp_mode_s
{
    kLP_MODE_DEEPSLEEP     = 0U,
    kLP_MODE_POWERDOWN     = 1U,
    kLP_MODE_DEEPPOWERDOWN = 2U,
    kLP_MODE_POWEROFF      = 3U,
    kLP_MODE_COUNT         = 4U,
} lp_mode_t;

/* Code relies on order/values */
typedef enum DCDC_exclude_mode_s
{
    kDCDC_EXCLUDE_NONE   = 0U,
    kDCDC_EXCLUDE_DCDC   = 1U,
    kDCDC_EXCLUDE_BYPASS = 2U,
    kDCDC_EXCLUDE_BOTH   = 3U,
    kDCDC_EXCLUDE_COUNT  = 4U,
} DCDC_exclude_mode_t;

/**
 * @brief List of DC/DC modes
 * defines must match with dcdc_mode_t
 */
typedef enum dcdc_hw_mode_s
{
    kDCDC_HW_MODE_HV_SM = 1U, /*!< HV supplied */
    kDCDC_HW_MODE_LV_SM = 2U, /*!< LV supplied */
} dcdc_hw_mode_t;

typedef status_t (*POWER_DCDC_exclude_function_t)(uint32_t *exclude_from_pd);

/*******************************************************************************
 * Global variables
 ******************************************************************************/
#define DEFAULT_FRO_STARTUP_DELAY  (100) /* in ms */
#define DEFAULT_XTAL_STARTUP_DELAY (500) /* in ms */
static uint32_t POWER_XTALStartupTime = DEFAULT_XTAL_STARTUP_DELAY;

/*******************************************************************************
 * Static functions
 ******************************************************************************/
static void POWER_delay_us(uint32_t delay)
{
#ifdef DEBUG
    if (SystemCoreClock == kFreq_12MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
    else if (SystemCoreClock == kFreq_24MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
    else if (SystemCoreClock == kFreq_32MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
#else
    if (SystemCoreClock == kFreq_12MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
    else if (SystemCoreClock == kFreq_24MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
    else if (SystemCoreClock == kFreq_32MHz)
    {
        while (delay--)
        {
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
            __NOP();
        }
    }
#endif
}

static void POWER_delay_ms(uint32_t delay)
{
    POWER_delay_us(delay * 1000);
}

static void POWER_SavePinRegisters(void)
{
#define IOCON_GPIO_FUNC12 0xC

    uint32_t *cpu_ret_store_ptr =
        (uint32_t *)(CPU_RETENTION_RAMX_STORAGE_START_ADDR + 0x900); // size 25*4=100 (0x64)  0x900 - 0x964
    uint32_t pinsDir = GPIO->DIR[0];

    *cpu_ret_store_ptr++ = pinsDir;
    *cpu_ret_store_ptr++ = GPIO->PIN[0];
    for (uint32_t i = 0; i <= 22; i++)
    {
        *cpu_ret_store_ptr++ = IOCON->PIO[0][i];
        /* Set all pins that are configured as output, temporary to FUNC12 before going to lower power
        to avoid a 120ns pulse during wakeup from power down. (see HCIOT-4852 and artf1215149) */
        if ((pinsDir & (1 << i)) > 0)
        {
            IOCON->PIO[0][i] = (IOCON->PIO[0][i] & ~IOCON_PIO_FUNC_MASK) | (IOCON_GPIO_FUNC12 & IOCON_PIO_FUNC_MASK);
        }
    }
}

static void POWER_RestorePinRegisters(void)
{
    uint32_t *cpu_ret_store_ptr = (uint32_t *)(CPU_RETENTION_RAMX_STORAGE_START_ADDR + 0x900);
    GPIO->DIR[0]                = *cpu_ret_store_ptr++;
    GPIO->PIN[0]                = *cpu_ret_store_ptr++;
    for (uint32_t i = 0; i <= 22; i++)
    {
        IOCON->PIO[0][i] = *cpu_ret_store_ptr++;
    }
}
/*
 * Complete sys clock configuration consists of settings in
 * MAINCLKSELA, MAINCLKSELB, AHBCLKDIV, PDRUNCFG, FRO192M_CTRL
 * This function reads the actual settings and returns them in a 32-bit word to be used in
 * CLOCK_SetCoreSysClkConfiguration
 */
static uint32_t CLOCK_GetCoreSysClkConfiguration(void)
{
    uint32_t return_value = 0;
    uint32_t pos          = 0;
    return_value |= ((SYSCON->MAINCLKSELA & SYSCON_MAINCLKSELA_SEL_MASK) << pos);
    pos += SYSCON_MAINCLKSELA_SEL_BITS;
    return_value |= ((SYSCON->MAINCLKSELB & SYSCON_MAINCLKSELB_SEL_MASK) << pos);
    pos += SYSCON_MAINCLKSELB_SEL_BITS;
    return_value |= ((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) << pos);
    pos += SYSCON_AHBCLKDIV_DIV_BITS;
    return_value |=
        (((ANACTRL->FRO192M_CTRL & (ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK | ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK |
                                    ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK | ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK |
                                    ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK)) >>
          ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT)
         << pos);
    pos += ANACTRL_FRO192M_CTRL_ENA_BITS;
    return_value |=
        (((SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK) >> SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT) << pos);
    pos += SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS;
    return_value |= (((SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK) >>
                      SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT)
                     << pos);
    pos += SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS;
    return_value |= (((PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) >> PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT) << pos);
    // most probably no need to add PDEN_FRO1M, PDEN_XTAL32K, PDEN_FRO32K here
    return return_value;
}

/*
 * This function restores the actual Sys Clock configuration settings as readn by CLOCK_GetCoreSysClkConfiguration
 */
static void CLOCK_SetCoreSysClkConfiguration(uint32_t configuration)
{
    PMC->PDRUNCFG0 = (PMC->PDRUNCFG0 & ~PMC_PDRUNCFG0_PDEN_FRO192M_MASK) |
                     ((configuration >> CONFIGURATION_PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT) &
                      ((1 << PMC_PDRUNCFG0_PDEN_FRO192M_BITS) - 1))
                         << PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT;

    SYSCON->CLOCK_CTRL = (SYSCON->CLOCK_CTRL & ~SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK) |
                         ((configuration >> CONFIGURATION_SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT) &
                          ((1 << SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS) - 1))
                             << SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT;

    SYSCON->CLOCK_CTRL = (SYSCON->CLOCK_CTRL & ~SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK) |
                         ((configuration >> CONFIGURATION_SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT) &
                          ((1 << SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS) - 1))
                             << SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT;

    ANACTRL->FRO192M_CTRL =
        ((configuration >> CONFIGURATION_ANACTRL_FRO192M_CTRL_ENA_SHIFT) & ((1 << ANACTRL_FRO192M_CTRL_ENA_BITS) - 1))
        << ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT;
    SYSCON->AHBCLKDIV   = (configuration >> CONFIGURATION_SYSCON_AHBCLKDIV_SHIFT) & SYSCON_AHBCLKDIV_DIV_MASK;
    SYSCON->MAINCLKSELB = (configuration >> CONFIGURATION_SYSCON_MAINCLKSELB_SHIFT) & SYSCON_MAINCLKSELB_SEL_MASK;
    SYSCON->MAINCLKSELA = configuration & SYSCON_MAINCLKSELA_SEL_MASK;
}

static status_t POWER_Bypass(uint32_t *exclude_from_pd)
{
    /* set enable LPBS request */
    PMC->DCDC0 |= PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* disable DCDC during low power mode */
    *exclude_from_pd &= ~kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

static status_t POWER_On(uint32_t *exclude_from_pd)
{
    /* disable LPBS */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* enable DCDC during low power mode */
    *exclude_from_pd |= kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

static status_t POWER_Off(uint32_t *exclude_from_pd)
{
    /* disable LPBS */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* disable DCDC during low power mode */
    *exclude_from_pd &= ~kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

static status_t POWER_OnAndBypass(uint32_t *exclude_from_pd)
{
    /* set enable LPBS request */
    PMC->DCDC0 |= PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* enable DCDC during low power mode */
    *exclude_from_pd |= kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

static status_t POWER_Error(uint32_t *exclude_from_pd)
{
    return kStatus_Fail;
}

static status_t POWER_Disabled(uint32_t *exclude_from_pd)
{
    return kStatus_Fail;
}

static status_t POWER_CannotBeUsed(uint32_t *exclude_from_pd)
{
    return kStatus_Fail;
}

static status_t POWER_InvalidArgument(uint32_t *exclude_from_pd)
{
    return kStatus_InvalidArgument;
}

/*
 * - On A0 and A2 (A1 does not exist), both Boost and Buck are supported.
 * - On A3 and A4, Boost is not available in HW. Table bellow will return error.
 * - On A5, Buck is not available in HW. Table bellow will return error.
 */
static const POWER_DCDC_exclude_function_t
    POWER_DCDC_exclude_function[kDCDC_EXCLUDE_CONFIG_COUNT][kLP_MODE_COUNT][kSUPPLY_MODE_COUNT][kDCDC_EXCLUDE_COUNT] = {
        /* A0, A1 and A2 */
        {{
             /* DEEPSLEEP */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},        /* kSUPPLY_MODE_HV_SM */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},        /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_OnAndBypass, POWER_Error, POWER_Error, POWER_InvalidArgument}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},         /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_CannotBeUsed, POWER_CannotBeUsed, POWER_CannotBeUsed,
              POWER_CannotBeUsed},                                       /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWERDOWN */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},        /* kSUPPLY_MODE_HV_SM */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},        /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_OnAndBypass, POWER_Error, POWER_Error, POWER_InvalidArgument}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},         /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_CannotBeUsed, POWER_CannotBeUsed, POWER_CannotBeUsed,
              POWER_CannotBeUsed},                                       /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* DEEPPOWERDOWN */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument},           /* kSUPPLY_MODE_HV_SM */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},        /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_OnAndBypass, POWER_Error, POWER_Error, POWER_InvalidArgument}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},         /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_CannotBeUsed, POWER_CannotBeUsed, POWER_CannotBeUsed,
              POWER_CannotBeUsed},                                       /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWEROFF */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},   /* kSUPPLY_MODE_HV_SM */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},   /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},   /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},   /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Error, POWER_Error, POWER_Error, POWER_InvalidArgument}, /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},   /* kSUPPLY_MODE_LV_SM */
         }},
        /* A3 and A4 */
        {{
             /* DEEPSLEEP */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},    /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWERDOWN */
             {POWER_Bypass, POWER_On, POWER_Bypass, POWER_InvalidArgument},    /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* DEEPPOWERDOWN */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument},       /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWEROFF */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_LV_SM */
         }},
        /* A5 */
        {{
             /* DEEPSLEEP */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument},       /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWERDOWN */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument},       /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* DEEPPOWERDOWN */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_On, POWER_Bypass, POWER_InvalidArgument},       /* kSUPPLY_MODE_LV_SM */
         },
         {
             /* POWEROFF */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_HV_SM */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_SS_BUCK */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BOOST */
             {POWER_Disabled, POWER_Disabled, POWER_Disabled, POWER_Disabled}, /* kSUPPLY_MODE_XR_DS_BUCK */
             {POWER_Off, POWER_Error, POWER_Error, POWER_InvalidArgument},     /* kSUPPLY_MODE_LV_SM */
         }}};

static status_t POWER_SetPowerConfiguration(lp_mode_t lp_mode, uint32_t *exclude_from_pd)
{
    chip_version_t version = SYSTEM_GetChipVersion();
    dcdc_mode_t mode       = POWER_DCDC_GetSupplyMode();
    dcdc_hw_mode_t hw_mode =
        (dcdc_hw_mode_t)((PMC->STATUSPWR & PMC_STATUSPWR_DCDCMODE_MASK) >> PMC_STATUSPWR_DCDCMODE_SHIFT);
    status_t status = kStatus_Success;
    dcdc_exclude_config_t dcdc_exclude_config;

    DCDC_exclude_mode_t dcdc_exclude = kDCDC_EXCLUDE_NONE;
    if (*exclude_from_pd & kLOWPOWERCFG_DCDC_BYPASS)
    {
        dcdc_exclude |= kDCDC_EXCLUDE_BYPASS;
    }
    if (*exclude_from_pd & kLOWPOWERCFG_DCDC)
    {
        dcdc_exclude |= kDCDC_EXCLUDE_DCDC;
    }

    /* Translate chip_version_t into number to use in lookup table */
    if (version <= kCHIPVERSION_A2)
    {
        dcdc_exclude_config = kDCDC_EXCLUDE_CONFIG_A0_A1_A2;
    }
    else if (version > kCHIPVERSION_A2 && version <= kCHIPVERSION_A4)
    {
        dcdc_exclude_config = kDCDC_EXCLUDE_CONFIG_A3_A4;
    }
    else if (version > kCHIPVERSION_A4 && version <= kCHIPVERSION_A5)
    {
        dcdc_exclude_config = kDCDC_EXCLUDE_CONFIG_A5;
    }
    else
    {
        return kStatus_Power_ChipVersionNotSupported;
    }

    /********************************* BUCK MODE *********************************/
    if (mode == kDCDC_MODE_HV_SM)
    {
        status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_HV_SM][dcdc_exclude](
            exclude_from_pd);
    }
    /********************************* XRSM SS MODE *********************************/
    else if (mode == kDCDC_MODE_XR_SM_SS)
    {
        /* XRSM mode but pmc started up as boost but actual mode is XRSM) */
        if (hw_mode == kDCDC_HW_MODE_LV_SM)
        {
            status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_XR_SS_BOOST][dcdc_exclude](
                exclude_from_pd);
        }
        /* XRSM mode but pmc started up as buck but actual mode is XRSM) */
        else if (hw_mode == kDCDC_HW_MODE_HV_SM)
        {
            status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_XR_SS_BUCK][dcdc_exclude](
                exclude_from_pd);
        }
    }
    /********************************* XRSM DS MODE *********************************/
    else if (mode == kDCDC_MODE_XR_SM_DS)
    {
        /* XRSM mode but pmc started up as boost but actual mode is XRSM) */
        if (hw_mode == kDCDC_HW_MODE_LV_SM)
        {
            status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_XR_DS_BOOST][dcdc_exclude](
                exclude_from_pd);
        }
        /* XRSM mode but pmc started up as buck but actual mode is XRSM) */
        else if (hw_mode == kDCDC_HW_MODE_HV_SM)
        {
            status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_XR_DS_BUCK][dcdc_exclude](
                exclude_from_pd);
        }
    }
    /********************************* BOOST MODE *********************************/
    else if (mode == kDCDC_MODE_LV_SM)
    {
        status = POWER_DCDC_exclude_function[dcdc_exclude_config][lp_mode][kSUPPLY_MODE_LV_SM][dcdc_exclude](
            exclude_from_pd);
    }

    return status;
}

static void EnableBOD1Interrupts(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

static void DisableBOD1Interrupts(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl &= ~ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

static void EnableBOD1Resets(void)
{
    uint32_t reset_ctrl = PMC->RESETCTRL;
    reset_ctrl &= (~(PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK));
    reset_ctrl |= (1 << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT | 1 << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = reset_ctrl;
}

static void DisableBOD1Resets(void)
{
    // note: direct clear and modify in the register triggers a hard reset in simulation.
    uint32_t reset_ctrl = PMC->RESETCTRL;
    reset_ctrl &= (~(PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK));
    reset_ctrl |= (2 << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT | 2 << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = reset_ctrl;
}

static void EnableBOD2Interrupts(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

static void DisableBOD2Interrupts(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl &= ~ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

static void EnableBOD2Resets(void)
{
    uint32_t reset_ctrl = PMC->RESETCTRL;
    reset_ctrl &= (~(PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK));
    reset_ctrl |= (1 << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT | 1 << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = reset_ctrl;
}

static void DisableBOD2Resets(void)
{
    // note: direct clear and modify in the register triggers a hard reset in simulation.
    uint32_t reset_ctrl = PMC->RESETCTRL;
    reset_ctrl &= (~(PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK));
    reset_ctrl |= (2 << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT | 2 << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = reset_ctrl;
}

static uint32_t AdjustedLevelRegisterSetting(bod_level_t level, uint8_t offset)
{
    int8_t signed_offset = offset;
    int8_t adjusted_hysteresis;
    uint8_t adjusted_triglvl = ((level & PMC_BOD1_TRIGLVL_MASK) >> PMC_BOD1_TRIGLVL_SHIFT);
    uint8_t adjusted_lvlsel  = ((level & PMC_BOD1_LVLSEL_MASK) >> PMC_BOD1_LVLSEL_SHIFT);

    /* offset is 5 bits 2-complement encoded */
    if (offset & 0x10)
    {
        signed_offset -= 0x20;
    }

    /* level contains the register value to be set in the BODx register. We calculate the adjusted_hysteresis
     * from the hysteresis setting, the lvlsel setting and the offset. We extend the definition beyond 0 - 3 with
     * -5 for -100mV, -4 for -75mV, -3 for -50mV, -2 for -25mV, -1 for 0mV, 5 for +125mV, 6 for +150mV and 7 for +175mV.
     */
    if (adjusted_lvlsel == 1)
    {
        adjusted_hysteresis = -1;
    }
    else
    {
        adjusted_hysteresis = ((level & PMC_BOD1_HYST_MASK) >> PMC_BOD1_HYST_SHIFT);
    }
    adjusted_hysteresis -= signed_offset;

    if (adjusted_triglvl > 10) /* triglvl has steps of 100mV for setting 10 and above */
    {
        if (adjusted_hysteresis < -1)
        {
            adjusted_hysteresis += 4;
            adjusted_triglvl -= 1;
        }
        if (adjusted_hysteresis > 3)
        {
            adjusted_hysteresis -= 4;
            adjusted_triglvl += 1;
        }
    }
    else
    {
        if (adjusted_triglvl == 10) /* triglvl has steps for setting 10 of 100mV upwards and 50mV downwards */
        {
            if (adjusted_hysteresis < -3)
            {
                adjusted_hysteresis += 2;
                adjusted_triglvl -= 1;
            }
            if (adjusted_hysteresis < -1)
            {
                adjusted_hysteresis += 2;
                adjusted_triglvl -= 1;
            }
            if (adjusted_hysteresis > 3)
            {
                adjusted_hysteresis -= 4;
                adjusted_triglvl += 1;
            }
        }
        else /* triglvl has steps of 50mV for setting 9 and below */
        {
            if (adjusted_hysteresis < -3)
            {
                adjusted_hysteresis += 2;
                adjusted_triglvl -= 1;
            }
            if (adjusted_hysteresis < -1)
            {
                adjusted_hysteresis += 2;
                adjusted_triglvl -= 1;
            }
            if (adjusted_hysteresis > 5)
            {
                adjusted_hysteresis -= 2;
                adjusted_triglvl += 1;
            }
            if (adjusted_hysteresis > 3)
            {
                adjusted_hysteresis -= 2;
                adjusted_triglvl += 1;
            }
        }
    }

    /* To add 0mV we have to set adjusted_lvlsel to 1, otherwise it must be set to 0. */
    if (adjusted_hysteresis == -1)
    {
        adjusted_hysteresis = 0;
        adjusted_lvlsel     = 1;
    }
    else
    {
        adjusted_lvlsel = 0;
    }

    return (uint32_t)((adjusted_lvlsel << PMC_BOD1_LVLSEL_SHIFT) | (adjusted_hysteresis << PMC_BOD1_HYST_SHIFT) |
                      (adjusted_triglvl << PMC_BOD1_TRIGLVL_SHIFT));
}
/* Below is test code for the AdjustedLevelRegisterSetting function. You can call TestAdjustedLevelRegisterSetting()
 * from the pmc_sandbox app. */
#if 0
extern void SysTick_DelayTicks(uint32_t n);
static uint32_t BodRegisterToMilliVolt(uint32_t regValue)
{
    uint32_t voltage;
    uint32_t triglvl = ((regValue & PMC_BOD1_TRIGLVL_MASK) >> PMC_BOD1_TRIGLVL_SHIFT);
    uint32_t hyst = ((regValue & PMC_BOD1_HYST_MASK) >> PMC_BOD1_HYST_SHIFT);

    if ((regValue & PMC_BOD1_MODE_MASK) || (triglvl > 26))
    {
        PRINTF("INVALID REGVALUE\n");
        return 0;
    }

    if (triglvl <= 10)
    {
        voltage = 1000 + (triglvl * 50);
    }
    else
    {
        voltage = 1500 + ((triglvl - 10) * 100);
    }
    if ((regValue & PMC_BOD1_LVLSEL_MASK) == 0)
    {
        voltage += ((hyst + 1) * 25);
    }

    return voltage;
}
extern void TestAdjustedLevelRegisterSetting(void)
{
    uint32_t level;
    uint32_t adjusted_level;

    for(uint32_t triglvl = 2; triglvl < 0x19; triglvl++)
    {
        for(uint32_t hyst = 0; hyst < 5; (triglvl < 10 ? hyst += 4 : hyst++))
        {
            if (hyst == 4)
            {
                level = triglvl | 0x100U;
            }
            else
            {
                level = triglvl | (hyst << 5);
            }
            for(int8_t offset = -4; offset < 5; offset++)
            {
                if (offset == -4)
                {
                    adjusted_level = AdjustedLevelRegisterSetting((bod_level_t)level, 0x1C);
                }
                if (offset == -3)
                {
                    adjusted_level = AdjustedLevelRegisterSetting((bod_level_t)level, 0x1D);
                }
                if (offset == -2)
                {
                    adjusted_level = AdjustedLevelRegisterSetting((bod_level_t)level, 0x1E);
                }
                if (offset == -1)
                {
                    adjusted_level = AdjustedLevelRegisterSetting((bod_level_t)level, 0x1F);
                }
                if (offset >= 0)
                {
                    adjusted_level = AdjustedLevelRegisterSetting((bod_level_t)level, (uint8_t)offset);
                }
                if (offset < 0)
                {
                    PRINTF("level = 0x%x, offset = -%d, adjusted_level = 0x%x\n", level, -offset, adjusted_level);
                    PRINTF("%d mV changed to %d mV, to compensate offset = -%d\n", BodRegisterToMilliVolt(level), BodRegisterToMilliVolt(adjusted_level), -offset);
                }
                else
                {
                    PRINTF("level = 0x%x, offset = %d, adjusted_level = 0x%x\n", level, offset, adjusted_level);
                    PRINTF("%d mV changed to %d mV, to compensate offset = %d\n", BodRegisterToMilliVolt(level), BodRegisterToMilliVolt(adjusted_level), offset);
                }
                if (BodRegisterToMilliVolt(adjusted_level) + (offset * 25) != BodRegisterToMilliVolt(level))
                {
                    PRINTF("ERROR\n");
                }
                SysTick_DelayTicks(10);
            }
        }
    }
}
#endif

/**
 * Measure the voltage on Vbat_hv using the given BOD instance.
 *
 * Normal operation of the selected BOD is suspended during the conversion.
 * Voltage must remain stable during conversion in order to get accurate results
 * Note that WDT_BOD_IRQn is disabled during the measurement but is restored afterwards.
 *
 * @param instance 0 for BOD1 and 1 for BOD2.
 * @param voltage pointer to variable that'll hold the measured voltage in millivolts
 * @return kStatus_Success in case of success.
 */
static status_t MeasureVoltage(uint32_t instance, uint32_t *voltage)
{
    static const uint16_t levelSettings[] = {
        kBOD_LEVEL_1100mv, kBOD_LEVEL_1125mv, kBOD_LEVEL_1150mv, kBOD_LEVEL_1175mv, kBOD_LEVEL_1200mv,
        kBOD_LEVEL_1225mv, kBOD_LEVEL_1250mv, kBOD_LEVEL_1275mv, kBOD_LEVEL_1300mv, kBOD_LEVEL_1325mv,
        kBOD_LEVEL_1350mv, kBOD_LEVEL_1375mv, kBOD_LEVEL_1400mv, kBOD_LEVEL_1425mv, kBOD_LEVEL_1450mv,
        kBOD_LEVEL_1475mv, kBOD_LEVEL_1500mv, kBOD_LEVEL_1525mv, kBOD_LEVEL_1550mv, kBOD_LEVEL_1575mv,
        kBOD_LEVEL_1600mv, kBOD_LEVEL_1625mv, kBOD_LEVEL_1650mv, kBOD_LEVEL_1675mv, kBOD_LEVEL_1700mv,
        kBOD_LEVEL_1725mv, kBOD_LEVEL_1750mv, kBOD_LEVEL_1775mv, kBOD_LEVEL_1800mv, kBOD_LEVEL_1825mv,
        kBOD_LEVEL_1850mv, kBOD_LEVEL_1875mv, kBOD_LEVEL_1900mv, kBOD_LEVEL_1925mv, kBOD_LEVEL_1950mv,
        kBOD_LEVEL_1975mv, kBOD_LEVEL_2000mv, kBOD_LEVEL_2025mv, kBOD_LEVEL_2050mv, kBOD_LEVEL_2075mv,
        kBOD_LEVEL_2100mv, kBOD_LEVEL_2125mv, kBOD_LEVEL_2150mv, kBOD_LEVEL_2175mv, kBOD_LEVEL_2200mv,
        kBOD_LEVEL_2225mv, kBOD_LEVEL_2250mv, kBOD_LEVEL_2275mv, kBOD_LEVEL_2300mv, kBOD_LEVEL_2325mv,
        kBOD_LEVEL_2350mv, kBOD_LEVEL_2375mv, kBOD_LEVEL_2400mv, kBOD_LEVEL_2425mv, kBOD_LEVEL_2450mv,
        kBOD_LEVEL_2475mv, kBOD_LEVEL_2500mv, kBOD_LEVEL_2525mv, kBOD_LEVEL_2550mv, kBOD_LEVEL_2575mv,
        kBOD_LEVEL_2600mv, kBOD_LEVEL_2625mv, kBOD_LEVEL_2650mv, kBOD_LEVEL_2675mv, kBOD_LEVEL_2700mv,
        kBOD_LEVEL_2725mv, kBOD_LEVEL_2750mv, kBOD_LEVEL_2775mv, kBOD_LEVEL_2800mv, kBOD_LEVEL_2825mv,
        kBOD_LEVEL_2850mv, kBOD_LEVEL_2875mv, kBOD_LEVEL_2900mv, kBOD_LEVEL_2925mv, kBOD_LEVEL_2950mv,
        kBOD_LEVEL_2975mv, kBOD_LEVEL_3000mv, kBOD_LEVEL_3025mv, kBOD_LEVEL_3050mv, kBOD_LEVEL_3075mv,
        kBOD_LEVEL_3100mv};
    uint32_t intMask =
        instance == 0 ? ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK : ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK;
    uint32_t resetMask               = instance == 0 ?
                                           PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK :
                                           PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK;
    uint32_t nvicBodIrq              = instance == 0 ? BOD1_IRQn : BOD2_IRQn;
    void (*setBodLevel)(bod_level_t) = instance == 0 ? POWER_SetBod1Level : POWER_SetBod2Level;
    bool (*isBodActive)(void)        = instance == 0 ? POWER_IsBOD1Active : POWER_IsBOD2Active;
    uint32_t regValue;
    int32_t direction;
    uint32_t bodActive;
    uint32_t previousBodActive;
    /* Store previous measurement as a static variable. Always start from previous measurement */
    static uint32_t currentSetting = ARRAY_SIZE(levelSettings) - 1;

    if (instance > 1)
    {
        return kStatus_InvalidArgument;
    }

    /* Store interrupt settings */
    uint32_t storedIntVal = ANACTRL->BOD_DCDC_INT_CTRL & intMask;
    /* Store NVIC interrupt setting */
    uint32_t storedNvicBodIrq = NVIC_GetEnableIRQ(nvicBodIrq);
    /* Store NVIC SYS interrupt setting */
    uint32_t storedNvicSysIrq = NVIC_GetEnableIRQ(WDT_BOD_IRQn);
    /* Store reset settings */
    uint32_t storedResetVal = PMC->RESETCTRL & resetMask;

    /* Disable NVIC interrupt */
    NVIC_DisableIRQ(nvicBodIrq);
    NVIC_DisableIRQ(WDT_BOD_IRQn);

    /* Enable interrupts */
    (instance == 0 ? EnableBOD1Interrupts : EnableBOD2Interrupts)();

    /* Disable reset */
    (instance == 0 ? DisableBOD1Resets : DisableBOD2Resets)();

    /* Start from previous measurement */
    setBodLevel(levelSettings[currentSetting]);
    POWER_delay_us(STABILIZATION_TIME_IN_US);

    /* The actual voltage is determined by changing the BOD trigger level until the level crosses Vbat_hv.
     * Determine direction of change from bodActive: if Vbat_hv is higher than trigger level,
     * the trigger level is increased each iteration until it is no longer below Vbat and vice versa.*/
    bodActive = previousBodActive = isBodActive();
    direction                     = bodActive ? -1 : 1;

    /* Change level until bodActive status changes or until end of range (based on direction) */
    while ((bodActive == previousBodActive) && ((currentSetting < ARRAY_SIZE(levelSettings) - 1) || direction < 0) &&
           ((currentSetting > 0) || direction > 0))
    {
        /* Update trigger level */
        currentSetting += direction;
        setBodLevel(levelSettings[currentSetting]);
        POWER_delay_us(STABILIZATION_TIME_IN_US);
        previousBodActive = bodActive;
        bodActive         = isBodActive();
    }

    /* Is Vbat_hv higher? */
    if (!bodActive && currentSetting < ARRAY_SIZE(levelSettings) - 1)
    {
        /* Yes, this means that trigger level is one step below actual voltage level. Adjust level. */
        currentSetting++;
    }

    /* Convert setting into voltage */
    *voltage = 1100 + currentSetting * 25;

    /* Restore reset settings */
    regValue = PMC->RESETCTRL;
    regValue = (regValue & ~resetMask) | storedResetVal;
    /* Restore interrupt settings */
    ANACTRL->BOD_DCDC_INT_CTRL |= storedIntVal;
    /* Restore NVIC interrupt setting */
    (storedNvicBodIrq ? NVIC_EnableIRQ : NVIC_DisableIRQ)(nvicBodIrq);
    /* Restore NVIC SYS interrupt setting */
    (storedNvicSysIrq ? NVIC_EnableIRQ : NVIC_DisableIRQ)(WDT_BOD_IRQn);

    return kStatus_Success;
}

/*******************************************************************************
 * Public functions
 ******************************************************************************/

/**
 * brief    Shut off the Flash and execute the _WFI(), then power up the Flash after wake-up event.
 *     		Shut off the Flash is done by hardware, then power up the Flash after wake-up event also.
 * 			Flush flash cache is only relevant when doing flash accesses like write or erase, not for executing from flash.
 * 			It is the responsibility of the user to properly finalize these functions before calling PMC driver lower power
 * API. param    None return    Nothing
 */
void CHIPLOWPOWER_PowerCycleCpuAndFlash(void)
{
    /* artf1040389 BOD workaround */
    /* store PDEN_BOD1/2 from PDRUNCFG register into AOREG1 for non retention modes */
    uint32_t pdruncfg0 = PMC->PDRUNCFG0;
    uint32_t pden_bod1 = (pdruncfg0 & PMC_PDRUNCFG0_PDEN_BOD1_MASK) >> PMC_PDRUNCFG0_PDEN_BOD1_SHIFT;
    uint32_t pden_bod2 = (pdruncfg0 & PMC_PDRUNCFG0_PDEN_BOD2_MASK) >> PMC_PDRUNCFG0_PDEN_BOD2_SHIFT;
    PMC->AOREG1 &= ~(kAOREG1_BOD1_MASK | kAOREG1_BOD2_MASK);
    PMC->AOREG1 |= ((pden_bod1 << kAOREG1_BOD1_SHIFT) | (pden_bod2 << kAOREG1_BOD2_SHIFT));
    /* write values of PDEN_BOD1/2 bits from PDSLEEPCFG register to PDRUNCFG register. */
    uint32_t pdruncfg0_wo = pdruncfg0 & ~(PMC_PDRUNCFG0_PDEN_BOD1_MASK | PMC_PDRUNCFG0_PDEN_BOD2_MASK);
    /* makes use of identical bit positions in RUN and SLEEP register - this will never change */
    pdruncfg0_wo |= (PMC->PDSLEEPCFG0 & (PMC_PDSLEEPCFG0_PDEN_BOD1_MASK | PMC_PDSLEEPCFG0_PDEN_BOD2_MASK));
    PMC->PDRUNCFG0 = pdruncfg0_wo;

    /* Configure the Cortex-M33 in Deep Sleep mode */
    SCB->SCR = SCB->SCR | SCB_SCR_SLEEPDEEP_Msk;

    /* Enter in low power mode */
    __WFI();

    /* Configure the Cortex-M33 in Active mode */
    SCB->SCR = SCB->SCR & (~SCB_SCR_SLEEPDEEP_Msk);

    /* this is retention mode, restore the PDEN_BOD1 and PDEN_BOD2 values of the PMC_PDRUNCFG0 register */
    PMC->PDRUNCFG0 = pdruncfg0;
}

void POWER_Reset(void)
{
    PMC->RESETCTRL |= PMC_RESETCTRL_SWRRESETENABLE_MASK;
    SYSCON->SWR_RESET = 0x5A000001;

    while (1)
    {
        ;
    }
}

void POWER_Init(void)
{
/* Example code to toggle pins and add debug prints from power driver */
#if 0
  PRINTF("Hello, I am the power driver.\n");

  /* Init pin 16*/
  gpio_pin_config_t pin_config = {
  .pinDirection = kGPIO_DigitalOutput,
  .outputLogic = 0U
  };
  GPIO_PinInit(GPIO, 0, 16, &pin_config);

  /* Set pin 16 low */
  GPIO_PortClear(GPIO, 0, 1U << 16);

  /* Set pin 16 high*/
  GPIO_PortSet(GPIO, 0, 1U << 16);
#endif
    /* DISCLAIMER: THIS IS EXPERIMENTAL CODE. REMOVE IF THIS CAUSES PROBLEMS (HCIOT-2181). */
    /* Write a 1b to the PMC_DCDC0_ENABLE_BYPASS bit followed by writing a zero.
       After these two actions, it is guaranteed that the LPBS switch is open. */
    PMC->DCDC0 |= PMC_DCDC0_ENABLE_BYPASS_MASK;
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;

    /* Allow dcdc startup for Vbat < 2v5 e.g. when coming out of deepsleep/powerdown */
    PMC->DCDC0 |= PMC_DCDC0_ROBUST_STARTUP_DISABLE_MASK;

    /* Increase startup time of 32 MHz XTAL from HW default 160us to 288us (9*32us).
    According to datasheet typical value is 209us and max value 270us.   */
    POWER_XTAL32M_SetStartupTime(9);

    /*  There are different techniques to reduce SRAM current in low power modes.
     *  Amongst them are voltage Scaling and source biasing.
     *  But they can not be combined, it is either voltage scaling or source biasing.
     *  Validation must indicate which technique is the most optimal for DEEPSLEEP/POWERDOWN.
     *  if something is planned as part of validation For now voltage scaling is used in all Low Power modes,
     *  just like in Niobe4Mini. So source biasing must be disabled.
     */
    PMC->SRAMCTRL = (PMC->SRAMCTRL & (~PMC_SRAMCTRL_SMB_MASK)) | PMC_SRAMCTRL_SMB(3);

    /*
     * R/W assist is a technique to improve R/W at lower voltage and over lifetime of the SRAM.
     * Default values indicated by memory team must be used and are not supposed to change.
     * In case they do, firmware must write these POR hardware defaults.
     */
    //   SRAMASSISTCTRL0 = 0xCB2CB2;
    //   SRAMASSISTCTRL1 = 0x2A;

    // enable auto clock gating of SRAMS - to be able to switch SRAM power mode - see artf861757 - and all the rest also
    // at the same time
    SYSCON->AUTOCLKGATEOVERRIDE =
        (SYSCON->AUTOCLKGATEOVERRIDE &
         ~(SYSCON_AUTOCLKGATEOVERRIDE_ROM_MASK | SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_MASK | SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_MASK | SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_MASK | SYSCON_AUTOCLKGATEOVERRIDE_FLASH_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_FMC_MASK | SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_MASK | SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_MASK)) |
        (0xC0DE << SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_SHIFT);
    // Note: there is no SYSCON_AUTOCLKGATEOVERRIDE for BLE RAM

    // goto DEEPSLEEP (retention) mode in PMC Low-power modes DSLP and PWDN except when already in SHUTDOWN, then remain
    // in SHUTDOWN
    PMC->SRAMRETCTRL = PMC_SRAMRETCTRL_RETEN_RAMX0_MASK | PMC_SRAMRETCTRL_RETEN_RAMX1_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAMX2_MASK | PMC_SRAMRETCTRL_RETEN_RAMX3_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAM00_MASK | PMC_SRAMRETCTRL_RETEN_RAM10_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAM20_MASK | PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_MASK;

    uint32_t pmc_ldomem = PMC->LDOMEM;
    /* Do not keep 1V from ACTIVE state but change to 0.6x V in low power mode  */
    pmc_ldomem |= PMC_LDOMEM_VADJ_PWD_MASK;
    /* Set 1 V for lowest power consumption */
    pmc_ldomem &= ~PMC_LDOMEM_VADJ_MASK;
    pmc_ldomem |= (kLDO_MEM_1000mv << PMC_LDOMEM_VADJ_SHIFT);
    PMC->LDOMEM = pmc_ldomem;

    uint32_t pmc_ldodig = PMC->LDODIG;
    /* Set 1 V for lowest power consumption */
    pmc_ldodig &= ~PMC_LDODIG_VADJ_MASK;
    pmc_ldodig |= (kLDO_DIG_1000mv << PMC_LDODIG_VADJ_SHIFT);
    PMC->LDODIG = pmc_ldodig;

    /* Enable LSActive for lowest power consumption */
    /* IMPORTANT: This bit must always be set to 1. Flash is characterized with this bit set. */
    FMU0->FCTRL |= FMU_FCTRL_LSACTIVE_MASK;

    /* artf1040389 BOD workaround */
    /* restore PDEN_BOD1/2 from AOREG1 to PDRUNCFG register for non retention modes */
    uint32_t pden_bod1 = (PMC->AOREG1 & kAOREG1_BOD1_MASK) >> kAOREG1_BOD1_SHIFT;
    uint32_t pden_bod2 = (PMC->AOREG1 & kAOREG1_BOD2_MASK) >> kAOREG1_BOD2_SHIFT;
    uint32_t pdruncfg0 = PMC->PDRUNCFG0;
    pdruncfg0 &= ~(PMC_PDRUNCFG0_PDEN_BOD1_MASK | PMC_PDRUNCFG0_PDEN_BOD2_MASK);
    pdruncfg0 |= ((pden_bod1 << PMC_PDRUNCFG0_PDEN_BOD1_SHIFT) | (pden_bod2 << PMC_PDRUNCFG0_PDEN_BOD2_SHIFT));
    PMC->PDRUNCFG0 = pdruncfg0;

    /* restore PMC settings in XR_SM modes */
    uint32_t aoreg1 = PMC->AOREG1;
    /* clear XR_SM mode in AOREG1 to be able to recover next time in case supply is not connected anymore and there is a
     * hang further down */
    /* POWER_DCDC_SetSupplyMode() will set it back. */
    PMC->AOREG1 &= ~(kAOREG1_DCDC_MODE_XR_SM_SS_MASK | kAOREG1_DCDC_MODE_XR_SM_DS_MASK);

    if (aoreg1 & kAOREG1_DCDC_MODE_XR_SM_SS_MASK)
    {
        POWER_DCDC_SetSupplyMode(kDCDC_MODE_XR_SM_SS);
    }
    else if (aoreg1 & kAOREG1_DCDC_MODE_XR_SM_DS_MASK)
    {
        POWER_DCDC_SetSupplyMode(kDCDC_MODE_XR_SM_DS);
    }

    /* Clean-up boot-loader leftovers that consume power */
    /* Disable all unused clocks that are on by default after boot */
    CLOCK_DisableClock(kCLOCK_Rng);

    /*    CLOCK_DisableClock(kCLOCK_Rom);*/ /* required for debugging */
    CLOCK_DisableClock(kCLOCK_Iocon);
    CLOCK_DisableClock(kCLOCK_Gpio0);
    CLOCK_DisableClock(kCLOCK_Sysctl);
    CLOCK_DisableClock(kCLOCK_HashCrypt);
    CLOCK_DisableClock(kCLOCK_Puf);
    CLOCK_DisableClock(kCLOCK_Casper);
    /*    CLOCK_DisableClock(kCLOCK_AnalogCtrl);*/ /* required for debugging */
}

/*!
 * @brief Function to disable the power of an analog peripheral when the device is in active mode.
 * @param power_config_bit    peripheral for which to disable the power
 */
void POWER_PeripheralPowerOff(power_config_bit_t power_config_bit)
{
    PMC->PDRUNCFGSET0 = power_config_bit;
}

/*!
 * @brief Function to set the delay for the XTAL oscillator to start up.
 * @param delay    delay time in ms
 */
void POWER_XTAL32K_SetStartupTime(uint32_t startupTime)
{
    POWER_XTALStartupTime = startupTime;
}

/*!
 * @brief Function to enable the power of an analog peripheral when the device is in active mode.
 * @param power_config_bit    peripheral for which to enable the power
 */
void POWER_PeripheralPowerOn(power_config_bit_t power_config_bit)
{
    if (power_config_bit & kPOWERCFG_XTAL32K)
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_XTAL32K) /* Check 32K XTAL not on yet (1 means off in PDRUNCFG0)*/
        {
            PMC->PDRUNCFGCLR0 = power_config_bit;
            POWER_delay_ms(POWER_XTALStartupTime); /* Delay configurable with API, in case customer uses different XTAL
                                                      configuration. */
        }
    }
    if (power_config_bit & kPOWERCFG_FRO32K)
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_FRO32K) /* Check 32K FRO not on yet (1 means off in PDRUNCFG0)*/
        {
            PMC->PDRUNCFGCLR0 = power_config_bit;
            POWER_delay_ms(DEFAULT_FRO_STARTUP_DELAY); /* Delay NOT configurable with API, we assume FRO startup not to
                                                          vary too much. */
        }
    }
    else if (power_config_bit & kPOWERCFG_BLE) /* Check 32MHz XTAL not on yet (1 means off in PDRUNCFG0)*/
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_BLE)
        {
#define PMC_BLE_STATE                  ((PMC->STATUS & PMC_STATUS_FSMBLESTATE_MASK) >> PMC_STATUS_FSMBLESTATE_SHIFT)
#define PMC_BLE_STATE_RADIO_ACTIVE     (6u)
#define PMC_BLE_STATE_ENABLE_CLOCK_OUT (2u)

            PMC->PDRUNCFGCLR0 = power_config_bit;
            /* Wait until 32 MHz xtal osc is active*/
            while ((PMC_BLE_STATE != PMC_BLE_STATE_ENABLE_CLOCK_OUT) && (PMC_BLE_STATE != PMC_BLE_STATE_RADIO_ACTIVE))
            {
            }
        }
    }
    else
    {
        PMC->PDRUNCFGCLR0 = power_config_bit;
    }
}

#define PMC_SRAMCTRL0_RAMX0_MASK                                                                    \
    (PMC_SRAMCTRL0_RAMX0_LS_MASK | PMC_SRAMCTRL0_RAMX0_DSB_MASK | PMC_SRAMCTRL0_RAMX0_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAMX0_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAMX1_MASK                                                                    \
    (PMC_SRAMCTRL0_RAMX1_LS_MASK | PMC_SRAMCTRL0_RAMX1_DSB_MASK | PMC_SRAMCTRL0_RAMX1_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAMX1_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAMX2_MASK                                                                    \
    (PMC_SRAMCTRL0_RAMX2_LS_MASK | PMC_SRAMCTRL0_RAMX2_DSB_MASK | PMC_SRAMCTRL0_RAMX2_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAMX2_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAMX3_MASK                                                                    \
    (PMC_SRAMCTRL0_RAMX3_LS_MASK | PMC_SRAMCTRL0_RAMX3_DSB_MASK | PMC_SRAMCTRL0_RAMX3_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAMX3_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAM00_MASK                                                                    \
    (PMC_SRAMCTRL0_RAM00_LS_MASK | PMC_SRAMCTRL0_RAM00_DSB_MASK | PMC_SRAMCTRL0_RAM00_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAM00_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAM10_MASK                                                                    \
    (PMC_SRAMCTRL0_RAM10_LS_MASK | PMC_SRAMCTRL0_RAM10_DSB_MASK | PMC_SRAMCTRL0_RAM10_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAM10_LSDEL_MASK)
#define PMC_SRAMCTRL0_RAM20_MASK                                                                    \
    (PMC_SRAMCTRL0_RAM20_LS_MASK | PMC_SRAMCTRL0_RAM20_DSB_MASK | PMC_SRAMCTRL0_RAM20_DSBDEL_MASK | \
     PMC_SRAMCTRL0_RAM20_LSDEL_MASK)

#define PMC_SRAMCTRL1_RAMBLEDATA_MASK                                                                              \
    (PMC_SRAMCTRL1_RAMBLEDATA_LS_MASK | PMC_SRAMCTRL1_RAMBLEDATA_DSB_MASK | PMC_SRAMCTRL1_RAMBLEDATA_DSBDEL_MASK | \
     PMC_SRAMCTRL1_RAMBLEDATA_LSDEL_MASK)
#define PMC_SRAMCTRL1_RAMBLESEQL_MASK                                                                              \
    (PMC_SRAMCTRL1_RAMBLESEQL_LS_MASK | PMC_SRAMCTRL1_RAMBLESEQL_DSB_MASK | PMC_SRAMCTRL1_RAMBLESEQL_DSBDEL_MASK | \
     PMC_SRAMCTRL1_RAMBLESEQL_LSDEL_MASK)

#define PMC_SRAMCTRL0_NORMAL_MODE   (PMC_SRAMCTRL0_RAMX0_DSB_MASK | PMC_SRAMCTRL0_RAMX0_DSBDEL_MASK)
#define PMC_SRAMCTRL0_SHUTDOWN_MODE (PMC_SRAMCTRL0_RAMX0_LS_MASK | PMC_SRAMCTRL0_RAMX0_LSDEL_MASK)

/*!
 * @brief Function to power off certain SRAM segments.
 * @param sram_ctrl    mask of sram_ctrl_bit_t bits to power off.
 */
void POWER_DisableSRAM(uint32_t sram_ctrl)
{
    // SYSCON:AHBCLKCTRL0:SRAM_CTRL1/2 =   //see artf861757  - rely on auto gating for now.
    if (sram_ctrl & kSRAM_CTRL_RAMX0)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX0_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX1)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX1_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX2)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX2_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX3)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX3_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM00)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM00_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM10)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM10_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM20)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM20_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMBLEDATA)
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl1 = PMC->SRAMCTRL1;
            pmc_sram_ctrl1 &= ~PMC_SRAMCTRL1_RAMBLEDATA_MASK;
            pmc_sram_ctrl1 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT);
            PMC->SRAMCTRL1 = pmc_sram_ctrl1;
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMBLESEQL)
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl1 = PMC->SRAMCTRL1;
            pmc_sram_ctrl1 &= ~PMC_SRAMCTRL1_RAMBLESEQL_MASK;
            pmc_sram_ctrl1 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT);
            PMC->SRAMCTRL1 = pmc_sram_ctrl1;
        }
    }
}

/*!
 * @brief Function to power on certain SRAM segments. By default all SRAM segments are on.
 * @param sram_ctrl    mask of sram_ctrl_bit_t bits to power on.
 */
void POWER_EnableSRAM(uint32_t sram_ctrl)
{
    // SYSCON:AHBCLKCTRL0:SRAM_CTRL1/2 =   //see artf861757  - rely on auto gating for now.
    if (sram_ctrl & kSRAM_CTRL_RAMX0) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX0_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(1); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX1) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX1_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(1); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX2) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX2_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(1); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMX3) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAMX3_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(1); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM00) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM00_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(4); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM10) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM10_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(6); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAM20) // ON
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl0 = PMC->SRAMCTRL0;
            pmc_sram_ctrl0 &= ~PMC_SRAMCTRL0_RAM20_MASK;
            pmc_sram_ctrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT);
            PMC->SRAMCTRL0 = pmc_sram_ctrl0;
            POWER_delay_us(12); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMBLEDATA) // ON
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) !=
            (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl1 = PMC->SRAMCTRL1;
            pmc_sram_ctrl1 &= ~PMC_SRAMCTRL1_RAMBLEDATA_MASK;
            pmc_sram_ctrl1 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT);
            PMC->SRAMCTRL1 = pmc_sram_ctrl1;
            POWER_delay_us(4); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }

    if (sram_ctrl & kSRAM_CTRL_RAMBLESEQL) // ON
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) !=
            (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
        {
            uint32_t pmc_sram_ctrl1 = PMC->SRAMCTRL1;
            pmc_sram_ctrl1 &= ~PMC_SRAMCTRL1_RAMBLESEQL_MASK;
            pmc_sram_ctrl1 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT);
            PMC->SRAMCTRL1 = pmc_sram_ctrl1;
            POWER_delay_us(1); // wait till SRAM ready to be used (HCIOT-1947, artf953383)
        }
    }
}

/*!
 * @brief Function to return power status of all SRAM segments.
 * @return sram_ctrl_bit_t bits of enabled SRAM segments.
 */
uint32_t POWER_GetSRAMConfig(void)
{
    uint32_t sram_ctrl = 0;

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMX0;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMX1;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMX2;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMX3;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAM00;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAM10;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAM20;
    }

    if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) ==
        (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMBLEDATA;
    }

    if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) ==
        (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
    {
        sram_ctrl |= kSRAM_CTRL_RAMBLESEQL;
    }
    return sram_ctrl;
}

/**
 * PMC Sleep function call: stop CPU, continues execution after wakeup
 */
void POWER_EnterSleep(void)
{
    uint32_t pmsk;
    pmsk = DisableGlobalIRQ();

    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __WFI();

    EnableGlobalIRQ(pmsk);
}

/**
 * PMC Deep Sleep function call: stop CPU and power down flash, continues execution after wakeup
 */
status_t POWER_EnterDeepSleep(uint32_t exclude_from_pd, uint64_t wakeup_interrupts)
{
    uint32_t cpu0_nmi_enable;
    uint32_t cpu0_int_enable_0;
    uint32_t cpu0_int_enable_1;

    // check validity of inputs ...................................
    // 1. only the following peripherals can be excluded from power down:   kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPSLEEP
    if (exclude_from_pd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPSLEEP)
    {
        return kStatus_InvalidArgument;
    }
    // 2. some analog peripherals need to stay powered.  => assumed all done by hardware.
    // 3. some combinations are not allowed
    // 3.2 kLOWPOWERCFG_BLE_WUP may only be set when either kLOWPOWERCFG_FRO32K or kLOWPOWERCFG_XTAL32K is set.
    // (remember the dirty exception of RTC and OSTIMER)
    if (exclude_from_pd & kLOWPOWERCFG_BLE_WUP)
    {
        if (!(exclude_from_pd & (kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K)))
        {
            return kStatus_InvalidArgument;
        }
    }
    // 3.3 FRO192M may only be set when HFDSM is set
    if (exclude_from_pd & kLOWPOWERCFG_FRO192M)
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_HFDSM))
        {
            return kStatus_InvalidArgument;
        }
    }

    // 4. combinations with other registers:

    // 4.1 BOD resets: when enabled, BOD should stay powered
    uint32_t pmc_reset_ctrl = PMC->RESETCTRL;
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    // artf834542: No CTIMER and UTICK at 1MHz during DEEPSLEEP with LDO_DIG = 0.6x V.
    if (!(exclude_from_pd & kLOWPOWERCFG_HFDSM)) // not 1V mode
    {
        if (exclude_from_pd & kLOWPOWERCFG_FRO1M) // FRO1M enables
        {
            if (SYSCON->AHBCLKCTRL.AHBCLKCTRL1 & SYSCON_AHBCLKCTRL1_UTICK_MASK) // UTICK is always connected to FRO1M
            {
                return kStatus_InvalidArgument;
            }
            // CTIMER can be connected directly to FRO1M, or via main clock
            // direct to FRO1M
            if (((SYSCON->CTIMERCLKSELX[0] & SYSCON_CTIMERCLKSEL0_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[1] & SYSCON_CTIMERCLKSEL1_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[2] & SYSCON_CTIMERCLKSEL2_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[3] & SYSCON_CTIMERCLKSEL3_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[4] & SYSCON_CTIMERCLKSEL4_SEL_MASK) == 4))
            {
                return kStatus_InvalidArgument;
            }
            // via main clock
            // first check if main clock is connected to FRO1M
            if (((SYSCON->MAINCLKSELA & SYSCON_MAINCLKSELA_SEL_MASK) == 2) &&
                ((SYSCON->MAINCLKSELB & SYSCON_MAINCLKSELB_SEL_MASK) == 0))
            {
                // then check CTIMERS
                if (((SYSCON->CTIMERCLKSELX[0] & SYSCON_CTIMERCLKSEL0_SEL_MASK) == 0) |
                    ((SYSCON->CTIMERCLKSELX[1] & SYSCON_CTIMERCLKSEL1_SEL_MASK) == 0) |
                    ((SYSCON->CTIMERCLKSELX[2] & SYSCON_CTIMERCLKSEL2_SEL_MASK) == 0) |
                    ((SYSCON->CTIMERCLKSELX[3] & SYSCON_CTIMERCLKSEL3_SEL_MASK) == 0) |
                    ((SYSCON->CTIMERCLKSELX[4] & SYSCON_CTIMERCLKSEL4_SEL_MASK) == 0))
                {
                    return kStatus_InvalidArgument;
                }
            }
        }
    }

    // end check valid combinations ...................................

    status_t status = POWER_SetPowerConfiguration(kLP_MODE_DEEPSLEEP, &exclude_from_pd);
    if (status != kStatus_Success)
    {
        return status;
    }

    // mask all sleepcfg0 register bits
    uint32_t pmc_sleepcfg0 = ~(exclude_from_pd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_CORE_MASK;                                        // keep core enabled
    pmc_sleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK | PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK); // keep ldo's enabled

    // check High Frequency Deep Sleep Mode - set LDO DIG voltage
    uint32_t pmc_ldodig = PMC->LDODIG;
    pmc_ldodig &= ~PMC_LDODIG_VADJ_PWD_MASK;
    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK; // clear bias bits
    if (exclude_from_pd & kLOWPOWERCFG_HFDSM)
    {
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63; // bias must stay on in 1V mode
        pmc_sleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK);
    }
    else
    {
        pmc_ldodig |= PMC_LDODIG_VADJ_PWD_MASK;
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63; // bias must be set to 0.63 in DeepSleep as much of the digital
                                                         // (CORE power domain) stays on
    }
    PMC->LDODIG = pmc_ldodig;

    // check BLE WakeUP
    if (exclude_from_pd & kLOWPOWERCFG_BLE_WUP)
    {
        // keep all required peripherals on for this mode - assume XO32M always off during deep sleep for now
        pmc_sleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_BLE_MASK);
    }

    /* Lower System Clock to FRO12Mhz if necessary */
    uint32_t restore_clock_settings = 0;
    uint32_t FLASHReadWaitStates;
    uint32_t core_sys_clk_configuration;
    /* See Clock structure diagram in Hardware Architecture Specification */
    if (((SYSCON->MAINCLKSELA == MAINCLKSELA_FRO_12MHz) && (SYSCON->MAINCLKSELB == MAINCLKSELB_MAINCLKAOUT)) ||
        ((SYSCON->MAINCLKSELA == MAINCLKSELA_FRO_1MHz) && (SYSCON->MAINCLKSELB == MAINCLKSELB_MAINCLKAOUT)) ||
        (SYSCON->MAINCLKSELB == MAINCLKSELB_32K_OSC) || (SYSCON->MAINCLKSELB == MAINCLKSELB_32K_OSC_ALTERNATE_VALUE1))
    {
    }
    else
    {
        /* Switch System Clock to FRO12Mhz (the configuration before calling this function will be restored back) */
        FLASHReadWaitStates        = CLOCK_GetFLASHAccessCycles();
        core_sys_clk_configuration = CLOCK_GetCoreSysClkConfiguration();
        CLOCK_SetupFROClocking(kFreq_12MHz); // do we need a check here in case clock is lower than 12MHz?
        CLOCK_SetFLASHAccessCyclesForFreq(
            kFreq_12MHz); // only relevant when running from flash - is it worth the effort to switch this?
        restore_clock_settings = 1;
    }

    // set excluded peripherals
    PMC->PDSLEEPCFG0 = pmc_sleepcfg0;

    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_DEEPSLEEP << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    cpu0_nmi_enable = SYSCON->NMISRC & SYSCON_NMISRC_NMIENCPU0_MASK; /* Save the configuration of the NMI Register */
    SYSCON->NMISRC &= ~SYSCON_NMISRC_NMIENCPU0_MASK;                 /* Disable NMI of CPU0 */

    /*
     * Enable wake up interrupt.
     * Rational : we enable each interrupt (NVIC->ISER) that can wake up the CPU here (before the __disable_irq()
     * below): Hence, if an interrupt was pending and not treated before (for any reason), the CPU will jump to that
     *            interrupt handler before trying to enter the low power mode.
     *            VERY IMPORTANT : Also, any interrupt set in NVIC->ISER, even though __disable_irq(), will make the CPU
     *                             go out of the Deep Sleep mode.
     */

    /* But first save the configuration of the CPU interrupt set enable Registers */
    cpu0_int_enable_0 = NVIC->ISER[0];
    cpu0_int_enable_1 = NVIC->ISER[1];

    NVIC->ISER[0] = (uint32_t)(wakeup_interrupts & 0xFFFFFFFF);
    NVIC->ISER[1] = (uint32_t)((wakeup_interrupts >> 32) & 0xFFFFFFFF);

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = (uint32_t)(wakeup_interrupts & 0xFFFFFFFF);
    SYSCON->STARTER[1] = (uint32_t)((wakeup_interrupts >> 32) & 0xFFFFFFFF);

    uint32_t g_savedPrimask = 0;

    /* Make sure DEEP POWER DOWN reset is disabled else DeepSleep will reset iso. continue */
    PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

    /* Disable all IRQs */
    g_savedPrimask = DisableGlobalIRQ();

    // wait for random number generator to be finished.
    // Would it trigger a false wake-up when still running ?
    // => no it does not
    // => after reading out random generator it takes about 2ms to generate a new value.
    // => this process is paused while sleeping and continues after wakeup - all automatically
    // => so no error bits are set (anymore) when coming out of deep sleep, see comment in line 1822 in fsl_trng.c
    // function TRNG_GetRandomData
    //	While (TRNG->MCTL & TRNG_MCTL_TSTOP_OK_MASK == 0);  => so this is not needed

    /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
    CHIPLOWPOWER_PowerCycleCpuAndFlash();

    if (restore_clock_settings == 1)
    {
        // restore main clock settings
        // restore flash wait cycles
        CLOCK_SetFLASHAccessCycles(
            FLASHReadWaitStates); // do we need a check here in case restored clock is lower than 12MHz?
        // restore System Clock
        CLOCK_SetCoreSysClkConfiguration(core_sys_clk_configuration);
    }

    /* Enable all interrupts */
    EnableGlobalIRQ(g_savedPrimask);

    /* Restore ACTIVE mode to allow using normal WFI again */
    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_ACTIVE << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    /* Reset Sleep Postpone configuration */
    //	SYSCON->HARDWARESLEEP = 0;  todo

    /* Restore the configuration of the NMI Register */
    SYSCON->NMISRC |= cpu0_nmi_enable;

    /* Restore the configuration of the CPU interrupt enable Registers */
    NVIC->ISER[0] = cpu0_int_enable_0;
    NVIC->ISER[1] = cpu0_int_enable_1;

    return kStatus_Success;
}

/**
 * PMC Power Down function call: power down flash and CPU, reset @ wakeup interrupt
 */
status_t POWER_EnterPowerDown(uint32_t exclude_from_pd, uint64_t wakeup_interrupts, uint32_t cpu_retention_ctrl)
{
    uint32_t cpu0_nmi_enable;
    uint32_t cpu0_int_enable_0;
    uint32_t cpu0_int_enable_1;
    uint32_t anactrl_bod_dcdc_int_ctrl;
    //    uint32_t rng_entropy_save[6];
    //    uint32_t analog_ctrl_regs[12]; /* To store Analog Controller Registers */

    // check validity of inputs ...................................
    // 1. only the following peripherals can be excluded from power down:
    if (exclude_from_pd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_POWERDOWN)
    {
        return kStatus_InvalidArgument;
    }
    // 2. some analog peripherals need to stay powered.
    // 3. some combinations are not allowed
    // 3.2 kLOWPOWERCFG_BLE_WUP may only be set when either kLOWPOWERCFG_FRO32K or kLOWPOWERCFG_XTAL32K is set.
    // (remember the dirty exception of RTC and OSTIMER)
    if (exclude_from_pd & kLOWPOWERCFG_BLE_WUP)
    {
        if (!(exclude_from_pd & (kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K)))
        {
            return kStatus_InvalidArgument;
        }
    }

    // 4. combinations with other registers:

    // 4.1 BOD resets: when enabled, BOD should stay powered
    uint32_t pmc_reset_ctrl = PMC->RESETCTRL;
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    // What about wakeup interrupts.  Allowed in PowerDown are: kWAKEUP_GINT0, kWAKEUP_FLEXCOMM0, kWAKEUP_BLE_SLP_TMR,
    // kWAKEUP_RTC, kWAKEUP_OS_EVENT, wakeup pin as gpio
    if (wakeup_interrupts & ~(kWAKEUP_GINT0 | kWAKEUP_FLEXCOMM0 | kWAKEUP_BLE_SLP_TMR | kWAKEUP_RTC |
                              kWAKEUP_OS_EVENT /* | wakeup pin as gpio */))
    {
        return kStatus_InvalidArgument;
    }

    // end check valid combinations ...................................

    status_t status = POWER_SetPowerConfiguration(kLP_MODE_POWERDOWN, &exclude_from_pd);
    if (status != kStatus_Success)
    {
        return status;
    }

    uint32_t pmc_sleepcfg0 = ~(exclude_from_pd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    // bias must be set to 0.66 V in power down, but BOD requires 0.63 V
    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK; // clear bias bits
    if (exclude_from_pd & (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2))
    {
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63;
    }
    else
    {
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_66;
    }

    PMC->LDODIG |= PMC_LDODIG_VADJ_PWD_MASK;

    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK;
    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK;

    // check BLE WakeUP
    if (exclude_from_pd & kLOWPOWERCFG_BLE_WUP)
    {
        // keep all required peripherals on for this mode
        pmc_sleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_BLE_MASK);
    }

    // cpu retention control
    SYSCON->FUNCRETENTIONCTRL &=
        (~(SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK | SYSCON_FUNCRETENTIONCTRL_RET_START_MASK));
    if (cpu_retention_ctrl)
    {
        SYSCON->FUNCRETENTIONCTRL |=
            (SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK |
             (((CPU_RETENTION_RAMX_STORAGE_START_ADDR >> 2) << SYSCON_FUNCRETENTIONCTRL_RET_START_SHIFT) &
              SYSCON_FUNCRETENTIONCTRL_RET_START_MASK));
        POWER_SavePinRegisters();
    }
    /* Switch System Clock to FRO12Mhz (the configuration before calling this function will be restored back) */
    uint32_t FLASHReadWaitStates        = CLOCK_GetFLASHAccessCycles();
    uint32_t core_sys_clk_configuration = CLOCK_GetCoreSysClkConfiguration();

    CLOCK_SetupFROClocking(kFreq_12MHz); // do we need a check here in case clock is lower than 12MHz?
    CLOCK_SetFLASHAccessCyclesForFreq(
        kFreq_12MHz); // only relevant when running from flash - is it worth the effort to switch this?

    // set excluded peripherals
    PMC->PDSLEEPCFG0 = pmc_sleepcfg0;

    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_POWERDOWN << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    cpu0_nmi_enable = SYSCON->NMISRC & SYSCON_NMISRC_NMIENCPU0_MASK; /* Save the configuration of the NMI Register */
    SYSCON->NMISRC &= ~SYSCON_NMISRC_NMIENCPU0_MASK;                 /* Disable NMI of CPU0 */

    /*
     * Enable wake up interrupt.
     * Rational : we enable each interrupt (NVIC->ISER) that can wake up the CPU here (before the __disable_irq()
     * below): Hence, if an interrupt was pending and not treated before (for any reason), the CPU will jump to that
     *            interrupt handler before trying to enter the low power mode.
     *            VERY IMPORTANT : Also, any interrupt set in NVIC->ISER, even though __disable_irq(), will make the CPU
     *                             go out of the Deep Sleep mode.
     */
    uint32_t interrupt_enables0 = (uint32_t)(wakeup_interrupts & 0xFFFFFFFF);
    uint32_t interrupt_enables1 = (uint32_t)((wakeup_interrupts >> 32) & 0xFFFFFFFF);
    uint32_t wakeup_sources0    = interrupt_enables0;
    uint32_t wakeup_sources1    = interrupt_enables1;

    if (cpu_retention_ctrl)
    {
        if (wakeup_interrupts & kWAKEUP_BLE_SLP_TMR)
        {
            // replace sleep timer irq (23) by wakeup state transition irq (31)
            ANACTRL->BLE_CTRL = ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_MASK; // and clear interrupt request flag to prevent
                                                                       // isr execution at wakeup
            interrupt_enables0 &= ~kWAKEUP_BLE_SLP_TMR;                // disable IRQ
            interrupt_enables0 |= kWAKEUP_WAKE_DSLP;                   // replace by state transition irq
        }
        PMC->RESETCAUSE = PMC->RESETCAUSE; // clear reset cause
    }

    /* But first save the configuration of the CPU interrupt set enable Registers */
    cpu0_int_enable_0 = NVIC->ISER[0];
    cpu0_int_enable_1 = NVIC->ISER[1];

    NVIC->ISER[0] = interrupt_enables0;
    NVIC->ISER[1] = interrupt_enables1;

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = wakeup_sources0;
    SYSCON->STARTER[1] = wakeup_sources1;

    uint32_t g_savedPrimask = 0;

    /* Make sure DEEP POWER DOWN reset is disabled else PowerDown with cpu retention will still reset */
    PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

    /* Disable all IRQs */
    g_savedPrimask = DisableGlobalIRQ();

    /*
     * From here :
     *  1 - If an interrupt that is enable occurs,
     *      the _WFI instruction will not be executed and we won't enter in POWER DOWN.
     *  2 - If an interrupt that is not enable occurs, there is no consequence neither
     *      on the execution of the low power mode nor on the behaviour of the CPU.
     */

    /* Enable boot remap feature if there is no retention */
    //	if (((p_lowpower_cfg->CPURETCTRL & LOWPOWER_CPURETCTRL_ENA_MASK) >> LOWPOWER_CPURETCTRL_ENA_INDEX) ==
    //			LOWPOWER_CPURETCTRL_ENA_DISABLE)
    //	{
    //		/* Retention mode is NOT enable : enable memory remap feature */
    //		SYSCON->MEMORYREMAP &= (~SYSCON_MEMORYREMAP_MAP_MASK); /* Vector Table in ROM */
    //	}

    /* Store BOD interrupt enables to be able to restore them later. */
    anactrl_bod_dcdc_int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;

    /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
    CHIPLOWPOWER_PowerCycleCpuAndFlash();

    /* DISCLAIMER: THIS IS EXPERIMENTAL CODE. REMOVE IF THIS CAUSES PROBLEMS (HCIOT-2181). */
    /* Only clearing the bit is required as the PMC must have kept its state. */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;

    /*
     * We can reach this point for 2 reasons:
     * 1 - We are coming out from POWER DOWN mode with CPU state retention. Assumption is that the SRAM
     *     containing the stack used to call this function shall be preserved during low power.
     * 2 - We didn't enter the POWER DOWN mode because a wake up interrupt popped up just
     *     before entering the POWER DOWN mode (as a consequence, the WFI() has been ignored)
     */

    /* Disable boot remap feature.
     * This is required because it could be that the _WFI has not been executed (Power cycle is cancelled),
     */
    //	if (((p_lowpower_cfg->CPURETCTRL & LOWPOWER_CPURETCTRL_ENA_MASK) >> LOWPOWER_CPURETCTRL_ENA_INDEX) ==
    //			LOWPOWER_CPURETCTRL_ENA_DISABLE)
    //	{
    //		/* Vector Table in Flash */
    //		SYSCON->MEMORYREMAP =
    //				(SYSCON->MEMORYREMAP & (~SYSCON_MEMORYREMAP_MAP_MASK)) | SYSCON_MEMORYREMAP_MAP(2);
    //	}

    // restore main clock settings
    // restore flash wait cycles
    CLOCK_SetFLASHAccessCycles(
        FLASHReadWaitStates); // do we need a check here in case restored clock is lower than 12MHz?
    // restore System Clock
    CLOCK_SetCoreSysClkConfiguration(core_sys_clk_configuration);

    if (cpu_retention_ctrl)
    {
        POWER_RestorePinRegisters(); // pin registers are lost after PD with cpu retention
    }

    /* Enable all interrupts */
    EnableGlobalIRQ(g_savedPrimask);

    /* Restore ACTIVE mode to allow using normal WFI again */
    PMC->CTRL = (PMC->CTRL & (~PMC_CTRL_LPMODE_MASK)) | (LOWPOWER_CTRL_LPMODE_ACTIVE << PMC_CTRL_LPMODE_SHIFT);

    /* Reset Sleep Postpone configuration */
    //	SYSCON->HARDWARESLEEP = 0;  todo

    /*** We'll reach this point in case of POWERDOWN with CPU retention or if the POWERDOWN has not been taken (for
      instance because an interrupt is pending). In case of CPU retention, assumption is that the SRAM containing the
      stack used to call this function shall be preserved during low power ***/

    /* Following code is to reset PUF to remove over consumption */
    /* Enable PUF register clock to access register */
    SYSCON->AHBCLKCTRLSET[2] = SYSCON_AHBCLKCTRL2_PUF_MASK;
    /* Release PUF reset */
    SYSCON->PRESETCTRLCLR[2] = SYSCON_PRESETCTRL2_PUF_RST_MASK;
    /* Enable PUF SRAM */
    PUF_SRAM_CTRL->CFG |= PUF_SRAM_CTRL_CFG_ENABLE_MASK | PUF_SRAM_CTRL_CFG_CKGATING_MASK;

    /* Disable PUF register clock. */
    // Delaying the line of code below until the PUF State Machine execution is completed:
    // Shutting down the clock too early will prevent the state machine from reaching the end.
    // => Wait for status bit in PUF Controller Registers before stop PUF clock.
    while (!(PUF_SRAM_CTRL->INT_STATUS & PUF_SRAM_CTRL_INT_STATUS_READY_MASK))
        ;
    SYSCON->AHBCLKCTRLCLR[2] = SYSCON_AHBCLKCTRL2_PUF_MASK;

    /* Restore the configuration of the NMI Register */
    SYSCON->NMISRC |= cpu0_nmi_enable;

    /* Restore the configuration of the CPU interrupt enable Registers (because they have been overwritten inside the
     * low power API */
    NVIC->ISER[0] = cpu0_int_enable_0;
    NVIC->ISER[1] = cpu0_int_enable_1;

    /* Restore BOD interrupt enables. */
    ANACTRL->BOD_DCDC_INT_CTRL = anactrl_bod_dcdc_int_ctrl;

    return kStatus_Success;
}

/**
 * PMC Deep Power Down function call: power down almost whole chip, reset/wakeup by pin, RTC or OS Timer
 */
status_t POWER_EnterDeepPowerDown(uint32_t exclude_from_pd, uint64_t wakeup_interrupts, uint32_t wakeup_io_ctrl)
{
    // check validity of inputs ...................................
    // 1. only the following peripherals can be excluded from deep power down:
    // kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPPOWERDOWN
    if (exclude_from_pd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPPOWERDOWN)
    {
        return kStatus_InvalidArgument;
    }
    // 2. some analog peripherals need to stay powered.  => assumed all done by hardware.
    // 3. some combinations are not allowed

    // 4. combinations with other registers:

    // 4.1 BOD resets: when enabled, BOD should stay powered
    uint32_t pmc_reset_ctrl = PMC->RESETCTRL;
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmc_reset_ctrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(exclude_from_pd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    // What about wakeup interrupts.  Allowed in DeepPowerDown are: kWAKEUP_RTC, kWAKEUP_OS_EVENT, kWAKEUP_WAKE_PAD
    if (wakeup_interrupts & ~(kWAKEUP_RTC | kWAKEUP_OS_EVENT | kWAKEUP_WAKE_PAD))
    {
        return kStatus_InvalidArgument;
    }

    // end check valid combinations ...................................

    status_t status = POWER_SetPowerConfiguration(kLP_MODE_DEEPPOWERDOWN, &exclude_from_pd);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (wakeup_interrupts == kWAKEUP_RTC)
    {
        RTC->CTRL |=
            RTC_CTRL_WAKEDPD_EN_MASK; // only for Deep power-down mode - set this to get RESETCAUSE RTCRESET bit set
    }

    uint32_t pmc_sleepcfg0 = ~(exclude_from_pd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    // bias must be set to 0 V in deep power down, except BOD requires 0.63 V
    pmc_sleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK; // clear bias bits
    if (exclude_from_pd & (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2))
    {
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63;
        PMC->LDODIG |= PMC_LDODIG_VADJ_PWD_MASK;
    }
    else
    {
        pmc_sleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_DISABLED;
    }

    /* Switch System Clock to FRO12Mhz */
    CLOCK_SetupFROClocking(kFreq_12MHz);
    CLOCK_SetFLASHAccessCyclesForFreq(
        kFreq_12MHz); // only relevant when running from flash - is it worth the effort to switch this?

    // set excluded peripherals
    PMC->PDSLEEPCFG0 = pmc_sleepcfg0;

    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_DEEPPOWERDOWN << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    /*
     * Enable wake up interrupt.
     * Rational : we enable each interrupt (NVIC->ISER) that can wake up the CPU here (before the __disable_irq()
     * below): Hence, if an interrupt was pending and not treated before (for any reason), the CPU will jump to that
     *            interrupt handler before trying to enter the low power mode.
     *            VERY IMPORTANT : Also, any interrupt set in NVIC->ISER, even though __disable_irq(), will make the CPU
     *                             go out of the Deep Sleep mode.
     */
    NVIC->ISER[0] = (uint32_t)(wakeup_interrupts & 0xFFFFFFFF);
    NVIC->ISER[1] = (uint32_t)((wakeup_interrupts >> 32) & 0xFFFFFFFF);

    // exception for OSTIMER
    if (wakeup_interrupts & kWAKEUP_OS_EVENT)
    {
        PMC->OSTIMERr |= PMC_OSTIMER_DPDWAKEUPENABLE_MASK;
        wakeup_interrupts &= ~kWAKEUP_OS_EVENT;
    }

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = (uint32_t)(wakeup_interrupts & 0xFFFFFFFF);
    SYSCON->STARTER[1] = (uint32_t)((wakeup_interrupts >> 32) & 0xFFFFFFFF);

    /* Configure wake-up by I/O */

    PMC->WAKEUPIOCTRL =
        wakeup_io_ctrl |
        PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK; // include RSTN to generate WAKEIOCAUSE being set in RESETCAUSE reg

    /* Enable DEEP POWER DOWN reset */
    PMC->RESETCTRL |= PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK;

    CHIPLOWPOWER_PowerCycleCpuAndFlash();

    return kStatus_Success; // never comes here - just to suppress compiler warning
}

/**
 * PMC Power Off function call: power down almost whole chip, reset/wake up by pin only
 */
status_t POWER_EnterPowerOff(uint32_t exclude_from_pd, uint32_t wakeup_io_ctrl)
{
    // check validity of inputs ...................................
    // 1. only the following peripherals can be excluded from power off:
    // kEXCLUDE_FROM_PD_LIMITATION_MASK_POWEROFF
    if (exclude_from_pd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_POWEROFF)
    {
        return kStatus_InvalidArgument;
    }
    // end check valid combinations

    status_t status = POWER_SetPowerConfiguration(kLP_MODE_POWEROFF, &exclude_from_pd);
    if (status != kStatus_Success)
    {
        return status;
    }

    // set excluded peripherals
    uint32_t pmc_sleepcfg0 = ~(exclude_from_pd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    PMC->PDSLEEPCFG0 = pmc_sleepcfg0;

    SYSCON->NMISRC &= ~SYSCON_NMISRC_NMIENCPU0_MASK; /* Disable NMI of CPU0 */

    PMC->CTRL = (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_ON << PMC_CTRL_POFFMODE_SHIFT);

    /* Configure wake-up by I/O */
    PMC->WAKEUPIOCTRL = wakeup_io_ctrl;

    CHIPLOWPOWER_PowerCycleCpuAndFlash();

    return kStatus_Success; // never comes here - just to suppress compiler warning
}

/*!
 * @brief Function that returns the Supply Mode.
 * @return Supply Mode.
 */
dcdc_mode_t POWER_DCDC_GetSupplyMode(void)
{
    dcdc_mode_t mode;
    uint32_t aoreg1 = PMC->AOREG1;

    if (aoreg1 & kAOREG1_DCDC_MODE_XR_SM_SS_MASK)
    {
        mode = kDCDC_MODE_XR_SM_SS;
    }
    else if (aoreg1 & kAOREG1_DCDC_MODE_XR_SM_DS_MASK)
    {
        mode = kDCDC_MODE_XR_SM_DS;
    }
    else
    {
        /* relies on match between dcdc_mode_t and dcdc_hw_mode_t */
        mode = (dcdc_mode_t)((PMC->STATUSPWR & PMC_STATUSPWR_DCDCMODE_MASK) >> PMC_STATUSPWR_DCDCMODE_SHIFT);
    }
    return mode;
}

/*!
 * @brief Function that sets the Supply mode
 * @return status
 */
status_t POWER_DCDC_SetSupplyMode(dcdc_mode_t mode)
{
    status_t status = kStatus_Success;
    dcdc_hw_mode_t hw_dcdc_mode =
        (dcdc_hw_mode_t)((PMC->STATUSPWR & PMC_STATUSPWR_DCDCMODE_MASK) >> PMC_STATUSPWR_DCDCMODE_SHIFT);
    chip_version_t version = SYSTEM_GetChipVersion();

    if (mode == kDCDC_MODE_HV_SM)
    {
        /* Buck (HV), supported on A0, A1, A2, A3 and A4 */
        if (version <= kCHIPVERSION_A4)
        {
            /* Check if reported HW PMC mode matches with inputs*/
            if (mode == kDCDC_MODE_HV_SM)
            {
                if (hw_dcdc_mode != kDCDC_HW_MODE_HV_SM)
                {
                    return kStatus_Power_SupplyModeModeInvalid;
                }
            }
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* Boost (LV), supported on A0, A1, A2 and A5 */
    else if (mode == kDCDC_MODE_LV_SM)
    {
        if (version <= kCHIPVERSION_A2 || version == kCHIPVERSION_A5)
        {
            if (mode == kDCDC_MODE_LV_SM)
            {
                if (hw_dcdc_mode != kDCDC_HW_MODE_LV_SM)
                {
                    return kStatus_Power_SupplyModeModeInvalid;
                }
            }
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* External regulated single supply (XRSM SM), supported on A0, A1, A2, A3 and A4 */
    else if (mode == kDCDC_MODE_XR_SM_SS)
    {
        if (version <= kCHIPVERSION_A4)
        {
            if (version <= kCHIPVERSION_A2)
            {
                /* enable LPBS */
                PMC->DCDC0 |= PMC_DCDC0_ENABLE_BYPASS_MASK;
            }
            /* disable DCDC */
            POWER_DCDC_Disable();
            PMC->AOREG1 |= kAOREG1_DCDC_MODE_XR_SM_SS_MASK; // register reset on POR, BOD, to be set only once
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* External regulated dual supply (XRSM DM), supported on A0, A1, A2, A3 and A4 */
    else if (mode == kDCDC_MODE_XR_SM_DS)
    {
        if (version <= kCHIPVERSION_A4)
        {
            if (version == kCHIPVERSION_A4)
            {
                /* disable DCDC */
                POWER_DCDC_Disable();
            }
            PMC->AOREG1 |= kAOREG1_DCDC_MODE_XR_SM_DS_MASK; // register reset on POR, BOD, to be set only once
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    else
    {
        return kStatus_Power_SupplyModeModeNotSupported;
    }
    return status;
}

/*!
 * @brief Function to disable DC/DC convertor. When the device is using an external supply mode, the DC/DC convertor
 * should be disabled. When supply mode is kDCDC_MODE_LV_SM , the DC/DC can be disabled but the flash subsystem can't be
 * used. All code needs to run from RAM. When supply mode is kDCDC_MODE_HV_SM , the DCDC can't be disabled.
 */
void POWER_DCDC_Disable(void)
{
    POWER_PeripheralPowerOff(kPOWERCFG_DCDC);
}

/*!
 * @brief Function to enable DC/DC convertor.
 */
void POWER_DCDC_Enable(void)
{
    POWER_PeripheralPowerOn(kPOWERCFG_DCDC);
}

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in buck mode.
 * @pre Can only be used supply mode kDCDC_MODE_HV_SM is used.
 * @param output_lvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBuckOutput(dcdc_buck_output_level_t output_lvl)
{
    PMC->DCDC0 = (PMC->DCDC0 & ~PMC_DCDC0_VOLTAGE_MASK) | output_lvl << PMC_DCDC0_VOLTAGE_SHIFT;
}

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in boost mode.
 * @pre Can only be used supply mode kDCDC_MODE_LV_SM is used.
 * @param output_lvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBoostOutput(dcdc_boost_output_level_t output_lvl)
{
    PMC->DCDC0 = (PMC->DCDC0 & ~PMC_DCDC0_VOLTAGE_MASK) | output_lvl << PMC_DCDC0_VOLTAGE_SHIFT;
}

/*!
 * @brief Function to retrieve the time it took for the DC/DC to have stable output level. Note that the measurement
 * circuit saturates at 0xFFFF (65535 us). The times it takes for the DC/DC to stabilize the output can be used to fine
 * tune the BLE wake up timer. The BLE stack needs to enable 'correction' of the BLE wakeup timer based on how long it
 * takes for the DC/DC to stabilize.
 * @return value that indicates how long it took for DC/DC convertor to have a stable output in us.
 */
uint16_t POWER_DCDC_GetStartupDuration(void)
{
    return (uint16_t)((PMC->STATUSPWR & PMC_STATUSPWR_DURATION_MASK) >> PMC_STATUSPWR_DURATION_SHIFT);
}

/* Get power lib version */
/*!
 * brief Power Library API to return the library version.
 *
 * param none
 * return version number of the power library
 */
uint32_t POWER_GetLibVersion(void)
{
    return FSL_MCXW23_POWER_CONTROL_VERSION;
}

/*!
 * @brief Function to configure the detection level of BOD1.
 * @param level      BOD1 detect level
 * @post             BOD1 is configured to kBOD_NO_ACTION
 * @post             this call must be followed by POWER_ConfigureBOD1() if reset or interrupt is required
 */
void POWER_SetBod1Level(bod_level_t level)
{
    POWER_ConfigureBOD1(kBOD_NO_ACTION);
    /* The BOD mode does not work as expected and the accuracy of the threshold is not good enough. [HCIOT-3939]
     * So we always use level detect mode and use the hysteresis to trim the level based on data stored in NMPA. */
    PMC->BOD1 = AdjustedLevelRegisterSetting(
        level, (FLASH_NMPA->BOD & FLASH_NMPA_BOD_BOD1_TRIGLVL_MASK) >> FLASH_NMPA_BOD_BOD1_TRIGLVL_SHIFT);
}

/*!
 * @brief Function to configure the detection level of BOD2.
 * @param level      BOD2 detect level
 * @post             BOD2 is configured to kBOD_NO_ACTION
 * @post             this call must be followed by POWER_ConfigureBOD2() if reset or interrupt is required
 */
void POWER_SetBod2Level(bod_level_t level)
{
    POWER_ConfigureBOD2(kBOD_NO_ACTION);
    /* The BOD mode does not work as expected and the accuracy of the threshold is not good enough. [HCIOT-3939]
     * So we always use level detect mode and use the hysteresis to trim the level based on data stored in NMPA. */
    PMC->BOD2 = AdjustedLevelRegisterSetting(
        level, (FLASH_NMPA->BOD & FLASH_NMPA_BOD_BOD2_TRIGLVL_MASK) >> FLASH_NMPA_BOD_BOD2_TRIGLVL_SHIFT);
}

/*!
 * @brief Function to configure the BOD1 action. Note that BOD is disabled automatically when BOD reset is triggered but
 * the settings remain.
 * @param action     the action to take when a BOD is detected
 */
void POWER_ConfigureBOD1(bod_action_t action)
{
    switch (action)
    {
        case kBOD_INTERRUPT:
            DisableBOD1Resets();
            EnableBOD1Interrupts();
            break;
        case kBOD_RESET:
            DisableBOD1Interrupts();
            EnableBOD1Resets();
            break;
        default: /* This includes kBOD_NO_ACTION */
            DisableBOD1Interrupts();
            DisableBOD1Resets();
            break;
    }
}

/*!
 * @brief Function to configure the BOD2 action. Note that BOD is disabled automatically when BOD reset is triggered but
 * the settings remain.
 * @param action     the action to take when a BOD is detected
 */
void POWER_ConfigureBOD2(bod_action_t action)
{
    switch (action)
    {
        case kBOD_INTERRUPT:
            DisableBOD2Resets();
            EnableBOD2Interrupts();
            break;
        case kBOD_RESET:
            DisableBOD2Interrupts();
            EnableBOD2Resets();
            break;
        default: /* This includes kBOD_NO_ACTION */
            DisableBOD2Interrupts();
            DisableBOD2Resets();
            break;
    }
}

/*!
 * @brief Function to clear the BOD1 interrupt. It does not
 *        clear the interrupt in the NVIC.
 */
void POWER_ClearBOD1Interrupt(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

/*!
 * @brief Function to clear the BOD2 interrupt. It does not
 *        clear the interrupt in the NVIC.
 */
void POWER_ClearBOD2Interrupt(void)
{
    uint32_t int_ctrl = ANACTRL->BOD_DCDC_INT_CTRL;
    int_ctrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = int_ctrl;
}

/*!
 * @brief Function to retrieve the BOD1 status.
 * @return true as long as BOD1 detects a voltage below the threshold
 */
bool POWER_IsBOD1Active(void)
{
    return ((ANACTRL->BOD_DCDC_INT_STATUS & ANACTRL_BOD_DCDC_INT_STATUS_BOD1_VAL_MASK) == 0);
}

/*!
 * @brief Function to retrieve the BOD2 status.
 * @return true as long as BOD2 detects a voltage below the threshold
 */
bool POWER_IsBOD2Active(void)
{
    return ((ANACTRL->BOD_DCDC_INT_STATUS & ANACTRL_BOD_DCDC_INT_STATUS_BOD2_VAL_MASK) == 0);
}

/*!
 * @brief Function to retrieve the reset cause.
 * @pre	   only valid when coming from DEEP POWER DOWN
 * @return reset cause register content when it was saved by bootloader - only significant bits
 */
reset_cause_t POWER_GetResetCause(void)
{
    return (reset_cause_t)((PMC->AOREG1 >> 4) & 0xfff); // match with bootloader implementation
}

/*!
 * @brief Function to configure the caps of the 32KHz xtal
 * @param capIn The capIn setting
 * @param capOut The capOut setting
 */
void POWER_XTAL32K_ConfigureCaps(uint8_t capIn, uint8_t capOut)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_CAP_OSCIN_MASK | PMC_XTAL32K_CAP_OSCOUT_MASK);
    val |= ((uint32_t)capIn << PMC_XTAL32K_CAP_OSCIN_SHIFT) | ((uint32_t)capOut << PMC_XTAL32K_CAP_OSCOUT_SHIFT);
    PMC->XTAL32K = val;
}

void POWER_XTAL32K_ConfigureReferenceOutputCurrent(uint8_t gm)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_GM_MASK);
    val |= ((uint32_t)gm << PMC_XTAL32K_GM_SHIFT);
    PMC->XTAL32K = val;
}

void POWER_XTAL32K_ConfigureOscillatorAmplitude(uint8_t ampl)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_AMPL_MASK);
    val |= ((uint32_t)ampl << PMC_XTAL32K_AMPL_SHIFT);
    PMC->XTAL32K = val;
}

void POWER_XTAL32K_EnableBypass(bool enable)
{
    if (enable)
    {
        POWER_PeripheralPowerOn(kPOWERCFG_XTAL32K);
        PMC->XTAL32K |= 1UL << PMC_XTAL32K_XTM_SHIFT;
        POWER_XTAL32K_ConfigureCaps(0, 0);
    }
    else
    {
        PMC->XTAL32K &= ~(1UL << PMC_XTAL32K_XTM_SHIFT);
    }
}

void POWER_XTAL32M_BLE_GateEnable(bool enable)
{
    if (enable)
    {
        // ungate BLE clock - gate-on the BLE-PHY cko16 to BLE-LL aclk
        PMC->XTALBLE |= PMC_XTALBLE_CKO_UNGATE_OVERRULE_MASK;
    }
    else
    {
        PMC->XTALBLE &= ~PMC_XTALBLE_CKO_UNGATE_OVERRULE_MASK;
    }
}

status_t POWER_XTAL32M_SetStartupTime(uint8_t startupTime)
{
    status_t status = kStatus_InvalidArgument;
    if (startupTime > 0 && startupTime <= 15)
    {
        PMC->TIMEOUT = (PMC->TIMEOUT & ~PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_MASK) |
                       (startupTime << PMC_TIMEOUT_BLE_RESTART_OSCEN_TIME_OUT_SHIFT);
        status = kStatus_Success;
    }
    return status;
}

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
status_t POWER_MeasureVoltageWithBod1(uint32_t *voltage)
{
    return MeasureVoltage(0, voltage);
}

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
status_t POWER_MeasureVoltageWithBod2(uint32_t *voltage)
{
    return MeasureVoltage(1, voltage);
}
