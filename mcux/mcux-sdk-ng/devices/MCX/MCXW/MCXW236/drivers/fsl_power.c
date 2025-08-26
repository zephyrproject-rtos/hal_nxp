/*
 * Copyright 2016,2020-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_power.h"
#include "fsl_iocon.h"
#include "fsl_system.h"
#include "fsl_rom_api.h"

/*! @name Driver version */
/*@{*/
/*! @brief MCXW23 power control version. */
#define FSL_MCXW23_POWER_CONTROL_VERSION (MAKE_VERSION(3, 0, 0))
/*@}*/

/* The settling time in microseconds of the BOD. After changing BOD level, POWER_IsBODActive is only valid after this
 * time */
#define STABILIZATION_TIME_IN_US (40)

/* FRO and XTAL startup time in milliseconds. */
#define DEFAULT_FRO_STARTUP_DELAY_MS  (100)
#define DEFAULT_XTAL_STARTUP_DELAY_MS (500)

/* Location in SRAM_X2 used to store CPU retention values. */
#define CPU_RETENTION_RAMX_STORAGE_START_ADDR (0x4002000)
#define CPU_RETENTION_RAMX_STORAGE_OFFSET (0x900)

/* BIAS configurations */
#define PMC_PDSLEEPCFG0_PDEN_BIAS_0_66     (0 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_0_63     (1 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)
#define PMC_PDSLEEPCFG0_PDEN_BIAS_DISABLED (2 << PMC_PDSLEEPCFG0_PDEN_BIAS_SHIFT)

/* Configuration values to select desired power mode in PMC->CTRL  */
#define LOWPOWER_CTRL_LPMODE_ACTIVE        0
#define LOWPOWER_CTRL_LPMODE_DEEPSLEEP     1
#define LOWPOWER_CTRL_LPMODE_POWERDOWN     2
#define LOWPOWER_CTRL_LPMODE_DEEPPOWERDOWN 3
#define LOWPOWER_CTRL_POFFMODE_OFF 0
#define LOWPOWER_CTRL_POFFMODE_ON  1
#define LOWPOWER_CTRL_SELCLOCK_1MHZ 0 

/* excludeFromPd direct hardware bits mask */
#define EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK                                                                    \
    (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2 | kLOWPOWERCFG_FRO1M | kLOWPOWERCFG_FRO192M | \
     kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K | kLOWPOWERCFG_TRNG)

/*
 * Defines needed by functions GetCoreSysClkConfiguration(void) and
 * SetCoreSysClkConfiguration(uint32_t configuration)
 */

#define BIT_COUNT_1(x)     ((x) & 1U)
#define BIT_COUNT_2(x)     (BIT_COUNT_1(x) + BIT_COUNT_1((x) >> 1))
#define BIT_COUNT_4(x)     (BIT_COUNT_2(x) + BIT_COUNT_2((x) >> 2))
#define BIT_COUNT_8(x)     (BIT_COUNT_4(x) + BIT_COUNT_4((x) >> 4))
#define BIT_COUNT_16(x)    (BIT_COUNT_8(x) + BIT_COUNT_8((x) >> 8))
#define BIT_COUNT_32(x)    (BIT_COUNT_16(x) + BIT_COUNT_16((x) >> 16))
#define COUNT_BITS(mask)   BIT_COUNT_32(mask)

#define SYSCON_MAINCLKSELA_SEL_BITS               COUNT_BITS(SYSCON_MAINCLKSELA_SEL_MASK)
#define SYSCON_MAINCLKSELB_SEL_BITS               COUNT_BITS(SYSCON_MAINCLKSELB_SEL_MASK)
#define SYSCON_AHBCLKDIV_DIV_BITS                 COUNT_BITS(SYSCON_AHBCLKDIV_DIV_MASK)
#define ANACTRL_FRO192M_CTRL_ENA_BITS             COUNT_BITS(ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK | \
                                                             ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK | \
                                                             ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK | \
                                                             ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK | \
                                                             ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK)
#define SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS          COUNT_BITS(SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK)
#define SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS COUNT_BITS(SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK)
#define PMC_PDRUNCFG0_PDEN_FRO192M_BITS           COUNT_BITS(PMC_PDRUNCFG0_PDEN_FRO192M_MASK)

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

/*
 * AOREG1 defines that match with bootloader
 */
#define AOREG1_DCDC_MODE_XR_SM_SS_SHIFT (24)
#define AOREG1_DCDC_MODE_XR_SM_SS_MASK  (1 << AOREG1_DCDC_MODE_XR_SM_SS_SHIFT)
#define AOREG1_DCDC_MODE_XR_SM_DS_SHIFT (25)
#define AOREG1_DCDC_MODE_XR_SM_DS_MASK  (1 << AOREG1_DCDC_MODE_XR_SM_DS_SHIFT)

#define AOREG1_BOD1_SHIFT (26)
#define AOREG1_BOD1_MASK  (1 << AOREG1_BOD1_SHIFT)
#define AOREG1_BOD2_SHIFT (27)
#define AOREG1_BOD2_MASK  (1 << AOREG1_BOD2_SHIFT)

/* BLE state related defines */
#define PMC_BLE_STATE                  ((PMC->STATUS & PMC_STATUS_FSMBLESTATE_MASK) >> PMC_STATUS_FSMBLESTATE_SHIFT)
#define PMC_BLE_STATE_RADIO_ACTIVE     (6u)
#define PMC_BLE_STATE_ENABLE_CLOCK_OUT (2u)

/* SRAM control related defines */
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

/**
 * @brief Digital LDO voltage adjustment levels.
 */
typedef enum ldo_dig_vadj_s
{
    kLDO_DIG_900mv  = 0U,
    kLDO_DIG_950mv  = 1U,
    kLDO_DIG_1000mv = 2U,
    kLDO_DIG_1050mv = 3U,
} ldo_dig_vadj_t;

/**
 * @brief Memory LDO voltage adjustment levels.
 */
typedef enum ldo_mem_vadj_s
{
    kLDO_MEM_900mv  = 0U,
    kLDO_MEM_950mv  = 1U,
    kLDO_MEM_1000mv = 2U,
    kLDO_MEM_1050mv = 3U,
} ldo_mem_vadj_t;

/**
 * @brief Power supply modes.
 */
typedef enum supply_mode_s
{
    kSUPPLY_MODE_HV_SM       = 0U,
    kSUPPLY_MODE_XR_SS_BUCK  = 1U,
    kSUPPLY_MODE_XR_DS_BUCK  = 2U,
    kSUPPLY_MODE_COUNT       = 3U,
} supply_mode_t;

/**
 * @brief Low power modes.
 */
typedef enum lp_mode_s
{
    kLP_MODE_DEEPSLEEP     = 0U,
    kLP_MODE_POWERDOWN     = 1U,
    kLP_MODE_DEEPPOWERDOWN = 2U,
    kLP_MODE_POWEROFF      = 3U,
    kLP_MODE_COUNT         = 4U,
} lp_mode_t;

/**
 * @brief DC/DC exclusion modes.
 */
typedef enum DCDC_exclude_mode_s
{
    kDCDC_EXCLUDE_NONE   = 0U,
    kDCDC_EXCLUDE_DCDC   = 1U,
    kDCDC_EXCLUDE_BYPASS = 2U,
    kDCDC_EXCLUDE_COUNT  = 3U,
} dcdc_exclude_mode_t;

/**
 * @brief DC/DC hardware modes.
 * 
 * These must match the values in dcdc_mode_t.
 */
typedef enum dcdc_hw_mode_s
{
    kDCDC_HW_MODE_HV_SM = 1U,
    kDCDC_HW_MODE_LV_SM = 2U,
} dcdc_hw_mode_t;

typedef status_t(*DcdcExcludeFunction_t)(uint32_t *excludeFromPd);

static void DelayUs(uint32_t delay);
static void DelayMs(uint32_t delay);
static status_t DcdcBypass(uint32_t *excludeFromPd);
static status_t DcdcOn(uint32_t *excludeFromPd);
static status_t DcdcOff(uint32_t *excludeFromPd);
static status_t DcdcError(uint32_t *excludeFromPd);

/*******************************************************************************
 * Global variables
 ******************************************************************************/
static uint32_t s_xtalStartupTime = DEFAULT_XTAL_STARTUP_DELAY_MS;

/* Lookup table for MCXW23xB (Buck and XRSM) silicon */
static const DcdcExcludeFunction_t
    s_dcdcExcludeFunctionMcxw23xb[kLP_MODE_COUNT][kSUPPLY_MODE_COUNT][kDCDC_EXCLUDE_COUNT] = {
        {
            /* DEEPSLEEP */
            {DcdcBypass, DcdcOn, DcdcBypass},    /* kSUPPLY_MODE_HV_SM */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_SS_BUCK */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_DS_BUCK */
        },
        {
            /* POWERDOWN */
            {DcdcBypass, DcdcOn, DcdcBypass},    /* kSUPPLY_MODE_HV_SM */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_SS_BUCK */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_DS_BUCK */
        },
        {
            /* DEEPPOWERDOWN */
            {DcdcOff, DcdcOn, DcdcBypass},       /* kSUPPLY_MODE_HV_SM */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_SS_BUCK */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_DS_BUCK */
        },
        {
            /* POWEROFF */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_HV_SM */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_SS_BUCK */
            {DcdcOff, DcdcError, DcdcError},     /* kSUPPLY_MODE_XR_DS_BUCK */
        },
    };

/* Lookup table for MCXW23xA (Boost) silicon */
static const DcdcExcludeFunction_t
    s_dcdcExcludeFunctionMcxw23xa[kLP_MODE_COUNT][kDCDC_EXCLUDE_COUNT] = {
        /* DEEPSLEEP */
        {DcdcOff, DcdcOn, DcdcBypass},
        /* POWERDOWN */
        {DcdcOff, DcdcOn, DcdcBypass},
        /* DEEPPOWERDOWN */
        {DcdcOff, DcdcOn, DcdcBypass},
        /* POWEROFF */
        {DcdcOff, DcdcError, DcdcError},
    };

/*******************************************************************************
 * Static functions
 ******************************************************************************/

 /**
 * @brief Save GPIO pin configuration registers to retention RAM
 */
 static void SavePinRegisters(void)
{
    uint32_t *cpuRetStorePtr =
        (uint32_t *)(CPU_RETENTION_RAMX_STORAGE_START_ADDR + CPU_RETENTION_RAMX_STORAGE_OFFSET);
    uint32_t pinsDir = GPIO->DIR[0];

    *cpuRetStorePtr++ = pinsDir;
    *cpuRetStorePtr++ = GPIO->PIN[0];
    for (uint32_t i = 0; i <= 22; i++)
    {
        *cpuRetStorePtr++ = IOCON->PIO[0][i];
        /* Set all pins that are configured as output, temporary to FUNC12 before going to lower power
        to avoid a 120ns pulse during wakeup from power down. */
        if ((pinsDir & (1 << i)) > 0)
        {
            IOCON->PIO[0][i] = (IOCON->PIO[0][i] & ~IOCON_PIO_FUNC_MASK) | (IOCON_FUNC12 & IOCON_PIO_FUNC_MASK);
        }
    }
}

/**
 * @brief Restore GPIO pin configuration registers from retention RAM
 */
static void RestorePinRegisters(void)
{
    uint32_t *cpuRetStorePtr = (uint32_t *)(CPU_RETENTION_RAMX_STORAGE_START_ADDR + CPU_RETENTION_RAMX_STORAGE_OFFSET);
    GPIO->DIR[0]                = *cpuRetStorePtr++;
    GPIO->PIN[0]                = *cpuRetStorePtr++;
    for (uint32_t i = 0; i <= 22; i++)
    {
        IOCON->PIO[0][i] = *cpuRetStorePtr++;
    }
}

/**
 * @brief Get current core system clock configuration
 * @return Packed 32-bit value containing clock configuration
 */
static uint32_t GetCoreSysClkConfiguration(void)
{
    uint32_t returnValue = 0;
    uint32_t pos          = 0;
    returnValue |= (((SYSCON->MAINCLKSELA & SYSCON_MAINCLKSELA_SEL_MASK) >> SYSCON_MAINCLKSELA_SEL_SHIFT) << pos);
    pos += SYSCON_MAINCLKSELA_SEL_BITS;
    returnValue |= (((SYSCON->MAINCLKSELB & SYSCON_MAINCLKSELB_SEL_MASK) >> SYSCON_MAINCLKSELB_SEL_SHIFT) << pos);
    pos += SYSCON_MAINCLKSELB_SEL_BITS;
    returnValue |= (((SYSCON->AHBCLKDIV & SYSCON_AHBCLKDIV_DIV_MASK) >> SYSCON_AHBCLKDIV_DIV_SHIFT) << pos);
    pos += SYSCON_AHBCLKDIV_DIV_BITS;
    returnValue |=
        (((ANACTRL->FRO192M_CTRL & (ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK | ANACTRL_FRO192M_CTRL_ENA_24MHZCLK_MASK |
                                    ANACTRL_FRO192M_CTRL_ENA_32MHZCLK_MASK | ANACTRL_FRO192M_CTRL_ENA_48MHZCLK_MASK |
                                    ANACTRL_FRO192M_CTRL_ENA_64MHZCLK_MASK)) >>
          ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_SHIFT)
         << pos);
    pos += ANACTRL_FRO192M_CTRL_ENA_BITS;
    returnValue |=
        (((SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_CLKIN_ENA_MASK) >> SYSCON_CLOCK_CTRL_CLKIN_ENA_SHIFT) << pos);
    pos += SYSCON_CLOCK_CTRL_CLKIN_ENA_BITS;
    returnValue |= (((SYSCON->CLOCK_CTRL & SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_MASK) >>
                      SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_SHIFT)
                     << pos);
    pos += SYSCON_CLOCK_CTRL_ANA_FRO12M_CLK_ENA_BITS;
    returnValue |= (((PMC->PDRUNCFG0 & PMC_PDRUNCFG0_PDEN_FRO192M_MASK) >> PMC_PDRUNCFG0_PDEN_FRO192M_SHIFT) << pos);
    return returnValue;
}

/**
 * @brief Set core system clock configuration
 * @param configuration Packed 32-bit value containing clock configuration
 */
static void SetCoreSysClkConfiguration(uint32_t configuration)
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

/**
 * @brief Enable DCDC bypass mode
 * @param excludeFromPd Pointer to power down exclusion bitmap
 * @return Status of operation
 */
static status_t DcdcBypass(uint32_t *excludeFromPd)
{
    /* Set enable LPBS request */
    PMC->DCDC0 |= PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* Disable DCDC during low power mode */
    *excludeFromPd &= ~kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

/**
 * @brief Enable DCDC converter
 * @param excludeFromPd Pointer to power down exclusion bitmap
 * @return Status of operation
 */
static status_t DcdcOn(uint32_t *excludeFromPd)
{
    /* Disable LPBS */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* Enable DCDC during low power mode */
    *excludeFromPd |= kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

static status_t DcdcOff(uint32_t *excludeFromPd)
{
    /* Disable LPBS */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;
    /* Disable DCDC during low power mode */
    *excludeFromPd &= ~kLOWPOWERCFG_DCDC;
    return kStatus_Success;
}

/**
 * @brief Disable DCDC converter
 * @param excludeFromPd Pointer to power down exclusion bitmap
 * @return Status of operation
 */
static status_t DcdcError(uint32_t *excludeFromPd)
{
    return kStatus_InvalidArgument;
}

/**
 * @brief Set power configuration for low power modes
 * @param lpMode Low power mode to configure
 * @param excludeFromPd Pointer to power down exclusion bitmap
 * @return Status of operation
 */
static status_t SetPowerConfiguration(lp_mode_t lpMode, uint32_t *excludeFromPd)
{
    dcdc_mode_t mode       = POWER_DCDC_GetSupplyMode();
    status_t status = kStatus_Success;

    dcdc_exclude_mode_t dcdcExclude = kDCDC_EXCLUDE_NONE;
    if ((*excludeFromPd & kLOWPOWERCFG_DCDC_BYPASS) && (*excludeFromPd & kLOWPOWERCFG_DCDC))
    {
        /* kLOWPOWERCFG_DCDC_BYPASS and kLOWPOWERCFG_DCDC cannot be added to excludeFromPd together. */
        status = kStatus_InvalidArgument;
    }
    else if(*excludeFromPd & kLOWPOWERCFG_DCDC_BYPASS)
    {
        dcdcExclude |= kDCDC_EXCLUDE_BYPASS;
    }
    else if(*excludeFromPd & kLOWPOWERCFG_DCDC)
    {
        dcdcExclude |= kDCDC_EXCLUDE_DCDC;
    }

    if(status == kStatus_Success)
    {
        /********************************* BUCK MODE (MCXW23xB) *********************************/
        if (mode == kDCDC_MODE_HV_SM)
        {
            status = s_dcdcExcludeFunctionMcxw23xb[lpMode][kSUPPLY_MODE_HV_SM][dcdcExclude](
                excludeFromPd);
        }
        /********************************* XRSM SS MODE (MCXW23xB) *********************************/
        else if (mode == kDCDC_MODE_XR_SM_SS)
        {
            /* XRSM only supported on MCXW23xB, so hw_mode is always buck */
            status = s_dcdcExcludeFunctionMcxw23xb[lpMode][kSUPPLY_MODE_XR_SS_BUCK][dcdcExclude](
                excludeFromPd);
        }
        /********************************* XRSM DS MODE (MCXW23xB) *********************************/
        else if (mode == kDCDC_MODE_XR_SM_DS)
        {
            /* XRSM only supported on MCXW23xB, so hw_mode is always buck */
            status = s_dcdcExcludeFunctionMcxw23xb[lpMode][kSUPPLY_MODE_XR_DS_BUCK][dcdcExclude](
                excludeFromPd);
        }
        /********************************* BOOST MODE (MCXW23xA) *********************************/
        else if (mode == kDCDC_MODE_LV_SM)
        {
            status = s_dcdcExcludeFunctionMcxw23xa[lpMode][dcdcExclude](
                excludeFromPd);
        }
        else
        {
            status = kStatus_InvalidArgument;
        }
    }

    return status;
}

/**
 * @brief Enable BOD1 interrupts
 */
static void EnableBOD1Interrupts(void)
{
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
}

/**
 * @brief Disable BOD1 interrupts
 */
static void DisableBOD1Interrupts(void)
{
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl &= ~ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
}

/**
 * @brief Enable BOD1 reset functionality
 */
static void EnableBOD1Resets(void)
{
    uint32_t resetCtrl = PMC->RESETCTRL;
    resetCtrl &= (~(PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK));
    resetCtrl |= (1 << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT | 1 << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = resetCtrl;
}

/**
 * @brief Disable BOD1 reset functionality
 */
static void DisableBOD1Resets(void)
{
    uint32_t resetCtrl = PMC->RESETCTRL;
    resetCtrl &= (~(PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK));
    resetCtrl |= (2 << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT | 2 << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = resetCtrl;
}

/**
 * @brief Enable BOD2 interrupts
 */
static void EnableBOD2Interrupts(void)
{
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
}

/**
 * @brief Disable BOD2 interrupts
 */
static void DisableBOD2Interrupts(void)
{
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl &= ~ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_ENABLE_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
}

/**
 * @brief Enable BOD2 reset functionality
 */
static void EnableBOD2Resets(void)
{
    uint32_t resetCtrl = PMC->RESETCTRL;
    resetCtrl &= (~(PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK));
    resetCtrl |= (1 << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT | 1 << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = resetCtrl;
}

/**
 * @brief Disable BOD2 reset functionality
 */
static void DisableBOD2Resets(void)
{
    uint32_t resetCtrl = PMC->RESETCTRL;
    resetCtrl &= (~(PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK | PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK));
    resetCtrl |= (2 << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT | 2 << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT);
    PMC->RESETCTRL = resetCtrl;
}

/**
 * @brief Calculate adjusted BOD level register setting
 * @param level BOD level configuration
 * @param offset Calibration offset
 * @return Adjusted register value
 */
static uint32_t AdjustedLevelRegisterSetting(bod_level_t level, uint8_t offset)
{
    int8_t signedOffset = offset;
    int8_t adjustedHysteresis;
    uint8_t adjustedTriglvl = ((level & PMC_BOD1_TRIGLVL_MASK) >> PMC_BOD1_TRIGLVL_SHIFT);
    uint8_t adjustedLvlsel  = ((level & PMC_BOD1_LVLSEL_MASK) >> PMC_BOD1_LVLSEL_SHIFT);

    /* Offset is 5 bits 2-complement encoded */
    if (offset & 0x10)
    {
        signedOffset -= 0x20;
    }

    /* Level contains the register value to be set in the BODx register. We calculate the adjustedHysteresis
     * from the hysteresis setting, the lvlsel setting and the offset. We extend the definition beyond 0 - 3 with
     * -5 for -100mV, -4 for -75mV, -3 for -50mV, -2 for -25mV, -1 for 0mV, 5 for +125mV, 6 for +150mV and 7 for +175mV.
     */
    if (adjustedLvlsel == 1)
    {
        adjustedHysteresis = -1;
    }
    else
    {
        adjustedHysteresis = ((level & PMC_BOD1_HYST_MASK) >> PMC_BOD1_HYST_SHIFT);
    }
    adjustedHysteresis -= signedOffset;

    if (adjustedTriglvl > 10) /* triglvl has steps of 100mV for setting 10 and above */
    {
        if (adjustedHysteresis < -1)
        {
            adjustedHysteresis += 4;
            adjustedTriglvl -= 1;
        }
        if (adjustedHysteresis > 3)
        {
            adjustedHysteresis -= 4;
            adjustedTriglvl += 1;
        }
    }
    else
    {
        if (adjustedTriglvl == 10) /* triglvl has steps for setting 10 of 100mV upwards and 50mV downwards */
        {
            if (adjustedHysteresis < -3)
            {
                adjustedHysteresis += 2;
                adjustedTriglvl -= 1;
            }
            if (adjustedHysteresis < -1)
            {
                adjustedHysteresis += 2;
                adjustedTriglvl -= 1;
            }
            if (adjustedHysteresis > 3)
            {
                adjustedHysteresis -= 4;
                adjustedTriglvl += 1;
            }
        }
        else /* triglvl has steps of 50mV for setting 9 and below */
        {
            if (adjustedHysteresis < -3)
            {
                adjustedHysteresis += 2;
                adjustedTriglvl -= 1;
            }
            if (adjustedHysteresis < -1)
            {
                adjustedHysteresis += 2;
                adjustedTriglvl -= 1;
            }
            if (adjustedHysteresis > 5)
            {
                adjustedHysteresis -= 2;
                adjustedTriglvl += 1;
            }
            if (adjustedHysteresis > 3)
            {
                adjustedHysteresis -= 2;
                adjustedTriglvl += 1;
            }
        }
    }

    /* To add 0mV we have to set adjustedLvlsel to 1, otherwise it must be set to 0. */
    if (adjustedHysteresis == -1)
    {
        adjustedHysteresis = 0;
        adjustedLvlsel     = 1;
    }
    else
    {
        adjustedLvlsel = 0;
    }

    return (uint32_t)((adjustedLvlsel << PMC_BOD1_LVLSEL_SHIFT) | (adjustedHysteresis << PMC_BOD1_HYST_SHIFT) |
                      (adjustedTriglvl << PMC_BOD1_TRIGLVL_SHIFT));
}

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
    IRQn_Type nvicBodIrq             = instance == 0 ? BOD1_IRQn : BOD2_IRQn;
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
    setBodLevel((bod_level_t)levelSettings[currentSetting]);
    DelayUs(STABILIZATION_TIME_IN_US);

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
        setBodLevel((bod_level_t)levelSettings[currentSetting]);
        DelayUs(STABILIZATION_TIME_IN_US);
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

/**
 * @brief Delay execution for microseconds
 * @param delay Number of microseconds to delay
 */
static void DelayUs(uint32_t delay)
{
    SDK_DelayAtLeastUs(delay, SystemCoreClock);
}

/**
 * @brief Delay execution for milliseconds
 * @param delay Number of milliseconds to delay
 */
static void DelayMs(uint32_t delay)
{
    DelayUs(delay * 1000);
}

/*******************************************************************************
 * Public functions
 ******************************************************************************/

/**
 * @brief Power cycle CPU and flash
 * 
 * Shuts off the Flash and executes WFI(), then powers up the Flash after wake-up event.
 * Shut off the Flash is done by hardware, then power up the Flash after wake-up event also.
 */
void POWER_PowerCycleCpuAndFlash(void)
{
    /* Store PDEN_BOD1/2 from PDRUNCFG register into AOREG1 for non retention modes */
    uint32_t pdruncfg0 = PMC->PDRUNCFG0;
    uint32_t pdenBod1 = (pdruncfg0 & PMC_PDRUNCFG0_PDEN_BOD1_MASK) >> PMC_PDRUNCFG0_PDEN_BOD1_SHIFT;
    uint32_t pdenBod2 = (pdruncfg0 & PMC_PDRUNCFG0_PDEN_BOD2_MASK) >> PMC_PDRUNCFG0_PDEN_BOD2_SHIFT;
    PMC->AOREG1 &= ~(AOREG1_BOD1_MASK | AOREG1_BOD2_MASK);
    PMC->AOREG1 |= ((pdenBod1 << AOREG1_BOD1_SHIFT) | (pdenBod2 << AOREG1_BOD2_SHIFT));
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

    /* This is retention mode, restore the PDEN_BOD1 and PDEN_BOD2 values of the PMC_PDRUNCFG0 register */
    PMC->PDRUNCFG0 = pdruncfg0;
}

/**
 * @brief Perform system reset
 */
void POWER_Reset(void)
{
    PMC->RESETCTRL |= PMC_RESETCTRL_SWRRESETENABLE_MASK;
    SYSCON->SWR_RESET = 0x5A000001;

    while (1)
    {
        ;
    }
}

/**
 * @brief Initialize power management subsystem
 */
void POWER_Init(void)
{
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

    /* Enable auto clock gating of SRAMS to be able to switch SRAM power mode and all the rest also at the same time */
    SYSCON->AUTOCLKGATEOVERRIDE =
        (SYSCON->AUTOCLKGATEOVERRIDE &
         ~(SYSCON_AUTOCLKGATEOVERRIDE_ROM_MASK | SYSCON_AUTOCLKGATEOVERRIDE_RAMX_CTRL_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_RAM0_CTRL_MASK | SYSCON_AUTOCLKGATEOVERRIDE_RAM1_CTRL_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_RAM2_CTRL_MASK | SYSCON_AUTOCLKGATEOVERRIDE_SYNC0_APB_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SYNC1_APB_MASK | SYSCON_AUTOCLKGATEOVERRIDE_FLASH_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_FMC_MASK | SYSCON_AUTOCLKGATEOVERRIDE_CRCGEN_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SDMA0_MASK | SYSCON_AUTOCLKGATEOVERRIDE_SDMA1_MASK |
           SYSCON_AUTOCLKGATEOVERRIDE_SYSCON_MASK)) |
        (0xC0DEU << SYSCON_AUTOCLKGATEOVERRIDE_ENABLEUPDATE_SHIFT);
    /* Note: there is no SYSCON_AUTOCLKGATEOVERRIDE for BLE RAM */

    /* Goto DEEPSLEEP (retention) mode in PMC Low-power modes DSLP and PWDN except when already in SHUTDOWN, then remain in SHUTDOWN */
    PMC->SRAMRETCTRL = PMC_SRAMRETCTRL_RETEN_RAMX0_MASK | PMC_SRAMRETCTRL_RETEN_RAMX1_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAMX2_MASK | PMC_SRAMRETCTRL_RETEN_RAMX3_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAM00_MASK | PMC_SRAMRETCTRL_RETEN_RAM10_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAM20_MASK | PMC_SRAMRETCTRL_RETEN_RAMBLEDATA_MASK |
                       PMC_SRAMRETCTRL_RETEN_RAMBLESEQL_MASK;

    uint32_t pmcLdoMem = PMC->LDOMEM;
    /* Do not keep 1V from ACTIVE state but change to 0.6x V in low power mode  */
    pmcLdoMem |= PMC_LDOMEM_VADJ_PWD_MASK;
    /* Set 1 V for lowest power consumption */
    pmcLdoMem &= ~PMC_LDOMEM_VADJ_MASK;
    pmcLdoMem |= (kLDO_MEM_1000mv << PMC_LDOMEM_VADJ_SHIFT);
    PMC->LDOMEM = pmcLdoMem;

    uint32_t pmcLdoDig = PMC->LDODIG;
    /* Set 1 V for lowest power consumption */
    pmcLdoDig &= ~PMC_LDODIG_VADJ_MASK;
    pmcLdoDig |= (kLDO_DIG_1000mv << PMC_LDODIG_VADJ_SHIFT);
    PMC->LDODIG = pmcLdoDig;

    /* Enable LSActive for lowest power consumption */
    /* IMPORTANT: This bit must always be set to 1. Flash is characterized with this bit set. */
    FMU0->FCTRL |= FMU_FCTRL_LSACTIVE_MASK;

    /* restore PDEN_BOD1/2 from AOREG1 to PDRUNCFG register for non retention modes */
    uint32_t pdenBod1 = (PMC->AOREG1 & AOREG1_BOD1_MASK) >> AOREG1_BOD1_SHIFT;
    uint32_t pdenBod2 = (PMC->AOREG1 & AOREG1_BOD2_MASK) >> AOREG1_BOD2_SHIFT;
    uint32_t pdruncfg0 = PMC->PDRUNCFG0;
    pdruncfg0 &= ~(PMC_PDRUNCFG0_PDEN_BOD1_MASK | PMC_PDRUNCFG0_PDEN_BOD2_MASK);
    pdruncfg0 |= ((pdenBod1 << PMC_PDRUNCFG0_PDEN_BOD1_SHIFT) | (pdenBod2 << PMC_PDRUNCFG0_PDEN_BOD2_SHIFT));
    PMC->PDRUNCFG0 = pdruncfg0;

    /* restore PMC settings in XR_SM modes */
    uint32_t aoreg1 = PMC->AOREG1;
    
    /* Clear XR_SM mode in AOREG1 to be able to recover next time in case supply is not connected anymore and there is a
     * hang further down */
    /* POWER_DCDC_SetSupplyMode() will set it back. */
    PMC->AOREG1 &= ~(AOREG1_DCDC_MODE_XR_SM_SS_MASK | AOREG1_DCDC_MODE_XR_SM_DS_MASK);

    if (aoreg1 & AOREG1_DCDC_MODE_XR_SM_SS_MASK)
    {
        POWER_DCDC_SetSupplyMode(kDCDC_MODE_XR_SM_SS);
    }
    else if (aoreg1 & AOREG1_DCDC_MODE_XR_SM_DS_MASK)
    {
        POWER_DCDC_SetSupplyMode(kDCDC_MODE_XR_SM_DS);
    }

    /* In case system woke up from os timer event in deep power down, PMC register 
     * needs to be cleared to avoid undesired future wakeup from ostimer.
     * (because PMC registers are not cleared automatically after reset or wakeup.) */
    PMC->OSTIMERr &= ~PMC_OSTIMER_DPDWAKEUPENABLE_MASK;

    /* Disable all unused clocks that are on by default after boot */
    CLOCK_DisableClock(kCLOCK_Rng);
    CLOCK_DisableClock(kCLOCK_Iocon);
    CLOCK_DisableClock(kCLOCK_Gpio0);
    CLOCK_DisableClock(kCLOCK_Sysctl);
    CLOCK_DisableClock(kCLOCK_HashCrypt);
    CLOCK_DisableClock(kCLOCK_Puf);
    CLOCK_DisableClock(kCLOCK_Casper);
}

/**
 * @brief Power off a peripheral
 * @param powerConfigBit Peripheral to power off
 */
void POWER_PeripheralPowerOff(power_config_bit_t powerConfigBit)
{
    PMC->PDRUNCFGSET0 = powerConfigBit;
}

/**
 * @brief Set 32K XTAL startup time
 * @param startupTime Startup time in milliseconds
 */
void POWER_XTAL32K_SetStartupTime(uint32_t startupTime)
{
    s_xtalStartupTime = startupTime;
}

/**
 * @brief Power on a peripheral
 * @param powerConfigBit Peripheral to power on
 */
void POWER_PeripheralPowerOn(power_config_bit_t powerConfigBit)
{
    if (powerConfigBit & kPOWERCFG_XTAL32K)
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_XTAL32K) /* Check 32K XTAL not on yet (1 means off in PDRUNCFG0)*/
        {
            PMC->PDRUNCFGCLR0 = powerConfigBit;
            DelayMs(s_xtalStartupTime); /* Delay configurable with API, in case customer uses different XTAL
                                                      configuration. */
        }
    }
    if (powerConfigBit & kPOWERCFG_FRO32K)
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_FRO32K) /* Check 32K FRO not on yet (1 means off in PDRUNCFG0)*/
        {
            PMC->PDRUNCFGCLR0 = powerConfigBit;
            DelayMs(DEFAULT_FRO_STARTUP_DELAY_MS); /* Delay NOT configurable with API, we assume FRO startup not to
                                                          vary too much. */
        }
    }
    else if(powerConfigBit & kPOWERCFG_BLE) /* Check 32MHz XTAL not on yet(1 means off in PDRUNCFG0)*/
    {
        if (PMC->PDRUNCFG0 & kPOWERCFG_BLE)
        {
            PMC->PDRUNCFGCLR0 = powerConfigBit;
            /* Wait until 32 MHz xtal osc is active*/
            while ((PMC_BLE_STATE != PMC_BLE_STATE_ENABLE_CLOCK_OUT) && (PMC_BLE_STATE != PMC_BLE_STATE_RADIO_ACTIVE))
            {
            }
        }
    }
    else
    {
        PMC->PDRUNCFGCLR0 = powerConfigBit;
    }
}

/**
 * @brief Disable SRAM segments
 * @param sramCtrl Bitmask of SRAM segments to disable
 */
void POWER_DisableSRAM(uint32_t sramCtrl)
{
    if (sramCtrl & kSRAM_CTRL_RAMX0)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX0_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX1)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX1_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX2)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX2_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX3)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX3_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM00)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM00_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM10)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM10_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM20)
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM20_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMBLEDATA)
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
        {
            uint32_t pmcSramCtrl1 = PMC->SRAMCTRL1;
            pmcSramCtrl1 &= ~PMC_SRAMCTRL1_RAMBLEDATA_MASK;
            pmcSramCtrl1 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT);
            PMC->SRAMCTRL1 = pmcSramCtrl1;
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMBLESEQL)
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) !=
            (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
        {
            uint32_t pmcSramCtrl1 = PMC->SRAMCTRL1;
            pmcSramCtrl1 &= ~PMC_SRAMCTRL1_RAMBLESEQL_MASK;
            pmcSramCtrl1 |= (PMC_SRAMCTRL0_SHUTDOWN_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT);
            PMC->SRAMCTRL1 = pmcSramCtrl1;
        }
    }
}

/**
 * @brief Enable SRAM segments
 * @param sramCtrl Bitmask of SRAM segments to enable
 */
void POWER_EnableSRAM(uint32_t sramCtrl)
{
    if (sramCtrl & kSRAM_CTRL_RAMX0) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX0_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(1); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX1) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX1_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(1); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX2) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX2_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(1); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMX3) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAMX3_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(1); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM00) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM00_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(4); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM10) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM10_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(6); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAM20) /* ON */
    {
        if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
        {
            uint32_t pmcSramCtrl0 = PMC->SRAMCTRL0;
            pmcSramCtrl0 &= ~PMC_SRAMCTRL0_RAM20_MASK;
            pmcSramCtrl0 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT);
            PMC->SRAMCTRL0 = pmcSramCtrl0;
            DelayUs(12); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMBLEDATA) /* ON */
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) !=
            (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
        {
            uint32_t pmcSramCtrl1 = PMC->SRAMCTRL1;
            pmcSramCtrl1 &= ~PMC_SRAMCTRL1_RAMBLEDATA_MASK;
            pmcSramCtrl1 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT);
            PMC->SRAMCTRL1 = pmcSramCtrl1;
            DelayUs(4); /* Wait until SRAM ready to be used */
        }
    }

    if (sramCtrl & kSRAM_CTRL_RAMBLESEQL) /* ON */
    {
        if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) !=
            (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
        {
            uint32_t pmcSramCtrl1 = PMC->SRAMCTRL1;
            pmcSramCtrl1 &= ~PMC_SRAMCTRL1_RAMBLESEQL_MASK;
            pmcSramCtrl1 |= (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT);
            PMC->SRAMCTRL1 = pmcSramCtrl1;
            DelayUs(1); /* Wait until SRAM ready to be used */
        }
    }
}

/**
 * @brief Get current SRAM configuration
 * @return Bitmask of enabled SRAM segments
 */
uint32_t POWER_GetSRAMConfig(void)
{
    uint32_t sramCtrl = 0;

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX0_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX0_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMX0;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX1_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX1_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMX1;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX2_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX2_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMX2;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAMX3_MASK) != (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAMX3_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMX3;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM00_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM00_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAM00;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM10_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM10_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAM10;
    }

    if ((PMC->SRAMCTRL0 & PMC_SRAMCTRL0_RAM20_MASK) == (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL0_RAM20_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAM20;
    }

    if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLEDATA_MASK) ==
        (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLEDATA_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMBLEDATA;
    }

    if ((PMC->SRAMCTRL1 & PMC_SRAMCTRL1_RAMBLESEQL_MASK) ==
        (PMC_SRAMCTRL0_NORMAL_MODE << PMC_SRAMCTRL1_RAMBLESEQL_LS_SHIFT))
    {
        sramCtrl |= kSRAM_CTRL_RAMBLESEQL;
    }
    return sramCtrl;
}

/**
 * @brief Enter sleep mode
 * 
 * Stops CPU but continues execution after wakeup
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
 * @brief Enter deep sleep mode
 * @param excludeFromPd Bitmask of peripherals to keep powered
 * @param wakeupInterrupts Bitmask of interrupts that can wake the system
 * @return Status of operation
 */
status_t POWER_EnterDeepSleep(uint32_t excludeFromPd, uint64_t wakeupInterrupts)
{
    uint32_t cpu0NmiEnable;
    uint32_t cpu0IntEnable0;
    uint32_t cpu0IntEnable1;
    uint32_t restoreClockSettings = 0;
    uint32_t flashReadWaitStates;
    uint32_t coreSysClkConfiguration;

    /* Validate input. */
    /* Only the following peripherals can be excluded from power down */
    if (excludeFromPd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPSLEEP)
    {
        return kStatus_InvalidArgument;
    }
    /* kLOWPOWERCFG_BLE_WUP may only be set when either kLOWPOWERCFG_FRO32K or kLOWPOWERCFG_XTAL32K is set. */
    if (excludeFromPd & kLOWPOWERCFG_BLE_WUP)
    {
        if (!(excludeFromPd & (kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K)))
        {
            return kStatus_InvalidArgument;
        }
    }
    /* FRO192M may only be set when HFDSM is set. */
    if (excludeFromPd & kLOWPOWERCFG_FRO192M)
    {
        if (!(excludeFromPd & kLOWPOWERCFG_HFDSM))
        {
            return kStatus_InvalidArgument;
        }
    }

    /* BOD resets: when enabled, BOD should stay powered. */
    uint32_t pmcResetCtrl = PMC->RESETCTRL;
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    /* No CTIMER and UTICK at 1MHz during DEEPSLEEP with LDO_DIG = 0.6x V. */
    if (!(excludeFromPd & kLOWPOWERCFG_HFDSM)) // not 1V mode
    {
        if (excludeFromPd & kLOWPOWERCFG_FRO1M) // FRO1M enables
        {
            if (SYSCON->AHBCLKCTRL.AHBCLKCTRL1 & SYSCON_AHBCLKCTRL1_UTICK_MASK) // UTICK is always connected to FRO1M
            {
                return kStatus_InvalidArgument;
            }
            /* CTIMER can be connected directly to FRO1M, or via main clock direct to FRO1M */
            if (((SYSCON->CTIMERCLKSELX[0] & SYSCON_CTIMERCLKSEL0_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[1] & SYSCON_CTIMERCLKSEL1_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[2] & SYSCON_CTIMERCLKSEL2_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[3] & SYSCON_CTIMERCLKSEL3_SEL_MASK) == 4) |
                ((SYSCON->CTIMERCLKSELX[4] & SYSCON_CTIMERCLKSEL4_SEL_MASK) == 4))
            {
                return kStatus_InvalidArgument;
            }
            if (((SYSCON->MAINCLKSELA & SYSCON_MAINCLKSELA_SEL_MASK) == 2) &&
                ((SYSCON->MAINCLKSELB & SYSCON_MAINCLKSELB_SEL_MASK) == 0))
            {
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

    status_t status = SetPowerConfiguration(kLP_MODE_DEEPSLEEP, &excludeFromPd);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Mask all sleepcfg0 register bits. */
    uint32_t pmcSleepcfg0 = ~(excludeFromPd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_CORE_MASK; /* Keep core enabled */
    pmcSleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK | PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK); /* Keep ldo's enabled */

    /* Check High Frequency Deep Sleep Mode - set LDO DIG voltage */
    uint32_t pmcLdoDig = PMC->LDODIG;
    pmcLdoDig &= ~PMC_LDODIG_VADJ_PWD_MASK;
    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK;  /* Clear bias bits */
    if (excludeFromPd & kLOWPOWERCFG_HFDSM)
    {
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63;
        pmcSleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK);
    }
    else
    {
        pmcLdoDig |= PMC_LDODIG_VADJ_PWD_MASK;
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63; 
    }
    PMC->LDODIG = pmcLdoDig;

    /* Check if link layer retention is enabled */
    if (excludeFromPd & kLOWPOWERCFG_BLE_WUP)
    {
        pmcSleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_BLE_MASK);
    }

    /* Lower System Clock to FRO12Mhz if necessary */
    if (((SYSCON->MAINCLKSELA == MAINCLKSELA_FRO_12MHz) && (SYSCON->MAINCLKSELB == MAINCLKSELB_MAINCLKAOUT)) ||
        ((SYSCON->MAINCLKSELA == MAINCLKSELA_FRO_1MHz) && (SYSCON->MAINCLKSELB == MAINCLKSELB_MAINCLKAOUT)) ||
        (SYSCON->MAINCLKSELB == MAINCLKSELB_32K_OSC) || (SYSCON->MAINCLKSELB == MAINCLKSELB_32K_OSC_ALTERNATE_VALUE1))
    {
    }
    else
    {
        /* Switch System Clock to FRO12Mhz(the configuration before calling this function will be restored back) */
        flashReadWaitStates        = CLOCK_GetFLASHAccessCycles();
        coreSysClkConfiguration = GetCoreSysClkConfiguration();
        CLOCK_SetupFROClocking(kFreq_12MHz);
        CLOCK_SetFLASHAccessCyclesForFreq(
            kFreq_12MHz);
        restoreClockSettings = 1;
    }

    /* Set excluded peripherals */
    PMC->PDSLEEPCFG0 = pmcSleepcfg0;

    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_DEEPSLEEP << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    cpu0NmiEnable = SYSCON->NMISRC & SYSCON_NMISRC_NMIENCPU0_MASK; /* Save the configuration of the NMI Register */
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
    cpu0IntEnable0 = NVIC->ISER[0];
    cpu0IntEnable1 = NVIC->ISER[1];

    NVIC->ISER[0] = (uint32_t)(wakeupInterrupts & 0xFFFFFFFF);
    NVIC->ISER[1] = (uint32_t)((wakeupInterrupts >> 32) & 0xFFFFFFFF);

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = (uint32_t)(wakeupInterrupts & 0xFFFFFFFF);
    SYSCON->STARTER[1] = (uint32_t)((wakeupInterrupts >> 32) & 0xFFFFFFFF);

    uint32_t savedPrimask = 0;

    /* Make sure DEEP POWER DOWN reset is disabled else DeepSleep will reset iso. continue */
    PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

    /* Disable all IRQs */
    savedPrimask = DisableGlobalIRQ();

    /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
    POWER_PowerCycleCpuAndFlash();

    if (restoreClockSettings == 1)
    {
        CLOCK_SetFLASHAccessCycles(
            flashReadWaitStates);
        SetCoreSysClkConfiguration(coreSysClkConfiguration);
    }

    /* Enable all interrupts */
    EnableGlobalIRQ(savedPrimask);

    /* Restore ACTIVE mode to allow using normal WFI again */
    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_ACTIVE << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    /* Restore the configuration of the NMI Register */
    SYSCON->NMISRC |= cpu0NmiEnable;

    /* Restore the configuration of the CPU interrupt enable Registers */
    NVIC->ISER[0] = cpu0IntEnable0;
    NVIC->ISER[1] = cpu0IntEnable1;

    return kStatus_Success;
}

/**
 * @brief Enter power down mode
 * @param excludeFromPd Bitmask of peripherals to keep powered
 * @param wakeupInterrupts Bitmask of interrupts that can wake the system
 * @param cpuRetentionCtrl CPU retention control flag
 * @return Status of operation
 */
status_t POWER_EnterPowerDown(uint32_t excludeFromPd, uint64_t wakeupInterrupts, uint32_t cpuRetentionCtrl)
{
    uint32_t cpu0NmiEnable;
    uint32_t cpu0IntEnable0;
    uint32_t cpu0IntEnable1;
    uint32_t anactrlBodDcdcIntCtrl;

    /* Validate input. */
    /* Only the following peripherals can be excluded from power down */
    if (excludeFromPd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_POWERDOWN)
    {
        return kStatus_InvalidArgument;
    }
    /* kLOWPOWERCFG_BLE_WUP may only be set when either kLOWPOWERCFG_FRO32K or kLOWPOWERCFG_XTAL32K is set. */
    if (excludeFromPd & kLOWPOWERCFG_BLE_WUP)
    {
        if (!(excludeFromPd & (kLOWPOWERCFG_FRO32K | kLOWPOWERCFG_XTAL32K)))
        {
            return kStatus_InvalidArgument;
        }
    }

    /* BOD resets: when enabled, BOD should stay powered. */
    uint32_t pmcResetCtrl = PMC->RESETCTRL;
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    if (wakeupInterrupts & ~(kWAKEUP_GINT0 | kWAKEUP_FLEXCOMM0 | kWAKEUP_BLE_SLP_TMR | kWAKEUP_RTC |
                              kWAKEUP_OS_EVENT /* | wakeup pin as gpio */))
    {
        return kStatus_InvalidArgument;
    }

    status_t status = SetPowerConfiguration(kLP_MODE_POWERDOWN, &excludeFromPd);
    if (status != kStatus_Success)
    {
        return status;
    }

    uint32_t pmcSleepcfg0 = ~(excludeFromPd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK; /* Clear bias bits */
    if (excludeFromPd & (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2))
    {
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63;
    }
    else
    {
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_66;
    }

    PMC->LDODIG |= PMC_LDODIG_VADJ_PWD_MASK;

    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_LDOMEM_MASK;
    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_LDODIG_MASK;

    /* Check if link layer retention is enabled */
    if (excludeFromPd & kLOWPOWERCFG_BLE_WUP)
    {
        pmcSleepcfg0 &= ~(PMC_PDSLEEPCFG0_PDEN_BLE_MASK);
    }

    /* CPU retention control */
    SYSCON->FUNCRETENTIONCTRL &=
        (~(SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK | SYSCON_FUNCRETENTIONCTRL_RET_START_MASK));
    if (cpuRetentionCtrl)
    {
        SYSCON->FUNCRETENTIONCTRL |=
            (SYSCON_FUNCRETENTIONCTRL_FUNCRETENA_MASK |
             (((CPU_RETENTION_RAMX_STORAGE_START_ADDR >> 2) << SYSCON_FUNCRETENTIONCTRL_RET_START_SHIFT) &
              SYSCON_FUNCRETENTIONCTRL_RET_START_MASK));
        SavePinRegisters();
    }
    /* Switch System Clock to FRO12Mhz (the configuration before calling this function will be restored back) */
    uint32_t flashReadWaitStates        = CLOCK_GetFLASHAccessCycles();
    uint32_t coreSysClkConfiguration = GetCoreSysClkConfiguration();

    CLOCK_SetupFROClocking(kFreq_12MHz);
    CLOCK_SetFLASHAccessCyclesForFreq(
        kFreq_12MHz);

    /* Set excluded peripherals */
    PMC->PDSLEEPCFG0 = pmcSleepcfg0;

    PMC->CTRL = (LOWPOWER_CTRL_LPMODE_POWERDOWN << PMC_CTRL_LPMODE_SHIFT) |
                (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_OFF << PMC_CTRL_POFFMODE_SHIFT);

    cpu0NmiEnable = SYSCON->NMISRC & SYSCON_NMISRC_NMIENCPU0_MASK; /* Save the configuration of the NMI Register */
    SYSCON->NMISRC &= ~SYSCON_NMISRC_NMIENCPU0_MASK;                 /* Disable NMI of CPU0 */

    /*
     * Enable wake up interrupt.
     * Rational : we enable each interrupt (NVIC->ISER) that can wake up the CPU here (before the __disable_irq()
     * below): Hence, if an interrupt was pending and not treated before (for any reason), the CPU will jump to that
     *            interrupt handler before trying to enter the low power mode.
     *            VERY IMPORTANT : Also, any interrupt set in NVIC->ISER, even though __disable_irq(), will make the CPU
     *                             go out of the Deep Sleep mode.
     */
    uint32_t interruptEnables0 = (uint32_t)(wakeupInterrupts & 0xFFFFFFFF);
    uint32_t interruptEnables1 = (uint32_t)((wakeupInterrupts >> 32) & 0xFFFFFFFF);
    uint32_t wakeupSources0    = interruptEnables0;
    uint32_t wakeupSources1    = interruptEnables1;

    if (cpuRetentionCtrl)
    {
        if (wakeupInterrupts & kWAKEUP_BLE_SLP_TMR)
        {
            /* Replace sleep timer irq (23) by wakeup state transition irq (31)
            and clear interrupt request flag to prevent isr execution at wakeup. */
            ANACTRL->BLE_CTRL = ANACTRL_BLE_CTRL_BLE_DST_INT_CLR_MASK;
            interruptEnables0 &= ~kWAKEUP_BLE_SLP_TMR; /* Disable IRQ */
            interruptEnables0 |= kWAKEUP_WAKE_DSLP; /* Replace by state transition irq */
        }
        PMC->RESETCAUSE = PMC->RESETCAUSE; /* Clear reset cause */
    }

    /* Save the configuration of the CPU interrupt set enable Registers */
    cpu0IntEnable0 = NVIC->ISER[0];
    cpu0IntEnable1 = NVIC->ISER[1];

    NVIC->ISER[0] = interruptEnables0;
    NVIC->ISER[1] = interruptEnables1;

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = wakeupSources0;
    SYSCON->STARTER[1] = wakeupSources1;

    uint32_t savedPrimask = 0;

    /* Make sure DEEP POWER DOWN reset is disabled else PowerDown with cpu retention will still reset */
    PMC->RESETCTRL &= (~PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK);

    /* Disable all IRQs */
    savedPrimask = DisableGlobalIRQ();

    /*
     * From here :
     *  1 - If an interrupt that is enable occurs,
     *      the _WFI instruction will not be executed and we won't enter in POWER DOWN.
     *  2 - If an interrupt that is not enable occurs, there is no consequence neither
     *      on the execution of the low power mode nor on the behaviour of the CPU.
     */

    /* Store BOD interrupt enables to be able to restore them later. */
    anactrlBodDcdcIntCtrl = ANACTRL->BOD_DCDC_INT_CTRL;

    /* Disable the Flash, execute _WFI() instruction then enable the Flash after wake up event */
    POWER_PowerCycleCpuAndFlash();

    /* Only clearing the bit is required as the PMC must have kept its state. */
    PMC->DCDC0 &= ~PMC_DCDC0_ENABLE_BYPASS_MASK;

    /*
     * We can reach this point for 2 reasons:
     * 1 - We are coming out from POWER DOWN mode with CPU state retention. Assumption is that the SRAM
     *     containing the stack used to call this function shall be preserved during low power.
     * 2 - We didn't enter the POWER DOWN mode because a wake up interrupt popped up just
     *     before entering the POWER DOWN mode (as a consequence, the WFI() has been ignored)
     */

    CLOCK_SetFLASHAccessCycles(
        flashReadWaitStates);
    SetCoreSysClkConfiguration(coreSysClkConfiguration);

    if (cpuRetentionCtrl)
    {
        /* Pin registers are lost after PD with cpu retention */
        RestorePinRegisters();
    }

    /* Enable all interrupts */
    EnableGlobalIRQ(savedPrimask);

    /* Restore ACTIVE mode to allow using normal WFI again */
    PMC->CTRL = (PMC->CTRL & (~PMC_CTRL_LPMODE_MASK)) | (LOWPOWER_CTRL_LPMODE_ACTIVE << PMC_CTRL_LPMODE_SHIFT);

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
    /* Delaying the line of code below until the PUF State Machine execution is completed:
       Shutting down the clock too early will prevent the state machine from reaching the end.
       => Wait for status bit in PUF Controller Registers before stop PUF clock.*/
    while (!(PUF_SRAM_CTRL->INT_STATUS & PUF_SRAM_CTRL_INT_STATUS_READY_MASK))
        ;
    SYSCON->AHBCLKCTRLCLR[2] = SYSCON_AHBCLKCTRL2_PUF_MASK;

    /* Restore the configuration of the NMI Register */
    SYSCON->NMISRC |= cpu0NmiEnable;

    /* Restore the configuration of the CPU interrupt enable Registers (because they have been overwritten inside the
     * low power API */
    NVIC->ISER[0] = cpu0IntEnable0;
    NVIC->ISER[1] = cpu0IntEnable1;

    /* Restore BOD interrupt enables. */
    ANACTRL->BOD_DCDC_INT_CTRL = anactrlBodDcdcIntCtrl;

    return kStatus_Success;
}

/**
 * @brief Enter deep power down mode
 * @param excludeFromPd Bitmask of peripherals to keep powered
 * @param wakeupInterrupts Bitmask of interrupts that can wake the system
 * @param wakeupIoCtrl Wakeup I/O control configuration
 * @return Status of operation
 */
status_t POWER_EnterDeepPowerDown(uint32_t excludeFromPd, uint64_t wakeupInterrupts, uint32_t wakeupIoCtrl)
{
    /* Validate input. */
    /* Only the following peripherals can be excluded from deep power down: */
    if (excludeFromPd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_DEEPPOWERDOWN)
    {
        return kStatus_InvalidArgument;
    }
    /* BOD resets: when enabled, BOD should stay powered */
    uint32_t pmcResetCtrl = PMC->RESETCTRL;
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD1RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD1))
        {
            return kStatus_InvalidArgument;
        }
    }
    if (((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_MASK) != 2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_SHIFT) ||
        ((pmcResetCtrl & PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_MASK) !=
         2U << PMC_RESETCTRL_BOD2RESETENA_SECURE_DP_SHIFT))
    {
        if (!(excludeFromPd & kLOWPOWERCFG_BOD2))
        {
            return kStatus_InvalidArgument;
        }
    }

    if (wakeupInterrupts & ~(kWAKEUP_RTC | kWAKEUP_OS_EVENT | kWAKEUP_WAKE_PAD))
    {
        return kStatus_InvalidArgument;
    }

    status_t status = SetPowerConfiguration(kLP_MODE_DEEPPOWERDOWN, &excludeFromPd);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (wakeupInterrupts == kWAKEUP_RTC)
    {
        RTC->CTRL |=
            RTC_CTRL_WAKEDPD_EN_MASK;
    }

    uint32_t pmcSleepcfg0 = ~(excludeFromPd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    pmcSleepcfg0 &= ~PMC_PDSLEEPCFG0_PDEN_BIAS_MASK; /* Clear bias bits */
    if (excludeFromPd & (kLOWPOWERCFG_DCDC | kLOWPOWERCFG_BOD1 | kLOWPOWERCFG_BOD2))
    {
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_0_63;
        PMC->LDODIG |= PMC_LDODIG_VADJ_PWD_MASK;
    }
    else
    {
        pmcSleepcfg0 |= PMC_PDSLEEPCFG0_PDEN_BIAS_DISABLED;
    }

    /* Switch System Clock to FRO12Mhz */
    CLOCK_SetupFROClocking(kFreq_12MHz);
    CLOCK_SetFLASHAccessCyclesForFreq(
        kFreq_12MHz);

    /* Set excluded peripherals */
    PMC->PDSLEEPCFG0 = pmcSleepcfg0;

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
    NVIC->ISER[0] = (uint32_t)(wakeupInterrupts & 0xFFFFFFFF);
    NVIC->ISER[1] = (uint32_t)((wakeupInterrupts >> 32) & 0xFFFFFFFF);

    /* Exception for OSTIMER */
    if (wakeupInterrupts & kWAKEUP_OS_EVENT)
    {
        PMC->OSTIMERr |= PMC_OSTIMER_DPDWAKEUPENABLE_MASK;
        wakeupInterrupts &= ~kWAKEUP_OS_EVENT;
    }

    /* Enable wake-up sources */
    SYSCON->STARTER[0] = (uint32_t)(wakeupInterrupts & 0xFFFFFFFF);
    SYSCON->STARTER[1] = (uint32_t)((wakeupInterrupts >> 32) & 0xFFFFFFFF);

    /* Configure wake-up by I/O */
    PMC->WAKEUPIOCTRL =
        wakeupIoCtrl |
        PMC_WAKEUPIOCTRL_WAKEUPIO_RSTN_MASK; /* include RSTN to generate WAKEIOCAUSE being set in RESETCAUSE reg */

    /* Enable DEEP POWER DOWN reset */
    PMC->RESETCTRL |= PMC_RESETCTRL_DPDWAKEUPRESETENABLE_MASK;

    POWER_PowerCycleCpuAndFlash();

    /* Should never come here (due to reboot) after wakeup */
    return kStatus_Success;
}

/**
 * @brief Enter power off mode
 * @param excludeFromPd Bitmask of peripherals to keep powered
 * @param wakeupIoCtrl Wakeup I/O control configuration
 * @return Status of operation
 */
status_t POWER_EnterPowerOff(uint32_t excludeFromPd, uint32_t wakeupIoCtrl)
{
    /* Validate input. */
    /* Only the following peripherals can be excluded from power off: */
    if (excludeFromPd & ~kEXCLUDE_FROM_PD_LIMITATION_MASK_POWEROFF)
    {
        return kStatus_InvalidArgument;
    }

    status_t status = SetPowerConfiguration(kLP_MODE_POWEROFF, &excludeFromPd);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Set excluded peripherals */
    uint32_t pmcSleepcfg0 = ~(excludeFromPd & EXCLUDE_FROM_PD_TO_SLEEPCFG0_MASK);

    PMC->PDSLEEPCFG0 = pmcSleepcfg0;

    SYSCON->NMISRC &= ~SYSCON_NMISRC_NMIENCPU0_MASK; /* Disable NMI of CPU0 */

    PMC->CTRL = (LOWPOWER_CTRL_SELCLOCK_1MHZ << PMC_CTRL_SELCLOCK_SHIFT) |
                (LOWPOWER_CTRL_POFFMODE_ON << PMC_CTRL_POFFMODE_SHIFT);

    /* Configure wake-up by I/O */
    PMC->WAKEUPIOCTRL = wakeupIoCtrl;

    POWER_PowerCycleCpuAndFlash();

    return kStatus_Success; /* Never comes here */
}

/**
 * @brief Get current DCDC supply mode
 * @return Current supply mode
 */
dcdc_mode_t POWER_DCDC_GetSupplyMode(void)
{
    dcdc_mode_t mode;
    uint32_t aoreg1 = PMC->AOREG1;

    if (aoreg1 & AOREG1_DCDC_MODE_XR_SM_SS_MASK)
    {
        mode = kDCDC_MODE_XR_SM_SS;
    }
    else if (aoreg1 & AOREG1_DCDC_MODE_XR_SM_DS_MASK)
    {
        mode = kDCDC_MODE_XR_SM_DS;
    }
    else
    {
        /* Relies on match between dcdc_mode_t and dcdc_hw_mode_t */
        mode = (dcdc_mode_t)((PMC->STATUSPWR & PMC_STATUSPWR_DCDCMODE_MASK) >> PMC_STATUSPWR_DCDCMODE_SHIFT);
    }
    return mode;
}

/**
 * @brief Set DCDC supply mode
 * @param mode Supply mode to set
 * @return Status of operation
 */
status_t POWER_DCDC_SetSupplyMode(dcdc_mode_t mode)
{
    status_t status = kStatus_Success;
    dcdc_hw_mode_t hwDcdcMode =
        (dcdc_hw_mode_t)((PMC->STATUSPWR & PMC_STATUSPWR_DCDCMODE_MASK) >> PMC_STATUSPWR_DCDCMODE_SHIFT);
    chip_version_t version = SYSTEM_GetChipVersion();

    if (mode == kDCDC_MODE_HV_SM)
    {
        /* Buck (HV), supported on MCXW23xB */
        if (version == kCHIPVERSION_A3 || version == kCHIPVERSION_A4)
        {
            /* Check if reported HW PMC mode matches with inputs*/
            if (hwDcdcMode != kDCDC_HW_MODE_HV_SM)
            {
                return kStatus_Power_SupplyModeModeInvalid;
            }
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* Boost (LV), supported on MCXW23xA */
    else if (mode == kDCDC_MODE_LV_SM)
    {
        if (version == kCHIPVERSION_A5)
        {
            if (hwDcdcMode != kDCDC_HW_MODE_LV_SM)
            {
                return kStatus_Power_SupplyModeModeInvalid;
            }
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* External regulated single supply (XRSM SM), supported on MCXW23xB */
    else if (mode == kDCDC_MODE_XR_SM_SS)
    {
        if (version == kCHIPVERSION_A3 || version == kCHIPVERSION_A4)
        {
            /* disable DCDC */
            POWER_DCDC_Disable();
            PMC->AOREG1 |= AOREG1_DCDC_MODE_XR_SM_SS_MASK; /* Register reset on POR, BOD, to be set only once */
        }
        else
        {
            return kStatus_Power_SupplyModeModeNotSupported;
        }
    }
    /* External regulated dual supply (XRSM DM), supported on MCXW23xB */
    else if (mode == kDCDC_MODE_XR_SM_DS)
    {
        if (version == kCHIPVERSION_A3 || version == kCHIPVERSION_A4)
        {
            if (version == kCHIPVERSION_A4)
            {
                /* disable DCDC */
                POWER_DCDC_Disable();
            }
            PMC->AOREG1 |= AOREG1_DCDC_MODE_XR_SM_DS_MASK; /* Register reset on POR, BOD, to be set only once */
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

/**
 * @brief Disable DCDC converter. When the device is using an external supply mode, the DC/DC convertor
 * should be disabled. When supply mode is kDCDC_MODE_LV_SM , the DC/DC can be disabled but the flash subsystem can't be
 * used. All code needs to run from RAM. When supply mode is kDCDC_MODE_HV_SM , the DCDC can't be disabled.
 */
void POWER_DCDC_Disable(void)
{
    POWER_PeripheralPowerOff(kPOWERCFG_DCDC);
}

/**
 * @brief Enable DCDC converter
 */
void POWER_DCDC_Enable(void)
{
    POWER_PeripheralPowerOn(kPOWERCFG_DCDC);
}

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in buck mode.
 * @pre Can only be used supply mode kDCDC_MODE_HV_SM is used.
 * @param outputLvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBuckOutput(dcdc_buck_output_level_t outputLvl)
{
    PMC->DCDC0 = (PMC->DCDC0 & ~PMC_DCDC0_VOLTAGE_MASK) | outputLvl << PMC_DCDC0_VOLTAGE_SHIFT;
}

/*!
 * @brief Function to configure output level of DC/DC convertor when configured in boost mode.
 * @pre Can only be used supply mode kDCDC_MODE_LV_SM is used.
 * @param outputLvl    The output level of the DC/DC convertor.
 */
void POWER_DCDC_ConfigureBoostOutput(dcdc_boost_output_level_t outputLvl)
{
    PMC->DCDC0 = (PMC->DCDC0 & ~PMC_DCDC0_VOLTAGE_MASK) | outputLvl << PMC_DCDC0_VOLTAGE_SHIFT;
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

/**
 * @brief Get power library version
 * @return Version number of the power library
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
    /* The BOD mode does not work as expected and the accuracy of the threshold is not good enough.
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
    /* The BOD mode does not work as expected and the accuracy of the threshold is not good enough.
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
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD1_INT_CLEAR_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
}

/*!
 * @brief Function to clear the BOD2 interrupt. It does not
 *        clear the interrupt in the NVIC.
 */
void POWER_ClearBOD2Interrupt(void)
{
    uint32_t intCtrl = ANACTRL->BOD_DCDC_INT_CTRL;
    intCtrl |= ANACTRL_BOD_DCDC_INT_CTRL_BOD2_INT_CLEAR_MASK;
    ANACTRL->BOD_DCDC_INT_CTRL = intCtrl;
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
    return (reset_cause_t)((PMC->AOREG1 >> 4) & 0xfff);
}

/**
 * @brief Configure 32K XTAL capacitors
 * @param capIn Input capacitor setting
 * @param capOut Output capacitor setting
 */
void POWER_XTAL32K_ConfigureCaps(uint8_t capIn, uint8_t capOut)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_CAP_OSCIN_MASK | PMC_XTAL32K_CAP_OSCOUT_MASK);
    val |= ((uint32_t)capIn << PMC_XTAL32K_CAP_OSCIN_SHIFT) | ((uint32_t)capOut << PMC_XTAL32K_CAP_OSCOUT_SHIFT);
    PMC->XTAL32K = val;
}

/**
 * @brief Configure 32K XTAL reference output current
 * @param gm Transconductance setting
 */
void POWER_XTAL32K_ConfigureReferenceOutputCurrent(uint8_t gm)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_GM_MASK);
    val |= ((uint32_t)gm << PMC_XTAL32K_GM_SHIFT);
    PMC->XTAL32K = val;
}

/**
 * @brief Configure 32K XTAL oscillator amplitude
 * @param ampl Amplitude setting
 */
void POWER_XTAL32K_ConfigureOscillatorAmplitude(uint8_t ampl)
{
    uint32_t val = PMC->XTAL32K;
    val &= ~(PMC_XTAL32K_AMPL_MASK);
    val |= ((uint32_t)ampl << PMC_XTAL32K_AMPL_SHIFT);
    PMC->XTAL32K = val;
}

/**
 * @brief Enable/disable 32K XTAL bypass mode
 * @param enable true to enable bypass, false to disable
 */
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

/**
 * @brief Enable/disable BLE clock gating for 32M XTAL
 * @param enable true to enable, false to disable
 */
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

/**
 * @brief Set 32M XTAL startup time
 * @param startupTime Startup time setting (1-15)
 * @return Status of operation
 */
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
