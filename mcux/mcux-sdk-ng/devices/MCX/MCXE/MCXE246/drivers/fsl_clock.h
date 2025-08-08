/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

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

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.0.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @brief External XTAL0 (OSC0/SYSOSC) clock frequency.
 *
 * The XTAL0/EXTAL0 (OSC0/SYSOSC) clock frequency in Hz. When the clock is set up, use the
 * function CLOCK_SetXtal0Freq to set the value in the clock driver. For example,
 * if XTAL0 is 8 MHz:
 * @code
 * CLOCK_InitSysOsc(...);
 * CLOCK_SetXtal0Freq(80000000);
 * @endcode
 *
 * This is important for the multicore platforms where only one core needs to set up the
 * OSC0/SYSOSC using CLOCK_InitSysOsc. All other cores need to call the CLOCK_SetXtal0Freq
 * to get a valid clock frequency.
 */
extern volatile uint32_t g_xtal0Freq;

#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (112000000UL)
#endif

/*! @brief Clock ip name array for DMAMUX. */
#define DMAMUX_CLOCKS  \
    {                  \
        kCLOCK_Dmamux0 \
    }

/*! @brief Clock ip name array for FlexCAN. */
#define FLEXCAN_CLOCKS                        \
    {                                         \
        kCLOCK_Can0, kCLOCK_Can1, kCLOCK_Can2 \
    }

/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS                                                          \
    {                                                                        \
        kCLOCK_PortA, kCLOCK_PortB, kCLOCK_PortC, kCLOCK_PortD, kCLOCK_PortE \
    }

/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                 \
    {                                \
        kCLOCK_Lpi2c0                \
    }

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS  \
    {                  \
        kCLOCK_Flexio0 \
    }

/*! @brief Clock ip name array for RTC. */
#define RTC_CLOCKS  \
    {               \
        kCLOCK_Rtc0 \
    }

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS \
    {               \
        kCLOCK_Dma  \
    }

/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                  \
    {                                                  \
        kCLOCK_Lpuart0, kCLOCK_Lpuart1, kCLOCK_Lpuart2 \
    }

/*! @brief Clock ip name array for LPTMR. */
#define LPTMR_CLOCKS  \
    {                 \
        kCLOCK_Lptmr0 \
    }

/*! @brief Clock ip name array for ADC12. */
#define ADC12_CLOCKS             \
    {                            \
        kCLOCK_Adc0, kCLOCK_Adc1 \
    }

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                \
    {                                               \
        kCLOCK_Lpspi0, kCLOCK_Lpspi1, kCLOCK_Lpspi2 \
    }

/*! @brief Clock ip name array for LPIT. */
#define LPIT_CLOCKS  \
    {                \
        kCLOCK_Lpit0 \
    }

/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS  \
    {               \
        kCLOCK_Crc0 \
    }

/*! @brief Clock ip name array for PDB. */
#define PDB_CLOCKS               \
    {                            \
        kCLOCK_Pdb0, kCLOCK_Pdb1 \
    }

/*! @brief Clock ip name array for CMP. */
#define CMP_CLOCKS  \
    {               \
        kCLOCK_Cmp0 \
    }

/*! @brief Clock ip name array for FLASH. */
#define FLASH_CLOCKS  \
    {                 \
        kCLOCK_Flash0 \
    }

/*! @brief Clock ip name array for EWM. */
#define EWM_CLOCKS  \
    {               \
        kCLOCK_Ewm0 \
    }

/*! @brief Clock ip name array for FLEXTMR. */
#define FTM_CLOCKS                                          \
    {                                                       \
        kCLOCK_Ftm0, kCLOCK_Ftm1, kCLOCK_Ftm2, kCLOCK_Ftm3, \
        kCLOCK_Ftm4, kCLOCK_Ftm5                            \
    }

/*! @brief Clock ip name array for FLEXIO_TRIG0/1 Aync clock. */
#define FLEXIOTRIG_CLOCKS                      \
    {                                          \
        kCLOCK_FlexioTrig0, kCLOCK_FlexioTrig1 \
    }

/*! @brief Clock ip name array for MPU. */
#define SYSMPU_CLOCKS  \
    {                  \
        kCLOCK_Mpu     \
    }

/*!
 * @brief LPO clock frequency.
 */
#define LPO_1K_CLK_FREQ   1000U
#define LPO_32K_CLK_FREQ  32000U
#define LPO_128K_CLK_FREQ 128000U


/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    /* ----------------------------- System layer clock -------------------------------*/
    kCLOCK_CoreSysClk, /*!< Core/system clock                                          */
    kCLOCK_BusClk,     /*!< Bus clock                                                  */
    kCLOCK_FlashClk,   /*!< Flash clock                                                */

    /* ------------------------------------ SCG clock ---------------------------------*/
    kCLOCK_ScgSysOscClk, /*!< SCG system OSC clock. (SYSOSC)                           */
    kCLOCK_ScgSircClk,   /*!< SCG SIRC clock.                                          */
    kCLOCK_ScgFircClk,   /*!< SCG FIRC clock.                                          */
    kCLOCK_ScgSysPllClk, /*!< SCG System PLL clock. (SPLL)                             */

    kCLOCK_ScgSysOscAsyncDiv1Clk, /*!< SOSCDIV1_CLK.                                   */
    kCLOCK_ScgSysOscAsyncDiv2Clk, /*!< SOSCDIV2_CLK.                                   */

    kCLOCK_ScgSircAsyncDiv1Clk, /*!< SIRCDIV1_CLK.                                     */
    kCLOCK_ScgSircAsyncDiv2Clk, /*!< SIRCDIV2_CLK.                                     */

    kCLOCK_ScgFircAsyncDiv1Clk, /*!< FIRCDIV1_CLK.                                     */
    kCLOCK_ScgFircAsyncDiv2Clk, /*!< FIRCDIV2_CLK.                                     */

    kCLOCK_ScgSysPllAsyncDiv1Clk, /*!< SPLLDIV1_CLK.                                   */
    kCLOCK_ScgSysPllAsyncDiv2Clk, /*!< SPLLDIV2_CLK.                                   */

    /* --------------------------------- Other clock ----------------------------------*/
    kCLOCK_Lpo1kClk,   /*!< 1kHz LPO clock                                             */
    kCLOCK_Lpo32kClk,  /*!< 32kHz LPO clock                                            */
    kCLOCK_Lpo128kClk, /*!< 128kHz LPO clock                                           */
    kCLOCK_LpoClk,     /*!< LPO clock selected by SIM_LPOCLKS[LPOCLKSEL]               */
    kCLOCK_ErClk,      /*!< ERCLK. The external reference clock from SCG.              */
} clock_name_t;

#define kCLOCK_Osc0ErClk       kCLOCK_ErClk
#define CLOCK_GetOsc0ErClkFreq CLOCK_GetErClkFreq /*!< For compatible with other MCG platforms. */

/*!
 * @brief Clock source for peripherals that support various clock selections.
 */
typedef enum _clock_ip_src
{
    kCLOCK_IpSrcNoneOrExt   = 0U, /*!< Clock is off or external clock is used. */
    kCLOCK_IpSrcSysOscAsync = 1U, /*!< System Oscillator async clock.          */
    kCLOCK_IpSrcSircAsync   = 2U, /*!< Slow IRC async clock.                   */
    kCLOCK_IpSrcFircAsync   = 3U, /*!< Fast IRC async clock.                   */
    kCLOCK_IpSrcSysPllAsync = 6U, /*!< SPLL async clock.                       */
    kCLOCK_IpSrcLpoAsync    = 7U  /*!< LPO128 async clock.                     */
} clock_ip_src_t;

#define CLOCK_SIM_CGC_MASK 0x1FU

/*!
 * @brief Peripheral clock name difinition used for clock gate, clock source
 * and clock divider setting.
 * It is defined as SIM_PLATCGC register adress with added 1 in bitfield
 * corresponding to controlled peripheral for peripherals controled by SIM.
 * It is defined as the corresponding register address for peripherals
 * controlled by PCC.
 */
typedef enum _clock_ip_name
{
    kCLOCK_IpInvalid = 0U,

    /* Controlled by SIM */
    kCLOCK_Eim         = (0x40048040U | SIM_PLATCGC_CGCEIM(1)),
    kCLOCK_Erm         = (0x40048040U | SIM_PLATCGC_CGCERM(1)),
    kCLOCK_Dma         = (0x40048040U | SIM_PLATCGC_CGCDMA(1)),
    kCLOCK_Mpu         = (0x40048040U | SIM_PLATCGC_CGCMPU(1)),
    kCLOCK_Mscm        = (0x40048040U | SIM_PLATCGC_CGCMSCM(1)),

    /* Controlled by PCC */
    kCLOCK_Flash0      = 0x40065080U,
    kCLOCK_Dmamux0     = 0x40065084U,
    kCLOCK_Can0        = 0x40065090U,
    kCLOCK_Can1        = 0x40065094U,
    kCLOCK_Ftm3        = 0x40065098U,
    kCLOCK_Adc1        = 0x4006509CU,
    kCLOCK_Can2        = 0x400650ACU,
    kCLOCK_Lpspi0      = 0x400650B0U,
    kCLOCK_Lpspi1      = 0x400650B4U,
    kCLOCK_Lpspi2      = 0x400650B8U,
    kCLOCK_Pdb1        = 0x400650C4U,
    kCLOCK_Crc0        = 0x400650C8U,
    kCLOCK_Pdb0        = 0x400650D8U,
    kCLOCK_Lpit0       = 0x400650DCU,
    kCLOCK_Ftm0        = 0x400650E0U,
    kCLOCK_Ftm1        = 0x400650E4U,
    kCLOCK_Ftm2        = 0x400650E8U,
    kCLOCK_Adc0        = 0x400650ECU,
    kCLOCK_Rtc0        = 0x400650F4U,
    kCLOCK_Lptmr0      = 0x40065100U,
    kCLOCK_PortA       = 0x40065124U,
    kCLOCK_PortB       = 0x40065128U,
    kCLOCK_PortC       = 0x4006512CU,
    kCLOCK_PortD       = 0x40065130U,
    kCLOCK_PortE       = 0x40065134U,
    kCLOCK_Flexio0     = 0x40065168U,
    kCLOCK_Ewm0        = 0x40065184U,
    kCLOCK_Lpi2c0      = 0x40065198U,
    kCLOCK_Lpuart0     = 0x400651A8U,
    kCLOCK_Lpuart1     = 0x400651ACU,
    kCLOCK_Lpuart2     = 0x400651B0U,
    kCLOCK_Ftm4        = 0x400651B8U,
    kCLOCK_Ftm5        = 0x400651BCU,
    kCLOCK_Cmp0        = 0x400651CCU,
} clock_ip_name_t;

/*!
 * @brief SCG status return codes.
 */
enum
{
    kStatus_SCG_Busy       = MAKE_STATUS(kStatusGroup_SCG, 1), /*!< Clock is busy.  */
    kStatus_SCG_InvalidSrc = MAKE_STATUS(kStatusGroup_SCG, 2)  /*!< Invalid source. */
};

/*!
 * @brief SCG system clock type.
 */
typedef enum _scg_sys_clk
{
    kSCG_SysClkSlow, /*!< System slow clock. */
    kSCG_SysClkBus,  /*!< Bus clock.         */
    kSCG_SysClkCore, /*!< Core clock.        */
} scg_sys_clk_t;

/*!
 * @brief SCG system clock source.
 */
typedef enum _scg_sys_clk_src
{
    kSCG_SysClkSrcSysOsc = 1U, /*!< System OSC. */
    kSCG_SysClkSrcSirc   = 2U, /*!< Slow IRC.   */
    kSCG_SysClkSrcFirc   = 3U, /*!< Fast IRC.   */
    kSCG_SysClkSrcSysPll = 6U  /*!< System PLL. */
} scg_sys_clk_src_t;

/*!
 * @brief SCG system clock divider value.
 */
typedef enum _scg_sys_clk_div
{
    kSCG_SysClkDivBy1  = 0U,  /*!< Divided by 1.  */
    kSCG_SysClkDivBy2  = 1U,  /*!< Divided by 2.  */
    kSCG_SysClkDivBy3  = 2U,  /*!< Divided by 3.  */
    kSCG_SysClkDivBy4  = 3U,  /*!< Divided by 4.  */
    kSCG_SysClkDivBy5  = 4U,  /*!< Divided by 5.  */
    kSCG_SysClkDivBy6  = 5U,  /*!< Divided by 6.  */
    kSCG_SysClkDivBy7  = 6U,  /*!< Divided by 7.  */
    kSCG_SysClkDivBy8  = 7U,  /*!< Divided by 8.  */
    kSCG_SysClkDivBy9  = 8U,  /*!< Divided by 9.  */
    kSCG_SysClkDivBy10 = 9U,  /*!< Divided by 10. */
    kSCG_SysClkDivBy11 = 10U, /*!< Divided by 11. */
    kSCG_SysClkDivBy12 = 11U, /*!< Divided by 12. */
    kSCG_SysClkDivBy13 = 12U, /*!< Divided by 13. */
    kSCG_SysClkDivBy14 = 13U, /*!< Divided by 14. */
    kSCG_SysClkDivBy15 = 14U, /*!< Divided by 15. */
    kSCG_SysClkDivBy16 = 15U  /*!< Divided by 16. */
} scg_sys_clk_div_t;

/*!
 * @brief SCG system clock configuration.
 */
typedef struct _scg_sys_clk_config
{
    uint32_t divSlow : 4; /*!< Slow clock divider, see @ref scg_sys_clk_div_t. */
    uint32_t divBus : 4;  /*!< Bus clock divider, see @ref scg_sys_clk_div_t.  */
    uint32_t : 4;         /*!< Reserved. */
    uint32_t : 4;         /*!< Reserved. */
    uint32_t divCore : 4; /*!< Core clock divider, see @ref scg_sys_clk_div_t. */
    uint32_t : 4;         /*!< Reserved. */
    uint32_t src : 4;     /*!< System clock source, see @ref scg_sys_clk_src_t. */
    uint32_t : 4;         /*!< reserved. */
} scg_sys_clk_config_t;

/*!
 * @brief SCG clock out configuration (CLKOUTSEL).
 */
typedef enum _clock_clkout_src
{
    kClockClkoutSelScgSlow = 0U, /*!< SCG slow clock. */
    kClockClkoutSelSysOsc  = 1U, /*!< System OSC.     */
    kClockClkoutSelSirc    = 2U, /*!< Slow IRC.       */
    kClockClkoutSelFirc    = 3U, /*!< Fast IRC.       */
    kClockClkoutSelSysPll  = 6U, /*!< System PLL.     */
} clock_clkout_src_t;

/*!
 * @brief SCG asynchronous clock type.
 */
typedef enum _scg_async_clk
{
    kSCG_AsyncDiv1Clk, /*!< The async clock by DIV1, e.g. SOSCDIV1_CLK, SIRCDIV1_CLK. */
    kSCG_AsyncDiv2Clk, /*!< The async clock by DIV2, e.g. SOSCDIV2_CLK, SIRCDIV2_CLK. */
} scg_async_clk_t;

/*!
 * @brief SCG asynchronous clock divider value.
 */
typedef enum scg_async_clk_div
{
    kSCG_AsyncClkDisable = 0U, /*!< Clock output is disabled.  */
    kSCG_AsyncClkDivBy1  = 1U, /*!< Divided by 1.              */
    kSCG_AsyncClkDivBy2  = 2U, /*!< Divided by 2.              */
    kSCG_AsyncClkDivBy4  = 3U, /*!< Divided by 4.              */
    kSCG_AsyncClkDivBy8  = 4U, /*!< Divided by 8.              */
    kSCG_AsyncClkDivBy16 = 5U, /*!< Divided by 16.             */
    kSCG_AsyncClkDivBy32 = 6U, /*!< Divided by 32.             */
    kSCG_AsyncClkDivBy64 = 7U  /*!< Divided by 64.             */
} scg_async_clk_div_t;

/*!
 * @brief SCG system OSC monitor mode.
 */
typedef enum _scg_sosc_monitor_mode
{
    kSCG_SysOscMonitorDisable = 0U,                      /*!< Monitor disabled.                                */
    kSCG_SysOscMonitorInt     = SCG_SOSCCSR_SOSCCM_MASK, /*!< Interrupt when the system OSC error is detected. */
    kSCG_SysOscMonitorReset =
        SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK /*!< Reset when the system OSC error is detected.  */
} scg_sosc_monitor_mode_t;

/*! @brief OSC work mode. */
typedef enum _scg_sosc_mode
{
    kSCG_SysOscModeExt         = 0U,                                           /*!< Use external clock.   */
    kSCG_SysOscModeOscLowPower = SCG_SOSCCFG_EREFS_MASK,                       /*!< Oscillator low power. */
    kSCG_SysOscModeOscHighGain = SCG_SOSCCFG_EREFS_MASK | SCG_SOSCCFG_HGO_MASK /*!< Oscillator high gain. */
} scg_sosc_mode_t;

/*! @brief OSC enable mode. */
enum
{
    kSCG_SysOscEnable           = SCG_SOSCCSR_SOSCEN_MASK,     /*!< Enable OSC clock. */
};

/*!
 * @brief SCG system OSC configuration.
 */
typedef struct _scg_sosc_config
{
    uint32_t freq;                       /*!< System OSC frequency.                               */
    scg_sosc_monitor_mode_t monitorMode; /*!< Clock monitor mode selected.                        */
    uint8_t enableMode;                  /*!< Enable mode, OR'ed value of _scg_sosc_enable_mode.  */

    scg_async_clk_div_t div1; /*!< SOSCDIV1 value. */
    scg_async_clk_div_t div2; /*!< SOSCDIV2 value. */

    scg_sosc_mode_t workMode; /*!< OSC work mode. */
} scg_sosc_config_t;

/*!
 * @brief SCG slow IRC clock frequency range.
 */
typedef enum _scg_sirc_range
{
    kSCG_SircRangeHigh = 1U /*!< Slow IRC high range clock (8 MHz). */
} scg_sirc_range_t;

/*! @brief SIRC enable mode. */
enum
{
    kSCG_SircEnable           = SCG_SIRCCSR_SIRCEN_MASK,   /*!< Enable SIRC clock.             */
    kSCG_SircEnableInStop     = SCG_SIRCCSR_SIRCSTEN_MASK, /*!< Enable SIRC in stop mode.      */
    kSCG_SircEnableInLowPower = SCG_SIRCCSR_SIRCLPEN_MASK  /*!< Enable SIRC in low power mode. */
};

/*!
 * @brief SCG slow IRC clock configuration.
 */
typedef struct _scg_sirc_config
{
    uint32_t enableMode;      /*!< Enable mode, OR'ed value of _scg_sirc_enable_mode. */

    scg_async_clk_div_t div1; /*!< SIRCDIV1 value.                          */
    scg_async_clk_div_t div2; /*!< SIRCDIV2 value.                          */

    scg_sirc_range_t range; /*!< Slow IRC frequency range.                */
} scg_sirc_config_t;

/*!
 * @brief SCG fast IRC clock frequency range.
 */
typedef enum _scg_firc_range
{
    kSCG_FircRange48M, /*!< Fast IRC is trimmed to 48 MHz.  */
} scg_firc_range_t;

/*! @brief FIRC enable mode. */
enum
{
    kSCG_FircEnable           = SCG_FIRCCSR_FIRCEN_MASK,    /*!< Enable FIRC clock.             */
    kSCG_FircDisableRegulator = SCG_FIRCCSR_FIRCREGOFF_MASK /*!< Disable regulator.             */
};

/*!
 * @brief SCG fast IRC clock configuration.
 */
typedef struct _scg_firc_config_t
{
    uint32_t enableMode; /*!< Enable mode, OR'ed value of _scg_firc_enable_mode. */

    scg_async_clk_div_t div1; /*!< FIRCDIV1 value.                          */
    scg_async_clk_div_t div2; /*!< FIRCDIV2 value.                          */

    scg_firc_range_t range; /*!< Fast IRC frequency range.                 */
    const uint32_t *trimConfig; /*!< Set NULL to disable trim. Trim is not supported on MCXE24x. */
} scg_firc_config_t;

/*!
 * @brief SCG system PLL monitor mode.
 */
typedef enum _scg_spll_monitor_mode
{
    kSCG_SysPllMonitorDisable = 0U,                      /*!< Monitor disabled.                          */
    kSCG_SysPllMonitorInt     = SCG_SPLLCSR_SPLLCM_MASK, /*!< Interrupt when the system PLL error is detected. */
    kSCG_SysPllMonitorReset =
        SCG_SPLLCSR_SPLLCM_MASK | SCG_SPLLCSR_SPLLCMRE_MASK /*!< Reset when the system PLL error is detected.     */
} scg_spll_monitor_mode_t;

/*! @brief SPLL enable mode. */
enum
{
    kSCG_SysPllEnable       = SCG_SPLLCSR_SPLLEN_MASK,  /*!< Enable SPLL clock.             */
};

/*!
 * @brief SCG system PLL configuration.
 */
typedef struct _scg_spll_config
{
    uint8_t enableMode;                  /*!< Enable mode, OR'ed value of _scg_spll_enable_mode */
    scg_spll_monitor_mode_t monitorMode; /*!< Clock monitor mode selected.     */

    scg_async_clk_div_t div1; /*!< SPLLDIV1 value.                          */
    scg_async_clk_div_t div2; /*!< SPLLDIV2 value.                          */

    uint8_t prediv;     /*!< PLL reference clock divider.             */
    uint8_t mult;       /*!< System PLL multiplier.                   */
} scg_spll_config_t;

/*!
 * @brief LPO clock source.
 */
typedef enum _sim_lpo_clk_src
{
    kSIM_LpoClkSrcLpo128k = 0U, /*!< 128kHz LPO clock. */
    kSIM_LpoClkSrcLpo32k  = 2U, /*!< 32kHz LPO clock.  */
    kSIM_LpoClkSrcLpo1k   = 3U, /*!< 1kHz LPO clock.   */
} sim_lpo_clk_src_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Enable the clock for specific IP.
 *
 * @param name  Which clock to enable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_EnableClock(clock_ip_name_t name)
{
    if ((name & SIM_BASE) == SIM_BASE)
    {
        /* Controlled by SIM */
        SIM->PLATCGC |= ((uint32_t)name & CLOCK_SIM_CGC_MASK );
    }
    else
    {
        /* Controlled by PCC */
        assert((*(volatile uint32_t *)((uint32_t)name)) & PCC_CLKCFG_PR_MASK);
        (*(volatile uint32_t *)((uint32_t)name)) |= PCC_CLKCFG_CGC_MASK;
    }
}

/*!
 * @brief Disable the clock for specific IP.
 *
 * @param name  Which clock to disable, see \ref clock_ip_name_t.
 */
static inline void CLOCK_DisableClock(clock_ip_name_t name)
{
    if ((name & SIM_BASE) == SIM_BASE)
    {
        /* Controlled by SIM */
        SIM->PLATCGC &= ~((uint32_t)name & CLOCK_SIM_CGC_MASK);
    }
    else
    {
        /* Controlled by PCC */
        assert((*(volatile uint32_t *)((uint32_t)name)) & PCC_CLKCFG_PR_MASK);
        (*(volatile uint32_t *)((uint32_t)name)) &= ~PCC_CLKCFG_CGC_MASK;
    }
}

/*!
 * @brief Set the clock source for specific IP module.
 *
 * Set the clock source for specific IP, not all modules need to set the
 * clock source, should only use this function for the modules need source
 * setting.
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param src Clock source to set.
 */
static inline void CLOCK_SetIpSrc(clock_ip_name_t name, clock_ip_src_t src)
{
    uint32_t reg = (*(volatile uint32_t *)((uint32_t)name));

    assert(reg & PCC_CLKCFG_PR_MASK);

    reg = (reg & ~PCC_CLKCFG_PCS_MASK) | PCC_CLKCFG_PCS(src);

    /*
     * If clock is already enabled, first disable it, then set the clock
     * source and re-enable it.
     */
    (*(volatile uint32_t *)((uint32_t)name)) = reg & ~PCC_CLKCFG_CGC_MASK;
    (*(volatile uint32_t *)((uint32_t)name)) = reg;
}

/*!
 * @brief Set the clock source and divider for specific IP module.
 *
 * Set the clock source and divider for specific IP, not all modules need to
 * set the clock source and divider, should only use this function for the
 * modules need source and divider setting.
 *
 * Divider output clock = Divider input clock x [(fracValue+1)/(divValue+1)]).
 *
 * @param name Which peripheral to check, see \ref clock_ip_name_t.
 * @param src Clock source to set.
 * @param divValue  The divider value.
 * @param fracValue The fraction multiply value.
 */
static inline void CLOCK_SetIpSrcDiv(clock_ip_name_t name, clock_ip_src_t src, uint16_t divValue, uint8_t fracValue)
{
    uint32_t reg = (*(volatile uint32_t *)(uint32_t)name);

    assert((reg & PCC_CLKCFG_PR_MASK) != 0UL);

    reg = (reg & ~(PCC_CLKCFG_PCS_MASK | PCC_CLKCFG_FRAC_MASK | PCC_CLKCFG_PCD_MASK)) | PCC_CLKCFG_PCS(src) |
          PCC_CLKCFG_PCD(divValue) | PCC_CLKCFG_FRAC(fracValue);

    /*
     * If clock is already enabled, first disable it, then set the clock
     * source and re-enable it.
     */
    (*(volatile uint32_t *)(uint32_t)name) = reg & ~PCC_CLKCFG_CGC_MASK;
    (*(volatile uint32_t *)(uint32_t)name) = reg;
}

/*!
 * @brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_name_t.
 *
 * @param clockName Clock names defined in clock_name_t
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*!
 * @brief Get the core clock or system clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*!
 * @brief Get the bus clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetBusClkFreq(void);

/*!
 * @brief Get the flash clock frequency.
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetFlashClkFreq(void);

/*!
 * @brief Get the external reference clock frequency (ERCLK).
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetErClkFreq(void);

/*!
 * @brief Get the internal low power oscillator frequency (LPO_CLK).
 *
 * @return Clock frequency in Hz.
 */
uint32_t CLOCK_GetLpoClkFreq(void);

/*!
 * @brief Gets the clock frequency for a specific IP module.
 *
 * This function gets the IP module clock frequency based on PCC registers. It is
 * only used for the IP modules which could select clock source by PCC[PCS].
 *
 * @param name Which peripheral to get, see \ref clock_ip_name_t.
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetIpFreq(clock_ip_name_t name);

/*!
 * @name MCU System Clock.
 * @{
 */

/*!
 * @brief Gets the SCG system clock frequency.
 *
 * This function gets the SCG system clock frequency. These clocks are used for
 * core, platform, external, and bus clock domains.
 *
 * @param type     Which type of clock to get, core clock or slow clock.
 * @return  Clock frequency.
 */
uint32_t CLOCK_GetSysClkFreq(scg_sys_clk_t type);

/*!
 * @brief Sets the system clock configuration for VLPR mode.
 *
 * This function sets the system clock configuration for VLPR mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_SetVlprModeSysClkConfig(const scg_sys_clk_config_t *config)
{
    assert(config);
    union
    {
        const uint32_t *configInt;
        const scg_sys_clk_config_t *configPtr;
    } Config;

    Config.configPtr = config;
    SCG->VCCR        = *(Config.configInt);
}

/*!
 * @brief Sets the system clock configuration for RUN mode.
 *
 * This function sets the system clock configuration for RUN mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_SetRunModeSysClkConfig(const scg_sys_clk_config_t *config)
{
    assert(config);
    union
    {
        const uint32_t *configInt;
        const scg_sys_clk_config_t *configPtr;
    } Config;

    Config.configPtr = config;
    SCG->RCCR        = *(Config.configInt);
}

/*!
 * @brief Sets the system clock configuration for HSRUN mode.
 *
 * This function sets the system clock configuration for HSRUN mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_SetHsrunModeSysClkConfig(const scg_sys_clk_config_t *config)
{
    assert(config);
    union
    {
        const uint32_t *configInt;
        const scg_sys_clk_config_t *configPtr;
    } Config;

    Config.configPtr = config;
    SCG->HCCR        = *(Config.configInt);
}

/*!
 * @brief Gets the system clock configuration in the current power mode.
 *
 * This function gets the system configuration in the current power mode.
 *
 * @param config Pointer to the configuration.
 */
static inline void CLOCK_GetCurSysClkConfig(scg_sys_clk_config_t *config)
{
    assert(config);

    uint32_t tempCsr;

    union
    {
        uint32_t *configInt;
        scg_sys_clk_config_t *configPtr;
    } Config;

    Config.configPtr = config;
    
    /*
       Errata: ERR010777
       Workaround: Read SCG->CSR twice in a loop to ensure system clock
       switch has completed.
     */
    do
    {
        tempCsr = SCG->CSR;
        *(Config.configInt) = SCG->CSR;
    } while (tempCsr != *(Config.configInt));
}

/*!
 * @brief Sets the clock out selection.
 *
 * This function sets the clock out selection (CLKOUTSEL).
 *
 * @param setting The selection to set.
 * @return  The current clock out selection.
 */
static inline void CLOCK_SetClkOutSel(clock_clkout_src_t setting)
{
    SCG->CLKOUTCNFG = SCG_CLKOUTCNFG_CLKOUTSEL(setting);
}
/* @} */

/*!
 * @name SCG System OSC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG system OSC.
 *
 * This function enables the SCG system OSC clock according to the
 * configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success System OSC is initialized.
 * @retval kStatus_SCG_Busy System OSC has been enabled and is used by the system clock.
 * @retval kStatus_ReadOnly System OSC control register is locked.
 *
 * @note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitSysOsc(const scg_sosc_config_t *config);

/*!
 * @brief De-initializes the SCG system OSC.
 *
 * This function disables the SCG system OSC clock.
 *
 * @retval kStatus_Success System OSC is deinitialized.
 * @retval kStatus_SCG_Busy System OSC is used by the system clock.
 * @retval kStatus_ReadOnly System OSC control register is locked.
 *
 * @note This function can't detect whether the system OSC is used by an IP.
 */
status_t CLOCK_DeinitSysOsc(void);

/*!
 * @brief Set the asynchronous clock divider.
 *
 * @param asyncClk Which asynchronous clock to configure.
 * @param divider The divider value to set.
 *
 * @note There might be glitch when changing the asynchronous divider, so make sure
 * the asynchronous clock is not used while changing divider.
 */
static inline void CLOCK_SetSysOscAsyncClkDiv(scg_async_clk_t asyncClk, scg_async_clk_div_t divider)
{
    uint32_t reg = SCG->SOSCDIV;

    switch (asyncClk)
    {
        case kSCG_AsyncDiv2Clk:
            reg = (reg & ~SCG_SOSCDIV_SOSCDIV2_MASK) | SCG_SOSCDIV_SOSCDIV2(divider);
            break;
        default:
            reg = (reg & ~SCG_SOSCDIV_SOSCDIV1_MASK) | SCG_SOSCDIV_SOSCDIV1(divider);
            break;
    }

    SCG->SOSCDIV = reg;
}

/*!
 * @brief Gets the SCG system OSC clock frequency (SYSOSC).
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSysOscFreq(void);

/*!
 * @brief Gets the SCG asynchronous clock frequency from the system OSC.
 *
 * @param type     The asynchronous clock type.
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSysOscAsyncFreq(scg_async_clk_t type);

/*!
 * @brief Checks whether the system OSC clock error occurs.
 *
 * @return  True if the error occurs, false if not.
 */
static inline bool CLOCK_IsSysOscErr(void)
{
    return (bool)(SCG->SOSCCSR & SCG_SOSCCSR_SOSCERR_MASK);
}

/*!
 * @brief Clears the system OSC clock error.
 */
static inline void CLOCK_ClearSysOscErr(void)
{
    SCG->SOSCCSR |= SCG_SOSCCSR_SOSCERR_MASK;
}

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
static inline void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode)
{
    uint32_t reg = SCG->SOSCCSR;

    reg &= ~(SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG->SOSCCSR = reg;
}

/*!
 * @brief Checks whether the system OSC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsSysOscValid(void)
{
    return (bool)(SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK);
}
/* @} */

/*!
 * @name SCG Slow IRC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG slow IRC clock.
 *
 * This function enables the SCG slow IRC clock according to the
 * configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success SIRC is initialized.
 * @retval kStatus_SCG_Busy SIRC has been enabled and is used by system clock.
 * @retval kStatus_ReadOnly SIRC control register is locked.
 *
 * @note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitSirc(const scg_sirc_config_t *config);

/*!
 * @brief De-initializes the SCG slow IRC.
 *
 * This function disables the SCG slow IRC.
 *
 * @retval kStatus_Success SIRC is deinitialized.
 * @retval kStatus_SCG_Busy SIRC is used by system clock.
 * @retval kStatus_ReadOnly SIRC control register is locked.
 *
 * @note This function can't detect whether the SIRC is used by an IP.
 */
status_t CLOCK_DeinitSirc(void);

/*!
 * @brief Set the asynchronous clock divider.
 *
 * @param asyncClk Which asynchronous clock to configure.
 * @param divider The divider value to set.
 *
 * @note There might be glitch when changing the asynchronous divider, so make sure
 * the asynchronous clock is not used while changing divider.
 */
static inline void CLOCK_SetSircAsyncClkDiv(scg_async_clk_t asyncClk, scg_async_clk_div_t divider)
{
    uint32_t reg = SCG->SIRCDIV;

    switch (asyncClk)
    {
        case kSCG_AsyncDiv2Clk:
            reg = (reg & ~SCG_SIRCDIV_SIRCDIV2_MASK) | SCG_SIRCDIV_SIRCDIV2(divider);
            break;
        default:
            reg = (reg & ~SCG_SIRCDIV_SIRCDIV1_MASK) | SCG_SIRCDIV_SIRCDIV1(divider);
            break;
    }

    SCG->SIRCDIV = reg;
}

/*!
 * @brief Gets the SCG SIRC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSircFreq(void);

/*!
 * @brief Gets the SCG asynchronous clock frequency from the SIRC.
 *
 * @param type     The asynchronous clock type.
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSircAsyncFreq(scg_async_clk_t type);

/*!
 * @brief Checks whether the SIRC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsSircValid(void)
{
    return (bool)(SCG->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK);
}
/* @} */

/*!
 * @name SCG Fast IRC Clock.
 * @{
 */

/*!
 * @brief Initializes the SCG fast IRC clock.
 *
 * This function enables the SCG fast IRC clock according to the configuration.
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success FIRC is initialized.
 * @retval kStatus_SCG_Busy FIRC has been enabled and is used by the system clock.
 * @retval kStatus_ReadOnly FIRC control register is locked.
 *
 * @note This function can't detect whether the FIRC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitFirc(const scg_firc_config_t *config);

/*!
 * @brief De-initializes the SCG fast IRC.
 *
 * This function disables the SCG fast IRC.
 *
 * @retval kStatus_Success FIRC is deinitialized.
 * @retval kStatus_SCG_Busy FIRC is used by the system clock.
 * @retval kStatus_ReadOnly FIRC control register is locked.
 *
 * @note This function can't detect whether the FIRC is used by an IP.
 */
status_t CLOCK_DeinitFirc(void);

/*!
 * @brief Set the asynchronous clock divider.
 *
 * @param asyncClk Which asynchronous clock to configure.
 * @param divider The divider value to set.
 *
 * @note There might be glitch when changing the asynchronous divider, so make sure
 * the asynchronous clock is not used while changing divider.
 */
static inline void CLOCK_SetFircAsyncClkDiv(scg_async_clk_t asyncClk, scg_async_clk_div_t divider)
{
    uint32_t reg = SCG->FIRCDIV;

    switch (asyncClk)
    {
        case kSCG_AsyncDiv2Clk:
            reg = (reg & ~SCG_FIRCDIV_FIRCDIV2_MASK) | SCG_FIRCDIV_FIRCDIV2(divider);
            break;
        default:
            reg = (reg & ~SCG_FIRCDIV_FIRCDIV1_MASK) | SCG_FIRCDIV_FIRCDIV1(divider);
            break;
    }

    SCG->FIRCDIV = reg;
}

/*!
 * @brief Gets the SCG FIRC clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetFircFreq(void);

/*!
 * @brief Gets the SCG asynchronous clock frequency from the FIRC.
 *
 * @param type     The asynchronous clock type.
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetFircAsyncFreq(scg_async_clk_t type);

/*!
 * @brief Checks whether the FIRC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsFircValid(void)
{
    return (bool)(SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK);
}
/* @} */

/*!
 * @name SCG System PLL Clock.
 * @{
 */

/*!
 * @brief Calculates the MULT and PREDIV for the PLL.
 *
 * This function calculates the proper MULT and PREDIV to generate the desired PLL
 * output frequency with the input reference clock frequency. It returns the closest
 * frequency match that the PLL can generate. The corresponding MULT/PREDIV are returned with
 * parameters. If the desired frequency is not valid, this function returns 0.
 *
 * @param refFreq     The input reference clock frequency.
 * @param desireFreq  The desired output clock frequency.
 * @param mult        The value of MULT.
 * @param prediv      The value of PREDIV.
 * @return The PLL output frequency with the MULT and PREDIV; If
 * the desired frequency can't be generated, this function returns 0U.
 */
uint32_t CLOCK_GetSysPllMultDiv(uint32_t refFreq, uint32_t desireFreq, uint8_t *mult, uint8_t *prediv);

/*!
 * @brief Initializes the SCG system PLL.
 *
 * This function enables the SCG system PLL clock according to the
 * configuration. The system PLL can use the system OSC or FIRC as
 * the clock source. Ensure that the source clock is valid before
 * calling this function.
 *
 * Example code for initializing SPLL clock output:
 * @code
 * const scg_spll_config_t g_scgSysPllConfig = {.enableMode = kSCG_SysPllEnable,
 *                                            .monitorMode = kSCG_SysPllMonitorDisable,
 *                                            .div1 = kSCG_AsyncClkDivBy1,
 *                                            .div2 = kSCG_AsyncClkDisable,
 *                                            .div3 = kSCG_AsyncClkDivBy2,
 *                                            .src = kSCG_SysPllSrcFirc,
 *                                            .isBypassSelected = false,
 *                                            .isPfdSelected = false,
 *                                            .prediv = 5U,
 *                                            .pfdClkout = kSCG_AuxPllPfd0Clk,
 *                                            .mult = 20U,
 *                                            .pllPostdiv1 = kSCG_SysClkDivBy3,
 *                                            .pllPostdiv2 = kSCG_SysClkDivBy4};
 * CLOCK_InitSysPll(&g_scgSysPllConfig);
 * @endcode
 *
 * @param config   Pointer to the configuration structure.
 * @retval kStatus_Success System PLL is initialized.
 * @retval kStatus_SCG_Busy System PLL has been enabled and is used by the system clock.
 * @retval kStatus_ReadOnly System PLL control register is locked.
 *
 * @note This function can't detect whether the system PLL has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitSysPll(const scg_spll_config_t *config);

/*!
 * @brief De-initializes the SCG system PLL.
 *
 * This function disables the SCG system PLL.
 *
 * @retval kStatus_Success system PLL is deinitialized.
 * @retval kStatus_SCG_Busy system PLL is used by the system clock.
 * @retval kStatus_ReadOnly System PLL control register is locked.
 *
 * @note This function can't detect whether the system PLL is used by an IP.
 */
status_t CLOCK_DeinitSysPll(void);

/*!
 * @brief Set the asynchronous clock divider.
 *
 * @param asyncClk Which asynchronous clock to configure.
 * @param divider The divider value to set.
 *
 * @note There might be glitch when changing the asynchronous divider, so make sure
 * the asynchronous clock is not used while changing divider.
 */
static inline void CLOCK_SetSysPllAsyncClkDiv(scg_async_clk_t asyncClk, scg_async_clk_div_t divider)
{
    uint32_t reg = SCG->SPLLDIV;

    switch (asyncClk)
    {
        case kSCG_AsyncDiv2Clk:
            reg = (reg & ~SCG_SPLLDIV_SPLLDIV2_MASK) | SCG_SPLLDIV_SPLLDIV2(divider);
            break;
        default:
            reg = (reg & ~SCG_SPLLDIV_SPLLDIV1_MASK) | SCG_SPLLDIV_SPLLDIV1(divider);
            break;
    }

    SCG->SPLLDIV = reg;
}

/*!
 * @brief Gets the SCG system PLL clock frequency.
 *
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSysPllFreq(void);

/*!
 * @brief Gets the SCG asynchronous clock frequency from the system PLL.
 *
 * @param type     The asynchronous clock type.
 * @return  Clock frequency; If the clock is invalid, returns 0.
 */
uint32_t CLOCK_GetSysPllAsyncFreq(scg_async_clk_t type);

/*!
 * @brief Checks whether the system PLL clock error occurs.
 *
 * @return  True if an error occurs, false if not.
 */
static inline bool CLOCK_IsSysPllErr(void)
{
    return (bool)(SCG->SPLLCSR & SCG_SPLLCSR_SPLLERR_MASK);
}

/*!
 * @brief Clears the system PLL clock error.
 */
static inline void CLOCK_ClearSysPllErr(void)
{
    SCG->SPLLCSR |= SCG_SPLLCSR_SPLLERR_MASK;
}

/*!
 * @brief Sets the system PLL monitor mode.
 *
 * This function sets the system PLL monitor mode. The mode can be disabled.
 * It can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
static inline void CLOCK_SetSysPllMonitorMode(scg_spll_monitor_mode_t mode)
{
    uint32_t reg = SCG->SPLLCSR;

    reg &= ~(SCG_SPLLCSR_SPLLCM_MASK | SCG_SPLLCSR_SPLLCMRE_MASK);

    reg |= (uint32_t)mode;

    SCG->SPLLCSR = reg;
}

/*!
 * @brief Checks whether the system PLL clock is valid.
 *
 * @return  True if the clock is valid, false if not.
 */
static inline bool CLOCK_IsSysPllValid(void)
{
    return (bool)(SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK);
}
/* @} */

/*!
 * @name External clock frequency
 * @{
 */

/*!
 * @brief Sets the XTAL0 frequency based on board settings.
 *
 * @param freq The XTAL0/EXTAL0 input clock frequency in Hz.
 */
static inline void CLOCK_SetXtal0Freq(uint32_t freq)
{
    g_xtal0Freq = freq;
}

/* @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
