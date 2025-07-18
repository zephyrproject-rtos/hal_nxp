/*
 * Copyright 2020-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 *@defgroup clock Clock Driver
 *@details
 *
 * The clock module is used to help software to configure the MCU OCCS and relevant field in SIM module,
 * to provide proper clock to MCU core and its peripherals.
 *
 * @{
 */

/*******************************************************************************
 * Driver Change Log
 ******************************************************************************/
/*!
 * @defgroup clock_driver_log Driver Change Log
 * @ingroup clock
 * @{
 * Current CLOCK driver version is 2.1.0
 *
 * - 2.1.0
 *   - Accumulated bug fix
 *   - MISRA warning fix
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Configurations
 ******************************************************************************/

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0
#endif

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.1.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

/*! Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (100000000UL)
#endif

/*! @brief List of IP clock name. */
typedef enum _clock_ip_name
{
    /* SIM_PCE0 */
    kCLOCK_GPIOG = 0U,  /*!< GPIOG clock */
    kCLOCK_GPIOF = 1U,  /*!< GPIOF clock */
    kCLOCK_GPIOE = 2U,  /*!< GPIOE clock */
    kCLOCK_GPIOD = 3U,  /*!< GPIOD clock */
    kCLOCK_GPIOC = 4U,  /*!< GPIOC clock */
    kCLOCK_GPIOB = 5U,  /*!< GPIOB clock */
    kCLOCK_GPIOA = 6U,  /*!< GPIOA clock */
    kCLOCK_TB3   = 8U,  /*!< Timer B3 clock */
    kCLOCK_TB2   = 9U,  /*!< Timer B2 clock */
    kCLOCK_TB1   = 10U, /*!< Timer B1 clock */
    kCLOCK_TB0   = 11U, /*!< Timer B0 clock */
    kCLOCK_TA3   = 12U, /*!< Timer A3 clock */
    kCLOCK_TA2   = 13U, /*!< Timer A2 clock */
    kCLOCK_TA1   = 14U, /*!< Timer A1 clock */
    kCLOCK_TA0   = 15U, /*!< Timer A0 clock */

    /* SIM_PCE1 */
    kCLOCK_FLEXCAN = 16U, /*!< Flex CAN clock */
    kCLOCK_I2C1    = 21U, /*!< I2C1 clock */
    kCLOCK_I2C0    = 22U, /*!< I2C0 clock */
    kCLOCK_QSPI1   = 24U, /*!< QSPI1 clock */
    kCLOCK_QSPI0   = 25U, /*!< QSPI0 clock */
    kCLOCK_QSCI2   = 26U, /*!< QSCI2 clock */
    kCLOCK_QSCI1   = 27U, /*!< QSCI1 clock */
    kCLOCK_QSCI0   = 28U, /*!< QSCI0 clock */
    kCLOCK_DACA    = 29U, /*!< DAC A clock */
    kCLOCK_DACB    = 30U, /*!< DAC B clock */

    /* SIM_PCE2 */
    kCLOCK_PIT1   = 34U, /*!< PIT 1 clock */
    kCLOCK_PIT0   = 35U, /*!< PIT 0 clock */
    kCLOCK_CRC    = 37U, /*!< CRC clock */
    kCLOCK_CYCADC = 39U, /*!< Cyclic ADC clock */
    kCLOCK_CMPD   = 41U, /*!< Comparator D clock */
    kCLOCK_CMPC   = 42U, /*!< Comparator C clock */
    kCLOCK_CMPB   = 43U, /*!< Comparator B clock */
    kCLOCK_CMPA   = 44U, /*!< Comparator A clock */

    /* SIM_PCE3 */
    kCLOCK_PWMBCH3 = 48U, /*!< Enhanced Flexible PWM B3 clock */
    kCLOCK_PWMBCH2 = 49U, /*!< Enhanced Flexible PWM B2 clock */
    kCLOCK_PWMBCH1 = 50U, /*!< Enhanced Flexible PWM B1 clock */
    kCLOCK_PWMBCH0 = 51U, /*!< Enhanced Flexible PWM B0 clock */
    kCLOCK_PWMACH3 = 52U, /*!< Enhanced Flexible PWM A3 clock */
    kCLOCK_PWMACH2 = 53U, /*!< Enhanced Flexible PWM A2 clock */
    kCLOCK_PWMACH1 = 54U, /*!< Enhanced Flexible PWM A1 clock */
    kCLOCK_PWMACH0 = 55U, /*!< Enhanced Flexible PWM A0 clock */
    kCLOCK_USB     = 56U, /*!< USB clock */
    kCLOCK_ROM     = 57U, /*!< ROM clock */

    /* total number of IP clock */
    kCLOCK_NOGATE = 58U, /*!< No clock gate for the IP */
    kCLOCK_EDMA   = kCLOCK_NOGATE,
    kCLOCK_EWM    = kCLOCK_NOGATE,
    kCLOCK_XBARA  = kCLOCK_NOGATE,
    kCLOCK_NUM    = 59U /*!< Total IP clock number */
} clock_ip_name_t;

/*! @brief List of system-level clock name. */
typedef enum _clock_name
{
    /*----------------------------- System layer clock -------------------------------*/
    kCLOCK_Mstr2xClk = 0, /*!< Master 2x clock which feed to core and peripheral */
    kCLOCK_SysClk    = 1, /*!< MCU system/core clock */
    kCLOCK_BusClk    = 2, /*!< Bus clock */
    kCLOCK_Bus2xClk  = 3, /*!< Bus 2x clock */
    kCLOCK_FlashClk  = 4, /*!< Flash clock */

    /*---------------------------------- OSC clock -----------------------------------*/
    kCLOCK_FastIrcClk     = 10, /*!< Fast internal RC oscillator, 48M */
    kCLOCK_FastIrcDiv6Clk = 11, /*!< ROSC 8M, derived from  kCLOCK_FastIrcClk div 6 */
    kCLOCK_SlowIrcClk     = 12, /*!< Slow internal RC oscillator, 200K */
    kCLOCK_CrystalOscClk  = 13, /*!< Crystal oscillator */

    /*----------------------------- Select/setting clock------------------------------*/
    kCLOCK_ExtClk     = 20, /*!< The selected external clock, it could be crystal oscillator, clkin0, clkin1 */
    kCLOCK_MstrOscClk = 21, /*!< The selected master oscillator clock */
    kCLOCK_PllDiv2Clk = 22  /*!< PLL output divide 2 */
} clock_name_t;

/*! @brief Crystal oscillator mode. */
typedef enum _clock_crystal_osc_mode
{
    kCLOCK_CrystalOscModeFSP = 0, /*!< Full swing pierce, high power mode */
    kCLOCK_CrystalOscModeLCP = 1  /*!< Loop controlled pierce, low power mode */
} clock_crystal_osc_mode_t;

/*! @brief List of external clock source. */
typedef enum _clock_ext_clk_src
{
    kCLOCK_ExtClkSrcCrystalOsc = 0, /*!< External clock source is crystal oscillator */
    kCLOCK_ExtClkSrcClkin      = 1  /*!< External clock source is clock in  */
} clock_ext_clk_src_t;

/*! @brief List of clock-in source. */
typedef enum _clock_ext_clkin_sel
{
    kCLOCK_SelClkIn0 = 0, /*!< Clock in 0 is selected as CLKIN */
    kCLOCK_SelClkIn1 = 1  /*!< Clock in 1 is selected as CLKIN */
} clock_ext_clkin_sel_t;

/*! @brief List of master oscillator source. */
typedef enum _clock_mstr_osc_clk_src
{
    kCLOCK_MstrOscClkSrcFircDiv6 = 0U, /*!< 8M, fast internal RC oscillator divide 6 */
    kCLOCK_MstrOscClkSrcExt      = 1U, /*!< External clock */
    kCLOCK_MstrOscClkSrcSirc     = 2U, /*!< 200K, slow internal RC oscillator */
    kCLOCK_MstrOscClkSrcFirc     = 3U  /*!< 48M, fast internal RC oscillator */
} clock_mstr_osc_clk_src_t;

/*! @brief List of master 2x clock source. */
typedef enum _clock_mstr_2x_clk_src
{
    kCLOCK_Mstr2xClkSrcMstrOsc = 0U, /*!< Master oscillator clock */
    kCLOCK_Mstr2xClkSrcPllDiv2 = 1U  /*!< PLL output divide 2 */
} clock_mstr_2x_clk_src_t;

/*! @brief List of output clock source. */
typedef enum _clock_output_clk_src
{
    kCLOCK_OutputClkSrc_Bus      = 0U, /*!< Bus clock */
    kCLOCK_OutputClkSrc_Bus2x    = 1U, /*!< Bus 2x clock */
    kCLOCK_OutputClkSrc_BusDiv4  = 2U, /*!< Bus clock div 4 */
    kCLOCK_OutputClkSrc_MstrOSC  = 3U, /*!< Master oscillator clock */
    kCLOCK_OutputClkSrc_FircDiv6 = 4U, /*!< 8M clock, FIRC/6 */
    kCLOCK_OutputClkSrc_Sirc     = 5U  /*!< 200K clock, SIRC*/
} clock_output_clk_src_t;

/*! @brief List of output clock divider. */
typedef enum _clock_output_clk_div
{
    kCLOCK_OutputDiv1   = 0U, /*!< output clock = selectedClock/1U */
    kCLOCK_OutputDiv2   = 1U, /*!< output clock = selectedClock/2U */
    kCLOCK_OutputDiv4   = 2U, /*!< output clock = selectedClock/4U */
    kCLOCK_OutputDiv8   = 3U, /*!< output clock = selectedClock/8U */
    kCLOCK_OutputDiv16  = 4U, /*!< output clock = selectedClock/16U */
    kCLOCK_OutputDiv32  = 5U, /*!< output clock = selectedClock/32U */
    kCLOCK_OutputDiv64  = 6U, /*!< output clock = selectedClock/64U */
    kCLOCK_OutputDiv128 = 7U  /*!< output clock = selectedClock/128U */
} clock_output_clk_div_t;

/*! @brief List of clock register protection mode. */
typedef enum _clock_protection
{
    kCLOCK_Protection_Off     = 0U, /*!< No protection, and could be changed any time */
    kCLOCK_Protection_On      = 1U, /*!< Protected, and could be changed any time */
    kCLOCK_Protection_OffLock = 2U, /*!< No protection and get locked until chip reset */
    kCLOCK_Protection_OnLock  = 3U  /*!< Protected and get locked until chip reset */
} clock_protection_t;

/*! @brief List of specific IP's clock source. */
typedef enum _clock_ip_clk_src
{
    kCLOCK_IPClkSrc_BusClk   = 0U, /*!< Bus clock */
    kCLOCK_IPClkSrc_Bus2xClk = 1U  /*!< Bus 2x clock */
} clock_ip_clk_src_t;

/*! @brief Mstr 2x clock postscale divider. */
typedef enum _clock_postscale
{
    kCLOCK_PostscaleDiv1   = 0, /*!< Mast 2X clock = clkSrc / 1 */
    kCLOCK_PostscaleDiv2   = 1, /*!< Mast 2X clock = clkSrc / 2 */
    kCLOCK_PostscaleDiv4   = 2, /*!< Mast 2X clock = clkSrc / 4 */
    kCLOCK_PostscaleDiv8   = 3, /*!< Mast 2X clock = clkSrc / 8 */
    kCLOCK_PostscaleDiv16  = 4, /*!< Mast 2X clock = clkSrc / 16 */
    kCLOCK_PostscaleDiv32  = 5, /*!< Mast 2X clock = clkSrc / 32 */
    kCLOCK_PostscaleDiv64  = 6, /*!< Mast 2X clock = clkSrc / 64 */
    kCLOCK_PostscaleDiv128 = 7, /*!< Mast 2X clock = clkSrc / 128 */
    kCLOCK_PostscaleDiv256 = 8, /*!< Mast 2X clock = clkSrc / 256 */
} clock_postscale_t;

/*! @brief Clock register protection configuration. */
typedef struct _clock_protection_config
{
    clock_protection_t eFrqEP; /*!< FRQEP bit field in OCCS PROT register, protect COD & ZSRC. */
    clock_protection_t eOscEP; /*!< OSCEP bit field in OCCS PROT register, protect OSCTL1, OSCTL2, PRECS. */
    clock_protection_t
        ePllEP; /*!< PLLEP bit field in OCCS PROT register, protect PLLDP, LOCIE, LORTP, PLLDB bitfield. */
} clock_protection_config_t;

/*! @brief Clock output configuration. */
typedef struct _clock_output_config
{
    bool bClkOut0En;                    /*!< Clock output 0 enable, CLKDIS0 bit field in SIM CLKOUT register*/
    bool bClkOut1En;                    /*!< Clock output 1 enable, CLKDIS1 bit field in SIM CLKOUT register*/
    clock_output_clk_src_t eClkOut0Src; /*!< Clock output 0 clock source, CLKOSEL0 bit field in SIM CLKOUT register*/
    clock_output_clk_src_t eClkOut1Src; /*!< Clock output 1 clock source, CLKOSEL1 bit field in SIM CLKOUT register*/
    clock_output_clk_div_t
        eClkDiv; /*!< Clock output divider, CLKODIV bit field in SIM CLKOUT register ,it apply to clkout0 & clkout1*/
} clock_output_config_t;

/*!
 * @brief mcu clock configuration structure.
 *
 * This is the key configuration structure of clock driver, which define the system
 * clock behavior. The function CLOCK_SetClkConfig deploy this configuration structure onto SOC.
 * */
typedef struct _clock_config
{
    bool bCrystalOscEnable; /*!< Crystal oscillator enable, COPD bit field in OCCS OSCTL2 register*/
    bool bFircEnable;       /*!< Fast internal RC oscillator enable, IRC48M_EN bit field in SIM MISC0 register*/
    bool bSircEnable;       /*!< Slow internal RC oscillator enable, ROPD200K bit field in OCCS OSCTL2 register*/
    bool bPllEnable;        /*!< PLL enable, PLLPD bit field in OCCS CTRL register*/
    bool
        bCrystalOscMonitorEnable; /*!< Crystal oscillator monitor enable, MON_ENABLE bit field in OCCS OSCTL2 register*/
    clock_crystal_osc_mode_t eCrystalOscMode; /*!< Crystal oscillator mode, COHL bit field in OCCS OSCTL1 register*/
    clock_ext_clk_src_t eExtClkSrc;           /*!< External clock source, EXT_SEL bit field in OCCS OSCTL1 register*/
    clock_ext_clkin_sel_t eClkInSel;         /*!< Clock IN selection(0 or 1), CLKINSEL bit field in SIM MISC0 register*/
    clock_mstr_osc_clk_src_t eMstrOscClkSrc; /*!< Master oscillator selection, PRECS bit field in OCCS CTRL register.
                                               When selected kCLOCK_MstrOscClkSrcExt, make sure corresponding
                                               pins(crystal osc or clkin pin) has been configured. */
    clock_mstr_2x_clk_src_t eMstr2xClkSrc;   /*!< Master 2x clock selection, ZSRC bit field in OCCS CTRL register*/
    clock_postscale_t eMstr2xClkPostScale;   /*!< Master 2x clock post scale, COD bit field in OCCS DIVBY register*/
    uint32_t u32PllClkFreq;                  /*!< Required PLL output frequency before divide 2 */
} clock_config_t;

/*! @brief PLL monitor type structure. */
typedef enum _clock_pll_monitor_type
{
    kCLOCK_PllMonitorUnLockCoarse,   /*!< PLL coarse unlock, due to loss of reference clock, power unstable...etc. */
    kCLOCK_PllMonitorUnLockFine,     /*!< PLL fine unlock, due to loss of reference clock, power unstable...etc. */
    kCLOCK_PllMonitorLostofReferClk, /*!< PLL lost reference clock. */
    kCLOCK_PllMonitorAll             /*!< All PLL monitor type. */
} clock_pll_monitor_type_t;

/*! @brief Describes PIT clock source. */
typedef enum _pit_count_clock_source
{
    /* This part is used for PIT driver. */
    kPIT_CountClockSource0 = 0U, /*!< PIT count clock sourced from IP bus clock */
    kPIT_CountClockSource1 = 1U, /*!< PIT count clock sourced from alternate clock 1 */
    kPIT_CountClockSource2 = 2U, /*!< PIT count clock sourced from alternate clock 2 */
    kPIT_CountClockSource3 = 3U, /*!< PIT count clock sourced from alternate clock 3 */
    /* This part is used for users. */
    kPIT_CountBusClock       = kPIT_CountClockSource0, /*!< PIT count clock sourced from IP bus clock */
    kPIT_CountCrystalClock   = kPIT_CountClockSource1, /*!< PIT count clock sourced from crystal clock */
    kPIT_Count8MHzIRCClock   = kPIT_CountClockSource2, /*!< PIT count clock sourced from 8MHz IRC clock */
    kPIT_Count200KHzIRCClock = kPIT_CountClockSource3, /*!< PIT count clock sourced from 200KHz IRC clock */
} pit_count_clock_source_t;

/*! @brief Describes EWM clock source. */
typedef enum _ewm_lpo_clock_source
{
    /* This part is used for EWM driver. */
    kEWM_LpoClockSource0 = 0U, /*!< EWM clock sourced from lpo_clk[0] */
    kEWM_LpoClockSource1 = 1U, /*!< EWM clock sourced from lpo_clk[1] */
    kEWM_LpoClockSource2 = 2U, /*!< EWM clock sourced from lpo_clk[2] */
    kEWM_LpoClockSource3 = 3U, /*!< EWM clock sourced from lpo_clk[3] */
    /* This part is used for users. */
    kEWM_Lpo8MHzIRCClock   = kEWM_LpoClockSource0, /*!< EWM clock sourced from 48 MHz IRC div6 clock */
    kEWM_LpoCrystalClock   = kEWM_LpoClockSource1, /*!< EWM clock sourced from crystal clock */
    kEWM_LpoBusClock       = kEWM_LpoClockSource2, /*!< EWM clock sourced from IP Bus clock */
    kEWM_Lpo200KHzIRCClock = kEWM_LpoClockSource3, /*!< EWM clock sourced from 200KHz IRC clock */
} ewm_lpo_clock_source_t;

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS                                                                                      \
    {                                                                                                    \
        kCLOCK_GPIOA, kCLOCK_GPIOB, kCLOCK_GPIOC, kCLOCK_GPIOD, kCLOCK_GPIOE, kCLOCK_GPIOF, kCLOCK_GPIOG \
    }

/*! @brief Clock ip name array for quad timer. */
#define TMR_CLOCKS                                                                                     \
    {                                                                                                  \
        kCLOCK_TA0, kCLOCK_TA1, kCLOCK_TA2, kCLOCK_TA3, kCLOCK_TB0, kCLOCK_TB1, kCLOCK_TB2, kCLOCK_TB3 \
    }

/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS \
    {                  \
        kCLOCK_FLEXCAN \
    }

/*! @brief Clock ip name array for I2C. */
#define I2C_CLOCKS               \
    {                            \
        kCLOCK_I2C0, kCLOCK_I2C1 \
    }

/*! @brief Clock ip name array for queued SPI. */
#define QSPI_CLOCKS                \
    {                              \
        kCLOCK_QSPI0, kCLOCK_QSPI1 \
    }

/*! @brief Clock ip name array for queued SCI. */
#define QSCI_CLOCKS                              \
    {                                            \
        kCLOCK_QSCI0, kCLOCK_QSCI1, kCLOCK_QSCI2 \
    }

/*! @brief Clock ip name array for DAC. */
#define DAC_CLOCKS               \
    {                            \
        kCLOCK_DACA, kCLOCK_DACB \
    }

/*! @brief Clock ip name array for PIT. */
#define PIT_CLOCKS               \
    {                            \
        kCLOCK_PIT0, kCLOCK_PIT1 \
    }

/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS \
    {              \
        kCLOCK_CRC \
    }

/*! @brief Clock ip name array for cyclic ADC. */
#define CADC_CLOCKS   \
    {                 \
        kCLOCK_CYCADC \
    }

/*! @brief Clock ip name array for CMP. */
#define CMP_CLOCKS                                         \
    {                                                      \
        kCLOCK_CMPA, kCLOCK_CMPB, kCLOCK_CMPC, kCLOCK_CMPD \
    }

/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS                                                         \
    {                                                                      \
        {kCLOCK_PWMACH0, kCLOCK_PWMACH1, kCLOCK_PWMACH2, kCLOCK_PWMACH3},  \
        {                                                                  \
            kCLOCK_PWMBCH0, kCLOCK_PWMBCH1, kCLOCK_PWMBCH2, kCLOCK_PWMBCH3 \
        }                                                                  \
    }

/*! @brief Clock ip name array for USB. */
#define USB_CLOCKS \
    {              \
        kCLOCK_USB \
    }

/*! @brief Clock ip name array for ROM. */
#define ROM_CLOCKS \
    {              \
        kCLOCK_ROM \
    }

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS \
    {               \
        kCLOCK_EDMA \
    }

/*! @brief Clock ip name array for EWM. */
#define EWM_CLOCKS \
    {              \
        kCLOCK_EWM \
    }

/*! @brief Clock ip name array for XBARA. */
#define XBARA_CLOCKS \
    {                \
        kCLOCK_XBARA \
    }

#define CLK_GATE_GET_REG_INDEX(x) (((uint16_t)(x)) >> 4)
#define CLK_GATE_GET_BIT_INDEX(x) (((uint16_t)(x)) & 0x0FU)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Enable IPs clock.
 *
 * @param eIpClkName IP clock name.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t eIpClkName)
{
    assert(eIpClkName < kCLOCK_NUM);
    if (eIpClkName != kCLOCK_NOGATE)
    {
        ((volatile uint16_t *)(&(SIM->PCE0)))[CLK_GATE_GET_REG_INDEX(eIpClkName)] |=
            (uint16_t)(1UL << CLK_GATE_GET_BIT_INDEX(eIpClkName));
    }
}

/*!
 * @brief Disable IPs clock.
 *
 * @param eIpClkName IP clock name.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t eIpClkName)
{
    assert(eIpClkName < kCLOCK_NUM);
    if (eIpClkName != kCLOCK_NOGATE)
    {
        ((volatile uint16_t *)(&(SIM->PCE0)))[CLK_GATE_GET_REG_INDEX(eIpClkName)] &=
            ~((uint16_t)(1UL << CLK_GATE_GET_BIT_INDEX(eIpClkName)));
    }
}

/*!
 * @brief Enable IPs clock in STOP mode.
 *
 * @param eIpClkName IP clock name.
 */
static inline void CLOCK_EnableClockInStopMode(clock_ip_name_t eIpClkName)
{
    assert(eIpClkName < kCLOCK_NUM);
    if (eIpClkName != kCLOCK_NOGATE)
    {
        ((volatile uint16_t *)(&(SIM->SD0)))[CLK_GATE_GET_REG_INDEX(eIpClkName)] |=
            (uint16_t)(1UL << CLK_GATE_GET_BIT_INDEX(eIpClkName));
    }
}

/*!
 * @brief Disable IPs clock in STOP mode.
 *
 * @param eIpClkName IP clock name.
 */
static inline void CLOCK_DisableClockInStopMode(clock_ip_name_t eIpClkName)
{
    assert(eIpClkName < kCLOCK_NUM);
    if (eIpClkName != kCLOCK_NOGATE)
    {
        ((volatile uint16_t *)(&(SIM->SD0)))[CLK_GATE_GET_REG_INDEX(eIpClkName)] &=
            ~((uint16_t)(1UL << CLK_GATE_GET_BIT_INDEX(eIpClkName)));
    }
}

/*!
 * @brief Configure QSCI clock source.
 *
 * QSCI clock could be bus or bus_2x clock. Default is bus clock.
 *
 * @param eQsciClkName IP(only QSCI is valid) clock name.
 * @param eClkSrc Clock source.
 */
static inline void CLOCK_ConfigQsciClockSrc(clock_ip_name_t eQsciClkName, clock_ip_clk_src_t eClkSrc)
{
    assert((eQsciClkName <= kCLOCK_QSCI0) && (eQsciClkName >= kCLOCK_QSCI2));
    if (kCLOCK_IPClkSrc_Bus2xClk == eClkSrc)
    {
        SIM->PCR |= (uint16_t)(1UL << (SIM_PCR_SCI0_CR_SHIFT + (uint16_t)eQsciClkName - (uint16_t)kCLOCK_QSCI0));
    }
    else
    {
        SIM->PCR &= ~((uint16_t)(1UL << (SIM_PCR_SCI0_CR_SHIFT + (uint16_t)eQsciClkName - (uint16_t)kCLOCK_QSCI0)));
    }
}

/*!
 * @brief Configure I2C filter clock source.
 *
 * I2C filter clock could be bus or bus_2x clock. Default is bus clock.
 *
 * @param eI2cClkName IP(only I2C is valid) clock name.
 * @param eClkSrc Clock source.
 */
static inline void CLOCK_ConfigI2cFilterClockSrc(clock_ip_name_t eI2cClkName, clock_ip_clk_src_t eClkSrc)
{
    assert((eI2cClkName <= kCLOCK_I2C0) && (eI2cClkName >= kCLOCK_I2C1));
    if (kCLOCK_IPClkSrc_Bus2xClk == eClkSrc)
    {
        SIM->PCR |= (uint16_t)(1UL << ((uint16_t)eI2cClkName - (uint16_t)kCLOCK_I2C1 + SIM_PCR_IIC1_CR_SHIFT));
    }
    else
    {
        SIM->PCR &= ~((uint16_t)(1UL << ((uint16_t)eI2cClkName - (uint16_t)kCLOCK_I2C1 + SIM_PCR_IIC1_CR_SHIFT)));
    }
}

/*!
 * @brief Set trim value to 200K slow internal RC oscillator.
 *
 * The factory trim value is loaded during reset.
 * User may call this function to fine tune the 200K IRC oscillator.
 *
 * @param u16Trim Slow internal RC oscillator trim value.
 */
static inline void CLOCK_SetSlowIrcTrim(uint16_t u16Trim)
{
    OCCS->OSCTL2 = (OCCS->OSCTL2 & (~((uint16_t)OCCS_OSCTL2_FREQ_TRIM200K_MASK))) | OCCS_OSCTL2_FREQ_TRIM200K(u16Trim);
}

/*!
 * @brief Get crystal oscillator failure status.
 *
 * @note This function should be called only when crystal osc is on and its monitor(MON_ENABLE in OSCTL2 register) is
 * enabled.
 *
 * @return Crystal oscillator status.
 *         true: Crystal oscillator frequency is below 680KHz(typical).
 *         false: No clock failure or crystal oscillator is off.
 */
static inline bool CLOCK_GetCrystalOscFailureStatus(void)
{
    return (0U != (OCCS->STAT & OCCS_STAT_MON_FAILURE_MASK));
}

/*!
 * @brief Set PLL loss of reference trip point.
 *
 * The trip point default value is 2.
 *
 * @param u8Trip Trip point for loss of reference.
 */
static inline void CLOCK_SetPllLossofRefererntTripPoint(uint8_t u8Trip)
{
    OCCS->DIVBY = (OCCS->DIVBY & (~((uint16_t)OCCS_DIVBY_LORTP_MASK))) | OCCS_DIVBY_LORTP(u8Trip);
}

/*!
 * @brief Clear PLL monitor flag.
 *
 * @param eType PLL monitor type.
 */
static inline void CLOCK_ClearPLLMonitorFlag(clock_pll_monitor_type_t eType)
{
    switch (eType)
    {
        case kCLOCK_PllMonitorUnLockCoarse:
            OCCS->STAT = OCCS_STAT_LOLI0_MASK;
            break;

        case kCLOCK_PllMonitorUnLockFine:
            OCCS->STAT = OCCS_STAT_LOLI1_MASK;
            break;

        case kCLOCK_PllMonitorLostofReferClk:
            OCCS->STAT = OCCS_STAT_LOCI_MASK;
            break;

        case kCLOCK_PllMonitorAll:
            OCCS->STAT = OCCS_STAT_LOLI0_MASK | OCCS_STAT_LOLI1_MASK | OCCS_STAT_LOCI_MASK;
            break;

        default:
            assert(false);
            break;
    }
}

/*!
 * @brief Get system-level clock frequency.
 *
 * @param eClkName System-level clock name.
 *
 * @return The required clock's frequency in Hz.
 */
uint32_t CLOCK_GetFreq(clock_name_t eClkName);

/*!
 * @brief Get IP clock frequency.
 *
 * @param eIpClkName IP clock name.
 *
 * @return The required IP clock's frequency in Hz.
 */
uint32_t CLOCK_GetIpClkSrcFreq(clock_ip_name_t eIpClkName);

/*!
 * @brief Set Clock IN 0 frequency.
 *
 * It is a must to call this function in advance if system is operated by clkin0.
 *
 * @param u32Freq Clock IN 0 frequency in Hz.
 */
void CLOCK_SetClkin0Freq(uint32_t u32Freq);

/*!
 * @brief Set Clock IN 1 frequency.
 *
 * It is a must to call this function in advance if system is operated by clkin1.
 *
 * @param u32Freq Clock IN 1 frequency in Hz.
 */
void CLOCK_SetClkin1Freq(uint32_t u32Freq);

/*!
 * @brief Set crystal oscillator frequency.
 *
 * It is a must to call this function in advance if system is operated by crystal oscillator.
 *
 * @param u32Freq Crystal oscillator frequency in Hz.
 */
void CLOCK_SetXtalFreq(uint32_t u32Freq);

/*!
 * @brief Config clock register access protection mode.
 *
 * @param psConfig Pointer for protection configuration.
 */
void CLOCK_SetProtectionConfig(clock_protection_config_t *psConfig);

/*!
 * @brief Config output clock.
 *
 * @param psConfig Pointer for clock output configuration.
 */
void CLOCK_SetOutputClockConfig(clock_output_config_t *psConfig);

/*!
 * @brief Config mcu operation clock.
 *
 * @param psConfig Pointer for clock configuration.
 */
void CLOCK_SetClkConfig(clock_config_t *psConfig);

#if (defined(FSL_FEATURE_SOC_USB_COUNT) && (FSL_FEATURE_SOC_USB_COUNT > 0U))
/*!
 * @brief Enable USB FS clock.
 */
void CLOCK_EnableUsbfs0Clock(void);
#endif

/*!
 * @brief Evaluate external clock frequency and return its frequency in Hz.
 *
 * This function should be called only when internal FIRC(48M) is on.
 * The evaluated result accuracy depends on:
 * 1. FIRC accuracy, now it is +/-1%.
 * 2. Truncation error, because the external clock and FIRC is not synchronised.
 * 3. External clock frequency, low accuracy for lower external clock frequency.
 * 4. MCU mstr 2x clock.
 *
 * For example, for namely 8M external clock, evaluated result may be range in 8M+/-5%.
 *
 * @return Evaluated external frequency in Hz.
 */
uint32_t CLOCK_EvaluateExtClkFreq(void);

/*!
 * @brief Enable/Disable PLL monitor interrupt.
 *
 * This function should be called only when PLL is on and its reference clock is external clock.
 * This function is for safety purpose when external clock is lost due to HW failure.
 * The normal flow to call this function:
 * 1. Call CLOCK_SetClkConfig to enable PLL and external clock to feed the PLL.
 * 2. Call CLOCK_ClearPLLMonitorFlag.
 * 3. Call CLOCK_SetPllLossofRefererntTripPoint (optional, setting value is for kCLOCK_PllMonitorLostofReferClk type).
 * 4. Call this function.
 * 5. Enable OCCS interrupt with highest priority 3.
 * 6. When OCCS interrupt occurs, recover clock from the disaster in OCCS_DriveISRHandler function. Such kind of clock
 * recovery is application dependent, and a demo OCCS_DriveISRHandler has been shown in fsl_clock.c
 *
 * @param eType PLL monitor type.
 * @param bEnable Enable or disable.
 */
void CLOCK_EnablePLLMonitorInterrupt(clock_pll_monitor_type_t eType, bool bEnable);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
