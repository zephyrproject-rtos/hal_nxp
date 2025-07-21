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
#define BODYBIAS_BASE (0x40030000u)
#define BODYBIAS ((BODYBIAS_Type *)BODYBIAS_BASE)

/* Normal Voltage level selection */
#define POWER_NORMAL_VLEVEL(x) ((x & 0xfU) << 0U)
#define POWER_NORMAL_FINE_VLEVEL(x) ((x & 0x3U) << 4U)

/* Low Power Mode Voltage level selection */
/* Normal Voltage level selection */
#define POWER_NORMAL_VLEVEL(x) ((x & 0xfU) << 0U)
#define POWER_NORMAL_FINE_VLEVEL(x) ((x & 0x3U) << 4U)

/* Low Power Mode Voltage level selection */
#define POWER_LP_VD1_LEVEL(x) ((x & 0x1U) << 0U)
#define POWER_LP_VD2_LEVEL(x) ((x & 0x1U) << 1U)
#define POWER_LP_VD3_LEVEL(x) ((x & 0x1U) << 2U)
#define POWER_LP_VD4_LEVEL(x) ((x & 0x1U) << 3U)
#define POWER_LP_VD5_LEVEL(x) ((x & 0x1U) << 4U)
#define POWER_LP_VD6_LEVEL(x) ((x & 0x1U) << 5U)
#define POWER_LP_FINE_VLEVEL(x) ((x & 0x3U) << 8U)

/* Clamp selection */
#define POWER_CLAMP_LOW_ENABLE(x) ((x & 0x1U) << 0U)
#define POWER_CLAMP_HIGH_ENABLE(x) ((x & 0x1U) << 3U)
#define POWER_CLAMP_LOW_LEVEL(x) ((x & 0x3U) << 1U)
#define POWER_CLAMP_HIGH_LEVEL(x) ((x & 0x3U) << 4U)

/* Power Switch Acknowledge */
#define PWRSWACK_VD2_ANA (1U << 0U)
#define PWRSWACK_VDDA_EE (1U << 1U)
#define PWRSWACK_VDDCORE_EE (1U << 2U)
#define PWRSWACK_VD4_RAM0 (1U << 3U)
#define PWRSWACK_VD4_RAM1 (1U << 4U)
#define PWRSWACK_VD4_RAM2 (1U << 5U)
#define PWRSWACK_VD4_RAM3 (1U << 6U)
#define PWRSWACK_VD4_ROM (1U << 7U)
#define PWRSWACK_VDDHV (1U << 8U)
#define PWRSWACK_VDDA_ADC (1U << 9U)
#define PWRSWACK_VREFP_SW (1U << 10U)
#define PWRSWACK_VAPP_SW_FROM_VD6 (1U << 11U)
#define PWRSWACK_VAPP_SW_FROM_VPP (1U << 12U)

/* MREG_VDOK */
#define POWER_VD1_OK_INIT (1U << 0U)
#define POWER_VD1_OK_LOAD (1U << 1U)
#define POWER_VD2_OK_INIT (1U << 2U)
#define POWER_VD2_OK_LOAD (1U << 3U)
#define POWER_VD3_OK_INIT (1U << 4U)
#define POWER_VD3_OK_LOAD (1U << 5U)
#define POWER_VD4_OK_INIT (1U << 6U)
#define POWER_VD4_OK_LOAD (1U << 7U)
#define POWER_VD5_OK_INIT (1U << 8U)
#define POWER_VD5_OK_LOAD (1U << 9U)
#define POWER_VD6_OK_INIT (1U << 10U)
#define POWER_VD6_OK_LOAD (1U << 11U)

/* Power Switch Acknowledge */
#define PWRSWACK_VD2_ANA (1U << 0U)
#define PWRSWACK_VD3_RAM0 (1U << 3U)
#define PWRSWACK_VD3_RAM1 (1U << 4U)
#define PWRSWACK_VD3_RAM2 (1U << 5U)
#define PWRSWACK_VD3_RAM3 (1U << 6U)
#define PWRSWACK_VD3_ROM (1U << 7U)
#define PWRSWACK_VDDHV (1U << 8U)
#define PWRSWACK_VD7_ENA (1U << 9U)
#define PWRSWACK_VREFP_SW (1U << 10U)

/* BOD CTRL */
#define BOD_RESET_LEVEL(x) ((x & 0x3U) << 0U)
#define BOD_RESET_ENABLE(x) ((x & 0x1U) << 2U)
#define BOD_INTR_LEVEL(x) ((x & 0x3U) << 3U)
#define BOD_INTR_ENABLE(x) ((x & 0x1U) << 5U)
#define BOD_RESET_STAT(x) ((x & 0x1U) << 6U)
#define BOD_INT_STAT(x) ((x & 0x1U) << 7U)

/* PDRUNCFG0 */
#define PDRUNCFG_MAINCLK_SHUTOFF (1U << 0U)
#define PDRUNCFG_DEEP_PD (1U << 1U)
#define PDRUNCFG_LP_MODE (1U << 2U)
#define PDRUNCFG_PD_FRO_EN (1U << 4U)
#define PDRUNCFG_PD_TEMPS (1U << 6U)
#define PDRUNCFG_PD_BOD_RESET (1U << 7U)
#define PDRUNCFG_PD_BOD_INTR (1U << 8U)
#define PDRUNCFG_PD_VD2_ANA (1U << 9U)
#define PDRUNCFG_PD_ADC0 (1U << 10U)
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
#define PDRUNCFG1_PD_RNG (1UL << (39U - 32U))
#define PDRUNCFG1_SEL_VPP_SW (1UL << (40U - 32U))
#define PDRUNCFG1_PD_VPP_SW (1UL << (41U - 32U))
#define PDRUNCFG1_IGNORE_VDOK_SWOK (1UL << (62U - 32U))
#define PDRUNCFG1_SWITCH_LPCTRL (1UL << (63U - 32U))

/* Body Bias bitfields */
#define VBB_MODE(x) ((x & (0x7U)) << 0U)

#define RBB_ENABLE(x) (x << 8U)
#define RBB_BYPASS_LDO(x) (x << 9U)

/* Deep power down mode wakeup source flags */
#define DPDWAKEUP_EXTRESET (1U << 0U)
#define DPDWAKEUP_RTC (1U << 1U)
/*Power VD3 VD5 retention in low power mode*/
#define VD3_VD5_RETENTION (PDRUNCFG_PD_VD3 | PDRUNCFG_PD_VD5)

/* LP bits should stay low on entry into Deep PD mode to avoid changing from full power to low power just prior to
 * latching in the new mode in the power subsys could get a voltage spike.
 */

/* PowerDown + RBB */
#define PCFG_RETENTION (0xffffffffU)

#define PD_WAKEUP_DELAY_LOOPS 126U
#define PD_WAKEUP_DELAY_CLKS (PD_WAKEUP_DELAY_LOOPS * 4U)

/* pdsleepcfg standard configurations */

/* Light Sleep */
#define PCFG_CLK_OFF_ONLY (SYSCON->PDRUNCFG[0] | PDRUNCFG_MAINCLK_SHUTOFF)

/* DeepSleep PDSLEEP0 */
#define PCFG0_DEEP_SLEEP                                                                                            \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_LP_MODE | PDRUNCFG_PD_FRO_EN | PDRUNCFG_PD_TEMPS | PDRUNCFG_PD_BOD_RESET | \
     PDRUNCFG_PD_BOD_INTR | PDRUNCFG_PD_ADC0 | PDRUNCFG_PD_VD2_ANA | PDRUNCFG_PD_VDDCORE_EE | PDRUNCFG_PD_RAM0 |    \
     PDRUNCFG_PD_RAM1 | PDRUNCFG_PD_RAM2 | PDRUNCFG_PD_RAM3 | PDRUNCFG_PD_ROM | PDRUNCFG_PD_VDDHV_ENA |             \
     PDRUNCFG_PD_VDDA | PDRUNCFG_PD_WDT_OSC | PDRUNCFG_PD_USB0_PHY | PDRUNCFG_PD_SYS_PLL | PDRUNCFG_PD_VREFP_SW |   \
     PDRUNCFG_PD_VD3 | PDRUNCFG_PD_VD5 | PDRUNCFG_PD_VD6 | PDRUNCFG_REQ_DELAY | PDRUNCFG_FORCE_RBB\
)

/* DeepSleep PDSLEEP1 */
#define PCFG1_DEEP_SLEEP \
    (PDRUNCFG1_PD_USB1_PHY | PDRUNCFG1_PD_USB_PLL | PDRUNCFG1_PD_AUD_PLL | PDRUNCFG1_PD_SYS_OSC | PDRUNCFG1_PD_RNG\
)

/* DeepPowerDown PDRUNCFG0*/
#define PCFG0_DEEP_POWERDOWN                                                                                        \
    (PDRUNCFG_MAINCLK_SHUTOFF | PDRUNCFG_DEEP_PD | PDRUNCFG_PD_FRO_EN | PDRUNCFG_PD_TEMPS | PDRUNCFG_PD_BOD_RESET | \
     PDRUNCFG_PD_BOD_INTR | PDRUNCFG_PD_VD2_ANA | PDRUNCFG_PD_ADC0 | PDRUNCFG_PD_RAM0 | PDRUNCFG_PD_RAM1 |          \
     PDRUNCFG_PD_RAM2 | PDRUNCFG_PD_RAM3 | PDRUNCFG_PD_ADC0 | PDRUNCFG_PD_ROM | PDRUNCFG_PD_VDDHV_ENA |             \
     PDRUNCFG_PD_VDDA | PDRUNCFG_PD_WDT_OSC | PDRUNCFG_PD_USB0_PHY | PDRUNCFG_PD_SYS_PLL | PDRUNCFG_PD_VREFP_SW |   \
     PDRUNCFG_PD_VD3 | PDRUNCFG_PD_VD4 | PDRUNCFG_PD_VD5 | PDRUNCFG_PD_VD6\
)

/* DeepPowerDown PDRUNCFG1*/
#define PCFG1_DEEP_POWERDOWN \
    (PDRUNCFG1_PD_USB1_PHY | PDRUNCFG1_PD_USB_PLL | PDRUNCFG1_PD_AUD_PLL | PDRUNCFG1_PD_SYS_OSC | PDRUNCFG1_PD_RNG\
)

#define PERIPH_CTRL_MASK_DEEP_SLEEP                                                                          \
    (PDRUNCFG_PD_BOD_INTR | PDRUNCFG_PD_WDT_OSC | PDRUNCFG_PD_FRO_EN | PDRUNCFG_PD_RAM0 | PDRUNCFG_PD_RAM1 | \
     PDRUNCFG_PD_RAM2 | PDRUNCFG_PD_RAM3\
)

/* KPSDK-17866 */
#define OTP_BANK_COUNT 4U
#define LPC_OTP_BASE 0x40015000
#define OTP_STATUS_COMPLETE 0x02U
#define OTP_CONFIG_BANK 0U
#define OTP_AES1_BANK 1U
#define OTP_AES2_BANK 2U
#define OTP_ROM_BANK 3U
typedef struct
{
    __IO uint32_t WR_Lock; /* Locks write access to itself and OTP write access */
    __IO uint32_t RD_Lock; /* Lock write access to itself and OTP read access */
} OTP_LOCK_T;

typedef struct
{
    __IO uint32_t OTP[OTP_BANK_COUNT][4]; /* 0x0 - OTP[0][0] .. OTP[3][3] */
    __IO uint32_t reserved0[8];           /* 0x40 */
    __O uint32_t Unique_Key[3];           /* 0x60 - Unique Key bit 95..0. This register is R+W locked at default. */
    __IO uint32_t reserved1[1];           /* 0x6C */
    __IO uint32_t OTP_WRMASK; /* 0x70 - Masks APB write to Fuses protecting unintentional fuse programming by customer.
                                 This register is not lockable. This
                                        register doesn't restrict JTAG write. */
    __I uint32_t OTP_Status;  /* 0x74 - Indicates write status of Fuses */
    __IO uint32_t Program_UserKey;    /* 0x78 - Enables write of Shuffled UserKey value to OTP[1] and OTP[2] */
    __IO uint32_t Shuffle_Control;    /* 0x7C - Shuffle block control */
    OTP_LOCK_T LOCKS[OTP_BANK_COUNT]; /* 0x80 - Write/Read locks for OTP[0] .. OTP[3] */
    __IO uint32_t UniqKey_W_Lock;     /* 0xA0 - Locks write access to itself and Unique Key write access */
    __IO uint32_t reserved2[3];       /* 0xA4 */
    __IO uint32_t OTP_Latch_Update;   /* 0xB0 - Updates the OTP read latches after programming */
    __IO uint32_t OTP_Write_Wait;     /* 0xB4 - write cycles based on 12MHz - n-1 register default = 150 */
} LPC_OTP_T;

#define LPC_OTP ((LPC_OTP_T *)LPC_OTP_BASE)

typedef struct
{
    __IO uint32_t VDCTRL[6];    /* < (0x00) VD1, vd2, vd3, vd4, vd5, vd6  domain voltage Control */
    __IO uint32_t RESERVED0[2]; /* < (0x18) */
    __IO uint32_t VDCLAMP[6];   /* < (0x20) VD1, vd2, vd3, vd4, vd5, vd6, domain voltage reg clamp Control */
    __IO uint32_t RESERVED1[2]; /* < (0x38) */
    __IO uint32_t LPCTRL;       /* < (0x40) LP VD control */
    __IO uint32_t BODCTRL;      /* < (0x44) bod Control */
    __IO uint32_t BODTRIM;      /* < (0x48) bod Trim */
    __IO uint32_t PWRSWACK;     /* < (0x4C) Power Switch Acknowledge */
    __IO uint32_t DPDWAKESRC;   /* < (0x50) Deep power down wakeup source flags */
    __IO uint32_t MREG_VDOK;    /* < (0x54) */
    __IO uint32_t ALTLPCTRL;    /* < (0x58) */
} POWER_Type;

typedef struct
{
    __IO uint32_t BBCTRL;    /* (0x00)  Body Bias Control */
    __IO uint32_t FBBOFFSET; /* (0x04)  FBB offset adjust */
} BODYBIAS_Type;

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

/* Low Power mode voltage selection */
typedef enum lp_voltage_level
{
    LP_V_SET_BY_LPCTRL = 0x0U,
    LP_V1200 = 0x1U,
    LVFORCEUNSIGNED = 0x80000000U,
} lpVoltageLevel_t;

/* Low Power mode trim voltage selection */
typedef enum lp_fine_voltage_level
{
    FINE_LP_V_P0750 = 0x0U,
    FINE_LP_V_P0800 = 0x1U,
    FINE_LP_V_P0900 = 0x2U,
    FINE_LP_V_P1000 = 0x3U,
    LFVFORCEUNSIGNED = 0x80000000U,
} lpFineVoltageLevel_t;

/* clamp selection */
typedef enum clamp_level
{
    CLAMP_OFF100 = 0x0U,
    CLAMP_OFF050 = 0x1U,
    CLAMP_OFF075 = 0x2U,
    CLAMP_OFF125 = 0x3U,
    CLFORCEUNSIGNED = 0x80000000U,
} clampLevel_t;

/* Body Bias selection */
typedef enum vbb_mode
{
    RBB_MODE = 0x0U,
    FBB2_MODE = 0x1U,
    FBB3_MODE = 0x2U,
    NBB_MODE = 0x3U,
    FBB1_MODE = 0x4U,
    VBFORCEUNSIGNED = 0x80000000U,
} vbbMode_t;

/*******************************************************************************
 * Private functions
 ******************************************************************************/

/* VDx voltage level selection */
void POWER_setVdLevel(domain_t domain, voltageLevel_t level)
{
    POWER->VDCTRL[domain] = POWER_NORMAL_VLEVEL(level) | POWER_NORMAL_FINE_VLEVEL(0);
}

/* Low power mode VDx voltage level selection */
void POWER_setLpVdLevel(lpVoltageLevel_t vd1LpLevel,
                        lpVoltageLevel_t vd2LpLevel,
                        lpVoltageLevel_t vd3LpLevel,
                        lpVoltageLevel_t vd4LpLevel,
                        lpVoltageLevel_t vd5LpLevel,
                        lpVoltageLevel_t vd6LpLevel,
                        lpFineVoltageLevel_t flevel)
{
    POWER->LPCTRL = POWER_LP_VD1_LEVEL(vd1LpLevel) | POWER_LP_VD2_LEVEL(vd2LpLevel) | POWER_LP_VD3_LEVEL(vd3LpLevel) |
                    POWER_LP_VD4_LEVEL(vd4LpLevel) | POWER_LP_VD5_LEVEL(vd5LpLevel) | POWER_LP_VD5_LEVEL(vd6LpLevel) |
                    POWER_LP_FINE_VLEVEL(flevel);
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

/* OTP must be reload if OTP(VD6) power off and power back again*/
void POWER_OtpReload(void)
{
    uint32_t i;
    /* Enable OTP power */
    SYSCON->PDRUNCFGCLR[0] = (1U << SYSCON_PDRUNCFGCLR_PDEN_VD6_SHIFT);
    /* Enable OTP clock */
    SYSCON->AHBCLKCTRLSET[2] = 1U << SYSCON_AHBCLKCTRL_OTP_SHIFT;
    /*FIXME - make sure status bits clear with LATCH bit write */
    LPC_OTP->OTP_Latch_Update = 0;
    for (i = 0; i < OTP_BANK_COUNT; i++)
    {
        LPC_OTP->LOCKS[i].RD_Lock |= 0x80;
        LPC_OTP->LOCKS[i].RD_Lock |= 0x0F;
        LPC_OTP->OTP_Latch_Update = 1 << i;
        /* wait for completion */
        while (!(LPC_OTP->OTP_Status & OTP_STATUS_COMPLETE))
        {
        }
    }
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
    volatile uint32_t i;
    uint32_t total_delay = 36U;
    uint32_t vd1_saved, vd4_saved, mem_banks_to_power;

    pmsk = __get_PRIMASK();
    __disable_irq();

    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    pdruncfg0_val = SYSCON->PDRUNCFG[0];
    pdruncfg1_val = SYSCON->PDRUNCFG[1];

    /*Check whether VD5 is uesd by USB PHY*/
    if (!(pdruncfg0_val & PDRUNCFG_PD_VD5))
    {
        peripheral_ctrl = (uint64_t)(peripheral_ctrl | PDRUNCFG_PD_VD5);
    }

    SYSCON->PDSLEEPCFG[0] = (PCFG0_DEEP_SLEEP & ~(uint32_t)(peripheral_ctrl)) | pdruncfg0_val;

    SYSCON->PDSLEEPCFG[1] = (PCFG1_DEEP_SLEEP & ~(uint32_t)(peripheral_ctrl >> 32U)) | pdruncfg1_val;
    /*Set low power voltage for entering deep sleep mode*/
    POWER->LPCTRL = 0x136;

    /* Enter low power mode */
    __WFI();

    /* Restore original pdruncfg except the RAM/ROM banks that were powered off */
    SYSCON->PDRUNCFG[0] = pdruncfg0_val | (~peripheral_ctrl & PDRUNCFG0_MEMORY_MASK);
    SYSCON->PDRUNCFG[1] = pdruncfg1_val;

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
        POWER->VDCTRL[VD1] = POWER_NORMAL_VLEVEL(V1250) | POWER_NORMAL_FINE_VLEVEL(0);
        POWER->VDCTRL[VD4] = POWER_NORMAL_VLEVEL(V1250) | POWER_NORMAL_FINE_VLEVEL(0);

        /* Wait for 10us for the VD voltage to stabilize */
        for (i = 0U; i < 24U; i++)
        {
            __NOP();
        }
        /* Reduce the total wait time if FRO was left enabled */
        total_delay -= i;

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

    if (peripheral_ctrl & PDRUNCFG_PD_FRO_EN)
    {
        /* Wait if FRO was requested to be On by user */
        for (i = 0U; i < total_delay; i++)
        {
            __NOP();
        }
    }

    /* Reload OTP latches from the fuses */
    if (SYSCON->PDSLEEPCFG[0] & PDRUNCFG_PD_VD6)
    {
        /* Enable OTP power */
        SYSCON->PDRUNCFGCLR[0] = (1U << SYSCON_PDRUNCFGCLR_PDEN_VD6_SHIFT);
        /* Enable OTP clock */
        SYSCON->AHBCLKCTRLSET[2] = 1U << SYSCON_AHBCLKCTRL_OTP_SHIFT;
        /*FIXME - make sure status bits clear with LATCH bit write */
        LPC_OTP->OTP_Latch_Update = 0;
        for (i = 0; i < OTP_BANK_COUNT; i++)
        {
            LPC_OTP->LOCKS[i].RD_Lock |= 0x80;
            LPC_OTP->LOCKS[i].RD_Lock |= 0x0F;
            LPC_OTP->OTP_Latch_Update = 1 << i;
            /* wait for completion */
            while (!(LPC_OTP->OTP_Status & OTP_STATUS_COMPLETE))
            {
            }
        }
    }
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    __set_PRIMASK(pmsk);
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
        POWER_setVdLevel(VD6, V1300);
    }
    else
    {
        POWER_setVdLevel(VD1, V1400);
        POWER_setVdLevel(VD2, V1250);
        POWER_setVdLevel(VD3, V1200);
        POWER_setVdLevel(VD4, V1400);
        POWER_setVdLevel(VD5, V1200);
        POWER_setVdLevel(VD6, V1300);
    }
}

/* Set low-power voltage levels for LP mode */
void POWER_SetLowPowerVoltageForFreq(uint32_t freq)
{
    switch (freq)
    {
        case 12000000:
            POWER_setLpVdLevel(LP_V_SET_BY_LPCTRL, LP_V1200, LP_V1200, LP_V1200, LP_V1200, LP_V1200, FINE_LP_V_P0900);
            SYSCON->PDRUNCFGSET[0] = PDRUNCFG_LP_MODE;
            break;
        case 48000000:
            POWER_setLpVdLevel(LP_V_SET_BY_LPCTRL, LP_V1200, LP_V1200, LP_V1200, LP_V1200, LP_V1200, FINE_LP_V_P1000);
            SYSCON->PDRUNCFGSET[0] = PDRUNCFG_LP_MODE;
            break;
        default:
            /* LP mode is not supported for other frequencies*/
            SYSCON->PDRUNCFGCLR[0] = PDRUNCFG_LP_MODE;
            break;
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
