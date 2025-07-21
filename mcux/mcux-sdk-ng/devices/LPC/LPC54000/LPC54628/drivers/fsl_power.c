/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016, 2021, 2024 NXP
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
#define OTP_BASE (0x40015000u)
#define OTP ((OTP_Type *)OTP_BASE)

/* Normal Voltage level selection */
#define POWER_NORMAL_VLEVEL(x) ((x & 0xfU) << 0U)

/* MREG_VDOK */
#define POWER_VD3_OK_LOAD (1U << 5U)
#define POWER_VD5_OK_LOAD (1U << 9U)

/* PDRUNCFG0 */
#define PDRUNCFG_MAINCLK_SHUTOFF (1U << 0U)
#define PDRUNCFG_DEEP_PD (1U << 1U)
#define PDRUNCFG_LP_MODE (1U << 2U)
#define PDRUNCFG_PD_FRO_EN (1U << 4U)
#define PDRUNCFG_PD_FLASH (1U << 5U)
#define PDRUNCFG_PD_TEMPS (1U << 6U)
#define PDRUNCFG_PD_BOD_RESET (1U << 7U)
#define PDRUNCFG_PD_BOD_INTR (1U << 8U)
#define PDRUNCFG_PD_VD2_ANA (1U << 9U)
#define PDRUNCFG_PD_ADC0 (1U << 10U)
#define PDRUNCFG_PD_EEPROM (1U << 11U)
#define PDRUNCFG_PD_VDDCORE_EE (1U << 12U)
#define PDRUNCFG_PD_RAM0 (1U << 13U)
#define PDRUNCFG_PD_RAM1 (1U << 14U)
#define PDRUNCFG_PD_RAM2 (1U << 15U)
#define PDRUNCFG_PD_RAM3 (1U << 16U)
#define PDRUNCFG_PD_ROM (1U << 17U)
#define PDRUNCFG_PD_VDDHV_ENA (1U << 18U)
#define PDRUNCFG_PD_VDDA (1U << 19U)
#define PDRUNCFG_PD_WDT_OSC (1U << 20U)
#define PDRUNCFG_PD_USB0_PHY (1U << 21U)
#define PDRUNCFG_PD_SYS_PLL (1U << 22U)
#define PDRUNCFG_PD_VREFP_SW (1U << 23U)
#define PDRUNCFG_PD_FLASH_BG (1U << 25U)
#define PDRUNCFG_PD_VD3 (1U << 26U)
#define PDRUNCFG_PD_VD4 (1U << 27U)
#define PDRUNCFG_PD_VD5 (1U << 28U)
#define PDRUNCFG_PD_VD6 (1U << 29U)
#define PDRUNCFG_REQ_DELAY (1U << 30U)
#define PDRUNCFG_FORCE_RBB (1U << 31U)

#define PDRUNCFG0_MEMORY_MASK (0x1fU << 13U)

/* PDRUNCFG1 */
#define PDRUNCFG1_PD_USB1_PHY (1UL << (32U - 32U))
#define PDRUNCFG1_PD_USB_PLL (1UL << (33U - 32U))
#define PDRUNCFG1_PD_AUD_PLL (1UL << (34U - 32U))
#define PDRUNCFG1_PD_SYS_OSC (1UL << (35U - 32U))
#define PDRUNCFG1_PD_EEPROM (1UL << (37U - 32U))
#define PDRUNCFG1_PD_RNG (1UL << (39U - 32U))
#define PDRUNCFG1_SEL_VPP_SW (1UL << (40U - 32U))
#define PDRUNCFG1_PD_VPP_SW (1UL << (41U - 32U))
#define PDRUNCFG1_PD_ALT_FLASH_IBG (1UL << (60U - 32U))
#define PDRUNCFG1_SEL_ALT_FLASH_IBG (1UL << (61U - 32U))
#define PDRUNCFG1_IGNORE_VDOK_SWOK (1UL << (62U - 32U))
#define PDRUNCFG1_SWITCH_LPCTRL (1UL << (63U - 32U))

/* pdsleepcfg standard configurations */

/* DeepSleep PDSLEEP0 */
#define PCFG0_DEEP_SLEEP                                                                                          \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_LP_MODE | PDRUNCFG_PD_FRO_EN | PDRUNCFG_PD_FLASH | PDRUNCFG_PD_TEMPS |   \
     PDRUNCFG_PD_BOD_RESET | PDRUNCFG_PD_BOD_INTR | PDRUNCFG_PD_VD2_ANA | PDRUNCFG_PD_ADC0 | PDRUNCFG_PD_EEPROM | \
     PDRUNCFG_PD_VDDCORE_EE | PDRUNCFG_PD_RAM0 | PDRUNCFG_PD_RAM1 | PDRUNCFG_PD_RAM2 | PDRUNCFG_PD_RAM3 |         \
     PDRUNCFG_PD_ROM | PDRUNCFG_PD_VDDHV_ENA | PDRUNCFG_PD_VDDA | PDRUNCFG_PD_WDT_OSC | PDRUNCFG_PD_USB0_PHY |    \
     PDRUNCFG_PD_SYS_PLL | PDRUNCFG_PD_VREFP_SW | PDRUNCFG_PD_FLASH_BG | PDRUNCFG_PD_VD3 | PDRUNCFG_PD_VD5 |      \
     PDRUNCFG_PD_VD6 | PDRUNCFG_REQ_DELAY | PDRUNCFG_FORCE_RBB\
)

/* DeepSleep PDSLEEP1 */
#define PCFG1_DEEP_SLEEP                                                                          \
    (PDRUNCFG1_PD_USB1_PHY | PDRUNCFG1_PD_USB_PLL | PDRUNCFG1_PD_AUD_PLL | PDRUNCFG1_PD_SYS_OSC | \
     PDRUNCFG1_PD_EEPROM | PDRUNCFG1_PD_RNG | PDRUNCFG1_PD_VPP_SW | PDRUNCFG1_PD_ALT_FLASH_IBG |  \
     PDRUNCFG1_SEL_ALT_FLASH_IBG\
)

/* DeepPowerDown PDRUNCFG0*/
#define PCFG0_DEEP_POWERDOWN                                                                                      \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_DEEP_PD | PDRUNCFG_LP_MODE | PDRUNCFG_PD_FRO_EN | PDRUNCFG_PD_FLASH |    \
     PDRUNCFG_PD_TEMPS | PDRUNCFG_PD_BOD_RESET | PDRUNCFG_PD_BOD_INTR | PDRUNCFG_PD_VD2_ANA | PDRUNCFG_PD_ADC0 |  \
     PDRUNCFG_PD_EEPROM | PDRUNCFG_PD_VDDCORE_EE | PDRUNCFG_PD_RAM0 | PDRUNCFG_PD_RAM1 | PDRUNCFG_PD_RAM2 |       \
     PDRUNCFG_PD_RAM3 | PDRUNCFG_PD_ROM | PDRUNCFG_PD_VDDHV_ENA | PDRUNCFG_PD_VDDA | PDRUNCFG_PD_WDT_OSC |        \
     PDRUNCFG_PD_USB0_PHY | PDRUNCFG_PD_SYS_PLL | PDRUNCFG_PD_VREFP_SW | PDRUNCFG_PD_FLASH_BG | PDRUNCFG_PD_VD3 | \
     PDRUNCFG_PD_VD4 | PDRUNCFG_PD_VD5 | PDRUNCFG_PD_VD6 | PDRUNCFG_REQ_DELAY | PDRUNCFG_FORCE_RBB\
)

/* DeepPowerDown PDRUNCFG1*/
#define PCFG1_DEEP_POWERDOWN                                                                      \
    (PDRUNCFG1_PD_USB1_PHY | PDRUNCFG1_PD_USB_PLL | PDRUNCFG1_PD_AUD_PLL | PDRUNCFG1_PD_SYS_OSC | \
     PDRUNCFG1_PD_EEPROM | PDRUNCFG1_PD_RNG | PDRUNCFG1_PD_VPP_SW | PDRUNCFG1_PD_ALT_FLASH_IBG |  \
     PDRUNCFG1_SEL_ALT_FLASH_IBG\
)

#define OTP_BANK_COUNT 4U

typedef struct
{
    __IO uint32_t VDCTRL[6]; /* < (0x00) VD1, vd2, vd3, vd4, vd5, vd6 vddflash domain voltage Control */
    __IO uint32_t RESERVED0[10];
    __IO uint32_t LPCTRL; /* < (0x40) LP VD control */
    __IO uint32_t RESERVED1[2];
    __IO uint32_t PWRSWACK; /* < (0x4C) Power Switch Acknowledge */
    __IO uint32_t RESERVED2[1];
    __IO uint32_t MREG_VDOK; /* < (0x54) */
} POWER_Type;

typedef struct
{
    __IO uint32_t RESERVED0[44];
    __IO uint32_t OTP_Latch_Update; /* 0xB0 - Updates the OTP read latches after programming */
} OTP_Type;

/* Power voltage configuration API parameter */
typedef enum voltage_level
{
    V0650 = 0x0U,
    V0700 = 0x1U,
    V0750 = 0x2U,
    V0800 = 0x3U,
    V0850 = 0x4U,
    V0900 = 0x5U,
    V0950 = 0x6U,
    V1000 = 0x7U,
    V1050 = 0x8U,
    V1100 = 0x9U,
    V1150 = 0xAU,
    V1200 = 0xBU,
    V1250 = 0xCU,
    V1300 = 0xDU,
    V1350 = 0xEU,
    V1400 = 0xFU,
    VLFORCEUNSIGNED = 0x80000000U,
} voltageLevel_t;

/* Power voltage domain selection */
typedef enum domain_name
{
    VD1 = 0x0U,
    VD2 = 0x1U,
    VD3 = 0x2U,
    VD4 = 0x3U,
    VD5 = 0x4U,
    VD6 = 0x5U,
    DLFORCEUNSIGNED = 0x80000000U,
} domain_t;

/*******************************************************************************
 * Private functions
 ******************************************************************************/

/* VDx voltage level selection */
void POWER_setVdLevel(domain_t domain, voltageLevel_t level)
{
    POWER->VDCTRL[domain] = POWER_NORMAL_VLEVEL(level);
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

/* DeepSleep funcion reloc on RAM */
static void DeepSleepReloc(uint64_t peripheral_ctrl)
{
    uint32_t pdruncfg0_val, pdruncfg1_val, pmsk;
    uint32_t ahbclkctrl0_val, ahbclkctrl2_val, autocgor_val;
    volatile uint32_t i, j;
    uint32_t vd1_saved, vd4_saved, mem_banks_to_power;

    pmsk = __get_PRIMASK();
    __disable_irq();

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    pdruncfg0_val = SYSCON->PDRUNCFG[0];
    pdruncfg1_val = SYSCON->PDRUNCFG[1];

    SYSCON->PDSLEEPCFG[0] = (PCFG0_DEEP_SLEEP & ~(uint32_t)(peripheral_ctrl)) | pdruncfg0_val;

    SYSCON->PDSLEEPCFG[1] = (PCFG1_DEEP_SLEEP & ~(uint32_t)(peripheral_ctrl >> 32U)) | pdruncfg1_val;
    /*Set low power voltage for entering deep sleep mode*/
    POWER->LPCTRL = 0x136;

    /* Power off the RAM/ROM banks that need to power down in deep sleep mode */
    SYSCON->PDRUNCFGSET[0] = (~peripheral_ctrl & PDRUNCFG0_MEMORY_MASK);

    /* Fix KPSDK-17803 */
    ahbclkctrl0_val = SYSCON->AHBCLKCTRL[0];
    SYSCON->AHBCLKCTRLSET[0] = SYSCON_AHBCLKCTRL_FLASH_MASK;

    /* Turn off flash when it wakes up */
    SYSCON->PDRUNCFGSET[0] = PDRUNCFG_PD_VDDHV_ENA | PDRUNCFG_PD_FLASH;

    /* Fix KPSDK-17275 */
    SYSCON->PRESETCTRLSET[0] = SYSCON_PRESETCTRL_FLASH_RST_MASK;

    /* Enter low power mode */
    __WFI();

    /* If flash needs to powered back on then power it On and wait */
    if (!(pdruncfg0_val & PDRUNCFG_PD_FLASH))
    {
        SYSCON->PDRUNCFGCLR[0] = PDRUNCFG_PD_FLASH | PDRUNCFG_PD_VDDHV_ENA;
        /* tpa_program isn't required, but tpa_read is still required, typical tpa_read is 10us */
        autocgor_val = SYSCON->AUTOCGOR;
        SYSCON->AUTOCGOR = 0xC0DE001E | (autocgor_val & 0x0000FFFF);
#if defined(__CC_ARM) /*---------------- RealView Compiler -----------------*/
        /* Optimization -O0 */
        /* Wait for 30us @ FRO 12MHz */
        for (i = 0U; i <= 28U; i++)
#elif defined(__ICCARM__) /*------------------ ICC Compiler --------------------*/
        /* Optimization Low */
        /* Wait for 30us @ FRO 12MHz */
        for (i = 0U; i <= 34U; i++)
#elif defined(__GNUC__)   /*------------------ GNU Compiler --------------------*/
        /* Optimization -Os */
        /* Wait for 30us @ FRO 12MHz */
        for (i = 0U; i <= 26U; i++)
#endif
        {
            __NOP();
        }
        SYSCON->AUTOCGOR = 0xC0DE0000 | (autocgor_val & 0x0000FFFF);
    }

    /* Fix KPSDK-17275 */
    SYSCON->PRESETCTRLCLR[0] = SYSCON_PRESETCTRL_FLASH_RST_MASK;

    /* Restore original pdruncfg except the RAM/ROM banks that were powered off */
    SYSCON->PDRUNCFG[0] = pdruncfg0_val | (~peripheral_ctrl & PDRUNCFG0_MEMORY_MASK);
    SYSCON->PDRUNCFG[1] = pdruncfg1_val;

    SYSCON->AHBCLKCTRL[0] = ahbclkctrl0_val;

    /* Calculate the memory banks that need to be powered On*/
    mem_banks_to_power = (~peripheral_ctrl & ~pdruncfg0_val & PDRUNCFG0_MEMORY_MASK);
    /* Check if more than one memory bank RAM/ROM was powered off, if so turn them on one by one at VD1, VD4 at 1.25V */
    /* Basically here we are checking if the bit pattern is not a power of 2 */
    if (mem_banks_to_power & (mem_banks_to_power - 1))
    {
        /* Save current VD1, VD4*/
        vd1_saved = POWER->VDCTRL[VD1];
        vd4_saved = POWER->VDCTRL[VD4];
        /* Set VD1, VD4 to 1.25V*/
        POWER->VDCTRL[VD1] = POWER_NORMAL_VLEVEL(V1250);
        POWER->VDCTRL[VD4] = POWER_NORMAL_VLEVEL(V1250);

        /* Wait for 10us for the VD voltage to stabilize */
        autocgor_val = SYSCON->AUTOCGOR;
        SYSCON->AUTOCGOR = 0xC0DE001E | (autocgor_val & 0x0000FFFF);
#if defined(__CC_ARM) /*---------------- RealView Compiler -----------------*/
        /* Optimization -O0 */
        /* Wait for 20us @ FRO 12MHz */
        for (i = 0U; i < 19U; i++)
#elif defined(__ICCARM__) /*------------------ ICC Compiler --------------------*/
        /* Optimization Low */
        /* Wait for 20us @ FRO 12MHz */
        for (i = 0U; i < 21U; i++)
#elif defined(__GNUC__)   /*------------------ GNU Compiler --------------------*/
        /* Optimization -Os */
        /* Wait for 20us @ FRO 12MHz */
        for (i = 0U; i < 18U; i++)
#endif
        {
            __NOP();
        }
        SYSCON->AUTOCGOR = 0xC0DE0000 | (autocgor_val & 0x0000FFFF);

        /* Enable ROM and USB RAM */
        for (i = 17; i > 15; i--)
        {
            /* Check if memory bank needs to be powered On */
            if (mem_banks_to_power & (1UL << i))
            {
                SYSCON->PDRUNCFGCLR[0] = 1UL << i;
                while (!(POWER->PWRSWACK & (1UL << (i - 10))))
                    ;
            }
        }

        /* Enable SRAMX, SRAM0 and SRAM1/2/3 */
        for (i = 13; i < 16; i++)
        {
            /* Check if memory bank needs to be powered On */
            if (mem_banks_to_power & (1UL << i))
            {
                SYSCON->PDRUNCFGCLR[0] = 1UL << i;
                while (!(POWER->PWRSWACK & (1UL << (i - 10))))
                    ;
            }
        }

        /* Revert the voltage level to previous value */
        POWER->VDCTRL[VD1] = vd1_saved;
        POWER->VDCTRL[VD4] = vd4_saved;
    }
    else
    {
        /* if only one ROM/RAM bank, just enable it*/
        SYSCON->PDRUNCFG[0] = pdruncfg0_val & (~mem_banks_to_power);
    }

    /* Reload OTP latches from the fuses */
    if ((SYSCON->PDSLEEPCFG[0] & PDRUNCFG_PD_VD6) && !(SYSCON->PDRUNCFG[0] & PDRUNCFG_PD_VD6))
    {
        ahbclkctrl2_val = SYSCON->AHBCLKCTRL[2];
        /* Enable OTP clock */
        SYSCON->AHBCLKCTRLSET[2] = 1U << SYSCON_AHBCLKCTRL_OTP_SHIFT;
        autocgor_val = SYSCON->AUTOCGOR;
        SYSCON->AUTOCGOR = 0xC0DE001E | (autocgor_val & 0x0000FFFF);
        OTP->OTP_Latch_Update = 0;
        for (i = 0U; i < OTP_BANK_COUNT; i++)
        {
            OTP->OTP_Latch_Update = 1 << i;
/* Wait for 3us for the OTP latch update to finish */
#if defined(__CC_ARM) /*---------------- RealView Compiler -----------------*/
            /* Optimization -O0 */
            /* Wait for 6us @ FRO 12MHz */
            for (j = 0U; j < 5U; j++)
#elif defined(__ICCARM__) /*------------------ ICC Compiler --------------------*/
            /* Optimization Low */
            /* Wait for 6us @ FRO 12MHz */
            for (j = 0U; j < 6U; j++)
#elif defined(__GNUC__)   /*------------------ GNU Compiler --------------------*/
            /* Optimization -Os */
            /* Wait for 6us @ FRO 12MHz */
            for (j = 0U; j < 5U; j++)
#endif
            {
                __NOP();
            }
        }
        SYSCON->AUTOCGOR = 0xC0DE0000 | (autocgor_val & 0x0000FFFF);
        SYSCON->AHBCLKCTRL[2] = ahbclkctrl2_val;
    }

    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __set_PRIMASK(pmsk);
}

/*******************************************************************************
 * Code
 ******************************************************************************/

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

void POWER_GetDefaultBodConfig(power_bod_config_t *bodConfig)
{
    assert(bodConfig != NULL);

    bodConfig->enableReset     = true;
    bodConfig->resetLevel      = kBod_ResetLevel0;
    bodConfig->enableInterrupt = false;
    bodConfig->interruptLevel  = kBod_InterruptLevel0;
}

/* Enter DeepSleep mode*/
void POWER_EnterDeepSleep(uint64_t exclude_from_pd)
{
    static uint32_t relocMem[512];
    void (*fptr)(uint64_t ex_pd);

    /* For deep sleep relocate power down call to RAM so that Flash can be put to standy mode */
    memcpy(relocMem, (void *)((uint32_t)DeepSleepReloc & ~3U), sizeof(relocMem));
    fptr = (void (*)(uint64_t expd))((uint32_t)relocMem + ((uint32_t)DeepSleepReloc & 3U));
    fptr(exclude_from_pd);
}

/* Enter DeepPower Down mode */
void POWER_EnterDeepPowerDown(uint64_t exclude_from_pd)
{
    uint32_t state;

    state = DisableGlobalIRQ();
    POWER_EnableDeepSleep();

    /* Turn off everything except the excluded blocks */
    SYSCON->PDRUNCFG[1] = PCFG1_DEEP_POWERDOWN & ~(uint32_t)(exclude_from_pd >> 32U);
    SYSCON->PDRUNCFG[0] = PCFG0_DEEP_POWERDOWN & ~(uint32_t)exclude_from_pd;

    /* Enter powerdown mode */
    __WFI();

    /* Note that this code is never reached because we re-boot */
    EnableGlobalIRQ(state);
}

/* Enter Power mode */
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

/* Set VDx voltage for Freq*/
void POWER_SetVoltageForFreq(uint32_t freq)
{
    if (freq <= 100000000U)
    {
        POWER_setVdLevel(VD1, V1200);
        POWER_setVdLevel(VD2, V1250);
        POWER_setVdLevel(VD3, V1200);
        POWER_setVdLevel(VD4, V1200);
        POWER_setVdLevel(VD5, V1200);
        POWER_setVdLevel(VD6, V1200);
    }
    else if (freq <= 180000000)
    {
        POWER_setVdLevel(VD1, V1300);
        POWER_setVdLevel(VD2, V1250);
        POWER_setVdLevel(VD3, V1200);
        POWER_setVdLevel(VD4, V1300);
        POWER_setVdLevel(VD5, V1200);
        POWER_setVdLevel(VD6, V1200);
    }
    else
    {
        POWER_setVdLevel(VD1, V1400);
        POWER_setVdLevel(VD2, V1250);
        POWER_setVdLevel(VD3, V1200);
        POWER_setVdLevel(VD4, V1400);
        POWER_setVdLevel(VD5, V1200);
        POWER_setVdLevel(VD6, V1200);
    }
}

/* Enable power for PLLs */
void POWER_SetPLL(void)
{
    SYSCON->PDRUNCFGCLR[0] = PDRUNCFG_PD_VD3;
    /*wait until VD3 fully power*/
    while ((POWER->MREG_VDOK & POWER_VD3_OK_LOAD) != POWER_VD3_OK_LOAD)
        ;
}

/* Enable source power for USB PHYs */
void POWER_SetUsbPhy(void)
{
    SYSCON->PDRUNCFGCLR[0] = PDRUNCFG_PD_VD5;
    /*wait until VD5 fully power*/
    while ((POWER->MREG_VDOK & POWER_VD5_OK_LOAD) != POWER_VD5_OK_LOAD)
        ;
}

/* Get power lib version */
uint32_t POWER_GetLibVersion(void)
{
    return FSL_POWER_DRIVER_VERSION;
}
