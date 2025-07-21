/*
 * Copyright 2016 Freescale
 * Copyright 2016,2020 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_rompower.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Codes
 ******************************************************************************/

/**
 * brief    Shut off the Flash and execute the _WFI(), then power up the Flash after wake-up event
 * param    None
 * return    Nothing
 */
void CHIPLOWPOWER_PowerCycleCpuAndFlash(void)
{
    /* Configure the Cortex-M33 in Deep Sleep mode */
    SCB->SCR = SCB->SCR | SCB_SCR_SLEEPDEEP_Msk;

    /*
     * NOTE : It is not necessary to disable the FMC, prior to shut down the flash.
     * Indeed, FMC "flash_pg_er" input pin is what stops any ongoing flash access.
     * We already have Flash Controller output pin "flash_unavailable" feeding into this signal.
     * So, software does not need to take direct action.
     */

    /*
     * Power down the flash
     */

    /* Clear the DONE status bit */
    FLASH->INT_CLR_STATUS = 0x4;

    /* Power Down the Flash */
    // FLASH->CMD = CMD_POWERDOWN;
    FLASH->CMD = 0x1;

    /* Enable analog_ctrl clock */
    SYSCON->PRESETCTRLCLR[2] = SYSCON_PRESETCTRL_ANALOG_CTRL_RST_MASK;
    SYSCON->AHBCLKCTRLSET[2] = SYSCON_AHBCLKCTRL_ANALOG_CTRL_MASK;

    /* Wait until flash is actually power down */
    while ((ANACTRL->ANALOG_CTRL_STATUS & 0x1000) == 0)
        ;

    /* Disable analog_ctrl clock */
    SYSCON->AHBCLKCTRLCLR[2] = SYSCON_AHBCLKCTRL_ANALOG_CTRL_MASK;

    /* Enter in low power mode */
    __WFI();

    /* Power Up the flash (WAKE UP event) */
    FLASH->EVENT = 0x2;

    /* Wait until Flash is powered up */
    while (!(FLASH->INT_STATUS & 0x4))
        ;

    /* Configure the Cortex-M33 in Active mode */
    SCB->SCR = SCB->SCR & (~SCB_SCR_SLEEPDEEP_Msk);
}

/**
 * brief    Configure and enters in low power mode
 * param    p_lowpower_cfg: pointer to a structure that contains all low power mode parameters
 * return   Nothing
 */
void CHIPLOWPOWER_SetLowPowerMode(LPC_LOWPOWER_T *p_lowpower_cfg)
{
    uint32_t low_power_mode = (p_lowpower_cfg->CFG & LOWPOWER_CFG_LPMODE_MASK) >> LOWPOWER_CFG_LPMODE_INDEX;
    uint32_t g_savedPrimask = 0;
    uint32_t primask;

    /* To speed up PMC configuration, change PMC clock from 1 MHz to 12 MHz & set the Low power mode.*/
    if (((p_lowpower_cfg->CFG & LOWPOWER_CFG_SELCLOCK_MASK) >> LOWPOWER_CFG_SELCLOCK_INDEX) ==
        LOWPOWER_CFG_SELCLOCK_1MHZ)
        /* Switch PMC clock to 1 MHz and set the low power mode */
        PMC->CTRL = (PMC->CTRL & (~PMC_CTRL_LPMODE_MASK) & (~PMC_CTRL_SELCLOCK_MASK)) |
                    (low_power_mode << PMC_CTRL_LPMODE_SHIFT);
    else
        /* Switch PMC clock to 12 MHz and set the low power mode */
        PMC->CTRL =
            (PMC->CTRL & (~PMC_CTRL_LPMODE_MASK)) | PMC_CTRL_SELCLOCK_MASK | (low_power_mode << PMC_CTRL_LPMODE_SHIFT);

    /* Interrupt that can postpone power down modes in case an interrupt is pending when the processor request deepsleep
     */
    SYSCON->HARDWARESLEEP = p_lowpower_cfg->HWWAKE;

    /* Configure wake-up by I/O */
    PMC->WAKEUPIOCTRL = p_lowpower_cfg->WAKEUPIOSRC;

    /*
     * SRAM in Retention modes
     * Note: ROM, USB HS SRAM & PUF SRAM are always powered off in DEEP POWER DOWN since DCDC and LDO DEEP SLEEP will be
     * shut off
     */
    PMC->SRAMRETCTRL = p_lowpower_cfg->SRAMRETCTRL;

    /* Configure the voltage level of the Always On domain, Memory and LDO Deep SLeep in Deep Sleep mode */
    PMC->LDOPMU =
        (PMC->LDOPMU & (~PMC_LDOPMU_VADJ_PWD_MASK) & (~PMC_LDOPMU_VADJ_BOOST_PWD_MASK)) |
        (((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_LDO_PMU_MASK) >> LOWPOWER_VOLTAGE_LDO_PMU_INDEX)
         << PMC_LDOPMU_VADJ_PWD_SHIFT) |
        (((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_LDO_PMU_BOOST_MASK) >> LOWPOWER_VOLTAGE_LDO_PMU_BOOST_INDEX)
         << PMC_LDOPMU_VADJ_BOOST_PWD_SHIFT);

    PMC->LDOMEM =
        (PMC->LDOMEM & (~PMC_LDOMEM_VADJ_PWD_MASK) & (~PMC_LDOMEM_VADJ_BOOST_PWD_MASK)) |
        (((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_LDO_MEM_MASK) >> LOWPOWER_VOLTAGE_LDO_MEM_INDEX)
         << PMC_LDOMEM_VADJ_PWD_SHIFT) |
        (((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_LDO_MEM_BOOST_MASK) >> LOWPOWER_VOLTAGE_LDO_MEM_BOOST_INDEX)
         << PMC_LDOMEM_VADJ_BOOST_PWD_SHIFT);

    /*
     * Enable wake up interrupt.
     * Rational : we enable each interrupt (NVIC->ISER) that can wake up the CPU here (before the __disable_irq()
     * below): Hence, if an interrupt was pending and not treated before (for any reason), the CPU will jump to that
     *            interrupt handler before trying to enter the low power mode.
     *            VERY IMPORTANT : Also, any interrupt set in NVIC->ISER, even though __disable_irq(), will make the CPU
     *                             go out of the Deep Sleep mode.
     */
    NVIC->ISER[0] = (uint32_t)(p_lowpower_cfg->WAKEUPINT & 0xFFFFFFFF);
    NVIC->ISER[1] = (uint32_t)((p_lowpower_cfg->WAKEUPINT >> 32) & 0xFFFFFFFF);

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = (uint32_t)(p_lowpower_cfg->WAKEUPSRC & 0xFFFFFFFF);
    SYSCON->STARTER[1] = (uint32_t)((p_lowpower_cfg->WAKEUPSRC >> 32) & 0xFFFFFFFF);

    /* CPU0 is the owner of reduced power mode control */
    /* Only the owner of reduced power mode (CPU0) receives the "wake-up event" from the Sleep Controller*/
    uint32_t syscon_cpuctrl = SYSCON->CPUCTRL;
    syscon_cpuctrl          = (syscon_cpuctrl & (~SYSCON_CPUCTRL_POWERCPU_MASK)) | SYSCON_CPUCTRL_WAKEUPEVENT_MASK;
    SYSCON->CPUCTRL         = 0xC0C40000 | syscon_cpuctrl;

    /* Save the configuration of the Priority Mask Register */
    primask = __get_PRIMASK();

    switch (low_power_mode)
    {
        case LOWPOWER_CFG_LPMODE_DEEPSLEEP:
        {
            /* DEEP SLEEP power mode */
            /* TODO :: :: Enable LDO_DEEP_SLEEP ??? Conflict withh DCDC ???*/

            /* Enable LDO DEEP SLEEP */
            if ((p_lowpower_cfg->PDCTRL0 & LOWPOWER_PDCTRL0_PDEN_LDODEEPSLEEP) == 0)
                /* Turn on DEEP SLEEP LDO in advance */
                PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_LDODEEPSLEEP_MASK;

            /* Analog Modules to be shut off */
            PMC->PDSLEEPCFG0 = p_lowpower_cfg->PDCTRL0;

            PMC->LDODEEPSLEEP = (PMC->LDODEEPSLEEP & (~PMC_LDODEEPSLEEP_VADJ_PWD_MASK)) |
                                (((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_LDO_DEEP_SLEEP_MASK) >>
                                  LOWPOWER_VOLTAGE_LDO_DEEP_SLEEP_INDEX)
                                 << PMC_LDODEEPSLEEP_VADJ_PWD_SHIFT);
            PMC->DCDC0 =
                (PMC->DCDC0 & (~PMC_DCDC0_VOUT_MASK)) |
                ((uint32_t)((p_lowpower_cfg->VOLTAGE & LOWPOWER_VOLTAGE_DCDC_MASK) >> LOWPOWER_VOLTAGE_DCDC_INDEX)
                 << PMC_DCDC0_VOUT_SHIFT);

            /* Make sure DEEP POWER DOWN reset is disable */
            PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

            /* Set Power Management Controller clock frequency to 1 MHz */
            if (((p_lowpower_cfg->CFG & LOWPOWER_CFG_SELCLOCK_MASK) >> LOWPOWER_CFG_SELCLOCK_INDEX) ==
                LOWPOWER_CFG_SELCLOCK_12MHZ)
                /* Switch back PMC clock to 1 MHz */
                PMC->CTRL = PMC->CTRL & (~PMC_CTRL_SELCLOCK_MASK);

            /* Disable all IRQs */
            g_savedPrimask = DisableGlobalIRQ();

            if (p_lowpower_cfg->POWERCYCLE != LOWPOWER_POWERCYCLE_CANCELLED)
            {
                /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
                CHIPLOWPOWER_PowerCycleCpuAndFlash();
            }

            /* Disable LDO DEEP SLEEP */
            PMC->PDRUNCFGSET0 = PMC_PDRUNCFG0_PDEN_LDODEEPSLEEP_MASK;

            /* Enable all interrupts */
            EnableGlobalIRQ(g_savedPrimask);

            break;
        }

        case LOWPOWER_CFG_LPMODE_POWERDOWN:
        {
            /* POWER DOWN power mode */

            /* Analog Modules to be shut off */
            PMC->PDSLEEPCFG0 =
                p_lowpower_cfg->PDCTRL0 | LOWPOWER_PDCTRL0_PDEN_BODCORE | LOWPOWER_PDCTRL0_PDEN_XTAL32M |
                LOWPOWER_PDCTRL0_PDEN_PLLSYS | LOWPOWER_PDCTRL0_PDEN_PLLUSB | LOWPOWER_PDCTRL0_PDEN_USBFSPHY |
                LOWPOWER_PDCTRL0_PDEN_USBHSPHY | LOWPOWER_PDCTRL0_PDEN_TEMPSENS | LOWPOWER_PDCTRL0_PDEN_GPADC |
                LOWPOWER_PDCTRL0_PDEN_LDODEEPSLEEP | LOWPOWER_PDCTRL0_PDEN_LDOUSBHS | LOWPOWER_PDCTRL0_PDEN_LDOGPADC |
                LOWPOWER_PDCTRL0_PDEN_LDOXO32M | LOWPOWER_PDCTRL0_PDEN_LDOFLASHNV | LOWPOWER_PDCTRL0_PDEN_RNG |
                LOWPOWER_PDCTRL0_PDEN_PLLSYS_SSCG;

            /* Make sure DEEP POWER DOWN reset is disable */
            PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

            /* Set Power Management Controller clock frequency to 1 MHz */
            if (((p_lowpower_cfg->CFG & LOWPOWER_CFG_SELCLOCK_MASK) >> LOWPOWER_CFG_SELCLOCK_INDEX) ==
                LOWPOWER_CFG_SELCLOCK_12MHZ)
                /* Switch back PMC clock to 1 MHz */
                PMC->CTRL = PMC->CTRL & (~PMC_CTRL_SELCLOCK_MASK);

            /* CPU0 Retention */
            SYSCON->FUNCRETENTIONCTRL = (SYSCON->FUNCRETENTIONCTRL & LOWPOWER_CPURETCTRL_RETDATALENGTH_MASK) |
                                        (p_lowpower_cfg->CPURETCTRL & (~LOWPOWER_CPURETCTRL_RETDATALENGTH_MASK));

            /* Disable all IRQs */
            g_savedPrimask = DisableGlobalIRQ();

            /*
             * From here :
             *  1 - If an interrupt that is enable occurs,
             *      the _WFI instruction will not be executed and we won't enter in POWER DOWN.
             *  2 - If an interrupt that is not enable occurs, there is no consequence neither
             *      on the execution of the low power mode nor on the behaviour of the CPU.
             */

            if (p_lowpower_cfg->POWERCYCLE != LOWPOWER_POWERCYCLE_CANCELLED)
            {
                /* Enable boot remap feature if there is no retention */
                if (((p_lowpower_cfg->CPURETCTRL & LOWPOWER_CPURETCTRL_ENA_MASK) >> LOWPOWER_CPURETCTRL_ENA_INDEX) ==
                    LOWPOWER_CPURETCTRL_ENA_DISABLE)
                {
                    /* Retention mode is NOT enable : enable memory remap feature */
                    SYSCON->MEMORYREMAP &= (~SYSCON_MEMORYREMAP_MAP_MASK); /* Vector Table in ROM */
                }

                /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
                CHIPLOWPOWER_PowerCycleCpuAndFlash();

                /*
                 * We can reach this point for 2 reasons:
                 * 1 - We are coming out from POWER DOWN mode with CPU state retention.
                 * 2 - We didn't enter the POWER DOWN mode because a wake up interrupt poped up just
                 *     before entering the POWER DOWN mode (as a consequence, the WFI() has been ignored)
                 */

                /* Disable boot remap feature.
                 * This is required because it could be that the _WFI has not been executed (Power cycle is cancelled),
                 */
                if (((p_lowpower_cfg->CPURETCTRL & LOWPOWER_CPURETCTRL_ENA_MASK) >> LOWPOWER_CPURETCTRL_ENA_INDEX) ==
                    LOWPOWER_CPURETCTRL_ENA_DISABLE)
                {
                    /* Vector Table in Flash */
                    SYSCON->MEMORYREMAP =
                        (SYSCON->MEMORYREMAP & (~SYSCON_MEMORYREMAP_MAP_MASK)) | SYSCON_MEMORYREMAP_MAP(2);
                }
            }

            /* Enable all interrupts */
            EnableGlobalIRQ(g_savedPrimask);

            break;
        }

        case LOWPOWER_CFG_LPMODE_DEEPPOWERDOWN:
        {
            /* DEEP POWER DOWN power mode */

            /*
             - Configure whether or not the BIAS shall stay powered in Deep Power Down mode
             - Configure whether or not the VBAT BOD shall stay powered in Deep Power Down mode
             - Configure whether or not the FRO 1MHz shall stay powered in Deep Power Down mode
            */
            PMC->PDSLEEPCFG0 =
                p_lowpower_cfg->PDCTRL0 | LOWPOWER_PDCTRL0_PDEN_BODCORE | LOWPOWER_PDCTRL0_PDEN_XTAL32M |
                LOWPOWER_PDCTRL0_PDEN_PLLSYS | LOWPOWER_PDCTRL0_PDEN_PLLUSB | LOWPOWER_PDCTRL0_PDEN_USBFSPHY |
                LOWPOWER_PDCTRL0_PDEN_USBHSPHY | LOWPOWER_PDCTRL0_PDEN_TEMPSENS | LOWPOWER_PDCTRL0_PDEN_GPADC |
                LOWPOWER_PDCTRL0_PDEN_LDODEEPSLEEP | LOWPOWER_PDCTRL0_PDEN_LDOUSBHS | LOWPOWER_PDCTRL0_PDEN_LDOGPADC |
                LOWPOWER_PDCTRL0_PDEN_LDOXO32M | LOWPOWER_PDCTRL0_PDEN_LDOFLASHNV | LOWPOWER_PDCTRL0_PDEN_RNG |
                LOWPOWER_PDCTRL0_PDEN_PLLSYS_SSCG;

            /* Set Power Management Controller clock frequency to 1 MHz */
            if (((p_lowpower_cfg->CFG & LOWPOWER_CFG_SELCLOCK_MASK) >> LOWPOWER_CFG_SELCLOCK_INDEX) ==
                LOWPOWER_CFG_SELCLOCK_12MHZ)
                /* Switch back PMC clock to 1 MHz */
                PMC->CTRL = PMC->CTRL & (~PMC_CTRL_SELCLOCK_MASK);

            /* Disable all IRQs */
            g_savedPrimask = DisableGlobalIRQ();

            /*
             * From here :
             *  1 - If an interrupt that is enable occurs,
             *      the _WFI instruction will not be executed and we won't enter in POWER DOWN.
             *  2 - If an interrupt that is not enable occurs, there is no consequence neither
             *      on the execution of the low power mode nor on the behaviour of the CPU.
             */
            if (p_lowpower_cfg->POWERCYCLE != LOWPOWER_POWERCYCLE_CANCELLED)
            {
                /* clear all Reset causes */
                PMC->RESETCAUSE = 0xFF;

                /* Enable DEEP POWER DOWN reset */
                PMC->RESETCTRL |= PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK;

                /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
                CHIPLOWPOWER_PowerCycleCpuAndFlash();
            }

            /* Enable all interrupts */
            EnableGlobalIRQ(g_savedPrimask);

            /*** We should never reach this point, unless the Low Power cycle has been canclled somehow. ***/
            break;
        }

        default:
        {
            /* Error */
            break;
        }

            PMC->CTRL = (PMC->CTRL & (~PMC_CTRL_LPMODE_MASK)) | (LOWPOWER_CFG_LPMODE_ACTIVE << PMC_CTRL_LPMODE_SHIFT);

            /* Reset Sleep Postpone configuration */
            SYSCON->HARDWARESLEEP = 0;

            /*
             * Restore the configuration of the Priority Mask Register.
             * Rational : if the interrupts were enable before entering the Low power mode, they will be re-enabled,
             *            if they were disabled, they will stay disabled.
             */
            __set_PRIMASK(primask);
    }
}
