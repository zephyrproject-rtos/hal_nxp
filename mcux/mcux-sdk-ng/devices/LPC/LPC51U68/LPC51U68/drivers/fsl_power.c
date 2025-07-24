/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016, 2021, NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_common.h"
#include "fsl_power.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power"
#endif

#define POWER_BASE (0x40020000u)
#define POWER ((POWER_Type *)POWER_BASE)
#define BODYBIAS_BASE (0x40030000u)
#define BODYBIAS ((BODYBIAS_Type *)BODYBIAS_BASE)

typedef struct
{
    __IO uint32_t VDCTRL[5];    /*!< (0x00) VD1, vd2, vd3, vd8, vddflash domain voltage Control */
    __IO uint32_t RESERVED0[3]; /*!< (0x14) */
    __IO uint32_t VDCLAMP[5];   /*!< (0x20) VD1, vd2, vd3, vd8, vddflash domain voltage reg clamp Control */
    __IO uint32_t RESERVED1[3]; /*!< (0x34) */
    __IO uint32_t LPCTRL;       /*!< (0x40) LP VD control */
    __IO uint32_t BODCTRL;      /*!< (0x44) bod Control */
    __IO uint32_t BODTRIM;      /*!< (0x48) bod Trim */
    __IO uint32_t PWRSWACK;     /*!< (0x4C) Power Switch Acknowledge */
    __IO uint32_t DPDWAKESRC;   /*!< (0x50) Deep power down wakeup source flags */
    __IO uint32_t MREG_VDOK;    /*!< (0x54) */
    __IO uint32_t ALTLPCTRL;    /*!< (0x58) */
} POWER_Type;

/* Normal Voltage level selection */
#define POWER_NORMAL_VLEVEL(X) ((X & 0xfU) << 0U)
#define POWER_NORMAL_FINE_VLEVEL(X) ((X & 0x3U) << 4U)

/* Low Power Mode Voltage level selection */
#define POWER_LP_VD1_LEVEL(x) ((x & 0x1U) << 0U)
#define POWER_LP_VD2_LEVEL(x) ((x & 0x1U) << 2U)
#define POWER_LP_VD3_LEVEL(x) ((x & 0x1U) << 4U)
#define POWER_LP_VD8_LEVEL(x) ((x & 0x1U) << 6U)
#define POWER_LP_VDDFLASH_LEVEL(x) ((x & 0x1U) << 8U)
#define POWER_LP_VD1_FULL_CURRENT(x) ((x & 0x1U) << 1U)
#define POWER_LP_VD2_FULL_CURRENT(x) ((x & 0x1U) << 3U)
#define POWER_LP_VD3_FULL_CURRENT(x) ((x & 0x1U) << 5U)
#define POWER_LP_VD8_FULL_CURRENT(x) ((x & 0x1U) << 7U)
#define POWER_LP_VDDFLASH_FULL_CURRENT(x) ((x & 0x1U) << 9U)
#define POWER_LP_FINE_VLEVEL(x) ((x & 0x3U) << 10U)

/* Clamp selection */
#define POWER_CLAMP_LOW_ENABLE(X) ((X & 0x1U) << 8U)
#define POWER_CLAMP_HIGH_ENABLE(X) ((X & 0x1U) << 11U)

#define POWER_CLAMP_LOW_LEVEL(X) ((X & 0x3U) << 9U)
#define POWER_CLAMP_HIGH_LEVEL(X) ((X & 0x3U) << 12U)

/* PDRUNCFG Bit defines */
#define PDRUNCFG_MAINCLK_SHUTOFF (1U << 0U)
#define PDRUNCFG_DEEP_PD (1U << 1U)
#define PDRUNCFG_LP_VD1 (1U << 2U)
#define PDRUNCFG_PD_VD2_ANA (1U << 9U)
#define PDRUNCFG_PD_FRO_EN (1U << 4U)
#define PDRUNCFG_PD_FLASH (1U << 5U)
#define PDRUNCFG_LP_VDDFLASH (1U << 12U)
#define PDRUNCFG_PD_RAM0 (1U << 13U)
#define PDRUNCFG_PD_RAM1 (1U << 14U)
#define PDRUNCFG_PD_RAM2 (1U << 15U)
#define PDRUNCFG_PD_RAMX (1U << 16U)
#define PDRUNCFG_PD_ROM (1U << 17U)
#define PDRUNCFG_PD_VDDHV_ENA (1U << 18U)
#define PDRUNCFG_PD_WDT_OSC (1U << 20U)
#define PDRUNCFG_PD_FLASH_BG (1U << 25U)
#define PDRUNCFG_PD_VD3 (1U << 26U)
#define PDRUNCFG_LP_VD2 (1U << 27U)
#define PDRUNCFG_LP_VD3 (1U << 28U)
#define PDRUNCFG_LP_VD8 (1U << 29U)
#define PDRUNCFG_REQ_DELAY (1U << 30U)
#define PDRUNCFG_FORCE_RBB (1U << 31U)

#define PDRUNCFG_PD_ALT_FLASH_IBG (1U << 28U)
#define PDRUNCFG_SEL_ALT_FLASH_IBG (1U << 29U)
#define PDRUNCFG_IGNORE_VDOK_SWOK (1U << 30U)
#define PDRUNCFG_SEL_ALTLPCTRL (1U << 31U)

typedef struct
{
    __IO uint32_t BBCTRL;    /* (0x00)  Body Bias Control */
    __IO uint32_t FBBOFFSET; /* (0x04)  FBB offset adjust */
} BODYBIAS_Type;

/* Body Bias bitfields */
#define VBB_MODE(x) ((x & (0x7U)) << 0U)

#define RBB_ENABLE(x) (x << 8U)
#define RBB_BYPASS_LDO(x) (x << 9U)

#define FBB_ENABLE(x) (x << 16U)
#define FBB_ENABLE_HP(x) (x << 17U)
#define FBB_NWS(x) (x << 18U)
#define FBB_PWS(x) (x << 19U)

/* Adjustment for process balancing (offset adjustment reg) */
#define FBB_WCODE(x) ((x & (0x3fU)) << 0U)

/* Deep power down mode wakeup source flags */
#define DPDWAKESRC_EXTRESET (1U << 0U)
#define DPDWAKESRC_RTC (1U << 1U)
#define DPDWAKESRC_BODRESET (1U << 2U)
#define DPDWAKESRC_BODINTR (1U << 3U)

/* pdsleepcfg standard configurations */

/* Light Sleep */
#define PCFG_CLK_OFF_ONLY (SYSCON->PDRUNCFG[0] | PDRUNCFG_MAINCLK_SHUTOFF)

/* Deep Sleep */
#define PCFG_DEEP_SLEEP                                                                                          \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_LP_VD1 | SYSCON_PDRUNCFG_PDEN_FRO_MASK | SYSCON_PDRUNCFG_PDEN_TS_MASK | \
     SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK | SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK | PDRUNCFG_PD_VD2_ANA |              \
     SYSCON_PDRUNCFG_PDEN_ADC0_MASK | SYSCON_PDRUNCFG_PDEN_SRAMX_MASK | SYSCON_PDRUNCFG_PDEN_SRAM0_MASK |        \
     PDRUNCFG_PD_ROM | SYSCON_PDRUNCFG_PDEN_VDDA_MASK | SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK |                      \
     SYSCON_PDRUNCFG_PDEN_USB_PHY_MASK | SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK | SYSCON_PDRUNCFG_PDEN_VREFP_MASK |   \
     PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8 | PDRUNCFG_REQ_DELAY | PDRUNCFG_FORCE_RBB)

/* PowerDown */
#define PCFG_POWERDOWN                                                                                           \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_LP_VD1 | SYSCON_PDRUNCFG_PDEN_FRO_MASK | SYSCON_PDRUNCFG_PDEN_TS_MASK | \
     SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK | SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK | PDRUNCFG_PD_VD2_ANA |              \
     SYSCON_PDRUNCFG_PDEN_ADC0_MASK | SYSCON_PDRUNCFG_PDEN_SRAM0_MASK | PDRUNCFG_PD_ROM |                        \
     SYSCON_PDRUNCFG_PDEN_VDDA_MASK | SYSCON_PDRUNCFG_PDEN_WDT_OSC_MASK | SYSCON_PDRUNCFG_PDEN_USB_PHY_MASK |    \
     SYSCON_PDRUNCFG_PDEN_SYS_PLL_MASK | SYSCON_PDRUNCFG_PDEN_VREFP_MASK | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 |   \
     PDRUNCFG_LP_VD8 | PDRUNCFG_REQ_DELAY | PDRUNCFG_FORCE_RBB)

/* DeepPowerDown */

/* LP bits should stay low on entry into Deep PD mode to avoid changing from full power to low power just prior to
 * latching in the new mode in the power subsys could get a voltage spike.
 */
#define PCFG_DEEP_POWERDOWN 0xFFFFFFFFU & ~(PDRUNCFG_LP_VD1 | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8)

/* PowerDown + RBB */
#define PCFG_RETENTION (0xffffffffU)

#define PD_WAKEUP_DELAY_LOOPS 126U
#define PD_WAKEUP_DELAY_CLKS (PD_WAKEUP_DELAY_LOOPS * 4U)

typedef enum voltage_level
{
    V0650           = 0x0U,
    V0700           = 0x1U,
    V0750           = 0x2U,
    V0800           = 0x3U,
    V0850           = 0x4U,
    V0900           = 0x5U,
    V0950           = 0x6U,
    V1000           = 0x7U,
    V1050           = 0x8U,
    V1100           = 0x9U,
    V1150           = 0xAU,
    V1200           = 0xBU,
    V1250           = 0xCU,
    V1300           = 0xDU,
    V1350           = 0xEU,
    V1400           = 0xFU,
    VLFORCEUNSIGNED = 0x80000000U,
} voltageLevel_t;

typedef enum domain_name
{
    VD1             = 0x0U,
    VD2             = 0x1U,
    VD3             = 0x2U,
    VD8             = 0x3U,
    VD9             = 0x4U,
    DLFORCEUNSIGNED = 0x80000000U,
} domain_t;

typedef enum lp_voltage_level
{
    LP_V0700        = 0x0U,
    LP_V1200        = 0x1U,
    LVFORCEUNSIGNED = 0x80000000U,
} lpVoltageLevel_t;

typedef enum lp_fine_voltage_level
{
    FINE_LP_V_M050   = 0x0U,
    FINE_LP_V_NONE   = 0x1U,
    FINE_LP_V_P050   = 0x2U,
    FINE_LP_V_P100   = 0x3U,
    LFVFORCEUNSIGNED = 0x80000000U,
} lpFineVoltageLevel_t;

typedef enum clamp_level
{
    CLAMP_OFF100    = 0x0U,
    CLAMP_OFF050    = 0x1U,
    CLAMP_OFF075    = 0x2U,
    CLAMP_OFF125    = 0x3U,
    CLFORCEUNSIGNED = 0x80000000U,
} clampLevel_t;

typedef enum vbb_mode
{
    RBB_MODE        = 0x0U,
    FBB2_MODE       = 0x1U,
    FBB3_MODE       = 0x2U,
    NBB_MODE        = 0x3U,
    FBB1_MODE       = 0x4U,
    VBFORCEUNSIGNED = 0x80000000U,
} vbbMode_t;

#define PERIPH_CTRL_MASK_DEEP_SLEEP                                                                          \
    (SYSCON_PDRUNCFG_PDEN_BOD_INTR_MASK | PDRUNCFG_PD_WDT_OSC | SYSCON_PDRUNCFG_PDEN_FRO_MASK |              \
     SYSCON_PDRUNCFG_PDEN_SRAM0_MASK | SYSCON_PDRUNCFG_PDEN_SRAMX_MASK | SYSCON_PDRUNCFG_PDEN_USB_PHY_MASK | \
     SYSCON_PDRUNCFG_PDEN_BOD_RST_MASK)

/*******************************************************************************
 * Private functions
 ******************************************************************************/

static void POWER_setVdLevel(domain_t domain, voltageLevel_t level)
{
    POWER->VDCTRL[domain] = POWER_NORMAL_VLEVEL(level) | POWER_NORMAL_FINE_VLEVEL(0);
}

static void POWER_setLpVdLevel(lpVoltageLevel_t vd1LpLevel,
                               lpVoltageLevel_t vd2LpLevel,
                               lpVoltageLevel_t vd3LpLevel,
                               lpVoltageLevel_t vd8LpLevel,
                               lpVoltageLevel_t vd9LpLevel,
                               lpFineVoltageLevel_t flevel)
{
    POWER->LPCTRL = POWER_LP_VD1_LEVEL(vd1LpLevel) | POWER_LP_VD2_LEVEL(vd2LpLevel) | POWER_LP_VD3_LEVEL(vd3LpLevel) |
                    POWER_LP_VD8_LEVEL(vd8LpLevel) | POWER_LP_VDDFLASH_LEVEL(vd9LpLevel) |
                    POWER_LP_VD1_FULL_CURRENT(0) | POWER_LP_VD2_FULL_CURRENT(0) | POWER_LP_VD3_FULL_CURRENT(0) |
                    POWER_LP_VD8_FULL_CURRENT(0) | POWER_LP_VDDFLASH_FULL_CURRENT(0) | POWER_LP_FINE_VLEVEL(flevel);
}

static void DeepSleepReloc(uint32_t peripheral_ctrl)
{
    uint32_t pdruncfg_val, pmsk;
    volatile uint32_t i;
    volatile uint32_t *pdSet;
    volatile uint32_t *pdClr;

    pmsk = __get_PRIMASK();
    __disable_irq();

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    pdruncfg_val = SYSCON->PDRUNCFG[0];

    SYSCON->PDSLEEPCFG[0] =
        (PCFG_DEEP_SLEEP | pdruncfg_val) & ~(peripheral_ctrl & PERIPH_CTRL_MASK_DEEP_SLEEP) & ~(1U << 3U);

    /* Set PDRUNCFG[1] bits 29, 28 */
    pdSet = &(SYSCON->PDRUNCFGSET[0]);
    *((volatile uint32_t *)pdSet + 1U) = (3U << 28U);

    /* Fix KPSDK-17275 */
    SYSCON->PRESETCTRLSET[0] = SYSCON_PRESETCTRL_FLASH_RST_MASK;

    /* Enter powerdown mode */
    __WFI();

    /* Fix KPSDK-17803 */
    SYSCON->AHBCLKCTRLSET[0] = SYSCON_AHBCLKCTRL_FLASH_MASK;
    __asm("nop");

    /* Fix KPSDK-17275 */
    SYSCON->PRESETCTRLCLR[0] = SYSCON_PRESETCTRL_FLASH_RST_MASK;

    /* When exiting only clear bit 29 of PDRUNCFG[1] */
    pdClr = &(SYSCON->PDRUNCFGCLR[0]);
    *((volatile uint32_t *)pdClr + 1U) = (1U << 29U);

    /* Restore original pdruncfg */
    SYSCON->PDRUNCFG[0] = pdruncfg_val & ~(1U << 3U);

    if (peripheral_ctrl & SYSCON_PDRUNCFG_PDEN_FRO_MASK)
    {
        /* Wait if FRO was requested to be On by user */
        for (i = 0U; i < 36U; i++)
        {
            __NOP();
        }
    }

    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __set_PRIMASK(pmsk);
}

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initialize BOD, including enabling/disabling BOD interrupt, enabling/disabling BOD reset, setting BOD
 * interrupt level, and reset level.
 *
 * param bodConfig Pointer the the structure  power_bod_config_t.
 */
void POWER_InitBod(const power_bod_config_t *bodConfig)
{
    assert(bodConfig != NULL);

    uint32_t tmp32 = 0UL;

    tmp32 = SYSCON->BODCTRL;

    tmp32 &= ~(SYSCON_BODCTRL_BODRSTLEV_MASK | SYSCON_BODCTRL_BODRSTENA_MASK | SYSCON_BODCTRL_BODINTLEV_MASK |
               SYSCON_BODCTRL_BODINTENA_MASK | SYSCON_BODCTRL_BODRSTSTAT_MASK | SYSCON_BODCTRL_BODINTSTAT_MASK);

    tmp32 |= SYSCON_BODCTRL_BODRSTLEV(bodConfig->resetLevel) | SYSCON_BODCTRL_BODRSTENA(bodConfig->enableReset) |
             SYSCON_BODCTRL_BODINTLEV(bodConfig->interruptLevel) | SYSCON_BODCTRL_BODINTENA(bodConfig->enableInterrupt);
    SYSCON->BODCTRL = tmp32;
}

/*!
 * brief Get default BOD configuration, including enabling/disabling BOD interrupt, enabling/disabling BOD reset,
 * setting BOD interrupt level, and reset level.
 *
 * param bodConfig Pointer the the structure power_bod_config_t.
 */
void POWER_GetDefaultBodConfig(power_bod_config_t *bodConfig)
{
    assert(bodConfig != NULL);

    bodConfig->enableReset     = true;
    bodConfig->resetLevel      = kBod_ResetLevel0;
    bodConfig->enableInterrupt = false;
    bodConfig->interruptLevel  = kBod_InterruptLevel0;
}

void POWER_EnterSleep(void)
{
    uint32_t pmsk;
    pmsk = __get_PRIMASK();
    __disable_irq();
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __WFI();
    __set_PRIMASK(pmsk);
}

void POWER_EnterDeepSleep(uint64_t exclude_from_pd)
{
    static uint32_t relocMem[256];
    void (*fptr)(uint32_t ex_pd);

    /* For deep sleep relocate power down call to RAM so that Flash can be put to standy mode */
    memcpy(relocMem, (void *)((uint32_t)DeepSleepReloc & ~3U), sizeof(relocMem));
    fptr = (void (*)(uint32_t expd))((uint32_t)relocMem + (uint32_t)(0x3U & (uint32_t)DeepSleepReloc));

    fptr(exclude_from_pd);
}

void POWER_EnterDeepPowerDown(uint64_t exclude_from_pd)
{
    uint32_t state;

    state = DisableGlobalIRQ();
    POWER_EnableDeepSleep();

    /* Turn off everything except the excluded blocks */
    SYSCON->PDRUNCFG[0] = PCFG_DEEP_POWERDOWN & ~exclude_from_pd;

    /* Note that this code is never reached because we re-boot */
    EnableGlobalIRQ(state);
}

void POWER_EnterPowerMode(power_mode_cfg_t mode, uint64_t exclude_from_pd)
{
    switch (mode)
    {
        case kPmu_Sleep:
            POWER_EnterSleep();
            break;

        case kPmu_Deep_Sleep:
            POWER_EnterDeepSleep(exclude_from_pd);
            break;

        case kPmu_Deep_PowerDown:
            POWER_EnterDeepPowerDown(exclude_from_pd);
            break;
        default:
            break;
    }
}

void POWER_SetVoltageForFreq(uint32_t freq)
{
    /* Set to normal regulation mode */
    SYSCON->PDRUNCFGCLR[0] = PDRUNCFG_LP_VD1 | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8;
    /* Set VD levels based on frequency */
    POWER_setVdLevel(VD2, V1200);
    POWER_setVdLevel(VD3, V1200);
    POWER_setVdLevel(VD9, V1200);
    if (freq <= 12000000U)
    {
        POWER_setVdLevel(VD1, V0950);
        POWER_setVdLevel(VD8, V0950);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x0 << 12);
    }
    else if (freq <= 24000000U)
    {
        POWER_setVdLevel(VD1, V1000);
        POWER_setVdLevel(VD8, V1000);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x1 << 12);
    }
    else if (freq <= 36000000U)
    {
        POWER_setVdLevel(VD1, V1050);
        POWER_setVdLevel(VD8, V1050);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x2 << 12);
    }
    else if (freq <= 48000000U)
    {
        POWER_setVdLevel(VD1, V1100);
        POWER_setVdLevel(VD8, V1100);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x2 << 12);
    }
    else if (freq <= 60000000U)
    {
        POWER_setVdLevel(VD1, V1150);
        POWER_setVdLevel(VD8, V1150);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x3 << 12);
    }
    else if (freq <= 72000000U)
    {
        POWER_setVdLevel(VD1, V1200);
        POWER_setVdLevel(VD8, V1200);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x3 << 12);
    }
    else if (freq <= 84000000U)
    {
        POWER_setVdLevel(VD1, V1200);
        POWER_setVdLevel(VD8, V1200);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x4 << 12);
    }
    else if (freq <= 96000000U)
    {
        POWER_setVdLevel(VD1, V1250);
        POWER_setVdLevel(VD3, V1250);
        POWER_setVdLevel(VD8, V1250);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x5 << 12);
    }
    else if (freq <= 100000000U)
    {
        POWER_setVdLevel(VD1, V1300);
        POWER_setVdLevel(VD3, V1300);
        POWER_setVdLevel(VD8, V1300);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x5 << 12);
    }
    else
    {
        POWER_setVdLevel(VD1, V1350);
        POWER_setVdLevel(VD3, V1350);
        POWER_setVdLevel(VD8, V1350);
        SYSCON->FLASHCFG = (SYSCON->FLASHCFG & ~(0xF << 12)) | (0x6 << 12);
    }
}

/* Set low-power voltage levels for LP mode */
void POWER_SetLowPowerVoltageForFreq(uint32_t freq)
{
    switch (freq)
    {
        case 12000000:
            POWER_setLpVdLevel(LP_V0700, LP_V1200, LP_V1200, LP_V1200, LP_V1200, FINE_LP_V_P050);
            SYSCON->PDRUNCFGSET[0] =
                PDRUNCFG_LP_VD1 | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8 | PDRUNCFG_LP_VDDFLASH;
            break;
        case 48000000:
            POWER_setLpVdLevel(LP_V0700, LP_V1200, LP_V1200, LP_V1200, LP_V1200, FINE_LP_V_P100);
            SYSCON->PDRUNCFGSET[0] =
                PDRUNCFG_LP_VD1 | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8 | PDRUNCFG_LP_VDDFLASH;
            break;
        default:
            /* LP mode is not supported for other frequencies*/
            SYSCON->PDRUNCFGCLR[0] =
                PDRUNCFG_LP_VD1 | PDRUNCFG_LP_VD2 | PDRUNCFG_LP_VD3 | PDRUNCFG_LP_VD8 | PDRUNCFG_LP_VDDFLASH;
            break;
    }
}

uint32_t POWER_GetLibVersion(void)
{
    return FSL_POWER_DRIVER_VERSION;
}
