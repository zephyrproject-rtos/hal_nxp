/*
 * Copyright 2020-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PWM_H_
#define FSL_PWM_H_

#include "fsl_common.h"

/*!
 * @defgroup pwm eFlexPWM: Enhanced Flexible Pulse Width Modulator Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief PWM driver version. */
#define FSL_PWM_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*! @} */

/*******************************************************************************
 * ChangeLog
 ******************************************************************************/
/*!
 * @defgroup pwm_driver_log The Driver Change Log
 * @ingroup pwm
 * @{
 * The current PWM driver version is 2.2.0.
 *
 * - 2.2.0
 *   - New Features
 *     - Supported capture PWM input filter.
 *     - Supported different PWM deadtime count register width.
 *   - Bug Fixes
 *     - Fixed wrong pwm_sm_pwm_out_t enum order issue.
 *
 * - 2.1.1
 *   - Bug Fixes
 *     - Fixed build error when soc not support Capture A/B features.
 *
 * - 2.1.0
 *   - Improvements
 *     - Supported MC56F80xxx.
 *
 * - 2.0.2
 *   - Bug Fixes
 *     - Fixed clear status flags API doesn't work issue.
 *
 * - 2.0.1
 *   - Improvements
 *     - Supported MC56F82xxx and MC56F84xxx.
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
 * @defgroup pwm_intro eFlexPWM Peripheral and Driver Overview
 * @ingroup pwm
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral feature and how this peripheral works
 * =================================================
 * The pulse width modulator (PWM) module contains 4 PWM submodules, each of which can set up to generate various
 * switching patterns, including highly sophisticated waveforms. It can be used to control all known motor types and is
 * ideal for controlling different Switched Mode Power Supplies (SMPS) topologies as well.
 *
 * Features
 * --------------------------
 * + Support flexible PWM generator logic, include a 16 bit counter, register reload logic, VAL registers logic, force
 *   logic, dead time insertion logic , fractional delay logic and output logic.
 *   - The 16 bit counter support select input clock from multiple clock sources, and has multiple initial source. It
 *     only count in the up direction and then reset to the initial count register (INIT) value.
 *     + Input source can select between three clock signals: the IPBus clock, EXT_CLK (typically from external
 *       timer or an off-chip source), and AUX_CLK (can't be used in submodule 0 ).
 *       - The AUX_CLK signal is broadcast from submodule0 (after clock prescaler and run enable control) and can
 *         be selected as the clock source by other submodules.
 *
 *     + 8 bit clock prescaler support to dividing the clock source by 1~128.
 *
 *     + 16-bit initial count register, which will loaded into the submodule counter when the selected initialize
 *       signal triggers or a FORCE_OUT signal is asserted.
 *       - The initial signal can select between four signals : the local initial signal (VAL1 register compare),
 *         master reload signal (from submodule 0), master initial signal (from submodule 0), and PWM_EXT_SYNC
 *         signal (from on chip or off chip depending on the system architecture).
 *       - The master reload/initial signal should not be used in submodule 0 as it will force the INIT signal to
 *         logic 0.
 *       - Force output signal initialization is disabled by default. A enabled FORCE_OUT initialization will also
 *         assert the local reload if MCTRL[LDOK] is set.
 *
 *   - The register reload control logic is used to determine when the outer set of registers for all double buffered
 *     register pairs will be transferred to the inner set of registers. The double buffered register include the
 *     prescaler bits, initial count register, and VALn registers. The reload signal can select from local reload
 *     signal or master reload signal (from submodule 0).
 *     + The master reload signal should not be used in submodule 0 as it will force the RELOAD signal to logic 0.
 *       The master reload signal actual is the submodule 0 local reload signal.
 *
 *     + When choose local reload signal, it can assert when execute the software initialization command, or can
 *       reload immediately if MCTRL[LDOK] is set. The local reload also can select take effect at the next PWM
 *       reload if MCTRL[LDOK] is set. The next PWM reload means need to wait one or more reload opportunities.
 *       - Reload opportunities can be generated on a half compare event (VAL0 register compare) or/and a full
 *         compare event (VAL1 register compare).
 *       - The number of reload opportunities need to wait can choose from 1 to 16.
 *
 *   - The VAL registers logic include 6 16-bit compare registers (VAL0 ~VAL5) and 3 PWM output (PwmX , Pwm23
 *     and Pwm45).Each output use two compare registers, and one VAL register is used to control the turn-on edge,
 *     while another VAL register control the turn-off edge. Each VAL register compare event can be used to
 *     generate interrupt and output trigger.
 *     + The VALx register compare mode can choose "equal to" or "equal to or greater than", and both under unsigned
 *       mode. The compare mode bit can only be written one time after which it requires a reset to release the bit
 *       for writing again.
 *
 *     + FORCE_OUT initialization can force PwmX and Pwm23/45 output, and the initial output value can select.
 *
 *     + The PwmX use VAL0 (turn-on) and VAL1 (turn-off) registers. The VAL0 used to trigger a half compare event
 *       and the VAL1 used to trigger a full compare event. The PwmX output falling edge will assert local initial
 *       signal.
 *
 *     + The Pwm23 use VAL2 (turn-on) and VAL3 (turn-off). The Pwm23 will transfer to force logic to do further
 *       processing.
 *
 *     + The Pwm45 use VAL4 (turn-on) and VAL5 (turn-off). The Pwm45 will transfer to force logic to do further
 *       processing.
 *
 *     + By set the initial count register value to be the 2's complement of the VAL1 value, the PWM generator
 *       can operates in "signed" mode. Just like set initial count value to 0xFF00, VAL0 to 0x0 and VAL1 to 0x00FF,
 *       (0x100 -1, because the change during the end to start of the PWM period requires a count time) then counter
 *        will count from 0xFF00 to 0xFFFF, then overflow to 0x0 and count to 0x00FF.
 *
 *   - Support force logic to process the Pwm23 and Pwm45 signal from VAL registers logic, and it has two outputs.
 *     (Pwm23_force and Pwm45_force).
 *     + Each force logic output can select between 4 sources : RAW Pwm23/45 ( RAW signal from PWM generation logic)
 *       , invert Pwm23/45, software output (can select logic 0 or 1) and PWM_EXTA/B signal (alternate external
 *       control signals).
 *
 *     + The selection of force logic output source are presented to the signal selection mux only when a selected
 *       FORCE_OUT signal assert. The FORCE_OUT signal support select from multiple signal sources.
 *       1. Local software force signal, will transfer to other submodules as master force signal.
 *       2. Master force signal form submodule 0. Should not be used in submodule 0 as it will hold the FORCE_OUT
 *          signal to logic 0.
 *       3. Local reload signal.
 *       4. Master reload signal form submodule 0. Should not be used in submodule 0 as it will hold the FORCE_OUT
 *          signal to logic 0.
 *       5. Local sync signal.
 *       6. Master sync signal form submodule 0. Should not be used in submodule 0 as it will hold the
 *          FORCE_OUT signal to logic 0.
 *       7. External force signal (EXT_FORCE) from outside the PWM module.
 *       8. External sync signal (EXT_SYNC) from outside the PWM module.
 *
 *   - Support deadtime insertion logic, which can insert dead time in its input source, and make the deadtime
 *     insertion logic output (Pwm23_deadtime and Pwm45_deadtime) to be complementary state.
 *     + Deadtime insertion logic input 0/1 can choose source as two types:
 *       1. Input 0 be Pwm23_force and Input 1 Pwm45_force from force logic.
 *       2. Both input0/1 be double switching signal ("Pwm23_force XOR Pwm45_force" signal).
 *
 *     + Deadtime insertion logic two output can select works as complementary mode or independent mode, and dead
 *       time insertion only takes effect in complementary mode.
 *       1. Complementary mode, the outputs become a pair of complementary signals.
 *         + The complementary signals source can select from Input 0 (Pwm23_force or double switching
 *           signal) or Input 1 (Pwm45_force or double switching signal).
 *         + The output complementary signals will be inserted a number of IPBus clock cycles of deadtime. The
 *           number can be different for each output.
 *         + The inserted number of IPBus clock cycles can be fractional if enable the fractional delay logic,
 *           the smallest unit is 1/32 IPBus clock cycle.
 *       2. Independent mode.
 *         + When the inputs are double switching signal, can enable SPLIT feature to causes Pwm23_deadtime
 *           output occurs when the Pwm23_force is 1 and the Pwm45_force is 0. The Pwm45_deadtime output occurs
 *           when the Pwm45_force is 1 and the Pwm23_force is 0.
 *
 *   - Support fractional delay logic to support more resolution than a single IPBus clock period, it can be used to
 *     achieve fine resolution the rising and falling edges of the Pwm23_deadtime and Pwm45_deadtime, and fine
 *     resolution for the PwmX period. The fractional delay logic can only be used when the IPBus clock is running at
 *     100 MHz.
 *     + Pwm23_deadtime and Pwm45_deadtime rising and falling edges fractional delay value can be different, range
 *       from 1/32 to 31/32 IPBus clock cycle.
 *
 *     + PwmX only support add fractional delay on falling edges, if it is enabled, the largest value for the VAL1
 *       register is 0xFFFE for "unsigned" usage or 0x7FFE for "signed" usage.
 *
 *     + Each output fractional delay feature can be enabled/disabled independent. And module fractional delay
 *       circuit need waiting 25usec after first submodule fractional delay logic power up.
 *
 *   - Support output logic to do flexibility control about fault disabling, polarity/mask control, and output enable.
 *     It process the PWM output form fractional delay logic (Pwm23_fractional_delay, Pwm45_fractional_delay and
 *     PwmX_fractional_delay) and output the final PWM signal (PWM_A , PWM_B and PWM_X). It also process the compare
 *     trigger output from PWM generation logic.
 *
 *     + Final PWM output signal under no-fault status be processed follow the steps below:
 *       1. Select mask output (logic 0 before polarity select) or normal output.
 *       2. Select polarity as invert or not invert.
 *       3. Select enable or disable output (disable with tristated status).
 *
 *     + Final PWM output signal under fault status (fault input signal mapping from fault protection channel) can be
 *       follow types:
 *       1. Output with low.
 *       2. Output with high.
 *       3. Output with tristated.
 *
 *     + Final mux trigger output signal (PWM_MUX_TRIG0/1)can choose to use "VAL compare trigger signal" from VAL
 *       registers logic or "final PWM output". The "VAL compare trigger signal" based on the counter value matching
 *       the value in one or more of the VAL0-5 registers.
 *       + The VAL0, VAL2, and VAL4 matching can use to generate PWM_MUX_TRIG0, and VAL1, VAL3, and VAL5 matching
 *         can use to generate PWM_MUX_TRIG1.
 *       + VAL0-5 registers compare trigger signals can be enabled/disabled independent.
 *       + VAL0-5 registers compare trigger signals can be generator on every full compare cycle (every PWM period
 *         which count from INIT to VAL1) or on local reload opportunities (need wait one or more reload
 *         opportunities according to reload configure).
 *
 * + Support enhanced capture (E-Capture) feature to measure both edges of an input signal. Each input signal has an
 *   independent E-Capture logic, which with two input capture circuits (Circuit 0/1). The submodule 16 bits counter are
 *   share for these input capture logic
 *   - The input signals are from PWM_A, PWM_B and PWM_X pins (default works as output and connect to PWM output
 *     signal). When enable input capture, the corresponding PWM output must be disabled.
 *
 *   - The input capture circuit0/1 input source are "raw input signal" and the "output of the edge counter/compare
 *     circuitry".
 *     + When the input source is "raw input signal", the input capture circuit0/1 capture edge can be falling
 *       edges, rising edges and both edges.
 *
 *     + When the input source is "output of the edge counter/compare circuitry", the capture edge selection will be
 *       ignored but it need to choose one edge mode to enable the circuit0/1.
 *
 *     + The edge counter/compare circuitry will counts rising and falling edges on the raw input signal. And
 *       trigger a active edge to the input capture circuit0/1 when it counter value matching the value in 8 bit
 *       capture compare register.
 *
 *   - The input capture circuit0/1 can be enabled/disabled independent, and they can work at one shot mode, which
 *     make both circuit0/1 works only once.
 *
 * + Support fault protection channel logic, one PWM can contain one or more fault protection channels. The fault
 *   protection channel process the input fault pin signals and output the faults status to all PWM submodules. When the
 *   faults status are mapped on submodules, it can disables PWM outputs (the submodule PWM generator continues to run,
 *   only the output pins are forced to logic 0, logic 1, or tristated status). The fault protection is enabled even
 *   when the PWM module clock is disabled.
 *   - Each fault protection channel has 4 independent input fault pins. And the active logic level of the individual
 *     fault inputs can be logic 0 or logic 1. Each fault pin has a programmable filter that can be bypassed, and the
 *     fault inputs signal can combined with the the filtered and latched fault input signal to disable the PWM
 *     outputs.
 *
 *   - Fault protection channel supports two different states (FFPIN and FFLAG).
 *     1. The FFPIN bits reflect the current state of the filtered FAULTx pins converted to high polarity. A logic 1
 *        indicates a fault condition exists on the filtered FAULTx pin.
 *     2. The FFLAG bits are set within two CPU cycles after a transition to active on the FAULTx pin. FFLAG only
 *        can be cleared by writing a logic one to it.
 *
 *   - Fault protection channel can select automatic or manual clearing mode to disable the PWM output. Each
 *     submodule PWM output (PwmA, PwmB and PwmX) can be disabled by each fault protection channel 4 fault input
 *     condition status independent.
 *     1. Manual fault clearing normal mode. The PWM output disable when FFLAG status set, and will not
 *        re-enable until FFLAG is clear at the start of a half cycle or full cycle without regard to the state of
 *        FFPIN.
 *     2. Manual fault clearing safe mode. The PWM output disable when FFLAG status set, and will not re-enable
 *        until FFLAG and FFPIN are clear at the start of a half cycle or full cycle.
 *     3. Automatic fault clearing. The PWM output disable when FFPIN status set, and will re-enable
 *        automatic base on FFPIN value at the start of a half cycle or full cycle.
 *
 * + Supports Interrupts.
 *   - Submodule interrupt.
 *     1. Compare VAL0-5 interrupt.
 *     2. Capture A0/1, B0/1 and X0/1 interrupt.
 *     3. Reload interrupt.
 *     4. Reload error interrupt.
 *
 *   - Fault protection channel interrupt.
 *     1. Each channel has 4 FAULT condition interrupt.
 *
 * + Supports DMA.
 *   - Submodule DMA request.
 *     1. Independent capture A0/1, B0/1 and X0/1 will trigger DMA read requests for the Capture A0/1, B0/1 and X0/1
 *        FIFO data. Will be selected as FIFO watermarks source for DMA read capture FIFOs request when enable.
 *        Can't works will capture interrupt.
 *     2. Reload will trigger DMA write requests for the VALx and FRACVALx registers.
 *     3. DMA read capture FIFOs request which the trigger source can select. The trigger source can be:
 *       - Exceeding a FIFO watermark sets the DMA read request. Need to enable at least one of the capture DMA
 *         request to decide use which capture FIFO. Multiple selected FIFO watermarks are OR'ed/AND'ed together.
 *       - A local initial (VAL1 matches counter) sets the read DMA request.
 *       - A local reload (STS[RF] being set) sets the read DMA request.
 *
 *
 * How this peripheral works
 * -------------------------
 * + PWM generation mode
 *   In this mode, the enhanced capture (E-Capture) logic is not used.
 *   1. Submodule start count up with input source rising edge until its value equals VAL1. This compare causes a
 *      rising edge to occur on the Local sync signal which is one of four possible sources used to cause the 16 bit
 *      counter to be initialized with INIT.
 *   2. During counting, the VAL0-5 registers compare make the corresponding output turn-on and turn-off, then the
 *      VAL registers logic output will process by force logic, deadtime insertion logic, fractional delay logic and
 *      output logic, final generate PWM output.
 *   3. Fault protection logic provide output faults status, which can mapping to disable submodule PWM output.
 *
 * + Input capture mode
 *   In this mode, the enhanced capture (E-Capture) logic is used.
 *   1. Submodule start count up with input source rising edge until its value equals VAL1, This compare causes a
 *      rising edge to occur on the Local sync signal which is one of four possible sources used to cause the 16 bit
 *      counter to be initialized with INIT.
 *   2. Enable the PWM output pin capture feature to make it works as an input signal. The CVALx registers
 *      associated with that pin will record the counter values when capture occurs.
 *
 * How this driver are designed to make this peripheral works
 * ===========================================================
 * The PWM driver provides the structure @ref pwm_config_t, which contain four submodule configure structure pointers
 * and two fault protection channel configure structure pointers, only actually used submodule/fault channels need to
 * assign a value to its structure pointer. This is want to save stack space. The channel configure structure @ref
 * pwm_sm_config_t which contain several sub-structures and other member to cover all feature of one PWM submodule. The
 * PWM_Init() function takes the argument in type of @ref pwm_config_t, and can complete the initialization of the PWM
 * module. Since PWM is very flexible and has a very complex function configuration, use sub-structures to facilitate
 * the understanding of the module and provide function APIs to take them as parameters. Base on the sub-structures and
 * other behaviors of PWM submodule, the PWM driver can be divided into several function API groups.
 *
 * + Initialization and De-initialization Interfaces.
 *     The APIs in this function group can be used to initialize or de-initialize the PWM module.
 * + Submodule PWM Generation Related Interfaces.
 *     The APIs in this function group can be used to configure submodule PWM generation related options. Include
 *     counter control, reload logic Control, force logic control, deadtime insert control, fractional delay feature
 *     control and final output control. Also provide a API to do the complete channel initialization.
 * + Submodule Input Capture Related Interfaces.
 *     The APIs in this function group can be used to configure submodule enhanced capture (E-Capture) logics.
 * + Fault Protection Channel Related Interfaces.
 *     The APIs in this function group can be used to configure fault protection channel.
 * + DMA Control Interfaces.
 *     The APIs in this function group can be used to set DMA features. Such as select DMA enable source select,
 *     enable/disable DMA.
 * + Interrupt Control Interfaces.
 *     The APIs in this function group can be used to enable/disable submodule or fault protection channnel interrupts.
 * + Status Flag Interfaces.
 *     The APIs in this function group can be used to get or clear the status flag of the PWM submodules and fault
 *     protection channels.
 *
 *
 * How to use this driver
 * =============================
 * + Steps shall be done outside PWM driver
 *   - Initialize the pin or/and XBAR with expected features configured. PWM input signal (fault input or input
 *     capture) can from chip pin or other peripheral output, and PWM output signal can connect to chip pin or other
 *     peripheral input.
 *   - SoC level interrupt controller configuration shall be configured / enabled in application codes if PWM
 *     is expected to generator interrupt on submodule compare event, submodule input capture event, submodule reload
 *     event or fault protection channel fault status event.
 *   - Interrupt entry function shall be added in the application codes and interrupt handler function shall be placed
 *     in the entry function to make sure the implemented interrupt handling codes will be invoked on a generation of
 *     interrupt.
 *   - Enable DMA and configure DMA channel trigger source in application codes if PWM submodule is expected to
 *     generator DMA request on input capture event or submodule reload/sync event.
 *
 * + Sets the PWM work mode by invoking PWM_Init()
 *   - [Optional] Invokes PWM_GetSMDefaultConfig() function to get the submodule default configuration.
 *   - [Optional] Invokes PWM_GetFaultProtectionDefaultConfig() function to get the fault protection channel default
 *                configuration.
 *   - [Optional] Invokes PWM_GetValueConfig() function to get the VALn registers configuration.
 *   - Set the member of submodule configure structure @ref pwm_sm_config_t to get expected PWM submodule feature.
 *   - Set the member of fault protection channel configure structure @ref pwm_fault_protection_config_t to get
 *     expected fault protection channel feature.
 *   - Set the pointer member of @ref pwm_config_t with the address of "submodule"/"fault protection channel"
 *     configure structure.
 *   - Invokes PWM_Init() to set PWM configuration.
 *     + Submodule counter will start directly when channel configure variable member enableRun is true.
 * + [Optional] Invokes PWM_EnableCounters() to start submodule counter.
 * + [Optional] Invokes function API to get status or do flexible control.
 *
 * Typical Use Case
 * =============================
 * 1. Generate PWM_A/B output with different pulse width and enable fault disable for PWM_A output.
 *   In this typical use case, the PWM submodule will count the rising edges of the IP bus clock divider by 1.
 *   The PWM_A output will be u16PwmPulse/u16PwmPeriod duty cycle PWM, and PWM_B duty cycle be the half of PWM_A. The
 *   PWM_A output will be disabled when the fault pins 0 of the fault protection channel 0 is activated (active
 *   level be logic 0).
 *    @code
 *        pwm_config_t sPwmConfig = {0};
 *        pwm_sm_config_t sSubmoduleConfig;
 *        pwm_fault_protection_config_t sFaultConfig;
 *        uint16_t u16PwmPeriod, u16PwmPulse;
 *        sPwmConfig.psPwmSubmoduleConfig[0] = &sSubmoduleConfig;
 *        sPwmConfig.psFaultProtectionConfig[0] = &sFaultConfig;
 *        PWM_GetSMDefaultConfig(&sSubmoduleConfig);
 *        PWM_GetFaultProtectionDefaultConfig(&sFaultConfig);
 *        PWM_GetValueConfig(&sSubmoduleConfig.sValRegisterConfig, kPWM_SignedCenterAligned, u16PwmPeriod,
 *                                    u16PwmPulse, (u16PwmPulse / 2));
 *        sPwmSm0Config.sPwmAFaultInputMapping.bFaultInput0Mapping = true;
 *        PWM_Init(PWM, &sPwmConfig);
 *        PWM_EnableCounters(PWM, kPWM_SubModule0Enable);
 *    @endcode
 *
 * 2. Generate a pair of center aligned complementary PWM (PWM_B is inverted PWM_A) signals (with dead time insert).
 *   In this typical use case, the PWM submodule 0 will count the rising edges of the IP bus clock divider by 1.
 *   The PWM_A output will be u16PwmPulse/u16PwmPeriod duty cycle PWM, and PWM_B be the inverted of PWM_A. The dead time
 *   can be inserted before the rising edge of PWM_A/B. The inserted value is in the unit of IP clock cycle and PWM_A/B
 *   can choose to insert different values.
 *    @code
 *        pwm_config_t sPwmConfig = {0};
 *        pwm_sm_config_t sSubmoduleConfig;
 *        uint16_t u16PwmPeriod, u16PwmPulse, u16DeadTime;
 *        sPwmConfig.psPwmSubmoduleConfig[0] = &sSubmoduleConfig;
 *        PWM_GetSMDefaultConfig(&sSubmoduleConfig);
 *        PWM_GetValueConfig(&sSubmoduleConfig.sValRegisterConfig, kPWM_SignedCenterAligned, u16PwmPeriod,
 *                                    u16PwmPulse, u16PwmPulse);
 *        sSubmoduleConfig.sDeadTimeConfig.eMode = kPWM_ComplementaryWithPwmA;
 *        sSubmoduleConfig.sDeadTimeConfig.sDeadTimeValue0.bitsIntegerCycles = u16DeadTime;
 *        sSubmoduleConfig.sDeadTimeConfig.sDeadTimeValue1.bitsIntegerCycles = u16DeadTime;
 *        PWM_Init(PWM, &sPwmConfig);
 *        PWM_EnableCounters(PWM, kPWM_SubModule0Enable);
 *    @endcode
 *
 * 3. Generate phase shifted PWMs
 *   In this typical use case, the PWM submodule 0 will start count the rising edges of the IP bus clock divider by 1.
 *   Submodule 1 count on same clock with submodule 0. And the PWM_A output of submodules 1 be delayed from the output
 *   of submodule 0 with same PWM period and same PWM pulse width.
 *    @code
 *        pwm_config_t sPwmConfig = {0};
 *        pwm_sm_config_t sSubmoduleConfig0, sSubmoduleConfig1;
 *        uint16_t u16PwmPeriod, u16PwmPulse, u16PhaseDelay;
 *        sPwmConfig.psPwmSubmoduleConfig[0] = &sSubmoduleConfig0;
 *        sPwmConfig.psPwmSubmoduleConfig[0] = &sSubmoduleConfig1;
 *        PWM_GetSMDefaultConfig(&sSubmoduleConfig0);
 *        PWM_GetSMDefaultConfig(&sSubmoduleConfig1);
 *        PWM_GetValueConfig(&sSubmoduleConfig.sValRegisterConfig, kPWM_SignedCenterAligned, u16PwmPeriod,
 *                                    u16PwmPulse, u16PwmPulse);
 *        sSubmoduleConfig1.sCounterConfig.eCountClockSource = kPWM_ClockSrcSubmodule0Clock;
 *        sSubmoduleConfig1.sCounterConfig.eCountInitSource = kPWM_InitOnMasterSync;
 *        sSubmoduleConfig1.sCounterConfig.u16PhaseDelayValue = u16PhaseDelay;
 *        PWM_Init(PWM, &sPwmConfig);
 *        PWM_EnableCounters(PWM, kPWM_SubModule0Enable | kPWM_SubModule1Enable);
 *    @endcode
 * @}
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief The enumeration for PWM submodule number.
 */
typedef enum _pwm_sm_number
{
    kPWM_SubModule0 = 0U, /*!< PWM Submodule 0 */
    kPWM_SubModule1,      /*!< PWM Submodule 1 */
    kPWM_SubModule2,      /*!< PWM Submodule 2 */
    kPWM_SubModule3       /*!< PWM Submodule 3 */
} pwm_sm_number_t;

/*!
 * @brief The enumeration for PWM submodule enable.
 */
enum _pwm_sm_enable
{
    kPWM_SubModule0Enable = (1U << 0U), /*!< PWM Submodule 0 enable. */
    kPWM_SubModule1Enable = (1U << 1U), /*!< PWM Submodule 1 enable. */
    kPWM_SubModule2Enable = (1U << 2U), /*!< PWM Submodule 2 enable. */
    kPWM_SubModule3Enable = (1U << 3U), /*!< PWM Submodule 3 enable. */
    kPWM_ALLSubModuleEnable =
        (kPWM_SubModule0Enable | kPWM_SubModule1Enable | kPWM_SubModule2Enable | kPWM_SubModule3Enable)
};

/*!
 * @brief The enumeration for PWM submodule clock source.
 */
typedef enum _pwm_sm_count_clock_source
{
    kPWM_ClockSrcBusClock = 0U,  /*!< The IPBus clock is used as the source clock */
    kPWM_ClockSrcExternalClock,  /*!< EXT_CLK is used as the source clock */
    kPWM_ClockSrcSubmodule0Clock /*!< Clock of the submodule 0 (AUX_CLK) is used as the source clock */
} pwm_sm_count_clock_source_t;

/*!
 * @brief The enumeration for PWM submodule prescaler factor selection for clock source.
 */
typedef enum _pwm_sm_count_clock_prescaler
{
    kPWM_ClockPrescaleDivide1 = 0U, /*!< PWM submodule clock frequency = fclk/1 */
    kPWM_ClockPrescaleDivide2,      /*!< PWM submodule clock frequency = fclk/2 */
    kPWM_ClockPrescaleDivide4,      /*!< PWM submodule clock frequency = fclk/4 */
    kPWM_ClockPrescaleDivide8,      /*!< PWM submodule clock frequency = fclk/8 */
    kPWM_ClockPrescaleDivide16,     /*!< PWM submodule clock frequency = fclk/16 */
    kPWM_ClockPrescaleDivide32,     /*!< PWM submodule clock frequency = fclk/32 */
    kPWM_ClockPrescaleDivide64,     /*!< PWM submodule clock frequency = fclk/64 */
    kPWM_ClockPrescaleDivide128     /*!< PWM submodule clock frequency = fclk/128 */
} pwm_sm_count_clock_prescaler_t;

/*!
 * @brief The enumeration for PWM submodule counter initialization options.
 */
typedef enum _pwm_sm_count_init_source
{
    kPWM_InitOnLocalSync = 0U, /*!< Local sync causes initialization */
    kPWM_InitOnMasterReload,   /*!< Master reload from submodule 0 causes initialization */
    kPWM_InitOnMasterSync,     /*!< Master sync from submodule 0 causes initialization */
    kPWM_InitOnExtSync         /*!< EXT_SYNC causes initialization */
} pwm_sm_count_init_source_t;

/*!
 * @brief The enumeration for PWM stretch IPBus clock count prescaler for
 * mux0_trig/mux1_trig/out0_trig/out1_trig/pwma_trig/pwmb_trig
 */
typedef enum _pwm_ml2_stretch_count_clock_prescaler
{
    kPWM_StretchIPBusClockPrescaler1 = 0U, /*!< Stretch count is zero, no stretch. */
    kPWM_StretchIPBusClockPrescaler2, /*!< Stretch mux0_trig/mux1_trig/out0_trig/out1_trig/pwma_trig/pwmb_trig for 2
                                         IPBus clock period. */
    kPWM_StretchIPBusClockPrescaler4, /*!< Stretch mux0_trig/mux1_trig/out0_trig/out1_trig/pwma_trig/pwmb_trig for 4
                                         IPBus clock period. */
    kPWM_StretchIPBusClockPrescaler8  /*!< Stretch mux0_trig/mux1_trig/out0_trig/out1_trig/pwma_trig/pwmb_trig for 8
                                         IPBus clock period. */
} pwm_ml2_stretch_count_clock_prescaler_t;

/*!
 * @brief The structure for configuring PWM submodule counter logic.
 */
typedef struct _pwm_sm_counter_config
{
    pwm_sm_count_clock_source_t eCountClockSource : 2U;       /*!< Configures PWM submodule counter clock source. */
    pwm_sm_count_clock_prescaler_t eCountClockPrescaler : 3U; /*!< Configures PWM submodule counter clock source
                                                                 prescaler. */
    pwm_sm_count_init_source_t eCountInitSource : 2U;         /*!< Configures PWM submodule counter initial source. */

    bool bEnableForceInitial : 1U; /*!< Enable force-controlled initialization. The assert FORCE_OUT signal can to
                                   initialize the counter without regard to the selected initial source. */
#if (defined(FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER) && FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER)
    uint16_t u16PhaseDelayValue; /*!< Defines the delay from the master sync signal of submodule 0 to this submodule
                                    counter (the unit of delay is the PWM clock cycle), only works when chose
                                    kPWM_InitOnMasterSync as initial source. */
#endif
} pwm_sm_counter_config_t;

/*!
 * @brief The enumeration for PWM submodule local reload take effect timing.
 */
typedef enum _pwm_sm_reload_signal_select
{
    kPWM_LocalReloadSignal = 0U, /*!<  The local RELOAD signal is used to reload buffered-registers. */
    kPWM_MasterReloadSignal,     /*!< The master RELOAD signal (from submodule 0) is used to reload buffered-registers
                              (should not be used in submodule 0). */
} pwm_sm_reload_signal_select_t;

/*!
 * @brief The enumeration for PWM submodule local reload take effect timing.
 */
typedef enum _pwm_sm_local_reload_effect_timing
{
    kPWM_TakeEffectAtReloadOportunity = 0U, /*!< Buffered-registers reload after one/more reload opportunities, and a
                                             load opportunity can generate on a PWM half or/and full cycle. */
    kPWM_TakeEffectImmediately, /*!< Buffered-registers reload with new values as soon as MCTRL[LDOK] bit is set
                                         when choose local reload. */
} pwm_sm_local_reload_effect_timing_t;

/*!
 * @brief The enumeration for PWM submodule reload opportunities selection under kPWM_ReloadWithLocalReloadOportunity.
 */
typedef enum _pwm_sm_local_reload_oportunity
{
    kPWM_LoadEveryOportunity = 0U, /*!< Every PWM submodule reload opportunity */
    kPWM_LoadEvery2Oportunity,     /*!< Every 2 PWM submodule reload opportunities */
    kPWM_LoadEvery3Oportunity,     /*!< Every 3 PWM submodule reload opportunities */
    kPWM_LoadEvery4Oportunity,     /*!< Every 4 PWM submodule reload opportunities */
    kPWM_LoadEvery5Oportunity,     /*!< Every 5 PWM submodule reload opportunities */
    kPWM_LoadEvery6Oportunity,     /*!< Every 6 PWM submodule reload opportunities */
    kPWM_LoadEvery7Oportunity,     /*!< Every 7 PWM submodule reload opportunities */
    kPWM_LoadEvery8Oportunity,     /*!< Every 8 PWM submodule reload opportunities */
    kPWM_LoadEvery9Oportunity,     /*!< Every 9 PWM submodule reload opportunities */
    kPWM_LoadEvery10Oportunity,    /*!< Every 10 PWM submodule reload opportunities */
    kPWM_LoadEvery11Oportunity,    /*!< Every 11 PWM submodule reload opportunities */
    kPWM_LoadEvery12Oportunity,    /*!< Every 12 PWM submodule reload opportunities */
    kPWM_LoadEvery13Oportunity,    /*!< Every 13 PWM submodule reload opportunities */
    kPWM_LoadEvery14Oportunity,    /*!< Every 14 PWM submodule reload opportunities */
    kPWM_LoadEvery15Oportunity,    /*!< Every 15 PWM submodule reload opportunities */
    kPWM_LoadEvery16Oportunity     /*!< Every 16 PWM submodule reload opportunities */
} pwm_sm_local_reload_oportunity_t;

/*!
 * @brief The structure for configuring PWM submodule reload logic.
 */
typedef struct _pwm_sm_reload_logic_config
{
    pwm_sm_reload_signal_select_t eReloadSignalSelect : 1U; /*!< Configures PWM submodule RELOAD signal source to be
                                                         local reload signal or master reload signal.*/
    pwm_sm_local_reload_effect_timing_t eLoclReloadEffectTime : 1U; /*!< Configures PWM submodule local reload signal
                                                        effective timing when choose it as RELOAD signal source. */
    bool bEnableFullCycleReloadOportunity : 1U; /*!< Enable generate a reload opportunity on PWM half cycle (count from
                                                   INIT value to VAL0). */
    bool bEnableHalfCycleReloadOportunity : 1U; /*!< Enable generate a reload opportunity on PWM full cycle (count from
                                                   INIT value to VAL1). */
    pwm_sm_local_reload_oportunity_t eLocalReloadOportunity : 4U; /*!< Configures PWM submodule reload frequency when
                                                                    using local reload opportunities mode . */
} pwm_sm_reload_logic_config_t;
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD)
/*!
 * @brief The enumeration for PWM submodule VALn register compare mode.
 */
typedef enum _pwm_sm_val_compare_mode
{
    kPWM_CompareOnEqual = 0U, /*!< The VALn registers and the PWM counter are compared using an "equal to" method. */
    kPWM_CompareOnEqualOrGreater, /*!< The VALn registers and the PWM counter are compared using an "equal to or
                                     greater than" method. */
} pwm_sm_val_compare_mode_t;
#endif
/*!
 * @brief The enumeration for PWM submodule VAL registers.
 */
typedef enum _pwm_sm_val_register
{
    kPWM_VAL0 = 0U, /*!< PWM submodule value register 0. */
    kPWM_VAL1,      /*!< PWM submodule value register 1. */
    kPWM_VAL2,      /*!< PWM submodule value register 2. */
    kPWM_VAL3,      /*!< PWM submodule value register 3. */
    kPWM_VAL4,      /*!< PWM submodule value register 4. */
    kPWM_VAL5       /*!< PWM submodule value register 5. */
} pwm_sm_val_register_t;

/*!
 * @brief The structure for configuring PWM submodule value registers.
 */
typedef struct _pwm_sm_value_register_config
{
    uint16_t u16CounterInitialValue; /*!< Configures PWM submodule counter initial value. */
    uint16_t u16ValRegister0;        /*!< Configures PWM submodule value register 0 (VAL0) value. */
    uint16_t u16ValRegister1;        /*!< Configures PWM submodule value register 1 (VAL1) value. */
    uint16_t u16ValRegister2;        /*!< Configures PWM submodule value register 2 (VAL2) value. */
    uint16_t u16ValRegister3;        /*!< Configures PWM submodule value register 3 (VAL3) value. */
    uint16_t u16ValRegister4;        /*!< Configures PWM submodule value register 4 (VAL4) value. */
    uint16_t u16ValRegister5;        /*!< Configures PWM submodule value register 5 (VAL5) value. */
} pwm_sm_value_register_config_t;

/*!
 * @brief The enumeration for PWM submodule FORCE_OUT source which can trigger force logic output update.
 */
typedef enum _pwm_sm_force_signal_select
{
    kPWM_LocalSoftwareForce = 0U, /*!< The local software force signal CTRL2[FORCE] is used to force updates. */
    kPWM_MasterSoftwareForce,     /*!< The master software force signal from submodule 0 is used to force updates. */
    kPWM_LocalReloadForce,        /*!< The local reload signal from this submodule is used to force updates without
                                      regard to the state of LDOK. */
    kPWM_MasterReloadForce,       /*!< The master reload signal from submodule 0 is used to force updates if LDOK is
                                             set, should not be used in submodule 0. */
    kPWM_LocalSyncForce,          /*!< The local sync (VAL1 match event) signal from this submodule is used to force
                                          updates. */
    kPWM_MasterSyncForce,         /*!< The master sync signal from submodule0 is used to force updates. */
    kPWM_ExternalForceForce, /*!< The external force signal EXT_FORCE, from outside the PWM module causes updates. */
    kPWM_ExternalSyncForce   /*!< The external sync signal EXT_SYNC, from outside the PWM module causes updates. */
} pwm_sm_force_signal_select_t;

/*!
 * @brief The enumeration for PWM submodule force out logic output (PWM23 and PWM45) source, which will transfer to
 *        output logic when a FORCE_OUT signal is asserted.
 */
typedef enum _pwm_sm_force_deadtime_source
{
    kPWM_GeneratedPwm = 0U,    /*!< Generated PWM signal is used as the deadtime logic output. */
    kPWM_InvertedGeneratedPwm, /*!< Inverted PWM signal is used as the deadtime logic output. */
    kPWM_SoftwareControlValue, /*!< Software controlled value is used as the deadtime logic output. */
    kPWM_UseExternal           /*!< PWM_EXTA signal is used as the deadtime logic output. */
} pwm_sm_force_deadtime_source_t;

/*!
 * @brief The enumeration for PWM submodule software controlled force out signal value.
 */
typedef enum _pwm_sm_force_software_output_value
{
    kPWM_SoftwareOutputLow = 0U, /*!< A logic 0 is supplied to the deadtime generator when chose Software
                                           controlled value as output source.*/
    kPWM_SoftwareOutputHigh,     /*!< A logic 1 is supplied to the deadtime generator when chose Software
                                           controlled value as output source.*/
} pwm_sm_force_software_output_value_t;

/*!
 * @brief The structure for configuring PWM submodule force logic.
 */
typedef struct _pwm_sm_force_logic_config
{
    uint8_t bitPWM23OutputInitialVaule : 1U; /*!< Configures PWM submodule compare output x (PwmX) initial value. */
    uint8_t bitPWM45OutputInitialVaule : 1U; /*!< Configures PWM submodule compare output A (PwmA) initial value. */
    uint8_t bitPWMXOutputInitialVaule : 1U;  /*!< Configures PWM submodule compare output B (PwmB) initial value. */
    pwm_sm_force_signal_select_t eForceSignalSelect : 3U; /*!< Configures PWM submodule force out select update trigger
                                                               source. */
    pwm_sm_force_software_output_value_t eSoftOutputFor23 : 1U; /*!< Configures PWM submodule force out PwmA value
                                                                        when select software as output source. */
    pwm_sm_force_software_output_value_t eSoftOutputFor45 : 1U; /*!< Configures PWM submodule force out PwmB value
                                                                        when select software as output source. */
    pwm_sm_force_deadtime_source_t eForceOutput23 : 2U;         /*!< Configures the source of Pwm23, which will be force
                                                                         to deadtime logic. */
    pwm_sm_force_deadtime_source_t eForceOutput45 : 2U;         /*!< Configures the source of Pwm45, which will be force
                                                                         to deadtime logic. */
} pwm_sm_force_logic_config_t;

/*!
 * @brief The enumeration for PWM submodule deadtime logic mode, which decide how the deadtime logic process the force
 *        logic output signal.
 */
typedef enum _pwm_sm_deadtime_logic_mode
{
    kPWM_Independent = 0U, /*!< The PWMA (PWM23) and PWMB (PWM45) signal from force logic transfer to output
                                      logic independent. */
    kPWM_IndependentWithDoubleSwitchPwm, /*!< The PWMA (PWM23) and PWMB (PWM45) signals from force logic
                                                    will XOR first, then the XOR signal transfer to output logic
                                                    independent. */
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD)
    kPWM_IndependentWithSplitDoubleSwitchPwm, /*!< The PWMA (PWM23) and PWMB (PWM45) signals from force_out
                                                    logic will XOR first, then the XOR signal transfer to output logic
                                                    independent. */
#endif
    kPWM_ComplementaryWithPwmA,            /*!< The PWMA (PWM23) signal from force logic will transfer to output logic
                                                       with complementary mode. */
    kPWM_ComplementaryWithPwmB,            /*!< The PWMB (PWM45) signal from force logic will transfer to output logic
                                                       with complementary mode. */
    kPWM_ComplementaryWithDoubleSwitchPwm, /*!< The PWMA (PWM23) and PWMB (PWM45) signals from force logic
                                                    will XOR first, then the XOR signal transfer to output logic with
                                                    complementary mode. */
} pwm_sm_deadtime_logic_mode_t;

/*!
 * @brief The structure of the inserted dead time value, applies only to KPWM_Complementaryxxx mode.
 */
typedef struct _pwm_sm_deadtime_value
{
#if (defined(FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT) && (FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT == 16U))
    uint16_t bitsFractionalCycles : 5U; /*!< Specify the fractional cycle added to the number of integer deadtime
                                         cycles. In terms of 1/32 IPBus clock cycles, range is 0x0 ~ 0x1F. Only valid
                                         when the fractional delays feature is enabled (FRCNTRL[FRAC23_EN]
                                         is set when PWM23 is used to generate complementary PWM, or FRCNTRL[FRAC45_EN])
                                         is set when PWM45 is used to generate complementary PWM. */
    uint16_t bitsIntegerCycles : 11U; /*!< Specify the number of integer deadtime cycles. In terms of IPBus clock
                                          cycles, range is 0x0 ~ 0x7FF. */
#elif (defined(FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT) && (FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT == 11U))
    uint16_t bitsIntegerCycles : 11U; /*!< Specify the number of integer deadtime cycles. In terms of IPBus clock
                                          cycles, range is 0x0 ~ 0x7FF. */
#else
#endif
} pwm_sm_deadtime_value_t;

/*!
 * @brief The structure for configuring PWM submodule force out logic, works on the deadtime logic output.
 */
typedef struct _pwm_sm_deadtime_logic_config
{
    pwm_sm_deadtime_logic_mode_t eMode; /*!< The mode in which Deadtime logic process the force logic output signal. */
    pwm_sm_deadtime_value_t sDeadTimeValue0; /*!< Control the deadtime during 0 to 1 transitions of the PWM_23 output
                            (assuming normal polarity). When disable fractional delays, the maximum value is 0x7FF which
                            represents 2047 cycles of IP bus cycles. When enable fractional delays, the maximum value is
                            0xFFFF which represents 2047 31/32 cycles cycles of IP bus cycles. */
    pwm_sm_deadtime_value_t sDeadTimeValue1; /*!< Control the deadtime during 0 to 1 transitions of the PWM_45 output
                             (assuming normal polarity). When disable fractional delays, the maximum value is 0x7FF
                             which represents 2047 cycles of IP bus cycles. When enable fractional delays, the maximum
                             value is 0xFFFF which represents 2047 31/32 cycles cycles of IP bus cycles. */
} pwm_sm_deadtime_logic_config_t;

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
/*!
 * @brief The enumeration for PWM submodule FRACVAL registers.
 */
typedef enum _pwm_sm_fracval_register
{
    kPWM_FRACVAL1 = 1U, /*!< PWM submodule fractional value register 1. */
    kPWM_FRACVAL2,      /*!< PWM submodule fractional value register 2. */
    kPWM_FRACVAL3,      /*!< PWM submodule fractional value register 3. */
    kPWM_FRACVAL4,      /*!< PWM submodule fractional value register 4. */
    kPWM_FRACVAL5,      /*!< PWM submodule fractional value register 5. */
} pwm_sm_fracval_register_t;

/*!
 * @brief The structure for configuring PWM submodule fractional delay logic, works on the deadtime logic output.
 */
typedef struct _pwm_sm_fractional_delay_logic_config
{
    uint8_t bitsFracValue1 : 5U; /*!< Configures PWM submodule compare register VAL1 fractional delay value, the unit
                                     is 1/32 IP bus clock. */
    bool bEnableVal1FractionalDelay; /*!< Enable the fractional delay feature of bitsFracValue1. */
    uint8_t bitsFracValue2 : 5U; /*!< Configures PWM submodule compare register VAL2 fractional delay value, the unit
                                     is 1/32 IP bus clock. */
    uint8_t bitsFracValue3 : 5U; /*!< Configures PWM submodule compare register VAL3 fractional delay value, the unit
                                     is 1/32 IP bus clock. */
    bool bEnableVal23FractionalDelay; /*!< Enable the fractional delay feature of bitsFracValue2 and bitsFracValue3. */
    uint8_t bitsFracValue4 : 5U; /*!< Configures PWM submodule compare register VAL4 fractional delay value, the unit
                                     is 1/32 IP bus clock. */
    uint8_t bitsFracValue5 : 5U; /*!< Configures PWM submodule compare register VAL5 fractional delay value, the unit
                                     is 1/32 IP bus clock. */
    bool bEnableVal45FractionalDelay; /*!< Enable the fractional delay feature of bitsFracValue4 and bitsFracValue5. */
} pwm_sm_fractional_delay_logic_config_t;

#endif
/*!
 * @brief The enumeration for PWM submodule output logic final trigger output port signal.
 */
typedef enum _pwm_sm_mux_trigger_source
{
    kPWM_ActualCompareEvent = 0U, /*!< Route the PWM_OUT_TRIG signal (OR of VALx compare signal) to the mux trigger
                                     output port. */
    kPWM_PwmOutput, /*!< Route the PWM output (after polarity/mask/enable control) to the mux trigger output port. */

} pwm_sm_mux_trigger_source_t;

/*!
 * @brief The enumeration for PWM submodule output logic PWM output fault status.
 */
typedef enum _pwm_sm_pwm_output_on_fault
{
    kPWM_OutputLowOnFault = 0U, /*!< The output is forced to logic 0 state prior to consideration of output
                            polarity/mask/enable control during fault conditions and STOP mode. */
    kPWM_OutputHighOnFault,     /*!< The output is forced to logic 1 state prior to consideration of output
                                 polarity/mask/enable control during fault conditions and STOP mode. */
    kPWM_OutputTristatedOnFault /*!< The output status be tristated during fault conditions and STOP mode. */
} pwm_sm_pwm_output_on_fault_t;

/*!
 * @brief The enumeration for PWM submodule output logic PwmX signal input source (before output polarity/mask/enable
 *        control).
 */
typedef enum _pwm_sm_pwmx_signal_select
{
    kPWM_RawPwmX = 0U, /*!< The PWM_X source is raw Pwm01_fractional_delay signal. */
    kPWM_DoubleSwitch, /*!< The PWM_X source is Pwm23_fractional_delay XOR Pwm23_fractional_delay signal. */
} pwm_sm_pwmx_signal_select_t;

/*!
 * @brief The enumeration for PWM submodule PWM output.
 */
typedef enum _pwm_sm_pwm_out
{
    kPWM_PwmX = 0U, /*!< The PWM output PWM_X. */
    kPWM_PwmB,       /*!< The PWM output PWM_B. */
    kPWM_PwmA      /*!< The PWM output PWM_A. */
} pwm_sm_pwm_out_t;

/*!
 * @brief The structure for configuring PWM submodule output logic.
 */
typedef struct _pwm_sm_output_logic_config_t
{
    bool bVal0TriggerEnable : 1U; /*!< Enable VAL0 register compare event trigger. */
    bool bVal1TriggerEnable : 1U; /*!< Enable VAL1 register compare event trigger. */
    bool bVal2TriggerEnable : 1U; /*!< Enable VAL2 register compare event trigger. */
    bool bVal3TriggerEnable : 1U; /*!< Enable VAL3 register compare event trigger. */
    bool bVal4TriggerEnable : 1U; /*!< Enable VAL4 register compare event trigger. */
    bool bVal5TriggerEnable : 1U; /*!< Enable VAL5 register compare event trigger. */
#if (defined(FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD) && FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD)
    bool bEnableTriggerPostScaler : 1U; /*!< True : Trigger outputs are generated only during the final PWM period prior
                                           to a reload opportunity, false : Trigger outputs are generated during every
                                           PWM period. */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL) && FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL)
    /*!< Configures PWM submodule mux trigger output signal 0 source. */
    pwm_sm_mux_trigger_source_t eMuxTrigger0 : 1U;
    /*!< Configures PWM submodule mux trigger output signal 1 source. */
    pwm_sm_mux_trigger_source_t eMuxTrigger1 : 1U;
#endif
    /*!< Configures PWM submodule PWM_X output source (before polarity/mask/enable control). */
    pwm_sm_pwmx_signal_select_t ePwmXSignalSelect : 1U;
    bool bInvertPwmxOutput : 1U; /*!< True : invert PWM_X output, false : no invert PWM_X output. */
    bool bInvertPwmaOutput : 1U; /*!< True : invert PWM_A output, false : no invert PWM_A output. */
    bool bInvertPwmbOutput : 1U; /*!< True : invert PWM_B output, false : no invert PWM_B output. */
    bool bMaskPwmxOutput : 1U;   /*!< True : PWM_X output masked, false : PWM_X output normal. Mask bit is buffered, and
                                    take effect until FORCE_OUT event or software update command. */
    bool bMaskPwmaOutput : 1U;   /*!< True : PWM_A output masked, false : PWM_A output normal. Mask bit is buffered, and
                                    take effect until FORCE_OUT event or software update command. */
    bool bMaskPwmbOutput : 1U;   /*!< True : PWM_B output masked, false : PWM_B output normal. Mask bit is buffered, and
                                    take effect until FORCE_OUT event or software update command. */
    bool bEnablePwmxOutput : 1U; /*!< True : Enable PWM_X output. false : PWM_X is disabled and output is tristated. */
    bool bEnablePwmaOutput : 1U; /*!< True : Enable PWM_A output. false : PWM_A is disabled and output is tristated. */
    bool bEnablePwmbOutput : 1U; /*!< True : Enable PWM_B output. false : PWM_B is disabled and output is tristated. */
    /*!< Configures PWM submodule PWM_X output during fault status (only works when fault status enable). */
    pwm_sm_pwm_output_on_fault_t ePwmxFaultState : 2U;
    /*!< Configures PWM submodule PWM_A output during fault status (only works when fault status enable). */
    pwm_sm_pwm_output_on_fault_t ePwmaFaultState : 2U;
    /*!< Configures PWM submodule PWM_B output during fault status (only works when fault status enable). */
    pwm_sm_pwm_output_on_fault_t ePwmbFaultState : 2U;
} pwm_sm_output_logic_config_t;

/*!
 * @brief The enumeration for PWM submodule input capture pins.
 */
typedef enum _pwm_sm_input_capture_pin
{
    kPWM_InputCapturePwmX = 0U, /*!< The input capture pin PwmX, need disable PwmX output when enable input capture. */
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    kPWM_InputCapturePwmA, /*!< The input capture pin PwmA, need disable PwmA output when enable input capture. */
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    kPWM_InputCapturePwmB /*!< The input capture pin PwmB, need disable PwmB output when enable input capture. */
#endif
} pwm_sm_input_capture_pin_t;

/*!
 * @brief The enumeration for PWM submodule input capture source.
 */
typedef enum _pwm_sm_input_capture_source
{
    kPWM_RawInput = 0U,    /*!< The capture source is the raw input signal. */
    kPWM_InputEdgeCounter, /*!< The capture source is edge counter which counts rising and falling edges on the raw
                              input signal. */

} pwm_sm_input_capture_source_t;

/*!
 * @brief The enumeration for PWM submodule input capture edge when choose raw input as capture source.
 */
typedef enum _pwm_sm_input_capture_edge
{
    kPWM_Noedge = 0U,    /*!< Disabled capture on source falling/falling edge. */
    kPWM_FallingEdge,    /*!< Enable input capture, and capture on source falling edge when chose the raw input
                              signal as capture source. */
    kPWM_RisingEdge,     /*!< Enable input capture, and capture on source rising edge when chose the raw input
                              signal as capture source. */
    kPWM_RiseAndFallEdge /*!<  Enable input capture, and capture on source rising or falling edge when chose
                            the raw input signal as capture source. */
} pwm_sm_input_capture_edge_t;

/*!
 * @brief The enumeration for PWM submodule input capture value register.
 */
typedef enum _pwm_sm_input_capture_register
{
    kPWM_InpCaptureVal0 = 0U, /*!< Stores the value captured from the submodule counter when the PWM_X circuitry 0
                            logic capture occurs.*/
    kPWM_InpCaptureVal1 = 2U, /*!< Stores the value captured from the submodule counter when the PWM_X circuitry 1
                            logic capture occurs. */
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    kPWM_InpCaptureVal2 = 4U, /*!< Stores the value captured from the submodule counter when the PWM_A circuitry 0
                            logic capture occurs. */
    kPWM_InpCaptureVal3 = 6U, /*!< Stores the value captured from the submodule counter when the PWM_A circuitry 1
                           logic capture occurs. */
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    kPWM_InpCaptureVal4 = 8U, /*!< Stores the value captured from the submodule counter when the PWM_B circuitry 0
                           logic capture occurs. */
    kPWM_InpCaptureVal5 = 10U /*!< Stores the value captured from the submodule counter when the PWM_B circuitry 1
                           logic capture occurs. */
#endif
} pwm_sm_input_capture_register_t;

#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
/*!
 * @brief The enumeration for input filter count
 * Represent the number of consecutive samples that must agree prior to the input filter accepting
 * an input transition.
 */
typedef enum _pwm_sm_input_capture_filter_count
{
    kPWM_InputCaptureFilterCount3Samples  = 0U, /*!< 3  samples. */
    kPWM_InputCaptureFilterCount4Samples  = 1U, /*!< 4  samples. */
    kPWM_InputCaptureFilterCount5Samples  = 2U, /*!< 5  samples. */
    kPWM_InputCaptureFilterCount6Samples  = 3U, /*!< 6  samples. */
    kPWM_InputCaptureFilterCount7Samples  = 4U, /*!< 7  samples. */
    kPWM_InputCaptureFilterCount8Samples  = 5U, /*!< 8  samples. */
    kPWM_InputCaptureFilterCount9Samples  = 6U, /*!< 9  samples. */
    kPWM_InputCaptureFilterCount10Samples = 7U, /*!< 10 samples. */
} pwm_sm_input_capture_filter_count_t;
#endif /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */

/*!
 * @brief The structure for configuring PWM submodule input capture logic.
 *
 * @note When choosing kPWM_InputEdgeCounter as circuit 0/1 capture source, the eCircuit0CaptureEdge and
 *       eCircuit1CaptureEdge selected trigger edge will be ignored, but still need place a value other than
 *       kPWM_Noedge in either or both of the eCaptureCircuit0 and/or CaptureCircuit1 fields in order to
 *       enable one or both of the capture registers.
 */
typedef struct _pwm_sm_input_capture_config
{
    bool bEnableInputCapture : 1U; /*!< True: enable the input capture process, false : disable the input capture
                                      process. */
    pwm_sm_input_capture_source_t eInCaptureSource : 1U;   /*!< Configures capture circuit 0/1 input source */
    pwm_sm_input_capture_edge_t eCircuit0CaptureEdge : 2U; /*!< Configures which edge causes a capture for capture
                                  circuit 0 , will be ignore when use edge counter as capture source. */
    pwm_sm_input_capture_edge_t eCircuit1CaptureEdge : 2U; /*!< Configures which edge causes a capture for capture
                                  circuit 1 , will be ignore when use edge counter as capture source. */
    bool bEnableOneShotCapture : 1U; /*!< True: Enable one-shot capture mode, the bEnableInputCapture will self-cleared
                                   when one or more of the enabled capture circuits has had a capture event;
                                   false: Capture circuit 0/1 will perform capture continue; */
    uint8_t bitsCaptureFifoWatermark : 2U; /*!< Watermark level for circuit 0/1 capture FIFO. The capture flags in
                                the status register will set if the word count in the circuit 0/1 capture FIFO
                                is greater than this watermark level */
    uint8_t u8EdgeCounterCompareValue;     /*!< Edge counter compare value, used only if edge counter is used as capture
                                              circuit 0/1 input source */
#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
    uint8_t u8FilterPeriod; /*!< Sampling period (in IPBus clock cycles) of the input filter, set to 0 to bypass the
                               filter. */
    pwm_sm_input_capture_filter_count_t eFilterCount; /*!< Filter sample count. */
#endif                                                /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */
} pwm_sm_input_capture_config_t;

/*!
 * @brief The enumeration for the source which can trigger the DMA read requests for the capture FIFOs.
 */
typedef enum _pwm_sm_capture_dma_source
{
    kPWM_FIFOWatermarksORDma  = 0x1U, /*!< Selected FIFO watermarks are OR'ed together to sets the read DMA request. */
    kPWM_FIFOWatermarksANDDma = 0x5U, /*!< Selected FIFO watermarks are AND'ed together to sets the read DMA request. */
    kPWM_LocalSyncDma         = 0x2u, /*!< A local sync (VAL1 match event) sets the read DMA request. */
    kPWM_LocalReloadDma       = 0x3U  /*!< A local reload (STS[RF] being set) sets the read DMA request. */
} pwm_sm_capture_dma_source_t;

/*!
 * @brief The structure for configuring PWM submodule read capture DMA.
 */
typedef struct _pwm_sm_capture_dma_config
{
    bool bEnableCaptureDMA : 1U;                        /*!< Enables DMA read requests for the Capture FIFOs. */
    pwm_sm_capture_dma_source_t eCaptureDMASource : 3U; /*!< Select the source to enables DMA read requests for the
                                                    Capture FIFOs. Will be ignored when bEnableCaptureDMA be false. */
} pwm_sm_capture_dma_config_t;

/*!
 * @brief The structure for configuring PWM submodule DMA.
 */
typedef struct _pwm_sm_dma_config
{
    bool bEnableWriteValDMA : 1U;      /*!< STS[RF] set enables DMA write requests for VALx and FRACVALx registers. */
    bool bEnableReadCaptureX0DMA : 1U; /*!< STS[CFX0] set enables DMA read requests for Capture X0 FIFO. And X0 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
    bool bEnableReadCaptureX1DMA : 1U; /*!< STS[CFX1] set enables DMA read requests for Capture X1 FIFO. And X1 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER)
    bool bEnableReadCaptureA0DMA : 1U; /*!< STS[CFA0] set enables DMA read requests for Capture A0 FIFO. And A0 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
    bool bEnableReadCaptureA1DMA : 1U; /*!< STS[CFA1] set enables DMA read requests for Capture A1 FIFO. And A1 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER)
    bool bEnableReadCaptureB0DMA : 1U; /*!< STS[CFB0] set enables DMA read requests for Capture B0 FIFO. And B0 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
    bool bEnableReadCaptureB1DMA : 1U; /*!< STS[CFB1] set enables DMA read requests for Capture B1 FIFO. And B1 FIFO
                                          watermark is selected for sCaptureDma @ref pwm_sm_capture_dma_config_t. */
#endif
    pwm_sm_capture_dma_config_t sCaptureDma; /*!< DMA read requests for the capture FIFOs configure. */
} pwm_sm_dma_config_t;

/*!
 * @brief The enumeration for PWM submodule output fault enable mask for one fault protection channel.
 * @note The channel 0 input 0 and channel 1 input 0 are different pins.
 */
/*!
 * @brief The structure for configuring PWM submodule fault input disable mapping.
 * @note Each PWM output can be mapping anyone or more fault inputs. The mapped fault protection channel inputs can
 *       disable PWM output.
 */
typedef struct _pwm_sm_fault_input_mapping
{
    bool bFaultInput0Mapping : 1U; /*!< Mapping fault input 0 (from fault protection channel 0) to PWM output. */
    bool bFaultInput1Mapping : 1U; /*!< Mapping fault input 1 (from fault protection channel 0) to PWM output. */
    bool bFaultInput2Mapping : 1U; /*!< Mapping fault input 2 (from fault protection channel 0) to PWM output. */
    bool bFaultInput3Mapping : 1U; /*!< Mapping fault input 3 (from fault protection channel 0) to PWM output. */
    bool bFaultInput4Mapping : 1U; /*!< Mapping fault input 4 (from fault protection channel 1) to PWM output. */
    bool bFaultInput5Mapping : 1U; /*!< Mapping fault input 5 (from fault protection channel 1) to PWM output. */
    bool bFaultInput6Mapping : 1U; /*!< Mapping fault input 6 (from fault protection channel 1) to PWM output. */
    bool bFaultInput7Mapping : 1U; /*!< Mapping fault input 7 (from fault protection channel 1) to PWM output. */
} pwm_sm_fault_input_mapping_t;

/*!
 * @brief The enumeration for PWM submodule interrupt enable.
 */
enum _pwm_sm_interrupt_enable
{
    kPWM_CompareVal0InterruptEnable = (1U << 0),  /*!< PWM submodule VAL0 compare interrupt. */
    kPWM_CompareVal1InterruptEnable = (1U << 1),  /*!< PWM submodule VAL1 compare interrupt. */
    kPWM_CompareVal2InterruptEnable = (1U << 2),  /*!< PWM submodule VAL2 compare interrupt. */
    kPWM_CompareVal3InterruptEnable = (1U << 3),  /*!< PWM submodule VAL3 compare interrupt. */
    kPWM_CompareVal4InterruptEnable = (1U << 4),  /*!< PWM submodule VAL4 compare interrupt. */
    kPWM_CompareVal5InterruptEnable = (1U << 5),  /*!< PWM submodule VAL5 compare interrupt. */
    kPWM_CaptureX0InterruptEnable   = (1U << 6),  /*!< PWM submodule capture X0 interrupt. */
    kPWM_CaptureX1InterruptEnable   = (1U << 7),  /*!< PWM submodule capture X1 interrupt. */
    kPWM_CaptureB0InterruptEnable   = (1U << 8),  /*!< PWM submodule capture B0 interrupt. */
    kPWM_CaptureB1InterruptEnable   = (1U << 9),  /*!< PWM submodule capture B1 interrupt. */
    kPWM_CaptureA0InterruptEnable   = (1U << 10), /*!< PWM submodule capture A0 interrupt. */
    kPWM_CaptureA1InterruptEnable   = (1U << 11), /*!< PWM submodule capture A1 interrupt. */
    kPWM_ReloadInterruptEnable      = (1U << 12), /*!< PWM submodule reload interrupt. */
    kPWM_ReloadErrorInterruptEnable = (1U << 13), /*!< PWM submodule reload error interrupt. */
    kPWM_ALLSubModuleInterruptEnable =
        (kPWM_CompareVal0InterruptEnable | kPWM_CompareVal1InterruptEnable | kPWM_CompareVal2InterruptEnable |
         kPWM_CompareVal3InterruptEnable | kPWM_CompareVal4InterruptEnable | kPWM_CompareVal5InterruptEnable |
         kPWM_CaptureX0InterruptEnable | kPWM_CaptureX1InterruptEnable | kPWM_CaptureB0InterruptEnable |
         kPWM_CaptureB1InterruptEnable | kPWM_CaptureA0InterruptEnable | kPWM_CaptureA1InterruptEnable |
         kPWM_ReloadInterruptEnable | kPWM_ReloadErrorInterruptEnable)
};

/*!
 * @brief The enumeration for PWM submodule status flags.
 */
typedef enum _pwm_sm_status_flags
{
    kPWM_CompareVal0Flag  = (1U << 0),  /*!< PWM submodule VAL0 compare flag. */
    kPWM_CompareVal1Flag  = (1U << 1),  /*!< PWM submodule VAL1 compare flag. */
    kPWM_CompareVal2Flag  = (1U << 2),  /*!< PWM submodule VAL2 compare flag. */
    kPWM_CompareVal3Flag  = (1U << 3),  /*!< PWM submodule VAL3 compare flag. */
    kPWM_CompareVal4Flag  = (1U << 4),  /*!< PWM submodule VAL4 compare flag. */
    kPWM_CompareVal5Flag  = (1U << 5),  /*!< PWM submodule VAL5 compare flag. */
    kPWM_CaptureX0Flag    = (1U << 6),  /*!< PWM submodule capture X0 flag. */
    kPWM_CaptureX1Flag    = (1U << 7),  /*!< PWM submodule capture X1 flag. */
    kPWM_CaptureB0Flag    = (1U << 8),  /*!< PWM submodule capture B0 flag. */
    kPWM_CaptureB1Flag    = (1U << 9),  /*!< PWM submodule capture B1 flag. */
    kPWM_CaptureA0Flag    = (1U << 10), /*!< PWM submodule capture A0 flag. */
    kPWM_CaptureA1Flag    = (1U << 11), /*!< PWM submodule capture A1 flag. */
    kPWM_ReloadFlag       = (1U << 12), /*!< PWM submodule reload flag. */
    kPWM_ReloadErrorFlag  = (1U << 13), /*!< PWM submodule reload error flag. */
    kPWM_RegUpdatedFlag   = (1U << 14), /*!< PWM submodule registers updated flag. */
    kPWM_ALLSMStatusFlags = (kPWM_CompareVal0Flag | kPWM_CompareVal1Flag | kPWM_CompareVal2Flag | kPWM_CompareVal3Flag |
                             kPWM_CompareVal4Flag | kPWM_CompareVal5Flag | kPWM_CaptureX0Flag | kPWM_CaptureX1Flag |
                             kPWM_CaptureB0Flag | kPWM_CaptureB1Flag | kPWM_CaptureA0Flag | kPWM_CaptureA1Flag |
                             kPWM_ReloadFlag | kPWM_ReloadErrorFlag | kPWM_RegUpdatedFlag)
} pwm_sm_status_flags_t;

/*!
 * @brief The enumeration for some PWM submodule PWM_A/B typical output mode.
 */
typedef enum _pwm_sm_typical_output_mode
{
    kPWM_SignedCenterAligned = 0U, /*!< Center-aligned PWM with signed compare value. */
    kPWM_CenterAligned,            /*!< Center-aligned PWM with unsigned compare value. */
    kPWM_SignedEdgeAligned,        /*!< Edge-aligned PWM with signed compare value. */
    kPWM_EdgeAligned               /*!< Edge-aligned PWM with signed compare value. */
} pwm_sm_typical_output_mode_t;

/*!
 * @brief PWM submodule config structure
 *
 * This structure holds the configuration settings for the PWM peripheral. To initialize this
 * structure to reasonable defaults, call the PWM_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 */
typedef struct _pwm_sm_config
{
    bool enableDebugMode : 1U; /*!< true: PWM continues to run in debug mode; false: PWM is paused in debug mode. */
    bool enableWaitMode : 1U;  /*!< true: PWM continues to run in WAIT mode; false: PWM is paused in WAIT mode. */
    bool enableRun : 1U;       /*!< true: PWM submodule is enabled;  false: PWM submodule is disabled. */
    /*!< Configures submodule value registers compare mode, only can be written one time. */
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD)
    pwm_sm_val_compare_mode_t eValCompareMode : 1U;
#endif
    pwm_sm_counter_config_t sCounterConfig;            /*!< Submodule counter logic config. */
    pwm_sm_reload_logic_config_t sReloadConfig;        /*!< Submodule reload control logic config. */
    pwm_sm_value_register_config_t sValRegisterConfig; /*!< Submodule value registers config. */
    pwm_sm_force_logic_config_t sForceConfig;          /*!< Submodule force out logic config. */
    pwm_sm_deadtime_logic_config_t sDeadTimeConfig;    /*!< Submodule deadtime logic config. */
#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
    pwm_sm_fractional_delay_logic_config_t sFracDelayConfig; /*!< Submodule fractional logic config. */
#endif
    pwm_sm_output_logic_config_t sOutputConfig;        /*!< Submodule output logic config. */
    pwm_sm_input_capture_config_t sInCaptureConfig[3]; /*!< Submodule input capture config for PWM_X/A/B pins. */
    pwm_sm_dma_config_t sDMAConfig;                    /*!< Submodule DMA config. */
    /*!< PWM_X output fault input mapping, determines which fault inputs can disable PWM_X output. */
    pwm_sm_fault_input_mapping_t sPwmXFaultInputMapping;
    /*!< PWM_A output fault input mapping, determines which fault inputs can disable PWM_A output. */
    pwm_sm_fault_input_mapping_t sPwmAFaultInputMapping;
    /*!< PWM_B output fault input mapping, determines which fault inputs can disable PWM_B output. */
    pwm_sm_fault_input_mapping_t sPwmBFaultInputMapping;
    /*!< Submodule interrupt enable mask, logic OR of @ref _pwm_sm_interrupt_enable. */
    uint16_t u16EnableInterruptMask;
#if ((defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) && \
      FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD))
    pwm_ml2_stretch_count_clock_prescaler_t eStrBusClock; /*!< PWM stretch IPBus clock count prescaler. */
#endif
} pwm_sm_config_t;

/*!
 * @brief The enumeration for PWM fault protection channel number.
 */
typedef enum _pwm_fault_protection_channel
{
    kPWM_FaultProtection0 = 0U, /*!< PWM fault protection channel 0 */
#if defined(FSL_FEATURE_PWM_FAULT_CH_COUNT) && (FSL_FEATURE_PWM_FAULT_CH_COUNT > 1)
    kPWM_FaultProtection1 /*!< PWM fault protection channel 1 */
#endif
} pwm_fault_protection_channel_t;

/*!
 * @brief The enumeration for PWM module fault protection channel interrupt enable.
 */
enum _pwm_fault_protection_interrupt_enable
{
    kPWM_Fault0InterruptEnable   = (1U << 0U), /*!< Fault protection channel fault 0 interrupt */
    kPWM_Fault1InterruptEnable   = (1U << 1U), /*!< Fault protection channel fault 1 interrupt */
    kPWM_Fault2InterruptEnable   = (1U << 2U), /*!< Fault protection channel fault 2 interrupt */
    kPWM_Fault3InterruptEnable   = (1U << 3U), /*!< Fault protection channel fault 3 interrupt */
    kPWM_ALLfaultInterruptEnable = (kPWM_Fault0InterruptEnable | kPWM_Fault1InterruptEnable |
                                    kPWM_Fault2InterruptEnable | kPWM_Fault3InterruptEnable)
};

/*!
 * @brief The enumeration for PWM module fault protection status flags
 */
enum _pwm_fault_protection_status_flags
{
    kPWM_Fault0Flag = (1U << 0U),          /*!< Fault protection channel fault 0 flag, set within two CPU cycles after a
                                              transition to active on the fault input pin 0. */
    kPWM_Fault1Flag = (1U << 1U),          /*!< Fault protection channel fault 1 flag, set within two CPU cycles after a
                                              transition to active on the fault input pin 1. */
    kPWM_Fault2Flag = (1U << 2U),          /*!< Fault protection channel fault 2 flag, set within two CPU cycles after a
                                              transition to active on the fault input pin 2. */
    kPWM_Fault3Flag = (1U << 3U),          /*!< Fault protection channel fault 3 flag, set within two CPU cycles after a
                                              transition to active on the fault input pin 3. */
    kPWM_FaultPin0ActiveFlag = (1U << 8U), /*!< Fault protection channel fault input pin 0 active flag. */
    kPWM_FaultPin1ActiveFlag = (1U << 9U), /*!< Fault protection channel fault input pin 1 active flag. */
    kPWM_FaultPin2ActiveFlag = (1U << 10U), /*!< Fault protection channel fault input pin 2 active flag. */
    kPWM_FaultPin3ActiveFlag = (1U << 11U), /*!< Fault protection channel fault input pin 3 active flag. */
    kPWM_ALLFaultStatusFlags =
        (kPWM_Fault0Flag | kPWM_Fault1Flag | kPWM_Fault2Flag | kPWM_Fault3Flag | kPWM_FaultPin0ActiveFlag |
         kPWM_FaultPin1ActiveFlag | kPWM_FaultPin2ActiveFlag | kPWM_FaultPin3ActiveFlag)
};

/*!
 * @brief The enumeration for PWM fault protection channel number.
 */
typedef enum _pwm_fault_active_level
{
    kPWM_Logic0 = 0U, /*!< A logic 0 on the fault input indicates a fault condition. */
    kPWM_Logic1       /*!< A logic 0 on the fault input indicates a fault condition. */
} pwm_fault_input_active_level_t;

typedef struct _pwm_fault_protection_input_config
{
    pwm_fault_input_active_level_t eFaultActiveLevel : 1U; /*!< Select the active logic level of the fault input. */
    bool bEnableAutoFaultClear : 1U; /*!< True : Enable automatic fault clearing, fault recovery (PWM outputs can
                                        re-enable) occurs when FSTS[FFPINx] is clear , false : Use manual fault
                                        clearing, fault recovery (PWM outputs can re-enable) occurs when FSTS[FFLAGx] is
                                        manual clear (and FSTS[FFPINx] is clear). */
    bool bEnableManualFaultClearSafeMode : 1U; /*!< True : fault recovery (PWM outputs can re-enable) occurs when
                                        FSTS[FFLAGx] is manual clear and FSTS[FFPINx] is clear, false : fault recovery
                                        (PWM outputs can re-enable) occurs when FSTS[FFLAGx] is manual clear. */
    bool bEnableFaultFullCycleRecovery : 1U;   /*!< Enable full cycle fault recovery, which make PWM outputs are
                                                  re-enabled at the start of a half cycle after fault recovery occurs. */
    bool bEnableFaultHalfCycleRecovery : 1U;   /*!< Enable half cycle fault recovery, which make PWM outputs are
                                                  re-enabled at the start of a half cycle after fault recovery occurs. */
#if (defined(FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER) && FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER)
    bool bEnableFaultNoCombinationalPath : 1U; /*!< True : The fault inputs are combined with the filtered and latched
                                                  fault signals to disable the PWM outputs , false : the filtered and
                                                  latched fault signals are used to disable the PWM outputs. */
#endif
    bool bEnableFaultInterrupt : 1U; /*!< Enable the fault input interrupt. */
} pwm_fault_protection_input_config_t;

/*!
 * @brief The structure for configuring PWM fault protection channel, a PWM module can have multiple fault
 *        protection channels, PWM sub-module can choose to mapping any one or more fault input from fault protection
 * channels.
 */
typedef struct _pwm_fault_protection_config
{
    pwm_fault_protection_input_config_t sFaultInput[4];
    bool bEnableFaultGlitchStretch : 1U; /*!< Fault Glitch Stretch Enable: A logic 1 means that input
                                         fault signals will be stretched to at least 2 IPBus clock cycles. */
    uint8_t bitsFaultFilterCount : 3U;   /*!< Configures PWM fault protection channel fault filter count. */
    uint8_t u8FaultFilterPeriod; /*!< Configures PWM fault protection channel fault filter period, value of 0 will
                                    bypass the filter. */
} pwm_fault_protection_config_t;

/*!
 * @brief PWM module config structure which contain submodule config structure pointers and fault protection
 *        filter config structure pointers.
 *
 * @note Need use submodule structure address to init the structure pointers, when the submodule or fault protection
 * structure pointers is NULL, it will be ignored by PWM_Init API. This can save stack space when only one or two
 * submodules are used.
 *
 */
typedef struct _pwm_config
{
    /*!< PWM submodule config. */
    pwm_sm_config_t *psPwmSubmoduleConfig[FSL_FEATURE_PWM_SUBMODULE_COUNT];
    /*!< PWM fault protection channel config, will take effect for all submodules. */
    pwm_fault_protection_config_t *psFaultProtectionConfig[FSL_FEATURE_PWM_FAULT_CH_COUNT];
} pwm_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization And De-initialization Interfaces
 * @{
 */

/*!
 * @brief Initialization PWM module with provided structure @ref pwm_config_t.
 *
 * This function can initial one or more submodules of the PWM module.
 *
 * This examples shows how only initial submodule 0 without fault protection channel.
 * @code
 *     pwm_config_t sPwmConfig = {0};
 *     pwm_sm_config_t sPwmSm0Config;
 *     sPwmConfig.psPwmSubmoduleConfig[0] = &sPwmSm0Config;
 *     PWM_GetSmDefaultConfig(&sPwmSm0Config);
 *     PWM_Init(PWM, sPwmConfig);
 * @endcode
 *
 * @note This API should be called at the beginning of the application using the PWM driver.
 *
 * @param base        PWM peripheral base address.
 * @param psConfig    Pointer to PWM module configure structure. See @ref pwm_config_t.
 */
void PWM_Init(PWM_Type *base, const pwm_config_t *psConfig);

/*!
 * @brief De-initialization a PWM module.
 *
 * @param base   PWM peripheral base address
 */
void PWM_Deinit(PWM_Type *base);

/*!
 * @brief Gets an default PWM submodule's configuration.
 *
 * This function fills in the initialization structure member, which can make submodule generate 50% duty cycle center
 * aligned PWM_A/B output.
 *
 * The default effective values are:
 * @code
 *   psConfig->enableDebugMode = false;
 *   psConfig->enableWaitMode = false;
 *   psConfig->enableRun = false;
 *   psConfig->sCounterConfig.eCountClockSource = kPWM_ClockSrcBusClock;
 *   psConfig->sCounterConfig.eCountClockPrescale = kPWM_ClockPrescaleDivide1;
 *   psConfig->sCounterConfig.eCountInitSource = kPWM_InitOnLocalSync;
 *   psConfig->sReloadConfig.eReloadSignalSelect = kPWM_LocalReloadSignal;
 *   psConfig->sReloadConfig.eLoclReloadEffectTime = kPWM_TakeEffectAtReloadOportunity;
 *   psConfig->sReloadConfig.eLocalReloadOportunity = kPWM_LoadEveryOportunity;
 *   psConfig->sReloadConfig.bEnableFullCycleReloadOportunity = true;
 *   psConfig->sReloadConfig.bEnableHalfCycleReloadOportunity = false;
 *   psConfig->sValRegisterConfig.u16CounterInitialValue = 0xFF00U;
 *   psConfig->sValRegisterConfig.u16ValRegister0 = 0x0U;
 *   psConfig->sValRegisterConfig.u16ValRegister1 = 0x00FFU;
 *   psConfig->sValRegisterConfig.u16ValRegister2 = 0xFF80U;
 *   psConfig->sValRegisterConfig.u16ValRegister3 = 0x80U;
 *   psConfig->sValRegisterConfig.u16ValRegister4 = 0xFF80U;
 *   psConfig->sValRegisterConfig.u16ValRegister5 = 0x80U;
 *   psConfig->sForceConfig.eForceSignalSelect = kPWM_LocalSoftwareForce;
 *   psConfig->sForceConfig.eSoftOutputFor23 = kPWM_SoftwareOutputLow;
 *   psConfig->sForceConfig.eSoftOutputFor45 = kPWM_SoftwareOutputLow;
 *   psConfig->sForceConfig.eForceOutput23 = kPWM_GeneratedPwm;
 *   psConfig->sForceConfig.eForceOutput45 = kPWM_GeneratedPwm;
 *   psConfig->sDeadTimeConfig.eMode = kPWM_Independent;
 *   psConfig->sOutputConfig.ePwmXSignalSelect = kPWM_RawPwmX;
 *   psConfig->sOutputConfig.bEnablePwmxOutput = true;
 *   psConfig->sOutputConfig.bEnablePwmaOutput = true;
 *   psConfig->sOutputConfig.bEnablePwmbOutput = true;
 *   psConfig->sOutputConfig.ePwmxFaultState = kPWM_OutputLowOnFault;
 *   psConfig->sOutputConfig.ePwmaFaultState = kPWM_OutputLowOnFault;
 *   psConfig->sOutputConfig.ePwmbFaultState = kPWM_OutputLowOnFault;
 * @endcode
 * @param psConfig  Pointer to user's PWM submodule config structure. See @ref pwm_sm_config_t.
 */
void PWM_GetSMDefaultConfig(pwm_sm_config_t *psConfig);

/*!
 * @brief Gets an default fault protection channel's configuration.
 *
 * The default effective values are:
 * @code
 *   psConfig->sFaultInput[i].eFaultActiveLevel = kPWM_Logic0;
 *   psConfig->sFaultInput[i].bEnableAutoFaultClear = true;
 *   psConfig->sFaultInput[i].bEnableFaultFullCycleRecovery = true;
 * @endcode
 * @param psConfig  Pointer to user's PWM fault protection config structure. See @ref pwm_fault_protection_config_t.
 */

void PWM_GetFaultProtectionDefaultConfig(pwm_fault_protection_config_t *psConfig);

/*! @}*/

/*!
 * @name Submodule PWM Generation Related Interfaces
 * @{
 */

/*!
 * @brief Sets up the PWM submodule configure.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig     Pointer to submodule configure structure, see @ref pwm_sm_config_t.
 */
void PWM_SetupSMConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_config_t *psConfig);

/*!
 * @brief Sets up the PWM submodule counter configure.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig     Pointer to submodule counter configure structure, see @ref pwm_sm_counter_config_t.
 */
static inline void PWM_SetupCounterConfig(PWM_Type *base,
                                          pwm_sm_number_t eSubModule,
                                          const pwm_sm_counter_config_t *psConfig)
{
    base->SM[eSubModule].CTRL2 =
        (base->SM[eSubModule].CTRL2 & ~(uint16_t)(PWM_CTRL2_CLK_SEL_MASK | PWM_CTRL2_INIT_SEL_MASK)) |
        PWM_CTRL2_CLK_SEL(psConfig->eCountClockSource) | PWM_CTRL2_INIT_SEL(psConfig->eCountInitSource);
    base->SM[eSubModule].CTRL =
        (base->SM[eSubModule].CTRL & ~(uint16_t)(PWM_CTRL_PRSC_MASK)) | PWM_CTRL_PRSC(psConfig->eCountClockPrescaler);
#if (defined(FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER) && FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER)
    /* PHASEDLY register only exist in submodule 1 ~ 3 */
    if (eSubModule != kPWM_SubModule0)
    {
        base->SM[eSubModule].PHASEDLY = psConfig->u16PhaseDelayValue;
    }
#endif
}

/*!
 * @brief Sets the PWM submodule counter initial register value.
 *
 * This function set the INIT register value, the counter will start counting from INIT register value when initial
 * signal assert or software force set. This write value will be loaded into inner set of buffered registers
 * according to reload logic configure.
 *
 * @param base             PWM peripheral base address
 * @param eSubModule       PWM submodule number, see @ref pwm_sm_number_t.
 * @param u16InitialValue  The submodule number counter initialize value.
 */
static inline void PWM_SetCounterInitialValue(PWM_Type *base, pwm_sm_number_t eSubModule, uint16_t u16InitialValue)
{
    base->SM[eSubModule].INIT = u16InitialValue;
}

/*!
 * @brief Sets up the PWM submodule reload logic configure.
 *
 * @param base         PWM peripheral base address.
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig     Pointer to submodule reload logic configure structure, see @ref pwm_sm_reload_logic_config_t.
 */
static inline void PWM_SetupReloadLogicConfig(PWM_Type *base,
                                              pwm_sm_number_t eSubModule,
                                              const pwm_sm_reload_logic_config_t *psConfig)
{
    base->SM[eSubModule].CTRL2 = (base->SM[eSubModule].CTRL2 & ~(uint16_t)(PWM_CTRL2_RELOAD_SEL_MASK)) |
                                 PWM_CTRL2_RELOAD_SEL(psConfig->eReloadSignalSelect);

    base->SM[eSubModule].CTRL =
        (base->SM[eSubModule].CTRL &
         ~(uint16_t)(PWM_CTRL_LDFQ_MASK | PWM_CTRL_HALF_MASK | PWM_CTRL_FULL_MASK | PWM_CTRL_LDMOD_MASK)) |
        PWM_CTRL_LDFQ(psConfig->eLocalReloadOportunity) | PWM_CTRL_HALF(psConfig->bEnableHalfCycleReloadOportunity) |
        PWM_CTRL_FULL(psConfig->bEnableFullCycleReloadOportunity) | PWM_CTRL_LDMOD(psConfig->eLoclReloadEffectTime);
}

/*!
 * @brief Update PWM submodule compare value configuration according to the typical output mode.
 *
 * @param psConfig             See @ref pwm_sm_config_t.
 * @param eTypicalOutputMode   Typical PWM_A/B output mode. See @ref pwm_sm_typical_output_mode_t.
 * @param u16PwmPeriod         PWM output period value in counter ticks. This value can be
 *                            got by (main counter clock in Hz) / (wanted PWM signal frequency in Hz).
 * @param u16PwmAPulseWidth    PWM_A pulse width value in counter ticks. Can got by (wanted PWM duty Cycle) *
 *                            u16PwmPeriod.
 * @param u16PwmBPulseWidth    PWM_B pulse width value in counter ticks. Can got by (wanted PWM duty Cycle) *
 *                            u16PwmPeriod.
 */
void PWM_GetValueConfig(pwm_sm_value_register_config_t *psConfig,
                        pwm_sm_typical_output_mode_t eTypicalOutputMode,
                        uint16_t u16PwmPeriod,
                        uint16_t u16PwmAPulseWidth,
                        uint16_t u16PwmBPulseWidth);

/*!
 * @brief Sets up the PWM submodule VALn registers logic configure.
 *
 * @param base         PWM peripheral base address.
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig     Pointer to VALn registers configure structure, see @ref pwm_sm_value_register_config_t.
 */
static inline void PWM_SetupValRegisterConfig(PWM_Type *base,
                                              pwm_sm_number_t eSubModule,
                                              const pwm_sm_value_register_config_t *psConfig)
{
    base->SM[eSubModule].INIT = psConfig->u16CounterInitialValue;
    base->SM[eSubModule].VAL0 = psConfig->u16ValRegister0;
    base->SM[eSubModule].VAL1 = psConfig->u16ValRegister1;
    base->SM[eSubModule].VAL2 = psConfig->u16ValRegister2;
    base->SM[eSubModule].VAL3 = psConfig->u16ValRegister3;
    base->SM[eSubModule].VAL4 = psConfig->u16ValRegister4;
    base->SM[eSubModule].VAL5 = psConfig->u16ValRegister5;
}

/*!
 * @brief Sets the PWM submodule VALn register value.
 *
 * @note  These write value will be loaded into inner set of buffered registers according to reload logic configure.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister        Value register index (range in 0~5), see @ref pwm_sm_val_register_t.
 * @param u16Value         The value for VALn register.
 */
static inline void PWM_SetValueRegister(PWM_Type *base,
                                        pwm_sm_number_t eSubModule,
                                        pwm_sm_val_register_t eRegister,
                                        uint16_t u16Value)
{
    switch (eRegister)
    {
        case kPWM_VAL0:
            base->SM[eSubModule].VAL0 = u16Value;
            break;
        case kPWM_VAL1:
            base->SM[eSubModule].VAL1 = u16Value;
            break;
        case kPWM_VAL2:
            base->SM[eSubModule].VAL2 = u16Value;
            break;
        case kPWM_VAL3:
            base->SM[eSubModule].VAL3 = u16Value;
            break;
        case kPWM_VAL4:
            base->SM[eSubModule].VAL4 = u16Value;
            break;
        case kPWM_VAL5:
            base->SM[eSubModule].VAL5 = u16Value;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * @brief Gets the PWM submodule VALn register value.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister        Value register index (range in 0~5), see @ref pwm_sm_val_register_t.
 *
 * @return The VALn register value.
 */
static inline uint16_t PWM_GetValueRegister(PWM_Type *base, pwm_sm_number_t eSubModule, pwm_sm_val_register_t eRegister)
{
    uint16_t u16Regs = 0U;

    switch (eRegister)
    {
        case kPWM_VAL0:
            u16Regs = base->SM[eSubModule].VAL0;
            break;
        case kPWM_VAL1:
            u16Regs = base->SM[eSubModule].VAL1;
            break;
        case kPWM_VAL2:
            u16Regs = base->SM[eSubModule].VAL2;
            break;
        case kPWM_VAL3:
            u16Regs = base->SM[eSubModule].VAL3;
            break;
        case kPWM_VAL4:
            u16Regs = base->SM[eSubModule].VAL4;
            break;
        case kPWM_VAL5:
            u16Regs = base->SM[eSubModule].VAL5;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }

    return u16Regs;
}

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && (FSL_FEATURE_PWM_HAS_FRACTIONAL > 0U))

/*!
 * @brief Sets the PWM submodule fractional value register value.
 *
 * @note  These write value will be loaded into inner set of buffered registers according to reload logic configure.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister        Fractional value register index (range in 1~5), see @ref pwm_sm_val_register_t.
 * @param u16Value         The value for FRACVALn register.
 */
static inline void PWM_SetFracvalRegister(PWM_Type *base,
                                          pwm_sm_number_t eSubModule,
                                          pwm_sm_fracval_register_t eRegister,
                                          uint16_t u16Value)
{
    switch (eRegister)
    {
        case kPWM_FRACVAL1:
            base->SM[eSubModule].FRACVAL1 = PWM_FRACVAL1_FRACVAL1(u16Value);
            break;
        case kPWM_FRACVAL2:
            base->SM[eSubModule].FRACVAL2 = PWM_FRACVAL2_FRACVAL2(u16Value);
            break;
        case kPWM_FRACVAL3:
            base->SM[eSubModule].FRACVAL3 = PWM_FRACVAL3_FRACVAL3(u16Value);
            break;
        case kPWM_FRACVAL4:
            base->SM[eSubModule].FRACVAL4 = PWM_FRACVAL4_FRACVAL4(u16Value);
            break;
        case kPWM_FRACVAL5:
            base->SM[eSubModule].FRACVAL5 = PWM_FRACVAL5_FRACVAL5(u16Value);
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * @brief Sets the PWM submodule fractional value register value.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister        Fractional value register index (range in 1~5), see @ref pwm_sm_fracval_register_t.
 *
 * @return The VALn FRACVALn value.
 */
static inline uint16_t PWM_GetFracvalRegister(PWM_Type *base,
                                              pwm_sm_number_t eSubModule,
                                              pwm_sm_fracval_register_t eRegister)
{
    uint16_t u16Regs = 0U;
    switch (eRegister)
    {
        case kPWM_FRACVAL1:
            u16Regs = (base->SM[eSubModule].FRACVAL1 & PWM_FRACVAL1_FRACVAL1_MASK) >> PWM_FRACVAL1_FRACVAL1_SHIFT;
            break;
        case kPWM_FRACVAL2:
            u16Regs = (base->SM[eSubModule].FRACVAL2 & PWM_FRACVAL2_FRACVAL2_MASK) >> PWM_FRACVAL2_FRACVAL2_SHIFT;
            break;
        case kPWM_FRACVAL3:
            u16Regs = (base->SM[eSubModule].FRACVAL3 & PWM_FRACVAL3_FRACVAL3_MASK) >> PWM_FRACVAL3_FRACVAL3_SHIFT;
            break;
        case kPWM_FRACVAL4:
            u16Regs = (base->SM[eSubModule].FRACVAL4 & PWM_FRACVAL4_FRACVAL4_MASK) >> PWM_FRACVAL4_FRACVAL4_SHIFT;
            break;
        case kPWM_FRACVAL5:
            u16Regs = (base->SM[eSubModule].FRACVAL5 & PWM_FRACVAL5_FRACVAL5_MASK) >> PWM_FRACVAL5_FRACVAL5_SHIFT;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
    return u16Regs;
}

/*!
 * @brief Set submodule register VALx and its FRAC value with 32bit access.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       Submodule ID.
 * @param eRegister        Fractional value register index (range in 1~5), see @ref pwm_sm_fracval_register_t.
 * @param u32Value         32bit value for VALx and its FRAC.
 *                         VALx: BIT16~BIT31.
 *                         FRACVALx: BIT11~BIT15.
 *                         RESERVED: BIT10~BIT0.
 */
static inline void PWM_SetValueAndFracRegister(PWM_Type *base,
                                               pwm_sm_number_t eSubModule,
                                               pwm_sm_fracval_register_t eRegister,
                                               uint32_t u32Value)
{
    switch (eRegister)
    {
        case kPWM_FRACVAL1:
            *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL1))) = u32Value;
            break;
        case kPWM_FRACVAL2:
            *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL2))) = u32Value;
            break;
        case kPWM_FRACVAL3:
            *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL3))) = u32Value;
            break;
        case kPWM_FRACVAL4:
            *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL4))) = u32Value;
            break;
        case kPWM_FRACVAL5:
            *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL5))) = u32Value;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * @brief Get submodule register VALx and its FRAC value with 32bit access.
 *
 * @param base             PWM peripheral base address.
 * @param eSubModule       Submodule ID.
 * @param eRegister        Fractional value register index (range in 1~5), see @ref pwm_sm_fracval_register_t.
 *
 * @return The value of submodule register VALx and its FRAC, combined into 32bit.
 *         VALx: BIT16~BIT31.
 *         FRACVALx: BIT11~BIT15.
 *         RESERVED: BIT10~BIT0.
 */
static inline uint32_t PWM_GetValueAndFracRegister(PWM_Type *base,
                                                   pwm_sm_number_t eSubModule,
                                                   pwm_sm_fracval_register_t eRegister)
{
    uint32_t u32Regs = 0U;
    switch (eRegister)
    {
        case kPWM_FRACVAL1:
            u32Regs = *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL1)));
            break;
        case kPWM_FRACVAL2:
            u32Regs = *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL2)));
            break;
        case kPWM_FRACVAL3:
            u32Regs = *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL3)));
            break;
        case kPWM_FRACVAL4:
            u32Regs = *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL4)));
            break;
        case kPWM_FRACVAL5:
            u32Regs = *((volatile uint32_t *)(&(base->SM[eSubModule].FRACVAL5)));
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
    return u32Regs;
}

#endif
/*!
 * @brief Set the PWM LDOK bit on a single or multiple submodules.
 *
 * Enable this feature can make buffered CTRL[PRSC] and the INIT, FRACVAL and VAL registers values take effect after
 * next local load signal assert. The timing of take effect can be the next PWM reload or immediately. After loading,
 * MCTRL[LDOK] is automatically cleared and need to enable again before the next register updated.
 *
 * @note The VALx, FRACVALx,INIT, and CTRL[PRSC] registers of the corresponding submodule cannot be written
 *       while the the corresponding MCTRL[LDOK] bit is set.
 * @param base         PWM peripheral base address
 * @param u16Mask      PWM submodules to set the LDOK bit, Logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_SetPwmLdok(PWM_Type *base, uint16_t u16Mask)
{
    base->MCTRL |= PWM_MCTRL_LDOK(u16Mask);
}

/*!
 * @brief Clear the PWM LDOK bit on a single or multiple submodules.
 *
 * @param base         PWM peripheral base address
 * @param u16Mask      PWM submodules to clear the LDOK bit, Logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_ClearPwmLdok(PWM_Type *base, uint16_t u16Mask)
{
    base->MCTRL &= ~PWM_MCTRL_CLDOK(u16Mask);
}

/*!
 * brief Sets up the PWM submodule force logic configure.
 *
 * param base         PWM peripheral base address.
 * param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig     Poniter to submodule force logic configure structure, see @ref pwm_sm_force_logic_config_t.
 */
static inline void PWM_SetupForceLogicConfig(PWM_Type *base,
                                             pwm_sm_number_t eSubModule,
                                             const pwm_sm_force_logic_config_t *psConfig)
{
    if (eSubModule == kPWM_SubModule0)
    {
        base->SWCOUT = (uint16_t)(base->SWCOUT & ~(PWM_SWCOUT_SM0OUT45_MASK | PWM_SWCOUT_SM0OUT23_MASK)) |
                       PWM_SWCOUT_SM0OUT45(psConfig->eSoftOutputFor45) |
                       PWM_SWCOUT_SM0OUT23(psConfig->eSoftOutputFor23);
        base->DTSRCSEL = (uint16_t)(base->DTSRCSEL & ~(PWM_DTSRCSEL_SM0SEL45_MASK | PWM_DTSRCSEL_SM0SEL23_MASK)) |
                         PWM_DTSRCSEL_SM0SEL45(psConfig->eForceOutput23) |
                         PWM_DTSRCSEL_SM0SEL23(psConfig->eForceOutput45);
    }
    else if (eSubModule == kPWM_SubModule1)
    {
        base->SWCOUT = (uint16_t)(base->SWCOUT & ~(PWM_SWCOUT_SM1OUT45_MASK | PWM_SWCOUT_SM1OUT23_MASK)) |
                       PWM_SWCOUT_SM1OUT45(psConfig->eSoftOutputFor45) |
                       PWM_SWCOUT_SM1OUT23(psConfig->eSoftOutputFor23);
        base->DTSRCSEL = (uint16_t)(base->DTSRCSEL & ~(PWM_DTSRCSEL_SM1SEL45_MASK | PWM_DTSRCSEL_SM1SEL23_MASK)) |
                         PWM_DTSRCSEL_SM1SEL45(psConfig->eForceOutput23) |
                         PWM_DTSRCSEL_SM1SEL23(psConfig->eForceOutput45);
    }
    else if (eSubModule == kPWM_SubModule2)
    {
        base->SWCOUT = (uint16_t)(base->SWCOUT & ~(PWM_SWCOUT_SM2OUT45_MASK | PWM_SWCOUT_SM2OUT23_MASK)) |
                       PWM_SWCOUT_SM2OUT45(psConfig->eSoftOutputFor45) |
                       PWM_SWCOUT_SM2OUT23(psConfig->eSoftOutputFor23);
        base->DTSRCSEL = (uint16_t)(base->DTSRCSEL & ~(PWM_DTSRCSEL_SM2SEL45_MASK | PWM_DTSRCSEL_SM2SEL23_MASK)) |
                         PWM_DTSRCSEL_SM2SEL45(psConfig->eForceOutput23) |
                         PWM_DTSRCSEL_SM2SEL23(psConfig->eForceOutput45);
    }
    else
    {
        base->SWCOUT = (uint16_t)(base->SWCOUT & ~(PWM_SWCOUT_SM3OUT45_MASK | PWM_SWCOUT_SM3OUT23_MASK)) |
                       PWM_SWCOUT_SM3OUT45(psConfig->eSoftOutputFor45) |
                       PWM_SWCOUT_SM3OUT23(psConfig->eSoftOutputFor23);
        base->DTSRCSEL = (uint16_t)(base->DTSRCSEL & ~(PWM_DTSRCSEL_SM3SEL45_MASK | PWM_DTSRCSEL_SM3SEL23_MASK)) |
                         PWM_DTSRCSEL_SM3SEL45(psConfig->eForceOutput23) |
                         PWM_DTSRCSEL_SM3SEL23(psConfig->eForceOutput45);
    }

    base->SM[eSubModule].CTRL2 = (base->SM[eSubModule].CTRL2 & ~(uint16_t)(PWM_CTRL2_FORCE_SEL_MASK)) |
                                 PWM_CTRL2_FORCE_SEL(psConfig->eForceSignalSelect);
}

/*!
 * @brief Sets up the PWM Sub-Module to trigger a software FORCE_OUT event.
 *
 * @note Only works when the CTRL2[FORCE_SEL] select kPWM_ForceOutOnLocalSoftware.
 *
 * @param base         PWM peripheral base address.
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 */
static inline void PWM_SetSoftwareForce(PWM_Type *base, pwm_sm_number_t eSubModule)
{
    base->SM[eSubModule].CTRL2 |= PWM_CTRL2_FORCE_MASK;
}

/*!
 * @brief Sets up the PWM submodule deadtime logic configure.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig      Pointer to deadtime logic configure structure, see @ref pwm_sm_deadtime_logic_config_t.
 */
void PWM_SetupDeadtimeConfig(PWM_Type *base,
                             pwm_sm_number_t eSubModule,
                             const pwm_sm_deadtime_logic_config_t *psConfig);

/*!
 * @brief Get the sampled values of the PWM_X input at the end of each deadtime.
 *
 * When use PWM_A/B in complementary mode and connect to transistor to controls the output voltage. Need insert deadtime
 * to avoid overlap of conducting interval between the top and bottom transistor. And both transistors in complementary
 * mode are off during deadtime. Then connect the PWM_X input to complementary transistors output, then it sampling
 * input at the end of deadtime 0 for DT[0] and the end of deadtime 1 for DT[1]. Which DT value is not 0 indicates that
 * there is a problem with the corresponding deadtime value. This can help to decide if there need do a deadtime
 * correction for current complementary PWM output.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 *
 * @return The PWM_X input sampled values.
 */
static inline uint16_t PWM_GetDeadtimeSampleValue(PWM_Type *base, pwm_sm_number_t eSubModule)
{
    return (base->SM[eSubModule].CTRL & PWM_CTRL_DT_MASK) >> PWM_CTRL_DT_SHIFT;
}

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
/*!
 * @brief Sets up the PWM submodule fractional delay logic configure.
 *
 * @note The fractional delay logic can only be used when the IPBus clock is running at 100 MHz.
 *
 * @param base         PWM peripheral base address.
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig     Pointer to fractional delay logic configure structure, see
 *                      @ref pwm_sm_fractional_delay_logic_config_t.
 */
void PWM_SetupFractionalDelayConfig(PWM_Type *base,
                                    pwm_sm_number_t eSubModule,
                                    const pwm_sm_fractional_delay_logic_config_t *psConfig);
#endif

/*!
 * @brief Sets up the PWM submodule output logic configure.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig      Pointer to output logic configure structure, see @ref pwm_sm_output_logic_config_t.
 */
void PWM_SetupOutputConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_output_logic_config_t *psConfig);

/*!
 * @brief Enables the PWM submodule pin output.
 *
 * This function handles PWMX_EN/PWMA_EN/PWMB_EN bit filed of OUTEN register, whcih can enable one or more submodule
 * pin in PWMX/A/B.
 *
 * @param base               PWM peripheral base address
 * @param u16SubModules      The submodules that enable eOutput output, logical OR of @ref _pwm_sm_enable.
 * @param eOutput            PWM output pin ID, see @ref pwm_sm_pwm_out_t.
 */
static inline void PWM_EnableOutput(PWM_Type *base, uint16_t u16SubModules, pwm_sm_pwm_out_t eOutput)
{
    base->OUTEN |= ((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput));
}

/*!
 * @brief Disables the PWM submodule pin output.
 *
 * This function handles PWMX_EN/PWMA_EN/PWMB_EN bit filed of OUTEN register, whcih can disable one or more submodule
 * pin in PWMX/A/B.
 *
 * @param base               PWM peripheral base address
 * @param u16SubModules      The submodules that disable eOutput output, logical OR of @ref _pwm_sm_enable.
 * @param eOutput            PWM output pin ID, see @ref pwm_sm_pwm_out_t.
 */
static inline void PWM_DisableOutput(PWM_Type *base, uint16_t u16SubModules, pwm_sm_pwm_out_t eOutput)
{
    base->OUTEN &= ~(((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput)));
}

/*!
 * @brief Enables the PWM pin combination output.
 *
 * This function handles PWMX_EN/PWMA_EN/PWMB_EN bit filed of OUTEN register at the same time.
 *
 * @param base                 PWM peripheral base address
 * @param u16XSubModules       The submodules that enable PWMX output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16ASubModules       The submodules that enable PWMA output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16BSubModules       The submodules that enable PWMB output, should be logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_EnableCombinedOutput(PWM_Type *base,
                                            uint16_t u16XSubModules,
                                            uint16_t u16ASubModules,
                                            uint16_t u16BSubModules)
{
    base->OUTEN |=
        PWM_OUTEN_PWMA_EN(u16ASubModules) | PWM_OUTEN_PWMB_EN(u16BSubModules) | PWM_OUTEN_PWMX_EN(u16XSubModules);
}

/*!
 * @brief Disables the PWM pin combination output.
 *
 * This function handles PWMX_EN/PWMA_EN/PWMB_EN bit filed of OUTEN register at the same time.
 *
 * @param base                 PWM peripheral base address
 * @param u16XSubModules       The submodules that disable PWMX output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16ASubModules       The submodules that disable PWMA output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16BSubModules       The submodules that disable PWMB output, should be logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_DisableCombinedOutput(PWM_Type *base,
                                             uint16_t u16XSubModules,
                                             uint16_t u16ASubModules,
                                             uint16_t u16BSubModules)
{
    base->OUTEN &=
        ~(PWM_OUTEN_PWMA_EN(u16ASubModules) | PWM_OUTEN_PWMB_EN(u16BSubModules) | PWM_OUTEN_PWMX_EN(u16XSubModules));
}

/*!
 * @brief Mask the PWM pin output.
 *
 * This function handles MASKA/MASKB/MASKX bit filed of MASK register, which can mask one or more submodule
 * pin in PWMX/A/B.
 *
 * @note The mask bits is buffered and can be updated until a FORCE_OUT event occurs or a software update command.
 *
 * @param base             PWM peripheral base address.
 * @param u16SubModules    The submodules that mask eOutput output, logical OR of @ref _pwm_sm_enable.
 * @param eOutput          PWM output pin ID, see @ref pwm_sm_pwm_out_t.
 */
static inline void PWM_MaskOutput(PWM_Type *base, uint16_t u16SubModules, pwm_sm_pwm_out_t eOutput)
{
#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
    /* Mask output immediate */
    base->MASK |= ((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput)) | PWM_MASK_UPDATE_MASK(u16SubModules);
#else
    base->MASK |= ((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput));
#endif
}

/*!
 * @brief Unmask the PWM pin output.
 *
 * This function handles MASKA/MASKB/MASKX bit filed of MASK register, which can mask one or more submodule
 * pin in PWMX/A/B.
 *
 * @note The mask bits is buffered and can be updated until a FORCE_OUT event occurs or a software update command.
 *
 * @param base              PWM peripheral base address
 * @param u16SubModules     The submodules that unmask eOutput output, logical OR of @ref _pwm_sm_enable.
 * @param eOutput           PWM output pin ID, see @ref pwm_sm_pwm_out_t.
 */
static inline void PWM_UnmaskOutput(PWM_Type *base, uint16_t u16SubModules, pwm_sm_pwm_out_t eOutput)
{
    /* Unmask output immediate */
#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
    base->MASK &= ~((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput)) | PWM_MASK_UPDATE_MASK(u16SubModules);
#else
    base->MASK &= ~((uint16_t)u16SubModules) << (4U * ((uint16_t)eOutput));
#endif
}

/*!
 * @brief Mask the PWM pin combination output.
 *
 * This function handles MASKA/MASKB/MASKX bit filed of MASK register at the same time.
 *
 * @note The mask bits is buffered and can be updated until a FORCE_OUT event occurs or a software update command.
 *
 *
 * @param base               PWM peripheral base address
 * @param u16XSubModules     The submodules that mask PWMX output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16ASubModules     The submodules that mask PWMA output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16BSubModules     The submodules that mask PWMB output, should be logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_MaskCombinedOutput(PWM_Type *base,
                                          uint16_t u16XSubModules,
                                          uint16_t u16ASubModules,
                                          uint16_t u16BSubModules)
{
    /* Mask output immediate */
#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
    base->MASK |= PWM_MASK_MASKA(u16ASubModules) | PWM_MASK_MASKB(u16BSubModules) | PWM_MASK_MASKX(u16XSubModules) |
                  PWM_MASK_UPDATE_MASK(u16ASubModules | u16BSubModules | u16XSubModules);
#else
    base->MASK |= PWM_MASK_MASKA(u16ASubModules) | PWM_MASK_MASKB(u16BSubModules) | PWM_MASK_MASKX(u16XSubModules);
#endif
}

/*!
 * @brief Unmask the PWM pin combination output.
 *
 * This function handles MASKA/MASKB/MASKX bit filed of MASK register at the same time.
 *
 * @note The mask bits is buffered and can be updated until a FORCE_OUT event occurs or a software update command.
 *
 *
 * @param base                 PWM peripheral base address
 * @param u16XSubModules     The submodules that unmask PWMX output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16ASubModules     The submodules that unmask PWMA output, should be logical OR of @ref _pwm_sm_enable.
 * @param u16BSubModules     The submodules that unmask PWMB output, should be logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_UnmaskCombinedOutput(PWM_Type *base,
                                            uint16_t u16XSubModules,
                                            uint16_t u16ASubModules,
                                            uint16_t u16BSubModules)
{
    /* Unmask output immediate */
#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
    base->MASK &= ~(PWM_MASK_MASKA(u16ASubModules) | PWM_MASK_MASKB(u16BSubModules) | PWM_MASK_MASKX(u16XSubModules) |
                    PWM_MASK_UPDATE_MASK(u16ASubModules | u16BSubModules | u16XSubModules));
#else
    base->MASK &= ~(PWM_MASK_MASKA(u16ASubModules) | PWM_MASK_MASKB(u16BSubModules) | PWM_MASK_MASKX(u16XSubModules));
#endif
}

#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
/*!
 * @brief Update PWM output mask bits immediately with a software command.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 */
static inline void PWM_UpdateMask(PWM_Type *base, pwm_sm_number_t eSubModule)
{
    base->MASK |= PWM_MASK_UPDATE_MASK((uint16_t)1U << (uint16_t)eSubModule);
}
#endif

/*!
 * @brief Enables/Disables the PWM submodule continue to run while the chip is in DEBUG mode.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param bEnable      Enable the feature or not.
 *                     - \b true Enable load feature.
 *                     - \b false Disable load feature.
 */
static inline void PWM_EnablePwmRunInDebug(PWM_Type *base, pwm_sm_number_t eSubModule, bool bEnable)
{
    if (bEnable)
    {
        base->SM[eSubModule].CTRL2 |= (uint16_t)PWM_CTRL2_DBGEN_MASK;
    }
    else
    {
        base->SM[eSubModule].CTRL2 &= ~(uint16_t)PWM_CTRL2_DBGEN_MASK;
    }
}

/*!
 * @brief Enables/Disables the PWM submodule continue to run while the chip is in WAIT mode.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param bEnable      Enable the feature or not.
 *                     - \b true Enable load feature.
 *                     - \b false Disable load feature.
 */
static inline void PWM_EnablePwmRunInWait(PWM_Type *base, pwm_sm_number_t eSubModule, bool bEnable)
{
    if (bEnable)
    {
        base->SM[eSubModule].CTRL2 |= (uint16_t)PWM_CTRL2_WAITEN_MASK;
    }
    else
    {
        base->SM[eSubModule].CTRL2 &= ~(uint16_t)PWM_CTRL2_WAITEN_MASK;
    }
}

/*!
 * @brief Starts the PWM submodule counter for a single or multiple submodules.
 *
 * Sets the Run bit which enables the clocks to the PWM submodule. This function can start multiple
 * submodules at the same time.
 *
 * @param base      PWM peripheral base address
 * @param u16Mask   PWM submodules to start run, Logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_EnableCounters(PWM_Type *base, uint16_t u16Mask)
{
    base->MCTRL |= PWM_MCTRL_RUN(u16Mask);
}

/*!
 * @brief Stops the PWM counter for a single or multiple submodules.
 *
 * Clears the Run bit which resets the submodule's counter. This function can stop multiple
 * submodules at the same time.
 *
 * @param base      PWM peripheral base address
 * @param u16Mask   PWM submodules to start run, Logical OR of @ref _pwm_sm_enable.
 */
static inline void PWM_DisableCounters(PWM_Type *base, uint16_t u16Mask)
{
    base->MCTRL &= ~(PWM_MCTRL_RUN(u16Mask));
}

/*! @}*/

/*!
 * @name Submodule Input Capture Related Interfaces
 * @{
 */

/*!
 * @brief Reads PWM submodule input capture value register.
 *
 * This function read the CVALn register value, stores the value captured from the submodule counter.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister     PWM submodule input capture value register, see @ref pwm_sm_input_capture_register_t.
 *
 * @return The input capture value.
 */
static inline uint16_t PWM_GetCaptureValue(PWM_Type *base,
                                           pwm_sm_number_t eSubModule,
                                           pwm_sm_input_capture_register_t eRegister)
{
    return (&base->SM[eSubModule].CVAL0)[(uint16_t)eRegister];
}

/*!
 * @brief Reads PWM submodule input capture value cycle register.
 *
 * This function read the CVALnCYC register value, stores the cycle number corresponding to the value captured in
 * CVALn. This register is incremented each time the counter is loaded with the INIT value at the end of a PWM
 * modulo cycle.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eRegister     PWM submodule input capture value register, see @ref pwm_sm_input_capture_register_t.
 *
 * @return The input capture register cycle value.
 */
static inline uint16_t PWM_GetCaptureValueCycle(PWM_Type *base,
                                                pwm_sm_number_t eSubModule,
                                                pwm_sm_input_capture_register_t eRegister)
{
    return (&base->SM[eSubModule].CVAL0CYC)[(uint16_t)eRegister] & PWM_CVAL0CYC_CVAL0CYC_MASK;
}

/*!
 * @brief Reads the PWM submodule input capture logic edge counter value.
 *
 * Each input capture logic has a edge counter, which counts both the rising and falling edges of
 * the input capture signal and it compare signal can select as input capture trigger source.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eInputPin     PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 */

static inline uint16_t PWM_GetCaptureEdgeCounterVaule(PWM_Type *base,
                                                      pwm_sm_number_t eSubModule,
                                                      pwm_sm_input_capture_pin_t eInputPin)
{
    uint16_t u16Regs;

    if (eInputPin == kPWM_InputCapturePwmX)
    {
        u16Regs = (base->SM[eSubModule].CAPTCOMPX & PWM_CAPTCOMPX_EDGCNTX_MASK) >> PWM_CAPTCOMPX_EDGCNTX_SHIFT;
    }
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    else if (eInputPin == kPWM_InputCapturePwmA)
    {
        u16Regs = (base->SM[eSubModule].CAPTCOMPA & PWM_CAPTCOMPA_EDGCNTA_MASK) >> PWM_CAPTCOMPA_EDGCNTA_SHIFT;
    }
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    else
    {
        u16Regs = (base->SM[eSubModule].CAPTCOMPB & PWM_CAPTCOMPB_EDGCNTB_MASK) >> PWM_CAPTCOMPB_EDGCNTB_SHIFT;
    }
#endif

    return u16Regs;
}

/*!
 * @brief Sets up the PWM submodule input capture configure.
 *
 * Each PWM submodule has 3 pins that can be configured for use as input capture pins. This function
 * sets up the capture parameters for each pin and enables the input capture operation.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eInputPin     PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 * @param psConfig      Pointer to input capture configure structure, see @ref pwm_sm_input_capture_config_t.
 */
void PWM_SetupInputCaptureConfig(PWM_Type *base,
                                 pwm_sm_number_t eSubModule,
                                 pwm_sm_input_capture_pin_t eInputPin,
                                 const pwm_sm_input_capture_config_t *psConfig);
/*!
 * @brief Enables the PWM submodule input capture operation.
 *
 * Enables input capture operation will start the input capture process. The enable bit is self-cleared when in one shot
 * mode and one or more of the enabled capture circuits has had a capture event.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eInputPin     PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 */
static inline void PWM_EnableInputCapture(PWM_Type *base,
                                          pwm_sm_number_t eSubModule,
                                          pwm_sm_input_capture_pin_t eInputPin)
{
    if (eInputPin == kPWM_InputCapturePwmX)
    {
        base->SM[eSubModule].CAPTCTRLX |= PWM_CAPTCTRLX_ARMX_MASK;
    }
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    else if (eInputPin == kPWM_InputCapturePwmA)
    {
        base->SM[eSubModule].CAPTCTRLA |= PWM_CAPTCTRLA_ARMA_MASK;
    }
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    else
    {
        base->SM[eSubModule].CAPTCTRLB |= PWM_CAPTCTRLB_ARMB_MASK;
    }
#endif
}

/*!
 * @brief Disables the PWM submodule input capture operation.
 *
 * The enable bit can be cleared at any time to disable input capture operation.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eInputPin     PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 */
static inline void PWM_DisableInputCapture(PWM_Type *base,
                                           pwm_sm_number_t eSubModule,
                                           pwm_sm_input_capture_pin_t eInputPin)
{
    if (eInputPin == kPWM_InputCapturePwmX)
    {
        base->SM[eSubModule].CAPTCTRLX &= ~(uint16_t)PWM_CAPTCTRLX_ARMX_MASK;
    }
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    else if (eInputPin == kPWM_InputCapturePwmA)
    {
        base->SM[eSubModule].CAPTCTRLA &= ~(uint16_t)PWM_CAPTCTRLA_ARMA_MASK;
    }
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    else
    {
        base->SM[eSubModule].CAPTCTRLB &= ~(uint16_t)PWM_CAPTCTRLB_ARMB_MASK;
    }
#endif
}

/*!
 * @brief Get the logic value currently being driven into the PWM inputs.
 *
 * @param base         PWM peripheral base address
 * @param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * @param eInputPin    PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 *
 * @return The PWM submodule input capture pin logic value.
 */
static inline uint16_t PWM_GetInputValue(PWM_Type *base,
                                         pwm_sm_number_t eSubModule,
                                         pwm_sm_input_capture_pin_t eInputPin)
{
    uint16_t u16Reg;
    if (eInputPin == kPWM_InputCapturePwmX)
    {
        u16Reg = (base->SM[eSubModule].OCTRL & PWM_OCTRL_PWMX_IN_MASK) >> PWM_OCTRL_PWMX_IN_SHIFT;
    }
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER))
    else if (eInputPin == kPWM_InputCapturePwmA)
    {
        u16Reg = (base->SM[eSubModule].OCTRL & PWM_OCTRL_PWMA_IN_MASK) >> PWM_OCTRL_PWMA_IN_SHIFT;
    }
#endif
#if ((defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER))
    else
    {
        u16Reg = (base->SM[eSubModule].OCTRL & PWM_OCTRL_PWMB_IN_MASK) >> PWM_OCTRL_PWMB_IN_SHIFT;
    }
#endif
    return u16Reg;
}

/*! @}*/

/*!
 * @name Fault Protection Channel Related Interfaces
 * @{
 */

/*!
 * @brief Sets up the PWM fault protection channel configure.
 *
 * @param base                PWM peripheral base address.
 * @param eFaultProtection    PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * @param psConfig            Pointer to fault protection channel configure structure, see @ref
 * pwm_fault_protection_config_t.
 */
void PWM_SetupFaultProtectionConfig(PWM_Type *base,
                                    pwm_fault_protection_channel_t eFaultProtection,
                                    const pwm_fault_protection_config_t *psConfig);

/*!
 * @brief Mapping fault protection channel fault input status to PWM submodule output,
 *
 * @note Each PWM output can be mapping anyone or more fault inputs. The mapped fault protection channel inputs can
 *       disable PWM output.
 *
 * @param base               PWM peripheral base address.
 * @param eSubModule         PWM submodule number, see @ref pwm_sm_number_t.
 * @param ePwmOutput         PWM submodule output, see @ref pwm_sm_pwm_out_t.
 * @param psMapping          The fault input disable mapping structure, see @ref pwm_sm_fault_input_mapping_t.
 */
static inline void PWM_SetupSMFaultInputMapping(PWM_Type *base,
                                                pwm_sm_number_t eSubModule,
                                                pwm_sm_pwm_out_t ePwmOutput,
                                                const pwm_sm_fault_input_mapping_t *psMapping)
{
    if (ePwmOutput == kPWM_PwmA)
    {
        base->SM[eSubModule].DISMAP[0] = (base->SM[eSubModule].DISMAP[0] & ~(uint16_t)PWM_DISMAP_DIS0A_MASK) |
                                         PWM_DISMAP_DIS0A((uint16_t)psMapping->bFaultInput0Mapping |
                                                          ((uint16_t)psMapping->bFaultInput1Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput2Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput3Mapping << 3U));
        base->SM[eSubModule].DISMAP[1] = (base->SM[eSubModule].DISMAP[1] & ~(uint16_t)PWM_DISMAP_DIS1A_MASK) |
                                         PWM_DISMAP_DIS1A((uint16_t)psMapping->bFaultInput4Mapping |
                                                          ((uint16_t)psMapping->bFaultInput5Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput6Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput7Mapping << 3U));
    }
    else if (ePwmOutput == kPWM_PwmB)
    {
        base->SM[eSubModule].DISMAP[0] = (base->SM[eSubModule].DISMAP[0] & ~(uint16_t)PWM_DISMAP_DIS0B_MASK) |
                                         PWM_DISMAP_DIS0B((uint16_t)psMapping->bFaultInput0Mapping |
                                                          ((uint16_t)psMapping->bFaultInput1Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput2Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput3Mapping << 3U));
        base->SM[eSubModule].DISMAP[1] = (base->SM[eSubModule].DISMAP[1] & ~(uint16_t)PWM_DISMAP_DIS1B_MASK) |
                                         PWM_DISMAP_DIS1B((uint16_t)psMapping->bFaultInput4Mapping |
                                                          ((uint16_t)psMapping->bFaultInput5Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput6Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput7Mapping << 3U));
    }
    else
    {
        base->SM[eSubModule].DISMAP[0] = (base->SM[eSubModule].DISMAP[0] & ~(uint16_t)PWM_DISMAP_DIS0X_MASK) |
                                         PWM_DISMAP_DIS0X((uint16_t)psMapping->bFaultInput0Mapping |
                                                          ((uint16_t)psMapping->bFaultInput1Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput2Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput3Mapping << 3U));
        base->SM[eSubModule].DISMAP[1] = (base->SM[eSubModule].DISMAP[1] & ~(uint16_t)PWM_DISMAP_DIS1X_MASK) |
                                         PWM_DISMAP_DIS1X((uint16_t)psMapping->bFaultInput4Mapping |
                                                          ((uint16_t)psMapping->bFaultInput5Mapping << 1U) |
                                                          ((uint16_t)psMapping->bFaultInput6Mapping << 2U) |
                                                          ((uint16_t)psMapping->bFaultInput7Mapping << 3U));
    }
}

/*! @}*/

/*!
 * @name DMA Control Interfaces
 * @{
 */

/*!
 * @brief Sets up the PWM submodule DMA configure.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param psConfig      Pointer to PWM submodule DMA configure, see @ref pwm_sm_dma_config_t.
 */
void PWM_SetupDmaConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_dma_config_t *psConfig);

/*!
 * @brief Select the trigger source for enabled capture FIFOs DMA read request.
 *
 * @note This function only can be used when the bEnableCaptureDMA be true.
 *
 * @param base          PWM peripheral base address.
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param eCaptureDmaSource  The PWM DMA capture source.
 */
static inline void PWM_SetEnabledCaptureDmaSource(PWM_Type *base,
                                                  pwm_sm_number_t eSubModule,
                                                  pwm_sm_capture_dma_source_t eCaptureDmaSource)
{
    base->SM[eSubModule].DMAEN =
        (base->SM[eSubModule].DMAEN & ~(uint16_t)(PWM_DMAEN_FAND_MASK | PWM_DMAEN_CAPTDE_MASK)) |
        ((uint16_t)(eCaptureDmaSource) << PWM_DMAEN_CAPTDE_SHIFT);
}

/*! @}*/

/*!
 * @name Interrupts Interface
 * @{
 */

/*!
 * @brief Enables the PWM submodule interrupts according to a provided mask.
 *
 * This examples shows how to enable VAL 0 compare interrupt and VAL 1 compare interrupt.
 * @code
 *      PWM_EnableSMInterrupts(PWM, kPWM_SubModule0, kPWM_CompareVal0InterruptEnable |
 *      kPWM_CompareVal1InterruptEnable);
 * @endcode
 *
 * @param base          PWM peripheral base address
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param u16Mask       The PWM submodule interrupts to enable. Logical OR of @ref _pwm_sm_interrupt_enable.
 */
static inline void PWM_EnableSMInterrupts(PWM_Type *base, pwm_sm_number_t eSubModule, uint16_t u16Mask)
{
    base->SM[eSubModule].INTEN |= u16Mask;
}

/*!
 * @brief Disables the PWM submodule interrupts according to a provided mask.
 *
 * This examples shows how to disable VAL 0 compare interrupt and VAL 1 compare interrupt.
 * @code
 *      PWM_DisbaleSMInterrupts(PWM, kPWM_SubModule0, kPWM_CompareVal0InterruptEnable |
 *      kPWM_CompareVal1InterruptEnable);
 * @endcode
 *
 * @param base          PWM peripheral base address
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param u16Mask       The PWM submodule interrupts to enable. Logical OR of @ref _pwm_sm_interrupt_enable.
 */
static inline void PWM_DisbaleSMInterrupts(PWM_Type *base, pwm_sm_number_t eSubModule, uint16_t u16Mask)
{
    base->SM[eSubModule].INTEN &= ~u16Mask;
}

/*!
 * @brief Enables the PWM fault protection channel interrupt according to a provided mask.
 *
 * This examples shows how to enable fault pin 0 interrupt and fault pin 1 interrupt.
 * @code
 *      PWM_EnableFaultInterrupts(PWM, kPWM_FaultProtection0, kPWM_Fault0InterruptEnable |
 *      kPWM_Fault1InterruptEnable);
 * @endcode
 *
 * @param base              PWM peripheral base address
 * @param eFaultProtection  PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * @param u16Mask           The PWM fault protection channel interrupts to enable. Logical OR of @ref
 *                          _pwm_fault_protection_interrupt_enable.
 */
static inline void PWM_EnableFaultInterrupts(PWM_Type *base,
                                             pwm_fault_protection_channel_t eFaultProtection,
                                             uint16_t u16Mask)
{
    base->FAULT[eFaultProtection].FCTRL |= u16Mask;
}

/*!
 * @brief Disables the PWM fault protection channel interrupt according to a provided mask.
 *
 * This examples shows how to disable fault pin 0 interrupt and fault pin 1 interrupt.
 * @code
 *      PWM_DisableFaultInterrupts(PWM, kPWM_FaultProtection0, kPWM_Fault0InterruptEnable |
 *      kPWM_Fault1InterruptEnable);
 * @endcode
 *
 * @param base              PWM peripheral base address
 * @param eFaultProtection  PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * @param u16Mask           The PWM fault protection channel interrupts to disable. Logical OR of @ref
 *                          _pwm_fault_protection_interrupt_enable.
 */
static inline void PWM_DisableFaultInterrupts(PWM_Type *base,
                                              pwm_fault_protection_channel_t eFaultProtection,
                                              uint16_t u16Mask)
{
    base->FAULT[eFaultProtection].FCTRL &= ~u16Mask;
}

/*! @}*/

/*!
 * @name Status Flag Interfaces
 * @{
 */

/*!
 * @brief Gets the PWM submodule status flags.
 *
 * This examples shows how to check whether the submodule VAL0 compare flag set.
 * @code
 *      if((PWM_GetSMStatusFlags(PWM, kPWM_SubModule0) & kPWM_CompareVal0Flag) != 0U)
 *      {
 * 	        ...
 *      }
 * @endcode
 *
 * @param base          PWM peripheral base address
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 *
 * @return The PWM submodule status flags. This is the logical OR of @ref pwm_sm_status_flags_t.
 */

static inline uint16_t PWM_GetSMStatusFlags(PWM_Type *base, pwm_sm_number_t eSubModule)
{
    return base->SM[eSubModule].STS & (uint16_t)kPWM_ALLSMStatusFlags;
}

/*!
 * @brief Clears the PWM submodule status flags.
 *
 * @note The kPWM_RegUpdatedFlag can't be cleared by software.
 *
 * This examples shows how to clear the submodule VAL0 compare flag.
 * @code
 *      PWM_ClearSMStatusFlags(PWM, kPWM_SubModule0, kPWM_CompareVal0Flag);
 * @endcode
 * @param base          PWM peripheral base address
 * @param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * @param u16Mask       The status flags to clear. This is the logical OR of @ref pwm_sm_status_flags_t.
 */
static inline void PWM_ClearSMStatusFlags(PWM_Type *base, pwm_sm_number_t eSubModule, uint16_t u16Mask)
{
    base->SM[eSubModule].STS = u16Mask;
}

/*!
 * @brief Gets the PWM fault protection status flags.
 *
 * This examples shows how to check whether the fault protection channel fault input pin 0 set.
 * @code
 *      if((PWM_GetFaultStatusFlags(PWM, kPWM_FaultProtection0) & kPWM_FaultPin0Flag) != 0U)
 *      {
 * 	        ...
 *      }
 * @endcode
 *
 * @param base              PWM peripheral base address
 * @param eFaultProtection  PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * @return The PWM fault protection channel status flags. This is the logical OR of @ref
 *         _pwm_fault_protection_status_flags.
 */
static inline uint16_t PWM_GetFaultStatusFlags(PWM_Type *base, pwm_fault_protection_channel_t eFaultProtection)
{
    return base->FAULT[eFaultProtection].FSTS & (uint16_t)kPWM_ALLFaultStatusFlags;
}

/*!
 * @brief Clears the PWM fault protection status flags according to a provided mask.
 *
 * @note The kPWM_FaultPin0ActiveFlag ~ kPWM_FaultPin3ActiveFlag can't be cleared by software.
 *
 * This examples shows how to clear the fault protection channel fault 0 flag.
 * @code
 *      PWM_ClearFaultStatusFlags(PWM, kPWM_FaultProtection0, kPWM_Fault0Flag);
 * @endcode
 *
 * @param base              PWM peripheral base address
 * @param eFaultProtection  PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * @param u16Mask           The PWM fault protection status flags to be clear. Logical OR of @ref
 *                          _pwm_fault_protection_status_flags.
 */
static inline void PWM_ClearFaultStatusFlags(PWM_Type *base,
                                             pwm_fault_protection_channel_t eFaultProtection,
                                             uint16_t u16Mask)
{
    base->FAULT[eFaultProtection].FSTS |= PWM_FSTS_FFLAG(u16Mask);
}

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_PWM_H_ */
