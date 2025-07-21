/*
 * Copyright 2016 Freescale
 * Copyright 2016,2020-2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_INPUTMUX_CONNECTIONS_
#define _FSL_INPUTMUX_CONNECTIONS_

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.inputmux_connections"
#endif

/*! @name Driver version */
/*@{*/
/*! @brief INPUTMUX_CONNECTION driver version 2.0.0. */
#define FSL_INPUTMUX_CONNECTION_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @addtogroup inputmux_driver
 * @{
 */

/*!
 * @name Input multiplexing connections
 * @{
 */

/*! @brief Periphinmux IDs */
#define SCT0_INMUX0         0x00U
#define TIMER0CAPTSEL0      0x20U
#define TIMER1CAPTSEL0      0x40U
#define TIMER2CAPTSEL0      0x60U
#define PINTSEL_PMUX_ID     0xC0U
#define PINTSEL0            0xC0U
#define DMA0_ITRIG_INMUX0   0xE0U
#define DMA0_OTRIG_INMUX0   0x160U
#define FREQMEAS_REF_REG    0x180U
#define FREQMEAS_TARGET_REG 0x184U
#define TIMER3CAPTSEL0      0x1A0U
#define TIMER4CAPTSEL0      0x1C0U
#define PINTSECSEL0         0x1E0U
#define DMA1_ITRIG_INMUX0   0x200U
#define DMA1_OTRIG_INMUX0   0x240U
#define PMUX_SHIFT          20U

#define INPUTMUX_GpioPortPinToPintsel(port, pin) ((pin) + (PINTSEL0 << PMUX_SHIFT))

/*! @brief INPUTMUX connections type */
typedef enum _inputmux_connection_t
{
    /*!< SCT0 INMUX. */
    kINPUTMUX_SctGpi0ToSct0       = 0U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi1ToSct0       = 1U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi2ToSct0       = 2U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi3ToSct0       = 3U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi4ToSct0       = 4U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi5ToSct0       = 5U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi6ToSct0       = 6U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_SctGpi7ToSct0       = 7U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer0M0ToSct0     = 8U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer1M0ToSct0     = 9U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer2M0ToSct0     = 10U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer3M0ToSct0     = 11U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer4M0ToSct0     = 12U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_GpiointBmatchToSct0 = 14U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_ArmTxevToSct0       = 22U + (SCT0_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_DebugHaltedToSct0   = 23U + (SCT0_INMUX0 << PMUX_SHIFT),

    /*!< TIMER0 CAPTSEL. */
    kINPUTMUX_CtimerInp0ToTimer0Captsel  = 0U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp1ToTimer0Captsel  = 1U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp2ToTimer0Captsel  = 2U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp3ToTimer0Captsel  = 3U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp4ToTimer0Captsel  = 4U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp5ToTimer0Captsel  = 5U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp6ToTimer0Captsel  = 6U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp7ToTimer0Captsel  = 7U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp8ToTimer0Captsel  = 8U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp9ToTimer0Captsel  = 9U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp10ToTimer0Captsel = 10U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp11ToTimer0Captsel = 11U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp12ToTimer0Captsel = 12U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp13ToTimer0Captsel = 13U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp14ToTimer0Captsel = 14U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp15ToTimer0Captsel = 15U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp16ToTimer0Captsel = 16U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp17ToTimer0Captsel = 17U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp18ToTimer0Captsel = 18U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp19ToTimer0Captsel = 19U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp20ToTimer0Captsel = 20U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp21ToTimer0Captsel = 21U + (TIMER0CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp22ToTimer0Captsel = 22U + (TIMER0CAPTSEL0 << PMUX_SHIFT),

    /*!< TIMER1 CAPTSEL. */
    kINPUTMUX_CtimerInp0ToTimer1Captsel  = 0U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp1ToTimer1Captsel  = 1U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp2ToTimer1Captsel  = 2U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp3ToTimer1Captsel  = 3U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp4ToTimer1Captsel  = 4U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp5ToTimer1Captsel  = 5U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp6ToTimer1Captsel  = 6U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp7ToTimer1Captsel  = 7U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp8ToTimer1Captsel  = 8U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp9ToTimer1Captsel  = 9U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp10ToTimer1Captsel = 10U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp11ToTimer1Captsel = 11U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp12ToTimer1Captsel = 12U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp13ToTimer1Captsel = 13U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp14ToTimer1Captsel = 14U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp15ToTimer1Captsel = 15U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp16ToTimer1Captsel = 16U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp17ToTimer1Captsel = 17U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp18ToTimer1Captsel = 18U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp19ToTimer1Captsel = 19U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp20ToTimer1Captsel = 20U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp21ToTimer1Captsel = 21U + (TIMER1CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp22ToTimer1Captsel = 22U + (TIMER1CAPTSEL0 << PMUX_SHIFT),

    /*!< TIMER2 CAPTSEL. */
    kINPUTMUX_CtimerInp0ToTimer2Captsel  = 0U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp1ToTimer2Captsel  = 1U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp2ToTimer2Captsel  = 2U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp3ToTimer2Captsel  = 3U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp4ToTimer2Captsel  = 4U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp5ToTimer2Captsel  = 5U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp6ToTimer2Captsel  = 6U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp7ToTimer2Captsel  = 7U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp8ToTimer2Captsel  = 8U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp9ToTimer2Captsel  = 9U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp10ToTimer2Captsel = 10U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp11ToTimer2Captsel = 11U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp12ToTimer2Captsel = 12U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp13ToTimer2Captsel = 13U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp14ToTimer2Captsel = 14U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp15ToTimer2Captsel = 15U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp16ToTimer2Captsel = 16U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp17ToTimer2Captsel = 17U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp18ToTimer2Captsel = 18U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp19ToTimer2Captsel = 19U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp20ToTimer2Captsel = 20U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp21ToTimer2Captsel = 21U + (TIMER2CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp22ToTimer2Captsel = 22U + (TIMER2CAPTSEL0 << PMUX_SHIFT),

    /*!< Pin interrupt select. */
    kINPUTMUX_GpioPort0Pin0ToPintsel  = 0U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin1ToPintsel  = 1U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin2ToPintsel  = 2U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin3ToPintsel  = 3U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin4ToPintsel  = 4U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin5ToPintsel  = 5U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin6ToPintsel  = 6U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin7ToPintsel  = 7U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin8ToPintsel  = 8U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin9ToPintsel  = 9U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin10ToPintsel = 10U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin11ToPintsel = 11U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin12ToPintsel = 12U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin13ToPintsel = 13U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin14ToPintsel = 14U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin15ToPintsel = 15U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin16ToPintsel = 16U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin17ToPintsel = 17U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin18ToPintsel = 18U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin19ToPintsel = 19U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin20ToPintsel = 20U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin21ToPintsel = 21U + (PINTSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin22ToPintsel = 22U + (PINTSEL0 << PMUX_SHIFT),

    /*!< DMA0 Input trigger. */
    kINPUTMUX_PinInt0ToDma0     = 0U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt1ToDma0     = 1U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt2ToDma0     = 2U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt3ToDma0     = 3U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer0M0ToDma0   = 4U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer0M1ToDma0   = 5U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer1M0ToDma0   = 6U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer1M1ToDma0   = 7U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer2M0ToDma0   = 8U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer2M1ToDma0   = 9U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer3M0ToDma0   = 10U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer3M1ToDma0   = 11U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer4M0ToDma0   = 12U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer4M1ToDma0   = 13U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_CompOutToDma0     = 14U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig0ToDma0      = 15U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig1ToDma0      = 16U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig2ToDma0      = 17U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig3ToDma0      = 18U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Sct0DmaReq0ToDma0 = 19U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Sct0DmaReq1ToDma0 = 20U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_HashDmaRxToDma0   = 21U + (DMA0_ITRIG_INMUX0 << PMUX_SHIFT),

    /*!< DMA0 output trigger. */
    kINPUTMUX_Dma0Hash0TxTrigoutToTriginChannels     = 0U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0SpifiTrigoutToTriginChannels       = 3U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm0RxTrigoutToTriginChannels = 4U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm0TxTrigoutToTriginChannels = 5U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm1RxTrigoutToTriginChannels = 6U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm1TxTrigoutToTriginChannels = 7U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm2RxTrigoutToTriginChannels = 8U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma0Flexcomm2TxTrigoutToTriginChannels = 9U + (DMA0_OTRIG_INMUX0 << PMUX_SHIFT),

    /*!< Selection for frequency measurement reference clock. */
    kINPUTMUX_ExternOscToFreqmeasRef  = 0U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Fro12MhzToFreqmeasRef   = 1U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Fro32MhzToFreqmeasRef   = 2U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Fro1MhzToFreqmeasRef    = 3U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_32KhzOscToFreqmeasRef   = 4U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_MainClkToFreqmeasRef    = 5U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_SpifiClkToFreqmeasRef   = 6U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin3ToFreqmeasRef  = 7U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin11ToFreqmeasRef = 8U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin12ToFreqmeasRef = 9U + (FREQMEAS_REF_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin14ToFreqmeasRef = 10U + (FREQMEAS_REF_REG << PMUX_SHIFT),

    /*!< Selection for frequency measurement target clock. */
    kINPUTMUX_ExternOscToFreqmeasTarget  = 0U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Fro12MhzToFreqmeasTarget   = 1U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Fro32MhzToFreqmeasTarget   = 2U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Fro1MhzToFreqmeasTarget    = 3U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_32KhzOscToFreqmeasTarget   = 4U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_MainClkToFreqmeasTarget    = 5U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_SpifiClkToFreqmeasTarget   = 6U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin3ToFreqmeasTarget  = 7U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin11ToFreqmeasTarget = 8U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin12ToFreqmeasTarget = 9U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),
    kINPUTMUX_Port0Pin14ToFreqmeasTarget = 10U + (FREQMEAS_TARGET_REG << PMUX_SHIFT),

    /*!< TIMER3 CAPTSEL. */
    kINPUTMUX_CtimerInp0ToTimer3Captsel  = 0U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp1ToTimer3Captsel  = 1U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp2ToTimer3Captsel  = 2U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp3ToTimer3Captsel  = 3U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp4ToTimer3Captsel  = 4U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp5ToTimer3Captsel  = 5U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp6ToTimer3Captsel  = 6U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp7ToTimer3Captsel  = 7U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp8ToTimer3Captsel  = 8U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp9ToTimer3Captsel  = 9U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp10ToTimer3Captsel = 10U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp11ToTimer3Captsel = 11U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp12ToTimer3Captsel = 12U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp13ToTimer3Captsel = 13U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp14ToTimer3Captsel = 14U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp15ToTimer3Captsel = 15U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp16ToTimer3Captsel = 16U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp17ToTimer3Captsel = 17U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp18ToTimer3Captsel = 18U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp19ToTimer3Captsel = 19U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp20ToTimer3Captsel = 20U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp21ToTimer3Captsel = 21U + (TIMER3CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp22ToTimer3Captsel = 22U + (TIMER3CAPTSEL0 << PMUX_SHIFT),

    /*!< Timer4 CAPTSEL. */
    kINPUTMUX_CtimerInp0ToTimer4Captsel  = 0U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp1ToTimer4Captsel  = 1U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp2ToTimer4Captsel  = 2U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp3ToTimer4Captsel  = 3U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp4ToTimer4Captsel  = 4U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp5ToTimer4Captsel  = 5U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp6ToTimer4Captsel  = 6U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp7ToTimer4Captsel  = 7U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp8ToTimer4Captsel  = 8U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp9ToTimer4Captsel  = 9U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp10ToTimer4Captsel = 10U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp11ToTimer4Captsel = 11U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp12ToTimer4Captsel = 12U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp13ToTimer4Captsel = 13U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp14ToTimer4Captsel = 14U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp15ToTimer4Captsel = 15U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp16ToTimer4Captsel = 16U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp17ToTimer4Captsel = 17U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp18ToTimer4Captsel = 18U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp19ToTimer4Captsel = 19U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp20ToTimer4Captsel = 20U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp21ToTimer4Captsel = 21U + (TIMER4CAPTSEL0 << PMUX_SHIFT),
    kINPUTMUX_CtimerInp22ToTimer4Captsel = 22U + (TIMER4CAPTSEL0 << PMUX_SHIFT),

    /*Pin interrupt secure select */
    kINPUTMUX_GpioPort0Pin0ToPintSecsel  = 0U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin1ToPintSecsel  = 1U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin2ToPintSecsel  = 2U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin3ToPintSecsel  = 3U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin4ToPintSecsel  = 4U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin5ToPintSecsel  = 5U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin6ToPintSecsel  = 6U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin7ToPintSecsel  = 7U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin8ToPintSecsel  = 8U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin9ToPintSecsel  = 9U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin10ToPintSecsel = 10U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin11ToPintSecsel = 11U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin12ToPintSecsel = 12U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin13ToPintSecsel = 13U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin14ToPintSecsel = 14U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin15ToPintSecsel = 15U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin16ToPintSecsel = 16U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin17ToPintSecsel = 17U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin18ToPintSecsel = 18U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin19ToPintSecsel = 19U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin20ToPintSecsel = 20U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin21ToPintSecsel = 21U + (PINTSECSEL0 << PMUX_SHIFT),
    kINPUTMUX_GpioPort0Pin22ToPintSecsel = 22U + (PINTSECSEL0 << PMUX_SHIFT),

    /*!< DMA1 Input trigger. */
    kINPUTMUX_PinInt0ToDma1     = 0U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt1ToDma1     = 1U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt2ToDma1     = 2U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_PinInt3ToDma1     = 3U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer0M0ToDma1   = 4U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer0M1ToDma1   = 5U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer2M0ToDma1   = 6U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Ctimer4M1ToDma1   = 7U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig0ToDma1      = 8U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig1ToDma1      = 9U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig2ToDma1      = 10U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Otrig3ToDma1      = 11U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Sct0DmaReq0ToDma1 = 12U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Sct0DmaReq1ToDma1 = 13U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_HashDmaRxToDma1   = 14U + (DMA1_ITRIG_INMUX0 << PMUX_SHIFT),

    /*!< DMA1 output trigger. */
    kINPUTMUX_Dma1Hash0TxTrigoutToTriginChannels     = 0U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1SpifiTrigoutToTriginChannels       = 3U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm0RxTrigoutToTriginChannels = 4U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm0TxTrigoutToTriginChannels = 5U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm1RxTrigoutToTriginChannels = 6U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm1TxTrigoutToTriginChannels = 7U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm2RxTrigoutToTriginChannels = 8U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
    kINPUTMUX_Dma1Flexcomm2TxTrigoutToTriginChannels = 9U + (DMA1_OTRIG_INMUX0 << PMUX_SHIFT),
} inputmux_connection_t;

/*@}*/

/*@}*/

#endif /* _FSL_INPUTMUX_CONNECTIONS_ */
