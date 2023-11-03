/*
* Copyright 2019-2020 NXP
* All rights reserved.
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include <fsl_power.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>

#include "EmbeddedTypes.h"
#include "psector_api.h"
#include "FunctionLib.h"
#include "RNG_Interface.h"
#include "board.h"
#include "fsl_adc.h"
#include "radio.h"

#include "fsl_os_abstraction.h"
#include "mcux_zephyr.h"

#if gSupportBle
#include "fsl_xcvr.h"
#endif

#if gDbgUseLLDiagPort
#include "fsl_iocon.h"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
#define BLE_MACID_SZ                      6
#define MANUFACTURER_BLE_MACID_ADRESS     (const uint8_t*)(0x9fc00 + 0x100)
#define gBD_ADDR_NXP_OUI_c                 0x00, 0x60, 0x37

#define BLE_BASE_ADDR                     0x400A0000
#define BLE_DIAGCNTL_OFFSET               0x00000050
#define BLE_DIAGSTAT_OFFSET               0x00000054
#define REG_BLE_RD(offs)             (*(volatile uint32_t *)(BLE_BASE_ADDR+(offs)))
#define REG_BLE_WR(offs, val)        (*(volatile uint32_t *)(BLE_BASE_ADDR+(offs))) = (val);

#if (defined(gSupportBle) && (gSupportBle == 1))
#if defined(__IAR_SYSTEMS_ICC__)
extern uint32_t _SCRATCH_AREA_START_[];
extern uint32_t _SCRATCH_AREA_END_[];
#define ScratchStartAddr   (uint32_t)(_SCRATCH_AREA_START_)
#define ScratchEndAddr     (uint32_t)(_SCRATCH_AREA_END_)
#else
extern uint32_t        _scratch_buf_start;
extern uint32_t        _scratch_buf_end;
#define ScratchStartAddr (uint32_t)&_scratch_buf_start
#define ScratchEndAddr   (uint32_t)&_scratch_buf_end
#endif
#else
#define ScratchStartAddr   (uint32_t)0x04000000UL
#define ScratchEndAddr     (uint32_t)0x04000400UL
#endif

/*******************************************************************************
* Local variables
******************************************************************************/
#if gAdcUsed_d
static adc_config_t adcConfigStruct;
static adc_conv_seq_config_t adcConvSeqConfigStruct;

/*  set if adc measurements are done */
static bool adc_measure_done = false;
#endif

#if gDbgUseDbgIos
#define IOCON_PIO_FUNC(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_FUNC_SHIFT)) & IOCON_PIO_FUNC_MASK)
static const struct device * _gpio_0_dev = NULL;
#if (gDbgIoCfg_c == 1) || (gDbgIoCfg_c == 2)

#define IOCON_DBGIO_MODE_FUNC 0

typedef struct {
   uint8_t gpioPort;
   uint8_t gpioPin;
   uint8_t outputLogic;
} gpioOutputPinConfig_t;

gpioOutputPinConfig_t dk6_dbg_io_pins[] = {
#if NB_DBG_IO >= 1
            [0] = { .gpioPort = 0,
                    .gpioPin = IOCON_DBG_PIN,
                    .outputLogic = 1,
                    },
#if NB_DBG_IO >= 2
        [1] = { .gpioPort = 0,
                .gpioPin = IOCON_DBG_PIN+1,
                .outputLogic = 1,
                },
#if NB_DBG_IO >= 3

        [2] = { .gpioPort = 0,
                .gpioPin = IOCON_DBG_PIN+2,
                .outputLogic = 1,
                },
#if NB_DBG_IO >= 4
        [3] = { .gpioPort = 0,
                .gpioPin = IOCON_DBG_PIN+3,
                .outputLogic = 1,
                },
#if NB_DBG_IO >= 5
        [4] = { .gpioPort = 0,
                .gpioPin = 7,
                .outputLogic = 1,
                },
#ifdef DBG_OSA_EVENTS
        [5] = { .gpioPort = 0,
                .gpioPin = DBG_OSA_EVENTS_S_PIN,
                .outputLogic = 1,
        },
        [6] = { .gpioPort = 0,
                .gpioPin = DBG_OSA_EVENTS_W_PIN,
                .outputLogic = 1,
        },
        [7] = { .gpioPort = 0,
            .gpioPin = 21,
            .outputLogic = 1,
        },
#endif
};
#endif
#endif
#endif
#endif
#endif


const iocon_group_t dk6_dbg_io[] = {
#if NB_DBG_IO >= 1
      [0] = {
          .port = 0,
          .pin =  IOCON_DBG_PIN,
          .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
      },
#if NB_DBG_IO >= 2
      [1] = {
          .port = 0,
          .pin =  7,
          .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
      },
#if NB_DBG_IO >= 3
      [2] = {
          .port = 0,
          .pin =  IOCON_DBG_PIN+2,
          .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
      },
#if NB_DBG_IO >= 4
      [3] = {
          .port = 0,
          .pin =  IOCON_DBG_PIN+3,
          .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
      },
#if NB_DBG_IO >= 5
      [4] = {
          .port = 0,
          .pin =  IOCON_DBG_PIN+4,
          .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
      },
#ifdef DBG_OSA_EVENTS
        [5] = {
            .port = 0,
            .pin =  DBG_OSA_EVENTS_S_PIN,
            .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
        },
        [6] = {
                .port = 0,
                .pin =  DBG_OSA_EVENTS_W_PIN,
                .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
        },
        [7] = {
                .port = 0,
                .pin =  21,
                .modefunc =  IOCON_PIO_FUNC(IOCON_DBGIO_MODE_FUNC)  | IOCON_MODE_PULLUP | IOCON_DIGITAL_EN,
        }
#endif
#endif
#endif
#endif
#endif
#endif
 };
#endif
#endif

/*******************************************************************************
 * Private functions
 *******************************************************************************/

#if gDbgUseDbgIos
static void BOARD_DbgSetIo(const gpioOutputPinConfig_t * cfg_array, int pin_id, int val)
{
    const gpioOutputPinConfig_t * pin_def = NULL;
    pin_def = &cfg_array[pin_id];

    if (pin_def)
    {
        gpio_pin_set(_gpio_0_dev, pin_def->gpioPin, val);
    }
}
#endif

#if ADC_TEMP_SENSOR_DRIVER_EN
static void ADC_ClockPower_Configuration(void)
{
    /* Enable ADC clock */
    CLOCK_EnableClock(kCLOCK_Adc0);

    //CLOCK_EnableClock(kCLOCK_PVT);

    /* Power on the ADC converter. */
    POWER_EnablePD(kPDRUNCFG_PD_LDO_ADC_EN);

    /* Enable the clock. */
    CLOCK_AttachClk(kXTAL32M_to_ADC_CLK);
}

static bool ADC_Configuration(ADC_Type *base)
{

    ADC_ClockPower_Configuration();

    int valid = 1;
#if 1
    /* Configure the converter. */
    adcConfigStruct.clockMode = kADC_ClockAsynchronousMode; /* Using async clock source. */
    adc_clock_src_t adc_clk_src = (adc_clock_src_t)((SYSCON->ADCCLKSEL) & SYSCON_ADCCLKSEL_SEL_MASK >> SYSCON_ADCCLKSEL_SEL_SHIFT);
    switch(adc_clk_src)
    {
    case kCLOCK_AdcXtal32M:
    {
        CLOCK_SetClkDiv(kCLOCK_DivAdcClk, 8, true);
        break;
    }
    case kCLOCK_AdcFro12M:
    {
        CLOCK_SetClkDiv(kCLOCK_DivAdcClk, 3, true);
        break;
    }
    case kCLOCK_AdcNoClock:
    default:
    {
        valid = 0;
        //PRINTF("ADC configuration error: no clock selected in asynchronous mode\r\n");
        break;
    }
    }

    if (!valid)
    {
        return valid;
    }
#endif

    /* Configure the converter. */
    //adcConfigStruct.clockMode = kADC_ClockSynchronousMode; /* Using sync clock source. */
    adcConfigStruct.resolution = kADC_Resolution12bit;
#if defined(FSL_FEATURE_ADC_HAS_CTRL_BYPASSCAL) & FSL_FEATURE_ADC_HAS_CTRL_BYPASSCAL
    adcConfigStruct.enableBypassCalibration = false;
#endif/* FSL_FEATURE_ADC_HAS_CTRL_BYPASSCAL. */
    adcConfigStruct.sampleTimeNumber = 0U;
    ADC_Init(base, &adcConfigStruct);

    /* Enable conversion in Sequence A. */
    /* Channel to be used is set up at the beginning of each sequence */
    adcConvSeqConfigStruct.channelMask = 0;
    adcConvSeqConfigStruct.triggerMask = 0U;
    adcConvSeqConfigStruct.triggerPolarity = kADC_TriggerPolarityPositiveEdge;
    adcConvSeqConfigStruct.enableSingleStep = false;
    adcConvSeqConfigStruct.enableSyncBypass = false;
    adcConvSeqConfigStruct.interruptMode = kADC_InterruptForEachSequence;
    ADC_SetConvSeqAConfig(base, &adcConvSeqConfigStruct);

    return valid;
}

#endif    /* #if(ADC_TEMP_SENSOR_DRIVER_EN) */

/*****************************************************************************
 * Public functions
 ****************************************************************************/

#if gDbgUseDbgIos
void BOARD_InitDbgIo(void)
{
    _gpio_0_dev = device_get_binding("GPIO_0");
    const struct device *port0 = DEVICE_DT_GET(DT_NODELABEL(pio0));

    const gpioOutputPinConfig_t *pinArray = &dk6_dbg_io_pins[0];
    const iocon_group_t * p_iocon = &dk6_dbg_io[0];
    uint32_t nb_dbg_io = sizeof(dk6_dbg_io)/sizeof(iocon_group_t);
    for (uint32_t i = 0; i < nb_dbg_io; i++)
    {
        pinmux_pin_set(port0, p_iocon->pin, p_iocon->modefunc);
        gpio_pin_configure(_gpio_0_dev, pinArray->gpioPin, GPIO_OUTPUT_ACTIVE);

        pinArray++;
        p_iocon++;
    }

    // Toggle all Dbg IOs
    for (int i = 0; i < nb_dbg_io; i++)
    {
        BOARD_DbgSetIo(dk6_dbg_io_pins, i, 0);
        BOARD_DbgSetIo(dk6_dbg_io_pins, i, 1);
        BOARD_DbgSetIo(dk6_dbg_io_pins, i, 0);
    }

    /* To output RFTX and RFRX on 20 & 21 */
    //    IOCON -> PIO[0][20] = 0x85;
    //    IOCON -> PIO[0][21] = 0x85;

    /* To output Clock on 17 */
    //    SYSCON -> CLKOUTSEL = SYSCON_CLKOUTSEL_SEL(0); // MAINCLK output to CLK_OUT
    //    SYSCON -> CLKOUTDIV = SYSCON_CLKOUTDIV_DIV(3) | SYSCON_CLKOUTDIV_HALT(0);
    //    IOCON -> PIO[0][17] =  0x3BD;
}
#endif

void BOARD_DbgIoSet(int pinid, int val)
{
#if (gDbgIoCfg_c == 1) || (gDbgIoCfg_c == 2)
    BOARD_DbgSetIo(dk6_dbg_io_pins, pinid, val);
#else
    NOT_USED(pinid);
    NOT_USED(val);
#endif
}

#if gDbgUseLLDiagPort
/* BOARD_DIAG_PORT_MODE 32 bit word is used to set up to 4 DBG_FUNC modes at a time.
 * It is used to set the Link Layer DIAGCTRL register telling it to output debug
 * information of IOs.
 * The value of each 8-bit tranche composing this 32-bit word is the configuration corresponds
 * to a DIAG mode: DIAG0 and DIAG2 can be muxed towards PIO0..PIO7 port whereas DIAG1..DIAG3
 * are routed to PIO8..PIO15 if configured.
 * The IOCON configuration allows the selection.
 * Beware PIO[8:9] are USART0 so might be lost
 * Beware PIO[10:11] are USART1 so might be lost too, also these 2 are I2C specific IOs
 * Beware PIO[12:13] are SWD so is very painful to lose
 * For each PIO in the IOCON, DBG_FUNC is coded on 4 bits however only values 1 and 2 make sense for
 * SW control of LL diagnostic traces. The DIAG port consists of 16 outputs, so let's consider a 2 bit code to say:
 *   - 0 means not a debug pin,
 *   - 1 routes DIAG0 signals to PIO [0..7] and DIAG1 ones to PIO[8..15]
 *   - 2 routes DIAG2 signals to PIO [0..7] and DIAG3 ones to PIO[8..15]
 *   Combining 16 of these 2 bit codes fits in a single 32bit word.
 * In order to mux to PIO[0..7] signals from either DIAG0 or DIAG2, configure DIAG_PIN_DBGCFG(pin, 1 or 2)
 * likewise the muxing to PIO[8..15] from DIAG1 or DIAG3 can be configured using  DIAG_PIN_DBGCFG(pin, 1 or 2)
 * Note that in order to preserve the debug UART functionality you may wish to prevent routing of LL DIAG signals
 * to pins 8 and 9. This is done using by configuring DIAG_PIN_DBGCFG(8, 0) since USART0 Tx is pin 8 with pin mode #2.
 * We could move USART0 to pin18 and 19 if we configured them in mode #5 thus potentially freeing pin 8 and 9 for LL DIAG.
 * The same kind of issue exists for pins 10 - 11 that are USART1's default.
 * Be warned that SWD interface makes use of pins 12 and 13. Setting the pinmux to make them belong to the DIAG port,
 * prevents the use of a debugger.
 * If we need to manually set a mix of groups
 * Diag 0 & Diag 2 -
 * Use the DIAG_PIN_DBGCFG macro below to select the pins that are to be directed to the DIAG port.
 * DIAG_PIN_DBGCFG(pin, 1) maps a Diag0 or Diag1 signal to IO pin
 * DIAG_PIN_DBGCFG(pin, 2) to map a Diag2 or Diag3 signal to IO the IO pin
 * For instance:
 *        GPIO 0:3    DIAGCNTL 0x03 TX,RX, sync win, sync found
 *        GPIO 4:6    DIAGCNTL 0x0B  exchange memory accesses
 *        GPIO 7      DIAGCNTL 0x03  ble_error_irq
 *        GPIO 11:12  DIAGCNTL 0x07 625us, prefetch
 *        GPIO 15     DIAGCNTL 0x1F event_in_process
 * This results in BOARD_DIAG_PORT_MODE defined as  0x9F8B8783
 *
 * #define DIAG_IOCON_SETTING \
 *       (DIAG_PIN_DBGCFG(0, 1) |\
 *        DIAG_PIN_DBGCFG(1, 1) |\
 *        DIAG_PIN_DBGCFG(2, 1) |\
 *        DIAG_PIN_DBGCFG(3, 1) |\
 *        DIAG_PIN_DBGCFG(4, 2) |\
 *        DIAG_PIN_DBGCFG(5, 2) |\
 *        DIAG_PIN_DBGCFG(6, 2) |\
 *        DIAG_PIN_DBGCFG(7, 1) |\
 *        DIAG_PIN_DBGCFG(8, 0) |\
 *        DIAG_PIN_DBGCFG(9, 0) |\
 *        DIAG_PIN_DBGCFG(10, 0) |\
 *      DIAG_PIN_DBGCFG(11, 1) |\ <- the breaks the USART1
 *      DIAG_PIN_DBGCFG(12, 1) |\ <- note that this setting ruins the SWD usage
 *        DIAG_PIN_DBGCFG(15, 2))
 *
**/

#define DIAG_PIN_DBGCFG(pin, cfg) (((cfg) & 0x3) << (pin*2))


#define DIAG_IOCON_SETTING \
       (DIAG_PIN_DBGCFG(0, 1) |\
        DIAG_PIN_DBGCFG(1, 1) |\
        DIAG_PIN_DBGCFG(2, 1) |\
        DIAG_PIN_DBGCFG(3, 1) |\
        DIAG_PIN_DBGCFG(4, 1) |\
        DIAG_PIN_DBGCFG(5, 1) |\
        DIAG_PIN_DBGCFG(6, 1) |\
        DIAG_PIN_DBGCFG(7, 1) |\
        DIAG_PIN_DBGCFG(8, 0) |\
        DIAG_PIN_DBGCFG(9, 0) |\
        DIAG_PIN_DBGCFG(10, 0) |\
        DIAG_PIN_DBGCFG(11, 0) |\
        DIAG_PIN_DBGCFG(12, 0) |\
        DIAG_PIN_DBGCFG(13, 0) |\
        DIAG_PIN_DBGCFG(14, 1) |\
        DIAG_PIN_DBGCFG(15, 1))

void BOARD_DbgDiagIoConf(void)
{
    int i;
    uint32_t diag_iocon_val = DIAG_IOCON_SETTING;

    uint32_t dbg_func;
    uint32_t val;

    /* PIO[0..7] settings */
    if (!(BOARD_DIAG_PORT_MODE & gDbgLLDiagPort0Msk))
        diag_iocon_val &= 0xffff0000;
    /* PIO[8..15] settings */
    if (!(BOARD_DIAG_PORT_MODE & gDbgLLDiagPort1Msk))
        diag_iocon_val &= 0x0000ffff;

    for (i = 0; i < 16; i++)
    {
        dbg_func = diag_iocon_val & 0x3;
        if (dbg_func == 1 || dbg_func == 2)
        {
            /* pins 10 and 11 are I2C capable and have a special programming */
            val = (i == 10 || i == 11) ? IOCON_I2C_CFG(dbg_func) : IOCON_CFG(dbg_func);
            IOCON -> PIO[0][i] = val;
        }
        else
        {
            val = IOCON->PIO[0][i];
            /* pins 10 and 11 are I2C capable and have a special programming */
            if (i == 10 || i == 11)
                val &= ~(uint32_t)IOCON_PIO_I2C_DBG_MODE_MASK;
            else
                val &= ~(uint32_t)IOCON_PIO_DBG_MODE_MASK;
            IOCON->PIO[0][i] = val;
        }
        diag_iocon_val >>= 2;
    }
}

void BOARD_DbgDiagEnable(void)
{
    REG_BLE_WR(BLE_DIAGCNTL_OFFSET, BOARD_DIAG_PORT_MODE );
}
#else
void BOARD_DbgDiagIoConf(void)
{
}
void BOARD_DbgDiagEnable(void)
{
}
#endif

#if gAdcUsed_d
/*
 * ISR for ADC conversion sequence A done.
 */
bool BOARD_IsADCEnabled(void)
{
    bool result = false;
    if(ADC0->STARTUP & ADC_STARTUP_ADC_ENA_MASK)
    {
        result = true;
    }
    return result;
}


/* Store time when ADC is initialised, then enabling could be done at least 230us later */
#if gTimestampUseWtimer_c
static uint64_t ADCInit_time = 0;

static void BOARD_StoreADCInitTime(uint64_t time)
{
    ADC_DBG_LOG("ADCInit_time: %d", (uint32_t )(0xFFFFFFFF & time));
    ADCInit_time = time;
}
#endif


void BOARD_InitAdc(void)
{
    ADC_DBG_LOG("");

    LpIoSet(1, 0);

    if (!BOARD_IsADCEnabled())
    {
        ADC_DBG_LOG("ADC not enabled");
        ADC_Configuration(ADC0);

        /* Enabling ADC should be done at least 230us later */

#if gTimestampUseWtimer_c
        /* Store ADC Init Time */
        BOARD_StoreADCInitTime(Timestamp_Get_uSec());
#endif
        /* ADC just initialized, measurements should be done before going to low power */
        adc_measure_done = false;
    }

    LpIoSet(1, 1);

}

/* periodical ADC initialisation , one over gAppADCMeasureCounter_c times */
void BOARD_ADCWakeupInit(void)
{
    static uint32_t adc_count = 0;

    /* init ADC for measurement one over gAppADCMeasureCounter_c wakeup times*/
    if(adc_count == 0 )
    {
        ADC_DBG_LOG("Init ADC, adc_count : %d", adc_count);
        BOARD_InitAdc();
        adc_count = gAppADCMeasureCounter_c;
    }
    else
    {
        ADC_DBG_LOG("adc_count : %d", adc_count);
        adc_count--;
    }
}

/* Verify that ADC init has been done at least ADC_WAIT_TIME_US earlier */
void BOARD_CheckADCReady(void)
{
#if gTimestampUseWtimer_c
    uint64_t time;

    time = Timestamp_Get_uSec() - ADCInit_time ;

    if (time < ADC_WAIT_TIME_US)
    {
        CLOCK_uDelay(ADC_WAIT_TIME_US - time);
    }
#else
    /* when no time stamp, wait for ADC_WAIT_TIME_US */
    CLOCK_uDelay(ADC_WAIT_TIME_US);
#endif
}

void BOARD_EnableAdc(void)
{
    LpIoSet(1, 0);
    /* Make sure 230us has elapsed since BOARD_InitAdc() has been called
     * ADC requires a delay after setup, see RFT 1340 */
    //CLOCK_uDelay(ADC_WAIT_TIME_US);
    ADC_DBG_LOG("");
    ADC_EnableConvSeqA(ADC0, true); /* Enable the conversion sequence A. */

    LpIoSet(1, 1);
}

/*  Do ADC measurements before going to low power */
void BOARD_ADCMeasure(void)
{
    int32_t temperature;

    /* check ADC is initialized and measurements not already done */
    if( BOARD_IsADCEnabled() && (adc_measure_done == false) )
    {
        adc_measure_done = true;
        BOARD_GetBatteryLevel();
        temperature = BOARD_GetTemperature();
#if gSupportBle
        XCVR_TemperatureUpdate(temperature);
#else
        vRadio_Temp_Update((int16_t) (2*temperature));
#endif
    }
}

void BOARD_DeInitAdc(void)
{
    ADC_DBG_LOG("");
    /* Power off the ADC converter. */
    POWER_DisablePD(kPDRUNCFG_PD_LDO_ADC_EN);
    ADC_Deinit(ADC0);
}
#endif



/*
 * BOARD_Get_BLE_MAC_Id tries to find a valid BLE MAC address by looking successively into
 * the PFLASH, if an address is found it exits returning this MAC address.
 * Otherwise it keeps looking for one into the CONFIG page (page N-2) and returns this if found.
 * If that fails too then it generates a random address whose OUI is
 * forced (3 MSB bytes of the address).
 *
 */

int psector_WriteBleMacAddress( uint8_t * src_mac_address)
{
    int res = -1;
    psector_page_data_t * page; /* Stored in the scratch area */
    page = (psector_page_data_t *)ScratchStartAddr;
    OSA_DisableIRQGlobal();
    do {

        psector_page_state_t pg_state;

        pg_state = psector_ReadData(PSECTOR_PFLASH_PART,
                                    0,
                                    0,
                                    sizeof(psector_page_data_t),
                                    page);
        if (pg_state < PAGE_STATE_DEGRADED) break;

        uint8_t * dst = (uint8_t*)&page->pFlash.ble_mac_id;
        uint8_t * src = &src_mac_address[0];

        for (int i = 0; i < sizeof(uint64_t); i++)
        {
            *dst++ = *src++;
        }
        if (psector_CommitPageUpdates(page,  PSECTOR_PFLASH_PART) < 0)
            break;

        res = 0;

    } while (0);

    /* Only reach this point when the BLE MAC address write fails */
    OSA_EnableIRQGlobal();

    return res;

}

int BOARD_Get_BLE_MAC_Id(uint8_t mac_addr[BLE_MACID_SZ])
{
    int res = -1;
    uint8_t buf[8];

    FLib_MemSet((uint8_t*)mac_addr, 0, BLE_MACID_SZ);

    do {
        /* Try to read form pFlash Customer MAC address */
        psector_page_state_t pg_state;
#define CUSTOMER_BLE_MACID_OFFSET  ((size_t)&((psector_page_data_t*)0)->pFlash.ble_mac_id)
        pg_state = psector_ReadData(PSECTOR_PFLASH_PART, 0, CUSTOMER_BLE_MACID_OFFSET, sizeof(uint64_t), buf);
        if (pg_state > 1)
        {
            if (!FLib_MemCmpToVal((uint8_t *)buf, 0, sizeof(uint64_t)))
            {
                res = 0;
                break;
            }
        }
        /* If unset by Customer continue to read Manufacturer's */

        FLib_MemCpy((uint8_t *)buf, MANUFACTURER_BLE_MACID_ADRESS, sizeof(uint64_t));
        if (!FLib_MemCmpToVal(buf, 0, sizeof(uint64_t)))
        {
            res = 1;
            FLib_MemCpy((uint8_t *)mac_addr, (uint8_t *)&buf[2], BLE_MACID_SZ);
            break;
        }
        else
        {
            uint8_t randomNb[4];
            const uint8_t oui[3] = { gBD_ADDR_NXP_OUI_c };
            RNG_GetRandomNo((uint32_t*)&randomNb[0]);
            buf[0] = buf[1] = 0;
            FLib_MemCpy(&buf[2], (void *)oui, 3);
            FLib_MemCpy(&buf[5], (void *)&randomNb[0], 3);

            if (psector_WriteBleMacAddress(&buf[0]) < 0)
            {
                res = -1;
                break;
            }
            res = 2;
            break;
        }
    } while (0);
    if (res >= 0)
    {
        for (int i = 0; i < BLE_MACID_SZ; i++)
        {
            mac_addr[i] = buf[BLE_MACID_SZ+1-i];
        }
    }
    return res;
}

void BOARD_DisplayMCUUid(uint8_t mac_id[BLE_MACID_SZ])
{
    //PRINTF("Device_MAC_ID = ");
    for (int i=0; i < BLE_MACID_SZ-1; i++)
    {
        //PRINTF("%02x:", mac_id[BLE_MACID_SZ - 1 - i]);
    }
    //PRINTF("%02x\r\n", mac_id[0]);
}

void BOARD_GetMCUUid(uint8_t* aOutUid16B, uint8_t* pOutLen)
{
#if defined(CONFIG_BT_NXP_FIXED_MAC_ADDR) && (CONFIG_BT_NXP_FIXED_MAC_ADDR != 0)
    uint8_t mac_id[BD_ADDR_SIZE] = { ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 40) & 0xFF),
                                     ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 32) & 0xFF),
                                     ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 24) & 0xFF),
                                     ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 16) & 0xFF),
                                     ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 8) & 0xFF),
                                     ((CONFIG_BT_NXP_FIXED_MAC_ADDR >> 0) & 0xFF) };
    *pOutLen = BD_ADDR_SIZE;

    FLib_MemCpy(aOutUid16B, mac_id, BD_ADDR_SIZE);
#else
    uint8_t mac_id[BD_ADDR_SIZE] = { 0 };

    if ( BOARD_Get_BLE_MAC_Id(mac_id) >= 0)
    {
        static int already_displayed = 0;
        if (!already_displayed)
        {
            BOARD_DisplayMCUUid(mac_id);
            already_displayed = 1;
        }

        *pOutLen = BD_ADDR_SIZE;
        FLib_MemCpy(aOutUid16B, mac_id, BD_ADDR_SIZE);
    }
#endif
}

