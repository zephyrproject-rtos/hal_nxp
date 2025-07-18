; -------------------------------------------------------------------------
;  @file:    startup_MIMX94398_cm7_core1.s
;  @purpose: CMSIS Cortex-M7 Core Device Startup File
;            MIMX94398_cm7_core1
;  @version: 1.0
;  @date:    2023-11-1
;  @build:   b250109
; -------------------------------------------------------------------------
;
; Copyright 1997-2016 Freescale Semiconductor, Inc.
; Copyright 2016-2025 NXP
; SPDX-License-Identifier: BSD-3-Clause
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)
        SECTION HEAP:DATA:NOROOT(3)
        SECTION RW:DATA:NOROOT(2)
        SECTION QACCESS_CODE_VAR:DATA:NOROOT(3)
        SECTION QACCESS_DATA_VAR:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table
        PUBLIC  __vector_table_0x1c
        PUBLIC  __Vectors
        PUBLIC  __Vectors_End
        PUBLIC  __Vectors_Size

        DATA

__iar_init$$done:              ; The vector table is not needed
                      ; until after copy initialization is done

__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler

        DCD     NMI_Handler                                   ;NMI Handler
        DCD     HardFault_Handler                             ;Hard Fault Handler
        DCD     MemManage_Handler                             ;MPU Fault Handler
        DCD     BusFault_Handler                              ;Bus Fault Handler
        DCD     UsageFault_Handler                            ;Usage Fault Handler
__vector_table_0x1c
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     0                                             ;Reserved
        DCD     SVC_Handler                                   ;SVCall Handler
        DCD     DebugMon_Handler                              ;Debug Monitor Handler
        DCD     0                                             ;Reserved
        DCD     PendSV_Handler                                ;PendSV Handler
        DCD     SysTick_Handler                               ;SysTick Handler

                                                              ;External Interrupts
        DCD     Reserved16_IRQHandler                         ;Reserved interrupt
        DCD     Reserved17_IRQHandler                         ;DAP interrupt
        DCD     Reserved18_IRQHandler                         ;CTI trigger outputs from CM7 platform
        DCD     Reserved19_IRQHandler                         ;CTI trigger outputs from CM33 platform
        DCD     Reserved20_IRQHandler                         ;CTI trigger outputs from CA55 platform
        DCD     Reserved21_IRQHandler                         ;Performance Unit Interrupts from CA55 platform
        DCD     Reserved22_IRQHandler                         ;ECC error from CA55 platform cache
        DCD     Reserved23_IRQHandler                         ;1-bit or 2-bit ECC or Parity error from CA55 platform cache
        DCD     Reserved24_IRQHandler                         ;CTI trigger outputs from CM7_1 platform
        DCD     Reserved25_IRQHandler                         ;CTI trigger outputs from CM33_sync platform
        DCD     CAN1_IRQHandler                               ;CAN1 interrupt
        DCD     CAN1_ERROR_IRQHandler                         ;CAN1 error interrupt
        DCD     GPIO1_INT0_IRQHandler                         ;General Purpose Input/Output 1 interrupt 0
        DCD     GPIO1_INT1_IRQHandler                         ;General Purpose Input/Output 1 interrupt 1
        DCD     I3C1_IRQHandler                               ;Improved Inter-Integrated Circuit 1 interrupt
        DCD     LPI2C1_IRQHandler                             ;Low Power Inter-Integrated Circuit module 1
        DCD     LPI2C2_IRQHandler                             ;Low Power Inter-Integrated Circuit module 2
        DCD     LPIT1_IRQHandler                              ;Low Power Periodic Interrupt Timer 1
        DCD     LPSPI1_IRQHandler                             ;Low Power Serial Peripheral Interface 1
        DCD     LPSPI2_IRQHandler                             ;Low Power Serial Peripheral Interface 2
        DCD     LPTMR1_IRQHandler                             ;Low Power Timer 1
        DCD     LPUART1_IRQHandler                            ;Low Power UART 1
        DCD     LPUART2_IRQHandler                            ;Low Power UART 2
        DCD     Reserved39_IRQHandler                         ;AONMIX Sentinel MU0 SideA interrupt
        DCD     Reserved40_IRQHandler                         ;AONMIX Sentinel MU1 SideA interrupt
        DCD     Reserved41_IRQHandler                         ;AONMIX Sentinel MU2 SideA interrupt
        DCD     Reserved42_IRQHandler                         ;AONMIX Sentinel MU3 SideA interrupt
        DCD     Reserved43_IRQHandler                         ;AONMIX Sentinel MU4 SideA interrupt
        DCD     Reserved44_IRQHandler                         ;AONMIX Sentinel MU5 SideA interrupt
        DCD     Reserved45_IRQHandler                         ;AONMIX Sentinel MU6 SideA interrupt
        DCD     Reserved46_IRQHandler                         ;AONMIX Sentinel MU7 SideA interrupt
        DCD     Reserved47_IRQHandler                         ;AONMIX Sentinel MU8 SideA interrupt
        DCD     V2X_FH_APCH0_IRQHandler                       ;V2X-FH MU APCH0 (APP0) interrupt
        DCD     V2X_FH_APHSM1_IRQHandler                      ;V2X-FH MU APHSM1 (HSM1) interrupt
        DCD     TPM1_IRQHandler                               ;Timer PWM module 1
        DCD     TPM2_IRQHandler                               ;Timer PWM module 2
        DCD     WDOG1_IRQHandler                              ;Watchdog 1 Interrupt
        DCD     WDOG2_IRQHandler                              ;Watchdog 2 Interrupt
        DCD     SAI1_IRQHandler                               ;Serial Audio Interface 1
        DCD     GPT1_IRQHandler                               ;AONMIX GPT1
        DCD     CAN2_IRQHandler                               ;WAKEUPMIX CAN2 interrupt
        DCD     CAN2_ERROR_IRQHandler                         ;WAKEUPMIX CAN2 error interrupt
        DCD     CAN3_IRQHandler                               ;WAKEUPMIX CAN3 interrupt
        DCD     CAN3_ERROR_IRQHandler                         ;WAKEUPMIX CAN3 error interrupt
        DCD     CAN4_IRQHandler                               ;WAKEUPMIX CAN4 interrupt
        DCD     CAN4_ERROR_IRQHandler                         ;WAKEUPMIX CAN4 error interrupt
        DCD     CAN5_IRQHandler                               ;WAKEUPMIX CAN5 interrupt
        DCD     CAN5_ERROR_IRQHandler                         ;WAKEUPMIX CAN5 error interrupt
        DCD     FLEXIO1_IRQHandler                            ;WAKEUPMIX Flexible IO 1 interrupt
        DCD     FLEXIO2_IRQHandler                            ;WAKEUPMIX Flexible IO 2 interrupt
        DCD     FLEXIO3_IRQHandler                            ;NETCMIX Flexible IO 3 interrupt
        DCD     FLEXIO4_IRQHandler                            ;NETCMIX Flexible IO 4 interrupt
        DCD     Reserved68_IRQHandler                         ;Earlier assigned for WAKEUPMIX XSPI1 interrupt
        DCD     Reserved69_IRQHandler                         ;Earlier assigned for WAKEUPMIX XSPI2 interrupt
        DCD     GPIO2_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 2 interrupt 0
        DCD     GPIO2_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 2 interrupt 1
        DCD     GPIO3_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 3 interrupt 0
        DCD     GPIO3_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 3 interrupt 1
        DCD     GPIO4_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 4 interrupt 0
        DCD     GPIO4_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 4 interrupt 1
        DCD     GPIO5_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 5 interrupt 0
        DCD     GPIO5_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 5 interrupt 1
        DCD     GPIO6_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 6 interrupt 0
        DCD     GPIO6_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 6 interrupt 1
        DCD     GPIO7_INT0_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 7 interrupt 0
        DCD     GPIO7_INT1_IRQHandler                         ;WAKEUPMIX General Purpose Input/Output 7 interrupt 1
        DCD     I3C2_IRQHandler                               ;WAKEUPMIX Improved Inter-Integrated Circuit 2 interrupt
        DCD     LPI2C3_IRQHandler                             ;WAKEUPMIX Low Power Inter-Integrated Circuit module 3
        DCD     LPI2C4_IRQHandler                             ;WAKEUPMIX Low Power Inter-Integrated Circuit module 4
        DCD     LPIT2_IRQHandler                              ;WAKEUPMIX Low Power Periodic Interrupt Timer 2
        DCD     LPIT3_IRQHandler                              ;WAKEUPMIX Low Power Periodic Interrupt Timer 3
        DCD     LPSPI3_IRQHandler                             ;WAKEUPMIX Low Power Serial Peripheral Interface 3
        DCD     LPSPI4_IRQHandler                             ;WAKEUPMIX Low Power Serial Peripheral Interface 4
        DCD     LPTMR2_IRQHandler                             ;WAKEUPMIX Low Power Timer 2
        DCD     LPUART3_IRQHandler                            ;WAKEUPMIX Low Power UART 3
        DCD     LPUART4_IRQHandler                            ;WAKEUPMIX Low Power UART 4
        DCD     LPUART5_IRQHandler                            ;WAKEUPMIX Low Power UART 5
        DCD     LPUART6_IRQHandler                            ;WAKEUPMIX Low Power UART 6
        DCD     LPUART7_IRQHandler                            ;WAKEUPMIX Low Power UART 7
        DCD     LPUART8_IRQHandler                            ;WAKEUPMIX Low Power UART 8
        DCD     LPUART9_IRQHandler                            ;WAKEUPMIX Low Power UART 9
        DCD     LPUART10_IRQHandler                           ;WAKEUPMIX Low Power UART 10
        DCD     LPUART11_IRQHandler                           ;WAKEUPMIX Low Power UART 11
        DCD     LPUART12_IRQHandler                           ;WAKEUPMIX Low Power UART 12
        DCD     BBNSM_IRQHandler                              ;BBNSM Non-Secure interrupt
        DCD     SYSCTR1_IRQHandler                            ;AONMIX System Counter compare interrupt
        DCD     TPM3_IRQHandler                               ;WAKEUPMIX Timer PWM module 3
        DCD     TPM4_IRQHandler                               ;WAKEUPMIX Timer PWM module 4
        DCD     TPM5_IRQHandler                               ;WAKEUPMIX Timer PWM module 5
        DCD     TPM6_IRQHandler                               ;WAKEUPMIX Timer PWM module 6
        DCD     WDOG3_IRQHandler                              ;WAKEUPMIX Watchdog 3 Interrupt
        DCD     WDOG4_IRQHandler                              ;WAKEUPMIX Watchdog 4 Interrupt
        DCD     WDOG5_IRQHandler                              ;WAKEUPMIX Watchdog 5 Interrupt
        DCD     WDOG6_IRQHandler                              ;WAKEUPMIX Watchdog 6 Interrupt
        DCD     WDOG7_IRQHandler                              ;NETCMIX Watchdog 7 Interrupt
        DCD     WDOG8_IRQHandler                              ;NETCMIX Watchdog 8 Interrupt
        DCD     USDHC1_IRQHandler                             ;MEGAMIX uSDHC1 Enhanced SDHC Interrupt Request
        DCD     USDHC2_IRQHandler                             ;MEGAMIX uSDHC2 Enhanced SDHC Interrupt Request
        DCD     EDMA2_ERROR_IRQHandler                        ;WAKEUPMIX EDMA2 error interrupt
        DCD     Reserved115_IRQHandler                        ;JTAGSW DAP MDM-AP SRC reset source
        DCD     Reserved116_IRQHandler                        ;JTAGC SRC reset source (the JTAGC used for boundary scan, not JTAGC used for password authentication)
        DCD     SAI2_IRQHandler                               ;WAKEUPMIX SAI2 interrupt
        DCD     SAI3_IRQHandler                               ;WAKEUPMIX SAI3 interrupt
        DCD     SAI4_IRQHandler                               ;WAKEUPMIX SAI4 interrupt
        DCD     LPSPI5_IRQHandler                             ;WAKEUPMIX LPSPI5 interrupt
        DCD     LPSPI6_IRQHandler                             ;WAKEUPMIX LPSPI6 interrupt
        DCD     LPSPI7_IRQHandler                             ;WAKEUPMIX LPSPI7 interrupt
        DCD     LPSPI8_IRQHandler                             ;WAKEUPMIX LPSPI8 interrupt
        DCD     LPI2C5_IRQHandler                             ;WAKEUPMIX LPI2C5 interrupt
        DCD     LPI2C6_IRQHandler                             ;WAKEUPMIX LPI2C6 interrupt
        DCD     LPI2C7_IRQHandler                             ;WAKEUPMIX LPI2C7 interrupt
        DCD     LPI2C8_IRQHandler                             ;WAKEUPMIX LPI2C8 interrupt
        DCD     PDM_HWVAD_ERROR_IRQHandler                    ;WAKEUPMIX PDM interrupt(hwvad err)
        DCD     PDM_HWVAD_EVENT_IRQHandler                    ;WAKEUPMIX PDM interrupt(hwvad event)
        DCD     PDM_ERROR_IRQHandler                          ;WAKEUPMIX PDM interrupt(mic err)
        DCD     PDM_EVENT_IRQHandler                          ;WAKEUPMIX PDM interrupt(mic event)
        DCD     USDHC3_IRQHandler                             ;MEGAMIX uSDHC3 Enhanced SDHC Interrupt Request
        DCD     ADC_ER_IRQHandler                             ;WAKEUPMIX ADC1 interrupt(er)
        DCD     ADC_WD_IRQHandler                             ;WAKEUPMIX ADC1 interrupt(wd)
        DCD     ADC_EOC_IRQHandler                            ;WAKEUPMIX ADC1 interrupt(eoc)
        DCD     Reserved136_IRQHandler                        ;I3C1 wakeup irq after double sync
        DCD     Reserved137_IRQHandler                        ;I3C2 wakeup irq after double sync
        DCD     MU5_A_IRQHandler                              ;AONMIX MU5 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU6_A_IRQHandler                              ;AONMIX MU6 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU7_A_IRQHandler                              ;AONMIX MU7 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU10_B_IRQHandler                             ;WAKEUPMIX MU10 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU11_B_IRQHandler                             ;WAKEUPMIX MU11 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU12_A_IRQHandler                             ;WAKEUPMIX MU12 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU13_A_IRQHandler                             ;WAKEUPMIX MU13 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU18_A_IRQHandler                             ;WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU18_B_IRQHandler                             ;WAKEUPMIX MU18 Ored of all (tx,rx,gp,core,murip) interrupt to MUB
        DCD     MU_E1_A_IRQHandler                            ;NETCMIX MU E1 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU_E2_A_IRQHandler                            ;NETCMIX MU E2 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU_E3_A_IRQHandler                            ;NETCMIX MU E3 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     MU_E4_A_IRQHandler                            ;NETCMIX MU E4 Ored of all (tx,rx,gp,core,murip) interrupt to MUA
        DCD     XSPI_SLV_IRQHandler                           ;WAKEUPMIX XSPI Responder
        DCD     FCCU_INT0_IRQHandler                          ;AONMIX FCCU Interrupt Reaction 0
        DCD     FCCU_INT1_IRQHandler                          ;AONMIX FCCU Interrupt Reaction 1
        DCD     FCCU_INT2_IRQHandler                          ;AONMIX FCCU Interrupt Reaction 2
        DCD     FCCU_INT3_IRQHandler                          ;AONMIX FCCU Interrupt Reaction 3(new interrupt for CM33_sync)
        DCD     FCCU_INT4_IRQHandler                          ;AONMIX FCCU Interrupt Reaction 4(new interrupt for CM7_1)
        DCD     STCU_IRQHandler                               ;AONMIX STCU Selftest end Interrupt
        DCD     XBAR1_CH0_CH1_IRQHandler                      ;XBAR1 interrupt 0 and 1
        DCD     XBAR1_CH2_CH3_IRQHandler                      ;XBAR1 interrupt 2 and 3
        DCD     GPT2_IRQHandler                               ;WAKEUPMIX GPT2 interrupt
        DCD     GPT3_IRQHandler                               ;WAKEUPMIX GPT3 interrupt
        DCD     GPT4_IRQHandler                               ;WAKEUPMIX GPT4 interrupt
        DCD     Reserved163_IRQHandler                        ;Endat2_1 interrupt/Hiperface1-DSL interrupt for safe events logged in EVENT_S register/Endat3 interrupt for background communication
        DCD     Reserved164_IRQHandler                        ;Hiperface1-DSL interrupt for events logged in EVENT_H or EVENT_L register/Endat3 interrupt
        DCD     Reserved165_IRQHandler                        ;Endat2_2  interrupt/Hiperface2-DSL interrupt for safe events logged in EVENT_S register/Biss interrupt for start of frame transmission
        DCD     Reserved166_IRQHandler                        ;Hiperface2-DSL interrupt for events logged in EVENT_H or EVENT_L register/Biss interrupt for end of frame transmission
        DCD     Reserved167_IRQHandler                        ;Flexpwm1(reload error, fault condition)
        DCD     Reserved168_IRQHandler                        ;Flexpwm1(capt0, comp0, reload0)
        DCD     Reserved169_IRQHandler                        ;Flexpwm1(capt1, comp1, reload1)
        DCD     Reserved170_IRQHandler                        ;Flexpwm1(capt2, comp2, reload2)
        DCD     Reserved171_IRQHandler                        ;Flexpwm1(capt3, comp3, reload3)
        DCD     Reserved172_IRQHandler                        ;Flexpwm2(reload error, fault condition)
        DCD     Reserved173_IRQHandler                        ;Flexpwm2(capt0, comp0, reload0)
        DCD     Reserved174_IRQHandler                        ;Flexpwm2(capt1, comp1, reload1)
        DCD     Reserved175_IRQHandler                        ;Flexpwm2(capt2, comp2, reload2)
        DCD     Reserved176_IRQHandler                        ;Flexpwm2(capt3, comp3, reload3)
        DCD     Reserved177_IRQHandler                        ;Flexpwm3(reload error, fault condition)
        DCD     Reserved178_IRQHandler                        ;Flexpwm3(capt0, comp0, reload0)
        DCD     Reserved179_IRQHandler                        ;Flexpwm3(capt1, comp1, reload1)
        DCD     Reserved180_IRQHandler                        ;Flexpwm3(capt2, comp2, reload2)
        DCD     Reserved181_IRQHandler                        ;Flexpwm3(capt3, comp3, reload3)
        DCD     Reserved182_IRQHandler                        ;Flexpwm4(reload error, fault condition)
        DCD     Reserved183_IRQHandler                        ;Flexpwm4(capt0, comp0, reload0)
        DCD     Reserved184_IRQHandler                        ;Flexpwm4(capt1, comp1, reload1)
        DCD     Reserved185_IRQHandler                        ;Flexpwm4(capt2, comp2, reload2)
        DCD     Reserved186_IRQHandler                        ;Flexpwm4(capt3, comp3, reload3)
        DCD     ENC1_IRQHandler                               ;Quad dec1 interrupt
        DCD     ENC2_IRQHandler                               ;Quad dec2 interrupt
        DCD     ENC3_IRQHandler                               ;Quad dec3 interrupt
        DCD     ENC4_IRQHandler                               ;Quad dec4 interrupt
        DCD     EWM_IRQHandler                                ;Ewm out interrupt
        DCD     Reserved192_IRQHandler                        ;Ethercat interrupt(PDI_OPB)
        DCD     Reserved193_IRQHandler                        ;Ethercat interrupt(RESET_OUT)
        DCD     Reserved194_IRQHandler                        ;Ethercat interrupt(SYNC_OUT0)
        DCD     Reserved195_IRQHandler                        ;Ethercat interrupt(SYNC_OUT1)
        DCD     USB1_IRQHandler                               ;USB-1(USB 3.0 Controller) interrupt
        DCD     USB2_IRQHandler                               ;USB-2(USB 2.0 Controller) interrupt
        DCD     SINC1_CH0_IRQHandler                          ;SINC Filter1(sinc filter glue1) Channel 0 interrupt
        DCD     SINC1_CH1_IRQHandler                          ;SINC Filter1(sinc filter glue1) Channel 1 interrupt
        DCD     SINC1_CH2_IRQHandler                          ;SINC Filter1(sinc filter glue1) Channel 2 interrupt
        DCD     SINC1_CH3_IRQHandler                          ;SINC Filter1(sinc filter glue1) Channel 3 interrupt
        DCD     SINC2_CH0_IRQHandler                          ;SINC Filter2(sinc filter glue2) Channel 0 interrupt
        DCD     SINC2_CH1_IRQHandler                          ;SINC Filter2(sinc filter glue2) Channel 1 interrupt
        DCD     SINC2_CH2_IRQHandler                          ;SINC Filter2(sinc filter glue2) Channel 2 interrupt
        DCD     SINC2_CH3_IRQHandler                          ;SINC Filter2(sinc filter glue2) Channel 3 interrupt
        DCD     SINC3_CH0_IRQHandler                          ;SINC Filter3(sinc filter glue3 Channel 0 interrupt
        DCD     SINC3_CH1_IRQHandler                          ;SINC Filter3(sinc filter glue3) Channel 1 interrupt
        DCD     SINC3_CH2_IRQHandler                          ;SINC Filter3(sinc filter glue3) Channel 2 interrupt
        DCD     SINC3_CH3_IRQHandler                          ;SINC Filter3(sinc filter glue3) Channel 3 interrupt
        DCD     SINC4_CH0_IRQHandler                          ;SINC Filter4(sinc filter glue4 Channel 0 interrupt
        DCD     SINC4_CH1_IRQHandler                          ;SINC Filter4(sinc filter glue4) Channel 1 interrupt
        DCD     SINC4_CH2_IRQHandler                          ;SINC Filter4(sinc filter glue4) Channel 2 interrupt
        DCD     SINC4_CH3_IRQHandler                          ;SINC Filter4(sinc filter glue4) Channel 3 interrupt
        DCD     TMR1_IRQHandler                               ;QTIMER1 interrupt
        DCD     TMR2_IRQHandler                               ;QTIMER2 interrupt
        DCD     TMR3_IRQHandler                               ;QTIMER3 interrupt
        DCD     TMR4_IRQHandler                               ;QTIMER4 interrupt
        DCD     TMR5_IRQHandler                               ;QTIMER5 interrupt
        DCD     TMR6_IRQHandler                               ;QTIMER6 interrupt
        DCD     TMR7_IRQHandler                               ;QTIMER7 interrupt
        DCD     TMR8_IRQHandler                               ;QTIMER8 interrupt
        DCD     EDMA4_ERROR_IRQHandler                        ;EDMA4 error interrupt
        DCD     Reserved223_IRQHandler                        ;Anamix Gllitch Detector output (da_ip_voltage_glitch_detector_cln16ffc). It's a latch signal. It can be cleared.
        DCD     Reserved224_IRQHandler                        ;Anamix VDET output (da_ip_vdetect_c16ffc). Detects high threshold on Core supply. It's a latch signal. It can be cleared.
        DCD     Reserved225_IRQHandler                        ;Anamix VDET output (da_ip_vdetect_c16ffc). Detects Low threshold on Core supply. It's a latch signal. It can be cleared
        DCD     Reserved226_IRQHandler                        ;LPCG Timeout interrupt generated by CCGR (CCM)
        DCD     Reserved227_IRQHandler                        ;Reserved227
        DCD     Reserved228_IRQHandler                        ;Reserved228
        DCD     Reserved229_IRQHandler                        ;Reserved229
        DCD     Reserved230_IRQHandler                        ;Reserved230
        DCD     Reserved231_IRQHandler                        ;Reserved231
        DCD     Reserved232_IRQHandler                        ;Reserved232
        DCD     Reserved233_IRQHandler                        ;Reserved233
        DCD     Reserved234_IRQHandler                        ;Reserved234
        DCD     Reserved235_IRQHandler                        ;Reserved235
        DCD     Reserved236_IRQHandler                        ;Reserved236
        DCD     Reserved237_IRQHandler                        ;Reserved237
        DCD     Reserved238_IRQHandler                        ;Reserved238
        DCD     Reserved239_IRQHandler                        ;Reserved239
        DCD     IRQSTEERM7_CH0_IRQHandler                     ;IRQSTEERM7 output channel 0 interrupt
        DCD     IRQSTEERM7_CH1_IRQHandler                     ;IRQSTEERM7 output channel 1 interrupt
        DCD     IRQSTEERM7_CH2_IRQHandler                     ;IRQSTEERM7 output channel 2 interrupt
        DCD     IRQSTEERM7_CH3_IRQHandler                     ;IRQSTEERM7 output channel 3 interrupt
        DCD     IRQSTEERM7_CH4_IRQHandler                     ;IRQSTEERM7 output channel 4 interrupt
        DCD     IRQSTEERM7_CH5_IRQHandler                     ;IRQSTEERM7 output channel 5 interrupt
        DCD     IRQSTEERM7_CH6_IRQHandler                     ;IRQSTEERM7 output channel 6 interrupt
        DCD     IRQSTEERM7_CH7_IRQHandler                     ;IRQSTEERM7 output channel 7 interrupt
        DCD     IRQSTEERM7_CH8_IRQHandler                     ;IRQSTEERM7 output channel 8 interrupt
        DCD     IRQSTEERM7_CH9_IRQHandler                     ;IRQSTEERM7 output channel 9 interrupt
        DCD     IRQSTEERM7_CH10_IRQHandler                    ;IRQSTEERM7 output channel 10 interrupt
        DCD     IRQSTEERM7_CH11_IRQHandler                    ;IRQSTEERM7 output channel 11 interrupt
        DCD     IRQSTEERM7_CH12_IRQHandler                    ;IRQSTEERM7 output channel 12 interrupt
        DCD     Reserved253_IRQHandler                        ;Global fault event Module=NETC IRQ=237
        DCD     EDMA2_CH0_IRQHandler                          ;WAKEUPMIX EDMA2 channel 0 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[0] - inputs[0]) IRQ=238
        DCD     EDMA2_CH1_IRQHandler                          ;WAKEUPMIX EDMA2 channel 1 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[1] - inputs[1]) IRQ=239
        DCD     EDMA2_CH2_IRQHandler                          ;WAKEUPMIX EDMA2 channel 2 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[2] - inputs[2]) IRQ=240
        DCD     EDMA2_CH3_IRQHandler                          ;WAKEUPMIX EDMA2 channel 3 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[3] - inputs[3]) IRQ=241
        DCD     EDMA2_CH4_IRQHandler                          ;WAKEUPMIX EDMA2 channel 4 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[4] - inputs[4]) IRQ=242
        DCD     EDMA2_CH5_IRQHandler                          ;WAKEUPMIX EDMA2 channel 5 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[5] - inputs[5]) IRQ=243
        DCD     EDMA2_CH6_IRQHandler                          ;WAKEUPMIX EDMA2 channel 6 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[6] - inputs[6]) IRQ=244
        DCD     EDMA2_CH7_IRQHandler                          ;WAKEUPMIX EDMA2 channel 7 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[7] - inputs[7]) IRQ=245
        DCD     EDMA2_CH8_IRQHandler                          ;WAKEUPMIX EDMA2 channel 8 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[8] - inputs[8]) IRQ=246
        DCD     EDMA2_CH9_IRQHandler                          ;WAKEUPMIX EDMA2 channel 9 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[9] - inputs[9]) IRQ=247
        DCD     EDMA2_CH10_IRQHandler                         ;WAKEUPMIX EDMA2 channel 10 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[10] - inputs[10]) IRQ=248
        DCD     EDMA2_CH11_IRQHandler                         ;WAKEUPMIX EDMA2 channel 11 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[11] - inputs[11]) IRQ=249
        DCD     EDMA2_CH12_IRQHandler                         ;WAKEUPMIX EDMA2 channel 12 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[12] - inputs[12]) IRQ=250
        DCD     EDMA2_CH13_IRQHandler                         ;WAKEUPMIX EDMA2 channel 13 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[13] - inputs[13]) IRQ=251
        DCD     EDMA2_CH14_IRQHandler                         ;WAKEUPMIX EDMA2 channel 14 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[14] - inputs[14]) IRQ=252
        DCD     EDMA2_CH15_IRQHandler                         ;WAKEUPMIX EDMA2 channel 15 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[15] - inputs[15]) IRQ=253
        DCD     EDMA2_CH16_IRQHandler                         ;WAKEUPMIX EDMA2 channel 16 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[16] - inputs[16]) IRQ=254
        DCD     EDMA2_CH17_IRQHandler                         ;WAKEUPMIX EDMA2 channel 17 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[17] - inputs[17]) IRQ=255
        DCD     EDMA2_CH18_IRQHandler                         ;WAKEUPMIX EDMA2 channel 18 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[18] - inputs[18]) IRQ=256
        DCD     EDMA2_CH19_IRQHandler                         ;WAKEUPMIX EDMA2 channel 19 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[19] - inputs[19]) IRQ=257
        DCD     EDMA2_CH20_IRQHandler                         ;WAKEUPMIX EDMA2 channel 20 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[20] - inputs[20]) IRQ=258
        DCD     EDMA2_CH21_IRQHandler                         ;WAKEUPMIX EDMA2 channel 21 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[21] - inputs[21]) IRQ=259
        DCD     EDMA2_CH22_IRQHandler                         ;WAKEUPMIX EDMA2 channel 22 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[22] - inputs[22]) IRQ=260
        DCD     EDMA2_CH23_IRQHandler                         ;WAKEUPMIX EDMA2 channel 23 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[23] - inputs[23]) IRQ=261
        DCD     EDMA2_CH24_IRQHandler                         ;WAKEUPMIX EDMA2 channel 24 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[24] - inputs[24]) IRQ=262
        DCD     EDMA2_CH25_IRQHandler                         ;WAKEUPMIX EDMA2 channel 25 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[25] - inputs[25]) IRQ=263
        DCD     EDMA2_CH26_IRQHandler                         ;WAKEUPMIX EDMA2 channel 26 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[26] - inputs[26]) IRQ=264
        DCD     EDMA2_CH27_IRQHandler                         ;WAKEUPMIX EDMA2 channel 27 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[27] - inputs[27]) IRQ=265
        DCD     EDMA2_CH28_IRQHandler                         ;WAKEUPMIX EDMA2 channel 28 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[28] - inputs[28]) IRQ=266
        DCD     EDMA2_CH29_IRQHandler                         ;WAKEUPMIX EDMA2 channel 29 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[29] - inputs[29]) IRQ=267
        DCD     EDMA2_CH30_IRQHandler                         ;WAKEUPMIX EDMA2 channel 30 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[30] - inputs[30]) IRQ=268
        DCD     EDMA2_CH31_IRQHandler                         ;WAKEUPMIX EDMA2 channel 31 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[31] - inputs[31]) IRQ=269
        DCD     EDMA2_CH32_IRQHandler                         ;WAKEUPMIX EDMA2 channel 32 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[32] - inputs[32]) IRQ=270
        DCD     EDMA2_CH33_IRQHandler                         ;WAKEUPMIX EDMA2 channel 33 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[33] - inputs[33]) IRQ=271
        DCD     EDMA2_CH34_IRQHandler                         ;WAKEUPMIX EDMA2 channel 34 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[34] - inputs[34]) IRQ=272
        DCD     EDMA2_CH35_IRQHandler                         ;WAKEUPMIX EDMA2 channel 35 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[35] - inputs[35]) IRQ=273
        DCD     EDMA2_CH36_IRQHandler                         ;WAKEUPMIX EDMA2 channel 36 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[36] - inputs[36]) IRQ=274
        DCD     EDMA2_CH37_IRQHandler                         ;WAKEUPMIX EDMA2 channel 37 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[37] - inputs[37]) IRQ=275
        DCD     EDMA2_CH38_IRQHandler                         ;WAKEUPMIX EDMA2 channel 38 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[38] - inputs[38]) IRQ=276
        DCD     EDMA2_CH39_IRQHandler                         ;WAKEUPMIX EDMA2 channel 39 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[39] - inputs[39]) IRQ=277
        DCD     EDMA2_CH40_IRQHandler                         ;WAKEUPMIX EDMA2 channel 40 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[40] - inputs[40]) IRQ=278
        DCD     EDMA2_CH41_IRQHandler                         ;WAKEUPMIX EDMA2 channel 41 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[41] - inputs[41]) IRQ=279
        DCD     EDMA2_CH42_IRQHandler                         ;WAKEUPMIX EDMA2 channel 42 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[42] - inputs[42]) IRQ=280
        DCD     EDMA2_CH43_IRQHandler                         ;WAKEUPMIX EDMA2 channel 43 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[43] - inputs[43]) IRQ=281
        DCD     EDMA2_CH44_IRQHandler                         ;WAKEUPMIX EDMA2 channel 44 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[44] - inputs[44]) IRQ=282
        DCD     EDMA2_CH45_IRQHandler                         ;WAKEUPMIX EDMA2 channel 45 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[45] - inputs[45]) IRQ=283
        DCD     EDMA2_CH46_IRQHandler                         ;WAKEUPMIX EDMA2 channel 46 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[46] - inputs[46]) IRQ=284
        DCD     EDMA2_CH47_IRQHandler                         ;WAKEUPMIX EDMA2 channel 47 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[47] - inputs[47]) IRQ=285
        DCD     EDMA2_CH48_IRQHandler                         ;WAKEUPMIX EDMA2 channel 48 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[48] - inputs[48]) IRQ=286
        DCD     EDMA2_CH49_IRQHandler                         ;WAKEUPMIX EDMA2 channel 49 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[49] - inputs[49]) IRQ=287
        DCD     EDMA2_CH50_IRQHandler                         ;WAKEUPMIX EDMA2 channel 50 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[50] - inputs[50]) IRQ=288
        DCD     EDMA2_CH51_IRQHandler                         ;WAKEUPMIX EDMA2 channel 51 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[51] - inputs[51]) IRQ=289
        DCD     EDMA2_CH52_IRQHandler                         ;WAKEUPMIX EDMA2 channel 52 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[52] - inputs[52]) IRQ=290
        DCD     EDMA2_CH53_IRQHandler                         ;WAKEUPMIX EDMA2 channel 53 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[53] - inputs[53]) IRQ=291
        DCD     EDMA2_CH54_IRQHandler                         ;WAKEUPMIX EDMA2 channel 54 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[54] - inputs[54]) IRQ=292
        DCD     EDMA2_CH55_IRQHandler                         ;WAKEUPMIX EDMA2 channel 55 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[55] - inputs[55]) IRQ=293
        DCD     EDMA2_CH56_IRQHandler                         ;WAKEUPMIX EDMA2 channel 56 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[56] - inputs[56]) IRQ=294
        DCD     EDMA2_CH57_IRQHandler                         ;WAKEUPMIX EDMA2 channel 57 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[57] - inputs[57]) IRQ=295
        DCD     EDMA2_CH58_IRQHandler                         ;WAKEUPMIX EDMA2 channel 58 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[58] - inputs[58]) IRQ=296
        DCD     EDMA2_CH59_IRQHandler                         ;WAKEUPMIX EDMA2 channel 59 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[59] - inputs[59]) IRQ=297
        DCD     EDMA2_CH60_IRQHandler                         ;WAKEUPMIX EDMA2 channel 60 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[60] - inputs[60]) IRQ=298
        DCD     EDMA2_CH61_IRQHandler                         ;WAKEUPMIX EDMA2 channel 61 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[61] - inputs[61]) IRQ=299
        DCD     EDMA2_CH62_IRQHandler                         ;WAKEUPMIX EDMA2 channel 62 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[62] - inputs[62]) IRQ=300
        DCD     EDMA2_CH63_IRQHandler                         ;WAKEUPMIX EDMA2 channel 63 interrupt Module=EDMA2 IRQSTEERM7 extend(bitoffset[63] - inputs[63]) IRQ=301
        DCD     EDMA4_CH0_IRQHandler                          ;WAKEUPMIX EDMA4 channel 0 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[0] - inputs[64]) IRQ=302
        DCD     EDMA4_CH1_IRQHandler                          ;WAKEUPMIX EDMA4 channel 1 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[1] - inputs[65]) IRQ=303
        DCD     EDMA4_CH2_IRQHandler                          ;WAKEUPMIX EDMA4 channel 2 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[2] - inputs[66]) IRQ=304
        DCD     EDMA4_CH3_IRQHandler                          ;WAKEUPMIX EDMA4 channel 3 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[3] - inputs[67]) IRQ=305
        DCD     EDMA4_CH4_IRQHandler                          ;WAKEUPMIX EDMA4 channel 4 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[4] - inputs[68]) IRQ=306
        DCD     EDMA4_CH5_IRQHandler                          ;WAKEUPMIX EDMA4 channel 5 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[5] - inputs[69]) IRQ=307
        DCD     EDMA4_CH6_IRQHandler                          ;WAKEUPMIX EDMA4 channel 6 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[6] - inputs[70]) IRQ=308
        DCD     EDMA4_CH7_IRQHandler                          ;WAKEUPMIX EDMA4 channel 7 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[7] - inputs[71]) IRQ=309
        DCD     EDMA4_CH8_IRQHandler                          ;WAKEUPMIX EDMA4 channel 8 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[8] - inputs[72]) IRQ=310
        DCD     EDMA4_CH9_IRQHandler                          ;WAKEUPMIX EDMA4 channel 9 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[9] - inputs[73]) IRQ=311
        DCD     EDMA4_CH10_IRQHandler                         ;WAKEUPMIX EDMA4 channel 10 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[10] - inputs[74]) IRQ=312
        DCD     EDMA4_CH11_IRQHandler                         ;WAKEUPMIX EDMA4 channel 11 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[11] - inputs[75]) IRQ=313
        DCD     EDMA4_CH12_IRQHandler                         ;WAKEUPMIX EDMA4 channel 12 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[12] - inputs[76]) IRQ=314
        DCD     EDMA4_CH13_IRQHandler                         ;WAKEUPMIX EDMA4 channel 13 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[13] - inputs[77]) IRQ=315
        DCD     EDMA4_CH14_IRQHandler                         ;WAKEUPMIX EDMA4 channel 14 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[14] - inputs[78]) IRQ=316
        DCD     EDMA4_CH15_IRQHandler                         ;WAKEUPMIX EDMA4 channel 15 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[15] - inputs[79]) IRQ=317
        DCD     EDMA4_CH16_IRQHandler                         ;WAKEUPMIX EDMA4 channel 16 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[16] - inputs[80]) IRQ=318
        DCD     EDMA4_CH17_IRQHandler                         ;WAKEUPMIX EDMA4 channel 17 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[17] - inputs[81]) IRQ=319
        DCD     EDMA4_CH18_IRQHandler                         ;WAKEUPMIX EDMA4 channel 18 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[18] - inputs[82]) IRQ=320
        DCD     EDMA4_CH19_IRQHandler                         ;WAKEUPMIX EDMA4 channel 19 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[19] - inputs[83]) IRQ=321
        DCD     EDMA4_CH20_IRQHandler                         ;WAKEUPMIX EDMA4 channel 20 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[20] - inputs[84]) IRQ=322
        DCD     EDMA4_CH21_IRQHandler                         ;WAKEUPMIX EDMA4 channel 21 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[21] - inputs[85]) IRQ=323
        DCD     EDMA4_CH22_IRQHandler                         ;WAKEUPMIX EDMA4 channel 22 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[22] - inputs[86]) IRQ=324
        DCD     EDMA4_CH23_IRQHandler                         ;WAKEUPMIX EDMA4 channel 23 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[23] - inputs[87]) IRQ=325
        DCD     EDMA4_CH24_IRQHandler                         ;WAKEUPMIX EDMA4 channel 24 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[24] - inputs[88]) IRQ=326
        DCD     EDMA4_CH25_IRQHandler                         ;WAKEUPMIX EDMA4 channel 25 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[25] - inputs[89]) IRQ=327
        DCD     EDMA4_CH26_IRQHandler                         ;WAKEUPMIX EDMA4 channel 26 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[26] - inputs[90]) IRQ=328
        DCD     EDMA4_CH27_IRQHandler                         ;WAKEUPMIX EDMA4 channel 27 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[27] - inputs[91]) IRQ=329
        DCD     EDMA4_CH28_IRQHandler                         ;WAKEUPMIX EDMA4 channel 28 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[28] - inputs[92]) IRQ=330
        DCD     EDMA4_CH29_IRQHandler                         ;WAKEUPMIX EDMA4 channel 29 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[29] - inputs[93]) IRQ=331
        DCD     EDMA4_CH30_IRQHandler                         ;WAKEUPMIX EDMA4 channel 30 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[30] - inputs[94]) IRQ=332
        DCD     EDMA4_CH31_IRQHandler                         ;WAKEUPMIX EDMA4 channel 31 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[31] - inputs[95]) IRQ=333
        DCD     EDMA4_CH32_IRQHandler                         ;WAKEUPMIX EDMA4 channel 32 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[32] - inputs[96]) IRQ=334
        DCD     EDMA4_CH33_IRQHandler                         ;WAKEUPMIX EDMA4 channel 33 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[33] - inputs[97]) IRQ=335
        DCD     EDMA4_CH34_IRQHandler                         ;WAKEUPMIX EDMA4 channel 34 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[34] - inputs[98]) IRQ=336
        DCD     EDMA4_CH35_IRQHandler                         ;WAKEUPMIX EDMA4 channel 35 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[35] - inputs[99]) IRQ=337
        DCD     EDMA4_CH36_IRQHandler                         ;WAKEUPMIX EDMA4 channel 36 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[36] - inputs[100]) IRQ=338
        DCD     EDMA4_CH37_IRQHandler                         ;WAKEUPMIX EDMA4 channel 37 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[37] - inputs[101]) IRQ=339
        DCD     EDMA4_CH38_IRQHandler                         ;WAKEUPMIX EDMA4 channel 38 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[38] - inputs[102]) IRQ=340
        DCD     EDMA4_CH39_IRQHandler                         ;WAKEUPMIX EDMA4 channel 39 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[39] - inputs[103]) IRQ=341
        DCD     EDMA4_CH40_IRQHandler                         ;WAKEUPMIX EDMA4 channel 40 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[40] - inputs[104]) IRQ=342
        DCD     EDMA4_CH41_IRQHandler                         ;WAKEUPMIX EDMA4 channel 41 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[41] - inputs[105]) IRQ=343
        DCD     EDMA4_CH42_IRQHandler                         ;WAKEUPMIX EDMA4 channel 42 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[42] - inputs[106]) IRQ=344
        DCD     EDMA4_CH43_IRQHandler                         ;WAKEUPMIX EDMA4 channel 43 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[43] - inputs[107]) IRQ=345
        DCD     EDMA4_CH44_IRQHandler                         ;WAKEUPMIX EDMA4 channel 44 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[44] - inputs[108]) IRQ=346
        DCD     EDMA4_CH45_IRQHandler                         ;WAKEUPMIX EDMA4 channel 45 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[45] - inputs[109]) IRQ=347
        DCD     EDMA4_CH46_IRQHandler                         ;WAKEUPMIX EDMA4 channel 46 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[46] - inputs[110]) IRQ=348
        DCD     EDMA4_CH47_IRQHandler                         ;WAKEUPMIX EDMA4 channel 47 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[47] - inputs[111]) IRQ=349
        DCD     EDMA4_CH48_IRQHandler                         ;WAKEUPMIX EDMA4 channel 48 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[48] - inputs[112]) IRQ=350
        DCD     EDMA4_CH49_IRQHandler                         ;WAKEUPMIX EDMA4 channel 49 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[49] - inputs[113]) IRQ=351
        DCD     EDMA4_CH50_IRQHandler                         ;WAKEUPMIX EDMA4 channel 50 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[50] - inputs[114]) IRQ=352
        DCD     EDMA4_CH51_IRQHandler                         ;WAKEUPMIX EDMA4 channel 51 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[51] - inputs[115]) IRQ=353
        DCD     EDMA4_CH52_IRQHandler                         ;WAKEUPMIX EDMA4 channel 52 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[52] - inputs[116]) IRQ=354
        DCD     EDMA4_CH53_IRQHandler                         ;WAKEUPMIX EDMA4 channel 53 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[53] - inputs[117]) IRQ=355
        DCD     EDMA4_CH54_IRQHandler                         ;WAKEUPMIX EDMA4 channel 54 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[54] - inputs[118]) IRQ=356
        DCD     EDMA4_CH55_IRQHandler                         ;WAKEUPMIX EDMA4 channel 55 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[55] - inputs[119]) IRQ=357
        DCD     EDMA4_CH56_IRQHandler                         ;WAKEUPMIX EDMA4 channel 56 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[56] - inputs[120]) IRQ=358
        DCD     EDMA4_CH57_IRQHandler                         ;WAKEUPMIX EDMA4 channel 57 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[57] - inputs[121]) IRQ=359
        DCD     EDMA4_CH58_IRQHandler                         ;WAKEUPMIX EDMA4 channel 58 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[58] - inputs[122]) IRQ=360
        DCD     EDMA4_CH59_IRQHandler                         ;WAKEUPMIX EDMA4 channel 59 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[59] - inputs[123]) IRQ=361
        DCD     EDMA4_CH60_IRQHandler                         ;WAKEUPMIX EDMA4 channel 60 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[60] - inputs[124]) IRQ=362
        DCD     EDMA4_CH61_IRQHandler                         ;WAKEUPMIX EDMA4 channel 61 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[61] - inputs[125]) IRQ=363
        DCD     EDMA4_CH62_IRQHandler                         ;WAKEUPMIX EDMA4 channel 62 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[62] - inputs[126]) IRQ=364
        DCD     EDMA4_CH63_IRQHandler                         ;WAKEUPMIX EDMA4 channel 63 interrupt Module=EDMA4 IRQSTEERM7 extend(bitoffset[63] - inputs[127]) IRQ=365
        DCD     EDMA3_CH0_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 0 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[0] - inputs[128]) IRQ=366
        DCD     EDMA3_CH1_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 1 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[1] - inputs[129]) IRQ=367
        DCD     EDMA3_CH2_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 2 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[2] - inputs[130]) IRQ=368
        DCD     EDMA3_CH3_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 3 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[3] - inputs[131]) IRQ=369
        DCD     EDMA3_CH4_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 4 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[4] - inputs[132]) IRQ=370
        DCD     EDMA3_CH5_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 5 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[5] - inputs[133]) IRQ=371
        DCD     EDMA3_CH6_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 6 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[6] - inputs[134]) IRQ=372
        DCD     EDMA3_CH7_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 7 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[7] - inputs[135]) IRQ=373
        DCD     EDMA3_CH8_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 8 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[8] - inputs[136]) IRQ=374
        DCD     EDMA3_CH9_IRQHandler                          ;WAKEUPMIX ACP EDMA channel 9 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[9] - inputs[137]) IRQ=375
        DCD     EDMA3_CH10_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 10 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[10] - inputs[138]) IRQ=376
        DCD     EDMA3_CH11_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 11 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[11] - inputs[139]) IRQ=377
        DCD     EDMA3_CH12_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 12 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[12] - inputs[140]) IRQ=378
        DCD     EDMA3_CH13_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 13 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[13] - inputs[141]) IRQ=379
        DCD     EDMA3_CH14_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 14 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[14] - inputs[142]) IRQ=380
        DCD     EDMA3_CH15_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 15 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[15] - inputs[143]) IRQ=381
        DCD     EDMA3_CH16_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 16 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[16] - inputs[144]) IRQ=382
        DCD     EDMA3_CH17_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 17 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[17] - inputs[145]) IRQ=383
        DCD     EDMA3_CH18_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 18 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[18] - inputs[146]) IRQ=384
        DCD     EDMA3_CH19_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 19 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[19] - inputs[147]) IRQ=385
        DCD     EDMA3_CH20_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 20 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[20] - inputs[148]) IRQ=386
        DCD     EDMA3_CH21_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 21 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[21] - inputs[149]) IRQ=387
        DCD     EDMA3_CH22_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 22 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[22] - inputs[150]) IRQ=388
        DCD     EDMA3_CH23_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 23 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[23] - inputs[151]) IRQ=389
        DCD     EDMA3_CH24_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 24 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[24] - inputs[152]) IRQ=390
        DCD     EDMA3_CH25_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 25 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[25] - inputs[153]) IRQ=391
        DCD     EDMA3_CH26_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 26 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[26] - inputs[154]) IRQ=392
        DCD     EDMA3_CH27_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 27 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[27] - inputs[155]) IRQ=393
        DCD     EDMA3_CH28_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 28 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[28] - inputs[156]) IRQ=394
        DCD     EDMA3_CH29_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 29 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[29] - inputs[157]) IRQ=395
        DCD     EDMA3_CH30_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 30 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[30] - inputs[158]) IRQ=396
        DCD     EDMA3_CH31_IRQHandler                         ;WAKEUPMIX ACP EDMA channel 31 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[31] - inputs[159]) IRQ=397
        DCD     EDMA3_CH32_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 32 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[32] - inputs[160]) IRQ=398
        DCD     EDMA3_CH33_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 33 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[33] - inputs[161]) IRQ=399
        DCD     EDMA3_CH34_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 34 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[34] - inputs[162]) IRQ=400
        DCD     EDMA3_CH35_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 35 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[35] - inputs[163]) IRQ=401
        DCD     EDMA3_CH36_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 36 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[36] - inputs[164]) IRQ=402
        DCD     EDMA3_CH37_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 37 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[37] - inputs[165]) IRQ=403
        DCD     EDMA3_CH38_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 38 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[38] - inputs[166]) IRQ=404
        DCD     EDMA3_CH39_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 39 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[39] - inputs[167]) IRQ=405
        DCD     EDMA3_CH40_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 40 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[40] - inputs[168]) IRQ=406
        DCD     EDMA3_CH41_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 41 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[41] - inputs[169]) IRQ=407
        DCD     EDMA3_CH42_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 42 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[42] - inputs[170]) IRQ=408
        DCD     EDMA3_CH43_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 43 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[43] - inputs[171]) IRQ=409
        DCD     EDMA3_CH44_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 44 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[44] - inputs[172]) IRQ=410
        DCD     EDMA3_CH45_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 45 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[45] - inputs[173]) IRQ=411
        DCD     EDMA3_CH46_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 46 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[46] - inputs[174]) IRQ=412
        DCD     EDMA3_CH47_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 47 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[47] - inputs[175]) IRQ=413
        DCD     EDMA3_CH48_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 48 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[48] - inputs[176]) IRQ=414
        DCD     EDMA3_CH49_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 49 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[49] - inputs[177]) IRQ=415
        DCD     EDMA3_CH50_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 50 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[50] - inputs[178]) IRQ=416
        DCD     EDMA3_CH51_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 51 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[51] - inputs[179]) IRQ=417
        DCD     EDMA3_CH52_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 52 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[52] - inputs[180]) IRQ=418
        DCD     EDMA3_CH53_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 53 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[53] - inputs[181]) IRQ=419
        DCD     EDMA3_CH54_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 54 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[54] - inputs[182]) IRQ=420
        DCD     EDMA3_CH55_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 55 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[55] - inputs[183]) IRQ=421
        DCD     EDMA3_CH56_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 56 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[56] - inputs[184]) IRQ=422
        DCD     EDMA3_CH57_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 57 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[57] - inputs[185]) IRQ=423
        DCD     EDMA3_CH58_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 58 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[58] - inputs[186]) IRQ=424
        DCD     EDMA3_CH59_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 59 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[59] - inputs[187]) IRQ=425
        DCD     EDMA3_CH60_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 60 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[60] - inputs[188]) IRQ=426
        DCD     EDMA3_CH61_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 61 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[61] - inputs[189]) IRQ=427
        DCD     EDMA3_CH62_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 62 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[62] - inputs[190]) IRQ=428
        DCD     EDMA3_CH63_IRQHandler                         ; WAKEUPMIX ACP EDMA channel 63 interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[63] - inputs[191]) IRQ=429
        DCD     EDMA1_CH0_IRQHandler                          ;AONMIX EDMA channel 0 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[0] - inputs[192]) IRQ=430
        DCD     EDMA1_CH1_IRQHandler                          ;AONMIX EDMA channel 1 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[1] - inputs[193]) IRQ=431
        DCD     EDMA1_CH2_IRQHandler                          ;AONMIX EDMA channel 2 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[2] - inputs[194]) IRQ=432
        DCD     EDMA1_CH3_IRQHandler                          ;AONMIX EDMA channel 3 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[3] - inputs[195]) IRQ=433
        DCD     EDMA1_CH4_IRQHandler                          ;AONMIX EDMA channel 4 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[4] - inputs[196]) IRQ=434
        DCD     EDMA1_CH5_IRQHandler                          ;AONMIX EDMA channel 5 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[5] - inputs[197]) IRQ=435
        DCD     EDMA1_CH6_IRQHandler                          ;AONMIX EDMA channel 6 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[6] - inputs[198]) IRQ=436
        DCD     EDMA1_CH7_IRQHandler                          ;AONMIX EDMA channel 7 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[7] - inputs[199]) IRQ=437
        DCD     EDMA1_CH8_IRQHandler                          ;AONMIX EDMA channel 8 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[8] - inputs[200]) IRQ=438
        DCD     EDMA1_CH9_IRQHandler                          ;AONMIX EDMA channel 9 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[9] - inputs[201]) IRQ=439
        DCD     EDMA1_CH10_IRQHandler                         ;AONMIX EDMA channel 10 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[10] - inputs[202]) IRQ=440
        DCD     EDMA1_CH11_IRQHandler                         ;AONMIX EDMA channel 11 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[11] - inputs[203]) IRQ=441
        DCD     EDMA1_CH12_IRQHandler                         ;AONMIX EDMA channel 12 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[12] - inputs[204]) IRQ=442
        DCD     EDMA1_CH13_IRQHandler                         ;AONMIX EDMA channel 13 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[13] - inputs[205]) IRQ=443
        DCD     EDMA1_CH14_IRQHandler                         ;AONMIX EDMA channel 14 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[14] - inputs[206]) IRQ=444
        DCD     EDMA1_CH15_IRQHandler                         ;AONMIX EDMA channel 15 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[15] - inputs[207]) IRQ=445
        DCD     EDMA1_CH16_IRQHandler                         ;AONMIX EDMA channel 16 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[16] - inputs[208]) IRQ=446
        DCD     EDMA1_CH17_IRQHandler                         ;AONMIX EDMA channel 17 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[17] - inputs[209]) IRQ=447
        DCD     EDMA1_CH18_IRQHandler                         ;AONMIX EDMA channel 18 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[18] - inputs[210]) IRQ=448
        DCD     EDMA1_CH19_IRQHandler                         ;AONMIX EDMA channel 19 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[19] - inputs[211]) IRQ=449
        DCD     EDMA1_CH20_IRQHandler                         ;AONMIX EDMA channel 20 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[20] - inputs[212]) IRQ=450
        DCD     EDMA1_CH21_IRQHandler                         ;AONMIX EDMA channel 21 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[21] - inputs[213]) IRQ=451
        DCD     EDMA1_CH22_IRQHandler                         ;AONMIX EDMA channel 22 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[22] - inputs[214]) IRQ=452
        DCD     EDMA1_CH23_IRQHandler                         ;AONMIX EDMA channel 23 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[23] - inputs[215]) IRQ=453
        DCD     EDMA1_CH24_IRQHandler                         ;AONMIX EDMA channel 24 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[24] - inputs[216]) IRQ=454
        DCD     EDMA1_CH25_IRQHandler                         ;AONMIX EDMA channel 25 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[25] - inputs[217]) IRQ=455
        DCD     EDMA1_CH26_IRQHandler                         ;AONMIX EDMA channel 26 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[26] - inputs[218]) IRQ=456
        DCD     EDMA1_CH27_IRQHandler                         ;AONMIX EDMA channel 27 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[27] - inputs[219]) IRQ=457
        DCD     EDMA1_CH28_IRQHandler                         ;AONMIX EDMA channel 28 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[28] - inputs[220]) IRQ=458
        DCD     EDMA1_CH29_IRQHandler                         ;AONMIX EDMA channel 29 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[29] - inputs[221]) IRQ=459
        DCD     EDMA1_CH30_IRQHandler                         ;AONMIX EDMA channel 30 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[30] - inputs[222]) IRQ=460
        DCD     EDMA1_CH31_IRQHandler                         ;AONMIX EDMA channel 31 interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[31] - inputs[223]) IRQ=461
        DCD     Reserved478_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[224]) IRQ=462
        DCD     Reserved479_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[225]) IRQ=463
        DCD     Reserved480_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[226]) IRQ=464
        DCD     Reserved481_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[227]) IRQ=465
        DCD     Reserved482_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[228]) IRQ=466
        DCD     Reserved483_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[229]) IRQ=467
        DCD     Reserved484_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[230]) IRQ=468
        DCD     Reserved485_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[231]) IRQ=469
        DCD     Reserved486_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[232]) IRQ=470
        DCD     Reserved487_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[233]) IRQ=471
        DCD     Reserved488_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[234]) IRQ=472
        DCD     Reserved489_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[235]) IRQ=473
        DCD     Reserved490_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[236]) IRQ=474
        DCD     Reserved491_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[237]) IRQ=475
        DCD     Reserved492_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[238]) IRQ=476
        DCD     Reserved493_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[239]) IRQ=477
        DCD     Reserved494_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[240]) IRQ=478
        DCD     Reserved495_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[241]) IRQ=479
        DCD     Reserved496_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[242]) IRQ=480
        DCD     Reserved497_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[243]) IRQ=481
        DCD     Reserved498_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[244]) IRQ=482
        DCD     Reserved499_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[245]) IRQ=483
        DCD     Reserved500_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[246]) IRQ=484
        DCD     Reserved501_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[247]) IRQ=485
        DCD     Reserved502_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[248]) IRQ=486
        DCD     Reserved503_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[249]) IRQ=487
        DCD     Reserved504_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[250]) IRQ=488
        DCD     Reserved505_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[251]) IRQ=489
        DCD     Reserved506_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[252]) IRQ=490
        DCD     Reserved507_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[253]) IRQ=491
        DCD     Reserved508_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[254]) IRQ=492
        DCD     Reserved509_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[255]) IRQ=493
        DCD     MU1_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU1 IRQSTEERM7 extend(bitoffset[0] - inputs[256]) IRQ=494
        DCD     MU1_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU1 IRQSTEERM7 extend(bitoffset[1] - inputs[257]) IRQ=495
        DCD     MU2_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU2 IRQSTEERM7 extend(bitoffset[2] - inputs[258]) IRQ=496
        DCD     MU2_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU2 IRQSTEERM7 extend(bitoffset[3] - inputs[259]) IRQ=497
        DCD     MU3_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU3 IRQSTEERM7 extend(bitoffset[4] - inputs[260]) IRQ=498
        DCD     MU3_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU3 IRQSTEERM7 extend(bitoffset[5] - inputs[261]) IRQ=499
        DCD     MU4_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU4 IRQSTEERM7 extend(bitoffset[6] - inputs[262]) IRQ=500
        DCD     MU4_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU4 IRQSTEERM7 extend(bitoffset[7] - inputs[263]) IRQ=501
        DCD     MU5_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU5 IRQSTEERM7 extend(bitoffset[8] - inputs[264]) IRQ=502
        DCD     MU6_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU6 IRQSTEERM7 extend(bitoffset[9] - inputs[265]) IRQ=503
        DCD     MU7_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU7 IRQSTEERM7 extend(bitoffset[10] - inputs[266]) IRQ=504
        DCD     MU8_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU8 IRQSTEERM7 extend(bitoffset[11] - inputs[267]) IRQ=505
        DCD     MU8_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU1 IRQSTEERM7 extend(bitoffset[12] - inputs[268]) IRQ=506
        DCD     MU9_A_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU9 IRQSTEERM7 extend(bitoffset[13] - inputs[269]) IRQ=507
        DCD     MU9_B_IRQHandler                              ;AONMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU9 IRQSTEERM7 extend(bitoffset[14] - inputs[270]) IRQ=508
        DCD     MU10_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU10 IRQSTEERM7 extend(bitoffset[15] - inputs[271]) IRQ=509
        DCD     Reserved526_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[272]) IRQ=510
        DCD     Reserved527_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[273]) IRQ=511
        DCD     Reserved528_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[274]) IRQ=512
        DCD     Reserved529_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[275]) IRQ=513
        DCD     Reserved530_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[276]) IRQ=514
        DCD     Reserved531_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[277]) IRQ=515
        DCD     Reserved532_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[278]) IRQ=516
        DCD     Reserved533_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[279]) IRQ=517
        DCD     Reserved534_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[280]) IRQ=518
        DCD     Reserved535_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[281]) IRQ=519
        DCD     Reserved536_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[282]) IRQ=520
        DCD     Reserved537_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[283]) IRQ=521
        DCD     Reserved538_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[284]) IRQ=522
        DCD     Reserved539_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[285]) IRQ=523
        DCD     Reserved540_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[286]) IRQ=524
        DCD     Reserved541_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[287]) IRQ=525
        DCD     Reserved542_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[288]) IRQ=526
        DCD     Reserved543_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[289]) IRQ=527
        DCD     Reserved544_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[290]) IRQ=528
        DCD     Reserved545_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[291]) IRQ=529
        DCD     Reserved546_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[292]) IRQ=530
        DCD     Reserved547_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[293]) IRQ=531
        DCD     Reserved548_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[294]) IRQ=532
        DCD     Reserved549_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[295]) IRQ=533
        DCD     Reserved550_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[296]) IRQ=534
        DCD     Reserved551_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[297]) IRQ=535
        DCD     Reserved552_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[298]) IRQ=536
        DCD     Reserved553_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[299]) IRQ=537
        DCD     Reserved554_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[300]) IRQ=538
        DCD     Reserved555_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[301]) IRQ=539
        DCD     Reserved556_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[302]) IRQ=540
        DCD     Reserved557_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[303]) IRQ=541
        DCD     Reserved558_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[304]) IRQ=542
        DCD     Reserved559_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[305]) IRQ=543
        DCD     Reserved560_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[306]) IRQ=544
        DCD     Reserved561_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[307]) IRQ=545
        DCD     Reserved562_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[308]) IRQ=546
        DCD     Reserved563_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[309]) IRQ=547
        DCD     Reserved564_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[310]) IRQ=548
        DCD     Reserved565_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[311]) IRQ=549
        DCD     Reserved566_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[312]) IRQ=550
        DCD     Reserved567_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[313]) IRQ=551
        DCD     Reserved568_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[314]) IRQ=552
        DCD     Reserved569_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[315]) IRQ=553
        DCD     Reserved570_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[316]) IRQ=554
        DCD     Reserved571_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[317]) IRQ=555
        DCD     Reserved572_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[318]) IRQ=556
        DCD     Reserved573_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[319]) IRQ=557
        DCD     MU11_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU11 IRQSTEERM7 extend(bitoffset[0] - inputs[320]) IRQ=558
        DCD     MU12_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU12 IRQSTEERM7 extend(bitoffset[1] - inputs[321]) IRQ=559
        DCD     MU13_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU13 IRQSTEERM7 extend(bitoffset[2] - inputs[322]) IRQ=560
        DCD     MU14_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU14 IRQSTEERM7 extend(bitoffset[3] - inputs[323]) IRQ=561
        DCD     MU14_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU14 IRQSTEERM7 extend(bitoffset[4] - inputs[324]) IRQ=562
        DCD     MU15_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU15 IRQSTEERM7 extend(bitoffset[5] - inputs[325]) IRQ=563
        DCD     MU15_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU15 IRQSTEERM7 extend(bitoffset[6] - inputs[326]) IRQ=564
        DCD     MU16_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU16 IRQSTEERM7 extend(bitoffset[7] - inputs[327]) IRQ=565
        DCD     MU16_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU16 IRQSTEERM7 extend(bitoffset[8] - inputs[328]) IRQ=566
        DCD     MU17_A_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUA Module=MU17 IRQSTEERM7 extend(bitoffset[9] - inputs[329]) IRQ=567
        DCD     MU17_B_IRQHandler                             ;WAKEUPMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU17 IRQSTEERM7 extend(bitoffset[10] - inputs[330]) IRQ=568
        DCD     MU_E1_B_IRQHandler                            ;NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E1 IRQSTEERM7 extend(bitoffset[11] - inputs[331]) IRQ=569
        DCD     MU_E2_B_IRQHandler                            ;NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E2 IRQSTEERM7 extend(bitoffset[12] - inputs[332]) IRQ=570
        DCD     MU_E3_B_IRQHandler                            ;NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E3 IRQSTEERM7 extend(bitoffset[13] - inputs[333]) IRQ=571
        DCD     MU_E4_B_IRQHandler                            ;NETCMIX MU Ored of all (tx,rx,gp,core,murip) interrupt to MUB Module=MU_E4 IRQSTEERM7 extend(bitoffset[14] - inputs[334]) IRQ=572
        DCD     MSGINTR1_IRQHandler                           ;MSGINTR Instance 1, Interrupt 1, MSGINTR Instance 1, Interrupt 2, MSGINTR Instance 1, Interrupt 3 Module=MSGINTR1 IRQSTEERM7 extend(bitoffset[15] - inputs[335]) IRQ=573
        DCD     Reserved590_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[336]) IRQ=574
        DCD     Reserved591_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[337]) IRQ=575
        DCD     Reserved592_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[338]) IRQ=576
        DCD     Reserved593_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[339]) IRQ=577
        DCD     Reserved594_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[340]) IRQ=578
        DCD     Reserved595_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[341]) IRQ=579
        DCD     Reserved596_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[342]) IRQ=580
        DCD     Reserved597_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[343]) IRQ=581
        DCD     Reserved598_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[344]) IRQ=582
        DCD     Reserved599_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[345]) IRQ=583
        DCD     Reserved600_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[346]) IRQ=584
        DCD     Reserved601_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[347]) IRQ=585
        DCD     Reserved602_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[348]) IRQ=586
        DCD     Reserved603_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[349]) IRQ=587
        DCD     Reserved604_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[350]) IRQ=588
        DCD     Reserved605_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[351]) IRQ=589
        DCD     Reserved606_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[352]) IRQ=590
        DCD     Reserved607_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[353]) IRQ=591
        DCD     Reserved608_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[354]) IRQ=592
        DCD     Reserved609_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[355]) IRQ=593
        DCD     Reserved610_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[356]) IRQ=594
        DCD     Reserved611_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[357]) IRQ=595
        DCD     Reserved612_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[358]) IRQ=596
        DCD     Reserved613_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[359]) IRQ=597
        DCD     Reserved614_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[360]) IRQ=598
        DCD     Reserved615_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[361]) IRQ=599
        DCD     Reserved616_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[362]) IRQ=600
        DCD     Reserved617_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[363]) IRQ=601
        DCD     Reserved618_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[364]) IRQ=602
        DCD     Reserved619_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[365]) IRQ=603
        DCD     Reserved620_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[366]) IRQ=604
        DCD     Reserved621_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[367]) IRQ=605
        DCD     Reserved622_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[368]) IRQ=606
        DCD     Reserved623_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[369]) IRQ=607
        DCD     Reserved624_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[370]) IRQ=608
        DCD     Reserved625_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[371]) IRQ=609
        DCD     Reserved626_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[372]) IRQ=610
        DCD     Reserved627_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[373]) IRQ=611
        DCD     Reserved628_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[374]) IRQ=612
        DCD     Reserved629_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[375]) IRQ=613
        DCD     Reserved630_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[376]) IRQ=614
        DCD     Reserved631_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[377]) IRQ=615
        DCD     Reserved632_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[378]) IRQ=616
        DCD     Reserved633_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[379]) IRQ=617
        DCD     Reserved634_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[380]) IRQ=618
        DCD     Reserved635_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[381]) IRQ=619
        DCD     Reserved636_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[382]) IRQ=620
        DCD     Reserved637_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[383]) IRQ=621
        DCD     MSGINTR2_IRQHandler                           ;MSGINTR Instance 2, Interrupt 1, MSGINTR Instance 2, Interrupt 2, MSGINTR Instance 2, Interrupt 3 Module=MSGINTR2 IRQSTEERM7 extend(bitoffset[0] - inputs[384]) IRQ=622
        DCD     MSGINTR3_IRQHandler                           ;MSGINTR Instance 3, Interrupt 1, MSGINTR Instance 3, Interrupt 2, MSGINTR Instance 3, Interrupt 3 Module=MSGINTR3 IRQSTEERM7 extend(bitoffset[1] - inputs[385]) IRQ=623
        DCD     MSGINTR4_IRQHandler                           ;MSGINTR Instance 4, Interrupt 1, MSGINTR Instance 4, Interrupt 2, MSGINTR Instance 4, Interrupt 3 Module=MSGINTR4 IRQSTEERM7 extend(bitoffset[2] - inputs[386]) IRQ=624
        DCD     MSGINTR5_IRQHandler                           ;MSGINTR Instance 5, Interrupt 1, MSGINTR Instance 5, Interrupt 2, MSGINTR Instance 5, Interrupt 3 Module=MSGINTR5 IRQSTEERM7 extend(bitoffset[3] - inputs[387]) IRQ=625
        DCD     MSGINTR6_IRQHandler                           ;MSGINTR Instance 6, Interrupt 1, MSGINTR Instance 6, Interrupt 2, MSGINTR Instance 6, Interrupt 3 Module=MSGINTR6 IRQSTEERM7 extend(bitoffset[4] - inputs[388]) IRQ=626
        DCD     MSGINTR7_IRQHandler                           ;MSGINTR Instance 7, Interrupt 1, MSGINTR Instance 7, Interrupt 2, MSGINTR Instance 7, Interrupt 3 Module=MSGINTR7 IRQSTEERM7 extend(bitoffset[5] - inputs[389]) IRQ=627
        DCD     MSGINTR8_IRQHandler                           ;MSGINTR Instance 8, Interrupt 1, MSGINTR Instance 8, Interrupt 2, MSGINTR Instance 8, Interrupt 3 Module=MSGINTR8 IRQSTEERM7 extend(bitoffset[6] - inputs[390]) IRQ=628
        DCD     V2X_FH_APP1_IRQHandler                        ;V2X-FH MU APCH1 (APP1) A_TX interrupt, V2X-FH MU APCH1 (APP1) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[7] - inputs[391]) IRQ=629
        DCD     V2X_FH_HSM2_IRQHandler                        ;V2X-FH MU APHSM2 (HSM2) A_TX interrupt, V2X-FH MU APHSM2 (HSM2) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[8] - inputs[392]) IRQ=630
        DCD     S500_REQ1_IRQHandler                          ;Sentinel Group 1 reset source if no s500 reference clock is detected.  Output synchronized to 32khz clk. New signal name for i.MX943 is s4v1_fdet0_tclk_err_irq. (Cause Reset) Module=S500 IRQSTEERM7 extend(bitoffset[9] - inputs[393]) IRQ=631
        DCD     S500_REQ2_IRQHandler                          ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk the S500 clock. New signal name for i.MX943 is s4v1_fdet2_tclk_err_irq.  (Reset Request in CM33 domain) Module=S500 IRQSTEERM7 extend(bitoffset[10] - inputs[394]) IRQ=632
        DCD     S500_REQ3_IRQHandler                          ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to ref1_clk. New signal name for i.MX943 is s4v1_fdet3_tclk_err_irq Module=S500 IRQSTEERM7 extend(bitoffset[11] - inputs[395]) IRQ=633
        DCD     S500_REQ4_IRQHandler                          ;Sentinel Group 2 reset source s500 reference clock is not detected or too slow.  Output synchronized to S500 clock domain. New signal name for i.MX943 is s4v1_fdet1_tclk_err_irq Module=S500 IRQSTEERM7 extend(bitoffset[12] - inputs[396]) IRQ=634
        DCD     S500_GLUE_IRQHandler                          ;s500 glue logic IRQ Module=SENTINEL_IRQ_GLUE IRQSTEERM7 extend(bitoffset[13] - inputs[397]) IRQ=635
        DCD     GPC_SM_REQ_IRQHandler                         ;SRC/GPC Low Power Handshake Gasket interrupt request for system management Module=LP_HDSK_GSKT IRQSTEERM7 extend(bitoffset[14] - inputs[398]) IRQ=636
        DCD     EDMA1_ERROR_IRQHandler                        ;AONMIX EDMA error interrupt Module=EDMA1 IRQSTEERM7 extend(bitoffset[15] - inputs[399]) IRQ=637
        DCD     Reserved654_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[400]) IRQ=638
        DCD     Reserved655_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[401]) IRQ=639
        DCD     Reserved656_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[402]) IRQ=640
        DCD     Reserved657_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[403]) IRQ=641
        DCD     Reserved658_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[404]) IRQ=642
        DCD     Reserved659_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[405]) IRQ=643
        DCD     Reserved660_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[406]) IRQ=644
        DCD     Reserved661_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[407]) IRQ=645
        DCD     Reserved662_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[408]) IRQ=646
        DCD     Reserved663_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[409]) IRQ=647
        DCD     Reserved664_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[410]) IRQ=648
        DCD     Reserved665_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[411]) IRQ=649
        DCD     Reserved666_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[412]) IRQ=650
        DCD     Reserved667_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[413]) IRQ=651
        DCD     Reserved668_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[414]) IRQ=652
        DCD     Reserved669_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[415]) IRQ=653
        DCD     Reserved670_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[416]) IRQ=654
        DCD     Reserved671_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[417]) IRQ=655
        DCD     Reserved672_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[418]) IRQ=656
        DCD     Reserved673_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[419]) IRQ=657
        DCD     Reserved674_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[420]) IRQ=658
        DCD     Reserved675_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[421]) IRQ=659
        DCD     Reserved676_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[422]) IRQ=660
        DCD     Reserved677_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[423]) IRQ=661
        DCD     Reserved678_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[424]) IRQ=662
        DCD     Reserved679_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[425]) IRQ=663
        DCD     Reserved680_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[426]) IRQ=664
        DCD     Reserved681_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[427]) IRQ=665
        DCD     Reserved682_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[428]) IRQ=666
        DCD     Reserved683_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[429]) IRQ=667
        DCD     Reserved684_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[430]) IRQ=668
        DCD     Reserved685_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[431]) IRQ=669
        DCD     Reserved686_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[432]) IRQ=670
        DCD     Reserved687_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[433]) IRQ=671
        DCD     Reserved688_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[434]) IRQ=672
        DCD     Reserved689_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[435]) IRQ=673
        DCD     Reserved690_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[436]) IRQ=674
        DCD     Reserved691_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[437]) IRQ=675
        DCD     Reserved692_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[438]) IRQ=676
        DCD     Reserved693_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[439]) IRQ=677
        DCD     Reserved694_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[440]) IRQ=678
        DCD     Reserved695_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[441]) IRQ=679
        DCD     Reserved696_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[442]) IRQ=680
        DCD     Reserved697_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[443]) IRQ=681
        DCD     Reserved698_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[444]) IRQ=682
        DCD     Reserved699_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[445]) IRQ=683
        DCD     Reserved700_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[446]) IRQ=684
        DCD     Reserved701_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[447]) IRQ=685
        DCD     Reserved702_IRQHandler                        ;AONMIX TRDC transfer error interrupt Module=TRDC_MGR_A IRQSTEERM7 extend(bitoffset[0] - inputs[448]) IRQ=686
        DCD     Reserved703_IRQHandler                        ;WAKEUPMIX TRDC-MGR1 transfer error interrupt Module=TRDC_MGR_W1 IRQSTEERM7 extend(bitoffset[1] - inputs[449]) IRQ=687
        DCD     Reserved704_IRQHandler                        ;MEGAMIX TRDC transfer error interrupt Module=TRDC_MGR_M IRQSTEERM7 extend(bitoffset[2] - inputs[450]) IRQ=688
        DCD     Reserved705_IRQHandler                        ;NOCMIX TRDC transfer error interrupt Module=TRDC_MGR_N IRQSTEERM7 extend(bitoffset[3] - inputs[451]) IRQ=689
        DCD     Reserved706_IRQHandler                        ;DISPLAYMIX TRDC transfer error interrupt Module=TRDC_MGR_D IRQSTEERM7 extend(bitoffset[4] - inputs[452]) IRQ=690
        DCD     Reserved707_IRQHandler                        ;NETCMIX TRDC transfer error interrupt, NET_CM33_Sync Platform TRDC transfer error interrupt Module=TRDC_MGR_S IRQSTEERM7 extend(bitoffset[5] - inputs[453]) IRQ=691
        DCD     Reserved708_IRQHandler                        ;HSIOMIX TRDC transfer error interrupt Module=TRDC_MGR_H IRQSTEERM7 extend(bitoffset[6] - inputs[454]) IRQ=692
        DCD     Reserved709_IRQHandler                        ;WAKEUPMIX TRDC-MGR2 transfer error interrupt Module=TRDC_MGR_W2 IRQSTEERM7 extend(bitoffset[7] - inputs[455]) IRQ=693
        DCD     Reserved710_IRQHandler                        ;AONMIX ERM Single bit corrected ECC Error Module=ERM_A IRQSTEERM7 extend(bitoffset[8] - inputs[456]) IRQ=694
        DCD     Reserved711_IRQHandler                        ;M7MIX0 ERM Single bit corrected ECC Error Module=ERM_M7_0 IRQSTEERM7 extend(bitoffset[9] - inputs[457]) IRQ=695
        DCD     Reserved712_IRQHandler                        ;M7MIX1 ERM Single bit corrected ECC Error Module=ERM_M7_1 IRQSTEERM7 extend(bitoffset[10] - inputs[458]) IRQ=696
        DCD     Reserved713_IRQHandler                        ;WAKEUPMIX ERM Single bit corrected ECC Error Module=ERM_W IRQSTEERM7 extend(bitoffset[11] - inputs[459]) IRQ=697
        DCD     Reserved714_IRQHandler                        ;NPUMIX ERM Single bit corrected ECC Error Module=ERM_ML IRQSTEERM7 extend(bitoffset[12] - inputs[460]) IRQ=698
        DCD     Reserved715_IRQHandler                        ;NETCMIX ERM Single bit corrected ECC Error Module=ERM_NETC IRQSTEERM7 extend(bitoffset[13] - inputs[461]) IRQ=699
        DCD     Reserved716_IRQHandler                        ;OCRAM ECC multi bit error Module=OCRAM IRQSTEERM7 extend(bitoffset[14] - inputs[462]) IRQ=700
        DCD     Reserved717_IRQHandler                        ;AONMIX MTR Master error interrupt Module=MTR_MSTR IRQSTEERM7 extend(bitoffset[15] - inputs[463]) IRQ=701
        DCD     Reserved718_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[464]) IRQ=702
        DCD     Reserved719_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[465]) IRQ=703
        DCD     Reserved720_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[466]) IRQ=704
        DCD     Reserved721_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[467]) IRQ=705
        DCD     Reserved722_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[468]) IRQ=706
        DCD     Reserved723_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[469]) IRQ=707
        DCD     Reserved724_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[470]) IRQ=708
        DCD     Reserved725_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[471]) IRQ=709
        DCD     Reserved726_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[472]) IRQ=710
        DCD     Reserved727_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[473]) IRQ=711
        DCD     Reserved728_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[474]) IRQ=712
        DCD     Reserved729_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[475]) IRQ=713
        DCD     Reserved730_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[476]) IRQ=714
        DCD     Reserved731_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[477]) IRQ=715
        DCD     Reserved732_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[478]) IRQ=716
        DCD     Reserved733_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[479]) IRQ=717
        DCD     Reserved734_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[480]) IRQ=718
        DCD     Reserved735_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[481]) IRQ=719
        DCD     Reserved736_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[482]) IRQ=720
        DCD     Reserved737_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[483]) IRQ=721
        DCD     Reserved738_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[484]) IRQ=722
        DCD     Reserved739_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[485]) IRQ=723
        DCD     Reserved740_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[486]) IRQ=724
        DCD     Reserved741_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[487]) IRQ=725
        DCD     Reserved742_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[488]) IRQ=726
        DCD     Reserved743_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[489]) IRQ=727
        DCD     Reserved744_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[490]) IRQ=728
        DCD     Reserved745_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[491]) IRQ=729
        DCD     Reserved746_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[492]) IRQ=730
        DCD     Reserved747_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[493]) IRQ=731
        DCD     Reserved748_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[494]) IRQ=732
        DCD     Reserved749_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[495]) IRQ=733
        DCD     Reserved750_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[496]) IRQ=734
        DCD     Reserved751_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[497]) IRQ=735
        DCD     Reserved752_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[498]) IRQ=736
        DCD     Reserved753_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[499]) IRQ=737
        DCD     Reserved754_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[500]) IRQ=738
        DCD     Reserved755_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[501]) IRQ=739
        DCD     Reserved756_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[502]) IRQ=740
        DCD     Reserved757_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[503]) IRQ=741
        DCD     Reserved758_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[504]) IRQ=742
        DCD     Reserved759_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[505]) IRQ=743
        DCD     Reserved760_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[506]) IRQ=744
        DCD     Reserved761_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[507]) IRQ=745
        DCD     Reserved762_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[508]) IRQ=746
        DCD     Reserved763_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[509]) IRQ=747
        DCD     Reserved764_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[510]) IRQ=748
        DCD     Reserved765_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[511]) IRQ=749
        DCD     Reserved766_IRQHandler                        ;EDMA3 DMA error interrupt Module=EDMA3 IRQSTEERM7 extend(bitoffset[0] - inputs[512]) IRQ=750
        DCD     Reserved767_IRQHandler                        ;AONMIX M33 PS Tag Parity Error, AONMIX M33 PS Data Parity Error Module=CM33 IRQSTEERM7 extend(bitoffset[1] - inputs[513]) IRQ=751
        DCD     Reserved768_IRQHandler                        ;AONMIX M33 TCM Error interrupt Module=CM33_ECC_MCM IRQSTEERM7 extend(bitoffset[2] - inputs[514]) IRQ=752
        DCD     Reserved769_IRQHandler                        ;M7MIX ECC Multi-bit error Module=ERM_M7_0 IRQSTEERM7 extend(bitoffset[3] - inputs[515]) IRQ=753
        DCD     Reserved770_IRQHandler                        ;NETCMIX M33 PS Tag Parity Error, NETCMIX M33 PS Data Parity Error Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[4] - inputs[516]) IRQ=754
        DCD     Reserved771_IRQHandler                        ;NETCMIX M33 TCM Error interrupt Module=CM33_SYNC_ECC_MCM IRQSTEERM7 extend(bitoffset[5] - inputs[517]) IRQ=755
        DCD     Reserved772_IRQHandler                        ;NETCMIX 1.5MB OCSRAM  Error interrupt Module=NETCMIX_ECC_MCM IRQSTEERM7 extend(bitoffset[6] - inputs[518]) IRQ=756
        DCD     Reserved773_IRQHandler                        ;M7MIX1 ECC Multi-bit error Module=ERM_M7_1 IRQSTEERM7 extend(bitoffset[7] - inputs[519]) IRQ=757
        DCD     Reserved774_IRQHandler                        ;GIC700 Fault (Uncorrectable ECC errors) Module=GIC700 IRQSTEERM7 extend(bitoffset[8] - inputs[520]) IRQ=758
        DCD     Reserved775_IRQHandler                        ;CM33 MCM interrupt Module=CM33 IRQSTEERM7 extend(bitoffset[9] - inputs[521]) IRQ=759
        DCD     Reserved776_IRQHandler                        ;CM33_sync MCM interrupt Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[10] - inputs[522]) IRQ=760
        DCD     Reserved777_IRQHandler                        ;NETCMIX 1.5 MB SRAM  MCM interrupt Module=NETCMIX IRQSTEERM7 extend(bitoffset[11] - inputs[523]) IRQ=761
        DCD     Reserved778_IRQHandler                        ;M7MIX0 MCM interrupt Module=M7MIX0 IRQSTEERM7 extend(bitoffset[12] - inputs[524]) IRQ=762
        DCD     Reserved779_IRQHandler                        ;M7MIX1 MCM interrupt Module=M7MIX1 IRQSTEERM7 extend(bitoffset[13] - inputs[525]) IRQ=763
        DCD     Reserved780_IRQHandler                        ;OCRAM ECC single bit error Module=OCRAM IRQSTEERM7 extend(bitoffset[14] - inputs[526]) IRQ=764
        DCD     Reserved781_IRQHandler                        ;GIC700 Error (Correctable ECC errors) Module=GIC700 IRQSTEERM7 extend(bitoffset[15] - inputs[527]) IRQ=765
        DCD     Reserved782_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[528]) IRQ=766
        DCD     Reserved783_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[529]) IRQ=767
        DCD     Reserved784_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[530]) IRQ=768
        DCD     Reserved785_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[531]) IRQ=769
        DCD     Reserved786_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[532]) IRQ=770
        DCD     Reserved787_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[533]) IRQ=771
        DCD     Reserved788_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[534]) IRQ=772
        DCD     Reserved789_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[535]) IRQ=773
        DCD     Reserved790_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[536]) IRQ=774
        DCD     Reserved791_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[537]) IRQ=775
        DCD     Reserved792_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[538]) IRQ=776
        DCD     Reserved793_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[539]) IRQ=777
        DCD     Reserved794_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[540]) IRQ=778
        DCD     Reserved795_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[541]) IRQ=779
        DCD     Reserved796_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[542]) IRQ=780
        DCD     Reserved797_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[543]) IRQ=781
        DCD     Reserved798_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[544]) IRQ=782
        DCD     Reserved799_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[545]) IRQ=783
        DCD     Reserved800_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[546]) IRQ=784
        DCD     Reserved801_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[547]) IRQ=785
        DCD     Reserved802_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[548]) IRQ=786
        DCD     Reserved803_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[549]) IRQ=787
        DCD     Reserved804_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[550]) IRQ=788
        DCD     Reserved805_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[551]) IRQ=789
        DCD     Reserved806_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[552]) IRQ=790
        DCD     Reserved807_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[553]) IRQ=791
        DCD     Reserved808_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[554]) IRQ=792
        DCD     Reserved809_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[555]) IRQ=793
        DCD     Reserved810_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[556]) IRQ=794
        DCD     Reserved811_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[557]) IRQ=795
        DCD     Reserved812_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[558]) IRQ=796
        DCD     Reserved813_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[559]) IRQ=797
        DCD     Reserved814_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[560]) IRQ=798
        DCD     Reserved815_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[561]) IRQ=799
        DCD     Reserved816_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[562]) IRQ=800
        DCD     Reserved817_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[563]) IRQ=801
        DCD     Reserved818_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[564]) IRQ=802
        DCD     Reserved819_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[565]) IRQ=803
        DCD     Reserved820_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[566]) IRQ=804
        DCD     Reserved821_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[567]) IRQ=805
        DCD     Reserved822_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[568]) IRQ=806
        DCD     Reserved823_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[569]) IRQ=807
        DCD     Reserved824_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[570]) IRQ=808
        DCD     Reserved825_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[571]) IRQ=809
        DCD     Reserved826_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[572]) IRQ=810
        DCD     Reserved827_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[573]) IRQ=811
        DCD     Reserved828_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[574]) IRQ=812
        DCD     Reserved829_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[575]) IRQ=813
        DCD     Reserved830_IRQHandler                        ;ANAMIX SFA(Signal Frequency Analyzer) interrupt Module=ANAMIX IRQSTEERM7 extend(bitoffset[0] - inputs[576]) IRQ=814
        DCD     TMPSNS_THR1_IRQHandler                        ;ANAMIX TempSensor non-secure interrupt from Threshold 1 Module=ANAMIX IRQSTEERM7 extend(bitoffset[1] - inputs[577]) IRQ=815
        DCD     TMPSNS_THR2_IRQHandler                        ;ANAMIX TempSensor non-secure interrupt from Threshold 2 Module=ANAMIX IRQSTEERM7 extend(bitoffset[2] - inputs[578]) IRQ=816
        DCD     Reserved833_IRQHandler                        ;ANAMIX TempSensor non-secure data ready interrupt Module=ANAMIX IRQSTEERM7 extend(bitoffset[3] - inputs[579]) IRQ=817
        DCD     Reserved834_IRQHandler                        ;CORTEXAMIX TempSensor non-secure interrupt from Threshold 1 Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[4] - inputs[580]) IRQ=818
        DCD     Reserved835_IRQHandler                        ;CORTEXAMIX TempSensor non-secure interrupt from Threshold 2 Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[5] - inputs[581]) IRQ=819
        DCD     Reserved836_IRQHandler                        ;CORTEXAMIX TempSensor non-secure data ready interrupt Module=CORTEXAMIX IRQSTEERM7 extend(bitoffset[6] - inputs[582]) IRQ=820
        DCD     CM33_0_SYSRESETREQ_IRQHandler                 ;AONMIX CM33 SYSREQRST SRC reset source Module=CM33 IRQSTEERM7 extend(bitoffset[7] - inputs[583]) IRQ=821
        DCD     CM33_0_LOCKUP_IRQHandler                      ;AONMIX CM33 LOCKUP SRC reset source Module=CM33 IRQSTEERM7 extend(bitoffset[8] - inputs[584]) IRQ=822
        DCD     CM7_0_SYSRESETREQ_IRQHandler                  ;CM7_0 SYSREQRST SRC reset source Module=CM7_0 IRQSTEERM7 extend(bitoffset[9] - inputs[585]) IRQ=823
        DCD     CM7_0_LOCKUP_IRQHandler                       ;CM7_0 LOCKUP SRC reset source Module=CM7_0 IRQSTEERM7 extend(bitoffset[10] - inputs[586]) IRQ=824
        DCD     CM33_1_SYSRESETREQ_IRQHandler                 ;NETCMIX CM33_sync SYSREQRST SRC reset source Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[11] - inputs[587]) IRQ=825
        DCD     CM33_1_LOCKUP_IRQHandler                      ;NETCMIX CM33_sync LOCKUP SRC reset source Module=CM33_SYNC IRQSTEERM7 extend(bitoffset[12] - inputs[588]) IRQ=826
        DCD     CM7_1_SYSRESETREQ_IRQHandler                  ;CM7_1 SYSREQRST SRC reset source Module=CM7_1 IRQSTEERM7 extend(bitoffset[13] - inputs[589]) IRQ=827
        DCD     CM7_1_LOCKUP_IRQHandler                       ;CM7_1 LOCKUP SRC reset source Module=CM7_1 IRQSTEERM7 extend(bitoffset[14] - inputs[590]) IRQ=828
        DCD     Reserved845_IRQHandler                        ;soc_reset_wo_netc_int Module=NETC_PLAT IRQSTEERM7 extend(bitoffset[15] - inputs[591]) IRQ=829
        DCD     Reserved846_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[592]) IRQ=830
        DCD     Reserved847_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[593]) IRQ=831
        DCD     Reserved848_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[594]) IRQ=832
        DCD     Reserved849_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[595]) IRQ=833
        DCD     Reserved850_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[596]) IRQ=834
        DCD     Reserved851_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[597]) IRQ=835
        DCD     Reserved852_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[598]) IRQ=836
        DCD     Reserved853_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[599]) IRQ=837
        DCD     Reserved854_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[600]) IRQ=838
        DCD     Reserved855_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[601]) IRQ=839
        DCD     Reserved856_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[602]) IRQ=840
        DCD     Reserved857_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[603]) IRQ=841
        DCD     Reserved858_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[604]) IRQ=842
        DCD     Reserved859_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[605]) IRQ=843
        DCD     Reserved860_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[606]) IRQ=844
        DCD     Reserved861_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[607]) IRQ=845
        DCD     Reserved862_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[608]) IRQ=846
        DCD     Reserved863_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[609]) IRQ=847
        DCD     Reserved864_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[610]) IRQ=848
        DCD     Reserved865_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[611]) IRQ=849
        DCD     Reserved866_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[612]) IRQ=850
        DCD     Reserved867_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[613]) IRQ=851
        DCD     Reserved868_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[614]) IRQ=852
        DCD     Reserved869_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[615]) IRQ=853
        DCD     Reserved870_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[616]) IRQ=854
        DCD     Reserved871_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[617]) IRQ=855
        DCD     Reserved872_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[618]) IRQ=856
        DCD     Reserved873_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[619]) IRQ=857
        DCD     Reserved874_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[620]) IRQ=858
        DCD     Reserved875_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[621]) IRQ=859
        DCD     Reserved876_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[622]) IRQ=860
        DCD     Reserved877_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[623]) IRQ=861
        DCD     Reserved878_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[624]) IRQ=862
        DCD     Reserved879_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[625]) IRQ=863
        DCD     Reserved880_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[626]) IRQ=864
        DCD     Reserved881_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[627]) IRQ=865
        DCD     Reserved882_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[628]) IRQ=866
        DCD     Reserved883_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[629]) IRQ=867
        DCD     Reserved884_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[630]) IRQ=868
        DCD     Reserved885_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[631]) IRQ=869
        DCD     Reserved886_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[632]) IRQ=870
        DCD     Reserved887_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[633]) IRQ=871
        DCD     Reserved888_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[634]) IRQ=872
        DCD     Reserved889_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[635]) IRQ=873
        DCD     Reserved890_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[636]) IRQ=874
        DCD     Reserved891_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[637]) IRQ=875
        DCD     Reserved892_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[638]) IRQ=876
        DCD     Reserved893_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[639]) IRQ=877
        DCD     Reserved894_IRQHandler                        ;NETC iEPRC PCI INT (one per each of two RC-EC) Module=NETC IRQSTEERM7 extend(bitoffset[0] - inputs[640]) IRQ=878
        DCD     Reserved895_IRQHandler                        ;NETC iEPRC PCI INT (one per each of two RC-EC) Module=NETC IRQSTEERM7 extend(bitoffset[1] - inputs[641]) IRQ=879
        DCD     Reserved896_IRQHandler                        ;PCIe Controller 1 INTA Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[2] - inputs[642]) IRQ=880
        DCD     Reserved897_IRQHandler                        ;PCIe Controller 1 INTB Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[3] - inputs[643]) IRQ=881
        DCD     Reserved898_IRQHandler                        ;PCIe Controller 1 INTC Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[4] - inputs[644]) IRQ=882
        DCD     Reserved899_IRQHandler                        ;PCIe Controller 1 INTD Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[5] - inputs[645]) IRQ=883
        DCD     Reserved900_IRQHandler                        ;PCIe miscellaneous interrupts, PCIe MSI reception interrupt for RC mode, PCIe Link reset request interrupt Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[6] - inputs[646]) IRQ=884
        DCD     Reserved901_IRQHandler                        ;PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt Module=PCIE_CTRL1 IRQSTEERM7 extend(bitoffset[7] - inputs[647]) IRQ=885
        DCD     Reserved902_IRQHandler                        ;PCIe Controller 1 INTA Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[8] - inputs[648]) IRQ=886
        DCD     Reserved903_IRQHandler                        ;PCIe Controller 1 INTB Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[9] - inputs[649]) IRQ=887
        DCD     Reserved904_IRQHandler                        ;PCIe Controller 1 INTC Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[10] - inputs[650]) IRQ=888
        DCD     Reserved905_IRQHandler                        ;PCIe Controller 1 INTD Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[11] - inputs[651]) IRQ=889
        DCD     Reserved906_IRQHandler                        ;PCIe miscellaneous interrupts, PCIe MSI reception interrupt for RC mode, PCIe Link reset request interrupt Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[12] - inputs[652]) IRQ=890
        DCD     Reserved907_IRQHandler                        ;PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt, PCIe Controller EDMA channel interrupt Module=PCIE_CTRL2 IRQSTEERM7 extend(bitoffset[13] - inputs[653]) IRQ=891
        DCD     Reserved908_IRQHandler                        ;Wakeup interrupt from CLKREQ#, WAKEUP#, BEACON_DET Module=NPU IRQSTEERM7 extend(bitoffset[14] - inputs[654]) IRQ=892
        DCD     Reserved909_IRQHandler                        ;NPUMIX Functional interrupt Module=NPU IRQSTEERM7 extend(bitoffset[15] - inputs[655]) IRQ=893
        DCD     Reserved910_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[656]) IRQ=894
        DCD     Reserved911_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[657]) IRQ=895
        DCD     Reserved912_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[658]) IRQ=896
        DCD     Reserved913_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[659]) IRQ=897
        DCD     Reserved914_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[660]) IRQ=898
        DCD     Reserved915_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[661]) IRQ=899
        DCD     Reserved916_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[662]) IRQ=900
        DCD     Reserved917_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[663]) IRQ=901
        DCD     Reserved918_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[664]) IRQ=902
        DCD     Reserved919_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[665]) IRQ=903
        DCD     Reserved920_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[666]) IRQ=904
        DCD     Reserved921_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[667]) IRQ=905
        DCD     Reserved922_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[668]) IRQ=906
        DCD     Reserved923_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[669]) IRQ=907
        DCD     Reserved924_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[670]) IRQ=908
        DCD     Reserved925_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[671]) IRQ=909
        DCD     Reserved926_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[672]) IRQ=910
        DCD     Reserved927_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[673]) IRQ=911
        DCD     Reserved928_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[674]) IRQ=912
        DCD     Reserved929_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[675]) IRQ=913
        DCD     Reserved930_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[676]) IRQ=914
        DCD     Reserved931_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[677]) IRQ=915
        DCD     Reserved932_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[678]) IRQ=916
        DCD     Reserved933_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[679]) IRQ=917
        DCD     Reserved934_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[680]) IRQ=918
        DCD     Reserved935_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[681]) IRQ=919
        DCD     Reserved936_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[682]) IRQ=920
        DCD     Reserved937_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[683]) IRQ=921
        DCD     Reserved938_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[684]) IRQ=922
        DCD     Reserved939_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[685]) IRQ=923
        DCD     Reserved940_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[686]) IRQ=924
        DCD     Reserved941_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[687]) IRQ=925
        DCD     Reserved942_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[688]) IRQ=926
        DCD     Reserved943_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[689]) IRQ=927
        DCD     Reserved944_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[690]) IRQ=928
        DCD     Reserved945_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[691]) IRQ=929
        DCD     Reserved946_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[692]) IRQ=930
        DCD     Reserved947_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[693]) IRQ=931
        DCD     Reserved948_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[694]) IRQ=932
        DCD     Reserved949_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[695]) IRQ=933
        DCD     Reserved950_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[696]) IRQ=934
        DCD     Reserved951_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[697]) IRQ=935
        DCD     Reserved952_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[698]) IRQ=936
        DCD     Reserved953_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[699]) IRQ=937
        DCD     Reserved954_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[700]) IRQ=938
        DCD     Reserved955_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[701]) IRQ=939
        DCD     Reserved956_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[702]) IRQ=940
        DCD     Reserved957_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[703]) IRQ=941
        DCD     Reserved958_IRQHandler                        ;DRAM controller Performance Monitor Interrupt Module=DDR_TOP IRQSTEERM7 extend(bitoffset[0] - inputs[704]) IRQ=942
        DCD     Reserved959_IRQHandler                        ;DRAM controller Critical Interrupt Module=DDR_TOP IRQSTEERM7 extend(bitoffset[1] - inputs[705]) IRQ=943
        DCD     Reserved960_IRQHandler                        ;DRAM Phy Critical Interrupt 0, DRAM Phy Critical Interrupt 1, DRAM Phy Critical Interrupt 2, DRAM Phy Critical Interrupt 3, DRAM Phy Critical Interrupt 4, DRAM Phy Critical Interrupt 5, DRAM Phy Critical Interrupt 6, DRAM Phy Critical Interrupt 7, DRAM Phy Critical Interrupt 8, DRAM Phy Critical Interrupt 9, DRAM Phy Critical Interrupt 10, DRAM Phy Critical Interrupt 11, DRAM Phy Critical Interrupt 12, DRAM Phy Critical Interrupt 13, DRAM Phy Critical Interrupt 14, DRAM Phy Critical Interrupt 15 Module=DDR_TOP IRQSTEERM7 extend(bitoffset[2] - inputs[706]) IRQ=944
        DCD     DCIF_CPU_DOMAIN0_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain0 (Controlled by common registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[3] - inputs[707]) IRQ=945
        DCD     DCIF_CPU_DOMAIN1_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain1 (Controlled by background layer registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[4] - inputs[708]) IRQ=946
        DCD     DCIF_CPU_DOMAIN2_IRQHandler                   ;DISPLAYMIX DCIF: Interrupt output for CPU domain2 (Controlled by foreground layer registers group) Module=DCIF1 IRQSTEERM7 extend(bitoffset[5] - inputs[709]) IRQ=947
        DCD     Reserved964_IRQHandler                        ;Reserved for DCIF/PXP, IP is under development Module=NAN IRQSTEERM7 extend(bitoffset[6] - inputs[710]) IRQ=948
        DCD     Reserved965_IRQHandler                        ;Reserved for DCIF/PXP, IP is under development Module=NAN IRQSTEERM7 extend(bitoffset[7] - inputs[711]) IRQ=949
        DCD     PXP_0_IRQHandler                              ;DISPLAYMIX PXP Module=PXP IRQSTEERM7 extend(bitoffset[8] - inputs[712]) IRQ=950
        DCD     PXP_1_IRQHandler                              ;DISPLAYMIX PXP Module=PXP IRQSTEERM7 extend(bitoffset[9] - inputs[713]) IRQ=951
        DCD     Reserved968_IRQHandler                        ;V2X-FH MU APSHE (SHE) A_TX interrupt, V2X-FH MU APSHE (SHE) A_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[10] - inputs[714]) IRQ=952
        DCD     Reserved969_IRQHandler                        ;V2X-FH MU SCU/APDEBUG (DEBUG) B_TX interrupt, V2X-FH MU SCU/APDEBUG (DEBUG) B_RX interrupt Module=V2X_FH IRQSTEERM7 extend(bitoffset[11] - inputs[715]) IRQ=953
        DCD     Reserved970_IRQHandler                        ;USB-1 (USB 3.0) Wake-up Interrupt Module=USB1 IRQSTEERM7 extend(bitoffset[12] - inputs[716]) IRQ=954
        DCD     Reserved971_IRQHandler                        ;USB-2 (USB 2.0) Wake-up Interrupt Module=USB2 IRQSTEERM7 extend(bitoffset[13] - inputs[717]) IRQ=955
        DCD     Reserved972_IRQHandler                        ;GIC700 PMU Counter Overflow Module=GIC700 IRQSTEERM7 extend(bitoffset[14] - inputs[718]) IRQ=956
        DCD     Reserved973_IRQHandler                        ;cdbgpwrupreq_irq Module=INTG_BOOTROM_DEBUG_CTRL IRQSTEERM7 extend(bitoffset[15] - inputs[719]) IRQ=957
        DCD     Reserved974_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[720]) IRQ=958
        DCD     Reserved975_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[721]) IRQ=959
        DCD     Reserved976_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[722]) IRQ=960
        DCD     Reserved977_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[723]) IRQ=961
        DCD     Reserved978_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[724]) IRQ=962
        DCD     Reserved979_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[725]) IRQ=963
        DCD     Reserved980_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[726]) IRQ=964
        DCD     Reserved981_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[727]) IRQ=965
        DCD     Reserved982_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[728]) IRQ=966
        DCD     Reserved983_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[729]) IRQ=967
        DCD     Reserved984_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[730]) IRQ=968
        DCD     Reserved985_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[731]) IRQ=969
        DCD     Reserved986_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[732]) IRQ=970
        DCD     Reserved987_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[733]) IRQ=971
        DCD     Reserved988_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[734]) IRQ=972
        DCD     Reserved989_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[735]) IRQ=973
        DCD     Reserved990_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[736]) IRQ=974
        DCD     Reserved991_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[737]) IRQ=975
        DCD     Reserved992_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[738]) IRQ=976
        DCD     Reserved993_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[739]) IRQ=977
        DCD     Reserved994_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[740]) IRQ=978
        DCD     Reserved995_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[741]) IRQ=979
        DCD     Reserved996_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[742]) IRQ=980
        DCD     Reserved997_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[743]) IRQ=981
        DCD     Reserved998_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[744]) IRQ=982
        DCD     Reserved999_IRQHandler                        ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[745]) IRQ=983
        DCD     Reserved1000_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[746]) IRQ=984
        DCD     Reserved1001_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[747]) IRQ=985
        DCD     Reserved1002_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[748]) IRQ=986
        DCD     Reserved1003_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[749]) IRQ=987
        DCD     Reserved1004_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[750]) IRQ=988
        DCD     Reserved1005_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[751]) IRQ=989
        DCD     Reserved1006_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[752]) IRQ=990
        DCD     Reserved1007_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[753]) IRQ=991
        DCD     Reserved1008_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[754]) IRQ=992
        DCD     Reserved1009_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[755]) IRQ=993
        DCD     Reserved1010_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[756]) IRQ=994
        DCD     Reserved1011_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[757]) IRQ=995
        DCD     Reserved1012_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[758]) IRQ=996
        DCD     Reserved1013_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[759]) IRQ=997
        DCD     Reserved1014_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[760]) IRQ=998
        DCD     Reserved1015_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[761]) IRQ=999
        DCD     Reserved1016_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[762]) IRQ=1000
        DCD     Reserved1017_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[763]) IRQ=1001
        DCD     Reserved1018_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[764]) IRQ=1002
        DCD     Reserved1019_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[765]) IRQ=1003
        DCD     Reserved1020_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[766]) IRQ=1004
        DCD     Reserved1021_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[767]) IRQ=1005
        DCD     XSPI1_IRQHandler                              ;xspi1 all interrupts ORed output for EENV0 (MEENV), xspi1 arbitration lock timeout interrupt for EENV0, xspi1 arbitration win interrupt for EENV0, xspi1 FlashA error interrupt for EENV0 Module=XSPI1 IRQSTEERM7 extend(bitoffset[0] - inputs[768]) IRQ=1006
        DCD     Reserved1023_IRQHandler                       ;xspi1 all interrupts ORed output for EENV1 (MEENV), xspi1 arbitration lock timeout interrupt for EENV1, xspi1 arbitration win interrupt for EENV1, xspi1 FlashA error interrupt for EENV1 Module=XSPI1 IRQSTEERM7 extend(bitoffset[1] - inputs[769]) IRQ=1007
        DCD     Reserved1024_IRQHandler                       ;xspi1 all interrupts ORed output for EENV2 (MEENV), xspi1 arbitration lock timeout interrupt for EENV2, xspi1 arbitration win interrupt for EENV2, xspi1 FlashA error interrupt for EENV2 Module=XSPI1 IRQSTEERM7 extend(bitoffset[2] - inputs[770]) IRQ=1008
        DCD     Reserved1025_IRQHandler                       ;xspi1 all interrupts ORed output for EENV3 (MEENV), xspi1 arbitration lock timeout interrupt for EENV3, xspi1 arbitration win interrupt for EENV3, xspi1 FlashA error interrupt for EENV3 Module=XSPI1 IRQSTEERM7 extend(bitoffset[3] - inputs[771]) IRQ=1009
        DCD     Reserved1026_IRQHandler                       ;xspi1 all interrupts ORed output for EENV4 (MEENV), xspi1 arbitration lock timeout interrupt for EENV4, xspi1 arbitration win interrupt for EENV4, xspi1 FlashA error interrupt for EENV4 Module=XSPI1 IRQSTEERM7 extend(bitoffset[4] - inputs[772]) IRQ=1010
        DCD     XSPI2_IRQHandler                              ;xspi2 all interrupts ORed output for EENV0 (MEENV), xspi2 arbitration lock timeout interrupt for EENV0, xspi2 arbitration win interrupt for EENV0, xspi2 FlashA error interrupt for EENV0 Module=XSPI2 IRQSTEERM7 extend(bitoffset[5] - inputs[773]) IRQ=1011
        DCD     Reserved1028_IRQHandler                       ;xspi2 all interrupts ORed output for EENV1 (MEENV), xspi2 arbitration lock timeout interrupt for EENV1, xspi2 arbitration win interrupt for EENV1, xspi2 FlashA error interrupt for EENV1 Module=XSPI2 IRQSTEERM7 extend(bitoffset[6] - inputs[774]) IRQ=1012
        DCD     Reserved1029_IRQHandler                       ;xspi2 all interrupts ORed output for EENV2 (MEENV), xspi2 arbitration lock timeout interrupt for EENV2, xspi2 arbitration win interrupt for EENV2, xspi2 FlashA error interrupt for EENV2 Module=XSPI2 IRQSTEERM7 extend(bitoffset[7] - inputs[775]) IRQ=1013
        DCD     Reserved1030_IRQHandler                       ;xspi2 all interrupts ORed output for EENV3 (MEENV), xspi2 arbitration lock timeout interrupt for EENV3, xspi2 arbitration win interrupt for EENV3, xspi2 FlashA error interrupt for EENV3 Module=XSPI2 IRQSTEERM7 extend(bitoffset[8] - inputs[776]) IRQ=1014
        DCD     Reserved1031_IRQHandler                       ;xspi2 all interrupts ORed output for EENV4 (MEENV), xspi2 arbitration lock timeout interrupt for EENV4, xspi2 arbitration win interrupt for EENV4, xspi2 FlashA error interrupt for EENV4 Module=XSPI2 IRQSTEERM7 extend(bitoffset[9] - inputs[777]) IRQ=1015
        DCD     Reserved1032_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[10] - inputs[778]) IRQ=1016
        DCD     Reserved1033_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[11] - inputs[779]) IRQ=1017
        DCD     Reserved1034_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[12] - inputs[780]) IRQ=1018
        DCD     Reserved1035_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[13] - inputs[781]) IRQ=1019
        DCD     Reserved1036_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[14] - inputs[782]) IRQ=1020
        DCD     Reserved1037_IRQHandler                       ;Reserved Module=NAN IRQSTEERM7 extend(bitoffset[15] - inputs[783]) IRQ=1021
        DCD     Reserved1038_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[16] - inputs[784]) IRQ=1022
        DCD     Reserved1039_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[17] - inputs[785]) IRQ=1023
        DCD     Reserved1040_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[18] - inputs[786]) IRQ=1024
        DCD     Reserved1041_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[19] - inputs[787]) IRQ=1025
        DCD     Reserved1042_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[20] - inputs[788]) IRQ=1026
        DCD     Reserved1043_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[21] - inputs[789]) IRQ=1027
        DCD     Reserved1044_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[22] - inputs[790]) IRQ=1028
        DCD     Reserved1045_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[23] - inputs[791]) IRQ=1029
        DCD     Reserved1046_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[24] - inputs[792]) IRQ=1030
        DCD     Reserved1047_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[25] - inputs[793]) IRQ=1031
        DCD     Reserved1048_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[26] - inputs[794]) IRQ=1032
        DCD     Reserved1049_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[27] - inputs[795]) IRQ=1033
        DCD     Reserved1050_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[28] - inputs[796]) IRQ=1034
        DCD     Reserved1051_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[29] - inputs[797]) IRQ=1035
        DCD     Reserved1052_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[30] - inputs[798]) IRQ=1036
        DCD     Reserved1053_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[31] - inputs[799]) IRQ=1037
        DCD     Reserved1054_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[32] - inputs[800]) IRQ=1038
        DCD     Reserved1055_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[33] - inputs[801]) IRQ=1039
        DCD     Reserved1056_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[34] - inputs[802]) IRQ=1040
        DCD     Reserved1057_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[35] - inputs[803]) IRQ=1041
        DCD     Reserved1058_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[36] - inputs[804]) IRQ=1042
        DCD     Reserved1059_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[37] - inputs[805]) IRQ=1043
        DCD     Reserved1060_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[38] - inputs[806]) IRQ=1044
        DCD     Reserved1061_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[39] - inputs[807]) IRQ=1045
        DCD     Reserved1062_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[40] - inputs[808]) IRQ=1046
        DCD     Reserved1063_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[41] - inputs[809]) IRQ=1047
        DCD     Reserved1064_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[42] - inputs[810]) IRQ=1048
        DCD     Reserved1065_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[43] - inputs[811]) IRQ=1049
        DCD     Reserved1066_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[44] - inputs[812]) IRQ=1050
        DCD     Reserved1067_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[45] - inputs[813]) IRQ=1051
        DCD     Reserved1068_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[46] - inputs[814]) IRQ=1052
        DCD     Reserved1069_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[47] - inputs[815]) IRQ=1053
        DCD     Reserved1070_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[48] - inputs[816]) IRQ=1054
        DCD     Reserved1071_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[49] - inputs[817]) IRQ=1055
        DCD     Reserved1072_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[50] - inputs[818]) IRQ=1056
        DCD     Reserved1073_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[51] - inputs[819]) IRQ=1057
        DCD     Reserved1074_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[52] - inputs[820]) IRQ=1058
        DCD     Reserved1075_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[53] - inputs[821]) IRQ=1059
        DCD     Reserved1076_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[54] - inputs[822]) IRQ=1060
        DCD     Reserved1077_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[55] - inputs[823]) IRQ=1061
        DCD     Reserved1078_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[56] - inputs[824]) IRQ=1062
        DCD     Reserved1079_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[57] - inputs[825]) IRQ=1063
        DCD     Reserved1080_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[58] - inputs[826]) IRQ=1064
        DCD     Reserved1081_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[59] - inputs[827]) IRQ=1065
        DCD     Reserved1082_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[60] - inputs[828]) IRQ=1066
        DCD     Reserved1083_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[61] - inputs[829]) IRQ=1067
        DCD     Reserved1084_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[62] - inputs[830]) IRQ=1068
        DCD     Reserved1085_IRQHandler                       ;Reserved interrupt Module=Reserved IRQSTEERM7 extend(bitoffset[63] - inputs[831]) IRQ=1069
        DCD     0xFFFFFFFF                                    ; Reserved for user TRIM value
__Vectors_End

__Vectors       EQU   __vector_table
__Vectors_Size  EQU   __Vectors_End - __Vectors


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        CPSID   I               ; Mask interrupts
        LDR     R0, =0xE000ED08
        LDR     R1, =__vector_table
        STR     R1, [R0]
        LDR     R2, [R1]
        MSR     MSP, R2

        ;
        ; Add RW / stack / heap / quick code / quick data initializaiton
        ; TCM controller must perform a read-modify-write for any access < 32-bit to keep the ECC updated.
        ; The Software must ensure the TCM is ECC clean by initializing all memories that have the potential to be accessed as < 32-bit.

        MOV    R0, #0
        LDR    R1, =SFB(RW)
        LDR    R2, =SFE(RW)
.rw_init:
        CMP    R1, R2
        ITT    LT
        STRLT  R0, [R1], #4
        BLT    .rw_init

        MOV    R0, #0
        LDR    R1, =SFB(HEAP)
        LDR    R2, =SFE(HEAP)
.heap_init:
        CMP    R1, R2
        ITT    LT
        STRLT  R0, [R1], #4
        BLT    .heap_init

        LDR     R1, =SFB(CSTACK)
        LDR     R2, =SFE(CSTACK)
.stack_init:
        CMP     R1, R2
        ITT     LT
        STRLT   R0, [R1], #4
        BLT     .stack_init

#if defined(FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE) && FSL_SDK_DRIVER_QUICK_ACCESS_ENABLE
        LDR     R1, =SFB(QACCESS_CODE_VAR)
        LDR     R2, =SFE(QACCESS_CODE_VAR)
.quick_code_init:
        CMP     R1, R2
        ITT     LT
        STRLT   R0, [R1], #4
        BLT     .quick_code_init

        LDR     R1, =SFB(QACCESS_DATA_VAR)
        LDR     R2, =SFE(QACCESS_DATA_VAR)
.quick_data_init:
        CMP     R1, R2
        ITT     LT
        STRLT   R0, [R1], #4
        BLT     .quick_data_init
#endif

        ; End RW / stack / heap / quick code / quick data initialization
        ;

        LDR     R0, =SystemInit
        BLX     R0
        CPSIE   I               ; Unmask interrupts
        LDR     R0, =__iar_program_start
        BX      R0

        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B .

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B .

        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B .

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B .

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B .

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B .

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B .

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B .

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B .

        PUBWEAK Reserved16_IRQHandler
        PUBWEAK Reserved17_IRQHandler
        PUBWEAK Reserved18_IRQHandler
        PUBWEAK Reserved19_IRQHandler
        PUBWEAK Reserved20_IRQHandler
        PUBWEAK Reserved21_IRQHandler
        PUBWEAK Reserved22_IRQHandler
        PUBWEAK Reserved23_IRQHandler
        PUBWEAK Reserved24_IRQHandler
        PUBWEAK Reserved25_IRQHandler
        PUBWEAK CAN1_IRQHandler
        PUBWEAK CAN1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN1_IRQHandler
        LDR     R0, =CAN1_DriverIRQHandler
        BX      R0

        PUBWEAK CAN1_ERROR_IRQHandler
        PUBWEAK CAN1_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN1_ERROR_IRQHandler
        LDR     R0, =CAN1_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK GPIO1_INT0_IRQHandler
        PUBWEAK GPIO1_INT1_IRQHandler
        PUBWEAK I3C1_IRQHandler
        PUBWEAK I3C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C1_IRQHandler
        LDR     R0, =I3C1_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C1_IRQHandler
        PUBWEAK LPI2C1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C1_IRQHandler
        LDR     R0, =LPI2C1_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C2_IRQHandler
        PUBWEAK LPI2C2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C2_IRQHandler
        LDR     R0, =LPI2C2_DriverIRQHandler
        BX      R0

        PUBWEAK LPIT1_IRQHandler
        PUBWEAK LPSPI1_IRQHandler
        PUBWEAK LPSPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI1_IRQHandler
        LDR     R0, =LPSPI1_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI2_IRQHandler
        PUBWEAK LPSPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI2_IRQHandler
        LDR     R0, =LPSPI2_DriverIRQHandler
        BX      R0

        PUBWEAK LPTMR1_IRQHandler
        PUBWEAK LPUART1_IRQHandler
        PUBWEAK LPUART1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART1_IRQHandler
        LDR     R0, =LPUART1_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART2_IRQHandler
        PUBWEAK LPUART2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART2_IRQHandler
        LDR     R0, =LPUART2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved39_IRQHandler
        PUBWEAK Reserved40_IRQHandler
        PUBWEAK Reserved41_IRQHandler
        PUBWEAK Reserved42_IRQHandler
        PUBWEAK Reserved43_IRQHandler
        PUBWEAK Reserved44_IRQHandler
        PUBWEAK Reserved45_IRQHandler
        PUBWEAK Reserved46_IRQHandler
        PUBWEAK Reserved47_IRQHandler
        PUBWEAK V2X_FH_APCH0_IRQHandler
        PUBWEAK V2X_FH_APHSM1_IRQHandler
        PUBWEAK TPM1_IRQHandler
        PUBWEAK TPM2_IRQHandler
        PUBWEAK WDOG1_IRQHandler
        PUBWEAK WDOG2_IRQHandler
        PUBWEAK SAI1_IRQHandler
        PUBWEAK SAI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI1_IRQHandler
        LDR     R0, =SAI1_DriverIRQHandler
        BX      R0

        PUBWEAK GPT1_IRQHandler
        PUBWEAK CAN2_IRQHandler
        PUBWEAK CAN2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN2_IRQHandler
        LDR     R0, =CAN2_DriverIRQHandler
        BX      R0

        PUBWEAK CAN2_ERROR_IRQHandler
        PUBWEAK CAN2_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN2_ERROR_IRQHandler
        LDR     R0, =CAN2_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK CAN3_IRQHandler
        PUBWEAK CAN3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN3_IRQHandler
        LDR     R0, =CAN3_DriverIRQHandler
        BX      R0

        PUBWEAK CAN3_ERROR_IRQHandler
        PUBWEAK CAN3_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN3_ERROR_IRQHandler
        LDR     R0, =CAN3_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK CAN4_IRQHandler
        PUBWEAK CAN4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN4_IRQHandler
        LDR     R0, =CAN4_DriverIRQHandler
        BX      R0

        PUBWEAK CAN4_ERROR_IRQHandler
        PUBWEAK CAN4_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN4_ERROR_IRQHandler
        LDR     R0, =CAN4_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK CAN5_IRQHandler
        PUBWEAK CAN5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN5_IRQHandler
        LDR     R0, =CAN5_DriverIRQHandler
        BX      R0

        PUBWEAK CAN5_ERROR_IRQHandler
        PUBWEAK CAN5_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
CAN5_ERROR_IRQHandler
        LDR     R0, =CAN5_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO1_IRQHandler
        PUBWEAK FLEXIO1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO1_IRQHandler
        LDR     R0, =FLEXIO1_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO2_IRQHandler
        PUBWEAK FLEXIO2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO2_IRQHandler
        LDR     R0, =FLEXIO2_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO3_IRQHandler
        PUBWEAK FLEXIO3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO3_IRQHandler
        LDR     R0, =FLEXIO3_DriverIRQHandler
        BX      R0

        PUBWEAK FLEXIO4_IRQHandler
        PUBWEAK FLEXIO4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
FLEXIO4_IRQHandler
        LDR     R0, =FLEXIO4_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved68_IRQHandler
        PUBWEAK Reserved69_IRQHandler
        PUBWEAK GPIO2_INT0_IRQHandler
        PUBWEAK GPIO2_INT1_IRQHandler
        PUBWEAK GPIO3_INT0_IRQHandler
        PUBWEAK GPIO3_INT1_IRQHandler
        PUBWEAK GPIO4_INT0_IRQHandler
        PUBWEAK GPIO4_INT1_IRQHandler
        PUBWEAK GPIO5_INT0_IRQHandler
        PUBWEAK GPIO5_INT1_IRQHandler
        PUBWEAK GPIO6_INT0_IRQHandler
        PUBWEAK GPIO6_INT1_IRQHandler
        PUBWEAK GPIO7_INT0_IRQHandler
        PUBWEAK GPIO7_INT1_IRQHandler
        PUBWEAK I3C2_IRQHandler
        PUBWEAK I3C2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
I3C2_IRQHandler
        LDR     R0, =I3C2_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C3_IRQHandler
        PUBWEAK LPI2C3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C3_IRQHandler
        LDR     R0, =LPI2C3_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C4_IRQHandler
        PUBWEAK LPI2C4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C4_IRQHandler
        LDR     R0, =LPI2C4_DriverIRQHandler
        BX      R0

        PUBWEAK LPIT2_IRQHandler
        PUBWEAK LPIT3_IRQHandler
        PUBWEAK LPSPI3_IRQHandler
        PUBWEAK LPSPI3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI3_IRQHandler
        LDR     R0, =LPSPI3_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI4_IRQHandler
        PUBWEAK LPSPI4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI4_IRQHandler
        LDR     R0, =LPSPI4_DriverIRQHandler
        BX      R0

        PUBWEAK LPTMR2_IRQHandler
        PUBWEAK LPUART3_IRQHandler
        PUBWEAK LPUART3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART3_IRQHandler
        LDR     R0, =LPUART3_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART4_IRQHandler
        PUBWEAK LPUART4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART4_IRQHandler
        LDR     R0, =LPUART4_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART5_IRQHandler
        PUBWEAK LPUART5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART5_IRQHandler
        LDR     R0, =LPUART5_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART6_IRQHandler
        PUBWEAK LPUART6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART6_IRQHandler
        LDR     R0, =LPUART6_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART7_IRQHandler
        PUBWEAK LPUART7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART7_IRQHandler
        LDR     R0, =LPUART7_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART8_IRQHandler
        PUBWEAK LPUART8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART8_IRQHandler
        LDR     R0, =LPUART8_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART9_IRQHandler
        PUBWEAK LPUART9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART9_IRQHandler
        LDR     R0, =LPUART9_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART10_IRQHandler
        PUBWEAK LPUART10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART10_IRQHandler
        LDR     R0, =LPUART10_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART11_IRQHandler
        PUBWEAK LPUART11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART11_IRQHandler
        LDR     R0, =LPUART11_DriverIRQHandler
        BX      R0

        PUBWEAK LPUART12_IRQHandler
        PUBWEAK LPUART12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPUART12_IRQHandler
        LDR     R0, =LPUART12_DriverIRQHandler
        BX      R0

        PUBWEAK BBNSM_IRQHandler
        PUBWEAK SYSCTR1_IRQHandler
        PUBWEAK TPM3_IRQHandler
        PUBWEAK TPM4_IRQHandler
        PUBWEAK TPM5_IRQHandler
        PUBWEAK TPM6_IRQHandler
        PUBWEAK WDOG3_IRQHandler
        PUBWEAK WDOG4_IRQHandler
        PUBWEAK WDOG5_IRQHandler
        PUBWEAK WDOG6_IRQHandler
        PUBWEAK WDOG7_IRQHandler
        PUBWEAK WDOG8_IRQHandler
        PUBWEAK USDHC1_IRQHandler
        PUBWEAK USDHC1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC1_IRQHandler
        LDR     R0, =USDHC1_DriverIRQHandler
        BX      R0

        PUBWEAK USDHC2_IRQHandler
        PUBWEAK USDHC2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC2_IRQHandler
        LDR     R0, =USDHC2_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_ERROR_IRQHandler
        PUBWEAK EDMA2_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_ERROR_IRQHandler
        LDR     R0, =EDMA2_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved115_IRQHandler
        PUBWEAK Reserved116_IRQHandler
        PUBWEAK SAI2_IRQHandler
        PUBWEAK SAI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI2_IRQHandler
        LDR     R0, =SAI2_DriverIRQHandler
        BX      R0

        PUBWEAK SAI3_IRQHandler
        PUBWEAK SAI3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI3_IRQHandler
        LDR     R0, =SAI3_DriverIRQHandler
        BX      R0

        PUBWEAK SAI4_IRQHandler
        PUBWEAK SAI4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
SAI4_IRQHandler
        LDR     R0, =SAI4_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI5_IRQHandler
        PUBWEAK LPSPI5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI5_IRQHandler
        LDR     R0, =LPSPI5_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI6_IRQHandler
        PUBWEAK LPSPI6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI6_IRQHandler
        LDR     R0, =LPSPI6_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI7_IRQHandler
        PUBWEAK LPSPI7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI7_IRQHandler
        LDR     R0, =LPSPI7_DriverIRQHandler
        BX      R0

        PUBWEAK LPSPI8_IRQHandler
        PUBWEAK LPSPI8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPSPI8_IRQHandler
        LDR     R0, =LPSPI8_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C5_IRQHandler
        PUBWEAK LPI2C5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C5_IRQHandler
        LDR     R0, =LPI2C5_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C6_IRQHandler
        PUBWEAK LPI2C6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C6_IRQHandler
        LDR     R0, =LPI2C6_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C7_IRQHandler
        PUBWEAK LPI2C7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C7_IRQHandler
        LDR     R0, =LPI2C7_DriverIRQHandler
        BX      R0

        PUBWEAK LPI2C8_IRQHandler
        PUBWEAK LPI2C8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
LPI2C8_IRQHandler
        LDR     R0, =LPI2C8_DriverIRQHandler
        BX      R0

        PUBWEAK PDM_HWVAD_ERROR_IRQHandler
        PUBWEAK PDM_HWVAD_EVENT_IRQHandler
        PUBWEAK PDM_ERROR_IRQHandler
        PUBWEAK PDM_EVENT_IRQHandler
        PUBWEAK PDM_EVENT_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
PDM_EVENT_IRQHandler
        LDR     R0, =PDM_EVENT_DriverIRQHandler
        BX      R0

        PUBWEAK USDHC3_IRQHandler
        PUBWEAK USDHC3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
USDHC3_IRQHandler
        LDR     R0, =USDHC3_DriverIRQHandler
        BX      R0

        PUBWEAK ADC_ER_IRQHandler
        PUBWEAK ADC_WD_IRQHandler
        PUBWEAK ADC_EOC_IRQHandler
        PUBWEAK Reserved136_IRQHandler
        PUBWEAK Reserved137_IRQHandler
        PUBWEAK MU5_A_IRQHandler
        PUBWEAK MU6_A_IRQHandler
        PUBWEAK MU7_A_IRQHandler
        PUBWEAK MU10_B_IRQHandler
        PUBWEAK MU11_B_IRQHandler
        PUBWEAK MU12_A_IRQHandler
        PUBWEAK MU13_A_IRQHandler
        PUBWEAK MU18_A_IRQHandler
        PUBWEAK MU18_B_IRQHandler
        PUBWEAK MU_E1_A_IRQHandler
        PUBWEAK MU_E2_A_IRQHandler
        PUBWEAK MU_E3_A_IRQHandler
        PUBWEAK MU_E4_A_IRQHandler
        PUBWEAK XSPI_SLV_IRQHandler
        PUBWEAK XSPI_SLV_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
XSPI_SLV_IRQHandler
        LDR     R0, =XSPI_SLV_DriverIRQHandler
        BX      R0

        PUBWEAK FCCU_INT0_IRQHandler
        PUBWEAK FCCU_INT1_IRQHandler
        PUBWEAK FCCU_INT2_IRQHandler
        PUBWEAK FCCU_INT3_IRQHandler
        PUBWEAK FCCU_INT4_IRQHandler
        PUBWEAK STCU_IRQHandler
        PUBWEAK XBAR1_CH0_CH1_IRQHandler
        PUBWEAK XBAR1_CH2_CH3_IRQHandler
        PUBWEAK GPT2_IRQHandler
        PUBWEAK GPT3_IRQHandler
        PUBWEAK GPT4_IRQHandler
        PUBWEAK Reserved163_IRQHandler
        PUBWEAK Reserved164_IRQHandler
        PUBWEAK Reserved165_IRQHandler
        PUBWEAK Reserved166_IRQHandler
        PUBWEAK Reserved167_IRQHandler
        PUBWEAK Reserved168_IRQHandler
        PUBWEAK Reserved169_IRQHandler
        PUBWEAK Reserved170_IRQHandler
        PUBWEAK Reserved171_IRQHandler
        PUBWEAK Reserved172_IRQHandler
        PUBWEAK Reserved173_IRQHandler
        PUBWEAK Reserved174_IRQHandler
        PUBWEAK Reserved175_IRQHandler
        PUBWEAK Reserved176_IRQHandler
        PUBWEAK Reserved177_IRQHandler
        PUBWEAK Reserved178_IRQHandler
        PUBWEAK Reserved179_IRQHandler
        PUBWEAK Reserved180_IRQHandler
        PUBWEAK Reserved181_IRQHandler
        PUBWEAK Reserved182_IRQHandler
        PUBWEAK Reserved183_IRQHandler
        PUBWEAK Reserved184_IRQHandler
        PUBWEAK Reserved185_IRQHandler
        PUBWEAK Reserved186_IRQHandler
        PUBWEAK ENC1_IRQHandler
        PUBWEAK ENC2_IRQHandler
        PUBWEAK ENC3_IRQHandler
        PUBWEAK ENC4_IRQHandler
        PUBWEAK EWM_IRQHandler
        PUBWEAK Reserved192_IRQHandler
        PUBWEAK Reserved193_IRQHandler
        PUBWEAK Reserved194_IRQHandler
        PUBWEAK Reserved195_IRQHandler
        PUBWEAK USB1_IRQHandler
        PUBWEAK USB2_IRQHandler
        PUBWEAK SINC1_CH0_IRQHandler
        PUBWEAK SINC1_CH1_IRQHandler
        PUBWEAK SINC1_CH2_IRQHandler
        PUBWEAK SINC1_CH3_IRQHandler
        PUBWEAK SINC2_CH0_IRQHandler
        PUBWEAK SINC2_CH1_IRQHandler
        PUBWEAK SINC2_CH2_IRQHandler
        PUBWEAK SINC2_CH3_IRQHandler
        PUBWEAK SINC3_CH0_IRQHandler
        PUBWEAK SINC3_CH1_IRQHandler
        PUBWEAK SINC3_CH2_IRQHandler
        PUBWEAK SINC3_CH3_IRQHandler
        PUBWEAK SINC4_CH0_IRQHandler
        PUBWEAK SINC4_CH1_IRQHandler
        PUBWEAK SINC4_CH2_IRQHandler
        PUBWEAK SINC4_CH3_IRQHandler
        PUBWEAK TMR1_IRQHandler
        PUBWEAK TMR2_IRQHandler
        PUBWEAK TMR3_IRQHandler
        PUBWEAK TMR4_IRQHandler
        PUBWEAK TMR5_IRQHandler
        PUBWEAK TMR6_IRQHandler
        PUBWEAK TMR7_IRQHandler
        PUBWEAK TMR8_IRQHandler
        PUBWEAK EDMA4_ERROR_IRQHandler
        PUBWEAK EDMA4_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_ERROR_IRQHandler
        LDR     R0, =EDMA4_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved223_IRQHandler
        PUBWEAK Reserved224_IRQHandler
        PUBWEAK Reserved225_IRQHandler
        PUBWEAK Reserved226_IRQHandler
        PUBWEAK Reserved227_IRQHandler
        PUBWEAK Reserved228_IRQHandler
        PUBWEAK Reserved229_IRQHandler
        PUBWEAK Reserved230_IRQHandler
        PUBWEAK Reserved231_IRQHandler
        PUBWEAK Reserved232_IRQHandler
        PUBWEAK Reserved233_IRQHandler
        PUBWEAK Reserved234_IRQHandler
        PUBWEAK Reserved235_IRQHandler
        PUBWEAK Reserved236_IRQHandler
        PUBWEAK Reserved237_IRQHandler
        PUBWEAK Reserved238_IRQHandler
        PUBWEAK Reserved239_IRQHandler
        PUBWEAK IRQSTEERM7_CH0_IRQHandler
        PUBWEAK IRQSTEERM7_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH0_IRQHandler
        LDR     R0, =IRQSTEERM7_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH1_IRQHandler
        PUBWEAK IRQSTEERM7_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH1_IRQHandler
        LDR     R0, =IRQSTEERM7_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH2_IRQHandler
        PUBWEAK IRQSTEERM7_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH2_IRQHandler
        LDR     R0, =IRQSTEERM7_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH3_IRQHandler
        PUBWEAK IRQSTEERM7_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH3_IRQHandler
        LDR     R0, =IRQSTEERM7_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH4_IRQHandler
        PUBWEAK IRQSTEERM7_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH4_IRQHandler
        LDR     R0, =IRQSTEERM7_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH5_IRQHandler
        PUBWEAK IRQSTEERM7_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH5_IRQHandler
        LDR     R0, =IRQSTEERM7_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH6_IRQHandler
        PUBWEAK IRQSTEERM7_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH6_IRQHandler
        LDR     R0, =IRQSTEERM7_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH7_IRQHandler
        PUBWEAK IRQSTEERM7_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH7_IRQHandler
        LDR     R0, =IRQSTEERM7_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH8_IRQHandler
        PUBWEAK IRQSTEERM7_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH8_IRQHandler
        LDR     R0, =IRQSTEERM7_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH9_IRQHandler
        PUBWEAK IRQSTEERM7_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH9_IRQHandler
        LDR     R0, =IRQSTEERM7_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH10_IRQHandler
        PUBWEAK IRQSTEERM7_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH10_IRQHandler
        LDR     R0, =IRQSTEERM7_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH11_IRQHandler
        PUBWEAK IRQSTEERM7_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH11_IRQHandler
        LDR     R0, =IRQSTEERM7_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK IRQSTEERM7_CH12_IRQHandler
        PUBWEAK IRQSTEERM7_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
IRQSTEERM7_CH12_IRQHandler
        LDR     R0, =IRQSTEERM7_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved253_IRQHandler
        PUBWEAK EDMA2_CH0_IRQHandler
        PUBWEAK EDMA2_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH0_IRQHandler
        LDR     R0, =EDMA2_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH1_IRQHandler
        PUBWEAK EDMA2_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH1_IRQHandler
        LDR     R0, =EDMA2_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH2_IRQHandler
        PUBWEAK EDMA2_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH2_IRQHandler
        LDR     R0, =EDMA2_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH3_IRQHandler
        PUBWEAK EDMA2_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH3_IRQHandler
        LDR     R0, =EDMA2_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH4_IRQHandler
        PUBWEAK EDMA2_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH4_IRQHandler
        LDR     R0, =EDMA2_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH5_IRQHandler
        PUBWEAK EDMA2_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH5_IRQHandler
        LDR     R0, =EDMA2_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH6_IRQHandler
        PUBWEAK EDMA2_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH6_IRQHandler
        LDR     R0, =EDMA2_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH7_IRQHandler
        PUBWEAK EDMA2_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH7_IRQHandler
        LDR     R0, =EDMA2_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH8_IRQHandler
        PUBWEAK EDMA2_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH8_IRQHandler
        LDR     R0, =EDMA2_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH9_IRQHandler
        PUBWEAK EDMA2_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH9_IRQHandler
        LDR     R0, =EDMA2_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH10_IRQHandler
        PUBWEAK EDMA2_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH10_IRQHandler
        LDR     R0, =EDMA2_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH11_IRQHandler
        PUBWEAK EDMA2_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH11_IRQHandler
        LDR     R0, =EDMA2_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH12_IRQHandler
        PUBWEAK EDMA2_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH12_IRQHandler
        LDR     R0, =EDMA2_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH13_IRQHandler
        PUBWEAK EDMA2_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH13_IRQHandler
        LDR     R0, =EDMA2_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH14_IRQHandler
        PUBWEAK EDMA2_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH14_IRQHandler
        LDR     R0, =EDMA2_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH15_IRQHandler
        PUBWEAK EDMA2_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH15_IRQHandler
        LDR     R0, =EDMA2_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH16_IRQHandler
        PUBWEAK EDMA2_CH16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH16_IRQHandler
        LDR     R0, =EDMA2_CH16_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH17_IRQHandler
        PUBWEAK EDMA2_CH17_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH17_IRQHandler
        LDR     R0, =EDMA2_CH17_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH18_IRQHandler
        PUBWEAK EDMA2_CH18_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH18_IRQHandler
        LDR     R0, =EDMA2_CH18_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH19_IRQHandler
        PUBWEAK EDMA2_CH19_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH19_IRQHandler
        LDR     R0, =EDMA2_CH19_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH20_IRQHandler
        PUBWEAK EDMA2_CH20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH20_IRQHandler
        LDR     R0, =EDMA2_CH20_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH21_IRQHandler
        PUBWEAK EDMA2_CH21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH21_IRQHandler
        LDR     R0, =EDMA2_CH21_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH22_IRQHandler
        PUBWEAK EDMA2_CH22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH22_IRQHandler
        LDR     R0, =EDMA2_CH22_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH23_IRQHandler
        PUBWEAK EDMA2_CH23_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH23_IRQHandler
        LDR     R0, =EDMA2_CH23_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH24_IRQHandler
        PUBWEAK EDMA2_CH24_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH24_IRQHandler
        LDR     R0, =EDMA2_CH24_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH25_IRQHandler
        PUBWEAK EDMA2_CH25_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH25_IRQHandler
        LDR     R0, =EDMA2_CH25_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH26_IRQHandler
        PUBWEAK EDMA2_CH26_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH26_IRQHandler
        LDR     R0, =EDMA2_CH26_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH27_IRQHandler
        PUBWEAK EDMA2_CH27_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH27_IRQHandler
        LDR     R0, =EDMA2_CH27_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH28_IRQHandler
        PUBWEAK EDMA2_CH28_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH28_IRQHandler
        LDR     R0, =EDMA2_CH28_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH29_IRQHandler
        PUBWEAK EDMA2_CH29_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH29_IRQHandler
        LDR     R0, =EDMA2_CH29_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH30_IRQHandler
        PUBWEAK EDMA2_CH30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH30_IRQHandler
        LDR     R0, =EDMA2_CH30_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH31_IRQHandler
        PUBWEAK EDMA2_CH31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH31_IRQHandler
        LDR     R0, =EDMA2_CH31_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH32_IRQHandler
        PUBWEAK EDMA2_CH32_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH32_IRQHandler
        LDR     R0, =EDMA2_CH32_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH33_IRQHandler
        PUBWEAK EDMA2_CH33_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH33_IRQHandler
        LDR     R0, =EDMA2_CH33_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH34_IRQHandler
        PUBWEAK EDMA2_CH34_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH34_IRQHandler
        LDR     R0, =EDMA2_CH34_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH35_IRQHandler
        PUBWEAK EDMA2_CH35_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH35_IRQHandler
        LDR     R0, =EDMA2_CH35_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH36_IRQHandler
        PUBWEAK EDMA2_CH36_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH36_IRQHandler
        LDR     R0, =EDMA2_CH36_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH37_IRQHandler
        PUBWEAK EDMA2_CH37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH37_IRQHandler
        LDR     R0, =EDMA2_CH37_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH38_IRQHandler
        PUBWEAK EDMA2_CH38_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH38_IRQHandler
        LDR     R0, =EDMA2_CH38_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH39_IRQHandler
        PUBWEAK EDMA2_CH39_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH39_IRQHandler
        LDR     R0, =EDMA2_CH39_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH40_IRQHandler
        PUBWEAK EDMA2_CH40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH40_IRQHandler
        LDR     R0, =EDMA2_CH40_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH41_IRQHandler
        PUBWEAK EDMA2_CH41_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH41_IRQHandler
        LDR     R0, =EDMA2_CH41_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH42_IRQHandler
        PUBWEAK EDMA2_CH42_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH42_IRQHandler
        LDR     R0, =EDMA2_CH42_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH43_IRQHandler
        PUBWEAK EDMA2_CH43_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH43_IRQHandler
        LDR     R0, =EDMA2_CH43_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH44_IRQHandler
        PUBWEAK EDMA2_CH44_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH44_IRQHandler
        LDR     R0, =EDMA2_CH44_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH45_IRQHandler
        PUBWEAK EDMA2_CH45_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH45_IRQHandler
        LDR     R0, =EDMA2_CH45_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH46_IRQHandler
        PUBWEAK EDMA2_CH46_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH46_IRQHandler
        LDR     R0, =EDMA2_CH46_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH47_IRQHandler
        PUBWEAK EDMA2_CH47_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH47_IRQHandler
        LDR     R0, =EDMA2_CH47_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH48_IRQHandler
        PUBWEAK EDMA2_CH48_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH48_IRQHandler
        LDR     R0, =EDMA2_CH48_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH49_IRQHandler
        PUBWEAK EDMA2_CH49_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH49_IRQHandler
        LDR     R0, =EDMA2_CH49_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH50_IRQHandler
        PUBWEAK EDMA2_CH50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH50_IRQHandler
        LDR     R0, =EDMA2_CH50_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH51_IRQHandler
        PUBWEAK EDMA2_CH51_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH51_IRQHandler
        LDR     R0, =EDMA2_CH51_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH52_IRQHandler
        PUBWEAK EDMA2_CH52_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH52_IRQHandler
        LDR     R0, =EDMA2_CH52_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH53_IRQHandler
        PUBWEAK EDMA2_CH53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH53_IRQHandler
        LDR     R0, =EDMA2_CH53_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH54_IRQHandler
        PUBWEAK EDMA2_CH54_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH54_IRQHandler
        LDR     R0, =EDMA2_CH54_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH55_IRQHandler
        PUBWEAK EDMA2_CH55_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH55_IRQHandler
        LDR     R0, =EDMA2_CH55_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH56_IRQHandler
        PUBWEAK EDMA2_CH56_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH56_IRQHandler
        LDR     R0, =EDMA2_CH56_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH57_IRQHandler
        PUBWEAK EDMA2_CH57_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH57_IRQHandler
        LDR     R0, =EDMA2_CH57_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH58_IRQHandler
        PUBWEAK EDMA2_CH58_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH58_IRQHandler
        LDR     R0, =EDMA2_CH58_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH59_IRQHandler
        PUBWEAK EDMA2_CH59_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH59_IRQHandler
        LDR     R0, =EDMA2_CH59_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH60_IRQHandler
        PUBWEAK EDMA2_CH60_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH60_IRQHandler
        LDR     R0, =EDMA2_CH60_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH61_IRQHandler
        PUBWEAK EDMA2_CH61_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH61_IRQHandler
        LDR     R0, =EDMA2_CH61_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH62_IRQHandler
        PUBWEAK EDMA2_CH62_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH62_IRQHandler
        LDR     R0, =EDMA2_CH62_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA2_CH63_IRQHandler
        PUBWEAK EDMA2_CH63_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA2_CH63_IRQHandler
        LDR     R0, =EDMA2_CH63_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH0_IRQHandler
        PUBWEAK EDMA4_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH0_IRQHandler
        LDR     R0, =EDMA4_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH1_IRQHandler
        PUBWEAK EDMA4_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH1_IRQHandler
        LDR     R0, =EDMA4_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH2_IRQHandler
        PUBWEAK EDMA4_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH2_IRQHandler
        LDR     R0, =EDMA4_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH3_IRQHandler
        PUBWEAK EDMA4_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH3_IRQHandler
        LDR     R0, =EDMA4_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH4_IRQHandler
        PUBWEAK EDMA4_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH4_IRQHandler
        LDR     R0, =EDMA4_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH5_IRQHandler
        PUBWEAK EDMA4_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH5_IRQHandler
        LDR     R0, =EDMA4_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH6_IRQHandler
        PUBWEAK EDMA4_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH6_IRQHandler
        LDR     R0, =EDMA4_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH7_IRQHandler
        PUBWEAK EDMA4_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH7_IRQHandler
        LDR     R0, =EDMA4_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH8_IRQHandler
        PUBWEAK EDMA4_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH8_IRQHandler
        LDR     R0, =EDMA4_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH9_IRQHandler
        PUBWEAK EDMA4_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH9_IRQHandler
        LDR     R0, =EDMA4_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH10_IRQHandler
        PUBWEAK EDMA4_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH10_IRQHandler
        LDR     R0, =EDMA4_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH11_IRQHandler
        PUBWEAK EDMA4_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH11_IRQHandler
        LDR     R0, =EDMA4_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH12_IRQHandler
        PUBWEAK EDMA4_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH12_IRQHandler
        LDR     R0, =EDMA4_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH13_IRQHandler
        PUBWEAK EDMA4_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH13_IRQHandler
        LDR     R0, =EDMA4_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH14_IRQHandler
        PUBWEAK EDMA4_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH14_IRQHandler
        LDR     R0, =EDMA4_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH15_IRQHandler
        PUBWEAK EDMA4_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH15_IRQHandler
        LDR     R0, =EDMA4_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH16_IRQHandler
        PUBWEAK EDMA4_CH16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH16_IRQHandler
        LDR     R0, =EDMA4_CH16_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH17_IRQHandler
        PUBWEAK EDMA4_CH17_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH17_IRQHandler
        LDR     R0, =EDMA4_CH17_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH18_IRQHandler
        PUBWEAK EDMA4_CH18_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH18_IRQHandler
        LDR     R0, =EDMA4_CH18_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH19_IRQHandler
        PUBWEAK EDMA4_CH19_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH19_IRQHandler
        LDR     R0, =EDMA4_CH19_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH20_IRQHandler
        PUBWEAK EDMA4_CH20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH20_IRQHandler
        LDR     R0, =EDMA4_CH20_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH21_IRQHandler
        PUBWEAK EDMA4_CH21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH21_IRQHandler
        LDR     R0, =EDMA4_CH21_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH22_IRQHandler
        PUBWEAK EDMA4_CH22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH22_IRQHandler
        LDR     R0, =EDMA4_CH22_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH23_IRQHandler
        PUBWEAK EDMA4_CH23_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH23_IRQHandler
        LDR     R0, =EDMA4_CH23_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH24_IRQHandler
        PUBWEAK EDMA4_CH24_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH24_IRQHandler
        LDR     R0, =EDMA4_CH24_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH25_IRQHandler
        PUBWEAK EDMA4_CH25_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH25_IRQHandler
        LDR     R0, =EDMA4_CH25_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH26_IRQHandler
        PUBWEAK EDMA4_CH26_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH26_IRQHandler
        LDR     R0, =EDMA4_CH26_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH27_IRQHandler
        PUBWEAK EDMA4_CH27_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH27_IRQHandler
        LDR     R0, =EDMA4_CH27_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH28_IRQHandler
        PUBWEAK EDMA4_CH28_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH28_IRQHandler
        LDR     R0, =EDMA4_CH28_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH29_IRQHandler
        PUBWEAK EDMA4_CH29_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH29_IRQHandler
        LDR     R0, =EDMA4_CH29_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH30_IRQHandler
        PUBWEAK EDMA4_CH30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH30_IRQHandler
        LDR     R0, =EDMA4_CH30_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH31_IRQHandler
        PUBWEAK EDMA4_CH31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH31_IRQHandler
        LDR     R0, =EDMA4_CH31_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH32_IRQHandler
        PUBWEAK EDMA4_CH32_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH32_IRQHandler
        LDR     R0, =EDMA4_CH32_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH33_IRQHandler
        PUBWEAK EDMA4_CH33_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH33_IRQHandler
        LDR     R0, =EDMA4_CH33_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH34_IRQHandler
        PUBWEAK EDMA4_CH34_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH34_IRQHandler
        LDR     R0, =EDMA4_CH34_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH35_IRQHandler
        PUBWEAK EDMA4_CH35_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH35_IRQHandler
        LDR     R0, =EDMA4_CH35_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH36_IRQHandler
        PUBWEAK EDMA4_CH36_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH36_IRQHandler
        LDR     R0, =EDMA4_CH36_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH37_IRQHandler
        PUBWEAK EDMA4_CH37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH37_IRQHandler
        LDR     R0, =EDMA4_CH37_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH38_IRQHandler
        PUBWEAK EDMA4_CH38_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH38_IRQHandler
        LDR     R0, =EDMA4_CH38_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH39_IRQHandler
        PUBWEAK EDMA4_CH39_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH39_IRQHandler
        LDR     R0, =EDMA4_CH39_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH40_IRQHandler
        PUBWEAK EDMA4_CH40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH40_IRQHandler
        LDR     R0, =EDMA4_CH40_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH41_IRQHandler
        PUBWEAK EDMA4_CH41_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH41_IRQHandler
        LDR     R0, =EDMA4_CH41_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH42_IRQHandler
        PUBWEAK EDMA4_CH42_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH42_IRQHandler
        LDR     R0, =EDMA4_CH42_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH43_IRQHandler
        PUBWEAK EDMA4_CH43_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH43_IRQHandler
        LDR     R0, =EDMA4_CH43_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH44_IRQHandler
        PUBWEAK EDMA4_CH44_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH44_IRQHandler
        LDR     R0, =EDMA4_CH44_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH45_IRQHandler
        PUBWEAK EDMA4_CH45_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH45_IRQHandler
        LDR     R0, =EDMA4_CH45_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH46_IRQHandler
        PUBWEAK EDMA4_CH46_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH46_IRQHandler
        LDR     R0, =EDMA4_CH46_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH47_IRQHandler
        PUBWEAK EDMA4_CH47_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH47_IRQHandler
        LDR     R0, =EDMA4_CH47_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH48_IRQHandler
        PUBWEAK EDMA4_CH48_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH48_IRQHandler
        LDR     R0, =EDMA4_CH48_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH49_IRQHandler
        PUBWEAK EDMA4_CH49_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH49_IRQHandler
        LDR     R0, =EDMA4_CH49_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH50_IRQHandler
        PUBWEAK EDMA4_CH50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH50_IRQHandler
        LDR     R0, =EDMA4_CH50_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH51_IRQHandler
        PUBWEAK EDMA4_CH51_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH51_IRQHandler
        LDR     R0, =EDMA4_CH51_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH52_IRQHandler
        PUBWEAK EDMA4_CH52_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH52_IRQHandler
        LDR     R0, =EDMA4_CH52_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH53_IRQHandler
        PUBWEAK EDMA4_CH53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH53_IRQHandler
        LDR     R0, =EDMA4_CH53_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH54_IRQHandler
        PUBWEAK EDMA4_CH54_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH54_IRQHandler
        LDR     R0, =EDMA4_CH54_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH55_IRQHandler
        PUBWEAK EDMA4_CH55_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH55_IRQHandler
        LDR     R0, =EDMA4_CH55_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH56_IRQHandler
        PUBWEAK EDMA4_CH56_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH56_IRQHandler
        LDR     R0, =EDMA4_CH56_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH57_IRQHandler
        PUBWEAK EDMA4_CH57_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH57_IRQHandler
        LDR     R0, =EDMA4_CH57_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH58_IRQHandler
        PUBWEAK EDMA4_CH58_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH58_IRQHandler
        LDR     R0, =EDMA4_CH58_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH59_IRQHandler
        PUBWEAK EDMA4_CH59_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH59_IRQHandler
        LDR     R0, =EDMA4_CH59_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH60_IRQHandler
        PUBWEAK EDMA4_CH60_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH60_IRQHandler
        LDR     R0, =EDMA4_CH60_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH61_IRQHandler
        PUBWEAK EDMA4_CH61_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH61_IRQHandler
        LDR     R0, =EDMA4_CH61_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH62_IRQHandler
        PUBWEAK EDMA4_CH62_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH62_IRQHandler
        LDR     R0, =EDMA4_CH62_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA4_CH63_IRQHandler
        PUBWEAK EDMA4_CH63_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA4_CH63_IRQHandler
        LDR     R0, =EDMA4_CH63_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH0_IRQHandler
        PUBWEAK EDMA3_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH0_IRQHandler
        LDR     R0, =EDMA3_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH1_IRQHandler
        PUBWEAK EDMA3_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH1_IRQHandler
        LDR     R0, =EDMA3_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH2_IRQHandler
        PUBWEAK EDMA3_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH2_IRQHandler
        LDR     R0, =EDMA3_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH3_IRQHandler
        PUBWEAK EDMA3_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH3_IRQHandler
        LDR     R0, =EDMA3_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH4_IRQHandler
        PUBWEAK EDMA3_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH4_IRQHandler
        LDR     R0, =EDMA3_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH5_IRQHandler
        PUBWEAK EDMA3_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH5_IRQHandler
        LDR     R0, =EDMA3_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH6_IRQHandler
        PUBWEAK EDMA3_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH6_IRQHandler
        LDR     R0, =EDMA3_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH7_IRQHandler
        PUBWEAK EDMA3_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH7_IRQHandler
        LDR     R0, =EDMA3_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH8_IRQHandler
        PUBWEAK EDMA3_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH8_IRQHandler
        LDR     R0, =EDMA3_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH9_IRQHandler
        PUBWEAK EDMA3_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH9_IRQHandler
        LDR     R0, =EDMA3_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH10_IRQHandler
        PUBWEAK EDMA3_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH10_IRQHandler
        LDR     R0, =EDMA3_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH11_IRQHandler
        PUBWEAK EDMA3_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH11_IRQHandler
        LDR     R0, =EDMA3_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH12_IRQHandler
        PUBWEAK EDMA3_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH12_IRQHandler
        LDR     R0, =EDMA3_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH13_IRQHandler
        PUBWEAK EDMA3_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH13_IRQHandler
        LDR     R0, =EDMA3_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH14_IRQHandler
        PUBWEAK EDMA3_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH14_IRQHandler
        LDR     R0, =EDMA3_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH15_IRQHandler
        PUBWEAK EDMA3_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH15_IRQHandler
        LDR     R0, =EDMA3_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH16_IRQHandler
        PUBWEAK EDMA3_CH16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH16_IRQHandler
        LDR     R0, =EDMA3_CH16_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH17_IRQHandler
        PUBWEAK EDMA3_CH17_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH17_IRQHandler
        LDR     R0, =EDMA3_CH17_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH18_IRQHandler
        PUBWEAK EDMA3_CH18_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH18_IRQHandler
        LDR     R0, =EDMA3_CH18_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH19_IRQHandler
        PUBWEAK EDMA3_CH19_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH19_IRQHandler
        LDR     R0, =EDMA3_CH19_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH20_IRQHandler
        PUBWEAK EDMA3_CH20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH20_IRQHandler
        LDR     R0, =EDMA3_CH20_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH21_IRQHandler
        PUBWEAK EDMA3_CH21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH21_IRQHandler
        LDR     R0, =EDMA3_CH21_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH22_IRQHandler
        PUBWEAK EDMA3_CH22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH22_IRQHandler
        LDR     R0, =EDMA3_CH22_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH23_IRQHandler
        PUBWEAK EDMA3_CH23_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH23_IRQHandler
        LDR     R0, =EDMA3_CH23_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH24_IRQHandler
        PUBWEAK EDMA3_CH24_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH24_IRQHandler
        LDR     R0, =EDMA3_CH24_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH25_IRQHandler
        PUBWEAK EDMA3_CH25_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH25_IRQHandler
        LDR     R0, =EDMA3_CH25_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH26_IRQHandler
        PUBWEAK EDMA3_CH26_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH26_IRQHandler
        LDR     R0, =EDMA3_CH26_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH27_IRQHandler
        PUBWEAK EDMA3_CH27_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH27_IRQHandler
        LDR     R0, =EDMA3_CH27_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH28_IRQHandler
        PUBWEAK EDMA3_CH28_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH28_IRQHandler
        LDR     R0, =EDMA3_CH28_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH29_IRQHandler
        PUBWEAK EDMA3_CH29_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH29_IRQHandler
        LDR     R0, =EDMA3_CH29_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH30_IRQHandler
        PUBWEAK EDMA3_CH30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH30_IRQHandler
        LDR     R0, =EDMA3_CH30_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH31_IRQHandler
        PUBWEAK EDMA3_CH31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH31_IRQHandler
        LDR     R0, =EDMA3_CH31_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH32_IRQHandler
        PUBWEAK EDMA3_CH32_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH32_IRQHandler
        LDR     R0, =EDMA3_CH32_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH33_IRQHandler
        PUBWEAK EDMA3_CH33_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH33_IRQHandler
        LDR     R0, =EDMA3_CH33_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH34_IRQHandler
        PUBWEAK EDMA3_CH34_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH34_IRQHandler
        LDR     R0, =EDMA3_CH34_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH35_IRQHandler
        PUBWEAK EDMA3_CH35_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH35_IRQHandler
        LDR     R0, =EDMA3_CH35_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH36_IRQHandler
        PUBWEAK EDMA3_CH36_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH36_IRQHandler
        LDR     R0, =EDMA3_CH36_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH37_IRQHandler
        PUBWEAK EDMA3_CH37_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH37_IRQHandler
        LDR     R0, =EDMA3_CH37_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH38_IRQHandler
        PUBWEAK EDMA3_CH38_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH38_IRQHandler
        LDR     R0, =EDMA3_CH38_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH39_IRQHandler
        PUBWEAK EDMA3_CH39_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH39_IRQHandler
        LDR     R0, =EDMA3_CH39_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH40_IRQHandler
        PUBWEAK EDMA3_CH40_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH40_IRQHandler
        LDR     R0, =EDMA3_CH40_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH41_IRQHandler
        PUBWEAK EDMA3_CH41_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH41_IRQHandler
        LDR     R0, =EDMA3_CH41_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH42_IRQHandler
        PUBWEAK EDMA3_CH42_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH42_IRQHandler
        LDR     R0, =EDMA3_CH42_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH43_IRQHandler
        PUBWEAK EDMA3_CH43_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH43_IRQHandler
        LDR     R0, =EDMA3_CH43_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH44_IRQHandler
        PUBWEAK EDMA3_CH44_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH44_IRQHandler
        LDR     R0, =EDMA3_CH44_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH45_IRQHandler
        PUBWEAK EDMA3_CH45_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH45_IRQHandler
        LDR     R0, =EDMA3_CH45_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH46_IRQHandler
        PUBWEAK EDMA3_CH46_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH46_IRQHandler
        LDR     R0, =EDMA3_CH46_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH47_IRQHandler
        PUBWEAK EDMA3_CH47_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH47_IRQHandler
        LDR     R0, =EDMA3_CH47_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH48_IRQHandler
        PUBWEAK EDMA3_CH48_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH48_IRQHandler
        LDR     R0, =EDMA3_CH48_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH49_IRQHandler
        PUBWEAK EDMA3_CH49_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH49_IRQHandler
        LDR     R0, =EDMA3_CH49_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH50_IRQHandler
        PUBWEAK EDMA3_CH50_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH50_IRQHandler
        LDR     R0, =EDMA3_CH50_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH51_IRQHandler
        PUBWEAK EDMA3_CH51_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH51_IRQHandler
        LDR     R0, =EDMA3_CH51_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH52_IRQHandler
        PUBWEAK EDMA3_CH52_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH52_IRQHandler
        LDR     R0, =EDMA3_CH52_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH53_IRQHandler
        PUBWEAK EDMA3_CH53_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH53_IRQHandler
        LDR     R0, =EDMA3_CH53_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH54_IRQHandler
        PUBWEAK EDMA3_CH54_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH54_IRQHandler
        LDR     R0, =EDMA3_CH54_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH55_IRQHandler
        PUBWEAK EDMA3_CH55_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH55_IRQHandler
        LDR     R0, =EDMA3_CH55_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH56_IRQHandler
        PUBWEAK EDMA3_CH56_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH56_IRQHandler
        LDR     R0, =EDMA3_CH56_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH57_IRQHandler
        PUBWEAK EDMA3_CH57_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH57_IRQHandler
        LDR     R0, =EDMA3_CH57_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH58_IRQHandler
        PUBWEAK EDMA3_CH58_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH58_IRQHandler
        LDR     R0, =EDMA3_CH58_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH59_IRQHandler
        PUBWEAK EDMA3_CH59_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH59_IRQHandler
        LDR     R0, =EDMA3_CH59_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH60_IRQHandler
        PUBWEAK EDMA3_CH60_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH60_IRQHandler
        LDR     R0, =EDMA3_CH60_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH61_IRQHandler
        PUBWEAK EDMA3_CH61_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH61_IRQHandler
        LDR     R0, =EDMA3_CH61_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH62_IRQHandler
        PUBWEAK EDMA3_CH62_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH62_IRQHandler
        LDR     R0, =EDMA3_CH62_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA3_CH63_IRQHandler
        PUBWEAK EDMA3_CH63_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA3_CH63_IRQHandler
        LDR     R0, =EDMA3_CH63_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH0_IRQHandler
        PUBWEAK EDMA1_CH0_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH0_IRQHandler
        LDR     R0, =EDMA1_CH0_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH1_IRQHandler
        PUBWEAK EDMA1_CH1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH1_IRQHandler
        LDR     R0, =EDMA1_CH1_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH2_IRQHandler
        PUBWEAK EDMA1_CH2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH2_IRQHandler
        LDR     R0, =EDMA1_CH2_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH3_IRQHandler
        PUBWEAK EDMA1_CH3_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH3_IRQHandler
        LDR     R0, =EDMA1_CH3_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH4_IRQHandler
        PUBWEAK EDMA1_CH4_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH4_IRQHandler
        LDR     R0, =EDMA1_CH4_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH5_IRQHandler
        PUBWEAK EDMA1_CH5_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH5_IRQHandler
        LDR     R0, =EDMA1_CH5_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH6_IRQHandler
        PUBWEAK EDMA1_CH6_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH6_IRQHandler
        LDR     R0, =EDMA1_CH6_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH7_IRQHandler
        PUBWEAK EDMA1_CH7_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH7_IRQHandler
        LDR     R0, =EDMA1_CH7_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH8_IRQHandler
        PUBWEAK EDMA1_CH8_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH8_IRQHandler
        LDR     R0, =EDMA1_CH8_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH9_IRQHandler
        PUBWEAK EDMA1_CH9_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH9_IRQHandler
        LDR     R0, =EDMA1_CH9_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH10_IRQHandler
        PUBWEAK EDMA1_CH10_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH10_IRQHandler
        LDR     R0, =EDMA1_CH10_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH11_IRQHandler
        PUBWEAK EDMA1_CH11_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH11_IRQHandler
        LDR     R0, =EDMA1_CH11_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH12_IRQHandler
        PUBWEAK EDMA1_CH12_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH12_IRQHandler
        LDR     R0, =EDMA1_CH12_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH13_IRQHandler
        PUBWEAK EDMA1_CH13_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH13_IRQHandler
        LDR     R0, =EDMA1_CH13_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH14_IRQHandler
        PUBWEAK EDMA1_CH14_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH14_IRQHandler
        LDR     R0, =EDMA1_CH14_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH15_IRQHandler
        PUBWEAK EDMA1_CH15_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH15_IRQHandler
        LDR     R0, =EDMA1_CH15_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH16_IRQHandler
        PUBWEAK EDMA1_CH16_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH16_IRQHandler
        LDR     R0, =EDMA1_CH16_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH17_IRQHandler
        PUBWEAK EDMA1_CH17_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH17_IRQHandler
        LDR     R0, =EDMA1_CH17_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH18_IRQHandler
        PUBWEAK EDMA1_CH18_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH18_IRQHandler
        LDR     R0, =EDMA1_CH18_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH19_IRQHandler
        PUBWEAK EDMA1_CH19_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH19_IRQHandler
        LDR     R0, =EDMA1_CH19_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH20_IRQHandler
        PUBWEAK EDMA1_CH20_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH20_IRQHandler
        LDR     R0, =EDMA1_CH20_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH21_IRQHandler
        PUBWEAK EDMA1_CH21_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH21_IRQHandler
        LDR     R0, =EDMA1_CH21_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH22_IRQHandler
        PUBWEAK EDMA1_CH22_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH22_IRQHandler
        LDR     R0, =EDMA1_CH22_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH23_IRQHandler
        PUBWEAK EDMA1_CH23_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH23_IRQHandler
        LDR     R0, =EDMA1_CH23_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH24_IRQHandler
        PUBWEAK EDMA1_CH24_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH24_IRQHandler
        LDR     R0, =EDMA1_CH24_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH25_IRQHandler
        PUBWEAK EDMA1_CH25_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH25_IRQHandler
        LDR     R0, =EDMA1_CH25_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH26_IRQHandler
        PUBWEAK EDMA1_CH26_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH26_IRQHandler
        LDR     R0, =EDMA1_CH26_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH27_IRQHandler
        PUBWEAK EDMA1_CH27_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH27_IRQHandler
        LDR     R0, =EDMA1_CH27_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH28_IRQHandler
        PUBWEAK EDMA1_CH28_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH28_IRQHandler
        LDR     R0, =EDMA1_CH28_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH29_IRQHandler
        PUBWEAK EDMA1_CH29_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH29_IRQHandler
        LDR     R0, =EDMA1_CH29_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH30_IRQHandler
        PUBWEAK EDMA1_CH30_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH30_IRQHandler
        LDR     R0, =EDMA1_CH30_DriverIRQHandler
        BX      R0

        PUBWEAK EDMA1_CH31_IRQHandler
        PUBWEAK EDMA1_CH31_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_CH31_IRQHandler
        LDR     R0, =EDMA1_CH31_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved478_IRQHandler
        PUBWEAK Reserved479_IRQHandler
        PUBWEAK Reserved480_IRQHandler
        PUBWEAK Reserved481_IRQHandler
        PUBWEAK Reserved482_IRQHandler
        PUBWEAK Reserved483_IRQHandler
        PUBWEAK Reserved484_IRQHandler
        PUBWEAK Reserved485_IRQHandler
        PUBWEAK Reserved486_IRQHandler
        PUBWEAK Reserved487_IRQHandler
        PUBWEAK Reserved488_IRQHandler
        PUBWEAK Reserved489_IRQHandler
        PUBWEAK Reserved490_IRQHandler
        PUBWEAK Reserved491_IRQHandler
        PUBWEAK Reserved492_IRQHandler
        PUBWEAK Reserved493_IRQHandler
        PUBWEAK Reserved494_IRQHandler
        PUBWEAK Reserved495_IRQHandler
        PUBWEAK Reserved496_IRQHandler
        PUBWEAK Reserved497_IRQHandler
        PUBWEAK Reserved498_IRQHandler
        PUBWEAK Reserved499_IRQHandler
        PUBWEAK Reserved500_IRQHandler
        PUBWEAK Reserved501_IRQHandler
        PUBWEAK Reserved502_IRQHandler
        PUBWEAK Reserved503_IRQHandler
        PUBWEAK Reserved504_IRQHandler
        PUBWEAK Reserved505_IRQHandler
        PUBWEAK Reserved506_IRQHandler
        PUBWEAK Reserved507_IRQHandler
        PUBWEAK Reserved508_IRQHandler
        PUBWEAK Reserved509_IRQHandler
        PUBWEAK MU1_A_IRQHandler
        PUBWEAK MU1_B_IRQHandler
        PUBWEAK MU2_A_IRQHandler
        PUBWEAK MU2_B_IRQHandler
        PUBWEAK MU3_A_IRQHandler
        PUBWEAK MU3_B_IRQHandler
        PUBWEAK MU4_A_IRQHandler
        PUBWEAK MU4_B_IRQHandler
        PUBWEAK MU5_B_IRQHandler
        PUBWEAK MU6_B_IRQHandler
        PUBWEAK MU7_B_IRQHandler
        PUBWEAK MU8_A_IRQHandler
        PUBWEAK MU8_B_IRQHandler
        PUBWEAK MU9_A_IRQHandler
        PUBWEAK MU9_B_IRQHandler
        PUBWEAK MU10_A_IRQHandler
        PUBWEAK Reserved526_IRQHandler
        PUBWEAK Reserved527_IRQHandler
        PUBWEAK Reserved528_IRQHandler
        PUBWEAK Reserved529_IRQHandler
        PUBWEAK Reserved530_IRQHandler
        PUBWEAK Reserved531_IRQHandler
        PUBWEAK Reserved532_IRQHandler
        PUBWEAK Reserved533_IRQHandler
        PUBWEAK Reserved534_IRQHandler
        PUBWEAK Reserved535_IRQHandler
        PUBWEAK Reserved536_IRQHandler
        PUBWEAK Reserved537_IRQHandler
        PUBWEAK Reserved538_IRQHandler
        PUBWEAK Reserved539_IRQHandler
        PUBWEAK Reserved540_IRQHandler
        PUBWEAK Reserved541_IRQHandler
        PUBWEAK Reserved542_IRQHandler
        PUBWEAK Reserved543_IRQHandler
        PUBWEAK Reserved544_IRQHandler
        PUBWEAK Reserved545_IRQHandler
        PUBWEAK Reserved546_IRQHandler
        PUBWEAK Reserved547_IRQHandler
        PUBWEAK Reserved548_IRQHandler
        PUBWEAK Reserved549_IRQHandler
        PUBWEAK Reserved550_IRQHandler
        PUBWEAK Reserved551_IRQHandler
        PUBWEAK Reserved552_IRQHandler
        PUBWEAK Reserved553_IRQHandler
        PUBWEAK Reserved554_IRQHandler
        PUBWEAK Reserved555_IRQHandler
        PUBWEAK Reserved556_IRQHandler
        PUBWEAK Reserved557_IRQHandler
        PUBWEAK Reserved558_IRQHandler
        PUBWEAK Reserved559_IRQHandler
        PUBWEAK Reserved560_IRQHandler
        PUBWEAK Reserved561_IRQHandler
        PUBWEAK Reserved562_IRQHandler
        PUBWEAK Reserved563_IRQHandler
        PUBWEAK Reserved564_IRQHandler
        PUBWEAK Reserved565_IRQHandler
        PUBWEAK Reserved566_IRQHandler
        PUBWEAK Reserved567_IRQHandler
        PUBWEAK Reserved568_IRQHandler
        PUBWEAK Reserved569_IRQHandler
        PUBWEAK Reserved570_IRQHandler
        PUBWEAK Reserved571_IRQHandler
        PUBWEAK Reserved572_IRQHandler
        PUBWEAK Reserved573_IRQHandler
        PUBWEAK MU11_A_IRQHandler
        PUBWEAK MU12_B_IRQHandler
        PUBWEAK MU13_B_IRQHandler
        PUBWEAK MU14_A_IRQHandler
        PUBWEAK MU14_B_IRQHandler
        PUBWEAK MU15_A_IRQHandler
        PUBWEAK MU15_B_IRQHandler
        PUBWEAK MU16_A_IRQHandler
        PUBWEAK MU16_B_IRQHandler
        PUBWEAK MU17_A_IRQHandler
        PUBWEAK MU17_B_IRQHandler
        PUBWEAK MU_E1_B_IRQHandler
        PUBWEAK MU_E2_B_IRQHandler
        PUBWEAK MU_E3_B_IRQHandler
        PUBWEAK MU_E4_B_IRQHandler
        PUBWEAK MSGINTR1_IRQHandler
        PUBWEAK Reserved590_IRQHandler
        PUBWEAK Reserved591_IRQHandler
        PUBWEAK Reserved592_IRQHandler
        PUBWEAK Reserved593_IRQHandler
        PUBWEAK Reserved594_IRQHandler
        PUBWEAK Reserved595_IRQHandler
        PUBWEAK Reserved596_IRQHandler
        PUBWEAK Reserved597_IRQHandler
        PUBWEAK Reserved598_IRQHandler
        PUBWEAK Reserved599_IRQHandler
        PUBWEAK Reserved600_IRQHandler
        PUBWEAK Reserved601_IRQHandler
        PUBWEAK Reserved602_IRQHandler
        PUBWEAK Reserved603_IRQHandler
        PUBWEAK Reserved604_IRQHandler
        PUBWEAK Reserved605_IRQHandler
        PUBWEAK Reserved606_IRQHandler
        PUBWEAK Reserved607_IRQHandler
        PUBWEAK Reserved608_IRQHandler
        PUBWEAK Reserved609_IRQHandler
        PUBWEAK Reserved610_IRQHandler
        PUBWEAK Reserved611_IRQHandler
        PUBWEAK Reserved612_IRQHandler
        PUBWEAK Reserved613_IRQHandler
        PUBWEAK Reserved614_IRQHandler
        PUBWEAK Reserved615_IRQHandler
        PUBWEAK Reserved616_IRQHandler
        PUBWEAK Reserved617_IRQHandler
        PUBWEAK Reserved618_IRQHandler
        PUBWEAK Reserved619_IRQHandler
        PUBWEAK Reserved620_IRQHandler
        PUBWEAK Reserved621_IRQHandler
        PUBWEAK Reserved622_IRQHandler
        PUBWEAK Reserved623_IRQHandler
        PUBWEAK Reserved624_IRQHandler
        PUBWEAK Reserved625_IRQHandler
        PUBWEAK Reserved626_IRQHandler
        PUBWEAK Reserved627_IRQHandler
        PUBWEAK Reserved628_IRQHandler
        PUBWEAK Reserved629_IRQHandler
        PUBWEAK Reserved630_IRQHandler
        PUBWEAK Reserved631_IRQHandler
        PUBWEAK Reserved632_IRQHandler
        PUBWEAK Reserved633_IRQHandler
        PUBWEAK Reserved634_IRQHandler
        PUBWEAK Reserved635_IRQHandler
        PUBWEAK Reserved636_IRQHandler
        PUBWEAK Reserved637_IRQHandler
        PUBWEAK MSGINTR2_IRQHandler
        PUBWEAK MSGINTR3_IRQHandler
        PUBWEAK MSGINTR4_IRQHandler
        PUBWEAK MSGINTR5_IRQHandler
        PUBWEAK MSGINTR6_IRQHandler
        PUBWEAK MSGINTR7_IRQHandler
        PUBWEAK MSGINTR8_IRQHandler
        PUBWEAK V2X_FH_APP1_IRQHandler
        PUBWEAK V2X_FH_HSM2_IRQHandler
        PUBWEAK S500_REQ1_IRQHandler
        PUBWEAK S500_REQ2_IRQHandler
        PUBWEAK S500_REQ3_IRQHandler
        PUBWEAK S500_REQ4_IRQHandler
        PUBWEAK S500_GLUE_IRQHandler
        PUBWEAK GPC_SM_REQ_IRQHandler
        PUBWEAK EDMA1_ERROR_IRQHandler
        PUBWEAK EDMA1_ERROR_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
EDMA1_ERROR_IRQHandler
        LDR     R0, =EDMA1_ERROR_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved654_IRQHandler
        PUBWEAK Reserved655_IRQHandler
        PUBWEAK Reserved656_IRQHandler
        PUBWEAK Reserved657_IRQHandler
        PUBWEAK Reserved658_IRQHandler
        PUBWEAK Reserved659_IRQHandler
        PUBWEAK Reserved660_IRQHandler
        PUBWEAK Reserved661_IRQHandler
        PUBWEAK Reserved662_IRQHandler
        PUBWEAK Reserved663_IRQHandler
        PUBWEAK Reserved664_IRQHandler
        PUBWEAK Reserved665_IRQHandler
        PUBWEAK Reserved666_IRQHandler
        PUBWEAK Reserved667_IRQHandler
        PUBWEAK Reserved668_IRQHandler
        PUBWEAK Reserved669_IRQHandler
        PUBWEAK Reserved670_IRQHandler
        PUBWEAK Reserved671_IRQHandler
        PUBWEAK Reserved672_IRQHandler
        PUBWEAK Reserved673_IRQHandler
        PUBWEAK Reserved674_IRQHandler
        PUBWEAK Reserved675_IRQHandler
        PUBWEAK Reserved676_IRQHandler
        PUBWEAK Reserved677_IRQHandler
        PUBWEAK Reserved678_IRQHandler
        PUBWEAK Reserved679_IRQHandler
        PUBWEAK Reserved680_IRQHandler
        PUBWEAK Reserved681_IRQHandler
        PUBWEAK Reserved682_IRQHandler
        PUBWEAK Reserved683_IRQHandler
        PUBWEAK Reserved684_IRQHandler
        PUBWEAK Reserved685_IRQHandler
        PUBWEAK Reserved686_IRQHandler
        PUBWEAK Reserved687_IRQHandler
        PUBWEAK Reserved688_IRQHandler
        PUBWEAK Reserved689_IRQHandler
        PUBWEAK Reserved690_IRQHandler
        PUBWEAK Reserved691_IRQHandler
        PUBWEAK Reserved692_IRQHandler
        PUBWEAK Reserved693_IRQHandler
        PUBWEAK Reserved694_IRQHandler
        PUBWEAK Reserved695_IRQHandler
        PUBWEAK Reserved696_IRQHandler
        PUBWEAK Reserved697_IRQHandler
        PUBWEAK Reserved698_IRQHandler
        PUBWEAK Reserved699_IRQHandler
        PUBWEAK Reserved700_IRQHandler
        PUBWEAK Reserved701_IRQHandler
        PUBWEAK Reserved702_IRQHandler
        PUBWEAK Reserved703_IRQHandler
        PUBWEAK Reserved704_IRQHandler
        PUBWEAK Reserved705_IRQHandler
        PUBWEAK Reserved706_IRQHandler
        PUBWEAK Reserved707_IRQHandler
        PUBWEAK Reserved708_IRQHandler
        PUBWEAK Reserved709_IRQHandler
        PUBWEAK Reserved710_IRQHandler
        PUBWEAK Reserved711_IRQHandler
        PUBWEAK Reserved712_IRQHandler
        PUBWEAK Reserved713_IRQHandler
        PUBWEAK Reserved714_IRQHandler
        PUBWEAK Reserved715_IRQHandler
        PUBWEAK Reserved716_IRQHandler
        PUBWEAK Reserved717_IRQHandler
        PUBWEAK Reserved718_IRQHandler
        PUBWEAK Reserved719_IRQHandler
        PUBWEAK Reserved720_IRQHandler
        PUBWEAK Reserved721_IRQHandler
        PUBWEAK Reserved722_IRQHandler
        PUBWEAK Reserved723_IRQHandler
        PUBWEAK Reserved724_IRQHandler
        PUBWEAK Reserved725_IRQHandler
        PUBWEAK Reserved726_IRQHandler
        PUBWEAK Reserved727_IRQHandler
        PUBWEAK Reserved728_IRQHandler
        PUBWEAK Reserved729_IRQHandler
        PUBWEAK Reserved730_IRQHandler
        PUBWEAK Reserved731_IRQHandler
        PUBWEAK Reserved732_IRQHandler
        PUBWEAK Reserved733_IRQHandler
        PUBWEAK Reserved734_IRQHandler
        PUBWEAK Reserved735_IRQHandler
        PUBWEAK Reserved736_IRQHandler
        PUBWEAK Reserved737_IRQHandler
        PUBWEAK Reserved738_IRQHandler
        PUBWEAK Reserved739_IRQHandler
        PUBWEAK Reserved740_IRQHandler
        PUBWEAK Reserved741_IRQHandler
        PUBWEAK Reserved742_IRQHandler
        PUBWEAK Reserved743_IRQHandler
        PUBWEAK Reserved744_IRQHandler
        PUBWEAK Reserved745_IRQHandler
        PUBWEAK Reserved746_IRQHandler
        PUBWEAK Reserved747_IRQHandler
        PUBWEAK Reserved748_IRQHandler
        PUBWEAK Reserved749_IRQHandler
        PUBWEAK Reserved750_IRQHandler
        PUBWEAK Reserved751_IRQHandler
        PUBWEAK Reserved752_IRQHandler
        PUBWEAK Reserved753_IRQHandler
        PUBWEAK Reserved754_IRQHandler
        PUBWEAK Reserved755_IRQHandler
        PUBWEAK Reserved756_IRQHandler
        PUBWEAK Reserved757_IRQHandler
        PUBWEAK Reserved758_IRQHandler
        PUBWEAK Reserved759_IRQHandler
        PUBWEAK Reserved760_IRQHandler
        PUBWEAK Reserved761_IRQHandler
        PUBWEAK Reserved762_IRQHandler
        PUBWEAK Reserved763_IRQHandler
        PUBWEAK Reserved764_IRQHandler
        PUBWEAK Reserved765_IRQHandler
        PUBWEAK Reserved766_IRQHandler
        PUBWEAK Reserved767_IRQHandler
        PUBWEAK Reserved768_IRQHandler
        PUBWEAK Reserved769_IRQHandler
        PUBWEAK Reserved770_IRQHandler
        PUBWEAK Reserved771_IRQHandler
        PUBWEAK Reserved772_IRQHandler
        PUBWEAK Reserved773_IRQHandler
        PUBWEAK Reserved774_IRQHandler
        PUBWEAK Reserved775_IRQHandler
        PUBWEAK Reserved776_IRQHandler
        PUBWEAK Reserved777_IRQHandler
        PUBWEAK Reserved778_IRQHandler
        PUBWEAK Reserved779_IRQHandler
        PUBWEAK Reserved780_IRQHandler
        PUBWEAK Reserved781_IRQHandler
        PUBWEAK Reserved782_IRQHandler
        PUBWEAK Reserved783_IRQHandler
        PUBWEAK Reserved784_IRQHandler
        PUBWEAK Reserved785_IRQHandler
        PUBWEAK Reserved786_IRQHandler
        PUBWEAK Reserved787_IRQHandler
        PUBWEAK Reserved788_IRQHandler
        PUBWEAK Reserved789_IRQHandler
        PUBWEAK Reserved790_IRQHandler
        PUBWEAK Reserved791_IRQHandler
        PUBWEAK Reserved792_IRQHandler
        PUBWEAK Reserved793_IRQHandler
        PUBWEAK Reserved794_IRQHandler
        PUBWEAK Reserved795_IRQHandler
        PUBWEAK Reserved796_IRQHandler
        PUBWEAK Reserved797_IRQHandler
        PUBWEAK Reserved798_IRQHandler
        PUBWEAK Reserved799_IRQHandler
        PUBWEAK Reserved800_IRQHandler
        PUBWEAK Reserved801_IRQHandler
        PUBWEAK Reserved802_IRQHandler
        PUBWEAK Reserved803_IRQHandler
        PUBWEAK Reserved804_IRQHandler
        PUBWEAK Reserved805_IRQHandler
        PUBWEAK Reserved806_IRQHandler
        PUBWEAK Reserved807_IRQHandler
        PUBWEAK Reserved808_IRQHandler
        PUBWEAK Reserved809_IRQHandler
        PUBWEAK Reserved810_IRQHandler
        PUBWEAK Reserved811_IRQHandler
        PUBWEAK Reserved812_IRQHandler
        PUBWEAK Reserved813_IRQHandler
        PUBWEAK Reserved814_IRQHandler
        PUBWEAK Reserved815_IRQHandler
        PUBWEAK Reserved816_IRQHandler
        PUBWEAK Reserved817_IRQHandler
        PUBWEAK Reserved818_IRQHandler
        PUBWEAK Reserved819_IRQHandler
        PUBWEAK Reserved820_IRQHandler
        PUBWEAK Reserved821_IRQHandler
        PUBWEAK Reserved822_IRQHandler
        PUBWEAK Reserved823_IRQHandler
        PUBWEAK Reserved824_IRQHandler
        PUBWEAK Reserved825_IRQHandler
        PUBWEAK Reserved826_IRQHandler
        PUBWEAK Reserved827_IRQHandler
        PUBWEAK Reserved828_IRQHandler
        PUBWEAK Reserved829_IRQHandler
        PUBWEAK Reserved830_IRQHandler
        PUBWEAK TMPSNS_THR1_IRQHandler
        PUBWEAK TMPSNS_THR2_IRQHandler
        PUBWEAK Reserved833_IRQHandler
        PUBWEAK Reserved834_IRQHandler
        PUBWEAK Reserved835_IRQHandler
        PUBWEAK Reserved836_IRQHandler
        PUBWEAK CM33_0_SYSRESETREQ_IRQHandler
        PUBWEAK CM33_0_LOCKUP_IRQHandler
        PUBWEAK CM7_0_SYSRESETREQ_IRQHandler
        PUBWEAK CM7_0_LOCKUP_IRQHandler
        PUBWEAK CM33_1_SYSRESETREQ_IRQHandler
        PUBWEAK CM33_1_LOCKUP_IRQHandler
        PUBWEAK CM7_1_SYSRESETREQ_IRQHandler
        PUBWEAK CM7_1_LOCKUP_IRQHandler
        PUBWEAK Reserved845_IRQHandler
        PUBWEAK Reserved846_IRQHandler
        PUBWEAK Reserved847_IRQHandler
        PUBWEAK Reserved848_IRQHandler
        PUBWEAK Reserved849_IRQHandler
        PUBWEAK Reserved850_IRQHandler
        PUBWEAK Reserved851_IRQHandler
        PUBWEAK Reserved852_IRQHandler
        PUBWEAK Reserved853_IRQHandler
        PUBWEAK Reserved854_IRQHandler
        PUBWEAK Reserved855_IRQHandler
        PUBWEAK Reserved856_IRQHandler
        PUBWEAK Reserved857_IRQHandler
        PUBWEAK Reserved858_IRQHandler
        PUBWEAK Reserved859_IRQHandler
        PUBWEAK Reserved860_IRQHandler
        PUBWEAK Reserved861_IRQHandler
        PUBWEAK Reserved862_IRQHandler
        PUBWEAK Reserved863_IRQHandler
        PUBWEAK Reserved864_IRQHandler
        PUBWEAK Reserved865_IRQHandler
        PUBWEAK Reserved866_IRQHandler
        PUBWEAK Reserved867_IRQHandler
        PUBWEAK Reserved868_IRQHandler
        PUBWEAK Reserved869_IRQHandler
        PUBWEAK Reserved870_IRQHandler
        PUBWEAK Reserved871_IRQHandler
        PUBWEAK Reserved872_IRQHandler
        PUBWEAK Reserved873_IRQHandler
        PUBWEAK Reserved874_IRQHandler
        PUBWEAK Reserved875_IRQHandler
        PUBWEAK Reserved876_IRQHandler
        PUBWEAK Reserved877_IRQHandler
        PUBWEAK Reserved878_IRQHandler
        PUBWEAK Reserved879_IRQHandler
        PUBWEAK Reserved880_IRQHandler
        PUBWEAK Reserved881_IRQHandler
        PUBWEAK Reserved882_IRQHandler
        PUBWEAK Reserved883_IRQHandler
        PUBWEAK Reserved884_IRQHandler
        PUBWEAK Reserved885_IRQHandler
        PUBWEAK Reserved886_IRQHandler
        PUBWEAK Reserved887_IRQHandler
        PUBWEAK Reserved888_IRQHandler
        PUBWEAK Reserved889_IRQHandler
        PUBWEAK Reserved890_IRQHandler
        PUBWEAK Reserved891_IRQHandler
        PUBWEAK Reserved892_IRQHandler
        PUBWEAK Reserved893_IRQHandler
        PUBWEAK Reserved894_IRQHandler
        PUBWEAK Reserved895_IRQHandler
        PUBWEAK Reserved896_IRQHandler
        PUBWEAK Reserved897_IRQHandler
        PUBWEAK Reserved898_IRQHandler
        PUBWEAK Reserved899_IRQHandler
        PUBWEAK Reserved900_IRQHandler
        PUBWEAK Reserved901_IRQHandler
        PUBWEAK Reserved902_IRQHandler
        PUBWEAK Reserved903_IRQHandler
        PUBWEAK Reserved904_IRQHandler
        PUBWEAK Reserved905_IRQHandler
        PUBWEAK Reserved906_IRQHandler
        PUBWEAK Reserved907_IRQHandler
        PUBWEAK Reserved908_IRQHandler
        PUBWEAK Reserved909_IRQHandler
        PUBWEAK Reserved910_IRQHandler
        PUBWEAK Reserved911_IRQHandler
        PUBWEAK Reserved912_IRQHandler
        PUBWEAK Reserved913_IRQHandler
        PUBWEAK Reserved914_IRQHandler
        PUBWEAK Reserved915_IRQHandler
        PUBWEAK Reserved916_IRQHandler
        PUBWEAK Reserved917_IRQHandler
        PUBWEAK Reserved918_IRQHandler
        PUBWEAK Reserved919_IRQHandler
        PUBWEAK Reserved920_IRQHandler
        PUBWEAK Reserved921_IRQHandler
        PUBWEAK Reserved922_IRQHandler
        PUBWEAK Reserved923_IRQHandler
        PUBWEAK Reserved924_IRQHandler
        PUBWEAK Reserved925_IRQHandler
        PUBWEAK Reserved926_IRQHandler
        PUBWEAK Reserved927_IRQHandler
        PUBWEAK Reserved928_IRQHandler
        PUBWEAK Reserved929_IRQHandler
        PUBWEAK Reserved930_IRQHandler
        PUBWEAK Reserved931_IRQHandler
        PUBWEAK Reserved932_IRQHandler
        PUBWEAK Reserved933_IRQHandler
        PUBWEAK Reserved934_IRQHandler
        PUBWEAK Reserved935_IRQHandler
        PUBWEAK Reserved936_IRQHandler
        PUBWEAK Reserved937_IRQHandler
        PUBWEAK Reserved938_IRQHandler
        PUBWEAK Reserved939_IRQHandler
        PUBWEAK Reserved940_IRQHandler
        PUBWEAK Reserved941_IRQHandler
        PUBWEAK Reserved942_IRQHandler
        PUBWEAK Reserved943_IRQHandler
        PUBWEAK Reserved944_IRQHandler
        PUBWEAK Reserved945_IRQHandler
        PUBWEAK Reserved946_IRQHandler
        PUBWEAK Reserved947_IRQHandler
        PUBWEAK Reserved948_IRQHandler
        PUBWEAK Reserved949_IRQHandler
        PUBWEAK Reserved950_IRQHandler
        PUBWEAK Reserved951_IRQHandler
        PUBWEAK Reserved952_IRQHandler
        PUBWEAK Reserved953_IRQHandler
        PUBWEAK Reserved954_IRQHandler
        PUBWEAK Reserved955_IRQHandler
        PUBWEAK Reserved956_IRQHandler
        PUBWEAK Reserved957_IRQHandler
        PUBWEAK Reserved958_IRQHandler
        PUBWEAK Reserved959_IRQHandler
        PUBWEAK Reserved960_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN0_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN1_IRQHandler
        PUBWEAK DCIF_CPU_DOMAIN2_IRQHandler
        PUBWEAK Reserved964_IRQHandler
        PUBWEAK Reserved965_IRQHandler
        PUBWEAK PXP_0_IRQHandler
        PUBWEAK PXP_1_IRQHandler
        PUBWEAK Reserved968_IRQHandler
        PUBWEAK Reserved969_IRQHandler
        PUBWEAK Reserved970_IRQHandler
        PUBWEAK Reserved971_IRQHandler
        PUBWEAK Reserved972_IRQHandler
        PUBWEAK Reserved973_IRQHandler
        PUBWEAK Reserved974_IRQHandler
        PUBWEAK Reserved975_IRQHandler
        PUBWEAK Reserved976_IRQHandler
        PUBWEAK Reserved977_IRQHandler
        PUBWEAK Reserved978_IRQHandler
        PUBWEAK Reserved979_IRQHandler
        PUBWEAK Reserved980_IRQHandler
        PUBWEAK Reserved981_IRQHandler
        PUBWEAK Reserved982_IRQHandler
        PUBWEAK Reserved983_IRQHandler
        PUBWEAK Reserved984_IRQHandler
        PUBWEAK Reserved985_IRQHandler
        PUBWEAK Reserved986_IRQHandler
        PUBWEAK Reserved987_IRQHandler
        PUBWEAK Reserved988_IRQHandler
        PUBWEAK Reserved989_IRQHandler
        PUBWEAK Reserved990_IRQHandler
        PUBWEAK Reserved991_IRQHandler
        PUBWEAK Reserved992_IRQHandler
        PUBWEAK Reserved993_IRQHandler
        PUBWEAK Reserved994_IRQHandler
        PUBWEAK Reserved995_IRQHandler
        PUBWEAK Reserved996_IRQHandler
        PUBWEAK Reserved997_IRQHandler
        PUBWEAK Reserved998_IRQHandler
        PUBWEAK Reserved999_IRQHandler
        PUBWEAK Reserved1000_IRQHandler
        PUBWEAK Reserved1001_IRQHandler
        PUBWEAK Reserved1002_IRQHandler
        PUBWEAK Reserved1003_IRQHandler
        PUBWEAK Reserved1004_IRQHandler
        PUBWEAK Reserved1005_IRQHandler
        PUBWEAK Reserved1006_IRQHandler
        PUBWEAK Reserved1007_IRQHandler
        PUBWEAK Reserved1008_IRQHandler
        PUBWEAK Reserved1009_IRQHandler
        PUBWEAK Reserved1010_IRQHandler
        PUBWEAK Reserved1011_IRQHandler
        PUBWEAK Reserved1012_IRQHandler
        PUBWEAK Reserved1013_IRQHandler
        PUBWEAK Reserved1014_IRQHandler
        PUBWEAK Reserved1015_IRQHandler
        PUBWEAK Reserved1016_IRQHandler
        PUBWEAK Reserved1017_IRQHandler
        PUBWEAK Reserved1018_IRQHandler
        PUBWEAK Reserved1019_IRQHandler
        PUBWEAK Reserved1020_IRQHandler
        PUBWEAK Reserved1021_IRQHandler
        PUBWEAK XSPI1_IRQHandler
        PUBWEAK XSPI1_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
XSPI1_IRQHandler
        LDR     R0, =XSPI1_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved1023_IRQHandler
        PUBWEAK Reserved1024_IRQHandler
        PUBWEAK Reserved1025_IRQHandler
        PUBWEAK Reserved1026_IRQHandler
        PUBWEAK XSPI2_IRQHandler
        PUBWEAK XSPI2_DriverIRQHandler
        SECTION .text:CODE:REORDER:NOROOT(2)
XSPI2_IRQHandler
        LDR     R0, =XSPI2_DriverIRQHandler
        BX      R0

        PUBWEAK Reserved1028_IRQHandler
        PUBWEAK Reserved1029_IRQHandler
        PUBWEAK Reserved1030_IRQHandler
        PUBWEAK Reserved1031_IRQHandler
        PUBWEAK Reserved1032_IRQHandler
        PUBWEAK Reserved1033_IRQHandler
        PUBWEAK Reserved1034_IRQHandler
        PUBWEAK Reserved1035_IRQHandler
        PUBWEAK Reserved1036_IRQHandler
        PUBWEAK Reserved1037_IRQHandler
        PUBWEAK Reserved1038_IRQHandler
        PUBWEAK Reserved1039_IRQHandler
        PUBWEAK Reserved1040_IRQHandler
        PUBWEAK Reserved1041_IRQHandler
        PUBWEAK Reserved1042_IRQHandler
        PUBWEAK Reserved1043_IRQHandler
        PUBWEAK Reserved1044_IRQHandler
        PUBWEAK Reserved1045_IRQHandler
        PUBWEAK Reserved1046_IRQHandler
        PUBWEAK Reserved1047_IRQHandler
        PUBWEAK Reserved1048_IRQHandler
        PUBWEAK Reserved1049_IRQHandler
        PUBWEAK Reserved1050_IRQHandler
        PUBWEAK Reserved1051_IRQHandler
        PUBWEAK Reserved1052_IRQHandler
        PUBWEAK Reserved1053_IRQHandler
        PUBWEAK Reserved1054_IRQHandler
        PUBWEAK Reserved1055_IRQHandler
        PUBWEAK Reserved1056_IRQHandler
        PUBWEAK Reserved1057_IRQHandler
        PUBWEAK Reserved1058_IRQHandler
        PUBWEAK Reserved1059_IRQHandler
        PUBWEAK Reserved1060_IRQHandler
        PUBWEAK Reserved1061_IRQHandler
        PUBWEAK Reserved1062_IRQHandler
        PUBWEAK Reserved1063_IRQHandler
        PUBWEAK Reserved1064_IRQHandler
        PUBWEAK Reserved1065_IRQHandler
        PUBWEAK Reserved1066_IRQHandler
        PUBWEAK Reserved1067_IRQHandler
        PUBWEAK Reserved1068_IRQHandler
        PUBWEAK Reserved1069_IRQHandler
        PUBWEAK Reserved1070_IRQHandler
        PUBWEAK Reserved1071_IRQHandler
        PUBWEAK Reserved1072_IRQHandler
        PUBWEAK Reserved1073_IRQHandler
        PUBWEAK Reserved1074_IRQHandler
        PUBWEAK Reserved1075_IRQHandler
        PUBWEAK Reserved1076_IRQHandler
        PUBWEAK Reserved1077_IRQHandler
        PUBWEAK Reserved1078_IRQHandler
        PUBWEAK Reserved1079_IRQHandler
        PUBWEAK Reserved1080_IRQHandler
        PUBWEAK Reserved1081_IRQHandler
        PUBWEAK Reserved1082_IRQHandler
        PUBWEAK Reserved1083_IRQHandler
        PUBWEAK Reserved1084_IRQHandler
        PUBWEAK Reserved1085_IRQHandler
        PUBWEAK DefaultISR
        SECTION .text:CODE:REORDER:NOROOT(1)
Reserved16_IRQHandler
Reserved17_IRQHandler
Reserved18_IRQHandler
Reserved19_IRQHandler
Reserved20_IRQHandler
Reserved21_IRQHandler
Reserved22_IRQHandler
Reserved23_IRQHandler
Reserved24_IRQHandler
Reserved25_IRQHandler
CAN1_DriverIRQHandler
CAN1_ERROR_DriverIRQHandler
GPIO1_INT0_IRQHandler
GPIO1_INT1_IRQHandler
I3C1_DriverIRQHandler
LPI2C1_DriverIRQHandler
LPI2C2_DriverIRQHandler
LPIT1_IRQHandler
LPSPI1_DriverIRQHandler
LPSPI2_DriverIRQHandler
LPTMR1_IRQHandler
LPUART1_DriverIRQHandler
LPUART2_DriverIRQHandler
Reserved39_IRQHandler
Reserved40_IRQHandler
Reserved41_IRQHandler
Reserved42_IRQHandler
Reserved43_IRQHandler
Reserved44_IRQHandler
Reserved45_IRQHandler
Reserved46_IRQHandler
Reserved47_IRQHandler
V2X_FH_APCH0_IRQHandler
V2X_FH_APHSM1_IRQHandler
TPM1_IRQHandler
TPM2_IRQHandler
WDOG1_IRQHandler
WDOG2_IRQHandler
SAI1_DriverIRQHandler
GPT1_IRQHandler
CAN2_DriverIRQHandler
CAN2_ERROR_DriverIRQHandler
CAN3_DriverIRQHandler
CAN3_ERROR_DriverIRQHandler
CAN4_DriverIRQHandler
CAN4_ERROR_DriverIRQHandler
CAN5_DriverIRQHandler
CAN5_ERROR_DriverIRQHandler
FLEXIO1_DriverIRQHandler
FLEXIO2_DriverIRQHandler
FLEXIO3_DriverIRQHandler
FLEXIO4_DriverIRQHandler
Reserved68_IRQHandler
Reserved69_IRQHandler
GPIO2_INT0_IRQHandler
GPIO2_INT1_IRQHandler
GPIO3_INT0_IRQHandler
GPIO3_INT1_IRQHandler
GPIO4_INT0_IRQHandler
GPIO4_INT1_IRQHandler
GPIO5_INT0_IRQHandler
GPIO5_INT1_IRQHandler
GPIO6_INT0_IRQHandler
GPIO6_INT1_IRQHandler
GPIO7_INT0_IRQHandler
GPIO7_INT1_IRQHandler
I3C2_DriverIRQHandler
LPI2C3_DriverIRQHandler
LPI2C4_DriverIRQHandler
LPIT2_IRQHandler
LPIT3_IRQHandler
LPSPI3_DriverIRQHandler
LPSPI4_DriverIRQHandler
LPTMR2_IRQHandler
LPUART3_DriverIRQHandler
LPUART4_DriverIRQHandler
LPUART5_DriverIRQHandler
LPUART6_DriverIRQHandler
LPUART7_DriverIRQHandler
LPUART8_DriverIRQHandler
LPUART9_DriverIRQHandler
LPUART10_DriverIRQHandler
LPUART11_DriverIRQHandler
LPUART12_DriverIRQHandler
BBNSM_IRQHandler
SYSCTR1_IRQHandler
TPM3_IRQHandler
TPM4_IRQHandler
TPM5_IRQHandler
TPM6_IRQHandler
WDOG3_IRQHandler
WDOG4_IRQHandler
WDOG5_IRQHandler
WDOG6_IRQHandler
WDOG7_IRQHandler
WDOG8_IRQHandler
USDHC1_DriverIRQHandler
USDHC2_DriverIRQHandler
EDMA2_ERROR_DriverIRQHandler
Reserved115_IRQHandler
Reserved116_IRQHandler
SAI2_DriverIRQHandler
SAI3_DriverIRQHandler
SAI4_DriverIRQHandler
LPSPI5_DriverIRQHandler
LPSPI6_DriverIRQHandler
LPSPI7_DriverIRQHandler
LPSPI8_DriverIRQHandler
LPI2C5_DriverIRQHandler
LPI2C6_DriverIRQHandler
LPI2C7_DriverIRQHandler
LPI2C8_DriverIRQHandler
PDM_HWVAD_ERROR_IRQHandler
PDM_HWVAD_EVENT_IRQHandler
PDM_ERROR_IRQHandler
PDM_EVENT_DriverIRQHandler
USDHC3_DriverIRQHandler
ADC_ER_IRQHandler
ADC_WD_IRQHandler
ADC_EOC_IRQHandler
Reserved136_IRQHandler
Reserved137_IRQHandler
MU5_A_IRQHandler
MU6_A_IRQHandler
MU7_A_IRQHandler
MU10_B_IRQHandler
MU11_B_IRQHandler
MU12_A_IRQHandler
MU13_A_IRQHandler
MU18_A_IRQHandler
MU18_B_IRQHandler
MU_E1_A_IRQHandler
MU_E2_A_IRQHandler
MU_E3_A_IRQHandler
MU_E4_A_IRQHandler
XSPI_SLV_DriverIRQHandler
FCCU_INT0_IRQHandler
FCCU_INT1_IRQHandler
FCCU_INT2_IRQHandler
FCCU_INT3_IRQHandler
FCCU_INT4_IRQHandler
STCU_IRQHandler
XBAR1_CH0_CH1_IRQHandler
XBAR1_CH2_CH3_IRQHandler
GPT2_IRQHandler
GPT3_IRQHandler
GPT4_IRQHandler
Reserved163_IRQHandler
Reserved164_IRQHandler
Reserved165_IRQHandler
Reserved166_IRQHandler
Reserved167_IRQHandler
Reserved168_IRQHandler
Reserved169_IRQHandler
Reserved170_IRQHandler
Reserved171_IRQHandler
Reserved172_IRQHandler
Reserved173_IRQHandler
Reserved174_IRQHandler
Reserved175_IRQHandler
Reserved176_IRQHandler
Reserved177_IRQHandler
Reserved178_IRQHandler
Reserved179_IRQHandler
Reserved180_IRQHandler
Reserved181_IRQHandler
Reserved182_IRQHandler
Reserved183_IRQHandler
Reserved184_IRQHandler
Reserved185_IRQHandler
Reserved186_IRQHandler
ENC1_IRQHandler
ENC2_IRQHandler
ENC3_IRQHandler
ENC4_IRQHandler
EWM_IRQHandler
Reserved192_IRQHandler
Reserved193_IRQHandler
Reserved194_IRQHandler
Reserved195_IRQHandler
USB1_IRQHandler
USB2_IRQHandler
SINC1_CH0_IRQHandler
SINC1_CH1_IRQHandler
SINC1_CH2_IRQHandler
SINC1_CH3_IRQHandler
SINC2_CH0_IRQHandler
SINC2_CH1_IRQHandler
SINC2_CH2_IRQHandler
SINC2_CH3_IRQHandler
SINC3_CH0_IRQHandler
SINC3_CH1_IRQHandler
SINC3_CH2_IRQHandler
SINC3_CH3_IRQHandler
SINC4_CH0_IRQHandler
SINC4_CH1_IRQHandler
SINC4_CH2_IRQHandler
SINC4_CH3_IRQHandler
TMR1_IRQHandler
TMR2_IRQHandler
TMR3_IRQHandler
TMR4_IRQHandler
TMR5_IRQHandler
TMR6_IRQHandler
TMR7_IRQHandler
TMR8_IRQHandler
EDMA4_ERROR_DriverIRQHandler
Reserved223_IRQHandler
Reserved224_IRQHandler
Reserved225_IRQHandler
Reserved226_IRQHandler
Reserved227_IRQHandler
Reserved228_IRQHandler
Reserved229_IRQHandler
Reserved230_IRQHandler
Reserved231_IRQHandler
Reserved232_IRQHandler
Reserved233_IRQHandler
Reserved234_IRQHandler
Reserved235_IRQHandler
Reserved236_IRQHandler
Reserved237_IRQHandler
Reserved238_IRQHandler
Reserved239_IRQHandler
IRQSTEERM7_CH0_DriverIRQHandler
IRQSTEERM7_CH1_DriverIRQHandler
IRQSTEERM7_CH2_DriverIRQHandler
IRQSTEERM7_CH3_DriverIRQHandler
IRQSTEERM7_CH4_DriverIRQHandler
IRQSTEERM7_CH5_DriverIRQHandler
IRQSTEERM7_CH6_DriverIRQHandler
IRQSTEERM7_CH7_DriverIRQHandler
IRQSTEERM7_CH8_DriverIRQHandler
IRQSTEERM7_CH9_DriverIRQHandler
IRQSTEERM7_CH10_DriverIRQHandler
IRQSTEERM7_CH11_DriverIRQHandler
IRQSTEERM7_CH12_DriverIRQHandler
Reserved253_IRQHandler
EDMA2_CH0_DriverIRQHandler
EDMA2_CH1_DriverIRQHandler
EDMA2_CH2_DriverIRQHandler
EDMA2_CH3_DriverIRQHandler
EDMA2_CH4_DriverIRQHandler
EDMA2_CH5_DriverIRQHandler
EDMA2_CH6_DriverIRQHandler
EDMA2_CH7_DriverIRQHandler
EDMA2_CH8_DriverIRQHandler
EDMA2_CH9_DriverIRQHandler
EDMA2_CH10_DriverIRQHandler
EDMA2_CH11_DriverIRQHandler
EDMA2_CH12_DriverIRQHandler
EDMA2_CH13_DriverIRQHandler
EDMA2_CH14_DriverIRQHandler
EDMA2_CH15_DriverIRQHandler
EDMA2_CH16_DriverIRQHandler
EDMA2_CH17_DriverIRQHandler
EDMA2_CH18_DriverIRQHandler
EDMA2_CH19_DriverIRQHandler
EDMA2_CH20_DriverIRQHandler
EDMA2_CH21_DriverIRQHandler
EDMA2_CH22_DriverIRQHandler
EDMA2_CH23_DriverIRQHandler
EDMA2_CH24_DriverIRQHandler
EDMA2_CH25_DriverIRQHandler
EDMA2_CH26_DriverIRQHandler
EDMA2_CH27_DriverIRQHandler
EDMA2_CH28_DriverIRQHandler
EDMA2_CH29_DriverIRQHandler
EDMA2_CH30_DriverIRQHandler
EDMA2_CH31_DriverIRQHandler
EDMA2_CH32_DriverIRQHandler
EDMA2_CH33_DriverIRQHandler
EDMA2_CH34_DriverIRQHandler
EDMA2_CH35_DriverIRQHandler
EDMA2_CH36_DriverIRQHandler
EDMA2_CH37_DriverIRQHandler
EDMA2_CH38_DriverIRQHandler
EDMA2_CH39_DriverIRQHandler
EDMA2_CH40_DriverIRQHandler
EDMA2_CH41_DriverIRQHandler
EDMA2_CH42_DriverIRQHandler
EDMA2_CH43_DriverIRQHandler
EDMA2_CH44_DriverIRQHandler
EDMA2_CH45_DriverIRQHandler
EDMA2_CH46_DriverIRQHandler
EDMA2_CH47_DriverIRQHandler
EDMA2_CH48_DriverIRQHandler
EDMA2_CH49_DriverIRQHandler
EDMA2_CH50_DriverIRQHandler
EDMA2_CH51_DriverIRQHandler
EDMA2_CH52_DriverIRQHandler
EDMA2_CH53_DriverIRQHandler
EDMA2_CH54_DriverIRQHandler
EDMA2_CH55_DriverIRQHandler
EDMA2_CH56_DriverIRQHandler
EDMA2_CH57_DriverIRQHandler
EDMA2_CH58_DriverIRQHandler
EDMA2_CH59_DriverIRQHandler
EDMA2_CH60_DriverIRQHandler
EDMA2_CH61_DriverIRQHandler
EDMA2_CH62_DriverIRQHandler
EDMA2_CH63_DriverIRQHandler
EDMA4_CH0_DriverIRQHandler
EDMA4_CH1_DriverIRQHandler
EDMA4_CH2_DriverIRQHandler
EDMA4_CH3_DriverIRQHandler
EDMA4_CH4_DriverIRQHandler
EDMA4_CH5_DriverIRQHandler
EDMA4_CH6_DriverIRQHandler
EDMA4_CH7_DriverIRQHandler
EDMA4_CH8_DriverIRQHandler
EDMA4_CH9_DriverIRQHandler
EDMA4_CH10_DriverIRQHandler
EDMA4_CH11_DriverIRQHandler
EDMA4_CH12_DriverIRQHandler
EDMA4_CH13_DriverIRQHandler
EDMA4_CH14_DriverIRQHandler
EDMA4_CH15_DriverIRQHandler
EDMA4_CH16_DriverIRQHandler
EDMA4_CH17_DriverIRQHandler
EDMA4_CH18_DriverIRQHandler
EDMA4_CH19_DriverIRQHandler
EDMA4_CH20_DriverIRQHandler
EDMA4_CH21_DriverIRQHandler
EDMA4_CH22_DriverIRQHandler
EDMA4_CH23_DriverIRQHandler
EDMA4_CH24_DriverIRQHandler
EDMA4_CH25_DriverIRQHandler
EDMA4_CH26_DriverIRQHandler
EDMA4_CH27_DriverIRQHandler
EDMA4_CH28_DriverIRQHandler
EDMA4_CH29_DriverIRQHandler
EDMA4_CH30_DriverIRQHandler
EDMA4_CH31_DriverIRQHandler
EDMA4_CH32_DriverIRQHandler
EDMA4_CH33_DriverIRQHandler
EDMA4_CH34_DriverIRQHandler
EDMA4_CH35_DriverIRQHandler
EDMA4_CH36_DriverIRQHandler
EDMA4_CH37_DriverIRQHandler
EDMA4_CH38_DriverIRQHandler
EDMA4_CH39_DriverIRQHandler
EDMA4_CH40_DriverIRQHandler
EDMA4_CH41_DriverIRQHandler
EDMA4_CH42_DriverIRQHandler
EDMA4_CH43_DriverIRQHandler
EDMA4_CH44_DriverIRQHandler
EDMA4_CH45_DriverIRQHandler
EDMA4_CH46_DriverIRQHandler
EDMA4_CH47_DriverIRQHandler
EDMA4_CH48_DriverIRQHandler
EDMA4_CH49_DriverIRQHandler
EDMA4_CH50_DriverIRQHandler
EDMA4_CH51_DriverIRQHandler
EDMA4_CH52_DriverIRQHandler
EDMA4_CH53_DriverIRQHandler
EDMA4_CH54_DriverIRQHandler
EDMA4_CH55_DriverIRQHandler
EDMA4_CH56_DriverIRQHandler
EDMA4_CH57_DriverIRQHandler
EDMA4_CH58_DriverIRQHandler
EDMA4_CH59_DriverIRQHandler
EDMA4_CH60_DriverIRQHandler
EDMA4_CH61_DriverIRQHandler
EDMA4_CH62_DriverIRQHandler
EDMA4_CH63_DriverIRQHandler
EDMA3_CH0_DriverIRQHandler
EDMA3_CH1_DriverIRQHandler
EDMA3_CH2_DriverIRQHandler
EDMA3_CH3_DriverIRQHandler
EDMA3_CH4_DriverIRQHandler
EDMA3_CH5_DriverIRQHandler
EDMA3_CH6_DriverIRQHandler
EDMA3_CH7_DriverIRQHandler
EDMA3_CH8_DriverIRQHandler
EDMA3_CH9_DriverIRQHandler
EDMA3_CH10_DriverIRQHandler
EDMA3_CH11_DriverIRQHandler
EDMA3_CH12_DriverIRQHandler
EDMA3_CH13_DriverIRQHandler
EDMA3_CH14_DriverIRQHandler
EDMA3_CH15_DriverIRQHandler
EDMA3_CH16_DriverIRQHandler
EDMA3_CH17_DriverIRQHandler
EDMA3_CH18_DriverIRQHandler
EDMA3_CH19_DriverIRQHandler
EDMA3_CH20_DriverIRQHandler
EDMA3_CH21_DriverIRQHandler
EDMA3_CH22_DriverIRQHandler
EDMA3_CH23_DriverIRQHandler
EDMA3_CH24_DriverIRQHandler
EDMA3_CH25_DriverIRQHandler
EDMA3_CH26_DriverIRQHandler
EDMA3_CH27_DriverIRQHandler
EDMA3_CH28_DriverIRQHandler
EDMA3_CH29_DriverIRQHandler
EDMA3_CH30_DriverIRQHandler
EDMA3_CH31_DriverIRQHandler
EDMA3_CH32_DriverIRQHandler
EDMA3_CH33_DriverIRQHandler
EDMA3_CH34_DriverIRQHandler
EDMA3_CH35_DriverIRQHandler
EDMA3_CH36_DriverIRQHandler
EDMA3_CH37_DriverIRQHandler
EDMA3_CH38_DriverIRQHandler
EDMA3_CH39_DriverIRQHandler
EDMA3_CH40_DriverIRQHandler
EDMA3_CH41_DriverIRQHandler
EDMA3_CH42_DriverIRQHandler
EDMA3_CH43_DriverIRQHandler
EDMA3_CH44_DriverIRQHandler
EDMA3_CH45_DriverIRQHandler
EDMA3_CH46_DriverIRQHandler
EDMA3_CH47_DriverIRQHandler
EDMA3_CH48_DriverIRQHandler
EDMA3_CH49_DriverIRQHandler
EDMA3_CH50_DriverIRQHandler
EDMA3_CH51_DriverIRQHandler
EDMA3_CH52_DriverIRQHandler
EDMA3_CH53_DriverIRQHandler
EDMA3_CH54_DriverIRQHandler
EDMA3_CH55_DriverIRQHandler
EDMA3_CH56_DriverIRQHandler
EDMA3_CH57_DriverIRQHandler
EDMA3_CH58_DriverIRQHandler
EDMA3_CH59_DriverIRQHandler
EDMA3_CH60_DriverIRQHandler
EDMA3_CH61_DriverIRQHandler
EDMA3_CH62_DriverIRQHandler
EDMA3_CH63_DriverIRQHandler
EDMA1_CH0_DriverIRQHandler
EDMA1_CH1_DriverIRQHandler
EDMA1_CH2_DriverIRQHandler
EDMA1_CH3_DriverIRQHandler
EDMA1_CH4_DriverIRQHandler
EDMA1_CH5_DriverIRQHandler
EDMA1_CH6_DriverIRQHandler
EDMA1_CH7_DriverIRQHandler
EDMA1_CH8_DriverIRQHandler
EDMA1_CH9_DriverIRQHandler
EDMA1_CH10_DriverIRQHandler
EDMA1_CH11_DriverIRQHandler
EDMA1_CH12_DriverIRQHandler
EDMA1_CH13_DriverIRQHandler
EDMA1_CH14_DriverIRQHandler
EDMA1_CH15_DriverIRQHandler
EDMA1_CH16_DriverIRQHandler
EDMA1_CH17_DriverIRQHandler
EDMA1_CH18_DriverIRQHandler
EDMA1_CH19_DriverIRQHandler
EDMA1_CH20_DriverIRQHandler
EDMA1_CH21_DriverIRQHandler
EDMA1_CH22_DriverIRQHandler
EDMA1_CH23_DriverIRQHandler
EDMA1_CH24_DriverIRQHandler
EDMA1_CH25_DriverIRQHandler
EDMA1_CH26_DriverIRQHandler
EDMA1_CH27_DriverIRQHandler
EDMA1_CH28_DriverIRQHandler
EDMA1_CH29_DriverIRQHandler
EDMA1_CH30_DriverIRQHandler
EDMA1_CH31_DriverIRQHandler
Reserved478_IRQHandler
Reserved479_IRQHandler
Reserved480_IRQHandler
Reserved481_IRQHandler
Reserved482_IRQHandler
Reserved483_IRQHandler
Reserved484_IRQHandler
Reserved485_IRQHandler
Reserved486_IRQHandler
Reserved487_IRQHandler
Reserved488_IRQHandler
Reserved489_IRQHandler
Reserved490_IRQHandler
Reserved491_IRQHandler
Reserved492_IRQHandler
Reserved493_IRQHandler
Reserved494_IRQHandler
Reserved495_IRQHandler
Reserved496_IRQHandler
Reserved497_IRQHandler
Reserved498_IRQHandler
Reserved499_IRQHandler
Reserved500_IRQHandler
Reserved501_IRQHandler
Reserved502_IRQHandler
Reserved503_IRQHandler
Reserved504_IRQHandler
Reserved505_IRQHandler
Reserved506_IRQHandler
Reserved507_IRQHandler
Reserved508_IRQHandler
Reserved509_IRQHandler
MU1_A_IRQHandler
MU1_B_IRQHandler
MU2_A_IRQHandler
MU2_B_IRQHandler
MU3_A_IRQHandler
MU3_B_IRQHandler
MU4_A_IRQHandler
MU4_B_IRQHandler
MU5_B_IRQHandler
MU6_B_IRQHandler
MU7_B_IRQHandler
MU8_A_IRQHandler
MU8_B_IRQHandler
MU9_A_IRQHandler
MU9_B_IRQHandler
MU10_A_IRQHandler
Reserved526_IRQHandler
Reserved527_IRQHandler
Reserved528_IRQHandler
Reserved529_IRQHandler
Reserved530_IRQHandler
Reserved531_IRQHandler
Reserved532_IRQHandler
Reserved533_IRQHandler
Reserved534_IRQHandler
Reserved535_IRQHandler
Reserved536_IRQHandler
Reserved537_IRQHandler
Reserved538_IRQHandler
Reserved539_IRQHandler
Reserved540_IRQHandler
Reserved541_IRQHandler
Reserved542_IRQHandler
Reserved543_IRQHandler
Reserved544_IRQHandler
Reserved545_IRQHandler
Reserved546_IRQHandler
Reserved547_IRQHandler
Reserved548_IRQHandler
Reserved549_IRQHandler
Reserved550_IRQHandler
Reserved551_IRQHandler
Reserved552_IRQHandler
Reserved553_IRQHandler
Reserved554_IRQHandler
Reserved555_IRQHandler
Reserved556_IRQHandler
Reserved557_IRQHandler
Reserved558_IRQHandler
Reserved559_IRQHandler
Reserved560_IRQHandler
Reserved561_IRQHandler
Reserved562_IRQHandler
Reserved563_IRQHandler
Reserved564_IRQHandler
Reserved565_IRQHandler
Reserved566_IRQHandler
Reserved567_IRQHandler
Reserved568_IRQHandler
Reserved569_IRQHandler
Reserved570_IRQHandler
Reserved571_IRQHandler
Reserved572_IRQHandler
Reserved573_IRQHandler
MU11_A_IRQHandler
MU12_B_IRQHandler
MU13_B_IRQHandler
MU14_A_IRQHandler
MU14_B_IRQHandler
MU15_A_IRQHandler
MU15_B_IRQHandler
MU16_A_IRQHandler
MU16_B_IRQHandler
MU17_A_IRQHandler
MU17_B_IRQHandler
MU_E1_B_IRQHandler
MU_E2_B_IRQHandler
MU_E3_B_IRQHandler
MU_E4_B_IRQHandler
MSGINTR1_IRQHandler
Reserved590_IRQHandler
Reserved591_IRQHandler
Reserved592_IRQHandler
Reserved593_IRQHandler
Reserved594_IRQHandler
Reserved595_IRQHandler
Reserved596_IRQHandler
Reserved597_IRQHandler
Reserved598_IRQHandler
Reserved599_IRQHandler
Reserved600_IRQHandler
Reserved601_IRQHandler
Reserved602_IRQHandler
Reserved603_IRQHandler
Reserved604_IRQHandler
Reserved605_IRQHandler
Reserved606_IRQHandler
Reserved607_IRQHandler
Reserved608_IRQHandler
Reserved609_IRQHandler
Reserved610_IRQHandler
Reserved611_IRQHandler
Reserved612_IRQHandler
Reserved613_IRQHandler
Reserved614_IRQHandler
Reserved615_IRQHandler
Reserved616_IRQHandler
Reserved617_IRQHandler
Reserved618_IRQHandler
Reserved619_IRQHandler
Reserved620_IRQHandler
Reserved621_IRQHandler
Reserved622_IRQHandler
Reserved623_IRQHandler
Reserved624_IRQHandler
Reserved625_IRQHandler
Reserved626_IRQHandler
Reserved627_IRQHandler
Reserved628_IRQHandler
Reserved629_IRQHandler
Reserved630_IRQHandler
Reserved631_IRQHandler
Reserved632_IRQHandler
Reserved633_IRQHandler
Reserved634_IRQHandler
Reserved635_IRQHandler
Reserved636_IRQHandler
Reserved637_IRQHandler
MSGINTR2_IRQHandler
MSGINTR3_IRQHandler
MSGINTR4_IRQHandler
MSGINTR5_IRQHandler
MSGINTR6_IRQHandler
MSGINTR7_IRQHandler
MSGINTR8_IRQHandler
V2X_FH_APP1_IRQHandler
V2X_FH_HSM2_IRQHandler
S500_REQ1_IRQHandler
S500_REQ2_IRQHandler
S500_REQ3_IRQHandler
S500_REQ4_IRQHandler
S500_GLUE_IRQHandler
GPC_SM_REQ_IRQHandler
EDMA1_ERROR_DriverIRQHandler
Reserved654_IRQHandler
Reserved655_IRQHandler
Reserved656_IRQHandler
Reserved657_IRQHandler
Reserved658_IRQHandler
Reserved659_IRQHandler
Reserved660_IRQHandler
Reserved661_IRQHandler
Reserved662_IRQHandler
Reserved663_IRQHandler
Reserved664_IRQHandler
Reserved665_IRQHandler
Reserved666_IRQHandler
Reserved667_IRQHandler
Reserved668_IRQHandler
Reserved669_IRQHandler
Reserved670_IRQHandler
Reserved671_IRQHandler
Reserved672_IRQHandler
Reserved673_IRQHandler
Reserved674_IRQHandler
Reserved675_IRQHandler
Reserved676_IRQHandler
Reserved677_IRQHandler
Reserved678_IRQHandler
Reserved679_IRQHandler
Reserved680_IRQHandler
Reserved681_IRQHandler
Reserved682_IRQHandler
Reserved683_IRQHandler
Reserved684_IRQHandler
Reserved685_IRQHandler
Reserved686_IRQHandler
Reserved687_IRQHandler
Reserved688_IRQHandler
Reserved689_IRQHandler
Reserved690_IRQHandler
Reserved691_IRQHandler
Reserved692_IRQHandler
Reserved693_IRQHandler
Reserved694_IRQHandler
Reserved695_IRQHandler
Reserved696_IRQHandler
Reserved697_IRQHandler
Reserved698_IRQHandler
Reserved699_IRQHandler
Reserved700_IRQHandler
Reserved701_IRQHandler
Reserved702_IRQHandler
Reserved703_IRQHandler
Reserved704_IRQHandler
Reserved705_IRQHandler
Reserved706_IRQHandler
Reserved707_IRQHandler
Reserved708_IRQHandler
Reserved709_IRQHandler
Reserved710_IRQHandler
Reserved711_IRQHandler
Reserved712_IRQHandler
Reserved713_IRQHandler
Reserved714_IRQHandler
Reserved715_IRQHandler
Reserved716_IRQHandler
Reserved717_IRQHandler
Reserved718_IRQHandler
Reserved719_IRQHandler
Reserved720_IRQHandler
Reserved721_IRQHandler
Reserved722_IRQHandler
Reserved723_IRQHandler
Reserved724_IRQHandler
Reserved725_IRQHandler
Reserved726_IRQHandler
Reserved727_IRQHandler
Reserved728_IRQHandler
Reserved729_IRQHandler
Reserved730_IRQHandler
Reserved731_IRQHandler
Reserved732_IRQHandler
Reserved733_IRQHandler
Reserved734_IRQHandler
Reserved735_IRQHandler
Reserved736_IRQHandler
Reserved737_IRQHandler
Reserved738_IRQHandler
Reserved739_IRQHandler
Reserved740_IRQHandler
Reserved741_IRQHandler
Reserved742_IRQHandler
Reserved743_IRQHandler
Reserved744_IRQHandler
Reserved745_IRQHandler
Reserved746_IRQHandler
Reserved747_IRQHandler
Reserved748_IRQHandler
Reserved749_IRQHandler
Reserved750_IRQHandler
Reserved751_IRQHandler
Reserved752_IRQHandler
Reserved753_IRQHandler
Reserved754_IRQHandler
Reserved755_IRQHandler
Reserved756_IRQHandler
Reserved757_IRQHandler
Reserved758_IRQHandler
Reserved759_IRQHandler
Reserved760_IRQHandler
Reserved761_IRQHandler
Reserved762_IRQHandler
Reserved763_IRQHandler
Reserved764_IRQHandler
Reserved765_IRQHandler
Reserved766_IRQHandler
Reserved767_IRQHandler
Reserved768_IRQHandler
Reserved769_IRQHandler
Reserved770_IRQHandler
Reserved771_IRQHandler
Reserved772_IRQHandler
Reserved773_IRQHandler
Reserved774_IRQHandler
Reserved775_IRQHandler
Reserved776_IRQHandler
Reserved777_IRQHandler
Reserved778_IRQHandler
Reserved779_IRQHandler
Reserved780_IRQHandler
Reserved781_IRQHandler
Reserved782_IRQHandler
Reserved783_IRQHandler
Reserved784_IRQHandler
Reserved785_IRQHandler
Reserved786_IRQHandler
Reserved787_IRQHandler
Reserved788_IRQHandler
Reserved789_IRQHandler
Reserved790_IRQHandler
Reserved791_IRQHandler
Reserved792_IRQHandler
Reserved793_IRQHandler
Reserved794_IRQHandler
Reserved795_IRQHandler
Reserved796_IRQHandler
Reserved797_IRQHandler
Reserved798_IRQHandler
Reserved799_IRQHandler
Reserved800_IRQHandler
Reserved801_IRQHandler
Reserved802_IRQHandler
Reserved803_IRQHandler
Reserved804_IRQHandler
Reserved805_IRQHandler
Reserved806_IRQHandler
Reserved807_IRQHandler
Reserved808_IRQHandler
Reserved809_IRQHandler
Reserved810_IRQHandler
Reserved811_IRQHandler
Reserved812_IRQHandler
Reserved813_IRQHandler
Reserved814_IRQHandler
Reserved815_IRQHandler
Reserved816_IRQHandler
Reserved817_IRQHandler
Reserved818_IRQHandler
Reserved819_IRQHandler
Reserved820_IRQHandler
Reserved821_IRQHandler
Reserved822_IRQHandler
Reserved823_IRQHandler
Reserved824_IRQHandler
Reserved825_IRQHandler
Reserved826_IRQHandler
Reserved827_IRQHandler
Reserved828_IRQHandler
Reserved829_IRQHandler
Reserved830_IRQHandler
TMPSNS_THR1_IRQHandler
TMPSNS_THR2_IRQHandler
Reserved833_IRQHandler
Reserved834_IRQHandler
Reserved835_IRQHandler
Reserved836_IRQHandler
CM33_0_SYSRESETREQ_IRQHandler
CM33_0_LOCKUP_IRQHandler
CM7_0_SYSRESETREQ_IRQHandler
CM7_0_LOCKUP_IRQHandler
CM33_1_SYSRESETREQ_IRQHandler
CM33_1_LOCKUP_IRQHandler
CM7_1_SYSRESETREQ_IRQHandler
CM7_1_LOCKUP_IRQHandler
Reserved845_IRQHandler
Reserved846_IRQHandler
Reserved847_IRQHandler
Reserved848_IRQHandler
Reserved849_IRQHandler
Reserved850_IRQHandler
Reserved851_IRQHandler
Reserved852_IRQHandler
Reserved853_IRQHandler
Reserved854_IRQHandler
Reserved855_IRQHandler
Reserved856_IRQHandler
Reserved857_IRQHandler
Reserved858_IRQHandler
Reserved859_IRQHandler
Reserved860_IRQHandler
Reserved861_IRQHandler
Reserved862_IRQHandler
Reserved863_IRQHandler
Reserved864_IRQHandler
Reserved865_IRQHandler
Reserved866_IRQHandler
Reserved867_IRQHandler
Reserved868_IRQHandler
Reserved869_IRQHandler
Reserved870_IRQHandler
Reserved871_IRQHandler
Reserved872_IRQHandler
Reserved873_IRQHandler
Reserved874_IRQHandler
Reserved875_IRQHandler
Reserved876_IRQHandler
Reserved877_IRQHandler
Reserved878_IRQHandler
Reserved879_IRQHandler
Reserved880_IRQHandler
Reserved881_IRQHandler
Reserved882_IRQHandler
Reserved883_IRQHandler
Reserved884_IRQHandler
Reserved885_IRQHandler
Reserved886_IRQHandler
Reserved887_IRQHandler
Reserved888_IRQHandler
Reserved889_IRQHandler
Reserved890_IRQHandler
Reserved891_IRQHandler
Reserved892_IRQHandler
Reserved893_IRQHandler
Reserved894_IRQHandler
Reserved895_IRQHandler
Reserved896_IRQHandler
Reserved897_IRQHandler
Reserved898_IRQHandler
Reserved899_IRQHandler
Reserved900_IRQHandler
Reserved901_IRQHandler
Reserved902_IRQHandler
Reserved903_IRQHandler
Reserved904_IRQHandler
Reserved905_IRQHandler
Reserved906_IRQHandler
Reserved907_IRQHandler
Reserved908_IRQHandler
Reserved909_IRQHandler
Reserved910_IRQHandler
Reserved911_IRQHandler
Reserved912_IRQHandler
Reserved913_IRQHandler
Reserved914_IRQHandler
Reserved915_IRQHandler
Reserved916_IRQHandler
Reserved917_IRQHandler
Reserved918_IRQHandler
Reserved919_IRQHandler
Reserved920_IRQHandler
Reserved921_IRQHandler
Reserved922_IRQHandler
Reserved923_IRQHandler
Reserved924_IRQHandler
Reserved925_IRQHandler
Reserved926_IRQHandler
Reserved927_IRQHandler
Reserved928_IRQHandler
Reserved929_IRQHandler
Reserved930_IRQHandler
Reserved931_IRQHandler
Reserved932_IRQHandler
Reserved933_IRQHandler
Reserved934_IRQHandler
Reserved935_IRQHandler
Reserved936_IRQHandler
Reserved937_IRQHandler
Reserved938_IRQHandler
Reserved939_IRQHandler
Reserved940_IRQHandler
Reserved941_IRQHandler
Reserved942_IRQHandler
Reserved943_IRQHandler
Reserved944_IRQHandler
Reserved945_IRQHandler
Reserved946_IRQHandler
Reserved947_IRQHandler
Reserved948_IRQHandler
Reserved949_IRQHandler
Reserved950_IRQHandler
Reserved951_IRQHandler
Reserved952_IRQHandler
Reserved953_IRQHandler
Reserved954_IRQHandler
Reserved955_IRQHandler
Reserved956_IRQHandler
Reserved957_IRQHandler
Reserved958_IRQHandler
Reserved959_IRQHandler
Reserved960_IRQHandler
DCIF_CPU_DOMAIN0_IRQHandler
DCIF_CPU_DOMAIN1_IRQHandler
DCIF_CPU_DOMAIN2_IRQHandler
Reserved964_IRQHandler
Reserved965_IRQHandler
PXP_0_IRQHandler
PXP_1_IRQHandler
Reserved968_IRQHandler
Reserved969_IRQHandler
Reserved970_IRQHandler
Reserved971_IRQHandler
Reserved972_IRQHandler
Reserved973_IRQHandler
Reserved974_IRQHandler
Reserved975_IRQHandler
Reserved976_IRQHandler
Reserved977_IRQHandler
Reserved978_IRQHandler
Reserved979_IRQHandler
Reserved980_IRQHandler
Reserved981_IRQHandler
Reserved982_IRQHandler
Reserved983_IRQHandler
Reserved984_IRQHandler
Reserved985_IRQHandler
Reserved986_IRQHandler
Reserved987_IRQHandler
Reserved988_IRQHandler
Reserved989_IRQHandler
Reserved990_IRQHandler
Reserved991_IRQHandler
Reserved992_IRQHandler
Reserved993_IRQHandler
Reserved994_IRQHandler
Reserved995_IRQHandler
Reserved996_IRQHandler
Reserved997_IRQHandler
Reserved998_IRQHandler
Reserved999_IRQHandler
Reserved1000_IRQHandler
Reserved1001_IRQHandler
Reserved1002_IRQHandler
Reserved1003_IRQHandler
Reserved1004_IRQHandler
Reserved1005_IRQHandler
Reserved1006_IRQHandler
Reserved1007_IRQHandler
Reserved1008_IRQHandler
Reserved1009_IRQHandler
Reserved1010_IRQHandler
Reserved1011_IRQHandler
Reserved1012_IRQHandler
Reserved1013_IRQHandler
Reserved1014_IRQHandler
Reserved1015_IRQHandler
Reserved1016_IRQHandler
Reserved1017_IRQHandler
Reserved1018_IRQHandler
Reserved1019_IRQHandler
Reserved1020_IRQHandler
Reserved1021_IRQHandler
XSPI1_DriverIRQHandler
Reserved1023_IRQHandler
Reserved1024_IRQHandler
Reserved1025_IRQHandler
Reserved1026_IRQHandler
XSPI2_DriverIRQHandler
Reserved1028_IRQHandler
Reserved1029_IRQHandler
Reserved1030_IRQHandler
Reserved1031_IRQHandler
Reserved1032_IRQHandler
Reserved1033_IRQHandler
Reserved1034_IRQHandler
Reserved1035_IRQHandler
Reserved1036_IRQHandler
Reserved1037_IRQHandler
Reserved1038_IRQHandler
Reserved1039_IRQHandler
Reserved1040_IRQHandler
Reserved1041_IRQHandler
Reserved1042_IRQHandler
Reserved1043_IRQHandler
Reserved1044_IRQHandler
Reserved1045_IRQHandler
Reserved1046_IRQHandler
Reserved1047_IRQHandler
Reserved1048_IRQHandler
Reserved1049_IRQHandler
Reserved1050_IRQHandler
Reserved1051_IRQHandler
Reserved1052_IRQHandler
Reserved1053_IRQHandler
Reserved1054_IRQHandler
Reserved1055_IRQHandler
Reserved1056_IRQHandler
Reserved1057_IRQHandler
Reserved1058_IRQHandler
Reserved1059_IRQHandler
Reserved1060_IRQHandler
Reserved1061_IRQHandler
Reserved1062_IRQHandler
Reserved1063_IRQHandler
Reserved1064_IRQHandler
Reserved1065_IRQHandler
Reserved1066_IRQHandler
Reserved1067_IRQHandler
Reserved1068_IRQHandler
Reserved1069_IRQHandler
Reserved1070_IRQHandler
Reserved1071_IRQHandler
Reserved1072_IRQHandler
Reserved1073_IRQHandler
Reserved1074_IRQHandler
Reserved1075_IRQHandler
Reserved1076_IRQHandler
Reserved1077_IRQHandler
Reserved1078_IRQHandler
Reserved1079_IRQHandler
Reserved1080_IRQHandler
Reserved1081_IRQHandler
Reserved1082_IRQHandler
Reserved1083_IRQHandler
Reserved1084_IRQHandler
Reserved1085_IRQHandler
DefaultISR
        B DefaultISR

        END
