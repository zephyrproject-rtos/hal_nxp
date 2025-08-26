/*
 * Copyright 2022-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_system.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define kFREQMEAS_target_clock_32MHz_XTAL (0U)

/* Typical values from datasheet */
#define STEPSIZE_1MHZ_FRO_PPM  (5000)
#define STEPSIZE_12MHZ_FRO_PPM (1200)
#define STEPSIZE_32KHZ_FRO_PPM (2000)
#define FREQ_1MHZ              (1000000)
#define FREQ_12MHZ             (12000000)
#define FREQ_32MHZ             (32000000)
#define FREQ_32KHZ             (32768)
#define STEPSIZE_1MHZ          (int32_t)((STEPSIZE_1MHZ_FRO_PPM * (int64_t)FREQ_1MHZ) / 1000000)
#define STEPSIZE_12MHZ         (int32_t)((STEPSIZE_12MHZ_FRO_PPM * (int64_t)FREQ_12MHZ) / 1000000)
#define STEPSIZE_32KHZ         ((STEPSIZE_32KHZ_FRO_PPM * FREQ_32KHZ) / 1000000)
#define RTC_TARGET_1KHZ        (993)
#define RTC_TARGET_1HZ         (1)

#define PMC_RTCOSC32K_CLK1KHZDIV_MAX    (PMC_RTCOSC32K_CLK1KHZDIV_MASK >> PMC_RTCOSC32K_CLK1KHZDIV_SHIFT)
#define PMC_RTCOSC32K_CLK1KHZDIV_MIN    (0)
#define PMC_RTCOSC32K_CLK1HZDIV_MAX     (PMC_RTCOSC32K_CLK1HZDIV_MASK >> PMC_RTCOSC32K_CLK1HZDIV_SHIFT)
#define PMC_RTCOSC32K_CLK1HZDIV_MIN     (0)
#define PMC_RTCOSC32K_CLK1KHZDIV_OFFSET (28)
#define PMC_RTCOSC32K_CLK1HZDIV_OFFSET  (31744)

/*******************************************************************************
 * Variables
 ******************************************************************************/

static const uint32_t s_freqMeasureRefTimeThreshold[kFREQMEAS_count] = {
    /*ppm 32.768kHz  ppm 12MHz  ppm 1MHz*/
    0xffffffff, /*  0 */
    0xffffffff, /*  1 */
    0xffffffff, /*  2 */
    0xffffffff, /*  3 */
    0xffffffff, /*  4 */
    0xffffffff, /*  5 */
    0xffffffff, /*  6 */
    250000,     /*  kFREQMEAS_ref_time_exp_7                            20833      250000 */
    125000,     /*  kFREQMEAS_ref_time_exp_8                            10417      125000 */
    62500,      /*  kFREQMEAS_ref_time_exp_9                            5208       62500  */
    31250,      /*  kFREQMEAS_ref_time_exp_10               953674      2604       31250  */
    15625,      /*  kFREQMEAS_ref_time_exp_11               476837      1302       15625  */
    7813,       /*  kFREQMEAS_ref_time_exp_12               238419      651        7813   */
    3906,       /*  kFREQMEAS_ref_time_exp_13               119209      326        3906   */
    1953,       /*  kFREQMEAS_ref_time_exp_14               59605       163        1953   */
    977,        /*  kFREQMEAS_ref_time_exp_15               29802       81         977    */
    488,        /*  kFREQMEAS_ref_time_exp_16               14901       41         488    */
    244,        /*  kFREQMEAS_ref_time_exp_17               7451        20         244    */
    122,        /*  kFREQMEAS_ref_time_exp_18               3725        10         122    */
    61,         /*  kFREQMEAS_ref_time_exp_19               1863        5          61     */
    31,         /*  kFREQMEAS_ref_time_exp_20               931         3          31     */
    15,         /*  kFREQMEAS_ref_time_exp_21               466         1          15     */
    8,          /*  kFREQMEAS_ref_time_exp_22               233         1          8      */
    4,          /*  kFREQMEAS_ref_time_exp_23               116         0          4      */
    2,          /*  kFREQMEAS_ref_time_exp_24               58          0          2      */
    1,          /*  kFREQMEAS_ref_time_exp_25               29          0          1      */
    0,          /*  kFREQMEAS_ref_time_exp_26               15          0          0      */
    0,          /*  kFREQMEAS_ref_time_exp_27               7           0          0      */
    0,          /*  kFREQMEAS_ref_time_exp_28               4           0          0      */
    0,          /*  kFREQMEAS_ref_time_exp_29               2           0          0      */
    0,          /*  kFREQMEAS_ref_time_exp_30               1           0          0      */
    0           /*  kFREQMEAS_ref_time_exp_31               0           0          0      */
};

/**
 * @brief Count clock cycles for frequency measurement
 * 
 * @param targetClock Target clock to measure (e.g., kFREQMEAS_target_clock_32kHz_FRO)
 * @param refClockPowerOf2Cycles Exponent for reference clock cycles (2^N)
 * @return uint32_t Measured cycle count
 * 
 * @note Saves/restores peripheral registers to avoid side effects
 */
static uint32_t CountClockCycles(freq_meas_target_clock_t targetClock,
                            freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    /* Save relevant potentially altered registers */
    uint32_t pdruncfg0        = PMC->PDRUNCFG0;
    uint32_t sysconClockCtrl = SYSCON->CLOCK_CTRL;
    uint32_t AHBClkCtrl0      = SYSCON->AHBCLKCTRL.AHBCLKCTRL0; /* For CLOCK_EnableClock functions */
    uint32_t AHBClkCtrl1      = SYSCON->AHBCLKCTRL.AHBCLKCTRL1; /* For CLOCK_EnableClock functions */
    uint32_t AHBClkCtrl2      = SYSCON->AHBCLKCTRL.AHBCLKCTRL2; /* For CLOCK_EnableClock functions */

    /* Enable BLE clock / CLKIN clock / 32MHz XTAL clock if not enabled yet */
    PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_BLE_MASK;

#define BLE_STATE ((PMC->STATUS & PMC_STATUS_FSMBLESTATE_MASK) >> PMC_STATUS_FSMBLESTATE_SHIFT)
    while ((BLE_STATE != 2) && (BLE_STATE != 6)) /* most probably not required seen the delays above */
    {
    } /* Wait until 32 MHz xtal osc is active */
    SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_XTAL32MHZ_FREQM_ENA_MASK;

    CLOCK_EnableClock(kCLOCK_Freqme);
    CLOCK_EnableClock(kCLOCK_InputMux);
    CLOCK_EnableClock(kCLOCK_AnalogCtrl);

    /* Use 32MHZ_XTAL as reference.  Note: e.g 32.768kHz FRO: duration can be halved for same resolution (tested on
     * FPGA) by swapping ref with target, but duration needs to be re-calculated */
    INPUTMUX->FREQMEAS_REF = kFREQMEAS_target_clock_32MHz_XTAL << INPUTMUX_FREQMEAS_REF_CLKIN_SHIFT;

    INPUTMUX->FREQMEAS_TARGET = targetClock << INPUTMUX_FREQMEAS_TARGET_CLKIN_SHIFT;
    /* Set scale and start measurement (must be done in one go, cannot use read-modify-write as read and write point to
     * different physical registers) */
    ANACTRL->FREQ_ME_CTRL =
        ANACTRL_FREQ_ME_CTRL_PROG_MASK | (refClockPowerOf2Cycles << ANACTRL_FREQ_ME_CTRL_CAPVAL_SCALE_SHIFT);
    /* wait till measurement done - should take 2^refClockPowerOf2Cycles-1 ref clock cycles -  2.05 ms */
    while (ANACTRL->FREQ_ME_CTRL & ANACTRL_FREQ_ME_CTRL_PROG_MASK)
        ;
    /* Now get the value */
    uint32_t val = ANACTRL->FREQ_ME_CTRL;
    if (val > 0)
    {
        val += 1; /* I guess you have to add one because of ...  hw sync delay of start signal maybe? */
    }
    /* Restore relevant potentially altered registers */
    SYSCON->AHBCLKCTRL.AHBCLKCTRL0 = AHBClkCtrl0;
    SYSCON->AHBCLKCTRL.AHBCLKCTRL1 = AHBClkCtrl1;
    SYSCON->AHBCLKCTRL.AHBCLKCTRL2 = AHBClkCtrl2;
    SYSCON->CLOCK_CTRL             = sysconClockCtrl;
    PMC->PDRUNCFG0                 = pdruncfg0;

    return val;
}

/**
 * @brief Measure and calibrate the 32kHz FRO clock frequency
 * 
 * @param refClockPowerOf2Cycles Measurement duration exponent (2^N cycles)
 * 
 */
static void MeasureAndCorrect32kHzFRO(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t capcal = (PMC->FRO32K & PMC_FRO32K_CAPCAL_MASK) >> PMC_FRO32K_CAPCAL_SHIFT;
    uint32_t freq   = SYSTEM_MeasureFrequency(kFREQMEAS_target_clock_32kHz_FRO, refClockPowerOf2Cycles);
    /* Error calculation */
    int32_t error = freq - FREQ_32KHZ;

    /*
     * some rules:
     * -1- do not correct when below measurement accuracy
     * -2- subtract half of the measurement accuracy to not make things worse
     * -3- do not correct below 1/2 step
     */
    if (abs(error) > s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles]) /* rule -1- */
    {
        int32_t correction;
        if (error > 0)
        {
            error -= (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);       /* rule -2- */ 
            correction = (error + STEPSIZE_32KHZ / 2) / STEPSIZE_32KHZ; /* rule -3- */
        }
        else
        {
            error += (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);       /* rule -2- */
            correction = (error - STEPSIZE_32KHZ / 2) / STEPSIZE_32KHZ; /* rule -3- */
        }
        /* Do correction */
        capcal          = (uint32_t)((int32_t)capcal + correction);
        uint32_t fro32k = PMC->FRO32K;
        fro32k &= ~(PMC_FRO32K_CAPCAL_MASK);
        fro32k |= PMC_FRO32K_CAPCAL(capcal);
        PMC->FRO32K = fro32k;
    }
}

/*!
 * @brief Measures frequency of 32.768kHz FRO referenced to 32MHz XTAL oscillator and corrects RTC dividers.
 * Correction aims to be as close as possible to targets 1Hz and 32768/33 = 993Hz.
 *
 * @param refClockPowerOf2Cycles Measurement duration exponent
 */
static void MeasureAndCorrect32kHzRTCdividers(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t val = CountClockCycles(kFREQMEAS_target_clock_32kHz_FRO, refClockPowerOf2Cycles);
    /* Calculate frequency in mHz */
    int32_t freqMHz = (int32_t)(((uint64_t)val * FREQ_32MHZ * 1000) / ((1 << refClockPowerOf2Cycles) - 1));

    int32_t setting1kHz =
        (freqMHz + RTC_TARGET_1KHZ * (1000 / 2)) / (RTC_TARGET_1KHZ * 1000) - PMC_RTCOSC32K_CLK1KHZDIV_OFFSET;
    if (setting1kHz < PMC_RTCOSC32K_CLK1KHZDIV_MIN)
        setting1kHz = PMC_RTCOSC32K_CLK1KHZDIV_MIN;
    if (setting1kHz > PMC_RTCOSC32K_CLK1KHZDIV_MAX)
        setting1kHz = PMC_RTCOSC32K_CLK1KHZDIV_MAX;

    int32_t setting1Hz =
        (freqMHz + RTC_TARGET_1HZ * (1000 / 2)) / (RTC_TARGET_1HZ * 1000) - PMC_RTCOSC32K_CLK1HZDIV_OFFSET;
    if (setting1Hz < PMC_RTCOSC32K_CLK1HZDIV_MIN)
        setting1Hz = PMC_RTCOSC32K_CLK1HZDIV_MIN;
    if (setting1Hz > PMC_RTCOSC32K_CLK1HZDIV_MAX)
        setting1Hz = PMC_RTCOSC32K_CLK1HZDIV_MAX;

    /* Do correction */
    uint32_t rtcosc32k = PMC->RTCOSC32K;
    rtcosc32k &= ~(PMC_RTCOSC32K_CLK1KHZDIV_MASK | PMC_RTCOSC32K_CLK1HZDIV_MASK);
    rtcosc32k |= (PMC_RTCOSC32K_CLK1KHZDIV(setting1kHz) | PMC_RTCOSC32K_CLK1HZDIV(setting1Hz));
    PMC->RTCOSC32K = rtcosc32k;
}

/*!
 * @brief Measures 12MHz FRO output and corrects frequency of 192MHz FRO referenced to 32MHz XTAL oscillator.
 *
 * @param refClockPowerOf2Cycles Measurement duration exponent
 */
static void MeasureAndCorrect12MHzFRO(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t curdac = (PMC->FRO192M & PMC_FRO192M_CUR_DAC_MASK) >>
                      PMC_FRO192M_CUR_DAC_SHIFT; /* fine, 8 bits, increase value is increase frequency, 1 step = 215 kHz
                                                    on 192MHz or 0.12% */
    uint32_t freq = SYSTEM_MeasureFrequency(kFREQMEAS_target_clock_12_24_32MHz_FRO, refClockPowerOf2Cycles);
    /* Error calculation */
    int32_t error = freq - FREQ_12MHZ;

    /*
     * some rules:
     * -1- do not correct when below measurement accuracy
     * -2- subtract half of the measurement accuracy to not make things worse
     * -3- do not correct below 1/2 step
     */
    if (abs(error) > s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles]) /* rule -1- */
    {
        int32_t correction;
        if (error > 0)
        {
            error -= (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);       /* rule -2- */ 
            correction = (error + STEPSIZE_12MHZ / 2) / STEPSIZE_12MHZ; /* rule -3- */
        }
        else
        {
            error += (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);      /* rule -2- */ 
            correction = (error - STEPSIZE_12MHZ / 2) / STEPSIZE_12MHZ; /* rule -3- */
        }
        /* Do fine correction */
        curdac           = (uint32_t)((int32_t)curdac - correction);
        uint32_t fro192m = PMC->FRO192M;
        fro192m &= ~(PMC_FRO192M_CUR_DAC_MASK);
        fro192m |= PMC_FRO192M_CUR_DAC(curdac);
        PMC->FRO192M = fro192m;
    }
}

/*!
 * @brief Measures and corrects frequency of 1MHz FRO referenced to 32MHz XTAL oscillator.
 *
 * @param refClockPowerOf2Cycles Measurement duration exponent
 */
static void MeasureAndCorrect1MHzFRO(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t freqsel = (PMC->FRO1M & PMC_FRO1M_FREQSEL_MASK) >>
                       PMC_FRO1M_FREQSEL_SHIFT; /* 7 bits, increase value is increase frequency */
    uint32_t freq = SYSTEM_MeasureFrequency(kFREQMEAS_target_clock_1MHz_FRO, refClockPowerOf2Cycles);
    /* Error calculation */
    int32_t error = (int32_t)freq - FREQ_1MHZ;
    /*
     * some rules:
     * -1- do not correct when below measurement accuracy
     * -2- subtract half of the measurement accuracy to not make things worse
     * -3- do not correct below 1/2 step
     */
    if (abs(error) > s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles]) /* rule -1- */
    {
        int32_t correction;
        if (error > 0)
        {
            error -= (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);    /* rule -2- */ 
            correction = (error + STEPSIZE_1MHZ / 2) / STEPSIZE_1MHZ; /* rule -3- */
        }
        else
        {
            error += (s_freqMeasureRefTimeThreshold[refClockPowerOf2Cycles] >> 1);     /* rule -2- */ 
            correction = (error - STEPSIZE_1MHZ / 2) / STEPSIZE_1MHZ; /* rule -3- */
        }
        /* Do correction */
        freqsel        = (uint32_t)((int32_t)freqsel + correction);
        uint32_t fro1m = PMC->FRO1M;
        fro1m &= ~(PMC_FRO1M_FREQSEL_MASK);
        fro1m |= PMC_FRO1M_FREQSEL(freqsel);
        PMC->FRO1M = fro1m;
    }
}

/*******************************************************************************
 * Functions
 ******************************************************************************/
/**
 * @brief Measure 32kHz FRO frequency with high accuracy (returns mHz)
 * 
 * @param refClockPowerOf2Cycles Measurement duration exponent
 * @return uint32_t Frequency in millihertz (mHz)
 * 
 * @note Uses 32MHz XTAL as reference clock
 */
 uint32_t SYSTEM_MeasureFrequency32kHzAccurate(freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t freqMHz = 0;

    /* Save relevant potentially altered registers */
    uint32_t pdruncfg0            = PMC->PDRUNCFG0;
    uint32_t sysconClockCtrl     = SYSCON->CLOCK_CTRL;
    uint32_t savedSystemCoreClock = SystemCoreClock;

    /* Enable BLE clock / CLKIN clock / 32MHz XTAL clock already here to gain time */
    PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_BLE_MASK;

    uint32_t val = CountClockCycles(kFREQMEAS_target_clock_32kHz_FRO, refClockPowerOf2Cycles);
    /* Calculate frequency in mHz */
    freqMHz = (uint32_t)(((uint64_t)val * FREQ_32MHZ * 1000) / ((1 << refClockPowerOf2Cycles) - 1));

    /* Restore relevant potentially altered registers */
    SystemCoreClock    = savedSystemCoreClock;
    SYSCON->CLOCK_CTRL = sysconClockCtrl;
    PMC->PDRUNCFG0     = pdruncfg0;

    return freqMHz;
}

/**
 * @brief Measure clock frequency in Hz
 * 
 * @param targetClock Clock to measure (see freq_meas_target_clock_t)
 * @param refClockPowerOf2Cycles Measurement duration exponent
 * @return uint32_t Frequency in Hz
 */
uint32_t SYSTEM_MeasureFrequency(freq_meas_target_clock_t targetClock,
                                 freq_meas_ref_time_exponent_t refClockPowerOf2Cycles)
{
    uint32_t freq = 0;

    /* Save relevant potentially altered registers */
    uint32_t pdruncfg0            = PMC->PDRUNCFG0;
    uint32_t sysconClockCtrl     = SYSCON->CLOCK_CTRL;
    uint32_t pmcRTCOsc32k         = PMC->RTCOSC32K;
    uint32_t fro192MCtrl         = ANACTRL->FRO192M_CTRL;
    uint32_t savedSystemCoreClock = SystemCoreClock;
    uint32_t val;

    /* Enable BLE clock / CLKIN clock / 32MHz XTAL clock already here to gain time */
    PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_BLE_MASK;

    if (targetClock == kFREQMEAS_target_clock_32kHz_FRO)
    {
        PMC->PDRUNCFG0 &= ~(PMC_PDRUNCFG0_PDEN_FRO32K_MASK);
        SDK_DelayAtLeastUs(100, SystemCoreClock);                      /* startup time of FRO32kHz? spec: max 100us to be within +/-2.2% */
        PMC->RTCOSC32K |= PMC_RTCOSC32K_SEL(0); /* use 32 kHz fro as 32k osc */
        SDK_DelayAtLeastUs(100, SystemCoreClock);                      /* delay 3 32kHz cycles to switch (and increase accuracy) */
    }
    else if (targetClock == kFREQMEAS_target_clock_12_24_32MHz_FRO)
    {
        PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_FRO192M_MASK;
        SDK_DelayAtLeastUs(100, SystemCoreClock); /* startup time of FRO192MHz? spec: 15us time it takes to release clock after enable */
        ANACTRL->FRO192M_CTRL = fro192MCtrl | ANACTRL_FRO192M_CTRL_ENA_12MHZCLK_MASK;
        SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_FRO12MHZ_FREQM_ENA_MASK;
    }
    else if (targetClock == kFREQMEAS_target_clock_1MHz_FRO)
    {
        PMC->PDRUNCFGCLR0 = PMC_PDRUNCFG0_PDEN_FRO1M_MASK;
        SDK_DelayAtLeastUs(2000, SystemCoreClock); /* startup time of FRO1MHz?  spec: 25us till 10% of final value.
        From experiments: 2000us is ok  1500 nok  this is with PMC running on 1MHz FRO which is already running -
        probably ldo stabilization time after previous activity
        200us FRO startup time measured to stabilize within one correction step when PMC is running on 12MHz */
        SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_FRO1MHZ_UTICK_ENA_MASK; /* really needed? Yes! */
        SYSCON->CLOCK_CTRL |= SYSCON_CLOCK_CTRL_FRO1MHZ_CLK_ENA_MASK;
    }
    else
    {
        goto func_exit;
    }

    val = CountClockCycles(targetClock, refClockPowerOf2Cycles);

    /* Calculate frequency in Hz */
    freq = (uint32_t)(((uint64_t)val * FREQ_32MHZ) / ((1 << refClockPowerOf2Cycles) - 1));

func_exit:
    /* Restore relevant potentially altered registers */
    SystemCoreClock       = savedSystemCoreClock;
    ANACTRL->FRO192M_CTRL = fro192MCtrl;
    PMC->RTCOSC32K        = pmcRTCOsc32k;
    SYSCON->CLOCK_CTRL    = sysconClockCtrl;
    PMC->PDRUNCFG0        = pdruncfg0;

    return freq;
}

/*!
 * @brief Calibrates clock referenced to 32MHz XTAL oscillator using a successive calibration algorithm for large
 * deviations.
 *
 * @param targetClock Clock to calibrate (32kHz/12MHz/1MHz FRO)
 */
void SYSTEM_CalibrateClock(freq_meas_target_clock_t targetClock)
{
    /*
     * successive approximation algorithm:
     *  - start with a short coarse measurement of the error
     *  - gradually go finer each step
     */
    if (targetClock == kFREQMEAS_target_clock_32kHz_FRO)
    {
        /*
         *  - This works when the deviation of capcal from 0.2% is not too big.  If not we have to review this.
         */
        MeasureAndCorrect32kHzFRO(kFREQMEAS_ref_time_exp_17);
        MeasureAndCorrect32kHzFRO(kFREQMEAS_ref_time_exp_18);
        MeasureAndCorrect32kHzFRO(kFREQMEAS_ref_time_exp_19);
        MeasureAndCorrect32kHzFRO(kFREQMEAS_ref_time_exp_20); /* 33 ms measurement */
    }
    else if (targetClock == kFREQMEAS_target_clock_12_24_32MHz_FRO)
    {
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_7);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_8);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_9);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_10);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_11);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_12);
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_13);
    }
    else if (targetClock == kFREQMEAS_target_clock_1MHz_FRO)
    {
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_7);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_8);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_9);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_10);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_11);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_12);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_13);
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_14);
    }
}

/*!
 * @brief Calibrates clock referenced to 32MHz XTAL oscillator for small deviations.
 *
 * @param targetClock Clock to calibrate
 */
void SYSTEM_CalibrateClockFine(freq_meas_target_clock_t targetClock)
{
    if (targetClock == kFREQMEAS_target_clock_32kHz_FRO)
    {
        MeasureAndCorrect32kHzFRO(kFREQMEAS_ref_time_exp_20);
    }
    else if (targetClock == kFREQMEAS_target_clock_12_24_32MHz_FRO)
    {
        MeasureAndCorrect12MHzFRO(kFREQMEAS_ref_time_exp_13);
    }
    else if (targetClock == kFREQMEAS_target_clock_1MHz_FRO)
    {
        MeasureAndCorrect1MHzFRO(kFREQMEAS_ref_time_exp_14);
    }
}

/*!
 * @brief Calibrates RTC clock dividers referenced to 32MHz XTAL oscillator
 *
 * @param None
 */
void SYSTEM_CalibrateRTCClockDividers(void)
{
    MeasureAndCorrect32kHzRTCdividers(kFREQMEAS_ref_time_exp_27); /* 4224 ms measurement - 7 ppm*/
}

/*!
 * @brief Assembles chip version from Flash and/or hardware registers
 *
 * @return chip version.
 */
chip_version_t SYSTEM_GetChipVersion(void)
{
    chip_version_t chipVersion = kCHIPVERSION_UNKNOWN;
    uint32_t metalFixNr        = ((uint32_t)FLASH_NMPA->GPO1.GPO1_0 & FLASH_NMPA_GPO1_0_METAL_REVISION_ID_MASK) >>
                          FLASH_NMPA_GPO1_0_METAL_REVISION_ID_SHIFT;
    chipVersion = (chip_version_t)(metalFixNr | 0xA0);
    return chipVersion;
}

/**
 * @brief Get device type information
 * 
 * @param[out] typeNr Device type number
 * @param[out] securityEnabled Security feature status
 * @param[out] packageType Chip package type
 * @param[out] nrOfPins Number of pins
 */
void SYSTEM_GetDeviceType(uint16_t *typeNr, bool *securityEnabled, chip_package_type_t *packageType, uint8_t *nrOfPins)
{
    FLASH_NMPA_Type *nmpa = ((FLASH_NMPA_Type *)(FLASH_NMPA_BASE));
    *typeNr               = (uint16_t)((nmpa->DEVICE_TYPE & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK) >>
                         FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT);
    *securityEnabled      = (bool)((nmpa->DEVICE_TYPE & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK) >>
                              FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT);
    *packageType          = (chip_package_type_t)((nmpa->DEVICE_TYPE & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK) >>
                             FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT);
    *nrOfPins             = (uint8_t)((nmpa->DEVICE_TYPE & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK) >>
                          FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT);
}
