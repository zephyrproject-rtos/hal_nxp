/*
 * Copyright 2020-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_QTMR_H_
#define FSL_QTMR_H_

#include "fsl_common.h"

/*!
 * @defgroup qtmr QTMR: Quad Timer Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief QTMR driver version. */
#define FSL_QTMR_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*******************************************************************************
 * QTMR peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup qtmr_driver_log The Driver Change Log
 * @ingroup qtmr
 * @{
 * The current QTMR driver version is 2.0.1.
 *
 * - 2.0.1
 *   - Improvements
 *     - Supported to get TMR capture register address.
 *   - Bug Fixes
 *     - Fixed violations of the MISRA C-2012 rules.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * Introduction of peripheral and driver
 ******************************************************************************/
/*!
 * @defgroup qtmr_intro QTMR Peripheral and Driver Overview
 * @ingroup qtmr
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 *
 * Peripheral feature and how this peripheral works
 * =================================================
 * QTMR module is a timer system with 4 identical independent 16-bit counter channels. Each channel has two input nodes
 * and its own output signal. One module has 4 input pins (input pin 0 ~ input pin 3), the input pin signals are shared
 * by all channels' input nodes in this module.
 *
 * Features
 * --------------------------
 * + Support two input nodes for each channel: primary input and secondary input.
 *     - Input source support select from multiple clock sources.
 *         + Primary input can select from "input pin 0~3", "channel output 0~3" and "IP bus clock prescaler".
 *         + Secondary input can select from "input pin 0~3".
 *         + External clock rate need lower than peripheral clock/2.
 *     - Secondary input source support capture feature.
 *         + The active edge of secondary input source can trigger capture the channel counter value into CAP register.
 *         + Support make channel reload counter value after capture event occurs.
 *     - Secondary input source support act as a fault signal.
 *         + When enabled, the channel output signal (OFLAG) is cleared when the secondary input is set.
 *     - Support invert the "input pin 0~3" clock sources of channel.
 *         + Invert feature only affects "input pin 0~3", and acts on the channel input node, not the input pin, so it
 *           only affect current channel and not share by other channel.
 *         + The primary and secondary input node can choose different "input pin 0~3" signals for one channel, the
 *           invert feature will act both primary input node and secondary input node at the same time.
 *     - Support add independent input filter for each "input pin 0~3" signal.
 *         + 4 input pins have 4 corresponding filter registers.
 *         + The input filter acts on the input pin directly, so the input filter config will affect all channels that
 *           select this input pin as source.
 *
 * + Support different count behaviors for each channel.
 *     - Support different basic channel counting events base on primary input or/and secondary input.
 *         + Support count primary input active edge.
 *             - Active edge is raising edge when choose "channel output 0~3" or "IP bus clock prescaler" as primary
 *               input source.
 *             - Active edge is determined by whether the invert feature is enabled when choose "input pin 0~3" as
 *               primary input source. It is raising edge when disable invert, is falling edge when enable invert.
 *         + Support count primary input both edges.
 *         + Support count primary input source active edge when secondary input is at a active level
 *             - Active edge/level is raising edge and high level when choose "channel output 0~3" or "IP bus clock
 *               prescaler" as primary/secondary input source.
 *             - Active edge/level is determined by whether the invert feature is enabled when choose "input pin 0~3" as
 *               primary/secondary input source. It is raising edge and high level when disable invert, is falling
 *               edge and low level when enable invert.
 *         + Support quadrature count mode, uses primary and secondary input sources.
 *         + Support count primary input active edge while secondary input level decide count direction.
 *             - Active edge is raising edge when choose "channel output 0~3" or "IP bus clock
 *               prescaler" as primary input source.
 *             - Active edge is determined by whether the invert feature is enabled when choose "input pin 0~3" as
 *               primary input source. It is raising edge when disable invert, is fall when enable invert.
 *             - Secondary input level also affects by invert feature when choose "input pin 0~3" as secondary input
 *               source.
 *         + Support count primary input active edge while secondary input act as a trigger to start and
 *           stop/re-initialize the counter.
 *             - Active edge and trigger edge is raising edge when choose "channel output 0~3" or "IP bus clock
 *               prescaler" as primary/secondary input source.
 *             - Active edge and trigger edge is determined by whether the invert feature is enabled when choose "input
 *               pin 0~3" as primary/secondary input source. It is raising edge when disable invert, is falling edge
 *               when enable invert.
 *             - Counter will start on first secondary input trigger edge, and continue until a compare event occurs or
 *               another secondary input trigger edge is detected, then counter will stop/re-initialize.
 *                  + Stop or re-initialize is determined by whether the re-initialize feature is enabled. When disable,
 *                    the counter will stop and timer compare flag will be set, when enable, the counter will reload and
 *                    continue counting.
 *                  + Subsequent secondary input trigger edge will continue to restart and stop/re-initialize the
 *                    counting until a compare event occurs.
 *         + Support count cascaded mode, primary input source must be set to another channel's output within the
 *           module. If a channel selecting its own output for input is illegal, the result is no counting.
 *     - Support count until roll over or until compare event.
 *         + Channel have two compare events, corresponding to the COMP1 and COMP2 registers.
 *     - Support count up or down.
 *         + Count direction can be selected independently by the CTRL[DIR] bit control.
 *         + When chose "secondary specifies direction" count mode, count direction decide by the secondary input
 *           level XOR with CTRL[DIR] bit. Secondary input level will affects by invert feature when choose "input pin
 *           0~3" as secondary input source.
 *             - Disable invert feature (IPS = 0)
 *                 + Count up when (CTRL[DIR] = 0 & secondary input = 0) or (CTRL[DIR] = 1 & secondary input = 1).
 *                 + Count down when (CTRL[DIR] = 0 & secondary input = 1) or (CTRL[DIR] = 1 & secondary input = 0).
 *             - Enable invert feature (IPS = 1)
 *                 + Count up when (CTRL[DIR] = 0 & secondary input = 1) or (CTRL[DIR] = 1 & secondary input = 0).
 *                 + Count down when (CTRL[DIR] = 0 & secondary input = 0) or (CTRL[DIR] = 1 & secondary input = 1).
 *     - Support different count compare event mode.
 *         + Normal mode, count up trigger COMP1 compare event and count down trigger COMP2 compare event.
 *         + Alternative mode, count up will trigger COMP1 compare event and COMP2 compare event alternating, or count
 *           down, but COMP2 act first.
 *     - Support count once or repeatedly.
 *     - Support different counter re-initialized mode.
 *         + Normal mode, channel counter re-initialized only with the LOAD register.
 *         + Alternative mode, channel counter is re-initialized with LOAD register when counting up and a match COMP1
 *           occurs, or channel counter is re-initialized with COMPLD2 register when counting down and a match COMP2
 *           occurs.
 *     - Support different preload mode for COMPn register.
 *         + Never reload.
 *         + COMPn register can be loaded with the value in corresponding CMPLDn register when COMP1 compare event.
 *         + COMPn register can be loaded with the value in corresponding CMPLDn register when COMP2 compare event.
 *
 * + Support different output behaviors for each channel.
 *     - Support operate output signal (OFLAG) base on different channel event.
 *         + Support Assert OFLAG while channel active.
 *         + Support Set/Clear/Toggle OFLAG on normal mode compare event.
 *         + Support Toggle OFLAG on compare event alternating mode.
 *         + Support Set OFLAG on compare event and clear on secondary input active edge.
 *         + Support Set OFLAG on compare event and clear on count roll over.
 *         + Support primary node source output while channel counter is active.
 *     - Support invert output signal.
 *     - Support forces a configurable value to output signal.
 *         + Force command can be software or compare event from a master channel.
 *     - Support drive the output signal to the external pin.
 *
 * + Support cooperation with other channel.
 *     - Support enable master mode for each channel, and master channel can broadcast compare event to all channels
 *       within this module.
 *     - Support enable receiving compare event from master channel. The master compare event can re-initialize
 *       channel or/and force this channel OFLAG signal.
 *
 * + Support hold feature to stores the counter's values of specific channels whenever any of the four channel
 *   within a module is read.
 *
 * + Support performs certain actions in response to the chip entering debug mode.
 *     - Continue with normal operation during chip in debug mode.
 *     - Halt channel counter during chip in debug mode.
 *     - Force channel output to logic 0 during chip in debug mode.
 *     - Halt channel counter and force channel output to logic 0 during chip in debug mode.
 *
 * + Supports Interrupts.
 *     - Compare event interrupt: Compare event interrupt, COMP1 compare event interrupt, COMP2 compare event
 *       interrupt.
 *     - Count overflow interrupt.
 *     - Input capture edge interrupt.
 *         + Secondary input source input capture rising or/and falling edge interrupt, the edge is determined by the
 *           capture mode, this interrupt can't work with input capture edge trigger DMA enable.
 *
 * + Supports DMA.
 *     - Channel load CMPLD1 register into COMP1 will trigger DMA write request for CMPLD1
 *     - Channel load CMPLD2 register into COMP2 will trigger DMA write request for CMPLD2.
 *     - Secondary input source input edge flag setting will trigger DMA read request for CAPT register, can't work with
 *       input capture edge interrupt enable.
 *
 * How this peripheral works
 * -------------------------
 * 1. Select clock source for primary input and secondary input and config necessary input attributes.
 * 2. Config count mode with length, direction, times, compare, load and perload attributes.
 * 3. Config output signal work mode and cooperation mode.
 * 4. Enable channel to start count, it can generate output signal (OFLAG) and interrupt/dma request.
 *
 * How this driver are designed to make this peripheral works
 * ===========================================================
 * The qtmr driver provides the structure @ref qtmr_channel_config_t which contain several sub-structures and other
 * member to cover all feature of one qtmr channel. The QTMR_Init() function takes the argument in type of @ref
 * qtmr_channel_config_t to complete the initialization of the channel. Since QTMR is very flexible and cannot give the
 * commonly used configuration, these sub-structures are only used to facilitate the understanding of the module and
 * will not provide function APIs to take them as parameters. Base on the sub-structures and other behaviors of QTMR
 * module, the qtmr driver also be divided into several basic function groups.
 *
 * + Initialization and deinitialization Interfaces.
 *     The APIs in this function group can be used to initialize or de-initialize the qtmr channel.
 * + Input signal control related Interfaces.
 *     The APIs in this function group can be used to configure channel input signal related option, such as
 *     primary/secondary input source, secondary input capture mode.
 * + Channel count related Interfaces.
 *     The APIs in this function group can be used to configure channel count control related option or read channel
 *     count status, such as count mode, count length, count preload mode, count mode.
 * + Channel output signal (OFLAG) related Interfaces.
 *     The APIs in this function group can be used to configure channel output signal related option, such as output
 *     mode, output polarity.
 * + Channel cooperation control related Interfaces.
 *     The APIs in this function group can be used to configure channel cooperation related option, such as master mode
 *     enable.
 * + DMA control Interfaces.
 *     The APIs in this function group can be used to enable/disable channel DMA features.
 * + Interrupt control Interfaces.
 *     The APIs in this function group can be used to enable/disable channel interrupts.
 * + QTMR channel Status Flag Interfaces.
 *     The APIs in this function group can be used to get or clear the status flag of the QTMR channel.
 * + QTMR channel debug control Interface.
 *     The API in this function group is used to configure the channel operation mode when the chip enters debug mode.
 * + QTMR channel enable control Interface.
 *     The API in this function group can be used to enable/disable one channel or multiple channels together.
 *
 * How to use this driver
 * =============================
 * + Steps shall be done outside QTMR driver
 *     - Initialize the pin or/and XBAR with expected features configured. QTMR input pin signal can from chip pin or
 *       other peripheral output, and channel output signal can connect to chip pin or other peripheral input.
 *     - SoC level interrupt controller configuration shall be configured / enabled in application codes if QTMR
 *       channel is expected to generator interrupt on compare event, input capture edge event or count overflow event.
 *     - Interrupt entry function shall be added in the application codes and interrupt handler function shall be placed
 *       in the entry function to make sure the implemented interrupt handling codes will be invoked on a generation of
 *       interrupt.
 *     - Enable DMA and configure DMA channel trigger source in application codes if QTMR channel is expected to
 *       generator DMA request on input capture edge event or channel load CMPLDn register into COMPn event.
 *
 * + Sets the QTMR work mode by invoking QTMR_Init()
 *     - [Optional] Invokes QTMR_GetChannelDefaultConfig() function to get the default channel configuration.
 *     - Set the member of channel configuration structure @ref qtmr_channel_config_t to get expected feature.
 *         The following lists the members that need be set to enable the channel to count.
 *         + eCountMode : Used to set the count mode of the channel.
 *                        E.g. If users set the count mode to count rising edges of primary source, this member can be
 *                             configured as @ref qtmr_channel_count_mode_t::kQTMR_CountPrimarySrcRiseEdge.
 *         + u16Comp1/2 : Decide the compare value in count up /down mode. Need set when "count until compare" is
 *           enabled.
 *     - Set the pointer member of @ref qtmr_config_t with the address of "channel"/"input pin filter"
 *       configure structure.
 *     - Invokes QTMR_Init() to set QTMR configuration.
 *         +  Channel will start directly when channel config variable member bEnableChannel is true.
 * + [Optional] Invokes QTMR_EnableChannels() to start channel counter.
 * + [Optional] Invokes function API to get status or do flexible control.
 *
 * Typical Use Case
 * =============================
 * 1. Count mode with trigger a periodic interrupt
 *   In this typical use case, the counter will count the rising edges of the IP bus clock divider by 2.
 *   And generate compare interrupts when channel count to u16Comp1 value.
 *    @code
 *        qtmr_config_t sQtmrConfig = {0};
 *        qtmr_channel_config_t sChannelConfig;
 *        sQtmrConfig.psChannelConfig[0] = &sChannelConfig;
 *        uint16_t interrupt_period;
 *        QTMR_GetChannelDefaultConfig(&sChannelConfig);
 *        sChannelConfig.sCountConfig.eCountLength = kQTMR_CountLengthUntilCompare;
 *        sChannelConfig.u16EnabledInterruptMask = kQTMR_CompareInterruptEnable;
 *        sChannelConfig.u16Comp1 = interrupt_period;
 *        QTMR_Init(DEMO_QTMR_BASEADDR, &sChannelConfig);
 *        QTMR_EnableChannels(QTMR, (uint16_t)kQTMR_Channel0);
 *    @endcode
 *
 * 2. Triggered count mode to capture PWM pulse width
 *   In this typical use case, the counter will start count the rising edges of the IP bus clock divider by 2 on first
 *   secondary input (secondary input connect to kQTMR_InputPin0) rising edge. And generate input edge flag on first
 *   secondary input falling edge. Then DMA will read the PWM pulse width from CAPT register. (Need enable DMA and
 *   configure DMA channel trigger source in application codes )
 *    @code
 *        qtmr_config_t sQtmrConfig = {0};
 *        qtmr_channel_config_t sChannelConfig;
 *        sQtmrConfig.psChannelConfig[0] = &sChannelConfig;
 *        QTMR_GetChannelDefaultConfig(&sChannelConfig);
 *        sChannelConfig.sInputConfig.eSecondarySourceCaptureMode = kQTMR_SecondarySrcCaptureFallingEdge;
 *        sChannelConfig.sCountConfig.eCountMode =
 *   	          kQTMR_CountPrimarySrcRiseEdgeSecondarySrcRiseEdgeTrigWithReInit;
 *        sChannelConfig.u16EnabledDMAMask = kQTMR_InputEdgeFlagDmaEnable;
 *        QTMR_Init(QTMR, &sChannelConfig);
 *        QTMR_EnableChannels(QTMR, (uint16_t)kQTMR_Channel0);
 *    @endcode
 *
 * 3. Triggered count mode to short the PWM pulse width
 *    In this typical use case, the counter will start count the rising edges of the IP bus clock divider by 2 on the
 *    first secondary input (PWM output connect to kQTMR_InputPin0) rising edge. The channel output will clear on this
 *    init, and set until the counter compare event(compare value should short than PWM pulse width), then the output
 *    will clear on the next secondary input falling edge. This case makes QTMR channel output to be a PWM signal with a
 *    shorter pulse width.
 *    @code
 *        qtmr_config_t sQtmrConfig = {0};
 *        qtmr_channel_config_t sChannelConfig;
 *        sQtmrConfig.psChannelConfig[0] = &sChannelConfig;
 *        uint16_t delay_period;
 *        QTMR_GetChannelDefaultConfig(&sChannelConfig);
 *        sChannelConfig.sCountConfig.eCountMode =
 *   	          kQTMR_CountPrimarySrcRiseEdgeSecondarySrcRiseEdgeTrig;
 *        sChannelConfig.sCountConfig.eCountLength = kQTMR_CountLengthUntilCompare;
 *        sChannelConfig.sOutputConfig.eOutputMode = kQTMR_OutputSetOnComareClearOnSecSrcActiveEdge;
 *        sChannelConfig.u16Comp1 = delay_period;
 *        QTMR_Init(QTMR, &sChannelConfig);
 *        QTMR_EnableChannels(QTMR, (uint16_t)kQTMR_Channel0);
 *    @endcode
 *
 * 4. PWM mode with variable frequency and pulse width
 *  In this typical use case, the channel output yields a pulse-width modulated (PWM) signal
 *  whose frequency and pulse width is determined by the values programmed into the
 *  COMP1 and COMP2 registers, and the input clock frequency. When interrupts generated by the channel compare2 event,
 *  use can write new values for both CMPLD1 and CMPLD2 according to the next pulse width and frequency.
 *    @code
 *        qtmr_config_t sQtmrConfig = {0};
 *        qtmr_channel_config_t sChannelConfig;
 *        sQtmrConfig.psChannelConfig[0] = &sChannelConfig;
 *        uint16_t pulse_width;
 *        uint16_t pwm_period;
 *        QTMR_GetChannelDefaultConfig(&sChannelConfig);
 *        sChannelConfig.u16EnabledInterruptMask = kQTMR_Compare2InterruptEnable;
 *        sChannelConfig.u16Comp1Preload = pulse_width;
 *        sChannelConfig.u16Comp2Preload = pwm_period - pulse_width;
 *        sChannelConfig.sCountConfig.eCountLength = kQTMR_CountLengthUntilCompare;
 *        sChannelConfig.sCountConfig.eCountPreload1 = kQTMR_CountPreloadOnComp2CompareEvent;
 *        sChannelConfig.sCountConfig.eCountPreload2 = kQTMR_CountPreloadOnComp1CompareEvent;
 *        sChannelConfig.sOutputConfig.eOutputMode = kQTMR_OutputToggleOnAltCompareReg;
 *        sChannelConfig.sOutputConfig.eOutputValueOnForce = kQTMR_OutputValueSetOnForce;
 *        sChannelConfig.sOutputConfig.bEnableSwForceOutput = true;
 *        sChannelConfig.sOutputConfig.bEnableOutputPin = true;
 *        QTMR_Init(QTMR, &sChannelConfig);
 *        QTMR_EnableChannels(QTMR, (uint16_t)kQTMR_Channel0);
 *    @endcode
 * @}
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The enumeration for Quad Timer module input pin source.
 */
typedef enum _qtmr_input_pin
{
    kQTMR_InputPin0 = 0, /*!< Quad Timer input pin 0. */
    kQTMR_InputPin1,     /*!< Quad Timer input pin 1. */
    kQTMR_InputPin2,     /*!< Quad Timer input pin 2. */
    kQTMR_InputPin3      /*!< Quad Timer input pin 3. */
} qtmr_input_pin_t;

/*!
 * @brief The enumeration for Quad Timer module channel number.
 */
typedef enum _qtmr_channel_number
{
    kQTMR_Channel0 = 0U, /*!< Quad Timer Channel 0. */
    kQTMR_Channel1,      /*!< Quad Timer Channel 1. */
    kQTMR_Channel2,      /*!< Quad Timer Channel 2. */
    kQTMR_Channel3,      /*!< Quad Timer Channel 3. */
} qtmr_channel_number_t;

/*!
 * @brief The enumeration for Quad Timer channel primary input source.
 */
typedef enum _qtmr_channel_primary_count_source
{
    kQTMR_PrimarySrcInputPin0 = 0,      /*!< Quad Timer input pin 0. */
    kQTMR_PrimarySrcInputPin1,          /*!< Quad Timer input pin 1. */
    kQTMR_PrimarySrcInputPin2,          /*!< Quad Timer input pin 2. */
    kQTMR_PrimarySrcInputPin3,          /*!< Quad Timer input pin 3. */
    kQTMR_PrimarySrcChannel0Output,     /*!< Quad Timer channel 0 output. */
    kQTMR_PrimarySrcChannel1Output,     /*!< Quad Timer channel 1 output. */
    kQTMR_PrimarySrcChannel2Output,     /*!< Quad Timer channel 2 output. */
    kQTMR_PrimarySrcChannel3Output,     /*!< Quad Timer channel 3 output. */
    kQTMR_PrimarySrcIPBusClockDivide1,  /*!< IP bus clock divide by 1. */
    kQTMR_PrimarySrcIPBusClockDivide2,  /*!< IP bus clock divide by 2. */
    kQTMR_PrimarySrcIPBusClockDivide4,  /*!< IP bus clock divide by 4. */
    kQTMR_PrimarySrcIPBusClockDivide8,  /*!< IP bus clock divide by 8. */
    kQTMR_PrimarySrcIPBusClockDivide16, /*!< IP bus clock divide by 16. */
    kQTMR_PrimarySrcIPBusClockDivide32, /*!< IP bus clock divide by 32. */
    kQTMR_PrimarySrcIPBusClockDivide64, /*!< IP bus clock divide by 64. */
    kQTMR_PrimarySrcIPBusClockDivide128 /*!< IP bus clock divide by 128. */
} qtmr_channel_primary_count_source_t;

/*!
 * @brief The enumeration for Quad Timer channel secondary input source.
 */
typedef enum _qtmr_channel_secondary_count_source
{
    kQTMR_SecondarySrcInputPin0 = 0, /*!< Quad Timer input pin 0. */
    kQTMR_SecondarySrcInputPin1,     /*!< Quad Timer input pin 1. */
    kQTMR_SecondarySrcInputPin2,     /*!< Quad Timer input pin 2. */
    kQTMR_SecondarySrcInputPin3      /*!< Quad Timer input pin 3. */
} qtmr_channel_secondary_count_source_t;

/*!
 * @brief The enumeration for Quad Timer channel secondary input source capture mode.
 */
typedef enum _qtmr_channel_secondary_source_capture_mode
{
    kQTMR_SecondarySrcCaptureNoCapture = 0,            /*!< Secondary source capture is disabled. */
    kQTMR_SecondarySrcCaptureRisingEdge,               /*!< Secondary source capture on rising edge. */
    kQTMR_SecondarySrcCaptureFallingEdge,              /*!< Secondary source capture on falling edge. */
    kQTMR_SecondarySrcCaptureRisingAndFallingEdge,     /*!< Secondary source capture on both edges. */
    kQTMR_SecondarySrcCaptureRisingEdgeWithReload = 5, /*!< Secondary source capture on rising edge while cause the
                                                          channel to be reloaded. */
    kQTMR_SecondarySrcCaptureFallingEdgeWithReload,    /*!< Secondary source capture on falling edge while cause the
                                                          channel to be reloaded. */
    kQTMR_SecondarySrcCaptureRisingAndFallingEdgeWithReload /*!< Secondary source capture on both edges while cause
                                                               the channel to be reloaded. */
} qtmr_channel_secondary_source_capture_mode_t;

/*!
 * @brief The enumeration for Quad Timer channel count mode.
 *
 * When "channel output 0~3" or "IP bus clock prescaler" is chosen, active edge is the rising edge. When "input pin 0~3"
 * is chosen, active edge and active level is determined by input invert feature (IPS). Disable input invert feature
 * means active edge is rising edge, active level is high level, enable input invert feature means active edge is
 * falling edge, active level is low level.
 */
typedef enum _qtmr_channel_count_mode
{
    kQTMR_CountNoOperation = 0,                      /*!< No operation. */
    kQTMR_CountPrimarySrcRiseEdge,                   /*!< Count active edge of primary input source. */
    kQTMR_CountPrimarySrcRiseAndFallEdge,            /*!< Count rising and falling edges of primary input source. */
    kQTMR_CountPrimarySrcRiseEdgeSecondarySrcInHigh, /*!< Count active edge of primary input source when secondary input
                                                        is at a active level. */
    kQTMR_CountPrimarySecondarySrcInQuadDecode,      /*!< Quadrature count mode, uses primary and secondary sources. */
    kQTMR_CountPrimarySrcRiseEdgeSecondarySrcDir, /*!< Count active edge of primary input source; secondary input source
                                                     specifies count direction. */
    kQTMR_CountPrimarySrcRiseEdgeSecondarySrcRiseEdgeTrig, /*!< The active edge of secondary input source triggers count
                                                              active edge of primary input source, and the channel
                                                              counter will stop upon receiving a second trigger event
                                                              while it's still counting from the first trigger event.*/
    kQTMR_CountCascadeWithOtherChannel, /*!< Cascaded count mode, the channel will count as compare events occur in the
                                             selected source chennel (use a special high-speed signal path rather than
                                             the OFLAG output signal). */
    /*!< The active edge of secondary input source triggers count active edge of primary input source, and the channel
       counter will re-initialized upon receiving a second trigger event while it's still counting from the first
       trigger event. */
    kQTMR_CountPrimarySrcRiseEdgeSecondarySrcRiseEdgeTrigWithReInit =
        (0x8 | kQTMR_CountPrimarySrcRiseEdgeSecondarySrcRiseEdgeTrig)
} qtmr_channel_count_mode_t;

/*!
 * @brief The enumeration for Quad Timer channel count length.
 */
typedef enum _qtmr_channel_count_length
{
    kQTMR_CountLengthUntilRollOver = 0, /*!< Count until roll over at $FFFF. */
    kQTMR_CountLengthUntilCompare,      /*!< Count until compare. */
} qtmr_channel_count_length_t;

/*!
 * @brief The enumeration for Quad Timer channel count direction.
 */
typedef enum _qtmr_channel_count_direction
{
    kQTMR_CountDirectionUp = 0, /*!< Count direction up. */
    kQTMR_CountDirectionDown,   /*!< Count direction down. */
} qtmr_channel_count_direction_t;

/*!
 * @brief The enumeration for Quad Timer channel count times.
 */
typedef enum _qtmr_channel_count_times
{
    kQTMR_CountTimesRepeat = 0, /*!< Count repeatedly. */
    kQTMR_CountTimesOnce,       /*!< Count time once. */
} qtmr_channel_count_times_t;

/*!
 * @brief The enumeration for Quad Timer channel count load mode.
 */
typedef enum _qtmr_channel_count_load_mode
{
    kQTMR_CountLoadNormal = 0,  /*!< Count can be re-initialized only with the LOAD register when match event occurs. */
    kQTMR_CountLoadAlternative, /*!< Channel can be re-initialized with the LOAD register when count up and a match with
                                   COMP1 occurs, or with CMPLD2 register when count down and a match with COMP2 occurs.
                                 */
} qtmr_channel_count_load_mode_t;

/*!
 * @brief The enumeration for Quad Timer channel COMP1 & COMP2 preload mode.
 */
typedef enum _qtmr_channel_count_preload_mode
{
    kQTMR_CountPreloadNoLoad = 0,          /*!< Not load CMPLDn into COMPn register when compare event occurs. */
    kQTMR_CountPreloadOnComp1CompareEvent, /*!< Load CMPLDn register into COMPn when occurs a successful comparison of
                                         channel counter value and the COMP1 register. */
    kQTMR_CountPreloadOnComp2CompareEvent  /*!< Load CMPLDn register into COMPn when occurs a successful comparison of
                                         channel counter value and the COMP2  register. */
} qtmr_channel_count_preload_mode_t;

/*!
 * @brief The enumeration for Quad Timer channel output signal (OFLAG signal) work mode.
 */
typedef enum _qtmr_channel_output_mode
{
    kQTMR_OutputAssertWhenCountActive = 0,          /*!< OFLAG output assert while counter is active. */
    kQTMR_OutputClearOnCompare,                     /*!< OFLAG output clear on successful compare. */
    kQTMR_OutputSetOnCompare,                       /*!< OFLAG output set on successful compare. */
    kQTMR_OutputToggleOnCompare,                    /*!< OFLAG output toggle on successful compare. */
    kQTMR_OutputToggleOnAltCompareReg,              /*!< OFLAG output toggle using alternating compare registers. */
    kQTMR_OutputSetOnComareClearOnSecSrcActiveEdge, /*!< OFLAG output set on compare, clear on secondary source input
                                                       edge. */
    kQTMR_OutputSetOnCompareClearOnCountRoll,       /*!< OFLAG output set on compare, clear on counter rollover. */
    kQTMR_OutputGateClockOutWhenCountActive         /*!< OFLAG output gated while count is active. */
} qtmr_channel_output_mode_t;

/*!
 * @brief The enumeration for Quad Timer channel output signal (OFLAG) value on force event occur.
 */
typedef enum _qtmr_qtmr_channel_output_value_on_force
{
    kQTMR_OutputValueClearOnForce = 0, /*!< OFLAG output clear (low) when software triggers a FORCE command or master
                                          channel force the OFLAG (EEOF need set). */
    kQTMR_OutputValueSetOnForce, /*!< OFLAG output set (high) when software triggers a FORCE command or master channel
                                    force the OFLAG (EEOF need set). */
} qtmr_channel_output_value_on_force_t;

/*!
 * @brief The enumeration for Quad Timer channel run options when the chip entering debug mode.
 */
typedef enum _qtmr_channel_debug_action
{
    kQTMR_DebugRunNormal = 0U,       /*!< Continue with normal operation. */
    kQTMR_DebugHaltCounter,          /*!< Halt counter. */
    kQTMR_DebugForceOutToZero,       /*!< Force output to logic 0. */
    kQTMR_DebugHaltCountForceOutZero /*!< Halt counter and force output to logic 0. */
} qtmr_channel_debug_action_t;

/*!
 * @brief The enumeration for Quad Timer channel interrupts.
 */
enum _qtmr_channel_interrupt_enable
{
    kQTMR_CompareInterruptEnable  = (TMR_SCTRL_TCFIE_MASK),   /*!< Compare interrupt. */
    kQTMR_Compare1InterruptEnable = (TMR_CSCTRL_TCF1EN_MASK), /*!< Compare 1 interrupt. */
    kQTMR_Compare2InterruptEnable = (TMR_CSCTRL_TCF2EN_MASK), /*!< Compare 2 interrupt. */
    kQTMR_OverflowInterruptEnable = (TMR_SCTRL_TOFIE_MASK),   /*!< Timer overflow interrupt. */
    kQTMR_EdgeInterruptEnable     = (TMR_SCTRL_IEFIE_MASK),   /*!< Input edge interrupt. */
    kQTMR_ALLInterruptEnable =
        (kQTMR_CompareInterruptEnable | kQTMR_Compare1InterruptEnable | kQTMR_Compare2InterruptEnable |
         kQTMR_OverflowInterruptEnable | kQTMR_EdgeInterruptEnable),
};

/*!
 * @brief The enumeration for Quad Timer channel work status.
 */
enum _qtmr_channel_status_flags
{
    kQTMR_CompareFlag  = TMR_SCTRL_TCF_MASK,   /*!< Compare flag. */
    kQTMR_Compare1Flag = TMR_CSCTRL_TCF1_MASK, /*!< Compare 1 flag. */
    kQTMR_Compare2Flag = TMR_CSCTRL_TCF2_MASK, /*!< Compare 2 flag. */
    kQTMR_OverflowFlag = TMR_SCTRL_TOF_MASK,   /*!< Timer overflow flag. */
    kQTMR_EdgeFlag     = TMR_SCTRL_IEF_MASK,   /*!< Input edge flag. */
    kQTMR_StatusAllFlags =
        kQTMR_CompareFlag | kQTMR_Compare1Flag | kQTMR_Compare2Flag | kQTMR_OverflowFlag | kQTMR_EdgeFlag,
};

/*!
 * @brief The enumeration for Quad Timer channel enable.
 */
enum _qtmr_channel_enable
{
    kQTMR_Channel0Enable = (1 << 0U), /*!< Channel 0 enable. */
    kQTMR_Channel1Enable = (1 << 1U), /*!< Channel 1 enable. */
    kQTMR_Channel2Enable = (1 << 2U), /*!< Channel 2 enable. */
    kQTMR_Channel3Enable = (1 << 3U), /*!< Channel 3 enable. */
    kQTMR_ALLChannelEnable =
        (kQTMR_Channel0Enable | kQTMR_Channel1Enable | kQTMR_Channel2Enable | kQTMR_Channel3Enable),
};

/*!
 * @brief The enumeration for Quad Timer channel DMA trigger source.
 */
enum _qtmr_channel_dma_enable
{
    kQTMR_InputEdgeFlagDmaEnable = (TMR_DMA_IEFDE_MASK), /*!< Input edge flag setting will trigger DMA read request for
                                                            CAPT register. */
    kQTMR_Compare1PreloadDmaEnable = (TMR_DMA_CMPLD1DE_MASK), /*!< Channel load CMPLD1 register into COMP1 will trigger
                                                                 DMA write request for CMPLD1. */
    kQTMR_Compare2PreloadDmaEnable = (TMR_DMA_CMPLD2DE_MASK), /*!< Channel load CMPLD2 register into COMP2 will trigger
                                                                 DMA write request for CMPLD2. */
    kQTMR_AllDMAEnable = kQTMR_InputEdgeFlagDmaEnable | kQTMR_Compare1PreloadDmaEnable | kQTMR_Compare2PreloadDmaEnable,
};

/*!
 * @brief The structure for configuring Quad Timer channel input signal.
 */
typedef struct _qtmr_channel_input_config
{
    qtmr_channel_primary_count_source_t ePrimarySource : 4U;     /*!< Specify the primary input source. */
    qtmr_channel_secondary_count_source_t eSecondarySource : 2U; /*!< Specify the secondary input source. */
    /* Configures the secondary input source capture mode. */
    qtmr_channel_secondary_source_capture_mode_t eSecondarySourceCaptureMode : 3U;
    bool bEnableSecondarySrcFaultFunction : 1U; /*!< true: The selected secondary input acts as a fault signal which can
                               clear the channel output signal when it is set, false: Fault function disabled. */
    bool eEnableInputInvert : 1U; /*!< true: Invert input signal value when select input pin as primary or/and secondary
                                input source false: no operation. */
} qtmr_channel_input_config_t;

/*!
 * @brief The structure for configuring Quad Timer channel counting behaviors.
 */
typedef struct _qtmr_channel_count_config
{
    qtmr_channel_count_mode_t eCountMode : 4U;          /*!< Configures channel count mode. */
    qtmr_channel_count_length_t eCountLength : 1U;      /*!< Configures channel count length. */
    qtmr_channel_count_direction_t eCountDir : 1U;      /*!< Configures channel count direction. */
    qtmr_channel_count_times_t eCountTimes : 1U;        /*!< Configures channel count times. */
    qtmr_channel_count_load_mode_t eCountLoadMode : 1U; /*!< Configures channel count load mode. */
    /* Configures channel count compare register 1 preload control. */
    qtmr_channel_count_preload_mode_t eCountPreload1 : 2U;
    /* Configures channel count compare register 2 preload control. */
    qtmr_channel_count_preload_mode_t eCountPreload2 : 2U;
    uint8_t bitsReserved : 4U;
} qtmr_channel_count_config_t;

/*!
 * @brief The structure for configuring Quad Timer channel output signal (OFLAG).
 */
typedef struct _qtmr_channel_output_config
{
    qtmr_channel_output_mode_t eOutputMode : 3U;                   /*!< Configures channel output signal work mode. */
    qtmr_channel_output_value_on_force_t eOutputValueOnForce : 1U; /*!< The value of output signal when
                                                                     force event occur. */
    bool bEnableOutputInvert : 1U;  /*!< True: the polarity of output signal will be inverted, false: The
                                       output signal is not inverted. */
    bool bEnableSwForceOutput : 1U; /*!< True: forces the current value of eOFLAGValueOnForce to output signal. false:
                                      no operation. */
    bool bEnableOutputPin : 1U;     /*!< True: the output signal is driven on the external pin. false: the external
                                        pin is configured as an input. */
    uint8_t bitReserved : 1U;
} qtmr_channel_output_config_t;

/*!
 * @brief The structure for configuring Quad Timer channel cooperation mode with other channels.
 */
typedef struct _qtmr_channel_cooperation_config
{
    bool bEnableMasterReInit : 1U;     /*!< true: Master channel within the module can re-initialize this
                                       channel when it has a compare event, false: no operation. */
    bool bEnableMasterForceOFLAG : 1U; /*!< true: Master channel within the module can force this channel OFLAG signal
                                        when it has a compare event, false: no operation. */
    bool bEnableMasterMode : 1U; /*!< true: This channel is configured as mater channel, it can broadcast compare event
                                  to all channels within the module to re-initialize channel and/or force channel output
                                  signal, false: no operation. */
    uint8_t bitsReserved : 5U;
} qtmr_channel_cooperation_config_t;

/*!
 * @brief Quad Timer channel configuration covering all channel configurable fields.
 */
typedef struct _qtmr_channel_config
{
    qtmr_channel_input_config_t sInputConfig;   /*!< Configures channel input signal. */
    qtmr_channel_count_config_t sCountConfig;   /*!< Configures channel count work mode. */
    qtmr_channel_output_config_t sOutputConfig; /*!< Configures channel output signal (OFLAG) work mode. */
    /* Configures channel cooperation mode with other channels. */
    qtmr_channel_cooperation_config_t sCooperationConfig;
    qtmr_channel_debug_action_t eDebugMode; /*!< Configures channel operation in chip debug mode. */
    uint16_t u16EnabledInterruptMask;       /*!< The mask of the interrupts to be enabled, should be the OR'ed of
                                              @ref _qtmr_channel_interrupt_enable. */
    uint16_t u16EnabledDMAMask;             /*!< The mask of the interrupts to be enabled, should be the OR'ed of
                                              @ref _qtmr_channel_dma_enable. */
    uint16_t u16Comp1;                      /*!< Value for Channel compare register 1. */
    uint16_t u16Comp2;                      /*!< Value for Channel compare register 2. */
    uint16_t u16Comp1Preload;               /*!< Value for Channel compare 1 preload register. */
    uint16_t u16Comp2Preload;               /*!< Value for Channel compare 2 preload register. */
    uint16_t u16Load;                       /*!< Value for Channel load register. */
    uint16_t u16Count;                      /*!< Value for Channel counter value register. */
    bool bEnableChannel;                    /*!< True: enable the channel prescaler (if it is being used) and counter
                                                 false: disable channel. */
} qtmr_channel_config_t;

/*!
 * @brief The structure for configuring Quad Timer module input pin filter.
 */
typedef struct _qtmr_input_pin_filter_config
{
    uint8_t u8Period; /*!< Value for input filter sample period. */
    uint8_t u8Count;  /*!< Value for input filter sample count (sample count = count +3). */
} qtmr_input_pin_filter_config_t;

/*!
 * @brief Quad Timer module configuration which contain channel config structure pointers and input pin
 *        filter config structure pointers.
 *
 * @note Need use channel structure address to init the structure pointers, when the channel or input pin structure
 *       pointers is NULL, it will be ignored by QTMR_Init API. This can save stack space when only one or two channels
 *       are used.
 */
typedef struct _qtmr_config
{
    qtmr_channel_config_t *psChannelConfig[4];
    qtmr_input_pin_filter_config_t *psInputFilterConfig[4];
} qtmr_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization Interfaces
 * @{
 */

/*!
 * @brief Initialization Quad Timer module with provided structure.
 *
 * This function can initial one or more channels of the Quad Timer module.
 *
 * This examples shows how only initial channel 0.
 * @code
 *     qtmr_config_t sConfig = {0};
 *     qtmr_channel_config_t sChannel0Config;
 *     sConfig.psChannelConfig[0] = &sChannel0Config;
 *     QTMR_GetChannelDefaultConfig(&sChannel0Config);
 *     QTMR_Init(QTMR, sConfig);
 * @endcode
 *
 * @note This API should be called at the beginning of the application using the Quad Timer module.
 *
 * @param base      Quad Timer peripheral base address.
 * @param psConfig  Pointer to user's Quad Timer config structure. See @ref qtmr_config_t.
 */
void QTMR_Init(TMR_Type *base, const qtmr_config_t *psConfig);

/*!
 * @brief De-initialization Quad Timer module.
 *
 * @param base  Quad Timer peripheral base address.
 */
void QTMR_Deinit(TMR_Type *base);

/*!
 * @brief Gets an available pre-defined options for Quad Timer channel module's configuration.
 *
 * This function initializes the channel configuration structure with a free run 16bit timer work setting.
 * The default values are:
 * @code
 *   psConfig->sInputConfig.ePrimarySource = kQTMR_PrimarySrcIPBusClockDivide2;
 *   psConfig->sInputConfig.eSecondarySource = kQTMR_SecondarySrcInputPin0;
 *   psConfig->sInputConfig.eSecondarySourceCaptureMode = kQTMR_SecondarySrcCaptureNoCapture;
 *   psConfig->sInputConfig.bEnableSecondarySrcFaultFunction = false;
 *   psConfig->sInputConfig.eEnableInputInvert = false;
 *   psConfig->sCountConfig.eCountMode = kQTMR_CountPrimarySrcRiseEdge;
 *   psConfig->sCountConfig.eCountLength = kQTMR_CountLengthUntilRollOver;
 *   psConfig->sCountConfig.eCountDir = kQTMR_CountDirectionUp;
 *   psConfig->sCountConfig.eCountTimes = kQTMR_CountTimesRepeat;
 *   psConfig->sCountConfig.eCountLoadMode = kQTMR_CountLoadNormal;
 *   psConfig->sCountConfig.eCountPreload1 = kQTMR_CountPreloadNoLoad;
 *   psConfig->sCountConfig.eCountPreload2 = kQTMR_CountPreloadNoLoad;
 *   psConfig->sOutputConfig.eOutputMode = kQTMR_OutputAssertWhenCountActive;
 *   psConfig->sOutputConfig.eOutputValueOnForce = kQTMR_OutputValueClearOnForce;
 *   psConfig->sOutputConfig.bEnableOutputInvert = false;
 *   psConfig->sOutputConfig.bEnableSwForceOutput = false;
 *   psConfig->sOutputConfig.bEnableOutputPin = false;
 *   psConfig->sCooperationConfig.bEnableMasterReInit = false;
 *   psConfig->sCooperationConfig.bEnableMasterForceOFLAG = false;
 *   psConfig->sCooperationConfig.bEnableMasterMode = false;
 *   psConfig->eDebugMode = kQTMR_DebugRunNormal;
 *   psConfig->u16EnabledInterruptMask = 0x0U;
 *   psConfig->u16EnabledDMAMask = 0x0U;
 *   psConfig->u16Comp1 = 0x0U;
 *   psConfig->u16Comp2 = 0x0U;
 *   psConfig->u16Comp1Preload = 0x0U;
 *   psConfig->u16Comp1Preload = 0x0U;
 *   psConfig->u16Load = 0x0U;
 *   psConfig->u16Count = 0x0U;
 *   psConfig->bEnableChannel = false;
 * @endcode
 *
 * @param psConfig  Pointer to user's Quad Timer channel config structure. See @ref qtmr_channel_config_t.
 */
void QTMR_GetChannelDefaultConfig(qtmr_channel_config_t *psConfig);

/*!
 * @brief Setup a Quad Timer channel with provided structure.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param psConfig        Pointer to user's Quad Timer channel config structure. See @ref qtmr_channel_config_t.
 */
void QTMR_SetupChannleConfig(TMR_Type *base,
                             qtmr_channel_number_t eChannelNumber,
                             const qtmr_channel_config_t *psConfig);

/*! @}*/

/*!
 * @name Input signal control related Interfaces
 * @{
 */

/*!
 * @brief Sets primary input source.
 *
 * This function select the primary input source, it can select from "input pin 0~3", "channel output
 * 0~3" and "IP bus clock prescaler".
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param ePrimarySource  The primary input source. See @ref qtmr_channel_primary_count_source_t.
 */
static inline void QTMR_SetPrimaryCountSource(TMR_Type *base,
                                              qtmr_channel_number_t eChannelNumber,
                                              qtmr_channel_primary_count_source_t ePrimarySource)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CTRL & (uint16_t)(~TMR_CTRL_PCS_MASK)) | TMR_CTRL_PCS(ePrimarySource);
}

/*!
 * @brief Sets secondary input source.
 *
 * This function select the secondary input source, it can select from "input pin 0~3".
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param source          The Secondary input source. See @ref qtmr_channel_secondary_count_source_t.
 */
static inline void QTMR_SetSecondaryCountSource(TMR_Type *base,
                                                qtmr_channel_number_t eChannelNumber,
                                                qtmr_channel_secondary_count_source_t source)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CTRL & (uint16_t)(~TMR_CTRL_SCS_MASK)) | TMR_CTRL_SCS(source);
}

/*!
 * @brief Sets secondary input capture mode.
 *
 * This function select the capture mode for secondary input, it can select from "disable capture", "capture on
 * rising/falling edge" and "capture on both edges". Need enable capture mode when input edge interrupt is needed.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eCaptureMode    The capture mode of secondary input. See @ref qtmr_channel_secondary_source_capture_mode_t.
 */
void QTMR_SetSecondarySourceInputCaptureMode(TMR_Type *base,
                                             qtmr_channel_number_t eChannelNumber,
                                             qtmr_channel_secondary_source_capture_mode_t eCaptureMode);

/*!
 * @brief Enables/Disables secondary input source signal fault feature.
 *
 * Enable fault feature will make secondary input acts as a fault signal so that the channel output signal (OFLAG) is
 * cleared when the secondary input is set.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Enable secondary source fault feature.
 *                        - \b false Disable secondary source fault feature.
 */
static inline void QTMR_EnableSecondarySourceFault(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL |= (uint16_t)(TMR_CSCTRL_FAULT_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL &= (uint16_t)(~(TMR_CSCTRL_FAULT_MASK));
    }
}

/*!
 * @brief Enables/Disables input pin signal polarity invert feature.
 *
 * This function enables/disables input pin signal polarity invert feature.
 * @note Invert feature only affects "input pin 0~3", and acts on the channel input node, not the input pin, so it
 *       only affect current channel and not share by other channel
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Invert input pin signal polarity.
 *                        - \b false No invert for input pin signal polarity.
 */
static inline void QTMR_EnableInputInvert(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &= ~(uint16_t)(TMR_SCTRL_IPS_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_IPS_MASK);
    }
}

/*!
 * @brief Sets input filter for one input pin.
 *
 * Sets input filter if the input signal is noisy.
 * @note The input filter acts on the input pin directly, so the input filter config will affect all channels that
 *       select this input pin as source. Turning on the input filter(setting FILT_PER to a non-zero value) introduces a
 *       latency of (((u8Count + 3) x u8Period) + 2) IP bus clock periods.
 *
 * @param base      Quad Timer peripheral base address.
 * @param ePin      Quad Timer input pin number. See @ref qtmr_input_pin_t.
 * @param u8Count   Range is 0~7, represent the number of consecutive samples that must agree prior to the input filter
 *                  accepting an input transition. Actual consecutive samples numbers is (u8Count + 3).
 * @param u8Period  Represent the sampling period (in IP bus clock cycles) of the input pin signals. Each input is
 *                  sampled multiple times at the rate specified by this field. If u8Period is 0, then the input pin
 *                  filter is bypassed.
 */
static inline void QTMR_SetInputFilter(TMR_Type *base, qtmr_input_pin_t ePin, uint8_t u8Count, uint8_t u8Period)
{
    /* Setup new input filter */
    base->CHANNEL[(uint8_t)ePin].FILT = (TMR_FILT_FILT_CNT(u8Count) | TMR_FILT_FILT_PER(u8Period));
}

/*!
 * @brief Gets the external input signal value selected via the secondary input source.
 *
 * This function read the value of the secondary input source, the input pin IPS and filtering have been applied to the
 * read back value.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The state of the current state of the external input pin selected via the secondary count
 *         source after application of IPS and filtering.
 */
static inline uint16_t QTMR_GetInputPinValueInSecondarySource(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return ((base->CHANNEL[(uint8_t)eChannelNumber].SCTRL & TMR_SCTRL_INPUT_MASK) >> TMR_SCTRL_INPUT_SHIFT);
}

/*! @}*/

/*!
 * @name Channel count related Interfaces
 * @{
 */

/*!
 * @brief Sets channel count mode.
 *
 * This function select channel basic count mode which trigger by primary input or/and secondary input events.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eCountMode      The mode of operation for the count. See @ref qtmr_channel_count_mode_t.
 */
void QTMR_SetCountMode(TMR_Type *base, qtmr_channel_number_t eChannelNumber, qtmr_channel_count_mode_t eCountMode);

/*!
 * @brief Sets channel count length.
 *
 * This function select channel single count length from "until roll over" or "until compare". "until roll over" means
 * count until 0xFFFF, "until compare" means count until reach COMP1 (for count up) or COMP2 (for count up) value
 * (unless the output signal is in alternating compare mode, this mode make channel use COMP1 and COMP2 alternately).
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eLength         The channel count length. See @ref qtmr_channel_count_length_t.
 */
static inline void QTMR_SetCountLength(TMR_Type *base,
                                       qtmr_channel_number_t eChannelNumber,
                                       qtmr_channel_count_length_t eLength)
{
    if (eLength == kQTMR_CountLengthUntilCompare)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL |= (uint16_t)(TMR_CTRL_LENGTH_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL &= ~(uint16_t)(TMR_CTRL_LENGTH_MASK);
    }
}

/*!
 * @brief Sets channel count direction.
 *
 * This function select channel count direction from "count up" or "count down". Under normal count mode, this function
 * decide the count direction directly, when chose "secondary specifies direction" count mode, count direction decide by
 * "the secondary input level" XOR with "the function selection".
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eDirection      The channel count direction. See @ref qtmr_channel_count_direction_t.
 */
static inline void QTMR_SetCountDirection(TMR_Type *base,
                                          qtmr_channel_number_t eChannelNumber,
                                          qtmr_channel_count_direction_t eDirection)
{
    if (eDirection == kQTMR_CountDirectionDown)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL |= (uint16_t)(TMR_CTRL_DIR_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL &= ~(uint16_t)(TMR_CTRL_DIR_MASK);
    }
}

/*!
 * @brief Gets channel count direction.
 *
 * This function read the channel count direction of the last count during quadrature encoded count mode.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The direction of the last count. Value see @ref qtmr_channel_count_direction_t.
 */
static inline qtmr_channel_count_direction_t QTMR_GetCountDirection(TMR_Type *base,
                                                                    qtmr_channel_number_t eChannelNumber)
{
    return (((base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & TMR_CSCTRL_UP_MASK) != 0U) ? kQTMR_CountDirectionUp :
                                                                                           kQTMR_CountDirectionDown);
}

/*!
 * @brief Sets channel count times.
 *
 * This function select channel count times from "once" or "repeatedly". If select "once" with "until compare", channel
 * will stop when reach COMP1 (for count up) or COMP2 (for count up) (unless the output signal is in alternating compare
 * mode, this mode will make channel reaching COMP1, re-initializes then count reaching COMP2, and then stops).
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eTimes          The channel count times. See @ref qtmr_channel_count_times_t.
 */
static inline void QTMR_SetCountTimes(TMR_Type *base,
                                      qtmr_channel_number_t eChannelNumber,
                                      qtmr_channel_count_times_t eTimes)
{
    if (eTimes == kQTMR_CountTimesOnce)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL |= (uint16_t)(TMR_CTRL_ONCE_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL &= ~(uint16_t)(TMR_CTRL_ONCE_MASK);
    }
}

/*!
 * @brief Sets channel count load mode.
 *
 * This function select channel count re-initialized load mode from "normal" or "alternative". "normal" means channel
 * counter re-initialized from LOAD register when compare event, "alternative" means channel counter can
 * re-initialized from LOAD (count up) or CMPLD2 (count down) when compare event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eLoadMode       The channel count load mode. See @ref qtmr_channel_count_load_mode_t.
 */
static inline void QTMR_SetCountLoadMode(TMR_Type *base,
                                         qtmr_channel_number_t eChannelNumber,
                                         qtmr_channel_count_load_mode_t eLoadMode)
{
    if (eLoadMode == kQTMR_CountLoadAlternative)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL |= (uint16_t)(TMR_CSCTRL_ALT_LOAD_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL &= ~(uint16_t)(TMR_CSCTRL_ALT_LOAD_MASK);
    }
}

/*!
 * @brief Sets channel preload mode for compare register 1.
 *
 * This function select channel preload mode for compare register 1. Default the COMP1 register never preload, when
 * enabled, the COMP1 can preload from CMPLD1 register when COMP1 or COMP2 compare event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param ePreloadMode    The compare register 1 preload mode. See @ref qtmr_channel_count_preload_mode_t.
 */
static inline void QTMR_SetCompare1PreloadControl(TMR_Type *base,
                                                  qtmr_channel_number_t eChannelNumber,
                                                  qtmr_channel_count_preload_mode_t ePreloadMode)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & (~(uint16_t)TMR_CSCTRL_CL1_MASK)) |
        TMR_CSCTRL_CL1(ePreloadMode);
}

/*!
 * @brief Sets channel preload mode for compare register 2.
 *
 * This function select channel preload mode for compare register 2. Default the COMP2 register never preload, when
 * enabled, the COMP2 can preload from CMPLD2 register when COMP1 or COMP2 compare event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param ePreloadMode    The compare register 2 preload mode. See @ref qtmr_channel_count_preload_mode_t.
 */
static inline void QTMR_SetCompare2PreloadControl(TMR_Type *base,
                                                  qtmr_channel_number_t eChannelNumber,
                                                  qtmr_channel_count_preload_mode_t ePreloadMode)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & (~(uint16_t)TMR_CSCTRL_CL2_MASK)) |
        TMR_CSCTRL_CL2(ePreloadMode);
}

/*!
 * @brief Sets channel compare register 1 preload register value.
 *
 * This function set the CMPLD1 register value. The COMP1 can preload from CMPLD1 register when preload mode is not
 * "never preload".
 *
 * @param base             Quad Timer peripheral base address.
 * @param eChannelNumber   Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Comp1Preload  Value for Channel compare register 1 preload register.
 */
static inline void QTMR_SetCompare1PreloadValue(TMR_Type *base,
                                                qtmr_channel_number_t eChannelNumber,
                                                uint16_t u16Comp1Preload)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CMPLD1 = u16Comp1Preload;
}

/*!
 * @brief Sets channel compare register 2 preload register value.
 *
 * This function set the CMPLD2 register value. The COMP2 can preload from CMPLD2 register when preload mode is not
 * "never preload".
 *
 * @param base             Quad Timer peripheral base address.
 * @param eChannelNumber   Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Comp2Preload  Value for Channel compare register 2 preload register.
 */
static inline void QTMR_SetCompare2PreloadValue(TMR_Type *base,
                                                qtmr_channel_number_t eChannelNumber,
                                                uint16_t u16Comp2Preload)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CMPLD2 = u16Comp2Preload;
}

/*!
 * @brief Sets channel load register value.
 *
 * This function set the LOAD register value. The channel will re-initialize the counter value with this register after
 * counter compare or overflow event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Load         Value used to initialize the counter after counter compare or overflow event.
 */
static inline void QTMR_SetLoadValue(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Load)
{
    base->CHANNEL[(uint8_t)eChannelNumber].LOAD = u16Load;
}

/*!
 * @brief Sets channel count compare register 1.
 *
 * This function set the COMP1 register value. It use to trigger compare event in count up mode or alternating compare
 * mode.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Comp1        Value for Channel compare register 1.
 */
static inline void QTMR_SetCompare1Value(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Comp1)
{
    base->CHANNEL[(uint8_t)eChannelNumber].COMP1 = u16Comp1;
}

/*!
 * @brief Sets channel count compare register 2.
 *
 * This function set the COMP2 register value. It use to trigger compare event in count down mode or alternating
 * compare mode.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Comp2        Value for Channel compare register 2.
 */
static inline void QTMR_SetCompare2Value(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Comp2)
{
    base->CHANNEL[(uint8_t)eChannelNumber].COMP2 = u16Comp2;
}

/*!
 * @brief Gets channel capture register value.
 *
 * This function read the CAPT register value, which store the real-time channel counter value when input capture event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return  The value captured from the channel counter.
 */
static inline uint16_t QTMR_ReadCaptureValue(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return base->CHANNEL[(uint8_t)eChannelNumber].CAPT;
}

/*!
 * @brief Gets channel hold register value.
 *
 * This function read the HOLD register value, which stores the channel counter's values of specific channels whenever
 * any of the four channels within a module is read.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The channel counter value when any read operation occurs.
 */
static inline uint16_t QTMR_GetHoldValue(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return base->CHANNEL[(uint8_t)eChannelNumber].HOLD;
}

/*!
 * @brief Sets channel counter register value.
 *
 * This function set the CNTR register value, the channel will start counting based on this value.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Count        The channel counter initialize value.
 */
static inline void QTMR_SetCounterValue(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Count)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CNTR = u16Count;
}

/*!
 * @brief Reads channel counter register value.
 *
 * This function read the CNTR register value, which stores the channel real-time channel counting value. This read
 * operation will trigger HOLD register update.
 *
 * @note User can call the utility macros provided in fsl_common.h to convert ticks to usec or msec.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The real-time channel counter value.
 */
static inline uint16_t QTMR_GetCounterValue(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return base->CHANNEL[(uint8_t)eChannelNumber].CNTR;
}

/*! @}*/

/*!
 * @name Channel output signal (OFLAG) related Interfaces
 * @{
 */

/*!
 * @brief Sets Channel output signal (OFLAG) work mode.
 *
 * This function select channel output signal (OFLAG) work mode base on different channel event.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eOutputMode     The mode of operation for the OFLAG output signal. See @ref qtmr_channel_output_mode_t.
 */
static inline void QTMR_SetOutputMode(TMR_Type *base,
                                      qtmr_channel_number_t eChannelNumber,
                                      qtmr_channel_output_mode_t eOutputMode)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CTRL & (~(uint16_t)TMR_CTRL_OUTMODE_MASK)) |
        TMR_CTRL_OUTMODE(eOutputMode);
}

/*!
 * @brief Sets the value of output signal when a force event occurs.
 *
 * This function config the value of output signal when a force event occurs. Force events can be a software command or
 * compare event from a master channel.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eValue          The value of output signal when force event occur. See
 *                         @ref qtmr_channel_output_value_on_force_t.
 */
static inline void QTMR_SetOutputValueOnForce(TMR_Type *base,
                                              qtmr_channel_number_t eChannelNumber,
                                              qtmr_channel_output_value_on_force_t eValue)
{
    base->CHANNEL[(uint8_t)eChannelNumber].SCTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].SCTRL & (~(uint16_t)TMR_SCTRL_VAL_MASK)) | TMR_SCTRL_VAL(eValue);
}

/*!
 * @brief Enables/Disables output signal polarity invert feature.
 *
 * This function enables/disables the invert feature of output signal (OFLAG).
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Invert output signal polarity.
 *                        - \b false No invert for output signal polarity.
 */
static inline void QTMR_EnableOutputInvert(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_OPS_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &= ~(uint16_t)(TMR_SCTRL_OPS_MASK);
    }
}

/*!
 * @brief Enables software triggers a FORCE command to output signal.
 *
 * This function uses a software command to trigger force event, which can force the current value of SCTRL[VAL] bit to
 * be written to the OFLAG output.
 *
 * @note This function can be called only if the counter is disabled.
 * @code
 *      QTMR_SetOutputValueOnForce(QTMR, kQTMR_Channel0, kQTMR_OutputValueSetOnForce);
 *      QTMR_EnableSwForceOutput(QTMR, kQTMR_Channel0);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 */
static inline void QTMR_EnableSwForceOutput(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_FORCE_MASK);
}

/*!
 * @brief Enables/Disables output signal (OFLAG) drive on the external pin feature.
 *
 * This function enables/disables output signal (OFLAG) drive on the external pin feature.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true The output signal is driven on the external pin.
 *                        - \b false The external pin is configured as an input.
 */
static inline void QTMR_EnableOutputPin(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_OEN_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &= ~(uint16_t)(TMR_SCTRL_OEN_MASK);
    }
}

#if defined(TMR_CSCTRL_OFLAG_MASK)
/*!
 * @brief Gets the channel output signal value.
 *
 * This function reads the state of the channel internal OFLAG signal prior to consideration of polarity or debug mode.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The state of the channel output signal.
 */
static inline uint16_t QTMR_GetOutputFlag(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return ((base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & TMR_CSCTRL_OFLAG_MASK) >> TMR_CSCTRL_OFLAG_SHIFT);
}
#endif

/*! @}*/

/*!
 * @name Channel cooperation control related Interfaces
 * @{
 */

/*!
 * @brief Enables/Disables channel master mode.
 *
 * This function enables/disables channel master mode.
 * @note Master channel can broadcast compare event to all channels within the module
 *       to re-initialize channel and/or force channel output signal.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Enables channel master mode.
 *                        - \b false Disables channel master mode.
 */
static inline void QTMR_EnableMasterMode(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_MSTR_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &= ~(uint16_t)(TMR_SCTRL_MSTR_MASK);
    }
}

/*!
 * @brief Enables/Disables force the channel output signal (OFLAG) state by master channel compare event.
 *
 * This function enables/disables the compare event from master channel within the same module to force the state of
 * this channel OFLAG output signal.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Enables OFLAG state to be forced by master channel compare event.
 *                        - \b false Disables OFLAG state to be forced by master channel compare event.
 */
static inline void QTMR_EnableMasterForceOFLAG(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |= (uint16_t)(TMR_SCTRL_EEOF_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &= ~(uint16_t)(TMR_SCTRL_EEOF_MASK);
    }
}

/*!
 * @brief Enables/Disables channel be re-initialized by master channel compare event feature.
 *
 * This function enables/disables the compare event from master channel within the same module to force the
 * re-initialization of this channel.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param bEnable         Enable the feature or not.
 *                        - \b true Enables channel be re-initialized by master channel compare event.
 *                        - \b false Disables channel be re-initialized by master channel compare event.
 */
static inline void QTMR_EnableMasterReInit(TMR_Type *base, qtmr_channel_number_t eChannelNumber, bool bEnable)
{
    if (bEnable)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL |= (uint16_t)(TMR_CTRL_COINIT_MASK);
    }
    else
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CTRL &= ~(uint16_t)(TMR_CTRL_COINIT_MASK);
    }
}

/*! @}*/

/*!
 * @name DMA control Interfaces
 * @{
 */

/*!
 * @brief Enables the Quad Timer DMA request according to a provided mask.
 *
 * This function enables the Quad Timer DMA request according to a provided mask. The mask is a logical OR of
 * enumerators members. See @ref _qtmr_channel_dma_enable.
 * This examples shows how to enable compare 1 register preload DMA request and compare 2 register preload DMA request.
 * @code
 *      QTMR_EnableDma((QTMR, kQTMR_Channel0,kQTMR_Compare1PreloadDmaEnable | kQTMR_Compare2PreloadDmaEnable);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Mask         The QTMR DMA requests to enable. Logical OR of @ref _qtmr_channel_dma_enable.
 */
static inline void QTMR_EnableDma(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Mask)
{
    base->CHANNEL[(uint8_t)eChannelNumber].DMA |= u16Mask;
}

/*!
 * @brief Disables the Quad Timer DMA request according to a provided mask.
 *
 * This function disables the Quad Timer DMA request according to a provided mask. The mask is a logical OR of
 * enumerators members. See @ref _qtmr_channel_dma_enable.
 * This examples shows how to disable compare 1 register preload DMA request and compare 2 register preload DMA request.
 * @code
 *      QTMR_DisableDma((QTMR, kQTMR_Channel0, kQTMR_Compare1PreloadDmaEnable | kQTMR_Compare2PreloadDmaEnable);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Mask         The QTMR DMA requests to disable. Logical OR of @ref _qtmr_channel_dma_enable.
 */
static inline void QTMR_DisableDma(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Mask)
{
    base->CHANNEL[(uint8_t)eChannelNumber].DMA &= ~u16Mask;
}

/*! @}*/

/*!
 * @name Interrupt control Interfaces
 * @{
 */

/*!
 * @brief Enables the Quad Timer interrupts according to a provided mask.
 *
 * This function enables the Quad Timer interrupts according to a provided mask. The mask is a logical OR of
 * enumerators members. See @ref _qtmr_channel_interrupt_enable.
 * This examples shows how to enable compare 1 interrupt and compare 2 interrupt.
 * @code
 *      QTMR_EnableInterrupts((QTMR, kQTMR_Channel0, kQTMR_Compare1InterruptEnable | kQTMR_Compare2InterruptEnable);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Mask         The QTMR DMA interrupts to enable. Logical OR of @ref _qtmr_channel_interrupt_enable.
 */
static inline void QTMR_EnableInterrupts(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Mask)
{
    /*Check if compare, overflow and input dege interrupts need enable*/
    if ((u16Mask & (TMR_SCTRL_TCFIE_MASK | TMR_SCTRL_TOFIE_MASK | TMR_SCTRL_IEFIE_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL |=
            u16Mask & (TMR_SCTRL_TCFIE_MASK | TMR_SCTRL_TOFIE_MASK | TMR_SCTRL_IEFIE_MASK);
    }
    /*Check if compare 1 and compare 2 interrupts need enable*/
    if ((u16Mask & (TMR_CSCTRL_TCF1EN_MASK | TMR_CSCTRL_TCF2EN_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL |= u16Mask & (TMR_CSCTRL_TCF1EN_MASK | TMR_CSCTRL_TCF2EN_MASK);
    }
}

/*!
 * @brief Disables the Quad Timer interrupts according to a provided mask.
 *
 * This function disables the Quad Timer interrupts according to a provided mask. The mask is a logical OR of
 * enumerators members. See @ref _qtmr_channel_interrupt_enable.
 * This examples shows how to disable compare 1 interrupt and compare 2 interrupt.
 * @code
 *      QTMR_DisableInterrupts((QTMR, kQTMR_Channel0, kQTMR_Compare1InterruptEnable | kQTMR_Compare2InterruptEnable);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param u16Mask         The QTMR DMA interrupts to disable. Logical OR of @ref _qtmr_channel_interrupt_enable.
 */
static inline void QTMR_DisableInterrupts(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Mask)
{
    /*Check if compare, overflow and input dege interrupts need disable*/
    if ((u16Mask & (TMR_SCTRL_TCFIE_MASK | TMR_SCTRL_TOFIE_MASK | TMR_SCTRL_IEFIE_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &=
            ~(u16Mask & (TMR_SCTRL_TCFIE_MASK | TMR_SCTRL_TOFIE_MASK | TMR_SCTRL_IEFIE_MASK));
    }
    /*Check if compare 1 and compare 2 interrupts need disable*/
    if ((u16Mask & (TMR_CSCTRL_TCF1EN_MASK | TMR_CSCTRL_TCF2EN_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL &= ~(u16Mask & (TMR_CSCTRL_TCF1EN_MASK | TMR_CSCTRL_TCF2EN_MASK));
    }
}

/*! @}*/

/*!
 * @name QTMR channel Status Flag Interfaces
 * @{
 */

/*!
 * @brief Gets the Quad Timer status flags.
 *
 * This function gets all QTMR channel status flags. The flags are returned as the logical OR value of the enumerators
 * @ref _qtmr_channel_status_flags. To check for a specific status, compare the return value with enumerators in the
 * @ref _qtmr_channel_status_flags. For example, to check whether the compare flag set.
 * @code
 *      if((QTMR_GetStatusFlags(QTMR, kQTMR_Channel0) & kQTMR_CompareFlag) != 0U)
 *      {
 * 	        ...
 *      }
 * @endcode
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 *
 * @return The QTMR status flags which is the logical OR of the enumerators @ref _qtmr_channel_status_flags.
 */
static inline uint16_t QTMR_GetStatusFlags(TMR_Type *base, qtmr_channel_number_t eChannelNumber)
{
    return (base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &
            (TMR_SCTRL_TCF_MASK | TMR_SCTRL_TOF_MASK | TMR_SCTRL_IEF_MASK)) |
           (base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & (TMR_CSCTRL_TCF1_MASK | TMR_CSCTRL_TCF2_MASK));
}

/*!
 * @brief Clears the Quad Timer status flags.
 *
 * This function clears QTMR channel status flags with a provide mask. The mask is a logical OR of enumerators
 * @ref _qtmr_channel_status_flags.
 * This examples shows how to clear compare 1 flag and compare 2 flag.
 * @code
 *      QTMR_ClearStatusFlags((QTMR, kQTMR_Channel0, kQTMR_Compare1Flag | kQTMR_Compare2Flag);
 * @endcode
 *
 * @param base            Quad Timer peripheral base address
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t
 * @param u16Mask         The QTMR status flags to clear. Logical OR of @ref _qtmr_channel_status_flags
 */
static inline void QTMR_ClearStatusFlags(TMR_Type *base, qtmr_channel_number_t eChannelNumber, uint16_t u16Mask)
{
    /*Check if compare 1 and compare 2 flags*/
    if ((u16Mask & (TMR_CSCTRL_TCF1_MASK | TMR_CSCTRL_TCF2_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL &= ~(u16Mask & (TMR_CSCTRL_TCF1_MASK | TMR_CSCTRL_TCF2_MASK));
    }
    /*Check if compare, overflow and input dege flags*/
    if ((u16Mask & (TMR_SCTRL_TCF_MASK | TMR_SCTRL_TOF_MASK | TMR_SCTRL_IEF_MASK)) != 0U)
    {
        base->CHANNEL[(uint8_t)eChannelNumber].SCTRL &=
            ~(u16Mask & (TMR_SCTRL_TCF_MASK | TMR_SCTRL_TOF_MASK | TMR_SCTRL_IEF_MASK));
    }
}

/*! @}*/

/*!
 * @name QTMR channel debug control Interface
 * @{
 */

/*!
 * @brief Sets channel debug actions.
 *
 * This function selects the certain actions which will perform when the chip entering debug mode.
 *
 * @param base            Quad Timer peripheral base address.
 * @param eChannelNumber  Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @param eDebugMode      The Quad Timer channel actions in response to the chip entering debug mode. See
 *                        @ref qtmr_channel_debug_action_t.
 */
static inline void QTMR_SetDebugActions(TMR_Type *base,
                                        qtmr_channel_number_t eChannelNumber,
                                        qtmr_channel_debug_action_t eDebugMode)
{
    base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL =
        (base->CHANNEL[(uint8_t)eChannelNumber].CSCTRL & (~(uint16_t)TMR_CSCTRL_DBG_EN_MASK)) |
        TMR_CSCTRL_DBG_EN(eDebugMode);
}

/*! @}*/

/*!
 * @name QTMR channels enable/disable control Interfaces
 * @{
 */

/*!
 * @brief Enables the Quad Timer channels according to a provided mask.
 *
 * This function enables the Quad Timer channels according to a provided mask. The mask is a logical OR of
 * enumerators @ref _qtmr_channel_enable.
 * This examples shows how to enable channel 0 and channel 1.
 * @code
 *      QTMR_EnableChannels(QTMR, kQTMR_Channel0Enable | kQTMR_Channel1Enable);
 * @endcode
 *
 * @note If one channel has effective count mode, it will start its counter as soon as the channel be enabled.
 *
 * @param base      Quad Timer peripheral base address.
 * @param u16Mask   The QTMR channels to enable. Logical OR of @ref _qtmr_channel_enable.
 */
static inline void QTMR_EnableChannels(TMR_Type *base, uint16_t u16Mask)
{
    /* Enables the channel */
    base->CHANNEL[0].ENBL |= TMR_ENBL_ENBL(u16Mask);
}

/*!
 * @brief Disables the Quad Timer channels according to a provided mask.
 *
 * This function disables the Quad Timer channels according to a provided mask. The mask is a logical OR of
 * enumerators @ref _qtmr_channel_enable.
 * This examples shows how to disable channel 0 and channel 1.
 * @code
 *      QTMR_DisableChannels(QTMR, kQTMR_Channel0Enable | kQTMR_Channel1Enable);
 * @endcode
 *
 * @param base      Quad Timer peripheral base address.
 * @param u16Mask   The QTMR channels to enable. Logical OR of @ref _qtmr_channel_enable.
 */
static inline void QTMR_DisableChannels(TMR_Type *base, uint16_t u16Mask)
{
    /* Disables the channel */
    base->CHANNEL[0].ENBL &= ~TMR_ENBL_ENBL(u16Mask);
}
/*!
 * @brief Gets the TMR capture register address. This API is used to provide the transfer address for TMR capture
 * transfer.
 *
 * @param base TMR base pointer
 * @param nChannel Quad Timer channel number. See @ref qtmr_channel_number_t.
 * @return capture register address
 */
static inline uint32_t TMR_GetCaptureRegAddr(TMR_Type *base, qtmr_channel_number_t nChannel)
{
    return SDK_GET_REGISTER_BYTE_ADDR(TMR_Type, base, CHANNEL[nChannel].CAPT);
}

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_QTMR_H_ */
